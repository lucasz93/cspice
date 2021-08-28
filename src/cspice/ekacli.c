/* ekacli.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int ekacli_state_t;
static inline ekacli_state_t* get_ekacli_state(cspice_t* state) {
	return 0;
}

/* $Procedure     EKACLI ( EK, add integer column to segment ) */
/* Subroutine */ int ekacli_(cspice_t* __global_state, integer *handle, 
	integer *segno, char *column, integer *ivals, integer *entszs, 
	logical *nlflgs, integer *rcptrs, integer *wkindx, ftnlen column_len)
{
    extern /* Subroutine */ int zzekcdsc_(cspice_t*, integer *, integer *, 
	    char *, integer *, ftnlen);
    extern /* Subroutine */ int zzeksdsc_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    integer class__;
    integer dtype;
    extern logical failed_(cspice_t*);
    integer coldsc[11];
    integer segdsc[24];
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int zzekac01_(cspice_t*, integer *, integer *, 
	    integer *, integer *, logical *, integer *, integer *);
    extern /* Subroutine */ int zzekac04_(cspice_t*, integer *, integer *, 
	    integer *, integer *, integer *, logical *);
    extern /* Subroutine */ int zzekac07_(cspice_t*, integer *, integer *, 
	    integer *, integer *, logical *, integer *);


    /* Module state */
    ekacli_state_t* __state = get_ekacli_state(__global_state);
/* $ Abstract */

/*     Add an entire integer column to an EK segment. */

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
/*     SEGNO      I   Number of segment to add column to. */
/*     COLUMN     I   Column name. */
/*     IVALS      I   Integer values to add to column. */
/*     ENTSZS     I   Array of sizes of column entries. */
/*     NLFLGS     I   Array of null flags for column entries. */
/*     RCPTRS     I   Record pointers for segment. */
/*     WKINDX    I-O  Work space for column index. */

/* $ Detailed_Input */

/*     HANDLE         the handle of an EK file that is open for writing. */
/*                    A "begin segment for fast write" operation must */
/*                    have already been performed for the designated */
/*                    segment. */

/*     SEGNO          is the number of the segment to which */
/*                    data is to be added. */

/*     COLUMN         is the name of the column to be added.  All of */
/*                    the data for the named column will be added in */
/*                    one shot. */

/*     IVALS          is an array containing the entire set of column */
/*                    entries for the specified column.  The entries */
/*                    are listed in row-order:  the column entry for the */
/*                    first row of the segment is first, followed by the */
/*                    column entry for the second row, and so on.  The */
/*                    number of column entries must match the declared */
/*                    number of rows in the segment.  For columns having */
/*                    fixed-size entries, a null entry must be allocated */
/*                    the same amount of space occupied by a non-null */
/*                    entry in the array IVALS.  For columns having */
/*                    variable-size entries, null entries do not require */
/*                    any space in the IVALS array, but in any case must */
/*                    have their allocated space described correctly by */
/*                    the corresponding element of the ENTSZS array */
/*                    (described below). */

/*     ENTSZS         is an array containing sizes of column entries. */
/*                    The Ith element of ENTSZS gives the size of the */
/*                    Ith column entry.  ENTSZS is used only for columns */
/*                    having variable-size entries.  For such columns, */
/*                    the dimension of ENTSZS must be at least NROWS. */
/*                    The size of null entries should be set to zero. */

/*                    For columns having fixed-size entries, the */
/*                    dimension of this array may be any positive value. */

/*     NLFLGS         is an array of logical flags indicating whether */
/*                    the corresponding entries are null.  If the Ith */
/*                    element of NLFLGS is .FALSE., the Ith column entry */
/*                    defined by IVALS and ENTSZS is added to the */
/*                    current segment in the specified kernel file. */

/*                    If the Ith element of NLFGLS is .TRUE., the */
/*                    contents of the Ith column entry are undefined. */

/*                    NLFLGS is used only for columns that allow null */
/*                    values; it's ignored for other columns. */

/*     RCPTRS         is an array of record pointers for the input */
/*                    segment.  This array is obtained as an output */
/*                    from EKIFLD, the routine called to initiate a */
/*                    fast write. */

/*     WKINDX         is a work space array used for building a column */
/*                    index.  If the column is indexed, the dimension of */
/*                    WKINDX must be at NROWS, where NROWS is the number */
/*                    of rows in the column.  If the column is not */
/*                    indexed, this work space is not used, so the */
/*                    dimension may be any positive value. */

/* $ Detailed_Output */

/*     None.  See $Particulars for a description of the effect of this */
/*     routine. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If HANDLE is invalid, the error will be diagnosed by routines */
/*         called by this routine. */

/*     2)  If COLUMN is not the name of a declared column, the error will */
/*         be diagnosed by routines called by this routine. */

/*     3)  If COLUMN specifies a column of whose data type is not */
/*         integer, the error SPICE(WRONGDATATYPE) will be signalled. */

/*     4)  If the specified column already contains ANY entries, the */
/*         error will be diagnosed by routines called by this routine. */

/*     5)  If an I/O error occurs while reading or writing the indicated */
/*         file, the error will be diagnosed by routines called by this */
/*         routine. */

/* $ Files */

/*     See the EK Required Reading for a discussion of the EK file */
/*     format. */

/* $ Particulars */

/*     This routine operates by side effects:  it modifies the named */
/*     EK file by adding data to the specified column.  This routine */
/*     writes the entire contents of the specified column in one shot. */
/*     This routine creates columns much more efficiently than can be */
/*     done by sequential calls to EKACEI, but has the drawback that */
/*     the caller must use more memory for the routine's inputs.  This */
/*     routine cannot be used to add data to a partially completed */
/*     column. */

/* $ Examples */

/*     1)  Suppose we have an E-kernel named ORDER_DB.EK which contains */
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

/*         Below, we show how we'd open a new EK file and create the */
/*         first of the segments described above. */


/*            C */
/*            C     Open a new EK file.  For simplicity, we will not */
/*            C     reserve any space for the comment area, so the */
/*            C     number of reserved comment characters is zero. */
/*            C     The variable IFNAME is the internal file name. */
/*            C */
/*                  NRESVC  =  0 */
/*                  IFNAME  =  'Test EK/Created 20-SEP-1995' */

/*                  CALL EKOPN ( 'ORDER_DB.EK', IFNAME, NRESVC, HANDLE ) */

/*            C */
/*            C     Set up the table and column names and declarations */
/*            C     for the DATAORDERS segment.  We'll index all of */
/*            C     the columns.  All columns are scalar, so we omit */
/*            C     the size declaration.  Only the COST column may take */
/*            C     null values. */
/*            C */
/*                  TABLE     =  'DATAORDERS' */
/*                  NCOLS     =  6 */

/*                  CNAMES(1) =  'ORDER_ID' */
/*                  CDECLS(1) =  'DATATYPE = INTEGER, INDEXED = TRUE' */

/*                  CNAMES(2) =  'CUSTOMER_ID' */
/*                  CDECLS(2) =  'DATATYPE = INTEGER, INDEXED = TRUE' */

/*                  CNAMES(3) =  'LAST_NAME' */
/*                  CDECLS(3) =  'DATATYPE = CHARACTER*(*),' // */
/*                 .             'INDEXED  = TRUE' */

/*                  CNAMES(4) =  'FIRST_NAME' */
/*                  CDECLS(4) =  'DATATYPE = CHARACTER*(*),' // */
/*                 .             'INDEXED  = TRUE' */

/*                  CNAMES(5) =  'ORDER_DATE' */
/*                  CDECLS(5) =  'DATATYPE = TIME, INDEXED  = TRUE' */

/*                  CNAMES(6) =  'COST' */
/*                  CDECLS(6) =  'DATATYPE = DOUBLE PRECISION,' // */
/*                 .             'INDEXED  = TRUE'           // */
/*                 .             'NULLS_OK = TRUE' */

/*            C */
/*            C     Start the segment.  We presume the number of  rows */
/*            C     of data is known in advance. */
/*            C */
/*                  CALL EKIFLD ( HANDLE,  TABNAM,  NCOLS,  NROWS, */
/*                 .              CNAMES,  CDECLS,  SEGNO,  RCPTRS ) */

/*            C */
/*            C     At this point, arrays containing data for the */
/*            C     segment's columns may be filled in.  The names */
/*            C     of the data arrays are shown below. */
/*            C */
/*            C        Column           Data array */
/*            C */
/*            C        'ORDER_ID'       ORDIDS */
/*            C        'CUSTOMER_ID'    CSTIDS */
/*            C        'LAST_NAME'      LNAMES */
/*            C        'FIRST_NAME'     FNAMES */
/*            C        'ORDER_DATE'     ONAMES */
/*            C        'COST'           COSTS */
/*            C */

/*                     [ Fill in data arrays here.] */

/*            C */
/*            C     The SIZES array shown below is ignored for scalar */
/*            C     and fixed-size array columns, so we need not */
/*            C     initialize it.  For variable-size arrays, the */
/*            C     Ith element of the SIZES array must contain the size */
/*            C     of the Ith column entry in the column being loaded. */
/*            C     Normally, the SIZES array would be reset for each */
/*            C     variable-size column. */
/*            C */
/*            C     The NLFLGS array indicates which entries are null. */
/*            C     It is ignored for columns that don't allow null */
/*            C     values.  In this case, only the COST column allows */
/*            C     nulls. */
/*            C */
/*            C     Add the columns of data to the segment.  All of the */
/*            C     data for each column is loaded in one shot. */
/*            C */
/*                  CALL EKACLI ( HANDLE, SEGNO,  'ORDER_ID', */
/*                 .              ORDIDS, SIZES,  NLFLGS,  WKINDX ) */

/*                  CALL EKACLI ( HANDLE, SEGNO,  'CUSTOMER_ID', */
/*                 .              CSTIDS, SIZES,  NLFLGS,  WKINDX ) */

/*                  CALL EKACLC ( HANDLE, SEGNO,  'LAST_NAME', */
/*                 .              LNAMES, SIZES,  NLFLGS,  WKINDX ) */

/*                  CALL EKACLC ( HANDLE, SEGNO,  'FIRST_NAME', */
/*                 .              FNAMES, SIZES,  NLFLGS,  WKINDX ) */


/*                  CALL UTC2ET ( ODATE,  ET ) */
/*                  CALL EKACLD ( HANDLE, SEGNO,  'ORDER_DATE', */
/*                 .              ODATES, SIZES,  NLFLGS,  WKINDX ) */


/*                     [Set the NLFLGS array here.] */

/*                  CALL EKACLD ( HANDLE, SEGNO,  'COST', */
/*                 .              COSTS,  SIZES,  NLFLGS,  WKINDX ) */

/*            C */
/*            C     Complete the segment.  The RCPTRS array is that */
/*            C     returned by EKIFLD. */
/*            C */
/*                  CALL EKFFLD ( HANDLE, SEGNO, RCPTRS ) */

/*            C */
/*            C     At this point, the second segment could be */
/*            C     created by an analogous process.  In fact, the */
/*            C     second segment could be created at any time; it is */
/*            C     not necessary to populate the first segment with */
/*            C     data before starting the second segment. */
/*            C */

/*            C */
/*            C     The file must be closed by a call to EKCLS. */
/*            C */
/*                  CALL EKCLS ( HANDLE ) */


/* $ Restrictions */

/*     1)  Only one segment can be created at a time using the fast */
/*         write routines. */

/*     2)  No other EK operation may interrupt a fast write.  For */
/*         example, it is not valid to issue a query while a fast write */
/*         is in progress. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.1, 09-JAN-2002 (NJB) */

/*        Documentation change:  instances of the phrase "fast load" */
/*        were replaced with "fast write." */

/* -    Beta Version 1.0.0, 08-NOV-1995 (NJB) */

/* -& */
/* $ Index_Entries */

/*     write entire integer column to EK segment */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "EKACLI", (ftnlen)6);
    }

