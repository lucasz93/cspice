/* tpartv.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern tpartv_init_t __tpartv_init;
static tpartv_state_t* get_tpartv_state(cspice_t* state) {
	if (!state->tpartv)
		state->tpartv = __cspice_allocate_module(sizeof(
	tpartv_state_t), &__tpartv_init, sizeof(__tpartv_init));
	return state->tpartv;

}

/* $Procedure      TPARTV ( Time string ---parse to a time vector) */
/* Subroutine */ int tpartv_(cspice_t* __global_state, char *string, 
	doublereal *tvec, integer *ntvec, char *type__, char *modify, logical 
	*mods, logical *yabbrv, logical *succes, char *pictur, char *error, 
	ftnlen string_len, ftnlen type_len, ftnlen modify_len, ftnlen 
	pictur_len, ftnlen error_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer i_indx(f2c_state_t*, char *, char *, ftnlen, ftnlen), s_cmp(
	    f2c_state_t*, char *, char *, ftnlen, ftnlen), s_rnge(f2c_state_t*
	    , char *, integer, char *, integer);

    /* Local variables */
    extern logical zztokns_(cspice_t*, char *, char *, ftnlen, ftnlen);
    extern /* Subroutine */ int zzinssub_(cspice_t*, char *, char *, integer *
	    , char *, ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int ucase_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int repmc_(cspice_t*, char *, char *, char *, 
	    char *, ftnlen, ftnlen, ftnlen, ftnlen);
    extern integer rtrim_(cspice_t*, char *, ftnlen);
    extern logical zzist_(cspice_t*, char *, ftnlen);
    extern integer bsrchc_(cspice_t*, char *, integer *, char *, ftnlen, 
	    ftnlen);
    extern integer isrchc_(cspice_t*, char *, integer *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int prefix_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    extern integer intmax_(cspice_t*);
    extern /* Subroutine */ int suffix_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    extern logical zzcmbt_(cspice_t*, char *, char *, logical *, ftnlen, 
	    ftnlen);
    extern logical zzgrep_(cspice_t*, char *, ftnlen);
    extern logical zznote_(cspice_t*, char *, integer *, integer *, ftnlen);
    extern logical zzvalt_(cspice_t*, char *, integer *, integer *, char *, 
	    ftnlen, ftnlen);
    extern logical zzremt_(cspice_t*, char *, ftnlen);
    extern logical zzrept_(cspice_t*, char *, char *, logical *, ftnlen, 
	    ftnlen);
    extern logical zzsubt_(cspice_t*, char *, char *, logical *, ftnlen, 
	    ftnlen);
    extern logical zzispt_(cspice_t*, char *, integer *, integer *, ftnlen);
    extern logical zzunpck_(cspice_t*, char *, logical *, doublereal *, 
	    integer *, char *, char *, char *, ftnlen, ftnlen, ftnlen, ftnlen)
	    ;
    extern logical zztpats_(cspice_t*, integer *, integer *, char *, char *, 
	    ftnlen, ftnlen);


    /* Module state */
    tpartv_state_t* __state = get_tpartv_state(__global_state);
/* $ Abstract */

/*     This routine returns the components of a time supplied */
/*     as a string and returns a vector of the components of */
/*     that string together with an array of modifiers that may */
/*     have been supplied with the string that may alter */
/*     the interpretation of the components. */

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
/*     STRING     I   A string to be parsed as a time */
/*     TVEC       O   A vector giving the components of the time. */
/*     NTVEC      O   The number of components supplied for TVEC */
/*     TYPE       O   The type of the "time vector" TVEC */
/*     MODIFY     O   A list of modifiers present in STRING. */
/*     MODS       O   A logical indicating the presence of a modifier */
/*     YABBRV     O   A logical indicating that a year was abbreviated */
/*     SUCCES     O   A logical indicating whether STRING was parsed. */
/*     PICTUR     O   A time format picture associated with STRING */
/*     ERROR      O   A diagnostic message if STRING couldn't be parsed */

/*     The function returns */

/* $ Detailed_Input */

/*     STRING     is a character string that represents some */
/*                julian or calendar epoch. */

/* $ Detailed_Output */

/*     TVEC       is a vector of double precision numbers that represent */
/*                the input string.  The number and meaning of the */
/*                components of TVEC depend upon the input string.  This */
/*                meaning can be determined from the output variable */
/*                TYPE. */

/*                TYPE      NTVEC     TVEC Components */
/*                ------------------------------------------------------- */
/*                YMD       3 to 6    TVEC(1) is the calendar year */
/*                                    TVEC(2) is the numeric value of the */
/*                                            month (1-12) */
/*                                    TVEC(3) is the day of the month */
/*                                    TVEC(4) is the hour of the day */
/*                                    TVEC(5) is the minute of the hour */
/*                                    TVEC(6) is the second of the minute */

/*                YD        2 to 5    TVEC(1) is the calendar year */
/*                                    TVEC(2) is the day of the year */
/*                                    TVEC(3) is the hour of the day */
/*                                    TVEC(4) is the minute of the hour */
/*                                    TVEC(5) is the second of the minute */

/*                JD        1         TVEC(1) is the julian date */

/*                Note that the values of TVEC are not forced into the */
/*                normal ranges used in daily conversation.  TPARTV */
/*                simply reports what's found in the string and does */
/*                not pass judgement on the "correctness" of these */
/*                components. */

/*     NTVEC     is the actual number of components that were present */
/*               in the string.  For example a user might have */
/*               supplied only year, month and day of an epoch. */
/*               In such a case NTVEC will be set to 3.  The components */
/*               actually supplied will be 1 through NTVEC.  Values */
/*               not supplied are set to zero. */

/*     TYPE      is the type of time string supplied.  This is a function */
/*               of whether the string contains year, month and day, */
/*               day of year, or julian date. */

/*     MODIFY    is an array of character strings that indicate */
/*               whether a modifier to the calendar string was supplied. */
/*               If a particular modifier was not supplied, the */
/*               value of that component of MODIFY will be set to */
/*               a blank.  Modifiers are used to change the meaning */
/*               of time strings. */

/*               For example 12:12:29 Jan 1, 1996  means 12 hours past */
/*               midnight on Jan 1, 1996 in the UTC time system. But */
/*               if we modify the string to be: */

/*                  12:12:29 A.M. Jan 1, Tuesday PDT 1996 B.C. */

/*               the string takes on an entirely different meaning. */

/*               Five different modifiers are recognized by TPARTV: */
/*               the era associated with the epoch, day of week of */
/*               the epoch, time zone of an epoch,  AM/PM used in */
/*               daily time usage, and the system (UTC, TDB, or TDT). */

/*               Again whether or not modifiers are compatible with the */
/*               time and date components or with each other is not */
/*               determined by TPARTV.  TPARTV simply reports what is */
/*               present in the string, leaving the task of deciding */
/*               the meaning of the string to the calling routine. */

/*               The components of MODIFY, their meaning and possible */
/*               values are given below. */

/*               Component   Meaning   Possible Non-blank Modifier Values */
/*               ---------   -------   ---------------------------------- */
/*               1           ERA       'A.D.', 'B.C.' */
/*               2           Weekday   'SUN',  'MON', ... etc. */
/*               3           Time Zone 'UTC+i:i', 'UTC-i:i' */
/*               4           AM/PM     'A.M.', 'P.M.' */
/*               5           System    'UTC',  'TDB', 'TDT' */

/*               TPARTV recognizes the standard abbreviations of */
/*               all continental U.S. time zones. */

/*                  PDT --- Pacific  Daylight Time  (UTC-07:00) */
/*                  PST --- Pacific  Standard Time  (UTC-08:00) */
/*                  MDT --- Mountain Daylight Time  (UTC-06:00) */
/*                  MST --- Mountain Standard Time  (UTC-07:00) */
/*                  CDT --- Central  Daylight Time  (UTC-05:00) */
/*                  CST --- Central  Standard Time  (UTC-06:00) */
/*                  EDT --- Eastern  Daylight Time  (UTC-04:00) */
/*                  EST --- Eastern  Standard Time  (UTC-05:00) */

/*               In addition it recognizes offsets from UTC expressed */
/*               as UTC+/-HR:MN.  Note that through out SPICELIB */
/*               the minutes component of the UTC offset are always */
/*               regarded as positive offsets from the hour offset. */

/*               All Time zones are returned in MODIFY as UTC offsets */
/*               as indicated in the table above. */

/*     MODS      is TRUE if some non-blank modifier was supplied. */

/*     YABBRV    is TRUE if a year was supplied in the abbreviated */
/*               form 'YR  where YR is a two digit integer. */

/*     SUCCES    is TRUE if the string was successfully parsed. */
/*               Otherwise it is set to FALSE and a diagnostic */
/*               is supplied in the argument ERROR. */

/*     PICTUR    is a string that gives a format picture that can */
/*               be used by the routine TIMOUT to construct a time */
/*               string of the same form as the input time string. */

/*               If some component of the input string could not be */
/*               identified, PICTUR is returned as a blank.  However, */
/*               if all components of the input string could be */
/*               identified and the string is simply ambiguous, PICTUR */
/*               will contain a format picture that corresponds to */
/*               the ambiguous input.  Consequently, you must check */
/*               the value of PICTUR to determine if TPARTV has */
/*               been able to construct a format picture. */

/*     ERROR     is blank if the string was successfully parsed. */
/*               Otherwise a human readable diagnostic is returned */
/*               in ERROR. */

/* $ Parameters */

/*     None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     Error Free. */

/*     1) All problems are diagnosed via the variables SUCCES and */
/*        ERROR. */

/* $ Particulars */

/*      This routine parses in input string that represents some */
/*      epoch in some time system.  In addition it constructs a */
/*      format picture that describes the position and meaning */
/*      of the various components of the string. */

/*      This routine is intended to be used in close conjunction with */
/*      the routines TTRANS and TIMOUT. */

/*      The string is parsed by first determining its recognizable */
/*      substrings (integers, punctuation marks, names of months, */
/*      names of weekdays, time systems, time zones, etc.)  These */
/*      recognizable substrings are called the tokens of the input */
/*      string.  The meaning of some tokens are immediately determined. */
/*      For example named months, weekdays, time systems have clear */
/*      meanings.  However, the meanings of numeric components must */
/*      be deciphered from their magnitudes and location in */
/*      the string relative to the immediately recognized components */
/*      of the input string. */

/*      To determine the meaning of the numeric tokens in the input */
/*      string, a set of "productions rules" and transformations are */
/*      applied to the full set of tokens in the string.  These */
/*      transformations are repeated until the meaning of every token */
/*      has been determined or until further transformations yield */
/*      no new clues into the meaning of the numeric tokens. */

/*      1)  Unless the substring JD or jd is present the string is */
/*          assumed to be a calendar format (day-month-year or year and */
/*          day of year).  If the substring JD or jd is present, the */
/*          string is assumed to represent a julian date. */

/*      2)  If the julian date specifier is not present, any integer */
/*          greater than 999 is regarded as being a year specification. */

/*      3)  A dash '-' can represent a minus sign only if it is precedes */
/*          the first digit in the string and the string contains */
/*          the julian date specifier (JD).  (No negative years, */
/*          months, days, etc are allowed). */

/*      4)  Numeric components of a time string must be separated */
/*          by a character that is not a digit or decimal point. */
/*          Only one decimal component is allowed.  For example */
/*          1994219.12819 is sometimes interpreted as the */
/*          219th day of 1994 + 0.12819 days.  TPARTV does not */
/*          support such strings. */

/*          No exponential components are allowed.  For example you */
/*          can't input 1993 Jun 23 23:00:01.202E-4 you have */
/*          to explicitly list all zeros that follow the decimal */
/*          point: i.e.  1993 Jun 23 23:00:00.0001202 */

/*      5)  The single colon (:) when used to separate numeric */
/*          components of a string is interpreted as separating */
/*          Hours, Minutes, and Seconds of time. */

/*      6)  If a double slash (//) or double colon (::) follows */
/*          a pair of integers, those integers are assumed  to */
/*          represent the year and day of year. */

/*      7)  A quote followed by an integer less than 100 is regarded */
/*          as an abbreviated year.  For example: '93 would be regarded */
/*          as the 93rd year of the reference century.  See TEXPYR */
/*          for further discussion of abbreviated years. */

/*       8) An integer followed by 'B.C.' or 'A.D.' is regarded as */
/*          a year in the era associated with that abbreviation. */

/*       9) All dates are regarded as belonging to the extended */
/*          Gregorian Calendar (the Gregorian calendar is the calendar */
/*          currently used by western society).  See the routine JUL2GR */
/*          for  converting from Julian Calendar to the */
/*          Gregorian Calendar. */
/*          western society). */

/*      10) If the ISO date-time separator (T) is present in the string */
/*          ISO allowed token patterns are examined for a match */
/*          with the current token list.  If no match is found the */
/*          search is abandoned and appropriate diagnostic messages */
/*          are generated. */

/*      11) If two delimiters are found in succession in the time */
/*          string, the time string is diagnosed as an erroneous */
/*          string.  ( Delimiters are comma, white space, dash, slash, */
/*          period, day of year mark ) */

/*          Note the delimiters do not have to be the same. The pair */
/*          of characters ",-" counts as two successive delimiters. */

/*      12) White space, commas serve only to delimit tokens in the */
/*          input string.  They do not affect the meaning of any */
/*          of the tokens. */

/*      13) When the size of the integer components does not clearly */
/*          specify a year the following patterns are assumed */

/*          Calendar Format */

/*              Year Month Day */
/*              Month Day Year */
/*              Year Day Month */

/*              Where Month is the name of a month, not its numeric */
/*              value. */

/*              When integer components are separated by slashes (/) */
/*              as in 3/4/5.  Month, Day, Year is assumed (2005 March 4) */

/*           Day of Year Format. */

/*              If a day of year marker is present (// or ::) the */
/*              pattern */

/*              I-I// or I-I:: (where I stands for and integer) */
/*              is interpreted as Year Day-of-Year. However, I-I/ is */
/*              regarded as ambiguous. */


/*      The table below gives a list of abbreviations used to */
/*      classify tokens. */

/*                 /   ---  slash punctuation mark */
/*                 H   ---  hour */
/*                 M   ---  Minute */
/*                 S   ---  Second */
/*                 Y   ---  year */
/*                 d   ---  day of year marker */
/*                 i   ---  unsigned integer */
/*                 m   ---  month */
/*                 n   ---  unsigned decimal number */
/*                 y   ---  day of year */
/*                 -   ---  dash punctuation mark */
/*                 D   ---  day of month */
/*                 :   ---  colon punctuation mark */

/*       Given these abbreviations the following (rather lengthy) */
/*       table gives the set of built in token patterns that */
/*       are recognized and the associated interpretation of that */
/*       pattern. */

/*        Pattern         Meaning         Pattern         Meaning */
/*        ------------------------        ------------------------- */
/*        Y-i-it......... YmD             i/i/ii:i:n..... mDYHMS */
/*        Y-i-iti........ YmDH            i/i/ii:n....... mDYHM */
/*        Y-i-iti:i...... YmDHM           i/i/ii:n....... mDYHM */
/*        Y-i-iti:i:i.... YmDHMS          i:i:ii-i-Y..... HMSmDY */
/*        Y-i-iti:i:n.... YmDHMS          i:i:ii/i/Y..... HMSmDY */
/*        Y-i-iti:n...... YmDHM           i:i:ii/i/i..... HMSmDY */
/*        Y-i-itn........ YmDH            i:i:iimY....... HMSDmY */
/*        Y-i/........... Yy              i:i:imiY....... HMSmDY */
/*        Y-i/i:i........ YyHM            i:i:ni-i-Y..... HMSmDY */
/*        Y-i/i:i:i...... YyHMS           i:i:ni/i/Y..... HMSmDY */
/*        Y-i/i:i:n...... YyHMS           i:i:ni/i/i..... HMSmDY */
/*        Y-i/i:n........ YyHM            i:i:nimY....... HMSDmY */
/*        Y-id........... Yy              i:i:nmiY....... HMSmDY */
/*        Y-idi:i........ YyHM            i:ii-i-Y....... HMmDY */
/*        Y-idi:i:i...... YyHMS           i:ii/i/Y....... HMmDY */
/*        Y-idi:i:n...... YyHMS           i:ii/i/i....... HMmDY */
/*        Y-idi:n........ YyHM            i:iimY......... HMDmY */
/*        Y-it........... Yy              i:imiY......... HMmDY */
/*        Y-iti.......... YyH             i:ni-i-Y....... HMmDY */
/*        Y-iti:i........ YyHM            i:ni/i/Y....... HMmDY */
/*        Y-iti:i:i...... YyHMS           i:ni/i/i....... HMmDY */
/*        Y-iti:i:n...... YyHMS           i:nimY......... HMDmY */
/*        Y-iti:n........ YyHM            i:nmiY......... HMmDY */
/*        Y-itn.......... YyH             iYd............ yY */
/*        Yid............ Yy              iYdi:i......... yYHM */
/*        Yidi:i......... YyHM            iYdi:i:i....... yYHMS */
/*        Yidi:i:i....... YyHMS           iYdi:i:n....... yYHMS */
/*        Yidi:i:n....... YyHMS           iYdi:n......... yYHM */
/*        Yidi:n......... YyHM            iiY............ mDY */
/*        Yii............ YmD             iiYi........... mDYH */
/*        Yiii........... YmDH            iiYi:i......... mDYHM */
/*        Yiii:i......... YmDHM           iiYi:i:i....... mDYHMS */
/*        Yiii:i:i....... YmDHMS          iiYi:i:n....... mDYHMS */
/*        Yiii:i:n....... YmDHMS          iiYi:n......... mDYHM */
/*        Yiii:n......... YmDHM           iiYn........... mDYH */
/*        Yiiii.......... YmDHM           iid............ Yy */
/*        Yiiiii......... YmDHMS          iidi:i......... YyHM */
/*        Yiiiin......... YmDHMS          iidi:i:i....... YyHMS */
/*        Yiiin.......... YmDHM           iidi:i:n....... YyHMS */
/*        Yiin........... YmDH            iidi:n......... YyHM */
/*        Yim............ YDm             iim............ YDm */
/*        Yimi........... YDmH            iimi........... YDmH */
/*        Yimi:i......... YDmHM           iimi:i......... YDmHM */
/*        Yimi:i:i....... YDmHMS          iimi:i:i....... YDmHMS */
/*        Yimi:i:n....... YDmHMS          iimi:i:n....... YDmHMS */
/*        Yimi:n......... YDmHM           iimi:n......... YDmHM */
/*        Yimn........... YDmH            iimii.......... YDmHM */
/*        Yin............ YmD             iimiii......... YDmHMS */
/*        Ymi............ YmD             iimiin......... YDmHMS */
/*        Ymii........... YmDH            iimin.......... YDmHM */
/*        Ymii:i......... YmDHM           iimn........... YDmH */
/*        Ymii:i:i....... YmDHMS          imY............ DmY */
/*        Ymii:i:n....... YmDHMS          imYi........... DmYH */
/*        Ymii:n......... YmDHM           imYi:i......... DmYHM */
/*        Ymin........... YmDH            imYi:i:i....... DmYHMS */
/*        Ymn............ YmD             imYi:i:n....... DmYHMS */
/*        Ynm............ YDm             imYi:n......... DmYHM */
/*        i-Y/........... yY              imYn........... DmYH */
/*        i-Y/i:i........ yYHM            imi............ YmD */
/*        i-Y/i:i:i...... yYHMS           imi:i:iY....... DmHMSY */
/*        i-Y/i:i:n...... yYHMS           imi:i:nY....... DmHMSY */
/*        i-Y/i:n........ yYHM            imi:iY......... DmHMY */
/*        i-Yd........... yY              imi:nY......... DmHMY */
/*        i-Ydi:i........ yYHM            imii........... YmDH */
/*        i-Ydi:i:i...... yYHMS           imii:i......... YmDHM */
/*        i-Ydi:i:n...... yYHMS           imii:i:i....... YmDHMS */
/*        i-Ydi:n........ yYHM            imii:i:n....... YmDHMS */
/*        i-i-Y.......... mDY             imii:n......... YmDHM */
/*        i-i-Yi:i....... mDYHM           imiii.......... YmDHM */
/*        i-i-Yi:i:i..... mDYHMS          imiiii......... YmDHMS */
/*        i-i-Yi:i:n..... mDYHMS          imiiin......... YmDHMS */
/*        i-i-Yi:n....... mDYHM           imiin.......... YmDHM */
/*        i-i-it......... YmD             imin........... YmDH */
/*        i-i-iti........ YmDH            imn............ YmD */
/*        i-i-iti:i...... YmDHM           inY............ mDY */
/*        i-i-iti:i:i.... YmDHMS          inm............ YDm */
/*        i-i-iti:i:n.... YmDHMS          miY............ mDY */
/*        i-i-iti:n...... YmDHM           miYi........... mDYH */
/*        i-i-itn........ YmDH            miYi:i......... mDYHM */
/*        i-i/i:i........ YyHM            miYi:i:i....... mDYHMS */
/*        i-i/i:i:i...... YyHMS           miYi:i:n....... mDYHMS */
/*        i-i/i:i:n...... YyHMS           miYi:n......... mDYHM */
/*        i-i/i:n........ YyHM            miYn........... mDYH */
/*        i-idi:i........ YyHM            mii............ mDY */
/*        i-idi:i:i...... YyHMS           mii:i:iY....... mDHMSY */
/*        i-idi:i:n...... YyHMS           mii:i:nY....... mDHMSY */
/*        i-idi:n........ YyHM            mii:iY......... mDHMY */
/*        i-it........... Yy              mii:nY......... mDHMY */
/*        i-iti.......... YyH             miii........... mDYH */
/*        i-iti:i........ YyHM            miii:i......... mDYHM */
/*        i-iti:i:i...... YyHMS           miii:i:i....... mDYHMS */
/*        i-iti:i:n...... YyHMS           miii:i:n....... mDYHMS */
/*        i-iti:n........ YyHM            miii:n......... mDYHM */
/*        i-itn.......... YyH             miiii.......... mDYHM */
/*        i/i/Y.......... mDY             miiiii......... mDYHMS */
/*        i/i/Y/i:n...... mDYHM           miiiin......... mDYHMS */
/*        i/i/Yi:i....... mDYHM           miiin.......... mDYHM */
/*        i/i/Yi:i:i..... mDYHMS          miin........... mDYH */
/*        i/i/Yi:i:n..... mDYHMS          mnY............ mDY */
/*        i/i/i.......... mDY             mni............ mDY */
/*        i/i/ii:i....... mDYHM           nmY............ DmY */
/*        i/i/ii:i:i..... mDYHMS */

/* $ Examples */

/*     Suppose you need to convert various time strings to ephemeris */
/*     seconds past J2000.  The following pair of calls shows */
/*     how you would use this routine together with the routines */
/*     TCHECK and TTRANS to perform this task. */


/*         CALL TPARTV ( STRING, */
/*        .              TVEC,   NTVEC, TYPE, */
/*        .              MODIFY, MODS,  YABBRV, SUCCES, */
/*        .              PICTUR, ERROR ) */


/*         IF ( .NOT. SUCCES ) THEN */

/*            Use the SPICE error handling facility to post an */
/*            error message and signal an error. */

/*            CALL SETMSG ( ERROR ) */
/*            CALL SIGERR ( 'MYCHECK(BADTIME)' ) */
/*            CALL CHKOUT ( 'MYROUTINE' ) */
/*            RETURN */
/*         END IF */

/*         Check the components of TVEC to make sure everything */
/*         makes sense. */

/*         CALL TCHECK( TVEC, TYPE, MODS, MODIFY, OK, ERROR ) */

/*         IF ( .NOT. OK ) THEN */

/*            Use the SPICE error handling facility to post an */
/*            error message and signal an error. */

/*            CALL SETMSG ( ERROR ) */
/*            CALL SIGERR ( 'MYCHECK(BADTIME)' ) */
/*            CALL CHKOUT ( 'MYROUTINE' ) */
/*            RETURN */
/*         END IF */

/*         CALL TTRANS ( TYPE, 'ET', TVEC ) */

/*         ET = TVEC(1) */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 3.1.0, 15-AUG-2002 (WLT) */

/*        Replaced the call to INSSUB with ZZINSSUB so that this */
/*        routine can legitimately be called error free. */

/* -    SPICELIB Version 3.0.0, 10-MAY-1999 (WLT) */

/*        The routine was modified so that weekday followed by a comma */
/*        is recognized as a legitimate pattern when parsing. */

/* -    SPICELIB Version 2.0.0, 16-APR-1997 (WLT) */

/*        The routine was modified so that last-chance removal of */
/*        delimiters ',', '-', and '/' are removed one at a time */
/*        (instead of all at once as in version 1.0.0) and the */
/*        resulting representation checked against */
/*        the built-in list. */

/*        In addition the set of built-in patterns was increased */
/*        from 185 to 203.  See ZZTPATS for more details. */

/* -    SPICELIB Version 1.0.0, 10-AUG-1996 (WLT) */


/* -& */
/* $ Index_Entries */

/*     Parse a time string into a vector of components */

/* -& */

/*     SPICELIB Functions */


/*     Private Functions */


/*     Parameters */


/*     ERA */
/*     WDAY */
/*     ZONE */
/*     AMPM */
/*     SYSTEM */


/*     Local Variables. */

/*     The number of known time patterns NKNOWN comes from the include */
/*     file timepars.inc */


/*     Time Zone Variables */


/*     Standard SPICE error handling. */


/*     So far there are no modifiers to the time string. */

    *mods = FALSE_;
    *yabbrv = FALSE_;
    for (__state->i__ = 1; __state->i__ <= 5; ++__state->i__) {
	s_copy(&__global_state->f2c, modify + (__state->i__ - 1) * modify_len,
		 " ", modify_len, (ftnlen)1);
    }

/*     On the first call to this routine we load the built in */
/*     representation patterns. */

    if (__state->first) {
	if (zztpats_(__global_state, &__state->c__300, &__state->nknown, 
		__state->known, __state->meanng, (ftnlen)12, (ftnlen)12)) {
	    __state->first = FALSE_;
	} else {
	    s_copy(&__global_state->f2c, pictur, " ", pictur_len, (ftnlen)1);
	    *succes = FALSE_;
	    s_copy(&__global_state->f2c, error, "There is an incompatibility"
		    " between ZZTPATS and the room allocated for KNOWN in TPA"
		    "RTV.", error_len, (ftnlen)87);
	    return 0;
	}
    }

/*     First step is to tokenize the string.  The new representation */
/*     is maintained in ZZTIME.  We'll get it later if we need it. */

    __state->resolv = zztokns_(__global_state, string, error, string_len, 
	    error_len);
    if (! __state->resolv) {
	*succes = FALSE_;
	*ntvec = 0;
	s_copy(&__global_state->f2c, type__, " ", type_len, (ftnlen)1);
	s_copy(&__global_state->f2c, pictur, " ", pictur_len, (ftnlen)1);
	return 0;
    }

/*     The result of tokenizing the string will be a representation */
/*     that contains the following letters. */

/*           '        The quote character */
/*           [        The left parenthesis */
/*           ]        The right parenthesis */
/*           ,        The comma */
/*           -        The dash */
/*           .        The decimal point */
/*           /        The slash---used to separate date components. */
/*           :        The colon (used to separate time components) */
/*           N  ---   stands for one of the symbols A.M. or P.M. */
/*           O        stands for the symbol UTC+ */
/*           Z  ---   stands for a time zone such as PDT, PSD, CDT, etc. */
/*           b        stands for a block of white space */
/*           d        stands for the day of year marker (// or ::) */
/*           e  ---   stands for the era (B.C. or A.D.) */
/*           j        stands for julian date */
/*           m        stands for a month */
/*           o        stands for the symbol UTC- */
/*           s  ---   stands for a time system (UTC, TDT, TDB) */
/*           t        stands the ISO date-T-time separator. */
/*           w  ---   stands for the day of the week. */
/*           i        stands for a sequence of digits */

/*     We will gradually remove many of these and replace the i, i. */
/*     and i.i with the following items */

/*           n       stands for a decimal number */
/*           Y       stands for a year */
/*           D       stands for the day in a month */
/*           y       stands for the day of the year */
/*           H       stands for hours */
/*           M       stands for minutes */
/*           S       stands for seconds. */


/*     We will use the following logical functions to modify */
/*     the tokenized representation: */

/*        ZZTOKNS --- breaks the string down into a list of recognized */
/*                    tokens and stores an internal model for this */
/*                    list.  The begins and ends of the substrings */
/*                    associated with the tokenization are maintained */
/*                    inside the routine ZZTIME (which ZZTOKNS is an */
/*                    entry point to).  If some substring cannot be */
/*                    recognized, ZZTOKNS returns the value FALSE */
/*                    together with a diagnostic indicating what */
/*                    was wrong with the input string. */

/*        ZZCMBT  --- combines one or more tokens into a single token. */
/*                    this is performed only once and is done either */
/*                    scanning left to right or right to left. */
/*                    It returns TRUE if a combination is performed. */

/*        ZZREMT  --- removes all instances of a token from the tokenized */
/*                    representation.  It returns TRUE is an item */
/*                    is removed. */

/*        ZZSUBT  --- substitutes the first occurrence of a */
/*                    subpattern (scanning left to right or right to */
/*                    left) with another pattern of the same length. */
/*                    This is where we attach new meaning to the */
/*                    tokenized pattern.  It returns TRUE if a */
/*                    substitution is performed. */

/*        ZZREPT  --- is a combination of the ZZSUBT and ZZREMT */
/*                    This performs ZZSUBT on the string, but then */
/*                    remove all occurrences of the special character */
/*                    * from the tokenized list. It returns TRUE */
/*                    is a substitution is performed. */

/*        ZZNOTE  --- returns the begin and end of the first occurrence */
/*                    of some token, and then removes the token */
/*                    from the tokenized representation.  We use this */
/*                    primarily to extract modifiers from the tokenized */
/*                    string.  These should occur only once and once */
/*                    removed allow us to more easily attach meaning */
/*                    to the remaining tokens. The value of ZZNOTE */
/*                    is true if the requested item could be found, */
/*                    otherwise it is false and the begin and end */
/*                    of the requested substring are set to 0. */

/*        ZZIST   --- returns TRUE if the specified token is present */
/*                    in the tokenized substring. */

/*        ZZISPT  --- returns true is a pair of consecutive tokens */
/*                    from a list are located in the representation */
/*                    of the tokenized string.  This is used to */
/*                    locate consecutive pairs of delimiters in the */
/*                    input string. It returns TRUE if a pair of */
/*                    consecutive items is located.  Otherwise */
/*                    it returns FALSE. */

/*        ZZVALT  --- allows you to substitute a new token for any */
/*                    integer (i) that lies within a specified range */
/*                    of values.  This is primarily used to recognize */
/*                    years in the input string. */

/*        ZZGREP  --- is used to get the current representation of the */
/*                    tokenized string (with all processing resulting */
/*                    from use of the manipulation routines taken into */
/*                    account). */

/*        ZZTPATS --- is used to set up the large list of canned patterns */
/*                    that are recognized as legitimate tokenizations. */
/*                    Almost all legitimate time strings when tokenized */
/*                    will match one of these patterns. */

/*        ZZUNPCK --- uses STRING together with the current */
/*                    representation of it's tokens to return a */
/*                    time vector.  If a problem is encountered with */
/*                    the current tokens, it returns a diagnostic */
/*                    message that indicates why the string */
/*                    could not be parsed.  Note ZZUNPCK should be */
/*                    called only after all string modifiers have */
/*                    been retrieved via a call to ZZNOTE (or by */
/*                    manually removing them). */

/*     Next Step is to combine some tokens so that we won't run */
/*     into problems later on.  We may introduce some new components */
/*     in the process. */

    __state->l2r = TRUE_;
    __state->r2l = ! __state->l2r;
    if (zzcmbt_(__global_state, "Oi", "z", &__state->l2r, (ftnlen)2, (ftnlen)
	    1)) {
	__state->resolv = zzcmbt_(__global_state, "z:i", "Z", &__state->l2r, (
		ftnlen)3, (ftnlen)1);
	__state->resolv = zzsubt_(__global_state, "z", "Z", &__state->l2r, (
		ftnlen)1, (ftnlen)1);
    }
    if (zzcmbt_(__global_state, "oi", "z", &__state->l2r, (ftnlen)2, (ftnlen)
	    1)) {
	__state->resolv = zzcmbt_(__global_state, "z:i", "Z", &__state->l2r, (
		ftnlen)3, (ftnlen)1);
	__state->resolv = zzsubt_(__global_state, "z", "Z", &__state->l2r, (
		ftnlen)1, (ftnlen)1);
    }

/*     Next we resolve any months, or weekdays that are followed */
/*     by periods. */

    __state->resolv = zzrept_(__global_state, "m.", "m*", &__state->l2r, (
	    ftnlen)2, (ftnlen)2);
    __state->resolv = zzrept_(__global_state, "w.", "w*", &__state->l2r, (
	    ftnlen)2, (ftnlen)2);
    __state->resolv = zzrept_(__global_state, "w,", "w*", &__state->l2r, (
	    ftnlen)2, (ftnlen)2);

/*     Now convert the right most integer-decimal-point pair to the */
/*     number representation. */

    if (zzcmbt_(__global_state, "i.i", "n", &__state->r2l, (ftnlen)3, (ftnlen)
	    1)) {

/*        We aren't going to do anything here.  We are simply */
/*        using the IF-THEN...ELSE IF ... ENDIF  to make sure */
/*        we only replace one decimal place. */

    } else if (zzcmbt_(__global_state, "i.", "n", &__state->r2l, (ftnlen)2, (
	    ftnlen)1)) {

/*        Same as the previous comment. */

    }

/*     Remove any white space from the tokenization. */

    __state->resolv = zzremt_(__global_state, "b", (ftnlen)1);

/*     User Custom Formats (this still needs a modicum of work). */
/*     ---------------------------------------------------------------- */
/*     ================================================================ */


/*     RESOLV = ZZGREP ( REP ) */
/*     USE    = ISRCHC ( REP, NCUSTM, CUSTOM ) */

/*     IF ( USE .GT. 0 ) THEN */
/*        RESOLV = ZZREPT ( CUSTM(USE), CMEANS(USE), L2R ) */
/*     ELSE */
/*        RESOLV =  .FALSE. */
/*     END IF */

/*     IF ( RESOLV ) THEN */

/*        SUCCES = ZZUNPCK ( STRING, YABBRV, ... */
/*                           TVEC,   NTVEC, TYPE, PICTUR, ERROR ) */
/*        ERROR  = ' ' */

/*        RETURN */
/*     END IF */



/*     Julian Date */
/*     ---------------------------------------------------------------- */
/*     ================================================================ */

    if (zzist_(__global_state, "j", (ftnlen)1)) {

/*        This is some form of Julian Date. Handle this case */
/*        right here and return. */

	__state->resolv = zzrept_(__global_state, "[s]", "*s*", &__state->l2r,
		 (ftnlen)3, (ftnlen)3);
	*mods = *mods || zznote_(__global_state, "s", &__state->b, &
		__state->e, (ftnlen)1);
	if (*mods) {
	    ucase_(__global_state, string + (__state->b - 1), modify + (
		    modify_len << 2), __state->e - (__state->b - 1), 
		    modify_len);
	}
	__state->resolv = zzrept_(__global_state, "[j]", "*j*", &__state->l2r,
		 (ftnlen)3, (ftnlen)3);
	__state->resolv = zzremt_(__global_state, "j", (ftnlen)1);
	if (! zzist_(__global_state, "n", (ftnlen)1)) {
	    __state->resolv = zzsubt_(__global_state, "i", "n", &__state->l2r,
		     (ftnlen)1, (ftnlen)1);
	}
	__state->resolv = zzcmbt_(__global_state, "-n", "n", &__state->l2r, (
		ftnlen)2, (ftnlen)1);
	__state->resolv = zzsubt_(__global_state, "n", "J", &__state->l2r, (
		ftnlen)1, (ftnlen)1);

/*        We let ZZUNPK handle the parsing or diagnosis of any problems. */

	*succes = zzunpck_(__global_state, string, yabbrv, tvec, ntvec, 
		type__, pictur, error, string_len, type_len, pictur_len, 
		error_len);
	if (i_indx(&__global_state->f2c, pictur, "JULIAND.", pictur_len, (
		ftnlen)8) > 0) {
	    suffix_(__global_state, "::RND", &__state->c__1, pictur, (ftnlen)
		    5, pictur_len);
	}
	if (s_cmp(&__global_state->f2c, modify + (modify_len << 2), " ", 
		modify_len, (ftnlen)1) != 0) {
	    suffix_(__global_state, "::", &__state->c__1, pictur, (ftnlen)2, 
		    pictur_len);
	    suffix_(__global_state, modify + (modify_len << 2), &
		    __state->c__0, pictur, modify_len, pictur_len);
	}
	return 0;
    }

/*     Calendar Date Formats. */
/*     ---------------------------------------------------------------- */
/*     ================================================================ */

/*     Replace any integers greater than 1000 by Y. */

    __state->b = 1000;
    __state->e = intmax_(__global_state);
    __state->resolv = zzvalt_(__global_state, string, &__state->b, &
	    __state->e, "Y", string_len, (ftnlen)1);

/*     If the ISO time delimiter 't' is present we don't perform */
/*     any further simplifications. */

    if (zzist_(__global_state, "t", (ftnlen)1)) {
	__state->resolv = zzgrep_(__global_state, __state->rep, (ftnlen)12);
	__state->use = bsrchc_(__global_state, __state->rep, &__state->nknown,
		 __state->known, (ftnlen)12, (ftnlen)12);
	if (__state->use != 0) {
	    __state->resolv = zzrept_(__global_state, __state->known + ((i__1 
		    = __state->use - 1) < 300 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "known", i__1, "tpartv_", (ftnlen)
		    1011)) * 12, __state->meanng + ((i__2 = __state->use - 1) 
		    < 300 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "meanng", i__2, "tpartv_", (ftnlen)1011)) * 12, &
		    __state->l2r, (ftnlen)12, (ftnlen)12);
	    *succes = zzunpck_(__global_state, string, yabbrv, tvec, ntvec, 
		    type__, pictur, error, string_len, type_len, pictur_len, 
		    error_len);
	    if (i_indx(&__global_state->f2c, pictur, ".#", pictur_len, (
		    ftnlen)2) != 0) {
		suffix_(__global_state, "::RND", &__state->c__1, pictur, (
			ftnlen)5, pictur_len);
	    }
	    if (s_cmp(&__global_state->f2c, modify + (modify_len << 1), " ", 
		    modify_len, (ftnlen)1) != 0) {
		suffix_(__global_state, "::", &__state->c__1, pictur, (ftnlen)
			2, pictur_len);
		suffix_(__global_state, modify + (modify_len << 1), &
			__state->c__0, pictur, modify_len, pictur_len);
	    }
	    if (s_cmp(&__global_state->f2c, modify + (modify_len << 2), " ", 
		    modify_len, (ftnlen)1) != 0) {
		suffix_(__global_state, "::", &__state->c__1, pictur, (ftnlen)
			2, pictur_len);
		suffix_(__global_state, modify + (modify_len << 2), &
			__state->c__0, pictur, modify_len, pictur_len);
	    }
	} else {
	    *succes = FALSE_;
	    *ntvec = 0;
	    *mods = FALSE_;
	    s_copy(&__global_state->f2c, type__, " ", type_len, (ftnlen)1);
	    s_copy(&__global_state->f2c, pictur, " ", pictur_len, (ftnlen)1);
	    s_copy(&__global_state->f2c, error, "The input string uses the I"
		    "SO  \"T\" date/time delimiter but does not match any of "
		    "the accepted ISO formats. ", error_len, (ftnlen)107);
	}
	return 0;
    }

/*     If we reach this point, either we didn't have any custom */
/*     formats supplied or we didn't match any of them. */
/*     Resolve any abbreviated years.  We've already set integers */
/*     that are 1000 or greater to 'Y'  Only 1 or 2 digit integers */
/*     can be year abbreviations.  We replace the 3 digit integers */
/*     with I temporarily; locate any abbreviated years; reset all */
/*     the 3-digit back to 'i'.  (Note 3-digit means value between */
/*     100 and 999.  003 is not regarded as a 3 digit number). */

    __state->b = 100;
    __state->e = 1000;
    __state->resolv = zzvalt_(__global_state, string, &__state->b, &
	    __state->e, "I", string_len, (ftnlen)1);
    *yabbrv = zzrept_(__global_state, "'i", "*Y", &__state->l2r, (ftnlen)2, (
	    ftnlen)2);
    while(zzsubt_(__global_state, "I", "i", &__state->l2r, (ftnlen)1, (ftnlen)
	    1)) {
	++__state->b;
    }

/*     Resolve the system, and other text components. */

    __state->resolv = zzrept_(__global_state, "[e]", "*e*", &__state->l2r, (
	    ftnlen)3, (ftnlen)3);
    __state->resolv = zzrept_(__global_state, "[w]", "*w*", &__state->l2r, (
	    ftnlen)3, (ftnlen)3);
    __state->resolv = zzrept_(__global_state, "[N]", "*N*", &__state->l2r, (
	    ftnlen)3, (ftnlen)3);
    __state->resolv = zzrept_(__global_state, "[Z]", "*Z*", &__state->l2r, (
	    ftnlen)3, (ftnlen)3);
    __state->resolv = zzrept_(__global_state, "[s]", "*s*", &__state->l2r, (
	    ftnlen)3, (ftnlen)3);
    __state->resolv = zzsubt_(__global_state, "ie", "Ye", &__state->l2r, (
	    ftnlen)2, (ftnlen)2);

/*     Note the positions of ERA, WEEKDAY, TIME-ZONE, AMPM marker */
/*     and time SYSTEM. */

    __state->havera = zznote_(__global_state, "e", __state->begs, 
	    __state->ends, (ftnlen)1);
    __state->havwdy = zznote_(__global_state, "w", &__state->begs[1], &
	    __state->ends[1], (ftnlen)1);
    __state->havzon = zznote_(__global_state, "Z", &__state->begs[2], &
	    __state->ends[2], (ftnlen)1);
    __state->havapm = zznote_(__global_state, "N", &__state->begs[3], &
	    __state->ends[3], (ftnlen)1);
    __state->havsys = zznote_(__global_state, "s", &__state->begs[4], &
	    __state->ends[4], (ftnlen)1);
    *mods = __state->havera || __state->havwdy || __state->havzon || 
	    __state->havapm || __state->havsys;
    if (*mods) {
	for (__state->i__ = 1; __state->i__ <= 5; ++__state->i__) {
	    if (__state->begs[(i__1 = __state->i__ - 1) < 5 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "begs", i__1, "tpart"
		    "v_", (ftnlen)1093)] != 0) {
		i__1 = __state->begs[(i__2 = __state->i__ - 1) < 5 && 0 <= 
			i__2 ? i__2 : s_rnge(&__global_state->f2c, "begs", 
			i__2, "tpartv_", (ftnlen)1094)] - 1;
		ucase_(__global_state, string + i__1, modify + (__state->i__ 
			- 1) * modify_len, __state->ends[(i__3 = __state->i__ 
			- 1) < 5 && 0 <= i__3 ? i__3 : s_rnge(&
			__global_state->f2c, "ends", i__3, "tpartv_", (ftnlen)
			1094)] - i__1, modify_len);
	    }
	}
	if (__state->havera) {
	    if (*(unsigned char *)&modify[0] == 'A') {
		s_copy(&__global_state->f2c, modify, "A.D.", modify_len, (
			ftnlen)4);
	    } else {
		s_copy(&__global_state->f2c, modify, "B.C.", modify_len, (
			ftnlen)4);
	    }
	}
	if (__state->havapm) {
	    if (*(unsigned char *)&modify[modify_len * 3] == 'A') {
		s_copy(&__global_state->f2c, modify + modify_len * 3, "A.M.", 
			modify_len, (ftnlen)4);
	    } else {
		s_copy(&__global_state->f2c, modify + modify_len * 3, "P.M.", 
			modify_len, (ftnlen)4);
	    }
	}
	s_copy(&__global_state->f2c, modify + (modify_len + 3), " ", 
		modify_len - 3, (ftnlen)1);
	if (__state->havzon) {
	    __state->mapto = isrchc_(__global_state, modify + (modify_len << 
		    1), &__state->c__8, __state->zones, modify_len, (ftnlen)3)
		    ;
	    if (__state->mapto != 0) {
		s_copy(&__global_state->f2c, modify + (modify_len << 1), 
			__state->offset + ((i__1 = __state->mapto - 1) < 8 && 
			0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "off"
			"set", i__1, "tpartv_", (ftnlen)1121)) * 6, modify_len,
			 (ftnlen)6);
	    }
	}
    }

