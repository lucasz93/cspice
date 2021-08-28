/* zzddhman.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzddhman_init_t __zzddhman_init;
static inline zzddhman_state_t* get_zzddhman_state(cspice_t* state) {
	if (!state->zzddhman)
		state->zzddhman = __cspice_allocate_module(sizeof(
	zzddhman_state_t), &__zzddhman_init, sizeof(__zzddhman_init));
	return state->zzddhman;

}

/* $Procedure ZZDDHMAN ( Private --- DAF/DAS Handle Manager ) */
/* Subroutine */ int zzddhman_0_(cspice_t* __global_state, int n__, logical *
	lock, char *arch, char *fname, char *method, integer *handle, integer 
	*unit, integer *intamh, integer *intarc, integer *intbff, logical *
	native, logical *found, logical *kill, ftnlen arch_len, ftnlen 
	fname_len, ftnlen method_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3;
    olist o__1;
    cllist cl__1;
    inlist ioin__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen), f_inqu(
	    f2c_state_t*, inlist *), s_rnge(f2c_state_t*, char *, integer, 
	    char *, integer), f_open(f2c_state_t*, olist *), f_clos(
	    f2c_state_t*, cllist *);

    /* Local variables */
    extern /* Subroutine */ int zzddhf2h_(cspice_t*, char *, integer *, 
	    integer *, integer *, integer *, integer *, char *, integer *, 
	    doublereal *, integer *, integer *, integer *, logical *, integer 
	    *, integer *, logical *, logical *, integer *, logical *, 
	    doublereal *, ftnlen, ftnlen);
    extern /* Subroutine */ int zzddhini_(cspice_t*, integer *, integer *, 
	    integer *, char *, char *, char *, ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int zzddhrcm_(cspice_t*, integer *, integer *, 
	    integer *);
    extern integer zzddhclu_(cspice_t*, logical *, integer *);
    extern /* Subroutine */ int zzddhppf_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int zzddhgtu_(cspice_t*, integer *, integer *, 
	    logical *, integer *, integer *, integer *);
    extern /* Subroutine */ int zzddhrmu_(cspice_t*, integer *, integer *, 
	    integer *, integer *, logical *, integer *, integer *);
    extern /* Subroutine */ int zzpltchk_(cspice_t*, logical *);
    integer i__;
    integer lchar;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int ucase_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int repmc_(cspice_t*, char *, char *, char *, 
	    char *, ftnlen, ftnlen, ftnlen, ftnlen);
    logical error;
    extern integer rtrim_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int ljust_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern logical failed_(cspice_t*);
    integer accmet;
    integer filarc;
    integer locked;
    logical locfnd;
    extern integer bsrchi_(cspice_t*, integer *, integer *, integer *);
    extern integer isrchc_(cspice_t*, char *, integer *, char *, ftnlen, 
	    ftnlen);
    char locfnm[255];
    integer inqhan;
    extern integer isrchi_(cspice_t*, integer *, integer *, integer *);
    logical platok;
    integer loclun;
    integer findex;
    integer uindex;
    integer iostat;
    logical inqopn;
    logical inqext;
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    integer supidx;
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int frelun_(cspice_t*, integer *);
    char tmpstr[8];
    integer bff;
    doublereal mnm;


    /* Module state */
    zzddhman_state_t* __state = get_zzddhman_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     This is an umbrella routine for a collection of entry points */
/*     to the DAF/DAS handle manager. */

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

/*     None. */

/* $ Keywords */

/*     DAF */
/*     DAS */
/*     PRIVATE */

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

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     LOCK       I   HLU */
/*     ARCH      I/O  OPN, CLS, HLU, UNL */
/*     FNAME     I/O  OPN, NFO, FNH */
/*     METHOD    I/O  OPN */
/*     HANDLE    I/O  OPN, CLS, HLU, UNL, ISN, NFO, FNH, LUH */
/*     UNIT      I/O  HLU, LUH */
/*     INTAMH     O   NFO */
/*     INTARC     O   NFO */
/*     INTBFF     O   NFO */
/*     NATIVE     O   ISN */
/*     FOUND      O   ISN, NFO, FNH, LUH */
/*     KILL       I   CLS */

/* $ Detailed_Input */

/*     See the entry points for descriptions of their inputs. */

/* $ Detailed_Output */

/*     See the entry points for descriptions of their outputs. */

/* $ Parameters */

/*     See the include file 'zzddhman.inc' for details of parameter */
/*     definitions used within this module. */

/* $ Exceptions */

/*     1) If ZZDDHMAN is called directly, the error SPICE(BOGUSENTRY) */
/*        is signaled. */

/*     2) See entry points ZZDDHOPN, ZZDDHCLS, ZZDDHHLU, ZZDDHUNL, */
/*        ZZDDHISN, ZZDDHNFO, ZZDDHFNH, and ZZDDHLUH for exceptions */
/*        specific to those entry points. */

/* $ Files */

/*     This set of routines is intended to provide low-level services */
/*     for the creation, updating, and reading of Fortran direct access */
/*     files utilized by the DAF and DAS systems within SPICE. */

/* $ Particulars */

/*     ZZDDHMAN serves as an umbrella, allowing data to be shared by */
/*     its entry points: */

/*        ZZDDHOPN       Open file. */
/*        ZZDDHCLS       Close file. */
/*        ZZDDHHLU       Handle to logical unit. */
/*        ZZDDHUNL       Unlock handle from unit. */
/*        ZZDDHISN       Is the file native architecture? */
/*        ZZDDHNFO       Fetch information about a handle. */
/*        ZZDDHFNH       Filename to handle. */
/*        ZZDDFLUH       Logical unit to handle. */

/*     This umbrella serves a variety of functions to the DAS/DAF */
/*     families of routines. */

/*        (1) DAF/DAS handle consolidation */
/*        (2) Binary file format detection and tracking */
/*        (3) FTP error detection services */
/*        (4) Logical unit sharing */
/*        (5) Filename and unit to handle mapping services */

/* $ Examples */

/*     See individual entry points for pointers to modules that utilize */
/*     their capabilities. */

/* $ Restrictions */

/*     1) Changing the current working directory of a program when */
/*        more than UTSIZE files are loaded into this interface requires */
/*        that all filenames passed into ZZDDHOPN are specified with */
/*        absolute pathnames.  Otherwise the OPEN/CLOSE switching */
/*        logic will fail to OPEN files that are loaded. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     F.S. Turner     (JPL) */
/*     E.D. Wright     (JPL) */
/*     B.V. Semenov    (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.1.0, 26-APR-2012 (BVS) */

/*        Added the "magic number" column to the file table. */

/* -    SPICELIB Version 2.0.1, 24-APR-2003 (EDW) */

/*        Added MAC-OSX-F77 to the list of platforms */
/*        that require READONLY to read write protected */
/*        kernels. */

/* -    SPICELIB Version 2.0.0, 07-AUG-2002 (FST) */

/*        The entry point ZZDDHOPN now invokes ZZPLTCHK, to verify */
/*        that the runtime environment's binary file format matches */
/*        the one for which the toolkit is configured. */

/*        The entry point ZZDDHCLS has had its argument list augmented */
/*        to include a "KILL" flag.  Check the entry point header for */
/*        details. */

/* -    SPICELIB Version 1.0.0, 06-NOV-2001 (FST) */


/* -& */
/* $ Revisions */

/* -    SPICELIB Version 2.0.0, 07-AUG-2002 (FST) */

/*        The toolkit source code is far more sensitive to blind */
/*        porting of source packaged for one environment to another. */
/*        This sensitivity has already caused a few of our users */
/*        some difficulty.  In an attempt to address these problems */
/*        with future toolkits, ZZDDHOPN now invokes ZZPLTCHK on */
/*        it's first pass.  This will perform any necessary checks */
/*        on the runtime environment against the values recorded */
/*        in ZZPLATFM and other environment specific components */
/*        of the library. */

/*        As of this release, all that is verified is that the */
/*        BFF ID listed in ZZPLATFM is compatible with the runtime */
/*        environment.  See ZZPLTCHK's header for deatils. */

/* -& */

/*     SPICELIB Functions */


/*     Local Variables */


/*     This logical allows initialization code to execute. */


/*     These strings store the labels for the parameters defined */
/*     in the include file and retrieved by ZZDDHINI. */


/*     The file table consists of a set of arrays which serve as */
/*     'columns' of the table.  The sets of elements having the same */
/*     index in the arrays form the 'rows' of the table.  Each column */
/*     contains a particular type of information; each row contains */
/*     all of the information pertaining to a particular file. */

/*     All column names in the file table begin with 'FT'.  The columns */
/*     are: */

/*        ABS      Absolute value of HAN */
/*        AMH      File access method */
/*        ARC      File architecture */
/*        BFF      Binary file format */
/*        HAN      Handle */
/*        NAM      Filename */
/*        RTM      RTRIM (right trimmed value for NAM) */
/*        MNM      Unique DP number (the Magic NuMber ;) */

/*     New 'rows' are added to the end of the list; the list is repacked */
/*     whenever a file is removed from the list. */

/*     NFT is the number of files currently loaded; this may not be */
/*     greater than FTSIZE.  FINDEX refers to a file of interest within */
/*     the table.  Since handles are always assigned in an increasing */
/*     fashion, FTABS is guaranteed to be a sorted list.  We will use */
/*     this fact to improve handle lookups in the file table. */


/*     NEXT stores the next handle to be used for file access.  This */
/*     could be either for read or write based operations. NEXT is */
/*     incremented just before entries in the file table are made. */
/*     It begins as zero valued. */


/*     The unit table consists of a set of arrays which serve as */
/*     'columns' of the table.  The sets of elements having the same */
/*     index in the arrays form the 'rows' of the table.  Each column */
/*     contains a particular type of information; each row contains */
/*     all of the information pertaining to a particular logical unit. */

/*     All column names in the unit table begin with 'UT'.  The columns */
/*     are: */

/*        CST      Cost to remove the file from the unit table */
/*        HAN      Handle */
/*        LCK      Is this logical unit locked to this handle? */
/*        LUN      Logical unit */

/*     New 'rows' are added to the end of the list; the list is repacked */
/*     whenever a logical unit is no longer needed. */

/*     NUT is the number of units currently stored in the table; this */
/*     may not exceed UTSIZE.  UINDEX referes to a unit of interest */
/*     within the table. */


/*     The following stores the native binary file format, a list of */
/*     codes for supported binary formats, and the number of entries */
/*     in SUPBFF. */


/*     Request counter used to determine cost. */


/*     Saved Variables */


/*     Data Statements */

    switch(n__) {
	case 1: goto L_zzddhopn;
	case 2: goto L_zzddhcls;
	case 3: goto L_zzddhhlu;
	case 4: goto L_zzddhunl;
	case 5: goto L_zzddhnfo;
	case 6: goto L_zzddhisn;
	case 7: goto L_zzddhfnh;
	case 8: goto L_zzddhluh;
	}


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "ZZDDHMAN", (ftnlen)8);
	sigerr_(__global_state, "SPICE(BOGUSENTRY)", (ftnlen)17);
	chkout_(__global_state, "ZZDDHMAN", (ftnlen)8);
    }
    return 0;
/* $Procedure ZZDDHOPN ( Private --- Load file ) */

L_zzddhopn:
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Load a new direct access file. */

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

/*     None. */

/* $ Keywords */

/*     DAS */
/*     DAF */
/*     PRIVATE */

/* $ Declarations */

/*     CHARACTER*(*)         FNAME */
/*     CHARACTER*(*)         METHOD */
/*     CHARACTER*(*)         ARCH */
/*     INTEGER               HANDLE */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     FNAME      I   Name of file to be loaded. */
/*     METHOD     I   Access method used to load the file. */
/*     ARCH       I   Expected architecture of the file to load. */
/*     HANDLE     O   Handle assigned to file. */

/* $ Detailed_Input */

/*     FNAME      is the file name of the file to be loaded for direct */
/*                access. */

/*     METHOD     is the method by which to load the file. Acceptable */
/*                values are: */

/*                   'READ'    - Load existing file for read access. */
/*                   'WRITE'   - Load existing file for write access. */
/*                   'SCRATCH' - Load scratch file. */
/*                   'NEW'     - Load a new file for write access. */

/*                Note: The value of METHOD is case-insensitive. */

/*     ARCH       is the architecture of the file to be loaded. */
/*                Acceptable values are: */

/*                   'DAF'    - Load a DAF file */
/*                   'DAS'    - Load a DAS file */

/*                Note: The value of ARCH is case-insensitive. */

/* $ Detailed_Output */

/*     HANDLE     is the file handle associated with the file.  This */
/*                handle is used to identify the file in subsequent */
/*                calls to other routines. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) The error SPICE(UNSUPPORTEDMETHOD) is signaled when the */
/*        METHOD input argument is improperly specified.  The value of */
/*        the output argument HANDLE is undefined when this error is */
/*        signaled. */

/*     2) The error SPICE(UNSUPPORTEDARCH) is signaled when the ARCH */
/*        input argument is improperly specified.  The value of the */
/*        output argument HANDLE is undefined when this error is */
/*        signaled. */

/*     3) The error SPICE(UTFULL) is signaled whenever METHOD is */
/*        set to 'SCRATCH' and no available units exist in the */
/*        unit table for locking.  The value of the output argument */
/*        HANDLE is undefined when this error is signaled. */

