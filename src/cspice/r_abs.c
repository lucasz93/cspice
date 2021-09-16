#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double r_abs(f2c, x) f2c_state_t *f2c; real *x;
#else
double r_abs(f2c_state_t *f2c, real *x)
#endif
{
if(*x >= 0)
	return(*x);
return(- *x);
}
