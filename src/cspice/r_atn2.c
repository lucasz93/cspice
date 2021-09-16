#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double atan2();
double r_atn2(f2c,x,y) f2c_state_t *f2c; real *x, *y;
#else
#undef abs
#include "math.h"
double r_atn2(f2c_state_t *f2c, real *x, real *y)
#endif
{
return( atan2(*x,*y) );
}