/*     Try our built in formats without any further substitution. */

    __state->resolv = zzgrep_(__global_state, __state->rep, (ftnlen)12);
    __state->use = bsrchc_(__global_state, __state->rep, &__state->nknown, 
	    __state->known, (ftnlen)12, (ftnlen)12);
    if (__state->use > 0) {
	__state->resolv = zzrept_(__global_state, __state->known + ((i__1 = 
		__state->use - 1) < 300 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "known", i__1, "tpartv_", (ftnlen)1136)) 
		* 12, __state->meanng + ((i__2 = __state->use - 1) < 300 && 0 
		<= i__2 ? i__2 : s_rnge(&__global_state->f2c, "meanng", i__2, 
		"tpartv_", (ftnlen)1136)) * 12, &__state->l2r, (ftnlen)12, (
		ftnlen)12);
	*succes = zzunpck_(__global_state, string, yabbrv, tvec, ntvec, 
		type__, pictur, error, string_len, type_len, pictur_len, 
		error_len);
	if (i_indx(&__global_state->f2c, pictur, ".#", pictur_len, (ftnlen)2) 
		!= 0) {
	    suffix_(__global_state, "::RND", &__state->c__1, pictur, (ftnlen)
		    5, pictur_len);
	}
	if (s_cmp(&__global_state->f2c, modify + (modify_len << 1), " ", 
		modify_len, (ftnlen)1) != 0) {
	    suffix_(__global_state, "::", &__state->c__1, pictur, (ftnlen)2, 
		    pictur_len);
	    suffix_(__global_state, modify + (modify_len << 1), &
		    __state->c__0, pictur, modify_len, pictur_len);
	}
	if (s_cmp(&__global_state->f2c, modify + (modify_len << 2), " ", 
		modify_len, (ftnlen)1) != 0) {
	    suffix_(__global_state, "::", &__state->c__1, pictur, (ftnlen)2, 
		    pictur_len);
	    suffix_(__global_state, modify + (modify_len << 2), &
		    __state->c__0, pictur, modify_len, pictur_len);
	}
	return 0;
    }

