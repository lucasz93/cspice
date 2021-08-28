/* zzeksinf.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzeksinf_init_t __zzeksinf_init;
static inline zzeksinf_state_t* get_zzeksinf_state(cspice_t* state) {
	if (!state->zzeksinf)
		state->zzeksinf = __cspice_allocate_module(sizeof(
	zzeksinf_state_t), &__zzeksinf_init, sizeof(__zzeksinf_init));
	return state->zzeksinf;

}

/* $Procedure      ZZEKSINF ( EK, return segment information ) */
/* Subroutine */ int zzeksinf_(cspice_t* __global_state, integer *handle, 
	integer *segno, char *tabnam, integer *segdsc, char *cnames, integer *
	cdscrs, ftnlen tabnam_len, ftnlen cnames_len)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer i_len(f2c_state_t*, char *, ftnlen);
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer base;
    integer nseg;
    extern /* Subroutine */ int zzekpgch_(cspice_t*, integer *, char *, 
	    ftnlen);
    extern /* Subroutine */ int zzekmloc_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    integer i__;
    integer p;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer ncols;
    extern logical failed_(cspice_t*);
    extern /* Subroutine */ int dasrdc_(cspice_t*, integer *, integer *, 
	    integer *, integer *, integer *, char *, ftnlen);
    extern /* Subroutine */ int dasrdi_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    extern integer eknseg_(cspice_t*, integer *);
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);


    /* Module state */
    zzeksinf_state_t* __state = get_zzeksinf_state(__global_state);
/* $ Abstract */

/*     Return general segment information for a specified segment in a */
/*     specified EK. */

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

/*     EK */

/* $ Keywords */

/*     EK */
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


/*     Include Section:  EK Column Name Size */

/*        ekcnamsz.inc Version 1    17-JAN-1995 (NJB) */


/*     Size of column name, in characters. */


/*     End Include Section:  EK Column Name Size */

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


/*     Include Section:  EK Column Descriptor Parameters */

/*        ekcoldsc.inc Version 6    23-AUG-1995 (NJB) */


/*     Note:  The column descriptor size parameter CDSCSZ  is */
/*     declared separately in the include section CDSIZE$INC.FOR. */

/*     Offset of column descriptors, relative to start of segment */
/*     integer address range.  This number, when added to the last */
/*     integer address preceding the segment, yields the DAS integer */
/*     base address of the first column descriptor.  Currently, this */
/*     offset is exactly the size of a segment descriptor.  The */
/*     parameter SDSCSZ, which defines the size of a segment descriptor, */
/*     is declared in the include file eksegdsc.inc. */


/*     Size of column descriptor */


/*     Indices of various pieces of column descriptors: */


/*     CLSIDX is the index of the column's class code.  (We use the */
/*     word `class' to distinguish this item from the column's data */
/*     type.) */


/*     TYPIDX is the index of the column's data type code (CHR, INT, DP, */
/*     or TIME).  The type is actually implied by the class, but it */
/*     will frequently be convenient to look up the type directly. */



/*     LENIDX is the index of the column's string length value, if the */
/*     column has character type.  A value of IFALSE in this element of */
/*     the descriptor indicates that the strings have variable length. */


/*     SIZIDX is the index of the column's element size value.  This */
/*     descriptor element is meaningful for columns with fixed-size */
/*     entries.  For variable-sized columns, this value is IFALSE. */


/*     NAMIDX is the index of the base address of the column's name. */


/*     IXTIDX is the data type of the column's index.  IXTIDX */
/*     contains a type value only if the column is indexed. For columns */
/*     that are not indexed, the location IXTIDX contains the boolean */
/*     value IFALSE. */


/*     IXPIDX is a pointer to the column's index.  IXTPDX contains a */
/*     meaningful value only if the column is indexed.  The */
/*     interpretation of the pointer depends on the data type of the */
/*     index. */


