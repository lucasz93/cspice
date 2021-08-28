/* zzspkgp0.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzspkgp0_init_t __zzspkgp0_init;
static inline zzspkgp0_state_t* get_zzspkgp0_state(cspice_t* state) {
	if (!state->zzspkgp0)
		state->zzspkgp0 = __cspice_allocate_module(sizeof(
	zzspkgp0_state_t), &__zzspkgp0_init, sizeof(__zzspkgp0_init));
	return state->zzspkgp0;

}

/* $Procedure ZZSPKGP0 ( S/P Kernel, geometric position ) */
/* Subroutine */ int zzspkgp0_(cspice_t* __global_state, integer *targ, 
	doublereal *et, char *ref, integer *obs, doublereal *pos, doublereal *
	lt, ftnlen ref_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen), s_rnge(
	    f2c_state_t*, char *, integer, char *, integer);

    /* Local variables */
    extern /* Subroutine */ int zzrefch0_(cspice_t*, integer *, integer *, 
	    doublereal *, doublereal *);
    extern /* Subroutine */ int vadd_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    integer cobs;
    integer legs;
    doublereal sobs[6];
    extern /* Subroutine */ int vsub_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    extern /* Subroutine */ int vequ_(cspice_t*, doublereal *, doublereal *);
    extern /* Subroutine */ int zznamfrm_(cspice_t*, integer *, char *, 
	    integer *, char *, integer *, ftnlen, ftnlen);
    extern /* Subroutine */ int zzctruin_(cspice_t*, integer *);
    integer i__;
    extern /* Subroutine */ int etcal_(cspice_t*, doublereal *, char *, 
	    ftnlen);
    integer refid;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    char oname[40];
    doublereal descr[5];
    integer ctarg[20];
    char ident[40];
    char tname[40];
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int moved_(cspice_t*, doublereal *, integer *, 
	    doublereal *);
    logical found;
    extern /* Subroutine */ int repmi_(cspice_t*, char *, char *, integer *, 
	    char *, ftnlen, ftnlen, ftnlen);
    doublereal starg[120]	/* was [6][20] */;
    logical nofrm;
    doublereal stemp[6];
    integer ctpos;
    doublereal vtemp[6];
    extern doublereal vnorm_(cspice_t*, doublereal *);
    extern /* Subroutine */ int bodc2n_(cspice_t*, integer *, char *, logical 
	    *, ftnlen);
    extern logical failed_(cspice_t*);
    extern /* Subroutine */ int cleard_(cspice_t*, integer *, doublereal *);
    integer handle;
    integer cframe;
    extern doublereal clight_(cspice_t*);
    integer tframe[20];
    extern integer isrchi_(cspice_t*, integer *, integer *, integer *);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int irfnum_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int prefix_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int suffix_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    integer tmpfrm;
    extern /* Subroutine */ int irfrot_(cspice_t*, integer *, integer *, 
	    doublereal *);
    extern /* Subroutine */ int spksfs_(cspice_t*, integer *, doublereal *, 
	    integer *, doublereal *, char *, logical *, ftnlen);
    extern integer frstnp_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);
    doublereal psxfrm[9]	/* was [3][3] */;
    extern /* Subroutine */ int spkpvn_(cspice_t*, integer *, doublereal *, 
	    doublereal *, integer *, doublereal *, integer *);
    extern /* Subroutine */ int intstr_(cspice_t*, integer *, char *, ftnlen);
    integer nct;
    doublereal rot[9]	/* was [3][3] */;
    extern /* Subroutine */ int mxv_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    char tstring[80];


    /* Module state */
    zzspkgp0_state_t* __state = get_zzspkgp0_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Compute the geometric position of a target body relative to an */
/*     observing body. */

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

/*     This file contains the number of inertial reference */
/*     frames that are currently known by the SPICE toolkit */
/*     software. */

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

/*     FRAMES */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     NINERT     P   Number of known inertial reference frames. */

/* $ Parameters */

/*     NINERT     is the number of recognized inertial reference */
/*                frames.  This value is needed by both CHGIRF */
/*                ZZFDAT, and FRAMEX. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 10-OCT-1996 (WLT) */

/* -& */
/* $ Abstract */

/*     This include file defines the dimension of the counter */
/*     array used by various SPICE subsystems to uniquely identify */
/*     changes in their states. */

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

/*     CTRSIZ      is the dimension of the counter array used by */
/*                 various SPICE subsystems to uniquely identify */
/*                 changes in their states. */

/* $ Author_and_Institution */

/*     B.V. Semenov    (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 29-JUL-2013 (BVS) */

/* -& */

/*     End of include file. */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     TARG       I   Target body. */
/*     ET         I   Target epoch. */
/*     REF        I   Target reference frame. */
/*     OBS        I   Observing body. */
/*     POS        O   Position of target. */
/*     LT         O   Light time. */

/* $ Detailed_Input */

/*     TARG        is the standard NAIF ID code for a target body. */

/*     ET          is the epoch (ephemeris time) at which the position */
/*                 of the target body is to be computed. */

