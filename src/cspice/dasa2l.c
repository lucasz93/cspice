/* dasa2l.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern dasa2l_init_t __dasa2l_init;
static dasa2l_state_t* get_dasa2l_state(cspice_t* state) {
	if (!state->dasa2l)
		state->dasa2l = __cspice_allocate_module(sizeof(
	dasa2l_state_t), &__dasa2l_init, sizeof(__dasa2l_init));
	return state->dasa2l;

}

/* $Procedure      DASA2L ( DAS, address to physical location ) */
/* Subroutine */ int dasa2l_(cspice_t* __global_state, integer *handle, 
	integer *type__, integer *addrss, integer *clbase, integer *clsize, 
	integer *recno, integer *wordno)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer), s_cmp(
	    f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern logical failed_(cspice_t*);
    extern /* Subroutine */ int dasham_(cspice_t*, integer *, char *, ftnlen);
    extern /* Subroutine */ int dashfs_(cspice_t*, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *);
    extern integer isrchi_(cspice_t*, integer *, integer *, integer *);
    extern /* Subroutine */ int errhan_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int dasrri_(cspice_t*, integer *, integer *, 
	    integer *, integer *, integer *);

    /* Module state */
    dasa2l_state_t* __state = get_dasa2l_state(__global_state);
/* $ Abstract */

/*     Map a DAS address to a physical location in a specified DAS file. */

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

/*     DAS */
/*     FILES */
/*     TRANSFORMATION */
/*     UTILITY */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   DAS file handle. */
/*     TYPE       I   Data type specifier. */
/*     ADDRSS     I   DAS address of a word of data type TYPE. */
/*     CLBASE, */
/*     CLSIZE     O   Cluster base record number and size. */
/*     RECNO, */
/*     WORDNO     O   Record/word pair corresponding to ADDRSS. */
/*     CHAR       P   Parameter indicating character data type. */
/*     INT        P   Parameter indicating integer data type. */

/* $ Detailed_Input */

/*     HANDLE         is the file handle of an open DAS file. */

/*     TYPE           is a data type specifier. TYPE may be any of */
/*                    the parameters */

/*                       CHAR */
/*                       DP */
/*                       INT */

/*                    which indicate `character', `double precision', */
/*                    and `integer' respectively. */


/*     ADDRSS         is the address in a DAS of a word of data */
/*                    type TYPE. For each data type (double precision, */
/*                    integer, or character), addresses range */
/*                    from 1 to the maximum current value for that type, */
/*                    which is available from DAFRFR. */

/* $ Detailed_Output */

/*     CLBASE, */
/*     CLSIZE         are, respectively, the base record number and */
/*                    size, in records, of the cluster containing the */
/*                    word corresponding to ADDRSS. The cluster spans */
/*                    records numbered CLBASE through CLBASE + */
/*                    CLSIZE - 1. */

/*     RECNO, */
/*     WORD           are, respectively, the number of the physical */
/*                    record and the number of the word within the */
/*                    record that correspond to ADDRSS. Word numbers */
/*                    start at 1 and go up to NC, ND, or NI in */
/*                    character, double precision, or integer records */
/*                    respectively. */

/* $ Parameters */

/*     CHAR, */
/*     DP, */
/*     INT            are data type specifiers which indicate */
/*                    `character', `double precision', and `integer' */
/*                    respectively. These parameters are used in */
/*                    all DAS routines that require a data type */
/*                    specifier as input. */

/* $ Exceptions */

/*     1)  If TYPE is not recognized, the error SPICE(DASINVALIDTYPE) */
/*         will be signaled. */

/*     2)  ADDRSS must be between 1 and LAST inclusive, where LAST */
/*         is last address in the DAS for a word of the specified */
/*         type. If ADDRSS is out of range, the error */
/*         SPICE(DASNOSUCHADDRESS) will be signaled. */

/*     3)  If this routine doesn't find an expected cluster descriptor */
/*         in a directory record, the error SPICE(BADDASDIRECTORY) is */
/*         signaled. */

/*     4)  If the input handle is invalid, the error will be diagnosed */
/*         by routines called by this routine. */

/*     If any of the above exceptions occur, the output arguments may */
/*     contain bogus information. */

/* $ Files */

/*     See the description of the argument HANDLE in $Detailed_Input. */

/* $ Particulars */

/*     The DAS architecture allows a programmer to think of the data */
/*     within a DAS file as three one-dimensional arrays: one of */
/*     double precision numbers, one of integers, and one of characters. */
/*     This model allows a programmer to ask the DAS system for the */
/*     `nth double precision number (or integer, or character) in the */
/*     file'. */

/*     DAS files are Fortran direct access files, so to find the */
/*     `nth double precision number', you must have the number of the */
/*     record containing it and the `word number', or position, within */
/*     the record of the double precision number. This routine finds */
/*     the record/word number pair that specify the physical location */
/*     in a DAS file corresponding to a DAS address. */

/*     As opposed to DAFs, the mapping of addresses to physical */
/*     locations for a DAS file depends on the organization of data in */
/*     the file. For example, given a fixed set of DAS file summary */
/*     parameters, the physical location of the nth double precision */
/*     number can depend on how many integer and character records have */
/*     been written prior to the record containing that double precision */
/*     number. */

/*     The cluster information output from this routine allows the */
/*     caller to substantially reduce the number of directory reads */
/*     required to read a from range of addresses that spans */
/*     multiple physical records; the reading program only need call */
/*     this routine once per cluster read, rather than once per */
/*     physical record read. */

/* $ Examples */

/*     1)  Use this routine to read integers from a range of */
/*         addresses. This is done in the routine DASRDI. */

/*            C */
/*            C     Decide how many integers to read. */
/*            C */
/*                  NUMINT = LAST - FIRST + 1 */
/*                  NREAD  = 0 */

/*            C */
/*            C     Find out the physical location of the first */
/*            C     integer. If FIRST is invalid, DASA2L will take care */
/*            C     of the problem. */
/*            C */
/*                  CALL DASA2L (  HANDLE,  INT,     FIRST, */
/*                 .               CLBASE,  CLSIZE,  RECNO,  WORDNO  ) */

/*            C */
/*            C     Read as much data from record RECNO as necessary. */
/*            C */
/*                  N  =  MIN ( NUMINT,  NWI - WORDNO + 1 ) */

/*                  CALL DASRRI ( HANDLE, RECNO, WORDNO, WORDNO + N-1, */
/*                 .              DATA                                 ) */

/*                  NREAD  =  N */
/*                  RECNO  =  RECNO + 1 */

/*            C */
/*            C     Read from as many additional records as necessary. */
/*            C */
/*                  DO WHILE ( NREAD .LT. NUMINT ) */
/*            C */
/*            C        At this point, RECNO if RECNO refers to */
/*            C        a record in the current cluster, RECNO */
/*            C        is the correct number of the record to read */
/*            C        from next. Otherwise, the next cluster of */
/*            C        records containing integer data must be located. */
/*            C        CLBASE is the number of the first record of */
/*            C        the cluster we're about to read from. */
/*            C */
/*                     IF (  RECNO  .LT.  ( CLBASE + CLSIZE )  ) THEN */
/*            C */
/*            C           We can continue reading from the current */
/*            C           cluster. */
/*            C */
/*                        N  =  MIN ( NUMINT - NREAD,  NWI ) */

/*                        CALL DASRRI (  HANDLE, */
/*                 .                     RECNO, */
/*                 .                     1, */
/*                 .                     N, */
/*                 .                     DATA ( NREAD + 1 )   ) */

/*                        NREAD   =   NREAD + N */
/*                        RECNO   =   RECNO + 1 */


/*                     ELSE */
/*            C */
/*            C           We must find the next integer cluster to */
/*            C           read from. The first integer in this */
/*            C           cluster has address FIRST + NREAD. */
/*            C */
/*                        CALL DASA2L ( HANDLE, */
/*                 .                    INT, */
/*                 .                    FIRST + NREAD, */
/*                 .                    CLBASE, */
/*                 .                    CLSIZE, */
/*                 .                    RECNO, */
/*                 .                    WORDNO  ) */

/*                     END IF */

/*                  END DO */


/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     K.R. Gehringer (JPL) */
/*     N.J. Bachman   (JPL) */
/*     W.L. Taber     (JPL) */

/* $ Version */

/* -    SPICELIB Version 3.0.0 FEB-09-2015 (NJB) */

/*        Updated to use DAF/DAS handle manager subsystem. */

/* -    SPICELIB Version 2.0.0 APR-15-2014 (NJB) */

/*        Previous update was 25-FEB-2014 */

/*        Bug fix: value of variable FAST for "unknown" files with one */
/*        directory record is now stored in TBFAST. The routine */
/*        previously computed correct outputs but did so more slowly */
/*        than necessary when multiple "fast" files were accessed. */

/*        Functional change: new entries in the file attribute table are */
/*        now inserted at index 1; the existing part of the table is */
/*        shifted to make room. Old entries drop off the end of the */
/*        list. The previous algorithm simply overwrote the first entry */
/*        once the table became full. */

/*        The file attribute table was expanded to store values of a */
/*        "read only" flag for each file. This enables the routine to */
/*        avoid look up of maximum addresses for known, read-only, */
/*        non-segregated files. */

/*        Tests of FAILED and backup loop termination checks */
/*        were added. Logic was introduced to prevent reliance on */
/*        previous values of logical flags unless those flags were */
/*        set on a successful call. On any call that fails, the */
/*        table entry for the current file is marked as unused by */
/*        setting the handle entry to zero. */

/*        The state variables FIRST and RDONLY have been removed. */

/*        Unneeded declarations were removed. */

/*        The code was re-structured to improve clarity. */

/* -    SPICELIB Version 1.2.1 20-NOV-2001 (NJB) */

/*        Comment fix: diagram showing directory record pointers */
/*        incorrectly showed element 2 of the record as a backward */
/*        pointer. The element is actually a forward pointer. */

/* -    SPICELIB Version 1.2.0 03-JUL-1996 (NJB) */

/*        Bug fix: calculation to determine whether file is segregated */
/*        has been fixed. */

/* -    SPICELIB Version 1.1.1 19-DEC-1995 (NJB) */

/*        Corrected title of permuted index entry section. */

/* -    SPICELIB Version 1.1.0, 03-NOV-1995 (NJB) */

/*        Re-written to optimize address calculations for segregated, */
/*        read-only files. */

/* -    SPICELIB Version 1.0.1, 26-OCT-1993 (KRG) */

/*        Fixed a typo in the $ Brief_I/O section of the header. */

/*        Removed references to specific DAS file open routines in the */
/*        $ Detailed_Input section of the header. This was done in order */
/*        to minimize documentation changes if the DAS open routines ever */
/*        change. */

/* -    SPICELIB Version 1.0.0, 11-NOV-1992 (NJB) (WLT) */

/* -& */
/* $ Index_Entries */

/*     map DAS logical address to physical location */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.2.0 03-JUL-1996 (NJB) */

/*        Bug fix: calculation to determine whether file is segregated */
/*        has been fixed. An incorrect variable name used in a bound */
/*        calculation resulted in an incorrect determination of whether */
/*        a file was segregated, and caused arithmetic overflow for */
/*        files with large maximum addresses. */

/*        In the previous version, the number of DAS words in a cluster */
/*        was incorrectly calculated as the product of the maximum */
/*        address of the cluster's data type and the number of words of */
/*        that data type in a DAS record. The correct product involves */
/*        the number of records in the cluster and the number of words of */
/*        that data type in a DAS record. */

/* -    SPICELIB Version 1.1.0, 03-NOV-1995 (NJB) */

/*        Re-written to optimize address calculations for segregated, */
/*        read-only files. */

/* -    SPICELIB Version 1.0.1, 26-OCT-1993 (KRG) */

/*        Fixed a typo in the $ Brief_I/O section of the header. */

/*        Removed references to specific DAS file open routines in the */
/*        $ Detailed_Input section of the header. This was done in order */
/*        to minimize documentation changes if the DAS open routines ever */
/*        change. */

/* -    SPICELIB Version 1.0.0, 11-NOV-1992 (NJB) (WLT) */

/* -& */

/*     Programmer's note: the TSPICE routine P_DASA2L must be */
/*     kept in sync with this routine. Current version of that */
/*     routine is */

/*        TSPICE Version 1.0.0 APR-11-2014 (NJB) */


/*     SPICELIB functions */


/*     Local parameters */


/*     Words per data record, for each data type: */


/*     Directory forward pointer location */


/*     Directory address range locations */


/*     Index of highest address in a `range array': */


/*     Location of first type descriptor */


/*     Access word length */


/*     File table size */


/*     Local variables */


/*     Saved variables */


/*     Initial values */


/*     NEXT and PREV map the DAS data type codes to their */
/*     successors and predecessors, respectively. */


/*     Discovery check-in is used in this routine, even though */
/*     this routine calls routines that can signal errors. This */
/*     routine is a special case, because fast operation is very */
/*     important. */


/*     DAS files have the following general structure: */

/*           +------------------------+ */
/*           |      file record       | */
/*           +------------------------+ */
/*           |    reserved records    | */
/*           |                        | */
/*           +------------------------+ */
/*           |     comment records    | */
/*           |                        | */
/*           |                        | */
/*           |                        | */
/*           +------------------------+ */
/*           | first data directory   | */
/*           +------------------------+ */
/*           |      data records      | */
/*           |                        | */
/*           |                        | */
/*           |                        | */
/*           |                        | */
/*           +------------------------+ */
/*                       . */
/*                       . */
/*           +------------------------+ */
/*           | last data directory    | */
/*           +------------------------+ */
/*           |     data records       | */
/*           |                        | */
/*           |                        | */
/*           +------------------------+ */


/*        Within each DAS data record, word numbers start at one and */
/*        increase up to NWI, NWD, or NWC: the number of words in an */
/*        integer, double precision, or character data record. */


/*           +--------------------------------+ */
/*           |       |       |   ...  |       | */
/*           +--------------------------------+ */
/*               1      2                NWD */

/*           +--------------------------------+ */
/*           |   |   |       ...          |   | */
/*           +--------------------------------+ */
/*             1   2                       NWI */

/*           +------------------------------------+ */
/*           | | |           ...                | | */
/*           +------------------------------------+ */
/*            1 2                               NWC */


/*        Directories are single records that describe the data */
/*        types of data records that follow. The directories */
/*        in a DAS file form a doubly linked list: each directory */
/*        contains forward and backward pointers to the next and */
/*        previous directories. */

/*        Each directory also contains, for each data type, the lowest */
/*        and highest logical address occurring in any of the records */
/*        described by the directory. */

/*        Following the pointers and address range information is */
/*        a sequence of data type descriptors. These descriptors */
/*        indicate the data type of data records following the */
/*        directory record. Each descriptor gives the data type */
/*        of a maximal set of contiguous data records, all having the */
/*        same type. By `maximal set' we mean that no data records of */
/*        the same type bound the set of records in question. */

/*        Pictorially, the structure of a directory is as follows: */

/*           +----------------------------------------------------+ */
/*           | <pointers> | <address ranges> | <type descriptors> | */
/*           +----------------------------------------------------+ */

/*        where the <pointers> section looks like */

/*           +-----------------------------------------+ */
/*           | <backward pointer> | <forward pointer>  | */
/*           +-----------------------------------------+ */

/*        the <address ranges> section looks like */

/*           +-------------------------------------------+ */
/*           | <char range> | <d.p. range> | <int range> | */
/*           +-------------------------------------------+ */

/*        and each range looks like one of: */

/*           +------------------------------------------------+ */
/*           | <lowest char address> | <highest char address> | */
/*           +------------------------------------------------+ */

/*           +------------------------------------------------+ */
/*           | <lowest d.p. address> | <highest d.p. address> | */
/*           +------------------------------------------------+ */

/*           +------------------------------------------------+ */
/*           | <lowest int address>  | <highest int address>  | */
/*           +------------------------------------------------+ */

/*        The type descriptors implement a run-length encoding */
/*        scheme. The first element of the series of descriptors */
/*        occupies two integers: it contains a type code and a count. */
/*        The rest of the descriptors are just signed counts; the data */
/*        types of the records they describe are deduced from the sign */
/*        of the count and the data type of the previous descriptor. */
/*        The method of finding the data type for a given descriptor */
/*        in terms of its predecessor is as follows: if the sign of a */
/*        descriptor is positive, the type of that descriptor is the */
/*        successor of the type of the preceding descriptor in the */
/*        sequence of types below. If the sign of a descriptor is */
/*        negative, the type of the descriptor is the predecessor of the */
/*        type of the preceding descriptor. */

/*           C  -->  D  -->  I  -->  C */

/*        For example, if the preceding type is `I', and a descriptor */
/*        contains the number 16, the type of the descriptor is `C', */
/*        whereas if the descriptor contained the number -800, the type */
/*        of the descriptor would be `D'. */


/*     Logic cases */
/*     =========== */

/*     There are three kinds of file attributes that this */
/*     routine distinguishes: */

/*        Attributes */
/*        ---------- */
/*        "FAST"           read-only and segregated */
/*        "READONLY"       read-only and unsegregated */
/*        "WRITABLE"       writable */

/*     There are three kinds of file histories that this */
/*     routine distinguishes: */

/*        History */
/*        ------- */
/*        "SAME"           file is the same as seen on */
/*                         the previous call */

/*        "KNOWN"          file is not the same as seen */
/*                         on the previous call, but file */
/*                         information is buffered */

/*        "UNKNOWN"        file information is not buffered. */

/*     All combinations of attributes and history are possible, */
/*     so there are nine cases. */

/*     Mapping actions to cases */
/*     ======================== */

/*        Action                             Cases */
/*        ------                             ----- */
/*        Set SAMFIL, PRVOK                  ALL */
/*        Data type check                    ALL */
/*        Set KNOWN                          not (FAST and SAME) */
/*        Get access method                  UNKNOWN */
/*        Buffer insertion                   UNKNOWN */
/*        Set */
/*            TBHAN */
/*            TBRDON */
/*            TBFAST */
/*            TBFWRD                         UNKNOWN */
/*        Get file summary                   UNKNOWN or WRITABLE */
/*        Set TBMXAD                         UNKNOWN or WRITABLE */
/*        Segregation check                  UNKNOWN and not WRITABLE */
/*        Set TBBASE, TBSIZE                 FAST and UNKNOWN */
/*        Set FAST                           not SAME */
/*        Address range check                ALL */
/*        Address search                     READONLY or WRITABLE */
/*        Set CLBASE, CLSIZE                 ALL */

/*     ======================== */


/*     Make sure the data type is valid. */

    if (*type__ < 1 || *type__ > 3) {
	chkin_(__global_state, "DASA2L", (ftnlen)6);
	setmsg_(__global_state, "Invalid data type: #. File was #", (ftnlen)
		32);
	errint_(__global_state, "#", type__, (ftnlen)1);
	errhan_(__global_state, "#", handle, (ftnlen)1);
	sigerr_(__global_state, "SPICE(DASINVALIDTYPE)", (ftnlen)21);
	chkout_(__global_state, "DASA2L", (ftnlen)6);
	return 0;
    }

/*     Decide whether we're looking at the same file as we did on the */
/*     last call. We can use data from the previous call only if that */
/*     call succeeded. */

    __state->samfil = *handle == __state->prvhan && __state->prvok;

/*     PRVOK defaults to .FALSE. and will be reset if this call */
/*     succeeds. */

    __state->prvok = FALSE_;

/*     Fast files get priority handling. If we have a fast file */
/*     that we saw on the previous call, skip directly to the */
/*     address range check. */

    if (! (__state->fast && __state->samfil)) {

/*        Is this a file we recognize? */

	if (__state->samfil) {
	    __state->known = TRUE_;
	} else {
	    __state->fidx = isrchi_(__global_state, handle, &__state->nfiles, 
		    __state->tbhan);
	    __state->known = __state->fidx > 0;
	}
	if (__state->known) {
	    __state->fast = __state->tbfast[(i__1 = __state->fidx - 1) < 20 &&
		     0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "tbfast",
		     i__1, "dasa2l_", (ftnlen)779)];
	} else {

/*           This file is not in our list. We'll buffer information */
/*           about this file. */

/*           Shift the table and insert the new entry at the front. The */
/*           entry at the back will be lost if the table is full. */

/*           Note that unused entries (those for which the DAS handle is */
/*           0) will drop out of the list automatically. */

	    __state->ub = min(__state->nfiles,19);
	    for (__state->i__ = __state->ub; __state->i__ >= 1; 
		    --__state->i__) {
		__state->tbhan[(i__1 = __state->i__) < 20 && 0 <= i__1 ? i__1 
			: s_rnge(&__global_state->f2c, "tbhan", i__1, "dasa2"
			"l_", (ftnlen)796)] = __state->tbhan[(i__2 = 
			__state->i__ - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "tbhan", i__2, "dasa2l_", (
			ftnlen)796)];
		__state->tbrdon[(i__1 = __state->i__) < 20 && 0 <= i__1 ? 
			i__1 : s_rnge(&__global_state->f2c, "tbrdon", i__1, 
			"dasa2l_", (ftnlen)797)] = __state->tbrdon[(i__2 = 
			__state->i__ - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "tbrdon", i__2, "dasa2l_", (
			ftnlen)797)];
		__state->tbfast[(i__1 = __state->i__) < 20 && 0 <= i__1 ? 
			i__1 : s_rnge(&__global_state->f2c, "tbfast", i__1, 
			"dasa2l_", (ftnlen)798)] = __state->tbfast[(i__2 = 
			__state->i__ - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "tbfast", i__2, "dasa2l_", (
			ftnlen)798)];
		__state->tbfwrd[(i__1 = __state->i__) < 20 && 0 <= i__1 ? 
			i__1 : s_rnge(&__global_state->f2c, "tbfwrd", i__1, 
			"dasa2l_", (ftnlen)799)] = __state->tbfwrd[(i__2 = 
			__state->i__ - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "tbfwrd", i__2, "dasa2l_", (
			ftnlen)799)];
		for (__state->j = 1; __state->j <= 3; ++__state->j) {
		    __state->tbbase[(i__1 = __state->j + (__state->i__ + 1) * 
			    3 - 4) < 60 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "tbbase", i__1, "dasa2l_", (
			    ftnlen)802)] = __state->tbbase[(i__2 = __state->j 
			    + __state->i__ * 3 - 4) < 60 && 0 <= i__2 ? i__2 :
			     s_rnge(&__global_state->f2c, "tbbase", i__2, 
			    "dasa2l_", (ftnlen)802)];
		    __state->tbsize[(i__1 = __state->j + (__state->i__ + 1) * 
			    3 - 4) < 60 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "tbsize", i__1, "dasa2l_", (
			    ftnlen)803)] = __state->tbsize[(i__2 = __state->j 
			    + __state->i__ * 3 - 4) < 60 && 0 <= i__2 ? i__2 :
			     s_rnge(&__global_state->f2c, "tbsize", i__2, 
			    "dasa2l_", (ftnlen)803)];
		    __state->tbmxad[(i__1 = __state->j + (__state->i__ + 1) * 
			    3 - 4) < 60 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "tbmxad", i__1, "dasa2l_", (
			    ftnlen)804)] = __state->tbmxad[(i__2 = __state->j 
			    + __state->i__ * 3 - 4) < 60 && 0 <= i__2 ? i__2 :
			     s_rnge(&__global_state->f2c, "tbmxad", i__2, 
			    "dasa2l_", (ftnlen)804)];
		}
	    }

