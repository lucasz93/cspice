/* dastb.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern dastb_init_t __dastb_init;
static inline dastb_state_t* get_dastb_state(cspice_t* state) {
	if (!state->dastb)
		state->dastb = __cspice_allocate_module(sizeof(dastb_state_t),
	 &__dastb_init, sizeof(__dastb_init));
	return state->dastb;

}

/* $Procedure DASTB ( DAS, convert transfer file to binary file ) */
/* Subroutine */ int dastb_(cspice_t* __global_state, integer *xfrlun, char *
	binfil, ftnlen binfil_len)
{
    /* System generated locals */
    cilist ci__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer s_rsle(f2c_state_t*, cilist *), do_lio(f2c_state_t*, integer *, 
	    integer *, char *, ftnlen), e_rsle(f2c_state_t*), s_cmp(
	    f2c_state_t*, char *, char *, ftnlen, ftnlen), s_rsfe(f2c_state_t*
	    , cilist *), do_fio(f2c_state_t*, integer *, char *, ftnlen), 
	    e_rsfe(f2c_state_t*);

    /* Local variables */
    char line[255];
    logical more;
    char word[255];
    char rest[255];
    extern /* Subroutine */ int zzddhhlu_(cspice_t*, integer *, char *, 
	    logical *, integer *, ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer ncomc;
    logical inblk;
    char tarch[8];
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    integer recno;
    integer ncomr;
    char ttype[8];
    extern /* Subroutine */ int idw2at_(cspice_t*, char *, char *, char *, 
	    ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int dasadc_(cspice_t*, integer *, integer *, 
	    integer *, integer *, char *, ftnlen);
    extern /* Subroutine */ int dasadd_(cspice_t*, integer *, integer *, 
	    doublereal *);
    extern logical failed_(cspice_t*);
    extern /* Subroutine */ int dasadi_(cspice_t*, integer *, integer *, 
	    integer *);
    integer ncdata;
    integer handle;
    integer nddata;
    extern /* Subroutine */ int dasacr_(cspice_t*, integer *, integer *);
    char ifname[60];
    integer nidata;
    extern /* Subroutine */ int rdencc_(cspice_t*, integer *, integer *, char 
	    *, ftnlen);
    char crecrd[1024];
    extern /* Subroutine */ int rdenci_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int dasioc_(cspice_t*, char *, integer *, integer 
	    *, char *, ftnlen, ftnlen);
    char cbuffr[4*1024];
    doublereal dbuffr[1024];
    integer bindex;
    integer blkcnt;
    integer dtacnt;
    integer eindex;
    integer ibuffr[1024];
    integer daslun;
    char idword[8];
    integer bcount;
    integer numblk;
    integer numdta;
    integer ecount;
    extern /* Subroutine */ int errfnm_(cspice_t*, char *, integer *, ftnlen);
    char errmsg[320];
    integer nresvc;
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    integer iostat;
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    integer numlft;
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int dasonw_(cspice_t*, char *, char *, char *, 
	    integer *, integer *, ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int daswfr_(cspice_t*, integer *, char *, char *, 
	    integer *, integer *, integer *, integer *, ftnlen, ftnlen);
    extern /* Subroutine */ int dascls_(cspice_t*, integer *);
    extern /* Subroutine */ int nextwd_(cspice_t*, char *, char *, char *, 
	    ftnlen, ftnlen, ftnlen);
    integer tcount;
    extern /* Subroutine */ int nparsi_(cspice_t*, char *, integer *, char *, 
	    integer *, ftnlen, ftnlen);
    extern logical return_(cspice_t*);
    integer errptr;
    integer nresvr;
    extern /* Subroutine */ int rdencd_(cspice_t*, integer *, integer *, 
	    doublereal *);

    /* Fortran I/O blocks */



    /* Module state */
    dastb_state_t* __state = get_dastb_state(__global_state);
/* $ Abstract */

/*     Convert the contents of a DAS transfer file into an equivalent */
/*     binary DAS file. */

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

/*     DAS */

/* $ Keywords */

/*     CONVERSION */
/*     FILES */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     XFRLUN     I   Logical unit of an open DAS transfer file. */
/*     BINFIL     I   Name of the binary DAS file to be created. */

/* $ Detailed_Input */

/*     XFRLUN   The Fortran logical unit number of a previously opened */
/*              DAS transfer file. */

/*              The file pointer should be positioned ready to read */
/*              the DAS file ID word. */

/*     BINFIL   The name of the binary DAS file to be created. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)   If the DAS transfer file cannot be read, the error */
/*          SPICE(FILEREADFAILED) will be signaled. */

/*     2)   If the specified file is not a DAS file, as indicated by the */
/*          file's ID word, the error SPICE(NOTADASFILE) is signaled. */

/*     3)   If an error occurs while attempting to decode data in the */
/*          DAS transfer file, the error SPICE(BADDASTRANSFERFILE) will */
/*          be signaled. */

/*     4)   If the DAS file cannot be written, a DAS file access routine */
/*          will signal an error with an appropriate error message. */

/*     5)   The binary DAS file opened by this routine, BINFIL, is only */
/*          GUARANTEED to be closed upon successful completion of the */
/*          text to binary conversion process. In the event of an error, */
/*          the caller of this routine is required to close the binary */
/*          DAS file BINFIL. */

/* $ Files */

/*     See arguments XFRLUN, BINFIL. */

/* $ Particulars */

/*     Any binary DAS file may be transferred between heterogeneous */
/*     Fortran environments by converting it to an equivalent file */
/*     containing only ASCII characters called a DAS transfer file. */
/*     Such a file can be transferred almost universally using any number */
/*     of established protocols. Once transferred, the DAS transfer file */
/*     can be converted to a binary file using the representations native */
/*     to the new host environment. */

/*     This routine provides a mechanism for converting a DAS */
/*     transfer file created by DASBT, or an equivalent procedure, */
/*     into an equivalent binary DAS file which may be used with the */
/*     SPICE system. It is one of a pair of routines for performing */
/*     conversions between the binary format of a DAS file and the DAS */
/*     transfer file. The inverse of this routine is the routine DASTB. */

/*     Upon successful completion, the binary DAS file specified by */
/*     BINFIL will have been created. The binary DAS file that was */
/*     created will be closed when this routine exits. The DAS transfer */
/*     file will remain open, as it was on entry, and it will be */
/*     positioned to read the first line after the encoded DAS file data. */

/* $ Examples */

/*     Let */

/*        XFRLUN   be the Fortran logical unit attached to a DAS transfer */
/*                 file which is to be converted into its binary DAS */
/*                 equivalent. */

/*        BINFIL   be the name of the binary DAS file which will be */
/*                 created. */

/*     Then, the following subroutine call would read the DAS transfer */
/*     file attached to the Fortran logical unit XFRLUN, convert its data */
/*     into binary format, and write that data to the binary DAS file */
/*     which is being created: */

/*        CALL DASTB( XFRLUN, BINFIL ) */

/* $ Restrictions */

/*     1) This routine assumes that it is positioned ready to read the */
/*        DAS file ID word from the encoded text DAS file. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     K.R. Gehringer  (JPL) */

/* $ Version */

/* -    SPICELIB Version 3.2.0, 05-FEB-2015 (NJB) */

/*        Updated to support integration with the handle */
/*        manager subsystem. */

/*        Corrected typo in a long error message and several */
/*        typos in comments. Re-ordered header sections. */

/* -    SPICELIB Version 3.1.0, 06-DEC-1995 (KRG) */

/*        Updated the call to DASONW; a new argument was added to the */
/*        call for reserving comment records. */

/* -    SPICELIB Version 3.0.0, 13-AUG-1994 (KRG) */

/*        Updated the header and in line comments to reflect the change */
/*        from calling files text files to calling them transfer files. */

/*        Changed the variable name XFRLUN to XFRLUN to make it */
/*        compatible with the change in terminology. */

/*        Changed the short error message "BADDASTEXTFILE" to the */
/*        message "BADDASTRANSFERFILE". */

/* -    SPICELIB Version 2.0.0, 27-OCT-1993 (KRG) */

/*       Updated the routine to use the new format ID words which */
/*       contain type as well as architecture information. */
/* C */
/*       Fixed a typo in the description of the DAS encoded text file: */
/*       ncomc appeared where nresvc should have been. */

/* -    SPICELIB Version 1.0.0, 02-NOV-1992 (KRG) */

/* -& */
/* $ Index_Entries */

/*     convert das transfer file to binary das */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 3.1.0, 06-DEC-1995 (KRG) */

/*        Updated the call to DASONW; a new argument was added to the */
/*        call for reserving comment records. The value used here is */
/*        zero (0). */

/* -    SPICELIB Version 3.0.0, 13-AUG-1994 (KRG) */

/*        Updated the header and in line comments to reflect the change */
/*        from calling files text files to calling them transfer files. */

/*        Changed the variable name XFRLUN to XFRLUN to make it */
/*        compatible with the change in terminology. */

/*        Changed the short error message "BADDASTEXTFILE" to the */
/*        message "BADDASTRANSFERFILE". */

/* -    SPICELIB Version 2.0.0, 27-OCT-1993 (KRG) */

/*        Updated the routine to use the new format ID words which */
/*        contain type as well as architecture information. */

/*        Changed the wording of exception '2)' so that it would make */
/*        sense with the ID word format change that was made. */

/*        Changed the error */

/*           SPICE(DASIDWORDNOTKNOWN) */

/*        to */

/*           SPICE(NOTADASFILE) */

/*        Added variables to support the file architecture and type */
/*        stored in the ID word. These are used in order to verify that */
/*        the text file that is to be converted is indeed a DAS file. */
/*        This test is performed instead of testing whether the ID word */
/*        is equal to 'NAIF/DAS'. */

/*        Modified the long error message that was set to conform to the */
/*        ID word change. */

/*        Changed the DASOPN call to DASONW to support the addition of */
/*        type information to the ID word. */

/*        Fixed a typo in the description of the DAS encoded text file: */
/*        ncomc appeared where nresvc should have been. */

/* -    SPICELIB Version 1.0.0, 02-NOV-1992 (KRG) */

/* -& */

/*     SPICELIB functions */


/*     Local Parameters */

/*      CHARACTER*(*)         BEGRES */
/*      PARAMETER           ( BEGRES = 'BEGIN_RESERVED_BLOCK'   ) */

/*      CHARACTER*(*)         ENDRES */
/*      PARAMETER           ( ENDRES = 'END_RESERVED_BLOCK'     ) */

/*      CHARACTER*(*)         TRRBLK */
/*      PARAMETER           ( TRRBLK = 'TOTAL_RESERVED_BLOCKS'  ) */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "DASTB", (ftnlen)5);
    }

/*     A DAS transfer file contains in an encoded form all of the data */
/*     from the original binary DAS file. This includes the reserved */
/*     record area, the comment area, and the character, double */
/*     precision, and integer data arrays as well. */

/*     Currently, the reserved record area has not been implemented, as */
/*     there is no need for it at this time. If, or when, the reserved */
/*     record area is implemented, this routine will need to be modified */
/*     in order to support it. See the code for details. */

/*     The data in the DAS transfer file are available as sequences of */
/*     small blocks of data. This is to provide a means for performing */
/*     some error detection when converting a DAS transfer file into its */
/*     binary equivalent. Each block of data is enclosed within begin and */
/*     end block markers which hold the count of data items in a data */
/*     block. When all of the data blocks for a data area have been */
/*     written, a total blocks line is read to verify that all of the */
/*     data has been converted. */

/*     The data in the DAS transfer file MUST appear in the following */
/*     order for this routine to work properly. */

/*           1) Reserved records (when/if implemented) */
/*           2) Comment area */
/*           3) Character data array */
/*           4) Double precision data array */
/*           5) Integer data array */

/*     If the data count for any of these DAS data areas is zero, */
/*     conversion proceeds with the next DAS data area in the list. */

/*     For example, suppose that we have a binary DAS file where there */
/*     are 0 reserved characters in the reserved record area, 5000 */
/*     comment characters in the comment area, and that the character, */
/*     double precision, and integer array counts are 0, 2300, and */
/*     6900, respectively. Then, the DAS encoded text file will contain */
/*     no reserved record data blocks, 2 comment data blocks, no */
/*     character data blocks, 3 double precision data blocks, and 7 */
/*     integer data blocks, in that order. */

/*     DAS encoded text file description. */
/*     ---------------------------------- */


/*     A brief description of the DAS encoded file format and its */
/*     intended use follows. This description is intended to provide a */
/*     simple ``picture'' of the DAS transfer file format to aid in the */
/*     understanding of this routine. This description is NOT intended to */
/*     be a detailed specification of the file format. */

/*     A DAS transfer file contains all of the data from a binary */
/*     DAS file in an encoded ASCII format. It also contains some */
/*     bookkeeping information for maintaining the integrity of the */
/*     data. The DAS transfer file format allows the full precision of */
/*     character, integer, and floating point numeric data to be */
/*     maintained in a portable fashion. The DAS transfer file format is */
/*     intended to provide a reliable and accurate means for porting data */
/*     among multiple computer systems and for the archival storage of */
/*     data. */

/*     A DAS transfer file is not intended to be used directly to provide */
/*     data to a program. The equivalent binary DAS file is to be used */
/*     for this purpose. In no way should any program, other than a DAS */
/*     binary <-> transfer conversion program, rely on the DAS transfer */
/*     file format. */

/*     To correctly understand the DAS transfer file description  the */
/*     reader should be familiar with the DAS file architecture. Items */
/*     enclosed in angle brackets, '<' and '>', are used to represent the */
/*     data which are to be placed at that position in the file. The */
/*     bookkeeping information which appears is represented exactly as it */
/*     would appear in a DAS transfer file. */

/*     Let */

/*        <BOF>  denote the beginning of the file */
/*        <EOF>  denote the end of the file */

/*     and */

/*        nresvb  denote the number of encoded reserved record data */
/*                blocks generated */
/*        nresvc  denote the total number of reserved record characters */
/*                in the  reserved record area of a DAS file */
/*        ncomb   denote the number of encoded comment data blocks */
/*                generated */
/*        ncomc   denote the total number of comment characters in the */
/*                comment area of a DAS file */
/*        nchrb   denote the number of encoded character data blocks */
/*                generated */
/*        nchrs   denote the count of characters in the DAS character */
/*                data array */
/*        ndpb    denote the number of encoded double precision data */
/*                blocks generated */
/*        ndps    denote the count of double precision numbers in the DAS */
/*                double precision data array */
/*        nintb   denote the number of encoded integer data blocks */
/*                generated */
/*        nints   denote the count of integers in the DAS integer data */
/*                array */

/*     A DAS encoded transfer file has the following format: */

/*        <BOF> */
/*        < Information line > */
/*        < DAS file ID word > */
/*        < Internal filename > */
/*        < Encoded count of reserved records > */
/*        < Encoded count of reserved characters > */
/*        < Encoded count of comment records > */
/*        < Encoded count of comment characters > */
/*        < Blocks of encoded reserved record data, if nresvc > 0 > */
/*        TOTAL_RESERVED_BLOCKS nresvb nresvc */
/*        < Blocks of encoded comment data, if ncomc > 0 > */
/*        TOTAL_COMMENT_BLOCKS ncomb ncomc */
/*        < Encoded count of character data > */
/*        < Encoded count of double precision data > */
/*        < Encoded count of integer data > */
/*        < Blocks of encoded character data, if nchrs > 0 > */
/*        TOTAL_CHARACTER_BLOCKS nchrb nchrs */
/*        < Blocks of encoded double precision data, if ndps > 0 > */
/*        TOTAL_DP_BLOCKS ndpb ndps */
/*        < Blocks of encoded integer data, if nints > 0 > */
/*        TOTAL_INTEGER_BLOCKS nintb nints */
/*        <EOF> */

/*     This routine will check the SPICELIB function FAILED() after */
/*     each call, or consecutive sequence of calls, to data encoding */
/*     routines, and if an error was signaled it will simply check out */
/*     and return to the caller. */

/*     This routine will check the SPICELIB function FAILED() after */
/*     each DAS file access call, and if an error was signaled it will */
/*     simply check out and return to the caller. */

/*     We begin by reading the DAS file ID word from the DAS transfer */
/*     file. We should have been positioned ready to read this. If an */
/*     error occurs, set an appropriate error message and signal the */
/*     error. */

    s_copy(&__global_state->f2c, idword, " ", (ftnlen)8, (ftnlen)1);
    __state->io___3.ciunit = *xfrlun;
    iostat = s_rsle(&__global_state->f2c, &__state->io___3);
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
	setmsg_(__global_state, "Error reading the file ID word from the DAS"
		" transfer file: #. IOSTAT = #.", (ftnlen)73);
	errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
	errint_(__global_state, "#", &iostat, (ftnlen)1);
	sigerr_(__global_state, "SPICE(FILEREADFAILED)", (ftnlen)21);
	chkout_(__global_state, "DASTB", (ftnlen)5);
	return 0;
    }

/*     Check the DAS ID word. When checking the ID word all we care about */
/*     is that we are attempting to convert a DAS file. So, split the */
/*     ID word into its architecture and type and check the architecture. */

    idw2at_(__global_state, idword, tarch, ttype, (ftnlen)8, (ftnlen)8, (
	    ftnlen)8);
    if (s_cmp(&__global_state->f2c, tarch, "DAS", (ftnlen)8, (ftnlen)3) != 0) 
	    {
	setmsg_(__global_state, "File architecture was not 'DAS' for file #.",
		 (ftnlen)43);
	errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
	sigerr_(__global_state, "SPICE(NOTADASFILE)", (ftnlen)18);
	chkout_(__global_state, "DASTB", (ftnlen)5);
	return 0;
    }

/*     Read the internal filename for the DAS file. */

    s_copy(&__global_state->f2c, ifname, " ", (ftnlen)60, (ftnlen)1);
    __state->io___7.ciunit = *xfrlun;
    iostat = s_rsle(&__global_state->f2c, &__state->io___7);
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
	setmsg_(__global_state, "Error reading the internal filename from th"
		"e DAS transfer file: #. IOSTAT = #.", (ftnlen)78);
	errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
	errint_(__global_state, "#", &iostat, (ftnlen)1);
	sigerr_(__global_state, "SPICE(FILEREADFAILED)", (ftnlen)21);
	chkout_(__global_state, "DASTB", (ftnlen)5);
	return 0;
    }

