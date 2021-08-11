/* dafrwd.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern dafrwd_init_t __dafrwd_init;
static dafrwd_state_t* get_dafrwd_state() {
	cspice_t* state =  __cspice_get_state();
	if (!state->dafrwd)
		state->dafrwd = __cspice_allocate_module(sizeof(
	dafrwd_state_t), &__dafrwd_init, sizeof(__dafrwd_init));
	return state->dafrwd;

}

/* $Procedure DAFRWD ( DAF, read, write double precision ) */
/* Subroutine */ int dafrwd_0_(int n__, integer *handle, integer *recno, 
	integer *begin, integer *end, doublereal *drec, doublereal *data, 
	logical *found, integer *reads, integer *reqs)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_rnge(char *, integer, char *, integer), s_wdue(cilist *), 
	    do_uio(integer *, char *, ftnlen), e_wdue(void);

    /* Local variables */
    logical done;
    integer unit;
    extern /* Subroutine */ int zzdafgdr_(integer *, integer *, doublereal *, 
	    logical *);
    extern /* Subroutine */ int zzddhrcm_(integer *, integer *, integer *);
    extern /* Subroutine */ int zzdafgsr_(integer *, integer *, integer *, 
	    integer *, doublereal *, logical *);
    extern /* Subroutine */ int zzddhhlu_(integer *, char *, logical *, 
	    integer *, ftnlen);
    extern /* Subroutine */ int zzddhisn_(integer *, logical *, logical *);
    integer b;
    integer e;
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    extern /* Subroutine */ int minai_(integer *, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int moved_(doublereal *, integer *, doublereal *);
    integer count;
    integer nd;
    extern logical failed_(void);
    integer ni;
    extern /* Subroutine */ int dafhsf_(integer *, integer *, integer *);
    logical locfnd;
    integer bufloc;
    extern /* Subroutine */ int errhan_(char *, integer *, ftnlen);
    integer minval;
    logical native;
    extern /* Subroutine */ int sigerr_(char *, ftnlen);
    extern /* Subroutine */ int chkout_(char *, ftnlen);
    logical stored;
    extern /* Subroutine */ int setmsg_(char *, ftnlen);
    integer iostat;
    extern /* Subroutine */ int errint_(char *, integer *, ftnlen);
    extern logical return_(void);

    /* Fortran I/O blocks */



    /* Module state */
    dafrwd_state_t* __state = get_dafrwd_state();
/* $ Abstract */

/*     Read, write, and rewrite double precision records to and */
/*     from DAFs. */

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

/*     Variable  I/O  Entry */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   DAFGDR. DAFGSR, DAFRDR (Obsolete), DAFWDR */
/*     RECNO      I   DAFGDR. DAFGSR, DAFRDR (Obsolete), DAFWDR */
/*     BEGIN      I   DAFGDR. DAFGSR, DAFRDR (Obsolete) */
/*     END        I   DAFGDR. DAFGSR, DAFRDR (Obsolete) */
/*     DREC       I   DAFWDR */
/*     DATA       O   DAFGDR. DAFGSR, DAFRDR (Obsolete) */
/*     FOUND      O   DAFGDR. DAFGSR, DAFRDR (Obsolete) */
/*     READS      O   DAFNRR */
/*     REQS       O   DAFNRR */
/*     RBSIZE     P   DAFGDR. DAFGSR, DAFRDR (Obsolete), DAFWDR, DAFNRR */

/* $ Detailed_Input */

/*     HANDLE      is the handle associated with a DAF. */

/*     RECNO       is the record number of a double precision record */
/*                 within a DAF to be read or written. */

/*     BEGIN       is the first in word in a double precision record */
/*                 to be read. */

/*     END         is the last in word in a double precision record */
/*                 to be read. */

/*     DREC        contains a single double precision record, to be */
/*                 written to the specified DAF. */

/* $ Detailed_Output */

/*     DATA        contains a portion of a single double precision */
/*                 record, read from the specified DAF. */

/*     FOUND       is true when the specified record is found, and is */
/*                 false otherwise. */

/*     READS, */
/*     REQS        are the number of physical reads and the number */
/*                 of requests processed by DAFRDR during the current */
/*                 execution of the calling program. */


/* $ Parameters */

/*     RBSIZE      is the size of the record buffer maintained by */
/*                 DAFRWD. In effect, RBSIZE is the maximum number */
/*                 of records that can be stored (buffered) at any */
/*                 one time. Higher values of RBSIZE reduce the */
/*                 amount of time spent reading from disk at the */
/*                 cost of increasing the amount of space required */
/*                 by the calling program. The optimal value of */
/*                 RBSIZE may differ from environment to environment, */
/*                 and may even vary from application to application. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     1) If DAFRWD is called directly, the error SPICE(BOGUSENTRY) */
/*        is signalled. */

/*     2) See entry points DAFGDR, DAFGSR, DAFRDR, DAFWDR, and DAFNRR */
/*        for exceptions specific to those entry points. */

/* $ Particulars */

/*     DAFRWD serves as an umbrella, allowing data to be shared by its */
/*     entry points: */

/*        DAFGDR         Read double precision record. */

/*        DAFGSR         Read summary/descriptor record. */

/*        DAFRDR         Read double precision record. (Obsolete, use */
/*                       DAFGDR) */

/*        DAFWDR         Write double precision record. */

/*        DAFNRR         Number of reads, requests. */

/*     DAFGDR, DAFGSR, and DAFWDR are the only approved means for */
/*     reading and writing double precision records to and from DAFs. */
/*     DAFRDR continues to function, but only on files of the native */
/*     binary format.  They keep track of which records have been read */
/*     most recently, and of which records have been requested most */
/*     often, in order to minimize the amount of time spent actually */
/*     reading from external storage. */

/*     DAFNRR may be used at any time during the execution of a */
/*     program to determine the number of requests that have been */
/*     processed, and the number of actual read operations needed */
/*     to fulfill those requests. Ideally, the ratio of reads to */
/*     requests should approach zero. In the worst case, the ratio */
/*     approaches one. The ratio is related to the size of the */
/*     record buffer, which controlled by parameter RBSIZE. The */
/*     results returned by DAFNRR may be used to determine the */
/*     optimal value of RBSIZE empirically. */

/*     All data records in a DAF can be treated as an undifferentiated */
/*     collection of double precision numbers.  Summary records must */
/*     be read using the DAFGSR interface, but their contents are */
/*     properly buffered in a single buffer with the data records. */
/*     No special buffers are required for each new data type, or to */
/*     keep summary records separate from data records. */

/* $ Examples */

/*     See entry points DAFGDR, DAFGSR, DAFRDR, DAFWDR, and DAFNRR */
/*     for examples specific to those entry points. */

/* $ Restrictions */

/*     1) An integer overflow may occur if the number of requests */
/*        by a single program exceeds the maximum number that can */
/*        be stored in an integer variable. */

/* $ Literature_References */

/*     NAIF Document 167.0, "Double Precision Array Files (DAF) */
/*     Specification and User's Guide" */

/* $ Author_and_Institution */

/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (FST) */

/*        Added DAFGDR and DAFGSR entry points to allow read access */
/*        to DAFs utilizing non-native, but supported, binary file */
/*        formats. */

/*        DAFRDR was phased into obsolescence. */

/*        The umbrella no longer suffers from integer overflow if */
/*        a sufficient number of successful read requests are made. */

/*        DAFWDR no longer uses DAFHLU to retrieve a logical unit */
/*        for HANDLE.  This call has been replaced with the handle */
/*        manager interface, which does not lock handles to their */
/*        logical units. */

/* -    SPICELIB Version 1.3.0, 24-MAR-2000 (WLT) */

/*        The loop in DAFRDR that moved buffered d.p.s into the output */
/*        array DATA was modified to use the routine MOVED. */

/* -    SPICELIB Version 1.2.0, 01-AUG-1997 (NJB) */

/*        Unnecessary CHKIN and CHKOUT calls were removed from entry */
/*        point DAFRDR. */

/* -    SPICELIB Version 1.1.0, 25-NOV-1992 (JML) */

/*        1) In DAFRDR, the found flag is now set to false if the */
/*           call to DAFHLU fails. */

/*        2) In the example code fragment in DAFRDR and DAFWDR, the */
/*           calling sequence to MOVED was corrected. */

/*        3) In DAFRDR a variable name was changed. */

/*        4) In DAFNRR a cut and paste error in the header was fixed. */

/* -    SPICELIB Version 1.0.2, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     read write d.p. daf */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (FST) */

/*        Updated this umbrella and its entry points in preparation */
/*        for DAF's utilization of the handle manager.  DAFRDR is */
/*        obsolete, and will now signal errors when used to read */
/*        records from DAFs using non-native, binary file formats. */

/*        Two new entry points were added: DAFGDR and DAFGDR.  These */
/*        are the translation-aware 'get data record' and 'get */
/*        summary record' routines that all new software developed */
/*        should utilize. */

/* -    SPICELIB Version 1.3.0, 24-MAR-2000 (WLT) */

/*        The loop in DAFRDR that moved buffered d.p.s into the output */
/*        array DATA was modified to use the routine MOVED. */

/* -    SPICELIB Version 1.2.0, 01-AUG-1997 (NJB) */

/*        Unnecessary CHKIN and CHKOUT calls were removed from entry */
/*        point DAFRDR. */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Saved variables */


/*     Initial values */

    /* Parameter adjustments */
    if (drec) {
	}
    if (data) {
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_dafgdr;
	case 2: goto L_dafgsr;
	case 3: goto L_dafrdr;
	case 4: goto L_dafwdr;
	case 5: goto L_dafnrr;
	}


/*     As double precision records are processed, they are stored in a */
/*     record buffer. (File and character records are not buffered.) */
/*     The user controls the number of records that may be stored at */
/*     any one time by setting the value of the paramater RBSIZE before */
/*     compiling the routine. */

/*     The record buffer contains one entry for each record that has */
/*     been read. */

/*        +----------+----------+----------+----------+ */
/*        | File       Record     Request    Contents | */
/*        | Handle     Number     Number              | */
/*        +----------+----------+----------+----------+ */
/*        | INT        INT        INT        DP(128)  | */
/*        +----------+----------+----------+----------+ */

/*     The request number is a counter that is incremented every time */
/*     a record is requested. When all the slots in the record buffer are */
/*     full, the least recently requested record (the one with the lowest */
/*     request number) is replaced by the new record. */

/*     In addition, a separate counter is used to keep track of the */
/*     number of actual file reads performed. It is possible to tune */
/*     the entire package by checking the read/request ratio for */
/*     any specific buffer configuration. */

/*     Note also that whenever a write operation fails, the affected */
/*     buffers (if any) should NOT be updated. */


/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    } else {
	chkin_("DAFRWD", (ftnlen)6);
	sigerr_("SPICE(BOGUSENTRY)", (ftnlen)17);
	chkout_("DAFRWD", (ftnlen)6);
    }
    return 0;
