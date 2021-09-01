/* daffa.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern daffa_init_t __daffa_init;
static daffa_state_t* get_daffa_state(cspice_t* state) {
	if (!state->daffa)
		state->daffa = __cspice_allocate_module(sizeof(daffa_state_t),
	 &__daffa_init, sizeof(__daffa_init));
	return state->daffa;

}

/* $Procedure DAFFA ( DAF, find array ) */
/* Subroutine */ int daffa_0_(cspice_t* __global_state, int n__, integer *
	handle, doublereal *sum, char *name__, logical *found, ftnlen 
	name_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3, i__4;

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern logical elemi_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int dafps_(cspice_t*, integer *, integer *, 
	    doublereal *, integer *, doublereal *);
    extern /* Subroutine */ int dafus_(cspice_t*, doublereal *, integer *, 
	    integer *, doublereal *, integer *);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int moved_(cspice_t*, doublereal *, integer *, 
	    doublereal *);
    extern /* Subroutine */ int movei_(cspice_t*, integer *, integer *, 
	    integer *);
    extern logical failed_(cspice_t*);
    extern /* Subroutine */ int dafhof_(cspice_t*, integer *);
    extern /* Subroutine */ int dafhfn_(cspice_t*, integer *, char *, ftnlen);
    extern /* Subroutine */ int dafhsf_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int dafsih_(cspice_t*, integer *, char *, ftnlen);
    extern /* Subroutine */ int dafrcr_(cspice_t*, integer *, integer *, char 
	    *, ftnlen);
    extern /* Subroutine */ int dafrfr_(cspice_t*, integer *, integer *, 
	    integer *, char *, integer *, integer *, integer *, ftnlen);
    extern /* Subroutine */ int dafgsr_(cspice_t*, integer *, integer *, 
	    integer *, integer *, doublereal *, logical *);
    extern /* Subroutine */ int dafwdr_(cspice_t*, integer *, integer *, 
	    doublereal *);
    extern /* Subroutine */ int dafwcr_(cspice_t*, integer *, integer *, char 
	    *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int ssizei_(cspice_t*, integer *, integer *);
    extern logical return_(cspice_t*);

    /* Module state */
    daffa_state_t* __state = get_daffa_state(__global_state);
/* $ Abstract */

/*     Find arrays in a DAF. */

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

/*     DAF */

/* $ Keywords */

/*     FILES */

/* $ Declarations */

/* $ Abstract */

/*     Parameter declarations for the DAF/DAS handle manager. */

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

/*     DAF, DAS */

/* $ Keywords */

/*     PRIVATE */

/* $ Particulars */

/*     This include file contains parameters defining limits and */
/*     integer codes that are utilized in the DAF/DAS handle manager */
/*     routines. */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     F.S. Turner       (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 2.5.0, 10-MAR-2014 (BVS) */

/*        Updated for SUN-SOLARIS-64BIT-INTEL. */

/* -    SPICELIB Version 2.4.0, 10-MAR-2014 (BVS) */

/*        Updated for PC-LINUX-64BIT-IFORT. */

/* -    SPICELIB Version 2.3.0, 10-MAR-2014 (BVS) */

/*        Updated for PC-CYGWIN-GFORTRAN. */

/* -    SPICELIB Version 2.2.0, 10-MAR-2014 (BVS) */

/*        Updated for PC-CYGWIN-64BIT-GFORTRAN. */

/* -    SPICELIB Version 2.1.0, 10-MAR-2014 (BVS) */

/*        Updated for PC-CYGWIN-64BIT-GCC_C. */

/* -    SPICELIB Version 2.0.0, 12-APR-2012 (BVS) */

/*        Increased FTSIZE (from 1000 to 5000). */

/* -    SPICELIB Version 1.20.0, 13-MAY-2010 (BVS) */

/*        Updated for SUN-SOLARIS-INTEL. */

/* -    SPICELIB Version 1.19.0, 13-MAY-2010 (BVS) */

/*        Updated for SUN-SOLARIS-INTEL-CC_C. */

/* -    SPICELIB Version 1.18.0, 13-MAY-2010 (BVS) */

/*        Updated for SUN-SOLARIS-INTEL-64BIT-CC_C. */

/* -    SPICELIB Version 1.17.0, 13-MAY-2010 (BVS) */

/*        Updated for SUN-SOLARIS-64BIT-NATIVE_C. */

/* -    SPICELIB Version 1.16.0, 13-MAY-2010 (BVS) */

/*        Updated for PC-WINDOWS-64BIT-IFORT. */

/* -    SPICELIB Version 1.15.0, 13-MAY-2010 (BVS) */

/*        Updated for PC-LINUX-64BIT-GFORTRAN. */

/* -    SPICELIB Version 1.14.0, 13-MAY-2010 (BVS) */

/*        Updated for PC-64BIT-MS_C. */

/* -    SPICELIB Version 1.13.0, 13-MAY-2010 (BVS) */

/*        Updated for MAC-OSX-64BIT-INTEL_C. */

/* -    SPICELIB Version 1.12.0, 13-MAY-2010 (BVS) */

/*        Updated for MAC-OSX-64BIT-IFORT. */

/* -    SPICELIB Version 1.11.0, 13-MAY-2010 (BVS) */

/*        Updated for MAC-OSX-64BIT-GFORTRAN. */

/* -    SPICELIB Version 1.10.0, 18-MAR-2009 (BVS) */

/*        Updated for PC-LINUX-GFORTRAN. */

/* -    SPICELIB Version 1.9.0, 18-MAR-2009 (BVS) */

/*        Updated for MAC-OSX-GFORTRAN. */

/* -    SPICELIB Version 1.8.0, 19-FEB-2008 (BVS) */

/*        Updated for PC-LINUX-IFORT. */

/* -    SPICELIB Version 1.7.0, 14-NOV-2006 (BVS) */

/*        Updated for PC-LINUX-64BIT-GCC_C. */

/* -    SPICELIB Version 1.6.0, 14-NOV-2006 (BVS) */

/*        Updated for MAC-OSX-INTEL_C. */

/* -    SPICELIB Version 1.5.0, 14-NOV-2006 (BVS) */

/*        Updated for MAC-OSX-IFORT. */

/* -    SPICELIB Version 1.4.0, 14-NOV-2006 (BVS) */

/*        Updated for PC-WINDOWS-IFORT. */

/* -    SPICELIB Version 1.3.0, 26-OCT-2005 (BVS) */

/*        Updated for SUN-SOLARIS-64BIT-GCC_C. */

/* -    SPICELIB Version 1.2.0, 03-JAN-2005 (BVS) */

/*        Updated for PC-CYGWIN_C. */

/* -    SPICELIB Version 1.1.0, 03-JAN-2005 (BVS) */

/*        Updated for PC-CYGWIN. */

/* -    SPICELIB Version 1.0.1, 17-JUL-2002 */

/*        Added MAC-OSX environments. */

/* -    SPICELIB Version 1.0.0, 07-NOV-2001 */

/* -& */

/*     Unit and file table size parameters. */

/*     FTSIZE     is the maximum number of files (DAS and DAF) that a */
/*                user may have open simultaneously. */


/*     RSVUNT     is the number of units protected from being locked */
/*                to a particular handle by ZZDDHHLU. */


/*     SCRUNT     is the number of units protected for use by scratch */
/*                files. */


/*     UTSIZE     is the maximum number of logical units this manager */
/*                will utilize at one time. */


/*     Access method enumeration.  These parameters are used to */
/*     identify which access method is associated with a particular */
/*     handle.  They need to be synchronized with the STRAMH array */
/*     defined in ZZDDHGSD in the following fashion: */

/*        STRAMH ( READ   ) = 'READ' */
/*        STRAMH ( WRITE  ) = 'WRITE' */
/*        STRAMH ( SCRTCH ) = 'SCRATCH' */
/*        STRAMH ( NEW    ) = 'NEW' */

/*     These values are used in the file table variable FTAMH. */


/*     Binary file format enumeration.  These parameters are used to */
/*     identify which binary file format is associated with a */
/*     particular handle.  They need to be synchronized with the STRBFF */
/*     array defined in ZZDDHGSD in the following fashion: */

/*        STRBFF ( BIGI3E ) = 'BIG-IEEE' */
/*        STRBFF ( LTLI3E ) = 'LTL-IEEE' */
/*        STRBFF ( VAXGFL ) = 'VAX-GFLT' */
/*        STRBFF ( VAXDFL ) = 'VAX-DFLT' */

/*     These values are used in the file table variable FTBFF. */


/*     Some random string lengths... more documentation required. */
/*     For now this will have to suffice. */


/*     Architecture enumeration.  These parameters are used to identify */
/*     which file architecture is associated with a particular handle. */
/*     They need to be synchronized with the STRARC array defined in */
/*     ZZDDHGSD in the following fashion: */

/*        STRARC ( DAF ) = 'DAF' */
/*        STRARC ( DAS ) = 'DAS' */

/*     These values will be used in the file table variable FTARC. */


/*     For the following environments, record length is measured in */
/*     characters (bytes) with eight characters per double precision */
/*     number. */

/*     Environment: Sun, Sun FORTRAN */
/*     Source:      Sun Fortran Programmer's Guide */

/*     Environment: PC, MS FORTRAN */
/*     Source:      Microsoft Fortran Optimizing Compiler User's Guide */

/*     Environment: Macintosh, Language Systems FORTRAN */
/*     Source:      Language Systems FORTRAN Reference Manual, */
/*                  Version 1.2, page 12-7 */

/*     Environment: PC/Linux, g77 */
/*     Source:      Determined by experiment. */

/*     Environment: PC, Lahey F77 EM/32 Version 4.0 */
/*     Source:      Lahey F77 EM/32 Language Reference Manual, */
/*                  page 144 */

/*     Environment: HP-UX 9000/750, FORTRAN/9000 Series 700 computers */
/*     Source:      FORTRAN/9000 Reference-Series 700 Computers, */
/*                  page 5-110 */

/*     Environment: NeXT Mach OS (Black Hardware), */
/*                  Absoft Fortran Version 3.2 */
/*     Source:      NAIF Program */


/*     The following parameter defines the size of a string used */
/*     to store a filenames on this target platform. */


/*     The following parameter controls the size of the character record */
/*     buffer used to read data from non-native files. */

/* $ Brief_I/O */

/*     Variable  I/O  Entry */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE    I,O  DAFBFS, DAFBBS, DAFGH, DAFCS */
/*     SUM       I,O  DAFGS,  DAFRS,  DAFWS */
/*     NAME      I,O  DAFGN,  DAFRN */
/*     FOUND      O   DAFFNA, DAFFPA */

/* $ Detailed_Input */

/*     HANDLE      on input is the handle of the DAF to be searched. */

/*     SUM         on input is an array summary that replaces the */
/*                 summary of the current array in the DAF currently */
/*                 being searched. */

/*     NAME        on input is an array name that replaces the name */
/*                 of the current array in the DAF currently being */
/*                 searched. */

/* $ Detailed_Output */

/*     HANDLE      on output is the handle of the DAF currently being */
/*                 searched. */

/*     SUM         on output is the summary for the array found most */
/*                 recently. */

/*     NAME        on output is the name for the array found */
/*                 most recently. */

/*     FOUND       is true whenever the search for the next or the */
/*                 previous array is successful, and is false otherwise. */

/* $ Parameters */

/*     TBSIZE      the maximum number of files (DAS and DAF) that may be */
/*                 simultaneously open. TBSIZE is set to FTSIZE which is */
/*                 assigned and defined in zzdhman.inc. */

/* $ Exceptions */

/*     1) If DAFFA is called directly, the error SPICE(BOGUSENTRY) */
/*        is signaled. */

/*     2) See entry points DAFBFS, DAFFNA, DAFBBS, DAFFPA, DAFGS, DAFGN, */
/*        DAFGH, DAFRS, DAFWS, DAFRN, and DAFCS for exceptions specific */
/*        to those entry points. */

/* $ Files */

/*     DAFs read by DAFFA and its entry points are opened */
/*     elsewhere, and referred to only by their handles. */

/* $ Particulars */

/*     DAFFA serves as an umbrella, allowing data to be shared by its */
/*     entry points: */

/*        DAFBFS         Begin forward search. */
/*        DAFFNA         Find next array. */

/*        DAFBBS         Begin backward search. */
/*        DAFFPA         Find previous array. */

/*        DAFGS          Get summary. */
/*        DAFGN          Get name. */
/*        DAFGH          Get handle. */

/*        DAFRS          Replace summary. */
/*        DAFWS          Write summary. */
/*        DAFRN          Replace name. */

/*        DAFCS          Continue search. */

/*     The main function of these entry points is to allow the */
/*     contents of any DAF to be examined on an array-by-array */
/*     basis. */

/*     Conceptually, the arrays in a DAF form a doubly linked list, */
/*     which can be searched in either of two directions: forward or */
/*     backward. It is possible to search multiple DAFs simultaneously. */

/*     DAFBFS (begin forward search) and DAFFNA are used to search the */
/*     arrays in a DAF in forward order. In applications that search a */
/*     single DAF at a time, the normal usage is */

/*        CALL DAFBFS ( HANDLE ) */
/*        CALL DAFFNA ( FOUND  ) */

/*        DO WHILE ( FOUND ) */
/*           CALL DAFGS ( SUM  ) */
/*           CALL DAFGN ( NAME ) */
/*            . */
/*            . */

/*           CALL DAFFNA ( FOUND ) */
/*        END DO */



/*     DAFBBS (begin backward search) and DAFFPA are used to search the */
/*     arrays in a DAF in backward order. In applications that search */
/*     a single DAF at a time, the normal usage is */

/*        CALL DAFBBS ( HANDLE ) */
/*        CALL DAFFPA ( FOUND  ) */

/*        DO WHILE ( FOUND ) */
/*           CALL DAFGS ( SUM  ) */
/*           CALL DAFGN ( NAME ) */
/*            . */
/*            . */

/*           CALL DAFFPA ( FOUND ) */
/*        END DO */


/*     In applications that conduct multiple searches simultaneously, */
/*     the above usage must be modified to specify the handle of the */
/*     file to operate on, in any case where the file may not be the */
/*     last one specified by DAFBFS or DAFBBS. The routine DAFCS */
/*     (DAF, continue search) is used for this purpose. Below, we */
/*     give an example of an interleaved search of two files specified */
/*     by the handles HANDL1 and HANDL2. The directions of searches */
/*     in different DAFs are independent; here we conduct a forward */
/*     search on one file and a backward search on the other. */
/*     Throughout, we use DAFCS to specify which file to operate on, */
/*     before calling DAFFNA, DAFFPA, DAFGS, DAFRS, DAFWS, DAFGN, or */
/*     DAFRN. */


/*        CALL DAFBFS ( HANDL1 ) */
/*        CALL DAFBBS ( HANDL2 ) */

/*        CALL DAFCS  ( HANDL1 ) */
/*        CALL DAFFNA ( FOUND1 ) */

/*        CALL DAFCS  ( HANDL2 ) */
/*        CALL DAFFPA ( FOUND2 ) */

/*        DO WHILE ( FOUND1 .OR. FOUND2 ) */

/*           IF ( FOUND1 ) THEN */

/*              CALL DAFCS ( HANDL1 ) */
/*              CALL DAFGS ( SUM    ) */
/*              CALL DAFGN ( NAME   ) */
/*               . */
/*               . */
/*              CALL DAFCS  ( HANDL1 ) */
/*              CALL DAFFNA ( FOUND1 ) */

/*           END IF */

/*           IF ( FOUND2 ) THEN */

/*              CALL DAFCS ( HANDL2 ) */
/*              CALL DAFGS ( SUM    ) */
/*              CALL DAFGN ( NAME   ) */
/*               . */
/*               . */
/*              CALL DAFCS  ( HANDL2 ) */
/*              CALL DAFFPA ( FOUND2 ) */

/*           END IF */

/*        END DO */


/*     At any time, the latest array found (whether by DAFFNA or DAFFPA) */
/*     is regarded as the `current' array for the file in which the */
/*     array was found. The last DAF in which a search was started, */
/*     executed, or continued by any of DAFBFS, DAFBBS, DAFFNA, DAFFPA */
/*     or DAFCS is regarded as the `current' DAF. The summary and name */
/*     for the current array in the current DAF can be returned */
/*     separately, as shown above, by calls to DAFGS (get summary) and */
/*     DAFGN (get name). The handle of the current DAF can also be */
/*     returned by calling DAFGH (get handle). */

/*     The summary and name of the current array in the current DAF can */
/*     be updated (again, separately) by providing new ones through DAFRS */
/*     (replace summary) and DAFRN (replace name). This feature */
/*     should not be used except to correct errors that occurred during */
/*     the creation of a file. Note that changes can only be made to */
/*     files opened for write access. Also, the addresses of an array */
/*     cannot be changed using these routines. (Another routine, */
/*     DAFWS, is provided for this purpose, but should be used only */
/*     to reorder the arrays in a file.) */

/*     Once a search has been begun, it may be continued in either */
/*     direction. That is, DAFFPA may be used to back up during a */
/*     forward search, and DAFFNA may be used to advance during a */
/*     backward search. */

/* $ Examples */

/*     1) The following code fragment illustrates the way the entry */
/*        points of DAFFA might be used to edit the summaries and names */
/*        for the arrays contained in a DAF. (All subroutines and */
/*        functions are from SPICELIB.) */

/*        In this example, the user begins by supplying the name of */
/*        the file to be edited, followed by any number of the following */
/*        commands. */

/*           NEXT      finds the next array. */

/*           PREV      finds the previous array. */

/*           EDIT      changes the value of an item in the summary or */
/*                     of the entire name. The keyword EDIT is */
/*                     always followed by the name of the item to be */
/*                     edited, */

/*                        DC n */
/*                        IC n */
/*                        NAME */

/*                     and the value, e.g., */

/*                        EDIT IC 2 315 */
/*                        EDIT NAME NAIF test K2905-1 */

/*        The user may terminate the session at any time by typing END. */
/*        Commands other than those listed above are ignored. */

/*           READ (*,FMT='(A)') FNAME */
/*           CALL DAFOPW ( FNAME, HANDLE ) */
/*           CALL DAFBFS ( HANDLE ) */

/*           READ (*,FMT='(A)') COMMAND */

/*           DO WHILE ( COMMAND .NE. 'END' ) */
/*              CALL NEXTWD ( COMMAND, VERB, COMMAND ) */

/*              IF ( VERB .EQ. 'NEXT' ) THEN */
/*                 CALL DAFFNA ( FOUND ) */
/*                 IF ( .NOT. FOUND ) THEN */
/*                    WRITE (*,*) 'At end of array list.' */
/*                 END IF */

/*              IF ( VERB .EQ. 'PREV' ) THEN */
/*                 CALL DAFFPA ( FOUND ) */
/*                 IF ( .NOT. FOUND ) THEN */
/*                    WRITE (*,*) 'At beginning of array list.' */
/*                 END IF */

/*              IF ( VERB .EQ. 'EDIT' ) THEN */
/*                 CALL DAFGS ( SUM ) */
/*                 CALL DAFGN ( NAME ) */
/*                 CALL DAFUS ( SUM, ND, NI, DC, IC ) */

/*                 CALL NEXTWD ( COMMAND, ITEM, VALUE ) */

/*                 IF ( ITEM .EQ. 'DC' ) THEN */
/*                    CALL NEXTWD ( VALUE, INDEX, VALUE ) */
/*                    CALL NPARSI ( INDEX, LOC,     ERR, PTR ) */
/*                    CALL NPARSD ( VALUE, DC(LOC), ERR, PTR ) */

/*                 ELSE IF ( ITEM .EQ. 'IC' ) THEN */
/*                    CALL NEXTWD ( VALUE, INDEX, VALUE ) */
/*                    CALL NPARSI ( INDEX, LOC,     ERR, PTR ) */
/*                    CALL NPARSI ( VALUE, IC(LOC), ERR, PTR ) */

/*                 ELSE IF ( ITEM .EQ. 'NAME' ) THEN */
/*                    NAME = VALUE */
/*                 END IF */

/*                 CALL DAFPS ( ND, NI, DC, IC, SUM ) */
/*                 CALL DAFRS ( SUM ) */
/*                 CALL DAFRN ( NAME ) */
/*              END IF */

/*              READ (*,FMT='(A)') COMMAND */
/*           END DO */


/*     2)  The following program compares data in two DAFs. The DAFs are */
/*         expected to have the same number of arrays, the same number */
/*         of elements in each corresponding array, and the same summary */
/*         format. */

/*         Each difference whose magnitude exceeds a specified tolerance */
/*         is flagged. The difference information is written to a file. */


/*           PROGRAM CMPDAF */
/*           IMPLICIT NONE */
/*     C */
/*     C     Compare data in two DAFs having identical structures. */
/*     C     No array in either DAF is longer than ARRYSZ d.p. */
/*     C     numbers. */
/*     C */

/*     C */
/*     C     Local parameters */
/*     C */
/*           INTEGER               ARRYSZ */
/*           PARAMETER           ( ARRYSZ = 10000000 ) */

/*           INTEGER               ERRLEN */
/*           PARAMETER           ( ERRLEN =  240 ) */

/*           INTEGER               FILEN */
/*           PARAMETER           ( FILEN  =  128 ) */

/*           INTEGER               LINLEN */
/*           PARAMETER           ( LINLEN =   80 ) */

/*           INTEGER               MAXND */
/*           PARAMETER           ( MAXND  =  125 ) */

/*           INTEGER               MAXNI */
/*           PARAMETER           ( MAXNI  =  250 ) */

/*           INTEGER               MAXSUM */
/*           PARAMETER           ( MAXSUM =  128 ) */

/*           INTEGER               RLEN */
/*           PARAMETER           ( RLEN   = 1000 ) */


/*     C */
/*     C     Local variables */
/*     C */
/*           CHARACTER*(RLEN)      ANAME1 */
/*           CHARACTER*(RLEN)      ANAME2 */
/*           CHARACTER*(FILEN)     DAF1 */
/*           CHARACTER*(FILEN)     DAF2 */
/*           CHARACTER*(FILEN)     LOG */
/*           CHARACTER*(ERRLEN)    PRSERR */
/*           CHARACTER*(LINLEN)    STR */
/*           CHARACTER*(LINLEN)    TOLCH */

/*           DOUBLE PRECISION      ARRAY1 ( ARRYSZ ) */
/*           DOUBLE PRECISION      ARRAY2 ( ARRYSZ ) */
/*           DOUBLE PRECISION      DC1    ( MAXND ) */
/*           DOUBLE PRECISION      DC2    ( MAXND ) */
/*           DOUBLE PRECISION      TOL */
/*           DOUBLE PRECISION      DIFF */
/*           DOUBLE PRECISION      SUM1   ( MAXSUM ) */
/*           DOUBLE PRECISION      SUM2   ( MAXSUM ) */

/*           INTEGER               FA1 */
/*           INTEGER               FA2 */
/*           INTEGER               I */
/*           INTEGER               IA1 */
/*           INTEGER               IA2 */
/*           INTEGER               IC1    ( MAXNI ) */
/*           INTEGER               IC2    ( MAXNI ) */
/*           INTEGER               HANDL1 */
/*           INTEGER               HANDL2 */
/*           INTEGER               LEN1 */
/*           INTEGER               LEN2 */
/*           INTEGER               ND1 */
/*           INTEGER               ND2 */
/*           INTEGER               NI1 */
/*           INTEGER               NI2 */
/*           INTEGER               PTR */

/*           LOGICAL               FOUND */


/*     C */
/*     C     Start out by obtaining the names of the DAFs to be */
/*     C     compared. */
/*     C */
/*           WRITE (*,*) 'Enter name of first DAF.' */
/*           READ  (*,FMT='(A)') DAF1 */

/*           WRITE (*,*) 'Enter name of second DAF.' */
/*           READ  (*,FMT='(A)') DAF2 */

/*           WRITE (*,*) 'Enter name of log file.' */
/*           READ  (*,FMT='(A)') LOG */

/*           WRITE (*,*) 'Enter tolerance for data comparison.' */
/*           READ  (*,FMT='(A)') TOLCH */

/*           CALL NPARSD ( TOLCH, TOL, PRSERR, PTR ) */

/*           DO WHILE ( PRSERR .NE. ' ' ) */

/*              WRITE (*,*) PRSERR */
/*              WRITE (*,*) 'Enter tolerance for data comparison.' */
/*              READ  (*,FMT='(A)') TOLCH */

/*              CALL NPARSD ( TOLCH, TOL, PRSERR, PTR ) */

/*           END DO */

/*     C */
/*     C     Open both DAFs for reading. */
/*     C */
/*           CALL DAFOPR ( DAF1, HANDL1 ) */
/*           CALL DAFOPR ( DAF2, HANDL2 ) */

/*     C */
/*     C     Start forward searches in both DAFS. */
/*     C */
/*           CALL DAFBFS ( HANDL1 ) */
/*           CALL DAFBFS ( HANDL2 ) */

/*     C */
/*     C     Obtain the summary formats for each DAF. Stop now */
/*     C     if the summary formats don't match. */
/*     C */
/*           CALL DAFHSF ( HANDL1, ND1, NI1 ) */
/*           CALL DAFHSF ( HANDL2, ND2, NI2 ) */

/*           IF (  ( ND1 .NE. ND2 ) .OR. ( NI1 .NE. NI2 )  ) THEN */

/*              STR = 'Summary formats do not match.  NI1 = #, '// */
/*          .                      'NI2 = #, ND1 = #, ND2 = #.' */

/*              CALL REPMI  ( STR, '#', NI1, STR ) */
/*              CALL REPMI  ( STR, '#', NI2, STR ) */
/*              CALL REPMI  ( STR, '#', ND1, STR ) */
/*              CALL REPMI  ( STR, '#', ND2, STR ) */

/*              CALL WRLINE ( LOG,  STR ) */

/*              CALL SIGERR ( 'Incompatible DAFs' ) */

/*           END IF */

/*     C */
/*     C     Find the first array in each DAF. Use DAFCS */
/*     C     (DAF, continue search) to set the handle of the DAF */
/*     C     to search in before calling DAFFNA. */
/*     C */
/*           CALL DAFCS  ( HANDL1 ) */
/*           CALL DAFFNA ( FOUND  ) */

/*           IF ( FOUND ) THEN */
/*              CALL DAFCS  ( HANDL2 ) */
/*              CALL DAFFNA ( FOUND  ) */
/*           END IF */

/*           DO WHILE ( FOUND ) */

/*     C */
/*     C        Get the summary and name of each array, using */
/*     C        DAFCS to select the DAF to get the information */
/*     C        from. Unpack the summaries and find the beginning */
/*     C        and ending addresses of the arrays. Read the */
/*     C        arrays into the variables ARRAY1 and ARRAY2. */
/*     C */
/*              CALL DAFCS ( HANDL1 ) */
/*              CALL DAFGN ( ANAME1 ) */
/*              CALL DAFGS ( SUM1   ) */
/*              CALL DAFUS ( SUM1, ND1, NI1, DC1, IC1 ) */

/*              IA1  = IC1 ( NI1 - 1 ) */
/*              FA1  = IC1 ( NI1     ) */
/*              LEN1 = FA1 - IA1  + 1 */

/*              IF (  LEN1  .GT.  ARRYSZ  ) THEN */
/*                 CALL SETMSG ( 'Buffer too small; need # elts.') */
/*                 CALL ERRINT ( '#', LEN1                       ) */
/*                 CALL SIGERR ( 'ARRAYTOOSMALL'                 ) */
/*              ELSE */
/*                 CALL DAFGDA ( HANDL1, IA1, FA1, ARRAY1 ) */
/*              END IF */

/*              CALL DAFCS ( HANDL2 ) */
/*              CALL DAFGN ( ANAME2 ) */
/*              CALL DAFGS ( SUM2   ) */
/*              CALL DAFUS ( SUM2, ND2, NI2, DC2, IC2 ) */

/*              IA2 = IC2 ( NI2 - 1 ) */
/*              FA2 = IC2 ( NI2     ) */

/*              LEN2 = FA2 - IA2  + 1 */

/*              IF (  LEN2  .GT.  ARRYSZ  ) THEN */

/*                 CALL SETMSG ( 'Buffer too small; need # elts.') */
/*                 CALL ERRINT ( '#', LEN2                       ) */
/*                 CALL SIGERR ( 'ARRAYTOOSMALL'                 ) */

/*              ELSE IF ( LEN1 .NE. LEN2 ) THEN */

/*                 CALL SETMSG ( 'DAF structures do not match. '// */
/*          .                    'LEN1 = #, LEN2 = #. ' ) */
/*                 CALL ERRINT ( '#', LEN1              ) */
/*                 CALL ERRINT ( '#', LEN2              ) */
/*                 CALL SIGERR ( 'Incompatible DAFs' ) */

/*              ELSE */
/*                 CALL DAFGDA ( HANDL2, IA2, FA2, ARRAY2 ) */
/*              END IF */
/*     C */
/*     C */
/*     C        Compare the data in the two arrays. Log a message */
/*     C        for every instance of data that differs by more */
/*     C        than the allowed tolerance. Use the array names */
/*     C        to label the data sources. */
/*     C */
/*              DO I = 1, LEN1 */

/*                 DIFF  =  ABS( ARRAY1(I) - ARRAY2(I) ) */

/*                 IF (  DIFF  .GT.  TOL  ) THEN */
/*     C */
/*     C              Get the array names. */
/*     C */
/*                    CALL DAFCS ( HANDL1 ) */
/*                    CALL DAFGN ( ANAME1 ) */
/*                    CALL DAFCS ( HANDL2 ) */
/*                    CALL DAFGN ( ANAME2 ) */

/*     C */
/*     C              Construct the report strings. The number 14 */
/*     C              below is the number of significant digits to */
/*     C              show in the strings representing d.p. */
/*     C              numbers. */
/*     C */

/*                    CALL WRLINE ( LOG, ' ' ) */
/*                    CALL WRLINE ( LOG, 'Difference of array ' // */
/*          .                            'elements exceeded '   // */
/*          .                            'tolerance.'            ) */
/*                    CALL WRLINE ( LOG, 'First array:  '//ANAME1) */
/*                    CALL WRLINE ( LOG, 'Second array: '//ANAME2) */

/*                    STR = 'First value:  #' */
/*                    CALL REPMD  ( STR, '#', ARRAY1(I), 14, STR ) */
/*                    CALL WRLINE ( LOG, STR                     ) */

/*                    STR = 'Second value: #' */
/*                    CALL REPMD  ( STR, '#', ARRAY2(I), 14, STR ) */
/*                    CALL WRLINE ( LOG, STR                     ) */

/*                    STR = 'Difference:   #' */
/*                    CALL REPMD  ( STR, '#', DIFF,      14, STR ) */
/*                    CALL WRLINE ( LOG, STR                     ) */
/*                    CALL WRLINE ( LOG, ' '                     ) */

/*                 END IF */

/*              END DO */

/*     C */
/*     C        Find the next pair of arrays. */
/*     C */
/*              CALL DAFCS  ( HANDL1 ) */
/*              CALL DAFFNA ( FOUND  ) */

/*              IF ( FOUND ) THEN */
/*                 CALL DAFCS  ( HANDL2 ) */
/*                 CALL DAFFNA ( FOUND  ) */
/*              END IF */

/*           END DO */

/*     C */
/*     C     Close the DAFs. */
/*     C */
/*           CALL DAFCLS ( HANDL1 ) */
/*           CALL DAFCLS ( HANDL2 ) */

/*           END */


/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     W.L. Taber      (JPL) */
/*     I.M. Underwood  (JPL) */
/*     E.D. Wright     (JPL) */
/*     B.V. Semenov    (JPL) */

/* $ Version */

/* -    SPICELIB Version 3.1.1, 14-MAR-2017 (NJB) */

/*        Updated second header code example in this routine: fixed */
/*        error check for array overflow, corrected indentation of */
/*        continuation characters, added IMPLICIT NONE, deleted unused */
/*        declaration, increased buffer size, and changed DAFRDA call to */
/*        DAFGDA call. */

/*        Updated header example in entry point DAFGH: changed DAFRDA */
/*        call to DAFGDA call. */

/* -    SPICELIB Version 3.1.0, 10-FEB-2014 (EDW) (BVS) */

/*        Added a functional code example to the Examples section */
/*        in DAFBFS, DAFFNA, DAFGS. */

/*        Added check on value of "found" boolean returned from */
/*        DAFGSR calls. Failure to check this value can cause an */
/*        infinite loop during segment searches on damaged SPKs. */

/*        Eliminated unneeded Revisions section. */

/*        Removed the obsolete Reference citation to "NAIF */
/*        Document 167.0." */

/*        Added full declaration of HANDLE to the Declarations section */
/*        of the DAFCS header. */

/* -    SPICELIB Version 3.0.0, 16-NOV-2001 (FST) */

/*        This umbrella and its entry points were updated to */
/*        work properly with the changes in the DAF system as */
/*        a result of its utilization of the new handle manager. */
/*        Calls to DAFRDR were replaced with the translation-aware */
/*        interface DAFGSR for retrieving summary records from */
/*        DAFs. */

/*        Updated the entry points of DAFFA to enable its */
/*        internal state table size, TBSIZE, to be smaller */
/*        than the file table maintained by DAFAH: FTSIZE. */

/*        Since DAFAH now tracks FTSIZE files as defined in */
/*        the include file 'zzddhman.inc', it was decided that */
/*        in the interest of releasing the toolkit this module */
/*        would undergo simple changes. As such most previous */
/*        references to FTSIZE in this umbrella have been replaced */
/*        with TBSIZE where appropriate. DAFBFS and DAFBBS now signal */
/*        errors if there is not enough room to add a new DAF's */
/*        dossier to the state table. Also, after attempting to */
/*        clean up all files listed in the state table that are */
/*        not currently open, DAFBFS and DAFBBS attempt to locate */
/*        the first dossier with STADDG set to FALSE. This is then */
/*        freed to make room for the new DAF. If DAFBNA fails */
/*        to locate such a dossier in the state table, it */
/*        signals the error SPICE(STFULL). */

/*        The parameter FILEN was removed, as it is defined */
/*        on an environmental basis in the include file */
/*        'zzddhman.inc'. */

/* -    SPICELIB Version 2.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 2.0.0, 04-SEP-1991 (NJB) (WLT) */

/*        Updated to support simultaneous searches of multiple DAFs. */

/*        In previous versions of DAFFA, only one search could be */
/*        conducted at a time. Therefore, there was no question about */
/*        which DAF was being operated on by any of the DAFFA entry */
/*        points that don't accept file handles as input arguments. */
/*        In the current version of DAFFA, the entry points that don't */
/*        accept file handles as inputs operate on the `current DAF'. */
/*        The current DAF is the last one in which a search was */
/*        started by DAFBFS or DAFBBS, or continued by the new entry */
/*        point DAFCS. DAFCS was added to allow users to set the */
/*        current DAF, so that searches of multiple DAFs can be */
/*        interleaved. */

/*        Note that the notion of `current DAF' as discussed here applies */
/*        only to DAFs acted upon by entry points of DAFFA. In DAFANA, */
/*        there is a DAF that is treated as the `current DAF' for */
/*        adding data; there is no connection between the DAFs regarded */
/*        as current by DAFFA and DAFANA. */

/*        The two principal changes to DAFFA are the addition of the */
/*        new entry point DAFCS, and the addition of a data structure */
/*        called the `state table'. The state table is a collection of */
/*        parallel arrays that maintain information about the state */
/*        of each search that is currently in progress. The arrays are */
/*        indexed by a singly linked list pool; this mechanism allows */
/*        addition and deletion of information about searches without */
/*        requiring movement of data already in the state table. The */
/*        linked list pool contains an `active' list and a `free' list. */
/*        Nodes in the active list are used to index elements of the */
/*        state table where data about searches in progress is stored. */
/*        The head node of the active list is of particular significance: */
/*        the state information pointed to by this node is that of the */
/*        current DAF. Nodes in the free list index elements of the */
/*        state table that are available for use. */

/*        When a search is started on a DAF that is not already `known' */
/*        to DAFFA, information about the DAF is added to the state */
/*        table. If there are no free elements in the state table, */
/*        the routine starting the search (DAFBFS or DAFBBS) will */
/*        perform garbage collection:  the routine will test the handles */
/*        of each file about which information in stored in the state */
/*        table to see whether that file is still open. Nodes containing */
/*        information about DAFs that are no longer open will be moved */
/*        to the free list. */

/*        Whenever a DAF becomes the current DAF, the linked list */
/*        that indexes the state table is adjusted so that the */
/*        information about the current DAF is at the head of the list. */
/*        This way, a slight efficiency is gained when repeated search */
/*        accesses are made to the same DAF, since the linear search */
/*        through the state table for information on that DAF will */
/*        be shortened. */

/*        Since the algorithms for maintenance of linked lists are well */
/*        known, they are not documented here. However, see the */
/*        internals of the SPICELIB routine SPKBSR for a nice diagram */
/*        describing a similar data structure. */

/*        The state table contains two arrays that are quite large: */
/*        there are buffers that contain the last character record */
/*        and summary record read from each DAF. A parallel situation */
/*        exists in DAFANA, where the name and array summary for each */
/*        array under construction are buffered. The total storage */
/*        required for these arrays (in DAFANA and DAFFA together) is */
/*        4000 * TBSIZE bytes. For this reason, it may be a good idea */
/*        to reduce the value of TBSIZE in SPICELIB versions for */
/*        machines where memory is scarce. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     find DAF array */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     State variables. */

/*     These variables define the state of each DAF to which data */
/*     is currently being added. For each DAF that we're writing to, we */
/*     maintain a copy of: */

/*        STFH           File handle. */

/*        STPREV         Record number of previous array summary. */

/*        STTHIS         Record number of current array summary. */

/*        STNEXT         Record number of next array summary. */

/*        STNSEG         Number of summaries in current summary record. */

/*        STCURR         Index of current summary within summary record. */

/*        STNR           Last name record read. */

/*        STHVNR         Flag indicating whether name record containing */
/*                       name of current array is buffered. */

/*        STSR           Last summary record read. */

/*     These variables are maintained in a table of parallel arrays; */
/*     the size of the table is TBSIZE. */


/*     The table of state variables is indexed by a singly linked list */
/*     of pointers. This mechanism avoids the work of moving */
/*     the state variable data about as information about DAFs is */
/*     added to or deleted from the table. */

/*     The structure containing the linked list pointers is called a */
/*     `pool'. The pool contains a list of `active' nodes and a list */
/*     of free nodes. The head nodes of the active and free lists are */
/*     maintained as the variables STHEAD (`state table head') and */
/*     STFPTR (`state table free pointer'), respectively. Every node in */
/*     the pool is on exactly one of these lists. */


/*     The pool starts out with all of the nodes on the free list. The */
/*     first one of DAFBFS or DAFBBS to be called initializes the pool. */
/*     As new DAFs are searched, DAFBFS and DAFBBS add information about */
/*     them to the state table. Every time a search is started by DAFBFS */
/*     or DAFBBS, the routine in question `moves' the DAF's state */
/*     information to the head of the active list, if the state */
/*     information is not already there. This re-organization is */
/*     accomplished by deleting the node for the DAF from its current */
/*     position in the active list and inserting the node at the head of */
/*     the list. Thus, the change is made merely by setting pointers, */
/*     not by moving chunks of data in the state table. */

/*     It may happen that there is no room left in the state table */
/*     to accommodate information about a new DAF. In this case, */
/*     garbage collection must be performed:  whichever of DAFBFS or */
/*     DAFBBS needs more room frees all nodes in the table that index */
/*     DAFs that are not currently open. */

/*     Note that the routines DAFGS, DAFGN, DAFRS, DAFRN, and DAFWS do */
/*     not modify the state table; they merely act on the current array */
/*     in the DAF that is at the head of the active list. */


/*     Other local variables */


/*     Save everything between calls */


/*     Initial values */

    /* Parameter adjustments */
    if (sum) {
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_dafbfs;
	case 2: goto L_daffna;
	case 3: goto L_dafbbs;
	case 4: goto L_daffpa;
	case 5: goto L_dafgs;
	case 6: goto L_dafgn;
	case 7: goto L_dafgh;
	case 8: goto L_dafrs;
	case 9: goto L_dafrn;
	case 10: goto L_dafws;
	case 11: goto L_dafcs;
	}


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "DAFFA", (ftnlen)5);
	sigerr_(__global_state, "SPICE(BOGUSENTRY)", (ftnlen)17);
	chkout_(__global_state, "DAFFA", (ftnlen)5);
    }
    return 0;
/* $Procedure DAFBFS ( DAF, begin forward search ) */

L_dafbfs:
/* $ Abstract */

/*     Begin a forward search for arrays in a DAF. */

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

/*     DAF */

/* $ Keywords */

/*     FILES */

/* $ Declarations */

/*     INTEGER               HANDLE */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle of file to be searched. */

/* $ Detailed_Input */

/*     HANDLE      is the handle of a DAF on which a forward */
/*                 search is to be conducted. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the input handle is invalid, the error will be diagnosed */
/*         by routines called by this routine. */

/*     2)  If DAFBSR retuns with the read success flag as false, a */
/*         SPICE(RECORDNOTFOUND) error signals. */

/* $ Files */

/*     See argument HANDLE. */

/* $ Particulars */

/*     See DAFFA. */

/* $ Examples */

/*     Example (1): */

/*        See DAFFA. */

/*     Example (2): */

/*     Use a simple routine to output the double precision and integer */
/*     values stored in an SPK's segments descriptors. This function */
/*     opens a DAF for read, performs a forwards search for the DAF */
/*     arrays, prints segments description for each array found, then */
/*     closes the DAF. */

/*           PROGRAM DAF_T */

/*           INTEGER             HANDLE */

/*     C */
/*     C     Define the summary parameters appropriate */
/*     C     for an SPK file. */
/*     C */
/*           INTEGER             ND */
/*           PARAMETER         ( ND = 2 ) */

/*           INTEGER             NI */
/*           PARAMETER         ( NI = 6 ) */

/*           INTEGER             IC( NI ) */

/*           DOUBLE PRECISION    DC( ND ) */

/*           CHARACTER*(32)      KERNEL */

/*           LOGICAL             FOUND */


/*     C */
/*     C     Open a DAF for read. Return a HANDLE referring to the file. */
/*     C */
/*           KERNEL = 'de421.bsp' */
/*           CALL DAFOPR ( KERNEL, HANDLE ) */

/*     C */
/*     C     Begin a forward search on the file. */
/*     C */
/*           CALL DAFBFS ( HANDLE ) */

/*     C */
/*     C     Search until a DAF array is found. */
/*     C */
/*           CALL DAFFNA ( FOUND ) */

/*     C */
/*     C     Loop while the search finds subsequent DAF arrays. */
/*     C */
/*           DO WHILE ( FOUND ) */

/*              CALL DAFGS ( SUM ) */
/*              CALL DAFUS ( SUM, ND, NI, DC, IC ) */

/*              WRITE(*,*)                'Doubles: ', DC(1:ND) */
/*              WRITE(*, FMT='(A,6I9)' ) 'Integers: ', IC(1:NI) */

/*     C */
/*     C        Check for another segment. */
/*     C */
/*              CALL DAFFNA ( FOUND ) */

/*           END DO */

/*     C */
/*     C     Safely close the DAF. */
/*     C */
/*           CALL DAFCLS ( HANDLE ) */

/*           END */

/*     The program outputs: */

/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         1        0        1        2      641   310404 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         2        0        1        2   310405   423048 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         3        0        1        2   423049   567372 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         4        0        1        2   567373   628976 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         5        0        1        2   628977   674740 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         6        0        1        2   674741   715224 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         7        0        1        2   715225   750428 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         8        0        1        2   750429   785632 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         9        0        1        2   785633   820836 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:        10        0        1        2   820837   944040 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       301        3        1        2   944041  1521324 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       399        3        1        2  1521325  2098608 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       199        1        1        2  2098609  2098620 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       299        2        1        2  2098621  2098632 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       499        4        1        2  2098633  2098644 */

/*      Note, the final entries in the integer array contains the segment */
/*      start/end indexes. The output indicates the search proceeded */
/*      from the start of the file (low value index) towards the end */
/*      (high value index). */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     W.L. Taber      (JPL) */
/*     I.M. Underwood  (JPL) */
/*     E.D. Wright     (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.1.0, 10-OCT-2012 (EDW) */

/*        Added a functional code example to the Examples section. */

/*        Added check on value of "found" boolean returned from */
/*        DAFGSR calls. Failure to check this value can cause an */
/*        infinite loop during segment searches on damaged SPKs. */

/*        Eliminated unneeded Revisions section. */

/*        Removed the obsolete Reference citation to "NAIF */
/*        Document 167.0." */

/* -    SPICELIB Version 2.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 2.0.0, 04-SEP-1991 (NJB) (WLT) */

/*        Updated to support simultaneous searches of multiple DAFs. */

/*        This routine now operates on the current DAF---the one at */
/*        the head of the active list. All saved state variables */
/*        used by this routine are now part of the state table, or */
/*        its associated set of pointers. */

/*        Also, the $Exceptions section was filled out. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     begin DAF forward search */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "DAFBFS", (ftnlen)6);
    }

