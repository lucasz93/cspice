/* wnintd.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int wnintd_state_t;
static inline wnintd_state_t* get_wnintd_state(cspice_t* state) {
	return 0;
}

/* $Procedure      WNINTD ( Intersect two DP windows ) */
/* Subroutine */ int wnintd_(cspice_t* __global_state, doublereal *a, 
	doublereal *b, doublereal *c__)
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Local variables */
    integer over;
    integer acard;
    integer bcard;
    extern integer cardd_(cspice_t*, doublereal *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer csize;
    extern integer sized_(cspice_t*, doublereal *);
    integer ap;
    integer bp;
    integer cp;
    extern /* Subroutine */ int scardd_(cspice_t*, integer *, doublereal *);
    extern /* Subroutine */ int excess_(cspice_t*, integer *, char *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);
    char use[1];


    /* Module state */
    wnintd_state_t* __state = get_wnintd_state(__global_state);
/* $ Abstract */

/*      Place the intersection of two double precision windows into */
/*      a third window. */

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

/*      WINDOWS */

/* $ Declarations */
/* $ Brief_I/O */

/*      VARIABLE  I/O  DESCRIPTION */
/*      --------  ---  -------------------------------------------------- */
/*      A, */
/*      B          I   Input windows. */
/*      C          I   Intersection of A and B. */

/* $ Detailed_Input */

/*      A, */
/*      B           are windows, each of which contains zero or more */
/*                  intervals. */

/* $ Detailed_Output */

/*      C           is the output window, containing the intersection */
/*                  of A and B---every point contained in both A and B. */

/*                  C must be distinct from both A and B. */

/* $ Parameters */

/*     None. */

/* $ Particulars */

/*      The intersection of two windows contains every point contained */
/*      both in the first window and in the second window. */

/* $ Examples */

/*      Let A contain the intervals */

/*            [ 1, 3 ]  [ 7, 11 ]  [ 23, 27 ] */

/*      and B contain the intervals */

/*            [ 2, 4 ]  [ 8, 10 ]  [ 16, 18 ] */

/*      Then the intersection of A and B contains the intervals */

/*            [ 2, 3 ]  [ 8, 10 ] */

/* $ Exceptions */

/*     1. If the intersection of the two windows results in an excess of */
/*        elements, the error SPICE(WINDOWEXCESS) is signalled. */

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

/*     intersect two d.p. windows */

/* -& */
/* $ Revisions */

/* -     Beta Version 1.1.0, 27-FEB-1989  (HAN) */

/*         Due to the calling sequence and functionality changes */
/*         in the routine EXCESS, the method of signalling an */
/*         excess of elements needed to be changed. */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "WNINTD", (ftnlen)6);
    }

/*     Find the cardinality of the input windows, and the allowed size */
/*     of the output window. */

    acard = cardd_(__global_state, a);
    bcard = cardd_(__global_state, b);
    csize = sized_(__global_state, c__);

/*     Begin with the input pointers at the first elements of the */
/*     input windows. The initial cardinality of the output window */
/*     is zero. And there is no overflow so far. */

/*     (Note that AP and BP point to the LEFT endpoints of intervals */
/*     in A and B, while CP points to the RIGHT endpoint of the latest */
/*     interval in C.) */

    ap = 1;
    bp = 1;
    cp = 0;
    over = 0;

/*     When the end of either input window is reached, we're done. */

    while(ap < acard && bp < bcard) {

/*        Let's see what we can do with the earlier of the next */
/*        intervals from A and B. */

	if (a[ap + 6] < b[bp + 6]) {
	    *(unsigned char *)use = 'A';
	} else if (b[bp + 6] <= a[ap + 6]) {
	    *(unsigned char *)use = 'B';
	}

/*        If there is still space in the output window, fill it */
/*        as necessary. Otherwise, stop filling the array, but continue */
/*        to count the number of elements in excess of the size of the */
/*        output window. */

/*        The general idea is this: if the next interval of A overlaps */
/*        the next interval of B, save the area of overlap. (Similarly */
/*        for B.) */

	if (*(unsigned char *)use == 'A') {
	    if (a[ap + 6] >= b[bp + 5]) {
		if (cp < csize) {
		    cp += 2;
/* Computing MAX */
		    d__1 = b[bp + 5], d__2 = a[ap + 5];
		    c__[cp + 4] = max(d__1,d__2);
		    c__[cp + 5] = a[ap + 6];
		} else {
		    over += 2;
		}
	    }
	    ap += 2;

/*        This is the same as the last clause, with B replacing A. */

	} else if (*(unsigned char *)use == 'B') {
	    if (b[bp + 6] >= a[ap + 5]) {
		if (cp < csize) {
		    cp += 2;
/* Computing MAX */
		    d__1 = a[ap + 5], d__2 = b[bp + 5];
		    c__[cp + 4] = max(d__1,d__2);
		    c__[cp + 5] = b[bp + 6];
		} else {
		    over += 2;
		}
	    }
	    bp += 2;
	}
    }

/*     Set the cardinality of the output window. */

    scardd_(__global_state, &cp, c__);

/*     If there are any excess elements, signal an error and check out */
/*     as usual. */

    if (over > 0) {
	excess_(__global_state, &over, "window", (ftnlen)6);
	sigerr_(__global_state, "SPICE(WINDOWEXCESS)", (ftnlen)19);
    }
    chkout_(__global_state, "WNINTD", (ftnlen)6);
    return 0;
} /* wnintd_ */

