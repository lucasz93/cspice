/* hyptof.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern hyptof_init_t __hyptof_init;
static hyptof_state_t* get_hyptof_state(cspice_t* state) {
	if (!state->hyptof)
		state->hyptof = __cspice_allocate_module(sizeof(
	hyptof_state_t), &__hyptof_init, sizeof(__hyptof_init));
	return state->hyptof;

}

/* $Procedure      HYPTOF ( Hyperbolic time of flight ) */
/* Subroutine */ int hyptof_(cspice_t* __global_state, doublereal *ma, 
	doublereal *ecc, doublereal *f)
{
    /* Initialized data */


    /* System generated locals */
    doublereal d__1, d__2, d__3, d__4;

    /* Builtin functions */
    double log(doublereal), sqrt(doublereal), sinh(doublereal);

    /* Local variables */
    doublereal diff;
    doublereal m;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern doublereal dcbrt_(cspice_t*, doublereal *);
    extern doublereal dpmax_(cspice_t*);
    integer count;
    doublereal lower;
    doublereal upper;
    doublereal middle;
    doublereal midval;
    doublereal lastdf;
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    integer mcount;
    extern logical return_(cspice_t*);


    /* Module state */
    hyptof_state_t* __state = get_hyptof_state(__global_state);
/* $ Abstract */

/*     Solve the time of flight equation MA = e sinh(F) - F for the */
/*     hyperbolic eccentric anomaly F, given the mean anomaly, MA, */
/*     and the eccentricity, e. */

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

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     MA         I   Mean anomaly at epoch. */
/*     ECC        I   Eccentricity. */
/*     F          O   Hyperbolic eccentric anomaly. */

/* $ Detailed_Input */

/*     MA          is the hyperbolic mean anomaly of an orbiting body at */
/*                 some epoch t, */

/*                                         3 1/2 */
/*                       MA = (t-T)(mu/(-a) ) */

/*                 where T is the time of periapsis passage, a is */
/*                 the semi-major axis of the orbit, and mu is the */
/*                 gravitational parameter of the primary body. */

/*     ECC         is the eccentricity of the orbit. */

/* $ Detailed_Output */

/*     F           is the corresponding eccentric anomaly. This is the */
/*                 solution to the time of flight equation */

/*                       MA = e sinh(F) - F */

/* $ Parameters */

/*      None. */

/* $ Exceptions */

/*     1) If the eccentricity (ECC) is less than one, the error */
/*        'SPICE(WRONGCONIC)' is signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     Iterate to solve */

/*           f(F,MA,e) = e sinh(F) - F - MA = 0 */

/* $ Examples */

/*     ELLTOF, HYPTOF, and PARTOF are used by CONICS. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     [1] Roger Bate, Fundamentals of Astrodynamics, Dover, 1971. */

/* $ Author_and_Institution */

/*     I.M. Underwood  (JPL) */
/*     W.L. Taber      (JPL) */

/* $ Version */

/* -    SPICELIB Version 3.1.0, 13-JUL-2007 (NJB) */

/*        Bug fix: MAXLOG is now saved. */

/* -    SPICELIB Version 3.0.0, 14-DEC-1994 (WLT) */

/*        A counter was placed in the loop which bisects to a */
/*        solution to the hyperbolic version of Kepler's equation. */
/*        This addition forces the loop to terminate.  On some platforms */
/*        the loop would not terminate without this additional */
/*        check.  This was due to the compiler performing tests on */
/*        extended precision registers. */

/* -    SPICELIB Version 2.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 2.0.0, 19-APR-1990 (WLT) */

/*        A bad initial guess at bracketing the solution to the */
/*        hyperbolic time of flight equation was corrected so that */
/*        floating point overflows are now avoided.  In addition, the */
/*        Newton's method used before has been replaced by simply */
/*        bisection. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     hyperbolic time of flight */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 3.0.0, 14-DEC-1994 (WLT) */

/*        A counter was placed in the loop which bisects to a */
/*        solution to the hyperbolic version of Kepler's equation. */
/*        This addition forces the loop to terminate.  On some platforms */
/*        the loop would not terminate without this additional */
/*        check.  This was due to the compiler performing tests on */
/*        extended precision registers. */

/*        This is not due to a bug in the algorithm but rather to */
/*        what NAIF feels is an error on the part of some compiler */
/*        vendors.  If the difference between two d.p. numbers is */
/*        zero to double precision we feel that that is the number */
/*        that should be used in subsequent statements---ESPECIALLY */
/*        in comparisons.  However, since we don't have control */
/*        over how compiler writers decide to compile code, we have */
/*        added the loop counter to guarantee that the loop solving */
/*        the hyperbolic Kepler's equation terminates. */

/* -    SPICELIB Version 2.0.0, 19-APR-1990 (WLT) */

/*        A bad initial guess at bracketing the solution to the */
/*        hyperbolic time of flight equation was corrected so that */
/*        floating point overflows are now avoided.  In addition, the */
/*        Newton's method used before has been replaced by simply */
/*        bisection. */

/* -    Beta Version 1.1.1, 27-JAN-1989 (IMU) */

/*        Examples section completed. */

/* -& */
/* $ Revisions */

/* -    Beta Version 1.1.0, 8-JAN-1989 (IMU) */

/*        The routine now verifies that the eccentricity is in the */
/*        proper range---(1,+infinity)---before proceeding. */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Saved variables */


/*     Initial values */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "HYPTOF", (ftnlen)6);
    }
    if (__state->first) {
	__state->first = FALSE_;
	__state->maxlog = log(dpmax_(__global_state));
    }
    if (*ecc < 1.) {
	sigerr_(__global_state, "SPICE(WRONGCONIC)", (ftnlen)17);
	chkout_(__global_state, "HYPTOF", (ftnlen)6);
	return 0;
    }

