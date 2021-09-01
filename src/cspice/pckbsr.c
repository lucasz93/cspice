/* pckbsr.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern pckbsr_init_t __pckbsr_init;
static pckbsr_state_t* get_pckbsr_state(cspice_t* state) {
	if (!state->pckbsr)
		state->pckbsr = __cspice_allocate_module(sizeof(
	pckbsr_state_t), &__pckbsr_init, sizeof(__pckbsr_init));
	return state->pckbsr;

}

/* $Procedure PCKBSR ( PCK, buffer segments for readers ) */
/* Subroutine */ int pckbsr_0_(cspice_t* __global_state, int n__, char *fname,
	 integer *handle, integer *body, doublereal *et, doublereal *descr, 
	char *ident, logical *found, ftnlen fname_len, ftnlen ident_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer head;
    integer tail;
    integer cost;
    integer i__;
    integer j;
    extern /* Subroutine */ int dafgn_(cspice_t*, char *, ftnlen);
    integer cheap;
    integer p;
    extern /* Subroutine */ int dafgs_(cspice_t*, doublereal *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    char doing[15];
    extern /* Subroutine */ int dafus_(cspice_t*, doublereal *, integer *, 
	    integer *, doublereal *, integer *);
    char stack[15*2];
    extern doublereal dpmin_(cspice_t*);
    extern /* Subroutine */ int lnkan_(cspice_t*, integer *, integer *);
    extern doublereal dpmax_(cspice_t*);
    extern /* Subroutine */ int moved_(cspice_t*, doublereal *, integer *, 
	    doublereal *);
    extern integer lnktl_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int daffna_(cspice_t*, logical *);
    extern /* Subroutine */ int dafbbs_(cspice_t*, integer *);
    extern /* Subroutine */ int daffpa_(cspice_t*, logical *);
    extern logical failed_(cspice_t*);
    extern /* Subroutine */ int dafbfs_(cspice_t*, integer *);
    extern /* Subroutine */ int cleard_(cspice_t*, integer *, doublereal *);
    extern /* Subroutine */ int dafcls_(cspice_t*, integer *);
    logical fndhan;
    integer crflbg;
    integer bindex;
    extern /* Subroutine */ int lnkila_(cspice_t*, integer *, integer *, 
	    integer *);
    integer findex;
    extern /* Subroutine */ int dafopr_(cspice_t*, char *, integer *, ftnlen);
    extern integer isrchi_(cspice_t*, integer *, integer *, integer *);
    extern /* Subroutine */ int lnkilb_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int lnkini_(cspice_t*, integer *, integer *);
    extern integer lnknfn_(cspice_t*, integer *);
    extern /* Subroutine */ int lnkfsl_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern integer intmax_(cspice_t*);
    char urgent[15];
    integer minexp;
    integer nxtseg;
    extern integer lnkprv_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern integer lnknxt_(cspice_t*, integer *, integer *);
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    char status[15];
    doublereal dcd[2];
    integer icd[5];
    logical fnd;
    integer new__;
    integer top;


    /* Module state */
    pckbsr_state_t* __state = get_pckbsr_state(__global_state);
/* $ Abstract */

/*     Load and unload PCK binary files for use by the readers. */
/*     Buffer segments for readers. */

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

/*     PCK */

/* $ Keywords */

/*     PCK */
/*     FILES */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Entry points */
/*     --------  ---  -------------------------------------------------- */
/*     FNAME      I   PCKLOF */
/*     HANDLE    I/O  PCKLOF, PCKUOF, PCKSFS */
/*     BODY       I   PCKSFS */
/*     ET         I   PCKSFS */
/*     DESCR      O   PCKSFS */
/*     IDENT      O   PCKSFS */

/* $ Detailed_Input */

/*     FNAME      is the name of an PCK file to be loaded. */

/*     HANDLE     on input is the handle of an PCK file to be */
/*                unloaded. */

/*     BODY       is the NAIF integer code of an ephemeris object, */
/*                typically a solar system body. */

/*     ET         is a time, in seconds past the epoch J2000 TDB. */

/* $ Detailed_Output */

/*     HANDLE     on output is the handle of the binary PCK file */
/*                containing a located segment. */

/*     DESCR      is the descriptor of a located segment. */

/*     IDENT      is the identifier of a located segment. */

/*     FOUND      is a logical flag indicating whether a segment meeting */
/*                the search criteria was found. FOUND will have the */
/*                value .TRUE. if an appropriate segment was found during */
/*                the search; it will have the value of .FALSE. */
/*                otherwise. If FOUND has the value .FALSE., then either */
/*                an appropriate segment could not be found in any of the */
/*                loaded files or there were no PCK kernel files loaded */
/*                when the request for a segment was made. */

/* $ Parameters */

/*     FTSIZE     is the maximum number of files that may be loaded */
/*                by PCKLOF at any given time for use by the PCK readers. */

/*     BTSIZE     is the maximum number of bodies whose segments can be */
/*                buffered by PCKSFS. */

/*     STSIZE     Maximum number of segments that can be buffered at any */
/*                given time by PCKSFS. */

/* $ Exceptions */

/*     1) If PCKBSR is called directly, the error 'SPICE(BOGUSENTRY)' */
/*        is signaled. */

/*     2) See entry points PCKLOF, PCKUOF, and PCKSFS for exceptions */
/*        specific to them. */

/* $ Files */

/*     PCK kernel  files are indicated by filename before loading */
/*     (see PCKLOF) and handle after loading (all other places). */

/* $ Particulars */

/*     PCKBSR serves as an umbrella, allowing data to be shared by its */
/*     entry points: */

/*        PCKLOF       Load PCK binary file. */
/*        PCKUOF       Unload PCK binary file. */
/*        PCKSFS       Select file and segment. */

/*     Before a file can be read by the PCK kernel readers, it must be */
/*     loaded by PCKLOF, which among other things, calls routines to */
/*     open the specified file. */

/*     Multiple files may be loaded for use simultaneously, and a file */
/*     need only be loaded once to become a potential search target */
/*     for any number of subsequent reads. */

/*     Once a PCK kernel file is loaded and opened, it is assigned a file */
/*     handle, which is used by the calling program to refer to the file */
/*     in all subsequent calls to PCK routines. */

/*     A file may be removed from the list of files searched by using */
/*     PCKUOF to unload it. */

/*     PCKSFS performs the search for segments within a file for the */
/*     PCK kernel readers.  It searches through the most recently loaded */
/*     files first.  Within a single file, PCKSFS searches through */
/*     the segments in reverse order, beginning with the last segment in */
/*     the file.  The search stops when the first appropriate segment is */
/*     found or all files and segments have been searched without a */
/*     match. */

/*     PCKSFS buffers information from loaded PCK files to improve access */
/*     time by preventing unnecessary file reads during segment searches. */

/* $ Examples */

/*     Example 1: */
/*     --------- */

/*     Suppose that the data of interest are contained in the file */
/*     THE_MISSION.PCK, and that we want to generate a table containing */
/*     the descriptors of the PCK segments, or a message indicating that */
/*     no segment was found, for various request times. We are interested */
/*     in the data coverage of the segments in the file. */

/*     Let */

/*        PCK_HANDL      be the handle for the mission PCK file. */
/*        HANDLE         be the handle obtained from a segment search. In */
/*                       this example, because there is only a single */
/*                       file, this will always have the same value. */
/*        BODY           be the NAIF ID code for the body of interest. */
/*        BEG_ET         be the beginning epoch for a data table that */
/*                       is generated. */
/*        END_ET         be the ending epoch for a data table that is */
/*                       generated. */
/*        DELTA          be the time step, in seconds, between */
/*                       consecutive times for a data table that is */
/*                       generated. */
/*        ET             be the epoch of interest for a segment */
/*                       search to get a data table entry. */
/*        DESCR ( 5 )    be the descriptor of the PCK segment that is */
/*                       found. */
/*        IDENT          be the identifier of the PCK segment that is */
/*                       found. */
/*        TABLE          be the logical unit for the data table that is */
/*                       generated. */
/*        ENTRY          be a string to hold a formatted PCK segment */
/*                       descriptor which is to be written to the table. */
/*        FOUND          be a logical flag indicating that an */
/*                       appropriate PCK segment has been found. */

/*     The two routine names FORMAT_ENTRY and WRITE_ENTRY are used here */
/*     for purposes of demonstration only. Routines with these names do */
/*     not exist in SPICELIB. FORMAT_ENTRY is used to format a PCK */
/*     segment descriptor into a character string for the table */
/*     generated, and WRITE_ENTRY is used to write an entry to the file. */

/*     The code fragment below loads PCK files and performs searches for */
/*     various epochs, generating a table containing the segment */
/*     descriptors, if found, or a message indicating that a segment */
/*     descriptor was not found. */

/*     C */
/*     C     Load the mission PCK file. */
/*     C */
/*           CALL PCKLOF ( 'THE_MISSION.PCK',  PCK_HANDL ) */

/*     C */
/*     C     Search for segments using evenly spaced epochs between */
/*     C     BEG_ET and END_ET. */
/*     C */
/*           ET = BEG_ET */

/*           DO WHILE ( ET .LE. END_ET ) */

/*     C */
/*     C        Locate the applicable segment (handle and descriptor). */
/*     C */
/*              CALL PCKSFS ( BODY, ET, HANDLE, DESCR, IDENT, FOUND ) */

/*              IF ( FOUND ) THEN */

/*                 CALL FORMAT_ENTRY ( DESCR, ENTRY ) */

/*              ELSE */

/*                 ENTRY = '***** SEGMENT NOT FOUND *****' */

/*              END IF */

/*              CALL WRITE_ENTRY ( ET, ENTRY, TABLE ) */

/*     C */
/*     C        Increment the epoch. */
/*     C */
/*              ET = ET + DELTA */

/*           END DO */

/*     Example 2: */
/*     --------- */

/*     In this example multiple PCK files are loaded and searched for */
/*     segments. */

/*     Let */

/*        PCK_HANDL      be the handle used when loading PCK files. */
/*        HANDLE         be the handle obtained from a segment search. In */
/*                       this example, because there is only a single */
/*                       file, this will always have the same value. */
/*        BODY           be the NAIF ID code for the body of interest. */
/*        ET             be the epoch of interest for a segment */
/*                       search to get a data table entry. */
/*        DESCR ( 5 )    be the descriptor of the PCK segment that is */
/*                       found. */
/*        IDENT          be the identifier of the PCK segment that is */
/*                       found. */
/*        FOUND          be a logical flag indicating that an */
/*                       appropriate PCK segment has been found. */

/*     The code fragment below loads several PCK files and then performs */
/*     a search for an appropriate segment. */

/*     C */
/*     C     Load the PCK files. We can reuse the variable PCK_HANDL */
/*     C     because the handle for the appropriate file is returned by */
/*     C     the search. */
/*     C */
/*           CALL PCKLOF ( 'FIRST.PCK',   PCK_HNDL ) */
/*           CALL PCKLOF ( 'SECOND.PCK',  PCK_HNDL ) */
/*           CALL PCKLOF ( 'THIRD.PCK',   PCK_HNDL ) */
/*           CALL PCKLOF ( 'FOURTH.PCK',  PCK_HNDL ) */
/*           CALL PCKLOF ( 'FIFTH.PCK',   PCK_HNDL ) */

/*     C */
/*     C     Do some computation that yields a body and epoch */
/*     C     of interest. */
/*     C */
/*                              . */
/*                              . */
/*                              . */
/*     C */
/*     C     Search for an appropriate segment in the loaded files. */
/*     C */

/*           CALL PCKSFS ( BODY, ET, HANDLE, DESCR, IDENT, FOUND ) */

/*           IF ( FOUND ) THEN */

/*              Display results. */

/*           ELSE */

/*              WRITE (*,*) 'Sorry, no segment was found.' */

/*           END IF */


/* $ Restrictions */

/*     1) If Fortran I/O errors occur while searching a loaded PCK */
/*        file, the internal state of this suite of routines may */
/*        be corrupted.  It may be possible to correct the state */
/*        by unloading the pertinent PCK files and then re-loading */
/*        them. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     K.S. Zukor      (JPL) */
/*     J.M. Lynch      (JPL) */
/*     R.E. Thurman    (JPL) */
/*     W.L. Taber      (JPL) */
/*     B.V. Semenov    (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.1, 30-JAN-2017 (NJB) */

/*        Corrected various spelling errors within comments. */

/* -    SPICELIB Version 2.0.0, 17-MAR-2014 (NJB) */

/*        Updated segment pool initialization condition in entry */
/*        point PCKLOF so that the pool is initialized only if the file */
/*        table is empty. */

/* -    SPICELIB Version 1.4.0, 03-JAN-2014 (BVS)(EDW) */

/*        Minor edits to Procedure; clean trailing whitespace. */

/*        Increased FTSIZE (from 1000 to 5000). */

/*        Increased STSIZE (from 100 to 5000). */

/* -    SPICELIB Version 1.3.0, 01-MAR-2011 (NJB) */

/*        Bug fix: */

/*          In the PCKSFS 'MAKE ROOM' state, when the suspended activity */
/*          is 'ADD TO FRONT' and no segment table room is available, */
/*          the body table's pointer to the current segment list */
/*          is now set to null. Previously the pointer was allowed to go */
/*          stale. */

/* -    SPICELIB Version 1.2.0, 08-SEP-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in MOVED calls in entry points PCKUOF and PCKSFS. */

/* -    SPICELIB Version 1.1.0, 08-NOV-2001 (NJB) */

/*        Bug fixes: */

/*           1) When a segment list is freed because the entire list */
/*              is contributed by a single PCK file, and the list is */
/*              too large to be buffered, the corresponding body table */
/*              pointer is now set to null. */

/*           2) An algorithm change has eliminated a bug caused by not */
/*              updating the current body index when body table entries */
/*              having empty segment lists were compressed out of the */
/*              body table.  Previously the body table pointer BINDEX */
/*              could go stale after the compression. */

/*           3) When a already loaded kernel is re-opened with DAFOPR, */
/*              it now has its link count reset to 1 via a call to */
/*              DAFCLS. */

/*           4) The load routine PCKLOF now resets all file numbers when */
/*              the next file number reaches INTMAX()-1, thereby */
/*              avoiding arithmetic overflow. */

/*           5) The unload routine PCKUOF now calls RETURN() on entry and */
/*              returns if so directed. */

/*           6) In PCKSFS, DAF calls are followed by tests of FAILED() */
/*              in order to ensure that the main state loop terminates. */

/*           7) In PCKSFS, a subscript bound violation in a loop */
/*              termination test was corrected. */

/*        The "re-use interval" feature was introduced to improve speed */
/*        in the case where repeated, consecutive requests are satisfied */
/*        by the same segment.  For each body, the associated re-use */
/*        interval marks the time interval containing the previous */
/*        request time for which the previously returned segment provides */
/*        the  highest-priority data available. */

/*        The segment list cost algorithm was modified slightly: */
/*        the contribution of a file search to the cost of a list */
/*        is included only when the file search is completed.  The */
/*        cost of finding the re-use interval is accounted for when */
/*        unbuffered searches are required. */

/*        The file table size has been increased to 1000, in order */
/*        to take advantage of the DAF system's new ability to load */
/*        1000 files. */

/*        Various small updates and corrections were made to the */
/*        comments throughout the file. */

/*        In order to simplify the source code, the in-line singly */
/*        linked list implementation of the segment table has been */
/*        replaced by an implementation relying on the SPICELIB */
/*        doubly linked list routines. */

/* -    SPICELIB Version 1.0.0, 16-MAR-1994 (KSZ) */

/*        This differs only slightly from the SPKXXX code. */
/*        The main difference is that the SFS subroutine returns */
/*        FOUND = .FALSE. if no files are found, rather than returning */
/*        an error. */

/* -& */
/* $ Index_Entries */

/*     buffer PCK segments for readers */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Constants used in the doubly linked list structure: */


/*     Local variables */



/*     The file table contains the handle and file number of each file */
/*     that has been loaded for use with the PCK readers. File */
/*     numbers begin at one, and are incremented until they reach a */
/*     value of INTMAX() - 1, at which point they are mapped to the */
/*     range 1:NFT, where NFT is the number of loaded PCK files. */

/*     (A file number is similar to a file handle, but it is assigned */
/*     and used exclusively by this module. The purpose of file numbers */
/*     is to keep track of the order in which files are loaded and the */
/*     order in which they are searched.) */

/*     All names begin with FT. */

/*        HAN      Handle */
/*        NUM      File number */

/*     NFT is the number of files that have been loaded. NEXT is */
/*     incremented whenever a new file is loaded to give the file */
/*     number of the file. FINDEX is the index of whatever file is */
/*     of current interest at any given time. */

/*     New files are added at the end of the table. As files are */
/*     removed, succeeding files are moved forward to take up the */
/*     slack. This keeps the table ordered by file number. */


/*     The body table contains the beginning of the list of the stored */
/*     segments for each body, and the expense at which that list */
/*     was constructed. (The expense of a body list is the number of */
/*     segment descriptors examined during the construction of the list.) */
/*     It also contains the highest and lowest file numbers searched */
/*     during the construction of the list. */

/*     For each body, the time bounds of the "re-use interval" of the */
/*     last segment found are stored.  This interval is the maximal */
/*     interval containing the epoch of the last request for data for */
/*     this body, such that the interval is not masked by higher-priority */
/*     segments.  The handle, segment descriptor, and segment identifier */
/*     returned on the last request are also stored. */

/*     All names begin with BT. */

/*        BOD      Body */
/*        EXP      Expense */
/*        HFS      Highest file (number) searched */
/*        LFS      Lowest  file (number) searched */
/*        BEG      Beginning of segment list */
/*        LB       Lower bound of the re-use interval of */
/*                 previous segment returned. */
/*        UB       Upper bound of the re-use interval of */
/*                 previous segment returned. */
/*        PRVD     Previous descriptor returned. */
/*        PRVI     Previous segment identifier returned. */
/*        PRVH     Previous handle returned. */
/*        CHKP     Logical indicating that previous segment should */
/*                 be checked to see whether it satisfies a request. */
/*        RUEX     Expense of the re-use interval. */

/*     NBT is the number of bodies for which segments are currently */
/*     being stored in the table. BINDEX is the index of whatever */
/*     body is of current interest at any given time. */

/*     New bodies are added at the end of the table. As bodies are */
/*     removed, the last body is moved forward to take up the slack. */
/*     This keeps the entries in the table contiguous. */


/*     The segment table contains the handle, descriptor, and identifier */
/*     for each segment that has been found so far. */

/*     The segment table is implemented as a set of arrays indexed by */
/*     a SPICE doubly linked list structure.  For each body in the */
/*     body table, there is a segment table list; each node of a list */
/*     points to data associated with a segment.  In each list, the head */
/*     node corresponds to the highest-priority segment in that list, */
/*     and segment priority decreases in the forward direction. */

/*     All names begin with ST. */

/*        POOL     Doubly linked list pool. */
/*        HAN      Handle */
/*        DES      Descriptor */
/*        IDNT     Identifier */

/*     New segments are added to the front or end of a body list */
/*     as appropriate, according to the rules spelled out under */
/*     entry point PCKSFS. */


/*     Other stuff */


/*     Saved variables */


/*     Initial values */

    /* Parameter adjustments */
    if (descr) {
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_pcklof;
	case 2: goto L_pckuof;
	case 3: goto L_pcksfs;
	}


/*     Nobody has any business calling PCKBSR directly. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "PCKBSR", (ftnlen)6);
    sigerr_(__global_state, "SPICE(BOGUSENTRY)", (ftnlen)17);
    chkout_(__global_state, "PCKBSR", (ftnlen)6);
    return 0;
/* $Procedure PCKLOF ( PCK, load binary file ) */

L_pcklof:
/* $ Abstract */


/*     Load a binary PCK file for use by the readers.  Return the */
/*     handle of the loaded file which is used by other PCK routines to */
/*     refer to the file. */

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

/*     PCK */

/* $ Keywords */

/*     PCK */
/*     FILES */

/* $ Declarations */

/*     CHARACTER*(*)         FNAME */
/*     INTEGER               HANDLE */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     FNAME      I   Name of the file to be loaded. */
/*     HANDLE     O   Loaded file's handle. */
/*     FTSIZE     P   Maximum number of loaded PCK files. */

/* $ Detailed_Input */

/*     FNAME      Character name of the file to be loaded. */

/* $ Detailed_Output */

/*     HANDLE     Integer handle assigned to the file upon loading. */
/*                Almost every other PCK routine will subsequently use */
/*                this number to refer to the file. */

/* $ Parameters */

/*     FTSIZE     is the maximum number of PCK files that may */
/*                be loaded simultaneously under any circumstances. */
/*                FTSIZE is currently set to match the maximum number */
/*                of DAF files that may be loaded simultaneously. */

/* $ Exceptions */

/*     1) If an attempt is made to open more DAF files than is specified */
/*        by the parameter FTSIZE in DAFAH, an error is signaled by a */
/*        routine in the call tree of this routine. */

/*     2) If an attempt is made to load more files than is specified */
/*        by the local parameter FTSIZE, and if the DAF system has */
/*        room to load another file, the error SPICE(PCKFILETABLEFULL) */
/*        signaled.  The current setting of FTSIZE does not allow this */
/*        situation to arise:  the DAF system will trap the error */
/*        before this routine has the chance. */

/* $ Files */

/*     A file specified by FNAME, to be loaded.  The file is assigned a */
/*     handle by PCKLOF, which will be used by most other routines to */
/*     refer to it. */

/* $ Particulars */

/*     If there is room for a new file in the file table, PCKLOF creates */
/*     an entry for it and loads the file for reading using DAFOPR. */

/* $ Examples */

/*     See the Example above, in PCKBSR. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     K.S. Zukor      (JPL) */
/*     J.M. Lynch      (JPL) */
/*     R.E. Thurman    (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.1, 30-JAN-2017 (NJB) */

/*        Corrected various spelling errors within comments. */

/* -    SPICELIB Version 2.0.0, 17-MAR-2014 (NJB) */

/*        Updated segment pool initialization condition in entry */
/*        point PCKLOF so that the pool is initialized only if the file */
/*        table is empty. */

/* -    SPICELIB Version 1.1.1, 03-JAN-2014 (EDW) */

/*        Minor edits to Procedure; clean trailing whitespace. */
/*        Removed unneeded Revisions section. */

/* -    SPICELIB Version 1.1.0, 08-NOV-2001 (NJB) */

/*        Bug fixes: */

/*        1) When an already loaded kernel is opened with DAFOPR, */
/*           it now has its link count reset to 1 via a call to */
/*           DAFCLS. */

/*        2) This routine now resets all file numbers when */
/*           the next file number reaches INTMAX()-1, thereby avoiding */
/*           arithmetic overflow.  The numbers in the file table */
/*           are replaced with consecutive integers in the range */
/*           1 : NFT, such that the ordering of the numbers is not */
/*           changed.  The HFS and LFS arrays are updated accordingly. */

/*        Also, the flags indicating validity of the re-use intervals */
/*        are set to .FALSE. here. */

/* -    SPICELIB Version 1.0.0, 16-MAR-1994 (KSZ) */

/* -& */
/* $ Index_Entries */

/*     load PCK file */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "PCKLOF", (ftnlen)6);
    }

