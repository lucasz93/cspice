/* spkpds.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern spkpds_init_t __spkpds_init;
static spkpds_state_t* get_spkpds_state(cspice_t* state) {
	if (!state->spkpds)
		state->spkpds = __cspice_allocate_module(sizeof(
	spkpds_state_t), &__spkpds_init, sizeof(__spkpds_init));
	return state->spkpds;

}

/* $Procedure      SPKPDS ( SPK pack descriptor ) */
/* Subroutine */ int spkpds_(cspice_t* __global_state, integer *body, integer 
	*center, char *frame, integer *type__, doublereal *first, doublereal *
	last, doublereal *descr, ftnlen frame_len)
{
    extern /* Subroutine */ int etcal_(cspice_t*, doublereal *, char *, 
	    ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int dafps_(cspice_t*, integer *, integer *, 
	    doublereal *, integer *, doublereal *);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    integer ipart[6];
    integer refcod;
    char calfst[40];
    extern /* Subroutine */ int namfrm_(cspice_t*, char *, integer *, ftnlen);
    char callst[40];
    doublereal dppart[2];
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    spkpds_state_t* __state = get_spkpds_state(__global_state);
/* $ Abstract */

/*     Perform routine error checks and if all check pass, pack the */
/*     descriptor for an SPK segment */

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

/*     SPK */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     BODY       I   The NAIF ID code for the body of the segment. */
/*     CENTER     I   The center of motion for BODY. */
/*     FRAME      I   The frame for this segment. */
/*     TYPE       I   The type of SPK segment to create. */
/*     FIRST      I   The first epoch for which the segment is valid. */
/*     LAST       I   The last  epoch for which the segment is valid. */
/*     DESCR      O   An SPK segment descriptor. */

/* $ Detailed_Input */

/*     BODY       is the NAIF ID code for the body of the segment. */

/*     CENTER     is the center of motion for BODY. */

/*     FRAME      is a string that names the frame to which states for */
/*                the body shall be referenced. */

/*     TYPE       is the type of SPK segment to create. */

/*     FIRST      is the first epoch for which the segment will have */
/*                ephemeris data. */

/*     LAST       is the last epoch for which the segment will have */
/*                ephemeris data. */

/* $ Detailed_Output */

/*     DESCR       is a valid SPK segment descriptor to use */
/*                 when creating a DAF segment for this body. */

/* $ Parameters */

/*     None. */

/* $ Particulars */

/*     This is a utility routine for validating and creating */
/*     the descriptor for an SPK segment.  It is intended for */
/*     use only by routines that create SPK segments. */

/* $ Examples */

/*     Suppose that you wish to create an SPK segment of type X */
/*     and that you are writing a routine to handle the details */
/*     of the segment creation.  This routine can be used to */
/*     ensure that the descriptor needed for the segment is */
/*     properly formed and that the information in that descriptor */
/*     is reasonable. */

/*     Having collected the needed information you can create the */
/*     descriptor and then begin a new segment as shown below. */

/*     CALL SPKPDS ( BODY,   CENTER, FRAME, TYPE, FIRST, LAST, DESCR ) */
/*     CALL DAFBNA ( HANDLE, DESCR,  SEGID ) */

/* $ Restrictions */

/*     None. */

/* $ Exceptions */

/*     1) The error 'SPICE(BARYCENTEREPHEM)' is signalled if the */
/*        value of BODY is 0. */

/*     2) The error 'SPICE(BODYANDCENTERSAME)' is signalled if the */
/*        values of BODY and CENTER are the same. */

/*     3) The error 'SPICE(INVALIDREFFRAME)' is signalled if FRAME */
/*        is not one of the known SPICE reference frames. */

/*     4) The error 'SPICE(BADDESCRTIMES)' is signalled if FIRST */
/*        is greater than or equal to LAST */

/*     5) The error 'SPICE(UNKNOWNSPKTYPE)' is signalled if the */
/*        value of TYPE is outside the range 1 to 1000 (inclusive). */
/*        This does not ensure that the TYPE is a legitimate SPK */
/*        segment type, but it is a simple check that helps avoid */
/*        problems that arise from uninitialized values or improperly */
/*        ordered calling arguments. */

/* $ Files */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */
/*     K.R. Gehringer    (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 1995-SEP-19 (WLT) */

/*        Upgraded the routine to support non-inertial frames. */

/* -    SPICELIB Version 1.0.0, 1994-JAN-4 (WLT) (KRG) */

/* -& */
/* $ Index_Entries */

/*     Validate and pack an SPK segment descriptor */

/* -& */

/*     Spicelib Functions */


/*     Local Parameters */

/*     ND and NI values for an SPK file. */


/*     Length of a calender string. */


/*     Local Variables */


/*     Standard SPICELIB error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "SPKPDS", (ftnlen)6);
    }

/*     We do not support ephemerides for the solar system barycenter */
/*     (at least not yet anyway). */

    if (*body == 0) {
	setmsg_(__global_state, "You've attempted to create a segment for th"
		"e solar system barycenter.  This is not supported by the eph"
		"emeris system.", (ftnlen)117);
	sigerr_(__global_state, "SPICE(BARYCENTEREPHEM)", (ftnlen)22);
	chkout_(__global_state, "SPKPDS", (ftnlen)6);
	return 0;
    }

/*     There is no point in having an ephemeris for a body relative */
/*     to itself. */

    if (*body == *center) {
	setmsg_(__global_state, "You've attempted to create a segment for a "
		"body relative to itself. The body ID code was: #.", (ftnlen)
		92);
	errint_(__global_state, "#", body, (ftnlen)1);
	sigerr_(__global_state, "SPICE(BODYANDCENTERSAME)", (ftnlen)24);
	chkout_(__global_state, "SPKPDS", (ftnlen)6);
	return 0;
    }

/*     Get the NAIF integer code for the reference frame. */

    namfrm_(__global_state, frame, &refcod, frame_len);
    if (refcod == 0) {
	setmsg_(__global_state, "The reference frame # is not supported.", (
		ftnlen)39);
	errch_(__global_state, "#", frame, (ftnlen)1, frame_len);
	sigerr_(__global_state, "SPICE(INVALIDREFFRAME)", (ftnlen)22);
	chkout_(__global_state, "SPKPDS", (ftnlen)6);
	return 0;
    }

/*     The segment stop time should be greater then the begin time. */

    if (*first >= *last) {

/*        We've got an error. Get the calendar string for the first */
/*        and last epochs. */

	etcal_(__global_state, first, calfst, (ftnlen)40);
	etcal_(__global_state, last, callst, (ftnlen)40);
	setmsg_(__global_state, "The segment start time: # (#) is at or afte"
		"r the segment stop time # (#).", (ftnlen)73);
	errdp_(__global_state, "#", first, (ftnlen)1);
	errch_(__global_state, "#", calfst, (ftnlen)1, (ftnlen)40);
	errdp_(__global_state, "#", last, (ftnlen)1);
	errch_(__global_state, "#", callst, (ftnlen)1, (ftnlen)40);
	sigerr_(__global_state, "SPICE(BADDESCRTIMES)", (ftnlen)20);
	chkout_(__global_state, "SPKPDS", (ftnlen)6);
	return 0;
    }

/*     The type must be something reasonable.  The interval from */
/*     1 to 1000 is what we are calling reasonable these days. */

    if (*type__ <= 0 || *type__ > 1000) {
	setmsg_(__global_state, "The type specified, #, is not supported wit"
		"hin the SPK system.", (ftnlen)62);
	errint_(__global_state, "#", type__, (ftnlen)1);
	sigerr_(__global_state, "SPICE(UNKNOWNSPKTYPE)", (ftnlen)21);
	chkout_(__global_state, "SPKPDS", (ftnlen)6);
	return 0;
    }

/*     Well, that's it.  As far as we can determine these seem to be */
/*     reasonable values to put into a descriptor.   Do it. */

    ipart[0] = *body;
    ipart[1] = *center;
    ipart[2] = refcod;
    ipart[3] = *type__;
    ipart[4] = 0;
    ipart[5] = 0;
    dppart[0] = *first;
    dppart[1] = *last;
    dafps_(__global_state, &__state->c__2, &__state->c__6, dppart, ipart, 
	    descr);
    chkout_(__global_state, "SPKPDS", (ftnlen)6);
    return 0;
} /* spkpds_ */