/*     Open a new binary DAS file and write its file record. */

    dasonw_(__global_state, binfil, ttype, ifname, &__state->c__0, &handle, 
	    binfil_len, (ftnlen)8, (ftnlen)60);
    if (failed_(__global_state)) {

/*        If an error occurred while opening the new DAS file, */
/*        then check out and return. */

	chkout_(__global_state, "DASTB", (ftnlen)5);
	return 0;
    }

/*     Write the initial file record to the newly opened DAS file. This */
/*     call will overwrite the ID word set when we opened the file with */
/*     the ID word from the DAS transfer file. We got to this point, so */
/*     we know that the ID word was a good one. */

    ncomr = 0;
    ncomc = 0;
    nresvr = 0;
    nresvc = 0;
    daswfr_(__global_state, &handle, idword, ifname, &nresvr, &nresvc, &ncomr,
	     &ncomc, (ftnlen)8, (ftnlen)60);
    if (failed_(__global_state)) {

/*        If an error occurred while writing the DAS file record, */
/*        attempt to close the binary file, then check out and return. */

	dascls_(__global_state, &handle);
	chkout_(__global_state, "DASTB", (ftnlen)5);
	return 0;
    }

/*     Read and decode the number of reserved records and reserved */
/*     characters. */

    rdenci_(__global_state, xfrlun, &__state->c__1, &nresvr);
    rdenci_(__global_state, xfrlun, &__state->c__1, &nresvc);
    if (failed_(__global_state)) {
	chkout_(__global_state, "DASTB", (ftnlen)5);
	return 0;
    }

