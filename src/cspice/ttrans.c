/* ttrans.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern ttrans_init_t __ttrans_init;
static ttrans_state_t* get_ttrans_state(cspice_t* state) {
	if (!state->ttrans)
		state->ttrans = __cspice_allocate_module(sizeof(
	ttrans_state_t), &__ttrans_init, sizeof(__ttrans_init));
	return state->ttrans;

}

/* $Procedure      TTRANS ( Time transformation ) */
/* Subroutine */ int ttrans_(cspice_t* __global_state, char *from, char *to, 
	doublereal *tvec, ftnlen from_len, ftnlen to_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6, i__7, i__8;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    double d_int(f2c_state_t*, doublereal *);

    /* Local variables */
    extern /* Subroutine */ int zzcvpool_(cspice_t*, char *, integer *, 
	    logical *, ftnlen);
    extern /* Subroutine */ int zzctruin_(cspice_t*, integer *);
    extern logical elemc_(cspice_t*, char *, char *, ftnlen, ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int ucase_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern integer bsrchc_(cspice_t*, char *, integer *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int rmaind_(cspice_t*, doublereal *, doublereal *,
	     doublereal *, doublereal *);
    extern /* Subroutine */ int orderc_(cspice_t*, char *, integer *, integer 
	    *, ftnlen);
    extern integer lstled_(cspice_t*, doublereal *, integer *, doublereal *);
    extern /* Subroutine */ int reordc_(cspice_t*, integer *, integer *, char 
	    *, ftnlen);
    extern /* Subroutine */ int reordi_(cspice_t*, integer *, integer *, 
	    integer *);
    extern integer lstlei_(cspice_t*, integer *, integer *, integer *);
    extern /* Subroutine */ int ssizec_(cspice_t*, integer *, char *, ftnlen);
    extern doublereal unitim_(cspice_t*, doublereal *, char *, char *, ftnlen,
	     ftnlen);
    extern /* Subroutine */ int insrtc_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int reordl_(cspice_t*, integer *, integer *, 
	    logical *);
    extern integer lstlti_(cspice_t*, integer *, integer *, integer *);
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int gdpool_(cspice_t*, char *, integer *, integer 
	    *, integer *, doublereal *, logical *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int swpool_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int nextwd_(cspice_t*, char *, char *, char *, 
	    ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int rmaini_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    extern doublereal j2000_(cspice_t*);
    extern logical odd_(cspice_t*, integer *);
    extern doublereal spd_(cspice_t*);

    /* Module state */
    ttrans_state_t* __state = get_ttrans_state(__global_state);
/* $ Abstract */

/*     Transform a time vector from one representation and system */
/*     to another. */

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

/*     TIME */

/* $ Keywords */

/*     PARSING */
/*     TIME */

/* $ Declarations */
/* $ Abstract */

/*     This include file defines the dimension of the counter */
/*     array used by various SPICE subsystems to uniquely identify */
/*     changes in their states. */

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

/* $ Parameters */

/*     CTRSIZ      is the dimension of the counter array used by */
/*                 various SPICE subsystems to uniquely identify */
/*                 changes in their states. */

/* $ Author_and_Institution */

/*     B.V. Semenov    (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 29-JUL-2013 (BVS) */

/* -& */

/*     End of include file. */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     MXCOMP     P    maximum number of components allowed for TVEC. */
/*     TO         I    description of a time vector. */
/*     FROM       I    description of a time vector. */
/*     TVEC      I/O   time vector representing an epoch. */

/* $ Detailed_Input */

/*     TVEC       is called a time vector.  It is an array of double */
/*                precision numbers that represent some epoch.  To */
/*                determine its meaning you must examine the string */
/*                FROM.  Note that the number of significant entries */
/*                in TVEC is implied by FROM. */

/*     FROM       is a string used to describe the type of time vector */
/*     TO         TVEC.  FROM is the type of the input vector TVEC */
/*                TO is the type of the output TVEC */

/*                The interpretation of TVEC  is as follows: */

/*                TYPE      Interpretation of TVEC */
/*                ------    ------------------------------------------- */
/*                YMD(F)  - year, month, day,   hour, minutes, seconds */
/*                YD(F)   - year,  day-of-year, hour, minutes, seconds */
/*                YD.D(F) - year, number of days past beginning of year */
/*                DAYSEC  - calendar days past 1 jan 1 AD, */
/*                          seconds past beg day */
/*                DP2000  - calendar days past 1 jan 2000, */
/*                          seconds past beg day */
/*                JDUTC   - julian date UTC. */
/*                FORMAL  - seconds in the formal calendar since J2000. */
/*                YWD(F)  - year, week, day, hour, minutes, seconds */
/*                YMWD(F) - year, month, week, day, hour, minutes, */
/*                          seconds */
/*                TAI     - atomic seconds past Atomic J2000. */
/*                TDT     - Terrestrial Dynamical Time */
/*                TDB     - Barycentric Dynamical Time */
/*                JED     - Julian Ephemeris Date (based on TDB) */
/*                ET      - Ephemeris time (same as TDB) */
/*                JDTDB   - Julian Date based on TDB (same as JED) */
/*                JDTDT   - Julian Date based on TDT */

/*                The number of components of TVEC implied by TYPE is */
/*                as follows: */

/*                   YMD     - 6 */
/*                   YD      - 5 */
/*                   JDUTC   - 1 */
/*                   FORMAL  - 1 */
/*                   YD.D    - 2 */
/*                   DAYSEC  - 2 */
/*                   DP2000  - 2 */
/*                   YWD     - 6 */
/*                   YMWD    - 7 */
/*                   TAI     - 1 */
/*                   TDT     - 1 */
/*                   TDB     - 1 */
/*                   JED     - 1 */
/*                   ET      - 1 */
/*                   JDTDB   - 1 */
/*                   JDTDT   - 1 */


/*                For all types, only the last component of the */
/*                time vector may be non-integer.  If other components */
/*                have fractional parts only their truncated integer */
/*                components will be recognized. */

/*                YMD and YD */

/*                   These types are assumed to be different */
/*                   representations on UTC time markers.  Thus */
/*                   the hour, minutes and seconds portions all */
/*                   represent time elapsed */
/*                   since the beginning of a day.  As such the */
/*                   seconds portion of HMS may range up to (but */
/*                   not include) 61 on days when positive leap */
/*                   seconds occur and may range up to (but not */
/*                   include) 59 on days during which negative */
/*                   leapseconds occur. */

/*                YD.D type. */

/*                   Y is the calendar year used in civil time keeping */
/*                   D is the day of the calendar year --- for any time */
/*                     during the first of January, the integer portion */
/*                     of the day will be 1. */

/*                     The fractional portion is the fractional part of */
/*                     the specific day.  Thus the amount of time */
/*                     specified by the fractional portion of the day */
/*                     depends upon whether or not the day has a leap */
/*                     second.  ".D" can be computed from the formula */

/*                           number of seconds past beginning of day */
/*                     .D = --------------------------------------- */
/*                              number of UTC seconds in the day. */

/*                FORMAL type. */

/*                   The FORMAL type for TVEC gives the number of */
/*                   seconds past the epoch J2000 (noon Jan 1 2000) */
/*                   on the formal calendar (no leap seconds --- */
/*                   all days contain 86400 seconds)  The formal clock */
/*                   is simply held still for one second during */
/*                   positive leap seconds.  Times during leap seconds */
/*                   cannot be represented in this system. */

/*                   This system is converted internally to a */
/*                   calendar days past epoch and seconds */
/*                   past beginning of day form.  For this reason, */
/*                   times that occur during a positive leap second */
/*                   can never be represented.  Moreover, if a negative */
/*                   leapsecond occurs, times that occur during the */
/*                   ``missing'' leapsecond will simply be placed */
/*                   at the beginning of the next day.  Thus two */
/*                   different FORMAL times can represent the */
/*                   same time around a negative leap second. */

/*                   FORMAL time is equivalent to somewhat parochial */
/*                   ``UTC seconds past J2000'' that is produced */
/*                   by the SPICE routine TPARSE. */

/*                JDUTC type. */

/*                   This system is similar to the FORMAL system */
/*                   described above.  All days are assumed to have */
/*                   86400 seconds.  All numbers of the form */

/*                      integer + 0.5 */

/*                   fall at the beginning of calendar UTC days. */

/*                   There is no way to represent times during a */
/*                   positive leapsecond. Times during missing */
/*                   negative leap seconds are represented in two ways. */

/*                DAYSEC type. */

/*                   This time vector has the form of calendar */
/*                   days since January 1, of the year 1 A.D. */
/*                   and number of seconds past the beginning of the */
/*                   calendar day. */
/*                   (January 2 of the year 1 A.D. is 1 calendar */
/*                   day past January 1, 1 A.D.) */

/*                DP2000 type. */

/*                   This time vector has the same form as DAYSEC */
/*                   time vectors.  The only difference is that */
/*                   the reference epoch is JAN 1, 2000. */

/*                YWD and YMWD types. */

/*                   These time vectors are used to specify a time */
/*                   that are most conveniently expressed by phrases */
/*                   such as ``the third Monday of every month'' or */
/*                   ``Beginning with the second Wednesday of the new */
/*                     year and every 4th Wednesday thereafter.'' */

/*                   The hours, minutes and seconds components of */
/*                   these time vectors are the */
/*                   same as for the Year-Month-Day and Year-Day UTC */
/*                   time vectors. */

/*                   The Y component refers to the calendar year, and */
/*                   in the YMWD vector, the M component refers to */
/*                   the calendar month. */

/*                   The W component refers to the week of the */
/*                   Year (YWD) or Month (YMWD).  The first week */
/*                   begins on the first day of the year or the first */
/*                   day of the month.  The D component is the day of the */
/*                   week with 1 corresponding to Sunday, 2 to Monday, */
/*                   and so on with 7 corresponding to Saturday. */

/*                   Thus the YMWD time vector */

/*                      1991 */
/*                        11 */
/*                         3 */
/*                         5 */
/*                        12 */
/*                         0 */
/*                         0 */

/*                   refers to 12:00:00 on the third Thursday of */
/*                   November of 1991. */

/*                   The YWD time vector */

/*                      1997 */
/*                        11 */
/*                         4 */
/*                        13 */
/*                         5 */
/*                        11 */

/*                   refers to 12:05:11 on the eleventh Wednesday */
/*                   of 1997. */

/*                Formal Calendar Time Vectors */
/*                ============================ */
/*                The types YMDF, YDF, YD.D(F), YWDF, YMWDF are similar */
/*                to the corresponding base types: YMD, YD, YD.D, YWD */
/*                and YMWD.  However, these types represent formal */
/*                time vectors.  Each day contains exactly 86400 seconds. */
/*                The difference between formal and non-formal systems */
/*                can only be seen during a positive leapsecond or */
/*                during the second following a negative leapsecond. */

/*                Epochs during a positive leapsecond on input are */
/*                placed in the first second of the next day.  Epochs */
/*                during a positive leapsecond on output are held */
/*                at 00:00:00 of the next day. */

/*                Epochs during the first second following a negative */
/*                leapsecond are counted as belonging to the previous */
/*                day if both the input and output types are formal */
/*                types. */


/*                Calendars */
/*                ===================== */
/*                In all time vectors for which a year is specified, */
/*                the year is assumed to belong to the Gregorian */
/*                Calendar---every 4th year is a leapyear except */
/*                for centuries (such as 1900) that are not divisible */
/*                by 400.  This calendar is formally extended */
/*                indefinitely backward and forward in time. */

/*                Note that the Gregorian Calendar did not */
/*                formally exist prior to October 15, 1582. Prior to */
/*                that time the Julian Calendar was used (in the */
/*                Julian Calendar every 4th year is a leapyear, including */
/*                all centuries). */

/*                If you have epochs relative to the Julian calendar, */
/*                the SPICE routine JUL2GR is available for converting */
/*                to the formal Gregorian Calendar. */


/*                Epochs Prior to 1972 */
/*                ===================== */
/*                UTC as it exists today, was adopted in 1972.  For */
/*                epochs prior to 1972, it is assumed that the difference */
/*                between TAI and UTC is a constant value. */

/*                Years prior to 1 A.D. */
/*                ===================== */
/*                A year belonging to the B.C. era,  may be */
/*                represented by subtracting the year from 1. */
/*                Thus to specify 27 B.C (Gregorian) set the */
/*                year component of the time vector to -26. */


/*                Notes: */
/*                ====== */
/*                The FORMAL and JDUTC types should not be used */
/*                for times near a leap second.  However, for times */
/*                removed from leap seconds they pose no problems. */

/*                The DAYSEC and DP2000 are useful for representing */
/*                times that are given in atomic seconds past some */
/*                reference epoch other than J2000. */

/* $ Detailed_Output */

/*     TVEC       is the time vector corresponding to the input */
/*                time vector but with components consistent with */
/*                the type specified by input variable TO. */

/* $ Parameters */

/*     MXCOMP     is the maximum number of components that can appear in */
/*                TVEC. */

/* $ Exceptions */

/*     1) If the type of either FROM or TO is not recognized the */
/*        error 'SPICE(UNKNONWNTIMESYSTEM)' is signalled. */

/*     2) If a leapseconds kernel has not been loaded prior a call */
/*        to TTRANS the error  'SPICE(NOLEAPSECONDS)' is signalled. */

/*     3) If epochs associated with leapseconds in the leapseconds */
/*        kernel are not in increasing order, the error */
/*        'SPICE(BADLEAPSECONDS)' is signalled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine is the fundamental translator between various */
/*     representations of time in the SPICE system.  However, it */
/*     is intended to be a mid-level routine that few user's should */
/*     have need of calling. */

/*     In addition to translating between time systems, this routine */
/*     can be used to normalize the components of a time string */
/*     so that they are in the normal range for a particular */
/*     representation.  This allows you to easily do arithmetic */
/*     with epochs. */

/* $ Examples */

/*     Suppose you need to convert a time expressed as seconds */
/*     past J2000 (TDB) to Pacific Daylight time.  The following */
/*     example shows how you might use TTRANS to accomplish this */
/*     task. */

/*      TVEC(1) = ET */

/*      CALL TTRANS ( 'TDB', 'YMD', TVEC ) */

/*      The seconds component of PDT is the same as the seconds */
/*      component of UTC.  We save and add the UTC-PDT offset */
/*      to the hours and minutes component of the time vector. */

/*      SECNDS  = TVEC(6) */
/*      TVEC(6) = 0.0D0 */

/*      TVEC(4) = TVEC(4) - 7.0D0 */
/*      TVEC(5) = TVEC(5) + 0.0D0 */

/*      CALL TTRANS ( 'YMDF', 'YMDF', TVEC ) */

/*      Now reset the seconds component to the original value */
/*      and pass the time vector to some formatting routine. */

/*      TVEC(6) = SECNDS */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     W.L. Taber     (JPL) */
/*     B.V. Semenov   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.5.0, 09-SEP-2013 (BVS) */

/*        Updated to keep track of the POOL counter and call ZZCVPOOL. */

/* -    SPICELIB Version 1.4.0, 05-MAR-2009 (NJB) */

/*        Bug fix: this routine now keeps track of whether its */
/*        kernel pool look-up succeeded. If not, a kernel pool */
/*        lookup is attempted on the next call to this routine. */

/* -    SPICELIB Version 1.3.0, 15-NOV-2006 (NJB) */

/*        A reference to RTPOOL was replaced by a reference */
/*        to GDPOOL. */

/* -    SPICELIB Version 1.2.0, 24-OCT-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in RMAIND and RMAINI calls.  Changed reference to LDPOOL to */
/*        reference to FURNSH in an error message. */

/* -    SPICELIB Version 1.1.0, 9-JUN-1999 (WLT) */

/*        The routine was modified so that uniform time system */
/*        transformations (see UNITIM) are handled without */
/*        performing intermediate computations.  This gives a slight */
/*        improvement in the accuracy of some computations. */

/*        In addition, two unused variables were removed. */

/* -    Spicelib Version 1.0.0, 17-SEP-1996 (WLT) */

/* -& */
/* $ Index_Entries */

/*     Convert from one time vector to another */
/*     Convert between various parsed time representations */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.2.0, 24-OCT-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in RMAIND and RMAINI calls.  Changed reference to LDPOOL to */
/*        reference to FURNSH in an error message. */

/* -& */

/*     SPICELIB functions */


/*     Local (in-line) functions */


/*     Local parameters */


/*     Parameters */

/*     We declare the variables that contain the number of days in */
/*     400 years, 100 years, 4 years and 1 year. */


/*     The following integers give the number of days during the */
/*     associated month of a non-leap year. */


/*     The integers that follow give the number of days in a normal */
/*     year that precede the first of the month. */


/*     The integers that follow give the number of days in a leap */
/*     year that precede the first of the month. */


/*     MAXLP is the maximum number of leap seconds that can be */
/*     stored internally.   The value of 140 should be sufficient */
/*     to store leap seconds through the year 2100. */


/*     MAXVAR is the number of kernel pool variables required by this */
/*     routine. */



/*     The following gives us an "enumeration" for all of the */
/*     various types of time vectors that are recognized. */

/*     DAYSEC */
/*     DAYP2 */
/*     ET */
/*     FRML */
/*     JDTDB */
/*     JDTDT */
/*     JDUTC */
/*     JED */
/*     TAI */
/*     TDB */
/*     TDT */
/*     YD */
/*     YDD */
/*     YDDF */
/*     YDF */
/*     YMD */
/*     YMDF */
/*     YMWD */
/*     YMWDF */
/*     YWD */
/*     YWDF */


/*     The following parameters just make the code seem a bit */
/*     more natural. */


/*     Local variables */


/*     The array EXTRA contains the number of many additional days that */
/*     appear before the first of a month during a leap year (as opposed */
/*     to a non-leap year). */


/*     DPJAN0(I) gives the number of days that occur before the I'th */
/*     month of a normal year. */


/*     Saved variables */


/*     Initial values */


/*     Definitions of statment functions. */

/*     The number of days elapsed since Jan 1, of year 1 A.D. to */
/*     Jan 1 of YEAR is given by: */


/*     Return 1 if YEAR is divisible by N, otherwise return 0. */


/*     The number of leap days in a year is given by: */


/*     To compute the day of the year we */

/*        look up the number of days to the beginning of the month, */

/*        add on the number leap days that occurred prior to that */
/*        time */

/*        add on the number of days into the month */


/*     The number of days since 1 Jan 1 A.D. is given by: */


/*     The number of seconds represented by HOURS hours MINS minutes */
/*     and SECS seconds. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "TTRANS", (ftnlen)6);
    }

/*     The first time any of the entry points are called we */
/*     must set up the "watcher" for the kernel pool variables */
/*     that will be needed by this routine. */

    if (__state->first) {
	__state->first = FALSE_;
	__state->secspd = spd_(__global_state);
	__state->halfd = spd_(__global_state) / 2.;
/* Computing MAX */
	i__3 = 0, i__4 = 1 + abs(__state->c__2000) / __state->c__4 * 
		__state->c__4 - abs(__state->c__2000);
/* Computing MAX */
	i__5 = 0, i__6 = 1 + abs(__state->c__2000) / __state->c__100 * 
		__state->c__100 - abs(__state->c__2000);
/* Computing MAX */
	i__7 = 0, i__8 = 1 + abs(__state->c__2000) / __state->c__400 * 
		__state->c__400 - abs(__state->c__2000);
	__state->dn2000 = 365 * (__state->c__2000 - 1) + (__state->c__2000 - 
		1) / 4 - (__state->c__2000 - 1) / 100 + (__state->c__2000 - 1)
		 / 400 + (__state->dpjan0[(i__1 = __state->c__1 - 1) < 12 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "dpjan0", 
		i__1, "ttrans_", (ftnlen)946)] + __state->extra[(i__2 = 
		__state->c__1 - 1) < 12 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "extra", i__2, "ttrans_", (ftnlen)946)] *
		 (max(i__3,i__4) - max(i__5,i__6) + max(i__7,i__8)) + 
		__state->c__1) - 1;
/* Computing MAX */
	i__3 = 0, i__4 = 1 + abs(__state->c__1991) / __state->c__4 * 
		__state->c__4 - abs(__state->c__1991);
/* Computing MAX */
	i__5 = 0, i__6 = 1 + abs(__state->c__1991) / __state->c__100 * 
		__state->c__100 - abs(__state->c__1991);
/* Computing MAX */
	i__7 = 0, i__8 = 1 + abs(__state->c__1991) / __state->c__400 * 
		__state->c__400 - abs(__state->c__1991);
	__state->sunday = 365 * (__state->c__1991 - 1) + (__state->c__1991 - 
		1) / 4 - (__state->c__1991 - 1) / 100 + (__state->c__1991 - 1)
		 / 400 + (__state->dpjan0[(i__1 = __state->c__1 - 1) < 12 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "dpjan0", 
		i__1, "ttrans_", (ftnlen)947)] + __state->extra[(i__2 = 
		__state->c__1 - 1) < 12 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "extra", i__2, "ttrans_", (ftnlen)947)] *
		 (max(i__3,i__4) - max(i__5,i__6) + max(i__7,i__8)) + 
		__state->c__6) - 1;
	__state->jd1101 = j2000_(__global_state) - (doublereal) 
		__state->dn2000 - .5;

/*        Initialize the list of Uniform time systems. */

	ssizec_(__global_state, &__state->c__21, __state->unifrm, (ftnlen)8);

/*        Set up the set of recognized time vectors. */

/*        The following 4 parallel arrays are here */
/*        to assist in the task of classifying the */
/*        FROM and TO time representations. The arrays */
/*        contain: */

/*        RECOG   the strings that are recognized as legitimate */
/*                time representations */

/*        PARSED  a unique integer that can be used to stand */
/*                for each recognized format.  This is used */
/*                in the various IF THEN blocks to decide */
/*                how a time vector should be processed instead */
/*                of the name because integer compares are */
/*                much faster than string comparisons. */

/*        FORML   is a logical that indicates whether or not the */
/*                corresponding time system is a formal system */
/*                or UTC based system.  FORML(I) = YES implies */
/*                the time system is formal.  FORML(I) means it */
/*                isn't. */

/*        NEEDY   is a logical that indicates whether or not */
/*                there is a YEAR in the time system.  It should */
/*                be read "NEED Y" for "need year"  not "needy" */
/*                as when you are destitute.  NEEDY(I) = YES means */
/*                the time system has a year.  NEEDY(I) = NO means */
/*                it doesn't */

	s_copy(&__global_state->f2c, __state->recog, "DAYSEC ", (ftnlen)8, (
		ftnlen)7);
	__state->parsed[0] = 1;
	__state->forml[0] = FALSE_;
	__state->needy[0] = FALSE_;
	s_copy(&__global_state->f2c, __state->recog + 8, "DP2000 ", (ftnlen)8,
		 (ftnlen)7);
	__state->parsed[1] = 2;
	__state->forml[1] = FALSE_;
	__state->needy[1] = FALSE_;
	s_copy(&__global_state->f2c, __state->recog + 16, "ET ", (ftnlen)8, (
		ftnlen)3);
	__state->parsed[2] = 3;
	__state->forml[2] = FALSE_;
	__state->needy[2] = FALSE_;
	insrtc_(__global_state, "ET", __state->unifrm, (ftnlen)2, (ftnlen)8);
	s_copy(&__global_state->f2c, __state->recog + 24, "FORMAL ", (ftnlen)
		8, (ftnlen)7);
	__state->parsed[3] = 4;
	__state->forml[3] = TRUE_;
	__state->needy[3] = FALSE_;
	s_copy(&__global_state->f2c, __state->recog + 32, "JDTDB ", (ftnlen)8,
		 (ftnlen)6);
	__state->parsed[4] = 5;
	__state->forml[4] = FALSE_;
	__state->needy[4] = FALSE_;
	insrtc_(__global_state, "JDTDB", __state->unifrm, (ftnlen)5, (ftnlen)
		8);
	s_copy(&__global_state->f2c, __state->recog + 40, "JDTDT ", (ftnlen)8,
		 (ftnlen)6);
	__state->parsed[5] = 6;
	__state->forml[5] = FALSE_;
	__state->needy[5] = FALSE_;
	insrtc_(__global_state, "JDTDT", __state->unifrm, (ftnlen)5, (ftnlen)
		8);
	s_copy(&__global_state->f2c, __state->recog + 48, "JDUTC ", (ftnlen)8,
		 (ftnlen)6);
	__state->parsed[6] = 7;
	__state->forml[6] = TRUE_;
	__state->needy[6] = FALSE_;
	s_copy(&__global_state->f2c, __state->recog + 56, "JED ", (ftnlen)8, (
		ftnlen)4);
	__state->parsed[7] = 8;
	__state->forml[7] = FALSE_;
	__state->needy[7] = FALSE_;
	insrtc_(__global_state, "JED", __state->unifrm, (ftnlen)3, (ftnlen)8);
	s_copy(&__global_state->f2c, __state->recog + 64, "TAI ", (ftnlen)8, (
		ftnlen)4);
	__state->parsed[8] = 9;
	__state->forml[8] = FALSE_;
	__state->needy[8] = FALSE_;
	insrtc_(__global_state, "TAI", __state->unifrm, (ftnlen)3, (ftnlen)8);
	s_copy(&__global_state->f2c, __state->recog + 72, "TDB ", (ftnlen)8, (
		ftnlen)4);
	__state->parsed[9] = 10;
	__state->forml[9] = FALSE_;
	__state->needy[9] = FALSE_;
	insrtc_(__global_state, "TDB", __state->unifrm, (ftnlen)3, (ftnlen)8);
	s_copy(&__global_state->f2c, __state->recog + 80, "TDT ", (ftnlen)8, (
		ftnlen)4);
	__state->parsed[10] = 11;
	__state->forml[10] = FALSE_;
	__state->needy[10] = FALSE_;
	insrtc_(__global_state, "TDT", __state->unifrm, (ftnlen)3, (ftnlen)8);
	s_copy(&__global_state->f2c, __state->recog + 88, "YD ", (ftnlen)8, (
		ftnlen)3);
	__state->parsed[11] = 12;
	__state->forml[11] = FALSE_;
	__state->needy[11] = TRUE_;
	s_copy(&__global_state->f2c, __state->recog + 96, "YD.D ", (ftnlen)8, 
		(ftnlen)5);
	__state->parsed[12] = 13;
	__state->forml[12] = FALSE_;
	__state->needy[12] = TRUE_;
	s_copy(&__global_state->f2c, __state->recog + 104, "YD.DF ", (ftnlen)
		8, (ftnlen)6);
	__state->parsed[13] = 14;
	__state->forml[13] = TRUE_;
	__state->needy[13] = TRUE_;
	s_copy(&__global_state->f2c, __state->recog + 112, "YDF ", (ftnlen)8, 
		(ftnlen)4);
	__state->parsed[14] = 15;
	__state->forml[14] = TRUE_;
	__state->needy[14] = TRUE_;
	s_copy(&__global_state->f2c, __state->recog + 120, "YMD ", (ftnlen)8, 
		(ftnlen)4);
	__state->parsed[15] = 16;
	__state->forml[15] = FALSE_;
	__state->needy[15] = TRUE_;
	s_copy(&__global_state->f2c, __state->recog + 128, "YMDF ", (ftnlen)8,
		 (ftnlen)5);
	__state->parsed[16] = 17;
	__state->forml[16] = TRUE_;
	__state->needy[16] = TRUE_;
	s_copy(&__global_state->f2c, __state->recog + 136, "YMWD ", (ftnlen)8,
		 (ftnlen)5);
	__state->parsed[17] = 18;
	__state->forml[17] = FALSE_;
	__state->needy[17] = TRUE_;
	s_copy(&__global_state->f2c, __state->recog + 144, "YMWDF ", (ftnlen)
		8, (ftnlen)6);
	__state->parsed[18] = 19;
	__state->forml[18] = TRUE_;
	__state->needy[18] = TRUE_;
	s_copy(&__global_state->f2c, __state->recog + 152, "YWD ", (ftnlen)8, 
		(ftnlen)4);
	__state->parsed[19] = 20;
	__state->forml[19] = FALSE_;
	__state->needy[19] = TRUE_;
	s_copy(&__global_state->f2c, __state->recog + 160, "YWDF ", (ftnlen)8,
		 (ftnlen)5);
	__state->parsed[20] = 21;
	__state->forml[20] = TRUE_;
	__state->needy[20] = TRUE_;
	orderc_(__global_state, __state->recog, &__state->c__21, 
		__state->ordvec, (ftnlen)8);
	reordc_(__global_state, __state->ordvec, &__state->c__21, 
		__state->recog, (ftnlen)8);
	reordi_(__global_state, __state->ordvec, &__state->c__21, 
		__state->parsed);
	reordl_(__global_state, __state->ordvec, &__state->c__21, 
		__state->forml);
	reordl_(__global_state, __state->ordvec, &__state->c__21, 
		__state->needy);

/*        Initialize the local POOL counter to user value. */

	zzctruin_(__global_state, __state->usrctr);

/*        Set up the kernel pool watchers */

	s_copy(&__global_state->f2c, __state->vars__, "DELTET/DELTA_AT", (
		ftnlen)32, (ftnlen)15);
	swpool_(__global_state, "TTRANS", &__state->c__1, __state->vars__, (
		ftnlen)6, (ftnlen)32);
    }

/*     Check to see if any of the kernel items required by this */
/*     routine have been updated since the last call to this */
/*     entry point. */

    zzcvpool_(__global_state, "TTRANS", __state->usrctr, &__state->update, (
	    ftnlen)6);
    if (__state->update || __state->nodata) {

/*        We load the TAI-UTC offsets and formal leapsecond epochs */
/*        into the TAITAB.  (We will modify this array in a minute). */

	gdpool_(__global_state, "DELTET/DELTA_AT", &__state->c__1, &
		__state->c__280, &__state->nref, __state->taitab, &
		__state->found, (ftnlen)15);

/*        Make sure all of the requested data was there. */

	if (! __state->found) {
	    __state->nodata = TRUE_;
	    setmsg_(__global_state, "The variable that points to the leapsec"
		    "onds (DELTET/DELTA_AT) could not be located in the kerne"
		    "l pool.  It is likely that the leapseconds kernel has no"
		    "t been loaded via the routine FURNSH.", (ftnlen)188);
	    sigerr_(__global_state, "SPICE(NOLEAPSECONDS)", (ftnlen)20);
	    chkout_(__global_state, "TTRANS", (ftnlen)6);
	    return 0;
	}

/*        Transform the TAITAB in place to give the TAI time tag */
/*        at the beginning of the UTC day in which a leap */
/*        second occurred and the TAI time tag at the beginning */
/*        of the next day.  Pictorially, the table is transformed */

/*               +----------------------+         +-------------------+ */
/*               | DELTA_1 (TAI to UTC) |         | TAI at start of   | */
/*               |                      |         | day before TAI-UTC| */
/*               |                      |         | change occurred   | */
/*               +----------------------+         +-------------------+ */
/*        from:  | First Formal time    |     to: | TAI time at start | */
/*               | associated with      |         | of next day UTC.  | */
/*               | DELTA_1              |         | after DELTA_1 jump| */
/*               +----------------------+         +-------------------+ */
/*               | DELTA_2 (TAI to UTC) |         | TAI at start of   | */
/*               |                      |         | day before TAI-UTC| */
/*               |                      |         | jump occurred     | */
/*               +----------------------+         +-------------------+ */
/*               | First Formal time    |         | TAI time at start | */
/*               | associated with      |         | of next day UTC.  | */
/*               | DELTA_2              |         | after DELTA_2 jump| */
/*               +----------------------+         +-------------------+ */
/*                        .                                . */
/*                        .                                . */
/*                        .                                . */


/*        At the same time, load the table DAYTAB. It contains the */
/*        the day number past 1 Jan 1 AD for the beginning of the */
/*        days loaded in TAITAB. */

	__state->lastdt = __state->taitab[0] - 1.;
	i__1 = __state->nref;
	for (__state->i__ = 1; __state->i__ <= i__1; __state->i__ += 2) {
	    __state->offset = __state->i__;
	    __state->refptr = __state->i__ + 1;
	    __state->dt = __state->taitab[(i__2 = __state->offset - 1) < 280 
		    && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "tait"
		    "ab", i__2, "ttrans_", (ftnlen)1199)];
	    __state->formal = __state->taitab[(i__2 = __state->refptr - 1) < 
		    280 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "taitab", i__2, "ttrans_", (ftnlen)1200)];
	    __state->taitab[(i__2 = __state->offset - 1) < 280 && 0 <= i__2 ? 
		    i__2 : s_rnge(&__global_state->f2c, "taitab", i__2, "ttr"
		    "ans_", (ftnlen)1201)] = __state->formal - __state->secspd 
		    + __state->lastdt;
	    __state->taitab[(i__2 = __state->refptr - 1) < 280 && 0 <= i__2 ? 
		    i__2 : s_rnge(&__global_state->f2c, "taitab", i__2, "ttr"
		    "ans_", (ftnlen)1202)] = __state->formal + __state->dt;
	    __state->daynum = (integer) ((__state->formal + __state->halfd) / 
		    __state->secspd) + __state->dn2000;
	    __state->daytab[(i__2 = __state->offset - 1) < 280 && 0 <= i__2 ? 
		    i__2 : s_rnge(&__global_state->f2c, "daytab", i__2, "ttr"
		    "ans_", (ftnlen)1207)] = __state->daynum - 1;
	    __state->daytab[(i__2 = __state->refptr - 1) < 280 && 0 <= i__2 ? 
		    i__2 : s_rnge(&__global_state->f2c, "daytab", i__2, "ttr"
		    "ans_", (ftnlen)1208)] = __state->daynum;
	    __state->lastdt = __state->dt;
	}

