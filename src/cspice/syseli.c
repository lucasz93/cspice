/* syseli.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int syseli_state_t;
static inline syseli_state_t* get_syseli_state(cspice_t* state) {
	return 0;
}

/* $Procedure      SYSELI ( Select a subset of the values of a symbol ) */
/* Subroutine */ int syseli_(cspice_t* __global_state, char *name__, integer *
	begin, integer *end, char *tabsym, integer *tabptr, integer *tabval, 
	integer *values, logical *found, ftnlen name_len, ftnlen tabsym_len)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    integer nsym;
    extern integer cardc_(cspice_t*, char *, ftnlen);
    integer n;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern integer sumai_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int movei_(cspice_t*, integer *, integer *, 
	    integer *);
    extern integer bsrchc_(cspice_t*, char *, integer *, char *, ftnlen, 
	    ftnlen);
    integer locval;
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    integer locsym;
    extern logical return_(cspice_t*);


    /* Module state */
    syseli_state_t* __state = get_syseli_state(__global_state);
/* $ Abstract */

/*     Select a subset of the values associated with a particular */
/*     symbol in an integer symbol table. */

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
/*                    be returned. */
/*     BEGIN      I   Index of the first associated value to be returned. */
/*     END        I   Index of the last associated value to be returned. */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL     I   Components of the symbol table. */

/*     VALUES     O   Subset of the values associated with the symbol */
/*                    NAME. */
/*     FOUND      O   True if the subset of values exists. */

/* $ Detailed_Input */

/*     NAME       is the name of the symbol whose subset of associated */
/*                values to be returned. If NAME is not in the symbol */
/*                table, FOUND is false. */

/*     BEGIN      is the index of the first associated value to be */
/*                returned. If BEGIN is out of range (BEGIN < 1 or */
/*                BEGIN > END) FOUND is false. */

/*     END        is the index of the last associated value to be */
/*                returned. If END is out of range (END < 1 or */
/*                END > is greater than the dimension of NAME) */
/*                FOUND is false. */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL     are components of the integer symbol table. */

/* $ Detailed_Output */

/*     VALUES     is a subset of the values associated with the */
/*                symbol NAME. If the subset specified by BEGIN and */
/*                END exists, as many values as will fit in VALUES */
/*                are returned. If the subset does not exist, no */
/*                values are returned and FOUND is false. */

/*     FOUND      is true if the subset of values is exists. */
/*                FOUND is false if BEGIN < 1, BEGIN > END, END < 1, */
/*                END > the dimension of NAME, or NAME is not */
/*                in the symbol table. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  This subroutine does not check to see if the output array */
/*         VALUES is large enough to hold the selected set of values. */
/*         The caller must provide the required space. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     FOUND will be false if the bounds of the subset specified by */
/*     BEGIN and END are out of range. Values of BEGIN and END which */
/*     specify bounds out of range are BEGIN < 1, BEGIN > END, */
/*     END < 1, or END > the dimension of NAME. FOUND is also false */
/*     if the symbol NAME is not in the symbol table. */

/* $ Examples */

/*     The contents of the symbol table are: */

/*        books   -->   5 */
/*                     10 */
/*        erasers -->   3 */
/*        pencils -->  12 */
/*                     18 */
/*                     24 */
/*                     30 */
/*        pens    -->  10 */
/*                     20 */
/*                     30 */

/*     Let the dimension of the array VALUES be 4. */

/*     The ouput values of VALUES and FOUND for the input values of */
/*     NAME, BEGIN, and END are contained in this table: */

/*     NAME         BEGIN    END     VALUES    FOUND */
/*     ----------   -----    ---    --------  ------- */
/*     pencils        2       3        18       TRUE */
/*                                     24 */

/*     pencils        1       4        12       TRUE */
/*                                     18 */
/*                                     24 */
/*                                     30 */

/*     desks          1       5                FALSE */

/*     books          2       1                FALSE */

/*     erasers        1      -2                FALSE */

/*     pens           1       5                FALSE */
/*     ---------------------------------------------------------------- */

/*     Note that FOUND is FALSE for examples 3 through 6 because: */

/*        - In the 3rd example, the symbol 'desks' is not in the */
/*          symbol table. */

/*        - In the 4th example, BEGIN > END. */

/*        - In the 5th example, END < 0. */

/*        - In the 6th example, END is greater than the dimension of the */
/*          symbol 'pens'. */

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

/*     select a subset of the values of a symbol */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "SYSELI", (ftnlen)6);
    }

/*     How many symbols to start with? */

    nsym = cardc_(__global_state, tabsym, tabsym_len);

/*     Is this symbol even in the table? */

    locsym = bsrchc_(__global_state, name__, &nsym, tabsym + tabsym_len * 6, 
	    name_len, tabsym_len);

/*     If it's not in the table, it's definitely a problem. */

    if (locsym == 0) {
	*found = FALSE_;
    } else {

/*        We could still have a problem: do these components exist? */
/*        Does this request even make sense? */

	n = tabptr[locsym + 5];
	if (*begin >= 1 && *begin <= n && *end >= 1 && *end <= n && *begin <= 
		*end) {
	    *found = TRUE_;
	    i__1 = locsym - 1;
	    locval = sumai_(__global_state, &tabptr[6], &i__1) + 1;
	    i__1 = *end - *begin + 1;
	    movei_(__global_state, &tabval[locval + *begin + 4], &i__1, 
		    values);
	} else {
	    *found = FALSE_;
	}
    }
    chkout_(__global_state, "SYSELI", (ftnlen)6);
    return 0;
} /* syseli_ */

