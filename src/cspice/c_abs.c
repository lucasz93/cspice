#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double c_abs(f2c, z) f2c_state_t *f2c; complex *z;
#else
double c_abs(f2c_state_t *f2c, complex *z)
#endif
{
return( f__cabs( z->r, z->i ) );
}