/*        Since we don't have to do it very often, make sure the */
/*        times in the TAI table are in increasing order. */

	i__1 = __state->nref;
	for (__state->i__ = 2; __state->i__ <= i__1; ++__state->i__) {
	    __state->nodata = TRUE_;
	    if (__state->taitab[(i__2 = __state->i__ - 2) < 280 && 0 <= i__2 ?
		     i__2 : s_rnge(&__global_state->f2c, "taitab", i__2, 
		    "ttrans_", (ftnlen)1222)] >= __state->taitab[(i__3 = 
		    __state->i__ - 1) < 280 && 0 <= i__3 ? i__3 : s_rnge(&
		    __global_state->f2c, "taitab", i__3, "ttrans_", (ftnlen)
		    1222)]) {
		setmsg_(__global_state, "Either the leapsecond epochs taken "
			"from the kernel pool are not properly ordered or the"
			" UTC - TAI offsets are completely out of range. ", (
			ftnlen)135);
		sigerr_(__global_state, "SPICE(BADLEAPSECONDS)", (ftnlen)21);
		chkout_(__global_state, "TTRANS", (ftnlen)6);
		return 0;
	    }
	}

/*        At this point, we've completed all checks on kernel data. */

	__state->nodata = FALSE_;
    }

/*     Make local normalized copies of FROM and TO. */

    nextwd_(__global_state, from, __state->myfrom, __state->rest, from_len, (
	    ftnlen)32, (ftnlen)32);
    nextwd_(__global_state, to, __state->myto, __state->rest, to_len, (ftnlen)
	    32, (ftnlen)32);
    ucase_(__global_state, __state->myfrom, __state->myfrom, (ftnlen)32, (
	    ftnlen)32);
    ucase_(__global_state, __state->myto, __state->myto, (ftnlen)32, (ftnlen)
	    32);