/*     Check to be sure that the number of reserved records and the */
/*     number of reserved characters are not being used. The DAS */
/*     reserved record area is not currently implemented, so nobody */
/*     should be using it. */

    if (nresvc != 0) {

/*        Close the file, signal the error, and exit. */

	dascls_(__global_state, &handle);
	setmsg_(__global_state, "The number of reserved characters was nonze"
		"ro (#) in file: #, but the DAS reserved record area has NOT "
		"been implemented yet!", (ftnlen)124);
	errint_(__global_state, "#", &nresvc, (ftnlen)1);
	errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
	sigerr_(__global_state, "SPICE(BADDASFILE)", (ftnlen)17);
	chkout_(__global_state, "DASTB", (ftnlen)5);
	return 0;
    }
    if (nresvr != 0) {

/*        Close the file, signal the error, and exit. */

	dascls_(__global_state, &handle);
	setmsg_(__global_state, "The number of reserved records was nonzero "
		"(#) in file: #, but the DAS reserved record area has NOT bee"
		"n implemented yet!", (ftnlen)121);
	errint_(__global_state, "#", &nresvr, (ftnlen)1);
	errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
	sigerr_(__global_state, "SPICE(BADDASFILE)", (ftnlen)17);
	chkout_(__global_state, "DASTB", (ftnlen)5);
	return 0;
    }

/*     Read and decode the number of comment records and comment */
/*     characters. */

    rdenci_(__global_state, xfrlun, &__state->c__1, &ncomr);
    rdenci_(__global_state, xfrlun, &__state->c__1, &ncomc);
    if (failed_(__global_state)) {
	chkout_(__global_state, "DASTB", (ftnlen)5);
	return 0;
    }

/*     Begin converting the DAS transfer file into an equivalent */
/*     binary DAS file here. */

/*     The reserved records, if there are any. */

/*     ************************************************************** */
/*     When/if the reserved record area is implemented, the code to */
/*     read it from the DAS transfer file and convert it to binary */
/*     should go here. It should be possible to simply copy the code */
/*     for the comment area, making all of the necessary variable */
/*     name changes, etc., since the reserved record area is going */
/*     to contain ONLY character data. */
/*     ************************************************************** */


