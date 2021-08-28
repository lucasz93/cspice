/* ekinsr.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern ekinsr_init_t __ekinsr_init;
static inline ekinsr_state_t* get_ekinsr_state(cspice_t* state) {
	if (!state->ekinsr)
		state->ekinsr = __cspice_allocate_module(sizeof(
	ekinsr_state_t), &__ekinsr_init, sizeof(__ekinsr_init));
	return state->ekinsr;

}

/* $Procedure      EKINSR ( EK, insert record into segment ) */
/* Subroutine */ int ekinsr_(cspice_t* __global_state, integer *handle, 
	integer *segno, integer *recno)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    integer base;
    integer nrec;
    integer size;
    integer room;
    extern /* Subroutine */ int zzekpgch_(cspice_t*, integer *, char *, 
	    ftnlen);
    extern /* Subroutine */ int zzekrbck_(cspice_t*, char *, integer *, 
	    integer *, integer *, integer *, ftnlen);
    extern /* Subroutine */ int zzekmloc_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    extern /* Subroutine */ int zzekpgbs_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int zzektrin_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    integer p;
    integer mbase;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int filli_(cspice_t*, integer *, integer *, 
	    integer *);
    integer ncols;
    integer lastp;
    integer lastw;
    extern logical failed_(cspice_t*);
    integer coldsc[11];
    integer mp;
    extern logical return_(cspice_t*);
    integer nlinks;
    integer recbas;
    integer recptr[254];
    integer segdsc[24];
    logical isshad;
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int dasrdi_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int cleari_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int ekshdw_(cspice_t*, integer *, logical *);
    extern /* Subroutine */ int dasudi_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    extern /* Subroutine */ int zzekaps_(cspice_t*, integer *, integer *, 
	    integer *, logical *, integer *, integer *);


    /* Module state */
    ekinsr_state_t* __state = get_ekinsr_state(__global_state);
/* $ Abstract */

/*     Add a new, empty record to a specified E-kernel segment at */
/*     a specified index. */

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

/*     PRIVATE */
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


/*     Include Section:  EK Data Page Parameters */

/*        ekfilpar.inc  Version 1  03-APR-1995 (NJB) */

/*     These parameters apply to EK files using architecture 4. */
/*     These files use a paged DAS file as their underlying file */
/*     structure. */

/*     In paged DAS EK files, data pages are structured:  they contain */
/*     metadata as well as data.  The metadata is located in the last */
/*     few addresses of each page, so as to interfere as little as */
/*     possible with calculation of data addresses. */

/*     Each data page belongs to exactly one segment.  Some bookkeeping */
/*     information, such as record pointers, is also stored in data */
/*     pages. */

/*     Each page contains a forward pointer that allows rapid lookup */
/*     of data items that span multiple pages.  Each page also keeps */
/*     track of the current number of links from its parent segment */
/*     to the page.  Link counts enable pages to `know' when they */
/*     are no longer in use by a segment; unused pages are deallocated */
/*     and returned to the free list. */

/*     The parameters in this include file depend on the parameters */
/*     declared in the include file ekpage.inc.  If those parameters */
/*     change, this file must be updated.  The specified parameter */
/*     declarations we need from that file are: */

/*        INTEGER               PGSIZC */
/*        PARAMETER           ( PGSIZC = 1024 ) */

/*        INTEGER               PGSIZD */
/*        PARAMETER           ( PGSIZD = 128 ) */

/*        INTEGER               PGSIZI */
/*        PARAMETER           ( PGSIZI = 256 ) */



/*     Character pages use an encoding mechanism to represent integer */
/*     metadata.  Each integer is encoded in five consecutive */
/*     characters. */


/*     Character data page parameters: */


/*     Size of encoded integer: */


/*     Usable page size: */


/*     Location of character forward pointer: */


/*     Location of character link count: */


/*     Double precision data page parameters: */

/*     Usable page size: */


/*     Location of d.p. forward pointer: */


/*     Location of d.p. link count: */


