#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double exp(), cos(), sin();
VOID z_exp(f2c, r, z) f2c_state_t *f2c; doublecomplex *r, *z;
#else
#undef abs
#include "math.h"
void z_exp(f2c_state_t *f2c, doublecomplex *r, doublecomplex *z)
#endif
{
double expx;

expx = exp(z->r);
r->r = expx * cos(z->i);
r->i = expx * sin(z->i);
}
