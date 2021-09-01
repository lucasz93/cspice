/* rdencc.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern rdencc_init_t __rdencc_init;
static rdencc_state_t* get_rdencc_state(cspice_t* state) {
	if (!state->rdencc)
		state->rdencc = __cspice_allocate_module(sizeof(
	rdencc_state_t), &__rdencc_init, sizeof(__rdencc_init));
	return state->rdencc;

}

/* $Procedure  RDENCC  ( Read encoded characters from a text file ) */
/* Subroutine */ int rdencc_(cspice_t* __global_state, integer *unit, integer 
	*n, char *data, ftnlen data_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer i_len(f2c_state_t*, char *, ftnlen), s_rsle(f2c_state_t*, cilist *
	    ), do_lio(f2c_state_t*, integer *, integer *, char *, ftnlen), 
	    e_rsle(f2c_state_t*);

    /* Local variables */
    integer nescd;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    integer intch;
    logical error;
    char ch[1];
    extern /* Subroutine */ int hx2int_(cspice_t*, char *, integer *, logical 
	    *, char *, ftnlen, ftnlen);
    logical escape;
    char encchr[64];
    integer dtalen;
    integer dtalin;
    integer nchars;
    integer encpos;
    integer dtapos;
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    char errmsg[80];
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    integer iostat;
    char hexnum[2];
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);

    /* Fortran I/O blocks */



    /* Module state */
    rdencc_state_t* __state = get_rdencc_state(__global_state);
/* $ Abstract */

/*     Read and decode encoded characters from a text file. */

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

/*     CHARACTERS */
/*     CONVERSION */
/*     UTILITY */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*      UNIT      I    Fortran unit number of input text file. */
/*      N         I    Number of characters to be read and decoded. */
/*      DATA      O    List of decoded characters to be returned. */

/* $ Detailed_Input */

/*     UNIT     The Fortran unit number for a previously opened text */
/*              file. All reading will begin at the CURRENT POSITION */
/*              in the text file. */

/*     N        The number of characters to be read from the text file */
/*              attached to UNIT. */

/* $ Detailed_Output */

/*     DATA     List of characters which were read from the text file */
/*              attached to UNIT and decoded. */

/* $ Parameters */

/*      None. */

/* $ Exceptions */

/*     1)   If N, the number of data items, is not positive, the error */
/*          SPICE(INVALIDARGUMENT) will be signalled. */

/*     2)   If an error occurs while reading from the text file */
/*          attached to UNIT, the error SPICE(FILEREADFAILED) will */
/*          be signalled. */

/*     3)   If an error occurs while decoding a character, the error */
/*          SPICE(DECODINGERROR) will be signalled. */

/* $ Files */

/*     See the description of UNIT in Detailed_Input. */

/* $ Particulars */

/*     This routine will read quoted character strings of length */
/*     MAXENC containing encoded characters produced by the routine */
/*     WRENCC, or some equivalent procedure. The reading begins at */
/*     the current position in a previously opened text file attached */
/*     to logical UNIT and continues until N contiguous characters */
/*     have been successfully decoded and placed in the data buffer */
/*     DATA or an error occurs. The current position in a file is */
/*     defined to be the text line immediately following the last text */
/*     line that was written or read. */

/*     The character strings are quoted so that a Fortran list directed */
/*     read may be used to read them, rather than a formatted read with */
/*     the format specifier FMT = '(A)'. */

/*     As the characters are decoded they are placed into the first N */
/*     contiguous positions in the data buffer DATA, where the first N */
/*     contiguous positions are determined by moving from the lowest */
/*     array indices to highest array indices, i.e., moving from ``left'' */
/*     to ``right'' and ``top'' to ``bottom'' in the character array */
/*     DATA, beginning at the first character position, DATA(1)(1:1). So, */
/*     logically all of the quoted strings containing encoded data can */
/*     be thought of as being concatenated together into one long */
/*     character string. */

