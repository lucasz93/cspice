#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
VOID c_div(f2c, c, a, b)
f2c_state_t *f2c;
complex *a, *b, *c;
#else
void c_div(f2c_state_t *f2c, complex *c, complex *a, complex *b)
#endif
{
	double ratio, den;
	double abr, abi, cr;

	if( (abr = b->r) < 0.)
		abr = - abr;
	if( (abi = b->i) < 0.)
		abi = - abi;
	if( abr <= abi )
		{
		if(abi == 0)
			sig_die(f2c, "complex division by zero", 1);
		ratio = (double)b->r / b->i ;
		den = b->i * (1 + ratio*ratio);
		cr = (a->r*ratio + a->i) / den;
		c->i = (a->i*ratio - a->r) / den;
		}

	else
		{
		ratio = (double)b->i / b->r ;
		den = b->r * (1 + ratio*ratio);
		cr = (a->r + a->i*ratio) / den;
		c->i = (a->i - a->r*ratio) / den;
		}
	c->r = cr;
	}
