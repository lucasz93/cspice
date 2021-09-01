/* pckpds.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern pckpds_init_t __pckpds_init;
static pckpds_state_t* get_pckpds_state(cspice_t* state) {
	if (!state->pckpds)
		state->pckpds = __cspice_allocate_module(sizeof(
	pckpds_state_t), &__pckpds_init, sizeof(__pckpds_init));
	return state->pckpds;

}

/* $Procedure PCKPDS ( PCK, pack descriptor ) */
/* Subroutine */ int pckpds_(cspice_t* __global_state, integer *body, char *
	frame, integer *type__, doublereal *first, doublereal *last, 
	doublereal *descr, ftnlen frame_len)
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
    integer ipart[5];
    integer refcod;
    char calfst[40];
    char callst[40];
    doublereal dppart[2];
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int irfnum_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    pckpds_state_t* __state = get_pckpds_state(__global_state);
/* $ Abstract */

/*     Perform routine error checks and if all checks pass, pack the */
/*     descriptor for a PCK segment */

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

/*     PCK. */

/* $ Keywords */

/*     PCK */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     BODY       I   The NAIF ID code for the body of the segment. */
/*     FRAME      I   The inertial frame for this segment. */
/*     TYPE       I   The type of PCK segment to create. */
/*     FIRST      I   The first epoch for which the segment is valid. */
/*     LAST       I   The last  epoch for which the segment is valid. */
/*     DESCR      O   A PCK segment descriptor. */

/* $ Detailed_Input */

/*     BODY       is the NAIF ID code for the body of the segment. */

/*     FRAME      is a string that names the inertial frame to which */
/*                states for the body shall be referenced. */

/*     TYPE       is the type of PCK segment to create. */

/*     FIRST      is the first epoch for which the segment will have */
/*                ephemeris data. */

/*     LAST       is the last epoch for which the segment will have */
/*                ephemeris data. */

/* $ Detailed_Output */

/*     DESCR       is a valid PCK segment descriptor to use */
/*                 when creating a DAF segment for this body. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) The error 'SPICE(BARYCENTERIDCODE)' is signalled if the */
/*        value of BODY is the ID code of a barycenter, codes */
/*        0, 1, ..., 9. */

/*     3) The error 'SPICE(INVALIDREFFRAME)' is signalled if FRAME */
/*        is not one of the known SPICE inertial reference frames. */

/*     4) The error 'SPICE(BADDESCRTIMES)' is signalled if FIRST */
/*        is greater than or equal to LAST */

/*     5) The error 'SPICE(UNKNOWNPCKTYPE)' is signalled if the */
/*        value of TYPE is outside the range 2 to 1000 (inclusive). */
/*        This does not ensure that the TYPE is a legitimate PCK */
/*        segment type, but it is a simple check that helps avoid */
/*        problems that arise from unitialized values or improperly */
/*        ordered calling arguments. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This is a utility routine for validating and creating */
/*     the descriptor for a PCK segment.  It is intended for */
/*     use only by routines that create PCK segments. */

/* $ Examples */

/*     Suppose that you wish to create a PCK segment of type X */
/*     and that you are writing a routine to handle the details */
/*     of the segment creation.  This routine can be used to */
/*     ensure that the descriptor needed for the segment is */
/*     properly formed and that the information in that descriptor */
/*     is reasonable. */

/*     Having collected the needed information you can create the */
/*     descriptor and then begin a new segment as shown below. */

/*     CALL PCKPDS ( BODY, FRAME, TYPE, FIRST, LAST, DESCR ) */
/*     CALL DAFBNA ( HANDLE, DESCR,  SEGID ) */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.1, 03-JAN-2014 (EDW) */

/*        Minor edits to Procedure; clean trailing whitespace. */
/*        Corrected order of header sections to conform to NAIF */
/*        standard. */

/* -    SPICELIB Version 1.0.0, 04-JAN-1995 (WLT) */

/* -& */
/* $ Index_Entries */

/*     Validate and pack a PCK segment descriptor */

/* -& */

/*     Spicelib Functions */


/*     Local Parameters */

/*     ND and NI values for a PCK file. */


/*     Length of a calender string. */


/*     Local Variables */


/*     Standard SPICLEIB error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "PCKPDS", (ftnlen)6);
    }

/*     We do not support orientation models for barycenters. */

    if (*body >= 0 && *body <= 9) {
	setmsg_(__global_state, "You have attempted to create a segment  for"
		" for a barycenter, and the PCK system does not support this.",
		 (ftnlen)103);
	sigerr_(__global_state, "SPICE(BARYCENTERIDCODE)", (ftnlen)23);
	chkout_(__global_state, "PCKPDS", (ftnlen)6);
	return 0;
    }

/*     Get the NAIF integer code for the reference frame. */

    irfnum_(__global_state, frame, &refcod, frame_len);
    if (refcod == 0) {
	setmsg_(__global_state, "The reference frame # is not supported.", (
		ftnlen)39);
	errch_(__global_state, "#", frame, (ftnlen)1, frame_len);
	sigerr_(__global_state, "SPICE(INVALIDREFFRAME)", (ftnlen)22);
	chkout_(__global_state, "PCKPDS", (ftnlen)6);
	return 0;
    }

/*     The segment stop time should be greater then the begin time. */

    if (*first >= *last) {

/*        We've got an error. Get the calendar string for the first */
/*        and last epochs. */

	etcal_(__global_state, first, calfst, (ftnlen)40);
	etcal_(__global_state, last, callst, (ftnlen)40);
	setmsg_(__global_state, "The segment start time: # (#) is at orafter"
		" the segment stop time # (#). ", (ftnlen)73);
	errdp_(__global_state, "#", first, (ftnlen)1);
	errch_(__global_state, "#", calfst, (ftnlen)1, (ftnlen)40);
	errdp_(__global_state, "#", last, (ftnlen)1);
	errch_(__global_state, "#", callst, (ftnlen)1, (ftnlen)40);
	sigerr_(__global_state, "SPICE(BADDESCRTIMES)", (ftnlen)20);
	chkout_(__global_state, "PCKPDS", (ftnlen)6);
	return 0;
    }

/*     The type must be something reasonable.  The interval from */
/*     2 to 1000 is what we are calling reasonable these days. */

    if (*type__ <= 1 || *type__ > 1000) {
	setmsg_(__global_state, "The type specified, #, is not supported wit"
		"hin the PCK system. ", (ftnlen)63);
	errint_(__global_state, "#", type__, (ftnlen)1);
	sigerr_(__global_state, "SPICE(UNKNOWNPCKTYPE)", (ftnlen)21);
	chkout_(__global_state, "PCKPDS", (ftnlen)6);
	return 0;
    }

/*     Well, that's it.  As far as we can determine these seem to be */
/*     reasonble values to put into a descriptor.   Do it. */

    ipart[0] = *body;
    ipart[1] = refcod;
    ipart[2] = *type__;
    ipart[3] = 0;
    ipart[4] = 0;
    dppart[0] = *first;
    dppart[1] = *last;
    dafps_(__global_state, &__state->c__2, &__state->c__5, dppart, ipart, 
	    descr);
    chkout_(__global_state, "PCKPDS", (ftnlen)6);
    return 0;
} /* pckpds_ */