/* $Procedure DAFGDR ( DAF, get double precision record ) */

L_dafgdr:
/* $ Abstract */

/*     Read a portion of the contents of a double precision record in a */
/*     DAF file. */

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

/*     INTEGER               HANDLE */
/*     INTEGER               RECNO */
/*     INTEGER               BEGIN */
/*     INTEGER               END */
/*     DOUBLE PRECISION      DATA    ( * ) */
/*     LOGICAL               FOUND */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle of DAF. */
/*     RECNO      I   Record number. */
/*     BEGIN      I   First word to read from record. */
/*     END        I   Last word to read from record. */
/*     DATA       O   Contents of record. */
/*     FOUND      O   True if record is found. */

/* $ Detailed_Input */

/*     HANDLE      is the handle associated with a DAF. */

/*     RECNO       is the record number of a particular double precision */
/*                 record within the DAF, whose contents are to be read. */

/*     BEGIN       is the first word in the specified record to be */
/*                 returned. */

/*     END         is the final word in the specified record to be */
/*                 returned. */

/* $ Detailed_Output */

/*     DATA        contains the specified portion (from BEGIN to END, */
/*                 inclusize) of the specified record from the specified */
/*                 file, specifically. */

/*     FOUND       is true when the specified record is found, and is */
/*                 false otherwise. */

