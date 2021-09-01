/* edlimb.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern edlimb_init_t __edlimb_init;
static edlimb_state_t* get_edlimb_state(cspice_t* state) {
	if (!state->edlimb)
		state->edlimb = __cspice_allocate_module(sizeof(
	edlimb_state_t), &__edlimb_init, sizeof(__edlimb_init));
	return state->edlimb;

}

/* $Procedure  EDLIMB   ( Ellipsoid Limb ) */
/* Subroutine */ int edlimb_(cspice_t* __global_state, doublereal *a, 
	doublereal *b, doublereal *c__, doublereal *viewpt, doublereal *limb)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Local variables */
    doublereal scla;
    doublereal sclb;
    doublereal sclc;
    extern /* Subroutine */ int vscl_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    doublereal scla2;
    doublereal sclb2;
    doublereal sclc2;
    doublereal v[3];
    doublereal scale;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    doublereal level;
    extern /* Subroutine */ int moved_(cspice_t*, doublereal *, integer *, 
	    doublereal *);
    logical found;
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    extern /* Subroutine */ int vsclg_(cspice_t*, doublereal *, doublereal *, 
	    integer *, doublereal *);
    doublereal tmpel[9];
    extern /* Subroutine */ int nvc2pl_(cspice_t*, doublereal *, doublereal *,
	     doublereal *);
    doublereal lplane[4];
    extern /* Subroutine */ int inedpl_(cspice_t*, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, logical *);
    doublereal normal[3];
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    edlimb_state_t* __state = get_edlimb_state(__global_state);
/* $ Abstract */

/*     Find the limb of a triaxial ellipsoid, viewed from a specified */
/*     point. */

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

/*     ELLIPSES */

/* $ Keywords */

/*     ELLIPSE */
/*     ELLIPSOID */
/*     GEOMETRY */
/*     MATH */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     A          I   Length of ellipsoid semi-axis lying on the x-axis. */
/*     B          I   Length of ellipsoid semi-axis lying on the y-axis. */
/*     C          I   Length of ellipsoid semi-axis lying on the z-axis. */
/*     VIEWPT     I   Location of viewing point. */
/*     LIMB       O   Limb of ellipsoid as seen from viewing point. */

/* $ Detailed_Input */

/*     A, */
/*     B, */
/*     C              are the lengths of the semi-axes of a triaxial */
/*                    ellipsoid.  The ellipsoid is centered at the */
/*                    origin and oriented so that its axes lie on the */
/*                    x, y and z axes.  A, B, and C are the lengths of */
/*                    the semi-axes that point in the x, y, and z */
/*                    directions respectively. */

/*     VIEWPT         is a point from which the ellipsoid is viewed. */
/*                    VIEWPT must be outside of the ellipsoid. */

/* $ Detailed_Output */

/*     LIMB           is a SPICELIB ellipse that represents the limb of */
/*                    the ellipsoid. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the length of any semi-axis of the ellipsoid is */
/*         non-positive, the error SPICE(INVALIDAXISLENGTH) is signalled. */
/*         LIMB is not modified. */

/*     2)  If the length of any semi-axis of the ellipsoid is zero after */
/*         the semi-axis lengths are scaled by the reciprocal of the */
/*         magnitude of the longest semi-axis and then squared, the error */
/*         SPICE(DEGENERATECASE) is signalled.  LIMB is not modified. */

/*     3)  If the viewing point VIEWPT is inside the ellipse, the error */
/*         SPICE(INVALIDPOINT) is signalled.  LIMB is not modified. */

/*     4)  If the geometry defined by the input ellipsoid and viewing */
/*         point is so extreme that the limb cannot be found, the error */
/*         SPICE(DEGENERATECASE) is signalled. */

/*     5)  If the shape of the ellipsoid and the viewing geometry are */
/*         such that the limb is an excessively flat ellipsoid, the */
/*         limb may be a degenerate ellipse.  You must determine whether */
/*         this possibility poses a problem for your application. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     The limb of a body, as seen from a viewing point, is the boundary */
/*     of the portion of the body's surface that is visible from that */
/*     viewing point.  In this definition, we consider a surface point */
/*     to be `visible' if it can be connected to the viewing point by a */
/*     line segment that doen't pass through the body.  This is a purely */
/*     geometrical definition that ignores the matter of which portions */
/*     of the surface are illuminated, or whether the view is obscured by */
/*     any additional objects. */

/*     If a body is modelled as a triaxial ellipsoid, the limb is always */
/*     an ellipse.  The limb is determined by its center, a semi-major */
/*     axis vector, and a semi-minor axis vector. */

/*     We note that the problem of finding the limb of a triaxial */
/*     ellipsoid is mathematically identical to that of finding its */
/*     terminator, if one makes the simplifying assumption that the */
/*     terminator is the limb of the body as seen from the vertex of the */
/*     umbra.  So, this routine can be used to solve this simplified */
/*     version of the problem of finding the terminator. */

