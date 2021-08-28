/* str2et.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern str2et_init_t __str2et_init;
static inline str2et_state_t* get_str2et_state(cspice_t* state) {
	if (!state->str2et)
		state->str2et = __cspice_allocate_module(sizeof(
	str2et_state_t), &__str2et_init, sizeof(__str2et_init));
	return state->str2et;

}

/* $Procedure      STR2ET ( String to ET ) */
/* Subroutine */ int str2et_(cspice_t* __global_state, char *string, 
	doublereal *et, ftnlen string_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6;

    /* Builtin functions */
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer), i_dnnt(
	    f2c_state_t*, doublereal *);
    double d_int(f2c_state_t*, doublereal *);

    /* Local variables */
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int repmc_(cspice_t*, char *, char *, char *, 
	    char *, ftnlen, ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int moved_(cspice_t*, doublereal *, integer *, 
	    doublereal *);
    extern /* Subroutine */ int dpfmt_(cspice_t*, doublereal *, char *, char *
	    , ftnlen, ftnlen);
    extern /* Subroutine */ int repmi_(cspice_t*, char *, char *, integer *, 
	    char *, ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int jul2gr_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    extern /* Subroutine */ int gr2jul_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    extern /* Subroutine */ int tchckd_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int tcheck_(cspice_t*, doublereal *, char *, 
	    logical *, char *, logical *, char *, ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int timdef_(cspice_t*, char *, char *, char *, 
	    ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int tparch_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int prefix_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int ttrans_(cspice_t*, char *, char *, doublereal 
	    *, ftnlen, ftnlen);
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int tpartv_(cspice_t*, char *, doublereal *, 
	    integer *, char *, char *, logical *, logical *, logical *, char *
	    , char *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int texpyr_(cspice_t*, integer *);
    extern /* Subroutine */ int zzutcpm_(cspice_t*, char *, integer *, 
	    doublereal *, doublereal *, integer *, logical *, ftnlen);


    /* Module state */
    str2et_state_t* __state = get_str2et_state(__global_state);
/* $ Abstract */

/*     Convert a string representing an epoch to a double precision */
/*     value representing the number of TDB seconds past the J2000 */
/*     epoch corresponding to the input epoch. */

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

/*      TIME */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     STRING     I   A string representing an epoch. */
/*     ET         O   The equivalent value in seconds past J2000, TDB. */

/* $ Detailed_Input */

/*     STRING     is a string representing an epoch.  Virtually all */
/*                common calendar representations are allowed. You may */
/*                specify a time string belonging to any of the */
/*                systems TDB, TDT, UTC.  Moreover, you may specify a */
/*                time string relative to a specific UTC based time */
/*                zone. */

/*                The rules used in the parsing of STRING are spelled */
/*                out in great detail in the routine TPARTV. The basics */
/*                are given in the Particulars section below. */

/* $ Detailed_Output */

/*     ET         is the double precision number of TDB seconds past the */
/*                J2000 epoch that corresponds to the input STRING. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */


/*     1) The error SPICE(UNPARSEDTIME) is signaled if the */
/*        string cannot be recognized as a legitimate time string. */

/*     2) The error SPICE(TIMECONFLICT) is signaled if more than */
/*        one time system is specified as part of the time string. */

/*     3) The error SPICE(BADTIMESTRING) is signaled if any component */
/*        of the time string is outside the normal range of usage. For */
/*        example, the day January 35 is outside the normal range of days */
/*        in January. The checks applied are spelled out in the routine */
/*        TCHECK. */

/*     4) If a time zone is specified with hours or minutes components */
/*        that are outside of the normal range, the error */
/*        SPICE(TIMEZONEERROR) will be signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*      This routine computes the ephemeris epoch corresponding to an */
/*      input string.  The ephemeris epoch is represented as seconds */
/*      past the J2000 epoch in the time system known as Barycentric */
/*      Dynamical Time (TDB).  This time system is also referred to as */
/*      Ephemeris Time (ET) throughout the SPICE Toolkit. */

/*      The variety of ways people have developed for representing */
/*      times is enormous. It is unlikely that any single subroutine */
/*      can accommodate the wide variety of custom time formats that */
/*      have arisen in various computing contexts. However, we */
/*      believe that this routine will correctly interpret most time */
/*      formats used throughout the planetary science community. */
/*      For example this routine supports ISO time formats and UNIX */
/*      `date` output formats. One obvious omission from the strings */
/*      recognized by this routine are strings of the form */

/*           93234.1829  or 1993234.1829 */

/*      Some readers may recognize this as the epoch that is 0.1829 */
/*      days past the beginning of the 234'th day of 1993.  However, */
/*      many other readers may regard this interpretation as a bit */
/*      obscure. */

/*      Below we outline some of the rules used in the interpretation */
/*      of strings.  A more complete discussion of the interpretation */
/*      of strings is given in the routine TPARTV. */


/*      Default Behavior */
/*      ---------------- */

/*      Consider the string */

/*           1988 June 13, 3:29:48 */

/*      There is nothing in this string to indicate what time system */
/*      the date and time belong to.  Moreover, there is nothing to */
/*      indicate whether the time is based on a 24-hour clock or */
/*      twelve hour clock. */

/*      In the absence of such indicators, the default interpretation */
/*      of this string is to regard the time of day to be a time on */
/*      a 24-hour clock in the UTC time system.  The date is a date */
/*      on the Gregorian Calendar (this is the calendar used in nearly */
/*      all western societies). */

/*      Labels */
/*      ------ */

/*      If you add more information to the string, STR2ET can make a */
/*      more informed interpretation of the time string. For example: */

/*           1988 June 13, 3:29:48 P.M. */

/*      is still regarded as a UTC epoch.  However, with the addition */
/*      of the 'P.M.' label it is now interpreted as the same epoch */
/*      as the unlabeled epoch 1988 June 13, 15:29:48.   Similarly */

/*           1988 June 13, 12:29:48 A.M. */

/*      is interpreted as */

/*            1988 June 13, 00:29:48 */

/*      For the record: 12:00 A.M. corresponds to Midnight (00:00 on the */
/*      24 hour clock.  12:00 P.M. corresponds to Noon. (12:00) on the */
/*      24 hour clock. */

/*      You may add still further indicators to the string.  For example */

/*          1988 June 13, 3:29:48 P.M. PST */

/*      is interpreted as an epoch in the Pacific Standard Time system. */
/*      This is equivalent to */

/*          1988 June 13, 07:29:48 UTC */

/*      The following U.S. time zones are recognized. */

/*         EST   --- Eastern Standard Time  ( UTC-5:00 ) */
/*         CST   --- Central Standard Time  ( UTC-6:00 ) */
/*         MST   --- Mountain Standard Time ( UTC-7:00 ) */
/*         PST   --- Pacific Standard Time  ( UTC-8:00 ) */

/*         EDT   --- Eastern Daylight Time  ( UTC-4:00 ) */
/*         CDT   --- Central Daylight Time  ( UTC-5:00 ) */
/*         MDT   --- Mountain Daylight Time ( UTC-6:00 ) */
/*         PDT   --- Pacific Daylight Time  ( UTC-7:00 ) */

/*      In addition any other time zone may be specified by representing */
/*      its offset from UTC. This notation starts with the letters 'UTC' */
/*      followed by a '+' for time zones east of Greenwich and '-' for */
/*      time zones west of Greenwich.  This is followed by the number of */
/*      hours to add or subtract from UTC.  This is optionally followed */
/*      by a colon ':' and the number of minutes to add or subtract to */
/*      get the local time zone.  Thus to specify the time zone of */
/*      Calcutta (which is 5 and 1/2 hours ahead of UTC) you would */
/*      specify the time zone to be UTC+5:30.  To specify the time zone */
/*      of Newfoundland (which is 3 and 1/2 hours behind UTC) use the */
/*      offset notation UTC-3:30. */

/*      For the Record:  Leapseconds occur at the same time in all */
/*      time zones.  In other words, the seconds component of a time */
/*      string is the same for any time zone as is the seconds */
/*      component of UTC.  Thus the following are all legitimate */
/*      ways to represent an epoch of some event that occurred */
/*      in the leapsecond */

/*           1995 December 31 23:59:60.5  (UTC) */


/*           1996 January   1, 05:29:60.5  (UTC+5:30 --- Calcutta Time) */
/*           1995 December 31, 20:29:60.5  (UTC-3:30 --- Newfoundland) */
/*           1995 December 31  18:59:60.5  (EST) */
/*           1995 December 31  17:59:60.5  (CST) */
/*           1995 December 31  16:59:60.5  (MST) */
/*           1995 December 31  15:59:60.5  (PST) */


/*      In addition to specifying time zones, you may specify that the */
/*      string be interpreted as a formal  calendar representation in */
/*      either the Barycentric Dynamical Time system (TDB) or the */
/*      Terrestrial Dynamical Time system (TDT).  In These systems there */
/*      are no leapseconds.  Times in TDB are written as */

/*        1988 June 13, 12:29:48 TDB */

/*      TDT times are written as: */

/*        1988 June 13, 12:29:48 TDT */

/*     Finally, you may explicitly state that the time system is UTC */

/*        1988 June 13, 12:29:48 UTC. */


/*      Abbreviating Years */
/*      ------------------ */

/*      Although it can lead to confusion, many people are in the */
/*      habit of abbreviating years when they write them in dates. */
/*      For example */

/*         99 Jan 13,  12:28:24 */

/*      Upon seeing such a string, most of us would regard this */
/*      as being 1999 January 13, 12:28:24 and not January 13 of */
/*      the year 99.  This routine interprets years that are less */
/*      than 100 as belonging either to the 1900's or 2000's.  Years */
/*      greater than 68 ( 69 - 99 ) are regarded as being an */
/*      abbreviation with the '19' suppressed (1969 - 1999).  Years */
/*      smaller than 69 ( 00 - 68 ) are regarded as being an */
/*      abbreviation with the '20' suppressed (2000 - 2068). */

/*      Note that in general it is usually a good idea to write */
/*      out the year.  Or if you'd like to save some typing */
/*      abbreviate 1999 as '99. */

/*      If you need to specify an epoch whose year */
/*      is less than 1000, we recommend that you specify the era */
/*      along with the year.  For example if you want to specify */
/*      the year 13 A.D. write it as */

/*        13 A.D. Jan 12 */

/*      When specifying the era it should immediately follow the year. */
/*      Both the A.D. and B.C. eras are supported. */


/*      Changing Default Behavior */
/*      ------------------------- */

/*      As discussed above, if a string is unlabeled, it is regarded */
/*      as representing a string in the UTC time system on the */
/*      Gregorian calendar.  In addition abbreviated years are */
/*      regarded as abbreviations of the years from 1969 to 2068. */

/*      You may modify these defaults through the routines TIMDEF */
/*      and TSETYR (an entry point of TEXPYR). */

/*      You may: */

/*        Set the calendar to be Gregorian, Julian or a mixture of */
/*        two via the TIMDEF; */

/*        Set the time system to be UTC, TDB, TDT or any time zone */
/*        via the routine TIMDEF; */

/*        Set the range of year abbreviations to be any 100 year */
/*        interval via the routine TSETYR. */

/*     See the routine TEXPYR and TIMDEF for details on changing */
/*     defaults. */

/*     These alterations affect only the interpretation of unlabeled */
/*     strings.  If an input string is labeled the specification */
/*     in the label is used. */


/*     If any component of a date or time is out of range, STR2ET */
/*     regards the string as erroneous.  Below is a list of */
/*     erroneous strings and why they are regarded as such. */

/*        1997 Jan 32 12:29:29     --- there are only 31 days in January */

/*        '98 Jan 12 13:29:29 A.M. --- Hours must be between 1 and 12 */
/*                                     inclusive when A.M. or P.M. is */
/*                                     specified. */

/*        1997 Feb 29, 12:29:20.0  --- February has only 29 days in */
/*                                     1997. This would be ok if the */
/*                                     year was 1996. */


/*        1992 Mar 12 12:62:20     --- Minutes must be between 0 and 59 */
/*                                     inclusive. */

/*        1993 Mar 18 15:29:60.5   --- Seconds is out of range for this */
/*                                     date.  It would not be out of */
/*                                     range for Dec 31 23:59:60.5 or */
/*                                     Jun 30 23:59:60.5 because these */
/*                                     can be leapseconds (UTC). */

/*     Specifics On Interpretation of the Input String */
/*     ----------------------------------------------- */

/*     The process of examining the string to determine its meaning is */
/*     called "parsing" the string. The string is parsed by first */
/*     determining its recognizable substrings (integers, punctuation */
/*     marks, names of months, names of weekdays, time systems, time */
/*     zones, etc.)  These recognizable substrings are called the tokens */
/*     of the input string.  The meaning of some tokens are immediately */
/*     determined. For example named months, weekdays, time systems have */
/*     clear meanings.  However, the meanings of numeric components must */
/*     be deciphered from their magnitudes and location in the string */
/*     relative to the immediately recognized components of the input */
/*     string. */

/*     To determine the meaning of the numeric tokens in the input */
/*     string, a set of "production rules" and transformations are */
/*     applied to the full set of tokens in the string.  These */
/*     transformations are repeated until the meaning of every token */
/*     has been determined, or until further transformations yield */
/*     no new clues into the meaning of the numeric tokens. */

/*     1)  Unless the substring 'JD' or 'jd' is present, the string is */
/*         assumed to be a calendar format (day-month-year or year and */
/*         day of year).  If the substring JD or jd is present, the */
/*         string is assumed to represent a Julian date. */

/*     2)  If the Julian date specifier is not present, any integer */
/*         greater than 999 is regarded as being a year specification. */

/*     3)  A dash '-' can represent a minus sign only if it precedes */
/*         the first digit in the string and the string contains */
/*         the Julian date specifier (JD).  (No negative years, */
/*         months, days, etc are allowed). */

/*     4)  Numeric components of a time string must be separated */
/*         by a character that is not a digit or decimal point. */
/*         Only one decimal component is allowed.  For example */
/*         1994219.12819 is sometimes interpreted as the */
/*         219th day of 1994 + 0.12819 days.  STR2ET does not */
/*         support such strings. */

/*         No exponential components are allowed.  For example you */
/*         can't specify the Julian date of J2000 as 2.451545E6. */

/*     5)  The single colon (:) when used to separate numeric */
/*         components of a string is interpreted as separating */
/*         Hours, Minutes, and Seconds of time. */

/*     6)  If a double slash (//) or double colon (::) follows */
/*         a pair of integers, those integers are assumed  to */
/*         represent the year and day of year. */

/*     7)  A quote followed by an integer less than 100 is regarded */
/*         as an abbreviated year.  For example: '93 would be regarded */
/*         as the 93rd year of the reference century.  See TEXPYR */
/*         for further discussion of abbreviated years. */

/*      8) An integer followed by 'B.C.' or 'A.D.' is regarded as */
/*         a year in the era associated with that abbreviation. */

/*      9) All dates are regarded as belonging to the extended */
/*         Gregorian Calendar (the Gregorian calendar is the calendar */
/*         currently used by western society).  See the routine TIMDEF */
/*         to modify this behavior. */

/*     10) If the ISO date-time separator (T) is present in the string */
/*         ISO allowed token patterns are examined for a match */
/*         with the current token list.  If no match is found the */
/*         search is abandoned and appropriate diagnostic messages */
/*         are generated. */

/*     11) If two delimiters are found in succession in the time */
/*         string, the time string is diagnosed as an erroneous string. */
/*         (Delimiters are comma, white space, dash, slash, period, or */
/*         of year mark.  The day of year mark is a pair of forward */
/*         slashes or a pair of colons.) */

/*         Note the delimiters do not have to be the same. The pair */
/*         of characters ",-" counts as two successive delimiters. */

/*     12) White space and commas serve only to delimit tokens in the */
/*         input string.  They do not affect the meaning of any */
/*         of the tokens. */

/*     13) If an integer is greater than 1000 (and the 'JD' label */
/*         is not present, the integer is regarded as a year. */

/*     14) When the size of the integer components does not clearly */
/*         specify a year the following patterns are assumed */

/*         Calendar Format */

/*             Year Month Day */
/*             Month Day Year */
/*             Year Day Month */

/*             where Month is the name of a month, not its numeric */
/*             value. */

/*             When integer components are separated by slashes (/) */
/*             as in 3/4/5.  Month, Day, Year is assumed (2005 March 4) */

/*          Day of Year Format. */

/*             If a day of year marker (// or ::) is present, the */
/*             pattern I-I// or I-I:: (where I stands for an integer) */
/*             is interpreted as Year Day-of-Year. However, I-I/ is */
/*             regarded as ambiguous. */


/* $ Examples */

/*      Below is a sampling of some of the time formats that are */
/*      acceptable as inputs to STR2ET.  A complete discussion of */
/*      permissible formats is given in the SPICE routine TPARTV as well */
/*      as the reference document time.req located in the "doc" */
/*      directory of the Toolkit. */

/*      ISO (T) Formats. */

/*      String                        Year Mon  DOY DOM  HR Min Sec */
/*      ----------------------------  ---- ---  --- ---  -- --- ------ */
/*      1996-12-18T12:28:28           1996 Dec   na  18  12  28 28 */
/*      1986-01-18T12                 1986 Jan   na  18  12  00 00 */
/*      1986-01-18T12:19              1986 Jan   na  18  12  19 00 */
/*      1986-01-18T12:19:52.18        1986 Jan   na  18  12  19 52.18 */
/*      1995-08T18:28:12              1995  na  008  na  18  28 12 */
/*      1995-18T                      1995  na  018  na  00  00 00 */


/*      Calendar Formats. */

/*      String                        Year   Mon DOM  HR Min  Sec */
/*      ----------------------------  ----   --- ---  -- ---  ------ */
/*      Tue Aug  6 11:10:57  1996     1996   Aug  06  11  10  57 */
/*      1 DEC 1997 12:28:29.192       1997   Dec  01  12  28  29.192 */
/*      2/3/1996 17:18:12.002         1996   Feb  03  17  18  12.002 */
/*      Mar 2 12:18:17.287 1993       1993   Mar  02  12  18  17.287 */
/*      1992 11:18:28  3 Jul          1992   Jul  03  11  18  28 */
/*      June 12, 1989 01:21           1989   Jun  12  01  21  00 */
/*      1978/3/12 23:28:59.29         1978   Mar  12  23  28  59.29 */
/*      17JUN1982 18:28:28            1982   Jun  17  18  28  28 */
/*      13:28:28.128 1992 27 Jun      1992   Jun  27  13  28  28.128 */
/*      1972 27 jun 12:29             1972   Jun  27  12  29  00 */
/*      '93 Jan 23 12:29:47.289       1993*  Jan  23  12  29  47.289 */
/*      27 Jan 3, 19:12:28.182        2027*  Jan  03  19  12  28.182 */
/*      23 A.D. APR 4, 18:28:29.29    0023** Apr  04  18  28  29.29 */
/*      18 B.C. Jun 3, 12:29:28.291   -017** Jun  03  12  29  28.291 */
/*      29 Jun  30 12:29:29.298       2029+  Jun  30  12  29  29.298 */
/*      29 Jun '30 12:29:29.298       2030*  Jun  29  12  29  29.298 */

/*      Day of Year Formats */

/*      String                        Year  DOY HR Min Sec */
/*      ----------------------------  ----  --- -- --- ------ */
/*      1997-162::12:18:28.827        1997  162 12  18 28.827 */
/*      162-1996/12:28:28.287         1996  162 12  28 28.287 */
/*      1993-321/12:28:28.287         1993  231 12  28 28.287 */
/*      1992 183// 12 18 19           1992  183 12  18 19 */
/*      17:28:01.287 1992-272//       1992  272 17  28 01.287 */
/*      17:28:01.282 272-1994//       1994  272 17  28 01.282 */
/*      '92-271/ 12:28:30.291         1992* 271 12  28 30.291 */
/*      92-182/ 18:28:28.281          1992* 182 18  28 28.281 */
/*      182-92/ 12:29:29.192          0182+ 092 12  29 29.192 */
/*      182-'92/ 12:28:29.182         1992  182 12  28 29.182 */


/*      Julian Date Strings */

/*      jd 28272.291                  Julian Date   28272.291 */
/*      2451515.2981 (JD)             Julian Date 2451515.2981 */
/*      2451515.2981 JD               Julian Date 2451515.2981 */

/*                                   Abbreviations Used in Tables */

/*                                      na    --- Not Applicable */
/*                                      Mon   --- Month */
/*                                      DOY   --- Day of Year */
/*                                      DOM   --- Day of Month */
/*                                      Wkday --- Weekday */
/*                                      Hr    --- Hour */
/*                                      Min   --- Minutes */
/*                                      Sec   --- Seconds */

/*      * The default interpretation of a year that has been abbreviated */
/*      with a leading quote as in 'xy (such as '92) is to treat the */
/*      year as 19xy if xy > 68 and to treat it is 20xy otherwise. Thus */
/*      '69 is interpreted as 1969 and '68 is treated as 2068. However, */
/*      you may change the "split point" and centuries through use of */
/*      the SPICE routine TSETYR which is an entry point in the SPICE */
/*      module TEXPYR.  See that routine for a discussion of how you may */
/*      reset the split point. */

/*      ** All epochs are regarded as belonging to the Gregorian */
/*      calendar.  We formally extend the Gregorian calendar backward */
/*      and forward in time for all epochs. */

/*      +  When a day of year format or calendar format string is input */
/*         and neither of the integer components of the date is greater */
/*         than 1000, the first integer is regarded as being the year. */


/*      Suppose you would like to determine whether your favorite */
/*      time representation is supported by STR2ET.  The small */
/*      program below gives you a simple way to experiment with */
/*      STR2ET.  (Note that erroneous inputs will be flagged by */
/*      signaling an error.) */

/*      To run this program you need to: */

/*      1.  copy it to a file, */
/*      2.  un-comment the obvious lines of code, */
/*      3.  compile it, */
/*      4.  link the resulting object file with SPICELIB, */
/*      5.  and place the leapseconds kernel in your current directory. */

/*      PROGRAM */

/*      CHARACTER*(64)        STRING */
/*      CHARACTER*(64)        CALDR */
/*      CHARACTER*(64)        DAYOFY */
/*      CHARACTER*(127)       FILNAM */

/*      DOUBLE PRECISION      ET */


/*      First get the name of a leapseconds kernel, and load it. */

/*      CALL PROMPT ( 'Leapseconds kernel: ', FILNAM ) */
/*      CALL FURNSH ( FILNAM ) */

/*      Leave some space on the screen and get the first trial string. */
/*      If we get a blank input, we quit. */

/*      WRITE (*,*) */
/*      CALL PROMPT ( 'String to try: ', STRING ) */

/*      DO WHILE ( STRING .NE. ' ' ) */

/*         Convert the string to ET and then back to UTC calendar */
/*         and day-of-year formats. */

/*         CALL STR2ET ( STRING, ET ) */
/*         CALL ET2UTC ( ET, 'C', 0, CALDR  ) */
/*         CALL ET2UTC ( ET, 'D', 0, DAYOFY ) */

/*         Print the results. */

/*         WRITE (*,*) 'Calendar    Format: ', CALDR */
/*         WRITE (*,*) 'Day of year Format: ', DAYOFY */

/*         Ask for another string and do it all again. */

/*         WRITE (*,*) */
/*         CALL PROMPT ( 'String to try: ', STRING ) */

/*      END DO */
/*      END */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     C.H. Acton         (JPL) */
/*     N.J. Bachman       (JPL) */
/*     W.L. Taber         (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.3.1, 02-NOV-2009 (CHA) */

/*        A few minor grammar errors were fixed in the header. */
/*        The header sections were reordered. */

/* -    SPICELIB Version 1.3.0, 31-AUG-2006 (NJB) (EDW) */

/*        Bug fix:  routine formerly returned incorrect results */
/*        in some cases on calls following calls for which a time */
/*        zone was specified. */

/*        Replaced reference to LDPOOL in header Examples section */
/*        with reference to FURNSH. */

/* -    SPICELIB Version 1.2.2, 29-JUL-2003 (NJB) */

/*        Various minor header corrections were made */

/* -    SPICELIB Version 1.2.1, 10-FEB-2003 (NJB) */

/*        Corrected header typo. */

/* -    SPICELIB Version 1.2.0, 11-NOV-1997 (WLT) */

/*        The previous versions of this routine did not correctly */
/*        convert day-of-year strings in the TDB or TDT systems. */
/*        They treated the day of year as year, month, day giving */
/*        spectacularly wrong answers. */

/*        In addition, comments concerning the default century for */
/*        abbreviated years were updated to reflect changes to TEXPYR */

/* -    SPICELIB Version 1.1.0, 10-FEB-1997 (WLT) */

/*        In the case that a time zone could not be parsed, */
/*        this routine signaled an error and checked out without */
/*        then returning.  This error has been corrected. */

/* -    SPICELIB Version 1.0.0, 15-NOV-1996 (WLT) */


/* -& */
/* $ Index_Entries */

/*     Convert a string to TDB seconds past the J2000 epoch */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.3.0, 31-AUG-2006 (NJB) */

/*        Bug fix:  routine formerly returned incorrect results */
/*        in some cases on calls following calls for which a time */
/*        zone was specified. */

/*        The problem was caused by the variable ZONED not being */
/*        properly set when a time system was specified */
/*        in the input string.  In such cases, ZONED retained the */
/*        value from the previous call. */

/* -& */

/*     SPICELIB Functions. */


/*     Local (in-line) Functions */


/*     The following integers are pointers to the */
/*     locations of various components in a time vector. */


/*     Saved variables */


/*     Initial values */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "STR2ET", (ftnlen)6);

/*     Collect the current defaults. */

    timdef_(__global_state, "GET", "SYSTEM", __state->defsys, (ftnlen)3, (
	    ftnlen)6, (ftnlen)16);
    timdef_(__global_state, "GET", "ZONE", __state->defzon, (ftnlen)3, (
	    ftnlen)4, (ftnlen)16);
    timdef_(__global_state, "GET", "CALENDAR", __state->calndr, (ftnlen)3, (
	    ftnlen)8, (ftnlen)16);
    if (s_cmp(&__global_state->f2c, __state->defzon, " ", (ftnlen)16, (ftnlen)
	    1) != 0) {
	prefix_(__global_state, "::", &__state->c__0, __state->defzon, (
		ftnlen)2, (ftnlen)16);
	zzutcpm_(__global_state, __state->defzon, &__state->c__1, &
		__state->dhoff, &__state->dmoff, &__state->last, &
		__state->succes, (ftnlen)16);
    } else {
	__state->dhoff = 0.;
	__state->dmoff = 0.;
    }

/*     See if TPARTV can recognize what the user has supplied. */

    tpartv_(__global_state, string, __state->tvec, &__state->ntvec, 
	    __state->type__, __state->modify, &__state->mods, &
	    __state->yabbrv, &__state->succes, __state->pictur, 
	    __state->error, string_len, (ftnlen)16, (ftnlen)16, (ftnlen)80, (
	    ftnlen)400);
    if (! __state->succes) {
	setmsg_(__global_state, __state->error, (ftnlen)400);
	sigerr_(__global_state, "SPICE(UNPARSEDTIME)", (ftnlen)19);
	chkout_(__global_state, "STR2ET", (ftnlen)6);
	return 0;
    }

/*     A system and time zone are incompatible components in a */
/*     time string. */

    if (s_cmp(&__global_state->f2c, __state->modify + 32, " ", (ftnlen)16, (
	    ftnlen)1) != 0 && s_cmp(&__global_state->f2c, __state->modify + 
	    64, " ", (ftnlen)16, (ftnlen)1) != 0) {
	setmsg_(__global_state, "Both a time system and time zone have been "
		"specified in the input string (# and #). These are inconsist"
		"ent. A time zone is a fixed offset from UTC. ", (ftnlen)148);
	errch_(__global_state, "#", __state->modify + 64, (ftnlen)1, (ftnlen)
		16);
	errch_(__global_state, "#", __state->modify + 32, (ftnlen)1, (ftnlen)
		16);
	sigerr_(__global_state, "SPICE(TIMECONFLICT)", (ftnlen)19);
	chkout_(__global_state, "STR2ET", (ftnlen)6);
	return 0;
    }

/*     If both the zone and system are empty, we can replace them */
/*     with the default zone and system values (only one of which */
/*     can be non-blank). */

    __state->zoned = FALSE_;
    if (s_cmp(&__global_state->f2c, __state->modify + 32, " ", (ftnlen)16, (
	    ftnlen)1) == 0 && s_cmp(&__global_state->f2c, __state->modify + 
	    64, " ", (ftnlen)16, (ftnlen)1) == 0) {
	s_copy(&__global_state->f2c, __state->modify + 32, __state->defzon, (
		ftnlen)16, (ftnlen)16);
	s_copy(&__global_state->f2c, __state->modify + 64, __state->defsys, (
		ftnlen)16, (ftnlen)16);
	__state->hoff = __state->dhoff;
	__state->moff = __state->dmoff;
	__state->zoned = s_cmp(&__global_state->f2c, __state->modify + 32, 
		" ", (ftnlen)16, (ftnlen)1) != 0;
    } else if (s_cmp(&__global_state->f2c, __state->modify + 32, " ", (ftnlen)
	    16, (ftnlen)1) != 0) {

/*        Parse the time zone specification.  If we don't succeed */
/*        in the parsing, signal an error. */

	__state->zoned = TRUE_;
	prefix_(__global_state, "::", &__state->c__0, __state->modify + 32, (
		ftnlen)2, (ftnlen)16);
	zzutcpm_(__global_state, __state->modify + 32, &__state->c__1, &
		__state->hoff, &__state->moff, &__state->last, &
		__state->succes, (ftnlen)16);
	if (! __state->succes) {
	    setmsg_(__global_state, "# is not a legitimate time zone specifi"
		    "cation. ", (ftnlen)47);
	    errch_(__global_state, "#", __state->modify + 34, (ftnlen)1, (
		    ftnlen)14);
	    sigerr_(__global_state, "SPICE(TIMEZONEERROR)", (ftnlen)20);
	    chkout_(__global_state, "STR2ET", (ftnlen)6);
	    return 0;
	}
    }

/*     We handle the julian date case now.  It doesn't have the */
/*     complications associated with it that the calendar strings */
/*     have. */

    if (s_cmp(&__global_state->f2c, __state->type__, "JD", (ftnlen)16, (
	    ftnlen)2) == 0) {
	if (s_cmp(&__global_state->f2c, __state->modify + 64, "UTC", (ftnlen)
		16, (ftnlen)3) == 0) {
	    s_copy(&__global_state->f2c, __state->type__, "JDUTC", (ftnlen)16,
		     (ftnlen)5);
	} else if (s_cmp(&__global_state->f2c, __state->modify + 64, "TDB", (
		ftnlen)16, (ftnlen)3) == 0) {
	    s_copy(&__global_state->f2c, __state->type__, "JDTDB", (ftnlen)16,
		     (ftnlen)5);
	} else if (s_cmp(&__global_state->f2c, __state->modify + 64, "TDT", (
		ftnlen)16, (ftnlen)3) == 0) {
	    s_copy(&__global_state->f2c, __state->type__, "JDTDT", (ftnlen)16,
		     (ftnlen)5);
	} else {
	    s_copy(&__global_state->f2c, __state->type__, "JDUTC", (ftnlen)16,
		     (ftnlen)5);
	}
	ttrans_(__global_state, __state->type__, "TDB", __state->tvec, (
		ftnlen)16, (ftnlen)3);
	*et = __state->tvec[0];
	chkout_(__global_state, "STR2ET", (ftnlen)6);
	return 0;
    }

/*     Set the indexes of the hours, minutes, seconds, etc. components */
/*     of the time vector. */

    if (s_cmp(&__global_state->f2c, __state->type__, "YD", (ftnlen)16, (
	    ftnlen)2) == 0) {
	__state->yr = 1;
	__state->dy = 2;
	__state->hr = 3;
	__state->mn = 4;
	__state->sc = 5;
	s_copy(&__global_state->f2c, __state->forml, "YDF", (ftnlen)16, (
		ftnlen)3);
    } else {
	__state->yr = 1;
	__state->mm = 2;
	__state->dy = 3;
	__state->hr = 4;
	__state->mn = 5;
	__state->sc = 6;
	s_copy(&__global_state->f2c, __state->forml, "YMDF", (ftnlen)16, (
		ftnlen)4);
    }

/*     Check the components for reasonableness. */

    tchckd_(__global_state, __state->check, (ftnlen)16);
    tparch_(__global_state, "YES", (ftnlen)3);

/*     If the calendar is NOT gregorian, or if we have a time zone */
/*     present, we avoid the problem of checking for legitimate */
/*     leapseconds (at least we avoid this problem for the moment). */

    __state->adjust = FALSE_;
    if (__state->zoned || s_cmp(&__global_state->f2c, __state->calndr, 
	    __state->gregrn, (ftnlen)16, (ftnlen)16) != 0) {
	if (__state->tvec[(i__1 = __state->sc - 1) < 8 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (ftnlen)
		949)] >= 60. && __state->tvec[(i__2 = __state->sc - 1) < 8 && 
		0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "tvec", i__2, 
		"str2et_", (ftnlen)949)] < 61.) {
	    __state->adjust = TRUE_;
	    __state->tvec[(i__1 = __state->sc - 1) < 8 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (
		    ftnlen)953)] = __state->tvec[(i__2 = __state->sc - 1) < 8 
		    && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "tvec",
		     i__2, "str2et_", (ftnlen)953)] - 1.;
	}
    }
    if (s_cmp(&__global_state->f2c, __state->calndr, __state->mixed, (ftnlen)
	    16, (ftnlen)16) == 0) {

/*        This is a bit awkward, but here's what's going on. */
/*        If the input calendar is part of the Julian calendar */
/*        it might be Feb 29 on a century such as 1500.  These */
/*        are not legitimate dates on the Gregorian calendar. */
/*        But they are ok on the Julian calendar. */

/*        However, one of the year numbers YEAR or YEAR + 4 will */
/*        be a leap year on both the Julian and Gregorian calendar. */
/*        If we have just a century problem, it will be a problem */
/*        for only one of the years.  So in the range where we could */
/*        have a problem we call TCHECK twice and .OR. the results */
/*        of the checks to see if we have a legitimate time vector. */

	if (__state->tvec[(i__1 = __state->yr - 1) < 8 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (ftnlen)
		976)] < 1580.) {
	    moved_(__global_state, __state->tvec, &__state->c__6, 
		    __state->tvecm);
	    __state->tvecm[0] += 4.;
	    tcheck_(__global_state, __state->tvecm, __state->type__, &
		    __state->mods, __state->modify, &__state->ok1, 
		    __state->error, (ftnlen)16, (ftnlen)16, (ftnlen)400);
	    tcheck_(__global_state, __state->tvec, __state->type__, &
		    __state->mods, __state->modify, &__state->ok2, 
		    __state->error, (ftnlen)16, (ftnlen)16, (ftnlen)400);
	    __state->ok = __state->ok1 || __state->ok2;
	} else {
	    tcheck_(__global_state, __state->tvec, __state->type__, &
		    __state->mods, __state->modify, &__state->ok, 
		    __state->error, (ftnlen)16, (ftnlen)16, (ftnlen)400);
	}
    } else if (s_cmp(&__global_state->f2c, __state->calndr, __state->juln, (
	    ftnlen)16, (ftnlen)16) == 0) {

/*        Basically, this is the same story as before, but there */
/*        are no bounds in the years where we might be on a century. */
/*        So we just check twice for each time vector. */

	moved_(__global_state, __state->tvec, &__state->c__6, __state->tvecm);
	__state->tvecm[0] += 4.;
	tcheck_(__global_state, __state->tvecm, __state->type__, &
		__state->mods, __state->modify, &__state->ok1, __state->error,
		 (ftnlen)16, (ftnlen)16, (ftnlen)400);
	tcheck_(__global_state, __state->tvec, __state->type__, &
		__state->mods, __state->modify, &__state->ok2, __state->error,
		 (ftnlen)16, (ftnlen)16, (ftnlen)400);
	__state->ok = __state->ok1 || __state->ok2;
    } else {

/*        TCHECK was designed for the Gregorian Calendar,  So we */
/*        don't have much to do. */

	tcheck_(__global_state, __state->tvec, __state->type__, &
		__state->mods, __state->modify, &__state->ok, __state->error, 
		(ftnlen)16, (ftnlen)16, (ftnlen)400);
    }

