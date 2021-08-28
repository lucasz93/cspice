/* vrel.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int vrel_state_t;
static inline vrel_state_t* get_vrel_state(cspice_t* state) {
	return 0;
}

/* $Procedure  VREL ( Vector relative difference, 3 dimensions ) */
doublereal vrel_(cspice_t* __global_state, doublereal *v1, doublereal *v2)
{
    /* System generated locals */
    doublereal ret_val, d__1, d__2;

    /* Local variables */
    extern doublereal vdist_(cspice_t*, doublereal *, doublereal *);
    extern doublereal vnorm_(cspice_t*, doublereal *);
    doublereal denorm;
    doublereal nunorm;


    /* Module state */
    vrel_state_t* __state = get_vrel_state(__global_state);
/* $ Abstract */

/*   Return the relative difference between two 3-dimensional vectors. */

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

/*   None. */

/* $ Keywords */

/*     MATH */
/*     VECTOR */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*      V1,V2     I   Input vectors. */

/* $ Detailed_Input */

/*      V1, V2        are two 3-dimensional vectors for which the */
/*                    relative difference is to be computed. */

/* $ Detailed_Output */

/*      VREL          is the relative difference between V1 and V2. */
/*                    It is defined as: */
/*                                             || V1 - V2 || */
/*                              VREL   =   ---------------------- */
/*                                         MAX ( ||V1||, ||V2|| ) */

/*                    where || X || indicates the Euclidean norm of */
/*                    the vector X. */

/*                    VREL assumes values in the range [0,2]. If both */
/*                    V1 and V2 are zero vectors then VREL is defined */
/*                    to be zero. */


/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/*     If both V1 and V2 are zero vectors then VREL is defined */
/*     to be zero. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This function computes the relative difference between two */
/*     3-dimensional vectors as defined above. */

/*     The function VRELG may be used to find the relative difference */
/*     for two vectors of general dimension. */

/* $ Examples */

/*     This example code fragment computes the relative difference */
/*     between the geometric and light time corrected state of Io */
/*     with respect to Voyager 2 at a given UTC time. */

/*     C */
/*     C     The NAIF integer code for Io is 501 and the code for */
/*     C     Voyager 2 is -32. */
/*     C */

/*           INTEGER               IO */
/*           PARAMETER           ( IO  = 501 ) */

/*           INTEGER               VG2 */
/*           PARAMETER           ( VG2 = -32 ) */

/*     C */
/*     C     Spicelib function */
/*     C */
/*           DOUBLE PRECISION      VREL */
/*     C */
/*     C     Local variables */
/*     C */
/*           DOUBLE PRECISION      STATE ( 6 ) */
/*           DOUBLE PRECISION      POS1  ( 3 ) */
/*           DOUBLE PRECISION      POS2  ( 3 ) */
/*           DOUBLE PRECISION      DIFF */
/*           DOUBLE PRECISION      LT */
/*           DOUBLE PRECISION      ET */

/*           INTEGER               HANDLE */

/*           CHARACTER*(20)        UTC */

/*           DATA                  UTC / '1979 JUN 25 12:00:00' / */

/*     C */
/*     C     Load the sample SPK ephemeris file. */
/*     C */
/*           CALL SPKLEF ( 'VG2_JUP.BSP', HANDLE ) */
/*     C */
/*     C     Convert the UTC time string to ephemeris time. */
/*     C */
/*           CALL UTC2ET ( UTC, ET ) */
/*     C */
/*     C     First calculate the geometric state and then the light */
/*     C     time corrected state. */
/*     C */
/*           CALL SPKEZ ( IO, ET, 'J2000', 'NONE', VG2, STATE, LT ) */

/*           CALL VEQU  ( STATE, POS1 ) */

/*           CALL SPKEZ ( IO, ET, 'J2000', 'LT', VG2, STATE, LT ) */

/*           CALL VEQU  ( STATE, POS2 ) */
/*     C */
/*     C     Call VREL to find the relative difference between the */
/*     C     two states. */
/*     C */
/*           DIFF = VREL ( POS1, POS2 ) */

/*           . */
/*           . */
/*           . */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     J.M. Lynch     (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 15-JUN-1992 (JML) */

/* -& */
/* $ Index_Entries */

/*     relative difference of 3-dimensional vectors */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     If the numerator is zero then set VREL equal to zero. Otherwise, */
/*     perform the rest of the calculation. */

/*     This handles the case where both vectors are zero vectors since */
/*     the distance between them will be zero. */

    nunorm = vdist_(__global_state, v1, v2);
    if (nunorm == 0.) {
	ret_val = 0.;
    } else {
/* Computing MAX */
	d__1 = vnorm_(__global_state, v1), d__2 = vnorm_(__global_state, v2);
	denorm = max(d__1,d__2);
	ret_val = nunorm / denorm;
    }
    return ret_val;
} /* vrel_ */

