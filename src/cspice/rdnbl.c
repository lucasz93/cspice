/* rdnbl.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int rdnbl_state_t;
static rdnbl_state_t* get_rdnbl_state(cspice_t* state) {
	return 0;
}

/* $Procedure RDNBL ( Read non-blank line ) */
/* Subroutine */ int rdnbl_(cspice_t* __global_state, char *file, char *line, 
	logical *eof, ftnlen file_len, ftnlen line_len)
{
    /* Builtin functions */
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern logical failed_(cspice_t*);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int rdtext_(cspice_t*, char *, char *, logical *, 
	    ftnlen, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    rdnbl_state_t* __state = get_rdnbl_state(__global_state);
/* $ Abstract */

/*     Read the next non-blank line of text from a text file. */

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

/*     FILES,  TEXT */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*      FILE       I   Input text file. */
/*      LINE       O   Next non-blank line from the input text file. */
/*      EOF        O   End-of-file indicator. */

/* $ Detailed_Input */

/*      FILE        is the name of the text file from which the next */
/*                  line is to be read. If the file is not currently */
/*                  open, it is opened with a logical unit determined */
/*                  at run time, and the first line of the file is */
/*                  returned. Otherwise, the next line not yet read */
/*                  from the file is read and returned. */

/* $ Detailed_Output */

/*      LINE        is next non-blank line of text in the specified file. */

/*      EOF         is true when the end of the file is reached, and is */
/*                  otherwise false. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If either the end of the file is reached or an error occurs */
/*        before a non-blank line is found, LINE is blank. */

/* $ Files */

/*     See input FILES. */

/* $ Particulars */

/*      RDNBL simply calls RDTEXT until one of two things happens: */

/*         1. A non-blank line is found (in which case the line */
/*            is returned). */

/*         2. The end of the file is reached (in which case the */
/*            file is closed, a blank line is returned, and the */
/*            end-of-file indicator becomes TRUE.) */

/* $ Examples */

/*      Let FILE.1 contain the following lines. */

/*         Mary had a little lamb */

/*         Everywhere that Mary went */



/*         Its fleece was white as snow. */
/*         The lamb was sure to go. */

/*      Then the code fragment */

/*         DO I = 1, 4 */
/*            CALL RDNBL ( 'FILE.1', LINE, EOF ) */
/*            WRITE (*,*) LINE */
/*         END DO */

/*      produces the following output: */

/*         Mary had a little lamb */
/*         Everywhere that Mary went */
/*         Its fleece was white as snow. */
/*         The lamb was sure to go. */

/*      In fact, the following code fragment removes all of the blank */
/*      lines from an arbitrary text file (FILE). */

/*         CALL RDNBL ( FILE, LINE, EOF ) */

/*         DO WHILE ( .NOT. EOF ) */
/*            WRITE (*,*) LINE( : RTRIM(LINE) ) */

/*            CALL RDNBL ( FILE, LINE, EOF ) */
/*         END DO */

/*      Note that because RDNBL calls RDTEXT, calls to either routine */
/*      can be interspersed. For example, RDNBL can be used to skip */
/*      blank lines at the beginning of the file, leaving the rest to */
/*      be processed: */

/*         CALL RDNBL ( FILE, LINE, EOF ) */

/*         DO WHILE ( .NOT. EOF ) */
/*            < do something with LINE > */

/*            CALL RDTEXT ( FILE, LINE, EOF ) */
/*         END DO */

/* $ Restrictions */

/*      Any restrictions that apply to RDTEXT apply to RDNBL as well. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     I.M. Underwood (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 07-AUG-1994 (IMU) */

/* -& */
/* $ Index_Entries */

/*     read a non-blank line from a text file */

/* -& */

/*     SPICELIB functions */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "RDNBL", (ftnlen)5);
    }

/*     Return as soon as a non-blank line is found. Otherwise, keep */
/*     looking until either the end of the file is reached or RDTEXT */
/*     manages to fail. */

    rdtext_(__global_state, file, line, eof, file_len, line_len);
    while(! (*eof) && ! failed_(__global_state)) {
	if (s_cmp(&__global_state->f2c, line, " ", line_len, (ftnlen)1) != 0) 
		{
	    chkout_(__global_state, "RDNBL", (ftnlen)5);
	    return 0;
	} else {
	    rdtext_(__global_state, file, line, eof, file_len, line_len);
	}
    }

/*     Didn't find anything? */

    s_copy(&__global_state->f2c, line, " ", line_len, (ftnlen)1);
    chkout_(__global_state, "RDNBL", (ftnlen)5);
    return 0;
} /* rdnbl_ */

