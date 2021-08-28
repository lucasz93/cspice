/* spks14.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern spks14_init_t __spks14_init;
static inline spks14_state_t* get_spks14_state(cspice_t* state) {
	if (!state->spks14)
		state->spks14 = __cspice_allocate_module(sizeof(
	spks14_state_t), &__spks14_init, sizeof(__spks14_init));
	return state->spks14;

}

/* $Procedure      SPKS14 ( S/P Kernel, subset, type 14 ) */
/* Subroutine */ int spks14_(cspice_t* __global_state, integer *srchan, 
	doublereal *srcdsc, integer *dsthan, doublereal *dstdsc, char *dstsid,
	 ftnlen dstsid_len)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    integer body;
    integer i__;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int dafus_(cspice_t*, doublereal *, integer *, 
	    integer *, doublereal *, integer *);
    extern /* Subroutine */ int spk14a_(cspice_t*, integer *, integer *, 
	    doublereal *, doublereal *);
    extern /* Subroutine */ int spk14b_(cspice_t*, integer *, char *, integer 
	    *, integer *, char *, doublereal *, doublereal *, integer *, 
	    ftnlen, ftnlen);
    extern /* Subroutine */ int spk14e_(cspice_t*, integer *);
    doublereal dtemp[2];
    logical found;
    integer itemp[6];
    doublereal myref;
    integer dummy;
    integer chbdeg;
    extern logical failed_(cspice_t*);
    integer begidx;
    integer iframe;
    doublereal begtim;
    integer endidx;
    extern /* Subroutine */ int irfnam_(cspice_t*, integer *, char *, ftnlen);
    extern /* Subroutine */ int sgfref_(cspice_t*, integer *, doublereal *, 
	    integer *, integer *, doublereal *);
    doublereal endtim;
    doublereal record[128];
    integer center;
    extern /* Subroutine */ int sgfcon_(cspice_t*, integer *, doublereal *, 
	    integer *, integer *, doublereal *);
    char myfram[16];
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    integer recsiz;
    extern /* Subroutine */ int sgfrvi_(cspice_t*, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, logical *);
    extern /* Subroutine */ int sgfpkt_(cspice_t*, integer *, doublereal *, 
	    integer *, integer *, doublereal *, integer *);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    spks14_state_t* __state = get_spks14_state(__global_state);
/* $ Abstract */

/*     Extract a subset of the data in a type 14 SPK segment into a new */
/*     type 14 segment. */

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
/*     SRCHAN     I   Handle of the SPK file with the source segment. */
/*     SRCDSC     I   Descriptor for the source segment. */
/*     DSTHAN     I   Handle of the SPK file for the destination segment. */
/*     DSTDSC     I   Descriptor for the destination segment. */
/*     DSTSID     I   Segment identifier for the new segment. */

/* $ Detailed_Input */

/*     SRCHAN   The handle of the SPK file containing the source segment. */

/*     SRCDSC   The SPK descriptor for the source segment. */

/*     DSTHAN   The handle of the SPK file containing the new segment. */

/*     DSTDSC   The SPK descriptor for the destination segment. It */
/*              contains the desired start and stop times for the */
/*              requested subset. */

/*     DSTSID   The segment identifier for the destination segment. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If the length of the SPK record that is to be moved is larger */
/*        than MAXREC, the error 'SPICE(SPKRECTOOLARGE)' will be */
/*        signalled. */

/* $ Files */

/*     See arguments SRCHAN, DSTHAN. */

/* $ Particulars */

/*     This subroutine copies a subset of the data form one SPK segment */
/*     to another. */

/*     The exact structure of a segment of SPK type 14 is detailed in */
/*     the SPK Required Reading. Please see this document for details. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     1) We assume that the source descriptor actually describes a */
/*        segment in the source SPK file containing the time coverage */
/*        that is desired for the subsetting operation. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     K.R. Gehringer    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 08-MAR-1995 (KRG) */

