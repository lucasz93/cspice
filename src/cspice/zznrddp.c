/* zznrddp.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


static inline zznrddp_state_t* get_zznrddp_state(cspice_t* state) {
	if (!state->zznrddp)
		state->zznrddp = __cspice_allocate_module(sizeof(
	zznrddp_state_t), 0, 0);
	return state->zznrddp;

}

/* $Procedure ZZNRDDP ( Shell for deep space entry points ) */
/* Subroutine */ int zznrddp_0_(cspice_t* __global_state, int n__, doublereal 
	*ao, doublereal *elems, doublereal *em, doublereal *omgasm, 
	doublereal *omgdot, doublereal *t, doublereal *xinc, doublereal *xll, 
	doublereal *xlldot, doublereal *xn, doublereal *xnodes, doublereal *
	xnodot, doublereal *xnodp)
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(f2c_state_t*, doublereal), sin(f2c_state_t*, doublereal), cos(
	    f2c_state_t*, doublereal), d_mod(f2c_state_t*, doublereal *, 
	    doublereal *), atan2(f2c_state_t*, doublereal, doublereal);

    /* Local variables */
    extern /* Subroutine */ int zzsecprt_(cspice_t*, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern doublereal twopi_(cspice_t*);
    extern doublereal pi_(cspice_t*);
    extern doublereal j2000_(cspice_t*);
    extern doublereal j1950_(cspice_t*);
    extern logical return_(cspice_t*);
    extern doublereal spd_(cspice_t*);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);

    /* Module state */
    zznrddp_state_t* __state = get_zznrddp_state(__global_state);
/* $ Abstract */

/*    This subroutine is a shell for the routines needed by DPSPCE */
/*    for calculating deep space effects on a vehicle. */

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

/*     TWO LINE ELEMENTS */
/*     SPACETRACK */
/*     DEEP SPACE */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     AO         I   Entry ZZDPINIT, Original semimajor axis */
/*     ELEMS      I   Entry ZZDPINIT, Array of orbit elements */
/*                      "   ZZDPSEC */
/*     EM         I   Entry ZZDPSEC,  Perturbed eccentricity of the orbit */
/*                      "   ZZDPPER   at time T */
/*     OMGASM     I   Entry ZZDPSEC   Perturbed argument of perigee */
/*                      "   ZZDPPER */
/*     OMGDOT     I   Entry ZZDPINIT, Time rate of change of arg of */
/*                      "   ZZDPSEC   perigee */
/*     T          I   Entry ZZDPSEC,  Time of state evaluation */
/*                      "   ZZDPPER */
/*     XINC       I   Entry ZZDPSEC,  Perturbed inclination of the orbit */
/*                      "   ZZDPPER   plane at time T */
/*     XLL        I   Entry ZZDPSEC   Long-period periodic term */
/*     XLLDOT     I   Entry ZZDPINIT, Time rate of change of XLL */
/*     XN         I   Entry ZZDPSEC   Perturbed mean motion of the orbit */
/*                                    at time T */
/*     XNODES     I   Entry ZZDPSEC,  Perturbed argument of ascending */
/*                      "   ZZDPPER   node */
/*     XNODOT     I   Entry ZZDPINIT, Time rate of change of mean motion */
/*     XNODP      I   Entry ZZDPINIT, Original mean motion */

/* $ Detailed_Input */

/*     AO          the original semimajor axis of the orbit. */

/*     ELEMS       is an array containing two-line element data */
/*                 as prescribed below. The elements XNDD6O and BSTAR */
/*                 must already be scaled by the proper exponent stored */
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

/*     EM          is the perturbed eccentricity from the mean */
/*                 eccentricity at epoch at time T. */

/*     OMGASM      the value of the argument of perigee after the */
/*                 perturbations at the time of interest are */
/*                 added */

/*     OMGDOT      the time derivative of the argument of perigee */

/*     T           is the total time from the epoch, in minutes, of the */
/*                 element set at which to calculate the state. */

/*     XINC        is the perturbed inclination of the orbit plane from */
/*                 the mean inclination at the epoch at time T */

/*     XLL         a long-period periodic term dependent on inclination, */
/*                 eccentricity and argument of periapsis */

/*     XLLDOT      the time derivative of the XLL long-period term */

/*     XN          is the perturbed mean motion from the 'mean' mean */
/*                 motion at epoch at time T. */

/*     XNODES      is the value of the argument of the ascending node */
/*                 after the perturbations at the time of interest are */
/*                 added. */

/*     XNODOT      the time derivative of the mean motion */

/*     XNODP       original mean motion of the orbit. */

/* $ Detailed_Output */

/*     None */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This subroutine is a shell for the entry points used by the */
/*     propagator for deep space orbits, where a deep space orbit is one */
/*     which has a period greater the 225 minutes.  The entry points */
/*     are */

/*     ZZDPINIT - initialize variables for the deep space regime */
/*     ZZDPSEC  - calculates and updates secular perturbation terms */
/*     ZZDPPER  - calculates and updates periodic perturbation terms */
/*                particularly as caused by the sun and the moon */

/*     The names of several constants defined in the Spacetrack 3 report */
/*     have been changed. */

/*     D2201 to DG( 1  ) */
/*     D2211 to DG( 2  ) */
/*     D3210 to DG( 3  ) */
/*     D3222 to DG( 4  ) */
/*     D4410 to DG( 5  ) */
/*     D4422 to DG( 6  ) */
/*     D5220 to DG( 7  ) */
/*     D5232 to DG( 8  ) */
/*     D5421 to DG( 9  ) */
/*     D5433 to DG( 10 ) */

/*     The names of variables changed from the Spacetrack 3 report */

/*     DEL1  to  DEL( 1 ) */
/*     DEL2  to  DEL( 2 ) */
/*     DEL3  to  DEL( 3 ) */
/*     SSL   to  SSX( 1 ) */
/*     SSG   to  SSX( 2 ) */
/*     SSH   to  SSX( 3 ) */
/*     SSE   to  SSX( 4 ) */
/*     SSI   to  SSX( 5 ) */
/*     OMGDT to  OMGDOT */

/*     The entry point ZZDPPER was modified to insure that the */
/*     perturbations on the elements are zero at the epoch.  This was */
/*     not correctly handled in the Spacetrack 3 report. */

/* $ Examples */

/*     Never call this subroutine directly. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     Hoots, Felix R., Ronald L. Roehrich (31 December 1988). "Models */
/*     for Propagation of NORAD Element Sets". United States Department */
/*     of Defense Spacetrack Report (3). */

/*     Vallado, David A., Paul Crawford, Richard Hujsak, and */
/*     Kelso, T. S., "Revisiting Spacetrack Report #3," AIAA/AAS */
/*     Astrodynamics Specialist Conference, Keystone, CO, Aug 2006. */

/* $ Author_and_Institution */

/*     E.D. Wright      (JPL) */
/*     W.L. Taber       (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.1.0, 03-JUL-2016 (EDW) */

/*        The "Revisiting Spacetrack Report #3" by Vallado et. al. */
/*        indicates the negative inclination modification as a mistake. */
/*        That code was removed. */

/*        Eliminated bug in ZZDPINIT that allowed NaN contaimination */
/*        for zero inclination orbits. */

