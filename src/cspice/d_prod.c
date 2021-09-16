#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double d_prod(f2c,x,y) f2c_state_t *f2c; real *x, *y;
#else
double d_prod(f2c_state_t *f2c, real *x, real *y)
#endif
{
return( (*x) * (*y) );
}