/* -& */
/* $ Index_Entries */

/*     subset type_14 spk segment */

/* -& */

/*     SPICELIB functions */


/*     Local Parameters */

/*     This is the maximum size type 14 record that we can move. This */
/*     allows a 20th degree Chebyshev Polynomial, which should be more */
/*     than sufficient. This should be the same as the value in SPKPV. */


/*     Reference frame name size. See CHGIRF. */


/*     DAF ND and NI values for SPK files. */


/*     Length of a state. */


/*     Local Variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "SPKS14", (ftnlen)6);
    }

/*     First, unpack the destination segment descriptor and set some */
/*     local variables. */

    dafus_(__global_state, dstdsc, &__state->c__2, &__state->c__6, dtemp, 
	    itemp);
    begtim = dtemp[0];
    endtim = dtemp[1];
    body = itemp[0];
    center = itemp[1];
    iframe = itemp[2];
    irfnam_(__global_state, &iframe, myfram, (ftnlen)16);

/*     If we can't find the code, it can't be an SPK file. */

    if (failed_(__global_state)) {
	chkout_(__global_state, "SPKS14", (ftnlen)6);
	return 0;
    }

/*     Get the constants for this segment. There is only one. */

    sgfcon_(__global_state, srchan, srcdsc, &__state->c__1, &__state->c__1, 
	    dtemp);
    if (failed_(__global_state)) {
	chkout_(__global_state, "SPKS14", (ftnlen)6);
	return 0;
    }

/*     The first element of DTEMP now contains the number of coefficients */
/*     used for the Chebyshev polynomials. We need the degree of the */
/*     polynomial which is one less than the number of coefficients. */

    chbdeg = (integer) dtemp[0] - 1;

/*     Compute the size of the SPK record and signal an error if there is */
/*     not enough room in the variable RECORD to hold it. */

    recsiz = (chbdeg + 1) * 6 + 2;
    if (recsiz > 128) {
	setmsg_(__global_state, "Storage for # double precision numbers is n"
		"eeded for an SPK data record and only # locations were avail"
		"able. Update the parameter MAXREC in the subroutine SPKS14 a"
		"nd notify the NAIF group of this problem.", (ftnlen)204);
	errint_(__global_state, "#", &recsiz, (ftnlen)1);
	errint_(__global_state, "#", &__state->c__128, (ftnlen)1);
	sigerr_(__global_state, "SPICE(SPKRECTOOLARGE)", (ftnlen)21);
	chkout_(__global_state, "SPKS14", (ftnlen)6);
	return 0;
    }

/*     Get the beginning and ending indices for the packets we need for */
/*     the destination segment. */

    sgfrvi_(__global_state, srchan, srcdsc, &begtim, &myref, &begidx, &found);
    sgfrvi_(__global_state, srchan, srcdsc, &endtim, &myref, &endidx, &found);

/*     Begin the destination segment. */

    spk14b_(__global_state, dsthan, dstsid, &body, &center, myfram, &begtim, &
	    endtim, &chbdeg, dstsid_len, (ftnlen)16);
    if (failed_(__global_state)) {
	chkout_(__global_state, "SPKS14", (ftnlen)6);
	return 0;
    }

/*     Now we get the data one record at a time from the source segment */
/*     and write it out to the destination segment. */

    i__1 = endidx;
    for (i__ = begidx; i__ <= i__1; ++i__) {
	sgfpkt_(__global_state, srchan, srcdsc, &i__, &i__, record, &dummy);
	sgfref_(__global_state, srchan, srcdsc, &i__, &i__, &myref);
	spk14a_(__global_state, dsthan, &__state->c__1, record, &myref);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "SPKS14", (ftnlen)6);
	    return 0;
	}
    }

/*     Now all we need to do is end the segment. */

    spk14e_(__global_state, dsthan);
    chkout_(__global_state, "SPKS14", (ftnlen)6);
    return 0;
} /* spks14_ */

