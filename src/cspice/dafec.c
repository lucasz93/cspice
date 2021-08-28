/* dafec.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern dafec_init_t __dafec_init;
static inline dafec_state_t* get_dafec_state(cspice_t* state) {
	if (!state->dafec)
		state->dafec = __cspice_allocate_module(sizeof(dafec_state_t),
	 &__dafec_init, sizeof(__dafec_init));
	return state->dafec;

}

/* $Procedure DAFEC ( DAF extract comments ) */
/* Subroutine */ int dafec_(cspice_t* __global_state, integer *handle, 
	integer *bufsiz, integer *n, char *buffer, logical *done, ftnlen 
	buffer_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer), i_len(
	    f2c_state_t*, char *, ftnlen), s_rdue(f2c_state_t*, cilist *), 
	    do_uio(f2c_state_t*, integer *, char *, ftnlen), e_rdue(
	    f2c_state_t*);
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer free;
    extern integer cpos_(cspice_t*, char *, char *, integer *, ftnlen, ftnlen)
	    ;
    extern /* Subroutine */ int zzddhhlu_(cspice_t*, integer *, char *, 
	    logical *, integer *, ftnlen);
    integer i__;
    integer j;
    integer k;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer ncomc;
    integer bward;
    integer fward;
    integer recno;
    integer index;
    logical found;
    integer ncomr;
    extern integer ncpos_(cspice_t*, char *, char *, integer *, ftnlen, 
	    ftnlen);
    logical empty;
    char ch[1];
    integer nd;
    extern logical failed_(cspice_t*);
    integer ni;
    extern /* Subroutine */ int dafsih_(cspice_t*, integer *, char *, ftnlen);
    char ifname[60];
    extern /* Subroutine */ int dafrfr_(cspice_t*, integer *, integer *, 
	    integer *, char *, integer *, integer *, integer *, ftnlen);
    integer daflun;
    integer nchars;
    extern integer isrchi_(cspice_t*, integer *, integer *, integer *);
    integer linlen;
    integer eocpos;
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    integer numcom;
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    integer nelpos;
    extern /* Subroutine */ int errfnm_(cspice_t*, char *, integer *, ftnlen);
    integer iostat;
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    integer curpos;
    extern logical return_(cspice_t*);
    logical eol;

    /* Fortran I/O blocks */



    /* Module state */
    dafec_state_t* __state = get_dafec_state(__global_state);
/* $ Abstract */

/*     Extract comments from the comment area of a binary DAF. */

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
/*      HANDLE    I   Handle of binary DAF opened with read access. */
/*      BUFSIZ    I   Maximum size, in lines, of BUFFER. */
/*      N         O   Number of extracted comment lines. */
/*      BUFFER    O   Buffer where extracted comment lines are placed. */
/*      DONE      O   Indicates whether all comments have been extracted. */

/* $ Detailed_Input */

/*     HANDLE   The file handle of a binary DAF which has been opened */
/*              with read access. */

/*     BUFSIZ   The maximum number of comments that may be placed into */
/*              BUFFER. This would typically be the declared array size */
/*              for the Fortran character string array passed into this */
/*              routine. */

/* $ Detailed_Output */

/*     N        The number of comment lines extracted from the comment */
/*              area of the binary DAF attached to HANDLE. This number */
/*              will be <= BUFSIZ on output. If N = BUFSIZ and DONE <> */
/*              .TRUE., then there are more comments left to to extract. */
/*              If N = 0, then DONE = .TRUE., i.e., there were no */
/*              comments in the comment area or we have extracted all */
/*              of the comments. If there are comments in the comment */
/*              area, or comments remaining after the extraction process */
/*              has begun, N > 0, always. */

/*     BUFFER   A array of at most BUFSIZ comments which have been */
/*              extracted from the comment area of the binary DAF */
/*              attached to HANDLE. */

/*     DONE     A logical flag indicating whether or not all of the */
/*              comment lines from the comment area of the DAF have */
/*              been read. This variable has the value .TRUE. after the */
/*              last comment line has been read. It will have the value */
/*              .FALSE. otherwise. */

/*              If there are no comments in the comment area, this */
/*              variable will have the value .TRUE., and N = 0. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)   If the size of the output line buffer is is not positive, */
/*          the error SPICE(INVALIDARGUMENT) will be signaled. */

