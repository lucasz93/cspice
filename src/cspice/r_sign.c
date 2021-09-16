#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double r_sign(f2c,a,b) f2c_state_t *f2c; real *a, *b;
#else
double r_sign(f2c_state_t *f2c, real *a, real *b)
#endif
{
double x;
x = (*a >= 0 ? *a : - *a);
return( *b >= 0 ? x : -x);
}
