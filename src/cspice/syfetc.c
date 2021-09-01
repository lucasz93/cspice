/* syfetc.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int syfetc_state_t;
static syfetc_state_t* get_syfetc_state(cspice_t* state) {
	return 0;
}

/* $Procedure      SYFETC ( Fetch the Nth symbol in the table ) */
/* Subroutine */ int syfetc_(cspice_t* __global_state, integer *nth, char *
	tabsym, integer *tabptr, char *tabval, char *name__, logical *found, 
	ftnlen tabsym_len, ftnlen tabval_len, ftnlen name_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer nsym;
    extern integer cardc_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    syfetc_state_t* __state = get_syfetc_state(__global_state);
/* $ Abstract */

/*     Fetch the Nth symbol in a character symbol table. */

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
/*     NTH        I   Index of symbol to be fetched. */
/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL     I   Components of the symbol table. */
/*     NAME       O   Name of the NTH symbol in the symbol table. */
/*     FOUND      O   True if the NTH symbol is in the symbol table, */
/*                    false if it is not. */

/* $ Detailed_Input */

/*     NTH        is the index of the symbol to be fetched. If the NTH */
/*                symbol does not exist, FOUND is FALSE. */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL     are the components of a character symbol table. */
/*                The NTH symbol may or may not be in the symbol */
/*                table. The symbol table is not modified by this */
/*                subroutine. */

/* $ Detailed_Output */

/*     NAME       is the name of the NTH symbol in the symbol table. */

/*     FOUND      is true if the NTH symbol is in the symbol table. */
/*                If the NTH symbol is not in the table, FOUND is false. */

/* $ Parameters */

/*     None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

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

/*     The calls, */

/*     CALL SYFETC (  2,  TABSYM, TABPTR, TABVAL, NAME, FOUND ) */
/*     CALL SYFETC (  3,  TABSYM, TABPTR, TABVAL, NAME, FOUND ) */
/*     CALL SYFETC ( -1,  TABSYM, TABPTR, TABVAL, NAME, FOUND ) */
/*     CALL SYFETC (  4,  TABSYM, TABPTR, TABVAL, NAME, FOUND ) */

/*     result in the values for NAME and FOUND: */

/*     NAME       FOUND */
/*    ----------  ----- */
/*     EINSTEIN    TRUE */
/*     FERMI       TRUE */
/*                FALSE */
/*                FALSE */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     H.A. Neilan     (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -     SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*         Comment section for permuted index source lines was added */
/*         following the header. */

/* -     SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) (HAN) */

/* -& */
/* $ Index_Entries */

/*     fetch the nth symbol in the table */

/* -& */
/* $ Revisions */

/* -     Beta Version 1.1.0, 17-FEB-1989 (NJB) */

/*         Declaration of the unused variable SUMAI removed. */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "SYFETC", (ftnlen)6);
    }

/*     How many symbols to start with? */

    nsym = cardc_(__global_state, tabsym, tabsym_len);

/*     If the value of NTH is out of range, that's a problem. */

    if (*nth < 1 || *nth > nsym) {
	*found = FALSE_;

/*     Otherwise, we can proceed without fear of error. Merely locate */
/*     and return the appropriate component from the values table. */

    } else {
	*found = TRUE_;
	s_copy(&__global_state->f2c, name__, tabsym + (*nth + 5) * tabsym_len,
		 name_len, tabsym_len);
    }
    chkout_(__global_state, "SYFETC", (ftnlen)6);
    return 0;
} /* syfetc_ */