/*     3)   If a comment line in a DAF is longer than the length */
/*          of a character string array element of BUFFER, the error */
/*          SPICE(COMMENTTOOLONG) will be signaled. */

/*     3)   If the end of the comments cannot be found, i.e., the end of */
/*          comments marker is missing on the last comment record, the */
/*          error SPICE(BADCOMMENTAREA) will be signaled. */

/*     4)   If the number of comment characters scanned exceeds the */
/*          number of comment characters computed, the error */
/*          SPICE(BADCOMMENTAREA) will be signaled. */

/*     5)   If the binary DAF attached to HANDLE is not open for */
/*          reading,an error will be signaled by a routine called by */
/*          this routine. */

/* $ Files */

/*     See argument HANDLE in $ Detailed_Input. */

/* $ Particulars */

/*     A binary DAF contains an area which is reserved for storing */
/*     annotations or descriptive textual information describing the data */
/*     contained in a file. This area is referred to as the ``comment */
/*     area'' of the file. The comment area of a DAF is a line */
/*     oriented medium for storing textual information. The comment */
/*     area preserves any leading or embedded white space in the line(s) */
/*     of text which are stored, so that the appearance of the of */
/*     information will be unchanged when it is retrieved (extracted) at */
/*     some other time. Trailing blanks, however, are NOT preserved, */
/*     due to the way that character strings are represented in */
/*     standard Fortran 77. */

/*     This routine will read the comments from the comment area of */
/*     a binary DAF, placing them into a line buffer. If the line */
/*     buffer is not large enough to hold the entire comment area, */
/*     the portion read will be returned to the caller, and the DONE */
/*     flag will be set to .FALSE.. This allows the comment area to be */
/*     read in ``chunks,'' a buffer at a time. After all of the comment */
/*     lines have been read, the DONE flag will be set to .TRUE.. */

/*     This routine can be used to ``simultaneously'' extract comments */
/*     from the comment areas of multiple binary DAFs. See Example */
/*     2 in the $ Examples section. */

/* $ Examples */

/*     Example 1 */
/*     --------- */

/*     The following example will extract the entire comment area of a */
/*     binary DAF attached to HANDLE, displaying the comments on the */
/*     terminal screen. */

/*     Let */

/*        BUFFER  have the following declaration: */

/*           CHARACTER*(80)  BUFFER(25) */

/*        HANDLE  be the handle of an open binary DAF file. */

/*     then */

/*        BUFSIZ = 25 */
/*        DONE   = .FALSE. */

/*        DO WHILE ( .NOT. DONE ) */

/*           CALL DAFEC( HANDLE, BUFSIZ, N, BUFFER, DONE ) */

/*           DO I = 1, N */

/*              WRITE (*,*) BUFFER(I) */

/*           END DO */

/*        END DO */

/*     Example 2 */
/*     --------- */

/*     The following example demonstrates the use of this routine to */
/*     simultaneously read the comment areas of multiple DAFs. For each */
/*     file, the comments will be displayed on the screen as they are */
/*     extracted. */

/*     Let */

/*        BUFFER  have the following declaration: */

/*           CHARACTER*(80)  BUFFER(25) */

/*        NUMFIL     be the number of binary DAFs that are to have their */
/*                   comment areas displayed. */

/*        DAFNAM(I)  Be a list of filenames for the DAFs which are to */
/*                   have their comment areas displayed. */

/*        HANDLE(I)  be a list of handles for the DAFs which are to have */
/*                   their comment areas displayed. */

/*        DONE(I)    be a list of logical flags indicating whether */
/*                   we are done extracting the comment area from the */
/*                   DAF attached to HANDLE(I) */

/*     then */

/*            BUFSIZ = 25 */

/*            DO I = 1, NUMFIL */

/*               DONE(I)   = .FALSE. */
/*               HANDLE(I) = 0 */

/*            END DO */
/*     C */
/*     C      Open the DAFs. */
/*     C */
/*            DO I = 1, NUMFIL */

/*               CALL DAFOPR ( DAFNAM(I), HANDLE(I) ) */

/*            END DO */
/*     C */
/*     C      While there are still some comments left to read in at */
/*     C      least one of the files, read them and display them. */
/*     C */
/*            DO WHILE ( .NOT. ALLTRU( DONE, NUMFIL ) ) */

