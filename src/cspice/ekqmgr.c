/* ekqmgr.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern ekqmgr_init_t __ekqmgr_init;
static ekqmgr_state_t* get_ekqmgr_state(cspice_t* state) {
	if (!state->ekqmgr)
		state->ekqmgr = __cspice_allocate_module(sizeof(
	ekqmgr_state_t), &__ekqmgr_init, sizeof(__ekqmgr_init));
	return state->ekqmgr;

}

/* $Procedure EKQMGR  ( EK, query manager ) */
/* Subroutine */ int ekqmgr_0_(cspice_t* __global_state, int n__, integer *
	cindex, integer *elment, char *eqryc, doublereal *eqryd, integer *
	eqryi, char *fname, integer *row, integer *selidx, char *column, 
	integer *handle, integer *n, char *table, integer *attdsc, integer *
	ccount, logical *found, integer *nelt, integer *nmrows, logical *
	semerr, char *errmsg, char *cdata, doublereal *ddata, integer *idata, 
	logical *null, ftnlen eqryc_len, ftnlen fname_len, ftnlen column_len, 
	ftnlen table_len, ftnlen errmsg_len, ftnlen cdata_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6, i__7, i__8, i__9, i__10, 
	    i__11, i__12, i__13, i__14;

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int lnkini_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int dascls_(cspice_t*, integer *);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errhan_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int lnkilb_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int zzekpgch_(cspice_t*, integer *, char *, 
	    ftnlen);
    extern /* Subroutine */ int ssizec_(cspice_t*, integer *, char *, ftnlen);
    extern /* Subroutine */ int validc_(cspice_t*, integer *, integer *, char 
	    *, ftnlen);
    extern /* Subroutine */ int lnkfsl_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical zzekrmch_(cspice_t*, integer *, logical *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    char *, integer *, integer *, doublereal *, integer *, ftnlen);
    extern /* Subroutine */ int zzekqtab_(cspice_t*, integer *, char *, 
	    integer *, char *, char *, ftnlen, ftnlen, ftnlen);
    extern logical zzekvmch_(cspice_t*, integer *, logical *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
    extern /* Subroutine */ int ssizei_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int zzeksinf_(cspice_t*, integer *, integer *, 
	    char *, integer *, char *, integer *, ftnlen, ftnlen);
    extern /* Subroutine */ int zzekreqi_(cspice_t*, integer *, char *, 
	    integer *, ftnlen);
    extern /* Subroutine */ int appndc_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int appndi_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int zzeksdec_(cspice_t*, integer *);
    extern /* Subroutine */ int cleari_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int zzekqcnj_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int zzekqcon_(cspice_t*, integer *, char *, 
	    doublereal *, integer *, integer *, char *, integer *, char *, 
	    integer *, integer *, char *, integer *, char *, integer *, 
	    integer *, integer *, integer *, doublereal *, integer *, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int zzekkey_(cspice_t*, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    char *, integer *, integer *, doublereal *, integer *, logical *, 
	    integer *, integer *, integer *, integer *, logical *, ftnlen);
    extern /* Subroutine */ int zzekixlk_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    extern /* Subroutine */ int zzekrplk_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    extern integer zzekesiz_(cspice_t*, integer *, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int zzeksupd_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int zzekjoin_(cspice_t*, integer *, integer *, 
	    integer *, logical *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
    extern /* Subroutine */ int zzekspsh_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int zzeksrd_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int zzekweed_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int zzekqsel_(cspice_t*, integer *, char *, 
	    integer *, integer *, integer *, char *, integer *, char *, 
	    integer *, ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int zzekvset_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int zzekqord_(cspice_t*, integer *, char *, 
	    integer *, char *, integer *, char *, integer *, integer *, 
	    ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int zzekjsrt_(cspice_t*, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *);
    extern /* Subroutine */ int zzekstop_(cspice_t*, integer *);
    extern integer cardc_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int ekcls_(cspice_t*, integer *);
    extern integer lnktl_(cspice_t*, integer *, integer *);
    extern logical eqstr_(cspice_t*, char *, char *, ftnlen, ftnlen);
    extern /* Subroutine */ int ekopr_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int lnkan_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int movec_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    extern /* Subroutine */ int movei_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int zzekjsqz_(cspice_t*, integer *);
    extern /* Subroutine */ int zzekvcal_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int zzekrsc_(cspice_t*, integer *, integer *, 
	    integer *, integer *, integer *, integer *, char *, logical *, 
	    logical *, ftnlen);
    extern /* Subroutine */ int zzekrsd_(cspice_t*, integer *, integer *, 
	    integer *, integer *, integer *, doublereal *, logical *, logical 
	    *);
    extern /* Subroutine */ int zzekrsi_(cspice_t*, integer *, integer *, 
	    integer *, integer *, integer *, integer *, logical *, logical *);
    extern logical failed_(cspice_t*);
    extern integer isrchc_(cspice_t*, char *, integer *, char *, ftnlen, 
	    ftnlen);
    extern logical return_(cspice_t*);
    extern integer eknseg_(cspice_t*, integer *);
    extern integer lnknxt_(cspice_t*, integer *, integer *);
    extern integer lnknfn_(cspice_t*, integer *);

    /* Module state */
    ekqmgr_state_t* __state = get_ekqmgr_state(__global_state);
/* $ Abstract */

/*     Manage query operations on EK files. */

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
/*     SEARCH */

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


/*     Include Section:  EK Column Attribute Descriptor Parameters */

/*        ekattdsc.inc Version 1    23-AUG-1995 (NJB) */


/*     This include file declares parameters used in EK column */
/*     attribute descriptors.  Column attribute descriptors are */
/*     a simplified version of column descriptors:  attribute */
/*     descriptors describe attributes of a column but do not contain */
/*     addresses or pointers. */


/*     Size of column attribute descriptor */


/*     Indices of various pieces of attribute descriptors: */


/*     ATTSIZ is the index of the column's class code.  (We use the */
/*     word `class' to distinguish this item from the column's data */
/*     type.) */


/*     ATTTYP is the index of the column's data type code (CHR, INT, DP, */
/*     or TIME).  The type is actually implied by the class, but it */
/*     will frequently be convenient to look up the type directly. */



/*     ATTLEN is the index of the column's string length value, if the */
/*     column has character type.  A value of IFALSE in this element of */
/*     the descriptor indicates that the strings have variable length. */


/*     ATTSIZ is the index of the column's element size value.  This */
/*     descriptor element is meaningful for columns with fixed-size */
/*     entries.  For variable-sized columns, this value is IFALSE. */


/*     ATTIDX is the location of a flag that indicates whether the column */
/*     is indexed.  The flag takes the value ITRUE if the column is */
/*     indexed and otherwise takes the value IFALSE. */


/*     ATTNFL is the index of a flag indicating whether nulls are */
/*     permitted in the column.  The value at location NFLIDX is */
/*     ITRUE if nulls are permitted and IFALSE otherwise. */


/*     End Include Section:  EK Column Attribute Descriptor Parameters */

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


/*     Include Section:  EK Join Row Set Parameters */

/*        ekjrs.inc  Version 1    07-FEB-1995 (NJB) */


/*     Maximum number of join row sets in a join row set union: */


/*     The layout of a join row set in the EK scratch area is shown */
/*     below: */

/*        +--------------------------------------------+ */
/*        |              join row set size             |  1 element */
/*        +--------------------------------------------+ */
/*        |    number of row vectors in join row set   |  1 element */
/*        +--------------------------------------------+ */
/*        |               table count (TC)             |  1 element */
/*        +--------------------------------------------+ */
/*        |          segment vector count (SVC)        |  1 element */
/*        +--------------------------------------------+ */
/*        |               segment vector 1             |  TC elements */
/*        +--------------------------------------------+ */
/*                              . */
/*                              . */
/*                              . */
/*        +--------------------------------------------+ */
/*        |               segment vector SVC           |  TC elements */
/*        +--------------------------------------------+ */
/*        |   segment vector 1 row set base address    |  1 element */
/*        +--------------------------------------------+ */
/*        |      segment vector 1 row count (RC_1)     |  1 element */
/*        +--------------------------------------------+ */
/*                              . */
/*                              . */
/*                              . */
/*        +--------------------------------------------+ */
/*        |  segment vector SVC row set base address   |  1 element */
/*        +--------------------------------------------+ */
/*        |   segment vector SVC row count (RC_SVC)    |  1 element */
/*        +--------------------------------------------+ */
/*        | Augmented row vectors for segment vector 1 |  (TC+1)*RC_1 */
/*        +--------------------------------------------+  elements */
/*                              . */
/*                              . */
/*                              . */
/*        +--------------------------------------------+ */
/*        |Augmented row vectors for segment vector SVC|  (TC+1)*RC_SVC1 */
/*        +--------------------------------------------+  elements */


/*     The following parameters indicate positions of elements in the */
/*     join row set structure: */


/*     Base-relative index of join row set size */


/*     Index of row vector count */


/*     Index of table count */


/*     Index of segment vector count */


/*     Base address of first segment vector */



/*     End Include Section:  EK Join Row Set Parameters */

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


/*     Include Section:  EK Query Limit Parameters */

/*        ekqlimit.inc  Version 3    16-NOV-1995 (NJB) */

/*           Parameter MAXCON increased to 1000. */

/*        ekqlimit.inc  Version 2    01-AUG-1995 (NJB) */

/*           Updated to support SELECT clause. */


/*        ekqlimit.inc  Version 1    07-FEB-1995 (NJB) */


/*     These limits apply to character string queries input to the */
/*     EK scanner.  This limits are part of the EK system's user */
/*     interface:  the values should be advertised in the EK required */
/*     reading document. */


/*     Maximum length of an input query:  MAXQRY.  This value is */
/*     currently set to twenty-five 80-character lines. */


/*     Maximum number of columns that may be listed in the */
/*     `order-by clause' of a query:  MAXSEL.  MAXSEL = 50. */


/*     Maximum number of tables that may be listed in the `FROM */
/*     clause' of a query: MAXTAB. */


/*     Maximum number of relational expressions that may be listed */
/*     in the `constraint clause' of a query: MAXCON. */

/*     This limit applies to a query when it is represented in */
/*     `normalized form': that is, the constraints have been */
/*     expressed as a disjunction of conjunctions of relational */
/*     expressions. The number of relational expressions in a query */
/*     that has been expanded in this fashion may be greater than */
/*     the number of relations in the query as orginally written. */
/*     For example, the expression */

/*             ( ( A LT 1 ) OR ( B GT 2 ) ) */
/*        AND */
/*             ( ( C NE 3 ) OR ( D EQ 4 ) ) */

/*     which contains 4 relational expressions, expands to the */
/*     equivalent normalized constraint */

/*             (  ( A LT 1 ) AND ( C NE 3 )  ) */
/*        OR */
/*             (  ( A LT 1 ) AND ( D EQ 4 )  ) */
/*        OR */
/*             (  ( B GT 2 ) AND ( C NE 3 )  ) */
/*        OR */
/*             (  ( B GT 2 ) AND ( D EQ 4 )  ) */

/*     which contains eight relational expressions. */



/*     MXJOIN is the maximum number of tables that can be joined. */


/*     MXJCON is the maximum number of join constraints allowed. */


/*     Maximum number of order-by columns that may be used in the */
/*     `order-by clause' of a query: MAXORD. MAXORD = 10. */


/*     Maximum number of tokens in a query: 500. Tokens are reserved */
/*     words, column names, parentheses, and values. Literal strings */
/*     and time values count as single tokens. */


/*     Maximum number of numeric tokens in a query: */


/*     Maximum total length of character tokens in a query: */


/*     Maximum length of literal string values allowed in queries: */
/*     MAXSTR. */


/*     End Include Section:  EK Query Limit Parameters */

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


/*     Include Section:  EK Encoded Query Internal Parameters */

/*        ekquery.inc  Version 3    16-NOV-1995 (NJB) */

/*           Updated to reflect increased value of MAXCON in */
/*           ekqlimit.inc. */

/*        ekquery.inc  Version 2    03-AUG-1995 (NJB) */

/*           Updated to support representation of the SELECT clause. */


/*        ekquery.inc  Version 1    12-JAN-1995 (NJB) */


/*     An encoded EK query is an abstract data type implemented */
/*     as an integer cell, along with a double precision cell and */
/*     a character string.  The d.p. cell and string contain numeric */
/*     and string values from the query string represented by the */
/*     encoded query. */

/*     The parameters in this file are intended for use only by the */
/*     EK encoded query access routines.  Callers of EK routines should */
/*     not use these parameters. */

/*     The following parameters are indices of specified elements */
/*     in the integer portion of the encoded query. */

/*     Encoded query architecture type: */


/*     `Name resolution' consists of: */

/*        - Verifying existence of tables:  any table names listed */
/*          in the FROM clause of a query must be loaded. */

/*        - Validating table aliases used to qualify column names. */

/*        - Verifying existence of columns and obtaining data types */
/*          for columns. */

/*        - Setting data type codes for literal values in the encoded */
/*          query. */

/*        - Checking consistency of operators and operand data types. */

/*        - Making sure unqualified column names are unambiguous. */

/*        - For constraints, mapping the table names used to qualify */
/*          column names to the ordinal position in the FROM clause */
/*          of the corresponding table. */


/*     Initialization status---this flag indicates whether the encoded */
/*     query has been initialized.  Values are ITRUE or IFALSE.  See the */
/*     include file ekbool.inc for parameter values. */


/*     Parse status---this flag indicates whether the parsing operation */
/*     that produced an encoded query has been completed. Values are */
/*     ITRUE or IFALSE. */


/*     Name resolution status---this flag indicates whether names */
/*     have been resolved in an encoded query.  Values are ITRUE or */
/*     IFALSE. */


/*     Time resolution status---this flag indicates whether time values */
/*     have been resolved in an encoded query.  Time resolution */
/*     consists of converting strings representing time values to ET. */
/*     Values of the status are ITRUE or IFALSE. */


/*     Semantic check status---this flag indicates whether semantic */
/*     checking of constraints has been performed. */


/*     Number of tables specified in FROM clause: */


/*     Number of constraints in query: */


/*     A special value is used to indicate the `maximal' constraint--- */
/*     one that logically cannot be satisfied.  If the constraints */
/*     are equivalent to the maximal constraint, the location EQNCNS */
/*     is assigned the value EQMXML */


/*     Number of constraint conjunctions: */


/*     Number of order-by columns: */


/*     Number of SELECT columns: */


/*     Size of double precision buffer: */


/*     `Free' pointer into double precision buffer: */


/*     Size of character string buffer: */


/*     `Free' pointer into character string buffer: */


/*     The following four base pointers will be valid after a query */
/*     has been parsed: */

/*     Base pointer for SELECT column descriptors: */


/*     Base pointer for constraint descriptors: */


/*     Base pointer for conjunction sizes: */


/*     Base pointer for order-by column descriptors: */


/*     After the quantities named above, the integer array contains */
/*     series of descriptors for tables, constraints, and order-by */
/*     columns, as well as a list of `conjunction sizes'---that is, */
/*     the sizes of the groups of constraints that form conjunctions, */
/*     after the input query has been re-arranged as a disjunction of */
/*     conjunctions of constraints. */


/*     The offsets of specific elements within descriptors are */
/*     parameterized. The base addresses of the descriptors themselves */
/*     must be  calculated using the counts and sizes of the items */
/*     preceding them. */

/*     A diagram of the structure of the variable-size portion of the */
/*     integer array is shown below: */


/*        +-------------------------------------+ */
/*        | Fixed-size portion of encoded query | */
/*        +-------------------------------------+ */
/*        |         Encoded FROM clause         | */
/*        +-------------------------------------+ */
/*        |      Encoded constraint clause      | */
/*        +-------------------------------------+ */
/*        |          Conjunction sizes          | */
/*        +-------------------------------------+ */
/*        |       Encoded ORDER BY clause       | */
/*        +-------------------------------------+ */
/*        |        Encoded SELECT clause        | */
/*        +-------------------------------------+ */


/*     Value Descriptors */
/*     ---------------- */

/*     In order to discuss the various descriptors below, we'll make use */
/*     of sub-structures called `value descriptors'.  These descriptors */
/*     come in two flavors:  character and double precision.  For */
/*     strings, a descriptor is a set of begin and end pointers that */
/*     indicate the location of the string in the character portion of an */
/*     encoded query, along with the begin and end pointers for the */
/*     corresponding lexeme in the original query.  The pointers are set */
/*     to zero when they are not in use, for example if they refer to an */
/*     optional lexeme that did not appear in the input query. */

/*     All value descriptors start with a data type indicator; values */
/*     are from ektype.inc.  Integer and time values are referred to */
/*     by double precision descriptors. */

/*     Parameters for string value descriptor elements: */


/*     Numeric value descriptors are similar to those for string values, */
/*     the difference being that they have only one pointer to the value */
/*     they represent.  This pointer is the index of the value in the */
/*     encoded query's numeric buffer. */


/*     All value descriptors have the same size.  In order to allow */
/*     table descriptors to have the same size as value descriptors, */
/*     we include an extra element in the descriptor. */


/*     Column Descriptors */
/*     ----------------- */

/*     Each column descriptor consists of a character descriptor for the */
/*     name of the column, followed by an index, which gives the ordinal */
/*     position of the column in the logical table to which the column */
/*     belongs.  The index element is filled in during name resolution. */


/*     Table Descriptors */
/*     ----------------- */

/*     Each table descriptor consists of a character descriptor for the */
/*     name of the table, followed by an index, which gives the ordinal */
/*     position of the table in the FROM clause in the original query. */
/*     The index element is filled in during name resolution.  Aliases */
/*     and table names have identical descriptor structures. */


/*     Constraint descriptors */
/*     ------------------ */

/*     Each constraint is characterized by: */

/*        - A code indicating whether the constraint compares values */
/*          in two columns or the value in a column and a literal */
/*          value.  The values of this element are EQCOL and EQVAL. */



/*        - A descriptor for the table used to qualify the */
/*          column name on the left side of the constraint. */


/*        - A character value descriptor for the column name on the left */
/*          side of the query. */


/*        - An operator code indicating the relational operator used */
/*          in the constraint. */


/*        If the constraint compares values from two columns, the */
/*        next items are table and column name descriptors that apply to */
/*        the column named on the right side of the relational operator. */


/*        If the constraint has a literal value on the right side, the */
/*        operator code is followed by... */

/*        - a value descriptor. */


/*        - Size of a constraint descriptor: */


/*     Conjunction sizes */
/*     ----------------- */

/*     The size of each conjunction of constraints occupies a single */
/*     integer. */




/*     Order-by Column Descriptors */
/*     --------------------------- */

/*     Each order-by column descriptor contains descriptors for */
/*     the table containing the column and for the name of the column */
/*     itself; one additional element is used to indicate the direction */
/*     of the ordering (ascending vs descending). */


/*        - The last integer in the descriptor indicates whether the */
/*          order direction is ascending or descending. */


/*        - Size of an order-by column descriptor: */


/*     Codes indicating sense of ordering (ascending vs descending): */


/*     SELECT Column Descriptors */
/*     --------------------------- */

/*     Each SELECT column descriptor contains descriptors for */
/*     the table containing the column and for the name of the column */
/*     itself. */


/*        - Size of a SELECT column descriptor: */


/*     Miscellaneous parameters: */


/*     EQIMIN is the minimum size of the integer portion of */
/*     an encoded query.  EQIMIN depends on the parameters */

/*        MAXTAB */
/*        MAXCON */
/*        MAXORD */
/*        MAXSEL */

/*     all of which are declared in the include file ekqlimit.inc. */
/*     The functional definition of EQIMIN is: */

/*     INTEGER               EQIMIN */
/*     PARAMETER           ( EQIMIN =   EQVBAS */
/*    .                              +  MAXTAB * EQVDSZ * 2 */
/*    .                              +  MAXCON * EQCDSZ */
/*    .                              +  MAXCON */
/*    .                              +  MAXORD * EQODSZ */
/*    .                              +  MAXSEL * EQSDSZ     ) */


/*     End Include Section:  EK Encoded Query Internal Parameters */

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

/*     Variable  I/O  Entry points */
/*     --------  ---  -------------------------------------------------- */
/*     CINDEX     I   EKCII */
/*     ELMENT     I   EKGC, EKGD, EKGI */
/*     EQRYC      I   EKSRCH */
/*     EQRYD      I   EKSRCH */
/*     EQRYI      I   EKSRCH */
/*     FNAME      I   EKLEF */
/*     ROW        I   EKGC, EKGD, EKGI, EKNELT */
/*     SELIDX     I   EKGC, EKGD, EKGI, EKNELT */
/*     COLUMN    I-O  EKCIN, EKGC, EKGD, EKGI, EKNELT, EKCII */
/*     HANDLE    I-O  EKLEF, EKUEF */
/*     N         I-O  EKTNAM, EKNTAB */
/*     TABLE     I-O  EKCCNT, EKCII, EKTNAM */
/*     ATTDSC     O   EKCII, EKCIN */
/*     CCOUNT     O   EKCCNT */
/*     FOUND      O   EKCIN, EKGC, EKGD, EKGI */
/*     NELT       O   EKNELT */
/*     NMROWS     O   EKSRCH */
/*     SEMERR     O   EKSRCH */
/*     ERRMSG     O   EKSRCH */
/*     CDATA      O   EKGC */
/*     DDATA      O   EKGD */
/*     IDATA      O   EKGI */
/*     NULL       O   EKGC, EKGD, EKGI */
/*     FTSIZE     P   All */
/*     MAXCON     P   All */
/*     MXCLLD     P   All */
/*     STSIZE     P   All */
/*     MAXORD     P   All */
/*     CNAMSZ     P   All */
/*     ITSIZE     P   All */

/* $ Detailed_Input */

/*     See the entry points for descriptions of their inputs. */

/* $ Detailed_Output */

/*     See the entry points for descriptions of their outputs. */

/* $ Parameters */

/*     FTSIZE         is the maximum number of EK files that may be */
/*                    loaded.  Any other DAS files loaded by the calling */
/*                    program count against this limit. */

/*     STSIZE         is the size of the segment table; this is the */
/*                    maximum number of segments that can be loaded at */
/*                    one time. */

/*     MXTBLD         is the maximum number of tables that can be loaded */
/*                    at any time.  A table can consist of multiple */
/*                    segments. */

/*     MXCLLD         is the maximum number of columns that can be loaded */
/*                    at any time.  A column may be spread across */
/*                    multiple segments; in this case, the portions of */
/*                    the column contained in each segment count against */
/*                    this limit. */

/*     ADSCSZ         is the size of column attribute descriptor. */
/*                    (Defined in ekattdsc.inc.) */

/*     LBCELL         is the SPICELIB cell lower bound. */

/*     Many other parameters are defined in the include files referenced */
/*     above.  See those files for details. */


/* $ Exceptions */

/*     1)  If this routine is called directly, the error */
/*         SPICE(BOGUSENTRY) is signaled. */

/*     See the headers of the entry points for descriptions of exceptions */
/*     specific to those routines. */

/* $ Files */

/*     This suite of routines reads binary `sequence component' EK files. */
/*     In order for a binary EK file to be accessible to this routine, */
/*     the file must be `loaded' via a call to the entry point EKLEF. */

/*     Text format EK files cannot be used by this routine; they must */
/*     first be converted by binary format by the NAIF Toolkit utility */
/*     SPACIT. */

/* $ Particulars */

/*     EKQMGR is an umbrella routine for its entry points:  all variables */
/*     used by the entry points are declared here. */

/*     EKQMGR supports loading and unloading EK files, executing queries, */
/*     and fetching the results of executed queries.  The entry points */
/*     and their functions are: */

/*        File loading and unloading: */

/*           EKLEF  ( EK, load event file   ) */
/*           EKUEF  ( EK, unload event file ) */

/*        Query execution: */

/*           EKSRCH ( EK, search for events ) */

/*        Fetching query results: */

/*           EKGC   ( EK, get event data, character        ) */
/*           EKGD   ( EK, get event data, double precision ) */
/*           EKGI   ( EK, get event data, integer          ) */

/*        Utilities: */

/*           EKNTAB ( EK, return the number of loaded tables        ) */
/*           EKTNAM ( EK, return the names of loaded tables         ) */
/*           EKCCNT ( EK, return the column count of a table        ) */
/*           EKCII  ( EK, look up column info by index              ) */
/*           EKNELT ( EK, return number of elements in column entry ) */


/*     To issue queries to the EK system, users would normally call the */
/*     high-level interface routine EKFIND.  EKFIND parses queries and */
/*     converts them to the encoded form expected by EKSRCH.  It is */
/*     possible to call EKSRCH directly, but this should not be attempted */
/*     by others than EK masters.  EKFIND is not an entry point of */
/*     EKQMGR, but instead is a separate subroutine. */

/* $ Examples */

/*     1)  Query the EK system and fetch data matching queries. */
/*         The code fragment shown here does not rely on advance */
/*         knowledge of the input query or the contents of any loaded EK */
/*         files. */

/*         To simplify the example, we assume that all data are scalar. */
/*         This assumption relieves us of the need to test the size of */
/*         column entries before fetching them.  In the event that a */
/*         column contains variable-size array entries, the entry point */
/*         EKNELT may be called to obtain the size of column entries to */
/*         be fetched.  See EKNELT for an example. */


/*            C */
/*            C     Load EK file.  Also load leapseconds file for */
/*            C     time conversion. */
/*            C */
/*                  CALL EKLEF  ( EK, HANDLE ) */
/*                  CALL FURNSH ( LEAP       ) */

/*            C */
/*            C     Prompt for query.  Parse the SELECT clause using */
/*            C     EKPSEL. */
/*            C */
/*                  CALL PROMPT ( 'Enter query > ', QUERY ) */

/*                  CALL EKPSEL ( QUERY, */
/*                                N, */
/*                                XBEGS, */
/*                                XENDS, */
/*                                XBEGS, */
/*                                XTYPES, */
/*                                XCLASS, */
/*                                TABS, */
/*                                COLS, */
/*                                ERROR, */
/*                                ERRMSG ) */


/*                  IF ( ERROR ) THEN */

/*                     WRITE (*,*) ERRMSG */

/*                  ELSE */
/*            C */
/*            C        Submit query to the EK query system. */
/*            C */
/*                     CALL EKFIND ( QUERY, NMROWS, ERROR, ERRMSG ) */

/*                     IF ( ERROR ) THEN */

/*                        WRITE (*,*) ERRMSG */

/*                     ELSE */
/*            C */
/*            C           Fetch the rows that matched the query. */
/*            C */
/*                        DO ROW = 1, NMROWS */
/*            C */
/*            C              Fetch data from the Ith row. */
/*            C */
/*                           WRITE (*,*) ' ' */
/*                           WRITE (*,*) 'ROW = ', ROW */

/*                           DO COL = 1, N */
/*            C */
/*            C                 Fetch the data from the Jth selected */
/*            C                 column. */
/*            C */
/*                              IF ( XCLASS(COL) .EQ. 'COL' ) THEN */

/*                                 OUTSTR  =  COLS(COL) */
/*                                 CALL PREFIX ( '.',       0, OUTSTR ) */
/*                                 CALL PREFIX ( TABS(COL), 0, OUTSTR ) */
/*                                 WRITE (*,*) 'COLUMN = ', OUTSTR */

/*                              ELSE */

/*                                 B  =  XBEGS(COL) */
/*                                 E  =  XENDS(COL) */
/*                                 WRITE (*,*) 'ITEM = ', QUERY(B:E) */

/*                              END IF */

/*                              IF ( XTYPES(COL) .EQ. 'CHR' ) THEN */

/*                                 CALL EKGC ( COL,   ROW,   1, */
/*                 .                           CDATA, NULL,  FOUND ) */

/*                                 IF ( NULL ) THEN */
/*                                    WRITE (*,*) '<Null>' */
/*                                 ELSE */
/*                                    WRITE (*,*) CDATA */
/*                                 END IF */


/*                              ELSE IF ( XTYPES(COL) .EQ. 'DP' ) THEN */

/*                                 CALL EKGD ( COL,   ROW,   1, */
/*                 .                           DDATA, NULL,  FOUND ) */

/*                                 IF ( NULL ) THEN */
/*                                    WRITE (*,*) '<Null>' */
/*                                 ELSE */
/*                                    WRITE (*,*) DDATA */
/*                                 END IF */


/*                              ELSE IF ( XTYPES(COL) .EQ. 'INT' ) THEN */

/*                                 CALL EKGI ( COL,   ROW,   1, */
/*                 .                           IDATA, NULL,  FOUND ) */

/*                                 IF ( NULL ) THEN */
/*                                    WRITE (*,*) '<Null>' */
/*                                 ELSE */
/*                                    WRITE (*,*) IDATA */
/*                                 END IF */


/*                              ELSE */
/*            C */
/*            C                    The item is a time value.  Convert it */
/*            C                    to UTC for output. */
/*            C */
/*                                 CALL EKGD   ( COL,   ROW,   1, */
/*                 .                             TDATA, NULL,  FOUND ) */

/*                                 IF ( NULL ) THEN */
/*                                    WRITE (*,*) '<Null>' */
/*                                 ELSE */
/*                                    CALL ET2UTC ( TDATA, 'C', 3, UTC ) */
/*                                    WRITE (*,*) UTC */
/*                                 END IF */

/*                              END IF */

/*                           END DO */
/*            C */
/*            C              We're done with the column having index COL. */
/*            C */
/*                        END DO */
/*            C */
/*            C           We're done with the row having index ROW. */
/*            C */
/*                     END IF */
/*            C */
/*            C        We either processed the query or had an error. */
/*            C */
/*                  END IF */
/*            C */
/*            C     We either parsed the SELECT clause or had an error. */
/*            C */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     B.V. Semenov   (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.1.0, 09-FEB-2015 (NJB) */

/*        Now uses ERRHAN to insert DAS file name into */
/*        long error messages. */

/* -    SPICELIB Version 2.0.3, 10-FEB-2014 (BVS) */

/*        Added descriptions of ADSCSZ and LBCELL to the Parameters */
/*        section of the header. */

/* -    SPICELIB Version 2.0.2, 22-AUG-2006 (EDW) */

/*        Replaced references to LDPOOL with references */
/*        to FURNSH. */

/* -    SPICELIB Version 2.0.1, 22-SEP-2004 (EDW) */

/*        Removed from the header descriptions, all occurrences of the */
/*        token used to mark the $Procedure section. */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (NJB) */

/*        Bug fix:   When an already loaded kernel is opened with EKOPR, */
/*        it now has its link count reset to 1 via a call to EKCLS. */

/* -    SPICELIB Version 1.3.0, 12-FEB-1999 (NJB) */

/*        Bug fix:  in entry point EKNELT, there was a error handling */
/*        branch that called CHKOUT where CHKIN should have been called. */
/*        This has been fixed. */

/* -    SPICELIB Version 1.2.0, 21-JUL-1998 (NJB) */

/*        In the entry point EKSRCH, a ZZEKJSQZ call was added after */
/*        the ZZEKJOIN call.  This change reduces the scratch area usage */
/*        for intermediate results of joins.  It also prevents ZZEKJOIN */
/*        from being handed a join row set containing a segment vector */
/*        having no corresponding row vectors. */

/* -    SPICELIB Version 1.1.0, 07-JUL-1996 (NJB) */

/*        Code fixes were made in routines */

/*           EKNELT, EKGC, EKGD, EKGI */

/*        Version lines were fixed in all routines:  versions were */
/*        changed from "Beta" to "SPICELIB." */

/* -    SPICELIB Version 1.0.0, 23-OCT-1995 (NJB) */

/* -& */
/* $ Index_Entries */

/*     Manage EK query operations */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.3.0, 12-FEB-1999 (NJB) */

/*        Bug fix:  in entry point EKNELT, there was a error handling */
/*        branch that called CHKOUT where CHKIN should have been called. */
/*        This has been fixed. */

/* -    SPICELIB Version 1.2.0, 21-JUL-1998 (NJB) */

/*        In the entry point EKSRCH, a ZZEKJSQZ call was added after */
/*        the ZZEKJOIN call.  This change reduces the scratch area usage */
/*        for intermediate results of joins.  It also prevents ZZEKJOIN */
/*        from being handed a join row set containing a segment vector */
/*        having no corresponding row vectors. */

/* -    SPICELIB Version 1.1.0, 07-JUL-1996 (NJB) */

/*        Code fixes were made in routines */

/*           EKNELT, EKGC, EKGD, EKGI */

/*        Version lines were fixed in all routines:  versions were */
/*        changed from "Beta" to "SPICELIB." */

/* -& */

/*     SPICELIB functions */


/*     Non-SPICELIB functions */


/*     Linked list functions: */

/*        Find next node */
/*        Find tail of list */
/*        Return number of free nodes */



/*     Local parameters */


/*     Maximum number of constraints allowed in a single query: */


/*     Miscellaneous parameters */


/*     Number of data types */


/*     Length of strings used for data type names. */


/*     Length of status strings. */


/*     Local variables */


/*     As do the CK and SPK `BSR' entry points, the EKQMGR entry points */
/*     make use of an amusing panoply of tables, linked lists, and */
/*     pointers.  Here's where they're declared and described. */


/*     The file table contains a list of handles of loaded EK files. */
/*     Entries in the table are organized as a doubly linked list. */
/*     Names of file table variables begin with the string 'FT'. */

/*        The maximum number of EK files that can be loaded is FTSIZE. */

/*        The linked list pool used to index table entries is called */
/*        FTPOOL. */

/*        FTHAN is an array containing file handles of loaded EKs. */

/*        FTHEAD is the head node of the file list. */


/*     The table list contains table names, segment table pointers, */
/*     and column table pointers for every table associated with a */
/*     loaded segment.  The segment table pointers indicate the head node */
/*     of the segment list for each table.  The column table pointers */
/*     indicate the column names and attributes associated with each */
/*     table. */

/*     The entries of the table list are organized as a doubly linked */
/*     list.  All variables in the table list have names starting with */
/*     the string 'TB'. */

/*        MXTBLD is the maximum number of tables that can be */
/*        accommodated by the table list. */

/*        TBPOOL is the doubly linked list pool used to index the */
/*        table list. */

/*        TBNAMS is an array of table names. */

/*        TBSTPT is an array containing pointers to the heads of segment */
/*        lists corresponding to segments belonging to the table. */

/*        TBNCOL is the number of columns in each table. */

/*        TBCTPT is an array of pointers to lists of column table */
/*        entries giving the names and attributes of the columns in each */
/*        table. */

/*        TBFILS is an array containing, for each table, handles of the */
/*        files that contain segments belonging to that table. */

/*        TBFLSZ is an array of sizes of handle lists for each table */
/*        entry. */

/*        TBHEAD is the head node of the table list. */




/*     The segment table contains descriptive information for each */
/*     loaded segment.  Entries in the table are indexed by a linked */
/*     list pool containing a doubly linked list for each system (or */
/*     instrument) for which segments are loaded. */

/*     Names of segment table variables begin with the string 'ST'. */

/*        The maximum number of segments that can be loaded is MAXSEG. */
/*        Currently, the value of MAXSEG is just the size of the segment */
/*        table, STSIZE. */

/*        The linked list pool used to index segment table entries is */
/*        called STPOOL. */

/*        For each loaded segment, the following information is stored: */

/*           -- The file handle of the EK containing the segment. */

/*           -- The index of the segment within the EK that contains it. */
/*              Indices start at 1 and end with the segment count for the */
/*              EK file. */

/*           -- The segment descriptor. */

/*           -- The number of rows in the segment. */

/*           -- The number of columns in the segment. */

/*           -- A pointer to a list of column descriptors.  The */
/*              column descriptor table contains a complete descriptor */
/*              for every loaded column. */




/*     The column descriptor table contains a column descriptor for */
/*     every loaded column.  This table allows segments to share the */
/*     area used for buffering descriptors, making it reasonable for */
/*     the buffer space to have room for fewer than */

/*        MXCLLD * MAXSEG */

/*     column descriptors. */

/*     The space in the table is organized as a doubly linked list. */


/*     The column attribute table contains attribute information for */
/*     every column in every loaded segment.  There is one entry per */
/*     column name; columns with the same names and different data */
/*     types may not be loaded simultaneously. */

/*     The entries of the column table are organized as a doubly linked */
/*     list.  All variables in the column table have names starting with */
/*     the string 'CT'. */

/*        CTSIZE is the maximum number of distinct column declarations */
/*        that can be accommodated by the column table. */

/*        CTPOOL is the doubly linked list pool used to index the column */
/*        table. */

/*        CTNAMS is an array containing column names. */

/*        CTCLAS is an array containing column class specifiers. */

/*        CTTYPS is an array containing column data types. */

/*        CTLENS is an array containing column string length specifiers. */

/*        CTFIXD is an array of logical flags indicating whether the */
/*        columns they correspond to have fixed size. */

/*        CTSIZS is an array of integers indicating the number of array */
/*        elements per column entry, for fixed-size columns. */

/*        CTINDX is an array of logical flags that indicate whether the */
/*        columns they correspond to are indexed. */

/*        CTNULL is an array of logical flags that indicate whether the */
/*        columns they correspond to may contain null values. */




/*     Other local variables */



/*     Saved variables */



/*     Initial values */

    /* Parameter adjustments */
    if (eqryd) {
	}
    if (eqryi) {
	}
    if (attdsc) {
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_eklef;
	case 2: goto L_ekuef;
	case 3: goto L_ekntab;
	case 4: goto L_ektnam;
	case 5: goto L_ekccnt;
	case 6: goto L_ekcii;
	case 7: goto L_eksrch;
	case 8: goto L_eknelt;
	case 9: goto L_ekgc;
	case 10: goto L_ekgd;
	case 11: goto L_ekgi;
	}


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "EKQMGR", (ftnlen)6);
    }

/*     Never come here. */

    sigerr_(__global_state, "SPICE(BOGUSENTRY)", (ftnlen)17);
    chkout_(__global_state, "EKQMGR", (ftnlen)6);
    return 0;
/* $Procedure     EKLEF  ( EK, load event file ) */

L_eklef:
/* $ Abstract */

/*     Load an EK file, making it accessible to the EK readers. */

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
/*     SEARCH */

/* $ Declarations */

/*     CHARACTER*(*)         FNAME */
/*     INTEGER               HANDLE */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     FNAME      I   Name of EK file to load. */
/*     HANDLE     O   File handle of loaded EK file. */

/* $ Detailed_Input */

/*     FNAME          is the name of a binary EK file to be loaded. */

/* $ Detailed_Output */

/*     HANDLE         is the handle of the EK file.  The file is */
/*                    accessible by the EK reader routines once it */
/*                    has been loaded. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the EK file indicated by FNAME contains a column whose */
/*         name matches that of a column in an already loaded EK, but */
/*         whose declared attributes don't match those of the loaded */
/*         column of the same name, the error SPICE(BADATTRIBUTES) is */
/*         signaled.  HANDLE is is undefined in this case. */

/*     2)  Loading an EK file that is already loaded does not cause side */
/*         effects.  The handle already associated with the file will be */
/*         returned. */

/*     3)  If a file open error occurs, the problem will be diagnosed by */
/*         routines called by this routine.  HANDLE is undefined in */
/*         this case. */

/*     4)  If loading the input file would cause the maximum number of */
/*         loaded EK files to be exceeded, the error */
/*         SPICE(EKFILETABLEFULL) will be signaled.  HANDLE is */
/*         undefined in this case.  This routine will attempt to */
/*         unload the file from the DAS system. */

/*     5)  If loading the input file would cause the maximum number of */
/*         loaded DAS files to be exceeded, the error will be diagnosed */
/*         by routines called by this routine.  HANDLE is undefined in */
/*         this case.  This routine will attempt to unload the file */
/*         from the DAS system. */

/*     6)  If loading the input file would cause the maximum number of */
/*         segments allowed in loaded EK files to be exceeded, the error */
/*         SPICE(EKSEGMENTTABLEFULL) will be signaled.  HANDLE is */
/*         is undefined in this case.  This routine will attempt to */
/*         unload the file from the DAS system. */

/*     7)  If loading the input file would cause the maximum number of */
/*         columns allowed in loaded EK files to be exceeded, the error */
/*         SPICE(EKCOLDESCTABLEFULL) will be signaled.  HANDLE is */
/*         is undefined in this case.  This routine will attempt to */
/*         unload the file from the DAS system. */

/*     8)  If loading the input file would cause the maximum allowed */
/*         number of columns having distinct attributes in loaded EK */
/*         files to be exceeded, the error SPICE(EKCOLATTRTABLEFULL) will */
/*         be signaled.  HANDLE is is undefined in this case.  This */
/*         routine will attempt to unload the file from the DAS system. */

/*     9)  If loading the input file would cause the maximum number of */
/*         instrument codes allowed in loaded EK files to be exceeded, */
/*         the error SPICE(EKIDTABLEFULL) will be signaled.  HANDLE is */
/*         is undefined in this case.  This routine will attempt to */
/*         unload the file from the DAS system. */

/*     10) If the input file does not contain at least one segment, the */
/*         error SPICE(EKNOSEGMENTS) will be signaled. */

/* $ Files */

/*     See description of FNAME in $Detailed_Input. */

/* $ Particulars */

/*     This routine makes EK files known to the EK system.  It is */
/*     necessary to load EK files using this routine in order to */
/*     query the files using the EK readers. */

/* $ Examples */

/*     1)  Load three EK files.  During query execution, all files */
/*         will be searched. */

/*            DO I = 1, 3 */
/*               CALL EKLEF ( EK(I), HANDLE ) */
/*            END DO */

/*            [Perform queries] */


/*     2)  Load 25 EK files sequentially, unloading the previous file */
/*         before each new file is loaded.  Unloading files prevents */
/*         them from being searched during query execution. */

/*            DO I = 1, 25 */

/*               CALL EKLEF ( EK(I), HANDLE ) */

/*               [Perform queries] */

/*               CALL EKUEF ( HANDLE ) */

/*            END DO */

/* $ Restrictions */

/*     1)  EK files containing columns having the same name but */
/*         inconsistent declarations are not diagnosed.  Such kernels */
/*         are invalid in any case. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.1.0, 09-FEB-2015 (NJB) */

/*        Now uses ERRHAN to insert DAS file name into */
/*        long error messages. */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (NJB) */

/*        Bug fix:   When an already loaded kernel is opened with EKOPR, */
/*        it now has its link count reset to 1 via a call to EKCLS. */

/* -    SPICELIB Version 1.0.1, 07-JUL-1996 (NJB) */

/*        Previous version line was changed from "Beta" to "SPICELIB." */

/* -    SPICELIB Version 1.0.0, 23-OCT-1995 (NJB) */

/* -& */
/* $ Index_Entries */

/*     load EK file */
/*     load E-Kernel */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "EKLEF", (ftnlen)5);
    }

/*     Here's a brief overview of what follows: */

/*        -- We do some once-per-program run initializations. */

/*        -- We do some simple error checks.  We need to make sure */
/*           that DAS can load the file, and that the EK architecture is */
/*           the right kind. */

/*        -- We need to make sure that there's enough space in our */
/*           data structures to hold the information about the new */
/*           EK.  Some of these checks are simple; we do these first. */
/*           However, checking that we have enough room in the column */
/*           table is best done by simply loading the column data into */
/*           the table.  If we run out of room, we abort the load. */

/*        -- We also need to make sure that the column attributes for */
/*           any two columns with the same name in the same table are */
/*           identical.  This is easy to do if the attributes for every */
/*           column we've encountered have been loaded into the column */
/*           table. */

/*        -- We save the table name and column names and attributes for */
/*           each new table we encounter.  For each table, we maintain a */
/*           list of handles of files that contain segments in that */
/*           table. */

/*        -- We make a segment table entry for each segment we find. */

/*        -- We save the column descriptor for each column we find, */
/*           associating it with the segment table entry for the segment */
/*           containing the column.  The column descriptor entries are */
/*           linked together in the same order that the corresponding */
/*           column names appear in the parent table's column name list; */
/*           this order is not necessarily the order that the columns */
/*           have within the segment. */

/*        -- We maintain a list of handles of loaded EKs. */

/*        If we run out of room in the column table, we clean up our */
/*        mess.  This means removing the current file's contributions */
/*        to the column table, segment table, file table, and if */
/*        necessary, the table list. */


/*     On the first pass through this routine, initialize the tables, */
/*     if it hasn't been done yet. */

    if (__state->first) {

/*        Initialize the file table pool, segment table pool, column */
/*        descriptor pool, column table pool, and table list pool. */

	lnkini_(__global_state, &__state->c__20, __state->ftpool);
	lnkini_(__global_state, &__state->c__200, __state->stpool);
	lnkini_(__global_state, &__state->c__10000, __state->dtpool);
	lnkini_(__global_state, &__state->c__500, __state->ctpool);
	lnkini_(__global_state, &__state->c__100, __state->tbpool);
	__state->fthead = 0;
	__state->tbhead = 0;
	__state->first = FALSE_;
    }

/*     Open the EK file for read access.  Bail out now if this doesn't */
/*     work.  This retreat will protect the various tables from */
/*     corruption. */

    ekopr_(__global_state, fname, handle, fname_len);
    if (failed_(__global_state)) {
	chkout_(__global_state, "EKLEF", (ftnlen)5);
	return 0;
    }

/*     Check to see whether the named EK has already been loaded. */
/*     If so, we've added another link to the EK, which must be */
/*     removed. */

    __state->i__ = __state->fthead;
    while(__state->i__ > 0) {
	if (*handle == __state->fthan[(i__1 = __state->i__ - 1) < 20 && 0 <= 
		i__1 ? i__1 : s_rnge(&__global_state->f2c, "fthan", i__1, 
		"ekqmgr_", (ftnlen)1214)]) {

/*           The last call we made to EKOPR added another link to */
/*           the EK file.  Remove this link. */

	    dascls_(__global_state, handle);
	    chkout_(__global_state, "EKLEF", (ftnlen)5);
	    return 0;
	}
	__state->i__ = lnknxt_(__global_state, &__state->i__, __state->ftpool)
		;
    }

/*     Nothing doing unless the architecture is correct.  This file */
/*     should be a paged DAS EK. */

    zzekpgch_(__global_state, handle, "READ", (ftnlen)4);

/*     Before getting too involved with this new EK file, let's check it */
/*     out.  We must have enough room to accommodate it in the file */
/*     table, segment table, table list, and column table. */

/*     Make sure there's enough room in the file table. */

    if (lnknfn_(__global_state, __state->ftpool) == 0) {

/*        Sorry, there are no free file table entries left. */

/*        We close the EK AFTER setting the long error message. */

	setmsg_(__global_state, "The EK file # could not be loaded; the maxi"
		"mum number of loaded EKs has already been reached.", (ftnlen)
		93);
	errhan_(__global_state, "#", handle, (ftnlen)1);
	ekcls_(__global_state, handle);
	sigerr_(__global_state, "SPICE(EKFILETABLEFULL)", (ftnlen)22);
	chkout_(__global_state, "EKLEF", (ftnlen)5);
	return 0;
    }

/*     Find out how many segments are in the new kernel, and make */
/*     sure there's enough room in the segment table. */

    __state->nseg = eknseg_(__global_state, handle);
    if (__state->nseg > lnknfn_(__global_state, __state->stpool)) {

/*        There are too many segments for the amount of space we've got */
/*        left. */

/*        We close the EK AFTER setting the long error message. */

	setmsg_(__global_state, "The EK file # could not be loaded; the maxi"
		"mum number of loaded segments has already been reached.", (
		ftnlen)98);
	errhan_(__global_state, "#", handle, (ftnlen)1);
	ekcls_(__global_state, handle);
	sigerr_(__global_state, "SPICE(EKSEGTABLEFULL)", (ftnlen)21);
	chkout_(__global_state, "EKLEF", (ftnlen)5);
	return 0;
    } else if (__state->nseg < 1) {
	setmsg_(__global_state, "The EK file # contains no segments.", (
		ftnlen)35);
	errhan_(__global_state, "#", handle, (ftnlen)1);
	ekcls_(__global_state, handle);
	sigerr_(__global_state, "SPICE(EKNOSEGMENTS)", (ftnlen)19);
	chkout_(__global_state, "EKLEF", (ftnlen)5);
	return 0;
    }

/*     At this point, the file has insinuated itself into our confidence, */
/*     justified or not.  We'll attempt to load the segment and column */
/*     tables, and we'll update the table list if new tables are */
/*     introduced in this file. */

    __state->seg = 1;
    s_copy(&__global_state->f2c, __state->state, "LOAD_FILE_TABLE", (ftnlen)
	    80, (ftnlen)15);
    while(s_cmp(&__global_state->f2c, __state->state, "DONE", (ftnlen)80, (
	    ftnlen)4) != 0) {
	if (s_cmp(&__global_state->f2c, __state->state, "LOAD_FILE_TABLE", (
		ftnlen)80, (ftnlen)15) == 0) {

/*           Allocate a file table entry and link the new entry in before */
/*           the current head of the list.  Update the list head pointer. */
/*           Record the file handle in the new file table entry. */

	    lnkan_(__global_state, __state->ftpool, &__state->new__);
	    lnkilb_(__global_state, &__state->new__, &__state->fthead, 
		    __state->ftpool);
	    __state->fthead = __state->new__;
	    __state->fthan[(i__1 = __state->new__ - 1) < 20 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "fthan", i__1, "ekqm"
		    "gr_", (ftnlen)1317)] = *handle;
	    s_copy(&__global_state->f2c, __state->state, "SUMMARIZE_SEGMENT", 
		    (ftnlen)80, (ftnlen)17);
	} else if (s_cmp(&__global_state->f2c, __state->state, "SUMMARIZE_SE"
		"GMENT", (ftnlen)80, (ftnlen)17) == 0) {

/*           Get the summary information for this segment. */

	    zzeksinf_(__global_state, handle, &__state->seg, __state->tabnam, 
		    __state->segdsc, __state->cnams, __state->cdscrs, (ftnlen)
		    64, (ftnlen)32);
	    __state->ncols = __state->segdsc[4];

/*           Before going further, check the segment for duplicate */
/*           column names.  Bail out if we find any. */

	    ssizec_(__global_state, &__state->c__500, __state->cnmset, (
		    ftnlen)32);
	    movec_(__global_state, __state->cnams, &__state->ncols, 
		    __state->cnmset + 192, (ftnlen)32, (ftnlen)32);
	    validc_(__global_state, &__state->c__500, &__state->ncols, 
		    __state->cnmset, (ftnlen)32);
	    if (cardc_(__global_state, __state->cnmset, (ftnlen)32) < 
		    __state->ncols) {
		s_copy(&__global_state->f2c, __state->state, "ABORT", (ftnlen)
			80, (ftnlen)5);
		s_copy(&__global_state->f2c, __state->problm, "DUPLICATE_COL"
			"UMN_NAMES", (ftnlen)80, (ftnlen)22);
	    } else {
		s_copy(&__global_state->f2c, __state->state, "FIND_TABLE", (
			ftnlen)80, (ftnlen)10);
	    }
	} else if (s_cmp(&__global_state->f2c, __state->state, "FIND_TABLE", (
		ftnlen)80, (ftnlen)10) == 0) {

/*           Traverse the table list, checking for a match. */

	    __state->tbcurr = __state->tbhead;
	    __state->presnt = FALSE_;
	    while(__state->tbcurr > 0 && ! __state->presnt) {
		if (s_cmp(&__global_state->f2c, __state->tabnam, 
			__state->tbnams + (((i__1 = __state->tbcurr - 1) < 
			100 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c,
			 "tbnams", i__1, "ekqmgr_", (ftnlen)1362)) << 6), (
			ftnlen)64, (ftnlen)64) == 0) {
		    __state->presnt = TRUE_;
		} else {
		    __state->tbcurr = lnknxt_(__global_state, &
			    __state->tbcurr, __state->tbpool);
		}
	    }

/*           If TABNAM is the name of a table we know about, go on to */
/*           fill out the segment list entry for the current segment. */
/*           If we didn't find TABNAM, we have a new table.  Make a table */
/*           list entry for it. */

	    if (__state->presnt) {

/*              Before going further, make sure the number of columns */
/*              in the segment matches the number of columns in the */
/*              parent table. */

		if (__state->ncols != __state->tbncol[(i__1 = __state->tbcurr 
			- 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "tbncol", i__1, "ekqmgr_", (
			ftnlen)1382)]) {
		    __state->npcol = __state->tbncol[(i__1 = __state->tbcurr 
			    - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "tbncol", i__1, "ekqmgr_", (
			    ftnlen)1384)];
		    s_copy(&__global_state->f2c, __state->state, "ABORT", (
			    ftnlen)80, (ftnlen)5);
		    s_copy(&__global_state->f2c, __state->problm, "COLUMN_NU"
			    "MBER_MISMATCH", (ftnlen)80, (ftnlen)22);
		} else {

/*                 Add the current file to the list of files containing */
/*                 the current table. */

		    __state->tbfils[(i__1 = __state->tbcurr * 20 - 20) < 2000 
			    && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c,
			     "tbfils", i__1, "ekqmgr_", (ftnlen)1393)] = *
			    handle;
		    __state->tbflsz[(i__1 = __state->tbcurr - 1) < 100 && 0 <=
			     i__1 ? i__1 : s_rnge(&__global_state->f2c, "tbf"
			    "lsz", i__1, "ekqmgr_", (ftnlen)1394)] = 
			    __state->tbflsz[(i__2 = __state->tbcurr - 1) < 
			    100 && 0 <= i__2 ? i__2 : s_rnge(&
			    __global_state->f2c, "tbflsz", i__2, "ekqmgr_", (
			    ftnlen)1394)] + 1;
		    s_copy(&__global_state->f2c, __state->state, "MAKE_SEGME"
			    "NT_TABLE_ENTRY", (ftnlen)80, (ftnlen)24);
		}
	    } else {

/*              This segment belongs to a new table. */

		s_copy(&__global_state->f2c, __state->state, "MAKE_TABLE_LIS"
			"T_ENTRY", (ftnlen)80, (ftnlen)21);
	    }
	} else if (s_cmp(&__global_state->f2c, __state->state, "MAKE_TABLE_L"
		"IST_ENTRY", (ftnlen)80, (ftnlen)21) == 0) {

/*           Allocate a table list entry, if we can. */

	    if (lnknfn_(__global_state, __state->tbpool) == 0) {

/*              Oops, we're out of room. */

		s_copy(&__global_state->f2c, __state->state, "ABORT", (ftnlen)
			80, (ftnlen)5);
		s_copy(&__global_state->f2c, __state->problm, "TABLE_LIST_FU"
			"LL", (ftnlen)80, (ftnlen)15);
	    } else {

/*              We have an entry; link it to the tail of the table list. */
/*              For consistency with the case in which the table entry */
/*              already exists, we'll call the table list node TBCURR. */

/*              If this is the first table in the table list, set the */
/*              table head pointer. */

		lnkan_(__global_state, __state->tbpool, &__state->tbcurr);
		if (__state->tbhead <= 0) {
		    __state->tbhead = __state->tbcurr;
		} else {
		    lnkilb_(__global_state, &__state->tbhead, &
			    __state->tbcurr, __state->tbpool);
		}

/*              Fill in the table name. */

		s_copy(&__global_state->f2c, __state->tbnams + (((i__1 = 
			__state->tbcurr - 1) < 100 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "tbnams", i__1, "ekqmgr_"
			, (ftnlen)1442)) << 6), __state->tabnam, (ftnlen)64, (
			ftnlen)64);

/*              Since this table is new, the file list for this table */
/*              contains only the handle of the current EK. */

		__state->tbfils[(i__1 = __state->tbcurr * 20 - 20) < 2000 && 
			0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "tbf"
			"ils", i__1, "ekqmgr_", (ftnlen)1447)] = *handle;
		__state->tbflsz[(i__1 = __state->tbcurr - 1) < 100 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "tbflsz", 
			i__1, "ekqmgr_", (ftnlen)1448)] = 1;

/*              Initialize the column count, column table pointer, and */
/*              segment list pointer for this table. */

		__state->tbncol[(i__1 = __state->tbcurr - 1) < 100 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "tbncol", 
			i__1, "ekqmgr_", (ftnlen)1454)] = __state->ncols;
		__state->tbctpt[(i__1 = __state->tbcurr - 1) < 100 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "tbctpt", 
			i__1, "ekqmgr_", (ftnlen)1455)] = 0;
		__state->tbstpt[(i__1 = __state->tbcurr - 1) < 100 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "tbstpt", 
			i__1, "ekqmgr_", (ftnlen)1456)] = 0;

