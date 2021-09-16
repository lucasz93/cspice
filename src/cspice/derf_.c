#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double erf();
double derf_(f2c, x) f2c_state_t *f2c; doublereal *x;
#else
extern double erf(double);
double derf_(f2c_state_t *f2c, doublereal *x)
#endif
{
return( erf(*x) );
}
