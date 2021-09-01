/* spkw12.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern spkw12_init_t __spkw12_init;
static spkw12_state_t* get_spkw12_state(cspice_t* state) {
	if (!state->spkw12)
		state->spkw12 = __cspice_allocate_module(sizeof(
	spkw12_state_t), &__spkw12_init, sizeof(__spkw12_init));
	return state->spkw12;

}

/* $Procedure      SPKW12 ( SPK, write segment, type 12 ) */
/* Subroutine */ int spkw12_(cspice_t* __global_state, integer *handle, 
	integer *body, integer *center, char *frame, doublereal *first, 
	doublereal *last, char *segid, integer *degree, integer *n, 
	doublereal *states, doublereal *epoch1, doublereal *step, ftnlen 
	frame_len, ftnlen segid_len)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Local variables */
    extern logical even_(cspice_t*, integer *);
    integer i__;
    extern /* Subroutine */ int etcal_(cspice_t*, doublereal *, char *, 
	    ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    doublereal descr[5];
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    doublereal ltime;
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    char etstr[40];
    extern /* Subroutine */ int dafada_(cspice_t*, doublereal *, integer *);
    extern /* Subroutine */ int dafbna_(cspice_t*, integer *, doublereal *, 
	    char *, ftnlen);
    extern /* Subroutine */ int dafena_(cspice_t*);
    extern logical failed_(cspice_t*);
    integer chrcod;
    integer refcod;
    extern /* Subroutine */ int namfrm_(cspice_t*, char *, integer *, ftnlen);
    extern integer lastnb_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int spkpds_(cspice_t*, integer *, integer *, char 
	    *, integer *, doublereal *, doublereal *, doublereal *, ftnlen);
    extern logical return_(cspice_t*);
    integer winsiz;
    doublereal tol;


    /* Module state */
    spkw12_state_t* __state = get_spkw12_state(__global_state);
/* $ Abstract */

/*     Write a type 12 segment to an SPK file. */

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

/*     NAIF_IDS */
/*     SPC */
/*     SPK */
/*     TIME */

/* $ Keywords */

/*     EPHEMERIS */
/*     FILES */

/* $ Declarations */
/* $ Abstract */

/*     Declare parameters specific to SPK type 12. */

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

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 11-JAN-2014 (NJB) */

/* -& */

/*     MAXDEG         is the maximum allowed degree of type 12 */
/*                    interpolating polynomials. If the value of MAXDEG */
/*                    is increased, the SPICELIB routine SPKPVN must be */
/*                    changed accordingly. In particular, the size of */
/*                    the record passed to SPKRnn and SPKEnn must be */
/*                    increased, and comments describing the record size */
/*                    must be changed. */

/*                    The record size requirement is */

/*                       MAXREC = ( 3 * ( MAXDEG + 1 ) )  +  3 */



/*     TOLSCL         is a tolerance scale factor (also called a */
/*                    "relative tolerance") used for time coverage */
/*                    bound checking. TOLSCL is unitless. TOLSCL */
/*                    produces a tolerance value via the formula */

/*                       TOL = TOLSCL * MAX( ABS(FIRST), ABS(LAST) ) */

/*                    where FIRST and LAST are the coverage time bounds */
/*                    of a type 2 segment, expressed as seconds past */
/*                    J2000 TDB. */

/*                    The resulting parameter TOL is used as a tolerance */
/*                    for comparing the input segment descriptor time */
/*                    bounds to the first and last epoch covered by the */
/*                    sequence of time intervals defined by the inputs */
/*                    to SPKW12: */

/*                       EPOCH1 */
/*                       STEP */
/*                       N */

/*     Tolerance scale for coverage gap at the endpoints */
/*     of the segment coverage interval: */


/*     End of include file spk12.inc. */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     MAXDEG     P   Maximum degree of interpolating polynomials. */
/*     TOLSCL     P   Scale factor used to compute time bound tolerance. */
/*     HANDLE     I   Handle of an SPK file open for writing. */
/*     BODY       I   NAIF code for an ephemeris object. */
/*     CENTER     I   NAIF code for center of motion of BODY. */
/*     FRAME      I   Reference frame name. */
/*     FIRST      I   Start time of interval covered by segment. */
/*     LAST       I   End time of interval covered by segment. */
/*     SEGID      I   Segment identifier. */
/*     DEGREE     I   Degree of interpolating polynomials. */
/*     N          I   Number of states. */
/*     STATES     I   Array of states. */
/*     EPOCH1     I   Epoch of first state in STATES array. */
/*     STEP       I   Time step separating epochs of states. */

/* $ Detailed_Input */

/*     HANDLE         is the file handle of an SPK file that has been */
/*                    opened for writing. */

/*     BODY           is the NAIF integer code for an ephemeris object */
/*                    whose state relative to another body is described */
/*                    by the segment to be created. */

/*     CENTER         is the NAIF integer code for the center of motion */
/*                    of the object identified by BODY. */

/*     FRAME          is the NAIF name for a reference frame */
/*                    relative to which the state information for BODY */
/*                    is specified. */

/*     FIRST, */
/*     LAST           are, respectively, the start and stop times of */
/*                    the time interval over which the segment defines */
/*                    the state of BODY. */

/*     SEGID          is the segment identifier.  An SPK segment */
/*                    identifier may contain up to 40 characters. */

/*     DEGREE         is the degree of the Lagrange polynomials used to */
/*                    interpolate the states.  All components of the */
/*                    state vectors are interpolated by polynomials of */
/*                    fixed degree. */

/*     N              is the number of states in the input state vector */
/*                    array. */

/*     STATES         contains a time-ordered array of geometric states */
/*                    ( x, y, z, dx/dt, dy/dt, dz/dt, in kilometers and */
/*                    kilometers per second ) of BODY relative to CENTER, */
/*                    specified relative to FRAME. */

/*     EPOCH1         is the epoch corresponding to the first state in */
/*                    the state array.  Because extra states are needed */
/*                    at the beginning and end of the segment in order */
/*                    for the interpolation method to work, EPOCH1 will */
/*                    normally precede FIRST. */

/*     STEP           is the time step separating the epochs of adjacent */
/*                    states in the input state array.  STEP is specified */
/*                    in seconds. */

/* $ Detailed_Output */

/*     None.  See $Particulars for a description of the effect of this */
/*     routine. */

/* $ Parameters */

/*     See the include file spk12.inc for declarations of the */
/*     parameters described below. */


/*     TOLSCL         is a tolerance scale factor (also called a */
/*                    "relative tolerance") used for time coverage */
/*                    bound checking. TOLSCL is unitless. TOLSCL */
/*                    produces a tolerance value via the formula */

/*                       TOL = TOLSCL * MAX( ABS(FIRST), ABS(LAST) ) */

/*                    where FIRST and LAST are the coverage time bounds */
/*                    of a type 12 segment, expressed as seconds past */
/*                    J2000 TDB. */

/*                    The resulting parameter TOL is used as a tolerance */
/*                    for comparing the input segment descriptor time */
/*                    bounds to the first and last epoch covered by the */
/*                    sequence of time intervals defined by the inputs */
/*                    to SPKW12: */

/*                       EPOCH1 */
/*                       STEP */
/*                       N */


/*     MAXDEG         is the maximum degree of Hermite polynomials that */
/*                    can be used to interpolate states from the segment */
/*                    written by this routine. */

/* $ Exceptions */

/*     If any of the following exceptions occur, this routine will return */
/*     without creating a new segment. */

/*     1)  If FRAME is not a recognized name, the error */
/*         SPICE(INVALIDREFFRAME) is signaled. */

/*     2)  If the last non-blank character of SEGID occurs past index 40, */
/*         the error SPICE(SEGIDTOOLONG) is signaled. */

/*     3)  If SEGID contains any nonprintable characters, the error */
/*         SPICE(NONPRINTABLECHARS) is signaled. */

/*     4)  If DEGREE is not at least 1 or is greater than MAXDEG, the */
/*         error SPICE(INVALIDDEGREE) is signaled. */

/*     5)  If DEGREE is not odd, the error SPICE(INVALIDDEGREE) is */
/*         signaled. */

/*     6)  If the number of states N is not at least (DEGREE+1)/2, the */
/*         error SPICE(TOOFEWSTATES) will be signaled. */

/*     7)  If FIRST is greater than LAST then the error */
/*         SPICE(BADDESCRTIMES) will be signaled. */

/*     8)  If STEP is non-positive, the error SPICE(INVALIDSTEPSIZE) will */
/*         be signaled. */

/*     9)  If the first epoch EPOCH1 is greater than FIRST, the error */
/*         SPICE(BADDESCRTIMES) will be signaled. */

/*    10)  If the start time of the first record exceeds the descriptor */
/*         begin time by more than a computed tolerance, or if the end */
/*         time of the last record precedes the descriptor end time by */
/*         more than a computed tolerance, the error SPICE(COVERAGEGAP) */
/*         is signaled. See the Parameters section above for a */
/*         description of the tolerance. */

/* $ Files */

/*     A new type 12 SPK segment is written to the SPK file attached */
/*     to HANDLE. */

/* $ Particulars */

/*     This routine writes an SPK type 12 data segment to the open SPK */
/*     file according to the format described in the type 12 section of */
/*     the SPK Required Reading. The SPK file must have been opened with */
/*     write access. */

/* $ Examples */

/*     Suppose that you have states and are prepared to produce */
/*     a segment of type 12 in an SPK file. */

/*     The following code fragment could be used to add the new segment */
/*     to a previously opened SPK file attached to HANDLE. The file must */
/*     have been opened with write access. */

/*            C */
/*            C     Create a segment identifier. */
/*            C */
/*                  SEGID = 'MY_SAMPLE_SPK_TYPE_12_SEGMENT' */

/*            C */
/*            C     Write the segment. */
/*            C */
/*                  CALL SPKW12 (  HANDLE,  BODY,    CENTER,  FRAME, */
/*                .                FIRST,   LAST,    SEGID,   DEGREE, */
/*                .                N,       STATES,  EPOCH1,  STEP     ) */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 18-JAN-2013 (NJB) */

/*        Relaxed test on relationship between the time bounds of the */
/*        input record set (determined by EPOCH1, STEP, and N) and the */
/*        descriptor bounds FIRST and LAST. Now the descriptor bounds */
/*        may extend beyond the time bounds of the record set by a ratio */
/*        computed using the parameter TOLSCL (see Parameters above for */
/*        details). MAXDEG was increased to 27. */

/*        Corrected long error message for even degree case. */

/* -    SPICELIB Version 1.0.0, 25-FEB-2000 (NJB) */

/* -& */
/* $ Index_Entries */

/*     write spk type_12 ephemeris data segment */

/* -& */

/*     SPICELIB functions */


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
	chkin_(__global_state, "SPKW12", (ftnlen)6);
    }

