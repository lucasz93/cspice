/* spkw05.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern spkw05_init_t __spkw05_init;
static inline spkw05_state_t* get_spkw05_state(cspice_t* state) {
	if (!state->spkw05)
		state->spkw05 = __cspice_allocate_module(sizeof(
	spkw05_state_t), &__spkw05_init, sizeof(__spkw05_init));
	return state->spkw05;

}

/* $Procedure  SPKW05 ( Write SPK segment, type 5 ) */
/* Subroutine */ int spkw05_(cspice_t* __global_state, integer *handle, 
	integer *body, integer *center, char *frame, doublereal *first, 
	doublereal *last, char *segid, doublereal *gm, integer *n, doublereal 
	*states, doublereal *epochs, ftnlen frame_len, ftnlen segid_len)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Local variables */
    integer i__;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int dafps_(cspice_t*, integer *, integer *, 
	    doublereal *, integer *, doublereal *);
    doublereal descr[5];
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    integer value;
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    extern /* Subroutine */ int dafada_(cspice_t*, doublereal *, integer *);
    extern /* Subroutine */ int dafbna_(cspice_t*, integer *, doublereal *, 
	    char *, ftnlen);
    extern /* Subroutine */ int dafena_(cspice_t*);
    extern logical failed_(cspice_t*);
    integer refcod;
    extern /* Subroutine */ int namfrm_(cspice_t*, char *, integer *, ftnlen);
    extern integer lastnb_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);
    doublereal dcd[2];
    integer icd[6];


    /* Module state */
    spkw05_state_t* __state = get_spkw05_state(__global_state);
/* $ Abstract */

/*     Write an SPK segment of type 5 given a time-ordered set of */
/*     discrete states and epochs, and the gravitational parameter */
/*     of a central body. */

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
/*     SPC */
/*     NAIF_IDS */

/* $ Keywords */

/*     EPHEMERIS */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle of an SPK file open for writing. */
/*     BODY       I   Body code for ephemeris object. */
/*     CENTER     I   Body code for the center of motion of the body. */
/*     FRAME      I   The reference frame of the states. */
/*     FIRST      I   First valid time for which states can be computed. */
/*     LAST       I   Last valid time for which states can be computed. */
/*     SEGID      I   Segment identifier. */
/*     GM         I   Gravitational parameter of central body. */
/*     N          I   Number of states and epochs. */
/*     STATES     I   States. */
/*     EPOCHS     I   Epochs. */

/* $ Detailed_Input */

/*     HANDLE      is the file handle of an SPK file */
/*                 opened for writing. */

/*     BODY        is the NAIF ID for the body whose states are */
/*                 to be recorded in an SPK file. */

/*     CENTER      is the NAIF ID for the center of motion associated */
/*                 with BODY. */

/*     FRAME       is the reference frame that states are referenced to, */
/*                 for example 'J2000'. */

/*     FIRST       are the bounds on the ephemeris times, expressed as */
/*     LAST        seconds past J2000, for which the states can be used */
/*                 to interpolate a state for BODY. */

/*     SEGID       is the segment identifier. An SPK segment identifier */
/*                 may contain up to 40 characters. */

/*     GM          is the gravitational parameter of the central body */
/*                 ( in units of kilometers **3 / seconds **2 ). */

/*     N           is the number of states and epochs to be stored */
/*                 in the segment. */

/*     STATES      contains a time-ordered array of geometric states */
/*                 ( x, y, z, dx/dt, dy/dt, dz/dt, in kilometers and */
/*                 kilometers per second ) of the target body with */
/*                 respect to the central body specified in the segment */
/*                 descriptor. */

/*     EPOCHS      contains the epochs (ephemeris seconds past J2000) */
/*                 corresponding to the states in STATES.  Epochs must */
/*                 form a strictly increasing sequence. */

/* $ Detailed_Output */

/*     None.  A type 5 segment is written to the file attached to HANDLE. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If GM is not positive, the error SPICE(NONPOSITIVEMASS) */
/*        signals. */

/*     2) If the input epochs do not form an increasing sequence, the */
/*        error SPICE(UNORDEREDTIMES) will be signalled. */

/*     3) If the number of states and epochs is not positive then the */
/*        error SPICE(NUMSTATESNOTPOS) will be signalled. */

/*     4) If FIRST is greater than LAST then the error */
/*        SPICE(BADDESCRTIMES) will be signalled. */

/*     5) If SEGID is more than 40 characters long, the error */
/*        SPICE(SEGIDTOOLONG) is signalled. */

