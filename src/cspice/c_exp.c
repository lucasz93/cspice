#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
extern double exp(), cos(), sin();

 VOID c_exp(f2c, r, z) f2c_state_t *f2c; complex *r, *z;
#else
#undef abs
#include "math.h"

void c_exp(f2c_state_t *f2c, complex *r, complex *z)
#endif
{
double expx;

expx = exp(z->r);
r->r = expx * cos(z->i);
r->i = expx * sin(z->i);
}
