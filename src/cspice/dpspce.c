/* dpspce.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern dpspce_init_t __dpspce_init;
static dpspce_state_t* get_dpspce_state() {
	cspice_t* state =  __cspice_get_state();
	if (!state->dpspce)
		state->dpspce = __cspice_allocate_module(sizeof(
	dpspce_state_t), &__dpspce_init, sizeof(__dpspce_init));
	return state->dpspce;

}

/* $Procedure DPSPCE ( Propagate a two line element set for deep space ) */
/* Subroutine */ int dpspce_(doublereal *time, doublereal *geophs, doublereal 
	*elems, doublereal *state)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer s_rnge(char *, integer, char *, integer);
    double pow_dd(doublereal *, doublereal *), cos(doublereal), sqrt(
	    doublereal), sin(doublereal), d_mod(doublereal *, doublereal *), 
	    atan2(doublereal, doublereal);

    /* Local variables */
    extern /* Subroutine */ int zzdpinit_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *);
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    extern doublereal twopi_(void);
    extern /* Subroutine */ int vlcom_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *);
    extern doublereal halfpi_(void);
    extern /* Subroutine */ int latrec_(doublereal *, doublereal *, 
	    doublereal *, doublereal *);
    extern /* Subroutine */ int chkout_(char *, ftnlen);
    extern logical return_(void);
    extern /* Subroutine */ int zzdpsec_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    extern /* Subroutine */ int zzdpper_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *);

    /* Module state */
    dpspce_state_t* __state = get_dpspce_state();
/* $ Abstract */

/*     This routine propagates NORAD two-line element data for */
/*     earth orbiting deep space vehicles (a vehicle with an */
/*     orbital period more than 225 minutes). */

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

/*     EPHEMERIS */
/*     TWO LINE ELEMENTS */
/*     DEEP SPACE PROPAGATOR */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     TIME       I   Time for state evaluation in seconds past ephemeris */
/*                    epoch J2000. */
/*     GEOPHS     I   The array of geophysical constants */
/*     ELEMS      I   Array of orbit elements */
/*     STATE      O   State vector at TIME */

/* $ Detailed_Input */

/*     TIME        is the epoch in seconds past ephemeris epoch J2000 */
/*                 to produced a state from the input elements. */

/*     GEOPHS      is a collection of 8 geophysical constants needed */
/*                 for computing a state.  The order of these */
/*                 constants must be: */

/*                 GEOPHS(1) = J2 gravitational harmonic for earth */
/*                 GEOPHS(2) = J3 gravitational harmonic for earth */
/*                 GEOPHS(3) = J4 gravitational harmonic for earth */

/*                 These first three constants are dimensionless. */

/*                 GEOPHS(4) = KE: Square root of the GM for earth where */
/*                             GM is expressed in earth radii cubed per */
/*                             minutes squared. */

/*                 GEOPHS(5) = QO: Low altitude bound for atmospheric */
/*                             model in km. */

/*                 GEOPHS(6) = SO: High altitude bound for atmospheric */
/*                             model in km. */


/*                 GEOPHS(7) = RE: Equatorial radius of the earth in km. */


/*                 GEOPHS(8) = AE: Distance units/earth radius */
/*                             (normally 1) */

/*                 Below are currently recommended values for these */
/*                 items: */

/*                   J2 =    1.082616D-3 */
/*                   J3 =   -2.53881D-6 */
/*                   J4 =   -1.65597D-6 */

/*                 The next item is the square root of GM for the */
/*                 earth given in units of earth-radii**1.5/Minute */

/*                   KE =    7.43669161D-2 */

/*                 The next two items define the top and */
/*                 bottom of the atmospheric drag model */
/*                 used by the type 10 ephemeris type. */
/*                 Don't adjust these unless you understand */
/*                 the full implications of such changes. */

/*                   QO =  120.0D0 */
/*                   SO =   78.0D0 */

/*                 The ER value is the equatorial radius in km */
/*                 of the earth as used by NORAD. */

/*                   ER = 6378.135D0 */

/*                 The value of AE is the number of */
/*                 distance units per earth radii used by */
/*                 the NORAD state propagation software. */
/*                 The value is 1 unless you've got */
/*                 a very good understanding of the NORAD */
/*                 routine SGP4 and the affect of changing */
/*                 this value.. */

/*                   AE =    1.0D0 */

