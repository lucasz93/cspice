/* oscltx.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern oscltx_init_t __oscltx_init;
static inline oscltx_state_t* get_oscltx_state(cspice_t* state) {
	if (!state->oscltx)
		state->oscltx = __cspice_allocate_module(sizeof(
	oscltx_state_t), &__oscltx_init, sizeof(__oscltx_init));
	return state->oscltx;

}

/* $Procedure  OSCLTX ( Extended osculating elements from state ) */
/* Subroutine */ int oscltx_(cspice_t* __global_state, doublereal *state, 
	doublereal *et, doublereal *mu, doublereal *elts)
{
    /* Initialized data */


    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double pow_dd(f2c_state_t*, doublereal *, doublereal *);

    /* Local variables */
    doublereal rmag;
    doublereal vmag;
    doublereal rhat[3];
    doublereal pole[3];
    doublereal xmat[9]	/* was [3][3] */;
    extern doublereal vdot_(cspice_t*, doublereal *, doublereal *);
    extern /* Subroutine */ int vequ_(cspice_t*, doublereal *, doublereal *);
    doublereal a;
    doublereal b;
    doublereal e;
    doublereal range;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern doublereal exact_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    extern doublereal dpmax_(cspice_t*);
    doublereal rperi[3];
    extern /* Subroutine */ int vlcom_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    doublereal c1;
    doublereal c2;
    extern /* Subroutine */ int ucrss_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    extern /* Subroutine */ int unorm_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    extern doublereal vnorm_(cspice_t*, doublereal *);
    extern doublereal twopi_(cspice_t*);
    extern logical failed_(cspice_t*);
    doublereal eccvec[3];
    extern /* Subroutine */ int cleard_(cspice_t*, integer *, doublereal *);
    extern /* Subroutine */ int recrad_(cspice_t*, doublereal *, doublereal *,
	     doublereal *, doublereal *);
    doublereal nu;
    logical cmptau;
    extern /* Subroutine */ int oscelt_(cspice_t*, doublereal *, doublereal *,
	     doublereal *, doublereal *);
    doublereal mucubr;
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int twovec_(cspice_t*, doublereal *, integer *, 
	    doublereal *, integer *, doublereal *);
    extern logical return_(cspice_t*);
    doublereal ecc;
    doublereal dec;
    doublereal vel[3];
    doublereal tau;
    extern /* Subroutine */ int mxv_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);


    /* Module state */
    oscltx_state_t* __state = get_oscltx_state(__global_state);
/* $ Abstract */

/*     Determine the set of osculating conic orbital elements that */
/*     corresponds to the state (position, velocity) of a body at some */
/*     epoch. In additional to the classical elements, return the true */
/*     anomaly, semi-major axis, and period, if applicable. */

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
/*     ELEMENTS */
/*     EPHEMERIS */

/* $ Declarations */

/*     Include file oscltx.inc */

/* $ Abstract */

/*     This file declares public parameters related to */
/*     the SPICELIB routine OSCLTX. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 25-JAN-2017 (NJB) */

/* -& */

/*     Size of the OSCLTX output argument array ELTS. */

/*     The output array ELTS is intended to contain unused space to hold */
/*     additional elements that may be added in a later version of this */
/*     routine. In order to maintain forward compatibility, user */
/*     applications should declare ELTS as follows: */

/*     DOUBLE PRECISION   ELTS( OSCXSZ ) */


/*     End of include file oscltx.inc */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     STATE      I   State of body at epoch of elements. */
/*     ET         I   Epoch of elements. */
/*     MU         I   Gravitational parameter (GM) of primary body. */
/*     ELTS       O   Extended set of classical conic elements. */

/* $ Detailed_Input */

/*     STATE      is the state (position and velocity) of the body */
/*                at some epoch. Components are x, y, z, dx/dt, dy/dt, */
/*                dz/dt. STATE must be expressed relative to an */
/*                inertial reference frame. Units are km and km/sec. */


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
/*                    NU      True anomaly at epoch. */
/*                    A       Semi-major axis. A is set to zero if */
/*                            it is not computable. */
/*                    TAU     Orbital period. Applicable only for */
/*                            elliptical orbits. Set to zero otherwise. */

/*                 The epoch of the elements is the epoch of the input */
/*                 state. Units are km, rad, rad/sec. The same elements */
/*                 are used to describe all three types (elliptic, */
/*                 hyperbolic, and parabolic) of conic orbit. */

/*                 User applications should declare ELTS using the */
/*                 parameter */

/*                    OSCXSZ */

