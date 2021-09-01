/* timout.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern timout_init_t __timout_init;
static timout_state_t* get_timout_state(cspice_t* state) {
	if (!state->timout)
		state->timout = __cspice_allocate_module(sizeof(
	timout_state_t), &__timout_init, sizeof(__timout_init));
	return state->timout;

}

/* $Procedure      TIMOUT ( Time Output ) */
/* Subroutine */ int timout_(cspice_t* __global_state, doublereal *et, char *
	pictur, char *output, ftnlen pictur_len, ftnlen output_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5;
    doublereal d__1, d__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer), s_cmp(
	    f2c_state_t*, char *, char *, ftnlen, ftnlen);
    double d_int(f2c_state_t*, doublereal *);
    integer i_dnnt(f2c_state_t*, doublereal *);

    /* Local variables */
    extern /* Subroutine */ int scan_(cspice_t*, char *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, ftnlen, ftnlen);
    extern /* Subroutine */ int lcase_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int ucase_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int dpfmt_(cspice_t*, doublereal *, char *, char *
	    , ftnlen, ftnlen);
    extern integer rtrim_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int ljust_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int gr2jul_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    extern /* Subroutine */ int jul2gr_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    extern integer bsrchc_(cspice_t*, char *, integer *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int timdef_(cspice_t*, char *, char *, char *, 
	    ftnlen, ftnlen, ftnlen);
    extern doublereal brcktd_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    extern /* Subroutine */ int rmaind_(cspice_t*, doublereal *, doublereal *,
	     doublereal *, doublereal *);
    extern integer brckti_(cspice_t*, integer *, integer *, integer *);
    extern integer isrchi_(cspice_t*, integer *, integer *, integer *);
    extern doublereal unitim_(cspice_t*, doublereal *, char *, char *, ftnlen,
	     ftnlen);
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int scanpr_(cspice_t*, integer *, char *, integer 
	    *, integer *, ftnlen);
    extern /* Subroutine */ int prefix_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    extern /* Subroutine */ int scanrj_(cspice_t*, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
    extern /* Subroutine */ int ttrans_(cspice_t*, char *, char *, doublereal 
	    *, ftnlen, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern doublereal j2000_(cspice_t*);
    extern doublereal j1950_(cspice_t*);
    extern doublereal spd_(cspice_t*);
    extern /* Subroutine */ int zzutcpm_(cspice_t*, char *, integer *, 
	    doublereal *, doublereal *, integer *, logical *, ftnlen);


    /* Module state */
    timout_state_t* __state = get_timout_state(__global_state);
/* $ Abstract */

/*     This routine converts an input epoch represented in TDB seconds */
/*     past the TDB epoch of J2000 to a character string formatted to */
/*     the specifications of a user's format picture. */

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

/*     TIME */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   An epoch in seconds past the ephemeris epoch J2000 */
/*     PICTUR     I   A format specification for the output string. */
/*     STRING     O   A string representation of the input epoch. */

/* $ Detailed_Input */

/*     ET         a double precision representation of time in seconds */
/*                past the ephemeris epoch J2000. */

/*     PICTUR     is a string that specifies how the output should be */
/*                presented.  The string is made up of various markers */
/*                that stand for various components associated with */
/*                a time. */

/*                There are five types of markers that may appear in a */
/*                format picture.  String Markers, Numeric Markers, */
/*                Meta markers, Modifier Markers and Literal Markers. */

/*                The PICTUR string is examined and the various markers */
/*                are identified. The output time string is constructed */
/*                by replacing each of the identified markers with */
/*                an appropriate time component. */

/*                The various markers and their meanings are discussed */
/*                in the Particulars section below. */

/*                Note that leading and trailing blanks in PICTUR are */
/*                ignored. */


/* $ Detailed_Output */

/*     OUTPUT     is a string matching the format of the input string. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     No exceptions are detected by this routine.  However, the user's */
/*     processing environment must be properly initialized by loading */
/*     a leapseconds kernel via the routine FURNSH before calling this */
/*     routine.  If a leapsecond kernel has not been loaded, an error */
/*     will be signalled by a routines called by TIMOUT. */

/* $ Files */

/*     A leapseconds kernel must be "loaded" via the routine FURNSH */
/*     prior to calling TIMOUT. */

/* $ Particulars */


/*     A format picture is simply a string of letters that lets */
/*     TIMOUT know where various components of a time representation */
/*     should be placed during creation of the time string. */
/*     Here's an example of such a picture: */

/*        MON DD,YYYY  HR:MN:SC.#### (TDB) ::TDB */

/*     Here is a sample of times that would be created by using this */
/*     format. */

/*        JAN 12,1992  12:28:18.2772 (TDB) */
/*        FEB 13,1994  23:18:25.2882 (TDB) */
/*        AUG 21,1995  00:02:00.1881 (TDB) */

/*     As you can see from the samples above, the format picture */
/*     specifies that every time string created should begin with a */
/*     three-letter abbreviation for the month, followed by a space and */
/*     the day of the month. The day of month is followed immediately by */
/*     a comma and the year. The year component is followed by two */
/*     spaces. The next outputs are hours represented as a two digit */
/*     integer, a colon, minutes represented as a two digit integer, */
/*     another colon, and seconds truncated to 4 decimal places and */
/*     having a two digit integer part (rounding can be commanded; see */
/*     the discussion of truncation and rounding below). This is */
/*     followed by a space and the string (TDB). The special marker */
/*     `::TDB' in the time picture is an ``invisible'' marker. It is */
/*     used to specify the time system that should be used in creating */
/*     the time string (in this case Barycentric Dynamical Time). */

/*     TIMOUT does not recognize all of the parts of the time format */
/*     picture in the example above. The list of recognized parts and */
/*     unrecognized parts is shown in the table below. */

/*       Recognized       Unrecognized */
/*       ----------       ------------ */
/*       'MON'            ' ' */
/*       'DD'             ',' */
/*       'YYYY'           '  ' */
/*       'HR'             ':' */
/*       'MN'             '(TDB)' */
/*       'SC' */
/*       '.####' */
/*       '::TDB' */

/*     The unrecognized parts are called literal markers.  They are */
/*     copied exactly as they appear in PICTUR into the output string. */
/*     The recognized parts of the picture are replaced by a */
/*     component of time or, as in the case of `::TDB' are used */
/*     as instructions about the overall properties of the time */
/*     string. */

/*     The full list of recognized markers, their classification */
/*     and meaning are given below. */

/*     MARKER       CLASS     MEANING */
/*     -----------  --------  ----------------------------------------- */
/*     '.##...'     modifier  represents a numeric component that */
/*                            immediately precedes this in a decimal */
/*                            format.  Number of decimal places */
/*                            equals the number of '#'  characters */
/*     '::GCAL'     meta      dates are reported in Gregorian calendar */
/*     '::JCAL'     meta      dates are reported in Julian calendar */
/*     '::MCAL'     meta      dates after 15 October, 1582 are reported */
/*                            in Gregorian calendar; before that */
/*                            dates are reported in Julian calendar */

/*     '::RND'      meta      round output to places specified by */
/*                            least significant component */

/*     '::TDB'      meta      all components should be TDB */

/*     '::TDT'      meta      all components should be TDT */

/*     '::TRNC'     meta      truncate all output components (default) */
/*     '::UTC'      meta      all components should be UTC (default) */
/*     '::UTC+h:m'  meta      all components in UTC offset by +h (hours) */
/*                            and +m (minutes) so as to allow time zones. */
/*     '::UTC-h:m'  meta      all components in UTC offset by -h (hours) */
/*                            and -m (minutes) so as to allow time zones. */
/*     'AMPM'       string    String (either 'A.M.'  or 'P.M.') */
/*                            indicating whether hours are before */
/*                            or after noon. */
/*     'ampm'       string    String (either 'a.m.'  or 'p.m.') */
/*                            indicating whether hours are before */
/*                            or after noon. */
/*     'AP'         numeric   AM/PM equivalents of the hour component */
/*                            of a time. */
/*     'DD'         numeric   Day of month */
/*     'DOY'        numeric   Day of year */
/*     'ERA'        string    String (either 'B.C.'  or 'A.D.') giving */
/*                            era associated with an epoch. */
/*     '?ERA?'      string    String: either ' B.C. ' or ' A.D. ' if the */
/*                            year is before 1000 A.D.  otherwise a */
/*                            blank: ' '. */
/*     'era'        string    String (either 'b.c.'  or 'a.d.') giving */
/*                            era associated with an epoch. */
/*     '?era?'        string   String: either ' b.c. ' or ' a.d. ' if the */
/*                            year is before 1000 A.D. otherwise a */
/*                            blank: ' '. */
/*     'HR'         numeric   hour component of time */
/*     'JULIAND'    numeric   Julian date component of time */
/*     'MM'         numeric   numeric representation of month component */
/*     'MN'         numeric   minute component of time */
/*     'MON'        string    upper case three letter abbreviation for */
/*                            month */
/*     'Mon'        string    capitalized three letter abbreviation for */
/*                            month */
/*     'mon'        string    lower case three letter abbreviation for */
/*                            month */
/*     'MONTH'      string    upper case full name of month */
/*     'Month'      string    capitalized full name of month */
/*     'month'      string    lower case full name of month */
/*     'SC'         numeric   seconds component of time */
/*     'SP1950'     numeric   seconds past 1950 component of time */
/*     'SP2000'     numeric   seconds past 2000 component of time */
/*     'YR'         numeric   last two digits of year component of time */
/*     'YYYY'       numeric   year component of time */
/*     'WEEKDAY'    string    upper case day of week */
/*     'Weekday'    string    capitalized day of week */
/*     'weekday'    string    lower case day of week */
/*     'WKD'        string    upper case three letter abbreviation for */
/*                            day of week. */
/*     'Wkd'        string    capitalized three letter abbreviation for */
/*                            day of week. */
/*     'wkd'        string    lower case three letter abbreviation for */
/*                            day of week. */

/*     String Markers */

/*        String markers are portions of the format picture that will */
/*        be replaced with a character string that represents the */
/*        corresponding component of a time. */

/*     Numeric Markers */

/*        Numeric markers are portions of the format picture that will */
/*        be replaced with a decimal string that represents the */
/*        corresponding component of a time. */

/*     Meta Markers */

/*        Meta markers (listed under the class ``meta'' in the */
/*        table above) are used to indicate `global' properties of */
/*        your time string. You may specify time scale and how */
/*        rounding should be performed on the components of time */
/*        in your output string. Meta markers may be placed anywhere */
/*        in your format picture. They do not contribute to placement */
/*        of characters in output time strings. Also there are no */
/*        restrictions on how many meta markers you may place in */
/*        the format picture. However, if you supply conflicting */
/*        `meta' markers (for example ::TDT and ::TDB) in your */
/*        picture the first marker listed (in left to right order) */
/*        overrules the conflicting marker that appears later in */
/*        the picture. */

/*     Default Meta Markers */

/*        If you do not specify a time system, calendar, or time */
/*        zone through the use of a Meta Marker, TIMOUT uses the */
/*        values returned by the SPICE routine TIMDEF. The default */
/*        time system, calendar returned by TIMDEF are UTC and */
/*        the Gregorian calendar.  The default time zone returned */
/*        by TIMDEF is a blank indicating that no time zone offset */
/*        should be used. */

/*        See the header for the routine TIMDEF for a more complete */
/*        discussion of setting and retrieving default values. */

/*     Modifier Markers */

/*        The numeric markers listed in the table above stand */
/*        for integers unless they are modified through use of a */
/*        modifier marker. The strings */

/*           .# */
/*           .## */
/*           .### */
/*           .#### */

/*        are used to this end. When a numeric marker is followed */
/*        immediately by one of these modifiers, the corresponding time */
/*        component will be written with the number of decimal places */
/*        indicated by the number of successive occurrences of the */
/*        character '#'. Any numeric token may be modified. */

/*     Rounding vs. Truncation */

/*        The meta markers ::TRNC and ::RND allow you to control */
/*        how the output time picture is rounded. If you specify */
/*        ::TRNC all components of time are simply truncated to */
/*        the precision specified by the marker and any modifier. */
/*        If you specify ::RND the output time is rounded to the */
/*        least significant component of the format picture. The */
/*        default action is truncation. */

/*        Whether an output time string should be rounded or */
/*        truncated depends upon what you plan to do with the */
/*        string. For example suppose you simply want to get the */
/*        calendar date associated with a time and not the time of */
/*        day. Then you probably do not want to round your output. */
/*        Rounding 1992 Dec 31, 13:12:00 to the nearest day */
/*        produces 1993 Jan 1. Thus in this case rounding is probably */
/*        not appropriate. */

/*        However, if you are producing output for plotting using */
/*        Julian Date, seconds past 1950 or seconds past 2000, you will */
/*        probably want your output rounded so as to produce a smoother */
/*        plot. */

/*     Time Systems */

/*        TIMOUT can produce output strings for epochs relative to */
/*        any of the three systems UTC, TDT, or TDB.  If you do not */
/*        explicitly specify a time system, TIMOUT will produce strings */
/*        relative to the time system returned by the SPICE routine */
/*        TIMDEF.  Unless you call TIMDEF and change it, the default time */
/*        system is UTC.  However, by using one of the Meta Markers */
/*        ::UTC, ::TDT, or ::TDB you may specify that TIMOUT produce */
/*        time strings relative to the UTC, TDT, or TDB system */
/*        respectively. */

/*     Time Zones */

/*        The meta markers ::UTC+h:m  and ::UTC-h:m  allow you to */
/*        offset UTC times so that you may represent times in a time */
/*        zone other than GMT.  For example you can output times in */
/*        Pacific Standard time by placing the meta-marker ::UTC-8 in */
/*        your format picture. */

/*        For instance, if you use the picture */

/*           YYYY Mon DD, HR:MN:SC ::UTC */

/*        you will get output strings such as: */

/*           1995 Jan 03, 12:00:00 */

/*        If you use the picture */


/*           YYYY Mon DD, HR:MN:SC ::UTC-8 */

/*        you will get output strings such as: */

/*           1995 Jan 03, 04:00:00 */

/*        Finally, if you use the picture */

/*           YYYY Mon DD, HR:MN:SC ::UTC-8:15 */

/*        you will get output string */

/*           1995 Jan 03, 03:45:00 */

/*        Note that the minutes are always added or subtracted based on */
/*        the sign present in the time zone specifier. In the case of */
/*        ::UTC+h:m, minutes are added. In the case ::UTC-h:m, minutes */
/*        are subtracted. */

/*        The unsigned part of the hours component can be no more than */
/*        12.  The unsigned part of the minutes component can be no */
/*        more than 59. */

/*     Calendars */

/*        The calendar currently used by western countries is the */
/*        Gregorian calendar.  This calendar begins on Oct 15, 1582. */
/*        Prior to Gregorian calendar the Julian calendar was used. The */
/*        last Julian calendar date prior to the beginning of the */
/*        Gregorian calendar is Oct 5, 1582. */

/*        The primary difference between the Julian and Gregorian */
/*        calendars is in the determination of leap years. Nevertheless, */
/*        both can be formally extended backward and forward in time */
/*        indefinitely. */

/*        By default TIMOUT uses the default calendar returned by */
/*        TIMDEF. Under most circumstances this will be the Gregorian */
/*        calendar (::GCAL).  However you may specify that TIMOUT use a */
/*        specific calendar through use of one of the calendar Meta */
/*        Markers. You may specify that TIMOUT use the Julian calendar */
/*        (::JCAL), the Gregorian calendar (::GCAL)  or a mixture of */
/*        both (::MCAL). */

/*        If you specify ::MCAL, epochs that occur after the beginning */
/*        of the Gregorian calendar will be represented using the */
/*        Gregorian calendar, and epochs prior to the beginning of the */
/*        Gregorian calendar will be represented using the Julian */
/*        calendar. */

/*     Getting Software to Construct Pictures for You. */

/*        Although it is not difficult to construct time format */
/*        pictures, you do need to be aware of the various markers that */
/*        may appear in a format picture. */

/*        There is an alternative means for getting a format picture. */
/*        The routine TPICTR constructs format pictures from a sample */
/*        time string.  For example, suppose you would like your time */
/*        strings to look like the basic pattern of the string below. */

/*        'Fri Jul 26 12:22:09 PDT 1996' */

/*        You can call TPICTR with this string, and it will create the */
/*        appropriate PICTUR for use with TIMOUT. */

/*        CALL TPICTR ( 'Fri Jul 26 12:22:09 PDT 1996', PICTUR, OK ) */

/*        The result will be: */

/*        'Wkd Mon DD HR:MN:SC (PDT) ::UTC-7' */

/*        Note: not every date that you can read is interpretable by */
/*        TPICTR.  For example, you might be able to understand that */
/*        19960212121116 is Feb 2 1996, 12:11:16.  However, TPICTR */
/*        cannot recognize this string.  Thus it is important to check */
/*        the logical output OK to make sure that TPICTR was able to */
/*        understand the time picture you provided. */

/*        Even thought TPICTR can not recognize every time pattern that */
/*        has been used by various people, it does recognize nearly all */
/*        patterns that you use when you want to communicate outside */
/*        your particular circle of colleagues. */

/* $ Examples */

/*     Example 1. */
/*     ---------- */

/*     Suppose you need to create time strings similar to the */
/*     default time string produced by the UNIX utility "date" */
/*     (for example a string of the form "Thu Aug 01 09:47:16 PDT 1996") */

/*     Make the following string assignment. */

/*       PICTUR = 'Wkd Mon DD HH:MN:SC PDT YYYY ::UTC-7' */

/*    (Note the meta marker ::UTC-7 is used to adjust the output */
/*     time system from UTC to PDT.  Also note that the substring PDT */
/*     is a literal marker.  Without it, the time system would not */
/*     appear in the output time string. */

/*     Now for each time ET for which an output time string is required */
/*     make the call to TIMOUT below, and write the time string. */

/*        CALL TIMOUT ( ET, PICTUR, STRING ) */
/*        WRITE (*,*) STRING */

/*     Alternatively, you can let the routine TPICTR create the TIMOUT */
/*     time picture for you. */

/*       CALL TPICTR ( 'Thu Aug 01 09:47:16 PDT 1996', PICTUR, OK ) */

/*       IF ( OK ) THEN */

/*          CALL TIMOUT ( ET, PICTUR, STRING ) */
/*          WRITE (*,*) STRING */

/*       END IF */


/*     Example 2. */
/*     ---------- */

/*     Suppose you want to output a string that contains both the */
/*     calendar representations of the date as well as the Julian */
/*     date (for example a string of the form: */
/*     "Thu Aug 01 09:47:16 PDT 1996 (2450297.1994 JDUTC)" ) */

/*     Make the following assignment. */

/*       PICTUR = 'Wkd Mon DD HR:MN ::UTC-7 YYYY (JULIAND.#### JDUTC)' */

/*     Now for each time ET for which an output time string is required */
/*     make the call to TIMOUT below, and write the time string. */

/*        CALL TIMOUT ( ET, PICTUR, STRING ) */
/*        WRITE (*,*) STRING */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     W.L. Taber     (JPL) */

/* $ Version */

/* -    SPICELIB Version 3.3.1, 31-Jan-2017 (NJB) */

/*        Updated header comments to draw attention to the fact that */
/*        rounding can be commanded. */

/* -    SPICELIB Version 3.3.0, 23-OCT-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in RMAIND call.  Replaced header references to LDPOOL with */
/*        references to FURNSH. */

/* -    Spicelib Version 3.2.0, 09-APR-2002 (WLT) */

/*        Added code to bracket the fractional part of a time component */
/*        so that it cannot become negative due to inability to invert */
/*        arthmetic operations with double precision arithmetic. */

/* -    Spicelib Version 3.1.0, 21-JUN-2001 (WLT) */

/*        Added the format picture components ?ERA? and ?era? which */
/*        vanish for years after 999 A.D. */

/* -    Spicelib Version 3.0.2, 10-APR-2000 (WLT) */

/*        Declared SCAN to be external. */

/* -    Spicelib Version 3.0.1, 22-JUN-1998 (WLT) */

/*        A number of typographical and grammatical errors */
/*        were corrected in the header. */

/* -    SPICELIB Version 3.0.0, 30-DEC-1997 (WLT) */

/*        The previous version of this routine did not output */
/*        fractional components for epochs prior to 1 A.D. */

/*        In addition, the default time system, calendar and time zone */
/*        are obtained from TIMDEF. */

/* -    SPICELIB Version 2.0.0, 1-APR-1997  (WLT) */

/*        In the event that the format picture requested 'YR' as */
/*        the first component of a time string, the previous edition */
/*        of this routine used the year value corresponding to the */
/*        last call to this routine (or whatever happened to be in */
/*        memory on the first call).  This error has been corrected. */

/* -    SPICELIB Version 1.0.0, 26-JUL-1996 (WLT) */

/* -& */
/* $ Index_Entries */

/*     Convert and format d.p. seconds past J2000 as a string */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 3.3.0, 23-OCT-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in RMAIND call.  Replaced header references to LDPOOL with */
/*        references to FURNSH. */

/* -    Spicelib Version 3.1.0, 21-JUN-2001 (WLT) */

/*        Added the format picture components ?ERA? and ?era? which */
/*        vanish for years after 999 A.D. */

/* -    Spicelib Version 3.0.2, 10-APR-2000 (WLT) */

/*        Declared SCAN to be external. */

/* -    Spicelib Version 3.0.1, 22-JUN-1998 (WLT) */

/*        A number of typographical and grammatical errors */
/*        were corrected in the header. */

/* -    SPICELIB Version 3.0.0, 30-DEC-1997 (WLT) */

/*        The previous version of this routine did not output */
/*        fractional components for epochs prior to 1 A.D. */

/*        This error was due to overuse of the original year */
/*        component returned from TTRANS.  The original year */
/*        component is now saved for use in computing the fractional */
/*        component.  The modified year (used in printing B.C. epochs) */
/*        is stored in a separate variable. */

/* -    SPICELIB Version 2.0.0, 1-APR-1997  (WLT) */

/*        In the event that the format picture requested 'YR' as */
/*        the first component of a time string, the previous edition */
/*        of this routine used the year value corresponding to the */
/*        last call to this routine (or whatever happened to be in */
/*        memory on the first call).  This error has been corrected. */


/*        The error was fixed by recoding the following IF THEN statement */

/*              IF (       TYPE .EQ. YEAR */
/*    .               .OR. TYPE .EQ. MONTH */
/*    .               .OR. TYPE .EQ. MON */
/*    .               .OR. TYPE .EQ. DAY */
/*    .               .OR. TYPE .EQ. DOY */
/*    .               .OR. TYPE .EQ. NOON */
/*    .               .OR. TYPE .EQ. HOUR */
/*    .               .OR. TYPE .EQ. ERA */
/*    .               .OR. TYPE .EQ. AMPM */
/*    .               .OR. TYPE .EQ. MINUTE */
/*    .               .OR. TYPE .EQ. SEC   ) THEN */

/*        as */

/*              IF (       TYPE .EQ. YEAR */
/*    .               .OR. TYPE .EQ. YR */
/*    .               .OR. TYPE .EQ. MONTH */
/*    .               .OR. TYPE .EQ. MON */
/*    .               .OR. TYPE .EQ. DAY */
/*    .               .OR. TYPE .EQ. DOY */
/*    .               .OR. TYPE .EQ. NOON */
/*    .               .OR. TYPE .EQ. HOUR */
/*    .               .OR. TYPE .EQ. ERA */
/*    .               .OR. TYPE .EQ. AMPM */
/*    .               .OR. TYPE .EQ. MINUTE */
/*    .               .OR. TYPE .EQ. SEC   ) THEN */


/* -    Beta Version 2.1.0, 17-MAR-1994 (MJS) (NJB) */

/*        Integer argument to BRCKTD changed from 0 to 0.0D0. */

/* -& */


/*     SPICELIB functions */


/*     Local parameters */


/*     The parameters below act essentially as an enumeration */
/*     of the various kinds of components we will be looking at in the */
/*     input time string. */


/*     The following parameters serve as an enumeration of the various */
/*     time formats that are recognized. */


/*     The parameters below are used to declare the space needed for */
/*     scanning the input format string. */


/*     The length of the local string that we will use for copying */
/*     the format string. */


/*     Local variables */


/*     The next set of variables holds the marks and auxiliary */
/*     arrays used for scanning the format string. */


/*     The variables below are used to hold, base formats, values of */
/*     time vector components, adjustments to use when rounding, */
/*     the lengths of the format pictures and whether or not various */
/*     components have already been computed. */


/*     The array below contains the indexes of the various values */
/*     associated with the three different times of time vectors */
/*     that we will be using YMD, YD, CONTIN. */


/*     We will be making a local copy of the input format string */
/*     and the input time. */


/*     The integers below are used to mark substring boundaries. */


/*     Times come in three flavors: TDT, TDB, UTC.  The one for used */
/*     on this particular invocation of TIMOUT is stored in TIMTYP. */
/*     The routine TTRANS needs to have input and output time vector */
/*     types.  The one used based upon the input PICTUR is stored */
/*     in BASTYP. */


/*     Loop counters and delimiters */


/*     Utility double precision numbers */


/*     The array power is used to assist in the truncation of double */
/*     precision values. */


/*     calendar variables. */


/*     Character string representations for months and week days. */


/*     Save everything. */


/*     Initial values */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "TIMOUT", (ftnlen)6);

/*     Chapter 1. Initializations. */
/*     ================================================================= */

/*     On the first pass, we need to set up the recognized tokens */
/*     that will be used for scanning, the classes of these tokens */
/*     and the array of ID's for time systems. */

    if (__state->first) {
	__state->first = FALSE_;
	s_copy(&__global_state->f2c, __state->marks, "YYYY", (ftnlen)8, (
		ftnlen)4);
	s_copy(&__global_state->f2c, __state->marks + 8, "YR", (ftnlen)8, (
		ftnlen)2);
	s_copy(&__global_state->f2c, __state->marks + 16, "MON", (ftnlen)8, (
		ftnlen)3);
	s_copy(&__global_state->f2c, __state->marks + 24, "Mon", (ftnlen)8, (
		ftnlen)3);
	s_copy(&__global_state->f2c, __state->marks + 32, "mon", (ftnlen)8, (
		ftnlen)3);
	s_copy(&__global_state->f2c, __state->marks + 40, "MONTH", (ftnlen)8, 
		(ftnlen)5);
	s_copy(&__global_state->f2c, __state->marks + 48, "Month", (ftnlen)8, 
		(ftnlen)5);
	s_copy(&__global_state->f2c, __state->marks + 56, "month", (ftnlen)8, 
		(ftnlen)5);
	s_copy(&__global_state->f2c, __state->marks + 64, "MM", (ftnlen)8, (
		ftnlen)2);
	s_copy(&__global_state->f2c, __state->marks + 72, "DOY", (ftnlen)8, (
		ftnlen)3);
	s_copy(&__global_state->f2c, __state->marks + 80, "WKD", (ftnlen)8, (
		ftnlen)3);
	s_copy(&__global_state->f2c, __state->marks + 88, "Wkd", (ftnlen)8, (
		ftnlen)3);
	s_copy(&__global_state->f2c, __state->marks + 96, "wkd", (ftnlen)8, (
		ftnlen)3);
	s_copy(&__global_state->f2c, __state->marks + 104, "WEEKDAY", (ftnlen)
		8, (ftnlen)7);
	s_copy(&__global_state->f2c, __state->marks + 112, "Weekday", (ftnlen)
		8, (ftnlen)7);
	s_copy(&__global_state->f2c, __state->marks + 120, "weekday", (ftnlen)
		8, (ftnlen)7);
	s_copy(&__global_state->f2c, __state->marks + 128, "DD", (ftnlen)8, (
		ftnlen)2);
	s_copy(&__global_state->f2c, __state->marks + 136, "MN", (ftnlen)8, (
		ftnlen)2);
	s_copy(&__global_state->f2c, __state->marks + 144, "HR", (ftnlen)8, (
		ftnlen)2);
	s_copy(&__global_state->f2c, __state->marks + 152, "SC", (ftnlen)8, (
		ftnlen)2);
	s_copy(&__global_state->f2c, __state->marks + 160, ".#", (ftnlen)8, (
		ftnlen)2);
	s_copy(&__global_state->f2c, __state->marks + 168, "#", (ftnlen)8, (
		ftnlen)1);
	s_copy(&__global_state->f2c, __state->marks + 176, "JULIAND", (ftnlen)
		8, (ftnlen)7);
	s_copy(&__global_state->f2c, __state->marks + 184, "::UTC", (ftnlen)8,
		 (ftnlen)5);
	s_copy(&__global_state->f2c, __state->marks + 192, "::TDB", (ftnlen)8,
		 (ftnlen)5);
	s_copy(&__global_state->f2c, __state->marks + 200, "::TDT", (ftnlen)8,
		 (ftnlen)5);
	s_copy(&__global_state->f2c, __state->marks + 208, "SP2000", (ftnlen)
		8, (ftnlen)6);
	s_copy(&__global_state->f2c, __state->marks + 216, "SP1950", (ftnlen)
		8, (ftnlen)6);
	s_copy(&__global_state->f2c, __state->marks + 224, "::RND", (ftnlen)8,
		 (ftnlen)5);
	s_copy(&__global_state->f2c, __state->marks + 232, "::TRNC", (ftnlen)
		8, (ftnlen)6);
	s_copy(&__global_state->f2c, __state->marks + 240, "ERA", (ftnlen)8, (
		ftnlen)3);
	s_copy(&__global_state->f2c, __state->marks + 248, "era", (ftnlen)8, (
		ftnlen)3);
	s_copy(&__global_state->f2c, __state->marks + 256, "AMPM", (ftnlen)8, 
		(ftnlen)4);
	s_copy(&__global_state->f2c, __state->marks + 264, "ampm", (ftnlen)8, 
		(ftnlen)4);
	s_copy(&__global_state->f2c, __state->marks + 272, "::UTC+", (ftnlen)
		8, (ftnlen)6);
	s_copy(&__global_state->f2c, __state->marks + 280, "::UTC-", (ftnlen)
		8, (ftnlen)6);
	s_copy(&__global_state->f2c, __state->marks + 288, "::JCAL", (ftnlen)
		8, (ftnlen)6);
	s_copy(&__global_state->f2c, __state->marks + 296, "::GCAL", (ftnlen)
		8, (ftnlen)6);
	s_copy(&__global_state->f2c, __state->marks + 304, "::MCAL", (ftnlen)
		8, (ftnlen)6);
	s_copy(&__global_state->f2c, __state->marks + 312, "AP", (ftnlen)8, (
		ftnlen)2);
	s_copy(&__global_state->f2c, __state->marks + 320, "?ERA?", (ftnlen)8,
		 (ftnlen)5);
	s_copy(&__global_state->f2c, __state->marks + 328, "?era?", (ftnlen)8,
		 (ftnlen)5);
	__state->nmarks = 42;
	scanpr_(__global_state, &__state->nmarks, __state->marks, 
		__state->mrklen, __state->pntrs, (ftnlen)8);

/*        Now that we've prepared our recognized substrings and */
/*        auxiliary arrays for scanning, collect the id's of the */
/*        various marks and classify the various marks. */
/*        substrings. */

	__state->id[1] = 0;
	__state->id[2] = bsrchc_(__global_state, "YYYY", &__state->nmarks, 
		__state->marks, (ftnlen)4, (ftnlen)8);
	__state->id[3] = bsrchc_(__global_state, "YR", &__state->nmarks, 
		__state->marks, (ftnlen)2, (ftnlen)8);
	__state->id[4] = bsrchc_(__global_state, "MON", &__state->nmarks, 
		__state->marks, (ftnlen)3, (ftnlen)8);
	__state->id[5] = bsrchc_(__global_state, "Mon", &__state->nmarks, 
		__state->marks, (ftnlen)3, (ftnlen)8);
	__state->id[6] = bsrchc_(__global_state, "mon", &__state->nmarks, 
		__state->marks, (ftnlen)3, (ftnlen)8);
	__state->id[7] = bsrchc_(__global_state, "MONTH", &__state->nmarks, 
		__state->marks, (ftnlen)5, (ftnlen)8);
	__state->id[8] = bsrchc_(__global_state, "Month", &__state->nmarks, 
		__state->marks, (ftnlen)5, (ftnlen)8);
	__state->id[9] = bsrchc_(__global_state, "month", &__state->nmarks, 
		__state->marks, (ftnlen)5, (ftnlen)8);
	__state->id[10] = bsrchc_(__global_state, "MM", &__state->nmarks, 
		__state->marks, (ftnlen)2, (ftnlen)8);
	__state->id[11] = bsrchc_(__global_state, "DOY", &__state->nmarks, 
		__state->marks, (ftnlen)3, (ftnlen)8);
	__state->id[12] = bsrchc_(__global_state, "WKD", &__state->nmarks, 
		__state->marks, (ftnlen)3, (ftnlen)8);
	__state->id[13] = bsrchc_(__global_state, "Wkd", &__state->nmarks, 
		__state->marks, (ftnlen)3, (ftnlen)8);
	__state->id[14] = bsrchc_(__global_state, "wkd", &__state->nmarks, 
		__state->marks, (ftnlen)3, (ftnlen)8);
	__state->id[15] = bsrchc_(__global_state, "WEEKDAY", &__state->nmarks,
		 __state->marks, (ftnlen)7, (ftnlen)8);
	__state->id[16] = bsrchc_(__global_state, "Weekday", &__state->nmarks,
		 __state->marks, (ftnlen)7, (ftnlen)8);
	__state->id[17] = bsrchc_(__global_state, "weekday", &__state->nmarks,
		 __state->marks, (ftnlen)7, (ftnlen)8);
	__state->id[18] = bsrchc_(__global_state, "DD", &__state->nmarks, 
		__state->marks, (ftnlen)2, (ftnlen)8);
	__state->id[19] = bsrchc_(__global_state, "MN", &__state->nmarks, 
		__state->marks, (ftnlen)2, (ftnlen)8);
	__state->id[20] = bsrchc_(__global_state, "HR", &__state->nmarks, 
		__state->marks, (ftnlen)2, (ftnlen)8);
	__state->id[21] = bsrchc_(__global_state, "SC", &__state->nmarks, 
		__state->marks, (ftnlen)2, (ftnlen)8);
	__state->id[22] = bsrchc_(__global_state, ".#", &__state->nmarks, 
		__state->marks, (ftnlen)2, (ftnlen)8);
	__state->id[23] = bsrchc_(__global_state, "#", &__state->nmarks, 
		__state->marks, (ftnlen)1, (ftnlen)8);
	__state->id[24] = bsrchc_(__global_state, "JULIAND", &__state->nmarks,
		 __state->marks, (ftnlen)7, (ftnlen)8);
	__state->id[25] = bsrchc_(__global_state, "::UTC", &__state->nmarks, 
		__state->marks, (ftnlen)5, (ftnlen)8);
	__state->id[26] = bsrchc_(__global_state, "::TDB", &__state->nmarks, 
		__state->marks, (ftnlen)5, (ftnlen)8);
	__state->id[27] = bsrchc_(__global_state, "::TDT", &__state->nmarks, 
		__state->marks, (ftnlen)5, (ftnlen)8);
	__state->id[28] = bsrchc_(__global_state, "SP2000", &__state->nmarks, 
		__state->marks, (ftnlen)6, (ftnlen)8);
	__state->id[29] = bsrchc_(__global_state, "SP1950", &__state->nmarks, 
		__state->marks, (ftnlen)6, (ftnlen)8);
	__state->id[30] = bsrchc_(__global_state, "::RND", &__state->nmarks, 
		__state->marks, (ftnlen)5, (ftnlen)8);
	__state->id[31] = bsrchc_(__global_state, "::TRNC", &__state->nmarks, 
		__state->marks, (ftnlen)6, (ftnlen)8);
	__state->id[32] = bsrchc_(__global_state, "ERA", &__state->nmarks, 
		__state->marks, (ftnlen)3, (ftnlen)8);
	__state->id[33] = bsrchc_(__global_state, "era", &__state->nmarks, 
		__state->marks, (ftnlen)3, (ftnlen)8);
	__state->id[34] = bsrchc_(__global_state, "?ERA?", &__state->nmarks, 
		__state->marks, (ftnlen)5, (ftnlen)8);
	__state->id[35] = bsrchc_(__global_state, "?era?", &__state->nmarks, 
		__state->marks, (ftnlen)5, (ftnlen)8);
	__state->id[36] = bsrchc_(__global_state, "AMPM", &__state->nmarks, 
		__state->marks, (ftnlen)4, (ftnlen)8);
	__state->id[37] = bsrchc_(__global_state, "ampm", &__state->nmarks, 
		__state->marks, (ftnlen)4, (ftnlen)8);
	__state->id[38] = bsrchc_(__global_state, "::UTC+", &__state->nmarks, 
		__state->marks, (ftnlen)6, (ftnlen)8);
	__state->id[39] = bsrchc_(__global_state, "::UTC-", &__state->nmarks, 
		__state->marks, (ftnlen)6, (ftnlen)8);
	__state->id[40] = bsrchc_(__global_state, "::JCAL", &__state->nmarks, 
		__state->marks, (ftnlen)6, (ftnlen)8);
	__state->id[41] = bsrchc_(__global_state, "::GCAL", &__state->nmarks, 
		__state->marks, (ftnlen)6, (ftnlen)8);
	__state->id[42] = bsrchc_(__global_state, "::MCAL", &__state->nmarks, 
		__state->marks, (ftnlen)6, (ftnlen)8);
	__state->id[45] = bsrchc_(__global_state, "AP", &__state->nmarks, 
		__state->marks, (ftnlen)2, (ftnlen)8);
	__state->class__[(i__1 = __state->id[1]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1174)] = 2;
	__state->class__[(i__1 = __state->id[2]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1175)] = 3;
	__state->class__[(i__1 = __state->id[3]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1176)] = 4;
	__state->class__[(i__1 = __state->id[4]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1177)] = 47;
	__state->class__[(i__1 = __state->id[5]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1178)] = 47;
	__state->class__[(i__1 = __state->id[6]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1179)] = 47;
	__state->class__[(i__1 = __state->id[7]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1180)] = 47;
	__state->class__[(i__1 = __state->id[8]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1181)] = 47;
	__state->class__[(i__1 = __state->id[9]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1182)] = 47;
	__state->class__[(i__1 = __state->id[10]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1183)] = 11;
	__state->class__[(i__1 = __state->id[11]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1184)] = 12;
	__state->class__[(i__1 = __state->id[12]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1185)] = 48;
	__state->class__[(i__1 = __state->id[13]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1186)] = 48;
	__state->class__[(i__1 = __state->id[14]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1187)] = 48;
	__state->class__[(i__1 = __state->id[15]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1188)] = 48;
	__state->class__[(i__1 = __state->id[16]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1189)] = 48;
	__state->class__[(i__1 = __state->id[17]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1190)] = 48;
	__state->class__[(i__1 = __state->id[18]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1191)] = 19;
	__state->class__[(i__1 = __state->id[19]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1192)] = 20;
	__state->class__[(i__1 = __state->id[20]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1193)] = 21;
	__state->class__[(i__1 = __state->id[21]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1194)] = 22;
	__state->class__[(i__1 = __state->id[22]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1195)] = 23;
	__state->class__[(i__1 = __state->id[23]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1196)] = 24;
	__state->class__[(i__1 = __state->id[24]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1197)] = 25;
	__state->class__[(i__1 = __state->id[25]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1198)] = 44;
	__state->class__[(i__1 = __state->id[26]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1199)] = 44;
	__state->class__[(i__1 = __state->id[27]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1200)] = 44;
	__state->class__[(i__1 = __state->id[28]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1201)] = 29;
	__state->class__[(i__1 = __state->id[29]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1202)] = 30;
	__state->class__[(i__1 = __state->id[30]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1203)] = 31;
	__state->class__[(i__1 = __state->id[31]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1204)] = 32;
	__state->class__[(i__1 = __state->id[32]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1205)] = 49;
	__state->class__[(i__1 = __state->id[33]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1206)] = 49;
	__state->class__[(i__1 = __state->id[34]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1207)] = 49;
	__state->class__[(i__1 = __state->id[35]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1208)] = 49;
	__state->class__[(i__1 = __state->id[36]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1209)] = 50;
	__state->class__[(i__1 = __state->id[37]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1210)] = 50;
	__state->class__[(i__1 = __state->id[38]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1211)] = 44;
	__state->class__[(i__1 = __state->id[39]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1212)] = 44;
	__state->class__[(i__1 = __state->id[40]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1213)] = 45;
	__state->class__[(i__1 = __state->id[41]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1214)] = 45;
	__state->class__[(i__1 = __state->id[42]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1215)] = 45;
	__state->class__[(i__1 = __state->id[45]) < 43 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "class", i__1, "timout_", (
		ftnlen)1216)] = 46;
	for (__state->i__ = 1; __state->i__ <= 51; ++__state->i__) {
	    __state->pad[(i__1 = __state->i__ - 1) < 51 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "pad", i__1, "timout_", (
		    ftnlen)1219)] = 0.;
	}
	__state->pad[21] = .5;
	__state->pad[19] = __state->pad[21] * 60.;
	__state->pad[20] = __state->pad[19] * 60.;
	__state->pad[18] = __state->pad[20] * 24.;
	__state->pad[10] = __state->pad[18] * 30.;
	__state->pad[11] = __state->pad[18];
	__state->pad[46] = __state->pad[10];
	__state->pad[2] = __state->pad[18] * 365.;
	__state->pad[3] = __state->pad[18] * 365.;
	__state->pad[24] = __state->pad[18];
	__state->pad[28] = __state->pad[21];
	__state->pad[29] = __state->pad[21];
	__state->pad[45] = __state->pad[20];

/*        After we've made the initial scan for tokens and determined */
/*        the time system requested, we will want to get rid of the */
/*        time system tokens. */

	__state->dump[0] = __state->id[25];
	__state->dump[1] = __state->id[27];
	__state->dump[2] = __state->id[26];
	__state->dump[3] = __state->id[30];
	__state->dump[4] = __state->id[31];
	__state->dump[5] = __state->id[39];
	__state->dump[6] = __state->id[38];
	__state->dump[7] = __state->id[40];
	__state->dump[8] = __state->id[41];
	__state->dump[9] = __state->id[42];
	__state->ndump = 10;

/*        Set up the default formats for the various time components */

	s_copy(&__global_state->f2c, __state->orignl + 64, "YYYY", (ftnlen)32,
		 (ftnlen)4);
	__state->length[2] = 4;
	s_copy(&__global_state->f2c, __state->orignl + 96, "0Y", (ftnlen)32, (
		ftnlen)2);
	__state->length[3] = 2;
	s_copy(&__global_state->f2c, __state->orignl + 352, "0DD", (ftnlen)32,
		 (ftnlen)3);
	__state->length[11] = 3;
	s_copy(&__global_state->f2c, __state->orignl + 576, "0D", (ftnlen)32, 
		(ftnlen)2);
	__state->length[18] = 2;
	s_copy(&__global_state->f2c, __state->orignl + 320, "0M", (ftnlen)32, 
		(ftnlen)2);
	__state->length[10] = 2;
	s_copy(&__global_state->f2c, __state->orignl + 640, "0H", (ftnlen)32, 
		(ftnlen)2);
	__state->length[20] = 2;
	s_copy(&__global_state->f2c, __state->orignl + 1440, "0H", (ftnlen)32,
		 (ftnlen)2);
	__state->length[45] = 2;
	s_copy(&__global_state->f2c, __state->orignl + 608, "0M", (ftnlen)32, 
		(ftnlen)2);
	__state->length[19] = 2;
	s_copy(&__global_state->f2c, __state->orignl + 672, "0S", (ftnlen)32, 
		(ftnlen)2);
	__state->length[21] = 2;
	s_copy(&__global_state->f2c, __state->orignl + 768, "XXXXXXX", (
		ftnlen)32, (ftnlen)7);
	__state->length[24] = 7;
	s_copy(&__global_state->f2c, __state->orignl + 896, "XXXXXXXXXXX", (
		ftnlen)32, (ftnlen)11);
	__state->length[28] = 11;
	s_copy(&__global_state->f2c, __state->orignl + 928, "XXXXXXXXXXX", (
		ftnlen)32, (ftnlen)11);
	__state->length[29] = 11;

/*        Finally set up the component pointers... */

	__state->compnt[0] = 51;
	__state->compnt[1] = 11;
	__state->compnt[2] = 19;
	__state->compnt[3] = 21;
	__state->compnt[4] = 20;
	__state->compnt[5] = 22;
	__state->compnt[8] = 1;
    }

