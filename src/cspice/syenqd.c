/* syenqd.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern syenqd_init_t __syenqd_init;
static inline syenqd_state_t* get_syenqd_state(cspice_t* state) {
	if (!state->syenqd)
		state->syenqd = __cspice_allocate_module(sizeof(
	syenqd_state_t), &__syenqd_init, sizeof(__syenqd_init));
	return state->syenqd;

}

/* $Procedure      SYENQD ( Enqueue a value onto a symbol ) */
/* Subroutine */ int syenqd_(cspice_t* __global_state, char *name__, 
	doublereal *value, char *tabsym, integer *tabptr, doublereal *tabval, 
	ftnlen name_len, ftnlen tabsym_len)
{
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
    syenqd_state_t* __state = get_syenqd_state(__global_state);
/* $ Abstract */

/*     Enqueue a value onto a particular symbol in a double precision */
/*     symbol table. If the symbol is not in the table, a new one */
/*     is created. */

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
/*     NAME       I   Name of the symbol onto which the value is */
/*                    enqueued. */
/*     VALUE      I   Value to be enqueued. */
/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL    I/O  Components of the symbol table. */

/* $ Detailed_Input */

/*     NAME       is the name of the symbol onto which the value is to */
/*                be enqueued. If NAME is not in the symbol table, a new */
/*                symbol having the value VALUE is created. */

/*     VALUE      is the value to be enqueued onto the symbol, NAME. */
/*                The value is inserted in the value table after the */
/*                last value associated with the symbol. */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL     are the components of a double precision symbol table. */
/*                The symbol NAME may or may not be in the symbol */
/*                table. */

/* $ Detailed_Output */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL      are the components of a double precision symbol table. */
/*                 On output, the value table contains the new value */
/*                 in addition to the old values associated with the */
/*                 symbol NAME. The pointer table is updated to */
/*                 reflect the change in the dimension of the symbol. */

/* $ Parameters */

/*     None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     1) If the addition of the new value to the symbol table */
/*        causes an overflow in the value table, the error */
/*        SPICE(VALUETABLEFULL) is signalled. */

/* $ Particulars */

/*     If the symbol NAME is not in the symbol table, a new symbol is */
/*     created which has the value VALUE. */

/* $ Examples */

/*     The contents of the symbol table are: */

/*        DELTA_T_A -->   32.184 */
/*        K         -->    1.657D-3 */
/*        MEAN_ANOM -->    6.239996D0 */
/*                         1.99096871D-7 */
/*        ORBIT_ECC -->    1.671D-2 */

/*     The call, */

/*     CALL SYENQD ( 'BODY399_POLE_RA', 0.0D0, TABSYM, TABPTR, TABVAL ) */

/*     produces the symbol table: */

/*        BODY399_POLE_RA -->    0.0D0 */
/*        DELTA_T_A       -->   32.184 */
/*        K               -->    1.657D-3 */
/*        MEAN_ANOM       -->    6.239996D0 */
/*                               1.99096871D-7 */
/*        ORBIT_ECC       -->    1.671D-2 */

/*     Notice that the new symbol "BODY399_POLE_RA" has been created and */
/*     has the value 0.0D0 associated with it. */

/*     The next call, */

/*     CALL SYENQD ( 'BODY399_POLE_RA', -6.4061614D-1, */
/*    .               TABSYM, TABPTR, TABVAL           ) */

/*     CALL SYENQD ( 'BODY399_POLE_RA', -8.386D-5, */
/*    .               TABSYM, TABPTR, TABVAL           ) */

/*     then produces the symbol table: */

/*        BODY399_POLE_RA -->    0.0D0 */
/*                              -6.4061614D-1 */
/*                              -8.386D-5 */
/*        DELTA_T_A       -->   32.184 */
/*        K               -->    1.657D-3 */
/*        MEAN_ANOM       -->    6.239996D0 */
/*                               1.99096871D-7 */
/*        ORBIT_ECC       -->    1.671D-2 */

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

/*     enqueue a value onto a symbol */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "SYENQD", (ftnlen)6);
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
	setmsg_(__global_state, "SYENQD: The addition of the value $ to the "
		"symbol # causes an overflow in the value table.", (ftnlen)90);
	errdp_(__global_state, "$", value, (ftnlen)1);
	errch_(__global_state, "#", name__, (ftnlen)1, name_len);
	sigerr_(__global_state, "SPICE(VALUETABLEFULL)", (ftnlen)21);

/*     If there's room, add the new value to the value table. Add one */
/*     to the dimension, and put the value in the right place. */

    } else {
	locval = sumai_(__global_state, &tabptr[6], &locsym) + 1;
	inslad_(__global_state, value, &__state->c__1, &locval, &tabval[6], &
		nval);
	scardd_(__global_state, &nval, tabval);
	++tabptr[locsym + 5];
    }
    chkout_(__global_state, "SYENQD", (ftnlen)6);
    return 0;
} /* syenqd_ */

