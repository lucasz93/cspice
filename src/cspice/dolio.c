#include "f2c.h"
#include "__cspice_state.h"

#ifdef __cplusplus
extern "C" {
#endif
#ifdef KR_headers
integer do_lio(f2c, type,number,ptr,len) f2c_state_t *f2c; ftnint *number,*type; char *ptr; ftnlen len;
#else
integer do_lio(f2c_state_t *f2c, ftnint *type, ftnint *number, char *ptr, ftnlen len)
#endif
{
	return((*f2c->f__lioproc)(number,ptr,len,*type));
}
#ifdef __cplusplus
	}
#endif
