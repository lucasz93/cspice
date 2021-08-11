/* jul2gr.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern jul2gr_init_t __jul2gr_init;
static jul2gr_state_t* get_jul2gr_state() {
	cspice_t* state =  __cspice_get_state();
	if (!state->jul2gr)
		state->jul2gr = __cspice_allocate_module(sizeof(
	jul2gr_state_t), &__jul2gr_init, sizeof(__jul2gr_init));
	return state->jul2gr;

}

/* $Procedure      JUL2GR (Julian to Gregorian Calendar) */
/* Subroutine */ int jul2gr_0_(int n__, integer *year, integer *month, 
	integer *day, integer *doy)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6, i__7, i__8;

    /* Builtin functions */
    integer s_rnge(char *, integer, char *, integer);

    /* Local variables */
    extern /* Subroutine */ int rmaini_(integer *, integer *, integer *, 
	    integer *);
    extern integer lstlti_(integer *, integer *, integer *);

    /* Module state */
    jul2gr_state_t* __state = get_jul2gr_state();
/* $ Abstract */

/*     Convert Year Month and Day on the Julian Calendar */
/*     to the Gregorian Calendar */

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

/*      None. */

/* $ Keywords */

/*      TIME */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     YEAR      I/O  Year  of Julian Calendar/Gregorian Calendar */
/*     MONTH     I/O  Month of Julian Calendar/Gregorian Calendar */
/*     DAY       I/O  Day of Month in Julian Calendar/Gregorian Calendar */
/*     DOY        O   Day of Year in Gregorian Calendar */

/* $ Detailed_Input */

/*     YEAR      is an integer representing the year of an epoch, E, in */
/*               the Julian proleptic calendar. Note that the year 0 */
/*               and negative values are required to represent */
/*               years in the pre-Christian era (B.C.)  A year, Y B.C., */
/*               should be represented as -(Y-1).  For example the year */
/*               435 B.C. should be input as -434. */

/*     MONTH     is an integer representing the month of some epoch, E, */
/*               in the Julian proleptic calendar. Months */
/*               outside the usual range from 1 to 12 are converted */
/*               to the standard range using modular arithmetic and */
/*               the input year is adjusted appropriately. */


/*     DAY       is the day of the month of some epoch, E, in the Julian */
/*               proleptic calendar. */

/*               Note to input an epoch as the day of a year, set MONTH */
/*               to 1 and DAY to the day of the year. */

/* $ Detailed_Output */

/*     YEAR      is an integer representing the year of the epoch, E, */
/*               above in the Gregorian calendar. Note that the year */
/*               0 (zero) and negative values are used to represent */
/*               years in the pre-Christian era (B.C.)  A year, Y B.C., */
/*               is be reprented as -(Y-1).  For example the year */
/*               435 B.C. will be returned as -434. */

/*     MONTH     is an integer representing the month of the epoch, E, */
/*               above in the Gregorian Calendar calendar. */

/*     DAY       is the day of the month of the epoch, E, above in the */
/*               Gregorian Calendar */

/*     DOY       is the day of the year of the epoch, E, above in the */
/*               Gregorian Calendar. */

/* $ Parameters */

/*     None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     None. */

/* $ Particulars */

/*     This is a mid-level utility routine to assist in the assignment */
/*     and presentation of ancient epochs. */

/*     The SPICE software deals primarily with epochs represented on */
/*     in the Gregororian Calendar.  However, the Gregorian calendar */
/*     was not adopted until October 15, 1582.  As a result, epochs */
/*     prior to that time are usually represented in the Julian */
/*     proleptic calendar. */

/*     Formally, both calendars can be extended indefinitely forward */
/*     and backward in time due the algorithmic nature of the */
/*     determination of calendar representation. */

/*     When converting "parsed" calendar epochs in the SPICE system, */
/*     you need to first convert to the Gregorian Calendar. From that */
/*     point the SPICE toolkit can easily convert the epoch to Julian */
/*     date or seconds past the J2000 epoch. */