/*              Go on to add a segment table entry for the current */
/*              segment. */

		s_copy(&__global_state->f2c, __state->state, "MAKE_SEGMENT_T"
			"ABLE_ENTRY", (ftnlen)80, (ftnlen)24);
	    }
	} else if (s_cmp(&__global_state->f2c, __state->state, "MAKE_SEGMENT"
		"_TABLE_ENTRY", (ftnlen)80, (ftnlen)24) == 0) {

/*           Add the data for the current segment to the segment */
/*           table. */

/*           Allocate a segment table entry.  We've already verified */
/*           that there's enough room. */

	    lnkan_(__global_state, __state->stpool, &__state->stnew);

/*           Link this segment table entry to the tail of the segment */
/*           list for the parent table, or, if the tail is NIL, just set */
/*           the segment list pointer to the current segment node. */

	    if (__state->tbstpt[(i__1 = __state->tbcurr - 1) < 100 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "tbstpt", i__1,
		     "ekqmgr_", (ftnlen)1482)] <= 0) {
		__state->tbstpt[(i__1 = __state->tbcurr - 1) < 100 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "tbstpt", 
			i__1, "ekqmgr_", (ftnlen)1484)] = __state->stnew;
	    } else {
		lnkilb_(__global_state, &__state->tbstpt[(i__1 = 
			__state->tbcurr - 1) < 100 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "tbstpt", i__1, "ekqmgr_"
			, (ftnlen)1488)], &__state->stnew, __state->stpool);
	    }

/*           At this point, we can fill in all elements of the segment */
/*           table entry except for the pointers into the column table */
/*           and the column base addresses. */

	    __state->sthan[(i__1 = __state->stnew - 1) < 200 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "sthan", i__1, "ekqm"
		    "gr_", (ftnlen)1497)] = *handle;
	    __state->stsidx[(i__1 = __state->stnew - 1) < 200 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stsidx", i__1, "ekq"
		    "mgr_", (ftnlen)1498)] = __state->seg;
	    __state->stnrow[(i__1 = __state->stnew - 1) < 200 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stnrow", i__1, "ekq"
		    "mgr_", (ftnlen)1499)] = __state->segdsc[5];
	    __state->stncol[(i__1 = __state->stnew - 1) < 200 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stncol", i__1, "ekq"
		    "mgr_", (ftnlen)1500)] = __state->segdsc[4];
	    __state->stdtpt[(i__1 = __state->stnew - 1) < 200 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stdtpt", i__1, "ekq"
		    "mgr_", (ftnlen)1501)] = 0;
	    movei_(__global_state, __state->segdsc, &__state->c__24, &
		    __state->stdscs[(i__1 = __state->stnew * 24 - 24) < 4800 
		    && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stds"
		    "cs", i__1, "ekqmgr_", (ftnlen)1503)]);

/*           The next step is to set up the column attributes and */
/*           descriptors. */

	    s_copy(&__global_state->f2c, __state->state, "MAKE_COLUMN_TABLE_"
		    "ENTRIES", (ftnlen)80, (ftnlen)25);
	} else if (s_cmp(&__global_state->f2c, __state->state, "MAKE_COLUMN_"
		"TABLE_ENTRIES", (ftnlen)80, (ftnlen)25) == 0) {
	    if (__state->presnt) {

/*              If the current table was present before loading the */
/*              current segment, we must make sure that the attributes */
/*              of the columns in this segment match those of the table */
/*              to which the segment belongs. */

/*              We must load the column descriptors for this segment */
/*              in the *same order* as those for every other segment */
/*              in the table.  This order matches that of the columns */
/*              in the column attribute list for the table. */

/*              For each column in the column list of the current table, */
/*              check the list of column names for the current segment, */
/*              looking for a match. */

		__state->j = __state->tbctpt[(i__1 = __state->tbcurr - 1) < 
			100 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c,
			 "tbctpt", i__1, "ekqmgr_", (ftnlen)1532)];
		while(__state->j > 0 && s_cmp(&__global_state->f2c, 
			__state->state, "ABORT", (ftnlen)80, (ftnlen)5) != 0) 
			{
		    __state->k = isrchc_(__global_state, __state->ctnams + (((
			    i__1 = __state->j - 1) < 500 && 0 <= i__1 ? i__1 :
			     s_rnge(&__global_state->f2c, "ctnams", i__1, 
			    "ekqmgr_", (ftnlen)1538)) << 5), &__state->ncols, 
			    __state->cnams, (ftnlen)32, (ftnlen)32);
		    if (__state->k > 0) {

/*                    We have a name match.  At this point, we must */
/*                    check that the column's other attributes---data */
/*                    type, size, and whether the column is */
/*                    indexed---match as well.  It's an error if they */
/*                    don't. */

			__state->indexd = __state->cdscrs[(i__1 = __state->k *
				 11 - 6) < 5500 && 0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "cdscrs", i__1, "ekqmgr_"
				, (ftnlen)1549)] != -1;
			__state->nulsok = __state->cdscrs[(i__1 = __state->k *
				 11 - 4) < 5500 && 0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "cdscrs", i__1, "ekqmgr_"
				, (ftnlen)1550)] != -1;
			__state->attmch = __state->cdscrs[(i__1 = __state->k *
				 11 - 11) < 5500 && 0 <= i__1 ? i__1 : s_rnge(
				&__global_state->f2c, "cdscrs", i__1, "ekqmg"
				"r_", (ftnlen)1551)] == __state->ctclas[(i__2 =
				 __state->j - 1) < 500 && 0 <= i__2 ? i__2 : 
				s_rnge(&__global_state->f2c, "ctclas", i__2, 
				"ekqmgr_", (ftnlen)1551)] && __state->cdscrs[(
				i__3 = __state->k * 11 - 10) < 5500 && 0 <= 
				i__3 ? i__3 : s_rnge(&__global_state->f2c, 
				"cdscrs", i__3, "ekqmgr_", (ftnlen)1551)] == 
				__state->cttyps[(i__4 = __state->j - 1) < 500 
				&& 0 <= i__4 ? i__4 : s_rnge(&
				__global_state->f2c, "cttyps", i__4, "ekqmgr_"
				, (ftnlen)1551)] && __state->cdscrs[(i__5 = 
				__state->k * 11 - 9) < 5500 && 0 <= i__5 ? 
				i__5 : s_rnge(&__global_state->f2c, "cdscrs", 
				i__5, "ekqmgr_", (ftnlen)1551)] == 
				__state->ctlens[(i__6 = __state->j - 1) < 500 
				&& 0 <= i__6 ? i__6 : s_rnge(&
				__global_state->f2c, "ctlens", i__6, "ekqmgr_"
				, (ftnlen)1551)] && __state->cdscrs[(i__7 = 
				__state->k * 11 - 8) < 5500 && 0 <= i__7 ? 
				i__7 : s_rnge(&__global_state->f2c, "cdscrs", 
				i__7, "ekqmgr_", (ftnlen)1551)] == 
				__state->ctsizs[(i__8 = __state->j - 1) < 500 
				&& 0 <= i__8 ? i__8 : s_rnge(&
				__global_state->f2c, "ctsizs", i__8, "ekqmgr_"
				, (ftnlen)1551)] && __state->indexd == 
				__state->ctindx[(i__9 = __state->j - 1) < 500 
				&& 0 <= i__9 ? i__9 : s_rnge(&
				__global_state->f2c, "ctindx", i__9, "ekqmgr_"
				, (ftnlen)1551)] && __state->nulsok == 
				__state->ctnull[(i__10 = __state->j - 1) < 
				500 && 0 <= i__10 ? i__10 : s_rnge(&
				__global_state->f2c, "ctnull", i__10, "ekqmg"
				"r_", (ftnlen)1551)];
			if (__state->attmch) {

/*                       Great, the attributes match.  Actually, the */
/*                       addition of the current segment can *change* */
/*                       one attribute of the current table:  the */
/*                       maximum non-blank width associated with the */
/*                       current column, if the column has character */
/*                       type.  We'll make this change after we're */
/*                       sure we won't have to undo it. */

/*                       Store the column descriptor for this column */
/*                       in the descriptor table.  We'll need to */
/*                       allocate a descriptor table entry first. */

			    if (lnknfn_(__global_state, __state->dtpool) == 0)
				     {

/*                          No free nodes left in the descriptor table. */

				s_copy(&__global_state->f2c, __state->state, 
					"ABORT", (ftnlen)80, (ftnlen)5);
				s_copy(&__global_state->f2c, __state->problm, 
					"DESCRIPTOR_TABLE_FULL", (ftnlen)80, (
					ftnlen)21);
			    } else {

/*                          A free node is available.  Link it in */
/*                          at the tail of the descriptor list for */
/*                          the current segment. */

				lnkan_(__global_state, __state->dtpool, &
					__state->dtnew);
				if (__state->stdtpt[(i__1 = __state->stnew - 
					1) < 200 && 0 <= i__1 ? i__1 : s_rnge(
					&__global_state->f2c, "stdtpt", i__1, 
					"ekqmgr_", (ftnlen)1589)] <= 0) {
				    __state->stdtpt[(i__1 = __state->stnew - 
					    1) < 200 && 0 <= i__1 ? i__1 : 
					    s_rnge(&__global_state->f2c, 
					    "stdtpt", i__1, "ekqmgr_", (
					    ftnlen)1591)] = __state->dtnew;
				} else {
				    lnkilb_(__global_state, &__state->stdtpt[(
					    i__1 = __state->stnew - 1) < 200 
					    && 0 <= i__1 ? i__1 : s_rnge(&
					    __global_state->f2c, "stdtpt", 
					    i__1, "ekqmgr_", (ftnlen)1595)], &
					    __state->dtnew, __state->dtpool);
				}

/*                          Fill in the descriptor. */

				movei_(__global_state, &__state->cdscrs[(i__1 
					= __state->k * 11 - 11) < 5500 && 0 <=
					 i__1 ? i__1 : s_rnge(&
					__global_state->f2c, "cdscrs", i__1, 
					"ekqmgr_", (ftnlen)1602)], &
					__state->c__11, &__state->dtdscs[(
					i__2 = __state->dtnew * 11 - 11) < 
					110000 && 0 <= i__2 ? i__2 : s_rnge(&
					__global_state->f2c, "dtdscs", i__2, 
					"ekqmgr_", (ftnlen)1602)]);
			    }

/*                       We filled in a descriptor table entry, or */
/*                       else we ran out of room. */

			} else {

/*                       Seriously bad news.  Someone's tried to */
/*                       load an EK containing a column with */
/*                       attributes that conflict with those of a */
/*                       loaded column of the same name in the */
/*                       current table. */

			    s_copy(&__global_state->f2c, __state->colnam, 
				    __state->ctnams + (((i__1 = __state->j - 
				    1) < 500 && 0 <= i__1 ? i__1 : s_rnge(&
				    __global_state->f2c, "ctnams", i__1, 
				    "ekqmgr_", (ftnlen)1620)) << 5), (ftnlen)
				    32, (ftnlen)32);
			    s_copy(&__global_state->f2c, __state->state, 
				    "ABORT", (ftnlen)80, (ftnlen)5);
			    s_copy(&__global_state->f2c, __state->problm, 
				    "MISMATCHED_COLUMN_ATTRIBUTES", (ftnlen)
				    80, (ftnlen)28);
			}
		    } else {

/*                    No name match; the current column from the current */
/*                    table is not present in the segment we're looking */
/*                    at. */

			s_copy(&__global_state->f2c, __state->colnam, 
				__state->ctnams + (((i__1 = __state->j - 1) < 
				500 && 0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "ctnams", i__1, "ekqmgr_"
				, (ftnlen)1633)) << 5), (ftnlen)32, (ftnlen)
				32);
			s_copy(&__global_state->f2c, __state->state, "ABORT", 
				(ftnlen)80, (ftnlen)5);
			s_copy(&__global_state->f2c, __state->problm, "MISSI"
				"NG_COLUMN", (ftnlen)80, (ftnlen)14);
		    }