/*     Make sure we don't have a pair of successive delimiters */
/*     or a delimiter at either end of the input string. */

    if (zzispt_(__global_state, ",/-:d.", &__state->from, &__state->to, (
	    ftnlen)6)) {
	*succes = FALSE_;
	*ntvec = 0;
	s_copy(&__global_state->f2c, type__, " ", type_len, (ftnlen)1);
	s_copy(&__global_state->f2c, error, string, error_len, string_len);
	i__1 = __state->to + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->from, error, 
		error_len, (ftnlen)1, error_len);
	prefix_(__global_state, "There are two successive delimiters <#> in "
		"the input string.  This is an ambiguous input. ' ", &
		__state->c__0, error, (ftnlen)92, error_len);
	repmc_(__global_state, error, "#", string + (__state->from - 1), 
		error, error_len, (ftnlen)1, __state->to - (__state->from - 1)
		, error_len);
	suffix_(__global_state, "'", &__state->c__0, error, (ftnlen)1, 
		error_len);
	s_copy(&__global_state->f2c, pictur, " ", pictur_len, (ftnlen)1);
	return 0;
    }

/*     A delimiter hanging at either end of the string shall be */
/*     regarded as an error. */

    __state->resolv = zzgrep_(__global_state, __state->rep, (ftnlen)12);
    __state->r__ = rtrim_(__global_state, __state->rep, (ftnlen)12);
    if (i_indx(&__global_state->f2c, ",/-:.", __state->rep, (ftnlen)5, (
	    ftnlen)1) > 0) {
	__state->resolv = zzsubt_(__global_state, __state->rep, "Q", &
		__state->l2r, (ftnlen)1, (ftnlen)1);
	__state->resolv = FALSE_;
    } else if (i_indx(&__global_state->f2c, ",/-:.", __state->rep + (
	    __state->r__ - 1), (ftnlen)5, (ftnlen)1) > 0) {
	__state->resolv = zzsubt_(__global_state, __state->rep + (
		__state->r__ - 1), "Q", &__state->l2r, (ftnlen)1, (ftnlen)1);
	__state->resolv = FALSE_;
    }
    if (! __state->resolv) {
	__state->resolv = zznote_(__global_state, "Q", &__state->from, &
		__state->to, (ftnlen)1);
	s_copy(&__global_state->f2c, error, string, error_len, string_len);
	i__1 = __state->to + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->from, error, 
		error_len, (ftnlen)1, error_len);
	prefix_(__global_state, "An unexpected delimiter ('#') was encounter"
		"ed in the input string. ' ", &__state->c__0, error, (ftnlen)
		69, error_len);
	suffix_(__global_state, "'", &__state->c__0, error, (ftnlen)1, 
		error_len);
	repmc_(__global_state, error, "#", string + (__state->from - 1), 
		error, error_len, (ftnlen)1, __state->to - (__state->from - 1)
		, error_len);
	s_copy(&__global_state->f2c, pictur, " ", pictur_len, (ftnlen)1);
	*succes = FALSE_;
	return 0;
    }

