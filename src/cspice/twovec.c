/* twovec.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern twovec_init_t __twovec_init;
static twovec_state_t* get_twovec_state(cspice_t* state) {
	if (!state->twovec)
		state->twovec = __cspice_allocate_module(sizeof(
	twovec_state_t), &__twovec_init, sizeof(__twovec_init));
	return state->twovec;

}

/* $Procedure      TWOVEC ( Two vectors defining an orthonormal frame ) */
/* Subroutine */ int twovec_(cspice_t* __global_state, doublereal *axdef, 
	integer *indexa, doublereal *plndef, integer *indexp, doublereal *
	mout)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);

    /* Local variables */
    extern /* Subroutine */ int vhat_(cspice_t*, doublereal *, doublereal *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int moved_(cspice_t*, doublereal *, integer *, 
	    doublereal *);
    doublereal mtemp[9]	/* was [3][3] */;
    integer i1;
    integer i2;
    integer i3;
    extern /* Subroutine */ int xpose_(cspice_t*, doublereal *, doublereal *);
    extern /* Subroutine */ int ucrss_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    twovec_state_t* __state = get_twovec_state(__global_state);
/* $ Abstract */

/*     Find the transformation to the right-handed frame having a */
/*     given vector as a specified axis and having a second given */
/*     vector lying in a specified coordinate plane. */

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

/*     AXES,  FRAME,  ROTATION,  TRANSFORMATION */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  ------------------------------------------------- */
/*     AXDEF      I   Vector defining a principal axis. */
/*     INDEXA     I   Principal axis number of AXDEF (X=1, Y=2, Z=3). */
/*     PLNDEF     I   Vector defining (with AXDEF) a principal plane. */
/*     INDEXP     I   Second axis number (with INDEXA) of principal */
/*                     plane. */
/*     MOUT       O   Output rotation matrix. */

/* $ Detailed_Input */

/*     AXDEF      is a vector defining one of the priciple axes of a */
/*                coordinate frame. */

/*     INDEXA     is a number that determines which of the three */
/*                coordinate axes contains AXDEF. */

/*                If INDEXA is 1 then AXDEF defines the X axis of the */
/*                coordinate frame. */

/*                If INDEXA is 2 then AXDEF defines the Y axis of the */
/*                coordinate frame. */

/*                If INDEXA is 3 then AXDEF defines the Z axis of the */
/*                coordinate frame */

/*     PLNDEF     is a vector defining (with AXDEF) a principal plane of */
/*                the coordinate frame. AXDEF and PLNDEF must be */
/*                linearly independent. */

/*     INDEXP     is the second axis of the principal frame determined */
/*                by AXDEF and PLNDEF.  INDEXA, INDEXP must be different */
/*                and be integers from 1 to 3. */

/*                If INDEXP is 1, the second axis of the principal */
/*                plane is the X-axis. */

/*                If INDEXP is 2, the second axis of the principal */
/*                plane is the Y-axis. */

/*                If INDEXP is 3, the second axis of the principal plane */
/*                is the Z-axis. */


/* $ Detailed_Output */

/*     MOUT       is a rotation matrix that transforms coordinates given */
/*                in the input frame to the frame determined by AXDEF, */
/*                PLNDEF, INDEXA and INDEXP. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If INDEXA or INDEXP is not in the set {1,2,3} the error */
/*        SPICE(BADINDEX) will be signaled. */

/*     2) If INDEXA and INDEXP are the same the error */
/*        SPICE(UNDEFINEDFRAME) will be signaled. */

/*     3) If the cross product of the vectors AXDEF and PLNDEF is zero, */
/*        the error SPICE(DEPENDENTVECTORS) will be signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     Given two linearly independent vectors there is a unique */
/*     right-handed coordinate frame having: */

/*        AXDEF lying along the INDEXA axis. */

/*        PLNDEF lying in the INDEXA-INDEXP coordinate plane. */

/*     This routine determines the transformation matrix that transforms */
/*     from coordinates used to represent the input vectors to the */
/*     the system determined by AXDEF and PLNDEF.  Thus a vector */
/*     (x,y,z) in the input coordinate system will have coordinates */

/*                     t */
/*        MOUT* (x,y,z) */

/*     in the frame determined by AXDEF and PLNDEF. */

/* $ Examples */

/*     The rotation matrix TICC from inertial to Sun-Canopus */
/*     (celestial) coordinates is found by the call */

/*        CALL TWOVEC (Sun vector, 3, Canopus vector, 1, TICC) */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     W.M. Owen       (JPL) */
/*     W.L. Taber      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 31-AUG-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in VSCL call. */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0,  31-JAN-1990 (WMO) */

/* -& */
/* $ Index_Entries */

/*     define an orthonormal frame from two vectors */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.1.0, 31-AUG-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in VSCL call. */

/* -    Beta Version 2.0.0, 10-JAN-1989 (WLT) */

/*     Error checking was added and the algorithm somewhat redesigned. */
/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Saved variables */


/*     Initial values */


/*     Standard SPICE error handling */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "TWOVEC", (ftnlen)6);
    }

