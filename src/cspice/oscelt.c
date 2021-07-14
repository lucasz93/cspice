/* oscelt.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static doublereal c_b16 = 0.;
static doublereal c_b17 = 1.;
static doublereal c_b18 = 1e-10;

/* $Procedure      OSCELT ( Determine conic elements from state ) */
/* Subroutine */ int oscelt_(doublereal *state, doublereal *et, doublereal *
	mu, doublereal *elts)
{
    /* Initialized data */

    static thread_local doublereal zvec[3] = { 0.,0.,1. };

    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double atan2(doublereal, doublereal), cos(doublereal), sqrt(doublereal), 
	    sin(doublereal), d_sign(doublereal *, doublereal *), sinh(
	    doublereal), tan(doublereal);

    /* Local variables */
    doublereal rmag, argp, vmag;
    extern /* Subroutine */ int vhat_(doublereal *, doublereal *);
    extern doublereal vdot_(doublereal *, doublereal *), vsep_(doublereal *, 
	    doublereal *);
    extern /* Subroutine */ int vequ_(doublereal *, doublereal *);
    doublereal e[3], h__[3], n[3], p, r__[3], v[3], cosea;
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    doublereal sinea, lnode, coshf;
    extern doublereal exact_(doublereal *, doublereal *, doublereal *);
    extern /* Subroutine */ int vpack_(doublereal *, doublereal *, doublereal 
	    *, doublereal *), errdp_(char *, doublereal *, ftnlen), vlcom_(
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *);
    doublereal perix[3], periy[3], xprod[3], m0;
    extern /* Subroutine */ int ucrss_(doublereal *, doublereal *, doublereal 
	    *), vcrss_(doublereal *, doublereal *, doublereal *);
    extern doublereal vnorm_(doublereal *), twopi_(void);
    extern logical vzero_(doublereal *);
    doublereal ea;
    extern doublereal pi_(void), dacosh_(doublereal *);
    doublereal nu, rp;
    extern /* Subroutine */ int sigerr_(char *, ftnlen), chkout_(char *, 
	    ftnlen), vsclip_(doublereal *, doublereal *), setmsg_(char *, 
	    ftnlen);
    extern logical return_(void);
    doublereal ecc, inc;

/* $ Abstract */

/*     Determine the set of osculating conic orbital elements that */
/*     corresponds to the state (position, velocity) of a body at */
/*     some epoch. */

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

/*     CONIC */
/*     EPHEMERIS */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     STATE      I   State of body at epoch of elements. */
/*     ET         I   Epoch of elements. */
/*     MU         I   Gravitational parameter (GM) of primary body. */
/*     ELTS       O   Equivalent conic elements. */

/* $ Detailed_Input */

/*     STATE      is the state (position and velocity) of the body */
/*                at some epoch. Components are x, y, z, dx/dt, dy/dt, */
/*                dz/dt. STATE must be expressed relative to an */
/*                inertial reference frame.  Units are km and km/sec. */


/*     ET         is the epoch of the input state, in ephemeris seconds */
/*                past J2000. */

/*                                                       3    2 */
/*     MU         is the gravitational parameter (GM, km /sec ) of */
/*                the primary body. */

/* $ Detailed_Output */

/*     ELTS        are equivalent conic elements describing the orbit */
/*                 of the body around its primary. The elements are, */
/*                 in order: */

/*                    RP      Perifocal distance. */
/*                    ECC     Eccentricity. */
/*                    INC     Inclination. */
/*                    LNODE   Longitude of the ascending node. */
/*                    ARGP    Argument of periapsis. */
/*                    M0      Mean anomaly at epoch. */
/*                    T0      Epoch. */
/*                    MU      Gravitational parameter. */

/*                 The epoch of the elements is the epoch of the input */
/*                 state. Units are km, rad, rad/sec. The same elements */
/*                 are used to describe all three types (elliptic, */
/*                 hyperbolic, and parabolic) of conic orbit. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If MU is not positive, the error SPICE(NONPOSITIVEMASS) */
/*        is signaled. */

/*     2) If the specific angular momentum vector derived from STATE */
/*        is the zero vector, the error SPICE(DEGENERATECASE) */
/*        is signaled. */

/*     3) If the position or velocity vectors derived from STATE */
/*        is the zero vector, the error SPICE(DEGENERATECASE) */
/*        is signaled. */

/*     4) If the inclination is determined to be zero or 180 degrees, */
/*        the longitude of the ascending node is set to zero. */

/*     5) If the eccentricity is determined to be zero, the argument of */
/*        periapse is set to zero. */

/*     6) If the eccentricy of the orbit is very close to but not */
/*        equal to zero, the argument of periapse may not be accurately */
/*        determined. */

/*     7) For inclinations near but not equal to 0 or 180 degrees, */
/*        the longitude of the ascending node may not be determined */
/*        accurately.  The argument of periapse and mean anomaly may */
/*        also be inaccurate. */

/*     8) For eccentricities very close to but not equal to 1, the */
/*        results of this routine are unreliable. */

/*     9) If the specific angular momentum vector is non-zero but */
/*        "close" to zero, the results of this routine are unreliable. */

/*    10) If STATE is expressed relative to a non-inertial reference */
/*        frame, the resulting elements are invalid.  No error checking */
/*        is done to detect this problem. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     The SPICELIB routine CONICS is the inverse of this routine: */
/*     CONICS maps a set of osculating elements and a time to a state */
/*     vector. */

/* $ Examples */

/*     Let VINIT contain the initial state of a spacecraft relative to */
/*     the center of a planet at epoch ET, and let GM be the gravitation */
/*     parameter of the planet. The call */

/*        CALL OSCELT ( VINIT, ET, GM, ELTS ) */

/*     produces a set of osculating elements describing the nominal */
/*     orbit that the spacecraft would follow in the absence of all */
/*     other bodies in the solar system. */

/*     Now let STATE contain the state of the same spacecraft at some */
/*     other epoch, LATER. The difference between this state and the */
/*     state predicted by the nominal orbit at the same epoch can be */
/*     computed as follows. */

/*        CALL CONICS ( ELTS, LATER, NOMINAL ) */
/*        CALL VSUBG  ( NOMINAL, STATE, 6, DIFF ) */

/*        WRITE (*,*) 'Perturbation in x, dx/dt = ', DIFF(1), DIFF(4) */
/*        WRITE (*,*) '                y, dy/dt = ', DIFF(2), DIFF(5) */
/*        WRITE (*,*) '                z, dz/dt = ', DIFF(3), DIFF(6) */

/* $ Restrictions */

/*     1) The input state vector must be expressed relative to an */
/*        inertial reference frame. */

/*     2) Osculating elements are generally not useful for */
/*        high-accuracy work. */

/*     3) Accurate osculating elements may be difficult to derive for */
/*        near-circular or near-equatorial orbits. Osculating elements */
/*        for such orbits should be used with caution. */

/*     4) Extracting osculating elements from a state vector is a */
/*        mathematically simple but numerically challenging task.  The */
/*        mapping from a state vector to equivalent elements is */
/*        undefined for certain state vectors, and the mapping is */
/*        difficult to implement with finite precision arithmetic for */
/*        states near the subsets of R6 where singularities occur. */

/*        In general, the elements found by this routine can have */
/*        two kinds of problems: */

/*           - The elements are not accurate but still represent */
/*             the input state accurately.  The can happen in */
/*             cases where the inclination is near zero or 180 */
/*             degrees, or for near-circular orbits. */

/*           - The elements are garbage.  This can occur when */
/*             the eccentricity of the orbit is close to but */
/*             not equal to 1.   In general, any inputs that cause */
/*             great loss of precision in the computation of the */
/*             specific angular momentum vector or the eccentricity */
/*             vector will result in invalid outputs. */

/*        For further details, see the Exceptions section. */

/*        Users of this routine should carefully consider whether */
/*        it is suitable for their applications.  One recommended */
/*        "sanity check" on the outputs is to supply them to the */
/*        SPICELIB routine CONICS and compare the resulting state */
/*        vector with the one supplied to this routine. */

/* $ Literature_References */

/*     [1] Roger Bate, Fundamentals of Astrodynamics, Dover, 1971. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     K.R. Gehringer  (JPL) */
/*     I.M. Underwood  (JPL) */
/*     E.D. Wright     (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.3.1, 28-FEB-2008 (NJB) */

/*        Updated Index_Entries header section to use keywords */
/*        "osculating" and "convert." Updated Particulars header */
/*        section to refer to CONICS. Fixed typo in in-line */
/*        comments. */

/* -    SPICELIB Version 1.3.0, 17-NOV-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in VSCL call. */

/*        The Exceptions and Restrictions header sections were updated. */

/* -    SPICELIB Version 1.2.0, 28-JAN-2003 (NJB) (EDW) */

/*        Bug fixes:  routine previously didn't correctly compute */
/*        the argument of periapse or mean anomaly for some cases. */
/*        Also, the arguments of the ACOS and DACOSH functions were */
/*        able to go out of range, causing floating-point exceptions. */

/*        The computations of M0 and INC were re-coded for improved */
/*        accuracy. */

/*        Also, added error checks for non-positive MU, zero */
/*        position, velocity, and specific angular momentum vectors. */

/* -    SPICELIB Version 1.1.0, 29-FEB-1996 (KRG) */

/*        The declaration for the SPICELIB function PI is now */
/*        preceded by an EXTERNAL statement declaring PI to be an */
/*        external function. This removes a conflict with any */
/*        compilers that have a PI intrinsic function. */

/* -    SPICELIB Version 1.0.2, 6-APR-1995 (WLT) */

/*        A typo was fixed in the description of the node vector */
/*        in the comments of the routine. */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     conic elements from state */
/*     osculating elements from state */
/*     convert state to osculating elements */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.3.0, 02-SEP-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in VSCL call. */

/* -    SPICELIB Version 1.2.0, 28-JAN-2003 (NJB) (EDW) */

/*        Bug fixes:  routine previously didn't correctly compute */
/*        the argument of periapse or mean anomaly for some cases. */
/*        Also, the arguments of the ACOS and DACOSH functions were */
/*        able to go out of range, causing floating-point exceptions. */

/*        The old computation of ARGP did not work for cases where */
/*        the inclination was 0 or pi:  the sign of ARGP was sometimes */
/*        incorrect. */

/*        The new method uses the criterion: for inclination zero or pi */
/*        the argument of periapse is between zero and pi radians when */

/*           e  *  ( h x n )  >  0 */
/*           -       -   -    - */

/*        where */

/*           e  is the eccentricity vector, */
/*           - */

/*           h  is the specific angular momentum vector, */
/*           - */

/*           n  is the node vector. */
/*           - */

/*        The computation of M0 was re-coded for improved accuracy. */
/*        The new computation uses ATAN2 rather than ACOS to find */
/*        the eccentric anomaly for the ellipse case.  The quadrant */
/*        of M0 is now found by converting the position to the */
/*        perifocal frame and finding the corresponding longitude. */

/*        The old method, using the sign of <r,v>, did not work */
/*        for circular orbits and was unreliable for near-circular */
/*        orbits. */

/*        Inclination is now computed using VSEP. */

/*        Also, added error checks for non-positive MU, zero */
/*        position, velocity, and specific angular momentum vectors. */

/* -    SPICELIB Version 1.1.0, 29-FEB-1996 (KRG) */

/*        The declaration for the SPICELIB function PI is now */
/*        preceded by an EXTERNAL statement declaring PI to be an */
/*        external function. This removes a conflict with any */
/*        compilers that have a PI intrinsic function. */

/* -    SPICELIB Version 1.0.2, 6-APR-1995 (WLT) */

/*        A typo was fixed in the description of the node vector */
/*        in the comments of the routine. */

/* -    Beta Version 1.0.1, 27-JAN-1989 (IMU) */

/*        Examples section completed. */

/* -& */

/*     External functions */


/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     Saved variables */


/*     Initial values */


/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    } else {
	chkin_("OSCELT", (ftnlen)6);
    }
    if (*mu <= 0.) {
	setmsg_("MU = #; non-positive gravitational parameter", (ftnlen)44);
	errdp_("#", mu, (ftnlen)1);
	sigerr_("SPICE(NONPOSITIVEMASS)", (ftnlen)22);
	chkout_("OSCELT", (ftnlen)6);
	return 0;
    }

