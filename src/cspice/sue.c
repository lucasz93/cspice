#include "f2c.h"
#include "fio.h"
#include "__cspice_state.h"

#ifdef KR_headers
c_sue(f2c, a) f2c_state_t *f2c; cilist *a;
#else
c_sue(f2c_state_t *f2c, cilist *a)
#endif
{
	f2c->f__external=f2c->f__sequential=1;
	f2c->f__formatted=0;
	f2c->f__curunit = &f2c->f__units[a->ciunit];
	if(a->ciunit >= MXUNIT || a->ciunit < 0)
		err(f2c,a->cierr,101,"startio");
	f2c->f__elist=a;
	if(f2c->f__curunit->ufd==NULL && fk_open(f2c,SEQ,UNF,a->ciunit))
		err(f2c,a->cierr,114,"sue");
	f2c->f__cf=f2c->f__curunit->ufd;
	if(f2c->f__curunit->ufmt) err(f2c,a->cierr,103,"sue")
	if(!f2c->f__curunit->useek) err(f2c,a->cierr,103,"sue")
	return(0);
}
#ifdef KR_headers
integer s_rsue(f2c, a) f2c_state_t *f2c; cilist *a;
#else
integer s_rsue(f2c_state_t *f2c, cilist *a)
#endif
{
	int n;
	if(!f2c->f__init) f_init(f2c);
	f2c->f__reading=1;
	if(n=c_sue(f2c,a)) return(n);
	f2c->f__recpos=0;
	if(f2c->f__curunit->uwrt && f__nowreading(f2c,f2c->f__curunit))
		err(f2c,a->cierr, errno, "read start");
	if(fread((char *)&f2c->f__reclen,sizeof(uiolen),1,f2c->f__cf)
		!= 1)
	{	if(feof(f2c->f__cf))
		{	f2c->f__curunit->uend = 1;
			err(f2c,a->ciend, EOF, "start");
		}
		clearerr(f2c->f__cf);
		err(f2c,a->cierr, errno, "start");
	}
	return(0);
}
#ifdef KR_headers
integer s_wsue(f2c,a) f2c_state_t *f2c; cilist *a;
#else
integer s_wsue(f2c_state_t *f2c, cilist *a)
#endif
{
	int n;
	if(!f2c->f__init) f_init(f2c);
	if(n=c_sue(f2c, a)) return(n);
	f2c->f__reading=0;
	f2c->f__reclen=0;
	if(f2c->f__curunit->uwrt != 1 && f__nowwriting(f2c,f2c->f__curunit))
		err(f2c,a->cierr, errno, "write start");
	f2c->f__recloc=ftell(f2c->f__cf);
	(void) fseek(f2c->f__cf,(long)sizeof(uiolen),SEEK_CUR);
	return(0);
}
integer e_wsue(f2c_state_t *f2c)
{	long loc;
	fwrite((char *)&f2c->f__reclen,sizeof(uiolen),1,f2c->f__cf);
#ifdef ALWAYS_FLUSH
	if (fflush(f2c->f__cf))
		err(f2c->f__elist->cierr, errno, "write end");
#endif
	loc=ftell(f2c->f__cf);
	fseek(f2c->f__cf,f2c->f__recloc,SEEK_SET);
	fwrite((char *)&f2c->f__reclen,sizeof(uiolen),1,f2c->f__cf);
	fseek(f2c->f__cf,loc,SEEK_SET);
	return(0);
}
integer e_rsue(f2c_state_t *f2c)
{
	(void) fseek(f2c->f__cf,(long)(f2c->f__reclen-f2c->f__recpos+sizeof(uiolen)),SEEK_CUR);
	return(0);
}