/*     Any time we load a file, there is a possibility that the */
/*     re-use intervals are invalid because they're been superseded */
/*     by higher-priority data.  Since we're not going to examine */
/*     the loaded file, simply indicate that all of the re-use */
/*     intervals are invalid. */

    i__1 = __state->nbt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	__state->btchkp[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "btchkp", i__2, "pckbsr_", (ftnlen)874)] 
		= FALSE_;
    }

/*     Nothing works unless at least one file has been loaded, so this */
/*     is as good a place as any to initialize the segment table pool. */
/*     We want to avoid unnecessary initializations, so we only */
/*     initialize the list when no files are loaded. It's quite possible */
/*     to have files loaded and an empty body table, so we don't */
/*     want to re-initialize just because there are no body table */
/*     entries. */

    if (__state->nft == 0) {
	lnkini_(__global_state, &__state->c__5000, __state->stpool);
    }

/*     To load a new file, first try to open it for reading. */

    dafopr_(__global_state, fname, handle, fname_len);
    if (failed_(__global_state)) {
	chkout_(__global_state, "PCKLOF", (ftnlen)6);
	return 0;
    }

/*     Determine if the file is already in the table. */

    findex = isrchi_(__global_state, handle, &__state->nft, __state->fthan);
    if (findex > 0) {

/*        The last call we made to DAFOPR added another DAF link to */
/*        the PCK file.  Remove this link. */

	dafcls_(__global_state, handle);

/*        Remove the file from the file table and remove its segments */
/*        from the segment table.  If the segment list for a body */
/*        becomes empty, remove that body from the body table. */

	--__state->nft;
	i__1 = __state->nft;
	for (i__ = findex; i__ <= i__1; ++i__) {
	    __state->fthan[(i__2 = i__ - 1) < 5000 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "fthan", i__2, "pckbsr_", (
		    ftnlen)920)] = __state->fthan[(i__3 = i__) < 5000 && 0 <= 
		    i__3 ? i__3 : s_rnge(&__global_state->f2c, "fthan", i__3, 
		    "pckbsr_", (ftnlen)920)];
	    __state->ftnum[(i__2 = i__ - 1) < 5000 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "ftnum", i__2, "pckbsr_", (
		    ftnlen)921)] = __state->ftnum[(i__3 = i__) < 5000 && 0 <= 
		    i__3 ? i__3 : s_rnge(&__global_state->f2c, "ftnum", i__3, 
		    "pckbsr_", (ftnlen)921)];
	}
	i__ = 1;
	while(i__ <= __state->nbt) {
	    p = __state->btbeg[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btbeg", i__1, "pckbsr_", (
		    ftnlen)928)];
	    while(p > 0) {

/*              Find the successor of P, if any. */

		nxtseg = lnknxt_(__global_state, &p, __state->stpool);
		if (__state->sthan[(i__1 = p - 1) < 5000 && 0 <= i__1 ? i__1 :
			 s_rnge(&__global_state->f2c, "sthan", i__1, "pckbsr_"
			, (ftnlen)936)] == *handle) {

/*                 The segment corresponding to node P came from */
/*                 the file we're unloading.  Delete the node for */
/*                 P from the segment list for body I; if P happens */
/*                 to be the head node for body I's segment list, */
/*                 make the successor of P the head of the list. */

		    lnkfsl_(__global_state, &p, &p, __state->stpool);
		    if (p == __state->btbeg[(i__1 = i__ - 1) < 20 && 0 <= 
			    i__1 ? i__1 : s_rnge(&__global_state->f2c, "btbeg"
			    , i__1, "pckbsr_", (ftnlen)946)]) {
			__state->btbeg[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? 
				i__1 : s_rnge(&__global_state->f2c, "btbeg", 
				i__1, "pckbsr_", (ftnlen)947)] = nxtseg;
		    }
		}

/*              Update P. */

		p = nxtseg;
	    }