/* $ Parameters */

/*      None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     None. */

/* $ Particulars */

/*     DAFGDR checks the record buffer to see if the requested */
/*     record can be returned without actually reading it from */
/*     external storage. If not, it reads the record and stores */
/*     it in the buffer, typically removing another record from */
/*     the buffer as a result. */

/*     Once in the buffer, the specified portion of the record is */
/*     returned, using the following control loop. */

/*        J = 1 */
/*        DO I = MAX( 1, BEGIN ), MIN( 128, END ) */
/*           DATA( J ) = Buffered record ( I ) */
/*           J = J + 1 */
/*        END DO */

/*     Therefore bad values for BEGIN and END (BEGIN < 1, END < BEGIN, */
/*     etc.) are not signaled as errors, but result in the actions */
/*     implied by the above. */

/* $ Examples */

/*     The following code fragment illustrates one way that DAFGDR */
/*     and DAFWDR can be used to update part of a double precision */
/*     record. If the record does not yet exist, we can assume that */
/*     it is filled with zeros. */

/*        CALL DAFGDR ( HANDLE, RECNO, 1, 128, DREC, FOUND ) */

/*        IF ( .NOT. FOUND ) THEN */
/*           CALL MOVED ( 0.D0, 128, DREC ) */
/*        END IF */

/*        DO I = FIRST, LAST */
/*           DREC(I) = NEW_VALUE(I) */
/*        END DO */

/*        CALL DAFWDR ( HANDLE, RECNO, DREC ) */

/*     Note that since only entire records may be written using DAFWDR, */
/*     the entire record needs to be read also. */

/* $ Restrictions */

/*     1) Bad values for BEGIN and END ( BEGIN < 1, END > 128, */
/*        END < BEGIN ) are not signalled as errors. The effects of */
/*        such assignments on the returned data are defined by the */
/*        following control structure: */

/*           J = 1 */
/*           DO I = MAX( 1, BEGIN ), MIN( 128, END ) */
/*              DATA( J ) = Buffered record ( I ) */
/*              J = J + 1 */
/*           END DO */

/* $ Literature_References */

/*     NAIF Document 167.0, "Double Precision Array Files (DAF) */
/*     Specification and User's Guide" */

/* $ Author_and_Institution */

/*     F.S. Turner     (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (FST) */

/* -& */
/* $ Index_Entries */

/*     read daf d.p. record */

/* -& */

/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    }

/*     Assume that the record will be found until proven otherwise. */

    *found = TRUE_;

/*     First, find the record. */

/*     If the specified handle and record number match those of */
/*     a buffered record, determine the location of that record */
/*     within the buffer. */

    bufloc = 0;
    done = FALSE_;
    stored = FALSE_;
    while(! done) {
	++bufloc;
	stored = *handle == __state->rbhan[(i__1 = bufloc - 1) < 100 && 0 <= 
		i__1 ? i__1 : s_rnge("rbhan", i__1, "dafrwd_", (ftnlen)592)] 
		&& *recno == __state->rbrec[(i__2 = bufloc - 1) < 100 && 0 <= 
		i__2 ? i__2 : s_rnge("rbrec", i__2, "dafrwd_", (ftnlen)592)];
	done = stored || bufloc == __state->rbnbr;
    }

/*     If not, determine the location of the least recently requested */
/*     record (the one with the smallest request number). Get the unit */
/*     number for the file, and read the record into this location. */

/*     If an error occurs while reading the record, clear the entire */
/*     buffer entry in case the entry was corrupted by a partial read. */
/*     Otherwise, increment the number of reads performed so far. */

    if (! stored) {
	minai_(__state->rbreq, &__state->rbnbr, &minval, &bufloc);
	zzdafgdr_(handle, recno, &__state->rbdat[(i__1 = (bufloc << 7) - 128) 
		< 12800 && 0 <= i__1 ? i__1 : s_rnge("rbdat", i__1, "dafrwd_",
		 (ftnlen)612)], &locfnd);

/*        If the call to ZZDAFGDR failed, or the record was not found, */
/*        then clean up. */

	if (failed_() || ! locfnd) {
	    *found = FALSE_;
	    __state->rbhan[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : 
		    s_rnge("rbhan", i__1, "dafrwd_", (ftnlen)620)] = 0;
	    __state->rbrec[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : 
		    s_rnge("rbrec", i__1, "dafrwd_", (ftnlen)621)] = 0;
	    __state->rbreq[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : 
		    s_rnge("rbreq", i__1, "dafrwd_", (ftnlen)622)] = 0;
	} else {
	    ++__state->nread;
	    __state->rbhan[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : 
		    s_rnge("rbhan", i__1, "dafrwd_", (ftnlen)625)] = *handle;
	    __state->rbrec[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : 
		    s_rnge("rbrec", i__1, "dafrwd_", (ftnlen)626)] = *recno;
	    if (__state->rbnbr < 100) {
		++__state->rbnbr;
	    }
	}
    }

