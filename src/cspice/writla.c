/* writla.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int writla_state_t;
static writla_state_t* get_writla_state() {
	cspice_t* state =  __cspice_get_state();
	return 0;
}

/* $Procedure      WRITLA ( Write array of lines to a logical unit ) */
/* Subroutine */ int writla_(integer *numlin, char *array, integer *unit, 
	ftnlen array_len)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    integer i__;
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    extern logical failed_(void);
    extern /* Subroutine */ int sigerr_(char *, ftnlen);
    extern /* Subroutine */ int chkout_(char *, ftnlen);
    extern /* Subroutine */ int setmsg_(char *, ftnlen);
    extern /* Subroutine */ int errint_(char *, integer *, ftnlen);
    extern logical return_(void);
    extern /* Subroutine */ int writln_(char *, integer *, ftnlen);


    /* Module state */
    writla_state_t* __state = get_writla_state();
/* $ Abstract */

/*     This routine will write an array of text lines to a Fortran */
/*     logical unit. */

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

/*     UTILITY */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*      NUMLIN    I    Number of lines to be written to the file. */
/*      ARRAY     I    Array containing the lines to be written. */
/*      UNIT      I    Fortran unit number to use for output. */

/* $ Detailed_Input */


/*     NUMLIN   The number of text lines in ARRAY which are to be */
/*              written to UNIT. NUMLIN > 0. */

/*     ARRAY    The array which contains the text lines to be written to */
/*              UNIT. */

/*              The contents of this variable are not modified. */

/*     UNIT     The Fortran unit number for the output. This may */
/*              be either the unit number for the terminal, or the */
/*              unit number of a previously opened text file. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)   If the number of lines, NUMLIN, is not positive, the error */
/*          SPICE(INVALIDARGUMENT) will be signalled. */

/*     2)   If an error occurs while attempting to write to the text */
/*          file attached to UNIT, a routine called by this routine will */
/*          detect and signal the error. */

/* $ Files */

/*     See the description of UNIT above. */

/* $ Particulars */

/*     This routine writes an array of character strings to a specified */
/*     Fortran logical unit, writing each array element as a line of */
/*     output. */

/* $ Examples */

/*     The following example demonstrates the use of this routine, */
/*     displaying a short poem on the standard output device, typically a */
/*     terminal screen. */

/*           PROGRAM EXAMPL */
/*     C */
/*     C     Example program for WRITLA. */
/*     C */
/*           CHARACTER*(80) LINES(4) */

/*           LINES(1) = 'Mary had a little lamb' */
/*           LINES(2) = 'Whose fleece was white as snow' */
/*           LINES(3) = 'And everywhere that mary went' */
/*           LINES(4) = 'The lamb was sure to go' */

/*           CALL WRITLA ( 4, LINES, 6 ) */

/*           END */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     K.R. Gehringer (JPL) */

/* $ Version */

/* -    SPICELIB     1.0.0, 20-DEC-1995 (KRG) */

/*        The routine graduated */

/* -    Beta Version 2.0.0, 13-OCT-1994 (KRG) */

/*        This routine now participates fully with the SPICELIB error */
/*        handler, checking in on entry and checking out on exit. The */
/*        overhead associated with the error handler should not be */
/*        significant relative to the operation of this routine. */

/* -    Beta Version 1.0.0, 18-DEC-1992 (KRG) */

/* -& */
/* $ Index_Entries */

/*      write an array of text lines to a logical unit */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    } else {
	chkin_("WRITLA", (ftnlen)6);
    }

/*     Check to see if the maximum number of lines is positive. */

    if (*numlin <= 0) {
	setmsg_("The number of lines to be written was not positive. It was "
		"#.", (ftnlen)61);
	errint_("#", numlin, (ftnlen)1);
	sigerr_("SPICE(INVALIDARGUMENT)", (ftnlen)22);
	chkout_("WRITLA", (ftnlen)6);
	return 0;
    }

/*     Begin writing the lines to UNIT. Stop when an error occurs, or */
/*     when we have finished writing all of the lines. */

    i__1 = *numlin;
    for (i__ = 1; i__ <= i__1; ++i__) {
	writln_(array + (i__ - 1) * array_len, unit, array_len);
	if (failed_()) {

/*           If the write failed, an appropriate error message has */
/*           already been set, so we simply need to return. */

	    chkout_("WRITLA", (ftnlen)6);
	    return 0;
	}
    }
    chkout_("WRITLA", (ftnlen)6);
    return 0;
} /* writla_ */