/*     Check out the file handle before going any further. */

    dafsih_(__global_state, handle, "READ", (ftnlen)4);
    if (failed_(__global_state)) {
	chkout_(__global_state, "DAFBFS", (ftnlen)6);
	return 0;
    }

/*     Initialize the state table pool, if this hasn't been done yet. */
/*     Also initialize the cell used to obtain the set of handles of */
/*     open DAFs. */

    if (__state->first) {
	ssizei_(__global_state, &__state->c__5000, __state->opnset);
	for (__state->i__ = 1; __state->i__ <= 4999; ++__state->i__) {
	    __state->stpool[(i__1 = __state->i__ - 1) < 5000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stpool", i__1, "daf"
		    "fa_", (ftnlen)1256)] = __state->i__ + 1;
	}
	__state->stpool[4999] = -1;
	__state->stfptr = 1;
	__state->first = FALSE_;
    }

/*     See whether we already have an entry for this DAF in the */
/*     state table. Find the previous node if possible. */

    __state->p = __state->sthead;
    __state->prev = -1;
    __state->fnd = FALSE_;
    while(__state->p != -1 && ! __state->fnd) {
	if (__state->stfh[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 :
		 s_rnge(&__global_state->f2c, "stfh", i__1, "daffa_", (ftnlen)
		1275)] == *handle) {
	    __state->fnd = TRUE_;
	} else {
	    __state->prev = __state->p;
	    __state->p = __state->stpool[(i__1 = __state->p - 1) < 5000 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stpool", 
		    i__1, "daffa_", (ftnlen)1279)];
	}
    }

