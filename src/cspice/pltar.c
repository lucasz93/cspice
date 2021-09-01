/* pltar.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int pltar_state_t;
static pltar_state_t* get_pltar_state(cspice_t* state) {
	return 0;
}

/* $Procedure PLTAR ( Compute area of plate set ) */
doublereal pltar_(cspice_t* __global_state, integer *nv, doublereal *vrtces, 
	integer *np, integer *plates)
{
    /* System generated locals */
    integer vrtces_dim2, plates_dim2, i__1, i__2, i__3, i__4, i__5;
    doublereal ret_val;

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);

    /* Local variables */
    extern /* Subroutine */ int vsub_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    doublereal edge1[3];
    doublereal edge2[3];
    integer i__;
    integer j;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int vcrss_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    extern doublereal vnorm_(cspice_t*, doublereal *);
    doublereal cp[3];
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    pltar_state_t* __state = get_pltar_state(__global_state);
/* $ Abstract */

/*     Compute the total area of a collection of triangular plates. */

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
/*     GEOMETRY */
/*     MATH */
/*     TOPOGRAPHY */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     NV         I   Number of vertices. */
/*     VRTCES     I   Array of vertices. */
/*     NP         I   Number of triangular plates. */
/*     PLATES     I   Array of plates. */

/*     The function returns the total area of the set of plates. */

/* $ Detailed_Input */

/*     NV             is the number of vertices comprising the plate */
/*                    set. */

/*     VRTCES         is an array containing the plate model's vertices. */
/*                    Elements */

/*                       VRTCES( 1, I ) */
/*                       VRTCES( 2, I ) */
/*                       VRTCES( 3, I ) */

/*                    are, respectively, the X, Y, and Z components of */
/*                    the Ith vertex. */

/*                    This routine doesn't associate units with the */
/*                    vertices. */


/*     NP             is the number of triangular plates comprising the */
/*                    plate set. */

/*     PLATES         is an array containing 3-tuples of integers */
/*                    representing the set of plates. The elements of */
/*                    PLATES are vertex indices. The vertex indices are */
/*                    1-based: vertices have indices ranging from 1 to */
/*                    NV. The elements */

/*                       PLATES( 1, I ) */
/*                       PLATES( 2, I ) */
/*                       PLATES( 3, I ) */

/*                    are, respectively, the indices of the vertices */
/*                    comprising the Ith plate. */

/*                    Note that the order of the vertices of a plate is */
/*                    significant: the vertices must be ordered in the */
/*                    positive (counterclockwise) sense with respect to */
/*                    the outward normal direction associated with the */
/*                    plate. In other words, if V1, V2, V3 are the */
/*                    vertices of a plate, then */

/*                       ( V2 - V1 )  x  ( V3 - V2 ) */

/*                    points in the outward normal direction. Here */
/*                    'x' denotes the vector cross product operator. */


/* $ Detailed_Output */

/*     The function returns the total area of the input set of plates. */
/*     Each plate contributes the area of the triangle defined by the */
/*     plate's vertices. */

/*     If the components of the vertex array have length unit L, then the */
/*     output area has units */

/*         2 */
/*        L */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If the number of plates is less than 0, the error */
/*        SPICE(BADPLATECOUNT) is signaled. */

/*     2) If the number of plates is positive and the number of vertices */
/*        is less than 3, the error SPICE(TOOFEWVERTICES) is signaled. */

/*     3) If any plate contains a vertex index outside of the range */

/*           [1, NV] */

/*        the error SPICE(INDEXOUTOFRANGE) will be signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine computes the total area of a set of triangular */
/*     plates. The plates need not define a closed surface. */

/*     Examples of valid plate sets: */

/*        Tetrahedron */
/*        Box */
/*        Tiled ellipsoid */
/*        Tiled ellipsoid with one plate removed */
/*        Two disjoint boxes */
/*        Two boxes with intersection having positive volume */
/*        Single plate */
/*        Empty plate set */


/* $ Examples */

/*     The numerical results shown for these examples may differ across */
/*     platforms. The results depend on the SPICE kernels used as input */
/*     (if any), the compiler and supporting libraries, and the machine */
/*     specific arithmetic implementation. */