/*     Whether previously stored or just read, the record is now in */
/*     the buffer. Return the specified portion directly, and increment */
/*     the corresponding request number. */

    if (*found) {
	b = max(1,*begin);
	e = min(128,*end);
	count = e - b + 1;
	moved_(&__state->rbdat[(i__1 = b + (bufloc << 7) - 129) < 12800 && 0 
		<= i__1 ? i__1 : s_rnge("rbdat", i__1, "dafrwd_", (ftnlen)646)
		], &count, data);

/*        Increment the request counter in such a way that integer */
/*        overflow will not occur.  This private module from the */
/*        handle manager halves RBREQ if adding 1 to NREQ would */
/*        cause its value to exceed INTMAX. */

	zzddhrcm_(&__state->rbnbr, __state->rbreq, &__state->nreq);
	__state->rbreq[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"rbreq", i__1, "dafrwd_", (ftnlen)655)] = __state->nreq;
    }
    return 0;
/* $Procedure DAFGSR ( DAF, get summary/descriptor record ) */

L_dafgsr:
/* $ Abstract */

/*     Read a portion of the contents of a summary record in a */
/*     DAF file. */

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

/*     INTEGER               HANDLE */
/*     INTEGER               RECNO */
/*     INTEGER               BEGIN */
/*     INTEGER               END */
/*     DOUBLE PRECISION      DATA    ( * ) */
/*     LOGICAL               FOUND */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle of DAF. */
/*     RECNO      I   Record number. */
/*     BEGIN      I   First word to read from record. */
/*     END        I   Last word to read from record. */
/*     DATA       O   Contents of record. */
/*     FOUND      O   True if record is found. */

/* $ Detailed_Input */

/*     HANDLE      is the handle associated with a DAF. */

/*     RECNO       is the record number of a particular double precision */
/*                 record within the DAF, whose contents are to be read. */

/*     BEGIN       is the first word in the specified record to be */
/*                 returned. */

/*     END         is the final word in the specified record to be */
/*                 returned. */

/* $ Detailed_Output */

/*     DATA        contains the specified portion (from BEGIN to END, */
/*                 inclusize) of the specified record from the specified */
/*                 file, specifically. */

/*     FOUND       is true when the specified record is found, and is */
/*                 false otherwise. */

/* $ Parameters */

/*      None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     None. */

/* $ Particulars */

/*     DAFGSR checks the record buffer to see if the requested */
/*     record can be returned without actually reading it from */
/*     external storage. If not, it reads the record and stores */
/*     it in the buffer, typically removing another record from */
/*     the buffer as a result. */

/*     Once in the buffer, the specified portion of the record is */
/*     returned, using the following control loop. */

/*        J = 1 */
/*        DO I = MAX( 1, BEGIN ), MIN( 128, END ) */
/*           DATA( J ) = Buffered record ( I ) */
/*           J = J + 1 */
/*        END DO */

/*     Therefore bad values for BEGIN and END (BEGIN < 1, END < BEGIN, */
/*     etc.) are not signalled as errors, but result in the actions */
/*     implied by the above. */

/* $ Examples */

/*     The following code fragment illustrates one way that DAFGSR */
/*     and DAFWDR can be used to update part of a summary record. */
/*     If the record does not yet exist, we can assume that it is */
/*     filled with zeros. */

/*        CALL DAFGSR ( HANDLE, RECNO, 1, 128, DREC, FOUND ) */

/*        IF ( .NOT. FOUND ) THEN */
/*           CALL MOVED ( 0.D0, 128, DREC ) */
/*        END IF */

/*        DO I = FIRST, LAST */
/*           DREC(I) = NEW_VALUE(I) */
/*        END DO */

/*        CALL DAFWDR ( HANDLE, RECNO, DREC ) */

/*     Note that since only entire records may be written using DAFWDR, */
/*     the entire record needs to be read also. */

/* $ Restrictions */

/*     1) Bad values for BEGIN and END ( BEGIN < 1, END > 128, */
/*        END < BEGIN ) are not signalled as errors. The effects of */
/*        such assignments on the returned data are defined by the */
/*        following control structure: */

/*           J = 1 */
/*           DO I = MAX( 1, BEGIN ), MIN( 128, END ) */
/*              DATA( J ) = Buffered record ( I ) */
/*              J = J + 1 */
/*           END DO */

/* $ Literature_References */

/*     NAIF Document 167.0, "Double Precision Array Files (DAF) */
/*     Specification and User's Guide" */

/* $ Author_and_Institution */

/*     F.S. Turner     (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (FST) */

/* -& */
/* $ Index_Entries */

/*     read daf summary record */

/* -& */

/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    }

/*     Assume that the record will be found until proven otherwise. */

    *found = TRUE_;

/*     First, find the record. */

/*     If the specified handle and record number match those of */
/*     a buffered record, determine the location of that record */
/*     within the buffer. */

    bufloc = 0;
    done = FALSE_;
    stored = FALSE_;
    while(! done) {
	++bufloc;
	stored = *handle == __state->rbhan[(i__1 = bufloc - 1) < 100 && 0 <= 
		i__1 ? i__1 : s_rnge("rbhan", i__1, "dafrwd_", (ftnlen)862)] 
		&& *recno == __state->rbrec[(i__2 = bufloc - 1) < 100 && 0 <= 
		i__2 ? i__2 : s_rnge("rbrec", i__2, "dafrwd_", (ftnlen)862)];
	done = stored || bufloc == __state->rbnbr;
    }

/*     If not, determine the location of the least recently requested */
/*     record (the one with the smallest request number). Get the unit */
/*     number for the file, and read the record into this location. */