/*     Set the window size corresponding to the input degree.  This */
/*     size will be used in various places below. */

    winsiz = (*degree + 1) / 2;

/*     Get the NAIF integer code for the reference frame. */

    namfrm_(__global_state, frame, &refcod, frame_len);
    if (refcod == 0) {
	setmsg_(__global_state, "The reference frame # is not supported.", (
		ftnlen)39);
	errch_(__global_state, "#", frame, (ftnlen)1, frame_len);
	sigerr_(__global_state, "SPICE(INVALIDREFFRAME)", (ftnlen)22);
	chkout_(__global_state, "SPKW12", (ftnlen)6);
	return 0;
    }

/*     Check to see if the segment identifier is too long. */

    if (lastnb_(__global_state, segid, segid_len) > 40) {
	setmsg_(__global_state, "Segment identifier contains more than 40 ch"
		"aracters.", (ftnlen)52);
	sigerr_(__global_state, "SPICE(SEGIDTOOLONG)", (ftnlen)19);
	chkout_(__global_state, "SPKW12", (ftnlen)6);
	return 0;
    }

/*     Now check that all the characters in the segment identifier */
/*     can be printed. */

    i__1 = lastnb_(__global_state, segid, segid_len);
    for (i__ = 1; i__ <= i__1; ++i__) {
	chrcod = *(unsigned char *)&segid[i__ - 1];
	if (chrcod < 32 || chrcod > 126) {
	    setmsg_(__global_state, "The segment identifier contains nonprin"
		    "table characters", (ftnlen)55);
	    sigerr_(__global_state, "SPICE(NONPRINTABLECHARS)", (ftnlen)24);
	    chkout_(__global_state, "SPKW12", (ftnlen)6);
	    return 0;
	}
    }

