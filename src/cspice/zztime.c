/* zztime.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zztime_init_t __zztime_init;
static zztime_state_t* get_zztime_state(cspice_t* state) {
	if (!state->zztime)
		state->zztime = __cspice_allocate_module(sizeof(
	zztime_state_t), &__zztime_init, sizeof(__zztime_init));
	return state->zztime;

}

/* $Procedure ZZTIME ( Private, Time --- time parsing utilities ) */
logical zztime_0_(cspice_t* __global_state, int n__, char *string, char *
	transl, char *letter, char *error, char *pic, doublereal *tvec, 
	integer *b, integer *e, logical *l2r, logical *yabbrv, ftnlen 
	string_len, ftnlen transl_len, ftnlen letter_len, ftnlen error_len, 
	ftnlen pic_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3;
    logical ret_val;

    /* Builtin functions */
    integer i_len(f2c_state_t*, char *, ftnlen), s_rnge(f2c_state_t*, char *, 
	    integer, char *, integer);
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer i_indx(f2c_state_t*, char *, char *, ftnlen, ftnlen), s_cmp(
	    f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern integer cpos_(cspice_t*, char *, char *, integer *, ftnlen, ftnlen)
	    ;
    extern integer posr_(cspice_t*, char *, char *, integer *, ftnlen, ftnlen)
	    ;
    extern /* Subroutine */ int zzrepsub_(cspice_t*, char *, integer *, 
	    integer *, char *, char *, ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int zzinssub_(cspice_t*, char *, char *, integer *
	    , char *, ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int zztknerr_(cspice_t*, char *, char *, char *, 
	    char *, logical *, ftnlen, ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int ucase_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int repmc_(cspice_t*, char *, char *, char *, 
	    char *, ftnlen, ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int repmi_(cspice_t*, char *, char *, integer *, 
	    char *, ftnlen, ftnlen, ftnlen);
    extern integer rtrim_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int lx4uns_(cspice_t*, char *, integer *, integer 
	    *, integer *, ftnlen);
    extern logical samchi_(cspice_t*, char *, integer *, char *, integer *, 
	    ftnlen, ftnlen);
    extern integer isrchc_(cspice_t*, char *, integer *, char *, ftnlen, 
	    ftnlen);
    extern logical samsbi_(cspice_t*, char *, integer *, integer *, char *, 
	    integer *, integer *, ftnlen, ftnlen);
    extern /* Subroutine */ int nparsd_(cspice_t*, char *, doublereal *, char 
	    *, integer *, ftnlen, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int nparsi_(cspice_t*, char *, integer *, char *, 
	    integer *, ftnlen, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int prefix_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    extern /* Subroutine */ int suffix_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    extern /* Subroutine */ int zzmkpc_(cspice_t*, char *, integer *, integer 
	    *, char *, char *, ftnlen, ftnlen, ftnlen);
    extern integer pos_(cspice_t*, char *, char *, integer *, ftnlen, ftnlen);

    /* Module state */
    zztime_state_t* __state = get_zztime_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     This is an umbrella routine for a collection of entry points */
/*     to the time parsing utility functions. */

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

/*      TIME --- Private */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  Entry Points */
/*     --------  ---  -------------------------------------------------- */
/*     STRING    I/O  ZZUNPCK ZZCMBT ZZGREP ZZISPT  ZZSUBT ZZTOKNS ZZVALT */
/*     TRANSL     I   ZZUNPCK ZZSUBT */
/*     LETTER     I   ZZCMBT  ZZIST   ZZNOTE  ZZREMT ZZVALT */
/*     ERROR      O   ZZUNPCK ZZTOKNS */
/*     TVEC       O   ZZUNPCK */
/*     B          O   ZZISPT  ZZNOTE  ZZVALT */
/*     E          O   ZZISPT  ZZNOTE  ZZUNPCK ZZVALT */
/*     L2R        I   ZZCMBT  ZZSUBT */
/*     YABBRV     I   ZZUNPCK */

/* $ Detailed_Input */

/*     See Individual Entry Points. */

/* $ Detailed_Output */

/*     See Individual Entry Points. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If ZZTIME is called directly the error 'SPICE(BOGUSENTRY)' */
/*         is signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine serves as an umbrella for a collection of */
/*     related entry points that are used to parse time strings. */

/*     Normal usage is to first call ZZTOKNS to create an internal */
/*     representation for a time string. This internal representations */
/*     maintains a list of identified substrings from the original */
/*     input time string. For example the call to ZZTOKNS using */
/*     the string */

/*       '1996 JAN 25 12:18:19.199' */
/*        123456789012345678901234 */

/*     yields the following internal representation: */

/*       'ibmbibi:i:i.i' */

/*     where the individual tokens correspond to the substrings */
/*     indicated in the following table: */

/*       Identifier    Substring          meaning */
/*       ----------    -------------      ---------------- */
/*         i           from 01 to 04      unsigned integer */
/*         b           from 05 to 05      blanks or tab */
/*         m           from 06 to 08      month */
/*         b           from 09 to 09      blanks or tab */
/*         i           from 10 to 11      unsigned integer */
/*         b           from 12 to 12      blank or tab */
/*         i           from 13 to 14      unsigned integer */
/*         :           from 15 to 15      colon */
/*         i           from 16 to 17      unsigned integer */
/*         :           from 18 to 18      colon */
/*         i           from 19 to 20      unsigned integer */
/*         .           from 21 to 21      decimal point */
/*         i           from 22 to 24      unsigned integer */

/*     These substrings may be combined and reidentified, removed */
/*     or re-identified using the various entry points listed here: */

/*     ZZCMBT   combine several tokens into a single token */
/*              for example you might scan right to left and replace */
/*              the token sequence i.i by n (for number). In this */
/*              case the substring boundaries of n would be from 19 */
/*              to 24. */

/*     ZZGREP   returns the current internal representation */
/*              in the case above 'ibmbibi:i:i.i' */


/*     ZZISPT   returns TRUE if a pair of letters from a list are */
/*              present in the internal representation. This is */
/*              used primarily to detect erroneous substrings such */
/*              as ',,' or ':,' */

/*     ZZIST    Return TRUE if a particular letter is present in the */
/*              string. */

/*     ZZNOTE   Returns the substring boundaries associated with */
/*              a letter and removes the letter from the internal */
/*              representation. This is used primarily for calendar */
/*              string modifiers such as 'B.C.', 'A.D.' etc. */

/*     ZZREMT   remove a letter from the internal representation. */
/*              In the input example you might remove all white space */
/*              markers. */

/*     ZZSUBT   substitute a different letter for one listed in the */
/*              input one for one. For example after removing blanks */
/*              you might substitute YmD for imi. */


/*     ZZVALT   replace an integer by a new marker if the integer */
/*              lies withing a particular range. For example */
/*              you might replace any integer between 1000 and 10000 */
/*              by Y (for year). */

/*     Once all substitutions and removals have been performed that */
/*     can be made, the entry point ZZUNPCK allows you to extract */
/*     year(Y), month(m), day or month(D), day of year (y), hours(H), */
/*     minutes(M) and seconds(S) from the input string */

/* $ Examples */

/*     See TPARTV. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     B.V. Semenov    (JPL) */
/*     W.L. Taber      (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.6.0, 05-FEB-2014 (EDW) (BVS) */

/*        BUG FIX: entry point ZZUNPCK: added error check on ITEM value. */
/*        Failure to perform this check can cause BADSUBSCRIPT error */
/*        signals from CSPICE code on invalid time strings. */

/*        BUG FIX: entry point ZZTOKNS: added checks for token indexes */
/*        overflowing the maximum number of tokens and for the character */
/*        positions in the time picture overflowing the time picture */
/*        length. Both overflows previously resulted in segmentation */
/*        faults for invalid input time strings that contained too many */
/*        recognizable tokens or were too long and required too many */
/*        characters in the picture representation. */

/* -    SPICELIB Version 1.5.0, 08-MAR-2009 (NJB) */

/*        Bug fix: in entry point ZZTOKNS, changed upper */
/*        bound used to detect non-printing characters from 128 */
/*        to 126. */

/*        Bug fix: added error handling to this routine. Header */
/*        already referred to SPICE(BOGUSENTRY) error, but no */
/*        such error was signaled. */

/*        Changed upper bound of arrays NAMES, F, and L from 128 */
/*        to 126. */

/*        Re-ordered header sections in various entry points. */

/* -    SPICELIB Version 1.4.0, 27-OCT-2006 (BVS) */

/*        Fixed the bug in the ZZTOKNS entry that in the case of a one */
/*        character long blank input time string caused the TO variable */
/*        be set to the value greater than the string length, triggering */
/*        an OUT OF BOUNDS runtime error on HP. Added to ZZTOKNS a */
/*        separate check for the blank input strings. */

/* -    SPICELIB Version 1.3.0, 13-Nov-2000 (WLT) */

/*        Changed the call to EQSTR to a call to SAMSBI so as to */
/*        guard against overflowing strings. */

/* -    SPICELIB Version 1.2.0, 09-DEC-1999 (WLT) */

/*        The main routine (which should never be called) now returns */
/*        the value .FALSE. */

/* -    SPICELIB Version 1.1.0, 30-JUN-1999 (WLT) */

/*        Added a RETURN statement at the end of the main routine. */
/*        Enhanced error message for the case when the input string */
/*        to ZZTOKNS has a non-printing character. */

/* -    SPICELIB Version 1.0.0, 8-APR-1996 (WLT) */

/* -& */

/*     Entry points */


/*     SPICELIB Functions */


/*     Standard Parameters */


/*     LOWER */
/*     UPPER */
/*     MIXED */


/*     FULL */
/*     SHORT */


/*     Maximum number of tokens that a valid time string can contain. */


/*     Length of the string buffer containing the time string picture. */


/*     Representation Variables. */


/*     Token Recognition Variables. */

/*     At the moment there are 53 recognized substrings, we */
/*     make room for 70 just so we won't have to increase */
/*     the parameter NRECOG soon. */

    /* Parameter adjustments */
    if (tvec) {
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_zzcmbt;
	case 2: goto L_zzgrep;
	case 3: goto L_zzispt;
	case 4: goto L_zzist;
	case 5: goto L_zznote;
	case 6: goto L_zzremt;
	case 7: goto L_zzsubt;
	case 8: goto L_zztokns;
	case 9: goto L_zzunpck;
	case 10: goto L_zzvalt;
	}

    ret_val = FALSE_;
    chkin_(__global_state, "ZZTIME", (ftnlen)6);
    sigerr_(__global_state, "SPICE(BOGUSENTRY)", (ftnlen)17);
    chkout_(__global_state, "ZZTIME", (ftnlen)6);
    return ret_val;
/* $Procedure ZZCMBT ( Private, Time --- combine tokens ) */

L_zzcmbt:
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Combine several token representatives into a single token. */

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

/*      TIME --- PRIVATE */


/* $ Declarations */

/*     CHARACTER*(*)         STRING */
/*     CHARACTER*(1)         LETTER */
/*     LOGICAL               L2R */

/* $ Brief_I/O */
/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     STRING     I   A sequence of tokens to be combined. */
/*     LETTER     I   The replacement token for the combination */
/*     L2R        I   If TRUE scan left to right, else scan right to left */

/*     The function returns TRUE is a combination was performed. */

/* $ Detailed_Input */

/*     STRING     is a sequence of tokens to look for in the */
/*                stored internal representation. */

/*     LETTER     is the replacement token to insert for STRING. */

/*                If letter is a blank, the combination is simply */
/*                replaced by a blank. */

/*     L2R        is a logical. If TRUE, the internal representation */
/*                is scanned left to right. If FALSE, the internal */
/*                representation is scanned right to left. */

/* $ Detailed_Output */

/*     The function returns TRUE if a combination is performed. */
/*     Otherwise it returns FALSE. */

/*     Note that the most important action of this function is a */
/*     side-effect. The internal representation of a time string */
/*     is modified to reflect the requested token combination. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error Free. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This function allows you to alter the internal representation */
/*     of a time string by combining two or more tokens into a single */
/*     token. */

/* $ Examples */

/*     See TPARTV */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.2.1, 08-MAR-2009 (NJB) */

/*        Re-ordered header sections. */

/* -    SPICELIB Version 1.2.0, 09-DEC-1999 (WLT) */

/*        The main routine (which should never be called) now returns */
/*        the value .FALSE. */

/* -    SPICELIB Version 1.1.0, 30-JUN-1999 (WLT) */

/*        Added a RETURN statement at the end of the main routine. */
/*        Enhanced error message for the case when the input string */
/*        to ZZTOKNS has a non-printing character. */

/* -    SPICELIB Version 1.0.0, 4-APR-1996 (WLT) */


/* -& */

/*     So far we haven't combined anything. */

    __state->did = FALSE_;

/*     Look for the substring either looking from the */
/*     left (L2R is YES) or from the right (L2R is NO). */

    if (*l2r) {
	__state->from = pos_(__global_state, __state->rep, string, &
		__state->c__1, __state->size, string_len);
    } else {
	__state->from = posr_(__global_state, __state->rep, string, &
		__state->size, __state->size, string_len);
    }
    __state->to = __state->from + i_len(&__global_state->f2c, string, 
	    string_len) - 1;
    if (__state->from > 0) {
	__state->did = TRUE_;
	__state->ends[(i__1 = __state->from - 1) < 64 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "ends", i__1, "zztime_", (ftnlen)
		610)] = __state->ends[(i__2 = __state->to - 1) < 64 && 0 <= 
		i__2 ? i__2 : s_rnge(&__global_state->f2c, "ends", i__2, 
		"zztime_", (ftnlen)610)];
	__state->pends[(i__1 = __state->from - 1) < 64 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "pends", i__1, "zztime_", (
		ftnlen)611)] = __state->pends[(i__2 = __state->to - 1) < 64 &&
		 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "pends", 
		i__2, "zztime_", (ftnlen)611)];
	__state->put = __state->from + 1;
	__state->next = __state->to + 1;

/*        Perform the substitution in the representation */

	zzrepsub_(__global_state, __state->rep, &__state->from, &__state->to, 
		letter, __state->rep, (ftnlen)64, (ftnlen)1, (ftnlen)64);

/*        Now update the begins and ends of tokens in the original */
/*        string. */

	i__1 = __state->size;
	for (__state->get = __state->next; __state->get <= i__1; 
		++__state->get) {
	    __state->begs[(i__2 = __state->put - 1) < 64 && 0 <= i__2 ? i__2 :
		     s_rnge(&__global_state->f2c, "begs", i__2, "zztime_", (
		    ftnlen)625)] = __state->begs[(i__3 = __state->get - 1) < 
		    64 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "begs", i__3, "zztime_", (ftnlen)625)];
	    __state->ends[(i__2 = __state->put - 1) < 64 && 0 <= i__2 ? i__2 :
		     s_rnge(&__global_state->f2c, "ends", i__2, "zztime_", (
		    ftnlen)626)] = __state->ends[(i__3 = __state->get - 1) < 
		    64 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "ends", i__3, "zztime_", (ftnlen)626)];
	    __state->pbegs[(i__2 = __state->put - 1) < 64 && 0 <= i__2 ? i__2 
		    : s_rnge(&__global_state->f2c, "pbegs", i__2, "zztime_", (
		    ftnlen)627)] = __state->pbegs[(i__3 = __state->get - 1) < 
		    64 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "pbegs", i__3, "zztime_", (ftnlen)627)];
	    __state->pends[(i__2 = __state->put - 1) < 64 && 0 <= i__2 ? i__2 
		    : s_rnge(&__global_state->f2c, "pends", i__2, "zztime_", (
		    ftnlen)628)] = __state->pends[(i__3 = __state->get - 1) < 
		    64 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "pends", i__3, "zztime_", (ftnlen)628)];
	    ++__state->put;
	}
	__state->size = __state->size - i_len(&__global_state->f2c, string, 
		string_len) + 1;
    }
    ret_val = __state->did;
    return ret_val;
/* $Procedure ZZGREP ( Private, Time --- get representation ) */

L_zzgrep:
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Return the internal representation of the time string. */

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

/*      TIME --- PRIVATE */


/* $ Declarations */

/*     CHARACTER*(*)         STRING */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     STRING     O   The current representation of tokenized time */

/* $ Detailed_Input */

/*     None. */

/* $ Detailed_Output */

/*     STRING     is the current internal tokenized representation of */
/*                the time string that was last supplied to ZZTIME */
/*                via the entry point ZZTOKNS. */

/*     The function returns TRUE. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This returns the current internal representation of the */
/*     tokenized time string. The function always returns the */
/*     value TRUE. */

/* $ Examples */

/*     See TPARTV. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.2.0, 09-DEC-1999 (WLT) */

/*        The main routine (which should never be called) now returns */
/*        the value .FALSE. */

/* -    SPICELIB Version 1.1.0, 30-JUN-1999 (WLT) */

/*        Added a RETURN statement at the end of the main routine. */
/*        Enhanced error message for the case when the input string */
/*        to ZZTOKNS has a non-printing character. */

/* -    SPICELIB Version 1.0.0, 4-APR-1996 (WLT) */


/* -& */
    s_copy(&__global_state->f2c, string, __state->rep, string_len, (max(1,
	    __state->size)));
    ret_val = TRUE_;
    return ret_val;
/* $Procedure ZZISPT ( Private, Time --- is pair of tokens ) */

L_zzispt:
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Determine if there is a pair of consecutive tokens from */
/*     a user specified list of tokens. */

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

/*      TIME --- PRIVATE */

/* $ Declarations */

/*     CHARACTER*(*)         STRING */
/*     INTEGER               B */
/*     INTEGER               E */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     STRING     I   a list of tokens to search for. */
/*     B          O   the beginning of the first matching token */
/*     E          O   the ending of the last matching token. */

/*     The function returns TRUE if a pair is found. */

/* $ Detailed_Input */

/*     STRING     is a character string that gives a list of tokens */
/*                to search for in a string. */

/* $ Detailed_Output */

/*     B          is the location in the original time string supplied */
/*                to ZZTOKNS of the beginning a pair of consecutive */
/*                tokens from the list specified by STRING. */

/*     E          is the location in the original time string supplied */
/*                to ZZTOKENS of the end a pair of consecutive */
/*                tokens from the list specified by STRING. */

/*     The function returns the TRUE is a consecutive pair of tokens */
/*     from STRING is located. Otherwise it returns FALSE. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error Free. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine exists primarily to assist in the diagnosis */
/*     of consecutive delimiters in a time string. */

/* $ Examples */

/*     See TPARTV */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.2.1, 08-MAR-2009 (NJB) */

/*        Re-ordered header sections. */

/* -    SPICELIB Version 1.2.0, 09-DEC-1999 (WLT) */

/*        The main routine (which should never be called) now returns */
/*        the value .FALSE. */

/* -    SPICELIB Version 1.1.0, 30-JUN-1999 (WLT) */

/*        Added a RETURN statement at the end of the main routine. */
/*        Enhanced error message for the case when the input string */
/*        to ZZTOKNS has a non-printing character. */

/* -    SPICELIB Version 1.0.0, 4-APR-1996 (WLT) */


/* -& */
    __state->did = FALSE_;
    __state->from = cpos_(__global_state, __state->rep, string, &
	    __state->c__1, (ftnlen)64, string_len);
    while(__state->from > 0) {
	if (__state->from < __state->size) {
	    __state->to = __state->from + 1;
	    __state->did = i_indx(&__global_state->f2c, string, __state->rep 
		    + (__state->to - 1), string_len, (ftnlen)1) > 0;
	} else {
	    *b = 0;
	    *e = 0;
	    ret_val = FALSE_;
	    return ret_val;
	}
	if (__state->did) {
	    *b = __state->begs[(i__1 = __state->from - 1) < 64 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "begs", i__1, "zztim"
		    "e_", (ftnlen)922)];
	    *e = __state->ends[(i__1 = __state->to - 1) < 64 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "ends", i__1, "zztim"
		    "e_", (ftnlen)923)];
	    ret_val = TRUE_;
	    return ret_val;
	}
	__state->from = cpos_(__global_state, __state->rep, string, &
		__state->to, (ftnlen)64, string_len);
    }
    *b = 0;
    *e = 0;
    ret_val = FALSE_;
    return ret_val;