/*     If an error occurs while reading the record, clear the entire */
/*     buffer entry in case the entry was corrupted by a partial read. */
/*     Otherwise, increment the number of reads performed so far. */

    if (! stored) {
	minai_(__state->rbreq, &__state->rbnbr, &minval, &bufloc);
	dafhsf_(handle, &nd, &ni);
	zzdafgsr_(handle, recno, &nd, &ni, &__state->rbdat[(i__1 = (bufloc << 
		7) - 128) < 12800 && 0 <= i__1 ? i__1 : s_rnge("rbdat", i__1, 
		"dafrwd_", (ftnlen)884)], &locfnd);

/*        If the call to ZZDAFGSR or DAFHSF failed, or the record */
/*        was not found, then clean up. */

	if (failed_() || ! locfnd) {
	    *found = FALSE_;
	    __state->rbhan[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : 
		    s_rnge("rbhan", i__1, "dafrwd_", (ftnlen)893)] = 0;
	    __state->rbrec[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : 
		    s_rnge("rbrec", i__1, "dafrwd_", (ftnlen)894)] = 0;
	    __state->rbreq[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : 
		    s_rnge("rbreq", i__1, "dafrwd_", (ftnlen)895)] = 0;
	} else {
	    ++__state->nread;
	    __state->rbhan[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : 
		    s_rnge("rbhan", i__1, "dafrwd_", (ftnlen)898)] = *handle;
	    __state->rbrec[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : 
		    s_rnge("rbrec", i__1, "dafrwd_", (ftnlen)899)] = *recno;
	    if (__state->rbnbr < 100) {
		++__state->rbnbr;
	    }
	}
    }

/*     Whether previously stored or just read, the record is now in */
/*     the buffer. Return the specified portion directly, and increment */
/*     the corresponding request number. */

    if (*found) {
	b = max(1,*begin);
	e = min(128,*end);
	count = e - b + 1;
	moved_(&__state->rbdat[(i__1 = b + (bufloc << 7) - 129) < 12800 && 0 
		<= i__1 ? i__1 : s_rnge("rbdat", i__1, "dafrwd_", (ftnlen)919)
		], &count, data);

/*        Increment the request counter in such a way that integer */
/*        overflow will not occur.  This private module from the */
/*        handle manager halves RBREQ if adding 1 to NREQ would */
/*        cause its value to exceed INTMAX. */

	zzddhrcm_(&__state->rbnbr, __state->rbreq, &__state->nreq);
	__state->rbreq[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"rbreq", i__1, "dafrwd_", (ftnlen)928)] = __state->nreq;
    }
    return 0;
/* $Procedure DAFRDR ( DAF, read double precision record ) */

L_dafrdr:
/* $ Abstract */

/*     Read a portion of the contents of a double precision record in a */
/*     DAF file. */
/*     Obsolete: This routine has been superceded by DAFGDR, and it is */
/*     supported for purposes of backwards compatibility only. */

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

/*     INTEGER               HANDLE */
/*     INTEGER               RECNO */
/*     INTEGER               BEGIN */
/*     INTEGER               END */
/*     DOUBLE PRECISION      DATA    ( * ) */
/*     LOGICAL               FOUND */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle of DAF. */
/*     RECNO      I   Record number. */
/*     BEGIN      I   First word to read from record. */
/*     END        I   Last word to read from record. */
/*     DATA       O   Contents of record. */
/*     FOUND      O   True if record is found. */

/* $ Detailed_Input */

/*     HANDLE      is the handle associated with a DAF. */

/*     RECNO       is the record number of a particular double precision */
/*                 record within the DAF, whose contents are to be read. */

/*     BEGIN       is the first word in the specified record to be */
/*                 returned. */

/*     END         is the final word in the specified record to be */
/*                 returned. */

/* $ Detailed_Output */

/*     DATA        contains the specified portion (from BEGIN to END, */
/*                 inclusize) of the specified record from the specified */
/*                 file, specifically. */

/*     FOUND       is true when the specified record is found, and is */
/*                 false otherwise. */

/* $ Parameters */

/*      None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     1) If the file associated with HANDLE is not of the native */
/*        binary file format, this routine signals the error */
/*        SPICE(UNSUPPORTEDBFF). */

/* $ Particulars */

/*     DAFRDR checks the record buffer to see if the requested */
/*     record can be returned without actually reading it from */
/*     external storage. If not, it reads the record and stores */
/*     it in the buffer, typically removing another record from */
/*     the buffer as a result. */

/*     Once in the buffer, the specified portion of the record is */
/*     returned, using the following control loop. */

/*        J = 1 */
/*        DO I = MAX( 1, BEGIN ), MIN( 128, END ) */
/*           DATA( J ) = Buffered record ( I ) */
/*           J = J + 1 */
/*        END DO */

/*     Therefore bad values for BEGIN and END (BEGIN < 1, END < BEGIN, */
/*     etc.) are not signalled as errors, but result in the actions */
/*     implied by the above. */

/*     This routine has been made obsolete by the routine DAFGDR, */
/*     and it is supported for reasons of backwards compatibility */
/*     only.  New software development should utilize DAFGDA. */

/* $ Examples */

/*     The following code fragment illustrates one way that DAFRDR */
/*     and DAFWDR can be used to update part of a double precision */
/*     record. If the record does not yet exist, we can assume that */
/*     it is filled with zeros. */

/*        CALL DAFRDR ( HANDLE, RECNO, 1, 128, DREC, FOUND ) */

/*        IF ( .NOT. FOUND ) THEN */
/*           CALL MOVED ( 0.D0, 128, DREC ) */
/*        END IF */

/*        DO I = FIRST, LAST */
/*           DREC(I) = NEW_VALUE(I) */
/*        END DO */

/*        CALL DAFWDR ( HANDLE, RECNO, DREC ) */

/*     Note that since only entire records may be written using DAFWDR, */
/*     the entire record needs to be read also. */

/* $ Restrictions */

/*     1) An integer overflow may occur if the number of requests */
/*        by a single program exceeds the maximum number that can */
/*        be stored in an integer variable. */

/*     2) Bad values for BEGIN and END ( BEGIN < 1, END > 128, */
/*        END < BEGIN ) are not signalled as errors. The effects of */
/*        such assignments on the returned data are defined by the */
/*        following control structure: */

/*           J = 1 */
/*           DO I = MAX( 1, BEGIN ), MIN( 128, END ) */
/*              DATA( J ) = Buffered record ( I ) */
/*              J = J + 1 */
/*           END DO */

/* $ Literature_References */

