#include "f2c.h"
#include "fio.h"
#include "fmt.h"

 static int
mv_cur(f2c_state_t *f2c)	/* shouldn't use fseek because it insists on calling fflush */
		/* instead we know too much about stdio */
{
	int cursor = f2c->f__cursor;
	f2c->f__cursor = 0;
	if(f2c->f__external == 0) {
		if(cursor < 0) {
			if(f2c->f__hiwater < f2c->f__recpos)
				f2c->f__hiwater = f2c->f__recpos;
			f2c->f__recpos += cursor;
			f2c->f__icptr += cursor;
			if(f2c->f__recpos < 0)
				err(f2c->f__elist->cierr, 110, "left off");
		}
		else if(cursor > 0) {
			if(f2c->f__recpos + cursor >= f2c->f__svic->icirlen)
				err(f2c->f__elist->cierr, 110, "recend");
			if(f2c->f__hiwater <= f2c->f__recpos)
				for(; cursor > 0; cursor--)
					(*f2c->f__putn)(' ');
			else if(f2c->f__hiwater <= f2c->f__recpos + cursor) {
				cursor -= f2c->f__hiwater - f2c->f__recpos;
				f2c->f__icptr += f2c->f__hiwater - f2c->f__recpos;
				f2c->f__recpos = f2c->f__hiwater;
				for(; cursor > 0; cursor--)
					(*f2c->f__putn)(' ');
			}
			else {
				f2c->f__icptr += cursor;
				f2c->f__recpos += cursor;
			}
		}
		return(0);
	}
	if (cursor > 0) {
		if(f2c->f__hiwater <= f2c->f__recpos)
			for(;cursor>0;cursor--) (*f2c->f__putn)(' ');
		else if(f2c->f__hiwater <= f2c->f__recpos + cursor) {
			cursor -= f2c->f__hiwater - f2c->f__recpos;
			f2c->f__recpos = f2c->f__hiwater;
			for(; cursor > 0; cursor--)
				(*f2c->f__putn)(' ');
		}
		else {
			f2c->f__recpos += cursor;
		}
	}
	else if (cursor < 0)
	{
		if(cursor + f2c->f__recpos < 0)
			err(f2c->f__elist->cierr,110,"left off");
		if(f2c->f__hiwater < f2c->f__recpos)
			f2c->f__hiwater = f2c->f__recpos;
		f2c->f__recpos += cursor;
	}
	return(0);
}

 static int
#ifdef KR_headers
wrt_Z(f2c,n,w,minlen,len) f2c_state_t *f2c; Uint *n; int w, minlen; ftnlen len;
#else
wrt_Z(f2c_state_t *f2c, Uint *n, int w, int minlen, ftnlen len)
#endif
{
	register char *s, *se;
	register int i, w1;
	static int one = 1;						/* MECHSOFT: Read only. Safe to keep static. */
	static char hex[] = "0123456789ABCDEF";	/* MECHSOFT: Not critical state. Safe to keep thread local. */
	s = (char *)n;
	--len;
	if (*(char *)&one) {
		/* little endian */
		se = s;
		s += len;
		i = -1;
		}
	else {
		se = s + len;
		i = 1;
		}
	for(;; s += i)
		if (s == se || *s)
			break;
	w1 = (i*(se-s) << 1) + 1;
	if (*s & 0xf0)
		w1++;
	if (w1 > w)
		for(i = 0; i < w; i++)
			(*f2c->f__putn)('*');
	else {
		if ((minlen -= w1) > 0)
			w1 += minlen;
		while(--w >= w1)
			(*f2c->f__putn)(' ');
		while(--minlen >= 0)
			(*f2c->f__putn)('0');
		if (!(*s & 0xf0)) {
			(*f2c->f__putn)(hex[*s & 0xf]);
			if (s == se)
				return 0;
			s += i;
			}
		for(;; s += i) {
			(*f2c->f__putn)(hex[*s >> 4 & 0xf]);
			(*f2c->f__putn)(hex[*s & 0xf]);
			if (s == se)
				break;
			}
		}
	return 0;
	}

 static int