/*     Make sure that the FROM and TO are recognized time types. */

    __state->pto = bsrchc_(__global_state, __state->myto, &__state->c__21, 
	    __state->recog, (ftnlen)32, (ftnlen)8);
    __state->pfrom = bsrchc_(__global_state, __state->myfrom, &__state->c__21,
	     __state->recog, (ftnlen)32, (ftnlen)8);

/*     Eventually, we need to handle SCLKs.  When that happens */
/*     we will do it here and in a similarly marked spot at */
/*     the end of this routine.  First see if we know how to */
/*     handle the FROM system. */

/*     IF ( PFROM .EQ. 0 ) THEN */

/*        CALL ISSCLK ( FROM,ERROR, FOUND ) */

/*        IF ( .NOT. FOUND ) THEN */
/*           IF ( ERROR .NE. ' ' ) THEN */
/*              CALL SETMSG ( ERROR ) */
/*              CALL SIGERR ( 'SPICE(TIMESYSTEMPROBLEM)' ) */
/*              CALL CHKOUT ( 'TTRANS' ) */
/*              RETURN */
/*           END IF */
/*        ELSE */
/*           CALL SCLKTV ( FROM, TVEC ) */
/*           PFROM = TDB */
/*        END IF */

/*     END IF */

/*     Now check to see if we know how to handle the  TO system. */

