/* zzwahr.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzwahr_init_t __zzwahr_init;
static zzwahr_state_t* get_zzwahr_state() {
	cspice_t* state =  __cspice_get_state();
	if (!state->zzwahr)
		state->zzwahr = __cspice_allocate_module(sizeof(
	zzwahr_state_t), &__zzwahr_init, sizeof(__zzwahr_init));
	return state->zzwahr;

}

/* $Procedure      ZZWAHR ( SPICELIB private version of Newhalls' WAHR ) */
/* Subroutine */ int zzwahr_(doublereal *et, doublereal *dvnut)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_rnge(char *, integer, char *, integer);
    double d_mod(doublereal *, doublereal *), cos(doublereal), sin(doublereal)
	    ;

    /* Local variables */
    extern doublereal twopi_(void);
    extern doublereal pi_(void);
    extern doublereal spd_(void);


    /* Module state */
    zzwahr_state_t* __state = get_zzwahr_state();
/* $ Abstract */

/*     Calculates nutation angles delta psi and delta epsilon,  and */
/*     their rates of change, referred to the ecliptic of date, from */
/*     the wahr series (Table 1,'Proposal to the IAU Working Group */
/*     on Nutation', John M. Wahr and Martin L. Smith 1979) */

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

/*     NUTATIONS */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Ephemeris Time for which nutations are sought */
/*     DVNUT      O   Nutation angles and their rates. */

/* $ Detailed_Input */

/*     ET         is the epoch for which nutation angles are being */
/*                requested expressed in TDB seconds past the epoch */
/*                of J2000. */

/* $ Detailed_Output */

/*     DVNUT      are the nutation angles and their derivatives. */
/*                Following the notation on page 112 of the */
/*                Explanatory Supplement to the Astronomical */
/*                Almanac we have */

/*                DVNUT(1) = Psi------nutation in longitude (radians) */
/*                DVNUT(2) = Epsilon--nutation in obliquity (radians) */
/*                DVNUT(3) = dPsi/dt     (radians/second) */
/*                DVNUT(4) = dEpsilon/dt (radians/second) */

/* $ Parameters */

/*     None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/* $ Particulars */

/*     This routine computes the angles required for computing the */
/*     transformation from the mean of date frame for the earth */
/*     to the true of date frame of the earth. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */

/* $ Literature_References */

/*     Explanatory Supplement to the Astronomical Almanac edited */
/*     by P. Kenneth Siedelmann. (1992) (University Science */
/*     Books, Mill Valley CA) pp. 111-116 */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 15-JUL-1997 (WLT) */

/*        This routine was adapted from a routine provided by */
/*        Skip Newhall.  Skip's notes indicate that he obtained this */
/*        from Jay Lieske and Mylse Standish.  The actual notes */
/*        from the original routine WAHR are given here. */

/*           Lieske 3/91.  NUTATION in the IAU J2000 system.  Univac */
/*           version obtained from Myles Standish, (subroutine WAHR) */
/*           who had obtained it from USNO.  Re-ordered terms to match */
/*           Astronomical Almanac 1984 table S23-S25 and corrected */
/*           the rate for dPsi in the 0 0 2 -2 2 term.  Eliminated */
/*           the equivalences, common block and added necessary SAVEs. */
/*           Corrected the fundamental angles (L, L', F, D, Node) to */
/*           match Almanac. */

/*        In the current routine the various angles L, L', F, D, and */
/*        Node (MG) are computed using the actual values given */
/*        in the Explanatory Supplement. */

/*        Note that there is an error in the Explanatory supplement */
/*        for the Node term.  The Explanatory Supplement (page 114) has */

/*          OMEGA = 135 degrees 2 minutes 40.280 seconds */
/*                +  etc. */

/*        The correct formulation should be: */

/*          OMEGA = 125 degrees 2 minutes 40.280 seconds */
/*                +  etc. */

/*        This is the value used in this routine.  The verification of */
/*        this error is courtesy of Myles Standish. */


/* -& */

/*     SPICELIB Functions */


/*     Parameters */

/*     NTERM is the number of SIN and COSINE terms used in the */
/*     computation of Delta Psi and Delta epsilon */


/*     The parameters below stand for */

/*        revolutions */
/*        degrees */
/*        minutes */
/*        seconds */
/*        julian century */
/*        julian century ** 2 */
/*        julian century ** 3 */

/*     These parameters are needed for converting the quantities */
/*     on page 114 of the Explanatory supplement from revolutions, */
/*     degrees, minutes and seconds / century, century**2 and century**3 */
/*     to degrees, degrees/day, degrees/(0.0001 days)**2 and */
/*     degress/(0.0001 days)**3. */