/* $Procedure ZZIST ( Private, Time --- is there a token ) */

L_zzist:
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Determine if a token is present in the internal representation */
/*     of a tokenized time string. */

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

/*      TIME --- PRIVATE */


/* $ Declarations */

/*     CHARACTER*(1)         LETTER */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     LETTER     I */

/*     The function returns */

/* $ Detailed_Input */

/*     LETTER     is a token to look for in the tokenized representation */
/*                of a time string. */

/* $ Detailed_Output */

/*     The function returns TRUE is LETTER is present in the internal */
/*     representation of the last time string passed to ZZTOKNS. */
/*     Otherwise it returns FALSE. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine determines whether or not a particular token */
/*     is present in a tokenized representation of a time. */

/* $ Examples */

/*     See TPARTV */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.2.0, 09-DEC-1999 (WLT) */

/*        The main routine (which should never be called) now returns */
/*        the value .FALSE. */

/* -    SPICELIB Version 1.1.0, 30-JUN-1999 (WLT) */

/*        Added a RETURN statement at the end of the main routine. */
/*        Enhanced error message for the case when the input string */
/*        to ZZTOKNS has a non-printing character. */

/* -    SPICELIB Version 1.0.0, 4-APR-1996 (WLT) */


/* -& */
    ret_val = i_indx(&__global_state->f2c, __state->rep, letter, 
	    __state->size, (ftnlen)1) > 0;
    return ret_val;
/* $Procedure ZZNOTE ( Private, Time --- note the existence and remove ) */

L_zznote:
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Return the beginning and ending of a token in a time string */
/*     and remove the token from the internal representation. */

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

/*      TIME --- PRIVATE */

/* $ Declarations */

/*     CHARACTER*(1)         LETTER */
/*     INTEGER               B */
/*     INTEGER               E */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     LETTER     I   a token to look for in the internal representation */
/*     B          O   is the beginning of the token */
/*     E          O   is the end of the token. */

/*     The function returns TRUE if the token is located. */

/* $ Detailed_Input */

/*     LETTER     is a token to look for and remove from the */
/*                current tokenization of a time string. */

/*                If located the token is removed from the string. */

/*                Note that this simply finds the first matching */
/*                token. If others are present they are not */
/*                affected. */

/* $ Detailed_Output */

/*     B          is the beginning of the requested token if it */
/*                was found. Otherwise B is zero. */

/*     E          is the ending of the requested token if it was */
/*                found. Otherwise E is zero. */

/*     The function returns the value TRUE if the token is located. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     Look up and remove a token from the internal representation */
/*     of a time string. This is useful in removing modifiers */
/*     from a string (such as the ERA of an epoch, AM/PM of a time */
/*     etc.) */

/* $ Examples */

/*     See TPARTV */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.2.1, 08-MAR-2009 (NJB) */

/*        Re-ordered header sections. */

/* -    SPICELIB Version 1.2.0, 09-DEC-1999 (WLT) */

/*        The main routine (which should never be called) now returns */
/*        the value .FALSE. */

/* -    SPICELIB Version 1.1.0, 30-JUN-1999 (WLT) */

/*        Added a RETURN statement at the end of the main routine. */
/*        Enhanced error message for the case when the input string */
/*        to ZZTOKNS has a non-printing character. */

/* -    SPICELIB Version 1.0.0, 4-APR-1996 (WLT) */


/* -& */
    __state->put = i_indx(&__global_state->f2c, __state->rep, letter, (ftnlen)
	    64, (ftnlen)1);
    if (__state->put > 0) {
	*b = __state->begs[(i__1 = __state->put - 1) < 64 && 0 <= i__1 ? i__1 
		: s_rnge(&__global_state->f2c, "begs", i__1, "zztime_", (
		ftnlen)1212)];
	*e = __state->ends[(i__1 = __state->put - 1) < 64 && 0 <= i__1 ? i__1 
		: s_rnge(&__global_state->f2c, "ends", i__1, "zztime_", (
		ftnlen)1213)];
	__state->next = __state->put + 1;
	i__1 = __state->size;
	for (__state->get = __state->next; __state->get <= i__1; 
		++__state->get) {
	    __state->begs[(i__2 = __state->put - 1) < 64 && 0 <= i__2 ? i__2 :
		     s_rnge(&__global_state->f2c, "begs", i__2, "zztime_", (
		    ftnlen)1219)] = __state->begs[(i__3 = __state->get - 1) < 
		    64 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "begs", i__3, "zztime_", (ftnlen)1219)];
	    __state->ends[(i__2 = __state->put - 1) < 64 && 0 <= i__2 ? i__2 :
		     s_rnge(&__global_state->f2c, "ends", i__2, "zztime_", (
		    ftnlen)1220)] = __state->ends[(i__3 = __state->get - 1) < 
		    64 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "ends", i__3, "zztime_", (ftnlen)1220)];
	    __state->pbegs[(i__2 = __state->put - 1) < 64 && 0 <= i__2 ? i__2 
		    : s_rnge(&__global_state->f2c, "pbegs", i__2, "zztime_", (
		    ftnlen)1221)] = __state->pbegs[(i__3 = __state->get - 1) <
		     64 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "pbegs", i__3, "zztime_", (ftnlen)1221)];
	    __state->pends[(i__2 = __state->put - 1) < 64 && 0 <= i__2 ? i__2 
		    : s_rnge(&__global_state->f2c, "pends", i__2, "zztime_", (
		    ftnlen)1222)] = __state->pends[(i__3 = __state->get - 1) <
		     64 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "pends", i__3, "zztime_", (ftnlen)1222)];
	    *(unsigned char *)&__state->rep[__state->put - 1] = *(unsigned 
		    char *)&__state->rep[__state->get - 1];
	    ++__state->put;
	}
	s_copy(&__global_state->f2c, __state->rep + (__state->size - 1), 
		" ", 64 - (__state->size - 1), (ftnlen)1);
	--__state->size;
	__state->did = TRUE_;
    } else {
	*b = 0;
	*e = 0;
	__state->did = FALSE_;
    }
    ret_val = __state->did;
    return ret_val;
/* $Procedure ZZREMT ( Private, Time --- remove token ) */

L_zzremt:
/* $ Abstract */

/*    SPICE Private routine intended solely for the support of SPICE */
/*    routines. Users should not call this routine directly due */
/*    to the volatile nature of this routine. */

/*    Remove a specified token from the internal representation */

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

/*     TIME --- Private */


/* $ Declarations */

/*     CHARACTER*(1)         LETTER */

/* $ Brief_I/O */
/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     LETTER     I   token to remove from the internal representation. */

/*     The function returns TRUE if any tokens are removed. */

/* $ Detailed_Input */

/*     LETTER     is a token to be removed from the internal */
/*                representation of a tokenized time string. */
/*                All instances of LETTER will be removed from */
/*                the internal representation. */

/* $ Detailed_Output */

/*     The function returns TRUE if any instance of LETTER is removed */
/*     from the internal representation of a tokenized time string. */
/*     If no instances are removed the function returns FALSE. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine is used to remove various delimiters that */
/*     appear in a tokenized time string (although it could be */
/*     used to remove any token from a tokenized time string). */

/* $ Examples */

/*     See TPARTV */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.2.1, 08-MAR-2009 (NJB) */

/*        Re-ordered header sections. */

/* -    SPICELIB Version 1.2.0, 09-DEC-1999 (WLT) */

/*        The main routine (which should never be called) now returns */
/*        the value .FALSE. */

/* -    SPICELIB Version 1.1.0, 30-JUN-1999 (WLT) */

/*        Added a RETURN statement at the end of the main routine. */
/*        Enhanced error message for the case when the input string */
/*        to ZZTOKNS has a non-printing character. */

/* -    SPICELIB Version 1.0.0, 4-APR-1996 (WLT) */


/* -& */
    __state->put = 0;
    __state->did = FALSE_;
    i__1 = __state->size;
    for (__state->i__ = 1; __state->i__ <= i__1; ++__state->i__) {
	if (*(unsigned char *)&__state->rep[__state->i__ - 1] != *(unsigned 
		char *)letter) {
	    ++__state->put;
	    *(unsigned char *)&__state->rep[__state->put - 1] = *(unsigned 
		    char *)&__state->rep[__state->i__ - 1];
	    __state->begs[(i__2 = __state->put - 1) < 64 && 0 <= i__2 ? i__2 :
		     s_rnge(&__global_state->f2c, "begs", i__2, "zztime_", (
		    ftnlen)1378)] = __state->begs[(i__3 = __state->i__ - 1) < 
		    64 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "begs", i__3, "zztime_", (ftnlen)1378)];
	    __state->ends[(i__2 = __state->put - 1) < 64 && 0 <= i__2 ? i__2 :
		     s_rnge(&__global_state->f2c, "ends", i__2, "zztime_", (
		    ftnlen)1379)] = __state->ends[(i__3 = __state->i__ - 1) < 
		    64 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "ends", i__3, "zztime_", (ftnlen)1379)];
	    __state->pbegs[(i__2 = __state->put - 1) < 64 && 0 <= i__2 ? i__2 
		    : s_rnge(&__global_state->f2c, "pbegs", i__2, "zztime_", (
		    ftnlen)1380)] = __state->pbegs[(i__3 = __state->i__ - 1) <
		     64 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "pbegs", i__3, "zztime_", (ftnlen)1380)];
	    __state->pends[(i__2 = __state->put - 1) < 64 && 0 <= i__2 ? i__2 
		    : s_rnge(&__global_state->f2c, "pends", i__2, "zztime_", (
		    ftnlen)1381)] = __state->pends[(i__3 = __state->i__ - 1) <
		     64 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "pends", i__3, "zztime_", (ftnlen)1381)];
	} else {
	    __state->did = TRUE_;
	}
    }
    __state->size = __state->put;
    if (__state->put == 0) {
	s_copy(&__global_state->f2c, __state->rep, " ", (ftnlen)64, (ftnlen)1)
		;
    } else if (__state->put < i_len(&__global_state->f2c, __state->rep, (
	    ftnlen)64)) {
	i__1 = __state->put;
	s_copy(&__global_state->f2c, __state->rep + i__1, " ", 64 - i__1, (
		ftnlen)1);
    }
    ret_val = __state->did;
    return ret_val;
/* $Procedure ZZSUBT ( Private, Time --- substitute tokens ) */

L_zzsubt:
/* $ Abstract */

/*    SPICE Private routine intended solely for the support of SPICE */
/*    routines. Users should not call this routine directly due */
/*    to the volatile nature of this routine. */

/*    Substitute one token for another in the internal representation */
/*    of a tokenized time string. */

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

/*     TIME --- Private */


/* $ Declarations */

/*     IMPLICIT NONE */
/*     CHARACTER*(*)         STRING */
/*     CHARACTER*(*)         TRANSL */
/*     LOGICAL               L2R */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     STRING     I   token pattern to look for. */
/*     TRANSL     I   token replacement pattern. */
/*     L2R        I   direction to scan internal representation. */

/*     The function returns TRUE is a substitution is performed. */

/* $ Detailed_Input */

/*     STRING     is a string of tokens to look for in the internal */
/*                representation of a tokenized time string. */

/*                Only the first occurrence of STRING will be modified. */

