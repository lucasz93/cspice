/* nparsd.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern nparsd_init_t __nparsd_init;
static nparsd_state_t* get_nparsd_state() {
	cspice_t* state =  __cspice_get_state();
	if (!state->nparsd)
		state->nparsd = __cspice_allocate_module(sizeof(
	nparsd_state_t), &__nparsd_init, sizeof(__nparsd_init));
	return state->nparsd;

}

/* $Procedure      NPARSD ( Double Precision parsing of a string ) */
/* Subroutine */ int nparsd_(char *string, doublereal *x, char *error, 
	integer *ptr, ftnlen string_len, ftnlen error_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rnge(char *, integer, char *, integer);
    double d_lg10(doublereal *), d_int(doublereal *);
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_len(char *, ftnlen), 
	    i_dnnt(doublereal *);

    /* Local variables */
    extern /* Subroutine */ int zzinssub_(char *, char *, integer *, char *, 
	    ftnlen, ftnlen, ftnlen);
    extern doublereal dpmax_(void);
    extern doublereal pi_(void);
    extern /* Subroutine */ int prefix_(char *, integer *, char *, ftnlen, 
	    ftnlen);

    /* Module state */
    nparsd_state_t* __state = get_nparsd_state();
/* $ Abstract */

/*     Parse a character string that represents a number and return */
/*     a double precision value. */

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

/*      ALPHANUMERIC */
/*      CONVERSION */
/*      PARSING */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  --------------------------------------------------- */
/*     STRING     I   Character string representing a numeric value. */
/*     X          O   Double precision value parsed from STRING. */
/*     ERROR      O   Message indicating whether errors have occurred. */
/*     PTR        O   Position in string where an error occurred. */

/* $ Detailed_Input */

/*     STRING     A character string that represents a numeric value. */
/*                Commas and spaces may be used in this string for */
/*                ease of reading and writing the number.  They */
/*                are treated as insignificant but non-error-producing */
/*                characters. */

/*                For exponential representation the characters */
/*                'E','D','e','d' may be used. */

/*                The following are legitimate numeric expressions */

/*                 +12.2 e-1 */
/*                 -3. 1415 9276 */
/*                 1e12 */
/*                 E10 */

/*                The program also recognizes the following  mnemonics */
/*                'PI', 'pi', 'Pi', 'pI' */
/*                '+PI', '+pi', '+Pi', '+pI' */
/*                '-PI', '-pi', '-Pi', '-pI' */
/*                and returns the value */
/*                ( + OR - ) 3.1415 9265 3589 7932 3846 2600 D0 as */
/*                appropriate. */

/* $ Detailed_Output */

/*     X          Double precision parsed value of input string. If an */
/*                error is encountered, X is not changed. */

/*     ERROR      is a message indicating that the string could */
/*                not be parsed due to use of an unexpected or misplaced */
/*                character or due to a string representing a number */
/*                too large for double precision.  If the number was */
/*                successfully parsed, ERROR will be returned as a blank. */

/*                In particular, blank strings, or strings that do not */
/*                contain either a digit or exponent character will */
/*                be regarded as errors. */

/*     PTR        This indicates which character was being used when */
/*                the error occurred.  If no error occurs, PTR is */
/*                returned as 0. */

/* $ Parameters */

/*      None. */

/* $ Exceptions */

/*     Error free. */

/*     1) If the string is non-numeric, PTR indicates the location in */
/*        the string where the error occurred, and ERROR contains a */
/*        descriptive error message. */

/* $ Particulars */

/*     This routine parses an input character string that represents a */
/*     number, checks for overflow, unexpected or misplaced */
/*     characters.  It returns the double precision number or an error */
/*     message. */

/* $ Examples */

/*     Let   LINE = 'DELTA_T_A       =   32.184' */

/*     The following code fragment parses the line and obtains the */
/*     double precision value. */


/*        CALL NEXTWD ( LINE,  FIRST,  REST ) */
/*        CALL NEXTWD ( REST, SECOND,  REST ) */
/*        CALL NEXTWD ( REST,  THIRD,  REST ) */

/*        CALL NPARSD (  THIRD,  VALUE, ERROR, PTR    ) */

/* $ Restrictions */

/*     Due to rounding errors this routine may not be able to parse */
/*     the decimal character string representation of the largest */
/*     and smallest double precision numbers. */

/* $ Files */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     K.R. Gehringer  (JPL) */
/*     H.A. Neilan     (JPL) */
/*     W.L. Taber      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 3.5.0, 15-AUG-2002 (WLT) */

/*        Replaced the call to INSSUB with a call to ZZINSSUB so */
/*        that this routine can legitimately call itself Error Free */

/* -    SPICELIB Version 3.4.0, 3-DEC-2001 */

/*        Added an extra check to make sure that ICHAR of any character */
/*        of the input string is positive. */

/* -    SPICELIB Version 3.3.0, 29-FEB-1996 (KRG) */

/*        The declaration for the SPICELIB function PI is now */
/*        preceded by an EXTERNAL statement declaring PI to be an */
/*        external function. This removes a conflict with any */
/*        compilers that have a PI intrinsic function. */

/*        Removed the error message and storage for the unexpected */
/*        comma error message. This variable was set but never used, */
/*        and according to the spec for this routine a comma is a valid */
/*        delimiter, treated like a space, within numbers. */

/* -    SPICELIB Version 3.2.0, 10-JAN-1995 (WLT) */

/*        Changed error strings from parameters to assignments to */
/*        compensate for shortcomings of the Absoft FORTRAN compiler */
/*        on the NeXT. */

/* -    SPICELIB Version 3.1.0, 12-JUL-1994 (WLT) */

/*        The previous version of the routine assumed that the range */
/*        of values of ICHAR was 0 to 128.  That turns out not to be */
/*        true on some machines.  If a character whose ICHAR value is */
/*        outside this range is detected, it is now handled properly */
/*        as an unexpected character. */

/* -    SPICELIB Version 3.0.0, 24-FEB-1993 (WLT) */

/*        The previous version of the algorithm interpreted P or p as 1. */
/*        This was not the intent of the routine and was corrected. */

/* -    SPICELIB Version 2.0.0, 28-AUG-1992 (WLT) (KRG) */

/*        The basic algorithm was completely re-written.  As a result */
/*        the routine now runs an order of magnitude faster than */
/*        it did before.  In addition, strings that do not contain */
/*        enough information to assign a value to the string are now */
/*        regarded as errors.  These include blank strings or strings */
/*        that contain only a sign characters, blanks and commas. */

/*        In addition the error diagnosis and checking for overflow */
/*        was greatly enhanced. */

/*        Note: strings may now parse with slightly different values */
/*        from the previous version of NPARSD.  The current */
/*        implementation is more accurate in converting strings to */
/*        double precision numbers. */

/* -    SPICELIB Version 1.1.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.1.0, 17-APR-1990 (WLT) */

/*        Bug fix.  The subscript used to reference individual characters */
/*        of the input string could sometimes step out of bounds.  This */
/*        went unnoticed until NAIF began compiling with the CHECK=BOUNDS */
/*        option of the DEC Fortran compiler. */


/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (WLT) */

/* -& */
/* $ Index_Entries */

/*     parse a character_string to a d.p. number */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 3.3.0, 29-FEB-1996 (KRG) */

/*        The declaration for the SPICELIB function PI is now */
/*        preceded by an EXTERNAL statement declaring PI to be an */
/*        external function. This removes a conflict with any */
/*        compilers that have a PI intrinsic function. */

/*        Removed the error message and storage for the unexpected */
/*        comma error message. This variable was set but never used, */
/*        and according to the spec for this routine a comma is a valid */
/*        delimiter, treated like a space, within numbers. */

/* -    SPICELIB Version 3.2.0, 10-JAN-1995 (WLT) */

/*        Changed error strings from parameters to assignments to */
/*        compensate for shortcomings of the Absoft FORTRAN compiler */
/*        on the NeXT. */

/* -    SPICELIB Version 3.1.0, 12-JUL-1994 (WLT) */

/*        The previous version of the routine assumed that the range */
/*        of values of ICHAR was 0 to 128.  That turns out not to be */
/*        true on some machines.  If a character whose ICHAR value is */
/*        outside this range is detected, it is now handled properly */
/*        as an unexpected character. */

/* -    SPICELIB Version 3.0.0, 24-FEB-1993 (WLT) */

/*        The previous version of the algorithm interpreted P or p as 1. */
/*        This was not the intent of the routine and was corrected. */

/* -    SPICELIB Version 2.0.0, 28-AUG-1992 (WLT) (KRG) */

/*        The basic algorithm was completely re-written.  As a result */
/*        the routine now runs an order of magnitude faster than */
/*        it did before.  In addition, strings that do not contain */
/*        enough information to assign a value to the string are now */
/*        regarded as errors.  These include blank strings or strings */
/*        that contain only a sign characters, blanks and commas. */

/*        In addition the error diagnosis and checking for overflow */
/*        was greatly enhanced. */

/*        In general the current algorithm is more robust and much */
/*        faster than the previous version. */

/*        Note: strings may now parse with slightly different values */
/*        from the previous version of NPARSD.  The current */
/*        implementation is more accurate in converting strings to */
/*        double precision numbers. */

/* -    SPICELIB Version 1.1.0, 17-APR-1990 (WLT) */

/*        Bug fix.  The subscript used to reference individual characters */
/*        of the input string could sometimes step out of bounds.  This */
/*        went unnoticed until NAIF began compiling with the CHECK=BOUNDS */
/*        option of the DEC Fortran compiler. */

/* -    Beta Version 1.1.0, 16-FEB-1989 (HAN) (NJB) */

/*        Contents of the Exceptions section was changed to "error free" */
/*        to reflect the decision that the module will never participate */
/*        in error handling. */

/*        An example was added to the header, and the Exceptions section */
/*        was completed. */

/*        Declaration of unused variables J, K and unused function */
/*        LASTNB removed. */

/* -& */

/*     SPICELIB functions. */


/*     Local Parameters. */


/*     Save everything.  It's easier than tracking down every */
/*     little variable that might need to be saved. */

    if (__state->first) {
	__state->first = FALSE_;

/*        Set up the error messages */

	s_copy(__state->toobig, "The number represented by the input string "
		"is too large to be stored as a double precision number. ", (
		ftnlen)160, (ftnlen)99);
	s_copy(__state->unxpch, "An unexpected character was found while att"
		"empting to parse the input string. ", (ftnlen)160, (ftnlen)78)
		;
	s_copy(__state->unxppt, "An unexpected decimal point was found in th"
		"e input string. ", (ftnlen)160, (ftnlen)59);
	s_copy(__state->unxpsn, "An unexpected sign character was found in t"
		"he input string. ", (ftnlen)160, (ftnlen)60);
	s_copy(__state->blnkst, "The input string is blank. Blank strings ar"
		"e not considered to be numbers. ", (ftnlen)160, (ftnlen)75);
	s_copy(__state->unrcst, "The input string could not be recognized as"
		" a number. ", (ftnlen)160, (ftnlen)54);
	__state->blank = ' ';
	__state->values[(i__1 = '0' - 1) < 128 && 0 <= i__1 ? i__1 : s_rnge(
		"values", i__1, "nparsd_", (ftnlen)476)] = 0.;
	__state->values[(i__1 = '1' - 1) < 128 && 0 <= i__1 ? i__1 : s_rnge(
		"values", i__1, "nparsd_", (ftnlen)477)] = 1.;
	__state->values[(i__1 = '2' - 1) < 128 && 0 <= i__1 ? i__1 : s_rnge(
		"values", i__1, "nparsd_", (ftnlen)478)] = 2.;
	__state->values[(i__1 = '3' - 1) < 128 && 0 <= i__1 ? i__1 : s_rnge(
		"values", i__1, "nparsd_", (ftnlen)479)] = 3.;
	__state->values[(i__1 = '4' - 1) < 128 && 0 <= i__1 ? i__1 : s_rnge(
		"values", i__1, "nparsd_", (ftnlen)480)] = 4.;
	__state->values[(i__1 = '5' - 1) < 128 && 0 <= i__1 ? i__1 : s_rnge(
		"values", i__1, "nparsd_", (ftnlen)481)] = 5.;
	__state->values[(i__1 = '6' - 1) < 128 && 0 <= i__1 ? i__1 : s_rnge(
		"values", i__1, "nparsd_", (ftnlen)482)] = 6.;
	__state->values[(i__1 = '7' - 1) < 128 && 0 <= i__1 ? i__1 : s_rnge(
		"values", i__1, "nparsd_", (ftnlen)483)] = 7.;
	__state->values[(i__1 = '8' - 1) < 128 && 0 <= i__1 ? i__1 : s_rnge(
		"values", i__1, "nparsd_", (ftnlen)484)] = 8.;
	__state->values[(i__1 = '9' - 1) < 128 && 0 <= i__1 ? i__1 : s_rnge(
		"values", i__1, "nparsd_", (ftnlen)485)] = 9.;
	__state->values[(i__1 = '-' - 1) < 128 && 0 <= i__1 ? i__1 : s_rnge(
		"values", i__1, "nparsd_", (ftnlen)486)] = -1.;
	__state->values[(i__1 = '+' - 1) < 128 && 0 <= i__1 ? i__1 : s_rnge(
		"values", i__1, "nparsd_", (ftnlen)487)] = 1.;
	__state->class__[(i__1 = ' ') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)489)] = 4;
	__state->class__[(i__1 = ',') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)490)] = 4;
	__state->class__[(i__1 = '.') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)492)] = 2;
	__state->class__[(i__1 = 'E') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)494)] = 3;
	__state->class__[(i__1 = 'D') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)495)] = 3;
	__state->class__[(i__1 = 'e') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)496)] = 3;
	__state->class__[(i__1 = 'd') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)497)] = 3;
	__state->class__[(i__1 = '+') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)499)] = 7;
	__state->class__[(i__1 = '-') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)500)] = 7;
	__state->class__[(i__1 = '1') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)502)] = 1;
	__state->class__[(i__1 = '2') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)503)] = 1;
	__state->class__[(i__1 = '3') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)504)] = 1;
	__state->class__[(i__1 = '4') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)505)] = 1;
	__state->class__[(i__1 = '5') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)506)] = 1;
	__state->class__[(i__1 = '6') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)507)] = 1;
	__state->class__[(i__1 = '7') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)508)] = 1;
	__state->class__[(i__1 = '8') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)509)] = 1;
	__state->class__[(i__1 = '9') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)510)] = 1;
	__state->class__[(i__1 = '0') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)511)] = 1;
	__state->class__[(i__1 = 'p') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)513)] = 5;
	__state->class__[(i__1 = 'P') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)514)] = 5;
	__state->class__[(i__1 = 'i') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)515)] = 6;
	__state->class__[(i__1 = 'I') < 129 && 0 <= i__1 ? i__1 : s_rnge(
		"class", i__1, "nparsd_", (ftnlen)516)] = 6;

