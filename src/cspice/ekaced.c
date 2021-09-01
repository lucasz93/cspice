/* ekaced.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int ekaced_state_t;
static ekaced_state_t* get_ekaced_state(cspice_t* state) {
	return 0;
}

/* $Procedure     EKACED ( EK, add d.p. data to column ) */
/* Subroutine */ int ekaced_(cspice_t* __global_state, integer *handle, 
	integer *segno, integer *recno, char *column, integer *nvals, 
	doublereal *dvals, logical *isnull, ftnlen column_len)
{
    extern /* Subroutine */ int zzekcdsc_(cspice_t*, integer *, integer *, 
	    char *, integer *, ftnlen);
    extern /* Subroutine */ int zzeksdsc_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int zzektrdp_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    integer class__;
    integer dtype;
    extern logical failed_(cspice_t*);
    integer coldsc[11];
    integer segdsc[24];
    extern /* Subroutine */ int errhan_(cspice_t*, char *, integer *, ftnlen);
    integer recptr;
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int zzekad02_(cspice_t*, integer *, integer *, 
	    integer *, integer *, doublereal *, logical *);
    extern /* Subroutine */ int zzekad05_(cspice_t*, integer *, integer *, 
	    integer *, integer *, integer *, doublereal *, logical *);


    /* Module state */
    ekaced_state_t* __state = get_ekaced_state(__global_state);
/* $ Abstract */

/*     Add data to an double precision column in a specified EK record. */

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
/*     FILES */
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
/*     DVALS      I   Double precision values to add to column. */
/*     ISNULL     I   Flag indicating whether column entry is null. */

/* $ Detailed_Input */

/*     HANDLE         is the handle of an EK file open for write access. */

/*     SEGNO          is the index of the segment to which data is to */
/*                    be added. */

/*     RECNO          is the index of the record to which data is to be */
/*                    added.  This record number is relative to the start */
/*                    of the segment indicated by SEGNO; the first */
/*                    record in the segment has index 1. */

/*     COLUMN         is the name of the column to which data is to be */
/*                    added. */

/*     NVALS, */
/*     DVALS          are, respectively, the number of values to add to */
/*                    the specified column and the set of values */
/*                    themselves.  The data values are written into the */
/*                    specified column and record. */

/*                    If the  column has fixed-size entries, then NVALS */
/*                    must equal the entry size for the specified column. */

/*                    Only one value can be added to a virtual column. */


/*     ISNULL         is a logical flag indicating whether the entry is */
/*                    null.  If ISNULL is .FALSE., the column entry */
/*                    defined by NVALS and DVALS is added to the */
/*                    specified kernel file. */

/*                    If ISNULL is .TRUE., NVALS and DVALS are ignored. */
/*                    The contents of the column entry are undefined. */
/*                    If the column has fixed-length, variable-size */
/*                    entries, the number of entries is considered to */
/*                    be 1. */

/* $ Detailed_Output */

/*     None.  See $Particulars for a description of the effect of this */
/*     routine. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If HANDLE is invalid, the error will be diagnosed by routines */
/*         called by this routine. */

/*     2)  If SEGNO is out of range, the error will be diagnosed by */
/*         routines called by this routine. */

/*     3)  If COLUMN is not the name of a declared column, the error */
/*         will be diagnosed by routines called by this routine. */

/*     4)  If COLUMN specifies a column of whose data type is not */
/*         double precision, the error SPICE(WRONGDATATYPE) will be */
/*         signaled. */

/*     5)  If RECNO is out of range, the error will be diagnosed by */
/*         routines called by this routine. */

/*     6)  If the specified column has fixed-size entries and NVALS */
/*         does not match this size, the error will be diagnosed by */
/*         routines called by this routine. */

/*     7)  If the specified column has variable-size entries and NVALS */
/*         is non-positive, the error will be diagnosed by routines */
/*         called by this routine. */

/*     8)  If an attempt is made to add a null value to a column that */
/*         doesn't take null values, the error will be diagnosed by */
/*         routines called by this routine. */

/*     9)  If COLUMN specifies a column of whose class is not */
/*         an character class known to this routine, the error */
/*         SPICE(NOCLASS) will be signaled. */

/*     10) If an I/O error occurs while reading or writing the indicated */
/*         file, the error will be diagnosed by routines called by this */
/*         routine. */

/* $ Files */

/*     See the EK Required Reading for a discussion of the EK file */
/*     format. */

/* $ Particulars */

/*     This routine operates by side effects:  it modifies the named */
/*     EK file by adding data to the specified record in the specified */
/*     column.  Data may be added to a segment in random order; it is not */
/*     necessary to fill in columns or rows sequentially.  Data may only */
/*     be added one column entry at a time. */

/* $ Examples */

/*     1)  Add the value 999.D0 to the third record of the column DCOL in */
/*         the fifth segment of an EK file designated by HANDLE. */

/*            CALL EKACED ( HANDLE, 5, 3, 'DCOL', 1, 999.D0, .FALSE. ) */


/*     2)  Same as (1), but this time add a null value.  The argument */
/*         999.D0 is ignored because the null flag is set to .TRUE. */

/*            CALL EKACED ( HANDLE, 5, 3, 'DCOL', 1, 999.D0, .TRUE. ) */


/*     3)  Add an array DBUFF of 10 values to the third record of the */
/*         column DARRAY in the fifth segment of an EK file designated by */
/*         HANDLE. */

/*            CALL EKACED ( HANDLE, 5, 3, 'DARRAY', 10, DBUFF, .FALSE. ) */

/*     4)  A more detailed example. */

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
/*            C     Open the database for write access.  This call is */
/*            C     made when the file already exists.  See EKOPN for */
/*            C     an example of creating a new file. */
/*            C */
/*                  CALL EKOPW ( 'ORDER_DB.EK', HANDLE ) */

/*            C */
/*            C     Append a new, empty record to the DATAORDERS */
/*            C     table. Recall that the DATAORDERS table */
/*            C     is in segment number 1.  The call will return */
/*            C     the number of the new, empty record. */
/*            C */
/*                  CALL EKAPPR ( HANDLE, 1, RECNO ) */

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

/* -    SPICELIB Version 1.2.0, 05-FEB-2015 (NJB) */

/*        Updated to use ERRHAN. */

/* -    SPICELIB Version 1.1.0, 18-JUN-1999 (WLT) */

/*        Removed an unbalanced call to CHKOUT */

/* -    Beta Version 1.0.0, 26-SEP-1995 (NJB) */

/* -& */
/* $ Index_Entries */

/*     add double precision data to EK column */
/*     add data to EK */
/*     write double precision data to EK column */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Use discovery check-in. */

/*     First step:  find the descriptor for the named segment.  Using */
/*     this descriptor, get the column descriptor. */

    zzeksdsc_(__global_state, handle, segno, segdsc);
    zzekcdsc_(__global_state, handle, segdsc, column, coldsc, column_len);
    if (failed_(__global_state)) {
	return 0;
    }

/*     This column had better be of double precision or `time' type. */

    dtype = coldsc[1];
    if (dtype != 2 && dtype != 4) {
	chkin_(__global_state, "EKACED", (ftnlen)6);
	setmsg_(__global_state, "Column # is of type #; EKACED only works wi"
		"th d.p. or time columns.  RECNO = #; SEGNO = #; EK = #.", (
		ftnlen)98);
	errch_(__global_state, "#", column, (ftnlen)1, column_len);
	errint_(__global_state, "#", &dtype, (ftnlen)1);
	errint_(__global_state, "#", recno, (ftnlen)1);
	errint_(__global_state, "#", segno, (ftnlen)1);
	errhan_(__global_state, "#", handle, (ftnlen)1);
	sigerr_(__global_state, "SPICE(WRONGDATATYPE)", (ftnlen)20);
	chkout_(__global_state, "EKACED", (ftnlen)6);
	return 0;
    }

/*     Look up the record pointer for the target record. */

    zzektrdp_(__global_state, handle, &segdsc[6], recno, &recptr);

/*     Now it's time to add data to the file. */

    class__ = coldsc[0];
    if (class__ == 2) {

/*        Class 2 columns contain scalar d.p. data. */

	zzekad02_(__global_state, handle, segdsc, coldsc, &recptr, dvals, 
		isnull);
    } else if (class__ == 5) {

/*        Class 5 columns contain array-valued d.p. data. */

	zzekad05_(__global_state, handle, segdsc, coldsc, &recptr, nvals, 
		dvals, isnull);
    } else {

/*        This is an unsupported d.p. column class. */

	*segno = segdsc[1];
	chkin_(__global_state, "EKACED", (ftnlen)6);
	setmsg_(__global_state, "Class # from input column descriptor is not"
		" a supported d.p. class.  COLUMN = #; RECNO = #; SEGNO = #; "
		"EK = #.", (ftnlen)110);
	errint_(__global_state, "#", &class__, (ftnlen)1);
	errch_(__global_state, "#", column, (ftnlen)1, column_len);
	errint_(__global_state, "#", recno, (ftnlen)1);
	errint_(__global_state, "#", segno, (ftnlen)1);
	errhan_(__global_state, "#", handle, (ftnlen)1);
	sigerr_(__global_state, "SPICE(NOCLASS)", (ftnlen)14);
	chkout_(__global_state, "EKACED", (ftnlen)6);
	return 0;
    }
    return 0;
} /* ekaced_ */