/*     ELEMS       is an array containing two-line element data */
/*                 as prescribed below. The elements XNDD6O and BSTAR */
/*                 must have been scaled by the proper exponent stored */
/*                 in the two line elements set.  Moreover, the */
/*                 various items must be converted to the units shown */
/*                 here. */

/*                    ELEMS (  1 ) = XNDT2O in radians/minute**2 */
/*                    ELEMS (  2 ) = XNDD6O in radians/minute**3 */
/*                    ELEMS (  3 ) = BSTAR */
/*                    ELEMS (  4 ) = XINCL  in radians */
/*                    ELEMS (  5 ) = XNODEO in radians */
/*                    ELEMS (  6 ) = EO */
/*                    ELEMS (  7 ) = OMEGAO in radians */
/*                    ELEMS (  8 ) = XMO    in radians */
/*                    ELEMS (  9 ) = XNO    in radians/minute */
/*                    ELEMS ( 10 ) = EPOCH of the elements in seconds */
/*                                   past ephemeris epoch J2000. */

/* $ Detailed_Output */

/*     STATE       A 6 vector containing the X, Y, Z, Vx, Vy, Vz */
/*                 coordinates in the inertial frame (double */
/*                 precision). */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This subroutine is an extensive rewrite of the SDP4 */
/*     routine as described in the Spacetrack 3 report.  All common */
/*     blocks were removed and all variables are explicitly defined. */

/*     The removal of common blocks causes the set of routines to */
/*     execute slower than the original version of SDP4.  However the */
/*     stability improves especially as concerns memory and */
/*     expanded internal documentation. */

/*     Trivial or redundant variables have been eliminated. */

/*       R         removed, occurrence replaced with RK */
/*       E6A       renamed TOL */
/*       THETA4    removed, relevant equation recast in Horner's form */
/*                 i.e. something like x^4 + x^2 -> x^2 ( x^2 + 1 ) */
/*       U         renamed UANG, U is now a euclidean 3 vector. */
/*       Ux,Uy,Uz  removed, replaced with 3-vector U */
/*       Vx,Vy,Vz  removed, replaced with 3-vector V */
/*       OMEGAQ    removed, usage replaced with OMEGAO */
/*       OMGDT     removed, same variable as OMGDOT, so all occurrences */
/*                 replaced with OMGDOT */
/*       SSL,SSG   replaced with the 5-vector SSX */
/*       SSH,SSE */
/*       SSI */

/*     Three functions present in the original Spacetrack report, ACTAN, */
/*     FMOD2P and THETAG, have been either replaced with an intrinsic */
/*     FORTRAN function (ACTAN -> DATAN2, FMOD2P -> DMOD) or recoded */
/*     using SPICELIB calls (THETAG). */

/*     The code at the end of this subroutine which calculates */
/*     orientation vectors, was replaced with a set of calls to */
/*     SPICELIB vector routines. */

/*     A direct comparison of output from the original Spacetrack 3 code */
/*     and these NAIF routines for the same elements and time parameters */
/*     will produce unacceptably different results. */

/* $ Examples */


/*   C---  Load the geophysical constants kernel and the leapsecond */
/*         kernel */
/*         CALL FURNSH( '/Users/ewright/lib/geophysical.ker' ) */
/*         CALL FURNSH( '/kernels/gen/lsk/naif0008.tls' ) */


/*   C---  Define a vehicle element array, TDRS 4 Geosynch */
/*         LINES( 1 ) = '1 19883U 89021B   97133.05943164 -.00000277  ' */
/*        .//           '00000-0  10000-3 0  3315' */
/*         LINES( 2 ) = '2 19883   0.5548  86.7278 0001786 312.2904 ' */
/*        .//           '172.2391  1.00269108202415' */


/*   C---  Identify the earliest first year for the elements */
/*         FRSTYR = 1988 */


/*   C---  Parse the elements to something SPICE can use */
/*         CALL GETELM ( FRSTYR, LINES, EPOCH, ELEMS ) */


/*   C---  Final time past epoch, 1400 mins (in seconds) */
/*         TF     = 1440.D0 * 60.D0 */

/*   C---  Step size for elements output 360 mins (in seconds) */
/*         DELT   = 360.D0  * 60.D0 */

/*   C---  Start time keyed off epoch */
/*         TIME   = EPOCH - 2.D0 * DELT */