/*     4) The error SPICE(BLANKFILENAME) is signaled whenever METHOD */
/*        is set to 'READ', 'WRITE', or 'NEW' and the FNAME argument */
/*        is a blank string.  The value of the output argument HANDLE */
/*        is undefined when this error is signaled. */

/*     5) The error SPICE(FILENOTFOUND) is signaled whenever METHOD */
/*        is set to 'READ' or 'WRITE' and an INQUIRE performed on FNAME */
/*        indicates the file does not exist.  The value of the output */
/*        argument HANDLE is undefined when this error is signaled. */

/*     6) The error SPICE(IMPROPEROPEN) is signaled if the file */
/*        associated with FNAME is attached to a unit from some */
/*        source external to ZZDDHMAN's entry points.  The value of the */
/*        output argument HANDLE is undefined when this error is */
/*        signaled. */

/*     7) The error SPICE(FILARCMISMATCH) is signaled when a file is */
/*        loaded for 'READ' or 'WRITE' and the architecture of the */
/*        existing file disagrees with that of the input argument ARCH. */
/*        The value of the output argument HANDLE is undefined when */
/*        this error is signaled. */

/*     8) The error SPICE(FILEOPENCONFLICT) is signaled when an attempt */
/*        to load an already loaded file for any access other than READ. */
/*        The value of the output argument HANDLE is undefined when this */
/*        error is signaled. */

/*     9) The error SPICE(RWCONFLICT) is signaled when an attempt to */
/*        load a file for READ access that is already loaded into the */
/*        handle manager with a conflicting access method.  The value of */
/*        the output argument HANDLE is undefined when this error is */
/*        signaled. */

/*    10) The error SPICE(FTFULL) is signaled when an attempt to load */
/*        more than the maximum number of allowable files, FTSIZE, */
/*        is made.  The value of the output argument HANDLE is undefined */
/*        when this error is signaled. */

/*    11) The error SPICE(FILEOPENFAIL) is signaled whenever the */
/*        the file open fails with non-zero IOSTAT.  The value of the */
/*        output argument HANDLE is undefined when this error is */
/*        signaled. */

/*    12) The error SPICE(UNSUPPORTEDBFF) is signaled whenever the file */
/*        to be opened utilizes a binary file format that the platform */
/*        does not currently support.  The value of the output argument */
/*        HANDLE is undefined when this error is signaled. */

/*    13) When loading files with METHOD set to 'NEW', any errors */
/*        generated by this routine will cause the newly created file */
/*        to be deleted. */

/*    14) If the toolkit source is improperly configured for the */
/*        runtime environment, routines in the call tree of this */
/*        routine may signal errors. */

/* $ Files */

/*     1) All direct access files loaded by this routine for */
/*        access methods other than 'SCRATCH' are specified by name. */

/*     2) Files opened with access method 'SCRATCH' are referenced */
/*        only by their logical unit. */

/* $ Particulars */

/*     This private routine is designed to provide a common, unified */
/*     file load interface for DAF and DAS. */

/* $ Examples */

/*     See DAFOPR, DAFONW, DAFOPW, DASOPR, DASOPS, DASONW, DASOPW for */
/*     sample usage. */

/* $ Restrictions */

/*     1) Files loaded through this interface should not be opened by */
/*        any other mechanism until the appropriate call to ZZDDHCLS */
/*        is made. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     F.S. Turner     (JPL) */
/*     B.V. Semenov    (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.1.0, 26-APR-2012 (BVS) */

/*        Updated for the new "magic number" column in the file table. */

/* -    SPICELIB Version 2.0.0, 07-AUG-2002 (FST) */

/*        This entry point was updated to perform checks on the */
/*        runtime environment, to verify that the source is properly */
/*        configured for execution on this environment.  See the */
/*        Revisions section of ZZDDHMAN for details. */

/* -    SPICELIB Version 1.0.0, 06-NOV-2001 (FST) */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "ZZDDHOPN", (ftnlen)8);
    }

/*     Do the initialization tasks. */

    if (__state->first) {
	zzddhini_(__global_state, &__state->natbff, __state->supbff, &
		__state->numsup, __state->stramh, __state->strarc, 
		__state->strbff, (ftnlen)8, (ftnlen)8, (ftnlen)8);

/*        Check FAILED() to handle the unlikely event that */
/*        ZZDDHINI signaled SPICE(BUG). */

	if (failed_(__global_state)) {
	    chkout_(__global_state, "ZZDDHOPN", (ftnlen)8);
	    return 0;
	}

/*        Clear FIRST since we've done the initialization. */

	__state->first = FALSE_;
    }

/*     On first pass, perform any runtime environment checks. */

    if (__state->opnfst) {
	zzpltchk_(__global_state, &platok);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "ZZDDHOPN", (ftnlen)8);
	    return 0;
	}

/*        Clear OPNFST, since we've performed the diagnostics. */

	__state->opnfst = FALSE_;
    }

/*     Initialize the value of HANDLE to 0.  In the event an error */
/*     is signaled this invalid value will be returned to the caller */
/*     for safety. */

    *handle = 0;

/*     Left justify FNAME to compress off any leading spaces. */

    ljust_(__global_state, fname, locfnm, fname_len, (ftnlen)255);

/*     Translate the value of the requested access method to the */
/*     corresponding integer code. */

    s_copy(&__global_state->f2c, tmpstr, method, (ftnlen)8, method_len);
    ucase_(__global_state, tmpstr, tmpstr, (ftnlen)8, (ftnlen)8);
    accmet = isrchc_(__global_state, tmpstr, &__state->c__4, __state->stramh, 
	    (ftnlen)8, (ftnlen)8);

/*     Check if the code was located. */

    if (accmet == 0) {

/*        Recall HANDLE was initialized to 0, and this invalid */
/*        value is returned to the caller. */

	setmsg_(__global_state, "The attempt to load file, '#', with access "
		"method, '#', failed because this access method is unsupporte"
		"d.", (ftnlen)105);
	errch_(__global_state, "#", locfnm, (ftnlen)1, (ftnlen)255);
	errch_(__global_state, "#", method, (ftnlen)1, method_len);
	sigerr_(__global_state, "SPICE(UNSUPPORTEDMETHOD)", (ftnlen)24);
	chkout_(__global_state, "ZZDDHOPN", (ftnlen)8);
	return 0;
    }

/*     Translate the value of the requested file architecture to */
/*     the appropriate integer code. */

    s_copy(&__global_state->f2c, tmpstr, arch, (ftnlen)8, arch_len);
    ucase_(__global_state, tmpstr, tmpstr, (ftnlen)8, (ftnlen)8);
    filarc = isrchc_(__global_state, tmpstr, &__state->c__2, __state->strarc, 
	    (ftnlen)8, (ftnlen)8);

/*     Check if the code was located. */

    if (filarc == 0) {

/*        Recall HANDLE was initialized to 0, and this invalid */
/*        value is returned to the caller. */

	setmsg_(__global_state, "The attempt to load file, '#', with archite"
		"cture, '#', failed because this file architecture is unsuppo"
		"rted.", (ftnlen)108);
	errch_(__global_state, "#", locfnm, (ftnlen)1, (ftnlen)255);
	errch_(__global_state, "#", arch, (ftnlen)1, arch_len);
	sigerr_(__global_state, "SPICE(UNSUPPORTEDARCH)", (ftnlen)22);
	chkout_(__global_state, "ZZDDHOPN", (ftnlen)8);
	return 0;
    }

/*     Perform any preliminary checks that must be done before */
/*     fetching a logical unit from the unit table.  This requires */
/*     branching based on ACCMET's value. */

    if (accmet == 3) {

/*        Check to see if there are enough units available for locking */
/*        in the unit table.  If not, signal an error as all files */
/*        open with SCRTCH access must be locked to their units. */

	locked = zzddhclu_(__global_state, __state->utlck, &__state->nut);
	if (locked >= 21) {

/*           Recall HANDLE was initialized to 0, and this invalid */
/*           value is returned to the caller. */

	    setmsg_(__global_state, "The maximum number of units are locked "
		    "to handles.  As such, there is no room to open the reque"
		    "sted scratch file.", (ftnlen)113);
	    sigerr_(__global_state, "SPICE(UTFULL)", (ftnlen)13);
	    chkout_(__global_state, "ZZDDHOPN", (ftnlen)8);
	    return 0;
	}

/*     The NEW, READ, and WRITE access methods perform the same */
/*     checks on LOCFNM. */

    } else if (accmet == 4 || accmet == 1 || accmet == 2) {

/*        Check for a non-blank file name. */

	if (s_cmp(&__global_state->f2c, locfnm, " ", (ftnlen)255, (ftnlen)1) 
		== 0) {

/*           Recall HANDLE was initialized to 0, and this invalid */
/*           value is returned to the caller. */

	    setmsg_(__global_state, "The attempt to load the file has failed"
		    ", because the filename is blank.", (ftnlen)71);
	    sigerr_(__global_state, "SPICE(BLANKFILENAME)", (ftnlen)20);
	    chkout_(__global_state, "ZZDDHOPN", (ftnlen)8);
	    return 0;
	}
    }
    mnm = 0.;

/*     In the READ or WRITE cases verify that LOCFNM is not already */
/*     in the file table. */

    if (accmet == 1 || accmet == 2) {

/*        Check to see if the file associated with LOCFNM is already in */
/*        the file table. */

	zzddhf2h_(__global_state, locfnm, __state->ftabs, __state->ftamh, 
		__state->ftarc, __state->ftbff, __state->fthan, 
		__state->ftnam, __state->ftrtm, __state->ftmnm, &__state->nft,
		 __state->utcst, __state->uthan, __state->utlck, 
		__state->utlun, &__state->nut, &inqext, &inqopn, &inqhan, &
		locfnd, &mnm, (ftnlen)255, (ftnlen)255);

/*        First, check FAILED(), and return if anything has gone awry. */
/*        Recall HANDLE was initialized to 0, and this invalid */
/*        value is returned to the caller. */

	if (failed_(__global_state)) {
	    chkout_(__global_state, "ZZDDHOPN", (ftnlen)8);
	    return 0;
	}

/*        Now perform some simple sanity checks before preparing to */
/*        load the file.  First check to see if the file exists, it must */
/*        if we are going to open it with ACCMET set to READ or WRITE. */

	if (! inqext) {

/*           Recall HANDLE was initialized to 0, and this invalid */
/*           value is returned to the caller. */

	    setmsg_(__global_state, "The file '#' does not exist.", (ftnlen)
		    28);
	    errch_(__global_state, "#", locfnm, (ftnlen)1, (ftnlen)255);
	    sigerr_(__global_state, "SPICE(FILENOTFOUND)", (ftnlen)19);
	    chkout_(__global_state, "ZZDDHOPN", (ftnlen)8);
	    return 0;
	}

/*        Now if the file was not found in the file table, and it is */
/*        attached to a unit, this presents a problem. */

	if (! locfnd && inqopn) {

/*           Get the unit to include in the error message. */

	    ioin__1.inerr = 1;
	    ioin__1.infilen = 255;
	    ioin__1.infile = locfnm;
	    ioin__1.inex = 0;
	    ioin__1.inopen = 0;
	    ioin__1.innum = &loclun;
	    ioin__1.innamed = 0;
	    ioin__1.inname = 0;
	    ioin__1.inacc = 0;
	    ioin__1.inseq = 0;
	    ioin__1.indir = 0;
	    ioin__1.infmt = 0;
	    ioin__1.inform = 0;
	    ioin__1.inunf = 0;
	    ioin__1.inrecl = 0;
	    ioin__1.innrec = 0;
	    ioin__1.inblank = 0;
	    iostat = f_inqu(&__global_state->f2c, &ioin__1);

/*           Since we performed a very similar INQUIRE statement in */
/*           ZZDDHF2H, a non-zero IOSTAT value indicates a severe error. */

	    if (iostat != 0) {

/*              Recall HANDLE was initialized to 0, and this invalid */
/*              value is returned to the caller. */

		setmsg_(__global_state, "INQUIRE failed.", (ftnlen)15);
		sigerr_(__global_state, "SPICE(BUG)", (ftnlen)10);
		chkout_(__global_state, "ZZDDHOPN", (ftnlen)8);
		return 0;
	    }

/*           Signal the error. Recall HANDLE was initialized to 0, and */
/*           this invalid value is returned to the caller. */

	    setmsg_(__global_state, "The file '#' is already connected to un"
		    "it #.", (ftnlen)44);
	    errch_(__global_state, "#", locfnm, (ftnlen)1, (ftnlen)255);
	    errint_(__global_state, "#", &loclun, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(IMPROPEROPEN)", (ftnlen)19);
	    chkout_(__global_state, "ZZDDHOPN", (ftnlen)8);
	    return 0;
	}

/*        Lastly check to see if the file in the file table, and */
/*        perform the appropriate sanity checks. */

	if (locfnd) {
	    i__1 = abs(inqhan);
	    findex = bsrchi_(__global_state, &i__1, &__state->nft, 
		    __state->ftabs);

/*           Check to see if the requested architecture does not match */
/*           that of the entry in the file table. */

	    if (filarc != __state->ftarc[(i__1 = findex - 1) < 5000 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftarc", i__1, 
		    "zzddhman_", (ftnlen)912)]) {

/*              Recall HANDLE was initialized to 0, and this invalid */
/*              value is returned to the caller. */

		setmsg_(__global_state, "The attempt to load file '#' as a #"
			" has failed because it is already loaded as a #.", (
			ftnlen)83);
		errch_(__global_state, "#", locfnm, (ftnlen)1, (ftnlen)255);
		errch_(__global_state, "#", __state->strarc + (((i__1 = 
			filarc - 1) < 2 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "strarc", i__1, "zzddhman_", (
			ftnlen)922)) << 3), (ftnlen)1, (ftnlen)8);
		errch_(__global_state, "#", __state->strarc + (((i__2 = 
			__state->ftarc[(i__1 = findex - 1) < 5000 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftarc", 
			i__1, "zzddhman_", (ftnlen)923)] - 1) < 2 && 0 <= 
			i__2 ? i__2 : s_rnge(&__global_state->f2c, "strarc", 
			i__2, "zzddhman_", (ftnlen)923)) << 3), (ftnlen)1, (
			ftnlen)8);
		sigerr_(__global_state, "SPICE(FILARCMISMATCH)", (ftnlen)21);
		chkout_(__global_state, "ZZDDHOPN", (ftnlen)8);
		return 0;
	    }

