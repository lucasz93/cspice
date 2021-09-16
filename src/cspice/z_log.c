#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double log(), atan2();
VOID z_log(f2c, r, z) f2c_state_t *f2c; doublecomplex *r, *z;
#else
#undef abs
#include "math.h"
void z_log(f2c_state_t *f2c, doublecomplex *r, doublecomplex *z)
#endif
{
	double zi = z->i;
	r->i = atan2(zi, z->r);
	r->r = log( f__cabs( z->r, zi ) );
	}