/*                 The current column matched one in the column list */
/*                 for the current table, or else we have a problem. */

/*                 Advance to the next column in the table's column list. */

		    if (s_cmp(&__global_state->f2c, __state->state, "ABORT", (
			    ftnlen)80, (ftnlen)5) != 0) {
			__state->j = lnknxt_(__global_state, &__state->j, 
				__state->ctpool);
		    }
		}

/*              We've made descriptor table entries for each column in */
/*              the current segment, or else we have an error. */

	    } else {

/*              We need to set up the column attribute entries for */
/*              the new table introduced by loading this segment.  We */
/*              also need to set up descriptor table entries for the */
/*              segment.  We *don't* have to check the consistency of */
/*              the attributes of the columns. */

		__state->k = 1;
		while(__state->k <= __state->ncols && s_cmp(&
			__global_state->f2c, __state->state, "ABORT", (ftnlen)
			80, (ftnlen)5) != 0) {

/*                 Allocate a new entry in the column attribute table and */
/*                 link it to the tail of the column list for the */
/*                 current table.  If the column list is empty, update */
/*                 the list head. */

		    if (lnknfn_(__global_state, __state->ctpool) == 0) {

/*                    There's no more space to store attribute */
/*                    descriptors. */

			s_copy(&__global_state->f2c, __state->state, "ABORT", 
				(ftnlen)80, (ftnlen)5);
			s_copy(&__global_state->f2c, __state->problm, "ATTRI"
				"BUTE_TABLE_FULL", (ftnlen)80, (ftnlen)20);
		    } else {
			lnkan_(__global_state, __state->ctpool, &
				__state->ctnew);
			if (__state->tbctpt[(i__1 = __state->tbcurr - 1) < 
				100 && 0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "tbctpt", i__1, "ekqmgr_"
				, (ftnlen)1684)] <= 0) {
			    __state->tbctpt[(i__1 = __state->tbcurr - 1) < 
				    100 && 0 <= i__1 ? i__1 : s_rnge(&
				    __global_state->f2c, "tbctpt", i__1, 
				    "ekqmgr_", (ftnlen)1686)] = 
				    __state->ctnew;
			} else {
			    lnkilb_(__global_state, &__state->tbctpt[(i__1 = 
				    __state->tbcurr - 1) < 100 && 0 <= i__1 ? 
				    i__1 : s_rnge(&__global_state->f2c, "tbc"
				    "tpt", i__1, "ekqmgr_", (ftnlen)1690)], &
				    __state->ctnew, __state->ctpool);
			}

/*                    Fill in the new column attribute entry with the */
/*                    attributes for this column. */

			s_copy(&__global_state->f2c, __state->ctnams + (((
				i__1 = __state->ctnew - 1) < 500 && 0 <= i__1 
				? i__1 : s_rnge(&__global_state->f2c, "ctnams"
				, i__1, "ekqmgr_", (ftnlen)1698)) << 5), 
				__state->cnams + (((i__2 = __state->k - 1) < 
				500 && 0 <= i__2 ? i__2 : s_rnge(&
				__global_state->f2c, "cnams", i__2, "ekqmgr_",
				 (ftnlen)1698)) << 5), (ftnlen)32, (ftnlen)32)
				;
			__state->ctclas[(i__1 = __state->ctnew - 1) < 500 && 
				0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "ctclas", i__1, "ekqmgr_"
				, (ftnlen)1699)] = __state->cdscrs[(i__2 = 
				__state->k * 11 - 11) < 5500 && 0 <= i__2 ? 
				i__2 : s_rnge(&__global_state->f2c, "cdscrs", 
				i__2, "ekqmgr_", (ftnlen)1699)];
			__state->cttyps[(i__1 = __state->ctnew - 1) < 500 && 
				0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "cttyps", i__1, "ekqmgr_"
				, (ftnlen)1700)] = __state->cdscrs[(i__2 = 
				__state->k * 11 - 10) < 5500 && 0 <= i__2 ? 
				i__2 : s_rnge(&__global_state->f2c, "cdscrs", 
				i__2, "ekqmgr_", (ftnlen)1700)];
			__state->ctlens[(i__1 = __state->ctnew - 1) < 500 && 
				0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "ctlens", i__1, "ekqmgr_"
				, (ftnlen)1701)] = __state->cdscrs[(i__2 = 
				__state->k * 11 - 9) < 5500 && 0 <= i__2 ? 
				i__2 : s_rnge(&__global_state->f2c, "cdscrs", 
				i__2, "ekqmgr_", (ftnlen)1701)];
			__state->ctsizs[(i__1 = __state->ctnew - 1) < 500 && 
				0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "ctsizs", i__1, "ekqmgr_"
				, (ftnlen)1702)] = __state->cdscrs[(i__2 = 
				__state->k * 11 - 8) < 5500 && 0 <= i__2 ? 
				i__2 : s_rnge(&__global_state->f2c, "cdscrs", 
				i__2, "ekqmgr_", (ftnlen)1702)];
			__state->ctindx[(i__1 = __state->ctnew - 1) < 500 && 
				0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "ctindx", i__1, "ekqmgr_"
				, (ftnlen)1703)] = __state->cdscrs[(i__2 = 
				__state->k * 11 - 6) < 5500 && 0 <= i__2 ? 
				i__2 : s_rnge(&__global_state->f2c, "cdscrs", 
				i__2, "ekqmgr_", (ftnlen)1703)] != -1;
			__state->ctfixd[(i__1 = __state->ctnew - 1) < 500 && 
				0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "ctfixd", i__1, "ekqmgr_"
				, (ftnlen)1704)] = __state->cdscrs[(i__2 = 
				__state->k * 11 - 8) < 5500 && 0 <= i__2 ? 
				i__2 : s_rnge(&__global_state->f2c, "cdscrs", 
				i__2, "ekqmgr_", (ftnlen)1704)] != -1;
			__state->ctnull[(i__1 = __state->ctnew - 1) < 500 && 
				0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "ctnull", i__1, "ekqmgr_"
				, (ftnlen)1705)] = __state->cdscrs[(i__2 = 
				__state->k * 11 - 4) < 5500 && 0 <= i__2 ? 
				i__2 : s_rnge(&__global_state->f2c, "cdscrs", 
				i__2, "ekqmgr_", (ftnlen)1705)] != -1;

/*                    Store the column descriptor for this column */
/*                    in the descriptor table.  We'll need to */
/*                    allocate a descriptor table entry first. */

			if (lnknfn_(__global_state, __state->dtpool) == 0) {

/*                       No free nodes left in the descriptor table. */

			    s_copy(&__global_state->f2c, __state->state, 
				    "ABORT", (ftnlen)80, (ftnlen)5);
			    s_copy(&__global_state->f2c, __state->problm, 
				    "DESCRIPTOR_TABLE_FULL", (ftnlen)80, (
				    ftnlen)21);
			} else {

/*                       A free node is available.  Link it in at the */
/*                       tail of the descriptor list for the current */
/*                       segment. */

			    lnkan_(__global_state, __state->dtpool, &
				    __state->dtnew);
			    if (__state->stdtpt[(i__1 = __state->stnew - 1) < 
				    200 && 0 <= i__1 ? i__1 : s_rnge(&
				    __global_state->f2c, "stdtpt", i__1, 
				    "ekqmgr_", (ftnlen)1727)] <= 0) {
				__state->stdtpt[(i__1 = __state->stnew - 1) < 
					200 && 0 <= i__1 ? i__1 : s_rnge(&
					__global_state->f2c, "stdtpt", i__1, 
					"ekqmgr_", (ftnlen)1729)] = 
					__state->dtnew;
			    } else {
				lnkilb_(__global_state, &__state->stdtpt[(
					i__1 = __state->stnew - 1) < 200 && 0 
					<= i__1 ? i__1 : s_rnge(&
					__global_state->f2c, "stdtpt", i__1, 
					"ekqmgr_", (ftnlen)1733)], &
					__state->dtnew, __state->dtpool);
			    }

/*                       Fill in the descriptor. */

			    movei_(__global_state, &__state->cdscrs[(i__1 = 
				    __state->k * 11 - 11) < 5500 && 0 <= i__1 
				    ? i__1 : s_rnge(&__global_state->f2c, 
				    "cdscrs", i__1, "ekqmgr_", (ftnlen)1740)],
				     &__state->c__11, &__state->dtdscs[(i__2 =
				     __state->dtnew * 11 - 11) < 110000 && 0 
				    <= i__2 ? i__2 : s_rnge(&
				    __global_state->f2c, "dtdscs", i__2, 
				    "ekqmgr_", (ftnlen)1740)]);
			}
		    }

/*                 We created attribute and descriptor entries for the */
/*                 current column, or we encountered an error. */

		    if (s_cmp(&__global_state->f2c, __state->state, "ABORT", (
			    ftnlen)80, (ftnlen)5) != 0) {

/*                    Consider the next column. */

			++__state->k;
		    }
		}

/*              We created attribute and descriptor entries for every */
/*              column in the current segment, or we encountered an */
/*              error. */

	    }

/*           We've processed the current segment in the new file, or */
/*           else we have an error condition. */

	    if (s_cmp(&__global_state->f2c, __state->state, "ABORT", (ftnlen)
		    80, (ftnlen)5) != 0) {

/*              We're ready to look at the next segment in the new file. */

		s_copy(&__global_state->f2c, __state->state, "NEXT_SEGMENT", (
			ftnlen)80, (ftnlen)12);
	    }
	} else if (s_cmp(&__global_state->f2c, __state->state, "NEXT_SEGMENT",
		 (ftnlen)80, (ftnlen)12) == 0) {
	    if (__state->seg < __state->nseg) {
		++__state->seg;
		s_copy(&__global_state->f2c, __state->state, "SUMMARIZE_SEGM"
			"ENT", (ftnlen)80, (ftnlen)17);
	    } else {

/*              We're done with all of the segments. */

		s_copy(&__global_state->f2c, __state->state, "DONE", (ftnlen)
			80, (ftnlen)4);
	    }
	} else if (s_cmp(&__global_state->f2c, __state->state, "ABORT", (
		ftnlen)80, (ftnlen)5) == 0) {

/*           We must clean up all the data structure additions we made to */
/*           accommodate the new file. */

/*           Basically, we unload the new file.  We defer the call to */
/*           EKCLS until after we've reported the error. */

/*           The file table is first.  The file is at the head of the */
/*           list.  If the file has a successor, that file is now at the */
/*           head of the list. */

	    __state->fthead = lnknxt_(__global_state, &__state->new__, 
		    __state->ftpool);
	    if (__state->fthead < 0) {

/*              There are no files left.  Clean up the whole shebang. */

		lnkini_(__global_state, &__state->c__20, __state->ftpool);
		lnkini_(__global_state, &__state->c__200, __state->stpool);
		lnkini_(__global_state, &__state->c__10000, __state->dtpool);
		lnkini_(__global_state, &__state->c__500, __state->ctpool);
		lnkini_(__global_state, &__state->c__100, __state->tbpool);
		__state->fthead = 0;
		__state->tbhead = 0;
	    } else {

/*              If we arrived here, the file we're unloading is not the */
/*              only loaded file. */

/*              Free the file table entry for the file.  The entry can be */
/*              regarded as a sublist that starts and ends with the Ith */
/*              node, so we can call the `free sublist' routine to get */
/*              rid of it. */

		lnkfsl_(__global_state, &__state->new__, &__state->new__, 
			__state->ftpool);

/*              It's time to clean up the table list, segment table, */
/*              column attribute table, and column descriptor table.  The */
/*              plan is to traverse the table list, and for each member */
/*              of the list, traverse the corresponding segment list, */
/*              removing from the list information about segments and */
/*              columns in the file we're unloading.  If the segment list */
/*              for any table becomes empty, we remove the entry for that */
/*              table from the table list. */

		__state->tbcurr = __state->tbhead;
		while(__state->tbcurr > 0) {

/*                 See whether the current table is in the file we're */
/*                 unloading. */

		    __state->i__ = 1;
		    while(__state->i__ <= __state->tbflsz[(i__1 = 
			    __state->tbcurr - 1) < 100 && 0 <= i__1 ? i__1 : 
			    s_rnge(&__global_state->f2c, "tbflsz", i__1, 
			    "ekqmgr_", (ftnlen)1861)] && ! __state->fnd) {
			if (__state->tbfils[(i__1 = __state->i__ + 
				__state->tbcurr * 20 - 21) < 2000 && 0 <= 
				i__1 ? i__1 : s_rnge(&__global_state->f2c, 
				"tbfils", i__1, "ekqmgr_", (ftnlen)1864)] == *
				handle) {

/*                       This table is affected by unloading the file. */

			    __state->fnd = TRUE_;
			} else {

/*                       Look at the next file handle. */

			    ++__state->i__;
			}
		    }
		    if (__state->fnd) {

/*                    Update the information for the current table to */
/*                    reflect the unloading of the specified EK. */

/*                    Unloading the specified EK removes one handle from */
/*                    the list of file handles associated with this */
/*                    table.  Compress this handle out of the list. */

			i__2 = __state->tbflsz[(i__1 = __state->tbcurr - 1) < 
				100 && 0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "tbflsz", i__1, "ekqmgr_"
				, (ftnlen)1890)] - 1;
			for (__state->j = __state->i__; __state->j <= i__2; 
				++__state->j) {
			    __state->tbfils[(i__1 = __state->j + 
				    __state->tbcurr * 20 - 21) < 2000 && 0 <= 
				    i__1 ? i__1 : s_rnge(&__global_state->f2c,
				     "tbfils", i__1, "ekqmgr_", (ftnlen)1892)]
				     = __state->tbfils[(i__3 = __state->j + 1 
				    + __state->tbcurr * 20 - 21) < 2000 && 0 
				    <= i__3 ? i__3 : s_rnge(&
				    __global_state->f2c, "tbfils", i__3, 
				    "ekqmgr_", (ftnlen)1892)];
			}
			__state->tbflsz[(i__2 = __state->tbcurr - 1) < 100 && 
				0 <= i__2 ? i__2 : s_rnge(&
				__global_state->f2c, "tbflsz", i__2, "ekqmgr_"
				, (ftnlen)1896)] = __state->tbflsz[(i__1 = 
				__state->tbcurr - 1) < 100 && 0 <= i__1 ? 
				i__1 : s_rnge(&__global_state->f2c, "tbflsz", 
				i__1, "ekqmgr_", (ftnlen)1896)] - 1;

/*                    Traverse the segment list for this table, looking */
/*                    for segments in the specified EK. */

			__state->delseg = __state->tbstpt[(i__2 = 
				__state->tbcurr - 1) < 100 && 0 <= i__2 ? 
				i__2 : s_rnge(&__global_state->f2c, "tbstpt", 
				i__2, "ekqmgr_", (ftnlen)1902)];
			while(__state->delseg > 0) {
			    if (__state->sthan[(i__2 = __state->delseg - 1) < 
				    200 && 0 <= i__2 ? i__2 : s_rnge(&
				    __global_state->f2c, "sthan", i__2, "ekq"
				    "mgr_", (ftnlen)1906)] == *handle) {

/*                          This segment is aboard the sinking ship.  Put */
/*                          it out of its misery. */

/*                          First, euthanize its column descriptors. */
/*                          These descriptors are linked together, so we */
/*                          can free all of them in one shot. */

				__state->j = __state->stdtpt[(i__2 = 
					__state->delseg - 1) < 200 && 0 <= 
					i__2 ? i__2 : s_rnge(&
					__global_state->f2c, "stdtpt", i__2, 
					"ekqmgr_", (ftnlen)1915)];
				if (__state->j > 0) {
				    __state->k = lnktl_(__global_state, &
					    __state->j, __state->dtpool);
				    lnkfsl_(__global_state, &__state->j, &
					    __state->k, __state->dtpool);
				}

/*                          Now we can delete the segment table entry */
/*                          itself.  This deletion may necessitate */
/*                          updating the segment list pointer in the */
/*                          parent table's table list entry. */

				if (__state->delseg == __state->tbstpt[(i__2 =
					 __state->tbcurr - 1) < 100 && 0 <= 
					i__2 ? i__2 : s_rnge(&
					__global_state->f2c, "tbstpt", i__2, 
					"ekqmgr_", (ftnlen)1928)]) {
				    __state->tbstpt[(i__2 = __state->tbcurr - 
					    1) < 100 && 0 <= i__2 ? i__2 : 
					    s_rnge(&__global_state->f2c, 
					    "tbstpt", i__2, "ekqmgr_", (
					    ftnlen)1930)] = lnknxt_(
					    __global_state, &__state->delseg, 
					    __state->stpool);
				}
				__state->next = lnknxt_(__global_state, &
					__state->delseg, __state->stpool);
				lnkfsl_(__global_state, &__state->delseg, &
					__state->delseg, __state->stpool);

/*                          The segment we just freed may have been the */
/*                          last one belonging to this table.  We deal */
/*                          with this possibility later, below the end of */
/*                          the current loop. */

				__state->delseg = __state->next;
			    } else {
				__state->delseg = lnknxt_(__global_state, &
					__state->delseg, __state->stpool);
			    }
			}

/*                    We've examined all of the segments in the current */
/*                    table. */

/*                    If the segment list for the current table became */
/*                    empty as a result of our having plundered the */
/*                    segment table, delete the entry for this table from */
/*                    the table list. We do *not* need to concern */
/*                    ourselves with the possibility that this deletion */
/*                    will empty the table list, since we know we're */
/*                    not unloading the last loaded file.  However, we */
/*                    may need to update the head-of-list pointer for the */
/*                    table list. */

			if (__state->tbstpt[(i__2 = __state->tbcurr - 1) < 
				100 && 0 <= i__2 ? i__2 : s_rnge(&
				__global_state->f2c, "tbstpt", i__2, "ekqmgr_"
				, (ftnlen)1969)] <= 0) {

/*                       There are no loaded segments left for this */
/*                       table. */

/*                       Delete the list of column attribute entries for */
/*                       the columns in this table, then delete the */
/*                       table's entry from the table list. */

/*                       The column attribute entries are linked, so we */
/*                       can free them in one shot.  Don't crash if the */
/*                       column attribute list is empty. */

			    __state->j = __state->tbctpt[(i__2 = 
				    __state->tbcurr - 1) < 100 && 0 <= i__2 ? 
				    i__2 : s_rnge(&__global_state->f2c, "tbc"
				    "tpt", i__2, "ekqmgr_", (ftnlen)1982)];
			    if (__state->j > 0) {
				__state->k = lnktl_(__global_state, &
					__state->j, __state->ctpool);
				lnkfsl_(__global_state, &__state->j, &
					__state->k, __state->ctpool);
			    }
			    if (__state->tbcurr == __state->tbhead) {

/*                          The entry for this table is at the head of */
/*                          the table list.  Update the head of the list. */

				__state->tbhead = lnknxt_(__global_state, &
					__state->tbcurr, __state->tbpool);
				__state->next = __state->tbhead;
			    } else {
				__state->next = lnknxt_(__global_state, &
					__state->tbcurr, __state->tbpool);
			    }

/*                       Make the entry for this table go away. */

			    lnkfsl_(__global_state, &__state->tbcurr, &
				    __state->tbcurr, __state->tbpool);

/*                       Look at the next table. */

			    __state->tbcurr = __state->next;
			} else {

/*                       We're done with the current table.  Look at the */
/*                       next one. */

			    __state->tbcurr = lnknxt_(__global_state, &
				    __state->tbcurr, __state->tbpool);
			}

/*                    We've cleaned up the table entry for the current */
/*                    table, if it was necessary to do so. */

		    } else {

/*                    The current table is not affected by unloading this */
/*                    file.  Examine the next table. */

			__state->tbcurr = lnknxt_(__global_state, &
				__state->tbcurr, __state->tbpool);
		    }

/*                 We've processed the current table. */

		}
	    }

/*           We've cleaned up after the aborted partial load. */

/*           Now that the mess has been arranged, tell the user what the */
/*           problem was. */

	    if (s_cmp(&__global_state->f2c, __state->problm, "TABLE_LIST_FULL"
		    , (ftnlen)80, (ftnlen)15) == 0) {
		setmsg_(__global_state, "The EK file # could not be loaded; "
			"the maximum number of distinct tables has already be"
			"en reached.", (ftnlen)98);
		errhan_(__global_state, "#", handle, (ftnlen)1);
		sigerr_(__global_state, "SPICE(EKTABLELISTFULL)", (ftnlen)22);
	    } else if (s_cmp(&__global_state->f2c, __state->problm, "DUPLICA"
		    "TE_COLUMN_NAMES", (ftnlen)80, (ftnlen)22) == 0) {
		setmsg_(__global_state, "The EK file # could not be loaded; "
			"the segment # contains duplicate column names in tab"
			"le #.", (ftnlen)92);
		errhan_(__global_state, "#", handle, (ftnlen)1);
		errint_(__global_state, "#", &__state->seg, (ftnlen)1);
		errch_(__global_state, "#", __state->tabnam, (ftnlen)1, (
			ftnlen)64);
		sigerr_(__global_state, "SPICE(EKCOLNUMMISMATCH)", (ftnlen)23)
			;
	    } else if (s_cmp(&__global_state->f2c, __state->problm, "COLUMN_"
		    "NUMBER_MISMATCH", (ftnlen)80, (ftnlen)22) == 0) {
		setmsg_(__global_state, "The EK file # could not be loaded; "
			"the number of columns (#) in segment # does not matc"
			"h the number of columns (#) in the parent table #.", (
			ftnlen)137);
		errhan_(__global_state, "#", handle, (ftnlen)1);
		errint_(__global_state, "#", &__state->ncols, (ftnlen)1);
		errint_(__global_state, "#", &__state->seg, (ftnlen)1);
		errint_(__global_state, "#", &__state->npcol, (ftnlen)1);
		errch_(__global_state, "#", __state->tabnam, (ftnlen)1, (
			ftnlen)64);
		sigerr_(__global_state, "SPICE(EKCOLNUMMISMATCH)", (ftnlen)23)
			;
	    } else if (s_cmp(&__global_state->f2c, __state->problm, "MISMATC"
		    "HED_COLUMN_ATTRIBUTES", (ftnlen)80, (ftnlen)28) == 0) {
		setmsg_(__global_state, "EK file # contains a column whose a"
			"ttributes conflict with a loaded column.  The offend"
			"ing column name is #; the column is in segment #* of"
			" the file.", (ftnlen)149);
		errhan_(__global_state, "#", handle, (ftnlen)1);
		errch_(__global_state, "#", __state->colnam, (ftnlen)1, (
			ftnlen)32);
		errint_(__global_state, "*", &__state->seg, (ftnlen)1);
		sigerr_(__global_state, "SPICE(BADATTRIBUTES)", (ftnlen)20);
	    } else if (s_cmp(&__global_state->f2c, __state->problm, "DESCRIP"
		    "TOR_TABLE_FULL", (ftnlen)80, (ftnlen)21) == 0) {
		setmsg_(__global_state, "The EK file # could not be loaded; "
			"themaximum allowed number of loaded columns already "
			"been reached.", (ftnlen)100);
		errhan_(__global_state, "#", handle, (ftnlen)1);
		sigerr_(__global_state, "SPICE(COLDESCTABLEFULL)", (ftnlen)23)
			;
	    } else if (s_cmp(&__global_state->f2c, __state->problm, "ATTRIBU"
		    "TE_TABLE_FULL", (ftnlen)80, (ftnlen)20) == 0) {
		setmsg_(__global_state, "The EK file # could not be loaded; "
			"the maximum number of columns havingdistinct attribu"
			"tes has already been reached.", (ftnlen)116);
		errhan_(__global_state, "#", handle, (ftnlen)1);
		sigerr_(__global_state, "SPICE(EKCOLATTRTABLEFULL)", (ftnlen)
			25);
	    } else if (s_cmp(&__global_state->f2c, __state->problm, "MISSING"
		    "_COLUMN", (ftnlen)80, (ftnlen)14) == 0) {
		setmsg_(__global_state, "The EK file # could not be loaded; "
			"the column # in already loaded table # is not presen"
			"t in segment # in the EK file.", (ftnlen)117);
		errhan_(__global_state, "#", handle, (ftnlen)1);
		errch_(__global_state, "#", __state->colnam, (ftnlen)1, (
			ftnlen)32);
		errch_(__global_state, "#", __state->tabnam, (ftnlen)1, (
			ftnlen)64);
		errint_(__global_state, "#", &__state->seg, (ftnlen)1);
		sigerr_(__global_state, "SPICE(EKMISSINGCOLUMN)", (ftnlen)22);
	    } else {
		setmsg_(__global_state, "The EK file # could not be loaded; "
			"the problem \"#\" occurred while attempting to load "
			"the file.  By way, there is a bug in EKLEF if you se"
			"e this message.", (ftnlen)152);
		errhan_(__global_state, "#", handle, (ftnlen)1);
		errch_(__global_state, "#", __state->problm, (ftnlen)1, (
			ftnlen)80);
		sigerr_(__global_state, "SPICE(BUG)", (ftnlen)10);
	    }
	    ekcls_(__global_state, handle);
	    chkout_(__global_state, "EKLEF", (ftnlen)5);
	    return 0;
	}
    }

/*     At this point, we've made the file table, table list, segment */
/*     table, column descriptor table, and column attribute table updates */
/*     necessary to reflect the presence of the new file. */

    chkout_(__global_state, "EKLEF", (ftnlen)5);
    return 0;
/* $Procedure     EKUEF  ( EK, unload event file ) */

L_ekuef:
/* $ Abstract */

/*     Unload an EK file, making its contents inaccessible to the */
/*     EK reader routines, and clearing space in order to allow other */
/*     EK files to be loaded. */

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

/* $ Declarations */

/*     INTEGER               HANDLE */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle of EK file. */

/* $ Detailed_Input */

/*     HANDLE         is a file handle returned by EKLEF. */

/* $ Detailed_Output */

/*     None.  See $Particulars for a description of the effect of this */
/*     routine. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  Unloading a file that is not loaded has no effect. */

/* $ Files */

/*     See the description of the input argument HANDLE in */
/*     $Detailed_Input. */

/* $ Particulars */

/*     This routine removes information about an EK file from the */
/*     EK system, freeing space to increase the number of other EK */
/*     files that can be loaded.  The file is also unloaded from */
/*     the DAS system and closed. */

/* $ Examples */

/*     1)  Load 25 EK files sequentially, unloading the previous file */
/*         before each new file is loaded.  Unloading files prevents */
/*         them from being searched during query execution. */

/*            DO I = 1, 25 */

/*               CALL EKLEF ( EK(I), HANDLE ) */

/*               [Perform queries] */

/*               CALL EKUEF ( HANDLE ) */

/*            END DO */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (NJB) */

/*        Bug fix:   When an already loaded kernel is opened with EKOPR, */
/*        it now has its link count reset to 1 via a call to EKCLS. */

/* -    SPICELIB Version 1.0.1, 07-JUL-1996 (NJB) */

/*        Previous version line was changed from "Beta" to "SPICELIB." */

/* -    SPICELIB Version 1.0.0, 23-OCT-1995 (NJB) */

/* -& */
/* $ Index_Entries */

/*     unload EK file */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "EKUEF", (ftnlen)5);
    }

/*     On the first pass through this routine, initialize the tables, */
/*     if it hasn't been done yet. */

    if (__state->first) {

/*        Initialize the file table pool, segment table pool, column */
/*        descriptor pool, column table pool, and table list pool. */

	lnkini_(__global_state, &__state->c__20, __state->ftpool);
	lnkini_(__global_state, &__state->c__200, __state->stpool);
	lnkini_(__global_state, &__state->c__10000, __state->dtpool);
	lnkini_(__global_state, &__state->c__500, __state->ctpool);
	lnkini_(__global_state, &__state->c__100, __state->tbpool);
	__state->fthead = 0;
	__state->tbhead = 0;
	__state->first = FALSE_;
    }

