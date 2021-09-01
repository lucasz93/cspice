/* zzekvadr.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzekvadr_init_t __zzekvadr_init;
static zzekvadr_state_t* get_zzekvadr_state(cspice_t* state) {
	if (!state->zzekvadr)
		state->zzekvadr = __cspice_allocate_module(sizeof(
	zzekvadr_state_t), &__zzekvadr_init, sizeof(__zzekvadr_init));
	return state->zzekvadr;

}

/* $Procedure  ZZEKVADR  ( Compute row vector address ) */
/* Subroutine */ int zzekvadr_0_(cspice_t* __global_state, int n__, integer *
	njrs, integer *bases, integer *rwvidx, integer *rwvbas, integer *
	sgvbas)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);

    /* Local variables */
    extern /* Subroutine */ int zzekstop_(cspice_t*, integer *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int cleari_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern integer lstlei_(cspice_t*, integer *, integer *, integer *);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int zzeksrd_(cspice_t*, integer *, integer *, 
	    integer *);


    /* Module state */
    zzekvadr_state_t* __state = get_zzekvadr_state(__global_state);
/* $ Abstract */

/*     Given a union of EK join row sets and a row vector index, */
/*     compute the EK scratch area base address of the row vector having */
/*     the specified index.  Also return the base address of the row */
/*     vector's parent segment vector. */

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
/* $ Brief_I/O */

/*     Variable  I/O  Entry points */
/*     --------  ---  -------------------------------------------------- */
/*     NJRS       I   ZZEKVSET */
/*     BASES      I   ZZEKVSET */
/*     RWVIDX     I   ZZEKVACL */
/*     RWVBAS     O   ZZEKVACL */
/*     SGVBAS     O   ZZEKVACL */
/*     MXJOIN     P   Maximum number of tables that can be joined. */
/*     MXJRS      P   Maximum number of join row sets allowed in union. */

/* $ Detailed_Input */

/*     See the entry points for a discussion of their arguments. */

/* $ Detailed_Output */

/*     See the entry points for a discussion of their arguments. */

/* $ Parameters */

/*     MXJOIN         is the maximum number of tables that can be joined. */

/*     MXJRS          is the maximum number of join row sets allowed in */
/*                    in the input union identified by BASES and NJRS. */

/* $ Exceptions */

/*     1)  This is an umbrella routine which contains declarations */
/*         for its entry points.  This routine should never be called */
/*         directly.  If it is, the error SPICE(BOGUSENTRY) will be */
/*         signalled. */

/*     See the entry points for discussions of the exceptions specific */
/*     to those entry points. */

/* $ Files */

/*     1)  This routine uses the EK scratch area, which employs a scratch */
/*         DAS file. */

/* $ Particulars */

/*     In the course of query resolution, the EK system builds a set of */
/*     data structures called `join row sets' that represent the rows */
/*     that satisfy the query constraints.  These rows belong to a table */
/*     formed by taking the Cartesian product of the tables in the FROM */
/*     clause of the query.  One join row set is formed for each */
/*     conjunction of join constraints; the total number of join row sets */
/*     is equal to the number of conjunctions of join constraints in */
/*     the query.  Join row sets are described below. */

/*     This group of routines allows the EK system to view the rows */
/*     matching a query as a sequence of vectors, where each vector is an */
/*     n-tuple of row numbers designating rows in segments of the */
/*     Cartesian product of tables specified in the input query.  These */
/*     vectors are called `row vectors'.  Each row vector also points to */
/*     a vector of segments that contain the rows represented by the row */
/*     vector. */

/*     These routines centralize the calculations needed to locate the */
/*     nth row vector. */

/*     Each join row set consists of: */

/*         - a base address in the scratch area */
/*         - a table count */
/*         - a segment vector count */
/*         - a set of segment vectors */
/*         - a set of segment vector row vector base addresses */
/*           (these are relative to the base of the join row set) */
/*         - a set of segment vector row vector counts */
/*         - a set of row vectors, augmented by offsets of their */
/*           parent segment vectors (these offsets are at the */
/*           end of each row vector) */

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
/*        | Augmented row vectors for segment vector 1 |  TC*(RC_1 + 1 ) */
/*        +--------------------------------------------+  elements */
/*                              . */
/*                              . */
/*                              . */
/*        +--------------------------------------------+ */
/*        |Augmented row vectors for segment vector SVC|  TC*(RC_SVC + 1) */
/*        +--------------------------------------------+  elements */


/* $ Examples */

/*     1)  For a given join row set union, initialize the addressing */
/*         routines, then look up row vectors. */


/*            C */
/*            C     Tell the addressing routines where the join row set */
/*            C     union is.  NJRS is the number of join row sets in */
/*            C     the union, BASES is an array of EK scratch area base */
/*            C     addresses of each join row set.  A base address is */
/*            C     the predecessor of the first address actually */
/*            C     occupied by a join row set. */
/*            C */
/*                  CALL ZZEKVSET ( NJRS, BASES ) */

/*            C */
/*            C     Find the base address of the each row vector, as well */
/*            C     as the base address of the corresponding segment */
/*            C     vector. */
/*            C */
/*                  DO I = 1, NJRS */

/*                     CALL EKVCAL ( I, RWVBAS, SGVBAS ) */

/*                     [Do something with the row vector....] */

/*                  END DO */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.1, 06-SEP-2006 (NJB) */

/*        Filled in Particulars section of header in entry point */
/*        ZZEKVCAL.  Changed previous version line's product from "Beta" */
/*        to "SPICELIB" both here and in ZZEKVCAL. */

/* -    SPICELIB Version 1.0.0, 28-SEP-1994 (NJB) (WLT) */

/* -& */
/* $ Index_Entries */

/*     EK row vector address calculation */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Include Section:  EK Join Row Set Parameters */

/*        JRS$INC Version 1    17-SEP-1994 (NJB) */

/*     Base-relative index of join row set size */


/*     Index of row vector count */


/*     Index of table count */


/*     Index of segment vector count */


/*     Base address of first segment vector */



/*     End Include Section:  EK Join Row Set Parameters */


/*     Local variables */


/*     Saved variables */


/*     Standard SPICE error handling. */

    /* Parameter adjustments */
    if (bases) {
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_zzekvset;
	case 2: goto L_zzekvcal;
	}

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "ZZEKVADR", (ftnlen)8);
    }

