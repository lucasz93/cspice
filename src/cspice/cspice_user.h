#define USER_T

#ifdef USER_T

/* zzadsave */
#define SPICE_N_PASSED_IN_FUNC     8
#include "SpiceZdf.h"

/* zzerror */
#define     MSG_LEN             2024
#define     OUT_LEN             2*MSG_LEN

typedef struct {
    struct {
        int first;
        double value;
    } dpmax_c;

    struct {
        int first;
        double value;
    } dpmin_c;

    struct {
        double value;
    } dpr_c;

    struct {
        double value;
    } halfpi_c;

    struct {
        int first;
        double value;
    } intmax_c;

    struct {
        int first;
        double value;
    } intmin_c;

    struct {
        double value;
    } pi_c;

    struct {
        double value;
    } rpd_c;

    struct {
        double value;
    } twopi_c;

    struct {
        /*
        The function pointer list is accessed by the functions

            zzadsave_c ( Save a function pointer for adapter use )
            zzadget_c  ( Get a function pointer for adapter use  )
        */
        void * funcPtrList [ SPICE_N_PASSED_IN_FUNC ];
    } zzadsave;

    struct {
        /*
        Initialize the count to zero. Save the value
        between calls.
        */
        int count;
    } zzalloc;

    struct {
        char msg_short [OUT_LEN];
    } zzerror;

    struct {
        SpiceBoolean first;
    } zzerrorinit;

    struct {
        SpiceInt          CML_argc;
        SpiceChar      ** CML_argv;
        SpiceBoolean      first;
    } zzgetcml;

    struct {
        SpiceBoolean signalStatus;
    } zzgfsavh;
} cspice_user_state_t;

static void __cspice_init_user(cspice_user_state_t *user)
{
    user->dpmax_c.first = 1;
    user->dpmin_c.first = 1;
    user->dpr_c.value = 0.;
    user->halfpi_c.value = 0.;
    user->intmax_c.first = 1;
    user->intmin_c.first = 1;
    user->pi_c.value = 0.;
    user->rpd_c.value = 0.;
    user->twopi_c.value = 0.;

    user->zzalloc.count = 0;

    user->zzerrorinit.first = SPICETRUE;

    user->zzgetcml.first = SPICETRUE;

    user->zzgfsavh.signalStatus = SPICEFALSE;
}

static void __cspice_free_user(cspice_user_state_t *user)
{

}
#endif
