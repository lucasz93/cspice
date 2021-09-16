#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double r_dim(f2c,a,b) f2c_state_t *f2c; real *a, *b;
#else
double r_dim(f2c_state_t *f2c, real *a, real *b)
#endif
{
return( *a > *b ? *a - *b : 0);
}