/*     Integer data page parameters: */

/*     Usable page size: */


/*     Location of integer forward pointer: */


/*     Location of integer link count: */


/*     End Include Section:  EK Data Page Parameters */

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


/*     Include Section:  EK Das Paging Parameters */

/*        ekpage.inc  Version 4    25-AUG-1995 (NJB) */



/*     The EK DAS paging system makes use of the integer portion */
/*     of an EK file's DAS address space to store the few numbers */
/*     required to describe the system's state.  The allocation */
/*     of DAS integer addresses is shown below. */


/*                       DAS integer array */

/*        +--------------------------------------------+ */
/*        |            EK architecture code            |  Address = 1 */
/*        +--------------------------------------------+ */
/*        |      Character page size (in DAS words)    | */
/*        +--------------------------------------------+ */
/*        |        Character page base address         | */
/*        +--------------------------------------------+ */
/*        |      Number of character pages in file     | */
/*        +--------------------------------------------+ */
/*        |   Number of character pages on free list   | */
/*        +--------------------------------------------+ */
/*        |      Character free list head pointer      |  Address = 6 */
/*        +--------------------------------------------+ */
/*        |                                            |  Addresses = */
/*        |           Metadata for d.p. pages          |    7--11 */
/*        |                                            | */
/*        +--------------------------------------------+ */
/*        |                                            |  Addresses = */
/*        |         Metadata for integer pages         |    12--16 */
/*        |                                            | */
/*        +--------------------------------------------+ */
/*                              . */
/*                              . */
/*                              . */
/*        +--------------------------------------------+ */
/*        |                                            |  End Address = */
/*        |                Unused space                |  integer page */
/*        |                                            |  end */
/*        +--------------------------------------------+ */
/*        |                                            |  Start Address = */
/*        |             First integer page             |  integer page */
/*        |                                            |  base */
/*        +--------------------------------------------+ */
/*                              . */
/*                              . */
/*                              . */
/*        +--------------------------------------------+ */
/*        |                                            | */
/*        |              Last integer page             | */
/*        |                                            | */
/*        +--------------------------------------------+ */

/*     The following parameters indicate positions of elements in the */
/*     paging system metadata array: */



/*     Number of metadata items per data type: */


/*     Character metadata indices: */


/*     Double precision metadata indices: */


/*     Integer metadata indices: */


/*     Size of metadata area: */


/*     Page sizes, in units of DAS words of the appropriate type: */


/*     Default page base addresses: */


/*     End Include Section:  EK Das Paging Parameters */

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


/*     Include Section:  EK Record Pointer Parameters */

/*        ekrecptr.inc Version 2  18-JUL-1995 (NJB) */


/*     This file declares parameters used in EK record pointers. */
/*     Each segment references data in a given record via two levels */
/*     of indirection:  a record number points to a record pointer, */
/*     which is a structured array of metadata and data pointers. */

/*     Record pointers always occupy contiguous ranges of integer */
/*     addresses. */

/*     The parameter declarations in this file depend on the assumption */
/*     that integer pages contain 256 DAS integer words and that the */
/*     maximum number of columns in a segment is 100.  Record pointers */
/*     are stored in integer data pages, so they must fit within the */
/*     usable data area afforded by these pages.  The size of the usable */
/*     data area is given by the parameter IPSIZE which is declared in */
/*     ekdatpag.inc.  The assumed value of IPSIZE is 254. */


/*     The first element of each record pointer is a status indicator. */
/*     The meanings of status indicators depend on whether the parent EK */
/*     is shadowed or not.  For shadowed EKs, allowed status values and */
/*     their meanings are: */

/*        OLD       The record has not been modified since */
/*                  the EK containing the record was opened. */

/*        UPDATE    The record is an update of a previously existing */
/*                  record.  The original record is now on the */
/*                  modified record list. */

/*        NEW       The record has been added since the EK containing the */
/*                  record was opened.  The record is not an update */
/*                  of a previously existing record. */