/* -    SPICELIB Version 2.0.0, 20-JAN-2012 (EDW) */

/*        Eliminated use of the DOPERT boolean in ZZDPINIT. */
/*        Refer to that entry point "Version" section for details. */

/*        Added proper citation for Spacetrack 3 (Hoots) and */
/*        Revisiting Spacetrak 3 (Vallado). */

/*        Added proper Declarations section. */

/* -    SPICELIB Version 1.5.1, 19-SEP-2006 (EDW) */

/*        Added text to previously empty Declarations section */
/*        in ZZDPINIT, ZZDPPER, ZZDPSEC. */

/* -    SPICELIB Version 1.5.0, 20-JAN-1999 (EDW) (WLT) */

/*        OMGDOT, named in an ENTRY point argument list */
/*        was not passed via an argument list. Solaris exhibited a */
/*        bus error because of this situation. All ENTRY point */
/*        arguments are passed only by argument lists and are declared */
/*        in the umbrella subroutine's, ZZNRDDP, argument list. */

/*        Combined the various SSL, SSG, SSH, SSI, SSE variables into */
/*        the vector SSX. */

/*        Removed the dependency upon the UTC/ET leapsecond kernel. */

/*        Alphabetized all variable declaration lists. */

/*        All arguments passed through entry points listed as arguments */
/*        of ZZNRDDP. OMGDT renamed OMGDOT to be consistent with other */
/*        deep space two line element routines. */

/* -    SPICELIB Version 1.0.0, 1-APR-1997 (EDW) */

/* -& */
/* $ Index_Entries */

/*     two line element set */

/* -& */

/*     Local variables */


/*     SPICELIB functions */


/*     Define rather a large number of local parameters. */


/*     Save everything just to be sure. */


/*     Standard SPICE error handling. */

    /* Parameter adjustments */
    if (elems) {
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_zzdpinit;
	case 2: goto L_zzdpsec;
	case 3: goto L_zzdpper;
	}

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "NRDDP", (ftnlen)5);
    }

/*     This routine should never be called. If this routine is called, */
/*     an error is signalled. */

    setmsg_(__global_state, "NRDDP: You called an entry which performs no ru"
	    "n-time function. This may indicate a bug. Please check the docum"
	    "entation for the subroutine ZZNRDDP.", (ftnlen)147);
    sigerr_(__global_state, "SPICE(EVILBOGUSENTRY)", (ftnlen)21);
    chkout_(__global_state, "NRDDP", (ftnlen)5);
    return 0;
/* $Procedure ZZDPINIT (Initialize deep space algorithm and variables ) */

L_zzdpinit:
/* $ Abstract */

/*     Entrance for deep space initialization.  This section is called */
/*     once per element set. */

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

/*     KEYWORD */

/* $ Declarations */

/*     None. */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     AO         I   Original semimajor axis */
/*     XLLDOT     I   Time rate of change of XLL */
/*     OMGDOT     I   Time rate of change of argument of perigee */
/*     XNODOT     I   Time rate of change of mean motion */
/*     XNODP      I   Original mean motion */
/*     ELEMS      I   Array of orbit elements */

/* $ Detailed_Input */

/*     AO          the original semimajor axis of the orbit. */

/*     XLLDOT      the time derivative of the XLL long-period term */

/*     OMGDOT      the time derivative of the argument of perigee */

/*     XNODOT      the time derivative of the mean motion */

/*     XNODP       original mean motion of the elements */

/*     ELEMS       is an array containing two-line element data */
/*                 as prescribed below. The elements XNDD6O and BSTAR */
/*                 must already be scaled by the proper exponent stored */
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

/*     No direct output. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine only initializes non-time dependent variables and */
/*     sets flags concerning whether the orbit is synchronous or */
/*     experiences resonance effects.  It should be called once per */
/*     element set. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     1)  This routine should only be called by DPSPCE when propagating */
/*         two line element sets. */

/* $ Literature_References */

/*     Hoots, Felix R., Ronald L. Roehrich (31 December 1988). "Models */
/*     for Propagation of NORAD Element Sets". United States Department */
/*     of Defense Spacetrack Report (3). */

/*     Vallado, David A., Paul Crawford, Richard Hujsak, and */
/*     Kelso, T. S., "Revisiting Spacetrack Report #3," AIAA/AAS */
/*     Astrodynamics Specialist Conference, Keystone, CO, Aug 2006. */

/* $ Author_and_Institution */

/*     E.D. Wright      (JPL) */
/*     W.L. Taber       (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.1.0, 27-JUN-2016 (EDW) */

/*        Eliminated bug that allowed NaN contaimination for zero */
/*        inclination orbits. New code avoids calculating 1/SINIQ for */
/*        SINIQ = 0. */

/* -    SPICELIB Version 2.0.0, 02-MAR-2011 (EDW) */

/*        Eliminated use of the DOPERT boolean. This algorithm used */
/*        that variable to zero-out the perturbations at epoch (T = 0). */
/*        The original code implementation introduced a logic error */
/*        such that the state of DOPERT was correct only for */
/*        runs involving a single vehicle TLE. */

/*        The "Revisiting Spacetrack Report #3" by Vallado et. al. */
/*        indicates the perturbation zeroing is a mistake. That */
/*        operation was removed. */

/* -    SPICELIB Version 1.5.1, 19-SEP-2006 (EDW) */

/*        Added text to previously empty Declarations section */
/*        in ZZDPINIT, ZZDPPER, ZZDPSEC. */

/* -    SPICELIB Version 1.5.0, 20-JAN-1999 (EDW) (WLT) */

/*        OMGDOT, named in an ENTRY point argument list */
/*        was not passed via an argument list.  Solaris exhibited a */
/*        bus error because of this situation.  All ENTRY point */
/*        arguments are passed only by argument lists and are declared */
/*        in the umbrella subroutine's, ZZNRDDP, argument list. */

/*        Combined the various SSL, SSG, SSH, SSI, SSE variables into */
/*        the vector SSX. */

/*        Removed the dependency upon the UTC/ET leapsecond kernel. */

/*        Alphabetized all variable declaration lists. */

/*        All arguments passed through entry points listed as arguments */
/*        of ZZNRDDP.  OMGDT renamed OMGDOT to be consistent with other */
/*        deep space two line element routines. */

/* -    SPICELIB Version 1.0.0, APR-30-1997 (EDW) */


/* -& */
/* $ Index_Entries */

/*     two line elements, deep space, initialize */

/* -& */
    __state->pix1 = pi_(__global_state);
    __state->pix2 = twopi_(__global_state);

/*     Unpack the elements array. */

    __state->xincl = elems[3];
    __state->xnodeo = elems[4];
    __state->eo = elems[5];
    __state->omegao = elems[6];
    __state->xmo = elems[7];

/*     Calculate intermediate values */

/* Computing 2nd power */
    d__1 = __state->eo;
    __state->eqsq = d__1 * d__1;
    __state->bsq = 1. - __state->eqsq;
    __state->rteqsq = sqrt(&__global_state->f2c, __state->bsq);
    __state->siniq = sin(&__global_state->f2c, __state->xincl);
    __state->cosiq = cos(&__global_state->f2c, __state->xincl);