/*     Chapter 2.  Parsing the input picture. */
/*     ============================================================== */

/*     First let's copy the input picture into local storage */
/*     (left justified) and get just past the end of the */
/*     significant portion (this way the loop that constructs the */
/*     output string will terminate with no unfinished business */
/*     left to resolve). */

    s_copy(&__global_state->f2c, __state->mystr, " ", (ftnlen)256, (ftnlen)1);
    ljust_(__global_state, pictur, __state->mystr, pictur_len, (ftnlen)255);
    __state->e = rtrim_(__global_state, __state->mystr, (ftnlen)256) + 1;
    __state->start = 1;

/*     Scan the input string. */

    scan_(__global_state, __state->mystr, __state->marks, __state->mrklen, 
	    __state->pntrs, &__state->c__100, &__state->start, &
	    __state->ntokns, __state->ident, __state->beg, __state->end, 
	    __state->e, (ftnlen)8);

/*     Locate the time system that will be used.  This must */
/*     be one of the following: UTC, TDB, TDT */

    __state->unknwn = TRUE_;
    __state->go2jul = FALSE_;
    __state->dozone = FALSE_;
    __state->i__ = 1;
    __state->hoff = 0.;
    __state->moff = 0.;

/*     Get the default time type from TIMDEF */

    timdef_(__global_state, "GET", "SYSTEM", __state->tsys, (ftnlen)3, (
	    ftnlen)6, (ftnlen)16);
    if (s_cmp(&__global_state->f2c, __state->tsys, "UTC", (ftnlen)16, (ftnlen)
	    3) == 0) {
	__state->timtyp = __state->id[25];
    } else if (s_cmp(&__global_state->f2c, __state->tsys, "TDB", (ftnlen)16, (
	    ftnlen)3) == 0) {
	__state->timtyp = __state->id[26];
    } else if (s_cmp(&__global_state->f2c, __state->tsys, "TDT", (ftnlen)16, (
	    ftnlen)3) == 0) {
	__state->timtyp = __state->id[27];
    } else {
	__state->timtyp = __state->id[38];
	timdef_(__global_state, "GET", "ZONE", __state->zon, (ftnlen)3, (
		ftnlen)4, (ftnlen)32);
	prefix_(__global_state, "::", &__state->c__0, __state->zon, (ftnlen)2,
		 (ftnlen)32);
	zzutcpm_(__global_state, __state->zon, &__state->c__1, &__state->hoff,
		 &__state->moff, &__state->last, &__state->ok, (ftnlen)32);
	__state->dozone = __state->ok;

/*        The routine TIMDEF uses ZZUTCPM to determine whether */
/*        or not a time zone is legitimate before it stores it */
/*        to be "GOTTEN."  As a result the value of OK should */
/*        always be TRUE.  However, just in case TIMDEF should */
/*        someday use something other that ZZUTCPM for checking */
/*        we put in the unneeded check below. */

	if (! __state->ok) {
	    __state->timtyp = __state->id[25];
	}
    }
    while(__state->unknwn && __state->i__ <= __state->ntokns) {
	if (__state->class__[(i__2 = __state->ident[(i__1 = __state->i__ - 1) 
		< 100 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"ident", i__1, "timout_", (ftnlen)1378)]) < 43 && 0 <= i__2 ? 
		i__2 : s_rnge(&__global_state->f2c, "class", i__2, "timout_", 
		(ftnlen)1378)] == 44) {
	    __state->timtyp = __state->ident[(i__1 = __state->i__ - 1) < 100 
		    && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ident"
		    , i__1, "timout_", (ftnlen)1379)];
	    __state->unknwn = FALSE_;
	    __state->dozone = FALSE_;
	    if (__state->ident[(i__1 = __state->i__ - 1) < 100 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "ident", i__1, "timo"
		    "ut_", (ftnlen)1383)] == __state->id[38] || __state->ident[
		    (i__2 = __state->i__ - 1) < 100 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "ident", i__2, "timout_", (
		    ftnlen)1383)] == __state->id[39]) {

/*              We've got a time zone specification. Parse it and */
/*              store the offsets from UTC. */

		zzutcpm_(__global_state, __state->mystr, &__state->beg[(i__1 =
			 __state->i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(
			&__global_state->f2c, "beg", i__1, "timout_", (ftnlen)
			1390)], &__state->hoff, &__state->moff, &
			__state->last, &__state->ok, (ftnlen)256);
		if (__state->ok) {
		    __state->dozone = TRUE_;
		    __state->timtyp = __state->id[38];

/*                 If we ran all the way up to the end of the next */
/*                 token, we simply reset the identity of the next */
/*                 token to be a zone type and increment  I. */

/*                 This way we never see the next token in this loop */
/*                 and it gets removed later when time systems and */
/*                 other meta markers from  our copy of the time */
/*                 format string. */

		    if (__state->last == __state->end[(i__1 = __state->i__) < 
			    100 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "end", i__1, "timout_", (
			    ftnlen)1407)]) {
			__state->ident[(i__1 = __state->i__) < 100 && 0 <= 
				i__1 ? i__1 : s_rnge(&__global_state->f2c, 
				"ident", i__1, "timout_", (ftnlen)1408)] = 
				__state->ident[(i__2 = __state->i__ - 1) < 
				100 && 0 <= i__2 ? i__2 : s_rnge(&
				__global_state->f2c, "ident", i__2, "timout_",
				 (ftnlen)1408)];
			++__state->i__;
		    } else {
			__state->end[(i__1 = __state->i__ - 1) < 100 && 0 <= 
				i__1 ? i__1 : s_rnge(&__global_state->f2c, 
				"end", i__1, "timout_", (ftnlen)1411)] = 
				__state->last;
			__state->beg[(i__1 = __state->i__) < 100 && 0 <= i__1 
				? i__1 : s_rnge(&__global_state->f2c, "beg", 
				i__1, "timout_", (ftnlen)1412)] = 
				__state->last + 1;
		    }
		}
	    }
	}
	++__state->i__;
    }

