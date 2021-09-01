/* zznrmlon.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zznrmlon_init_t __zznrmlon_init;
static zznrmlon_state_t* get_zznrmlon_state(cspice_t* state) {
	if (!state->zznrmlon)
		state->zznrmlon = __cspice_allocate_module(sizeof(
	zznrmlon_state_t), &__zznrmlon_init, sizeof(__zznrmlon_init));
	return state->zznrmlon;

}

/* $Procedure ZZNRMLON ( Normalize longitude bounds ) */
/* Subroutine */ int zznrmlon_(cspice_t* __global_state, doublereal *inmin, 
	doublereal *inmax, doublereal *tol, doublereal *outmin, doublereal *
	outmax)
{
    /* Initialized data */


    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Local variables */
    doublereal delta;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    extern doublereal twopi_(cspice_t*);
    extern doublereal touchd_(cspice_t*, doublereal *);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern doublereal dpr_(cspice_t*);


    /* Module state */
    zznrmlon_state_t* __state = get_zznrmlon_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due to the */
/*     volatile nature of this routine. */

/*     Normalize longitude bounds: map bounds into the interval */

/*        [ -2*pi, 2*pi ] */

/*     Put the bounds in order and ensure that the bounds differ by no */
/*     more than 2*pi. */

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
/*     LONGITUDE */
/*     MATH */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     INMIN      I   Longitude interval lower bound. */
/*     INMAX      I   Longitude interval upper bound. */
/*     TOL        I   Round-off tolerance. */
/*     OUTMIN     O   Adjusted longitude interval lower bound. */
/*     OUTMAX     O   Adjusted longitude interval upper bound. */

/* $ Detailed_Input */

/*     INMIN, */
/*     INMAX      are, respectively, the lower and upper */
/*                bounds of a longitude interval. Units are */
/*                radians. INMIN and INMAX must lie in the range */

/*                   [-2*pi, 2pi] */

/*                INMAX is allowed to be less than INMIN, but must */
/*                not be equal to it. */


/*     TOL        is a non-negative tolerance value. If an input bound */
/*                lies outside of the range */

/*                   [-2*pi, 2pi] */

/*                by less than TOL, it is interpreted as being equal */
/*                to the nearest interval endpoint. */

/*                If INMAX exceeds INMIN by less than TOL, the bounds */
/*                are interpreted as being 2*pi radians apart. */


/* $ Detailed_Output */

/*     OUTMIN, */
/*     OUTMAX     are, respectively, the normalized lower and upper */
/*                bounds of the longitude interval described by the */
/*                inputs. Units are radians. */

/*                "Normalization" means the bounds are modified if */
/*                necessary so that they represent the same interval */
/*                as [INMIN, INMAX], but also meet the following */
/*                criteria: */

/*                   1) Both OUTMIN and OUTMAX lie in the interval */
/*                      [-2*pi, 2*pi]. */

/*                   2) OUTMIN is strictly less than OUTMAX. */

/*                   3) OUTMAX does not exceed OUTMIN by more than 2*pi. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If TOL is negative, the error SPICE(VALUEOUTOFRANGE) */
/*         is signaled. */

/*     2)  If either input longitude is less than 2*pi-TOL or */
/*         greater than 2*pi + TOL, the error SPICE(VALUEOUTOFRANGE) */
/*         is signaled. */

/*     3)  If INMAX equals INMIN, or if INMAX is less than INMIN */
/*         by an integer multiple of 2*pi, the error */
/*         SPICE(ZEROBOUNDSEXTENT) is signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine centralizes an oft-repeated algorithm. It is */
/*     called by several DSK routines. */

/* $ Examples */

/*     See usage in ZZINLAT. */

/* $ Restrictions */

/*     This is a private routine. It is meant to be used only by SPICE */
/*     routines. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 11-OCT-2016 (NJB) */

/*        Original version 16-MAY-2016 (NJB) */

/* -& */
/* $ Index_Entries */

/*     normalize longitude interval */
/*     normalize longitude boundaries */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Saved values */


/*     Initial values */


/*     Use discovery check-in. Don't check RETURN. */

    if (__state->first) {
	__state->pi2 = twopi_(__global_state);
	__state->first = FALSE_;
    }

/*     TOL cannot be negative. */

    if (*tol < 0.) {
	chkin_(__global_state, "ZZNRMLON", (ftnlen)8);
	setmsg_(__global_state, "Tolerance must be non-negative but was #.", (
		ftnlen)41);
	errdp_(__global_state, "#", tol, (ftnlen)1);
	sigerr_(__global_state, "SPICE(VALUEOUTOFRANGE)", (ftnlen)22);
	chkout_(__global_state, "ZZNRMLON", (ftnlen)8);
	return 0;
    }

/*     Reject inputs that lie outside of [-2*pi, 2*pi], accounting */
/*     for the tolerance. */

    if (*inmin < -__state->pi2 - *tol || *inmin > __state->pi2 + *tol) {
	chkin_(__global_state, "ZZNRMLON", (ftnlen)8);
	setmsg_(__global_state, "Longitude lower bound INMIN = # (radians), "
		" = # (deg). The minimum allowed value is  -2*pi - TOL = # (r"
		"adians), = # (deg).", (ftnlen)122);
	errdp_(__global_state, "#", inmin, (ftnlen)1);
	d__1 = *inmin * dpr_(__global_state);
	errdp_(__global_state, "#", &d__1, (ftnlen)1);
	d__1 = -__state->pi2 - *tol;
	errdp_(__global_state, "#", &d__1, (ftnlen)1);
	d__1 = (-__state->pi2 - *tol) * dpr_(__global_state);
	errdp_(__global_state, "#", &d__1, (ftnlen)1);
	sigerr_(__global_state, "SPICE(VALUEOUTOFRANGE)", (ftnlen)22);
	chkout_(__global_state, "ZZNRMLON", (ftnlen)8);
	return 0;
    }

/*     The input bounds may not be equal. */

    if (*inmin == *inmax) {
	chkin_(__global_state, "ZZNRMLON", (ftnlen)8);
	setmsg_(__global_state, "Longitude lower bound INMIN = # (radians), "
		" = # (deg), is equal to upper bound.", (ftnlen)79);
	errdp_(__global_state, "#", inmin, (ftnlen)1);
	d__1 = *inmin * dpr_(__global_state);
	errdp_(__global_state, "#", &d__1, (ftnlen)1);
	sigerr_(__global_state, "SPICE(ZEROBOUNDSEXTENT)", (ftnlen)23);
	chkout_(__global_state, "ZZNRMLON", (ftnlen)8);
	return 0;
    }

/*     The input longitude is within range or is out of range by at most */
/*     |TOL| radians. Bracket it. */
/* Computing MAX */
    d__1 = -__state->pi2, d__2 = min(*inmin,__state->pi2);
    *outmin = max(d__1,d__2);

/*     Same deal for the upper bound. */

    if (*inmax < -__state->pi2 - *tol || *inmax > __state->pi2 + *tol) {
	chkin_(__global_state, "ZZNRMLON", (ftnlen)8);
	setmsg_(__global_state, "Longitude upper bound INMAX = # (radians), "
		" = # (deg). The minimum allowed value is  -2*pi - TOL = # (r"
		"adians), = # (deg).", (ftnlen)122);
	errdp_(__global_state, "#", inmax, (ftnlen)1);
	d__1 = *inmax * dpr_(__global_state);
	errdp_(__global_state, "#", &d__1, (ftnlen)1);
	d__1 = -__state->pi2 - *tol;
	errdp_(__global_state, "#", &d__1, (ftnlen)1);
	d__1 = (-__state->pi2 - *tol) * dpr_(__global_state);
	errdp_(__global_state, "#", &d__1, (ftnlen)1);
	sigerr_(__global_state, "SPICE(VALUEOUTOFRANGE)", (ftnlen)22);
	chkout_(__global_state, "ZZNRMLON", (ftnlen)8);
	return 0;
    }
/* Computing MAX */
    d__1 = -__state->pi2, d__2 = min(*inmax,__state->pi2);
    *outmax = max(d__1,d__2);

/*     If the bounds are out of order, put them in order. */
/*     It is assumed that no interval has length zero. */

/*     If the upper bound is greater than the lower bound by */
/*     less than TOL, the bounds are considered to be "out of */
/*     order." */

    d__1 = *outmin + *tol;
    if (*outmax <= touchd_(__global_state, &d__1)) {

/*        Shift one of the bounds by 2*pi, while keeping */
/*        the bounds in the range [-2pi, 2pi]. */

	if (*outmax <= 0.) {

/*           OUTMAX is non-positive. Shift it to the right. */

/* Computing MIN */
	    d__2 = *outmax + __state->pi2;
	    d__1 = touchd_(__global_state, &d__2);
	    *outmax = min(d__1,__state->pi2);
	    if (*outmax < *outmin) {

/*              If the bounds are still out of order, shift the lower */
/*              bound left. */

/* Computing MAX */
		d__3 = *outmin - __state->pi2;
		d__1 = touchd_(__global_state, &d__3), d__2 = -__state->pi2;
		*outmin = max(d__1,d__2);
	    }
	} else {

/*           OUTMAX is > 0. Shift the lower bound left. */

/* Computing MAX */
	    d__3 = *outmin - __state->pi2;
	    d__1 = touchd_(__global_state, &d__3), d__2 = -__state->pi2;
	    *outmin = max(d__1,d__2);
	}
    }

/*     If the bounds are too far apart, move them together. Note */
/*     that OUTMIN and OUTMAX are already set at this point. */

    d__1 = *outmax - *outmin;
    delta = touchd_(__global_state, &d__1);
    d__1 = __state->pi2 + *tol;
    if (delta > touchd_(__global_state, &d__1)) {

/*        Shift the upper bound lower by 2*pi. */

	d__1 = *outmax - __state->pi2;
	*outmax = touchd_(__global_state, &d__1);
    }

/*     The output bounds must not be equal. We could end up with */
/*     equal output bounds if the input maximum is less than */
/*     the input minimum and the bounds differ by an integer */
/*     multiple of 2*pi. */

    if (*outmin == *outmax) {
	chkin_(__global_state, "ZZNRMLON", (ftnlen)8);
	setmsg_(__global_state, "After adjustment, input longitude lower bou"
		"nd INMIN = # (radians),  = # (deg), is equal to adjusted lon"
		"gitude upper bound. Input upper bound = # (radians),  = # (d"
		"eg). When the input upper bound is less than the input lower"
		" bound, the difference must not be an integer multiple of 2*"
		"pi.", (ftnlen)286);
	errdp_(__global_state, "#", inmin, (ftnlen)1);
	d__1 = *inmin * dpr_(__global_state);
	errdp_(__global_state, "#", &d__1, (ftnlen)1);
	errdp_(__global_state, "#", inmax, (ftnlen)1);
	d__1 = *inmax * dpr_(__global_state);
	errdp_(__global_state, "#", &d__1, (ftnlen)1);
	sigerr_(__global_state, "SPICE(ZEROBOUNDSEXTENT)", (ftnlen)23);
	chkout_(__global_state, "ZZNRMLON", (ftnlen)8);
	return 0;
    }
    return 0;
} /* zznrmlon_ */