/*     Make sure that the degree of the interpolating polynomials is */
/*     in range. */

    if (*degree < 1 || *degree > 27) {
	setmsg_(__global_state, "The interpolating polynomials have degree #"
		"; the valid degree range is [1, #]", (ftnlen)77);
	errint_(__global_state, "#", degree, (ftnlen)1);
	errint_(__global_state, "#", &__state->c__27, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDDEGREE)", (ftnlen)20);
	chkout_(__global_state, "SPKW12", (ftnlen)6);
	return 0;
    }

/*     Make sure that the degree of the interpolating polynomials is odd. */

    if (even_(__global_state, degree)) {
	setmsg_(__global_state, "The interpolating polynomials have degree #"
		"; for SPK type 12, the degree must be odd.", (ftnlen)85);
	errint_(__global_state, "#", degree, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDDEGREE)", (ftnlen)20);
	chkout_(__global_state, "SPKW12", (ftnlen)6);
	return 0;
    }

/*     Make sure that the number of states is sufficient to define a */
/*     polynomial whose degree is DEGREE. */

    if (*n < winsiz) {
	setmsg_(__global_state, "At least # states are required to define a "
		"Hermite polynomial of degree #.  Number of states supplied: "
		" #", (ftnlen)105);
	errint_(__global_state, "#", &winsiz, (ftnlen)1);
	errint_(__global_state, "#", degree, (ftnlen)1);
	errint_(__global_state, "#", n, (ftnlen)1);
	sigerr_(__global_state, "SPICE(TOOFEWSTATES)", (ftnlen)19);
	chkout_(__global_state, "SPKW12", (ftnlen)6);
	return 0;
    }