/*     6) If SEGID contains any nonprintable characters, the error */
/*        SPICE(NONPRINTABLECHARS) is signalled. */

/*     7) Any file I/O problems will be detected and diagnosed by one */
/*        of the DAF routines called by this routine. */

/* $ Files */

/*     A new type 05 SPK segment is written to the SPK file attached */
/*     to HANDLE. */

/* $ Particulars */

/*     This routine writes an SPK type 05 data segment to the open SPK */
/*     file according to the format described in the type 05 section of */
/*     the SPK Required Reading. The SPK file must have been opened with */
/*     write access. */

/* $ Examples */

/*     Suppose that you have states and are prepared to produce */
/*     a segment of type 05 in an SPK file. */

/*     The following code fragment could be used to add the new segment */
/*     to a previously opened SPK file attached to HANDLE. The file must */
/*     have been opened with write access. */

/*     C */
/*     C      Create a segment identifier. */
/*     C */
/*            SEGID = 'MY_SAMPLE_SPK_TYPE_5_SEGMENT' */

/*     C */
/*     C      Write the segment. */
/*     C */
/*            CALL SPKW05 ( HANDLE, BODY, CENTER, FRAME,  FIRST, LAST, */
/*          .               SEGID,  GM,   N,      STATES, EPOCHS      ) */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     K.R. Gehringer  (JPL) */
/*     J.M. Lynch      (JPL) */
/*     W.L. Taber      (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 30-OCT-2006 (BVS) */

/*        Removed restriction that the input reference frame should be */
/*        inertial by changing the routine that determins the frame ID */
/*        from the name from IRFNUM to NAMFRM. */

/* -    SPICELIB Version 1.0.2, 27-JAN-2003 (EDW) */

/*        Added error check to catch non-positive gravitational */
/*        parameter GM. */

/* -    SPICELIB Version 1.0.1, 05-OCT-1993 (KRG) */

/*        Removed all references to a specific method of opening the SPK */
/*        file in the $ Brief_I/O, $ Detailed_Input, $ Particulars and */
/*        $ Examples sections of the header. It is assumed that a person */
/*        using this routine has some knowledge of the DAF system and the */
/*        methods for obtaining file handles. */

/* -    SPICELIB Version 1.0.0, 01-APR-1992 (JML) (WLT) (IMU) */

/* -& */
/* $ Index_Entries */

/*     write spk type_5 ephemeris data segment */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.1.0, 30-OCT-2006 (BVS) */

/*        Removed restriction that the input reference frame should be */
/*        inertial by changing the routine that determins the frame ID */
/*        from the name from IRFNUM to NAMFRM. */

/* -    SPICELIB Version 1.0.2, 27-JAN-2003 (EDW) */

/*        Added error check to catch non-positive gravitational */
/*        parameter GM. */

/* -    SPICELIB Version 1.0.1, 05-OCT-1993 (KRG) */

/*        Removed all references to a specific method of opening the SPK */
/*        file in the $ Brief_I/O, $ Detailed_Input,  and $ Examples */
/*        sections of the header. It is assumed that a person using this */
/*        routine has some knowledge of the DAF system and the methods */
/*        for obtaining file handles. */

/* -    SPICELIB Version 1.0.0, 01-APR-1992 (JML) (WLT) (IMU) */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */

/*     SIDLEN is the maximum number of characters allowed in an */
/*     SPK segment identifier. */

/*     NS is the size of a packed SPK segment descriptor. */

/*     ND is the number of double precision components in an SPK */
/*     segment descriptor. */

/*     NI is the number of integer components in an SPK segment */
/*     descriptor. */

/*     DTYPE is the data type. */

/*     FPRINT is the integer value of the first printable ASCII */
/*     character. */

/*     LPRINT is the integer value of the last printable ASCII character. */



/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "SPKW05", (ftnlen)6);
    }
    if (*gm <= 0.) {
	setmsg_(__global_state, "GM = #; Non-positive gravitational parameter"
		, (ftnlen)44);
	errdp_(__global_state, "#", gm, (ftnlen)1);
	sigerr_(__global_state, "SPICE(NONPOSITIVEMASS)", (ftnlen)22);
	chkout_(__global_state, "SPKW05", (ftnlen)6);
	return 0;
    }

