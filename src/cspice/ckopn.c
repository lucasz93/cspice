/* ckopn.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern ckopn_init_t __ckopn_init;
static inline ckopn_state_t* get_ckopn_state(cspice_t* state) {
	if (!state->ckopn)
		state->ckopn = __cspice_allocate_module(sizeof(ckopn_state_t),
	 &__ckopn_init, sizeof(__ckopn_init));
	return state->ckopn;

}

/* $Procedure      CKOPN ( CK, open new file. ) */
/* Subroutine */ int ckopn_(cspice_t* __global_state, char *name__, char *
	ifname, integer *ncomch, integer *handle, ftnlen name_len, ftnlen 
	ifname_len)
{
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer ncomr;
    extern logical failed_(cspice_t*);
    extern /* Subroutine */ int dafonw_(cspice_t*, char *, char *, integer *, 
	    integer *, char *, integer *, integer *, ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    ckopn_state_t* __state = get_ckopn_state(__global_state);
/* $ Abstract */

/*     Open a new CK file, returning the handle of the opened file. */

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

/*      CK */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     NAME       I   The name of the CK file to be opened. */
/*     IFNAME     I   The internal filename for the CK. */
/*     NCOMCH     I   The number of characters to reserve for comments. */
/*     HANDLE     O   The handle of the opened CK file. */

/* $ Detailed_Input */

/*     NAME     The name of the CK file to be opened. */

/*     IFNAME   The internal filename for the CK file that is being */
/*              created. The internal filename may be up to 60 characters */
/*              long. If you do not have any conventions for tagging your */
/*              files, an internal filename of 'CK_file' is perfectly */
/*              acceptable. You may also leave it blank if you like. */

/*     NCOMCH   This is the space, measured in characters, to be */
/*              initially set aside for the comment area when a new CK */
/*              file is opened. The amount of space actually set aside */
/*              may be greater than the amount requested, due to the */
/*              manner in which comment records are allocated in an CK */
/*              file. However, the amount of space set aside for comments */
/*              will always be at least the amount that was requested. */

/*              The value of NCOMCH should be greater than or equal to */
/*              zero, i.e., 0 <= NCOMCH. A negative value, should one */
/*              occur, will be assumed to be zero. */

/* $ Detailed_Output */

/*     HANDLE   The handle of the opened CK file. If an error occurs the */
/*              value of this variable will not represent a valid handle. */

/* $ Parameters */

/*      None. */

/* $ Exceptions */

/*     1) If the value of NCOMCH is negative, a value of zero (0) will */
/*        be used for the number of comment characters to be set aside */
/*        for comments. */

/*     2) If an error occurs while attempting to open a CK file the */
/*        value of HANDLE will not represent a valid file handle. */

/* $ Files */

/*      See NAME and HANDLE. */

/* $ Particulars */

/*     Open a new CK file, reserving room for comments if requested. */

/* $ Examples */

/*     Suppose that you want to create a new CK file called 'new.ck' */
/*     that contains a single type 3 CK segment and has room for at */
/*     least 5000 comment characters. The following code fragment should */
/*     take care of this for you, assuming that all of the variables */
/*     passed to the CK type 3 segment writer have appropriate values. */

/*        NAME   = 'new.ck' */
/*        IFNAME = 'Test CK file' */

/*        CALL CKOPN ( NAME, IFNAME, 5000, HANDLE ) */
/*        CALL CKW03 ( HANDLE, BEGTIM, ENDTIM, INST,  REF,  AVFLAG, */
/*       .             SEGID,  NREC,   SCLKDP, QUATS, AVVS, NINTS, */
/*       .             STARTS                                       ) */
/*        CALL CKCLS ( HANDLE ) */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*      K.R. Gehringer    (JPL) */

/* $ Literature_References */

/*      None. */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 09-NOV-2006 (NJB) */

/*        Routine has been upgraded to support comment */
/*        area allocation using NCOMCH. */

/* -    SPICELIB Version 1.0.0, 26-JAN-1995 (KRG) */

/* -& */
/* $ Index_Entries */

/*     open a new ck file */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     DAF ND and NI values for CK files. */


/*     Length of a DAF comment record, in characters. */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "CKOPN", (ftnlen)5);

/*     Compute the number of comment records that we want to allocate, if */
/*     the number of comment characters requested is greater than zero, */
/*     we always allocate an extra record to account for the end of line */
/*     marks in the comment area. */

    if (*ncomch > 0) {
	ncomr = (*ncomch - 1) / 1000 + 1;
    } else {
	ncomr = 0;
    }

/*     Just do it. All of the error handling is taken care of for us. */

    dafonw_(__global_state, name__, "CK", &__state->c__2, &__state->c__6, 
	    ifname, &ncomr, handle, name_len, (ftnlen)2, ifname_len);
    if (failed_(__global_state)) {

/*        If we failed, make sure that HANDLE does not contain a value */
/*        that represents a valid DAF file handle. */

	*handle = 0;
    }
    chkout_(__global_state, "CKOPN", (ftnlen)5);
    return 0;
} /* ckopn_ */

