#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
integer i_sign(f2c,a,b) f2c_state_t *f2c; integer *a, *b;
#else
integer i_sign(f2c_state_t *f2c, integer *a, integer *b)
#endif
{
integer x;
x = (*a >= 0 ? *a : - *a);
return( *b >= 0 ? x : -x);
}