/*           If the list for this body is now empty, shorten the current */
/*           table by one: put all the entries for the last body in the */
/*           table into the space occupied by the one we've deleted. */

	    if (__state->btbeg[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btbeg", i__1, "pckbsr_", (
		    ftnlen)963)] <= 0) {

/*              Because all of the re-use intervals are invalid, we need */
/*              not copy the saved items associated with them.  The */
/*              items not copied are */

/*                 BTCHKP */
/*                 BTLB */
/*                 BTPRVD */
/*                 BTPRVH */
/*                 BTPRVI */
/*                 BTRUEX */
/*                 BTUB */

		__state->btbod[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "btbod", i__1, "pckbsr_",
			 (ftnlen)977)] = __state->btbod[(i__2 = __state->nbt 
			- 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "btbod", i__2, "pckbsr_", (
			ftnlen)977)];
		__state->btexp[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "btexp", i__1, "pckbsr_",
			 (ftnlen)978)] = __state->btexp[(i__2 = __state->nbt 
			- 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "btexp", i__2, "pckbsr_", (
			ftnlen)978)];
		__state->bthfs[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "bthfs", i__1, "pckbsr_",
			 (ftnlen)979)] = __state->bthfs[(i__2 = __state->nbt 
			- 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "bthfs", i__2, "pckbsr_", (
			ftnlen)979)];
		__state->btlfs[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "btlfs", i__1, "pckbsr_",
			 (ftnlen)980)] = __state->btlfs[(i__2 = __state->nbt 
			- 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "btlfs", i__2, "pckbsr_", (
			ftnlen)980)];
		__state->btbeg[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "btbeg", i__1, "pckbsr_",
			 (ftnlen)981)] = __state->btbeg[(i__2 = __state->nbt 
			- 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "btbeg", i__2, "pckbsr_", (
			ftnlen)981)];
		--__state->nbt;
	    } else {
		++i__;
	    }
	}
    } else {

/*        This is a new file.  Make sure that there are unused slots */
/*        in the file table. */

	if (__state->nft == 5000) {

/*           This error case can occur only if FTSIZE is larger than */
/*           the maximum number of open DAF files.  Currently FTSIZE */
/*           is equal to this limit. */

	    dafcls_(__global_state, handle);
	    setmsg_(__global_state, "The internal file table is already full"
		    ", with # entries.", (ftnlen)56);
	    errint_(__global_state, "#", &__state->c__5000, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(PCKFILETABLEFULL)", (ftnlen)23);
	    chkout_(__global_state, "PCKLOF", (ftnlen)6);
	    return 0;
	}
    }

/*     Determine the next file number.  Note that later code assumes */
/*     that the file number can be incremented by 1, so we can't allow */
/*     the file number to reach INTMAX(). */

    if (__state->next < intmax_(__global_state) - 1) {
	++__state->next;
    } else {

/*        The user is to be congratulated:  we've run out of file */
/*        numbers. */

/*        Re-set the valid file numbers so they lie in the range 1:NFT, */
/*        with the Ith file in the file table having file number I. */
/*        First update the LFS and HFS components of the body table */
/*        according to this mapping. */

/*        Set any body table entries that are lower than FTNUM(1) to */
/*        zero. */

	i__1 = __state->nbt;
	for (i__ = 1; i__ <= i__1; ++i__) {

/*           Re-map the HFS table for the Ith body. */

	    j = isrchi_(__global_state, &__state->bthfs[(i__2 = i__ - 1) < 20 
		    && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "bthfs"
		    , i__2, "pckbsr_", (ftnlen)1043)], &__state->nft, 
		    __state->ftnum);
	    if (j > 0) {

/*              The highest file searched for body I is the Jth file */
/*              in the file table. */

		__state->bthfs[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : 
			s_rnge(&__global_state->f2c, "bthfs", i__2, "pckbsr_",
			 (ftnlen)1050)] = j;
	    } else {

/*              The highest file searched for body I is not in the file */
/*              table.  This occurs when the highest file searched has */
/*              been unloaded.  Note that this assignment makes all files */
/*              appear to be "new" when a lookup for body I is performed. */

		__state->bthfs[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : 
			s_rnge(&__global_state->f2c, "bthfs", i__2, "pckbsr_",
			 (ftnlen)1059)] = 0;
	    }

/*           Re-map the LFS table for the Ith body. */

	    j = isrchi_(__global_state, &__state->btlfs[(i__2 = i__ - 1) < 20 
		    && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "btlfs"
		    , i__2, "pckbsr_", (ftnlen)1066)], &__state->nft, 
		    __state->ftnum);
	    if (j > 0) {

/*              The lowest file searched for body I is the Jth file */
/*              in the file table. */

		__state->btlfs[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : 
			s_rnge(&__global_state->f2c, "btlfs", i__2, "pckbsr_",
			 (ftnlen)1073)] = j;
	    } else {

/*              The lowest file searched for body I is not in the file */
/*              table.  This occurs when the lowest file searched has */
/*              been unloaded.  Force reconstruction of the list by */
/*              making all files "new." */

		__state->btlfs[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : 
			s_rnge(&__global_state->f2c, "btlfs", i__2, "pckbsr_",
			 (ftnlen)1082)] = 0;
		__state->bthfs[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : 
			s_rnge(&__global_state->f2c, "bthfs", i__2, "pckbsr_",
			 (ftnlen)1083)] = 0;
	    }
	}

/*        Re-map the file number table itself. */

	i__1 = __state->nft;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    __state->ftnum[(i__2 = i__ - 1) < 5000 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "ftnum", i__2, "pckbsr_", (
		    ftnlen)1094)] = i__;
	}

/*        Assign a new file number. */

	__state->next = __state->nft + 1;
    }
    ++__state->nft;
    __state->fthan[(i__1 = __state->nft - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "fthan", i__1, "pckbsr_", (ftnlen)
	    1107)] = *handle;
    __state->ftnum[(i__1 = __state->nft - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftnum", i__1, "pckbsr_", (ftnlen)
	    1108)] = __state->next;
    chkout_(__global_state, "PCKLOF", (ftnlen)6);
    return 0;
/* $Procedure PCKUOF ( PCK, unload binary file ) */

L_pckuof:
/* $ Abstract */

/*     Unload a binary PCK file so that it will no longer be searched by */
/*     the readers. */

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

/*     PCK */

/* $ Keywords */

/*     PCK */
/*     FILES */

/* $ Declarations */

/*     INTEGER               HANDLE */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle of file to be unloaded */

/* $ Detailed_Input */

/*     HANDLE     Integer handle assigned to the file upon loading. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Unloading a file that has not been loaded is a no-op. */
/*        No error is signaled. */

/* $ Files */

/*     The file referred to by HANDLE is unloaded. */

/* $ Particulars */

/*     A file is removed from consideration by the readers by a call to */
/*     PCKUOF. */

/*     If the file specified by HANDLE is not currently loaded in the */
/*     PCK system, no action is taken. */

/* $ Examples */

/*     See the Example above, in PCKBSR. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     K.S. Zukor      (JPL) */
/*     J.M. Lynch      (JPL) */
/*     R.E. Thurman    (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 4.1.2, 30-JAN-2017 (NJB) */

/*        Corrected various spelling errors within comments. */

/* -    SPICELIB Version 4.1.1, 03-JAN-2014 (EDW) */

/*        Minor edits to Procedure; clean trailing whitespace. */
/*        Removed unneeded Revisions section. */

/* -    SPICELIB Version 4.1.0, 08-SEP-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in MOVED call. */

/* -    SPICELIB Version 1.1.0, 08-NOV-2001 (NJB) */

/*        Bug fixes: */

/*        1) This routine now calls RETURN() on entry and */
/*           returns if so directed. */

/*        Also, the flags indicating validity of those re-use intervals */
/*        whose data comes from the unloaded file are set to .FALSE. */

/* -    SPICELIB Version 1.0.0, 16-MAR-1994 (KSZ) */

/* -& */
/* $ Index_Entries */

/*     unload PCK file */

/* -& */
    if (return_(__global_state)) {
	return 0;
    }

/*     All of the stored segments from the file must be removed */
/*     from the segment table (by returning the corresponding nodes */
/*     to the segment table pool.) */

/*     Don't do anything if the given handle is not in the file table. */

    findex = isrchi_(__global_state, handle, &__state->nft, __state->fthan);
    if (findex == 0) {
	return 0;
    }

/*     First get rid of the entry in the file table. Close the file */
/*     before wiping out the handle. */

    dafcls_(__global_state, &__state->fthan[(i__1 = findex - 1) < 5000 && 0 <=
	     i__1 ? i__1 : s_rnge(&__global_state->f2c, "fthan", i__1, "pckb"
	    "sr_", (ftnlen)1274)]);
    --__state->nft;
    i__1 = __state->nft;
    for (i__ = findex; i__ <= i__1; ++i__) {
	__state->fthan[(i__2 = i__ - 1) < 5000 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "fthan", i__2, "pckbsr_", (ftnlen)1279)] 
		= __state->fthan[(i__3 = i__) < 5000 && 0 <= i__3 ? i__3 : 
		s_rnge(&__global_state->f2c, "fthan", i__3, "pckbsr_", (
		ftnlen)1279)];
	__state->ftnum[(i__2 = i__ - 1) < 5000 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "ftnum", i__2, "pckbsr_", (ftnlen)1280)] 
		= __state->ftnum[(i__3 = i__) < 5000 && 0 <= i__3 ? i__3 : 
		s_rnge(&__global_state->f2c, "ftnum", i__3, "pckbsr_", (
		ftnlen)1280)];
    }

/*     Check each body list individually. Note that the first node */
/*     on each list, having no predecessor, must be handled specially. */

    i__ = 1;
    while(i__ <= __state->nbt) {
	p = __state->btbeg[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge(
		&__global_state->f2c, "btbeg", i__1, "pckbsr_", (ftnlen)1291)]
		;
	while(p > 0) {
	    nxtseg = lnknxt_(__global_state, &p, __state->stpool);
	    if (__state->sthan[(i__1 = p - 1) < 5000 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "sthan", i__1, "pckbsr_", (
		    ftnlen)1297)] == *handle) {
		if (p == __state->btbeg[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? 
			i__1 : s_rnge(&__global_state->f2c, "btbeg", i__1, 
			"pckbsr_", (ftnlen)1299)]) {
		    __state->btbeg[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 :
			     s_rnge(&__global_state->f2c, "btbeg", i__1, 
			    "pckbsr_", (ftnlen)1300)] = nxtseg;
		}
		lnkfsl_(__global_state, &p, &p, __state->stpool);
	    }
	    p = nxtseg;
	}

/*        If we happened to get rid of all of the segments for this */
/*        body, then the body should be deleted from the table: shift */
/*        all entries for the body at the end of the table into the */
/*        space occupied by the deleted body. */

	if (__state->btbeg[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge(
		&__global_state->f2c, "btbeg", i__1, "pckbsr_", (ftnlen)1317)]
		 <= 0) {
	    if (i__ != __state->nbt) {
		__state->btbod[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "btbod", i__1, "pckbsr_",
			 (ftnlen)1321)] = __state->btbod[(i__2 = __state->nbt 
			- 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "btbod", i__2, "pckbsr_", (
			ftnlen)1321)];
		__state->btexp[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "btexp", i__1, "pckbsr_",
			 (ftnlen)1322)] = __state->btexp[(i__2 = __state->nbt 
			- 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "btexp", i__2, "pckbsr_", (
			ftnlen)1322)];
		__state->bthfs[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "bthfs", i__1, "pckbsr_",
			 (ftnlen)1323)] = __state->bthfs[(i__2 = __state->nbt 
			- 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "bthfs", i__2, "pckbsr_", (
			ftnlen)1323)];
		__state->btlfs[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "btlfs", i__1, "pckbsr_",
			 (ftnlen)1324)] = __state->btlfs[(i__2 = __state->nbt 
			- 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "btlfs", i__2, "pckbsr_", (
			ftnlen)1324)];
		__state->btbeg[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "btbeg", i__1, "pckbsr_",
			 (ftnlen)1325)] = __state->btbeg[(i__2 = __state->nbt 
			- 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "btbeg", i__2, "pckbsr_", (
			ftnlen)1325)];
		__state->btlb[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "btlb", i__1, "pckbsr_", 
			(ftnlen)1326)] = __state->btlb[(i__2 = __state->nbt - 
			1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "btlb", i__2, "pckbsr_", (ftnlen)
			1326)];
		__state->btub[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "btub", i__1, "pckbsr_", 
			(ftnlen)1327)] = __state->btub[(i__2 = __state->nbt - 
			1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "btub", i__2, "pckbsr_", (ftnlen)
			1327)];
		__state->btprvh[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "btprvh", i__1, "pckbsr_"
			, (ftnlen)1328)] = __state->btprvh[(i__2 = 
			__state->nbt - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "btprvh", i__2, "pckbsr_", (
			ftnlen)1328)];
		s_copy(&__global_state->f2c, __state->btprvi + ((i__1 = i__ - 
			1) < 20 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "btprvi", i__1, "pckbsr_", (
			ftnlen)1329)) * 40, __state->btprvi + ((i__2 = 
			__state->nbt - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "btprvi", i__2, "pckbsr_", (
			ftnlen)1329)) * 40, (ftnlen)40, (ftnlen)40);
		__state->btchkp[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "btchkp", i__1, "pckbsr_"
			, (ftnlen)1330)] = __state->btchkp[(i__2 = 
			__state->nbt - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "btchkp", i__2, "pckbsr_", (
			ftnlen)1330)];
		__state->btruex[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "btruex", i__1, "pckbsr_"
			, (ftnlen)1331)] = __state->btruex[(i__2 = 
			__state->nbt - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "btruex", i__2, "pckbsr_", (
			ftnlen)1331)];
		moved_(__global_state, &__state->btprvd[(i__1 = __state->nbt *
			 5 - 5) < 100 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "btprvd", i__1, "pckbsr_", (
			ftnlen)1333)], &__state->c__5, &__state->btprvd[(i__2 
			= i__ * 5 - 5) < 100 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "btprvd", i__2, "pckbsr_", (
			ftnlen)1333)]);
	    }
	    --__state->nbt;
	} else {
	    ++i__;
	}
    }

/*     Any time we unload a file, we may be removing the file */
/*     providing data for the re-use interval for one or more bodies. */
/*     For each body, if the handle associated with the re-use interval */
/*     happens to be that of the file we're unloading, indicate */
/*     that the re-use interval is invalid. */

    i__1 = __state->nbt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (__state->btchkp[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : 
		s_rnge(&__global_state->f2c, "btchkp", i__2, "pckbsr_", (
		ftnlen)1356)]) {
	    if (__state->btprvh[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "btprvh", i__2, "pckbsr_", (
		    ftnlen)1358)] == *handle) {
		__state->btchkp[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : 
			s_rnge(&__global_state->f2c, "btchkp", i__2, "pckbsr_"
			, (ftnlen)1359)] = FALSE_;
	    }
	}
    }
    return 0;
/* $Procedure PCKSFS ( PCK, select file and segment ) */

L_pcksfs:
/* $ Abstract */

/*     Search through loaded files to find the first segment applicable */
/*     to the body and time specified.  Buffer searched segments in the */
/*     process, to attempt to avoid re-reading files. */

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