/*               DO I = 1, NUMFIL */

/*                  IF ( .NOT. DONE(I) ) THEN */

/*                     WRITE (*,*) */
/*                     WRITE (*,*) 'File: ', DAFNAM(I)(:RTRIM(DAFNAM(I))) */
/*                     WRITE (*,*) */
/*                     N = 0 */

/*                     CALL DAFEC ( HANDLE(I), */
/*           .                      BUFSIZ, */
/*           .                      N, */
/*           .                      BUFFER, */
/*           .                      DONE(I) ) */

/*                     DO J = 1, N */

/*                        WRITE (*,*) BUFFER(J)(:RTRIM(BUFFER(J))) */

/*                     END DO */

/*                  END IF */

/*               END DO */

/*            END DO */

/* $ Restrictions */

/*     1) The comment area may consist only of printing ASCII characters, */
/*        decimal values 32 - 126. */

/*     2) There is NO maximum length imposed on the significant portion */
/*        of a text line that may be placed into the comment area of a */
/*        DAF. The maximum length of a line stored in the comment area */
/*        should be kept reasonable, so that they may be easily */
/*        extracted. A good value for this would be 1000 characters, as */
/*        this can easily accomodate ``screen width'' lines as well as */
/*        long lines which may contain some other form of information. */

/*     3) This routine is only used to read records on environments */
/*        whose characters are a single byte in size.  Updates */
/*        to this routine and routines in its call tree may be */
/*        required to properly handle other cases. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     K.R. Gehringer (JPL) */
/*     F.S. Turner    (JPL) */
/*     N.J. Bachman   (JPL) */
/*     B.V. Semenov   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.1.0 12-APR-2012 (BVS) */

/*        Increased FTSIZE (from 1000 to 5000). */

/* -    SPICELIB Version 1.0.0 08-NOV-2006 (NJB) (KRG) (FST) */

/*        Based on Support Version 2.0.0, 16-NOV-2001 (FST) */

/* -& */
/* $ Index_Entries */

/*      extract comments from a DAF */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */

/*     Length of a DAF internal filename. */


/*     Decimal value for the DAF comment area end-of-comment (EOC) */
/*     marker. */


/*     Decimal value for the DAF comment area end-of-line (EOL) marker. */


/*     The maximum number of DAFs that may be open simultaneously. */


/*     Length of a DAF character record, in characters. */


/*     Local variables */


/*     The file table declarations for keeping track of which files */
/*     are currently in the process of having comments extracted. */


/*     Saved variables */


/*     Save all of the file table information. */


/*     Initial values */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "DAFEC", (ftnlen)5);
    }

/*     If this is the first time that this routine has been called, */
/*     we need to initialize the character value of the end-of-line */
/*     marker, and the file table variables. */

    if (__state->first) {
	__state->first = FALSE_;
	__state->nfiles = 0;
	__state->lsthan = 0;
	*(unsigned char *)__state->eocmrk = '\4';
	*(unsigned char *)__state->eolmrk = '\0';
	for (i__ = 1; i__ <= 5000; ++i__) {
	    __state->filchr[(i__1 = i__ - 1) < 5000 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "filchr", i__1, "dafec_", (
		    ftnlen)446)] = 0;
	    __state->filcnt[(i__1 = i__ - 1) < 5000 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "filcnt", i__1, "dafec_", (
		    ftnlen)447)] = 0;
	    __state->filhan[(i__1 = i__ - 1) < 5000 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "filhan", i__1, "dafec_", (
		    ftnlen)448)] = 0;
	    __state->lstpos[(i__1 = i__ - 1) < 5000 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "lstpos", i__1, "dafec_", (
		    ftnlen)449)] = 0;
	    __state->lstrec[(i__1 = i__ - 1) < 5000 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "lstrec", i__1, "dafec_", (
		    ftnlen)450)] = 0;
	}
    }

/*     Verify that the DAF attached to HANDLE is opened for reading */
/*     by calling the routine to signal an invalid access mode on a */
/*     handle. */

    dafsih_(__global_state, handle, "READ", (ftnlen)4);
    if (failed_(__global_state)) {
	chkout_(__global_state, "DAFEC", (ftnlen)5);
	return 0;
    }

