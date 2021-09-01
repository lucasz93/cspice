/* sypshd.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern sypshd_init_t __sypshd_init;
static sypshd_state_t* get_sypshd_state(cspice_t* state) {
	if (!state->sypshd)
		state->sypshd = __cspice_allocate_module(sizeof(
	sypshd_state_t), &__sypshd_init, sizeof(__sypshd_init));
	return state->sypshd;

}

/* $Procedure      SYPSHD ( Push a value onto a particular symbol ) */
/* Subroutine */ int sypshd_(cspice_t* __global_state, char *name__, 
	doublereal *value, char *tabsym, integer *tabptr, doublereal *tabval, 
	ftnlen name_len, ftnlen tabsym_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer nval;
    integer nsym;
    extern integer cardc_(cspice_t*, char *, ftnlen);
    extern integer cardd_(cspice_t*, doublereal *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    extern integer sized_(cspice_t*, doublereal *);
    extern integer sumai_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int scardd_(cspice_t*, integer *, doublereal *);
    extern /* Subroutine */ int inslad_(cspice_t*, doublereal *, integer *, 
	    integer *, doublereal *, integer *);
    integer locval;
    extern integer lstlec_(cspice_t*, char *, integer *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    integer locsym;
    logical oldsym;
    extern /* Subroutine */ int sysetd_(cspice_t*, char *, doublereal *, char 
	    *, integer *, doublereal *, ftnlen, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    sypshd_state_t* __state = get_sypshd_state(__global_state);
/* $ Abstract */

/*     Push a value onto a particular symbol in a double precision */
/*     symbol table. The previous value(s) associated with the symbol */
/*     is extended at the front. A new symbol is created if necessary. */

/* $ Disclaimer */

/*     THIS SOFTWARE AND ANY RELATED MATERIALS WERE CREATED BY THE */
/*     CALIFORNIA INSTITUTE OF TECHNOLOGY (CALTECH) UNDER A U.S. */
/*     GOVERNMENT CONTRACT WITH THE NATIONAL AERONAUTICS AND SPACE */
/*     ADMINISTRATION (NASA). THE SOFTWARE IS TECHNOLOGY AND SOFTWARE */
/*     PUBLICLY AVAILABLE UNDER U.S. EXPORT LAWS AND IS PROVIDED "AS-IS" */
/*     TO THE RECIPIENT WITHOUT WARRANTY OF ANY KIND, INCLUDING ANY */
/*     WARRANTIES OF PERFORMANCE OR MERCHANTABILITY OR FITNESS FOR A */
/*     PARTICULAR USE OR PURPOSE (AS SET FORTH IN UNITED STATES UCC */
/*     SECTIONS 2312-2313) OR FOR ANY PURPOSE WHATSOEVER, FOR THE */
/*     SOFTWARE AND RELATED MATERIALS, HOWEVER USED. */

/*     IN NO EVENT SHALL CALTECH, ITS JET PROPULSION LABORATORY, OR NASA */
/*     BE LIABLE FOR ANY DAMAGES AND/OR COSTS, INCLUDING, BUT NOT */
/*     LIMITED TO, INCIDENTAL OR CONSEQUENTIAL DAMAGES OF ANY KIND, */
/*     INCLUDING ECONOMIC DAMAGE OR INJURY TO PROPERTY AND LOST PROFITS, */
/*     REGARDLESS OF WHETHER CALTECH, JPL, OR NASA BE ADVISED, HAVE */
/*     REASON TO KNOW, OR, IN FACT, SHALL KNOW OF THE POSSIBILITY. */

/*     RECIPIENT BEARS ALL RISK RELATING TO QUALITY AND PERFORMANCE OF */
/*     THE SOFTWARE AND ANY RELATED MATERIALS, AND AGREES TO INDEMNIFY */
/*     CALTECH AND NASA FOR ALL THIRD-PARTY CLAIMS RESULTING FROM THE */
/*     ACTIONS OF RECIPIENT IN THE USE OF THE SOFTWARE. */

/* $ Required_Reading */

/*     SYMBOLS */

/* $ Keywords */

/*     SYMBOLS */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     NAME       I   Name of the symbol onto which the value is to be */
/*                    pushed. */
/*     VALUE      I   Value that is to be pushed onto the symbol NAME. */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL    I/O  Components of the symbol table. */

/* $ Detailed_Input */

/*     NAME       is the name of the symbol onto which the value is to */
/*                be pushed. If NAME is not in the symbol table, a new */
/*                symbol is created. */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL     are the components of a double precision symbol table. */

/* $ Detailed_Output */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL     are the components of a double precision symbol table. */
/*                The value is added to the symbol table at the front */
/*                of the previous value(s) associated with the symbol */
/*                NAME. If NAME is not originally in the symbol table, */
/*                a new symbol is created. */

/* $ Parameters */

/*     None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     1) If the addition of the new value to the symbol table */
/*        causes an overflow in the value table, the error */
/*        SPICE(VALUETABLEFULL) is signalled. */

/* $ Particulars */

/*     If the symbol NAME is not in the symbol table, a new symbol */
/*     is created. */

/* $ Examples */

/*     The contents of the symbol table are: */

/*        BODY4_POLE_RA -->    1.08D-1 */
/*                             0.0D0 */
/*        DELTA_T_A     -->    3.2184D1 */
/*        K             -->    1.657D-3 */
/*        MEAN_ANOM     -->    6.239996D0 */
/*                             1.99096871D-7 */
/*        ORBIT_ECC     -->    1.671D-2 */

/*     The call, */

/*     CALL SYPSHD ( 'BODY4_POLE_RA',  3.17681D2, */
/*    .               TABSYM,          TABPTR,         TABVAL ) */

/*     modifies the contents of the symbol table to be: */

/*        BODY4_POLE_RA -->    3.17681D2 */
/*                             1.08D-1 */
/*                             0.0D0 */
/*        DELTA_T_A     -->    3.2184D1 */
/*        K             -->    1.657D-3 */
/*        MEAN_ANOM     -->    6.239996D0 */
/*                             1.99096871D-7 */
/*        ORBIT_ECC     -->    1.671D-2 */

/*     The next call, */

/*     CALL SYPSHC ( 'BODY4_GM', 4.2826286548993737D4, */
/*    .               TABSYM,     TABPTR,                TABVAL ) */

/*     modifies the contents of the symbol table to be: */

/*        BODY4_GM      -->    4.2826286548993737D4 */
/*        BODY4_POLE_RA -->    3.17681D2 */
/*                             1.08D-1 */
/*                             0.0D0 */
/*        DELTA_T_A     -->    3.2184D1 */
/*        K             -->    1.657D-3 */
/*        MEAN_ANOM     -->    6.239996D0 */
/*                             1.99096871D-7 */
/*        ORBIT_ECC     -->    1.671D-2 */

/*     Note that a new symbol "BODY4_GM" was created by the last call. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     H.A. Neilan     (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -     SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*         Comment section for permuted index source lines was added */
/*         following the header. */

/* -     SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) (HAN) */

/* -& */
/* $ Index_Entries */

/*     push a value onto a particular symbol */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "SYPSHD", (ftnlen)6);
    }

/*     How many symbols to start with? */

    nsym = cardc_(__global_state, tabsym, tabsym_len);
    nval = cardd_(__global_state, tabval);

/*     Where does this symbol belong? Is it already in the table? */

    locsym = lstlec_(__global_state, name__, &nsym, tabsym + tabsym_len * 6, 
	    name_len, tabsym_len);
    oldsym = locsym != 0 && s_cmp(&__global_state->f2c, tabsym + (locsym + 5) 
	    * tabsym_len, name__, tabsym_len, name_len) == 0;

/*     If it's not already in the table, use SET to create a brand new */
/*     symbol. */

    if (! oldsym) {
	sysetd_(__global_state, name__, value, tabsym, tabptr, tabval, 
		name_len, tabsym_len);

/*     If it is in the table, we can't proceed unless we know that we */
/*     have enough room for one extra addition in the value table. */

    } else if (nval >= sized_(__global_state, tabval)) {
	setmsg_(__global_state, "SYPSHD: The addition of the value $ to the "
		"symbol # causes an overflow in the value table.", (ftnlen)90);
	errdp_(__global_state, "$", value, (ftnlen)1);
	errch_(__global_state, "#", name__, (ftnlen)1, name_len);
	sigerr_(__global_state, "SPICE(VALUETABLEFULL)", (ftnlen)21);

/*     If there's room, add the new value to the value table. Add one */
/*     to the dimension, and put the value in the right place. */

    } else {
	i__1 = locsym - 1;
	locval = sumai_(__global_state, &tabptr[6], &i__1) + 1;
	inslad_(__global_state, value, &__state->c__1, &locval, &tabval[6], &
		nval);
	scardd_(__global_state, &nval, tabval);
	++tabptr[locsym + 5];
    }
    chkout_(__global_state, "SYPSHD", (ftnlen)6);
    return 0;
} /* sypshd_ */