/*     At this point, either FND is false, or P points to a */
/*     state table entry describing the DAF indicated by HANDLE. */
/*     In the latter case, PREV is the predecessor of P. */

    if (__state->fnd) {

/*        We already have a dossier on this DAF. We already have */
/*        the information on the summary format, but we must re-set */
/*        our summary record pointers and our name record availability */
/*        flag. */

/*        Rather than doing the update here, we do it outside of this */
/*        IF block. That way, the update gets done in just one place. */
/*        This just makes life easier:  if the collection of state */
/*        variables is changed, there are fewer places to forget to */
/*        make the required code changes. */

/*        Move the node for this DAF to the head of the active list, */
/*        if it is not already there: */

/*           - Make the predecessor of P point to the successor of P. */

/*           - Make P point to the head of the active list. */

/*           - Make P the active list head node. */


	if (__state->p != __state->sthead) {

/*           P is in the active list, but is not at the head. So, */
/*           the predecessor of P is not NIL. */

	    __state->stpool[(i__1 = __state->prev - 1) < 5000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stpool", i__1, "daf"
		    "fa_", (ftnlen)1317)] = __state->stpool[(i__2 = __state->p 
		    - 1) < 5000 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "stpool", i__2, "daffa_", (ftnlen)
		    1317)];
	    __state->stpool[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stpool", i__1, "daf"
		    "fa_", (ftnlen)1318)] = __state->sthead;
	    __state->sthead = __state->p;
	}
    } else {

/*        We don't yet have any information on this DAF. Make a new */
/*        state table entry for the DAF. We may need to make room for */
/*        the new information by freeing space allocated to DAFs that */
/*        are no longer open. */

	if (__state->stfptr == -1) {

/*           Oops, we're out of space. Time for garbage collection. */
/*           Test each file handle to see whether it designates a DAF */
/*           that is still open. DAFHOF will tell us which handles */
/*           point to open DAFs. */

	    dafhof_(__global_state, __state->opnset);
	    __state->p = __state->sthead;
	    __state->prev = -1;

/*           For every DAF file represented in the state table, we'll */
/*           delete the corresponding state information if the DAF is */
/*           now closed. We traverse the active list, examining each */
/*           file handle as we go. */

	    while(__state->p != -1) {
		if (elemi_(__global_state, &__state->stfh[(i__1 = __state->p 
			- 1) < 5000 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "stfh", i__1, "daffa_", (ftnlen)
			1350)], __state->opnset)) {

/*                 The file is open. Have a look at the next node. */

		    __state->prev = __state->p;
		    __state->p = __state->stpool[(i__1 = __state->p - 1) < 
			    5000 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "stpool", i__1, "daffa_", (
			    ftnlen)1355)];
		} else {

/*                 This file handle is not on the list, so free the */
/*                 node pointing to the information about the DAF it */
/*                 designated: */

/*                    - Save the successor of P. */

/*                    - Link the predecessor of node P to the successor */
/*                      of P, if the predecessor is not NIL. */

/*                    - If it happens that P is the head node of the */
/*                      active list, set the head equal to the */
/*                      successor of P. */

/*                    - Link P into the free list. */

/*                    - Set P equal to its saved successor. */

/*                    - (PREV remains unchanged.) */


		    __state->nextp = __state->stpool[(i__1 = __state->p - 1) <
			     5000 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "stpool", i__1, "daffa_", (
			    ftnlen)1379)];
		    if (__state->p == __state->sthead) {

/*                    Re-assign STHEAD so that we don't lose the head */
/*                    of the active list. P has no predecessor in this */
/*                    case, so there's no need to set the forward pointer */
/*                    of node PREV. */

			__state->sthead = __state->nextp;
		    } else {

/*                    Since P is not the head node of the active list, */
/*                    PREV is not NIL, so we'll need to set the forward */
/*                    pointer of node PREV. */

			__state->stpool[(i__1 = __state->prev - 1) < 5000 && 
				0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "stpool", i__1, "daffa_",
				 (ftnlen)1397)] = __state->nextp;
		    }
		    __state->stpool[(i__1 = __state->p - 1) < 5000 && 0 <= 
			    i__1 ? i__1 : s_rnge(&__global_state->f2c, "stpo"
			    "ol", i__1, "daffa_", (ftnlen)1401)] = 
			    __state->stfptr;
		    __state->stfptr = __state->p;
		    __state->p = __state->nextp;
		}
	    }

/*           At this point, we've freed all nodes from the active */
/*           list that were used to index information about DAFs that */
/*           are no longer open. If there's any more room in the state */
/*           table, we have it now. */

	}

/*        If there still is no room, there is a bug in DAFAH, since DAFAH */
/*        should not allow more than TBSIZE DAFs to be open. So, we */
/*        assume that we've found some room. The first free node is */
/*        indicated by STFPTR. We'll allocate this node and use it to */
/*        index the state information for the new DAF. */

	__state->p = __state->stfptr;

