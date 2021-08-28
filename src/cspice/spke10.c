/* spke10.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern spke10_init_t __spke10_init;
static inline spke10_state_t* get_spke10_state(cspice_t* state) {
	if (!state->spke10)
		state->spke10 = __cspice_allocate_module(sizeof(
	spke10_state_t), &__spke10_init, sizeof(__spke10_init));
	return state->spke10;

}

/* $Procedure SPKE10 ( Evaluate SPK record, type 10 ) */
/* Subroutine */ int spke10_(cspice_t* __global_state, doublereal *et, 
	doublereal *record, doublereal *state)
{
    /* Initialized data */


    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double cos(f2c_state_t*, doublereal), sin(f2c_state_t*, doublereal);

    /* Local variables */
    extern /* Subroutine */ int vadd_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    extern /* Subroutine */ int vequ_(cspice_t*, doublereal *, doublereal *);
    extern /* Subroutine */ int mxvg_(cspice_t*, doublereal *, doublereal *, 
	    integer *, integer *, doublereal *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int moved_(cspice_t*, doublereal *, integer *, 
	    doublereal *);
    extern /* Subroutine */ int vlcom_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    extern doublereal twopi_(cspice_t*);
    extern logical failed_(cspice_t*);
    extern doublereal pi_(cspice_t*);
    extern /* Subroutine */ int vlcomg_(cspice_t*, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int zzteme_(cspice_t*, doublereal *, doublereal *)
	    ;
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int invstm_(cspice_t*, doublereal *, doublereal *)
	    ;
    extern /* Subroutine */ int xxsgp4e_(cspice_t*, doublereal *, doublereal *
	    );
    extern /* Subroutine */ int xxsgp4i_(cspice_t*, doublereal *, doublereal *
	    , integer *);


    /* Module state */
    spke10_state_t* __state = get_spke10_state(__global_state);
/* $ Abstract */

/*     Evaluate a single SPK data record from a segment of type 10 */
/*     (NORAD two-line element sets.). */

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
/* $Procedure ZZSGP4 ( SGP4 parameters ) */

/* $ Abstract */

/*      Parameter assignments for SGP4 algorithm as expressed */
/*      by Vallado [2]. */

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

/*     None. */

/* $ Keywords */

/*     None. */

/* $ Declarations */

/*     None. */

/* $ Brief_I/O */

/*     None. */

/* $ Detailed_Input */

/*     None. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     None. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     None. */

/* $ Examples */

/*     J2    = GEOPHS(K_J2) */
/*     J3    = GEOPHS(K_J3) */
/*     J4    = GEOPHS(K_J4) */
/*     ER    = GEOPHS(K_ER) */
/*     XKE   = GEOPHS(K_KE) */

/*     TUMIN = 1.D0/XKE */
/*     J3OJ2 = J3/J2 */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*   [1] Hoots, F. R., and Roehrich, R. L. 1980. "Models for */
/*       Propagation of the NORAD Element Sets." Spacetrack Report #3. */
/*       U.S. Air Force: Aerospace Defense Command. */

/*   [2] Vallado, David, Crawford, Paul, Hujsak, Richard, and Kelso, T.S. */
/*       2006. Revisiting Spacetrack Report #3. Paper AIAA 2006-6753 */
/*       presented at the AIAA/AAS Astrodynamics Specialist Conference, */
/*       August 21-24, 2006. Keystone, CO. */

/* $ Author_and_Institution */

/*     E. D. Wright    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0 22-JUL-2014 (EDW) */

/* -& */
/* $ Index_Entries */

/*  SGP4 */

/* -& */

/*      WGS gravitational constants IDs. */


/*      Gravitational constant indices. */


/*     The following parameters give the location in the GEOPHS */
/*     array of the various geophysical parameters needed for */
/*     the two line element sets. */

/*     K_J2  --- location of J2 */
/*     K_J3  --- location of J3 */
/*     K_J4  --- location if J4 */
/*     K_KE  --- location of KE = sqrt(GM) in earth-radii**1.5/MIN */
/*     K_QO  --- upper bound of atmospheric model in KM */
/*     K_SO  --- lower bound of atmospheric model in KM */
/*     K_ER  --- earth equatorial radius in KM. */
/*     K_AE  --- distance units/earth radius */


/*     Operation mode values, OPMODE. */


/*     An enumeration of the various components of the */
/*     elements array---ELEMS */

/*     KNDT20  --- location of NDT20 */
/*     KNDD60  --- location of NDD60 */
/*     KBSTAR  --- location of BSTAR */
/*     KINCL   --- location of INCL */
/*     KNODE0  --- location of NODE0 */
/*     KECC    --- location of ECC */
/*     KOMEGA  --- location of OMEGA */
/*     KMO     --- location of MO */
/*     KNO     --- location of NO */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Target epoch. */
/*     RECORD     I   Data record. */
/*     STATE      O   State (position and velocity). */

/* $ Detailed_Input */

/*     ET          is a target epoch, specified as ephemeris seconds past */
/*                 J2000, at which a state vector is to be computed. */

/*     RECORD      is a data record which, when evaluated at epoch ET, */
/*                 will give the state (position and velocity) of some */
/*                 body, relative to some center, in some inertial */
/*                 reference frame. */

/*                 The structure of RECORD is: */

/*                     RECORD(1) */
/*                        .            Geophysical Constants such as */
/*                        .            GM, J2, J3, J4, etc. */
/*                        . */
/*                     RECORD(NGEO) */

/*                     RECORD(NGEO + 1) */
/*                        . */
/*                        .            elements and epoch for the body */
/*                        .            at epoch 1. */
/*                        . */
/*                     RECORD(NGEO + NELEMS ) */

/*                     RECORD(NGEO + NELEMS + 1) */
/*                        . */
/*                        .            elements and epoch for the body */
/*                        .            at epoch 2. */
/*                        . */
/*                     RECORD(NGEO + 2*NELEMS ) */

/*                 Epoch 1 and epoch 2 are the times in the segment that */
/*                 bracket ET. If ET is less than the first time in the */
/*                 segment then both epochs 1 and 2 are equal to the */
/*                 first time. And if ET is greater than the last time */
/*                 then, epochs 1 and 2 are set equal to this last time. */

/* $ Detailed_Output */

/*     STATE       is the state produced by evaluating RECORD at ET. */
/*                 Units are km and km/sec. */

/* $ Parameters */

/*     NGEO        Number of geophysical constants for SGP4 SPK records. */

/*     AFSPC       set the SGP4 propagator to use the original */
/*                 Spacke Track #3 GST algorithm [1]; value defined in */
/*                 zzsgp4.inc. The other option for routines */
/*                 using this value is IMPRVD which causes the algorithm */
/*                 to use calculate GST as described in */
/*                 Vallado 2006 [4]. */

/*     IMPRVD      set the SGP4 propagator to use the improved */
/*                 GST algorithm [1]; value defined in */
/*                 zzsgp4.inc. The other option for routines */
/*                 using this value is AFSPC which causes the algorithm */
/*                 to use calculate GST as described in */
/*                 Vallado 2006 [4]. */

/* $ Exceptions */

/*     1) If a problem occurs when evaluating the two-line elements, */
/*         an error will signal from XXSGPeI or XSGP4E. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine interpolates a state from the two reference sets */
/*     of two-line element sets contained in RECORD. */

/*     It is assumed that this routine is used in conjunction with */
/*     the routine SPKR10 as shown here: */

/*        CALL SPKR10   ( HANDLE, DESCR, ET, RECORD         ) */
/*        CALL SPKE10   (                ET, RECORD, STATE  ) */

/*     Where it is known in advance that the HANDLE, DESCR pair points */
/*     to a type 10 data segment. */

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

/*           IF ( TYPE .EQ. 10 ) THEN */

/*              CALL SPKR10 ( HANDLE, DESCR, ET, RECORD ) */
/*                  . */
/*                  .  Look at the RECORD data. */
/*                  . */
/*              CALL SPKE10 ( ET, RECORD, STATE ) */
/*                  . */
/*                  .  Check out the evaluated state. */
/*                  . */
/*           END IF */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*   [1] Hoots, F. R., and Roehrich, R. L. 1980. "Models for */
/*       Propagation of the NORAD Element Sets." Spacetrack Report #3. */
/*       U.S. Air Force: Aerospace Defense Command. */

/*   [2] Hoots, Felix R. "Spacetrack Report #6: Models for Propagation */
/*       of Space Command Element Sets." Space Command, */
/*       U. S. Air Force, CO. */

/*   [3] Hoots, Felix R., P. W. Schumacher, and R. A. Glover. 2004. */
/*       History of Analytical Orbit Modeling in the U. S. Space */
/*       Surveillance System. Journal of Guidance, Control, and */
/*       Dynamics. 27(2):174-185. */

/*   [4] Vallado, David, Crawford, Paul, Hujsak, Richard, */
/*       and Kelso, T.S. 2006. Revisiting Spacetrack Report #3. Paper */
/*       AIAA 2006-6753 presented at the AIAA/AAS Astrodynamics */
/*       Specialist Conference, August 21-24, 2006. Keystone, CO. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     W.L. Taber      (JPL) */

/* $ Version */

/* -    SPICELIB Version 3.0.0, 18-FEB-2015 (EDW) */

/*        Evaluator now uses Vallado derived propagator as described */
/*        in Vallado 2006 [4]. */

/* -    SPICELIB Version 2.0.0, 01-JAN-2011 (EDW) */

/*        Correction of state transformation calculation. Algorithm */
/*        now computes state transformation as from TEME to J2000. */
/*        The previous version of this routine calculated TETE to */
/*        J2000. */

/* -    SPICELIB Version 1.1.0, 01-SEP-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in MTXV and VADD calls. */

/* -    SPICELIB Version 1.0.0 18-JUL-1997 (WLT) */

/* -& */
/* $ Index_Entries */

/*     evaluate type_10 spk segment */

/* -& */

/*     SPICELIB functions */


/*     The nutation in obliquity and longitude as well as their rates */
/*     follow the elements.  So we've got four angles/angle rates */
/*     following the elements */


/*     The locations of the epochs and the starts of the element */
/*     sets are given below. */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "SPKE10", (ftnlen)6);
    }
    if (__state->first) {
	__state->first = FALSE_;
	__state->mypi = pi_(__global_state);
	__state->my2pi = twopi_(__global_state);
    }

/*     Fetch the two epochs stored in the record. */

    __state->t1 = record[17];
    __state->t2 = record[31];

/*     Evaluate the two states. Call them s_1(t) and s_2(t). */
/*     Let the position and velocity components be: p_1, v_1, p_2, v_2. */

/*     The final position is a weighted average. */

/*     Let */

/*        W(t) =  0.5 + 0.5*COS( PI*(t-t1)/(t2-t1) ) */

/*     then */

/*        p  = W(t)*p_1(t) + (1 - W(t))*p_2(t) */
/*        v  = W(t)*v_1(t) + (1 - W(t))*v_2(t) + W'(t)*(p_1(t) - p_2(t)) */

/*     If t1 = t2, the state is just s(t1). */

/*     Note: there are a number of weighting schemes we could have */
/*     used.  This one has the nice property that */

/*     The graph of W is symmetric about the point */

/*        ( (t1+t2)/2,  W( (t1+t2)/2 ) ) */

/*     The range of W is from 1 to 0. The derivative of W is */
/*     symmetric and zero at both t1 and t2. */

    if (__state->t1 != __state->t2) {

/*        Initialize then propagate. */

/*        XXSGP4E returns on entry if XXSGP4I signals an error. */


/*        Evaluate first TLE. */

	xxsgp4i_(__global_state, record, &record[8], &__state->c__1);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "SPKE10", (ftnlen)6);
	    return 0;
	}

