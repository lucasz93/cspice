#include "f2c.h"
#include "fio.h"
#include "__cspice_state.h"
#include "fprocs.h"
#ifdef KR_headers
integer f_rew(f2c,a) f2c_state_t *f2c; alist *a;
#else
integer f_rew(f2c_state_t *f2c, alist *a)
#endif
{
	unit *b;
	if(a->aunit>=MXUNIT || a->aunit<0)
		err(f2c,a->aerr,101,"rewind");
	b = &f2c->f__units[a->aunit];
	if(b->ufd == NULL || b->uwrt == 3)
		return(0);
	if(!b->useek)
		err(f2c,a->aerr,106,"rewind")
	if(b->uwrt) {
		(void) t_runc(f2c,a);
		b->uwrt = 3;
		}
	rewind(b->ufd);
	b->uend=0;
	return(0);
}
