/* dafac.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern dafac_init_t __dafac_init;
static inline dafac_state_t* get_dafac_state(cspice_t* state) {
	if (!state->dafac)
		state->dafac = __cspice_allocate_module(sizeof(dafac_state_t),
	 &__dafac_init, sizeof(__dafac_init));
	return state->dafac;

}

/* $Procedure DAFAC ( DAF add comments ) */
/* Subroutine */ int dafac_(cspice_t* __global_state, integer *handle, 
	integer *n, char *buffer, ftnlen buffer_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer s_rdue(f2c_state_t*, cilist *), do_uio(f2c_state_t*, integer *, 
	    char *, ftnlen), e_rdue(f2c_state_t*);
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer s_wdue(f2c_state_t*, cilist *), e_wdue(f2c_state_t*);

    /* Local variables */
    integer free;
    extern integer cpos_(cspice_t*, char *, char *, integer *, ftnlen, ftnlen)
	    ;
    extern /* Subroutine */ int zzddhhlu_(cspice_t*, integer *, char *, 
	    logical *, integer *, ftnlen);
    integer i__;
    integer j;
    integer space;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer ncomc;
    integer bward;
    integer fward;
    integer recno;
    logical found;
    integer ncomr;
    extern integer ncpos_(cspice_t*, char *, char *, integer *, ftnlen, 
	    ftnlen);
    logical empty;
    integer nd;
    extern logical failed_(cspice_t*);
    integer ni;
    extern /* Subroutine */ int dafsih_(cspice_t*, integer *, char *, ftnlen);
    char ifname[60];
    extern /* Subroutine */ int dafarr_(cspice_t*, integer *, integer *);
    char crecrd[1000];
    extern /* Subroutine */ int dafrfr_(cspice_t*, integer *, integer *, 
	    integer *, char *, integer *, integer *, integer *, ftnlen);
    integer daflun;
    integer nchars;
    extern integer lastnb_(cspice_t*, char *, ftnlen);
    integer length;
    integer newrec;
    integer eocpos;
    extern /* Subroutine */ int errfnm_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    integer nelpos;
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    integer iostat;
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    integer rinuse;
    integer curpos;
    integer notusd;
    extern logical return_(cspice_t*);

    /* Fortran I/O blocks */



    /* Module state */
    dafac_state_t* __state = get_dafac_state(__global_state);
/* $ Abstract */

/*     Add comments from a buffer of character strings to the comment */
/*     area of a binary DAF file, appending them to any comments which */
/*     are already present in the file's comment area. */

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
/*     UTILITY */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*      HANDLE    I    handle of a DAF opened with write access. */
/*      N         I    Number of comments to put into the comment area. */
/*      BUFFER    I    Buffer of comments to put into the comment area. */

/* $ Detailed_Input */

/*     HANDLE   The file handle of a binary DAF which has been opened */
/*              with write access. */

/*     N        The number of comments in BUFFER that are to be added to */
/*              the comment area of the binary DAF attached to HANDLE. */

/*     BUFFER   A buffer containing comments which are to be added */
/*              to the comment area of the binary DAF attached to HANDLE. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)   If the number of comments to be added is not positive, the */
/*          error SPICE(INVALIDARGUMENT) will be signalled. */

/*     2)   If a non printing ASCII character is encountered in the */
/*          comments, the error SPICE(ILLEGALCHARACTER) will be */
/*          signalled. */

/*     3)   If the binary DAF file attached to HANDLE is not open with */
/*          write access an error will be signalled by a routine called */
/*          by this routine. */

/*     4)   If the end of the comments cannot be found, i.e., the end of */
/*          comments marker is missing on the last comment record, the */
/*          error SPICE(BADCOMMENTAREA) will be signalled. */

/* $ Files */

/*     See argument HANDLE in $ Detailed_Input. */

/* $ Particulars */

/*     A binary DAF contains a data area which is reserved for storing */
/*     annotations or descriptive textual information about the data */
/*     contained in a file. This area is referred to as the ``comment */
/*     area'' of the file. The comment area of a DAF is a line oriented */
/*     medium for storing textual information. The comment area */
/*     preserves leading or embedded white space in the line(s) of text */
/*     which are stored so that the appearance of the information will */
/*     be unchanged when it is retrieved (extracted) at some other time. */
/*     Trailing blanks, however, are NOT preserved, due to the way that */
/*     character strings are represented in standard Fortran 77. */

/*     This routine will take a buffer of text lines and add (append) */
/*     them to the comment area of a binary DAF. If there are no */
/*     comments in the comment area of the file, then space will be */
/*     allocated and the text lines in BUFFER will be placed into the */
/*     comment area. The text lines may contain only printable ASCII */
/*     characters (decimal values 32 - 126). */

/*     There is NO maximum length imposed on the significant portion */
/*     of a text line that may be placed into the comment area of a */
/*     DAF. The maximum length of a line stored in the comment area */
/*     should be reasonable, however, so that they may be easily */
/*     extracted. A good maximum value for this would be 255 characters, */
/*     as this can easily accommodate ``screen width'' lines as well as */
/*     long lines which may contain some other form of information. */

/* $ Examples */

/*     Let */

/*           HANDLE   be the handle for a DAF which has been opened with */
/*                    write access. */

/*           N        be the number of lines of text to be added to the */
/*                    comment area of the binary DAF attached to HANDLE. */

/*           BUFFER   is a list of text lines to be added to the comment */
/*                    area of the binary DAF attached to HANDLE. */

/*     The call */

/*           CALL DAFAC ( HANDLE, N, BUFFER ) */

/*     will append the first N line(s) in BUFFER to the comment area */
/*     of the binary DAF attached to HANDLE. */

/* $ Restrictions */

/*     1) This routine uses constants that are specific to the ASCII */
/*        character sequence. The results of using this routine with */
/*        a different character sequence are unpredictable. */

/*     2) This routine is only used to extract records on environments */
/*        whose characters are a single byte in size.  Updates to this */
/*        routine and routines in its call tree may be required to */
/*        properly handle other cases. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     K.R. Gehringer (JPL) */

/* $ Version */

/* -    Support Version 2.0.0, 16-NOV-2001 (FST) */

/*        Updated this routine to utilize the new handle manager */
/*        interfaces. */

/* -    Beta Version 1.0.0, 26-JUL-1994 (KRG) */

/* -& */
/* $ Index_Entries */

/*     add comments to a binary daf file */
/*     append comments to a daf file comment area */

/* -& */
/* $ Revisions */

/* -    Support Version 2.0.0, 16-NOV-2001 (FST) */

/*        The call to DAFHLU has been replaced with a call to ZZDDHHLU, */
/*        the handle manager interface for retrieving a logical unit. */
/*        DAFHLU is no longer used, since it locks the unit returned to */
/*        its HANDLE, tying up resources in the handle manager. */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */

/*     Length of a DAF file internal filename. */


/*     Decimal value for the DAF comment area end-of-comment (EOC) */
/*     marker. */


/*     Decimal value for the DAF comment area end-of-line (EOL) marker. */


/*     Length of a DAF character record, in characters. */


/*     Maximum and minimum decimal values for the printable ASCII */
/*     characters. */


/*     Local variables */


/*     Saved variables */


/*     Initial values */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "DAFAC", (ftnlen)5);
    }