/*     Never come here. */

    sigerr_(__global_state, "SPICE(BOGUSENTRY)", (ftnlen)17);
    chkout_(__global_state, "ZZEKVADR", (ftnlen)8);
    return 0;
/* $Procedure  ZZEKVSET  ( Row vector address calculation set-up ) */

L_zzekvset:
/* $ Abstract */

/*     Given a union of EK join row sets, prepare EKVCAL to */
/*     compute addresses of row vectors in that union. */

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

/*     INTEGER               NJRS */
/*     INTEGER               BASES  ( * ) */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     NJRS       I   Number of join row sets in union. */
/*     BASES      I   EK scratch area base addresses of join row sets. */

/* $ Detailed_Input */

/*     NJRS           is the number of join row sets in a join row set */
/*                    for which address calculations will be performed. */

/*     BASES          is an array of base addresses of the join row sets */
/*                    comprising the union.  These addresses are the */
/*                    predecessors of the addresses actually occupied by */
/*                    the join row sets.  There are NJRS base addresses */
/*                    in the array.  The order in which addresses are */
/*                    listed in BASES determines the order of the union */
/*                    of the row vectors:  the first row vector in the */
/*                    join row set whose base address is BASES(1) has */
/*                    index 1, and so on.  The last row vector in the */
/*                    join row set whose base address is BASES(NJRS) has */
/*                    the highest index of any row vector in the union. */

/* $ Detailed_Output */

/*     None.  See $Particulars for a discussion of the effect of this */
/*     routine. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the join row set count is less than 1 or greater than */
/*         MXJRS, the error SPICE(INVALIDCOUNT) is signalled. */

/*     2)  If any base address is less than zero or greater than TOP, */
/*         the EK scratch area stack top, the error */
/*         SPICE(BADADDRESS) is signalled. */

/*     3)  If the table count for any join row set is less than 1 or */
/*         greater than MXJOIN, the error SPICE(INVALIDCOUNT) is */
/*         signalled. */

/*     4)  If the table count for any join row set unequal to the count */
/*         for the first join row set, the error SPICE(INVALIDCOUNT) is */
/*         signalled. */

