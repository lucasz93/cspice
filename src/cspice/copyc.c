/* copyc.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int copyc_state_t;
static copyc_state_t* get_copyc_state(cspice_t* state) {
	return 0;
}

/* $Procedure      COPYC ( Copy a character cell ) */
/* Subroutine */ int copyc_(cspice_t* __global_state, char *cell, char *copy, 
	ftnlen cell_len, ftnlen copy_len)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen), i_len(
	    f2c_state_t*, char *, ftnlen);

    /* Local variables */
    integer card;
    integer size;
    integer i__;
    extern integer cardc_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer moved;
    extern integer sizec_(cspice_t*, char *, ftnlen);
    logical trunc;
    extern /* Subroutine */ int scardc_(cspice_t*, integer *, char *, ftnlen);
    extern integer lastpc_(cspice_t*, char *, ftnlen);
    integer reqlen;
    extern /* Subroutine */ int excess_(cspice_t*, integer *, char *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    copyc_state_t* __state = get_copyc_state(__global_state);
/* $ Abstract */

/*      Copy the contents of a character cell to another cell. */

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

/*      CELLS */

/* $ Keywords */

/*      CELLS */

/* $ Declarations */
/* $ Brief_I/O */

/*      VARIABLE  I/O  DESCRIPTION */
/*      --------  ---  -------------------------------------------------- */
/*      CELL       I   Cell to be copied. */
/*      COPY       O   New cell. */

/* $ Detailed_Input */


/*      CELL        is a cell. */


/* $ Detailed_Output */

/*      COPY        is a cell which contains the same elements as the */
/*                  input cell, in the same order. If the size (maximum */
/*                  cardinality) of the output cell is smaller than */
/*                  the cardinality of the input cell, then only as many */
/*                  items as will fit in the output cell are copied, */
/*                  and an error is signalled. */

/* $ Parameters */

/*      None. */

/* $ Particulars */

/*     The copy routines (COPYC, COPYD, and COPYI) are used primarily */
/*     to manipulate working cells, since many routines that use cells */
/*     (binary set routines, for instance) do not allow cells to be */
/*     combined or manipulated in place. */

/* $ Examples */

/*     In the following example, COPYC is used to copy the result */
/*     of the union of two sets (ordered cells) from a temporary */
/*     working set back into the one of the original set. */

/*           CALL UNIONC ( BODIES, PLANETS, TEMP ) */
/*           CALL COPYC  ( TEMP,   BODIES       ) */

/*     If the size of the temporary cell is greater than the size */
/*     of the original set, the function FAILED should be checked to be */
/*     sure that no overflow occurred. If BODIES is at least as */
/*     large as TEMP, no such check is necessary. */

/* $ Restrictions */

/*     None. */

/* $ Exceptions */

/*      1) If the output cell in not large enough to hold the elements */
/*         of the input cell, the error SPICE(CELLTOOSMALL) is signalled. */

/*      2) If length of the elements of the output cell is less than the */
/*         length of the elements of the input cell, the error */
/*         SPICE(ELEMENTSTOOSHORT) is signalled. */

/* $ Files */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     C.A. Curzon     (JPL) */
/*     W.L. Taber      (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (CAC) (WLT) (IMU) */

/* -& */
/* $ Index_Entries */

/*     copy a character cell */

/* -& */
/* $ Revisions */

/* -    Beta Version 2.0.0, 09-JAN-1989 (NJB) */

/*        Error signalled if output set elements are not long enough. */
/*        Length must be at least max of lengths of input elements. */
/*        Also, calling protocol for EXCESS has been changed.  And, */
/*        elements LBCELL through -2 of control area are now copied to */
/*        the output cell. */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Set up the error processing. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "COPYC", (ftnlen)5);

/*     We need the cardinality of the input cell, and the size of */
/*     the output cell. */

    card = cardc_(__global_state, cell, cell_len);
    size = sizec_(__global_state, copy, copy_len);

/*     Start moving the elements, one by one. Stop if the output */
/*     cell fills up.  Copy the control area too, except for the */
/*     the size and cardinality values.  Truncation indicator */
/*     starts at .FALSE. */

    trunc = FALSE_;
    reqlen = 0;
    moved = min(card,size);
    i__1 = moved;
    for (i__ = 1; i__ <= i__1; ++i__) {
	s_copy(&__global_state->f2c, copy + (i__ + 5) * copy_len, cell + (i__ 
		+ 5) * cell_len, copy_len, cell_len);

/*        Test for truncation: */

	if (s_cmp(&__global_state->f2c, copy + (i__ + 5) * copy_len, cell + (
		i__ + 5) * cell_len, copy_len, cell_len) != 0) {
	    trunc = TRUE_;
/* Computing MAX */
	    i__2 = reqlen, i__3 = lastpc_(__global_state, cell + (i__ + 5) * 
		    cell_len, cell_len);
	    reqlen = max(i__2,i__3);
	}
    }
    for (i__ = -5; i__ <= -2; ++i__) {
	s_copy(&__global_state->f2c, copy + (i__ + 5) * copy_len, cell + (i__ 
		+ 5) * cell_len, copy_len, cell_len);

/*        Test for truncation: */

	if (s_cmp(&__global_state->f2c, copy + (i__ + 5) * copy_len, cell + (
		i__ + 5) * cell_len, copy_len, cell_len) != 0) {
	    trunc = TRUE_;
/* Computing MAX */
	    i__1 = reqlen, i__2 = lastpc_(__global_state, cell + (i__ + 5) * 
		    cell_len, cell_len);
	    reqlen = max(i__1,i__2);
	}
    }

/*     Set the cardinality of the output cell. */

    scardc_(__global_state, &moved, copy, copy_len);

/*     We've got an error if the output cell was too small. */

    if (size < card) {
	i__1 = card - size;
	excess_(__global_state, &i__1, "cell", (ftnlen)4);
	sigerr_(__global_state, "SPICE(CELLTOOSMALL)", (ftnlen)19);
	chkout_(__global_state, "COPYC", (ftnlen)5);
	return 0;
    }

/*     We also have an error if the output set elements are not long */
/*     enough. */

    if (trunc) {
	setmsg_(__global_state, "Length of output cell is #.  Length require"
		"d to contain result is #.", (ftnlen)68);
	i__1 = i_len(&__global_state->f2c, copy, copy_len);
	errint_(__global_state, "#", &i__1, (ftnlen)1);
	errint_(__global_state, "#", &reqlen, (ftnlen)1);
	sigerr_(__global_state, "SPICE(ELEMENTSTOOSHORT)", (ftnlen)23);
	chkout_(__global_state, "COPYC", (ftnlen)5);
	return 0;
    }
    chkout_(__global_state, "COPYC", (ftnlen)5);
    return 0;
} /* copyc_ */

