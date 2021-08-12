#include "f2c.h"
#include "fio.h"
#include "fmt.h"
#include "__cspice_state.h"

z_getc(Void)
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	if(f2c->f__recpos++ < f2c->f__svic->icirlen) {
		if(f2c->f__icptr >= f2c->f__icend) err(f2c->f__svic->iciend,(EOF),"endfile");
		return(*(unsigned char *)f2c->f__icptr++);
		}
	return '\n';
}

 void
#ifdef KR_headers
z_putc(c)
#else
z_putc(int c)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	if (f2c->f__icptr < f2c->f__icend && f2c->f__recpos++ < f2c->f__svic->icirlen)
		*f2c->f__icptr++ = c;
}
z_rnew(Void)
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;

	f2c->f__icptr = f2c->f__svic->iciunit + (++f2c->f__icnum)*f2c->f__svic->icirlen;
	f2c->f__recpos = 0;
	f2c->f__cursor = 0;
	f2c->f__hiwater = 0;
	return 1;
}

 static int
z_endp(Void)
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	(*f2c->f__donewrec)();
	return 0;
	}

#ifdef KR_headers
c_si(a) icilist *a;
#else
c_si(icilist *a)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;

	f2c->f__elist = (cilist *)a;
	f2c->f__fmtbuf=a->icifmt;
	f2c->f__curunit = 0;
	f2c->f__sequential=f2c->f__formatted=1;
	f2c->f__external=0;
	if(pars_f(f2c->f__fmtbuf)<0)
		err(a->icierr,100,"startint");
	fmt_bg();
	f2c->f__cblank=f2c->f__cplus=f2c->f__scale=0;
	f2c->f__svic=a;
	f2c->f__icnum=f2c->f__recpos=0;
	f2c->f__cursor = 0;
	f2c->f__hiwater = 0;
	f2c->f__icptr = a->iciunit;
	f2c->f__icend = f2c->f__icptr + a->icirlen*a->icirnum;
	f2c->f__cf = 0;
	return(0);
}

 int
iw_rev(Void)
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	if(f2c->f__workdone)
		z_endp();
	f2c->f__hiwater = f2c->f__recpos = f2c->f__cursor = 0;
	return(f2c->f__workdone=0);
	}

#ifdef KR_headers
integer s_rsfi(a) icilist *a;
#else
integer s_rsfi(icilist *a)
#endif
{	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	int n;
	if(n=c_si(a)) return(n);
	f2c->f__reading=1;
	f2c->f__doed=rd_ed;
	f2c->f__doned=rd_ned;
	f2c->f__getn=z_getc;
	f2c->f__dorevert = z_endp;
	f2c->f__donewrec = z_rnew;
	f2c->f__doend = z_endp;
	return(0);
}

z_wnew(Void)
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;

	if (f2c->f__recpos < f2c->f__hiwater) {
		f2c->f__icptr += f2c->f__hiwater - f2c->f__recpos;
		f2c->f__recpos = f2c->f__hiwater;
		}
	while(f2c->f__recpos++ < f2c->f__svic->icirlen)
		*f2c->f__icptr++ = ' ';
	f2c->f__recpos = 0;
	f2c->f__cursor = 0;
	f2c->f__hiwater = 0;
	f2c->f__icnum++;
	return 1;
}
#ifdef KR_headers
integer s_wsfi(a) icilist *a;
#else
integer s_wsfi(icilist *a)
#endif
{	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	int n;
	if(n=c_si(a)) return(n);
	f2c->f__reading=0;
	f2c->f__doed=w_ed;
	f2c->f__doned=w_ned;
	f2c->f__putn=z_putc;
	f2c->f__dorevert = iw_rev;
	f2c->f__donewrec = z_wnew;
	f2c->f__doend = z_endp;
	return(0);
}
integer e_rsfi(Void)
{	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	int n = en_fio();
	f2c->f__fmtbuf = NULL;
	return(n);
}
integer e_wsfi(Void)
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;

	int n;
	n = en_fio();
	f2c->f__fmtbuf = NULL;
	if(f2c->f__svic->icirnum != 1
	 && (f2c->f__icnum >  f2c->f__svic->icirnum
	 || (f2c->f__icnum == f2c->f__svic->icirnum && (f2c->f__recpos | f2c->f__hiwater))))
		err(f2c->f__svic->icierr,110,"inwrite");
	if (f2c->f__recpos < f2c->f__hiwater)
		f2c->f__recpos = f2c->f__hiwater;
	if (f2c->f__recpos >= f2c->f__svic->icirlen)
		err(f2c->f__svic->icierr,110,"recend");
	if (!f2c->f__recpos && f2c->f__icnum)
		return n;
	while(f2c->f__recpos++ < f2c->f__svic->icirlen)
		*f2c->f__icptr++ = ' ';
	return n;
}