/*     REF         is the name of the reference frame to */
/*                 which the vectors returned by the routine should */
/*                 be rotated. This may be any frame supported by */
/*                 the SPICELIB subroutine ZZREFCH0. */

/*     OBS         is the standard NAIF ID code for an observing body. */

/* $ Detailed_Output */

/*     POS         contains the position of the target */
/*                 body, relative to the observing body. This vector is */
/*                 rotated into the specified reference frame. Units */
/*                 are always km. */

/*     LT          is the one-way light time from the observing body */
/*                 to the geometric position of the target body at the */
/*                 specified epoch. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If insufficient ephemeris data has been loaded to compute */
/*        the necessary positions, the error SPICE(SPKINSUFFDATA) is */
/*        signalled. */

/* $ Files */

/*     See: $Restrictions. */

/* $ Particulars */

/*     ZZSPKGP0 computes the geometric position, T(t), of the target */
/*     body and the geometric position, O(t), of the observing body */
/*     relative to the first common center of motion.  Subtracting */
/*     O(t) from T(t) gives the geometric position of the target */
/*     body relative to the observer. */


/*        CENTER ----- O(t) */
/*            |      / */
/*            |     / */
/*            |    / */
/*            |   /  T(t) - O(t) */
/*            |  / */
/*           T(t) */


/*     The one-way light time, tau, is given by */


/*               | T(t) - O(t) | */
/*        tau = ----------------- */
/*                      c */


/*     For example, if the observing body is -94, the Mars Observer */
/*     spacecraft, and the target body is 401, Phobos, then the */
/*     first common center is probably 4, the Mars Barycenter. */
/*     O(t) is the position of -94 relative to 4 and T(t) is the */
/*     position of 401 relative to 4. */

/*     The center could also be the Solar System Barycenter, body 0. */
/*     For example, if the observer is 399, Earth, and the target */
/*     is 299, Venus, then O(t) would be the position of 399 relative */
/*     to 0 and T(t) would be the position of 299 relative to 0. */

/*     Ephemeris data from more than one segment may be required */
/*     to determine the positions of the target body and observer */
/*     relative to a common center.  ZZSPKGP0 reads as many segments */
/*     as necessary, from as many files as necessary, using files */
/*     that have been loaded by previous calls to SPKLEF (load */
/*     ephemeris file). */

/*     ZZSPKGP0 is similar to SPKGEO but returns geometric positions */
/*     only. */

/* $ Examples */

/*     The following code example computes the geometric */
/*     position of the moon with respect to the earth and */
/*     then prints the distance of the moon from the */
/*     the earth at a number of epochs. */

/*     Assume the SPK file SAMPLE.BSP contains ephemeris data */
/*     for the moon relative to earth over the time interval */
/*     from BEGIN to END. */

/*            INTEGER               EARTH */
/*            PARAMETER           ( EARTH = 399 ) */

/*            INTEGER               MOON */
/*            PARAMETER           ( MOON  = 301 ) */

/*            INTEGER               N */
/*            PARAMETER           ( N     = 100 ) */

/*            INTEGER               I */
/*            CHARACTER*(20)        UTC */
/*            DOUBLE PRECISION      BEGIN */
/*            DOUBLE PRECISION      DELTA */
/*            DOUBLE PRECISION      END */
/*            DOUBLE PRECISION      ET */
/*            DOUBLE PRECISION      POS ( 3 ) */
/*            DOUBLE PRECISION      LT */

/*            DOUBLE PRECISION      VNORM */

/*     C */
/*     C      Load the binary SPK ephemeris file. */
/*     C */
/*            CALL FURNSH ( 'SAMPLE.BSP' ) */

/*            . */
/*            . */
/*            . */

/*     C */
/*     C      Divide the interval of coverage [BEGIN,END] into */
/*     C      N steps.  At each step, compute the position, and */
/*     C      print out the epoch in UTC time and position norm. */
/*     C */
/*            DELTA = ( END - BEGIN ) / N */

/*            DO I = 0, N */

/*               ET = BEGIN + I*DELTA */

/*               CALL ZZSPKGP0 ( MOON, ET, 'J2000', EARTH, POS, LT ) */

/*               CALL ET2UTC ( ET, 'C', 0, UTC ) */

/*               WRITE (*,*) UTC, VNORM ( POS ) */

/*            END DO */

/* $ Restrictions */

/*     1) SPICE Private routine. */

/*     2) The ephemeris files to be used by ZZSPKGP0 must be loaded */
/*        by SPKLEF before ZZSPKGP0 is called. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman  (JPL) */
/*     B.V. Semenov  (JPL) */
/*     W.L. Taber    (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 08-JAN-2014 (BVS) */

/*        Updated to save the input frame name and POOL state counter */
/*        and to do frame name-ID conversion only if the counter has */
/*        changed. */