/*           Check to see if the access method is anything other */
/*           than READ.  If so, signal the appropriate error. */
/*           Note: this is only for READ. */

	    if (accmet != 1) {

/*              Recall HANDLE was initialized to 0, and this invalid */
/*              value is returned to the caller. */

		setmsg_(__global_state, "File '#' already loaded.", (ftnlen)
			24);
		errch_(__global_state, "#", locfnm, (ftnlen)1, (ftnlen)255);
		sigerr_(__global_state, "SPICE(FILEOPENCONFLICT)", (ftnlen)23)
			;
		chkout_(__global_state, "ZZDDHOPN", (ftnlen)8);
		return 0;
	    }

/*           If we reach here, then we have a file that exists */
/*           in the table, and the caller is attempting to load it */
/*           for READ access.  Check to make certain it is not */
/*           already loaded with another method. */

	    if (accmet != __state->ftamh[(i__1 = findex - 1) < 5000 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftamh", i__1, 
		    "zzddhman_", (ftnlen)955)]) {

/*              Recall HANDLE was initialized to 0, and this invalid */
/*              value is returned to the caller. */

		setmsg_(__global_state, "Unable to load file '#' for # acces"
			"s.  It is already loaded with the conflicting access"
			" #.", (ftnlen)90);
		errch_(__global_state, "#", locfnm, (ftnlen)1, (ftnlen)255);
		errch_(__global_state, "#", __state->stramh + (((i__1 = 
			accmet - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "stramh", i__1, "zzddhman_", (
			ftnlen)965)) << 3), (ftnlen)1, (ftnlen)8);
		errch_(__global_state, "#", __state->stramh + (((i__2 = 
			__state->ftamh[(i__1 = findex - 1) < 5000 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftamh", 
			i__1, "zzddhman_", (ftnlen)966)] - 1) < 4 && 0 <= 
			i__2 ? i__2 : s_rnge(&__global_state->f2c, "stramh", 
			i__2, "zzddhman_", (ftnlen)966)) << 3), (ftnlen)1, (
			ftnlen)8);
		sigerr_(__global_state, "SPICE(RWCONFLICT)", (ftnlen)17);
		chkout_(__global_state, "ZZDDHOPN", (ftnlen)8);
		return 0;
	    }

/*           If we make it this far, the file is in the file table */
/*           and all the sanity checks have passed. Return to the */
/*           caller as this is effectively a no-op. */

	    *handle = __state->fthan[(i__1 = findex - 1) < 5000 && 0 <= i__1 ?
		     i__1 : s_rnge(&__global_state->f2c, "fthan", i__1, "zzd"
		    "dhman_", (ftnlen)978)];
	    chkout_(__global_state, "ZZDDHOPN", (ftnlen)8);
	    return 0;
	}
    }

/*     Now check to see if there is room in the file table for this */
/*     new file. */

    if (__state->nft == 5000) {

/*        Recall HANDLE was initialized to 0, and this invalid */
/*        value is returned to the caller. */

	setmsg_(__global_state, "The file table is full, with # entries. As "
		"a result, the file '#' could not be loaded.", (ftnlen)86);
	errint_(__global_state, "#", &__state->nft, (ftnlen)1);
	errch_(__global_state, "#", locfnm, (ftnlen)1, (ftnlen)255);
	sigerr_(__global_state, "SPICE(FTFULL)", (ftnlen)13);
	chkout_(__global_state, "ZZDDHOPN", (ftnlen)8);
	return 0;
    }

/*     We are about to attempt a HANDLE to LUN connection, increment */
/*     the request counter. */

    zzddhrcm_(__global_state, &__state->nut, __state->utcst, &__state->reqcnt)
	    ;

/*     Free up a logical unit in the UNIT table for our usage. */

    zzddhgtu_(__global_state, __state->utcst, __state->uthan, __state->utlck, 
	    __state->utlun, &__state->nut, &uindex);

/*     Check FAILED() since ZZDDHGTU may have invoked GETLUN. */
/*     Recall HANDLE was initialized to 0, and this invalid */
/*     value is returned to the caller. */

    if (failed_(__global_state)) {
	chkout_(__global_state, "ZZDDHOPN", (ftnlen)8);
	return 0;
    }

/*     Trim up the filename. */

    if (accmet != 3) {
	lchar = rtrim_(__global_state, locfnm, (ftnlen)255);
    }

/*     If we have made it this far, then we're ready to perform the */
/*     appropriate open.  First get the handle ready. */

    ++__state->next;

/*     Determine the sign of the new handle based on the requested */
/*     METHOD. */

    if (accmet == 1) {
	__state->uthan[(i__1 = uindex - 1) < 23 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "uthan", i__1, "zzddhman_", (ftnlen)1047)
		] = __state->next;
    } else {
	__state->uthan[(i__1 = uindex - 1) < 23 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "uthan", i__1, "zzddhman_", (ftnlen)1049)
		] = -__state->next;
    }

/*     The code that follows is structured a little strangely.  This */
/*     discussion is an attempt to clarify what the code does and */
/*     the motivation that led to its peculiar construction. */

/*     First, the file, scratch or otherwise, is opened with the */
/*     appropriate OPEN statement.  Then, the logical ERROR is set */
/*     to TRUE or FALSE depending on whether and IOSTAT error has */
/*     occurred as a result of the OPEN.  At this point, the code */
/*     enters into a IF block structured in the following manner: */

/*        IF ( ERROR ) THEN */

/*           Signal the IOSTAT related error from the OPEN statement. */

/*        ELSE IF ( ACCMET .EQ SCRTCH ) THEN */

/*           Attempt to INQUIRE on the UNIT assigned to the scratch */
/*           file to determine its name.  Store a default value, */
/*           in the event one is not returned. */

/*        ELSE IF ( ACCMET .EQ. READ ) .OR. ( ACCMET .EQ. WRITE ) THEN */

/*           Examine the preexisting file to determine if its FTP */
/*           detection string, file architecture, and binary */
/*           file format are acceptable.  If not, then signal the */
/*           error, set ERROR to TRUE, and do not check out or */
/*           return. */

/*        END IF */

/*        IF ( ERROR ) THEN */

/*           Remove the UNIT from the unit table. Decrement NEXT, */
/*           since the current value is not to be assigned as */
/*           a handle for this file. Check out and return. */

/*        END IF */

/*     The reason the code is structured in this unusual fashion */
/*     is to allow for a single treatment of the clean up on error */
/*     code to exist. */


/*     Perform the OPEN.  Branch on the appropriate access method. */

    if (accmet == 3) {
	o__1.oerr = 1;
	o__1.ounit = __state->utlun[(i__1 = uindex - 1) < 23 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "utlun", i__1, "zzddhman_"
		, (ftnlen)1101)];
	o__1.ofnm = 0;
	o__1.orl = 1024;
	o__1.osta = "SCRATCH";
	o__1.oacc = "DIRECT";
	o__1.ofm = 0;
	o__1.oblnk = 0;
	iostat = f_open(&__global_state->f2c, &o__1);
	bff = __state->natbff;
    } else if (accmet == 4) {
	o__1.oerr = 1;
	o__1.ounit = __state->utlun[(i__1 = uindex - 1) < 23 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "utlun", i__1, "zzddhman_"
		, (ftnlen)1111)];
	o__1.ofnmlen = lchar;
	o__1.ofnm = locfnm;
	o__1.orl = 1024;
	o__1.osta = "NEW";
	o__1.oacc = "DIRECT";
	o__1.ofm = 0;
	o__1.oblnk = 0;
	iostat = f_open(&__global_state->f2c, &o__1);
	bff = __state->natbff;
    } else if (accmet == 1) {
	o__1.oerr = 1;
	o__1.ounit = __state->utlun[(i__1 = uindex - 1) < 23 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "utlun", i__1, "zzddhman_"
		, (ftnlen)1122)];
	o__1.ofnmlen = lchar;
	o__1.ofnm = locfnm;
	o__1.orl = 1024;
	o__1.osta = "OLD";
	o__1.oacc = "DIRECT";
	o__1.ofm = 0;
	o__1.oblnk = 0;
	iostat = f_open(&__global_state->f2c, &o__1);
    } else if (accmet == 2) {
	o__1.oerr = 1;
	o__1.ounit = __state->utlun[(i__1 = uindex - 1) < 23 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "utlun", i__1, "zzddhman_"
		, (ftnlen)1131)];
	o__1.ofnmlen = lchar;
	o__1.ofnm = locfnm;
	o__1.orl = 1024;
	o__1.osta = "OLD";
	o__1.oacc = "DIRECT";
	o__1.ofm = 0;
	o__1.oblnk = 0;
	iostat = f_open(&__global_state->f2c, &o__1);
    }

/*     Verify that IOSTAT is non-zero. */

    error = iostat != 0;

/*     Partially process the error. */

    if (error) {

/*        Now signal the error, but delay cleaning up and checking */
/*        out until leaving this IF block. */

	if (accmet == 3) {
	    setmsg_(__global_state, "Attempt to open scratch file failed. IO"
		    "STAT was #.", (ftnlen)50);
	} else if (accmet == 4) {
	    setmsg_(__global_state, "Attempt to create new file, '$' failed."
		    " IOSTAT was #.", (ftnlen)53);
	} else {
	    setmsg_(__global_state, "Attempt to open file, '$' for % access "
		    "failed. IOSTAT was #.", (ftnlen)60);
	}
	errch_(__global_state, "$", locfnm, (ftnlen)1, (ftnlen)255);
	errch_(__global_state, "%", __state->stramh + (((i__1 = accmet - 1) < 
		4 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "stramh",
		 i__1, "zzddhman_", (ftnlen)1166)) << 3), (ftnlen)1, (ftnlen)
		8);
	errint_(__global_state, "#", &iostat, (ftnlen)1);
	sigerr_(__global_state, "SPICE(FILEOPENFAIL)", (ftnlen)19);

/*     If no IOSTAT based error has occurred as a result of the OPEN */
/*     statement, then perform any remaining checks or I/O operations */
/*     that are necessary to support loading the file. */

    } else if (accmet == 3) {

/*        Inquire on the logical unit to produce the file name for */
/*        the scratch file.  Set the initial value of LOCFNM, in case */
/*        the INQUIRE does not replace it. */

	s_copy(&__global_state->f2c, locfnm, "# SCRATCH FILE", (ftnlen)255, (
		ftnlen)14);
	repmc_(__global_state, locfnm, "#", __state->strarc + (((i__1 = 
		filarc - 1) < 2 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "strarc", i__1, "zzddhman_", (ftnlen)
		1183)) << 3), locfnm, (ftnlen)255, (ftnlen)1, (ftnlen)8, (
		ftnlen)255);
	ioin__1.inerr = 1;
	ioin__1.inunit = __state->utlun[(i__1 = uindex - 1) < 23 && 0 <= i__1 
		? i__1 : s_rnge(&__global_state->f2c, "utlun", i__1, "zzddhm"
		"an_", (ftnlen)1185)];
	ioin__1.infile = 0;
	ioin__1.inex = 0;
	ioin__1.inopen = 0;
	ioin__1.innum = 0;
	ioin__1.innamed = 0;
	ioin__1.innamlen = 255;
	ioin__1.inname = locfnm;
	ioin__1.inacc = 0;
	ioin__1.inseq = 0;
	ioin__1.indir = 0;
	ioin__1.infmt = 0;
	ioin__1.inform = 0;
	ioin__1.inunf = 0;
	ioin__1.inrecl = 0;
	ioin__1.innrec = 0;
	ioin__1.inblank = 0;
	iostat = f_inqu(&__global_state->f2c, &ioin__1);

/*        In the event that this INQUIRE failed, replace the value */
/*        stored in LOCFNM with the initial value. */

	if (iostat != 0) {
	    s_copy(&__global_state->f2c, locfnm, "# SCRATCH FILE", (ftnlen)
		    255, (ftnlen)14);
	    repmc_(__global_state, locfnm, "#", __state->strarc + (((i__1 = 
		    filarc - 1) < 2 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "strarc", i__1, "zzddhman_", (ftnlen)
		    1196)) << 3), locfnm, (ftnlen)255, (ftnlen)1, (ftnlen)8, (
		    ftnlen)255);
	}

