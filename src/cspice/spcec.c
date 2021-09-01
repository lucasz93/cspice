/* spcec.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern spcec_init_t __spcec_init;
static spcec_state_t* get_spcec_state(cspice_t* state) {
	if (!state->spcec)
		state->spcec = __cspice_allocate_module(sizeof(spcec_state_t),
	 &__spcec_init, sizeof(__spcec_init));
	return state->spcec;

}

/* $Procedure SPCEC ( SPK and CK, extract comments ) */
/* Subroutine */ int spcec_(cspice_t* __global_state, integer *handle, 
	integer *unit)
{
    /* System generated locals */
    integer i__1;
    cilist ci__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer s_rdue(f2c_state_t*, cilist *), do_uio(f2c_state_t*, integer *, 
	    char *, ftnlen), e_rdue(f2c_state_t*), s_wsle(f2c_state_t*, 
	    cilist *), e_wsle(f2c_state_t*), s_wsfe(f2c_state_t*, cilist *), 
	    do_fio(f2c_state_t*, integer *, char *, ftnlen), e_wsfe(
	    f2c_state_t*);

    /* Local variables */
    integer dafu;
    integer free;
    char line[1000];
    char null[1];
    extern /* Subroutine */ int zzddhhlu_(cspice_t*, integer *, char *, 
	    logical *, integer *, ftnlen);
    integer c__;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer bward;
    integer fward;
    integer nd;
    extern logical failed_(cspice_t*);
    integer ni;
    extern /* Subroutine */ int dafsih_(cspice_t*, integer *, char *, ftnlen);
    char ifname[60];
    extern /* Subroutine */ int dafrfr_(cspice_t*, integer *, integer *, 
	    integer *, char *, integer *, integer *, integer *, ftnlen);
    char record[1000];
    extern /* Subroutine */ int errfnm_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    integer iostat;
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);
    integer rec;
    char eot[1];
    integer nrr;
    integer pos;

    /* Fortran I/O blocks */



    /* Module state */
    spcec_state_t* __state = get_spcec_state(__global_state);
/* $ Abstract */

/*     Extract the text from the comment area of a binary SPK or CK file */
/*     and write it to a text file. */

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
/*     UNIT       I   Logical unit connected to text file. */

/* $ Detailed_Input */

/*     HANDLE      is the handle assigned to the binary SPK or CK file */
/*                 which has been opened for read access. */

/*     UNIT        is the logical unit connected to the text file to */
/*                 which the contents of the comment area of the SPK */
/*                 or CK file will be written, beginning at the current */
/*                 position of the file pointer. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If the comment area of the SPK or CK file is empty, nothing */
/*        will be written to the text file. */

/*     2) If there is a problem reading from the comment area, the error */
/*        SPICE(FILEREADFAILED) is signalled. */

/*     3) If there is a problem writing to the text file, the error */
/*        SPICE(FILEWRITEFAILED) is signalled. */

/* $ Files */

/*     HANDLE      is the handle assigned to the binary SPK or CK file. */
/*                 Use DAFOPR to open it for read access and get its */
/*                 handle unless SPKLEF or CKLPF has already been called */
/*                 and returned the handle.  This file is unchanged by */
/*                 calling SPCEC. */

/*     UNIT        is the logical unit connected to the text file which */
/*                 has been opened for write access.  Use TXTOPN to */
/*                 open the file and get its logical unit.  Upon exit, */
/*                 this file will contain the text from the comment */
/*                 area of the binary SPK or CK file, beginning at */
/*                 the line that was the position of the file pointer */
/*                 when SPCEC was called.  In other words, SPCEC does */
/*                 not rewind or backspace this file before writing */
/*                 the text to it. */

/* $ Particulars */

/*     The structure of SPK and CK files accommodates comments in */
/*     addition to data.  The following three routines are available */
/*     for accessing the comment area of a binary SPK or CK file: */