/*                If the first character in STRING is '<', (and string */
/*                is more than 1 character in length) substitutions */
/*                will be performed in the4 tokenized string only if */
/*                STRING exactly matches the tokenized string */
/*                starting at the left most character. */

/*                If the last character in STRING is '>' (and string */
/*                is more than 1 character in length) substitutions */
/*                will be performed in the4 tokenized string only if */
/*                STRING exactly matches the tokenized string */
/*                ending at the right most character. */

/*                If first and last character of STRING are '<' and '>' */
/*                respectively, the first case above is applied and the */
/*                greater than character ('>') is regarded as just */
/*                another character. */

/*     TRANSL     is a sequence of replacement tokens to substitute */
/*                in place of STRING. */

/*     L2R        is a logical flag. If L2R is TRUE, the internal */
/*                representation is scanned from left to right. If */
/*                L2R is FALSE, the internal representation is scanned */
/*                from right to left. */

/* $ Detailed_Output */

/*     The function returns TRUE if a substitution is performed. */
/*     Otherwise it returns FALSE. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine searches for the first instance of a specified */
/*     pattern in the internal representation of a tokenized */
/*     time string. If the pattern is found, it is replaced */
/*     by that value of TRANSL. Only one pattern substitution */
/*     is performed per call to this function. */

/* $ Examples */

/*     See TPARTV */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.2.1, 08-MAR-2009 (NJB) */

/*        Re-ordered header sections. */

/* -    SPICELIB Version 1.2.0, 09-DEC-1999 (WLT) */

/*        The main routine (which should never be called) now returns */
/*        the value .FALSE. */

/* -    SPICELIB Version 1.1.0, 30-JUN-1999 (WLT) */

/*        Added a RETURN statement at the end of the main routine. */
/*        Enhanced error message for the case when the input string */
/*        to ZZTOKNS has a non-printing character. */

/* -    SPICELIB Version 1.0.0, 4-APR-1996 (WLT) */


/* -& */

/*     So far we haven't combined anything. */

    __state->did = FALSE_;
    __state->k = i_len(&__global_state->f2c, string, string_len);

/*     We have two special cases to deal with. */

    if (*(unsigned char *)string == '<' && __state->k > 1) {
/* Computing MIN */
	i__1 = __state->k - 1;
	__state->to = min(i__1,__state->size);
	__state->from = 1;
	if (s_cmp(&__global_state->f2c, string + 1, __state->rep + (
		__state->from - 1), __state->k - 1, __state->to - (
		__state->from - 1)) == 0) {
	    s_copy(&__global_state->f2c, __state->rep + (__state->from - 1), 
		    transl, __state->to - (__state->from - 1), transl_len);
	    ret_val = TRUE_;
	} else {
	    ret_val = FALSE_;
	}
	return ret_val;
    } else if (*(unsigned char *)&string[__state->k - 1] == '>' && __state->k 
	    > 1) {
/* Computing MAX */
	i__1 = 1, i__2 = __state->size - __state->k + 2;
	__state->from = max(i__1,i__2);
	__state->to = __state->size;
	if (s_cmp(&__global_state->f2c, string, __state->rep + (__state->from 
		- 1), __state->k - 1, __state->to - (__state->from - 1)) == 0)
		 {
	    s_copy(&__global_state->f2c, __state->rep + (__state->from - 1), 
		    transl, __state->to - (__state->from - 1), transl_len);
	    ret_val = TRUE_;
	} else {
	    ret_val = FALSE_;
	}
	return ret_val;
    }

/*     Look for the substring either looking from the */
/*     left (L2R is YES) or from the right (L2R is NO). */

    if (*l2r) {
	__state->from = pos_(__global_state, __state->rep, string, &
		__state->c__1, (ftnlen)64, string_len);
    } else {
	__state->from = posr_(__global_state, __state->rep, string, &
		__state->size, (ftnlen)64, string_len);
    }
    __state->to = __state->from + i_len(&__global_state->f2c, transl, 
	    transl_len) - 1;
    if (__state->from > 0) {
	__state->did = TRUE_;
	s_copy(&__global_state->f2c, __state->rep + (__state->from - 1), 
		transl, __state->to - (__state->from - 1), transl_len);
    }
    ret_val = __state->did;
    return ret_val;
/* $Procedure ZZTOKNS ( Private, Time --- Time Tokens ) */

L_zztokns:
/* $ Abstract */

/*    SPICE Private routine intended solely for the support of SPICE */
/*    routines. Users should not call this routine directly due */
/*    to the volatile nature of this routine. */

/*    Construct an internal tokenized representation of STRING. */

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

/*     TIME --- PRIVATE */

/* $ Declarations */

/*     IMPLICIT NONE */
/*     CHARACTER*(*)         STRING */
/*     CHARACTER*(*)         ERROR */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     STRING     I   A time string to be tokenized and internalized. */
/*     ERROR      O   A diagnostic message */

/*     The function returns TRUE is STRING can be tokenized. */

/* $ Detailed_Input */

/*     STRING     is a string that is intended to represent some */
/*                epoch and that needs parsing. */

/* $ Detailed_Output */

/*     ERROR      is a diagnostic message that is returned if a */
/*                problem occurs while trying to tokenize the */
/*                input time string. If no problems arise, ERROR */
/*                will be returned as a blank. */

/*     The function returns TRUE if the input string can be successfully */
/*     tokenized. If a problem arises, the function returns FALSE */
/*     and diagnostic is returned in ERROR. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This is the first step in parsing a time string. The */
/*     string is examined for integers, month, weekdays, time systems */
/*     time zones, eras, am/pm and various separators. This */
/*     representation is maintained and manipulated by the */
/*     companion entry points in ZZTIME. */

/*     The various recognized tokens represented by this routine */
/*     are: */

/*        '    --- the quote character (year abbreviation) */
/*        ,    --- a comma  (delimiter) */
/*        -    --- a dash   (delimiter) */
/*        .    --- a period (delimiter) */
/*        /    --- a slash  (delimiter) */
/*        :    --- a colon  (delimiter) */
/*        N    --- AM/PM marker */
/*        O    --- UTC+  marker */
/*        Z    --- US Time Zone Marker */
/*        [    --- left parenthesis marker */
/*        ]    --- right parenthesis marker */
/*        b    --- stands for blanks, or tabs (delimiter) */
/*        d    --- day of year marker (delimiter) */
/*        e    --- era marker */
/*        j    --- Julian date system marker */
/*        m    --- month marker */
/*        o    --- UTC- marker */
/*        s    --- time system marker */
/*        t    --- the "T" marker used in ISO formats. */
/*        w    --- the weekday marker */
/*        i    --- unsigned integer marker */

/*     Using the other entry points in ZZTIME, these markers are */
/*     gradually removed and transformed to more meaningful markers. */

/* $ Examples */

/*     See TPARTV */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     B.V. Semenov    (JPL) */
/*     W.L. Taber      (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.6.0, 05-JAN-2014 (NJB) */

/*        BUG FIX: added checks for token indexes overflowing the */
/*        maximum number of tokens and for the character positions in */
/*        the time picture overflowing the time picture length. Both */
/*        overflows previously resulted in segmentation faults for */
/*        invalid input time strings that contained too many */
/*        recognizable tokens or were too long and required too many */
/*        characters in the picture representation. */

/* -    SPICELIB Version 1.5.0, 08-MAR-2009 (NJB) */

/*        Bug fix: changed upper bound used to detect */
/*        non-printing characters from 128 to 126. */

/*        Re-ordered header sections. */

/* -    SPICELIB Version 1.3.0, 27-OCT-2006 (BVS) */

/*        Fixed the bug that in the case of a one character long blank */
/*        input time string caused the TO variable be set to the value */
/*        greater than the string length, triggering an OUT OF BOUNDS */
/*        runtime error on HP. Added a separate up-front check for the */
/*        blank input string. */

/* -    SPICELIB Version 1.2.0, 09-DEC-1999 (WLT) */

/*        The main routine (which should never be called) now returns */
/*        the value .FALSE. */

/* -    SPICELIB Version 1.1.0, 30-JUN-1999 (WLT) */

/*        Added a RETURN statement at the end of the main routine. */
/*        Enhanced error message for the case when the input string */
/*        to ZZTOKNS has a non-printing character. */

/* -    SPICELIB Version 1.0.0, 4-APR-1996 (WLT) */


/* -& */

/*     The first time in this routine we initialize our "tokenizing" */
/*     table. */

    ret_val = FALSE_;
    if (__state->first) {
	__state->first = FALSE_;
	__state->blank = ' ';

/*        These are the error message templates for errors generated */
/*        for input time strings that have too many recognizable tokens */
/*        or are too long for their pictures to fit in the internal */
/*        picture buffer. */

	s_copy(&__global_state->f2c, __state->tknerr, "The input time string"
		" '#' cannot be processed because it contains more than @ rec"
		"ognizable tokens. The token that could not be processed was "
		"'#'.", (ftnlen)320, (ftnlen)145);
	repmi_(__global_state, __state->tknerr, "@", &__state->c__64, 
		__state->tknerr, (ftnlen)320, (ftnlen)1, (ftnlen)320);
	s_copy(&__global_state->f2c, __state->picerr, "The input time string"
		" '#' cannot be processed because the internal picture descri"
		"bing it requires more than @ characters. The token that coul"
		"d not be processed was '#'.", (ftnlen)320, (ftnlen)168);
	repmi_(__global_state, __state->picerr, "@", &__state->c__320, 
		__state->picerr, (ftnlen)320, (ftnlen)1, (ftnlen)320);

/*        Below is the list of recognized substrings. The basic */
/*        pattern here is to find the block of special tokens */
/*        that begin with a particular character. Insert into */
/*        that block the lines of code below */

/*        I              =  I + 1 */
/*        F( ICHAR('letter')) =  I */
/*        RECOG(I)       = 'the full substring that's recognized ' */
/*        WIDTH(I)       =  number of characters required to match */
/*        CLASS(I)       = 'the classification of this substring' */
/*        L( ICHAR('b')) =  I */

/*        Note matching is performed from the first string in the */
/*        group to the last. */


	for (__state->i__ = 32; __state->i__ <= 126; ++__state->i__) {
	    __state->f[(i__1 = __state->i__ - 32) < 95 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "f", i__1, "zztime_", (
		    ftnlen)1856)] = 0;
	    __state->l[(i__1 = __state->i__ - 32) < 95 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "l", i__1, "zztime_", (
		    ftnlen)1857)] = -1;
	    s_copy(&__global_state->f2c, __state->names + (((i__1 = 
		    __state->i__ - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "names", i__1, "zztime_", (ftnlen)
		    1858)) << 5), "substring", (ftnlen)32, (ftnlen)9);
	}
	s_copy(&__global_state->f2c, __state->names + (((i__1 = '\'' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1862)) << 5), "\"Year Abbreviation"
		" Mark\"", (ftnlen)32, (ftnlen)24);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = ',' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1863)) << 5), "comma", (ftnlen)32, (
		ftnlen)5);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = '-' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1864)) << 5), "dash", (ftnlen)32, (
		ftnlen)4);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = '.' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1865)) << 5), "period", (ftnlen)32, 
		(ftnlen)6);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = '/' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1866)) << 5), "slash", (ftnlen)32, (
		ftnlen)5);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = ':' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1867)) << 5), "colon", (ftnlen)32, (
		ftnlen)5);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = 'D' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1868)) << 5), "Day of Month", (
		ftnlen)32, (ftnlen)12);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = 'H' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1869)) << 5), "Hour", (ftnlen)32, (
		ftnlen)4);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = 'M' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1870)) << 5), "Minute", (ftnlen)32, 
		(ftnlen)6);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = 'N' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1871)) << 5), "AM/PM indicator", (
		ftnlen)32, (ftnlen)15);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = 'O' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1872)) << 5), "UTC-Offset indicator"
		, (ftnlen)32, (ftnlen)20);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = 'S' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1873)) << 5), "Second", (ftnlen)32, 
		(ftnlen)6);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = 'Y' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1874)) << 5), "Year", (ftnlen)32, (
		ftnlen)4);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = 'Z' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1875)) << 5), "Time-Zone indicator",
		 (ftnlen)32, (ftnlen)19);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = '[' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1876)) << 5), "Left Parenthesis", (
		ftnlen)32, (ftnlen)16);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = ']' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1877)) << 5), "Right Parenthesis", (
		ftnlen)32, (ftnlen)17);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = 'b' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1878)) << 5), "White Space", (
		ftnlen)32, (ftnlen)11);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = 'd' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1879)) << 5), "Day-of-Year indicat"
		"or", (ftnlen)32, (ftnlen)21);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = 'e' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1880)) << 5), "Era", (ftnlen)32, (
		ftnlen)3);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = 'i' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1881)) << 5), "Integer", (ftnlen)32,
		 (ftnlen)7);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = 'j' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1882)) << 5), "Julian Date indicat"
		"or", (ftnlen)32, (ftnlen)21);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = 'm' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1883)) << 5), "Month", (ftnlen)32, (
		ftnlen)5);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = 'n' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1884)) << 5), "Decimal Number", (
		ftnlen)32, (ftnlen)14);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = 'o' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1885)) << 5), "UTC-Offset indicator"
		, (ftnlen)32, (ftnlen)20);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = 's' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1886)) << 5), "Time System specifi"
		"cation", (ftnlen)32, (ftnlen)25);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = 't' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1887)) << 5), "ISO Time Separator", 
		(ftnlen)32, (ftnlen)18);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = 'w' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1888)) << 5), "Weekday", (ftnlen)32,
		 (ftnlen)7);
	s_copy(&__global_state->f2c, __state->names + (((i__1 = 'y' - 32) < 
		95 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "names",
		 i__1, "zztime_", (ftnlen)1889)) << 5), "Day of Year", (
		ftnlen)32, (ftnlen)11);
	s_copy(&__global_state->f2c, __state->mnmrk, "month", (ftnlen)12, (
		ftnlen)5);
	s_copy(&__global_state->f2c, __state->mnmrk + 12, "MONTH", (ftnlen)12,
		 (ftnlen)5);
	s_copy(&__global_state->f2c, __state->mnmrk + 24, "Month", (ftnlen)12,
		 (ftnlen)5);
	s_copy(&__global_state->f2c, __state->mnmrk + 36, "mon", (ftnlen)12, (
		ftnlen)3);
	s_copy(&__global_state->f2c, __state->mnmrk + 48, "MON", (ftnlen)12, (
		ftnlen)3);
	s_copy(&__global_state->f2c, __state->mnmrk + 60, "Mon", (ftnlen)12, (
		ftnlen)3);
	s_copy(&__global_state->f2c, __state->wkday, "weekday", (ftnlen)12, (
		ftnlen)7);
	s_copy(&__global_state->f2c, __state->wkday + 12, "WEEKDAY", (ftnlen)
		12, (ftnlen)7);
	s_copy(&__global_state->f2c, __state->wkday + 24, "Weekday", (ftnlen)
		12, (ftnlen)7);
	s_copy(&__global_state->f2c, __state->wkday + 36, "wkd", (ftnlen)12, (
		ftnlen)3);
	s_copy(&__global_state->f2c, __state->wkday + 48, "WKD", (ftnlen)12, (
		ftnlen)3);
	s_copy(&__global_state->f2c, __state->wkday + 60, "Wkd", (ftnlen)12, (
		ftnlen)3);

/*        Length of the items Month, Mon, weekday, wkd */

	__state->wksize[0] = 7;
	__state->wksize[1] = 3;
	__state->mnsize[0] = 5;
	__state->mnsize[1] = 3;
	__state->i__ = 0;

/*        Tokens beginning with ' ' */

	++__state->i__;
	__state->f[(i__1 = ' ' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)1917)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)1918)) * 12, " ", (ftnlen)
		12, (ftnlen)1);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)1919)] = 1;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)1920)] = 'b';
	__state->l[(i__1 = ' ' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)1921)] = 
		__state->i__;