/*           Insert the new table entry at index 1. */

/* Computing MIN */
	    i__1 = __state->nfiles + 1;
	    __state->nfiles = min(i__1,20);
	    __state->fidx = 1;
	    __state->tbhan[(i__1 = __state->fidx - 1) < 20 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "tbhan", i__1, "dasa"
		    "2l_", (ftnlen)813)] = *handle;

/*           Set FAST to .FALSE. until we find out whether the file */
/*           is read-only and segregated. */

	    __state->fast = FALSE_;
	    __state->tbfast[(i__1 = __state->fidx - 1) < 20 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "tbfast", i__1, "das"
		    "a2l_", (ftnlen)819)] = __state->fast;

/*           FIDX is now set whether or not the current file is known. */

/*           TBRDON(FIDX) and TBFAST(FIDX) are set. */

/*           Find out whether the file is open for read or write access. */
/*           We consider the file to be `slow' until we find out */
/*           otherwise. The contents of the arrays TBBASE, TBSIZE, and */
/*           TBMXAD are left undefined for slow files. */

	    dasham_(__global_state, handle, __state->access, (ftnlen)10);
	    if (failed_(__global_state)) {

/*              Make sure the current table entry won't be found */
/*              on a subsequent search. */

		__state->tbhan[(i__1 = __state->fidx - 1) < 20 && 0 <= i__1 ? 
			i__1 : s_rnge(&__global_state->f2c, "tbhan", i__1, 
			"dasa2l_", (ftnlen)837)] = 0;
		return 0;
	    }