/* $ Examples */

/*     1)  We'd like to find the apparent limb of Jupiter, corrected for */
/*         light time, as seen from a spacecraft's position at time ET. */

/*            C */
/*            C     Find the viewing point in Jupiter-centered */
/*            C     coordinates.  To do this, find the apparent position */
/*            C     of Jupiter as seen from the spacecraft and negate */
/*            C     this vector.  In this case we'll use light time */
/*            C     correction to arrive at the apparent limb. JSTAT is */
/*            C     the Jupiter's state (position and velocity) as seen */
/*            C     from the spacecraft.  SCPOS is the spacecraft's */
/*            C     position relative to Jupiter. */
/*            C */
/*                  CALL SPKEZ  ( JUPID,  ET, 'J2000', 'LT', SCID, */
/*                 .              SCSTAT, LT                       ) */

/*                  CALL VMINUS ( SCSTAT, SCPOS ) */

/*            C */
/*            C     Get Jupiter's semi-axis lengths... */
/*            C */
/*                  CALL BODVCD ( JUPID, 'RADII', 3, N, RAD ) */

/*            C */
/*            C     ...and the transformation from J2000 to Jupiter */
/*            C     equator and prime meridian coordinates. Note that we */
/*            C     use the orientation of Jupiter at the time of */
/*            C     emission of the light that arrived at the */
/*            C     spacecraft at time ET. */
/*            C */
/*                  CALL BODMAT ( JUPID, ET-LT, TIPM ) */

/*            C */
/*            C     Transform the spacecraft's position into Jupiter- */
/*            C     fixed coordinates. */
/*            C */
/*                  CALL MXV ( TIPM, SCPOS, SCPOS ) */

/*            C */
/*            C     Find the apparent limb.  LIMB is a SPICELIB ellipse */
/*            C     representing the limb. */
/*            C */
/*                  CALL EDLIMB ( RAD(1), RAD(2), RAD(3), SCPOS, LIMB ) */

/*            C */
/*            C     LCENTR, SMAJOR, and SMINOR are the limb's center, */
/*            C     semi-major axis of the limb, and a semi-minor axis */
/*            C     of the limb.  We obtain these from LIMB using the */
/*            C     SPICELIB routine EL2CGV ( Ellipse to center and */
/*            C     generating vectors ). */
/*            C */
/*                  CALL EL2CGV ( LIMB, CENTER, SMAJOR, SMINOR ) */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.3.0, 23-OCT-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in VSCLG call.  Updated header to refer to BODVCD instead */
/*        of BODVAR. */

/* -    SPICELIB Version 1.2.0, 06-OCT-1993 (NJB) */

/*        Declaration of unused local variable NEAR was removed. */

/* -    SPICELIB Version 1.1.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.1.0, 04-DEC-1990 (NJB) */

/*        Error message and description changed for non-positive */
/*        axis length error. */

/* -    SPICELIB Version 1.0.0, 02-NOV-1990 (NJB) */

/* -& */
/* $ Index_Entries */

/*     ellipsoid limb */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.3.0, 23-OCT-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in VSCLG call.  Updated header to refer to BODVCD instead */
/*        of BODVAR. */

/* -    SPICELIB Version 1.2.0, 06-OCT-1993 (NJB) */

/*        Declaration of unused local variable NEAR was removed. */

/* -    SPICELIB Version 1.1.0, 04-DEC-1990 (NJB) */

/*        Error message and description changed for non-positive */
/*        axis length error.  The former message and description did */
/*        not match, and the description was incorrect:  it described */
/*        `zero-length', rather than `non-positive' axes as invalid. */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "EDLIMB", (ftnlen)6);
    }

/*     The semi-axes must have positive length. */

    if (*a <= 0. || *b <= 0. || *c__ <= 0.) {
	setmsg_(__global_state, "Semi-axis lengths:  A = #, B = #, C = #. ", (
		ftnlen)41);
	errdp_(__global_state, "#", a, (ftnlen)1);
	errdp_(__global_state, "#", b, (ftnlen)1);
	errdp_(__global_state, "#", c__, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDAXISLENGTH)", (ftnlen)24);
	chkout_(__global_state, "EDLIMB", (ftnlen)6);
	return 0;
    }

/*     Scale the semi-axes lengths for better numerical behavior. */
/*     If squaring any one of the scaled lengths causes it to */
/*     underflow to zero, we cannot continue the computation. Otherwise, */
/*     scale the viewing point too. */

/* Computing MAX */
    d__1 = abs(*a), d__2 = abs(*b), d__1 = max(d__1,d__2), d__2 = abs(*c__);
    scale = max(d__1,d__2);
    scla = *a / scale;
    sclb = *b / scale;
    sclc = *c__ / scale;