/*     Check to see whether the named EK has been loaded.  Do nothing */
/*     if not. */

    __state->i__ = __state->fthead;
    __state->fnd = FALSE_;
    while(__state->i__ > 0 && ! __state->fnd) {
	if (*handle == __state->fthan[(i__2 = __state->i__ - 1) < 20 && 0 <= 
		i__2 ? i__2 : s_rnge(&__global_state->f2c, "fthan", i__2, 
		"ekqmgr_", (ftnlen)2342)]) {
	    __state->fnd = TRUE_;
	} else {
	    __state->i__ = lnknxt_(__global_state, &__state->i__, 
		    __state->ftpool);
	}
    }
    if (! __state->fnd) {
	chkout_(__global_state, "EKUEF", (ftnlen)5);
	return 0;
    }

/*     If we got to here, HANDLE points to a loaded EK file.  It's */
/*     time to wipe from the EK tables all trivial fond records */
/*     pertaining to the file in question. */

/*     The file table is first. */

    if (__state->i__ == __state->fthead) {

/*        The file is at the head of the list.  If the file has a */
/*        successor, that file is now at the head of the list. */

	__state->fthead = lnknxt_(__global_state, &__state->i__, 
		__state->ftpool);
	if (__state->fthead < 0) {

/*           There are no files left.  Clean up the whole shebang. */

	    lnkini_(__global_state, &__state->c__20, __state->ftpool);
	    lnkini_(__global_state, &__state->c__200, __state->stpool);
	    lnkini_(__global_state, &__state->c__10000, __state->dtpool);
	    lnkini_(__global_state, &__state->c__500, __state->ctpool);
	    lnkini_(__global_state, &__state->c__100, __state->tbpool);
	    __state->fthead = 0;
	    __state->tbhead = 0;

/*           Close the EK file, to keep the DAS system's bookkeeping */
/*           up to date. */

	    ekcls_(__global_state, handle);
	    chkout_(__global_state, "EKUEF", (ftnlen)5);
	    return 0;
	}
    }

/*     If we arrived here, the file we're unloading is not the only */
/*     loaded file. */

/*     Free the file table entry for the file.  The entry can be */
/*     regarded as a sublist that starts and ends with the Ith node, */
/*     so we can call the `free sublist' routine to get rid of it. */

    lnkfsl_(__global_state, &__state->i__, &__state->i__, __state->ftpool);

/*     It's time to clean up the table list, segment table, column */
/*     attribute table, and column descriptor table.  The plan is */
/*     to traverse the table list, and for each member of the list, */
/*     traverse the corresponding segment list, removing from the list */
/*     information about segments and columns in the file we're */
/*     unloading.  If the segment list for any table becomes empty, we */
/*     remove the entry for that table from the table list. */

    __state->tbcurr = __state->tbhead;
    while(__state->tbcurr > 0) {

/*        See whether the current table is in the file we're unloading. */

	__state->i__ = 1;
	while(__state->i__ <= __state->tbflsz[(i__2 = __state->tbcurr - 1) < 
		100 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "tbfl"
		"sz", i__2, "ekqmgr_", (ftnlen)2422)] && ! __state->fnd) {
	    if (__state->tbfils[(i__2 = __state->i__ + __state->tbcurr * 20 - 
		    21) < 2000 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "tbfils", i__2, "ekqmgr_", (ftnlen)
		    2424)] == *handle) {

/*              This table is affected by unloading the file. */

		__state->fnd = TRUE_;
	    } else {

/*              Look at the next file handle. */

		++__state->i__;
	    }
	}
	if (__state->fnd) {

/*           Update the information for the current table to reflect */
/*           the unloading of the specified EK. */

/*           Unloading the specified EK removes one handle from the */
/*           list of file handles associated with this table.  Compress */
/*           this handle out of the list. */

	    i__1 = __state->tbflsz[(i__2 = __state->tbcurr - 1) < 100 && 0 <= 
		    i__2 ? i__2 : s_rnge(&__global_state->f2c, "tbflsz", i__2,
		     "ekqmgr_", (ftnlen)2450)] - 1;
	    for (__state->j = __state->i__; __state->j <= i__1; ++__state->j) 
		    {
		__state->tbfils[(i__2 = __state->j + __state->tbcurr * 20 - 
			21) < 2000 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "tbfils", i__2, "ekqmgr_", (
			ftnlen)2452)] = __state->tbfils[(i__3 = __state->j + 
			1 + __state->tbcurr * 20 - 21) < 2000 && 0 <= i__3 ? 
			i__3 : s_rnge(&__global_state->f2c, "tbfils", i__3, 
			"ekqmgr_", (ftnlen)2452)];
	    }
	    __state->tbflsz[(i__1 = __state->tbcurr - 1) < 100 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "tbflsz", i__1, "ekq"
		    "mgr_", (ftnlen)2456)] = __state->tbflsz[(i__2 = 
		    __state->tbcurr - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "tbflsz", i__2, "ekqmgr_", (ftnlen)
		    2456)] - 1;

/*           Traverse the segment list for this table, looking */
/*           for segments in the specified EK. */

	    __state->seg = __state->tbstpt[(i__1 = __state->tbcurr - 1) < 100 
		    && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "tbst"
		    "pt", i__1, "ekqmgr_", (ftnlen)2462)];
	    while(__state->seg > 0) {
		if (__state->sthan[(i__1 = __state->seg - 1) < 200 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "sthan", 
			i__1, "ekqmgr_", (ftnlen)2466)] == *handle) {

/*                 This segment is aboard the sinking ship.  Put it */
/*                 out of its misery. */

/*                 First, euthanize the segment's column descriptors. */
/*                 These descriptors are linked together, so we can free */
/*                 all of them in one shot.  Don't crash if the column */
/*                 descriptor list is empty. */

		    __state->j = __state->stdtpt[(i__1 = __state->seg - 1) < 
			    200 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "stdtpt", i__1, "ekqmgr_", (
			    ftnlen)2476)];
		    if (__state->j > 0) {
			__state->k = lnktl_(__global_state, &__state->j, 
				__state->dtpool);
			lnkfsl_(__global_state, &__state->j, &__state->k, 
				__state->dtpool);
		    }

/*                 Now we can delete the segment table entry itself. */
/*                 This deletion may necessitate updating the segment */
/*                 list pointer in the parent table's table list entry. */

		    if (__state->seg == __state->tbstpt[(i__1 = 
			    __state->tbcurr - 1) < 100 && 0 <= i__1 ? i__1 : 
			    s_rnge(&__global_state->f2c, "tbstpt", i__1, 
			    "ekqmgr_", (ftnlen)2488)]) {
			__state->tbstpt[(i__1 = __state->tbcurr - 1) < 100 && 
				0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "tbstpt", i__1, "ekqmgr_"
				, (ftnlen)2490)] = lnknxt_(__global_state, &
				__state->seg, __state->stpool);
		    }
		    __state->next = lnknxt_(__global_state, &__state->seg, 
			    __state->stpool);
		    lnkfsl_(__global_state, &__state->seg, &__state->seg, 
			    __state->stpool);
		    __state->seg = __state->next;
		} else {
		    __state->seg = lnknxt_(__global_state, &__state->seg, 
			    __state->stpool);
		}
	    }

/*           We've examined all of the segments in the current table. */

/*           If the segment list for the current table became empty */
/*           as a result of our having plundered the segment table, */
/*           delete the entry for this table from the table list.  We do */
/*           *not* need to concern ourselves with the possibility that */
/*           this deletion will empty the table list, since we know we're */
/*           not unloading the last loaded file.  However, we may need to */
/*           update the head-of-list pointer for the table list. */

	    if (__state->tbstpt[(i__1 = __state->tbcurr - 1) < 100 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "tbstpt", i__1,
		     "ekqmgr_", (ftnlen)2520)] <= 0) {

/*              There are no loaded segments left for this table. */

/*              Delete the list of column attribute entries for the */
/*              columns in this table, then delete the table's entry from */
/*              the table list. */

/*              The column attribute entries are linked, so we can free */
/*              them in one shot. */

		__state->j = __state->tbctpt[(i__1 = __state->tbcurr - 1) < 
			100 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c,
			 "tbctpt", i__1, "ekqmgr_", (ftnlen)2531)];
		if (__state->j > 0) {
		    __state->k = lnktl_(__global_state, &__state->j, 
			    __state->ctpool);
		    lnkfsl_(__global_state, &__state->j, &__state->k, 
			    __state->ctpool);
		}
		if (__state->tbcurr == __state->tbhead) {

/*                 The entry for this table is at the head of the */
/*                 table list.  Update the head of the list. */

		    __state->tbhead = lnknxt_(__global_state, &
			    __state->tbcurr, __state->tbpool);
		    __state->next = __state->tbhead;
		} else {
		    __state->next = lnknxt_(__global_state, &__state->tbcurr, 
			    __state->tbpool);
		}

/*              Make the entry for this table go away. */

		lnkfsl_(__global_state, &__state->tbcurr, &__state->tbcurr, 
			__state->tbpool);

/*              The successor of the current node is the next node to */
/*              examine. */

		__state->tbcurr = __state->next;
	    } else {

/*              We're done with the current table.  Look at the next one. */

		__state->tbcurr = lnknxt_(__global_state, &__state->tbcurr, 
			__state->tbpool);
	    }

/*           We've cleaned up the table entry for the current table, */
/*           if it was necessary to do so. */

	} else {

/*           The current table is not affected by unloading this file. */
/*           Examine the next table. */

	    __state->tbcurr = lnknxt_(__global_state, &__state->tbcurr, 
		    __state->tbpool);
	}

/*        We've processed the current table. */

    }

/*     Don't forget to unload the EK file from the DAS system. */

    ekcls_(__global_state, handle);
    chkout_(__global_state, "EKUEF", (ftnlen)5);
    return 0;
/* $Procedure     EKNTAB  ( EK, return number of loaded tables ) */

L_ekntab:
/* $ Abstract */

/*     Return the number of loaded EK tables. */

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

/* $ Declarations */

/*     INTEGER               N */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     N          O   Number of loaded tables. */

/* $ Detailed_Input */

/*     None. */

/* $ Detailed_Output */

/*     N              is the number of loaded tables.  The count refers */
/*                    to the number of logical tables; if multiple */
/*                    segments contain data for the same table, these */
/*                    segments collectively contribute only one table */
/*                    to the count. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     None. */

/* $ Files */

/*     The returned count is based on the currently loaded EK files. */
/*     These files must be loaded via the entry point EKLEF. */

/* $ Particulars */

/*     This routine is a utility that provides the caller with the */
/*     number of loaded tables.  Callers of EKTNAM can use this count */
/*     as the upper bound on set of table indices when looking up table */
/*     names. */

/* $ Examples */

/*     1)  Suppose we have the following list of EK files and tables */
/*         contained in those files: */

/*            File name        Table name */
/*            ---------        ---------- */

/*            FILE_1.EK        TABLE_1 */
/*                             TABLE_2 */

/*            FILE_2.EK        TABLE_1 */
/*                             TABLE_3 */

/*            FILE_3.EK        TABLE_2 */
/*                             TABLE_3 */
/*                             TABLE_4 */


/*         Then after loading these files, the call */

/*            CALL EKNTAB ( N ) */

/*         returns the value N = 4. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (NJB) */

/*        Bug fix:   When an already loaded kernel is opened with EKOPR, */
/*        it now has its link count reset to 1 via a call to EKCLS. */

/* -    SPICELIB Version 1.0.1, 07-JUL-1996 (NJB) */

/*        Previous version line was changed from "Beta" to "SPICELIB." */

/* -    SPICELIB Version 1.0.0, 23-OCT-1995 (NJB) */

/* -& */
/* $ Index_Entries */

/*     return number of loaded tables */

/* -& */
    if (__state->first) {

/*        Initialize the file table pool, segment table pool, column */
/*        descriptor pool, column table pool, and table list pool. */

	lnkini_(__global_state, &__state->c__20, __state->ftpool);
	lnkini_(__global_state, &__state->c__200, __state->stpool);
	lnkini_(__global_state, &__state->c__10000, __state->dtpool);
	lnkini_(__global_state, &__state->c__500, __state->ctpool);
	lnkini_(__global_state, &__state->c__100, __state->tbpool);
	__state->fthead = 0;
	__state->tbhead = 0;
	__state->first = FALSE_;
    }

/*     Return the number of loaded tables. */

    *n = 100 - lnknfn_(__global_state, __state->tbpool);
    return 0;
/* $Procedure     EKTNAM  ( EK, return name of loaded table ) */

L_ektnam:
/* $ Abstract */

/*     Return the name of a specified, loaded table. */

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

/* $ Declarations */

/*     INTEGER               N */
/*     CHARACTER*(*)         TABLE */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     N          I   Index of table. */
/*     TABLE      O   Name of table. */

/* $ Detailed_Input */

/*     N              is the index of the table whose name is desired. */
/*                    The value of N ranges from 1 to the number of */
/*                    loaded tables, which count may be obtained from */
/*                    EKNTAB. */

/* $ Detailed_Output */

/*     TABLE          is the name of the Nth loaded table. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If this routine is called when no files are loaded, the */
/*         error SPICE(NOLOADEDFILES) is signaled. */

/*     2)  If the input N is out of range, the error SPICE(INVALDINDEX) */
/*         is signaled. */

/* $ Files */

/*     The returned name is based on the currently loaded EK files. */

/* $ Particulars */

/*     This routine is a utility that provides the caller with the */
/*     name of a specified loaded table.  The index of a table with */
/*     a given name depends on the kernels loaded and possibly on */
/*     the order in which the files have been loaded. */

/* $ Examples */

/*     1)  Dump the names of the loaded tables. */

/*         CALL EKNTAB ( N ) */

/*         DO I = 1, N */
/*            CALL EKTNAM ( I, TABLE ) */
/*            WRITE (*,*) TABLE */
/*         END DO */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (NJB) */

/*        Bug fix:   When an already loaded kernel is opened with EKOPR, */
/*        it now has its link count reset to 1 via a call to EKCLS. */

/* -    SPICELIB Version 1.0.1, 07-JUL-1996 (NJB) */

/*        Previous version line was changed from "Beta" to "SPICELIB." */

/* -    SPICELIB Version 1.0.0, 23-OCT-1995 (NJB) */

/* -& */
/* $ Index_Entries */

/*     return name of a loaded table */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "EKTNAM", (ftnlen)6);
    }
    if (__state->first) {

/*        Initialize the file table pool, segment table pool, column */
/*        descriptor pool, column table pool, and table list pool. */

	lnkini_(__global_state, &__state->c__20, __state->ftpool);
	lnkini_(__global_state, &__state->c__200, __state->stpool);
	lnkini_(__global_state, &__state->c__10000, __state->dtpool);
	lnkini_(__global_state, &__state->c__500, __state->ctpool);
	lnkini_(__global_state, &__state->c__100, __state->tbpool);
	__state->fthead = 0;
	__state->tbhead = 0;
	__state->first = FALSE_;
    }

/*     There nothing to fetch if no files are loaded.  A sure */
/*     symptom of this problem is that the file list is empty. */

    if (__state->fthead <= 0) {
	setmsg_(__global_state, "No E-kernels are currently loaded.", (ftnlen)
		34);
	sigerr_(__global_state, "SPICE(NOLOADEDFILES)", (ftnlen)20);
	chkout_(__global_state, "EKTNAM", (ftnlen)6);
	return 0;
    }
    __state->tbcurr = __state->tbhead;
    __state->fnd = FALSE_;
    __state->i__ = 0;
    while(__state->tbcurr > 0 && ! __state->fnd) {
	++__state->i__;
	if (__state->i__ == *n) {
	    __state->fnd = TRUE_;
	    s_copy(&__global_state->f2c, table, __state->tbnams + (((i__1 = 
		    __state->tbcurr - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "tbnams", i__1, "ekqmgr_", (ftnlen)
		    2956)) << 6), table_len, (ftnlen)64);
	} else {
	    __state->tbcurr = lnknxt_(__global_state, &__state->tbcurr, 
		    __state->tbpool);
	}
    }
    if (! __state->fnd) {
	setmsg_(__global_state, "The index # does not correspond to a loaded"
		" table.", (ftnlen)50);
	errint_(__global_state, "#", n, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDINDEX)", (ftnlen)19);
    }
    chkout_(__global_state, "EKTNAM", (ftnlen)6);
    return 0;
/* $Procedure     EKCCNT  ( EK, column count ) */

L_ekccnt:
/* $ Abstract */

/*     Return the number of distinct columns in a specified, currently */
/*     loaded table */

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

/*     CHARACTER*(*)         TABLE */
/*     INTEGER               CCOUNT */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     TABLE      I   Name of table. */
/*     CCOUNT     O   Count of distinct, currently loaded columns. */

/* $ Detailed_Input */

/*     TABLE          is the name of a currently loaded table.  Case */
/*                    is not significant in the table name. */

/* $ Detailed_Output */

/*     CCOUNT         is the number of distinct columns in TABLE. */
/*                    Columns that have the same name but belong to */
/*                    different segments that are considered to be */
/*                    portions of the same column, if the segments */
/*                    containing those columns belong to TABLE. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the specified table is not loaded, the error */
/*         SPICE(TABLENOTLOADED) is signaled. */

/* $ Files */

/*     See the header of EKQMGR for a description of files used */
/*     by this routine. */

/* $ Particulars */

/*     This routine is a utility intended for use in conjunction with */
/*     the entry point EKCII.  These routines can be used to find the */
/*     names and attributes of the columns that are currently loaded. */

/* $ Examples */

/*     1)  Dump the names and attributes of the columns in each loaded */
/*         table.  EKCCNT is used to obtain column counts. */

/*            C */
/*            C     Get the number of loaded tables. */
/*            C */
/*                  CALL EKNTAB ( NTAB ) */

/*                  DO TAB = 1, NTAB */
/*            C */
/*            C        Get the name of the current table, and look up */
/*            C        the column count for this table. */
/*            C */
/*                     CALL EKTNAM ( TAB,    TABNAM ) */
/*                     CALL EKCCNT ( TABNAM, NCOLS  ) */

/*                     WRITE (*,*) 'TABLE = ', TABNAM */
/*                     WRITE (*,*) ' ' */

/*            C */
/*            C        For each column in the current table, look up the */
/*            C        column's attributes.  The attribute block */
/*            C        index parameters are defined in the include file */
/*            C        ekattdsc.inc. */
/*            C */
/*                     DO I = 1, NCOLS */

/*                        CALL EKCII ( TABNAM, I, COLNAM, ATTDSC ) */

/*                        WRITE (*,*) 'COLUMN = ', COLNAM */

/*            C */
/*            C           Write out the current column's data type. */
/*            C */
/*                        IF ( ATTDSC(ATTTYP) .EQ. CHR ) THEN */
/*                           WRITE (*,*) 'TYPE   =  CHR' */

/*                           IF ( ATTDSC(ATTLEN) .EQ. -1 ) THEN */
/*                              WRITE (*,*) 'STRING LENGTH = VARIABLE.' */
/*                           ELSE */
/*                              WRITE (*,*) 'STRING LENGTH = ', */
/*                 .                         ATTDSC(ATTLEN) */
/*                           END IF */

/*                        ELSE IF ( ATTDSC(ATTTYP) .EQ. DP ) THEN */
/*                           WRITE (*,*) 'TYPE   =  DP' */

/*                        ELSE IF ( ATTDSC(ATTTYP) .EQ. INT ) THEN */
/*                           WRITE (*,*) 'TYPE   =  INT' */

/*                        ELSE */
/*                           WRITE (*,*) 'TYPE   =  TIME' */
/*                        END IF */

/*            C */
/*            C           Write out the current column's entry size. */
/*            C */
/*                        WRITE (*,*) 'SIZE   = ', ATTDSC(ATTSIZ) */

/*            C */
/*            C           Indicate whether the current column is indexed. */
/*            C */
/*                        IF ( ATTDSC(ATTIDX) .EQ. -1 ) THEN */
/*                           WRITE (*,*) 'NOT INDEXED' */
/*                        ELSE */
/*                           WRITE (*,*) 'INDEXED' */
/*                        END IF */

/*            C */
/*            C           Indicate whether the current column allows */
/*            C           null values. */
/*            C */
/*                        IF ( ATTDSC(ATTNFL) .EQ. -1 ) THEN */
/*                           WRITE (*,*) 'NULL VALUES NOT ALLOWED' */
/*                        ELSE */
/*                           WRITE (*,*) 'NULL VALUES ALLOWED' */
/*                        END IF */

/*                     END DO */

/*                  END DO */


/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (NJB) */

/*        Bug fix:   When an already loaded kernel is opened with EKOPR, */
/*        it now has its link count reset to 1 via a call to EKCLS. */

/* -    SPICELIB Version 1.0.1, 07-JUL-1996 (NJB) */

/*        Misspelling of "conjunction" was fixed. */

/* -    SPICELIB Version 1.0.0, 23-OCT-1995 (NJB) */


/* -& */
/* $ Index_Entries */

/*     return the number of loaded EK columns */
/*     return the count of loaded EK columns */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "EKCCNT", (ftnlen)6);
    }

/*     On the first pass through this routine, initialize the tables, */
/*     if it hasn't been done yet. */

    if (__state->first) {

/*        Initialize the file table pool, segment table pool, column */
/*        descriptor pool, column table pool, and table list pool. */

	lnkini_(__global_state, &__state->c__20, __state->ftpool);
	lnkini_(__global_state, &__state->c__200, __state->stpool);
	lnkini_(__global_state, &__state->c__10000, __state->dtpool);
	lnkini_(__global_state, &__state->c__500, __state->ctpool);
	lnkini_(__global_state, &__state->c__100, __state->tbpool);
	__state->fthead = 0;
	__state->tbhead = 0;
	__state->first = FALSE_;
    }

/*     Find the table.  If there's no match, the number of loaded columns */
/*     is zero. */

    __state->tbcurr = __state->tbhead;
    __state->fnd = FALSE_;
    while(__state->tbcurr > 0 && ! __state->fnd) {
	if (eqstr_(__global_state, table, __state->tbnams + (((i__1 = 
		__state->tbcurr - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "tbnams", i__1, "ekqmgr_", (ftnlen)3233))
		 << 6), table_len, (ftnlen)64)) {
	    __state->fnd = TRUE_;
	} else {
	    __state->tbcurr = lnknxt_(__global_state, &__state->tbcurr, 
		    __state->tbpool);
	}
    }
    if (! __state->fnd) {
	*ccount = 0;
	setmsg_(__global_state, "The table # is not currently loaded.", (
		ftnlen)36);
	errch_(__global_state, "#", table, (ftnlen)1, table_len);
	sigerr_(__global_state, "SPICE(TABLENOTLOADED)", (ftnlen)21);
	chkout_(__global_state, "EKCCNT", (ftnlen)6);
	return 0;
    } else {

/*        Count the columns in the attribute table for the current table. */

	*ccount = 0;
	__state->col = __state->tbctpt[(i__1 = __state->tbcurr - 1) < 100 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "tbctpt", 
		i__1, "ekqmgr_", (ftnlen)3256)];
	while(__state->col > 0) {
	    ++(*ccount);
	    __state->col = lnknxt_(__global_state, &__state->col, 
		    __state->ctpool);
	}
    }
    chkout_(__global_state, "EKCCNT", (ftnlen)6);
    return 0;
/* $Procedure     EKCII  ( EK, column info by index ) */

L_ekcii:
/* $ Abstract */

/*     Return attribute information about a column belonging to a loaded */
/*     EK table, specifying the column by table and index. */

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

/*     CHARACTER*(*)         TABLE */
/*     INTEGER               CINDEX */
/*     CHARACTER*(*)         COLUMN */
/*     INTEGER               ATTDSC ( ADSCSZ ) */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     TABLE      I   Name of table containing column. */
/*     CINDEX     I   Index of column whose attributes are to be found. */
/*     COLUMN     O   Name of column. */
/*     ATTDSC     O   Column attribute descriptor. */

/* $ Detailed_Input */

/*     TABLE          is the name of a loaded EK table.  Case is not */
/*                    significant. */

/*     CINDEX         is the index, within TABLE's column attribute */
/*                    table, of the column whose attributes are to be */
/*                    found.  The indices of the column table entries */
/*                    range from 1 to CCOUNT, where CCOUNT is the value */
/*                    returned by the entry point EKCCNT. */

/* $ Detailed_Output */

/*     COLUMN         is the name of the specified column. */

/*     ATTDSC         is a column attribute descriptor.  ATTDSC is an */
/*                    integer array containing descriptive information */
/*                    that applies uniformly to all loaded columns */
/*                    having the name COLUMN.  The following parameter */
/*                    values occur in ATTDSC: */

/*                       IFALSE:  -1 */
/*                       ITRUE:    1 */
/*                       CHR:      1 */
/*                       DP:       2 */
/*                       INT:      3 */
/*                       TIME:     4 */

/*                    The meanings of the elements of ATTDSC are given */
/*                    below.  The indices of the elements are */
/*                    parameterized; the parameter values are defined */
/*                    in the include file ekattdsc.inc. */

/*                       ATTDSC(ATTCLS):   Column class code */

/*                       ATTDSC(ATTTYP):   Data type code---CHR, DP, INT, */
/*                                         or TIME */

/*                       ATTDSC(ATTLEN):   String length; applies to CHR */
/*                                         type.  Value is IFALSE for */
/*                                         variable-length strings. */

/*                       ATTDSC(ATTSIZ):   Column entry size; value is */
/*                                         IFALSE for variable-size */
/*                                         columns.  Here `size' refers */
/*                                         to the number of array */
/*                                         elements in a column entry. */

/*                       ATTDSC(ATTIDX):   Index flag; value is ITRUE if */
/*                                         column is indexed, IFALSE */
/*                                         otherwise. */

/*                       ATTDSC(ATTNFL):   Null flag; value is ITRUE if */
/*                                         column may contain null */
/*                                         values, IFALSE otherwise. */

/* $ Parameters */

/*     ADSCSZ         is the size of column attribute descriptor. */
/*                    (Defined in ekattdsc.inc.) */

/* $ Exceptions */

/*     1)  If the specified table is not loaded, the error */
/*         SPICE(TABLENOTLOADED) is signaled. */

/*     2)  If the input argument CINDEX is less than one or greater */
/*         than the number of columns in TABLE, the error */
/*         SPICE(INVALIDINDEX) is signaled. */

/* $ Files */

/*     See the header of EKQMGR for a description of files used */
/*     by this routine. */

/* $ Particulars */

/*     This routine is a utility that allows a calling routine to */
/*     determine the attributes of the currently loaded columns. */

/* $ Examples */

/*     1)  Dump the names and attributes of the columns in each loaded */
/*         table.  EKCII is used to obtain column attributes. */

/*            C */
/*            C     Get the number of loaded tables. */
/*            C */
/*                  CALL EKNTAB ( NTAB ) */

/*                  DO TAB = 1, NTAB */
/*            C */
/*            C        Get the name of the current table, and look up */
/*            C        the column count for this table. */
/*            C */
/*                     CALL EKTNAM ( TAB,    TABNAM ) */
/*                     CALL EKCCNT ( TABNAM, NCOLS  ) */

/*                     WRITE (*,*) 'TABLE = ', TABNAM */
/*                     WRITE (*,*) ' ' */

/*            C */
/*            C        For each column in the current table, look up the */
/*            C        column's attributes.  The attribute block */
/*            C        index parameters are defined in the include file */
/*            C        ekattdsc.inc. */
/*            C */
/*                     DO I = 1, NCOLS */

/*                        CALL EKCII ( TABNAM, I, COLNAM, ATTDSC ) */

/*                        WRITE (*,*) 'COLUMN = ', COLNAM */

/*            C */
/*            C           Write out the current column's data type. */
/*            C */
/*                        IF ( ATTDSC(ATTTYP) .EQ. CHR ) THEN */
/*                           WRITE (*,*) 'TYPE   =  CHR' */

/*                           IF ( ATTDSC(ATTLEN) .EQ. -1 ) THEN */
/*                              WRITE (*,*) 'STRING LENGTH = VARIABLE.' */
/*                           ELSE */
/*                              WRITE (*,*) 'STRING LENGTH = ', */
/*                 .                         ATTDSC(ATTLEN) */
/*                           END IF */

/*                        ELSE IF ( ATTDSC(ATTTYP) .EQ. DP ) THEN */
/*                           WRITE (*,*) 'TYPE   =  DP' */

/*                        ELSE IF ( ATTDSC(ATTTYP) .EQ. INT ) THEN */
/*                           WRITE (*,*) 'TYPE   =  INT' */

/*                        ELSE */
/*                           WRITE (*,*) 'TYPE   =  TIME' */
/*                        END IF */

/*            C */
/*            C           Write out the current column's entry size. */
/*            C */
/*                        WRITE (*,*) 'SIZE   = ', ATTDSC(ATTSIZ) */

/*            C */
/*            C           Indicate whether the current column is indexed. */
/*            C */
/*                        IF ( ATTDSC(ATTIDX) .EQ. -1 ) THEN */
/*                           WRITE (*,*) 'NOT INDEXED' */
/*                        ELSE */
/*                           WRITE (*,*) 'INDEXED' */
/*                        END IF */

/*            C */
/*            C           Indicate whether the current column allows */
/*            C           null values. */
/*            C */
/*                        IF ( ATTDSC(ATTNFL) .EQ. -1 ) THEN */
/*                           WRITE (*,*) 'NULL VALUES NOT ALLOWED' */
/*                        ELSE */
/*                           WRITE (*,*) 'NULL VALUES ALLOWED' */
/*                        END IF */

/*                     END DO */

/*                  END DO */


/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     B.V. Semenov   (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.1, 10-FEB-2014 (BVS) */

/*        Added description of ADSCSZ to the Parameters section of the */
/*        header. */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (NJB) */

/*        Bug fix:   When an already loaded kernel is opened with EKOPR, */
/*        it now has its link count reset to 1 via a call to EKCLS. */

/* -    SPICELIB Version 1.0.1, 07-JUL-1996 (NJB) */

/*        Previous version line was changed from "Beta" to "SPICELIB." */

/* -    SPICELIB Version 1.0.0, 23-OCT-1995 (NJB) */

/* -& */
/* $ Index_Entries */

/*     return information on loaded EK column specified by index */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "EKCII", (ftnlen)5);
    }

/*     On the first pass through this routine, initialize the tables, */
/*     if it hasn't been done yet. */

    if (__state->first) {

/*        Initialize the file table pool, segment table pool, column */
/*        descriptor pool, column table pool, and table list pool. */

	lnkini_(__global_state, &__state->c__20, __state->ftpool);
	lnkini_(__global_state, &__state->c__200, __state->stpool);
	lnkini_(__global_state, &__state->c__10000, __state->dtpool);
	lnkini_(__global_state, &__state->c__500, __state->ctpool);
	lnkini_(__global_state, &__state->c__100, __state->tbpool);
	__state->fthead = 0;
	__state->tbhead = 0;
	__state->first = FALSE_;
    }

/*     Find the table.  If there's no match, the number of loaded columns */
/*     is zero. */

    __state->tbcurr = __state->tbhead;
    __state->fnd = FALSE_;
    while(__state->tbcurr > 0 && ! __state->fnd) {
	if (eqstr_(__global_state, table, __state->tbnams + (((i__1 = 
		__state->tbcurr - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "tbnams", i__1, "ekqmgr_", (ftnlen)3580))
		 << 6), table_len, (ftnlen)64)) {
	    __state->fnd = TRUE_;
	} else {
	    __state->tbcurr = lnknxt_(__global_state, &__state->tbcurr, 
		    __state->tbpool);
	}
    }
    if (! __state->fnd) {
	setmsg_(__global_state, "The table # is not currently loaded.", (
		ftnlen)36);
	errch_(__global_state, "#", table, (ftnlen)1, table_len);
	sigerr_(__global_state, "SPICE(TABLENOTLOADED)", (ftnlen)21);
	chkout_(__global_state, "EKCII", (ftnlen)5);
	return 0;
    }

