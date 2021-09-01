/* lcase.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern lcase_init_t __lcase_init;
static lcase_state_t* get_lcase_state(cspice_t* state) {
	if (!state->lcase)
		state->lcase = __cspice_allocate_module(sizeof(lcase_state_t),
	 &__lcase_init, sizeof(__lcase_init));
	return state->lcase;

}

/* $Procedure      LCASE ( Convert to lowercase ) */
/* Subroutine */ int lcase_(cspice_t* __global_state, char *in, char *out, 
	ftnlen in_len, ftnlen out_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer i_len(f2c_state_t*, char *, ftnlen);

    /* Local variables */
    integer i__;
    integer ich;


    /* Module state */
    lcase_state_t* __state = get_lcase_state(__global_state);
/* $ Abstract */

/*      Convert the characters in a string to lowercase. */

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

/*     None. */

/* $ Keywords */

/*      ASCII,  CHARACTER */

/* $ Declarations */
/* $ Brief_I/O */

/*      VARIABLE  I/O  DESCRIPTION */
/*      --------  ---  -------------------------------------------------- */
/*      IN         I   Input string. */
/*      OUT        O   Output string, all lowercase. */

/* $ Detailed_Input */

/*      IN          is the input string. */

/* $ Detailed_Output */

/*      OUT         is the output string. This is the input string */
/*                  with all uppercase letters converted to lowercase. */
/*                  Non-letters are not affected. */

/*                  OUT may overwrite IN. */

/* $ Parameters */

/*     None. */

/* $ Particulars */

/*      Convert each uppercase character in IN to lowercase. */

/* $ Examples */

/*      'This is an EXAMPLE'     becomes  'this is an example' */
/*      '12345 +-=? > * $ &'              '12345 +-=? > * $ &' */

/* $ Restrictions */

/*      None. */

/* $ Exceptions */

/*      Error free. */

/* $ Files */

/*      None. */

/* $ Author_and_Institution */

/*      I.M. Underwood  (JPL) */

/* $ Literature_References */

/*      K.R. Gehringer  (JPL) */
/*      None. */

/* $ Version */

/* -     SPICELIB Version 1.1.0, 13-MAR-1996 (KRG) */

/*         Removed the calls to the string lexicographic functions. */

/*         Modified the algorithm to use the ICHAR() intrinsic function */
/*         and some local integer storage for the bases of the lower and */
/*         upper case letters. */

/*         Added a "FIRST" clause to the code so that the lower and */
/*         upper case bases and the separation between them are only */
/*         initialized the first time the subroutine is called rather */
/*         than every time. */

/*         These changes were made to improve the execution speed of */
/*         the subroutine */

/* -     SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*         Comment section for permuted index source lines was added */
/*         following the header. */

/* -     SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     convert to lowercase */

/* -& */

/*     Local variables */


/*     Saved variables */


/*     Initial Data */


/*     Do some set up stuff the first time through so that we do not */
/*     need to reinitialize the boundary values used for comparisons */
/*     and the shift on each call. */

    if (__state->first) {
	__state->first = FALSE_;
	__state->uppera = 'A';
	__state->upperz = 'Z';
	__state->shift = 'a' - __state->uppera;
    }

/*     Move the string from IN to OUT. Step through OUT one character */
/*     at a time, translating letters between 'A' and 'Z' to lowercase. */

    s_copy(&__global_state->f2c, out, in, out_len, in_len);
    i__1 = i_len(&__global_state->f2c, out, out_len);
    for (i__ = 1; i__ <= i__1; ++i__) {
	ich = *(unsigned char *)&out[i__ - 1];
	if (ich >= __state->uppera && ich <= __state->upperz) {
	    *(unsigned char *)&out[i__ - 1] = (char) (ich + __state->shift);
	}
    }
    return 0;
} /* lcase_ */

