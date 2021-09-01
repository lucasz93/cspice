/* spks21.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern spks21_init_t __spks21_init;
static spks21_state_t* get_spks21_state(cspice_t* state) {
	if (!state->spks21)
		state->spks21 = __cspice_allocate_module(sizeof(
	spks21_state_t), &__spks21_init, sizeof(__spks21_init));
	return state->spks21;

}

/* $Procedure      SPKS21 ( S/P Kernel, subset, type 21 ) */
/* Subroutine */ int spks21_(cspice_t* __global_state, integer *handle, 
	integer *baddr, integer *eaddr, doublereal *begin, doublereal *end)
{
    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1;

    /* Builtin functions */
    integer i_dnnt(f2c_state_t*, doublereal *);

    /* Local variables */
    doublereal data[111];
    integer offe;
    integer nrec;
    integer ndir;
    integer last;
    integer i__;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer first;
    extern /* Subroutine */ int dafada_(cspice_t*, doublereal *, integer *);
    extern /* Subroutine */ int dafgda_(cspice_t*, integer *, integer *, 
	    integer *, doublereal *);
    integer maxdim;
    integer offset;
    integer dlsize;
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    spks21_state_t* __state = get_spks21_state(__global_state);
/* $ Abstract */

/*     Extract a subset of the data in a SPK segment of type 21 */
/*     into a new segment. */

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
/*     SPK */
/*     TIME */

/* $ Keywords */

/*     EPHEMERIS */

/* $ Declarations */
/* $ Abstract */

/*     Declare parameters specific to SPK type 21. */

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

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 25-DEC-2013 (NJB) */

/* -& */

/*     MAXTRM      is the maximum number of terms allowed in each */
/*                 component of the difference table contained in a type */
/*                 21 SPK difference line. MAXTRM replaces the fixed */
/*                 table parameter value of 15 used in SPK type 1 */
/*                 segments. */

/*                 Type 21 segments have variable size. Let MAXDIM be */
/*                 the dimension of each component of the difference */
/*                 table within each difference line. Then the size */
/*                 DLSIZE of the difference line is */

/*                    ( 4 * MAXDIM ) + 11 */

/*                 MAXTRM is the largest allowed value of MAXDIM. */



/*     End of include file spk21.inc. */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle of source segment. */
/*     BADDR      I   Beginning address of source segment. */
/*     EADDR      I   Ending address of source segment. */
/*     BEGIN      I   Beginning (initial epoch) of subset. */
/*     END        I   End (final epoch) of subset. */

/* $ Detailed_Input */

/*     HANDLE, */
/*     BADDR, */
/*     EADDR       are the file handle assigned to a SPK file, and the */
/*                 beginning and ending addresses of a segment within */
/*                 the file. Together they determine a complete set of */
/*                 ephemeris data, from which a subset is to be */
/*                 extracted. */

/*     BEGIN, */
/*     END         are the initial and final epochs (ephemeris time) */
/*                 of the subset to be extracted. */


/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  Any errors that occur while reading data from the source SPK */
/*         file will be diagnosed by routines in the call tree of this */
/*         routine. */

/*     2)  Any errors that occur while writing data to the output SPK */
/*         file will be diagnosed by routines in the call tree of this */
/*         routine. */

/* $ Files */

/*     See argument HANDLE. */

/* $ Particulars */

/*     The exact structure of a segment of data type 21 is detailed in */
/*     the SPK Required Reading file. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     NAIF Document 168.0, "S- and P- Kernel (SPK) Specification and */
/*     User's Guide" */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     I.M. Underwood  (JPL) */
/*     E.D. Wright     (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 16-JAN-2014 (NJB) (FTK) (WLT) (IMU) */

/* -& */
/* $ Index_Entries */

/*     subset type_21 spk segment */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "SPKS01", (ftnlen)6);

/*     Get the number of records in the segment. From that, we can */
/*     compute */

/*        NDIR      The number of directory epochs. */

/*        OFFE      The offset of the first epoch. */


/*     the number of directory epochs. */

    i__1 = *eaddr - 1;
    dafgda_(__global_state, handle, &i__1, eaddr, data);
    maxdim = i_dnnt(&__global_state->f2c, data);
    nrec = i_dnnt(&__global_state->f2c, &data[1]);
    ndir = nrec / 100;
    offe = *eaddr - ndir - nrec - 2;

/*     Well, the new segment has already been begun. We just have to */
/*     decide what to move, and move it (using DAFADA). */

/*     Let's agree right now that speed is not of the greatest */
/*     importance here. We can probably do this with two passes */
/*     through the record epochs, and one pass through the records. */

/*        1) Determine the first and last records to be included */
/*           in the subset. */

/*        2) Move the records. */

/*        3) Write the epochs. */

/*     We can leap through the epochs one last time to get the */
/*     directory epochs. */

/*     First pass: which records are to be moved? */

    first = 0;
    last = 0;
    i__1 = nrec;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = offe + i__;
	i__3 = offe + i__;
	dafgda_(__global_state, handle, &i__2, &i__3, data);
	if (first == 0 && data[0] >= *begin) {
	    first = i__;
	}
	if (first != 0 && last == 0 && data[0] >= *end) {
	    last = i__;
	}
    }

/*     Second pass. Move the records. */

    dlsize = (maxdim << 2) + 11;
    offset = *baddr - 1 + (first - 1) * dlsize;
    i__1 = last;
    for (i__ = first; i__ <= i__1; ++i__) {
	i__2 = offset + 1;
	i__3 = offset + dlsize;
	dafgda_(__global_state, handle, &i__2, &i__3, data);
	dafada_(__global_state, data, &dlsize);
	offset += dlsize;
    }

/*     Third pass. Move the epochs. */

    i__1 = last;
    for (i__ = first; i__ <= i__1; ++i__) {
	i__2 = offe + i__;
	i__3 = offe + i__;
	dafgda_(__global_state, handle, &i__2, &i__3, data);
	dafada_(__global_state, data, &__state->c__1);
    }

/*     Get every DIRSIZ'th epoch for the directory. */

    i__1 = last;
    for (i__ = first + 99; i__ <= i__1; i__ += 100) {
	i__2 = offe + i__;
	i__3 = offe + i__;
	dafgda_(__global_state, handle, &i__2, &i__3, data);
	dafada_(__global_state, data, &__state->c__1);
    }

/*     Add the maximum difference line dimension and the */
/*     number of records, and we're done. */

    d__1 = (doublereal) maxdim;
    dafada_(__global_state, &d__1, &__state->c__1);
    data[0] = (doublereal) (last - first + 1);
    dafada_(__global_state, data, &__state->c__1);
    chkout_(__global_state, "SPKS01", (ftnlen)6);
    return 0;
} /* spks21_ */