/*     Determine whether we should use the Julian or gregorian (default) */
/*     calendar */

    __state->unknwn = TRUE_;
    __state->i__ = 1;

/*     Get the default calendar from TIMDEF. */

    timdef_(__global_state, "GET", "CALENDAR", __state->cal, (ftnlen)3, (
	    ftnlen)8, (ftnlen)16);
    if (s_cmp(&__global_state->f2c, __state->cal, "GREGORIAN", (ftnlen)16, (
	    ftnlen)9) == 0) {
	__state->caltyp = __state->id[41];
    } else if (s_cmp(&__global_state->f2c, __state->cal, "JULIAN", (ftnlen)16,
	     (ftnlen)6) == 0) {
	__state->caltyp = __state->id[40];
    } else {
	__state->caltyp = __state->id[42];
    }
    while(__state->unknwn && __state->i__ <= __state->ntokns) {
	if (__state->class__[(i__2 = __state->ident[(i__1 = __state->i__ - 1) 
		< 100 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"ident", i__1, "timout_", (ftnlen)1448)]) < 43 && 0 <= i__2 ? 
		i__2 : s_rnge(&__global_state->f2c, "class", i__2, "timout_", 
		(ftnlen)1448)] == 45) {
	    __state->caltyp = __state->ident[(i__1 = __state->i__ - 1) < 100 
		    && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ident"
		    , i__1, "timout_", (ftnlen)1449)];
	    __state->unknwn = FALSE_;
	}
	++__state->i__;
    }

