#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double floor();
integer i_nint(f2c,x) f2c_state_t *f2c; real *x;
#else
#undef abs
#include "math.h"
integer i_nint(f2c_state_t *f2c, real *x)
#endif
{
return (integer)(*x >= 0 ? floor(*x + .5) : -floor(.5 - *x));
}