/*        Updated to map the input frame name to its ID by first calling */
/*        ZZNAMFRM, and then calling IRFNUM. The side effect of this */
/*        change is that now the frame with the fixed name 'DEFAULT' */
/*        that can be associated with any code via CHGIRF's entry point */
/*        IRFDEF will be fully masked by a frame with indentical name */
/*        defined via a text kernel. Previously the CHGIRF's 'DEFAULT' */
/*        frame masked the text kernel frame with the same name. */

/*        Replaced SPKLEF with FURNSH and fixed errors in Examples. */

/* -    SPICELIB Version 1.1.0, 09-NOV-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in VADD calls. */

/* -    SPICELIB Version 1.0.0, 05-JAN-2005 (NJB) */

/*        Based on SPICELIB Version 1.1.0, 05-JAN-2005 (NJB) */

/* -& */
/* $ Index_Entries */

/*     geometric position of one body relative to another */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.1.0, 09-NOV-2005 (NJB) */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in VADD calls. */

/* -& */

/*     This is the idea: */

/*     Every body moves with respect to some center. The center */
/*     is itself a body, which in turn moves about some other */
/*     center.  If we begin at the target body (T), follow */
/*     the chain, */

/*                                   T */
/*                                     \ */
/*           SSB                        \ */
/*               \                     C[1] */
/*                \                     / */
/*                 \                   / */
/*                  \                 / */
/*                   \               / */
/*                  C[3]-----------C[2] */

/*     and avoid circular definitions (A moves about B, and B moves */
/*     about A), eventually we get the position relative to the solar */
/*     system barycenter (which, for our purposes, doesn't move). */
/*     Thus, */

/*        T    = T     + C[1]     + C[2]     + ... + C[n] */
/*         SSB    C[1]       C[2]       [C3]             SSB */

/*     where */

/*        X */
/*         Y */

/*     is the position of body X relative to body Y. */

/*     However, we don't want to follow each chain back to the SSB */
/*     if it isn't necessary.  Instead we will just follow the chain */
/*     of the target body and follow the chain of the observing body */
/*     until we find a common node in the tree. */

/*     In the example below, C is the first common node.  We compute */
/*     the position of TARG relative to C and the position of OBS */
/*     relative to C, then subtract the two positions. */

/*                                   TARG */
/*                                     \ */
/*           SSB                        \ */
/*               \                       A */
/*                \                     /            OBS */
/*                 \                   /              | */
/*                  \                 /               | */
/*                   \               /                | */
/*                    B-------------C-----------------D */




/*     SPICELIB functions */


/*     Local parameters */


/*     CHLEN is the maximum length of a chain.  That is, */
/*     it is the maximum number of bodies in the chain from */
/*     the target or observer to the SSB. */


/*     Saved frame name length. */


/*     Local variables */


/*     Saved frame name/ID item declarations. */


/*     Saved frame name/ID items. */


/*     Initial values. */


/*     In-line Function Definitions */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "ZZSPKGP0", (ftnlen)8);
    }

/*     Initialization. */

    if (__state->first) {

/*        Initialize counter. */

	zzctruin_(__global_state, __state->svctr1);
	__state->first = FALSE_;
    }

/*     We take care of the obvious case first.  It TARG and OBS are the */
/*     same we can just fill in zero. */

    if (*targ == *obs) {
	*lt = 0.;
	cleard_(__global_state, &__state->c__3, pos);
	chkout_(__global_state, "ZZSPKGP0", (ftnlen)8);
	return 0;
    }

/*     CTARG contains the integer codes of the bodies in the */
/*     target body chain, beginning with TARG itself and then */
/*     the successive centers of motion. */

/*     STARG(1,I) is the position of the target body relative */
/*     to CTARG(I).  The id-code of the frame of this position is */
/*     stored in TFRAME(I). */

/*     COBS and SOBS will contain the centers and positions of the */
/*     observing body.  (They are single elements instead of arrays */
/*     because we only need the current center and position of the */
/*     observer relative to it.) */

/*     First, we construct CTARG and STARG.  CTARG(1) is */
/*     just the target itself, and STARG(1,1) is just a zero */
/*     vector, that is, the position of the target relative */
/*     to itself. */

/*     Then we follow the chain, filling up CTARG and STARG */
/*     as we go.  We use SPKSFS to search through loaded */
/*     files to find the first segment applicable to CTARG(1) */
/*     and time ET.  Then we use SPKPVN to compute the position */
/*     of the body CTARG(1) at ET in the segment that was found */
/*     and get its center and frame of motion (CTARG(2) and TFRAME(2). */

/*     We repeat the process for CTARG(2) and so on, until */
/*     there is no data found for some CTARG(I) or until we */
/*     reach the SSB. */

/*     Next, we find centers and positions in a similar manner */
/*     for the observer.  It's a similar construction as */
/*     described above, but I is always 1.  COBS and SOBS */
/*     are overwritten with each new center and position, */
/*     beginning at OBS.  However, we stop when we encounter */
/*     a common center of motion, that is when COBS is equal */
/*     to CTARG(I) for some I. */

