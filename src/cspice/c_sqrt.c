#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
extern double sqrt()

VOID c_sqrt(f2c, r, z) f2c_state_t *f2c; complex *r, *z;
#else
#undef abs
#include "math.h"
void c_sqrt(f2c_state_t *f2c, complex *r, complex *z)
#endif
{
	double mag, t;
	double zi = z->i, zr = z->r;

	if( (mag = f__cabs(zr, zi)) == 0.)
		r->r = r->i = 0.;
	else if(zr > 0)
		{
		r->r = t = sqrt(0.5 * (mag + zr) );
		t = zi / t;
		r->i = 0.5 * t;
		}
	else
		{
		t = sqrt(0.5 * (mag - zr) );
		if(zi < 0)
			t = -t;
		r->i = t;
		t = zi / t;
		r->r = 0.5 * t;
		}
	}
