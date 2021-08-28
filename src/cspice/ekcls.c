/* ekcls.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int ekcls_state_t;
static inline ekcls_state_t* get_ekcls_state(cspice_t* state) {
	return 0;
}

/* $Procedure   EKCLS ( EK, close file ) */
/* Subroutine */ int ekcls_(cspice_t* __global_state, integer *handle)
{
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int dascls_(cspice_t*, integer *);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    ekcls_state_t* __state = get_ekcls_state(__global_state);
/* $ Abstract */

/*     Close an E-kernel. */

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
/*     FILES */
/*     UTILITY */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   EK file handle. */

/* $ Detailed_Input */

/*     HANDLE         is the file handle of an EK to be closed.  Note */
/*                    that EKs open for writing must be closed by this */
/*                    routine in order by be valid. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the indicated file is not recognized, no error is */
/*         signalled. */

/*     2)  If an I/O error occurs while reading or writing the indicated */
/*         file, the error will be diagnosed by routines called by this */
/*         routine. */

/* $ Files */

/*     See the EK Required Reading for a discussion of the EK file */
/*     format. */

/* $ Particulars */

/*     This routine should be used to close open EK files.  EK files */
/*     open for writing *must* be closed by this routine in order to be */
/*     valid.  EK files open for read access should also be closed using */
/*     this routine. */

/*     EKs open for reading won't be corrupted if closed via a FORTRAN */
/*     CLOSE statement, but the underlying bookkeeping software will */
/*     become confused if an EK is closed this way---so we recommend */
/*     closing EK files with EKCLS exclusively. */

/* $ Examples */

/*     1)  Add data to an existing EK file, then close the file. */

/*            CALL EKOPW ( 'MY.EK', HANDLE ) */

/*               [add data] */

/*            CALL EKCLS ( HANDLE ) */


/* $ Restrictions */

/*     1)  No more than FTSIZE DAS files may be opened simultaneously. */
/*         See DASFM for the value of FTSIZE. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.1, 31-MAR-1998 (NJB) */

/*        Corrected Index_Entries section. */

/* -    SPICELIB Version 1.0.0, 26-SEP-1995 (NJB) */

/* -& */
/* $ Index_Entries */

/*     close EK */

/* -& */

/*     SPICELIB functions */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "EKCLS", (ftnlen)5);
    }

/*     Close the file as a DAS file. */

    dascls_(__global_state, handle);
    chkout_(__global_state, "EKCLS", (ftnlen)5);
    return 0;
} /* ekcls_ */