/*     Locate the named column in the column attribute table. */

    __state->i__ = 0;
    __state->col = __state->tbctpt[(i__1 = __state->tbcurr - 1) < 100 && 0 <= 
	    i__1 ? i__1 : s_rnge(&__global_state->f2c, "tbctpt", i__1, "ekqm"
	    "gr_", (ftnlen)3604)];
    while(__state->col > 0 && __state->i__ < *cindex) {
	++__state->i__;
	if (__state->i__ == *cindex) {

/*           We've found the column.  Set the output arguments using */
/*           its attributes. */

	    s_copy(&__global_state->f2c, column, __state->ctnams + (((i__1 = 
		    __state->col - 1) < 500 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "ctnams", i__1, "ekqmgr_", (ftnlen)
		    3615)) << 5), column_len, (ftnlen)32);
	    attdsc[0] = __state->ctclas[(i__1 = __state->col - 1) < 500 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ctclas", 
		    i__1, "ekqmgr_", (ftnlen)3617)];
	    attdsc[1] = __state->cttyps[(i__1 = __state->col - 1) < 500 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "cttyps", 
		    i__1, "ekqmgr_", (ftnlen)3618)];
	    attdsc[2] = __state->ctlens[(i__1 = __state->col - 1) < 500 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ctlens", 
		    i__1, "ekqmgr_", (ftnlen)3619)];
	    attdsc[3] = __state->ctsizs[(i__1 = __state->col - 1) < 500 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ctsizs", 
		    i__1, "ekqmgr_", (ftnlen)3620)];
	    if (__state->ctindx[(i__1 = __state->col - 1) < 500 && 0 <= i__1 ?
		     i__1 : s_rnge(&__global_state->f2c, "ctindx", i__1, 
		    "ekqmgr_", (ftnlen)3622)]) {
		attdsc[4] = 1;
	    } else {
		attdsc[4] = -1;
	    }
	    if (__state->ctnull[(i__1 = __state->col - 1) < 500 && 0 <= i__1 ?
		     i__1 : s_rnge(&__global_state->f2c, "ctnull", i__1, 
		    "ekqmgr_", (ftnlen)3628)]) {
		attdsc[5] = 1;
	    } else {
		attdsc[5] = -1;
	    }
	    chkout_(__global_state, "EKCII", (ftnlen)5);
	    return 0;
	} else {
	    __state->col = lnknxt_(__global_state, &__state->col, 
		    __state->ctpool);
	}
    }

/*     We end up here if we ran out of columns before finding the */
/*     CINDEXth one, or if CINDEX was non-positive. */

    setmsg_(__global_state, "Column indices for table # range from # to #; r"
	    "equested index was #.", (ftnlen)68);
    errch_(__global_state, "#", __state->tabnam, (ftnlen)1, (ftnlen)64);
    i__1 = max(1,__state->i__);
    errint_(__global_state, "#", &i__1, (ftnlen)1);
    errint_(__global_state, "#", &__state->i__, (ftnlen)1);
    errint_(__global_state, "#", cindex, (ftnlen)1);
    sigerr_(__global_state, "SPICE(INVALIDINDEX)", (ftnlen)19);
    chkout_(__global_state, "EKCII", (ftnlen)5);
    return 0;
/* $Procedure     EKSRCH  ( EK, search for events ) */

L_eksrch:
/* $ Abstract */

/*     Search for EK events matching a specified set of constraints. */

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
/*     EVENT */
/*     FILES */
/*     SEARCH */

/* $ Declarations */

/*     INTEGER               EQRYI  ( LBCELL : * ) */
/*     CHARACTER*(*)         EQRYC */
/*     DOUBLE PRECISION      EQRYD  ( * ) */
/*     INTEGER               NMROWS */
/*     LOGICAL               SEMERR */
/*     CHARACTER*(*)         ERRMSG */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     EQRYI      I   Integer component of encoded query. */
/*     EQRYC      I   Character component of encoded query. */
/*     EQRYD      I   D.p. component of encoded query. */
/*     NMROWS     O   Number of rows matching query constraints. */
/*     SEMERR     O   Flag indicating whether semantic error occurred. */
/*     ERRMSG     O   Message describing semantic error, if any. */

/* $ Detailed_Input */

/*     EQRYI, */
/*     EQRYC, */
/*     EQRYD          are, respectively, the integer, character, and */
/*                    double precision portions of an encoded query. */
/*                    The query must have been parsed and must have */
/*                    its table and column names resolved.  Time values */
/*                    must have been resolved.  The query is expected */
/*                    to be semantically correct. */

/* $ Detailed_Output */

/*     NMROWS         is the number of rows matching the input query */
/*                    constraints. */

/*     SEMERR         is a logical flag indicating whether a semantic */
/*                    error was detected while attempting to respond to */
/*                    the input query. */

/*     ERRMSG         is a descriptive error message that is set if a */
/*                    semantic error is detected.  Otherwise, ERRMSG */
/*                    is returned blank. */

/*     See $Particulars for a description of the effect of this */
/*     routine. */

/* $ Parameters */

/*     LBCELL         is the SPICELIB cell lower bound. */

/* $ Exceptions */

/*     1)  If this routine is called when no files are loaded, the */
/*         error SPICE(NOLOADEDFILES) is signaled. */

/*     2)  If the structure of the input query is invalid, this routine */
/*         may fail in mysterious ways. */

/* $ Files */

/*     See the header of EKQMGR for a description of files used */
/*     by this routine. */

/* $ Particulars */

/*     NAIF Toolkit-based applications will rarely need to call this */
/*     routine directly; the high-level routine EKFIND should normally */
/*     be used to query the EK system. */

/*     Because the structure of encoded queries is not part of the */
/*     SPICELIB user interface, we strongly recommend that users' */
/*     applications not call this routine directly. */

/* $ Examples */

/*     See the header of the umbrella subroutine EKQMGR for a */
/*     comprehensive example of the use of EKQMGR's entry points. */

/* $ Restrictions */

/*     1) This routine should normally not be called directly from */
/*        users' applications. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     B.V. Semenov   (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.1, 10-FEB-2014 (BVS) */

/*        Added description of LBCELL to the Parameters section of the */
/*        header. */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (NJB) */

/*        Bug fix:   When an already loaded kernel is opened with EKOPR, */
/*        it now has its link count reset to 1 via a call to EKCLS. */

/* -    SPICELIB Version 1.2.0, 21-JUL-1998 (NJB) */

/*        ZZEKJSQZ call was added after the ZZEKJOIN call.  This change */
/*        reduces the scratch area usage for intermediate results of */
/*        joins.  It also prevents ZZEKJOIN from being handed a join */
/*        row set containing a segment vector having no corresponding */
/*        row vectors. */

/*        Removed a comment in the join loop indicating that non-join */
/*        constraints involving comparisons of column entries in the */
/*        table were being activated.  This comment was incorrect; the */
/*        constraints in question were applied earlier. */

/* -    SPICELIB Version 1.0.1, 07-JUL-1996 (NJB) */

/*        Previous version line was changed from "Beta" to "SPICELIB." */

/* -    SPICELIB Version 1.0.0, 23-OCT-1995 (NJB) */

/* -& */
/* $ Index_Entries */

/*     search for events in loaded EK files */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "EKSRCH", (ftnlen)6);
    }

/*     There nothing to search if no files are loaded.  A sure */
/*     symptom of this problem is that the file list is empty. */

    if (__state->fthead <= 0) {
	setmsg_(__global_state, "No E-kernels are currently loaded.", (ftnlen)
		34);
	sigerr_(__global_state, "SPICE(NOLOADEDFILES)", (ftnlen)20);
	chkout_(__global_state, "EKSRCH", (ftnlen)6);
	return 0;
    }

/*     No error to begin with. */

    *semerr = FALSE_;
    s_copy(&__global_state->f2c, errmsg, " ", errmsg_len, (ftnlen)1);
    *nmrows = 0;
    if (__state->first) {

/*        Initialize the file table pool, segment table pool, column */
/*        descriptor pool, column table pool, and table list pool. */

	lnkini_(__global_state, &__state->c__20, __state->ftpool);
	lnkini_(__global_state, &__state->c__200, __state->stpool);
	lnkini_(__global_state, &__state->c__10000, __state->dtpool);
	lnkini_(__global_state, &__state->c__500, __state->ctpool);
	lnkini_(__global_state, &__state->c__100, __state->tbpool);
	__state->fthead = 0;
	__state->tbhead = 0;
	__state->first = FALSE_;
    }

/*     Read some of our favorite things from the query.  We need: */

/*        - the table count */
/*        - the SELECT clause column count */
/*        - the order-by column count */
/*        - the table and alias list */

    zzekreqi_(__global_state, eqryi, "NUM_TABLES", &__state->ntab, (ftnlen)10)
	    ;
    zzekreqi_(__global_state, eqryi, "NUM_SELECT_COLS", &__state->nsel, (
	    ftnlen)15);
    zzekreqi_(__global_state, eqryi, "NUM_ORDERBY_COLS", &__state->norder, (
	    ftnlen)16);
    i__1 = __state->ntab;
    for (__state->i__ = 1; __state->i__ <= i__1; ++__state->i__) {
	zzekqtab_(__global_state, eqryi, eqryc, &__state->i__, 
		__state->frmtab + (((i__2 = __state->i__ - 1) < 10 && 0 <= 
		i__2 ? i__2 : s_rnge(&__global_state->f2c, "frmtab", i__2, 
		"ekqmgr_", (ftnlen)3904)) << 6), __state->frmals + (((i__3 = 
		__state->i__ - 1) < 10 && 0 <= i__3 ? i__3 : s_rnge(&
		__global_state->f2c, "frmals", i__3, "ekqmgr_", (ftnlen)3904))
		 << 6), eqryc_len, (ftnlen)64, (ftnlen)64);
    }

/*     Initialize the table vectors.  Also initialize a vector of column */
/*     list pointers. */

    ssizec_(__global_state, &__state->c__10, __state->tabvec, (ftnlen)64);
    ssizei_(__global_state, &__state->c__10, __state->tptvec);

/*     Fill in the FROM table vector and corresponding column pointer */
/*     vector.  It's an error if a table referenced in the FROM clause */
/*     can't be found. */

    i__1 = __state->ntab;
    for (__state->i__ = 1; __state->i__ <= i__1; ++__state->i__) {

/*        Find the table list entry for this table name. */

	__state->tbcurr = __state->tbhead;
	__state->fnd = FALSE_;
	while(__state->tbcurr > 0 && ! __state->fnd) {
	    if (s_cmp(&__global_state->f2c, __state->tbnams + (((i__2 = 
		    __state->tbcurr - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "tbnams", i__2, "ekqmgr_", (ftnlen)
		    3928)) << 6), __state->frmtab + (((i__3 = __state->i__ - 
		    1) < 10 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c,
		     "frmtab", i__3, "ekqmgr_", (ftnlen)3928)) << 6), (ftnlen)
		    64, (ftnlen)64) == 0) {

/*              We've found the table list entry for the Ith table. */

		appndc_(__global_state, __state->frmtab + (((i__2 = 
			__state->i__ - 1) < 10 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "frmtab", i__2, "ekqmgr_", (
			ftnlen)3932)) << 6), __state->tabvec, (ftnlen)64, (
			ftnlen)64);
		appndi_(__global_state, &__state->tbcurr, __state->tptvec);
		__state->fnd = TRUE_;
	    } else {
		__state->tbcurr = lnknxt_(__global_state, &__state->tbcurr, 
			__state->tbpool);
	    }
	}
	if (! __state->fnd) {
	    setmsg_(__global_state, "The table # is not currently loaded.", (
		    ftnlen)36);
	    errch_(__global_state, "#", __state->frmtab + (((i__2 = 
		    __state->i__ - 1) < 10 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "frmtab", i__2, "ekqmgr_", (ftnlen)
		    3943)) << 6), (ftnlen)1, (ftnlen)64);
	    sigerr_(__global_state, "SPICE(INVALIDTABLENAME)", (ftnlen)23);
	    chkout_(__global_state, "EKSRCH", (ftnlen)6);
	    return 0;
	}
    }

/*     Since this is a new search, re-initialize the stack in the EK */
/*     scratch area.  Also initialize our total segment list count. */

    zzekstop_(__global_state, &__state->top);
    zzeksdec_(__global_state, &__state->top);

/*     Initialize the size of the join row set union for the current */
/*     query.  At this point, no matching rows have been found. */

    __state->usize = 0;
    __state->unrows = 0;

/*     Get the number of conjunctions and the sizes of the conjunctions. */

    zzekreqi_(__global_state, eqryi, "NUM_CONJUNCTIONS", &__state->nconj, (
	    ftnlen)16);
    cleari_(__global_state, &__state->c__1000, __state->sizes);
    i__1 = __state->nconj;
    for (__state->i__ = 1; __state->i__ <= i__1; ++__state->i__) {
	zzekqcnj_(__global_state, eqryi, &__state->i__, &__state->sizes[(i__2 
		= __state->i__ - 1) < 1000 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "sizes", i__2, "ekqmgr_", (ftnlen)3972)])
		;
    }

/*     For each conjunction of constraints, we'll build a join row */
/*     set representing the row vectors matching those constraints. */
/*     The final result will be a join row set union representing the */
/*     row vectors satisfying at least one conjunction. */

/*     We want to build a join row set even if there are *no* */
/*     constraints.  Therefore, we always make at least one pass */
/*     through the loop below. */

    __state->cjend = 0;
    i__1 = max(1,__state->nconj);
    for (__state->conj = 1; __state->conj <= i__1; ++__state->conj) {

/*        Our objective is to build a join row set representing the table */
/*        defined by the FROM columns and the input constraints.  To do */
/*        this, we'll first build a trivial join row set for each table; */
/*        this join row set represents the rows that satisfy constraints */
/*        on columns in that table.  Having done this, we'll produce a */
/*        final (for this conjunction) join row set that represents the */
/*        constrained join of the FROM tables.  The base address of this */
/*        join row set will be stored in the array UBASE. */

/*        We'll start out by recording the FROM table indices and column */
/*        list indices of columns listed in the constraints. */

	if (__state->nconj == 0) {
	    __state->cjsize = 0;
	} else {
	    __state->cjsize = __state->sizes[(i__2 = __state->conj - 1) < 
		    1000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "sizes", i__2, "ekqmgr_", (ftnlen)4004)];
	}
	__state->cjbeg = __state->cjend + 1;
	__state->cjend += __state->cjsize;
	i__2 = __state->cjsize;
	for (__state->i__ = 1; __state->i__ <= i__2; ++__state->i__) {
	    i__14 = __state->cjbeg + __state->i__ - 1;
	    zzekqcon_(__global_state, eqryi, eqryc, eqryd, &i__14, &
		    __state->cnstyp[(i__3 = __state->i__ - 1) < 1000 && 0 <= 
		    i__3 ? i__3 : s_rnge(&__global_state->f2c, "cnstyp", i__3,
		     "ekqmgr_", (ftnlen)4012)], __state->ltname, &
		    __state->ltbidx[(i__4 = __state->i__ - 1) < 1000 && 0 <= 
		    i__4 ? i__4 : s_rnge(&__global_state->f2c, "ltbidx", i__4,
		     "ekqmgr_", (ftnlen)4012)], __state->lcname, &
		    __state->lcidx[(i__5 = __state->i__ - 1) < 1000 && 0 <= 
		    i__5 ? i__5 : s_rnge(&__global_state->f2c, "lcidx", i__5, 
		    "ekqmgr_", (ftnlen)4012)], &__state->ops[(i__6 = 
		    __state->i__ - 1) < 1000 && 0 <= i__6 ? i__6 : s_rnge(&
		    __global_state->f2c, "ops", i__6, "ekqmgr_", (ftnlen)4012)
		    ], __state->rtname, &__state->rtbidx[(i__7 = __state->i__ 
		    - 1) < 1000 && 0 <= i__7 ? i__7 : s_rnge(&
		    __global_state->f2c, "rtbidx", i__7, "ekqmgr_", (ftnlen)
		    4012)], __state->rcname, &__state->rcidx[(i__8 = 
		    __state->i__ - 1) < 1000 && 0 <= i__8 ? i__8 : s_rnge(&
		    __global_state->f2c, "rcidx", i__8, "ekqmgr_", (ftnlen)
		    4012)], &__state->dtype[(i__9 = __state->i__ - 1) < 1000 
		    && 0 <= i__9 ? i__9 : s_rnge(&__global_state->f2c, "dtype"
		    , i__9, "ekqmgr_", (ftnlen)4012)], &__state->cbegs[(i__10 
		    = __state->i__ - 1) < 1000 && 0 <= i__10 ? i__10 : s_rnge(
		    &__global_state->f2c, "cbegs", i__10, "ekqmgr_", (ftnlen)
		    4012)], &__state->cends[(i__11 = __state->i__ - 1) < 1000 
		    && 0 <= i__11 ? i__11 : s_rnge(&__global_state->f2c, 
		    "cends", i__11, "ekqmgr_", (ftnlen)4012)], &
		    __state->dvals[(i__12 = __state->i__ - 1) < 1000 && 0 <= 
		    i__12 ? i__12 : s_rnge(&__global_state->f2c, "dvals", 
		    i__12, "ekqmgr_", (ftnlen)4012)], &__state->ivals[(i__13 =
		     __state->i__ - 1) < 1000 && 0 <= i__13 ? i__13 : s_rnge(&
		    __global_state->f2c, "ivals", i__13, "ekqmgr_", (ftnlen)
		    4012)], eqryc_len, (ftnlen)64, (ftnlen)32, (ftnlen)64, (
		    ftnlen)32);
	}
	i__2 = __state->ntab;
	for (__state->t = 1; __state->t <= i__2; ++__state->t) {

/*           We will build a trivial (one-table) join row set for the */
/*           current table. */

/*           Initialize the join row set.  Retain the base address.  We */
/*           can fill in the table count right away; the count is 1. */

	    zzekstop_(__global_state, &__state->rbas[(i__3 = __state->t - 1) <
		     10 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "rbas", i__3, "ekqmgr_", (ftnlen)4030)]);
	    for (__state->i__ = 1; __state->i__ <= 4; ++__state->i__) {
		zzekspsh_(__global_state, &__state->c__1, &__state->c__0);
	    }
	    i__5 = __state->rbas[(i__3 = __state->t - 1) < 10 && 0 <= i__3 ? 
		    i__3 : s_rnge(&__global_state->f2c, "rbas", i__3, "ekqmg"
		    "r_", (ftnlen)4036)] + 3;
	    i__6 = __state->rbas[(i__4 = __state->t - 1) < 10 && 0 <= i__4 ? 
		    i__4 : s_rnge(&__global_state->f2c, "rbas", i__4, "ekqmg"
		    "r_", (ftnlen)4036)] + 3;
	    zzeksupd_(__global_state, &i__5, &i__6, &__state->c__1);

/*           Count the loaded segments for the current table.  We'll */
/*           leave enough room in the join row set for each segment. */

	    __state->tab = __state->tptvec[(i__3 = __state->t + 5) < 16 && 0 
		    <= i__3 ? i__3 : s_rnge(&__global_state->f2c, "tptvec", 
		    i__3, "ekqmgr_", (ftnlen)4042)];
	    __state->i__ = __state->tbstpt[(i__3 = __state->tab - 1) < 100 && 
		    0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, "tbstpt", 
		    i__3, "ekqmgr_", (ftnlen)4043)];
	    __state->nsv = 0;
	    while(__state->i__ > 0) {
		zzekspsh_(__global_state, &__state->c__1, &__state->c__0);
		++__state->nsv;
		__state->i__ = lnknxt_(__global_state, &__state->i__, 
			__state->stpool);
	    }

/*           Save room for the row vector base addresses and counts. */

	    i__3 = __state->nsv << 1;
	    for (__state->i__ = 1; __state->i__ <= i__3; ++__state->i__) {
		zzekspsh_(__global_state, &__state->c__1, &__state->c__0);
	    }

/*           At this point, we can set the segment vector count in the */
/*           join row set. */

	    i__5 = __state->rbas[(i__3 = __state->t - 1) < 10 && 0 <= i__3 ? 
		    i__3 : s_rnge(&__global_state->f2c, "rbas", i__3, "ekqmg"
		    "r_", (ftnlen)4066)] + 4;
	    i__6 = __state->rbas[(i__4 = __state->t - 1) < 10 && 0 <= i__4 ? 
		    i__4 : s_rnge(&__global_state->f2c, "rbas", i__4, "ekqmg"
		    "r_", (ftnlen)4066)] + 4;
	    zzeksupd_(__global_state, &i__5, &i__6, &__state->nsv);

/*           Find the matching rows in the segments belonging to the */
/*           current table. */

	    __state->seg = __state->tbstpt[(i__3 = __state->tab - 1) < 100 && 
		    0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, "tbstpt", 
		    i__3, "ekqmgr_", (ftnlen)4072)];
	    __state->nseg = 0;
	    __state->rtotal = 0;
	    while(__state->seg > 0) {
		++__state->nseg;

/*              The segment vector for this segment is trivial:  it's */
/*              just the segment's index in the segment table. */

		__state->sgvbas = __state->rbas[(i__3 = __state->t - 1) < 10 
			&& 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
			"rbas", i__3, "ekqmgr_", (ftnlen)4083)] + 4 + (
			__state->nseg - 1);
		i__3 = __state->sgvbas + 1;
		i__4 = __state->sgvbas + 1;
		zzeksupd_(__global_state, &i__3, &i__4, &__state->seg);

/*              Label as `inactive' any constraints that don't apply to */
/*              this table.  Join constraints are inactive at this stage */
/*              of the game.  Label all other constraints `active'. */
/*              We'll keep track of column and value constraints */
/*              separately. */

		i__3 = __state->cjsize;
		for (__state->i__ = 1; __state->i__ <= i__3; ++__state->i__) {

/*                 Each constraint is active to start with. */

		    __state->activc[(i__4 = __state->i__ - 1) < 1000 && 0 <= 
			    i__4 ? i__4 : s_rnge(&__global_state->f2c, "acti"
			    "vc", i__4, "ekqmgr_", (ftnlen)4098)] = 
			    __state->cnstyp[(i__5 = __state->i__ - 1) < 1000 
			    && 0 <= i__5 ? i__5 : s_rnge(&__global_state->f2c,
			     "cnstyp", i__5, "ekqmgr_", (ftnlen)4098)] == 1;
		    __state->activv[(i__4 = __state->i__ - 1) < 1000 && 0 <= 
			    i__4 ? i__4 : s_rnge(&__global_state->f2c, "acti"
			    "vv", i__4, "ekqmgr_", (ftnlen)4099)] = 
			    __state->cnstyp[(i__5 = __state->i__ - 1) < 1000 
			    && 0 <= i__5 ? i__5 : s_rnge(&__global_state->f2c,
			     "cnstyp", i__5, "ekqmgr_", (ftnlen)4099)] == 2;

/*                 The parent table of the LHS column must be the Tth */
/*                 table, or this constraint does not apply. */

/*                 We'll also exclude join constraints.  Note that */
/*                 constraints comparing values from two columns need not */
/*                 be join constraints:  it's possible that the column on */
/*                 the right belongs to the same FROM table as the */
/*                 column on the left. */

		    if (__state->ltbidx[(i__4 = __state->i__ - 1) < 1000 && 0 
			    <= i__4 ? i__4 : s_rnge(&__global_state->f2c, 
			    "ltbidx", i__4, "ekqmgr_", (ftnlen)4111)] != 
			    __state->t) {
			__state->activc[(i__4 = __state->i__ - 1) < 1000 && 0 
				<= i__4 ? i__4 : s_rnge(&__global_state->f2c, 
				"activc", i__4, "ekqmgr_", (ftnlen)4113)] = 
				FALSE_;
			__state->activv[(i__4 = __state->i__ - 1) < 1000 && 0 
				<= i__4 ? i__4 : s_rnge(&__global_state->f2c, 
				"activv", i__4, "ekqmgr_", (ftnlen)4114)] = 
				FALSE_;
		    } else if (__state->cnstyp[(i__4 = __state->i__ - 1) < 
			    1000 && 0 <= i__4 ? i__4 : s_rnge(&
			    __global_state->f2c, "cnstyp", i__4, "ekqmgr_", (
			    ftnlen)4117)] == 1) {
			if (__state->ltbidx[(i__4 = __state->i__ - 1) < 1000 
				&& 0 <= i__4 ? i__4 : s_rnge(&
				__global_state->f2c, "ltbidx", i__4, "ekqmgr_"
				, (ftnlen)4119)] != __state->rtbidx[(i__5 = 
				__state->i__ - 1) < 1000 && 0 <= i__5 ? i__5 :
				 s_rnge(&__global_state->f2c, "rtbidx", i__5, 
				"ekqmgr_", (ftnlen)4119)]) {

/*                       This is a join constraint; disable it. */

			    __state->activc[(i__4 = __state->i__ - 1) < 1000 
				    && 0 <= i__4 ? i__4 : s_rnge(&
				    __global_state->f2c, "activc", i__4, 
				    "ekqmgr_", (ftnlen)4123)] = FALSE_;
			}
		    }
		}

/*              At this point, we'll have to search the segment for */
/*              matching rows.  Pick a key column for the segment.  To */
/*              do this, we'll need to pack an array with column */
/*              descriptors for each active constraint.  The */
/*              descriptor for the column on the left side of the Ith */
/*              constraint will be placed in elements LDSCRS(*,I), if */
/*              the Ith constraint is active. */

		cleari_(__global_state, &__state->c__11000, __state->ldscrs);
		i__3 = __state->cjsize;
		for (__state->i__ = 1; __state->i__ <= i__3; ++__state->i__) {
		    if (__state->activv[(i__4 = __state->i__ - 1) < 1000 && 0 
			    <= i__4 ? i__4 : s_rnge(&__global_state->f2c, 
			    "activv", i__4, "ekqmgr_", (ftnlen)4147)]) {

/*                     Look up the column descriptor for this */
/*                     constraint. */

			__state->j = __state->stdtpt[(i__4 = __state->seg - 1)
				 < 200 && 0 <= i__4 ? i__4 : s_rnge(&
				__global_state->f2c, "stdtpt", i__4, "ekqmgr_"
				, (ftnlen)4152)];
			i__5 = __state->lcidx[(i__4 = __state->i__ - 1) < 
				1000 && 0 <= i__4 ? i__4 : s_rnge(&
				__global_state->f2c, "lcidx", i__4, "ekqmgr_",
				 (ftnlen)4154)];
			for (__state->k = 2; __state->k <= i__5; ++__state->k)
				 {
			    __state->j = lnknxt_(__global_state, &__state->j, 
				    __state->dtpool);
			}
			movei_(__global_state, &__state->dtdscs[(i__5 = 
				__state->j * 11 - 11) < 110000 && 0 <= i__5 ? 
				i__5 : s_rnge(&__global_state->f2c, "dtdscs", 
				i__5, "ekqmgr_", (ftnlen)4158)], &
				__state->c__11, &__state->ldscrs[(i__4 = 
				__state->i__ * 11 - 11) < 11000 && 0 <= i__4 ?
				 i__4 : s_rnge(&__global_state->f2c, "ldscrs",
				 i__4, "ekqmgr_", (ftnlen)4158)]);
		    }
		}
		zzekkey_(__global_state, &__state->sthan[(i__3 = __state->seg 
			- 1) < 200 && 0 <= i__3 ? i__3 : s_rnge(&
			__global_state->f2c, "sthan", i__3, "ekqmgr_", (
			ftnlen)4165)], &__state->stdscs[(i__5 = __state->seg *
			 24 - 24) < 4800 && 0 <= i__5 ? i__5 : s_rnge(&
			__global_state->f2c, "stdscs", i__5, "ekqmgr_", (
			ftnlen)4165)], &__state->stnrow[(i__4 = __state->seg 
			- 1) < 200 && 0 <= i__4 ? i__4 : s_rnge(&
			__global_state->f2c, "stnrow", i__4, "ekqmgr_", (
			ftnlen)4165)], &__state->cjsize, __state->lcidx, 
			__state->ldscrs, __state->ops, __state->dtype, eqryc, 
			__state->cbegs, __state->cends, __state->dvals, 
			__state->ivals, __state->activv, &__state->key, 
			__state->keydsc, &__state->begidx, &__state->endidx, &
			__state->keyfnd, eqryc_len);

/*              ZZEKKEY has updated ACTIVV to reflect the application */
/*              of constraints that were used to determine BEGIDX and */
/*              ENDIDX. */

		if (__state->keyfnd) {
		    __state->indexd = TRUE_;
		} else {

/*                 A key column could not be determined from the */
/*                 active constraints.  We'll use the first column of */
/*                 the segment as the key column. */

		    __state->indexd = FALSE_;
		    __state->begidx = 1;
		    __state->endidx = __state->stnrow[(i__3 = __state->seg - 
			    1) < 200 && 0 <= i__3 ? i__3 : s_rnge(&
			    __global_state->f2c, "stnrow", i__3, "ekqmgr_", (
			    ftnlen)4193)];
		}

