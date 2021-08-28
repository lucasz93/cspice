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
    user->zzalloc.count = 0;

    user->zzerrorinit.first = SPICETRUE;

    user->zzgetcml.first = SPICETRUE;

    user->zzgfsavh.signalStatus = SPICEFALSE;
}

static void __cspice_free_user(cspice_user_state_t *user)
{

}
#endif