/*        DELOLD    This status applies only to a backup record. */
/*                  DELOLD status indicates that the record corresponds */
/*                  to a deleted OLD record in the source segment. */

/*        DELNEW    This status applies only to a backup record. */
/*                  DELNEW status indicates that the record corresponds */
/*                  to a deleted NEW record in the source segment. */

/*        DELUPD    This status applies only to a backup record. */
/*                  DELUPD status indicates that the record corresponds */
/*                  to a deleted UPDATEd record in the source segment. */

/*     In EKs that are not shadowed, all records have status OLD. */



/*     The following parameters refer to indices within the record */
/*     pointer structure: */

/*     Index of status indicator: */


/*     Each record pointer contains a pointer to its companion:  for a */
/*     record belonging to a shadowed EK, this is the backup counterpart, */
/*     or if the parent EK is itself a backup EK, a pointer to the */
/*     record's source record.  The pointer is UNINIT (see below) if the */
/*     record is unmodified. */

/*     Record companion pointers contain record numbers, not record */
/*     base addresses. */

/*     Index of record's companion pointer: */


/*     Each data item is referenced by an integer.  The meaning of */
/*     this integer depends on the representation of data in the */
/*     column to which the data item belongs.  Actual lookup of a */
/*     data item must be done by subroutines appropriate to the class of */
/*     the column to which the item belongs.  Note that data items don't */
/*     necessarily occupy contiguous ranges of DAS addresses. */

/*     Base address of data pointers: */


/*     Maximum record pointer size: */


/*     Data pointers are given the value UNINIT to start with; this */
/*     indicates that the data item is uninitialized.  UNINIT is */
/*     distinct from the value NULL.  NOBACK indicates an uninitialized */
/*     backup column entry. */


/*     End Include Section:  EK Record Pointer Parameters */

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


/*     Include Section:  EK Data Types */

/*        ektype.inc Version 1  27-DEC-1994 (NJB) */


/*     Within the EK system, data types of EK column contents are */
/*     represented by integer codes.  The codes and their meanings */
/*     are listed below. */

/*     Integer codes are also used within the DAS system to indicate */
/*     data types; the EK system makes no assumptions about compatibility */
/*     between the codes used here and those used in the DAS system. */


/*     Character type: */


/*     Double precision type: */


/*     Integer type: */


/*     `Time' type: */

/*     Within the EK system, time values are represented as ephemeris */
/*     seconds past J2000 (TDB), and double precision numbers are used */
/*     to store these values.  However, since time values require special */
/*     treatment both on input and output, and since the `TIME' column */
/*     has a special role in the EK specification and code, time values */
/*     are identified as a type distinct from double precision numbers. */


/*     End Include Section:  EK Data Types */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   File handle. */
/*     SEGNO      I   Segment number. */
/*     RECNO      I   Record number. */

/* $ Detailed_Input */

/*     HANDLE         is a file handle of an EK open for write access. */

/*     SEGNO          is the number of the segment to which the record */
/*                    is to be added. */

/*     RECNO          is the index of the new record.  RECNO must be */
/*                    in the range 1 : (NREC+1), where NREC is the */
/*                    number of records in the segment prior to the */
/*                    insertion.  If RECNO is equal to NREC+1, the */
/*                    new record is appended.  Otherwise, the new */
/*                    record has the ordinal position specified by */
/*                    RECNO, and the records previously occupying */
/*                    positions RECNO : NREC have their indexes */
/*                    incremented by 1. */

/* $ Detailed_Output */

/*     None.  See the $Particulars section for a description of the */
/*     effect of this routine. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If HANDLE is invalid, the error will be diagnosed by routines */
/*         called by this routine.  The file will not be modified. */

/*     2)  If SEGNO is out of range, the error SPICE(INVALIDINDEX) */
/*         will be signalled.  The file will not be modified. */

/*     3)  If RECNO is out of range, the error SPICE(INVALIDINDEX) */
/*         will be signalled.  The file will not be modified. */

