#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double r_imag(f2c, z) f2c_state_t *f2c; complex *z;
#else
double r_imag(f2c_state_t *f2c, complex *z)
#endif
{
return(z->i);
}