/*              Whether or not we have any matching rows, we'll need */
/*              to record how many we have.  Save the offset from the */
/*              join row set base for the pointer to the row vectors. */
/*              The row vector count follows this pointer. */

		__state->ptroff = __state->nsv + 4 + (__state->nseg - 1 << 1) 
			+ 1;
		if (__state->endidx >= __state->begidx) {

/*                 Initialize the count of matching rows for this */
/*                 segment.  The current stack top is the base address */
/*                 for the row vectors; save the offset of this */
/*                 address from the join row set's base. */
/*                 Also compute the base address of the segment vector */
/*                 for the current segment. */

		    __state->nmatch = 0;
		    zzekstop_(__global_state, &__state->rwvbas);
		    i__6 = __state->rbas[(i__3 = __state->t - 1) < 10 && 0 <= 
			    i__3 ? i__3 : s_rnge(&__global_state->f2c, "rbas",
			     i__3, "ekqmgr_", (ftnlen)4218)] + 
			    __state->ptroff;
		    i__7 = __state->rbas[(i__5 = __state->t - 1) < 10 && 0 <= 
			    i__5 ? i__5 : s_rnge(&__global_state->f2c, "rbas",
			     i__5, "ekqmgr_", (ftnlen)4218)] + 
			    __state->ptroff;
		    i__8 = __state->rwvbas - __state->rbas[(i__4 = __state->t 
			    - 1) < 10 && 0 <= i__4 ? i__4 : s_rnge(&
			    __global_state->f2c, "rbas", i__4, "ekqmgr_", (
			    ftnlen)4218)];
		    zzeksupd_(__global_state, &i__6, &i__7, &i__8);

/*                 Count the active constraints.  While we're at it, */
/*                 fill in the descriptor lists LDSCRS and RDSCRS */
/*                 with, respectively, the descriptors for the columns */
/*                 on the left hand sides and right hand sides of */
/*                 these constraints. */

		    cleari_(__global_state, &__state->c__11000, 
			    __state->ldscrs);
		    cleari_(__global_state, &__state->c__11000, 
			    __state->rdscrs);
		    __state->nact = 0;
		    i__3 = __state->cjsize;
		    for (__state->i__ = 1; __state->i__ <= i__3; 
			    ++__state->i__) {
			if (__state->activc[(i__5 = __state->i__ - 1) < 1000 
				&& 0 <= i__5 ? i__5 : s_rnge(&
				__global_state->f2c, "activc", i__5, "ekqmgr_"
				, (ftnlen)4234)] || __state->activv[(i__4 = 
				__state->i__ - 1) < 1000 && 0 <= i__4 ? i__4 :
				 s_rnge(&__global_state->f2c, "activv", i__4, 
				"ekqmgr_", (ftnlen)4234)]) {
			    ++__state->nact;

/*                       Look up the column descriptor for this */
/*                       constraint. */
			    __state->j = __state->stdtpt[(i__5 = __state->seg 
				    - 1) < 200 && 0 <= i__5 ? i__5 : s_rnge(&
				    __global_state->f2c, "stdtpt", i__5, 
				    "ekqmgr_", (ftnlen)4241)];
			    i__4 = __state->lcidx[(i__5 = __state->i__ - 1) < 
				    1000 && 0 <= i__5 ? i__5 : s_rnge(&
				    __global_state->f2c, "lcidx", i__5, "ekq"
				    "mgr_", (ftnlen)4243)];
			    for (__state->k = 2; __state->k <= i__4; 
				    ++__state->k) {
				__state->j = lnknxt_(__global_state, &
					__state->j, __state->dtpool);
			    }
			    movei_(__global_state, &__state->dtdscs[(i__4 = 
				    __state->j * 11 - 11) < 110000 && 0 <= 
				    i__4 ? i__4 : s_rnge(&__global_state->f2c,
				     "dtdscs", i__4, "ekqmgr_", (ftnlen)4247)]
				    , &__state->c__11, &__state->ldscrs[(i__5 
				    = __state->i__ * 11 - 11) < 11000 && 0 <= 
				    i__5 ? i__5 : s_rnge(&__global_state->f2c,
				     "ldscrs", i__5, "ekqmgr_", (ftnlen)4247)]
				    );
			    __state->j = __state->stdtpt[(i__4 = __state->seg 
				    - 1) < 200 && 0 <= i__4 ? i__4 : s_rnge(&
				    __global_state->f2c, "stdtpt", i__4, 
				    "ekqmgr_", (ftnlen)4250)];
			    i__5 = __state->rcidx[(i__4 = __state->i__ - 1) < 
				    1000 && 0 <= i__4 ? i__4 : s_rnge(&
				    __global_state->f2c, "rcidx", i__4, "ekq"
				    "mgr_", (ftnlen)4252)];
			    for (__state->k = 2; __state->k <= i__5; 
				    ++__state->k) {
				__state->j = lnknxt_(__global_state, &
					__state->j, __state->dtpool);
			    }
			    movei_(__global_state, &__state->dtdscs[(i__5 = 
				    __state->j * 11 - 11) < 110000 && 0 <= 
				    i__5 ? i__5 : s_rnge(&__global_state->f2c,
				     "dtdscs", i__5, "ekqmgr_", (ftnlen)4256)]
				    , &__state->c__11, &__state->rdscrs[(i__4 
				    = __state->i__ * 11 - 11) < 11000 && 0 <= 
				    i__4 ? i__4 : s_rnge(&__global_state->f2c,
				     "rdscrs", i__4, "ekqmgr_", (ftnlen)4256)]
				    );
			}
		    }
		    if (__state->nact > 0) {

/*                    There are still active constraints left, so */
/*                    proceed linearly through the remaining rows, */
/*                    testing each one against these constraints. Add */
/*                    matching rows to the current join row set. */

			i__3 = __state->endidx;
			for (__state->r__ = __state->begidx; __state->r__ <= 
				i__3; ++__state->r__) {
			    if (__state->indexd) {
				zzekixlk_(__global_state, &__state->sthan[(
					i__5 = __state->seg - 1) < 200 && 0 <=
					 i__5 ? i__5 : s_rnge(&
					__global_state->f2c, "sthan", i__5, 
					"ekqmgr_", (ftnlen)4275)], 
					__state->keydsc, &__state->r__, &
					__state->rowidx);
			    } else {

/*                          Look up the record pointer for row R. */

				zzekrplk_(__global_state, &__state->sthan[(
					i__5 = __state->seg - 1) < 200 && 0 <=
					 i__5 ? i__5 : s_rnge(&
					__global_state->f2c, "sthan", i__5, 
					"ekqmgr_", (ftnlen)4283)], &
					__state->stdscs[(i__4 = __state->seg *
					 24 - 24) < 4800 && 0 <= i__4 ? i__4 :
					 s_rnge(&__global_state->f2c, "stdscs"
					, i__4, "ekqmgr_", (ftnlen)4283)], &
					__state->r__, &__state->rowidx);
			    }

/*                       Test the row against both value and column */
/*                       constraints.  For now, we supply an array */
/*                       of default column entry element indices. */

			    __state->vmtch = zzekrmch_(__global_state, &
				    __state->cjsize, __state->activv, &
				    __state->sthan[(i__5 = __state->seg - 1) <
				     200 && 0 <= i__5 ? i__5 : s_rnge(&
				    __global_state->f2c, "sthan", i__5, "ekq"
				    "mgr_", (ftnlen)4294)], &__state->stdscs[(
				    i__4 = __state->seg * 24 - 24) < 4800 && 
				    0 <= i__4 ? i__4 : s_rnge(&
				    __global_state->f2c, "stdscs", i__4, 
				    "ekqmgr_", (ftnlen)4294)], 
				    __state->ldscrs, &__state->rowidx, 
				    __state->lelts, __state->ops, 
				    __state->dtype, eqryc, __state->cbegs, 
				    __state->cends, __state->dvals, 
				    __state->ivals, eqryc_len);
			    __state->cmtch = TRUE_;

/*                       Note that ZZEKVMCH expects a set of inputs */
/*                       that are not really parallel to those */
/*                       expected by ZZEKRMCH.  We feed the */
/*                       column comparison constraints to ZZEKVMCH */
/*                       one at a time. */

			    i__5 = __state->cjsize;
			    for (__state->j = 1; __state->j <= i__5; 
				    ++__state->j) {
				__state->cmtch = __state->cmtch && zzekvmch_(
					__global_state, &__state->c__1, &
					__state->activc[(i__4 = __state->j - 
					1) < 1000 && 0 <= i__4 ? i__4 : 
					s_rnge(&__global_state->f2c, "activc",
					 i__4, "ekqmgr_", (ftnlen)4313)], &
					__state->sthan[(i__6 = __state->seg - 
					1) < 200 && 0 <= i__6 ? i__6 : s_rnge(
					&__global_state->f2c, "sthan", i__6, 
					"ekqmgr_", (ftnlen)4313)], &
					__state->stdscs[(i__7 = __state->seg *
					 24 - 24) < 4800 && 0 <= i__7 ? i__7 :
					 s_rnge(&__global_state->f2c, "stdscs"
					, i__7, "ekqmgr_", (ftnlen)4313)], &
					__state->ldscrs[(i__8 = __state->j * 
					11 - 11) < 11000 && 0 <= i__8 ? i__8 :
					 s_rnge(&__global_state->f2c, "ldscrs"
					, i__8, "ekqmgr_", (ftnlen)4313)], &
					__state->rowidx, &__state->c__1, &
					__state->ops[(i__9 = __state->j - 1) <
					 1000 && 0 <= i__9 ? i__9 : s_rnge(&
					__global_state->f2c, "ops", i__9, 
					"ekqmgr_", (ftnlen)4313)], &
					__state->sthan[(i__10 = __state->seg 
					- 1) < 200 && 0 <= i__10 ? i__10 : 
					s_rnge(&__global_state->f2c, "sthan", 
					i__10, "ekqmgr_", (ftnlen)4313)], &
					__state->stdscs[(i__11 = __state->seg 
					* 24 - 24) < 4800 && 0 <= i__11 ? 
					i__11 : s_rnge(&__global_state->f2c, 
					"stdscs", i__11, "ekqmgr_", (ftnlen)
					4313)], &__state->rdscrs[(i__12 = 
					__state->j * 11 - 11) < 11000 && 0 <= 
					i__12 ? i__12 : s_rnge(&
					__global_state->f2c, "rdscrs", i__12, 
					"ekqmgr_", (ftnlen)4313)], &
					__state->rowidx, &__state->c__1);
			    }
			    if (__state->cmtch && __state->vmtch) {

/*                          Push the `augmented row vector' for the */
/*                          current row onto the stack.  In this case, */
/*                          of course, the augmented row vector is */
/*                          trivial:  it consists of the row number, */
/*                          followed by the base address of the parent */
/*                          segment vector. */

				++__state->nmatch;
				zzekspsh_(__global_state, &__state->c__1, &
					__state->rowidx);
				i__4 = __state->sgvbas - __state->rbas[(i__5 =
					 __state->t - 1) < 10 && 0 <= i__5 ? 
					i__5 : s_rnge(&__global_state->f2c, 
					"rbas", i__5, "ekqmgr_", (ftnlen)4342)
					];
				zzekspsh_(__global_state, &__state->c__1, &
					i__4);
			    }
			}
		    } else {

/*                    All the rows indicated by BEGIDX and ENDIDX */
/*                    match the constraints.  This code section should */
/*                    be upgraded to transfer the row numbers in */
/*                    chunks. */

			__state->nmatch = __state->endidx - __state->begidx + 
				1;
			i__3 = __state->endidx;
			for (__state->r__ = __state->begidx; __state->r__ <= 
				i__3; ++__state->r__) {
			    if (__state->indexd) {

/*                          Look up the record pointer for row R */
/*                          from the column index. */

				zzekixlk_(__global_state, &__state->sthan[(
					i__5 = __state->seg - 1) < 200 && 0 <=
					 i__5 ? i__5 : s_rnge(&
					__global_state->f2c, "sthan", i__5, 
					"ekqmgr_", (ftnlen)4366)], 
					__state->keydsc, &__state->r__, &
					__state->rowidx);
			    } else {

/*                          Look up the record pointer for row R. */

				zzekrplk_(__global_state, &__state->sthan[(
					i__5 = __state->seg - 1) < 200 && 0 <=
					 i__5 ? i__5 : s_rnge(&
					__global_state->f2c, "sthan", i__5, 
					"ekqmgr_", (ftnlen)4374)], &
					__state->stdscs[(i__4 = __state->seg *
					 24 - 24) < 4800 && 0 <= i__4 ? i__4 :
					 s_rnge(&__global_state->f2c, "stdscs"
					, i__4, "ekqmgr_", (ftnlen)4374)], &
					__state->r__, &__state->rowidx);
			    }
			    zzekspsh_(__global_state, &__state->c__1, &
				    __state->rowidx);
			    i__4 = __state->sgvbas - __state->rbas[(i__5 = 
				    __state->t - 1) < 10 && 0 <= i__5 ? i__5 :
				     s_rnge(&__global_state->f2c, "rbas", 
				    i__5, "ekqmgr_", (ftnlen)4382)];
			    zzekspsh_(__global_state, &__state->c__1, &i__4);
			}
		    }

/*                 Fill in the row count for this segment in the join row */
/*                 set. */

		    i__4 = __state->rbas[(i__3 = __state->t - 1) < 10 && 0 <= 
			    i__3 ? i__3 : s_rnge(&__global_state->f2c, "rbas",
			     i__3, "ekqmgr_", (ftnlen)4392)] + 
			    __state->ptroff + 1;
		    i__6 = __state->rbas[(i__5 = __state->t - 1) < 10 && 0 <= 
			    i__5 ? i__5 : s_rnge(&__global_state->f2c, "rbas",
			     i__5, "ekqmgr_", (ftnlen)4392)] + 
			    __state->ptroff + 1;
		    zzeksupd_(__global_state, &i__4, &i__6, &__state->nmatch);
		}

/*              Take a look at the next segment.  Update the total count */
/*              of matching rows for this table. */

		__state->seg = lnknxt_(__global_state, &__state->seg, 
			__state->stpool);
		__state->rtotal += __state->nmatch;
	    }

/*           Fill in the size and count information for the join row set. */

	    zzekstop_(__global_state, &__state->top);
	    __state->rsize[(i__3 = __state->t - 1) < 200 && 0 <= i__3 ? i__3 :
		     s_rnge(&__global_state->f2c, "rsize", i__3, "ekqmgr_", (
		    ftnlen)4410)] = __state->top - __state->rbas[(i__5 = 
		    __state->t - 1) < 10 && 0 <= i__5 ? i__5 : s_rnge(&
		    __global_state->f2c, "rbas", i__5, "ekqmgr_", (ftnlen)
		    4410)];
	    i__6 = __state->rbas[(i__3 = __state->t - 1) < 10 && 0 <= i__3 ? 
		    i__3 : s_rnge(&__global_state->f2c, "rbas", i__3, "ekqmg"
		    "r_", (ftnlen)4412)] + 1;
	    i__7 = __state->rbas[(i__5 = __state->t - 1) < 10 && 0 <= i__5 ? 
		    i__5 : s_rnge(&__global_state->f2c, "rbas", i__5, "ekqmg"
		    "r_", (ftnlen)4412)] + 1;
	    zzeksupd_(__global_state, &i__6, &i__7, &__state->rsize[(i__4 = 
		    __state->t - 1) < 200 && 0 <= i__4 ? i__4 : s_rnge(&
		    __global_state->f2c, "rsize", i__4, "ekqmgr_", (ftnlen)
		    4412)]);
	    i__4 = __state->rbas[(i__3 = __state->t - 1) < 10 && 0 <= i__3 ? 
		    i__3 : s_rnge(&__global_state->f2c, "rbas", i__3, "ekqmg"
		    "r_", (ftnlen)4413)] + 2;
	    i__6 = __state->rbas[(i__5 = __state->t - 1) < 10 && 0 <= i__5 ? 
		    i__5 : s_rnge(&__global_state->f2c, "rbas", i__5, "ekqmg"
		    "r_", (ftnlen)4413)] + 2;
	    zzeksupd_(__global_state, &i__4, &i__6, &__state->rtotal);

/*           Compress out any empty segment vectors from the join row */
/*           set. */

	    zzekjsqz_(__global_state, &__state->rbas[(i__3 = __state->t - 1) <
		     10 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "rbas", i__3, "ekqmgr_", (ftnlen)4419)]);

/*           At this point, we've filled in the entire join row set for */
/*           table T. */

	}

/*        Join the trivial join row sets, producing a final join row set */
/*        for the current conjunction.  Retain the base address of this */
/*        join row set, if it is non-empty.  Update the size of the join */
/*        row set union. */


	__state->resbas = __state->rbas[0];
	i__2 = __state->ntab;
	for (__state->t = 2; __state->t <= i__2; ++__state->t) {

/*           Arm the join constraints!  Turn on the constraints that */
/*           have the Tth table on the one side, and tables */
/*           1, 2, ... , T on the other. */

	    i__3 = __state->cjsize;
	    for (__state->i__ = 1; __state->i__ <= i__3; ++__state->i__) {
		__state->activc[(i__5 = __state->i__ - 1) < 1000 && 0 <= i__5 
			? i__5 : s_rnge(&__global_state->f2c, "activc", i__5, 
			"ekqmgr_", (ftnlen)4444)] = FALSE_;
		if (__state->cnstyp[(i__5 = __state->i__ - 1) < 1000 && 0 <= 
			i__5 ? i__5 : s_rnge(&__global_state->f2c, "cnstyp", 
			i__5, "ekqmgr_", (ftnlen)4446)] == 1) {
		    __state->l = __state->ltbidx[(i__5 = __state->i__ - 1) < 
			    1000 && 0 <= i__5 ? i__5 : s_rnge(&
			    __global_state->f2c, "ltbidx", i__5, "ekqmgr_", (
			    ftnlen)4448)];
		    __state->r__ = __state->rtbidx[(i__5 = __state->i__ - 1) <
			     1000 && 0 <= i__5 ? i__5 : s_rnge(&
			    __global_state->f2c, "rtbidx", i__5, "ekqmgr_", (
			    ftnlen)4449)];
		    if (__state->l >= 1 && __state->l <= __state->t && 
			    __state->r__ >= 1 && __state->r__ <= __state->t &&
			     __state->l != __state->r__ && (__state->r__ == 
			    __state->t || __state->l == __state->t)) {
			__state->activc[(i__5 = __state->i__ - 1) < 1000 && 0 
				<= i__5 ? i__5 : s_rnge(&__global_state->f2c, 
				"activc", i__5, "ekqmgr_", (ftnlen)4459)] = 
				TRUE_;
		    }
		}
	    }

/*           The base address of the first join row set is the base */
/*           address of the result of the previous join.  The first time */
/*           through, the base of the join row set for table 1 is used. */

	    if (__state->t == 2) {
		__state->jbase1 = __state->rbas[0];
	    } else {
		__state->jbase1 = __state->resbas;
	    }
	    __state->jbase2 = __state->rbas[(i__3 = __state->t - 1) < 10 && 0 
		    <= i__3 ? i__3 : s_rnge(&__global_state->f2c, "rbas", 
		    i__3, "ekqmgr_", (ftnlen)4478)];
	    zzekjoin_(__global_state, &__state->jbase1, &__state->jbase2, &
		    __state->cjsize, __state->activc, __state->ltbidx, 
		    __state->lcidx, __state->lelts, __state->ops, 
		    __state->rtbidx, __state->rcidx, __state->relts, 
		    __state->sthan, __state->stdscs, __state->stdtpt, 
		    __state->dtpool, __state->dtdscs, &__state->resbas, &
		    __state->jsize);
	    zzekjsqz_(__global_state, &__state->resbas);
	}

/*        At this point, we've found the matching rows for the current */
/*        query conjunction.  Update the size of the join row set union */
/*        corresponding to the current query.  Save the base address of */
/*        the final join row set.  Update the total number of matching */
/*        rows in the join row set union. */

	++__state->usize;
	__state->ubase[(i__2 = __state->usize - 1) < 200 && 0 <= i__2 ? i__2 :
		 s_rnge(&__global_state->f2c, "ubase", i__2, "ekqmgr_", (
		ftnlen)4498)] = __state->resbas;
	i__2 = __state->resbas + 2;
	i__3 = __state->resbas + 2;
	zzeksrd_(__global_state, &i__2, &i__3, &__state->cjrows);
	__state->unrows += __state->cjrows;

/*        Remove redundant row vectors from the join row set union. */
/*        These row vectors may arise in the execution of queries whose */
/*        WHERE clauses contain multiple conjunctions. */

	zzekweed_(__global_state, &__state->usize, __state->ubase, &
		__state->unrows);

/*        Initialize the addressing function for the current join row */
/*        set union. */

	if (__state->usize > 0) {
	    zzekvset_(__global_state, &__state->usize, __state->ubase);
	}
    }

/*     At this point, we've formed the join row set union that */
/*     represents the set of row vectors matching the entire query. */

    *nmrows = __state->unrows;

/*     Get the tables and columns of from the SELECT clause.  For */
/*     each qualifying table, we need the index in the FROM clause */
/*     of that table.  For each column, we need the column table */
/*     index. */

    i__1 = __state->nsel;
    for (__state->i__ = 1; __state->i__ <= i__1; ++__state->i__) {
	zzekqsel_(__global_state, eqryi, eqryc, &__state->i__, &
		__state->lxbeg, &__state->lxend, __state->tabnam, &
		__state->tabidx, __state->colnam, &__state->k, eqryc_len, (
		ftnlen)64, (ftnlen)32);

/*        Locate the column's attribute information.  Retain the column's */
/*        index within the parent table's column list. */

	__state->tab = __state->tptvec[(i__2 = __state->tabidx + 5) < 16 && 0 
		<= i__2 ? i__2 : s_rnge(&__global_state->f2c, "tptvec", i__2, 
		"ekqmgr_", (ftnlen)4542)];
	__state->j = __state->tbctpt[(i__2 = __state->tab - 1) < 100 && 0 <= 
		i__2 ? i__2 : s_rnge(&__global_state->f2c, "tbctpt", i__2, 
		"ekqmgr_", (ftnlen)4543)];
	__state->col = 0;
	__state->fnd = FALSE_;
	while(__state->j > 0 && ! __state->fnd) {
	    ++__state->col;
	    if (s_cmp(&__global_state->f2c, __state->ctnams + (((i__2 = 
		    __state->j - 1) < 500 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "ctnams", i__2, "ekqmgr_", (ftnlen)
		    4551)) << 5), __state->colnam, (ftnlen)32, (ftnlen)32) == 
		    0) {
		__state->fnd = TRUE_;
	    } else {
		__state->j = lnknxt_(__global_state, &__state->j, 
			__state->ctpool);
	    }
	}
	if (! __state->fnd) {
	    setmsg_(__global_state, "# is not name of a column in FROM table"
		    " #.", (ftnlen)42);
	    errch_(__global_state, "#", __state->colnam, (ftnlen)1, (ftnlen)
		    32);
	    errint_(__global_state, "#", &__state->tabidx, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(BUG)", (ftnlen)10);
	    chkout_(__global_state, "EKSRCH", (ftnlen)6);
	    return 0;
	}
	__state->selctp[(i__2 = __state->i__ - 1) < 50 && 0 <= i__2 ? i__2 : 
		s_rnge(&__global_state->f2c, "selctp", i__2, "ekqmgr_", (
		ftnlen)4568)] = __state->j;
	__state->selcol[(i__2 = __state->i__ - 1) < 50 && 0 <= i__2 ? i__2 : 
		s_rnge(&__global_state->f2c, "selcol", i__2, "ekqmgr_", (
		ftnlen)4569)] = __state->col;
	__state->seltab[(i__2 = __state->i__ - 1) < 50 && 0 <= i__2 ? i__2 : 
		s_rnge(&__global_state->f2c, "seltab", i__2, "ekqmgr_", (
		ftnlen)4570)] = __state->tabidx;
    }

/*     Enable sorting of the matching row vectors, if necessary.  The */
/*     first fetch request will invoke the sort. */

    __state->dosort = __state->norder > 0 && *nmrows > 0;
    __state->sorted = FALSE_;
    if (__state->dosort) {
	i__1 = __state->norder;
	for (__state->i__ = 1; __state->i__ <= i__1; ++__state->i__) {
	    zzekqord_(__global_state, eqryi, eqryc, &__state->i__, 
		    __state->tabnam, &__state->otabs[(i__2 = __state->i__ - 1)
		     < 10 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "otabs", i__2, "ekqmgr_", (ftnlen)4585)], __state->colnam,
		     &__state->ocols[(i__3 = __state->i__ - 1) < 10 && 0 <= 
		    i__3 ? i__3 : s_rnge(&__global_state->f2c, "ocols", i__3, 
		    "ekqmgr_", (ftnlen)4585)], &__state->sense[(i__5 = 
		    __state->i__ - 1) < 10 && 0 <= i__5 ? i__5 : s_rnge(&
		    __global_state->f2c, "sense", i__5, "ekqmgr_", (ftnlen)
		    4585)], eqryc_len, (ftnlen)64, (ftnlen)32);
	}
    }
    chkout_(__global_state, "EKSRCH", (ftnlen)6);
    return 0;
/* $Procedure     EKNELT  ( EK, get number of elements in column entry ) */

L_eknelt:
/* $ Abstract */

/*     Return the number of elements in a specified column entry in */
/*     the current row. */

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

/*     INTEGER               SELIDX */
/*     INTEGER               ROW */
/*     INTEGER               NELT */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     SELIDX     I   Index of parent column in SELECT clause. */
/*     ROW        I   Row containing element. */
/*     NELT       O   Number of elements in entry in current row. */

/* $ Detailed_Input */

/*     SELIDX         is the SELECT clause index of the column to */
/*                    fetch from. */

/*     ROW            is the index of the row containing the element. */
/*                    This number refers to a member of the set of rows */
/*                    matching a query.  ROW must be in the range */

/*                      1 : NMROWS */

/*                    where NMROWS is the matching row count returned */
/*                    by EKSRCH. */

/* $ Detailed_Output */

/*     NELT           is the number of elements in the column entry */
/*                    belonging to the specified column in the current */
/*                    row. */

/*                    Null entries in variable-size columns are */
/*                    considered to have size 1. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If this routine is called when no E-kernels have been loaded, */
/*         the error SPICE(NOLOADEDFILES) is signaled. */

/*     2)  If SELIDX is outside of the range established by the */
/*         last query passed to EKSRCH, the error SPICE(INVALIDINDEX) */
/*         will be signaled. */

/*     3)  If ROW is outside of the range established by the */
/*         last query passed to EKSRCH, the error SPICE(INVALIDINDEX) */
/*         will be signaled. */

/* $ Files */

/*     See the header of EKQMGR for a description of files used */
/*     by this routine. */

/* $ Particulars */

/*     This routine is meant to be used in conjunction with the EKQMGR */
/*     fetch entry points EKGC, EKGD, and EKGI.  This routine */
/*     allows the caller of those routines to determine appropriate */
/*     loop bounds to use to fetch each column entry in the current row. */

/* $ Examples */

/*     1)  Suppose the EK table TAB contains the following columns: */


/*            Column name   Data Type   Size */
/*            -----------   ---------   ---- */
/*            IARRAY        INT         10 */
/*            DARRAY        DP          VARIABLE */
/*            CARRAY        CHR         VARIABLE */


/*         Suppose the query */

/*            QUERY = 'SELECT IARRAY, DARRAY, CARRAY FROM TAB' */

/*         is issued to EKFIND via the call */

/*            CALL EKFIND ( QUERY, NMROWS, ERROR, ERRMSG ) */

/*         To fetch and dump column values from the rows that satisfy the */
/*         query, the loop below could be used.  Note that we don't check */
/*         the FOUND flags returned by the fetch routines since we know */
/*         in advance how many elements are contained in each column */
/*         entry we fetch. */


/*                  DO ROW = 1, NMROWS */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'ROW  = ', ROW */
/*                     WRITE (*,*) ' ' */

/*            C */
/*            C        Fetch values from column IARRAY in the current */
/*            C        row.  Since IARRAY was the first column selected, */
/*            C        the selection index SELIDX is set to 1. */
/*            C */
/*                     SELIDX = 1 */

/*                     ELTIDX = 1 */
/*                     ISNULL = .FALSE. */

/*                     DO WHILE ( ( ELTIDX .LE. 10 ) .AND. .NOT. ISNULL ) */
/*            C */
/*            C           If the column entry is null, we'll be kicked */
/*            C           out of this loop after the first iteration. */
/*            C */
/*                        CALL EKGI ( SELIDX,         ROW,     ELTIDX, */
/*                                    IVALS(ELTIDX),  ISNULL,  FOUND   ) */

/*                        ELTIDX = ELTIDX + 1 */

/*                     END DO */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'COLUMN = IARRAY' */
/*                     WRITE (*,*) ' ' */

/*                     IF ( ISNULL ) THEN */
/*                        WRITE (*,*) '<Null>' */
/*                     ELSE */
/*                        WRITE (*,*) ( IVALS(I), I = 1, 10 ) */
/*                     END IF */

/*            C */
/*            C        Fetch values from column DARRAY in the current */
/*            C        row.  Since DARRAY contains variable-size array */
/*            C        elements, we call EKNELT to determine how many */
/*            C        elements to fetch. */
/*            C */
/*                     SELIDX = 2 */

/*                     CALL EKNELT ( SELIDX, ROW, NELT ) */

/*                     ELTIDX = 1 */
/*                     ISNULL = .FALSE. */

/*                     DO WHILE (       ( ELTIDX .LE.  NELT   ) */
/*                 .              .AND. (        .NOT. ISNULL )  ) */

/*                        CALL EKGD ( SELIDX,         ROW,     ELTIDX, */
/*                                    DVALS(ELTIDX),  ISNULL,  FOUND   ) */

/*                        ELTIDX = ELTIDX + 1 */

/*                     END DO */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'COLUMN = DARRAY' */
/*                     WRITE (*,*) ' ' */

/*                     IF ( ISNULL ) THEN */
/*                        WRITE (*,*) '<Null>' */
/*                     ELSE */
/*                        WRITE (*,*) ( DVALS(I), I = 1, NELT ) */
/*                     END IF */

/*            C */
/*            C        Fetch values from column CARRAY in the current */
/*            C        row. */
/*            C */
/*                     SELIDX = 3 */
/*                     CALL EKNELT ( SELIDX, ROW, NELT ) */

/*                     ELTIDX = 1 */
/*                     ISNULL = .FALSE. */

/*                     DO WHILE (       ( ELTIDX .LE.  NELT   ) */
/*                 .              .AND. (        .NOT. ISNULL )  ) */

/*                        CALL EKGC ( SELIDX,         ROW,     ELTIDX, */
/*                                    CVALS(ELTIDX),  ISNULL,  FOUND   ) */

/*                        ELTIDX = ELTIDX + 1 */

/*                     END DO */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'COLUMN = CARRAY' */
/*                     WRITE (*,*) ' ' */

/*                     IF ( ISNULL ) THEN */
/*                        WRITE (*,*) '<Null>' */
/*                     ELSE */
/*                        WRITE (*,*) ( CVALS(I), I = 1, NELT ) */
/*                     END IF */

/*                  END DO */


/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (NJB) */

/*        Bug fix:   When an already loaded kernel is opened with EKOPR, */
/*        it now has its link count reset to 1 via a call to EKCLS. */

/* -    SPICELIB Version 1.2.0, 12-FEB-1999 (NJB) */

/*        Bug fix:  There was a error handling branch that called CHKOUT */
/*        where CHKIN should have been called.  This has been fixed. */

/* -    SPICELIB Version 1.1.0, 09-JUL-1996 (NJB) */

/*        Bug fix:  EKNELT now initiates a sort operation if sorted */
/*        outputs are required and EKNELT is called after query */
/*        resolution but before the fetch routines.  Also, addressing */
/*        for sorted query results has been fixed. */

/*        Misspelling of "issued" was fixed.  Previous version line was */
/*        changed from "Beta" to "SPICELIB." */


/* -    SPICELIB Version 1.0.0, 23-OCT-1995 (NJB) */

/* -& */
/* $ Index_Entries */

/*     return the number of elements in a column entry */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.2.0, 12-FEB-1999 (NJB) */

/*        Bug fix:  There was a error handling branch that called CHKOUT */
/*        where CHKIN should have been called.  This has been fixed. */

/* -    SPICELIB Version 1.1.0, 09-JUL-1996 (NJB) */

/*        Bug fix:  EKNELT now initiates a sort operation if sorted */
/*        outputs are required and EKNELT is called after query */
/*        resolution but before the fetch routines.  Also, addressing */
/*        for sorted query results has been fixed.  The fix involved */
/*        copying the sort invocation and addressing code from the */
/*        fetch routines. */

/*        Misspelling of "issued" was fixed.  Previous version line was */
/*        changed from "Beta" to "SPICELIB." */

/* -& */

/*     Use discovery check-in for speed. */

    if (return_(__global_state)) {
	return 0;
    }

/*     The request doesn't make sense if no files are loaded.  A sure */
/*     symptom of this problem is that the file list is empty. */

    if (__state->fthead <= 0) {
	chkin_(__global_state, "EKNELT", (ftnlen)6);
	setmsg_(__global_state, "No E-kernels are currently loaded.", (ftnlen)
		34);
	sigerr_(__global_state, "SPICE(NOLOADEDFILES)", (ftnlen)20);
	chkout_(__global_state, "EKNELT", (ftnlen)6);
	return 0;
    }

/*     The row number must be valid, or we can't proceed. */

    if (*row < 1 || *row > __state->unrows) {
	chkin_(__global_state, "EKNELT", (ftnlen)6);
	setmsg_(__global_state, "Row indices for query result range from 1 t"
		"o #; requested row index was #.", (ftnlen)74);
	errint_(__global_state, "#", &__state->unrows, (ftnlen)1);
	errint_(__global_state, "#", row, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDINDEX)", (ftnlen)19);
	chkout_(__global_state, "EKNELT", (ftnlen)6);
	return 0;
    }

/*     Make sure the SELECT clause column index is valid. */

    if (*selidx < 1 || *selidx > __state->nsel) {
	chkin_(__global_state, "EKNELT", (ftnlen)6);
	setmsg_(__global_state, "The SELECT column index # is out of the val"
		"id range 1:#", (ftnlen)55);
	errint_(__global_state, "#", selidx, (ftnlen)1);
	errint_(__global_state, "#", &__state->ntab, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDINDEX)", (ftnlen)19);
	chkout_(__global_state, "EKNELT", (ftnlen)6);
	return 0;
    }

/*     If it hasn't been done yet, and if it needs to be done, sort the */
/*     matching row vectors. */

    if (__state->dosort) {
	zzekjsrt_(__global_state, &__state->usize, __state->ubase, &
		__state->norder, __state->otabs, __state->ocols, 
		__state->oelts, __state->sense, __state->sthan, 
		__state->stdscs, __state->stdtpt, __state->dtpool, 
		__state->dtdscs, &__state->ordbas);
	__state->dosort = FALSE_;
	__state->sorted = TRUE_;
    }

