/* spke13.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int spke13_state_t;
static inline spke13_state_t* get_spke13_state(cspice_t* state) {
	return 0;
}

/* $Procedure      SPKE13 ( S/P Kernel, evaluate, type 13 ) */
/* Subroutine */ int spke13_(cspice_t* __global_state, doublereal *et, 
	doublereal *record, doublereal *state)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer i_dnnt(f2c_state_t*, doublereal *), s_rnge(f2c_state_t*, char *, 
	    integer, char *, integer);

    /* Local variables */
    integer from;
    doublereal work[516]	/* was [258][2] */;
    integer i__;
    integer j;
    integer n;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer to;
    doublereal locrec[129];
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int hrmint_(cspice_t*, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *);
    extern logical return_(cspice_t*);
    integer xstart;


    /* Module state */
    spke13_state_t* __state = get_spke13_state(__global_state);
/* $ Abstract */

/*     Evaluate a single data record from a type 13 SPK segment. */

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
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     MAXREC     P   Maximum size of SPK record.  See SPKPVN. */
/*     ET         I   Epoch for which a state is desired. */
/*     RECORD     I   Record from a type 13 SPK segment valid for ET. */
/*     STATE      O   State (position and velocity) at epoch ET. */

/* $ Detailed_Input */

/*     ET             is the epoch for which a state vector is desired. */

/*     RECORD         is a record from a type 13 SPK segment which, when */
/*                    evaluated at epoch ET, will give the state */
/*                    (position and velocity) of some body, relative to */
/*                    some center, in some inertial reference frame. */

/*                    The structure of the record is as follows: */

/*                       +----------------------+ */
/*                       | number of states (n) | */
/*                       +----------------------+ */
/*                       | state 1 (6 elts.)    | */
/*                       +----------------------+ */
/*                       | state 2 (6 elts.)    | */
/*                       +----------------------+ */
/*                                   . */
/*                                   . */
/*                                   . */
/*                       +----------------------+ */
/*                       | state n (6 elts.)    | */
/*                       +----------------------+ */
/*                       | epochs 1--n          | */
/*                       +----------------------+ */

/* $ Detailed_Output */

/*     STATE    is the state vector at epoch ET. Its contents are, in */
/*              order, X, Y, Z, X', Y', and Z'. Units are km and km/sec. */

/* $ Parameters */

/*     MAXREC   is the maximum size of SPK record.  See the SPICELIB */
/*              routine SPKPVN for details. */

/* $ Exceptions */

/*     None.  This routine assumes that the input record is valid. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     The exact format and structure of type 13 (unequally spaced */
/*     discrete states, evaluated by Hermite interpolation) SPK segments */
/*     is described in the SPK Required Reading. */

/* $ Examples */

/*     The SPKEnn routines are almost always used in conjunction with */
/*     the corresponding SPKRnn routines, which read the records from */
/*     SPK files. */

/*     The data returned by the SPKRnn routine is in a raw form, taken */
/*     directly from the segment.  As such, it will be not be directly */
/*     useful to a user unless they have a complete understanding of the */
/*     structure of the data type.  Given that understanding, however, */
/*     the SPKRnn routines could be used to "dump" and check segment data */
/*     for a particular epoch before evaluating the record to obtain a */
/*     state vector, as in the example which follows. */


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

/*           IF ( TYPE .EQ. 13 ) THEN */

/*              CALL SPKR13 ( HANDLE, DESCR, ET, RECORD ) */
/*                  . */
/*                  .  Look at the RECORD data. */
/*                  . */
/*              CALL SPKE13 ( ET, RECORD, STATE ) */
/*                  . */
/*                  .  Check out the evaluated state. */
/*                  . */
/*           END IF */

/* $ Restrictions */

/*     1)  This routine assumes that the input record is valid.  Any */
/*         checking of the input data is assumed to have been performed */
/*         when the source SPK file was created. */

/* $ Literature_References */

/*     NAIF Document 168.0, "S- and P- Kernel (SPK) Specification and */
/*     User's Guide" */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 25-FEB-2000 (NJB) */

/* -& */
/* $ Index_Entries */

/*     evaluate type_13 spk segment */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "SPKE13", (ftnlen)6);
    n = i_dnnt(&__global_state->f2c, record);

/*     We interpolate each state component in turn. */

    xstart = n * 6 + 2;
    for (i__ = 1; i__ <= 3; ++i__) {
	i__1 = n;
	for (j = 1; j <= i__1; ++j) {

/*           For the Jth input state vector, copy the Ith position and */
/*           velocity components into the local record buffer LOCREC. */

	    from = (j - 1) * 6 + 1 + i__;
	    to = (j << 1) - 1;
	    locrec[(i__2 = to - 1) < 129 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "locrec", i__2, "spke13_", (ftnlen)
		    234)] = record[from - 1];
	    locrec[(i__2 = to) < 129 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "locrec", i__2, "spke13_", (ftnlen)
		    235)] = record[from + 2];
	}

/*        Interpolate the Ith position and velocity components of the */
/*        state. */

	hrmint_(__global_state, &n, &record[xstart - 1], locrec, et, work, &
		state[(i__1 = i__ - 1) < 6 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "state", i__1, "spke13_", (ftnlen)243)], 
		&state[(i__2 = i__ + 2) < 6 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "state", i__2, "spke13_", (ftnlen)243)]);
    }
    chkout_(__global_state, "SPKE13", (ftnlen)6);
    return 0;
} /* spke13_ */