/*     Reset the checking status. */

    tparch_(__global_state, __state->check, (ftnlen)16);

/*     If we didn't get an OK from the inspection above, */
/*     say so and signal an error. */

    if (! __state->ok) {
	setmsg_(__global_state, __state->error, (ftnlen)400);
	sigerr_(__global_state, "SPICE(BADTIMESTRING)", (ftnlen)20);
	chkout_(__global_state, "STR2ET", (ftnlen)6);
	return 0;
    }

/*     Reset TVEC(SC) if it was adjusted earlier. */

    if (__state->adjust) {
	__state->tvec[(i__1 = __state->sc - 1) < 8 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (ftnlen)
		1037)] = __state->tvec[(i__2 = __state->sc - 1) < 8 && 0 <= 
		i__2 ? i__2 : s_rnge(&__global_state->f2c, "tvec", i__2, 
		"str2et_", (ftnlen)1037)] + 1.;
    }

/*     There are no leapseconds in the TDT and TDB time systems */
/*     This means that the seconds component must be less than 60. */

    if (s_cmp(&__global_state->f2c, __state->modify + 64, "TDT", (ftnlen)16, (
	    ftnlen)3) == 0 || s_cmp(&__global_state->f2c, __state->modify + 
	    64, "TDB", (ftnlen)16, (ftnlen)3) == 0) {
	if (__state->tvec[(i__1 = __state->sc - 1) < 8 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (ftnlen)
		1047)] >= 60.) {
	    setmsg_(__global_state, "The seconds component of time must be l"
		    "ess than 60 for any calendar representation of #. ", (
		    ftnlen)89);
	    errch_(__global_state, "#", __state->modify + 64, (ftnlen)1, (
		    ftnlen)16);
	    sigerr_(__global_state, "SPICE(BADTIMESTRING)", (ftnlen)20);
	    chkout_(__global_state, "STR2ET", (ftnlen)6);
	    return 0;
	}
    }

