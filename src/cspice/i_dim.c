#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
integer i_dim(f2c,a,b) f2c_state_t *f2c; integer *a, *b;
#else
integer i_dim(f2c_state_t *f2c, integer *a, integer *b)
#endif
{
return( *a > *b ? *a - *b : 0);
}
