/* appndc.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int appndc_state_t;
static inline appndc_state_t* get_appndc_state(cspice_t* state) {
	return 0;
}

/* $Procedure      APPNDC ( Append an item to a character cell ) */
/* Subroutine */ int appndc_(cspice_t* __global_state, char *item, char *cell,
	 ftnlen item_len, ftnlen cell_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern integer cardc_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern integer sizec_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int scardc_(cspice_t*, integer *, char *, ftnlen);
    integer nwcard;
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    appndc_state_t* __state = get_appndc_state(__global_state);
/* $ Abstract */

/*      Append an item to a character cell. */

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

/*     CELLS */

/* $ Keywords */

/*     CELLS */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     ITEM       I   The item to append. */
/*     CELL      I/O  The cell to which ITEM will be appended. */

/* $ Detailed_Input */

/*     ITEM       is a character string which is to be appended to CELL. */

/*     CELL       is a character cell to which ITEM will be appended. */

/* $ Detailed_Output */

/*     CELL       is a character cell in which the last element is ITEM. */

/* $ Parameters */

/*      None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     1) If the cell is not large enough to accommodate the addition */
/*        of a new element, the error SPICE(CELLTOOSMALL) is signalled. */

/*     2) If the length of the item is longer than the length of the */
/*        cell, ITEM is truncated on the right. */

/* $ Particulars */

/*     None. */

/* $ Examples */

/*      In the following example, the item 'PLUTO' is appended to */
/*      the character cell PLANETS. */

/*      Before appending 'PLUTO', the cell contains: */

/*      PLANETS (1) = 'MERCURY' */
/*      PLANETS (2) = 'VENUS' */
/*      PLANETS (3) = 'EARTH' */
/*      PLANTES (4) = 'MARS' */
/*      PLANETS (5) = 'JUPITER' */
/*      PLANETS (6) = 'SATURN' */
/*      PLANETS (7) = 'URANUS' */
/*      PLANETS (8) = 'NEPTUNE' */

/*      The call */

/*        CALL APPNDC ( 'PLUTO', PLANETS ) */

/*      appends the element 'PLUTO' at the location PLANETS (9), and the */
/*      cardinality is updated. */

/*      If the cell is not big enough to accomodate the addition of */
/*      the item, an error is signalled. In this case, the cell is not */
/*      altered. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     H.A. Neilan     (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (HAN) */

/* -& */
/* $ Index_Entries */

/*     append an item to a character cell */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "APPNDC", (ftnlen)6);
    }

/*     Check to see if the cell can accomodate the addition of a */
/*     new item. If there is room, append the item to the cell and */
/*     reset the cardinality. If the cell cannot accomodate the */
/*     addition of a new item, signal an error. */

    nwcard = cardc_(__global_state, cell, cell_len) + 1;
    if (nwcard <= sizec_(__global_state, cell, cell_len)) {
	s_copy(&__global_state->f2c, cell + (nwcard + 5) * cell_len, item, 
		cell_len, item_len);
	scardc_(__global_state, &nwcard, cell, cell_len);
    } else {
	setmsg_(__global_state, "The cell cannot accomodate the addition of "
		"the item *.", (ftnlen)54);
	errch_(__global_state, "*", item, (ftnlen)1, item_len);
	sigerr_(__global_state, "SPICE(CELLTOOSMALL)", (ftnlen)19);
    }
    chkout_(__global_state, "APPNDC", (ftnlen)6);
    return 0;
} /* appndc_ */