/*     1) Compute the area of the pyramid defined by the four */
/*        triangular plates whose vertices are the 3-element */
/*        subsets of the set of vectors */

/*           ( 0, 0, 0 ) */
/*           ( 1, 0, 0 ) */
/*           ( 0, 1, 0 ) */
/*           ( 0, 0, 1 ) */


/*        Example code begins here. */

/*           PROGRAM EX1 */
/*           IMPLICIT NONE */
/*     C */
/*     C     Compute the area of a plate model representing the pyramid */
/*     C     with one vertex at the origin and the other vertices */
/*     C     coinciding with the standard basis vectors. */
/*     C */
/*     C */
/*     C     SPICELIB functions */
/*     C */
/*           DOUBLE PRECISION      PLTAR */
/*     C */
/*     C     Local parameters */
/*     C */
/*           INTEGER               NVERT */
/*           PARAMETER           ( NVERT  = 4 ) */

/*           INTEGER               NPLATE */
/*           PARAMETER           ( NPLATE = 4 ) */
/*     C */
/*     C     Local variables */
/*     C */
/*           DOUBLE PRECISION      VRTCES ( 3, NVERT  ) */
/*           DOUBLE PRECISION      AREA */

/*           INTEGER               PLATES ( 3, NPLATE ) */
/*     C */
/*     C     Initial values */
/*     C */
/*     C     The plates defined below lie in the following planes, */
/*     C     respectively: */
/*     C */
/*     C        Plate 1:    { P :  < P, (-1,  0,  0) > = 0 } */
/*     C        Plate 2:    { P :  < P, ( 0, -1,  0) > = 0 } */
/*     C        Plate 3:    { P :  < P, ( 0,  0, -1) > = 0 } */
/*     C        Plate 4:    { P :  < P, ( 1,  1,  1) > = 1 } */
/*     C */
/*           DATA                  PLATES /    1,     4,     3, */
/*          .                                  1,     2,     4, */
/*          .                                  1,     3,     2, */
/*          .                                  2,     3,     4 / */

/*           DATA                  VRTCES / 0.D0,  0.D0,  0.D0, */
/*          .                               1.D0,  0.D0,  0.D0, */
/*          .                               0.D0,  1.D0,  0.D0, */
/*          .                               0.D0,  0.D0,  1.D0 / */


/*           AREA = PLTAR ( NVERT, VRTCES, NPLATE, PLATES ) */

/*           WRITE (*,*) 'Expected area   =    (3 + SQRT(3)) / 2' */
/*           WRITE (*,*) '                =    0.23660254037844384E+01' */
/*           WRITE (*,*) 'Computed area   = ', AREA */

/*           END */


/*     When this program was executed on a PC/Linux/gfortran platform, */
/*     the output was: */


/*        Expected area   =    (3 + SQRT(3)) / 2 */
/*                        =    0.23660254037844384E+01 */
/*        Computed area   =    2.3660254037844384 */


/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 21-OCT-2016 (NJB) */

/*        Original version 25-MAR-2016 (NJB) */

/* -& */
/* $ Index_Entries */

/*     compute plate model area */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     The function must have an initial value. */

    /* Parameter adjustments */
    vrtces_dim2 = *nv;
    plates_dim2 = *np;

    /* Function Body */
    ret_val = 0.;

/*     This routine uses discovery check-in. */

    if (return_(__global_state)) {
	return ret_val;
    }

/*     Check the vertex and plate counts. */

    if (*np < 0) {
	chkin_(__global_state, "PLTAR", (ftnlen)5);
	setmsg_(__global_state, "Plate count must be non-negative but NP = #."
		, (ftnlen)44);
	errint_(__global_state, "#", np, (ftnlen)1);
	sigerr_(__global_state, "SPICE(BADPLATECOUNT)", (ftnlen)20);
	chkout_(__global_state, "PLTAR", (ftnlen)5);
	return ret_val;
    }
    if (*np == 0) {

/*        The area has already been set to zero. */

	return ret_val;
    }
    if (*nv < 3) {
	chkin_(__global_state, "PLTAR", (ftnlen)5);
	setmsg_(__global_state, "At least 3 vertices are needed, but NV = #.",
		 (ftnlen)43);
	errint_(__global_state, "#", nv, (ftnlen)1);
	sigerr_(__global_state, "SPICE(TOOFEWVERTICES)", (ftnlen)21);
	chkout_(__global_state, "PLTAR", (ftnlen)5);
	return ret_val;
    }