/*        Finally create the numbers that will be used for checking */
/*        for floating point overflow. */

/*        NOTE: The value for MINEXP may be too small by one, but it */
/*              really doesn't make any difference, as you're going to */
/*              underflow anyway, and dividing zero by a number (BASE) */
/*              still gives you zero. */

	d__2 = dpmax_();
	d__1 = d_lg10(&d__2);
	__state->maxexp = d_int(&d__1);
	__state->minexp = -(__state->maxexp + 1);
	__state->smlbnd = dpmax_() / __state->lookup[10];
	__state->intbnd = 10.;
	__state->next = __state->intbnd + 1.;
	while(__state->intbnd != __state->next) {
	    __state->intbnd *= 10.;
	    __state->next = __state->intbnd + 1.;
	}
	__state->intbnd /= 10.;

/*        That takes care of the first pass initializations. */

    }

/*     Here's what's true right now. */

/*     There are no errors. */
/*     The error pointer doesn't need to point anywhere. */
/*     It's ok for the next token to be a decimal point. */
/*     It's ok for the next token to be a sign character. */
/*     It's ok for the next token to be an exponent marker. */
/*     It's ok for the next character to be the start of pi. */

/*     We expect to be constructing the integer part of the */
/*     numeric string. */

    s_copy(error, " ", error_len, (ftnlen)1);
    *ptr = 0;
    __state->pntok = TRUE_;
    __state->signok = TRUE_;
    __state->expok = TRUE_;
    __state->bpiok = TRUE_;
    __state->doint = TRUE_;
    __state->roundd = TRUE_;
    __state->roundi = TRUE_;

