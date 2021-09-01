/* daft2b.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern daft2b_init_t __daft2b_init;
static daft2b_state_t* get_daft2b_state(cspice_t* state) {
	if (!state->daft2b)
		state->daft2b = __cspice_allocate_module(sizeof(
	daft2b_state_t), &__daft2b_init, sizeof(__daft2b_init));
	return state->daft2b;

}

/* $Procedure DAFT2B ( DAF, text to binary ) */
/* Subroutine */ int daft2b_(cspice_t* __global_state, integer *text, char *
	binary, integer *resv, ftnlen binary_len)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer s_rsle(f2c_state_t*, cilist *), do_lio(f2c_state_t*, integer *, 
	    integer *, char *, ftnlen), e_rsle(f2c_state_t*), s_cmp(
	    f2c_state_t*, char *, char *, ftnlen, ftnlen), s_rnge(f2c_state_t*
	    , char *, integer, char *, integer);

    /* Local variables */
    char name__[1000*2];
    integer more;
    integer i__;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int dafps_(cspice_t*, integer *, integer *, 
	    doublereal *, integer *, doublereal *);
    char tarch[8];
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    integer chunk;
    integer isize;
    integer lsize;
    char ttype[8];
    extern /* Subroutine */ int idw2at_(cspice_t*, char *, char *, char *, 
	    ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int dafada_(cspice_t*, doublereal *, integer *);
    doublereal dc[125];
    extern /* Subroutine */ int dafbna_(cspice_t*, integer *, doublereal *, 
	    char *, ftnlen);
    integer ic[250];
    extern /* Subroutine */ int dafena_(cspice_t*);
    integer nd;
    extern logical failed_(cspice_t*);
    integer ni;
    integer handle;
    extern /* Subroutine */ int dafcls_(cspice_t*, integer *);
    char ifname[60*2];
    extern /* Subroutine */ int dafopn_(cspice_t*, char *, integer *, integer 
	    *, char *, integer *, integer *, ftnlen, ftnlen);
    doublereal buffer[1024];
    char idword[8];
    extern /* Subroutine */ int errfnm_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    integer iostat;
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);
    doublereal sum[125];

    /* Fortran I/O blocks */



    /* Module state */
    daft2b_state_t* __state = get_daft2b_state(__global_state);
/* $ Abstract */

/*     Deprecated. The routine DAFTB supersedes this routine. */
/*     NAIF supports this routine only to provide backward */
/*     compatibility. */

/*     Reconstruct a binary DAF from a text file opened by */
/*     the calling program. */

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
/*     TEXT       I   Logical unit connected to text file. */
/*     BINARY     I   Name of a binary DAF to be created. */
/*     RESV       I   Number of records to reserve. */
/*     BSIZE      P   Buffer size. */

/* $ Detailed_Input */

/*     TEXT        is a logical unit number, to which a text file has */
/*                 been connected by the calling program, and into */
/*                 which the contents of binary DAF have been */
/*                 written. The file pointer should be placed just */
/*                 before the file ID word. */

/*     BINARY      is the name of a binary DAF to be created. */
/*                 The binary DAF contains the same data as the */
/*                 text file, but in a form more suitable for use */
/*                 by application programs. */

/*     RESV        is the number of records to be reserved in the */
/*                 binary DAF. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     BSIZE       is the size of the buffer used to read array elements */
/*                 from the text file. No single group of elements should */
/*                 contains more than BSIZE elements. */

/* $ Exceptions */

/*     1) If for some reason the text file cannot be read, */
/*        the error SPICE(DAFREADFAIL) is signalled. */

/*     2) If the architecture of the file is not DAF, as specified by */
/*        the ID word, the error SPICE(NOTADAFFILE) will be signalled. */

/*     3) If the text file does not contain matching internal file */
/*        names, the error SPICE(DAFNOIFNMATCH) is signalled. */

/*     4) If the text file does not contain matching array names, */
/*        the error SPICE(DAFNONAMEMATCH) is signalled. */

/*     5) If the buffer size is not sufficient, the error */
/*        SPICE(DAFOVERFLOW) is signalled. */

