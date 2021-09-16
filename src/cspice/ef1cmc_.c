/* EFL support routine to compare two character strings */

#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
integer ef1cmc_(f2c, a, la, b, lb) f2c_state_t *f2c; ftnint *a, *b; ftnlen *la, *lb;
#else
integer ef1cmc_(f2c_state_t *f2c, ftnint *a, ftnlen *la, ftnint *b, ftnlen *lb)
#endif
{
return( s_cmp( f2c, (char *)a, (char *)b, *la, *lb) );
}
