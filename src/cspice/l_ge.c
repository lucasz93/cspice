#include "f2c.h"

#ifdef KR_headers
extern integer s_cmp();
logical l_ge(f2c,a,b,la,lb) f2c_state_t *f2c; char *a, *b; ftnlen la, lb;
#else
extern integer s_cmp(f2c_state_t *f2c, char *, char *, ftnlen, ftnlen);
logical l_ge(f2c_state_t *f2c, char *a, char *b, ftnlen la, ftnlen lb)
#endif
{
return(s_cmp(f2c, a,b,la,lb) >= 0);
}