/*        Time from epoch of set 1 in minutes. */

	d__1 = (*et - __state->t1) / 60.;
	xxsgp4e_(__global_state, &d__1, __state->s1);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "SPKE10", (ftnlen)6);
	    return 0;
	}

/*        Evaluate second TLE. */

	xxsgp4i_(__global_state, record, &record[22], &__state->c__1);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "SPKE10", (ftnlen)6);
	    return 0;
	}

/*        Time from epoch of set 2 in minutes. */

	d__1 = (*et - __state->t2) / 60.;
	xxsgp4e_(__global_state, &d__1, __state->s2);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "SPKE10", (ftnlen)6);
	    return 0;
	}

/*        Compute the weighting function that we'll need later */
/*        when we combine states 1 and 2. */

	__state->numer = *et - __state->t1;
	__state->denom = __state->t2 - __state->t1;
	__state->arg = __state->numer * __state->mypi / __state->denom;
	__state->dargdt = __state->mypi / __state->denom;
	__state->w = cos(&__global_state->f2c, __state->arg) * .5 + .5;
	__state->dwdt = sin(&__global_state->f2c, __state->arg) * -.5 * 
		__state->dargdt;

/*        Now compute the weighted average of the two states. */

	d__1 = 1. - __state->w;
	vlcomg_(__global_state, &__state->c__6, &__state->w, __state->s1, &
		d__1, __state->s2, state);
	d__1 = -__state->dwdt;
	vlcom_(__global_state, &__state->dwdt, __state->s1, &d__1, 
		__state->s2, __state->vcomp);
	vadd_(__global_state, &state[3], __state->vcomp, &__state->tmpsta[3]);
	vequ_(__global_state, &__state->tmpsta[3], &state[3]);
    } else {

/*        Evaluate the TLE. */

	xxsgp4i_(__global_state, record, &record[8], &__state->c__1);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "SPKE10", (ftnlen)6);
	    return 0;
	}

/*        Time from epoch of set 1 in minutes. */

	d__1 = (*et - __state->t1) / 60.;
	xxsgp4e_(__global_state, &d__1, state);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "SPKE10", (ftnlen)6);
	    return 0;
	}
    }

/*     Finally, convert the TEME state to J2000.  First get */
/*     the rotation from J2000 to TEME... */

    zzteme_(__global_state, et, __state->precm);

/*     ...now convert STATE to J2000. Invert the state transformation */
/*     operator (important to correctly do this). */

    invstm_(__global_state, __state->precm, __state->invprc);

/*     Map STATE to the corresponding expression in J2000. */

    mxvg_(__global_state, __state->invprc, state, &__state->c__6, &
	    __state->c__6, __state->tmpsta);
    moved_(__global_state, __state->tmpsta, &__state->c__6, state);
    chkout_(__global_state, "SPKE10", (ftnlen)6);
    return 0;
} /* spke10_ */