/*           TBRDON(FIDX) indicates whether the file is read-only. */

	    __state->tbrdon[(i__1 = __state->fidx - 1) < 20 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "tbrdon", i__1, "das"
		    "a2l_", (ftnlen)845)] = s_cmp(&__global_state->f2c, 
		    __state->access, "READ", (ftnlen)10, (ftnlen)4) == 0;
	}

/*        FIDX, KNOWN and TBRDON( FIDX ) are set. */

/*        Get the file summary if it isn't known already. */

	if (! (__state->known && __state->tbrdon[(i__1 = __state->fidx - 1) < 
		20 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "tbrdon"
		, i__1, "dasa2l_", (ftnlen)854)])) {

/*           The file is new or it's writable; in either case the */
/*           maximum addresses are unknown. Get the current address */
/*           range for the file. */

	    dashfs_(__global_state, handle, &__state->nresvr, &
		    __state->nresvc, &__state->ncomr, &__state->ncomc, &
		    __state->free, &__state->tbmxad[(i__1 = __state->fidx * 3 
		    - 3) < 60 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "tbmxad", i__1, "dasa2l_", (ftnlen)
		    860)], __state->lstrec, __state->lstwrd);
	    if (failed_(__global_state)) {

/*              Make sure the current table entry won't be found */
/*              on a subsequent search. */

		__state->tbhan[(i__1 = __state->fidx - 1) < 20 && 0 <= i__1 ? 
			i__1 : s_rnge(&__global_state->f2c, "tbhan", i__1, 
			"dasa2l_", (ftnlen)875)] = 0;
		return 0;
	    }

