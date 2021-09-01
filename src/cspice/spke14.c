/* spke14.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int spke14_state_t;
static spke14_state_t* get_spke14_state(cspice_t* state) {
	return 0;
}

/* $Procedure      SPKE14 ( S/P Kernel, evaluate, type 14 ) */
/* Subroutine */ int spke14_(cspice_t* __global_state, doublereal *et, 
	doublereal *record, doublereal *state)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);

    /* Local variables */
    integer i__;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer degree;
    extern /* Subroutine */ int chbval_(cspice_t*, doublereal *, integer *, 
	    doublereal *, doublereal *, doublereal *);
    integer ncoeff;
    integer cofloc;
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    spke14_state_t* __state = get_spke14_state(__global_state);
/* $ Abstract */

/*     Evaluate a single data record from a type 14 SPK segment. */

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
/*     ET         I   Epoch for which a state is desired. */
/*     RECORD     I   Record from a type 14 SPK segment valid for ET. */
/*     STATE      O   State (position and velocity) at epoch ET. */

/* $ Detailed_Input */

/*     ET       is the epoch for which a state vector is desired. */

/*     RECORD   is a record from a type 14 SPK segment which, when */
/*              evaluated at epoch ET, will give the state (position */
/*              and velocity) of some body, relative to some center, in */
/*              some inertial reference frame. */

/* $ Detailed_Output */

/*     STATE    is the state vector at epoch ET. Its contents are, in */
/*              order, X, Y, Z, X', Y', and Z'. Units are km and km/sec. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     None. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     The exact format and structure of a type 14 SPK segment is */
/*     described in the SPK Required Reading. */

/*     A type 14 record contains six sets of Chebyshev coefficients, */
/*     one set each for the position coordinates X, Y, and Z, and one */
/*     set each for the velocity coordinates X', Y', and Z' of a state */
/*     vector.  SPKE14 calls the routine CHBVAL to evalute each */
/*     Chebyshev polynomial, and arrive at the complete state. */

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

/*           IF ( TYPE .EQ. 14 ) THEN */

/*              CALL SPKR14 ( HANDLE, DESCR, ET, RECORD ) */
/*                  . */
/*                  .  Look at the RECORD data. */
/*                  . */
/*              CALL SPKE14 ( ET, RECORD, STATE ) */
/*                  . */
/*                  .  Check out the evaluated state. */
/*                  . */
/*           END IF */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     NAIF Document 168.0, "S- and P- Kernel (SPK) Specification and */
/*     User's Guide" */

/* $ Author_and_Institution */

/*     K.R. Gehringer (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 10-MAR-1995 (KRG) */

/* -& */
/* $ Index_Entries */

/*     evaluate type_14 spk segment */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "SPKE14", (ftnlen)6);
    }

/*     The first number in the record is the number of Chebyshev */
/*     Polynomial coefficients used to represent each component of the */
/*     state vector. Following it are two numbers that will be used */
/*     when evaluating the sets of coefficients, and finally the six sets */
/*     of coefficients. */

    ncoeff = (integer) record[0];

/*     The degree of each polynomial is one less than the number of */
/*     coefficients. */

    degree = ncoeff - 1;

/*     Call CHBVAL once for each quantity to evaluate the position */
/*     and velocity values. */

    for (i__ = 1; i__ <= 6; ++i__) {

/*        The coefficients for each variable are located contiguously, */
/*        following the first three words in the record. */

	cofloc = ncoeff * (i__ - 1) + 4;

/*        CHBVAL needs as input the coefficients, the degree of the */
/*        polynomial, also two variable transformation parameters, which */
/*        are located in the second and third slots of the record, and */
/*        the epoch. We get back the appropriate element of a state */
/*        vector. */

	chbval_(__global_state, &record[cofloc - 1], &degree, &record[1], et, 
		&state[(i__1 = i__ - 1) < 6 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "state", i__1, "spke14_", (ftnlen)216)]);
    }
    chkout_(__global_state, "SPKE14", (ftnlen)6);
    return 0;
} /* spke14_ */