/*     NFLIDX is the index of a flag indicating whether nulls are */
/*     permitted in the column.  The value at location NFLIDX is */
/*     ITRUE if nulls are permitted and IFALSE otherwise. */


/*     ORDIDX is the index of the column's ordinal position in the */
/*     list of columns belonging to the column's parent segment. */


/*     METIDX is the index of the column's integer metadata pointer. */
/*     This pointer is a DAS integer address. */


/*     The last position in the column descriptor is reserved.  No */
/*     parameter is defined to point to this location. */


/*     End Include Section:  EK Column Descriptor Parameters */

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


/*     Include Section:  EK Segment Descriptor Parameters */

/*        eksegdsc.inc  Version 8  06-NOV-1995 (NJB) */


/*     All `base addresses' referred to below are the addresses */
/*     *preceding* the item the base applies to.  This convention */
/*     enables simplied address calculations in many cases. */

/*     Size of segment descriptor.  Note:  the include file ekcoldsc.inc */
/*     must be updated if this parameter is changed.  The parameter */
/*     CDOFF in that file should be kept equal to SDSCSZ. */


/*     Index of the segment type code: */


/*     Index of the segment's number.  This number is the segment's */
/*     index in the list of segments contained in the EK to which */
/*     the segment belongs. */


/*     Index of the DAS integer base address of the segment's integer */
/*     meta-data: */


/*     Index of the DAS character base address of the table name: */


/*     Index of the segment's column count: */


/*     Index of the segment's record count: */


/*     Index of the root page number of the record tree: */


/*     Index of the root page number of the character data page tree: */


/*     Index of the root page number of the double precision data page */
/*     tree: */


/*     Index of the root page number of the integer data page tree: */


/*     Index of the `modified' flag: */


/*     Index of the `initialized' flag: */


/*     Index of the shadowing flag: */


/*     Index of the companion file handle: */


/*     Index of the companion segment number: */


/*     The next three items are, respectively, the page numbers of the */
/*     last character, d.p., and integer data pages allocated by the */
/*     segment: */


/*     The next three items are, respectively, the page-relative */
/*     indices of the last DAS word in use in the segment's */
/*     last character, d.p., and integer data pages: */


/*     Index of the DAS character base address of the column name list: */


/*     The last descriptor element is reserved for future use.  No */
/*     parameter is defined to point to this location. */


/*     End Include Section:  EK Segment Descriptor Parameters */

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


/*     Include Section:  EK Table Name Size */

/*        ektnamsz.inc Version 1    17-JAN-1995 (NJB) */


/*     Size of table name, in characters. */


/*     End Include Section:  EK Table Name Size */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle of EK. */
/*     SEGNO      I   Number of segment to be summarized. */
/*     TABNAM     O   Name of table containing segment. */
/*     SEGDSC     O   Segment descriptor. */
/*     CNAMES     O   Names of columns in segment. */
/*     CDSCRS     O   Descriptors of columns in segment. */

/* $ Detailed_Input */

/*     HANDLE         is an EK file handle.  The file may be open for */
/*                    reading or writing. */

/*     SEGNO          is the number of the segment whose summary is */
/*                    desired.  Segments are numbered from 1 to NSEG, */
/*                    where NSEG is the count of segments in the file. */

/* $ Detailed_Output */

/*     TABNAM         is the name of the table to which the segment */
/*                    belongs. */

/*     SEGDSC         is an EK segment descriptor.  The contents of this */
/*                    integer array are described in the include file */

/*                       eksegdsc.inc. */

/*                    Two commonly used elements of the */
/*                    descriptor are the number of rows in the table */
/*                    and the number of columns in the table.  The */
/*                    indices of these items are given by the parameters */
/*                    NRIDX and NCIDX, respectively. */


/*     CNAMES         is a list of names of data columns in the segment. */