/* Computing 2nd power */
    d__1 = scla;
    scla2 = d__1 * d__1;
/* Computing 2nd power */
    d__1 = sclb;
    sclb2 = d__1 * d__1;
/* Computing 2nd power */
    d__1 = sclc;
    sclc2 = d__1 * d__1;
    if (scla2 == 0. || sclb2 == 0. || sclc2 == 0.) {
	setmsg_(__global_state, "Semi-axis too small:  A = #, B = #, C = #. ",
		 (ftnlen)43);
	errdp_(__global_state, "#", a, (ftnlen)1);
	errdp_(__global_state, "#", b, (ftnlen)1);
	errdp_(__global_state, "#", c__, (ftnlen)1);
	sigerr_(__global_state, "SPICE(DEGENERATECASE)", (ftnlen)21);
	chkout_(__global_state, "EDLIMB", (ftnlen)6);
	return 0;
    }
    d__1 = 1. / scale;
    vscl_(__global_state, &d__1, viewpt, v);

/*     The viewing point must be outside of the ellipsoid.  LEVEL is the */
/*     constant of the level surface that V lies on.  The ellipsoid */
/*     itself is the level surface corresponding to LEVEL = 1. */

/* Computing 2nd power */
    d__1 = v[0];
/* Computing 2nd power */
    d__2 = v[1];
/* Computing 2nd power */
    d__3 = v[2];
    level = d__1 * d__1 / scla2 + d__2 * d__2 / sclb2 + d__3 * d__3 / sclc2;
    if (level < 1.) {
	setmsg_(__global_state, "Viewing point is inside the ellipsoid.", (
		ftnlen)38);
	sigerr_(__global_state, "SPICE(DEGENERATECASE)", (ftnlen)21);
	chkout_(__global_state, "EDLIMB", (ftnlen)6);
	return 0;
    }

/*     Find a normal vector for the limb plane. */

/*     To compute this vector, we use the fact that the surface normal at */
/*     each limb point is orthogonal to the line segment connecting the */
/*     viewing point and the limb point.   Let the notation */

/*        < a, b > */

/*     indicate the dot product of the vectors a and b.  If we call the */
/*     viewing point V and the limb point X, then */



/*                            X(1)         X(2)         X(3) */
/*        0  =   < V - X,  ( -------- ,   -------- ,   --------  )  > */
/*                                2           2             2 */
/*                            SCLA        SCLB          SCLC */


/*                            X(1)         X(2)         X(3) */
/*           =   <   V,    ( -------- ,   -------- ,   --------  )  > */
/*                                2           2             2 */
/*                            SCLA        SCLB          SCLC */


/*                            X(1)         X(2)         X(3) */
/*            - <   X,    ( -------- ,   -------- ,   --------  )  > */
/*                                2           2             2 */
/*                            SCLA        SCLB          SCLC */

/*                                2           2             2 */
/*                            X(1)        X(2)          X(3) */
/*           =             --------  +   --------  +  -------- */
/*                               2            2             2 */
/*                           SCLA         SCLB          SCLC */


/*           =   1 */


/*     This last equation is just the equation of the scaled ellipsoid. */
/*     We can combine the last two equalities and interchange the */
/*     positions of X and V to obtain */


/*                      V(1)         V(2)         V(3) */
/*        <   X,    ( -------- ,   -------- ,   --------  )  >   =   1 */
/*                          2           2             2 */
/*                      SCLA        SCLB          SCLC */


/*     This is the equation of the limb plane. */


/*     Put together a SPICELIB plane, LPLANE, that represents the limb */
/*     plane. */

    normal[0] = v[0] / scla2;
    normal[1] = v[1] / sclb2;
    normal[2] = v[2] / sclc2;
    nvc2pl_(__global_state, normal, &__state->c_b18, lplane);

/*     Find the limb by intersecting the limb plane with the ellipsoid. */

    inedpl_(__global_state, &scla, &sclb, &sclc, lplane, limb, &found);

/*     FOUND should be true unless we've encountered numerical problems. */

    if (! found) {
	setmsg_(__global_state, "Ellipsoid shape and viewing geometry are to"
		"o extreme; the limb was not found. ", (ftnlen)78);
	sigerr_(__global_state, "SPICE(DEGENERATECASE)", (ftnlen)21);
	chkout_(__global_state, "EDLIMB", (ftnlen)6);
	return 0;
    }

/*     Undo the scaling before returning the limb. */

    vsclg_(__global_state, &scale, limb, &__state->c__9, tmpel);
    moved_(__global_state, tmpel, &__state->c__9, limb);
    chkout_(__global_state, "EDLIMB", (ftnlen)6);
    return 0;
} /* edlimb_ */

