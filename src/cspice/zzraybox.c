/* zzraybox.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzraybox_init_t __zzraybox_init;
static inline zzraybox_state_t* get_zzraybox_state(cspice_t* state) {
	if (!state->zzraybox)
		state->zzraybox = __cspice_allocate_module(sizeof(
	zzraybox_state_t), &__zzraybox_init, sizeof(__zzraybox_init));
	return state->zzraybox;

}

/* $Procedure ZZRAYBOX ( Ray-box intercept ) */
/* Subroutine */ int zzraybox_(cspice_t* __global_state, doublereal *vertex, 
	doublereal *raydir, doublereal *boxori, doublereal *extent, 
	doublereal *xpt, logical *found)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);

    /* Local variables */
    extern /* Subroutine */ int vadd_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    doublereal near__[3];
    extern /* Subroutine */ int vhat_(cspice_t*, doublereal *, doublereal *);
    doublereal udir[3];
    doublereal maxt;
    extern /* Subroutine */ int vsub_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    extern /* Subroutine */ int vequ_(cspice_t*, doublereal *, doublereal *);
    integer i__;
    doublereal r__;
    doublereal t[3];
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    doublereal limit;
    extern /* Subroutine */ int vlcom_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    doublereal vtemp[3];
    extern doublereal vnorm_(cspice_t*, doublereal *);
    extern logical vzero_(cspice_t*, doublereal *);
    doublereal center[3];
    logical sphfnd;
    doublereal offset[3];
    integer maxidx;
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    integer sector[3];
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    doublereal plndst[3];
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int surfpt_(cspice_t*, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, logical *
	    );
    doublereal sphxpt[3];
    doublereal sphvtx[3];


    /* Module state */
    zzraybox_state_t* __state = get_zzraybox_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Find the surface intercept of a ray on a specified box in */
/*     three-dimensional space. */

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

/*     DSK */

/* $ Keywords */

/*     MATH */
/*     GEOMETRY */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     VERTEX     I   Vertex of ray. */
/*     RAYDIR     I   Direction vector of ray. */
/*     BOXORI     I   Box origin: corner having minimum coordinates. */
/*     EXTENT     I   Box extents in X, Y, Z directions. */
/*     XPT        O   Ray-box intercept. */
/*     FOUND      O   Flag indicating whether intercept was found. */

/* $ Detailed_Input */

/*     VERTEX     is the vertex of a ray in three dimensional space. */

/*     RAYDIR     is the direction vector of the input ray. */

/*     BOXORI     is a vector representing the "origin" of a box in */
/*                three-dimensional space. BOXORI is the corner of */
/*                the box at which each coordinate attains its */
/*                minimum value. */

/*     EXTENT     is an array containing the box's edge lengths in */
/*                the X, Y, and Z directions. All lengths must be */
/*                positive. */

/* $ Detailed_Output */

/*     XPT        is the point of intersection closest to VERTEX */
/*                of the ray and the box. If VERTEX lies within the */
/*                box, XPT is set equal to VERTEX. */

/*                XPT is undefined if FOUND is .FALSE. */


/*     FOUND      is set to .TRUE. if and only if the ray intersects */
/*                the box. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the input ray is the zero vector, the error */
/*         SPICE(ZEROVECTOR) is signaled. */

/*     2)  If any element of EXTENT is non-positive, the error */
/*         SPICE(VALUEOUTOFRANGE) is signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     None. */

/* $ Examples */

/*     See use in DSKX02. */

/* $ Restrictions */

/*     This is a private routine; its interface or functionality */
/*     may be changed without notice. SPICE user applications */
/*     should not call this routine directly. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     J.A. Bytof      (JPL) */
/*     E.D. Wright     (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 06-JUN-2014 (NJB) */

/* -& */
/* $ Index_Entries */

/*     compute ray-box intercept */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     Use discovery check-in. */

    if (return_(__global_state)) {
	return 0;
    }

/*     No intercept has been found yet. */

    *found = FALSE_;

/*     Check for a zero ray direction vector. */

    if (vzero_(__global_state, raydir)) {
	chkin_(__global_state, "ZZRAYBOX", (ftnlen)8);
	setmsg_(__global_state, "Input ray direction was the zero vector; th"
		"is vector must be non-zero.", (ftnlen)70);
	sigerr_(__global_state, "SPICE(ZEROVECTOR)", (ftnlen)17);
	chkout_(__global_state, "ZZRAYBOX", (ftnlen)8);
	return 0;
    }
    vhat_(__global_state, raydir, udir);