/*     This routine allows you to take a numeric representation of */
/*     an epoch represented in the Julian proleptic calendar and */
/*     convert that to an epoch in the Gregorian calendar. */

/*     To convert from Gregorian Calendar to Julian proleptic */
/*     calendar, use the entry point GR2JUL. */

/* $ Examples */

/*     Suppose you need to find the epoch (in seconds past the */
/*     J2000) of some ancient epoch that occurred at */
/*     3:00 on March 4 of the year 121 B.C.  And that this epoch */
/*     is based on the Julian proleptic calendar.  We first need */
/*     to convert the Julian Calendar date to the Gregorian Calendar. */

/*     Here's the declarations we'll need */

/*        INTEGER               YEAR */
/*        INTEGER               MONTH */
/*        INTEGER               DAY */
/*        INTEGER               DOY */

/*        DOUBLE PRECISION      TVEC ( 6 ) */
/*        DOUBLE PRECISION      TDB */

/*     You first need to convert the calendar date of this epoch */
/*     integers. (We don't need to worry about the hours for a moment). */

/*        YEAR  = -120 */
/*        MONTH =  3 */
/*        DAY   =  4 */

/*     Convert this Year, Month and Day to the Gregorian Calendar. */

/*        CALL JUL2GR ( YEAR, MONTH, DAY, DOY ) */

/*     Now construct a time vector for use in the routine TTRANS. */
/*     Note now we use the hour component of the epoch (the fourth */
/*     component of the time vector TVEC). */

/*        TVEC(1) = DBLE( YEAR ) */
/*        TVEC(2) = DBLE( MONTH ) */
/*        TVEC(3) = DBLE( DAY ) */
/*        TVEC(4) = 3.0D0 */
/*        TVEC(5) = 0.0D0 */
/*        TVEC(6) = 0.0D0 */

/*     Now the routine TTRANS can convert the time vector from */
/*     the input YMD format to barycentric dynamical time. */

/*        CALL TTRANS ( 'YDM', 'TDB', TVEC ) */

/*        TDB = TVEC(1) */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.2.0, 26-AUG-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in RMAINI calls. */

/* -    SPICELIB Version 1.1.1, 23-SEP-1999 (WLT) */

/*        Removed the unused variable DPMON. */

/* -    SPICELIB Version 1.1.0, 23-FEB-1998 (WLT) */

/*        The routine was upgraded so that it will handle without */
/*        error months that are outside the range from 1 to 12. */

/* -    SPICELIB Version 1.0.0, 13-MAR-1996 (WLT) */


/* -& */
/* $ Index_Entries */

/*     Convert from Julian proleptic to Gregorian Calendar */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.1.0, 26-AUG-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in RMAINI calls. */

/* -& */

/*     Spicelib Functions */


/*     Local (in-line) Functions */


/*     Local parameters */

/*     We declare the variables that contain the number of days in */
/*     400 years (Gregorian), 100 years (Gregorian), 4 years and 1 year. */


/*     The following integers give the number of days during the */
/*     associated month of a non-leap year. */


/*     The integers that follow give the number of days in a normal */
/*     year that precede the first of the month. */


/*     The integers that follow give the number of days in a leap */
/*     year that precede the first of the month. */


/*     Local variables */


/*     The array EXTRA contains the number of additional days that */
/*     appear before the first of a month during a leap year (as opposed */
/*     to a non-leap year). */


/*     DPJAN0(I) gives the number of days that occur before the I'th */
/*     month of a normal year. */


/*     Saved variables */


/*     Initial values */

    switch(n__) {
	case 1: goto L_gr2jul;
	}


/*     Definitions of statment functions. */

/*     The number of days ellapsed since Gregorian Jan 1, of year 1 A.D. */
/*     to Jan 1 of YR is given by: */


/*     The number of days ellapsed since Julian Jan 1, of year 1 A.D. */
/*     to Jan 1 of YR is given by: */


/*     Return 1 if YR is divisible by M, otherwise return 0. */


/*     The number of leap days in a Gregorian year is given by: */


/*     The number of leap days in a Julian year is given by: */


