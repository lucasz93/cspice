/* sytrnc.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int sytrnc_state_t;
static inline sytrnc_state_t* get_sytrnc_state(cspice_t* state) {
	return 0;
}

/* $Procedure      SYTRNC (Transpose two values associated with a symbol) */
/* Subroutine */ int sytrnc_(cspice_t* __global_state, char *name__, integer *
	i__, integer *j, char *tabsym, integer *tabptr, char *tabval, ftnlen 
	name_len, ftnlen tabsym_len, ftnlen tabval_len)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    integer nsym;
    extern integer cardc_(cspice_t*, char *, ftnlen);
    integer n;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int swapc_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern integer sumai_(cspice_t*, integer *, integer *);
    extern integer bsrchc_(cspice_t*, char *, integer *, char *, ftnlen, 
	    ftnlen);
    integer locval;
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    integer locsym;
    extern logical return_(cspice_t*);


    /* Module state */
    sytrnc_state_t* __state = get_sytrnc_state(__global_state);
/* $ Abstract */

/*     Transpose two values associated with a particular symbol in a */
/*     character symbol table. */

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
/*     NAME       I   Name of the symbol whose associated values are to */
/*                    be transposed. */
/*     I          I   Index of the first associated value to be */
/*                    transposed. */
/*     J          I   Index of the second associated value to be */
/*                    transposed. */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL    I/O  Components of the symbol table. */

/* $ Detailed_Input */

/*     NAME       is the name of the symbol whose associated values are */
/*                to be transposed. */

/*     I          is the index of the first associated value to be */
/*                transposed. */

/*     J          is the index of the second associated value to be */
/*                transposed. */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL     are components of the character symbol table. */

/* $ Detailed_Output */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL     are components of the character symbol table. */
/*                If the symbol NAME is not in the symbol table */
/*                the symbol tables are not modified. Otherwise, */
/*                the values that I and J refer to are transposed */
/*                in the value table. */

/* $ Parameters */

/*     None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     1) If I < 1, J < 1, I > the dimension of NAME, or J > the */
/*        dimension of NAME, the error SPICE(INVALIDINDEX) is signaled. */

/*     2) If NAME is not in the symbol table, the symbol tables are not */
/*        modified. */

/* $ Particulars */

/*     None. */

/* $ Examples */

/*     The contents of the symbol table are: */

/*        BOHR      -->   HYDROGEN ATOM */
/*        EINSTEIN  -->   SPECIAL RELATIVITY */
/*                        PHOTOELECTRIC EFFECT */
/*                        BROWNIAN MOTION */
/*        FERMI     -->   NUCLEAR FISSION */
/*        PAULI     -->   EXCLUSION PRINCIPLE */
/*                        NEUTRINO */

/*     The call, */

/*     CALL SYTRNC ( 'EINSTEIN', 2, 3, TABSYM, TABPTR, TABVAL ) */

/*     modifies the contents of the symbol table to be: */

/*        BOHR      -->   HYDROGEN ATOM */
/*        EINSTEIN  -->   SPECIAL RELATIVITY */
/*                        BROWNIAN MOTION */
/*                        PHOTOELECTRIC EFFECT */
/*        FERMI     -->   NUCLEAR FISSION */
/*        PAULI     -->   EXCLUSION PRINCIPLE */
/*                        NEUTRINO */

/*     The next call, */

/*     CALL SYTRNC ( 'PAULI', 2, 4, TABSYM, TABPTR, TABVAL ) */

/*     causes the error SPICE(INVALIDINDEX) to be signaled. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     H.A. Neilan     (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 09-SEP-2005 (NJB) */

/*        Updated so no "exchange" occurs if I equals J. */

/* -     SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*         Comment section for permuted index source lines was added */
/*         following the header. */

/* -     SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) (HAN) */

/* -& */
/* $ Index_Entries */

/*     transpose two values associated with a symbol */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.1.0, 09-SEP-2005 (NJB) */

/*        Updated so no "exchange" occurs if I equals J. */

/* -     Beta Version 2.0.0, 16-JAN-1989 (HAN) */

/*         If one of the indices of the values to be transposed is */
/*         invalid, an error is signaled and the symbol table is */
/*         not modified. */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "SYTRNC", (ftnlen)6);
    }

/*     How many symbols? */

    nsym = cardc_(__global_state, tabsym, tabsym_len);

/*     Is this symbol even in the table? */

    locsym = bsrchc_(__global_state, name__, &nsym, tabsym + tabsym_len * 6, 
	    name_len, tabsym_len);
    if (locsym > 0) {

/*        Are there enough values associated with the symbol? */

	n = tabptr[locsym + 5];

/*        Are the indices valid? */

	if (*i__ >= 1 && *i__ <= n && *j >= 1 && *j <= n) {

/*           Exchange the values in place. */

	    if (*i__ != *j) {
		i__1 = locsym - 1;
		locval = sumai_(__global_state, &tabptr[6], &i__1) + 1;
		swapc_(__global_state, tabval + (locval + *i__ + 4) * 
			tabval_len, tabval + (locval + *j + 4) * tabval_len, 
			tabval_len, tabval_len);
	    }
	} else {
	    setmsg_(__global_state, "The first index was *. The second index"
		    " was *.", (ftnlen)46);
	    errint_(__global_state, "*", i__, (ftnlen)1);
	    errint_(__global_state, "*", j, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(INVALIDINDEX)", (ftnlen)19);
	}
    }
    chkout_(__global_state, "SYTRNC", (ftnlen)6);
    return 0;
} /* sytrnc_ */

