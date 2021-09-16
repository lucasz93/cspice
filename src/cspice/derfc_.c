#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
extern double erfc();

double derfc_(f2c,x) f2c_state_t *f2c; doublereal *x;
#else
extern double erfc(double);

double derfc_(f2c_state_t *f2c, doublereal *x)
#endif
{
return( erfc(*x) );
}