/*        Store the RTRIM value of this filename in LCHAR. */

	lchar = rtrim_(__global_state, locfnm, (ftnlen)255);
    } else if (accmet == 1 || accmet == 2) {

/*        Check for FTP errors, verify that FILARC is appropriate, */
/*        and determine the binary file format of the preexisting */
/*        file LOCFNM. */

	zzddhppf_(__global_state, &__state->utlun[(i__1 = uindex - 1) < 23 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "utlun", i__1,
		 "zzddhman_", (ftnlen)1213)], &filarc, &bff);

/*        Set ERROR. */

	error = failed_(__global_state);

/*        If no error has occurred, verify that BFF is among the */
/*        list of supported format ID codes for the requested access */
/*        method. */

	if (! error) {

/*           This platform supports reading from files whose */
/*           format codes are listed in SUPBFF. */

	    if (accmet == 1) {
		supidx = isrchi_(__global_state, &bff, &__state->numsup, 
			__state->supbff);
		if (supidx == 0) {

/*                 Delay clean up and check out. */

		    error = TRUE_;
		    if (bff == 0) {
			setmsg_(__global_state, "Attempt to open file, '#', "
				"for read access has failed.  This file utili"
				"zes an unknown binary file format.  This err"
				"or may result from attempting to open a corr"
				"upt file or one of an unknown type.", (ftnlen)
				194);
			errch_(__global_state, "#", locfnm, (ftnlen)1, (
				ftnlen)255);
			sigerr_(__global_state, "SPICE(UNSUPPORTEDBFF)", (
				ftnlen)21);
		    } else {
			setmsg_(__global_state, "Attempt to open file, '#', "
				"for read access has failed.  The non-native "
				"binary file format '#' is not currently supp"
				"orted on this platform.  Obtain a transfer f"
				"ormat version, and convert it to the native "
				"format. See the Convert User's Guide for det"
				"ails.", (ftnlen)252);
			errch_(__global_state, "#", locfnm, (ftnlen)1, (
				ftnlen)255);
			errch_(__global_state, "#", __state->strbff + (((i__1 
				= bff - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "strbff", i__1, "zzddhm"
				"an_", (ftnlen)1266)) << 3), (ftnlen)1, (
				ftnlen)8);
			sigerr_(__global_state, "SPICE(UNSUPPORTEDBFF)", (
				ftnlen)21);
		    }
		}

/*           This platform only supports writing to files whose */
/*           binary formats are native. */

	    } else {

/*              Delay clean up and check out. */

		if (bff == 0) {
		    error = TRUE_;
		    setmsg_(__global_state, "Attempt to open file, '#', for "
			    "write access has failed.  This file utilizes an "
			    "unknown binary file format.  This error may resu"
			    "lt from attempting to open a corrupt file or one"
			    " of an unknown type.", (ftnlen)195);
		    errch_(__global_state, "#", locfnm, (ftnlen)1, (ftnlen)
			    255);
		    sigerr_(__global_state, "SPICE(UNSUPPORTEDBFF)", (ftnlen)
			    21);
		} else if (bff != __state->natbff) {
		    error = TRUE_;
		    setmsg_(__global_state, "Attempt to open file, '#', for "
			    "write access has failed.  This file utilizes the"
			    " non-native binary file format '#'.  At this tim"
			    "e only files of the native format, '#', are supp"
			    "orted for write access.  See the Convert User's "
			    "Guide for details.", (ftnlen)241);
		    errch_(__global_state, "#", locfnm, (ftnlen)1, (ftnlen)
			    255);
		    errch_(__global_state, "#", __state->strbff + (((i__1 = 
			    bff - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "strbff", i__1, "zzddhman_", 
			    (ftnlen)1310)) << 3), (ftnlen)1, (ftnlen)8);
		    errch_(__global_state, "#", __state->strbff + (((i__1 = 
			    __state->natbff - 1) < 4 && 0 <= i__1 ? i__1 : 
			    s_rnge(&__global_state->f2c, "strbff", i__1, 
			    "zzddhman_", (ftnlen)1311)) << 3), (ftnlen)1, (
			    ftnlen)8);
		    sigerr_(__global_state, "SPICE(UNSUPPORTEDBFF)", (ftnlen)
			    21);
		}
	    }
	}
    }

/*     If an error has occurred as a result of opening the file or */
/*     examining its contents, clean up and check out. */

    if (error) {

/*        Close the unit we were using.  Remember to delete the file */
/*        if it was a 'new' one. */

	if (accmet == 4) {
	    cl__1.cerr = 0;
	    cl__1.cunit = __state->utlun[(i__1 = uindex - 1) < 23 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "utlun", i__1, 
		    "zzddhman_", (ftnlen)1333)];
	    cl__1.csta = "DELETE";
	    f_clos(&__global_state->f2c, &cl__1);
	} else {
	    cl__1.cerr = 0;
	    cl__1.cunit = __state->utlun[(i__1 = uindex - 1) < 23 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "utlun", i__1, 
		    "zzddhman_", (ftnlen)1335)];
	    cl__1.csta = 0;
	    f_clos(&__global_state->f2c, &cl__1);
	}

/*        Remove the unit from the unit table, since this UNIT */
/*        is no longer in use. */

	zzddhrmu_(__global_state, &uindex, &__state->nft, __state->utcst, 
		__state->uthan, __state->utlck, __state->utlun, &__state->nut)
		;

/*        Decrement NEXT since this handle was never assigned to */
/*        a file. */

	--__state->next;

/*        Recall HANDLE was initialized to 0, and this invalid */
/*        value is returned to the caller. */

	chkout_(__global_state, "ZZDDHOPN", (ftnlen)8);
	return 0;
    }

/*     Finish filling out the unit table. */

    __state->utcst[(i__1 = uindex - 1) < 23 && 0 <= i__1 ? i__1 : s_rnge(&
	    __global_state->f2c, "utcst", i__1, "zzddhman_", (ftnlen)1363)] = 
	    __state->reqcnt;

/*     Only scratch files get the units locked to handles, this is */
/*     because they only exist as long as they have a unit. */

    __state->utlck[(i__1 = uindex - 1) < 23 && 0 <= i__1 ? i__1 : s_rnge(&
	    __global_state->f2c, "utlck", i__1, "zzddhman_", (ftnlen)1369)] = 
	    accmet == 3;

/*     Now fill out the file table. */

    ++__state->nft;

/*     Use the absolute value of the handle used to index the file */
/*     table. */

    __state->ftabs[(i__1 = __state->nft - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftabs", i__1, "zzddhman_", (ftnlen)
	    1380)] = (i__3 = __state->uthan[(i__2 = uindex - 1) < 23 && 0 <= 
	    i__2 ? i__2 : s_rnge(&__global_state->f2c, "uthan", i__2, "zzddh"
	    "man_", (ftnlen)1380)], abs(i__3));

/*     Assign access method, file architecture, and native binary file */
/*     format to the appropriate columns. */

    __state->ftamh[(i__1 = __state->nft - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftamh", i__1, "zzddhman_", (ftnlen)
	    1386)] = accmet;
    __state->ftarc[(i__1 = __state->nft - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftarc", i__1, "zzddhman_", (ftnlen)
	    1387)] = filarc;
    __state->ftbff[(i__1 = __state->nft - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftbff", i__1, "zzddhman_", (ftnlen)
	    1388)] = bff;

/*     Assign the handle, filename, RTRIM ( FTNAM(NFT) ) as FTRTM, and */
/*     unique DP number as FTMNM. */

    __state->fthan[(i__1 = __state->nft - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "fthan", i__1, "zzddhman_", (ftnlen)
	    1394)] = __state->uthan[(i__2 = uindex - 1) < 23 && 0 <= i__2 ? 
	    i__2 : s_rnge(&__global_state->f2c, "uthan", i__2, "zzddhman_", (
	    ftnlen)1394)];
    s_copy(&__global_state->f2c, __state->ftnam + ((i__1 = __state->nft - 1) <
	     5000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftnam", 
	    i__1, "zzddhman_", (ftnlen)1395)) * 255, locfnm, (ftnlen)255, 
	    lchar);
    __state->ftrtm[(i__1 = __state->nft - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftrtm", i__1, "zzddhman_", (ftnlen)
	    1396)] = lchar;
    __state->ftmnm[(i__1 = __state->nft - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftmnm", i__1, "zzddhman_", (ftnlen)
	    1397)] = mnm;

/*     Assign HANDLE the value of the new handle. */

    *handle = __state->fthan[(i__1 = __state->nft - 1) < 5000 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "fthan", i__1, "zzddhman_", (
	    ftnlen)1402)];
    chkout_(__global_state, "ZZDDHOPN", (ftnlen)8);
    return 0;
/* $Procedure ZZDDHCLS ( Private --- Close file ) */

L_zzddhcls:
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Close the file associated with HANDLE. */

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

/*     None. */

/* $ Keywords */

/*     DAF */
/*     DAS */
/*     PRIVATE */

/* $ Declarations */

/*     INTEGER               HANDLE */
/*     CHARACTER*(*)         ARCH */
/*     LOGICAL               KILL */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   File handle associated with the file to close. */
/*     ARCH       I   Expected architecture of the handle to close. */
/*     KILL       I   Logical indicating whether to delete the file. */

/* $ Detailed_Input */

/*     HANDLE     is the file handle associated with the file that is */
/*                to be closed. */

/*     ARCH       is the expected architecture of the file associated */
/*                with HANDLE. */

/*     KILL       is a logical that indicates whether to kill the file */
/*                associated with HANDLE.  Essentially it performs: */

/*                   CLOSE ( UNIT, STATUS = 'DELETE') */

/*                on the file.  This only works if HANDLE is currently */
/*                assigned a UNIT in the UNIT table. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) SPICE(FILARCMISMATCH) is signaled if the specified architecture */
/*        does not match the one listed in the file table. */

/*     2) SPICE(INVALIDACCESS) is signaled if KILL is set to .TRUE., and */
/*        HANDLE is associated with a file open for READ access. */

/*     3) SPICE(FILENOTCONNECTED) is signaled if KILL is set to .TRUE., */
/*        and the file associated with handle is not currently in the */
/*        unit table.  The file is removed from the file table (closed) */
/*        as a result, even if this error is signaled. */

/*     4) If HANDLE is not found in the file table, this routine simply */
/*        returns to the caller. */

/* $ Files */

/*     This routine will close the file associated with HANDLE if it */
/*     is currently utilizing a logical unit. */

/* $ Particulars */

/*     This routine closes files in the file table and performs */
/*     any necessary operations to facilitate the proper disconnect */
/*     from any logical unit. */

/*     This routine may also be used to delete a file that is open */
/*     for write access if it currently has an entry in the UNIT table. */

/* $ Examples */

/*     See DAFCLS or DASLLC. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     F.S. Turner     (JPL) */
/*     B.V. Semenov    (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.1.0, 26-APR-2012 (BVS) */

/*        Updated for the new "magic number" column in the file table. */

/* -    SPICELIB Version 2.0.0, 02-APR-2001 (FST) */

/*        Added a "KILL" argument to the argument list of the routine. */
/*        This will allow certain raw close statements to be replaced */
/*        with calls to ZZDDHCLS. */

/* -    SPICELIB Version 1.0.0, 06-NOV-2001 (FST) */

/* -& */

/* $ Revisions */

/* -    SPICELIB Version 2.0.0, 02-APR-2002 (FST) */

/*        Added the error SPICE(FILENOTCONNECTED) since the KILL */
/*        functionality is only required in the entry points: */

/*            DASFM - DASOPN, DASONW */
/*            DAFAH - DAFOPN, DAFONW */

/*        These routines open new files, so they reference newly */
/*        created handles that have entries in the UNIT table. Thus */
/*        the decision was made to signal the error */
/*        SPICE(FILENOTCONNECTED) rather than connect a file not */
/*        present in the unit table when KILL is set. */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "ZZDDHCLS", (ftnlen)8);
    }

/*     Do the initialization tasks. */

    if (__state->first) {
	zzddhini_(__global_state, &__state->natbff, __state->supbff, &
		__state->numsup, __state->stramh, __state->strarc, 
		__state->strbff, (ftnlen)8, (ftnlen)8, (ftnlen)8);

/*        Check FAILED() only to trap the possibility of ZZDDHINI */
/*        signaling SPICE(BUG). */

	if (failed_(__global_state)) {
	    chkout_(__global_state, "ZZDDHCLS", (ftnlen)8);
	    return 0;
	}

/*        Clear FIRST since we've done the initialization. */

	__state->first = FALSE_;
    }

/*     Find the file in the handle table. */

    i__1 = abs(*handle);
    findex = bsrchi_(__global_state, &i__1, &__state->nft, __state->ftabs);

/*     Check to see whether we found the handle or not. */

    if (findex == 0) {
	chkout_(__global_state, "ZZDDHCLS", (ftnlen)8);
	return 0;
    } else if (__state->fthan[(i__1 = findex - 1) < 5000 && 0 <= i__1 ? i__1 :
	     s_rnge(&__global_state->f2c, "fthan", i__1, "zzddhman_", (ftnlen)
	    1620)] != *handle) {
	chkout_(__global_state, "ZZDDHCLS", (ftnlen)8);
	return 0;
    }

