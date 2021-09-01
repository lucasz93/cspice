/* ednmpt.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern ednmpt_init_t __ednmpt_init;
static ednmpt_state_t* get_ednmpt_state(cspice_t* state) {
	if (!state->ednmpt)
		state->ednmpt = __cspice_allocate_module(sizeof(
	ednmpt_state_t), &__ednmpt_init, sizeof(__ednmpt_init));
	return state->ednmpt;

}

/* $Procedure EDNMPT ( Ellipsoid normal vector to surface point ) */
/* Subroutine */ int ednmpt_(cspice_t* __global_state, doublereal *a, 
	doublereal *b, doublereal *c__, doublereal *normal, doublereal *point)
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double pow_dd(f2c_state_t*, doublereal *, doublereal *);

    /* Local variables */
    doublereal scale;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    extern logical vzero_(cspice_t*, doublereal *);
    doublereal lambda;
    doublereal sa;
    doublereal sb;
    doublereal sc;
    extern doublereal touchd_(cspice_t*, doublereal *);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    doublereal na2;
    doublereal nb2;
    doublereal nc2;
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);
    doublereal arg;


    /* Module state */
    ednmpt_state_t* __state = get_ednmpt_state(__global_state);
/* $ Abstract */

/*     Return the unique point on an ellipsoid's surface where the */
/*     outward normal direction is a given vector. */

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

/*     ELLIPSOID */
/*     GEOMETRY */
/*     NORMAL */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     A          I   Length of the ellipsoid semi-axis along the x-axis. */
/*     B          I   Length of the ellipsoid semi-axis along the y-axis. */
/*     C          I   Length of the ellipsoid semi-axis along the z-axis. */
/*     NORMAL     I   Outward normal direction. */
/*     POINT      O   Point where outward normal is parallel to NORMAL. */

/* $ Detailed_Input */

/*     A          is the length of the semi-axis of the ellipsoid */
/*                that is parallel to the x-axis of the body-fixed */
/*                coordinate system. */

/*     B          is the length of the semi-axis of the ellipsoid */
/*                that is parallel to the y-axis of the body-fixed */
/*                coordinate system. */

/*     C          is the length of the semi-axis of the ellipsoid */
/*                that is parallel to the z-axis of the body-fixed */
/*                coordinate system. */

/*     NORMAL     is a non-zero vector. The unique point on the */
/*                ellipsoid at which NORMAL is an outward normal vector */
/*                is sought. */

/* $ Detailed_Output */

/*     POINT      is the unique point on the ellipsoid at which NORMAL */
/*                is an outward normal vector. */

/*                POINT is a 3-vector giving the bodyfixed coordinates */
/*                of a point on the ellipsoid. In bodyfixed coordinates, */
/*                the semi-axes of the ellipsoid are aligned with the x, */
/*                y, and z-axes of the coordinate system. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If any of the semi-axis lengths is non-positive, the error */
/*         SPICE(BADAXISLENGTH) will be signaled. */

/*     2)  If any of the semi-axis lengths underflows to zero when */
/*         divided by the largest semi-axis length, the error */
/*         SPICE(AXISUNDERFLOW) will be signaled. */

/*     3)  If NORMAL is the zero vector, the error SPICE(ZEROVECTOR) */
/*         will be signaled. */

/*     4)  If the input pass the above checks but lead to a */
/*         divide-by-zero error or to an computing an invalid argument */
/*         of a fractional exponential expression, the error */
/*         SPICE(DEGENERATECASE) will be signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine can be used to determine the distance between an */
/*     ellipsoid and a non-intersecting plane. This distance computation */
/*     supports computation of terminator points on an ellipsoid. */

/* $ Examples */

/*     The numerical results shown for this example may differ across */
/*     platforms. The results depend on the SPICE kernels used as */
/*     input, the compiler and supporting libraries, and the machine */
/*     specific arithmetic implementation. */

/*     1) Choose a triaxial ellipsoid with three unequal semi-axis */
/*        lengths. Pick several vectors; find the points on the */
/*        ellipsoid where the respective outward normals are parallel to */
/*        those vectors. */

/*        Check the results: at each point, a computed outward normal */
/*        vector should have very small angular separation from the */
/*        input vector. Also, the point should be on the surface of the */
/*        ellipsoid. The ellipsoid can be thought of as a level surface */
/*        of the function */