/*        Tokens beginning with '(' */

	++__state->i__;
	__state->f[(i__1 = '(' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)1927)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)1928)) * 12, "(", (ftnlen)
		12, (ftnlen)1);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)1929)] = 1;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)1930)] = '[';
	__state->l[(i__1 = '(' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)1931)] = 
		__state->i__;

/*        Tokens beginning with ')' */

	++__state->i__;
	__state->f[(i__1 = ')' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)1936)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)1937)) * 12, ")", (ftnlen)
		12, (ftnlen)1);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)1938)] = 1;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)1939)] = ']';
	__state->l[(i__1 = ')' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)1940)] = 
		__state->i__;

/*        Tokens beginning with ',' */

	++__state->i__;
	__state->f[(i__1 = ',' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)1945)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)1946)) * 12, ",", (ftnlen)
		12, (ftnlen)1);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)1947)] = 1;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)1948)] = ',';
	__state->l[(i__1 = ',' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)1949)] = 
		__state->i__;

/*        Tokens beginning with '-' */

	++__state->i__;
	__state->f[(i__1 = '-' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)1955)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)1956)) * 12, "-", (ftnlen)
		12, (ftnlen)1);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)1957)] = 1;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)1958)] = '-';
	__state->l[(i__1 = '-' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)1959)] = 
		__state->i__;

/*        Tokens beginning with '.' */

	++__state->i__;
	__state->f[(i__1 = '.' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)1965)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)1966)) * 12, ".", (ftnlen)
		12, (ftnlen)1);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)1967)] = 1;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)1968)] = '.';
	__state->l[(i__1 = '.' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)1969)] = 
		__state->i__;

/*        Tokens beginning with '/' */

	++__state->i__;
	__state->f[(i__1 = '/' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)1975)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)1976)) * 12, "//", (ftnlen)
		12, (ftnlen)2);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)1977)] = 2;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)1978)] = 'd';
	__state->l[(i__1 = '/' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)1979)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)1982)) * 12, "/", (ftnlen)
		12, (ftnlen)1);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)1983)] = 1;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)1984)] = '/';
	__state->l[(i__1 = '/' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)1985)] = 
		__state->i__;

/*        Tokens beginning with ':' */

	++__state->i__;
	__state->f[(i__1 = ':' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)1990)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)1991)) * 12, "::", (ftnlen)
		12, (ftnlen)2);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)1992)] = 2;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)1993)] = 'd';
	__state->l[(i__1 = ':' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)1994)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)1997)) * 12, ":", (ftnlen)
		12, (ftnlen)1);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)1998)] = 1;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)1999)] = ':';
	__state->l[(i__1 = ':' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2000)] = 
		__state->i__;

/*        Tokens beginning with 'A' */

	++__state->i__;
	__state->f[(i__1 = 'A' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)2006)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2007)) * 12, "A.D.", (
		ftnlen)12, (ftnlen)4);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2008)] = 4;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2009)] = 'e';
	__state->l[(i__1 = 'A' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2010)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2013)) * 12, "AD", (ftnlen)
		12, (ftnlen)2);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2014)] = 2;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2015)] = 'e';
	__state->l[(i__1 = 'A' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2016)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2019)) * 12, "A.M.", (
		ftnlen)12, (ftnlen)4);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2020)] = 4;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2021)] = 'N';
	__state->l[(i__1 = 'A' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2022)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2025)) * 12, "AM", (ftnlen)
		12, (ftnlen)2);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2026)] = 2;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2027)] = 'N';
	__state->l[(i__1 = 'A' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2028)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2031)) * 12, "APRIL", (
		ftnlen)12, (ftnlen)5);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2032)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2033)] = 'm';
	__state->l[(i__1 = 'A' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2034)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2037)) * 12, "AUGUST", (
		ftnlen)12, (ftnlen)6);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2038)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2039)] = 'm';
	__state->l[(i__1 = 'A' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2040)] = 
		__state->i__;

/*        Tokens beginning with 'B' */

	++__state->i__;
	__state->f[(i__1 = 'B' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)2046)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2047)) * 12, "B.C.", (
		ftnlen)12, (ftnlen)4);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2048)] = 4;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2049)] = 'e';
	__state->l[(i__1 = 'B' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2050)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2053)) * 12, "BC", (ftnlen)
		12, (ftnlen)2);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2054)] = 2;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2055)] = 'e';
	__state->l[(i__1 = 'B' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2056)] = 
		__state->i__;

/*        Tokens beginning with 'C' */

	++__state->i__;
	__state->f[(i__1 = 'C' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)2062)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2063)) * 12, "CDT", (ftnlen)
		12, (ftnlen)3);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2064)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2065)] = 'Z';
	__state->l[(i__1 = 'C' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2066)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2069)) * 12, "CST", (ftnlen)
		12, (ftnlen)3);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2070)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2071)] = 'Z';
	__state->l[(i__1 = 'C' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2072)] = 
		__state->i__;

/*        Tokens beginning with 'D' */

	++__state->i__;
	__state->f[(i__1 = 'D' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)2078)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2079)) * 12, "DECEMBER", (
		ftnlen)12, (ftnlen)8);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2080)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2081)] = 'm';
	__state->l[(i__1 = 'D' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2082)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2085)) * 12, "D+", (ftnlen)
		12, (ftnlen)2);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2086)] = 2;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2087)] = 'E';
	__state->l[(i__1 = 'D' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2088)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2091)) * 12, "D-", (ftnlen)
		12, (ftnlen)2);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2092)] = 2;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2093)] = 'E';
	__state->l[(i__1 = 'D' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2094)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2097)) * 12, "D", (ftnlen)
		12, (ftnlen)1);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2098)] = 1;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2099)] = 'E';
	__state->l[(i__1 = 'D' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2100)] = 
		__state->i__;

/*        Tokens beginning with 'E' */

	++__state->i__;
	__state->f[(i__1 = 'E' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)2109)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2110)) * 12, "EDT", (ftnlen)
		12, (ftnlen)3);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2111)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2112)] = 'Z';
	__state->l[(i__1 = 'E' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2113)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2116)) * 12, "EST", (ftnlen)
		12, (ftnlen)3);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2117)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2118)] = 'Z';
	__state->l[(i__1 = 'E' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2119)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2122)) * 12, "E+", (ftnlen)
		12, (ftnlen)2);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2123)] = 2;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2124)] = 'E';
	__state->l[(i__1 = 'E' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2125)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2128)) * 12, "E-", (ftnlen)
		12, (ftnlen)2);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2129)] = 2;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2130)] = 'E';
	__state->l[(i__1 = 'E' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2131)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2134)) * 12, "E", (ftnlen)
		12, (ftnlen)1);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2135)] = 1;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2136)] = 'E';
	__state->l[(i__1 = 'E' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2137)] = 
		__state->i__;

/*        Tokens beginning with 'F' */

	++__state->i__;
	__state->f[(i__1 = 'F' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)2144)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2145)) * 12, "FEBRUARY", (
		ftnlen)12, (ftnlen)8);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2146)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2147)] = 'm';
	__state->l[(i__1 = 'F' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2148)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2151)) * 12, "FRIDAY", (
		ftnlen)12, (ftnlen)6);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2152)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2153)] = 'w';
	__state->l[(i__1 = 'F' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2154)] = 
		__state->i__;

/*        Tokens beginning with 'J' */

	++__state->i__;
	__state->f[(i__1 = 'J' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)2160)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2161)) * 12, "JANUARY", (
		ftnlen)12, (ftnlen)7);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2162)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2163)] = 'm';
	__state->l[(i__1 = 'J' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2164)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2167)) * 12, "JD", (ftnlen)
		12, (ftnlen)2);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2168)] = 2;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2169)] = 'j';
	__state->l[(i__1 = 'J' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2170)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2173)) * 12, "JULY", (
		ftnlen)12, (ftnlen)4);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2174)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2175)] = 'm';
	__state->l[(i__1 = 'J' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2176)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2179)) * 12, "JUNE", (
		ftnlen)12, (ftnlen)4);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2180)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2181)] = 'm';
	__state->l[(i__1 = 'J' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2182)] = 
		__state->i__;

/*        Tokens beginning with 'M' */

	++__state->i__;
	__state->f[(i__1 = 'M' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)2188)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2189)) * 12, "MARCH", (
		ftnlen)12, (ftnlen)5);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2190)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2191)] = 'm';
	__state->l[(i__1 = 'M' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2192)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2195)) * 12, "MAY", (ftnlen)
		12, (ftnlen)3);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2196)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2197)] = 'm';
	__state->l[(i__1 = 'M' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2198)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2201)) * 12, "MDT", (ftnlen)
		12, (ftnlen)3);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2202)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2203)] = 'Z';
	__state->l[(i__1 = 'M' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2204)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2207)) * 12, "MONDAY", (
		ftnlen)12, (ftnlen)6);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2208)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2209)] = 'w';
	__state->l[(i__1 = 'M' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2210)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2213)) * 12, "MST", (ftnlen)
		12, (ftnlen)3);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2214)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2215)] = 'Z';
	__state->l[(i__1 = 'M' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2216)] = 
		__state->i__;

/*        Tokens beginning with 'N' */

	++__state->i__;
	__state->f[(i__1 = 'N' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)2222)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2223)) * 12, "NOVEMBER", (
		ftnlen)12, (ftnlen)8);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2224)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2225)] = 'm';
	__state->l[(i__1 = 'N' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2226)] = 
		__state->i__;

/*        Tokens beginning with 'O' */

	++__state->i__;
	__state->f[(i__1 = 'O' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)2232)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2233)) * 12, "OCTOBER", (
		ftnlen)12, (ftnlen)7);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2234)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2235)] = 'm';
	__state->l[(i__1 = 'O' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2236)] = 
		__state->i__;

/*        Tokens beginning with 'P' */

	++__state->i__;
	__state->f[(i__1 = 'P' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)2242)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2243)) * 12, "P.M.", (
		ftnlen)12, (ftnlen)4);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2244)] = 4;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2245)] = 'N';
	__state->l[(i__1 = 'P' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2246)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2249)) * 12, "PDT", (ftnlen)
		12, (ftnlen)3);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2250)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2251)] = 'Z';
	__state->l[(i__1 = 'P' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2252)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2255)) * 12, "PM", (ftnlen)
		12, (ftnlen)2);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2256)] = 2;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2257)] = 'N';
	__state->l[(i__1 = 'P' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2258)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2261)) * 12, "PST", (ftnlen)
		12, (ftnlen)3);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2262)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2263)] = 'Z';
	__state->l[(i__1 = 'P' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2264)] = 
		__state->i__;

/*        Tokens beginning with 'S' */

	++__state->i__;
	__state->f[(i__1 = 'S' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)2270)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2271)) * 12, "SATURDAY", (
		ftnlen)12, (ftnlen)8);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2272)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2273)] = 'w';
	__state->l[(i__1 = 'S' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2274)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2277)) * 12, "SEPTEMBER", (
		ftnlen)12, (ftnlen)9);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2278)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2279)] = 'm';
	__state->l[(i__1 = 'S' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2280)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2283)) * 12, "SUNDAY", (
		ftnlen)12, (ftnlen)6);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2284)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2285)] = 'w';
	__state->l[(i__1 = 'S' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2286)] = 
		__state->i__;

/*        Tokens beginning with 'T' */

	++__state->i__;
	__state->f[(i__1 = 'T' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)2292)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2293)) * 12, "TDB", (ftnlen)
		12, (ftnlen)3);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2294)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2295)] = 's';
	__state->l[(i__1 = 'T' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2296)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2299)) * 12, "TDT", (ftnlen)
		12, (ftnlen)3);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2300)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2301)] = 's';
	__state->l[(i__1 = 'T' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2302)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2305)) * 12, "THURSDAY", (
		ftnlen)12, (ftnlen)8);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2306)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2307)] = 'w';
	__state->l[(i__1 = 'T' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2308)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2311)) * 12, "TUESDAY", (
		ftnlen)12, (ftnlen)7);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2312)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2313)] = 'w';
	__state->l[(i__1 = 'T' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2314)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2317)) * 12, "T", (ftnlen)
		12, (ftnlen)1);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2318)] = 1;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2319)] = 't';
	__state->l[(i__1 = 'T' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2320)] = 
		__state->i__;

/*        Tokens beginning with 'U' */

	++__state->i__;
	__state->f[(i__1 = 'U' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)2326)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2327)) * 12, "UTC+", (
		ftnlen)12, (ftnlen)4);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2328)] = 4;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2329)] = 'O';
	__state->l[(i__1 = 'U' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2330)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2333)) * 12, "UTC-", (
		ftnlen)12, (ftnlen)4);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2334)] = 4;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2335)] = 'o';
	__state->l[(i__1 = 'U' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2336)] = 
		__state->i__;
	++__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2339)) * 12, "UTC", (ftnlen)
		12, (ftnlen)3);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2340)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2341)] = 's';
	__state->l[(i__1 = 'U' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2342)] = 
		__state->i__;

/*        Tokens beginning with '''' */

	++__state->i__;
	__state->f[(i__1 = '\'' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)2347)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2348)) * 12, "'", (ftnlen)
		12, (ftnlen)1);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2349)] = 1;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2350)] = '\'';
	__state->l[(i__1 = '\'' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2351)] = 
		__state->i__;

/*        Tokens beginning with 'W' */

	++__state->i__;
	__state->f[(i__1 = 'W' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "f", i__1, "zztime_", (ftnlen)2356)] = 
		__state->i__;
	s_copy(&__global_state->f2c, __state->recog + ((i__1 = __state->i__ - 
		1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"recog", i__1, "zztime_", (ftnlen)2357)) * 12, "WEDNESDAY", (
		ftnlen)12, (ftnlen)9);
	__state->width[(i__1 = __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "width", i__1, "zztime_", (
		ftnlen)2358)] = 3;
	*(unsigned char *)&__state->class__[(i__1 = __state->i__ - 1) < 70 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "class", i__1,
		 "zztime_", (ftnlen)2359)] = 'w';
	__state->l[(i__1 = 'W' - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "l", i__1, "zztime_", (ftnlen)2360)] = 
		__state->i__;
    }

/*     If the input string is blank, return with an error message. */

    if (s_cmp(&__global_state->f2c, string, " ", string_len, (ftnlen)1) == 0) 
	    {
	s_copy(&__global_state->f2c, error, "The input time string is blank.",
		 error_len, (ftnlen)31);
	ret_val = FALSE_;
	return ret_val;
    }