/*     Before actually closing the file, check the input architecture */
/*     matches that listed in the file table for this handle.  This is */
/*     to prevent one architecture's code from stepping on anothers. */

    s_copy(&__global_state->f2c, tmpstr, arch, (ftnlen)8, arch_len);
    ucase_(__global_state, tmpstr, tmpstr, (ftnlen)8, (ftnlen)8);
    filarc = isrchc_(__global_state, tmpstr, &__state->c__2, __state->strarc, 
	    (ftnlen)8, (ftnlen)8);

/*     Check to see if FILARC matches the code stored in the FTARC */
/*     column of the file table for this handle.  If it doesn't, */
/*     signal an error. */

    if (filarc != __state->ftarc[(i__1 = findex - 1) < 5000 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "ftarc", i__1, "zzddhman_", (
	    ftnlen)1639)]) {
	setmsg_(__global_state, "Logical unit associated with # file $, is t"
		"rying to be closed by routines in in the % system.", (ftnlen)
		93);
	errch_(__global_state, "#", __state->strarc + (((i__2 = 
		__state->ftarc[(i__1 = findex - 1) < 5000 && 0 <= i__1 ? i__1 
		: s_rnge(&__global_state->f2c, "ftarc", i__1, "zzddhman_", (
		ftnlen)1644)] - 1) < 2 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "strarc", i__2, "zzddhman_", (ftnlen)
		1644)) << 3), (ftnlen)1, (ftnlen)8);
	errch_(__global_state, "%", tmpstr, (ftnlen)1, (ftnlen)8);
	errch_(__global_state, "$", __state->ftnam + ((i__1 = findex - 1) < 
		5000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftn"
		"am", i__1, "zzddhman_", (ftnlen)1646)) * 255, (ftnlen)1, (
		ftnlen)255);
	sigerr_(__global_state, "SPICE(FILARCMISMATCH)", (ftnlen)21);
	chkout_(__global_state, "ZZDDHCLS", (ftnlen)8);
	return 0;
    }

/*     Now check that if KILL is set, the file is accessible for */
/*     WRITE. */

    if (*kill && __state->ftamh[(i__1 = findex - 1) < 5000 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "ftamh", i__1, "zzddhman_", (
	    ftnlen)1657)] == 1) {
	setmsg_(__global_state, "# file $ is open for READ access.  Attempt "
		"to close and delete file has failed. ", (ftnlen)80);
	errch_(__global_state, "#", __state->strarc + (((i__2 = 
		__state->ftarc[(i__1 = findex - 1) < 5000 && 0 <= i__1 ? i__1 
		: s_rnge(&__global_state->f2c, "ftarc", i__1, "zzddhman_", (
		ftnlen)1661)] - 1) < 2 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "strarc", i__2, "zzddhman_", (ftnlen)
		1661)) << 3), (ftnlen)1, (ftnlen)8);
	errch_(__global_state, "#", __state->ftnam + ((i__1 = findex - 1) < 
		5000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftn"
		"am", i__1, "zzddhman_", (ftnlen)1662)) * 255, (ftnlen)1, (
		ftnlen)255);
	sigerr_(__global_state, "SPICE(INVALIDACCESS)", (ftnlen)20);
	chkout_(__global_state, "ZZDDHCLS", (ftnlen)8);
	return 0;
    }

/*     Buffer the access method for HANDLE, since we may need it */
/*     when deciding which close to perform. */

    accmet = __state->ftamh[(i__1 = findex - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftamh", i__1, "zzddhman_", (ftnlen)
	    1673)];

/*     If we reach here, we need to remove the row FINDEX from */
/*     the file table. */

    i__1 = __state->nft;
    for (i__ = findex + 1; i__ <= i__1; ++i__) {
	__state->ftabs[(i__2 = i__ - 2) < 5000 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "ftabs", i__2, "zzddhman_", (ftnlen)1681)
		] = __state->ftabs[(i__3 = i__ - 1) < 5000 && 0 <= i__3 ? 
		i__3 : s_rnge(&__global_state->f2c, "ftabs", i__3, "zzddhman_"
		, (ftnlen)1681)];
	__state->ftamh[(i__2 = i__ - 2) < 5000 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "ftamh", i__2, "zzddhman_", (ftnlen)1682)
		] = __state->ftamh[(i__3 = i__ - 1) < 5000 && 0 <= i__3 ? 
		i__3 : s_rnge(&__global_state->f2c, "ftamh", i__3, "zzddhman_"
		, (ftnlen)1682)];
	__state->ftarc[(i__2 = i__ - 2) < 5000 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "ftarc", i__2, "zzddhman_", (ftnlen)1683)
		] = __state->ftarc[(i__3 = i__ - 1) < 5000 && 0 <= i__3 ? 
		i__3 : s_rnge(&__global_state->f2c, "ftarc", i__3, "zzddhman_"
		, (ftnlen)1683)];
	__state->ftbff[(i__2 = i__ - 2) < 5000 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "ftbff", i__2, "zzddhman_", (ftnlen)1684)
		] = __state->ftbff[(i__3 = i__ - 1) < 5000 && 0 <= i__3 ? 
		i__3 : s_rnge(&__global_state->f2c, "ftbff", i__3, "zzddhman_"
		, (ftnlen)1684)];
	__state->fthan[(i__2 = i__ - 2) < 5000 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "fthan", i__2, "zzddhman_", (ftnlen)1685)
		] = __state->fthan[(i__3 = i__ - 1) < 5000 && 0 <= i__3 ? 
		i__3 : s_rnge(&__global_state->f2c, "fthan", i__3, "zzddhman_"
		, (ftnlen)1685)];
	s_copy(&__global_state->f2c, __state->ftnam + ((i__2 = i__ - 2) < 
		5000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftn"
		"am", i__2, "zzddhman_", (ftnlen)1686)) * 255, __state->ftnam 
		+ ((i__3 = i__ - 1) < 5000 && 0 <= i__3 ? i__3 : s_rnge(&
		__global_state->f2c, "ftnam", i__3, "zzddhman_", (ftnlen)1686)
		) * 255, (ftnlen)255, (ftnlen)255);
	__state->ftrtm[(i__2 = i__ - 2) < 5000 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "ftrtm", i__2, "zzddhman_", (ftnlen)1687)
		] = __state->ftrtm[(i__3 = i__ - 1) < 5000 && 0 <= i__3 ? 
		i__3 : s_rnge(&__global_state->f2c, "ftrtm", i__3, "zzddhman_"
		, (ftnlen)1687)];
	__state->ftmnm[(i__2 = i__ - 2) < 5000 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "ftmnm", i__2, "zzddhman_", (ftnlen)1688)
		] = __state->ftmnm[(i__3 = i__ - 1) < 5000 && 0 <= i__3 ? 
		i__3 : s_rnge(&__global_state->f2c, "ftmnm", i__3, "zzddhman_"
		, (ftnlen)1688)];
    }
    --__state->nft;

/*     Locate HANDLE in the unit table. */

    uindex = isrchi_(__global_state, handle, &__state->nut, __state->uthan);
    if (uindex != 0) {

/*        Close the unit. */

	if (*kill && accmet != 3) {
	    cl__1.cerr = 0;
	    cl__1.cunit = __state->utlun[(i__1 = uindex - 1) < 23 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "utlun", i__1, 
		    "zzddhman_", (ftnlen)1705)];
	    cl__1.csta = "DELETE";
	    f_clos(&__global_state->f2c, &cl__1);
	} else {
	    cl__1.cerr = 0;
	    cl__1.cunit = __state->utlun[(i__1 = uindex - 1) < 23 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "utlun", i__1, 
		    "zzddhman_", (ftnlen)1707)];
	    cl__1.csta = 0;
	    f_clos(&__global_state->f2c, &cl__1);
	}

/*        Remove its entry from the unit table. */

	zzddhrmu_(__global_state, &uindex, &__state->nft, __state->utcst, 
		__state->uthan, __state->utlck, __state->utlun, &__state->nut)
		;
    } else {

/*        First, check to see if KILL is set, if it is signal an error */
/*        since we are unable to delete the file. */

	if (*kill && accmet != 3) {
	    setmsg_(__global_state, "File successfully closed.  Unable to de"
		    "lete file as requested.  File not currently present in t"
		    "he UNIT table. ", (ftnlen)110);
	    sigerr_(__global_state, "SPICE(FILENOTCONNECTED)", (ftnlen)23);
	    chkout_(__global_state, "ZZDDHCLS", (ftnlen)8);
	    return 0;
	}

/*        If we were unable to find the HANDLE in the unit table, */
/*        check to see if we have to clean up the UNIT table. */

	if (__state->nft < __state->nut) {
	    uindex = isrchi_(__global_state, &__state->c__0, &__state->nut, 
		    __state->uthan);

/*           Now check to see if we located a zero valued handle. */
/*           If we did not manage to, then this is an error condition, */
/*           since we have more LUNs listed in the unit table than */
/*           files in the file table. */

	    if (uindex == 0) {
		setmsg_(__global_state, "There are less files in the file ta"
			"ble than units in the unit table, and no row with a "
			"zero-valued handle can be found.  This should never "
			"occur.", (ftnlen)145);
		sigerr_(__global_state, "SPICE(BUG)", (ftnlen)10);
		chkout_(__global_state, "ZZDDHCLS", (ftnlen)8);
		return 0;
	    }

/*           Free the unit. */

	    frelun_(__global_state, &__state->utlun[(i__1 = uindex - 1) < 23 
		    && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "utlun"
		    , i__1, "zzddhman_", (ftnlen)1759)]);

/*           Compress the table. */

	    i__1 = __state->nut;
	    for (i__ = uindex + 1; i__ <= i__1; ++i__) {
		__state->utcst[(i__2 = i__ - 2) < 23 && 0 <= i__2 ? i__2 : 
			s_rnge(&__global_state->f2c, "utcst", i__2, "zzddhma"
			"n_", (ftnlen)1766)] = __state->utcst[(i__3 = i__ - 1) 
			< 23 && 0 <= i__3 ? i__3 : s_rnge(&
			__global_state->f2c, "utcst", i__3, "zzddhman_", (
			ftnlen)1766)];
		__state->uthan[(i__2 = i__ - 2) < 23 && 0 <= i__2 ? i__2 : 
			s_rnge(&__global_state->f2c, "uthan", i__2, "zzddhma"
			"n_", (ftnlen)1767)] = __state->uthan[(i__3 = i__ - 1) 
			< 23 && 0 <= i__3 ? i__3 : s_rnge(&
			__global_state->f2c, "uthan", i__3, "zzddhman_", (
			ftnlen)1767)];
		__state->utlck[(i__2 = i__ - 2) < 23 && 0 <= i__2 ? i__2 : 
			s_rnge(&__global_state->f2c, "utlck", i__2, "zzddhma"
			"n_", (ftnlen)1768)] = __state->utlck[(i__3 = i__ - 1) 
			< 23 && 0 <= i__3 ? i__3 : s_rnge(&
			__global_state->f2c, "utlck", i__3, "zzddhman_", (
			ftnlen)1768)];
		__state->utlun[(i__2 = i__ - 2) < 23 && 0 <= i__2 ? i__2 : 
			s_rnge(&__global_state->f2c, "utlun", i__2, "zzddhma"
			"n_", (ftnlen)1769)] = __state->utlun[(i__3 = i__ - 1) 
			< 23 && 0 <= i__3 ? i__3 : s_rnge(&
			__global_state->f2c, "utlun", i__3, "zzddhman_", (
			ftnlen)1769)];
	    }

/*           Decrement NUT. */

	    --__state->nut;
	}
    }
    chkout_(__global_state, "ZZDDHCLS", (ftnlen)8);
    return 0;
/* $Procedure ZZDDHHLU ( Private --- Handle to Logical Unit ) */

L_zzddhhlu:
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Return the logical unit associated with a handle, in the event */
/*     the handle is not connected to a unit, connect it to one. */

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

/*     None. */

/* $ Keywords */

/*     DAS */
/*     DAF */
/*     PRIVATE */

/* $ Declarations */

/*     INTEGER               HANDLE */
/*     CHARACTER*(*)         ARCH */
/*     LOGICAL               LOCK */
/*     INTEGER               UNIT */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle associated with the file of interest. */
/*     ARCH       I   Expected file architecture. */
/*     LOCK       I   Logical indicating to lock UNIT to HANDLE. */
/*     UNIT       O   Corresponding logical unit. */

/* $ Detailed_Input */

/*     HANDLE     is the handle associated with the file to retrieve a */
/*                logical unit. */

/*     ARCH       is the expected file architecture of the file */
/*                associated with HANDLE. */

/*     LOCK       is a logical that indicates whether the UNIT should be */
/*                locked to HANDLE.  Locked units will keep the files */
/*                open and assigned the same logical unit.  They may */
/*                only be unlocked by calling ZZDDHUNL. */

/* $ Detailed_Output */

/*     UNIT       is the logical unit that is currently assigned to */
/*                HANDLE.  This unit may be used to perform I/O */
/*                operations on the file. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) The error SPICE(NOSUCHHANDLE) is signaled when HANDLE is not */
/*        found in the file table.  The value of UNIT is undefined when */
/*        this error occurs. */

/*     2) The error SPICE(FILARCMISMATCH) is signaled if the specified */
/*        architecture does not match the one listed for HANDLE in the */
/*        file table.  The value of UNIT is undefined when this error */
/*        occurs. */

