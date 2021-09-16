#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double asin();
double d_asin(f2c, x) f2c_state_t *f2c; doublereal *x;
#else
#undef abs
#include "math.h"
double d_asin(f2c_state_t *f2c, doublereal *x)
#endif
{
return( asin(*x) );
}
