/* dvnorm.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int dvnorm_state_t;
static inline dvnorm_state_t* get_dvnorm_state(cspice_t* state) {
	return 0;
}

/* $Procedure DVNORM ( Derivative of vector norm ) */
doublereal dvnorm_(cspice_t* __global_state, doublereal *state)
{
    /* System generated locals */
    doublereal ret_val;

    /* Local variables */
    extern /* Subroutine */ int vhat_(cspice_t*, doublereal *, doublereal *);
    doublereal xhat[3];
    extern doublereal vdot_(cspice_t*, doublereal *, doublereal *);
    extern doublereal vnorm_(cspice_t*, doublereal *);


    /* Module state */
    dvnorm_state_t* __state = get_dvnorm_state(__global_state);
/* $ Abstract */

/*     Function to calculate the derivative of the norm of a 3-vector. */

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

/*     DERIVATIVE */
/*     MATH */
/*     VECTOR */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     STATE      I   A 6-vector composed of three coordinates and their */
/*                    derivatives. */

/* $ Detailed_Input */

/*     STATE      A double precision 6-vector, the second three */
/*                components being the derivatives of the first three */
/*                with respect to some scalar. */

/*                   STATE =  ( x, dx ) */
/*                                 -- */
/*                                 ds */

/*                A common form for STATE would contain position and */
/*                velocity. */

/* $ Detailed_Output */

/*     DVNORM     The value of d||x|| corresponding to STATE. */
/*                             ------ */
/*                               ds */

/*                                   1/2         2    2    2  1/2 */
/*              where ||x|| = < x, x >    =  ( x1 + x2 + x3 ) */


/*                        v = ( dx1, dx2, dx3 ) */
/*                              ---  ---  --- */
/*                              ds   ds   ds */

/*                   d||x||   < x, v > */
/*                   ------ =  ------     =  < xhat, v > */
/*                     ds            1/2 */
/*                            < x, x > */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     None. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*   A common use for this routine is to calculate the time derivative */
/*   of the radius corresponding to a state vector. */

/* $ Examples */

/*   Any numerical results shown for this example may differ between */
/*   platforms as the results depend on the SPICE kernels used as input */
/*   and the machine specific arithmetic implementation. */


/*           PROGRAM DVNORM_T */
/*           IMPLICIT NONE */

/*           DOUBLE PRECISION      X     (3) */
/*           DOUBLE PRECISION      MAG   (3) */
/*           DOUBLE PRECISION      DVMAG (3) */
/*           DOUBLE PRECISION      Y     (6) */

/*           DOUBLE PRECISION      DVNORM */
/*     C */
/*     C     Create several 6-vectors (6x1 arrays) with the structure */
/*     C */
/*     C        s = |  x  | */
/*     C            |     | */
/*     C            |  dx | */
/*     C            |  -- | */
/*     C            |  ds | */
/*     C */
/*     C      where 'x' is a 3-vector (3x1 array). */
/*     C */

/*     C */
/*     C      Create 's' with 'x' of varying magnitudes. Use 'x' */
/*     C      and '-x' to define the derivative as parallel and */
/*     C      anti-parallel. */
/*     C */
/*           MAG(1) =  -4.D0 */
/*           MAG(2) =   4.D0 */
/*           MAG(3) =  12.D0 */

/*           X(1)   = 1.D0 */
/*           X(2)   = DSQRT( 2.D0 ) */
/*           X(3)   = DSQRT( 3.D0 ) */

/*     C */
/*     C     Parallel... */
/*     C */
/*           Y(1)   = X(1) * 10.D0**MAG(1) */
/*           Y(2)   = X(2) * 10.D0**MAG(1) */
/*           Y(3)   = X(3) * 10.D0**MAG(1) */
/*           Y(4)   = X(1) */
/*           Y(5)   = X(2) */
/*           Y(6)   = X(3) */

/*           WRITE(*,*) 'Parallel x, dx/ds         : ', DVNORM( Y ) */

/*     C */
/*     C     ... anti-parallel... */
/*     C */
/*           Y(1)   = X(1) * 10.D0**MAG(2) */
/*           Y(2)   = X(2) * 10.D0**MAG(2) */
/*           Y(3)   = X(3) * 10.D0**MAG(2) */
/*           Y(4)   = -X(1) */
/*           Y(5)   = -X(2) */
/*           Y(6)   = -X(3) */

/*           WRITE(*,*) 'Anti-parallel x, dx/ds    : ', DVNORM( Y ) */

/*     C */
/*     C     ... 'x' zero vector */
/*     C */
/*           Y(1)   = 0.D0 */
/*           Y(2)   = 0.D0 */
/*           Y(3)   = 0.D0 */
/*           Y(4)   = X(1) * 10.D0**MAG(3) */
/*           Y(5)   = X(2) * 10.D0**MAG(3) */
/*           Y(6)   = X(3) * 10.D0**MAG(3) */

/*           WRITE(*,*) 'Zero vector x, large dx/ds: ', DVNORM( Y ) */
/*           END */

/*   The program outputs: */

/*      Parallel x, dx/ds         :   2.44948974 */
/*      Anti-parallel x, dx/ds    :  -2.44948974 */
/*      Zero vector x, large dx/ds:   0. */

/* $ Restrictions */

/*     Error free. */

/*     1) If the first three components of STATE ("x") describes the */
/*        origin (zero vector) the routine returns zero as the */
/*        derivative of the vector norm. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     Ed Wright     (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 03-MAY-2010 (EDW) */

/* -& */
/* $ Index_Entries */

/*   derivative of 3-vector norm */

/* -& */

/*     SPICELIB functions. */


/*     Local Variables. */


/*     If "x" describes the zero vector, return zero as the derivative */
/*     of the vector norm. */

    if (vnorm_(__global_state, state) == 0.) {
	ret_val = 0.;
	return ret_val;
    }

/*     Construct a unit vector from the x vector data */
/*     in STATE. */

    vhat_(__global_state, state, xhat);

/*     Project the velocity components onto the XHAT vector. */

/*      d ||x||          x */
/*      -------  = v . ----- */
/*        ds           ||x|| */

    ret_val = vdot_(__global_state, &state[3], xhat);
    return ret_val;
} /* dvnorm_ */