/*                 See the Parameters section below. */


/* $ Parameters */

/*     OSCXSZ      is the size of the output elements array ELTS. OSCXSZ */
/*                 is declared in the Fortran include file */

/*                    oscltx.inc */

/*                 The output array ELTS is intended to contain unused */
/*                 space to hold additional elements that may be added */
/*                 in a later version of this routine. In order to */
/*                 maintain forward compatibility, user applications */
/*                 should declare ELTS as follows: */

/*                    DOUBLE PRECISION   ELTS( OSCXSZ ) */


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

/*     6) If the eccentricity of the orbit is very close to but not */
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

/*    11) The semi-major axis and period may not be computable for */
/*        orbits having eccentricity too close to 1. If the semi-major */
/*        axis is not computable, both it and the period are set to zero. */
/*        If the period is not computable, it is set to zero. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine returns in the first 8 elements of the array ELTS */
/*     the outputs computed by OSCELT, and in addition returns in */
/*     elements 9-11 the quantities: */

/*        ELTS(9)   true anomaly at ET, in radians. */

/*        ELTS(10)  orbital semi-major axis at ET, in km. Valid */
/*                  if and only if this value is non-zero. */

/*                  The semi-major axis won't be computable if the */
/*                  eccentricity of the orbit is too close to 1. */
/*                  In this case A is set to zero. */

/*        ELTS(11)  orbital period. If the period is not computable, */
/*                  TAU is set to zero. */

/*     The SPICELIB routine CONICS is an approximate inverse of this */
/*     routine: CONICS maps a set of osculating elements and a time to a */
/*     state vector. */

/* $ Examples */

/*     Let VINIT contain the initial state of a spacecraft relative to */
/*     the center of a planet at epoch ET, and let GM be the gravitation */
/*     parameter of the planet. The call */

/*        CALL OSCLTX ( VINIT, ET, GM, ELTS ) */

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
/*             not equal to 1. In general, any inputs that cause */
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

/* -    SPICELIB Version 1.0.0, 02-FEB-2017 (NJB) */

/*        12-MAR-2015 (NJB) */

/*           Re-arranged test for small E to avoid overflow. */
/*           Changed definition of B to make the maximum value */
/*           of TAU equal to LIMIT. Removed test comparing */
/*           E/LIMIT to RMAG. */

/*        11-NOV-2014 (NJB) */

/*           Original version. Based on OSCELT version 1.3.1, */
/*           28-FEB-2008 */

/* -& */
/* $ Index_Entries */

/*     extended conic elements from state */
/*     extended osculating elements from state */
/*     convert state to extended osculating elements */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "OSCLTX", (ftnlen)6);
    if (__state->pass1) {
	__state->limit = dpmax_(__global_state) / 200.;
	__state->pass1 = FALSE_;
    }

/*     Initialize the members of ELTS that won't be set by OSCELT. This */
/*     is necessary because this routine may return early if A or TAU */
/*     cannot be computed. */

    cleard_(__global_state, &__state->c__12, &elts[8]);
    nu = 0.;
    tau = 0.;
    a = 0.;

/*     Compute osculating elements using OSCELT. Take advantage */
/*     of OSCELT's error handling. */

    oscelt_(__global_state, state, et, mu, elts);
    if (failed_(__global_state)) {
	chkout_(__global_state, "OSCLTX", (ftnlen)6);
	return 0;
    }

/*     Due to checks made by OSCELT, we know that MU and RMAG */
/*     are strictly positive. */


/*     Compute the true anomaly at ET. For the non-degenerate case, we */
/*     use equation 2.4-5 from [1] to compute the eccentricity vector: */

/*        _    1          2   mu    _     _  _  _ */
/*        e = ---- * [ ( v - ---- ) r  - <r, v> v ]                   (1) */
/*             mu             r */


/*     where */

/*        _ */
/*        e      is the eccentricity vector */

/*        _  _ */
/*        r, v   are, respectively, the object's position and */
/*               velocity vectors expressed in the inertial */
/*               reference frame of the input state. */
/*                                                    _     _ */
/*        r, v   are, respectively, the magnitudes of r and v */

