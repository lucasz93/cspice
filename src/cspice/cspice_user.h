#define USER_T

#ifdef USER_T
/* dtime */
#ifndef USE_CLOCK
#define _INCLUDE_POSIX_SOURCE   /* for HP-UX */
#define _INCLUDE_XOPEN_SOURCE   /* for HP-UX */
#include "sys/times.h"
#endif

/* err */
#include "fio.h"

/* fmt */
#ifdef interdata
#define SYLMX 300
#endif
#ifdef pdp11
#define SYLMX 300
#endif
#ifdef vax
#define SYLMX 300
#endif
#ifndef SYLMX
#define SYLMX 300
#endif
#include "fmt.h"

/* fmtlib */
#define MAXINTLENGTH 23

/* rsne */
typedef struct hashentry {
    struct hashentry *next;
    char *name;
    Vardesc *vd;
} hashentry;

typedef struct hashtab {
    struct hashtab *next;
    Namelist *nl;
    int htsize;
    hashentry *tab[1];
} hashtab;

typedef struct {
    cllist xx;

#ifdef MSDOS
        double t0;
#else
        struct tms t0;
#endif

    unit f__units[MXUNIT];   /*unit table*/
    flag f__init;   /*0 on entry, 1 after initializations*/
    cilist *f__elist;   /*active external io list*/
    icilist *f__svic;   /*active internal io list*/
    flag f__reading;   /*1 if reading, 0 if writing*/
    flag f__cplus,f__cblank;
    char *f__fmtbuf;
    flag f__external;   /*1 if external io, 0 if internal */

    int (*f__getn)(void);   /* for formatted input */
    void (*f__putn)(int);   /* for formatted output */
    int (*f__doed)(struct syl*, char*, ftnlen),(*f__doned)(struct syl*);
    int (*f__dorevert)(void),(*f__donewrec)(void),(*f__doend)(void);

    flag f__sequential;   /*1 if sequential io, 0 if direct*/
    flag f__formatted;   /*1 if formatted io, 0 if unformatted*/
    FILE *f__cf;   /*current file*/
    unit *f__curunit;   /*current unit*/
    int f__recpos;   /*place in current record*/
    int f__cursor, f__hiwater, f__scale;
    char *f__icptr;

    struct syl f__syl[SYLMX];
    int f__parenlvl,f__pc,f__revloc;

#define STKSZ 10
    int f__cnt[STKSZ],f__ret[STKSZ],f__cp,f__rp;
    flag f__workdone, f__nonl;

    char *f__icend;
    int f__icnum;

#ifdef Allow_TYQUAD
    longint f__llx;
#endif
    int l_eof;
#ifdef KR_headers
     int (*f__lioproc)(), (*l_getc)(), (*l_ungetc)();
#else
     int (*f__lioproc)(ftnint*, char*, ftnlen, ftnint), (*l_getc)(void), (*l_ungetc)(int,FILE*);
#endif

    flag f__lquit;
    int f__lcount,f__ltype,nml_read;
    char *f__lchar;
    double f__lx,f__ly;

    ftnint L_len;
    int f__Aquote;

    char f__buf0[400];
    char* f__buf;
    int f__buflen;

    long f__recloc;

    uiolen f__reclen;

    /*
        The variable read_non_native is set via the function zzsetnnread_.
        This variable has file scope; functions in this file use it 
        to decide whether to handle non-native line termination.
        The functions rdknew_ and rdkdat_ should turn on non-native
        line termination handling before calling rdtext_ and turn this
        feature off immediately after rdtext_ returns.
    */
    logical read_non_native;

    char buf[MAXINTLENGTH+1];

     hashtab *nl_cache;
    int n_nlcache;
    hashentry **zot;
    int colonseen;
} f2c_state_t;

/* zzadsave */
#define SPICE_N_PASSED_IN_FUNC     8
#include "SpiceZdf.h"

/* zzerror */
#define     MSG_LEN             2024
#define     OUT_LEN             2*MSG_LEN

typedef struct {
    f2c_state_t f2c;

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
    f2c_state_t* f2c = &user->f2c;

    f2c->f__init = 0;

    f2c->f__buf = f2c->f__buf0;
    f2c->f__buflen = sizeof(f2c->f__buf);

    f2c->read_non_native = 0;

    user->zzalloc.count = 0;

    user->zzerrorinit.first = SPICETRUE;

    user->zzgetcml.first = SPICETRUE;

    user->zzgfsavh.signalStatus = SPICEFALSE;
}

static void __cspice_free_user(cspice_user_state_t *user)
{

}
#endif