/* $ Files */

/*     See arguments TEXT, BINARY. */

/* $ Particulars */

/*     This routine has been made obsolete by the new DAF text to binary */
/*     conversion routine DAFTB. This routine remains available for */
/*     reasons of backward compatibility. We strongly recommend that you */
/*     use the new conversion routines for any new software development. */
/*     Please see the header of the routine DAFTB for details. */

/*     This routine is necessary for converting older DAF text files into */
/*     their equivalent binary formats, as DAFTB uses a different text */
/*     file format that is incompatible with the text file format */
/*     expected by this routine. */

/*     Any binary DAF may be transferred between heterogeneous */
/*     Fortran environments by converting it to an equivalent file */
/*     containing only ASCII characters. Such a file can be transferred */
/*     almost universally, using any number of established protocols */
/*     (Kermit, FTP, and so on). Once transferred, the ASCII file can */
/*     be reconverted to a binary DAF, using the representations */
/*     native to the new host environment. */

/*     There are two pairs of routines that can be used to convert */
/*     DAFs between binary and ASCII. The first pair, DAFB2A */
/*     and DAFA2B, works with complete files. That is, DAFB2A creates */
/*     a complete ASCII file containing all of the information in */
/*     a particular binary DAF, and nothing else; this file can */
/*     be fed directly into DAFA2B to produce a complete binary DAF. */
/*     In each case, the names of the files are specified. */

/*     A related pair of routines, DAFB2T and DAFT2B, assume that */
/*     the ASCII data are to be stored in the midst of a text file. */
/*     This allows the calling program to surround the data with */
/*     standardized labels, to append several binary DAFs into a */
/*     single text file, and so on. */

/*     Note that you must select the number of records to be reserved */
/*     in the binary DAF. The contents of reserved records are ignored */
/*     by the normal transfer process. */

/* $ Examples */

/*     DAFB2A and DAFA2B are typically used for simple transfers. */
/*     If A.DAF is a binary DAF in environment 1, it can be transferred */
/*     to environment 2 in three steps. */

/*        1) Convert it to ASCII: */

/*              CALL DAFB2A ( 'A.DAF', 'A.ASCII' ) */

/*        2) Transfer the ASCII file, using FTP, Kermit, or some other */
/*           file transfer utility: */

/*              ftp> put a.ascii */

/*        3) Convert it to binary on the new machine, */

/*              CALL DAFA2B ( 'A.ASCII', 'A.DAF', RESV ) */

/*     Note that DAFB2A and DAFA2B work in any standard Fortran-77 */
/*     environment. */

/*     If the file needs to contain other information---a standard */
/*     label, for instance---the first and third steps must be modified */
/*     to use DAFB2T and DAFT2B. The first step becomes */

/*        (Open a text file) */
/*        (Write the label) */
/*        CALL DAFB2T ( BINARY, UNIT  ) */
/*        (Close the text file) */

/*     The third step becomes */

/*        (Open the text file) */
/*        (Read the label) */
/*        CALL DAFT2B ( UNIT, BINARY, RESV ) */
/*        (Close the text file) */

/* $ Restrictions */

/*     DAFT2B cannot be executed while any other DAF is open */
/*     for writing. */

/* $ Literature_References */

/*     NAIF Document 167.0, "Double Precision Array Files (DAF) */
/*     Specification and User's Guide" */

/* $ Author_and_Institution */

/*     K. R. Gehringer (JPL) */
/*     J.E. McLean     (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 3.0.1, 26-JUL-2012 (EDW) */

/*        Edited Abstract section to use "Deprecated" keyword */
/*        and state replacement routine. */

/*        Eliminated unneeded Revisions section. */

/* -    SPICELIB Version 3.0.0, 04-OCT-1993 (KRG) */

/*        Removed the error SPICE(DAFNOIDWORD) as it was no longer */
/*        relevant. */

/*        Added the error SPICE(NOTADAFFILE) if this routine is called */
/*        with a file that does not contain an ID word identifying the */
/*        file as a DAF file. */

