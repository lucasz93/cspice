/* surfnm.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern surfnm_init_t __surfnm_init;
static surfnm_state_t* get_surfnm_state(cspice_t* state) {
	if (!state->surfnm)
		state->surfnm = __cspice_allocate_module(sizeof(
	surfnm_state_t), &__surfnm_init, sizeof(__surfnm_init));
	return state->surfnm;

}

/* $Procedure      SURFNM ( Surface normal vector on an ellipsoid ) */
/* Subroutine */ int surfnm_(cspice_t* __global_state, doublereal *a, 
	doublereal *b, doublereal *c__, doublereal *point, doublereal *normal)
{
    /* Initialized data */


    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2];
    doublereal d__1;
    char ch__1[35];

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);
    /* Subroutine */ int s_cat(f2c_state_t*, char *, char **, integer *, 
	    integer *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int vhatip_(cspice_t*, doublereal *);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);

    /* Module state */
    surfnm_state_t* __state = get_surfnm_state(__global_state);
/* $ Abstract */

/*     This routine computes the outward-pointing, unit normal vector */
/*     from a point on the surface of an ellipsoid. */

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

/*      ELLIPSOID,  GEOMETRY */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     A          I   Length of the ellipsoid semi-axis along the x-axis. */
/*     B          I   Length of the ellipsoid semi-axis along the y-axis. */
/*     C          I   Length of the ellipsoid semi-axis along the z-axis. */
/*     POINT      I   Body-fixed coordinates of a point on the ellipsoid. */
/*     NORMAL     O   Outward pointing unit normal to ellipsoid at POINT. */

/* $ Detailed_Input */

/*     A          This is the length of the semi-axis of the ellipsoid */
/*                that is parallel to the x-axis of the body-fixed */
/*                coordinate system. */

/*     B          This is the length of the semi-axis of the ellipsoid */
/*                that is parallel to the y-axis of the body-fixed */
/*                coordinate system. */

/*     C          This is the length of the semi-axis of the ellipsoid */
/*                that is parallel to the z-axis of the body-fixed */
/*                coordinate system. */

/*     POINT      This is a 3-vector giving the bodyfixed coordinates */
/*                of a point on the ellipsoid. In bodyfixed coordinates, */
/*                the semi-axes of the ellipsoid are aligned with the */
/*                x, y, and z-axes of the coordinate system. */

/* $ Detailed_Output */

/*     NORMAL     A unit vector pointing away from the ellipsoid and */
/*                normal to the ellipsoid at POINT. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If any of the axes are non-positive, the error */
/*        SPICE(BADAXISLENGTH) will be signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine computes the outward pointing unit normal vector to */
/*     the ellipsoid having semi-axes of length A, B, and C from the */
/*     point POINT. */

/* $ Examples */

/*     A typical use of SURFNM would be to find the angle of incidence */
/*     of the light from the sun at a point on the surface of an */
/*     ellipsoid. */

/*     Let Q be a 3-vector representing the rectangular body-fixed */
/*     coordinates of a point on the ellipsoid (we are assuming that */
/*     the axes of the ellipsoid are aligned with the axes of the */
/*     body fixed frame.)  Let V be the vector from Q to the sun in */
/*     bodyfixed coordinates.  Then the following code fragment could */
/*     be used to compute angle of incidence of sunlight at Q. */

/*        CALL SURFNM   ( A, B, C, Q, NRML ) */

/*        INCIDN = VSEP ( V,          NRML ) */


/* $ Restrictions */

/*     It is assumed that the input POINT is indeed on the ellipsoid. */
/*     No checking for this is done. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     B.V. Semenov    (JPL) */
/*     W.L. Taber      (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.3.2, 23-FEB-2016 (NJB) */

/*        Corrected some typos in the header. */

/* -    SPICELIB Version 1.3.1, 18-MAY-2010 (BVS) */

/*        Removed "C$" marker from text in the header. */

/* -    SPICELIB Version 1.3.0, 02-SEP-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in VHAT call. */

/* -    SPICELIB Version 1.2.0, 07-AUG-1996 (WLT) */

/*        Added a SAVE statement so that the error message will */
/*        not be lost between separate invocations of the routine. */

/* -    SPICELIB Version 1.1.0, 21-JUL-1995 (WLT) */

/*        A typo in the Examples section was corrected */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (WLT) */

/* -& */
/* $ Index_Entries */

/*     surface normal vector on an ellipsoid */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.3.0, 02-SEP-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in VHAT call. */

/* -    Beta Version 2.0.0, 9-JAN-1989  (WLT) */

/*     Error handling added. */

/*     The algorithm was modified from the initial obvious routine */
/*     to one that is immune to numerical catastrophes (multiplication */
/*     or division overflows). */

/* -& */

/*     SPICELIB Functions */


/*     Local Variables */


/*     Initial values */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "SURFNM", (ftnlen)6);
    }

/*     Check the axes to make sure that none of them is less than or */
/*     equal to zero. If one is, signal an error and return. */

    __state->bad = 0;
    if (*a <= 0.) {
	++__state->bad;
    }
    if (*b <= 0.) {
	__state->bad += 2;
    }
    if (*c__ <= 0.) {
	__state->bad += 4;
    }
    if (__state->bad > 0) {
/* Writing concatenation */
	i__2[0] = 32, a__1[0] = __state->mssg + (((i__1 = __state->bad - 1) < 
		7 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "mssg", 
		i__1, "surfnm_", (ftnlen)251)) << 5);
	i__2[1] = 3, a__1[1] = " ? ";
	s_cat(&__global_state->f2c, ch__1, a__1, i__2, &__state->c__2, (
		ftnlen)35);
	setmsg_(__global_state, ch__1, (ftnlen)35);
	errch_(__global_state, " ? ", "The A,B, and C axes were #, #, and # "
		"respectively.", (ftnlen)3, (ftnlen)50);
	errdp_(__global_state, "#", a, (ftnlen)1);
	errdp_(__global_state, "#", b, (ftnlen)1);
	errdp_(__global_state, "#", c__, (ftnlen)1);
	sigerr_(__global_state, "SPICE(BADAXISLENGTH)", (ftnlen)20);
	chkout_(__global_state, "SURFNM", (ftnlen)6);
	return 0;
    }

/*     Mathematically we want to compute (Px/a**2, Py/b**2, Pz/c**2) */
/*     and then convert this to a unit vector. However, computationally */
/*     this can blow up in our faces.  But note that only the ratios */
/*     a/b, b/c and a/c are important in computing the unit normal. */
/*     We can use the trick below to avoid the unpleasantness of */
/*     multiplication and division overflows. */

/* Computing MIN */
    d__1 = min(*a,*b);
    __state->m = min(d__1,*c__);

/*     M can be divided by A,B or C without fear of an overflow */
/*     occurring. */

    __state->a1 = __state->m / *a;
    __state->b1 = __state->m / *b;
    __state->c1 = __state->m / *c__;

/*     All of the terms A1,B1,C1 are less than 1. Thus no overflows */
/*     can occur. */

    normal[0] = point[0] * (__state->a1 * __state->a1);
    normal[1] = point[1] * (__state->b1 * __state->b1);
    normal[2] = point[2] * (__state->c1 * __state->c1);
    vhatip_(__global_state, normal);
    chkout_(__global_state, "SURFNM", (ftnlen)6);
    return 0;
} /* surfnm_ */

