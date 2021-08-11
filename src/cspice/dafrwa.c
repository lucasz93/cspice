/* dafrwa.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int dafrwa_state_t;
static dafrwa_state_t* get_dafrwa_state() {
	cspice_t* state =  __cspice_get_state();
	return 0;
}

/* $Procedure DAFRWA ( DAF, record/word to address ) */
/* Subroutine */ int dafrwa_0_(int n__, integer *recno, integer *wordno, 
	integer *addr__)
{
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    extern /* Subroutine */ int sigerr_(char *, ftnlen);
    extern /* Subroutine */ int chkout_(char *, ftnlen);
    extern /* Subroutine */ int setmsg_(char *, ftnlen);
    extern /* Subroutine */ int errint_(char *, integer *, ftnlen);
    extern logical return_(void);


    /* Module state */
    dafrwa_state_t* __state = get_dafrwa_state();
/* $ Abstract */

/*     Convert a record/word pair to its equivalent address within */
/*     a DAF. */

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

/*     DAF */

/* $ Keywords */

/*     CONVERSION */
/*     FILES */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     RECNO, */
/*     WORDNO     I   Record, word numbers of a location within DAF. */
/*     ADDR       O   Corresponding address. */

/* $ Detailed_Input */

/*     RECNO, */
/*     WORDNO      are the record and word numbers of an arbitrary */
/*                 location within a DAF. */

/* $ Detailed_Output */

/*     ADDR        is the corresponding address within the DAF. */

/* $ Parameters */

/*      None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     1) If either RECNO or WORDNO is zero or negative, the error */
/*        SPICE(DAFNOSUCHADDR) is signalled. */

/* $ Particulars */

/*     To the user, the data in a DAF appear to be a contiguous */
/*     collection of double precision numbers, each of which has an */
/*     address. To the DAF software, however, the data appear to be */
/*     a collection of records, each containing 128 double precision */
/*     words. The routines DAFARW and DAFRWA translate between these */
/*     two representations. */

/* $ Examples */

/*     Routines DAFRDA and DAFWDA illustrate the use of DAFARW and */
/*     DAFRWA. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     NAIF Document 167.0, "Double Precision Array Files (DAF) */
/*     Specification and User's Guide" */

/* $ Author_and_Institution */

/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.2, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     record/word to daf address */

/* -& */

/*     SPICELIB functions */


/*     Standard SPICE error handling. */

    switch(n__) {
	case 1: goto L_dafarw;
	}

    if (return_()) {
	return 0;
    } else if (*recno <= 0 || *wordno <= 0) {
	chkin_("DAFRWA", (ftnlen)6);
	setmsg_("No address for record #, word #.", (ftnlen)32);
	errint_("#", recno, (ftnlen)1);
	errint_("#", wordno, (ftnlen)1);
	sigerr_("SPICE(DAFNOSUCHADDR)", (ftnlen)20);
	chkout_("DAFRWA", (ftnlen)6);
	return 0;
    }

/*     If the record and word numbers are legal, the computation is */
/*     straightforward. */

    *addr__ = *wordno + (*recno - 1 << 7);
    return 0;
/* $Procedure DAFARW ( DAF, address to record/word ) */

L_dafarw:
/* $ Abstract */

/*     Convert an address within a DAF to its equivalent */
/*     record/word representation. */

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

/*     DAF */

/* $ Keywords */

/*     CONVERSION */
/*     FILES */

/* $ Declarations */

/*     INTEGER               ADDR */
/*     INTEGER               RECNO */
/*     INTEGER               WORDNO */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ADDR       I   Address within DAF. */
/*     RECNO, */
/*     WORDNO     O   Corresponding record, word numbers. */

/* $ Detailed_Input */

/*     ADDR        is an arbitrary address within a DAF. */

/* $ Detailed_Output */

/*     RECNO, */
/*     WORDNO      are the corresponding record and word numbers */
/*                 within the DAF. */

/* $ Parameters */

/*      None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     1) If ADDR is zero or negative, the error SPICE(DAFNOSUCHADDR) */
/*        is signalled. */

/* $ Particulars */

/*     To the user, the data in a DAF appear to be a contiguous */
/*     collection of double precision numbers, each of which has an */
/*     address. To the DAF software, however, the data appear to be */
/*     a collection of records, each containing 128 double precision */
/*     words. The routines DAFARW and DAFRWA translate between these */
/*     two representations. */

/* $ Examples */

/*     Routines DAFRDA and DAFWDA illustrate the use of DAFARW and */
/*     DAFRWA. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     NAIF Document 167.0, "Double Precision Array Files (DAF) */
/*     Specification and User's Guide" */

/* $ Author_and_Institution */

/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.2, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     daf address to record/word */

/* -& */

/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    } else if (*addr__ <= 0) {
	chkin_("DAFARW", (ftnlen)6);
	setmsg_("No record, word for address #.", (ftnlen)30);
	errint_("#", addr__, (ftnlen)1);
	sigerr_("SPICE(DAFNOSUCHADDR)", (ftnlen)20);
	chkout_("DAFARW", (ftnlen)6);
	return 0;
    }

/*     If the address is legal, the computation is straightforward. */

    *recno = (*addr__ - 1) / 128 + 1;
    *wordno = *addr__ - (*recno - 1 << 7);
    return 0;
} /* dafrwa_ */

/* Subroutine */ int dafrwa_(integer *recno, integer *wordno, integer *addr__)
{
    return dafrwa_0_(0, recno, wordno, addr__);
    }

/* Subroutine */ int dafarw_(integer *addr__, integer *recno, integer *wordno)
{
    return dafrwa_0_(1, recno, wordno, addr__);
    }

