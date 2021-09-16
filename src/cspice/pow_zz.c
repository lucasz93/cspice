#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double log(), exp(), cos(), sin(), atan2();
VOID pow_zz(f2c,r,a,b) f2c_state_t *f2c; doublecomplex *r, *a, *b;
#else
#undef abs
#include "math.h"
void pow_zz(f2c_state_t *f2c, doublecomplex *r, doublecomplex *a, doublecomplex *b)
#endif
{
double logr, logi, x, y;

logr = log( f__cabs(a->r, a->i) );
logi = atan2(a->i, a->r);

x = exp( logr * b->r - logi * b->i );
y = logr * b->i + logi * b->r;

r->r = x * cos(y);
r->i = x * sin(y);
}
