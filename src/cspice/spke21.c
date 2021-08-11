/* spke21.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern spke21_init_t __spke21_init;
static spke21_state_t* get_spke21_state() {
	cspice_t* state =  __cspice_get_state();
	if (!state->spke21)
		state->spke21 = __cspice_allocate_module(sizeof(
	spke21_state_t), &__spke21_init, sizeof(__spke21_init));
	return state->spke21;

}

/* $Procedure      SPKE21 ( S/P Kernel, evaluate, type 21 ) */
/* Subroutine */ int spke21_(doublereal *et, doublereal *record, doublereal *
	state)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6;

    /* Builtin functions */
    integer i_dnnt(doublereal *), s_rnge(char *, integer, char *, integer);

    /* Local variables */
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    extern /* Subroutine */ int moved_(doublereal *, integer *, doublereal *);
    extern /* Subroutine */ int sigerr_(char *, ftnlen);
    extern /* Subroutine */ int chkout_(char *, ftnlen);
    extern /* Subroutine */ int setmsg_(char *, ftnlen);
    extern /* Subroutine */ int errint_(char *, integer *, ftnlen);
    extern logical return_(void);

    /* Module state */
    spke21_state_t* __state = get_spke21_state();
/* $ Abstract */

/*     Evaluate a single SPK data record from a segment of type 21 */
/*     (Extended Difference Lines). */

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

/*     SPK */
/*     TIME */

/* $ Keywords */

/*     EPHEMERIS */

/* $ Declarations */
/* $ Abstract */

/*     Declare parameters specific to SPK type 21. */

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

/*     SPK */

/* $ Keywords */

/*     SPK */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 25-DEC-2013 (NJB) */

/* -& */

/*     MAXTRM      is the maximum number of terms allowed in each */
/*                 component of the difference table contained in a type */
/*                 21 SPK difference line. MAXTRM replaces the fixed */
/*                 table parameter value of 15 used in SPK type 1 */
/*                 segments. */

/*                 Type 21 segments have variable size. Let MAXDIM be */
/*                 the dimension of each component of the difference */
/*                 table within each difference line. Then the size */
/*                 DLSIZE of the difference line is */

/*                    ( 4 * MAXDIM ) + 11 */

/*                 MAXTRM is the largest allowed value of MAXDIM. */



/*     End of include file spk21.inc. */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Evaluation epoch. */
/*     RECORD     I   Data record. */
/*     STATE      O   State (position and velocity). */
/*     MAXTRM     P   Maximum number of terms per difference table */
/*                    component. */

/* $ Detailed_Input */

/*     ET          is an epoch at which a state vector is to be */
/*                 computed. The epoch is represented as seconds past */
/*                 J2000 TDB. */

/*     RECORD      is a data record which, when evaluated at epoch ET, */
/*                 will give the state (position and velocity) of an */
/*                 ephemeris object, relative to its center of motion, */
/*                 in an inertial reference frame. */

/*                 The contents of RECORD are as follows: */

/*                    RECORD(1):         The difference table size per */
/*                                       Cartesian component. Call this */
/*                                       size MAXDIM; then the difference */
/*                                       line (MDA) size DLSIZE is */

/*                                         ( 4 * MAXDIM ) + 11 */

/*                    RECORD(2) */
/*                       ... */
/*                    RECORD(1+DLSIZE):  An extended difference line. */
/*                                       The contents are: */

/*                       Dimension  Description */
/*                       ---------  ---------------------------------- */
/*                       1          Reference epoch of difference line */
/*                       MAXDIM     Stepsize function vector */
/*                       1          Reference position vector,  x */
/*                       1          Reference velocity vector,  x */
/*                       1          Reference position vector,  y */
/*                       1          Reference velocity vector,  y */
/*                       1          Reference position vector,  z */
/*                       1          Reference velocity vector,  z */
/*                       MAXDIM,3   Modified divided difference */
/*                                  arrays (MDAs) */
/*                       1          Maximum integration order plus 1 */
/*                       3          Integration order array */

/* $ Detailed_Output */

/*     STATE       is the state resulting from evaluation of the input */
/*                 record at ET. Units are km and km/sec. */

/* $ Parameters */