#ifdef KR_headers
wrt_I(f2c,n,w,len, base) f2c_state_t *f2c; Uint *n; ftnlen len; register int base;
#else
wrt_I(f2c_state_t *f2c, Uint *n, int w, ftnlen len, register int base)
#endif
{	int ndigit,sign,spare,i;
	longint x;
	char *ans;
	if(len==sizeof(integer)) x=n->il;
	else if(len == sizeof(char)) x = n->ic;
#ifdef Allow_TYQUAD
	else if (len == sizeof(longint)) x = n->ili;
#endif
	else x=n->is;
	ans=f__icvt(x,&ndigit,&sign, base);
	spare=w-ndigit;
	if(sign || f2c->f__cplus) spare--;
	if(spare<0)
		for(i=0;i<w;i++) (*f2c->f__putn)('*');
	else
	{	for(i=0;i<spare;i++) (*f2c->f__putn)(' ');
		if(sign) (*f2c->f__putn)('-');
		else if(f2c->f__cplus) (*f2c->f__putn)('+');
		for(i=0;i<ndigit;i++) (*f2c->f__putn)(*ans++);
	}
	return(0);
}
 static int
#ifdef KR_headers
wrt_IM(f2c,n,w,m,len,base) f2c_state_t *f2c; Uint *n; ftnlen len; int base;
#else
wrt_IM(f2c_state_t *f2c, Uint *n, int w, int m, ftnlen len, int base)
#endif
{	int ndigit,sign,spare,i,xsign;
	longint x;
	char *ans;
	if(sizeof(integer)==len) x=n->il;
	else if(len == sizeof(char)) x = n->ic;
#ifdef Allow_TYQUAD
	else if (len == sizeof(longint)) x = n->ili;
#endif
	else x=n->is;
	ans=f__icvt(x,&ndigit,&sign, base);
	if(sign || f2c->f__cplus) xsign=1;
	else xsign=0;
	if(ndigit+xsign>w || m+xsign>w)
	{	for(i=0;i<w;i++) (*f2c->f__putn)('*');
		return(0);
	}
	if(x==0 && m==0)
	{	for(i=0;i<w;i++) (*f2c->f__putn)(' ');
		return(0);
	}
	if(ndigit>=m)
		spare=w-ndigit-xsign;
	else
		spare=w-m-xsign;
	for(i=0;i<spare;i++) (*f2c->f__putn)(' ');
	if(sign) (*f2c->f__putn)('-');
	else if(f2c->f__cplus) (*f2c->f__putn)('+');
	for(i=0;i<m-ndigit;i++) (*f2c->f__putn)('0');
	for(i=0;i<ndigit;i++) (*f2c->f__putn)(*ans++);
	return(0);
}
 static int
#ifdef KR_headers
wrt_AP(f2c,s) f2c_state_t *f2c; char *s;
#else
wrt_AP(f2c_state_t *f2c, char *s)
#endif
{	char quote;
	int i;

	if(f2c->f__cursor && (i = mv_cur(f2c)))
		return i;
	quote = *s++;
	for(;*s;s++)
	{	if(*s!=quote) (*f2c->f__putn)(*s);
		else if(*++s==quote) (*f2c->f__putn)(*s);
		else return(1);
	}
	return(1);
}
 static int
#ifdef KR_headers
wrt_H(f2c,a,s) f2c_state_t *f2c; char *s;
#else
wrt_H(f2c_state_t *f2c, int a, char *s)
#endif
{
	int i;

	if(f2c->f__cursor && (i = mv_cur(f2c)))
		return i;
	while(a--) (*f2c->f__putn)(*s++);
	return(1);
}
#ifdef KR_headers
wrt_L(f2c, n,len, sz) f2c_state_t *f2c; Uint *n; ftnlen sz;
#else
wrt_L(f2c_state_t *f2c, Uint *n, int len, ftnlen sz)
#endif
{	int i;
	long x;
	if(sizeof(long)==sz) x=n->il;
	else if(sz == sizeof(char)) x = n->ic;
	else x=n->is;
	for(i=0;i<len-1;i++)
		(*f2c->f__putn)(' ');
	if(x) (*f2c->f__putn)('T');
	else (*f2c->f__putn)('F');
	return(0);
}
 static int
#ifdef KR_headers
wrt_A(f2c,p,len) f2c_state_t *f2c; char *p; ftnlen len;
#else
wrt_A(f2c_state_t *f2c, char *p, ftnlen len)
#endif
{
	while(len-- > 0) (*f2c->f__putn)(*p++);
	return(0);
}
 static int
