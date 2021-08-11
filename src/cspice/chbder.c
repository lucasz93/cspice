/* chbder.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int chbder_state_t;
static chbder_state_t* get_chbder_state() {
	cspice_t* state =  __cspice_get_state();
	return 0;
}

/* $Procedure      CHBDER ( Derivatives of a Chebyshev expansion ) */
/* Subroutine */ int chbder_(doublereal *cp, integer *degp, doublereal *x2s, 
	doublereal *x, integer *nderiv, doublereal *partdp, doublereal *dpdxs)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    integer i__;
    integer j;
    doublereal s;
    doublereal scale;
    doublereal s2;


    /* Module state */
    chbder_state_t* __state = get_chbder_state();
/* $ Abstract */

/*     Given the coefficients for the Chebyshev expansion of a */
/*     polynomial, this returns the value of the polynomial and its */
/*     first NDERIV derivatives evaluated at the input X. */

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

/*      INTERPOLATION,  MATH,  POLYNOMIAL */

/* $ Declarations */
/* $ Brief_I/O */

/*      VARIABLE  I/O  DESCRIPTION */
/*      --------  ---  -------------------------------------------------- */
/*      CP         I   NDEG+1 Chebyshev polynomial coefficients. */
/*      DEGP       I   Degree of polynomial. */
/*      X2S        I   Transformation parameters of polynomial. */
/*      X          I   Value for which the polynomial is to be evaluated */
/*      NDERIV     I   The number of derivatives to compute */
/*      PARTDP     -   Workspace provided for computing derivatives */
/*      DPDXS(I)   O   Value of the I'th derivative of the polynomial */

/* $ Detailed_Input */

/*      CP         is an array of coefficients a polynomial with respect */
/*                 to the Chebyshev basis.  The polynomial to be */
/*                 evaluated is assumed to be of the form: */

/*                   CP(DEGP+1)*T(DEGP,S) + CP(DEGP)*T(DEGP-1,S) + ... */

/*                                    ... + CP(2)*T(1,S) + CP(1)*T(0,S) */

/*                 where T(I,S) is the I'th Chebyshev polynomial */
/*                 evaluated  at a number S whose double precision */
/*                 value lies between -1 and 1.  The value of S is */
/*                 computed from the input variables P(1), P(2) and X. */

/*      DEGP       is the degree of the Chebyshev polynomial to be */
/*                 evaluated. */

/*      X2S        is an array of two parameters.  These parameters are */
/*                 used to transform the domain of the input variable X */
/*                 into the standard domain of the Chebyshev polynomial. */
/*                 X2S(1) should be a reference point in the domain of */
/*                 X; X2S(2) should be the radius by which points are */
/*                 allowed to deviate from the reference point and while */
/*                 remaining within the domain of X.  The value of */
/*                 X is transformed into the value S given by */

/*                           S = ( X - X2S(1) ) / X2S(2) */

/*                 Typically X2S(1) is the midpoint of the interval over */
/*                 which X is allowed to vary and X2S(2) is the radius */
/*                 of the interval. */

/*                 The main reason for doing this is that a Chebyshev */
/*                 expansion is usually fit to data over a span */
/*                 from A to B where A and B are not -1 and 1 */
/*                 respectively.  Thus to get the "best fit" the */
/*                 data was transformed to the interval [-1,1] and */
/*                 coefficients generated. These coefficients are */
/*                 not rescaled to the interval of the data so that */
/*                 the numerical "robustness" of the Chebyshev fit will */
/*                 not be lost. Consequently, when the "best fitting" */
/*                 polynomial needs to be evaluated at an intermediate */
/*                 point, the point of evaluation must be transformed */
/*                 in the same way that the generating points were */
/*                 transformed. */

/*      X          Value for which the polynomial is to be evaluated. */

/*      NDERIV     is the number of derivatives to be computed by the */
/*                 routine.  NDERIV should be non-negative. */

/*      PARTDP     Is a work space used by the program to compute */
/*                 all of the desired derivatives.  It should be declared */
/*                 in the calling program as */

/*                        DOUBLE PRECISION PARTDP(3, 0:NDERIV) */

/* $ Detailed_Output */

/*      DPDXS(0)   The value of the polynomial to be evaluated.  It */
/*                 is given by */