/*     In order to convert a position and velocity to an equivalent */
/*     set of (osculating) orbital elements, we need to determine three */
/*     principal vectors associated with the orbit: */

/*        h         The angular momentum vector. This is perpendicular */
/*        -         to the plane of the orbit. */

/*                        h = r X v */
/*                        -   -   - */

/*        n         The node vector. This is perpendicular to the */
/*        -         normals of both the reference and orbital planes; */
/*                  it lies in the intersecton of these planes, */
/*                  pointing toward the ascending node. */

/*                             ^ */
/*                        n  = k X h  = ( -h , h , 0 ) */
/*                        -        -        y   x */

/*        e         The eccentricity vector. This lies in the plane */
/*        -         of the orbit, and points toward periapse. The */
/*                  magnitude of this vector is the eccentricity. */

/*                                      2 */
/*                        e = (1/mu)( (v  - mu/r) r  -  <r,v> v ) */
/*                        -                       -      - -  - */

    vequ_(state, r__);
    vequ_(&state[3], v);

/*     Check for non-physical cases. Probably due to user */
/*     input error */

    if (vzero_(r__)) {
	setmsg_("Zero vector for input position vector.", (ftnlen)38);
	sigerr_("SPICE(DEGENERATECASE)", (ftnlen)21);
	chkout_("OSCELT", (ftnlen)6);
	return 0;
    }
    if (vzero_(v)) {
	setmsg_("Zero vector for input velocity vector.", (ftnlen)38);
	sigerr_("SPICE(DEGENERATECASE)", (ftnlen)21);
	chkout_("OSCELT", (ftnlen)6);
	return 0;
    }
    rmag = vnorm_(r__);
    vmag = vnorm_(v);
    vcrss_(r__, v, h__);

