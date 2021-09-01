/* zzelnaxx.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int zzelnaxx_state_t;
static zzelnaxx_state_t* get_zzelnaxx_state(cspice_t* state) {
	return 0;
}

/* $Procedure ZZELNAXX ( ellipse normal axis intercepts ) */
/* Subroutine */ int zzelnaxx_(cspice_t* __global_state, doublereal *a, 
	doublereal *b, doublereal *lat, doublereal *xxpt, doublereal *yxpt)
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double cos(doublereal), sin(doublereal);

    /* Local variables */
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    extern /* Subroutine */ int ednmpt_(cspice_t*, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *);
    doublereal normal[3];
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);
    doublereal ept[3];


    /* Module state */
    zzelnaxx_state_t* __state = get_zzelnaxx_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Given semi-axis lengths of an ellipse and a planetodetic */
/*     latitude, find the X-axis and Y-axis intercepts of the normal */
/*     line corresponding to the point at that latitude in the right */
/*     (positive X) half-plane. */

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

/*     DSK */
/*     ELLIPSE */
/*     GEOMETRY */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     A          I   Ellipse's semi-axis length in the X direction. */
/*     B          I   Ellipse's semi-axis length in the Y direction. */
/*     LAT        I   Planetodetic latitude in radians. */
/*     XXPT       O   Normal line intercept on the X-axis. */
/*     YXPT       O   Normal line intercept on the Y-axis. */

/* $ Detailed_Input */

/*     A, */
/*     B          are, respectively, an ellipse's semi-axis lengths */
/*                in the X and Y directions. The ellipse lies in */
/*                two-dimensional Euclidean space. */

/*                Any of the relationships */

/*                   A < B,  A = B,  A > B */

/*                are allowed. */


/*     LAT        is a planetodetic latitude corresponding to */
/*                some point P on the ellipse defined by A and B, */
/*                where */

/*                   P(1) >= 0 */

/*                Units are radians. */

/* $ Detailed_Output */

/*     XXPT       is the X-intercept of a line passing through the */
/*                ellipse and normal to the ellipse at the point having */
/*                the given latitude. */

/*                If LAT = 0 radians, XXPT is defined to be */

/*                        2 */
/*                   A - B / A */


/*     YXPT       is the Y-intercept of a line passing through the */
/*                ellipse and normal to the ellipse at the point having */
/*                the given latitude. */

/*                If LAT = pi/2 radians, YXPT is defined to be */

/*                         2 */
/*                    B - A / B */

/*                If LAT = -pi/2 radians, YXPT is defined to be */

/*                         2 */
/*                   -B + A / B */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the X semi-axis length A is non-positive, the */
/*         error SPICE(NONPOSITIVEAXIS) will be signaled. */

/*     2)  If the Y semi-axis length B is non-positive, the */
/*         error SPICE(NONPOSITIVEAXIS) will be signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */


/*     The outputs of this routine can be used to determine the */
/*     apex of a cone of constant planetodetic latitude. */


/*     The axis intercepts computed by this routine are defined */
/*     as described below. */

/*     Let M be the normal vector's slope. Let DELTAX be */
/*     X - XXPT. Then, given that the normal direction is */
/*     parallel to */

/*             2     2 */
/*        ( X/A,  Y/B  ) */

/*     we have, for non-zero DELTAX, */

/*        Y = M * DELTAX */

/*               2   2 */
/*          = ( A / B )  * ( Y / X ) * ( X - XXPT ) */

/*     So */
/*             2    2 */
/*        X ( B  / A ) = X - XXPT */

/*     and */
/*                         2   2 */
/*        XXPT = X ( 1 - (B / A ) ) */


/*     The X intercept is a linear function of the X-coordinate */
/*     of the point on the ellipsoid. Define the intercept for */

/*        X = 0 */

/*     as the limit as X -> 0 of the expression for XXPT above. */
/*     The expression is continuous and defined at X = 0, so */
/*     we can just evaluate the expression at X = 0 as for other */
/*     values of X. */


/*     Using the definition of M above, we have for non-zero X: */

/*        Y - YXPT = M * X */

/*     or */

/*        YXPT = Y - M*X */

/*                      2   2 */
/*             = Y - ( A / B ) (Y/X) * X */

/*                           2   2 */
/*             = Y (  1 - ( A / B )  ) */

/*     As above, we define YXPT at X = 0 to be the limit as X -> 0 */
/*     of the expression above, which is */

/*                    2   2 */
/*        B (  1 - ( A / B )  ) */


/* $ Examples */

/*     See usage in ZZRYXPDT. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 09-MAR-2016 (NJB) */

/* -& */
/* $ Index_Entries */

/*     find x and y intercepts of ellipse normal line */

/* -& */

/*     SPICELIB functions */


/*     Local variables */

    if (return_(__global_state)) {
	return 0;
    }
    if (*a <= 0. || *b <= 0.) {
	chkin_(__global_state, "ZZELNAXX", (ftnlen)8);
	setmsg_(__global_state, "Semi-axis lengths were A = #; B = #. Both m"
		"ust be positive.", (ftnlen)59);
	errdp_(__global_state, "#", a, (ftnlen)1);
	errdp_(__global_state, "#", b, (ftnlen)1);
	sigerr_(__global_state, "SPICE(NONPOSITIVEAXIS)", (ftnlen)22);
	chkout_(__global_state, "ZZELNAXX", (ftnlen)8);
	return 0;
    }

/*     Find the point lying on the positive X portion of the ellipsoid */
/*     and having the input planetodetic latitude. */

/*     To start, create a normal vector pointing in the direction */
/*     indicated by the latitude. We'll work in three dimensions in */
/*     order to take advantage of existing code. The third coordinates */
/*     of all participating vectors will be zero. */

    normal[0] = cos(*lat);
    normal[1] = sin(*lat);
    normal[2] = 0.;
    ednmpt_(__global_state, a, b, b, normal, ept);

/*     Compute the X-axis and Y-axis intercepts of the line */
/*     passing through EPT and parallel to a normal vector */
/*     at EPT. Refer to the Particulars above for details. */

/* Computing 2nd power */
    d__1 = *b / *a;
    *xxpt = (1. - d__1 * d__1) * ept[0];
/* Computing 2nd power */
    d__1 = *a / *b;
    *yxpt = (1. - d__1 * d__1) * ept[1];
    return 0;
} /* zzelnaxx_ */

