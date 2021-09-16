#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double d_abs(f2c, x) f2c_state_t *f2c; doublereal *x;
#else
double d_abs(f2c_state_t *f2c, doublereal *x)
#endif
{
if(*x >= 0)
	return(*x);
return(- *x);
}
