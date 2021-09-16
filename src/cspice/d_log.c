#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double log();
double d_log(f2c,x) f2c_state_t *f2c; doublereal *x;
#else
#undef abs
#include "math.h"
double d_log(f2c_state_t *f2c, doublereal *x)
#endif
{
return( log(*x) );
}
