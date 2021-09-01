/* zzekad06.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzekad06_init_t __zzekad06_init;
static zzekad06_state_t* get_zzekad06_state(cspice_t* state) {
	if (!state->zzekad06)
		state->zzekad06 = __cspice_allocate_module(sizeof(
	zzekad06_state_t), &__zzekad06_init, sizeof(__zzekad06_init));
	return state->zzekad06;

}

/* $Procedure     ZZEKAD06 ( EK, add data to class 6 column ) */
/* Subroutine */ int zzekad06_(cspice_t* __global_state, integer *handle, 
	integer *segdsc, integer *coldsc, integer *recptr, integer *nvals, 
	char *cvals, logical *isnull, ftnlen cvals_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer i_len(f2c_state_t*, char *, ftnlen);

    /* Local variables */
    extern integer zzekrp2n_(cspice_t*, integer *, integer *, integer *);
    extern /* Subroutine */ int zzekpgbs_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int zzekglnk_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    extern /* Subroutine */ int zzeksfwd_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    extern /* Subroutine */ int zzekslnk_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern logical failed_(cspice_t*);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int dasudi_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    extern /* Subroutine */ int dasudc_(cspice_t*, integer *, integer *, 
	    integer *, integer *, integer *, char *, ftnlen);
    extern /* Subroutine */ int zzeksei_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int zzekaps_(cspice_t*, integer *, integer *, 
	    integer *, logical *, integer *, integer *);


    /* Module state */
    zzekad06_state_t* __state = get_zzekad06_state(__global_state);
/* $ Abstract */

/*     Add a column entry to a specified record in a class 6 column. */
/*     The entries of class 6 columns are arrays of character string */
/*     values. */

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
/*     PRIVATE */

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


/*     Include Section:  EK Boolean Enumerated Type */


/*        ekbool.inc Version 1   21-DEC-1994 (NJB) */


/*     Within the EK system, boolean values sometimes must be */
/*     represented by integer or character codes.  The codes and their */
/*     meanings are listed below. */

/*     Integer code indicating `true': */


/*     Integer code indicating `false': */


/*     Character code indicating `true': */


/*     Character code indicating `false': */


/*     End Include Section:  EK Boolean Enumerated Type */

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
/*     HANDLE     I   EK file handle. */
/*     SEGNO      I   Index of segment containing record. */
/*     RECNO      I   Record to which data is to be added. */
/*     COLUMN     I   Column name. */
/*     NVALS      I   Number of values to add to column. */
/*     CVALS      I   Character values to add to column. */
/*     ISNULL     I   Flag indicating whether column entry is null. */

/* $ Detailed_Input */

/*     HANDLE         is the handle of an EK file that is open for write */
/*                    access. */

/*     SEGNO          is the index of the segment to which data is to */
/*                    be added. */

/*     RECNO          is the index of the record to which data is to be */
/*                    added.  This record number is relative to the start */
/*                    of the segment indicated by SEGNO; the first */
/*                    record in the segment has index 1. */

/*     COLUMN         is the name of the column to which data is to be */
/*                    added. */

/*     NVALS, */
/*     CVALS          are, respectively, the number of values to add to */
/*                    the specified column and the set of values */
/*                    themselves.  The data values are written into the */
/*                    specified column and record. */

/*                    If the  column has fixed-size entries, then NVALS */
/*                    must equal the entry size for the specified column. */

/*                    Only one value can be added to a virtual column. */


/*     ISNULL         is a logical flag indicating whether the entry is */
/*                    null.  If ISNULL is .FALSE., the column entry */
/*                    defined by NVALS and CVALS is added to the */
/*                    specified kernel file. */

/*                    If ISNULL is .TRUE., NVALS and CVALS are ignored. */
/*                    The contents of the column entry are undefined. */
/*                    If the column has fixed-length, variable-size */
/*                    entries, the number of entries is considered to */
/*                    be 1. */

/* $ Detailed_Output */

/*     None.  See the $Particulars section for a description of the */
/*     effect of this routine. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If HANDLE is invalid, the error will be diagnosed by routines */
/*         called by this routine.  The file is not modified. */

/*     2)  If the ordinal position of the column specified by COLDSC */
/*         is out of range, the error SPICE(INVALIDINDEX) is signalled. */
/*         The file is not modified. */

/*     3)  If the input flag ISNULL is .TRUE. but the target column */
/*         does not allow nulls, the error SPICE(BADATTRIBUTE) is */
/*         signalled.  The file is not modified. */

/*     4)  If RECPTR is invalid, a DAS addressing error may occur.  The */
/*         error in *not* trapped in advance.  This routine assumes that */
/*         a valid value of RECPTR has been supplied by the caller. */

/*     3)  If an I/O error occurs while reading or writing the indicated */
/*         file, the error will be diagnosed by routines called by this */
/*         routine.  The file may be corrupted. */

/* $ Files */

/*     See the EK Required Reading for a discussion of the EK file */
/*     format. */

/* $ Particulars */

/*     This routine operates by side effects:  it sets the value of a */
/*     column entry in an EK segment.  If the column is indexed, the */
/*     index is updated to reflect the presence of the new entry.  This */
/*     routine is intended to set values of uninitialized column entries */
/*     only.  To update existing entries, use the ZZEKUExx routines, or */
/*     at the user level, the EKUCEx routines. */

/*     This routine does not participate in shadowing functions.  If the */
/*     target EK is shadowed, the caller is responsible for performing */
/*     necessary backup operations.  If the target EK is not shadowed, */
/*     the target record's status is not modified. */

/*     The changes made by this routine to the target EK file become */
/*     permanent when the file is closed.  Failure to close the file */
/*     properly will leave it in an indeterminate state. */

/* $ Examples */

/*     See EKACEC. */

/* $ Restrictions */

/*     1) This routine cannot be used to update existing column entries. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    Beta Version 1.0.0, 23-OCT-1995 (NJB) */

/* -& */

/*     SPICELIB functions */


/*     Non-SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     Saved variables */


/*     Initial values */


/*     Use discovery check-in. */

    if (__state->first) {
	s_copy(&__global_state->f2c, __state->padbuf, " ", (ftnlen)100, (
		ftnlen)1);
	__state->first = FALSE_;
    }

/*     Make sure the record exists. */

    __state->nrec = segdsc[5];
    __state->colidx = coldsc[8];

/*     Make sure the column exists. */

    __state->ncols = segdsc[4];
    if (__state->colidx < 1 || __state->colidx > __state->ncols) {
	chkin_(__global_state, "ZZEKAD06", (ftnlen)8);
	setmsg_(__global_state, "Column index = #; valid range is 1:#.", (
		ftnlen)37);
	errint_(__global_state, "#", &__state->colidx, (ftnlen)1);
	errint_(__global_state, "#", &__state->nrec, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDINDEX)", (ftnlen)19);
	chkout_(__global_state, "ZZEKAD06", (ftnlen)8);
	return 0;
    }

/*     If the value is null, make sure that nulls are permitted */
/*     in this column. */

    if (*isnull && coldsc[7] != 1) {
	__state->recno = zzekrp2n_(__global_state, handle, &segdsc[1], recptr)
		;
	chkin_(__global_state, "ZZEKAD06", (ftnlen)8);
	setmsg_(__global_state, "Column having index # in segment # does not"
		" allow nulls, but a null value was supplied for the element "
		"in record #.", (ftnlen)115);
	errint_(__global_state, "#", &__state->colidx, (ftnlen)1);
	errint_(__global_state, "#", &segdsc[1], (ftnlen)1);
	errint_(__global_state, "#", &__state->recno, (ftnlen)1);
	sigerr_(__global_state, "SPICE(BADATTRIBUTE)", (ftnlen)19);
	chkout_(__global_state, "ZZEKAD06", (ftnlen)8);
	return 0;
    }

/*     Check NVALS.  If the column has fixed-size entries, NVALS must */
/*     match the declared entry size.  In all cases, NVALS must be */
/*     positive. */

    if (*nvals < 1) {
	chkin_(__global_state, "ZZEKAD06", (ftnlen)8);
	setmsg_(__global_state, "COLIDX = #;  segment = #; NVALS = #;  NVALS"
		" must be positive ", (ftnlen)61);
	errint_(__global_state, "#", &__state->colidx, (ftnlen)1);
	errint_(__global_state, "#", &segdsc[1], (ftnlen)1);
	errint_(__global_state, "#", nvals, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDCOUNT)", (ftnlen)19);
	chkout_(__global_state, "ZZEKAD06", (ftnlen)8);
	return 0;
    }
    if (coldsc[3] != -1) {
	if (*nvals != coldsc[3]) {
	    chkin_(__global_state, "ZZEKAD06", (ftnlen)8);
	    setmsg_(__global_state, "COLIDX = #;  segment = #; NVALS = #; de"
		    "clared entry size = #.  Sizes must match.", (ftnlen)80);
	    errint_(__global_state, "#", &__state->colidx, (ftnlen)1);
	    errint_(__global_state, "#", &segdsc[1], (ftnlen)1);
	    errint_(__global_state, "#", nvals, (ftnlen)1);
	    errint_(__global_state, "#", &coldsc[3], (ftnlen)1);
	    sigerr_(__global_state, "SPICE(INVALIDCOUNT)", (ftnlen)19);
	    chkout_(__global_state, "ZZEKAD06", (ftnlen)8);
	    return 0;
	}
    }

/*     Compute the data pointer location. */

    __state->ptrloc = *recptr + 2 + __state->colidx;
    if (*isnull) {

/*        All we need do is set the data pointer.  The segment's */
/*        metadata are not affected. */

	dasudi_(__global_state, handle, &__state->ptrloc, &__state->ptrloc, &
		__state->c_n2);
    } else {

/*        Decide now whether we will need to pad the input entry */
/*        elements with trailing blanks, and if so how much padding */
/*        we'll need. */

	__state->strlen = coldsc[2];
	__state->cvlen = i_len(&__global_state->f2c, cvals, cvals_len);
	__state->pad = __state->cvlen < __state->strlen;
	if (__state->pad) {
	    __state->padlen = __state->strlen - __state->cvlen;
	}
	__state->lastw = segdsc[18];
	__state->room = 1014 - __state->lastw;
	__state->fstpag = TRUE_;

/*        Initialize the page base and target data pointer, if possible. */
/*        If the current page is full, these functions will be performed */
/*        below in the code section in which a new page is allocated. */

	if (__state->lastw < 1014) {
	    __state->p = segdsc[15];
	    zzekpgbs_(__global_state, &__state->c__1, &__state->p, &
		    __state->pbase);
	    __state->datptr = __state->pbase + __state->lastw + 1;
	}
	__state->eltidx = 1;
	while(__state->eltidx <= *nvals && ! failed_(__global_state)) {

/*           Write out the element having index ELTIDX. */

	    __state->pos = 0;
	    __state->remain = __state->strlen;
	    while(__state->remain > 0) {

/*              Decide where to write the data values.  In order to write */
/*              a new entry, we require enough room for the count */
/*              and at least one character of data. */

		if (__state->fstpag) {
		    __state->mnroom = 6;
		} else {
		    __state->mnroom = 1;
		}
		if (__state->room >= __state->mnroom) {

/*                 There's room in the current page.  If this is the */
/*                 first page this entry is written on, set the data */
/*                 pointer and count.  Write as much of the value as */
/*                 possible to the current page. */

		    if (__state->fstpag) {
			dasudi_(__global_state, handle, &__state->ptrloc, &
				__state->ptrloc, &__state->datptr);
			zzeksei_(__global_state, handle, &__state->datptr, 
				nvals);
			__state->room += -5;
			__state->datptr += 5;

/*                    The first page containing some or all of the data */
/*                    item gains a link. */

			zzekglnk_(__global_state, handle, &__state->c__1, &
				__state->p, &__state->nlinks);
			i__1 = __state->nlinks + 1;
			zzekslnk_(__global_state, handle, &__state->c__1, &
				__state->p, &i__1);
		    }

/*                 Write the characters we can fit onto the current page. */

		    __state->nwrite = min(__state->remain,__state->room);
		    __state->n = __state->nwrite;
		    while(__state->n > 0) {
			if (__state->pos < __state->cvlen) {

/*                       Take data from the input string CVALS(ELTIDX). */

/* Computing MIN */
			    i__1 = __state->n, i__2 = __state->cvlen - 
				    __state->pos;
			    __state->nchrs = min(i__1,i__2);
			    i__1 = __state->datptr + __state->nchrs - 1;
			    i__2 = __state->pos + 1;
			    i__3 = __state->pos + __state->nchrs;
			    dasudc_(__global_state, handle, &__state->datptr, 
				    &i__1, &i__2, &i__3, cvals + (
				    __state->eltidx - 1) * cvals_len, 
				    cvals_len);
			    __state->n -= __state->nchrs;
			    __state->pos += __state->nchrs;
			    __state->datptr += __state->nchrs;
			} else if (__state->pad) {

/*                       We must add trailing blanks to the column */
/*                       entry at this point. */

			    __state->npad = min(__state->n,__state->padlen);
			    __state->np = __state->npad;
			    while(__state->np > 0) {
				__state->wp = min(__state->np,100);
				i__1 = __state->datptr + __state->wp - 1;
				dasudc_(__global_state, handle, &
					__state->datptr, &i__1, &
					__state->c__1, &__state->wp, 
					__state->padbuf, (ftnlen)100);
				__state->np -= __state->wp;
				__state->datptr += __state->wp;
			    }
			    __state->n -= __state->npad;
			    __state->pos += __state->npad;
			}
		    }

/*                 We've written all we can to the current page. */

		    __state->remain -= __state->nwrite;
		    __state->room -= __state->nwrite;

/*                 The last character word in use must be updated. */
/*                 Account for the count, if this is the first page on */
/*                 which the current entry is written. */

		    if (__state->fstpag) {
			__state->lastw = __state->lastw + 5 + __state->nwrite;
			segdsc[18] = __state->lastw;
			__state->fstpag = FALSE_;
		    } else {
			__state->lastw += __state->nwrite;
			segdsc[18] = __state->lastw;
		    }
		} else {

/*                 Allocate a character data page.  If this is not the */
/*                 first data page written to, link the previous page to */
/*                 the current one. */

		    zzekaps_(__global_state, handle, segdsc, &__state->c__1, &
			    __state->c_false, &__state->p2, &__state->pbase);
		    if (! __state->fstpag) {
			zzeksfwd_(__global_state, handle, &__state->c__1, &
				__state->p, &__state->p2);
		    }
		    __state->p = __state->p2;
		    __state->lastw = 0;
		    segdsc[15] = __state->p;
		    segdsc[18] = __state->lastw;
		    __state->room = 1014;
		    __state->datptr = __state->pbase + 1;

/*                 Set the link count.  If this is the first page */
/*                 onto which the input column entry is written, */
/*                 just zero out the count; the count will be set above. */
/*                 Additional pages get one link. */

		    if (__state->fstpag) {
			__state->nlinks = 0;
		    } else {
			__state->nlinks = 1;
		    }
		    zzekslnk_(__global_state, handle, &__state->c__1, &
			    __state->p, &__state->nlinks);
		}
	    }

/*           We've written out the current element. */

	    ++__state->eltidx;
	}
    }

/*     Write out the updated segment descriptor. */

    __state->mbase = segdsc[2];
    i__1 = __state->mbase + 1;
    i__2 = __state->mbase + 24;
    dasudi_(__global_state, handle, &i__1, &i__2, segdsc);

/*     Class 6 columns are not indexed, so we need not update any */
/*     index to account for the new element. */

    return 0;
} /* zzekad06_ */

