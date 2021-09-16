#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double sin(), cos(), sinh(), cosh();
VOID z_sin(f2c, r, z) f2c_state_t *f2c; doublecomplex *r, *z;
#else
#undef abs
#include "math.h"
void z_sin(f2c_state_t *f2c, doublecomplex *r, doublecomplex *z)
#endif
{
	double zr = z->r;
	r->r = sin(zr) * cosh(z->i);
	r->i = cos(zr) * sinh(z->i);
	}