/* Computing 2nd power */
    d__1 = __state->cosiq;
    __state->cosq2 = d__1 * d__1;
    __state->sinomo = sin(&__global_state->f2c, __state->omegao);
    __state->cosomo = cos(&__global_state->f2c, __state->omegao);

/*     This section of code was previously performed by the THETAG */
/*     function.  The epoch of the elements is defined in seconds since */
/*     J2000.  It is necessary to calculate the number of days which have */
/*     elapsed since the Jan 0.0 1950 reference date which is */
/*     Dec 31 1949 00:00:00 UTC ( J1950 - 1 ).  First extract the epoch */
/*     from the ELEMS array and place it in the first entry of a working */
/*     array. */

    __state->et = elems[9];

/*     Convert the ET seconds past the J2000 epoch to the Julian */
/*     date TDB. */

    __state->jdtdb = j2000_(__global_state) + __state->et / spd_(
	    __global_state);

/*     How many days since the 1950 reference? Using SPICE standard */
/*     leapseconds the difference between TDB and UTC in 1950 is 32.184 */
/*     seconds.  So we compute JDTDB corresponding to the UTC 1950 */
/*     epoch.  We call this JDTDB epoch ---JDUT50. Then we get the days */
/*     since 1950 by simple arithmetic. */

    __state->jdut50 = j1950_(__global_state) - 1. + 32.184 / spd_(
	    __global_state);
    __state->ds50 = __state->jdtdb - __state->jdut50;

/*     What is the Earth's right ascension of the epoch?  We know the */
/*     value at the JD1950-1 reference date, so add the number of radians */
/*     the Earth has rotated through since then.  MOD this value with */
/*     2*PI to get the right ascension for the epoch.  This technique may */
/*     not be the best way to get this value. */

    __state->theta = __state->ds50 * 6.3003880987 + 1.72944494;
    __state->thgr = d_mod(&__global_state->f2c, &__state->theta, &
	    __state->pix2);

/*     THGR should have a domain between 0 and 2 Pi. */

    if (__state->thgr < 0.) {
	__state->thgr += __state->pix2;
    }

/*     Set some operation variables. */

    __state->eq = __state->eo;
    __state->xnq = *xnodp;
    __state->aqnv = 1. / *ao;
    __state->xqncl = __state->xincl;
    __state->xmao = __state->xmo;
    __state->sinq = sin(&__global_state->f2c, __state->xnodeo);
    __state->cosq = cos(&__global_state->f2c, __state->xnodeo);

/*     Initialize lunar solar terms */

    __state->day = __state->ds50 + 18261.5;
    if (__state->day != __state->preep) {
	__state->preep = __state->day;
	__state->xnodce = 4.523602 - __state->day * 9.2422029e-4;
	__state->stem = sin(&__global_state->f2c, __state->xnodce);
	__state->ctem = cos(&__global_state->f2c, __state->xnodce);
	__state->zcosil = .91375164 - __state->ctem * .03568096;
/* Computing 2nd power */
	d__1 = __state->zcosil;
	__state->zsinil = sqrt(&__global_state->f2c, 1. - d__1 * d__1);
	__state->zsinhl = __state->stem * .089683511 / __state->zsinil;
/* Computing 2nd power */
	d__1 = __state->zsinhl;
	__state->zcoshl = sqrt(&__global_state->f2c, 1. - d__1 * d__1);
	__state->c__ = __state->day * .2299715 + 4.7199672;
	__state->gam = __state->day * .001944368 + 5.8351514;
	d__1 = __state->c__ - __state->gam;
	__state->zmol = d_mod(&__global_state->f2c, &d__1, &__state->pix2);
	if (__state->zmol < 0.) {
	    __state->zmol += __state->pix2;
	}
	__state->zx = __state->stem * .39785416 / __state->zsinil;
	__state->zy = __state->zcoshl * __state->ctem + __state->zsinhl * 
		.91744867 * __state->stem;

/*        Compute the angle from the x-axis of the point */

	if (__state->zx != 0. || __state->zy != 0.) {
	    __state->zx = atan2(&__global_state->f2c, __state->zx, 
		    __state->zy);
	    if (__state->zx < 0.) {
		__state->zx += __state->pix2;
	    }
	} else {
	    __state->zx = 0.;
	}
	__state->zx = __state->gam + __state->zx - __state->xnodce;
	__state->zcosgl = cos(&__global_state->f2c, __state->zx);
	__state->zsingl = sin(&__global_state->f2c, __state->zx);
	__state->zmos = __state->day * .017201977 + 6.2565837;
	__state->zmos = d_mod(&__global_state->f2c, &__state->zmos, &
		__state->pix2);
	if (__state->zmos < 0.) {
	    __state->zmos += __state->pix2;
	}
    }

/*     Do solar terms.  Start with the constant values. */

    __state->zcosg = .1945905;
    __state->zsing = -.98088458;
    __state->zcosi = .91744867;
    __state->zsini = .39785416;
    __state->zcosh = __state->cosq;
    __state->zsinh = __state->sinq;
    __state->cc = 2.9864797e-6;
    __state->zn = 1.19459e-5;
    __state->ze = .01675;
    __state->xnoi = 1. / __state->xnq;

