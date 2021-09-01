/* ckw04e.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern ckw04e_init_t __ckw04e_init;
static ckw04e_state_t* get_ckw04e_state(cspice_t* state) {
	if (!state->ckw04e)
		state->ckw04e = __cspice_allocate_module(sizeof(
	ckw04e_state_t), &__ckw04e_init, sizeof(__ckw04e_init));
	return state->ckw04e;

}

/* $Procedure      CKW04E ( CK type 04: End a segment ) */
/* Subroutine */ int ckw04e_(cspice_t* __global_state, integer *handle, 
	doublereal *endtim)
{
    extern /* Subroutine */ int dafgs_(cspice_t*, doublereal *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int dafps_(cspice_t*, integer *, integer *, 
	    doublereal *, integer *, doublereal *);
    extern /* Subroutine */ int dafrs_(cspice_t*, doublereal *);
    doublereal descr[5];
    extern /* Subroutine */ int dafus_(cspice_t*, doublereal *, integer *, 
	    integer *, doublereal *, integer *);
    logical found;
    extern /* Subroutine */ int sgwes_(cspice_t*, integer *);
    extern /* Subroutine */ int dafbbs_(cspice_t*, integer *);
    extern /* Subroutine */ int daffpa_(cspice_t*, logical *);
    extern logical failed_(cspice_t*);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);
    doublereal dcd[2];
    integer icd[6];


    /* Module state */
    ckw04e_state_t* __state = get_ckw04e_state(__global_state);
/* $ Abstract */

/*     End the type 04 CK segment currently being written to the DAF */
/*     file associated with HANDLE. See also CKW04B and CKW04E. */

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

/*     CK */
/*     DAF */

/* $ Keywords */

/*     POINTING */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   The handle of an CK file open for writing. */
/*     ENDTIM     I   The segment coverage end encoded SCLK time. */

/* $ Detailed_Input */

/*     HANDLE     is the file handle of an CK file that has been */
/*                opened for writing, and to which a type 4 CK segment */
/*                is being written. */

/*     ENDTIM     is the encoded SCLK time for the end of the segment */
/*                coverage. */

/* $ Detailed_Output */

/*     None.       The type 4 segment in the DAF file associated with */
/*                 HANDLE will be ended, making the addition of the */
/*                 data to the file permanent. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  Errors reading or writing the file indicated by HANDLE will */
/*         be diagnosed by routine in the call tree of this routine. */

/* $ Files */

/*     See the argument HANDLE. */

/* $ Particulars */

/*     This routine ends a type 4 CK segment which is being written to */
/*     the DAF file associated with HANDLE. Ending the DAF segment is a */
/*     necessary step in the process of making the data a permanent part */
/*     of the DAF file. */

/*     This routine is one of a set of three routines for creating and */
/*     adding data to type 4 CK segments. These routines are: */

/*        CKW04B: Begin a type 4 CK segment. This routine must be */
/*                called before any data may be added to a type 4 */
/*                segment. */

/*        CKW04A: Add data to a type 4 CK segment. This routine may be */
/*                called any number of times after a call to CKW04B to */
/*                add type 4 records to the CK segment that was */
/*                started. */

/*        CKW04E: End a type 4 CK segment. This routine is called to */
/*                make the type 4 segment a permanent addition to the */
/*                DAF file. Once this routine is called, no further type */
/*                4 records may be added to the segment. A new segment */
/*                must be started. */

/*     A type 4 CK segment consists of coefficient sets for variable */
/*     order Chebyshev polynomials over consecutive time intervals of */
/*     a variable length. The gaps between intervals are allowed. */
/*     The Chebyshev polynomials represent individual quaternion */
/*     components q0, q1, q2 and q3 and individual angular velocities */
/*     AV1, AV2 and AV3 if they are included with the data. */

/*     The pointing data supplied to the type 4 CK writer (CKW04A) */
/*     is packed into an array as a sequence of records, */

/*        ---------------------------------------------------- */
/*        | Record 1 | Record 2 | .. | Record N-1 | Record N | */
/*        ---------------------------------------------------- */

/*     with each record in data packets has the following format. */

/*        ---------------------------------------------------- */
/*        | The midpoint of the approximation interval       | */
/*        ---------------------------------------------------- */
/*        | The radius of the approximation interval         | */
/*        ---------------------------------------------------- */
/*        | Number of coefficients for q0                    | */
/*        ---------------------------------------------------- */
/*        | Number of coefficients for q1                    | */
/*        ---------------------------------------------------- */
/*        | Number of coefficients for q2                    | */
/*        ---------------------------------------------------- */
/*        | Number of coefficients for q3                    | */
/*        ---------------------------------------------------- */
/*        | Number of coefficients for AV1                   | */
/*        ---------------------------------------------------- */
/*        | Number of coefficients for AV2                   | */
/*        ---------------------------------------------------- */
/*        | Number of coefficients for AV3                   | */
/*        ---------------------------------------------------- */
/*        | q0 Cheby coefficients                            | */
/*        ---------------------------------------------------- */
/*        | q1 Cheby coefficients                            | */
/*        ---------------------------------------------------- */
/*        | q2 Cheby coefficients                            | */
/*        ---------------------------------------------------- */
/*        | q3 Cheby coefficients                            | */
/*        ---------------------------------------------------- */
/*        | AV1 Cheby coefficients (optional)                | */
/*        ---------------------------------------------------- */
/*        | AV2 Cheby coefficients (optional)                | */
/*        ---------------------------------------------------- */
/*        | AV3 Cheby coefficients (optional)                | */
/*        ---------------------------------------------------- */

/* $ Examples */

/*     Assume that we have: */

/*        HANDLE   is the handle of an CK file opened with write */
/*                 access. */

/*        SEGID    is a character string of no more than 40 characters */
/*                 which provides a pedigree for the data in the CK */
/*                 segment we will create. */

/*        INST     is the SPICE ID code for the instrument whose */
/*                 pointing data is to be placed into the file. */

/*        AVFLAG   angular rates flag. */

/*        REFFRM   is the name of the SPICE reference frame for the */
/*                 pointing data. */

/*        BEGTIM   is the starting encoded SCLK time for which the */
/*                 segment is valid. */

/*        ENDTIM   is the ending encoded SCLK time for which the segment */
/*                 is valid. */

/*        N        is the number of type 4 records that we want to */
/*                 put into a segment in an CK file. */

/*        NPKTS    is integer array which contains the lengths of */
/*                 variable size data packets */

/*        RECRDS   contains N type 4 records packaged for the CK */
/*                 file. */

/*        SCSTRT   contains the initial encoded SC time for each of */
/*                 the records contained in RECRDS, where */

/*                    SCSTRT(I) < SCSTRT(I+1), I = 1, N-1 */

/*                    SCSTRT(1) <= FIRST, SCSTRT(N) < LAST */

/*     Then the following code fragment demonstrates how to create */
/*     a type 4 CK segment if all of the data for the segment is */
/*     available at one time. */

/*     C */
/*     C     Begin the segment. */
/*     C */
/*           CALL CKW04B ( HANDLE, BEGTIM, INST, REF, AVFLAG, SEGID ) */
/*     C */
/*     C     Add the data to the segment all at once. */
/*     C */
/*           CALL CKW04A ( HANDLE, N, NPKTS, RECRDS, SCSTRT ) */
/*     C */
/*     C     End the segment, making the segment a permanent */
/*     C     addition to the CK file. */
/*     C */
/*           CALL CKW04E ( HANDLE, ENDTIM ) */

/* $ Restrictions */

/*     1) The type 4 CK segment being closed must have been started by */
/*        the routine CKW04B, the routine which begins a type 4 CK */
/*        segment. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     Y.K. Zaiko     (JPL) */
/*     B.V. Semenov   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.1, 18-APR-2014 (BVS) */

/*        Minor header edits. */

/* -    SPICELIB Version 1.0.0, 05-MAY-1999 (YKZ) (BVS) */

/* -& */
/* $ Index_Entries */

/*     end a type_4 ck segment */

/* -& */

/*     SPICELIB functions. */


/*     Local parameters. */


/*     DAF ND and NI values for CK files and length of a DAF descriptor. */


/*     Local variables. */


/*     Standard SPICELIB error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "CKW04E", (ftnlen)6);
    }

/*     This is simple, just call the routine which ends a generic */
/*     segment. */

    sgwes_(__global_state, handle);
    if (failed_(__global_state)) {
	chkout_(__global_state, "CKW04E", (ftnlen)6);
	return 0;
    }

/*     Now update the descriptor with the end time. Locate the segment */
/*     with a backward search. */

    dafbbs_(__global_state, handle);
    daffpa_(__global_state, &found);
    if (! found) {

/*        We have a bug. */

	setmsg_(__global_state, "The segment which was just written could no"
		"t be found by a DAF search. This  indicates a serious error."
		"  Contact NAIF.", (ftnlen)118);
	sigerr_(__global_state, "SPICE(BUG)", (ftnlen)10);
	chkout_(__global_state, "CKW04E", (ftnlen)6);
	return 0;
    }

/*     Get the descriptor, set the end time, and update the descriptor */
/*     in the file. */

    dafgs_(__global_state, descr);
    dafus_(__global_state, descr, &__state->c__2, &__state->c__6, dcd, icd);
    dcd[1] = *endtim;
    dafps_(__global_state, &__state->c__2, &__state->c__6, dcd, icd, descr);
    dafrs_(__global_state, descr);

/*     All done. */

    chkout_(__global_state, "CKW04E", (ftnlen)6);
    return 0;
} /* ckw04e_ */