/*     To compute the day of the year we */

/*        look up the number of days to the beginning of the month, */

/*        add on the number leap days that occurred prior to that */
/*        time */

/*        add on the number of days into the month */


/*     The number of days since 1 Jan 1 A.D. (Gregorian) is given by: */


/*     The number of days since 1 Jan 1 A.D. (Julianis given by: */


/*     If this is the first pass through this entry point (or the */
/*     companion entry point) we need to set up some reference points. */

/*     RDAYG   is the number of days past 1 A.D. Jan 1 of the Gregorian */
/*             calendar of the date Oct 15, 1582 */

/*     RDAYJ   is the number of days past 1 A.D. Jan 1 of the Julian */
/*             calendar of the date Oct 5, 1582. */

/*     OFFSTJ and OFFSTG are just the offset from one count of days */
/*     to the other. */

    if (__state->first) {
	__state->first = FALSE_;
/* Computing MAX */
	i__3 = 0, i__4 = 1 + abs(__state->c__1582) / __state->c__4 * 
		__state->c__4 - abs(__state->c__1582);
/* Computing MAX */
	i__5 = 0, i__6 = 1 + abs(__state->c__1582) / __state->c__100 * 
		__state->c__100 - abs(__state->c__1582);
/* Computing MAX */
	i__7 = 0, i__8 = 1 + abs(__state->c__1582) / __state->c__400 * 
		__state->c__400 - abs(__state->c__1582);
	__state->rdayg = 365 * (__state->c__1582 - 1) + (__state->c__1582 - 1)
		 / 4 - (__state->c__1582 - 1) / 100 + (__state->c__1582 - 1) /
		 400 + (__state->dpjan0[(i__1 = __state->c__10 - 1) < 12 && 0 
		<= i__1 ? i__1 : s_rnge("dpjan0", i__1, "jul2gr_", (ftnlen)
		535)] + __state->extra[(i__2 = __state->c__10 - 1) < 12 && 0 
		<= i__2 ? i__2 : s_rnge("extra", i__2, "jul2gr_", (ftnlen)535)
		] * (max(i__3,i__4) - max(i__5,i__6) + max(i__7,i__8)) + 
		__state->c__15) - 1;
/* Computing MAX */
	i__3 = 0, i__4 = 1 + abs(__state->c__1582) / __state->c__4 * 
		__state->c__4 - abs(__state->c__1582);
	__state->rdayj = 365 * (__state->c__1582 - 1) + (__state->c__1582 - 1)
		 / 4 + (__state->dpjan0[(i__1 = __state->c__10 - 1) < 12 && 0 
		<= i__1 ? i__1 : s_rnge("dpjan0", i__1, "jul2gr_", (ftnlen)
		536)] + __state->extra[(i__2 = __state->c__10 - 1) < 12 && 0 
		<= i__2 ? i__2 : s_rnge("extra", i__2, "jul2gr_", (ftnlen)536)
		] * max(i__3,i__4) + __state->c__5) - 1;
	__state->offstj = __state->rdayj - __state->rdayg;
	__state->offstg = __state->rdayg - __state->rdayj;
    }

/*     Make local copies of the year, month and day.  Then get the */
/*     YEARs into a positive range. */

    i__1 = *month - 1;
    rmaini_(&i__1, &__state->c__12, &__state->yroff, &__state->mon);
    __state->yr = *year + __state->yroff;
    ++__state->mon;
    __state->dy = *day;
    if (__state->yr <= 0) {
	rmaini_(&__state->yr, &__state->c__4, &__state->m4, &__state->tmpyr);
	__state->yr = __state->tmpyr;
	if (__state->yr == 0) {
	    __state->yr += 4;
	    --__state->m4;
	}
	__state->offset = __state->m4 * 1461;
    } else {
	__state->offset = 0;
    }

/*     First get the day number (Julian) for the input */
/*     year month and day. */

