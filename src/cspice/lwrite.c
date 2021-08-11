#include "f2c.h"
#include "fio.h"
#include "fmt.h"
#include "lio.h"
#include "__cspice_state.h"

 static VOID
donewrec(Void)
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;

	if (f2c->f__recpos)
		(*f2c->f__donewrec)();
	}

 static VOID
#ifdef KR_headers
lwrt_I(n) longint n;
#else
lwrt_I(longint n)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	char *p;
	int ndigit, sign;

	p = f__icvt(n, &ndigit, &sign, 10);
	if(f2c->f__recpos + ndigit >= f2c->L_len)
		donewrec();
	PUT(f2c, ' ');
	if (sign)
		PUT(f2c, '-');
	while(*p)
		PUT(f2c, *p++);
}
 static VOID
#ifdef KR_headers
lwrt_L(n, len) ftnint n; ftnlen len;
#else
lwrt_L(ftnint n, ftnlen len)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	if(f2c->f__recpos+LLOGW>=f2c->L_len)
		donewrec();
	wrt_L((Uint *)&n,LLOGW, len);
}
 static VOID
#ifdef KR_headers
lwrt_A(p,len) char *p; ftnlen len;
#else
lwrt_A(char *p, ftnlen len)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	int a;
	char *p1, *pe;

	a = 0;
	pe = p + len;
	if (f2c->f__Aquote) {
		a = 3;
		if (len > 1 && p[len-1] == ' ') {
			while(--len > 1 && p[len-1] == ' ');
			pe = p + len;
			}
		p1 = p;
		while(p1 < pe)
			if (*p1++ == '\'')
				a++;
		}
	if(f2c->f__recpos+len+a >= f2c->L_len)
		donewrec();
	if (a
#ifndef OMIT_BLANK_CC
		|| !f2c->f__recpos
#endif
		)
		PUT(f2c, ' ');
	if (a) {
		PUT(f2c, '\'');
		while(p < pe) {
			if (*p == '\'')
				PUT(f2c, '\'');
			PUT(f2c, *p++);
			}
		PUT(f2c, '\'');
		}
	else
		while(p < pe)
			PUT(f2c, *p++);
}

 static int
#ifdef KR_headers
l_g(buf, n) char *buf; double n;
#else
l_g(char *buf, double n)
#endif
{
#ifdef Old_list_output
	doublereal absn;
	char *fmt;

	absn = n;
	if (absn < 0)
		absn = -absn;
	fmt = LLOW <= absn && absn < LHIGH ? LFFMT : LEFMT;
#ifdef USE_STRLEN
	sprintf(buf, fmt, n);
	return strlen(buf);
#else
	return sprintf(buf, fmt, n);
#endif

#else
	register char *b, c, c1;

	b = buf;
	*b++ = ' ';
	if (n < 0) {
		*b++ = '-';
		n = -n;
		}
	else
		*b++ = ' ';
	if (n == 0) {
		*b++ = '0';
		*b++ = '.';
		*b = 0;
		goto f__ret;
		}
	sprintf(b, LGFMT, n);
	switch(*b) {
#ifndef WANT_LEAD_0
		case '0':
			while(b[0] = b[1])
				b++;
			break;
#endif
		case 'i':
		case 'I':
			/* Infinity */
		case 'n':
		case 'N':
			/* NaN */
			while(*++b);
			break;

		default:
	/* Fortran 77 insists on having a decimal point... */
		    for(;; b++)
			switch(*b) {
			case 0:
				*b++ = '.';
				*b = 0;
				goto f__ret;
			case '.':
				while(*++b);
				goto f__ret;
			case 'E':
				for(c1 = '.', c = 'E';  *b = c1;
					c1 = c, c = *++b);
				goto f__ret;
			}
		}
 f__ret:
	return b - buf;
#endif
	}

 static VOID
#ifdef KR_headers
l_put(s) register char *s;
#else
l_put(register char *s)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
#ifdef KR_headers
	register void (*pn)() = f2c->f__putn;
#else
	register void (*pn)(int) = f2c->f__putn;
#endif
	register int c;

	while(c = *s++)
		(*pn)(c);
	}

 static VOID
#ifdef KR_headers
lwrt_F(n) double n;
#else
lwrt_F(double n)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	char buf[LEFBL];

	if(f2c->f__recpos + l_g(buf,n) >= f2c->L_len)
		donewrec();
	l_put(buf);
}
 static VOID
#ifdef KR_headers
lwrt_C(a,b) double a,b;
#else
lwrt_C(double a, double b)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	char *ba, *bb, bufa[LEFBL], bufb[LEFBL];
	int al, bl;

	al = l_g(bufa, a);
	for(ba = bufa; *ba == ' '; ba++)
		--al;
	bl = l_g(bufb, b) + 1;	/* intentionally high by 1 */
	for(bb = bufb; *bb == ' '; bb++)
		--bl;
	if(f2c->f__recpos + al + bl + 3 >= f2c->L_len)
		donewrec();
#ifdef OMIT_BLANK_CC
	else
#endif
	PUT(f2c, ' ');
	PUT(f2c, '(');
	l_put(ba);
	PUT(f2c, ',');
	if (f2c->f__recpos + bl >= f2c->L_len) {
		(*f2c->f__donewrec)();
#ifndef OMIT_BLANK_CC
		PUT(f2c, ' ');
#endif
		}
	l_put(bb);
	PUT(f2c, ')');
}
#ifdef KR_headers
l_write(number,ptr,len,type) ftnint *number,type; char *ptr; ftnlen len;
#else
l_write(ftnint *number, char *ptr, ftnlen len, ftnint type)
#endif
{
#define Ptr ((flex *)ptr)
	int i;
	longint x;
	double y,z;
	real *xx;
	doublereal *yy;
	for(i=0;i< *number; i++)
	{
		switch((int)type)
		{
		default: f__fatal(204,"unknown type in lio");
		case TYINT1:
			x = Ptr->flchar;
			goto xint;
		case TYSHORT:
			x=Ptr->flshort;
			goto xint;
#ifdef Allow_TYQUAD
		case TYQUAD:
			x = Ptr->fllongint;
			goto xint;
#endif
		case TYLONG:
			x=Ptr->flint;
		xint:	lwrt_I(x);
			break;
		case TYREAL:
			y=Ptr->flreal;
			goto xfloat;
		case TYDREAL:
			y=Ptr->fldouble;
		xfloat: lwrt_F(y);
			break;
		case TYCOMPLEX:
			xx= &Ptr->flreal;
			y = *xx++;
			z = *xx;
			goto xcomplex;
		case TYDCOMPLEX:
			yy = &Ptr->fldouble;
			y= *yy++;
			z = *yy;
		xcomplex:
			lwrt_C(y,z);
			break;
		case TYLOGICAL1:
			x = Ptr->flchar;
			goto xlog;
		case TYLOGICAL2:
			x = Ptr->flshort;
			goto xlog;
		case TYLOGICAL:
			x = Ptr->flint;
		xlog:	lwrt_L(Ptr->flint, len);
			break;
		case TYCHAR:
			lwrt_A(ptr,len);
			break;
		}
		ptr += len;
	}
	return(0);
}
