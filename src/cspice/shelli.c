/* shelli.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int shelli_state_t;
static shelli_state_t* get_shelli_state(cspice_t* state) {
	return 0;
}

/* $Procedure      SHELLI ( Shell sort an integer array ) */
/* Subroutine */ int shelli_(cspice_t* __global_state, integer *ndim, integer 
	*array)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    integer i__;
    integer j;
    extern /* Subroutine */ int swapi_(cspice_t*, integer *, integer *);
    integer jg;
    integer gap;


    /* Module state */
    shelli_state_t* __state = get_shelli_state(__global_state);
/* $ Abstract */

/*      Sort an integer array using the Shell Sort algorithm. */

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

/*      ARRAY,  SORT */

/* $ Declarations */
/* $ Brief_I/O */

/*      VARIABLE  I/O  DESCRIPTION */
/*      --------  ---  -------------------------------------------------- */
/*      NDIM       I   Dimension of the array. */
/*      ARRAY     I/O  The array. */

/* $ Detailed_Input */

/*      NDIM        is the number of elements in the array to be sorted. */

/*      ARRAY       on input, is the array to be sorted. */

/* $ Detailed_Output */

/*      ARRAY       on output, contains the same elements, sorted */
/*                  in increasing order. The actual sorting is done */
/*                  in place in ARRAY. */

/* $ Parameters */

/*     None. */

/* $ Particulars */

/*      The Shell Sort Algorithm is well known. */

/* $ Examples */

/*      Let ARRAY contain the following elements: */

/*            99 */
/*            33 */
/*            55 */
/*            44 */
/*           -77 */
/*            66 */

/*      Then after a call to SHELLI, the array would be ordered as */
/*      follows: */

/*           -77 */
/*            33 */
/*            44 */
/*            55 */
/*            66 */
/*            99 */

/* $ Restrictions */

/*      None. */

/* $ Exceptions */

/*      Error free. */

/* $ Files */

/*      None. */

/* $ Author_and_Institution */

/*      I.M. Underwood  (JPL) */

/* $ Literature_References */

/*      None. */

/* $ Version */

/* -     SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*         Comment section for permuted index source lines was added */
/*         following the header. */

/* -     SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     shell sort an integer array */

/* -& */

/*     Local variables */


/*     This is a straightforward implementation of the Shell Sort */
/*     algorithm. */

    gap = *ndim / 2;
    while(gap > 0) {
	i__1 = *ndim;
	for (i__ = gap + 1; i__ <= i__1; ++i__) {
	    j = i__ - gap;
	    while(j > 0) {
		jg = j + gap;
		if (array[j - 1] <= array[jg - 1]) {
		    j = 0;
		} else {
		    swapi_(__global_state, &array[j - 1], &array[jg - 1]);
		}
		j -= gap;
	    }
	}
	gap /= 2;
    }
    return 0;
} /* shelli_ */