/*     NAIF Document 167.0, "Double Precision Array Files (DAF) */
/*     Specification and User's Guide" */

/* $ Author_and_Institution */

/*     R.E. Thurman    (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (FST) */

/*        Added SPICE(UNSUPPORTEDBFF) exception to the routine. */

/* -    SPICELIB Version 1.3.0, 24-MAR-2000 (WLT) */

/*        The loop in DAFRDR that moved buffered d.p.s into the output */
/*        array DATA was modified to use the routine MOVED. */

/* -    SPICELIB Version 1.2.0, 01-AUG-1997 (NJB) */

/*        Unnecessary CHKIN and CHKOUT calls were removed from entry */
/*        point DAFRDR. */

/* -    SPICELIB Version 1.1.0, 25-NOV-1992 (JML) */

/*        1) In DAFRDR, the found flag is now set to false if the */
/*           call to DAFHLU fails. */

/*        2) In the example code fragment in DAFRDR and DAFWDR, the */
/*           calling sequence to MOVED was corrected. */

/*        3) In the call to MINAI the argument for the minimum value */
/*           was changed from I to MINVAL. */

/* -    SPICELIB Version 1.0.2, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     read daf d.p. record */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (FST) */

/*        The exception SPICE(UNSUPPORTEDBFF) was added to guarantee */
/*        this routine's functionality remains unchanged as a result */
/*        of the updates to the underlying DAF software's utilization of */
/*        the handle manager.  In versions of the toolkit prior to this, */
/*        all DAFs loaded were of the native binary file format. */
/*        Previously, this routine was used to read the contents of */
/*        summary records in addition to the usual data records. */
/*        The non-native to native translation process for these two */
/*        different types of records in general are not the same. */
/*        Rather than attempt to interpret the caller's intent, this */
/*        routine is obsolete and restricted to functioning only on */
/*        DAFs of the native binary file format. */

/* -    SPICELIB Version 1.3.0, 24-MAR-2000 (WLT) */

/*        The loop in DAFRDR that moved buffered d.p.s into the output */
/*        array DATA was modified to use the routine MOVED. */

/* -    SPICELIB Version 1.2.0, 01-AUG-1997 (NJB) */

/*        Unnecessary CHKIN and CHKOUT calls were removed from entry */
/*        point DAFRDR.  These calls were placed together prior to */
/*        a RETURN statement.  It's unclear why they were there in the */
/*        first place. */

/* -    SPICELIB Version 1.1.0, 25-NOV-1992 (JML) */

/*        1) In DAFRDR, the found flag is now set to false if the */
/*           call to DAFHLU fails. */

/*        2) In the example code fragment in DAFRDR and DAFWDR, the */
/*           calling sequence to MOVED was corrected. */

/*        3) In the call to MINAI the argument for the minimum value */
/*           was changed from I to MINVAL. */

/* -     Beta Version 2.0.0, 1-NOV-1989 (RET) */

/*        The function of DAFRDR was changed so that it returns only */
/*        a specified portion of the record. The calling sequence there- */
/*        fore changed from */

/*           DAFRDR ( HANDLE, RECNO, DREC, FOUND ) to */
/*           DAFRDR ( HANDLE, RECNO, BEGIN, END, DATA, FOUND ) */

/*        The change was made to cut down on the shuffling of unneeded */
/*        data. */

/*        Also, DAFRDR now only checks in and checks out if DAFHLU has */
/*        failed (the only routine called by DAFRDR that could possibly */
/*        signal an error). The purpose of this change was to help */
/*        speed up a routine that gets called constantly by higher level */
/*        DAF routines. */

/* -& */

/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    }

/*     Assume that the record will be found until proven otherwise. */

    *found = TRUE_;

/*     First check to see if HANDLE is associated with a DAF of the */
/*     native binary file format. */

    zzddhisn_(handle, &native, &locfnd);
    if (locfnd && ! native) {
	*found = FALSE_;
	chkin_("DAFRDR", (ftnlen)6);
	setmsg_("The binary file format for file '#' is not native. This rou"
		"tine operates only on files of the native format.", (ftnlen)
		108);
	errhan_("#", handle, (ftnlen)1);
	sigerr_("SPICE(UNSUPPORTEDBFF)", (ftnlen)21);
	chkout_("DAFRDR", (ftnlen)6);
	return 0;
    }

/*     Now, find the record. */

/*     If the specified handle and record number match those of */
/*     a buffered record, determine the location of that record */
/*     within the buffer. */

    bufloc = 0;
    done = FALSE_;
    stored = FALSE_;
    while(! done) {
	++bufloc;
	stored = *handle == __state->rbhan[(i__1 = bufloc - 1) < 100 && 0 <= 
		i__1 ? i__1 : s_rnge("rbhan", i__1, "dafrwd_", (ftnlen)1264)] 
		&& *recno == __state->rbrec[(i__2 = bufloc - 1) < 100 && 0 <= 
		i__2 ? i__2 : s_rnge("rbrec", i__2, "dafrwd_", (ftnlen)1264)];
	done = stored || bufloc == __state->rbnbr;
    }

/*     If not, determine the location of the least recently requested */
/*     record (the one with the smallest request number). Get the unit */
/*     number for the file, and read the record into this location. */