/*           Set the forward cluster pointer. */

	    __state->tbfwrd[(i__1 = __state->fidx - 1) < 20 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "tbfwrd", i__1, "das"
		    "a2l_", (ftnlen)883)] = __state->nresvr + __state->ncomr + 
		    2;
	}

/*        TBMXAD is set. */

/*        If this is an unknown file and is read-only, determine */
/*        whether the file is segregated */

	if (! __state->known && __state->tbrdon[(i__1 = __state->fidx - 1) < 
		20 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "tbrdon"
		, i__1, "dasa2l_", (ftnlen)893)]) {

/*           The file is read-only; we need to know whether it is */
/*           segregated. If so, there are at most three cluster */
/*           descriptors, and the first directory record's maximum */
/*           address for each type matches the last logical address for */
/*           that type. */

/*           FAST has been initialized to .FALSE. above. */

/*           NREC is the record number of the first directory record. */

	    __state->nrec = __state->tbfwrd[(i__1 = __state->fidx - 1) < 20 &&
		     0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "tbfwrd",
		     i__1, "dasa2l_", (ftnlen)905)];
	    dasrri_(__global_state, handle, &__state->nrec, &__state->c__1, &
		    __state->c__256, __state->dirrec);
	    __state->nxtrec = __state->dirrec[1];
	    if (__state->nxtrec <= 0) {

/*              If this file is segregated, there are at most three */
/*              cluster descriptors, and each one points to a cluster */
/*              containing all records of the corresponding data type. */
/*              For each data type having a non-zero maximum address, */
/*              the size of the corresponding cluster must be large */
/*              enough to hold all addresses of that type. */

		__state->ntypes = 0;
		for (__state->i__ = 1; __state->i__ <= 3; ++__state->i__) {
		    if (__state->tbmxad[(i__1 = __state->i__ + __state->fidx *
			     3 - 4) < 60 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "tbmxad", i__1, "dasa2l_", (
			    ftnlen)924)] > 0) {
			++__state->ntypes;
		    }
		}

