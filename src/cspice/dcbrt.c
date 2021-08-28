/* dcbrt.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern dcbrt_init_t __dcbrt_init;
static inline dcbrt_state_t* get_dcbrt_state(cspice_t* state) {
	if (!state->dcbrt)
		state->dcbrt = __cspice_allocate_module(sizeof(dcbrt_state_t),
	 &__dcbrt_init, sizeof(__dcbrt_init));
	return state->dcbrt;

}

/* $Procedure  DCBRT ( Double precision cube root ) */
doublereal dcbrt_(cspice_t* __global_state, doublereal *x)
{
    /* System generated locals */
    doublereal ret_val, d__1, d__2;

    /* Builtin functions */
    double pow_dd(f2c_state_t*, doublereal *, doublereal *), d_sign(
	    f2c_state_t*, doublereal *, doublereal *);


    /* Module state */
    dcbrt_state_t* __state = get_dcbrt_state(__global_state);
/* $ Abstract */

/*      Return the cube root of a double precision number. */

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

/*      MATH,  ROOT */

/* $ Declarations */
/* $ Brief_I/O */

/*      VARIABLE  I/O  DESCRIPTION */
/*      --------  ---  -------------------------------------------------- */
/*       X         I     Number whose cube root is desired. */

/* $ Detailed_Input */

/*      X   may be any double precision value. */

/* $ Detailed_Output */

/*      DCBRT   is the cube root of the input value. */

/* $ Parameters */

/*     None. */

/* $ Particulars */

/*      DCBRT calculates the cube root of the input value by using the */
/*      exponentiation operator to raise the input value to the 1/3 */
/*      power.  This operation, however, is performed on the absolute */
/*      value of the input variable, and then the sign of the input */
/*      is transferred to the output value. */

/*      All values of the input variable X should be acceptible to the */
/*      DCBRT. */

/* $ Examples */

/*      The following table gives sample values of the variable X and */
/*      DCBRT(X) */

/*       X                        DCBRT(X) */
/*      -------------------------------------------------------------- */
/*       0.0D0                    0.0D0 */
/*       8.0D0                    2.0D0 */
/*      -1.0D3                   -1.0D1 */

/* $ Restrictions */

/*      None */

/* $ Exceptions */

/*      Error free. */

/* $ Files */

/*      None */

/* $ Author_and_Institution */

/*      W.M. Owen       (JPL) */

/* $ Literature_References */

/*      None */

/* $ Version */

/* -     SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*         Comment section for permuted index source lines was added */
/*         following the header. */

/* -     SPICELIB Version 1.0.0, 31-JAN-1990 (WMO) */

/* -& */
/* $ Index_Entries */

/*     d.p. cube root */

/* -& */

    d__2 = abs(*x);
    d__1 = pow_dd(&__global_state->f2c, &d__2, &__state->c_b2);
    ret_val = d_sign(&__global_state->f2c, &d__1, x);

    return ret_val;
} /* dcbrt_ */

