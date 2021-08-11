#include "f2c.h"
#include "fio.h"
#include "__cspice_state.h"

 static FILE *
#ifdef KR_headers
unit_chk(Unit, who) integer Unit; char *who;
#else
unit_chk(integer Unit, char *who)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	if (Unit >= MXUNIT || Unit < 0)
		f__fatal(101, who);
	return f2c->f__units[Unit].ufd;
	}

 integer
#ifdef KR_headers
ftell_(Unit) integer *Unit;
#else
ftell_(integer *Unit)
#endif
{
	FILE *f;
	return (f = unit_chk(*Unit, "ftell")) ? ftell(f) : -1L;
	}

 int
#ifdef KR_headers
fseek_(Unit, offset, whence) integer *Unit, *offset, *whence;
#else
fseek_(integer *Unit, integer *offset, integer *whence)
#endif
{
	FILE *f;
	int w = (int)*whence;
#ifdef SEEK_SET
	/* MECHSOFT: Read only. Safe to keep static. */
	static int wohin[3] = { SEEK_SET, SEEK_CUR, SEEK_END };
#endif
	if (w < 0 || w > 2)
		w = 0;
#ifdef SEEK_SET
	w = wohin[w];
#endif
	return	!(f = unit_chk(*Unit, "fseek"))
		|| fseek(f, *offset, w) ? 1 : 0;
	}
