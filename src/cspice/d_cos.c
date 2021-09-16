#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double cos();
double d_cos(f2c, x) f2c_state_t *f2c; doublereal *x;
#else
#undef abs
#include "math.h"
double d_cos(f2c_state_t *f2c, doublereal *x)
#endif
{
return( cos(*x) );
}
