/* wnfltd.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int wnfltd_state_t;
static wnfltd_state_t* get_wnfltd_state(cspice_t* state) {
	return 0;
}

/* $Procedure      WNFLTD ( Filter small intervals from a DP window ) */
/* Subroutine */ int wnfltd_(cspice_t* __global_state, doublereal *small, 
	doublereal *window)
{
    integer card;
    integer i__;
    integer j;
    extern integer cardd_(cspice_t*, doublereal *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int scardd_(cspice_t*, integer *, doublereal *);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    wnfltd_state_t* __state = get_wnfltd_state(__global_state);
/* $ Abstract */

/*     Filter (remove) small intervals from a double precision window. */

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

/*      WINDOWS */

/* $ Keywords */

/*     WINDOWS */

/* $ Declarations */
/* $ Brief_I/O */

/*      VARIABLE  I/O  DESCRIPTION */
/*      --------  ---  -------------------------------------------------- */
/*      SMALL      I   Limiting measure of small intervals. */
/*      WINDOW    I,O  Window to be filtered. */

/* $ Detailed_Input */

/*      SMALL       is the limiting measure of the small intervals to */
/*                  be filtered. Intervals of measure less than or equal */
/*                  to SMALL are removed from the window. */

/*      WINDOW      on input, is a window containing zero or more */
/*                  intervals. */

/* $ Detailed_Output */

/*      WINDOW      on output, is the original window, after small */
/*                  intervals have been removed. */

/* $ Parameters */

/*     None. */

/* $ Particulars */

/*      This routine removes from the input window every interval with */
/*      measure less than or equal to the limiting measure (SMALL). */

/* $ Examples */

/*      Let WINDOW contain the intervals */

/*            [ 1, 3 ]  [ 7, 11 ]  [ 23, 27 ]  [ 29, 29 ] */

/*      Then the following series of calls */

/*            CALL WNFLTD (  0, WINDOW )              (1) */
/*            CALL WNFLTD (  2, WINDOW )              (2) */
/*            CALL WNFLTD (  3, WINDOW )              (3) */

/*      produces the following series of windows */

/*            [ 1, 3 ]   [ 7, 11 ]  [ 23, 27 ]         (1) */
/*                       [ 7, 11 ]  [ 23, 27 ]         (2) */
/*                       [ 7, 11 ]  [ 23, 27 ]         (3) */

/* $ Exceptions */

/*     None. */

/* $ Files */

/*      None. */

/* $ Restrictions */

/*      None. */

/* $ Literature_References */

/*      None. */

/* $ Author_and_Institution */

/*      H.A. Neilan     (JPL) */
/*      W.L. Taber      (JPL) */
/*      I.M. Underwood  (JPL) */

/* $ Version */

/* -     SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*         Comment section for permuted index source lines was added */
/*         following the header. */

/* -     SPICELIB Version 1.0.0, 31-JAN-1990 (WLT) (IMU) */

/* -& */
/* $ Index_Entries */

/*     filter small intervals from a d.p. window */

/* -& */
/* $ Revisions */

/* -     Beta Version 1.2.0, 24-FEB-1989  (HAN) */

/*         Added calls to CHKIN and CHKOUT. */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "WNFLTD", (ftnlen)6);
    }

/*     Get the cardinality of the window. (The size is not important; */
/*     this routine can't create any new intervals.) */

    card = cardd_(__global_state, window);

/*     Step through the window, looking for the next interval big */
/*     enough to get stuck in the filter. Keep this up until the last */
/*     interval has been checked. */

    i__ = 0;
    j = 2;
    while(j <= card) {
	if (window[j + 5] - window[j + 4] > *small) {
	    i__ += 2;
	    window[i__ + 4] = window[j + 4];
	    window[i__ + 5] = window[j + 5];
	}
	j += 2;
    }
    scardd_(__global_state, &i__, window);
    chkout_(__global_state, "WNFLTD", (ftnlen)6);
    return 0;
} /* wnfltd_ */

