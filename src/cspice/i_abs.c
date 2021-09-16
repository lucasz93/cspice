#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
integer i_abs(f2c,x) f2c_state_t *f2c; integer *x;
#else
integer i_abs(f2c_state_t *f2c, integer *x)
#endif
{
if(*x >= 0)
	return(*x);
return(- *x);
}