/*        Update the free list pointer, link P to the previous head */
/*        of the active list, and make P the head of the active list. */

	__state->stfptr = __state->stpool[(i__1 = __state->p - 1) < 5000 && 0 
		<= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stpool", i__1, 
		"daffa_", (ftnlen)1429)];
	__state->stpool[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "stpool", i__1, "daffa_", (
		ftnlen)1430)] = __state->sthead;
	__state->sthead = __state->p;
    }

/*     At this point, P is the head node of the active list, and P is */
/*     the index in the state table of the information for the current */
/*     DAF. */


/*     Read the file record and first summary record. Do not read the */
/*     corresponding name record until necessary. In most searches, */
/*     names are of no interest. */

    dafrfr_(__global_state, handle, &__state->nd, &__state->ni, 
	    __state->ifname, &__state->fward, &__state->bward, &__state->free,
	     (ftnlen)60);
    dafgsr_(__global_state, handle, &__state->fward, &__state->c__1, &
	    __state->c__128, &__state->stsr[(i__1 = (__state->p << 7) - 128) <
	     640000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stsr",
	     i__1, "daffa_", (ftnlen)1447)], &__state->fnd);
    if (! __state->fnd) {
	dafhfn_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)1451)], __state->dafnam, (ftnlen)255);
	setmsg_(__global_state, "Attempt to read descriptor record # of DAF "
		"'#' failed; record was not found. This condition may indicat"
		"e a corrupted DAF.", (ftnlen)121);
	errint_(__global_state, "#", &__state->stnext[(i__1 = __state->p - 1) 
		< 5000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"stnext", i__1, "daffa_", (ftnlen)1457)], (ftnlen)1);
	errch_(__global_state, "#", __state->dafnam, (ftnlen)1, (ftnlen)255);
	sigerr_(__global_state, "SPICE(RECORDNOTFOUND)", (ftnlen)21);
	chkout_(__global_state, "DAFBFS", (ftnlen)6);
	return 0;
    }

/*     Set up the state information for this file. Note that we */
/*     don't have a name record yet, and we have no current array */
/*     yet. */

    __state->stfh[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : s_rnge(
	    &__global_state->f2c, "stfh", i__1, "daffa_", (ftnlen)1470)] = *
	    handle;
    __state->stthis[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "stthis", i__1, "daffa_", (ftnlen)
	    1471)] = __state->fward;
    __state->stnext[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "stnext", i__1, "daffa_", (ftnlen)
	    1472)] = (integer) __state->stsr[(i__2 = (__state->p << 7) - 128) 
	    < 640000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "stsr"
	    , i__2, "daffa_", (ftnlen)1472)];
    __state->stprev[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "stprev", i__1, "daffa_", (ftnlen)
	    1473)] = (integer) __state->stsr[(i__2 = (__state->p << 7) - 127) 
	    < 640000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "stsr"
	    , i__2, "daffa_", (ftnlen)1473)];
    __state->stnseg[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "stnseg", i__1, "daffa_", (ftnlen)
	    1474)] = (integer) __state->stsr[(i__2 = (__state->p << 7) - 126) 
	    < 640000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "stsr"
	    , i__2, "daffa_", (ftnlen)1474)];
    __state->sthvnr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "sthvnr", i__1, "daffa_", (ftnlen)
	    1475)] = FALSE_;

/*     The arrays are returned in forward order within each summary */
/*     record. */

    __state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "stcurr", i__1, "daffa_", (ftnlen)
	    1481)] = 0;
    chkout_(__global_state, "DAFBFS", (ftnlen)6);
    return 0;
/* $Procedure DAFFNA ( DAF, find next array ) */

L_daffna:
/* $ Abstract */

/*     Find the next (forward) array in the current DAF. */

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

/*     DAF */

/* $ Keywords */

/*     FILES */

/* $ Declarations */

/*     LOGICAL               FOUND */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     FOUND      O   True if an array was found. */

/* $ Detailed_Input */

/*     None. */

/* $ Detailed_Output */

/*     FOUND       is true if an array was found, and is false if, */
/*                 when this routine is called, the current array is */
/*                 the tail of the array list. (Recall that the */
/*                 arrays in a DAF may be viewed as a doubly linked */
/*                 list, with the tail being the last array in the file.) */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If this routine is called before a search is begun, the */
/*         error SPICE(DAFNOSEARCH) is signaled. */

/*     2)  If the DAF to be searched has actually been closed, the error */
/*         will be diagnosed by routines called by this routine. */

/*     3)  If the end of the array list has already been reached when */
/*         this routine is called, this routine has no effect. */

/*     4)  If DAFBSR retuns with the read success flag as false, a */
/*         SPICE(RECORDNOTFOUND) error signals. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     See DAFFA. */

/* $ Examples */

/*     Example (1): */

/*        See DAFFA. */

/*     Example (2): */

/*     Use a simple routine to output the double precision and integer */
/*     values stored in an SPK's segments descriptors. This function */
/*     opens a DAF for read, performs a forwards search for the DAF */
/*     arrays, prints segments description for each array found, then */
/*     closes the DAF. */

/*           PROGRAM DAF_T */

/*           INTEGER             HANDLE */

/*     C */
/*     C     Define the summary parameters appropriate */
/*     C     for an SPK file. */
/*     C */
/*           INTEGER             ND */
/*           PARAMETER         ( ND = 2 ) */

/*           INTEGER             NI */
/*           PARAMETER         ( NI = 6 ) */

/*           INTEGER             IC( NI ) */

/*           DOUBLE PRECISION    DC( ND ) */

/*           CHARACTER*(32)      KERNEL */

/*           LOGICAL             FOUND */


/*     C */
/*     C     Open a DAF for read. Return a HANDLE referring to the file. */
/*     C */
/*           KERNEL = 'de421.bsp' */
/*           CALL DAFOPR ( KERNEL, HANDLE ) */

/*     C */
/*     C     Begin a forward search on the file. */
/*     C */
/*           CALL DAFBFS ( HANDLE ) */

/*     C */
/*     C     Search until a DAF array is found. */
/*     C */
/*           CALL DAFFNA ( FOUND ) */

/*     C */
/*     C     Loop while the search finds subsequent DAF arrays. */
/*     C */
/*           DO WHILE ( FOUND ) */

/*              CALL DAFGS ( SUM ) */
/*              CALL DAFUS ( SUM, ND, NI, DC, IC ) */

/*              WRITE(*,*)                'Doubles: ', DC(1:ND) */
/*              WRITE(*, FMT='(A,6I9)' ) 'Integers: ', IC(1:NI) */

/*     C */
/*     C        Check for another segment. */
/*     C */
/*              CALL DAFFNA ( FOUND ) */

/*           END DO */

/*     C */
/*     C     Safely close the DAF. */
/*     C */
/*           CALL DAFCLS ( HANDLE ) */

/*           END */

/*     The program outputs: */

/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         1        0        1        2      641   310404 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         2        0        1        2   310405   423048 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         3        0        1        2   423049   567372 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         4        0        1        2   567373   628976 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         5        0        1        2   628977   674740 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         6        0        1        2   674741   715224 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         7        0        1        2   715225   750428 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         8        0        1        2   750429   785632 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         9        0        1        2   785633   820836 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:        10        0        1        2   820837   944040 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       301        3        1        2   944041  1521324 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       399        3        1        2  1521325  2098608 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       199        1        1        2  2098609  2098620 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       299        2        1        2  2098621  2098632 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       499        4        1        2  2098633  2098644 */

/*      Note, the final entries in the integer array contains the segment */
/*      start/end indexes. The output indicates the search proceeded */
/*      from the start of the file (low value index) towards the end */
/*      (high value index). */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     W.L. Taber      (JPL) */
/*     I.M. Underwood  (JPL) */
/*     E.D. Wright     (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.1.0, 10-OCT-2012 (EDW) */

/*        Added a functional code example to the Examples section. */

/*        Added check on value of "found" boolean returned from */
/*        DAFGSR calls. Failure to check this value can cause an */
/*        infinite loop during segment searches on damaged SPKs. */

/*        Eliminated unneeded Revisions section. */

/*        Removed the obsolete Reference citation to "NAIF */
/*        Document 167.0." */

/* -    SPICELIB Version 2.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 2.0.0, 04-SEP-1991 (NJB) (WLT) */

/*        Updated to support simultaneous searches of multiple DAFs. */

/*        This routine now operates on the current DAF---the one at */
/*        the head of the active list. All saved state variables */
/*        used by this routine are now part of the state table, or */
/*        its associated set of pointers. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     find next DAF array */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "DAFFNA", (ftnlen)6);
    }

/*     FOUND will be false until we make it past the error checks. */

    *found = FALSE_;

/*     Operate on the last DAF in which a search has been started. */

    __state->p = __state->sthead;

/*     Make sure that a search has been started in this DAF. */

    if (__state->p == -1) {
	setmsg_(__global_state, "No DAF is currently being searched.", (
		ftnlen)35);
	sigerr_(__global_state, "SPICE(DAFNOSEARCH)", (ftnlen)18);
	chkout_(__global_state, "DAFFNA", (ftnlen)6);
	return 0;

/*     Make sure that the `current' DAF is still open. */

    } else {
	dafsih_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)1788)], "READ", (ftnlen)4);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "DAFFNA", (ftnlen)6);
	    return 0;
	}
    }

/*     Now that we know a search is going on, assume that we will find */
/*     an array until proven otherwise. */

    *found = TRUE_;

/*     Either there are more summaries left in this record, or */
/*     there aren't. If there are, just incrementing the pointer */
/*     is sufficient. If there aren't, we have to find the next */
/*     record and point to the first array there. (If that */
/*     record is empty, or doesn't exist, then there are simply */
/*     no more arrays to be found.) */

    __state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "stcurr", i__1, "daffa_", (ftnlen)
	    1814)] = __state->stcurr[(i__2 = __state->p - 1) < 5000 && 0 <= 
	    i__2 ? i__2 : s_rnge(&__global_state->f2c, "stcurr", i__2, "daff"
	    "a_", (ftnlen)1814)] + 1;
    if (__state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "stcurr", i__1, "daffa_", (ftnlen)
	    1816)] > __state->stnseg[(i__2 = __state->p - 1) < 5000 && 0 <= 
	    i__2 ? i__2 : s_rnge(&__global_state->f2c, "stnseg", i__2, "daff"
	    "a_", (ftnlen)1816)]) {
	if (__state->stnext[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "stnext", i__1, "daffa_", 
		(ftnlen)1818)] == 0) {

/*           There are no more arrays in the list. */

	    *found = FALSE_;

/*           Make sure that the array pointer stays pointing to */
/*           the position following the end of the list. Otherwise, */
/*           a call to DAFFPA might fail to find the last array in */
/*           the list. */

	    __state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stcurr", i__1, "daf"
		    "fa_", (ftnlen)1829)] = __state->stnseg[(i__2 = __state->p 
		    - 1) < 5000 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "stnseg", i__2, "daffa_", (ftnlen)
		    1829)] + 1;

/*           The careful reader may note that we're not updating any */
/*           of the pointers */

/*              STTHIS */
/*              STNEXT */
/*              STPREV */

/*           These will not be accessed if there is no current array. */
/*           If the array pointer is backed up again by a call to */
/*           DAFFPA, the values we have right now will be correct. */

	} else {
	    dafgsr_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 
		    5000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "stfh", i__1, "daffa_", (ftnlen)1844)], &__state->stnext[(
		    i__2 = __state->p - 1) < 5000 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "stnext", i__2, "daffa_", (
		    ftnlen)1844)], &__state->c__1, &__state->c__128, &
		    __state->stsr[(i__3 = (__state->p << 7) - 128) < 640000 &&
		     0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, "stsr", 
		    i__3, "daffa_", (ftnlen)1844)], &__state->fnd);
	    if (! __state->fnd) {
		dafhfn_(__global_state, &__state->stfh[(i__1 = __state->p - 1)
			 < 5000 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "stfh", i__1, "daffa_", (ftnlen)
			1848)], __state->dafnam, (ftnlen)255);
		setmsg_(__global_state, "Attempt to read descriptor record #"
			" of DAF '#' failed; record was not found. This condi"
			"tion may indicate a corrupted DAF.", (ftnlen)121);
		errint_(__global_state, "#", &__state->stnext[(i__1 = 
			__state->p - 1) < 5000 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "stnext", i__1, "daffa_", (
			ftnlen)1854)], (ftnlen)1);
		errch_(__global_state, "#", __state->dafnam, (ftnlen)1, (
			ftnlen)255);
		sigerr_(__global_state, "SPICE(RECORDNOTFOUND)", (ftnlen)21);
		chkout_(__global_state, "DAFFNA", (ftnlen)6);
		return 0;
	    }

/*           The name (character) record we've saved no longer applies */
/*           to the current summary record. However, we've just updated */
/*           the summary record, so the summary record remains valid. */

	    __state->sthvnr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "sthvnr", i__1, "daf"
		    "fa_", (ftnlen)1867)] = FALSE_;
	    __state->stthis[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stthis", i__1, "daf"
		    "fa_", (ftnlen)1869)] = __state->stnext[(i__2 = __state->p 
		    - 1) < 5000 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "stnext", i__2, "daffa_", (ftnlen)
		    1869)];
	    __state->stnext[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stnext", i__1, "daf"
		    "fa_", (ftnlen)1870)] = (integer) __state->stsr[(i__2 = (
		    __state->p << 7) - 128) < 640000 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "stsr", i__2, "daffa_", (
		    ftnlen)1870)];
	    __state->stprev[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stprev", i__1, "daf"
		    "fa_", (ftnlen)1871)] = (integer) __state->stsr[(i__2 = (
		    __state->p << 7) - 127) < 640000 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "stsr", i__2, "daffa_", (
		    ftnlen)1871)];
	    __state->stnseg[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stnseg", i__1, "daf"
		    "fa_", (ftnlen)1872)] = (integer) __state->stsr[(i__2 = (
		    __state->p << 7) - 126) < 640000 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "stsr", i__2, "daffa_", (
		    ftnlen)1872)];
	    __state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stcurr", i__1, "daf"
		    "fa_", (ftnlen)1873)] = 1;
	    *found = __state->stnseg[(i__1 = __state->p - 1) < 5000 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "stnseg", i__1,
		     "daffa_", (ftnlen)1875)] > 0;
	}
    }
    chkout_(__global_state, "DAFFNA", (ftnlen)6);
    return 0;
/* $Procedure DAFBBS ( DAF, begin backward search ) */

L_dafbbs:
/* $ Abstract */

/*     Begin a backward search for arrays in a DAF. */

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

/*     DAF */

/* $ Keywords */

/*     FILES */

/* $ Declarations */

/*     INTEGER               HANDLE */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle of DAF to be searched. */

/* $ Detailed_Input */

/*     HANDLE      is the handle of a DAF on which a backward */
/*                 search is to be conducted. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the input handle is invalid, the error will be diagnosed */
/*         by routines called by this routine. */

/*     2)  If DAFBSR retuns with the read success flag as false, a */
/*         SPICE(RECORDNOTFOUND) error signals. */

/* $ Files */

/*     See argument HANDLE. */

/* $ Particulars */

/*     See DAFFA. */

/* $ Examples */

/*     Example (1): */

/*        See DAFFA. */

/*     Example (2): */

/*     Use a simple routine to output the double precision and integer */
/*     values stored in an SPK's segments descriptors. This function */
/*     opens a DAF for read, performs a backward search for the DAF */
/*     arrays, prints segments description for each array found, then */
/*     closes the DAF. */

/*           PROGRAM DAFB_T */

/*           INTEGER             HANDLE */

/*     C */
/*     C     Define the summary parameters appropriate */
/*     C     for an SPK file. */
/*     C */
/*           INTEGER             ND */
/*           PARAMETER         ( ND = 2 ) */

/*           INTEGER             NI */
/*           PARAMETER         ( NI = 6 ) */

/*           INTEGER             IC( NI ) */

/*           DOUBLE PRECISION    DC( ND ) */

/*           CHARACTER*(32)      KERNEL */

/*           LOGICAL             FOUND */


/*     C */
/*     C     Open a DAF for read. Return a HANDLE referring to the file. */
/*     C */
/*           KERNEL = 'de421.bsp' */
/*           CALL DAFOPR ( KERNEL, HANDLE ) */

/*     C */
/*     C     Begin a backward search on the file. */
/*     C */
/*           CALL DAFBBS ( HANDLE ) */

/*     C */
/*     C     Search until a DAF array is found. */
/*     C */
/*           CALL DAFFPA ( FOUND ) */

/*     C */
/*     C     Loop while the search finds subsequent DAF arrays. */
/*     C */
/*           DO WHILE ( FOUND ) */

/*              CALL DAFGS ( SUM ) */
/*              CALL DAFUS ( SUM, ND, NI, DC, IC ) */

/*              WRITE(*,*)                'Doubles: ', DC(1:ND) */
/*              WRITE(*, FMT='(A,6I9)' ) 'Integers: ', IC(1:NI) */

/*     C */
/*     C        Check for another segment. */
/*     C */
/*              CALL DAFFPA ( FOUND ) */

/*           END DO */

/*     C */
/*     C     Safely close the DAF. */
/*     C */
/*           CALL DAFCLS ( HANDLE ) */

/*           END */

/*     The program outputs: */

