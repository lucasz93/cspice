/* zzldker.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzldker_init_t __zzldker_init;
static zzldker_state_t* get_zzldker_state(cspice_t* state) {
	if (!state->zzldker)
		state->zzldker = __cspice_allocate_module(sizeof(
	zzldker_state_t), &__zzldker_init, sizeof(__zzldker_init));
	return state->zzldker;

}

/* $Procedure ZZLDKER ( Load a kernel ) */
/* Subroutine */ int zzldker_(cspice_t* __global_state, char *file, char *
	nofile, char *filtyp, integer *handle, ftnlen file_len, ftnlen 
	nofile_len, ftnlen filtyp_len)
{
    /* Builtin functions */
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    char arch[32];
    extern /* Subroutine */ int zzbodkik_(cspice_t*);
    extern /* Subroutine */ int zzdsklsf_(cspice_t*, char *, integer *, 
	    ftnlen);
    extern /* Subroutine */ int eklef_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int cklpf_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    char versn[32];
    extern logical failed_(cspice_t*);
    extern /* Subroutine */ int getfat_(cspice_t*, char *, char *, char *, 
	    ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int pcklof_(cspice_t*, char *, integer *, ftnlen);
    char kerlin[132];
    extern /* Subroutine */ int spklef_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int ldpool_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    char termin[5];
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical exists_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);
    char mytype[32];
    extern /* Subroutine */ int tkvrsn_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int zzascii_(cspice_t*, char *, char *, logical *,
	     char *, ftnlen, ftnlen, ftnlen);


    /* Module state */
    zzldker_state_t* __state = get_zzldker_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Determine the architecture and type of a file and load */
/*     the file into the appropriate SPICE subsystem */

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

/*      None. */

/* $ Keywords */

/*      PRIVATE */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     FILE       I   The name of a file to be loaded. */
/*     NOFILE     I   A message to issue if FILE cannot be located */
/*     FILTYP     O   The type of kernel. */
/*     HANDLE     O   The handle associated with the loaded kernel. */

/* $ Detailed_Input */

/*     FILE       is the name of a file that is anticipated to */
/*                be a SPICE kernel. */

/*     NOFILE     is a template for the message that should be created */
/*                with SETMSG if a problem is identified with FILE. The */
/*                message should have the form: "[text] '#' [text] #" The */
/*                first octothorpe ('#') will be replaced by the name of */
/*                the file. The second by a descriptive message. */

/* $ Detailed_Output */

/*     FILTYP     is the type of the kernel as determined by the */
/*                SPICE file record of the file or by various */
/*                heuristics.  Possible return values are: */

/*                  TEXT   ---  if FILE is interpreted as a text kernel */
/*                              suitable for loading via LDPOOL.  No */
/*                              attempt is made to distinguish between */
/*                              different types of text kernels. */
/*                  SPK   | */
/*                  CK    | */
/*                  PCK   |---  if FILE is a binary PCK file. */
/*                  DSK   | */
/*                  EK    | */

/*                If a failure occurs during the attempt to load */
/*                the FILE, FILTYP will be returned as the blank string. */

/*     HANDLE     is the DAF or DAS handle that is associated with the */
/*                file.  If the FILTYP of the file is 'TEXT', HANDLE */
/*                will be set to zero. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If the specified file does not exist, the error */
/*        SPICE(NOSUCHFILE) will be signaled. */

/*     2) If the specified file can be identified as unloadable */
/*        because it is a transfer format file, the error */
/*        SPICE(TRANSFERFILE) will be signaled. */

/*     3) If the specified file can be identified as unloadable */
/*        because it is an obsolete text E-kernel, the error */
/*        SPICE(TYPE1TEXTEK) will be signaled. */

/*     4) If the specified file can be recognized as a DAF/DAS file */
/*        but is not one of the currently recognized binary kernel */
/*        types, the error SPICE(UNKNOWNKERNELTYPE) will be signaled. */

/*     5) FILTYP is not sufficiently long to hold the full text of the */
/*        type of the kernel, the value returned will be the truncation */
/*        of the value.  As currently implemented this truncated type is */
/*        sufficient to distinguish between the various types of */
/*        kernels. */

/*     6) If the FILE cannot be loaded, HANDLE will be set to zero. */

/*     7) All other problems associated with the loading of FILE */
/*        are diagnosed by the routines called by this routine. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine is intended as a supporting routine for the */
/*     SPICE routine FURNSH.  It handles the task of loading */
/*     an arbitrary kernel without the caller having to specify */
/*     the type of the kernel. */

/* $ Examples */

/*     None.  (After all it's a private routine) */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     W.L. Taber      (JPL) */
/*     E.D. Wright     (JPL) */
/*     B.V. Semenov    (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 20-JAN-2016 (NJB) */

/*        Added ability to load DSK files. */

/* -    SPICELIB Version 1.17.0, 10-MAR-2014 (BVS) */

/*        Updated for SUN-SOLARIS-64BIT-INTEL. */

/* -    SPICELIB Version 1.16.0, 10-MAR-2014 (BVS) */

/*        Updated for PC-LINUX-64BIT-IFORT. */

/* -    SPICELIB Version 1.15.0, 10-MAR-2014 (BVS) */

/*        Updated for PC-CYGWIN-GFORTRAN. */

/* -    SPICELIB Version 1.14.0, 10-MAR-2014 (BVS) */

/*        Updated for PC-CYGWIN-64BIT-GFORTRAN. */

/* -    SPICELIB Version 1.13.0, 13-MAY-2010 (BVS) */

/*        Updated for SUN-SOLARIS-INTEL. */

/* -    SPICELIB Version 1.12.0, 13-MAY-2010 (BVS) */

/*        Updated for PC-WINDOWS-64BIT-IFORT. */

/* -    SPICELIB Version 1.11.0, 13-MAY-2010 (BVS) */

/*        Updated for PC-LINUX-64BIT-GFORTRAN. */

/* -    SPICELIB Version 1.10.0, 13-MAY-2010 (BVS) */

/*        Updated for MAC-OSX-64BIT-IFORT. */

/* -    SPICELIB Version 1.9.0, 13-MAY-2010 (BVS) */

/*        Updated for MAC-OSX-64BIT-GFORTRAN. */

/* -    SPICELIB Version 1.8.0, 18-MAR-2009 (BVS) */

/*        Updated for PC-LINUX-GFORTRAN. */

/* -    SPICELIB Version 1.7.0, 18-MAR-2009 (BVS) */

/*        Updated for MAC-OSX-GFORTRAN. */

/* -    SPICELIB Version 1.6.0, 19-FEB-2008 (BVS) */

/*        Updated for PC-LINUX-IFORT. */

/* -    SPICELIB Version 1.5.0, 14-NOV-2006 (BVS) */

/*        Updated for MAC-OSX-IFORT. */

/* -    SPICELIB Version 1.4.0, 14-NOV-2006 (BVS) */

/*        Updated for PC-WINDOWS-IFORT. */

/* -    SPICELIB Version 1.3.0, 03-OCT-2005 (EDW) */

/*        Source file zzldker.f converted to master file. */
/*        Modification occurred to prevent f2c's versions */
/*        from making the zzascii test. CSPICE now */
/*        includes coed to allow reading of non native text files. */

/* -    SPICELIB Version 1.2.0, 17-FEB-2004 (EDW) (BVS) */

/*        Added the ZZASCII terminator test for text files. Used a */
/*        working line length of 132 characters (maximum text kernel */
/*        line size.) */

/* -    SPICELIB Version 1.1.0, 24-JUN-2002 (EDW) */

/*        Added a call to ZZBODKIK to run the */
/*        NAIF_BODY_NAME/CODE read/check routine */
/*        whenever a text kernel loads. */

/* -    SPICELIB Version 1.0.0, 04-JUN-1999 (WLT) */


/* -& */

/*     SPICELIB Functions */


/*     Local Variables. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "ZZLDKER", (ftnlen)7);
    if (! exists_(__global_state, file, file_len)) {
	setmsg_(__global_state, nofile, nofile_len);
	errch_(__global_state, "#", file, (ftnlen)1, file_len);
	errch_(__global_state, "#", "could not be located.", (ftnlen)1, (
		ftnlen)21);
	sigerr_(__global_state, "SPICE(NOSUCHFILE)", (ftnlen)17);
	chkout_(__global_state, "ZZLDKER", (ftnlen)7);
	return 0;
    }
    getfat_(__global_state, file, arch, mytype, file_len, (ftnlen)32, (ftnlen)
	    32);

/*     Possible values for the architecture are: */

/*        DAF -- The file is based on the DAF architecture. */
/*        DAS -- The file is based on the DAS architecture. */
/*        XFR -- The file is in a SPICE transfer file format. */
/*        DEC -- The file is an old SPICE decimal text file. */
/*        ASC -- An ASCII text file. */
/*        KPL -- Kernel Pool File (i.e., a text kernel) */
/*        TXT -- An ASCII text file. */
/*        TE1 -- Text E-Kernel type 1. */
/*         ?  -- The architecture could not be determined. */

/*     Some of these are obviously losers. */

    if (s_cmp(&__global_state->f2c, arch, "XFR", (ftnlen)32, (ftnlen)3) == 0 
	    || s_cmp(&__global_state->f2c, arch, "DEC", (ftnlen)32, (ftnlen)3)
	     == 0) {
	setmsg_(__global_state, nofile, nofile_len);
	errch_(__global_state, "#", file, (ftnlen)1, file_len);
	errch_(__global_state, "#", "is a transfer format file. Transfer for"
		"mat files cannot be loaded. ", (ftnlen)1, (ftnlen)67);
	sigerr_(__global_state, "SPICE(TRANSFERFILE)", (ftnlen)19);
	chkout_(__global_state, "ZZLDKER", (ftnlen)7);
	return 0;
    } else if (s_cmp(&__global_state->f2c, arch, "TE1", (ftnlen)32, (ftnlen)3)
	     == 0) {
	setmsg_(__global_state, nofile, nofile_len);
	errch_(__global_state, "#", file, (ftnlen)1, file_len);
	errch_(__global_state, "#", "is a type 1 text E-kernel.  These files"
		" are obsolete and cannot be loaded. ", (ftnlen)1, (ftnlen)75);
	sigerr_(__global_state, "SPICE(TYPE1TEXTEK)", (ftnlen)18);
	chkout_(__global_state, "ZZLDKER", (ftnlen)7);
	return 0;
    }

/*     That takes care of the obvious errors.  Try loading the */
/*     kernel. */

    *handle = 0;
    s_copy(&__global_state->f2c, filtyp, " ", filtyp_len, (ftnlen)1);
    if (s_cmp(&__global_state->f2c, arch, "DAF", (ftnlen)32, (ftnlen)3) == 0) 
	    {
	if (s_cmp(&__global_state->f2c, mytype, "SPK", (ftnlen)32, (ftnlen)3) 
		== 0) {
	    spklef_(__global_state, file, handle, file_len);
	} else if (s_cmp(&__global_state->f2c, mytype, "CK", (ftnlen)32, (
		ftnlen)2) == 0) {
	    cklpf_(__global_state, file, handle, file_len);
	} else if (s_cmp(&__global_state->f2c, mytype, "PCK", (ftnlen)32, (
		ftnlen)3) == 0) {
	    pcklof_(__global_state, file, handle, file_len);
	} else {
	    tkvrsn_(__global_state, "TOOLKIT", versn, (ftnlen)7, (ftnlen)32);
	    setmsg_(__global_state, nofile, nofile_len);
	    errch_(__global_state, "#", file, (ftnlen)1, file_len);
	    errch_(__global_state, "#", "is a \"#\" DAF file. This kind of b"
		    "inary file is not supported in version # of the SPICE to"
		    "olkit. Check with NAIF to see if your toolkit version is"
		    " up to date. ", (ftnlen)1, (ftnlen)158);
	    errch_(__global_state, "#", mytype, (ftnlen)1, (ftnlen)32);
	    errch_(__global_state, "#", versn, (ftnlen)1, (ftnlen)32);
	    sigerr_(__global_state, "SPICE(UNKNOWNKERNELTYPE)", (ftnlen)24);
	    chkout_(__global_state, "ZZLDKER", (ftnlen)7);
	    return 0;
	}
	s_copy(&__global_state->f2c, filtyp, mytype, filtyp_len, (ftnlen)32);
    } else if (s_cmp(&__global_state->f2c, arch, "DAS", (ftnlen)32, (ftnlen)3)
	     == 0) {
	if (s_cmp(&__global_state->f2c, mytype, "EK", (ftnlen)32, (ftnlen)2) 
		== 0) {
	    eklef_(__global_state, file, handle, file_len);
	} else if (s_cmp(&__global_state->f2c, mytype, "DSK", (ftnlen)32, (
		ftnlen)3) == 0) {
	    zzdsklsf_(__global_state, file, handle, file_len);
	} else {
	    tkvrsn_(__global_state, "TOOLKIT", versn, (ftnlen)7, (ftnlen)32);
	    setmsg_(__global_state, nofile, nofile_len);
	    errch_(__global_state, "#", file, (ftnlen)1, file_len);
	    errch_(__global_state, "#", "is a \"#\" DAS file.  This kind of "
		    "binary file is not supported in version # of the SPICE t"
		    "oolkit. Check with NAIF to see if your toolkit version i"
		    "s up to date. ", (ftnlen)1, (ftnlen)159);
	    errch_(__global_state, "#", mytype, (ftnlen)1, (ftnlen)32);
	    errch_(__global_state, "#", versn, (ftnlen)1, (ftnlen)32);
	    sigerr_(__global_state, "SPICE(UNKNOWNKERNELTYPE)", (ftnlen)24);
	    chkout_(__global_state, "ZZLDKER", (ftnlen)7);
	    return 0;
	}
	s_copy(&__global_state->f2c, filtyp, mytype, filtyp_len, (ftnlen)32);
    } else {

/*        Check for line terminator compatibility with this platform. */
/*        .TRUE. means that ZZASCII will compare terminator */
/*        detected with the one native to this platform and will */
/*        stop if they don't match. */

	zzascii_(__global_state, file, kerlin, &__state->c_true, termin, 
		file_len, (ftnlen)132, (ftnlen)5);

/*        Load the file using the text file loader. */

	ldpool_(__global_state, file, file_len);
	if (! failed_(__global_state)) {
	    s_copy(&__global_state->f2c, filtyp, "TEXT", filtyp_len, (ftnlen)
		    4);

/*           Cause the kernel pool mechanism to perform */
/*           the standard error checks on the pool */
/*           data. */

	    zzbodkik_(__global_state);
	}
    }
    chkout_(__global_state, "ZZLDKER", (ftnlen)7);
    return 0;
} /* zzldker_ */