/*     Check for obvious bad inputs. */

    if (max(*indexp,*indexa) > 3 || min(*indexp,*indexa) < 1) {
	setmsg_(__global_state, "The definition indexs must lie in the range"
		" from 1 to 3.  The value of INDEXA was #. The value of INDEX"
		"P was #. ", (ftnlen)112);
	errint_(__global_state, "#", indexa, (ftnlen)1);
	errint_(__global_state, "#", indexp, (ftnlen)1);
	sigerr_(__global_state, "SPICE(BADINDEX)", (ftnlen)15);
	chkout_(__global_state, "TWOVEC", (ftnlen)6);
	return 0;
    } else if (*indexa == *indexp) {
	setmsg_(__global_state, "The values of INDEXA and INDEXP were the sa"
		"me, namely #.  They are required to be different.", (ftnlen)
		92);
	errint_(__global_state, "#", indexa, (ftnlen)1);
	sigerr_(__global_state, "SPICE(UNDEFINEDFRAME)", (ftnlen)21);
	chkout_(__global_state, "TWOVEC", (ftnlen)6);
	return 0;
    }

/*     Get indices for right-handed axes */

/*     First AXDEF ... */

    i1 = *indexa;

/*     ... then the other two. */

    i2 = __state->seqnce[(i__1 = *indexa) < 5 && 0 <= i__1 ? i__1 : s_rnge(&
	    __global_state->f2c, "seqnce", i__1, "twovec_", (ftnlen)270)];
    i3 = __state->seqnce[(i__1 = *indexa + 1) < 5 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "seqnce", i__1, "twovec_", (ftnlen)
	    271)];

/*     Row I1 contains normalized AXDEF (store in columns for now) */

    vhat_(__global_state, axdef, &mout[(i__1 = i1 * 3 - 3) < 9 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "mout", i__1, "twovec_", (
	    ftnlen)276)]);

/*     Obtain rows I2 and I3 using cross products.  Which order to use */
/*     depends on whether INDEXP = I2 (next axis in right-handed order) */
/*     or INDEXP = I3 (previous axis in right-handed order). */

    if (*indexp == i2) {
	ucrss_(__global_state, axdef, plndef, &mout[(i__1 = i3 * 3 - 3) < 9 &&
		 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "mout", i__1,
		 "twovec_", (ftnlen)285)]);
	ucrss_(__global_state, &mout[(i__1 = i3 * 3 - 3) < 9 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "mout", i__1, "twovec_", (
		ftnlen)286)], axdef, &mout[(i__2 = i2 * 3 - 3) < 9 && 0 <= 
		i__2 ? i__2 : s_rnge(&__global_state->f2c, "mout", i__2, 
		"twovec_", (ftnlen)286)]);
    } else {
	ucrss_(__global_state, plndef, axdef, &mout[(i__1 = i2 * 3 - 3) < 9 &&
		 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "mout", i__1,
		 "twovec_", (ftnlen)290)]);
	ucrss_(__global_state, axdef, &mout[(i__1 = i2 * 3 - 3) < 9 && 0 <= 
		i__1 ? i__1 : s_rnge(&__global_state->f2c, "mout", i__1, 
		"twovec_", (ftnlen)291)], &mout[(i__2 = i3 * 3 - 3) < 9 && 0 
		<= i__2 ? i__2 : s_rnge(&__global_state->f2c, "mout", i__2, 
		"twovec_", (ftnlen)291)]);
    }

/*     Finally, check to see that we actually got something non-zero */
/*     in one of the one columns of MOUT(1,I2) and MOUT(1,I3) (we need */
/*     only check one of them since they are related by a cross product). */

    if (mout[(i__1 = i2 * 3 - 3) < 9 && 0 <= i__1 ? i__1 : s_rnge(&
	    __global_state->f2c, "mout", i__1, "twovec_", (ftnlen)300)] == 0. 
	    && mout[(i__2 = i2 * 3 - 2) < 9 && 0 <= i__2 ? i__2 : s_rnge(&
	    __global_state->f2c, "mout", i__2, "twovec_", (ftnlen)300)] == 0. 
	    && mout[(i__3 = i2 * 3 - 1) < 9 && 0 <= i__3 ? i__3 : s_rnge(&
	    __global_state->f2c, "mout", i__3, "twovec_", (ftnlen)300)] == 0.)
	     {
	setmsg_(__global_state, "The input vectors AXDEF and PLNDEF are line"
		"arly dependent.", (ftnlen)58);
	sigerr_(__global_state, "SPICE(DEPENDENTVECTORS)", (ftnlen)23);
    }

/*     Transpose MOUT. */

    xpose_(__global_state, mout, mtemp);
    moved_(__global_state, mtemp, &__state->c__9, mout);
    chkout_(__global_state, "TWOVEC", (ftnlen)6);
    return 0;
} /* twovec_ */

