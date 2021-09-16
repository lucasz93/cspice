#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double acos();
double r_acos(f2c, x) f2c_state_t *f2c; real *x;
#else
#undef abs
#include "math.h"
double r_acos(f2c_state_t *f2c, real *x)
#endif
{
return( acos(*x) );
}