/*                             2        2         2 */
/*           f(x, y, z) = (x/a)  + (y/b)  +  (z/c) */

/*        where a, b, c are the semi-axis lengths of the ellipsoid. */
/*        Specifically, the ellipsoid is the set */

/*           { (x, y, z) : f(x, y, z)  =  1 } */

/*        We can evaluate f at a point to determine whether that point */
/*        is close to the ellipsoid's surface. */


/*        Example code begins here. */


/*              PROGRAM EX1 */
/*              IMPLICIT NONE */
/*        C */
/*        C     SPICELIB functions */
/*        C */
/*              DOUBLE PRECISION      VSEP */
/*        C */
/*        C     Local parameters */
/*        C */
/*              CHARACTER*(*)         FMT1 */
/*              PARAMETER           ( FMT1 = '(A,3F15.9)' ) */
/*        C */
/*        C     Local variables */
/*        C */
/*              DOUBLE PRECISION      A */
/*              DOUBLE PRECISION      B */
/*              DOUBLE PRECISION      C */
/*              DOUBLE PRECISION      NORMAL ( 3 ) */
/*              DOUBLE PRECISION      POINT  ( 3 ) */
/*              DOUBLE PRECISION      XNORML ( 3 ) */
/*        C */
/*        C     Initialize the ellipsoid semi-axes. */
/*        C */
/*              A = 10.D0 */
/*              B =  5.D0 */
/*              C =  2.D0 */
/*        C */
/*        C     Pick several vectors; find the points */
/*        C     on the ellipsoid where the respective */
/*        C     outward normals are parallel to those */
/*        C     vectors; check the results. */
/*        C */
/*              CALL VPACK  ( 0.D0, 0.D0, 3.D0, XNORML ) */
/*              CALL EDNMPT ( A,    B,    C,    XNORML, POINT  ) */
/*              CALL SURFNM ( A,    B,    C,    POINT,  NORMAL ) */

/*              WRITE (*,*   ) ' ' */
/*              WRITE (*,FMT1) 'Semi-axis lengths:   ', A, B, C */
/*              WRITE (*,FMT1) 'Input vector:        ', XNORML */
/*              WRITE (*,FMT1) 'Point:               ', POINT */
/*              WRITE (*,FMT1) 'Outward normal:      ', NORMAL */
/*              WRITE (*,FMT1) 'Angular error (rad): ', VSEP(NORMAL, */
/*             .                                          XNORML ) */
/*              WRITE (*,FMT1) 'Off-surface error:   ', */
/*             .                 (POINT(1)/A)**2 + (POINT(2)/B)**2 */
/*             .               + (POINT(3)/C)**2 - 1 */
/*              WRITE (*,*) ' ' */


/*              CALL VPACK  ( 15.D0, -7.D0, 3.D0, XNORML ) */
/*              CALL EDNMPT ( A,      B,    C,    XNORML, POINT  ) */
/*              CALL SURFNM ( A,      B,    C,    POINT,  NORMAL ) */

/*              WRITE (*,FMT1) 'Semi-axis lengths:   ', A, B, C */
/*              WRITE (*,FMT1) 'Input vector:        ', XNORML */
/*              WRITE (*,FMT1) 'Point:               ', POINT */
/*              WRITE (*,FMT1) 'Outward normal:      ', NORMAL */
/*              WRITE (*,FMT1) 'Angular error (rad): ', VSEP(NORMAL, */
/*             .                                             XNORML ) */
/*              WRITE (*,FMT1) 'Off-surface error:   ', */
/*             .                 (POINT(1)/A)**2 + (POINT(2)/B)**2 */
/*             .               + (POINT(3)/C)**2 - 1 */
/*              WRITE (*,*) ' ' */

/*              CALL VPACK  ( 15.D0, -7.D0, 3.D0, XNORML ) */
/*              CALL EDNMPT ( A,      B,    C,    XNORML, POINT  ) */
/*              CALL SURFNM ( A,      B,    C,    POINT,  NORMAL ) */

