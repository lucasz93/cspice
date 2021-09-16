#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
shortint h_mod(f2c,a,b) f2c_state_t *f2c; short *a, *b;
#else
shortint h_mod(f2c_state_t *f2c, short *a, short *b)
#endif
{
return( *a % *b);
}