/*     OK. Initializations are out of the way. We now take */
/*     apart the string. */

    __state->did = FALSE_;
    s_copy(&__global_state->f2c, error, " ", error_len, (ftnlen)1);
    s_copy(&__global_state->f2c, __state->rep, " ", (ftnlen)64, (ftnlen)1);
    s_copy(&__global_state->f2c, __state->pictur, " ", (ftnlen)320, (ftnlen)1)
	    ;
    __state->size = 0;
    __state->next = 1;
    __state->pnext = 1;
    __state->put = 0;
    __state->ampm = FALSE_;
    __state->last = rtrim_(__global_state, string, string_len);
    while(__state->next <= __state->last) {

/*        FROM and NEXT point to parts of the string, PFROM and PNEXT */
/*        point to parts of the picture we will construct. */

	__state->from = __state->next;
	__state->pfrom = __state->pnext;
	__state->item = *(unsigned char *)&string[__state->next - 1];

/*        First we try to find an unsigned integer in the string. */

	lx4uns_(__global_state, string, &__state->from, &__state->to, &
		__state->nchar, __state->last);
	if (__state->nchar > 0) {

/*           We found an unsigned integer, add a letter to the */
/*           internal representation, note the begin and end */
/*           of the token and set NEXT to the first character */
/*           beyond this token. */

	    ++__state->put;
	    if (__state->put > 64) {
		zztknerr_(__global_state, __state->tknerr, string, string + (
			__state->from - 1), error, &ret_val, (ftnlen)320, 
			string_len, __state->to - (__state->from - 1), 
			error_len);
		return ret_val;
	    }
	    *(unsigned char *)&__state->rep[__state->put - 1] = 'i';
	    __state->begs[(i__1 = __state->put - 1) < 64 && 0 <= i__1 ? i__1 :
		     s_rnge(&__global_state->f2c, "begs", i__1, "zztime_", (
		    ftnlen)2417)] = __state->from;
	    __state->ends[(i__1 = __state->put - 1) < 64 && 0 <= i__1 ? i__1 :
		     s_rnge(&__global_state->f2c, "ends", i__1, "zztime_", (
		    ftnlen)2418)] = __state->to;
	    __state->next = __state->to + 1;
	    __state->pto = __state->pfrom + __state->nchar - 1;
	    if (__state->pto > 320) {
		zztknerr_(__global_state, __state->picerr, string, string + (
			__state->from - 1), error, &ret_val, (ftnlen)320, 
			string_len, __state->to - (__state->from - 1), 
			error_len);
		return ret_val;
	    }
	    __state->pnext = __state->pto + 1;
	    s_copy(&__global_state->f2c, __state->pictur + (__state->pfrom - 
		    1), string + (__state->from - 1), __state->pto - (
		    __state->pfrom - 1), __state->to - (__state->from - 1));
	    __state->pbegs[(i__1 = __state->put - 1) < 64 && 0 <= i__1 ? i__1 
		    : s_rnge(&__global_state->f2c, "pbegs", i__1, "zztime_", (
		    ftnlen)2430)] = __state->pfrom;
	    __state->pends[(i__1 = __state->put - 1) < 64 && 0 <= i__1 ? i__1 
		    : s_rnge(&__global_state->f2c, "pends", i__1, "zztime_", (
		    ftnlen)2431)] = __state->pto;
	} else if (__state->item == __state->blank) {

/*           We have a blank. We lump all consecutive */
/*           blanks together as one big fat blank. */

	    ++__state->put;
	    if (__state->put > 64) {
		zztknerr_(__global_state, __state->tknerr, string, " ", error,
			 &ret_val, (ftnlen)320, string_len, (ftnlen)1, 
			error_len);
		return ret_val;
	    }
	    __state->to = __state->from;
	    __state->begs[(i__1 = __state->put - 1) < 64 && 0 <= i__1 ? i__1 :
		     s_rnge(&__global_state->f2c, "begs", i__1, "zztime_", (
		    ftnlen)2446)] = __state->from;
	    *(unsigned char *)&__state->rep[__state->put - 1] = 'b';
	    while(__state->item == __state->blank && __state->to <= 
		    __state->last) {
		++__state->to;
		if (__state->to <= __state->last) {
		    __state->item = *(unsigned char *)&string[__state->to - 1]
			    ;
		}
	    }
	    __state->next = __state->to;
	    --__state->to;
	    __state->ends[(i__1 = __state->put - 1) < 64 && 0 <= i__1 ? i__1 :
		     s_rnge(&__global_state->f2c, "ends", i__1, "zztime_", (
		    ftnlen)2460)] = __state->to;
	    __state->pto = __state->pfrom + __state->to - __state->from;
	    if (__state->pto > 320) {
		zztknerr_(__global_state, __state->picerr, string, " ", error,
			 &ret_val, (ftnlen)320, string_len, (ftnlen)1, 
			error_len);
		return ret_val;
	    }
	    __state->pnext = __state->pto + 1;
	    s_copy(&__global_state->f2c, __state->pictur + (__state->pfrom - 
		    1), string + (__state->from - 1), __state->pto - (
		    __state->pfrom - 1), __state->to - (__state->from - 1));
	    __state->pbegs[(i__1 = __state->put - 1) < 64 && 0 <= i__1 ? i__1 
		    : s_rnge(&__global_state->f2c, "pbegs", i__1, "zztime_", (
		    ftnlen)2471)] = __state->pfrom;
	    __state->pends[(i__1 = __state->put - 1) < 64 && 0 <= i__1 ? i__1 
		    : s_rnge(&__global_state->f2c, "pends", i__1, "zztime_", (
		    ftnlen)2472)] = __state->pto;
	} else if (__state->item == 9) {

/*           We've got a tab character, we treat tabs as */
/*           blanks. */

	    ++__state->put;
	    if (__state->put > 64) {
		zztknerr_(__global_state, __state->tknerr, string, "<TAB>", 
			error, &ret_val, (ftnlen)320, string_len, (ftnlen)5, 
			error_len);
		return ret_val;
	    }
	    *(unsigned char *)&__state->rep[__state->put - 1] = 'b';
	    __state->begs[(i__1 = __state->put - 1) < 64 && 0 <= i__1 ? i__1 :
		     s_rnge(&__global_state->f2c, "begs", i__1, "zztime_", (
		    ftnlen)2488)] = __state->from;
	    __state->ends[(i__1 = __state->put - 1) < 64 && 0 <= i__1 ? i__1 :
		     s_rnge(&__global_state->f2c, "ends", i__1, "zztime_", (
		    ftnlen)2489)] = __state->from;
	    ++__state->next;
	    __state->pto = __state->pfrom;
	    if (__state->pto > 320) {
		zztknerr_(__global_state, __state->picerr, string, "<TAB>", 
			error, &ret_val, (ftnlen)320, string_len, (ftnlen)5, 
			error_len);
		return ret_val;
	    }
	    __state->pnext = __state->pto + 1;
	    s_copy(&__global_state->f2c, __state->pictur + (__state->pfrom - 
		    1), " ", __state->pto - (__state->pfrom - 1), (ftnlen)1);
	    __state->pbegs[(i__1 = __state->put - 1) < 64 && 0 <= i__1 ? i__1 
		    : s_rnge(&__global_state->f2c, "pbegs", i__1, "zztime_", (
		    ftnlen)2502)] = __state->pfrom;
	    __state->pends[(i__1 = __state->put - 1) < 64 && 0 <= i__1 ? i__1 
		    : s_rnge(&__global_state->f2c, "pends", i__1, "zztime_", (
		    ftnlen)2503)] = __state->pfrom;
	} else if (__state->item < 32 || __state->item > 126) {

/*           This is a non-printing character. This is */
/*           regarded as an error. */

	    s_copy(&__global_state->f2c, error, string, error_len, string_len)
		    ;
	    zzinssub_(__global_state, error, "<", &__state->next, error, 
		    error_len, (ftnlen)1, error_len);

/*           Overwrite the non-printing character with a */
/*           closing angle bracket. */

	    if (__state->next < i_len(&__global_state->f2c, error, error_len))
		     {
		i__1 = __state->next;
		s_copy(&__global_state->f2c, error + i__1, ">", __state->next 
			+ 1 - i__1, (ftnlen)1);
	    }
	    prefix_(__global_state, "There is a non-printing, non-tab charac"
		    "ter (ASCII #) at position # of the time string: ", &
		    __state->c__1, error, (ftnlen)87, error_len);
	    repmi_(__global_state, error, "#", &__state->item, error, 
		    error_len, (ftnlen)1, error_len);
	    repmi_(__global_state, error, "#", &__state->next, error, 
		    error_len, (ftnlen)1, error_len);
	    ret_val = FALSE_;
	    return ret_val;
	} else {

/*           This has to be one of the known types or we */
/*           have an unknown component in the string. We've constructed */
/*           a "parsing" table for handling these special cases. */
/*           This table uses the first letter of the string */
/*           to begin a search. We get that code and force it */
/*           into a suitable range. */

	    ucase_(__global_state, string + (__state->next - 1), 
		    __state->this__, (ftnlen)1, (ftnlen)1);
	    __state->item = *(unsigned char *)__state->this__;
	    __state->from = __state->next;
	    __state->check = TRUE_;
	    __state->i__ = __state->f[(i__1 = __state->item - 32) < 95 && 0 <=
		     i__1 ? i__1 : s_rnge(&__global_state->f2c, "f", i__1, 
		    "zztime_", (ftnlen)2547)];
	    while(__state->check && __state->i__ <= __state->l[(i__1 = 
		    __state->item - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "l", i__1, "zztime_", (ftnlen)2549)])
		     {
		__state->w = __state->width[(i__1 = __state->i__ - 1) < 70 && 
			0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "wid"
			"th", i__1, "zztime_", (ftnlen)2551)];
		__state->to = __state->from + __state->w - 1;
		__state->got = samsbi_(__global_state, string, &__state->from,
			 &__state->to, __state->recog + ((i__1 = __state->i__ 
			- 1) < 70 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "recog", i__1, "zztime_", (
			ftnlen)2554)) * 12, &__state->c__1, &__state->w, 
			string_len, (ftnlen)12);
		if (__state->got) {

/*                 We have a match. If it is the match of a month */
/*                 or day of the week, we keep looking for the */
/*                 end of the match. */

		    if (*(unsigned char *)&__state->class__[(i__1 = 
			    __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
			    s_rnge(&__global_state->f2c, "class", i__1, "zzt"
			    "ime_", (ftnlen)2562)] == 'm' || *(unsigned char *)
			    &__state->class__[(i__2 = __state->i__ - 1) < 70 
			    && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c,
			     "class", i__2, "zztime_", (ftnlen)2562)] == 'w') 
			    {
			s_copy(&__global_state->f2c, __state->spcial, 
				__state->recog + ((i__1 = __state->i__ - 1) < 
				70 && 0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "recog", i__1, "zztime_",
				 (ftnlen)2566)) * 12, (ftnlen)12, (ftnlen)12);
			__state->r__ = rtrim_(__global_state, __state->spcial,
				 (ftnlen)12);
			++__state->w;
			++__state->to;
			while(samchi_(__global_state, string, &__state->to, 
				__state->spcial, &__state->w, string_len, 
				__state->r__)) {
			    ++__state->w;
			    ++__state->to;
			}
			--__state->to;
			if (__state->w > __state->r__) {
			    __state->kind = 1;
			} else {
			    __state->kind = 2;
			}
			if (*(unsigned char *)__state->this__ != *(unsigned 
				char *)&string[__state->next - 1]) {
			    __state->case__ = 1;
			} else if (s_cmp(&__global_state->f2c, string + (
				__state->next - 1), __state->spcial, (ftnlen)
				3, (ftnlen)3) == 0) {
			    __state->case__ = 2;
			} else {
			    __state->case__ = 3;
			}
			if (*(unsigned char *)&__state->class__[(i__1 = 
				__state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
				s_rnge(&__global_state->f2c, "class", i__1, 
				"zztime_", (ftnlen)2593)] == 'm') {
			    __state->pto = __state->pfrom + __state->mnsize[(
				    i__1 = __state->kind - 1) < 2 && 0 <= 
				    i__1 ? i__1 : s_rnge(&__global_state->f2c,
				     "mnsize", i__1, "zztime_", (ftnlen)2595)]
				     - 1;
			    if (__state->pto > 320) {
				zztknerr_(__global_state, __state->picerr, 
					string, string + (__state->from - 1), 
					error, &ret_val, (ftnlen)320, 
					string_len, __state->to - (
					__state->from - 1), error_len);
				return ret_val;
			    }
			    __state->pnext = __state->pto + 1;
			    s_copy(&__global_state->f2c, __state->pictur + (
				    __state->pfrom - 1), __state->mnmrk + ((
				    i__1 = __state->case__ + __state->kind * 
				    3 - 4) < 6 && 0 <= i__1 ? i__1 : s_rnge(&
				    __global_state->f2c, "mnmrk", i__1, "zzt"
				    "ime_", (ftnlen)2604)) * 12, __state->pto 
				    - (__state->pfrom - 1), (ftnlen)12);
			} else {
			    __state->pto = __state->pfrom + __state->wksize[(
				    i__1 = __state->kind - 1) < 2 && 0 <= 
				    i__1 ? i__1 : s_rnge(&__global_state->f2c,
				     "wksize", i__1, "zztime_", (ftnlen)2608)]
				     - 1;
			    if (__state->pto > 320) {
				zztknerr_(__global_state, __state->picerr, 
					string, string + (__state->from - 1), 
					error, &ret_val, (ftnlen)320, 
					string_len, __state->to - (
					__state->from - 1), error_len);
				return ret_val;
			    }
			    __state->pnext = __state->pto + 1;
			    s_copy(&__global_state->f2c, __state->pictur + (
				    __state->pfrom - 1), __state->wkday + ((
				    i__1 = __state->case__ + __state->kind * 
				    3 - 4) < 6 && 0 <= i__1 ? i__1 : s_rnge(&
				    __global_state->f2c, "wkday", i__1, "zzt"
				    "ime_", (ftnlen)2617)) * 12, __state->pto 
				    - (__state->pfrom - 1), (ftnlen)12);
			}
		    } else if (*(unsigned char *)&__state->class__[(i__1 = 
			    __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
			    s_rnge(&__global_state->f2c, "class", i__1, "zzt"
			    "ime_", (ftnlen)2621)] == 'e') {
			__state->pto = __state->pfrom + 2;
			if (__state->pto > 320) {
			    zztknerr_(__global_state, __state->picerr, string,
				     string + (__state->from - 1), error, &
				    ret_val, (ftnlen)320, string_len, 
				    __state->to - (__state->from - 1), 
				    error_len);
			    return ret_val;
			}
			__state->pnext = __state->pto + 1;
			if (*(unsigned char *)&string[__state->from - 1] == *(
				unsigned char *)__state->this__) {
			    s_copy(&__global_state->f2c, __state->pictur + (
				    __state->pfrom - 1), "ERA", __state->pto 
				    - (__state->pfrom - 1), (ftnlen)3);
			} else {
			    s_copy(&__global_state->f2c, __state->pictur + (
				    __state->pfrom - 1), "era", __state->pto 
				    - (__state->pfrom - 1), (ftnlen)3);
			}
		    } else if (*(unsigned char *)&__state->class__[(i__1 = 
			    __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
			    s_rnge(&__global_state->f2c, "class", i__1, "zzt"
			    "ime_", (ftnlen)2639)] == 'N') {
			__state->pto = __state->pfrom + 3;
			if (__state->pto > 320) {
			    zztknerr_(__global_state, __state->picerr, string,
				     string + (__state->from - 1), error, &
				    ret_val, (ftnlen)320, string_len, 
				    __state->to - (__state->from - 1), 
				    error_len);
			    return ret_val;
			}
			__state->pnext = __state->pto + 1;
			if (*(unsigned char *)&string[__state->from - 1] == *(
				unsigned char *)__state->this__) {
			    s_copy(&__global_state->f2c, __state->pictur + (
				    __state->pfrom - 1), "AMPM", __state->pto 
				    - (__state->pfrom - 1), (ftnlen)4);
			} else {
			    s_copy(&__global_state->f2c, __state->pictur + (
				    __state->pfrom - 1), "ampm", __state->pto 
				    - (__state->pfrom - 1), (ftnlen)4);
			}
			__state->ampm = TRUE_;
		    } else {
			__state->pto = __state->pfrom + __state->to - 
				__state->from;
			if (__state->pto > 320) {
			    zztknerr_(__global_state, __state->picerr, string,
				     string + (__state->from - 1), error, &
				    ret_val, (ftnlen)320, string_len, 
				    __state->to - (__state->from - 1), 
				    error_len);
			    return ret_val;
			}
			__state->pnext = __state->pto + 1;
			s_copy(&__global_state->f2c, __state->pictur + (
				__state->pfrom - 1), string + (__state->from 
				- 1), __state->pto - (__state->pfrom - 1), 
				__state->to - (__state->from - 1));
		    }
		    ++__state->put;
		    if (__state->put > 64) {
			zztknerr_(__global_state, __state->tknerr, string, 
				string + (__state->from - 1), error, &ret_val,
				 (ftnlen)320, string_len, __state->to - (
				__state->from - 1), error_len);
			return ret_val;
		    }
		    *(unsigned char *)&__state->rep[__state->put - 1] = *(
			    unsigned char *)&__state->class__[(i__1 = 
			    __state->i__ - 1) < 70 && 0 <= i__1 ? i__1 : 
			    s_rnge(&__global_state->f2c, "class", i__1, "zzt"
			    "ime_", (ftnlen)2681)];
		    __state->begs[(i__1 = __state->put - 1) < 64 && 0 <= i__1 
			    ? i__1 : s_rnge(&__global_state->f2c, "begs", 
			    i__1, "zztime_", (ftnlen)2682)] = __state->from;
		    __state->ends[(i__1 = __state->put - 1) < 64 && 0 <= i__1 
			    ? i__1 : s_rnge(&__global_state->f2c, "ends", 
			    i__1, "zztime_", (ftnlen)2683)] = __state->to;
		    __state->pbegs[(i__1 = __state->put - 1) < 64 && 0 <= 
			    i__1 ? i__1 : s_rnge(&__global_state->f2c, "pbegs"
			    , i__1, "zztime_", (ftnlen)2684)] = 
			    __state->pfrom;
		    __state->pends[(i__1 = __state->put - 1) < 64 && 0 <= 
			    i__1 ? i__1 : s_rnge(&__global_state->f2c, "pends"
			    , i__1, "zztime_", (ftnlen)2685)] = __state->pto;
		    __state->check = FALSE_;
		    __state->next = __state->to + 1;
		}
		++__state->i__;
	    }

/*           If we reach the end of the loop and CHECK is still */
/*           set to TRUE, we have a bit of unrecognizable string. */

	    if (__state->check) {
		s_copy(&__global_state->f2c, error, string, error_len, 
			string_len);
		i__1 = __state->from + 1;
		zzinssub_(__global_state, error, ">", &i__1, error, error_len,
			 (ftnlen)1, error_len);
		zzinssub_(__global_state, error, "<", &__state->from, error, 
			error_len, (ftnlen)1, error_len);
		prefix_(__global_state, "The input string contains an unreco"
			"gnizable substring beginning at the character marked"
			" by <#>: \"", &__state->c__0, error, (ftnlen)97, 
			error_len);
		suffix_(__global_state, "\"", &__state->c__0, error, (ftnlen)
			1, error_len);
		repmc_(__global_state, error, "#", string + (__state->from - 
			1), error, error_len, (ftnlen)1, (ftnlen)1, error_len)
			;
		ret_val = FALSE_;
		return ret_val;
	    }
	}
    }
    __state->size = __state->put;
    ret_val = TRUE_;
    return ret_val;
