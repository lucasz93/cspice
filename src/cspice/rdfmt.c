#include "f2c.h"
#include "fio.h"
#include "__cspice_state.h"
#include "fprocs.h"

#ifdef KR_headers
extern double atof();
#else
#undef abs
#undef min
#undef max
#include "stdlib.h"
#endif

#include "fmt.h"
#include "fp.h"
#include "ctype.h"

 static int
#ifdef KR_headers
rd_Z(f2c,n,w,len) f2c_state_t *f2c; Uint *n; ftnlen len;
#else
rd_Z(f2c_state_t *f2c, Uint *n, int w, ftnlen len)
#endif
{
	long x[9];
	char *s, *s0, *s1, *se, *t;
	int ch, i, w1, w2;
	static int one = 1;					/* MECHSOFT: Read only. Safe to keep static. */
	int bad = 0;

	s = s0 = (char *)x;
	s1 = (char *)&x[4];
	se = (char *)&x[8];
	if (len > 4*sizeof(long))
		return errno = 117;
	while (w) {
		GET(f2c,ch);
		if (ch==',' || ch=='\n')
			break;
		w--;
		if (ch > ' ') {
			if (!f2c->hex[ch & 0xff])
				bad++;
			*s++ = ch;
			if (s == se) {
				/* discard excess characters */
				for(t = s0, s = s1; t < s1;)
					*t++ = *s++;
				s = s1;
				}
			}
		}
	if (bad)
		return errno = 115;
	w = (int)len;
	w1 = s - s0;
	w2 = w1+1 >> 1;
	t = (char *)n;
	if (*(char *)&one) {
		/* little endian */
		t += w - 1;
		i = -1;
		}
	else
		i = 1;
	for(; w > w2; t += i, --w)
		*t = 0;
	if (!w)
		return 0;
	if (w < w2)
		s0 = s - (w << 1);
	else if (w1 & 1) {
		*t = f2c->hex[*s0++ & 0xff] - 1;
		if (!--w)
			return 0;
		t += i;
		}
	do {
		*t = f2c->hex[*s0 & 0xff]-1 << 4 | f2c->hex[s0[1] & 0xff]-1;
		t += i;
		s0 += 2;
		}
		while(--w);
	return 0;
	}

 static int
#ifdef KR_headers
rd_I(f2c,n,w,len, base) f2c_state_t *f2c; Uint *n; int w; ftnlen len; register int base;
#else
rd_I(f2c_state_t *f2c, Uint *n, int w, ftnlen len, register int base)
#endif
{	longint x;
	int sign,ch;
	char s[84], *ps;
	ps=s; x=0;
	while (w)
	{
		GET(f2c,ch);
		if (ch==',' || ch=='\n') break;
		*ps=ch; ps++; w--;
	}
	*ps='\0';
	ps=s;
	while (*ps==' ') ps++;
	if (*ps=='-') { sign=1; ps++; }
	else { sign=0; if (*ps=='+') ps++; }
loop:	while (*ps>='0' && *ps<='9') { x=x*base+(*ps-'0'); ps++; }
	if (*ps==' ') {if (f2c->f__cblank) x *= base; ps++; goto loop;}
	if(sign) x = -x;
	if(len==sizeof(integer)) n->il=x;
	else if(len == sizeof(char)) n->ic = (char)x;
#ifdef Allow_TYQUAD
	else if (len == sizeof(longint)) n->ili = x;
#endif
	else n->is = (short)x;
	if (*ps) return(errno=115); else return(0);
}
 static int
#ifdef KR_headers
rd_L(f2c,n,w,len) f2c_state_t *f2c; ftnint *n; ftnlen len;
#else
rd_L(f2c_state_t *f2c, ftnint *n, int w, ftnlen len)
#endif
{	int ch, lv;
	char s[84], *ps;
	ps=s;
	while (w) {
		GET(f2c,ch);
		if (ch==','||ch=='\n') break;
		*ps=ch;
		ps++; w--;
		}
	*ps='\0';
	ps=s; while (*ps==' ') ps++;
	if (*ps=='.') ps++;
	if (*ps=='t' || *ps == 'T')
		lv = 1;
	else if (*ps == 'f' || *ps == 'F')
		lv = 0;
	else return(errno=116);
	switch(len) {
		case sizeof(char):	*(char *)n = (char)lv;	 break;
		case sizeof(short):	*(short *)n = (short)lv; break;
		default:		*n = lv;
		}
	return 0;
}

 static int
