#include "f2c.h"
#include "fio.h"
#include "lio.h"
#include "__cspice_state.h"
#ifdef KR_headers
extern void z_putc();
#else
extern void z_putc(f2c_state_t *,int);
#endif

 static int
z_wSL(f2c_state_t *f2c)
{
	while(f2c->f__recpos < f2c->f__svic->icirlen)
		z_putc(f2c,' ');
	return z_rnew(f2c);
	}

 static void
#ifdef KR_headers
c_liw(f2c, a) f2c_state_t *f2c; icilist *a;
#else
c_liw(f2c_state_t *f2c, icilist *a)
#endif
{
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
s_wsni(f2c, a) f2c_state_t *f2c; icilist *a;
#else
s_wsni(f2c_state_t *f2c, icilist *a)
#endif
{
	cilist ca;

	c_liw(f2c, a);
	ca.cifmt = a->icifmt;
	x_wsne(f2c,&ca);
	z_wSL(f2c);
	return 0;
	}

 integer
#ifdef KR_headers
s_wsli(f2c, a) f2c_state_t *f2c; icilist *a;
#else
s_wsli(f2c_state_t *f2c, icilist *a)
#endif
{
	f2c->f__lioproc = l_write;
	c_liw(f2c, a);
	return(0);
	}

integer e_wsli(f2c_state_t *f2c)
{
	z_wSL(f2c);
	return(0);
	}
