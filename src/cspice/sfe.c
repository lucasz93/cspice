/* sequential formatted external common routines*/
#include "f2c.h"
#include "fio.h"
#include "__cspice_state.h"

integer e_rsfe(Void)
{	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	int n;
	n=en_fio();
	f2c->f__fmtbuf=NULL;
	return(n);
}
#ifdef KR_headers
c_sfe(a) cilist *a; /* check */
#else
c_sfe(cilist *a) /* check */
#endif
{	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	unit *p;
	f2c->f__curunit = p = &f2c->f__units[a->ciunit];
	if(a->ciunit >= MXUNIT || a->ciunit<0)
		err(a->cierr,101,"startio");
	if(p->ufd==NULL && fk_open(SEQ,FMT,a->ciunit)) err(a->cierr,114,"sfe")
	if(!p->ufmt) err(a->cierr,102,"sfe")
	return(0);
}
integer e_wsfe(Void)
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	int n = en_fio();
	f2c->f__fmtbuf = NULL;
	return n;
}