/*     If a B.C. era  marker is present we can't have a year abbreviation */

    if (s_cmp(&__global_state->f2c, __state->modify, "B.C.", (ftnlen)16, (
	    ftnlen)4) == 0 && __state->yabbrv) {
	setmsg_(__global_state, "The Year may be abbreviated only if the yea"
		"r belongs to the Christian Era (A.D.) ", (ftnlen)81);
	sigerr_(__global_state, "SPICE(BADTIMESTRING)", (ftnlen)20);
	chkout_(__global_state, "STR2ET", (ftnlen)6);
	return 0;
    }

/*     If the era is B.C. we need to reset the year. */

    if (s_cmp(&__global_state->f2c, __state->modify, "B.C.", (ftnlen)16, (
	    ftnlen)4) == 0) {
	__state->tvec[(i__1 = __state->yr - 1) < 8 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (ftnlen)
		1078)] = 1. - __state->tvec[(i__2 = __state->yr - 1) < 8 && 0 
		<= i__2 ? i__2 : s_rnge(&__global_state->f2c, "tvec", i__2, 
		"str2et_", (ftnlen)1078)];
    }

/*     If there is a A.M. or P.M. time string modifier, we need to adjust */
/*     the hours component of the time. */

    if (s_cmp(&__global_state->f2c, __state->modify + 48, "P.M.", (ftnlen)16, 
	    (ftnlen)4) == 0) {
	if (__state->tvec[(i__1 = __state->hr - 1) < 8 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (ftnlen)
		1087)] < 12.) {
	    __state->tvec[(i__1 = __state->hr - 1) < 8 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (
		    ftnlen)1088)] = __state->tvec[(i__2 = __state->hr - 1) < 
		    8 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "tvec", i__2, "str2et_", (ftnlen)1088)] + 12.;
	}
    } else if (s_cmp(&__global_state->f2c, __state->modify + 48, "A.M.", (
	    ftnlen)16, (ftnlen)4) == 0) {
	if (__state->tvec[(i__1 = __state->hr - 1) < 8 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (ftnlen)
		1093)] >= 12.) {
	    __state->tvec[(i__1 = __state->hr - 1) < 8 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (
		    ftnlen)1094)] = __state->tvec[(i__2 = __state->hr - 1) < 
		    8 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "tvec", i__2, "str2et_", (ftnlen)1094)] - 12.;
	}
    }