/*     IF ( PTO .EQ. 0 ) THEN */

/*        CALL ISSCLK ( TO, ERROR, FOUND ) */

/*        IF ( .NOT. FOUND ) THEN */

/*           IF ( ERROR .NE. ' ' ) THEN */
/*              CALL SETMSG ( ERROR ) */
/*              CALL SIGERR ( 'SPICE(TIMESYSTEMPROBLEM)' ) */
/*              CALL CHKOUT ( 'TTRANS' ) */
/*           END IF */

/*        ELSE */

/*           MKSCLK = .TRUE. */
/*           PTO    =  TDB */

/*        END IF */

/*     END IF */


/*     For now we are NOT going to deal with SCLK so if something */
/*     isn't recognized, we can just signal an error and quit. */

    if (__state->pfrom == 0) {
	setmsg_(__global_state, "The FROM time representation '#' is not rec"
		"ognized. ", (ftnlen)52);
	errch_(__global_state, "#", from, (ftnlen)1, from_len);
	sigerr_(__global_state, "SPICE(UNKNONWNTIMESYSTEM)", (ftnlen)25);
	chkout_(__global_state, "TTRANS", (ftnlen)6);
	return 0;
    } else if (__state->pto == 0) {
	setmsg_(__global_state, "The TO time representation '#' is not recog"
		"nized. ", (ftnlen)50);
	errch_(__global_state, "#", from, (ftnlen)1, from_len);
	sigerr_(__global_state, "SPICE(UNKNONWNTIMESYSTEM)", (ftnlen)25);
	chkout_(__global_state, "TTRANS", (ftnlen)6);
	return 0;
    }

