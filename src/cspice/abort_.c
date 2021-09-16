/*
   06-FEB-1999 (NJB)
	
	The statement
	
      return 0;
		
	for the normal C case was added to suppress compilation warnings.
		
*/

#include "stdio.h"
#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
int abort_(f2c) f2c_state_t *f2c;
#else
int abort_(f2c_state_t *f2c)
#endif
{
sig_die(f2c, "Fortran abort routine called", 1);

return 0;

#ifdef __cplusplus
return 0;
#endif
}
