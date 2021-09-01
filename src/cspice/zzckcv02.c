/* zzckcv02.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int zzckcv02_state_t;
static zzckcv02_state_t* get_zzckcv02_state(cspice_t* state) {
	return 0;
}

/* $Procedure ZZCKCV02 ( Private --- C-kernel segment coverage, type 02 ) */
/* Subroutine */ int zzckcv02_(cspice_t* __global_state, integer *handle, 
	integer *arrbeg, integer *arrend, integer *sclkid, doublereal *tol, 
	char *timsys, doublereal *schedl, ftnlen timsys_len)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    integer i_dnnt(f2c_state_t*, doublereal *), s_rnge(f2c_state_t*, char *, 
	    integer, char *, integer);

    /* Local variables */
    integer nrec;
    doublereal last[100];
    extern /* Subroutine */ int sct2e_(cspice_t*, integer *, doublereal *, 
	    doublereal *);
    integer i__;
    integer begat;
    doublereal begin;
    integer endat;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    logical istdb;
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    doublereal first[100];
    extern logical eqstr_(cspice_t*, char *, char *, ftnlen, ftnlen);
    extern /* Subroutine */ int dafgda_(cspice_t*, integer *, integer *, 
	    integer *, doublereal *);
    doublereal et;
    doublereal finish;
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int wninsd_(cspice_t*, doublereal *, doublereal *,
	     doublereal *);
    integer arrsiz;
    extern logical return_(cspice_t*);
    integer get;
    integer got;


    /* Module state */
    zzckcv02_state_t* __state = get_zzckcv02_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Determine the "window" of coverage of a type 02 C-kernel segment. */

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

/*     ARRBEG     is the beginning address of a type 02 segment */

/*     ARREND     is the ending address of a type 02 segment. */


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
/*                of coverage for this segment. */

/* $ Parameters */

/*     None. */

/* $ Files */

/*     This routine reads the contents of the file associated with */
/*     HANDLE to locate coverage intervals. */

/* $ Exceptions */

/*     1) Routines in the call tree of this routine may signal errors */
/*        if insufficient room in SCHEDL exists or other error */
/*        conditions relating to file access arise. */

/*     2) If TOL is negative, the error SPICE(VALUEOUTOFRANGE) is */
/*        signaled. */

/*     3) If TIMSYS is not recognized, the error SPICE(INVALIDOPTION) */
/*        is signaled. */

/*     4) If a time conversion error occurs, the error will be */
/*        diagnosed by a routine in the call tree of this routine */

/* $ Particulars */

/*     This is a utility routine that determines the intervals */
/*     of coverage for a type 02 C-kernel segment. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     W.L. Taber      (JPL) */
/*     F.S. Turner     (JPL) */
/*     B.V. Semenov    (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 03-JAN-2005 (NJB) (FST) (WLT) (BVS) */

/* -& */

/*     SPICELIB Functions */


/*     Local Parameters */


/*     Local Variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "ZZCKCV02", (ftnlen)8);
    }

/*     Check tolerance value. */

    if (*tol < 0.) {
	setmsg_(__global_state, "Tolerance must be non-negative; actual valu"
		"e was #.", (ftnlen)51);
	errdp_(__global_state, "#", tol, (ftnlen)1);
	sigerr_(__global_state, "SPICE(VALUEOUTOFRANGE)", (ftnlen)22);
	chkout_(__global_state, "ZZCKCV02", (ftnlen)8);
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
	    chkout_(__global_state, "ZZCKCV02", (ftnlen)8);
	    return 0;
	}
    }

/*     Determine the size of the array and the number of records */
/*     in it. */

    arrsiz = *arrend - *arrbeg + 1;
    d__1 = ((doublereal) arrsiz * 100. + 1.) / 1001.;
    nrec = i_dnnt(&__global_state->f2c, &d__1);

/*     The variable GOT tells us how many time endpoints we've */
/*     gotten so far. */

    got = 0;
    while(got < nrec) {
/* Computing MIN */
	i__1 = 100, i__2 = nrec - got;
	get = min(i__1,i__2);
	begat = *arrbeg + (nrec << 3) + got;
	endat = *arrbeg + (nrec << 3) + nrec + got;

/*        Retrieve the list next list of windows. */

	i__1 = begat + get - 1;
	dafgda_(__global_state, handle, &begat, &i__1, first);
	i__1 = endat + get - 1;
	dafgda_(__global_state, handle, &endat, &i__1, last);

/*        Insert the coverage intervals into the schedule. */

	i__1 = get;
	for (i__ = 1; i__ <= i__1; ++i__) {

/*           Adjust the interval using the tolerance. */

	    begin = first[(i__2 = i__ - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge(
		    &__global_state->f2c, "first", i__2, "zzckcv02_", (ftnlen)
		    295)];
	    finish = last[(i__2 = i__ - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge(
		    &__global_state->f2c, "last", i__2, "zzckcv02_", (ftnlen)
		    296)];
	    if (*tol > 0.) {
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
	got += get;
    }
    chkout_(__global_state, "ZZCKCV02", (ftnlen)8);
    return 0;
} /* zzckcv02_ */

