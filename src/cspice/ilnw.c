#include "f2c.h"
#include "fio.h"
#include "lio.h"
#include "__cspice_state.h"
#ifdef KR_headers
extern void z_putc();
#else
extern void z_putc(int);
#endif

 static int
z_wSL(Void)
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	while(f2c->f__recpos < f2c->f__svic->icirlen)
		z_putc(' ');
	return z_rnew();
	}

 static void
#ifdef KR_headers
c_liw(a) icilist *a;
#else
c_liw(icilist *a)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	f2c->f__reading = 0;
	f2c->f__external = 0;
	f2c->f__formatted = 1;
	f2c->f__putn = z_putc;
	f2c->L_len = a->icirlen;
	f2c->f__donewrec = z_wSL;
	f2c->f__svic = a;
	f2c->f__icnum = f2c->f__recpos = 0;
	f2c->f__cursor = 0;
	f2c->f__cf = 0;
	f2c->f__curunit = 0;
	f2c->f__icptr = a->iciunit;
	f2c->f__icend = f2c->f__icptr + a->icirlen*a->icirnum;
	f2c->f__elist = (cilist *)a;
	}

 integer
#ifdef KR_headers
s_wsni(a) icilist *a;
#else
s_wsni(icilist *a)
#endif
{
	cilist ca;

	c_liw(a);
	ca.cifmt = a->icifmt;
	x_wsne(&ca);
	z_wSL();
	return 0;
	}

 integer
#ifdef KR_headers
s_wsli(a) icilist *a;
#else
s_wsli(icilist *a)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	f2c->f__lioproc = l_write;
	c_liw(a);
	return(0);
	}

integer e_wsli(Void)
{
	z_wSL();
	return(0);
	}
