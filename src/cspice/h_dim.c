#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
shortint h_dim(f2c,a,b) f2c_state_t *f2c; shortint *a, *b;
#else
shortint h_dim(f2c_state_t *f2c, shortint *a, shortint *b)
#endif
{
return( *a > *b ? *a - *b : 0);
}