/*     If the specific angular momentum vector is the zero vector, */
/*     we have a degenerate orbit and cannot proceed. */

    if (vzero_(h__)) {
	setmsg_("Input position and velocity are too close to parallel; the "
		"specific angular momentum vector is zero.", (ftnlen)100);
	sigerr_("SPICE(DEGENERATECASE)", (ftnlen)21);
	chkout_("OSCELT", (ftnlen)6);
	return 0;
    }
    d__1 = -h__[1];
    vpack_(&d__1, h__, &c_b16, n);
/* Computing 2nd power */
    d__2 = vmag;
    d__1 = d__2 * d__2 - *mu / rmag;
    d__3 = -vdot_(r__, v);
    vlcom_(&d__1, r__, &d__3, v, e);
    d__1 = 1. / *mu;
    vsclip_(&d__1, e);

/*     We begin by determining the size and shape of the orbit. */

/*     The eccentricity of the orbit is the magnitude of the */
/*     eccentricity vector. If the eccentricity is "close" to one, */
/*     go ahead and make this a parabola. */

/*     The perifocal distance depends on the eccentricity and the */
/*     semi-latus rectum, which in turn orbit depends only on the */
/*     specific angular momentum of the orbiting object. */

    d__1 = vnorm_(e);
    ecc = exact_(&d__1, &c_b17, &c_b18);
    p = vdot_(h__, h__) / *mu;
    rp = p / (ecc + 1.);

