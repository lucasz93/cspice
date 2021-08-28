/* sygetc.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int sygetc_state_t;
static inline sygetc_state_t* get_sygetc_state(cspice_t* state) {
	return 0;
}

/* $Procedure      SYGETC ( Return all components for a symbol ) */
/* Subroutine */ int sygetc_(cspice_t* __global_state, char *name__, char *
	tabsym, integer *tabptr, char *tabval, integer *n, char *values, 
	logical *found, ftnlen name_len, ftnlen tabsym_len, ftnlen tabval_len,
	 ftnlen values_len)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    integer nsym;
    extern integer cardc_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int movec_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    extern integer sumai_(cspice_t*, integer *, integer *);
    extern integer bsrchc_(cspice_t*, char *, integer *, char *, ftnlen, 
	    ftnlen);
    integer locval;
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    integer locsym;
    extern logical return_(cspice_t*);


    /* Module state */
    sygetc_state_t* __state = get_sygetc_state(__global_state);
/* $ Abstract */

/*     Return the dimension and associated values for a particular */
/*     symbol. */

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
/*     NAME       I   Name of the symbol whose components are to be */
/*                    returned. */
/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL     I   Components of the symbol table. */

/*     N          O   Dimension of the symbol. */
/*     VALUES     O   Values associated with the symbol. */
/*     FOUND      O   True if the symbol NAME is in the symbol table, */
/*                    false if it is not. */

/* $ Detailed_Input */

/*     NAME       is the name of the symbol whose components are to be */
/*                returned. If NAME is not in the symbol table, FOUND is */
/*                false. */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL     are the components of a character symbol table. */
/*                The symbol NAME may or may not be in the symbol */
/*                table. The symbol table is not modified by this */
/*                subroutine. */

/* $ Detailed_Output */

/*     N          is the dimension of the symbol NAME. The dimension is */
/*                the number of values associated with the given symbol. */
/*                N is defined only if the output argument FOUND is */
/*                .TRUE. */

/*     VALUES     is an array containing the values associated with the */
/*                symbol. If the array is not large enough to hold all */
/*                of the values associated with NAME, as many as will */
/*                fit are returned.  VALUES is defined only if the */
/*                output argument FOUND is .TRUE. */

/*     FOUND      is true if NAME is in the symbol table. If NAME is not */
/*                in the table, FOUND is false. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  This subroutine does not check to see if the output array */
/*         VALUES is large enough to hold all of the values associated */
/*         with the symbol NAME.  The caller must provide the required */
/*         space. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     None. */

/* $ Examples */

/*     The contents of the symbol table are: */

/*        BOHR      -->   HYDROGEN ATOM */
/*        EINSTEIN  -->   SPECIAL RELATIVITY */
/*                        PHOTOELECTRIC EFFECT */
/*                        BROWNIAN MOTION */
/*        FERMI     -->   NUCLEAR FISSION */

/*     Let the dimension of VALUES be 3. */

/*     The calls, */

/*     CALL SYGETC ( 'EINSTEIN', TABSYM, TABPTR, TABVAL, */
/*    .               N,         VALUES, FOUND           ) */

/*     CALL SYGETC ( 'MILLIKAN', TABSYM, TABPTR, TABVAL, */
/*    .               N,         VALUES, FOUND           ) */

/*     CALL SYGETC ( 'BORN',     TABSYM, TABPTR, TABVAL, */
/*    .               N,         VALUES, FOUND           ) */


/*     return the values for N, VALUES, and FOUND associated with NAME: */

/*     NAME         N        VALUES                      FOUND */
/*     ----------  ---      -----------------------     ------- */
/*     EINSTEIN     3        SPECIAL RELATIVITY           TRUE */
/*                           PHOTOELECTRIC EFFECT */
/*                           BROWNIAN MOTION */
/*     MILLIKAN                                          FALSE */
/*     BORN         1        HYDROGEN ATOM                TRUE */


/* $ Restrictions */

/*     1) See Exceptions section. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     H.A. Neilan     (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -     SPICELIB Version 1.0.2, 03-NOV-2005 (NJB) */

/*         Various header corrections were made.  In particular, */
/*         the header no longer asserts that this routine will */
/*         "return as many values as will fit" in the output array */
/*         VALUES. */

/* -     SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*         Comment section for permuted index source lines was added */
/*         following the header. */

/* -     SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) (HAN) */

/* -& */
/* $ Index_Entries */

/*     fetch all components for a symbol */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "SYGETC", (ftnlen)6);
    }

/*     How many symbols to start with? */

    nsym = cardc_(__global_state, tabsym, tabsym_len);

/*     Is this symbol even in the table? */

    locsym = bsrchc_(__global_state, name__, &nsym, tabsym + tabsym_len * 6, 
	    name_len, tabsym_len);

/*     If it's not in the table, it's definitely a problem. */

    if (locsym == 0) {
	*found = FALSE_;

/*     Otherwise, we can proceed without fear of error. Merely locate */
/*     and return the appropriate component from the values table. */
/*     We trust that the user has supplied enough room. */

    } else {
	*found = TRUE_;
	i__1 = locsym - 1;
	locval = sumai_(__global_state, &tabptr[6], &i__1) + 1;
	*n = tabptr[locsym + 5];
	movec_(__global_state, tabval + (locval + 5) * tabval_len, n, values, 
		tabval_len, values_len);
    }
    chkout_(__global_state, "SYGETC", (ftnlen)6);
    return 0;
} /* sygetc_ */

