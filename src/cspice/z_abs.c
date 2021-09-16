#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double z_abs(f2c, z) f2c_state_t *f2c; doublecomplex *z;
#else
double z_abs(f2c_state_t *f2c, doublecomplex *z)
#endif
{
return( f__cabs( z->r, z->i ) );
}
