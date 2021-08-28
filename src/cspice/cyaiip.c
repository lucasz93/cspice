/* cyaiip.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int cyaiip_state_t;
static inline cyaiip_state_t* get_cyaiip_state(cspice_t* state) {
	return 0;
}

/* $Procedure CYAIIP ( Cycle the elements of an integer array, in place ) */
/* Subroutine */ int cyaiip_(cspice_t* __global_state, integer *nelt, char *
	dir, integer *ncycle, integer *array, ftnlen dir_len)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    integer last;
    integer temp;
    integer g;
    integer i__;
    integer j;
    integer k;
    integer l;
    integer m;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);
    extern integer gcd_(cspice_t*, integer *, integer *);


    /* Module state */
    cyaiip_state_t* __state = get_cyaiip_state(__global_state);
/* $ Abstract */

/*     Cycle the elements of an integer array forward or backward */
/*     in place. */

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

/*     ARRAY */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     NELT       I   Number of elements. */
/*     DIR        I   Direction to cycle: 'F' or 'B'. */
/*     NCYCLE     I   Number of times to cycle. */
/*     ARRAY     I-O  Array to be cycled/cycled array. */

/* $ Detailed_Input */

/*     NELT        is the number of elements in the input array. */

/*     DIR         is the direction in which the elements in the */
/*                 array are to be cycled. */

/*                    'F' or 'f'  to cycle forward. */
/*                    'B' or 'b'  to cycle backward. */

/*     NCYCLE      is the number of times the elements in the array */
/*                 are to be cycled. */

/*     ARRAY       is the array to be cycled. */

/* $ Detailed_Output */

/*     ARRAY       is the input array after it has been cycled. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If the value of DIR is not recognized, the error */
/*        SPICE(INVALIDDIRECTION) is signaled. */

/*     2) If NELT is less than 1, the output array is not modified. */

/*     3) If NCYCLE is negative, the array is cycled NCYCLE times in */
/*        the opposite direction of DIR. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine cycles an integer array in place. To cycle */
/*     an array and store the result in a new array, use CYCLAI. */

/*     An array is cycled when its contents are shifted forward or */
/*     backward by one place. An element pushed off one end of the */
/*     array is brought around to the other end of the array instead */
/*     of disappearing. */

/* $ Examples */

/*     Let the integer array A contain the following elements. */

/*        A(1) = 1 */
/*        A(2) = 2 */
/*        A(3) = 3 */
/*        A(4) = 4 */

/*     Cycling A forward once yields the array */

/*        A(1) = 4 */
/*        A(2) = 1 */
/*        A(3) = 2 */
/*        A(4) = 3 */

/*     Cycling A backward once yields the array */

/*        A(1) = 2 */
/*        A(2) = 3 */
/*        A(3) = 4 */
/*        A(4) = 1 */

/*     Cycling by any multiple of the number of elements in the array */
/*     yields the same array. */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     H.A. Neilan     (JPL) */
/*     W.L. Taber      (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 09-SEP-2005 (NJB) (HAN) (WLT) (IMU) */

/* -& */
/* $ Index_Entries */

/*     cycle the elements of an integer array in place */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "CYAIIP", (ftnlen)6);
    }

/*     Don't even screw around if there are no elements in the array. */

    if (*nelt < 1) {
	chkout_(__global_state, "CYAIIP", (ftnlen)6);
	return 0;
    }

/*     A backward cycle is the same as a forward cycle by the opposite */
/*     of NCYCLE.  Moreover a cycle by K is the same as a cycle by */
/*     K + m*N for any integer m.  Thus we compute the value of the */
/*     minimum forward right cycle that is equivalent to the inputs. */

    if (*(unsigned char *)dir == 'B' || *(unsigned char *)dir == 'b') {
	k = -(*ncycle) % *nelt;
    } else if (*(unsigned char *)dir == 'F' || *(unsigned char *)dir == 'F') {
	k = *ncycle % *nelt;
    } else {
	setmsg_(__global_state, "Cycling direction was *.", (ftnlen)24);
	errch_(__global_state, "*", dir, (ftnlen)1, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDDIRECTION)", (ftnlen)23);
	chkout_(__global_state, "CYAIIP", (ftnlen)6);
	return 0;
    }
    if (k < 0) {
	k += *nelt;
    } else if (k == 0) {
	chkout_(__global_state, "CYAIIP", (ftnlen)6);
	return 0;
    }

/*     The algorithm used to cycle arrays is identical to the one used */
/*     to cycle character strings in CYCLEC. We won't repeat the (rather */
/*     lengthy) description here. */

    g = gcd_(__global_state, &k, nelt);
    m = *nelt / g;
    i__1 = g;
    for (i__ = 1; i__ <= i__1; ++i__) {
	l = i__;
	last = array[l - 1];
	i__2 = m;
	for (j = 1; j <= i__2; ++j) {
	    l += k;
	    if (l > *nelt) {
		l -= *nelt;
	    }
	    temp = array[l - 1];
	    array[l - 1] = last;
	    last = temp;
	}
    }
    chkout_(__global_state, "CYAIIP", (ftnlen)6);
    return 0;
} /* cyaiip_ */

