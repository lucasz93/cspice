/* zzgfspq.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzgfspq_init_t __zzgfspq_init;
static zzgfspq_state_t* get_zzgfspq_state(cspice_t* state) {
	if (!state->zzgfspq)
		state->zzgfspq = __cspice_allocate_module(sizeof(
	zzgfspq_state_t), &__zzgfspq_init, sizeof(__zzgfspq_init));
	return state->zzgfspq;

}

/* $Procedure ZZGFSPQ ( GF, separation quantity ) */
/* Subroutine */ int zzgfspq_(cspice_t* __global_state, doublereal *et, 
	integer *targ1, integer *targ2, doublereal *r1, doublereal *r2, 
	integer *obs, char *abcorr, char *ref, doublereal *value, ftnlen 
	abcorr_len, ftnlen ref_len)
{
    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    extern doublereal vsep_(cspice_t*, doublereal *, doublereal *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    doublereal theta;
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    extern doublereal vnorm_(cspice_t*, doublereal *);
    doublereal range1;
    doublereal range2;
    extern logical failed_(cspice_t*);
    doublereal lt;
    extern doublereal dasine_(cspice_t*, doublereal *, doublereal *);
    extern doublereal halfpi_(cspice_t*);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int spkezp_(cspice_t*, integer *, doublereal *, 
	    char *, char *, integer *, doublereal *, doublereal *, ftnlen, 
	    ftnlen);
    extern logical return_(cspice_t*);
    doublereal pv1[3];
    doublereal pv2[3];
    doublereal ang1;
    doublereal ang2;


    /* Module state */
    zzgfspq_state_t* __state = get_zzgfspq_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Compute the angular separation between the limbs of two objects. */

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

/*     GEOMETRY */
/*     ANGLE */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Ephemeris seconds past J2000 TDB */
/*     TARG1      I   NAIF ID for first target */
/*     TARG2      I   NAIF ID for second target */
/*     R1         I   Radius of a spherical model for TARG1 */
/*     R2         I   Radius of a spherical model for TARG2 */
/*     OBS        I   NAIF ID of observer */
/*     ABCORR     I   Aberration correction flag */
/*     REF        I   Reference frame of the angular separation */
/*     VALUE      O   Value of angular separation between objects */

/* $ Detailed_Input */

/*     ET       is the time in ephemeris seconds past J2000 TDB at */
/*              which the separation is to be measured. */

/*     TARG1 */
/*     TARG2    the NAIF IDs of the two objects for which to */
/*              determine the angular separation. */

/*     R1 */
/*     R2       are the radii of the two objects TARG1 and TARG2 */
/*              respectively. */

/*     OBS      the NAIF ID identifying the body observing */
/*              TARG1 and TARG2. */

/*     ABCORR   the string description of the aberration corrections */
/*              to apply to the state evaluations to account for */
/*              one-way light time and stellar aberration. */

/*              This routine accepts the same aberration corrections */
/*              as does the SPICE routine SPKEZR. See the header of */
/*              SPKEZR for a detailed description of the aberration */
/*              correction options. For convenience, the options are */
/*              listed below: */

/*                 'NONE'     Apply no correction. */

/*                 'LT'       "Reception" case:  correct for */
/*                            one-way light time using a Newtonian */
/*                            formulation. */

/*                 'LT+S'     "Reception" case:  correct for */
/*                            one-way light time and stellar */
/*                            aberration using a Newtonian */
/*                            formulation. */

/*                 'CN'       "Reception" case:  converged */
/*                            Newtonian light time correction. */

/*                 'CN+S'     "Reception" case:  converged */
/*                            Newtonian light time and stellar */
/*                            aberration corrections. */

/*                 'XLT'      "Transmission" case:  correct for */
/*                            one-way light time using a Newtonian */
/*                            formulation. */

/*                 'XLT+S'    "Transmission" case:  correct for */
/*                            one-way light time and stellar */
/*                            aberration using a Newtonian */
/*                            formulation. */

/*                 'XCN'      "Transmission" case:  converged */
/*                            Newtonian light time correction. */

/*                 'XCN+S'    "Transmission" case:  converged */
/*                            Newtonian light time and stellar */
/*                            aberration corrections. */

/*                 The ABCORR string lacks sensitivity to case, leading */
/*                 and trailing blanks. */

/*     REF         is the name of the reference frame relative to which */
/*                 the angular separation should be expressed. This may */
/*                 be any frame supported by the SPICE system, including */
/*                 built-in frames (documented in the Frames Required */
/*                 Reading) and frames defined by a loaded frame kernel. */

/*                 When REF designates a non-inertial frame, the */
/*                 orientation of the frame is evaluated at an epoch */
/*                 dependent on the selected aberration correction. */

/* $ Detailed_Output */

/*     VALUE   is the light-time (and stellar aberration corrected */
/*             if this feature is enabled) separation of the two */
/*             objects TARG1 and TARG2 as observed from OBS. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) SPICE(BADRADIUS) signals if either R1 or R2 have a negative */
/*        value. */

/*     2) If the ephemeris data required to perform the needed state */
/*        look-ups are not loaded, routines called by this routine */
/*        will signal the error SPICE(SPKINSUFFDATA). */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine determines the apparent separation between the limbs */
/*     of two objects as observed from a third.  The value reported is */
/*     corrected for light time. Moreover, if at the time this routine */
/*     is called, stellar aberration corrections are enabled, this */
/*     correction will also be applied to the apparent positions of the */
/*     centers of the two objects. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber     (JPL) */
/*     L.S. Elson     (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.1, 28-JUN-2012 (EDW) */

/*        Minor edits to header, correcting spelling error and improving */
/*        syntax of Exceptions. */

/*        Corrected a typo in SETMSG error message where TARG1 was quoted */
/*        twice instead of quoting TARG1 and TARG2. This edit does change */
/*        the error message output. */

/* -    SPICELIB Version 1.0.0, 03-MAR-2009 (EDW) */

/* -& */
/* $ Index_Entries */

/*     compute the apparent relative angular separation */

/* -& */

/*     SPICELIB functions. */


/*     Local Variables. */


/*     ATOL is a tolerance value for computing arc sine. */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "ZZGFSPQ", (ftnlen)7);

/*     First check for bad inputs. */

    if (*r1 < 0. || *r2 < 0.) {
	setmsg_(__global_state, "A negative radius for a body was encountere"
		"d. The radius for body # was given as #, the radius of body "
		"# was given as #. ", (ftnlen)121);
	errint_(__global_state, "#", targ1, (ftnlen)1);
	errdp_(__global_state, "#", r1, (ftnlen)1);
	errint_(__global_state, "#", targ2, (ftnlen)1);
	errdp_(__global_state, "#", r2, (ftnlen)1);
	sigerr_(__global_state, "SPICE(BADRADIUS)", (ftnlen)16);
	chkout_(__global_state, "ZZGFSPQ", (ftnlen)7);
	return 0;
    }

/*     Get the state of the TARG1, TARG2 objects relative to OBS. */

    spkezp_(__global_state, targ1, et, ref, abcorr, obs, pv1, &lt, ref_len, 
	    abcorr_len);
    if (failed_(__global_state)) {
	chkout_(__global_state, "ZZGFSPQ", (ftnlen)7);
	return 0;
    }
    spkezp_(__global_state, targ2, et, ref, abcorr, obs, pv2, &lt, ref_len, 
	    abcorr_len);
    if (failed_(__global_state)) {
	chkout_(__global_state, "ZZGFSPQ", (ftnlen)7);
	return 0;
    }

/*     Compute the range to the objects of interest. */

    range1 = vnorm_(__global_state, pv1);
    range2 = vnorm_(__global_state, pv2);

/*     Compute the apparent angular radii as seen from OBS. */

    if (range1 > *r1) {
	d__1 = *r1 / range1;
	ang1 = dasine_(__global_state, &d__1, &__state->c_b12);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "ZZGFSPQ", (ftnlen)7);
	    return 0;
	}
    } else {
	ang1 = halfpi_(__global_state);
    }
    if (range2 > *r2) {
	d__1 = *r2 / range2;
	ang2 = dasine_(__global_state, &d__1, &__state->c_b12);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "ZZGFSPQ", (ftnlen)7);
	    return 0;
	}
    } else {
	ang2 = halfpi_(__global_state);
    }

/*     Finally compute the apparent separation. */

    theta = vsep_(__global_state, pv1, pv2);
    *value = theta - ang1 - ang2;
    chkout_(__global_state, "ZZGFSPQ", (ftnlen)7);
    return 0;
} /* zzgfspq_ */

