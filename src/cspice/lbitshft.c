#include "f2c.h"
#include "fprocs.h"

 integer
#ifdef KR_headers
lbit_shift(f2c, a, b) f2c_state_t *f2c; integer a; integer b;
#else
lbit_shift(f2c_state_t *f2c, integer a, integer b)
#endif
{
	return b >= 0 ? a << b : (integer)((uinteger)a >> -b);
	}