/*                   CP(DEGP+1)*T(DEGP,S) + CP(DEGP)*T(DEGP-1,S) + ... */

/*                                    ... + CP(2)*T(1,S) + CP(1)*T(0,S) */

/*                 where T(I,S) is the I'th Chebyshev polynomial */
/*                 evaluated  at a number S = ( X - P(1) )/P(2) */

/*      DPDXS(I)   The value of the I'th derivative of the polynomial at */
/*                 X. (I ranges from 1 to NDERIV) It is given by */

/*                                             [i] */
/*                   (1/P(2)**I) ( CP(DEGP+1)*T   (DEGP,S) */

/*                                           [i] */
/*                               + CP(DEGP)*T   (DEGP-1,S) + ... */

/*                               . */
/*                               . */
/*                               . */
/*                                        [i] */
/*                           ... + CP(2)*T   (1,S) */

/*                                        [i] */
/*                               + CP(1)*T   (0,S) ) */

/*                                   [i] */
/*                 where T(k,S) and T   (I,S)  are the k'th Chebyshev */
/*                 polynomial and its i'th derivative respectively, */
/*                 evaluated  at the number S = ( X - X2S(1) )/X2S(2). */

/* $ Parameters */

/*      None. */

/* $ Particulars */

/*      This routine computes the value of a Chebyshev polynomial */
/*      expansion and the derivatives of the expansion with respect to X. */
/*      The polynomial is given by */

/*           CP(DEGP+1)*T(DEGP,S) + CP(DEGP)*T(DEGP-1,S) + ... */

/*                            ... + CP(2)*T(1,S) + CP(1)*T(0,S) */

/*      where */

/*           S  =  ( X - X2S(1) ) / X2S(2) */

/*      and */

/*           T(i,S) is the i'th Chebyshev polynomial of the first kind */
/*           evaluated at S. */


/* $ Examples */

/*     Depending upon the user's needs, there are 3 routines available */
/*     for evaluating Chebyshev polynomials. */

/*        CHBVAL for evaluating a Chebyshev polynomial when no */
/*               derivatives are desired. */

/*        CHBINT for evaluating a Chebyshev polynomial and its */
/*               first derivative. */

/*        CHBDER for evaluating a Chebyshev polynomial and a user */
/*               or application dependent number of derivatives. */

/*     Of these 3 the one most commonly employed by NAIF software */
/*     is CHBINT as it is used to interpolate ephemeris state */
/*     vectors which requires the evaluation of a polynomial */
/*     and its derivative.  When no derivatives are desired one */
/*     should use CHBVAL, or when more than one or an unknown */
/*     number of derivatives are desired one should use CHBDER. */

/*     The code fragment below illustrates how this routine might */
/*     be used to obtain points for plotting a polynomial */
/*     and its derivatives. */

/*           fetch the pieces needed for describing the polynomial */
/*           to be evaluated. */

/*           READ  (*,*) DEGP, ( CP(I), I = 1, DEG+1 ), NDERIV, BEG, END */

/*           check to see that BEG is actually less than END */

/*           IF ( BEG .GE. END ) THEN */

/*              take some appropriate action */

/*           ELSE */

/*              X2S(1) = ( END + BEG ) / 2.0D0 */
/*              X2S(2) = ( END - BEG ) / 2.0D0 */

/*           END IF */

/*           STEP = END - BEG / <number of points used for plotting> */
/*           X    = BEG */

/*           DO WHILE ( X .LE. END ) */

/*              CALL CHBDER ( CP, DEGP, X2S , X, NDERIV, PARTDP, DPDXS ) */

/*              do something with the pairs ( X, DPDXS(0)),(X,DPDXS(1)), */
/*              (X,DPDXS(2)) ... (X,DPDXS(NDERIV)) */

/*              X = X + STEP */

/*           END DO */

/* $ Restrictions */

/*      The user must be sure that the provided workspace is declared */
/*      properly in the calling routine.  The proper declaration is: */

/*      INTEGER          NDERIV */
/*      PARAMETER      ( NDERIV = the desired number of derivatives ) */
/*      DOUBLE PRECISION PARTDP (3, 0:NDERIV) */

