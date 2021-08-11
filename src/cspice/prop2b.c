/* prop2b.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern prop2b_init_t __prop2b_init;
static prop2b_state_t* get_prop2b_state() {
	cspice_t* state =  __cspice_get_state();
	if (!state->prop2b)
		state->prop2b = __cspice_allocate_module(sizeof(
	prop2b_state_t), &__prop2b_init, sizeof(__prop2b_init));
	return state->prop2b;

}

/* $Procedure      PROP2B ( Propagate a two-body solution ) */
/* Subroutine */ int prop2b_(doublereal *gm, doublereal *pvinit, doublereal *
	dt, doublereal *pvprop)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6, i__7;
    doublereal d__1, d__2, d__3, d__4;

    /* Builtin functions */
    integer s_rnge(char *, integer, char *, integer);
    double sqrt(doublereal), log(doublereal), exp(doublereal);

    /* Local variables */
    extern doublereal vdot_(doublereal *, doublereal *);
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    extern doublereal dpmax_(void);
    extern /* Subroutine */ int errdp_(char *, doublereal *, ftnlen);
    extern /* Subroutine */ int vlcom_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *);
    extern /* Subroutine */ int stmp03_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    extern /* Subroutine */ int vequg_(doublereal *, integer *, doublereal *);
    extern /* Subroutine */ int vcrss_(doublereal *, doublereal *, doublereal 
	    *);
    extern doublereal vnorm_(doublereal *);
    extern logical vzero_(doublereal *);
    extern doublereal brcktd_(doublereal *, doublereal *, doublereal *);
    extern integer brckti_(integer *, integer *, integer *);
    extern /* Subroutine */ int sigerr_(char *, ftnlen);
    extern /* Subroutine */ int chkout_(char *, ftnlen);
    extern /* Subroutine */ int setmsg_(char *, ftnlen);
    extern logical return_(void);

    /* Module state */
    prop2b_state_t* __state = get_prop2b_state();
/* $ Abstract */

/*     Given a central mass and the state of massless body at time t_0, */
/*     this routine determines the state as predicted by a two-body */
/*     force model at time t_0 + DT. */

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
/*     UTILITY */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     GM         I   Gravity of the central mass. */
/*     PVINIT     I   Initial state from which to propagate a state. */
/*     DT         I   Time offset from initial state to propagate to. */
/*     PVPROP     O   The propagated state. */

/* $ Detailed_Input */

/*     GM         is the gravitational constant G times the mass M of the */
/*                central body. */

/*     PVINIT     is the state at some specified time relative to the */
/*                central mass.  The mass of the object is assumed to */
/*                be negligible when compared to the central mass. */

/*     DT         is a offset in time from the time of the initial */
/*                state to which the two-body state should be */
/*                propagated. (The units of time and distance must be */
/*                the same in GM, PVINIT, and DT). */

/* $ Detailed_Output */

/*     PVPROP     is the two-body propagation of the initial state */
/*                DT units of time past the epoch of the initial state. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If GM is not positive, the error SPICE(NONPOSITIVEMASS) will */
/*        be signalled. */

/*     2) If the position of the initial state is the zero vector, the */
/*        error SPICE(ZEROPOSITION) will be signalled. */

/*     3) If the velocity of the initial state is the zero vector, the */
/*        error SPICE(ZEROVELOCITY) will be signalled. */

/*     4) If the cross product of the position and velocity of PVINIT */
/*        has squared length of zero, the error SPICE(NONCONICMOTION) */
/*        will be signalled. */

/*     5) The value of DT must be "reasonable".  In other words, DT */
/*        should be less than 10**20 seconds for realistic solar system */
/*        orbits specified in the MKS system.  (The actual bounds */
/*        on DT are much greater but require substantial computation.) */
/*        The "reasonableness" of DT is checked at run-time.  If DT is */
/*        so large that there is a danger of floating point overflow */
/*        during computation, the error SPICE(DTOUTOFRANGE) is */
/*        signalled and a message is generated describing the problem. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine uses a universal variables formulation for the */
/*     two-body motion of an object in orbit about a central mass. It */
/*     propagates an initial state to an epoch offset from the */
/*     epoch of the initial state by time DT. */

/*     This routine does not suffer from the finite precision */
/*     problems of the machine that are inherent to classical */
/*     formulations based on the solutions to Kepler's equation: */

/*           n( t - T ) = E - e Sin(E)         elliptic case */
/*           n( t - T ) = e sinh(F) - F        hyperbolic case */

/*     The derivation used to determine the propagated state is a */
/*     slight variation of the derivation in Danby's book */
/*     `Fundamentals of Celestial Mechanics' [1] . */

/* $ Examples */

/*     When the eccentricity of an orbit is near 1, and the epoch */
/*     of classical elements is near the epoch of periapse, classical */
/*     formulations that propagate a state from elements tend to */
/*     lack robustness due to the finite precision of floating point */
/*     machines. In those situations it is better to use a universal */
/*     variables formulation to propagate the state. */

/*     By using this routine, you need not go from a state to elements */
/*     and back to a state. Instead, you can get the state from an */
/*     initial state. */

/*     If PV is your initial state and you want the state 3600 */
/*     seconds later, the following call will suffice. */