/*     4)  If an I/O error occurs while reading or writing the indicated */
/*         file, the error will be diagnosed by routines called by this */
/*         routine.  The file may be corrupted. */

/* $ Files */

/*     See the EK Required Reading for a discussion of the EK file */
/*     format. */

/* $ Particulars */

/*     This routine operates by side effects:  It adds a new, empty */
/*     record structure to an EK segment at a specified ordinal position. */

/*     After a record has been inserted into a segment by this routine, */
/*     the record must be populated with data using the EKACEx */
/*     routines.  EKs are valid only when all of their column entries */
/*     are initialized. */

/*     To append a record to a segment, use the routine EKAPPR. */

/*     This routine cannot be used with the "fast write" suite of */
/*     routines.  See the EK Required Reading for a discussion of the */
/*     fast writers. */

/*     When a record is inserted into an EK file that is not shadowed, */
/*     the status of the record starts out set to OLD.  The status */
/*     does not change when data is added to the record. */

/*     If the target EK is shadowed, the new record will be given the */
/*     status NEW.  Updating column values in the record does not change */
/*     its status.  When changes are committed, the status is set to OLD. */
/*     If a rollback is performed before changes are committed, the */
/*     record is deleted.  Closing the target file without committing */
/*     changes implies a rollback. */

/* $ Examples */

/*     1)  Insert a record into a specified E-kernel segment at a */
/*         specified ordinal position. */

/*         Suppose we have an E-kernel named ORDER_DB.EK which contains */
/*         records of orders for data products.  The E-kernel has a */
/*         table called DATAORDERS that consists of the set of columns */
/*         listed below: */

/*            DATAORDERS */

/*               Column Name     Data Type */
/*               -----------     --------- */
/*               ORDER_ID        INTEGER */
/*               CUSTOMER_ID     INTEGER */
/*               LAST_NAME       CHARACTER*(*) */
/*               FIRST_NAME      CHARACTER*(*) */
/*               ORDER_DATE      TIME */
/*               COST            DOUBLE PRECISION */

/*         The order database also has a table of items that have been */
/*         ordered.  The columns of this table are shown below: */

/*            DATAITEMS */

/*               Column Name     Data Type */
/*               -----------     --------- */
/*               ITEM_ID         INTEGER */
/*               ORDER_ID        INTEGER */
/*               ITEM_NAME       CHARACTER*(*) */
/*               DESCRIPTION     CHARACTER*(*) */
/*               PRICE           DOUBLE PRECISION */


/*         We'll suppose that the file ORDER_DB.EK contains two segments, */
/*         the first containing the DATAORDERS table and the second */
/*         containing the DATAITEMS table. */

/*         If we wanted to insert a new record into the DATAORDERS */
/*         table in position 1, we'd make the following calls: */

/*            C */
/*            C     Open the database for write access. */
/*            C */
/*                  CALL EKOPW ( 'ORDER_DB.EK', HANDLE ) */

/*            C */
/*            C     Insert a new, empty record into the DATAORDERS */
/*            C     table at record number 1.  This moves the existing */
/*            C     records down, so the old record 1 becomes record 2, */
/*            C     and so on.  Recall that the DATAORDERS table */
/*            C     is in segment number 1. */
/*            C */
/*                  RECNO = 1 */
/*                  SEGNO = 1 */

/*                  CALL EKINSR ( HANDLE, SEGNO, RECNO ) */

/*            C */
/*            C     At this point, the new record is empty.  A valid EK */
/*            C     cannot contain empty records.  We fill in the data */
/*            C     here.  Data items are filled in one column at a time. */
/*            C     The order in which the columns are filled in is not */
/*            C     important.  We use the EKACEx (add column entry) */
/*            C     routines to fill in column entries.  We'll assume */
/*            C     that no entries are null.  All entries are scalar, */
/*            C     so the entry size is 1. */
/*            C */
/*                  ISNULL   =  .FALSE. */
/*                  ESIZE    =  1 */