/*         DO WHILE ( DABS(TIME - EPOCH) .LE. DABS(TF) ) */

/*            CALL DPSPCE ( TIME, GEOPHS, ELEMS, STATE ) */

/*            WRITE(*, FMT ='(7F17.8)' ) (TIME-EPOCH)/60.D0, */
/*        .                              (STATE(I),I=1,6) */

/*            TIME = TIME + DELT */

/*         END DO */


/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     Hoots, Felix R., Ronald L. Roehrich (31 December 1988). "Models */
/*     for Propagation of NORAD Element Sets". United States Department */
/*     of Defense Spacetrack Report (3). */

/* $ Author_and_Institution */

/*     E.D. Wright      (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 23-JAN-2013 (EDW) */

/*        Corrected initialization block error. The ZZDPINIT call */
/*        causes a side-effect required for each DPSPCE call. */
/*        The ZZDPINIT call now occurs outside the initialization */
/*        block. Note from designer, side-effects are bad. */

/*        Added proper citation for Hoots paper. */

/* -    SPICELIB Version 1.2.2, 22-AUG-2006 (EDW) */

/*        Replaced references to LDPOOL with references */
/*        to FURNSH. */

/* -    SPICELIB Version 1.2.1, DEC-27-2000 (EDW) */

/*       Corrected error in header documentation. Horner's Rule */
/*       not Butcher's. */

/* -    SPICELIB Version 1.2.0, MAR-24-1999 (EDW) */

/*       Documentation expanded to include modifications made */
/*       to private routines.  Some english errors corrected. */

/*       Alphabetized variable declaration lists. */

/*       Temporary variable TEMP removed.  OMGDOT argument added to */
/*       ZZDPSEC call. */

/* -    SPICELIB Version 1.1.0, OCT-05-1998 (WLT) */

/*        Forced initialization section until we can figure out */
/*        why it doesn't work on SUNs. */

/* -    SPICELIB Version 1.0.1, MAR-11-1998 (EDW) */

/*       Corrected error in header describing GEOPHS array. */

/* -    SPICELIB Version 1.0.0, NOV-11-1998 (EDW) */

/* -& */
/* $ Index_Entries */

/*     NORAD two line elements deep space evaluator */

/* -& */

/*     Local variables */


/*     Define parameters for convergence tolerance and the value for 2/3, */
/*     0 and 1. */


/*     The geophysical Quantities */


/*     Elements */


/*     Other quantities */


/*     SPICELIB routines */


/*     Save everything. */


/*     Set initialization flags */


/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    } else {
	chkin_("DPSPCE", (ftnlen)6);
    }

/*     If this is the very first time into this routine, set these */
/*     values. */

    if (__state->first) {
	__state->pix2 = twopi_();
	__state->pio2 = halfpi_();
	__state->first = FALSE_;
    }

/*     If initialization flag is FALSE, then this is not the first */
/*     call to this routine.  Check the stuff. */

    if (! __state->doinit) {

/*        Check whether the current and last constants and elements */
/*        match.  If not, we need to reinitialize everything */
/*        since the propagation is dependent on the value of these */
/*        arrays. */

	for (__state->i__ = 1; __state->i__ <= 8; ++__state->i__) {
	    if (__state->lstphs[(i__1 = __state->i__ - 1) < 8 && 0 <= i__1 ? 
		    i__1 : s_rnge("lstphs", i__1, "dpspce_", (ftnlen)547)] != 
		    geophs[(i__2 = __state->i__ - 1) < 8 && 0 <= i__2 ? i__2 :
		     s_rnge("geophs", i__2, "dpspce_", (ftnlen)547)]) {
		__state->doinit = TRUE_;
	    }
	}
	for (__state->i__ = 1; __state->i__ <= 10; ++__state->i__) {
	    if (__state->lstelm[(i__1 = __state->i__ - 1) < 10 && 0 <= i__1 ? 
		    i__1 : s_rnge("lstelm", i__1, "dpspce_", (ftnlen)556)] != 
		    elems[(i__2 = __state->i__ - 1) < 10 && 0 <= i__2 ? i__2 :
		     s_rnge("elems", i__2, "dpspce_", (ftnlen)556)]) {
		__state->doinit = TRUE_;
	    }
	}
    }