/*     3) SPICE(FILEOPENFAIL) is signaled only when an attempt to */
/*        attach a logical unit to the file associated with HANDLE */
/*        fails.  The value of UNIT is undefined when this error */
/*        occurs. */

/*     4) The error SPICE(HLULOCKFAILED) is signaled when the input */
/*        LOCK logical has a value of TRUE, and there are no free */
/*        'lockable' units left in the unit table.  The value of UNIT */
/*        returned when this error is signaled is undefined. */

/* $ Files */

/*     If HANDLE refers to a file not currently connected to a logical */
/*     unit, this routine will locate an entry in the unit table; */
/*     disconnect it if necessary; and connect the file associated with */
/*     HANDLE in its place. */

/* $ Particulars */

/*     This routine is used to retrieve a logical unit for a desired */
/*     handle.  It also serves as a mechanism for locking the UNIT */
/*     to HANDLE relationship for a particular handle.  This routine */
/*     can not be used to unlock this relationship.  See ZZDDHUNL for */
/*     that functionality. */

/* $ Examples */

/*     See DAFHLU or DASHLU for sample usage. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     F.S. Turner     (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 06-NOV-2001 (FST) */


/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "ZZDDHHLU", (ftnlen)8);
    }

/*     Do the initialization tasks. */

    if (__state->first) {
	zzddhini_(__global_state, &__state->natbff, __state->supbff, &
		__state->numsup, __state->stramh, __state->strarc, 
		__state->strbff, (ftnlen)8, (ftnlen)8, (ftnlen)8);

/*        Check FAILED() only to trap the possibility of ZZDDHINI */
/*        signaling SPICE(BUG). */

	if (failed_(__global_state)) {
	    *unit = 0;
	    chkout_(__global_state, "ZZDDHHLU", (ftnlen)8);
	    return 0;
	}

/*        Clear FIRST since we've done the initialization. */

	__state->first = FALSE_;
    }

/*     Locate HANDLE in the file table. */

    i__1 = abs(*handle);
    findex = bsrchi_(__global_state, &i__1, &__state->nft, __state->ftabs);
    if (findex == 0) {
	error = TRUE_;
    } else if (__state->fthan[(i__1 = findex - 1) < 5000 && 0 <= i__1 ? i__1 :
	     s_rnge(&__global_state->f2c, "fthan", i__1, "zzddhman_", (ftnlen)
	    1974)] != *handle) {
	error = TRUE_;
    } else {
	error = FALSE_;
    }
    if (error) {
	*unit = 0;
	setmsg_(__global_state, "There is no file loaded with handle = #", (
		ftnlen)39);
	errint_(__global_state, "#", handle, (ftnlen)1);
	sigerr_(__global_state, "SPICE(NOSUCHHANDLE)", (ftnlen)19);
	chkout_(__global_state, "ZZDDHHLU", (ftnlen)8);
	return 0;
    }

/*     Before actually fetching the unit, check the input architecture */
/*     matches that listed in the file table for this handle.  This is */
/*     to prevent one architectures code from stepping on anothers. */

    s_copy(&__global_state->f2c, tmpstr, arch, (ftnlen)8, arch_len);
    ucase_(__global_state, tmpstr, tmpstr, (ftnlen)8, (ftnlen)8);
    filarc = isrchc_(__global_state, tmpstr, &__state->c__2, __state->strarc, 
	    (ftnlen)8, (ftnlen)8);

/*     Check to see if FILARC matches the code stored in the FTARC */
/*     column of the file table for this handle.  If it doesn't, */
/*     signal an error. */

    if (filarc != __state->ftarc[(i__1 = findex - 1) < 5000 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "ftarc", i__1, "zzddhman_", (
	    ftnlen)2005)]) {
	*unit = 0;
	setmsg_(__global_state, "Logical unit associated with # file $, is t"
		"rying to be unlocked by routines in in the % system.", (
		ftnlen)95);
	errch_(__global_state, "#", __state->strarc + (((i__2 = 
		__state->ftarc[(i__1 = findex - 1) < 5000 && 0 <= i__1 ? i__1 
		: s_rnge(&__global_state->f2c, "ftarc", i__1, "zzddhman_", (
		ftnlen)2012)] - 1) < 2 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "strarc", i__2, "zzddhman_", (ftnlen)
		2012)) << 3), (ftnlen)1, (ftnlen)8);
	errch_(__global_state, "%", tmpstr, (ftnlen)1, (ftnlen)8);
	errch_(__global_state, "$", __state->ftnam + ((i__1 = findex - 1) < 
		5000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftn"
		"am", i__1, "zzddhman_", (ftnlen)2014)) * 255, (ftnlen)1, (
		ftnlen)255);
	sigerr_(__global_state, "SPICE(FILARCMISMATCH)", (ftnlen)21);
	chkout_(__global_state, "ZZDDHHLU", (ftnlen)8);
	return 0;
    }

/*     If we make it this far, then we will be processing a handle */
/*     to logical unit request.  Increment REQCNT. */

    zzddhrcm_(__global_state, &__state->nut, __state->utcst, &__state->reqcnt)
	    ;

/*     Now check to see if the handle is already present in the */
/*     unit table. */

    uindex = isrchi_(__global_state, handle, &__state->nut, __state->uthan);

/*     Check to see if we didn't locate the HANDLE in the table. */
/*     If we didn't, open the file associated with HANDLE again, */
/*     and get it into the unit table. */

    if (uindex == 0) {

/*        We need a unit from the unit table, get one. */

	zzddhgtu_(__global_state, __state->utcst, __state->uthan, 
		__state->utlck, __state->utlun, &__state->nut, &uindex);

/*        Check FAILED, since ZZDDHGTU may have invoked GETLUN. */

	if (failed_(__global_state)) {
	    *unit = 0;
	    chkout_(__global_state, "ZZDDHHLU", (ftnlen)8);
	    return 0;
	}

/*        Re-attach the file to a logical unit.  Branch based on the */
/*        access method stored in the file table. */

	if (__state->ftamh[(i__1 = findex - 1) < 5000 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "ftamh", i__1, "zzddhman_", (
		ftnlen)2060)] == 4 || __state->ftamh[(i__2 = findex - 1) < 
		5000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "fta"
		"mh", i__2, "zzddhman_", (ftnlen)2060)] == 2) {
	    o__1.oerr = 1;
	    o__1.ounit = __state->utlun[(i__1 = uindex - 1) < 23 && 0 <= i__1 
		    ? i__1 : s_rnge(&__global_state->f2c, "utlun", i__1, 
		    "zzddhman_", (ftnlen)2063)];
	    o__1.ofnmlen = __state->ftrtm[(i__3 = findex - 1) < 5000 && 0 <= 
		    i__3 ? i__3 : s_rnge(&__global_state->f2c, "ftrtm", i__3, 
		    "zzddhman_", (ftnlen)2063)];
	    o__1.ofnm = __state->ftnam + ((i__2 = findex - 1) < 5000 && 0 <= 
		    i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftnam", i__2, 
		    "zzddhman_", (ftnlen)2063)) * 255;
	    o__1.orl = 1024;
	    o__1.osta = "OLD";
	    o__1.oacc = "DIRECT";
	    o__1.ofm = 0;
	    o__1.oblnk = 0;
	    iostat = f_open(&__global_state->f2c, &o__1);
	} else if (__state->ftamh[(i__1 = findex - 1) < 5000 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "ftamh", i__1, "zzddhman_"
		, (ftnlen)2070)] == 1) {
	    o__1.oerr = 1;
	    o__1.ounit = __state->utlun[(i__1 = uindex - 1) < 23 && 0 <= i__1 
		    ? i__1 : s_rnge(&__global_state->f2c, "utlun", i__1, 
		    "zzddhman_", (ftnlen)2072)];
	    o__1.ofnmlen = __state->ftrtm[(i__3 = findex - 1) < 5000 && 0 <= 
		    i__3 ? i__3 : s_rnge(&__global_state->f2c, "ftrtm", i__3, 
		    "zzddhman_", (ftnlen)2072)];
	    o__1.ofnm = __state->ftnam + ((i__2 = findex - 1) < 5000 && 0 <= 
		    i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftnam", i__2, 
		    "zzddhman_", (ftnlen)2072)) * 255;
	    o__1.orl = 1024;
	    o__1.osta = "OLD";
	    o__1.oacc = "DIRECT";
	    o__1.ofm = 0;
	    o__1.oblnk = 0;
	    iostat = f_open(&__global_state->f2c, &o__1);
	} else {
	    *unit = 0;
	    setmsg_(__global_state, "Invalid access method.  This error shou"
		    "ld never be signalled.", (ftnlen)61);
	    sigerr_(__global_state, "SPICE(BUG)", (ftnlen)10);
	    chkout_(__global_state, "ZZDDHHLU", (ftnlen)8);
	    return 0;
	}

/*        Check IOSTAT for troubles. */

	if (iostat != 0) {

/*           The re-open was unsuccessful, leave the entry in the file */
/*           table and clean up the row in the unit table before */
/*           returning.  Normally when we call ZZDDHRMU it is to */
/*           remove a unit from the unit table.  In this case we */
/*           know the unit will remain since we have not decreased */
/*           the entries in the file table. */

	    zzddhrmu_(__global_state, &uindex, &__state->nft, __state->utcst, 
		    __state->uthan, __state->utlck, __state->utlun, &
		    __state->nut);

/*           Now signal the error. */

	    *unit = 0;
	    setmsg_(__global_state, "Attempt to reconnect logical unit to fi"
		    "le '#' failed. IOSTAT was #.", (ftnlen)67);
	    errch_(__global_state, "#", __state->ftnam + ((i__1 = findex - 1) 
		    < 5000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "ftnam", i__1, "zzddhman_", (ftnlen)2113)) * 255, (ftnlen)
		    1, (ftnlen)255);
	    errint_(__global_state, "#", &iostat, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(FILEOPENFAIL)", (ftnlen)19);
	    chkout_(__global_state, "ZZDDHHLU", (ftnlen)8);
	    return 0;
	}

/*        Lastly populate the unit table values. */

	__state->uthan[(i__1 = uindex - 1) < 23 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "uthan", i__1, "zzddhman_", (ftnlen)2124)
		] = __state->fthan[(i__2 = findex - 1) < 5000 && 0 <= i__2 ? 
		i__2 : s_rnge(&__global_state->f2c, "fthan", i__2, "zzddhman_"
		, (ftnlen)2124)];
	__state->utlck[(i__1 = uindex - 1) < 23 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "utlck", i__1, "zzddhman_", (ftnlen)2125)
		] = FALSE_;
    }

/*     At this point UINDEX points to the row in the unit table that */
/*     contains the connection information.  We need to update the cost */
/*     row with the new value of REQCNT, and then set the lock row to */
/*     TRUE if a lock request was made. */

    __state->utcst[(i__1 = uindex - 1) < 23 && 0 <= i__1 ? i__1 : s_rnge(&
	    __global_state->f2c, "utcst", i__1, "zzddhman_", (ftnlen)2135)] = 
	    __state->reqcnt;
    if (*lock && ! __state->utlck[(i__1 = uindex - 1) < 23 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "utlck", i__1, "zzddhman_", (
	    ftnlen)2137)]) {

/*        First check to see if we have enough lockable units */
/*        left in the unit table. */

	locked = zzddhclu_(__global_state, __state->utlck, &__state->nut);
	if (locked >= 20) {
	    *unit = 0;
	    setmsg_(__global_state, "Unable to lock handle for file '#' to a"
		    " logical unit.  There are no rows available for locking "
		    "in the unit table.", (ftnlen)113);
	    errch_(__global_state, "#", __state->ftnam + ((i__1 = findex - 1) 
		    < 5000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "ftnam", i__1, "zzddhman_", (ftnlen)2152)) * 255, (ftnlen)
		    1, (ftnlen)255);
	    sigerr_(__global_state, "SPICE(HLULOCKFAILED)", (ftnlen)20);
	    chkout_(__global_state, "ZZDDHHLU", (ftnlen)8);
	    return 0;
	}
	__state->utlck[(i__1 = uindex - 1) < 23 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "utlck", i__1, "zzddhman_", (ftnlen)2159)
		] = TRUE_;
    }

/*     Set the value of UNIT and return. */

    *unit = __state->utlun[(i__1 = uindex - 1) < 23 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "utlun", i__1, "zzddhman_", (ftnlen)
	    2166)];
    chkout_(__global_state, "ZZDDHHLU", (ftnlen)8);
    return 0;
/* $Procedure ZZDDHUNL ( Private --- Unlock Logical Unit from Handle ) */

L_zzddhunl:
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Unlock a logical unit from the specified handle. */

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

/*     None. */

/* $ Keywords */

/*     DAS */
/*     DAF */
/*     PRIVATE */

/* $ Declarations */

/*     INTEGER               HANDLE */
/*     CHARACTER*(*)         ARCH */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   File handle assigned to the file to unlock. */
/*     ARCH       I   Expected architecture of the handle to unlock. */

/* $ Detailed_Input */

/*     HANDLE     is the file handle associated with the file that */
/*                is to have its logicial unit lock released. */

/*     ARCH       is the expected architecture of the file associated */
/*                with HANDLE. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If HANDLE is 0, not found in the unit table, or found and */
/*        not currently locked, this routine just returns to the */
/*        caller. */

/*     2) SPICE(FILARCMISMATCH) is signaled if the specified architecture */
/*        does not match the one listed in the file table. */