/*     OK.  We have made our last attempt at diagnosing a user error. */
/*     From this point on we assume that the user input exactly what */
/*     was intended. */

/*     We convert the time vector to days past 1 jan 01 and seconds */
/*     past the beginning of the day.  None of the cases below */
/*     are particularly tricky.  There's just a lot of cases. */

    if (__state->pfrom == 16 || __state->pfrom == 17) {
	__state->year = (integer) tvec[0];
	__state->month = (integer) tvec[1];
	__state->day = (integer) tvec[2];
	i__1 = __state->month - 1;
	rmaini_(__global_state, &i__1, &__state->c__12, &__state->dyear, &
		__state->month);
	__state->year += __state->dyear;
	++__state->month;
	__state->doffst = 0;
	if (__state->year <= 0) {
	    rmaini_(__global_state, &__state->year, &__state->c__400, &
		    __state->yr400, &__state->tempi);
	    __state->year = __state->tempi;
	    if (__state->year == 0) {
		__state->year += 400;
		--__state->yr400;
	    }
	    __state->doffst = __state->yr400 * 146097;
	}
/* Computing MAX */
	i__3 = 0, i__4 = 1 + abs(__state->year) / __state->c__4 * 
		__state->c__4 - abs(__state->year);
/* Computing MAX */
	i__5 = 0, i__6 = 1 + abs(__state->year) / __state->c__100 * 
		__state->c__100 - abs(__state->year);
/* Computing MAX */
	i__7 = 0, i__8 = 1 + abs(__state->year) / __state->c__400 * 
		__state->c__400 - abs(__state->year);
	__state->daynum = 365 * (__state->year - 1) + (__state->year - 1) / 4 
		- (__state->year - 1) / 100 + (__state->year - 1) / 400 + (
		__state->dpjan0[(i__1 = __state->month - 1) < 12 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "dpjan0", i__1, "ttran"
		"s_", (ftnlen)1361)] + __state->extra[(i__2 = __state->month - 
		1) < 12 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		"extra", i__2, "ttrans_", (ftnlen)1361)] * (max(i__3,i__4) - 
		max(i__5,i__6) + max(i__7,i__8)) + __state->day) - 1 + 
		__state->doffst;
	d__1 = d_int(&__global_state->f2c, &tvec[3]);
	d__2 = d_int(&__global_state->f2c, &tvec[4]);
	__state->secs = d__1 * 3600. + d__2 * 60. + tvec[5];
    } else if (__state->pfrom == 12 || __state->pfrom == 15) {
	__state->year = (integer) tvec[0];
	__state->day = (integer) tvec[1];
	__state->month = 1;
	__state->doffst = 0;
	if (__state->year <= 0) {
	    rmaini_(__global_state, &__state->year, &__state->c__400, &
		    __state->yr400, &__state->tempi);
	    __state->year = __state->tempi;
	    if (__state->year == 0) {
		__state->year += 400;
		--__state->yr400;
	    }
	    __state->doffst = __state->yr400 * 146097;
	}
/* Computing MAX */
	i__3 = 0, i__4 = 1 + abs(__state->year) / __state->c__4 * 
		__state->c__4 - abs(__state->year);
/* Computing MAX */
	i__5 = 0, i__6 = 1 + abs(__state->year) / __state->c__100 * 
		__state->c__100 - abs(__state->year);
/* Computing MAX */
	i__7 = 0, i__8 = 1 + abs(__state->year) / __state->c__400 * 
		__state->c__400 - abs(__state->year);
	__state->daynum = 365 * (__state->year - 1) + (__state->year - 1) / 4 
		- (__state->year - 1) / 100 + (__state->year - 1) / 400 + (
		__state->dpjan0[(i__1 = __state->month - 1) < 12 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "dpjan0", i__1, "ttran"
		"s_", (ftnlen)1388)] + __state->extra[(i__2 = __state->month - 
		1) < 12 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		"extra", i__2, "ttrans_", (ftnlen)1388)] * (max(i__3,i__4) - 
		max(i__5,i__6) + max(i__7,i__8)) + __state->day) - 1 + 
		__state->doffst;
	d__1 = d_int(&__global_state->f2c, &tvec[2]);
	d__2 = d_int(&__global_state->f2c, &tvec[3]);
	__state->secs = d__1 * 3600. + d__2 * 60. + tvec[4];
    } else if (__state->pfrom == 13 || __state->pfrom == 14) {
	__state->year = (integer) tvec[0];
	__state->day = (integer) tvec[1];
	__state->month = 1;
	__state->doffst = 0;
	if (__state->year <= 0) {
	    rmaini_(__global_state, &__state->year, &__state->c__400, &
		    __state->yr400, &__state->tempi);
	    __state->year = __state->tempi;
	    if (__state->year == 0) {
		__state->year += 400;
		--__state->yr400;
	    }
	    __state->doffst = __state->yr400 * 146097;
	}
	__state->frac = tvec[1] - (doublereal) __state->day;
/* Computing MAX */
	i__3 = 0, i__4 = 1 + abs(__state->year) / __state->c__4 * 
		__state->c__4 - abs(__state->year);
/* Computing MAX */
	i__5 = 0, i__6 = 1 + abs(__state->year) / __state->c__100 * 
		__state->c__100 - abs(__state->year);
/* Computing MAX */
	i__7 = 0, i__8 = 1 + abs(__state->year) / __state->c__400 * 
		__state->c__400 - abs(__state->year);
	__state->daynum = 365 * (__state->year - 1) + (__state->year - 1) / 4 
		- (__state->year - 1) / 100 + (__state->year - 1) / 400 + (
		__state->dpjan0[(i__1 = __state->month - 1) < 12 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "dpjan0", i__1, "ttran"
		"s_", (ftnlen)1416)] + __state->extra[(i__2 = __state->month - 
		1) < 12 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		"extra", i__2, "ttrans_", (ftnlen)1416)] * (max(i__3,i__4) - 
		max(i__5,i__6) + max(i__7,i__8)) + __state->day) - 1 + 
		__state->doffst;