/*              Now look at the first NTYPES cluster descriptors, */
/*              collecting cluster bases and sizes as we go. */

		__state->baserc = __state->nrec + 1;
		__state->prvtyp = __state->prev[(i__1 = __state->dirrec[8] - 
			1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "prev", i__1, "dasa2l_", (ftnlen)
			935)];
		__state->dscloc = 10;
		__state->segok = TRUE_;
		while(__state->dscloc <= __state->ntypes + 9 && 
			__state->segok) {

/*                 Find the type of the current descriptor. */

		    if (__state->dirrec[(i__1 = __state->dscloc - 1) < 256 && 
			    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			    "dirrec", i__1, "dasa2l_", (ftnlen)944)] > 0) {
			__state->curtyp = __state->next[(i__1 = 
				__state->prvtyp - 1) < 3 && 0 <= i__1 ? i__1 :
				 s_rnge(&__global_state->f2c, "next", i__1, 
				"dasa2l_", (ftnlen)945)];
		    } else {
			__state->curtyp = __state->prev[(i__1 = 
				__state->prvtyp - 1) < 3 && 0 <= i__1 ? i__1 :
				 s_rnge(&__global_state->f2c, "prev", i__1, 
				"dasa2l_", (ftnlen)947)];
		    }
		    __state->prvtyp = __state->curtyp;
		    __state->tbbase[(i__1 = __state->curtyp + __state->fidx * 
			    3 - 4) < 60 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "tbbase", i__1, "dasa2l_", (
			    ftnlen)951)] = __state->baserc;
		    __state->tbsize[(i__1 = __state->curtyp + __state->fidx * 
			    3 - 4) < 60 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "tbsize", i__1, "dasa2l_", (
			    ftnlen)952)] = (i__3 = __state->dirrec[(i__2 = 
			    __state->dscloc - 1) < 256 && 0 <= i__2 ? i__2 : 
			    s_rnge(&__global_state->f2c, "dirrec", i__2, 
			    "dasa2l_", (ftnlen)952)], abs(i__3));
		    __state->baserc += __state->tbsize[(i__1 = 
			    __state->curtyp + __state->fidx * 3 - 4) < 60 && 
			    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			    "tbsize", i__1, "dasa2l_", (ftnlen)953)];
		    __state->segok = __state->tbmxad[(i__1 = __state->curtyp 
			    + __state->fidx * 3 - 4) < 60 && 0 <= i__1 ? i__1 
			    : s_rnge(&__global_state->f2c, "tbmxad", i__1, 
			    "dasa2l_", (ftnlen)956)] <= __state->tbsize[(i__2 
			    = __state->curtyp + __state->fidx * 3 - 4) < 60 &&
			     0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
			    "tbsize", i__2, "dasa2l_", (ftnlen)956)] * 
			    __state->nw[(i__3 = __state->curtyp - 1) < 3 && 0 
			    <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
			    "nw", i__3, "dasa2l_", (ftnlen)956)];
		    ++__state->dscloc;