/*     The lines of text in BUFFER will be ``packed'' into DAF comment */
/*     records: the significant portion of each comment line from BUFFER */
/*     will be terminated using the special character EOLMRK to indicate */
/*     the end of the line. When a comment record is full or all of the */
/*     comments have been added, the comment record will be written to */
/*     the comment area of the binary DAF file. */

/*     If this is the first time that this routine has been called, */
/*     we need to initialize the character value for the end-of-line */
/*     marker and the character value for the end of comments marker. */

    if (__state->first) {
	__state->first = FALSE_;
	*(unsigned char *)__state->eocmrk = '\4';
	*(unsigned char *)__state->eolmrk = '\0';
    }

/*     Verify that the DAF file attached to HANDLE is opened with write */
/*     access. */

    dafsih_(__global_state, handle, "WRITE", (ftnlen)5);
    if (failed_(__global_state)) {
	chkout_(__global_state, "DAFAC", (ftnlen)5);
	return 0;
    }

/*     Convert the DAF file handle to its corresponding Fortran logical */
/*     unit number for reading and writing comment records. */

    zzddhhlu_(__global_state, handle, "DAF", &__state->c_false, &daflun, (
	    ftnlen)3);
    if (failed_(__global_state)) {
	chkout_(__global_state, "DAFAC", (ftnlen)5);
	return 0;
    }