/*     Here's some other facts. */

/*     We are not parsing the decimal part of the string. */
/*     We are not parsing the exponent part of the string. */
/*     We have not encountered any digits in the mantissa. */
/*     We have not encountered any significant characters. */
/*     It's not ok for the next character to be the end of pi (i). */

    __state->dodec = FALSE_;
    __state->doexp = FALSE_;
    __state->mantsa = FALSE_;
    __state->sigchr = FALSE_;
    __state->epiok = FALSE_;

/*     So far there is no integer, decimal or exponent part to this */
/*     string. */

    __state->intval = 0.;
    __state->decval = 0.;
    __state->expval = 0.;
    __state->divisr = 1.;
    __state->factor = 1.;
    __state->ecount = 0.;

/*     Right now if we encounter a sign, it's part of the mantissa. */
/*     And until we know better the sign of both the mantissa and */
/*     exponent are +1 (as opposed to -1). */

    __state->signdx = 1;
    __state->dpsign[0] = 1.;
    __state->dpsign[1] = 1.;

/*     Before doing anything else we determine whether or not */
/*     the input string is empty. */

    if (s_cmp(string, " ", string_len, (ftnlen)1) == 0) {
	s_copy(error, __state->blnkst, error_len, (ftnlen)160);
	*ptr = 1;
	return 0;
    }

