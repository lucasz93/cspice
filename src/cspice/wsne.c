#include "f2c.h"
#include "fio.h"
#include "lio.h"
#include "__cspice_state.h"

 integer
#ifdef KR_headers
s_wsne(a) cilist *a;
#else
s_wsne(cilist *a)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	int n;

	if(n=c_le(a))
		return(n);
	f2c->f__reading=0;
	f2c->f__external=1;
	f2c->f__formatted=1;
	f2c->f__putn = x_putc;
	f2c->L_len = LINE;
	f2c->f__donewrec = x_wSL;
	if(f2c->f__curunit->uwrt != 1 && f__nowwriting(f2c->f__curunit))
		err(a->cierr, errno, "namelist output start");
	x_wsne(a);
	return e_wsle();
	}