#ifdef KR_headers
rd_F(f2c, p, w, d, len) f2c_state_t *f2c; ufloat *p; ftnlen len;
#else
rd_F(f2c_state_t *f2c, ufloat *p, int w, int d, ftnlen len)
#endif
{
	char s[FMAX+EXPMAXDIGS+4];
	register int ch;
	register char *sp, *spe, *sp1;
	double x;
	int scale1, se;
	long e, exp;

	sp1 = sp = s;
	spe = sp + FMAX;
	exp = -d;
	x = 0.;

	do {
		GET(f2c,ch);
		w--;
		} while (ch == ' ' && w);
	switch(ch) {
		case '-': *sp++ = ch; sp1++; spe++;
		case '+':
			if (!w) goto zero;
			--w;
			GET(f2c,ch);
		}
	while(ch == ' ') {
blankdrop:
		if (!w--) goto zero; GET(f2c,ch); }
	while(ch == '0')
		{ if (!w--) goto zero; GET(f2c,ch); }
	if (ch == ' ' && f2c->f__cblank)
		goto blankdrop;
	scale1 = f2c->f__scale;
	while(isdigit(ch)) {
digloop1:
		if (sp < spe) *sp++ = ch;
		else ++exp;
digloop1e:
		if (!w--) goto done;
		GET(f2c,ch);
		}
	if (ch == ' ') {
		if (f2c->f__cblank)
			{ ch = '0'; goto digloop1; }
		goto digloop1e;
		}
	if (ch == '.') {
		exp += d;
		if (!w--) goto done;
		GET(f2c,ch);
		if (sp == sp1) { /* no digits yet */
			while(ch == '0') {
skip01:
				--exp;
skip0:
				if (!w--) goto done;
				GET(f2c,ch);
				}
			if (ch == ' ') {
				if (f2c->f__cblank) goto skip01;
				goto skip0;
				}
			}
		while(isdigit(ch)) {
digloop2:
			if (sp < spe)
				{ *sp++ = ch; --exp; }
digloop2e:
			if (!w--) goto done;
			GET(f2c,ch);
			}
		if (ch == ' ') {
			if (f2c->f__cblank)
				{ ch = '0'; goto digloop2; }
			goto digloop2e;
			}
		}
	switch(ch) {
	  default:
		break;
	  case '-': se = 1; goto signonly;
	  case '+': se = 0; goto signonly;
	  case 'e':
	  case 'E':
	  case 'd':
	  case 'D':
		if (!w--)
			goto bad;
		GET(f2c,ch);
		while(ch == ' ') {
			if (!w--)
				goto bad;
			GET(f2c,ch);
			}
		se = 0;
	  	switch(ch) {
		  case '-': se = 1;
		  case '+':
signonly:
			if (!w--)
				goto bad;
			GET(f2c,ch);
			}
		while(ch == ' ') {
			if (!w--)
				goto bad;
			GET(f2c,ch);
			}
		if (!isdigit(ch))
			goto bad;

		e = ch - '0';
		for(;;) {
			if (!w--)
				{ ch = '\n'; break; }
			GET(f2c,ch);
			if (!isdigit(ch)) {
				if (ch == ' ') {
					if (f2c->f__cblank)
						ch = '0';
					else continue;
					}
				else
					break;
				}
			e = 10*e + ch - '0';
			if (e > EXPMAX && sp > sp1)
				goto bad;
			}
		if (se)
			exp -= e;
		else
			exp += e;
		scale1 = 0;
		}
	switch(ch) {
	  case '\n':
	  case ',':
		break;
	  default:
bad:
		return (errno = 115);
		}
done:
	if (sp > sp1) {
		while(*--sp == '0')
			++exp;
		if (exp -= scale1)
			sprintf(sp+1, "e%ld", exp);
		else
			sp[1] = 0;
		x = atof(s);
		}
zero:
	if (len == sizeof(real))
		p->pf = x;
	else
		p->pd = x;
	return(0);
	}


 static int
#ifdef KR_headers
rd_A(f2c,p,len) f2c_state_t *f2c; char *p; ftnlen len;
#else
rd_A(f2c_state_t *f2c, char *p, ftnlen len)
#endif
{	int i,ch;
	for(i=0;i<len;i++)
	{	GET(f2c,ch);
		*p++=VAL(ch);
	}
	return(0);
}
 static int
#ifdef KR_headers
rd_AW(f2c,p,w,len) f2c_state_t *f2c; char *p; ftnlen len;
#else
rd_AW(f2c_state_t *f2c, char *p, int w, ftnlen len)
#endif
{	int i,ch;
	if(w>=len)
	{	for(i=0;i<w-len;i++)
			GET(f2c,ch);
		for(i=0;i<len;i++)
		{	GET(f2c,ch);
			*p++=VAL(ch);
		}
		return(0);
	}
	for(i=0;i<w;i++)
	{	GET(f2c,ch);
		*p++=VAL(ch);
	}
	for(i=0;i<len-w;i++) *p++=' ';
	return(0);
}
 static int
