/* dasecu.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern dasecu_init_t __dasecu_init;
static inline dasecu_state_t* get_dasecu_state(cspice_t* state) {
	if (!state->dasecu)
		state->dasecu = __cspice_allocate_module(sizeof(
	dasecu_state_t), &__dasecu_init, sizeof(__dasecu_init));
	return state->dasecu;

}

/* $Procedure      DASECU ( DAS extract comments to a logical unit ) */
/* Subroutine */ int dasecu_(cspice_t* __global_state, integer *handle, 
	integer *comlun, logical *comnts)
{
    extern /* Subroutine */ int dasec_(cspice_t*, integer *, integer *, 
	    integer *, char *, logical *, ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern logical failed_(cspice_t*);
    char combuf[255*22];
    extern /* Subroutine */ int dassih_(cspice_t*, integer *, char *, ftnlen);
    integer numcom;
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int writla_(cspice_t*, integer *, char *, integer 
	    *, ftnlen);
    logical gotsom;
    extern logical return_(cspice_t*);
    logical eoc;


    /* Module state */
    dasecu_state_t* __state = get_dasecu_state(__global_state);
/* $ Abstract */

/*     Extract comments from a previously opened binary DAS file to a */
/*     previously opened text file attached to a Fortran logical unit. */

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

/*     None. */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*      HANDLE    I   Handle of a DAS file opened with read access. */
/*      COMLUN    I   Logical unit of an opened text file. */
/*      COMNTS    O   Logical flag, indicating comments were found. */

/* $ Detailed_Input */

/*     HANDLE   The file handle for a binary DAS file that has been */
/*              opened with read access. */

/*     COMLUN   The Fortran logical unit of a previously opened text */
/*              file to which the comments from a binary DAS file are */
/*              to be written. */

/*              The comments will be placed into the text file beginning */
/*              at the current location in the file, and continuing */
/*              until all of the comments have been written. */

/* $ Detailed_Output */

/*     COMNTS   A logical flag indicating whether or not any comments */
/*              were found in the comment area of a DAS file. COMNTS will */
/*              have the value .TRUE. if there were some comments, and */
/*              the value .FALSE. otherwise. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)   If an error occurs while reading from the binary DAS file */
/*          attached to HANDLE, a routine called by this routine will */
/*          signal an error. */

/*     2)   If an error occurs while writing to the text file attached */
/*          to COMLUN, a routine called by this routine will signal an */
/*          error. */

/* $ Files */

/*     See parameters COMLUN and HANDLE in the $ Detailed_Inputs section. */

/* $ Particulars */

/*     This routine will extract all of the comments from the comment */
/*     area of a binary DAS file, placing them into a text file */
/*     attached to COMLUN, beginning at the current position in the */
/*     text file. If there are no comments in the DAS file, nothing is */
/*     written to the text file attached to COMLUN. */

/* $ Examples */

/*      Let */

/*         HANDLE   be the DAS file handle of a previously opened binary */
/*                  DAS file. */

/*         COMLUN   be the Fortran logical unit of a previously opened */
/*                  text file that is to accept the comments from the */
/*                  DAS comment area. */

/*      The subroutine call */

/*         CALL DASECU ( HANDLE, COMLUN, COMNTS ) */

/*      will extract the comments from the comment area of the binary */
/*      DAS file attached to HANDLE, if there are any, and write them */
/*      to the logical unit COMLUN. Upun successfur completion, the */
/*      value of COMNTS will be .TRUE. if there were some comments */
/*      in the comment area and .FALSE. otherwise. */

/* $ Restrictions */

/*     The maximum length of a single line comment in the comment area is */
/*     specified by the parameter LINLEN defined below. Currently this */
/*     value is 255 characters. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     K.R. Gehringer (JPL) */

/* $ Version */

/* -    Beta Version 1.0.0, 5-JAN-1993 (KRG) */

/* -& */
/* $ Index_Entries */

/*      extract comments from a DAS file to a logical unit */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */

/*     Set the value for the maximum length of a text line. */


/*     Set the size of the comment buffer. */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "DASECU", (ftnlen)6);
    }

/*     Verify that the DAS file attached to HANDLE is opened for reading. */

    dassih_(__global_state, handle, "READ", (ftnlen)4);
    if (failed_(__global_state)) {
	chkout_(__global_state, "DASECU", (ftnlen)6);
	return 0;
    }

/*     Initialize some things before the loop. */

    numcom = 0;
    eoc = FALSE_;
    gotsom = FALSE_;
    while(! eoc) {

/*        While we have not reached the end of the comments, get some */
/*        more. */

	dasec_(__global_state, handle, &__state->c__22, &numcom, combuf, &eoc,
		 (ftnlen)255);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "DASECU", (ftnlen)6);
	    return 0;
	}
	if (numcom > 0) {

/*           If NUMCOM .GT. 0 then we did get some comments, and we need */
/*           to write them out, but first, set the flag indicating that */
/*           we got some comments. */

	    if (! gotsom) {
		gotsom = TRUE_;
	    }
	    writla_(__global_state, &numcom, combuf, comlun, (ftnlen)255);
	    if (failed_(__global_state)) {
		chkout_(__global_state, "DASECU", (ftnlen)6);
		return 0;
	    }
	}
    }

/*     Set the output flag indicating whether or not we got any comments. */

    *comnts = gotsom;
    chkout_(__global_state, "DASECU", (ftnlen)6);
    return 0;
} /* dasecu_ */