/*     MAXTRM      is the maximum number of terms allowed in */
/*                 each component of the difference table */
/*                 contained in the input argument RECORD. */
/*                 See the INCLUDE file spk21.inc for the value */
/*                 of MAXTRM. */

/* $ Exceptions */

/*     1) If the maximum table size of the input record exceeds */
/*        MAXTRM, the error SPICE(DIFFLINETOOLARGE) is signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     The exact format and structure of type 21 (difference lines) */
/*     segments are described in the SPK Required Reading file. */

/*     SPKE21 is a modified version of SPKE01. The routine has been */
/*     generalized to support variable size difference lines. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     Unknown. */

/* $ Literature_References */

/*     NAIF Document 168.0, "S- and P- Kernel (SPK) Specification and */
/*     User's Guide" */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     F.T. Krogh      (JPL) */
/*     W.L. Taber      (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 03-FEB-2014 (NJB) (FTK) (WLT) (IMU) */

/* -& */
/* $ Index_Entries */

/*     evaluate type_21 spk segment */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */

/*     The names below are original to the routine. They correspond */
/*     roughly to the original memos written by Fred Krogh to explain */
/*     how all this stuff really works. */


/*     Save everything between calls. */


/*     Initial values */


/*     Use discovery check-in. */

/*     If the RETURN function is set, don't even bother with this. */

    if (return_()) {
	return 0;
    }

/*     The first element of the input record is the dimension */
/*     of the difference table MAXDIM. */

    __state->maxdim = i_dnnt(record);
    if (__state->maxdim > 25) {
	chkin_("SPKE21", (ftnlen)6);
	setmsg_("The input record has a maximum table dimension of #, while "
		"the maximum supported by this routine is #. It is possible t"
		"hat this problem is due to your SPICE Toolkit being out of d"
		"ate.", (ftnlen)183);
	errint_("#", &__state->maxdim, (ftnlen)1);
	errint_("#", &__state->c__25, (ftnlen)1);
	sigerr_("SPICE(DIFFLINETOOLARGE)", (ftnlen)23);
	chkout_("SPKE21", (ftnlen)6);
	return 0;
    }

/*     Unpack the contents of the MDA array. */

/*        Name     Dimension  Description */
/*        ------   ---------  ------------------------------- */
/*        TL               1  Reference epoch of record */
/*        G           MAXDIM  Stepsize function vector */
/*        REFPOS           3  Reference position vector */
/*        REFVEL           3  Reference velocity vector */
/*        DT      MAXDIM,NTE  Modified divided difference arrays */
/*        KQMAX1           1  Maximum integration order plus 1 */
/*        KQ             NTE  Integration order array */

/*     For our purposes, NTE is always 3. */

    moved_(&record[1], &__state->c__1, &__state->tl);
    moved_(&record[2], &__state->maxdim, __state->g);

/*     Collect the reference position and velocity. */

    __state->refpos[0] = record[__state->maxdim + 2];
    __state->refvel[0] = record[__state->maxdim + 3];
    __state->refpos[1] = record[__state->maxdim + 4];
    __state->refvel[1] = record[__state->maxdim + 5];
    __state->refpos[2] = record[__state->maxdim + 6];
    __state->refvel[2] = record[__state->maxdim + 7];

/*     Initializing the difference table is one aspect of this routine */
/*     that's a bit different from SPKE01. Here the first dimension of */
/*     the table in the input record can be smaller than MAXTRM. So, we */
/*     must transfer separately the portions of the table corresponding */
/*     to each component. */

    for (__state->i__ = 1; __state->i__ <= 3; ++__state->i__) {
	moved_(&record[__state->i__ * __state->maxdim + 8], &__state->maxdim, 
		&__state->dt[(i__1 = __state->i__ * 25 - 25) < 75 && 0 <= 
		i__1 ? i__1 : s_rnge("dt", i__1, "spke21_", (ftnlen)289)]);
    }
    __state->kqmax1 = (integer) record[(__state->maxdim << 2) + 8];
    __state->kq[0] = (integer) record[(__state->maxdim << 2) + 9];
    __state->kq[1] = (integer) record[(__state->maxdim << 2) + 10];
    __state->kq[2] = (integer) record[(__state->maxdim << 2) + 11];