/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       499        4        1        2  2098633  2098644 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       299        2        1        2  2098621  2098632 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       199        1        1        2  2098609  2098620 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       399        3        1        2  1521325  2098608 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       301        3        1        2   944041  1521324 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:        10        0        1        2   820837   944040 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         9        0        1        2   785633   820836 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         8        0        1        2   750429   785632 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         7        0        1        2   715225   750428 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         6        0        1        2   674741   715224 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         5        0        1        2   628977   674740 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         4        0        1        2   567373   628976 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         3        0        1        2   423049   567372 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         2        0        1        2   310405   423048 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         1        0        1        2      641   310404 */

/*      Note, the final entries in the integer arrays record the segment */
/*      start/end indexes. The output indicates the search proceeded */
/*      from the end of the file (high value index) towards the beginning */
/*      (low value index). */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     W.L. Taber      (JPL) */
/*     I.M. Underwood  (JPL) */
/*     E.D. Wright     (JPL) */

/* $ Version */

/* -    SPICELIB Version 3.1.0, 10-OCT-2012 (EDW) */

/*        Added a functional code example to the Examples section. */

/*        Added check on value of "found" boolean returned from */
/*        DAFGSR calls. Failure to check this value can cause an */
/*        infinite loop during segment searches on damaged SPKs. */

/*        Eliminated unneeded Revisions section. */

/*        Removed the obsolete Reference citation to "NAIF */
/*        Document 167.0." */

/* -    SPICELIB Version 2.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 2.0.0, 04-SEP-1991 (NJB) (WLT) */

/*        Updated to support simultaneous searches of multiple DAFs. */

/*        This routine now makes the DAF designated by HANDLE the */
/*        current DAF---the one at the head of the active list. All */
/*        saved state variables used by this routine are now part of the */
/*        state table, or its associated set of pointers. */

/*        Also, the $Exceptions section was filled out. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     begin DAF backward search */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "DAFBBS", (ftnlen)6);
    }

/*     Check out the file handle before going any further. */

    dafsih_(__global_state, handle, "READ", (ftnlen)4);
    if (failed_(__global_state)) {
	chkout_(__global_state, "DAFBBS", (ftnlen)6);
	return 0;
    }

/*     Initialize the state table pool, if this hasn't been done yet. */
/*     Also initialize the cell used to obtain the set of handles of */
/*     open DAFs. */

    if (__state->first) {
	ssizei_(__global_state, &__state->c__5000, __state->opnset);
	for (__state->i__ = 1; __state->i__ <= 4999; ++__state->i__) {
	    __state->stpool[(i__1 = __state->i__ - 1) < 5000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stpool", i__1, "daf"
		    "fa_", (ftnlen)2172)] = __state->i__ + 1;
	}
	__state->stpool[4999] = -1;
	__state->stfptr = 1;
	__state->first = FALSE_;
    }

/*     See whether we already have an entry for this DAF in the */
/*     state table. Find the previous node if possible. */

    __state->p = __state->sthead;
    __state->prev = -1;
    __state->fnd = FALSE_;
    while(__state->p != -1 && ! __state->fnd) {
	if (__state->stfh[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 :
		 s_rnge(&__global_state->f2c, "stfh", i__1, "daffa_", (ftnlen)
		2191)] == *handle) {
	    __state->fnd = TRUE_;
	} else {
	    __state->prev = __state->p;
	    __state->p = __state->stpool[(i__1 = __state->p - 1) < 5000 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stpool", 
		    i__1, "daffa_", (ftnlen)2195)];
	}
    }

/*     At this point, either FND is false, or P points to a */
/*     state table entry describing the DAF indicated by HANDLE. */
/*     In the latter case, PREV is the predecessor of P. */

    if (__state->fnd) {

/*        We already have a dossier on this DAF. We already have */
/*        the information on the summary format, but we must re-set */
/*        our summary record pointers and our name record availability */
/*        flag. */

/*        Rather than doing the update here, we do it outside of this */
/*        IF block. That way, the update gets done in just one place. */
/*        This just makes life easier:  if the collection of state */
/*        variables is changed, there are fewer places to forget to */
/*        make the required code changes. */

/*        Move the node for this DAF to the head of the active list, */
/*        if it is not already there: */

/*           - Make the predecessor of P point to the successor of P. */

/*           - Make P point to the head of the active list. */

/*           - Make P the active list head node. */


	if (__state->p != __state->sthead) {

/*           P is in the active list, but is not at the head. So, */
/*           the predecessor of P is not NIL. */

	    __state->stpool[(i__1 = __state->prev - 1) < 5000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stpool", i__1, "daf"
		    "fa_", (ftnlen)2233)] = __state->stpool[(i__2 = __state->p 
		    - 1) < 5000 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "stpool", i__2, "daffa_", (ftnlen)
		    2233)];
	    __state->stpool[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stpool", i__1, "daf"
		    "fa_", (ftnlen)2234)] = __state->sthead;
	    __state->sthead = __state->p;
	}
    } else {

/*        We don't yet have any information on this DAF. Make a new */
/*        state table entry for the DAF. We may need to make room for */
/*        the new information by freeing space allocated to DAFs that */
/*        are no longer open. */

	if (__state->stfptr == -1) {

/*           Oops, we're out of space. Time for garbage collection. */
/*           Test each file handle to see whether it designates a DAF */
/*           that is still open. DAFHOF will tell us which handles */
/*           point to open DAFs. */

	    dafhof_(__global_state, __state->opnset);
	    __state->p = __state->sthead;
	    __state->prev = -1;

/*           For every DAF file represented in the state table, we'll */
/*           delete the corresponding state information if the DAF is */
/*           now closed. We traverse the active list, examining each */
/*           file handle as we go. */

	    while(__state->p != -1) {
		if (elemi_(__global_state, &__state->stfh[(i__1 = __state->p 
			- 1) < 5000 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "stfh", i__1, "daffa_", (ftnlen)
			2266)], __state->opnset)) {

/*                 The file is open. Have a look at the next node. */

		    __state->prev = __state->p;
		    __state->p = __state->stpool[(i__1 = __state->p - 1) < 
			    5000 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "stpool", i__1, "daffa_", (
			    ftnlen)2271)];
		} else {

/*                 This file handle is not on the list, so free the */
/*                 node pointing to the information about the DAF it */
/*                 designated: */

/*                    - Save the successor of P. */

/*                    - Link the predecessor of node P to the successor */
/*                      of P, if the predecessor is not NIL. */

/*                    - If it happens that P is the head node of the */
/*                      active list, set the head equal to the */
/*                      successor of P. */

/*                    - Link P into the free list. */

/*                    - Set P equal to its saved successor. */

/*                    - (PREV remains unchanged.) */


		    __state->nextp = __state->stpool[(i__1 = __state->p - 1) <
			     5000 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "stpool", i__1, "daffa_", (
			    ftnlen)2295)];
		    if (__state->p == __state->sthead) {

/*                    Re-assign STHEAD so that we don't lose the head */
/*                    of the active list. P has no predecessor in this */
/*                    case, so there's no need to set the forward pointer */
/*                    of node PREV. */

			__state->sthead = __state->nextp;
		    } else {

/*                    Since P is not the head node of the active list, */
/*                    PREV is not NIL, so we'll need to set the forward */
/*                    pointer of node PREV. */

			__state->stpool[(i__1 = __state->prev - 1) < 5000 && 
				0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "stpool", i__1, "daffa_",
				 (ftnlen)2313)] = __state->nextp;
		    }
		    __state->stpool[(i__1 = __state->p - 1) < 5000 && 0 <= 
			    i__1 ? i__1 : s_rnge(&__global_state->f2c, "stpo"
			    "ol", i__1, "daffa_", (ftnlen)2318)] = 
			    __state->stfptr;
		    __state->stfptr = __state->p;
		    __state->p = __state->nextp;
		}
	    }

/*           At this point, we've freed all nodes from the active */
/*           list that were used to index information about DAFs that */
/*           are no longer open. If there's any more room in the state */
/*           table, we have it now. */

	}

/*        If there still is no room, there is a bug in DAFAH, since DAFAH */
/*        should not allow more than TBSIZE DAFs to be open. So, we */
/*        assume that we've found some room. The first free node is */
/*        indicated by STFPTR. We'll allocate this node and use it to */
/*        index the state information for the new DAF. */

	__state->p = __state->stfptr;

/*        Update the free list pointer, link P to the previous head */
/*        of the active list, and make P the head of the active list. */

	__state->stfptr = __state->stpool[(i__1 = __state->p - 1) < 5000 && 0 
		<= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stpool", i__1, 
		"daffa_", (ftnlen)2345)];
	__state->stpool[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "stpool", i__1, "daffa_", (
		ftnlen)2346)] = __state->sthead;
	__state->sthead = __state->p;
    }

/*     At this point, P is the head node of the active list, and P is */
/*     the index in the state table of the information for the current */
/*     DAF. */


/*     Read the file record and last summary record. Do not read the */
/*     corresponding name record until necessary. In most searches, */
/*     names are of no interest. */

    dafrfr_(__global_state, handle, &__state->nd, &__state->ni, 
	    __state->ifname, &__state->fward, &__state->bward, &__state->free,
	     (ftnlen)60);
    dafgsr_(__global_state, handle, &__state->bward, &__state->c__1, &
	    __state->c__128, &__state->stsr[(i__1 = (__state->p << 7) - 128) <
	     640000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stsr",
	     i__1, "daffa_", (ftnlen)2363)], &__state->fnd);
    if (! __state->fnd) {
	dafhfn_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)2367)], __state->dafnam, (ftnlen)255);
	setmsg_(__global_state, "Attempt to read descriptor record # of DAF "
		"'#' failed; record was not found. This condition may indicat"
		"e a corrupted DAF.", (ftnlen)121);
	errint_(__global_state, "#", &__state->stnext[(i__1 = __state->p - 1) 
		< 5000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"stnext", i__1, "daffa_", (ftnlen)2373)], (ftnlen)1);
	errch_(__global_state, "#", __state->dafnam, (ftnlen)1, (ftnlen)255);
	sigerr_(__global_state, "SPICE(RECORDNOTFOUND)", (ftnlen)21);
	chkout_(__global_state, "DAFBBS", (ftnlen)6);
	return 0;
    }
    __state->stfh[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : s_rnge(
	    &__global_state->f2c, "stfh", i__1, "daffa_", (ftnlen)2381)] = *
	    handle;
    __state->stthis[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "stthis", i__1, "daffa_", (ftnlen)
	    2382)] = __state->bward;
    __state->stnext[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "stnext", i__1, "daffa_", (ftnlen)
	    2383)] = (integer) __state->stsr[(i__2 = (__state->p << 7) - 128) 
	    < 640000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "stsr"
	    , i__2, "daffa_", (ftnlen)2383)];
    __state->stprev[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "stprev", i__1, "daffa_", (ftnlen)
	    2384)] = (integer) __state->stsr[(i__2 = (__state->p << 7) - 127) 
	    < 640000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "stsr"
	    , i__2, "daffa_", (ftnlen)2384)];
    __state->stnseg[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "stnseg", i__1, "daffa_", (ftnlen)
	    2385)] = (integer) __state->stsr[(i__2 = (__state->p << 7) - 126) 
	    < 640000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "stsr"
	    , i__2, "daffa_", (ftnlen)2385)];
    __state->sthvnr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "sthvnr", i__1, "daffa_", (ftnlen)
	    2386)] = FALSE_;

/*     The arrays are returned in backward order from each summary */
/*     record. */

    __state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "stcurr", i__1, "daffa_", (ftnlen)
	    2392)] = __state->stnseg[(i__2 = __state->p - 1) < 5000 && 0 <= 
	    i__2 ? i__2 : s_rnge(&__global_state->f2c, "stnseg", i__2, "daff"
	    "a_", (ftnlen)2392)] + 1;
    chkout_(__global_state, "DAFBBS", (ftnlen)6);
    return 0;
/* $Procedure DAFFPA ( DAF, find previous array ) */

L_daffpa:
/* $ Abstract */

/*     Find the previous (backward) array in the current DAF. */

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

/*     DAF */

/* $ Keywords */

/*     FILES */

/* $ Declarations */

/*     LOGICAL               FOUND */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     FOUND      O   True if an array was found. */

/* $ Detailed_Input */

/*     None. */

/* $ Detailed_Output */

/*     FOUND       is true if an array was found, and is false if, */
/*                 when this routine is called, the current array is */
/*                 the head of the array list. (Recall that the */
/*                 arrays in a DAF may be viewed as a doubly linked */
/*                 list, with the head being the first array in the */
/*                 file.) */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If this routine is called before a search is begun, the */
/*        error SPICE(DAFNOSEARCH) is signaled. */

/*     2) If the DAF to be searched has actually been closed, the error */
/*        will be diagnosed by routines called by this routine. */

/*     3) If the beginning of the array list has already been reached */
/*        when this routine is called, this routine will not change the */
/*        current array. FOUND will be false on output. */

/*     4) If DAFBSR retuns with the read success flag as false, a */
/*        SPICE(RECORDNOTFOUND) error signals. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     See DAFFA. */

/* $ Examples */

/*     Example (1): */

/*        See DAFFA. */

/*     Example (2): */

/*     Use a simple routine to output the double precision and integer */
/*     values stored in an SPK's segments descriptors. This function */
/*     opens a DAF for read, performs a backward search for the DAF */
/*     arrays, prints segments description for each array found, then */
/*     closes the DAF. */

/*           PROGRAM DAFB_T */

/*           INTEGER             HANDLE */

/*     C */
/*     C     Define the summary parameters appropriate */
/*     C     for an SPK file. */
/*     C */
/*           INTEGER             ND */
/*           PARAMETER         ( ND = 2 ) */

/*           INTEGER             NI */
/*           PARAMETER         ( NI = 6 ) */

/*           INTEGER             IC( NI ) */

/*           DOUBLE PRECISION    DC( ND ) */

/*           CHARACTER*(32)      KERNEL */

/*           LOGICAL             FOUND */


/*     C */
/*     C     Open a DAF for read. Return a HANDLE referring to the file. */
/*     C */
/*           KERNEL = 'de421.bsp' */
/*           CALL DAFOPR ( KERNEL, HANDLE ) */

/*     C */
/*     C     Begin a backward search on the file. */
/*     C */
/*           CALL DAFBBS ( HANDLE ) */

/*     C */
/*     C     Search until a DAF array is found. */
/*     C */
/*           CALL DAFFPA ( FOUND ) */

/*     C */
/*     C     Loop while the search finds subsequent DAF arrays. */
/*     C */
/*           DO WHILE ( FOUND ) */

/*              CALL DAFGS ( SUM ) */
/*              CALL DAFUS ( SUM, ND, NI, DC, IC ) */

/*              WRITE(*,*)                'Doubles: ', DC(1:ND) */
/*              WRITE(*, FMT='(A,6I9)' ) 'Integers: ', IC(1:NI) */

/*     C */
/*     C        Check for another segment. */
/*     C */
/*              CALL DAFFPA ( FOUND ) */

/*           END DO */

/*     C */
/*     C     Safely close the DAF. */
/*     C */
/*           CALL DAFCLS ( HANDLE ) */

/*           END */

/*     The program outputs: */

/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       499        4        1        2  2098633  2098644 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       299        2        1        2  2098621  2098632 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       199        1        1        2  2098609  2098620 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       399        3        1        2  1521325  2098608 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       301        3        1        2   944041  1521324 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:        10        0        1        2   820837   944040 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         9        0        1        2   785633   820836 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         8        0        1        2   750429   785632 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         7        0        1        2   715225   750428 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         6        0        1        2   674741   715224 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         5        0        1        2   628977   674740 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         4        0        1        2   567373   628976 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         3        0        1        2   423049   567372 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         2        0        1        2   310405   423048 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         1        0        1        2      641   310404 */

/*      Note, the final entries in the integer arrays record the segment */
/*      start/end indexes. The output indicates the search proceeded */
/*      from the end of the file (high value index) towards the beginning */
/*      (low value index). */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     W.L. Taber      (JPL) */
/*     I.M. Underwood  (JPL) */
/*     E.D. Wright     (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.1.0, 10-OCT-2012 (EDW) */

/*        Added a functional code example to the Examples section. */

/*        Added check on value of "found" boolean returned from */
/*        DAFGSR calls. Failure to check this value can cause an */
/*        infinite loop during segment searches on damaged SPKs. */

/*        Eliminated unneeded Revisions section. */

/*        Removed the obsolete Reference citation to "NAIF */
/*        Document 167.0." */

/* -    SPICELIB Version 2.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 2.0.0, 04-SEP-1991 (NJB) (WLT) */

/*        Updated to support simultaneous searches of multiple DAFs. */

/*        This routine now operates on the current DAF---the one at */
/*        the head of the active list. All saved state variables */
/*        used by this routine are now part of the state table, or */
/*        its associated set of pointers. */

/*        Also, a bug fix was made to the array pointer adjustment */
/*        algorithm:  the pointer is no longer decremented if it */
/*        is already less than 1 and the array summary pointer */
/*        is already pointing to the first array summary. In */
/*        addition, a test made to detect this condition was fixed: */
/*        the test */

/*           CURR .EQ. 0 */

/*        was replaced by */

/*           STCURR(P) .LE. 0 */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     find previous DAF array */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "DAFFPA", (ftnlen)6);
    }

/*     Operate on the last DAF in which a search has been started. */

    __state->p = __state->sthead;

