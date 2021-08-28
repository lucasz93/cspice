/* zzilusta.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzilusta_init_t __zzilusta_init;
static inline zzilusta_state_t* get_zzilusta_state(cspice_t* state) {
	if (!state->zzilusta)
		state->zzilusta = __cspice_allocate_module(sizeof(
	zzilusta_state_t), &__zzilusta_init, sizeof(__zzilusta_init));
	return state->zzilusta;

}

/* $Procedure ZZILUSTA ( Illumination angle states ) */
/* Subroutine */ int zzilusta_(cspice_t* __global_state, char *method, char *
	target, char *illum, doublereal *et, char *fixref, char *abcorr, char 
	*obsrvr, doublereal *spoint, doublereal *normal, doublereal *phssta, 
	doublereal *incsta, doublereal *emista, ftnlen method_len, ftnlen 
	target_len, ftnlen illum_len, ftnlen fixref_len, ftnlen abcorr_len, 
	ftnlen obsrvr_len)
{
    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    doublereal uvec[3];
    extern /* Subroutine */ int vhat_(cspice_t*, doublereal *, doublereal *);
    extern doublereal vdot_(cspice_t*, doublereal *, doublereal *);
    extern doublereal vsep_(cspice_t*, doublereal *, doublereal *);
    logical xmit;
    extern /* Subroutine */ int mxvg_(cspice_t*, doublereal *, doublereal *, 
	    integer *, integer *, doublereal *);
    extern /* Subroutine */ int zzcorepc_(cspice_t*, char *, doublereal *, 
	    doublereal *, doublereal *, ftnlen);
    extern /* Subroutine */ int zzvalcor_(cspice_t*, char *, logical *, 
	    ftnlen);
    extern /* Subroutine */ int zzcorsxf_(cspice_t*, logical *, doublereal *, 
	    doublereal *, doublereal *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int moved_(cspice_t*, doublereal *, integer *, 
	    doublereal *);
    doublereal starg[6];
    extern doublereal dvsep_(cspice_t*, doublereal *, doublereal *);
    doublereal ltsrc;
    doublereal xform[36]	/* was [6][6] */;
    logical uselt;
    extern logical eqstr_(cspice_t*, char *, char *, ftnlen, ftnlen);
    extern logical vzero_(cspice_t*, doublereal *);
    extern logical failed_(cspice_t*);
    extern /* Subroutine */ int cleard_(cspice_t*, integer *, doublereal *);
    doublereal lt;
    extern doublereal clight_(cspice_t*);
    logical attblk[6];
    doublereal obssta[6];
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    doublereal srcsta[6];
    extern /* Subroutine */ int spkcpo_(cspice_t*, char *, doublereal *, char 
	    *, char *, char *, doublereal *, char *, char *, doublereal *, 
	    doublereal *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int vsclip_(cspice_t*, doublereal *, doublereal *)
	    ;
    doublereal fxnsta[6];
    doublereal nrmsta[6];
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int spkcpt_(cspice_t*, doublereal *, char *, char 
	    *, doublereal *, char *, char *, char *, char *, doublereal *, 
	    doublereal *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen);
    doublereal etsurf;
    extern /* Subroutine */ int vminug_(cspice_t*, doublereal *, integer *, 
	    doublereal *);
    doublereal tmpxfm[36]	/* was [6][6] */;
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int sxform_(cspice_t*, char *, char *, doublereal 
	    *, doublereal *, ftnlen, ftnlen);
    doublereal dlt;


    /* Module state */
    zzilusta_state_t* __state = get_zzilusta_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Compute illumination angles and their rates of change at a */
/*     surface point. */

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

/*     GF */
/*     PCK */
/*     TIME */
/*     SPK */

/* $ Keywords */

/*     ANGLE */
/*     GEOMETRY */
/*     SEARCH */
/*     UTILITY */

/* $ Declarations */
/* $ Abstract */

/*     Include file zzabcorr.inc */

/*     SPICE private file intended solely for the support of SPICE */
/*     routines.  Users should not include this file directly due */
/*     to the volatile nature of this file */

/*     The parameters below define the structure of an aberration */
/*     correction attribute block. */

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

/* $ Parameters */

/*     An aberration correction attribute block is an array of logical */
/*     flags indicating the attributes of the aberration correction */
/*     specified by an aberration correction string.  The attributes */
/*     are: */

/*        - Is the correction "geometric"? */

/*        - Is light time correction indicated? */

/*        - Is stellar aberration correction indicated? */

/*        - Is the light time correction of the "converged */
/*          Newtonian" variety? */

/*        - Is the correction for the transmission case? */

/*        - Is the correction relativistic? */

/*    The parameters defining the structure of the block are as */
/*    follows: */

/*       NABCOR    Number of aberration correction choices. */

/*       ABATSZ    Number of elements in the aberration correction */
/*                 block. */

/*       GEOIDX    Index in block of geometric correction flag. */

/*       LTIDX     Index of light time flag. */

/*       STLIDX    Index of stellar aberration flag. */

/*       CNVIDX    Index of converged Newtonian flag. */

/*       XMTIDX    Index of transmission flag. */

/*       RELIDX    Index of relativistic flag. */

/*    The following parameter is not required to define the block */
/*    structure, but it is convenient to include it here: */

/*       CORLEN    The maximum string length required by any aberration */
/*                 correction string */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 18-DEC-2004 (NJB) */

/* -& */
/*     Number of aberration correction choices: */


/*     Aberration correction attribute block size */
/*     (number of aberration correction attributes): */


/*     Indices of attributes within an aberration correction */
/*     attribute block: */


/*     Maximum length of an aberration correction string: */


/*     End of include file zzabcorr.inc */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     METHOD     I   Computation method. */
/*     TARGET     I   Name of target body associated with surface point. */
/*     ILLUM      I   Name of illumination source. */
/*     ET         I   Observation epoch (TDB). */
/*     FIXREF     I   Body-fixed reference frame. */
/*     ABCORR     I   Aberration correction. */
/*     OBSRVR     I   Name of observer. */
/*     SPOINT     I   Surface point. */
/*     NORMAL     I   Outward normal vector at surface point. */
/*     PHSSTA     O   Phase angle state. */
/*     INCSTA     O   Solar incidence angle state. */
/*     EMISTA     O   Emission angle state. */

/* $ Detailed_Input */

/*     METHOD         is a string specifying the computation method to */
/*                    be used by this routine. The only value currently */
/*                    allowed is 'ELLIPSOID'. This indicates that the */
/*                    target body shape is modeled as an ellipsoid. */

/*                    Case and leading and trailing blanks are not */
/*                    significant in METHOD. */

/*     TARGET         is the name of the target body associated with the */
/*                    surface point SPOINT. TARGET may be a body name or */
/*                    an ID code provided as as string. */

/*     ILLUM          is the name of the illumination source used to */
/*                    define the illumination angles computed by this */
/*                    routine. ILLUM may be a body name or an ID code */
/*                    provided as as string. */

/*     ET             is the observation time. ET is expressed as */
/*                    seconds past J2000 TDB. */

/*     FIXREF         is the name of the body-centered, body-fixed */
/*                    reference frame relative to which SPOINT is */
/*                    specified. The frame's center must coincide with */
/*                    TARGET. */

/*     ABCORR         indicates the aberration corrections to be */
/*                    applied. Only reception corrections are supported. */
/*                    See the header of ILUMIN for a discussion of */
/*                    aberration corrections used in illumination angle */
/*                    computations. */

/*     OBSRVR         is the name of the observing body. OBSRVR may be a */
/*                    body name or an ID code provided as as string. */

/*     SPOINT         is a 3-vector containing the cartesian coordinates */
/*                    of the surface point at which the illumination */
/*                    angle states are to be computed. SPOINT is */
/*                    expressed in the body-centered, body-fixed frame */
/*                    designated by FIXREF (see description above). */

/*                    Units are km. */

/*     NORMAL         is an outward normal vector to be used for */
/*                    emission angle and solar incidence angle */
/*                    calculations. NORMAL should be orthogonal to the */
/*                    plane tangent at SPOINT to the target body's */
/*                    surface. */

/* $ Detailed_Output */

/*     PHSSTA         is the phase angle and its rate of change with */
/*                    respect to TDB, evaluated at ET. */

/*     INCSTA         is the solar incidence angle and its rate of */
/*                    change with respect to TDB, evaluated at ET. */

/*     EMISTA         is the emission angle and its rate of change with */
/*                    respect to TDB, evaluated at ET. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the computation method is not recognized, the error */
/*         SPICE(INVALIDMETHOD) is signaled. */

/*     2)  If ABCORR specifies a transmission aberration correction, */
/*         the error SPICE(INVALIDOPTION) is signaled. */

/*     3)  If an error occurs while looking up a state vector, the */
/*         error will be signaled by a routine in the call tree of */
/*         this routine. */

/*     4)  If the input normal vector is zero, the error */
/*         SPICE(ZEROVECTOR) is signaled. */

/* $ Files */

/*     See GFILUM. */

/* $ Particulars */

/*     The term "state" used in the name of this routine refers to */
/*     the combination of a function and its derivative with respect */
/*     to time. */

/*     This routine centralizes computation of illumination angles and */
/*     their rates of change. It also exposes the illumination angle */
/*     rates of change used by the GF system in order to allow these */
/*     rates to be tested using the TSPICE system. */

/*     See the SPICELIB routine ILUMIN for a description of the */
/*     illumination angles computed by this routine. */

/* $ Examples */

/*     See usage in ZZGFILDC. */

/* $ Restrictions */

/*     1) This routine is intended for use only by the GF subsystem. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 02-APR-2012 (NJB) */

/*       Previous version was dated 21-MAR-2012 */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "ZZILUSTA", (ftnlen)8);

/*     For now, only ellipsoids are supported as target shapes. */

    if (! eqstr_(__global_state, method, "ELLIPSOID", method_len, (ftnlen)9)) 
	    {
	setmsg_(__global_state, "The computation method # was not recognized"
		". ", (ftnlen)45);
	errch_(__global_state, "#", method, (ftnlen)1, method_len);
	sigerr_(__global_state, "SPICE(INVALIDMETHOD)", (ftnlen)20);
	chkout_(__global_state, "ZZILUSTA", (ftnlen)8);
	return 0;
    }

/*     Reject zero normal vectors. */

    if (vzero_(__global_state, normal)) {
	setmsg_(__global_state, "The input normal vector must not be zero, b"
		"ut sadly, it was.", (ftnlen)60);
	sigerr_(__global_state, "SPICE(ZEROVECTOR)", (ftnlen)17);
	chkout_(__global_state, "ZZILUSTA", (ftnlen)8);
	return 0;
    }

/*     Look up the state of the target with respect to the */
/*     observer. We'll represent the state in an inertial */
/*     reference frame. */

    spkcpt_(__global_state, spoint, target, fixref, et, "J2000", "TARGET", 
	    abcorr, obsrvr, starg, &lt, target_len, fixref_len, (ftnlen)5, (
	    ftnlen)6, abcorr_len, obsrvr_len);

/*     Compute the epoch associated with the surface point. */

    zzcorepc_(__global_state, abcorr, et, &lt, &etsurf, abcorr_len);

/*     Now let the surface point be the observer, let the observation */
/*     epoch be ETSURF, and find the apparent state of the illumination */
/*     source as seen from the surface point. */

    spkcpo_(__global_state, illum, &etsurf, "J2000", "OBSERVER", abcorr, 
	    spoint, target, fixref, srcsta, &ltsrc, illum_len, (ftnlen)5, (
	    ftnlen)8, abcorr_len, target_len, fixref_len);
    if (failed_(__global_state)) {
	chkout_(__global_state, "ZZILUSTA", (ftnlen)8);
	return 0;
    }

/*     We will need to transform the state of the normal vector to */
/*     the inertial frame. The epoch at which the transformation must be */
/*     evaluated is that associated with the surface point. */
    sxform_(__global_state, fixref, "J2000", &etsurf, xform, fixref_len, (
	    ftnlen)5);

/*     Correct the body-fixed to inertial frame transformation for the */
/*     rate of change with respect to ET of observer-surface point light */
/*     time, if light time corrections are used. */

/*     Start out by parsing ABCORR. */

    zzvalcor_(__global_state, abcorr, attblk, abcorr_len);
    if (failed_(__global_state)) {
	chkout_(__global_state, "ZZILUSTA", (ftnlen)8);
	return 0;
    }
    uselt = attblk[1];
    xmit = attblk[4];
    if (xmit) {
	setmsg_(__global_state, "Aberration correction # is for transmission"
		"; only reception corrections are supported by this routine.", 
		(ftnlen)102);
	errch_(__global_state, "#", abcorr, (ftnlen)1, abcorr_len);
	sigerr_(__global_state, "SPICE(INVALIDOPTION)", (ftnlen)20);
	chkout_(__global_state, "ZZILUSTA", (ftnlen)8);
	return 0;
    }
    if (uselt) {

/*        Compute the rate of change with respect to ET of the */
/*        observer-surface point light time. This rate is the range rate */
/*        divided by the speed of light. */

	vhat_(__global_state, starg, uvec);
	dlt = vdot_(__global_state, &starg[3], uvec) / clight_(__global_state)
		;

/*        Correct the state transformation. */

	zzcorsxf_(__global_state, &__state->c_false, &dlt, xform, tmpxfm);
	moved_(__global_state, tmpxfm, &__state->c__36, xform);
    }

/*     Create a body-fixed state vector for the normal vector. */
/*     Convert the normal vector to unit length for safety. */

    vhat_(__global_state, normal, fxnsta);
    cleard_(__global_state, &__state->c__3, &fxnsta[3]);

/*     Transform the state of the normal vector to the inertial */
/*     frame. */

    mxvg_(__global_state, xform, fxnsta, &__state->c__6, &__state->c__6, 
	    nrmsta);

/*     We also must adjust the state of the illumination source for the */
/*     rate of change with respect to ET of the observer-surface point */
/*     light time. The velocity portion of the state we've computed is */
/*     the derivative with respect to ETSURF (time at the surface point) */
/*     of the surface point-illumination source vector. We must convert */
/*     this to a derivative with respect to ET. */

/*     This code assumes reception corrections. */

    if (uselt) {

/*        ETSURF = ET - LT, so */

/*        d(ETSURF) / d(ET) = ( 1 - DLT ) */

	d__1 = 1. - dlt;
	vsclip_(__global_state, &d__1, &srcsta[3]);
    }

/*     The surface-point observer state we wish to use is the negative */
/*     of the observer-surface point state. */

    vminug_(__global_state, starg, &__state->c__6, obssta);

/*     Compute the state (value and rate of change ) */
/*     of the phase angle. */

    phssta[0] = vsep_(__global_state, obssta, srcsta);
    phssta[1] = dvsep_(__global_state, obssta, srcsta);

/*     Compute the state of the illumination source */
/*     incidence angle. */

    incsta[0] = vsep_(__global_state, nrmsta, srcsta);
    incsta[1] = dvsep_(__global_state, nrmsta, srcsta);

/*     Compute the state of the emission angle. */

    emista[0] = vsep_(__global_state, nrmsta, obssta);
    emista[1] = dvsep_(__global_state, nrmsta, obssta);
    chkout_(__global_state, "ZZILUSTA", (ftnlen)8);
    return 0;
} /* zzilusta_ */

