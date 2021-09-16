#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
VOID r_cnjg(f2c, r, z) f2c_state_t *f2c; complex *r, *z;
#else
VOID r_cnjg(f2c_state_t *f2c, complex *r, complex *z)
#endif
{
r->r = z->r;
r->i = - z->i;
}