/*     Check for a nonpositive BUFFER size. */

    if (*bufsiz <= 0) {
	setmsg_(__global_state, "The output buffer size was not positive: #.",
		 (ftnlen)43);
	errint_(__global_state, "#", bufsiz, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDARGUMENT)", (ftnlen)22);
	chkout_(__global_state, "DAFEC", (ftnlen)5);
	return 0;
    }

/*     Convert the DAF handle to its corresponding Fortran logical */
/*     unit number for reading the comment records. */

    zzddhhlu_(__global_state, handle, "DAF", &__state->c_false, &daflun, (
	    ftnlen)3);
    if (failed_(__global_state)) {
	chkout_(__global_state, "DAFEC", (ftnlen)5);
	return 0;
    }

/*     Get the length of a single character string in the buffer. */

    linlen = i_len(&__global_state->f2c, buffer, buffer_len);

/*     If we have extracted comments from at least one file and we */
/*     didn't finish, check to see if HANDLE is in the file table. */

    if (__state->nfiles > 0) {
	index = isrchi_(__global_state, handle, &__state->nfiles, 
		__state->filhan);
    } else {
	index = 0;
    }

/*     Check to see if we found HANDLE in the file handle table. If */
/*     we did, INDEX will be > 0. */

    if (index > 0) {

/*        Set the record number and the starting position accordingly, */
/*        i.e., where we left off when we last read from that file. */

	recno = __state->lstrec[(i__1 = index - 1) < 5000 && 0 <= i__1 ? i__1 
		: s_rnge(&__global_state->f2c, "lstrec", i__1, "dafec_", (
		ftnlen)516)];
	curpos = __state->lstpos[(i__1 = index - 1) < 5000 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "lstpos", i__1, "dafec_", 
		(ftnlen)517)];
	nchars = __state->filchr[(i__1 = index - 1) < 5000 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "filchr", i__1, "dafec_", 
		(ftnlen)518)];
	ncomc = __state->filcnt[(i__1 = index - 1) < 5000 && 0 <= i__1 ? i__1 
		: s_rnge(&__global_state->f2c, "filcnt", i__1, "dafec_", (
		ftnlen)519)];
    } else {

/*        We have not yet read any comments from this file, so start at */
/*        the start. To get to the first comment record, we need to skip */
/*        the file record. We also need to count the number of comment */
/*        characters. */

/*        Read the file record from the DAF attached to HANDLE. We will */
/*        get back some stuff that we do not use. */

	dafrfr_(__global_state, handle, &nd, &ni, ifname, &fward, &bward, &
		free, (ftnlen)60);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "DAFEC", (ftnlen)5);
	    return 0;
	}

/*        Compute the number of comment records and the number of */
/*        comment characters. In order to perform these calculations, */
/*        we assume that we have a valid comment area in the DAF */
/*        attached to HANDLE. */

	ncomr = fward - 2;
	if (ncomr > 0) {

/*           The starting record number is the number of comment records */
/*           + 1 where the 1 skips the file record. */

	    empty = TRUE_;
	    found = FALSE_;
	    while(ncomr > 0 && ! found && empty) {
		recno = ncomr + 1;
		__state->io___29.ciunit = daflun;
		__state->io___29.cirec = recno;
		iostat = s_rdue(&__global_state->f2c, &__state->io___29);
		if (iostat != 0) {
		    goto L100001;
		}
		iostat = do_uio(&__global_state->f2c, &__state->c__1, 
			__state->crecrd, (ftnlen)1000);
		if (iostat != 0) {
		    goto L100001;
		}
		iostat = e_rdue(&__global_state->f2c);
L100001:
		if (iostat != 0) {
		    setmsg_(__global_state, "Error reading comment area of b"
			    "inary file named '#'. IOSTAT = #.", (ftnlen)64);
		    errfnm_(__global_state, "#", &daflun, (ftnlen)1);
		    errint_(__global_state, "#", &iostat, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(FILEREADFAILED)", (ftnlen)
			    21);
		    chkout_(__global_state, "DAFEC", (ftnlen)5);
		    return 0;
		}

/*              Scan the comment record looking for the end of comments */
/*              marker. */

		eocpos = cpos_(__global_state, __state->crecrd, 
			__state->eocmrk, &__state->c__1, (ftnlen)1000, (
			ftnlen)1);
		if (eocpos > 0) {
		    found = TRUE_;
		} else {
		    nelpos = ncpos_(__global_state, __state->crecrd, 
			    __state->eolmrk, &__state->c__1, (ftnlen)1000, (
			    ftnlen)1);
		    if (nelpos != 0) {
			empty = FALSE_;
		    } else {
			--ncomr;
		    }
		}
	    }

/*           If we do not find the end of comments marker and the */
/*           comment area is not empty, then it is an error. */

	    if (! found && ! empty) {
		setmsg_(__global_state, "The comment area in the DAF file '#"
			"' may be damaged. The end of the comments could not "
			"be found.", (ftnlen)96);
		errfnm_(__global_state, "#", &daflun, (ftnlen)1);
		sigerr_(__global_state, "SPICE(BADCOMMENTAREA)", (ftnlen)21);
		chkout_(__global_state, "DAFEC", (ftnlen)5);
		return 0;
	    } else if (found) {
		ncomc = (ncomr - 1) * 1000 + eocpos - 1;
	    } else if (empty) {
		ncomc = 0;
	    }
	} else {
	    ncomc = 0;
	}