/*     Next determine whether or not we shall be performing rounding */
/*     on output. */

    __state->pumpup = isrchi_(__global_state, &__state->id[30], &
	    __state->ntokns, __state->ident) != 0;

/*     Determine if we have an Era specification */

    __state->doera = isrchi_(__global_state, &__state->id[33], &
	    __state->ntokns, __state->ident) != 0 || isrchi_(__global_state, &
	    __state->id[32], &__state->ntokns, __state->ident) != 0 || 
	    isrchi_(__global_state, &__state->id[34], &__state->ntokns, 
	    __state->ident) != 0 || isrchi_(__global_state, &__state->id[35], 
	    &__state->ntokns, __state->ident) != 0;

/*     Until we've examined the year, we assume that the era is not */
/*     supposed to vanish. */

    __state->vanish = FALSE_;

/*     Next remove all of the time system dudes from the list of */
/*     tokens. */

    scanrj_(__global_state, __state->dump, &__state->ndump, &__state->ntokns, 
	    __state->ident, __state->beg, __state->end);

/*     If the user wants to round the output, we need to pump up ET */
/*     by the smallest significant part of the input picture.  But */
/*     in either case we are going to pad the input time.  For now */
/*     we pad it by zero. */

    __state->timpad = 0.;
    if (__state->pumpup) {

/*        We need to determine the amount to pad ET by.  So we need */
/*        to look at the string and find the least significant component */
/*        that has been requested.  Keep in mind that the last token */
/*        is of type NONAME (its a blank) by construction. */

	__state->i__ = 1;
	while(__state->i__ <= __state->ntokns) {
	    __state->type__ = __state->class__[(i__2 = __state->ident[(i__1 = 
		    __state->i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "ident", i__1, "timout_", (ftnlen)
		    1503)]) < 43 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "class", i__2, "timout_", (ftnlen)
		    1503)];
	    if (__state->type__ == 2 || __state->type__ == 23 || 
		    __state->type__ == 24 || __state->type__ == 50 || 
		    __state->type__ == 49 || __state->type__ == 47 || 
		    __state->type__ == 48) {

/*              Don't do anything, just go on to the next token. */

		++__state->i__;
	    } else {

/*              Look up the amount we should pad our time by. */

		__state->factor = 1.;
		__state->incr = __state->pad[(i__1 = __state->type__ - 1) < 
			51 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			"pad", i__1, "timout_", (ftnlen)1524)];

/*              Examine the next token.  If it's not a decimal point */
/*              and marker, we have the least significant part of */
/*              this component. */

		++__state->i__;
		__state->type__ = __state->class__[(i__2 = __state->ident[(
			i__1 = __state->i__ - 1) < 100 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "ident", i__1, "timout_",
			 (ftnlen)1532)]) < 43 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "class", i__2, "timout_", (
			ftnlen)1532)];
		if (__state->type__ == 23) {
		    __state->factor *= .1;
		    ++__state->i__;

/*                 Now just look for the end of the string of place */
/*                 holders */

		    while(__state->ident[(i__1 = __state->i__ - 1) < 100 && 0 
			    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			    "ident", i__1, "timout_", (ftnlen)1543)] == 
			    __state->id[23]) {
			__state->factor *= .1;
			++__state->i__;
		    }
		}