/*     Next we set up for the computation of the various differences */

    __state->delta = *et - __state->tl;
    __state->tp = __state->delta;
    __state->mq2 = __state->kqmax1 - 2;
    __state->ks = __state->kqmax1 - 1;

/*     This is clearly collecting some kind of coefficients. */
/*     The problem is that we have no idea what they are... */

/*     The G coefficients are supposed to be some kind of step size */
/*     vector. */

/*     TP starts out as the delta t between the request time and the */
/*     difference line's reference epoch. We then change it from DELTA */
/*     by the components of the stepsize vector G. */

    i__1 = __state->mq2;
    for (__state->j = 1; __state->j <= i__1; ++__state->j) {

/*        Make sure we're not about to attempt division by zero. */

	if (__state->g[(i__2 = __state->j - 1) < 25 && 0 <= i__2 ? i__2 : 
		s_rnge("g", i__2, "spke21_", (ftnlen)320)] == 0.) {
	    chkin_("SPKE21", (ftnlen)6);
	    setmsg_("A  value of zero was found at index # of the step size "
		    "vector.", (ftnlen)62);
	    errint_("#", &__state->j, (ftnlen)1);
	    sigerr_("SPICE(ZEROSTEP)", (ftnlen)15);
	    chkout_("SPKE21", (ftnlen)6);
	    return 0;
	}
	__state->fc[(i__2 = __state->j) < 25 && 0 <= i__2 ? i__2 : s_rnge(
		"fc", i__2, "spke21_", (ftnlen)332)] = __state->tp / 
		__state->g[(i__3 = __state->j - 1) < 25 && 0 <= i__3 ? i__3 : 
		s_rnge("g", i__3, "spke21_", (ftnlen)332)];
	__state->wc[(i__2 = __state->j - 1) < 24 && 0 <= i__2 ? i__2 : s_rnge(
		"wc", i__2, "spke21_", (ftnlen)333)] = __state->delta / 
		__state->g[(i__3 = __state->j - 1) < 25 && 0 <= i__3 ? i__3 : 
		s_rnge("g", i__3, "spke21_", (ftnlen)333)];
	__state->tp = __state->delta + __state->g[(i__2 = __state->j - 1) < 
		25 && 0 <= i__2 ? i__2 : s_rnge("g", i__2, "spke21_", (ftnlen)
		334)];
    }

/*     Collect KQMAX1 reciprocals. */

    i__1 = __state->kqmax1;
    for (__state->j = 1; __state->j <= i__1; ++__state->j) {
	__state->w[(i__2 = __state->j - 1) < 27 && 0 <= i__2 ? i__2 : s_rnge(
		"w", i__2, "spke21_", (ftnlen)342)] = 1. / (doublereal) 
		__state->j;
    }

/*     Compute the W(K) terms needed for the position interpolation */
/*     (Note,  it is assumed throughout this routine that KS, which */
/*     starts out as KQMAX1-1 (the ``maximum integration'') */
/*     is at least 2. */

    __state->jx = 0;
    __state->ks1 = __state->ks - 1;
    while(__state->ks >= 2) {
	++__state->jx;
	i__1 = __state->jx;
	for (__state->j = 1; __state->j <= i__1; ++__state->j) {
	    __state->w[(i__2 = __state->j + __state->ks - 1) < 27 && 0 <= 
		    i__2 ? i__2 : s_rnge("w", i__2, "spke21_", (ftnlen)359)] =
		     __state->fc[(i__3 = __state->j) < 25 && 0 <= i__3 ? i__3 
		    : s_rnge("fc", i__3, "spke21_", (ftnlen)359)] * 
		    __state->w[(i__4 = __state->j + __state->ks1 - 1) < 27 && 
		    0 <= i__4 ? i__4 : s_rnge("w", i__4, "spke21_", (ftnlen)
		    359)] - __state->wc[(i__5 = __state->j - 1) < 24 && 0 <= 
		    i__5 ? i__5 : s_rnge("wc", i__5, "spke21_", (ftnlen)359)] 
		    * __state->w[(i__6 = __state->j + __state->ks - 1) < 27 &&
		     0 <= i__6 ? i__6 : s_rnge("w", i__6, "spke21_", (ftnlen)
		    359)];
	}
	__state->ks = __state->ks1;
	--__state->ks1;
    }