/*     Next, the orientation of the orbit. */
/*                                                       ^ */
/*     The inclination of the orbit is the angle between k (which is */
/*     perpendicular to the equator) and h (which is perpendicular to */
/*     the orbit.                        - */

/*     If close to zero or pi, make it exact. In either case, the node */
/*     vector becomes undefined. */

    inc = vsep_(h__, zvec);
    if ((d__1 = inc + 0., abs(d__1)) < 1e-10) {
	inc = 0.;
	vpack_(&c_b17, &c_b16, &c_b16, n);
    } else if ((d__1 = inc - pi_(), abs(d__1)) < 1e-10) {
	inc = pi_();
	vpack_(&c_b17, &c_b16, &c_b16, n);
    }

/*                                                              ^ */
/*     The longitude of the ascending node is the angle between i */
/*     (the x-axis) and the node vector, n. */
/*                                       - */

    lnode = atan2(n[1], n[0]);
    if (lnode < 0.) {
	lnode += twopi_();
    }

/*     The argument of periapsis is the angle between the node vector */
/*     n, and the eccentricity vector e. This is not defined for */
/*     -                              - */
/*     circular orbits. */


    if (ecc == 0.) {
	argp = 0.;
    } else {

/*        Set the magnitude of ARGP; we'll determine the sign next. */

	argp = vsep_(n, e);
	if (argp != 0.) {
	    if (inc == 0. || inc == pi_()) {

/*              The quadrant of ARGP is determined by the component of E */
/*              in the direction H x N. */

		ucrss_(h__, n, xprod);
		if (vdot_(e, xprod) < 0.) {
		    argp = twopi_() - argp;
		}
	    } else if (e[2] < 0.) {

/*              The periapsis is below the reference plane;  the argument */
/*              of periapsis must be greater than 180 degrees. */

		argp = twopi_() - argp;
	    }
	}
    }