/*     This routine is one of a pair of routines which are used to */
/*     encode and decode ASCII characters: */

/*           WRENCC -- Encode and write ASCII characters to a file. */
/*           RDENCC -- Read and decode ASCII characters from a file. */

/*     The encoding/decoding of characters is performed to provide */
/*     a portable means for transferring character data values. */

/*     This routine is for use with the ASCII character set and */
/*     extensions to it. The supported characters must have decimal */
/*     values in the range from 0 to 255. */

/* $ Examples */

/*     The following examples demonstrate the use of this routine. In */
/*     each of the examples, the variable UNIT is the Fortran logical */
/*     unit of a previously opened text file, and the variable N is */
/*     an integer which will represent the number of characters to be */
/*     read and decoded. */

/*     The first example demonstrates a typical correct usage of this */
/*     routine. The second example demonstrates what would probably be */
/*     the most common incorrect usage of this routine. These examples */
/*     are meant to be illustrative, so for the sake of brevity and */
/*     clarity, the length of the quoted strings expected in the input */
/*     text file has been shortened. */

/*     The examples use as data correctly and incorrectly encoded */
/*     versions of the following character string which has a length */
/*     of exactly 64 characters: */

/*        'Here is some data. What follows is more '// */
/*        'data. This is more data.                ' */

/*     Example 1 */
/*     --------- */

/*        This example demonstrates a typical usage of this routine. */

/*        Let the symbol '-->' denote the file pointer. */

/*        Let the current file pointer position and succeeding data be */
/*        the following: */

/*           --> 'Here is some data. W' */
/*               'hat follows is more ' */
/*               'data. This is more d' */
/*               'ata.                ' */

/*        There are exactly N = 64 characters of encoded data. */

/*        Let the character data buffer have the following */
/*        declaration in the calling program: */

/*           CHARACTER*(40)         DATA(2) */

/*        Then, the subroutine call */

/*           CALL RDENCC( UNIT, N, DATA ) */

/*        with N = 64 would produce the following results: */

/*           DATA(1) = 'Here is some data. What follows is more ' */
/*           DATA(2) = 'data. This is more data.' */

/*     Example 2 */
/*     --------- */

/*        This example is meant to demonstrate what would probably be */
/*        a common misuse of this routine. */

/*        Let the symbol '-->' denote the file pointer. */

/*        Let the current file pointer position and succeeding data be */
/*        the following: */

/*           --> 'Here is some data.  ' */
/*               'What follows is more' */
/*               'data. This is more  ' */
/*               'data.               ' */

/*        As in example 1, there are exactly N = 64 characters of */
/*        encoded data, but to make the data more ``readable'' two extra */
/*        spaces have been added: one at the end of the first line and */
/*        one at the end of the third line. */

/*        Let the character data buffer have the following */
/*        declaration in the calling program: */

/*           CHARACTER*(40)         DATA(2) */

/*        Then, the subroutine call */

/*           CALL RDENCC( UNIT, N, DATA ) */

/*        with N = 64 would produce the following results: */

/*           DATA(1) = 'Here is some data.  What follows is more' */
/*           DATA(2) = ' data. This is  more dat' */

/*        This is probably not what was desired. The problem is that */
/*        the ``significant'' characters in the encoded string do not */
/*        appear contiguously; an ``extra'' blank appears at the end */
/*        of the first and third encoded quoted strings. */

/*     Example 3 */
/*     --------- */

/*        This example demonstrates the use of WRENCC and RDENCC for */
/*        writing and subsequent reading of character data using data */
/*        buffers that are ``shaped'' differently, i.e., that have */
/*        different dimensions. */

/*        Let the input and output character data buffers have the */
/*        following declarations: */

/*           CHARACTER*(25)  OUTBUF(3) */
/*           CHARACTER*(10)  INPBUF(7) */

/*        Further, let the output buffer contain the following data: */