/*              WRITE (*,FMT1) 'Semi-axis lengths:   ', A, B, C */
/*              WRITE (*,FMT1) 'Input vector:        ', XNORML */
/*              WRITE (*,FMT1) 'Point:               ', POINT */
/*              WRITE (*,FMT1) 'Outward normal:      ', NORMAL */
/*              WRITE (*,FMT1) 'Angular error (rad): ', VSEP(NORMAL, */
/*             .                                             XNORML ) */
/*              WRITE (*,FMT1) 'Off-surface error:   ', */
/*             .                 (POINT(1)/A)**2 + (POINT(2)/B)**2 */
/*             .               + (POINT(3)/C)**2 - 1 */
/*              WRITE (*,*) ' ' */

/*              CALL VPACK  ( A/2, B/2,  C/2, XNORML ) */
/*              CALL EDNMPT ( A,   B,    C,   XNORML, POINT  ) */
/*              CALL SURFNM ( A,   B,    C,   POINT,  NORMAL ) */

/*              WRITE (*,FMT1) 'Semi-axis lengths:   ', A, B, C */
/*              WRITE (*,FMT1) 'Input vector:        ', XNORML */
/*              WRITE (*,FMT1) 'Point:               ', POINT */
/*              WRITE (*,FMT1) 'Outward normal:      ', NORMAL */
/*              WRITE (*,FMT1) 'Angular error (rad): ', VSEP(NORMAL, */
/*             .                                             XNORML ) */
/*              WRITE (*,FMT1) 'Off-surface error:   ', */
/*             .                 (POINT(1)/A)**2 + (POINT(2)/B)**2 */
/*             .               + (POINT(3)/C)**2 - 1 */
/*              WRITE (*,*) ' ' */
/*              END */


/*     When this program was executed on a PC/Linux/gfortran 64-bit */
/*     platform, the output was: */


/*     Semi-axis lengths:      10.000000000    5.000000000    2.000000000 */
/*     Input vector:            0.000000000    0.000000000    3.000000000 */
/*     Point:                   0.000000000    0.000000000    2.000000000 */
/*     Outward normal:          0.000000000    0.000000000    1.000000000 */
/*     Angular error (rad):     0.000000000 */
/*     Off-surface error:       0.000000000 */

/*     Semi-axis lengths:      10.000000000    5.000000000    2.000000000 */
/*     Input vector:           15.000000000   -7.000000000    3.000000000 */
/*     Point:                   9.731032027   -1.135287070    0.077848256 */
/*     Outward normal:          0.891657447   -0.416106809    0.178331489 */
/*     Angular error (rad):     0.000000000 */
/*     Off-surface error:       0.000000000 */

/*     Semi-axis lengths:      10.000000000    5.000000000    2.000000000 */
/*     Input vector:           15.000000000   -7.000000000    3.000000000 */
/*     Point:                   9.731032027   -1.135287070    0.077848256 */
/*     Outward normal:          0.891657447   -0.416106809    0.178331489 */
/*     Angular error (rad):     0.000000000 */
/*     Off-surface error:       0.000000000 */

/*     Semi-axis lengths:      10.000000000    5.000000000    2.000000000 */
/*     Input vector:            5.000000000    2.500000000    1.000000000 */
/*     Point:                   9.694128639    1.211766080    0.077553029 */
/*     Outward normal:          0.880450906    0.440225453    0.176090181 */
/*     Angular error (rad):     0.000000000 */
/*     Off-surface error:       0.000000000 */