/*        There were no checks of the IOSTAT variable after attempting to */
/*        read from the text file, a single test of the IOSTAT variable */
/*        was made at the end of the routine. This was not adequate to */
/*        detect errors when writing to the text file. So after all of */
/*        these read statements, an IF ... END IF block was added to */
/*        signal an error if IOSTAT .NE. 0. */

/*            IF ( IOSTAT .NE. 0 ) THEN */

/*               CALL SETMSG ( 'The attempt to read from file ''#''' // */
/*         .                   ' failed. IOSTAT = #.'                 ) */
/*               CALL ERRFNM ( '#', UNIT                              ) */
/*               CALL SIGERR ( 'SPICE(DAFREADFAIL)'                   ) */
/*               CALL CHKOUT ( 'DAFT2B'                               ) */
/*               RETURN */

/*            END IF */

/*        Removed the code from the end of the routine that purported to */
/*        check for read errors: */

/*            C */
/*            C     If any read screws up, they should all screw up. Why */
/*            C     make a billion separate checks? */
/*            C */
/*                  IF ( IOSTAT .NE. 0 ) THEN */
/*                     CALL SETMSG ( 'Value of IOSTAT was: #. ' ) */
/*                     CALL ERRINT ( '#', IOSTAT                ) */
/*                     CALL SIGERR ( 'SPICE(DAFREADFAIL)'       ) */
/*                   END IF */

/*        The answer to the question is: */

/*            You have to do a billion separate checks because the IOSTAT */
/*            value is only valid for the most recently executed read. */

/*        Added a statment to the $ Particulars section to the effect */
/*        that this routine has been made obsolete by the introduction of */
/*        the routine DAFTB, and that we strongly recommend the use of */
/*        the new routine. This routine must, however, be used when */
/*        converting older text files to binary, as the old and new */
/*        formats are not compatible. */

/*        Modified the $ Abstract section to reflect the fact that this */
/*        routine is obsolete and maintained for purposes of backward */
/*        compatibility only. */

/* -    SPICELIB Version 2.0.2, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 2.0.1,  6-AUG-1990 (HAN) */

/*        Header documentation was corrected. This routine will */
/*        convert a file containing either ID word, 'NAIF/DAF' or */
/*        'NAIF/NIP'. (Previous versions of SPICELIB software used */
/*        the ID word 'NAIF/NIP'.) */

/* -    SPICELIB Version 2.0.0,  2-AUG-1990 (JEM) */

/*        The previous version of this routine always failed and */
/*        signalled the error SPICE(DAFNOIDWORD) because of a faulty */
/*        logical expression in an error-checking IF statement. */
/*        The error SPICE(DAFNOIDWORD) should be signalled if the */
/*        next non-blank line in the text file does not begin with the */
/*        word 'NAIF/DAF' AND does not begin with the word 'NAIF/NIP'. */
/*        Previously the logic was incorrect causing the error to be */
/*        signalled every time no matter what the word was. The */
/*        correction consisted of replacing '.OR.' with '.AND.' */
/*        in the logical expression. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     text daf to binary */

/* -& */

/*     SPICELIB functions */


/*     Local Parameters */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "DAFT2B", (ftnlen)6);
    }
    s_copy(&__global_state->f2c, idword, " ", (ftnlen)8, (ftnlen)1);
    s_copy(&__global_state->f2c, tarch, " ", (ftnlen)8, (ftnlen)1);
    s_copy(&__global_state->f2c, ttype, " ", (ftnlen)8, (ftnlen)1);

/*     We should be positioned and ready to read the file ID word from */
/*     the text file, so let's try it. */

    __state->io___5.ciunit = *text;
    iostat = s_rsle(&__global_state->f2c, &__state->io___5);
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_lio(&__global_state->f2c, &__state->c__9, &__state->c__1, 
	    idword, (ftnlen)8);
    if (iostat != 0) {
	goto L100001;
    }
    iostat = e_rsle(&__global_state->f2c);
