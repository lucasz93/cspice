/* zzckcv01.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int zzckcv01_state_t;
static zzckcv01_state_t* get_zzckcv01_state(cspice_t* state) {
	return 0;
}

/* $Procedure ZZCKCV01 ( Private --- C-kernel segment coverage, type 01 ) */
/* Subroutine */ int zzckcv01_(cspice_t* __global_state, integer *handle, 
	integer *arrbeg, integer *arrend, integer *sclkid, doublereal *tol, 
	char *timsys, doublereal *schedl, ftnlen timsys_len)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);

    /* Local variables */
    integer nrec;
    integer psiz;
    extern /* Subroutine */ int sct2e_(cspice_t*, integer *, doublereal *, 
	    doublereal *);
    integer i__;
    integer n;
    doublereal begin;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer tbase;
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    logical istdb;
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    integer avsln;
    extern logical eqstr_(cspice_t*, char *, char *, ftnlen, ftnlen);
    extern /* Subroutine */ int dafgda_(cspice_t*, integer *, integer *, 
	    integer *, doublereal *);
    doublereal et;
    doublereal buffer[100];
    integer remain;
    integer seglen;
    extern /* Subroutine */ int errhan_(cspice_t*, char *, integer *, ftnlen);
    doublereal finish;
    integer offset;
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    integer navsln;
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int wninsd_(cspice_t*, doublereal *, doublereal *,
	     doublereal *);
    extern logical return_(cspice_t*);


    /* Module state */
    zzckcv01_state_t* __state = get_zzckcv01_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Determine the "window" of coverage of a type 01 C-kernel segment. */

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

/*     CK */
/*     UTILITY */
/*     PRIVATE */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle of a C-kernel open for read access */
/*     ARRBEG     I   Beginning DAF address */
/*     ARREND     I   Ending DAF address */
/*     SCLKID     I   ID of SCLK associated with segment. */
/*     TOL        I   Tolerance in ticks. */
/*     TIMSYS     I   Time system used to represent coverage. */
/*     SCHEDL    I/O  An initialized window/schedule of interval */

/* $ Detailed_Input */

/*     HANDLE     is the handle of some DAF that is open for reading. */

/*     ARRBEG     is the beginning address of a type 01 segment */

/*     ARREND     is the ending address of a type 01 segment. */

/*     SCLKID     is the ID code of the spacecraft clock associated with */
/*                the object for which the segment contains pointing. */
/*                This is the ID code used by the SCLK conversion */
/*                routines. */

/*     TOL        is a tolerance value expressed in ticks of the */
/*                spacecraft clock associated with the segment. Before */
/*                each interval is inserted into the coverage window, */
/*                the intervals are expanded by TOL:  the left endpoint */
/*                of each interval is reduced by TOL and the right */
/*                endpoint is increased by TOL.  Any intervals that */
/*                overlap as a result of the expansion are merged. */

/*                The coverage window returned when TOL > 0 indicates */
/*                the coverage provided by the file to the CK readers */
/*                CKGPAV and CKGP when that value of TOL is passed to */
/*                them as an input. */


/*     TIMSYS     is a string indicating the time system used in the */
/*                output coverage window.  TIMSYS may have the values: */

/*                   'SCLK'    Elements of SCHEDL are expressed in */
/*                             encoded SCLK ("ticks"), where the clock */
/*                             is associated with the object designated */
/*                             by IDCODE. */

/*                   'TDB'     Elements of SCHEDL are expressed as */
/*                             seconds past J2000 TDB. */

/*                TIMSYS must be consistent with the system used for */
/*                the contents of SCHEDL on input, if any. */


/*     SCHEDL     is a schedule (window) of intervals, to which the */
/*                intervals of coverage for this segment will be added. */

/* $ Detailed_Output */

/*     SCHEDL     the input schedule updated to include the intervals */
/*                of coverage for this segment. Since type 01 segments, */
/*                don't have interpolation intervals, each epoch */
/*                associated with a pointing instance is treated as a */
/*                singleton interval. */

/* $ Parameters */

/*     None. */

/* $ Files */

/*     This routine reads the contents of the file associated with */
/*     HANDLE to locate coverage intervals. */

/* $ Exceptions */

/*     1) The error SPICE(BADCK1SEGMENT) is signaled if the derived */
/*        segment length from ARRBEG and ARREND does not match */
/*        the possible lengths computed from the segment metadata. */

/*     2) Routines in the call tree of this routine may signal errors */
/*        if insufficient room in SCHEDL exists or other error */
/*        conditions relating to file access arise. */

/*     3)  If TOL is negative, the error SPICE(VALUEOUTOFRANGE) is */
/*         signaled. */

/*     4)  If TIMSYS is not recognized, the error SPICE(INVALIDOPTION) */
/*         is signaled. */

/*     5) If a time conversion error occurs, the error will be */
/*         diagnosed by a routine in the call tree of this routine. */
/* C */
/* $ Particulars */