/*     Look up the segment vector and row vector for the current row. */

    if (__state->sorted) {
	i__1 = __state->ordbas + *row;
	i__2 = __state->ordbas + *row;
	zzeksrd_(__global_state, &i__1, &i__2, &__state->i__);
	zzekvcal_(__global_state, &__state->i__, &__state->rwvbas, &
		__state->sgvbas);
    } else {
	zzekvcal_(__global_state, row, &__state->rwvbas, &__state->sgvbas);
    }
    i__1 = __state->rwvbas + 1;
    i__2 = __state->rwvbas + __state->ntab;
    zzeksrd_(__global_state, &i__1, &i__2, __state->rowvec);
    i__1 = __state->sgvbas + 1;
    i__2 = __state->sgvbas + __state->ntab;
    zzeksrd_(__global_state, &i__1, &i__2, __state->segvec);
    __state->tabidx = __state->seltab[(i__1 = *selidx - 1) < 50 && 0 <= i__1 ?
	     i__1 : s_rnge(&__global_state->f2c, "seltab", i__1, "ekqmgr_", (
	    ftnlen)4983)];
    __state->rowidx = __state->rowvec[(i__1 = __state->tabidx - 1) < 10 && 0 
	    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "rowvec", i__1, 
	    "ekqmgr_", (ftnlen)4984)];
    __state->seg = __state->segvec[(i__1 = __state->tabidx - 1) < 10 && 0 <= 
	    i__1 ? i__1 : s_rnge(&__global_state->f2c, "segvec", i__1, "ekqm"
	    "gr_", (ftnlen)4985)];
    __state->col = __state->selcol[(i__1 = *selidx - 1) < 50 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "selcol", i__1, "ekqmgr_", (
	    ftnlen)4986)];
    __state->colptr = __state->stdtpt[(i__1 = __state->seg - 1) < 200 && 0 <= 
	    i__1 ? i__1 : s_rnge(&__global_state->f2c, "stdtpt", i__1, "ekqm"
	    "gr_", (ftnlen)4988)];
    i__1 = __state->col;
    for (__state->i__ = 2; __state->i__ <= i__1; ++__state->i__) {
	__state->colptr = lnknxt_(__global_state, &__state->colptr, 
		__state->dtpool);
    }
    *nelt = zzekesiz_(__global_state, &__state->sthan[(i__1 = __state->seg - 
	    1) < 200 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "sth"
	    "an", i__1, "ekqmgr_", (ftnlen)4994)], &__state->stdscs[(i__2 = 
	    __state->seg * 24 - 24) < 4800 && 0 <= i__2 ? i__2 : s_rnge(&
	    __global_state->f2c, "stdscs", i__2, "ekqmgr_", (ftnlen)4994)], &
	    __state->dtdscs[(i__3 = __state->colptr * 11 - 11) < 110000 && 0 
	    <= i__3 ? i__3 : s_rnge(&__global_state->f2c, "dtdscs", i__3, 
	    "ekqmgr_", (ftnlen)4994)], &__state->rowidx);
    return 0;
/* $Procedure     EKGC  ( EK, get event data, character ) */

L_ekgc:
/* $ Abstract */

/*     Return an element of an entry in a column of character */
/*     type in a specified row. */

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

/*     ASSIGNMENT */
/*     EK */

/* $ Declarations */

/*     INTEGER               SELIDX */
/*     INTEGER               ROW */
/*     INTEGER               ELMENT */
/*     CHARACTER*(*)         CDATA */
/*     LOGICAL               NULL */
/*     LOGICAL               FOUND */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     SELIDX     I   Index of parent column in SELECT clause. */
/*     ROW        I   Row to fetch from. */
/*     ELMENT     I   Index of element, within column entry, to fetch. */
/*     CDATA      O   Character string element of column entry. */
/*     NULL       O   Flag indicating whether column entry was null. */
/*     FOUND      O   Flag indicating whether column was present in row. */

/* $ Detailed_Input */

/*     SELIDX         is the SELECT clause index of the column to */
/*                    fetch from. */

/*     ROW            is the output row containing the entry to fetch */
/*                    from. */

/*     ELMENT         is the index of the element of the column entry */
/*                    to fetch.  The normal range of ELMENT is from 1 to */
/*                    the size of the column's entry, but ELMENT is */
/*                    allowed to exceed the number of elements in the */
/*                    column entry; if it does, FOUND is returned .FALSE. */
/*                    This allows the caller to read data from the column */
/*                    entry in a loop without checking the number of */
/*                    available elements first. */

/*                    Null values in variable-sized columns are */
/*                    considered to have size 1. */

/* $ Detailed_Output */

/*     CDATA          is the requested element of the specified column */
/*                    entry.  If the entry is null, CDATA is undefined. */

/*                    If CDATA is too short to accommodate the requested */
/*                    column entry element, the element is truncated on */
/*                    the right to fit CDATA.  If CDATA is longer than */
/*                    the element, CDATA is returned blank-padded on */
/*                    the right. */

/*     NULL           is a logical flag indicating whether the entry */
/*                    belonging to the specified column in the specified */
/*                    row is null. */

/*     FOUND          is a logical flag indicating whether the specified */
/*                    element was found.  If the element does not exist, */
/*                    FOUND is returned .FALSE. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the input argument ELMENT is less than 1, FOUND is returned */
/*         .FALSE., and the error SPICE(INVALIDINDEX) is signaled. */
/*         However, ELMENT is allowed to be greater than the number of */
/*         elements in the specified column entry; this allows the caller */
/*         to read data from the column entry in a loop without checking */
/*         the number of available elements first.  If ELMENT is greater */
/*         than the number of available elements, FOUND is returned */
/*         .FALSE. */

/*     2)  If SELIDX is outside of the range established by the */
/*         last query passed to EKSRCH, the error SPICE(INVALIDINDEX) */
/*         will be signaled. */

/*     3)  If the input argument ROW is less than 1 or greater than */
/*         the number of rows matching the query, FOUND is returned */
/*        .FALSE., and the error SPICE(INVALIDINDEX) is signaled. */

/*     4)  If the specified column does not have character type, the */
/*         error SPICE(INVALIDTYPE) is signaled. */

/*     5)  If this routine is called when no E-kernels have been loaded, */
/*         the error SPICE(NOLOADEDFILES) is signaled. */

/* $ Files */

/*     See the header of EKQMGR for a description of files used */
/*     by this routine. */

/* $ Particulars */

/*     This routine allows retrieval of data from character columns. */

/*     This routine returns one element at a time in order to save the */
/*     caller from imposing a limit on the size of the column entries */
/*     that can be handled. */

/* $ Examples */

/*     1)  Suppose the EK table TAB contains the following columns: */

/*            Column name   Data Type   Size */
/*            -----------   ---------   ---- */
/*            CHR_COL_1     CHR         1 */
/*            CHR_COL_2     CHR         VARIABLE */
/*            CHR_COL_3     CHR         10 */


/*         Suppose the query */

/*            QUERY = 'SELECT CHR_COL_1 FROM TAB' */

/*         is issued to EKFIND via the call */

/*            CALL EKFIND ( QUERY, NMROWS, ERROR, ERRMSG ) */

/*         To fetch and dump column values from the rows that satisfy the */
/*         query, the loop below could be used.  Note that we don't check */
/*         the FOUND flags returned by EKGC since we know that every */
/*         entry in column CHR_COL_1 contains one element. */

/*            C */
/*            C     Since CHR_COL_1was the first column selected, */
/*            C     the selection index SELIDX is set to 1. */
/*            C     The column is scalar, so the element index ELTIDX */
/*            C     is set to 1.  The variable NMROWS is the number of */
/*            C     matching rows returned by EKFIND. */
/*            C */

/*                  SELIDX = 1 */
/*                  ELTIDX = 1 */

/*                  DO ROW = 1, NMROWS */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'ROW  = ', ROW */
/*                     WRITE (*,*) ' ' */

/*            C */
/*            C        Fetch values from column CHR_COL_1. */
/*            C */
/*                     CALL EKGC ( SELIDX,  ROW,     ELTIDX, */
/*                                 CVAL,    ISNULL,  FOUND   ) */

/*                     IF ( ISNULL ) THEN */
/*                        WRITE (*,*) '<Null>' */
/*                     ELSE */
/*                        WRITE (*,*) CVAL */
/*                     END IF */

/*                  END DO */



/*     2)  Suppose the EK table TAB is as in example 1, and we issue */
/*         the query */

/*            QUERY = 'SELECT CHR_COL_1, CHR_COL_2, CHR_COL_3 FROM TAB' */

/*         to EKFIND via the call */

/*            CALL EKFIND ( QUERY, NMROWS, ERROR, ERRMSG ) */

/*         To fetch and dump column values from the rows that satisfy the */
/*         query, the loop below could be used.  Note that we don't check */
/*         the FOUND flags returned by EKGC since we know in advance how */
/*         many elements are contained in each column entry we fetch. */


/*                  DO ROW = 1, NMROWS */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'ROW  = ', ROW */
/*                     WRITE (*,*) ' ' */

/*            C */
/*            C        Fetch values from column CHR_COL_1.  Since */
/*            C        CHR_COL_1 was the first column selected, the */
/*            C        selection index SELIDX is set to 1. */
/*            C */
/*                     SELIDX = 1 */
/*                     ELTIDX = 1 */
/*                     CALL EKGC ( SELIDX,    ROW,     ELTIDX, */
/*                                 CVALS(1),  ISNULL,  FOUND   ) */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'COLUMN = CHR_COL_1' */
/*                     WRITE (*,*) ' ' */

/*                     IF ( ISNULL ) THEN */
/*                        WRITE (*,*) '<Null>' */
/*                     ELSE */
/*                        WRITE (*,*) CVALS(1) */
/*                     END IF */

/*            C */
/*            C        Fetch values from column CHR_COL_2 in the current */
/*            C        row.  Since CHR_COL_2 contains variable-size array */
/*            C        elements, we call EKNELT to determine how many */
/*            C        elements to fetch. */
/*            C */
/*                     SELIDX = 2 */
/*                     CALL EKNELT ( SELIDX, ROW, NELT ) */

/*                     ELTIDX = 1 */
/*                     ISNULL = .FALSE. */

/*                     DO WHILE (       ( ELTIDX .LE.  NELT   ) */
/*                 .              .AND. (        .NOT. ISNULL )  ) */

/*                        CALL EKGC ( SELIDX,         ROW,     ELTIDX, */
/*                                    CVALS(ELTIDX),  ISNULL,  FOUND   ) */

/*                        ELTIDX = ELTIDX + 1 */

/*            C */
/*            C           If the column entry is null, we'll be kicked */
/*            C           out of this loop after the first iteration. */
/*            C */
/*                     END DO */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'COLUMN = CHR_COL_2' */
/*                     WRITE (*,*) ' ' */

/*                     IF ( ISNULL ) THEN */
/*                        WRITE (*,*) '<Null>' */
/*                     ELSE */
/*                        WRITE (*,*) ( CVALS(I), I = 1, NELT ) */
/*                     END IF */

/*            C */
/*            C        Fetch values from column CHR_COL_3 in the current */
/*            C        row.  We need not call EKNELT since we know how */
/*            C        many elements are in each column entry. */
/*            C */
/*                     SELIDX = 3 */
/*                     ELTIDX = 1 */
/*                     ISNULL = .FALSE. */

/*                     DO WHILE (       ( ELTIDX .LE.  10    ) */
/*                 .              .AND. (        .NOT. ISNULL )  ) */

/*                        CALL EKGC ( SELIDX,         ROW,     ELTIDX, */
/*                                    CVALS(ELTIDX),  ISNULL,  FOUND   ) */

/*                        ELTIDX = ELTIDX + 1 */

/*                     END DO */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'COLUMN = CHR_COL_3' */
/*                     WRITE (*,*) ' ' */

/*                     IF ( ISNULL ) THEN */
/*                        WRITE (*,*) '<Null>' */
/*                     ELSE */
/*                        WRITE (*,*) ( CVALS(I), I = 1, 10 ) */
/*                     END IF */

/*                  END DO */


/*     3)  See the $Examples section of the umbrella routine EKQMGR */
/*         for an example in which the names and data types of the */
/*         columns from which to fetch data are not known in advance. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (NJB) */

/*        Bug fix:   When an already loaded kernel is opened with EKOPR, */
/*        it now has its link count reset to 1 via a call to EKCLS. */

/* -    SPICELIB Version 1.1.0, 07-JUL-1996 (NJB) */

/*        Redundant CHKIN call removed from SELIDX error check. */
/*        Misspelling of "issued" was fixed.  Previous version line */
/*        was changed from "Beta" to "SPICELIB." */

/* -    SPICELIB Version 1.0.0, 23-OCT-1995 (NJB) */

/* -& */
/* $ Index_Entries */

/*     fetch element from character column entry */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.1.0, 07-JUL-1996 (NJB) */

/*        Redundant CHKIN call removed from SELIDX error check. */
/*        Misspelling of "issued" was fixed.  Previous version line */
/*        was changed from "Beta" to "SPICELIB." */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "EKGC", (ftnlen)4);
    }

/*     Nothing found yet. */

    *found = FALSE_;

/*     There nothing to fetch if no files are loaded.  A sure */
/*     symptom of this problem is that the file list is empty. */

    if (__state->fthead <= 0) {
	setmsg_(__global_state, "No E-kernels are currently loaded.", (ftnlen)
		34);
	sigerr_(__global_state, "SPICE(NOLOADEDFILES)", (ftnlen)20);
	chkout_(__global_state, "EKGC", (ftnlen)4);
	return 0;
    }

/*     The row number must be valid, or we can't proceed. */

    if (*row < 1 || *row > __state->unrows) {
	setmsg_(__global_state, "Row indices for query result range from 1 t"
		"o #; requested row index was #.", (ftnlen)74);
	errint_(__global_state, "#", &__state->unrows, (ftnlen)1);
	errint_(__global_state, "#", row, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDINDEX)", (ftnlen)19);
	chkout_(__global_state, "EKGC", (ftnlen)4);
	return 0;
    }

/*     The element index must be positive. */

    if (*elment < 1) {
	setmsg_(__global_state, "ELMENT must be positive but was #.", (ftnlen)
		34);
	errint_(__global_state, "#", elment, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDINDEX)", (ftnlen)19);
	chkout_(__global_state, "EKGC", (ftnlen)4);
	return 0;
    }

/*     Make sure the SELECT clause column index is valid. */

    if (*selidx < 1 || *selidx > __state->nsel) {
	setmsg_(__global_state, "The SELECT column index # is out of the val"
		"id range 1:#", (ftnlen)55);
	errint_(__global_state, "#", selidx, (ftnlen)1);
	errint_(__global_state, "#", &__state->ntab, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDINDEX)", (ftnlen)19);
	chkout_(__global_state, "EKGC", (ftnlen)4);
	return 0;
    }

/*     COL is the column's index within the parent */
/*     table's column list. */

    __state->tabidx = __state->seltab[(i__1 = *selidx - 1) < 50 && 0 <= i__1 ?
	     i__1 : s_rnge(&__global_state->f2c, "seltab", i__1, "ekqmgr_", (
	    ftnlen)5434)];
    __state->col = __state->selcol[(i__1 = *selidx - 1) < 50 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "selcol", i__1, "ekqmgr_", (
	    ftnlen)5435)];
    __state->colptr = __state->selctp[(i__1 = *selidx - 1) < 50 && 0 <= i__1 ?
	     i__1 : s_rnge(&__global_state->f2c, "selctp", i__1, "ekqmgr_", (
	    ftnlen)5436)];
    __state->tab = __state->tptvec[(i__1 = __state->tabidx + 5) < 16 && 0 <= 
	    i__1 ? i__1 : s_rnge(&__global_state->f2c, "tptvec", i__1, "ekqm"
	    "gr_", (ftnlen)5437)];

/*     Make sure the column has character type. */

    if (__state->cttyps[(i__1 = __state->colptr - 1) < 500 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "cttyps", i__1, "ekqmgr_", (
	    ftnlen)5442)] != 1) {
	setmsg_(__global_state, "Column # has data type #.", (ftnlen)25);
	errch_(__global_state, "#", __state->ctnams + (((i__1 = 
		__state->colptr - 1) < 500 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "ctnams", i__1, "ekqmgr_", (ftnlen)5445))
		 << 5), (ftnlen)1, (ftnlen)32);
	errch_(__global_state, "#", __state->chtype + (((i__2 = 
		__state->cttyps[(i__1 = __state->colptr - 1) < 500 && 0 <= 
		i__1 ? i__1 : s_rnge(&__global_state->f2c, "cttyps", i__1, 
		"ekqmgr_", (ftnlen)5446)] - 1) < 4 && 0 <= i__2 ? i__2 : 
		s_rnge(&__global_state->f2c, "chtype", i__2, "ekqmgr_", (
		ftnlen)5446)) << 2), (ftnlen)1, (ftnlen)4);
	sigerr_(__global_state, "SPICE(INVALIDTYPE)", (ftnlen)18);
	chkout_(__global_state, "EKGC", (ftnlen)4);
	return 0;
    }

/*     If it hasn't been done yet, and if it needs to be done, sort the */
/*     matching row vectors. */

    if (__state->dosort) {
	zzekjsrt_(__global_state, &__state->usize, __state->ubase, &
		__state->norder, __state->otabs, __state->ocols, 
		__state->oelts, __state->sense, __state->sthan, 
		__state->stdscs, __state->stdtpt, __state->dtpool, 
		__state->dtdscs, &__state->ordbas);
	__state->dosort = FALSE_;
	__state->sorted = TRUE_;
    }

/*     Look up the segment vector and row vector for the current row. */

    if (__state->sorted) {
	i__1 = __state->ordbas + *row;
	i__2 = __state->ordbas + *row;
	zzeksrd_(__global_state, &i__1, &i__2, &__state->i__);
	zzekvcal_(__global_state, &__state->i__, &__state->rwvbas, &
		__state->sgvbas);
    } else {
	zzekvcal_(__global_state, row, &__state->rwvbas, &__state->sgvbas);
    }
    i__1 = __state->rwvbas + 1;
    i__2 = __state->rwvbas + __state->ntab;
    zzeksrd_(__global_state, &i__1, &i__2, __state->rowvec);
    i__1 = __state->sgvbas + 1;
    i__2 = __state->sgvbas + __state->ntab;
    zzeksrd_(__global_state, &i__1, &i__2, __state->segvec);

/*     Identify the segment containing the column entry of interest. */
/*     Obtain the column descriptor for the column. */

    __state->rowidx = __state->rowvec[(i__1 = __state->tabidx - 1) < 10 && 0 
	    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "rowvec", i__1, 
	    "ekqmgr_", (ftnlen)5484)];
    __state->seg = __state->segvec[(i__1 = __state->tabidx - 1) < 10 && 0 <= 
	    i__1 ? i__1 : s_rnge(&__global_state->f2c, "segvec", i__1, "ekqm"
	    "gr_", (ftnlen)5485)];
    __state->j = __state->stdtpt[(i__1 = __state->seg - 1) < 200 && 0 <= i__1 
	    ? i__1 : s_rnge(&__global_state->f2c, "stdtpt", i__1, "ekqmgr_", (
	    ftnlen)5487)];
    i__1 = __state->col;
    for (__state->i__ = 2; __state->i__ <= i__1; ++__state->i__) {
	__state->j = lnknxt_(__global_state, &__state->j, __state->dtpool);
    }

/*     Look up the element. */

    zzekrsc_(__global_state, &__state->sthan[(i__1 = __state->seg - 1) < 200 
	    && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "sthan", i__1, 
	    "ekqmgr_", (ftnlen)5496)], &__state->stdscs[(i__2 = __state->seg *
	     24 - 24) < 4800 && 0 <= i__2 ? i__2 : s_rnge(&
	    __global_state->f2c, "stdscs", i__2, "ekqmgr_", (ftnlen)5496)], &
	    __state->dtdscs[(i__3 = __state->j * 11 - 11) < 110000 && 0 <= 
	    i__3 ? i__3 : s_rnge(&__global_state->f2c, "dtdscs", i__3, "ekqm"
	    "gr_", (ftnlen)5496)], &__state->rowidx, elment, &__state->cvlen, 
	    cdata, null, found, cdata_len);
    chkout_(__global_state, "EKGC", (ftnlen)4);
    return 0;
/* $Procedure     EKGD  ( EK, get event data, double precision ) */

L_ekgd:
/* $ Abstract */

/*     Return an element of an entry in a column of double precision */
/*     or `time' type in a specified row. */

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

/*     ASSIGNMENT */
/*     EK */

/* $ Declarations */

/*     INTEGER               SELIDX */
/*     INTEGER               ROW */
/*     INTEGER               ELMENT */
/*     DOUBLE PRECISION      DDATA */
/*     LOGICAL               NULL */
/*     LOGICAL               FOUND */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     SELIDX     I   Index of parent column in SELECT clause. */
/*     ROW        I   Row to fetch from. */
/*     ELMENT     I   Index of element, within column entry, to fetch. */
/*     DDATA      O   D.p. element of column entry. */
/*     NULL       O   Flag indicating whether column entry was null. */
/*     FOUND      O   Flag indicating whether column was present in row. */

/* $ Detailed_Input */

/*     SELIDX         is the SELECT clause index of the column to */
/*                    fetch from. */

/*     ROW            is the output row containing the entry to fetch */
/*                    from. */

/*     ELMENT         is the index of the element of the column entry */
/*                    to fetch.  The normal range of ELMENT is from 1 to */
/*                    the size of the column's entry, but ELMENT is */
/*                    allowed to exceed the number of elements in the */
/*                    column entry; if it does, FOUND is returned .FALSE. */
/*                    This allows the caller to read data from the column */
/*                    entry in a loop without checking the number of */
/*                    available elements first. */

/*                    Null values in variable-sized columns are */
/*                    considered to have size 1. */

/* $ Detailed_Output */

/*     DDATA          is the requested element of the specified column */
/*                    entry.  If the entry is null, DDATA is undefined. */

/*     NULL           is a logical flag indicating whether the entry */
/*                    belonging to the specified column in the specified */
/*                    row is null. */

/*     FOUND          is a logical flag indicating whether the specified */
/*                    element was found.  If the element does not exist, */
/*                    FOUND is returned .FALSE. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the input argument ELMENT is less than 1, FOUND is returned */
/*         .FALSE., and the error SPICE(INVALIDINDEX) is signaled. */
/*         However, ELMENT is allowed to be greater than the number of */
/*         elements in the specified column entry; this allows the caller */
/*         to read data from the column entry in a loop without checking */
/*         the number of available elements first.  If ELMENT is greater */
/*         than the number of available elements, FOUND is returned */
/*         .FALSE. */

/*     2)  If SELIDX is outside of the range established by the */
/*         last query passed to EKSRCH, the error SPICE(INVALIDINDEX) */
/*         will be signaled. */

/*     3)  If the input argument ROW is less than 1 or greater than */
/*         the number of rows matching the query, FOUND is returned */
/*        .FALSE., and the error SPICE(INVALIDINDEX) is signaled. */

/*     4)  If the specified column does not have DP or TIME type, the */
/*         error SPICE(INVALIDTYPE) is signaled. */

/*     5)  If this routine is called when no E-kernels have been loaded, */
/*         the error SPICE(NOLOADEDFILES) is signaled. */

/* $ Files */

/*     See the header of EKQMGR for a description of files used */
/*     by this routine. */

/* $ Particulars */

/*     This routine allows retrieval of data from double precision or */
/*     `time' columns. */

/*     This routine returns one element at a time in order to save the */
/*     caller from imposing a limit on the size of the column entries */
/*     that can be handled. */

/* $ Examples */

/*     1)  Suppose the EK table TAB contains the following columns: */

/*            Column name   Data Type   Size */
/*            -----------   ---------   ---- */
/*            DP_COL_1      DP          1 */
/*            DP_COL_2      DP          VARIABLE */
/*            DP_COL_3      DP          10 */
/*            TIME          TIME        1 */


/*         Suppose the query */

/*            QUERY = 'SELECT DP_COL_1 FROM TAB' */

/*         is issued to EKFIND via the call */

/*            CALL EKFIND ( QUERY, NMROWS, ERROR, ERRMSG ) */

/*         To fetch and dump column values from the rows that satisfy the */
/*         query, the loop below could be used.  Note that we don't check */
/*         the FOUND flags returned by EKGD since we know that every */
/*         entry in column DP_COL_1 contains one element. */

/*            C */
/*            C     Since DP_COL_1was the first column selected, */
/*            C     the selection index SELIDX is set to 1. */
/*            C     The column is scalar, so the element index ELTIDX */
/*            C     is set to 1.  The variable NMROWS is the number of */
/*            C     matching rows returned by EKFIND. */
/*            C */

/*                  SELIDX = 1 */
/*                  ELTIDX = 1 */

/*                  DO ROW = 1, NMROWS */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'ROW  = ', ROW */
/*                     WRITE (*,*) ' ' */

/*            C */
/*            C        Fetch values from column DP_COL_1. */
/*            C */
/*                     CALL EKGD ( SELIDX,  ROW,     ELTIDX, */
/*                                 DVAL,    ISNULL,  FOUND   ) */

/*                     IF ( ISNULL ) THEN */
/*                        WRITE (*,*) '<Null>' */
/*                     ELSE */
/*                        WRITE (*,*) DVAL */
/*                     END IF */

/*                  END DO */


/*     2)  Suppose the EK table TAB is as in example 1, and we issue */
/*         the query */

/*            QUERY = 'SELECT TIME FROM TAB' */

/*         to EKFIND via the call */

/*            CALL EKFIND ( QUERY, NMROWS, ERROR, ERRMSG ) */

/*         We wish to dump the time values as UTC calendar dates. */
/*         The code fragment below carries out this task.  We assume */
/*         a leapseconds kernel is loaded.  The variable UTC shown */
/*         below should be declared as a character string. */

/*                  SELIDX = 1 */
/*                  ELTIDX = 1 */

/*                  DO ROW = 1, NMROWS */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'ROW  = ', ROW */
/*                     WRITE (*,*) ' ' */

/*            C */
/*            C        Fetch values from column TIME. */
/*            C */
/*                     CALL EKGD ( SELIDX,  ROW,     ELTIDX, */
/*                                 DVAL,    ISNULL,  FOUND   ) */

/*                     IF ( ISNULL ) THEN */
/*                        WRITE (*,*) '<Null>' */
/*                     ELSE */
/*                        CALL ET2UTC ( DVAL, 'C', 3, UTC ) */
/*                        WRITE (*,*) UTC */
/*                     END IF */

/*                  END DO */


/*     3)  Suppose the EK table TAB is as in example 1, and we issue */
/*         the query */

/*            QUERY = 'SELECT DP_COL_1, DP_COL_2, DP_COL_3 FROM TAB' */

/*         to EKFIND via the call */

/*            CALL EKFIND ( QUERY, NMROWS, ERROR, ERRMSG ) */

/*         To fetch and dump column values from the rows that satisfy the */
/*         query, the loop below could be used.  Note that we don't check */
/*         the FOUND flags returned by EKGD since we know in advance how */
/*         many elements are contained in each column entry we fetch. */

/*                  DO ROW = 1, NMROWS */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'ROW  = ', ROW */
/*                     WRITE (*,*) ' ' */

/*            C */
/*            C        Fetch values from column DP_COL_1.  Since */
/*            C        DP_COL_1was the first column selected, the */
/*            C        selection index SELIDX is set to 1. */
/*            C */
/*                     SELIDX = 1 */
/*                     ELTIDX = 1 */
/*                     CALL EKGD ( SELIDX,    ROW,     ELTIDX, */
/*                                 DVALS(1),  ISNULL,  FOUND   ) */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'COLUMN = DP_COL_1' */
/*                     WRITE (*,*) ' ' */

/*                     IF ( ISNULL ) THEN */
/*                        WRITE (*,*) '<Null>' */
/*                     ELSE */
/*                        WRITE (*,*) DVALS(1) */
/*                     END IF */

/*            C */
/*            C        Fetch values from column DP_COL_2 in the current */
/*            C        row.  Since DP_COL_2 contains variable-size array */
/*            C        elements, we call EKNELT to determine how many */
/*            C        elements to fetch. */
/*            C */
/*                     SELIDX = 2 */
/*                     CALL EKNELT ( SELIDX, ROW, NELT ) */

/*                     ELTIDX = 1 */
/*                     ISNULL = .FALSE. */

/*                     DO WHILE (       ( ELTIDX .LE.  NELT   ) */
/*                 .              .AND. (        .NOT. ISNULL )  ) */

/*                        CALL EKGD ( SELIDX,         ROW,     ELTIDX, */
/*                                    DVALS(ELTIDX),  ISNULL,  FOUND   ) */

/*                        ELTIDX = ELTIDX + 1 */

/*            C */
/*            C           If the column entry is null, we'll be kicked */
/*            C           out of this loop after the first iteration. */
/*            C */
/*                     END DO */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'COLUMN = DP_COL_2' */
/*                     WRITE (*,*) ' ' */

/*                     IF ( ISNULL ) THEN */
/*                        WRITE (*,*) '<Null>' */
/*                     ELSE */
/*                        WRITE (*,*) ( DVALS(I), I = 1, NELT ) */
/*                     END IF */

/*            C */
/*            C        Fetch values from column DP_COL_3 in the current */
/*            C        row.  We need not call EKNELT since we know how */
/*            C        many elements are in each column entry. */
/*            C */
/*                     SELIDX = 3 */
/*                     ELTIDX = 1 */
/*                     ISNULL = .FALSE. */

/*                     DO WHILE (       ( ELTIDX .LE.  10    ) */
/*                 .              .AND. (        .NOT. ISNULL )  ) */

/*                        CALL EKGD ( SELIDX,         ROW,     ELTIDX, */
/*                                    DVALS(ELTIDX),  ISNULL,  FOUND   ) */

/*                        ELTIDX = ELTIDX + 1 */

/*                     END DO */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'COLUMN = DP_COL_3' */
/*                     WRITE (*,*) ' ' */

/*                     IF ( ISNULL ) THEN */
/*                        WRITE (*,*) '<Null>' */
/*                     ELSE */
/*                        WRITE (*,*) ( DVALS(I), I = 1, 10 ) */
/*                     END IF */

/*                  END DO */


/*     4)  See the $Examples section of the umbrella routine EKQMGR */
/*         for an example in which the names and data types of the */
/*         columns from which to fetch data are not known in advance. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (NJB) */

/*        Bug fix:   When an already loaded kernel is opened with EKOPR, */
/*        it now has its link count reset to 1 via a call to EKCLS. */

/* -    SPICELIB Version 1.1.0, 07-JUL-1996 (NJB) */

/*        Redundant CHKIN call removed from SELIDX error check. */
/*        Misspelling of "issued" was fixed.  Previous version line */
/*        was changed from "Beta" to "SPICELIB." */

/* -    SPICELIB Version 1.0.0, 23-OCT-1995 (NJB) */

/* -& */
/* $ Index_Entries */

/*     fetch element from double precision column entry */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.1.0, 07-JUL-1996 (NJB) */

/*        Redundant CHKIN call removed from SELIDX error check. */
/*        Misspelling of "issued" was fixed.  Previous version line */
/*        was changed from "Beta" to "SPICELIB." */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "EKGD", (ftnlen)4);
    }

/*     Nothing found yet. */

    *found = FALSE_;

/*     There nothing to fetch if no files are loaded.  A sure */
/*     symptom of this problem is that the file list is empty. */

    if (__state->fthead <= 0) {
	setmsg_(__global_state, "No E-kernels are currently loaded.", (ftnlen)
		34);
	sigerr_(__global_state, "SPICE(NOLOADEDFILES)", (ftnlen)20);
	chkout_(__global_state, "EKGD", (ftnlen)4);
	return 0;
    }

/*     The row number must be valid, or we can't proceed. */

    if (*row < 1 || *row > __state->unrows) {
	setmsg_(__global_state, "Row indices for query result range from 1 t"
		"o #; requested row index was #.", (ftnlen)74);
	errint_(__global_state, "#", &__state->unrows, (ftnlen)1);
	errint_(__global_state, "#", row, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDINDEX)", (ftnlen)19);
	chkout_(__global_state, "EKGD", (ftnlen)4);
	return 0;
    }

/*     The element index must be positive. */

    if (*elment < 1) {
	setmsg_(__global_state, "ELMENT must be positive but was #.", (ftnlen)
		34);
	errint_(__global_state, "#", elment, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDINDEX)", (ftnlen)19);
	chkout_(__global_state, "EKGD", (ftnlen)4);
	return 0;
    }

/*     Make sure the SELECT clause column index is valid. */

    if (*selidx < 1 || *selidx > __state->nsel) {
	setmsg_(__global_state, "The SELECT column index # is out of the val"
		"id range 1:#", (ftnlen)55);
	errint_(__global_state, "#", selidx, (ftnlen)1);
	errint_(__global_state, "#", &__state->ntab, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDINDEX)", (ftnlen)19);
	chkout_(__global_state, "EKGD", (ftnlen)4);
	return 0;
    }