/*           SPCAC           add comments */

/*           SPCEC           extract comments */

/*           SPCDC           delete comments */

/*     Note that comments must consist of only text, that is, printable */
/*     ASCII characters, specifically ASCII 32-126.  This excludes */
/*     tabs (ASCII 9) and control characters. */

/*     The SPC conversion routines---SPCB2A, SPCA2B, SPCB2T, and */
/*     SPCT2B---include these comments when converting SPK and CK */
/*     files between binary and text formats. */

/* $ Examples */

/*     Suppose we have a binary SPK file called A.BSP.  The following */
/*     code fragment stores the contents of the comment area of A.BSP */
/*     in a text file called COMMENTS.TXT and surrounds the comments */
/*     with markers. */

/*            CALL DAFOPR ( 'A.BSP', HANDLE ) */

/*            CALL TXTOPN ( 'COMMENTS.TXT', UNIT ) */

/*            WRITE (UNIT,*) '\begincomments' */

/*            CALL SPCEC  ( HANDLE, UNIT ) */

/*            WRITE (UNIT,*) '\endcomments' */

/* $ Restrictions */

/*     1)  Use TXTOPN to open new text files and get their logical unit. */
/*         There are system dependencies regarding opening text files, */
/*         and these have been isolated in the routines TXTOPN and */
/*         TXTOPR. */

/*     2)  This routine assumes that the comment area of the binary SPK */
/*         or CK file contains only text stored by SPCAC.  Comments */
/*         written any other way may not be handled properly. */

/*     3) This routine is only used to read records on environments */
/*        whose characters are a single byte in size.  Updates */
/*        to this routine and routines in its call tree may be */
/*        required to properly handle other cases. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     J.E. McLean (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (FST) */

/*        Updated this routine to utilize new handle manager */
/*        interfaces. */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 05-APR-1991 (JEM) */

/* -& */
/* $ Index_Entries */

/*     extract comments from spk or ck file */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (FST) */

/*        The call to DAFHLU has been replaced with a call to */
/*        ZZDDHHLU, the handle manager interface for retrieving */
/*        a logical unit.  DAFHLU is no longer used, since it */
/*        locks the unit returned to its HANDLE, tying up resources */
/*        in the handle manager.  A call to DAFSIH was inserted to */
/*        make certain that HANDLE is present in DAFAH's file table. */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */

/*     IFNLEN      is the length of a DAF internal file name. */

/*     MAXCPR      is the maximum number of characters per DAF record and */
/*                 hence the maximum comment line length. */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "SPCEC", (ftnlen)5);
    }

/*     First, check to see if HANDLE is a legitimate DAF handle. */

    dafsih_(__global_state, handle, "READ", (ftnlen)4);
    if (failed_(__global_state)) {
	chkout_(__global_state, "SPCEC", (ftnlen)5);
	return 0;
    }

/*     Read the file record to find out if the DAF contains any */
/*     reserved records.  The reserved records in an array file */
/*     are stored between the first record and the first summary */
/*     record.  FWARD is the record number of that first summary */
/*     record, and NRR is the number of reserved records in the file. */
/*     If there are no reserved records, there's nothing to be done. */

    dafrfr_(__global_state, handle, &nd, &ni, ifname, &fward, &bward, &free, (
	    ftnlen)60);
    nrr = fward - 2;
    if (nrr == 0) {
	chkout_(__global_state, "SPCEC", (ftnlen)5);
	return 0;
    }

/*     We need to read directly from the SPK or CK file, using a logical */
/*     unit instead of a handle. */

    zzddhhlu_(__global_state, handle, "DAF", &__state->c_false, &dafu, (
	    ftnlen)3);
    if (failed_(__global_state)) {
	chkout_(__global_state, "SPCEC", (ftnlen)5);
	return 0;
    }