L100001:
    if (iostat != 0) {
	setmsg_(__global_state, "The attempt to read from file '#' failed. I"
		"OSTAT = #.", (ftnlen)53);
	errfnm_(__global_state, "#", text, (ftnlen)1);
	errint_(__global_state, "#", &iostat, (ftnlen)1);
	sigerr_(__global_state, "SPICE(DAFREADFAIL)", (ftnlen)18);
	chkout_(__global_state, "DAFT2B", (ftnlen)6);
	return 0;
    }

/*     Split the ID word into an architecture and type, and verify that */
/*     the architecture is 'DAF'. If it is not, this is the wrong */
/*     routine, and an error will be signalled. */

    idw2at_(__global_state, idword, tarch, ttype, (ftnlen)8, (ftnlen)8, (
	    ftnlen)8);
    if (s_cmp(&__global_state->f2c, tarch, "DAF", (ftnlen)8, (ftnlen)3) != 0) 
	    {
	setmsg_(__global_state, "File architecture is not 'DAF' for file '#'",
		 (ftnlen)43);
	errfnm_(__global_state, "#", text, (ftnlen)1);
	sigerr_(__global_state, "SPICE(NOTADAFFILE)", (ftnlen)18);
	chkout_(__global_state, "DAFT2B", (ftnlen)6);
	return 0;
    }
    __state->io___6.ciunit = *text;
    iostat = s_rsle(&__global_state->f2c, &__state->io___6);
    if (iostat != 0) {
	goto L100002;
    }
    iostat = do_lio(&__global_state->f2c, &__state->c__3, &__state->c__1, (
	    char *)&nd, (ftnlen)sizeof(integer));
    if (iostat != 0) {
	goto L100002;
    }
    iostat = do_lio(&__global_state->f2c, &__state->c__3, &__state->c__1, (
	    char *)&ni, (ftnlen)sizeof(integer));
    if (iostat != 0) {
	goto L100002;
    }
    iostat = do_lio(&__global_state->f2c, &__state->c__9, &__state->c__1, 
	    ifname, (ftnlen)60);
    if (iostat != 0) {
	goto L100002;
    }
    iostat = e_rsle(&__global_state->f2c);
L100002:
    if (iostat != 0) {
	setmsg_(__global_state, "The attempt to read from file '#' failed. I"
		"OSTAT = #.", (ftnlen)53);
	errfnm_(__global_state, "#", text, (ftnlen)1);
	errint_(__global_state, "#", &iostat, (ftnlen)1);
	sigerr_(__global_state, "SPICE(DAFREADFAIL)", (ftnlen)18);
	chkout_(__global_state, "DAFT2B", (ftnlen)6);
	return 0;
    }

/*     Open the new binary file. */

    dafopn_(__global_state, binary, &nd, &ni, ifname, resv, &handle, 
	    binary_len, (ftnlen)60);
    if (failed_(__global_state)) {
	chkout_(__global_state, "DAFT2B", (ftnlen)6);
	return 0;
    }

/*     Each array is preceded by a '1', which indicates that more */
/*     arrays are to come. The array itself begins with the name */
/*     and the summary components, and ends with the name again. */
/*     The contents are written in arbitrary chunks. The final */
/*     chunk is followed by a '0', which indicates that no chunks */
/*     remain. The names must match, or the array should not */
/*     be terminated normally. */

/*     If the chunks in the file are bigger than the local buffer */
/*     size, we are in trouble. */

    lsize = nd + (ni - 1) / 2 + 1;
    isize = lsize << 3;
    __state->io___13.ciunit = *text;
    iostat = s_rsle(&__global_state->f2c, &__state->io___13);
    if (iostat != 0) {
	goto L100003;
    }
    iostat = do_lio(&__global_state->f2c, &__state->c__3, &__state->c__1, (
	    char *)&more, (ftnlen)sizeof(integer));
    if (iostat != 0) {
	goto L100003;
    }
    iostat = e_rsle(&__global_state->f2c);