/*     Check the box extents. */

/* Computing MIN */
    d__1 = min(extent[0],extent[1]);
    if (min(d__1,extent[2]) <= 0.) {
	chkin_(__global_state, "ZZRAYBOX", (ftnlen)8);
	setmsg_(__global_state, "All box extents should be strictly positive"
		" but the extents were #, #, #.", (ftnlen)73);
	errdp_(__global_state, "#", extent, (ftnlen)1);
	errdp_(__global_state, "#", &extent[1], (ftnlen)1);
	errdp_(__global_state, "#", &extent[2], (ftnlen)1);
	sigerr_(__global_state, "SPICE(VALUEOUTOFRANGE)", (ftnlen)22);
	chkout_(__global_state, "ZZRAYBOX", (ftnlen)8);
	return 0;
    }

/*     Compute the coordinates of the center of the box, and compute */
/*     the offset of the ray's vertex from the center. */

    for (i__ = 1; i__ <= 3; ++i__) {
	center[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "center", i__1, "zzraybox_", (ftnlen)242)
		] = boxori[(i__2 = i__ - 1) < 3 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "boxori", i__2, "zzraybox_", (ftnlen)242)
		] + extent[(i__3 = i__ - 1) < 3 && 0 <= i__3 ? i__3 : s_rnge(&
		__global_state->f2c, "extent", i__3, "zzraybox_", (ftnlen)242)
		] / 2;
    }
    vsub_(__global_state, vertex, center, offset);

/*     If the ray's vertex is inside the box, we consider the */
/*     vertex to be the intercept. */

    if (abs(offset[0]) <= extent[0] / 2 && abs(offset[1]) <= extent[1] / 2 && 
	    abs(offset[2]) <= extent[2] / 2) {
	vequ_(__global_state, vertex, xpt);
	*found = TRUE_;
	return 0;
    }

/*     Compute the intercept of the ray on the surface of a bounding */
/*     sphere that contains the box. Let R be the radius of this sphere. */

    r__ = vnorm_(__global_state, extent) * .50049999999999994;
    if (vnorm_(__global_state, offset) < r__) {

/*        The vertex is already inside the bounding sphere. */

	vequ_(__global_state, offset, sphxpt);
    } else {
	surfpt_(__global_state, offset, udir, &r__, &r__, &r__, sphxpt, &
		sphfnd);
	if (! sphfnd) {

/*           The ray misses the bounding sphere. */

	    return 0;
	}
    }

/*     Shift the sphere intercept so as to be relative to the */
/*     box's origin. From this point on, we'll treat BOXORI */
/*     as the origin of the reference frame. */

    for (i__ = 1; i__ <= 3; ++i__) {
	sphvtx[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "sphvtx", i__1, "zzraybox_", (ftnlen)293)
		] = sphxpt[(i__2 = i__ - 1) < 3 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "sphxpt", i__2, "zzraybox_", (ftnlen)293)
		] + center[(i__3 = i__ - 1) < 3 && 0 <= i__3 ? i__3 : s_rnge(&
		__global_state->f2c, "center", i__3, "zzraybox_", (ftnlen)293)
		] - boxori[(i__4 = i__ - 1) < 3 && 0 <= i__4 ? i__4 : s_rnge(&
		__global_state->f2c, "boxori", i__4, "zzraybox_", (ftnlen)293)
		];
    }

/*     Classify the position of the vertex relative to the planes */
/*     bounding the box: each coordinate will be classified as */
/*     "left," "middle," or "right" depending on whether it is */
/*     less than the lower bound for that coordinate, between */
/*     the bounds, or greater than the upper bound. */

    for (i__ = 1; i__ <= 3; ++i__) {
	if (sphvtx[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "sphvtx", i__1, "zzraybox_", (ftnlen)305)
		] < 0.) {
	    sector[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "sector", i__1, "zzraybox_", (ftnlen)
		    307)] = 1;
	    near__[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "near", i__1, "zzraybox_", (ftnlen)
		    308)] = 0.;
	} else if (sphvtx[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "sphvtx", i__1, "zzraybox_", (ftnlen)310)
		] > extent[(i__2 = i__ - 1) < 3 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "extent", i__2, "zzraybox_", (ftnlen)310)
		]) {
	    sector[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "sector", i__1, "zzraybox_", (ftnlen)
		    312)] = 3;
	    near__[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "near", i__1, "zzraybox_", (ftnlen)
		    313)] = extent[(i__2 = i__ - 1) < 3 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "extent", i__2, "zzraybox_", 
		    (ftnlen)313)];
	} else {
	    sector[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "sector", i__1, "zzraybox_", (ftnlen)
		    316)] = 2;
	    near__[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "near", i__1, "zzraybox_", (ftnlen)
		    317)] = 0.;
	}
    }

