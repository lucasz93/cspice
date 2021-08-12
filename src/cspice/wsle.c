#include "f2c.h"
#include "fio.h"
#include "fmt.h"
#include "lio.h"
#include "string.h"
#include "__cspice_state.h"

#ifdef KR_headers
integer s_wsle(a) cilist *a;
#else
integer s_wsle(cilist *a)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	int n;
	if(n=c_le(a)) return(n);
	f2c->f__reading=0;
	f2c->f__external=1;
	f2c->f__formatted=1;
	f2c->f__putn = x_putc;
	f2c->f__lioproc = l_write;
	f2c->L_len = LINE;
	f2c->f__donewrec = x_wSL;
	if(f2c->f__curunit->uwrt != 1 && f__nowwriting(f2c->f__curunit))
		err(a->cierr, errno, "list output start");
	return(0);
	}

integer e_wsle(Void)
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	int n = f__putbuf('\n');
	f2c->f__recpos=0;
#ifdef ALWAYS_FLUSH
	if (!n && fflush(f2c->f__cf))
		err(f2c->f__elist->cierr, errno, "write end");
#endif
	return(n);
	}