/*     COL is the column's index within the parent */
/*     table's column list. */

    __state->tabidx = __state->seltab[(i__1 = *selidx - 1) < 50 && 0 <= i__1 ?
	     i__1 : s_rnge(&__global_state->f2c, "seltab", i__1, "ekqmgr_", (
	    ftnlen)5978)];
    __state->col = __state->selcol[(i__1 = *selidx - 1) < 50 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "selcol", i__1, "ekqmgr_", (
	    ftnlen)5979)];
    __state->colptr = __state->selctp[(i__1 = *selidx - 1) < 50 && 0 <= i__1 ?
	     i__1 : s_rnge(&__global_state->f2c, "selctp", i__1, "ekqmgr_", (
	    ftnlen)5980)];
    __state->tab = __state->tptvec[(i__1 = __state->tabidx + 5) < 16 && 0 <= 
	    i__1 ? i__1 : s_rnge(&__global_state->f2c, "tptvec", i__1, "ekqm"
	    "gr_", (ftnlen)5981)];

/*     Make sure the column has double precision or `time' type. */

    if (__state->cttyps[(i__1 = __state->colptr - 1) < 500 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "cttyps", i__1, "ekqmgr_", (
	    ftnlen)5986)] != 2 && __state->cttyps[(i__2 = __state->colptr - 1)
	     < 500 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "cttyps"
	    , i__2, "ekqmgr_", (ftnlen)5986)] != 4) {
	setmsg_(__global_state, "Column # has data type #.", (ftnlen)25);
	errch_(__global_state, "#", __state->ctnams + (((i__1 = 
		__state->colptr - 1) < 500 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "ctnams", i__1, "ekqmgr_", (ftnlen)5990))
		 << 5), (ftnlen)1, (ftnlen)32);
	errch_(__global_state, "#", __state->chtype + (((i__2 = 
		__state->cttyps[(i__1 = __state->colptr - 1) < 500 && 0 <= 
		i__1 ? i__1 : s_rnge(&__global_state->f2c, "cttyps", i__1, 
		"ekqmgr_", (ftnlen)5991)] - 1) < 4 && 0 <= i__2 ? i__2 : 
		s_rnge(&__global_state->f2c, "chtype", i__2, "ekqmgr_", (
		ftnlen)5991)) << 2), (ftnlen)1, (ftnlen)4);
	sigerr_(__global_state, "SPICE(INVALIDTYPE)", (ftnlen)18);
	chkout_(__global_state, "EKGD", (ftnlen)4);
	return 0;
    }

/*     If it hasn't been done yet, and if it needs to be done, sort the */
/*     matching row vectors. */

    if (__state->dosort) {
	zzekjsrt_(__global_state, &__state->usize, __state->ubase, &
		__state->norder, __state->otabs, __state->ocols, 
		__state->oelts, __state->sense, __state->sthan, 
		__state->stdscs, __state->stdtpt, __state->dtpool, 
		__state->dtdscs, &__state->ordbas);
	__state->dosort = FALSE_;
	__state->sorted = TRUE_;
    }

/*     Look up the segment vector and row vector for the current row. */

    if (__state->sorted) {
	i__1 = __state->ordbas + *row;
	i__2 = __state->ordbas + *row;
	zzeksrd_(__global_state, &i__1, &i__2, &__state->i__);
	zzekvcal_(__global_state, &__state->i__, &__state->rwvbas, &
		__state->sgvbas);
    } else {
	zzekvcal_(__global_state, row, &__state->rwvbas, &__state->sgvbas);
    }
    i__1 = __state->rwvbas + 1;
    i__2 = __state->rwvbas + __state->ntab;
    zzeksrd_(__global_state, &i__1, &i__2, __state->rowvec);
    i__1 = __state->sgvbas + 1;
    i__2 = __state->sgvbas + __state->ntab;
    zzeksrd_(__global_state, &i__1, &i__2, __state->segvec);

/*     Identify the segment containing the column entry of interest. */
/*     Obtain the column descriptor for the column. */

    __state->rowidx = __state->rowvec[(i__1 = __state->tabidx - 1) < 10 && 0 
	    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "rowvec", i__1, 
	    "ekqmgr_", (ftnlen)6029)];
    __state->seg = __state->segvec[(i__1 = __state->tabidx - 1) < 10 && 0 <= 
	    i__1 ? i__1 : s_rnge(&__global_state->f2c, "segvec", i__1, "ekqm"
	    "gr_", (ftnlen)6030)];
    __state->j = __state->stdtpt[(i__1 = __state->seg - 1) < 200 && 0 <= i__1 
	    ? i__1 : s_rnge(&__global_state->f2c, "stdtpt", i__1, "ekqmgr_", (
	    ftnlen)6032)];
    i__1 = __state->col;
    for (__state->i__ = 2; __state->i__ <= i__1; ++__state->i__) {
	__state->j = lnknxt_(__global_state, &__state->j, __state->dtpool);
    }

/*     Look up the element. */

    zzekrsd_(__global_state, &__state->sthan[(i__1 = __state->seg - 1) < 200 
	    && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "sthan", i__1, 
	    "ekqmgr_", (ftnlen)6041)], &__state->stdscs[(i__2 = __state->seg *
	     24 - 24) < 4800 && 0 <= i__2 ? i__2 : s_rnge(&
	    __global_state->f2c, "stdscs", i__2, "ekqmgr_", (ftnlen)6041)], &
	    __state->dtdscs[(i__3 = __state->j * 11 - 11) < 110000 && 0 <= 
	    i__3 ? i__3 : s_rnge(&__global_state->f2c, "dtdscs", i__3, "ekqm"
	    "gr_", (ftnlen)6041)], &__state->rowidx, elment, ddata, null, 
	    found);
    chkout_(__global_state, "EKGD", (ftnlen)4);
    return 0;
/* $Procedure     EKGI  ( EK, get event data, integer ) */

L_ekgi:
/* $ Abstract */

/*     Return an element of an entry in a column of integer */
/*     type in a specified row. */

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

/*     ASSIGNMENT */
/*     EK */

/* $ Declarations */

/*     INTEGER               SELIDX */
/*     INTEGER               ROW */
/*     INTEGER               ELMENT */
/*     INTEGER               IDATA */
/*     LOGICAL               NULL */
/*     LOGICAL               FOUND */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     SELIDX     I   Index of parent column in SELECT clause. */
/*     ROW        I   Row to fetch from. */
/*     ELMENT     I   Index of element, within column entry, to fetch. */
/*     IDATA      O   Integer element of column entry. */
/*     NULL       O   Flag indicating whether column entry was null. */
/*     FOUND      O   Flag indicating whether column was present in row. */

/* $ Detailed_Input */

/*     SELIDX         is the SELECT clause index of the column to */
/*                    fetch from. */

/*     ROW            is the output row containing the entry to fetch */
/*                    from. */

/*     ELMENT         is the index of the element of the column entry */
/*                    to fetch.  The normal range of ELMENT is from 1 to */
/*                    the size of the column's entry, but ELMENT is */
/*                    allowed to exceed the number of elements in the */
/*                    column entry; if it does, FOUND is returned .FALSE. */
/*                    This allows the caller to read data from the column */
/*                    entry in a loop without checking the number of */
/*                    available elements first. */

/*                    Null values in variable-sized columns are */
/*                    considered to have size 1. */

/* $ Detailed_Output */

/*     IDATA          is the requested element of the specified column */
/*                    entry.  If the entry is null, IDATA is undefined. */

/*     NULL           is a logical flag indicating whether the entry */
/*                    belonging to the specified column in the specified */
/*                    row is null. */

/*     FOUND          is a logical flag indicating whether the specified */
/*                    element was found.  If the element does not exist, */
/*                    FOUND is returned .FALSE. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the input argument ELMENT is less than 1, FOUND is returned */
/*         .FALSE., and the error SPICE(INVALIDINDEX) is signaled. */
/*         However, ELMENT is allowed to be greater than the number of */
/*         elements in the specified column entry; this allows the caller */
/*         to read data from the column entry in a loop without checking */
/*         the number of available elements first.  If ELMENT is greater */
/*         than the number of available elements, FOUND is returned */
/*         .FALSE. */

/*     2)  If SELIDX is outside of the range established by the */
/*         last query passed to EKSRCH, the error SPICE(INVALIDINDEX) */
/*         will be signaled. */

/*     3)  If the input argument ROW is less than 1 or greater than */
/*         the number of rows matching the query, FOUND is returned */
/*        .FALSE., and the error SPICE(INVALIDINDEX) is signaled. */

/*     4)  If the specified column does not have integer type, the */
/*         error SPICE(INVALIDTYPE) is signaled. */

/*     5)  If this routine is called when no E-kernels have been loaded, */
/*         the error SPICE(NOLOADEDFILES) is signaled. */

/* $ Files */

/*     See the header of EKQMGR for a description of files used */
/*     by this routine. */

/* $ Particulars */

/*     This routine allows retrieval of data from integer columns. */

/*     This routine returns one element at a time in order to save the */
/*     caller from imposing a limit on the size of the column entries */
/*     that can be handled. */

/* $ Examples */

/*     1)  Suppose the EK table TAB contains the following columns: */

/*            Column name   Data Type   Size */
/*            -----------   ---------   ---- */
/*            INT_COL_1     INT         1 */
/*            INT_COL_2     INT         VARIABLE */
/*            INT_COL_3     INT         10 */


/*         Suppose the query */

/*            QUERY = 'SELECT INT_COL_1 FROM TAB' */

/*         is issued to EKFIND via the call */

/*            CALL EKFIND ( QUERY, NMROWS, ERROR, ERRMSG ) */

/*         To fetch and dump column values from the rows that satisfy the */
/*         query, the loop below could be used.  Note that we don't check */
/*         the FOUND flags returned by EKGI since we know that every */
/*         entry in column INT_COL_1 contains one element. */

/*            C */
/*            C     Since INT_COL_1was the first column selected, */
/*            C     the selection index SELIDX is set to 1. */
/*            C     The column is scalar, so the element index ELTIDX */
/*            C     is set to 1.  The variable NMROWS is the number of */
/*            C     matching rows returned by EKFIND. */
/*            C */

/*                  SELIDX = 1 */
/*                  ELTIDX = 1 */

/*                  DO ROW = 1, NMROWS */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'ROW  = ', ROW */
/*                     WRITE (*,*) ' ' */

/*            C */
/*            C        Fetch values from column INT_COL_1. */
/*            C */
/*                     CALL EKGI ( SELIDX,  ROW,     ELTIDX, */
/*                                 IVAL,    ISNULL,  FOUND   ) */

/*                     IF ( ISNULL ) THEN */
/*                        WRITE (*,*) '<Null>' */
/*                     ELSE */
/*                        WRITE (*,*) IVAL */
/*                     END IF */

/*                  END DO */



/*     2)  Suppose the EK table TAB is as in example 1, and we issue */
/*         the query */

/*            QUERY = 'SELECT INT_COL_1, INT_COL_2, INT_COL_3 FROM TAB' */

/*         to EKFIND via the call */

/*            CALL EKFIND ( QUERY, NMROWS, ERROR, ERRMSG ) */

/*         To fetch and dump column values from the rows that satisfy the */
/*         query, the loop below could be used.  Note that we don't check */
/*         the FOUND flags returned by EKGI since we know in advance how */
/*         many elements are contained in each column entry we fetch. */


/*                  DO ROW = 1, NMROWS */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'ROW  = ', ROW */
/*                     WRITE (*,*) ' ' */

/*            C */
/*            C        Fetch values from column INT_COL_1.  Since */
/*            C        INT_COL_1 was the first column selected, the */
/*            C        selection index SELIDX is set to 1. */
/*            C */
/*                     SELIDX = 1 */
/*                     ELTIDX = 1 */
/*                     CALL EKGI ( SELIDX,    ROW,     ELTIDX, */
/*                                 IVALS(1),  ISNULL,  FOUND   ) */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'COLUMN = INT_COL_1' */
/*                     WRITE (*,*) ' ' */

/*                     IF ( ISNULL ) THEN */
/*                        WRITE (*,*) '<Null>' */
/*                     ELSE */
/*                        WRITE (*,*) IVALS(1) */
/*                     END IF */

/*            C */
/*            C        Fetch values from column INT_COL_2 in the current */
/*            C        row.  Since INT_COL_2 contains variable-size array */
/*            C        elements, we call EKNELT to determine how many */
/*            C        elements to fetch. */
/*            C */
/*                     SELIDX = 2 */
/*                     CALL EKNELT ( SELIDX, ROW, NELT ) */

/*                     ELTIDX = 1 */
/*                     ISNULL = .FALSE. */

/*                     DO WHILE (       ( ELTIDX .LE.  NELT   ) */
/*                 .              .AND. (        .NOT. ISNULL )  ) */

/*                        CALL EKGI ( SELIDX,         ROW,     ELTIDX, */
/*                                    IVALS(ELTIDX),  ISNULL,  FOUND   ) */

/*                        ELTIDX = ELTIDX + 1 */

/*            C */
/*            C           If the column entry is null, we'll be kicked */
/*            C           out of this loop after the first iteration. */
/*            C */
/*                     END DO */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'COLUMN = INT_COL_2' */
/*                     WRITE (*,*) ' ' */

/*                     IF ( ISNULL ) THEN */
/*                        WRITE (*,*) '<Null>' */
/*                     ELSE */
/*                        WRITE (*,*) ( IVALS(I), I = 1, NELT ) */
/*                     END IF */

/*            C */
/*            C        Fetch values from column INT_COL_3 in the current */
/*            C        row.  We need not call EKNELT since we know how */
/*            C        many elements are in each column entry. */
/*            C */
/*                     SELIDX = 3 */
/*                     ELTIDX = 1 */
/*                     ISNULL = .FALSE. */

/*                     DO WHILE (       ( ELTIDX .LE.  10    ) */
/*                 .              .AND. (        .NOT. ISNULL )  ) */

/*                        CALL EKGI ( SELIDX,         ROW,     ELTIDX, */
/*                                    IVALS(ELTIDX),  ISNULL,  FOUND   ) */

/*                        ELTIDX = ELTIDX + 1 */

/*                     END DO */

/*                     WRITE (*,*) ' ' */
/*                     WRITE (*,*) 'COLUMN = INT_COL_3' */
/*                     WRITE (*,*) ' ' */

/*                     IF ( ISNULL ) THEN */
/*                        WRITE (*,*) '<Null>' */
/*                     ELSE */
/*                        WRITE (*,*) ( IVALS(I), I = 1, 10 ) */
/*                     END IF */

/*                  END DO */


/*     3)  See the $Examples section of the umbrella routine EKQMGR */
/*         for an example in which the names and data types of the */
/*         columns from which to fetch data are not known in advance. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.1, 22-SEP-2004 (EDW) */

/*        Edited 1.1.0 Version entry to not include */
/*        the token used to mark the $Procedure section. */

/* -    SPICELIB Version 2.0.0, 16-NOV-2001 (NJB) */

/*        Bug fix:   When an already loaded kernel is opened with EKOPR, */
/*        it now has its link count reset to 1 via a call to EKCLS. */

/* -    SPICELIB Version 1.1.0, 07-JUL-1996 (NJB) */

/*        Redundant CHKIN call removed from SELIDX error check. */
/*        Misspelling of "issued" was fixed.  Previous version line */
/*        was changed from "Beta" to "SPICELIB."  Header $Procedure */
/*        line was corrected to indicate integer data type. */

/* -    SPICELIB Version 1.0.0, 23-OCT-1995 (NJB) */

/* -& */
/* $ Index_Entries */

/*     fetch element from integer column entry */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.1.1, 22-SEP-2004 (EDW) */

/*        Edited 1.1.0 Version entry to not include */
/*        the token used to mark the $Procedure section. */

/* -    SPICELIB Version 1.1.0, 07-JUL-1996 (NJB) */

/*        Redundant CHKIN call removed from SELIDX error check. */
/*        Misspelling of "issued" was fixed.  Previous version line */
/*        was changed from "Beta" to "SPICELIB."  Header $Procedure */
/*        line was corrected to indicate integer data type. */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "EKGI", (ftnlen)4);
    }

/*     Nothing found yet. */

    *found = FALSE_;

/*     There nothing to fetch if no files are loaded.  A sure */
/*     symptom of this problem is that the file list is empty. */

    if (__state->fthead <= 0) {
	setmsg_(__global_state, "No E-kernels are currently loaded.", (ftnlen)
		34);
	sigerr_(__global_state, "SPICE(NOLOADEDFILES)", (ftnlen)20);
	chkout_(__global_state, "EKGI", (ftnlen)4);
	return 0;
    }

/*     The row number must be valid, or we can't proceed. */

    if (*row < 1 || *row > __state->unrows) {
	setmsg_(__global_state, "Row indices for query result range from 1 t"
		"o #; requested row index was #.", (ftnlen)74);
	errint_(__global_state, "#", &__state->unrows, (ftnlen)1);
	errint_(__global_state, "#", row, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDINDEX)", (ftnlen)19);
	chkout_(__global_state, "EKGI", (ftnlen)4);
	return 0;
    }

/*     The element index must be positive. */

    if (*elment < 1) {
	setmsg_(__global_state, "ELMENT must be positive but was #.", (ftnlen)
		34);
	errint_(__global_state, "#", elment, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDINDEX)", (ftnlen)19);
	chkout_(__global_state, "EKGI", (ftnlen)4);
	return 0;
    }

/*     Make sure the SELECT clause column index is valid. */

    if (*selidx < 1 || *selidx > __state->nsel) {
	setmsg_(__global_state, "The SELECT column index # is out of the val"
		"id range 1:#", (ftnlen)55);
	errint_(__global_state, "#", selidx, (ftnlen)1);
	errint_(__global_state, "#", &__state->ntab, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDINDEX)", (ftnlen)19);
	chkout_(__global_state, "EKGI", (ftnlen)4);
	return 0;
    }

/*     COL is the column's index within the parent */
/*     table's column list. */

    __state->tabidx = __state->seltab[(i__1 = *selidx - 1) < 50 && 0 <= i__1 ?
	     i__1 : s_rnge(&__global_state->f2c, "seltab", i__1, "ekqmgr_", (
	    ftnlen)6494)];
    __state->col = __state->selcol[(i__1 = *selidx - 1) < 50 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "selcol", i__1, "ekqmgr_", (
	    ftnlen)6495)];
    __state->colptr = __state->selctp[(i__1 = *selidx - 1) < 50 && 0 <= i__1 ?
	     i__1 : s_rnge(&__global_state->f2c, "selctp", i__1, "ekqmgr_", (
	    ftnlen)6496)];
    __state->tab = __state->tptvec[(i__1 = __state->tabidx + 5) < 16 && 0 <= 
	    i__1 ? i__1 : s_rnge(&__global_state->f2c, "tptvec", i__1, "ekqm"
	    "gr_", (ftnlen)6497)];

/*     Make sure the column has integer type. */

    if (__state->cttyps[(i__1 = __state->colptr - 1) < 500 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "cttyps", i__1, "ekqmgr_", (
	    ftnlen)6502)] != 3) {
	setmsg_(__global_state, "Column # has data type #.", (ftnlen)25);
	errch_(__global_state, "#", __state->ctnams + (((i__1 = 
		__state->colptr - 1) < 500 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "ctnams", i__1, "ekqmgr_", (ftnlen)6505))
		 << 5), (ftnlen)1, (ftnlen)32);
	errch_(__global_state, "#", __state->chtype + (((i__2 = 
		__state->cttyps[(i__1 = __state->colptr - 1) < 500 && 0 <= 
		i__1 ? i__1 : s_rnge(&__global_state->f2c, "cttyps", i__1, 
		"ekqmgr_", (ftnlen)6506)] - 1) < 4 && 0 <= i__2 ? i__2 : 
		s_rnge(&__global_state->f2c, "chtype", i__2, "ekqmgr_", (
		ftnlen)6506)) << 2), (ftnlen)1, (ftnlen)4);
	sigerr_(__global_state, "SPICE(INVALIDTYPE)", (ftnlen)18);
	chkout_(__global_state, "EKGI", (ftnlen)4);
	return 0;
    }

/*     If it hasn't been done yet, and if it needs to be done, sort the */
/*     matching row vectors. */

    if (__state->dosort) {
	zzekjsrt_(__global_state, &__state->usize, __state->ubase, &
		__state->norder, __state->otabs, __state->ocols, 
		__state->oelts, __state->sense, __state->sthan, 
		__state->stdscs, __state->stdtpt, __state->dtpool, 
		__state->dtdscs, &__state->ordbas);
	__state->dosort = FALSE_;
	__state->sorted = TRUE_;
    }

/*     Look up the segment vector and row vector for the current row. */

    if (__state->sorted) {
	i__1 = __state->ordbas + *row;
	i__2 = __state->ordbas + *row;
	zzeksrd_(__global_state, &i__1, &i__2, &__state->i__);
	zzekvcal_(__global_state, &__state->i__, &__state->rwvbas, &
		__state->sgvbas);
    } else {
	zzekvcal_(__global_state, row, &__state->rwvbas, &__state->sgvbas);
    }
    i__1 = __state->rwvbas + 1;
    i__2 = __state->rwvbas + __state->ntab;
    zzeksrd_(__global_state, &i__1, &i__2, __state->rowvec);
    i__1 = __state->sgvbas + 1;
    i__2 = __state->sgvbas + __state->ntab;
    zzeksrd_(__global_state, &i__1, &i__2, __state->segvec);

/*     Identify the segment containing the column entry of interest. */
/*     Obtain the column descriptor for the column. */

    __state->rowidx = __state->rowvec[(i__1 = __state->tabidx - 1) < 10 && 0 
	    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "rowvec", i__1, 
	    "ekqmgr_", (ftnlen)6544)];
    __state->seg = __state->segvec[(i__1 = __state->tabidx - 1) < 10 && 0 <= 
	    i__1 ? i__1 : s_rnge(&__global_state->f2c, "segvec", i__1, "ekqm"
	    "gr_", (ftnlen)6545)];
    __state->j = __state->stdtpt[(i__1 = __state->seg - 1) < 200 && 0 <= i__1 
	    ? i__1 : s_rnge(&__global_state->f2c, "stdtpt", i__1, "ekqmgr_", (
	    ftnlen)6547)];
    i__1 = __state->col;
    for (__state->i__ = 2; __state->i__ <= i__1; ++__state->i__) {
	__state->j = lnknxt_(__global_state, &__state->j, __state->dtpool);
    }

/*     Look up the element. */

    zzekrsi_(__global_state, &__state->sthan[(i__1 = __state->seg - 1) < 200 
	    && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "sthan", i__1, 
	    "ekqmgr_", (ftnlen)6556)], &__state->stdscs[(i__2 = __state->seg *
	     24 - 24) < 4800 && 0 <= i__2 ? i__2 : s_rnge(&
	    __global_state->f2c, "stdscs", i__2, "ekqmgr_", (ftnlen)6556)], &
	    __state->dtdscs[(i__3 = __state->j * 11 - 11) < 110000 && 0 <= 
	    i__3 ? i__3 : s_rnge(&__global_state->f2c, "dtdscs", i__3, "ekqm"
	    "gr_", (ftnlen)6556)], &__state->rowidx, elment, idata, null, 
	    found);
    chkout_(__global_state, "EKGI", (ftnlen)4);
    return 0;
} /* ekqmgr_ */

/* Subroutine */ int ekqmgr_(cspice_t* __global_state, integer *cindex, 
	integer *elment, char *eqryc, doublereal *eqryd, integer *eqryi, char 
	*fname, integer *row, integer *selidx, char *column, integer *handle, 
	integer *n, char *table, integer *attdsc, integer *ccount, logical *
	found, integer *nelt, integer *nmrows, logical *semerr, char *errmsg, 
	char *cdata, doublereal *ddata, integer *idata, logical *null, ftnlen 
	eqryc_len, ftnlen fname_len, ftnlen column_len, ftnlen table_len, 
	ftnlen errmsg_len, ftnlen cdata_len)
{
    return ekqmgr_0_(__global_state, 0, cindex, elment, eqryc, eqryd, eqryi, 
	    fname, row, selidx, column, handle, n, table, attdsc, ccount, 
	    found, nelt, nmrows, semerr, errmsg, cdata, ddata, idata, null, 
	    eqryc_len, fname_len, column_len, table_len, errmsg_len, 
	    cdata_len);
    }

/* Subroutine */ int eklef_(cspice_t* __global_state, char *fname, integer *
	handle, ftnlen fname_len)
{
    return ekqmgr_0_(__global_state, 1, (integer *)0, (integer *)0, (char *)0,
	     (doublereal *)0, (integer *)0, fname, (integer *)0, (integer *)0,
	     (char *)0, handle, (integer *)0, (char *)0, (integer *)0, (
	    integer *)0, (logical *)0, (integer *)0, (integer *)0, (logical *)
	    0, (char *)0, (char *)0, (doublereal *)0, (integer *)0, (logical *
	    )0, (ftnint)0, fname_len, (ftnint)0, (ftnint)0, (ftnint)0, (
	    ftnint)0);
    }

/* Subroutine */ int ekuef_(cspice_t* __global_state, integer *handle)
{
    return ekqmgr_0_(__global_state, 2, (integer *)0, (integer *)0, (char *)0,
	     (doublereal *)0, (integer *)0, (char *)0, (integer *)0, (integer 
	    *)0, (char *)0, handle, (integer *)0, (char *)0, (integer *)0, (
	    integer *)0, (logical *)0, (integer *)0, (integer *)0, (logical *)
	    0, (char *)0, (char *)0, (doublereal *)0, (integer *)0, (logical *
	    )0, (ftnint)0, (ftnint)0, (ftnint)0, (ftnint)0, (ftnint)0, (
	    ftnint)0);
    }

/* Subroutine */ int ekntab_(cspice_t* __global_state, integer *n)
{
    return ekqmgr_0_(__global_state, 3, (integer *)0, (integer *)0, (char *)0,
	     (doublereal *)0, (integer *)0, (char *)0, (integer *)0, (integer 
	    *)0, (char *)0, (integer *)0, n, (char *)0, (integer *)0, (
	    integer *)0, (logical *)0, (integer *)0, (integer *)0, (logical *)
	    0, (char *)0, (char *)0, (doublereal *)0, (integer *)0, (logical *
	    )0, (ftnint)0, (ftnint)0, (ftnint)0, (ftnint)0, (ftnint)0, (
	    ftnint)0);
    }

/* Subroutine */ int ektnam_(cspice_t* __global_state, integer *n, char *
	table, ftnlen table_len)
{
    return ekqmgr_0_(__global_state, 4, (integer *)0, (integer *)0, (char *)0,
	     (doublereal *)0, (integer *)0, (char *)0, (integer *)0, (integer 
	    *)0, (char *)0, (integer *)0, n, table, (integer *)0, (integer *)
	    0, (logical *)0, (integer *)0, (integer *)0, (logical *)0, (char *
	    )0, (char *)0, (doublereal *)0, (integer *)0, (logical *)0, (
	    ftnint)0, (ftnint)0, (ftnint)0, table_len, (ftnint)0, (ftnint)0);
    }

/* Subroutine */ int ekccnt_(cspice_t* __global_state, char *table, integer *
	ccount, ftnlen table_len)
{
    return ekqmgr_0_(__global_state, 5, (integer *)0, (integer *)0, (char *)0,
	     (doublereal *)0, (integer *)0, (char *)0, (integer *)0, (integer 
	    *)0, (char *)0, (integer *)0, (integer *)0, table, (integer *)0, 
	    ccount, (logical *)0, (integer *)0, (integer *)0, (logical *)0, (
	    char *)0, (char *)0, (doublereal *)0, (integer *)0, (logical *)0, 
	    (ftnint)0, (ftnint)0, (ftnint)0, table_len, (ftnint)0, (ftnint)0);
    }

/* Subroutine */ int ekcii_(cspice_t* __global_state, char *table, integer *
	cindex, char *column, integer *attdsc, ftnlen table_len, ftnlen 
	column_len)
{
    return ekqmgr_0_(__global_state, 6, cindex, (integer *)0, (char *)0, (
	    doublereal *)0, (integer *)0, (char *)0, (integer *)0, (integer *)
	    0, column, (integer *)0, (integer *)0, table, attdsc, (integer *)
	    0, (logical *)0, (integer *)0, (integer *)0, (logical *)0, (char *
	    )0, (char *)0, (doublereal *)0, (integer *)0, (logical *)0, (
	    ftnint)0, (ftnint)0, column_len, table_len, (ftnint)0, (ftnint)0);
    }

/* Subroutine */ int eksrch_(cspice_t* __global_state, integer *eqryi, char *
	eqryc, doublereal *eqryd, integer *nmrows, logical *semerr, char *
	errmsg, ftnlen eqryc_len, ftnlen errmsg_len)
{
    return ekqmgr_0_(__global_state, 7, (integer *)0, (integer *)0, eqryc, 
	    eqryd, eqryi, (char *)0, (integer *)0, (integer *)0, (char *)0, (
	    integer *)0, (integer *)0, (char *)0, (integer *)0, (integer *)0, 
	    (logical *)0, (integer *)0, nmrows, semerr, errmsg, (char *)0, (
	    doublereal *)0, (integer *)0, (logical *)0, eqryc_len, (ftnint)0, 
	    (ftnint)0, (ftnint)0, errmsg_len, (ftnint)0);
    }

/* Subroutine */ int eknelt_(cspice_t* __global_state, integer *selidx, 
	integer *row, integer *nelt)
{
    return ekqmgr_0_(__global_state, 8, (integer *)0, (integer *)0, (char *)0,
	     (doublereal *)0, (integer *)0, (char *)0, row, selidx, (char *)0,
	     (integer *)0, (integer *)0, (char *)0, (integer *)0, (integer *)
	    0, (logical *)0, nelt, (integer *)0, (logical *)0, (char *)0, (
	    char *)0, (doublereal *)0, (integer *)0, (logical *)0, (ftnint)0, 
	    (ftnint)0, (ftnint)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

/* Subroutine */ int ekgc_(cspice_t* __global_state, integer *selidx, integer 
	*row, integer *elment, char *cdata, logical *null, logical *found, 
	ftnlen cdata_len)
{
    return ekqmgr_0_(__global_state, 9, (integer *)0, elment, (char *)0, (
	    doublereal *)0, (integer *)0, (char *)0, row, selidx, (char *)0, (
	    integer *)0, (integer *)0, (char *)0, (integer *)0, (integer *)0, 
	    found, (integer *)0, (integer *)0, (logical *)0, (char *)0, cdata,
	     (doublereal *)0, (integer *)0, null, (ftnint)0, (ftnint)0, (
	    ftnint)0, (ftnint)0, (ftnint)0, cdata_len);
    }

/* Subroutine */ int ekgd_(cspice_t* __global_state, integer *selidx, integer 
	*row, integer *elment, doublereal *ddata, logical *null, logical *
	found)
{
    return ekqmgr_0_(__global_state, 10, (integer *)0, elment, (char *)0, (
	    doublereal *)0, (integer *)0, (char *)0, row, selidx, (char *)0, (
	    integer *)0, (integer *)0, (char *)0, (integer *)0, (integer *)0, 
	    found, (integer *)0, (integer *)0, (logical *)0, (char *)0, (char 
	    *)0, ddata, (integer *)0, null, (ftnint)0, (ftnint)0, (ftnint)0, (
	    ftnint)0, (ftnint)0, (ftnint)0);
    }

/* Subroutine */ int ekgi_(cspice_t* __global_state, integer *selidx, integer 
	*row, integer *elment, integer *idata, logical *null, logical *found)
{
    return ekqmgr_0_(__global_state, 11, (integer *)0, elment, (char *)0, (
	    doublereal *)0, (integer *)0, (char *)0, row, selidx, (char *)0, (
	    integer *)0, (integer *)0, (char *)0, (integer *)0, (integer *)0, 
	    found, (integer *)0, (integer *)0, (logical *)0, (char *)0, (char 
	    *)0, (doublereal *)0, idata, null, (ftnint)0, (ftnint)0, (ftnint)
	    0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