/*              Now compute the time pad for this component of the */
/*              time string. */

		__state->incr *= __state->factor;
		if (__state->timpad != 0.) {
		    __state->timpad = min(__state->timpad,__state->incr);
		} else {
		    __state->timpad = __state->incr;
		}
	    }
	}
    }

/*     Right now we don't have any components of the time format */
/*     and we don't need any of them so far. */

    for (__state->part = 1; __state->part <= 51; ++__state->part) {
	__state->have[(i__1 = __state->part - 1) < 51 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "have", i__1, "timout_", (ftnlen)
		1573)] = FALSE_;
    }

/*     Set up the input time format and the output time format that will */
/*     be used later. */

/*     The input time format is used to convert the basic ET we have now */
/*     to one of the various time formats that are supported by the */
/*     routine TTRANS.  If we are going to construct a string in one of */
/*     the dynamical time systems we will call the input time a formal */
/*     time in seconds past a formal calendar epoch of J2000.  If on the */
/*     other hand we are going to construct a UTC based string, we will */
/*     convert our ET to an earth based epoch (TDT) and use this as our */
/*     base input system. */


    __state->myet = *et;
    if (__state->timtyp == __state->id[26]) {

/*        Since we are likely to need SP2000, SP1950 or JD, we */
/*        compute them now. */

	__state->myet += __state->timpad;
	__state->values[28] = __state->myet;
	__state->values[24] = unitim_(__global_state, &__state->myet, "TDB", 
		"JDTDB", (ftnlen)3, (ftnlen)5);
	__state->values[29] = __state->values[28] + spd_(__global_state) * (
		j2000_(__global_state) - j1950_(__global_state));
	s_copy(&__global_state->f2c, __state->bastyp, "FORMAL", (ftnlen)16, (
		ftnlen)6);
	s_copy(&__global_state->f2c, __state->ymdfmt, "YMDF", (ftnlen)8, (
		ftnlen)4);
	s_copy(&__global_state->f2c, __state->ywfmt, "YMWDF", (ftnlen)8, (
		ftnlen)5);
	__state->have[28] = TRUE_;
	__state->have[29] = TRUE_;
	__state->have[24] = TRUE_;
    } else if (__state->timtyp == __state->id[27]) {
	__state->myet = unitim_(__global_state, &__state->myet, "TDB", "TDT", 
		(ftnlen)3, (ftnlen)3) + __state->timpad;
	__state->values[28] = __state->myet;
	__state->values[24] = unitim_(__global_state, &__state->myet, "TDT", 
		"JDTDT", (ftnlen)3, (ftnlen)5);
	__state->values[29] = __state->values[28] + spd_(__global_state) * (
		j2000_(__global_state) - j1950_(__global_state));
	s_copy(&__global_state->f2c, __state->bastyp, "FORMAL", (ftnlen)16, (
		ftnlen)6);
	s_copy(&__global_state->f2c, __state->ymdfmt, "YMDF", (ftnlen)8, (
		ftnlen)4);
	s_copy(&__global_state->f2c, __state->ywfmt, "YMWDF", (ftnlen)8, (
		ftnlen)5);
	__state->have[28] = TRUE_;
	__state->have[29] = TRUE_;
	__state->have[24] = TRUE_;
    } else {

/*        In this case we convert to an earth based frame for our */
/*        working epoch.  This rounds properly when it's time to get */
/*        fractional components. */

	__state->myet = unitim_(__global_state, &__state->myet, "TDB", "TDT", 
		(ftnlen)3, (ftnlen)3) + __state->timpad;
	s_copy(&__global_state->f2c, __state->bastyp, "TDT", (ftnlen)16, (
		ftnlen)3);
	s_copy(&__global_state->f2c, __state->ymdfmt, "YMD", (ftnlen)8, (
		ftnlen)3);
	s_copy(&__global_state->f2c, __state->ywfmt, "YMWD", (ftnlen)8, (
		ftnlen)4);
    }

/*     Chapter 3.  Building the Output String */
/*     ================================================================== */


/*     Now we are ready to go, we need to fetch the tokens */
/*     and construct the output string.  We will */
/*     put the next portion of the output at APPND */

    __state->appnd = 1;
    __state->making = FALSE_;
    i__1 = __state->ntokns;
    for (__state->i__ = 1; __state->i__ <= i__1; ++__state->i__) {
	__state->type__ = __state->class__[(i__3 = __state->ident[(i__2 = 
		__state->i__ - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "ident", i__2, "timout_", (ftnlen)1654)])
		 < 43 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		"class", i__3, "timout_", (ftnlen)1654)];
	__state->tvec[0] = __state->myet;

/*        If the next marker is not one we use as a place holder */
/*        in the fractional part of decimal formats AND we */
/*        are in the process of building a format, then the format */
/*        building is done.  We can construct the component and */
/*        append it to the string we are building. */

	if (__state->type__ != 24 && __state->making) {

/*           We also need to be sure this isn't a decimal point */
/*           marker before we add on to the output string. */

	    if (__state->type__ != 23 || __state->have[22]) {

/*              We are going to truncate the number to the number of */
/*              places requested NOT round. */

		i__3 = __state->width - __state->length[(i__2 = 
			__state->numtyp - 1) < 51 && 0 <= i__2 ? i__2 : 
			s_rnge(&__global_state->f2c, "length", i__2, "timout_"
			, (ftnlen)1676)] - 1;
		__state->trncat = brckti_(__global_state, &i__3, &
			__state->c__0, &__state->c__14);
		__state->frac = __state->value - d_int(&__global_state->f2c, &
			__state->value);
		if (__state->frac < 0.) {
		    __state->value += -1.;
		    __state->frac += 1.;
		}
		d__1 = __state->frac * __state->power[(i__2 = __state->trncat)
			 < 15 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "power", i__2, "timout_", (
			ftnlen)1684)];
		__state->intmed = (d_int(&__global_state->f2c, &d__1) - .125) 
			/ __state->power[(i__3 = __state->trncat) < 15 && 0 <=
			 i__3 ? i__3 : s_rnge(&__global_state->f2c, "power", 
			i__3, "timout_", (ftnlen)1684)];
		__state->frac = brcktd_(__global_state, &__state->intmed, &
			__state->c_b274, &__state->c_b275);
		__state->value = d_int(&__global_state->f2c, &__state->value) 
			+ __state->frac;
		dpfmt_(__global_state, &__state->value, __state->fmt, 
			__state->substr, (ftnlen)32, (ftnlen)256);
		s_copy(&__global_state->f2c, __state->string + (
			__state->appnd - 1), __state->substr, 256 - (
			__state->appnd - 1), (ftnlen)256);
		__state->appnd += __state->width;
		__state->have[22] = FALSE_;
		__state->making = FALSE_;
	    }
	}

