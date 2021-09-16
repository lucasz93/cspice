#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
shortint h_sign(f2c,a,b) f2c_state_t *f2c; shortint *a, *b;
#else
shortint h_sign(f2c_state_t *f2c, shortint *a, shortint *b)
#endif
{
shortint x;
x = (*a >= 0 ? *a : - *a);
return( *b >= 0 ? x : -x);
}