/*     5)  If any join row set has a row vector count that is less than */
/*         zero or greater than TOP, the EK scratch area stack top, the */
/*         error SPICE(BADADDRESS) is signalled. */

/*     6)  If any join row set has a segment vector count that is less */
/*         than zero or greater than TOP, the EK scratch area stack top, */
/*         the error SPICE(BADADDRESS) is signalled. */

/* $ Files */

/*     1)  This routine uses the EK scratch area, which employs a scratch */
/*         DAS file. */

/* $ Particulars */

/*     This routine speeds up EK row vectors address calculations by */
/*     centralizating the activities that need be performed only once */
/*     for a series of address  calculations for a given join row set */
/*     union. */

/* $ Examples */

/*     See the $Examples section of ZZEKVADR. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    Beta Version 1.0.0, 28-SEP-1994 (NJB) (WLT) */

/* -& */
/* $ Index_Entries */

/*     EK row vector address calculation */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "ZZEKVSET", (ftnlen)8);
    }

/*     Validate join row set count. */

    if (*njrs < 1 || *njrs > 200) {
	setmsg_(__global_state, "Number of join row sets was #; valid range "
		"is 1:#", (ftnlen)49);
	errint_(__global_state, "#", njrs, (ftnlen)1);
	errint_(__global_state, "#", &__state->c__200, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDCOUNT)", (ftnlen)19);
	chkout_(__global_state, "ZZEKVSET", (ftnlen)8);
	return 0;
    }

/*     Validate the join row set bases. */

    zzekstop_(__global_state, &__state->top);
    i__1 = *njrs;
    for (__state->i__ = 1; __state->i__ <= i__1; ++__state->i__) {
	if (bases[__state->i__ - 1] < 0 || bases[__state->i__ - 1] > 
		__state->top) {
	    setmsg_(__global_state, "Base address # was #; valid range is 1:#"
		    , (ftnlen)40);
	    errint_(__global_state, "#", &__state->i__, (ftnlen)1);
	    errint_(__global_state, "#", &bases[__state->i__ - 1], (ftnlen)1);
	    errint_(__global_state, "#", &__state->top, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(BADADDRESS)", (ftnlen)17);
	    chkout_(__global_state, "ZZEKVSET", (ftnlen)8);
	    return 0;
	}
	__state->svbas[(i__2 = __state->i__ - 1) < 200 && 0 <= i__2 ? i__2 : 
		s_rnge(&__global_state->f2c, "svbas", i__2, "zzekvadr_", (
		ftnlen)526)] = bases[__state->i__ - 1];
    }

/*     Validate and save the table count.  It's an error for this */
/*     count not to be identical for all of the join row sets in the */
/*     union. */

    __state->addrss = bases[0] + 3;
    zzeksrd_(__global_state, &__state->addrss, &__state->addrss, &
	    __state->ntabs);
    if (__state->ntabs < 1 || __state->ntabs > 10) {
	setmsg_(__global_state, "Table count for first join row set was #; v"
		"alid range is 1:#", (ftnlen)60);
	errint_(__global_state, "#", &__state->ntabs, (ftnlen)1);
	errint_(__global_state, "#", &__state->c__10, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDCOUNT)", (ftnlen)19);
	chkout_(__global_state, "ZZEKVSET", (ftnlen)8);
	return 0;
    }
    i__1 = *njrs;
    for (__state->i__ = 2; __state->i__ <= i__1; ++__state->i__) {
	__state->addrss = bases[__state->i__ - 1] + 3;
	zzeksrd_(__global_state, &__state->addrss, &__state->addrss, &
		__state->j);
	if (__state->j != __state->ntabs) {
	    setmsg_(__global_state, "Join row set # contains # tables; first"
		    " join row set contains # tables.  These counts are suppo"
		    "sed to match.", (ftnlen)108);
	    errint_(__global_state, "#", &__state->i__, (ftnlen)1);
	    errint_(__global_state, "#", &__state->j, (ftnlen)1);
	    errint_(__global_state, "#", &__state->ntabs, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(INVALIDCOUNT)", (ftnlen)19);
	    chkout_(__global_state, "ZZEKVSET", (ftnlen)8);
	    return 0;
	}
    }

/*     Validate the row vector counts for each join row set. */
/*     These counts must be in range.  Save the start indices of */
/*     the row vectors in each join row set. */

    cleari_(__global_state, &__state->c__200, __state->begidx);
    __state->begidx[0] = 1;
    i__1 = *njrs;
    for (__state->i__ = 1; __state->i__ <= i__1; ++__state->i__) {
	__state->addrss = bases[__state->i__ - 1] + 2;
	zzeksrd_(__global_state, &__state->addrss, &__state->addrss, &
		__state->j);
	if (__state->j < 0 || __state->j > __state->top) {
	    setmsg_(__global_state, "Join row set # has row count #; valid r"
		    "ange is 0:#", (ftnlen)50);
	    errint_(__global_state, "#", &__state->i__, (ftnlen)1);
	    errint_(__global_state, "#", &__state->j, (ftnlen)1);
	    errint_(__global_state, "#", &__state->top, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(INVALIDCOUNT)", (ftnlen)19);
	    chkout_(__global_state, "ZZEKVSET", (ftnlen)8);
	    return 0;
	}
	if (__state->i__ < *njrs) {
	    __state->begidx[(i__2 = __state->i__) < 200 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "begidx", i__2, "zzekvadr_", 
		    (ftnlen)598)] = __state->begidx[(i__3 = __state->i__ - 1) 
		    < 200 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "begidx", i__3, "zzekvadr_", (ftnlen)598)] + __state->j;
	}
    }

/*     Retain the index of the last row vector. */

    __state->maxrwv = __state->begidx[(i__1 = *njrs - 1) < 200 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "begidx", i__1, "zzekvadr_", (
	    ftnlen)608)] + __state->j;