/*     This is a utility routine that determines the intervals of */
/*     coverage for a type 01 C-kernel segment. Since type 01 segments, */
/*     don't have interpolation intervals, each epoch associated with a */
/*     pointing instance is treated as a singleton interval. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */
/*     N.J. Bachman    (JPL) */
/*     B.V. Semenov    (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SUPPORT Version 1.0.0, 03-JAN-2005 (WLT)(NJB)(BVS) */

/*        Initial version. */

/* -& */

/*     SPICELIB Functions */


/*     Local Parameters */


/*     Local Variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "ZZCKCV01", (ftnlen)8);
    }

/*     Check tolerance value. */

    if (*tol < 0.) {
	setmsg_(__global_state, "Tolerance must be non-negative; actual valu"
		"e was #.", (ftnlen)51);
	errdp_(__global_state, "#", tol, (ftnlen)1);
	sigerr_(__global_state, "SPICE(VALUEOUTOFRANGE)", (ftnlen)22);
	chkout_(__global_state, "ZZCKCV01", (ftnlen)8);
	return 0;
    }

/*     Set a logical flag indicating whether the time systm is SCLK. */

    istdb = eqstr_(__global_state, timsys, "TDB", timsys_len, (ftnlen)3);

/*     Check time system. */

    if (! istdb) {
	if (! eqstr_(__global_state, timsys, "SCLK", timsys_len, (ftnlen)4)) {
	    setmsg_(__global_state, "Time system spec TIMSYS was #; allowed "
		    "values are SCLK and TDB.", (ftnlen)63);
	    errch_(__global_state, "#", timsys, (ftnlen)1, timsys_len);
	    sigerr_(__global_state, "SPICE(INVALIDOPTION)", (ftnlen)20);
	    chkout_(__global_state, "ZZCKCV01", (ftnlen)8);
	    return 0;
	}
    }

/*     The coverage window is the set of singleton intervals consisting */
/*     of the epochs of the pointing records. We'll need to find the */
/*     epochs. */

/*     First, get the number of records in this segment. */

    dafgda_(__global_state, handle, arrend, arrend, buffer);
    nrec = (integer) buffer[0];

/*     Determine the size of the pointing packets. This is dependent */
/*     on whether angular rate data is present in the segment or not. */
/*     We can determine this with the following computation: */

/*     Assume a record size of 4, i.e. no angular rate data. */

    navsln = nrec * 5 + (nrec - 1) / 100 + 1;

/*     Assume a record size of 7, i.e. angular rate data. */

    avsln = (nrec << 3) + (nrec - 1) / 100 + 1;

/*     Compute the actual length of the segment. */

    seglen = *arrend - *arrbeg + 1;
    if (seglen == navsln) {
	psiz = 4;
    } else if (seglen == avsln) {
	psiz = 7;
    } else {
	setmsg_(__global_state, "The requested segment in file # reports a l"
		"ength of # d.p. numbers, but the metadata in the segment ind"
		"icates the length must either be # (no angular rate data) or"
		" # (angular rate data). Perhaps the segment is not type 1?", (
		ftnlen)221);
	errhan_(__global_state, "#", handle, (ftnlen)1);
	errint_(__global_state, "#", &seglen, (ftnlen)1);
	errint_(__global_state, "#", &navsln, (ftnlen)1);
	errint_(__global_state, "#", &avsln, (ftnlen)1);
	sigerr_(__global_state, "SPICE(BADCK1SEGMENT)", (ftnlen)20);
	chkout_(__global_state, "ZZCKCV01", (ftnlen)8);
	return 0;
    }

/*     The epochs start right after the pointing data. Let TBASE be the */
/*     address preceding the first epoch. */

    tbase = *arrbeg + nrec * psiz - 1;

/*     Grab the epochs. Make a singleton interval out of each one; add */
/*     the interval to the coverage window. */

/*     For efficiency, we'll read the epochs into a buffer of length */
/*     BUFSIZ. */

    remain = nrec;
    offset = 0;
    while(remain > 0) {

/*        Buffer the next set of epochs. */

	n = min(100,remain);
	i__1 = tbase + offset + 1;
	i__2 = tbase + offset + n;
	dafgda_(__global_state, handle, &i__1, &i__2, buffer);

/*        Insert the current batch of N singleton intervals. */

	i__1 = n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    begin = buffer[(i__2 = i__ - 1) < 100 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "buffer", i__2, "zzckcv01_", 
		    (ftnlen)359)];
	    finish = buffer[(i__2 = i__ - 1) < 100 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "buffer", i__2, "zzckcv01_", 
		    (ftnlen)360)];
	    if (*tol > 0.) {

/*              Adjust the interval using the tolerance. */

/* Computing MAX */
		d__1 = begin - *tol;
		begin = max(d__1,0.);
		finish += *tol;
	    }

/*           Convert the time to TDB if necessary. */

	    if (istdb) {
		sct2e_(__global_state, sclkid, &begin, &et);
		begin = et;
		sct2e_(__global_state, sclkid, &finish, &et);
		finish = et;
	    }
	    wninsd_(__global_state, &begin, &finish, schedl);
	}
	offset += n;
	remain -= n;
    }
    chkout_(__global_state, "ZZCKCV01", (ftnlen)8);
    return 0;
} /* zzckcv01_ */