/*     The segment stop time should be greater then the begin time. */

    if (*first >= *last) {
	setmsg_(__global_state, "The segment start time: # is greater then t"
		"he segment end time: #", (ftnlen)65);
	errdp_(__global_state, "#", first, (ftnlen)1);
	errdp_(__global_state, "#", last, (ftnlen)1);
	sigerr_(__global_state, "SPICE(BADDESCRTIMES)", (ftnlen)20);
	chkout_(__global_state, "SPKW12", (ftnlen)6);
	return 0;
    }

/*     The step size must be positive. */

    if (*step <= 0.) {
	setmsg_(__global_state, "The step size must be > 0 but was #. ", (
		ftnlen)37);
	errdp_(__global_state, "#", step, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDSTEPSIZE)", (ftnlen)22);
	chkout_(__global_state, "SPKW12", (ftnlen)6);
	return 0;
    }

/*     Compute the tolerance to use for descriptor time bound checks. */

/* Computing MAX */
    d__1 = abs(*first), d__2 = abs(*last);
    tol = max(d__1,d__2) * 1e-13;
    if (*first < *epoch1 - tol) {
	setmsg_(__global_state, "The segment descriptor start time # is too "
		"much less than the beginning time of the  segment data # (in"
		" seconds past J2000: #). The difference is # seconds; the  t"
		"olerance is # seconds.", (ftnlen)185);
	etcal_(__global_state, first, etstr, (ftnlen)40);
	errch_(__global_state, "#", etstr, (ftnlen)1, (ftnlen)40);
	etcal_(__global_state, epoch1, etstr, (ftnlen)40);
	errch_(__global_state, "#", etstr, (ftnlen)1, (ftnlen)40);
	errdp_(__global_state, "#", first, (ftnlen)1);
	d__1 = *epoch1 - *first;
	errdp_(__global_state, "#", &d__1, (ftnlen)1);
	errdp_(__global_state, "#", &tol, (ftnlen)1);
	sigerr_(__global_state, "SPICE(COVERAGEGAP)", (ftnlen)18);
	chkout_(__global_state, "SPKW12", (ftnlen)6);
	return 0;
    }

