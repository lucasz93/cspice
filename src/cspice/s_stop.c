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
VOID s_stop(f2c, s, n) f2c_state_t *f2c; char *s; ftnlen n;
#else
#undef abs
#undef min
#undef max
#include "stdlib.h"
#ifdef __cplusplus
extern "C" {
#endif
int s_stop(f2c_state_t *f2c, char *s, ftnlen n)
#endif
{
int i;

if(n > 0)
   {
   fprintf(stderr, "STOP ");
   for(i = 0; i<n ; ++i)
      putc(*s++, stderr);
   fprintf(stderr, " statement executed\n");
   }
#ifdef NO_ONEXIT
f_exit(f2c);
#endif
exit(0);

return 0;


#ifdef __cplusplus
return 0; /* NOT REACHED */
}
#endif
}