/*     The next set of parameters is an enumeration of the various */
/*     angles needed in the computation of nutations. */


/*     Local Variables. */


/*     Below are the coefficients for the various periods of the */
/*     nutation model.  There does not appear to be any particular reason */
/*     for the ordering selected.  The n'th row corresponds to the n'th */
/*     period listed above each data statement. */

/* >> Periods: 6798.4, 3399.2, 1305.5, 1095.2, 1615.7, 3232.9, 6786.3, */
/*             943.2,  182.6,  365.3,  121.7,  365.2,  177.8,  205.9, */
/*             173.3,  182.6,  386.0,   91.3,  346.6 */


/*     Periods: 199.8, 346.6, 212.3, 119.6, 411.8, 131.7, 169.0, 329.8, */
/*              409.2, 388.3, 117.5,  13.7,  27.6,  13.6,   9.1,  31.8, */
/*               27.1,  14.8,  27.7 */


/*     Periods: 27.4, 9.6,  9.1,  7.1, 13.8, 23.9, 6.9, 13.6, 27.0, 32.0, */
/*              31.7, 9.5, 34.8, 13.2, 14.2,  5.6, 9.6, 12.8, 14.8 */


/*     Periods: 7.1, 23.9, 14.7, 29.8, 6.9, 15.4, 26.9, 29.5, 25.6, 9.1, */
/*              9.4,  9.8, 13.7,  5.5, 7.2,  8.9, 32.6, 13.8, 27.8 */

/*      Periods: 9.2,  9.3, 27.3, 10.1, 14.6,  5.8, 15.9, 22.5,  5.6, */
/*               7.3,  9.1, 29.3, 12.8,  4.7,  9.6, 12.7,  8.7, 23.8, */
/*              13.1 */

/*     Periods: 35.0, 13.6, 25.4, 14.2, 9.5, 14.2, 34.7, 32.8, 7.1, 4.8, */
/*              27.3 */
    if (__state->first) {
	__state->first = FALSE_;
	__state->dpi = pi_();
	__state->dtwopi = twopi_();
	__state->radian = 180. / __state->dpi;
	__state->rasec = __state->radian * 3600.;
	__state->factr = __state->rasec * 1e4;
	__state->oneday = spd_();

/*        The following values are direct conversions to degrees from */
/*        page 114 of the Explanatory Supplement to the Astronomical */
/*        Almanac. */

/*        L0 through L3 are the coefficients for l---the mean longitude */
/*        of the Moon minus the mean longitude of the Moon's perigee. */
/*        Units for the various terms: */

/*           L0      degrees */
/*           L1      degrees/day */
/*           L2      degrees/(0.0001 days)**2 */
/*           L3      degrees/(0.0001 days)**3 */

	__state->l0 = 134.96298138888886;
	__state->l1 = 13.064992947243136;
	__state->l2 = 6.5192872572139397e-4;
	__state->l3 = 3.6484365631332527e-7;

/*        LP0 through LP3 are the coefficients for l'---the mean */
/*        longitude of the Sun minus the mean longitude of the Sun's */
/*        perigee. Units for the various terms: */

/*           LP0      degrees */
/*           LP1      degrees/day */
/*           LP2      degrees/(0.0001 days)**2 */
/*           LP3      degrees/(0.0001 days)**3 */

	__state->lp0 = 357.52772333333331;
	__state->lp1 = .98560028309377146;
	__state->lp2 = -1.201414483363923e-5;
	__state->lp3 = -6.8408185558748495e-8;

/*        F0 through F3 are the coefficients for F---the mean longitude */
/*        of the Moon minus the mean longitude of the Moon's node. Units */
/*        for the various terms: */

/*           F0      degrees */
/*           F1      degrees/day */
/*           F2      degrees/(0.0001 days)**2 */
/*           F3      degrees/(0.0001 days)**3 */

	__state->f0 = 93.271910277777778;
	__state->f1 = 13.229350240603848;
	__state->f2 = -2.760338267929901e-4;
	__state->f3 = 6.2707503428852773e-8;

/*        D0 through D3 are the coefficients for D---the mean longitude */
/*        of the Moon minus the mean longitude of the Sun. Units */
/*        for the various terms: */

/*           D0      degrees */
/*           D1      degrees/day */
/*           D2      degrees/(0.0001 days)**2 */
/*           D3      degrees/(0.0001 days)**3 */

	__state->d0 = 297.85036305555559;
	__state->d1 = 12.190749116495549;
	__state->d2 = -1.4348262053484912e-4;
	__state->d3 = 1.0831296046801845e-7;

/*        MG0 through MG3 are the coefficients for Omega---the longitude */
/*        of the mean ascending node of the lunar orbit on the ecliptic */
/*        measured from the mean equinox of date.  NOTE: The constant */
/*        term MG0 is correct.  The value */
/*               o */
/*            135 02' 40".280 */

/*        given in the Explanatory Supplement page 114 has a typo.  The */
/*        correct value is the one used here: */

/*               o */
/*            125 02' 40".280 */

/*           MG0      degrees */
/*           MG1      degrees/day */
/*           MG2      degrees/(0.0001 days)**2 */
/*           MG3      degrees/(0.0001 days)**3 */

	__state->mg0 = 125.04452222222223;
	__state->mg1 = -.052953764841432813;
	__state->mg2 = 1.5522608272925558e-4;
	__state->mg3 = 4.5605457039165659e-8;
    }