/*            C */
/*            C     The following variables will contain the data for */
/*            C     the new record. */
/*            C */
/*                  ORDID    =   10011 */
/*                  CUSTID   =   531 */
/*                  LNAME    =   'Scientist' */
/*                  FNAME    =   'Joe' */
/*                  ODATE    =   '1995-SEP-20' */
/*                  COST     =   0.D0 */

/*            C */
/*            C     Note that the names of the routines called */
/*            C     correspond to the data types of the columns:  the */
/*            C     last letter of the routine name is C, I, or D, */
/*            C     depending on the data type.  Time values are */
/*            C     converted to ET for storage. */
/*            C */
/*                  CALL EKACEI ( HANDLE, SEGNO,  RECNO, 'ORDER_ID', */
/*                 .              SIZE,   ORDID,  ISNULL               ) */

/*                  CALL EKACEI ( HANDLE, SEGNO,  RECNO, 'CUSTOMER_ID', */
/*                 .              SIZE,   CUSTID, ISNULL               ) */

/*                  CALL EKACEC ( HANDLE, SEGNO,  RECNO, 'LAST_NAME', */
/*                 .              SIZE,   LNAME,  ISNULL               ) */

/*                  CALL EKACEC ( HANDLE, SEGNO,  RECNO, 'FIRST_NAME', */
/*                 .              SIZE,   FNAME,  ISNULL               ) */


/*                  CALL UTC2ET ( ODATE,  ET ) */
/*                  CALL EKACED ( HANDLE, SEGNO,  RECNO, 'ORDER_DATE', */
/*                 .              SIZE,   ET,     ISNULL               ) */

/*                  CALL EKACED ( HANDLE, SEGNO,  RECNO, 'COST', */
/*                 .              SIZE,   COST,   ISNULL               ) */

/*            C */
/*            C     Close the file to make the update permanent. */
/*            C */
/*                  CALL EKCLS ( HANDLE ) */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.1, 09-JAN-2002 (NJB) */

/*        Documentation change:  instances of the phrase "fast load" */
/*        were replaced with "fast write." */

/* -    Beta Version 1.0.0, 19-DEC-1995 (NJB) */

/* -& */
/* $ Index_Entries */

/*     insert record into EK segment */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "EKINSR", (ftnlen)6);
    }

/*     Before trying to actually write anything, do every error */
/*     check we can. */

/*     Is this file handle valid--is the file open for paged write */
/*     access?  Signal an error if not. */

    zzekpgch_(__global_state, handle, "WRITE", (ftnlen)5);
    if (failed_(__global_state)) {
	chkout_(__global_state, "EKINSR", (ftnlen)6);
	return 0;
    }

/*     Look up the integer metadata page and page base for the segment. */
/*     Given the base address, we can read the pertinent metadata in */
/*     one shot. */

    zzekmloc_(__global_state, handle, segno, &mp, &mbase);
    if (failed_(__global_state)) {
	chkout_(__global_state, "EKINSR", (ftnlen)6);
	return 0;
    }
    i__1 = mbase + 1;
    i__2 = mbase + 24;
    dasrdi_(__global_state, handle, &i__1, &i__2, segdsc);

/*     We'll need to know how many columns the segment has in order to */
/*     compute the size of the record pointer.  The record pointer */
/*     contains DPTBAS items plus two elements for each column. */

    ncols = segdsc[4];
    size = ncols + 2;

/*     We're assuming the record pointer can fit on an integer page. */
/*     If this is not the case, we've got a bug. */

    if (size > 254) {
	setmsg_(__global_state, "Record pointer requires # integer words; EK"
		" software assumes size is <= #.  This is an EK software bug."
		"  Contact NAIF.", (ftnlen)118);
	errint_(__global_state, "#", &size, (ftnlen)1);
	errint_(__global_state, "#", &__state->c__254, (ftnlen)1);
	sigerr_(__global_state, "SPICE(BUG)", (ftnlen)10);
	chkout_(__global_state, "EKINSR", (ftnlen)6);
	return 0;
    }

