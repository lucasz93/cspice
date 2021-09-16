#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double floor();
shortint h_nint(f2c,x) f2c_state_t *f2c; real *x;
#else
#undef abs
#include "math.h"
shortint h_nint(f2c_state_t *f2c, real *x)
#endif
{
return (shortint)(*x >= 0 ? floor(*x + .5) : -floor(.5 - *x));
}