/*     PCK */

/* $ Keywords */

/*     PCK */
/*     FILES */

/* $ Declarations */

/*     INTEGER               BODY */
/*     DOUBLE PRECISION      ET */
/*     INTEGER               HANDLE */
/*     DOUBLE PRECISION      DESCR  ( * ) */
/*     CHARACTER*(*)         IDENT */
/*     LOGICAL               FOUND */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     BODY       I   Body ID. */
/*     ET         I   Ephemeris time. */
/*     HANDLE     O   Handle of file containing the applicable segment. */
/*     DESCR      O   Descriptor of the applicable segment. */
/*     IDENT      O   Identifier of the applicable segment. */
/*     FOUND      O   Indicates whether or not a segment was found. */

/* $ Detailed_Input */

/*     BODY       is the NAIF integer code of an ephemeris object, */
/*                typically a solar system body. */

/*     ET         is a time, in seconds past the epoch J2000 TDB. */

/* $ Detailed_Output */

/*     HANDLE     on output is the handle of the binary PCK file */
/*                containing a located segment. */

/*     DESCR      is the descriptor of a located segment. */

/*     IDENT      is the identifier of a located segment. */

/*     FOUND      indicates whether a requested segment was found or not. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If an attempt is made to call PCKSFS when there aren't any */
/*        files loaded, the error SPICE(NOLOADEDFILES) is signaled. */

/* $ Files */

/*     All files loaded by PCKLOF are potential search targets for */
/*     PCKSFS. */

/* $ Particulars */

/*     This routine finds the highest-priority segment, in any loaded */
/*     PCK file, such that the segment provides data for the specified */
/*     body and epoch. */

/* $ Examples */

/*     See the Example above, in PCKBSR. */

/* $ Restrictions */

/*     1) If Fortran I/O errors occur while searching a loaded PCK */
/*        file, the internal state of this suite of routines may */
/*        be corrupted.  It may be possible to correct the state */
/*        by unloading the pertinent PCK files and then re-loading */
/*        them. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     K.S. Zukor      (JPL) */
/*     R.E. Thurman    (JPL) */

/* $ Version */

/* -    SPICELIB Version 4.2.2, 30-JAN-2017 (NJB) */

/*        Corrected various spelling errors within comments. */

/* -    SPICELIB Version 4.2.1, 03-JAN-2014 (EDW) */

/*        Minor edits to Procedure; clean trailing whitespace. */
/*        Removed unneeded Revisions section. */

/* -    SPICELIB Version 4.2.0, 01-MAR-2011 (NJB) */

/*        Bug fix: */

/*          In the PCKSFS 'MAKE ROOM' state, when the suspended activity */
/*          is 'ADD TO FRONT' and no segment table room is available, */
/*          the body table's pointer to the current segment list */
/*          is now set to null. Previously the pointer was allowed to go */
/*          stale. */

/* -    SPICELIB Version 4.1.0, 08-SEP-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in MOVED call. */

/* -    SPICELIB Version 1.1.0, 08-NOV-2001 (NJB) */

/*        Bug fixes: */

/*           1) When a segment list is freed because the entire list */
/*              is contributed by a single PCK file, and the list is */
/*              too large to be buffered, the corresponding body table */
/*              pointer is now set to null. */

/*           2) An algorithm change has eliminated a bug caused by not */
/*              updating the current body index when body table entries */
/*              having empty segment lists were compressed out of the */
/*              body table.  Previously the body table pointer BINDEX */
/*              could go stale after the compression. */

/*           3) DAF calls are now followed by tests of FAILED() */
/*              in order to ensure that the main state loop terminates. */

/*           4) A subscript bound violation in a loop termination test */
/*              was corrected.  The loop is located in the */
/*              'SEARCH W/O BUFFERING' block; it finds the start of a */
/*              partial list that is to be freed. */

/*        The "re-use interval" feature was introduced to improve speed */
/*        in the case where repeated, consecutive requests are satisfied */
/*        by the same segment. */

/*        The segment list cost algorithm was modified slightly: */
/*        the contribution of a file search to the cost of a list */
/*        is included only when the file search is completed.  The */
/*        cost of finding the re-use interval is accounted for when */
/*        unbuffered searches are required. */

/*        The file table size has been increased to 1000, in order */
/*        to take advantage of the DAF system's new ability to load */
/*        1000 files. */

/*        The body table size has been increased to 200 in order to */
/*        decrease the chance of thrashing due to swapping segment */
/*        lists for different bodies. */

/*        Various small updates and corrections were made to the */
/*        comments throughout the file. */

/*        In order to simplify the source code, the in-line singly */
/*        linked list implementation of the segment table has been */
/*        replaced by an implementation relying on the SPICELIB */
/*        doubly linked list routines. */

/* -    SPICELIB Version 1.0.0, 16-MAR-1994 (KSZ) */

/*        This differs only slightly from the SPKXXX code. */
/*        The main difference is that the SFS subroutine returns */
/*        FOUND = FALSE if no files are found, rather than returning */
/*        an error. */

/* -& */
/* $ Index_Entries */

/*     select PCK file and segment */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "PCKSFS", (ftnlen)6);
    }

/*     Assume the segment is not found, until it actually is. */

    *found = FALSE_;

/*     Buffering segments involves maintaining three tables:  the */
/*     file table, the body table, and the segment table.  The routine */
/*     is broken down into various tasks, described below, which */
/*     perform these manipulations.  A description of the components */
/*     of each table is provided in the declarations section of PCKBSR. */

/*     Return FOUND as .FALSE. if no files are loaded.  Unlike the SPK */
/*     case, it's not an error to call this routine if no files are */
/*     loaded. */

    if (__state->nft == 0) {
	chkout_(__global_state, "PCKSFS", (ftnlen)6);
	return 0;
    }

/*     The stack of suspended tasks is empty. */

    top = 0;

/*     In the following loop, we will try to simplify things by */
/*     doing exactly one thing on each pass through the loop. */
/*     After each pass, the status of the loop (STATUS) will be */
/*     adjusted to reflect the next thing that needs to be done. */
/*     Occasionally, the current task will have to be interrupted */
/*     until another task can be carried out. (For example, when */
/*     collecting new segments, an interrupt might place a segment */
/*     at the front or end of the current body list; when placing */
/*     the segment on the list, a second interrupt might free up */
/*     room in the segment table in order to allow the addition */
/*     to proceed.) In this case, the current task will be saved and */
/*     restored after the more urgent task has been completed. */

/*     The loop can terminate in only one of two ways (unless an */
/*     error occurs). First, if an applicable segment is found in */
/*     the segment table, the  handle, descriptor, and identifier for */
/*     the segment are returned immediately.  Second, if the table */
/*     does not contain an applicable segment, and if no files remain */
/*     to be searched, the loop terminates normally, and no data are */
/*     returned. */

/*     The individual tasks are described below. */

/*     'NEW BODY' */


/*        This indicates that the specified body has no segments stored */
/*        for it at all. It must be added to the body table.  (This is */
/*        followed immediately by an OLD FILES search, in which every */
/*        file loaded is considered an old file.) */

/*     'NEW FILES' */

/*        This indicates that at least one new file has been added */
/*        since the last time the segment list for the specified */
/*        body was searched. Find the oldest of these new files, */
/*        and begin a NEW SEGMENTS search in forward order for */
/*        segments to add to the front of the list. */

/*     'NEW SEGMENTS' */

/*        Continue a NEW FILES search, adding segments for the specified */
/*        body to the front of the list. */

/*     'OLD FILES' */

/*        This indicates that although the list has been searched */
/*        and found to contain no applicable segment, some of the */
/*        older files remain to be searched. Find the newest of these */
/*        old files, and begin an OLD SEGMENTS search in backward order. */

/*     'OLD SEGMENTS' */

/*        Continue an OLD FILES search, adding segments for the specified */
/*        body to the end of the list. */

/*     'CHECK LIST' */

/*        This indicates that the list is ready to be searched, */
/*        either because no new files have been added, or because */
/*        segments from a new file or an old file have recently */
/*        been added. */

/*        The list is never checked until all new files have been */
/*        searched. */

/*        If an applicable segment is found, it is returned. */

/*     'MAKE ROOM' (Interrupt) */

/*        This indicates that one of the bodies must be removed, */
/*        along with its stored segments, to make room for another */
/*        body or segment.  The body (other than the one being searched */
/*        for) with the smallest expense is selected for this honor. */

/*     'ADD TO FRONT' (Interrupt) */

/*        This indicates that a segment has been found (during the */
/*        course of a NEW FILES search) and must be added to the front */
/*        of the list. */

/*     'ADD TO END' (Interrupt) */

/*        This indicates that a segment has been found (during the */
/*        course of an OLD FILES search) and must be added to the end */
/*        of the list. */

/*     'SUSPEND' */

/*        This indicates that the current task (DOING) should be */
/*        interrupted until a more urgent task (URGENT) can be */
/*        carried out. The current task is placed on a stack for */
/*        safekeeping. */

/*     'RESUME' */

/*        This indicates that the most recently interrupted task */
/*        should be resumed immediately. */

/*     '?' */

/*        This indicates that the next task is not immediately */
/*        apparent: if new files exist, they should be searched; */
/*        otherwise the list should be checked. */


/*     Is the body already in the body table?  This determines what the */
/*     first task should be. */

    bindex = isrchi_(__global_state, body, &__state->nbt, __state->btbod);
    if (bindex == 0) {
	s_copy(&__global_state->f2c, status, "NEW BODY", (ftnlen)15, (ftnlen)
		8);
    } else {

/*        Much of the time, the segment used to satisfy the previous */
/*        request for a given body will also satisfy the current request */
/*        for data for that body.  Check whether this is the case. */

	if (__state->btchkp[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "btchkp", i__1, "pckbsr_", (
		ftnlen)1744)]) {

/*           The previous segment found for the current body is a */
/*           viable candidate for the current request.  See whether */
/*           the input ET value falls into the re-use interval for this */
/*           body:  the time interval for which the previously returned */
/*           segment for this body provides the highest-priority */
/*           coverage. */

/*           We treat the re-use interval as topologically open because */
/*           one or both endpoints may belong to higher-priority */
/*           segments. */

	    if (*et > __state->btlb[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "btlb", i__1, "pckbs"
		    "r_", (ftnlen)1757)] && *et < __state->btub[(i__2 = bindex 
		    - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "btub", i__2, "pckbsr_", (ftnlen)
		    1757)]) {

/*              The request time is covered by the segment found on */
/*              the previous request for data for the current body, */
/*              and this interval is not masked by any higher-priority */
/*              segments.  The previous segment for this body satisfies */
/*              the request. */

		*handle = __state->btprvh[(i__1 = bindex - 1) < 20 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "btprvh", 
			i__1, "pckbsr_", (ftnlen)1766)];
		s_copy(&__global_state->f2c, ident, __state->btprvi + ((i__1 =
			 bindex - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "btprvi", i__1, "pckbsr_", (
			ftnlen)1767)) * 40, ident_len, (ftnlen)40);
		moved_(__global_state, &__state->btprvd[(i__1 = bindex * 5 - 
			5) < 100 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "btprvd", i__1, "pckbsr_", (
			ftnlen)1769)], &__state->c__5, descr);
		*found = TRUE_;
		chkout_(__global_state, "PCKSFS", (ftnlen)6);
		return 0;
	    }

/*           Adjust the expense here. If the expense of the list */
/*           contains a component due to the cost of finding the */
/*           unbuffered segment providing data for re-use, subtract */
/*           that component from the expense. */

	    __state->btexp[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btexp", i__1, "pckbsr_", (
		    ftnlen)1784)] = __state->btexp[(i__2 = bindex - 1) < 20 &&
		     0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "btexp", 
		    i__2, "pckbsr_", (ftnlen)1784)] - __state->btruex[(i__3 = 
		    bindex - 1) < 20 && 0 <= i__3 ? i__3 : s_rnge(&
		    __global_state->f2c, "btruex", i__3, "pckbsr_", (ftnlen)
		    1784)];
	    __state->btruex[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btruex", i__1, "pckbsr_", (
		    ftnlen)1785)] = 0;

/*           The re-use interval becomes invalid if it didn't satisfy */
/*           the request.  The validity flag gets re-set below. */

/*           At this point, the previous segment is not a candidate */
/*           to satisfy the request---at least not until we've verified */
/*           that */

/*              - The previous segment is still available. */

/*              - The previous segment hasn't been superseded by a more */
/*                recently loaded segment. */

	    __state->btchkp[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btchkp", i__1, "pckbsr_", (
		    ftnlen)1800)] = FALSE_;
	}