/*     We need to find the last non-blank character of the input */
/*     string.  We shall use the idea of binary searching to locate */
/*     this character.  At first this may appear to be a bit convoluted */
/*     when compared to the obvious thing to do (start at the end of */
/*     the string and step backward until a non-blank character is */
/*     located).  However, on every machine we've looked at this method */
/*     locates the last non-blank character much more quickly on average */
/*     than the obvious method. */

/*     L and B denote the last and beginning characters */
/*     of the substring we are searching.  NL is the next to last */
/*     character that we are concerned with and M is the middle of */
/*     the current search interval ( from B to NL ). */

    __state->l = i_len(string, string_len);
    __state->b = 1;
    __state->nl = __state->l - 1;

/*     We want M to be ( B + NL ) / 2   but right now that's L/2 */

    __state->m = __state->l / 2;
    while(__state->l - __state->b > 16) {

/*        What is true right now?  The string from L+1 on out */
/*        is blank.  L > B; L-1 = NL >= B;  M = (B + NL) / 2; */
/*        and M >= B,  B is at least one and if greater than 1 */
/*        there must be a non-blank character between B and the */
/*        end of the string. */

	if (*(unsigned char *)&string[__state->l - 1] != __state->blank) {
	    __state->b = __state->l;
	} else if (s_cmp(string + (__state->m - 1), " ", __state->nl - (
		__state->m - 1), (ftnlen)1) == 0) {

/*           If you got here, the STRING(L:L) is a blank. */
/*           The string from L+1 on out is blank. */
/*           The string from M to NL (=L-1) is blank.  Thus the */
/*           string from M out is blank. */

/*           M is greater than or equal to B. */
/*           If M  is less than B + 2, then L will become */
/*           B or less and there will not be a */
/*           next pass through the loop.  That means that */
/*           we will never get to this point again and don't */
/*           have to worry about the reference STRING(M:NL) */
/*           giving us an access violation. */

	    __state->l = __state->m - 1;

/*           With the new value of L, we now know that STRING(L+1:) */
/*           is blank. */

	} else {

/*           If you get to this point all of the string from */
/*           L out is blank and L is greater than M. */
/*           There is a non-blank character between M and NL. */
/*           If L should get within 16 of B, then the loop */
/*           will not be executed again.  That means again that */
/*           we don't have to worry about STRING(M:NL) being */
/*           an ill formed string. */

	    __state->l = __state->nl;
	    __state->b = __state->m;

/*           With the new value of L, we now know that STRING(L+1:) */
/*           is blank. */

	}

/*        Finally compute NL,the index of the character that precedes */
/*        L and the new midpoint of the stuff from B to NL. */

	__state->nl = __state->l - 1;
	__state->m = (__state->b + __state->nl) / 2;

/*        What's true now?  The string from L+1 on out is blank. */

    }