/*        If the token isn't recognized we can just */
/*        append it to the string we are constructing and */
/*        adjust the point at which the next substring is */
/*        to be appended. */

	if (__state->type__ == 2) {
	    i__2 = __state->beg[(i__3 = __state->i__ - 1) < 100 && 0 <= i__3 ?
		     i__3 : s_rnge(&__global_state->f2c, "beg", i__3, "timou"
		    "t_", (ftnlen)1711)] - 1;
	    s_copy(&__global_state->f2c, __state->string + (__state->appnd - 
		    1), __state->mystr + i__2, 256 - (__state->appnd - 1), 
		    __state->end[(i__4 = __state->i__ - 1) < 100 && 0 <= i__4 
		    ? i__4 : s_rnge(&__global_state->f2c, "end", i__4, "timo"
		    "ut_", (ftnlen)1711)] - i__2);
	    __state->appnd = __state->appnd - __state->beg[(i__2 = 
		    __state->i__ - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "beg", i__2, "timout_", (ftnlen)1712)
		    ] + __state->end[(i__3 = __state->i__ - 1) < 100 && 0 <= 
		    i__3 ? i__3 : s_rnge(&__global_state->f2c, "end", i__3, 
		    "timout_", (ftnlen)1712)] + 1;

/*        If the token is a place holder, we either just append it */
/*        or tack it on to a format string we are creating.. */

	} else if (__state->type__ == 24) {
	    if (__state->making) {
		__state->b = __state->width + 1;
		__state->e = __state->b - __state->beg[(i__2 = __state->i__ - 
			1) < 100 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "beg", i__2, "timout_", (ftnlen)
			1723)] + __state->end[(i__3 = __state->i__ - 1) < 100 
			&& 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
			"end", i__3, "timout_", (ftnlen)1723)];
		i__2 = __state->beg[(i__3 = __state->i__ - 1) < 100 && 0 <= 
			i__3 ? i__3 : s_rnge(&__global_state->f2c, "beg", 
			i__3, "timout_", (ftnlen)1724)] - 1;
		s_copy(&__global_state->f2c, __state->fmt + (__state->b - 1), 
			__state->mystr + i__2, __state->e - (__state->b - 1), 
			__state->end[(i__4 = __state->i__ - 1) < 100 && 0 <= 
			i__4 ? i__4 : s_rnge(&__global_state->f2c, "end", 
			i__4, "timout_", (ftnlen)1724)] - i__2);
		__state->width = __state->width - __state->beg[(i__2 = 
			__state->i__ - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "beg", i__2, "timout_", (ftnlen)
			1725)] + __state->end[(i__3 = __state->i__ - 1) < 100 
			&& 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
			"end", i__3, "timout_", (ftnlen)1725)] + 1;
	    } else {
		i__2 = __state->beg[(i__3 = __state->i__ - 1) < 100 && 0 <= 
			i__3 ? i__3 : s_rnge(&__global_state->f2c, "beg", 
			i__3, "timout_", (ftnlen)1727)] - 1;
		s_copy(&__global_state->f2c, __state->string + (
			__state->appnd - 1), __state->mystr + i__2, (ftnlen)1,
			 __state->end[(i__4 = __state->i__ - 1) < 100 && 0 <= 
			i__4 ? i__4 : s_rnge(&__global_state->f2c, "end", 
			i__4, "timout_", (ftnlen)1727)] - i__2);
		__state->appnd = __state->appnd - __state->beg[(i__2 = 
			__state->i__ - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "beg", i__2, "timout_", (ftnlen)
			1728)] + __state->end[(i__3 = __state->i__ - 1) < 100 
			&& 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
			"end", i__3, "timout_", (ftnlen)1728)] + 1;
	    }

/*        If the token is the decimal point plus place holder */
/*        AND we are making a format, we append it to the current */
/*        format and determine the fractional part of the current */
/*        quantity. */

	} else if (__state->type__ == 23) {
	    if (! __state->making) {
		__state->b = __state->appnd;
		__state->e = __state->appnd - __state->beg[(i__2 = 
			__state->i__ - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "beg", i__2, "timout_", (ftnlen)
			1742)] + __state->end[(i__3 = __state->i__ - 1) < 100 
			&& 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
			"end", i__3, "timout_", (ftnlen)1742)];
		i__2 = __state->beg[(i__3 = __state->i__ - 1) < 100 && 0 <= 
			i__3 ? i__3 : s_rnge(&__global_state->f2c, "beg", 
			i__3, "timout_", (ftnlen)1743)] - 1;
		s_copy(&__global_state->f2c, __state->string + (__state->b - 
			1), __state->mystr + i__2, __state->e - (__state->b - 
			1), __state->end[(i__4 = __state->i__ - 1) < 100 && 0 
			<= i__4 ? i__4 : s_rnge(&__global_state->f2c, "end", 
			i__4, "timout_", (ftnlen)1743)] - i__2);
		__state->appnd = __state->e + 1;
		__state->have[22] = FALSE_;
	    } else if (__state->timfmt == 2) {
		__state->b = __state->width + 1;
		__state->e = __state->b - __state->beg[(i__2 = __state->i__ - 
			1) < 100 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "beg", i__2, "timout_", (ftnlen)
			1750)] + __state->end[(i__3 = __state->i__ - 1) < 100 
			&& 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
			"end", i__3, "timout_", (ftnlen)1750)];
		i__2 = __state->beg[(i__3 = __state->i__ - 1) < 100 && 0 <= 
			i__3 ? i__3 : s_rnge(&__global_state->f2c, "beg", 
			i__3, "timout_", (ftnlen)1751)] - 1;
		s_copy(&__global_state->f2c, __state->fmt + (__state->b - 1), 
			__state->mystr + i__2, __state->e - (__state->b - 1), 
			__state->end[(i__4 = __state->i__ - 1) < 100 && 0 <= 
			i__4 ? i__4 : s_rnge(&__global_state->f2c, "end", 
			i__4, "timout_", (ftnlen)1751)] - i__2);
		__state->width = __state->e;
		__state->have[22] = TRUE_;
	    } else {
		__state->b = __state->width + 1;
		__state->e = __state->b - __state->beg[(i__2 = __state->i__ - 
			1) < 100 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "beg", i__2, "timout_", (ftnlen)
			1758)] + __state->end[(i__3 = __state->i__ - 1) < 100 
			&& 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
			"end", i__3, "timout_", (ftnlen)1758)];
		i__2 = __state->beg[(i__3 = __state->i__ - 1) < 100 && 0 <= 
			i__3 ? i__3 : s_rnge(&__global_state->f2c, "beg", 
			i__3, "timout_", (ftnlen)1759)] - 1;
		s_copy(&__global_state->f2c, __state->fmt + (__state->b - 1), 
			__state->mystr + i__2, __state->e - (__state->b - 1), 
			__state->end[(i__4 = __state->i__ - 1) < 100 && 0 <= 
			i__4 ? i__4 : s_rnge(&__global_state->f2c, "end", 
			i__4, "timout_", (ftnlen)1759)] - i__2);
		__state->width = __state->e;
		__state->have[22] = TRUE_;

/*              Since we obviously are going to be needing */
/*              the fractional part of this component we fetch it */
/*              now and add it to whatever the integer part of the */
/*              current value is.  Here's how we do this. */
/*              If we truncated the input time to this component */
/*              we'd have a value on an "integer" portion of the */
/*              time scale. */
/*              . */
/*              .               current */
/*              .               time */
/*              .               truncated    .---MYET */
/*                                   |       | */
/*                                   v       v */
/*              time scale: ---------+-------X-----------+----- */
/*                                                       ^ */
/*                                                       | */
/*              .                               truncated time */
/*              .                               plus 1 in this */
/*              .                               component */
/*              . */
/*              Add one to the truncated component to get the */
/*              next integer component.  Finally we convert these */
/*              two constructed stings to seconds so that we can */
/*              get the "fractional part" of the current component. */
/*              Fortunately, when we computed the integer value */
/*              for this component we constructed the time */
/*              vectors we need, so we don't have to go to a lot */
/*              of trouble now. */

		ttrans_(__global_state, __state->intyp, __state->bastyp, 
			__state->ptvec, (ftnlen)16, (ftnlen)16);
		ttrans_(__global_state, __state->intyp, __state->bastyp, 
			__state->ntvec, (ftnlen)16, (ftnlen)16);
/* Computing MAX */
		d__1 = 1., d__2 = __state->ntvec[0] - __state->ptvec[0];
		__state->delta = max(d__1,d__2);
		d__1 = (__state->myet - __state->ptvec[0]) / __state->delta;
		__state->frac = brcktd_(__global_state, &__state->c_b274, &
			__state->c_b275, &d__1);
		__state->value += __state->frac;
	    }
	} else {

/*        If we get to this point we have an honest time */
/*        string component to fetch.  We might already have */
/*        this guy.  If so we can just collect him from the */
/*        values buffer (although this collection is performed */
/*        after the next long IF-THEN block that gets the value */
/*        if we don't already have it). */

	    __state->making = TRUE_;
	    __state->have[22] = FALSE_;
	    s_copy(&__global_state->f2c, __state->fmt, __state->orignl + (((
		    i__2 = __state->type__ - 1) < 51 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "orignl", i__2, "timout_", (
		    ftnlen)1816)) << 5), (ftnlen)32, (ftnlen)32);
	    __state->width = __state->length[(i__2 = __state->type__ - 1) < 
		    51 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "length", i__2, "timout_", (ftnlen)1817)];
	    __state->numtyp = __state->type__;
	    if (! __state->have[(i__2 = __state->type__ - 1) < 51 && 0 <= 
		    i__2 ? i__2 : s_rnge(&__global_state->f2c, "have", i__2, 
		    "timout_", (ftnlen)1820)]) {
		__state->tvec[0] = __state->myet;

/*              Most components are handled in the next block. */

		if (__state->type__ == 3 || __state->type__ == 4 || 
			__state->type__ == 11 || __state->type__ == 47 || 
			__state->type__ == 19 || __state->type__ == 12 || 
			__state->type__ == 50 || __state->type__ == 21 || 
			__state->type__ == 49 || __state->type__ == 46 || 
			__state->type__ == 20 || __state->type__ == 22) {
		    ttrans_(__global_state, __state->bastyp, __state->ymdfmt, 
			    __state->tvec, (ftnlen)16, (ftnlen)8);

/*                 The seconds component is finished.  Regardless */
/*                 of any zone or calendar modifications, we just */
/*                 don't have to deal with this component any more. */

		    __state->values[21] = __state->tvec[5];

/*                 If we need to deal with time zones, this is */
/*                 the time to do it. */

		    if (__state->timtyp == __state->id[38]) {
			__state->tvec[3] += __state->hoff;
			__state->tvec[4] += __state->moff;
			__state->tvec[5] = 0.;
			ttrans_(__global_state, "YMDF", "YMDF", __state->tvec,
				 (ftnlen)4, (ftnlen)4);
		    }

/*                 One way or the other the hours and minutes components */
/*                 are finished.  Record their values. */

		    __state->values[20] = __state->tvec[3];
		    __state->values[19] = __state->tvec[4];
		    if (__state->values[20] == 0.) {
			__state->values[45] = 12.;
		    } else if (__state->values[20] > 12.) {
			__state->values[45] = __state->values[20] - 12.;
		    } else {
			__state->values[45] = __state->values[20];
		    }

/*                 Finally, if we need to change the calendar to */
/*                 Julian this is the place to handle it. */

		    __state->jyear = i_dnnt(&__global_state->f2c, 
			    __state->tvec);
		    __state->jmonth = i_dnnt(&__global_state->f2c, &
			    __state->tvec[1]);
		    __state->jday = i_dnnt(&__global_state->f2c, &
			    __state->tvec[2]);
		    gr2jul_(__global_state, &__state->jyear, &__state->jmonth,
			     &__state->jday, &__state->jdoy);
		    __state->gyear = __state->jyear;
		    __state->gmonth = __state->jmonth;
		    __state->gday = __state->jday;
		    jul2gr_(__global_state, &__state->gyear, &__state->gmonth,
			     &__state->gday, &__state->gdoy);
		    if (__state->caltyp == __state->id[41]) {
			__state->values[2] = (doublereal) __state->gyear;
			__state->values[10] = (doublereal) __state->gmonth;
			__state->values[18] = (doublereal) __state->gday;
			__state->values[11] = (doublereal) __state->gdoy;
			__state->go2jul = FALSE_;
		    } else if (__state->caltyp == __state->id[40]) {
			__state->values[2] = (doublereal) __state->jyear;
			__state->values[10] = (doublereal) __state->jmonth;
			__state->values[18] = (doublereal) __state->jday;
			__state->values[11] = (doublereal) __state->jdoy;
			__state->go2jul = TRUE_;
		    } else if (__state->caltyp == __state->id[42]) {
			if (__state->gyear < 1582) {
			    __state->go2jul = TRUE_;
			} else if (__state->gyear > 1582) {
			    __state->go2jul = FALSE_;
			} else if (__state->gmonth < 10) {
			    __state->go2jul = TRUE_;
			} else if (__state->gmonth > 10) {
			    __state->go2jul = FALSE_;
			} else if (__state->gday >= 15) {
			    __state->go2jul = FALSE_;
			} else {
			    __state->go2jul = TRUE_;
			}
			if (__state->go2jul) {
			    __state->values[2] = (doublereal) __state->jyear;
			    __state->values[10] = (doublereal) 
				    __state->jmonth;
			    __state->values[18] = (doublereal) __state->jday;
			    __state->values[11] = (doublereal) __state->jdoy;
			} else {
			    __state->values[2] = (doublereal) __state->gyear;
			    __state->values[10] = (doublereal) 
				    __state->gmonth;
			    __state->values[18] = (doublereal) __state->gday;
			    __state->values[11] = (doublereal) __state->gdoy;
			}
		    }

/*                 Determine the era associated with the epoch.  Also */
/*                 if the year component is negative, we handle  that */
/*                 now. */

/*                 We store the actual value of the year so that */
/*                 it can be used when determining rounding of */
/*                 other components. */

		    __state->values[50] = __state->values[2];
		    if (__state->doera) {
			if (__state->values[2] < 1.) {
			    __state->values[2] = 1. - __state->values[2];
			    __state->values[48] = 1.;
			} else {
			    __state->values[48] = 2.;
			}
			__state->vanish = __state->values[2] >= 1e3;
		    }

/*                 Fetch the last two digits of the year. */

		    rmaind_(__global_state, &__state->values[2], &
			    __state->c_b338, &__state->x, &__state->tempd);
		    __state->values[3] = __state->tempd;
		    __state->have[2] = TRUE_;
		    __state->have[3] = TRUE_;
		    __state->have[11] = TRUE_;
		    __state->have[10] = TRUE_;
		    __state->have[46] = TRUE_;
		    __state->have[18] = TRUE_;
		    __state->have[20] = TRUE_;
		    __state->have[19] = TRUE_;
		    __state->have[21] = TRUE_;
		    __state->have[45] = TRUE_;
		    __state->have[48] = TRUE_;
		} else if (__state->type__ == 48) {
		    __state->tvec[0] = __state->myet;
		    ttrans_(__global_state, __state->bastyp, __state->ywfmt, 
			    __state->tvec, (ftnlen)16, (ftnlen)8);

/*                 If we need to deal with time zones, this is */
/*                 the time to do it. */

		    if (__state->timtyp == __state->id[38]) {
			__state->tvec[4] += __state->hoff;
			__state->tvec[5] += __state->moff;
			__state->tvec[6] = 0.;
			ttrans_(__global_state, "YMWDF", "YMWDF", 
				__state->tvec, (ftnlen)5, (ftnlen)5);
		    }
		    __state->values[47] = __state->tvec[3];
		    __state->have[47] = TRUE_;
		} else if (__state->type__ == 30 || __state->type__ == 29) {

/*                 The only way to get here is if the output time */
/*                 type is UTC or a time zone (otherwise we'd */
/*                 already HAVE SP2000 and SP1950). */

		    __state->tvec[0] = __state->myet;
		    ttrans_(__global_state, __state->bastyp, "FORMAL", 
			    __state->tvec, (ftnlen)16, (ftnlen)6);
		    __state->values[28] = __state->tvec[0];
		    __state->values[29] = __state->values[28] + spd_(
			    __global_state) * (j2000_(__global_state) - 
			    j1950_(__global_state));
		    __state->have[28] = TRUE_;
		    __state->have[29] = TRUE_;
		} else if (__state->type__ == 25) {

/*                 The same tale can be told here as in the last */
/*                 case.  We can only get here if this is UTC */
/*                 output. */

		    __state->tvec[0] = __state->myet;
		    ttrans_(__global_state, __state->bastyp, "JDUTC", 
			    __state->tvec, (ftnlen)16, (ftnlen)5);
		    __state->values[24] = __state->tvec[0];
		    __state->have[24] = TRUE_;
		}
	    }