/*     Finally, we compute the desired position of the target */
/*     relative to the observer by subtracting the position of */
/*     the observing body relative to the common node from */
/*     the position of the target body relative to the common */
/*     node. */

/*     CTPOS is the position in CTARG of the common node. */

/*     Since the upgrade to use hashes and counter bypass ZZNAMFRM */
/*     became more efficient in looking up frame IDs than IRFNUM. So the */
/*     original order of calls "IRFNUM first, NAMFRM second" was */
/*     switched to "ZZNAMFRM first, IRFNUM second". */

/*     The call to IRFNUM, now redundant for built-in inertial frames, */
/*     was preserved to for a sole reason -- to still support the */
/*     ancient and barely documented ability for the users to associate */
/*     a frame with the fixed name 'DEFAULT' with any CHGIRF inertial */
/*     frame code via CHGIRF's entry point IRFDEF. */

/*     Note that in the case of ZZNAMFRM's failure to resolve name and */
/*     IRFNUM's success to do so, the code returned by IRFNUM for */
/*     'DEFAULT' frame is *not* copied to the saved code SVREFI (which */
/*     would be set to 0 by ZZNAMFRM) to make sure that on subsequent */
/*     calls ZZNAMFRM does not do a bypass (as SVREFI always forced look */
/*     up) and calls IRFNUM again to reset the 'DEFAULT's frame ID */
/*     should it change between the calls. */

    zznamfrm_(__global_state, __state->svctr1, __state->svref, &
	    __state->svrefi, ref, &refid, (ftnlen)32, ref_len);
    if (refid == 0) {
	irfnum_(__global_state, ref, &refid, ref_len);
    }
    if (refid == 0) {
	if (frstnp_(__global_state, ref, ref_len) > 0) {
	    setmsg_(__global_state, "The string supplied to specify the refe"
		    "rence frame, ('#') contains non-printing characters.  Th"
		    "e two most common causes for this kind of error are: 1. "
		    "an error in the call to ZZSPKGP0; 2. an uninitialized va"
		    "riable. ", (ftnlen)215);
	    errch_(__global_state, "#", ref, (ftnlen)1, ref_len);
	} else if (s_cmp(&__global_state->f2c, ref, " ", ref_len, (ftnlen)1) 
		== 0) {
	    setmsg_(__global_state, "The string supplied to specify the refe"
		    "rence frame is blank.  The most common cause for this ki"
		    "nd of error is an uninitialized variable. ", (ftnlen)137);
	} else {
	    setmsg_(__global_state, "The string supplied to specify the refe"
		    "rence frame was '#'.  This frame is not recognized. Poss"
		    "ible causes for this error are: 1. failure to load the f"
		    "rame definition into the kernel pool; 2. An out-of-date "
		    "edition of the toolkit. ", (ftnlen)231);
	    errch_(__global_state, "#", ref, (ftnlen)1, ref_len);
	}
	sigerr_(__global_state, "SPICE(UNKNOWNFRAME)", (ftnlen)19);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "ZZSPKGP0", (ftnlen)8);
	    return 0;
	}
    }

/*     Fill in CTARG and STARG until no more data is found */
/*     or until we reach the SSB.  If the chain gets too */
/*     long to fit in CTARG, that is if I equals CHLEN, */
/*     then overwrite the last elements of CTARG and STARG. */

/*     Note the check for FAILED in the loop.  If SPKSFS */
/*     or SPKPVN happens to fail during execution, and the */
/*     current error handling action is to NOT abort, then */
/*     FOUND may be stuck at TRUE, CTARG(I) will never */
/*     become zero, and the loop will execute indefinitely. */


/*     Construct CTARG and STARG.  Begin by assigning the */
/*     first elements:  TARG and the position of TARG relative */
/*     to itself. */

    i__ = 1;
    ctarg[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge(&
	    __global_state->f2c, "ctarg", i__1, "zzspkgp0_", (ftnlen)610)] = *
	    targ;
    found = TRUE_;
    cleard_(__global_state, &__state->c__6, &starg[(i__1 = i__ * 6 - 6) < 120 
	    && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "starg", i__1, 
	    "zzspkgp0_", (ftnlen)613)]);
    while(found && i__ < 20 && ctarg[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? 
	    i__1 : s_rnge(&__global_state->f2c, "ctarg", i__1, "zzspkgp0_", (
	    ftnlen)615)] != *obs && ctarg[(i__2 = i__ - 1) < 20 && 0 <= i__2 ?
	     i__2 : s_rnge(&__global_state->f2c, "ctarg", i__2, "zzspkgp0_", (
	    ftnlen)615)] != 0) {

/*        Find a file and segment that has position */
/*        data for CTARG(I). */

	spksfs_(__global_state, &ctarg[(i__1 = i__ - 1) < 20 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "ctarg", i__1, "zzspkgp0_"
		, (ftnlen)624)], et, &handle, descr, ident, &found, (ftnlen)
		40);
	if (found) {

/*           Get the position of CTARG(I) relative to some */
/*           center of motion.  This new center goes in */
/*           CTARG(I+1) and the position is called STEMP. */

	    ++i__;
	    spkpvn_(__global_state, &handle, descr, et, &tframe[(i__1 = i__ - 
		    1) < 20 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c,
		     "tframe", i__1, "zzspkgp0_", (ftnlen)634)], &starg[(i__2 
		    = i__ * 6 - 6) < 120 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "starg", i__2, "zzspkgp0_", (ftnlen)
		    634)], &ctarg[(i__3 = i__ - 1) < 20 && 0 <= i__3 ? i__3 : 
		    s_rnge(&__global_state->f2c, "ctarg", i__3, "zzspkgp0_", (
		    ftnlen)634)]);