/* $Procedure ZZUNPCK ( Private, Time --- Unpack a time string ) */

L_zzunpck:
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Unpack the time string and parse its components using the */
/*     stored internal representation. */

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

/*      TIME --- PRIVATE */

/* $ Declarations */

/*     IMPLICIT NONE */
/*     CHARACTER*(*)         STRING */
/*     LOGICAL               YABBRV */
/*     DOUBLE PRECISION      TVEC ( * ) */
/*     INTEGER               E */
/*     CHARACTER*(*)         TRANSL */
/*     CHARACTER*(*)         ERROR */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     STRING     I   is a time string that has been tokenized. */
/*     YABBRV     I   has the year been abbreviated. */
/*     TVEC       O   is a vector of time components */
/*     E          O   is the actual number of components present */
/*     TRANSL     O   is the type TVEC ( YMD or YD ) */
/*     PIC        O   is a picture of the format used for the time string */
/*     ERROR      O   a diagnostic of any problems */

/*     The function returns TRUE if the string was unpacked completely. */

/* $ Detailed_Input */

/*     STRING     is the original string from which the current */
/*                internal representation was derived. */

/*     YABBRV     is a logical that indicates whether or not an */
/*                abbreviated year was encountered in the string. */
/*                YABBRV is TRUE if such an abbreviation was present */
/*                otherwise it is FALSE. */

/* $ Detailed_Output */

/*     TVEC       is a double precision array of the parsed time */
/*                components. TVEC will have either 5 or 6 values */
/*                depending upon whether the string is Year, Month, */
/*                and Day of Month, or Year and Day of Year. */

/*     E          is the actual number of components that were */
/*                present in the internal representation. */

/*                If STRING cannot be fully resolved, E is returned */
/*                as a zero. */

/*     TRANSL     is the type of time vector. The value will be */
/*                'YD' (day of year) or 'YMD' (Year, Month, Day). */

/*                If STRING cannot be fully resolved, TRANSL is */
/*                returned as a blank. */

/*     PIC        is a picture of the time format corresponding the */
/*                the time string in the last call to ZZTOKNS. */

/*                If some part of the input string can't be identified */
/*                PIC is returned as a blank. Note that there is a */
/*                distinction between recognizable and parsable. */
/*                The input string must be unambiguous to be parsable, */
/*                However, even if a string is ambiguous it may */
/*                correspond to a legitimate format picture. Since */
/*                occasionally, that's what you want (an ambiguous */
/*                format), we allow it in PIC. */

/*     ERROR      is a diagnostic that indicates some problem in */
/*                resolving STRING. If no problems occur ERROR */
/*                is returned as a blank. */

/*     The function returns TRUE if STRING was successfully unpacked. */
/*     That is the string is parsed and is unambiguously recognized. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine is the last routine that will normally be */
/*     called by a time parsing routine. This call should be */
/*     made after all combinations, replacements and removals */
/*     that make sense to perform have been made. */

/* $ Examples */

/*     See TPARTV */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.3.0, 29-APR-2013 (EDW) */

/*        Added error check on ITEM value. Failure to perform */
/*        this check can cause BADSUBSCRIPT error signals */
/*        from CSPICE code on invalid time strings. */

/* -    SPICELIB Version 1.2.1, 08-MAR-2009 (NJB) */

/*        Re-ordered header sections. */

/* -    SPICELIB Version 1.2.0, 09-DEC-1999 (WLT) */

/*        The main routine (which should never be called) now returns */
/*        the value .FALSE. */

/* -    SPICELIB Version 1.1.0, 30-JUN-1999 (WLT) */

/*        Added a RETURN statement at the end of the main routine. */
/*        Enhanced error message for the case when the input string */
/*        to ZZTOKNS has a non-printing character. */

/* -    SPICELIB Version 1.0.0, 4-APR-1996 (WLT) */


/* -& */
    __state->nyear = 0;
    __state->nmon = 0;
    __state->nday = 0;
    __state->nhour = 0;
    __state->nmin = 0;
    __state->nsec = 0;
    __state->ndoy = 0;
    __state->njd = 0;
    *e = 0;
    s_copy(&__global_state->f2c, transl, " ", transl_len, (ftnlen)1);
    __state->hms[0] = 0.;
    __state->hms[1] = 0.;
    __state->hms[2] = 0.;
    for (__state->i__ = __state->size; __state->i__ >= 1; --__state->i__) {
	__state->item = *(unsigned char *)&__state->rep[__state->i__ - 1];

/*        Confirm ITEM range [32,126]. */

	if (__state->item < 32 || __state->item > 126) {

/*           A non-printing character found in REP. This is */
/*           an error. */

	    s_copy(&__global_state->f2c, error, "A character at location #1 "
		    "does not have ASCII value [32,126] for REP string.", 
		    error_len, (ftnlen)77);
	    repmi_(__global_state, error, "#1", &__state->i__, error, 
		    error_len, (ftnlen)2, error_len);

/*           Error condition, return. */

	    ret_val = FALSE_;
	    return ret_val;
	}
	__state->j = __state->begs[(i__1 = __state->i__ - 1) < 64 && 0 <= 
		i__1 ? i__1 : s_rnge(&__global_state->f2c, "begs", i__1, 
		"zztime_", (ftnlen)2954)];
	__state->k = __state->ends[(i__1 = __state->i__ - 1) < 64 && 0 <= 
		i__1 ? i__1 : s_rnge(&__global_state->f2c, "ends", i__1, 
		"zztime_", (ftnlen)2955)];
	if (__state->item == 'Y') {
	    ++__state->nyear;
	    ++(*e);
	    nparsd_(__global_state, string + (__state->j - 1), tvec, error, &
		    __state->ptr, __state->k - (__state->j - 1), error_len);
	    if (*yabbrv) {
		zzrepsub_(__global_state, __state->pictur, &__state->pbegs[(
			i__1 = __state->i__ - 1) < 64 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "pbegs", i__1, "zztime_",
			 (ftnlen)2964)], &__state->pends[(i__2 = __state->i__ 
			- 1) < 64 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "pends", i__2, "zztime_", (
			ftnlen)2964)], "YR", __state->pictur, (ftnlen)320, (
			ftnlen)2, (ftnlen)320);
	    } else {
		zzrepsub_(__global_state, __state->pictur, &__state->pbegs[(
			i__1 = __state->i__ - 1) < 64 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "pbegs", i__1, "zztime_",
			 (ftnlen)2967)], &__state->pends[(i__2 = __state->i__ 
			- 1) < 64 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "pends", i__2, "zztime_", (
			ftnlen)2967)], "YYYY", __state->pictur, (ftnlen)320, (
			ftnlen)4, (ftnlen)320);
	    }
	} else if (__state->item == 'm') {
	    ++__state->nmon;
	    ++(*e);
	    ucase_(__global_state, string + (__state->j - 1), __state->month, 
		    __state->k - (__state->j - 1), (ftnlen)3);
	    __state->value = isrchc_(__global_state, __state->month, &
		    __state->c__12, __state->months, (ftnlen)3, (ftnlen)3);
	    if (__state->value == 0) {
		nparsd_(__global_state, string + (__state->j - 1), &tvec[1], 
			error, &__state->ptr, __state->k - (__state->j - 1), 
			error_len);
		zzrepsub_(__global_state, __state->pictur, &__state->pbegs[(
			i__1 = __state->i__ - 1) < 64 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "pbegs", i__1, "zztime_",
			 (ftnlen)2981)], &__state->pends[(i__2 = __state->i__ 
			- 1) < 64 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "pends", i__2, "zztime_", (
			ftnlen)2981)], "MM", __state->pictur, (ftnlen)320, (
			ftnlen)2, (ftnlen)320);
	    } else {
		tvec[1] = (doublereal) __state->value;
	    }
	} else if (__state->item == 'D') {
	    ++__state->nday;
	    ++(*e);
	    nparsd_(__global_state, string + (__state->j - 1), &tvec[2], 
		    error, &__state->ptr, __state->k - (__state->j - 1), 
		    error_len);
	    zzmkpc_(__global_state, __state->pictur, &__state->pbegs[(i__1 = 
		    __state->i__ - 1) < 64 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "pbegs", i__1, "zztime_", (ftnlen)
		    2994)], &__state->pends[(i__2 = __state->i__ - 1) < 64 && 
		    0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "pends", 
		    i__2, "zztime_", (ftnlen)2994)], "DD", string + (
		    __state->j - 1), (ftnlen)320, (ftnlen)2, __state->k - (
		    __state->j - 1));
	} else if (__state->item == 'y') {
	    ++__state->ndoy;
	    ++(*e);
	    nparsd_(__global_state, string + (__state->j - 1), &tvec[1], 
		    error, &__state->ptr, __state->k - (__state->j - 1), 
		    error_len);
	    zzmkpc_(__global_state, __state->pictur, &__state->pbegs[(i__1 = 
		    __state->i__ - 1) < 64 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "pbegs", i__1, "zztime_", (ftnlen)
		    3004)], &__state->pends[(i__2 = __state->i__ - 1) < 64 && 
		    0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "pends", 
		    i__2, "zztime_", (ftnlen)3004)], "DOY", string + (
		    __state->j - 1), (ftnlen)320, (ftnlen)3, __state->k - (
		    __state->j - 1));
	} else if (__state->item == 'H') {
	    ++__state->nhour;
	    ++(*e);
	    nparsd_(__global_state, string + (__state->j - 1), __state->hms, 
		    error, &__state->ptr, __state->k - (__state->j - 1), 
		    error_len);

/*           We have to handle the hour component based on the */
/*           presence of the AM/PM mark in the picture. We earlier */
/*           set up the logical AMPM to indicate its presence. */

	    if (__state->ampm) {
		zzmkpc_(__global_state, __state->pictur, &__state->pbegs[(
			i__1 = __state->i__ - 1) < 64 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "pbegs", i__1, "zztime_",
			 (ftnlen)3020)], &__state->pends[(i__2 = __state->i__ 
			- 1) < 64 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "pends", i__2, "zztime_", (
			ftnlen)3020)], "AP", string + (__state->j - 1), (
			ftnlen)320, (ftnlen)2, __state->k - (__state->j - 1));
	    } else {
		zzmkpc_(__global_state, __state->pictur, &__state->pbegs[(
			i__1 = __state->i__ - 1) < 64 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "pbegs", i__1, "zztime_",
			 (ftnlen)3025)], &__state->pends[(i__2 = __state->i__ 
			- 1) < 64 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "pends", i__2, "zztime_", (
			ftnlen)3025)], "HR", string + (__state->j - 1), (
			ftnlen)320, (ftnlen)2, __state->k - (__state->j - 1));
	    }
	} else if (__state->item == 'M') {
	    ++__state->nmin;
	    ++(*e);
	    nparsd_(__global_state, string + (__state->j - 1), &__state->hms[
		    1], error, &__state->ptr, __state->k - (__state->j - 1), 
		    error_len);
	    zzmkpc_(__global_state, __state->pictur, &__state->pbegs[(i__1 = 
		    __state->i__ - 1) < 64 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "pbegs", i__1, "zztime_", (ftnlen)
		    3037)], &__state->pends[(i__2 = __state->i__ - 1) < 64 && 
		    0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "pends", 
		    i__2, "zztime_", (ftnlen)3037)], "MN", string + (
		    __state->j - 1), (ftnlen)320, (ftnlen)2, __state->k - (
		    __state->j - 1));
	} else if (__state->item == 'S') {
	    ++__state->nsec;
	    ++(*e);
	    nparsd_(__global_state, string + (__state->j - 1), &__state->hms[
		    2], error, &__state->ptr, __state->k - (__state->j - 1), 
		    error_len);
	    zzmkpc_(__global_state, __state->pictur, &__state->pbegs[(i__1 = 
		    __state->i__ - 1) < 64 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "pbegs", i__1, "zztime_", (ftnlen)
		    3047)], &__state->pends[(i__2 = __state->i__ - 1) < 64 && 
		    0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "pends", 
		    i__2, "zztime_", (ftnlen)3047)], "SC", string + (
		    __state->j - 1), (ftnlen)320, (ftnlen)2, __state->k - (
		    __state->j - 1));
	} else if (__state->item == 'J') {
	    ++__state->njd;
	    ++(*e);
	    nparsd_(__global_state, string + (__state->j - 1), tvec, error, &
		    __state->ptr, __state->k - (__state->j - 1), error_len);
	    zzmkpc_(__global_state, __state->pictur, &__state->pbegs[(i__1 = 
		    __state->i__ - 1) < 64 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "pbegs", i__1, "zztime_", (ftnlen)
		    3057)], &__state->pends[(i__2 = __state->i__ - 1) < 64 && 
		    0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "pends", 
		    i__2, "zztime_", (ftnlen)3057)], "JULIAND", string + (
		    __state->j - 1), (ftnlen)320, (ftnlen)7, __state->k - (
		    __state->j - 1));
	} else if (__state->item == 'i') {
	    s_copy(&__global_state->f2c, error, string, error_len, string_len)
		    ;
	    i__1 = __state->k + 1;
	    zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		    ftnlen)1, error_len);
	    zzinssub_(__global_state, error, "<", &__state->j, error, 
		    error_len, (ftnlen)1, error_len);
	    prefix_(__global_state, "The meaning of the integer <#> could no"
		    "t be determined: '", &__state->c__1, error, (ftnlen)57, 
		    error_len);
	    suffix_(__global_state, "'", &__state->c__0, error, (ftnlen)1, 
		    error_len);
	    repmc_(__global_state, error, "#", string + (__state->j - 1), 
		    error, error_len, (ftnlen)1, __state->k - (__state->j - 1)
		    , error_len);
	    *e = 0;
	    s_copy(&__global_state->f2c, pic, " ", pic_len, (ftnlen)1);
	    ret_val = FALSE_;
	    return ret_val;
	} else if (__state->item == 'n') {
	    s_copy(&__global_state->f2c, error, string, error_len, string_len)
		    ;
	    i__1 = __state->k + 1;
	    zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		    ftnlen)1, error_len);
	    zzinssub_(__global_state, error, "<", &__state->j, error, 
		    error_len, (ftnlen)1, error_len);
	    prefix_(__global_state, "The meaning of the decimal number <#> c"
		    "ould not be determined: ", &__state->c__1, error, (ftnlen)
		    63, error_len);
	    repmc_(__global_state, error, "#", string + (__state->j - 1), 
		    error, error_len, (ftnlen)1, __state->k - (__state->j - 1)
		    , error_len);
	    *e = 0;
	    s_copy(&__global_state->f2c, pic, " ", pic_len, (ftnlen)1);
	    ret_val = FALSE_;
	    return ret_val;
	} else {
	    s_copy(&__global_state->f2c, error, string, error_len, string_len)
		    ;
	    i__1 = __state->k + 1;
	    zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		    ftnlen)1, error_len);
	    zzinssub_(__global_state, error, "<", &__state->j, error, 
		    error_len, (ftnlen)1, error_len);
	    prefix_(__global_state, "An unexpected # (\"#\") was encountered"
		    " in the time string: ", &__state->c__1, error, (ftnlen)58,
		     error_len);
	    repmc_(__global_state, error, "#", __state->names + (((i__1 = 
		    __state->item - 32) < 95 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "names", i__1, "zztime_", (ftnlen)
		    3105)) << 5), error, error_len, (ftnlen)1, (ftnlen)32, 
		    error_len);
	    repmc_(__global_state, error, "#", string + (__state->j - 1), 
		    error, error_len, (ftnlen)1, __state->k - (__state->j - 1)
		    , error_len);
	    s_copy(&__global_state->f2c, pic, " ", pic_len, (ftnlen)1);
	    *e = 0;
	    ret_val = FALSE_;
	    return ret_val;
	}
    }