/*     If the year has been abbreviated, we need to convert it */
/*     to the proper range.  In addition we assume a year less */
/*     than 100 that is not qualified with the B.C. or A.D. era */
/*     string is in fact an abbreviated year. */

    __state->year = i_dnnt(&__global_state->f2c, &__state->tvec[(i__1 = 
	    __state->yr - 1) < 8 && 0 <= i__1 ? i__1 : s_rnge(&
	    __global_state->f2c, "tvec", i__1, "str2et_", (ftnlen)1105)]);
    if (__state->yabbrv) {
	texpyr_(__global_state, &__state->year);
	__state->tvec[(i__1 = __state->yr - 1) < 8 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (ftnlen)
		1110)] = (doublereal) __state->year;
    } else if (__state->year < 100 && s_cmp(&__global_state->f2c, 
	    __state->modify, " ", (ftnlen)16, (ftnlen)1) == 0) {
	texpyr_(__global_state, &__state->year);
	__state->tvec[(i__1 = __state->yr - 1) < 8 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (ftnlen)
		1116)] = (doublereal) __state->year;
    }

/*     We may need to convert to the Gregorian Calendar, now is */
/*     the time to do so. */

    if (s_cmp(&__global_state->f2c, __state->calndr, __state->mixed, (ftnlen)
	    16, (ftnlen)16) == 0) {

/*        We need to check the components. */

	if (s_cmp(&__global_state->f2c, __state->type__, "YD", (ftnlen)16, (
		ftnlen)2) == 0) {
	    __state->dojul = __state->tvec[(i__1 = __state->yr - 1) < 8 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "tvec", 
		    i__1, "str2et_", (ftnlen)1131)] < 1582. || __state->tvec[(
		    i__2 = __state->yr - 1) < 8 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "tvec", i__2, "str2et_", (ftnlen)
		    1131)] == 1582. && __state->tvec[(i__3 = __state->dy - 1) 
		    < 8 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "tvec", i__3, "str2et_", (ftnlen)1131)] < 279.;
	} else {
	    __state->dojul = __state->tvec[(i__1 = __state->yr - 1) < 8 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "tvec", 
		    i__1, "str2et_", (ftnlen)1137)] < 1582. || __state->tvec[(
		    i__2 = __state->yr - 1) < 8 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "tvec", i__2, "str2et_", (ftnlen)
		    1137)] <= 1582. && __state->tvec[(i__3 = __state->mm - 1) 
		    < 8 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "tvec", i__3, "str2et_", (ftnlen)1137)] < 10. || 
		    __state->tvec[(i__4 = __state->yr - 1) < 8 && 0 <= i__4 ? 
		    i__4 : s_rnge(&__global_state->f2c, "tvec", i__4, "str2e"
		    "t_", (ftnlen)1137)] <= 1582. && __state->tvec[(i__5 = 
		    __state->mm - 1) < 8 && 0 <= i__5 ? i__5 : s_rnge(&
		    __global_state->f2c, "tvec", i__5, "str2et_", (ftnlen)
		    1137)] <= 10. && __state->tvec[(i__6 = __state->dy - 1) < 
		    8 && 0 <= i__6 ? i__6 : s_rnge(&__global_state->f2c, 
		    "tvec", i__6, "str2et_", (ftnlen)1137)] < 6.;
	}
    } else if (s_cmp(&__global_state->f2c, __state->calndr, __state->juln, (
	    ftnlen)16, (ftnlen)16) == 0) {
	__state->dojul = TRUE_;
    } else {
	__state->dojul = FALSE_;
    }