/*     Check for a nonpositive number of lines in the buffer. */

    if (*n <= 0) {
	setmsg_(__global_state, "The number of comment lines to be added to "
		"the binary DAF file '#' was not positive: #.", (ftnlen)87);
	errfnm_(__global_state, "#", &daflun, (ftnlen)1);
	errint_(__global_state, "#", n, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDARGUMENT)", (ftnlen)22);
	chkout_(__global_state, "DAFAC", (ftnlen)5);
	return 0;
    }

/*     Count the number of characters in the buffer ignoring trailing */
/*     blanks on nonblank lines and blank lines. The count will be */
/*     modified to include the contribution of blank lines later. This */
/*     count is used to determine the number of character records to be */
/*     added to the binary DAF file attached to HANDLE. */

    nchars = 0;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {

/*        Get the length of the significant portion of a comment line. */

	length = lastnb_(__global_state, buffer + (i__ - 1) * buffer_len, 
		buffer_len);

/*        Scan the comment line for non printing characters. */

	i__2 = length;
	for (j = 1; j <= i__2; ++j) {

/*           Check to see that the characters in the buffer are all */
/*           printing ASCII characters. The bounds for printing ASCII */
/*           characters are given by MINPCH and MAXPCH, which are */
/*           defined in the $ Local Parameters section of the header. */

	    if (*(unsigned char *)&buffer[(i__ - 1) * buffer_len + (j - 1)] > 
		    126 || *(unsigned char *)&buffer[(i__ - 1) * buffer_len + 
		    (j - 1)] < 32) {
		setmsg_(__global_state, "A nonprinting character was encount"
			"ered in the comment buffer. Value: #", (ftnlen)71);
		i__3 = *(unsigned char *)&buffer[(i__ - 1) * buffer_len + (j 
			- 1)];
		errint_(__global_state, "#", &i__3, (ftnlen)1);
		sigerr_(__global_state, "SPICE(ILLEGALCHARACTER)", (ftnlen)23)
			;
		chkout_(__global_state, "DAFAC", (ftnlen)5);
		return 0;
	    }
	}

/*        Increment the number of characters by the length of the */
/*        significant portion of the current line in the buffer. */

	nchars += length;
    }

/*     We need to include the number of end of line markers in the */
/*     number of characters, so add the number of comment lines to */
/*     be added, N, to the number of characters, NCHARS. This is where */
/*     the contribution of any blank lines gets added to the character */
/*     count. We also need to have space for the end of comments marker. */

    nchars = nchars + *n + 1;

/*     Get the current number of comment records and comment characters */
/*     from the DAF file attached to HANDLE. We will also get back some */
/*     extra stuff that we do not use. */

    dafrfr_(__global_state, handle, &nd, &ni, ifname, &fward, &bward, &free, (
	    ftnlen)60);
    if (failed_(__global_state)) {
	chkout_(__global_state, "DAFAC", (ftnlen)5);
	return 0;
    }