/*     FOUND will be false until we make it past the error checks. */

    *found = FALSE_;

/*     Make sure that a search has been started in this DAF. */

    if (__state->p == -1) {
	setmsg_(__global_state, "No DAF is currently being searched.", (
		ftnlen)35);
	sigerr_(__global_state, "SPICE(DAFNOSEARCH)", (ftnlen)18);
	chkout_(__global_state, "DAFFPA", (ftnlen)6);
	return 0;

/*     Make sure that the `current' DAF is still open. */

    } else {
	dafsih_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)2714)], "READ", (ftnlen)4);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "DAFFPA", (ftnlen)6);
	    return 0;
	}
    }

/*     Now that we know a search is going on, assume that we will find */
/*     an array until proven otherwise. */

    *found = TRUE_;

/*     Either there are more summaries left in this record, or */
/*     there aren't. If there are, just decrementing the pointer */
/*     is sufficient. If there aren't, we have to find the previous */
/*     record and point to the last array there. (If that */
/*     record is empty, or doesn't exist, then there are simply */
/*     no more arrays to be found.) */

    __state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "stcurr", i__1, "daffa_", (ftnlen)
	    2737)] = __state->stcurr[(i__2 = __state->p - 1) < 5000 && 0 <= 
	    i__2 ? i__2 : s_rnge(&__global_state->f2c, "stcurr", i__2, "daff"
	    "a_", (ftnlen)2737)] - 1;
    if (__state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "stcurr", i__1, "daffa_", (ftnlen)
	    2739)] <= 0) {
	if (__state->stprev[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "stprev", i__1, "daffa_", 
		(ftnlen)2741)] == 0) {

/*           There is no predecessor of the current array in the list. */

	    *found = FALSE_;

/*           Make sure that the array pointer stays pointing to */
/*           the position preceding the front of the list. Otherwise, */
/*           a call to DAFFNA might fail to find the first array in */
/*           the list. */

	    __state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stcurr", i__1, "daf"
		    "fa_", (ftnlen)2752)] = 0;

/*           The careful reader may note that we're not updating any */
/*           of the pointers */

/*              STTHIS */
/*              STNEXT */
/*              STPREV */

/*           These will not be accessed if there is no current array. */
/*           If the array pointer is moved forward again by a call to */
/*           DAFFNA, the values we have right now will be correct. */

	} else {
	    dafgsr_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 
		    5000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "stfh", i__1, "daffa_", (ftnlen)2767)], &__state->stprev[(
		    i__2 = __state->p - 1) < 5000 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "stprev", i__2, "daffa_", (
		    ftnlen)2767)], &__state->c__1, &__state->c__128, &
		    __state->stsr[(i__3 = (__state->p << 7) - 128) < 640000 &&
		     0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, "stsr", 
		    i__3, "daffa_", (ftnlen)2767)], &__state->fnd);
	    if (! __state->fnd) {
		dafhfn_(__global_state, &__state->stfh[(i__1 = __state->p - 1)
			 < 5000 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "stfh", i__1, "daffa_", (ftnlen)
			2771)], __state->dafnam, (ftnlen)255);
		setmsg_(__global_state, "Attempt to read descriptor record #"
			" of DAF '#' failed; record was not found. This condi"
			"tion may indicate a corrupted DAF.", (ftnlen)121);
		errint_(__global_state, "#", &__state->stnext[(i__1 = 
			__state->p - 1) < 5000 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "stnext", i__1, "daffa_", (
			ftnlen)2777)], (ftnlen)1);
		errch_(__global_state, "#", __state->dafnam, (ftnlen)1, (
			ftnlen)255);
		sigerr_(__global_state, "SPICE(RECORDNOTFOUND)", (ftnlen)21);
		chkout_(__global_state, "DAFFPA", (ftnlen)6);
		return 0;
	    }

/*           The name (character) record we've saved no longer applies */
/*           to the current summary record. However, we've just updated */
/*           the summary record, so the summary record remains valid. */

	    __state->sthvnr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "sthvnr", i__1, "daf"
		    "fa_", (ftnlen)2790)] = FALSE_;
	    __state->stthis[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stthis", i__1, "daf"
		    "fa_", (ftnlen)2792)] = __state->stprev[(i__2 = __state->p 
		    - 1) < 5000 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "stprev", i__2, "daffa_", (ftnlen)
		    2792)];
	    __state->stnext[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stnext", i__1, "daf"
		    "fa_", (ftnlen)2793)] = (integer) __state->stsr[(i__2 = (
		    __state->p << 7) - 128) < 640000 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "stsr", i__2, "daffa_", (
		    ftnlen)2793)];
	    __state->stprev[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stprev", i__1, "daf"
		    "fa_", (ftnlen)2794)] = (integer) __state->stsr[(i__2 = (
		    __state->p << 7) - 127) < 640000 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "stsr", i__2, "daffa_", (
		    ftnlen)2794)];
	    __state->stnseg[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stnseg", i__1, "daf"
		    "fa_", (ftnlen)2795)] = (integer) __state->stsr[(i__2 = (
		    __state->p << 7) - 126) < 640000 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "stsr", i__2, "daffa_", (
		    ftnlen)2795)];
	    __state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "stcurr", i__1, "daf"
		    "fa_", (ftnlen)2796)] = __state->stnseg[(i__2 = __state->p 
		    - 1) < 5000 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "stnseg", i__2, "daffa_", (ftnlen)
		    2796)];
	    *found = __state->stnseg[(i__1 = __state->p - 1) < 5000 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "stnseg", i__1,
		     "daffa_", (ftnlen)2798)] > 0;
	}
    }
    chkout_(__global_state, "DAFFPA", (ftnlen)6);
    return 0;
/* $Procedure DAFGS ( DAF, get summary ) */

L_dafgs:
/* $ Abstract */

/*     Return (get) the summary for the current array in the current */
/*     DAF. */

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

/*     DAF */

/* $ Keywords */

/*     FILES */

/* $ Declarations */

/*     DOUBLE PRECISION      SUM    ( * ) */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     SUM        O   Summary for current array. */

/* $ Detailed_Input */

/*     None. */

/* $ Detailed_Output */

/*     SUM         is the summary for the current array (the array */
/*                 found by the latest call to DAFFNA or DAFFPA). */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If this routine is called when no search is in progress in the */
/*         the current DAF, the error SPICE(DAFNOSEARCH) is signaled. */

/*     2)  If the DAF for which the `current' array's summary is to be */
/*         returned has actually been closed, the error will be diagnosed */
/*         by routines called by this routine. */

/*     3)  If no array is current in the current DAF, the error */
/*         SPICE(NOCURRENTARRAY) is signaled. There is no current */
/*         array when a search is started by DAFBFS or DAFBBS, but no */
/*         calls to DAFFNA or DAFBNA have been made yet, or whenever */
/*         DAFFNA or DAFFPA return the value .FALSE. in the FOUND */
/*         argument. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     See DAFFA. */

/* $ Examples */

/*     Example (1): */

/*        See DAFFA. */

/*     Example (2): */

/*     Use a simple routine to output the double precision and integer */
/*     values stored in an SPK's segments descriptors. This function */
/*     opens a DAF for read, performs a forwards search for the DAF */
/*     arrays, prints segments description for each array found, then */
/*     closes the DAF. */

/*           PROGRAM DAF_T */

/*           INTEGER             HANDLE */

/*     C */
/*     C     Define the summary parameters appropriate */
/*     C     for an SPK file. */
/*     C */
/*           INTEGER             ND */
/*           PARAMETER         ( ND = 2 ) */

/*           INTEGER             NI */
/*           PARAMETER         ( NI = 6 ) */

/*           INTEGER             IC( NI ) */

/*           DOUBLE PRECISION    DC( ND ) */

/*           CHARACTER*(32)      KERNEL */

/*           LOGICAL             FOUND */


/*     C */
/*     C     Open a DAF for read. Return a HANDLE referring to the file. */
/*     C */
/*           KERNEL = 'de421.bsp' */
/*           CALL DAFOPR ( KERNEL, HANDLE ) */

/*     C */
/*     C     Begin a forward search on the file. */
/*     C */
/*           CALL DAFBFS ( HANDLE ) */

/*     C */
/*     C     Search until a DAF array is found. */
/*     C */
/*           CALL DAFFNA ( FOUND ) */

/*     C */
/*     C     Loop while the search finds subsequent DAF arrays. */
/*     C */
/*           DO WHILE ( FOUND ) */

/*              CALL DAFGS ( SUM ) */
/*              CALL DAFUS ( SUM, ND, NI, DC, IC ) */

/*              WRITE(*,*)                'Doubles: ', DC(1:ND) */
/*              WRITE(*, FMT='(A,6I9)' ) 'Integers: ', IC(1:NI) */

/*     C */
/*     C        Check for another segment. */
/*     C */
/*              CALL DAFFNA ( FOUND ) */

/*           END DO */

/*     C */
/*     C     Safely close the DAF. */
/*     C */
/*           CALL DAFCLS ( HANDLE ) */

/*           END */

/*     The program outputs: */

/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         1        0        1        2      641   310404 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         2        0        1        2   310405   423048 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         3        0        1        2   423049   567372 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         4        0        1        2   567373   628976 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         5        0        1        2   628977   674740 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         6        0        1        2   674741   715224 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         7        0        1        2   715225   750428 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         8        0        1        2   750429   785632 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:         9        0        1        2   785633   820836 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:        10        0        1        2   820837   944040 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       301        3        1        2   944041  1521324 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       399        3        1        2  1521325  2098608 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       199        1        1        2  2098609  2098620 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       299        2        1        2  2098621  2098632 */
/*      Doubles:   -3169195200.0000000        1696852800.0000000 */
/*     Integers:       499        4        1        2  2098633  2098644 */

/*      Note, the final entries in the integer array contains the segment */
/*      start/end indexes. The output indicates the search proceeded */
/*      from the start of the file (low value index) towards the end */
/*      (high value index). */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     W.L. Taber      (JPL) */
/*     I.M. Underwood  (JPL) */
/*     E.D. Wright     (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.2, 10-OCT-2012 (EDW) */

/*        Added a functional code example to the Examples section. */

/*        Eliminated unneeded Revisions section. */

/*        Removed the obsolete Reference citation to "NAIF */
/*        Document 167.0." */

/* -    SPICELIB Version 2.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 2.0.0, 04-SEP-1991 (NJB) (WLT) */

/*        Updated to support simultaneous searches of multiple DAFs. */
/*        Bug fix made to handle case of having no current array. */

/*        This routine now operates on the current DAF---the one at */
/*        the head of the active list. All saved state variables */
/*        used by this routine are now part of the state table, or */
/*        its associated set of pointers. */

/*        In addition, this routine now checks whether an array */
/*        is current before trying to read its summary. The routine */
/*        previously crashed under these conditions. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     get DAF summary */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "DAFGS", (ftnlen)5);
    }

/*     Operate on the last DAF in which a search has been started. */

    __state->p = __state->sthead;

/*     Make sure that a search has been started in this DAF. */

    if (__state->p == -1) {
	setmsg_(__global_state, "No DAF is currently being searched.", (
		ftnlen)35);
	sigerr_(__global_state, "SPICE(DAFNOSEARCH)", (ftnlen)18);
	chkout_(__global_state, "DAFGS", (ftnlen)5);
	return 0;

/*     Make sure that the `current' DAF is still open. */

    } else {
	dafsih_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)3104)], "READ", (ftnlen)4);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "DAFGS", (ftnlen)5);
	    return 0;
	}
    }

/*     Check the current pointer position to make sure that it's in */
/*     bounds. If there is no current array, then we cannot return */
/*     a summary. This situation occurs if DAFFNA was called when the */
/*     current array was the last, or if DAFFPA was called when the */
/*     current array was the first. */

    if (__state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "stcurr", i__1, "daffa_", (ftnlen)
	    3120)] == 0) {
	dafhfn_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)3122)], __state->dafnam, (ftnlen)255);
	setmsg_(__global_state, "No array is current; the `next' array is th"
		"e first array of DAF #", (ftnlen)65);
	errch_(__global_state, "#", __state->dafnam, (ftnlen)1, (ftnlen)255);
	sigerr_(__global_state, "SPICE(NOCURRENTARRAY)", (ftnlen)21);
	chkout_(__global_state, "DAFGS", (ftnlen)5);
	return 0;
    } else if (__state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "stcurr", i__1, "daffa_", (
	    ftnlen)3131)] > __state->stnseg[(i__2 = __state->p - 1) < 5000 && 
	    0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "stnseg", i__2, 
	    "daffa_", (ftnlen)3131)]) {
	dafhfn_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)3133)], __state->dafnam, (ftnlen)255);
	setmsg_(__global_state, "No array is current; the `previous' array i"
		"s the last array of DAF #", (ftnlen)68);
	errch_(__global_state, "#", __state->dafnam, (ftnlen)1, (ftnlen)255);
	sigerr_(__global_state, "SPICE(NOCURRENTARRAY)", (ftnlen)21);
	chkout_(__global_state, "DAFGS", (ftnlen)5);
	return 0;
    }

/*     The location of the summary depends on the current pointer */
/*     position. */

    dafhsf_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 && 
	    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", i__1, 
	    "daffa_", (ftnlen)3148)], &__state->nd, &__state->ni);
    __state->sumsiz = __state->nd + (__state->ni + 1) / 2;
    __state->offset = (__state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= 
	    i__1 ? i__1 : s_rnge(&__global_state->f2c, "stcurr", i__1, "daff"
	    "a_", (ftnlen)3152)] - 1) * __state->sumsiz + 3;
    moved_(__global_state, &__state->stsr[(i__1 = __state->offset + 1 + (
	    __state->p << 7) - 129) < 640000 && 0 <= i__1 ? i__1 : s_rnge(&
	    __global_state->f2c, "stsr", i__1, "daffa_", (ftnlen)3154)], &
	    __state->sumsiz, sum);
    chkout_(__global_state, "DAFGS", (ftnlen)5);
    return 0;
/* $Procedure DAFGN ( DAF, get array name ) */

L_dafgn:
/* $ Abstract */

/*     Return (get) the name for the current array in the current DAF. */

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

/*     DAF */

/* $ Keywords */

/*     FILES */

/* $ Declarations */

/*     CHARACTER*(*)         NAME */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     NAME       O   Name of current array. */

/* $ Detailed_Input */

/*     None. */

/* $ Detailed_Output */

/*     NAME        is the name for the current array (the array */
/*                 found by the latest call to DAFFNA or DAFFPA). */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If this routine is called when no search is in progress in the */
/*         the current DAF, the error SPICE(DAFNOSEARCH) is signaled. */

/*     2)  If the DAF for which the `current' array's name is to be */
/*         returned has actually been closed, the error will be diagnosed */
/*         by routines called by this routine. */

/*     3)  If no array is current in the current DAF, the error */
/*         SPICE(NOCURRENTARRAY) is signaled. There is no current */
/*         array when a search is started by DAFBFS or DAFBBS, but no */
/*         calls to DAFFNA or DAFBNA have been made yet, or whenever */
/*         DAFFNA or DAFFPA return the value .FALSE. in the FOUND */
/*         argument. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     See DAFFA. */

/* $ Examples */

/*     See DAFFA. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     W.L. Taber      (JPL) */
/*     I.M. Underwood  (JPL) */
/*     E.D. Wright     (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.2, 18-AUG-2011 (EDW) */

/*        Eliminated unneeded Revisions section. */

/*        Removed the obsolete Reference citation to "NAIF */
/*        Document 167.0." */

/* -    SPICELIB Version 2.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 2.0.0, 04-SEP-1991 (NJB) (WLT) */

/*        Updated to support simultaneous searches of multiple DAFs. */
/*        Bug fix made to handle case of having no current array. */

/*        This routine now operates on the current DAF---the one at */
/*        the head of the active list. All saved state variables */
/*        used by this routine are now part of the state table, or */
/*        its associated set of pointers. */

/*        In addition, this routine now checks whether an array */
/*        is current before trying to read its summary. The routine */
/*        previously crashed under these conditions. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     get DAF array name */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "DAFGN", (ftnlen)5);
    }

/*     Operate on the last DAF in which a search has been started. */

    __state->p = __state->sthead;

/*     Make sure that a search has been started in this DAF. */

    if (__state->p == -1) {
	setmsg_(__global_state, "No DAF is currently being searched.", (
		ftnlen)35);
	sigerr_(__global_state, "SPICE(DAFNOSEARCH)", (ftnlen)18);
	chkout_(__global_state, "DAFGN", (ftnlen)5);
	return 0;

/*     Make sure that the `current' DAF is still open. */

    } else {
	dafsih_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)3342)], "READ", (ftnlen)4);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "DAFGN", (ftnlen)5);
	    return 0;
	}
    }