L100003:
    if (iostat != 0) {
	dafcls_(__global_state, &handle);
	setmsg_(__global_state, "The attempt to read from file '#' failed. I"
		"OSTAT = #.", (ftnlen)53);
	errfnm_(__global_state, "#", text, (ftnlen)1);
	errint_(__global_state, "#", &iostat, (ftnlen)1);
	sigerr_(__global_state, "SPICE(DAFREADFAIL)", (ftnlen)18);
	chkout_(__global_state, "DAFT2B", (ftnlen)6);
	return 0;
    }
    while(more > 0) {
	__state->io___15.ciunit = *text;
	iostat = s_rsle(&__global_state->f2c, &__state->io___15);
	if (iostat != 0) {
	    goto L100004;
	}
	iostat = do_lio(&__global_state->f2c, &__state->c__9, &__state->c__1, 
		name__, isize);
	if (iostat != 0) {
	    goto L100004;
	}
	iostat = e_rsle(&__global_state->f2c);
L100004:
	if (iostat != 0) {
	    dafcls_(__global_state, &handle);
	    setmsg_(__global_state, "The attempt to read from file '#' faile"
		    "d. IOSTAT = #.", (ftnlen)53);
	    errfnm_(__global_state, "#", text, (ftnlen)1);
	    errint_(__global_state, "#", &iostat, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(DAFREADFAIL)", (ftnlen)18);
	    chkout_(__global_state, "DAFT2B", (ftnlen)6);
	    return 0;
	}
	__state->io___17.ciunit = *text;
	iostat = s_rsle(&__global_state->f2c, &__state->io___17);
	if (iostat != 0) {
	    goto L100005;
	}
	i__1 = nd;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    iostat = do_lio(&__global_state->f2c, &__state->c__5, &
		    __state->c__1, (char *)&dc[(i__2 = i__ - 1) < 125 && 0 <= 
		    i__2 ? i__2 : s_rnge(&__global_state->f2c, "dc", i__2, 
		    "daft2b_", (ftnlen)465)], (ftnlen)sizeof(doublereal));
	    if (iostat != 0) {
		goto L100005;
	    }
	}
	iostat = e_rsle(&__global_state->f2c);
L100005:
	if (iostat != 0) {
	    dafcls_(__global_state, &handle);
	    setmsg_(__global_state, "The attempt to read from file '#' faile"
		    "d. IOSTAT = #.", (ftnlen)53);
	    errfnm_(__global_state, "#", text, (ftnlen)1);
	    errint_(__global_state, "#", &iostat, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(DAFREADFAIL)", (ftnlen)18);
	    chkout_(__global_state, "DAFT2B", (ftnlen)6);
	    return 0;
	}
	__state->io___20.ciunit = *text;
	iostat = s_rsle(&__global_state->f2c, &__state->io___20);
	if (iostat != 0) {
	    goto L100006;
	}
	i__2 = ni - 2;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    iostat = do_lio(&__global_state->f2c, &__state->c__3, &
		    __state->c__1, (char *)&ic[(i__1 = i__ - 1) < 250 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "ic", i__1, 
		    "daft2b_", (ftnlen)480)], (ftnlen)sizeof(integer));
	    if (iostat != 0) {
		goto L100006;
	    }
	}
	iostat = e_rsle(&__global_state->f2c);
L100006:
	if (iostat != 0) {
	    dafcls_(__global_state, &handle);
	    setmsg_(__global_state, "The attempt to read from file '#' faile"
		    "d. IOSTAT = #.", (ftnlen)53);
	    errfnm_(__global_state, "#", text, (ftnlen)1);
	    errint_(__global_state, "#", &iostat, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(DAFREADFAIL)", (ftnlen)18);
	    chkout_(__global_state, "DAFT2B", (ftnlen)6);
	    return 0;
	}
	dafps_(__global_state, &nd, &ni, dc, ic, sum);
	dafbna_(__global_state, &handle, sum, name__, isize);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "DAFT2B", (ftnlen)6);
	    return 0;
	}
	__state->io___23.ciunit = *text;
	iostat = s_rsle(&__global_state->f2c, &__state->io___23);
	if (iostat != 0) {
	    goto L100007;
	}
	iostat = do_lio(&__global_state->f2c, &__state->c__3, &__state->c__1, 
		(char *)&chunk, (ftnlen)sizeof(integer));
	if (iostat != 0) {
	    goto L100007;
	}
	iostat = e_rsle(&__global_state->f2c);
