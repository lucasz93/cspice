/* zzedtmpt.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzedtmpt_init_t __zzedtmpt_init;
static zzedtmpt_state_t* get_zzedtmpt_state(cspice_t* state) {
	if (!state->zzedtmpt)
		state->zzedtmpt = __cspice_allocate_module(sizeof(
	zzedtmpt_state_t), &__zzedtmpt_init, sizeof(__zzedtmpt_init));
	return state->zzedtmpt;

}

/* $Procedure ZZEDTMPT ( Ellipsoid terminator point in half-plane ) */
/* Subroutine */ int zzedtmpt_(cspice_t* __global_state, logical *umbral, 
	doublereal *a, doublereal *b, doublereal *c__, doublereal *r__, 
	doublereal *axis, doublereal *plnvec, doublereal *point)
{
    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    extern /* Subroutine */ int vadd_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    extern /* Subroutine */ int vhat_(cspice_t*, doublereal *, doublereal *);
    doublereal maxr;
    extern /* Subroutine */ int vscl_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    doublereal proj[3];
    extern doublereal vdot_(cspice_t*, doublereal *, doublereal *);
    integer nitr;
    extern /* Subroutine */ int vequ_(cspice_t*, doublereal *, doublereal *);
    doublereal d__;
    doublereal h__;
    doublereal s;
    doublereal angle;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    doublereal theta;
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    doublereal const__;
    doublereal trans[9]	/* was [3][3] */;
    doublereal taxis[3];
    extern doublereal vdist_(cspice_t*, doublereal *, doublereal *);
    extern /* Subroutine */ int vperp_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    extern /* Subroutine */ int vcrss_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    extern doublereal vnorm_(cspice_t*, doublereal *);
    extern logical vzero_(cspice_t*, doublereal *);
    extern /* Subroutine */ int vrotv_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *, doublereal *);
    extern logical failed_(cspice_t*);
    doublereal ta;
    doublereal tb;
    doublereal tc;
    doublereal xa;
    doublereal xb;
    doublereal xc;
    extern /* Subroutine */ int cleard_(cspice_t*, integer *, doublereal *);
    extern doublereal dasine_(cspice_t*, doublereal *, doublereal *);
    extern doublereal halfpi_(cspice_t*);
    doublereal angerr;
    extern doublereal touchd_(cspice_t*, doublereal *);
    doublereal normal[3];
    doublereal hplnml[3];
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int ednmpt_(cspice_t*, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    doublereal sgnnml[3];
    doublereal tmpvec[3];
    doublereal targpt[3];
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    doublereal tplnvc[3];
    doublereal srcpnt[3];
    doublereal utaxis[3];
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int mxv_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);


    /* Module state */
    zzedtmpt_state_t* __state = get_zzedtmpt_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due to the */
/*     volatile nature of this routine. */

/*     Compute an umbral or penumbral terminator point on an ellipsoidal */
/*     target. The point is confined to a specified half-plane. The */
/*     illumination source is spherical. */

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

/*     GEOMETRY */
/*     ILLUMINATION */
/*     TERMINATOR */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     UMBRAL     I   Flag indicating whether terminator is umbral. */
/*     A          I   Semi-axis length in the X direction. */
/*     B          I   Semi-axis length in the Y direction. */
/*     C          I   Semi-axis length in the Z direction. */
/*     R          I   Radius of illumination source. */
/*     AXIS       I   Axis vector from target to source. */
/*     PLNVEC     I   Vector in cutting half-plane. */
/*     POINT      O   Terminator point. */

/* $ Detailed_Input */

/*     UMBRAL     is a logical flag that must be set by the caller */
/*                to .TRUE. if an umbral terminator point is to be */
/*                computed, and set to .FALSE. if a penumbral */
/*                terminator point is to be computed. */

/*     A, */
/*     B, */
/*     C          are, respectively, the semi-axis lengths of a */
/*                triaxial ellipsoid representing a target object. */
/*                The axes of the ellipsoid are aligned with the */
/*                axes of the Cartesian coordinate system. */


/*     R          is the radius of the spherical model of the */
/*                illumination source. */