/*        If the segment list for this body is empty, make sure the */
/*        expense is reset to 0. */

	if (__state->btbeg[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "btbeg", i__1, "pckbsr_", (
		ftnlen)1809)] == 0) {
	    __state->btexp[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btexp", i__1, "pckbsr_", (
		    ftnlen)1811)] = 0;
	}
	s_copy(&__global_state->f2c, status, "?", (ftnlen)15, (ftnlen)1);
    }
    while(s_cmp(&__global_state->f2c, status, "HOPELESS", (ftnlen)15, (ftnlen)
	    8) != 0) {

/*        If new files have been added, they have to be searched. */
/*        Otherwise, we can go right to the list of stored segments. */

	if (s_cmp(&__global_state->f2c, status, "?", (ftnlen)15, (ftnlen)1) ==
		 0) {

/*           There are two ways to get to this point. */

/*           1)  Status may have been set to '?' prior to the */
/*               loop DO WHILE ( STATUS .NE. HOPELESS ). */

/*           2)  Status was set to '?' by the NEW SEGMENTS block */
/*               of code as the result of finishing the read of */
/*               a new file. */

	    if (__state->bthfs[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "bthfs", i__1, "pckbsr_", (
		    ftnlen)1838)] < __state->ftnum[(i__2 = __state->nft - 1) <
		     5000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "ftnum", i__2, "pckbsr_", (ftnlen)1838)]) {
		s_copy(&__global_state->f2c, status, "NEW FILES", (ftnlen)15, 
			(ftnlen)9);
	    } else {
		s_copy(&__global_state->f2c, status, "CHECK LIST", (ftnlen)15,
			 (ftnlen)10);
	    }
	} else if (s_cmp(&__global_state->f2c, status, "NEW BODY", (ftnlen)15,
		 (ftnlen)8) == 0) {

/*           New bodies are added to the end of the body table. If the */
/*           table is full, one of the current occupants must be */
/*           removed to make room for the new one. */

/*           Setting LFS to one more than the highest current */
/*           file number means the OLD FILES SEARCH that follows will */
/*           begin with the last-loaded file. */

/*           There is one way to get here: */

/*           1)  The variable STATUS was set to NEW BODY prior to the */
/*               loop DO WHILE ( STATUS .NE. HOPELESS ). */

/*           Find the cheapest slot in the body table to store */
/*           the initial information about this body. */

/*           NOTE:  This used to be handled by the MAKE ROOM section. */
/*           However, trying to handle this special case there was */
/*           just more trouble than it was worth. */

	    if (__state->nbt < 20) {

/*              If the body table isn't full, the cheapest place is */
/*              just the next unused row of the table. */

		++__state->nbt;
		cheap = __state->nbt;
	    } else {

/*              The body table is full.  Find the least */
/*              expensive body in the table and remove it. */

		cheap = 1;
		minexp = __state->btexp[0];
		i__1 = __state->nbt;
		for (i__ = 2; i__ <= i__1; ++i__) {
		    if (__state->btexp[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? 
			    i__2 : s_rnge(&__global_state->f2c, "btexp", i__2,
			     "pckbsr_", (ftnlen)1887)] < minexp) {
			cheap = i__;
			minexp = __state->btexp[(i__2 = i__ - 1) < 20 && 0 <= 
				i__2 ? i__2 : s_rnge(&__global_state->f2c, 
				"btexp", i__2, "pckbsr_", (ftnlen)1889)];
		    }
		}

/*              If there are any segments associated with the */
/*              least expensive body, we put them back on the free */
/*              list. */

		head = __state->btbeg[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? 
			i__1 : s_rnge(&__global_state->f2c, "btbeg", i__1, 
			"pckbsr_", (ftnlen)1899)];
		if (head > 0) {
		    tail = -lnkprv_(__global_state, &head, __state->stpool);
		    lnkfsl_(__global_state, &head, &tail, __state->stpool);
		}
	    }

/*           Set up a body table entry for the new body. */

	    __state->btbod[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btbod", i__1, "pckbsr_", (
		    ftnlen)1913)] = *body;
	    __state->btexp[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btexp", i__1, "pckbsr_", (
		    ftnlen)1914)] = 0;
	    __state->bthfs[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "bthfs", i__1, "pckbsr_", (
		    ftnlen)1915)] = __state->ftnum[(i__2 = __state->nft - 1) <
		     5000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "ftnum", i__2, "pckbsr_", (ftnlen)1915)];
	    __state->btlfs[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btlfs", i__1, "pckbsr_", (
		    ftnlen)1916)] = __state->ftnum[(i__2 = __state->nft - 1) <
		     5000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "ftnum", i__2, "pckbsr_", (ftnlen)1916)] + 1;
	    __state->btbeg[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btbeg", i__1, "pckbsr_", (
		    ftnlen)1917)] = 0;
	    __state->btchkp[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btchkp", i__1, "pckbsr_", (
		    ftnlen)1918)] = FALSE_;

/*           The following items associated with the re-use interval */
/*           need not be initialized at this point: */

/*              BTRUEX */
/*              BTLB */
/*              BTUB */
/*              BTPRVH */
/*              BTPRVI */
/*              BTPRVD */

/*           However, we'll give these items initial values to */
/*           help prevent compilation warnings from zealous */
/*           compilers. */

	    __state->btruex[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btruex", i__1, "pckbsr_", (
		    ftnlen)1935)] = 0;
	    __state->btlb[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btlb", i__1, "pckbsr_", (
		    ftnlen)1936)] = dpmin_(__global_state);
	    __state->btub[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btub", i__1, "pckbsr_", (
		    ftnlen)1937)] = dpmax_(__global_state);
	    __state->btprvh[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btprvh", i__1, "pckbsr_", (
		    ftnlen)1938)] = 0;
	    s_copy(&__global_state->f2c, __state->btprvi + ((i__1 = cheap - 1)
		     < 20 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "btprvi", i__1, "pckbsr_", (ftnlen)1939)) * 40, " ", (
		    ftnlen)40, (ftnlen)1);
	    cleard_(__global_state, &__state->c__5, &__state->btprvd[(i__1 = 
		    cheap * 5 - 5) < 100 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "btprvd", i__1, "pckbsr_", (ftnlen)
		    1940)]);

/*           BINDEX is the body table index of the new entry. */

	    bindex = cheap;

/*           Now search the loaded PCK files for segments relating to */
/*           this body.  We start with the last-loaded files and */
/*           work backwards. */

	    s_copy(&__global_state->f2c, status, "OLD FILES", (ftnlen)15, (
		    ftnlen)9);
	} else if (s_cmp(&__global_state->f2c, status, "NEW FILES", (ftnlen)
		15, (ftnlen)9) == 0) {

/*           When new files exist, they should be searched in forward */
/*           order, beginning with the oldest new file not yet searched. */
/*           All new files must be searched before the list can be */
/*           checked, to ensure that the best (newest) segments are */
/*           being used. */

/*           Begin a forward search, and prepare to look for individual */
/*           segments from the file. */

/*           The only way to get here is to have STATUS set to */
/*           the value NEW FILES in the STATUS .EQ. '?' block */
/*           of the IF structure. */

/*           Find the next file to search; set FINDEX to the */
/*           corresponding file table entry. */

	    findex = 1;
	    while(__state->bthfs[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 
		    : s_rnge(&__global_state->f2c, "bthfs", i__1, "pckbsr_", (
		    ftnlen)1976)] >= __state->ftnum[(i__2 = findex - 1) < 
		    5000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "ftnum", i__2, "pckbsr_", (ftnlen)1976)]) {
		++findex;
	    }
	    __state->bthfs[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "bthfs", i__1, "pckbsr_", (
		    ftnlen)1980)] = __state->ftnum[(i__2 = findex - 1) < 5000 
		    && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftnum"
		    , i__2, "pckbsr_", (ftnlen)1980)];
	    dafbfs_(__global_state, &__state->fthan[(i__1 = findex - 1) < 
		    5000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "fthan", i__1, "pckbsr_", (ftnlen)1982)]);
	    if (failed_(__global_state)) {
		chkout_(__global_state, "PCKSFS", (ftnlen)6);
		return 0;
	    }
	    s_copy(&__global_state->f2c, status, "NEW SEGMENTS", (ftnlen)15, (
		    ftnlen)12);

/*           The cost of the list contributed by the new file is */
/*           zero so far. */

	    cost = 0;
	} else if (s_cmp(&__global_state->f2c, status, "NEW SEGMENTS", (
		ftnlen)15, (ftnlen)12) == 0) {

/*           New files are searched in forward order. Segments, when */
/*           found, are inserted at the front of the list. Invisible */
/*           segments (alpha > omega) are ignored. */

/*           Each segment examined, whether applicable or not, adds to */
/*           the expense of the list. */

/*           The only way to get here is from the NEW FILES block */
/*           of the IF structure. */
	    daffna_(__global_state, &fnd);
	    if (failed_(__global_state)) {
		chkout_(__global_state, "PCKSFS", (ftnlen)6);
		return 0;
	    }
	    if (! fnd) {

/*              We're out of segments in the current file.  Decide */
/*              whether we need to examine another new file, or */
/*              whether we're ready to check the list. */

		s_copy(&__global_state->f2c, status, "?", (ftnlen)15, (ftnlen)
			1);
		__state->btexp[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "btexp", i__1, "pckbsr_",
			 (ftnlen)2024)] = __state->btexp[(i__2 = bindex - 1) <
			 20 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c,
			 "btexp", i__2, "pckbsr_", (ftnlen)2024)] + cost;
	    } else {
		dafgs_(__global_state, descr);
		dafus_(__global_state, descr, &__state->c__2, &__state->c__5, 
			dcd, icd);
		if (failed_(__global_state)) {
		    chkout_(__global_state, "PCKSFS", (ftnlen)6);
		    return 0;
		}
		if (icd[0] == *body && dcd[0] <= dcd[1]) {
		    s_copy(&__global_state->f2c, doing, "NEW SEGMENTS", (
			    ftnlen)15, (ftnlen)12);
		    s_copy(&__global_state->f2c, urgent, "ADD TO FRONT", (
			    ftnlen)15, (ftnlen)12);
		    s_copy(&__global_state->f2c, status, "SUSPEND", (ftnlen)
			    15, (ftnlen)7);
		}
		++cost;
	    }

/*           If we haven't reset the status, we'll return for another */
/*           'NEW SEGMENTS' pass. */

	} else if (s_cmp(&__global_state->f2c, status, "OLD FILES", (ftnlen)
		15, (ftnlen)9) == 0) {

/*           When old files must be searched (because the segments */
/*           in the list are inadequate), they should be searched */
/*           in backward order, beginning with the newest old file */
/*           not yet searched. The segment list will be re-checked */
/*           after each file is searched.  If a match is found, */
/*           the search terminates, so some old files may not be */
/*           searched. */

/*           Search from the end, and prepare to look for individual */
/*           segments from the file. */

/*           You can get to this block in two ways. */

/*           1) We can have a NEW BODY */

/*           2) We have checked the current list (CHECK LIST) for */
/*              this body, didn't find an applicable segment and */
/*              have some files left that have not been searched. */
	    findex = __state->nft;
	    while(__state->btlfs[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 
		    : s_rnge(&__global_state->f2c, "btlfs", i__1, "pckbsr_", (
		    ftnlen)2076)] <= __state->ftnum[(i__2 = findex - 1) < 
		    5000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "ftnum", i__2, "pckbsr_", (ftnlen)2076)]) {
		--findex;
	    }
	    dafbbs_(__global_state, &__state->fthan[(i__1 = findex - 1) < 
		    5000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "fthan", i__1, "pckbsr_", (ftnlen)2080)]);
	    if (failed_(__global_state)) {
		chkout_(__global_state, "PCKSFS", (ftnlen)6);
		return 0;
	    }
	    s_copy(&__global_state->f2c, status, "OLD SEGMENTS", (ftnlen)15, (
		    ftnlen)12);

/*           The next thing we'll do is search through all the segments */
/*           of this file for those that applicable to this body. */
/*           The cost of the list contributed by the current file is */
/*           zero so far. */

	    cost = 0;
	} else if (s_cmp(&__global_state->f2c, status, "OLD SEGMENTS", (
		ftnlen)15, (ftnlen)12) == 0) {

/*           Old files are searched in backward order. Segments, when */
/*           found, are inserted at the end of the list. Invisible */
/*           segments (alpha > omega) are ignored. */

/*           Each segment examined, whether applicable or not, adds to */
/*           the expense of the list. */

/*           There is only one way to get here---from the */
/*           block 'OLD FILES'.  Note we do not add to the */
/*           expense of the list for this body until we've */
/*           completely searched this file. */

	    daffpa_(__global_state, &fnd);
	    if (failed_(__global_state)) {
		chkout_(__global_state, "PCKSFS", (ftnlen)6);
		return 0;
	    }
	    if (! fnd) {

/*              We've been through all of the segments in this file. */
/*              Change the lowest file searched indicator for this body */
/*              to be the current file, and go check the current list. */

		__state->btlfs[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "btlfs", i__1, "pckbsr_",
			 (ftnlen)2125)] = __state->ftnum[(i__2 = findex - 1) <
			 5000 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "ftnum", i__2, "pckbsr_", (
			ftnlen)2125)];
		__state->btexp[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "btexp", i__1, "pckbsr_",
			 (ftnlen)2126)] = __state->btexp[(i__2 = bindex - 1) <
			 20 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c,
			 "btexp", i__2, "pckbsr_", (ftnlen)2126)] + cost;
		s_copy(&__global_state->f2c, status, "CHECK LIST", (ftnlen)15,
			 (ftnlen)10);
	    } else {
		dafgs_(__global_state, descr);
		dafus_(__global_state, descr, &__state->c__2, &__state->c__5, 
			dcd, icd);
		if (failed_(__global_state)) {
		    chkout_(__global_state, "PCKSFS", (ftnlen)6);
		    return 0;
		}
		if (icd[0] == *body && dcd[0] <= dcd[1]) {
		    s_copy(&__global_state->f2c, doing, "OLD SEGMENTS", (
			    ftnlen)15, (ftnlen)12);
		    s_copy(&__global_state->f2c, urgent, "ADD TO END", (
			    ftnlen)15, (ftnlen)10);
		    s_copy(&__global_state->f2c, status, "SUSPEND", (ftnlen)
			    15, (ftnlen)7);
		}
		++cost;
	    }