/* Computing MAX */
    i__3 = 0, i__4 = 1 + abs(__state->yr) / __state->c__4 * __state->c__4 - 
	    abs(__state->yr);
    __state->dayj = 365 * (__state->yr - 1) + (__state->yr - 1) / 4 + (
	    __state->dpjan0[(i__1 = __state->mon - 1) < 12 && 0 <= i__1 ? 
	    i__1 : s_rnge("dpjan0", i__1, "jul2gr_", (ftnlen)574)] + 
	    __state->extra[(i__2 = __state->mon - 1) < 12 && 0 <= i__2 ? i__2 
	    : s_rnge("extra", i__2, "jul2gr_", (ftnlen)574)] * max(i__3,i__4) 
	    + __state->dy) - 1 + __state->offset;

/*     This day is DAYJ - RDAYJ days after 1582 Oct 5 on the */
/*     julian calendar.  But this is the same as the number */
/*     of days past 1582 Oct 15 on the Gregorian Calendar */
/*     So the Gregorian day number is DAYJ - RDAYJ + RDAYG */
/*     which is the same as DAYJ + OFFSTG. */

    __state->dayg = __state->dayj + __state->offstg;

/*     Now that we have the Gregorian day number it's a fairly */
/*     straight forward task to get the year, month and day */
/*     on the Gregorian calendar. */

    rmaini_(&__state->dayg, &__state->c_b27, &__state->m400, &__state->tmpday)
	    ;
    __state->dayg = __state->tmpday;
/* Computing MIN */
    i__1 = 3, i__2 = __state->dayg / 36524;
    __state->m100 = min(i__1,i__2);
    __state->dayg -= __state->m100 * 36524;
/* Computing MIN */
    i__1 = 24, i__2 = __state->dayg / 1461;
    __state->m4 = min(i__1,i__2);
    __state->dayg -= __state->m4 * 1461;
/* Computing MIN */
    i__1 = 3, i__2 = __state->dayg / 365;
    __state->m = min(i__1,i__2);
    __state->dayg -= __state->m * 365;
    __state->dofyr = __state->dayg + 1;
    __state->yr = __state->m400 * 400 + __state->m100 * 100 + (__state->m4 << 
	    2) + __state->m + 1;

/*     Now look up the month number and compute the day of the month. */
/*     How we do this depends on whether or not this is a leap year. */

/* Computing MAX */
    i__1 = 0, i__2 = 1 + abs(__state->yr) / __state->c__4 * __state->c__4 - 
	    abs(__state->yr);
/* Computing MAX */
    i__3 = 0, i__4 = 1 + abs(__state->yr) / __state->c__100 * __state->c__100 
	    - abs(__state->yr);
/* Computing MAX */
    i__5 = 0, i__6 = 1 + abs(__state->yr) / __state->c__400 * __state->c__400 
	    - abs(__state->yr);
    if (max(i__1,i__2) - max(i__3,i__4) + max(i__5,i__6) == 0) {
	__state->mon = lstlti_(&__state->dofyr, &__state->c__12, 
		__state->dpjan0);
	__state->dy = __state->dofyr - __state->dpjan0[(i__1 = __state->mon - 
		1) < 12 && 0 <= i__1 ? i__1 : s_rnge("dpjan0", i__1, "jul2gr_"
		, (ftnlen)616)];
    } else {
	__state->mon = lstlti_(&__state->dofyr, &__state->c__12, 
		__state->dpbegl);
	__state->dy = __state->dofyr - __state->dpbegl[(i__1 = __state->mon - 
		1) < 12 && 0 <= i__1 ? i__1 : s_rnge("dpbegl", i__1, "jul2gr_"
		, (ftnlen)619)];
    }
    *year = __state->yr;
    *month = __state->mon;
    *day = __state->dy;
    *doy = __state->dofyr;
    return 0;
/* $Procedure      GR2JUL (Gregorian to Julian Calendar) */

L_gr2jul:
/* $ Abstract */

/*     Convert Year Month and Day on the  Gregorian Calendar */
/*     to the Julian Calendar */

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

/*      None. */

/* $ Keywords */

/*      TIME */

/* $ Declarations */

