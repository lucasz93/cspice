/* spke01.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern spke01_init_t __spke01_init;
static spke01_state_t* get_spke01_state(cspice_t* state) {
	if (!state->spke01)
		state->spke01 = __cspice_allocate_module(sizeof(
	spke01_state_t), &__spke01_init, sizeof(__spke01_init));
	return state->spke01;

}

/* $Procedure      SPKE01 ( S/P Kernel, evaluate, type 1 ) */
/* Subroutine */ int spke01_(cspice_t* __global_state, doublereal *et, 
	doublereal *record, doublereal *state)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6;

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);

    /* Local variables */
    extern /* Subroutine */ int moved_(cspice_t*, doublereal *, integer *, 
	    doublereal *);
    extern logical return_(cspice_t*);

    /* Module state */
    spke01_state_t* __state = get_spke01_state(__global_state);
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

    if (return_(__global_state)) {
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

    moved_(__global_state, record, &__state->c__1, &__state->tl);
    moved_(__global_state, &record[1], &__state->c__15, __state->g);

/*     Collect the reference position and velocity. */

    __state->refpos[0] = record[16];
    __state->refvel[0] = record[17];
    __state->refpos[1] = record[18];
    __state->refvel[1] = record[19];
    __state->refpos[2] = record[20];
    __state->refvel[2] = record[21];
    moved_(__global_state, &record[22], &__state->c__45, __state->dt);
    __state->kqmax1 = (integer) record[67];
    __state->kq[0] = (integer) record[68];
    __state->kq[1] = (integer) record[69];
    __state->kq[2] = (integer) record[70];

/*     Next we set up for the computation of the various differences */

    __state->delta = *et - __state->tl;
    __state->tp = __state->delta;
    __state->mq2 = __state->kqmax1 - 2;
    __state->ks = __state->kqmax1 - 1;

/*     This is clearly collecting some kind of coefficients. */
/*     The problem is that we have no idea what they are... */

/*     The G coefficients are supposed to be some kind of step size */
/*     vector. */

/*     TP starts out as the delta t between the request time */
/*     and the time for which we last had a state in the MDL file. */
/*     We then change it from DELTA  by the components of the stepsize */
/*     vector G. */

    i__1 = __state->mq2;
    for (__state->j = 1; __state->j <= i__1; ++__state->j) {
	__state->fc[(i__2 = __state->j) < 14 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "fc", i__2, "spke01_", (ftnlen)267)] = 
		__state->tp / __state->g[(i__3 = __state->j - 1) < 15 && 0 <= 
		i__3 ? i__3 : s_rnge(&__global_state->f2c, "g", i__3, "spke0"
		"1_", (ftnlen)267)];
	__state->wc[(i__2 = __state->j - 1) < 13 && 0 <= i__2 ? i__2 : s_rnge(
		&__global_state->f2c, "wc", i__2, "spke01_", (ftnlen)268)] = 
		__state->delta / __state->g[(i__3 = __state->j - 1) < 15 && 0 
		<= i__3 ? i__3 : s_rnge(&__global_state->f2c, "g", i__3, 
		"spke01_", (ftnlen)268)];
	__state->tp = __state->delta + __state->g[(i__2 = __state->j - 1) < 
		15 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "g", 
		i__2, "spke01_", (ftnlen)269)];
    }

/*     Collect KQMAX1 reciprocals. */

    i__1 = __state->kqmax1;
    for (__state->j = 1; __state->j <= i__1; ++__state->j) {
	__state->w[(i__2 = __state->j - 1) < 17 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "w", i__2, "spke01_", (ftnlen)276)] = 1. 
		/ (doublereal) __state->j;
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
	    __state->w[(i__2 = __state->j + __state->ks - 1) < 17 && 0 <= 
		    i__2 ? i__2 : s_rnge(&__global_state->f2c, "w", i__2, 
		    "spke01_", (ftnlen)293)] = __state->fc[(i__3 = __state->j)
		     < 14 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "fc", i__3, "spke01_", (ftnlen)293)] * __state->w[(i__4 = 
		    __state->j + __state->ks1 - 1) < 17 && 0 <= i__4 ? i__4 : 
		    s_rnge(&__global_state->f2c, "w", i__4, "spke01_", (
		    ftnlen)293)] - __state->wc[(i__5 = __state->j - 1) < 13 &&
		     0 <= i__5 ? i__5 : s_rnge(&__global_state->f2c, "wc", 
		    i__5, "spke01_", (ftnlen)293)] * __state->w[(i__6 = 
		    __state->j + __state->ks - 1) < 17 && 0 <= i__6 ? i__6 : 
		    s_rnge(&__global_state->f2c, "w", i__6, "spke01_", (
		    ftnlen)293)];
	}
	__state->ks = __state->ks1;
	--__state->ks1;
    }

