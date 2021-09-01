/* wdcnt.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int wdcnt_state_t;
static wdcnt_state_t* get_wdcnt_state(cspice_t* state) {
	return 0;
}

/* $Procedure WDCNT ( Word Count ) */
integer wdcnt_(cspice_t* __global_state, char *string, ftnlen string_len)
{
    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen), i_len(
	    f2c_state_t*, char *, ftnlen);

    /* Local variables */
    logical cont;
    integer n;
    integer length;
    integer loc;


    /* Module state */
    wdcnt_state_t* __state = get_wdcnt_state(__global_state);
/* $ Abstract */

/*      Return the number of words in a string. */

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

/*      STRING,  WORD */

/* $ Declarations */
/* $ Brief_I/O */

/*      VARIABLE  I/O  DESCRIPTION */
/*      --------  ---  -------------------------------------------------- */
/*      STRING     I   Input character string. */
/*      WDCNT      O   The number of words in string. */

/* $ Detailed_Input */

/*      STRING      is the input string to be parsed. It contains */
/*                  some number of words, where a word is any string */
/*                  of consecutive non-blank characters delimited */
/*                  by a blank or by either end of the string. */

/* $ Detailed_Output */

/*      WDCNT       is the number of words in the input character */
/*                  string. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*      Error free. */

/* $ Files */

/*      None. */

/* $ Particulars */

/*      WDCNT, like NTHWD and NEXTWD, is useful primarily for parsing */
/*      input commands consisting of one or more words, where a word is */
/*      defined to be any sequence of consecutive non-blank characters */
/*      delimited by either a blank or by either end of the string. */

/* $ Examples */

/*      The following examples illustrate the use of WDCNT. */

/*            WDCNT ( 'Now is the time'  )   = 4 */
/*            WDCNT ( '  for all  '      )   = 2 */
/*            WDCNT ( 'good,men.to_come' )   = 1 */
/*            WDCNT ( ' '                )   = 0 */

/* $ Restrictions */

/*      None. */

/* $ Literature_References */

/*      None. */

/* $ Author_and_Institution */

/*      I.M. Underwood  (JPL) */

/* $ Version */

/* -     SPICELIB Version 1.1.0, 10-JAN-2005 (EDW) */

/*         Added logic to prevent the evaluation of STRING(LOC:LOC) */
/*         if LOC exceeds the length of string. Functionally, the */
/*         evaluation had no effect on WDCNT's output, but the NAG */
/*         F95 compiler flagged the evaluation as an array */
/*         overrun error. This occurred because given: */

/*             A .AND. B */

/*         NAG evaluates A then B then performs the logical */
/*         comparison. */

/* -     SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*         Comment section for permuted index source lines was added */
/*         following the header. */

/* -     SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     word count */

/* -& */

/*     Local variables */


/*     This is just NTHWD, except that it keeps looking until */
/*     it finds the last word. */


/*     Trivial case first. */

    if (s_cmp(&__global_state->f2c, string, " ", string_len, (ftnlen)1) == 0) 
	    {
	ret_val = 0;
	return ret_val;
    } else {
	length = i_len(&__global_state->f2c, string, string_len);
    }

/*     Skip leading blanks. */

    loc = 1;
    while(*(unsigned char *)&string[loc - 1] == ' ') {
	++loc;
    }

/*     Keep stepping through STRING, counting words as we go. */
/*     (The current word is ended whenever a blank is encountered.) */
/*     Quit when the end of the string is reached. */

/*     N is the number of words found so far. */
/*     LOC is the current location in STRING. */

    n = 1;
    while(loc < length) {
	++loc;

/*        Blank signals end of the current word. */

	if (*(unsigned char *)&string[loc - 1] == ' ') {

/*           Skip ahead to the next word. Ensure no */
/*           evaluation of STRING(LOC:LOC) when */
/*           LOC = LENGTH+1. */

	    cont = loc <= length;
	    if (cont) {
		cont = cont && *(unsigned char *)&string[loc - 1] == ' ';
	    }
	    while(cont) {
		++loc;
		cont = loc <= length;
		if (cont) {
		    cont = cont && *(unsigned char *)&string[loc - 1] == ' ';
		}
	    }

/*           If not at the end of the string, we have another word. */

	    if (loc <= length) {
		++n;
	    }
	}
    }

/*     Return the number of words found. */

    ret_val = n;
    return ret_val;
} /* wdcnt_ */