/*     Check the number of records already present.  RECNO must not */
/*     exceed this count by more than 1. */

    nrec = segdsc[5];
    if (*recno < 1 || *recno > nrec + 1) {
	setmsg_(__global_state, "Record number = #; valid range is 1:#.", (
		ftnlen)38);
	errint_(__global_state, "#", recno, (ftnlen)1);
	i__1 = nrec + 1;
	errint_(__global_state, "#", &i__1, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDINDEX)", (ftnlen)19);
	chkout_(__global_state, "EKINSR", (ftnlen)6);
	return 0;
    }

/*     Find the last integer data page and the last word in use in that */
/*     page.  If there's enough room, we can store the record pointer */
/*     in the current page. */

    lastp = segdsc[17];
    lastw = segdsc[20];
    room = 254 - lastw;

/*     Initialize the record pointer:  set the record's status and */
/*     set the data pointers to indicate no data is present.  To */
/*     determine the status, we must know whether the parent file is */
/*     shadowed. */

    cleari_(__global_state, &__state->c__254, recptr);
    filli_(__global_state, &__state->c_n1, &__state->c__252, recptr);
    ekshdw_(__global_state, handle, &isshad);
    if (isshad) {
	recptr[0] = 3;
    } else {
	recptr[0] = 1;
    }

/*     Find a place to write the record pointer. */

    if (size <= room) {

/*        Just write the record pointer into the current integer page. */

	zzekpgbs_(__global_state, &__state->c__3, &lastp, &base);
	recbas = base + lastw;
	i__1 = recbas + 1;
	i__2 = recbas + size;
	dasudi_(__global_state, handle, &i__1, &i__2, recptr);

/*        Update the page's metadata to reflect the addition.  The */
/*        page gains a link. */

	i__1 = base + 256;
	i__2 = base + 256;
	dasrdi_(__global_state, handle, &i__1, &i__2, &nlinks);
	i__1 = base + 256;
	i__2 = base + 256;
	i__3 = nlinks + 1;
	dasudi_(__global_state, handle, &i__1, &i__2, &i__3);

/*        The last integer word in use has changed too. */

	segdsc[20] += size;
    } else {

/*        Allocate an integer page. */

	zzekaps_(__global_state, handle, segdsc, &__state->c__3, &
		__state->c_false, &p, &recbas);

/*        Write out the record pointer. */

	i__1 = recbas + 1;
	i__2 = recbas + size;
	dasudi_(__global_state, handle, &i__1, &i__2, recptr);

/*        Update the page's metadata to reflect the addition.  The */
/*        page starts out with one link. */

	i__1 = recbas + 256;
	i__2 = recbas + 256;
	dasudi_(__global_state, handle, &i__1, &i__2, &__state->c__1);

/*        Update the segment's metadata to reflect the addition of a */
/*        data page.  The last page in use is the one we just wrote to. */
/*        The last word in use is the last word of the record pointer. */

	segdsc[17] = p;
	segdsc[20] = size;
    }

/*     Update the segment's metadata to reflect the addition of the */
/*     new record.  The base address of the record is inserted into */
/*     the data record tree at index RECNO.  The record count gets */
/*     incremented. */

    zzektrin_(__global_state, handle, &segdsc[6], recno, &recbas);
    ++segdsc[5];

/*     If the segment is shadowed but no backup segment exists yet, we */
/*     need to create one.  We'll let ZZEKRBCK take care of the details. */
/*     Note that for data additions, the input argument COLDSC is */
/*     ignored. */

    zzekrbck_(__global_state, "ADD", handle, segdsc, coldsc, recno, (ftnlen)3)
	    ;

/*     Write out the updated segment descriptor. */

    i__1 = mbase + 1;
    i__2 = mbase + 24;
    dasudi_(__global_state, handle, &i__1, &i__2, segdsc);
    chkout_(__global_state, "EKINSR", (ftnlen)6);
    return 0;
} /* ekinsr_ */