/*     If the input string is from the julian calendar, we need */
/*     to convert it to Gregorian.  We also need to save the original */
/*     year value in the unlikely event it is needed for a later */
/*     diagnostic message. */

    if (__state->dojul) {
	if (s_cmp(&__global_state->f2c, __state->type__, "YD", (ftnlen)16, (
		ftnlen)2) == 0) {
	    __state->year = (integer) d_int(&__global_state->f2c, &
		    __state->tvec[(i__1 = __state->yr - 1) < 8 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "tvec", i__1, "str2e"
		    "t_", (ftnlen)1165)]);
	    __state->month = 1;
	    __state->day = (integer) d_int(&__global_state->f2c, &
		    __state->tvec[(i__1 = __state->dy - 1) < 8 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "tvec", i__1, "str2e"
		    "t_", (ftnlen)1167)]);
	    __state->frac = __state->tvec[(i__1 = __state->dy - 1) < 8 && 0 <=
		     i__1 ? i__1 : s_rnge(&__global_state->f2c, "tvec", i__1, 
		    "str2et_", (ftnlen)1168)] - (doublereal) __state->day;
	    __state->orgnyr = __state->year;
	    jul2gr_(__global_state, &__state->year, &__state->month, &
		    __state->day, &__state->doy);
	    __state->tvec[(i__1 = __state->yr - 1) < 8 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (
		    ftnlen)1173)] = (doublereal) __state->year;
	    __state->tvec[(i__1 = __state->dy - 1) < 8 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (
		    ftnlen)1174)] = (doublereal) __state->doy + __state->frac;
	} else {
	    __state->year = (integer) d_int(&__global_state->f2c, &
		    __state->tvec[(i__1 = __state->yr - 1) < 8 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "tvec", i__1, "str2e"
		    "t_", (ftnlen)1178)]);
	    __state->month = (integer) d_int(&__global_state->f2c, &
		    __state->tvec[(i__1 = __state->mm - 1) < 8 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "tvec", i__1, "str2e"
		    "t_", (ftnlen)1179)]);
	    __state->day = (integer) d_int(&__global_state->f2c, &
		    __state->tvec[(i__1 = __state->dy - 1) < 8 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "tvec", i__1, "str2e"
		    "t_", (ftnlen)1180)]);
	    __state->frac = __state->tvec[(i__1 = __state->dy - 1) < 8 && 0 <=
		     i__1 ? i__1 : s_rnge(&__global_state->f2c, "tvec", i__1, 
		    "str2et_", (ftnlen)1181)] - (doublereal) __state->day;
	    __state->orgnyr = __state->year;
	    jul2gr_(__global_state, &__state->year, &__state->month, &
		    __state->day, &__state->doy);
	    __state->tvec[(i__1 = __state->yr - 1) < 8 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (
		    ftnlen)1186)] = (doublereal) __state->year;
	    __state->tvec[(i__1 = __state->mm - 1) < 8 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (
		    ftnlen)1187)] = (doublereal) __state->month;
	    __state->tvec[(i__1 = __state->dy - 1) < 8 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (
		    ftnlen)1188)] = (doublereal) __state->day + __state->frac;
	}
    } else {
	__state->orgnyr = (integer) d_int(&__global_state->f2c, &
		__state->tvec[(i__1 = __state->yr - 1) < 8 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (
		ftnlen)1194)]);
    }

