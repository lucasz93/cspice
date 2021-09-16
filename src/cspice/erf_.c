#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double erf();
double erf_(f2c,x) f2c_state_t *f2c; real *x;
#else
extern double erf(double);
double erf_(f2c_state_t *f2c, real *x)
#endif
{
return( erf(*x) );
}