/*     L is now within 16 characters of the last non-blank character */
/*     of the input string.  We simply search backward from L to */
/*     locate this last non-blank. */

    while(*(unsigned char *)&string[__state->l - 1] == __state->blank) {
	--__state->l;
    }

/*     Begin to collect the number in its various parts: an integer */
/*     portion, a fractional portion, and an exponent. */

    i__1 = __state->l;
    for (__state->i__ = 1; __state->i__ <= i__1; ++__state->i__) {
	__state->id = *(unsigned char *)&string[__state->i__ - 1];
	if (__state->id > 128 || __state->id < 0) {

/*           This is definitely not expected.  Set the error message */
/*           and return. */

	    __state->nexti = __state->i__ + 1;
	    __state->thisi = __state->i__;
	    zzinssub_(string, "]", &__state->nexti, error, string_len, (
		    ftnlen)1, error_len);
	    zzinssub_(error, "[", &__state->thisi, error, error_len, (ftnlen)
		    1, error_len);
	    prefix_(__state->unxpch, &__state->c__1, error, (ftnlen)160, 
		    error_len);
	    *ptr = __state->i__;
	    return 0;

/*        The action taken depends upon the class of the token. */

	} else if (__state->class__[(i__2 = __state->id) < 129 && 0 <= i__2 ? 
		i__2 : s_rnge("class", i__2, "nparsd_", (ftnlen)739)] == 1) {

/*           Once a digit has been encountered, we can no longer */
/*           allow the string 'PI' or a sign until an exponent */
/*           character is hit and resets the SIGNOK flag. */

	    __state->bpiok = FALSE_;
	    __state->epiok = FALSE_;
	    __state->signok = FALSE_;
	    __state->sigchr = TRUE_;

/*           If we are constructing the integer part ... */

	    if (__state->doint) {
		__state->mantsa = TRUE_;

/*              Check the current value of the integer part to */
/*              make sure we don't overflow. */

		if (__state->intval < __state->intbnd) {
		    __state->intval = __state->intval * 10. + __state->values[
			    (i__2 = __state->id - 1) < 128 && 0 <= i__2 ? 
			    i__2 : s_rnge("values", i__2, "nparsd_", (ftnlen)
			    761)];
		} else {

/*                 Once the integer exceeds a given bound, */
/*                 we add the rest on as fractional part and */
/*                 keep track of the factor we will need to */
/*                 multiply the decimal part by to scale things */
/*                 appropriately.  We also keep track of the number */
/*                 we will need to add to the exponent part. */

		    __state->ecount += 1;
		    __state->factor /= 10.;
		    if (__state->roundi) {
			__state->roundi = FALSE_;
			if (__state->values[(i__2 = __state->id - 1) < 128 && 
				0 <= i__2 ? i__2 : s_rnge("values", i__2, 
				"nparsd_", (ftnlen)779)] > 5.) {
			    __state->intval += 1.;
			}
		    }
		}

/*           ... or the decimal part ... */

	    } else if (__state->dodec) {
		__state->mantsa = TRUE_;

/*              There are two cases to consider.  The case in which */
/*              the integer portion of the string has value 0... */

		if (__state->zeroi) {

/*                 We can just keep accumulating the decimal part */
/*                 as an integer.  But we keep track of how many */
/*                 places past the decimal point the first non-zero */
/*                 digit occurs.  Note that once the decimal part */
/*                 exceeds the integer bound, we don't need to do */
/*                 anything.  The remaining digits cannot contribute */
/*                 to the value of the decimal part. */

		    if (__state->decval < __state->intbnd) {
			__state->decval = __state->decval * 10. + 
				__state->values[(i__2 = __state->id - 1) < 
				128 && 0 <= i__2 ? i__2 : s_rnge("values", 
				i__2, "nparsd_", (ftnlen)808)];
			__state->ecount += -1;
		    } else if (__state->roundd) {
			__state->roundd = FALSE_;
			if (__state->values[(i__2 = __state->id - 1) < 128 && 
				0 <= i__2 ? i__2 : s_rnge("values", i__2, 
				"nparsd_", (ftnlen)815)] >= 5.) {
			    __state->decval += 1.;
			}
		    }

/*              ...and the case in which the integer portion is not */
/*              zero. */

		} else {

/*                 In this case, we know there is at least _something_ */
/*                 to the integer part of this string.  We can */
/*                 stop accumulating the decimal part when the divisor */
/*                 portion exceeds the integer barrier.  After that */
/*                 the extra digits can't make any contribution to */
/*                 the double precision value given to the string. */

		    if (__state->divisr < __state->intbnd) {
			__state->decval = __state->decval * 10. + 
				__state->values[(i__2 = __state->id - 1) < 
				128 && 0 <= i__2 ? i__2 : s_rnge("values", 
				i__2, "nparsd_", (ftnlen)835)];
			__state->divisr *= 10.;
		    }
		}

/*           ...or the exponent part of the string. */

	    } else if (__state->doexp) {
		if (__state->expval + __state->ecount > __state->maxexp) {

/*                 This number is too big to put into a double */
/*                 precision number. The marginal case where */
/*                 EXPVAL + ECOUNT .EQ. MAXEXP will be dealt */
/*                 with when the integer and fractional parts */
/*                 of the double precision number are built */
/*                 at the end of this routine. */

		    s_copy(error, __state->toobig, error_len, (ftnlen)160);
		    *ptr = __state->i__;
		    return 0;
		} else if (__state->expval + __state->ecount < 
			__state->minexp) {

/*                 This number is going to underflow, we can */
/*                 just stop accumulating exponent. But we don't */
/*                 stop parsing the string yet. There might be */
/*                 a bad character lurking somewhere later in the */
/*                 string. */

/*                 NOTE: It is also possible to underflow when the */
/*                       value of EXPVAL + ECOUNT is equal to MINEXP, */
/*                       since an entire 'BASE' scale is not supported */
/*                       for this particular exponent. */

		} else {

/*                 This is the case we expect.  Just add on the */
/*                 next part of the exponent. */

		    __state->expval = __state->expval * 10. + __state->dpsign[
			    1] * __state->values[(i__2 = __state->id - 1) < 
			    128 && 0 <= i__2 ? i__2 : s_rnge("values", i__2, 
			    "nparsd_", (ftnlen)877)];
		}

/*           Even though this character is a digit, its not expected */
/*           for some reason.  Set the error flag and return. */

	    } else {
		__state->nexti = __state->i__ + 1;
		__state->thisi = __state->i__;
		zzinssub_(string, "]", &__state->nexti, error, string_len, (
			ftnlen)1, error_len);
		zzinssub_(error, "[", &__state->thisi, error, error_len, (
			ftnlen)1, error_len);
		prefix_(__state->unxpch, &__state->c__1, error, (ftnlen)160, 
			error_len);
		*ptr = __state->i__;
		return 0;
	    }
	} else if (__state->class__[(i__2 = __state->id) < 129 && 0 <= i__2 ? 
		i__2 : s_rnge("class", i__2, "nparsd_", (ftnlen)898)] == 2) {
	    if (__state->pntok) {
		__state->bpiok = FALSE_;
		__state->epiok = FALSE_;
		__state->pntok = FALSE_;
		__state->signok = FALSE_;
		__state->dodec = TRUE_;
		__state->doint = FALSE_;
		__state->doexp = FALSE_;
		__state->zeroi = __state->intval == 0.;
	    } else {
		__state->nexti = __state->i__ + 1;
		__state->thisi = __state->i__;
		zzinssub_(string, "]", &__state->nexti, error, string_len, (
			ftnlen)1, error_len);
		zzinssub_(error, "[", &__state->thisi, error, error_len, (
			ftnlen)1, error_len);
		prefix_(__state->unxppt, &__state->c__1, error, (ftnlen)160, 
			error_len);
		*ptr = __state->i__;
		return 0;
	    }
	} else if (__state->class__[(i__2 = __state->id) < 129 && 0 <= i__2 ? 
		i__2 : s_rnge("class", i__2, "nparsd_", (ftnlen)925)] == 3) {
	    __state->sigchr = TRUE_;
	    if (__state->expok) {
		__state->bpiok = FALSE_;
		__state->epiok = FALSE_;
		__state->expok = FALSE_;
		__state->pntok = FALSE_;
		__state->dodec = FALSE_;
		__state->doint = FALSE_;
		__state->doexp = TRUE_;
		__state->signok = TRUE_;
		__state->signdx = 2;
	    } else {
		__state->nexti = __state->i__ + 1;
		__state->thisi = __state->i__;
		zzinssub_(string, "]", &__state->nexti, error, string_len, (
			ftnlen)1, error_len);
		zzinssub_(error, "[", &__state->thisi, error, error_len, (
			ftnlen)1, error_len);
		prefix_(__state->unxpch, &__state->c__1, error, (ftnlen)160, 
			error_len);
		*ptr = __state->i__;
		return 0;
	    }
	} else if (__state->class__[(i__2 = __state->id) < 129 && 0 <= i__2 ? 
		i__2 : s_rnge("class", i__2, "nparsd_", (ftnlen)955)] == 7) {
	    if (__state->signok) {
		__state->dpsign[(i__2 = __state->signdx - 1) < 2 && 0 <= i__2 
			? i__2 : s_rnge("dpsign", i__2, "nparsd_", (ftnlen)
			959)] = __state->values[(i__3 = __state->id - 1) < 
			128 && 0 <= i__3 ? i__3 : s_rnge("values", i__3, 
			"nparsd_", (ftnlen)959)];
		__state->signok = FALSE_;
	    } else {
		__state->nexti = __state->i__ + 1;
		__state->thisi = __state->i__;
		zzinssub_(string, "]", &__state->nexti, error, string_len, (
			ftnlen)1, error_len);
		zzinssub_(error, "[", &__state->thisi, error, error_len, (
			ftnlen)1, error_len);
		prefix_(__state->unxpsn, &__state->c__1, error, (ftnlen)160, 
			error_len);
		*ptr = __state->i__;
		return 0;
	    }
	} else if (__state->class__[(i__2 = __state->id) < 129 && 0 <= i__2 ? 
		i__2 : s_rnge("class", i__2, "nparsd_", (ftnlen)976)] == 5) {
	    __state->sigchr = TRUE_;
	    if (__state->bpiok) {
		__state->doint = FALSE_;
		__state->dodec = FALSE_;
		__state->doexp = FALSE_;
		__state->expok = FALSE_;
		__state->pntok = FALSE_;
		__state->bpiok = FALSE_;
		__state->signok = FALSE_;
		__state->epiok = TRUE_;
	    } else {
		__state->nexti = __state->i__ + 1;
		__state->thisi = __state->i__;
		zzinssub_(string, "]", &__state->nexti, error, string_len, (
			ftnlen)1, error_len);
		zzinssub_(error, "[", &__state->thisi, error, error_len, (
			ftnlen)1, error_len);
		prefix_(__state->unxpch, &__state->c__1, error, (ftnlen)160, 
			error_len);
		*ptr = __state->i__;
		return 0;
	    }
	} else if (__state->class__[(i__2 = __state->id) < 129 && 0 <= i__2 ? 
		i__2 : s_rnge("class", i__2, "nparsd_", (ftnlen)1005)] == 6) {
	    if (__state->epiok) {
		__state->doint = FALSE_;
		__state->dodec = FALSE_;
		__state->doexp = FALSE_;
		__state->expok = FALSE_;
		__state->pntok = FALSE_;
		__state->bpiok = FALSE_;
		__state->signok = FALSE_;
		__state->epiok = FALSE_;
		__state->mantsa = TRUE_;
		__state->intval = pi_();
	    } else {
		__state->nexti = __state->i__ + 1;
		__state->thisi = __state->i__;
		zzinssub_(string, "]", &__state->nexti, error, string_len, (
			ftnlen)1, error_len);
		zzinssub_(error, "[", &__state->thisi, error, error_len, (
			ftnlen)1, error_len);
		prefix_(__state->unxpch, &__state->c__1, error, (ftnlen)160, 
			error_len);
		*ptr = __state->i__;
		return 0;
	    }
	} else if (__state->class__[(i__2 = __state->id) < 129 && 0 <= i__2 ? 
		i__2 : s_rnge("class", i__2, "nparsd_", (ftnlen)1035)] == 4) {

/*           We don't do anything. */

	} else {

/*           This is definitely not expected.  Set the error message */
/*           and return. */

	    __state->nexti = __state->i__ + 1;
	    __state->thisi = __state->i__;
	    zzinssub_(string, "]", &__state->nexti, error, string_len, (
		    ftnlen)1, error_len);
	    zzinssub_(error, "[", &__state->thisi, error, error_len, (ftnlen)
		    1, error_len);
	    prefix_(__state->unxpch, &__state->c__1, error, (ftnlen)160, 
		    error_len);
	    *ptr = __state->i__;
	    return 0;
	}
    }