/*     We probably made it unscathed through the check above. */
/*     Remove delimiters ',', '/', and '-' and retry the built-in */
/*     patterns. */

    *(unsigned char *)&__state->delim[0] = ',';
    *(unsigned char *)&__state->delim[1] = '-';
    *(unsigned char *)&__state->delim[2] = '/';
    for (__state->i__ = 1; __state->i__ <= 3; ++__state->i__) {
	__state->resolv = zzremt_(__global_state, __state->delim + ((i__1 = 
		__state->i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "delim", i__1, "tpartv_", (ftnlen)1227)),
		 (ftnlen)1);
	__state->resolv = zzgrep_(__global_state, __state->rep, (ftnlen)12);
	__state->use = bsrchc_(__global_state, __state->rep, &__state->nknown,
		 __state->known, (ftnlen)12, (ftnlen)12);
	if (__state->use > 0) {
	    __state->resolv = zzrept_(__global_state, __state->known + ((i__1 
		    = __state->use - 1) < 300 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "known", i__1, "tpartv_", (ftnlen)
		    1234)) * 12, __state->meanng + ((i__2 = __state->use - 1) 
		    < 300 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "meanng", i__2, "tpartv_", (ftnlen)1234)) * 12, &
		    __state->l2r, (ftnlen)12, (ftnlen)12);
	    *succes = zzunpck_(__global_state, string, yabbrv, tvec, ntvec, 
		    type__, pictur, error, string_len, type_len, pictur_len, 
		    error_len);
	    if (i_indx(&__global_state->f2c, pictur, ".#", pictur_len, (
		    ftnlen)2) != 0) {
		suffix_(__global_state, "::RND", &__state->c__1, pictur, (
			ftnlen)5, pictur_len);
	    }
	    if (s_cmp(&__global_state->f2c, modify + (modify_len << 1), " ", 
		    modify_len, (ftnlen)1) != 0) {
		suffix_(__global_state, "::", &__state->c__1, pictur, (ftnlen)
			2, pictur_len);
		suffix_(__global_state, modify + (modify_len << 1), &
			__state->c__0, pictur, modify_len, pictur_len);
	    }
	    if (s_cmp(&__global_state->f2c, modify + (modify_len << 2), " ", 
		    modify_len, (ftnlen)1) != 0) {
		suffix_(__global_state, "::", &__state->c__1, pictur, (ftnlen)
			2, pictur_len);
		suffix_(__global_state, modify + (modify_len << 2), &
			__state->c__0, pictur, modify_len, pictur_len);
	    }
	    return 0;
	}
    }