/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     W.L. Taber      (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 17-MAY-2016 (NJB) (WLT) */

/* -& */
/* $ Index_Entries */

/*     point on an ellipsoid having given surface normal */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Use discovery check-in. We will test RETURN though, since */
/*     we could have invalid inputs to our arithmetic computations */
/*     if a SPICE error condition exists upon entry. */

    if (return_(__global_state)) {
	return 0;
    }

/*     Perform some preliminary checks. */

/*     We need a non-degenerate ellipsoid to start with. */

    if (*a <= 0. || *b <= 0. || *c__ <= 0.) {
	chkin_(__global_state, "EDNMPT", (ftnlen)6);
	setmsg_(__global_state, "All ellipsoid semi-axis lengths must be str"
		"ictly positive. Lengths were: A = #; B = #; C = #", (ftnlen)
		92);
	errdp_(__global_state, "#", a, (ftnlen)1);
	errdp_(__global_state, "#", b, (ftnlen)1);
	errdp_(__global_state, "#", c__, (ftnlen)1);
	sigerr_(__global_state, "SPICE(BADAXISLENGTH)", (ftnlen)20);
	chkout_(__global_state, "EDNMPT", (ftnlen)6);
	return 0;
    }

/*     We'll work with scaled copies of the input semi-axis */
/*     lengths. */

/* Computing MAX */
    d__1 = max(*a,*b);
    scale = max(d__1,*c__);
    d__1 = *a / scale;
    sa = touchd_(__global_state, &d__1);
    d__1 = *b / scale;
    sb = touchd_(__global_state, &d__1);
    d__1 = *c__ / scale;
    sc = touchd_(__global_state, &d__1);

/*     If any of the scaled-semi axes underflowed to zero, */
/*     we can't continue. */

    if (sa <= 0. || sb <= 0. || sc <= 0.) {
	chkin_(__global_state, "EDNMPT", (ftnlen)6);
	setmsg_(__global_state, "Scaled semi-axis lengths must be strictly p"
		"ositive. Scaled lengths were: SA = #; SB = #; SC = #", (
		ftnlen)95);
	errdp_(__global_state, "#", &sa, (ftnlen)1);
	errdp_(__global_state, "#", &sb, (ftnlen)1);
	errdp_(__global_state, "#", &sc, (ftnlen)1);
	sigerr_(__global_state, "SPICE(AXISUNDERFLOW)", (ftnlen)20);
	chkout_(__global_state, "EDNMPT", (ftnlen)6);
	return 0;
    }

/*     The normal vector can't be the zero vector. */

    if (vzero_(__global_state, normal)) {
	chkin_(__global_state, "EDNMPT", (ftnlen)6);
	setmsg_(__global_state, "The input normal vector was the zero vector"
		". There is no solution.", (ftnlen)66);
	sigerr_(__global_state, "SPICE(ZEROVECTOR)", (ftnlen)17);
	chkout_(__global_state, "EDNMPT", (ftnlen)6);
	return 0;
    }

/*     In general, given an ellipsoid E with axes a, b, c, */
/*     and given a normal vector */

/*        n = ( n1, n2, n3 ) */

/*     this problem is equivalent to finding a point (x,y,z) */
/*     on E such that */

/*             2     2     2 */
/*        ( x/a,  y/b,  z/c ) = lambda * n */

/*     which implies */
/*                                           2     2     2 */
/*        ( x, y, z )         = lambda ( n1*a, n2*b, n3*c ) */


/*     Then since the vector on the left side is on the surface */
/*     of E, we must have */

/*              2       2   2        2   2       2   2 */
/*        lambda  ( ( n1 * a  ) + (n2 * b ) + (n3 + c ) ) = 1 */


/*     Requiring lambda to be positive, we have */

/*                               2   2        2   2       2   2 */
/*        lambda = 1 / sqrt( ( n1 * a  ) + (n2 * b ) + (n3 + c ) ) */


    na2 = normal[0] * sa * sa;
    nb2 = normal[1] * sb * sb;
    nc2 = normal[2] * sc * sc;
    d__1 = na2 * normal[0] + nb2 * normal[1] + nc2 * normal[2];
    arg = touchd_(__global_state, &d__1);
    if (arg <= 0.) {
	chkin_(__global_state, "EDNMPT", (ftnlen)6);
	setmsg_(__global_state, "Scale factor LAMBDA must be positive, but r"
		"eciprocal of square of LAMBDA is #.", (ftnlen)78);
	errdp_(__global_state, "#", &arg, (ftnlen)1);
	sigerr_(__global_state, "SPICE(DEGENERATECASE)", (ftnlen)21);
	chkout_(__global_state, "EDNMPT", (ftnlen)6);
	return 0;
    }

/*     Compute LAMBDA as above, and scale it too. This will place */
/*     POINT on the original ellipsoid. */

    lambda = pow_dd(&__global_state->f2c, &arg, &__state->c_b25) * scale;
    point[0] = lambda * na2;
    point[1] = lambda * nb2;
    point[2] = lambda * nc2;
    return 0;
} /* ednmpt_ */