/*     AXIS       is the position of the center of the illumination */
/*                source relative to the center of the target. AXIS is */
/*                contained in the line bounding cutting half-planes in */
/*                which terminator points are found. */


/*     PLNVEC     is a vector that, together with AXIS, defines */
/*                a cutting half-plane. The half-plane contains */
/*                PLNVEC and has the line containing AXIS as a */
/*                boundary. */

/*                The terminator point that is sought lies within */
/*                the half-plane. */

/* $ Detailed_Output */

/*     POINT      is a terminator point lying within the half-plane */
/*                defined by AXIS and PLNVEC. */

/*                When UMBRAL is set to .TRUE., POINT lies on the */
/*                umbral terminator: the plane tangent to the target */
/*                ellipsoid at POINT is also tangent to the illumination */
/*                source. This plane does not intersect the vector */
/*                AXIS. */

/*                When UMBRAL is set to .FALSE., POINT lies on the */
/*                penumbral terminator: the plane tangent to the target */
/*                ellipsoid at POINT is also tangent to the illumination */
/*                source. This plane intersects the vector AXIS. */

/*                Unless the target is spherical, the plane tangent */
/*                to the target at POINT is usually tangent to the */
/*                illumination source at a point outside the plane */
/*                containing the cutting half-plane. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If any of the target ellipsoid's semi-axis lengths is */
/*         non-positive, the error SPICE(INVALIDAXISLENGTH) is signaled. */

/*     2)  If the radius of the illumination source is non-positive, the */
/*         error SPICE(INVALIDRADIUS) is signaled. */

/*     3)  If AXIS is the zero vector, the error SPICE(ZEROVECTOR) is */
/*         signaled. */

/*     4)  If the target and illumination source are separated by */
/*         less than the sum of the radius of the source sphere */
/*         and the maximum radius of the target ellipsoid, the */
/*         error SPICE(OBJECTSTOOCLOSE) is signaled. */

/*     5)  If PLNVEC is the zero vector, the error SPICE(ZEROVECTOR) is */
/*         signaled. */

/*     6)  If AXIS and PLNVEC are linearly dependent, the error */
/*         SPICE(DEGENERATECASE) is signaled. */

/*     7)  If the terminator solution doesn't converge, the error */
/*         SPICE(NOCONVERGENCE) is signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     The "umbral" terminator on an ellipsoid is the boundary of the */
/*     region that is in total shadow. At any point P on this boundary, */
/*     the illumination source is below and tangent to the local */
/*     horizontal plane at P. */

/*     The "penumbral" terminator on an ellipsoid is the boundary of the */
/*     region that totally illuminated. At any point P on this boundary, */
/*     the illumination source is above and tangent to the local */
/*     horizontal plane at P. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     This is a SPICELIB private routine. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 30-JUN-2016 (NJB) */

/* -& */
/* $ Index_Entries */

/*     compute ellipsoid terminator point in half-plane */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Tolerance used for arcsine arguments: */


/*     Angular error used to determine convergence: */


/*     Maximum number of iterations allowed for root finding: */


/*     Local variables */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "ZZEDTMPT", (ftnlen)8);

/*     Check A, B, C, and R. */

    if (*a <= 0. || *b <= 0. || *c__ <= 0.) {
	setmsg_(__global_state, "Target radii must be strictly positive but "
		"were #, #, #.", (ftnlen)56);
	errdp_(__global_state, "#", a, (ftnlen)1);
	errdp_(__global_state, "#", b, (ftnlen)1);
	errdp_(__global_state, "#", c__, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDAXISLENGTH)", (ftnlen)24);
	chkout_(__global_state, "ZZEDTMPT", (ftnlen)8);
	return 0;
    }
    if (*r__ <= 0.) {
	setmsg_(__global_state, "Source radius must be strictly positive but"
		" was #.", (ftnlen)50);
	errdp_(__global_state, "#", r__, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDRADIUS)", (ftnlen)20);
	chkout_(__global_state, "ZZEDTMPT", (ftnlen)8);
	return 0;
    }