/*     Ok. Check the counts of substrings to make sure everything */
/*     looks ok. If so move the HMS into the appropriate slots */
/*     in TVEC, set the kind of TVEC, set the function value to YES, */
/*     and RETURN. Note regardless of the correctness of the parsing */
/*     we have a legitimate format picture at this point so we keep it. */

    s_copy(&__global_state->f2c, pic, __state->pictur, pic_len, (ftnlen)320);
    if (__state->nyear == 1 && __state->nmon == 1 && __state->nday == 1 && 
	    __state->ndoy == 0 && __state->njd == 0 && __state->nhour <= 1 && 
	    __state->nmin <= __state->nhour && __state->nsec <= __state->nmin)
	     {
	tvec[3] = __state->hms[0];
	tvec[4] = __state->hms[1];
	tvec[5] = __state->hms[2];
	s_copy(&__global_state->f2c, transl, "YMD", transl_len, (ftnlen)3);
	ret_val = TRUE_;
	return ret_val;
    } else if (__state->nyear == 1 && __state->nmon == 0 && __state->nday == 
	    0 && __state->njd == 0 && __state->ndoy == 1 && __state->nhour <= 
	    1 && __state->nmin <= __state->nhour && __state->nsec <= 
	    __state->nmin) {
	tvec[2] = __state->hms[0];
	tvec[3] = __state->hms[1];
	tvec[4] = __state->hms[2];
	s_copy(&__global_state->f2c, transl, "YD", transl_len, (ftnlen)2);
	ret_val = TRUE_;
	return ret_val;
    } else if (__state->nyear == 0 && __state->nmon == 0 && __state->nday == 
	    0 && __state->njd == 1 && __state->ndoy == 0 && __state->nhour <= 
	    0 && __state->nmin <= 0 && __state->nsec <= 0) {
	s_copy(&__global_state->f2c, transl, "JD", transl_len, (ftnlen)2);
	ret_val = TRUE_;
	return ret_val;
    }

/*     If we're still here, there is some kind of an error */
/*     in the input string. There are a lot of possible */
/*     problems. */

    *e = 0;
    if (__state->nyear == 0 && __state->nday == 0 && __state->njd == 0 && 
	    __state->ndoy == 0 && __state->nhour == 0 && __state->nmin == 0 &&
	     __state->nsec == 0) {
	s_copy(&__global_state->f2c, error, "No numeric components were supp"
		"lied in the time string. ", error_len, (ftnlen)56);
    } else if (__state->njd == 1) {
	s_copy(&__global_state->f2c, error, "The string possesses calendar c"
		"omponents in addition to Julian Date specifier. ", error_len, 
		(ftnlen)79);
    } else if (__state->njd > 1) {
	s_copy(&__global_state->f2c, error, "There is more than one Julian D"
		"ate specified in the epoch string. ", error_len, (ftnlen)66);
    } else if (__state->nyear == 0) {
	s_copy(&__global_state->f2c, error, "The year associated with the ca"
		"lendar string \"#\" could not be identified. ", error_len, (
		ftnlen)74);
	repmc_(__global_state, error, "#", string, error, error_len, (ftnlen)
		1, string_len, error_len);
    } else if (__state->nyear > 1) {
	s_copy(&__global_state->f2c, error, string, error_len, string_len);
	s_copy(&__global_state->f2c, __state->messge, "Two substrings indica"
		"ting a calendar year were identified in the input time strin"
		"g <#> and <#>: \"", (ftnlen)320, (ftnlen)97);
	__state->p1 = pos_(__global_state, __state->rep, "Y", &__state->c__1, 
		(ftnlen)64, (ftnlen)1);
	i__1 = __state->p1 + 1;
	__state->p2 = pos_(__global_state, __state->rep, "Y", &i__1, (ftnlen)
		64, (ftnlen)1);
	__state->j = __state->begs[(i__1 = __state->p2 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "begs", i__1, "zztime_",
		 (ftnlen)3224)];
	__state->k = __state->ends[(i__1 = __state->p2 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "ends", i__1, "zztime_",
		 (ftnlen)3225)];
	i__1 = __state->k + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->j, error, error_len, (
		ftnlen)1, error_len);
	repmc_(__global_state, __state->messge, "#", string + (__state->j - 1)
		, __state->messge, (ftnlen)320, (ftnlen)1, __state->k - (
		__state->j - 1), (ftnlen)320);
	__state->j = __state->begs[(i__1 = __state->p1 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "begs", i__1, "zztime_",
		 (ftnlen)3231)];
	__state->k = __state->ends[(i__1 = __state->p1 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "ends", i__1, "zztime_",
		 (ftnlen)3232)];
	i__1 = __state->k + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->j, error, error_len, (
		ftnlen)1, error_len);
	repmc_(__global_state, __state->messge, "#", string + (__state->j - 1)
		, __state->messge, (ftnlen)320, (ftnlen)1, __state->k - (
		__state->j - 1), (ftnlen)320);
	prefix_(__global_state, __state->messge, &__state->c__1, error, (
		ftnlen)320, error_len);
	suffix_(__global_state, "\"", &__state->c__0, error, (ftnlen)1, 
		error_len);
    } else if (__state->nmon > 0 && __state->ndoy > 0) {
	s_copy(&__global_state->f2c, error, string, error_len, string_len);
	s_copy(&__global_state->f2c, __state->messge, "Both a day of year an"
		"d month were identified in the input string. \"", (ftnlen)320,
		 (ftnlen)67);
/* Computing MAX */
	i__1 = pos_(__global_state, __state->rep, "m", &__state->c__1, (
		ftnlen)64, (ftnlen)1), i__2 = pos_(__global_state, 
		__state->rep, "y", &__state->c__1, (ftnlen)64, (ftnlen)1);
	__state->p2 = max(i__1,i__2);
/* Computing MIN */
	i__1 = pos_(__global_state, __state->rep, "m", &__state->c__1, (
		ftnlen)64, (ftnlen)1), i__2 = pos_(__global_state, 
		__state->rep, "y", &__state->c__1, (ftnlen)64, (ftnlen)1);
	__state->p1 = min(i__1,i__2);
	__state->j = __state->begs[(i__1 = __state->p2 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "begs", i__1, "zztime_",
		 (ftnlen)3254)];
	__state->k = __state->ends[(i__1 = __state->p2 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "ends", i__1, "zztime_",
		 (ftnlen)3255)];
	i__1 = __state->k + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->j, error, error_len, (
		ftnlen)1, error_len);
	__state->j = __state->begs[(i__1 = __state->p1 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "begs", i__1, "zztime_",
		 (ftnlen)3260)];
	__state->k = __state->ends[(i__1 = __state->p1 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "ends", i__1, "zztime_",
		 (ftnlen)3261)];
	i__1 = __state->k + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->j, error, error_len, (
		ftnlen)1, error_len);
	prefix_(__global_state, __state->messge, &__state->c__1, error, (
		ftnlen)320, error_len);
	suffix_(__global_state, "\"", &__state->c__0, error, (ftnlen)1, 
		error_len);
    } else if (__state->nmon > 1) {
	s_copy(&__global_state->f2c, error, string, error_len, string_len);
	s_copy(&__global_state->f2c, __state->messge, "Two substrings indica"
		"ting a calendar month were identified in the input time stri"
		"ng <#> and <#>: \"", (ftnlen)320, (ftnlen)98);
	__state->p1 = pos_(__global_state, __state->rep, "m", &__state->c__1, 
		(ftnlen)64, (ftnlen)1);
	i__1 = __state->p1 + 1;
	__state->p2 = pos_(__global_state, __state->rep, "m", &i__1, (ftnlen)
		64, (ftnlen)1);
	__state->j = __state->begs[(i__1 = __state->p2 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "begs", i__1, "zztime_",
		 (ftnlen)3280)];
	__state->k = __state->ends[(i__1 = __state->p2 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "ends", i__1, "zztime_",
		 (ftnlen)3281)];
	i__1 = __state->k + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->j, error, error_len, (
		ftnlen)1, error_len);
	repmc_(__global_state, __state->messge, "#", string + (__state->j - 1)
		, __state->messge, (ftnlen)320, (ftnlen)1, __state->k - (
		__state->j - 1), (ftnlen)320);
	__state->j = __state->begs[(i__1 = __state->p1 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "begs", i__1, "zztime_",
		 (ftnlen)3287)];
	__state->k = __state->ends[(i__1 = __state->p1 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "ends", i__1, "zztime_",
		 (ftnlen)3288)];
	i__1 = __state->k + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->j, error, error_len, (
		ftnlen)1, error_len);
	repmc_(__global_state, __state->messge, "#", string + (__state->j - 1)
		, __state->messge, (ftnlen)320, (ftnlen)1, __state->k - (
		__state->j - 1), (ftnlen)320);
	prefix_(__global_state, __state->messge, &__state->c__1, error, (
		ftnlen)320, error_len);
	suffix_(__global_state, "\"", &__state->c__0, error, (ftnlen)1, 
		error_len);
    } else if (__state->ndoy > 1) {
	s_copy(&__global_state->f2c, error, string, error_len, string_len);
	s_copy(&__global_state->f2c, __state->messge, "Two substrings indica"
		"ting a day of year were identified in the input time string "
		"<#> and <#>: \"", (ftnlen)320, (ftnlen)95);
	__state->p1 = pos_(__global_state, __state->rep, "y", &__state->c__1, 
		(ftnlen)64, (ftnlen)1);
	i__1 = __state->p1 + 1;
	__state->p2 = pos_(__global_state, __state->rep, "y", &i__1, (ftnlen)
		64, (ftnlen)1);
	__state->j = __state->begs[(i__1 = __state->p2 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "begs", i__1, "zztime_",
		 (ftnlen)3308)];
	__state->k = __state->ends[(i__1 = __state->p2 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "ends", i__1, "zztime_",
		 (ftnlen)3309)];
	i__1 = __state->k + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->j, error, error_len, (
		ftnlen)1, error_len);
	repmc_(__global_state, __state->messge, "#", string + (__state->j - 1)
		, __state->messge, (ftnlen)320, (ftnlen)1, __state->k - (
		__state->j - 1), (ftnlen)320);
	__state->j = __state->begs[(i__1 = __state->p1 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "begs", i__1, "zztime_",
		 (ftnlen)3315)];
	__state->k = __state->ends[(i__1 = __state->p1 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "ends", i__1, "zztime_",
		 (ftnlen)3316)];
	i__1 = __state->k + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->j, error, error_len, (
		ftnlen)1, error_len);
	repmc_(__global_state, __state->messge, "#", string + (__state->j - 1)
		, __state->messge, (ftnlen)320, (ftnlen)1, __state->k - (
		__state->j - 1), (ftnlen)320);
	prefix_(__global_state, __state->messge, &__state->c__1, error, (
		ftnlen)320, error_len);
	suffix_(__global_state, "\"", &__state->c__0, error, (ftnlen)1, 
		error_len);
    } else if (__state->nday > 1) {
	s_copy(&__global_state->f2c, error, string, error_len, string_len);
	s_copy(&__global_state->f2c, __state->messge, "Two substrings indica"
		"ting a day of month were identified in the input time string"
		" <#> and <#>: \"", (ftnlen)320, (ftnlen)96);
	__state->p1 = pos_(__global_state, __state->rep, "D", &__state->c__1, 
		(ftnlen)64, (ftnlen)1);
	i__1 = __state->p1 + 1;
	__state->p2 = pos_(__global_state, __state->rep, "D", &i__1, (ftnlen)
		64, (ftnlen)1);
	__state->j = __state->begs[(i__1 = __state->p2 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "begs", i__1, "zztime_",
		 (ftnlen)3336)];
	__state->k = __state->ends[(i__1 = __state->p2 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "ends", i__1, "zztime_",
		 (ftnlen)3337)];
	i__1 = __state->k + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->j, error, error_len, (
		ftnlen)1, error_len);
	repmc_(__global_state, __state->messge, "#", string + (__state->j - 1)
		, __state->messge, (ftnlen)320, (ftnlen)1, __state->k - (
		__state->j - 1), (ftnlen)320);
	__state->j = __state->begs[(i__1 = __state->p1 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "begs", i__1, "zztime_",
		 (ftnlen)3343)];
	__state->k = __state->ends[(i__1 = __state->p1 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "ends", i__1, "zztime_",
		 (ftnlen)3344)];
	i__1 = __state->k + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->j, error, error_len, (
		ftnlen)1, error_len);
	repmc_(__global_state, __state->messge, "#", string + (__state->j - 1)
		, __state->messge, (ftnlen)320, (ftnlen)1, __state->k - (
		__state->j - 1), (ftnlen)320);
	prefix_(__global_state, __state->messge, &__state->c__1, error, (
		ftnlen)320, error_len);
	suffix_(__global_state, "\"", &__state->c__0, error, (ftnlen)1, 
		error_len);
    } else if (__state->nhour > 1) {
	s_copy(&__global_state->f2c, error, string, error_len, string_len);
	s_copy(&__global_state->f2c, __state->messge, "Two substrings repres"
		"enting an hour of the day were identified in the input time "
		"string <#> and <#>: \"", (ftnlen)320, (ftnlen)102);
	__state->p1 = pos_(__global_state, __state->rep, "H", &__state->c__1, 
		(ftnlen)64, (ftnlen)1);
	i__1 = __state->p1 + 1;
	__state->p2 = pos_(__global_state, __state->rep, "H", &i__1, (ftnlen)
		64, (ftnlen)1);
	__state->j = __state->begs[(i__1 = __state->p2 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "begs", i__1, "zztime_",
		 (ftnlen)3364)];
	__state->k = __state->ends[(i__1 = __state->p2 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "ends", i__1, "zztime_",
		 (ftnlen)3365)];
	i__1 = __state->k + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->j, error, error_len, (
		ftnlen)1, error_len);
	repmc_(__global_state, __state->messge, "#", string + (__state->j - 1)
		, __state->messge, (ftnlen)320, (ftnlen)1, __state->k - (
		__state->j - 1), (ftnlen)320);
	__state->j = __state->begs[(i__1 = __state->p1 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "begs", i__1, "zztime_",
		 (ftnlen)3371)];
	__state->k = __state->ends[(i__1 = __state->p1 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "ends", i__1, "zztime_",
		 (ftnlen)3372)];
	i__1 = __state->k + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->j, error, error_len, (
		ftnlen)1, error_len);
	repmc_(__global_state, __state->messge, "#", string + (__state->j - 1)
		, __state->messge, (ftnlen)320, (ftnlen)1, __state->k - (
		__state->j - 1), (ftnlen)320);
	prefix_(__global_state, __state->messge, &__state->c__1, error, (
		ftnlen)320, error_len);
	suffix_(__global_state, "\"", &__state->c__0, error, (ftnlen)1, 
		error_len);
    } else if (__state->nmin > 1) {
	s_copy(&__global_state->f2c, error, string, error_len, string_len);
	s_copy(&__global_state->f2c, __state->messge, "Two substrings repres"
		"enting minutes of the hour were identified in the input time"
		" string <#> and <#>: \"", (ftnlen)320, (ftnlen)103);
	__state->p1 = pos_(__global_state, __state->rep, "M", &__state->c__1, 
		(ftnlen)64, (ftnlen)1);
	i__1 = __state->p1 + 1;
	__state->p2 = pos_(__global_state, __state->rep, "M", &i__1, (ftnlen)
		64, (ftnlen)1);
	__state->j = __state->begs[(i__1 = __state->p2 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "begs", i__1, "zztime_",
		 (ftnlen)3392)];
	__state->k = __state->ends[(i__1 = __state->p2 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "ends", i__1, "zztime_",
		 (ftnlen)3393)];
	i__1 = __state->k + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->j, error, error_len, (
		ftnlen)1, error_len);
	repmc_(__global_state, __state->messge, "#", string + (__state->j - 1)
		, __state->messge, (ftnlen)320, (ftnlen)1, __state->k - (
		__state->j - 1), (ftnlen)320);
	__state->j = __state->begs[(i__1 = __state->p1 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "begs", i__1, "zztime_",
		 (ftnlen)3399)];
	__state->k = __state->ends[(i__1 = __state->p1 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "ends", i__1, "zztime_",
		 (ftnlen)3400)];
	i__1 = __state->k + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->j, error, error_len, (
		ftnlen)1, error_len);
	repmc_(__global_state, __state->messge, "#", string + (__state->j - 1)
		, __state->messge, (ftnlen)320, (ftnlen)1, __state->k - (
		__state->j - 1), (ftnlen)320);
	prefix_(__global_state, __state->messge, &__state->c__1, error, (
		ftnlen)320, error_len);
	suffix_(__global_state, "\"", &__state->c__0, error, (ftnlen)1, 
		error_len);
    } else if (__state->nsec > 1) {
	s_copy(&__global_state->f2c, error, string, error_len, string_len);
	s_copy(&__global_state->f2c, __state->messge, "Two substrings repres"
		"enting seconds were identified in the input time string <#> "
		"and <#>: \"", (ftnlen)320, (ftnlen)91);
	__state->p1 = pos_(__global_state, __state->rep, "S", &__state->c__1, 
		(ftnlen)64, (ftnlen)1);
	i__1 = __state->p1 + 1;
	__state->p2 = pos_(__global_state, __state->rep, "S", &i__1, (ftnlen)
		64, (ftnlen)1);
	__state->j = __state->begs[(i__1 = __state->p2 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "begs", i__1, "zztime_",
		 (ftnlen)3420)];
	__state->k = __state->ends[(i__1 = __state->p2 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "ends", i__1, "zztime_",
		 (ftnlen)3421)];
	i__1 = __state->k + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->j, error, error_len, (
		ftnlen)1, error_len);
	repmc_(__global_state, __state->messge, "#", string + (__state->j - 1)
		, __state->messge, (ftnlen)320, (ftnlen)1, __state->k - (
		__state->j - 1), (ftnlen)320);
	__state->j = __state->begs[(i__1 = __state->p1 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "begs", i__1, "zztime_",
		 (ftnlen)3427)];
	__state->k = __state->ends[(i__1 = __state->p1 - 1) < 64 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "ends", i__1, "zztime_",
		 (ftnlen)3428)];
	i__1 = __state->k + 1;
	zzinssub_(__global_state, error, ">", &i__1, error, error_len, (
		ftnlen)1, error_len);
	zzinssub_(__global_state, error, "<", &__state->j, error, error_len, (
		ftnlen)1, error_len);
	repmc_(__global_state, __state->messge, "#", string + (__state->j - 1)
		, __state->messge, (ftnlen)320, (ftnlen)1, __state->k - (
		__state->j - 1), (ftnlen)320);
	prefix_(__global_state, __state->messge, &__state->c__1, error, (
		ftnlen)320, error_len);
	suffix_(__global_state, "\"", &__state->c__0, error, (ftnlen)1, 
		error_len);
    } else if (__state->ndoy == 0 && __state->nmon == 0) {
	s_copy(&__global_state->f2c, error, "Neither a month nor day of year"
		" could be identified in the input time string: \"#\" ", 
		error_len, (ftnlen)82);
	repmc_(__global_state, error, "#", string, error, error_len, (ftnlen)
		1, string_len, error_len);
    } else if (__state->nmon == 1 && __state->nday == 0) {
	s_copy(&__global_state->f2c, error, "A month was identified in the t"
		"ime string \"#\", but a day of month could not be identified"
		". ", error_len, (ftnlen)91);
	repmc_(__global_state, error, "#", string, error, error_len, (ftnlen)
		1, string_len, error_len);
    } else if (__state->nmon == 0 && __state->nday == 1) {
	s_copy(&__global_state->f2c, error, "A day of month was identified i"
		"n the time string \"#\", but the month it belongs to could n"
		"ot be identified. ", error_len, (ftnlen)107);
	repmc_(__global_state, error, "#", string, error, error_len, (ftnlen)
		1, string_len, error_len);
    } else if (__state->nmin > __state->nhour) {
	s_copy(&__global_state->f2c, error, "A minutes components of the tim"
		"e  was identified in the time string \"#\", but the hours co"
		"mponent could not be identified. ", error_len, (ftnlen)122);
	repmc_(__global_state, error, "#", string, error, error_len, (ftnlen)
		1, string_len, error_len);
    } else if (__state->nsec > __state->nmin) {
	s_copy(&__global_state->f2c, error, "A seconds components of the tim"
		"e was identified in the time string \"#\", but the minutes c"
		"omponent could not be identified. ", error_len, (ftnlen)123);
	repmc_(__global_state, error, "#", string, error, error_len, (ftnlen)
		1, string_len, error_len);
    }
    ret_val = FALSE_;
    return ret_val;
