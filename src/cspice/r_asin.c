#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double asin();
double r_asin(f2c, x) f2c_state_t *f2c; real *x;
#else
#undef abs
#include "math.h"
double r_asin(f2c_state_t *f2c, real *x)
#endif
{
return( asin(*x) );
}