/*           If we haven't reset the status, we'll return for another */
/*           'OLD SEGMENTS' pass. */

	} else if (s_cmp(&__global_state->f2c, status, "CHECK LIST", (ftnlen)
		15, (ftnlen)10) == 0) {

/*           Okay, all the new files (and maybe an old file or two) have */
/*           been searched. Time to look at the list of segments stored */
/*           for the body to see if one applicable to the specified */
/*           epoch is hiding in there. If so, return it.  If not, */
/*           try another old file.  If there are no more old files, */
/*           give up the ghost. */

/*           There are two ways to get to this point. */

/*           1) From the '?' block. */
/*           2) From the 'OLD SEGMENTS' block. */

/*           For every segment examined, initialize the re-use interval */
/*           associated with the current body. */

	    __state->btlb[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btlb", i__1, "pckbsr_", (
		    ftnlen)2173)] = dpmin_(__global_state);
	    __state->btub[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btub", i__1, "pckbsr_", (
		    ftnlen)2174)] = dpmax_(__global_state);
	    p = __state->btbeg[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btbeg", i__1, "pckbsr_", (
		    ftnlen)2175)];
	    while(p > 0) {
		if (*et > __state->stdes[(i__1 = p * 5 - 4) < 25000 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "stdes", 
			i__1, "pckbsr_", (ftnlen)2179)]) {

/*                 ET is to the right of the coverage interval of this */
/*                 segment. */

/* Computing MAX */
		    d__1 = __state->btlb[(i__2 = bindex - 1) < 20 && 0 <= 
			    i__2 ? i__2 : s_rnge(&__global_state->f2c, "btlb",
			     i__2, "pckbsr_", (ftnlen)2184)], d__2 = 
			    __state->stdes[(i__3 = p * 5 - 4) < 25000 && 0 <= 
			    i__3 ? i__3 : s_rnge(&__global_state->f2c, "stdes"
			    , i__3, "pckbsr_", (ftnlen)2184)];
		    __state->btlb[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btlb", i__1, 
			    "pckbsr_", (ftnlen)2184)] = max(d__1,d__2);
		} else if (*et < __state->stdes[(i__1 = p * 5 - 5) < 25000 && 
			0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "std"
			"es", i__1, "pckbsr_", (ftnlen)2187)]) {

/*                 ET is to the left of the coverage interval of this */
/*                 segment. */

/* Computing MIN */
		    d__1 = __state->btub[(i__2 = bindex - 1) < 20 && 0 <= 
			    i__2 ? i__2 : s_rnge(&__global_state->f2c, "btub",
			     i__2, "pckbsr_", (ftnlen)2192)], d__2 = 
			    __state->stdes[(i__3 = p * 5 - 5) < 25000 && 0 <= 
			    i__3 ? i__3 : s_rnge(&__global_state->f2c, "stdes"
			    , i__3, "pckbsr_", (ftnlen)2192)];
		    __state->btub[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btub", i__1, 
			    "pckbsr_", (ftnlen)2192)] = min(d__1,d__2);
		} else {

/*                 The segment coverage interval includes ET. */

		    moved_(__global_state, &__state->stdes[(i__1 = p * 5 - 5) 
			    < 25000 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "stdes", i__1, "pckbsr_", (
			    ftnlen)2198)], &__state->c__5, descr);
		    s_copy(&__global_state->f2c, ident, __state->stidnt + ((
			    i__1 = p - 1) < 5000 && 0 <= i__1 ? i__1 : s_rnge(
			    &__global_state->f2c, "stidnt", i__1, "pckbsr_", (
			    ftnlen)2199)) * 40, ident_len, (ftnlen)40);
		    *handle = __state->sthan[(i__1 = p - 1) < 5000 && 0 <= 
			    i__1 ? i__1 : s_rnge(&__global_state->f2c, "sthan"
			    , i__1, "pckbsr_", (ftnlen)2200)];
		    *found = TRUE_;

/*                 Set the re-use interval for the current body. */

/* Computing MAX */
		    d__1 = __state->btlb[(i__2 = bindex - 1) < 20 && 0 <= 
			    i__2 ? i__2 : s_rnge(&__global_state->f2c, "btlb",
			     i__2, "pckbsr_", (ftnlen)2206)], d__2 = 
			    __state->stdes[(i__3 = p * 5 - 5) < 25000 && 0 <= 
			    i__3 ? i__3 : s_rnge(&__global_state->f2c, "stdes"
			    , i__3, "pckbsr_", (ftnlen)2206)];
		    __state->btlb[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btlb", i__1, 
			    "pckbsr_", (ftnlen)2206)] = max(d__1,d__2);
/* Computing MIN */
		    d__1 = __state->btub[(i__2 = bindex - 1) < 20 && 0 <= 
			    i__2 ? i__2 : s_rnge(&__global_state->f2c, "btub",
			     i__2, "pckbsr_", (ftnlen)2207)], d__2 = 
			    __state->stdes[(i__3 = p * 5 - 4) < 25000 && 0 <= 
			    i__3 ? i__3 : s_rnge(&__global_state->f2c, "stdes"
			    , i__3, "pckbsr_", (ftnlen)2207)];
		    __state->btub[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btub", i__1, 
			    "pckbsr_", (ftnlen)2207)] = min(d__1,d__2);

/*                 Save the returned output items, in case this segment */
/*                 may satisfy the next request. */

		    __state->btprvh[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btprvh", 
			    i__1, "pckbsr_", (ftnlen)2213)] = *handle;
		    s_copy(&__global_state->f2c, __state->btprvi + ((i__1 = 
			    bindex - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "btprvi", i__1, "pckbsr_", (
			    ftnlen)2214)) * 40, ident, (ftnlen)40, ident_len);
		    moved_(__global_state, descr, &__state->c__5, &
			    __state->btprvd[(i__1 = bindex * 5 - 5) < 100 && 
			    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			    "btprvd", i__1, "pckbsr_", (ftnlen)2215)]);
		    __state->btchkp[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btchkp", 
			    i__1, "pckbsr_", (ftnlen)2216)] = TRUE_;
		    chkout_(__global_state, "PCKSFS", (ftnlen)6);
		    return 0;
		}

/*              Get the next node.  We avoid LNKNXT here in order */
/*              to speed up the operation. */

		p = __state->stpool[(i__1 = (p << 1) + 10) < 10012 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "stpool", 
			i__1, "pckbsr_", (ftnlen)2227)];
	    }

/*           If we're still here we didn't have information for this */
/*           body in the segment list. */

/*           If there are more files, search them. */
/*           Otherwise, things are hopeless, set the status that way. */

	    if (__state->btlfs[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btlfs", i__1, "pckbsr_", (
		    ftnlen)2238)] > __state->ftnum[0]) {
		s_copy(&__global_state->f2c, status, "OLD FILES", (ftnlen)15, 
			(ftnlen)9);
	    } else {
		s_copy(&__global_state->f2c, status, "HOPELESS", (ftnlen)15, (
			ftnlen)8);
	    }
	} else if (s_cmp(&__global_state->f2c, status, "MAKE ROOM", (ftnlen)
		15, (ftnlen)9) == 0) {

/*           When adding a segment to a full segment table, one of */
/*           the current bodies must be dropped. The ideal candidate */
/*           is the one whose list was constructed at the lowest expense. */
/*           The candidate should be removed from the body table, and */
/*           its list transferred to the segment table pool. */

/*           There is ``room'' if the segment table pool contains at */
/*           least one free node. */

/*           It is possible that a single body requires more than the */
/*           entire segment table for its own segments. Two things might */
/*           happen in such a case: */

/*              1) If the list under consideration was being added to at */
/*                 the end, then a search is continued without buffering */
/*                 any segments. */

/*              2) If the list was being added to at the beginning, then */
/*                 that means there was a NEW FILES search going on, and */
/*                 so a brand new list is constructed for the body, much */
/*                 as in a 'NEW BODY' task. */

/*           There are two different ways to get to this point. */

/*              1) From 'ADD TO FRONT' if the segment table pool is full. */
/*              2) From 'ADD TO END' if the segment table pool is full. */

/*           Try to make room by deleting a segment list.  CHEAP will */
/*           be the index of the "cheapest" segment list in the body */
/*           table. */

	    minexp = intmax_(__global_state);
	    cheap = 0;
	    i__1 = __state->nbt;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		if (i__ != bindex) {

/*                 This list is for a body other than the current */
/*                 one. */

		    if (__state->btexp[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? 
			    i__2 : s_rnge(&__global_state->f2c, "btexp", i__2,
			     "pckbsr_", (ftnlen)2289)] < minexp || cheap == 0)
			     {

/*                    This list is the cheapest seen so far, */
/*                    possibly because it's the first one */
/*                    considered.  At the moment, it's as good */
/*                    a candidate for removal as any. */

			cheap = i__;
			minexp = __state->btexp[(i__2 = i__ - 1) < 20 && 0 <= 
				i__2 ? i__2 : s_rnge(&__global_state->f2c, 
				"btexp", i__2, "pckbsr_", (ftnlen)2298)];
		    }
		}
	    }
	    if (cheap == 0) {

/*              What we do if there are no delete-able segments */
/*              depends on the task that was suspended before entering */
/*              'MAKE ROOM'. */

		if (s_cmp(&__global_state->f2c, stack + ((i__1 = top - 1) < 2 
			&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			"stack", i__1, "pckbsr_", (ftnlen)2313)) * 15, "ADD "
			"TO END", (ftnlen)15, (ftnlen)10) == 0) {

/*                 There's nothing left to do but search the remaining */
/*                 files and segments without buffering them. */

		    s_copy(&__global_state->f2c, status, "SEARCH W/O BUFF", (
			    ftnlen)15, (ftnlen)15);
		} else {

/*                 STACK(TOP) is set to 'ADD TO FRONT'. */

/*                 If there is no room left in the table in the middle */
/*                 of an attempt to add to the front of the list, just */
/*                 start from scratch by treating all files as */
/*                 unsearched and doing an OLD FILES search, as would */
/*                 be done for a new body. */

/*                 Return the current list to the segment table pool. */

/*                 Note that, according to the specification of the */
/*                 SPICELIB doubly linked list routines, the backward */
/*                 pointer of a list head is the negative of the tail */
/*                 node. */

		    p = __state->btbeg[(i__1 = bindex - 1) < 20 && 0 <= i__1 ?
			     i__1 : s_rnge(&__global_state->f2c, "btbeg", 
			    i__1, "pckbsr_", (ftnlen)2338)];
		    tail = -lnkprv_(__global_state, &p, __state->stpool);
		    lnkfsl_(__global_state, &p, &tail, __state->stpool);

/*                 Re-initialize the table for this body, and initiate */
/*                 an 'OLD FILES' search, just as in 'NEW BODY'. */
/*                 Also, reset the suspended task stack to be empty. */

		    __state->btbeg[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btbeg", i__1,
			     "pckbsr_", (ftnlen)2348)] = 0;
		    __state->btexp[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btexp", i__1,
			     "pckbsr_", (ftnlen)2349)] = 0;
		    __state->bthfs[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "bthfs", i__1,
			     "pckbsr_", (ftnlen)2350)] = __state->ftnum[(i__2 
			    = __state->nft - 1) < 5000 && 0 <= i__2 ? i__2 : 
			    s_rnge(&__global_state->f2c, "ftnum", i__2, "pck"
			    "bsr_", (ftnlen)2350)];
		    __state->btlfs[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btlfs", i__1,
			     "pckbsr_", (ftnlen)2351)] = __state->ftnum[(i__2 
			    = __state->nft - 1) < 5000 && 0 <= i__2 ? i__2 : 
			    s_rnge(&__global_state->f2c, "ftnum", i__2, "pck"
			    "bsr_", (ftnlen)2351)] + 1;
		    s_copy(&__global_state->f2c, status, "OLD FILES", (ftnlen)
			    15, (ftnlen)9);
		    top = 0;
		}
	    } else {

/*              Return this cheapest list to the segment pool. */

		p = __state->btbeg[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? 
			i__1 : s_rnge(&__global_state->f2c, "btbeg", i__1, 
			"pckbsr_", (ftnlen)2361)];
		if (p > 0) {
		    tail = -lnkprv_(__global_state, &p, __state->stpool);
		    lnkfsl_(__global_state, &p, &tail, __state->stpool);
		}

/*              Fill the deleted body's space in the table with */
/*              the final entry in the table. */

		if (cheap != __state->nbt) {
		    __state->btbod[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btbod", i__1,
			     "pckbsr_", (ftnlen)2376)] = __state->btbod[(i__2 
			    = __state->nbt - 1) < 20 && 0 <= i__2 ? i__2 : 
			    s_rnge(&__global_state->f2c, "btbod", i__2, "pck"
			    "bsr_", (ftnlen)2376)];
		    __state->btexp[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btexp", i__1,
			     "pckbsr_", (ftnlen)2377)] = __state->btexp[(i__2 
			    = __state->nbt - 1) < 20 && 0 <= i__2 ? i__2 : 
			    s_rnge(&__global_state->f2c, "btexp", i__2, "pck"
			    "bsr_", (ftnlen)2377)];
		    __state->bthfs[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "bthfs", i__1,
			     "pckbsr_", (ftnlen)2378)] = __state->bthfs[(i__2 
			    = __state->nbt - 1) < 20 && 0 <= i__2 ? i__2 : 
			    s_rnge(&__global_state->f2c, "bthfs", i__2, "pck"
			    "bsr_", (ftnlen)2378)];
		    __state->btlfs[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btlfs", i__1,
			     "pckbsr_", (ftnlen)2379)] = __state->btlfs[(i__2 
			    = __state->nbt - 1) < 20 && 0 <= i__2 ? i__2 : 
			    s_rnge(&__global_state->f2c, "btlfs", i__2, "pck"
			    "bsr_", (ftnlen)2379)];
		    __state->btbeg[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btbeg", i__1,
			     "pckbsr_", (ftnlen)2380)] = __state->btbeg[(i__2 
			    = __state->nbt - 1) < 20 && 0 <= i__2 ? i__2 : 
			    s_rnge(&__global_state->f2c, "btbeg", i__2, "pck"
			    "bsr_", (ftnlen)2380)];
		    __state->btlb[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? i__1 
			    : s_rnge(&__global_state->f2c, "btlb", i__1, 
			    "pckbsr_", (ftnlen)2381)] = __state->btlb[(i__2 = 
			    __state->nbt - 1) < 20 && 0 <= i__2 ? i__2 : 
			    s_rnge(&__global_state->f2c, "btlb", i__2, "pckb"
			    "sr_", (ftnlen)2381)];
		    __state->btub[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? i__1 
			    : s_rnge(&__global_state->f2c, "btub", i__1, 
			    "pckbsr_", (ftnlen)2382)] = __state->btub[(i__2 = 
			    __state->nbt - 1) < 20 && 0 <= i__2 ? i__2 : 
			    s_rnge(&__global_state->f2c, "btub", i__2, "pckb"
			    "sr_", (ftnlen)2382)];
		    __state->btprvh[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btprvh", 
			    i__1, "pckbsr_", (ftnlen)2383)] = __state->btprvh[
			    (i__2 = __state->nbt - 1) < 20 && 0 <= i__2 ? 
			    i__2 : s_rnge(&__global_state->f2c, "btprvh", 
			    i__2, "pckbsr_", (ftnlen)2383)];
		    s_copy(&__global_state->f2c, __state->btprvi + ((i__1 = 
			    cheap - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "btprvi", i__1, "pckbsr_", (
			    ftnlen)2384)) * 40, __state->btprvi + ((i__2 = 
			    __state->nbt - 1) < 20 && 0 <= i__2 ? i__2 : 
			    s_rnge(&__global_state->f2c, "btprvi", i__2, 
			    "pckbsr_", (ftnlen)2384)) * 40, (ftnlen)40, (
			    ftnlen)40);
		    __state->btruex[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btruex", 
			    i__1, "pckbsr_", (ftnlen)2385)] = __state->btruex[
			    (i__2 = __state->nbt - 1) < 20 && 0 <= i__2 ? 
			    i__2 : s_rnge(&__global_state->f2c, "btruex", 
			    i__2, "pckbsr_", (ftnlen)2385)];
		    __state->btchkp[(i__1 = cheap - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btchkp", 
			    i__1, "pckbsr_", (ftnlen)2386)] = __state->btchkp[
			    (i__2 = __state->nbt - 1) < 20 && 0 <= i__2 ? 
			    i__2 : s_rnge(&__global_state->f2c, "btchkp", 
			    i__2, "pckbsr_", (ftnlen)2386)];
		    moved_(__global_state, &__state->btprvd[(i__1 = 
			    __state->nbt * 5 - 5) < 100 && 0 <= i__1 ? i__1 : 
			    s_rnge(&__global_state->f2c, "btprvd", i__1, 
			    "pckbsr_", (ftnlen)2389)], &__state->c__5, &
			    __state->btprvd[(i__2 = cheap * 5 - 5) < 100 && 0 
			    <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
			    "btprvd", i__2, "pckbsr_", (ftnlen)2389)]);
		}

