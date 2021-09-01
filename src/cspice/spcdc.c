/* spcdc.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int spcdc_state_t;
static spcdc_state_t* get_spcdc_state(cspice_t* state) {
	return 0;
}

/* $Procedure SPCDC ( SPK and CK, delete comments ) */
/* Subroutine */ int spcdc_(cspice_t* __global_state, integer *handle)
{
    integer free;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer bward;
    integer fward;
    integer nd;
    integer ni;
    char ifname[60];
    extern /* Subroutine */ int dafrfr_(cspice_t*, integer *, integer *, 
	    integer *, char *, integer *, integer *, integer *, ftnlen);
    extern /* Subroutine */ int dafrrr_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);
    integer nrr;


    /* Module state */
    spcdc_state_t* __state = get_spcdc_state(__global_state);
/* $ Abstract */

/*     Empty the comment area of a binary SPK or CK file. */

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

/* $ Detailed_Input */

/*     HANDLE      is the handle assigned to the binary SPK or CK file */
/*                 which has been opened for write access. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If the file does not contain any comments in its comment area */
/*        on input, it will be unchanged by this routine. */

/* $ Files */

/*     HANDLE      is the handle assigned to the binary SPK or CK file. */
/*                 Use DAFOPW to open it for write access and get its */
/*                 handle.  Upon exit, this binary file will have an */
/*                 empty comment area:  all previous comments are */
/*                 deleted.  Note, however, that the size of the */
/*                 file does not change. */

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

/*     1)  Suppose we have a binary SPK file called A.BSP.  The following */
/*         code fragment deletes any comments that may have been stored */
/*         in the comment area of the file. */

/*                 CALL DAFOPW ( 'A.BSP', HANDLE ) */

/*                 CALL SPCDC  ( HANDLE ) */

/*     2)  Suppose B.BSP is a binary SPK file with comments in its */
/*         comment area.  The routine TXTOPN opens a new text file. */

/*           C */
/*           C     Open the binary SPK file with write access and */
/*           C     get its handle. */
/*           C */
/*                 CALL DAFOPW ( 'B.BSP', HANDLE ) */

/*           C */
/*           C     Open a new text file and write the comments */
/*           C     from the SPK file to it. */
/*           C */
/*                 CALL TXTOPN ( 'COMMENTS.TXT',   UNIT1 ) */
/*                 CALL SPCEC  ( HANDLE,           UNIT1 ) */

/*           C */
/*           C     Delete the comments in the SPK file. */
/*           C */
/*                 CALL SPCDC  ( HANDLE ) */

/*           C */
/*           C     Open another new text file and try to write */
/*           C     comments from the SPK file to it. */
/*           C */
/*                 CALL TXTOPN ( 'NOCOMMENTS.TXT', UNIT2 ) */
/*                 CALL SPCEC  ( HANDLE,           UNIT2 ) */

/*         After executing this code fragment, COMMENTS.TXT would */
/*         contain the comments from the SPK file.  NOCOMMENTS.TXT */
/*         would be empty because of the call to SPCDC. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     J.E. McLean (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 05-APR-1991 (JEM) */

/* -& */
/* $ Index_Entries */

/*     delete comments from spk or ck file */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */

/*     IFNLEN      is the length of a DAF internal file name. */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "SPCDC", (ftnlen)5);
    }

/*     The comment area IS the reserved records.  To empty the comment */
/*     area we just remove the reserved records. */

/*     Read the file record to find out how many reserved records are */
/*     in the DAF.  The reserved records are stored between the first */
/*     record (the file record) and the first summary record.  FWARD */
/*     is the record number of that first summary record, and NRR is */
/*     the number of reserved records in the file. */

    dafrfr_(__global_state, handle, &nd, &ni, ifname, &fward, &bward, &free, (
	    ftnlen)60);
    nrr = fward - 2;

/*     Once we know how many there are, we can remove them. */

    dafrrr_(__global_state, handle, &nrr);
    chkout_(__global_state, "SPCDC", (ftnlen)5);
    return 0;
} /* spcdc_ */