/*     If we make it to this point, we must have a pretty funky */
/*     time string.  There are some obvious incompatibilities. We */
/*     check them now */

    if (zznote_(__global_state, "e", &__state->b, &__state->e, (ftnlen)1)) {
    } else if (zznote_(__global_state, "s", &__state->b, &__state->e, (ftnlen)
	    1)) {
    } else if (zznote_(__global_state, "Z", &__state->b, &__state->e, (ftnlen)
	    1)) {
    } else if (zznote_(__global_state, "w", &__state->b, &__state->e, (ftnlen)
	    1)) {
    } else if (zznote_(__global_state, "N", &__state->b, &__state->e, (ftnlen)
	    1)) {
    }

/*     If B is non-zero the item in question is a duplicate */
/*     modifier. */

    if (__state->b > 0) {
	*succes = FALSE_;
	*ntvec = 0;
	s_copy(&__global_state->f2c, type__, " ", type_len, (ftnlen)1);
	s_copy(&__global_state->f2c, error, string, error_len, string_len);
	i__1 = __state->e + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->b, error, error_len, (
		ftnlen)1, error_len);
	prefix_(__global_state, "The substring \"#\" is a duplicate modifier"
		" of the input string: ' ", &__state->c__0, error, (ftnlen)65, 
		error_len);
	suffix_(__global_state, "'", &__state->c__0, error, (ftnlen)1, 
		error_len);
	repmc_(__global_state, error, "#", string + (__state->b - 1), error, 
		error_len, (ftnlen)1, __state->e - (__state->b - 1), 
		error_len);
	s_copy(&__global_state->f2c, pictur, " ", pictur_len, (ftnlen)1);
	return 0;
    }

