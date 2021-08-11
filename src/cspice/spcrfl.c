/* spcrfl.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern spcrfl_init_t __spcrfl_init;
static spcrfl_state_t* get_spcrfl_state() {
	cspice_t* state =  __cspice_get_state();
	if (!state->spcrfl)
		state->spcrfl = __cspice_allocate_module(sizeof(
	spcrfl_state_t), &__spcrfl_init, sizeof(__spcrfl_init));
	return state->spcrfl;

}

/* $Procedure SPCRFL ( SPK and CK, read first line of comments ) */
/* Subroutine */ int spcrfl_0_(int n__, integer *handle, char *line, logical *
	eoc, ftnlen line_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rdue(cilist *), do_uio(integer *, char *, ftnlen), e_rdue(void);

    /* Local variables */
    extern /* Subroutine */ int zzddhhlu_(integer *, char *, logical *, 
	    integer *, ftnlen);
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    extern logical failed_(void);
    extern /* Subroutine */ int dafrfr_(integer *, integer *, integer *, char 
	    *, integer *, integer *, integer *, ftnlen);
    extern /* Subroutine */ int errfnm_(char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(char *, ftnlen);
    extern /* Subroutine */ int chkout_(char *, ftnlen);
    extern /* Subroutine */ int setmsg_(char *, ftnlen);
    extern /* Subroutine */ int errint_(char *, integer *, ftnlen);
    extern logical return_(void);
    extern integer pos_(char *, char *, integer *, ftnlen, ftnlen);
    /* Fortran I/O blocks */



    /* Module state */
    spcrfl_state_t* __state = get_spcrfl_state();
/* $ Abstract */

/*     Read the first line of text from the comment area */
/*     of a binary SPK or CK file. */

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

/*     SPC */

/* $ Keywords */

/*     FILES */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle assigned to binary SPK or CK file. */
/*     LINE       O   First line of text from the comment area. */
/*     EOC        O   End of comments? */

/* $ Detailed_Input */

/*     HANDLE      is the handle assigned to the binary SPK or CK file */
/*                 which has been opened for read access. */

/* $ Detailed_Output */

/*     LINE        is the first line of text from the comment area of */
/*                 the SPK or CK file specified by HANDLE.  LINE may */
/*                 be blank. */

/*     EOC         is true if the comment area is empty.  If there */
/*                 are comments in the comment area, then EOC is false. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If the comment area of the SPK or CK file is empty, LINE */
/*        will be blank. */

/*     2) If the first line of comments in the comment area is longer */
/*        than the declared length of LINE, it will be truncated to */
/*        fit into the variable. */

/*     3) If there is a problem reading from the comment area, the error */
/*        SPICE(FILEREADFAILED) is signalled. */

/*     4) If the comments are not in the correct format, the error */
/*        SPICE(FORMATERROR) is signalled. */

/* $ Files */

/*     HANDLE      is the handle assigned to the binary SPK or CK file. */
/*                 Use DAFOPR to open it for read access and get its */
/*                 handle unless SPKLEF or CKLPF has already been called */
/*                 and returned the handle.  This file is unchanged by */
/*                 calling SPCRFL. */

/* $ Particulars */

/*     The structure of SPK and CK files accommodates comments in */
/*     addition to data.  The following routines are available */
/*     for accessing the comment area of a binary SPK or CK file: */

/*           SPCAC           add comments */

/*           SPCEC           extract comments */

/*           SPCDC           delete comments */

/*           SPCRFL          read first line of comments */

/*           SPCRNL          read next line of comments */

/*     Note that comments must consist of only text, that is, printable */
/*     ASCII characters, specifically ASCII 32-126.  This excludes */
/*     tabs (ASCII 9) and control characters. */

/*     The SPC conversion routines---SPCB2A, SPCA2B, SPCB2T, and */
/*     SPCT2B---include these comments when converting SPK and CK */
/*     files between binary and text formats. */

/* $ Examples */

/*     Suppose we have a binary SPK file called A.BSP.  The following */
/*     code fragment searches the comment area for a lines containing */
/*     the character string `SOURCE' and writes the lines to standard */
/*     output. */

/*      C */
/*      C     Open the binary SPK file and get its handle. */
/*      C */
/*            CALL DAFOPR ( 'A.BSP', HANDLE ) */

/*      C */
/*      C     Read the first line of comments. */
/*      C */
/*            CALL SPCRFL ( HANDLE, LINE, EOC ) */

/*      C */
/*      C     Search for the string 'SOURCE' in the line.  If */
/*      C     it is found, write the line.  Then get the next */
/*      C     line of comments and repeat as long as we're not */
/*      C     at the end. */
/*      C */
/*            DO WHILE ( .NOT. EOC ) */

/*               IF (  POS ( LINE, 'SOURCE', 1 ) .NE. 0  ) THEN */
/*                  WRITE (*,*) LINE */
/*               END IF */

/*               CALL SPCRNL ( LINE, EOC ) */

/*            END DO */

/* $ Restrictions */

/*     1)  This routine assumes that the comment area of the binary SPK */
/*         or CK file contains only text stored by SPCAC.  Comments */
/*         written any other way may not be handled properly. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     K.R. Gehringer (JPL) */
/*     J.E. McLean    (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (FST) */

/*        Updated this routine to utilize the new handle manager */
/*        interfaces. */

/* -    SPICELIB Version 1.1.0, 27-JUL-1992 (KRG) */

/*        Removed a call to the SPICELIB subroutine SUFFIX() which */
/*        was used to join two parts of a comment line that may be */
/*        broken across two comment records. The problem was, SUFFIX */
/*        cannot know about leading/imbedded blanks when it appends, so */
/*        blanks were inadvertantly removed when they happened to be */
/*        stored at the end of comment record. */

/*        Added the variable TMPLEN to record the length of the first */
/*        part of a comment line that may be broken across comment */
/*        records. */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 15-APR-1991 (JEM) */

/* -& */
/* $ Index_Entries */

/*     read the first comment line of an spk or ck file */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (FST) */

/*        Calls to DAFHLU now lock handles to their logical units. */
/*        While at first glance it may seem this is the appropriate */
/*        course of action due to the buffering of the logical unit */
/*        by this routine for its entry point, adding a call to */
/*        ZZDDHUNL in the entry point removes the need to lock DAFU */
/*        to its handle.  The value of HANDLE is now buffered in */
/*        HANBUF, to allow the entry point to retrieve a logical */
/*        unit. */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */

/*     IFNLEN      is the length of a DAF internal file name. */

/*     MAXCPR      is the maximum number of characters per DAF record and */
/*                 hence the maximum comment line length. */


/*     Local variables */


/*     Saved variables */


/*     Standard SPICE error handling. */

    switch(n__) {
	case 1: goto L_spcrnl;
	}

    if (return_()) {
	return 0;
    } else {
	chkin_("SPCRFL", (ftnlen)6);
    }

/*     SPCRFL has been called for this file. */

    __state->called = TRUE_;

/*     Read the file record to find out if the DAF contains any */
/*     reserved records.  The reserved records in an array file */
/*     are stored between the first record and the first summary */
/*     record.  FWARD is the record number of that first summary */
/*     record, and NRR is the number of reserved records in the file. */

/*     If there are no reserved records, there are no comments. */

    dafrfr_(handle, &__state->nd, &__state->ni, __state->ifname, &
	    __state->fward, &__state->bward, &__state->free, (ftnlen)60);
    __state->nrr = __state->fward - 2;
    if (__state->nrr == 0) {
	s_copy(line, " ", line_len, (ftnlen)1);
	*eoc = TRUE_;
	__state->eocsav = *eoc;
	chkout_("SPCRFL", (ftnlen)6);
	return 0;
    }

/*     We need to read directly from the SPK/CK file, using a logical */
/*     unit instead of a handle. */

    zzddhhlu_(handle, "DAF", &__state->c_false, &__state->dafu, (ftnlen)3);
    if (failed_()) {
	chkout_("SPCRFL", (ftnlen)6);
	return 0;
    }

/*     Buffer the value of HANDLE. */

    __state->hanbuf = *handle;

/*     In the comment area, NULL means end-of-line, and EOT means */
/*     end-of-transmission, or in other words, end-of-comments. */

    *(unsigned char *)__state->null = '\0';
    *(unsigned char *)__state->eot = '\4';

/*     Read the first reserved record. */

    __state->rec = 2;
    __state->io___16.ciunit = __state->dafu;
    __state->io___16.cirec = __state->rec;
    __state->iostat = s_rdue(&__state->io___16);
    if (__state->iostat != 0) {
	goto L100001;
    }
    __state->iostat = do_uio(&__state->c__1, __state->record, (ftnlen)1000);
    if (__state->iostat != 0) {
	goto L100001;
    }
    __state->iostat = e_rdue();
L100001:
    if (__state->iostat != 0) {
	setmsg_("Error reading comment area of the binary file named FNM at "
		"record #.  Value of IOSTAT is #.", (ftnlen)91);
	errint_("#", &__state->rec, (ftnlen)1);
	errint_("#", &__state->iostat, (ftnlen)1);
	errfnm_("FNM", &__state->dafu, (ftnlen)3);
	sigerr_("SPICE(FILEREADFAILED)", (ftnlen)21);
	chkout_("SPCRFL", (ftnlen)6);
	return 0;
    }

/*     The first line of comments begins with the first character */
/*     of the record.  A NULL character specifies the end. */

    __state->posnul = pos_(__state->record, __state->null, &__state->c__1, (
	    ftnlen)1000, (ftnlen)1);
    if (__state->posnul == 0) {

/*        No NULL is in the record, so LINE is just the whole */
/*        record.  (The maximum length of a line written to */
/*        the comment area by SPCAC is MAXCPR characters). */

	__state->eol = 1000;
    } else {

/*        The end of the line precedes the NULL character. */

	__state->eol = __state->posnul - 1;
    }

/*     Now we have the position of the end of the first line. */
/*     Assign it to LINE.  We're not yet at the end of comments, */
/*     since we have a line to return.  If the first character */
/*     was a NULL, the line is blank. */

    if (__state->eol == 0) {
	s_copy(line, " ", line_len, (ftnlen)1);
    } else {
	s_copy(line, __state->record, line_len, __state->eol);
    }
    *eoc = FALSE_;
    __state->eocsav = *eoc;
    chkout_("SPCRFL", (ftnlen)6);
    return 0;
/* $Procedure SPCRNL ( SPK and CK, read next line of comments ) */

L_spcrnl:
/* $ Abstract */

/*     Continue reading lines from the comment area of a binary */
/*     SPK or CK file specified by the most recent call to */
/*     the routine SPCRFL. */

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

/*     SPC */

/* $ Keywords */

/*     FILES */

/* $ Declarations */

/*     CHARACTER*(*)         LINE */
/*     LOGICAL               EOC */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     LINE       O   Next line of text from the comment area. */
/*     EOC        O   End of comments? */

/* $ Detailed_Input */

/*     None. */

/* $ Detailed_Output */

/*     LINE        is the next line of text from the comment area of */
/*                 the SPK or CK file.  LINE may be blank. */
/*                 SPCRFL reads the first line of comments from */
/*                 a specified binary SPK or CK file.  Once SPCRFL */
/*                 has been called, SPCRNL may be called repetitively */
/*                 to read the next lines of the comment area until */
/*                 the end. */

/*     EOC         is true if there are no more comments to read. */
/*                 Otherwise, EOC is false. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If SPCRFL is not called prior to calling SPCRNL, the error */
/*        SPICE(SPCRFLNOTCALLED). */

/*     2) If the most recent call to SPCRFL returned EOC with the value */
/*        true, then SPCRNL will return EOC with the same value. */

/*     3) If EOC is true, LINE will be blank. */

/*     4) If the first line of comments in the comment area is longer */
/*        than the declared length of LINE, it will be truncated to */
/*        fit into the variable. */

/*     5) If there is a problem reading from the comment area, the error */
/*        SPICE(FILEREADFAILED) is signalled. */

/*     6) If the comments are not in the correct format, the error */
/*        SPICE(FORMATERROR) is signalled. */

/* $ Files */

/*     The handle of the binary SPK or CK is specified with the routine */
/*     SPCRFL. */

/* $ Particulars */

/*     The structure of SPK and CK files accommodates comments in */
/*     addition to data.  The following five routines are available */
/*     for accessing the comment area of a binary SPK or CK file: */

/*           SPCAC           add comments */

/*           SPCEC           extract comments */

/*           SPCDC           delete comments */

/*           SPCRFL          read first line of comments */

/*           SPCRNL          read next line of comments */

/*     Note that comments must consist of only text, that is, printable */
/*     ASCII characters, specifically ASCII 32-126.  This excludes */
/*     tabs (ASCII 9) and control characters. */

/*     The SPC conversion routines---SPCB2A, SPCA2B, SPCB2T, and */
/*     SPCT2B---include these comments when converting SPK and CK */
/*     files between binary and text formats. */

/* $ Examples */

/*     Suppose we have a binary SPK file called A.BSP.  The following */
/*     code fragment searches the comment area for a lines containing */
/*     the character string `SOURCE' and writes the lines to standard */
/*     output. */

/*      C */
/*      C     Open the binary SPK file and get its handle. */
/*      C */
/*            CALL DAFOPR ( 'A.BSP', HANDLE ) */

/*      C */
/*      C     Read the first line of comments. */
/*      C */
/*            CALL SPCRFL ( HANDLE, LINE, EOC ) */

/*      C */
/*      C     Search for the string 'SOURCE' in the line.  If */
/*      C     it is found, write the line.  Then get the next */
/*      C     line of comments and repeat as long as we're not */
/*      C     at the end. */
/*      C */
/*            DO WHILE ( .NOT. EOC ) */

/*               IF (  POS ( LINE, 'SOURCE', 1 ) .NE. 0  ) THEN */
/*                  WRITE (*,*) LINE */
/*               END IF */

/*               CALL SPCRNL ( LINE, EOC ) */

/*            END DO */

/* $ Restrictions */

/*     1)  This routine assumes that the comment area of the binary SPK */
/*         or CK file contains only text stored by SPCAC.  Comments */
/*         written any other way may not be handled properly. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     K.R. Gehringer (JPL) */
/*     J.E. McLean    (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (FST) */

/*        Updated this entry point to utilize the handle manager */
/*        interfaces.  See the Revisions section of the subroutine */
/*        header above for a detailed discussion of the changes. */

/* -    SPICELIB Version 1.1.0, 27-JUL-1992 (KRG) */

/*        Removed a call to the SPICELIB subroutine SUFFIX() which */
/*        was used to join two parts of a comment line that may be */
/*        broken across two comment records. The problem was, SUFFIX */
/*        cannot know about leading/imbedded blanks when it appends, so */
/*        blanks were inadvertantly removed when they happened to be */
/*        stored at the end of comment record. */

/*        Added the variable TMPLEN to record the length of the first */
/*        part of a comment line that may be broken across comment */
/*        records. */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 15-APR-1991 (JEM) */

/* -& */
/* $ Index_Entries */

/*     continue reading comments from an spk or ck file */
/*     read the next comment line of an spk or ck file */

/* -& */

/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    } else {
	chkin_("SPCRNL", (ftnlen)6);
    }

/*     If SPCRFL hasn't been called, then we don't know which */
/*     file to read from. */

    if (! __state->called) {
	setmsg_("You must call SPCRFL to read the first line of comments bef"
		"ore calling SPCRNL to read the next line.", (ftnlen)100);
	sigerr_("SPICE(SPCRFLNOTCALLED)", (ftnlen)22);
	chkout_("SPCRNL", (ftnlen)6);
	return 0;
    }

/*     If we were at the end of comments before, then we're still */
/*     at the end. */

    if (__state->eocsav) {
	s_copy(line, " ", line_len, (ftnlen)1);
	*eoc = TRUE_;
	chkout_("SPCRNL", (ftnlen)6);
	return 0;
    }

/*     Retrieve a logical unit for HANBUF. */

    zzddhhlu_(&__state->hanbuf, "DAF", &__state->c_false, &__state->dafu, (
	    ftnlen)3);
    if (failed_()) {
	chkout_("SPCRNL", (ftnlen)6);
	return 0;
    }

/*     RECORD contains the last line and EOL is the position of */
/*     the end of that line.  Now we need to determine the */
/*     position of the beginning of the next line (BOL).  There */
/*     is a NULL between EOL and BOL, so BOL is two more than */
/*     EOL.  If that puts BOL off the end of the current RECORD, */
/*     then we have to go to the next record. */

    __state->bol = __state->eol + 2;
    if (__state->bol > 1000) {
	__state->bol += -1000;
	++__state->rec;

/*        Check to make sure that we're not reading past the */
/*        reserved records.  FWARD is the "forward list pointer". */
/*        It is the number of the first record after the reserved */
/*        records. */

	if (__state->rec >= __state->fward) {
	    setmsg_("The comment area of the binary file named FNM is format"
		    "ted incorrectly. The end of the comments is not marked a"
		    "s it should be in record #. Calling SPCDC or DAFRRR will"
		    " remove the comment area and eliminate this format error"
		    ". Comments should be written ONLY by SPCAC.", (ftnlen)266)
		    ;
	    i__1 = __state->rec - 1;
	    errint_("#", &i__1, (ftnlen)1);
	    errfnm_("FNM", &__state->dafu, (ftnlen)3);
	    sigerr_("SPICE(FORMATERROR)", (ftnlen)18);
	    chkout_("SPCRNL", (ftnlen)6);
	    return 0;
	}

/*        All clear to read the record. */

	__state->io___21.ciunit = __state->dafu;
	__state->io___21.cirec = __state->rec;
	__state->iostat = s_rdue(&__state->io___21);
	if (__state->iostat != 0) {
	    goto L100002;
	}
	__state->iostat = do_uio(&__state->c__1, __state->record, (ftnlen)
		1000);
	if (__state->iostat != 0) {
	    goto L100002;
	}
	__state->iostat = e_rdue();
L100002:
	if (__state->iostat != 0) {
	    setmsg_("Error reading comment area of the binary file named FNM"
		    " at record #.  Value of IOSTAT is #.", (ftnlen)91);
	    errint_("#", &__state->rec, (ftnlen)1);
	    errint_("#", &__state->iostat, (ftnlen)1);
	    errfnm_("FNM", &__state->dafu, (ftnlen)3);
	    sigerr_("SPICE(FILEREADFAILED)", (ftnlen)21);
	    chkout_("SPCRNL", (ftnlen)6);
	    return 0;
	}
    }

/*     RECORD is now the record of the file that contains the */
/*     beginning of the next line (BOL).  The line may not */
/*     exist or may be blank or may be a character string. */

    if (*(unsigned char *)&__state->record[__state->bol - 1] == *(unsigned 
	    char *)__state->eot) {

/*        There isn't a next line to get.  We're at the end of */
/*        the comments. */

	s_copy(line, " ", line_len, (ftnlen)1);
	*eoc = TRUE_;
	__state->eocsav = *eoc;
	chkout_("SPCRNL", (ftnlen)6);
	return 0;
    }
    if (*(unsigned char *)&__state->record[__state->bol - 1] == *(unsigned 
	    char *)__state->null) {

/*        Just a NULL means a blank line. */

	__state->eol = __state->bol - 1;
	s_copy(line, " ", line_len, (ftnlen)1);
	*eoc = FALSE_;
	__state->eocsav = *eoc;
	chkout_("SPCRNL", (ftnlen)6);
	return 0;
    }

/*     The beginning of the next line is a character.  Now we have */
/*     to find the end.  It precedes the next NULL. */

    __state->posnul = pos_(__state->record, __state->null, &__state->bol, (
	    ftnlen)1000, (ftnlen)1);
    if (__state->posnul != 0) {
	__state->eol = __state->posnul - 1;
	s_copy(line, __state->record + (__state->bol - 1), line_len, 
		__state->eol - (__state->bol - 1));
	*eoc = FALSE_;
	__state->eocsav = *eoc;
    } else {

/*        There is no NULL in the rest of the record, so we have to */
/*        read the next record to find it.  Save the first part */
/*        of the line in TEMP. */

	s_copy(__state->temp, __state->record + (__state->bol - 1), (ftnlen)
		1000, 1000 - (__state->bol - 1));
	__state->tmplen = 1000 - __state->bol + 1;
	++__state->rec;

/*        Check to make sure that we're not reading past the */
/*        reserved records.  FWARD is the "forward list pointer". */
/*        It is the number of the first record after the reserved */
/*        records. */

	if (__state->rec >= __state->fward) {
	    setmsg_("The comment area of the binary file named FNM is format"
		    "ted incorrectly. The end of the comments is not marked a"
		    "s it should be in record #. Calling SPCDC or DAFRRR will"
		    " remove the comment area and eliminate this format error"
		    ". Comments should be written ONLY by SPCAC.", (ftnlen)266)
		    ;
	    i__1 = __state->rec - 1;
	    errint_("#", &i__1, (ftnlen)1);
	    errfnm_("FNM", &__state->dafu, (ftnlen)3);
	    sigerr_("SPICE(FORMATERROR)", (ftnlen)18);
	    chkout_("SPCRNL", (ftnlen)6);
	    return 0;
	}

/*        All clear to read the record. */

	__state->io___24.ciunit = __state->dafu;
	__state->io___24.cirec = __state->rec;
	__state->iostat = s_rdue(&__state->io___24);
	if (__state->iostat != 0) {
	    goto L100003;
	}
	__state->iostat = do_uio(&__state->c__1, __state->record, (ftnlen)
		1000);
	if (__state->iostat != 0) {
	    goto L100003;
	}
	__state->iostat = e_rdue();
L100003:
	if (__state->iostat != 0) {
	    setmsg_("Error reading comment area of the binary file named FNM"
		    " at record #.  Value of IOSTAT is #.", (ftnlen)91);
	    errint_("#", &__state->rec, (ftnlen)1);
	    errint_("#", &__state->iostat, (ftnlen)1);
	    errfnm_("FNM", &__state->dafu, (ftnlen)3);
	    sigerr_("SPICE(FILEREADFAILED)", (ftnlen)21);
	    chkout_("SPCRNL", (ftnlen)6);
	    return 0;
	}

/*        There should be a null in this new record.  If there isn't */
/*        then something is wrong.  The maximum length of a line is */
/*        MAXCPR characters according to SPCAC.  So BOL and the NULL */
/*        should be in the same record or in adjacent records. */

	__state->posnul = pos_(__state->record, __state->null, &__state->c__1,
		 (ftnlen)1000, (ftnlen)1);
	if (__state->posnul == 0) {
	    setmsg_("Cannot find the end of the line.  There is something wr"
		    "ong with the format of thecomments.", (ftnlen)90);
	    sigerr_("SPICE(FORMATERROR)", (ftnlen)18);
	    chkout_("SPCRNL", (ftnlen)6);
	    return 0;
	}
	__state->eol = __state->posnul - 1;

/*        EOL is zero if the NULL was the first character of the */
/*        new record.  Otherwise, concatenate the two parts of */
/*        the line from the two adjacent records.  Then assign the */
/*        values of LINE and EOC. */

	if (__state->eol != 0) {
	    i__1 = __state->tmplen;
	    s_copy(__state->temp + i__1, __state->record, 1000 - i__1, 
		    __state->eol);
	}
	s_copy(line, __state->temp, line_len, (ftnlen)1000);
	*eoc = FALSE_;
	__state->eocsav = *eoc;
    }
    chkout_("SPCRNL", (ftnlen)6);
    return 0;
} /* spcrfl_ */

/* Subroutine */ int spcrfl_(integer *handle, char *line, logical *eoc, 
	ftnlen line_len)
{
    return spcrfl_0_(0, handle, line, eoc, line_len);
    }

/* Subroutine */ int spcrnl_(char *line, logical *eoc, ftnlen line_len)
{
    return spcrfl_0_(1, (integer *)0, line, eoc, line_len);
    }