/*           Here's what we have.  STARG is the position of CTARG(I-1) */
/*           relative to CTARG(I) in reference frame TFRAME(I) */

/*           If one of the routines above failed during */
/*           execution, we just give up and check out. */

	    if (failed_(__global_state)) {
		chkout_(__global_state, "ZZSPKGP0", (ftnlen)8);
		return 0;
	    }
	}
    }
    tframe[0] = tframe[1];

/*     If the loop above ended because we ran out of */
/*     room in the arrays CTARG and STARG, then we */
/*     continue finding positions but we overwrite the */
/*     last elements of CTARG and STARG. */

/*     If, as a result, the first common node is */
/*     overwritten, we'll just have to settle for */
/*     the last common node.  This will cause a small */
/*     loss of precision, but it's better than other */
/*     alternatives. */

    if (i__ == 20) {
	while(found && ctarg[19] != 0 && ctarg[19] != *obs) {

/*           Find a file and segment that has position */
/*           data for CTARG(CHLEN). */

	    spksfs_(__global_state, &ctarg[19], et, &handle, descr, ident, &
		    found, (ftnlen)40);
	    if (found) {

/*              Get the position of CTARG(CHLEN) relative to */
/*              some center of motion.  The new center */
/*              overwrites the old.  The position is called */
/*              STEMP. */

		spkpvn_(__global_state, &handle, descr, et, &tmpfrm, stemp, &
			ctarg[19]);

/*              Add STEMP to the position of TARG relative to */
/*              the old center to get the position of TARG */
/*              relative to the new center.  Overwrite */
/*              the last element of STARG. */

		if (tframe[19] == tmpfrm) {
		    moved_(__global_state, &starg[114], &__state->c__3, vtemp)
			    ;
		} else if (tmpfrm > 0 && tmpfrm <= 21 && tframe[19] > 0 && 
			tframe[19] <= 21) {
		    irfrot_(__global_state, &tframe[19], &tmpfrm, rot);
		    mxv_(__global_state, rot, &starg[114], vtemp);
		} else {
		    zzrefch0_(__global_state, &tframe[19], &tmpfrm, et, 
			    psxfrm);
		    if (failed_(__global_state)) {
			chkout_(__global_state, "ZZSPKGP0", (ftnlen)8);
			return 0;
		    }
		    mxv_(__global_state, psxfrm, &starg[114], vtemp);
		}
		vadd_(__global_state, vtemp, stemp, &starg[114]);
		tframe[19] = tmpfrm;

/*              If one of the routines above failed during */
/*              execution, we just give up and check out. */

		if (failed_(__global_state)) {
		    chkout_(__global_state, "ZZSPKGP0", (ftnlen)8);
		    return 0;
		}
	    }
	}
    }
    nct = i__;

/*     NCT is the number of elements in CTARG, */
/*     the chain length.  We have in hand the following information */

/*        STARG(1...3,K)  position of body */
/*        CTARG(K-1)      relative to body CTARG(K) in the frame */
/*        TFRAME(K) */


/*     For K = 2,..., NCT. */

/*     CTARG(1) = TARG */
/*     STARG(1...3,1) = ( 0, 0, 0 ) */
/*     TFRAME(1)      = TFRAME(2) */


/*     Now follow the observer's chain.  Assign */
/*     the first values for COBS and SOBS. */

    cobs = *obs;
    cleard_(__global_state, &__state->c__6, sobs);

/*     Perhaps we have a common node already. */
/*     If so it will be the last node on the */
/*     list CTARG. */

