#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double d_dim(f2c,a,b) f2c_state_t *f2c; doublereal *a, *b;
#else
double d_dim(f2c_state_t *f2c, doublereal *a, doublereal *b)
#endif
{
return( *a > *b ? *a - *b : 0);
}