/*                 This loop will terminate after at most 3 */
/*                 iterations. No further checks are needed. */

		}

/*              Update FAST and TBFAST based on the segregation check. */

		__state->fast = __state->segok;
		__state->tbfast[(i__1 = __state->fidx - 1) < 20 && 0 <= i__1 ?
			 i__1 : s_rnge(&__global_state->f2c, "tbfast", i__1, 
			"dasa2l_", (ftnlen)970)] = __state->fast;

/*              If the file is FAST, */

/*                 TBBASE */
/*                 TBSIZE */

/*              have been updated as well. */

	    }
	}

/*        End of the segregation check. */

    }

/*     End of the NOT FAST or NOT SAME case. */

/*     At this point we have the logical address ranges for the */
/*     file. Check the input address against them. */

    __state->mxaddr = __state->tbmxad[(i__1 = *type__ + __state->fidx * 3 - 4)
	     < 60 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "tbmxad",
	     i__1, "dasa2l_", (ftnlen)992)];
    if (*addrss < 1 || *addrss > __state->mxaddr) {

/*        Make sure the current table entry won't be found on a */
/*        subsequent search. */

	__state->tbhan[(i__1 = __state->fidx - 1) < 20 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "tbhan", i__1, "dasa2l_", (
		ftnlen)999)] = 0;
	chkin_(__global_state, "DASA2L", (ftnlen)6);
	setmsg_(__global_state, "ADDRSS was #; valid range for type # is # t"
		"o #.  File was #", (ftnlen)59);
	errint_(__global_state, "#", addrss, (ftnlen)1);
	errint_(__global_state, "#", type__, (ftnlen)1);
	errint_(__global_state, "#", &__state->c__1, (ftnlen)1);
	errint_(__global_state, "#", &__state->mxaddr, (ftnlen)1);
	errhan_(__global_state, "#", handle, (ftnlen)1);
	sigerr_(__global_state, "SPICE(DASNOSUCHADDRESS)", (ftnlen)23);
	chkout_(__global_state, "DASA2L", (ftnlen)6);
	return 0;
    }