/*     Initialization block.  Always called on the initial entry and */
/*     anytime the geophysical or elements array changes. */

    if (__state->doinit) {
	__state->doinit = FALSE_;

/*        Retrieve the geophysical constants from the GEOPHS array */

	__state->xj2 = geophs[0];
	__state->xj3 = geophs[1];
	__state->xj4 = geophs[2];
	__state->xke = geophs[3];
	__state->qo = geophs[4];
	__state->so = geophs[5];
	__state->xkmper = geophs[6];
	__state->ae = geophs[7];

/*        Save the geophysical constants for later comparison */

	for (__state->i__ = 1; __state->i__ <= 8; ++__state->i__) {
	    __state->lstphs[(i__1 = __state->i__ - 1) < 8 && 0 <= i__1 ? i__1 
		    : s_rnge("lstphs", i__1, "dpspce_", (ftnlen)590)] = 
		    geophs[(i__2 = __state->i__ - 1) < 8 && 0 <= i__2 ? i__2 :
		     s_rnge("geophs", i__2, "dpspce_", (ftnlen)590)];
	}

/*        Unpack the elements array. */

	__state->bstar = elems[2];
	__state->xincl = elems[3];
	__state->xnodeo = elems[4];
	__state->eo = elems[5];
	__state->omegao = elems[6];
	__state->xmo = elems[7];
	__state->xno = elems[8];
	__state->epoch = elems[9];

/*        Save the elements for later comparison */

	for (__state->i__ = 1; __state->i__ <= 10; ++__state->i__) {
	    __state->lstelm[(i__1 = __state->i__ - 1) < 10 && 0 <= i__1 ? 
		    i__1 : s_rnge("lstelm", i__1, "dpspce_", (ftnlen)610)] = 
		    elems[(i__2 = __state->i__ - 1) < 10 && 0 <= i__2 ? i__2 :
		     s_rnge("elems", i__2, "dpspce_", (ftnlen)610)];
	}

/*        Set common variables, the init flag and calculate the */
/*        WGS-72 physical and geopotential constants */

/*        CK2 =  0.5   * J2 * AE^2 */
/*        CK4 = -0.375 * J4 * AE^4 */

/*        These are values calculated only once and then saved for */
/*        future access. */

/* Computing 2nd power */
	d__1 = __state->ae;
	__state->ck2 = __state->xj2 * .5 * (d__1 * d__1);
/* Computing 4th power */
	d__1 = __state->ae, d__1 *= d__1;
	__state->ck4 = __state->xj4 * -.375 * (d__1 * d__1);
/* Computing 4th power */
	d__1 = (__state->qo - __state->so) * __state->ae / __state->xkmper, 
		d__1 *= d__1;
	__state->qoms2t = d__1 * d__1;
	__state->s = __state->ae * (__state->so / __state->xkmper + 1.);

/*        Recover original mean motion (XNODP) and semimajor axis (AODP) */
/*        from input elements */

	d__1 = __state->xke / __state->xno;
	__state->a1 = pow_dd(&d__1, &__state->c_b19);
	__state->cosio = cos(__state->xincl);
/* Computing 2nd power */
	d__1 = __state->cosio;
	__state->theta2 = d__1 * d__1;
	__state->x3thm1 = __state->theta2 * 3. - 1.;
/* Computing 2nd power */
	d__1 = __state->eo;
	__state->betao2 = 1. - d__1 * d__1;
	__state->betao = sqrt(__state->betao2);
/* Computing 2nd power */
	d__1 = __state->a1;
	__state->del1 = __state->ck2 * 1.5 * __state->x3thm1 / (d__1 * d__1 * 
		__state->betao * __state->betao2);
	__state->ao = __state->a1 * (1. - __state->del1 * (__state->del1 * (
		__state->del1 * 1.654320987654321 + 1.) + .33333333333333331))
		;
/* Computing 2nd power */
	d__1 = __state->ao;
	__state->delo = __state->ck2 * 1.5 * __state->x3thm1 / (d__1 * d__1 * 
		__state->betao * __state->betao2);
	__state->xnodp = __state->xno / (__state->delo + 1.);
	__state->aodp = __state->ao / (1. - __state->delo);

/*        For perigee below 156 km, the values of S and QOMS2T are */
/*        altered */

	__state->s4 = __state->s;
	__state->qoms24 = __state->qoms2t;
	__state->perige = (__state->aodp * (1. - __state->eo) - __state->ae) *
		 __state->xkmper;
	if (__state->perige < 156.) {
	    __state->s4 = __state->perige - 78.;
	    if (__state->perige > 98.) {
/* Computing 4th power */
		d__1 = (120. - __state->s4) * __state->ae / __state->xkmper, 
			d__1 *= d__1;
		__state->qoms24 = d__1 * d__1;
		__state->s4 = __state->s4 / __state->xkmper + __state->ae;
	    } else {
		__state->s4 = 20.;
	    }
	}
/* Computing 2nd power */
	d__1 = __state->aodp;
/* Computing 2nd power */
	d__2 = __state->betao2;
	__state->pinvsq = 1. / (d__1 * d__1 * (d__2 * d__2));
	__state->tsi = 1. / (__state->aodp - __state->s4);
	__state->eta = __state->aodp * __state->eo * __state->tsi;
/* Computing 2nd power */
	d__1 = __state->eta;
	__state->etasq = d__1 * d__1;
	__state->eeta = __state->eo * __state->eta;
	__state->psisq = (d__1 = 1. - __state->etasq, abs(d__1));
/* Computing 4th power */
	d__1 = __state->tsi, d__1 *= d__1;
	__state->coef = __state->qoms24 * (d__1 * d__1);
	__state->coef1 = __state->coef / pow_dd(&__state->psisq, &
		__state->c_b20);
	__state->c2 = __state->coef1 * __state->xnodp * (__state->aodp * (
		__state->etasq * 1.5 + 1. + __state->eeta * (__state->etasq + 
		4.)) + __state->ck2 * .75 * __state->tsi / __state->psisq * 
		__state->x3thm1 * (__state->etasq * 3. * (__state->etasq + 8.)
		 + 8.));
	__state->c1 = __state->bstar * __state->c2;
	__state->sinio = sin(__state->xincl);
/* Computing 3rd power */
	d__1 = __state->ae;
	__state->a3ovk2 = -__state->xj3 / __state->ck2 * (d__1 * (d__1 * d__1)
		);
	__state->x1mth2 = 1. - __state->theta2;
	__state->c4 = __state->xnodp * 2. * __state->coef1 * __state->aodp * 
		__state->betao2 * (__state->eta * (__state->etasq * .5 + 2.) 
		+ __state->eo * (__state->etasq * 2. + .5) - __state->ck2 * 
		2. * __state->tsi / (__state->aodp * __state->psisq) * (
		__state->x3thm1 * -3. * (1. - __state->eeta * 2. + 
		__state->etasq * (1.5 - __state->eeta * .5)) + 
		__state->x1mth2 * .75 * (__state->etasq * 2. - __state->eeta *
		 (__state->etasq + 1.)) * cos(__state->omegao * 2.)));
	__state->temp1 = __state->ck2 * 3. * __state->pinvsq * __state->xnodp;
	__state->temp2 = __state->temp1 * __state->ck2 * __state->pinvsq;
	__state->temp3 = __state->ck4 * 1.25 * __state->pinvsq * 
		__state->pinvsq * __state->xnodp;
	__state->xmdot = __state->xnodp + __state->temp1 * .5 * 
		__state->betao * __state->x3thm1 + __state->temp2 * .0625 * 
		__state->betao * (__state->theta2 * (__state->theta2 * 137. - 
		78.) + 13.);
	__state->x1m5th = 1. - __state->theta2 * 5.;
	__state->omgdot = __state->temp1 * -.5 * __state->x1m5th + 
		__state->temp2 * .0625 * (__state->theta2 * (__state->theta2 *
		 395. - 114.) + 7.) + __state->temp3 * (__state->theta2 * (
		__state->theta2 * 49. - 36.) + 3.);
	__state->xhdot1 = -__state->temp1 * __state->cosio;
	__state->xnodot = __state->xhdot1 + (__state->temp2 * .5 * (4. - 
		__state->theta2 * 19.) + __state->temp3 * 2. * (3. - 
		__state->theta2 * 7.)) * __state->cosio;
	__state->xnodcf = __state->betao2 * 3.5 * __state->xhdot1 * 
		__state->c1;
	__state->t2cof = __state->c1 * 1.5;
	__state->xlcof = __state->a3ovk2 * .125 * __state->sinio * (
		__state->cosio * 5. + 3.) / (__state->cosio + 1.);
	__state->aycof = __state->a3ovk2 * .25 * __state->sinio;
	__state->x7thm1 = __state->theta2 * 7. - 1.;
    }
    zzdpinit_(&__state->aodp, &__state->xmdot, &__state->omgdot, &
	    __state->xnodot, &__state->xnodp, elems);

