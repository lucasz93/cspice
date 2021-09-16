#include "f2c.h"
#include "fprocs.h"
#undef abs
#undef min
#undef max
#include "stdio.h"

/* MECHSOFT: Read only. Safe to keep as static. */
static integer memfailure = 3;

#ifdef KR_headers
extern char *malloc();

 char *
F77_aloc(f2c, Len, whence) f2c_state_t *f2c; integer Len; char *whence;
#else
#include "stdlib.h"

 char *
F77_aloc(f2c_state_t *f2c, integer Len, char *whence)
#endif
{
	char *rv;
	unsigned int uLen = (unsigned int) Len;	/* for K&R C */

	if (!(rv = (char*)malloc(uLen))) {
		fprintf(stderr, "malloc(%u) failure in %s\n",
			uLen, whence);
		exit_(f2c, &memfailure);
		}
	return rv;
	}
