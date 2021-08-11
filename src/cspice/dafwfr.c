/* dafwfr.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern dafwfr_init_t __dafwfr_init;
static dafwfr_state_t* get_dafwfr_state() {
	cspice_t* state =  __cspice_get_state();
	if (!state->dafwfr)
		state->dafwfr = __cspice_allocate_module(sizeof(
	dafwfr_state_t), &__dafwfr_init, sizeof(__dafwfr_init));
	return state->dafwfr;

}

/* $Procedure DAFWFR ( DAF write file record ) */
/* Subroutine */ int dafwfr_(integer *handle, integer *nd, integer *ni, char *
	ifname, integer *fward, integer *bward, integer *free, ftnlen 
	ifname_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rdue(cilist *), do_uio(integer *, char *, ftnlen), e_rdue(void),
	     s_wdue(cilist *), e_wdue(void);

    /* Local variables */
    char tail[928];
    integer unit;
    extern /* Subroutine */ int zzddhhlu_(integer *, char *, logical *, 
	    integer *, ftnlen);
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    integer locnd;
    integer locni;
    extern logical failed_(void);
    integer locffa;
    extern /* Subroutine */ int dafsih_(integer *, char *, ftnlen);
    char locifn[60];
    integer locfdr;
    integer locldr;
    char format[8];
    char idword[8];
    extern /* Subroutine */ int errfnm_(char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(char *, ftnlen);
    extern /* Subroutine */ int chkout_(char *, ftnlen);
    extern /* Subroutine */ int setmsg_(char *, ftnlen);
    integer iostat;
    extern /* Subroutine */ int errint_(char *, integer *, ftnlen);
    extern logical return_(void);
    char ifn[60];

    /* Fortran I/O blocks */



    /* Module state */
    dafwfr_state_t* __state = get_dafwfr_state();
/* $ Abstract */

/*     Write or rewrite the contents of the file record of a DAF. */

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
/*     HANDLE     I   Handle of an open DAF file. */
/*     ND         I   Number of double precision components in summaries. */
/*     ND         I   Number of integer components in summaries. */
/*     IFNAME     I   Internal filename. */
/*     FWARD      I   Forward list pointer. */
/*     BWARD      I   Backward list pointer. */
/*     FREE       I   Free address pointer. */

/* $ Detailed_Input */

/*     HANDLE      is the handle associated with a DAF file opened for */
/*                 writing. */

/*     ND, */
/*     NI          are the numbers of double precision and integer */
/*                 components, respectively, in each array summary */
/*                 in the specified file. */

/*     IFNAME      is the internal file name to be stored in the first */
/*                 (or file) record of the specified file. */

/*     FWARD       is the forward list pointer. This points to the */
/*                 first summary record in the file. */

/*     BWARD       is the backward list pointer. This points to the */
/*                 final summary record in the file. */

/*     FREE        is the free address pointer. This contains the */
/*                 first free address in the file. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     1) If the handle passed to this routine is not the handle of an */
/*        open DAF file, the error will be signaled by a routine called */
/*        by this routine. */

/*     2) If the specified DAF file is not open for write access, the */
/*        error will be diagnosed by a routine called by this routine. */

/*     3) If the file record cannot (for some reason) be written, */
/*        the error SPICE(DAFWRITEFAIL) is signaled. */

/*     4) If the attempt to read the file record fails, the error */
/*        SPICE(DAFREADFAIL) will be signaled. */

/* $ Particulars */

/*     The file record of a DAF is the only record that contains */
/*     any global information about the file. This record is created */
/*     when the file is created, and is updated only when new arrays */
/*     are added. */

/*        DO NOT CHANGE THE CONTENTS OF THE FILE RECORD UNLESS */
/*        YOU ARE ABSOLUTELY SURE YOU KNOW WHAT YOU ARE DOING. */

/*     Like character records, file records are not buffered. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     NAIF Document 167.0, "Double Precision Array Files (DAF) */
/*     Specification and User's Guide" */

/* $ Author_and_Institution */

/*     K.R. Gehringer  (JPL) */
/*     F.S. Turner     (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 4.0.0, 27-NOV-2001 (FST) */

/*        Updated this routine to utilize new handle manager */
/*        interfaces.  Comments were expanded and clarified. */

/* -    SPICELIB Version 3.0.0, 21-MAR-1999 (FST) */

/*        This routine was modified to accomodate the preservation */
/*        of the FTP validation and binary file format strings that */
/*        are now part of the DAF file record. */

/* -    SPICELIB Version 2.0.0, 05-OCT-1993 (KRG) */

/*        The error SPICE(DAFNOIDWORD) is no longer signalled by this */
/*        routine. The reason for this is that if DAFSIH returns OK then */
/*        the handle passed to this routine is indeed a valid DAF file */
/*        handle, otherwise the error is diagnosed by DAFSIH. */

/*        Added two new exceptions to the $ Exceptions section: 1 and 4. */
/*        The remaining exceptions (2 and 3) were already present. The */
/*        exceptions that were added are not new, but are being */
/*        documented for the first time. */

/* -    SPICELIB Version 1.0.2, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     write daf file record */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 4.0.0, 27-NOV-2001 (FST) */

/*        The call to DAFHLU has been replaced with a call to */
/*        ZZDDHHLU, the handle manager interface for retrieving */
/*        a logical unit.  DAFHLU is no longer used, since it */
/*        locks the unit returned to its HANDLE, tying up resources */
/*        in the handle manager. */

/* -    SPICELIB Version 3.0.0, 21-MAR-1999 (FST) */

/*        In order to preserve the additional information that */
/*        now resides in the file record, this routine reads */
/*        the entire record into local buffers, including the */
/*        TAILEN characters that follow the actual data content. */
/*        The contents of the local buffers that correspond to */
/*        information brought in from the call sequence of the */
/*        routine are ignored when the record is rewritten. */
/*        However, the ID word, the file format string, and the */
/*        trailing TAILEN characters that contain the FTP validation */
/*        string are rewritten along with the input values. */

/*        This routine does not simply replace the FTP validation */
/*        string with the components from ZZFTPSTR, since that */
/*        would possibly validate a corrupt file created using a newer */
/*        Toolkit. */

/* -    SPICELIB Version 2.0.0, 05-OCT-1993 (KRG) */

/*        The error SPICE(DAFNOIDWORD) is no longer signalled by this */
/*        routine. The reason for this is that if DAFSIH returns OK then */
/*        the handle passed to this routine is indeed a valid DAF file */
/*        handle, otherwise the error is diagnosed by DAFSIH. */

/*        Added a call to DAFSIH to signal an invalid handle and a test */
/*        of FAILED () after it. This is to make sure that the DAF file */
/*        is open for writing. If this call succeeds, we know that we */
/*        have a valid DAF handle, so there is no need to check FAILED */
/*        after the call to DAFHLU. */

/*        Added code to read the file ID word so that it could be */
/*        preserved when the file record is written. This supports the ID */
/*        word format that contains type information. */

/*        Added variable IDWORD to the routine, as well as the parameters */
/*        IDWLEN and IFNLEN. */

/*        Added two new exceptions to the $ Exceptions section: 1 and 4. */
/*        The remaining exceptions (2 and 3) were already present. The */
/*        exceptions that were added are not new, but are being */
/*        documented for the first time. */

/*        Removed code that tested the sign of HANDLE to see if the file */
/*        was open for write access, HANDLE < 0. This test was no longer */
/*        necessary, as the call to DASSIH performs this test as well. No */
/*        sense doing it twice. */

/* -    SPICELIB Version 1.0.2, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */

/*     SPICELIB functions */


/*     Local Parameters */


/*     The parameter TAILEN determines the tail length of a DAF file */
/*     record.  This is the number of bytes (characters) that */
/*     occupy the portion of the file record that follows the */
/*     integer holding the first free address.  For environments */
/*     with a 32 bit word length, 1 byte characters, and DAF */
/*     record sizes of 1024 bytes, we have: */

/*           8 bytes - IDWORD */
/*           4 bytes - ND     (32 bit integer) */
/*           4 bytes - NI     (32 bit integer) */
/*          60 bytes - IFNAME */
/*           4 bytes - FWARD  (32 bit integer) */
/*           4 bytes - BWARD  (32 bit integer) */
/*         + 4 bytes - FREE   (32 bit integer) */
/*          --------- */
/*          88 bytes - (All file records utilize this space.) */

/*     So the size of the remaining portion (or tail) of the DAF */
/*     file record for computing enviroments as described above */
/*     would be: */

/*        1024 bytes - DAF record size */
/*      -    8 bytes - DAF Binary File Format Word */
/*      -   88 bytes - (from above) */
/*       ------------ */
/*         928 bytes - DAF file record tail length */

/*     Note: environments that do not have a 32 bit word length, */
/*     1 byte characters, and a DAF record size of 1024 bytes, will */
/*     require the adjustment of this parameter. */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    } else {
	chkin_("DAFWFR", (ftnlen)6);
    }

/*     Do some initializations */

    s_copy(idword, " ", (ftnlen)8, (ftnlen)1);

/*     Check to be sure that HANDLE is attached to a file that is open */
/*     with write access. If the call fails, check out and return. */

    dafsih_(handle, "WRITE", (ftnlen)5);
    if (failed_()) {
	chkout_("DAFWFR", (ftnlen)6);
	return 0;
    }

/*     Get the logical unit for the file, as we know we have a valid DAF */
/*     handle with the correct access method. */

    zzddhhlu_(handle, "DAF", &__state->c_false, &unit, (ftnlen)3);
    if (failed_()) {
	chkout_("DAFWFR", (ftnlen)6);
	return 0;
    }

/*     In order to maintain the integrity of the file ID word, the */
/*     file FORMAT, and the FTP string if present, we need to */
/*     read the entire file record into the appropriate sized local */
/*     buffers. The values of the LOCxxx variables are simply */
/*     ignored, since the caller passes new values in for updates. */

    __state->io___4.ciunit = unit;
    iostat = s_rdue(&__state->io___4);
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__state->c__1, idword, (ftnlen)8);
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__state->c__1, (char *)&locnd, (ftnlen)sizeof(integer));
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__state->c__1, (char *)&locni, (ftnlen)sizeof(integer));
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__state->c__1, locifn, (ftnlen)60);
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__state->c__1, (char *)&locfdr, (ftnlen)sizeof(integer));
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__state->c__1, (char *)&locldr, (ftnlen)sizeof(integer));
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__state->c__1, (char *)&locffa, (ftnlen)sizeof(integer));
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__state->c__1, format, (ftnlen)8);
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__state->c__1, tail, (ftnlen)928);
    if (iostat != 0) {
	goto L100001;
    }
    iostat = e_rdue();