/*     Get the time since the EPOCH in minutes. */

    __state->tsince = (*time - __state->epoch) / 60.;

/*     Update for secular gravity and atmospheric drag */

    __state->xmdf = __state->xmo + __state->xmdot * __state->tsince;
    __state->omgadf = __state->omegao + __state->omgdot * __state->tsince;
    __state->xnoddf = __state->xnodeo + __state->xnodot * __state->tsince;
    __state->tsq = __state->tsince * __state->tsince;
    __state->xnode = __state->xnoddf + __state->xnodcf * __state->tsq;
    __state->tempa = 1. - __state->c1 * __state->tsince;
    __state->tempe = __state->bstar * __state->c4 * __state->tsince;
    __state->templ = __state->t2cof * __state->tsq;
    __state->xn = __state->xnodp;

/*     Calculate the secular terms. */

    zzdpsec_(&__state->xmdf, &__state->omgadf, &__state->xnode, &__state->em, 
	    &__state->xinc, &__state->xn, &__state->tsince, elems, &
	    __state->omgdot);
    d__1 = __state->xke / __state->xn;
/* Computing 2nd power */
    d__2 = __state->tempa;
    __state->a = pow_dd(&d__1, &__state->c_b19) * (d__2 * d__2);
    __state->e = __state->em - __state->tempe;
    __state->xmam = __state->xmdf + __state->xnodp * __state->templ;