/*     INTEGER               YEAR */
/*     INTEGER               MONTH */
/*     INTEGER               DAY */
/*     INTEGER               DOY */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     YEAR      I/O  Year  of Gregorian Calendar/Julian Calendar */
/*     MONTH     I/O  Month of Gregorian Calendar/Julian Calendar */
/*     DAY       I/O  Day of Month in Gregorian Calendar/Julian Calendar */
/*     DOY        O   Day of Year in Julian Calendar */

/* $ Detailed_Input */

/*     YEAR      is an integer representing the year of an epoch, E, in */
/*               the Gregorian calendar. Note that the year 0 (zero) */
/*               and negative values are required to represent */
/*               years in the pre-Christian era (B.C.)  A year, Y B.C. */
/*               should be reprented as -(Y-1).  For example the year */
/*               435 B.C. should be input as -434. */

/*     MONTH     is an integer representing the month of some epoch, E, */
/*               in the Gregorian calendar. Months */
/*               outside the usual range from 1 to 12 are converted */
/*               to the standard range using modular arithmetic and */
/*               the input year is adjusted appropriately. */

/*     DAY       is the day of the month of some epoch, E, in the */
/*               Gregorian calendar. */

/*               Note to input an epoch as the day of a year, set MONTH */
/*               to 1 and DAY to the day of the year. */

/* $ Detailed_Output */

/*     YEAR      is an integer representing the year of the epoch, E, */
/*               above in the Julian calendar. Note that the year 0 */
/*               (zero) and negative values are used to represent */
/*               years in the pre-Christian era (B.C.)  A year, Y B.C., */
/*               is be reprented as -(Y-1).  For example the year */
/*               435 B.C. will be returned as -434. */

/*     MONTH     is an integer representing the month of the epoch, E, */
/*               above in the Julian Calendar calendar. */

/*     DAY       is the day of the month of the epoch, E, above in the */
/*               Julian Calendar */

/*     DOY       is the day of the year of the epoch, E, above in the */
/*               Julian Calendar. */

/* $ Parameters */

/*     None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     None. */

/* $ Particulars */

/*     This is a mid-level utility routine to assist in the assignment */
/*     and presentation of Ancient epochs. */

/*     The SPICE software deals primarily with epochs represented on */
/*     in the Gregororian Calendar.  However, the Gregorian calendar */
/*     was not adopted until October 15, 1582.  As a result, epochs */
/*     prior to that time are usually represented in the Julian */
/*     proleptic calendar. */

/*     Formally, both calendars can be extended indefinitely forward */
/*     and backward in time due the algorithmic nature of the */
/*     determination of calendar representation. */

/*     This routine allows you to take a numeric representation of */
/*     an epoch represented in the Gregorian calendar and */
/*     convert that to an epoch in the Julian calendar. */

/*     To convert from Julian Calendar to Gregorian */
/*     calendar, use the entry point JUL2GR. */

/* $ Examples */

/*     Suppose you need to print an epoch (given in seconds past the */
/*     J2000 epoch) of some ancient epoch that occured during */
/*     pre-Christian era, and that you want to represent this epoch */
/*     using the Julian proleptic calendar. */

/*     Here's the declarations we'll need */

/*        INTEGER               YEAR */
/*        INTEGER               MONTH */
/*        INTEGER               DAY */
/*        INTEGER               DOY */

/*        DOUBLE PRECISION      TVEC ( 6 ) */
/*        DOUBLE PRECISION      TDB */

/*     You first need to convert TDB (the epoch in Seconds past J2000) */
/*     to a calendar representation. */

/*        TVEC(1) = TDB. */

/*        CALL TTRANS ( 'TDB', 'YMD', TVEC ) */

/*     The output time vector will be relative to the Gregorian */
/*     Calendar.  Collect the year, month and day from the time */
/*     vectory. */

/*        YEAR    = INT ( TVEC(1) ) */
/*        MONTH   = INT ( TVEC(2) ) */
/*        DAY     = INT ( TVEC(3) ) */

