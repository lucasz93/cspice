#include "f2c.h"
#include "fio.h"
#include "__cspice_state.h"
#ifdef KR_headers
integer f_clos(f2c, a) f2c_state_t *f2c; cllist *a;
#else
#undef abs
#undef min
#undef max
#include "stdlib.h"
#ifdef NON_UNIX_STDIO
#ifndef unlink
#define unlink remove
#endif
#else
#ifdef MSDOS
#include "io.h"
#else
#ifdef __cplusplus
extern "C" int unlink(const char*);
#else
extern int unlink(const char*);
#endif
#endif
#endif

integer f_clos(f2c_state_t *f2c, cllist *a)
#endif
{	unit *b;

	if(a->cunit >= MXUNIT) return(0);
	b= &f2c->f__units[a->cunit];
	if(b->ufd==NULL)
		goto done;
	if (b->uscrtch == 1)
		goto Delete;
	if (!a->csta)
		goto Keep;
	switch(*a->csta) {
		default:
	 	Keep:
		case 'k':
		case 'K':
			if(b->uwrt == 1)
				t_runc((alist *)a);
			if(b->ufnm) {
				fclose(b->ufd);
				free(b->ufnm);
				}
			break;
		case 'd':
		case 'D':
		Delete:
			fclose(b->ufd);
			if(b->ufnm) {
				unlink(b->ufnm); /*SYSDEP*/
				free(b->ufnm);
				}
		}
	b->ufd=NULL;
 done:
	b->uend=0;
	b->ufnm=NULL;
	return(0);
	}
 void
#ifdef KR_headers
f_exit(f2c) f2c_state_t *f2c;
#else
f_exit(f2c_state_t *f2c)
#endif
{	int i;
	if (!f2c->xx.cerr) {
		f2c->xx.cerr=1;
		f2c->xx.csta=NULL;
		for(i=0;i<MXUNIT;i++)
		{
			f2c->xx.cunit=i;
			(void) f_clos(f2c, &f2c->xx);
		}
	}
}
 int
#ifdef KR_headers
flush_(f2c) f2c_state_t *f2c;
#else
flush_(f2c_state_t *f2c)
#endif
{	int i;
	for(i=0;i<MXUNIT;i++)
		if(f2c->f__units[i].ufd != NULL && f2c->f__units[i].uwrt)
			fflush(f2c->f__units[i].ufd);
return 0;
}
