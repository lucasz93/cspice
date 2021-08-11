#include "f2c.h"
#include "fio.h"
#include "lio.h"
#include "fmt.h" /* for f__doend */
#include "__cspice_state.h"

static int i_getc(Void)
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	if(f2c->f__recpos >= f2c->f__svic->icirlen) {
		if (f2c->f__recpos++ == f2c->f__svic->icirlen)
			return '\n';
		z_rnew();
		}
	f2c->f__recpos++;
	if(f2c->f__icptr >= f2c->f__icend)
		return EOF;
	return(*f2c->f__icptr++);
	}

 static
#ifdef KR_headers
int i_ungetc(ch, f) int ch; FILE *f;
#else
int i_ungetc(int ch, FILE *f)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	if (--f2c->f__recpos == f2c->f__svic->icirlen)
		return '\n';
	if (f2c->f__recpos < -1)
		err(f2c->f__svic->icierr,110,"recend");
	/* *--icptr == ch, and icptr may point to read-only memory */
	return *--f2c->f__icptr /* = ch */;
	}

 static void
#ifdef KR_headers
c_lir(a) icilist *a;
#else
c_lir(icilist *a)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	extern int l_eof;
	f2c->f__reading = 1;
	f2c->f__external = 0;
	f2c->f__formatted = 1;
	f2c->f__svic = a;
	f2c->L_len = a->icirlen;
	f2c->f__recpos = -1;
	f2c->f__icnum = f2c->f__recpos = 0;
	f2c->f__cursor = 0;
	f2c->l_getc = i_getc;
	f2c->l_ungetc = i_ungetc;
	l_eof = 0;
	f2c->f__icptr = a->iciunit;
	f2c->f__icend = f2c->f__icptr + a->icirlen*a->icirnum;
	f2c->f__cf = 0;
	f2c->f__curunit = 0;
	f2c->f__elist = (cilist *)a;
	}


#ifdef KR_headers
integer s_rsli(a) icilist *a;
#else
integer s_rsli(icilist *a)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	f2c->f__lioproc = l_read;
	f2c->f__lquit = 0;
	f2c->f__lcount = 0;
	c_lir(a);
	f2c->f__doend = 0;
	return(0);
	}

integer e_rsli(Void)
{ return 0; }

#ifdef KR_headers
integer s_rsni(a) icilist *a;
#else
extern int x_rsne(cilist*);

integer s_rsni(icilist *a)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	integer rv;
	cilist ca;
	ca.ciend = a->iciend;
	ca.cierr = a->icierr;
	ca.cifmt = a->icifmt;
	c_lir(a);
	rv = x_rsne(&ca);
	f2c->nml_read = 0;
	return rv;
	}