/*     Load the contents of the reserved records into individual lines, */
/*     for printing.  Keep adding characters to the current line until */
/*     it has been filled, then write it to the text file, and */
/*     begin a new line. */

/*     In the comment area, NULL means end-of-line, and EOT means */
/*     end-of-transmission, or in other words, end-of-comments. */

    *(unsigned char *)null = '\0';
    *(unsigned char *)eot = '\4';
    s_copy(&__global_state->f2c, line, " ", (ftnlen)1000, (ftnlen)1);
    s_copy(&__global_state->f2c, record, " ", (ftnlen)1000, (ftnlen)1);
    pos = 0;
    i__1 = nrr;
    for (rec = 1; rec <= i__1; ++rec) {
	__state->io___16.ciunit = dafu;
	__state->io___16.cirec = rec + 1;
	iostat = s_rdue(&__global_state->f2c, &__state->io___16);
	if (iostat != 0) {
	    goto L100001;
	}
	iostat = do_uio(&__global_state->f2c, &__state->c__1, record, (ftnlen)
		1000);
	if (iostat != 0) {
	    goto L100001;
	}
	iostat = e_rdue(&__global_state->f2c);
L100001:
	if (iostat != 0) {
	    setmsg_(__global_state, "Error reading comment area of the binar"
		    "y file named FNM.  Value of IOSTAT is #.", (ftnlen)79);
	    errint_(__global_state, "#", &iostat, (ftnlen)1);
	    errfnm_(__global_state, "FNM", &dafu, (ftnlen)3);
	    sigerr_(__global_state, "SPICE(FILEREADFAILED)", (ftnlen)21);
	    chkout_(__global_state, "SPCEC", (ftnlen)5);
	    return 0;
	}
	for (c__ = 1; c__ <= 1000; ++c__) {

/*           End-of-transmission means we're done. */

	    if (*(unsigned char *)&record[c__ - 1] == *(unsigned char *)eot) {
		chkout_(__global_state, "SPCEC", (ftnlen)5);
		return 0;

/*           NULL means that the current line is ready to be written to */
/*           the text file.  The end-of-line character itself does not */
/*           get written.  After this, the current line should be empty */
/*           again. */

	    } else if (*(unsigned char *)&record[c__ - 1] == *(unsigned char *
		    )null) {
		if (pos == 0) {
		    __state->io___18.ciunit = *unit;
		    iostat = s_wsle(&__global_state->f2c, &__state->io___18);
		    if (iostat != 0) {
			goto L100002;
		    }
		    iostat = e_wsle(&__global_state->f2c);
L100002:
		    ;
		} else {
		    ci__1.cierr = 1;
		    ci__1.ciunit = *unit;
		    ci__1.cifmt = "(A)";
		    iostat = s_wsfe(&__global_state->f2c, &ci__1);
		    if (iostat != 0) {
			goto L100003;
		    }
		    iostat = do_fio(&__global_state->f2c, &__state->c__1, 
			    line, pos);
		    if (iostat != 0) {
			goto L100003;
		    }
		    iostat = e_wsfe(&__global_state->f2c);
L100003:
		    ;
		}
		if (iostat != 0) {
		    setmsg_(__global_state, "Error writing to the text file "
			    "named FNM.  Value of IOSTAT is #.", (ftnlen)64);
		    errint_(__global_state, "#", &iostat, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(FILEWRITEFAILED)", (ftnlen)
			    22);
		    chkout_(__global_state, "SPCEC", (ftnlen)5);
		    return 0;
		}
		s_copy(&__global_state->f2c, line, " ", (ftnlen)1000, (ftnlen)
			1);
		pos = 0;

/*           If this a normal character, add it to the current line. */

	    } else {
		++pos;
		*(unsigned char *)&line[pos - 1] = *(unsigned char *)&record[
			c__ - 1];
	    }
	}
    }
    chkout_(__global_state, "SPCEC", (ftnlen)5);
    return 0;
} /* spcec_ */