/*     Get the NAIF integer code for the reference frame. */

    namfrm_(__global_state, frame, &refcod, frame_len);
    if (refcod == 0) {
	setmsg_(__global_state, "The reference frame # is not supported.", (
		ftnlen)39);
	errch_(__global_state, "#", frame, (ftnlen)1, frame_len);
	sigerr_(__global_state, "SPICE(INVALIDREFFRAME)", (ftnlen)22);
	chkout_(__global_state, "SPKW05", (ftnlen)6);
	return 0;
    }

/*     Make sure that the number of states and epochs is positive. */

    if (*n <= 0) {
	setmsg_(__global_state, "The number of states and epochs is not posi"
		"tive. N = #", (ftnlen)54);
	errint_(__global_state, "#", n, (ftnlen)1);
	sigerr_(__global_state, "SPICE(NUMSTATESNOTPOS)", (ftnlen)22);
	chkout_(__global_state, "SPKW05", (ftnlen)6);
	return 0;
    }

/*     Check the input epochs to make sure that they form a */
/*     strictly increasing sequence. */

    i__1 = *n;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if (epochs[i__ - 1] <= epochs[i__ - 2]) {
	    setmsg_(__global_state, "Epoch # is out of order. ", (ftnlen)25);
	    errdp_(__global_state, "#", &epochs[i__ - 1], (ftnlen)1);
	    sigerr_(__global_state, "SPICE(UNORDEREDTIMES)", (ftnlen)21);
	    chkout_(__global_state, "SPKW05", (ftnlen)6);
	    return 0;
	}
    }

/*     The segment stop time should be greater then the begin time. */

    if (*first > *last) {
	setmsg_(__global_state, "The segment start time: # is greater then t"
		"he segment end time: #", (ftnlen)65);
	errdp_(__global_state, "#", first, (ftnlen)1);
	errdp_(__global_state, "#", last, (ftnlen)1);
	sigerr_(__global_state, "SPICE(BADDESCRTIMES)", (ftnlen)20);
	chkout_(__global_state, "SPKW05", (ftnlen)6);
	return 0;
    }

/*     Now check that all the characters in the segid can be printed. */

    i__1 = lastnb_(__global_state, segid, segid_len);
    for (i__ = 1; i__ <= i__1; ++i__) {
	value = *(unsigned char *)&segid[i__ - 1];
	if (value < 32 || value > 126) {
	    setmsg_(__global_state, "The segment identifier contains nonprin"
		    "table characters", (ftnlen)55);
	    sigerr_(__global_state, "SPICE(NONPRINTABLECHARS)", (ftnlen)24);
	    chkout_(__global_state, "SPKW05", (ftnlen)6);
	    return 0;
	}
    }

/*     Also check to see if the segment identifier is too long. */

    if (lastnb_(__global_state, segid, segid_len) > 40) {
	setmsg_(__global_state, "Segment identifier contains more than 40 ch"
		"aracters.", (ftnlen)52);
	sigerr_(__global_state, "SPICE(SEGIDTOOLONG)", (ftnlen)19);
	chkout_(__global_state, "SPKW05", (ftnlen)6);
	return 0;
    }

/*     Store the start and end times to be associated */
/*     with this segment. */

    dcd[0] = *first;
    dcd[1] = *last;

/*     Create the integer portion of the descriptor. */

    icd[0] = *body;
    icd[1] = *center;
    icd[2] = refcod;
    icd[3] = 5;

/*     Pack the segment descriptor. */

    dafps_(__global_state, &__state->c__2, &__state->c__6, dcd, icd, descr);

/*     Begin a new segment. */

    dafbna_(__global_state, handle, descr, segid, segid_len);
    if (failed_(__global_state)) {
	chkout_(__global_state, "SPKW05", (ftnlen)6);
	return 0;
    }

/*     This could hardly be simpler. Stuff the states into the segment, */
/*     followed by the epochs. */

    i__1 = *n * 6;
    dafada_(__global_state, states, &i__1);
    dafada_(__global_state, epochs, n);

/*     If there are at least 100 state/epoch pairs, write a directory */
/*     containing every 100'th epoch. */

    i__ = 100;
    while(i__ <= *n) {
	dafada_(__global_state, &epochs[i__ - 1], &__state->c__1);
	i__ += 100;
    }

/*     Store the GM of the central body, and the number of states. */

    dafada_(__global_state, gm, &__state->c__1);
    d__1 = (doublereal) (*n);
    dafada_(__global_state, &d__1, &__state->c__1);

/*     If anything went wrong, don't end the segment. */

    if (! failed_(__global_state)) {
	dafena_(__global_state);
    }
    chkout_(__global_state, "SPKW05", (ftnlen)6);
    return 0;
} /* spkw05_ */

