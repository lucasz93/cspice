/* zzdafnfr.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzdafnfr_init_t __zzdafnfr_init;
static inline zzdafnfr_state_t* get_zzdafnfr_state(cspice_t* state) {
	if (!state->zzdafnfr)
		state->zzdafnfr = __cspice_allocate_module(sizeof(
	zzdafnfr_state_t), &__zzdafnfr_init, sizeof(__zzdafnfr_init));
	return state->zzdafnfr;

}

/* $Procedure ZZDAFNFR ( Private --- DAF write New File Record ) */
/* Subroutine */ int zzdafnfr_(cspice_t* __global_state, integer *lun, char *
	idword, integer *nd, integer *ni, char *ifname, integer *fward, 
	integer *bward, integer *free, char *format, ftnlen idword_len, 
	ftnlen ifname_len, ftnlen format_len)
{
    /* Initialized data */


    /* System generated locals */
    address a__1[3];
    integer i__1[3];
    cllist cl__1;

    /* Builtin functions */
    /* Subroutine */ int s_cat(f2c_state_t*, char *, char **, integer *, 
	    integer *, ftnlen), s_copy(f2c_state_t*, char *, char *, ftnlen, 
	    ftnlen);
    integer s_wdue(f2c_state_t*, cilist *), do_uio(f2c_state_t*, integer *, 
	    char *, ftnlen), e_wdue(f2c_state_t*), f_clos(f2c_state_t*, 
	    cllist *);

    /* Local variables */
    integer i__;
    extern /* Subroutine */ int zzftpstr_(cspice_t*, char *, char *, char *, 
	    char *, ftnlen, ftnlen, ftnlen, ftnlen);
    char delim[1];
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern integer rtrim_(cspice_t*, char *, ftnlen);
    char locifn[60];
    char locidw[8];
    char locfmt[8];
    char nullch[1];
    char lftbkt[6];
    extern /* Subroutine */ int errfnm_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    char rgtbkt[6];
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    integer iostat;
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);
    char tststr[16];

    /* Fortran I/O blocks */



    /* Module state */
    zzdafnfr_state_t* __state = get_zzdafnfr_state(__global_state);
/* $ Abstract */

/*    Write the file record to a new DAF file. */

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

/*     None. */

/* $ Keywords */

/*     DAF */
/*     UTILITY */

/* $ Declarations */
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


/*     Include Section:  Private FTP Validation String Parameters */

/*        zzftprms.inc Version 1    01-MAR-1999 (FST) */

/*     This include file centralizes the definition of string sizes */
/*     and other parameters that are necessary to properly implement */
/*     the FTP error detection scheme for binary kernels. */

/*     Before making any alterations to the contents of this file, */
/*     refer to the header of ZZFTPSTR for a detailed discussion of */
/*     the FTP validation string. */

/*     Size of FTP Test String Component: */


/*     Size of Maximum Expanded FTP Validation String: */

/*      (This indicates the size of a buffer to hold the test */
/*       string sequence from a possibly corrupt file. Empirical */
/*       evidence strongly indicates that expansion due to FTP */
/*       corruption at worst doubles the number of characters. */
/*       So take 3*SIZSTR to be on the safe side.) */


/*     Size of FTP Validation String Brackets: */


/*     Size of FTP Validation String: */


/*     Size of DELIM. */


/*     Number of character clusters present in the validation string. */


/*     End Include Section:  Private FTP Validation String Parameters */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     LUN        I   Logical unit number of an open DAF file. */
/*     IDWORD     I   DAF ID word. */
/*     ND         I   Number of double precision components in a summary. */
/*     NI         I   Number of integer componenets in a summary. */
/*     IFNAME     I   Internal filename. */
/*     FWARD      I   First descriptor record. */
/*     BWARD      I   Last descriptor record. */
/*     FREE       I   First free address. */
/*     FORMAT     I   File binary format identifier string. */

/* $ Detailed_Input */