/*     CDSCRS         is a list of descriptors of columns in the segment. */
/*                    Elements (1:CDSCSZ,I) of this integer array */
/*                    comprise the descriptor of the Ith column in the */
/*                    segment.  The contents of a column descriptor are */
/*                    listed below.  The parameters shown in the first */
/*                    subscript of CDSCRS are declared in the include */
/*                    file */

/*                       ekcoldsc.inc. */

/*                    We recommend using these parameters in any calling */
/*                    routine. */

/*                       CDSCRS(CLSIDX,I):    Column class */
/*                       CDSCRS(TYPIDX,I):    Data type */
/*                       CDSCRS(LENIDX,I):    String length */
/*                       CDSCRS(SIZIDX,I):    Element size */
/*                       CDSCRS(NAMIDX,I):    Column name base address */
/*                       CDSCRS(IXTIDX,I):    Column index's type code */
/*                       CDSCRS(IXPIDX,I):    Column index's pointer */
/*                       CDSCRS(NULIDX,I):    Null flag */
/*                       CDSCRS(ORDIDX,I):    Column's ordinal position */
/*                                            in parent table */
/*                       CDSCRS(METIDX,I):    Column's integer metadata */
/*                                            pointer */
/*                       CDSCRS(11,I):        Reserved. */

/*                    Notes: */

/*                       1) Element 3 applies only to character columns. */

/*                          Element 3 takes the boolean value IFALSE */
/*                          if the column contains variable-length */
/*                          strings. */

/*                          The boolean parameter IFALSE is represented */
/*                          by the integer -1. */

/*                       2) Element 4 takes the boolean value IFALSE */
/*                          if the column contains variable-size */
/*                          arrays. */

/*                       3) Element 6 takes the value IFALSE if the */
/*                          column is not indexed. */

/*                       4) Element 8 takes the value IFALSE if null */
/*                          values are not allowed in the column. */
/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If HANDLE is invalid, the error will be diagnosed by routines */
/*         called by this routine.  The output arguments will not be */
/*         modified. */

/*     2)  If SEGNO is not the index of an existing segment in the */
/*         specified file, the error SPICE(INDEXOUTOFRANGE) will be */
/*         signalled.  The output arguments will not be modified. */

/*     3)  If an I/O error occurs while attempting to obtain summary */
/*         information for the specified segment, the error will be */
/*         diagnosed by routines called by this routine.  The output */
/*         arguments may be modified in this case. */

/* $ Files */

/*     See the description of HANDLE in $Detailed_Input. */

/* $ Particulars */

/*     This routine supports the function of summarizing a binary */
/*     EK file, allowing NAIF Toolkit users to determine whether it */
/*     contains data of interest.  The routine also also provides */
/*     address information necessary to retrieve information from the */
/*     segment. */

/* $ Examples */

/*     1)  Dump the table and column names of the segments in an EK. */

/*            C */
/*            C     Open the EK for read access and get the number of */
/*            C     segments it */
/*            C     contains. */
/*            C */
/*                  CALL EKOPR ( EKNAME, HANDLE ) */

/*                  NSEG = EKNSEG ( HANDLE ) */

/*            C */
/*            C     Loop through the segments, dumping the desired */
/*            C     summary information for each one. */
/*            C */
/*                  WRITE (*,*) ' ' */
/*                  WRITE (*,*) ' ' */
/*                  WRITE (*,*) 'Segment summary for file ', EKNAME */
/*                  WRITE (*,*) ' ' */
/*                  WRITE (*,*) ' ' */

/*                  DO I = 1, NSEG */

/*                     CALL ZZEKSINF ( HANDLE,  I,      TABNAM, */
/*                 .                   SEGDSC,  CNAMES, CDSCRS  ) */

/*                     WRITE (*,*) */
/*                 .   '========================================'      // */
/*                 .   '========================================' */


/*                     WRITE (*,*) 'Table containing segment: ', TABNAM */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'Column names: ' */
/*                     WRITE (*,*) ' ' */

