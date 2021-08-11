/* zzrvbf.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzrvbf_init_t __zzrvbf_init;
static zzrvbf_state_t* get_zzrvbf_state() {
	cspice_t* state =  __cspice_get_state();
	if (!state->zzrvbf)
		state->zzrvbf = __cspice_allocate_module(sizeof(
	zzrvbf_state_t), &__zzrvbf_init, sizeof(__zzrvbf_init));
	return state->zzrvbf;

}

/* $Procedure ZZRVBF ( Private --- Pool, read the next buffer variable ) */
/* Subroutine */ int zzrvbf_(char *buffer, integer *bsize, integer *linnum, 
	integer *namlst, integer *nmpool, char *names, integer *datlst, 
	integer *dppool, doublereal *dpvals, integer *chpool, char *chvals, 
	char *varnam, logical *eof, ftnlen buffer_len, ftnlen names_len, 
	ftnlen chvals_len, ftnlen varnam_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_len(char *, ftnlen), 
	    s_rnge(char *, integer, char *, integer);

    /* Local variables */
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    extern /* Subroutine */ int errch_(char *, char *, ftnlen, ftnlen);
    extern /* Subroutine */ int lnkan_(integer *, integer *);
    extern integer rtrim_(char *, ftnlen);
    extern /* Subroutine */ int zzcln_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
    extern logical failed_(void);
    extern /* Subroutine */ int lnkila_(integer *, integer *, integer *);
    extern integer lastpc_(char *, ftnlen);
    extern integer lnknfn_(integer *);
    extern integer zzhash_(char *, ftnlen);
    extern /* Subroutine */ int chkout_(char *, ftnlen);
    extern logical return_(void);
    extern /* Subroutine */ int setmsg_(char *, ftnlen);
    extern /* Subroutine */ int errint_(char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(char *, ftnlen);
    extern /* Subroutine */ int lnkfsl_(integer *, integer *, integer *);
    extern /* Subroutine */ int tparse_(char *, doublereal *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int nparsd_(char *, doublereal *, char *, integer 
	    *, ftnlen, ftnlen);


    /* Module state */
    zzrvbf_state_t* __state = get_zzrvbf_state();
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Read the next variable from a text buffer into the kernel pool. */

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

/*     PRIVATE KERNEL */

/* $ Keywords */

/*     POOL */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     BUFFER     I   Array of text to be read and parsed. */
/*     BSIZE      I   Number of lines in text buffer. */
/*     LINNUM    I/O  line number to begin reading buffer */
/*     NAMLST    I/O  array of collision resolution list heads */
/*     NMPOOL    I/O  linked list pool of collision resolution lists */
/*     NAMES     I/O  array of names of kernel pool variables */
/*     DATLST    I/O  array of heads of lists of variable values */
/*     DPPOOL    I/O  linked list pool of pointer lists to d.p. values */
/*     DPVALS    I/O  array of d.p. kernel pool values */
/*     CHPOOL    I/O  linked list pool of pointer lists to string values */
/*     CHVALS    I/O  array of string kernel pool values */
/*     VARNAM     O   name of variable parsed */
/*     EOF        O   if TRUE end of input file has been reached. */

/* $ Detailed_Input */

/*     BUFFER    is a string array that contains the text that should */
/*               be parsed and placed into the kernel pool data */
/*               structure. */

/*     BSIZE     is the number of lines of text in BUFFER. */

/*     LINNUM    the line number (in BUFFER) at which to begin parsing */
/*               text. */

/*     NAMLST    this collection of arrays together with the hash */
/*     NMPOOL    function ZZHASH provide the mechanism for storing */
/*     NAMES     and retrieving kernel pool variables. */
/*     DATLST */
/*     DPPOOL    Given a potential variable name NAME the function */
/*     DPVALS    ZZHASH(NAME) gives the location in the array in */
/*     CHPOOL    NAMLST where one should begin looking for the */
/*     CHVALS    kernel pool variable NAME. */

/*               If NAMLST( ZZHASH(NAME) ) is zero, there is no kernel */
/*               pool variable corresponding to NAME.  If it is non-zero */
/*               then NAMLST is the head node of a linked list of names */
/*               that evaluate to the same integer under the function */
/*               ZZHASH.  Letting NODE = NAMLST( ZZHASH(NAME) ) check */
/*               NAMES(NODE) for equality with NAME.  If there is */
/*               no match find the next node ( NMPOOL(NEXT,NODE) ) until */
/*               a match occurs or all nodes of the list have been */
/*               examined.  To insert a new NAME allocate a node NEW from */
/*               the free list of NMPOOL and append it to the tail of the */
/*               list pointed to by NAMLST ( ZZHASH(NAME) ). */

/*               Once a node for NAME is located (call it NAMEAT) */
/*               the values for NAME can be found by examining */
/*               DATLST(NAMEAT).  If zero, no values have yet been */
/*               given to NAME.  If less than zero, -DATLST(NAMEAT) */
/*               is the head node of a list in CHPOOL that gives the */
/*               indexes of the values of NAME in CHVALS.  If greater */
/*               than zero, DATLST(NAMEAT) is the head node of a list */
/*               in DPPOOL that gives the indexes of the values of NAME */
/*               in DPVALS. */




/* $ Detailed_Output */

/*     LINNUM     is the line number at which the "next" read should */
/*                begin. */

/*     NAMLST     is the same structure as input but updated to */
/*     NMPOOL     include the next variable read from the text buffer. */
/*     NAMES */
/*     DATLST */
/*     DPPOOL */
/*     DPVALS */
/*     CHPOOL */
/*     CHVALS */

/*     VARNAM     is the name of the variable. VARNAM is blank if */
/*                no variable is read. */

/*     EOF        is true when the end of the internal buffer has been */
/*                reached, and is false otherwise. */

/* $ Parameters */

/*      LINLEN      is the maximum length of a line in the buffer. */

/*      MAXLEN      is the maximum length of the variable names that */
/*                  can be stored in the kernel pool (defined in pool.f). */

/* $ Exceptions */


/*     1) The error 'SPICE(BADTIMESPEC)' is signalled if a value */
/*        beginning with '@' cannot be parsed as a time. */

/*     2) The error 'SPICE(BADVARASSIGN)' is signalled if variable */
/*        assignment does not have the form NAME = [(] value [ value ) ]. */

/*     3) The error 'SPICE(KERNELPOOLFULL)' is signalled if there is */
/*        no room left in the kernel pool to store another variable */
/*        or value. */

/*     4) The error 'SPICE(NONPRINTINGCHAR)' is signalled if the name */
/*        in a variable assignment contains a non-printing character. */

/*     5) The error 'SPICE(NUMBEREXPECTED)' is signalled if a value */
/*        that is unquoted cannot be parsed as time or number. */

/*     6) The error 'SPICE(TYPEMISMATCH)' is signalled if a variable */
/*        has a first value of one type (numeric or character) and */
/*        a subsequent component has the other type. */

/*     7) The error 'SPICE(BADVARNAME)' signals if a kernel pool */
/*        variable name length exceeds MAXLEN. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     None. */

/* $ Examples */

/*     See POOL (entry point LMPOOL). */

/* $ Restrictions */

/*     The input buffer should be no more than 132 characters in width. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 09-FEB-2010 (EDW) */

/*        Added an error check on the length of the kernel pool variable */
/*        names read from BUFFER. */

/* -    SPICELIB Version 1.0.0, 29-MAR-1999 (WLT) */

/* -& */


/*     SPICELIB functions */


/*     Local parameters. */

/*     Below are a collection of enumerated lists that are used */
/*     to discern what part of the processing we are in and what */
/*     kind of entity we are dealing with.  First the overall */
/*     processing flow of a variable assignment. */


/*     Next we have the various types of tokens that can be found */
/*     in the parsing of an input line */

/*     Q   --- quoted (or protected tokens) */
/*     NQ  --- unquoted tokens */
/*     BV  --- beginning of a vector */
/*     EV  --- ending of a vector */
/*     EQ  --- equal sign */
/*     EQP --- equal sign plus */


/*     A variable can have one of three types as we process */
/*     it.  It can have an unknown type UNKNWN, STRTYP or NUMTYP. */



/*     The next two parameters indicate which component of a linked */
/*     list node point to the previous node and the next node. */


/*     The next collection of variables are set up in first pass */
/*     through this routine.  They would be parameters if FORTRAN */
/*     allowed us to do this in a standard way. */


/*     The logicals below are used to take apart the tokens in an */
/*     input line. */


/*     The following logicals are in-line functions that are used */
/*     when processing the input strings. */


/*     Save everything. */


/*     Below are a collection of In-line function definitions that are */
/*     intended to make the code a bit easier to write and read. */


/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    } else {
	chkin_("ZZRVBF", (ftnlen)6);
    }

/*     Initializations. */

    if (__state->first) {
	__state->first = FALSE_;
	__state->icomma = ',';
	__state->iblank = ' ';
	__state->iquote = '\'';
	__state->ilparn = '(';
	__state->irparn = ')';
	__state->iequal = '=';
	__state->iplus = '+';
	__state->itmark = '@';
	__state->itab = 9;
    }

/*     No variable yet and no parsing errors so far. */

    s_copy(__state->name__, " ", (ftnlen)132, (ftnlen)1);
    s_copy(__state->error, " ", (ftnlen)256, (ftnlen)1);
    __state->ncomp = 0;

/*     Get the next data line. Unless something is terribly wrong, */
/*     this will begin a new variable definition. We have to read */
/*     the whole variable, unless we get an error, in which case */
/*     we can quit. */

    __state->status = 1;
    while(__state->status != 2 && ! failed_()) {
	s_copy(__state->line, " ", (ftnlen)132, (ftnlen)1);

/*        We need to skip blank lines... */

	while(s_cmp(__state->line, " ", (ftnlen)132, (ftnlen)1) == 0) {
	    *eof = *linnum > *bsize;
	    if (*eof) {
		chkout_("ZZRVBF", (ftnlen)6);
		return 0;
	    }
	    s_copy(__state->line, buffer + (*linnum - 1) * buffer_len, (
		    ftnlen)132, buffer_len);
	    ++(*linnum);
	}

/*        Find the "tokens" in the input line. As you scan from left */
/*        to right along the line, exactly one of the following */
/*        conditions is true. */

/*        1) You are in a separator field */
/*        4) You are in a quoted substring */
/*        5) You are in a non-quoted substring that isn't a separator */
/*           field. */

/*        Stuff between separator fields are regarded as tokens.  Note */
/*        this includes quoted strings. */

/*        In addition we keep track of 3 separators: '=', '(', ')' */
/*        Finally, whenever we encounters the separator '=', we back */
/*        up and see if it is preceded by a '+', if so we attach */
/*        it to the '=' and treat the pair of characters as a single */
/*        separator. */

	__state->even = TRUE_;
	__state->intokn = FALSE_;
	__state->inquot = FALSE_;
	__state->insepf = TRUE_;
	__state->count = 0;
	__state->i__ = 0;
	while(__state->i__ < i_len(__state->line, (ftnlen)132)) {

/*           The current character is either a separator, quote or */
/*           some other character. */

	    ++__state->i__;
	    __state->code = *(unsigned char *)&__state->line[__state->i__ - 1]
		    ;
	    if (__state->code == __state->iblank || __state->code == 
		    __state->icomma || __state->code == __state->ilparn || 
		    __state->code == __state->irparn || __state->code == 
		    __state->iequal || __state->code == __state->itab) {

/*              There are 3 possible states we could be in */
/*                 Separation Field */
/*                 A quoted substring with the last quote an odd one. */
/*                 A quoted substring with the last quote an even one. */
/*                 A non-quoted token. */
/*              In the first two cases nothing changes, but in the */
/*              next two cases we transition to a separation field. */

		if (__state->intokn || __state->inquot && __state->even) {
		    __state->inquot = FALSE_;
		    __state->intokn = FALSE_;
		    __state->insepf = TRUE_;
		}
		if (__state->insepf) {

/*                 We need to see if this is one of the special */
/*                 separators */

		    if (__state->code == __state->iequal) {
			++__state->count;
			__state->begs[(i__1 = __state->count - 1) < 132 && 0 
				<= i__1 ? i__1 : s_rnge("begs", i__1, "zzrvb"
				"f_", (ftnlen)544)] = __state->i__;
			__state->type__[(i__1 = __state->count - 1) < 132 && 
				0 <= i__1 ? i__1 : s_rnge("type", i__1, "zzr"
				"vbf_", (ftnlen)545)] = 5;
			__state->ends[(i__1 = __state->count - 1) < 132 && 0 
				<= i__1 ? i__1 : s_rnge("ends", i__1, "zzrvb"
				"f_", (ftnlen)546)] = __state->i__;
			if (__state->i__ > 1) {

/*                       Look back at the previous character. */
/*                       See if it is a plus character. */

			    i__1 = __state->i__ - 2;
			    __state->code = *(unsigned char *)&__state->line[
				    i__1];
			    if (__state->code == __state->iplus) {

/*                          This is the directive '+=' we need */
/*                          to set the beginning of this token */
/*                          to the one before this and adjust */
/*                          the end of the last token. */

				__state->type__[(i__1 = __state->count - 1) < 
					132 && 0 <= i__1 ? i__1 : s_rnge(
					"type", i__1, "zzrvbf_", (ftnlen)562)]
					 = 6;
				__state->begs[(i__1 = __state->count - 1) < 
					132 && 0 <= i__1 ? i__1 : s_rnge(
					"begs", i__1, "zzrvbf_", (ftnlen)563)]
					 = __state->i__ - 1;
				if (__state->begs[(i__1 = __state->count - 2) 
					< 132 && 0 <= i__1 ? i__1 : s_rnge(
					"begs", i__1, "zzrvbf_", (ftnlen)565)]
					 == __state->ends[(i__2 = 
					__state->count - 2) < 132 && 0 <= 
					i__2 ? i__2 : s_rnge("ends", i__2, 
					"zzrvbf_", (ftnlen)565)]) {
				    --__state->count;
				    __state->begs[(i__1 = __state->count - 1) 
					    < 132 && 0 <= i__1 ? i__1 : 
					    s_rnge("begs", i__1, "zzrvbf_", (
					    ftnlen)569)] = __state->i__ - 1;
				    __state->ends[(i__1 = __state->count - 1) 
					    < 132 && 0 <= i__1 ? i__1 : 
					    s_rnge("ends", i__1, "zzrvbf_", (
					    ftnlen)570)] = __state->i__;
				    __state->type__[(i__1 = __state->count - 
					    1) < 132 && 0 <= i__1 ? i__1 : 
					    s_rnge("type", i__1, "zzrvbf_", (
					    ftnlen)571)] = 6;
				} else {
				    __state->ends[(i__1 = __state->count - 2) 
					    < 132 && 0 <= i__1 ? i__1 : 
					    s_rnge("ends", i__1, "zzrvbf_", (
					    ftnlen)575)] = __state->ends[(
					    i__2 = __state->count - 2) < 132 
					    && 0 <= i__2 ? i__2 : s_rnge(
					    "ends", i__2, "zzrvbf_", (ftnlen)
					    575)] - 1;
				}
			    }
			}
		    } else if (__state->code == __state->irparn) {
			++__state->count;
			__state->begs[(i__1 = __state->count - 1) < 132 && 0 
				<= i__1 ? i__1 : s_rnge("begs", i__1, "zzrvb"
				"f_", (ftnlen)586)] = __state->i__;
			__state->ends[(i__1 = __state->count - 1) < 132 && 0 
				<= i__1 ? i__1 : s_rnge("ends", i__1, "zzrvb"
				"f_", (ftnlen)587)] = __state->i__;
			__state->type__[(i__1 = __state->count - 1) < 132 && 
				0 <= i__1 ? i__1 : s_rnge("type", i__1, "zzr"
				"vbf_", (ftnlen)588)] = 4;
		    } else if (__state->code == __state->ilparn) {
			++__state->count;
			__state->begs[(i__1 = __state->count - 1) < 132 && 0 
				<= i__1 ? i__1 : s_rnge("begs", i__1, "zzrvb"
				"f_", (ftnlen)593)] = __state->i__;
			__state->ends[(i__1 = __state->count - 1) < 132 && 0 
				<= i__1 ? i__1 : s_rnge("ends", i__1, "zzrvb"
				"f_", (ftnlen)594)] = __state->i__;
			__state->type__[(i__1 = __state->count - 1) < 132 && 
				0 <= i__1 ? i__1 : s_rnge("type", i__1, "zzr"
				"vbf_", (ftnlen)595)] = 3;
		    }
		}
	    } else if (__state->code == __state->iquote) {

/*              There are 3 cases of interest. */
/*                 We are in a quoted substring already */
/*                 We are in a separator field */
/*                 We are in a non-quoted token. */
/*              In the first case nothing changes.  In the second */
/*              two cases we change to being in a quoted substring. */

		__state->even = ! __state->even;
		if (! __state->inquot) {
		    __state->insepf = FALSE_;
		    __state->intokn = FALSE_;
		    __state->inquot = TRUE_;
		    ++__state->count;
		    __state->begs[(i__1 = __state->count - 1) < 132 && 0 <= 
			    i__1 ? i__1 : s_rnge("begs", i__1, "zzrvbf_", (
			    ftnlen)618)] = __state->i__;
		    __state->type__[(i__1 = __state->count - 1) < 132 && 0 <= 
			    i__1 ? i__1 : s_rnge("type", i__1, "zzrvbf_", (
			    ftnlen)619)] = 1;
		}
		__state->ends[(i__1 = __state->count - 1) < 132 && 0 <= i__1 ?
			 i__1 : s_rnge("ends", i__1, "zzrvbf_", (ftnlen)623)] 
			= __state->i__;
	    } else {

/*              This is some character other than a quote, or */
/*              separator character. */

/*              We are in one of four situations. */

/*                 1) We are in a quoted substring with an odd number of */
/*                    quotes. */
/*                 2) We are in a quoted substring with an even number of */
/*                    quotes. */
/*                 2) We are in a separator field */
/*                 3) We are in a non-quoted token. */

/*              In cases 1 and 3 nothing changes. So we won't check */
/*              those cases. */

		if (__state->insepf || __state->inquot && __state->even) {
		    __state->inquot = FALSE_;
		    __state->insepf = FALSE_;
		    __state->intokn = TRUE_;
		    ++__state->count;
		    __state->begs[(i__1 = __state->count - 1) < 132 && 0 <= 
			    i__1 ? i__1 : s_rnge("begs", i__1, "zzrvbf_", (
			    ftnlen)648)] = __state->i__;
		    __state->type__[(i__1 = __state->count - 1) < 132 && 0 <= 
			    i__1 ? i__1 : s_rnge("type", i__1, "zzrvbf_", (
			    ftnlen)649)] = 2;
		}
		__state->ends[(i__1 = __state->count - 1) < 132 && 0 <= i__1 ?
			 i__1 : s_rnge("ends", i__1, "zzrvbf_", (ftnlen)652)] 
			= __state->i__;
	    }
	}

/*        The first word on the first line should be the name of a */
/*        variable. The second word should be a directive: = or +=. */

	if (__state->status == 1) {

/*           There must be at least 3 contributing tokens on this line. */

	    if (__state->count < 3) {
		setmsg_("A kernel variable was not properly formed on line #"
			" text buffer.Such an assignment should have the form"
			": '<variable name> [+]= <values>'. This line was '#'"
			". ", (ftnlen)157);
		__state->r2 = rtrim_(__state->line, (ftnlen)132);
		errint_("#", linnum, (ftnlen)1);
		errch_("#", __state->line, (ftnlen)1, __state->r2);
		sigerr_("SPICE(BADVARASSIGN)", (ftnlen)19);
		chkout_("ZZRVBF", (ftnlen)6);
		return 0;
	    }

/*           See if the variable name is legitimate: */

	    i__1 = __state->begs[0] - 1;
	    __state->badat = lastpc_(__state->line + i__1, __state->ends[0] - 
		    i__1);
	    if (__state->badat <= __state->ends[0] - __state->begs[0]) {

/*              There is a non-printing character in the variable */
/*              name.  This isn't allowed. */

		__state->at = __state->begs[0] + __state->badat;
		setmsg_("There is a non-printing character embedded in line "
			"# of the text buffer.  Non-printing characters are n"
			"ot allowed in kernel variable assignments.  The non-"
			"printing character has ASCII code #. ", (ftnlen)192);
		errint_("#", linnum, (ftnlen)1);
		i__1 = *(unsigned char *)&__state->line[__state->at - 1];
		errint_("#", &i__1, (ftnlen)1);
		sigerr_("SPICE(NONPRINTINGCHAR)", (ftnlen)22);
		chkout_("ZZRVBF", (ftnlen)6);
		return 0;
	    }

/*           Check the variable name length; signal an error */
/*           if longer than MAXLEN. */

	    i__1 = __state->begs[0] - 1;
	    __state->varlen = i_len(__state->line + i__1, __state->ends[0] - 
		    i__1);
	    if (__state->varlen > 32) {
		setmsg_("A kernel pool variable name in the input buffer exc"
			"eeds the maximum allowed length #1. The actual lengt"
			"h of the variable name is #2, the offending variable"
			" name to #3 characters: '#4'.", (ftnlen)184);
		errint_("#1", &__state->c__32, (ftnlen)2);
		errint_("#2", &__state->varlen, (ftnlen)2);
		errint_("#3", &__state->c__132, (ftnlen)2);
		i__1 = __state->begs[0] - 1;
		errch_("#4", __state->line + i__1, (ftnlen)2, __state->ends[0]
			 - i__1);
		sigerr_("SPICE(BADVARNAME)", (ftnlen)17);
	    }

/*           The variable name is ok. How about the directive. */

	    i__1 = __state->begs[0] - 1;
	    s_copy(varnam, __state->line + i__1, varnam_len, __state->ends[0] 
		    - i__1);
	    __state->dirctv = __state->type__[1];

/*           If this is replacement (=) and not an addition (+=), */
/*           delete the values currently associated with the variable. */
/*           They will be replaced later. */

	    if (__state->dirctv != 5 && __state->dirctv != 6) {
		setmsg_("A kernel variable was not properly formed on line #"
			" of the text buffer. Such an assignment should have "
			"the form: '<variable name> [+]= <values>'.  More spe"
			"cifically, the assignment operator did not have one "
			"of the expected forms: '=' or '+='. The line was '#'"
			". ", (ftnlen)261);
		__state->r2 = rtrim_(__state->line, (ftnlen)132);
		errint_("#", linnum, (ftnlen)1);
		errch_("#", __state->line, (ftnlen)1, __state->r2);
		sigerr_("SPICE(BADVARASSIGN)", (ftnlen)19);
		chkout_("ZZRVBF", (ftnlen)6);
		return 0;
	    }

/*           Locate this variable name in the name pool or insert it */
/*           if it isn't there.  The location will be NAMEAT and */
/*           we will use the variable FOUND to indicate whether or */
/*           not it was already present. */

	    __state->lookat = zzhash_(varnam, varnam_len);
	    __state->node = namlst[__state->lookat - 1];
	    __state->full = lnknfn_(nmpool) <= 0;
	    __state->found = FALSE_;

/*           See if this name (or one colliding with it in the */
/*           hash scheme) has already been stored in the name list. */

	    if (__state->node > 0) {
		__state->head = __state->node;
		__state->tail = -nmpool[(__state->head << 1) + 11];
		while(__state->node > 0 && ! __state->found) {
		    __state->found = s_cmp(names + (__state->node - 1) * 
			    names_len, varnam, names_len, varnam_len) == 0;
		    __state->nameat = __state->node;
		    __state->node = nmpool[(__state->node << 1) + 10];
		}
		if (! __state->found && ! __state->full) {

/*                 We didn't find this name on the conflict resolution */
/*                 list. Allocate a new slot for it. */

		    lnkan_(nmpool, &__state->node);
		    lnkila_(&__state->tail, &__state->node, nmpool);
		    s_copy(names + (__state->node - 1) * names_len, varnam, 
			    names_len, varnam_len);
		    __state->nameat = __state->node;
		}
	    } else if (! __state->full) {

/*              Nothing like this variable name (in the hashing sense) */
/*              has been loaded so far.  We need to allocate */
/*              a name slot for this variable. */

		lnkan_(nmpool, &__state->node);
		namlst[__state->lookat - 1] = __state->node;
		s_copy(names + (__state->node - 1) * names_len, varnam, 
			names_len, varnam_len);
		__state->nameat = __state->node;
	    }

/*           If the name pool was full and we didn't find this name */
/*           we've got an error. Diagnose it and return. */

	    if (__state->full && ! __state->found) {
		setmsg_("The kernel pool does not have room for any more var"
			"iables.  It filled up at line # of the text buffer. ",
			 (ftnlen)103);
		errint_("#", linnum, (ftnlen)1);
		sigerr_("SPICE(KERNELPOOLFULL)", (ftnlen)21);
		chkout_("ZZRVBF", (ftnlen)6);
		return 0;
	    }

/*           Now depending upon the kind of directive, we will need */
/*           to remove data and allocate a new list or simply append */
/*           data to the existing list. */

	    if (__state->dirctv == 5) {

/*              We are going to dump whatever is associated with */
/*              this name and then we will need to allocate a new */
/*              linked list for the data. */

		__state->vartyp = 3;
		if (__state->found) {

/*                 We need to free the data associated with this */
/*                 variable. */

		    __state->datahd = datlst[__state->nameat - 1];
		    datlst[__state->nameat - 1] = 0;
		    if (__state->datahd < 0) {

/*                    This variable was character type we need to */
/*                    free a linked list from the character data */
/*                    pool. */

			__state->head = -__state->datahd;
			__state->tail = -chpool[(__state->head << 1) + 11];
			lnkfsl_(&__state->head, &__state->tail, chpool);
		    } else {

/*                    This variable was numeric type. We need to */
/*                    free a linked list from the numeric pool. */

			__state->head = __state->datahd;
			__state->tail = -dppool[(__state->head << 1) + 11];
			lnkfsl_(&__state->head, &__state->tail, dppool);
		    }
		}
	    } else if (__state->dirctv == 6) {

/*              We need to append to the current variable. */

		if (__state->found) {
		    if (datlst[__state->nameat - 1] > 0) {
			__state->vartyp = 2;
		    } else if (datlst[__state->nameat - 1] < 0) {
			__state->vartyp = 1;
		    } else {
			__state->vartyp = 3;
		    }
		} else {
		    __state->vartyp = 3;
		}
	    }

/*           If this is a vector, the next thing on the line will be a */
/*           left parenthesis. Otherwise, assume that this is a scalar. */
/*           If it's a vector, get the first value. If it's a scalar, */
/*           plant a bogus right parenthesis, to make the following loop */
/*           terminate after one iteration. */

	    if (__state->type__[2] == 3) {
		__state->nxttok = 4;
	    } else {
		__state->nxttok = 3;
		++__state->count;
		__state->type__[(i__1 = __state->count - 1) < 132 && 0 <= 
			i__1 ? i__1 : s_rnge("type", i__1, "zzrvbf_", (ftnlen)
			921)] = 4;
	    }

/*        For subsequent lines, treat everything as a new value. */

	} else {
	    __state->nxttok = 1;
	}

/*        We have a value anyway. Store it in the table. */

/*        Keep going until the other shoe (the right parenthesis) */
/*        drops, or until the end of the line is reached. */

/*        Dates begin with @; anything else is presumed to be a number. */

	while(__state->type__[(i__1 = __state->nxttok - 1) < 132 && 0 <= i__1 
		? i__1 : s_rnge("type", i__1, "zzrvbf_", (ftnlen)941)] != 4 &&
		 __state->nxttok <= __state->count) {

/*           Get the begin and end of this token. */

	    __state->b = __state->begs[(i__1 = __state->nxttok - 1) < 132 && 
		    0 <= i__1 ? i__1 : s_rnge("begs", i__1, "zzrvbf_", (
		    ftnlen)945)];
	    __state->e = __state->ends[(i__1 = __state->nxttok - 1) < 132 && 
		    0 <= i__1 ? i__1 : s_rnge("ends", i__1, "zzrvbf_", (
		    ftnlen)946)];
	    if (__state->vartyp == 3) {

/*              We need to determine which category of variable we */
/*              have by looking at this token and deducing the */
/*              type. */

		if (__state->type__[(i__1 = __state->nxttok - 1) < 132 && 0 <=
			 i__1 ? i__1 : s_rnge("type", i__1, "zzrvbf_", (
			ftnlen)954)] == 1) {
		    __state->vartyp = 1;
		} else if (__state->type__[(i__1 = __state->nxttok - 1) < 132 
			&& 0 <= i__1 ? i__1 : s_rnge("type", i__1, "zzrvbf_", 
			(ftnlen)958)] == 2) {
		    __state->vartyp = 2;
		} else {

/*                 This is an error. We should have had one of the */
/*                 two previous types. */

/*                 First perform the clean up function. */

		    zzcln_(&__state->lookat, &__state->nameat, namlst, datlst,
			     nmpool, chpool, dppool);
		    setmsg_("The first item following the assignment operato"
			    "r should be the value of a variable or a left pa"
			    "renthesis '(' followed by a value for a variable"
			    ". This is not true on line # of the text buffer. "
			    , (ftnlen)192);
		    errint_("#", linnum, (ftnlen)1);
		    sigerr_("SPICE(BADVARASSIGN)", (ftnlen)19);
		    chkout_("ZZRVBF", (ftnlen)6);
		    return 0;
		}
	    }
	    if (__state->vartyp == 1) {

/*              First make sure that this token represents a string. */

		if (__state->type__[(i__1 = __state->nxttok - 1) < 132 && 0 <=
			 i__1 ? i__1 : s_rnge("type", i__1, "zzrvbf_", (
			ftnlen)996)] != 1) {

/*                 First perform the clean up function. */

		    zzcln_(&__state->lookat, &__state->nameat, namlst, datlst,
			     nmpool, chpool, dppool);
		    __state->r1 = rtrim_(varnam, varnam_len);
		    setmsg_("The kernel variable # has been set up as a stri"
			    "ng variable.  However, the value that you are at"
			    "tempting to assign to this variable on line # of"
			    " the text buffer is not a string value. ", (
			    ftnlen)183);
		    errch_("#", varnam, (ftnlen)1, __state->r1);
		    errint_("#", linnum, (ftnlen)1);
		    sigerr_("SPICE(TYPEMISMATCH)", (ftnlen)19);
		    chkout_("ZZRVBF", (ftnlen)6);
		    return 0;
		}

/*              Still going? Make sure there is something between */
/*              the quotes. */

		if (__state->b + 1 >= __state->e) {

/*                 First perform the clean up function. */

		    zzcln_(&__state->lookat, &__state->nameat, namlst, datlst,
			     nmpool, chpool, dppool);
		    setmsg_("There is a quoted string with no characters on "
			    "line # of the text buffer. ", (ftnlen)74);
		    errint_("#", linnum, (ftnlen)1);
		    sigerr_("SPICE(TYPEMISMATCH)", (ftnlen)19);
		    chkout_("ZZRVBF", (ftnlen)6);
		    return 0;
		}

/*              We are ready to go.  Allocate a node for this data */
/*              item. First make sure there is room to do so. */

		__state->free = lnknfn_(chpool);
		if (__state->free <= 0) {
		    setmsg_("There is no room available for adding another c"
			    "haracter value to the kernel pool.  The characte"
			    "r values buffer became full at line # of the tex"
			    "t buffer. ", (ftnlen)153);
		    errint_("#", linnum, (ftnlen)1);
		    sigerr_("SPICE(KERNELPOOLFULL)", (ftnlen)21);
		    chkout_("ZZRVBF", (ftnlen)6);
		    return 0;
		}

/*              Allocate a node for storing this string value: */

		lnkan_(chpool, &__state->chnode);
		if (datlst[__state->nameat - 1] == 0) {

/*                 There was no data for this name yet.  We make */
/*                 CHNODE be the head of the data list for this name. */

		    datlst[__state->nameat - 1] = -__state->chnode;
		} else {

/*                 Put this node after the tail of the current list. */

		    __state->head = -datlst[__state->nameat - 1];
		    __state->tail = -chpool[(__state->head << 1) + 11];
		    lnkila_(&__state->tail, &__state->chnode, chpool);
		}

/*              Finally insert this data item in the data buffer */
/*              at CHNODE.  Note any quotes will be doubled so we */
/*              have to undo this affect when we store the data. */

		s_copy(chvals + (__state->chnode - 1) * chvals_len, " ", 
			chvals_len, (ftnlen)1);
		++__state->ncomp;
		__state->i__ = 1;
		__state->j = __state->b + 1;
		while(__state->j < __state->e) {
		    __state->code = *(unsigned char *)&__state->line[
			    __state->j - 1];
		    if (__state->code == __state->iquote) {
			++__state->j;
		    }
		    *(unsigned char *)&chvals[(__state->chnode - 1) * 
			    chvals_len + (__state->i__ - 1)] = *(unsigned 
			    char *)&__state->line[__state->j - 1];
		    ++__state->i__;
		    ++__state->j;
		}

/*              That's all for this value. It's now time to loop */
/*              back through and get the next value. */

	    } else {
		if (__state->type__[(i__1 = __state->nxttok - 1) < 132 && 0 <=
			 i__1 ? i__1 : s_rnge("type", i__1, "zzrvbf_", (
			ftnlen)1117)] != 2) {

/*                 First perform the clean up function. */

		    zzcln_(&__state->lookat, &__state->nameat, namlst, datlst,
			     nmpool, chpool, dppool);
		    __state->r1 = rtrim_(varnam, varnam_len);
		    setmsg_("The kernel variable # has been set up as a nume"
			    "ric or time variable.  However, the value that y"
			    "ou are attempting to assign to this variable on "
			    "line # of the kernel buffer is not a numeric or "
			    "time value. ", (ftnlen)203);
		    errch_("#", varnam, (ftnlen)1, __state->r1);
		    errint_("#", linnum, (ftnlen)1);
		    sigerr_("SPICE(TYPEMISMATCH)", (ftnlen)19);
		    chkout_("ZZRVBF", (ftnlen)6);
		    return 0;
		}

/*              Look at the first character to see if we have a time */
/*              or a number. */

		__state->code = *(unsigned char *)&__state->line[__state->b - 
			1];
		if (__state->code == __state->itmark) {

/*                 We need to have more than a single character. */

		    if (__state->e == __state->b) {

/*                    First perform the clean up function. */

			zzcln_(&__state->lookat, &__state->nameat, namlst, 
				datlst, nmpool, chpool, dppool);
			__state->r1 = rtrim_(varnam, varnam_len);
			setmsg_("At character # of  line # in the text buffe"
				"r the character '@' appears.  This character"
				" is reserved for identifying time values in "
				"assignments to kernel pool variables.  Howev"
				"er it is not being used in this fashion for "
				"the variable '#'. ", (ftnlen)237);
			errint_("#", &__state->b, (ftnlen)1);
			errint_("#", linnum, (ftnlen)1);
			errch_("#", varnam, (ftnlen)1, __state->r1);
			sigerr_("SPICE(BADTIMESPEC)", (ftnlen)18);
			chkout_("ZZRVBF", (ftnlen)6);
			return 0;
		    }
		    i__1 = __state->b;
		    tparse_(__state->line + i__1, &__state->dvalue, 
			    __state->error, __state->e - i__1, (ftnlen)256);
		    if (s_cmp(__state->error, " ", (ftnlen)256, (ftnlen)1) != 
			    0) {

/*                    First perform the clean up function. */

			zzcln_(&__state->lookat, &__state->nameat, namlst, 
				datlst, nmpool, chpool, dppool);
			setmsg_("Encountered '#' while attempting to parse a"
				" time on line # of the text buffer. ", (
				ftnlen)79);
			i__1 = __state->b;
			errch_("#", __state->line + i__1, (ftnlen)1, 
				__state->e - i__1);
			errint_("#", linnum, (ftnlen)1);
			sigerr_("SPICE(BADTIMESPEC)", (ftnlen)18);
			chkout_("ZZRVBF", (ftnlen)6);
			return 0;
		    }
		} else {
		    nparsd_(__state->line + (__state->b - 1), &
			    __state->dvalue, __state->error, &__state->i__, 
			    __state->e - (__state->b - 1), (ftnlen)256);
		    if (s_cmp(__state->error, " ", (ftnlen)256, (ftnlen)1) != 
			    0) {
			zzcln_(&__state->lookat, &__state->nameat, namlst, 
				datlst, nmpool, chpool, dppool);
			setmsg_("Encountered '#' while attempting to parse a"
				" number on line # of the text buffer", (
				ftnlen)79);
			errch_("#", __state->line + (__state->b - 1), (ftnlen)
				1, __state->e - (__state->b - 1));
			errint_("#", linnum, (ftnlen)1);
			sigerr_("SPICE(NUMBEREXPECTED)", (ftnlen)21);
			chkout_("ZZRVBF", (ftnlen)6);
			return 0;
		    }
		}

/*              OK. We have a parsed value.  See if there is room in */
/*              the numeric portion of the pool to store this value. */

		__state->free = lnknfn_(dppool);
		if (__state->free <= 0) {
		    setmsg_("There is no room available for adding another n"
			    "umeric value to the kernel pool.  The numeric va"
			    "lues buffer became full at line # of the text bu"
			    "ffer.", (ftnlen)148);
		    errint_("#", linnum, (ftnlen)1);
		    sigerr_("SPICE(KERNELPOOLFULL)", (ftnlen)21);
		    chkout_("ZZRVBF", (ftnlen)6);
		    return 0;
		}

/*              Allocate a node for storing this numeric value: */

		lnkan_(dppool, &__state->dpnode);
		if (datlst[__state->nameat - 1] == 0) {

/*                 There was no data for this name yet.  We make */
/*                 DPNODE be the head of the data list for this name. */

		    datlst[__state->nameat - 1] = __state->dpnode;
		} else {

/*                 Put this node after the tail of the current list. */

		    __state->head = datlst[__state->nameat - 1];
		    __state->tail = -dppool[(__state->head << 1) + 11];
		    lnkila_(&__state->tail, &__state->dpnode, dppool);
		}

/*              Finally insert this data item into the numeric buffer. */

		dpvals[__state->dpnode - 1] = __state->dvalue;
		++__state->ncomp;
	    }

/*           Now process the next token in the list of tokens. */

	    ++__state->nxttok;
	}

/*        We could have ended the above loop in one of two ways. */

/*        1) NXTTOK now exceeds count.  This means we did not reach */
/*           an end of vector marker. */
/*        2) We hit an end of vector marker. */

	if (__state->nxttok > __state->count) {
	    __state->status = 3;
	} else {
	    __state->status = 2;
	}
    }

/*     It is possible that we reached this point without actually */
/*     assigning a value to the kernel pool variable.  This can */
/*     happen if there is a vector input of the form NAME = ( ) */

    if (__state->ncomp < 1) {
	zzcln_(&__state->lookat, &__state->nameat, namlst, datlst, nmpool, 
		chpool, dppool);
	setmsg_("The first item following the assignment operator should be "
		"the value of a variable or a left parenthesis '(' followed b"
		"y a value for a variable. This is not true on line # of the "
		"text buffer. ", (ftnlen)192);
	i__1 = *linnum - 1;
	errint_("#", &i__1, (ftnlen)1);
	sigerr_("SPICE(BADVARASSIGN)", (ftnlen)19);
	chkout_("ZZRVBF", (ftnlen)6);
	return 0;
    }

/*     Return the name of the variable. */

    s_copy(__state->name__, varnam, (ftnlen)132, varnam_len);
    chkout_("ZZRVBF", (ftnlen)6);
    return 0;
} /* zzrvbf_ */

