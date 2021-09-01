/* vsepg.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int vsepg_state_t;
static vsepg_state_t* get_vsepg_state(cspice_t* state) {
	return 0;
}

/* $Procedure  VSEPG ( Angular separation of vectors, general dimension ) */
doublereal vsepg_(cspice_t* __global_state, doublereal *v1, doublereal *v2, 
	integer *ndim)
{
    /* System generated locals */
    integer i__1;
    doublereal ret_val, d__1;

    /* Builtin functions */
    double sqrt(doublereal), asin(doublereal);

    /* Local variables */
    doublereal dmag1;
    doublereal dmag2;
    integer i__;
    extern doublereal vdotg_(cspice_t*, doublereal *, doublereal *, integer *)
	    ;
    doublereal r1;
    doublereal r2;
    doublereal magdif;
    extern doublereal pi_(cspice_t*);
    extern doublereal vnormg_(cspice_t*, doublereal *, integer *);


    /* Module state */
    vsepg_state_t* __state = get_vsepg_state(__global_state);
/* $ Abstract */

/*      VSEPG finds the separation angle in radians between two double */
/*      precision vectors of arbitrary dimension. This angle is defined */
/*      as zero if either vector is zero. */

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

/*      ANGLE,  VECTOR */

/* $ Declarations */
/* $ Brief_I/O */

/*      VARIABLE  I/O  DESCRIPTION */
/*      --------  ---  -------------------------------------------------- */
/*       V1        I     First vector. */
/*       V2        I     Second vector. */
/*       NDIM      I     The number of elements in V1 and V2. */

/* $ Detailed_Input */

/*      V1      is any double precision vector of arbitrary dimension. */
/*      V2      is also a double precision vector of arbitrary dimension. */
/*              V1 or V2 or both may be the zero vector. */
/*      NDIM    is the dimension of the both of the input vectors */
/*              V1 and V2. */

/* $ Detailed_Output */

/*      VSEPG   is the angle between V1 and V2 expressed in radians. */
/*              VSEPG is strictly non-negative.  For input vectors of */
/*              four or more dimensions, the angle is defined as the */
/*              generalization of the definition for three dimensions. */
/*              If either V1 or V2 is the zero vector, then VSEPG is */
/*              defined to be 0 radians. */

/* $ Parameters */

/*      None. */

/* $ Particulars */

/*      In four or more dimensions this angle does not have a physically */
/*      realizable interpretation.  However, the angle is defined as */
/*      the generalization of the following definition which is valid in */
/*      three or two dimensions: */

/*      In the plane, it is a simple matter to calculate the angle */
/*      between two vectors once the two vectors have been made to be */
/*      unit length.  Then, since the two vectors form the two equal */
/*      sides of an isosceles triangle, the length of the third side */
/*      is given by the expression */

/*            LENGTH = 2.0 * SINE ( VSEPG/2.0 ) */

/*      The length is given by the magnitude of the difference of the */
/*      two unit vectors */

/*            LENGTH = NORM ( U1 - U2 ) */

/*      Once the length is found, the value of VSEPG may be calculated */
/*      by inverting the first expression given above as */

/*            VSEPG = 2.0 * ARCSINE ( LENGTH/2.0 ) */

/*      This expression becomes increasingly unstable when VSEPG gets */
/*      larger than PI/2 or 90 degrees.  In this situation (which is */
/*      easily detected by determining the sign of the dot product of */
/*      V1 and V2) the supplementary angle is calculated first and */
/*      then VSEPG is given by */

/*            VSEPG = PI - SUPPLEMENTARY_ANGLE */

/* $ Examples */

/*      The following table gives sample values for V1, V2 and VSEPG */
/*      implied by the inputs. */

/*      V1               V2               NDIM          VSEPG */
/*      ----------------------------------------------------------------- */
/*      (1, 0, 0, 0)     (1, 0, 0, 0)       4           0.0D0 */
/*      (1, 0, 0)        (0, 1, 0)          3           PI/2 (=1.71...) */
/*      (3, 0)           (-5, 0)            2           PI   (=3.14...) */

/* $ Restrictions */

/*      The user is required to insure that the input vectors will not */
/*      cause floating point overflow upon calculation of the vector */
/*      dot product since no error detection or correction code is */
/*      implemented.  In practice, this is not a significant */
/*      restriction. */

/* $ Exceptions */

/*     Error free. */

/* $ Files */

/*      None */

/* $ Author_and_Institution */

/*     C.A. Curzon     (JPL) */
/*     K.R. Gehringer  (JPL) */
/*     H.A. Neilan     (JPL) */
/*     W.L. Taber      (JPL) */

/* $ Literature_References */

/*      None */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 29-FEB-1996 (KRG) */

/*        The declaration for the SPICELIB function PI is now */
/*        preceded by an EXTERNAL statement declaring PI to be an */
/*        external function. This removes a conflict with any */
/*        compilers that have a PI intrinsic function. */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (CAC) */

/* -& */
/* $ Index_Entries */

/*     angular separation of n-dimensional vectors */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.1.0, 29-FEB-1996 (KRG) */

/*        The declaration for the SPICELIB function PI is now */
/*        preceded by an EXTERNAL statement declaring PI to be an */
/*        external function. This removes a conflict with any */
/*        compilers that have a PI intrinsic function. */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (CAC) */

/* -    Beta Version 1.1.0, 02-MAR-1989 (HAN) */

/*        The variable MAGDIFF was changed to MAGDIF in order to */
/*        comply with the ANSI Fortran Standard six character */
/*        variable name length restriction. */

/* -    Beta Version 1.0.1, 10-JAN-1989 (WLT) */

/*        Error free specification added. */

/* -& */

/*     SPICELIB functions */


/*     Local Variables */

/*     The following declarations represent, respectively: */
/*        Magnitudes of V1, V2 */
/*        Reciprocals of the magnitudes of V1, V2 */
/*        Magnitude of either of the difference vectors: V1-V2 or */
/*           V1-(-V2) */


/*     Calculate the magnitudes of V1 and V2; if either is 0, VSEPG = 0 */

    dmag1 = vnormg_(__global_state, v1, ndim);
    if (dmag1 == 0.) {
	ret_val = 0.;
	return ret_val;
    }
    dmag2 = vnormg_(__global_state, v2, ndim);
    if (dmag2 == 0.) {
	ret_val = 0.;
	return ret_val;
    }
    if (vdotg_(__global_state, v1, v2, ndim) > 0.) {
	r1 = 1. / dmag1;
	r2 = 1. / dmag2;
	magdif = 0.;
	i__1 = *ndim;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* Computing 2nd power */
	    d__1 = v1[i__ - 1] * r1 - v2[i__ - 1] * r2;
	    magdif += d__1 * d__1;
	}
	magdif = sqrt(magdif);
	ret_val = asin(magdif * .5) * 2.;
    } else if (vdotg_(__global_state, v1, v2, ndim) < 0.) {
	r1 = 1. / dmag1;
	r2 = 1. / dmag2;
	magdif = 0.;
	i__1 = *ndim;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* Computing 2nd power */
	    d__1 = v1[i__ - 1] * r1 + v2[i__ - 1] * r2;
	    magdif += d__1 * d__1;
	}
	magdif = sqrt(magdif);
	ret_val = pi_(__global_state) - asin(magdif * .5) * 2.;
    } else {
	ret_val = pi_(__global_state) / 2.;
    }
    return ret_val;
} /* vsepg_ */