/*     If we're looking at a "fast" file, we know the cluster base and */
/*     size. HIADDR is the highest address (not necessarily in use) in */
/*     the cluster. */

    if (__state->tbfast[(i__1 = __state->fidx - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "tbfast", i__1, "dasa2l_", (ftnlen)
	    1020)]) {

/*        The current file is "fast": read-only and segregated. */

	*clbase = __state->tbbase[(i__1 = *type__ + __state->fidx * 3 - 4) < 
		60 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "tbbase"
		, i__1, "dasa2l_", (ftnlen)1024)];
	*clsize = __state->tbsize[(i__1 = *type__ + __state->fidx * 3 - 4) < 
		60 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "tbsize"
		, i__1, "dasa2l_", (ftnlen)1025)];
	__state->hiaddr = *clsize * __state->nw[(i__1 = *type__ - 1) < 3 && 0 
		<= i__1 ? i__1 : s_rnge(&__global_state->f2c, "nw", i__1, 
		"dasa2l_", (ftnlen)1026)];
    } else {

/*        If we're not looking at a "fast" file, find the cluster */
/*        containing the input address, for the input data type. */

/*        Find out which directory describes the cluster containing this */
/*        word. To do this, we must traverse the directory list. The */
/*        first directory record comes right after the last comment */
/*        record. (Don't forget the file record when counting the */
/*        predecessors of the directory record.) */

/*        Note that we don't need to worry about not finding a directory */
/*        record that contains the address we're looking for, since */
/*        we've already checked that the address is in range. */

	__state->nrec = __state->tbfwrd[(i__1 = __state->fidx - 1) < 20 && 0 
		<= i__1 ? i__1 : s_rnge(&__global_state->f2c, "tbfwrd", i__1, 
		"dasa2l_", (ftnlen)1043)];
	__state->ndirs = 1;
	i__3 = __state->rngloc[(i__2 = *type__ - 1) < 3 && 0 <= i__2 ? i__2 : 
		s_rnge(&__global_state->f2c, "rngloc", i__2, "dasa2l_", (
		ftnlen)1046)] + 1;
	dasrri_(__global_state, handle, &__state->nrec, &__state->rngloc[(
		i__1 = *type__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "rngloc", i__1, "dasa2l_", (ftnlen)1046)]
		, &i__3, __state->range);
	while(__state->range[1] < *addrss) {

/*           The record number of the next directory is the forward */
/*           pointer in the current directory record. Update NREC with */
/*           this pointer. Get the address range for the specified type */
/*           covered by this next directory record. */

	    dasrri_(__global_state, handle, &__state->nrec, &__state->c__2, &
		    __state->c__2, &__state->nxtrec);
	    __state->nrec = __state->nxtrec;
	    ++__state->ndirs;
	    i__3 = __state->rngloc[(i__2 = *type__ - 1) < 3 && 0 <= i__2 ? 
		    i__2 : s_rnge(&__global_state->f2c, "rngloc", i__2, "das"
		    "a2l_", (ftnlen)1065)] + 1;
	    dasrri_(__global_state, handle, &__state->nrec, &__state->rngloc[(
		    i__1 = *type__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "rngloc", i__1, "dasa2l_", (ftnlen)
		    1065)], &i__3, __state->range);
	    if (failed_(__global_state)) {

/*              Make sure the current table entry won't be found */
/*              on a subsequent search. */

		__state->tbhan[(i__1 = __state->fidx - 1) < 20 && 0 <= i__1 ? 
			i__1 : s_rnge(&__global_state->f2c, "tbhan", i__1, 
			"dasa2l_", (ftnlen)1076)] = 0;
		return 0;
	    }
	}

/*        NREC is now the record number of the directory that contains */
/*        the type descriptor for the address we're looking for. */

/*        Our next task is to find the descriptor for the cluster */
/*        containing the input address. To do this, we must examine the */
/*        directory record in `left-to-right' order. As we do so, we'll */
/*        keep track of the highest address of type TYPE occurring in */
/*        the clusters whose descriptors we've seen. The variable HIADDR */
/*        will contain this address. */

	dasrri_(__global_state, handle, &__state->nrec, &__state->c__1, &
		__state->c__256, __state->dirrec);
	if (failed_(__global_state)) {

/*           Make sure the current table entry won't be found on a */
/*           subsequent search. */

	    __state->tbhan[(i__1 = __state->fidx - 1) < 20 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "tbhan", i__1, "dasa"
		    "2l_", (ftnlen)1102)] = 0;
	    return 0;
	}

/*        In the process of finding the physical location corresponding */
/*        to ADDRSS, we'll find the record number of the base of the */
/*        cluster containing ADDRSS. We'll start out by initializing */
/*        this value with the number of the first data record of the */
/*        next cluster. */

	*clbase = __state->nrec + 1;

/*        We'll initialize HIADDR with the value preceding the lowest */
/*        address of type TYPE described by the current directory. */

	__state->hiaddr = __state->dirrec[(i__2 = __state->rngloc[(i__1 = *
		type__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "rngloc", i__1, "dasa2l_", (ftnlen)1121)]
		 - 1) < 256 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c,
		 "dirrec", i__2, "dasa2l_", (ftnlen)1121)] - 1;

/*        Initialize the number of records described by the last seen */
/*        type descriptor. This number, when added to CLBASE, should */
/*        yield the number of the first record of the current cluster; */
/*        that's why it's initialized to 0. */

	*clsize = 0;