/*     LUN        is a logical unit number of a DAF whose first record is */
/*                to be created with a DAF file record bearing the */
/*                attributes specified by the other arguments. */

/*     IDWORD     is the 'ID word' contained in the first eight */
/*                characters of the file record. */

/*     ND,        are the number of double precision and integer */
/*     NI         components, respectively, in each array summary */
/*                in the specified file. */

/*     IFNAME     is the internal filename to be stored in the file */
/*                record for identification purposes. */

/*     FWARD,     are the record numbers of the first and last */
/*     BWARD      descriptor records in the DAF file, respectively. */
/*                FWARD is greater than 2 whenever reserved records */
/*                are present. */

/*     FREE       is the first free address pointer.  This integer */
/*                stores the first free DAF address for writing the */
/*                next array to be appended to the file. */

/*     FORMAT     is a character string that indicates what the numeric */
/*                binary format the DAF is utilizing. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     See include file zzftprms.inc. */

/* $ Files */

/*     This routine writes to the first record of the DAF whose */
/*     logical unit is LUN. */

/* $ Exceptions */

/*     1) If any errors occur from the WRITE to the logical unit LUN, */
/*        the error SPICE(DAFWRITEFAIL) is signaled. Before returning */
/*        to the caller, the file attached to LUN is closed and deleted. */

/* $ Particulars */

/*     This routine assembles the file record and writes it to the */
/*     first record in a DAF.  Its purpose is to write new file */
/*     records only.  For updates, use DAFWFR. */

/*     Make certain the caller checks FAILED() after this returns, since */
/*     on error it closes and deletes the file. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     1) An individual character must occupy 1 byte of space and */
/*        conform to the ASCII standard. */

/*     2) The word size for the machine should be at least 32 bits, */
/*        else the computations to null pad the gaps in the file */
/*        record may overstep record boundaries. */

/* $ Author_and_Institution */

/*     F.S. Turner     (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.1, 11-DEC-2001 (FST) */

/*        Corrected the omission of IDWORD from the Brief_I/O and */
/*        Detailed_Input sections of the module header. */

/* -    SPICELIB Version 1.0.0, 02-MAR-1999 (FST) */


/* -& */

/*     SPICELIB Functions */


/*     Local Parameters */

/*     Amount of space measured in characters necessary to */
/*     null pad between the last character of FORMAT and the */
/*     first character of FTPSTR to keep FTPSTR at character */
/*     700 in a 1024 byte record. */


/*     Amount of space measured in characters necessary to */
/*     null pad from the last character of FTPSTR to the */
/*     end of the file record. Note: This value assumes the */
/*     length of the file record is 1024 bytes.  The DAF */
/*     specification only requires the presence of 1000 */
/*     characters, so this may requiremodification for */
/*     non-standard platforms. */


/*     Lengths of internal file name, ID word, and format word. */


/*     Local Variables */


/*     Saved Variables */


/*     Data Statements */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "ZZDAFNFR", (ftnlen)8);
    }

