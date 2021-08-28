#include "f2c.h"
#include "fio.h"
#include "lio.h"

 integer
#ifdef KR_headers
s_wsne(f2c, a) f2c_state_t *f2c; cilist *a;
#else
s_wsne(f2c_state_t *f2c, cilist *a)
#endif
{
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
