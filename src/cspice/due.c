#include "f2c.h"
#include "fio.h"
#include "__cspice_state.h"

#ifdef KR_headers
c_due(a) cilist *a;
#else
c_due(cilist *a)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	if(!f2c->f__init) f_init();
	f2c->f__sequential=f2c->f__formatted=f2c->f__recpos=0;
	f2c->f__external=1;
	f2c->f__curunit = &f2c->f__units[a->ciunit];
	if(a->ciunit>=MXUNIT || a->ciunit<0)
		err(a->cierr,101,"startio");
	f2c->f__elist=a;
	if(f2c->f__curunit->ufd==NULL && fk_open(DIR,UNF,a->ciunit) ) err(a->cierr,104,"due");
	f2c->f__cf=f2c->f__curunit->ufd;
	if(f2c->f__curunit->ufmt) err(a->cierr,102,"cdue")
	if(!f2c->f__curunit->useek) err(a->cierr,104,"cdue")
	if(f2c->f__curunit->ufd==NULL) err(a->cierr,114,"cdue")
	if(a->cirec <= 0)
		err(a->cierr,130,"due")
	fseek(f2c->f__cf,(long)(a->cirec-1)*f2c->f__curunit->url,SEEK_SET);
	f2c->f__curunit->uend = 0;
	return(0);
}
#ifdef KR_headers
integer s_rdue(a) cilist *a;
#else
integer s_rdue(cilist *a)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	int n;
	f2c->f__reading=1;
	if(n=c_due(a)) return(n);
	if(f2c->f__curunit->uwrt && f__nowreading(f2c->f__curunit))
		err(a->cierr,errno,"read start");
	return(0);
}
#ifdef KR_headers
integer s_wdue(a) cilist *a;
#else
integer s_wdue(cilist *a)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	int n;
	f2c->f__reading=0;
	if(n=c_due(a)) return(n);
	if(f2c->f__curunit->uwrt != 1 && f__nowwriting(f2c->f__curunit))
		err(a->cierr,errno,"write start");
	return(0);
}
integer e_rdue(Void)
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	if(f2c->f__curunit->url==1 || f2c->f__recpos==f2c->f__curunit->url)
		return(0);
	fseek(f2c->f__cf,(long)(f2c->f__curunit->url-f2c->f__recpos),SEEK_CUR);
	if(ftell(f2c->f__cf)%f2c->f__curunit->url)
		err(f2c->f__elist->cierr,200,"syserr");
	return(0);
}
integer e_wdue(Void)
{
#ifdef ALWAYS_FLUSH
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	if (fflush(f2c->f__cf))
		err(f2c->f__elist->cierr,errno,"write end");
#endif
	return(e_rdue());
}
