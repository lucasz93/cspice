/* sequential formatted external common routines*/
#include "f2c.h"
#include "fio.h"
#include "fprocs.h"

integer e_rsfe(f2c_state_t *f2c)
{	int n;
	n=en_fio(f2c);
	f2c->f__fmtbuf=NULL;
	return(n);
}
#ifdef KR_headers
c_sfe(f2c, a) f2c_state_t *f2c; cilist *a; /* check */
#else
c_sfe(f2c_state_t *f2c, cilist *a) /* check */
#endif
{	unit *p;
	f2c->f__curunit = p = &f2c->f__units[a->ciunit];
	if(a->ciunit >= MXUNIT || a->ciunit<0)
		err(f2c,a->cierr,101,"startio");
	if(p->ufd==NULL && fk_open(f2c,SEQ,FMT,a->ciunit)) err(f2c,a->cierr,114,"sfe")
	if(!p->ufmt) err(f2c,a->cierr,102,"sfe")
	return(0);
}
integer e_wsfe(f2c_state_t *f2c)
{
	int n = en_fio(f2c);
	f2c->f__fmtbuf = NULL;
	return n;
}