L100001:
    if (iostat != 0) {
	setmsg_("Attempt to read the file record failed for file '#'. IOSTAT"
		" = #", (ftnlen)63);
	errfnm_("#", &unit, (ftnlen)1);
	errint_("#", &iostat, (ftnlen)1);
	sigerr_("SPICE(DAFREADFAIL)", (ftnlen)18);
	chkout_("DAFWFR", (ftnlen)6);
	return 0;
    }

/*     Set the value of the internal filename before writing. This is to */
/*     guarantee that its length is ok. */

    s_copy(ifn, ifname, (ftnlen)60, ifname_len);
    __state->io___14.ciunit = unit;
    iostat = s_wdue(&__state->io___14);
    if (iostat != 0) {
	goto L100002;
    }
    iostat = do_uio(&__state->c__1, idword, (ftnlen)8);
    if (iostat != 0) {
	goto L100002;
    }
    iostat = do_uio(&__state->c__1, (char *)&(*nd), (ftnlen)sizeof(integer));
    if (iostat != 0) {
	goto L100002;
    }
    iostat = do_uio(&__state->c__1, (char *)&(*ni), (ftnlen)sizeof(integer));
    if (iostat != 0) {
	goto L100002;
    }
    iostat = do_uio(&__state->c__1, ifn, (ftnlen)60);
    if (iostat != 0) {
	goto L100002;
    }
    iostat = do_uio(&__state->c__1, (char *)&(*fward), (ftnlen)sizeof(integer)
	    );
    if (iostat != 0) {
	goto L100002;
    }
    iostat = do_uio(&__state->c__1, (char *)&(*bward), (ftnlen)sizeof(integer)
	    );
    if (iostat != 0) {
	goto L100002;
    }
    iostat = do_uio(&__state->c__1, (char *)&(*free), (ftnlen)sizeof(integer))
	    ;
    if (iostat != 0) {
	goto L100002;
    }
    iostat = do_uio(&__state->c__1, format, (ftnlen)8);
    if (iostat != 0) {
	goto L100002;
    }
    iostat = do_uio(&__state->c__1, tail, (ftnlen)928);
    if (iostat != 0) {
	goto L100002;
    }
    iostat = e_wdue();
L100002:
    if (iostat != 0) {
	setmsg_("File record write failed. Value of IOSTAT was #", (ftnlen)47)
		;
	errint_("#", &iostat, (ftnlen)1);
	sigerr_("SPICE(DAFWRITEFAIL)", (ftnlen)19);
	chkout_("DAFWFR", (ftnlen)6);
	return 0;
    }
    chkout_("DAFWFR", (ftnlen)6);
    return 0;
} /* dafwfr_ */

