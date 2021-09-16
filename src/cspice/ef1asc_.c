/*
   06-FEB-1999 (NJB)
	
	The statement
	
      return 0;
		
	for the normal C case was added to suppress compilation warnings.
		
*/

/* EFL support routine to copy string b to string a */

#include "f2c.h"
#include "fprocs.h"

#define M	( (long) (sizeof(long) - 1) )
#define EVEN(x)	( ( (x)+ M) & (~M) )

#ifdef KR_headers
ef1asc_(f2c, a, la, b, lb) f2c_state_t *f2c; ftnint *a, *b; ftnlen *la, *lb;
#else
int ef1asc_(f2c_state_t *f2c, ftnint *a, ftnlen *la, ftnint *b, ftnlen *lb)
#endif
{
s_copy( f2c, (char *)a, (char *)b, EVEN(*la), *lb );

return 0;

#ifdef __cplusplus
return 0;
#endif
}