/*     The TDT and TDB calendars don't need to worry about time */
/*     zone adjustments. */

    if (s_cmp(&__global_state->f2c, __state->modify + 64, "TDT", (ftnlen)16, (
	    ftnlen)3) == 0) {
	ttrans_(__global_state, __state->forml, "FORMAL", __state->tvec, (
		ftnlen)16, (ftnlen)6);
	ttrans_(__global_state, "TDT", "TDB", __state->tvec, (ftnlen)3, (
		ftnlen)3);
	*et = __state->tvec[0];
	chkout_(__global_state, "STR2ET", (ftnlen)6);
	return 0;
    } else if (s_cmp(&__global_state->f2c, __state->modify + 64, "TDB", (
	    ftnlen)16, (ftnlen)3) == 0) {
	ttrans_(__global_state, __state->forml, "FORMAL", __state->tvec, (
		ftnlen)16, (ftnlen)6);
	*et = __state->tvec[0];
	chkout_(__global_state, "STR2ET", (ftnlen)6);
	return 0;
    }

/*     If a time zone has been specified, we need to convert */
/*     from the time zone components to UTC components. */

    if (__state->zoned) {

/*        A time zone was specified explicitly in the input */
/*        string.  We need to compute the hour and minute offsets */
/*        associated with the time zone. */

	__state->tvec[(i__1 = __state->hr - 1) < 8 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (ftnlen)
		1230)] = __state->tvec[(i__2 = __state->hr - 1) < 8 && 0 <= 
		i__2 ? i__2 : s_rnge(&__global_state->f2c, "tvec", i__2, 
		"str2et_", (ftnlen)1230)] - __state->hoff;
	__state->tvec[(i__1 = __state->mn - 1) < 8 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (ftnlen)
		1231)] = __state->tvec[(i__2 = __state->mn - 1) < 8 && 0 <= 
		i__2 ? i__2 : s_rnge(&__global_state->f2c, "tvec", i__2, 
		"str2et_", (ftnlen)1231)] - __state->moff;
	__state->secs = __state->tvec[(i__1 = __state->sc - 1) < 8 && 0 <= 
		i__1 ? i__1 : s_rnge(&__global_state->f2c, "tvec", i__1, 
		"str2et_", (ftnlen)1232)];
	__state->tvec[(i__1 = __state->sc - 1) < 8 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (ftnlen)
		1233)] = 0.;
	ttrans_(__global_state, __state->forml, __state->forml, __state->tvec,
		 (ftnlen)16, (ftnlen)16);
	__state->tvec[(i__1 = __state->sc - 1) < 8 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "tvec", i__1, "str2et_", (ftnlen)
		1237)] = __state->secs;
    }