/*        Normally the length of a day is 86400 seconds, but this day */
/*        might be a leapsecond day.  We will set DAYLEN to SECSPD and */
/*        change it if it turns out this is a day with a leapsecond. */

	if (__state->pfrom == 14) {
	    __state->secs = __state->frac * __state->secspd;
	} else {
	    __state->daylen = __state->secspd;
	    __state->dayptr = lstlei_(__global_state, &__state->daynum, &
		    __state->nref, __state->daytab);
	    if (odd_(__global_state, &__state->dayptr)) {
		__state->daylen = __state->taitab[(i__1 = __state->dayptr) < 
			280 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c,
			 "taitab", i__1, "ttrans_", (ftnlen)1431)] - 
			__state->taitab[(i__2 = __state->dayptr - 1) < 280 && 
			0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "tai"
			"tab", i__2, "ttrans_", (ftnlen)1431)];
	    }
	    __state->secs = __state->frac * __state->daylen;
	}
    } else if (__state->pfrom == 4) {

/*        First lets get the number of days since 1-Jan-2000 00:00:00 */

	d__1 = tvec[0] + __state->halfd;
	rmaind_(__global_state, &d__1, &__state->secspd, &__state->dp2000, &
		__state->secs);
	__state->daynum = (integer) __state->dp2000 + __state->dn2000;
    } else if (__state->pfrom == 7) {

/*        JD1101 is the julian date UTC of Jan 1, 1 AD. */

	__state->jdsecs = (tvec[0] - __state->jd1101) * __state->secspd;
	rmaind_(__global_state, &__state->jdsecs, &__state->secspd, &
		__state->daydp, &__state->secs);
	__state->daynum = (integer) __state->daydp;
    } else if (__state->pfrom == 1) {
	__state->daynum = (integer) tvec[0];
	__state->secs = tvec[1];
    } else if (__state->pfrom == 2) {
	__state->daynum = (integer) tvec[0] + __state->dn2000;
	__state->secs = tvec[1];
    } else if (__state->pfrom == 20 || __state->pfrom == 21) {
	__state->year = (integer) tvec[0];
	__state->week = (integer) tvec[1] - 1;
	__state->wkday = (integer) tvec[2];
	__state->month = 1;

/*        Compute the days past 1 jan 1 of the beginning of this */
/*        year and month. */

	__state->doffst = 0;
	if (__state->year <= 0) {
	    rmaini_(__global_state, &__state->year, &__state->c__400, &
		    __state->yr400, &__state->tempi);
	    __state->year = __state->tempi;
	    if (__state->year == 0) {
		__state->year += 400;
		--__state->yr400;
	    }
	    __state->doffst = __state->yr400 * 146097;
	}
/* Computing MAX */
	i__3 = 0, i__4 = 1 + abs(__state->year) / __state->c__4 * 
		__state->c__4 - abs(__state->year);
/* Computing MAX */
	i__5 = 0, i__6 = 1 + abs(__state->year) / __state->c__100 * 
		__state->c__100 - abs(__state->year);
/* Computing MAX */
	i__7 = 0, i__8 = 1 + abs(__state->year) / __state->c__400 * 
		__state->c__400 - abs(__state->year);
	__state->daynum = 365 * (__state->year - 1) + (__state->year - 1) / 4 
		- (__state->year - 1) / 100 + (__state->year - 1) / 400 + (
		__state->dpjan0[(i__1 = __state->month - 1) < 12 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "dpjan0", i__1, "ttran"
		"s_", (ftnlen)1504)] + __state->extra[(i__2 = __state->month - 
		1) < 12 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		"extra", i__2, "ttrans_", (ftnlen)1504)] * (max(i__3,i__4) - 
		max(i__5,i__6) + max(i__7,i__8)) + __state->c__1) - 1 + 
		__state->doffst;
	i__1 = __state->daynum - __state->sunday;
	rmaini_(__global_state, &i__1, &__state->c__7, &__state->qint, &
		__state->dpsun);
	__state->fyrday = __state->dpsun + 1;
	i__1 = __state->wkday - __state->fyrday;
	rmaini_(__global_state, &i__1, &__state->c__7, &__state->qint, &
		__state->offset);
	__state->daynum = __state->daynum + __state->week * 7 + 
		__state->offset;
	d__1 = d_int(&__global_state->f2c, &tvec[3]);
	d__2 = d_int(&__global_state->f2c, &tvec[4]);
	__state->secs = d__1 * 3600. + d__2 * 60. + tvec[5];
    } else if (__state->pfrom == 18 || __state->pfrom == 19) {
	__state->year = (integer) tvec[0];
	__state->month = (integer) tvec[1];
	__state->week = (integer) tvec[2] - 1;
	__state->day = (integer) tvec[3];
	__state->doffst = 0;
	if (__state->year <= 0) {
	    rmaini_(__global_state, &__state->year, &__state->c__400, &
		    __state->yr400, &__state->tempi);
	    __state->year = __state->tempi;
	    if (__state->year == 0) {
		__state->year += 400;
		--__state->yr400;
	    }
	    __state->doffst = __state->yr400 * 146097;
	}
/* Computing MAX */
	i__3 = 0, i__4 = 1 + abs(__state->year) / __state->c__4 * 
		__state->c__4 - abs(__state->year);
/* Computing MAX */
	i__5 = 0, i__6 = 1 + abs(__state->year) / __state->c__100 * 
		__state->c__100 - abs(__state->year);
/* Computing MAX */
	i__7 = 0, i__8 = 1 + abs(__state->year) / __state->c__400 * 
		__state->c__400 - abs(__state->year);
	__state->daynum = 365 * (__state->year - 1) + (__state->year - 1) / 4 
		- (__state->year - 1) / 100 + (__state->year - 1) / 400 + (
		__state->dpjan0[(i__1 = __state->month - 1) < 12 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "dpjan0", i__1, "ttran"
		"s_", (ftnlen)1541)] + __state->extra[(i__2 = __state->month - 
		1) < 12 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		"extra", i__2, "ttrans_", (ftnlen)1541)] * (max(i__3,i__4) - 
		max(i__5,i__6) + max(i__7,i__8)) + __state->c__1) - 1 + 
		__state->doffst;
	i__1 = __state->daynum - __state->sunday;
	rmaini_(__global_state, &i__1, &__state->c__7, &__state->qint, &
		__state->dpsun);
	__state->fmday = __state->dpsun + 1;
	i__1 = __state->day - __state->fmday;
	rmaini_(__global_state, &i__1, &__state->c__7, &__state->qint, &
		__state->offset);
	__state->daynum = __state->daynum + __state->week * 7 + 
		__state->offset;
	__state->secs = tvec[4] * 3600. + tvec[5] * 60. + tvec[6];

