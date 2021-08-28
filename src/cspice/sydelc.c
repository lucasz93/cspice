/* sydelc.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern sydelc_init_t __sydelc_init;
static inline sydelc_state_t* get_sydelc_state(cspice_t* state) {
	if (!state->sydelc)
		state->sydelc = __cspice_allocate_module(sizeof(
	sydelc_state_t), &__sydelc_init, sizeof(__sydelc_init));
	return state->sydelc;

}

/* $Procedure      SYDELC ( Delete a symbol from the symbol table ) */
/* Subroutine */ int sydelc_(cspice_t* __global_state, char *name__, char *
	tabsym, integer *tabptr, char *tabval, ftnlen name_len, ftnlen 
	tabsym_len, ftnlen tabval_len)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    integer nval;
    integer nptr;
    integer nsym;
    extern integer cardc_(cspice_t*, char *, ftnlen);
    extern integer cardi_(cspice_t*, integer *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern integer sumai_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int scardc_(cspice_t*, integer *, char *, ftnlen);
    extern /* Subroutine */ int remlac_(cspice_t*, integer *, integer *, char 
	    *, integer *, ftnlen);
    extern integer bsrchc_(cspice_t*, char *, integer *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int scardi_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int remlai_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    integer dimval;
    integer locval;
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    integer locsym;
    extern logical return_(cspice_t*);


    /* Module state */
    sydelc_state_t* __state = get_sydelc_state(__global_state);
/* $ Abstract */

/*     Delete a symbol from a character symbol table. The symbol and its */
/*     associated values are deleted. */

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
/*     NAME       I   Name of the symbol to be deleted. */
/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL    I/O  Components of the symbol table. */

/* $ Detailed_Input */

/*     NAME       is the name of the symbol to be deleted from the symbol */
/*                table. If the symbol does not exist, the symbol table */
/*                remains unchanged. This subroutine is case sensitive. */
/*                NAME must the symbol exactly. */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL      are the components of a character symbol table. */
/*                 On input, the table may or may not contain the */
/*                 symbol NAME. */

/* $ Detailed_Output */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL      are the components of a character symbol table. */
/*                 On output, the symbol table no longer contains the */
/*                 symbol NAME or its associated values. If NAME is not */
/*                 a symbol, the components of the symbol table remain */
/*                 unchanged. */

/* $ Parameters */

/*     None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     None. */

/* $ Particulars */

/*     None. */

/* $ Examples */

/*     In the following example the subroutine SYDELC is used to delete */
/*     the symbol "BOHR" and its values from the symbol table. */

/*     The contents of the symbol table are: */

/*        BOHR      -->   HYDROGEN ATOM */
/*        EINSTEIN  -->   SPECIAL RELATIVITY */
/*                        PHOTOELECTRIC EFFECT */
/*                        BROWNIAN MOTION */
/*        FERMI     -->   NUCLEAR FISSION */

/*     The call */

/*     CALL SYDELC ( 'BOHR', TABSYM, TABPTR, TABVAL ) */

/*     deletes the symbol "BOHR" from the symbol table. The components */
/*     of the symbol table on output are: */

/*        EINSTEIN  -->   SPECIAL RELATIVITY */
/*                        PHOTOELECTRIC EFFECT */
/*                        BROWNIAN MOTION */
/*        FERMI     -->   NUCLEAR FISSION */

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

/*     delete a symbol from a symbol table */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "SYDELC", (ftnlen)6);
    }

/*     How many symbols to start with? */

    nsym = cardc_(__global_state, tabsym, tabsym_len);
    nptr = cardi_(__global_state, tabptr);
    nval = cardc_(__global_state, tabval, tabval_len);

/*     Is this symbol even in the table? */

    locsym = bsrchc_(__global_state, name__, &nsym, tabsym + tabsym_len * 6, 
	    name_len, tabsym_len);

/*     If it's not in the table, we're done. If it is, we can proceed */
/*     without fear of overflow. */

    if (locsym > 0) {
	i__1 = locsym - 1;
	locval = sumai_(__global_state, &tabptr[6], &i__1) + 1;
	dimval = tabptr[locsym + 5];
	remlac_(__global_state, &__state->c__1, &locsym, tabsym + tabsym_len *
		 6, &nsym, tabsym_len);
	scardc_(__global_state, &nsym, tabsym, tabsym_len);
	remlai_(__global_state, &__state->c__1, &locsym, &tabptr[6], &nptr);
	scardi_(__global_state, &nptr, tabptr);
	remlac_(__global_state, &dimval, &locval, tabval + tabval_len * 6, &
		nval, tabval_len);
	scardc_(__global_state, &nval, tabval, tabval_len);
    }
    chkout_(__global_state, "SYDELC", (ftnlen)6);
    return 0;
} /* sydelc_ */

