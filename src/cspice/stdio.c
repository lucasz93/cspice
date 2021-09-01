/* stdio.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int stdio_state_t;
static stdio_state_t* get_stdio_state(cspice_t* state) {
	return 0;
}

/* $Procedure      STDIO ( Standard IO ) */
/* Subroutine */ int stdio_(cspice_t* __global_state, char *name__, integer *
	unit, ftnlen name_len)
{
    /* Builtin functions */
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int ucase_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int ljust_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    char myname[8];
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    stdio_state_t* __state = get_stdio_state(__global_state);
/* $ Abstract */

/*    Return the logical unit associated with some standard input or */
/*    standard output. */

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

/*     I/O */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     NAME       I   is the name of a logical unit to return. */
/*     UNIT       O   is the logical unit associated with NAME. */

/* $ Detailed_Input */

/*     NAME       is the "name" of a FORTRAN unit to return. */
/*                Recognized names are 'STDIN' and 'STDOUT'. */
/*                The routine is case insensitive to NAME. */

/*                If NAME is not recognized the error */
/*                'SPICE(BADSTDIONAME)' is signalled and UNIT is */
/*                set to -100. */

/* $ Detailed_Output */

/*     UNIT       is the logical unit associated with NAME.  If */
/*                NAME is not recognized, UNIT is set to -100. */

/* $ Parameters */

/*     None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     1)  If NAME is not recognized, the error 'SPICE(BADSTDIONAME)' is */
/*         signalled. */

/* $ Particulars */

/*     This is a low level utility for retrieving the logical units */
/*     associated with standard input and output.  It exists to */
/*     isolate SPICE based code from compiler writer choices in the */
/*     implementation of standard input and output. */

/* $ Examples */

/*     Suppose you would like to send a message to standard output */
/*     and that this message is contained in the array of N character */
/*     strings MESSGE.  The code below would handle the task. */

/*        CALL STDIO ( 'STDOUT', STDOUT ) */

/*        DO I = 1, N */
/*           CALL WRITLN ( MESSGE(I), STDOUT ) */
/*        END DO */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 18-SEP-1996 (WLT) */


/* -& */
/* $ Index_Entries */

/*     logical units associated standard input and output */

/* -& */

/*     Spicelib Functions */


/*     Local Variables */

    ljust_(__global_state, name__, myname, name_len, (ftnlen)8);
    ucase_(__global_state, myname, myname, (ftnlen)8, (ftnlen)8);
    if (s_cmp(&__global_state->f2c, myname, "STDIN", (ftnlen)8, (ftnlen)5) == 
	    0) {
	*unit = 5;
    } else if (s_cmp(&__global_state->f2c, myname, "STDOUT", (ftnlen)8, (
	    ftnlen)6) == 0) {
	*unit = 6;
    } else if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "STDIO", (ftnlen)5);
	setmsg_(__global_state, "The only \"names\" recognized by STDIO are "
		"'STDIN' and 'STDOUT' you requested a unit for '#'. ", (ftnlen)
		92);
	errch_(__global_state, "#", name__, (ftnlen)1, name_len);
	sigerr_(__global_state, "SPICE(BADSTDIONAME)", (ftnlen)19);
	chkout_(__global_state, "STDIO", (ftnlen)5);
    }
    return 0;
} /* stdio_ */

