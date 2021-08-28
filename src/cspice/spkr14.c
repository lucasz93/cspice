/* spkr14.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern spkr14_init_t __spkr14_init;
static inline spkr14_state_t* get_spkr14_state(cspice_t* state) {
	if (!state->spkr14)
		state->spkr14 = __cspice_allocate_module(sizeof(
	spkr14_state_t), &__spkr14_init, sizeof(__spkr14_init));
	return state->spkr14;

}

/* $Procedure      SPKR14 ( Read SPK record from segment, type 14 ) */
/* Subroutine */ int spkr14_(cspice_t* __global_state, integer *handle, 
	doublereal *descr, doublereal *et, doublereal *record)
{
    integer ends;
    integer indx;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    logical found;
    doublereal value;
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    extern /* Subroutine */ int sgfcon_(cspice_t*, integer *, doublereal *, 
	    integer *, integer *, doublereal *);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int sgfpkt_(cspice_t*, integer *, doublereal *, 
	    integer *, integer *, doublereal *, integer *);
    extern /* Subroutine */ int sgfrvi_(cspice_t*, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, logical *);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    spkr14_state_t* __state = get_spkr14_state(__global_state);
/* $ Abstract */

/*     Read a single data record from a type 14 SPK segment. */

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

/*     SPK */

/* $ Keywords */

/*     EPHEMERIS */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle of the open SPK file. */
/*     DESCR      I   Descriptor of the segment with the desired record. */
/*     ET         I   Epoch used to identify the desired record. */
/*     RECORD     O   The desired type 14 SPK record. */

/* $ Detailed_Input */

/*     HANDLE   is the handle of the open SPK file which contains the */
/*              segment of interest. */

/*     DESCR    is the descriptor for a type 14 SPK segment that contains */
/*              the record of interest. */

/*     ET       is the target epoch used to determine the particular */
/*              record to be obtained from the SPK segment. */

/* $ Detailed_Output */

/*     RECORD   is the record from the specified segment which, */
/*              when evaluated at epoch ET, will give the state */
/*              (position and velocity) of some body, relative */
/*              to some center, in some inertial reference frame. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) It is assumed that the descriptor and handle supplied are */
/*        for a properly constructed type 14 segment. No checks are */
/*        performed to ensure this. */

/*     2) If the input ET value is not within the range specified */
/*        in the segment descriptor, the error SPICE(TIMEOUTOFBOUNDS) */
/*        is signalled. */

/*     3) All other errors are diagnosed by routines in the call tree */
/*        of this routine. */

/* $ Files */

/*     See argument HANDLE. */

/* $ Particulars */

/*     This subroutine will read a single record from a type 14 SPK */
/*     segment. The record read will provide the data necessary to */
/*     compute the state for a some body in some inertial frame at epoch */
/*     ET. */

/*     See the SPK Required Reading file for a description of the */
/*     structure of a type 14 SPK segment. */

/* $ Examples */

/*     The data returned by the SPKRnn routine is in a raw form, taken */
/*     directly from the segment.  As such, it will be not be directly */
/*     useful to a user unless they have a complete understanding of the */
/*     structure of the data type.  Given that understanding, however, */
/*     the SPKRnn routines could be used to "dump" and check segment data */
/*     for a particular epoch, as in the example which follows. */


/*     C */
/*     C     Get a segment applicable to a specified body and epoch. */
/*     C */
/*           CALL SPKSFS ( BODY, ET, HANDLE, DESCR, IDENT, FOUND ) */

/*     C */
/*     C     Look at parts of the descriptor. */
/*     C */
/*           CALL DAFUS ( DESCR, 2, 6, DCD, ICD ) */
/*           CENTER = ICD( 2 ) */
/*           REF    = ICD( 3 ) */
/*           TYPE   = ICD( 4 ) */

/*           IF ( TYPE .EQ. 14 ) THEN */
/*              CALL SPKR14 ( HANDLE, DESCR, ET, RECORD ) */
/*                  . */
/*                  .  Look at the RECORD data. */
/*                  . */
/*           END IF */

/* $ Restrictions */

/*     This subroutine should not be called directly by a casual user. It */
/*     is intended for use by the subroutine SPKPV, and certain tests for */
/*     error conditions are not performed here, as SPKPV will have */
/*     already performed them. */

/* $ Literature_References */

/*     NAIF Document 168.0, "S- and P- Kernel (SPK) Specification and */
/*     User's Guide" */

/* $ Author_and_Institution */

/*     K.R. Gehringer  (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 10-MAR-1995 (KRG) */

/* -& */
/* $ Index_Entries */

/*     read record from type_14 spk segment */

/* -& */

/*     SPICELIB functions */


/*     Local variables */

/*     The number of constant values stored with a type 14 segment */
/*     segment. */


/*     The beginning location in the output record for the non constant */
/*     segment data. */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "SPKR14", (ftnlen)6);
    }

/*     Check the request time against the time bounds in the segment */
/*     descriptor. In order to get the right data back from the generic */
/*     segment calls below, we need to be sure that the desired epoch */
/*     falls within the bounds of the segment, as specified by the */
/*     descriptor. The first two elements of the descriptor are the start */
/*     time for the segment and the stop time for the segment, */
/*     respectively. */

    if (*et < descr[0] || *et > descr[1]) {
	setmsg_(__global_state, "Request time # is outside of descriptor bou"
		"nds # : #.", (ftnlen)53);
	errdp_(__global_state, "#", et, (ftnlen)1);
	errdp_(__global_state, "#", descr, (ftnlen)1);
	errdp_(__global_state, "#", &descr[1], (ftnlen)1);
	sigerr_(__global_state, "SPICE(TIMEOUTOFBOUNDS)", (ftnlen)22);
	chkout_(__global_state, "SPKR14", (ftnlen)6);
	return 0;
    }

/*     Fetch the constants and store them in the first part of */
/*     the output RECORD. */

    sgfcon_(__global_state, handle, descr, &__state->c__1, &__state->c__1, 
	    record);

/*     Locate the time in the file less than or equal to the input ET, */
/*     obtaining its index. This will allow us to retrieve the proper */
/*     record. */

    sgfrvi_(__global_state, handle, descr, et, &value, &indx, &found);

/*     Fetch the appropriate record from the segment. */

    sgfpkt_(__global_state, handle, descr, &indx, &indx, &record[1], &ends);
    chkout_(__global_state, "SPKR14", (ftnlen)6);
    return 0;
} /* spkr14_ */

