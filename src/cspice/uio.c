#include "f2c.h"
#include "fio.h"
#include "__cspice_state.h"

#ifdef KR_headers
do_us(f2c,number,ptr,len) f2c_state_t *f2c; ftnint *number; char *ptr; ftnlen len;
#else
do_us(f2c_state_t *f2c, ftnint *number, char *ptr, ftnlen len)
#endif
{
	if(f2c->f__reading)
	{
		f2c->f__recpos += (int)(*number * len);
		if(f2c->f__recpos>f2c->f__reclen)
			err(f2c->f__elist->cierr, 110, "do_us");
		if (fread(ptr,(int)len,(int)(*number),f2c->f__cf) != *number)
			err(f2c->f__elist->ciend, EOF, "do_us");
		return(0);
	}
	else
	{
		f2c->f__reclen += *number * len;
		(void) fwrite(ptr,(int)len,(int)(*number),f2c->f__cf);
		return(0);
	}
}
#ifdef KR_headers
integer do_ud(f2c,number,ptr,len) f2c_state_t *f2c; ftnint *number; char *ptr; ftnlen len;
#else
integer do_ud(f2c_state_t *f2c, ftnint *number, char *ptr, ftnlen len)
#endif
{
	f2c->f__recpos += (int)(*number * len);
	if(f2c->f__recpos > f2c->f__curunit->url && f2c->f__curunit->url!=1)
		err(f2c->f__elist->cierr,110,"do_ud");
	if(f2c->f__reading)
	{
#ifdef Pad_UDread
#ifdef KR_headers
	int i;
#else
	size_t i;
#endif
		if (!(i = fread(ptr,(int)len,(int)(*number),f2c->f__cf))
		 && !(f2c->f__recpos - *number*len))
			err(f2c->f__elist->cierr,EOF,"do_ud")
		if (i < *number)
			memset(ptr + i*len, 0, (*number - i)*len);
		return 0;
#else
		if(fread(ptr,(int)len,(int)(*number),f2c->f__cf) != *number)
			err(f2c->f__elist->cierr,EOF,"do_ud")
		else return(0);
#endif
	}
	(void) fwrite(ptr,(int)len,(int)(*number),f2c->f__cf);
	return(0);
}
#ifdef KR_headers
integer do_uio(f2c,number,ptr,len) f2c_state_t *f2c; ftnint *number; char *ptr; ftnlen len;
#else
integer do_uio(f2c_state_t *f2c, ftnint *number, char *ptr, ftnlen len)
#endif
{
	if(f2c->f__sequential)
		return(do_us(f2c,number,ptr,len));
	else	return(do_ud(f2c,number,ptr,len));
}
