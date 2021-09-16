/* This gives the effect of

	subroutine exit(rc)
	integer*4 rc
	stop
	end

 * with the added side effect of supplying rc as the program's exit code.
 */

#include "f2c.h"
#include "fprocs.h"
#undef abs
#undef min
#undef max
#ifndef KR_headers
#include "stdlib.h"
#ifdef __cplusplus
extern "C" {
#endif
#endif

 void
#ifdef KR_headers
exit_(f2c,rc) f2c_state_t *f2c; integer *rc;
#else
exit_(f2c_state_t *f2c, integer *rc)
#endif
{
#ifdef NO_ONEXIT
	f_exit(f2c);
#endif
	exit(*rc);
	}
#ifdef __cplusplus
}
#endif