/*     The comments, if there are any. */

    if (ncomc > 0) {

/*        We assume that the condition NCOMC > 0 and NCOMR <= 0 */
/*        cannot occur. */

/*        The binary DAS file that we are creating is already open, */
/*        so just add the comments. But first, convert the DAS file */
/*        handle into its equivalent logical unit. */

	zzddhhlu_(__global_state, &handle, "DAS", &__state->c_false, &daslun, 
		(ftnlen)3);
	if (failed_(__global_state)) {

/*           If an error occurred, attempt to close the binary file, */
/*           then check out and return. */

	    dascls_(__global_state, &handle);
	    chkout_(__global_state, "DASTB", (ftnlen)5);
	    return 0;
	}

/*        Allocate the necessary comment records. */

	dasacr_(__global_state, &handle, &ncomr);
	if (failed_(__global_state)) {

/*           If an error occurred, attempt to close the binary file, */
/*           then checkout and return. */

	    dascls_(__global_state, &handle);
	    chkout_(__global_state, "DASTB", (ftnlen)5);
	    return 0;
	}

/*        Initialize a few things: the block counter, the data */
/*        counter, and the starting record position. The starting */
/*        record position is one short of the actual first comment */
/*        record. We will increment the record number before we */
/*        write anything. */

	blkcnt = 0;
	dtacnt = 0;
	recno = nresvr + 1;

/*        We currently have more to process. */

	more = TRUE_;

/*        We are currently not processing a comment block. */

	inblk = FALSE_;
	while(more) {
	    s_copy(&__global_state->f2c, crecrd, " ", (ftnlen)1024, (ftnlen)1)
		    ;
	    ci__1.cierr = 1;
	    ci__1.ciend = 1;
	    ci__1.ciunit = *xfrlun;
	    ci__1.cifmt = "(A)";
	    iostat = s_rsfe(&__global_state->f2c, &ci__1);
	    if (iostat != 0) {
		goto L100003;
	    }
	    iostat = do_fio(&__global_state->f2c, &__state->c__1, line, (
		    ftnlen)255);
	    if (iostat != 0) {
		goto L100003;
	    }
	    iostat = e_rsfe(&__global_state->f2c);
L100003:
	    if (iostat != 0) {

/*              If an error occurred while reading from the DAS transfer */
/*              file close the binary file, set an appropriate error */
/*              message, then check out and return. */

		dascls_(__global_state, &handle);
		setmsg_(__global_state, "Error reading from the DAS transfer"
			" file #. IOSTAT = #.", (ftnlen)55);
		errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		errint_(__global_state, "#", &iostat, (ftnlen)1);
		sigerr_(__global_state, "SPICE(FILEREADFAILED)", (ftnlen)21);
		chkout_(__global_state, "DASTB", (ftnlen)5);
		return 0;
	    }

/*           At this point, we should be beginning a comment block, */
/*           ending a comment block, or scanning for the total number */
/*           of comment blocks. So look for the appropriate keyword. */

	    nextwd_(__global_state, line, word, rest, (ftnlen)255, (ftnlen)
		    255, (ftnlen)255);
	    if (s_cmp(&__global_state->f2c, word, "BEGIN_COMMENT_BLOCK", (
		    ftnlen)255, (ftnlen)19) == 0) {

/*              Get the comment block index. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &bindex, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the begin block */
/*                 index, close the binary file, set an appropriate */
/*                 error  message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Begin comment block error, coul"
			    "d not parse block number. Error: # File: #", (
			    ftnlen)73);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Parse the count of characters in the block. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &bcount, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the beginning */
/*                 data count, close the binary file, set an */
/*                 appropriate error message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Begin comment block error, coul"
			    "d not parse the data count for block: #. Error: "
			    "# File: #", (ftnlen)88);
		    errint_(__global_state, "#", &bindex, (ftnlen)1);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              If we got to here, we are inside a comment block, so set */
/*              the in block flag, INBLK, to .TRUE. and increment the */
/*              block counter. */

		inblk = TRUE_;
		++blkcnt;
	    } else if (s_cmp(&__global_state->f2c, word, "END_COMMENT_BLOCK", 
		    (ftnlen)255, (ftnlen)17) == 0) {

/*              Get the data block index. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &eindex, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the end comment */
/*                 block index, close the binary file, set an appropriate */
/*                 error message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "End comment block error, could "
			    "not parse block number. Error: # File: #", (
			    ftnlen)71);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Parse the count of characters in the DAS array. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &ecount, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the ending data */
/*                 count, close the binary file, set an appropriate */
/*                 error message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "End comment block error, could "
			    "not parse the data count for  block: #. Error: #"
			    " File: #", (ftnlen)87);
		    errint_(__global_state, "#", &eindex, (ftnlen)1);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Check to see if the beginning and ending array indices */
/*              match. */

		if (eindex != bindex) {

/*                 If the begin and end data block indices do not match, */
/*                 close the binary file, set an appropriate error */
/*                 message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Comment block index mismatch: B"
			    "eginning index: #; Ending index: #. File: #", (
			    ftnlen)74);
		    errint_(__global_state, "#", &bindex, (ftnlen)1);
		    errint_(__global_state, "#", &eindex, (ftnlen)1);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Check to see if the beginning and ending comment data */
/*              counts match. */

		if (ecount != bcount) {

/*                 If the begin and end data block counts do not match, */
/*                 close the binary file, set an appropriate error */
/*                 message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Comment block count mismatch: B"
			    "eginning count: #; Ending count: #. File: #", (
			    ftnlen)74);
		    errint_(__global_state, "#", &bcount, (ftnlen)1);
		    errint_(__global_state, "#", &ecount, (ftnlen)1);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              If we got to here, we have successfully ended the */
/*              processing of a comment block, so set the in block */
/*              flag INBLK, to .FALSE.. */

		inblk = FALSE_;
	    } else if (s_cmp(&__global_state->f2c, word, "TOTAL_COMMENT_BLOC"
		    "KS", (ftnlen)255, (ftnlen)20) == 0) {

/*              We have the total comment blocks keyword to parse, so */
/*              get the total number of comment blocks processed. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &numblk, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the total number of */
/*                 data blocks, close the binary file, set an appropriate */
/*                 error  message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Comment block count error, coul"
			    "d not parse the total number of character blocks"
			    ": #. File: #", (ftnlen)91);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Parse the total count of comment characters. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &tcount, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the comment */
/*                 data count, close the binary file, set an */
/*                 appropriate error message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Comment count error, could not "
			    "parse the total count. Error: # File: #", (ftnlen)
			    70);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Compare the computed block count with the block count */
/*              from the file. */

		if (blkcnt != numblk) {

/*                 If the computed number of comment blocks and the */
/*                 number of comment blocks from the text file do */
/*                 not match, close the binary file, set an appropriate */
/*                 error message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "The number of comment data bloc"
			    "ks processed (#) was not equal to the number of "
			    "comment data blocks placed in the DAS text file "
			    "(#). File: #", (ftnlen)139);
		    errint_(__global_state, "#", &blkcnt, (ftnlen)1);
		    errint_(__global_state, "#", &numblk, (ftnlen)1);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Check to see if the total count and the computed count */
/*              match. */

		if (tcount != dtacnt) {

/*                 If the total count and computed count do not match, */
/*                 close the binary file, set an appropriate error */
/*                 message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Comment count mismatch: compute"
			    "d count: #; expected count: #. File: #", (ftnlen)
			    69);
		    errint_(__global_state, "#", &dtacnt, (ftnlen)1);
		    errint_(__global_state, "#", &tcount, (ftnlen)1);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              If we got to here, we have successfully processed the */
/*              entire DAS comment area in the text file, so there is */
/*              no more comment data. */

		more = FALSE_;
	    } else {

/*              We got an unknown keyword of some sort, so set an */
/*              appropriate error message, close the DAS file, and */
/*              return. */

		dascls_(__global_state, &handle);
		setmsg_(__global_state, "Unknown keyword '#' encountered whi"
			"le processing the DAS transfer file #.", (ftnlen)73);
		errch_(__global_state, "#", word, (ftnlen)1, (ftnlen)255);
		errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (ftnlen)
			25);
		chkout_(__global_state, "DASTB", (ftnlen)5);
		return 0;
	    }

/*           If we have begun a block, then process it. Otherwise, we */
/*           have ended a block. */

	    if (inblk) {

/*              Increment the record number by one for each comment */
/*              data block we process, because each block contains a */
/*              comment record. */

		++recno;

/*              Set the count of comment characters yet to be decoded and */
/*              placed in the binary DAS file. */

		numlft = bcount;
		while(numlft > 0) {

/*                 Now read and decode the data in the current */
/*                 comment data block, placing the data in the */
/*                 comment area of the binary DAS file. */

		    if (numlft >= 1024) {
			numdta = 1024;
		    } else {
			numdta = numlft;
		    }

/*                 Read and decode a record of encoded comment data */
/*                 from the text file. */

		    rdencc_(__global_state, xfrlun, &numdta, crecrd, (ftnlen)
			    1024);

/*                 Write the comment data to the comment area in the */
/*                 binary DAS file. */

		    dasioc_(__global_state, "WRITE", &daslun, &recno, crecrd, 
			    (ftnlen)5, (ftnlen)1024);
		    if (failed_(__global_state)) {

/*                    If an error occurred, attempt to close the */
/*                    binary file, then checkout and return. */

			dascls_(__global_state, &handle);
			chkout_(__global_state, "DASTB", (ftnlen)5);
			return 0;
		    }

/*                 Decrement the counter for the amount of data */
/*                 remaining to be moved from the current comment */
/*                 block, NUMLFT. */

		    numlft -= numdta;

/*                 Increment the counter for the amount of data that */
/*                 has been successfully moved into the comment area */
/*                 of the binary DAS file. */

		    dtacnt += numdta;
		}

/*              At this point, we have finished reading in an entire */
/*              comment block. */

	    }

/*           If we got to here, we have successfully written a comment */
/*           block to the binary file. */

	}

/*        At this point, we will have successfully written the entire */
/*        comment area to the binary DAS file, if there was a comment */
/*        area. */

/*        Write the file record to the DAS file, to update the number */
/*        of comment characters. */

	daswfr_(__global_state, &handle, idword, ifname, &nresvr, &nresvc, &
		ncomr, &ncomc, (ftnlen)8, (ftnlen)60);
    }

/*     Read the data counts from the DAS transfer file. These will be */
/*     useful in determining which data types to expect in the text file */
/*     when converting back to binary. */

    rdenci_(__global_state, xfrlun, &__state->c__1, &ncdata);
    rdenci_(__global_state, xfrlun, &__state->c__1, &nddata);
    rdenci_(__global_state, xfrlun, &__state->c__1, &nidata);

/*     Process the character data array, if there is some character data. */

    if (ncdata > 0) {

/*        Initialize a few things: the block counter, and the data */
/*        counter. */

	blkcnt = 0;
	dtacnt = 0;

/*        We currently have more to process. */

	more = TRUE_;

/*        We are currently not processing a data block. */

	inblk = FALSE_;
	while(more) {
	    ci__1.cierr = 1;
	    ci__1.ciend = 1;
	    ci__1.ciunit = *xfrlun;
	    ci__1.cifmt = "(A)";
	    iostat = s_rsfe(&__global_state->f2c, &ci__1);
	    if (iostat != 0) {
		goto L100004;
	    }
	    iostat = do_fio(&__global_state->f2c, &__state->c__1, line, (
		    ftnlen)255);
	    if (iostat != 0) {
		goto L100004;
	    }
	    iostat = e_rsfe(&__global_state->f2c);
L100004:
	    if (iostat != 0) {

/*              If an error occurred while reading from the encoded text */
/*              DAS file close the binary file, set an appropriate error */
/*              message, then check out and return. */

		dascls_(__global_state, &handle);
		setmsg_(__global_state, "Error reading from the DAS transfer"
			" file #. IOSTAT = #.", (ftnlen)55);
		errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		errint_(__global_state, "#", &iostat, (ftnlen)1);
		sigerr_(__global_state, "SPICE(FILEREADFAILED)", (ftnlen)21);
		chkout_(__global_state, "DASTB", (ftnlen)5);
		return 0;
	    }

/*           At this point, we should be beginning a data block, ending a */
/*           data block, or scanning for the total number of data blocks. */
/*           So look for the appropriate keyword. */

	    nextwd_(__global_state, line, word, rest, (ftnlen)255, (ftnlen)
		    255, (ftnlen)255);
	    if (s_cmp(&__global_state->f2c, word, "BEGIN_CHARACTER_BLOCK", (
		    ftnlen)255, (ftnlen)21) == 0) {

/*              Get the block number. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &bindex, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the begin block */
/*                 index, close the binary file, set an appropriate */
/*                 error  message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Begin character block error, co"
			    "uld not parse block number. Error: # File: #", (
			    ftnlen)75);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Parse the count of characters in the block. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &bcount, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the beginning */
/*                 data count, close the binary file, set an */
/*                 appropriate error message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Begin character block error, co"
			    "uld not parse the data count for block: #. Error"
			    ": # File: #", (ftnlen)90);
		    errint_(__global_state, "#", &bindex, (ftnlen)1);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              If we got to here, we are inside a data block, so set */
/*              the in block flag, INBLK, to .TRUE. and increment the */
/*              data block counter. */

		inblk = TRUE_;
		++blkcnt;
	    } else if (s_cmp(&__global_state->f2c, word, "END_CHARACTER_BLOCK"
		    , (ftnlen)255, (ftnlen)19) == 0) {

/*              Get the data block index. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &eindex, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the end block */
/*                 index, close the binary file, set an appropriate */
/*                 error message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "End character block error, coul"
			    "d not parse block number. Error: # File: #", (
			    ftnlen)73);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Parse the count of characters in the DAS array. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &ecount, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the ending data */
/*                 count, close the binary file, set an appropriate */
/*                 error message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "End character block error, coul"
			    "d not parse the data count for block: #. Error: "
			    "# File: #", (ftnlen)88);
		    errint_(__global_state, "#", &eindex, (ftnlen)1);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Check to see if the beginning and ending array indices */
/*              match. */

		if (eindex != bindex) {

/*                 If the begin and end data block indices do not match, */
/*                 close the binary file, set an appropriate error */
/*                 message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Character block index mismatch:"
			    " Beginning index: #; Ending index: #. File: #", (
			    ftnlen)76);
		    errint_(__global_state, "#", &bindex, (ftnlen)1);
		    errint_(__global_state, "#", &eindex, (ftnlen)1);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Check to see if the beginning and ending array data */
/*              counts match. */

		if (ecount != bcount) {

/*                 If the begin and end data block counts do not match, */
/*                 close the binary file, set an appropriate error */
/*                 message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Character block count mismatch:"
			    " Beginning count: #; Ending count: #. File: #", (
			    ftnlen)76);
		    errint_(__global_state, "#", &bcount, (ftnlen)1);
		    errint_(__global_state, "#", &ecount, (ftnlen)1);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              If we got to here, we have successfully ended the */
/*              processing of a data block, so set the in block flag, */
/*              INBLK, to  .FALSE.. */

		inblk = FALSE_;
	    } else if (s_cmp(&__global_state->f2c, word, "TOTAL_CHARACTER_BL"
		    "OCKS", (ftnlen)255, (ftnlen)22) == 0) {

/*              We have the total data blocks keyword to parse, so get */
/*              the total number of character data blocks processed. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &numblk, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the total number of */
/*                 data blocks, close the binary file, set an appropriate */
/*                 error  message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Block count error, could not pa"
			    "rse the total number of character blocks: #. Fil"
			    "e: #", (ftnlen)83);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Parse the total count of characters. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &tcount, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the character */
/*                 data count, close the binary file, set an */
/*                 appropriate error message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Character count error, could no"
			    "t parse the total count. Error: # File: #", (
			    ftnlen)72);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Compare the computed block count with the block count */
/*              from the file. */

		if (blkcnt != numblk) {

/*                 If the  calculated data block count and the data */
/*                 block count from the text file do not match, close */
/*                 the binary file, set an appropriate error message, */
/*                 then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "The number of character data bl"
			    "ocks processed (#) was not equal to the number o"
			    "f character data blocks placed in the DAS transf"
			    "er file (#). File: #", (ftnlen)147);
		    errint_(__global_state, "#", &blkcnt, (ftnlen)1);
		    errint_(__global_state, "#", &numblk, (ftnlen)1);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Check to see if the total count and the computed count */
/*              match. */

		if (tcount != dtacnt) {

/*                 If the total count and computed count do not match, */
/*                 close the binary file, set an appropriate error */
/*                 message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Character count mismatch: compu"
			    "ted count: #; expected count: #. File: #", (
			    ftnlen)71);
		    errint_(__global_state, "#", &dtacnt, (ftnlen)1);
		    errint_(__global_state, "#", &tcount, (ftnlen)1);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              If we got to here, we have successfully processed the */
/*              entire character data portion of the DAS transfer file, */
/*              so there is no more character data. */

		more = FALSE_;
	    } else {

/*              We got an unknown keyword of some sort, so set an */
/*              appropriate error message, close the DAS file, and */
/*              return. */

		dascls_(__global_state, &handle);
		setmsg_(__global_state, "Unknown keyword '#' encountered whi"
			"le processing the DAS transfer file #.", (ftnlen)73);
		errch_(__global_state, "#", word, (ftnlen)1, (ftnlen)255);
		errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (ftnlen)
			25);
		chkout_(__global_state, "DASTB", (ftnlen)5);
		return 0;
	    }

/*           If we have begun a block, then process it. Otherwise, we */
/*           have ended a block. */

	    if (inblk) {

/*              Read and decode the data in the current DAS character */
/*              array data block. */

/*              Set the count of characters yet to be decoded and placed */
/*              in the binary DAS file. */

		numlft = bcount;
		while(numlft > 0) {

/*                 Now read and decode the data in the current */
/*                 character data block, placing the data in the */
/*                 character array in the binary DAS file. */

		    if (numlft >= 4096) {
			numdta = 4096;
		    } else {
			numdta = numlft;
		    }

/*                 Read and decode a buffer of encoded character data */
/*                 from the text file. */

		    rdencc_(__global_state, xfrlun, &numdta, cbuffr, (ftnlen)
			    4);

/*                 Write the character data to the DAS character */
/*                 array in the binary DAS file. */

		    dasadc_(__global_state, &handle, &numdta, &__state->c__1, 
			    &__state->c__4, cbuffr, (ftnlen)4);
		    if (failed_(__global_state)) {

/*                    If an error occurred, attempt to close the */
/*                    binary file, then checkout and return. */

			dascls_(__global_state, &handle);
			chkout_(__global_state, "DASTB", (ftnlen)5);
			return 0;
		    }

/*                 Decrement the counter for the amount of data */
/*                 remaining to be moved from the current data block, */
/*                 NUMLFT. */

		    numlft -= numdta;

/*                 Increment the counter for the amount of data that */
/*                 has been successfully moved into the current array */
/*                 in the binary DAS file. */

		    dtacnt += numdta;

/*                 At this point, we have either finished reading in an */
/*                 entire data block, or we have more data to read in */
/*                 the current data block. */

		}
	    }

/*           If we got to here, we have successfully written a data */
/*           block to the binary file. */

	}

/*        At this point, we will have successfully written the entire */
/*        character data array to the binary DAS file, if there was */
/*        any character data to be written. */
    }

/*     Process the double precision data array, if there is some */
/*     double precision data. */

    if (nddata > 0) {

/*        Initialize a few things: the block counter, and the data */
/*        counter. */

	blkcnt = 0;
	dtacnt = 0;

/*        We currently have more to process. */

	more = TRUE_;

/*        We are currently not processing a data block. */

	inblk = FALSE_;
	while(more) {
	    ci__1.cierr = 1;
	    ci__1.ciend = 1;
	    ci__1.ciunit = *xfrlun;
	    ci__1.cifmt = "(A)";
	    iostat = s_rsfe(&__global_state->f2c, &ci__1);
	    if (iostat != 0) {
		goto L100005;
	    }
	    iostat = do_fio(&__global_state->f2c, &__state->c__1, line, (
		    ftnlen)255);
	    if (iostat != 0) {
		goto L100005;
	    }
	    iostat = e_rsfe(&__global_state->f2c);
L100005:
	    if (iostat != 0) {

/*              If an error occurred while reading from the encoded text */
/*              DAS file close the binary file, set an appropriate error */
/*              message, then check out and return. */

		dascls_(__global_state, &handle);
		setmsg_(__global_state, "Error reading from the DAS transfer"
			" file #. IOSTAT = #.", (ftnlen)55);
		errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		errint_(__global_state, "#", &iostat, (ftnlen)1);
		sigerr_(__global_state, "SPICE(FILEREADFAILED)", (ftnlen)21);
		chkout_(__global_state, "DASTB", (ftnlen)5);
		return 0;
	    }

/*           At this point, we should be beginning a data block, ending a */
/*           data block, or scanning for the total number of data blocks. */
/*           So look for the appropriate keyword. */

	    nextwd_(__global_state, line, word, rest, (ftnlen)255, (ftnlen)
		    255, (ftnlen)255);
	    if (s_cmp(&__global_state->f2c, word, "BEGIN_DP_BLOCK", (ftnlen)
		    255, (ftnlen)14) == 0) {

/*              Get the block number. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &bindex, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the begin block */
/*                 index, close the binary file, set an appropriate */
/*                 error  message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Begin double precision block er"
			    "ror, could not parse block number. Error: # File"
			    ": #", (ftnlen)82);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Parse the count of double precision numbers in the block. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &bcount, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the beginning */
/*                 data count, close the binary file, set an */
/*                 appropriate error message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Begin double precision block er"
			    "ror, could not parse the data count for block: #"
			    ". Error: # File: #", (ftnlen)97);
		    errint_(__global_state, "#", &bindex, (ftnlen)1);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              If we got to here, we are inside a data block, so set */
/*              the in block flag, INBLK, to .TRUE. and increment the */
/*              data block counter. */

		inblk = TRUE_;
		++blkcnt;
	    } else if (s_cmp(&__global_state->f2c, word, "END_DP_BLOCK", (
		    ftnlen)255, (ftnlen)12) == 0) {

/*              Get the data block index. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &eindex, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the end block */
/*                 index, close the binary file, set an appropriate */
/*                 error message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "End double precision block erro"
			    "r, could not parse block number. Error: # File: #"
			    , (ftnlen)80);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Parse the count of double precision numbers in the block. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &ecount, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the ending data */
/*                 count, close the binary file, set an appropriate */
/*                 error message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "End double precision block erro"
			    "r, could not parse the data count for block: #. "
			    "Error: # File: #", (ftnlen)95);
		    errint_(__global_state, "#", &eindex, (ftnlen)1);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Check to see if the beginning and ending array indices */
/*              match. */

		if (eindex != bindex) {

/*                 If the begin and end data block indices do not match, */
/*                 close the binary file, set an appropriate error */
/*                 message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Double precision block index mi"
			    "smatch: Beginning index: #; Ending index: #. Fil"
			    "e: #", (ftnlen)83);
		    errint_(__global_state, "#", &bindex, (ftnlen)1);
		    errint_(__global_state, "#", &eindex, (ftnlen)1);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Check to see if the beginning and ending array data */
/*              counts match. */

		if (ecount != bcount) {

/*                 If the begin and end data block counts do not match, */
/*                 close the binary file, set an appropriate error */
/*                 message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Double precision block count mi"
			    "smatch: Beginning count: #; Ending count: #. Fil"
			    "e: #", (ftnlen)83);
		    errint_(__global_state, "#", &bcount, (ftnlen)1);
		    errint_(__global_state, "#", &ecount, (ftnlen)1);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              If we got to here, we have successfully ended the */
/*              processing of a data block, so set the in block flag, */
/*              INBLK, to  .FALSE.. */

		inblk = FALSE_;
	    } else if (s_cmp(&__global_state->f2c, word, "TOTAL_DP_BLOCKS", (
		    ftnlen)255, (ftnlen)15) == 0) {

/*              We have the total data blocks keyword to parse, so get */
/*              the total number of character data blocks processed. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &numblk, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the total number of */
/*                 data blocks, close the binary file, set an appropriate */
/*                 error  message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Block count error, could not pa"
			    "rse the total number of double precision data bl"
			    "ocks: #. File: #", (ftnlen)95);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Parse the total count of double precision numbers. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &tcount, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the double */
/*                 precision data count, close the binary file, set an */
/*                 appropriate error message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Double precision count error, c"
			    "ould not parse the total count. Error: # File: #",
			     (ftnlen)79);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Compare the computed block count with the block count */
/*              from the file. */

		if (blkcnt != numblk) {

/*                 If the  calculated data block count and the data */
/*                 block count from the text file do not match, close */
/*                 the binary file, set an appropriate error message, */
/*                 then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "The number of double precision "
			    "data blocks processed (#) was not equal to the n"
			    "umber of double precision data blocks placed in "
			    "the DAS transfer file (#). File: #", (ftnlen)161);
		    errint_(__global_state, "#", &blkcnt, (ftnlen)1);
		    errint_(__global_state, "#", &numblk, (ftnlen)1);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Check to see if the total count and the computed count */
/*              match. */

		if (tcount != dtacnt) {

/*                 If the total count and computed count do not match, */
/*                 close the binary file, set an appropriate error */
/*                 message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Double precision count mismatch"
			    ": computed count: #; expected count: #. File: #", 
			    (ftnlen)78);
		    errint_(__global_state, "#", &dtacnt, (ftnlen)1);
		    errint_(__global_state, "#", &tcount, (ftnlen)1);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              If we got to here, we have successfully processed the */
/*              entire DAS double precision data portion of the text */
/*              file, so there is no more double precision data. */

		more = FALSE_;
	    } else {

/*              We got an unknown keyword of some sort, so set an */
/*              appropriate error message, close the DAS file, and */
/*              return. */

		dascls_(__global_state, &handle);
		setmsg_(__global_state, "Unknown keyword '#' encountered whi"
			"le processing the DAS transfer  file #.", (ftnlen)74);
		errch_(__global_state, "#", word, (ftnlen)1, (ftnlen)255);
		errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (ftnlen)
			25);
		chkout_(__global_state, "DASTB", (ftnlen)5);
		return 0;
	    }

/*           If we have begun a block, then process it. Otherwise, we */
/*           have ended a block. */
	    if (inblk) {

/*              Read and decode the data in the current DAS double */
/*              precision array data block. */

/*              Set the count of double precision numbers yet to be */
/*              decoded and placed in the binary DAS file. */

		numlft = bcount;
		while(numlft > 0) {

/*                 Now read and decode the data in the current double */
/*                 precision data block, placing the data in the double */
/*                 precision array in the binary DAS file. */

		    if (numlft >= 1024) {
			numdta = 1024;
		    } else {
			numdta = numlft;
		    }

/*                 Read and decode a buffer of encoded double precision */
/*                 data from the text file. */

		    rdencd_(__global_state, xfrlun, &numdta, dbuffr);

/*                 Write the double precision data to the DAS double */
/*                 precision array in the binary DAS file. */

		    dasadd_(__global_state, &handle, &numdta, dbuffr);
		    if (failed_(__global_state)) {

/*                    If an error occurred, attempt to close the */
/*                    binary file, then checkout and return. */

			dascls_(__global_state, &handle);
			chkout_(__global_state, "DASTB", (ftnlen)5);
			return 0;
		    }

/*                 Decrement the counter for the amount of data */
/*                 remaining to be moved from the current data block, */
/*                 NUMLFT. */

		    numlft -= numdta;

/*                 Increment the counter for the amount of data that */
/*                 has been successfully moved into the current array */
/*                 in the binary DAS file. */

		    dtacnt += numdta;

/*                 At this point, we have either finished reading in an */
/*                 entire data block, or there is still some data */
/*                 remaining to be read. */

		}
	    }

/*           If we got to here, we have successfully written a data */
/*           block to the binary file. */

	}

/*        At this point, we will have successfully written the entire */
/*        double precision data array to the binary DAS file, if there */
/*        was any double precision data to be written. */
    }

/*     Process the integer data array, if there is some integer data. */

    if (nidata > 0) {

/*        Initialize a few things: the block counter, and the data */
/*        counter. */

	blkcnt = 0;
	dtacnt = 0;

/*        We currently have more to process. */

	more = TRUE_;

/*        We are currently not processing a data block. */

	inblk = FALSE_;
	while(more) {
	    ci__1.cierr = 1;
	    ci__1.ciend = 1;
	    ci__1.ciunit = *xfrlun;
	    ci__1.cifmt = "(A)";
	    iostat = s_rsfe(&__global_state->f2c, &ci__1);
	    if (iostat != 0) {
		goto L100006;
	    }
	    iostat = do_fio(&__global_state->f2c, &__state->c__1, line, (
		    ftnlen)255);
	    if (iostat != 0) {
		goto L100006;
	    }
	    iostat = e_rsfe(&__global_state->f2c);
L100006:
	    if (iostat != 0) {

/*              If an error occurred while reading from the encoded text */
/*              DAS file close the binary file, set an appropriate error */
/*              message, then check out and return. */

		dascls_(__global_state, &handle);
		setmsg_(__global_state, "Error reading from the DAS transfer"
			" file #. IOSTAT = #.", (ftnlen)55);
		errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		errint_(__global_state, "#", &iostat, (ftnlen)1);
		sigerr_(__global_state, "SPICE(FILEREADFAILED)", (ftnlen)21);
		chkout_(__global_state, "DASTB", (ftnlen)5);
		return 0;
	    }

/*           At this point, we should be beginning a data block, ending a */
/*           data block, or scanning for the total number of data blocks. */
/*           So look for the appropriate keyword. */

	    nextwd_(__global_state, line, word, rest, (ftnlen)255, (ftnlen)
		    255, (ftnlen)255);
	    if (s_cmp(&__global_state->f2c, word, "BEGIN_INTEGER_BLOCK", (
		    ftnlen)255, (ftnlen)19) == 0) {

/*              Get the block number. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &bindex, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the begin block */
/*                 index, close the binary file, set an appropriate */
/*                 error  message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Begin integer block error, coul"
			    "d not parse block number. Error: # File: #", (
			    ftnlen)73);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Parse the count of integers in the block. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &bcount, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the beginning */
/*                 data count, close the binary file, set an */
/*                 appropriate error message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Begin integer block error, coul"
			    "d not parse the data count for  block: #. Error:"
			    " # File: #", (ftnlen)89);
		    errint_(__global_state, "#", &bindex, (ftnlen)1);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              If we got to here, we are inside a data block, so set */
/*              the in block flag, INBLK, to .TRUE. and increment the */
/*              data block counter. */

		inblk = TRUE_;
		++blkcnt;
	    } else if (s_cmp(&__global_state->f2c, word, "END_INTEGER_BLOCK", 
		    (ftnlen)255, (ftnlen)17) == 0) {

/*              Get the data block index. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &eindex, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the end block */
/*                 index, close the binary file, set an appropriate */
/*                 error message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "End integer block error, could "
			    "not parse block number. Error: # File: #", (
			    ftnlen)71);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Parse the count of integers in the block. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &ecount, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the ending data */
/*                 count, close the binary file, set an appropriate */
/*                 error message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "End integer block error, could "
			    "not parse the data count for block: #.Error: # F"
			    "ile: #", (ftnlen)85);
		    errint_(__global_state, "#", &eindex, (ftnlen)1);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Check to see if the beginning and ending array indices */
/*              match. */

		if (eindex != bindex) {

/*                 If the begin and end data block indices do not match, */
/*                 close the binary file, set an appropriate error */
/*                 message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Integer block index mismatch: B"
			    "eginning index: #; Ending index: #. File: #", (
			    ftnlen)74);
		    errint_(__global_state, "#", &bindex, (ftnlen)1);
		    errint_(__global_state, "#", &eindex, (ftnlen)1);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Check to see if the beginning and ending array data */
/*              counts match. */

		if (ecount != bcount) {

/*                 If the begin and end data block counts do not match, */
/*                 close the binary file, set an appropriate error */
/*                 message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Integer block count mismatch: B"
			    "eginning count: #; Ending count: #. File: #", (
			    ftnlen)74);
		    errint_(__global_state, "#", &bcount, (ftnlen)1);
		    errint_(__global_state, "#", &ecount, (ftnlen)1);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              If we got to here, we have successfully ended the */
/*              processing of a data block, so set the in block flag, */
/*              INBLK, to .FALSE.. */

		inblk = FALSE_;
	    } else if (s_cmp(&__global_state->f2c, word, "TOTAL_INTEGER_BLOC"
		    "KS", (ftnlen)255, (ftnlen)20) == 0) {

/*              We have the total data blocks keyword to parse, so get */
/*              the total number of character data blocks processed. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &numblk, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the total number of */
/*                 data blocks, close the binary file, set an appropriate */
/*                 error  message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Block count error, could not pa"
			    "rse the total number of integer data blocks: #. "
			    "File: #", (ftnlen)86);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Parse the total count of integers. */

		nextwd_(__global_state, rest, word, rest, (ftnlen)255, (
			ftnlen)255, (ftnlen)255);
		nparsi_(__global_state, word, &tcount, errmsg, &errptr, (
			ftnlen)255, (ftnlen)320);
		if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (
			ftnlen)1) != 0) {

/*                 If an error occurred while parsing the integer */
/*                 data count, close the binary file, set an */
/*                 appropriate error message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Integer count error, could not "
			    "parse the total count. Error: # File: #", (ftnlen)
			    70);
		    errch_(__global_state, "#", errmsg, (ftnlen)1, (ftnlen)
			    320);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Compare the computed block count with the block count */
/*              from the file. */

		if (blkcnt != numblk) {

/*                 If the  calculated data block count and the data */
/*                 block count from the text file do not match, close */
/*                 the binary file, set an appropriate error message, */
/*                 then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "The number of integer data bloc"
			    "ks processed (#) was not equal to the number of "
			    "integer data blocks placed in the DAS transfer f"
			    "ile (#). File: #", (ftnlen)143);
		    errint_(__global_state, "#", &blkcnt, (ftnlen)1);
		    errint_(__global_state, "#", &numblk, (ftnlen)1);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              Check to see if the total count and the computed count */
/*              match. */

		if (tcount != dtacnt) {

/*                 If the total count and computed count do not match, */
/*                 close the binary file, set an appropriate error */
/*                 message, then check out and return. */

		    dascls_(__global_state, &handle);
		    setmsg_(__global_state, "Integer count mismatch: compute"
			    "d count: #; expected count: #. File: #", (ftnlen)
			    69);
		    errint_(__global_state, "#", &dtacnt, (ftnlen)1);
		    errint_(__global_state, "#", &tcount, (ftnlen)1);
		    errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		    sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (
			    ftnlen)25);
		    chkout_(__global_state, "DASTB", (ftnlen)5);
		    return 0;
		}

/*              If we got to here, we have successfully processed the */
/*              entire DAS integer data portion of the text file, so */
/*              there is no more integer data. */

		more = FALSE_;
	    } else {

/*              We got an unknown keyword of some sort, so set an */
/*              appropriate error message, close the DAS file, and */
/*              return. */

		dascls_(__global_state, &handle);
		setmsg_(__global_state, "Unknown keyword '#' encountered whi"
			"le processing the DAS transfer  file #.", (ftnlen)74);
		errch_(__global_state, "#", word, (ftnlen)1, (ftnlen)255);
		errfnm_(__global_state, "#", xfrlun, (ftnlen)1);
		sigerr_(__global_state, "SPICE(BADDASTRANSFERFILE)", (ftnlen)
			25);
		chkout_(__global_state, "DASTB", (ftnlen)5);
		return 0;
	    }

/*           If we have begun a block, then process it. Otherwise, we */
/*           have ended a block. */
	    if (inblk) {

/*              Read and decode the data in the current DAS integer */
/*              array data block. */

/*              Set the count of integers yet to be decoded and placed */
/*              in the binary DAS file. */

		numlft = bcount;
		while(numlft > 0) {

/*                 Now read and decode the data in the current */
/*                 integer data block, placing the data in the */
/*                 integer precision array in the binary DAS file. */

		    if (numlft >= 1024) {
			numdta = 1024;
		    } else {
			numdta = numlft;
		    }

/*                 Read and decode a buffer of encoded integer data */
/*                 from the text file. */

		    rdenci_(__global_state, xfrlun, &numdta, ibuffr);

/*                 Write the integer data to the DAS integer array in */
/*                 the binary DAS file. */

		    dasadi_(__global_state, &handle, &numdta, ibuffr);
		    if (failed_(__global_state)) {

/*                    If an error occurred, attempt to close the */
/*                    binary file, then checkout and return. */

			dascls_(__global_state, &handle);
			chkout_(__global_state, "DASTB", (ftnlen)5);
			return 0;
		    }

/*                 Decrement the counter for the amount of data */
/*                 remaining to be moved from the current data block, */
/*                 NUMLFT. */

		    numlft -= numdta;

/*                 Increment the counter for the amount of data that */
/*                 has been successfully moved into the current array */
/*                 in the binary DAS file. */

		    dtacnt += numdta;

/*                 At this point, we have either finished reading in an */
/*                 entire data block, or there is still data remaining */
/*                 to be read. */

		}
	    }

/*           If we got to here, we have successfully written a data */
/*           block to the binary file. */

	}

/*        At this point, we will have successfully written the entire */
/*        integer data array to the binary DAS file, if there was any */
/*        integer data to be written. */
    }

/*     Close only the binary file. */

    dascls_(__global_state, &handle);
    chkout_(__global_state, "DASTB", (ftnlen)5);
    return 0;
} /* dastb_ */