#ifdef KR_headers
rd_H(f2c,n,s) f2c_state_t *f2c; char *s;
#else
rd_H(f2c_state_t *f2c, int n, char *s)
#endif
{	int i,ch;
	for(i=0;i<n;i++)
		if((ch=(*f2c->f__getn)(f2c))<0) return(ch);
		else *s++ = ch=='\n'?' ':ch;
	return(1);
}
 static int
#ifdef KR_headers
rd_POS(f2c,s) f2c_state_t *f2c; char *s;
#else
rd_POS(f2c_state_t *f2c, char *s)
#endif
{	char quote;
	int ch;
	quote= *s++;
	for(;*s;s++)
		if(*s==quote && *(s+1)!=quote) break;
		else if((ch=(*f2c->f__getn)(f2c))<0) return(ch);
		else *s = ch=='\n'?' ':ch;
	return(1);
}
#ifdef KR_headers
rd_ed(f2c,p,ptr,len) f2c_state_t *f2c; struct syl *p; char *ptr; ftnlen len;
#else
rd_ed(f2c_state_t *f2c, struct syl *p, char *ptr, ftnlen len)
#endif
{	int ch;
	for(;f2c->f__cursor>0;f2c->f__cursor--) if((ch=(*f2c->f__getn)(f2c))<0) return(ch);
	if(f2c->f__cursor<0)
	{	if(f2c->f__recpos+f2c->f__cursor < 0) /*err(elist->cierr,110,"fmt")*/
			f2c->f__cursor = -f2c->f__recpos;	/* is this in the standard? */
		if(f2c->f__external == 0) {
			f2c->f__icptr += f2c->f__cursor;
		}
		else if(f2c->f__curunit && f2c->f__curunit->useek)
			(void) fseek(f2c->f__cf,(long) f2c->f__cursor,SEEK_CUR);
		else
			err(f2c,f2c->f__elist->cierr,106,"fmt");
		f2c->f__recpos += f2c->f__cursor;
		f2c->f__cursor=0;
	}
	switch(p->op)
	{
	default: fprintf(stderr,"rd_ed, unexpected code: %d\n", p->op);
		sig_die(f2c->f__fmtbuf, 1);
	case IM:
	case I: ch = rd_I(f2c,(Uint *)ptr,p->p1,len, 10);
		break;

		/* O and OM don't work right for character, double, complex, */
		/* or doublecomplex, and they differ from Fortran 90 in */
		/* showing a minus sign for negative values. */

	case OM:
	case O: ch = rd_I(f2c,(Uint *)ptr, p->p1, len, 8);
		break;
	case L: ch = rd_L(f2c,(ftnint *)ptr,p->p1,len);
		break;
	case A:	ch = rd_A(f2c,ptr,len);
		break;
	case AW:
		ch = rd_AW(f2c,ptr,p->p1,len);
		break;
	case E: case EE:
	case D:
	case G:
	case GE:
	case F:	ch = rd_F(f2c,(ufloat *)ptr,p->p1,p->p2.i[0],len);
		break;

		/* Z and ZM assume 8-bit bytes. */

	case ZM:
	case Z:
		ch = rd_Z(f2c,(Uint *)ptr, p->p1, len);
		break;
	}
	if(ch == 0) return(ch);
	else if(ch == EOF) return(EOF);
	if (f2c->f__cf)
		clearerr(f2c->f__cf);
	return(errno);
}
#ifdef KR_headers
rd_ned(f2c,p) f2c_state_t *f2c; struct syl *p;
#else
rd_ned(f2c_state_t *f2c, struct syl *p)
#endif
{
	switch(p->op)
	{
	default: fprintf(stderr,"rd_ned, unexpected code: %d\n", p->op);
		sig_die(f2c->f__fmtbuf, 1);
	case APOS:
		return(rd_POS(f2c,p->p2.s));
	case H:	return(rd_H(f2c,p->p1,p->p2.s));
	case SLASH: return((*f2c->f__donewrec)(f2c));
	case TR:
	case X:	f2c->f__cursor += p->p1;
		return(1);
	case T: f2c->f__cursor=p->p1-f2c->f__recpos - 1;
		return(1);
	case TL: f2c->f__cursor -= p->p1;
		if(f2c->f__cursor < -f2c->f__recpos)	/* TL1000, 1X */
			f2c->f__cursor = -f2c->f__recpos;
		return(1);
	}
}