/*     Calculate the periodic terms. */

    zzdpper_(&__state->tsince, &__state->e, &__state->xinc, &__state->omgadf, 
	    &__state->xnode, &__state->xmam);
    __state->xl = __state->xmam + __state->omgadf + __state->xnode;
    __state->xn = __state->xke / pow_dd(&__state->a, &__state->c_b22);

/*      Long period periodics */

    __state->axn = __state->e * cos(__state->omgadf);
/* Computing 2nd power */
    d__1 = __state->e;
    __state->temp = 1. / (__state->a * (1. - d__1 * d__1));
    __state->xll = __state->temp * __state->xlcof * __state->axn;
    __state->aynl = __state->temp * __state->aycof;
    __state->xlt = __state->xl + __state->xll;
    __state->ayn = __state->e * sin(__state->omgadf) + __state->aynl;

/*     Solve Kepler's equation */

/*           U = EPW - AXN * SIN(EPW)  +  AYN * COS(EPW) */

/*     Where */

/*        AYN  = E * SIN(OMEGA)  +   AYNL */
/*        AXN  = E * COS(OMEGA) */

/*     And */

/*        AYNL =  -0.50D0 * SINIO * AE * J3 / (J2 * A * (1.0D0  -  E^2)) */


/*     Get the mod division of CAPU with 2 Pi */

    d__1 = __state->xlt - __state->xnode;
    __state->capu = d_mod(&d__1, &__state->pix2);
    if (__state->capu < 0.) {
	__state->capu += __state->pix2;
    }

/*     Set initial states for the Kepler solution */

    __state->epw = __state->capu;
    __state->cont = TRUE_;
    while(__state->cont) {
	__state->temp2 = __state->epw;
	__state->sinepw = sin(__state->temp2);
	__state->cosepw = cos(__state->temp2);
	__state->temp3 = __state->axn * __state->sinepw;
	__state->temp4 = __state->ayn * __state->cosepw;
	__state->temp5 = __state->axn * __state->cosepw;
	__state->temp6 = __state->ayn * __state->sinepw;
	__state->epw = (__state->capu - __state->temp4 + __state->temp3 - 
		__state->temp2) / (1. - __state->temp5 - __state->temp6) + 
		__state->temp2;

/*        Test for convergence against the defined tolerance */

	if ((d__1 = __state->epw - __state->temp2, abs(d__1)) <= 1e-6) {
	    __state->cont = FALSE_;
	}
    }