/*              If the final entry in the table happened to be the */
/*              current body of interest, then we also have to change */
/*              the current body index. */

		if (bindex == __state->nbt) {
		    bindex = cheap;
		}

/*              One less body now. */

		--__state->nbt;
		s_copy(&__global_state->f2c, status, "RESUME", (ftnlen)15, (
			ftnlen)6);
	    }

/*           Either we made room by freeing a non-empty segment list, */
/*           or we're going to work without additional space.  In the */
/*           latter case, the state is now 'OLD FILES' or */
/*           'SEARCH W/O BUFF'. */

	} else if (s_cmp(&__global_state->f2c, status, "ADD TO FRONT", (
		ftnlen)15, (ftnlen)12) == 0) {

/*           The current segment information should be linked in at */
/*           the head of the segment list for the current body, and */
/*           the pertinent body table entry should point to the new */
/*           head of the list. */

/*           The only way to get here is from the block NEW SEGMENTS */
/*           after suspending that task. */

	    if (lnknfn_(__global_state, __state->stpool) == 0) {

/*              There's no room left in the segment pool.  We must make */
/*              room before continuing. */

		s_copy(&__global_state->f2c, doing, "ADD TO FRONT", (ftnlen)
			15, (ftnlen)12);
		s_copy(&__global_state->f2c, urgent, "MAKE ROOM", (ftnlen)15, 
			(ftnlen)9);
		s_copy(&__global_state->f2c, status, "SUSPEND", (ftnlen)15, (
			ftnlen)7);
	    } else {

/*              Allocate a node and link it to the front of the list */
/*              for the current body. */

		lnkan_(__global_state, __state->stpool, &new__);
		__state->sthan[(i__1 = new__ - 1) < 5000 && 0 <= i__1 ? i__1 :
			 s_rnge(&__global_state->f2c, "sthan", i__1, "pckbsr_"
			, (ftnlen)2443)] = __state->fthan[(i__2 = findex - 1) 
			< 5000 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "fthan", i__2, "pckbsr_", (
			ftnlen)2443)];
		moved_(__global_state, descr, &__state->c__5, &__state->stdes[
			(i__1 = new__ * 5 - 5) < 25000 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "stdes", i__1, "pckbsr_",
			 (ftnlen)2444)]);
		dafgn_(__global_state, __state->stidnt + ((i__1 = new__ - 1) <
			 5000 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "stidnt", i__1, "pckbsr_", (
			ftnlen)2445)) * 40, (ftnlen)40);
		if (failed_(__global_state)) {
		    chkout_(__global_state, "PCKSFS", (ftnlen)6);
		    return 0;
		}

/*              If the current list is empty, this append operation */
/*              is a no-op. */

		lnkilb_(__global_state, &new__, &__state->btbeg[(i__1 = 
			bindex - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "btbeg", i__1, "pckbsr_", (
			ftnlen)2456)], __state->stpool);
		__state->btbeg[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "btbeg", i__1, "pckbsr_",
			 (ftnlen)2457)] = new__;
		s_copy(&__global_state->f2c, status, "RESUME", (ftnlen)15, (
			ftnlen)6);
	    }
	} else if (s_cmp(&__global_state->f2c, status, "ADD TO END", (ftnlen)
		15, (ftnlen)10) == 0) {

/*           The current segment information should be linked in at */
/*           the tail of the segment list for the current body. */

/*           The only way to get to this task is from the OLD SEGMENTS */
/*           block after suspending that task. */

	    if (lnknfn_(__global_state, __state->stpool) == 0) {

/*              There's no room left in the segment pool.  We must make */
/*              room before continuing. */

		s_copy(&__global_state->f2c, doing, "ADD TO END", (ftnlen)15, 
			(ftnlen)10);
		s_copy(&__global_state->f2c, urgent, "MAKE ROOM", (ftnlen)15, 
			(ftnlen)9);
		s_copy(&__global_state->f2c, status, "SUSPEND", (ftnlen)15, (
			ftnlen)7);
	    } else {

/*              Allocate a new node in the segment table pool. */

		lnkan_(__global_state, __state->stpool, &new__);
		__state->sthan[(i__1 = new__ - 1) < 5000 && 0 <= i__1 ? i__1 :
			 s_rnge(&__global_state->f2c, "sthan", i__1, "pckbsr_"
			, (ftnlen)2488)] = __state->fthan[(i__2 = findex - 1) 
			< 5000 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "fthan", i__2, "pckbsr_", (
			ftnlen)2488)];
		moved_(__global_state, descr, &__state->c__5, &__state->stdes[
			(i__1 = new__ * 5 - 5) < 25000 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "stdes", i__1, "pckbsr_",
			 (ftnlen)2489)]);
		dafgn_(__global_state, __state->stidnt + ((i__1 = new__ - 1) <
			 5000 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "stidnt", i__1, "pckbsr_", (
			ftnlen)2490)) * 40, (ftnlen)40);
		if (failed_(__global_state)) {
		    chkout_(__global_state, "PCKSFS", (ftnlen)6);
		    return 0;
		}
		if (__state->btbeg[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
			i__1 : s_rnge(&__global_state->f2c, "btbeg", i__1, 
			"pckbsr_", (ftnlen)2497)] <= 0) {

/*                 This is the first node in the list for this body. */

		    __state->btbeg[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btbeg", i__1,
			     "pckbsr_", (ftnlen)2501)] = new__;
		} else {

/*                 Link the new node to the tail of the list. */

		    tail = -lnkprv_(__global_state, &__state->btbeg[(i__1 = 
			    bindex - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "btbeg", i__1, "pckbsr_", (
			    ftnlen)2507)], __state->stpool);
		    lnkila_(__global_state, &tail, &new__, __state->stpool);
		}
		s_copy(&__global_state->f2c, status, "RESUME", (ftnlen)15, (
			ftnlen)6);
	    }
	} else if (s_cmp(&__global_state->f2c, status, "SEARCH W/O BUFF", (
		ftnlen)15, (ftnlen)15) == 0) {

/*           When the segment table is completely full, continue */
/*           the search by looking through the unchecked portion */
/*           of the segment list for the current body, and */
/*           then searching old, unchecked files without buffering */
/*           their segments. */

/*           The only way to get here is from the MAKE ROOM state */
/*           via the block ADD TO END.  If you get here there is no */
/*           free space in the segment table pool. */

/*           At this point, we need to initialize the cost of */
/*           the re-use interval. */

	    __state->btruex[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btruex", i__1, "pckbsr_", (
		    ftnlen)2533)] = 0;

/*           Need to find the portion of the current body's segment */
/*           list which comes from the current file of interest.  It */
/*           will be returned to the segment table pool, since the */
/*           remainder of the file's segments can't be added to the list. */

	    crflbg = __state->btbeg[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "btbeg", i__1, "pckb"
		    "sr_", (ftnlen)2541)];
	    fndhan = FALSE_;
	    while(! fndhan && crflbg > 0) {
		fndhan = __state->sthan[(i__1 = crflbg - 1) < 5000 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "sthan", 
			i__1, "pckbsr_", (ftnlen)2546)] == __state->fthan[(
			i__2 = findex - 1) < 5000 && 0 <= i__2 ? i__2 : 
			s_rnge(&__global_state->f2c, "fthan", i__2, "pckbsr_",
			 (ftnlen)2546)];
		if (! fndhan) {

/*                 Get the next node.  We avoid LNKNXT here in order */
/*                 to speed up the operation. */

		    crflbg = __state->stpool[(i__1 = (crflbg << 1) + 10) < 
			    10012 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "stpool", i__1, "pckbsr_", (
			    ftnlen)2553)];
		}
	    }
	    if (crflbg > 0) {

/*              The sub-list from the current node onwards is to be */
/*              returned to the segment table pool.  Save this node, */
/*              since we'll finish searching the list before freeing */
/*              the sub-list. */

		p = crflbg;

/*              It may be that the sub-list we're deleting is the */
/*              entire segment list for this body.  If so, the */
/*              corresponding body table entry should be set to */
/*              a non-positive value to indicate an empty segment list. */

		if (p == __state->btbeg[(i__1 = bindex - 1) < 20 && 0 <= i__1 
			? i__1 : s_rnge(&__global_state->f2c, "btbeg", i__1, 
			"pckbsr_", (ftnlen)2574)]) {
		    __state->btbeg[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btbeg", i__1,
			     "pckbsr_", (ftnlen)2576)] = 0;

/*                 Also in this case, we must initialize the re-use */
/*                 interval for this body. */

		    __state->btlb[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btlb", i__1, 
			    "pckbsr_", (ftnlen)2581)] = dpmin_(__global_state)
			    ;
		    __state->btub[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btub", i__1, 
			    "pckbsr_", (ftnlen)2582)] = dpmax_(__global_state)
			    ;
		}

/*              Finish searching through the incomplete list for the */
/*              desired segment. */

		while(crflbg > 0) {

/*                 Every segment seen from the current file contributes */
/*                 to the expense of the re-use interval. */

		    __state->btruex[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btruex", 
			    i__1, "pckbsr_", (ftnlen)2595)] = __state->btruex[
			    (i__2 = bindex - 1) < 20 && 0 <= i__2 ? i__2 : 
			    s_rnge(&__global_state->f2c, "btruex", i__2, 
			    "pckbsr_", (ftnlen)2595)] + 1;
		    if (*et > __state->stdes[(i__1 = crflbg * 5 - 4) < 25000 
			    && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c,
			     "stdes", i__1, "pckbsr_", (ftnlen)2598)]) {

/*                    ET is to the right of the coverage interval of this */
/*                    segment. */

/* Computing MAX */
			d__1 = __state->btlb[(i__2 = bindex - 1) < 20 && 0 <= 
				i__2 ? i__2 : s_rnge(&__global_state->f2c, 
				"btlb", i__2, "pckbsr_", (ftnlen)2603)], d__2 
				= __state->stdes[(i__3 = crflbg * 5 - 4) < 
				25000 && 0 <= i__3 ? i__3 : s_rnge(&
				__global_state->f2c, "stdes", i__3, "pckbsr_",
				 (ftnlen)2603)];
			__state->btlb[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
				i__1 : s_rnge(&__global_state->f2c, "btlb", 
				i__1, "pckbsr_", (ftnlen)2603)] = max(d__1,
				d__2);
		    } else if (*et < __state->stdes[(i__1 = crflbg * 5 - 5) < 
			    25000 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "stdes", i__1, "pckbsr_", (
			    ftnlen)2606)]) {

/*                    ET is to the left of the coverage interval of this */
/*                    segment. */

/* Computing MIN */
			d__1 = __state->btub[(i__2 = bindex - 1) < 20 && 0 <= 
				i__2 ? i__2 : s_rnge(&__global_state->f2c, 
				"btub", i__2, "pckbsr_", (ftnlen)2611)], d__2 
				= __state->stdes[(i__3 = crflbg * 5 - 5) < 
				25000 && 0 <= i__3 ? i__3 : s_rnge(&
				__global_state->f2c, "stdes", i__3, "pckbsr_",
				 (ftnlen)2611)];
			__state->btub[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
				i__1 : s_rnge(&__global_state->f2c, "btub", 
				i__1, "pckbsr_", (ftnlen)2611)] = min(d__1,
				d__2);
		    } else {

/*                    The segment coverage interval includes ET. */

			moved_(__global_state, &__state->stdes[(i__1 = crflbg 
				* 5 - 5) < 25000 && 0 <= i__1 ? i__1 : s_rnge(
				&__global_state->f2c, "stdes", i__1, "pckbsr_"
				, (ftnlen)2617)], &__state->c__5, descr);
			s_copy(&__global_state->f2c, ident, __state->stidnt + 
				((i__1 = crflbg - 1) < 5000 && 0 <= i__1 ? 
				i__1 : s_rnge(&__global_state->f2c, "stidnt", 
				i__1, "pckbsr_", (ftnlen)2619)) * 40, 
				ident_len, (ftnlen)40);
			*handle = __state->sthan[(i__1 = crflbg - 1) < 5000 &&
				 0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "sthan", i__1, "pckbsr_",
				 (ftnlen)2620)];
			*found = TRUE_;

/*                    Set the re-use interval for the current body. */

/* Computing MAX */
			d__1 = __state->btlb[(i__2 = bindex - 1) < 20 && 0 <= 
				i__2 ? i__2 : s_rnge(&__global_state->f2c, 
				"btlb", i__2, "pckbsr_", (ftnlen)2626)], d__2 
				= __state->stdes[(i__3 = crflbg * 5 - 5) < 
				25000 && 0 <= i__3 ? i__3 : s_rnge(&
				__global_state->f2c, "stdes", i__3, "pckbsr_",
				 (ftnlen)2626)];
			__state->btlb[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
				i__1 : s_rnge(&__global_state->f2c, "btlb", 
				i__1, "pckbsr_", (ftnlen)2626)] = max(d__1,
				d__2);