/*     Compute the number of comment records and the number of comment */
/*     characters. In order to perform these calculations, we assume */
/*     that we have a valid comment area in the DAF file attached to */
/*     HANDLE. */

    ncomr = fward - 2;
    if (ncomr > 0) {

/*        The starting record number is the number of comment records + 1 */
/*        where the 1 skips the file record. */

	empty = TRUE_;
	found = FALSE_;
	notusd = 0;
	while(ncomr > 0 && ! found && empty) {
	    recno = ncomr + 1;
	    __state->io___21.ciunit = daflun;
	    __state->io___21.cirec = recno;
	    iostat = s_rdue(&__global_state->f2c, &__state->io___21);
	    if (iostat != 0) {
		goto L100001;
	    }
	    iostat = do_uio(&__global_state->f2c, &__state->c__1, crecrd, (
		    ftnlen)1000);
	    if (iostat != 0) {
		goto L100001;
	    }
	    iostat = e_rdue(&__global_state->f2c);
L100001:
	    if (iostat != 0) {
		setmsg_(__global_state, "Error reading comment area of binar"
			"y file named '#'.  IOSTAT = #.", (ftnlen)65);
		errfnm_(__global_state, "#", &daflun, (ftnlen)1);
		errint_(__global_state, "#", &iostat, (ftnlen)1);
		sigerr_(__global_state, "SPICE(FILEREADFAILED)", (ftnlen)21);
		chkout_(__global_state, "DAFAC", (ftnlen)5);
		return 0;
	    }

/*           Scan the comment record looking for the end of comments */
/*           marker. */

	    eocpos = cpos_(__global_state, crecrd, __state->eocmrk, &
		    __state->c__1, (ftnlen)1000, (ftnlen)1);
	    if (eocpos > 0) {
		found = TRUE_;
	    } else {
		nelpos = ncpos_(__global_state, crecrd, __state->eolmrk, &
			__state->c__1, (ftnlen)1000, (ftnlen)1);
		if (nelpos != 0) {
		    empty = FALSE_;
		} else {
		    --ncomr;
		    ++notusd;
		}
	    }
	}

/*        If we do not find the end of comments marker and the comment */
/*        area is not empty, then it is an error. */

	if (! found && ! empty) {
	    setmsg_(__global_state, "The comment area in the DAF file '#' ma"
		    "y be damaged. The end of the comments could not be found."
		    , (ftnlen)96);
	    errfnm_(__global_state, "#", &daflun, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(BADCOMMENTAREA)", (ftnlen)21);
	    chkout_(__global_state, "DAFAC", (ftnlen)5);
	    return 0;
	} else if (found) {
	    ncomc = (ncomr - 1) * 1000 + eocpos - 1;
	} else if (empty) {
	    ncomc = 0;
	}
    } else {
	ncomc = 0;
	notusd = 0;
    }

/*     Determine the amount of free space in the comment area. If */
/*     there are some comment records allocated, the space available */
/*     is the number of comment records allocated times the length of */
/*     a comment record, minus the number of comment characters already */
/*     used. Otherwise, the space available is zero. */

    if (ncomr + notusd > 0) {
	space = notusd * 1000 + ncomr * 1000 - ncomc;
    } else {
	space = 0;
    }

/*     Determine the number of new comment records which are necessary */
/*     to store all of the comments from the buffer. */

    if (nchars > space) {

/*        If there are more characters to store than available space */
/*        we need at least one new record. */

	newrec = (nchars - space - 1) / 1000 + 1;
    } else {

/*        Otherwise, we do not need any new records. */

	newrec = 0;
    }

/*     Now add the necessary number of comment records to the file, */
/*     if we need to add any. */

    if (newrec > 0) {
	dafarr_(__global_state, handle, &newrec);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "DAFAC", (ftnlen)5);
	    return 0;
	}
    }

/*     At this point, we know that we have enough space to write all of */
/*     the comments in BUFFER to the comment area. Either there was */
/*     enough space already there, or we calculated how many new comment */
/*     records were needed, and we added them to the file. So, now we */
/*     begin ``packing'' the comments into DAF comment records and */
/*     writing them to the file. */

