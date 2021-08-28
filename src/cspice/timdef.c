/* timdef.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern timdef_init_t __timdef_init;
static inline timdef_state_t* get_timdef_state(cspice_t* state) {
	if (!state->timdef)
		state->timdef = __cspice_allocate_module(sizeof(
	timdef_state_t), &__timdef_init, sizeof(__timdef_init));
	return state->timdef;

}

/* $Procedure      TIMDEF ( Time Software Defaults ) */
/* Subroutine */ int timdef_(cspice_t* __global_state, char *action, char *
	item, char *value, ftnlen action_len, ftnlen item_len, ftnlen 
	value_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);

    /* Local variables */
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int ucase_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int ljust_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern integer isrchc_(cspice_t*, char *, integer *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int prefix_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int zzutcpm_(cspice_t*, char *, integer *, 
	    doublereal *, doublereal *, integer *, logical *, ftnlen);


    /* Module state */
    timdef_state_t* __state = get_timdef_state(__global_state);
/* $ Abstract */

/*     Set and retrieve the defaults associated with calendar */
/*     input strings. */

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
/*     ACTION     I   is the kind of action to take 'SET' or 'GET'. */
/*     ITEM       I   is the default item of interest. */
/*     VALUE     I/O  is the value associated with the default item. */

/* $ Detailed_Input */

/*     ACTION     is a word that specifies whether TIMDEF sets the */
/*                value associated with ITEM or retrieves the value */
/*                associated with ITEM.  The allowed values for */
/*                ACTION are 'SET' and 'GET'.  The routine is not */
/*                sensitive to the case of the letters in ACTION. */

/*     ITEM       is the default items whose value should be set or */
/*                retrieved.  The items that may be requested are: */

/*                ITEM        Allowed Values */
/*                ---------   -------------- */
/*                CALENDAR    GREGORIAN */
/*                            JULIAN */
/*                            MIXED */

/*                SYSTEM      TDB */
/*                            TDT */
/*                            UTC */

/*                ZONE        EST, EDT, CST, CDT, MST, MDT, PST, PDT */
/*                            UTC+HR */
/*                            UTC-HR       ( 0 <= HR < 13 ) */
/*                            UTC+HR:MN    ( 0 <= MN < 60 ) */
/*                            UTC-HR:MN */

/*                The case of ITEM is not significant. */


/*     VALUE      if the action is 'SET' then VALUE is an input and */
/*                is the value to be associated with ITEM.  Note that */
/*                VALUE is checked to ensure it is within the range */
/*                of allowed values for ITEM.  If it is not within */
/*                the expected range and appropriate error message */
/*                is signalled.  The case of VALUE is not significant. */

/* $ Detailed_Output */

/*     VALUE      if the action is 'GET' then VALUE will be the */
/*                value associated with the requested ITEM.  Note that */
/*                when time zones are set, they are translated to the */
/*                UTC offset form ( UTC(+/-)HR[:MN] ).  When VALUE is */
/*                an output it will be in upper case. */

/* $ Parameters */

/*     None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     1) If the ACTION specified is not SET or GET the error */
/*        'SPICE(BADACTION)' is signalled. */

/*     2) If the ITEM specified is not one the recognized items */
/*        the error 'SPICE(BADTIMEITEM)' is signalled. */

/*     3) If the value associated with a 'SET', item input */
/*        is not one of the recognized items, the error */
/*        'SPICE(BADDEFAULTVALUE)' is signalled. */

/* $ Particulars */

/*     This routine exists to allow SPICE toolkit users to alter */
/*     the default interpretation of time strings made by the */
/*     routine STR2ET. */

/*     Normally, unlabelled time strings are assumed to belong to */
/*     the Gregorian Calendar and are UTC times.  However, you */
/*     may alter the default behavior by calling TIMDEF. */

/*     Calendar */
/*     -------- */

/*     You may set the calendar to be one of the following */

/*     Gregorian   --- This is the calendar used daily the */
/*                     Western Hemisphere.  Leap years occur in this */
/*                     calendar every 4 years except on centuries */
/*                     such as 1900 that are not divisible by 400. */

/*     Julian      --- This is the calendar that was in use prior */
/*                     to October 15, 1582.  Leap years occur every */
/*                     4 years on the Julian Calendar (including all */
/*                     centuries.)  October 5, 1582 on the Julian */
/*                     calendar corresponds to October 15, 1582 of the */
/*                     Gregorian Calendar. */

/*     Mixed       --- This calendar uses the Julian calendar */
/*                     for days prior to October 15, 1582 and */
/*                     the Gregorian calendar for days on or after */
/*                     October 15, 1582. */

/*     To set the default calendar, select on of the above for VALUE */
/*     and make the following call. */

/*        CALL TIMDEF ( 'SET', 'CALENDAR', VALUE ) */


/*     System */
/*     ------- */

/*     You may set the system used for keeping time to be UTC (default) */
/*     TDB (barycentric dynamical time) or TDT (terrestrial dynamical */
/*     time).  Both TDB and TDT have no leapseconds.  As such the time */
/*     elapsed between any two epochs on these calendars does not depend */
/*     upon when leapseconds occur. */

/*     To set the default time system, select TDT, TDB or UTC for VALUE */
/*     and make the following call. */

/*        CALL TIMDEF ( 'SET', 'SYSTEM', VALUE ) */

/*     Note that such a call has the side effect of setting the value */
/*     associated with ZONE to a blank. */

/*     Zone */
/*     ----- */

/*     You may alter the UTC system by specifying a time zone (UTC */
/*     offset).  For example you may specify that epochs are referred */
/*     to Pacific Standard Time (PST --- UTC-7).  The standard */
/*     abbreviations for U.S. time zones are recognized: */

/*        EST   UTC-5 */
/*        EDT   UTC-4 */
/*        CST   UTC-6 */
/*        CDT   UTC-5 */
/*        MST   UTC-7 */
/*        MDT   UTC-6 */
/*        PST   UTC-8 */
/*        PDT   UTC-7 */

/*     In addition you may specify any commercial time zone by using */
/*     "offset" notation.  This notation starts with the letters 'UTC' */
/*     followed by a + for time zones east of Greenwich and - for */
/*     time zones west of Greenwich.  This is followed by the number */
/*     of hours to add or subtract from UTC.  This is optionally followed */
/*     by a colon ':' and the number of minutes to add or subtract (based */
/*     on the sign that follows 'UTC') to get the */
/*     local time zone.  Thus to specify the time zone of Calcutta you */
/*     would specify the time zone to be UTC+5:30.  To specify the */
/*     time zone of Newfoundland use the time zone UTC-3:30. */

/*     To set a default time zone, select one of the "built-in" U.S. */
/*     zones or construct an offset as discussed above.  Then make the */
/*     call */

/*        CALL TIMDEF ( 'SET', 'ZONE', VALUE ) */

/*     If you 'GET' a 'ZONE' it will either be blank, or have the */
/*     form 'UTC+/-HR[:MN]' */

/*     Note that such a call has the side effect of setting the value */
/*     associated with SYSTEM to a blank. */

/* $ Examples */

/*     Suppose you wish to modify the behavior of STR2ET so that */
/*     it interprets unlabeled time strings as being times in */
/*     Pacific Daylight Time and that you want the calendar to use */
/*     to be the "Mixed" calendar.  The following two calls will */
/*     make the desired changes to the behavior of STR2ET */

/*         CALL TIMDEF ( 'SET', 'CALENDAR', 'MIXED' ) */
/*         CALL TIMDEF ( 'SET', 'ZONE',     'PDT'   ) */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.2.0, 26-MAY-1998 (WLT) */

/*        The previous version did not check out and return */
/*        when an error was detected in the if block that */
/*        begins with */

/*           ELSE IF ( MYITEM .EQ. 'ZONE' ) THEN */

/*        The routine did eventually check out and return so */
/*        that the trace stack was maintained correctly, but */
/*        the default time zone would be modified which was not */
/*        the desired behavior. */

/* -    SPICELIB Version 1.1.0, 27-JUN-1997 (WLT) */

/*        The previous version failed to check out when */
/*        the default value was set. */

/* -    SPICELIB Version 1.0.0, 13-NOV-1996 (WLT) */


/* -& */
/* $ Index_Entries */

/*     Change time software defaults. */
/*     Time Zones */
/*     Gregorian and Julian Calendars */

/* -& */


/*     SPICELIB Functions */


/*     Local Variables. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "TIMDEF", (ftnlen)6);

/*     Normalize the input. */

    ljust_(__global_state, action, __state->myactn, action_len, (ftnlen)16);
    ucase_(__global_state, __state->myactn, __state->myactn, (ftnlen)16, (
	    ftnlen)16);
    ljust_(__global_state, item, __state->myitem, item_len, (ftnlen)16);
    ucase_(__global_state, __state->myitem, __state->myitem, (ftnlen)16, (
	    ftnlen)16);
    ljust_(__global_state, value, __state->myval, value_len, (ftnlen)16);
    ucase_(__global_state, __state->myval, __state->myval, (ftnlen)16, (
	    ftnlen)16);

/*     Admittedly, the decision making below is not very elegant. */
/*     However, this works and is simpler than anything that comes */
/*     to mind at the moment and allows us to give quite specific */
/*     diagnostic messages easily. */

    if (s_cmp(&__global_state->f2c, __state->myactn, "SET", (ftnlen)16, (
	    ftnlen)3) == 0) {
	if (s_cmp(&__global_state->f2c, __state->myitem, "SYSTEM", (ftnlen)16,
		 (ftnlen)6) == 0) {
	    if (s_cmp(&__global_state->f2c, __state->myval, "TDB", (ftnlen)16,
		     (ftnlen)3) == 0 || s_cmp(&__global_state->f2c, 
		    __state->myval, "TDT", (ftnlen)16, (ftnlen)3) == 0 || 
		    s_cmp(&__global_state->f2c, __state->myval, "UTC", (
		    ftnlen)16, (ftnlen)3) == 0) {
		s_copy(&__global_state->f2c, __state->defzon, " ", (ftnlen)16,
			 (ftnlen)1);
		s_copy(&__global_state->f2c, __state->defsys, __state->myval, 
			(ftnlen)16, (ftnlen)16);
	    } else {
		setmsg_(__global_state, "The default value assigned to the t"
			"ime system must be one of 'UTC', 'TDT', or 'TDB'. Th"
			"e value supplied was '#'. ", (ftnlen)113);
		errch_(__global_state, "#", value, (ftnlen)1, value_len);
		sigerr_(__global_state, "SPICE(BADDEFAULTVALUE)", (ftnlen)22);
		chkout_(__global_state, "TIMDEF", (ftnlen)6);
		return 0;
	    }
	} else if (s_cmp(&__global_state->f2c, __state->myitem, "ZONE", (
		ftnlen)16, (ftnlen)4) == 0) {
	    __state->zone = isrchc_(__global_state, __state->myval, &
		    __state->c__8, __state->zones, (ftnlen)16, (ftnlen)16);

/*           If MYVAL was one of the recognized time zones, we */
/*           translate it to the UTC offset form. */

	    if (__state->zone > 0) {
		s_copy(&__global_state->f2c, __state->myval, __state->trnslt 
			+ (((i__1 = __state->zone - 1) < 8 && 0 <= i__1 ? 
			i__1 : s_rnge(&__global_state->f2c, "trnslt", i__1, 
			"timdef_", (ftnlen)387)) << 4), (ftnlen)16, (ftnlen)
			16);
	    }
	    prefix_(__global_state, "::", &__state->c__0, __state->myval, (
		    ftnlen)2, (ftnlen)16);
	    zzutcpm_(__global_state, __state->myval, &__state->c__1, &
		    __state->hoff, &__state->moff, &__state->last, &
		    __state->succes, (ftnlen)16);
	    if (! __state->succes) {
		setmsg_(__global_state, "The input value for a time zone \""
			"#\" was not recognized as known time zone and could "
			"not be parsed according to the pattern UTC(+/-)HR[:M"
			"N]. Known time zones are: 'EST', 'EDT', 'CST', 'CDT'"
			", 'MST', 'MDT', 'PST', and 'PDT'. ", (ftnlen)222);
		errch_(__global_state, "#", value, (ftnlen)1, value_len);
		sigerr_(__global_state, "SPICE(BADDEFAULTVALUE)", (ftnlen)22);
		chkout_(__global_state, "TIMDEF", (ftnlen)6);
		return 0;
	    }
	    s_copy(&__global_state->f2c, __state->defzon, __state->myval + 2, 
		    (ftnlen)16, (ftnlen)14);
	    s_copy(&__global_state->f2c, __state->defsys, " ", (ftnlen)16, (
		    ftnlen)1);
	} else if (s_cmp(&__global_state->f2c, __state->myitem, "CALENDAR", (
		ftnlen)16, (ftnlen)8) == 0) {
	    if (s_cmp(&__global_state->f2c, __state->myval, "JULIAN", (ftnlen)
		    16, (ftnlen)6) == 0 || s_cmp(&__global_state->f2c, 
		    __state->myval, "GREGORIAN", (ftnlen)16, (ftnlen)9) == 0 
		    || s_cmp(&__global_state->f2c, __state->myval, "MIXED", (
		    ftnlen)16, (ftnlen)5) == 0) {
		s_copy(&__global_state->f2c, __state->defcal, __state->myval, 
			(ftnlen)16, (ftnlen)16);
	    } else {
		setmsg_(__global_state, "The input value for '#' is not a re"
			"cognized calendar type.  The recognized calendars ar"
			"e 'GREGORIAN', 'JULIAN', and 'MIXED'. ", (ftnlen)125);
		errch_(__global_state, "#", value, (ftnlen)1, value_len);
		sigerr_(__global_state, "SPICE(BADDEFAULTVALUE)", (ftnlen)22);
		chkout_(__global_state, "TIMDEF", (ftnlen)6);
		return 0;
	    }
	} else {
	    setmsg_(__global_state, "The specified item '#' is not a recogni"
		    "zed time default item.  The items that you may \"SET\" v"
		    "ia the routine TIMDEF are 'CALENDAR', 'SYSTEM', or 'ZONE"
		    "' ", (ftnlen)151);
	    errch_(__global_state, "#", item, (ftnlen)1, item_len);
	    sigerr_(__global_state, "SPICE(BADTIMEITEM)", (ftnlen)18);
	    chkout_(__global_state, "TIMDEF", (ftnlen)6);
	    return 0;
	}
	chkout_(__global_state, "TIMDEF", (ftnlen)6);
	return 0;
    } else if (s_cmp(&__global_state->f2c, __state->myactn, "GET", (ftnlen)16,
	     (ftnlen)3) == 0) {
	if (s_cmp(&__global_state->f2c, __state->myitem, "CALENDAR", (ftnlen)
		16, (ftnlen)8) == 0) {
	    s_copy(&__global_state->f2c, value, __state->defcal, value_len, (
		    ftnlen)16);
	} else if (s_cmp(&__global_state->f2c, __state->myitem, "SYSTEM", (
		ftnlen)16, (ftnlen)6) == 0) {
	    s_copy(&__global_state->f2c, value, __state->defsys, value_len, (
		    ftnlen)16);
	} else if (s_cmp(&__global_state->f2c, __state->myitem, "ZONE", (
		ftnlen)16, (ftnlen)4) == 0) {
	    s_copy(&__global_state->f2c, value, __state->defzon, value_len, (
		    ftnlen)16);
	} else {
	    setmsg_(__global_state, "The specified item '#' is not a recogni"
		    "zed time default item.  The items that you may \"SET\" v"
		    "ia the routine TIMDEF are 'CALENDAR', 'SYSTEM', or 'ZONE"
		    "' ", (ftnlen)151);
	    errch_(__global_state, "#", item, (ftnlen)1, item_len);
	    sigerr_(__global_state, "SPICE(BADTIMEITEM)", (ftnlen)18);
	    chkout_(__global_state, "TIMDEF", (ftnlen)6);
	    return 0;
	}
    } else {
	setmsg_(__global_state, "The action speficied to TIMDEF was '#'.  Th"
		"is is not a recognized action. The recognized actions are 'S"
		"ET' and 'GET'. ", (ftnlen)118);
	errch_(__global_state, "#", action, (ftnlen)1, action_len);
	sigerr_(__global_state, "SPICE(BADACTION)", (ftnlen)16);
	chkout_(__global_state, "TIMDEF", (ftnlen)6);
	return 0;
    }
    chkout_(__global_state, "TIMDEF", (ftnlen)6);
    return 0;
} /* timdef_ */