/*     Check the current pointer position to make sure that it's in */
/*     bounds. If there is no current array, then we cannot get the */
/*     array's summary's name. This situation occurs if DAFFNA was */
/*     called when the current array was the last, or if DAFFPA was */
/*     called when the current array was the first. */

    if (__state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "stcurr", i__1, "daffa_", (ftnlen)
	    3358)] == 0) {
	dafhfn_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)3360)], __state->dafnam, (ftnlen)255);
	setmsg_(__global_state, "No array is current; the `next' array is th"
		"e first array of DAF #", (ftnlen)65);
	errch_(__global_state, "#", __state->dafnam, (ftnlen)1, (ftnlen)255);
	sigerr_(__global_state, "SPICE(NOCURRENTARRAY)", (ftnlen)21);
	chkout_(__global_state, "DAFGN", (ftnlen)5);
	return 0;
    } else if (__state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "stcurr", i__1, "daffa_", (
	    ftnlen)3369)] > __state->stnseg[(i__2 = __state->p - 1) < 5000 && 
	    0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "stnseg", i__2, 
	    "daffa_", (ftnlen)3369)]) {
	dafhfn_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)3371)], __state->dafnam, (ftnlen)255);
	setmsg_(__global_state, "No array is current; the `previous' array i"
		"s the last array of DAF #", (ftnlen)68);
	errch_(__global_state, "#", __state->dafnam, (ftnlen)1, (ftnlen)255);
	sigerr_(__global_state, "SPICE(NOCURRENTARRAY)", (ftnlen)21);
	chkout_(__global_state, "DAFGN", (ftnlen)5);
	return 0;
    }

/*     Read the name record for this summary record, if we don't have it */
/*     already. */

    if (! __state->sthvnr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 :
	     s_rnge(&__global_state->f2c, "sthvnr", i__1, "daffa_", (ftnlen)
	    3387)]) {
	i__4 = __state->stthis[(i__2 = __state->p - 1) < 5000 && 0 <= i__2 ? 
		i__2 : s_rnge(&__global_state->f2c, "stthis", i__2, "daffa_", 
		(ftnlen)3389)] + 1;
	dafrcr_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)3389)], &i__4, __state->stnr + ((i__3 
		= __state->p - 1) < 5000 && 0 <= i__3 ? i__3 : s_rnge(&
		__global_state->f2c, "stnr", i__3, "daffa_", (ftnlen)3389)) * 
		1000, (ftnlen)1000);
	__state->sthvnr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "sthvnr", i__1, "daffa_", (
		ftnlen)3391)] = TRUE_;
    }

/*     The location of the name depends on the current pointer */
/*     position. */

    dafhsf_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 && 
	    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", i__1, 
	    "daffa_", (ftnlen)3400)], &__state->nd, &__state->ni);
    __state->sumsiz = __state->nd + (__state->ni + 1) / 2;
    __state->namsiz = __state->sumsiz << 3;
    __state->offset = (__state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= 
	    i__1 ? i__1 : s_rnge(&__global_state->f2c, "stcurr", i__1, "daff"
	    "a_", (ftnlen)3406)] - 1) * __state->namsiz;
    i__2 = __state->offset;
    s_copy(&__global_state->f2c, name__, __state->stnr + (((i__1 = __state->p 
	    - 1) < 5000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
	    "stnr", i__1, "daffa_", (ftnlen)3408)) * 1000 + i__2), name_len, 
	    __state->offset + __state->namsiz - i__2);
    chkout_(__global_state, "DAFGN", (ftnlen)5);
    return 0;
/* $Procedure DAFGH ( DAF, get handle ) */

L_dafgh:
/* $ Abstract */

/*     Return (get) the handle of the DAF currently being searched. */

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

/*     DAF */

/* $ Keywords */

/*     FILES */

/* $ Declarations */

/*     INTEGER               HANDLE */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     O   Handle for current DAF. */

/* $ Detailed_Input */

/*     None. */

/* $ Detailed_Output */

/*     HANDLE      is the handle for the current DAF (the handle */
/*                 connected to the DAF that is currently being */
/*                 searched). */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If this routine is called when no search is in progress in the */
/*         the current DAF, the error SPICE(DAFNOSEARCH) is signaled. */

/*     2)  If the DAF whose handle is to be returned has actually been */
/*         closed, the error will be diagnosed by routines called by */
/*         this routine. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     Under rare circumstances, it may be necessary to identify */
/*     the particular DAF that is being searched (such as when */
/*     the search is begun by one module and continued by another). */

/* $ Examples */

/*     Consider a program like the following, which examines the */
/*     individual arrays in a DAF and examines the contents of those */
/*     meeting certain criteria. */

/*        CALL DAFOPW ( FNAME, HANDLE ) */
/*        CALL DAFBFS ( HANDLE ) */
/*        CALL DAFFNA ( FOUND  ) */

/*        DO WHILE ( FOUND ) */
/*           CALL CHECK_DAF ( STATUS ) */

/*           IF ( STATUS .EQ. 'EXAMINE' ) THEN */
/*              CALL EXAMINE_DAF */
/*           END IF */

/*           CALL DAFFNA ( FOUND ) */
/*        END DO */

/*     The subroutine CHECK_DAF, which assumes that a search is in */
/*     progress, gets the summary and name for the current array, and */
/*     uses them to decide whether the data in the array merit further */
/*     consideration. */

/*        SUBROUTINE CHECK_DAF ( STATUS ) */

/*        CALL DAFGS ( SUM ) */
/*        CALL DAFGN ( NAME ) */
/*        CALL DAFUS ( SUM, ND, NI, DC, IC ) */
/*         . */
/*         . */

/*     The subroutine EXAMINE_DAF needs to examine the data in */
/*     the array itself. In order to do do, it needs to have access */
/*     not only to the summary, but to the handle of the file */
/*     containing the array. This is provided by DAFGH. */

/*        SUBROUTINE EXAMINE_DAF */

/*        CALL DAFGS ( SUM  ) */
/*        CALL DAFGH ( HANDLE ) */
/*        CALL DAFUS ( SUM, ND, NI, DC, IC ) */

/*        CALL DAFGDA ( HANDLE, BEGIN, END, DATA ) */
/*         . */
/*         . */


/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     W.L. Taber      (JPL) */
/*     I.M. Underwood  (JPL) */
/*     E.D. Wright     (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.3, 14-MAR-2017 (NJB) */

/*        Updated header example: changed DAFRDA call to DAFGDA call. */

/* -    SPICELIB Version 2.0.2, 18-AUG-2011 (EDW) */

/*        Eliminated unneeded Revisions section. */

/*        Removed the obsolete Reference citation to "NAIF */
/*        Document 167.0." */

/* -    SPICELIB Version 2.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 2.0.0, 04-SEP-1991 (NJB) (WLT) */

/*        Updated to support simultaneous searches of multiple DAFs. */

/*        This routine now operates on the current DAF---the one at */
/*        the head of the active list. All saved state variables */
/*        used by this routine are now part of the state table, or */
/*        its associated set of pointers. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     get DAF handle */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "DAFGH", (ftnlen)5);
    }

/*     Operate on the last DAF in which a search has been started. */

    __state->p = __state->sthead;

/*     Make sure that a search has been started in this DAF. */

    if (__state->p == -1) {
	setmsg_(__global_state, "No DAF is currently being searched.", (
		ftnlen)35);
	sigerr_(__global_state, "SPICE(DAFNOSEARCH)", (ftnlen)18);
	chkout_(__global_state, "DAFGH", (ftnlen)5);
	return 0;

/*     Make sure that the `current' DAF is still open. */

    } else {
	dafsih_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)3636)], "READ", (ftnlen)4);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "DAFGH", (ftnlen)5);
	    return 0;
	}
    }
    *handle = __state->stfh[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "stfh", i__1, "daffa_", (
	    ftnlen)3645)];
    chkout_(__global_state, "DAFGH", (ftnlen)5);
    return 0;
/* $Procedure DAFRS ( DAF, replace summary ) */

L_dafrs:
/* $ Abstract */

/*     Change the summary for the current array in the current DAF. */

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

/*     DAF */

/* $ Keywords */

/*     FILES */

/* $ Declarations */

/*     DOUBLE PRECISION      SUM */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     SUM        I   New summary for current array. */

/* $ Detailed_Input */

/*     SUM         is the new summary for the current array. This */
/*                 replaces the existing summary. However, the addresses */
/*                 (the final two integer components) of the original */
/*                 summary are not changed. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If this routine is called when no search is in progress in the */
/*         the current DAF, the error SPICE(DAFNOSEARCH) is signaled. */

/*     2)  If the DAF containing the `current' array has actually been */
/*         closed, the error will be diagnosed by routines called by */
/*         this routine. */

/*     3)  If the DAF containing the `current' array is not open for */
/*         writing, the error will be diagnosed by routines called by */
/*         this routine. */

/*     4)  If no array is current in the current DAF, the error */
/*         SPICE(NOCURRENTARRAY) is signaled. There is no current */
/*         array when a search is started by DAFBFS or DAFBBS, but no */
/*         calls to DAFFNA or DAFBNA have been made yet, or whenever */
/*         DAFFNA or DAFFPA return the value .FALSE. in the FOUND */
/*         argument. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     See DAFFA. */

/* $ Examples */

/*     See DAFFA. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     W.L. Taber      (JPL) */
/*     I.M. Underwood  (JPL) */
/*     E.D. Wright     (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.2, 18-AUG-2011 (EDW) */

/*        Eliminated unneeded Revisions section. */

/*        Removed the obsolete Reference citation to "NAIF */
/*        Document 167.0." */

/* -    SPICELIB Version 2.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 2.0.0, 04-SEP-1991 (NJB) (WLT) */

/*        Updated to support simultaneous searches of multiple DAFs. */
/*        Bug fix made to handle case of having no current array. */

/*        This routine now operates on the current DAF---the one at */
/*        the head of the active list. All saved state variables */
/*        used by this routine are now part of the state table, or */
/*        its associated set of pointers. */

/*        In addition, this routine now checks whether an array */
/*        is current before trying to read its summary. The routine */
/*        previously crashed under these conditions. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     replace DAF summary */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "DAFRS", (ftnlen)5);
    }

/*     Operate on the last DAF in which a search has been started. */

    __state->p = __state->sthead;

/*     Make sure that a search has been started in this DAF. */

    if (__state->p == -1) {
	setmsg_(__global_state, "No DAF is currently being searched.", (
		ftnlen)35);
	sigerr_(__global_state, "SPICE(DAFNOSEARCH)", (ftnlen)18);
	chkout_(__global_state, "DAFRS", (ftnlen)5);
	return 0;

/*     Make sure that the `current' DAF is still open, and that it */
/*     is open for writing. */

    } else {
	dafsih_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)3840)], "WRITE", (ftnlen)5);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "DAFRS", (ftnlen)5);
	    return 0;
	}
    }

/*     Check the current pointer position to make sure that it's in */
/*     bounds. If there is no current array, then we cannot replace the */
/*     array's  summary. This situation occurs if DAFFNA was called */
/*     when the current array was the last, or if DAFFPA was called when */
/*     the current array was the first. */

    if (__state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "stcurr", i__1, "daffa_", (ftnlen)
	    3856)] == 0) {
	dafhfn_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)3858)], __state->dafnam, (ftnlen)255);
	setmsg_(__global_state, "No array is current; the `next' array is th"
		"e first array of DAF #", (ftnlen)65);
	errch_(__global_state, "#", __state->dafnam, (ftnlen)1, (ftnlen)255);
	sigerr_(__global_state, "SPICE(NOCURRENTARRAY)", (ftnlen)21);
	chkout_(__global_state, "DAFRS", (ftnlen)5);
	return 0;
    } else if (__state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "stcurr", i__1, "daffa_", (
	    ftnlen)3867)] > __state->stnseg[(i__2 = __state->p - 1) < 5000 && 
	    0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "stnseg", i__2, 
	    "daffa_", (ftnlen)3867)]) {
	dafhfn_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)3869)], __state->dafnam, (ftnlen)255);
	setmsg_(__global_state, "No array is current; the `previous' array i"
		"s the last array of DAF #", (ftnlen)68);
	errch_(__global_state, "#", __state->dafnam, (ftnlen)1, (ftnlen)255);
	sigerr_(__global_state, "SPICE(NOCURRENTARRAY)", (ftnlen)21);
	chkout_(__global_state, "DAFRS", (ftnlen)5);
	return 0;
    }

/*     The location of the summary depends on the current pointer */
/*     position. */

    dafhsf_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 && 
	    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", i__1, 
	    "daffa_", (ftnlen)3884)], &__state->nd, &__state->ni);
    __state->sumsiz = __state->nd + (__state->ni + 1) / 2;
    __state->offset = (__state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= 
	    i__1 ? i__1 : s_rnge(&__global_state->f2c, "stcurr", i__1, "daff"
	    "a_", (ftnlen)3888)] - 1) * __state->sumsiz + 3;

/*     Get the existing summary, and unpack it. Replace everything */
/*     but the addresses (the final two integer components), and */
/*     repack. Then replace the existing summary within the record. */

    moved_(__global_state, &__state->stsr[(i__1 = __state->offset + 1 + (
	    __state->p << 7) - 129) < 640000 && 0 <= i__1 ? i__1 : s_rnge(&
	    __global_state->f2c, "stsr", i__1, "daffa_", (ftnlen)3895)], &
	    __state->sumsiz, __state->exsum);
    dafus_(__global_state, __state->exsum, &__state->nd, &__state->ni, 
	    __state->exdc, __state->exic);
    dafus_(__global_state, sum, &__state->nd, &__state->ni, __state->newdc, 
	    __state->newic);
    moved_(__global_state, __state->newdc, &__state->nd, __state->exdc);
    i__1 = __state->ni - 2;
    movei_(__global_state, __state->newic, &i__1, __state->exic);
    dafps_(__global_state, &__state->nd, &__state->ni, __state->exdc, 
	    __state->exic, __state->exsum);
    moved_(__global_state, __state->exsum, &__state->sumsiz, &__state->stsr[(
	    i__1 = __state->offset + 1 + (__state->p << 7) - 129) < 640000 && 
	    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stsr", i__1, 
	    "daffa_", (ftnlen)3904)]);

/*     Rewrite the modified summary record. */

    dafwdr_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 && 
	    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", i__1, 
	    "daffa_", (ftnlen)3909)], &__state->stthis[(i__2 = __state->p - 1)
	     < 5000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "stth"
	    "is", i__2, "daffa_", (ftnlen)3909)], &__state->stsr[(i__3 = (
	    __state->p << 7) - 128) < 640000 && 0 <= i__3 ? i__3 : s_rnge(&
	    __global_state->f2c, "stsr", i__3, "daffa_", (ftnlen)3909)]);
    chkout_(__global_state, "DAFRS", (ftnlen)5);
    return 0;
/* $Procedure DAFRN ( DAF, change array name ) */

L_dafrn:
/* $ Abstract */

/*     Replace the name for the current array in the current DAF. */

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

/*     DAF */

/* $ Keywords */

/*     FILES */

/* $ Declarations */

/*     CHARACTER*(*)         NAME */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     NAME       I   New name for current array. */

/* $ Detailed_Input */

/*     NAME        is the new name for the current array. */
/*                 This replaces the existing name. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If this routine is called when no search is in progress in the */
/*         the current DAF, the error SPICE(DAFNOSEARCH) is signaled. */

/*     2)  If the DAF containing the `current' array has actually been */
/*         closed, the error will be diagnosed by routines called by */
/*         this routine. */

/*     3)  If the DAF containing the `current' array is not open for */
/*         writing, the error will be diagnosed by routines called by */
/*         this routine. */

/*     4)  If no array is current in the current DAF, the error */
/*         SPICE(NOCURRENTARRAY) is signaled. There is no current */
/*         array when a search is started by DAFBFS or DAFBBS, but no */
/*         calls to DAFFNA or DAFBNA have been made yet, or whenever */
/*         DAFFNA or DAFFPA return the value .FALSE. in the FOUND */
/*         argument. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     See DAFFA. */

/* $ Examples */

/*     See DAFFA. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     W.L. Taber      (JPL) */
/*     I.M. Underwood  (JPL) */
/*     E.D. Wright     (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.2, 18-AUG-2011 (EDW) */

/*        Eliminated unneeded Revisions section. */

/*        Removed the obsolete Reference citation to "NAIF */
/*        Document 167.0." */

/* -    SPICELIB Version 2.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 2.0.0, 04-SEP-1991 (NJB) (WLT) */

/*        Updated to support simultaneous searches of multiple DAFs. */

/*        This routine now operates on the current DAF---the one at */
/*        the head of the active list. All saved state variables */
/*        used by this routine are now part of the state table, or */
/*        its associated set of pointers. */

/*        In addition, this routine now checks whether an array */
/*        is current before trying to read its summary. The routine */
/*        previously crashed under these conditions. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     change DAF array name */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "DAFRN", (ftnlen)5);
    }

/*     Operate on the last DAF in which a search has been started. */

    __state->p = __state->sthead;

/*     Make sure that a search has been started in this DAF. */

    if (__state->p == -1) {
	setmsg_(__global_state, "No DAF is currently being searched.", (
		ftnlen)35);
	sigerr_(__global_state, "SPICE(DAFNOSEARCH)", (ftnlen)18);
	chkout_(__global_state, "DAFRN", (ftnlen)5);
	return 0;

/*     Make sure that the `current' DAF is still open, and that it */
/*     is open for writing. */

    } else {
	dafsih_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)4100)], "WRITE", (ftnlen)5);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "DAFRN", (ftnlen)5);
	    return 0;
	}
    }