/*     Save the base addresses of the row vectors in each join row set. */
/*     Validate the segment vector counts while we're at it. */

    i__1 = *njrs;
    for (__state->i__ = 1; __state->i__ <= i__1; ++__state->i__) {
	__state->addrss = bases[__state->i__ - 1] + 4;
	zzeksrd_(__global_state, &__state->addrss, &__state->addrss, &
		__state->nsv);
	if (__state->nsv < 0) {
	    setmsg_(__global_state, "Join row set # has segment vector count"
		    " #; count must be non-negative.", (ftnlen)70);
	    errint_(__global_state, "#", &__state->i__, (ftnlen)1);
	    errint_(__global_state, "#", &__state->nsv, (ftnlen)1);
	    errint_(__global_state, "#", &__state->top, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(INVALIDCOUNT)", (ftnlen)19);
	    chkout_(__global_state, "ZZEKVSET", (ftnlen)8);
	    return 0;
	}
	__state->rbas[(i__2 = __state->i__ - 1) < 200 && 0 <= i__2 ? i__2 : 
		s_rnge(&__global_state->f2c, "rbas", i__2, "zzekvadr_", (
		ftnlen)633)] = __state->addrss + __state->nsv * (
		__state->ntabs + 2);
    }

/*     Retain the count of join row sets in the union. */

    __state->svnjrs = *njrs;
    chkout_(__global_state, "ZZEKVSET", (ftnlen)8);
    return 0;
/* $Procedure  ZZEKVCAL  ( Row vector address calculation  ) */

L_zzekvcal:
/* $ Abstract */

/*     Find the EK scratch area base address of a row vector and the */
/*     corresponding segment vector, where the row vector has a */
/*     specified index within a union of join row sets. */

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

/*     INTEGER               RWVIDX */
/*     INTEGER               RWVBAS */
/*     INTEGER               SGVBAS */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     RWVIDX     I   Index of row vector. */
/*     RWVBAS     O   EK scratch area base address of row vector. */
/*     SGVBAS     O   Base address of parent segment vector. */

/* $ Detailed_Input */

/*     RWVIDX         is the index of a row vector in a join row set */
/*                    union.  The union is presumed to have been */
/*                    specified by a call to ZZEKVSET. */

/* $ Detailed_Output */

/*     RWVBAS         is the EK scratch area base address of the row */
/*                    vector specified by RWVIDX.  This address is */
/*                    the predecessor of the first address occupied by */
/*                    the row vector.  The row vector occupies NTAB */
/*                    consecutive addresses, where NTAB is the common */
/*                    table count for all join row sets in the union */
/*                    containing the specified row vector. */

/*     SGVBAS         is the EK scratch area base address of the segment */
/*                    vector corresponding to the specified row vector. */
/*                    The segment vector also occupies NTAB consecutive */
/*                    addresses. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the input index is less than 1 or greater than */
/*         the highest index in the join row set union being addressed, */
/*         the error SPICE(INVALIDINDEX) is signalled. */

/* $ Files */

/*     1)  This routine uses the EK scratch area, which employs a scratch */
/*         DAS file. */

/* $ Particulars */

/*     See header of umbrella routine ZZEKVADR. */

/* $ Examples */

/*     See the $Examples section of ZZEKVADR. */

/* $ Restrictions */

/*     1)  ZZEKVSET must be called before this routine is called for the */
/*         first time. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.1, 06-SEP-2006 (NJB) */

/*        Filled in Particulars section of header.  Changed */
/*        previous version line's product from "Beta" to "SPICELIB." */

/* -    SPICELIB Version 1.0.0, 22-SEP-1994 (NJB) (WLT) */

/* -& */
/* $ Index_Entries */

/*     EK row vector address calculation */

/* -& */

/*     Use discovery check-in for speed; don't check RETURN. */


/*     If the index is out of range, that's an error. */

    if (*rwvidx < 1 || *rwvidx > __state->maxrwv) {
	chkin_(__global_state, "ZZEKVCAL", (ftnlen)8);
	setmsg_(__global_state, "Row vector index was #; valid range is 0:#", 
		(ftnlen)42);
	errint_(__global_state, "#", rwvidx, (ftnlen)1);
	errint_(__global_state, "#", &__state->maxrwv, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDINDEX)", (ftnlen)19);
	chkout_(__global_state, "ZZEKVCAL", (ftnlen)8);
	return 0;
    }

/*     Identify the join row set containing the indicated row.  Our error */
/*     check guarantees a non-zero result. */

    __state->jrsidx = lstlei_(__global_state, rwvidx, &__state->svnjrs, 
	    __state->begidx);

/*     Compute the offset of the indicated row vector relative to the */
/*     first row vector in the parent join row set.  This offset is one */
/*     less than the relative index of the row vector, multiplied by */
/*     the augmented row vector size. */

    __state->reloff = (*rwvidx - __state->begidx[(i__1 = __state->jrsidx - 1) 
	    < 200 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "begidx",
	     i__1, "zzekvadr_", (ftnlen)814)]) * (__state->ntabs + 1);

