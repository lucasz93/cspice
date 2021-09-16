#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
VOID c_log(f2c, r, z) f2c_state_t *f2c; complex *r, *z;
#else
#undef abs
#include "math.h"
void c_log(f2c_state_t *f2c, complex *r, complex *z)
#endif
{
	double zi;
	r->i = atan2(zi = z->i, z->r);
	r->r = log( f__cabs(z->r, zi) );
	}