/* $Procedure ZZVALT ( Private, Time --- Value Based Tokens ) */

L_zzvalt:
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Examine the value of an integer token and if it is within the */
/*     range from B to E replace the token with the new token */
/*     specified by LETTER. */

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

/*      TIME --- PRIVATE */

/* $ Declarations */

/*     IMPLICIT NONE */
/*     CHARACTER*(*)         STRING */
/*     INTEGER               B */
/*     INTEGER               E */
/*     CHARACTER*(1)         LETTER */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     STRING     I   Original time string. */
/*     B          I   Lower bound of value range */
/*     E          I   Upper bound of value range */
/*     LETTER     I   New token if integer is within range. */

/*     The function returns TRUE if any substitutions are performed. */

/* $ Detailed_Input */

/*     STRING     is an original time string as last supplied to ZZTOKNS. */

/*     B          is the lower bound of some test range of integers */

/*     E          is the upper bound of some test range of integers */

/*     LETTER     is the new token value to put in place of 'i' if */
/*                the value of the integer is between B and E */
/*                (inclusive). */
/* $ Detailed_Output */

/*     The function returns TRUE if any substitutions are performed.. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This function replaces every occurrence of 'i' in the internal */
/*     representation by the value LETTER if the numerical value */
/*     of the token corresponding to 'i' is between B and E. */

/*     This is used primarily to identify YEAR tokens in a time */
/*     string. */

/* $ Examples */

/*     See TPARTV */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.2.1, 08-MAR-2009 (NJB) */

/*        Re-ordered header sections. */

/* -    SPICELIB Version 1.2.0, 09-DEC-1999 (WLT) */

/*        The main routine (which should never be called) now returns */
/*        the value .FALSE. */

/* -    SPICELIB Version 1.1.0, 30-JUN-1999 (WLT) */

/*        Added a RETURN statement at the end of the main routine. */
/*        Enhanced error message for the case when the input string */
/*        to ZZTOKNS has a non-printing character. */

/* -    SPICELIB Version 1.0.0, 4-APR-1996 (WLT) */


/* -& */

/*     So far no translations have been performed. */

    __state->did = FALSE_;

/*     Examine each token to see if it is an integer. */

    i__1 = __state->size;
    for (__state->i__ = 1; __state->i__ <= i__1; ++__state->i__) {
	__state->item = *(unsigned char *)&__state->rep[__state->i__ - 1];
	if (__state->item == 'i') {

/*           We've got an integer. Parse it to see if it */
/*           is in the specified range. */

	    __state->j = __state->begs[(i__2 = __state->i__ - 1) < 64 && 0 <= 
		    i__2 ? i__2 : s_rnge(&__global_state->f2c, "begs", i__2, 
		    "zztime_", (ftnlen)3639)];
	    __state->k = __state->ends[(i__2 = __state->i__ - 1) < 64 && 0 <= 
		    i__2 ? i__2 : s_rnge(&__global_state->f2c, "ends", i__2, 
		    "zztime_", (ftnlen)3640)];
	    nparsi_(__global_state, string + (__state->j - 1), &
		    __state->value, __state->myerr, &__state->ptr, __state->k 
		    - (__state->j - 1), (ftnlen)32);
	    if (__state->ptr == 0 && __state->value >= *b && __state->value <=
		     *e) {
		*(unsigned char *)&__state->rep[__state->i__ - 1] = *(
			unsigned char *)letter;
		__state->did = TRUE_;
	    }
	}
    }
    ret_val = __state->did;
    return ret_val;
} /* zztime_ */

logical zztime_(cspice_t* __global_state, char *string, char *transl, char *
	letter, char *error, char *pic, doublereal *tvec, integer *b, integer 
	*e, logical *l2r, logical *yabbrv, ftnlen string_len, ftnlen 
	transl_len, ftnlen letter_len, ftnlen error_len, ftnlen pic_len)
{
    return zztime_0_(__global_state, 0, string, transl, letter, error, pic, 
	    tvec, b, e, l2r, yabbrv, string_len, transl_len, letter_len, 
	    error_len, pic_len);
    }

logical zzcmbt_(cspice_t* __global_state, char *string, char *letter, logical 
	*l2r, ftnlen string_len, ftnlen letter_len)
{
    return zztime_0_(__global_state, 1, string, (char *)0, letter, (char *)0, 
	    (char *)0, (doublereal *)0, (integer *)0, (integer *)0, l2r, (
	    logical *)0, string_len, (ftnint)0, letter_len, (ftnint)0, (
	    ftnint)0);
    }

logical zzgrep_(cspice_t* __global_state, char *string, ftnlen string_len)
{
    return zztime_0_(__global_state, 2, string, (char *)0, (char *)0, (char *)
	    0, (char *)0, (doublereal *)0, (integer *)0, (integer *)0, (
	    logical *)0, (logical *)0, string_len, (ftnint)0, (ftnint)0, (
	    ftnint)0, (ftnint)0);
    }

logical zzispt_(cspice_t* __global_state, char *string, integer *b, integer *
	e, ftnlen string_len)
{
    return zztime_0_(__global_state, 3, string, (char *)0, (char *)0, (char *)
	    0, (char *)0, (doublereal *)0, b, e, (logical *)0, (logical *)0, 
	    string_len, (ftnint)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

logical zzist_(cspice_t* __global_state, char *letter, ftnlen letter_len)
{
    return zztime_0_(__global_state, 4, (char *)0, (char *)0, letter, (char *)
	    0, (char *)0, (doublereal *)0, (integer *)0, (integer *)0, (
	    logical *)0, (logical *)0, (ftnint)0, (ftnint)0, letter_len, (
	    ftnint)0, (ftnint)0);
    }

logical zznote_(cspice_t* __global_state, char *letter, integer *b, integer *
	e, ftnlen letter_len)
{
    return zztime_0_(__global_state, 5, (char *)0, (char *)0, letter, (char *)
	    0, (char *)0, (doublereal *)0, b, e, (logical *)0, (logical *)0, (
	    ftnint)0, (ftnint)0, letter_len, (ftnint)0, (ftnint)0);
    }

logical zzremt_(cspice_t* __global_state, char *letter, ftnlen letter_len)
{
    return zztime_0_(__global_state, 6, (char *)0, (char *)0, letter, (char *)
	    0, (char *)0, (doublereal *)0, (integer *)0, (integer *)0, (
	    logical *)0, (logical *)0, (ftnint)0, (ftnint)0, letter_len, (
	    ftnint)0, (ftnint)0);
    }

logical zzsubt_(cspice_t* __global_state, char *string, char *transl, logical 
	*l2r, ftnlen string_len, ftnlen transl_len)
{
    return zztime_0_(__global_state, 7, string, transl, (char *)0, (char *)0, 
	    (char *)0, (doublereal *)0, (integer *)0, (integer *)0, l2r, (
	    logical *)0, string_len, transl_len, (ftnint)0, (ftnint)0, (
	    ftnint)0);
    }

logical zztokns_(cspice_t* __global_state, char *string, char *error, ftnlen 
	string_len, ftnlen error_len)
{
    return zztime_0_(__global_state, 8, string, (char *)0, (char *)0, error, (
	    char *)0, (doublereal *)0, (integer *)0, (integer *)0, (logical *)
	    0, (logical *)0, string_len, (ftnint)0, (ftnint)0, error_len, (
	    ftnint)0);
    }

logical zzunpck_(cspice_t* __global_state, char *string, logical *yabbrv, 
	doublereal *tvec, integer *e, char *transl, char *pic, char *error, 
	ftnlen string_len, ftnlen transl_len, ftnlen pic_len, ftnlen 
	error_len)
{
    return zztime_0_(__global_state, 9, string, transl, (char *)0, error, pic,
	     tvec, (integer *)0, e, (logical *)0, yabbrv, string_len, 
	    transl_len, (ftnint)0, error_len, pic_len);
    }

logical zzvalt_(cspice_t* __global_state, char *string, integer *b, integer *
	e, char *letter, ftnlen string_len, ftnlen letter_len)
{
    return zztime_0_(__global_state, 10, string, (char *)0, letter, (char *)0,
	     (char *)0, (doublereal *)0, b, e, (logical *)0, (logical *)0, 
	    string_len, (ftnint)0, letter_len, (ftnint)0, (ftnint)0);
    }