/*     We let CTPOS will be the position of the common */
/*     node in CTARG if one is found.  It will */
/*     be zero if COBS is not found in CTARG. */

    if (ctarg[(i__1 = nct - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge(&
	    __global_state->f2c, "ctarg", i__1, "zzspkgp0_", (ftnlen)769)] == 
	    cobs) {
	ctpos = nct;
	cframe = tframe[(i__1 = ctpos - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "tframe", i__1, "zzspkgp0_", (ftnlen)771)
		];
    } else {
	ctpos = 0;
    }

/*     Repeat the same loop as above, but each time */
/*     we encounter a new center of motion, check to */
/*     see if it is a common node.  (When CTPOS is */
/*     not zero, CTARG(CTPOS) is the first common node.) */

/*     Note that we don't need a centers array nor a */
/*     positions array, just a single center and position */
/*     is sufficient --- we just keep overwriting them. */
/*     When the common node is found, we have everything */
/*     we need in that one center (COBS) and position */
/*     (SOBS-position of the target relative to COBS). */

    found = TRUE_;
    nofrm = TRUE_;
    legs = 0;
    while(found && cobs != 0 && ctpos == 0) {

/*        Find a file and segment that has position */
/*        data for COBS. */

	spksfs_(__global_state, &cobs, et, &handle, descr, ident, &found, (
		ftnlen)40);
	if (found) {

/*           Get the position of COBS; call it STEMP. */
/*           The center of motion of COBS becomes the */
/*           new COBS. */

	    if (legs == 0) {
		spkpvn_(__global_state, &handle, descr, et, &tmpfrm, sobs, &
			cobs);
	    } else {
		spkpvn_(__global_state, &handle, descr, et, &tmpfrm, stemp, &
			cobs);
	    }
	    if (nofrm) {
		nofrm = FALSE_;
		cframe = tmpfrm;
	    }

/*           Add STEMP to the position of OBS relative to */
/*           the old COBS to get the position of OBS */
/*           relative to the new COBS. */

	    if (cframe == tmpfrm) {

/*              On the first leg of the position of the observer, we */
/*              don't have to add anything, the position of the */
/*              observer is already in SOBS.  We only have to add when */
/*              the number of legs in the observer position is one or */
/*              greater. */

		if (legs > 0) {
		    vadd_(__global_state, sobs, stemp, vtemp);
		    vequ_(__global_state, vtemp, sobs);
		}
	    } else if (tmpfrm > 0 && tmpfrm <= 21 && cframe > 0 && cframe <= 
		    21) {
		irfrot_(__global_state, &cframe, &tmpfrm, rot);
		mxv_(__global_state, rot, sobs, vtemp);
		vadd_(__global_state, vtemp, stemp, sobs);
		cframe = tmpfrm;
	    } else {
		zzrefch0_(__global_state, &cframe, &tmpfrm, et, psxfrm);
		if (failed_(__global_state)) {
		    chkout_(__global_state, "ZZSPKGP0", (ftnlen)8);
		    return 0;
		}
		mxv_(__global_state, psxfrm, sobs, vtemp);
		vadd_(__global_state, vtemp, stemp, sobs);
		cframe = tmpfrm;
	    }

/*           Check failed.  We don't want to loop */
/*           indefinitely. */

	    if (failed_(__global_state)) {
		chkout_(__global_state, "ZZSPKGP0", (ftnlen)8);
		return 0;
	    }

/*           We now have one more leg of the path for OBS.  Set */
/*           LEGS to reflect this.  Then see if the new center */
/*           is a common node. If not, repeat the loop. */

	    ++legs;
	    ctpos = isrchi_(__global_state, &cobs, &nct, ctarg);
	}
    }

/*     If CTPOS is zero at this point, it means we */
/*     have not found a common node though we have */
/*     searched through all the available data. */

    if (ctpos == 0) {
	bodc2n_(__global_state, targ, tname, &found, (ftnlen)40);
	if (found) {
	    prefix_(__global_state, "# (", &__state->c__0, tname, (ftnlen)3, (
		    ftnlen)40);
	    suffix_(__global_state, ")", &__state->c__0, tname, (ftnlen)1, (
		    ftnlen)40);
	    repmi_(__global_state, tname, "#", targ, tname, (ftnlen)40, (
		    ftnlen)1, (ftnlen)40);
	} else {
	    intstr_(__global_state, targ, tname, (ftnlen)40);
	}
	bodc2n_(__global_state, obs, oname, &found, (ftnlen)40);
	if (found) {
	    prefix_(__global_state, "# (", &__state->c__0, oname, (ftnlen)3, (
		    ftnlen)40);
	    suffix_(__global_state, ")", &__state->c__0, oname, (ftnlen)1, (
		    ftnlen)40);
	    repmi_(__global_state, oname, "#", obs, oname, (ftnlen)40, (
		    ftnlen)1, (ftnlen)40);
	} else {
	    intstr_(__global_state, obs, oname, (ftnlen)40);
	}
	setmsg_(__global_state, "Insufficient ephemeris data has been loaded"
		" to compute the position of TARG relative to OBS at the ephe"
		"meris epoch #. ", (ftnlen)118);
	etcal_(__global_state, et, tstring, (ftnlen)80);
	errch_(__global_state, "TARG", tname, (ftnlen)4, (ftnlen)40);
	errch_(__global_state, "OBS", oname, (ftnlen)3, (ftnlen)40);
	errch_(__global_state, "#", tstring, (ftnlen)1, (ftnlen)80);
	sigerr_(__global_state, "SPICE(SPKINSUFFDATA)", (ftnlen)20);
	chkout_(__global_state, "ZZSPKGP0", (ftnlen)8);
	return 0;
    }

/*     If CTPOS is not zero, then we have reached a */
/*     common node, specifically, */

/*        CTARG(CTPOS) = COBS = CENTER */

/*     (in diagram below).  The POSITION of the target */
/*     (TARG) relative to the observer (OBS) is just */

/*        STARG(1,CTPOS) - SOBS. */



/*                     SOBS */
/*         CENTER ---------------->OBS */
/*            |                  . */
/*            |                . N */
/*         S  |              . O */
/*         T  |            . I */
/*         A  |          . T */
/*         R  |        . I */
/*         G  |      . S */
/*            |    . O */
/*            |  . P */
/*            V L */
/*           TARG */


/*     And the light-time between them is just */

/*               | POSITION | */
/*          LT = --------- */
/*                   c */


/*     Compute the position of the target relative to CTARG(CTPOS) */

    if (ctpos == 1) {
	tframe[0] = cframe;
    }
    i__1 = ctpos - 1;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if (tframe[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "tframe", i__2, "zzspkgp0_", (ftnlen)967)
		] == tframe[(i__3 = i__) < 20 && 0 <= i__3 ? i__3 : s_rnge(&
		__global_state->f2c, "tframe", i__3, "zzspkgp0_", (ftnlen)967)
		]) {
	    vadd_(__global_state, &starg[(i__2 = i__ * 6 - 6) < 120 && 0 <= 
		    i__2 ? i__2 : s_rnge(&__global_state->f2c, "starg", i__2, 
		    "zzspkgp0_", (ftnlen)969)], &starg[(i__3 = (i__ + 1) * 6 
		    - 6) < 120 && 0 <= i__3 ? i__3 : s_rnge(&
		    __global_state->f2c, "starg", i__3, "zzspkgp0_", (ftnlen)
		    969)], stemp);
	    moved_(__global_state, stemp, &__state->c__3, &starg[(i__2 = (i__ 
		    + 1) * 6 - 6) < 120 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "starg", i__2, "zzspkgp0_", (ftnlen)
		    970)]);
	} else if (tframe[(i__3 = i__) < 20 && 0 <= i__3 ? i__3 : s_rnge(&
		__global_state->f2c, "tframe", i__3, "zzspkgp0_", (ftnlen)972)
		] > 0 && tframe[(i__3 = i__) < 20 && 0 <= i__3 ? i__3 : 
		s_rnge(&__global_state->f2c, "tframe", i__3, "zzspkgp0_", (
		ftnlen)972)] <= 21 && tframe[(i__2 = i__ - 1) < 20 && 0 <= 
		i__2 ? i__2 : s_rnge(&__global_state->f2c, "tframe", i__2, 
		"zzspkgp0_", (ftnlen)972)] > 0 && tframe[(i__2 = i__ - 1) < 
		20 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "tframe"
		, i__2, "zzspkgp0_", (ftnlen)972)] <= 21) {
	    irfrot_(__global_state, &tframe[(i__2 = i__ - 1) < 20 && 0 <= 
		    i__2 ? i__2 : s_rnge(&__global_state->f2c, "tframe", i__2,
		     "zzspkgp0_", (ftnlen)974)], &tframe[(i__3 = i__) < 20 && 
		    0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, "tframe", 
		    i__3, "zzspkgp0_", (ftnlen)974)], rot);
	    mxv_(__global_state, rot, &starg[(i__2 = i__ * 6 - 6) < 120 && 0 
		    <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "starg", 
		    i__2, "zzspkgp0_", (ftnlen)975)], stemp);
	    vadd_(__global_state, stemp, &starg[(i__2 = (i__ + 1) * 6 - 6) < 
		    120 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "starg", i__2, "zzspkgp0_", (ftnlen)976)], vtemp);
	    moved_(__global_state, vtemp, &__state->c__3, &starg[(i__2 = (i__ 
		    + 1) * 6 - 6) < 120 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "starg", i__2, "zzspkgp0_", (ftnlen)
		    977)]);
	} else {
	    zzrefch0_(__global_state, &tframe[(i__2 = i__ - 1) < 20 && 0 <= 
		    i__2 ? i__2 : s_rnge(&__global_state->f2c, "tframe", i__2,
		     "zzspkgp0_", (ftnlen)981)], &tframe[(i__3 = i__) < 20 && 
		    0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, "tframe", 
		    i__3, "zzspkgp0_", (ftnlen)981)], et, psxfrm);
	    if (failed_(__global_state)) {
		chkout_(__global_state, "ZZSPKGP0", (ftnlen)8);
		return 0;
	    }
	    mxv_(__global_state, psxfrm, &starg[(i__2 = i__ * 6 - 6) < 120 && 
		    0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "starg", 
		    i__2, "zzspkgp0_", (ftnlen)988)], stemp);
	    vadd_(__global_state, stemp, &starg[(i__2 = (i__ + 1) * 6 - 6) < 
		    120 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "starg", i__2, "zzspkgp0_", (ftnlen)989)], vtemp);
	    moved_(__global_state, vtemp, &__state->c__3, &starg[(i__2 = (i__ 
		    + 1) * 6 - 6) < 120 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "starg", i__2, "zzspkgp0_", (ftnlen)
		    990)]);
	}
    }

