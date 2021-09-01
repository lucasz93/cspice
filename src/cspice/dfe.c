#include "f2c.h"
#include "fio.h"
#include "fmt.h"
#include "__cspice_state.h"

int y_rsk(f2c_state_t *f2c)
{
	if(f2c->f__curunit->uend || f2c->f__curunit->url <= f2c->f__recpos
		|| f2c->f__curunit->url == 1) return 0;
	do {
		getc(f2c->f__cf);
	} while(++f2c->f__recpos < f2c->f__curunit->url);
	return 0;
}
int y_getc(f2c_state_t *f2c)
{
	int ch;
	if(f2c->f__curunit->uend) return(-1);
	if((ch=getc(f2c->f__cf))!=EOF)
	{
		f2c->f__recpos++;
		if(f2c->f__curunit->url>=f2c->f__recpos ||
			f2c->f__curunit->url==1)
			return(ch);
		else	return(' ');
	}
	if(feof(f2c->f__cf))
	{
		f2c->f__curunit->uend=1;
		errno=0;
		return(-1);
	}
	err(f2c,f2c->f__elist->cierr,errno,"readingd");
}

 static int
y_rev(f2c_state_t *f2c)
{
	if (f2c->f__recpos < f2c->f__hiwater)
		f2c->f__recpos = f2c->f__hiwater;
	if (f2c->f__curunit->url > 1)
		while(f2c->f__recpos < f2c->f__curunit->url)
			(*f2c->f__putn)(f2c,' ');
	if (f2c->f__recpos)
		f__putbuf(f2c,0);
	f2c->f__recpos = 0;
	return(0);
}

 static int
y_err(f2c_state_t *f2c)
{
	err(f2c,f2c->f__elist->cierr, 110, "dfe");
}

 static int
y_newrec(f2c_state_t *f2c)
{
	y_rev(f2c);
	f2c->f__hiwater = f2c->f__cursor = 0;
	return(1);
}

#ifdef KR_headers
c_dfe(f2c, a) f2c_state_t *f2c; cilist *a;
#else
int c_dfe(f2c_state_t *f2c, cilist *a)
#endif
{
	f2c->f__sequential=0;
	f2c->f__formatted=f2c->f__external=1;
	f2c->f__elist=a;
	f2c->f__cursor=f2c->f__scale=f2c->f__recpos=0;
	f2c->f__curunit = &f2c->f__units[a->ciunit];
	if(a->ciunit>MXUNIT || a->ciunit<0)
		err(f2c,a->cierr,101,"startchk");
	if(f2c->f__curunit->ufd==NULL && fk_open(f2c,DIR,FMT,a->ciunit))
		err(f2c,a->cierr,104,"dfe");
	f2c->f__cf=f2c->f__curunit->ufd;
	if(!f2c->f__curunit->ufmt) err(f2c,a->cierr,102,"dfe")
	if(!f2c->f__curunit->useek) err(f2c,a->cierr,104,"dfe")
	f2c->f__fmtbuf=a->cifmt;
	if(a->cirec <= 0)
		err(f2c,a->cierr,130,"dfe")
	fseek(f2c->f__cf,(long)f2c->f__curunit->url * (a->cirec-1),SEEK_SET);
	f2c->f__curunit->uend = 0;
	return(0);
}
#ifdef KR_headers
integer s_rdfe(f2c, a) f2c_state_t *f2c; cilist *a;
#else
integer s_rdfe(f2c_state_t *f2c, cilist *a)
#endif
{
	int n;
	if(!f2c->f__init) f_init(f2c);
	f2c->f__reading=1;
	if(n=c_dfe(f2c, a))return(n);
	if(f2c->f__curunit->uwrt && f__nowreading(f2c,f2c->f__curunit))
		err(f2c,a->cierr,errno,"read start");
	f2c->f__getn = y_getc;
	f2c->f__doed = rd_ed;
	f2c->f__doned = rd_ned;
	f2c->f__dorevert = f2c->f__donewrec = y_err;
	f2c->f__doend = y_rsk;
	if(pars_f(f2c,f2c->f__fmtbuf)<0)
		err(f2c,a->cierr,100,"read start");
	fmt_bg(f2c);
	return(0);
}
#ifdef KR_headers
integer s_wdfe(f2c, a) f2c_state_t *f2c; cilist *a;
#else
integer s_wdfe(f2c_state_t *f2c, cilist *a)
#endif
{
	int n;
	if(!f2c->f__init) f_init(f2c);
	f2c->f__reading=0;
	if(n=c_dfe(f2c, a)) return(n);
	if(f2c->f__curunit->uwrt != 1 && f__nowwriting(f2c,f2c->f__curunit))
		err(f2c,a->cierr,errno,"startwrt");
	f2c->f__putn = x_putc;
	f2c->f__doed = w_ed;
	f2c->f__doned= w_ned;
	f2c->f__dorevert = y_err;
	f2c->f__donewrec = y_newrec;
	f2c->f__doend = y_rev;
	if(pars_f(f2c,f2c->f__fmtbuf)<0)
		err(f2c,a->cierr,100,"startwrt");
	fmt_bg(f2c);
	return(0);
}
integer e_rdfe(f2c_state_t *f2c)
{
	en_fio(f2c);
	return 0;
}
integer e_wdfe(f2c_state_t *f2c)
{
	return en_fio(f2c);
}