/*     Look for unresolved markers */

    if (zznote_(__global_state, "[", &__state->b, &__state->e, (ftnlen)1)) {
    } else if (zznote_(__global_state, "]", &__state->b, &__state->e, (ftnlen)
	    1)) {
    } else if (zznote_(__global_state, "O", &__state->b, &__state->e, (ftnlen)
	    1)) {
    } else if (zznote_(__global_state, "o", &__state->b, &__state->e, (ftnlen)
	    1)) {
    } else if (zznote_(__global_state, "z", &__state->b, &__state->e, (ftnlen)
	    1)) {
    }
    if (__state->b > 0) {
	*succes = FALSE_;
	*ntvec = 0;
	s_copy(&__global_state->f2c, type__, " ", type_len, (ftnlen)1);
	s_copy(&__global_state->f2c, error, string, error_len, string_len);
	i__1 = __state->e + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->b, error, error_len, (
		ftnlen)1, error_len);
	prefix_(__global_state, "The substring \"#\" could not be resolved i"
		"n the input string: ' ", &__state->c__0, error, (ftnlen)63, 
		error_len);
	suffix_(__global_state, "'", &__state->c__0, error, (ftnlen)1, 
		error_len);
	repmc_(__global_state, error, "#", string + (__state->b - 1), error, 
		error_len, (ftnlen)1, __state->e - (__state->b - 1), 
		error_len);
	s_copy(&__global_state->f2c, pictur, " ", pictur_len, (ftnlen)1);
	return 0;
    }
    if (zzist_(__global_state, "m", (ftnlen)1) && zzist_(__global_state, 
	    "d", (ftnlen)1)) {
	*succes = FALSE_;
	*ntvec = 0;
	s_copy(&__global_state->f2c, type__, " ", type_len, (ftnlen)1);
	s_copy(&__global_state->f2c, error, string, error_len, string_len);
	__state->resolv = zznote_(__global_state, "m", &__state->b1, &
		__state->e1, (ftnlen)1);
	__state->resolv = zznote_(__global_state, "d", &__state->b2, &
		__state->e2, (ftnlen)1);
	__state->b = max(__state->b1,__state->b2);
	__state->e = max(__state->e1,__state->e2);
	i__1 = __state->e + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->b, error, error_len, (
		ftnlen)1, error_len);
	__state->b = min(__state->b1,__state->b2);
	__state->e = min(__state->e1,__state->e2);
	i__1 = __state->e + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->b, error, error_len, (
		ftnlen)1, error_len);
	prefix_(__global_state, "Both a month \"#\" and day of year delimite"
		"r \"#\" appear in the input string: ' ", &__state->c__0, 
		error, (ftnlen)77, error_len);
	suffix_(__global_state, "'", &__state->c__0, error, (ftnlen)1, 
		error_len);
	repmc_(__global_state, error, "#", string + (__state->b1 - 1), error, 
		error_len, (ftnlen)1, __state->e1 - (__state->b1 - 1), 
		error_len);
	repmc_(__global_state, error, "#", string + (__state->b2 - 1), error, 
		error_len, (ftnlen)1, __state->e2 - (__state->b2 - 1), 
		error_len);
	s_copy(&__global_state->f2c, pictur, " ", pictur_len, (ftnlen)1);
	return 0;
    }