/*     Compute all of the various time components.  DJ is the delta */
/*     in the Julian date from the J2000 epoch. */

    __state->dj = *et / __state->oneday;
    __state->dd = __state->dj / 1e4;
    __state->dddj = __state->dd / 1e4;
    __state->dd2 = __state->dd * __state->dd;
    __state->t = __state->dj / 365250.;

/*     Now compute all of the various angles and their rates */
/*     at the current epoch */

    __state->angle[0] = __state->l0 + __state->dj * __state->l1 + (
	    __state->l2 + __state->dd * __state->l3) * __state->dd2;
    __state->angle[1] = __state->lp0 + __state->dj * __state->lp1 + (
	    __state->lp2 + __state->dd * __state->lp3) * __state->dd2;
    __state->angle[2] = __state->f0 + __state->dj * __state->f1 + (
	    __state->f2 + __state->dd * __state->f3) * __state->dd2;
    __state->angle[3] = __state->d0 + __state->dj * __state->d1 + (
	    __state->d2 + __state->dd * __state->d3) * __state->dd2;
    __state->angle[4] = __state->mg0 + __state->dj * __state->mg1 + (
	    __state->mg2 + __state->dd * __state->mg3) * __state->dd2;
    __state->angrt[0] = __state->l1 + __state->dddj * (__state->l2 * 2. + 
	    __state->dd * 3. * __state->l3);
    __state->angrt[1] = __state->lp1 + __state->dddj * (__state->lp2 * 2. + 
	    __state->dd * 3. * __state->lp3);
    __state->angrt[2] = __state->f1 + __state->dddj * (__state->f2 * 2. + 
	    __state->dd * 3. * __state->f3);
    __state->angrt[3] = __state->d1 + __state->dddj * (__state->d2 * 2. + 
	    __state->dd * 3. * __state->d3);
    __state->angrt[4] = __state->mg1 + __state->dddj * (__state->mg2 * 2. + 
	    __state->dd * 3. * __state->mg3);

/*     Wrap all of the angles and rates to range from 0 to 360, then */
/*     convert to radians. */

    for (__state->j = 1; __state->j <= 5; ++__state->j) {
	__state->angle[(i__1 = __state->j - 1) < 5 && 0 <= i__1 ? i__1 : 
		s_rnge("angle", i__1, "zzwahr_", (ftnlen)570)] = d_mod(&
		__state->angle[(i__2 = __state->j - 1) < 5 && 0 <= i__2 ? 
		i__2 : s_rnge("angle", i__2, "zzwahr_", (ftnlen)570)], &
		__state->c_b2);
	__state->angrt[(i__1 = __state->j - 1) < 5 && 0 <= i__1 ? i__1 : 
		s_rnge("angrt", i__1, "zzwahr_", (ftnlen)571)] = d_mod(&
		__state->angrt[(i__2 = __state->j - 1) < 5 && 0 <= i__2 ? 
		i__2 : s_rnge("angrt", i__2, "zzwahr_", (ftnlen)571)], &
		__state->c_b2);
	__state->angle[(i__1 = __state->j - 1) < 5 && 0 <= i__1 ? i__1 : 
		s_rnge("angle", i__1, "zzwahr_", (ftnlen)573)] = 
		__state->angle[(i__2 = __state->j - 1) < 5 && 0 <= i__2 ? 
		i__2 : s_rnge("angle", i__2, "zzwahr_", (ftnlen)573)] / 
		__state->radian;
	__state->angrt[(i__1 = __state->j - 1) < 5 && 0 <= i__1 ? i__1 : 
		s_rnge("angrt", i__1, "zzwahr_", (ftnlen)574)] = 
		__state->angrt[(i__2 = __state->j - 1) < 5 && 0 <= i__2 ? 
		i__2 : s_rnge("angrt", i__2, "zzwahr_", (ftnlen)574)] / 
		__state->radian;
    }