/*     3) If HANDLE is associated with a scratch file, this routine */
/*        simply returns, as scratch files may not be unlocked from */
/*        their logical units. */

/* $ Files */

/*     This routine does not explicitly alter the open or closed */
/*     state of the file associated with HANDLE. */

/* $ Particulars */

/*     This routine allows users to unlock a handle from it's logical */
/*     unit in the event a handle to logical unit request was made */
/*     with the LOCK argument set to true.  (DAFHLU and DASHLU both */
/*     lock units, and require a call to this routine to unlock them). */

/* $ Examples */

/*     See some routine that calls this one (TBD). */

/* $ Restrictions */

/*     This routine utilizes discovery check in and out.  However, */
/*     routines in the initialization loop may signal the error */
/*     SPICE(BUG) under the conditions of the existence of a bug. */
/*     Since this routine utilizes discovery check in and out, */
/*     no check in or out is performed around the initialization */
/*     block.  This is by design. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     F.S. Turner     (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 06-NOV-2001 (FST) */


/* -& */

/*     Standard SPICE discovery error handling. */

    if (return_(__global_state)) {
	return 0;
    }

/*     Do the initialization tasks. */

    if (__state->first) {
	zzddhini_(__global_state, &__state->natbff, __state->supbff, &
		__state->numsup, __state->stramh, __state->strarc, 
		__state->strbff, (ftnlen)8, (ftnlen)8, (ftnlen)8);

/*        Check FAILED() only to trap the possibility of ZZDDHINI */
/*        signaling SPICE(BUG).  No check out is performed, see the */
/*        $Restrictions section of the entry point header for details. */

	if (failed_(__global_state)) {
	    return 0;
	}

/*        Clear FIRST since we've done the initialization. */

	__state->first = FALSE_;
    }

/*     Prevent the user from locating zero handle rows.  This is not */
/*     really necessary since zero handle rows in the unit table are */
/*     empty and awaiting connections.  The state of the UTLCK is */
/*     not significant. */

    if (*handle == 0) {
	return 0;
    }

/*     Look up the handle in the unit table. */

    uindex = isrchi_(__global_state, handle, &__state->nut, __state->uthan);

/*     Now check the results of the lookup.  If HANDLE was not found */
/*     in the unit table or the unit was not locked, just return as */
/*     there is nothing to do. */

    if (uindex == 0) {
	return 0;
    } else if (! __state->utlck[(i__1 = uindex - 1) < 23 && 0 <= i__1 ? i__1 :
	     s_rnge(&__global_state->f2c, "utlck", i__1, "zzddhman_", (ftnlen)
	    2354)]) {
	return 0;
    }

/*     Now look up the handle in the table. Remember FTABS is a sorted */
/*     list in increasing order. */

    i__1 = abs(*handle);
    findex = bsrchi_(__global_state, &i__1, &__state->nft, __state->ftabs);

/*     Check to see if HANDLE is in the file table.  We know it has */
/*     to be since it is in the unit table if we make it this far. */
/*     These checks are just for safety's sake. */

    if (findex == 0) {
	chkin_(__global_state, "ZZDDHUNL", (ftnlen)8);
	setmsg_(__global_state, "HANDLE # was not found in the file table bu"
		"t was located in the unit table.  This error should never oc"
		"cur.", (ftnlen)107);
	errint_(__global_state, "#", handle, (ftnlen)1);
	sigerr_(__global_state, "SPICE(BUG)", (ftnlen)10);
	chkout_(__global_state, "ZZDDHUNL", (ftnlen)8);
	return 0;
    } else if (__state->fthan[(i__1 = findex - 1) < 5000 && 0 <= i__1 ? i__1 :
	     s_rnge(&__global_state->f2c, "fthan", i__1, "zzddhman_", (ftnlen)
	    2380)] != *handle) {
	chkin_(__global_state, "ZZDDHUNL", (ftnlen)8);
	setmsg_(__global_state, "HANDLE # was not found in the file table bu"
		"t was located in the unit table.  This error should never oc"
		"cur.", (ftnlen)107);
	errint_(__global_state, "#", handle, (ftnlen)1);
	sigerr_(__global_state, "SPICE(BUG)", (ftnlen)10);
	chkout_(__global_state, "ZZDDHUNL", (ftnlen)8);
	return 0;
    }

/*     Before actually unlocking the unit, check the input architecture */
/*     matches that listed in the file table for this handle.  This is */
/*     to prevent one architectures code from stepping on anothers. */

    s_copy(&__global_state->f2c, tmpstr, arch, (ftnlen)8, arch_len);
    ucase_(__global_state, tmpstr, tmpstr, (ftnlen)8, (ftnlen)8);
    filarc = isrchc_(__global_state, tmpstr, &__state->c__2, __state->strarc, 
	    (ftnlen)8, (ftnlen)8);

/*     Check to see if FILARC matches the code stored in the FTARC */
/*     column of the file table for this handle.  If it doesn't, */
/*     signal an error. */

    if (filarc != __state->ftarc[(i__1 = findex - 1) < 5000 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "ftarc", i__1, "zzddhman_", (
	    ftnlen)2407)]) {
	chkin_(__global_state, "ZZDDHUNL", (ftnlen)8);
	setmsg_(__global_state, "Logical unit associated with # file $, is t"
		"rying to be unlocked by routines in in the % system.", (
		ftnlen)95);
	errch_(__global_state, "#", __state->strarc + (((i__2 = 
		__state->ftarc[(i__1 = findex - 1) < 5000 && 0 <= i__1 ? i__1 
		: s_rnge(&__global_state->f2c, "ftarc", i__1, "zzddhman_", (
		ftnlen)2413)] - 1) < 2 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "strarc", i__2, "zzddhman_", (ftnlen)
		2413)) << 3), (ftnlen)1, (ftnlen)8);
	errch_(__global_state, "%", tmpstr, (ftnlen)1, (ftnlen)8);
	errch_(__global_state, "$", __state->ftnam + ((i__1 = findex - 1) < 
		5000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftn"
		"am", i__1, "zzddhman_", (ftnlen)2415)) * 255, (ftnlen)1, (
		ftnlen)255);
	sigerr_(__global_state, "SPICE(FILARCMISMATCH)", (ftnlen)21);
	chkout_(__global_state, "ZZDDHUNL", (ftnlen)8);
	return 0;
    }

/*     Lastly, check to see if the access method for HANDLE indicates */
/*     scratch access.  If it is, just return, since scratch files */
/*     can not have their units unlocked. */

    if (__state->ftamh[(i__1 = findex - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftamh", i__1, "zzddhman_", (ftnlen)
	    2427)] == 3) {
	return 0;
    }
    __state->utlck[(i__1 = uindex - 1) < 23 && 0 <= i__1 ? i__1 : s_rnge(&
	    __global_state->f2c, "utlck", i__1, "zzddhman_", (ftnlen)2431)] = 
	    FALSE_;
    return 0;
/* $Procedure ZZDDHNFO ( Private --- Get information about a Handle ) */

L_zzddhnfo:
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Get information about the file attached to HANDLE. */

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

/*     None. */

/* $ Keywords */

/*     DAF */
/*     DAS */
/*     PRIVATE */

/* $ Declarations */

/*     INTEGER               HANDLE */
/*     CHARACTER*(*)         FNAME */
/*     INTEGER               INTARC */
/*     INTEGER               INTBFF */
/*     INTEGER               INTAMH */
/*     LOGICAL               FOUND */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   File handle assigned to file of interest. */
/*     FNAME      O   Name of the file associated with HANDLE. */
/*     INTARC     O   Integer code for FNAME's file architecture. */
/*     INTBFF     O   Integer code for FNAME's binary file format. */
/*     INTAMH     O   Integer code for FNAME's access method. */
/*     FOUND      O   Logical that indicates if HANDLE was found. */

/* $ Detailed_Input */

/*     HANDLE     is the file handle associated with the file for which */
/*                information is requested. */

/* $ Detailed_Output */

/*     FNAME      is the name of the file used associated with HANDLE. */
/*                This is the name used to load the file originally. */

/*     INTARC     is an integer code for FNAME's file architecture. */
/*                See the include file 'zzddhman.inc' for particulars. */
/*                The following are possible outputs: */

/*                   DAS - Direct Access, Segregated File Architecture */
/*                   DAF - Double Precision Array File Architecture */

/*     INTBFF     is an integer code that represents FNAME's binary */
/*                file format.  See the include file 'zzddhman.inc' for */
/*                particulars.  The following are the possible outputs: */

/*                   BIGI3E - Big Endian IEEE Floating Point Format */
/*                   LTLI3E - Little Endian IEEE Floating Point Format */
/*                   VAXGFL - VAX G-Float Format */
/*                   VAXDFL - VAX D-Float Format */

/*     INTAMH     is an integer code that represents FNAME's access */
/*                method.  See the include file 'zzddhman.inc' for */
/*                particulars.  The following are possible outputs: */

/*                   READ   - File was loaded for read access */
/*                   WRITE  - File was loaded for read/write access */
/*                   NEW    - New file was created for read/write access */
/*                   SCRTCH - Scratch file created for read/write access */

/*     FOUND      is a logical if set to TRUE indicates that HANDLE */
/*                was located in the file table.  Otherwise, it was */
/*                not found in the table. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/*     1) If FOUND is FALSE, then the other output arguments */
/*        are undefined. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine provides access to information necessary for */
/*     translation and other I/O based tasks to modules that are */
/*     not entry points to this handle manager. */

/* $ Examples */

/*     See ZZDAFGFR, ZZDAFGSR, or ZZDAFGDR for sample usage. */

/* $ Restrictions */

/*     Routines in the call tree of this routine may signal the error */
/*     SPICE(BUG) under the conditions of the existence of a bug */
/*     in routines the initialization loop invokes.  Since this */
/*     routine is error free with the exception of this bug condition, */
/*     it does not participate in tracing by design. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     F.S. Turner     (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 06-NOV-2001 (FST) */


/* -& */

/*     Do the initialization tasks. */

    if (__state->first) {
	zzddhini_(__global_state, &__state->natbff, __state->supbff, &
		__state->numsup, __state->stramh, __state->strarc, 
		__state->strbff, (ftnlen)8, (ftnlen)8, (ftnlen)8);

/*        Check FAILED(), and return on failure.  We are not checking */
/*        out or in since this routine would be error free if not for */
/*        the possibility of ZZDDHINI signaling SPICE(BUG).  See */
/*        $Restrictions for details. */

	if (failed_(__global_state)) {
	    return 0;
	}

/*        Clear FIRST since we've done the initialization. */

	__state->first = FALSE_;
    }

/*     Look up the handle in the table.  Remember FTABS is sorted */
/*     listed in increasing order. */

    i__1 = abs(*handle);
    findex = bsrchi_(__global_state, &i__1, &__state->nft, __state->ftabs);

/*     Check to see if HANDLE is in the handle table.  Remember that */
/*     we are indexing the table using the absolute value of handle. */
/*     So include a check to see that HANDLE is FTHAN(FINDEX). */

    if (findex == 0) {
	s_copy(&__global_state->f2c, fname, " ", fname_len, (ftnlen)1);
	*intarc = 0;
	*intbff = 0;
	*intamh = 0;
	*found = FALSE_;
	return 0;
    } else if (__state->fthan[(i__1 = findex - 1) < 5000 && 0 <= i__1 ? i__1 :
	     s_rnge(&__global_state->f2c, "fthan", i__1, "zzddhman_", (ftnlen)
	    2635)] != *handle) {
	s_copy(&__global_state->f2c, fname, " ", fname_len, (ftnlen)1);
	*intarc = 0;
	*intbff = 0;
	*intamh = 0;
	*found = FALSE_;
	return 0;
    }

/*     If we make it this far, then we have a handle that is in */
/*     the handle table at row FINDEX. */

    *found = TRUE_;
    s_copy(&__global_state->f2c, fname, __state->ftnam + ((i__1 = findex - 1) 
	    < 5000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftnam",
	     i__1, "zzddhman_", (ftnlen)2649)) * 255, fname_len, 
	    __state->ftrtm[(i__2 = findex - 1) < 5000 && 0 <= i__2 ? i__2 : 
	    s_rnge(&__global_state->f2c, "ftrtm", i__2, "zzddhman_", (ftnlen)
	    2649)]);
    *intarc = __state->ftarc[(i__1 = findex - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftarc", i__1, "zzddhman_", (ftnlen)
	    2650)];
    *intbff = __state->ftbff[(i__1 = findex - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftbff", i__1, "zzddhman_", (ftnlen)
	    2651)];
    *intamh = __state->ftamh[(i__1 = findex - 1) < 5000 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftamh", i__1, "zzddhman_", (ftnlen)
	    2652)];
    return 0;
/* $Procedure ZZDDHISN ( Private --- Is Handle Native? ) */

L_zzddhisn:
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Determine whether the file attached to HANDLE is uses the */
/*     binary file format native to the system. */

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

/*     None. */

/* $ Keywords */

/*     DAS */
/*     DAF */
/*     PRIVATE */

/* $ Declarations */

/*     INTEGER               HANDLE */
/*     LOGICAL               NATIVE */
/*     LOGICAL               FOUND */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   File handle assigned to file to determine format. */
/*     NATIVE     O   Indicates if the file format is native. */
/*     FOUND      O   Indicates if HANDLE is currently attached to file. */