/*     We begin initializing the appropriate variables. */

    if (ncomc == 0) {

/*        If there are no comments in the comment area, then we need */
/*        to skip the file record. The first available comment record */
/*        is therecord immediately after the file record, so we set */
/*        RECNO accordingly. We also initialize the current position in */
/*        the comment record, and the comment record itself. */

	recno = 2;
	curpos = 1;
	s_copy(&__global_state->f2c, crecrd, " ", (ftnlen)1000, (ftnlen)1);
    } else {

/*        If there are comments in the comment area, then we need to */
/*        skip the file record and any comment records which have been */
/*        filled. The first comment record with space available is the */
/*        record immediately following the last completely filled */
/*        comment record. So calculate the number of comment records */
/*        in use, and set RECNO appropriately. Finally calculate the */
/*        initial position. */

	rinuse = ncomc / 1000 + 1;
	recno = rinuse + 1;
	curpos = ncomc - (rinuse - 1) * 1000 + 1;
    }

/*     Begin ``packing'' the comments from the input buffer into the */
/*     comment records, writing the comment records to the file as they */
/*     become filled. */

    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {

/*        Get the length of the significant portion of comment line I. */

	length = lastnb_(__global_state, buffer + (i__ - 1) * buffer_len, 
		buffer_len);

/*        Process the comment line. */

	i__2 = length;
	for (j = 1; j <= i__2; ++j) {

/*           If we have filled the comment record while processing */
/*           comment line BUFFER(I), write out the comment record, */
/*           increment the record number, RECNO, and reset the values */
/*           of the current position and the comment record. */

	    if (curpos > 1000) {
		__state->io___30.ciunit = daflun;
		__state->io___30.cirec = recno;
		iostat = s_wdue(&__global_state->f2c, &__state->io___30);
		if (iostat != 0) {
		    goto L100002;
		}
		iostat = do_uio(&__global_state->f2c, &__state->c__1, crecrd, 
			(ftnlen)1000);
		if (iostat != 0) {
		    goto L100002;
		}
		iostat = e_wdue(&__global_state->f2c);
L100002:
		if (iostat != 0) {
		    setmsg_(__global_state, "Error writing to record # of th"
			    "e binary file named '#'. IOSTAT = #.", (ftnlen)67)
			    ;
		    errint_(__global_state, "#", &recno, (ftnlen)1);
		    errfnm_(__global_state, "#", &daflun, (ftnlen)1);
		    errint_(__global_state, "#", &iostat, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(FILEWRITEFAILED)", (ftnlen)
			    22);
		    chkout_(__global_state, "DAFAC", (ftnlen)5);
		    return 0;
		}
		++recno;
		curpos = 1;
		s_copy(&__global_state->f2c, crecrd, " ", (ftnlen)1000, (
			ftnlen)1);
	    }
	    *(unsigned char *)&crecrd[curpos - 1] = *(unsigned char *)&buffer[
		    (i__ - 1) * buffer_len + (j - 1)];
	    ++curpos;
	}

/*        Check to see if we happened to exactly fill the comment record */
/*        when we finished processing comment line BUFFER(I). If we */
/*        did, CURPOS will be 1 greater than MXCREC, and we will need */
/*        to write the comment record to the file, increment the record */
/*        number, RECNO, and reset the values of the current position */
/*        and the comment record. */

	if (curpos > 1000) {
	    __state->io___31.ciunit = daflun;
	    __state->io___31.cirec = recno;
	    iostat = s_wdue(&__global_state->f2c, &__state->io___31);
	    if (iostat != 0) {
		goto L100003;
	    }
	    iostat = do_uio(&__global_state->f2c, &__state->c__1, crecrd, (
		    ftnlen)1000);
	    if (iostat != 0) {
		goto L100003;
	    }
	    iostat = e_wdue(&__global_state->f2c);
L100003:
	    if (iostat != 0) {
		setmsg_(__global_state, "Error writing to record # of the bi"
			"nary file named '#'. IOSTAT = #.", (ftnlen)67);
		errint_(__global_state, "#", &recno, (ftnlen)1);
		errfnm_(__global_state, "#", &daflun, (ftnlen)1);
		errint_(__global_state, "#", &iostat, (ftnlen)1);
		sigerr_(__global_state, "SPICE(FILEWRITEFAILED)", (ftnlen)22);
		chkout_(__global_state, "DAFAC", (ftnlen)5);
		return 0;
	    }
	    ++recno;
	    curpos = 1;
	    s_copy(&__global_state->f2c, crecrd, " ", (ftnlen)1000, (ftnlen)1)
		    ;
	}

/*        Append the end-of-line marker to the comment line that we just */
/*        placed into the comment record. */

	*(unsigned char *)&crecrd[curpos - 1] = *(unsigned char *)
		__state->eolmrk;
	++curpos;
    }

