/* bodvar.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern bodvar_init_t __bodvar_init;
static bodvar_state_t* get_bodvar_state(cspice_t* state) {
	if (!state->bodvar)
		state->bodvar = __cspice_allocate_module(sizeof(
	bodvar_state_t), &__bodvar_init, sizeof(__bodvar_init));
	return state->bodvar;

}

/* $Procedure      BODVAR ( Return values from the kernel pool ) */
/* Subroutine */ int bodvar_(cspice_t* __global_state, integer *body, char *
	item, integer *dim, doublereal *values, ftnlen item_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    char code[16];
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    logical found;
    char varnam[32];
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int suffix_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int rtpool_(cspice_t*, char *, integer *, 
	    doublereal *, logical *, ftnlen);
    extern /* Subroutine */ int intstr_(cspice_t*, integer *, char *, ftnlen);


    /* Module state */
    bodvar_state_t* __state = get_bodvar_state(__global_state);
/* $ Abstract */

/*     Deprecated: This routine has been superseded by BODVCD and */
/*     BODVRD.  This routine is supported for purposes of backward */
/*     compatibility only. */

/*     Return the values of some item for any body in the */
/*     kernel pool. */

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

/*     KERNEL */

/* $ Keywords */

/*     CONSTANTS */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     BODY       I   ID code of body. */
/*     ITEM       I   Item for which values are desired. ('RADII', */
/*                    'NUT_PREC_ANGLES', etc. ) */
/*     DIM        O   Number of values returned. */
/*     VALUES     O   Values. */

/* $ Detailed_Input */

/*     BODY       is the ID code of the body for which ITEM is */
/*                requested. Bodies are numbered according to the */
/*                standard NAIF numbering scheme. */

/*     ITEM       is the item to be returned. Together, the body and */
/*                item name combine to form a variable name, e.g., */

/*                      'BODY599_RADII' */
/*                      'BODY401_POLE_RA' */

/* $ Detailed_Output */

/*     DIM        is the number of values associated with the variable. */

/*     VALUES     are the values associated with the variable. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*    None. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     None. */

/* $ Examples */

/*     The call */

/*         CALL BODVAR ( 399, 'RADII', DIM, VALUE ) */

/*     returns the dimension and values associated with the variable */
/*     'BODY399_RADII', for example, */

/*          DIM      = 3 */
/*          VALUE(1) = 6378.140 */
/*          VALUE(2) = 6378.140 */
/*          VALUE(3) = 6356.755 */

/* $ Restrictions */

/*     1) If the requested item is not found, the error */
/*        SPICE(KERNELVARNOTFOUND) is signalled. */

/* $ Literature_References */

/*      1) Refer to the SPK required reading file for a complete list of */
/*         the NAIF integer ID codes for bodies. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -     SPICELIB Version 1.0.5, 18-MAY-2010 (BVS) */

/*        Index lines now state that this routine is deprecated. */

/* -     SPICELIB Version 1.0.4, 27-OCT-2005 (NJB) */

/*         Routine is now deprecated. */

/* -     SPICELIB Version 1.0.3, 08-JAN-2004 (EDW) */

/*         Trivial typo corrected. */

/* -     SPICELIB Version 1.0.2, 10-MAR-1992 (WLT) */

/*         Comment section for permuted index source lines was added */
/*         following the header. */

/* -     SPICELIB Version 1.0.1, 8-AUG-1990 (HAN) */

/*           Detailed Input section of the header was updated. The */
/*           description for the variable BODY was incorrect. */

/* -     SPICELIB Version 1.0.0, 31-JAN-1990  (WLT) (IMU) */

/* -& */
/* $ Index_Entries */

/*     DEPRECATED fetch constants for a body from the kernel pool */
/*     DEPRECATED physical constants for a body */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "BODVAR", (ftnlen)6);
    }

/*     Construct the variable name from BODY and ITEM. */

    s_copy(&__global_state->f2c, varnam, "BODY", (ftnlen)32, (ftnlen)4);
    intstr_(__global_state, body, code, (ftnlen)16);
    suffix_(__global_state, code, &__state->c__0, varnam, (ftnlen)16, (ftnlen)
	    32);
    suffix_(__global_state, "_", &__state->c__0, varnam, (ftnlen)1, (ftnlen)
	    32);
    suffix_(__global_state, item, &__state->c__0, varnam, item_len, (ftnlen)
	    32);

/*     Grab the items. Complain if they aren't there. */

    rtpool_(__global_state, varnam, dim, values, &found, (ftnlen)32);
    if (! found) {
	setmsg_(__global_state, "The variable # could not be found in the ke"
		"rnel pool.", (ftnlen)53);
	errch_(__global_state, "#", varnam, (ftnlen)1, (ftnlen)32);
	sigerr_(__global_state, "SPICE(KERNELVARNOTFOUND)", (ftnlen)24);
    }
    chkout_(__global_state, "BODVAR", (ftnlen)6);
    return 0;
} /* bodvar_ */