/*     Short period preliminary quantities */

    __state->ecose = __state->temp5 + __state->temp6;
    __state->esine = __state->temp3 - __state->temp4;
    __state->elsq = __state->axn * __state->axn + __state->ayn * __state->ayn;
    __state->temp = 1. - __state->elsq;
    __state->pl = __state->a * __state->temp;
    __state->rk = __state->a * (1. - __state->ecose);
    __state->temp1 = 1. / __state->rk;
    __state->rdot = __state->xke * sqrt(__state->a) * __state->esine * 
	    __state->temp1;
    __state->rfdot = __state->xke * sqrt(__state->pl) * __state->temp1;
    __state->temp2 = __state->a * __state->temp1;
    __state->betal = sqrt(__state->temp);
    __state->temp3 = 1. / (__state->betal + 1.);
    __state->cosu = __state->temp2 * (__state->cosepw - __state->axn + 
	    __state->ayn * __state->esine * __state->temp3);
    __state->sinu = __state->temp2 * (__state->sinepw - __state->ayn - 
	    __state->axn * __state->esine * __state->temp3);

/*     Compute the angle from the x-axis of the point ( COSU, SINU ) */

    if (__state->sinu != 0. || __state->cosu != 0.) {
	__state->uang = atan2(__state->sinu, __state->cosu);
	if (__state->uang < 0.) {
	    __state->uang += __state->pix2;
	}
    } else {
	__state->uang = 0.;
    }
    __state->sin2u = __state->sinu * 2. * __state->cosu;
    __state->cos2u = __state->cosu * 2. * __state->cosu - 1.;
    __state->temp1 = __state->ck2 * (1. / __state->pl);
    __state->temp2 = __state->temp1 * (1. / __state->pl);

/*     Update for short periodics */

    __state->rk = __state->rk * (1. - __state->temp2 * 1.5 * __state->betal * 
	    __state->x3thm1) + __state->temp1 * .5 * __state->x1mth2 * 
	    __state->cos2u;
    __state->uk = __state->uang - __state->temp2 * .25 * __state->x7thm1 * 
	    __state->sin2u;
    __state->xnodek = __state->xnode + __state->temp2 * 1.5 * __state->cosio *
	     __state->sin2u;
    __state->xinck = __state->xinc + __state->temp2 * 1.5 * __state->cosio * 
	    __state->sinio * __state->cos2u;
    __state->rdotk = __state->rdot - __state->xn * __state->temp1 * 
	    __state->x1mth2 * __state->sin2u;
    __state->rfdotk = __state->rfdot + __state->xn * __state->temp1 * (
	    __state->x1mth2 * __state->cos2u + __state->x3thm1 * 1.5);

/*     Orientation vectors are calculated by */

/*     U = M sin(uk) + N cos(uk) */
/*     V = M cos(uk) - N sin(uk) */

/*     Where M and N are euclidean 3 vectors */

/*     M = (-sin(xnodek)cos(xinck), cos(xnodek)cos(xinck), sin(xinck) ) */
/*     N = (           cos(xnodek), sin(xnodek)          , 0          ) */

    __state->sinuk = sin(__state->uk);
    __state->cosuk = cos(__state->uk);

/*     Use LATREC to generate M and N.  M is a latitude to rectangle */
/*     conversion of a unit vector where PI/2 + XNODEK is the longitude */

    d__1 = __state->pio2 + __state->xnodek;
    latrec_(&__state->c_b23, &d__1, &__state->xinck, __state->m);
    latrec_(&__state->c_b23, &__state->xnodek, &__state->c_b25, __state->n);

/*     Sum the components to obtain U and V */

    vlcom_(&__state->sinuk, __state->m, &__state->cosuk, __state->n, 
	    __state->u);
    d__1 = -__state->sinuk;
    vlcom_(&__state->cosuk, __state->m, &d__1, __state->n, __state->v);

/*     Determine the position and velocity then pack the STATE vector */
/*     with value scaled to KM and KPS. */

/*     R = RK    U +        0 V */
/*     V = RKDOT U + RK RFDOT V */

    __state->scale = __state->xkmper / __state->ae;
    d__1 = __state->rk * __state->scale;
    vlcom_(&d__1, __state->u, &__state->c_b25, __state->v, state);

/*     Now scale to KPS for the velocity component */

    __state->scale /= 60.;
    d__1 = __state->rdotk * __state->scale;
    d__2 = __state->rfdotk * __state->scale;
    vlcom_(&d__1, __state->u, &d__2, __state->v, &state[3]);

/*     All done now.... */

    chkout_("DPSPCE", (ftnlen)6);
    return 0;
} /* dpspce_ */

