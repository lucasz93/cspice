/* dafwcr.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern dafwcr_init_t __dafwcr_init;
static inline dafwcr_state_t* get_dafwcr_state(cspice_t* state) {
	if (!state->dafwcr)
		state->dafwcr = __cspice_allocate_module(sizeof(
	dafwcr_state_t), &__dafwcr_init, sizeof(__dafwcr_init));
	return state->dafwcr;

}

/* $Procedure DAFWCR ( DAF, write character record ) */
/* Subroutine */ int dafwcr_(cspice_t* __global_state, integer *handle, 
	integer *recno, char *crec, ftnlen crec_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer i_len(f2c_state_t*, char *, ftnlen), s_wdue(f2c_state_t*, cilist *
	    ), do_uio(f2c_state_t*, integer *, char *, ftnlen), e_wdue(
	    f2c_state_t*);

    /* Local variables */
    integer unit;
    extern /* Subroutine */ int zzddhhlu_(cspice_t*, integer *, char *, 
	    logical *, integer *, ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int dafsih_(cspice_t*, integer *, char *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    integer iostat;
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);

    /* Fortran I/O blocks */



    /* Module state */
    dafwcr_state_t* __state = get_dafwcr_state(__global_state);
/* $ Abstract */

/*     Write or rewrite the contents of a character record to */
/*     a DAF. */

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
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle of DAF. */
/*     RECNO      I   Record number of character record. */
/*     CREC       I   Character record. */

/* $ Detailed_Input */

/*     HANDLE      is the handle associated with a DAF. */

/*     RECNO       is the record number of a character record within */
/*                 the file. If the record does not already exist, it */
/*                 is created. Otherwise its contents are overwritten. */

/*     CREC        contains the first 1000 characters of the specified */
/*                 record. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*      None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     1) If the specified file is not open for write access, an error */
/*        is signaled by routines in the call tree of this routine. */

/*     2) If the declared length of CREC is not 1000 characters, */
/*        the error SPICE(DAFBADRECLEN) is signaled. */

/*     2) If the specified record cannot (for some reason) be written, */
/*        the error SPICE(DAFWRITEFAIL) is signaled. */

/* $ Particulars */

/*     Unlike double precision records, character records are */
/*     not buffered. */

/* $ Examples */

/*     In the following example, matching summary and name records are */
/*     written to a DAF: */

/*        CALL DAFWDR ( HANDLE, NEXT,   DREC ) */
/*        CALL DAFWCR ( HANDLE, NEXT+1, CREC ) */

/*     Note that a character record always immediately follows a summary */
/*     record. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     NAIF Document 167.0, "Double Precision Array Files (DAF) */
/*     Specification and User's Guide" */

/* $ Author_and_Institution */

/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 27-NOV-2001 (FST) */

/*        Updated this routine to utilize new handle manager */
/*        interfaces.  Replaced the check of the input handle's */
/*        sign with the appropriate call to DAFSIH. */

/* -    SPICELIB Version 1.0.2, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.1, 22-MAR-1990 (HAN) */

/*        Literature references added to the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     write daf character record */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 2.0.0, 27-NOV-2001 (FST) */

/*        The call to DAFHLU has been replaced with a call to */
/*        ZZDDHHLU, the handle manager interface for retrieving */
/*        a logical unit.  DAFHLU is no longer used, since it */
/*        locks the unit returned to its HANDLE, tying up resources */
/*        in the handle manager.  A call to DAFSIH was inserted to */
/*        make certain that HANDLE is present in DAFAH's file table, */
/*        rather than simply checking the sign of HANDLE. */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "DAFWCR", (ftnlen)6);
    }
    zzddhhlu_(__global_state, handle, "DAF", &__state->c_false, &unit, (
	    ftnlen)3);

/*     Look out for */

/*       -- Writing to a file that is open for read-only. */

/*       -- Trying to write a record that doesn't have length 1000. */

/*       -- Failed write. */

    dafsih_(__global_state, handle, "WRITE", (ftnlen)5);
    if (i_len(&__global_state->f2c, crec, crec_len) != 1000) {
	setmsg_(__global_state, "Expected length of character record is 1000"
		". Length of passed record is #", (ftnlen)73);
	i__1 = i_len(&__global_state->f2c, crec, crec_len);
	errint_(__global_state, "#", &i__1, (ftnlen)1);
	sigerr_(__global_state, "SPICE(DAFBADCRECLEN)", (ftnlen)20);
    } else {
	__state->io___3.ciunit = unit;
	__state->io___3.cirec = *recno;
	iostat = s_wdue(&__global_state->f2c, &__state->io___3);
	if (iostat != 0) {
	    goto L100001;
	}
	iostat = do_uio(&__global_state->f2c, &__state->c__1, crec, crec_len);
	if (iostat != 0) {
	    goto L100001;
	}
	iostat = e_wdue(&__global_state->f2c);
L100001:
	if (iostat != 0) {
	    setmsg_(__global_state, "Character record write failed. Value of"
		    " IOSTAT was #", (ftnlen)52);
	    errint_(__global_state, "#", &iostat, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(DAFWRITEFAIL)", (ftnlen)19);
	}
    }
    chkout_(__global_state, "DAFWCR", (ftnlen)6);
    return 0;
} /* dafwcr_ */

