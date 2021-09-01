#include "f2c.h"
#include "fio.h"

/* Compile with -DF8X_NML_ELIDE_QUOTES to permit eliding quotation */
/* marks in namelist input a la the Fortran 8X Draft published in  */
/* the May 1989 issue of Fortran Forum. */

#ifdef KR_headers
extern double atof();
extern char *malloc(), *realloc();
#else
#undef abs
#undef min
#undef max
#include "stdlib.h"
#endif

#include "fmt.h"
#include "lio.h"
#include "ctype.h"
#include "fp.h"
#include "__cspice_state.h"

#define isblnk(x) (f__ltab[x+1]&B)
#define issep(x) (f__ltab[x+1]&SX)
#define isapos(x) (f__ltab[x+1]&AX)
#define isexp(x) (f__ltab[x+1]&EX)
#define issign(x) (f__ltab[x+1]&SG)
#define iswhit(x) (f__ltab[x+1]&WH)
#define SX 1
#define B 2
#define AX 4
#define EX 8
#define SG 16
#define WH 32
/* MECHSOFT: Read only. Safe to keep static. */
char f__ltab[128+1] = {	/* offset one for EOF */
	0,
	0,0,AX,0,0,0,0,0,0,WH|B,SX|WH,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	SX|B|WH,0,AX,0,0,0,0,AX,0,0,0,SG,SX,SG,0,SX,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,EX,EX,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	AX,0,0,0,EX,EX,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

 static int
#ifdef KR_headers
un_getc(f2c,x,f__cf) f2c_state_t *f2c; int x; FILE *f__cf;
#else
un_getc(f2c_state_t *f2c, int x, FILE *f__cf)
#endif
{ return ungetc(x,f__cf); }

t_getc(f2c_state_t *f2c)
{	int ch;
	if(f2c->f__curunit->uend) return(EOF);
	if((ch=getc(f2c->f__cf))!=EOF) return(ch);
	if(feof(f2c->f__cf))
		f2c->f__curunit->uend = f2c->l_eof = 1;
	return(EOF);
}
integer e_rsle(f2c_state_t *f2c)
{
	int ch;
	if(f2c->f__curunit->uend) return(0);
	while((ch=t_getc(f2c))!='\n')
		if (ch == EOF) {
			if(feof(f2c->f__cf))
				f2c->f__curunit->uend = f2c->l_eof = 1;
			return EOF;
			}
	return(0);
}

#define ERR(x) if(n=(x)) return(n)
#define GETC(f2c,x) (x=(*f2c->l_getc)(f2c))
#define Ungetc(f2c,x,y) (*f2c->l_ungetc)(f2c,x,y)

 static int
#ifdef KR_headers
l_R(f2c, poststar, reqint) f2c_state_t *f2c; int poststar, reqint;
#else
l_R(f2c_state_t *f2c, int poststar, int reqint)
#endif
{
	char s[FMAX+EXPMAXDIGS+4];
	register int ch;
	register char *sp, *spe, *sp1;
	long e, exp;
	int havenum, havestar, se;

	if (!poststar) {
		if (f2c->f__lcount > 0)
			return(0);
		f2c->f__lcount = 1;
		}
#ifdef Allow_TYQUAD
	f2c->f__llx = 0;
#endif
	f2c->f__ltype = 0;
	exp = 0;
	havestar = 0;
retry:
	sp1 = sp = s;
	spe = sp + FMAX;
	havenum = 0;

	switch(GETC(f2c, ch)) {
		case '-': *sp++ = ch; sp1++; spe++;
		case '+':
			GETC(f2c, ch);
		}
	while(ch == '0') {
		++havenum;
		GETC(f2c, ch);
		}
	while(isdigit(ch)) {
		if (sp < spe) *sp++ = ch;
		else ++exp;
		GETC(f2c, ch);
		}
	if (ch == '*' && !poststar) {
		if (sp == sp1 || exp || *s == '-') {
			errfl(f2c,f2c->f__elist->cierr,112,"bad repetition count");
			}
		poststar = havestar = 1;
		*sp = 0;
		f2c->f__lcount = atoi(s);
		goto retry;
		}
	if (ch == '.') {
#ifndef ALLOW_FLOAT_IN_INTEGER_LIST_INPUT
		if (reqint)
			errfl(f2c,f2c->f__elist->cierr,115,"invalid integer");
#endif
		GETC(f2c, ch);
		if (sp == sp1)
			while(ch == '0') {
				++havenum;
				--exp;
				GETC(f2c, ch);
				}
		while(isdigit(ch)) {
			if (sp < spe)
				{ *sp++ = ch; --exp; }
			GETC(f2c, ch);
			}
		}
	havenum += sp - sp1;
	se = 0;
	if (issign(ch))
		goto signonly;
	if (havenum && isexp(ch)) {
#ifndef ALLOW_FLOAT_IN_INTEGER_LIST_INPUT
		if (reqint)
			errfl(f2c,f2c->f__elist->cierr,115,"invalid integer");
#endif
		GETC(f2c, ch);
		if (issign(ch)) {
signonly:
			if (ch == '-') se = 1;
			GETC(f2c, ch);
			}
		if (!isdigit(ch)) {
bad:
			errfl(f2c,f2c->f__elist->cierr,112,"exponent field");
			}

		e = ch - '0';
		while(isdigit(GETC(f2c, ch))) {
			e = 10*e + ch - '0';
			if (e > EXPMAX)
				goto bad;
			}
		if (se)
			exp -= e;
		else
			exp += e;
		}
	(void) Ungetc(f2c, ch, f2c->f__cf);
	if (sp > sp1) {
		++havenum;
		while(*--sp == '0')
			++exp;
		if (exp)
			sprintf(sp+1, "e%ld", exp);
		else
			sp[1] = 0;
		f2c->f__lx = atof(s);
#ifdef Allow_TYQUAD
		if (reqint&2 && (se = sp - sp1 + exp) > 14 && se < 20) {
			/* Assuming 64-bit longint and 32-bit long. */
			if (exp < 0)
				sp += exp;
			if (sp1 <= sp) {
				f2c->f__llx = *sp1 - '0';
				while(++sp1 <= sp)
					f2c->f__llx = 10*f2c->f__llx + (*sp1 - '0');
				}
			while(--exp >= 0)
				f2c->f__llx *= 10;
			if (*s == '-')
				f2c->f__llx = -f2c->f__llx;
			}
#endif
		}
	else
		f2c->f__lx = 0.;
	if (havenum)
		f2c->f__ltype = TYLONG;
	else
		switch(ch) {
			case ',':
			case '/':
				break;
			default:
				if (havestar && ( ch == ' '
						||ch == '\t'
						||ch == '\n'))
					break;
				if (f2c->nml_read > 1) {
					f2c->f__lquit = 2;
					return 0;
					}
				errfl(f2c,f2c->f__elist->cierr,112,"invalid number");
			}
	return 0;
	}

 static int
#ifdef KR_headers
rd_count(f2c, ch) f2c_state_t *f2c; register int ch;
#else
rd_count(f2c_state_t *f2c, register int ch)
#endif
{
	if (ch < '0' || ch > '9')
		return 1;
	f2c->f__lcount = ch - '0';
	while(GETC(f2c, ch) >= '0' && ch <= '9')
		f2c->f__lcount = 10*f2c->f__lcount + ch - '0';
	Ungetc(f2c, ch, f2c->f__cf);
	return f2c->f__lcount <= 0;
	}

 static int
l_C(f2c_state_t *f2c)
{	int ch, nml_save;
	double lz;
	if(f2c->f__lcount>0) return(0);
	f2c->f__ltype=0;
	GETC(f2c, ch);
	if(ch!='(')
	{
		if (f2c->nml_read > 1 && (ch < '0' || ch > '9')) {
			Ungetc(f2c, ch, f2c->f__cf);
			f2c->f__lquit = 2;
			return 0;
			}
		if (rd_count(f2c, ch))
			if(!f2c->f__cf || !feof(f2c->f__cf))
				errfl(f2c,f2c->f__elist->cierr,112,"complex format");
			else
				err(f2c,f2c->f__elist->cierr,(EOF),"lread");
		if(GETC(f2c, ch)!='*')
		{
			if(!f2c->f__cf || !feof(f2c->f__cf))
				errfl(f2c,f2c->f__elist->cierr,112,"no star");
			else
				err(f2c,f2c->f__elist->cierr,(EOF),"lread");
		}
		if(GETC(f2c, ch)!='(')
		{	Ungetc(f2c,ch,f2c->f__cf);
			return(0);
		}
	}
	else
		f2c->f__lcount = 1;
	while(iswhit(GETC(f2c, ch)));
	Ungetc(f2c,ch,f2c->f__cf);
	nml_save = f2c->nml_read;
	f2c->nml_read = 0;
	if (ch = l_R(f2c,1,0))
		return ch;
	if (!f2c->f__ltype)
		errfl(f2c,f2c->f__elist->cierr,112,"no real part");
	lz = f2c->f__lx;
	while(iswhit(GETC(f2c, ch)));
	if(ch!=',')
	{	(void) Ungetc(f2c,ch,f2c->f__cf);
		errfl(f2c,f2c->f__elist->cierr,112,"no comma");
	}
	while(iswhit(GETC(f2c, ch)));
	(void) Ungetc(f2c, ch, f2c->f__cf);
	if (ch = l_R(f2c,1,0))
		return ch;
	if (!f2c->f__ltype)
		errfl(f2c,f2c->f__elist->cierr,112,"no imaginary part");
	while(iswhit(GETC(f2c, ch)));
	if(ch!=')') errfl(f2c,f2c->f__elist->cierr,112,"no )");
	f2c->f__ly = f2c->f__lx;
	f2c->f__lx = lz;
#ifdef Allow_TYQUAD
	f2c->f__llx = 0;
#endif
	f2c->nml_read = nml_save;
	return(0);
}

 static int
l_L(f2c_state_t *f2c)
{
	int ch;
	if(f2c->f__lcount>0) return(0);
	f2c->f__lcount = 1;
	f2c->f__ltype=0;
	GETC(f2c, ch);
	if(isdigit(ch))
	{
		rd_count(f2c,ch);
		if(GETC(f2c, ch)!='*')
			if(!f2c->f__cf || !feof(f2c->f__cf))
				errfl(f2c,f2c->f__elist->cierr,112,"no star");
			else
				err(f2c,f2c->f__elist->cierr,(EOF),"lread");
		GETC(f2c, ch);
	}
	if(ch == '.') GETC(f2c, ch);
	switch(ch)
	{
	case 't':
	case 'T':
		f2c->f__lx=1;
		break;
	case 'f':
	case 'F':
		f2c->f__lx=0;
		break;
	default:
		if(isblnk(ch) || issep(ch) || ch==EOF)
		{	(void) Ungetc(f2c, ch, f2c->f__cf);
			return(0);
		}
		if (f2c->nml_read > 1) {
			Ungetc(f2c, ch, f2c->f__cf);
			f2c->f__lquit = 2;
			return 0;
			}
		errfl(f2c,f2c->f__elist->cierr,112,"logical");
	}
	f2c->f__ltype=TYLONG;
	while(!issep(GETC(f2c, ch)) && ch!=EOF);
	(void) Ungetc(f2c, ch, f2c->f__cf);
	return(0);
}

#define BUFSIZE	128

 static int
l_CHAR(f2c_state_t *f2c)
{	int ch,size,i;
	static char rafail[] = "realloc failure";
	char quote,*p;
	if(f2c->f__lcount>0) return(0);
	f2c->f__ltype=0;
	if(f2c->f__lchar!=NULL) free(f2c->f__lchar);
	size=BUFSIZE;
	p=f2c->f__lchar = (char *)malloc((unsigned int)size);
	if(f2c->f__lchar == NULL)
		errfl(f2c,f2c->f__elist->cierr,113,"no space");

	GETC(f2c, ch);
	if(isdigit(ch)) {
		/* allow Fortran 8x-style unquoted string...	*/
		/* either find a repetition count or the string	*/
		f2c->f__lcount = ch - '0';
		*p++ = ch;
		for(i = 1;;) {
			switch(GETC(f2c, ch)) {
				case '*':
					if (f2c->f__lcount == 0) {
						f2c->f__lcount = 1;
#ifndef F8X_NML_ELIDE_QUOTES
						if (f2c->nml_read)
							goto no_quote;
#endif
						goto noquote;
						}
					p = f2c->f__lchar;
					goto have_lcount;
				case ',':
				case ' ':
				case '\t':
				case '\n':
				case '/':
					Ungetc(f2c, ch, f2c->f__cf);
					/* no break */
				case EOF:
					f2c->f__lcount = 1;
					f2c->f__ltype = TYCHAR;
					return *p = 0;
				}
			if (!isdigit(ch)) {
				f2c->f__lcount = 1;
#ifndef F8X_NML_ELIDE_QUOTES
				if (f2c->nml_read) {
 no_quote:
					errfl(f2c,f2c->f__elist->cierr,112,
						"undelimited character string");
					}
#endif
				goto noquote;
				}
			*p++ = ch;
			f2c->f__lcount = 10*f2c->f__lcount + ch - '0';
			if (++i == size) {
				f2c->f__lchar = (char *)realloc(f2c->f__lchar,
					(unsigned int)(size += BUFSIZE));
				if(f2c->f__lchar == NULL)
					errfl(f2c,f2c->f__elist->cierr,113,rafail);
				p = f2c->f__lchar + i;
				}
			}
		}
	else	(void) Ungetc(f2c, ch, f2c->f__cf);
 have_lcount:
	if(GETC(f2c, ch)=='\'' || ch=='"') quote=ch;
	else if(isblnk(ch) || (issep(ch) && ch != '\n') || ch==EOF) {
		Ungetc(f2c,ch,f2c->f__cf);
		return 0;
		}
#ifndef F8X_NML_ELIDE_QUOTES
	else if (f2c->nml_read > 1) {
		Ungetc(f2c,ch,f2c->f__cf);
		f2c->f__lquit = 2;
		return 0;
		}
#endif
	else {
		/* Fortran 8x-style unquoted string */
		*p++ = ch;
		for(i = 1;;) {
			switch(GETC(f2c,ch)) {
				case ',':
				case ' ':
				case '\t':
				case '\n':
				case '/':
					Ungetc(f2c,ch,f2c->f__cf);
					/* no break */
				case EOF:
					f2c->f__ltype = TYCHAR;
					return *p = 0;
				}
 noquote:
			*p++ = ch;
			if (++i == size) {
				f2c->f__lchar = (char *)realloc(f2c->f__lchar,
					(unsigned int)(size += BUFSIZE));
				if(f2c->f__lchar == NULL)
					errfl(f2c,f2c->f__elist->cierr,113,rafail);
				p = f2c->f__lchar + i;
				}
			}
		}
	f2c->f__ltype=TYCHAR;
	for(i=0;;)
	{	while(GETC(f2c,ch)!=quote && ch!='\n'
			&& ch!=EOF && ++i<size) *p++ = ch;
		if(i==size)
		{
		newone:
			f2c->f__lchar= (char *)realloc(f2c->f__lchar,
					(unsigned int)(size += BUFSIZE));
			if(f2c->f__lchar == NULL)
				errfl(f2c,f2c->f__elist->cierr,113,rafail);
			p=f2c->f__lchar+i-1;
			*p++ = ch;
		}
		else if(ch==EOF) return(EOF);
		else if(ch=='\n')
		{	if(*(p-1) != '\\') continue;
			i--;
			p--;
			if(++i<size) *p++ = ch;
			else goto newone;
		}
		else if(GETC(f2c,ch)==quote)
		{	if(++i<size) *p++ = ch;
			else goto newone;
		}
		else
		{	(void) Ungetc(f2c,ch,f2c->f__cf);
			*p = 0;
			return(0);
		}
	}
}
#ifdef KR_headers
c_le(f2c,a) f2c_state_t *f2c; cilist *a;
#else
c_le(f2c_state_t *f2c, cilist *a)
#endif
{
	if(!f2c->f__init)
		f_init(f2c);
	f2c->f__fmtbuf="list io";
	f2c->f__curunit = &f2c->f__units[a->ciunit];
	if(a->ciunit>=MXUNIT || a->ciunit<0)
		err(f2c,a->cierr,101,"stler");
	f2c->f__scale=f2c->f__recpos=0;
	f2c->f__elist=a;
	if(f2c->f__curunit->ufd==NULL && fk_open(f2c,SEQ,FMT,a->ciunit))
		err(f2c,a->cierr,102,"lio");
	f2c->f__cf=f2c->f__curunit->ufd;
	if(!f2c->f__curunit->ufmt) err(f2c,a->cierr,103,"lio")
	return(0);
}
#ifdef KR_headers
l_read(f2c,number,ptr,len,type) f2c_state_t *f2c; ftnint *number,type; char *ptr; ftnlen len;
#else
l_read(f2c_state_t *f2c, ftnint *number, char *ptr, ftnlen len, ftnint type)
#endif
{
#define Ptr ((flex *)ptr)
	int i,n,ch;
	doublereal *yy;
	real *xx;
	for(i=0;i<*number;i++)
	{
		if(f2c->f__lquit) return(0);
		if(f2c->l_eof)
			err(f2c,f2c->f__elist->ciend, EOF, "list in")
		if(f2c->f__lcount == 0) {
			f2c->f__ltype = 0;
			for(;;)  {
				GETC(f2c,ch);
				switch(ch) {
				case EOF:
					err(f2c,f2c->f__elist->ciend,(EOF),"list in")
				case ' ':
				case '\t':
				case '\n':
					continue;
				case '/':
					f2c->f__lquit = 1;
					goto loopend;
				case ',':
					f2c->f__lcount = 1;
					goto loopend;
				default:
					(void) Ungetc(f2c, ch, f2c->f__cf);
					goto rddata;
				}
			}
		}
	rddata:
		switch((int)type)
		{
		case TYINT1:
		case TYSHORT:
		case TYLONG:
#ifndef ALLOW_FLOAT_IN_INTEGER_LIST_INPUT
			ERR(l_R(f2c,0,1));
			break;
#endif
		case TYREAL:
		case TYDREAL:
			ERR(l_R(f2c,0,0));
			break;
#ifdef TYQUAD
		case TYQUAD:
			n = l_R(0,2);
			if (n)
				return n;
			break;
#endif
		case TYCOMPLEX:
		case TYDCOMPLEX:
			ERR(l_C(f2c));
			break;
		case TYLOGICAL1:
		case TYLOGICAL2:
		case TYLOGICAL:
			ERR(l_L(f2c));
			break;
		case TYCHAR:
			ERR(l_CHAR(f2c));
			break;
		}
	while (GETC(f2c, ch) == ' ' || ch == '\t');
	if (ch != ',' || f2c->f__lcount > 1)
		Ungetc(f2c, ch, f2c->f__cf);
	loopend:
		if(f2c->f__lquit) return(0);
		if(f2c->f__cf && ferror(f2c->f__cf)) {
			clearerr(f2c->f__cf);
			errfl(f2c,f2c->f__elist->cierr,errno,"list in");
			}
		if(f2c->f__ltype==0) goto bump;
		switch((int)type)
		{
		case TYINT1:
		case TYLOGICAL1:
			Ptr->flchar = (char)f2c->f__lx;
			break;
		case TYLOGICAL2:
		case TYSHORT:
			Ptr->flshort = (short)f2c->f__lx;
			break;
		case TYLOGICAL:
		case TYLONG:
			Ptr->flint = (ftnint)f2c->f__lx;
			break;
#ifdef Allow_TYQUAD
		case TYQUAD:
			if (!(Ptr->fllongint = f2c->f__llx))
				Ptr->fllongint = f2c->f__lx;
			break;
#endif
		case TYREAL:
			Ptr->flreal=f2c->f__lx;
			break;
		case TYDREAL:
			Ptr->fldouble=f2c->f__lx;
			break;
		case TYCOMPLEX:
			xx=(real *)ptr;
			*xx++ = f2c->f__lx;
			*xx = f2c->f__ly;
			break;
		case TYDCOMPLEX:
			yy=(doublereal *)ptr;
			*yy++ = f2c->f__lx;
			*yy = f2c->f__ly;
			break;
		case TYCHAR:
			b_char(f2c->f__lchar,ptr,len);
			break;
		}
	bump:
		if(f2c->f__lcount>0) f2c->f__lcount--;
		ptr += len;
		if (f2c->nml_read)
			f2c->nml_read++;
	}
	return(0);
#undef Ptr
}
#ifdef KR_headers
integer s_rsle(f2c,a) f2c_state_t *f2c; cilist *a;
#else
integer s_rsle(f2c_state_t *f2c, cilist *a)
#endif
{
	int n;

	f2c->f__reading=1;
	f2c->f__external=1;
	f2c->f__formatted=1;
	if(n=c_le(f2c,a)) return(n);
	f2c->f__lioproc = l_read;
	f2c->f__lquit = 0;
	f2c->f__lcount = 0;
	f2c->l_eof = 0;
	if(f2c->f__curunit->uwrt && f__nowreading(f2c,f2c->f__curunit))
		err(f2c,a->cierr,errno,"read start");
	if(f2c->f__curunit->uend)
		err(f2c,f2c->f__elist->ciend,(EOF),"read start");
	f2c->l_getc = t_getc;
	f2c->l_ungetc = un_getc;
	f2c->f__doend = xrd_SL;
	return(0);
}