/*                     DO J = 1, SEGDSC(NCIDX) */

/*                        WRITE (*,*) '   '//CNAMES(J) */

/*                     END DO */

/*                     WRITE (*,*) */
/*                 .   '========================================'      // */
/*                 .   '========================================' */

/*                  END DO */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    Beta Version 1.1.0, 03-JUL-1996 (NJB) */

/*        Bug fix:  table and column names are now padded with trailing */
/*        blanks on output if necessary. */

/* -    Beta Version 1.0.0, 27-SEP-1995 (NJB) */

/* -& */
/* $ Revisions */

/* -    Beta Version 1.1.0, 03-JUL-1996 (NJB) */

/*        Bug fix:  table and column names are now padded with trailing */
/*        blanks on output if necessary.  Previously, if the caller */
/*        declared these variables with string lengths longer than */
/*        TNAMSZ and CNAMSZ respectively, the trailing characters */
/*        at positions past those designated by these parameters were */
/*        left unassigned on output. */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "ZZEKSINF", (ftnlen)8);
    }

/*     Verify that the target file is a paged DAS EK open for read */
/*     access, or we can't summarize the file. */

    zzekpgch_(__global_state, handle, "READ", (ftnlen)4);
    if (failed_(__global_state)) {
	chkout_(__global_state, "ZZEKSINF", (ftnlen)8);
	return 0;
    }

/*     Find out how many segments are in the file, so we can check */
/*     the index for validity. */

    nseg = eknseg_(__global_state, handle);
    if (*segno < 1 || *segno > nseg) {
	setmsg_(__global_state, "Segment index was #; valid range is 1:#", (
		ftnlen)39);
	errint_(__global_state, "#", segno, (ftnlen)1);
	errint_(__global_state, "#", &nseg, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INDEXOUTOFRANGE)", (ftnlen)22);
	chkout_(__global_state, "ZZEKSINF", (ftnlen)8);
	return 0;
    }

/*     We're ready to proceed.  The first step is to find the */
/*     segment's metadata location and look up the segment descriptor. */

    zzekmloc_(__global_state, handle, segno, &p, &base);
    i__1 = base + 1;
    i__2 = base + 24;
    dasrdi_(__global_state, handle, &i__1, &i__2, segdsc);

/*     Get the table name.  The table's base address is in the segment */
/*     descriptor. */

    i__1 = segdsc[3] + 1;
    i__2 = segdsc[3] + 64;
    dasrdc_(__global_state, handle, &i__1, &i__2, &__state->c__1, &
	    __state->c__64, tabnam, tabnam_len);
    if (i_len(&__global_state->f2c, tabnam, tabnam_len) > 64) {
	s_copy(&__global_state->f2c, tabnam + 64, " ", tabnam_len - 64, (
		ftnlen)1);
    }

/*     Read the column descriptors.  The first one starts at DAS */
/*     integer address */

/*        BASE + CDOFF + 1. */


    ncols = segdsc[4];
    i__1 = base + 25;
    i__2 = base + 24 + ncols * 11;
    dasrdi_(__global_state, handle, &i__1, &i__2, cdscrs);

/*     Now read the column names into the names array. */

    i__1 = segdsc[21] + 1;
    i__2 = segdsc[21] + (ncols << 5);
    dasrdc_(__global_state, handle, &i__1, &i__2, &__state->c__1, &
	    __state->c__32, cnames, cnames_len);
    if (i_len(&__global_state->f2c, cnames, cnames_len) > 32) {
	i__1 = ncols;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    s_copy(&__global_state->f2c, cnames + ((i__ - 1) * cnames_len + 
		    32), " ", cnames_len - 32, (ftnlen)1);
	}
    }

/*     All output arguments are set, or else FAILED() is .TRUE. */

    chkout_(__global_state, "ZZEKSINF", (ftnlen)8);
    return 0;
} /* zzeksinf_ */

