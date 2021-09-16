#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double erfc();
double erfc_(f2c,x) f2c_state_t *f2c; real *x;
#else
extern double erfc(double);
double erfc_(f2c_state_t *f2c, real *x)
#endif
{
return( erfc(*x) );
}