#ifdef KR_headers
wrt_AW(f2c,p,w,len) f2c_state_t *f2c; char * p; ftnlen len;
#else
wrt_AW(f2c_state_t *f2c, char * p, int w, ftnlen len)
#endif
{
	while(w>len)
	{	w--;
		(*f2c->f__putn)(' ');
	}
	while(w-- > 0)
		(*f2c->f__putn)(*p++);
	return(0);
}

 static int
#ifdef KR_headers
wrt_G(f2c,p,w,d,e,len) f2c_state_t *f2c; ufloat *p; ftnlen len;
#else
wrt_G(f2c_state_t *f2c, ufloat *p, int w, int d, int e, ftnlen len)
#endif
{	double up = 1,x;
	int i=0,oldscale,n,j;
	x = len==sizeof(real)?p->pf:p->pd;
	if(x < 0 ) x = -x;
	if(x<.1) {
		if (x != 0.)
			return(wrt_E(p,w,d,e,len));
		i = 1;
		goto have_i;
		}
	for(;i<=d;i++,up*=10)
	{	if(x>=up) continue;
 have_i:
		oldscale = f2c->f__scale;
		f2c->f__scale = 0;
		if(e==0) n=4;
		else	n=e+2;
		i=wrt_F(p,w-n,d-i,len);
		for(j=0;j<n;j++) (*f2c->f__putn)(' ');
		f2c->f__scale=oldscale;
		return(i);
	}
	return(wrt_E(p,w,d,e,len));
}
#ifdef KR_headers
w_ed(f2c,p,ptr,len) f2c_state_t *f2c; struct syl *p; char *ptr; ftnlen len;
#else
w_ed(f2c_state_t *f2c, struct syl *p, char *ptr, ftnlen len)
#endif
{
	int i;

	if(f2c->f__cursor && (i = mv_cur(f2c)))
		return i;
	switch(p->op)
	{
	default:
		fprintf(stderr,"w_ed, unexpected code: %d\n", p->op);
		sig_die(f2c->f__fmtbuf, 1);
	case I:	return(wrt_I(f2c,(Uint *)ptr,p->p1,len, 10));
	case IM:
		return(wrt_IM(f2c,(Uint *)ptr,p->p1,p->p2.i[0],len,10));

		/* O and OM don't work right for character, double, complex, */
		/* or doublecomplex, and they differ from Fortran 90 in */
		/* showing a minus sign for negative values. */

	case O:	return(wrt_I(f2c,(Uint *)ptr, p->p1, len, 8));
	case OM:
		return(wrt_IM(f2c,(Uint *)ptr,p->p1,p->p2.i[0],len,8));
	case L:	return(wrt_L(f2c,(Uint *)ptr,p->p1, len));
	case A: return(wrt_A(f2c,ptr,len));
	case AW:
		return(wrt_AW(f2c,ptr,p->p1,len));
	case D:
	case E:
	case EE:
		return(wrt_E((ufloat *)ptr,p->p1,p->p2.i[0],p->p2.i[1],len));
	case G:
	case GE:
		return(wrt_G(f2c,(ufloat *)ptr,p->p1,p->p2.i[0],p->p2.i[1],len));
	case F:	return(wrt_F((ufloat *)ptr,p->p1,p->p2.i[0],len));

		/* Z and ZM assume 8-bit bytes. */

	case Z: return(wrt_Z(f2c,(Uint *)ptr,p->p1,0,len));
	case ZM:
		return(wrt_Z(f2c,(Uint *)ptr,p->p1,p->p2.i[0],len));
	}
}
#ifdef KR_headers
w_ned(f2c,p) f2c_state_t *f2c; struct syl *p;
#else
w_ned(f2c_state_t *f2c, struct syl *p)
#endif
{
	switch(p->op)
	{
	default: fprintf(stderr,"w_ned, unexpected code: %d\n", p->op);
		sig_die(f2c->f__fmtbuf, 1);
	case SLASH:
		return((*f2c->f__donewrec)());
	case T: f2c->f__cursor = p->p1-f2c->f__recpos - 1;
		return(1);
	case TL: f2c->f__cursor -= p->p1;
		if(f2c->f__cursor < -f2c->f__recpos)	/* TL1000, 1X */
			f2c->f__cursor = -f2c->f__recpos;
		return(1);
	case TR:
	case X:
		f2c->f__cursor += p->p1;
		return(1);
	case APOS:
		return(wrt_AP(f2c,p->p2.s));
	case H:
		return(wrt_H(f2c,p->p1,p->p2.s));
	}
}
