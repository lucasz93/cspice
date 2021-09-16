#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
VOID pow_zi(f2c, p, a, b) 	/* p = a**b  */
 f2c_state_t *f2c;
 doublecomplex *p, *a; integer *b;
#else
void pow_zi(f2c_state_t *f2c, doublecomplex *p, doublecomplex *a, integer *b) 	/* p = a**b  */
#endif
{
	integer n;
	unsigned long u;
	double t;
	doublecomplex q, x;
	/* MECHSOFT: Read only. Safe to keep static. */
	static doublecomplex one = {1.0, 0.0};

	n = *b;
	q.r = 1;
	q.i = 0;

	if(n == 0)
		goto done;
	if(n < 0)
		{
		n = -n;
		z_div(f2c, &x, &one, a);
		}
	else
		{
		x.r = a->r;
		x.i = a->i;
		}

	for(u = n; ; )
		{
		if(u & 01)
			{
			t = q.r * x.r - q.i * x.i;
			q.i = q.r * x.i + q.i * x.r;
			q.r = t;
			}
		if(u >>= 1)
			{
			t = x.r * x.r - x.i * x.i;
			x.i = 2 * x.r * x.i;
			x.r = t;
			}
		else
			break;
		}
 done:
	p->i = q.i;
	p->r = q.r;
	}