/*     At this point, SPHVTX is a point on the ray that is outside, */
/*     but close to, the box. SPHVTX is an offset from BOXORI we'll */
/*     need to add BOXORI to it to obtain the corresponding point in */
/*     the input reference frame. */

/*     We'll use SPHVTX as the new ray vertex. */

/*     Find the distances of the vertex's components from the nearest */
/*     bounding planes of the box; find the corresponding distances */
/*     along the ray that would be traveled in order to move each */
/*     component from the vertex to the nearest bounding plane. Call the */
/*     latter distance for the Ith coordinate T(I). We're only */
/*     interested in the vertex components that are "outside" the */
/*     bounding planes. Mark the values of T(I) for components in the */
/*     "middle" using the value -1. */

/*     Find the index of the maximum T value while we're at it. If */
/*     there's an intercept, it occurs at the point on the ray */
/*     corresponding to the maximum value of T. */

    maxidx = 1;
    maxt = -1.;
    for (i__ = 1; i__ <= 3; ++i__) {
	t[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "t", i__1, "zzraybox_", (ftnlen)349)] = 
		-1.;
	if (sector[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "sector", i__1, "zzraybox_", (ftnlen)351)
		] != 2) {
	    plndst[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "plndst", i__1, "zzraybox_", (ftnlen)
		    353)] = near__[(i__2 = i__ - 1) < 3 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "near", i__2, "zzraybox_", (
		    ftnlen)353)] - sphvtx[(i__3 = i__ - 1) < 3 && 0 <= i__3 ? 
		    i__3 : s_rnge(&__global_state->f2c, "sphvtx", i__3, "zzr"
		    "aybox_", (ftnlen)353)];

/*           Prepare for a "safe" division. */

	    limit = r__ * 2 * (d__1 = udir[(i__1 = i__ - 1) < 3 && 0 <= i__1 ?
		     i__1 : s_rnge(&__global_state->f2c, "udir", i__1, "zzra"
		    "ybox_", (ftnlen)358)], abs(d__1));
	    if ((d__1 = plndst[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "plndst", i__1, "zzraybox_", 
		    (ftnlen)360)], abs(d__1)) > limit) {

/*              The ray can't get to the nearest bounding plane */
/*              before exiting the bounding sphere. No intersection */
/*              is possible. */

		return 0;
	    }

/*           The magnitude of the following quotient is bounded by 2R. */

	    t[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "t", i__1, "zzraybox_", (ftnlen)372)]
		     = plndst[(i__2 = i__ - 1) < 3 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "plndst", i__2, "zzraybox_", 
		    (ftnlen)372)] / udir[(i__3 = i__ - 1) < 3 && 0 <= i__3 ? 
		    i__3 : s_rnge(&__global_state->f2c, "udir", i__3, "zzray"
		    "box_", (ftnlen)372)];
	    if (t[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "t", i__1, "zzraybox_", (ftnlen)374)]
		     < 0.) {

/*              This component of the ray is going in the wrong */
/*              direction. No intersection is possible. */

		return 0;
	    }
	    if (t[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "t", i__1, "zzraybox_", (ftnlen)383)]
		     > maxt) {
		maxidx = i__;
		maxt = t[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "t", i__1, "zzraybox_", (ftnlen)
			386)];
	    }
	}
    }

/*     We should have a positive value of T for at least one */
/*     coordinate. However, if we don't, there's no intersection. */

    if (maxt < 0.) {
	return 0;
    }

/*     Compute the candidate intercept. Note that we're now working */
/*     in a frame centered at the box origin. */

    vlcom_(__global_state, &__state->c_b73, sphvtx, &maxt, udir, xpt);