/*     To avoid unnecessary frame transformations we'll do */
/*     a bit of extra decision making here.  It's a lot */
/*     faster to make logical checks than it is to compute */
/*     frame transformations. */

    if (tframe[(i__1 = ctpos - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge(&
	    __global_state->f2c, "tframe", i__1, "zzspkgp0_", (ftnlen)1003)] 
	    == cframe) {
	vsub_(__global_state, &starg[(i__1 = ctpos * 6 - 6) < 120 && 0 <= 
		i__1 ? i__1 : s_rnge(&__global_state->f2c, "starg", i__1, 
		"zzspkgp0_", (ftnlen)1005)], sobs, pos);
    } else if (tframe[(i__1 = ctpos - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge(&
	    __global_state->f2c, "tframe", i__1, "zzspkgp0_", (ftnlen)1007)] 
	    == refid) {

/*        If the last frame associated with the target is already */
/*        in the requested output frame, we convert the position of */
/*        the observer to that frame and then subtract the position */
/*        of the observer from the position of the target. */

	if (refid > 0 && refid <= 21 && cframe > 0 && cframe <= 21) {
	    irfrot_(__global_state, &cframe, &refid, rot);
	    mxv_(__global_state, rot, sobs, stemp);
	} else {
	    zzrefch0_(__global_state, &cframe, &refid, et, psxfrm);
	    if (failed_(__global_state)) {
		chkout_(__global_state, "ZZSPKGP0", (ftnlen)8);
		return 0;
	    }
	    mxv_(__global_state, psxfrm, sobs, stemp);
	}

/*        We've now transformed SOBS into the requested reference frame. */
/*        Set CFRAME to reflect this. */

	cframe = refid;
	vsub_(__global_state, &starg[(i__1 = ctpos * 6 - 6) < 120 && 0 <= 
		i__1 ? i__1 : s_rnge(&__global_state->f2c, "starg", i__1, 
		"zzspkgp0_", (ftnlen)1038)], stemp, pos);
    } else if (cframe > 0 && cframe <= 21 && tframe[(i__1 = ctpos - 1) < 20 &&
	     0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "tframe", i__1, 
	    "zzspkgp0_", (ftnlen)1041)] > 0 && tframe[(i__1 = ctpos - 1) < 20 
	    && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "tframe", i__1,
	     "zzspkgp0_", (ftnlen)1041)] <= 21) {

/*        If both frames are inertial we use IRFROT instead of */
/*        ZZREFCH0 to get things into a common frame. */

	irfrot_(__global_state, &tframe[(i__1 = ctpos - 1) < 20 && 0 <= i__1 ?
		 i__1 : s_rnge(&__global_state->f2c, "tframe", i__1, "zzspkg"
		"p0_", (ftnlen)1047)], &cframe, rot);
	mxv_(__global_state, rot, &starg[(i__1 = ctpos * 6 - 6) < 120 && 0 <= 
		i__1 ? i__1 : s_rnge(&__global_state->f2c, "starg", i__1, 
		"zzspkgp0_", (ftnlen)1048)], stemp);
	vsub_(__global_state, stemp, sobs, pos);
    } else {

/*        Use the more general routine ZZREFCH0 to make the */
/*        transformation. */

	zzrefch0_(__global_state, &tframe[(i__1 = ctpos - 1) < 20 && 0 <= 
		i__1 ? i__1 : s_rnge(&__global_state->f2c, "tframe", i__1, 
		"zzspkgp0_", (ftnlen)1056)], &cframe, et, psxfrm);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "ZZSPKGP0", (ftnlen)8);
	    return 0;
	}
	mxv_(__global_state, psxfrm, &starg[(i__1 = ctpos * 6 - 6) < 120 && 0 
		<= i__1 ? i__1 : s_rnge(&__global_state->f2c, "starg", i__1, 
		"zzspkgp0_", (ftnlen)1063)], stemp);
	vsub_(__global_state, stemp, sobs, pos);
    }

/*     Finally, rotate as needed into the requested frame. */

    if (cframe == refid) {

/*        We don't have to do anything in this case. */

    } else if (refid > 0 && refid <= 21 && cframe > 0 && cframe <= 21) {

/*        Since both frames are inertial, we use the more direct */
/*        routine IRFROT to get the transformation to REFID. */

	irfrot_(__global_state, &cframe, &refid, rot);
	mxv_(__global_state, rot, pos, stemp);
	moved_(__global_state, stemp, &__state->c__3, pos);
    } else {
	zzrefch0_(__global_state, &cframe, &refid, et, psxfrm);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "ZZSPKGP0", (ftnlen)8);
	    return 0;
	}
	mxv_(__global_state, psxfrm, pos, stemp);
	moved_(__global_state, stemp, &__state->c__3, pos);
    }
    *lt = vnorm_(__global_state, pos) / clight_(__global_state);
    chkout_(__global_state, "ZZSPKGP0", (ftnlen)8);
    return 0;
} /* zzspkgp0_ */