/* $ Detailed_Input */

/*     HANDLE     is the file handle associated with the file that is */
/*                to be determined to be native or not. */

/* $ Detailed_Output */

/*     NATIVE     is a logical that when set to TRUE indicates that */
/*                the file associated with HANDLE is of the native */
/*                binary file format for the current platform. If */
/*                FALSE, then the file is of an alien file format. */

/*     FOUND      is a logical that when set to TRUE indicates that */
/*                HANDLE was found in the file table and is associated */
/*                with a file.  If FALSE, then NATIVE remains unchanged, */
/*                since the file was not found in the table. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error Free. */

/*     1) In the event that HANDLE can not be found in the file table, */
/*        FOUND is set to FALSE and NATIVE is left unchanged. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine simply answers the question:  "Is the file attached */
/*     to this handle of the native binary file format?" */

/* $ Examples */

/*     See DAFRDA for sample usage. */

/* $ Restrictions */

/*     Routines in the call tree of this routine may signal the error */
/*     SPICE(BUG) under the conditions of the existence of a bug */
/*     in routines the initialization loop invokes.  Since this */
/*     routine is error free with the exception of this bug condition, */
/*     it does not participate in tracing by design. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     F.S. Turner     (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 06-NOV-2001 (FST) */


/* -& */

/*     Do the initialization tasks. */

    if (__state->first) {
	zzddhini_(__global_state, &__state->natbff, __state->supbff, &
		__state->numsup, __state->stramh, __state->strarc, 
		__state->strbff, (ftnlen)8, (ftnlen)8, (ftnlen)8);

/*        Check FAILED(), and return on failure.  We are not checking */
/*        out or in since this routine would be error free if not for */
/*        the possibility of ZZDDHINI signaling SPICE(BUG).  See */
/*        $Restrictions for details. */

	if (failed_(__global_state)) {
	    return 0;
	}

/*        Clear FIRST since we've done the initialization. */

	__state->first = FALSE_;
    }

/*     Look up the handle in the table. Remember FTABS is sorted */
/*     listed in increasing order. */

    i__1 = abs(*handle);
    findex = bsrchi_(__global_state, &i__1, &__state->nft, __state->ftabs);

/*     Check to see if HANDLE is in the handle table.  Remember */
/*     that we are indexing the table using the absolute value of */
/*     handle.  So include a check to see that HANDLE is FTHAN(FINDEX). */

    if (findex == 0) {
	*found = FALSE_;
	return 0;
    } else if (__state->fthan[(i__1 = findex - 1) < 5000 && 0 <= i__1 ? i__1 :
	     s_rnge(&__global_state->f2c, "fthan", i__1, "zzddhman_", (ftnlen)
	    2824)] != *handle) {
	*found = FALSE_;
	return 0;
    }

/*     If we make it this far, then we have found HANDLE in the file */
/*     table.  Set NATIVE appropriately and FOUND to TRUE. */

    *native = __state->natbff == __state->ftbff[(i__1 = findex - 1) < 5000 && 
	    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftbff", i__1, 
	    "zzddhman_", (ftnlen)2833)];
    *found = TRUE_;
    return 0;
/* $Procedure ZZDDHFNH ( Private --- Filename to Handle ) */

L_zzddhfnh:
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Retrieve handle associated with filename. */

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

/*     None. */

/* $ Keywords */

/*     DAF */
/*     DAS */
/*     PRIVATE */

/* $ Declarations */

/*     CHARACTER*(*)         FNAME */
/*     INTEGER               HANDLE */
/*     LOGICAL               FOUND */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     FNAME      I   Name of a file previously loaded with ZZDDHOPN. */
/*     HANDLE     O   Corresponding file handle. */
/*     FOUND      O   Logical indicating whether HANDLE was located. */

/* $ Detailed_Input */

/*     FNAME      is the name of a file previously loaded with ZZDDHOPN. */

/* $ Detailed_Output */

/*     HANDLE     is the handle associated with the file. */

/*     FOUND      is a logical when TRUE indicates HANDLE was located */
/*                for FNAME.  If FALSE no handle was found associated */
/*                with FNAME. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) ZZDDHF2H in the call tree of this routine performs I/O */
/*        functions and may signal errors that are the result of */
/*        I/O failures.  See ZZDDHF2H header for details. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine is provided for completeness and serves only to */
/*     support the DAFFNH and DASFNH interfaces. */

/* $ Examples */

/*     See DAFFNH or DASFNH for sample usage. */

/* $ Restrictions */

/*     1) On VAX environments, this routine may only be used when */
/*        FNAME refers to a DAF or DAS file.  An error may be */
/*        signaled when used with unopened files that utilize other */
/*        architectures. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     F.S. Turner     (JPL) */
/*     B.V. Semenov    (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.1.0, 26-APR-2012 (BVS) */

/*        Updated for the new "magic number" column in the file table. */

/* -    SPICELIB Version 1.0.0, 06-NOV-2001 (FST) */


/* -& */
    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "ZZDDHFNH", (ftnlen)8);
    }

/*     Do the initialization tasks. */

    if (__state->first) {
	zzddhini_(__global_state, &__state->natbff, __state->supbff, &
		__state->numsup, __state->stramh, __state->strarc, 
		__state->strbff, (ftnlen)8, (ftnlen)8, (ftnlen)8);

/*        Check FAILED() only to trap the possibility of ZZDDHINI */
/*        signaling SPICE(BUG). */

	if (failed_(__global_state)) {
	    *handle = 0;
	    chkout_(__global_state, "ZZDDHFNH", (ftnlen)8);
	    return 0;
	}

/*        Clear FIRST since we've done the initialization. */

	__state->first = FALSE_;
    }

/*     Left justify FNAME to trim any leading white space. */

    ljust_(__global_state, fname, locfnm, fname_len, (ftnlen)255);

/*     Look up FNAME in the handle table. */

    zzddhf2h_(__global_state, locfnm, __state->ftabs, __state->ftamh, 
	    __state->ftarc, __state->ftbff, __state->fthan, __state->ftnam, 
	    __state->ftrtm, __state->ftmnm, &__state->nft, __state->utcst, 
	    __state->uthan, __state->utlck, __state->utlun, &__state->nut, &
	    inqext, &inqopn, &inqhan, found, &mnm, (ftnlen)255, (ftnlen)255);

/*     Check found and set HANDLE if we have got one.  No need to */
/*     check FAILED() since ZZDDHF2H returns FOUND set to FALSE on */
/*     error. */

    if (*found) {
	*handle = inqhan;
    } else {
	*handle = 0;
    }
    chkout_(__global_state, "ZZDDHFNH", (ftnlen)8);
    return 0;
/* $Procedure ZZDDHLUH ( Private --- Logical Unit to Handle ) */

L_zzddhluh:
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Return the handle associated with a logical unit. */

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

/*     None. */

/* $ Keywords */

/*     DAS */
/*     DAF */
/*     PRIVATE */

/* $ Declarations */

/*     INTEGER               UNIT */
/*     INTEGER               HANDLE */
/*     LOGICAL               FOUND */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     UNIT       I   Logical unit connected to a file. */
/*     HANDLE     O   Corresponding handle. */
/*     FOUND      O   Logical indicating the handle was located. */

/* $ Detailed_Input */

/*     UNIT       is the logical unit to which a file managed by DDH is */
/*                currently connected. */

/* $ Detailed_Output */

/*     HANDLE     is the handle associated with the logical unit of */
/*                interest. */

/*     FOUND      is a logical flag if TRUE indicates that a HANDLE */
/*                was found associated with UNIT.  If FALSE indicates */
/*                no handle was found for UNIT. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/*     1) If UNIT is not found in the unit table, HANDLE is undefined */
/*        and FOUND is set to .FALSE. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine is provided for completeness and serves only to */
/*     support the DAFLUH and DASLUH interfaces. */

/* $ Examples */

/*     See DAFLUH or DASLUH for usage. */

/* $ Restrictions */

/*     Routines in the call tree of this routine may signal the error */
/*     SPICE(BUG) under the conditions of the existence of a bug */
/*     in routines the initialization loop invokes.  Since this */
/*     routine is error free with the exception of this bug condition, */
/*     it does not participate in tracing by design. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     F.S. Turner     (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 06-NOV-2001 (FST) */


/* -& */

/*     Do the initialization tasks. */

    if (__state->first) {
	zzddhini_(__global_state, &__state->natbff, __state->supbff, &
		__state->numsup, __state->stramh, __state->strarc, 
		__state->strbff, (ftnlen)8, (ftnlen)8, (ftnlen)8);

/*        Check FAILED(), and return on failure.  We are not checking */
/*        out or in since this routine would be error free if not for */
/*        the possibility of ZZDDHINI signaling SPICE(BUG).  See */
/*        $Restrictions for details. */

	if (failed_(__global_state)) {
	    *handle = 0;
	    return 0;
	}

/*        Clear FIRST since we've done the initialization. */

	__state->first = FALSE_;
    }

/*     Look up the unit in the table. */

    uindex = isrchi_(__global_state, unit, &__state->nut, __state->utlun);
    if (uindex == 0) {
	*handle = 0;
	*found = FALSE_;
	return 0;
    } else if (__state->uthan[(i__1 = uindex - 1) < 23 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "uthan", i__1, "zzddhman_", (ftnlen)
	    3183)] == 0) {
	*handle = 0;
	*found = FALSE_;
	return 0;
    }

/*     We've got a handle, store the value and return. */

    *handle = __state->uthan[(i__1 = uindex - 1) < 23 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "uthan", i__1, "zzddhman_", (ftnlen)
	    3192)];
    *found = TRUE_;
    return 0;
} /* zzddhman_ */

/* Subroutine */ int zzddhman_(cspice_t* __global_state, logical *lock, char *
	arch, char *fname, char *method, integer *handle, integer *unit, 
	integer *intamh, integer *intarc, integer *intbff, logical *native, 
	logical *found, logical *kill, ftnlen arch_len, ftnlen fname_len, 
	ftnlen method_len)
{
    return zzddhman_0_(0, lock, arch, fname, method, handle, unit, intamh, 
	    intarc, intbff, native, found, kill, arch_len, fname_len, 
	    method_len);
    }

/* Subroutine */ int zzddhopn_(cspice_t* __global_state, char *fname, char *
	method, char *arch, integer *handle, ftnlen fname_len, ftnlen 
	method_len, ftnlen arch_len)
{
    return zzddhman_0_(1, (logical *)0, arch, fname, method, handle, (integer 
	    *)0, (integer *)0, (integer *)0, (integer *)0, (logical *)0, (
	    logical *)0, (logical *)0, arch_len, fname_len, method_len);
    }

/* Subroutine */ int zzddhcls_(cspice_t* __global_state, integer *handle, 
	char *arch, logical *kill, ftnlen arch_len)
{
    return zzddhman_0_(2, (logical *)0, arch, (char *)0, (char *)0, handle, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (logical *)
	    0, (logical *)0, kill, arch_len, (ftnint)0, (ftnint)0);
    }

/* Subroutine */ int zzddhhlu_(cspice_t* __global_state, integer *handle, 
	char *arch, logical *lock, integer *unit, ftnlen arch_len)
{
    return zzddhman_0_(3, lock, arch, (char *)0, (char *)0, handle, unit, (
	    integer *)0, (integer *)0, (integer *)0, (logical *)0, (logical *)
	    0, (logical *)0, arch_len, (ftnint)0, (ftnint)0);
    }

/* Subroutine */ int zzddhunl_(cspice_t* __global_state, integer *handle, 
	char *arch, ftnlen arch_len)
{
    return zzddhman_0_(4, (logical *)0, arch, (char *)0, (char *)0, handle, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (logical *)
	    0, (logical *)0, (logical *)0, arch_len, (ftnint)0, (ftnint)0);
    }

/* Subroutine */ int zzddhnfo_(cspice_t* __global_state, integer *handle, 
	char *fname, integer *intarc, integer *intbff, integer *intamh, 
	logical *found, ftnlen fname_len)
{
    return zzddhman_0_(5, (logical *)0, (char *)0, fname, (char *)0, handle, (
	    integer *)0, intamh, intarc, intbff, (logical *)0, found, (
	    logical *)0, (ftnint)0, fname_len, (ftnint)0);
    }

/* Subroutine */ int zzddhisn_(cspice_t* __global_state, integer *handle, 
	logical *native, logical *found)
{
    return zzddhman_0_(6, (logical *)0, (char *)0, (char *)0, (char *)0, 
	    handle, (integer *)0, (integer *)0, (integer *)0, (integer *)0, 
	    native, found, (logical *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

/* Subroutine */ int zzddhfnh_(cspice_t* __global_state, char *fname, integer 
	*handle, logical *found, ftnlen fname_len)
{
    return zzddhman_0_(7, (logical *)0, (char *)0, fname, (char *)0, handle, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (logical *)
	    0, found, (logical *)0, (ftnint)0, fname_len, (ftnint)0);
    }

/* Subroutine */ int zzddhluh_(cspice_t* __global_state, integer *unit, 
	integer *handle, logical *found)
{
    return zzddhman_0_(8, (logical *)0, (char *)0, (char *)0, (char *)0, 
	    handle, unit, (integer *)0, (integer *)0, (integer *)0, (logical *
	    )0, found, (logical *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

