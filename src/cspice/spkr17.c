/* spkr17.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern spkr17_init_t __spkr17_init;
static inline spkr17_state_t* get_spkr17_state(cspice_t* state) {
	if (!state->spkr17)
		state->spkr17 = __cspice_allocate_module(sizeof(
	spkr17_state_t), &__spkr17_init, sizeof(__spkr17_init));
	return state->spkr17;

}

/* $Procedure      SPKR17 ( Read SPK record from segment, type 17 ) */
/* Subroutine */ int spkr17_(cspice_t* __global_state, integer *handle, 
	doublereal *descr, doublereal *et, doublereal *record)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    integer type__;
    integer begin;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int dafus_(cspice_t*, doublereal *, integer *, 
	    integer *, doublereal *, integer *);
    extern /* Subroutine */ int dafgda_(cspice_t*, integer *, integer *, 
	    integer *, doublereal *);
    doublereal dc[2];
    integer ic[6];
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);
    integer end;


    /* Module state */
    spkr17_state_t* __state = get_spkr17_state(__global_state);
/* $ Abstract */

/*     This routine reads a single spk data record from a segment of */
/*     type 17 (Precessing Conic Propagation). */

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
/*     HANDLE     I   File handle. */
/*     DESCR      I   Segment descriptor. */
/*     ET         I   Target epoch. */
/*     RECORD     O   Data record. */

/* $ Detailed_Input */

/*     HANDLE, */
/*     DESCR       are the file handle and segment descriptor for */
/*                 a SPK segment of type 17. */

/*     ET          is a target epoch, for which a data record from */
/*                 a specific segment is required. */

/* $ Detailed_Output */

/*     RECORD      is the record from the specified segment which, */
/*                 when evaluated at epoch ET, will give the state */
/*                 (position and velocity) of some body, relative */
/*                 to some center, in some inertial reference frame. */

/* $ Parameters */

/*     None. */

/* $ Files */

/*     See argument HANDLE. */

/* $ Exceptions */

/*     1) If the segment specified by DESCR is not a type 17 segment */
/*        the error 'SPICE(WRONGSPKTYPE)' will be signalled. */

/*     2) A type 17 segment should have exactly 16 values.  If this */
/*        is not the case the error 'SPICE(MALFORMEDSEGMENT)' is */
/*        signalled. */

/* $ Particulars */

/*     This routine reads all of the data from a type 17 SPK segment. */

/*     The structure of the data retrieved in RECORD is: */

/*         RECORD(1) is the epoch of the orbit elements at */
/*                   in ephemeris seconds past J2000. */

/*         RECORD(2) is the semi-major axis (A) of the orbit. */

/*         RECORD(3) is the value of H at the specified epoch. */
/*                   ( E*SIN(ARGP+NODE) ). */

/*         RECORD(4) is the value of K at the specified epoch */
/*                   ( E*COS(ARGP+NODE) ). */

/*         RECORD(5) is the mean longitude (MEAN0+ARGP+NODE)at */
/*                   the epoch of the elements. */

/*         RECORD(6) is the value of P (TAN(INC/2)*SIN(NODE))at */
/*                   the specified epoch. */

/*         RECORD(7) is the value of Q (TAN(INC/2)*COS(NODE))at */
/*                        the specified epoch. */

/*         RECORD(8) is the rate of the longitude of periapse */
/*                   (dARGP/dt + dNODE/dt ) at the epoch of */
/*                   the elements.  This rate is assumed to hold */
/*                   for all time. */

/*         RECORD(9) is the derivative of the mean longitude */
/*                   ( dM/dt + dARGP/dt + dNODE/dt ).  This */
/*                   rate is assumed to be constant. */

/*         RECORD(10) is the rate of the longitude of the ascending */
/*                    node ( dNODE/dt). */

/*         RECORD(11) Right Ascension of the pole of the */
/*                    orbital reference system relative to the */
/*                    reference frame of the associated SPK segment. */

/*         RECORD(12) Declination of the pole of the */
/*                    orbital reference system relative to the */
/*                    reference frame of the associated SPK segment. */

/*     Units are km, radians and radians/second. */


/* $ Examples */

/*     The data returned by the SPKRnn routine is in its rawest form, */
/*     taken directly from the segment.  As such, it will be meaningless */
/*     to a user unless he/she understands the structure of the data type */
/*     completely.  Given that understanding, however, the SPKRnn */
/*     routines might be used to "dump" and check segment data for a */
/*     particular epoch. */


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

/*           IF ( TYPE .EQ. 17 ) THEN */
/*              CALL SPKR17 ( HANDLE, DESCR, ET, RECORD ) */
/*                  . */
/*                  .  Look at the RECORD data. */
/*                  . */
/*           END IF */


/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*      W.L. Taber      (JPL) */

/* $ Literature_References */

/*      None. */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 07-SEP-2001 (EDW) */

/*        Replaced DAFRDA call with DAFGDA. */
/*        Added IMPLICIT NONE. */

/* -    SPICELIB Version 1.0.0, 3-JAN-1997 (WLT) (SS) */

/* -& */
/* $ Index_Entries */

/*     read record from type_17 spk segment */

/* -& */

/*     SPICELIB Functions */


/*     Local Variables */


/*     The difference between the first and last address of a type 17 */
/*     segment should be 11. */


/*     Standard Spice Error Handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "SPKR17", (ftnlen)6);

/*     Unpack the segment descriptor. */

    dafus_(__global_state, descr, &__state->c__2, &__state->c__6, dc, ic);
    type__ = ic[3];
    begin = ic[4];
    end = ic[5];

/*     Make sure that this really is a type 17 data segment. */

    if (type__ != 17) {
	setmsg_(__global_state, "You are attempting to locate type 17 data i"
		"n a type # data segment.", (ftnlen)67);
	errint_(__global_state, "#", &type__, (ftnlen)1);
	sigerr_(__global_state, "SPICE(WRONGSPKTYPE)", (ftnlen)19);
	chkout_(__global_state, "SPKR17", (ftnlen)6);
	return 0;
    }

/*     Since it doesn't cost much we make sure that the segment has */
/*     the correct amount of data. */

    if (end - begin != 11) {
	setmsg_(__global_state, "A type 17 segment should contain exactly # "
		"double precision values.  The segment supplied had #.  The s"
		"egment is badly formed. ", (ftnlen)127);
	i__1 = end - begin + 1;
	errint_(__global_state, "#", &i__1, (ftnlen)1);
	errint_(__global_state, "#", &__state->c__12, (ftnlen)1);
	sigerr_(__global_state, "SPICE(MALFORMEDSEGMENT)", (ftnlen)23);
	chkout_(__global_state, "SPKR17", (ftnlen)6);
	return 0;
    }

/*     Read the data for the record. */

    dafgda_(__global_state, handle, &begin, &end, record);
    chkout_(__global_state, "SPKR17", (ftnlen)6);
    return 0;
} /* spkr17_ */