/*     On the first pass, format the PRENUL and PSTNUL strings, */
/*     and build FTPSTR from its components. */

    if (__state->first) {

/*        Store NULL into NULLCH. */

	*(unsigned char *)nullch = '\0';

/*        Set all of the characters of PRENUL to nulls. */

	for (i__ = 1; i__ <= 603; ++i__) {
	    *(unsigned char *)&__state->prenul[i__ - 1] = *(unsigned char *)
		    nullch;
	}

/*        Set all of the characters of PSTNUL to nulls. */

	for (i__ = 1; i__ <= 297; ++i__) {
	    *(unsigned char *)&__state->pstnul[i__ - 1] = *(unsigned char *)
		    nullch;
	}

/*        Build FTPSTR from its components that come back from */
/*        ZZFTPSTR.  This private SPICE routine returns the */
/*        following components: */
/* 7 */
/*           TSTSTR - The test component of the FTP string */
/*           LFTBKT - The left bracketing, printable, component of */
/*                    the FTP string. */
/*           RGTBKT - The right bracketing, printable, component of */
/*                    the FTP string. */
/*           DELIM  - The printable delimiter that separates the */
/*                    individual test character blocks in TSTSTR. */

/*        which are assembled into the FTP string as it appears in */
/*        the DAF file record. */

	zzftpstr_(__global_state, tststr, lftbkt, rgtbkt, delim, (ftnlen)16, (
		ftnlen)6, (ftnlen)6, (ftnlen)1);
/* Writing concatenation */
	i__1[0] = rtrim_(__global_state, lftbkt, (ftnlen)6), a__1[0] = lftbkt;
	i__1[1] = rtrim_(__global_state, tststr, (ftnlen)16), a__1[1] = 
		tststr;
	i__1[2] = rtrim_(__global_state, rgtbkt, (ftnlen)6), a__1[2] = rgtbkt;
	s_cat(&__global_state->f2c, __state->ftpstr, a__1, i__1, &
		__state->c__3, (ftnlen)28);

/*        Stop this block from executing except on the first pass. */

	__state->first = FALSE_;
    }

/*     Make local copies of each of the string arguments.  This way we */
/*     maintain the proper sizes for each of the string objects, in */
/*     the event larger or smaller strings are passed in. */

    s_copy(&__global_state->f2c, locidw, idword, (ftnlen)8, idword_len);
    s_copy(&__global_state->f2c, locifn, ifname, (ftnlen)60, ifname_len);
    s_copy(&__global_state->f2c, locfmt, format, (ftnlen)8, format_len);

/*     Write the file record components out to the first record of the */
/*     file. */

    __state->io___15.ciunit = *lun;
    iostat = s_wdue(&__global_state->f2c, &__state->io___15);
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__global_state->f2c, &__state->c__1, locidw, (ftnlen)8);
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__global_state->f2c, &__state->c__1, (char *)&(*nd), (
	    ftnlen)sizeof(integer));
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__global_state->f2c, &__state->c__1, (char *)&(*ni), (
	    ftnlen)sizeof(integer));
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__global_state->f2c, &__state->c__1, locifn, (ftnlen)60);
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__global_state->f2c, &__state->c__1, (char *)&(*fward), (
	    ftnlen)sizeof(integer));
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__global_state->f2c, &__state->c__1, (char *)&(*bward), (
	    ftnlen)sizeof(integer));
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__global_state->f2c, &__state->c__1, (char *)&(*free), (
	    ftnlen)sizeof(integer));
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__global_state->f2c, &__state->c__1, locfmt, (ftnlen)8);
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__global_state->f2c, &__state->c__1, __state->prenul, (
	    ftnlen)603);
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__global_state->f2c, &__state->c__1, __state->ftpstr, (
	    ftnlen)28);
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_uio(&__global_state->f2c, &__state->c__1, __state->pstnul, (
	    ftnlen)297);
    if (iostat != 0) {
	goto L100001;
    }
    iostat = e_wdue(&__global_state->f2c);
L100001:

/*     Check IOSTAT for errors. */

    if (iostat != 0) {

/*        Since we are unable to write to the file record, make */
/*        certain the output file is destroyed. */

	setmsg_(__global_state, "Attempt to write file '#' failed. Value of "
		"IOSTAT was #. The file has been deleted.", (ftnlen)83);
	errfnm_(__global_state, "#", lun, (ftnlen)1);
	errint_(__global_state, "#", &iostat, (ftnlen)1);
	cl__1.cerr = 0;
	cl__1.cunit = *lun;
	cl__1.csta = "DELETE";
	f_clos(&__global_state->f2c, &cl__1);
	sigerr_(__global_state, "SPICE(DAFWRITEFAIL)", (ftnlen)19);
	chkout_(__global_state, "ZZDAFNFR", (ftnlen)8);
	return 0;
    }
    chkout_(__global_state, "ZZDAFNFR", (ftnlen)8);
    return 0;
} /* zzdafnfr_ */

