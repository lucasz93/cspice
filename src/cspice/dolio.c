#include "f2c.h"
#include "__cspice_state.h"

#ifdef __cplusplus
extern "C" {
#endif
#ifdef KR_headers
integer do_lio(type,number,ptr,len) ftnint *number,*type; char *ptr; ftnlen len;
#else
integer do_lio(ftnint *type, ftnint *number, char *ptr, ftnlen len)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	return((*f2c->f__lioproc)(number,ptr,len,*type));
}
#ifdef __cplusplus
	}
#endif
