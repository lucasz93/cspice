/* zzekerc1.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzekerc1_init_t __zzekerc1_init;
static inline zzekerc1_state_t* get_zzekerc1_state(cspice_t* state) {
	if (!state->zzekerc1)
		state->zzekerc1 = __cspice_allocate_module(sizeof(
	zzekerc1_state_t), &__zzekerc1_init, sizeof(__zzekerc1_init));
	return state->zzekerc1;

}

/* $Procedure ZZEKERC1 ( EK, LLE using record pointers, char, type 1 ) */
/* Subroutine */ int zzekerc1_(cspice_t* __global_state, integer *handle, 
	integer *segdsc, integer *coldsc, char *ckey, integer *recptr, 
	logical *null, integer *prvidx, integer *prvptr, ftnlen ckey_len)
{
    integer nrec;
    integer tree;
    extern logical zzekscmp_(cspice_t*, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, char *, doublereal *, 
	    integer *, logical *, ftnlen);
    extern /* Subroutine */ int zzektrdp_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    integer begin;
    extern integer zzektrsz_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer tsize;
    extern logical failed_(cspice_t*);
    integer middle;
    integer begptr;
    integer endptr;
    integer midptr;
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    integer end;
    logical leq;


    /* Module state */
    zzekerc1_state_t* __state = get_zzekerc1_state(__global_state);
/* $ Abstract */

/*     Find the last column value less than or equal to a specified key, */
/*     for a specifed character EK column having a type 1 index, using */
/*     dictionary ordering on character data values and record pointers. */

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


/*     Include Section:  EK Operator Codes */

/*        ekopcd.inc  Version 1  30-DEC-1994 (NJB) */


/*     Within the EK system, operators used in EK queries are */
/*     represented by integer codes.  The codes and their meanings are */
/*     listed below. */

/*     Relational expressions in EK queries have the form */

/*        <column name> <operator> <value> */

/*     For columns containing numeric values, the operators */

/*        EQ,  GE,  GT,  LE,  LT,  NE */

/*     may be used; these operators have the same meanings as their */
/*     Fortran counterparts.  For columns containing character values, */
/*     the list of allowed operators includes those in the above list, */
/*     and in addition includes the operators */

/*        LIKE,  UNLIKE */

/*     which are used to compare strings to a template.  In the character */
/*     case, the meanings of the parameters */

/*        GE,  GT,  LE,  LT */

/*     match those of the Fortran lexical functions */

/*        LGE, LGT, LLE, LLT */


/*     The additional unary operators */

/*        ISNULL, NOTNUL */

/*     are used to test whether a value of any type is null. */



/*     End Include Section:  EK Operator Codes */

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
/*     SEGDSC     I   Segment descriptor. */
/*     COLDSC     I   Column descriptor. */
/*     CKEY       I   Character key. */
/*     RECPTR     I   Record pointer. */
/*     NULL       I   Null flag. */
/*     PRVIDX     O   Ordinal position of predecessor of CKEY. */
/*     PRVPTR     O   Record pointer for predecessor of CKEY. */

/* $ Detailed_Input */

/*     HANDLE         is a file handle of an EK open for read or write */
/*                    access. */

/*     SEGDSC         is the segment descriptor of the segment */
/*                    containing the column specified by COLDSC. */

/*     COLDSC         is the column descriptor of the column to be */
/*                    searched. */

/*     CKEY, */
/*     RECPTR         are, respectively, a character key and a pointer */
/*                    to an EK record containing that key.  The last */
/*                    column entry less than or equal to this key is */
/*                    sought.  The order relation used is dictionary */
/*                    ordering on the pair (CKEY, RECPTR). */

/*     NULL           is a logical flag indicating whether the input */
/*                    key is null.  When NULL is .TRUE., CKEY is */
/*                    ignored by this routine. */

/* $ Detailed_Output */

/*     PRVIDX         is the ordinal position, according to the order */
/*                    relation implied by the column's index, of the */
/*                    record containing the last element less than or */
/*                    equal to CKEY, where the order relation is */
/*                    as indicated above.  If the column contains */
/*                    elements equal to CKEY, PRVIDX is the index of the */
/*                    record designated by the input RECPTR. */

/*                    If all elements of the column are greater than */
/*                    CKEY, PRVIDX is set to zero. */

/*     PRVPTR         is a pointer to the record containing the element */
/*                    whose ordinal position is PRVIDX. */

/*                    If all elements of the column are greater than */
/*                    CKEY, PRVPTR is set to zero. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If HANDLE is invalid, the error will be diagnosed by routines */
/*         called by this routine. */

/*     2)  If an I/O error occurs while reading or writing the indicated */
/*         file, the error will be diagnosed by routines called by this */
/*         routine. */

/*     3)  If the tree is empty, PRVIDX and PRVPTR are set to zero. */
/*         This case is not considered an error. */

/* $ Files */

/*     See the EK Required Reading for a discussion of the EK file */
/*     format. */

/* $ Particulars */

/*     This routine finds the last column element less than or equal */
/*     to a specified character key, within a specified segment and */
/*     column.  The column must be indexed by a type 1 index.  The order */
/*     relation used is dictionary ordering on ordered pairs consisting */
/*     of data values and record pointers:  if the data values in two */
/*     column entries are equal, the associated record pointers determine */
/*     the order relation of the column entries. */

/*     Type 1 indexes are implemented as DAS B*-trees.  The data */
/*     pointers of an index tree contain record pointers.  Therefore, the */
/*     tree implements an abstract order vector. */

/*     In order to support the capability of creating an index for a */
/*     column that has already been populated with data, this routine */
/*     does not require that number of elements referenced by the */
/*     input column's index match the number of elements in the column; */
/*     the index is allowed to reference fewer elements.  However, */
/*     every record referenced by the index must be populated with data. */

/* $ Examples */

/*     See ZZEKLERC. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    Beta Version 1.1.0, 18-MAY-1997 (NJB) */

/*        Errors in comparisons of items of equal value were fixed. */
/*        In such cases, items are compared according to order of */
/*        their record pointers. */

/* -    Beta Version 1.0.0, 11-OCT-1995 (NJB) */

/* -& */

/*     SPICELIB functions */


/*     Non-SPICELIB functions */


/*     Local variables */


/*     Use discovery check-in. */

    if (failed_(__global_state)) {
	return 0;
    }

/*     Make sure the number of records in the segment is at least as */
/*     large as the number of entries in the index:  we must not look */
/*     up any entries that don't exist! */

    tree = coldsc[6];
    tsize = zzektrsz_(__global_state, handle, &tree);
    nrec = segdsc[5];
    if (tsize > nrec) {
	chkin_(__global_state, "ZZEKERC1", (ftnlen)8);
	setmsg_(__global_state, "Index size = # but column contains # record"
		"s.", (ftnlen)45);
	errint_(__global_state, "#", &tsize, (ftnlen)1);
	errint_(__global_state, "#", &nrec, (ftnlen)1);
	sigerr_(__global_state, "SPICE(SIZEMISMATCH)", (ftnlen)19);
	chkout_(__global_state, "ZZEKERC1", (ftnlen)8);
	return 0;
    }

/*     Handle the case of an empty tree gracefully. */

    if (tsize == 0) {
	*prvidx = 0;
	*prvptr = 0;
	return 0;
    }

/*     The algorithm used here is very like unto that used in LSTLED. */

    begin = 1;
    end = tsize;

/*     Get the record pointers BEGPTR and ENDPTR of the least and */
/*     greatest elements in the column. */

    zzektrdp_(__global_state, handle, &tree, &begin, &begptr);
    zzektrdp_(__global_state, handle, &tree, &end, &endptr);

/*     Compare the input value to the smallest value in the column. */

    if (zzekscmp_(__global_state, &__state->c__3, handle, segdsc, coldsc, &
	    begptr, &__state->c__1, &__state->c__1, ckey, &__state->c_b11, &
	    __state->c__0, null, ckey_len)) {

/*        The smallest entry of the column is greater than */
/*        the input value, so none of the entries */
/*        are less than or equal to the input value. */

	*prvidx = 0;
	*prvptr = 0;
	return 0;
    } else if (zzekscmp_(__global_state, &__state->c__1, handle, segdsc, 
	    coldsc, &begptr, &__state->c__1, &__state->c__1, ckey, &
	    __state->c_b11, &__state->c__0, null, ckey_len) && *recptr < 
	    begptr) {

/*        The smallest entry of the column is greater than the input */
/*        value, based on a comparison of record pointers, so none of the */
/*        entries are less than or equal to the input value. */

	*prvidx = 0;
	*prvptr = 0;
	return 0;
    }

/*     At this point, we know the input value is greater than or equal */
/*     to the smallest element of the column. */

/*     Compare the input value to the greatest value in the column. */

    if (zzekscmp_(__global_state, &__state->c__5, handle, segdsc, coldsc, &
	    endptr, &__state->c__1, &__state->c__1, ckey, &__state->c_b11, &
	    __state->c__0, null, ckey_len)) {

/*        The last element of the column is less than the */
/*        input value. */

	*prvidx = tsize;
	zzektrdp_(__global_state, handle, &tree, prvidx, prvptr);
	return 0;
    } else if (zzekscmp_(__global_state, &__state->c__1, handle, segdsc, 
	    coldsc, &endptr, &__state->c__1, &__state->c__1, ckey, &
	    __state->c_b11, &__state->c__0, null, ckey_len) && endptr <= *
	    recptr) {

/*        The last element of the column is less than or equal to the */
/*        input value, based on a comparison of record pointers. */

	*prvidx = tsize;
	*prvptr = endptr;
	return 0;
    }

/*     The input value lies between some pair of column entries. */
/*     The value is greater than or equal to the smallest column entry */
/*     and less than the greatest entry, according to the dictionary */
/*     ordering we're using. */

/*     Below, we'll use the variable LEQ to indicate whether the "middle" */
/*     element in our search is less than or equal to the input value. */

    while(end > begin + 1) {

/*        Find the record pointer of the element whose ordinal position */
/*        is halfway between BEGIN and END. */

	middle = (begin + end) / 2;
	zzektrdp_(__global_state, handle, &tree, &middle, &midptr);

/*        Determine the order relation between CKEY and the column */
/*        entry at record MIDPTR. */

	if (zzekscmp_(__global_state, &__state->c__5, handle, segdsc, coldsc, 
		&midptr, &__state->c__1, &__state->c__1, ckey, &
		__state->c_b11, &__state->c__0, null, ckey_len)) {

/*           The column element at record MIDPTR is less than */
/*           or equal to CKEY, based on data values. */

	    leq = TRUE_;
	} else if (zzekscmp_(__global_state, &__state->c__1, handle, segdsc, 
		coldsc, &midptr, &__state->c__1, &__state->c__1, ckey, &
		__state->c_b11, &__state->c__0, null, ckey_len)) {

/*           The column entry's value matches CKEY.  We must */
/*           compare record pointers at this point. */

	    leq = midptr <= *recptr;
	} else {

/*           The inequality of data values is strict. */

	    leq = FALSE_;
	}
	if (leq) {

/*           The middle value is less than or equal to the input */
/*           value. */

	    begin = middle;
	} else {
	    end = middle;
	}

/*        The input value is greater than or equal to the element */
/*        having ordinal position BEGIN and strictly less than the */
/*        element having ordinal position END. */

    }
    *prvidx = begin;
    zzektrdp_(__global_state, handle, &tree, prvidx, prvptr);
    return 0;
} /* zzekerc1_ */

