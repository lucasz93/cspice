#include "f2c.h"
#include "signal1.h"
#include "fprocs.h"

 ftnint
#ifdef KR_headers
signal_(sigp, proc) integer *sigp; sig_pf proc;
#else
signal_(integer *sigp, sig_pf proc)
#endif
{
	int sig;
	sig = (int)*sigp;

	return (ftnint)signal(sig, proc);
	}

static void *signal_user_data = NULL;
static sig_user_pf signal_fn = NULL;

static void signal_user_cb(int err)
{
	signal_fn(signal_user_data, err);
}

sig_pf signal_user(int err, sig_user_pf fn, void *usr)
{
	signal_fn = fn;
	signal_user_data = usr;

	return signal(err, signal_user_cb);
}
