#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
shortint h_abs(f2c,x) f2c_state_t *f2c; shortint *x;
#else
shortint h_abs(f2c_state_t *f2c, shortint *x)
#endif
{
if(*x >= 0)
	return(*x);
return(- *x);
}