/*     If we get to this point the type must be one of the continuous */
/*     time types: 'TAI', 'TDT', 'TDB', 'JED', 'ET', 'JDTDT', 'JDTDB'. */

    } else {

/*        If the output time is one of the continuous time systems */
/*        we can take a short cut and just perform the computation */
/*        directly. */

	if (elemc_(__global_state, __state->myto, __state->unifrm, (ftnlen)32,
		 (ftnlen)8)) {
	    tvec[0] = unitim_(__global_state, tvec, __state->myfrom, 
		    __state->myto, (ftnlen)32, (ftnlen)32);
	    chkout_(__global_state, "TTRANS", (ftnlen)6);
	    return 0;
	}

/*        The output time system isn't one of the uniform time systems. */
/*        Convert what we have to TAI and then to the DAYNUM, SECOND */
/*        representation. */

	__state->tai = unitim_(__global_state, tvec, __state->myfrom, "TAI", (
		ftnlen)32, (ftnlen)3);
	__state->taiptr = lstled_(__global_state, &__state->tai, &
		__state->nref, __state->taitab);

/*        If the TAIPTR value is odd, then the TAI time falls during */
/*        a day with a leap second.  We can just look up the day */
/*        number and compute the number of seconds into that */
/*        day directly ... */

	if (odd_(__global_state, &__state->taiptr)) {
	    __state->daynum = __state->daytab[(i__1 = __state->taiptr - 1) < 
		    280 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "daytab", i__1, "ttrans_", (ftnlen)1589)];
	    __state->secs = __state->tai - __state->taitab[(i__1 = 
		    __state->taiptr - 1) < 280 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "taitab", i__1, "ttrans_", (ftnlen)
		    1590)];

/*        ...Otherwise, all days since the reference TAI time have */
/*        the same number of seconds (SECSPD).  (This statement applies */
/*        to days that precede the first reference TAI time too.) */
/*        Thus we can simply compute the number of days and seconds */
/*        that have elapsed since the reference TAI time. */

	} else {

/*           If TAI is before the first time in the table, we can */
/*           compute the number of days and seconds before the first */
/*           entry in the TAI table. */

	    __state->taiptr = max(__state->taiptr,1);
	    d__1 = __state->tai - __state->taitab[(i__1 = __state->taiptr - 1)
		     < 280 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "taitab", i__1, "ttrans_", (ftnlen)1609)];
	    rmaind_(__global_state, &d__1, &__state->secspd, &__state->daydp, 
		    &__state->secs);
	    __state->daynum = (integer) __state->daydp + __state->daytab[(
		    i__1 = __state->taiptr - 1) < 280 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "daytab", i__1, "ttrans_", (
		    ftnlen)1612)];
	}
    }
    if (__state->forml[(i__1 = __state->pfrom - 1) < 21 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "forml", i__1, "ttrans_", (ftnlen)
	    1619)]) {
	rmaind_(__global_state, &__state->secs, &__state->secspd, &
		__state->daydp, &__state->tsecs);
	__state->daynum += (integer) __state->daydp;
	__state->secs = __state->tsecs;
    }
/*     ================================================================== */

/*     Force the seconds into the range 0 to 86401 or 86400 */
/*     depending upon whether or not the output system is a formal */
/*     time system or not. */

    if (__state->forml[(i__1 = __state->pto - 1) < 21 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "forml", i__1, "ttrans_", (ftnlen)
	    1634)] && __state->forml[(i__2 = __state->pfrom - 1) < 21 && 0 <= 
	    i__2 ? i__2 : s_rnge(&__global_state->f2c, "forml", i__2, "ttran"
	    "s_", (ftnlen)1634)]) {

/*        We don't have to do anything here. */

    } else {
	if (__state->secs > __state->secspd - 1. || __state->secs < 0.) {

/*           First convert to TAI... */

/* Computing MAX */
	    i__1 = 1, i__2 = lstlei_(__global_state, &__state->daynum, &
		    __state->nref, __state->daytab);
	    __state->dayptr = max(i__1,i__2);
	    __state->secs += (doublereal) (__state->daynum - __state->daytab[(
		    i__1 = __state->dayptr - 1) < 280 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "daytab", i__1, "ttrans_", (
		    ftnlen)1647)]) * __state->secspd;
	    __state->tai = __state->taitab[(i__1 = __state->dayptr - 1) < 280 
		    && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "tait"
		    "ab", i__1, "ttrans_", (ftnlen)1649)] + __state->secs;

/*           ...then back to DAYNUM and SECS */

	    __state->taiptr = lstled_(__global_state, &__state->tai, &
		    __state->nref, __state->taitab);
	    if (odd_(__global_state, &__state->taiptr)) {
		__state->daynum = __state->daytab[(i__1 = __state->taiptr - 1)
			 < 280 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "daytab", i__1, "ttrans_", (
			ftnlen)1658)];
		__state->secs = __state->tai - __state->taitab[(i__1 = 
			__state->taiptr - 1) < 280 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "taitab", i__1, "ttrans_"
			, (ftnlen)1659)];
	    } else {
		__state->taiptr = max(1,__state->taiptr);
		__state->daynum = __state->daytab[(i__1 = __state->taiptr - 1)
			 < 280 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "daytab", i__1, "ttrans_", (
			ftnlen)1665)];
		d__1 = __state->tai - __state->taitab[(i__1 = __state->taiptr 
			- 1) < 280 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "taitab", i__1, "ttrans_", (
			ftnlen)1667)];
		rmaind_(__global_state, &d__1, &__state->secspd, &
			__state->daydp, &__state->secs);
		__state->daynum += (integer) __state->daydp;
	    }
	}
    }

/*     One last thing.  If we are going to a formal time vector, */
/*     we want to ignore positive leapseconds. (Negative ones */
/*     were handled above, the clock jumped ahead one second */
/*     when the second hand got to 59.) */

/*     The idea is that we want the clock */
/*     to stand still during the leapsecond.  Yeah this is bogus, */
/*     but people with analog clocks don't have any other choice. */

/*     We are in a positive leapsecond only if SECS is greater than */
/*     the number of seconds in a normal day.  In that case we */
/*     increment the day number by one and set SECS to zero. */

    if (__state->forml[(i__1 = __state->pto - 1) < 21 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "forml", i__1, "ttrans_", (ftnlen)
	    1690)] && __state->secs > __state->secspd) {
	++__state->daynum;
	__state->secs = 0.;
    }

/*     OK. Now we have DAYNUM and SECS,  convert this form to the */
/*     one requested. */