/*      If for some reason a parameter is not passed to this routine in */
/*      NDERIV, the user should make sure that the value of NDERIV is not */
/*      so large that the work space provided is inadequate. */

/*      One needs to be careful that the value (X-X2S(1)) / X2S(2) lies */
/*      between -1 and 1.  Otherwise, the routine may fail spectacularly */
/*      (for example with a floating point overflow). */

/*      While this routine will compute derivatives of the input */
/*      polynomial, the user should consider how accurately the */
/*      derivatives of the Chebyshev fit, match the derivatives of the */
/*      function it approximates. */



/* $ Exceptions */

/*     Error free */

/*     No tests are performed for exceptional values ( NDERIV negative, */
/*     DEGP negative, etc.) This routine is expected to be used at a low */
/*     level in ephemeris evaluations. For that reason it has been */
/*     elected as a routine that will not participate in error handling. */

/* $ Files */

/*      None. */

/* $ Author_and_Institution */

/*      N.J. Bachman    (JPL) */
/*      W.L. Taber      (JPL) */

/* $ Literature_References */

/*      "Numerical Recipes -- The Art of Scientific Computing" by */
/*       William H. Press, Brian P. Flannery, Saul A. Teukolsky, */
/*       Willam T. Vetterling.  (See Clenshaw's Recurrence Formula) */

/*      "The Chebyshev Polynomials" by Theodore J. Rivlin */

/*      "CRC Handbook of Tables for Mathematics" */

/* $ Version */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (WLT) */

/* -& */
/* $ Index_Entries */

/*     derivatives of a chebyshev expansion */

/* -& */
/* $ Revisions */

/* -    Beta Version 1.0.1, 16-FEB-1988 (WLT) (NJB) */

/*     The Error free specification was added to the routine as */
/*     well as an explanation for this designation.  Examples added. */
/*     Declaration of unused variable RECIP removed. */
/* -& */

/*     Local variables */


/*     Transform X to S and initialize temporary variables. */

    s = (*x - x2s[0]) / x2s[1];
    s2 = s * 2.;
    j = *degp + 1;
    i__1 = *nderiv;
    for (i__ = 0; i__ <= i__1; ++i__) {
	partdp[i__ * 3] = 0.;
	partdp[i__ * 3 + 1] = 0.;
    }

/*     Evaluate the polynomial ... */

    while(j > 1) {
	partdp[2] = partdp[1];
	partdp[1] = partdp[0];
	partdp[0] = cp[j - 1] + (s2 * partdp[1] - partdp[2]);

/*        ... and its derivatives using recursion. */

	scale = 2.;
	i__1 = *nderiv;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    partdp[i__ * 3 + 2] = partdp[i__ * 3 + 1];
	    partdp[i__ * 3 + 1] = partdp[i__ * 3];
	    partdp[i__ * 3] = partdp[(i__ - 1) * 3 + 1] * scale + partdp[i__ *
		     3 + 1] * s2 - partdp[i__ * 3 + 2];
	    scale += 2.;
	}
	--j;
    }
    dpdxs[0] = cp[0] + (s * partdp[0] - partdp[1]);
    scale = 1.;
    i__1 = *nderiv;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dpdxs[i__] = partdp[(i__ - 1) * 3] * scale + partdp[i__ * 3] * s - 
		partdp[i__ * 3 + 1];
	scale += 1;
    }

/*     Scale the k'th derivative w.r.t S by (1/X2S(2)**k) so that we have */
/*     the derivatives */

/*                    2          3          4          5 */
/*        d P(S)     d P(S)     d P(S)     d P(S)     d P(S) */
/*        ------     ------     ------     ------     ------ */
/*                       2          3          4          5 */
/*          dX         dX         dX         dX         dX */


/*     NOTE: In the loop that follows we perform division instead of */
/*           multiplying by reciprocals so that the algorithm matches */
/*           CHBINT.  If multiplication by reciprocals is performed */
/*           CHBINT and CHBDER (although mathematically equivalent) will */
/*           not produce identical results for the first derivative. */


    scale = x2s[1];
    i__1 = *nderiv;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dpdxs[i__] /= scale;
	scale = x2s[1] * scale;
    }
    return 0;
} /* chbder_ */

