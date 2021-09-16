#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
logical l_ge(f2c,a,b,la,lb) f2c_state_t *f2c; char *a, *b; ftnlen la, lb;
#else
logical l_ge(f2c_state_t *f2c, char *a, char *b, ftnlen la, ftnlen lb)
#endif
{
return(s_cmp(f2c, a,b,la,lb) >= 0);
}
