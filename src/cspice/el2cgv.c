/* el2cgv.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int el2cgv_state_t;
static el2cgv_state_t* get_el2cgv_state(cspice_t* state) {
	return 0;
}

/* $Procedure      EL2CGV ( Ellipse to center and generating vectors ) */
/* Subroutine */ int el2cgv_(cspice_t* __global_state, doublereal *ellips, 
	doublereal *center, doublereal *smajor, doublereal *sminor)
{
    extern /* Subroutine */ int vequ_(cspice_t*, doublereal *, doublereal *);


    /* Module state */
    el2cgv_state_t* __state = get_el2cgv_state(__global_state);
/* $ Abstract */

/*     Convert a SPICELIB ellipse to a center vector and two generating */
/*     vectors.  The selected generating vectors are semi-axes of the */
/*     ellipse. */

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

/*     ELLIPSES */

/* $ Keywords */

/*     ELLIPSE */
/*     GEOMETRY */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ELLIPS     I   A SPICELIB ellipse. */
/*     CENTER, */
/*     SMAJOR, */
/*     SMINOR     O   Center and semi-axes of ELLIPS. */

/* $ Detailed_Input */

/*     ELLIPS         is a SPICELIB ellipse. */

/* $ Detailed_Output */

/*     CENTER, */
/*     SMAJOR, */
/*     SMINOR         are, respectively, a center vector, a semi-major */
/*                    axis vector, and a semi-minor axis vector that */
/*                    generate the input ellipse.  This ellipse is the */
/*                    set of points */

/*                       CENTER + cos(theta) SMAJOR + sin(theta) SMINOR */

/*                    where theta ranges over the interval (-pi, pi]. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     SPICELIB ellipses serve to simplify calling sequences and reduce */
/*     the chance for error in declaring and describing argument lists */
/*     involving ellipses. */

/*     The set of ellipse conversion routines is */

/*        CGV2EL ( Center and generating vectors to ellipse ) */
/*        EL2CGV ( Ellipse to center and generating vectors ) */

/*     A word about the output of this routine:   the semi-major axis of */
/*     an ellipse is a vector of largest possible magnitude in the set */

/*        cos(theta) VEC1  +  sin(theta) VEC2, */

/*     where theta is in the interval (-pi, pi].  There are two such */
/*     vectors; they are additive inverses of each other. The semi-minor */
/*     axis is an analogous vector of smallest possible magnitude.  The */
/*     semi-major and semi-minor axes are orthogonal to each other.  If */
/*     SMAJOR and SMINOR are choices of semi-major and semi-minor axes, */
/*     then the input ellipse can also be represented as the set of */
/*     points */


/*        CENTER + cos(theta) SMAJOR + sin(theta) SMINOR */

/*     where theta ranges over the interval (-pi, pi]. */

/* $ Examples */

/*     1)  Find the semi-axes of the limb of an ellipsoid. */

/*         C */
/*         C     Our viewing location is VIEWPT.  The radii of the */
/*         C     ellipsoid are A, B, and C. */
/*         C */
/*               CALL EDLIMB ( A, B, C, VIEWPT, LIMB ) */

/*               CALL EL2CGV ( LIMB, CENTER, SMAJOR, SMINOR ) */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 02-NOV-1990 (NJB) */

/* -& */
/* $ Index_Entries */

/*     ellipse to center and generating vectors */

/* -& */

/*     Local parameters */


/*     SPICELIB ellipses contain a center vector, a semi-major */
/*     axis vector, and a semi-minor axis vector.  These are */
/*     located, respectively, in elements */

/*        CTRPOS through CTRPOS + 1 */

/*        MAJPOS through MAJPOS + 1 */

/*        MINPOS through MINPOS + 1 */



/*     The center of the ellipse is held in the first three elements. */
/*     The semi-major and semi-minor axes come next. */

    vequ_(__global_state, ellips, center);
    vequ_(__global_state, &ellips[3], smajor);
    vequ_(__global_state, &ellips[6], sminor);
    return 0;
} /* el2cgv_ */