/*     Check AXIS and PLNVEC. */

    if (vzero_(__global_state, axis)) {
	setmsg_(__global_state, "AXIS must be a non-zero vector but is in fa"
		"ct zero.", (ftnlen)51);
	sigerr_(__global_state, "SPICE(ZEROVECTOR)", (ftnlen)17);
	chkout_(__global_state, "ZZEDTMPT", (ftnlen)8);
	return 0;
    }
/* Computing MAX */
    d__1 = max(*a,*b);
    if (*r__ + max(d__1,*c__) >= vnorm_(__global_state, axis)) {
	setmsg_(__global_state, "Centers of source and target are too close "
		"together; distance is #. Radius of source is #; semi-axis le"
		"ngths are #, #, #.", (ftnlen)121);
	d__1 = vnorm_(__global_state, axis);
	errdp_(__global_state, "#", &d__1, (ftnlen)1);
	errdp_(__global_state, "#", r__, (ftnlen)1);
	errdp_(__global_state, "#", a, (ftnlen)1);
	errdp_(__global_state, "#", b, (ftnlen)1);
	errdp_(__global_state, "#", c__, (ftnlen)1);
	sigerr_(__global_state, "SPICE(OBJECTSTOOCLOSE)", (ftnlen)22);
	chkout_(__global_state, "ZZEDTMPT", (ftnlen)8);
	return 0;
    }
    if (vzero_(__global_state, plnvec)) {
	setmsg_(__global_state, "PLNVEC must be a non-zero vector but is in "
		"fact zero.", (ftnlen)53);
	sigerr_(__global_state, "SPICE(ZEROVECTOR)", (ftnlen)17);
	chkout_(__global_state, "ZZEDTMPT", (ftnlen)8);
	return 0;
    }

/*     Transform the source, target, axis, and plane vector */
/*     so that the target becomes a unit sphere. */

    cleard_(__global_state, &__state->c__9, trans);
    ta = 1. / *a;
    tb = 1. / *b;
    tc = 1. / *c__;
    xa = ta * *r__;
    xb = tb * *r__;
    xc = tc * *r__;
    trans[0] = ta;
    trans[4] = tb;
    trans[8] = tc;

/*     TNEGAX is the negative of the transformed axis. */
/*     UTAXIS is the unit vector in the direction of TNEGAX. */

    mxv_(__global_state, trans, plnvec, tplnvc);
    mxv_(__global_state, trans, axis, taxis);
    vhat_(__global_state, taxis, utaxis);

/*     Let HPLNML be a normal vector to the plane containing */
/*     the transformed axis and plane vectors. */

    vcrss_(__global_state, tplnvc, taxis, hplnml);
    if (vzero_(__global_state, hplnml)) {
	setmsg_(__global_state, "Plane reference vector and axis are linearl"
		"y dependent.", (ftnlen)55);
	sigerr_(__global_state, "SPICE(DEGENERATECASE)", (ftnlen)21);
	chkout_(__global_state, "ZZEDTMPT", (ftnlen)8);
	return 0;
    }

/*     Let MAXR be an outer bounding radius for the transformed */
/*     source sphere. */

/* Computing MAX */
    d__1 = max(xa,xb);
    maxr = max(d__1,xc);
    d__ = vnorm_(__global_state, taxis);
    if (*umbral) {

/*        Find the angle between the negative axis and a ray tangent to */
/*        both the transformed target and the outer bounding sphere of */
/*        the transformed source. Here a tangent point on the */
/*        transformed target is the vertex, and the tangent ray is */
/*        confined to the half-plane normal to HPLNML, containing */
/*        TPLNVC, and bounded by the line containing TNEGAX. The */
/*        tangent ray does not cross the line containing TNEGAX. */

	d__1 = (maxr - 1.) / d__;
	angle = dasine_(__global_state, &d__1, &__state->c_b31);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "ZZEDTMPT", (ftnlen)8);
	    return 0;
	}

/*        Create the tangent point on the transformed target. */

	theta = -(halfpi_(__global_state) + angle);
	vrotv_(__global_state, utaxis, hplnml, &theta, targpt);