/*     Make the remaining obvious substitutions for hours, */
/*     minutes, and seconds */

    if (zzrept_(__global_state, "i:i:i:n", "D*H*M*S", &__state->r2l, (ftnlen)
	    7, (ftnlen)7)) {
    } else if (zzrept_(__global_state, "i:i:i:i", "D*H*M*S", &__state->r2l, (
	    ftnlen)7, (ftnlen)7)) {
    } else if (zzrept_(__global_state, "i:i:n", "H*M*S", &__state->r2l, (
	    ftnlen)5, (ftnlen)5)) {
    } else if (zzrept_(__global_state, "i:i:i", "H*M*S", &__state->r2l, (
	    ftnlen)5, (ftnlen)5)) {
    } else if (zzrept_(__global_state, "i:n", "H*M", &__state->r2l, (ftnlen)3,
	     (ftnlen)3)) {
    } else if (zzrept_(__global_state, "i:i", "H*M", &__state->r2l, (ftnlen)3,
	     (ftnlen)3)) {
    }
    __state->resolv = zzremt_(__global_state, ":", (ftnlen)1);

/*     Handle the obvious substitutions of an integer next to */
/*     a Month. */

    if (zzsubt_(__global_state, "<miiH", "mDY", &__state->l2r, (ftnlen)5, (
	    ftnlen)3)) {
    } else if (zzsubt_(__global_state, "<mi", "mD", &__state->l2r, (ftnlen)3, 
	    (ftnlen)2)) {
    } else if (zzsubt_(__global_state, "Siim>", "SYDm", &__state->l2r, (
	    ftnlen)5, (ftnlen)4)) {
    } else if (zzsubt_(__global_state, "im>", "Dm", &__state->l2r, (ftnlen)3, 
	    (ftnlen)2)) {
    } else if (zzsubt_(__global_state, "miY>", "mDY", &__state->l2r, (ftnlen)
	    4, (ftnlen)3)) {
    } else if (zzsubt_(__global_state, "Ymi", "YmD", &__state->l2r, (ftnlen)3,
	     (ftnlen)3)) {
    } else if (zzsubt_(__global_state, "Smi", "SmD", &__state->l2r, (ftnlen)3,
	     (ftnlen)3)) {
    } else if (zzsubt_(__global_state, "Mmi", "MmD", &__state->l2r, (ftnlen)3,
	     (ftnlen)3)) {
    } else if (zzsubt_(__global_state, "imY", "DmY", &__state->l2r, (ftnlen)3,
	     (ftnlen)3)) {
    } else if (zzsubt_(__global_state, "imH", "DmH", &__state->l2r, (ftnlen)3,
	     (ftnlen)3)) {
    } else if (zzrept_(__global_state, "Yid", "Yy*", &__state->l2r, (ftnlen)3,
	     (ftnlen)3)) {
    } else if (zzrept_(__global_state, "iYd", "yY*", &__state->l2r, (ftnlen)3,
	     (ftnlen)3)) {
    } else if (zzrept_(__global_state, "Ydi", "Y*y", &__state->l2r, (ftnlen)3,
	     (ftnlen)3)) {
    }