/*     If there is a 'Y' in the form we are to convert to, then we */
/*     will need some form of year, etc.  Do the work now and sort it */
/*     it all out at the appropriate time later on. */

    if (__state->needy[(i__1 = __state->pto - 1) < 21 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "needy", i__1, "ttrans_", (ftnlen)
	    1702)]) {
	__state->yr400 = __state->daynum / 146097;
	__state->rem = __state->daynum - __state->yr400 * 146097;

/*        We want to be able to deal with years prior to  1 Jan 1 */
/*        So we make sure the remainder is positive. */

	if (__state->rem < 0) {
	    --__state->yr400;
	    __state->rem += 146097;
	}
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
/* Computing MAX */
	i__1 = 0, i__2 = 1 + abs(__state->year) / __state->c__4 * 
		__state->c__4 - abs(__state->year);
/* Computing MAX */
	i__3 = 0, i__4 = 1 + abs(__state->year) / __state->c__100 * 
		__state->c__100 - abs(__state->year);
/* Computing MAX */
	i__5 = 0, i__6 = 1 + abs(__state->year) / __state->c__400 * 
		__state->c__400 - abs(__state->year);
	if (max(i__1,i__2) - max(i__3,i__4) + max(i__5,i__6) == 0) {
	    __state->month = lstlti_(__global_state, &__state->dofyr, &
		    __state->c__12, __state->dpjan0);
	    __state->day = __state->dofyr - __state->dpjan0[(i__1 = 
		    __state->month - 1) < 12 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "dpjan0", i__1, "ttrans_", (ftnlen)
		    1730)];
	} else {
	    __state->month = lstlti_(__global_state, &__state->dofyr, &
		    __state->c__12, __state->dpbegl);
	    __state->day = __state->dofyr - __state->dpbegl[(i__1 = 
		    __state->month - 1) < 12 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "dpbegl", i__1, "ttrans_", (ftnlen)
		    1733)];
	}

/*        We only want to convert that portion of seconds less than */
/*        86399 to hours, minutes and seconds.  Take anything extra */
/*        and put it in EXSECS. */

/* Computing MAX */
	d__1 = 0., d__2 = __state->secs - __state->secspd + 1;
	__state->exsecs = max(d__1,d__2);
	__state->tsecs = __state->secs - __state->exsecs;
	rmaind_(__global_state, &__state->tsecs, &__state->c_b188, &
		__state->hours, &__state->tempd);
	rmaind_(__global_state, &__state->tempd, &__state->c_b189, &
		__state->mins, &__state->tsecs);
	__state->tsecs += __state->exsecs;
    }
/* ===================================================================== */

/*     Finally, we convert to the requested output. */

    if (__state->pto == 16 || __state->pto == 17) {
	tvec[0] = (doublereal) __state->year;
	tvec[1] = (doublereal) __state->month;
	tvec[2] = (doublereal) __state->day;
	tvec[3] = __state->hours;
	tvec[4] = __state->mins;
	tvec[5] = __state->tsecs;
    } else if (__state->pto == 12 || __state->pto == 15) {
	tvec[0] = (doublereal) __state->year;
	tvec[1] = (doublereal) __state->dofyr;
	tvec[2] = __state->hours;
	tvec[3] = __state->mins;
	tvec[4] = __state->tsecs;
    } else if (__state->pto == 13 || __state->pto == 14) {
	tvec[0] = (doublereal) __state->year;
	if (__state->pto == 13) {
	    __state->dayptr = lstlei_(__global_state, &__state->daynum, &
		    __state->nref, __state->daytab);
	    __state->daylen = __state->secspd;
	    if (odd_(__global_state, &__state->dayptr)) {
		__state->daylen = __state->taitab[(i__1 = __state->dayptr) < 
			280 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c,
			 "taitab", i__1, "ttrans_", (ftnlen)1782)] - 
			__state->taitab[(i__2 = __state->dayptr - 1) < 280 && 
			0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "tai"
			"tab", i__2, "ttrans_", (ftnlen)1782)];
	    }
	    tvec[1] = (doublereal) __state->dofyr + __state->secs / 
		    __state->daylen;
	} else {
	    tvec[1] = (doublereal) __state->dofyr + __state->secs / 
		    __state->secspd;
	}
    } else if (__state->pto == 4) {
	tvec[0] = (doublereal) (__state->daynum - __state->dn2000) * 
		__state->secspd - __state->halfd + __state->secs;
    } else if (__state->pto == 7) {
	tvec[0] = __state->jd1101 + (doublereal) __state->daynum + 
		__state->secs / __state->secspd;
    } else if (__state->pto == 1) {
	tvec[0] = (doublereal) __state->daynum;
	tvec[1] = __state->secs;
    } else if (__state->pto == 2) {
	tvec[0] = (doublereal) (__state->daynum - __state->dn2000);
	tvec[1] = __state->secs;
    } else if (__state->pto == 20 || __state->pto == 21) {

/*        First compute the day of the week, and the week number */

	i__1 = __state->daynum - __state->sunday;
	rmaini_(__global_state, &i__1, &__state->c__7, &__state->qint, &
		__state->day);
	__state->week = (__state->dofyr - 1) / 7 + 1;

/*        Now just put everything where it belongs. */

	tvec[0] = (doublereal) __state->year;
	tvec[1] = (doublereal) __state->week;
	tvec[2] = (doublereal) __state->day + 1.;
	tvec[3] = __state->hours;
	tvec[4] = __state->mins;
	tvec[5] = __state->tsecs;
    } else if (__state->pto == 18 || __state->pto == 19) {

/*        First compute how many weeks into the month DAYNUM is, */
/*        and compute the day of week number. */

	tvec[0] = (doublereal) __state->year;
	__state->doffst = 0;
	if (__state->year <= 0) {
	    rmaini_(__global_state, &__state->year, &__state->c__400, &
		    __state->yr400, &__state->tempi);
	    __state->year = __state->tempi;
	    if (__state->year == 0) {
		__state->year += 400;
		--__state->yr400;
	    }
	    __state->doffst = __state->yr400 * 146097;
	}
/* Computing MAX */
	i__3 = 0, i__4 = 1 + abs(__state->year) / __state->c__4 * 
		__state->c__4 - abs(__state->year);
/* Computing MAX */
	i__5 = 0, i__6 = 1 + abs(__state->year) / __state->c__100 * 
		__state->c__100 - abs(__state->year);
/* Computing MAX */
	i__7 = 0, i__8 = 1 + abs(__state->year) / __state->c__400 * 
		__state->c__400 - abs(__state->year);
	__state->week = (__state->daynum - (365 * (__state->year - 1) + (
		__state->year - 1) / 4 - (__state->year - 1) / 100 + (
		__state->year - 1) / 400 + (__state->dpjan0[(i__1 = 
		__state->month - 1) < 12 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "dpjan0", i__1, "ttrans_", (ftnlen)1851)]
		 + __state->extra[(i__2 = __state->month - 1) < 12 && 0 <= 
		i__2 ? i__2 : s_rnge(&__global_state->f2c, "extra", i__2, 
		"ttrans_", (ftnlen)1851)] * (max(i__3,i__4) - max(i__5,i__6) 
		+ max(i__7,i__8)) + __state->c__1) - 1) - __state->doffst) / 
		7 + 1;
	i__1 = __state->daynum - __state->sunday;
	rmaini_(__global_state, &i__1, &__state->c__7, &__state->qint, &
		__state->day);

/*        Now just move the remaining stuff into TVEC. */

	tvec[1] = (doublereal) __state->month;
	tvec[2] = (doublereal) __state->week;
	tvec[3] = (doublereal) __state->day + 1.;
	tvec[4] = __state->hours;
	tvec[5] = __state->mins;
	tvec[6] = __state->tsecs;

/*     If we get to this point the type must be one of the continuous */
/*     time types: 'TAI', 'TDT', 'TDB', 'JED', 'ET', 'JDTDT', 'JDTDB'. */

/*     First convert to TAI and then to the appropriate output type. */

    } else {
/* Computing MAX */
	i__1 = 1, i__2 = lstlei_(__global_state, &__state->daynum, &
		__state->nref, __state->daytab);
	__state->dayptr = max(i__1,i__2);
	__state->secs += (doublereal) (__state->daynum - __state->daytab[(
		i__1 = __state->dayptr - 1) < 280 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "daytab", i__1, "ttrans_", (
		ftnlen)1873)]) * __state->secspd;
	__state->tai = __state->taitab[(i__1 = __state->dayptr - 1) < 280 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "taitab", 
		i__1, "ttrans_", (ftnlen)1875)] + __state->secs;
	tvec[0] = unitim_(__global_state, &__state->tai, "TAI", __state->myto,
		 (ftnlen)3, (ftnlen)32);
    }

/*     Here's where we will handle conversion to SCLK when */
/*     we get around to implementing that portion of TTRANS */


/*     IF ( MKSCLK ) THEN */
/*        CALL TVSCLK ( TO, TVEC ) */
/*     END IF */

/*     END IF */

    chkout_(__global_state, "TTRANS", (ftnlen)6);
    return 0;
} /* ttrans_ */