/*     Initialize solar and lunar terms.  The procedure will */
/*     first initialize just the solar, then the lunar, then */
/*     reinitialize the solar with the added lunar effect. */

    for (__state->i__ = 1; __state->i__ <= 2; ++__state->i__) {

/*        Solar. */

	__state->a1 = __state->zcosg * __state->zcosh + __state->zsing * 
		__state->zcosi * __state->zsinh;
	__state->a3 = -__state->zsing * __state->zcosh + __state->zcosg * 
		__state->zcosi * __state->zsinh;
	__state->a7 = -__state->zcosg * __state->zsinh + __state->zsing * 
		__state->zcosi * __state->zcosh;
	__state->a8 = __state->zsing * __state->zsini;
	__state->a9 = __state->zsing * __state->zsinh + __state->zcosg * 
		__state->zcosi * __state->zcosh;
	__state->a10 = __state->zcosg * __state->zsini;
	__state->a2 = __state->cosiq * __state->a7 + __state->siniq * 
		__state->a8;
	__state->a4 = __state->cosiq * __state->a9 + __state->siniq * 
		__state->a10;
	__state->a5 = -__state->siniq * __state->a7 + __state->cosiq * 
		__state->a8;
	__state->a6 = -__state->siniq * __state->a9 + __state->cosiq * 
		__state->a10;
	__state->x1 = __state->a1 * __state->cosomo + __state->a2 * 
		__state->sinomo;
	__state->x2 = __state->a3 * __state->cosomo + __state->a4 * 
		__state->sinomo;
	__state->x3 = -__state->a1 * __state->sinomo + __state->a2 * 
		__state->cosomo;
	__state->x4 = -__state->a3 * __state->sinomo + __state->a4 * 
		__state->cosomo;
	__state->x5 = __state->a5 * __state->sinomo;
	__state->x6 = __state->a6 * __state->sinomo;
	__state->x7 = __state->a5 * __state->cosomo;
	__state->x8 = __state->a6 * __state->cosomo;
/* Computing 2nd power */
	d__1 = __state->x1;
/* Computing 2nd power */
	d__2 = __state->x3;
	__state->z31 = d__1 * d__1 * 12. - d__2 * d__2 * 3.;
	__state->z32 = __state->x1 * 24. * __state->x2 - __state->x3 * 6. * 
		__state->x4;
/* Computing 2nd power */
	d__1 = __state->x2;
/* Computing 2nd power */
	d__2 = __state->x4;
	__state->z33 = d__1 * d__1 * 12. - d__2 * d__2 * 3.;
/* Computing 2nd power */
	d__1 = __state->a1;
/* Computing 2nd power */
	d__2 = __state->a2;
	__state->z1 = (d__1 * d__1 + d__2 * d__2) * 3. + __state->z31 * 
		__state->eqsq;
	__state->z2 = (__state->a1 * __state->a3 + __state->a2 * __state->a4) 
		* 6. + __state->z32 * __state->eqsq;
/* Computing 2nd power */
	d__1 = __state->a3;
/* Computing 2nd power */
	d__2 = __state->a4;
	__state->z3 = (d__1 * d__1 + d__2 * d__2) * 3. + __state->z33 * 
		__state->eqsq;
	__state->z11 = __state->a1 * -6. * __state->a5 + __state->eqsq * (
		__state->x1 * -24. * __state->x7 - __state->x3 * 6. * 
		__state->x5);
	__state->z12 = (__state->a1 * __state->a6 + __state->a3 * __state->a5)
		 * -6. + __state->eqsq * ((__state->x2 * __state->x7 + 
		__state->x1 * __state->x8) * -24. - (__state->x3 * 
		__state->x6 + __state->x4 * __state->x5) * 6.);
	__state->z13 = __state->a3 * -6. * __state->a6 + __state->eqsq * (
		__state->x2 * -24. * __state->x8 - __state->x4 * 6. * 
		__state->x6);
	__state->z21 = __state->a2 * 6. * __state->a5 + __state->eqsq * (
		__state->x1 * 24. * __state->x5 - __state->x3 * 6. * 
		__state->x7);
	__state->z22 = (__state->a4 * __state->a5 + __state->a2 * __state->a6)
		 * 6. + __state->eqsq * ((__state->x2 * __state->x5 + 
		__state->x1 * __state->x6) * 24. - (__state->x4 * __state->x7 
		+ __state->x3 * __state->x8) * 6.);
	__state->z23 = __state->a4 * 6. * __state->a6 + __state->eqsq * (
		__state->x2 * 24. * __state->x6 - __state->x4 * 6. * 
		__state->x8);
	__state->z1 = __state->z1 + __state->z1 + __state->bsq * __state->z31;
	__state->z2 = __state->z2 + __state->z2 + __state->bsq * __state->z32;
	__state->z3 = __state->z3 + __state->z3 + __state->bsq * __state->z33;
	__state->s3 = __state->cc * __state->xnoi;
	__state->s2 = __state->s3 * -.5 / __state->rteqsq;
	__state->s4 = __state->s3 * __state->rteqsq;
	__state->s1 = __state->eq * -15. * __state->s4;
	__state->s5 = __state->x1 * __state->x3 + __state->x2 * __state->x4;
	__state->s6 = __state->x2 * __state->x3 + __state->x1 * __state->x4;
	__state->s7 = __state->x2 * __state->x4 - __state->x1 * __state->x3;
	__state->se = __state->s1 * __state->zn * __state->s5;
	__state->si = __state->s2 * __state->zn * (__state->z11 + 
		__state->z13);
	__state->sl = -__state->zn * __state->s3 * (__state->z1 + __state->z3 
		- 14. - __state->eqsq * 6.);
	__state->sgh = __state->s4 * __state->zn * (__state->z31 + 
		__state->z33 - 6.);
	__state->sh = -__state->zn * __state->s2 * (__state->z21 + 
		__state->z23);

/*        Check for, and adust SH, at inclinations near 0 and 180 degs. */

	if (__state->xqncl < .052359877 || __state->xqncl > pi_(
		__global_state) - .052359877) {
	    __state->sh = 0.;
	}

/*        Secondary check, J.I.C. */

	if (__state->siniq == 0.) {
	    __state->sh = 0.;
	}
	__state->ee2 = __state->s1 * 2. * __state->s6;
	__state->e3 = __state->s1 * 2. * __state->s7;
	__state->xi2 = __state->s2 * 2. * __state->z12;
	__state->xi3 = __state->s2 * 2. * (__state->z13 - __state->z11);
	__state->xl2 = __state->s3 * -2. * __state->z2;
	__state->xl3 = __state->s3 * -2. * (__state->z3 - __state->z1);
	__state->xl4 = __state->s3 * -2. * (-21. - __state->eqsq * 9.) * 
		__state->ze;
	__state->xgh2 = __state->s4 * 2. * __state->z32;
	__state->xgh3 = __state->s4 * 2. * (__state->z33 - __state->z31);
	__state->xgh4 = __state->s4 * -18. * __state->ze;
	__state->xh2 = __state->s2 * -2. * __state->z22;
	__state->xh3 = __state->s2 * -2. * (__state->z23 - __state->z21);
	if (__state->i__ == 1) {

/*           Do lunar terms after solar terms, but only once. */

	    __state->ssx[0] = __state->sl;

/*            Prevent evaluation of 1/SINIQ for SH = 0. */

	    if (__state->sh == 0.) {
		__state->ssx[2] = 0.;
	    }
	    if (__state->sh != 0.) {
		__state->ssx[2] = __state->sh / __state->siniq;
	    }
	    __state->ssx[1] = __state->sgh - __state->cosiq * __state->ssx[2];
	    __state->ssx[3] = __state->se;
	    __state->ssx[4] = __state->si;
	    __state->se2 = __state->ee2;
	    __state->si2 = __state->xi2;
	    __state->sl2 = __state->xl2;
	    __state->sgh2 = __state->xgh2;
	    __state->sh2 = __state->xh2;
	    __state->se3 = __state->e3;
	    __state->si3 = __state->xi3;
	    __state->sl3 = __state->xl3;
	    __state->sgh3 = __state->xgh3;
	    __state->sh3 = __state->xh3;
	    __state->sl4 = __state->xl4;
	    __state->sgh4 = __state->xgh4;
	    __state->zcosg = __state->zcosgl;
	    __state->zsing = __state->zsingl;
	    __state->zcosi = __state->zcosil;
	    __state->zsini = __state->zsinil;
	    __state->zcosh = __state->zcoshl * __state->cosq + 
		    __state->zsinhl * __state->sinq;
	    __state->zsinh = __state->sinq * __state->zcoshl - __state->cosq *
		     __state->zsinhl;
	    __state->zn = 1.5835218e-4;
	    __state->cc = 4.7968065e-7;
	    __state->ze = .0549;
	}
    }
    __state->ssx[0] += __state->sl;

