/*write sequential formatted external*/
#include "f2c.h"
#include "fio.h"
#include "fmt.h"
#include "__cspice_state.h"

 int
x_wSL(Void)
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	int n = f__putbuf('\n');
	f2c->f__hiwater = f2c->f__recpos = f2c->f__cursor = 0;
	return(n == 0);
}

 static int
xw_end(Void)
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	int n;

	if(f2c->f__nonl) {
		f__putbuf(n = 0);
		fflush(f2c->f__cf);
		}
	else
		n = f__putbuf('\n');
	f2c->f__hiwater = f2c->f__recpos = f2c->f__cursor = 0;
	return n;
}

 static int
xw_rev(Void)
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	int n = 0;
	if(f2c->f__workdone) {
		n = f__putbuf('\n');
		f2c->f__workdone = 0;
		}
	f2c->f__hiwater = f2c->f__recpos = f2c->f__cursor = 0;
	return n;
}

#ifdef KR_headers
integer s_wsfe(a) cilist *a;	/*start*/
#else
integer s_wsfe(cilist *a)	/*start*/
#endif
{	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	int n;
	if(!f2c->f__init) f_init();
	f2c->f__reading=0;
	f2c->f__sequential=1;
	f2c->f__formatted=1;
	f2c->f__external=1;
	if(n=c_sfe(a)) return(n);
	f2c->f__elist=a;
	f2c->f__hiwater = f2c->f__cursor=f2c->f__recpos=0;
	f2c->f__nonl = 0;
	f2c->f__scale=0;
	f2c->f__fmtbuf=a->cifmt;
	f2c->f__cf=f2c->f__curunit->ufd;
	if(pars_f(f2c->f__fmtbuf)<0) err(a->cierr,100,"startio");
	f2c->f__putn= x_putc;
	f2c->f__doed= w_ed;
	f2c->f__doned= w_ned;
	f2c->f__doend=xw_end;
	f2c->f__dorevert=xw_rev;
	f2c->f__donewrec=x_wSL;
	fmt_bg();
	f2c->f__cplus=0;
	f2c->f__cblank=f2c->f__curunit->ublnk;
	if(f2c->f__curunit->uwrt != 1 && f__nowwriting(f2c->f__curunit))
		err(a->cierr,errno,"write start");
	return(0);
}