/*     If we got through the loop and it's OK to end PI, then we started */
/*     it but never finished.  This is an error. */

    if (__state->epiok) {
	s_copy(error, __state->unrcst, error_len, (ftnlen)160);
	*ptr = __state->l;
	return 0;
    }

/*     Put together the portion that does not involve an exponent. */

/*     If */
/*        (1) MANTSA = .TRUE., then we had some explicit part of a */
/*            number, an  integer part, a fractional part, or both. */

/*        (2) SIGCHR = .TRUE, then we had either: */

/*            (a) MANTSA = .TRUE. */

/*         or */

/*            (b) there was an implicit value associated with the input */
/*                string. For example, an exponent character followed */
/*                by an optional exponent would produce a valid number: */
/*                E+10 --> 1.0d+10. This is due to the fact that this */
/*                routine emulates an RPN calculator of popular repute, */
/*                not because it is inherently a good idea. */

    if (__state->mantsa) {

/*        We had an integer part of the number, a fractional part, or */
/*        both, so we need to put them together in an appropriate */
/*        fashion. */

	__state->value = __state->intval + __state->decval / __state->divisr *
		 __state->factor;
    } else if (__state->sigchr) {

/*        We do not have a mantissa, so we had an  implicit mantissa, */
/*        see above, so we need to set the value to one. */

	__state->value = 1.;
    } else {

/*        We have an error. There were no significant characters in the */
/*        input character string, and hence we could not parse it into */
/*        a number. An example of such a string would be: '+  ,,.,,'. */
/*        So, we will set an appropriate error message and return. */

	s_copy(error, __state->unrcst, error_len, (ftnlen)160);
	*ptr = i_len(string, string_len) + 1;
	return 0;
    }

