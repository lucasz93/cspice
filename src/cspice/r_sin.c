#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double sin();
double r_sin(f2c,x) f2c_state_t *f2c; real *x;
#else
#undef abs
#include "math.h"
double r_sin(f2c_state_t *f2c, real *x)
#endif
{
return( sin(*x) );
}
