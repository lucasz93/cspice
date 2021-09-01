/* spkcls.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int spkcls_state_t;
static spkcls_state_t* get_spkcls_state(cspice_t* state) {
	return 0;
}

/* $Procedure SPKCLS ( SPK, Close file ) */
/* Subroutine */ int spkcls_(cspice_t* __global_state, integer *handle)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    logical found;
    extern /* Subroutine */ int daffna_(cspice_t*, logical *);
    extern logical failed_(cspice_t*);
    extern /* Subroutine */ int dafbfs_(cspice_t*, integer *);
    extern /* Subroutine */ int dafcls_(cspice_t*, integer *);
    char access[5];
    extern /* Subroutine */ int errhan_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    spkcls_state_t* __state = get_spkcls_state(__global_state);
/* $ Abstract */

/*     Close an open SPK file. */

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
/*     HANDLE     I   Handle of the SPK file to be closed. */

/* $ Detailed_Input */

/*     HANDLE   The handle of the SPK file that is to be closed. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If there are no segments in the file the error */
/*        SPICE(NOSEGMENTSFOUND) will be signalled. */

/* $ Files */

/*     See argument HANDLE. */

/* $ Particulars */

/*     Close the SPK file attached to HANDLE. */

/* $ Examples */

/*     Suppose that you want to create a new SPK file called 'new.spk' */
/*     that contains a single type 5 SPK segment and has room for at */
/*     least 5000 comment characters. The following code fragment should */
/*     take care of this for you, assuming that all of the variables */
/*     passed to the SPK type 5 segment writer have appropriate values */
/*     and no errors occur. */

/*        NAME   = 'new.spk' */
/*        IFNAME = 'Test SPK file' */

/*        CALL SPKOPN ( NAME, IFNAME, 5000,  HANDLE ) */
/*        CALL SPKW05 ( HANDLE, OBJID, CNTRID, CFRAME, ETBEG, */
/*       .              ETEND, SEGMID, CNTRGM, NSTATE, STATE, */
/*       .              EPOCH                                 ) */
/*        CALL SPKCLS ( HANDLE ) */


/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     K.R. Gehringer    (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.2.0, 07-SEP-2001 (EDW) */

/*        Removed DAFHLU call; replaced ERRFN call with ERRHAN. */

/* -    SPICELIB Version 1.1.0, 17-FEB-2000 (FST) */

/*        Removed the call to ZZFIXID.  This will make all SPK files */
/*        created with future versions of the toolkit possess the */
/*        unambiguous ID word 'DAF/SPK '. */

/* -    SPICELIB Version 1.0.0, 27-JAN-1995 (KRG) */


/* -& */
/* $ Index_Entries */

/*     close an spk file */

/* -& */

/*     SPICELIB functions */


/*     Local Parameters */


/*     Local Variables */


/*     Standard SPICELIB error handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "SPKCLS", (ftnlen)6);

/*     Get the access method for the file. Currently, if HANDLE < 0, the */
/*     access method is 'WRITE'. If HANDLE > 0, the access method is */
/*     'READ'.  In the future this should make use of the private entry */
/*     in the handle manager umbrella, ZZDDHNFO. */

    if (*handle < 0) {
	s_copy(&__global_state->f2c, access, "WRITE", (ftnlen)5, (ftnlen)5);
    } else if (*handle > 0) {
	s_copy(&__global_state->f2c, access, "READ", (ftnlen)5, (ftnlen)4);
    }

/*     If the file is open for writing and there are segments in the file */
/*     fix the ID word and close the file, or just close the file. */

    if (s_cmp(&__global_state->f2c, access, "WRITE", (ftnlen)5, (ftnlen)5) == 
	    0) {

/*        Check to see if there are any segments in the file. If there */
/*        are no segments, we signal an error. This probably indicates a */
/*        programming error of some sort anyway. Why would you create a */
/*        file and put nothing in it? */

	dafbfs_(__global_state, handle);
	daffna_(__global_state, &found);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "SPKCLS", (ftnlen)6);
	    return 0;
	}
	if (! found) {
	    setmsg_(__global_state, "No segments were found in the SPK file "
		    "'#'. There must be at least one segment in the file when"
		    " this subroutine is called.", (ftnlen)122);
	    errhan_(__global_state, "#", handle, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(NOSEGMENTSFOUND)", (ftnlen)22);
	    chkout_(__global_state, "SPKCLS", (ftnlen)6);
	    return 0;
	}
    }

/*     Close the file. */

    dafcls_(__global_state, handle);

/*     No need to check FAILED() here, since we only call spicelib */
/*     subroutines and return. The caller should check it though. */

    chkout_(__global_state, "SPKCLS", (ftnlen)6);
    return 0;
} /* spkcls_ */