/*     Zero out the components of the nutation array */

    for (__state->j = 1; __state->j <= 4; ++__state->j) {
	dvnut[(i__1 = __state->j - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("dvnut"
		, i__1, "zzwahr_", (ftnlen)580)] = 0.;
    }

/*     Now we accumulate the various terms of Delta Psi and Delta */
/*     epsilon as expressed on page 115 of the Green Book */
/*     (Explanatory Supplement to the Astronomical Almanac). */

    for (__state->i__ = 1; __state->i__ <= 106; ++__state->i__) {
	__state->arg = 0.;
	__state->argrt = 0.;
	for (__state->j = 1; __state->j <= 5; ++__state->j) {
	    if (__state->matrix[(i__1 = __state->j + __state->i__ * 9 - 10) < 
		    954 && 0 <= i__1 ? i__1 : s_rnge("matrix", i__1, "zzwahr_"
		    , (ftnlen)593)] != 0) {
		__state->arg += __state->matrix[(i__1 = __state->j + 
			__state->i__ * 9 - 10) < 954 && 0 <= i__1 ? i__1 : 
			s_rnge("matrix", i__1, "zzwahr_", (ftnlen)594)] * 
			__state->angle[(i__2 = __state->j - 1) < 5 && 0 <= 
			i__2 ? i__2 : s_rnge("angle", i__2, "zzwahr_", (
			ftnlen)594)];
		__state->argrt += __state->matrix[(i__1 = __state->j + 
			__state->i__ * 9 - 10) < 954 && 0 <= i__1 ? i__1 : 
			s_rnge("matrix", i__1, "zzwahr_", (ftnlen)595)] * 
			__state->angrt[(i__2 = __state->j - 1) < 5 && 0 <= 
			i__2 ? i__2 : s_rnge("angrt", i__2, "zzwahr_", (
			ftnlen)595)];
		__state->arg = d_mod(&__state->arg, &__state->dtwopi);
	    }
	}
	__state->cl = (doublereal) __state->matrix[(i__1 = __state->i__ * 9 - 
		4) < 954 && 0 <= i__1 ? i__1 : s_rnge("matrix", i__1, "zzwah"
		"r_", (ftnlen)600)];
	if (__state->matrix[(i__1 = __state->i__ * 9 - 3) < 954 && 0 <= i__1 ?
		 i__1 : s_rnge("matrix", i__1, "zzwahr_", (ftnlen)602)] != 0) 
		{
	    __state->cl += __state->matrix[(i__1 = __state->i__ * 9 - 3) < 
		    954 && 0 <= i__1 ? i__1 : s_rnge("matrix", i__1, "zzwahr_"
		    , (ftnlen)603)] * __state->t;
	}
	__state->ce = (doublereal) __state->matrix[(i__1 = __state->i__ * 9 - 
		2) < 954 && 0 <= i__1 ? i__1 : s_rnge("matrix", i__1, "zzwah"
		"r_", (ftnlen)606)];
	if (__state->matrix[(i__1 = __state->i__ * 9 - 1) < 954 && 0 <= i__1 ?
		 i__1 : s_rnge("matrix", i__1, "zzwahr_", (ftnlen)608)] != 0) 
		{
	    __state->ce += __state->matrix[(i__1 = __state->i__ * 9 - 1) < 
		    954 && 0 <= i__1 ? i__1 : s_rnge("matrix", i__1, "zzwahr_"
		    , (ftnlen)609)] * __state->t;
	}
	__state->cosang = cos(__state->arg);
	__state->sinang = sin(__state->arg);
	dvnut[0] += __state->cl * __state->sinang / __state->factr;
	dvnut[1] += __state->ce * __state->cosang / __state->factr;
	dvnut[2] += __state->cl * __state->cosang * __state->argrt / 
		__state->factr;
	dvnut[3] -= __state->ce * __state->sinang * __state->argrt / 
		__state->factr;
    }

/*     Finally convert DVNUT(3) and DVNUT(4) to radians/second */

    dvnut[2] /= __state->oneday;
    dvnut[3] /= __state->oneday;
    return 0;
} /* zzwahr_ */

