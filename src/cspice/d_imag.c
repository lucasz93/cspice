#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double d_imag(f2c,z) f2c_state_t *f2c; doublecomplex *z;
#else
double d_imag(f2c_state_t *f2c, doublecomplex *z)
#endif
{
return(z->i);
}
