/* synthd.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int synthd_state_t;
static synthd_state_t* get_synthd_state(cspice_t* state) {
	return 0;
}

/* $Procedure      SYNTHD ( Return the Nth component of a symbol ) */
/* Subroutine */ int synthd_(cspice_t* __global_state, char *name__, integer *
	nth, char *tabsym, integer *tabptr, doublereal *tabval, doublereal *
	value, logical *found, ftnlen name_len, ftnlen tabsym_len)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    integer nsym;
    extern integer cardc_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern integer sumai_(cspice_t*, integer *, integer *);
    extern integer bsrchc_(cspice_t*, char *, integer *, char *, ftnlen, 
	    ftnlen);
    integer locval;
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    integer locsym;
    extern logical return_(cspice_t*);


    /* Module state */
    synthd_state_t* __state = get_synthd_state(__global_state);
/* $ Abstract */

/*     Return the Nth component of a particular symbol in a double */
/*     precision symbol table. */

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
/*     NAME       I   Name of the symbol whose Nth component is to be */
/*                    returned. */
/*     NTH        I   Index of the value to be returned. */
/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL     I   Components of the symbol table. */
/*     VALUE      O   Nth value associated with the symbol. */
/*     FOUND      O   True if the Nth value of the symbol exists, false */
/*                    if it does not. */

/* $ Detailed_Input */

/*     NAME       is the name of the symbol whose Nth component is to be */
/*                returned. If NAME is not in the symbol table, FOUND is */
/*                false. */

/*     NTH        is the index of the component to be returned. If the */
/*                value of NTH is out of range ( NTH < 1 or NTH is */
/*                greater than the dimension of the symbol ) FOUND is */
/*                false. */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL     are the components of a double precision symbol table. */
/*                The symbol table is not modified by this subroutine. */

/* $ Detailed_Output */

/*     VALUES     is the NTH component of the symbol NAME. */

/*     FOUND      is true if NAME is in the symbol table and the NTH */
/*                component of NAME exists.  Otherwise FOUND is false. */

/* $ Parameters */

/*     None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     None. */

/* $ Particulars */

/*     Two conditions will cause the value of FOUND to be false: */

/*       1) The symbol NAME is not in the symbol table. */

/*       2) NTH is out of range ( NTH < 1 or NTH is greater than the */
/*          dimension of the symbol ). */

/* $ Examples */

/*     The contents of the symbol table are: */

/*        BODY4_POLE_RA -->    3.17681D2 */
/*                             1.08D-1 */
/*                             0.0D0 */
/*        DELTA_T_A     -->    3.2184D1 */
/*        K             -->    1.657D-3 */
/*        MEAN_ANOM     -->    6.239996D0 */
/*                             1.99096871D-7 */
/*        ORBIT_ECC     -->    1.671D-2 */

/*     The calls, */

/*     CALL SYNTHD ( 'MEAN_ANOM',     2, TABSYM, TABPTR, TABVAL, VALUE, */
/*    .               FOUND                                             ) */

/*     CALL SYNTHD ( 'BODY4_PRIME',   1, TABSYM, TABPTR, TABVAL, VALUE, */
/*    .               FOUND                                             ) */

/*     CALL SYNTHD ( 'ORBIT_ECC',    -5, TABSYM, TABPTR, TABVAL, VALUE, */
/*    .               FOUND                                             ) */

/*     return the values of VALUE and FOUND corresponding to NAME and */
/*     NTH: */

/*     NAME            NTH           VALUE            FOUND */
/*     ----------     -----     ----------------      ------- */
/*     MEAN_ANOM        2        1.99096871D-7          TRUE */
/*     BODY4_PRIME      1                              FALSE */
/*     ORBIT_ECC       -5                              FALSE */

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

/*     fetch nth value associated with a symbol */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "SYNTHD", (ftnlen)6);
    }

/*     How many symbols to start with? */

    nsym = cardc_(__global_state, tabsym, tabsym_len);

/*     Is this symbol even in the table? */

    locsym = bsrchc_(__global_state, name__, &nsym, tabsym + tabsym_len * 6, 
	    name_len, tabsym_len);

/*     If it's not in the table, it's definitely a problem. */

    if (locsym == 0) {
	*found = FALSE_;

/*     If the value of NTH is out of range, that's a problem too. */

    } else if (*nth < 1 || *nth > tabptr[locsym + 5]) {
	*found = FALSE_;

/*     Otherwise, we can proceed without fear of error. Merely locate */
/*     and return the appropriate component from the values table. */

    } else {
	*found = TRUE_;
	i__1 = locsym - 1;
	locval = sumai_(__global_state, &tabptr[6], &i__1) + *nth;
	*value = tabval[locval + 5];
    }
    chkout_(__global_state, "SYNTHD", (ftnlen)6);
    return 0;
} /* synthd_ */

