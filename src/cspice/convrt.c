/* convrt.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern convrt_init_t __convrt_init;
static convrt_state_t* get_convrt_state(cspice_t* state) {
	if (!state->convrt)
		state->convrt = __cspice_allocate_module(sizeof(
	convrt_state_t), &__convrt_init, sizeof(__convrt_init));
	return state->convrt;

}

/* $Procedure      CONVRT ( Convert Units ) */
/* Subroutine */ int convrt_(cspice_t* __global_state, doublereal *x, char *
	in, char *out, doublereal *y, ftnlen in_len, ftnlen out_len)
{
    /* Initialized data */


    /* System generated locals */
    address a__1[5], a__2[3], a__3[9];
    integer i__1[5], i__2[3], i__3, i__4, i__5[9];
    char ch__1[101], ch__2[56], ch__3[57], ch__4[123];

    /* Builtin functions */
    /* Subroutine */ int s_cat(f2c_state_t*, char *, char **, integer *, 
	    integer *, ftnlen);
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer), s_cmp(
	    f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    doublereal temp;
    char outu[16];
    integer i__;
    integer j;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int ucase_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern integer isrchc_(cspice_t*, char *, integer *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);
    extern doublereal dpr_(cspice_t*);
    char inu[16];


    /* Module state */
    convrt_state_t* __state = get_convrt_state(__global_state);
/* $ Abstract */

/*      Take a measurement X, the units associated with */
/*      X, and units to which X should be converted; return Y --- */
/*      the value of the measurement in the output units. */

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

/*     CONVERSION, UNITS */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  ------------------------------------------------- */
/*     X          I   Number representing a measurement in some units. */
/*     IN         I   The units in which X is measured. */
/*     OUT        I   Desired units for the measurement. */
/*     Y          O   The measurement in the desired units. */

/* $ Detailed_Input */

/*     X          is a number representing a measurement in the units */
/*                specified by IN. */

/*     IN         represents the units associated with a measurement X. */
/*                Acceptable units are: */

/*                Angles:                 'RADIANS' */
/*                                        'DEGREES' */
/*                                        'ARCMINUTES' */
/*                                        'ARCSECONDS' */
/*                                        'HOURANGLE' */
/*                                        'MINUTEANGLE' */
/*                                        'SECONDANGLE' */

/*                Metric Distances:       'M' */
/*                                        'METERS' */
/*                                        'KM' */
/*                                        'KILOMETERS' */
/*                                        'CM' */
/*                                        'CENTIMETERS' */
/*                                        'MM' */
/*                                        'MILLIMETERS' */

/*                English Distances:      'FEET' */
/*                                        'INCHES' */
/*                                        'YARDS' */
/*                                        'STATUTE_MILES' */
/*                                        'NAUTICAL_MILES' */

/*                Astrometric Distances:  'AU' */
/*                                        'PARSECS' */
/*                                        'LIGHTSECS' */
/*                                        'LIGHTYEARS' julian lightyears */

/*                Time:                   'SECONDS' */
/*                                        'MINUTES' */
/*                                        'HOURS' */
/*                                        'DAYS' */
/*                                        'JULIAN_YEARS' */
/*                                        'TROPICAL_YEARS' */
/*                                        'YEARS' (same as julian years) */

/*     OUT        represents the units desired for the measurement X. */
/*                See the description of IN. */

/* $ Detailed_Output */

/*     Y          is the input measurement converted to the desired */
/*                units. */


/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If the input units, output units, or both input and */
/*        output units are not recognized, the error */
/*        SPICE(UNITSNOTREC) is signaled. */

/*     2) If the units being converted between are incompatible, the */
/*        error SPICE(INCOMPATIBLEUNITS) is signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine converts a measurement X given in units specified by */
/*     IN to the equivalent value Y in units specified by OUT. */

/*     If a unit is not recognized, an error message is produced that */
/*     indicates which one was not recognized. */

/*     If input and output units are incompatible (for example ANGLE */
/*     and DISTANCE units) and error message will be produced stating */
/*     the requested units and associated types. */

/* $ Examples */

/*     To convert 1 meter to statute miles and feet you could */

/*        CALL CONVRT ( 1.0D0, 'METERS',        'STATUTE_MILES', MILES ) */
/*        CALL CONVRT ( MILES, 'STATUTE_MILES', 'FEET',          FEET  ) */

/*     or */

/*        CALL CONVRT ( 1.0D0, 'METERS', 'STATUTE_MILES', MILES ) */
/*        CALL CONVRT ( 1.0D0, 'METERS', 'FEET',          FEET  ) */


/* $ Restrictions */

/*     You should make sure that your units are appropriate for the */
/*     measurement. This routine does not do any checking for over- */
/*     flow. Something like */

/*        CALL ( 10.0D22, 'LIGHTYEARS', 'MM', Y ) */

/*     will cause a floating point overflow. */

/*     Some of the units are not "defined" quantities.  In such a case */
/*     a best estimate is provided as of the date of the current version */
/*     of this routine. Those estimated quantities are: */

/*         1 AU    --- the astronomical unit. The value was taken from */
/*                     the JPL ephemeris DE125. This value is an */
/*                     approximation and should not be used for */
/*                     high-accuracy work. It agrees with the value used */
/*                     in the JPL planetary ephemeris DE430 */
/*                     (149597870.700 km) at the 100m level. */

/*         The tropical year is the time from equinox to equinox.  This */
/*         varies slightly with time. */

/*         1 PARSEC --- is dependent upon the value of the astronomical */
/*                      unit. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     C.A. Curzon     (JPL) */
/*     H.A. Neilan     (JPL) */
/*     W.M. Owen       (JPL) */
/*     W.L. Taber      (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 12-MAY-2015 (NJB) */

/*        Added support for full names of metric distance units. Added */
/*        support for the abbreviation 'M' indicating meters. */

/* -    SPICELIB Version 1.0.2, 01-JUL-2014 (NJB) */

/*        Updated the description of the AU in the Restrictions */
/*        section. */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (CAC) (WMO) (WLT) (IMU) */

/* -& */
/* $ Index_Entries */

/*     convert units */

/* -& */
/* $ Revisions */

/* -    Beta Version 1.2.0, 05-JAN-1990 (WLT) */

/*        Data statements for double precision values were changed */
/*        to include a 'D' so that this routine would function properly */
/*        on the Univac. */

/* -   Beta Version 1.1.0, 02-MAR-1989 (HAN) */

/*        The variable LIGHTYEAR was changed to LTYEAR in order to */
/*        comply with the ANSI Fortran Standard six character */
/*        variable name length restriction. */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     1.0d0 divided by the sin of 1 arc second */


/*     Angular Conversions: */

/*                 (1)  Degrees/Radians */
/*                 (2)  Degrees/Degrees */
/*                 (3)  Degrees/ARCMINUTES */
/*                 (4)  Degrees/ARCSECONDS */

/*                 ()   Degrees/HOURANGLE */
/*                 ()   Degrees/MINUTEANGLE */
/*                 ()   Degrees/SECONDANGLE */


/*     DATA CNVRTN (ANG + 1)  /      DPR()   / */

/*     This value will be loaded using the SPICELIB function DPR() */
/*     on the first execution of this routine. */


/*     Distance Conversions ( 8 through 17 ) */

/*                 (+  1) Meters/Meter */
/*                 (+  2) Meters/Km */
/*                 (+  3) Meters/Cm */
/*                 (+  4) Meters/mm */
/*                 (+  5) Meters/Lightsecs */
/*                 (+  6) Meters/AU */
/*                 (+  7) Meters/Meter */
/*                 (+  8) Meters/Km */
/*                 (+  9) Meters/cm */
/*                 (+ 10) Meters/mm */


/*     Distance Conversions */

/*                 (+ 11) Meters/Foot */
/*                 (+ 12) Meters/inch */
/*                 (+ 13) Meters/Statute Mile */
/*                 (+ 14) Meters/Nautical Mile */
/*                 (+ 15) Meters/Yard */


/*     Distance Conversions */

/*                 (+ 16) Meters/LightYear */
/*                 (+ 17) Meters/Parsec */


/*     Time Conversions */

/*                 (+ 1 ) seconds / second */
/*                 (+ 2 ) seconds / minute */
/*                 (+ 3 ) seconds / hour */
/*                 (+ 4 ) seconds / day */
/*                 (+ 5 ) Seconds / Julian year */
/*                 (+ 6 ) Seconds / Tropical year */
/*                 (+ 7 ) Seconds / year          --- same as Julian year */


/*     Set up the error processing. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "CONVRT", (ftnlen)6);
    if (__state->first) {
	__state->cnvrtn[0] = dpr_(__global_state);
	__state->first = FALSE_;
    }
    ucase_(__global_state, in, inu, in_len, (ftnlen)16);
    ucase_(__global_state, out, outu, out_len, (ftnlen)16);
    i__ = isrchc_(__global_state, inu, &__state->c__31, __state->units, (
	    ftnlen)16, (ftnlen)16);
    j = isrchc_(__global_state, outu, &__state->c__31, __state->units, (
	    ftnlen)16, (ftnlen)16);
    if (i__ == 0 || j == 0) {
	if (i__ == 0 && j == 0) {
/* Writing concatenation */
	    i__1[0] = 32, a__1[0] = "CONVRT: Neither the input units ";
	    i__1[1] = 16, a__1[1] = inu;
	    i__1[2] = 21, a__1[2] = "nor the output units ";
	    i__1[3] = 16, a__1[3] = outu;
	    i__1[4] = 16, a__1[4] = "were recognized.";
	    s_cat(&__global_state->f2c, ch__1, a__1, i__1, &__state->c__5, (
		    ftnlen)101);
	    setmsg_(__global_state, ch__1, (ftnlen)101);
	    sigerr_(__global_state, "SPICE(UNITSNOTREC)", (ftnlen)18);
	    chkout_(__global_state, "CONVRT", (ftnlen)6);
	    return 0;
	} else if (i__ == 0) {
/* Writing concatenation */
	    i__2[0] = 20, a__2[0] = "CONVRT: Input units ";
	    i__2[1] = 16, a__2[1] = inu;
	    i__2[2] = 20, a__2[2] = " were not recognized";
	    s_cat(&__global_state->f2c, ch__2, a__2, i__2, &__state->c__3, (
		    ftnlen)56);
	    setmsg_(__global_state, ch__2, (ftnlen)56);
	    sigerr_(__global_state, "SPICE(UNITSNOTREC)", (ftnlen)18);
	    chkout_(__global_state, "CONVRT", (ftnlen)6);
	    return 0;
	} else if (j == 0) {
/* Writing concatenation */
	    i__2[0] = 21, a__2[0] = "CONVRT: Output units ";
	    i__2[1] = 16, a__2[1] = outu;
	    i__2[2] = 20, a__2[2] = " were not recognized";
	    s_cat(&__global_state->f2c, ch__3, a__2, i__2, &__state->c__3, (
		    ftnlen)57);
	    setmsg_(__global_state, ch__3, (ftnlen)57);
	    sigerr_(__global_state, "SPICE(UNITSNOTREC)", (ftnlen)18);
	    chkout_(__global_state, "CONVRT", (ftnlen)6);
	    return 0;
	}
    }
    if (s_cmp(&__global_state->f2c, __state->type__ + (((i__3 = i__ - 1) < 31 
	    && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, "type", i__3, 
	    "convrt_", (ftnlen)547)) << 3), __state->type__ + (((i__4 = j - 1)
	     < 31 && 0 <= i__4 ? i__4 : s_rnge(&__global_state->f2c, "type", 
	    i__4, "convrt_", (ftnlen)547)) << 3), (ftnlen)8, (ftnlen)8) != 0) 
	    {
/* Writing concatenation */
	i__5[0] = 58, a__3[0] = "CONVRT: Incompatible units. You are attempt"
		"ing to convert ";
	i__5[1] = 16, a__3[1] = inu;
	i__5[2] = 6, a__3[2] = "type: ";
	i__5[3] = 8, a__3[3] = __state->type__ + (((i__3 = i__ - 1) < 31 && 0 
		<= i__3 ? i__3 : s_rnge(&__global_state->f2c, "type", i__3, 
		"convrt_", (ftnlen)549)) << 3);
	i__5[4] = 4, a__3[4] = " to ";
	i__5[5] = 16, a__3[5] = outu;
	i__5[6] = 6, a__3[6] = "type: ";
	i__5[7] = 8, a__3[7] = __state->type__ + (((i__4 = j - 1) < 31 && 0 <=
		 i__4 ? i__4 : s_rnge(&__global_state->f2c, "type", i__4, 
		"convrt_", (ftnlen)549)) << 3);
	i__5[8] = 1, a__3[8] = ".";
	s_cat(&__global_state->f2c, ch__4, a__3, i__5, &__state->c__9, (
		ftnlen)123);
	setmsg_(__global_state, ch__4, (ftnlen)123);
	sigerr_(__global_state, "SPICE(INCOMPATIBLEUNITS)", (ftnlen)24);
	chkout_(__global_state, "CONVRT", (ftnlen)6);
	return 0;
    }
    temp = *x * __state->cnvrtn[(i__3 = i__ - 1) < 31 && 0 <= i__3 ? i__3 : 
	    s_rnge(&__global_state->f2c, "cnvrtn", i__3, "convrt_", (ftnlen)
	    565)];
    *y = temp / __state->cnvrtn[(i__3 = j - 1) < 31 && 0 <= i__3 ? i__3 : 
	    s_rnge(&__global_state->f2c, "cnvrtn", i__3, "convrt_", (ftnlen)
	    566)];
    chkout_(__global_state, "CONVRT", (ftnlen)6);
    return 0;
} /* convrt_ */