/*     Find the descriptors for the specified segment and column. */

    zzeksdsc_(__global_state, handle, segno, segdsc);
    zzekcdsc_(__global_state, handle, segdsc, column, coldsc, column_len);
    if (failed_(__global_state)) {
	chkout_(__global_state, "EKACLI", (ftnlen)6);
	return 0;
    }

/*     This column had better be of integer type. */

    class__ = coldsc[0];
    dtype = coldsc[1];
    if (dtype != 3) {
	setmsg_(__global_state, "Column # is of type #; EKACLI only works wi"
		"th integer columns.", (ftnlen)62);
	errch_(__global_state, "#", column, (ftnlen)1, column_len);
	errint_(__global_state, "#", &dtype, (ftnlen)1);
	sigerr_(__global_state, "SPICE(WRONGDATATYPE)", (ftnlen)20);
	chkout_(__global_state, "EKACLI", (ftnlen)6);
	return 0;
    }

/*     Hand off the task to the routine of the appropriate class. */

    if (class__ == 1) {

/*        Class 1 columns contain integer scalars. */

	zzekac01_(__global_state, handle, segdsc, coldsc, ivals, nlflgs, 
		rcptrs, wkindx);
    } else if (class__ == 4) {

/*        Class 4 columns contain integer arrays. */

	zzekac04_(__global_state, handle, segdsc, coldsc, ivals, entszs, 
		nlflgs);
    } else if (class__ == 7) {

/*        Class 7 columns contain fixed-count integer scalars. */

	zzekac07_(__global_state, handle, segdsc, coldsc, ivals, nlflgs, 
		wkindx);
    } else {

/*        This is an unsupported column class. */

	setmsg_(__global_state, "Unsupported column class code # found in de"
		"scriptor for column #.", (ftnlen)65);
	errint_(__global_state, "#", &class__, (ftnlen)1);
	errch_(__global_state, "#", column, (ftnlen)1, column_len);
	sigerr_(__global_state, "SPICE(NOTSUPPORTED)", (ftnlen)19);
	chkout_(__global_state, "EKACLI", (ftnlen)6);
	return 0;
    }
    chkout_(__global_state, "EKACLI", (ftnlen)6);
    return 0;
} /* ekacli_ */