/*     For reasons of numerical stability, we have to intercept cases */
/*     where the mean anomaly is zero or negative (since log x is not */
/*     defined for non-positive x). If the mean anomaly is zero, the */
/*     eccentric anomaly is also zero (by inspection). */

/*     Since the function e sinh(F) - F is an odd function, we can */
/*     solve the equation ABS(MA) = e sinh(F) - F for F and get */
/*     the solution to MA = e sinh(F) - F by negating F if MA is */
/*     less than 0. */

    if (*ma == 0.) {
	*f = 0.;
	chkout_(__global_state, "HYPTOF", (ftnlen)6);
	return 0;
    } else {
	m = abs(*ma);
    }

/*     The initial bounds for the eccentric anomaly F are determined */
/*     as follows: */

/*     For the value of F we seek, */

/*        M = e sinh F - F */

/*     Thus */

/*        M < e sinh F =    (e/2) { Exp(F) - Exp(-F)} */

/*     Hence */

/*        2 M                1 */
/*        ---   < Exp(F) - ----- */
/*         e               Exp(F) */

/*     which yields */


/*        2 M Exp(F) */
/*        ----------   < Exp(F)**2 - 1 */
/*            e */

/*     and */

/*           M**2                2M Exp(F)     M**2 */
/*       1 + ---- <  Exp(F)**2 - ---------  +  ---- = {Exp(F) - (M/e)}**2 */
/*           e**2                   e          e**2 */


/*     Therefore we must have one of the following be true. */


/*      SQRT( 1 + (M/e)**2 )  <  Exp(F) - (M/e) */

/*    or */

/*     - SQRT( 1 + (M/e)**2 )  >  Exp(F) - (M/e) */

/*    The second case implies that */

/*     0 > (M/e) - SQRT( 1 + (M/e)**2 ) > Exp(F) */

/*    but since Exp(F) > 0 for all F it must be the case that */

/*      (M/e) + SQRT( 1 + (M/e)**2 ) < Exp(F) */


/*    Hence */

/*       Log ( (M/e) + SQRT(1 + (M/e)**2) )  < F */



/*     Returning to our initial equation: */

/*        M = e sinh F - F */

/*                         3        5 */
/*                        F        F */
/*          =  e ( F  +  ---   +  --- + ...   )  -  F */
/*                        3!       5! */

/*               3 */
/*          >  eF / 6 */

/*     Thus */


/*             3 __________ */
/*        F <  \/  6M / e */


/*     Thus our solution must satisfy the inequalities */


/*                                                      3 __________ */
/*      LOG ( (M/e) + SQRT(1 + (M/e)**2) )  <   F   <   \/  6M/e */


/*     In addition we know that the solution must lie somewhere */
/*     in the region between 0 and the maximum value of F for which */
/*     (e sinh F - F) can be computed.  This turns out to be */
/*     approximately LOG( DPMAX() / e ) = LOG(DPMAX()) - LOG(e) . */


/* Computing 2nd power */
    d__1 = m / *ecc;
    lower = log(m / *ecc + sqrt(d__1 * d__1 + 1.));
/* Computing MIN */
    d__3 = m * 6. / *ecc;
    d__1 = dcbrt_(__global_state, &d__3), d__2 = __state->maxlog - log(*ecc);
    upper = min(d__1,d__2);
    upper = max(lower,upper);

/*     Perform some simple checks first to avoid problems with */
/*     convergence of the loop below.  If LOWER is zero, then */
/*     M/ECC is so small that when added to 1 it doesn't make */
/*     any difference ( dLOG/dt = 1 at 1 after all).  So in this */
/*     case we will just solve the linear portion of the */
/*     expansion of e SINH(F) - F = M */


/*     Now we simply perform bisection to locate the root. */

/* Computing MAX */
/* Computing MIN */
    d__3 = upper, d__4 = upper * .5 + lower * .5;
    d__1 = lower, d__2 = min(d__3,d__4);
    middle = max(d__1,d__2);
    midval = *ecc * sinh(middle) - middle - m;
    diff = upper - lower;

/*     Finally pick a reasonable upper bound on the number of loop */
/*     iterations we shall need to perform. */

    mcount = 100;
    count = 0;
    while(diff > 0. && count < mcount) {

/*        Move one of the endpoints to the middle. */

	if (midval > 0.) {
	    upper = middle;
	} else if (midval < 0.) {
	    lower = middle;
	} else {
	    lower = middle;
	    upper = middle;
	}

/*        Compute the next middle point. */

/* Computing MAX */
/* Computing MIN */
	d__3 = upper, d__4 = upper * .5 + lower * .5;
	d__1 = lower, d__2 = min(d__3,d__4);
	middle = max(d__1,d__2);
	lastdf = diff;
	++count;

/*        If we are on an endpoint, we are ready to call it quits. */

	if (middle == lower || middle == upper) {
	    diff = 0.;
	} else {
	    diff = upper - lower;
	    midval = *ecc * sinh(middle) - middle - m;
	}
    }

/*     Restore the proper sign, if necessary. */

    if (*ma < 0.) {
	*f = -middle;
    } else {
	*f = middle;
    }
    chkout_(__global_state, "HYPTOF", (ftnlen)6);
    return 0;
} /* hyptof_ */