/*        If the number of comment characters, NCOMC, is equal to zero, */
/*        then we have no comments to read, so set the number of comments */
/*        to zero, set DONE to .TRUE., check out,  and return. */

	if (ncomc == 0) {
	    *n = 0;
	    *done = TRUE_;
	    chkout_(__global_state, "DAFEC", (ftnlen)5);
	    return 0;
	}

/*        Otherwise, set the initial position  in the comment area. */

	recno = 2;
	curpos = 1;
	nchars = 0;
    }

/*     Begin reading the comment area into the buffer. */

    if (*handle != __state->lsthan) {

/*        If the current DAF handle is not the same as the handle on */
/*        the last call, then we need to read in the appropriate record */
/*        from the DAF comment area. Otherwise the record was saved and */
/*        so we don't need to read it in. */

	__state->io___33.ciunit = daflun;
	__state->io___33.cirec = recno;
	iostat = s_rdue(&__global_state->f2c, &__state->io___33);
	if (iostat != 0) {
	    goto L100002;
	}
	iostat = do_uio(&__global_state->f2c, &__state->c__1, __state->crecrd,
		 (ftnlen)1000);
	if (iostat != 0) {
	    goto L100002;
	}
	iostat = e_rdue(&__global_state->f2c);
L100002:
	if (iostat != 0) {
	    setmsg_(__global_state, "Error reading comment area of binary fi"
		    "le named FILE.  IOSTAT = *.", (ftnlen)66);
	    errint_(__global_state, "*", &iostat, (ftnlen)1);
	    errfnm_(__global_state, "FILE", &daflun, (ftnlen)4);
	    sigerr_(__global_state, "SPICE(FILEREADFAILED)", (ftnlen)21);
	    chkout_(__global_state, "DAFEC", (ftnlen)5);
	    return 0;
	}
    }

/*     Initialize the BUFFER line counter, I, and the line position */
/*     counter, J. */

    i__ = 1;
    j = 1;

