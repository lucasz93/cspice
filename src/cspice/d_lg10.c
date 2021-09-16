#include "f2c.h"
#include "fprocs.h"

#define log10e 0.43429448190325182765

#ifdef KR_headers
double log();
double d_lg10(f2c,x) f2c_state_t *f2c; doublereal *x;
#else
#undef abs
#include "math.h"
double d_lg10(f2c_state_t *f2c, doublereal *x)
#endif
{
return( log10e * log(*x) );
}
