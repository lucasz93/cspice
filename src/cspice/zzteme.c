/* zzteme.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzteme_init_t __zzteme_init;
static zzteme_state_t* get_zzteme_state(cspice_t* state) {
	if (!state->zzteme)
		state->zzteme = __cspice_allocate_module(sizeof(
	zzteme_state_t), &__zzteme_init, sizeof(__zzteme_init));
	return state->zzteme;

}

/* $Procedure ZZTEME ( J2000 to TEME at epoch ) */
/* Subroutine */ int zzteme_(cspice_t* __global_state, doublereal *et, 
	doublereal *mt)
{
    doublereal xj2000[6];
    doublereal zj2000[6];
    extern /* Subroutine */ int mxvg_(cspice_t*, doublereal *, doublereal *, 
	    integer *, integer *, doublereal *);
    doublereal m1inv[36]	/* was [6][6] */;
    doublereal m2inv[36]	/* was [6][6] */;
    doublereal z__[6];
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int zztwovxf_(cspice_t*, doublereal *, integer *, 
	    doublereal *, integer *, doublereal *);
    extern /* Subroutine */ int moved_(cspice_t*, doublereal *, integer *, 
	    doublereal *);
    doublereal xtemp[36]	/* was [6][6] */;
    doublereal m1[36]	/* was [6][6] */;
    doublereal m2[36]	/* was [6][6] */;
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int invstm_(cspice_t*, doublereal *, doublereal *)
	    ;
    extern /* Subroutine */ int zzeprc76_(cspice_t*, doublereal *, doublereal 
	    *);
    extern /* Subroutine */ int zzenut80_(cspice_t*, doublereal *, doublereal 
	    *);


    /* Module state */
    zzteme_state_t* __state = get_zzteme_state(__global_state);
/* $ Abstract */

/*     J2000 to TEME, probably. */

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

/*     FRAMES */

/* $ Keywords */

/*     FRAMES */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Epoch of the state transformation operator. */
/*     MT         O   The state transformation operator. */

/* $ Detailed_Input */

/*     ET         time expressed in terms of TDB seconds past epoch J2000 */
/*                for which to to calculate the J2000 frame to TEME frame */
/*                transformation operator. */

/* $ Detailed_Output */

/*     MT         the 6x6 operator that transforms cartesian states from */
/*                the J2000 to TEME reference frames. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     None. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     TETE    True equator true equinox */
/*     MEME    Mean equator mean equinox */
/*     TEME    True equator mean equinox */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     S.C. Krening   (JPL) */
/*     E.D. Wright    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 06-MAR-2012 (NJB) (SCK) (EDW) */

/* -& */
/* $ Index_Entries */

/*   tranformation J2000 frame to pseudo TEME */

/* -& */

/*     SPICELIB functions */


/*     Local variables */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "ZZTEME", (ftnlen)6);

/*     Extract the MEME +X vector and its derivative, both */
/*     expressed relative to the J2000 frame, into X. */

    zzeprc76_(__global_state, et, m1);
    invstm_(__global_state, m1, m1inv);
    moved_(__global_state, m1inv, &__state->c__6, xj2000);

/*     Extract the TETE +Z vector and its derivative, both */
/*     expressed relative to the MEME frame, into Z. */

    zzenut80_(__global_state, et, m2);
    invstm_(__global_state, m2, m2inv);
    moved_(__global_state, &m2inv[12], &__state->c__6, z__);

/*     Transform Z to the J2000 frame. */

    mxvg_(__global_state, m1inv, z__, &__state->c__6, &__state->c__6, zj2000);

/*     Compute the TEME to J2000 state transformation; */
/*     invert this to produce the output matrix. */

    zztwovxf_(__global_state, zj2000, &__state->c__3, xj2000, &__state->c__1, 
	    xtemp);
    invstm_(__global_state, xtemp, mt);
    chkout_(__global_state, "ZZTEME", (ftnlen)6);
    return 0;
} /* zzteme_ */