/*     Start filling up the BUFFER. */

    numcom = 0;
    *done = FALSE_;
    while(i__ <= *bufsiz && ! (*done)) {
	eol = FALSE_;
	while(! eol) {
	    ++nchars;
	    *(unsigned char *)ch = *(unsigned char *)&__state->crecrd[curpos 
		    - 1];
	    if (*(unsigned char *)ch == 0) {
		eol = TRUE_;
		if (j <= linlen) {
		    s_copy(&__global_state->f2c, buffer + ((i__ - 1) * 
			    buffer_len + (j - 1)), " ", buffer_len - (j - 1), 
			    (ftnlen)1);
		}
	    } else {
		if (j <= linlen) {
		    *(unsigned char *)&buffer[(i__ - 1) * buffer_len + (j - 1)
			    ] = *(unsigned char *)ch;
		    ++j;
		} else {
		    setmsg_(__global_state, "The output buffer line length ("
			    "#) was not long enough to contain comment line #."
			    , (ftnlen)80);
		    errint_(__global_state, "#", &linlen, (ftnlen)1);
		    errint_(__global_state, "#", &i__, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(COMMENTTOOLONG)", (ftnlen)
			    21);
		    chkout_(__global_state, "DAFEC", (ftnlen)5);
		    return 0;
		}
	    }

/*           If we have reached the end of the current comment record, */
/*           read in the next one and reset the current position. */
/*           Otherwise, just increment the current position. */

	    if (curpos == 1000) {
		++recno;
		__state->io___38.ciunit = daflun;
		__state->io___38.cirec = recno;
		iostat = s_rdue(&__global_state->f2c, &__state->io___38);
		if (iostat != 0) {
		    goto L100003;
		}
		iostat = do_uio(&__global_state->f2c, &__state->c__1, 
			__state->crecrd, (ftnlen)1000);
		if (iostat != 0) {
		    goto L100003;
		}
		iostat = e_rdue(&__global_state->f2c);
L100003:
		if (iostat != 0) {
		    setmsg_(__global_state, "Error reading comment area of b"
			    "inary file named #.  IOSTAT = #.", (ftnlen)63);
		    errfnm_(__global_state, "#", &daflun, (ftnlen)1);
		    errint_(__global_state, "#", &iostat, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(FILEREADFAILED)", (ftnlen)
			    21);
		    chkout_(__global_state, "DAFEC", (ftnlen)5);
		    return 0;
		}
		curpos = 1;
	    } else {
		++curpos;
	    }

/*           Check to make sure that it is safe to continue, i.e., */
/*           that the number of comment characters we have processed */
/*           has not exceeded the number of comment characters in the */
/*           comment area of the DAF file. This should never happen. */

	    if (nchars > ncomc) {
		setmsg_(__global_state, "Count of comment characters (#) exc"
			"eeds the number of comment characters (#) in the DAF"
			" file #.", (ftnlen)95);
		errint_(__global_state, "#", &nchars, (ftnlen)1);
		errint_(__global_state, "#", &ncomc, (ftnlen)1);
		errfnm_(__global_state, "#", &daflun, (ftnlen)1);
		sigerr_(__global_state, "SPICE(BADCOMMENTAREA)", (ftnlen)21);
		chkout_(__global_state, "DAFEC", (ftnlen)5);
		return 0;
	    }
	}

/*        We have just completed a comment line, so we save the comment */
/*        number, increment the buffer line counter, I, and reset the */
/*        buffer line position counter, J. */

	numcom = i__;
	++i__;
	j = 1;

/*        Check for the end of the comments. */

	if (nchars == ncomc) {

/*           If we have reached the end of the comments, signaled */
/*           by having processed all of the comment characters, NCOMC, */
/*           then we are done. So, set DONE to .TRUE. and remove the */
/*           entry for this file from the file table. */

	    *done = TRUE_;
	    __state->lsthan = 0;

/*           0 <= INDEX <= NFILES, and we only want to remove things */
/*           from the file table if: */

/*              The file we are currently reading from is in the */
/*              file table, INDEX > 0, which implies NFILES > 0. */

/*           So, if INDEX > 0, we know that there are files in the file */
/*           table, and that we are currently reading from one of them. */

	    if (index > 0) {
		i__1 = __state->nfiles - 1;
		for (k = index; k <= i__1; ++k) {
		    __state->filchr[(i__2 = k - 1) < 5000 && 0 <= i__2 ? i__2 
			    : s_rnge(&__global_state->f2c, "filchr", i__2, 
			    "dafec_", (ftnlen)811)] = __state->filchr[(i__3 = 
			    k) < 5000 && 0 <= i__3 ? i__3 : s_rnge(&
			    __global_state->f2c, "filchr", i__3, "dafec_", (
			    ftnlen)811)];
		    __state->filcnt[(i__2 = k - 1) < 5000 && 0 <= i__2 ? i__2 
			    : s_rnge(&__global_state->f2c, "filcnt", i__2, 
			    "dafec_", (ftnlen)812)] = __state->filcnt[(i__3 = 
			    k) < 5000 && 0 <= i__3 ? i__3 : s_rnge(&
			    __global_state->f2c, "filcnt", i__3, "dafec_", (
			    ftnlen)812)];
		    __state->filhan[(i__2 = k - 1) < 5000 && 0 <= i__2 ? i__2 
			    : s_rnge(&__global_state->f2c, "filhan", i__2, 
			    "dafec_", (ftnlen)813)] = __state->filhan[(i__3 = 
			    k) < 5000 && 0 <= i__3 ? i__3 : s_rnge(&
			    __global_state->f2c, "filhan", i__3, "dafec_", (
			    ftnlen)813)];
		    __state->lstrec[(i__2 = k - 1) < 5000 && 0 <= i__2 ? i__2 
			    : s_rnge(&__global_state->f2c, "lstrec", i__2, 
			    "dafec_", (ftnlen)814)] = __state->lstrec[(i__3 = 
			    k) < 5000 && 0 <= i__3 ? i__3 : s_rnge(&
			    __global_state->f2c, "lstrec", i__3, "dafec_", (
			    ftnlen)814)];
		    __state->lstpos[(i__2 = k - 1) < 5000 && 0 <= i__2 ? i__2 
			    : s_rnge(&__global_state->f2c, "lstpos", i__2, 
			    "dafec_", (ftnlen)815)] = __state->lstpos[(i__3 = 
			    k) < 5000 && 0 <= i__3 ? i__3 : s_rnge(&
			    __global_state->f2c, "lstpos", i__3, "dafec_", (
			    ftnlen)815)];
		}
		--__state->nfiles;
	    }
	}
    }