/*     If an error occurs while reading the record, clear the entire */
/*     buffer entry in case the entry was corrupted by a partial read. */
/*     Otherwise, increment the number of reads performed so far. */

    if (! stored) {
	minai_(__state->rbreq, &__state->rbnbr, &minval, &bufloc);
	zzdafgdr_(handle, recno, &__state->rbdat[(i__1 = (bufloc << 7) - 128) 
		< 12800 && 0 <= i__1 ? i__1 : s_rnge("rbdat", i__1, "dafrwd_",
		 (ftnlen)1284)], &locfnd);

/*        If the call to ZZDAFGDR failed, or the record was not found, */
/*        then clean up. */

	if (failed_() || ! locfnd) {
	    *found = FALSE_;
	    __state->rbhan[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : 
		    s_rnge("rbhan", i__1, "dafrwd_", (ftnlen)1292)] = 0;
	    __state->rbrec[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : 
		    s_rnge("rbrec", i__1, "dafrwd_", (ftnlen)1293)] = 0;
	    __state->rbreq[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : 
		    s_rnge("rbreq", i__1, "dafrwd_", (ftnlen)1294)] = 0;
	} else {
	    ++__state->nread;
	    __state->rbhan[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : 
		    s_rnge("rbhan", i__1, "dafrwd_", (ftnlen)1297)] = *handle;
	    __state->rbrec[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : 
		    s_rnge("rbrec", i__1, "dafrwd_", (ftnlen)1298)] = *recno;
	    if (__state->rbnbr < 100) {
		++__state->rbnbr;
	    }
	}
    }

/*     Whether previously stored or just read, the record is now in */
/*     the buffer. Return the specified portion directly, and increment */
/*     the corresponding request number. */

    if (*found) {
	b = max(1,*begin);
	e = min(128,*end);
	count = e - b + 1;
	moved_(&__state->rbdat[(i__1 = b + (bufloc << 7) - 129) < 12800 && 0 
		<= i__1 ? i__1 : s_rnge("rbdat", i__1, "dafrwd_", (ftnlen)
		1318)], &count, data);

/*        Increment the request counter in such a way that integer */
/*        overflow will not occur.  This private module from the */
/*        handle manager halves RBREQ if adding 1 to NREQ would */
/*        cause its value to exceed INTMAX. */

	zzddhrcm_(&__state->rbnbr, __state->rbreq, &__state->nreq);
	__state->rbreq[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"rbreq", i__1, "dafrwd_", (ftnlen)1327)] = __state->nreq;
    }
    return 0;
/* $Procedure DAFWDR ( DAF, write double precision record ) */

L_dafwdr:
/* $ Abstract */

/*     Write or rewrite the contents of a double precision record in */
/*     a DAF. */

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

/*     INTEGER               HANDLE */
/*     INTEGER               RECNO */
/*     DOUBLE PRECISION      DREC     ( 128 ) */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle of DAF. */
/*     RECNO      I   Record number. */
/*     DREC       I   Contents of record. */

/* $ Detailed_Input */

/*     HANDLE      is the handle associated with a DAF. */

/*     RECNO       is the record number of a particular double */
/*                 precision record within the file, whose */
/*                 contents are to be written (if the record does */
/*                 not yet exist) or overwritten (if it does). */

/*     DREC        contains the new contents of the record. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*      None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     1) If the file is not open for write access, the error */
/*        SPICE(DAFILLEGWRITE) is signalled. */

/*     2) If (for some reason) the record cannot be written the */
/*        error SPICE(DAFDPWRITEFAIL) is signalled. */

/* $ Particulars */

/*     Like DAFRDR, DAFWDR checks the record buffer to see if the */
/*     requested record is in the buffer. If so, the buffer is */
/*     updated along with the file. This prevents the buffer from */
/*     becoming outdated. */

/* $ Examples */

/*     The following code fragment illustrates one way that DAFRDR */
/*     and DAFWDR can be used to update part of a double precision */
/*     record. If the record does not yet exist, we can assume that */
/*     it is filled with zeros. */

/*        CALL DAFRDR ( HANDLE, RECNO, DREC, FOUND ) */

/*        IF ( .NOT. FOUND ) THEN */
/*           CALL MOVED ( 0.D0, 128, DREC ) */
/*        END IF */

/*        DO I = FIRST, LAST */
/*           DREC(I) = NEW_VALUE(I) */
/*        END DO */

/*        CALL DAFWDR ( HANDLE, RECNO, DREC ) */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     NAIF Document 167.0, "Double Precision Array Files (DAF) */
/*     Specification and User's Guide" */

/* $ Author_and_Institution */

/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (FST) */

/*        Replaced the call to DAFHLU to ZZDDHHLU.  This prevents */
/*        DAFWDR from tying up resources in the handle manager. */

/* -    SPICELIB Version 1.3.0, 24-MAR-2000 (WLT) */

/*        The loop in DAFRDR that moved buffered d.p.s into the output */
/*        array DATA was modified to use the routine MOVED. */

/* -    SPICELIB Version 1.1.0, 25-NOV-1992 (JML) */

/*        In the example code fragment in DAFRDR and DAFWDR, the */
/*        calling sequence to MOVED was corrected. */

/* -    SPICELIB Version 1.0.2, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     write daf d.p. record */

/* -& */

/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    } else {
	chkin_("DAFWDR", (ftnlen)6);
    }

/*     No fair writing to a read-only file! */

    if (*handle >= 0) {
	setmsg_("Attempt was made to write to a read-only file.", (ftnlen)46);
	sigerr_("SPICE(DAFILLEGWRITE)", (ftnlen)20);
	chkout_("DAFWDR", (ftnlen)6);
	return 0;
    }

/*     If the specified handle and record number match those of */
/*     a buffered record, determine the location of that record */
/*     within the buffer. */

    bufloc = 0;
    done = FALSE_;
    stored = FALSE_;
    while(! done) {
	++bufloc;
	stored = *handle == __state->rbhan[(i__1 = bufloc - 1) < 100 && 0 <= 
		i__1 ? i__1 : s_rnge("rbhan", i__1, "dafrwd_", (ftnlen)1532)] 
		&& *recno == __state->rbrec[(i__2 = bufloc - 1) < 100 && 0 <= 
		i__2 ? i__2 : s_rnge("rbrec", i__2, "dafrwd_", (ftnlen)1532)];
	done = stored || bufloc == 100;
    }