/*     The hours, minutes and seconds appear in components 4 through 6 */
/*     of the time vector.  We can ignore them in the conversion */
/*     of the calendar from Gregorian to Julian. */

/*        CALL GR2JUL ( YEAR, MONTH, DAY, DOY ) */

/*     Now create a string from the YEAR, MONTH, DAY and TVEC(4) */
/*     through TVEC(6). */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 23-FEB-1998 (WLT) */

/*        The routine was upgraded so that it will handle without */
/*        error months that are outside the range from 1 to 12. */

/* -    SPICELIB Version 1.0.0, 13-MAR-1996 (WLT) */


/* -& */
/* $ Index_Entries */

/*     Convert from Gregorian to Julian Calendar */

/* -& */

/*     If this is the first pass through this entry point (or the */
/*     companion entry point) we need to set up some reference points. */

/*     RDAYG   is the number of days past 1 A.D. Jan 1 of the Gregorian */
/*             calendar of the date Oct 15, 1582 */

/*     RDAYJ   is the number of days past 1 A.D. Jan 1 of the Julian */
/*             calendar of the date Oct 5, 1582. */

/*     OFFSTJ and OFFSTG are just the offset from one count of days */
/*     to the other. */

    if (__state->first) {
	__state->first = FALSE_;
/* Computing MAX */
	i__3 = 0, i__4 = 1 + abs(__state->c__1582) / __state->c__4 * 
		__state->c__4 - abs(__state->c__1582);
/* Computing MAX */
	i__5 = 0, i__6 = 1 + abs(__state->c__1582) / __state->c__100 * 
		__state->c__100 - abs(__state->c__1582);
/* Computing MAX */
	i__7 = 0, i__8 = 1 + abs(__state->c__1582) / __state->c__400 * 
		__state->c__400 - abs(__state->c__1582);
	__state->rdayg = 365 * (__state->c__1582 - 1) + (__state->c__1582 - 1)
		 / 4 - (__state->c__1582 - 1) / 100 + (__state->c__1582 - 1) /
		 400 + (__state->dpjan0[(i__1 = __state->c__10 - 1) < 12 && 0 
		<= i__1 ? i__1 : s_rnge("dpjan0", i__1, "jul2gr_", (ftnlen)
		850)] + __state->extra[(i__2 = __state->c__10 - 1) < 12 && 0 
		<= i__2 ? i__2 : s_rnge("extra", i__2, "jul2gr_", (ftnlen)850)
		] * (max(i__3,i__4) - max(i__5,i__6) + max(i__7,i__8)) + 
		__state->c__15) - 1;
/* Computing MAX */
	i__3 = 0, i__4 = 1 + abs(__state->c__1582) / __state->c__4 * 
		__state->c__4 - abs(__state->c__1582);
	__state->rdayj = 365 * (__state->c__1582 - 1) + (__state->c__1582 - 1)
		 / 4 + (__state->dpjan0[(i__1 = __state->c__10 - 1) < 12 && 0 
		<= i__1 ? i__1 : s_rnge("dpjan0", i__1, "jul2gr_", (ftnlen)
		851)] + __state->extra[(i__2 = __state->c__10 - 1) < 12 && 0 
		<= i__2 ? i__2 : s_rnge("extra", i__2, "jul2gr_", (ftnlen)851)
		] * max(i__3,i__4) + __state->c__5) - 1;
	__state->offstj = __state->rdayj - __state->rdayg;
	__state->offstg = __state->rdayg - __state->rdayj;
    }

/*     Make Local Copies of YEAR, MONTH and DAY and get YEAR into */
/*     a positive range. */

    i__1 = *month - 1;
    rmaini_(&i__1, &__state->c__12, &__state->yroff, &__state->mon);
    __state->yr = *year + __state->yroff;
    ++__state->mon;
    __state->dy = *day;
    if (__state->yr <= 0) {
	rmaini_(&__state->yr, &__state->c__400, &__state->m400, &
		__state->tmpyr);
	__state->yr = __state->tmpyr;
	if (__state->yr == 0) {
	    __state->yr += 400;
	    --__state->m400;
	}
	__state->offset = __state->m400 * 146097;
    } else {
	__state->offset = 0;
    }

