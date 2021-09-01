/* spkopa.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int spkopa_state_t;
static spkopa_state_t* get_spkopa_state(cspice_t* state) {
	return 0;
}

/* $Procedure      SPKOPA ( SPK open for addition ) */
/* Subroutine */ int spkopa_(cspice_t* __global_state, char *file, integer *
	handle, ftnlen file_len)
{
    /* Builtin functions */
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    char arch[8];
    char type__[8];
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern logical failed_(cspice_t*);
    extern /* Subroutine */ int getfat_(cspice_t*, char *, char *, char *, 
	    ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int dafopw_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical exists_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    spkopa_state_t* __state = get_spkopa_state(__global_state);
/* $ Abstract */

/*    Open an existing SPK file for subsequent write. */

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

/*     SPK */

/* $ Keywords */

/*     SPK */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     FILE       I   The name of an existing SPK file. */
/*     HANDLE     O   A handle attached to the SPK file opened for write. */

/* $ Detailed_Input */

/*     FILE       is the name of an existing SPK file to which */
/*                you wish to append additional SPK segments. */

/* $ Detailed_Output */

/*     HANDLE     is the DAF handle attached to the file required */
/*                by any of the SPK writing routines.  If any exceptions */
/*                arise that prevent opening of the specified file for */
/*                writing, HANDLE will be returned with the value 0. */

/* $ Parameters */

/*     None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     1)  If the file specified does not exist the error */
/*         'SPICE(FILENOTFOUND)' will be signalled. */

/*     2)  If the file specified is not an SPK file, the error */
/*         'SPICE(FILEISNOTSPK)' will be signalled. */

/*     All other exceptions are determined by routines in the */
/*     call tree of this routine. */

/* $ Particulars */

/*     This file provides an interface for opening existing SPK */
/*     files for the addition of SPK segments.  If you need */
/*     to open an new SPK file for writing, call the routine SPKOPN. */

/* $ Examples */

/*     Suppose you have collected data for a type 05 spk segment and */
/*     wish to place the new segment in an existing SPK file.  The */
/*     code fragment below shows one set of calls that you could perform */
/*     to make the addition.  (Note that you could add segments of */
/*     other data types by replacing the call to SPKW05 with a suitably */
/*     modified call to another SPKWxx routine.) */

/*     We assume that the following variables have already been */
/*     assigned the proper values: */

/*        BODY   (integer)  Body code for ephemeris object. */
/*        CENTER (integer)  Body code for the center of motion */
/*                          of the body. */
/*        FRAME  (string)   The reference frame of the states. */
/*        FIRST  (d.p.)     First valid time for which states can be */
/*                          computed in seconds past 2000. */
/*        LAST   (d.p.)     Last valid time for which states can */
/*                          be computed in seconds past 2000. */
/*        GM     (d.p.)     Gravitational mass of central body. */
/*        N      (integer)  Number of states and epochs. */
/*        STATES (d.p.)     Array of states (x,y,z,dx,dy,dz). */
/*        EPOCHS (d.p.)     Array of epochs (seconds past 2000.) */
/*        SEGID  (string)   Segment identifier */


/*     Begin by opening the file. */

/*     CALL SPKOPA ( FILE, HANDLE ) */

/*     Now add the collected data as a new segment. */

/*     CALL SPKW05 ( HANDLE, BODY,  CENTER, FRAME,  FIRST, LAST, SEGID, */
/*    .              GM,    N,      STATES, EPOCHS      ) */

/*     Finally, close the file. */

/*     CALL SPKCLS ( HANDLE ) */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 10-MAR-1999 (WLT) */


/* -& */
/* $ Index_Entries */

/*     Open an existing SPK file for adding segments */

/* -& */

/*     SPICELIB Functions */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "SPKOPA", (ftnlen)6);

/*     Until we get a legitimate handle we set HANDLE to zero. */

    *handle = 0;

/*     First make sure the file exists. */

    if (! exists_(__global_state, file, file_len)) {
	setmsg_(__global_state, "The file '#' is not recognized as an existi"
		"ng file. ", (ftnlen)52);
	errch_(__global_state, "#", file, (ftnlen)1, file_len);
	sigerr_(__global_state, "SPICE(FILENOTFOUND)", (ftnlen)19);
	chkout_(__global_state, "SPKOPA", (ftnlen)6);
	return 0;
    }

/*     Next make sure it is an SPK file. */

    getfat_(__global_state, file, arch, type__, file_len, (ftnlen)8, (ftnlen)
	    8);
    if (failed_(__global_state)) {
	chkout_(__global_state, "SPKOPA", (ftnlen)6);
	return 0;
    }
    if (s_cmp(&__global_state->f2c, arch, "DAF", (ftnlen)8, (ftnlen)3) != 0 ||
	     s_cmp(&__global_state->f2c, type__, "SPK", (ftnlen)8, (ftnlen)3) 
	    != 0) {
	setmsg_(__global_state, "The file '#' was not an SPK file.  The arch"
		"itecture and type of the file were found to be '#' and '#' r"
		"espectively. ", (ftnlen)116);
	errch_(__global_state, "#", file, (ftnlen)1, file_len);
	errch_(__global_state, "#", arch, (ftnlen)1, (ftnlen)8);
	errch_(__global_state, "#", type__, (ftnlen)1, (ftnlen)8);
	sigerr_(__global_state, "SPICE(FILEISNOTSPK)", (ftnlen)19);
	chkout_(__global_state, "SPKOPA", (ftnlen)6);
	return 0;
    }

/*     That's the limit of the checks performed here.  We let DAFOPW */
/*     handle the remaining checks. */

    dafopw_(__global_state, file, handle, file_len);
    if (failed_(__global_state)) {
	*handle = 0;
    }
    chkout_(__global_state, "SPKOPA", (ftnlen)6);
    return 0;
} /* spkopa_ */

