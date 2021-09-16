#include "f2c.h"
#include "fprocs.h"

#ifdef KR_headers
double pow();
double pow_dd(f2c, ap, bp) f2c_state_t *f2c; doublereal *ap, *bp;
#else
#undef abs
#include "math.h"
double pow_dd(f2c_state_t *f2c, doublereal *ap, doublereal *bp)
#endif
{
return(pow(*ap, *bp) );
}
