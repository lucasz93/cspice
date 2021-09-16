#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double sqrt();
VOID z_sqrt(f2c, r, z) f2c_state_t *f2c; doublecomplex *r, *z;
#else
#undef abs
#include "math.h"
void z_sqrt(f2c_state_t *f2c, doublecomplex *r, doublecomplex *z)
#endif
{
	double mag, zi = z->i, zr = z->r;

	if( (mag = f__cabs(zr, zi)) == 0.)
		r->r = r->i = 0.;
	else if(zr > 0)
		{
		r->r = sqrt(0.5 * (mag + zr) );
		r->i = zi / r->r / 2;
		}
	else
		{
		r->i = sqrt(0.5 * (mag - zr) );
		if(zi < 0)
			r->i = - r->i;
		r->r = zi / r->i / 2;
		}
	}
