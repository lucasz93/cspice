/* zzstelab.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzstelab_init_t __zzstelab_init;
static zzstelab_state_t* get_zzstelab_state(cspice_t* state) {
	if (!state->zzstelab)
		state->zzstelab = __cspice_allocate_module(sizeof(
	zzstelab_state_t), &__zzstelab_init, sizeof(__zzstelab_init));
	return state->zzstelab;

}

/* $Procedure ZZSTELAB ( Private --- stellar aberration correction ) */
/* Subroutine */ int zzstelab_(cspice_t* __global_state, logical *xmit, 
	doublereal *accobs, doublereal *vobs, doublereal *starg, doublereal *
	scorr, doublereal *dscorr)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);

    /* Local variables */
    extern /* Subroutine */ int vadd_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    doublereal dphi;
    doublereal rhat[3];
    extern /* Subroutine */ int vhat_(cspice_t*, doublereal *, doublereal *);
    extern doublereal vdot_(cspice_t*, doublereal *, doublereal *);
    extern /* Subroutine */ int vequ_(cspice_t*, doublereal *, doublereal *);
    doublereal term1[3];
    doublereal term2[3];
    doublereal term3[3];
    doublereal c__;
    doublereal lcacc[3];
    integer i__;
    doublereal s;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    doublereal saoff[6]	/* was [3][2] */;
    doublereal drhat[3];
    extern /* Subroutine */ int dvhat_(cspice_t*, doublereal *, doublereal *);
    doublereal ptarg[3];
    doublereal evobs[3];
    doublereal srhat[6];
    doublereal vphat[3];
    doublereal vtarg[3];
    extern /* Subroutine */ int vlcom_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    extern /* Subroutine */ int vperp_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    extern doublereal vnorm_(cspice_t*, doublereal *);
    extern logical vzero_(cspice_t*, doublereal *);
    extern /* Subroutine */ int vlcom3_(cspice_t*, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *);
    extern /* Subroutine */ int cleard_(cspice_t*, integer *, doublereal *);
    doublereal vp[3];
    extern doublereal clight_(cspice_t*);
    doublereal dptmag;
    doublereal ptgmag;
    doublereal eptarg[3];
    doublereal dvphat[3];
    doublereal lcvobs[3];
    extern /* Subroutine */ int qderiv_(cspice_t*, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    doublereal svphat[6];
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int vminus_(cspice_t*, doublereal *, doublereal *)
	    ;
    doublereal sgn;
    doublereal dvp[3];
    doublereal svp[6];


    /* Module state */
    zzstelab_state_t* __state = get_zzstelab_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Return the state (position and velocity) of a target body */
/*     relative to an observing body, optionally corrected for light */
/*     time (planetary aberration) and stellar aberration. */

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
/*     XMIT       I   Reception/transmission flag. */
/*     ACCOBS     I   Observer acceleration relative to SSB. */
/*     VOBS       I   Observer velocity relative to to SSB. */
/*     STARG      I   State of target relative to observer. */
/*     SCORR      O   Stellar aberration correction for position. */
/*     DSCORR     O   Stellar aberration correction for velocity. */

/* $ Detailed_Input */

/*     XMIT        is a logical flag which is set to .TRUE. for the */
/*                 "transmission" case in which photons *depart* from */
/*                 the observer's location at an observation epoch ET */
/*                 and arrive at the target's location at the light-time */
/*                 corrected epoch ET+LT, where LT is the one-way light */
/*                 time between observer and target; XMIT is set to */
/*                 .FALSE. for "reception" case in which photons depart */
/*                 from the target's location at the light-time */
/*                 corrected epoch ET-LT and *arrive* at the observer's */
/*                 location at ET. */

/*                 Note that the observation epoch is not used in this */
/*                 routine. */

/*                 XMIT must be consistent with any light time */
/*                 corrections used for the input state STARG: if that */
/*                 state has been corrected for "reception" light time; */
/*                 XMIT must be .FALSE.; otherwise XMIT must be .TRUE. */

/*     ACCOBS      is the geometric acceleration of the observer */
/*                 relative to the solar system barycenter. Units are */
/*                 km/sec**2. ACCOBS must be expressed relative to */
/*                 an inertial reference frame. */

/*     VOBS        is the geometric velocity of the observer relative to */
/*                 the solar system barycenter. VOBS must be expressed */
/*                 relative to the same inertial reference frame as */
/*                 ACCOBS. Units are km/sec. */

/*     STARG       is the Cartesian state of the target relative to the */
/*                 observer. Normally STARG has been corrected for */
/*                 one-way light time, but this is not required. STARG */
/*                 must be expressed relative to the same inertial */
/*                 reference frame as ACCOBS. Components are */
/*                 (x, y, z, dx, dy, dz). Units are km and km/sec. */

/* $ Detailed_Output */

/*     SCORR       is the stellar aberration correction for the position */
/*                 component of STARG. Adding SCORR to this position */
/*                 vector produces the input observer-target position, */
/*                 corrected for stellar aberration. */

/*                 The reference frame of SCORR is the common frame */
/*                 relative to which the inputs ACCOBS, VOBS, and STARG */
/*                 are expressed. Units are km. */

/*     DSCORR      is the stellar aberration correction for the velocity */
/*                 component of STARG. Adding DSCORR to this velocity */
/*                 vector produces the input observer-target velocity, */
/*                 corrected for stellar aberration. */

/*                 The reference frame of DSCORR is the common frame */
/*                 relative to which the inputs ACCOBS, VOBS, and STARG */
/*                 are expressed. Units are km/s. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If attempt to divide by zero occurs, the error */
/*        SPICE(DIVIDEBYZERO) will be signaled. This case may occur */
/*        due to uninitialized inputs. */

/*     2) Loss of precision will occur for geometric cases in which */
/*        VOBS is nearly parallel to the position component of STARG. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine computes a Newtonian estimate of the stellar */
/*     aberration correction of an input state. Normally the input state */
/*     has already been corrected for one-way light time. */

/*     Since stellar aberration corrections are typically "small" */
/*     relative to the magnitude of the input observer-target position */
/*     and velocity, this routine avoids loss of precision by returning */
/*     the corrections themselves rather than the corrected state */
/*     vector. This allows the caller to manipulate (for example, */
/*     interpolate) the corrections with greater accuracy. */

/* $ Examples */

/*     See SPICELIB routine SPKACS. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     SPK Required Reading. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 15-APR-2014 (NJB) */

/*        Added RETURN test and discovery check-in. */
/*        Check for division by zero was added. This */
/*        case might occur due to uninitialized inputs. */

/* -    SPICELIB Version 1.0.1, 12-FEB-2009 (NJB) */

/*        Minor updates were made to the inline documentation. */

/* -    SPICELIB Version 1.0.0, 17-JAN-2008 (NJB) */

/* -& */

/*     Note for the maintenance programmer */
/*     =================================== */

/*     The source code of the test utility T_ZZSTLABN must be */
/*     kept in sync with the source code of this routine. That */
/*     routine uses a value of SEPLIM that forces the numeric */
/*     branch of the velocity computation to be taken in all */
/*     cases. See the documentation of that routine for details. */


/*     SPICELIB functions */


/*     Local parameters */


/*     Let PHI be the (non-negative) rotation angle of the stellar */
/*     aberration correction; then SEPLIM is a limit on how close PHI */
/*     may be to zero radians while stellar aberration velocity is */
/*     computed analytically. When sin(PHI) is less than SEPLIM, the */
/*     velocity must be computed numerically. */


/*     Let TDELTA be the time interval, measured in seconds, */
/*     used for numerical differentiation of the stellar */
/*     aberration correction, when this is necessary. */


/*     Local variables */


/*     Use discovery check-in. */

    if (return_(__global_state)) {
	return 0;
    }

/*     In the discussion below, the dot product of vectors X and Y */
/*     is denoted by */

/*        <X,Y> */

/*     The speed of light is denoted by the lower case letter "c." BTW, */
/*     variable names used here are case-sensitive: upper case "C" */
/*     represents a different quantity which is unrelated to the speed */
/*     of light. */

/*     Variable names ending in "HAT" denote unit vectors. Variable */
/*     names starting with "D" denote derivatives with respect to time. */

/*     We'll compute the correction SCORR and its derivative with */
/*     respect to time DSCORR for the reception case. In the */
/*     transmission case, we perform the same computation with the */
/*     negatives of the observer velocity and acceleration. */

/*     In the code below, we'll store the position and velocity portions */
/*     of the input observer-target state STARG in the variables PTARG */
/*     and VTARG, respectively. */

/*     Let VP be the component of VOBS orthogonal to PTARG. VP */
/*     is defined as */

/*         VOBS - < VOBS, RHAT > RHAT                                 (1) */

/*     where RHAT is the unit vector */

/*         PTARG/||PTARG|| */

/*     Then */

/*        ||VP||/c                                                    (2) */

/*     is the magnitude of */

/*        s = sin( phi )                                              (3) */

/*     where phi is the stellar aberration correction angle. We'll */
/*     need the derivative with respect to time of (2). */

/*     Differentiating (1) with respect to time yields the */
/*     velocity DVP, where, letting */

/*        DRHAT  =  d(RHAT) / dt */
/*        VPHAT  =  VP      / ||VP|| */
/*        DVPMAG =  d( ||VP|| ) / dt */

/*     we have */

/*        DVP = d(VP)/dt */

/*            = ACCOBS - (  ( <VOBS,DRHAT> + <ACCOBS, RHAT> )*RHAT */
/*                        +   <VOBS,RHAT>  * DRHAT                 )  (4) */

/*     and */

/*        DVPMAG = < DVP, VPHAT >                                     (5) */

/*     Now we can find the derivative with respect to time of */
/*     the stellar aberration angle phi: */

/*        ds/dt = d(sin(phi))/dt = d(phi)/dt * cos(phi)               (6) */

/*     Using (2) and (5), we have for positive phi, */

/*        ds/dt = (1/c)*DVPMAG = (1/c)*<DVP, VPHAT>                   (7) */

/*     Then for positive phi */

/*        d(phi)/dt = (1/cos(phi)) * (1/c) * <DVP, VPHAT>             (8) */

/*     Equation (8) is well-defined as along as VP is non-zero: */
/*     if VP is the zero vector, VPHAT is undefined. We'll treat */
/*     the singular and near-singular cases separately. */

/*     The aberration correction itself is a rotation by angle phi */
/*     from RHAT towards VP, so the corrected vector is */

/*        ( sin(phi)*VPHAT + cos(phi)*RHAT ) * ||PTARG|| */

/*     and  we can express the offset of the corrected vector from */
/*     PTARG, which is the output SCORR, as */

/*        SCORR = */

/*        ( sin(phi)*VPHAT + (cos(phi)-1)*RHAT ) * ||PTARG||          (9) */

/*     Let DPTMAG be defined as */

/*        DPTMAG  =  d ( ||PTARG|| ) / dt                            (10) */

/*     Then the derivative with respect to time of SCORR is */

/*        DSCORR = */

/*             (      sin(phi)*DVPHAT */

/*                +   cos(phi)*d(phi)/dt * VPHAT */

/*                +  (cos(phi) - 1) * DRHAT */

/*                +  ( -sin(phi)*d(phi)/dt ) * RHAT   ) * ||PTARG|| */

/*           + ( sin(phi)*VPHAT + (cos(phi)-1)*RHAT ) * DPTMAG       (11) */


/*     Computations begin here: */

/*     Split STARG into position and velocity components. Compute */

/*        RHAT */
/*        DRHAT */
/*        VP */
/*        DPTMAG */

    if (*xmit) {
	vminus_(__global_state, vobs, lcvobs);
	vminus_(__global_state, accobs, lcacc);
    } else {
	vequ_(__global_state, vobs, lcvobs);
	vequ_(__global_state, accobs, lcacc);
    }
    vequ_(__global_state, starg, ptarg);
    vequ_(__global_state, &starg[3], vtarg);
    dvhat_(__global_state, starg, srhat);
    vequ_(__global_state, srhat, rhat);
    vequ_(__global_state, &srhat[3], drhat);
    vperp_(__global_state, lcvobs, rhat, vp);
    dptmag = vdot_(__global_state, vtarg, rhat);

/*     Compute sin(phi) and cos(phi), which we'll call S and C */
/*     respectively. Note that phi is always close to zero for */
/*     realistic inputs (for which ||VOBS|| << CLIGHT), so the */
/*     cosine term is positive. */

    s = vnorm_(__global_state, vp) / clight_(__global_state);
/* Computing MAX */
    d__1 = 0., d__2 = 1 - s * s;
    c__ = sqrt((max(d__1,d__2)));
    if (c__ == 0.) {

/*        C will be used as a divisor later (in the computation */
/*        of DPHI), so we'll put a stop to the problem here. */

	chkin_(__global_state, "ZZSTELAB", (ftnlen)8);
	setmsg_(__global_state, "Cosine of the aberration angle is 0; this c"
		"annot occur for realistic observer velocities. This case can"
		" arise due to uninitialized inputs. This cosine value is use"
		"d as a divisor in a later computation, so it must not be equ"
		"al to zero.", (ftnlen)234);
	sigerr_(__global_state, "SPICE(DIVIDEBYZERO)", (ftnlen)19);
	chkout_(__global_state, "ZZSTELAB", (ftnlen)8);
	return 0;
    }

/*     Compute the unit vector VPHAT and the stellar */
/*     aberration correction. We avoid relying on */
/*     VHAT's exception handling for the zero vector. */

    if (vzero_(__global_state, vp)) {
	cleard_(__global_state, &__state->c__3, vphat);
    } else {
	vhat_(__global_state, vp, vphat);
    }

/*     Now we can use equation (9) to obtain the stellar */
/*     aberration correction SCORR: */

/*        SCORR = */

/*           ( sin(phi)*VPHAT + (cos(phi)-1)*RHAT ) * ||PTARG|| */


    ptgmag = vnorm_(__global_state, ptarg);
    d__1 = ptgmag * s;
    d__2 = ptgmag * (c__ - 1.);
    vlcom_(__global_state, &d__1, vphat, &d__2, rhat, scorr);

/*     Now we use S as an estimate of PHI to decide if we're */
/*     going to differentiate the stellar aberration correction */
/*     analytically or numerically. */

/*     Note that S is non-negative by construction, so we don't */
/*     need to use the absolute value of S here. */

    if (s >= 1e-6) {

/*        This is the analytic case. */

/*        Compute DVP---the derivative of VP with respect to time. */
/*        Recall equation (4): */

/*        DVP = d(VP)/dt */

/*            = ACCOBS - (  ( <VOBS,DRHAT> + <ACCOBS, RHAT> )*RHAT */
/*                        +   <VOBS,RHAT>  * DRHAT                 ) */

	d__1 = -vdot_(__global_state, lcvobs, drhat) - vdot_(__global_state, 
		lcacc, rhat);
	d__2 = -vdot_(__global_state, lcvobs, rhat);
	vlcom3_(__global_state, &__state->c_b7, lcacc, &d__1, rhat, &d__2, 
		drhat, dvp);
	vhat_(__global_state, vp, vphat);

/*        Now we can compute DVPHAT, the derivative of VPHAT: */

	vequ_(__global_state, vp, svp);
	vequ_(__global_state, dvp, &svp[3]);
	dvhat_(__global_state, svp, svphat);
	vequ_(__global_state, &svphat[3], dvphat);

/*        Compute the DPHI, the time derivative of PHI, using equation 8: */

/*           d(phi)/dt = (1/cos(phi)) * (1/c) * <DVP, VPHAT> */


	dphi = 1. / (c__ * clight_(__global_state)) * vdot_(__global_state, 
		dvp, vphat);

/*        At long last we've assembled all of the "ingredients" required */
/*        to compute DSCORR: */

/*           DSCORR = */

/*             (     sin(phi)*DVPHAT */

/*                +  cos(phi)*d(phi)/dt * VPHAT */

/*                +  (cos(phi) - 1) * DRHAT */

/*                +  ( -sin(phi)*d(phi)/dt ) * RHAT   ) * ||PTARG|| */

/*                +  ( sin(phi)*VPHAT + (cos(phi)-1)*RHAT ) * DPTMAG */


	d__1 = c__ * dphi;
	vlcom_(__global_state, &s, dvphat, &d__1, vphat, term1);
	d__1 = c__ - 1.;
	d__2 = -s * dphi;
	vlcom_(__global_state, &d__1, drhat, &d__2, rhat, term2);
	vadd_(__global_state, term1, term2, term3);
	d__1 = dptmag * s;
	d__2 = dptmag * (c__ - 1.);
	vlcom3_(__global_state, &ptgmag, term3, &d__1, vphat, &d__2, rhat, 
		dscorr);
    } else {

/*        This is the numeric case. We're going to differentiate */
/*        the stellar aberration correction offset vector using */
/*        a quadratic estimate. */

	for (i__ = 1; i__ <= 2; ++i__) {

/*           Set the sign of the time offset. */

	    if (i__ == 1) {
		sgn = -1.;
	    } else {
		sgn = 1.;
	    }

/*           Estimate the observer's velocity relative to the */
/*           solar system barycenter at the current epoch. We use */
/*           the local copies of the input velocity and acceleration */
/*           to make a linear estimate. */

	    d__1 = sgn * 1.;
	    vlcom_(__global_state, &__state->c_b7, lcvobs, &d__1, lcacc, 
		    evobs);

/*           Estimate the observer-target vector. We use the */
/*           observer-target state velocity to make a linear estimate. */

	    d__1 = sgn * 1.;
	    vlcom_(__global_state, &__state->c_b7, starg, &d__1, &starg[3], 
		    eptarg);

/*           Let RHAT be the unit observer-target position. */
/*           Compute the component of the observer's velocity */
/*           that is perpendicular to the target position; call */
/*           this vector VP. Also compute the unit vector in */
/*           the direction of VP. */

	    vhat_(__global_state, eptarg, rhat);
	    vperp_(__global_state, evobs, rhat, vp);
	    if (vzero_(__global_state, vp)) {
		cleard_(__global_state, &__state->c__3, vphat);
	    } else {
		vhat_(__global_state, vp, vphat);
	    }

/*           Compute the sine and cosine of the correction */
/*           angle. */

	    s = vnorm_(__global_state, vp) / clight_(__global_state);
/* Computing MAX */
	    d__1 = 0., d__2 = 1 - s * s;
	    c__ = sqrt((max(d__1,d__2)));

/*           Compute the vector offset of the correction. */

	    ptgmag = vnorm_(__global_state, eptarg);
	    d__1 = ptgmag * s;
	    d__2 = ptgmag * (c__ - 1.);
	    vlcom_(__global_state, &d__1, vphat, &d__2, rhat, &saoff[(i__1 = 
		    i__ * 3 - 3) < 6 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "saoff", i__1, "zzstelab_", (ftnlen)
		    597)]);
	}

/*        Now compute the derivative. */

	qderiv_(__global_state, &__state->c__3, saoff, &saoff[3], &
		__state->c_b7, dscorr);
    }

/*     At this point the correction offset SCORR and its derivative */
/*     with respect to time DSCORR are both set. */

    return 0;
} /* zzstelab_ */