/*      Prevent evaluation of 1/SINIQ for SH = 0. */

    if (__state->sh == 0.) {
	__state->ssx[1] += __state->sgh;
    }
    if (__state->sh != 0.) {
	__state->ssx[1] = __state->ssx[1] + __state->sgh - __state->cosiq / 
		__state->siniq * __state->sh;
    }
    if (__state->sh == 0.) {
	__state->ssx[2] = __state->ssx[2];
    }
    if (__state->sh != 0.) {
	__state->ssx[2] += __state->sh / __state->siniq;
    }
    __state->ssx[3] += __state->se;
    __state->ssx[4] += __state->si;

/*     Geopotential resonance initialization for 12 hour orbits */

    __state->iresfl = 0;
    __state->isynfl = 0;
    if (__state->xnq < .0052359877 && __state->xnq > .0034906585) {

/*        Synchronous resonance terms initialization */

	__state->iresfl = 1;
	__state->isynfl = 1;
	__state->g200 = __state->eqsq * (__state->eqsq * .8125 - 2.5) + 1.;
	__state->g310 = __state->eqsq * 2. + 1.;
	__state->g300 = __state->eqsq * (__state->eqsq * 6.60937 - 6.) + 1.;
/* Computing 2nd power */
	d__1 = __state->cosiq + 1.;
	__state->f220 = d__1 * d__1 * .75;
	__state->f311 = __state->siniq * .9375 * __state->siniq * (
		__state->cosiq * 3. + 1.) - (__state->cosiq + 1.) * .75;
/* Computing 3rd power */
	d__1 = __state->cosiq + 1.;
	__state->f330 = d__1 * (d__1 * d__1) * 1.875;
/* Computing 2nd power */
	d__1 = __state->xnq;
/* Computing 2nd power */
	d__2 = __state->aqnv;
	__state->del[0] = d__1 * d__1 * 3. * (d__2 * d__2);
	__state->del[1] = __state->del[0] * 2. * __state->f220 * 
		__state->g200 * 1.7891679e-6;
	__state->del[2] = __state->del[0] * 3. * __state->f330 * 
		__state->g300 * 2.2123015e-7 * __state->aqnv;
	__state->del[0] = __state->del[0] * __state->f311 * __state->g310 * 
		2.1460748e-6 * __state->aqnv;
	__state->xlamo = __state->xmao + __state->xnodeo + __state->omegao - 
		__state->thgr;
	__state->bfact = *xlldot + *omgdot + *xnodot - .0043752691;
	__state->bfact = __state->bfact + __state->ssx[0] + __state->ssx[1] + 
		__state->ssx[2];
    } else {
	if (__state->xnq < .00826 || __state->xnq > .00924 || __state->eq < 
		.5) {
	    return 0;
	}
	__state->iresfl = 1;
	__state->eoc = __state->eq * __state->eqsq;
	__state->g201 = -.306 - (__state->eq - .64) * .44;

/*     Looks icky doesn't it? */

	if (__state->eq > .65) {
	    __state->g211 = __state->eq * 331.819 - 72.099 - __state->eqsq * 
		    508.738 + __state->eoc * 266.724;
	    __state->g310 = __state->eq * 1582.851 - 346.844 - __state->eqsq *
		     2415.925 + __state->eoc * 1246.113;
	    __state->g322 = __state->eq * 1554.908 - 342.585 - __state->eqsq *
		     2366.899 + __state->eoc * 1215.972;
	    __state->g410 = __state->eq * 4758.686 - 1052.797 - __state->eqsq 
		    * 7193.992 + __state->eoc * 3651.957;
	    __state->g422 = __state->eq * 16178.11 - 3581.69 - __state->eqsq *
		     24462.77 + __state->eoc * 12422.52;

/*           Decide on the G520 coefficient. */

	    if (__state->eq > .715) {
		__state->g520 = __state->eq * 29936.92 - 5149.66 - 
			__state->eqsq * 54087.36 + __state->eoc * 31324.56;
	    } else {
		__state->g520 = 1464.74 - __state->eq * 4664.75 + 
			__state->eqsq * 3763.64;
	    }
	} else {
	    __state->g211 = 3.616 - __state->eq * 13.247 + __state->eqsq * 
		    16.29;
	    __state->g310 = __state->eq * 117.39 - 19.302 - __state->eqsq * 
		    228.419 + __state->eoc * 156.591;
	    __state->g322 = __state->eq * 109.7927 - 18.9068 - __state->eqsq *
		     214.6334 + __state->eoc * 146.5816;
	    __state->g410 = __state->eq * 242.694 - 41.122 - __state->eqsq * 
		    471.094 + __state->eoc * 313.953;
	    __state->g422 = __state->eq * 841.88 - 146.407 - __state->eqsq * 
		    1629.014 + __state->eoc * 1083.435;
	    __state->g520 = __state->eq * 3017.977 - 532.114 - __state->eqsq *
		     5740. + __state->eoc * 3708.276;
	}
	if (__state->eq >= .7) {
	    __state->g533 = __state->eq * 161616.52 - 37995.78 - 
		    __state->eqsq * 229838.2 + __state->eoc * 109377.94;
	    __state->g521 = __state->eq * 218913.95 - 51752.104 - 
		    __state->eqsq * 309468.16 + __state->eoc * 146349.42;
	    __state->g532 = __state->eq * 170470.89 - 40023.88 - 
		    __state->eqsq * 242699.48 + __state->eoc * 115605.82;
	} else {
	    __state->g533 = __state->eq * 4988.61 - 919.2277 - __state->eqsq *
		     9064.77 + __state->eoc * 5542.21;
	    __state->g521 = __state->eq * 4568.6173 - 822.71072 - 
		    __state->eqsq * 8491.4146 + __state->eoc * 5337.524;
	    __state->g532 = __state->eq * 4690.25 - 853.666 - __state->eqsq * 
		    8624.77 + __state->eoc * 5341.4;
	}
	__state->sini2 = __state->siniq * __state->siniq;
	__state->f220 = (__state->cosiq * 2. + 1. + __state->cosq2) * .75;
	__state->f221 = __state->sini2 * 1.5;
	__state->f321 = __state->siniq * 1.875 * (1. - __state->cosiq * 2. - 
		__state->cosq2 * 3.);
	__state->f322 = __state->siniq * -1.875 * (__state->cosiq * 2. + 1. - 
		__state->cosq2 * 3.);
	__state->f441 = __state->sini2 * 35. * __state->f220;
	__state->f442 = __state->sini2 * 39.375 * __state->sini2;
	__state->f522 = __state->siniq * 9.84375 * (__state->sini2 * (1. - 
		__state->cosiq * 2. - __state->cosq2 * 5.) + (__state->cosiq *
		 4. - 2. + __state->cosq2 * 6.) * .33333333);
	__state->f523 = __state->siniq * (__state->sini2 * 4.92187512 * (-2. 
		- __state->cosiq * 4. + __state->cosq2 * 10.) + (
		__state->cosiq * 2. + 1. - __state->cosq2 * 3.) * 6.56250012);
	__state->f542 = __state->siniq * 29.53125 * (2. - __state->cosiq * 8. 
		+ __state->cosq2 * (__state->cosiq * 8. - 12. + 
		__state->cosq2 * 10.));
	__state->f543 = __state->siniq * 29.53125 * (-2. - __state->cosiq * 
		8. + __state->cosq2 * (__state->cosiq * 8. + 12. - 
		__state->cosq2 * 10.));
	__state->xno2 = __state->xnq * __state->xnq;
	__state->ainv2 = __state->aqnv * __state->aqnv;
	__state->temp1 = __state->xno2 * 3. * __state->ainv2;
	__state->temp = __state->temp1 * 1.7891679e-6;
	__state->dg[0] = __state->temp * __state->f220 * __state->g201;
	__state->dg[1] = __state->temp * __state->f221 * __state->g211;
	__state->temp1 *= __state->aqnv;
	__state->temp = __state->temp1 * 3.7393792e-7;
	__state->dg[2] = __state->temp * __state->f321 * __state->g310;
	__state->dg[3] = __state->temp * __state->f322 * __state->g322;
	__state->temp1 *= __state->aqnv;
	__state->temp = __state->temp1 * 2. * 7.3636953e-9;
	__state->dg[4] = __state->temp * __state->f441 * __state->g410;
	__state->dg[5] = __state->temp * __state->f442 * __state->g422;
	__state->temp1 *= __state->aqnv;
	__state->temp = __state->temp1 * 1.1428639e-7;
	__state->dg[6] = __state->temp * __state->f522 * __state->g520;
	__state->dg[7] = __state->temp * __state->f523 * __state->g532;
	__state->temp = __state->temp1 * 2. * 2.1765803e-9;
	__state->dg[8] = __state->temp * __state->f542 * __state->g521;
	__state->dg[9] = __state->temp * __state->f543 * __state->g533;
	__state->xlamo = __state->xmao + __state->xnodeo + __state->xnodeo - 
		__state->thgr - __state->thgr;
	__state->bfact = *xlldot + *xnodot + *xnodot - .0043752691 - 
		.0043752691;
	__state->bfact = __state->bfact + __state->ssx[0] + __state->ssx[2] + 
		__state->ssx[2];
    }
    __state->xfact = __state->bfact - __state->xnq;