/*        Now find the descriptor for the cluster containing ADDRSS. */
/*        Read descriptors until we get to the one that describes the */
/*        record containing ADDRSS. Keep track of descriptor data */
/*        types as we go. Also count the descriptors. */

/*        At this point, HIADDR is less than ADDRSS, so the loop will */
/*        always be executed at least once. */

	__state->prvtyp = __state->prev[(i__1 = __state->dirrec[8] - 1) < 3 &&
		 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "prev", i__1,
		 "dasa2l_", (ftnlen)1140)];
	__state->dscloc = 10;
	while(__state->hiaddr < *addrss) {
	    if (__state->dscloc > 256) {

/*              This situation shouldn't occur, but it might if the */
/*              DAS file is corrupted. */

/*              Make sure the current table entry won't be found */
/*              on a subsequent search. */

		__state->tbhan[(i__1 = __state->fidx - 1) < 20 && 0 <= i__1 ? 
			i__1 : s_rnge(&__global_state->f2c, "tbhan", i__1, 
			"dasa2l_", (ftnlen)1153)] = 0;
		chkin_(__global_state, "DASA2L", (ftnlen)6);
		setmsg_(__global_state, "Directory record # in DAS file with"
			" handle # is probably corrupted. No high cluster add"
			"ress at or above the input address # was found, thou"
			"gh it should have been. High address was #. Data typ"
			"e was #.", (ftnlen)199);
		errint_(__global_state, "#", &__state->nrec, (ftnlen)1);
		errint_(__global_state, "#", handle, (ftnlen)1);
		errint_(__global_state, "#", addrss, (ftnlen)1);
		errint_(__global_state, "#", &__state->hiaddr, (ftnlen)1);
		errint_(__global_state, "#", type__, (ftnlen)1);
		sigerr_(__global_state, "SPICE(BADDASDIRECTORY)", (ftnlen)22);
		chkout_(__global_state, "DASA2L", (ftnlen)6);
		return 0;
	    }

/*           Update CLBASE so that it is the record number of the */
/*           first record of the current cluster. */

	    *clbase += *clsize;

/*           Find the type of the current descriptor. */

	    if (__state->dirrec[(i__1 = __state->dscloc - 1) < 256 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "dirrec", i__1,
		     "dasa2l_", (ftnlen)1180)] > 0) {
		__state->curtyp = __state->next[(i__1 = __state->prvtyp - 1) <
			 3 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			"next", i__1, "dasa2l_", (ftnlen)1181)];
	    } else {
		__state->curtyp = __state->prev[(i__1 = __state->prvtyp - 1) <
			 3 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			"prev", i__1, "dasa2l_", (ftnlen)1183)];
	    }

/*           Forgetting to update PRVTYP is a Very Bad Thing (VBT). */

	    __state->prvtyp = __state->curtyp;

/*           If the current descriptor is of the type we're interested */
/*           in, update the highest address count. */

	    if (__state->curtyp == *type__) {
		__state->hiaddr += __state->nw[(i__3 = *type__ - 1) < 3 && 0 
			<= i__3 ? i__3 : s_rnge(&__global_state->f2c, "nw", 
			i__3, "dasa2l_", (ftnlen)1196)] * (i__2 = 
			__state->dirrec[(i__1 = __state->dscloc - 1) < 256 && 
			0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "dir"
			"rec", i__1, "dasa2l_", (ftnlen)1196)], abs(i__2));
	    }

/*           Compute the number of records described by the current */
/*           descriptor. Update the descriptor location. */

	    *clsize = (i__2 = __state->dirrec[(i__1 = __state->dscloc - 1) < 
		    256 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "dirrec", i__1, "dasa2l_", (ftnlen)1203)], abs(i__2));
	    ++__state->dscloc;
	}

/*        At this point, the variables */

/*           CLBASE */
/*           CLSIZE */
/*           HIADDR */

/*        are set. */

    }

/*     At this point, */

/*        -- CLBASE is properly set: it is the record number of the */
/*           first record of the cluster containing ADDRSS. */

/*        -- CLSIZE is properly set: it is the size of the cluster */
/*           containing ADDRSS. */

/*        -- HIADDR is the last logical address in the cluster */
/*           containing ADDRSS. */

/*     Now we must find the physical record and word corresponding */
/*     to ADDRSS. The structure of the cluster containing ADDRSS and */
/*     HIADDR is shown below: */

/*        +--------------------------------------+ */
/*        |                                      |  Record # CLBASE */
/*        +--------------------------------------+ */
/*                           . */
/*                           . */
/*                           . */
/*        +--------------------------------------+ */
/*        |      |ADDRSS|                        |  Record # RECNO */
/*        +--------------------------------------+ */
/*                           . */
/*                           . */
/*                           . */
/*        +--------------------------------------+  Record # */
/*        |                               |HIADDR| */
/*        +--------------------------------------+  CLBASE + CLSIZE - 1 */


    *recno = *clbase + *clsize - 1 - (__state->hiaddr - *addrss) / 
	    __state->nw[(i__1 = *type__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(
	    &__global_state->f2c, "nw", i__1, "dasa2l_", (ftnlen)1251)];
    *wordno = *addrss - (*addrss - 1) / __state->nw[(i__1 = *type__ - 1) < 3 
	    && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "nw", i__1, 
	    "dasa2l_", (ftnlen)1254)] * __state->nw[(i__2 = *type__ - 1) < 3 
	    && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "nw", i__2, 
	    "dasa2l_", (ftnlen)1254)];

/*     Update PRVHAN and set PRVOK to .TRUE. only if the call succeeded. */

    __state->prvhan = *handle;
    __state->prvok = TRUE_;
    return 0;
} /* dasa2l_ */

