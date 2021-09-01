/* vadd.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int vadd_state_t;
static vadd_state_t* get_vadd_state(cspice_t* state) {
	return 0;
}

/* $Procedure      VADD ( Vector addition, 3 dimensional ) */
/* Subroutine */ int vadd_(cspice_t* __global_state, doublereal *v1, 
	doublereal *v2, doublereal *vout)
{

    /* Module state */
    vadd_state_t* __state = get_vadd_state(__global_state);
/* $ Abstract */

/*      Add two 3 dimensional vectors. */

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

/*     VECTOR */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     V1        I     First vector to be added. */
/*     V2        I     Second vector to be added. */
/*     VOUT      O     Sum vector, V1 + V2. */

/* $ Detailed_Input */

/*     V1      This may be any 3-element vector. */

/*     V2      Likewise. */

/* $ Detailed_Output */

/*     VOUT   This is vector sum of V1 and V2. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine simply performs addition between components of V1 */
/*     and V2.  No checking is performed to determine whether floating */
/*     point overflow has occurred. */

/* $ Examples */

/*     The following table shows the output VOUT as a function of the */
/*     the input V1 and V2 from the subroutine VADD. */

/*     V1                  V2              ---> VOUT */
/*     --------------      --------------       -------------- */
/*     (1.0, 2.0, 3.0)     (4.0, 5.0, 6.0)      (5.0, 7.0, 9.0) */
/*     (1D-7,1D23,0)       (1D24, 1D23, 0.0)    (1D24,2D23,0.0) */

/* $ Restrictions */

/*     The user is required to determine that the magnitude each */
/*     component of the vectors is within the appropriate range so as */
/*     not to cause floating point overflow. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     W.M. Owen       (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.2, 22-APR-2010 (NJB) */

/*        Header correction: assertions that the output */
/*        can overwrite the input have been removed. */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (WMO) */

/* -& */
/* $ Index_Entries */

/*     3-dimensional vector addition */

/* -& */
    vout[0] = v1[0] + v2[0];
    vout[1] = v1[1] + v2[1];
    vout[2] = v1[2] + v2[2];
    return 0;
} /* vadd_ */