/* Computing MIN */
			d__1 = __state->btub[(i__2 = bindex - 1) < 20 && 0 <= 
				i__2 ? i__2 : s_rnge(&__global_state->f2c, 
				"btub", i__2, "pckbsr_", (ftnlen)2627)], d__2 
				= __state->stdes[(i__3 = crflbg * 5 - 4) < 
				25000 && 0 <= i__3 ? i__3 : s_rnge(&
				__global_state->f2c, "stdes", i__3, "pckbsr_",
				 (ftnlen)2627)];
			__state->btub[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
				i__1 : s_rnge(&__global_state->f2c, "btub", 
				i__1, "pckbsr_", (ftnlen)2627)] = min(d__1,
				d__2);

/*                    Save the output items, in case this */
/*                    segment may be satisfy the next request. */

			__state->btprvh[(i__1 = bindex - 1) < 20 && 0 <= i__1 
				? i__1 : s_rnge(&__global_state->f2c, "btprvh"
				, i__1, "pckbsr_", (ftnlen)2633)] = *handle;
			s_copy(&__global_state->f2c, __state->btprvi + ((i__1 
				= bindex - 1) < 20 && 0 <= i__1 ? i__1 : 
				s_rnge(&__global_state->f2c, "btprvi", i__1, 
				"pckbsr_", (ftnlen)2634)) * 40, ident, (
				ftnlen)40, ident_len);
			moved_(__global_state, descr, &__state->c__5, &
				__state->btprvd[(i__1 = bindex * 5 - 5) < 100 
				&& 0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "btprvd", i__1, "pckbsr_"
				, (ftnlen)2635)]);
			__state->btchkp[(i__1 = bindex - 1) < 20 && 0 <= i__1 
				? i__1 : s_rnge(&__global_state->f2c, "btchkp"
				, i__1, "pckbsr_", (ftnlen)2636)] = TRUE_;

/*                    Update the expense of the list to reflect */
/*                    the cost of locating this segment. */

			__state->btexp[(i__1 = bindex - 1) < 20 && 0 <= i__1 ?
				 i__1 : s_rnge(&__global_state->f2c, "btexp", 
				i__1, "pckbsr_", (ftnlen)2642)] = 
				__state->btexp[(i__2 = bindex - 1) < 20 && 0 
				<= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
				"btexp", i__2, "pckbsr_", (ftnlen)2642)] + 
				__state->btruex[(i__3 = bindex - 1) < 20 && 0 
				<= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
				"btruex", i__3, "pckbsr_", (ftnlen)2642)];

/*                    Free the sub-list we were searching. */

			tail = lnktl_(__global_state, &crflbg, 
				__state->stpool);
			lnkfsl_(__global_state, &p, &tail, __state->stpool);
			chkout_(__global_state, "PCKSFS", (ftnlen)6);
			return 0;
		    }
/*                 Get the next node.  We avoid LNKNXT here in order */
/*                 to speed up the operation. */

		    crflbg = __state->stpool[(i__1 = (crflbg << 1) + 10) < 
			    10012 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "stpool", i__1, "pckbsr_", (
			    ftnlen)2658)];
		}

/*              Return the sub-list to the segment table pool. */
/*              CRFLBG at this point is the negative of the list head. */
/*              The list tail is (by the spec of the SPICELIB doubly */
/*              linked list routines) the negative of the predecessor */
/*              of the head. */

/*              Note the list is always non-empty. */

		i__1 = -crflbg;
		tail = -lnkprv_(__global_state, &i__1, __state->stpool);
		lnkfsl_(__global_state, &p, &tail, __state->stpool);
	    }

/*           Search through the remaining files without buffering. */
/*           Recall that a search is already in progress and that a */
/*           segment is currently under consideration (FND = .TRUE.). */

	    while(findex > 0) {
		while(fnd) {

/*                 Each segment found contributes to the expense of the */
/*                 re-use interval. */

		    __state->btruex[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
			    i__1 : s_rnge(&__global_state->f2c, "btruex", 
			    i__1, "pckbsr_", (ftnlen)2689)] = __state->btruex[
			    (i__2 = bindex - 1) < 20 && 0 <= i__2 ? i__2 : 
			    s_rnge(&__global_state->f2c, "btruex", i__2, 
			    "pckbsr_", (ftnlen)2689)] + 1;
		    dafgs_(__global_state, descr);
		    dafus_(__global_state, descr, &__state->c__2, &
			    __state->c__5, dcd, icd);
		    if (failed_(__global_state)) {
			chkout_(__global_state, "PCKSFS", (ftnlen)6);
			return 0;
		    }
		    if (*body == icd[0]) {

/*                    This is a segment for the body of interest. */
/*                    Update the re-use interval for this body. */

			if (*et > dcd[1]) {

/*                       ET is to the right of the coverage interval */
/*                       of this segment. */

/* Computing MAX */
			    d__1 = __state->btlb[(i__2 = bindex - 1) < 20 && 
				    0 <= i__2 ? i__2 : s_rnge(&
				    __global_state->f2c, "btlb", i__2, "pckb"
				    "sr_", (ftnlen)2709)];
			    __state->btlb[(i__1 = bindex - 1) < 20 && 0 <= 
				    i__1 ? i__1 : s_rnge(&__global_state->f2c,
				     "btlb", i__1, "pckbsr_", (ftnlen)2709)] =
				     max(d__1,dcd[1]);
			} else if (*et < dcd[0]) {

/*                       ET is to the left of the coverage interval */
/*                       of this segment. */

/* Computing MIN */
			    d__1 = __state->btub[(i__2 = bindex - 1) < 20 && 
				    0 <= i__2 ? i__2 : s_rnge(&
				    __global_state->f2c, "btub", i__2, "pckb"
				    "sr_", (ftnlen)2717)];
			    __state->btub[(i__1 = bindex - 1) < 20 && 0 <= 
				    i__1 ? i__1 : s_rnge(&__global_state->f2c,
				     "btub", i__1, "pckbsr_", (ftnlen)2717)] =
				     min(d__1,dcd[0]);
			} else {

/*                       The segment coverage interval includes ET. */

			    dafgn_(__global_state, ident, ident_len);
			    if (failed_(__global_state)) {
				chkout_(__global_state, "PCKSFS", (ftnlen)6);
				return 0;
			    }
			    *handle = __state->fthan[(i__1 = findex - 1) < 
				    5000 && 0 <= i__1 ? i__1 : s_rnge(&
				    __global_state->f2c, "fthan", i__1, "pck"
				    "bsr_", (ftnlen)2730)];
			    *found = TRUE_;

/*                       Set the re-use interval for the current body. */

/* Computing MAX */
			    d__1 = __state->btlb[(i__2 = bindex - 1) < 20 && 
				    0 <= i__2 ? i__2 : s_rnge(&
				    __global_state->f2c, "btlb", i__2, "pckb"
				    "sr_", (ftnlen)2736)];
			    __state->btlb[(i__1 = bindex - 1) < 20 && 0 <= 
				    i__1 ? i__1 : s_rnge(&__global_state->f2c,
				     "btlb", i__1, "pckbsr_", (ftnlen)2736)] =
				     max(d__1,dcd[0]);
/* Computing MIN */
			    d__1 = __state->btub[(i__2 = bindex - 1) < 20 && 
				    0 <= i__2 ? i__2 : s_rnge(&
				    __global_state->f2c, "btub", i__2, "pckb"
				    "sr_", (ftnlen)2737)];
			    __state->btub[(i__1 = bindex - 1) < 20 && 0 <= 
				    i__1 ? i__1 : s_rnge(&__global_state->f2c,
				     "btub", i__1, "pckbsr_", (ftnlen)2737)] =
				     min(d__1,dcd[1]);

/*                       Save the output items, in case this */
/*                       segment may satisfy the next request. */

			    __state->btprvh[(i__1 = bindex - 1) < 20 && 0 <= 
				    i__1 ? i__1 : s_rnge(&__global_state->f2c,
				     "btprvh", i__1, "pckbsr_", (ftnlen)2743)]
				     = *handle;
			    s_copy(&__global_state->f2c, __state->btprvi + ((
				    i__1 = bindex - 1) < 20 && 0 <= i__1 ? 
				    i__1 : s_rnge(&__global_state->f2c, "btp"
				    "rvi", i__1, "pckbsr_", (ftnlen)2744)) * 
				    40, ident, (ftnlen)40, ident_len);
			    moved_(__global_state, descr, &__state->c__5, &
				    __state->btprvd[(i__1 = bindex * 5 - 5) < 
				    100 && 0 <= i__1 ? i__1 : s_rnge(&
				    __global_state->f2c, "btprvd", i__1, 
				    "pckbsr_", (ftnlen)2745)]);
			    __state->btchkp[(i__1 = bindex - 1) < 20 && 0 <= 
				    i__1 ? i__1 : s_rnge(&__global_state->f2c,
				     "btchkp", i__1, "pckbsr_", (ftnlen)2746)]
				     = TRUE_;

/*                       Update the expense of the list to reflect */
/*                       the cost of locating this segment. */

			    __state->btexp[(i__1 = bindex - 1) < 20 && 0 <= 
				    i__1 ? i__1 : s_rnge(&__global_state->f2c,
				     "btexp", i__1, "pckbsr_", (ftnlen)2752)] 
				    = __state->btexp[(i__2 = bindex - 1) < 20 
				    && 0 <= i__2 ? i__2 : s_rnge(&
				    __global_state->f2c, "btexp", i__2, "pck"
				    "bsr_", (ftnlen)2752)] + __state->btruex[(
				    i__3 = bindex - 1) < 20 && 0 <= i__3 ? 
				    i__3 : s_rnge(&__global_state->f2c, "btr"
				    "uex", i__3, "pckbsr_", (ftnlen)2752)];
			    chkout_(__global_state, "PCKSFS", (ftnlen)6);
			    return 0;
			}
		    }
		    daffpa_(__global_state, &fnd);
		    if (failed_(__global_state)) {
			chkout_(__global_state, "PCKSFS", (ftnlen)6);
			return 0;
		    }
		}

/*              Try the next oldest file. */

		--findex;
		if (findex > 0) {
		    dafbbs_(__global_state, &__state->fthan[(i__1 = findex - 
			    1) < 5000 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "fthan", i__1, "pckbsr_", (
			    ftnlen)2777)]);
		    daffpa_(__global_state, &fnd);
		    if (failed_(__global_state)) {
			chkout_(__global_state, "PCKSFS", (ftnlen)6);
			return 0;
		    }
		}
	    }

/*           If you get to here, sorry. */

	    __state->btruex[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "btruex", i__1, "pckbsr_", (
		    ftnlen)2792)] = 0;
	    s_copy(&__global_state->f2c, status, "HOPELESS", (ftnlen)15, (
		    ftnlen)8);

/*        When a task is suspended, the current activity is placed on */
/*        a stack, to be restored later. Two levels are provided, since */
/*        some interrupts can be interrupted by others. */

	} else if (s_cmp(&__global_state->f2c, status, "SUSPEND", (ftnlen)15, 
		(ftnlen)7) == 0) {
	    ++top;
	    s_copy(&__global_state->f2c, stack + ((i__1 = top - 1) < 2 && 0 <=
		     i__1 ? i__1 : s_rnge(&__global_state->f2c, "stack", i__1,
		     "pckbsr_", (ftnlen)2803)) * 15, doing, (ftnlen)15, (
		    ftnlen)15);
	    s_copy(&__global_state->f2c, status, urgent, (ftnlen)15, (ftnlen)
		    15);
	} else if (s_cmp(&__global_state->f2c, status, "RESUME", (ftnlen)15, (
		ftnlen)6) == 0) {

/*           Pop the status stack. */

	    s_copy(&__global_state->f2c, status, stack + ((i__1 = top - 1) < 
		    2 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "stack", i__1, "pckbsr_", (ftnlen)2810)) * 15, (ftnlen)15,
		     (ftnlen)15);
	    --top;
	}
    }

/*     If we didn't find a segment, don't attempt to use saved */
/*     outputs from a previous call.  BINDEX will always be set */
/*     at this point.  Also, zero out the expense of the re-use */
/*     interval. */

    if (bindex > 0) {
	__state->btchkp[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge(
		&__global_state->f2c, "btchkp", i__1, "pckbsr_", (ftnlen)2825)
		] = FALSE_;
	__state->btruex[(i__1 = bindex - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge(
		&__global_state->f2c, "btruex", i__1, "pckbsr_", (ftnlen)2826)
		] = 0;
    }
    chkout_(__global_state, "PCKSFS", (ftnlen)6);
    return 0;
} /* pckbsr_ */

/* Subroutine */ int pckbsr_(cspice_t* __global_state, char *fname, integer *
	handle, integer *body, doublereal *et, doublereal *descr, char *ident,
	 logical *found, ftnlen fname_len, ftnlen ident_len)
{
    return pckbsr_0_(__global_state, 0, fname, handle, body, et, descr, ident,
	     found, fname_len, ident_len);
    }

/* Subroutine */ int pcklof_(cspice_t* __global_state, char *fname, integer *
	handle, ftnlen fname_len)
{
    return pckbsr_0_(__global_state, 1, fname, handle, (integer *)0, (
	    doublereal *)0, (doublereal *)0, (char *)0, (logical *)0, 
	    fname_len, (ftnint)0);
    }

/* Subroutine */ int pckuof_(cspice_t* __global_state, integer *handle)
{
    return pckbsr_0_(__global_state, 2, (char *)0, handle, (integer *)0, (
	    doublereal *)0, (doublereal *)0, (char *)0, (logical *)0, (ftnint)
	    0, (ftnint)0);
    }

/* Subroutine */ int pcksfs_(cspice_t* __global_state, integer *body, 
	doublereal *et, integer *handle, doublereal *descr, char *ident, 
	logical *found, ftnlen ident_len)
{
    return pckbsr_0_(__global_state, 3, (char *)0, handle, body, et, descr, 
	    ident, found, (ftnint)0, ident_len);
    }

