#ifndef NON_UNIX_STDIO
#define _INCLUDE_POSIX_SOURCE	/* for HP-UX */
#define _INCLUDE_XOPEN_SOURCE	/* for HP-UX */
#include "sys/types.h"
#include "sys/stat.h"
#endif
#include "f2c.h"
#include "fio.h"
#include "fprocs.h"

 VOID
#ifdef KR_headers
g_char(f2c,a,alen,b) f2c_state_t *f2c; char *a,*b; ftnlen alen;
#else
g_char(f2c_state_t *f2c, char *a, ftnlen alen, char *b)
#endif
{
	char *x = a + alen, *y = b + alen;

	for(;; y--) {
		if (x <= a) {
			*b = 0;
			return;
			}
		if (*--x != ' ')
			break;
		}
	*y-- = 0;
	do *y-- = *x;
		while(x-- > a);
	}

 VOID
#ifdef KR_headers
b_char(f2c,a,b,blen) f2c_state_t *f2c; char *a,*b; ftnlen blen;
#else
b_char(f2c_state_t *f2c, char *a, char *b, ftnlen blen)
#endif
{	int i;
	for(i=0;i<blen && *a!=0;i++) *b++= *a++;
	for(;i<blen;i++) *b++=' ';
}
#ifndef NON_UNIX_STDIO
#ifdef KR_headers
long f__inode(f2c, a, dev) f2c_state_t *f2c; char *a; int *dev;
#else
long f__inode(f2c_state_t *f2c, char *a, int *dev)
#endif
{	struct stat x;
	if(stat(a,&x)<0) return(-1);
	*dev = x.st_dev;
	return(x.st_ino);
}
#endif
