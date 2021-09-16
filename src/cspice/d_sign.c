#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double d_sign(f2c,a,b) f2c_state_t *f2c; doublereal *a, *b;
#else
double d_sign(f2c_state_t *f2c, doublereal *a, doublereal *b)
#endif
{
double x;
x = (*a >= 0 ? *a : - *a);
return( *b >= 0 ? x : -x);
}