/*     Make sure the vertex indices are in the range [1, NV]. */

    i__1 = *np;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 3; ++j) {
	    if (plates[(i__2 = j + i__ * 3 - 4) < 3 * plates_dim2 && 0 <= 
		    i__2 ? i__2 : s_rnge(&__global_state->f2c, "plates", i__2,
		     "pltar_", (ftnlen)348)] < 1 || plates[(i__3 = j + i__ * 
		    3 - 4) < 3 * plates_dim2 && 0 <= i__3 ? i__3 : s_rnge(&
		    __global_state->f2c, "plates", i__3, "pltar_", (ftnlen)
		    348)] > *nv) {
		chkin_(__global_state, "PLTAR", (ftnlen)5);
		setmsg_(__global_state, "Vertex indices must be in the range"
			" [1, NV] for all SPICE language versions. The input "
			"value of NV was #. Vertex index # in plate # was #. "
			"(The vertex and plate numbers in this message are 1-"
			"based as well.)", (ftnlen)206);
		errint_(__global_state, "#", nv, (ftnlen)1);
		errint_(__global_state, "#", &j, (ftnlen)1);
		errint_(__global_state, "#", &i__, (ftnlen)1);
		errint_(__global_state, "#", &plates[(i__2 = j + i__ * 3 - 4) 
			< 3 * plates_dim2 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "plates", i__2, "pltar_", (
			ftnlen)361)], (ftnlen)1);
		sigerr_(__global_state, "SPICE(INDEXOUTOFRANGE)", (ftnlen)22);
		chkout_(__global_state, "PLTAR", (ftnlen)5);
		return ret_val;
	    }
	}
    }
    i__1 = *np;
    for (i__ = 1; i__ <= i__1; ++i__) {

/*        Take the cross product of two edges of the Ith plate. */

	vsub_(__global_state, &vrtces[(i__3 = plates[(i__2 = i__ * 3 - 2) < 3 
		* plates_dim2 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "plates", i__2, "pltar_", (ftnlen)377)] *
		 3 - 3) < 3 * vrtces_dim2 && 0 <= i__3 ? i__3 : s_rnge(&
		__global_state->f2c, "vrtces", i__3, "pltar_", (ftnlen)377)], 
		&vrtces[(i__5 = plates[(i__4 = i__ * 3 - 3) < 3 * plates_dim2 
		&& 0 <= i__4 ? i__4 : s_rnge(&__global_state->f2c, "plates", 
		i__4, "pltar_", (ftnlen)377)] * 3 - 3) < 3 * vrtces_dim2 && 0 
		<= i__5 ? i__5 : s_rnge(&__global_state->f2c, "vrtces", i__5, 
		"pltar_", (ftnlen)377)], edge1);
	vsub_(__global_state, &vrtces[(i__3 = plates[(i__2 = i__ * 3 - 1) < 3 
		* plates_dim2 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "plates", i__2, "pltar_", (ftnlen)380)] *
		 3 - 3) < 3 * vrtces_dim2 && 0 <= i__3 ? i__3 : s_rnge(&
		__global_state->f2c, "vrtces", i__3, "pltar_", (ftnlen)380)], 
		&vrtces[(i__5 = plates[(i__4 = i__ * 3 - 2) < 3 * plates_dim2 
		&& 0 <= i__4 ? i__4 : s_rnge(&__global_state->f2c, "plates", 
		i__4, "pltar_", (ftnlen)380)] * 3 - 3) < 3 * vrtces_dim2 && 0 
		<= i__5 ? i__5 : s_rnge(&__global_state->f2c, "vrtces", i__5, 
		"pltar_", (ftnlen)380)], edge2);
	vcrss_(__global_state, edge1, edge2, cp);

/*        The plate area is 1/2 of the magnitude of the */
/*        cross product. */

	ret_val += vnorm_(__global_state, cp) * .5;
    }

/*     No check-out required, since the routine is not checked in */
/*     at this point. */

    return ret_val;
} /* pltar_ */