/*     If we decided to forgo the leapseconds check earlier */
/*     now is the time to do it.  We've now got Gregorian UTC */
/*     time components. */

    if (__state->adjust) {
	tchckd_(__global_state, __state->check, (ftnlen)16);
	tparch_(__global_state, "YES", (ftnlen)3);
	__state->mods = FALSE_;
	s_copy(&__global_state->f2c, __state->modify + 48, " ", (ftnlen)16, (
		ftnlen)1);
	tcheck_(__global_state, __state->tvec, __state->type__, &
		__state->mods, __state->modify, &__state->ok, __state->error, 
		(ftnlen)16, (ftnlen)16, (ftnlen)400);
    } else {
	__state->ok = TRUE_;
    }
    if (__state->ok) {

/*        That's it we are ready to rumble. */

	ttrans_(__global_state, __state->type__, "TDB", __state->tvec, (
		ftnlen)16, (ftnlen)3);
	*et = __state->tvec[0];
	chkout_(__global_state, "STR2ET", (ftnlen)6);
	return 0;
    }
/*     =============================================================== */
/*     If you are still here, it is because OK was .FALSE. in the test */
/*     above.  The only way this can happen is if the seconds were */
/*     not in the expected range.  The rest of the code is a diagnosis */
/*     of this problem.  (This is a nuisance case that is */
/*     unlikely to occur very often.) */

    if (__state->zoned && __state->dojul) {
	s_copy(&__global_state->f2c, __state->error, "The seconds component "
		"of '#' is out of range. On the Julian Calendar in the specif"
		"ied time zone  (#) leapseconds can occur during the year # o"
		"nly in the second that immediately follows the time #:#:59 o"
		"n  # # and # #. ", (ftnlen)400, (ftnlen)218);
	repmc_(__global_state, __state->error, "#", string, __state->error, (
		ftnlen)400, (ftnlen)1, string_len, (ftnlen)400);
	repmc_(__global_state, __state->error, "#", __state->modify + 34, 
		__state->error, (ftnlen)400, (ftnlen)1, (ftnlen)14, (ftnlen)
		400);
    } else if (__state->zoned) {

/*        If we had a time zone, we want to say what time zone */
/*        in the output string. */

	s_copy(&__global_state->f2c, __state->error, "The seconds component "
		"of '#' is out of range. In the specified time zone  (#) leap"
		"seconds can occur during the year # only in the second that "
		"immediately follows the time #:#:59 on  # # and # #.", (
		ftnlen)400, (ftnlen)194);
	repmc_(__global_state, __state->error, "#", string, __state->error, (
		ftnlen)400, (ftnlen)1, string_len, (ftnlen)400);
	repmc_(__global_state, __state->error, "#", __state->modify + 34, 
		__state->error, (ftnlen)400, (ftnlen)1, (ftnlen)14, (ftnlen)
		400);
    } else {

/*        No time zone, this case can only occur if we interpreted */
/*        the input string as a date on the Julian Calendar */

	s_copy(&__global_state->f2c, __state->error, "The seconds component "
		"of '#' is out of range. Leapseconds can occur during the yea"
		"r # of the Julian calendar only in the second that immediate"
		"ly follows the time #:#:59  on # # and # #.' ", (ftnlen)400, (
		ftnlen)187);
	repmc_(__global_state, __state->error, "#", string, __state->error, (
		ftnlen)400, (ftnlen)1, string_len, (ftnlen)400);
    }