/*          Look up GM somewhere */

/*          DT = 3600.0D0 */

/*          CALL PROP2B ( GM, PV, DT, PVDT ) */

/*     After the call, PVDT will contain the state of the */
/*     object 3600 seconds after the time it had state PV. */

/* $ Restrictions */

/*     Users should be sure that GM, PVINIT and DT are all in the */
/*     same system of units ( for example MKS ). */

/* $ Literature_References */

/*     [1] `Fundamentals of Celestial Mechanics', Second Edition */
/*         by J.M.A. Danby;  Willman-Bell, Inc., P.O. Box 35025 */
/*         Richmond Virginia;  pp 168-180 */

/* $ Author_and_Institution */

/*     W.L. Taber     (JPL) */
/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.1.0, 31-AUG-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in VSCL call. */

/* -    SPICELIB Version 2.0.1, 22-AUG-2001 (EDW) */

/*        Corrected ENDIF to END IF. */

/* -    Spicelib Version 2.0.0 16-May-1995  (WLT) */

/*        The initial guess at a solution to Kepler's equation was */
/*        modified slightly and a loop counter was added to the */
/*        bisection loop together with logic that will force termination */
/*        of the bisection loop. */

/* -    Spicelib Version 1.0.0, 10-Mar-1992 (WLT) */


/* -& */
/* $ Index_Entries */

/*      Propagate state vector using two-body force model */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 2.1.0, 31-AUG-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in VSCL call. */

/* -& */

/*     SPICELIB functions */


/*     Local Parameters */


/*     Local variables */


/*     The following quantities are needed in the solution of Kepler's */
/*     equation and in the propagation of the input state.  They are */
/*     described as they are introduced in the code below. */


/*     The variables below store intermediate results that can be */
/*     reused if PVINIT is supplied more than once to this routine. */
/*     In this way, the number of redundant computations can be reduced. */


/*     Variables used to bracket X in our solution of Kepler's equation. */


/*     Save everything. */


/*     Initial values */


/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    } else {
	chkin_("PROP2B", (ftnlen)6);
    }

/*     Life will be easier if we use POS and VEL to hold the state. */

    __state->pos[0] = pvinit[0];
    __state->pos[1] = pvinit[1];
    __state->pos[2] = pvinit[2];
    __state->vel[0] = pvinit[3];
    __state->vel[1] = pvinit[4];
    __state->vel[2] = pvinit[5];

/*     If we propagate many states from the same initial state, */
/*     most of the variables used to propagate the state will */
/*     not change in value. */

/*     To save time needed to compute these variables, we recompute */
/*     variables that depend upon the initial state only when the */
/*     initial state is not one of those already buffered by this */
/*     routine. */

/*     Determine whether or not this GM and state are the same as the */
/*     one of those already buffered.  Note that we look through the */
/*     saved states and GM from the most recently input values of PVINIT */
/*     and GM to the oldest saved state and GM. */

/*     NEWEST(1)  contains the most recently input initial conditions */
/*     NEWEST(2)  contains the next most recently input intial conditions */
/*                etc. */

