#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double floor();
shortint h_dnnt(f2c,x) f2c_state_t *f2c; doublereal *x;
#else
#undef abs
#include "math.h"
shortint h_dnnt(f2c_state_t *f2c, doublereal *x)
#endif
{
return (shortint)(*x >= 0. ? floor(*x + .5) : -floor(.5 - *x));
}
