#include "f2c.h"
#include "fio.h"
#include "__cspice_state.h"
#include "fprocs.h"

 static FILE *
#ifdef KR_headers
unit_chk(f2c, Unit, who) f2c_state_t *f2c; integer Unit; char *who;
#else
unit_chk(f2c_state_t *f2c, integer Unit, char *who)
#endif
{
	if (Unit >= MXUNIT || Unit < 0)
		f__fatal(f2c, 101, who);
	return f2c->f__units[Unit].ufd;
	}

 integer
#ifdef KR_headers
ftell_(f2c, Unit) f2c_state_t *f2c; integer *Unit;
#else
ftell_(f2c_state_t *f2c, integer *Unit)
#endif
{
	FILE *f;
	return (f = unit_chk(f2c, *Unit, "ftell")) ? ftell(f) : -1L;
	}

 int
#ifdef KR_headers
fseek_(f2c, Unit, offset, whence) f2c_state_t *f2c; integer *Unit, *offset, *whence;
#else
fseek_(f2c_state_t *f2c, integer *Unit, integer *offset, integer *whence)
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
	return	!(f = unit_chk(f2c, *Unit, "fseek"))
		|| fseek(f, *offset, w) ? 1 : 0;
	}