/*     Also note that when this routine starts up there will be no */
/*     buffered states or GMs.  Every time we encounter a new state, we */
/*     will increment the number of saved states NSAVED until we have */
/*     BUFSIZ states buffered.  From that point on, when a new state is */
/*     encountered we will overwrite the oldest buffered state. */

    __state->i__ = 0;
    __state->new__ = TRUE_;
    while(__state->i__ < __state->nsaved && __state->new__) {
	++__state->i__;
	__state->k = __state->newest[(i__1 = __state->i__ - 1) < 3 && 0 <= 
		i__1 ? i__1 : s_rnge("newest", i__1, "prop2b_", (ftnlen)375)];
	__state->new__ = pvinit[0] != __state->savepv[(i__1 = __state->k * 6 
		- 6) < 18 && 0 <= i__1 ? i__1 : s_rnge("savepv", i__1, "prop"
		"2b_", (ftnlen)377)] || pvinit[1] != __state->savepv[(i__2 = 
		__state->k * 6 - 5) < 18 && 0 <= i__2 ? i__2 : s_rnge("savepv"
		, i__2, "prop2b_", (ftnlen)377)] || pvinit[2] != 
		__state->savepv[(i__3 = __state->k * 6 - 4) < 18 && 0 <= i__3 
		? i__3 : s_rnge("savepv", i__3, "prop2b_", (ftnlen)377)] || 
		pvinit[3] != __state->savepv[(i__4 = __state->k * 6 - 3) < 18 
		&& 0 <= i__4 ? i__4 : s_rnge("savepv", i__4, "prop2b_", (
		ftnlen)377)] || pvinit[4] != __state->savepv[(i__5 = 
		__state->k * 6 - 2) < 18 && 0 <= i__5 ? i__5 : s_rnge("savepv"
		, i__5, "prop2b_", (ftnlen)377)] || pvinit[5] != 
		__state->savepv[(i__6 = __state->k * 6 - 1) < 18 && 0 <= i__6 
		? i__6 : s_rnge("savepv", i__6, "prop2b_", (ftnlen)377)] || *
		gm != __state->savegm[(i__7 = __state->k - 1) < 3 && 0 <= 
		i__7 ? i__7 : s_rnge("savegm", i__7, "prop2b_", (ftnlen)377)];
    }
    if (! __state->new__) {

/*        We update the order vector NEWEST so that the state being */
/*        used this time becomes the "youngest" state. */

	__state->k = __state->i__;
	__state->bumped = __state->newest[(i__1 = __state->k - 1) < 3 && 0 <= 
		i__1 ? i__1 : s_rnge("newest", i__1, "prop2b_", (ftnlen)394)];
	for (__state->i__ = __state->k; __state->i__ >= 2; --__state->i__) {
	    __state->newest[(i__1 = __state->i__ - 1) < 3 && 0 <= i__1 ? i__1 
		    : s_rnge("newest", i__1, "prop2b_", (ftnlen)397)] = 
		    __state->newest[(i__2 = __state->i__ - 2) < 3 && 0 <= 
		    i__2 ? i__2 : s_rnge("newest", i__2, "prop2b_", (ftnlen)
		    397)];
	}
	__state->newest[0] = __state->bumped;
	__state->k = __state->bumped;

/*        Now look up all of the other saved quantities. */

	__state->b2rv = __state->sb2rv[(i__1 = __state->k - 1) < 3 && 0 <= 
		i__1 ? i__1 : s_rnge("sb2rv", i__1, "prop2b_", (ftnlen)406)];
	__state->bound = __state->sbound[(i__1 = __state->k - 1) < 3 && 0 <= 
		i__1 ? i__1 : s_rnge("sbound", i__1, "prop2b_", (ftnlen)407)];
	__state->bq = __state->sbq[(i__1 = __state->k - 1) < 3 && 0 <= i__1 ? 
		i__1 : s_rnge("sbq", i__1, "prop2b_", (ftnlen)408)];
	__state->br0 = __state->sbr0[(i__1 = __state->k - 1) < 3 && 0 <= i__1 
		? i__1 : s_rnge("sbr0", i__1, "prop2b_", (ftnlen)409)];
	__state->f = __state->sf[(i__1 = __state->k - 1) < 3 && 0 <= i__1 ? 
		i__1 : s_rnge("sf", i__1, "prop2b_", (ftnlen)410)];
	__state->qovr0 = __state->sqovr0[(i__1 = __state->k - 1) < 3 && 0 <= 
		i__1 ? i__1 : s_rnge("sqovr0", i__1, "prop2b_", (ftnlen)411)];
    } else {

/*        We have a new state, new GM or both.  First let's make sure */
/*        there is nothing obviously wrong with them.  (We buffer */
/*        only states, GMs and intermediate values that are "good.") */
/*        First check for nonpositive mass. */

	if (*gm <= 0.) {
	    sigerr_("SPICE(NONPOSITIVEMASS)", (ftnlen)22);
	    chkout_("PROP2B", (ftnlen)6);
	    return 0;
	}

/*        Next for a zero position vector */

	if (vzero_(__state->pos)) {
	    sigerr_("SPICE(ZEROPOSITION)", (ftnlen)19);
	    chkout_("PROP2B", (ftnlen)6);
	    return 0;
	}

/*        Finally for a zero velocity vector */

	if (vzero_(__state->vel)) {
	    sigerr_("SPICE(ZEROVELOCITY)", (ftnlen)19);
	    chkout_("PROP2B", (ftnlen)6);
	    return 0;
	}

/*        Obvious problems have been checked. Here are the relevant */
/*        equations. Let ... */

/*           GM        be the gravitational attraction of the central */
/*                     mass. */

/*           POS and   be the initial position and velocity respectively */
/*           VEL       of the orbiting object. */

/*           R0       be the magnitude of the position vector POS */

/*           RV       be the value of the dot product  POS * VEL */

	__state->r0 = vnorm_(__state->pos);
	__state->rv = vdot_(__state->pos, __state->vel);

/*        Let HVEC be the specific angular momentum vector and let Q be */
/*        the distance at periapse. */

/*                   1)    HVEC  =   POS  x  VEL */

/*                                       2 */
/*                   2)    H2    = |HVEC|  =  GM*(1+E)*Q */


	vcrss_(__state->pos, __state->vel, __state->hvec);
	__state->h2 = vdot_(__state->hvec, __state->hvec);

/*        Let's make sure we are not in the pathological case of */
/*        rectilinear motion. */

	if (__state->h2 == 0.) {
	    sigerr_("SPICE(NONCONICMOTION)", (ftnlen)21);
	    chkout_("PROP2B", (ftnlen)6);
	    return 0;
	}

/*        Let E be the eccentricity of the orbit. */

/*        Let QVEC be the unit vector that points toward perihelion, and */
/*        let EQVEC be QVEC scaled by E. */

/*                                   VEL X HVEC      POS */
/*                    1)  E*QVEC  =  ----------  -   --- */
/*                                       GM           R0 */


/*                                         VEL X HVEC      POS */
/*                    2)  E       = NORM ( ----------  -   --- ) */
/*                                            GM            R0 */


	vcrss_(__state->vel, __state->hvec, __state->tmpvec);
	d__1 = 1. / *gm;
	d__2 = -1. / __state->r0;
	vlcom_(&d__1, __state->tmpvec, &d__2, __state->pos, __state->eqvec);
	__state->e = vnorm_(__state->eqvec);

/*        Solve the equation H2 = GM*Q*(1+E) for Q. */

	__state->q = __state->h2 / (*gm * (__state->e + 1));

/*        From the discussion of the universal variables formulation in */
/*        Danby's book on pages 174 and 175 (see the reference listed */
/*        above) you can show that by making the substitutions */

/*              F  =  1 - E */

/*        and */

/*                       _____ */
/*                      /  Q */
/*              S  =   / -----    X   = B * X */
/*                   \/   GM */


/*        that DT satisfies the universal variables Kepler's equation: */

/*                                   2     2     2        2 */
/*              DT =  B*R0*X*C_1( F*X ) + B *RV*X C_2( F*X ) */

/*                                               3        2 */
/*                                      +   B*Q*X C_3( F*X ) */

/*                 =  KFUN( X ) */

/*        (where C_k is used to denote the Stumpff functions. This is */
/*        the universal variables formulation of Kepler's equation. */
/*        KFUN is our abbreviation for "Kepler function.") */

/*        (One might wonder, "Why make such a change of variables?" */
/*        By making this substitution early in the derivation supplied */
/*        in Danby's book, you can always deal with physically */
/*        meaningful quantities --- the pure numeric value of F and the */
/*        distance of periapse.  Thus one does not need to be concerned */
/*        about infinite or negative semi-major axes or with discussing */
/*        how to interpret these somewhat artificial artifacts of the */
/*        classical derivations for two body motion.) */

/*        Given the unique X for which this Kepler's equation is */
/*        satisfied, we can compute the state of the orbiting object */
/*        at a time DT past the epoch of the state POS and VEL. */
/*        Evidently we will need the constants: */

	__state->f = 1. - __state->e;
	__state->b = sqrt(__state->q / *gm);
	__state->br0 = __state->b * __state->r0;
	__state->b2rv = __state->b * __state->b * __state->rv;
	__state->bq = __state->b * __state->q;

/*        The state corresponding to the value of X that solves this */
/*        equation is given by */

/*              PC * POS + VC * VEL              ( position ) */

/*        and */

/*              PCDOT * POS + VCDOT * VEL        ( velocity ) */

/*        where */
/*                                            2        2 */
/*           ( 1 )    PC    =  1  -  ( Q/R0 )X C_2( F*X ) */

/*                                            3        2 */
/*           ( 2 )    VC    =  DT -  ( B*Q  )X C_3( F*X ) */


/*                                       Q               2 */
/*           ( 3 )    PCDOT =     -  ( ------ ) X C_1( F*X ) */
/*                                     B*R*R0 */

/*                                      B*Q     2        2 */
/*           ( 4 )    VCDOT =  1  -  (  ---  ) X C_2( F*X ) */
/*                                      B*R */

/*        Here R denotes the distance from the center of CP*POS + CV*VEL */
/*        It turns out that R can be computed as: */

/*                                        2     2             2 */
/*           ( 5 )   B*R    = B*R0 C_0(F*X ) + B *RV X C_1(F*X ) */

/*                                                 2       2 */
/*                                        +   B*Q X C_2(F*X ) */


/*        Therefore we will also need the constant */

	__state->qovr0 = __state->q / __state->r0;

/*        We will have to find the unique value of X such that */

/*             DT = KFUN ( X ) */

/*        where KFUN stands for the "Kepler function" defined by the */
/*        equation below: */

/*                                   2 */
/*        KFUN(X) =   B*R0*X * C_1(FX ) */

/*                   2     2        2 */
/*                + B *RV*X * C_2(FX ) */

/*                         3        2 */
/*                +   B*Q*X * C_3(FX ) */


/*        (There is a unique solution to this equation. KFUN(X) is */
/*        unbounded above and below and is an increasing function */
/*        over all real X for all non-rectilinear orbits. To see this */
/*        we note that the variable X is a function of DT and is given */
/*        by the integral from 0 to DT of the differential: */

/*                   dt */
/*                 ------ */
/*                 B*R(t) */

/*        where R(t) is the range of the body as a function of time. */
/*        Therefore X is an increasing function of DT, and DT must */
/*        also be an increasing function of X. */

/*        Thus, there is a unique value of X  that solves this */
/*        equation). */

/*        If F is less than zero, we can have the computation of C0,... */
/*        overflow.  This is because for X < 0 */


/*               C_0(X) = COSH( DSQRT(-X) ) */

/*               C_1(X) = SINH( DSQRT(-X) ) */
/*                        ----------------- */
/*                              DSQRT(-X) */



/*        and from the recursion relationship we know that */


/*               C_2(X) =  ( 1/0! - C_0(X) ) / X */

/*               C_3(X) =  ( 1/1! - C_1(X) ) / X */


/*                         1 - COSH( DSQRT(-X) ) */
/*               C_2(X) = ------------------------ */
/*                                  X */

/*                         1  - SINH( DSQRT(-X) ) / DSQRT(-X) */
/*               C_3(X) = ----------------------------------- */
/*                                    X */

/*        Clearly for negative values of F*X*X having large magnitude, */
/*        it is easy to get an overflow. */

/*        In the case when F is less than 0 we choose X so that we can */
/*        compute all of the following: */

/*               | COEF_0 * X**0 * C_0(FX**2) | */

/*               | COEF_1 * X**1 * C_1(FX**2) | */

/*               | COEF_2 * X**2 * C_2(FX**2) | */

/*               | COEF_3 * X**3 * C_3(FX**2) | */


/*         where COEF_n are coefficients that will be used in forming */
/*         linear combinations of X**n C_n(FX**2) terms. */

/*         The variable portion of the last 3 terms above can be */
/*         rewritten as: */


/*                                   SINH ( DSQRT(-F)*|X| ) */
/*        | X**1 * C_1(FX**2) |  =   ---------------------- */
/*                                          DSQRT(-F) */



/*                                   1 - COSH( DSQRT(-F)*|X| ) */
/*        | X**2 * C_2(FX**2) |  =  ---------------------------- */
/*                                             -F */


/*                                  DSQRT(-F)*|X|   - SINH(DSQRT(-F)*|X|) */
/*        | X**3 * C_3(FX**2) |  =  ------------------------------------- */
/*                                              F*DSQRT(-F) */


/*        For large |X| the absolute values of these expressions are well */
/*        approximated by */

/*                                         0.0 */
/*               COSH( DSQRT(-F)|X| ) * |F| */

/*                                         -0.5 */
/*               SINH( DSQRT(-F)|X| ) * |F| */

/*                                         -1.0 */
/*               COSH( DSQRT(-F)|X| ) * |F| */

/*                                         -1.5 */
/*               SINH( DSQRT(-F)|X| ) * |F| */


/*        For large |X| the logarithms of these expressions are well */
/*        approximated by: */


/*               DSQRT(-F)|X| - LOG(2) - 0.0*LOG(-F) */

/*               DSQRT(-F)|X| - LOG(2) - 0.5*LOG(-F) */

/*               DSQRT(-F)|X| - LOG(2) - 1.0*LOG(-F) */

/*               DSQRT(-F)|X| - LOG(2) - 1.5*LOG(-F) */

/*        respectively. */


/*        To ensure that we can form a linear combination of these terms */
/*        we will require that: */


/*           |COEF_N*X**N * C_N(FX**2)| < DPMAX / 4 */



/*        for N=0,1,2,3.  This is equivalent to */

/*              LOG ( X**N * C_N(FX**2) )   <      LOG ( DPMAX ) */
/*            + LOG (|COEF_N|)                   - 2 LOG ( 2     ) */



/*        or */

/*              LOG ( X**N * C_N(FX**2) )   <      LOG ( DPMAX    ) */
/*                                             -   LOG ( |COEF_N| ) */
/*                                             - 2*LOG ( 2        ). */


/*        Replacing the left hand side with the magnitude expressions */
/*        computed above we have: */

/*            DSQRT(-F)|X| - LOG(2) - N*0.5*LOG( -F )  <   LOG ( DPMAX  ) */
/*                                                      -  LOG (|COEF_N|) */
/*                                                      -2*LOG ( 2      ) */

/*         So that: */


/*            |X|  <    {   LOG ( DPMAX  ) */
/*                        - LOG (|COEF_N|) */
/*                        - LOG (  2     ) */
/*                        + LOG ( -F     )*N*0.5 } / DSQRT(-F) */

/*         Let MAXC be the maximum of 1.0D0 and the various coefficients */
/*         of the Stumpff functions.  We can then set our absolute value */
/*         bound on X to be: */


/*             MIN        LOG(DPMAX/2) - LOG(MAXC) + (n/2)LOG(-F) */
/*            n = 0,3  {  -----------------------------------------  } */
/*                               DSQRT(-F) */

/*        (Actually we know that the minimum must occur for n = 0 or */
/*        for n = 3). */


/* Computing MAX */
	d__2 = 1., d__3 = abs(__state->br0), d__2 = max(d__2,d__3), d__3 = 
		abs(__state->b2rv), d__2 = max(d__2,d__3), d__3 = abs(
		__state->bq), d__2 = max(d__2,d__3), d__3 = (d__1 = 
		__state->qovr0 / __state->bq, abs(d__1));
	__state->maxc = max(d__2,d__3);
	if (__state->f < 0.) {
	    __state->logmxc = log(__state->maxc);
	    __state->logdpm = log(dpmax_() / 2.);
	    __state->fixed = __state->logdpm - __state->logmxc;
	    __state->rootf = sqrt(-__state->f);
	    __state->logf = log(-__state->f);
/* Computing MIN */
	    d__1 = __state->fixed / __state->rootf, d__2 = (__state->fixed + 
		    __state->logf * 1.5) / __state->rootf;
	    __state->bound = min(d__1,d__2);

/*           Note that in the above, we can always perform the division */
/*           by ROOTF.  To see this we note that -F is at least the */
/*           machine precision (we got it by subtracting E from 1.) */
/*           Thus its square root is a reasonably large number (if F is */
/*           10**-N then ROOTF is 10**(-N/2) )  The value of FIXED is */
/*           about 3*M where M is the largest exponent such that 2**M */
/*           is representable on the host machine.  Thus BOUND is at */
/*           worst M*10**(N/2)  This will always be computable. */

	} else {


/*           In the case when F is non-negative we must be sure we */
/*           can compute all of the following. */

/*               | COEF_0 * X**0 * C_0(FX**2) | < | COEF_0          | */

/*               | COEF_1 * X**1 * C_1(FX**2) | < | COEF_1*|X|      | */

/*               | COEF_2 * X**2 * C_2(FX**2) | < | COEF_2*X**2 / 2 | */

/*               | COEF_3 * X**3 * C_3(FX**2) | < | COEF_3*X**3 / 6 | */

/*           If we assume that COEF_0 is computable, all of these are */
/*           bounded above by: */

/*                       | MAX(COEF_1,...COEF_3) * X**3 / 6 | */

/*           We want to make sure we can add these terms so we need to */
/*           make sure that */

/*              | MAX(COEF_1,...,COEF_3) * X**3 / 6 | < DPMAX() / 4. */

/*           Thus we need: */

/*              |X**3| <          1.5*DPMAX / MAX(COEF_1,...,COEF_3) */
/*              |X|    <  DCBRT ( 1.5*DPMAX / MAX(COEF_1,...,COEF_3) ) */

/*           (We'll use logarithms to compute the upper bound for |X|.) */

	    __state->logbnd = (log(1.5) + log(dpmax_()) - log(__state->maxc)) 
		    / 3.;
	    __state->bound = exp(__state->logbnd);
	}

/*        All the obvious problems have been checked, move everybody */
/*        on the list down and put the new guy on top of the list. */

	i__1 = __state->nsaved + 1;
	__state->nsaved = brckti_(&i__1, &__state->c__1, &__state->c__3);
	__state->bumped = __state->newest[(i__1 = __state->nsaved - 1) < 3 && 
		0 <= i__1 ? i__1 : s_rnge("newest", i__1, "prop2b_", (ftnlen)
		855)];
	for (__state->i__ = __state->nsaved; __state->i__ >= 2; 
		--__state->i__) {
	    __state->newest[(i__1 = __state->i__ - 1) < 3 && 0 <= i__1 ? i__1 
		    : s_rnge("newest", i__1, "prop2b_", (ftnlen)858)] = 
		    __state->newest[(i__2 = __state->i__ - 2) < 3 && 0 <= 
		    i__2 ? i__2 : s_rnge("newest", i__2, "prop2b_", (ftnlen)
		    858)];
	}
	__state->newest[0] = __state->bumped;
	__state->k = __state->bumped;
	__state->savepv[(i__1 = __state->k * 6 - 6) < 18 && 0 <= i__1 ? i__1 :
		 s_rnge("savepv", i__1, "prop2b_", (ftnlen)864)] = pvinit[0];
	__state->savepv[(i__1 = __state->k * 6 - 5) < 18 && 0 <= i__1 ? i__1 :
		 s_rnge("savepv", i__1, "prop2b_", (ftnlen)865)] = pvinit[1];
	__state->savepv[(i__1 = __state->k * 6 - 4) < 18 && 0 <= i__1 ? i__1 :
		 s_rnge("savepv", i__1, "prop2b_", (ftnlen)866)] = pvinit[2];
	__state->savepv[(i__1 = __state->k * 6 - 3) < 18 && 0 <= i__1 ? i__1 :
		 s_rnge("savepv", i__1, "prop2b_", (ftnlen)867)] = pvinit[3];
	__state->savepv[(i__1 = __state->k * 6 - 2) < 18 && 0 <= i__1 ? i__1 :
		 s_rnge("savepv", i__1, "prop2b_", (ftnlen)868)] = pvinit[4];
	__state->savepv[(i__1 = __state->k * 6 - 1) < 18 && 0 <= i__1 ? i__1 :
		 s_rnge("savepv", i__1, "prop2b_", (ftnlen)869)] = pvinit[5];
	__state->savegm[(i__1 = __state->k - 1) < 3 && 0 <= i__1 ? i__1 : 
		s_rnge("savegm", i__1, "prop2b_", (ftnlen)870)] = *gm;

/*        Finally we save the results of all of the above */
/*        computations so that we won't have to do them again, */
/*        if this initial state and GM are entered again. */

	__state->sb2rv[(i__1 = __state->k - 1) < 3 && 0 <= i__1 ? i__1 : 
		s_rnge("sb2rv", i__1, "prop2b_", (ftnlen)877)] = 
		__state->b2rv;
	__state->sbound[(i__1 = __state->k - 1) < 3 && 0 <= i__1 ? i__1 : 
		s_rnge("sbound", i__1, "prop2b_", (ftnlen)878)] = 
		__state->bound;
	__state->sbq[(i__1 = __state->k - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(
		"sbq", i__1, "prop2b_", (ftnlen)879)] = __state->bq;
	__state->sbr0[(i__1 = __state->k - 1) < 3 && 0 <= i__1 ? i__1 : 
		s_rnge("sbr0", i__1, "prop2b_", (ftnlen)880)] = __state->br0;
	__state->sf[(i__1 = __state->k - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(
		"sf", i__1, "prop2b_", (ftnlen)881)] = __state->f;
	__state->sqovr0[(i__1 = __state->k - 1) < 3 && 0 <= i__1 ? i__1 : 
		s_rnge("sqovr0", i__1, "prop2b_", (ftnlen)882)] = 
		__state->qovr0;
    }


/*     We are now ready to find the unique value of X such that */

/*             DT = KFUN ( X ) */

/*     First we must bracket the root. The basic idea is this: */

/*     1) KFUN(0) = 0 so we will let one endpoint of our initial */
/*        guess of a bracketing interval be 0. */

/*     2) We get our initial guess at the other endpoint of the */
/*        bracketing interval by recalling that */

/*                   dt */
/*         dX  =   ------ */
/*                 B*R(t) */

/*        From this observation it follows that */

/*                   DT */
/*          X  <  ------- */
/*                   B*Q */

/*        Thus the solution to */

/*             DT = KFUN ( X ) */

/*        Satisifies */

/*                     DT */
/*         0 < X  <  ------- */
/*                    B*Q */


/*        We now have a guess at a bracketing interval. In the case */
/*        DT is positive it looks like */

/*                0        X */
/*         -------[--------]----------------------------- */

/*        This is ok mathematically, but due to rounding etc it is */
/*        conceivable that we might not have bracketed the root. */
/*        We check and if not we will double the */
/*        endpoint farthest from zero and call this X, and make */
/*        the other endpoint the old value of X. */


/*                0 */
/*         -------+--------[--------]-------------------- */


/*        We continue this process ... */

/*                0 */
/*         -------+-----------------[-----------------]-- */

/*        ...until the root is bracketed. (One shift is certain */
/*        to do the job). */

/*        If we perform this interval shift, we will have to take */
/*        care that X does not run out of the domain for which */
/*        we can safely compute KFUN.  Thus we will make sure that */
/*        the endpoints of these shifted intervals always stay safely */
/*        inside the domain for which KFUN can be computed. */

    __state->x = *dt / __state->bq;
    d__1 = -__state->bound;
    __state->x = brcktd_(&__state->x, &d__1, &__state->bound);
    __state->fx2 = __state->f * __state->x * __state->x;
    stmp03_(&__state->fx2, &__state->c0, &__state->c1, &__state->c2, &
	    __state->c3);
    __state->kfun = __state->x * (__state->br0 * __state->c1 + __state->x * (
	    __state->b2rv * __state->c2 + __state->x * (__state->bq * 
	    __state->c3)));
    if (*dt < 0.) {
	__state->upper = 0.;
	__state->lower = __state->x;
	while(__state->kfun > *dt) {
	    __state->upper = __state->lower;
	    __state->lower *= 2.;
	    __state->oldx = __state->x;
	    d__1 = -__state->bound;
	    __state->x = brcktd_(&__state->lower, &d__1, &__state->bound);

/*           Make sure we are making progress. (In other words make sure */
/*           we don't run into the boundary of values that X can assume. */
/*           If we do run into the boundary, X will be unchanged and */
/*           there's nothing further we can do.  We'll have to call it */
/*           quits and tell the user what happened.) */

	    if (__state->x == __state->oldx) {
		__state->fx2 = __state->f * __state->bound * __state->bound;
		stmp03_(&__state->fx2, &__state->c0, &__state->c1, &
			__state->c2, &__state->c3);
		__state->kfunl = -__state->bound * (__state->br0 * 
			__state->c1 - __state->bound * (__state->b2rv * 
			__state->c2 - __state->bound * __state->bq * 
			__state->c3));
		__state->kfunu = __state->bound * (__state->br0 * __state->c1 
			+ __state->bound * (__state->b2rv * __state->c2 + 
			__state->bound * __state->bq * __state->c3));
		setmsg_("The input delta time (DT) has a value of #.  This i"
			"s beyond the range of DT for which we can reliably p"
			"ropagate states. The limits for this GM and initial "
			"state are from # to #. ", (ftnlen)178);
		errdp_("#", dt, (ftnlen)1);
		errdp_("#", &__state->kfunl, (ftnlen)1);
		errdp_("#", &__state->kfunu, (ftnlen)1);
		sigerr_("SPICE(DTOUTOFRANGE)", (ftnlen)19);
		chkout_("PROP2B", (ftnlen)6);
		return 0;
	    }
	    __state->fx2 = __state->f * __state->x * __state->x;
	    stmp03_(&__state->fx2, &__state->c0, &__state->c1, &__state->c2, &
		    __state->c3);
	    __state->kfun = __state->x * (__state->br0 * __state->c1 + 
		    __state->x * (__state->b2rv * __state->c2 + __state->x * (
		    __state->bq * __state->c3)));
	}
    } else if (*dt > 0.) {
	__state->lower = 0.;
	__state->upper = __state->x;
	while(__state->kfun < *dt) {
	    __state->lower = __state->upper;
	    __state->upper *= 2.;
	    __state->oldx = __state->x;
	    d__1 = -__state->bound;
	    __state->x = brcktd_(&__state->upper, &d__1, &__state->bound);

/*           Make sure we are making progress. */

	    if (__state->x == __state->oldx) {
		__state->fx2 = __state->f * __state->bound * __state->bound;
		stmp03_(&__state->fx2, &__state->c0, &__state->c1, &
			__state->c2, &__state->c3);
		__state->kfunl = -__state->bound * (__state->br0 * 
			__state->c1 - __state->bound * (__state->b2rv * 
			__state->c2 - __state->bound * __state->bq * 
			__state->c3));
		__state->kfunu = __state->bound * (__state->br0 * __state->c1 
			+ __state->bound * (__state->b2rv * __state->c2 + 
			__state->bound * __state->bq * __state->c3));
		setmsg_("The input delta time (DT) has a value of #.  This i"
			"s beyond the range of DT for which we can reliably p"
			"ropagate states. The limits for this GM and initial "
			"state are from # to #. ", (ftnlen)178);
		errdp_("#", dt, (ftnlen)1);
		errdp_("#", &__state->kfunl, (ftnlen)1);
		errdp_("#", &__state->kfunu, (ftnlen)1);
		sigerr_("SPICE(DTOUTOFRANGE)", (ftnlen)19);
		chkout_("PROP2B", (ftnlen)6);
		return 0;
	    }
	    __state->fx2 = __state->f * __state->x * __state->x;
	    stmp03_(&__state->fx2, &__state->c0, &__state->c1, &__state->c2, &
		    __state->c3);
	    __state->kfun = __state->x * (__state->br0 * __state->c1 + 
		    __state->x * (__state->b2rv * __state->c2 + __state->x * 
		    __state->bq * __state->c3));
	}
    } else {
	vequg_(pvinit, &__state->c__6, pvprop);
	chkout_("PROP2B", (ftnlen)6);
	return 0;
    }

/*     Ok. We've bracketed the root.  Now for lack of anything more */
/*     clever, we just bisect to find the solution. */

/*     We add a loop counter so that we can ensure termination of the */
/*     loop below. */

/*     On some systems the computed midpoint is stored in an extended */
/*     precision register.  Thus the midpoint is always different from */
/*     UPPER and LOWER.  Yet when the new value of LOWER and UPPER */
/*     are assigned UPPER and LOWER do not change and hence the */
/*     loop fails to terminate.  With the loop counter we force */
/*     termination of the loop. */

/* Computing MIN */
/* Computing MAX */
    d__3 = __state->lower, d__4 = (__state->lower + __state->upper) / 2.;
    d__1 = __state->upper, d__2 = max(d__3,d__4);
    __state->x = min(d__1,d__2);
    __state->fx2 = __state->f * __state->x * __state->x;
    stmp03_(&__state->fx2, &__state->c0, &__state->c1, &__state->c2, &
	    __state->c3);
    __state->lcount = 0;
    __state->mostc = 1000;
    while(__state->x > __state->lower && __state->x < __state->upper && 
	    __state->lcount < __state->mostc) {
	__state->kfun = __state->x * (__state->br0 * __state->c1 + __state->x 
		* (__state->b2rv * __state->c2 + __state->x * __state->bq * 
		__state->c3));
	if (__state->kfun > *dt) {
	    __state->upper = __state->x;
	} else if (__state->kfun < *dt) {
	    __state->lower = __state->x;
	} else {
	    __state->upper = __state->x;
	    __state->lower = __state->x;
	}

/*        As soon as the bracketting values move away from */
/*        zero we can modify the count limit. */

	if (__state->mostc > 64) {
	    if (__state->upper != 0. && __state->lower != 0.) {
		__state->mostc = 64;
		__state->lcount = 0;
	    }
	}
/* Computing MIN */
/* Computing MAX */
	d__3 = __state->lower, d__4 = (__state->lower + __state->upper) / 2.;
	d__1 = __state->upper, d__2 = max(d__3,d__4);
	__state->x = min(d__1,d__2);
	__state->fx2 = __state->f * __state->x * __state->x;
	stmp03_(&__state->fx2, &__state->c0, &__state->c1, &__state->c2, &
		__state->c3);
	++__state->lcount;
    }

/*     With X in hand we simply compute BR, PC, VC, PCDOT and VCDOT */
/*     described in equations (1) --- (5) above. (Note, by our choice */
/*     of BOUND above, one can show that none of the computations */
/*     below can cause an overflow). */

    __state->x2 = __state->x * __state->x;
    __state->x3 = __state->x2 * __state->x;
    __state->br = __state->br0 * __state->c0 + __state->x * (__state->b2rv * 
	    __state->c1 + __state->x * (__state->bq * __state->c2));
    __state->pc = 1. - __state->qovr0 * __state->x2 * __state->c2;
    __state->vc = *dt - __state->bq * __state->x3 * __state->c3;
    __state->pcdot = -(__state->qovr0 / __state->br) * __state->x * 
	    __state->c1;
    __state->vcdot = 1. - __state->bq / __state->br * __state->x2 * 
	    __state->c2;

/*     ... and compute the linear combinations needed to get PVPROP */

    vlcom_(&__state->pc, __state->pos, &__state->vc, __state->vel, pvprop);
    vlcom_(&__state->pcdot, __state->pos, &__state->vcdot, __state->vel, &
	    pvprop[3]);
    chkout_("PROP2B", (ftnlen)6);
    return 0;
} /* prop2b_ */

