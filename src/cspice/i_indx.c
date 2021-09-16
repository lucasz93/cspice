#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
integer i_indx(f2c, a, b, la, lb) f2c_state_t *f2c; char *a, *b; ftnlen la, lb;
#else
integer i_indx(f2c_state_t *f2c, char *a, char *b, ftnlen la, ftnlen lb)
#endif
{
ftnlen i, n;
char *s, *t, *bend;

n = la - lb + 1;
bend = b + lb;

for(i = 0 ; i < n ; ++i)
	{
	s = a + i;
	t = b;
	while(t < bend)
		if(*s++ != *t++)
			goto no;
	return(i+1);
	no: ;
	}
return(0);
}