/*     Perform position interpolation: (Note that KS = 1 right now. */
/*     We don't know much more than that.) */

    for (__state->i__ = 1; __state->i__ <= 3; ++__state->i__) {
	__state->kqq = __state->kq[(i__1 = __state->i__ - 1) < 3 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "kq", i__1, "spke01_", (
		ftnlen)307)];
	__state->sum = 0.;
	for (__state->j = __state->kqq; __state->j >= 1; --__state->j) {
	    __state->sum += __state->dt[(i__1 = __state->j + __state->i__ * 
		    15 - 16) < 45 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "dt", i__1, "spke01_", (ftnlen)311)] 
		    * __state->w[(i__2 = __state->j + __state->ks - 1) < 17 &&
		     0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "w", 
		    i__2, "spke01_", (ftnlen)311)];
	}
	state[(i__1 = __state->i__ - 1) < 6 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "state", i__1, "spke01_", (ftnlen)314)] =
		 __state->refpos[(i__2 = __state->i__ - 1) < 3 && 0 <= i__2 ? 
		i__2 : s_rnge(&__global_state->f2c, "refpos", i__2, "spke01_",
		 (ftnlen)314)] + __state->delta * (__state->refvel[(i__3 = 
		__state->i__ - 1) < 3 && 0 <= i__3 ? i__3 : s_rnge(&
		__global_state->f2c, "refvel", i__3, "spke01_", (ftnlen)314)] 
		+ __state->delta * __state->sum);
    }

/*     Again we need to compute the W(K) coefficients that are */
/*     going to be used in the velocity interpolation. */
/*     (Note, at this point, KS = 1, KS1 = 0.) */

    i__1 = __state->jx;
    for (__state->j = 1; __state->j <= i__1; ++__state->j) {
	__state->w[(i__2 = __state->j + __state->ks - 1) < 17 && 0 <= i__2 ? 
		i__2 : s_rnge(&__global_state->f2c, "w", i__2, "spke01_", (
		ftnlen)324)] = __state->fc[(i__3 = __state->j) < 14 && 0 <= 
		i__3 ? i__3 : s_rnge(&__global_state->f2c, "fc", i__3, "spke"
		"01_", (ftnlen)324)] * __state->w[(i__4 = __state->j + 
		__state->ks1 - 1) < 17 && 0 <= i__4 ? i__4 : s_rnge(&
		__global_state->f2c, "w", i__4, "spke01_", (ftnlen)324)] - 
		__state->wc[(i__5 = __state->j - 1) < 13 && 0 <= i__5 ? i__5 :
		 s_rnge(&__global_state->f2c, "wc", i__5, "spke01_", (ftnlen)
		324)] * __state->w[(i__6 = __state->j + __state->ks - 1) < 17 
		&& 0 <= i__6 ? i__6 : s_rnge(&__global_state->f2c, "w", i__6, 
		"spke01_", (ftnlen)324)];
    }
    --__state->ks;

/*     Perform velocity interpolation: */

    for (__state->i__ = 1; __state->i__ <= 3; ++__state->i__) {
	__state->kqq = __state->kq[(i__1 = __state->i__ - 1) < 3 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "kq", i__1, "spke01_", (
		ftnlen)334)];
	__state->sum = 0.;
	for (__state->j = __state->kqq; __state->j >= 1; --__state->j) {
	    __state->sum += __state->dt[(i__1 = __state->j + __state->i__ * 
		    15 - 16) < 45 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "dt", i__1, "spke01_", (ftnlen)338)] 
		    * __state->w[(i__2 = __state->j + __state->ks - 1) < 17 &&
		     0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "w", 
		    i__2, "spke01_", (ftnlen)338)];
	}
	state[(i__1 = __state->i__ + 2) < 6 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "state", i__1, "spke01_", (ftnlen)341)] =
		 __state->refvel[(i__2 = __state->i__ - 1) < 3 && 0 <= i__2 ? 
		i__2 : s_rnge(&__global_state->f2c, "refvel", i__2, "spke01_",
		 (ftnlen)341)] + __state->delta * __state->sum;
    }

/*     That's all folks.  We don't know why we did anything, but */
/*     at least we can tell structurally what we did. */

    return 0;
} /* spke01_ */