/*           O.K. whatever thing we are about to construct, we now */
/*           have it's numeric value.  It's time to construct its */
/*           string  value. */


/*           We need to treat character months, weekdays, eras, a.m.'s */
/*           and p.m.'s specially. */

	    if (__state->type__ == 47) {
		__state->indx = i_dnnt(&__global_state->f2c, &__state->values[
			10]);
		s_copy(&__global_state->f2c, __state->mymon, __state->months 
			+ ((i__2 = __state->indx - 1) < 12 && 0 <= i__2 ? 
			i__2 : s_rnge(&__global_state->f2c, "months", i__2, 
			"timout_", (ftnlen)2060)) * 9, (ftnlen)9, (ftnlen)9);
		__state->montyp = __state->ident[(i__2 = __state->i__ - 1) < 
			100 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c,
			 "ident", i__2, "timout_", (ftnlen)2061)];

/*              There is no ELSE case in the block below because all of */
/*              the possible MONTYP values are checked explicitly. */

		if (__state->montyp == __state->id[4]) {
		    ucase_(__global_state, __state->mymon, __state->mymon, (
			    ftnlen)9, (ftnlen)9);
		    s_copy(&__global_state->f2c, __state->mymon + 3, " ", (
			    ftnlen)6, (ftnlen)1);
		    __state->mylen = 3;
		} else if (__state->montyp == __state->id[5]) {
		    s_copy(&__global_state->f2c, __state->mymon + 3, " ", (
			    ftnlen)6, (ftnlen)1);
		    __state->mylen = 3;
		} else if (__state->montyp == __state->id[6]) {
		    lcase_(__global_state, __state->mymon, __state->mymon, (
			    ftnlen)9, (ftnlen)9);
		    s_copy(&__global_state->f2c, __state->mymon + 3, " ", (
			    ftnlen)6, (ftnlen)1);
		    __state->mylen = 3;
		} else if (__state->montyp == __state->id[8]) {
		    __state->mylen = __state->mlen[(i__2 = __state->indx - 1) 
			    < 12 && 0 <= i__2 ? i__2 : s_rnge(&
			    __global_state->f2c, "mlen", i__2, "timout_", (
			    ftnlen)2079)];
		} else if (__state->montyp == __state->id[7]) {
		    ucase_(__global_state, __state->mymon, __state->mymon, (
			    ftnlen)9, (ftnlen)9);
		    __state->mylen = __state->mlen[(i__2 = __state->indx - 1) 
			    < 12 && 0 <= i__2 ? i__2 : s_rnge(&
			    __global_state->f2c, "mlen", i__2, "timout_", (
			    ftnlen)2082)];
		} else if (__state->montyp == __state->id[9]) {
		    lcase_(__global_state, __state->mymon, __state->mymon, (
			    ftnlen)9, (ftnlen)9);
		    __state->mylen = __state->mlen[(i__2 = __state->indx - 1) 
			    < 12 && 0 <= i__2 ? i__2 : s_rnge(&
			    __global_state->f2c, "mlen", i__2, "timout_", (
			    ftnlen)2085)];
		}
		s_copy(&__global_state->f2c, __state->string + (
			__state->appnd - 1), __state->mymon, 256 - (
			__state->appnd - 1), (ftnlen)9);
		__state->appnd += __state->mylen;
		__state->making = FALSE_;
	    } else if (__state->type__ == 48) {
		__state->indx = i_dnnt(&__global_state->f2c, &__state->values[
			47]);
		s_copy(&__global_state->f2c, __state->mywkd, __state->wkdays 
			+ ((i__2 = __state->indx - 1) < 7 && 0 <= i__2 ? i__2 
			: s_rnge(&__global_state->f2c, "wkdays", i__2, "timo"
			"ut_", (ftnlen)2095)) * 9, (ftnlen)9, (ftnlen)9);
		__state->wktyp = __state->ident[(i__2 = __state->i__ - 1) < 
			100 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c,
			 "ident", i__2, "timout_", (ftnlen)2096)];

/*              There is no ELSE case in the block below because all of */
/*              the possible WKTYP values are checked explicitly. */

		if (__state->wktyp == __state->id[12]) {
		    ucase_(__global_state, __state->mywkd, __state->mywkd, (
			    ftnlen)9, (ftnlen)9);
		    s_copy(&__global_state->f2c, __state->mywkd + 3, " ", (
			    ftnlen)6, (ftnlen)1);
		    __state->mylen = 3;
		} else if (__state->wktyp == __state->id[13]) {
		    s_copy(&__global_state->f2c, __state->mywkd + 3, " ", (
			    ftnlen)6, (ftnlen)1);
		    __state->mylen = 3;
		} else if (__state->wktyp == __state->id[14]) {
		    lcase_(__global_state, __state->mywkd, __state->mywkd, (
			    ftnlen)9, (ftnlen)9);
		    s_copy(&__global_state->f2c, __state->mywkd + 3, " ", (
			    ftnlen)6, (ftnlen)1);
		    __state->mylen = 3;
		} else if (__state->wktyp == __state->id[16]) {
		    __state->mylen = __state->wklen[(i__2 = __state->indx - 1)
			     < 7 && 0 <= i__2 ? i__2 : s_rnge(&
			    __global_state->f2c, "wklen", i__2, "timout_", (
			    ftnlen)2114)];
		} else if (__state->wktyp == __state->id[15]) {
		    ucase_(__global_state, __state->mywkd, __state->mywkd, (
			    ftnlen)9, (ftnlen)9);
		    __state->mylen = __state->wklen[(i__2 = __state->indx - 1)
			     < 7 && 0 <= i__2 ? i__2 : s_rnge(&
			    __global_state->f2c, "wklen", i__2, "timout_", (
			    ftnlen)2117)];
		} else if (__state->wktyp == __state->id[17]) {
		    lcase_(__global_state, __state->mywkd, __state->mywkd, (
			    ftnlen)9, (ftnlen)9);
		    __state->mylen = __state->wklen[(i__2 = __state->indx - 1)
			     < 7 && 0 <= i__2 ? i__2 : s_rnge(&
			    __global_state->f2c, "wklen", i__2, "timout_", (
			    ftnlen)2120)];
		}
		s_copy(&__global_state->f2c, __state->string + (
			__state->appnd - 1), __state->mywkd, 256 - (
			__state->appnd - 1), (ftnlen)9);
		__state->appnd += __state->mylen;
		__state->making = FALSE_;
	    } else if (__state->type__ == 49) {
		if (__state->values[48] == 2. && (__state->ident[(i__2 = 
			__state->i__ - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "ident", i__2, "timout_", (
			ftnlen)2130)] == __state->id[32] || __state->ident[(
			i__3 = __state->i__ - 1) < 100 && 0 <= i__3 ? i__3 : 
			s_rnge(&__global_state->f2c, "ident", i__3, "timout_",
			 (ftnlen)2130)] == __state->id[34])) {
		    s_copy(&__global_state->f2c, __state->string + (
			    __state->appnd - 1), " A.D.", 256 - (
			    __state->appnd - 1), (ftnlen)5);
		} else if (__state->values[48] == 2. && (__state->ident[(i__2 
			= __state->i__ - 1) < 100 && 0 <= i__2 ? i__2 : 
			s_rnge(&__global_state->f2c, "ident", i__2, "timout_",
			 (ftnlen)2136)] == __state->id[33] || __state->ident[(
			i__3 = __state->i__ - 1) < 100 && 0 <= i__3 ? i__3 : 
			s_rnge(&__global_state->f2c, "ident", i__3, "timout_",
			 (ftnlen)2136)] == __state->id[35])) {
		    s_copy(&__global_state->f2c, __state->string + (
			    __state->appnd - 1), " a.d.", 256 - (
			    __state->appnd - 1), (ftnlen)5);
		} else if (__state->values[48] == 1. && (__state->ident[(i__2 
			= __state->i__ - 1) < 100 && 0 <= i__2 ? i__2 : 
			s_rnge(&__global_state->f2c, "ident", i__2, "timout_",
			 (ftnlen)2141)] == __state->id[32] || __state->ident[(
			i__3 = __state->i__ - 1) < 100 && 0 <= i__3 ? i__3 : 
			s_rnge(&__global_state->f2c, "ident", i__3, "timout_",
			 (ftnlen)2141)] == __state->id[34])) {
		    s_copy(&__global_state->f2c, __state->string + (
			    __state->appnd - 1), " B.C.", 256 - (
			    __state->appnd - 1), (ftnlen)5);
		} else {
		    s_copy(&__global_state->f2c, __state->string + (
			    __state->appnd - 1), " b.c.", 256 - (
			    __state->appnd - 1), (ftnlen)5);
		}

/*              If we have the vanishing kind of era, and we've */
/*              determined that it needs to vanish, then blank out the */
/*              portion of the string we just filled in. and don't */
/*              increment the place holder. */

		if (__state->ident[(i__2 = __state->i__ - 1) < 100 && 0 <= 
			i__2 ? i__2 : s_rnge(&__global_state->f2c, "ident", 
			i__2, "timout_", (ftnlen)2158)] == __state->id[34] || 
			__state->ident[(i__3 = __state->i__ - 1) < 100 && 0 <=
			 i__3 ? i__3 : s_rnge(&__global_state->f2c, "ident", 
			i__3, "timout_", (ftnlen)2158)] == __state->id[35]) {
		    if (__state->vanish) {
			s_copy(&__global_state->f2c, __state->string + (
				__state->appnd - 1), " ", 256 - (
				__state->appnd - 1), (ftnlen)1);
			++__state->appnd;
		    } else {
			__state->appnd += 6;
		    }
		} else {
		    ljust_(__global_state, __state->string + (__state->appnd 
			    - 1), __state->string + (__state->appnd - 1), 256 
			    - (__state->appnd - 1), 256 - (__state->appnd - 1)
			    );
		    __state->appnd += 4;
		}
		__state->making = FALSE_;
	    } else if (__state->type__ == 50) {
		if (__state->ident[(i__2 = __state->i__ - 1) < 100 && 0 <= 
			i__2 ? i__2 : s_rnge(&__global_state->f2c, "ident", 
			i__2, "timout_", (ftnlen)2178)] == __state->id[36] && 
			__state->values[20] >= 12.) {
		    s_copy(&__global_state->f2c, __state->string + (
			    __state->appnd - 1), "P.M.", 256 - (
			    __state->appnd - 1), (ftnlen)4);
		} else if (__state->ident[(i__2 = __state->i__ - 1) < 100 && 
			0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "ide"
			"nt", i__2, "timout_", (ftnlen)2183)] == __state->id[
			36] && __state->values[20] < 12.) {
		    s_copy(&__global_state->f2c, __state->string + (
			    __state->appnd - 1), "A.M.", 256 - (
			    __state->appnd - 1), (ftnlen)4);
		} else if (__state->ident[(i__2 = __state->i__ - 1) < 100 && 
			0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "ide"
			"nt", i__2, "timout_", (ftnlen)2188)] == __state->id[
			37] && __state->values[20] >= 12.) {
		    s_copy(&__global_state->f2c, __state->string + (
			    __state->appnd - 1), "p.m.", 256 - (
			    __state->appnd - 1), (ftnlen)4);
		} else {
		    s_copy(&__global_state->f2c, __state->string + (
			    __state->appnd - 1), "a.m.", 256 - (
			    __state->appnd - 1), (ftnlen)4);
		}
		__state->appnd += 4;
		__state->making = FALSE_;
	    } else {
		__state->value = __state->values[(i__2 = __state->type__ - 1) 
			< 51 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "values", i__2, "timout_", (
			ftnlen)2204)];
	    }

