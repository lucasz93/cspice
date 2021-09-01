/* spke09.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern spke09_init_t __spke09_init;
static spke09_state_t* get_spke09_state(cspice_t* state) {
	if (!state->spke09)
		state->spke09 = __cspice_allocate_module(sizeof(
	spke09_state_t), &__spke09_init, sizeof(__spke09_init));
	return state->spke09;

}

/* $Procedure      SPKE09 ( S/P Kernel, evaluate, type 9 ) */
/* Subroutine */ int spke09_(cspice_t* __global_state, doublereal *et, 
	doublereal *record, doublereal *state)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer i_dnnt(f2c_state_t*, doublereal *), s_rnge(f2c_state_t*, char *, 
	    integer, char *, integer);

    /* Local variables */
    integer i__;
    integer n;
    extern /* Subroutine */ int moved_(cspice_t*, doublereal *, integer *, 
	    doublereal *);
    doublereal locrec[198];
    extern doublereal lgrint_(cspice_t*, integer *, doublereal *, doublereal *
	    , doublereal *, doublereal *);
    extern /* Subroutine */ int xposeg_(cspice_t*, doublereal *, integer *, 
	    integer *, doublereal *);
    extern logical return_(cspice_t*);
    integer xstart;
    integer ystart;


    /* Module state */
    spke09_state_t* __state = get_spke09_state(__global_state);
/* $ Abstract */

/*     Evaluate a single SPK data record from a segment of type 9 */
/*     (discrete states, evaluated by Lagrange interpolation). */

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

/*     EPHEMERIS */

/* $ Declarations */
/* $ Abstract */

/*     Declare SPK data record size.  This record is declared in */
/*     SPKPVN and is passed to SPK reader (SPKRxx) and evaluator */
/*     (SPKExx) routines. */

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

/*     1) If new SPK types are added, it may be necessary to */
/*        increase the size of this record.  The header of SPKPVN */
/*        should be updated as well to show the record size */
/*        requirement for each data type. */

/* $ Author_and_Institution */

/*     N.J. Bachman      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 05-OCT-2012 (NJB) */

/*        Updated to support increase of maximum degree to 27 for types */
/*        2, 3, 8, 9, 12, 13, 18, and 19. See SPKPVN for a list */
/*        of record size requirements as a function of data type. */

/* -    SPICELIB Version 1.0.0, 16-AUG-2002 (NJB) */

/* -& */

/*     End include file spkrec.inc */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Target epoch. */
/*     RECORD    I-O  Data record. */
/*     STATE      O   State (position and velocity). */

/* $ Detailed_Input */

/*     ET          is a target epoch, at which a state vector is to */
/*                 be computed. */

/*     RECORD      is a data record which, when evaluated at epoch ET, */
/*                 will give the state (position and velocity) of some */
/*                 body, relative to some center, in some inertial */
/*                 reference frame.  Normally, the caller of this routine */
/*                 will obtain RECORD by calling SPKR09. */

/*                 The structure of the record is as follows: */

/*                    +----------------------+ */
/*                    | number of states (n) | */
/*                    +----------------------+ */
/*                    | state 1 (6 elts.)    | */
/*                    +----------------------+ */
/*                    | state 2 (6 elts.)    | */
/*                    +----------------------+ */
/*                                . */
/*                                . */
/*                                . */
/*                    +----------------------+ */
/*                    | state n (6 elts.)    | */
/*                    +----------------------+ */
/*                    | epochs 1--n          | */
/*                    +----------------------+ */

/* $ Detailed_Output */

/*     RECORD      is the input record, modified by use as a work area. */
/*                 On output, RECORD no longer contains useful */
/*                 information. */

/*     STATE       is the state. In order, the elements are */

/*                    X, Y, Z, X', Y', and Z' */

/*                 Units are km and km/sec. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  The caller of this routine must ensure that the input record */
/*         is appropriate for the supplied ET value.  Otherwise, */
/*         arithmetic overflow may result. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     The exact format and structure of type 9 (unequally spaced */
/*     discrete states, evaluated by Lagrange interpolation) segments are */
/*     described in the SPK Required Reading file. */

/* $ Examples */

/*     The SPKEnn routines are almost always used in conjunction with */
/*     the corresponding SPKRnn routines, which read the records from */
/*     SPK files. */

/*     The data returned by the SPKRnn routine is in its rawest form, */
/*     taken directly from the segment.  As such, it will be meaningless */
/*     to a user unless he/she understands the structure of the data type */
/*     completely.  Given that understanding, however, the SPKRnn */
/*     routines might be used to examine raw segment data before */
/*     evaluating it with the SPKEnn routines. */


/*     C */
/*     C     Get a segment applicable to a specified body and epoch. */
/*     C */
/*           CALL SPKSFS ( BODY, ET, HANDLE, DESCR, IDENT, FOUND ) */

/*     C */
/*     C     Look at parts of the descriptor. */
/*     C */
/*           CALL DAFUS ( DESCR, 2, 6, DCD, ICD ) */
/*           CENTER = ICD( 2 ) */
/*           REF    = ICD( 3 ) */
/*           TYPE   = ICD( 4 ) */

/*           IF ( TYPE .EQ. 9 ) THEN */

/*              CALL SPKR09 ( HANDLE, DESCR, ET, RECORD ) */
/*                  . */
/*                  .  Look at the RECORD data. */
/*                  . */
/*              CALL SPKE09 ( ET, RECORD, STATE ) */
/*                  . */
/*                  .  Check out the evaluated state. */
/*                  . */
/*           END IF */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     R.E. Thurman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 31-AUG-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in XPOSEG and LGRINT calls. */

/* -    SPICELIB Version 1.0.0, 14-AUG-1993 (NJB) (RET) */

/* -& */
/* $ Index_Entries */

/*     evaluate type_9 spk segment */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.1.0, 31-AUG-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in XPOSEG and LGRINT calls. */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Indices of input record elements: */

/*        -- size */
/*        -- start of state information */


/*     Local variables */


/*     Discovery check-in. */

    if (return_(__global_state)) {
	return 0;
    }

/*     We'll transpose the state information in the input record */
/*     so that contiguous pieces of it can be shoved directly into the */
/*     interpolation routine LGRINT.  We allow LGRINT to overwrite the */
/*     state values in the input record, since this saves local storage */
/*     and does no harm.  (See the header of LGRINT for a description of */
/*     its work space usage.) */

    n = i_dnnt(&__global_state->f2c, record);
    xposeg_(__global_state, &record[1], &__state->c__6, &n, locrec);
    i__1 = n * 6;
    moved_(__global_state, locrec, &i__1, &record[1]);

/*     We interpolate each state component in turn. */

    xstart = n * 6 + 2;
    for (i__ = 1; i__ <= 6; ++i__) {
	ystart = n * (i__ - 1) + 2;
	state[(i__1 = i__ - 1) < 6 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "state", i__1, "spke09_", (ftnlen)261)] =
		 lgrint_(__global_state, &n, &record[xstart - 1], &record[
		ystart - 1], locrec, et);
    }
    return 0;
} /* spke09_ */