/*     Check the current pointer position to make sure that it's in */
/*     bounds. If there is no current array, then we cannot replace */
/*     the array's summary's name. This situation occurs if DAFFNA was */
/*     called when the current array was the last, or if DAFFPA was */
/*     called when the current array was the first. */

    if (__state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "stcurr", i__1, "daffa_", (ftnlen)
	    4116)] == 0) {
	dafhfn_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)4118)], __state->dafnam, (ftnlen)255);
	setmsg_(__global_state, "No array is current; the `next' array is th"
		"e first array of DAF #", (ftnlen)65);
	errch_(__global_state, "#", __state->dafnam, (ftnlen)1, (ftnlen)255);
	sigerr_(__global_state, "SPICE(NOCURRENTARRAY)", (ftnlen)21);
	chkout_(__global_state, "DAFRN", (ftnlen)5);
	return 0;
    } else if (__state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "stcurr", i__1, "daffa_", (
	    ftnlen)4127)] > __state->stnseg[(i__2 = __state->p - 1) < 5000 && 
	    0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "stnseg", i__2, 
	    "daffa_", (ftnlen)4127)]) {
	dafhfn_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)4129)], __state->dafnam, (ftnlen)255);
	setmsg_(__global_state, "No array is current; the `previous' array i"
		"s the last array of DAF #", (ftnlen)68);
	errch_(__global_state, "#", __state->dafnam, (ftnlen)1, (ftnlen)255);
	sigerr_(__global_state, "SPICE(NOCURRENTARRAY)", (ftnlen)21);
	chkout_(__global_state, "DAFRN", (ftnlen)5);
	return 0;
    }

/*     Read the name record for this summary record, if we don't have it */
/*     already. */

    if (! __state->sthvnr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 :
	     s_rnge(&__global_state->f2c, "sthvnr", i__1, "daffa_", (ftnlen)
	    4146)]) {
	i__4 = __state->stthis[(i__2 = __state->p - 1) < 5000 && 0 <= i__2 ? 
		i__2 : s_rnge(&__global_state->f2c, "stthis", i__2, "daffa_", 
		(ftnlen)4148)] + 1;
	dafrcr_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)4148)], &i__4, __state->stnr + ((i__3 
		= __state->p - 1) < 5000 && 0 <= i__3 ? i__3 : s_rnge(&
		__global_state->f2c, "stnr", i__3, "daffa_", (ftnlen)4148)) * 
		1000, (ftnlen)1000);
	__state->sthvnr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "sthvnr", i__1, "daffa_", (
		ftnlen)4150)] = TRUE_;
    }

/*     The location of the name depends on the current pointer */
/*     position. */

    dafhsf_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 && 
	    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", i__1, 
	    "daffa_", (ftnlen)4159)], &__state->nd, &__state->ni);
    __state->sumsiz = __state->nd + (__state->ni + 1) / 2;
    __state->namsiz = __state->sumsiz << 3;
    __state->offset = (__state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= 
	    i__1 ? i__1 : s_rnge(&__global_state->f2c, "stcurr", i__1, "daff"
	    "a_", (ftnlen)4165)] - 1) * __state->namsiz;
    i__2 = __state->offset;
    s_copy(&__global_state->f2c, __state->stnr + (((i__1 = __state->p - 1) < 
	    5000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stnr", 
	    i__1, "daffa_", (ftnlen)4167)) * 1000 + i__2), name__, 
	    __state->offset + __state->namsiz - i__2, name_len);

/*     Rewrite the character record. */

    i__4 = __state->stthis[(i__2 = __state->p - 1) < 5000 && 0 <= i__2 ? i__2 
	    : s_rnge(&__global_state->f2c, "stthis", i__2, "daffa_", (ftnlen)
	    4172)] + 1;
    dafwcr_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 && 
	    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", i__1, 
	    "daffa_", (ftnlen)4172)], &i__4, __state->stnr + ((i__3 = 
	    __state->p - 1) < 5000 && 0 <= i__3 ? i__3 : s_rnge(&
	    __global_state->f2c, "stnr", i__3, "daffa_", (ftnlen)4172)) * 
	    1000, (ftnlen)1000);
    chkout_(__global_state, "DAFRN", (ftnlen)5);
    return 0;
/* $Procedure DAFWS ( DAF, write summary ) */

L_dafws:
/* $ Abstract */

/*     Write a new summary for the current array in the current DAF. */

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

/*     DAF */

/* $ Keywords */

/*     FILES */

/* $ Declarations */

/*     DOUBLE PRECISION      SUM ( * ) */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     SUM        I   New summary for current array in the current DAF. */

/* $ Detailed_Input */

/*     SUM         is the new summary for the current array. This */
/*                 replaces the existing summary, including the */
/*                 addresses (the final two integer components) of */
/*                 the original summary. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If this routine is called when no search is in progress in the */
/*         the current DAF, the error SPICE(DAFNOSEARCH) is signaled. */

/*     2)  If the DAF containing the `current' array has actually been */
/*         closed, the error will be diagnosed by routines called by */
/*         this routine. */

/*     3)  If the DAF containing the `current' array is not open for */
/*         writing, the error will be diagnosed by routines called by */
/*         this routine. */

/*     4)  If no array is current in the current DAF, the error */
/*         SPICE(NOCURRENTARRAY) is signaled. There is no current */
/*         array when a search is started by DAFBFS or DAFBBS, but no */
/*         calls to DAFFNA or DAFBNA have been made yet, or whenever */
/*         DAFFNA or DAFFPA return the value .FALSE. in the FOUND */
/*         argument. */

/* $ Files */

/*     DAFWS updates the DAF currently being searched. The handle */
/*     of this DAF can be retrieved using the routine DAFGH. */

/* $ Particulars */

/*     Unless you are reordering the arrays in the file being searched, */
/*     you should be using DAFRS instead of this routine. */

/*     See also DAFFA, DAFRS. */

/* $ Examples */

/*     See DAFFA. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     W.L. Taber      (JPL) */
/*     I.M. Underwood  (JPL) */
/*     E.D. Wright     (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.2, 18-AUG-2011 (EDW) */

/*        Eliminated unneeded Revisions section. */

/*        Removed the obsolete Reference citation to "NAIF */
/*        Document 167.0." */

/* -    SPICELIB Version 2.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 2.0.0, 04-SEP-1991 (NJB) (WLT) */

/*        Updated to support simultaneous searches of multiple DAFs. */
/*        Bug fix made to handle case of having no current array. */

/*        This routine now operates on the current DAF---the one at */
/*        the head of the active list. All saved state variables */
/*        used by this routine are now part of the state table, or */
/*        its associated set of pointers. */

/*        In addition, this routine now checks whether an array */
/*        is current before trying to read its summary. The routine */
/*        previously crashed under these conditions. */

/* -    SPICELIB Version 1.0.0, 28-MAR-1991 (IMU) */

/* -& */
/* $ Index_Entries */

/*     write DAF summary */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "DAFWS", (ftnlen)5);
    }

/*     Operate on the last DAF in which a search has been started. */

    __state->p = __state->sthead;

/*     Make sure that a search has been started in this DAF. */

    if (__state->p == -1) {
	setmsg_(__global_state, "No DAF is currently being searched.", (
		ftnlen)35);
	sigerr_(__global_state, "SPICE(DAFNOSEARCH)", (ftnlen)18);
	chkout_(__global_state, "DAFWS", (ftnlen)5);
	return 0;

/*     Make sure that the `current' DAF is still open, and that it is */
/*     open for writing. */

    } else {
	dafsih_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)4366)], "READ", (ftnlen)4);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "DAFWS", (ftnlen)5);
	    return 0;
	}
    }

/*     Check the current pointer position to make sure that it's in */
/*     bounds. If there is no current array, then we cannot write a */
/*     new array summary. This situation occurs if DAFFNA was called */
/*     when the current array was the last, or if DAFFPA was called */
/*     when the current array was the first. */

    if (__state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "stcurr", i__1, "daffa_", (ftnlen)
	    4382)] == 0) {
	dafhfn_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)4384)], __state->dafnam, (ftnlen)255);
	setmsg_(__global_state, "No array is current; the `next' array is th"
		"e first array of DAF #", (ftnlen)65);
	errch_(__global_state, "#", __state->dafnam, (ftnlen)1, (ftnlen)255);
	sigerr_(__global_state, "SPICE(NOCURRENTARRAY)", (ftnlen)21);
	chkout_(__global_state, "DAFWS", (ftnlen)5);
	return 0;
    } else if (__state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "stcurr", i__1, "daffa_", (
	    ftnlen)4393)] > __state->stnseg[(i__2 = __state->p - 1) < 5000 && 
	    0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "stnseg", i__2, 
	    "daffa_", (ftnlen)4393)]) {
	dafhfn_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", 
		i__1, "daffa_", (ftnlen)4395)], __state->dafnam, (ftnlen)255);
	setmsg_(__global_state, "No array is current; the `previous' array i"
		"s the last array of DAF #", (ftnlen)68);
	errch_(__global_state, "#", __state->dafnam, (ftnlen)1, (ftnlen)255);
	sigerr_(__global_state, "SPICE(NOCURRENTARRAY)", (ftnlen)21);
	chkout_(__global_state, "DAFWS", (ftnlen)5);
	return 0;
    }

/*     The location of the summary depends on the current pointer */
/*     position. */

    dafhsf_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 && 
	    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", i__1, 
	    "daffa_", (ftnlen)4412)], &__state->nd, &__state->ni);
    __state->sumsiz = __state->nd + (__state->ni + 1) / 2;
    __state->offset = (__state->stcurr[(i__1 = __state->p - 1) < 5000 && 0 <= 
	    i__1 ? i__1 : s_rnge(&__global_state->f2c, "stcurr", i__1, "daff"
	    "a_", (ftnlen)4416)] - 1) * __state->sumsiz + 3;
    moved_(__global_state, sum, &__state->sumsiz, &__state->stsr[(i__1 = 
	    __state->offset + 1 + (__state->p << 7) - 129) < 640000 && 0 <= 
	    i__1 ? i__1 : s_rnge(&__global_state->f2c, "stsr", i__1, "daffa_",
	     (ftnlen)4418)]);

/*     Rewrite the modified summary record. */

    dafwdr_(__global_state, &__state->stfh[(i__1 = __state->p - 1) < 5000 && 
	    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stfh", i__1, 
	    "daffa_", (ftnlen)4423)], &__state->stthis[(i__2 = __state->p - 1)
	     < 5000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "stth"
	    "is", i__2, "daffa_", (ftnlen)4423)], &__state->stsr[(i__3 = (
	    __state->p << 7) - 128) < 640000 && 0 <= i__3 ? i__3 : s_rnge(&
	    __global_state->f2c, "stsr", i__3, "daffa_", (ftnlen)4423)]);
    chkout_(__global_state, "DAFWS", (ftnlen)5);
    return 0;
/* $Procedure DAFCS ( DAF, continue search ) */

L_dafcs:
/* $ Abstract */

/*     Select a DAF that already has a search in progress as the */
/*     one to continue searching. */

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

/*     DAF */

/* $ Keywords */

/*     FILES */

/* $ Declarations */

/*     INTEGER               HANDLE */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle of DAF to continue searching. */

/* $ Detailed_Input */

/*     HANDLE         is the handle of a DAF in which either a forward */
/*                    or backward search has already been started by */
/*                    DAFBFS or DAFBBS. The DAF may be open for read */
/*                    or write access. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the input handle is invalid, the error will be diagnosed */
/*         by routines called by this routine. */

/*     2)  If this routine is called when no search is in progress in the */
/*         the current DAF, the error SPICE(DAFNOSEARCH) is signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     DAFCS supports simultaneous searching of multiple DAFs. In */
/*     applications that use this capability, DAFCS should be called */
/*     prior to each call to DAFFNA, DAFFPA, DAFGN, DAFGS, DAFRS, or */
/*     DAFWS, to specify which DAF is to be acted upon. */

/* $ Examples */

/*     See DAFFA. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     W.L. Taber     (JPL) */
/*     B.V. Semenov   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.2, 10-FEB-2014 (BVS) */

/*        Added full declaration of HANDLE to the Declarations section */
/*        of the header. */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 04-SEP-1991 (NJB) (WLT) */

/* -& */
/* $ Index_Entries */

/*     select a DAF to continue searching */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "DAFCS", (ftnlen)5);
    }

/*     Validate the DAF's handle before going any further. DAFSIH will */
/*     signal an error if HANDLE doesn't designate an open DAF. */

    dafsih_(__global_state, handle, "READ", (ftnlen)4);
    if (failed_(__global_state)) {
	chkout_(__global_state, "DAFCS", (ftnlen)5);
	return 0;
    }

/*     See whether we already have an entry for this DAF in the */
/*     state table. Find the previous node if possible. */

    __state->p = __state->sthead;
    __state->prev = -1;
    __state->fnd = FALSE_;
    while(__state->p != -1 && ! __state->fnd) {
	if (__state->stfh[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 :
		 s_rnge(&__global_state->f2c, "stfh", i__1, "daffa_", (ftnlen)
		4588)] == *handle) {
	    __state->fnd = TRUE_;
	} else {
	    __state->prev = __state->p;
	    __state->p = __state->stpool[(i__1 = __state->p - 1) < 5000 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stpool", 
		    i__1, "daffa_", (ftnlen)4592)];
	}
    }

/*     Either FND is false, or P is the index in the state table of */
/*     the DAF specified by HANDLE, and PREV is the predecessor of P. */


/*     You can't continue searching a DAF that you're not already */
/*     searching. */

    if (! __state->fnd) {
	setmsg_(__global_state, "No DAF is currently being searched.", (
		ftnlen)35);
	sigerr_(__global_state, "SPICE(DAFNOSEARCH)", (ftnlen)18);
	chkout_(__global_state, "DAFCS", (ftnlen)5);
	return 0;
    }

/*     Move the node for this DAF to the head of the active list, */
/*     if it is not already there: */

/*        - Make the predecessor of P point to the successor of P. */

/*        - Make P point to the head of the active list. */

/*        - Make P the active list head node. */

    if (__state->p != __state->sthead) {

/*        P is in the active list, but is not at the head. So, */
/*        the predecessor of P is not NIL. */

	__state->stpool[(i__1 = __state->prev - 1) < 5000 && 0 <= i__1 ? i__1 
		: s_rnge(&__global_state->f2c, "stpool", i__1, "daffa_", (
		ftnlen)4632)] = __state->stpool[(i__2 = __state->p - 1) < 
		5000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "stp"
		"ool", i__2, "daffa_", (ftnlen)4632)];
	__state->stpool[(i__1 = __state->p - 1) < 5000 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "stpool", i__1, "daffa_", (
		ftnlen)4633)] = __state->sthead;
	__state->sthead = __state->p;
    }
    chkout_(__global_state, "DAFCS", (ftnlen)5);
    return 0;
} /* daffa_ */

/* Subroutine */ int daffa_(cspice_t* __global_state, integer *handle, 
	doublereal *sum, char *name__, logical *found, ftnlen name_len)
{
    return daffa_0_(__global_state, 0, handle, sum, name__, found, name_len);
    }

/* Subroutine */ int dafbfs_(cspice_t* __global_state, integer *handle)
{
    return daffa_0_(__global_state, 1, handle, (doublereal *)0, (char *)0, (
	    logical *)0, (ftnint)0);
    }

/* Subroutine */ int daffna_(cspice_t* __global_state, logical *found)
{
    return daffa_0_(__global_state, 2, (integer *)0, (doublereal *)0, (char *)
	    0, found, (ftnint)0);
    }

/* Subroutine */ int dafbbs_(cspice_t* __global_state, integer *handle)
{
    return daffa_0_(__global_state, 3, handle, (doublereal *)0, (char *)0, (
	    logical *)0, (ftnint)0);
    }

/* Subroutine */ int daffpa_(cspice_t* __global_state, logical *found)
{
    return daffa_0_(__global_state, 4, (integer *)0, (doublereal *)0, (char *)
	    0, found, (ftnint)0);
    }

/* Subroutine */ int dafgs_(cspice_t* __global_state, doublereal *sum)
{
    return daffa_0_(__global_state, 5, (integer *)0, sum, (char *)0, (logical 
	    *)0, (ftnint)0);
    }

/* Subroutine */ int dafgn_(cspice_t* __global_state, char *name__, ftnlen 
	name_len)
{
    return daffa_0_(__global_state, 6, (integer *)0, (doublereal *)0, name__, 
	    (logical *)0, name_len);
    }

/* Subroutine */ int dafgh_(cspice_t* __global_state, integer *handle)
{
    return daffa_0_(__global_state, 7, handle, (doublereal *)0, (char *)0, (
	    logical *)0, (ftnint)0);
    }

/* Subroutine */ int dafrs_(cspice_t* __global_state, doublereal *sum)
{
    return daffa_0_(__global_state, 8, (integer *)0, sum, (char *)0, (logical 
	    *)0, (ftnint)0);
    }

/* Subroutine */ int dafrn_(cspice_t* __global_state, char *name__, ftnlen 
	name_len)
{
    return daffa_0_(__global_state, 9, (integer *)0, (doublereal *)0, name__, 
	    (logical *)0, name_len);
    }

/* Subroutine */ int dafws_(cspice_t* __global_state, doublereal *sum)
{
    return daffa_0_(__global_state, 10, (integer *)0, sum, (char *)0, (
	    logical *)0, (ftnint)0);
    }

/* Subroutine */ int dafcs_(cspice_t* __global_state, integer *handle)
{
    return daffa_0_(__global_state, 11, handle, (doublereal *)0, (char *)0, (
	    logical *)0, (ftnint)0);
    }