/*           OUTBUF(1) = 'Today is the first day of' */
/*           OUTBUF(2) = ' the rest of my life, so ' */
/*           OUTBUF(3) = 'I will enjoy it.' */

/*        There are exactly N = 66 significant characters in the output */
/*        buffer. The code fragment */

/*           N = 66 */
/*           CALL WRENCC ( UNIT, N, OUTBUF ) */
/*           REWIND ( UNIT ) */
/*           CALL RDENCC ( UNIT, N, INPBUF ) */

/*        has the effect of placing the original data into the */
/*        differently ``shaped'' input buffer with the following */
/*        results: */

/*           INPBUF(1) = 'Today is t' */
/*           INPBUF(2) = 'he first d' */
/*           INPBUF(3) = 'ay of the ' */
/*           INPBUF(4) = 'rest of my' */
/*           INPBUF(5) = ' life, so ' */
/*           INPBUF(6) = 'I will enj' */
/*           INPBUF(7) = 'oy it.    ' */

/*       No information has been lost, it is simply arranged differently. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     K.R. Gehringer (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 20-OCT-1992 (KRG) */

/* -& */
/* $ Index_Entries */

/*      read encoded characters from a text file */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "RDENCC", (ftnlen)6);
    }

/*     Check to see if the number of data items is less than or equal */
/*     to zero. If it is, signal an error. */

    if (*n < 1) {
	setmsg_(__global_state, "The number of data items to be read was not"
		" positive: #.", (ftnlen)56);
	errint_(__global_state, "#", n, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDARGUMENT)", (ftnlen)22);
	chkout_(__global_state, "RDENCC", (ftnlen)6);
	return 0;
    }

/*     Initialize some stuff here */

/*     Make sure that the encoding character string is empty when we */
/*     start. */

    s_copy(&__global_state->f2c, encchr, " ", (ftnlen)64, (ftnlen)1);

/*     We have not encountered any errors yet, so set the error indicator */
/*     to .FALSE.. */

    error = FALSE_;

/*     Get the length of a data ``line'' in the data buffer DATA. */

    dtalen = i_len(&__global_state->f2c, data, data_len);

/*     We are not currently parsing an escaped character, so set the */
/*     escape indicator to .FALSE. and set the number of escape digits */
/*     to zero. */

    escape = FALSE_;
    nescd = 0;

/*     Set the initial line and position for the output data buffer. */

    dtapos = 1;
    dtalin = 1;

/*     Set the initial position in the encoding buffer to be 1 too */
/*     big so that we read an encoded character string from the file */
/*     attached to UNIT on the first pass through the loop. */

    encpos = 65;

