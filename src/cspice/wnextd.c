/* wnextd.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int wnextd_state_t;
static wnextd_state_t* get_wnextd_state(cspice_t* state) {
	return 0;
}

/* $Procedure      WNEXTD ( Extract the endpoints from a DP window ) */
/* Subroutine */ int wnextd_(cspice_t* __global_state, char *side, doublereal 
	*window, ftnlen side_len)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    integer card;
    integer i__;
    extern integer cardd_(cspice_t*, doublereal *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    wnextd_state_t* __state = get_wnextd_state(__global_state);
/* $ Abstract */

/*     Extract the left or right endpoints from a double precision */
/*     window. */

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

/*     WINDOWS */

/* $ Keywords */

/*     WINDOWS */

/* $ Declarations */
/* $ Brief_I/O */

/*      VARIABLE  I/O  DESCRIPTION */
/*      --------  ---  -------------------------------------------------- */
/*      SIDE       I   Extract left ('L') or right ('R') endpoints. */
/*      WINDOW    I,O  Window to be extracted. */

/* $ Detailed_Input */

/*      SIDE        indicates whether the left or right endpoints of */
/*                  the intervals in the window are to be extracted. */

/*                        'L', 'l'       Left endpoints. */
/*                        'R', 'r'       Right endpoints. */

/*                  If SIDE is not recognized, the input window is */
/*                  not changed. */

/*      WINDOW      on input, is a window containing zero or more */
/*                  intervals. */

/* $ Detailed_Output */

/*      WINDOW      on output, is the collection of singleton intervals */
/*                  containing either the left or the right endpoints */
/*                  of the intervals in the original window. */

/* $ Parameters */

/*     None. */

/* $ Particulars */

/*      This routine replaces every interval in the input window with */
/*      the singleton interval containing one of the endpoints of the */
/*      interval. */

/* $ Examples */

/*      Let WINDOW contain the intervals */

/*            [ 1, 3 ]  [ 7, 11 ]  [ 23, 27 ]  [ 29, 29 ] */

/*      Then the call */

/*            CALL WNEXTD (  'L', WINDOW ) */

/*      produces the window */

/*            [ 1, 1 ]  [ 7, 7 ]  [ 23, 23 ]  [ 29, 29 ] */

/*      And the call */

/*            CALL WNEXTD ( 'R', WINDOW ) */

/*      produces the window */

/*            [ 3, 3 ]  [ 11, 11 ]  [ 27, 27 ]  [ 29, 29 ] */

/* $ Exceptions */

/*     1) If the endpoint specification, SIDE, is not recognized, the */
/*        error SPICE(INVALIDENDPNTSPEC) is signalled. */

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

/*     extract the endpoints from a d.p. window */

/* -& */
/* $ Revisions */

/* -     Beta Version 1.2.0, 24-FEB-1989  (HAN) */

/*         Added calls to CHKIN and CHKOUT. Error handling was added to */
/*         detect invalid endpoint specification. The previous version */
/*         did not signal an error if SIDE was not 'R', 'r', 'L', or 'l'. */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "WNEXTD", (ftnlen)6);
    }

/*     Get the cardinality of the window. (The size is not important; */
/*     this routine can't create any new intervals.) */

    card = cardd_(__global_state, window);

/*     Step through the window, keeping one endpoint from each interval. */
/*     For the sake of efficiency, we have separate loops for the two */
/*     possible values of SIDE. */

    if (*(unsigned char *)side == 'L' || *(unsigned char *)side == 'l') {
	i__1 = card;
	for (i__ = 1; i__ <= i__1; i__ += 2) {
	    window[i__ + 6] = window[i__ + 5];
	}
    } else if (*(unsigned char *)side == 'R' || *(unsigned char *)side == 'r')
	     {
	i__1 = card;
	for (i__ = 1; i__ <= i__1; i__ += 2) {
	    window[i__ + 5] = window[i__ + 6];
	}
    } else {
	setmsg_(__global_state, "SIDE was *.", (ftnlen)11);
	errch_(__global_state, "*", side, (ftnlen)1, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDENDPNTSPEC)", (ftnlen)24);
    }
    chkout_(__global_state, "WNEXTD", (ftnlen)6);
    return 0;
} /* wnextd_ */

