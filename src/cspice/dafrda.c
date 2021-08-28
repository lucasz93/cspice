/* dafrda.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int dafrda_state_t;
static inline dafrda_state_t* get_dafrda_state(cspice_t* state) {
	return 0;
}

/* $Procedure DAFRDA ( DAF, read data from address ) */
/* Subroutine */ int dafrda_(cspice_t* __global_state, integer *handle, 
	integer *begin, integer *end, doublereal *data)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    integer begr;
    integer begw;
    integer endr;
    integer endw;
    integer last;
    integer next;
    extern /* Subroutine */ int zzddhisn_(cspice_t*, integer *, logical *, 
	    logical *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer recno;
    logical found;
    integer first;
    extern /* Subroutine */ int cleard_(cspice_t*, integer *, doublereal *);
    extern /* Subroutine */ int dafrdr_(cspice_t*, integer *, integer *, 
	    integer *, integer *, doublereal *, logical *);
    extern /* Subroutine */ int dafarw_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int errhan_(cspice_t*, char *, integer *, ftnlen);
    logical native;
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    dafrda_state_t* __state = get_dafrda_state(__global_state);
/* $ Abstract */

/*     Read the double precision data bounded by two addresses within */
/*     a DAF. */

/*     Deprecated: This routine has been superseded by DAFGDA and */
/*     DAFGSR.  This routine is supported for purposes of backward */
/*     compatibility only. */

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

/*     FILES */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle of a DAF. */
/*     BEGIN, */
/*     END        I   Initial, final address within file. */
/*     DATA       O   Data contained between BEGIN and END. */

/* $ Detailed_Input */

/*     HANDLE      is the handle of a DAF. */

/*     BEGIN, */
/*     END         are the initial and final addresses of a contiguous */
/*                 set of double precision numbers within a DAF. */
/*                 Presumably, these make up all or part of a particular */
/*                 array. */

/* $ Detailed_Output */

/*     DATA        are the double precision data contained between */
/*                 the specified addresses within the specified file. */

/* $ Parameters */

/*      None. */

/* $ Exceptions */

/*     1) If BEGIN is zero or negative, the error SPICE(DAFNEGADDR) */
/*        is signalled. */

/*     2) If the BEGIN > END, the error SPICE(DAFBEGGTEND) */
/*        is signalled. */

/*     3) If the file associated with HANDLE is not of the native */
/*        binary file format this routine signals the error */
/*        SPICE(UNSUPPORTEDBFF). */

/*     4) If HANDLE is invalid, routines in the call tree of DAFRDA */
/*        signal an appropriate error. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     The principal reason that DAFs are so easy to use is that */
/*     the data in each DAF are considered to be one long contiguous */
/*     set of double precision numbers. You can grab data from anywhere */
/*     within a DAF without knowing (or caring) about the physical */
/*     records in which they are stored. */

/*     This routine has been made obsolete by the routines DAFGDA and */
/*     DAFGSR.  This routine is supported for reasons of backward */
/*     compatibility only.  New software development should utilize */
/*     DAFGDA or DAFGSR. */

/* $ Examples */

/*     The following code fragment illustrates the use of DAFRDA */
/*     to read data from an imaginary array. The array begins with a */
/*     directory containing 11 epochs. Each pair of epochs bounds */
/*     an interval, and each interval is covered by a set of eight */
/*     osculating elements. */

/*        CALL DAFUS ( SUM, ND, NI, DC, IC ) */
/*        BEGIN = IC(5) */
/*        END   = IC(6) */

/*        CALL DAFRDA ( HANDLE, BEGIN, BEGIN+10, EPOCHS ) */

/*        DO I = 1, 10 */
/*           IF ( ET .GE. EPOCHS(I)  .AND.  ET .LE. EPOCHS(I+1) ) THEN */
/*              OFFSET = IC(5) + 11 + (I - 1) * 8 */

/*              CALL DAFRDA ( HANDLE, OFFSET+1, OFFSET+8, ELEMENTS ) */
/*              RETURN */
/*           END IF */
/*        END DO */


/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     R.E. Thurman    (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.2, 18-MAY-2010 (BVS) */

/*        Index line now states that this routine is deprecated. */

/* -    SPICELIB Version 2.0.1, 27-OCT-2003 (NJB) */

/*        The header now states that this routine is deprecated. */
/*        The Exceptions header section has been extended. */
/*        Minor additional header updates were made. */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (FST) */

/*        Added SPICE(UNSUPPORTEDBFF) exception to the routine. */

/* -    SPICELIB Version 1.0.2, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     DEPRECATED read data from daf address */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (FST) */

/*        The exception SPICE(UNSUPPORTEDBFF) was added to guarantee */
/*        this routine's functionality remains unchanged as a result */
/*        of the updates to the underlying DAF software's utilization of */
/*        the handle manager.  In versions of the Toolkit prior to this, */
/*        all DAFs loaded were of the native binary file format. */
/*        While rather unlikely, this routine could be used to read */
/*        the contents of summary records in addition to the usual */
/*        data records.  The non-native to native translation process */
/*        for these two different types of records in general are not */
/*        the same.  Rather than attempt to interpret the caller's */
/*        intent, this routine is deprecated and restricted to */
/*        functioning only on DAFs of the native binary file format. */

/* -    Beta Version 1.1.0, 1-NOV-1989 (RET) */

/*        DAFRDA now only checks in and checks out if one of the two */
/*        possible exceptions occurs. The purpose of this change was to */
/*        help speed up a routine that gets called constantly by higher */
/*        level DAF routines. */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }

/*     Check to see if HANDLE is associated with a DAF of the native */
/*     binary file format. */

    zzddhisn_(__global_state, handle, &native, &found);

/*     If the HANDLE was located, then check whether the binary file */
/*     format is native.  Otherwise, defer diagnosing the missing */
/*     handle to DAFRDR. */

    if (found && ! native) {
	chkin_(__global_state, "DAFRDA", (ftnlen)6);
	setmsg_(__global_state, "The binary file format for file '#' is not "
		"native. This routine operates only on files of the native fo"
		"rmat.", (ftnlen)108);
	errhan_(__global_state, "#", handle, (ftnlen)1);
	sigerr_(__global_state, "SPICE(UNSUPPORTEDBFF)", (ftnlen)21);
	chkout_(__global_state, "DAFRDA", (ftnlen)6);
	return 0;
    }

/*     Bad addresses? */

    if (*begin <= 0) {
	chkin_(__global_state, "DAFRDA", (ftnlen)6);
	setmsg_(__global_state, "Negative value for BEGIN address: #", (
		ftnlen)35);
	errint_(__global_state, "#", begin, (ftnlen)1);
	sigerr_(__global_state, "SPICE(DAFNEGADDR)", (ftnlen)17);
	chkout_(__global_state, "DAFRDA", (ftnlen)6);
	return 0;
    } else if (*begin > *end) {
	chkin_(__global_state, "DAFRDA", (ftnlen)6);
	setmsg_(__global_state, "Beginning address (#) greater than ending a"
		"ddress (#).", (ftnlen)54);
	errint_(__global_state, "#", begin, (ftnlen)1);
	errint_(__global_state, "#", end, (ftnlen)1);
	sigerr_(__global_state, "SPICE(DAFBEGGTEND)", (ftnlen)18);
	chkout_(__global_state, "DAFRDA", (ftnlen)6);
	return 0;
    }

/*     Convert raw addresses to record/word representations. */

    dafarw_(__global_state, begin, &begr, &begw);
    dafarw_(__global_state, end, &endr, &endw);

/*     Get as many records as needed. Return the last part of the */
/*     first record, the first part of the last record, and all of */
/*     every record in between. Any record not found is assumed to */
/*     be filled with zeros. */

    next = 1;
    i__1 = endr;
    for (recno = begr; recno <= i__1; ++recno) {
	if (begr == endr) {
	    first = begw;
	    last = endw;
	} else if (recno == begr) {
	    first = begw;
	    last = 128;
	} else if (recno == endr) {
	    first = 1;
	    last = endw;
	} else {
	    first = 1;
	    last = 128;
	}
	dafrdr_(__global_state, handle, &recno, &first, &last, &data[next - 1]
		, &found);
	if (! found) {
	    i__2 = last - first + 1;
	    cleard_(__global_state, &i__2, &data[next - 1]);
	}
	next += last - first + 1;
    }
    return 0;
} /* dafrda_ */