/*     Decide whether XPT is actually on the surface of the box. */
/*     Sharpen XPT as part of the process. */

    for (i__ = 1; i__ <= 3; ++i__) {
	if (i__ == maxidx) {

/*           XPT is supposed to lie exactly on the bounding plane */
/*           orthogonal to the Ith axis and nearest to SPHVTX. */

	    xpt[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "xpt", i__1, "zzraybox_", (ftnlen)
		    419)] = near__[(i__2 = i__ - 1) < 3 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "near", i__2, "zzraybox_", (
		    ftnlen)419)];
	} else {
	    if (sector[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "sector", i__1, "zzraybox_", (ftnlen)
		    423)] == 2) {

/*              The Ith component of the vertex is between the */
/*              bounding planes for the Ith coordinate. If the */
/*              Ith component of XPT is outside these bounds, */
/*              the ray misses the box. */

		if (xpt[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "xpt", i__1, "zzraybox_", (
			ftnlen)430)] < 0. || xpt[(i__2 = i__ - 1) < 3 && 0 <= 
			i__2 ? i__2 : s_rnge(&__global_state->f2c, "xpt", 
			i__2, "zzraybox_", (ftnlen)430)] > extent[(i__3 = i__ 
			- 1) < 3 && 0 <= i__3 ? i__3 : s_rnge(&
			__global_state->f2c, "extent", i__3, "zzraybox_", (
			ftnlen)430)]) {
		    return 0;
		}
	    } else {

/*              The Ith component of the vertex SPHVTX is outside of the */
/*              bounding planes for the Ith coordinate. Since T(MAXIDX) */
/*              is greater than or equal to T(I), XPT(I) should be on or */
/*              past the bounding plane closest to SPHVTX(I). Sharpen */
/*              XPT(I) if necessary. If XPT(I) is beyond the bounding */
/*              plane farthest from SPHVTX(I), no intersection can */
/*              exist. */

		if (sector[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "sector", i__1, "zzraybox_", (
			ftnlen)447)] == 1) {

/*                 Sharpen the Ith component of XPT. */

/* Computing MAX */
		    d__1 = xpt[(i__2 = i__ - 1) < 3 && 0 <= i__2 ? i__2 : 
			    s_rnge(&__global_state->f2c, "xpt", i__2, "zzray"
			    "box_", (ftnlen)451)];
		    xpt[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "xpt", i__1, "zzraybox_", (
			    ftnlen)451)] = max(d__1,0.);
		    if (xpt[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(
			    &__global_state->f2c, "xpt", i__1, "zzraybox_", (
			    ftnlen)453)] > extent[(i__2 = i__ - 1) < 3 && 0 <=
			     i__2 ? i__2 : s_rnge(&__global_state->f2c, "ext"
			    "ent", i__2, "zzraybox_", (ftnlen)453)]) {

/*                    The ray hits the MAXIDX face too far away from */
/*                    SPHVTX(I). There's no intersection with the box. */

			return 0;
		    }
		} else {

/*                 SECTOR(I) .EQ. RIGHT */

/*                 Sharpen the Ith component of XPT. */

/* Computing MIN */
		    d__1 = xpt[(i__2 = i__ - 1) < 3 && 0 <= i__2 ? i__2 : 
			    s_rnge(&__global_state->f2c, "xpt", i__2, "zzray"
			    "box_", (ftnlen)469)], d__2 = extent[(i__3 = i__ - 
			    1) < 3 && 0 <= i__3 ? i__3 : s_rnge(&
			    __global_state->f2c, "extent", i__3, "zzraybox_", 
			    (ftnlen)469)];
		    xpt[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "xpt", i__1, "zzraybox_", (
			    ftnlen)469)] = min(d__1,d__2);
		    if (xpt[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(
			    &__global_state->f2c, "xpt", i__1, "zzraybox_", (
			    ftnlen)471)] < 0.) {

/*                    The ray hits the MAXIDX face too far away from */
/*                    SPHVTX(I). There's no intersection with the box. */

			return 0;
		    }
		}

/*              End of block in which the Ith component of XPT is */
/*              either sharpened or found to be off the surface of the */
/*              box. This block deals with the components other than */
/*              MAXIDX. */

	    }

/*           End of block in which the Ith component of XPT is either */
/*           sharpened or found to be off the surface of the box. This */
/*           block deals with all components. */

	}
    }

/*     End of loop in which XPT is either sharpened or found to be off */
/*     the surface of the box. Getting here means XPT is valid. */

/*     Shift XPT to the input reference frame. */

    vadd_(__global_state, xpt, boxori, vtemp);
    vequ_(__global_state, vtemp, xpt);
    *found = TRUE_;
    return 0;
} /* zzraybox_ */