/*     Get the unit number for the file, and write the record. */

    zzddhhlu_(handle, "DAF", &__state->c_false, &unit, (ftnlen)3);
    __state->io___21.ciunit = unit;
    __state->io___21.cirec = *recno;
    iostat = s_wdue(&__state->io___21);
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__state->c__128, (char *)&drec[0], (ftnlen)sizeof(
	    doublereal));
    if (iostat != 0) {
	goto L100001;
    }
    iostat = e_wdue();
L100001:

/*     If the record was buffered, replace it---with the input */
/*     record if the write was successful, or with zeros if it */
/*     was not. */

    if (stored) {
	if (iostat == 0) {
	    moved_(drec, &__state->c__128, &__state->rbdat[(i__1 = (bufloc << 
		    7) - 128) < 12800 && 0 <= i__1 ? i__1 : s_rnge("rbdat", 
		    i__1, "dafrwd_", (ftnlen)1555)]);
	} else {
	    __state->rbhan[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : 
		    s_rnge("rbhan", i__1, "dafrwd_", (ftnlen)1557)] = 0;
	    __state->rbrec[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : 
		    s_rnge("rbrec", i__1, "dafrwd_", (ftnlen)1558)] = 0;
	    __state->rbreq[(i__1 = bufloc - 1) < 100 && 0 <= i__1 ? i__1 : 
		    s_rnge("rbreq", i__1, "dafrwd_", (ftnlen)1559)] = 0;
	}
    }

/*     Declare an error if the write failed. */

    if (iostat != 0) {
	setmsg_("Double precision write failed. Value of IOSTAT was #", (
		ftnlen)52);
	errint_("#", &iostat, (ftnlen)1);
	sigerr_("SPICE(DAFDPWRITEFAIL)", (ftnlen)21);
    }
    chkout_("DAFWDR", (ftnlen)6);
    return 0;
/* $Procedure DAFNRR ( DAF number of reads, requests ) */

L_dafnrr:
/* $ Abstract */

/*     Return the number of reads and requests fielded by DAFRDR. */

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

/*     INTEGER               READS */
/*     INTEGER               REQS */

/* $ Brief_I/O */

/*     Variable  I/O  Entry */
/*     --------  ---  -------------------------------------------------- */
/*     READS, */
/*     REQS       O   Reads, requests in this execution. */

/* $ Detailed_Input */

/*     None. */

/* $ Detailed_Output */

/*     READS, */
/*     REQS        are the number of physical reads and the number */
/*                 of requests processed by DAFRDR during the current */
/*                 execution of the calling program. */

/* $ Parameters */

/*      None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/* $ Particulars */

/*     The ratio of reads to requests tells you something about */
/*     the effectiveness with which the record buffer is preventing */
/*     unwanted disk access. In the ideal case, most of the records */
/*     needed by the calling program can be returned directly from */
/*     the buffer, and the ratio of reads to requests approaches zero. */
/*     More realistically, it should be be somewhere between 1/10 */
/*     and 1/2. */

/*     If the ratio is greater than 1/2, you should consider increasing */
/*     the size of the record buffer (which is controlled by parameter */
/*     RBSIZE) in order to improve the performance of the DAF package, */
/*     unless your application is strapped for space. */

/* $ Examples */

/*     In the following code fragment, the ratio of reads to requests */
/*     is determined following a series of calls to the reader DAFEZ. */

/*        DO I = 1, N */
/*           CALL DAFEZ ( ..., STATES(1,I), ... ) */
/*        END DO */

/*        CALL DAFNRR ( READS, REQS ) */

/*        WRITE (*,*) 'Reads/requests = ', FLOAT( READS ) / FLOAT( REQS ) */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     NAIF Document 167.0, "Double Precision Array Files (DAF) */
/*     Specification and User's Guide" */

/* $ Author_and_Institution */

/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.3.0, 24-MAR-2000 (WLT) */

/*        The loop in DAFRDR that moved buffered d.p.s into the output */
/*        array DATA was modified to use the routine MOVED. */

/* -    SPICELIB Version 1.1.0, 25-NOV-1992 (JML) */

/*        A cut and paste error in the literature references */
/*        section of the header was fixed. */

/* -    SPICELIB Version 1.0.2, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     number of daf read requests */

/* -& */
    *reads = __state->nread;
    *reqs = __state->nreq;
    return 0;
} /* dafrwd_ */

/* Subroutine */ int dafrwd_(integer *handle, integer *recno, integer *begin, 
	integer *end, doublereal *drec, doublereal *data, logical *found, 
	integer *reads, integer *reqs)
{
    return dafrwd_0_(0, handle, recno, begin, end, drec, data, found, reads, 
	    reqs);
    }

/* Subroutine */ int dafgdr_(integer *handle, integer *recno, integer *begin, 
	integer *end, doublereal *data, logical *found)
{
    return dafrwd_0_(1, handle, recno, begin, end, (doublereal *)0, data, 
	    found, (integer *)0, (integer *)0);
    }

/* Subroutine */ int dafgsr_(integer *handle, integer *recno, integer *begin, 
	integer *end, doublereal *data, logical *found)
{
    return dafrwd_0_(2, handle, recno, begin, end, (doublereal *)0, data, 
	    found, (integer *)0, (integer *)0);
    }

/* Subroutine */ int dafrdr_(integer *handle, integer *recno, integer *begin, 
	integer *end, doublereal *data, logical *found)
{
    return dafrwd_0_(3, handle, recno, begin, end, (doublereal *)0, data, 
	    found, (integer *)0, (integer *)0);
    }

/* Subroutine */ int dafwdr_(integer *handle, integer *recno, doublereal *
	drec)
{
    return dafrwd_0_(4, handle, recno, (integer *)0, (integer *)0, drec, (
	    doublereal *)0, (logical *)0, (integer *)0, (integer *)0);
    }

/* Subroutine */ int dafnrr_(integer *reads, integer *reqs)
{
    return dafrwd_0_(5, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (doublereal *)0, (doublereal *)0, (logical *)0, reads, reqs);
    }