/*     First fill in the year portion of the error message. */

    repmi_(__global_state, __state->error, "#", &__state->orgnyr, 
	    __state->error, (ftnlen)400, (ftnlen)1, (ftnlen)400);
    __state->mon[0] = 6.;
    __state->mon[1] = 12.;
    __state->mdy[0] = 30.;
    __state->mdy[1] = 31.;

/*     Next Fill in the hours and minutes. Recall that leapseconds */
/*     occur during the last second of the 59'th minute of the 23'rd */
/*     hour UTC.  So in the new time zone, it occurs in the 59'th + MOFF */
/*     minute of the 23'rd + HOFF hour of the time zone.  We adjust */
/*     these to account for hour roll over and day roll over. */

    __state->minute = __state->moff + 59.;
    if (__state->minute > 59.) {
	__state->minute += -60.;
	__state->extra = 1.;
    } else if (__state->minute < 0.) {
	__state->minute += 60.;
	__state->extra = -1.;
    } else {
	__state->extra = 0.;
    }
    __state->hour = __state->hoff + 23. + __state->extra;
    if (__state->hour > 23.) {
	__state->hour += -24;
    }

/*     Convert the hours and minutes to strings and place the */
/*     strings in the message. */

    dpfmt_(__global_state, &__state->hour, "0x", __state->hstr, (ftnlen)2, (
	    ftnlen)2);
    dpfmt_(__global_state, &__state->minute, "0x", __state->mstr, (ftnlen)2, (
	    ftnlen)2);
    repmc_(__global_state, __state->error, "#", __state->hstr, __state->error,
	     (ftnlen)400, (ftnlen)1, (ftnlen)2, (ftnlen)400);
    repmc_(__global_state, __state->error, "#", __state->mstr, __state->error,
	     (ftnlen)400, (ftnlen)1, (ftnlen)2, (ftnlen)400);

/*     Last step we generate the month and day corresponding */
/*     to Dec 31, 23:59, and Jun 30, 23:59.  We only want the */
/*     dates that belong to the original year.  We could */
/*     probably figure out the right year to use, but with Julian */
/*     date possibly messing everything up, we just use the */
/*     current year and the one before.  If you keep in mind that */
/*     the Julian Year is always less than the Gregorian year and */
/*     that the offsets can only push you into the next year, you */
/*     can determine that we want to start with what ever current */
/*     UTC year we have and work backwards until we have the */
/*     year corresponding to the original year.  Since the current */
/*     UTC year was constructed from the input original year, we */
/*     only have to step back at most 1 year to get all the dates */
/*     that might have leapseconds in the user specified year */
/*     of whatever calendar happens to be in use. */

    __state->cyear = (integer) d_int(&__global_state->f2c, &__state->tvec[(
	    i__1 = __state->yr - 1) < 8 && 0 <= i__1 ? i__1 : s_rnge(&
	    __global_state->f2c, "tvec", i__1, "str2et_", (ftnlen)1387)]);
    i__1 = __state->cyear - 1;
    for (__state->gyear = __state->cyear; __state->gyear >= i__1; 
	    --__state->gyear) {
	for (__state->i__ = 1; __state->i__ <= 2; ++__state->i__) {
	    __state->tvec[0] = (doublereal) __state->gyear;
	    __state->tvec[1] = __state->mon[(i__2 = __state->i__ - 1) < 2 && 
		    0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "mon", 
		    i__2, "str2et_", (ftnlen)1394)];
	    __state->tvec[2] = __state->mdy[(i__2 = __state->i__ - 1) < 2 && 
		    0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "mdy", 
		    i__2, "str2et_", (ftnlen)1395)];
	    __state->tvec[3] = __state->hoff + 23.;
	    __state->tvec[4] = __state->moff + 59.;
	    __state->tvec[5] = 0.;

/*           Normalize the time vector. */

	    ttrans_(__global_state, "YMDF", "YMDF", __state->tvec, (ftnlen)4, 
		    (ftnlen)4);
	    __state->year = i_dnnt(&__global_state->f2c, __state->tvec);
	    __state->month = i_dnnt(&__global_state->f2c, &__state->tvec[1]);
	    __state->day = i_dnnt(&__global_state->f2c, &__state->tvec[2]);
	    if (__state->dojul) {
		gr2jul_(__global_state, &__state->year, &__state->month, &
			__state->day, &__state->doy);
	    }
	    if (__state->year == __state->orgnyr) {
		repmc_(__global_state, __state->error, "#", __state->mname + (
			((i__2 = __state->month - 1) < 12 && 0 <= i__2 ? i__2 
			: s_rnge(&__global_state->f2c, "mname", i__2, "str2e"
			"t_", (ftnlen)1415)) << 4), __state->error, (ftnlen)
			400, (ftnlen)1, (ftnlen)16, (ftnlen)400);
		repmi_(__global_state, __state->error, "#", &__state->day, 
			__state->error, (ftnlen)400, (ftnlen)1, (ftnlen)400);
	    }
	}
    }
    setmsg_(__global_state, __state->error, (ftnlen)400);
    sigerr_(__global_state, "SPICE(BADTIMESTRING)", (ftnlen)20);
    chkout_(__global_state, "STR2ET", (ftnlen)6);
    return 0;
} /* str2et_ */