/*     And finally, the position of the object within the orbit. */
/*     The true anomaly, nu, is the angle between the eccentricity */
/*     and radius vectors, e and r. (For circular orbits, substitute */
/*     n for e.)           -     - */
/*     -     - */

/*     This angle increases in the counterclockwise direction about h. */
/*     We express the position in the perifocal frame in order to */
/*     extract nu. */

    if (ecc == 0.) {

/*        In this case, the argument of periapse is set to zero, */
/*        so the nu is measured from N. */

	vhat_(n, perix);
    } else {
	vhat_(e, perix);
    }
    ucrss_(h__, perix, periy);
    nu = atan2(vdot_(r__, periy), vdot_(r__, perix));

/*     Unfortunately, the other element routines need the mean */
/*     anomaly, M. The true and mean anomalies are related through */
/*     the eccentric anomalies D (parabolas), E (ellipses), and */
/*     F (hyperbolas), as shown below. */

/*                      e + cos(nu) */
/*           cos(E)  = ---------------         (ellipse) */
/*                      1 + e cos(nu) */

/*           M       = E - e sin(E) */


/*                       e + cos(nu) */
/*           cosh(F) = ---------------         (hyperbola) */
/*                       1 + e cos(nu) */

/*           M       = e sinh(F) - F */


/*           D       = tan(nu/2)               (parabola) */

/*                           3 */
/*           M       =  D + D / 3 */

/*     For elliptic orbits, the mean anomaly should be in [0,2*pi]. */

    if (ecc < 1.) {

/*        For improved numerical performance, we compute both the */
/*        sine and cosine of the eccentric anomaly, then let ATAN2 */
/*        find the eccentric anomaly. */

	cosea = (ecc + cos(nu)) / (ecc * cos(nu) + 1.);

/*        Here we use the relationships (here b is the length */
/*        of the semi-minor axis): */

/*           a sin(E) = (a/b) r sin(nu) */

/*           sin(E)   = (r/b) sin(nu) */
/*                               ______________ */
/*                    = (r/rp) \/ (1-e) / (1+e)  sin(nu) */


	sinea = rmag / rp * sqrt((1. - ecc) / (ecc + 1.)) * sin(nu);
	ea = atan2(sinea, cosea);
	d__1 = ea - ecc * sin(ea);
	m0 = d_sign(&d__1, &nu);
	if (m0 < 0.) {
	    m0 += twopi_();
	}
    } else if (ecc > 1.) {
	coshf = (ecc + cos(nu)) / (ecc * cos(nu) + 1.);
	d__1 = max(1.,coshf);
	ea = dacosh_(&d__1);
	d__1 = ecc * sinh(ea) - ea;
	m0 = d_sign(&d__1, &nu);
    } else {
	ea = tan(nu / 2.);
/* Computing 3rd power */
	d__2 = ea;
	d__1 = ea + d__2 * (d__2 * d__2) / 3.;
	m0 = d_sign(&d__1, &nu);
    }

/*     Return the elements as a vector, suitable for input to CONICS. */

    elts[0] = rp;
    elts[1] = ecc;
    elts[2] = inc;
    elts[3] = lnode;
    elts[4] = argp;
    elts[5] = m0;
    elts[6] = *et;
    elts[7] = *mu;
    chkout_("OSCELT", (ftnlen)6);
    return 0;
} /* oscelt_ */

