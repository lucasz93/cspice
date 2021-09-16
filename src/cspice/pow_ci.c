#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
VOID pow_ci(f2c, p, a, b) 	/* p = a**b  */
 f2c_state_t *f2c; complex *p, *a; integer *b;
#else
void pow_ci(f2c_state_t *f2c, complex *p, complex *a, integer *b) 	/* p = a**b  */
#endif
{
doublecomplex p1, a1;

a1.r = a->r;
a1.i = a->i;

pow_zi(f2c, &p1, &a1, b);

p->r = p1.r;
p->i = p1.i;
}