/*     Set the number of characters decoded to zero and begin the */
/*     decoding loop. */

    nchars = 0;
    while(nchars < *n) {

/*        If the last character we processed was the last one in the */
/*        encoded character string, then we need to read in the next */
/*        encoded character string from the file. This also accomplishes */
/*        the task of reading in the first encoded character string. */

	if (encpos > 64) {
	    __state->io___11.ciunit = *unit;
	    iostat = s_rsle(&__global_state->f2c, &__state->io___11);
	    if (iostat != 0) {
		goto L100001;
	    }
	    iostat = do_lio(&__global_state->f2c, &__state->c__9, &
		    __state->c__1, encchr, (ftnlen)64);
	    if (iostat != 0) {
		goto L100001;
	    }
	    iostat = e_rsle(&__global_state->f2c);
L100001:
	    if (iostat != 0) {
		setmsg_(__global_state, "Error reading from logical unit #, "
			"IOSTAT = #.", (ftnlen)46);
		errint_(__global_state, "#", unit, (ftnlen)1);
		errint_(__global_state, "#", &iostat, (ftnlen)1);
		sigerr_(__global_state, "SPICE(FILEREADFAILED)", (ftnlen)21);
		chkout_(__global_state, "RDENCC", (ftnlen)6);
		return 0;
	    }

/*           Set the pointer for the encoded character buffer to the */
/*           beginning of the buffer. */

	    encpos = 1;
	}
	*(unsigned char *)ch = *(unsigned char *)&encchr[encpos - 1];

/*        If we are processing a character which was escaped when it was */
/*        encoded, we need to do some special stuff. */

	if (escape) {
	    ++nescd;
	    if (nescd == 2) {

/*              If we have all of the digits in the encoded character, */
/*              then decode it. */

		*(unsigned char *)&hexnum[nescd - 1] = *(unsigned char *)ch;
		hx2int_(__global_state, hexnum, &intch, &error, errmsg, (
			ftnlen)2, (ftnlen)80);
		if (error) {
		    setmsg_(__global_state, "Decoding error occurred while a"
			    "ttempting to decode item #: @#. #", (ftnlen)64);
		    i__1 = nchars + 1;
		    errint_(__global_state, "#", &i__1, (ftnlen)1);
		    errch_(__global_state, "#", hexnum, (ftnlen)1, (ftnlen)2);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)80)
			    ;
		    sigerr_(__global_state, "SPICE(DECODINGERROR)", (ftnlen)
			    20);
		    chkout_(__global_state, "RDENCC", (ftnlen)6);
		    return 0;
		}
		*(unsigned char *)ch = (char) intch;

/*              We now have the decoded character. We are no longer */
/*              processing an escaped character, so set the escape */
/*              indicator to .FALSE. and continue. The character we */
/*              just decoded will be placed into the data buffer DATA */
/*              below. */

		escape = FALSE_;
		nescd = 0;
	    } else if (nescd < 2 && nescd > 0) {

/*              Otherwise we are still collecting the digits of the */
/*              encoded character, so store the current character and */
/*              move on to the next one. */

		*(unsigned char *)&hexnum[nescd - 1] = *(unsigned char *)ch;
	    }
	} else {

/*           Check to see if the current character is the escape */
/*           character. If it is, we need to set the escape indicator */
/*           to .TRUE. so that we correctly process the encoded */
/*           digits. */

	    if (*(unsigned char *)ch == '@') {
		escape = TRUE_;
	    }
	}

/*        At this point one of the following is true: */

/*           (1) CH contains a character to be placed into the data */
/*               buffer DATA. */

/*           (2) We are currently building an escaped character from */
/*               its escape sequence, ESCAPE = .TRUE., and CH contains */
/*               some part of the escape sequence. */

/*        If we are not currently decoding an escaped character, then */
/*        we need to store the character value that we have in the data */
/*        buffer, and move on to the next character. */

	if (! escape) {
	    ++nchars;

/*           If the position in the data buffer is greater than the */
/*           length  of a data line (DTALEN) then we need to increment */
/*           the current data line (DTALIN) and reset the current data */
/*           line buffer position (DTAPOS). */

	    if (dtapos > dtalen) {
		++dtalin;
		dtapos = 1;
	    }

/*           Store the current character in the data buffer and */
/*           increment the buffer position. */

	    *(unsigned char *)&data[(dtalin - 1) * data_len + (dtapos - 1)] = 
		    *(unsigned char *)ch;
	    ++dtapos;
	}

/*        Increment the encoded character buffer position */

	++encpos;

/*        At this point, we know the following: */

/*        (1)  1 <= ENCPOS <= MAXENC */
/*        (2)  1 <= NCHARS <= N */
/*        (3)  1 <= DTAPOS <= DTALEN */
/*        (4)  1 <= DTALIN */
/*        (5)  0 <= NESCD <= MXESCD */
/*        (6)  ESCAPE is .TRUE. if we are currently decoding an escaped */
/*             character, otherwise it is .FALSE.. */

    }
    chkout_(__global_state, "RDENCC", (ftnlen)6);
    return 0;
} /* rdencc_ */