/*        S is the sign applied to pi/2 - ANGLE. */

	s = 1.;
    } else {

/*        This is the penumbral case. The tangent ray crosses */
/*        the line containing TNEGAX. */


/*        The tangent line always slopes downward (toward AXIS) */
/*        toward the light source. */

	d__1 = (maxr + 1.) / d__;
	angle = dasine_(__global_state, &d__1, &__state->c_b31);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "ZZEDTMPT", (ftnlen)8);
	    return 0;
	}

/*        Create the tangent point on the transformed target. */

	theta = angle - halfpi_(__global_state);
	vrotv_(__global_state, utaxis, hplnml, &theta, targpt);
	s = -1.;
    }

/*     The tangent point is also a normal direction for the plane */
/*     tangent to both objects. Get the corresponding unit normal and */
/*     the plane constant. */

    vhat_(__global_state, targpt, normal);
    const__ = vdot_(__global_state, normal, targpt);

/*     Find the height of the plane relative to the transformed source. */
/*     We'll find the unique point on the transformed source where the */
/*     outward normal is parallel to NORMAL and find the height of this */
/*     point relative to the plane. */

/*     Let SGNNML be the "signed" normal which is parallel to NORMAL */
/*     in the umbral case and anti-parallel otherwise. */

    vscl_(__global_state, &s, normal, sgnnml);
    ednmpt_(__global_state, &xa, &xb, &xc, sgnnml, srcpnt);

/*     Express the source point as an offset from the transformed */
/*     target center. */

    vadd_(__global_state, srcpnt, taxis, tmpvec);
    vequ_(__global_state, tmpvec, srcpnt);

/*     H is the height of the surface point on the source, relative */
/*     to the plane tangent to the target at TARGPT. ANGERR is the */
/*     corresponding angular error estimate: an estimate of the */
/*     amount by which TARGPT needs to be rotated in the positive */
/*     sense about HPLNML to make the plane contain SRCPNT. */

    h__ = vdot_(__global_state, srcpnt, normal) - const__;
    d__1 = -h__ / d__;
    angerr = touchd_(__global_state, &d__1);
    nitr = 0;

/*     The loop terminates when the angular error magnitude */
/*     stops decreasing. If the iteration count exceeds the */
/*     limit, an error will be signaled. */

    while(abs(angerr) > 1e-15 && nitr <= 20) {

/*        Rotate the target point about HPLNML in the positive sense */
/*        by the angular error. This should make the tangent plane */
/*        closer to the source point. */

	vrotv_(__global_state, targpt, hplnml, &angerr, tmpvec);
	vequ_(__global_state, tmpvec, targpt);
	vhat_(__global_state, targpt, normal);

/*        Re-compute the normal and constant of the tangent plane. */

	const__ = vdot_(__global_state, normal, targpt);
	vscl_(__global_state, &s, normal, sgnnml);

/*        Find the near point on the source to the tangent plane. */

	ednmpt_(__global_state, &xa, &xb, &xc, sgnnml, srcpnt);
	vadd_(__global_state, srcpnt, taxis, tmpvec);
	vequ_(__global_state, tmpvec, srcpnt);

/*        Re-compute the height error and angular error. */

	h__ = vdot_(__global_state, srcpnt, normal) - const__;
	vperp_(__global_state, srcpnt, hplnml, proj);
	d__ = vdist_(__global_state, proj, targpt);
	d__1 = -h__ / d__;
	angerr = touchd_(__global_state, &d__1);
	++nitr;
	if (nitr > 20) {
	    setmsg_(__global_state, "Tangent finding loop failed to converge"
		    ". Iteration count = #.", (ftnlen)61);
	    errint_(__global_state, "#", &nitr, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(NOCONVERGENCE)", (ftnlen)20);
	    chkout_(__global_state, "ZZEDTMPT", (ftnlen)8);
	    return 0;
	}
    }

/*     Apply the inverse distortion transformation to TARGPT in order to */
/*     obtain the tangent point on the original, ellipsoidal target. */

    point[0] = *a * targpt[0];
    point[1] = *b * targpt[1];
    point[2] = *c__ * targpt[2];
    chkout_(__global_state, "ZZEDTMPT", (ftnlen)8);
    return 0;
} /* zzedtmpt_ */

