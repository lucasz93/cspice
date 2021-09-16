#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
integer i_mod(f2c,a,b) f2c_state_t *f2c; integer *a, *b;
#else
integer i_mod(f2c_state_t *f2c, integer *a, integer *b)
#endif
{
return( *a % *b);
}