/*     We have now finished processing all of the comment lines in */
/*     BUFFER, so we need write the current record to the file. This */
/*     record will always contain something, so we always need to write */
/*     it. */

    if (curpos > 1000) {

/*        If we have completely filled the comment record, the last */
/*        character of the last line n the buffer coincides with the */
/*        last character in the comment record, then we need to write */
/*        the record and get set up to add the end of comments mark on */
/*        the next record. */

	__state->io___32.ciunit = daflun;
	__state->io___32.cirec = recno;
	iostat = s_wdue(&__global_state->f2c, &__state->io___32);
	if (iostat != 0) {
	    goto L100004;
	}
	iostat = do_uio(&__global_state->f2c, &__state->c__1, crecrd, (ftnlen)
		1000);
	if (iostat != 0) {
	    goto L100004;
	}
	iostat = e_wdue(&__global_state->f2c);
L100004:
	if (iostat != 0) {
	    setmsg_(__global_state, "Error writing to record # of the binary"
		    " file named '#'. IOSTAT = #.", (ftnlen)67);
	    errint_(__global_state, "#", &recno, (ftnlen)1);
	    errfnm_(__global_state, "#", &daflun, (ftnlen)1);
	    errint_(__global_state, "#", &iostat, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(FILEWRITEFAILED)", (ftnlen)22);
	    chkout_(__global_state, "DAFAC", (ftnlen)5);
	    return 0;
	}
	++recno;
	curpos = 1;
	s_copy(&__global_state->f2c, crecrd, " ", (ftnlen)1000, (ftnlen)1);
    }

/*     Add the end of comments mark to the final comment record and */
/*     write it to the file. */

    *(unsigned char *)&crecrd[curpos - 1] = *(unsigned char *)__state->eocmrk;
    __state->io___33.ciunit = daflun;
    __state->io___33.cirec = recno;
    iostat = s_wdue(&__global_state->f2c, &__state->io___33);
    if (iostat != 0) {
	goto L100005;
    }
    iostat = do_uio(&__global_state->f2c, &__state->c__1, crecrd, (ftnlen)
	    1000);
    if (iostat != 0) {
	goto L100005;
    }
    iostat = e_wdue(&__global_state->f2c);
L100005:
    if (iostat != 0) {
	setmsg_(__global_state, "Error writing to record # of the binary fil"
		"e named '#'. IOSTAT = #.", (ftnlen)67);
	errint_(__global_state, "#", &recno, (ftnlen)1);
	errfnm_(__global_state, "#", &daflun, (ftnlen)1);
	errint_(__global_state, "#", &iostat, (ftnlen)1);
	sigerr_(__global_state, "SPICE(FILEWRITEFAILED)", (ftnlen)22);
	chkout_(__global_state, "DAFAC", (ftnlen)5);
	return 0;
    }

/*     Check out and leave DAFAC. */

    chkout_(__global_state, "DAFAC", (ftnlen)5);
    return 0;
} /* dafac_ */

