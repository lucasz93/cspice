#include "f2c.h"
#include "fprocs.h"

 VOID
#ifdef KR_headers
d_cnjg(f2c, r, z) f2c_state_t *f2c; doublecomplex *r, *z;
#else
d_cnjg(f2c_state_t *f2c, doublecomplex *r, doublecomplex *z)
#endif
{
r->r = z->r;
r->i = - z->i;
}