/*     The end time of the final record must be greater than or */
/*     equal to the end time of the segment. */

    ltime = *epoch1 + (*n - 1) * *step;
    if (*last > ltime + tol) {
	setmsg_(__global_state, "The segment descriptor end time # is too mu"
		"ch greater than the end time of the segment data # (in secon"
		"ds past J2000: #). The difference is # seconds; the toleranc"
		"e is # seconds.", (ftnlen)178);
	etcal_(__global_state, last, etstr, (ftnlen)40);
	errch_(__global_state, "#", etstr, (ftnlen)1, (ftnlen)40);
	etcal_(__global_state, &ltime, etstr, (ftnlen)40);
	errch_(__global_state, "#", etstr, (ftnlen)1, (ftnlen)40);
	errdp_(__global_state, "#", last, (ftnlen)1);
	d__1 = *last - ltime;
	errdp_(__global_state, "#", &d__1, (ftnlen)1);
	errdp_(__global_state, "#", &tol, (ftnlen)1);
	sigerr_(__global_state, "SPICE(COVERAGEGAP)", (ftnlen)18);
	chkout_(__global_state, "SPKW12", (ftnlen)6);
	return 0;
    }

/*     If we made it this far, we're ready to start writing the segment. */


/*     Create the segment descriptor. */

    spkpds_(__global_state, body, center, frame, &__state->c__12, first, last,
	     descr, frame_len);

/*     Begin a new segment. */

    dafbna_(__global_state, handle, descr, segid, segid_len);
    if (failed_(__global_state)) {
	chkout_(__global_state, "SPKW12", (ftnlen)6);
	return 0;
    }

/*     The type 12 segment structure is eloquently described by this */
/*     diagram from the SPK Required Reading: */

/*        +-----------------------+ */
/*        | State 1               | */
/*        +-----------------------+ */
/*        | State 2               | */
/*        +-----------------------+ */
/*                    . */
/*                    . */
/*                    . */
/*        +-----------------------+ */
/*        | State N               | */
/*        +-----------------------+ */
/*        | Epoch of state 1 (ET) | */
/*        +-----------------------+ */
/*        | Step size             | */
/*        +-----------------------+ */
/*        | Window size - 1       | */
/*        +-----------------------+ */
/*        | Number of states      | */
/*        +-----------------------+ */


    i__1 = *n * 6;
    dafada_(__global_state, states, &i__1);
    dafada_(__global_state, epoch1, &__state->c__1);
    dafada_(__global_state, step, &__state->c__1);
    d__1 = (doublereal) (winsiz - 1);
    dafada_(__global_state, &d__1, &__state->c__1);
    d__1 = (doublereal) (*n);
    dafada_(__global_state, &d__1, &__state->c__1);

/*     As long as nothing went wrong, end the segment. */

    if (! failed_(__global_state)) {
	dafena_(__global_state);
    }
    chkout_(__global_state, "SPKW12", (ftnlen)6);
    return 0;
} /* spkw12_ */