/*        mu     is the GM value of the center of motion */



    unorm_(__global_state, state, rhat, &rmag);
    vequ_(__global_state, &state[3], vel);
    vmag = vnorm_(__global_state, vel);
    ecc = exact_(__global_state, &elts[1], &__state->c_b5, &__state->c_b6);
    if (ecc != 0.) {
/*                                 _   _ */
/*        C1 is the coefficient of r/||r|| in (1) above: */

/* Computing 2nd power */
	d__1 = vmag;
	c1 = 1. / *mu * (rmag * (d__1 * d__1) - *mu);
/*                                 _ */
/*        C2 is the coefficient of v in (1) above: */

	c2 = -(1. / *mu) * vdot_(__global_state, state, vel);

/*        ECCVEC is the eccentricity vector: */

	vlcom_(__global_state, &c1, rhat, &c2, vel, eccvec);

/*        POLE is the orbital pole unit vector. */

	ucrss_(__global_state, state, vel, pole);

/*        Compute the transformation from the frame of the input state */
/*        to the perifocal frame. */

	twovec_(__global_state, eccvec, &__state->c__1, pole, &__state->c__3, 
		xmat);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "OSCLTX", (ftnlen)6);
	    return 0;
	}

/*        Transform the input position to the perifocal frame and */
/*        compute its "right ascension." This is the true anomaly NU, */
/*        confined to the range [0, 2*pi) radians. */

	mxv_(__global_state, xmat, state, rperi);
	recrad_(__global_state, rperi, &range, &nu, &dec);
    } else {

/*        The orbit is circular or nearly so. The mean anomaly can */
/*        be used as the true anomaly. */

	nu = elts[5];
    }
    elts[8] = nu;

/*     The semi-major axis A satisfies the relationship */

/*                mu */
/*        E =  - ----                                                 (2) */
/*                2A */

/*     where E represents the specific energy of the orbit, as long */
/*     as A is computable. */

/*     If the orbit is not parabolic or too close to parabolic, */
/*     we can recover A from (2) above: */

/*                mu */
/*        A =  - ---- */
/*                2E */

/*     To make sure that A is computable, we require */



/*        |mu/E| < LIMIT */

/*     so */

/*        |mu/LIMIT| < |E| */

/*     We compute E from the specific kinetic and potential */
/*     energy of the orbit: */

/*               2 */
/*              v     mu */
/*        E =  --- - ----                                             (3) */
/*              2     r */

/*     The second term on the right hand side is computable if */

/*        mu/LIMIT < r */


    if (elts[1] == 1.) {

/*        This is the parabolic case. */

	chkout_(__global_state, "OSCLTX", (ftnlen)6);
	return 0;
    }
    if (rmag <= *mu / __state->limit) {

/*        We need RMAG > MU/LIMIT to make E computable. */

/*        We can't safely compute E. */

	chkout_(__global_state, "OSCLTX", (ftnlen)6);
	return 0;
    }

/*     We assume V and MU are small enough not to cause overflow. */

/* Computing 2nd power */
    d__1 = vmag;
    e = d__1 * d__1 * .5 - *mu / rmag;
    if (abs(e) < abs(*mu) / __state->limit) {

/*        We can't safely compute A. The case of E equal to 0 */
/*        gets the code to this point. */

	chkout_(__global_state, "OSCLTX", (ftnlen)6);
	return 0;
    }

/*     At this point we can compute A (which is stored in ELTS(10)). */

    a = -(*mu) / (e * 2);
    elts[9] = a;

/*     If the orbit is elliptical, compute the period. */

    ecc = elts[1];
    if (ecc < 1.) {

/*        The period is given by the formula */

/*                             3       1/2 */
/*           tau = 2 * pi * ( a  / mu ) */

/*        We need to make sure this computation doesn't */
/*        overflow. */

/*        If mu >= 1 then we can express the constraint */
/*        on a as */

/*                   1/3                         2/3 */
/*           ( a / mu    )  <  ( LIMIT / (2*pi) ) */


/*        Otherwise, we require that */

/*                                 2/3     1/3 */
/*           a < ( LIMIT / (2*pi) )    * mu */



/*        Note that the case of non-positive MU has already */
/*        been ruled out. */

	d__1 = __state->limit / twopi_(__global_state);
	b = pow_dd(&__global_state->f2c, &d__1, &__state->c_b13);
	mucubr = pow_dd(&__global_state->f2c, mu, &__state->c_b14);
	if (*mu >= 1.) {
	    cmptau = a / mucubr < b;
	} else {
	    cmptau = a < b * mucubr;
	}
	if (cmptau) {
	    d__1 = a / mucubr;
	    tau = twopi_(__global_state) * pow_dd(&__global_state->f2c, &d__1,
		     &__state->c_b15);
	}
    }

/*     Assign the remaining members of ELTS. */

    elts[10] = tau;
    chkout_(__global_state, "OSCLTX", (ftnlen)6);
    return 0;
} /* oscltx_ */

