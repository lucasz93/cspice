/* etcal.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern etcal_init_t __etcal_init;
static etcal_state_t* get_etcal_state() {
	cspice_t* state =  __cspice_get_state();
	if (!state->etcal)
		state->etcal = __cspice_allocate_module(sizeof(etcal_state_t),
	 &__etcal_init, sizeof(__etcal_init));
	return state->etcal;

}

/* $Procedure            ETCAL ( Convert ET to Calendar format ) */
/* Subroutine */ int etcal_(doublereal *et, char *string, ftnlen string_len)
{
    /* Initialized data */


    /* System generated locals */
    address a__1[12];
    integer i__1, i__2, i__3[12];
    doublereal d__1;

    /* Builtin functions */
    integer s_rnge(char *, integer, char *, integer);
    double d_int(doublereal *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int ljust_(char *, char *, ftnlen, ftnlen);
    extern integer intmin_(void);
    extern integer intmax_(void);
    extern /* Subroutine */ int dpstrf_(doublereal *, integer *, char *, char 
	    *, ftnlen, ftnlen);
    extern /* Subroutine */ int cmprss_(char *, integer *, char *, char *, 
	    ftnlen, ftnlen, ftnlen);
    extern integer lstlti_(integer *, integer *, integer *);
    extern /* Subroutine */ int intstr_(integer *, char *, ftnlen);
    extern doublereal spd_(void);

    /* Module state */
    etcal_state_t* __state = get_etcal_state();
/* $ Abstract */


/*     Convert from an ephemeris epoch measured in seconds past */
/*     the epoch of J2000 to a calendar string format using a */
/*     formal calendar free of leapseconds. */

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

/*     TIME */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Ephemeris time measured in seconds past J2000. */
/*     STRING     O   A standard calendar representation of ET. */

/* $ Detailed_Input */

/*     ET       is an epoch measured in ephemeris seconds */
/*              past the epoch of J2000. */

/* $ Detailed_Output */

/*     STRING   is a calendar string representing the input ephemeris */
/*              epoch.  This string is based upon extending the */
/*              Gregorian Calendar backward and forward indefinitely */
/*              keeping the same rules for determining leap years. */
/*              Moreover, there is no accounting for leapseconds. */

/*              To be sure that all of the date can be stored in */
/*              STRING, it should be declared to have length at */
/*              least 48 characters. */

/*              The string will have the following format */

/*                 year (era) mon day hr:mn:sc.sss */

/*              Where: */

/*                 year --- is the year */
/*                 era  --- is the chronological era associated with */
/*                          the date.  For years after 999 A.D. */
/*                          the era is omitted.  For years */
/*                          between 1 A.D. and 999 A.D. (inclusive) */
/*                          era is the string 'A.D.' For epochs */
/*                          before 1 A.D. Jan 1 00:00:00, era is */
/*                          given as 'B.C.' and the year is converted */
/*                          to years before the "Christian Era". */
/*                          The last B.C. epoch is */

/*                            1 B.C. DEC 31 23:59:59.999 */

/*                          The first A.D. epoch (which occurs .001 */
/*                          seconds after the last B.C. epoch) is: */

/*                             1 A.D. JAN 1 00:00:00.000 */

/*                          Note: there is no year 0 A.D. or 0 B.C. */
/*                 mon  --- is a 3-letter abbreviation for the month */
/*                          in all capital letters. */
/*                 day  --- is the day of the month */
/*                 hr   --- is the hour of the day (between 0 and 23) */
/*                          leading zeros are added to hr if the */
/*                          numeric value is less than 10. */
/*                 mn   --- is the minute of the hour (0 to 59) */
/*                          leading zeros are added to mn if the */
/*                          numeric value is less than 10. */
/*                 sc.sss   is the second of the minute to 3 decimal */
/*                          places ( 0 to 59.999).  Leading zeros */
/*                          are added if the numeric value is less */
/*                          than 10.  Seconds are truncated, not */
/*                          rounded. */


/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/*     1) If the input ET is so large that the corresponding */
/*        number of days since 1 A.D. Jan 1, 00:00:00 is */
/*        within 1 of overflowing or underflowing an integer, */
/*        ET will not be converted to the correct string */
/*        representation rather, the string returned will */
/*        state that the epoch was before or after the day */
/*        that is INTMIN +1 or INTMAX - 1 days after */
/*        1 A.D. Jan 1, 00:00:00. */

/*     2) If the output string is not sufficiently long to hold */
/*        the full date, it will be truncated on the right. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This is an error free routine for converting ephemeris epochs */
/*     represented as seconds past the J2000 epoch to formal */
/*     calendar strings based upon the Gregorian Calendar.  This formal */
/*     time is often useful when one needs a human recognizable */
/*     form of an ephemeris epoch.  There is no accounting for leap */
/*     seconds in the output times produced. */

/*     Note: The calendar epochs produced are not the same as the */
/*           UTC calendar epochs that correspond to ET. The strings */
/*           produced by this routine may vary from the corresponding */
/*           UTC epochs by more than 1 minute. */

/*     This routine can be used in creating error messages or */
/*     in routines and programs in which one prefers to report */
/*     times without employing leapseconds to produce exact UTC */
/*     epochs. */


/* $ Examples */

/*     Suppose you wish to  report that no data is */
/*     available at a particular ephemeris epoch ET.  The following */
/*     code shows how you might accomplish this task. */

/*     CALL DPSTRF ( ET,  6, 'F', ETSTR  ) */
/*     CALL ETCAL  ( ET,          STRING ) */

/*     E1 = RTRIM   (             STRING ) */
/*     E2 = RTRIM   (             ETSTR  ) */

/*     WRITE (*,*) 'There is no data available for the body ' */
/*     WRITE (*,*) 'at requested time: ' */
/*     WRITE (*,*) '   ', STRING(1:E1), ' (', ETSTR(1:E2), ')' */


/* $ Restrictions */

/*     One must keep in mind when using this routine that */
/*     ancient times are not based upon the Gregorian */
/*     calendar.  For example the 0 point of the Julian */
/*     Date system is 4713 B.C. Jan 1, 12:00:00 on the Julian */
/*     Calendar.  If one formalized the Gregorian calendar */
/*     and extended it indefinitely, the zero point of the Julian */
/*     date system corresponds to 4714 B.C. NOV 24 12:00:00 on */
/*     the Gregorian calendar.  There are several reasons for this. */
/*     Leap years in the Julian calendar occur every */
/*     4 years (including *all* centuries).  Moreover,  the */
/*     Gregorian calendar "effectively" begins on 15 Oct, 1582 A.D. */
/*     which is 5 Oct, 1582 A.D. in the Julian Calendar. */

/*     Therefore you must be careful in your interpretation */
/*     of ancient dates produced by this routine. */

/* $ Literature_References */

/*     1. "From Sundial to Atomic Clocks---Understanding Time and */
/*         Frequency" by James Jespersen and Jane Fitz-Randolph */
/*         Dover Publications, Inc. New York (1982). */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */
/*     K.R. Gehringer  (JPL) */

/* $ Version */

/* -     SPICELIB Version 2.2.0, 05-MAR-1998 (WLT) */

/*         The documentation concerning the appearance of the output */
/*         time string was corrected so that it does not suggest */
/*         a comma is inserted after the day of the month.  The */
/*         comma was removed from the output string in Version 2.0.0 */
/*         (see the note below) but the documentation was not upgraded */
/*         accordingly. */

/* -     SPICELIB Version 2.1.0, 20-MAY-1996 (WLT) */

/*         Two arrays that were initialized but never used were */
/*         removed. */

/* -     SPICELIB Version 2.0.0, 16-AUG-1995 (KRG) */

/*         If the day number was less than 10, the spacing was off for */
/*         the rest of the time by one space, that for the "tens" digit. */
/*         This has been fixed by using a leading zero when the number of */
/*         days is < 10. */

/*         Also, the comma that appeared between the month/day/year */
/*         and the hour:minute:seconds tokens has been removed. This was */
/*         done in order to make the calendar date format of ETCAL */
/*         consistent with the calendar date format of ET2UTC. */


/* -     SPICELIB Version 1.0.0, 14-DEC-1993 (WLT) */

/* -& */
/* $ Index_Entries */

/*     Convert ephemeris time to a formal calendar date */

/* -& */
/* $ Revisions */

/* -     SPICELIB Version 2.1.0, 20-MAY-1996 (WLT) */

/*         Two arrays that were initialized but never used were */
/*         removed. */

/* -     SPICELIB Version 2.0.0, 16-AUG-1995 (KRG) */

/*         If the day number was less than 10, the spacing was off for */
/*         the rest of the time by one space, that for the "tens" digit. */
/*         This has been fixed byusing a leading zero when the number of */
/*         days is < 10. */

/*         Also, the comma that appeared between the month/day/year */
/*         and the hour:minute:seconds tokens has been removed. This was */
/*         done in order to make the calendar date format of ETCAL */
/*         consistent with the calendar date format of ET2UTC. */

/* -     SPICELIB Version 1.0.0, 14-DEC-1993 (WLT) */

/* -& */

/*     Spicelib Functions. */


/*     We declare the variables that contain the number of days in */
/*     400 years, 100 years, 4 years and 1 year. */


/*     The following integers give the number of days during the */
/*     associated month of a non-leap year. */


/*     The integers that follow give the number of days in a normal */
/*     year that precede the first of the month. */


/*     The integers that follow give the number of days in a leap */
/*     year that precede the first of the month. */


/*     The variables below hold the components of the output string */
/*     before they are put together. */


/*     We will construct our string using the local variable DATE */
/*     and transfer the results to the output STRING when we are */
/*     done. */


/*     MONTHS contains 3-letter abbreviations for the months of the year */


/*     The array EXTRA contains the number of additional days that */
/*     appear before the first of a month during a leap year (as opposed */
/*     to a non-leap year). */


/*     DPJAN0(I) gives the number of days that occur before the I'th */
/*     month of a normal year. */


/*     Definitions of statement functions. */


/*     The number of days elapsed since Jan 1, of year 1 A.D. to */
/*     Jan 1 of YEAR is given by: */


/*     The number of leap days in a year is given by: */


/*     To compute the day of the year we */

/*        look up the number of days to the beginning of the month, */

/*        add on the number leap days that occurred prior to that */
/*        time */

/*        add on the number of days into the month */


/*     The number of days since 1 Jan 1 A.D. is given by: */

    if (__state->first) {
	__state->first = FALSE_;
	__state->halfd = spd_() / 2.;
	__state->secspd = spd_();
	__state->dn2000 = 365 * (__state->c__2000 - 1) + (__state->c__2000 - 
		1) / 4 - (__state->c__2000 - 1) / 100 + (__state->c__2000 - 1)
		 / 400 + (__state->dpjan0[(i__1 = __state->c__1 - 1) < 12 && 
		0 <= i__1 ? i__1 : s_rnge("dpjan0", i__1, "etcal_", (ftnlen)
		571)] + __state->extra[(i__2 = __state->c__1 - 1) < 12 && 0 <=
		 i__2 ? i__2 : s_rnge("extra", i__2, "etcal_", (ftnlen)571)] *
		 ((__state->c__2000 / 4 << 2) / __state->c__2000 - 
		__state->c__2000 / 100 * 100 / __state->c__2000 + 
		__state->c__2000 / 400 * 400 / __state->c__2000) + 
		__state->c__1) - 1;
	__state->dmxint = (doublereal) intmax_();
	__state->dmnint = (doublereal) intmin_();
    }

/*     Now we "in-line" compute the following call. */

/*        call rmaind ( et + halfd, secspd, dp2000, secs ) */

/*     because we can't make a call to rmaind. */

/*     The reader may wonder why we use et + halfd.  The value */
/*     et is seconds past the ephemeris epoch of J2000 which */
/*     is at 2000 Jan 1, 12:00:00.  We want to compute days past */
/*     2000 Jan 1, 00:00:00.  The seconds past THAT epoch is et + halfd. */
/*     We add on 0.0005 seconds so that the string produced will be */
/*     rounded to the nearest millisecond. */

    __state->mydnom = __state->secspd;
    __state->mynum = *et + __state->halfd;
    d__1 = __state->mynum / __state->mydnom;
    __state->q = d_int(&d__1);
    __state->remd = __state->mynum - __state->q * __state->mydnom;
    if (__state->remd < 0.) {
	__state->q += -1.;
	__state->remd += __state->mydnom;
    }
    __state->secs = __state->remd;
    __state->dp2000 = __state->q;

/*     Do something about the problem when ET is vastly */
/*     out of range.  (Day number outside MAX and MIN integer). */

    if (__state->dp2000 + __state->dn2000 < __state->dmnint + 1) {
	__state->dp2000 = __state->dmnint - __state->dn2000 + 1;
	s_copy(__state->messge, "Epoch before ", (ftnlen)16, (ftnlen)13);
	__state->secs = 0.;
    } else if (__state->dp2000 + __state->dn2000 > __state->dmxint - 1) {
	__state->dp2000 = __state->dmxint - __state->dn2000 - 1;
	s_copy(__state->messge, "Epoch after ", (ftnlen)16, (ftnlen)12);
	__state->secs = 0.;
    } else {
	s_copy(__state->messge, " ", (ftnlen)16, (ftnlen)1);
    }

/*     Compute the number of days since 1 .A.D. Jan 1, 00:00:00. */
/*     From the tests in the previous IF-ELSE IF-ELSE block this */
/*     addition is guaranteed not to overflow. */

    __state->daynum = (integer) (__state->dp2000 + (doublereal) 
	    __state->dn2000);

/*     If the number of days is negative, we need to do a little */
/*     work so that we can represent the date in the B.C. era. */
/*     We add enough multiples of 400 years so that the year will */
/*     be positive and then we subtract off the appropriate multiple */
/*     of 400 years later. */

    if (__state->daynum < 0) {

/*        Since we can't make the call below and remain */
/*        error free, we compute it ourselves. */

/*        call rmaini ( daynum, dp400y, offset, daynum ) */

	__state->iq = __state->daynum / 146097;
	__state->rem = __state->daynum - __state->iq * 146097;
	if (__state->rem < 0) {
	    --__state->iq;
	    __state->rem += 146097;
	}
	__state->offset = __state->iq;
	__state->daynum = __state->rem;
	__state->adjust = TRUE_;
    } else {
	__state->adjust = FALSE_;
    }

/*     Next we compute the year.  Divide out multiples of 400, 100 */
/*     4 and 1 year.  Finally combine these to get the correct */
/*     value for year.  (Note this is all integer arithmetic.) */

/*     Recall that DP1Y   =    365 */
/*                 DP4Y   =  4*DPY    + 1 */
/*                 DP100Y = 25*DP4Y   - 1 */
/*                 DP400Y =  4*DP100Y + 1 */

    __state->yr400 = __state->daynum / 146097;
    __state->rem = __state->daynum - __state->yr400 * 146097;
/* Computing MIN */
    i__1 = 3, i__2 = __state->rem / 36524;
    __state->yr100 = min(i__1,i__2);
    __state->rem -= __state->yr100 * 36524;
/* Computing MIN */
    i__1 = 24, i__2 = __state->rem / 1461;
    __state->yr4 = min(i__1,i__2);
    __state->rem -= __state->yr4 * 1461;
/* Computing MIN */
    i__1 = 3, i__2 = __state->rem / 365;
    __state->yr1 = min(i__1,i__2);
    __state->rem -= __state->yr1 * 365;
    __state->dofyr = __state->rem + 1;
    __state->year = __state->yr400 * 400 + __state->yr100 * 100 + (
	    __state->yr4 << 2) + __state->yr1 + 1;

/*     Get the month, and day of month (depending upon whether */
/*     we have a leap year or not). */

    if ((__state->year / 4 << 2) / __state->year - __state->year / 100 * 100 /
	     __state->year + __state->year / 400 * 400 / __state->year == 0) {
	__state->month = lstlti_(&__state->dofyr, &__state->c__12, 
		__state->dpjan0);
	__state->day = __state->dofyr - __state->dpjan0[(i__1 = 
		__state->month - 1) < 12 && 0 <= i__1 ? i__1 : s_rnge("dpjan0"
		, i__1, "etcal_", (ftnlen)698)];
    } else {
	__state->month = lstlti_(&__state->dofyr, &__state->c__12, 
		__state->dpbegl);
	__state->day = __state->dofyr - __state->dpbegl[(i__1 = 
		__state->month - 1) < 12 && 0 <= i__1 ? i__1 : s_rnge("dpbegl"
		, i__1, "etcal_", (ftnlen)701)];
    }

/*     If we had to adjust the year to make it positive, we now */
/*     need to correct it and then convert it to a B.C. year. */

    if (__state->adjust) {
	__state->year += __state->offset * 400;
	__state->year = -__state->year + 1;
	s_copy(__state->era, " B.C. ", (ftnlen)16, (ftnlen)6);
    } else {

/*        If the year is less than 1000, we can't just write it */
/*        out.  We need to add the era.  If we don't do this */
/*        the dates look very confusing. */

	if (__state->year < 1000) {
	    s_copy(__state->era, " A.D. ", (ftnlen)16, (ftnlen)6);
	} else {
	    s_copy(__state->era, " ", (ftnlen)16, (ftnlen)1);
	}
    }

/*     Convert Seconds to Hours, Minute and Seconds. */
/*     We work with thousandths of a second in integer arithmetic */
/*     so that all of the truncation work with seconds will already */
/*     be done.  (Note that we already know that SECS is greater than */
/*     or equal to zero so we'll have no problems with HOURS, MINS */
/*     or SECS becoming negative.) */

    __state->tsecs = (integer) (__state->secs * 1e3);
    __state->frac = __state->secs - (doublereal) __state->tsecs;
    __state->hours = __state->tsecs / 3600000;
    __state->tsecs -= __state->hours * 3600000;
    __state->mins = __state->tsecs / 60000;
    __state->tsecs -= __state->mins * 60000;
    __state->secs = (doublereal) __state->tsecs / 1e3;

/*     We round seconds if we can do so without getting seconds to be */
/*     bigger than 60. */

    if (__state->secs + 5e-4 < 60.) {
	__state->secs += 5e-4;
    }

/*     Finally, get the components of our date string. */

    intstr_(&__state->year, __state->ystr, (ftnlen)16);
    if (__state->day >= 10) {
	intstr_(&__state->day, __state->dstr, (ftnlen)16);
    } else {
	s_copy(__state->dstr, "0", (ftnlen)16, (ftnlen)1);
	intstr_(&__state->day, __state->dstr + 1, (ftnlen)15);
    }

/*     We want to zero pad the hours minutes and seconds. */

    if (__state->hours < 10) {
	__state->bh = 2;
    } else {
	__state->bh = 1;
    }
    if (__state->mins < 10) {
	__state->bm = 2;
    } else {
	__state->bm = 1;
    }
    s_copy(__state->mstr, "00", (ftnlen)16, (ftnlen)2);
    s_copy(__state->hstr, "00", (ftnlen)16, (ftnlen)2);
    s_copy(__state->sstr, " ", (ftnlen)16, (ftnlen)1);

/*     Now construct the string components for hours, minutes and */
/*     seconds. */

    __state->secs = (integer) (__state->secs * 1e3) / 1e3;
    intstr_(&__state->hours, __state->hstr + (__state->bh - 1), 16 - (
	    __state->bh - 1));
    intstr_(&__state->mins, __state->mstr + (__state->bm - 1), 16 - (
	    __state->bm - 1));
    dpstrf_(&__state->secs, &__state->c__6, "F", __state->sstr, (ftnlen)1, (
	    ftnlen)16);

/*     The form of the output for SSTR has a leading blank followed by */
/*     the first significant digit.  If a decimal point is in the */
/*     third slot, then SSTR is of the form ' x.xxxxx'  and we need */
/*     to insert a leading zero. */

    if (*(unsigned char *)&__state->sstr[2] == '.') {
	*(unsigned char *)__state->sstr = '0';
    }

/*     We don't want any leading spaces in SSTR, (HSTR and MSTR don't */
/*     have leading spaces by construction. */

    ljust_(__state->sstr, __state->sstr, (ftnlen)16, (ftnlen)16);

/*     Now form the date string, squeeze out extra spaces and */
/*     left justify the whole thing. */

/* Writing concatenation */
    i__3[0] = 16, a__1[0] = __state->messge;
    i__3[1] = 16, a__1[1] = __state->ystr;
    i__3[2] = 16, a__1[2] = __state->era;
    i__3[3] = 3, a__1[3] = __state->months + ((i__1 = __state->month - 1) < 
	    12 && 0 <= i__1 ? i__1 : s_rnge("months", i__1, "etcal_", (ftnlen)
	    810)) * 3;
    i__3[4] = 1, a__1[4] = " ";
    i__3[5] = 3, a__1[5] = __state->dstr;
    i__3[6] = 1, a__1[6] = " ";
    i__3[7] = 2, a__1[7] = __state->hstr;
    i__3[8] = 1, a__1[8] = ":";
    i__3[9] = 2, a__1[9] = __state->mstr;
    i__3[10] = 1, a__1[10] = ":";
    i__3[11] = 6, a__1[11] = __state->sstr;
    s_cat(__state->date, a__1, i__3, &__state->c__12, (ftnlen)180);
    cmprss_(" ", &__state->c__1, __state->date, __state->date, (ftnlen)1, (
	    ftnlen)180, (ftnlen)180);
    ljust_(__state->date, __state->date, (ftnlen)180, (ftnlen)180);
    s_copy(string, __state->date, string_len, (ftnlen)180);
    return 0;
} /* etcal_ */