/*     That's it we let ZZUNPCK handle the problem of diagnosing */
/*     or decoding the current representation. */

    *succes = zzunpck_(__global_state, string, yabbrv, tvec, ntvec, type__, 
	    pictur, error, string_len, type_len, pictur_len, error_len);
    if (s_cmp(&__global_state->f2c, pictur, " ", pictur_len, (ftnlen)1) != 0) 
	    {
	if (i_indx(&__global_state->f2c, pictur, ".#", pictur_len, (ftnlen)2) 
		!= 0) {
	    suffix_(__global_state, "::RND", &__state->c__1, pictur, (ftnlen)
		    5, pictur_len);
	}
	if (s_cmp(&__global_state->f2c, modify + (modify_len << 1), " ", 
		modify_len, (ftnlen)1) != 0) {
	    suffix_(__global_state, "::", &__state->c__1, pictur, (ftnlen)2, 
		    pictur_len);
	    suffix_(__global_state, modify + (modify_len << 1), &
		    __state->c__0, pictur, modify_len, pictur_len);
	}
	if (s_cmp(&__global_state->f2c, modify + (modify_len << 2), " ", 
		modify_len, (ftnlen)1) != 0) {
	    suffix_(__global_state, "::", &__state->c__1, pictur, (ftnlen)2, 
		    pictur_len);
	    suffix_(__global_state, modify + (modify_len << 2), &
		    __state->c__0, pictur, modify_len, pictur_len);
	}
    }
    return 0;
} /* tpartv_ */