/*           If we are now creating a format string, we should */
/*           construct the previous time representation and */
/*           the next for this component (just in case we need it */
/*           later). */

	    if (__state->making) {

/*              We store the value of our current type in the */
/*              CURRNT slot of the values array.  This value */
/*              is used by the single numeric types, JD, SP2000, */
/*              and SP1950. */

		__state->values[0] = __state->values[(i__2 = __state->type__ 
			- 1) < 51 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "values", i__2, "timout_", (
			ftnlen)2222)];

/*              Here's how this works:  We will copy all of */
/*              the components of the time representation up to */
/*              the current one.  This is the truncated representation */
/*              of our epoch.  We then copy these same components into */
/*              another time vector, but add an increment to the */
/*              component corresponding to the one we are dealing with */
/*              now.  We use an increment of 0 for those components that */
/*              already contain their fractional part. We use an */
/*              increment of 1 for the components that typically have */
/*              integer representations. */


/*              Zero out the previous and next time vectors so we won't */
/*              have to do it when we are filling in the truncated */
/*              portions. */

		for (__state->j = 1; __state->j <= 7; ++__state->j) {
		    __state->ptvec[(i__2 = __state->j - 1) < 8 && 0 <= i__2 ? 
			    i__2 : s_rnge(&__global_state->f2c, "ptvec", i__2,
			     "timout_", (ftnlen)2242)] = 0.;
		    __state->ntvec[(i__2 = __state->j - 1) < 8 && 0 <= i__2 ? 
			    i__2 : s_rnge(&__global_state->f2c, "ntvec", i__2,
			     "timout_", (ftnlen)2243)] = 0.;
		}
		if (__state->type__ == 3 || __state->type__ == 4) {
		    __state->stopat = 1;
		    __state->timfmt = 1;
		    s_copy(&__global_state->f2c, __state->intyp, 
			    __state->ymdfmt, (ftnlen)16, (ftnlen)8);
		    __state->incr = 1.;
		} else if (__state->type__ == 11) {
		    __state->stopat = 2;
		    __state->timfmt = 1;
		    s_copy(&__global_state->f2c, __state->intyp, 
			    __state->ymdfmt, (ftnlen)16, (ftnlen)8);
		    __state->incr = 1.;
		} else if (__state->type__ == 19 || __state->type__ == 12) {
		    __state->stopat = 3;
		    __state->timfmt = 1;
		    s_copy(&__global_state->f2c, __state->intyp, 
			    __state->ymdfmt, (ftnlen)16, (ftnlen)8);
		    __state->incr = 1.;
		} else if (__state->type__ == 21 || __state->type__ == 46) {

/*                 Note that in this case (and the next 2) that if we */
/*                 an HOUR component, we had to get it either from */
/*                 a Day of Year format or from a Year Month Day */
/*                 format. Thus we have all of the more significant */
/*                 components for this format. */

		    __state->stopat = 4;
		    __state->timfmt = 1;
		    s_copy(&__global_state->f2c, __state->intyp, 
			    __state->ymdfmt, (ftnlen)16, (ftnlen)8);
		    __state->incr = 1.;
		} else if (__state->type__ == 20) {
		    __state->stopat = 5;
		    __state->timfmt = 1;
		    s_copy(&__global_state->f2c, __state->intyp, 
			    __state->ymdfmt, (ftnlen)16, (ftnlen)8);
		    __state->incr = 1.;
		} else if (__state->type__ == 22) {
		    __state->stopat = 6;
		    __state->timfmt = 1;
		    s_copy(&__global_state->f2c, __state->intyp, 
			    __state->ymdfmt, (ftnlen)16, (ftnlen)8);
		    __state->incr = 0.;
		} else if (__state->type__ == 25) {
		    __state->stopat = 1;
		    __state->timfmt = 2;
		    __state->incr = 0.;
		    if (__state->timtyp == __state->id[27]) {
			s_copy(&__global_state->f2c, __state->intyp, "JDTDT", 
				(ftnlen)16, (ftnlen)5);
		    } else if (__state->timtyp == __state->id[26]) {
			s_copy(&__global_state->f2c, __state->intyp, "JDTDB", 
				(ftnlen)16, (ftnlen)5);
		    } else if (__state->timtyp == __state->id[25] || 
			    __state->timtyp == __state->id[38]) {
			s_copy(&__global_state->f2c, __state->intyp, "JDUTC", 
				(ftnlen)16, (ftnlen)5);
		    }
		} else {

/*                 The only types left are the continuous (numeric) */
/*                 types. */

		    __state->stopat = 1;
		    __state->timfmt = 2;
		    __state->incr = 0.;
		    s_copy(&__global_state->f2c, __state->intyp, 
			    __state->bastyp, (ftnlen)16, (ftnlen)16);
		}

/*              Ok.  We are now ready to construct the previous */
/*              and next time vectors. */

		i__2 = __state->stopat;
		for (__state->j = 1; __state->j <= i__2; ++__state->j) {
		    __state->ptvec[(i__3 = __state->j - 1) < 8 && 0 <= i__3 ? 
			    i__3 : s_rnge(&__global_state->f2c, "ptvec", i__3,
			     "timout_", (ftnlen)2333)] = __state->values[(
			    i__5 = __state->compnt[(i__4 = __state->j + (
			    __state->timfmt << 3) - 9) < 16 && 0 <= i__4 ? 
			    i__4 : s_rnge(&__global_state->f2c, "compnt", 
			    i__4, "timout_", (ftnlen)2333)] - 1) < 51 && 0 <= 
			    i__5 ? i__5 : s_rnge(&__global_state->f2c, "valu"
			    "es", i__5, "timout_", (ftnlen)2333)];
		    __state->ntvec[(i__3 = __state->j - 1) < 8 && 0 <= i__3 ? 
			    i__3 : s_rnge(&__global_state->f2c, "ntvec", i__3,
			     "timout_", (ftnlen)2334)] = __state->ptvec[(i__4 
			    = __state->j - 1) < 8 && 0 <= i__4 ? i__4 : 
			    s_rnge(&__global_state->f2c, "ptvec", i__4, "tim"
			    "out_", (ftnlen)2334)];
		}
		__state->ntvec[(i__2 = __state->stopat - 1) < 8 && 0 <= i__2 ?
			 i__2 : s_rnge(&__global_state->f2c, "ntvec", i__2, 
			"timout_", (ftnlen)2337)] = __state->ntvec[(i__3 = 
			__state->stopat - 1) < 8 && 0 <= i__3 ? i__3 : s_rnge(
			&__global_state->f2c, "ntvec", i__3, "timout_", (
			ftnlen)2337)] + __state->incr;

/*              If the type is a year or month, then we need to set */
/*              the month to 1, so that we will be working with */
/*              beginnings of years not beginning of last months of */
/*              the previous year. */

		if (__state->type__ == 3 || __state->type__ == 4) {
		    __state->ptvec[1] = 1.;
		    __state->ntvec[1] = 1.;
		    __state->ptvec[2] = 1.;
		    __state->ntvec[2] = 1.;
		} else if (__state->type__ == 11) {
		    __state->ptvec[2] = 1.;
		    __state->ntvec[2] = 1.;
		}
		if (__state->go2jul && __state->timfmt != 2) {

/*                 Convert both PTVEC and NTVEC to the gregorian */
/*                 calendar */

		    __state->jyear = i_dnnt(&__global_state->f2c, 
			    __state->ptvec);
		    __state->jmonth = i_dnnt(&__global_state->f2c, &
			    __state->ptvec[1]);
		    __state->jday = i_dnnt(&__global_state->f2c, &
			    __state->ptvec[2]);
		    jul2gr_(__global_state, &__state->jyear, &__state->jmonth,
			     &__state->jday, &__state->jdoy);
		    __state->ptvec[0] = (doublereal) __state->jyear;
		    __state->ptvec[1] = (doublereal) __state->jmonth;
		    __state->ptvec[2] = (doublereal) __state->jday;
		    __state->jyear = i_dnnt(&__global_state->f2c, 
			    __state->ntvec);
		    __state->jmonth = i_dnnt(&__global_state->f2c, &
			    __state->ntvec[1]);
		    __state->jday = i_dnnt(&__global_state->f2c, &
			    __state->ntvec[2]);
		    jul2gr_(__global_state, &__state->jyear, &__state->jmonth,
			     &__state->jday, &__state->jdoy);
		    __state->ntvec[0] = (doublereal) __state->jyear;
		    __state->ntvec[1] = (doublereal) __state->jmonth;
		    __state->ntvec[2] = (doublereal) __state->jday;
		}
		if (__state->dozone && __state->timfmt != 2) {
		    __state->ptvec[3] -= __state->hoff;
		    __state->ntvec[3] = __state->ntvec[4] - __state->hoff;
		    __state->ptvec[4] -= __state->moff;
		    __state->ntvec[4] -= __state->moff;
		    __state->ptvec[5] = 0.;
		    __state->ntvec[5] = 0.;
		    ttrans_(__global_state, "YMDF", "YMDF", __state->ptvec, (
			    ftnlen)4, (ftnlen)4);
		    ttrans_(__global_state, "YMDF", "YMDF", __state->ntvec, (
			    ftnlen)4, (ftnlen)4);
		    if (__state->type__ == 22) {
			__state->ptvec[5] = __state->values[21];
			__state->ntvec[5] = __state->values[21];
		    }
		}
	    }
	}
    }

/*     All that's left to do is to copy the constructed string */
/*     to the output string. */

    s_copy(&__global_state->f2c, output, __state->string, output_len, (ftnlen)
	    256);
    chkout_(__global_state, "TIMOUT", (ftnlen)6);
    return 0;
} /* timout_ */