L100007:
	if (iostat != 0) {
	    dafcls_(__global_state, &handle);
	    setmsg_(__global_state, "The attempt to read from file '#' faile"
		    "d. IOSTAT = #.", (ftnlen)53);
	    errfnm_(__global_state, "#", text, (ftnlen)1);
	    errint_(__global_state, "#", &iostat, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(DAFREADFAIL)", (ftnlen)18);
	    chkout_(__global_state, "DAFT2B", (ftnlen)6);
	    return 0;
	}
	while(chunk > 0) {
	    if (chunk > 1024) {
		dafcls_(__global_state, &handle);
		setmsg_(__global_state, "Buffer size exceeded. Increase to #."
			, (ftnlen)36);
		errint_(__global_state, "#", &chunk, (ftnlen)1);
		sigerr_(__global_state, "SPICE(DAFOVERFLOW)", (ftnlen)18);
		chkout_(__global_state, "DAFT2B", (ftnlen)6);
		return 0;
	    } else {
		__state->io___25.ciunit = *text;
		iostat = s_rsle(&__global_state->f2c, &__state->io___25);
		if (iostat != 0) {
		    goto L100008;
		}
		i__1 = chunk;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    iostat = do_lio(&__global_state->f2c, &__state->c__5, &
			    __state->c__1, (char *)&buffer[(i__2 = i__ - 1) < 
			    1024 && 0 <= i__2 ? i__2 : s_rnge(&
			    __global_state->f2c, "buffer", i__2, "daft2b_", (
			    ftnlen)533)], (ftnlen)sizeof(doublereal));
		    if (iostat != 0) {
			goto L100008;
		    }
		}
		iostat = e_rsle(&__global_state->f2c);
L100008:
		if (iostat != 0) {
		    dafcls_(__global_state, &handle);
		    setmsg_(__global_state, "The attempt to read from file '"
			    "#' failed. IOSTAT = #.", (ftnlen)53);
		    errfnm_(__global_state, "#", text, (ftnlen)1);
		    errint_(__global_state, "#", &iostat, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(DAFREADFAIL)", (ftnlen)18);
		    chkout_(__global_state, "DAFT2B", (ftnlen)6);
		    return 0;
		}
		dafada_(__global_state, buffer, &chunk);
		if (failed_(__global_state)) {
		    chkout_(__global_state, "DAFT2B", (ftnlen)6);
		    return 0;
		}
	    }
	    __state->io___27.ciunit = *text;
	    iostat = s_rsle(&__global_state->f2c, &__state->io___27);
	    if (iostat != 0) {
		goto L100009;
	    }
	    iostat = do_lio(&__global_state->f2c, &__state->c__3, &
		    __state->c__1, (char *)&chunk, (ftnlen)sizeof(integer));
	    if (iostat != 0) {
		goto L100009;
	    }
	    iostat = e_rsle(&__global_state->f2c);
L100009:
	    if (iostat != 0) {
		dafcls_(__global_state, &handle);
		setmsg_(__global_state, "The attempt to read from file '#' f"
			"ailed. IOSTAT = #.", (ftnlen)53);
		errfnm_(__global_state, "#", text, (ftnlen)1);
		errint_(__global_state, "#", &iostat, (ftnlen)1);
		sigerr_(__global_state, "SPICE(DAFREADFAIL)", (ftnlen)18);
		chkout_(__global_state, "DAFT2B", (ftnlen)6);
		return 0;
	    }
	}
	__state->io___28.ciunit = *text;
	iostat = s_rsle(&__global_state->f2c, &__state->io___28);
	if (iostat != 0) {
	    goto L100010;
	}
	iostat = do_lio(&__global_state->f2c, &__state->c__9, &__state->c__1, 
		name__ + 1000, isize);
	if (iostat != 0) {
	    goto L100010;
	}
	iostat = e_rsle(&__global_state->f2c);
L100010:
	if (iostat != 0) {
	    dafcls_(__global_state, &handle);
	    setmsg_(__global_state, "The attempt to read from file '#' faile"
		    "d. IOSTAT = #.", (ftnlen)53);
	    errfnm_(__global_state, "#", text, (ftnlen)1);
	    errint_(__global_state, "#", &iostat, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(DAFREADFAIL)", (ftnlen)18);
	    chkout_(__global_state, "DAFT2B", (ftnlen)6);
	    return 0;
	}
	if (s_cmp(&__global_state->f2c, name__, name__ + 1000, isize, isize) 
		!= 0) {
	    dafcls_(__global_state, &handle);
	    setmsg_(__global_state, "Array name mismatch: # and #.", (ftnlen)
		    29);
	    errch_(__global_state, "#", name__, (ftnlen)1, isize);
	    errch_(__global_state, "#", name__ + 1000, (ftnlen)1, isize);
	    sigerr_(__global_state, "SPICE(DAFNONAMEMATCH)", (ftnlen)21);
	    chkout_(__global_state, "DAFT2B", (ftnlen)6);
	    return 0;
	} else {
	    dafena_(__global_state);
	    if (failed_(__global_state)) {
		chkout_(__global_state, "DAFT2B", (ftnlen)6);
		return 0;
	    }
	}
	__state->io___29.ciunit = *text;
	iostat = s_rsle(&__global_state->f2c, &__state->io___29);
	if (iostat != 0) {
	    goto L100011;
	}
	iostat = do_lio(&__global_state->f2c, &__state->c__3, &__state->c__1, 
		(char *)&more, (ftnlen)sizeof(integer));
	if (iostat != 0) {
	    goto L100011;
	}
	iostat = e_rsle(&__global_state->f2c);
L100011:
	if (iostat != 0) {
	    dafcls_(__global_state, &handle);
	    setmsg_(__global_state, "The attempt to read from file '#' faile"
		    "d. IOSTAT = #.", (ftnlen)53);
	    errfnm_(__global_state, "#", text, (ftnlen)1);
	    errint_(__global_state, "#", &iostat, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(DAFREADFAIL)", (ftnlen)18);
	    chkout_(__global_state, "DAFT2B", (ftnlen)6);
	    return 0;
	}
    }

/*     The final '0' indicates that no arrays remain. The first shall */
/*     be last: the internal file name brings up the rear. If it doesn't */
/*     match the one at the front, complain. */

    __state->io___30.ciunit = *text;
    iostat = s_rsle(&__global_state->f2c, &__state->io___30);
    if (iostat != 0) {
	goto L100012;
    }
    iostat = do_lio(&__global_state->f2c, &__state->c__9, &__state->c__1, 
	    ifname + 60, (ftnlen)60);
    if (iostat != 0) {
	goto L100012;
    }
    iostat = e_rsle(&__global_state->f2c);
L100012:
    if (iostat != 0) {
	dafcls_(__global_state, &handle);
	setmsg_(__global_state, "The attempt to read from file '#' failed. I"
		"OSTAT = #.", (ftnlen)53);
	errfnm_(__global_state, "#", text, (ftnlen)1);
	errint_(__global_state, "#", &iostat, (ftnlen)1);
	sigerr_(__global_state, "SPICE(DAFREADFAIL)", (ftnlen)18);
	chkout_(__global_state, "DAFT2B", (ftnlen)6);
	return 0;
    }
    if (s_cmp(&__global_state->f2c, ifname, ifname + 60, (ftnlen)60, (ftnlen)
	    60) != 0) {
	dafcls_(__global_state, &handle);
	setmsg_(__global_state, "Internal file name mismatch: # and #", (
		ftnlen)36);
	errch_(__global_state, "#", ifname, (ftnlen)1, (ftnlen)60);
	errch_(__global_state, "#", ifname + 60, (ftnlen)1, (ftnlen)60);
	sigerr_(__global_state, "SPICE(DAFNOIFNMATCH)", (ftnlen)20);
	chkout_(__global_state, "DAFT2B", (ftnlen)6);
	return 0;
    }

/*     Close the DAF file we just created. */

    dafcls_(__global_state, &handle);
    chkout_(__global_state, "DAFT2B", (ftnlen)6);
    return 0;
} /* daft2b_ */