/*     Adjust the entered part of the exponent by the amount */
/*     we "shifted" the decimal point when we were computing */
/*     the integer and decimal values. */

    __state->expval += __state->ecount;

/*     Now take care of the exponent contribution to the answer. */

/*     If the exponent is negative ... */

    if (__state->expval < 0.) {
	while(__state->expval < -10.) {
	    __state->value /= __state->lookup[10];
	    __state->expval += 10.;
	}
	__state->value /= __state->lookup[(i__1 = -((integer) __state->expval)
		) < 11 && 0 <= i__1 ? i__1 : s_rnge("lookup", i__1, "nparsd_",
		 (ftnlen)1139)];

/*     If the exponent is positive ... */

    } else if (__state->expval > 0.) {
	while(__state->expval > 10.) {

/*           Make sure that a multiply isn't going to create */
/*           a number that overflows. */

	    if (__state->value >= __state->smlbnd) {
		s_copy(error, __state->toobig, error_len, (ftnlen)160);
		*ptr = i_len(string, string_len) + 1;
		return 0;
	    } else {
		__state->value *= __state->lookup[10];
		__state->expval += -10.;
	    }
	}
	__state->exp__ = i_dnnt(&__state->expval);

/*        Again, make sure that a floating point overflow isn't */
/*        going to happen. */

	if (__state->value < dpmax_() / __state->lookup[(i__1 = 
		__state->exp__) < 11 && 0 <= i__1 ? i__1 : s_rnge("lookup", 
		i__1, "nparsd_", (ftnlen)1172)]) {
	    __state->value *= __state->lookup[(i__1 = __state->exp__) < 11 && 
		    0 <= i__1 ? i__1 : s_rnge("lookup", i__1, "nparsd_", (
		    ftnlen)1174)];
	} else {
	    s_copy(error, __state->toobig, error_len, (ftnlen)160);
	    *ptr = i_len(string, string_len) + 1;
	    return 0;
	}
    }
    *x = __state->dpsign[0] * __state->value;
    return 0;
} /* nparsd_ */