/*     Set the number of comment lines in the buffer */

    *n = numcom;

/*     At this point, we have either filled the buffer or we have */
/*     finished reading in the comment area. Find out what has */
/*     happened and act accordingly. */

    if (! (*done)) {

/*        If we are not done, then we have filled the buffer, so save */
/*        everything that needs to be saved in the file table before */
/*        exiting. */

	if (index == 0) {

/*           This was the first time that the comment area of this file */
/*           has been read, so add it to the file table and save all of */
/*           its information if there is room in the file table. */

	    if (__state->nfiles >= 5000) {
		setmsg_(__global_state, "The file table is full with # files"
			", and another file could not be added.", (ftnlen)73);
		errint_(__global_state, "#", &__state->c__5000, (ftnlen)1);
		sigerr_(__global_state, "SPICE(FILETABLEFULL)", (ftnlen)20);
		chkout_(__global_state, "DAFEC", (ftnlen)5);
		return 0;
	    }
	    ++__state->nfiles;
	    __state->filchr[(i__1 = __state->nfiles - 1) < 5000 && 0 <= i__1 ?
		     i__1 : s_rnge(&__global_state->f2c, "filchr", i__1, 
		    "dafec_", (ftnlen)859)] = nchars;
	    __state->filcnt[(i__1 = __state->nfiles - 1) < 5000 && 0 <= i__1 ?
		     i__1 : s_rnge(&__global_state->f2c, "filcnt", i__1, 
		    "dafec_", (ftnlen)860)] = ncomc;
	    __state->filhan[(i__1 = __state->nfiles - 1) < 5000 && 0 <= i__1 ?
		     i__1 : s_rnge(&__global_state->f2c, "filhan", i__1, 
		    "dafec_", (ftnlen)861)] = *handle;
	    __state->lstrec[(i__1 = __state->nfiles - 1) < 5000 && 0 <= i__1 ?
		     i__1 : s_rnge(&__global_state->f2c, "lstrec", i__1, 
		    "dafec_", (ftnlen)862)] = recno;
	    __state->lstpos[(i__1 = __state->nfiles - 1) < 5000 && 0 <= i__1 ?
		     i__1 : s_rnge(&__global_state->f2c, "lstpos", i__1, 
		    "dafec_", (ftnlen)863)] = curpos;
	    __state->lsthan = *handle;
	} else {

/*           The comment area of this file is already in the file table, */
/*           so just update its information. */

	    __state->filchr[(i__1 = index - 1) < 5000 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "filchr", i__1, "dafec_", (
		    ftnlen)871)] = nchars;
	    __state->lstrec[(i__1 = index - 1) < 5000 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "lstrec", i__1, "dafec_", (
		    ftnlen)872)] = recno;
	    __state->lstpos[(i__1 = index - 1) < 5000 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "lstpos", i__1, "dafec_", (
		    ftnlen)873)] = curpos;
	    __state->lsthan = *handle;
	}
    }
    chkout_(__global_state, "DAFEC", (ftnlen)5);
    return 0;
} /* dafec_ */

