#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double atan();
double d_atan(f2c, x) f2c_state_t *f2c; doublereal *x;
#else
#undef abs
#include "math.h"
double d_atan(f2c_state_t *f2c, doublereal *x)
#endif
{
return( atan(*x) );
}
