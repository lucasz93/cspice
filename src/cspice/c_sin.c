#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
extern double sin(), cos(), sinh(), cosh();

VOID c_sin(f2c, r, z) f2c_state_t *f2c; complex *r, *z;
#else
#undef abs
#include "math.h"

void c_sin(f2c_state_t *f2c, complex *r, complex *z)
#endif
{
	double zr = z->r;
	r->r = sin(zr) * cosh(z->i);
	r->i = cos(zr) * sinh(z->i);
	}