/*     Perform position interpolation: (Note that KS = 1 right now. */
/*     We don't know much more than that.) */

    for (__state->i__ = 1; __state->i__ <= 3; ++__state->i__) {
	__state->kqq = __state->kq[(i__1 = __state->i__ - 1) < 3 && 0 <= i__1 
		? i__1 : s_rnge("kq", i__1, "spke21_", (ftnlen)373)];
	__state->sum = 0.;
	for (__state->j = __state->kqq; __state->j >= 1; --__state->j) {
	    __state->sum += __state->dt[(i__1 = __state->j + __state->i__ * 
		    25 - 26) < 75 && 0 <= i__1 ? i__1 : s_rnge("dt", i__1, 
		    "spke21_", (ftnlen)377)] * __state->w[(i__2 = __state->j 
		    + __state->ks - 1) < 27 && 0 <= i__2 ? i__2 : s_rnge(
		    "w", i__2, "spke21_", (ftnlen)377)];
	}
	state[(i__1 = __state->i__ - 1) < 6 && 0 <= i__1 ? i__1 : s_rnge(
		"state", i__1, "spke21_", (ftnlen)380)] = __state->refpos[(
		i__2 = __state->i__ - 1) < 3 && 0 <= i__2 ? i__2 : s_rnge(
		"refpos", i__2, "spke21_", (ftnlen)380)] + __state->delta * (
		__state->refvel[(i__3 = __state->i__ - 1) < 3 && 0 <= i__3 ? 
		i__3 : s_rnge("refvel", i__3, "spke21_", (ftnlen)380)] + 
		__state->delta * __state->sum);
    }

/*     Again we need to compute the W(K) coefficients that are */
/*     going to be used in the velocity interpolation. */
/*     (Note, at this point, KS = 1, KS1 = 0.) */

    i__1 = __state->jx;
    for (__state->j = 1; __state->j <= i__1; ++__state->j) {
	__state->w[(i__2 = __state->j + __state->ks - 1) < 27 && 0 <= i__2 ? 
		i__2 : s_rnge("w", i__2, "spke21_", (ftnlen)390)] = 
		__state->fc[(i__3 = __state->j) < 25 && 0 <= i__3 ? i__3 : 
		s_rnge("fc", i__3, "spke21_", (ftnlen)390)] * __state->w[(
		i__4 = __state->j + __state->ks1 - 1) < 27 && 0 <= i__4 ? 
		i__4 : s_rnge("w", i__4, "spke21_", (ftnlen)390)] - 
		__state->wc[(i__5 = __state->j - 1) < 24 && 0 <= i__5 ? i__5 :
		 s_rnge("wc", i__5, "spke21_", (ftnlen)390)] * __state->w[(
		i__6 = __state->j + __state->ks - 1) < 27 && 0 <= i__6 ? i__6 
		: s_rnge("w", i__6, "spke21_", (ftnlen)390)];
    }
    --__state->ks;

/*     Perform velocity interpolation: */

    for (__state->i__ = 1; __state->i__ <= 3; ++__state->i__) {
	__state->kqq = __state->kq[(i__1 = __state->i__ - 1) < 3 && 0 <= i__1 
		? i__1 : s_rnge("kq", i__1, "spke21_", (ftnlen)400)];
	__state->sum = 0.;
	for (__state->j = __state->kqq; __state->j >= 1; --__state->j) {
	    __state->sum += __state->dt[(i__1 = __state->j + __state->i__ * 
		    25 - 26) < 75 && 0 <= i__1 ? i__1 : s_rnge("dt", i__1, 
		    "spke21_", (ftnlen)404)] * __state->w[(i__2 = __state->j 
		    + __state->ks - 1) < 27 && 0 <= i__2 ? i__2 : s_rnge(
		    "w", i__2, "spke21_", (ftnlen)404)];
	}
	state[(i__1 = __state->i__ + 2) < 6 && 0 <= i__1 ? i__1 : s_rnge(
		"state", i__1, "spke21_", (ftnlen)407)] = __state->refvel[(
		i__2 = __state->i__ - 1) < 3 && 0 <= i__2 ? i__2 : s_rnge(
		"refvel", i__2, "spke21_", (ftnlen)407)] + __state->delta * 
		__state->sum;
    }
    return 0;
} /* spke21_ */

