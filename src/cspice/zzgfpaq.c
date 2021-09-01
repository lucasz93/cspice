/* zzgfpaq.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int zzgfpaq_state_t;
static zzgfpaq_state_t* get_zzgfpaq_state(cspice_t* state) {
	return 0;
}

/* $Procedure ZZGFPAQ ( Private --- GF, phase angle between bodies ) */
/* Subroutine */ int zzgfpaq_(cspice_t* __global_state, doublereal *et, 
	integer *targ, integer *illmn, integer *obs, char *abcorr, doublereal 
	*value, ftnlen abcorr_len)
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern doublereal vsep_(cspice_t*, doublereal *, doublereal *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern logical eqstr_(cspice_t*, char *, char *, ftnlen, ftnlen);
    extern logical failed_(cspice_t*);
    extern doublereal pi_(cspice_t*);
    doublereal lt;
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int spkezp_(cspice_t*, integer *, doublereal *, 
	    char *, char *, integer *, doublereal *, doublereal *, ftnlen, 
	    ftnlen);
    extern logical return_(cspice_t*);
    doublereal pv1[3];
    doublereal pv2[3];
    char ref[5];
    doublereal sep;


    /* Module state */
    zzgfpaq_state_t* __state = get_zzgfpaq_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Compute the apparent phase angle for a target, observer, */
/*     illuminator set of ephemeris objects. */

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

/*     PHASE ANGLE */
/*     EPHEMERIS */
/*     GEOMETRY */
/*     SEARCH */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Ephemeris seconds past J2000 TDB. */
/*     TARG       I   Target body ID. */
/*     ILLMN      I   Illuminating body ID. */
/*     OBS        I   Observer body ID. */
/*     ABCORR     I   Aberration correction flag. */
/*     VALUE      O   Value of phase angle. */

/* $ Detailed_Input */

/*     ET       the time in ephemeris seconds past J2000 TDB at which */
/*              to compute the phase angle. */

/*     TARG     the SPICE integer ID for the target body. */

/*     ILLMN    the SPICE integer ID for the illuminating body. */

/*     OBS      the SPICE integer ID for the observer. */

/*     ABCORR   the string description of the aberration corrections to */
/*              apply to the state evaluations to account for one-way */
/*              light time and stellar aberration. */

/*              Any aberration correction accepted by the SPICE */
/*              routine SPKEZR is accepted here. See the header */
/*              of SPKEZR for a detailed description of the */
/*              aberration correction options. For convenience, */
/*              the options are listed below: */

/*                 'NONE'     Apply no correction. Returns the "true" */
/*                            geometric state. */

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

/*              The ABCORR string lacks sensitivity to case, leading */
/*              and trailing blanks. */

/* $ Detailed_Output */

/*     VALUE      is the optionally light-time corrected phase angle */
/*                between TARG and ILLMN as observed from OBS. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     None. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine calculates the phase angle using the location of the */
/*     bodies (if point objects) or the center of the bodies (if finite */
/*     bodies). */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     E.D. Wright    (JPL) */

/* $ Version */

/* -    SPICELIB version 1.0.0 23-JUN-2010 (EDW) */

/* -& */
/* $ Index_Entries */

/*   compute the phase of two objects wrt an illumination source */

/* -& */

/*     SPICELIB functions. */


/*     Local Variables. */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "ZZGFPAQ", (ftnlen)7);

/*     This calculation is invariant with respect to reference frame. */
/*     Use J2000 for convenience. */

    s_copy(&__global_state->f2c, ref, "J2000", (ftnlen)5, (ftnlen)5);

/*     Get the position of the TARG object relative to OBS at ET. */

    spkezp_(__global_state, targ, et, ref, abcorr, obs, pv1, &lt, (ftnlen)5, 
	    abcorr_len);
    if (failed_(__global_state)) {
	chkout_(__global_state, "ZZGFPAQ", (ftnlen)7);
	return 0;
    }

/*     Get the state of the ILLMN object relative to TARG at ET */
/*     for no aberration correction, or ET - LT otherwise. */

    if (eqstr_(__global_state, abcorr, "NONE", abcorr_len, (ftnlen)4)) {
	spkezp_(__global_state, illmn, et, ref, abcorr, targ, pv2, &lt, (
		ftnlen)5, abcorr_len);
    } else {
	d__1 = *et - lt;
	spkezp_(__global_state, illmn, &d__1, ref, abcorr, targ, pv2, &lt, (
		ftnlen)5, abcorr_len);
    }
    if (failed_(__global_state)) {
	chkout_(__global_state, "ZZGFPAQ", (ftnlen)7);
	return 0;
    }

/*                       ILLMN      OBS */
/*       ILLMN as seen      ^       / */
/*       from TARG at       |      / */
/*       ET - LT.           |     / */
/*                         >|..../< phase angle */
/*                          |   / */
/*                        . |  / */
/*                      .   | / */
/*                     .     v     TARG as seen from OBS */
/*               SEP   .   TARG    at ET */
/*                      .  / */
/*                        / */
/*                       v */

/*        PI = SEP + PHASE */

/*        so */

/*        PHASE = PI - SEP */

/*     Calculate the angle separating the vectors relative to TARG */

    sep = vsep_(__global_state, pv1, pv2);

/*     The angle of interest is that between -PV1 and PV2 measured from */
/*     TARG. Subtract SEP from PI to calculate this angle. */

    *value = pi_(__global_state) - sep;

/*     All done. */

    chkout_(__global_state, "ZZGFPAQ", (ftnlen)7);
    return 0;
} /* zzgfpaq_ */