/*     Initialize integrator */

    __state->xli = __state->xlamo;
    __state->xni = __state->xnq;
    __state->atime = 0.;
    return 0;
/* $Procedure ZZDPSEC (Calculate secular perturbations ) */

L_zzdpsec:
/* $ Abstract */

/*     Entrance for deep space secular effects */

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

/*     SECULAR PERTURBATION */

/* $ Declarations */

/*     None. */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     XLL        I    Long-period periodic term */
/*     OMGASM     I    Perturbed argument of perigee */
/*     XNODES     I    Perturbed argument of ascending node */
/*     T          I    Time to calculate perturbation */
/*     ELEMS      I    The two line elements array */
/*     XN         O    Perturbed mean motion of the orbit at time T */
/*     EM         O    Perturbed eccentricity of the orbit at time T */
/*     XINC       O    Perturbed inclination of the orbit plane at time T */

/* $ Detailed_Input */

/*     XLL         a long-period periodic term dependent on inclination, */
/*                 eccentricity and argument of periapsis */

/*     OMGASM      the value of the argument of perigee after the */
/*                 perturbations at the time of interest are */
/*                 added */

/*     XNODES      is the value of the argument of the ascending node */
/*                 after the perturbations at the time of interest are */
/*                 added. */

/*     T           is the total time from the epoch, in minutes, of the */
/*                 element set at which to calculate the perturbation. */

/*     ELEMS       is an array containing two-line element data */
/*                 as prescribed below. The elements XNDD6O and BSTAR */
/*                 must already be scaled by the proper exponent stored */
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

/*     XN          is the perturbed mean motion from the 'mean' mean */
/*                 motion at epoch at time T. */

/*     EM          is the perturbed eccentricity from the mean */
/*                 eccentricity at epoch at time T. */

/*     XINC        is the perturbed inclination of the orbit plane from */
/*                 the mean inclination at the epoch at time T */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     None. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     The operation of this routine is to calculate the current secular */
/*     perturbations of the 'mean' orbit elements.  The extent of the */
/*     perturbations is determined by the state of the IRESFL flag.  This */
/*     flag indicates whether the resonance effects will or will not be */
/*     calculated for the vehicle.  Resonance will be calculated when */
/*     mean motion is between 0.8 to 1.2 orbits per day (approximately */
/*     geosynch), or between 1.9 and 2.1 orbits per days. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     1)  This routine should only be called by DPSPCE when propagating */
/*         two line element sets. */

/* $ Literature_References */

/*     Hoots, Felix R., Ronald L. Roehrich (31 December 1988). "Models */
/*     for Propagation of NORAD Element Sets". United States Department */
/*     of Defense Spacetrack Report (3). */

/*     Vallado, David A., Paul Crawford, Richard Hujsak, and */
/*     Kelso, T. S., "Revisiting Spacetrack Report #3," AIAA/AAS */
/*     Astrodynamics Specialist Conference, Keystone, CO, Aug 2006. */

/* $ Author_and_Institution */

/*     E.D. Wright      (JPL) */
/*     W.L. Taber       (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.6.0, 27-JUN-2016 (EDW) */

/*        The "Revisiting Spacetrack Report #3" by Vallado et. al. */
/*        indicates the negative inclination modification as a mistake. */
/*        That code was removed. */

/* -    SPICELIB Version 1.5.1, 19-SEP-2006 (EDW) */

/*        Added text to previously empty Declarations section */
/*        in ZZDPINIT, ZZDPPER, ZZDPSEC. */

/* -    SPICELIB Version 1.5.0, 20-JAN-1999 (EDW) (WLT) */

/*        OMGDOT, named in an ENTRY point argument list */
/*        was not passed via an argument list.  Solaris exhibited a */
/*        bus error because of this situation.  All ENTRY point */
/*        arguments are passed only by argument lists and are declared */
/*        in the umbrella subroutine's, ZZNRDDP, argument list. */

/*        Combined the various SSL, SSG, SSH, SSI, SSE variables into */
/*        the vector SSX. */

/*        Removed the dependency upon the UTC/ET leapsecond kernel. */

/*        Alphabetized all variable declaration lists. */

/*        All arguments passed through entry points listed as arguments */
/*        of ZZNRDDP.  OMGDT renamed OMGDOT to be consistent with other */
/*        deep space two line element routines. */

/* -    SPICELIB Version 1.0.0, MAY-2-1997 (EDW) */

/* -& */
/* $ Index_Entries */

/*     two line elements, secular perturbation */

/* -& */
    __state->stepp = 720.;
    __state->stepn = -720.;
    __state->xincl = elems[3];
    __state->eo = elems[5];
    *xll += __state->ssx[0] * *t;
    *omgasm += __state->ssx[1] * *t;
    *xnodes += __state->ssx[2] * *t;
    *em = __state->eo + __state->ssx[3] * *t;
    *xinc = __state->xincl + __state->ssx[4] * *t;

/*     Check for the state of the resonance flag. */

    if (__state->iresfl == 0) {
	return 0;
    }

