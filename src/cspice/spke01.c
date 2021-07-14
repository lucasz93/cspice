/* spke01.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static integer c__15 = 15;
static integer c__45 = 45;

/* $Procedure      SPKE01 ( S/P Kernel, evaluate, type 1 ) */
/* Subroutine */ int spke01_(doublereal *et, doublereal *record, doublereal *
	state)
{
    /* Initialized data */

    static thread_local doublereal fc[14] = { 1. };

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6;

    /* Builtin functions */
    integer s_rnge(char *, integer, char *, integer);

    /* Local variables */
    static thread_local doublereal g[15];
    static thread_local integer i__, j;
    static thread_local doublereal w[17], delta;
    extern /* Subroutine */ int moved_(doublereal *, integer *, doublereal *);
    static thread_local integer kqmax1;
    static thread_local doublereal dt[45]	/* was [15][3] */, wc[13];
    static thread_local integer kq[3], ks;
    static thread_local doublereal tl;
    static thread_local integer jx;
    static thread_local doublereal tp, refvel[3], refpos[3];
    extern logical return_(void);
    static thread_local integer mq2, ks1, kqq;
    static thread_local doublereal sum;

/* $ Abstract */

/*     Evaluate a single SPK data record from a segment of type 1 */
/*     (Difference Lines). */

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

/*     EPHEMERIS */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Target epoch. */
/*     RECORD     I   Data record. */
/*     STATE      O   State (position and velocity). */

/* $ Detailed_Input */

/*     ET          is a target epoch, at which a state vector is to */
/*                 be computed. */

/*     RECORD      is a data record which, when evaluated at epoch ET, */
/*                 will give the state (position and velocity) of some */
/*                 body, relative to some center, in some inertial */
/*                 reference frame. */

/* $ Detailed_Output */

/*     STATE       is the state. Units are km and km/sec. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     None. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     The exact format and structure of type 1 (difference lines) */
/*     segments are described in the SPK Required Reading file. */

/*     Difference lines (DL's) are generated by JPL navigation */
/*     system programs P and PV. Each data record is equivalent */
/*     to the (slightly rearranged) 'P' portion of a NAVIO PV file */
/*     data record. */

/*     SPKE01 is a specialized version of Fred Krogh's subroutine DAINT. */
/*     Only the calling sequence has been changed. */

/*     Because the original version was undocumented, only Fred */
/*     knows how this really works. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     Unknown. */

/* $ Literature_References */

/*     NAIF Document 168.0, "S- and P- Kernel (SPK) Specification and */
/*     User's Guide" */

/* $ Author_and_Institution */

/*     F.T. Krogh      (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 14-FEB-1997 (WLT) */

/*        The goto's were removed and loop and if structures */
/*        revealed.  We still don't know exactly what's going */
/*        on, but at least the bones of this routine have been */
/*        cleaned off and are ready for assembly. (WLT) */

/* -    SPICELIB Version 1.0.4, 30-OCT-1996 (WLT) */

/*        Removed redundant SAVE statements from the declaration */
/*        section.  Thanks to Steve Schlaifer for finding this */
/*        error. */

/* -    SPICELIB Version 1.0.3, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.2, 23-AUG-1991 (HAN) */

/*        SPK01 was removed from the Required_Reading section of the */
/*        header. The information in the SPK01 Required Reading file */
/*        is now part of the SPK Required Reading file. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) (FTK) */

/* -& */
/* $ Index_Entries */

/*     evaluate type_1 spk segment */

/* -& */

/*     SPICELIB functions */


/*     Local variables */

/*     The names below are original to the routine. They correspond */
/*     roughly to the original memos written by Fred Krogh to explain */
/*     how all this stuff really works. */


/*     Save everything between calls. */


/*     If the RETURN function is set, don't even bother with this. */

    if (return_()) {
	return 0;
    }

/*     Unpack the contents of the MDA array. */

/*        Name    Dimension  Description */
/*        ------  ---------  ------------------------------- */
/*        TL              1  Final epoch of record */
/*        G              15  Stepsize function vector */
/*        REFPOS          3  Reference position vector */
/*        REFVEL          3  Reference velocity vector */
/*        DT         15,NTE  Modified divided difference arrays */
/*        KQMAX1          1  Maximum integration order plus 1 */
/*        KQ            NTE  Integration order array */

/*     For our purposes, NTE is always 3. */

    moved_(record, &c__1, &tl);
    moved_(&record[1], &c__15, g);

/*     Collect the reference position and velocity. */

    refpos[0] = record[16];
    refvel[0] = record[17];
    refpos[1] = record[18];
    refvel[1] = record[19];
    refpos[2] = record[20];
    refvel[2] = record[21];
    moved_(&record[22], &c__45, dt);
    kqmax1 = (integer) record[67];
    kq[0] = (integer) record[68];
    kq[1] = (integer) record[69];
    kq[2] = (integer) record[70];

/*     Next we set up for the computation of the various differences */

    delta = *et - tl;
    tp = delta;
    mq2 = kqmax1 - 2;
    ks = kqmax1 - 1;

/*     This is clearly collecting some kind of coefficients. */
/*     The problem is that we have no idea what they are... */

/*     The G coefficients are supposed to be some kind of step size */
/*     vector. */

/*     TP starts out as the delta t between the request time */
/*     and the time for which we last had a state in the MDL file. */
/*     We then change it from DELTA  by the components of the stepsize */
/*     vector G. */

    i__1 = mq2;
    for (j = 1; j <= i__1; ++j) {
	fc[(i__2 = j) < 14 && 0 <= i__2 ? i__2 : s_rnge("fc", i__2, "spke01_",
		 (ftnlen)267)] = tp / g[(i__3 = j - 1) < 15 && 0 <= i__3 ? 
		i__3 : s_rnge("g", i__3, "spke01_", (ftnlen)267)];
	wc[(i__2 = j - 1) < 13 && 0 <= i__2 ? i__2 : s_rnge("wc", i__2, "spk"
		"e01_", (ftnlen)268)] = delta / g[(i__3 = j - 1) < 15 && 0 <= 
		i__3 ? i__3 : s_rnge("g", i__3, "spke01_", (ftnlen)268)];
	tp = delta + g[(i__2 = j - 1) < 15 && 0 <= i__2 ? i__2 : s_rnge("g", 
		i__2, "spke01_", (ftnlen)269)];
    }

/*     Collect KQMAX1 reciprocals. */

    i__1 = kqmax1;
    for (j = 1; j <= i__1; ++j) {
	w[(i__2 = j - 1) < 17 && 0 <= i__2 ? i__2 : s_rnge("w", i__2, "spke0"
		"1_", (ftnlen)276)] = 1. / (doublereal) j;
    }

/*     Compute the W(K) terms needed for the position interpolation */
/*     (Note,  it is assumed throughout this routine that KS, which */
/*     starts out as KQMAX1-1 (the ``maximum integration'') */
/*     is at least 2. */

    jx = 0;
    ks1 = ks - 1;
    while(ks >= 2) {
	++jx;
	i__1 = jx;
	for (j = 1; j <= i__1; ++j) {
	    w[(i__2 = j + ks - 1) < 17 && 0 <= i__2 ? i__2 : s_rnge("w", i__2,
		     "spke01_", (ftnlen)293)] = fc[(i__3 = j) < 14 && 0 <= 
		    i__3 ? i__3 : s_rnge("fc", i__3, "spke01_", (ftnlen)293)] 
		    * w[(i__4 = j + ks1 - 1) < 17 && 0 <= i__4 ? i__4 : 
		    s_rnge("w", i__4, "spke01_", (ftnlen)293)] - wc[(i__5 = j 
		    - 1) < 13 && 0 <= i__5 ? i__5 : s_rnge("wc", i__5, "spke"
		    "01_", (ftnlen)293)] * w[(i__6 = j + ks - 1) < 17 && 0 <= 
		    i__6 ? i__6 : s_rnge("w", i__6, "spke01_", (ftnlen)293)];
	}
	ks = ks1;
	--ks1;
    }

/*     Perform position interpolation: (Note that KS = 1 right now. */
/*     We don't know much more than that.) */

    for (i__ = 1; i__ <= 3; ++i__) {
	kqq = kq[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge("kq", i__1,
		 "spke01_", (ftnlen)307)];
	sum = 0.;
	for (j = kqq; j >= 1; --j) {
	    sum += dt[(i__1 = j + i__ * 15 - 16) < 45 && 0 <= i__1 ? i__1 : 
		    s_rnge("dt", i__1, "spke01_", (ftnlen)311)] * w[(i__2 = j 
		    + ks - 1) < 17 && 0 <= i__2 ? i__2 : s_rnge("w", i__2, 
		    "spke01_", (ftnlen)311)];
	}
	state[(i__1 = i__ - 1) < 6 && 0 <= i__1 ? i__1 : s_rnge("state", i__1,
		 "spke01_", (ftnlen)314)] = refpos[(i__2 = i__ - 1) < 3 && 0 
		<= i__2 ? i__2 : s_rnge("refpos", i__2, "spke01_", (ftnlen)
		314)] + delta * (refvel[(i__3 = i__ - 1) < 3 && 0 <= i__3 ? 
		i__3 : s_rnge("refvel", i__3, "spke01_", (ftnlen)314)] + 
		delta * sum);
    }

/*     Again we need to compute the W(K) coefficients that are */
/*     going to be used in the velocity interpolation. */
/*     (Note, at this point, KS = 1, KS1 = 0.) */

    i__1 = jx;
    for (j = 1; j <= i__1; ++j) {
	w[(i__2 = j + ks - 1) < 17 && 0 <= i__2 ? i__2 : s_rnge("w", i__2, 
		"spke01_", (ftnlen)324)] = fc[(i__3 = j) < 14 && 0 <= i__3 ? 
		i__3 : s_rnge("fc", i__3, "spke01_", (ftnlen)324)] * w[(i__4 =
		 j + ks1 - 1) < 17 && 0 <= i__4 ? i__4 : s_rnge("w", i__4, 
		"spke01_", (ftnlen)324)] - wc[(i__5 = j - 1) < 13 && 0 <= 
		i__5 ? i__5 : s_rnge("wc", i__5, "spke01_", (ftnlen)324)] * w[
		(i__6 = j + ks - 1) < 17 && 0 <= i__6 ? i__6 : s_rnge("w", 
		i__6, "spke01_", (ftnlen)324)];
    }
    --ks;

/*     Perform velocity interpolation: */

    for (i__ = 1; i__ <= 3; ++i__) {
	kqq = kq[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge("kq", i__1,
		 "spke01_", (ftnlen)334)];
	sum = 0.;
	for (j = kqq; j >= 1; --j) {
	    sum += dt[(i__1 = j + i__ * 15 - 16) < 45 && 0 <= i__1 ? i__1 : 
		    s_rnge("dt", i__1, "spke01_", (ftnlen)338)] * w[(i__2 = j 
		    + ks - 1) < 17 && 0 <= i__2 ? i__2 : s_rnge("w", i__2, 
		    "spke01_", (ftnlen)338)];
	}
	state[(i__1 = i__ + 2) < 6 && 0 <= i__1 ? i__1 : s_rnge("state", i__1,
		 "spke01_", (ftnlen)341)] = refvel[(i__2 = i__ - 1) < 3 && 0 
		<= i__2 ? i__2 : s_rnge("refvel", i__2, "spke01_", (ftnlen)
		341)] + delta * sum;
    }

/*     That's all folks.  We don't know why we did anything, but */
/*     at least we can tell structurally what we did. */

    return 0;
} /* spke01_ */