/*     First get the day number (Gregorian) for the input */
/*     year month and day. */

/* Computing MAX */
    i__3 = 0, i__4 = 1 + abs(__state->yr) / __state->c__4 * __state->c__4 - 
	    abs(__state->yr);
/* Computing MAX */
    i__5 = 0, i__6 = 1 + abs(__state->yr) / __state->c__100 * __state->c__100 
	    - abs(__state->yr);
/* Computing MAX */
    i__7 = 0, i__8 = 1 + abs(__state->yr) / __state->c__400 * __state->c__400 
	    - abs(__state->yr);
    __state->dayg = 365 * (__state->yr - 1) + (__state->yr - 1) / 4 - (
	    __state->yr - 1) / 100 + (__state->yr - 1) / 400 + (
	    __state->dpjan0[(i__1 = __state->mon - 1) < 12 && 0 <= i__1 ? 
	    i__1 : s_rnge("dpjan0", i__1, "jul2gr_", (ftnlen)888)] + 
	    __state->extra[(i__2 = __state->mon - 1) < 12 && 0 <= i__2 ? i__2 
	    : s_rnge("extra", i__2, "jul2gr_", (ftnlen)888)] * (max(i__3,i__4)
	     - max(i__5,i__6) + max(i__7,i__8)) + __state->dy) - 1 + 
	    __state->offset;

/*     This day is DAYG - RDAYG days after 1582 Oct 15 on the */
/*     Gregorian calendar.  But this is the same as the number */
/*     of days past 1582 Oct 5 on the Julian Calendar */
/*     So the Julian day number is DAYG - RDAYG + RDAYJ */
/*     which is the same as DAYG + OFFSTJ. */

    __state->dayj = __state->dayg + __state->offstj;

/*     Now that we have the Julian day number it's a fairly */
/*     straight forward task to get the year, month and day */
/*     on the Julian calendar. */

    rmaini_(&__state->dayj, &__state->c__1461, &__state->m4, &__state->tmpday)
	    ;
    __state->dayj = __state->tmpday;
/* Computing MIN */
    i__1 = 3, i__2 = __state->dayj / 365;
    __state->m = min(i__1,i__2);
    __state->dayj -= __state->m * 365;
    __state->dofyr = __state->dayj + 1;
    __state->yr = (__state->m4 << 2) + __state->m + 1;

/*     Now look up the month number and compute the day of the month. */
/*     How we do this depends on whether or not this is a leap year. */

/* Computing MAX */
    i__1 = 0, i__2 = 1 + abs(__state->yr) / __state->c__4 * __state->c__4 - 
	    abs(__state->yr);
    if (max(i__1,i__2) == 0) {
	__state->mon = lstlti_(&__state->dofyr, &__state->c__12, 
		__state->dpjan0);
	__state->dy = __state->dofyr - __state->dpjan0[(i__1 = __state->mon - 
		1) < 12 && 0 <= i__1 ? i__1 : s_rnge("dpjan0", i__1, "jul2gr_"
		, (ftnlen)922)];
    } else {
	__state->mon = lstlti_(&__state->dofyr, &__state->c__12, 
		__state->dpbegl);
	__state->dy = __state->dofyr - __state->dpbegl[(i__1 = __state->mon - 
		1) < 12 && 0 <= i__1 ? i__1 : s_rnge("dpbegl", i__1, "jul2gr_"
		, (ftnlen)925)];
    }
    *year = __state->yr;
    *month = __state->mon;
    *day = __state->dy;
    *doy = __state->dofyr;
    return 0;
} /* jul2gr_ */

/* Subroutine */ int jul2gr_(integer *year, integer *month, integer *day, 
	integer *doy)
{
    return jul2gr_0_(0, year, month, day, doy);
    }

/* Subroutine */ int gr2jul_(integer *year, integer *month, integer *day, 
	integer *doy)
{
    return jul2gr_0_(1, year, month, day, doy);
    }