/*     If we got down here then the resonance effects need to be */
/*     calculated.  Continue to loop until the CONT flag is set to false. */

    __state->cont = TRUE_;
    while(__state->cont) {
	if (__state->atime == 0. || *t >= 0. && __state->atime < 0. || *t < 
		0. && __state->atime >= 0.) {

/*           Epoch restart */

	    if (*t >= 0.) {
		__state->delt = __state->stepp;
	    } else {
		__state->delt = __state->stepn;
	    }
	    __state->atime = 0.;
	    __state->xni = __state->xnq;
	    __state->xli = __state->xlamo;
	    __state->cont = FALSE_;
	} else if (abs(*t) >= abs(__state->atime)) {
	    __state->delt = __state->stepn;
	    if (*t > 0.) {
		__state->delt = __state->stepp;
	    }
	    __state->cont = FALSE_;
	} else {
	    __state->delt = __state->stepp;
	    if (*t >= 0.) {
		__state->delt = __state->stepn;
	    }
	    zzsecprt_(__global_state, &__state->isynfl, __state->dg, 
		    __state->del, &__state->xni, &__state->omegao, &
		    __state->atime, omgdot, &__state->xli, &__state->xfact, &
		    __state->xldot, &__state->xndot, &__state->xnddt);
	    __state->xli = __state->xli + __state->xldot * __state->delt + 
		    __state->xndot * 259200.;
	    __state->xni = __state->xni + __state->xndot * __state->delt + 
		    __state->xnddt * 259200.;
	    __state->atime += __state->delt;
	    __state->cont = TRUE_;
	}
    }

/*     Do this loop while the time interval is greater than STEPP */

    while((d__1 = *t - __state->atime, abs(d__1)) >= __state->stepp) {
	zzsecprt_(__global_state, &__state->isynfl, __state->dg, __state->del,
		 &__state->xni, &__state->omegao, &__state->atime, omgdot, &
		__state->xli, &__state->xfact, &__state->xldot, &
		__state->xndot, &__state->xnddt);
	__state->xli = __state->xli + __state->xldot * __state->delt + 
		__state->xndot * 259200.;
	__state->xni = __state->xni + __state->xndot * __state->delt + 
		__state->xnddt * 259200.;
	__state->atime += __state->delt;
    }

/*     Calculate the time interval and determine the secular */
/*     perturbations */

    __state->ft = *t - __state->atime;
    zzsecprt_(__global_state, &__state->isynfl, __state->dg, __state->del, &
	    __state->xni, &__state->omegao, &__state->atime, omgdot, &
	    __state->xli, &__state->xfact, &__state->xldot, &__state->xndot, &
	    __state->xnddt);
    *xn = __state->xni + __state->xndot * __state->ft + __state->xnddt * 
	    __state->ft * __state->ft * .5;
    __state->xl = __state->xli + __state->xldot * __state->ft + 
	    __state->xndot * __state->ft * __state->ft * .5;
    __state->temp = -(*xnodes) + __state->thgr + *t * .0043752691;
    *xll = __state->xl - *omgasm + __state->temp;
    if (__state->isynfl == 0) {
	*xll = __state->xl + __state->temp + __state->temp;
    }
    return 0;
/* $Procedure ZZDPPER ( Calculate periodic perturbations ) */

L_zzdpper:
/* $ Abstract */

/*     Entrances for lunar-solar periodics */

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

/*     PERIODIC PERTURBATION */

/* $ Declarations */

/*     None. */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     T          I   Time to calculate perturbations */
/*     EM         O   Perturbed eccentricity of the orbit at time T */
/*     XINC       O   Perturbed inclination of the orbit plane at time T */
/*     OMGASM     O   Perturbed argument of perigee */
/*     XNODES     O   Perturbed argument of ascending node */
/*     XLL        0   Long-period periodic term */

/* $ Detailed_Input */

/*     T           the time from the epoch in minutes of the element set */
/*                 at which to calculate the perturbation. */

/* $ Detailed_Output */

/*     EM          is the perturbed eccentricity from the mean */
/*                 eccentricity at epoch at time T. */

/*     XINC        is the perturbed inclination of the orbit plane from */
/*                 the mean inclination at the epoch at time T. */

/*     OMGASM      the value of the argument of perigee after the */
/*                 perturbations at the time of interest are */
/*                 added. */

/*     XNODES      is the value of the argument of the ascending node */
/*                 after the perturbations at the time of interest are */
/*                 added. */

/*     XLL         a long-period periodic term dependent on inclination, */
/*                 eccentricity and argument of periapsis. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine calculates the current time dependent periodic */
/*     perturbations values due to the sun and the moon.  The original */
/*     version, as taken from the Spacetrack 3 report, had a number of */
/*     bugs. */

/*     XNODES could be evaluated as being in the wrong quadrant due to */
/*     a failure to insure a domain of 0 to 2 Pi. */

/*     The SIN and COS of the perturbed inclination, XINCL, were */
/*     calculated before the perturbed value. */

/*     EM & XINC are input and output values.  The input value is updated */
/*     by the addition of a perturbation value. */

/*     The original report did not recalculate perturbation terms if two */
/*     consecutive epoch times were less than 30 minutes apart.  This */
/*     condition has been removed.  Perturbation terms are always */
/*     calculated. */

/* $ Examples */

/*     None needed. */

/* $ Restrictions */

/*     1)  This routine should only be called by DPSPCE when propagating */
/*         two line element sets. */

/*     2)  This routine should be initialized prior to use by making */
/*         a call with the time epoch set to 0.  Failure to do so */
/*         invalidates the perturbation calculation. */

/* $ Literature_References */

/*     Hoots, Felix R., Ronald L. Roehrich (31 December 1988). "Models */
/*     for Propagation of NORAD Element Sets". United States Department */
/*     of Defense Spacetrack Report (3). */

/* $ Author_and_Institution */

/*     E.D. Wright      (JPL) */
/*     W.L. Taber       (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.5.1, 19-SEP-2006 (EDW) */

/*        Added text to previously empty Declarations section */
/*        in ZZDPINIT, ZZDPPER, ZZDPSEC. */

/* -    SPICELIB Version 1.5.0, 20-JAN-1999 (EDW) (WLT) */

/*        OMGDOT, named in an ENTRY point argument list */
/*        was not passed via an argument list.  Solaris exhibited a */
/*        bus error because of this situation.  All ENTRY point */
/*        arguments are passed only by argument lists and are declared */
/*        in the umbrella subroutine's, ZZNRDDP, argument list. */

/*        Combined the various SSL, SSG, SSH, SSI, SSE variables into */
/*        the vector SSX. */

/*        Removed the dependency upon the UTC/ET leapsecond kernel. */

/*        Alphabetized all variable declaration lists. */

/*        All arguments passed through entry points listed as arguments */
/*        of ZZNRDDP.  OMGDT renamed OMGDOT to be consistent with other */
/*        deep space two line element routines. */

/* -    SPICELIB Version 1.0.0, MAY-17-1997 (EDW) */


/* -& */
/* $ Index_Entries */

/*     two line elements, periodic perturbation */

/* -& */

/*     Time varying periodic terms. */