/*     Find the base address of the row vector. */

    *rwvbas = __state->rbas[(i__1 = __state->jrsidx - 1) < 200 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "rbas", i__1, "zzekvadr_", (
	    ftnlen)819)] + __state->reloff;

/*     Compute the base address of the parent segment vector.  The base- */
/*     relative address of the segment vector is stored at the end of the */
/*     row vector. */

    i__1 = *rwvbas + __state->ntabs + 1;
    i__2 = *rwvbas + __state->ntabs + 1;
    zzeksrd_(__global_state, &i__1, &i__2, sgvbas);
    *sgvbas = __state->svbas[(i__1 = __state->jrsidx - 1) < 200 && 0 <= i__1 ?
	     i__1 : s_rnge(&__global_state->f2c, "svbas", i__1, "zzekvadr_", (
	    ftnlen)828)] + *sgvbas;
    return 0;
} /* zzekvadr_ */

/* Subroutine */ int zzekvadr_(cspice_t* __global_state, integer *njrs, 
	integer *bases, integer *rwvidx, integer *rwvbas, integer *sgvbas)
{
    return zzekvadr_0_(__global_state, 0, njrs, bases, rwvidx, rwvbas, sgvbas)
	    ;
    }

/* Subroutine */ int zzekvset_(cspice_t* __global_state, integer *njrs, 
	integer *bases)
{
    return zzekvadr_0_(__global_state, 1, njrs, bases, (integer *)0, (integer 
	    *)0, (integer *)0);
    }

/* Subroutine */ int zzekvcal_(cspice_t* __global_state, integer *rwvidx, 
	integer *rwvbas, integer *sgvbas)
{
    return zzekvadr_0_(__global_state, 2, (integer *)0, (integer *)0, rwvidx, 
	    rwvbas, sgvbas);
    }