/*     Update for solar perts at time T. */

    __state->zm = __state->zmos + *t * 1.19459e-5;
    __state->zf = __state->zm + sin(&__global_state->f2c, __state->zm) * 
	    .033500000000000002;
    __state->sinzf = sin(&__global_state->f2c, __state->zf);
    __state->f2 = __state->sinzf * .5 * __state->sinzf - .25;
    __state->f3 = __state->sinzf * -.5 * cos(&__global_state->f2c, 
	    __state->zf);
    __state->ses = __state->se2 * __state->f2 + __state->se3 * __state->f3;
    __state->sis = __state->si2 * __state->f2 + __state->si3 * __state->f3;
    __state->sls = __state->sl2 * __state->f2 + __state->sl3 * __state->f3 + 
	    __state->sl4 * __state->sinzf;
    __state->sghs = __state->sgh2 * __state->f2 + __state->sgh3 * __state->f3 
	    + __state->sgh4 * __state->sinzf;
    __state->shs = __state->sh2 * __state->f2 + __state->sh3 * __state->f3;

/*     Update for lunar perts at time T. */

    __state->zm = __state->zmol + *t * 1.5835218e-4;
    __state->zf = __state->zm + sin(&__global_state->f2c, __state->zm) * 
	    .10979999999999999;
    __state->sinzf = sin(&__global_state->f2c, __state->zf);
    __state->f2 = __state->sinzf * .5 * __state->sinzf - .25;
    __state->f3 = __state->sinzf * -.5 * cos(&__global_state->f2c, 
	    __state->zf);
    __state->sel = __state->ee2 * __state->f2 + __state->e3 * __state->f3;
    __state->sil = __state->xi2 * __state->f2 + __state->xi3 * __state->f3;
    __state->sll = __state->xl2 * __state->f2 + __state->xl3 * __state->f3 + 
	    __state->xl4 * __state->sinzf;
    __state->sghl = __state->xgh2 * __state->f2 + __state->xgh3 * __state->f3 
	    + __state->xgh4 * __state->sinzf;
    __state->shl = __state->xh2 * __state->f2 + __state->xh3 * __state->f3;

/*     Sum of solar and lunar perts */

    __state->pe = __state->ses + __state->sel;
    __state->pinc = __state->sis + __state->sil;
    __state->pl = __state->sls + __state->sll;
    __state->pgh = __state->sghs + __state->sghl;
    __state->ph = __state->shs + __state->shl;

/*     Subtract the epoch perturbations off the calculated values. */

    __state->pe -= __state->pe0;
    __state->pinc -= __state->pinc0;
    __state->pl -= __state->pl0;
    __state->pgh -= __state->pgh0;
    __state->ph -= __state->ph0;
    *xinc += __state->pinc;
    *em += __state->pe;

/*     Sin and Cos of the perturbed inclination.  The original */
/*     Spacetrack 3 report calculated the values before the */
/*     perturbation. */

    __state->sinis = sin(&__global_state->f2c, *xinc);
    __state->cosis = cos(&__global_state->f2c, *xinc);
    if (__state->xqncl > .2) {
	__state->ph /= __state->siniq;
	__state->pgh -= __state->cosiq * __state->ph;
	*omgasm += __state->pgh;
	*xnodes += __state->ph;
	*xll += __state->pl;
    } else {

/*        Apply periodics with Lyddane modification */

	__state->sinok = sin(&__global_state->f2c, *xnodes);
	__state->cosok = cos(&__global_state->f2c, *xnodes);
	__state->alfdp = __state->sinis * __state->sinok;
	__state->betdp = __state->sinis * __state->cosok;
	__state->alfdp = __state->alfdp + __state->ph * __state->cosok + 
		__state->pinc * __state->cosis * __state->sinok;
	__state->betdp = __state->betdp - __state->ph * __state->sinok + 
		__state->pinc * __state->cosis * __state->cosok;

/*        Force a 0 - 2Pi domain on XNODES. */

	if (*xnodes < 0.) {
	    *xnodes += __state->pix2;
	}
	__state->xls = *xll + *omgasm + __state->pl + __state->pgh + 
		__state->cosis * *xnodes - __state->sinis * *xnodes * 
		__state->pinc;

/*        Compute the angle from the x-axis of the point */

	if (__state->alfdp != 0. || __state->betdp != 0.) {

/*           Save the old value of XNODES, then compute the current value */
/*           From ALFDP and BETDP */

	    __state->oxnode = *xnodes;
	    *xnodes = atan2(&__global_state->f2c, __state->alfdp, 
		    __state->betdp);

/*           Force a 0 - 2Pi domain on XNODES */

	    if (*xnodes < 0.) {
		*xnodes += __state->pix2;
	    }

/*           XNODES should be the angular difference between the previous */
/*           value of XNODES and that just calculated.  This is a */
/*           correction to the standard SDP4 routine which did not */
/*           calculate this term correctly if XNODES passes over the */
/*           branch cut at 2*Pi. */

	    if ((d__1 = *xnodes - __state->oxnode, abs(d__1)) > __state->pix1)
		     {
		if (*xnodes > __state->oxnode) {
		    *xnodes -= __state->pix2;
		} else {
		    *xnodes += __state->pix2;
		}
	    }
	} else {
	    *xnodes = 0.;
	}
	*xll += __state->pl;
	*omgasm = __state->xls - *xll - *xnodes * cos(&__global_state->f2c, *
		xinc);
    }
    return 0;
} /* zznrddp_ */

/* Subroutine */ int zznrddp_(cspice_t* __global_state, doublereal *ao, 
	doublereal *elems, doublereal *em, doublereal *omgasm, doublereal *
	omgdot, doublereal *t, doublereal *xinc, doublereal *xll, doublereal *
	xlldot, doublereal *xn, doublereal *xnodes, doublereal *xnodot, 
	doublereal *xnodp)
{
    return zznrddp_0_(0, ao, elems, em, omgasm, omgdot, t, xinc, xll, xlldot, 
	    xn, xnodes, xnodot, xnodp);
    }

/* Subroutine */ int zzdpinit_(cspice_t* __global_state, doublereal *ao, 
	doublereal *xlldot, doublereal *omgdot, doublereal *xnodot, 
	doublereal *xnodp, doublereal *elems)
{
    return zznrddp_0_(1, ao, elems, (doublereal *)0, (doublereal *)0, omgdot, 
	    (doublereal *)0, (doublereal *)0, (doublereal *)0, xlldot, (
	    doublereal *)0, (doublereal *)0, xnodot, xnodp);
    }

/* Subroutine */ int zzdpsec_(cspice_t* __global_state, doublereal *xll, 
	doublereal *omgasm, doublereal *xnodes, doublereal *em, doublereal *
	xinc, doublereal *xn, doublereal *t, doublereal *elems, doublereal *
	omgdot)
{
    return zznrddp_0_(2, (doublereal *)0, elems, em, omgasm, omgdot, t, xinc, 
	    xll, (doublereal *)0, xn, xnodes, (doublereal *)0, (doublereal *)
	    0);
    }

/* Subroutine */ int zzdpper_(cspice_t* __global_state, doublereal *t, 
	doublereal *em, doublereal *xinc, doublereal *omgasm, doublereal *
	xnodes, doublereal *xll)
{
    return zznrddp_0_(3, (doublereal *)0, (doublereal *)0, em, omgasm, (
	    doublereal *)0, t, xinc, xll, (doublereal *)0, (doublereal *)0, 
	    xnodes, (doublereal *)0, (doublereal *)0);
    }

