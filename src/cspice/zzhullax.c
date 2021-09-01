/* zzhullax.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzhullax_init_t __zzhullax_init;
static zzhullax_state_t* get_zzhullax_state(cspice_t* state) {
	if (!state->zzhullax)
		state->zzhullax = __cspice_allocate_module(sizeof(
	zzhullax_state_t), &__zzhullax_init, sizeof(__zzhullax_init));
	return state->zzhullax;

}

/* $Procedure   ZZHULLAX ( Pyramidal FOV convex hull to FOV axis ) */
/* Subroutine */ int zzhullax_(cspice_t* __global_state, char *inst, integer *
	n, doublereal *bounds, doublereal *axis, ftnlen inst_len)
{
    /* System generated locals */
    integer bounds_dim2, i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);

    /* Local variables */
    extern /* Subroutine */ int vhat_(cspice_t*, doublereal *, doublereal *);
    doublereal xvec[3];
    doublereal yvec[3];
    doublereal zvec[3];
    integer xidx;
    extern doublereal vsep_(cspice_t*, doublereal *, doublereal *);
    integer next;
    logical pass1;
    integer i__;
    integer m;
    doublereal r__;
    doublereal v[3];
    doublereal delta;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    logical found;
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    extern /* Subroutine */ int vlcom_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    integer minix;
    integer maxix;
    doublereal trans[9]	/* was [3][3] */;
    extern /* Subroutine */ int ucrss_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    extern /* Subroutine */ int vcrss_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    extern logical vzero_(cspice_t*, doublereal *);
    extern /* Subroutine */ int vrotv_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *, doublereal *);
    doublereal cp[3];
    extern doublereal pi_(cspice_t*);
    logical ok;
    extern doublereal halfpi_(cspice_t*);
    extern /* Subroutine */ int reclat_(cspice_t*, doublereal *, doublereal *,
	     doublereal *, doublereal *);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    doublereal minlon;
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    doublereal maxlon;
    extern /* Subroutine */ int vhatip_(cspice_t*, doublereal *);
    extern /* Subroutine */ int vsclip_(cspice_t*, doublereal *, doublereal *)
	    ;
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);
    doublereal lat;
    doublereal sep;
    doublereal lon;
    extern /* Subroutine */ int mxv_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    doublereal ray1[3];
    doublereal ray2[3];


    /* Module state */
    zzhullax_state_t* __state = get_zzhullax_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Identify a face of the convex hull of an instrument's */
/*     polygonal FOV, and use this face to generate an axis of the */
/*     FOV. */

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

/*     CK */
/*     FRAMES */
/*     GF */
/*     IK */
/*     KERNEL */

/* $ Keywords */

/*     FOV */
/*     GEOMETRY */
/*     INSTRUMENT */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     MARGIN     P   Minimum complement of FOV cone angle. */
/*     INST       I   Instrument name. */
/*     N          I   Number of FOV boundary vectors. */
/*     BOUNDS     I   FOV boundary vectors. */
/*     AXIS       O   Instrument FOV axis vector. */

/* $ Detailed_Input */

/*     INST       is the name of an instrument with which the field of */
/*                view (FOV) of interest is associated. This name is */
/*                used only to generate long error messages. */

/*     N          is the number of boundary vectors in the array */
/*                BOUNDS. */

/*     BOUNDS     is an array of N vectors emanating from a common */
/*                vertex and defining the edges of a pyramidal region in */
/*                three-dimensional space: this the region within the */
/*                FOV of the instrument designated by INST. The Ith */
/*                vector of BOUNDS resides in elements (1:3,I) of this */
/*                array. */

/*                The vectors contained in BOUNDS are called the */
/*                "boundary vectors" of the FOV. */

/*                The boundary vectors  must satisfy the constraints: */

/*                   1)  The boundary vectors  must be contained within */
/*                       a right circular cone of angular radius less */
/*                       than than (pi/2) - MARGIN radians; in other */
/*                       words, there must be a vector A such that all */
/*                       boundary vectors have angular separation from */
/*                       A of less than (pi/2)-MARGIN radians. */

/*                   2)  There must be a pair of vectors U, V in BOUNDS */
/*                       such that all other boundary vectors lie in */
/*                       the same half space bounded by the plane */
/*                       containing U and V. Furthermore, all other */
/*                       boundary vectors must have orthogonal */
/*                       projections onto a plane normal to this plane */
/*                       such that the projections have angular */
/*                       separation of at least 2*MARGIN radians from */
/*                       the plane spanned by U and V. */

/*                Given the first constraint above, there is plane PL */
/*                such that each of the set of rays extending the */
/*                boundary vectors intersects PL. (In fact, there is an */
/*                infinite set of such planes.) The boundary vectors */
/*                must be ordered so that the set of line segments */
/*                connecting the intercept on PL of the ray extending */
/*                the Ith vector to that of the (I+1)st, with the Nth */
/*                intercept connected to the first, form a polygon (the */
/*                "FOV polygon") constituting the intersection of the */
/*                FOV pyramid with PL. This polygon may wrap in either */
/*                the positive or negative sense about a ray emanating */
/*                from the FOV vertex and passing through the plane */
/*                region bounded by the FOV polygon. */

/*                The FOV polygon need not be convex; it may be */
/*                self-intersecting as well. */

/*                No pair of consecutive vectors in BOUNDS may be */
/*                linearly dependent. */

/*                The boundary vectors need not have unit length. */


/* $ Detailed_Output */

/*     AXIS       is a unit vector normal to a plane containing the */
/*                FOV polygon. All boundary vectors have angular */
/*                separation from AXIS of not more than */

/*                   ( pi/2 ) - MARGIN */

/*                radians. */

/*                This routine signals an error if it cannot find */
/*                a satisfactory value of AXIS. */

/* $ Parameters */

/*     MARGIN     is a small positive number used to constrain the */
/*                orientation of the boundary vectors. See the two */
/*                constraints described in the Detailed_Input section */
/*                above for specifics. */

/* $ Exceptions */

/*     1)  In the input vector count N is not at least 3, the error */
/*         SPICE(INVALIDCOUNT) is signaled. */

/*     2)  If any pair of consecutive boundary vectors has cross */
/*         product zero, the error SPICE(DEGENERATECASE) is signaled. */
/*         For this test, the first vector is considered the successor */
/*         of the Nth. */

/*     3)  If this routine can't find a face of the convex hull of */
/*         the set of boundary vectors such that this face satisfies */
/*         constraint (2) of the Detailed_Input section above, the */
/*         error SPICE(FACENOTFOUND) is signaled. */

/*     4)  If any boundary vectors have longitude too close to 0 */
/*         or too close to pi radians in the face frame (see discussion */
/*         of the search algorithm's steps 3 and 4 in Particulars */
/*         below), the respective errors SPICE(NOTSUPPORTED) or */
/*         SPICE(FOVTOOWIDE) are signaled. */

/*     5)  If any boundary vectors have angular separation of more than */
/*         (pi/2)-MARGIN radians from the candidate FOV axis, the */
/*         error SPICE(FOVTOOWIDE) is signaled. */

/* $ Files */

/*     The boundary vectors input to this routine are typically */
/*     obtained from an IK file. */

/* $ Particulars */

/*     Normally implementation is not discussed in SPICE headers, but we */
/*     make an exception here because this routine's implementation and */
/*     specification are deeply intertwined. */

/*     This routine produces an "axis" for a polygonal FOV using the */
/*     following approach: */

/*        1)  Test pairs of consecutive FOV boundary vectors to see */
/*            whether there's a pair such that the plane region bounded */
/*            by these vectors is */

/*            a)  part of the convex hull of the set of boundary vectors */

/*            b)  such that all other boundary vectors have angular */
/*                separation of at least MARGIN from the plane */
/*                containing these vectors */

/*            This search has O(N**2) run time dependency on N. */

/*            If this test produces a candidate face of the convex hull, */
/*            proceed to step 3. */


/*        2)  If step (1) fails, repeat the search for a candidate */
/*            convex hull face, but this time search over every pair of */
/*            distinct boundary vectors. */

/*            This search has O(N**3) run time dependency on N. */

/*            If this search fails, signal an error. */


/*        3)  Produce a set of basis vectors for a reference frame, */
/*            which we'll call the "face frame," using as the +X axis */
/*            the angle bisector of the vectors bounding the candidate */
/*            face, the +Y axis the inward normal vector to this face, */
/*            and the +Z axis completing a right-handed basis. */


/*        4)  Transform each boundary vector, other than the two vectors */
/*            defining the selected convex hull face, to the face frame */
/*            and compute the vector's longitude in that frame. Find the */
/*            maximum and minimum longitudes of the vectors in the face */
/*            frame. */

/*            If any vector's longitude is less than 2*MARGIN or greater */
/*            than pi - 2*MARGIN radians, signal an error. */


/*        5)  Let DELTA be the difference between pi and the maximum */
/*            longitude found in step (4). Rotate the +Y axis (which */
/*            points in the inward normal direction relative to the */
/*            selected face) by -DELTA/2 radians about the +Z axis of */
/*            the face frame. This rotation aligns the +Y axis with the */
/*            central longitude of the set of boundary vectors. The */
/*            resulting vector is our candidate FOV axis. */


/*        6)  Check the angular separation of the candidate FOV axis */
/*            against each boundary vector. If any vector has angular */
/*            separation of more than (pi/2)-MARGIN radians from the */
/*            axis, signal an error. */


/*     Note that there are reasonable FOVs that cannot be handled by the */
/*     algorithm described here. For example, any FOV whose cross */
/*     section is a regular convex polygon can be made unusable by */
/*     adding boundary vectors aligned with the angle bisectors of each */
/*     face of the pyramid defined by the FOV's boundary vectors. The */
/*     resulting set of boundary vectors has no face in its convex hull */
/*     such that all other boundary vectors have positive angular */
/*     separation from that face. */

/*     Because of this limitation, this algorithm should be used only */
/*     after a simple FOV axis-finding approach, such as using as the */
/*     FOV axis the average of the boundary vectors, has been tried */
/*     unsuccessfully. */

/*     Note that it's easy to construct FOVs where the average of the */
/*     boundary vectors doesn't yield a viable axis: a FOV of angular */
/*     width nearly equal to pi radians, with a sufficiently large */
/*     number of boundary vectors on one side and few boundary vectors */
/*     on the other, is one such example. This routine can find an */
/*     axis for many such intractable FOVs---that's why this routine */
/*     should be called after the simple approach fails. */

/* $ Examples */

/*     See SPICELIB private routine ZZFOVAXI. */

/* $ Restrictions */

/*     1) This is a SPICE private routine. User applications should not */
/*        call this routine. */

/*     2) There are "reasonable" polygonal FOVs that cannot be handled */
/*        by this routine. See the discussion in Particulars above. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    SPICELIB 1.0.0, 05-MAR-2009 (NJB) */

/* -& */
/* $ Index_Entries */

/*     Create axis vector for polygonal FOV */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */

    /* Parameter adjustments */
    bounds_dim2 = *n;

    /* Function Body */
    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "ZZHULLAX", (ftnlen)8);

/*     Nothing found yet. */

    found = FALSE_;
    xidx = 0;

/*     We must have at least 3 boundary vectors. */

    if (*n < 3) {
	setmsg_(__global_state, "Polygonal FOV requires at least 3 boundary "
		"vectors but number supplied for # was #.", (ftnlen)83);
	errch_(__global_state, "#", inst, (ftnlen)1, inst_len);
	errint_(__global_state, "#", n, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDCOUNT)", (ftnlen)19);
	chkout_(__global_state, "ZZHULLAX", (ftnlen)8);
	return 0;
    }

/*     Find an exterior face of the pyramid defined by the */
/*     input boundary vectors. Since most polygonal FOVs will have */
/*     an exterior face bounded by two consecutive rays, we'll */
/*     try pairs of consecutive rays first. If this fails, we'll */
/*     try each pair of rays. */

    i__ = 1;
    while(i__ <= *n && ! found) {

/*        Set the index of the next ray. When we get to the */
/*        last boundary vector, the next ray is the first. */

	if (i__ == *n) {
	    next = 1;
	} else {
	    next = i__ + 1;
	}

/*        Find the cross product of the first ray with the */
/*        second. Depending on the ordering of the boundary */
/*        vectors, this could be an inward or outward normal, */
/*        in the case the current face is exterior. */

	vcrss_(__global_state, &bounds[(i__1 = i__ * 3 - 3) < 3 * bounds_dim2 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "bounds", 
		i__1, "zzhullax_", (ftnlen)408)], &bounds[(i__2 = next * 3 - 
		3) < 3 * bounds_dim2 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "bounds", i__2, "zzhullax_", (ftnlen)408)
		], cp);

/*        We insist on consecutive boundary vectors being */
/*        linearly independent. */

	if (vzero_(__global_state, cp)) {
	    setmsg_(__global_state, "Polygonal FOV must have linearly indepe"
		    "ndent consecutive boundary but vectors at indices # and "
		    "# have cross product equal to the zero vector. Instrumen"
		    "t is #.", (ftnlen)158);
	    errint_(__global_state, "#", &i__, (ftnlen)1);
	    errint_(__global_state, "#", &next, (ftnlen)1);
	    errch_(__global_state, "#", inst, (ftnlen)1, inst_len);
	    sigerr_(__global_state, "SPICE(DEGENERATECASE)", (ftnlen)21);
	    chkout_(__global_state, "ZZHULLAX", (ftnlen)8);
	    return 0;
	}

/*        See whether the other boundary vectors have angular */
/*        separation of at least MARGIN from the plane containing */
/*        the current face. */

	pass1 = TRUE_;
	ok = TRUE_;
	m = 1;
	while(m <= *n && ok) {

/*           Find the angular separation of CP and the Mth vector if the */
/*           latter is not an edge of the current face. */

	    if (m != i__ && m != next) {
		sep = vsep_(__global_state, cp, &bounds[(i__1 = m * 3 - 3) < 
			3 * bounds_dim2 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "bounds", i__1, "zzhullax_", (
			ftnlen)446)]);
		if (pass1) {

/*                 Adjust CP if necessary so that it points */
/*                 toward the interior of the pyramid. */

		    if (sep > halfpi_(__global_state)) {

/*                    Invert the cross product vector and adjust SEP */
/*                    accordingly. Within this "M" loop, all other */
/*                    angular separations will be computed using the new */
/*                    value of CP. */

			vsclip_(__global_state, &__state->c_b20, cp);
			sep = pi_(__global_state) - sep;
		    }
		    pass1 = FALSE_;
		}
		ok = sep < halfpi_(__global_state) - 1e-12;
	    }
	    if (ok) {

/*              Consider the next boundary vector. */

		++m;
	    }
	}

/*        We've tested each boundary vector against the current face, or */
/*        else the loop terminated early because a vector with */
/*        insufficient angular separation from the plane containing the */
/*        face was found. */

	if (ok) {

/*           The current face is exterior. It's bounded by rays I and */
/*           NEXT. */

	    xidx = i__;
	    found = TRUE_;
	} else {

/*           Look at the next face of the pyramid. */

	    ++i__;
	}
    }

/*     If we didn't find an exterior face, we'll have to look at each */
/*     face bounded by a pair of rays, even if those rays are not */
/*     adjacent. (This can be a very slow process is N is large.) */

    if (! found) {
	i__ = 1;
	while(i__ <= *n && ! found) {

/*           Consider all ray pairs (I,NEXT) where NEXT > I. */

	    next = i__ + 1;
	    while(next <= *n && ! found) {

/*              Find the cross product of the first ray with the second. */
/*              If the current face is exterior, CP could be an inward */
/*              or outward normal, depending on the ordering of the */
/*              boundary vectors. */

		vcrss_(__global_state, &bounds[(i__1 = i__ * 3 - 3) < 3 * 
			bounds_dim2 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "bounds", i__1, "zzhullax_", (
			ftnlen)530)], &bounds[(i__2 = next * 3 - 3) < 3 * 
			bounds_dim2 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "bounds", i__2, "zzhullax_", (
			ftnlen)530)], cp);

/*              It's allowable for non-consecutive boundary vectors to */
/*              be linearly dependent, but if we have such a pair, */
/*              it doesn't define an exterior face. */

		if (! vzero_(__global_state, cp)) {

/*                 The rays having direction vectors indexed I and NEXT */
/*                 define a semi-infinite sector of a plane that might */
/*                 be of interest. */

/*                 Check whether all of the boundary vectors that are */
/*                 not edges of the current face have angular separation */
/*                 of at least MARGIN from the plane containing the */
/*                 current face. */

		    pass1 = TRUE_;
		    ok = TRUE_;
		    m = 1;
		    while(m <= *n && ok) {

/*                    Find the angular separation of CP and the Mth */
/*                    vector if the latter is not an edge of the current */
/*                    face. */

			if (m != i__ && m != next) {
			    sep = vsep_(__global_state, cp, &bounds[(i__1 = m 
				    * 3 - 3) < 3 * bounds_dim2 && 0 <= i__1 ? 
				    i__1 : s_rnge(&__global_state->f2c, "bou"
				    "nds", i__1, "zzhullax_", (ftnlen)560)]);
			    if (pass1) {

/*                          Adjust CP if necessary so that it points */
/*                          toward the interior of the pyramid. */

				if (sep > halfpi_(__global_state)) {

/*                             Invert the cross product vector and */
/*                             adjust SEP accordingly. Within this "M" */
/*                             loop, all other angular separations will */
/*                             be computed using the new value of CP. */

				    vsclip_(__global_state, &__state->c_b20, 
					    cp);
				    sep = pi_(__global_state) - sep;
				}
				pass1 = FALSE_;
			    }
			    ok = sep < halfpi_(__global_state) - 1e-12;
			}
			if (ok) {

/*                       Consider the next boundary vector. */

			    ++m;
			}
		    }

/*                 We've tested each boundary vector against the current */
/*                 face, or else the loop terminated early because a */
/*                 vector with insufficient angular separation from the */
/*                 plane containing the face was found. */

		    if (ok) {

/*                    The current face is exterior. It's bounded by rays */
/*                    I and NEXT. */
			xidx = i__;
			found = TRUE_;
		    }

/*                 End of angular separation test block. */

		}

/*              End of non-zero cross product block. */

		if (! found) {

/*                 Look at the face bounded by the rays */
/*                 at indices I and NEXT+1. */

		    ++next;
		}
	    }

/*           End of NEXT loop. */

	    if (! found) {

/*              Look at the face bounded by the pairs of rays */
/*              including the ray at index I+1. */

		++i__;
	    }
	}

/*        End of I loop. */

    }

/*     End of search for exterior face using each pair of rays. */

/*     If we still haven't found an exterior face, we can't continue. */

    if (! found) {
	setmsg_(__global_state, "Unable to find face of convex hull of FOV o"
		"f instrument #.", (ftnlen)58);
	errch_(__global_state, "#", inst, (ftnlen)1, inst_len);
	sigerr_(__global_state, "SPICE(FACENOTFOUND)", (ftnlen)19);
	chkout_(__global_state, "ZZHULLAX", (ftnlen)8);
	return 0;
    }

/*     Arrival at this point means that the rays at indices */
/*     XIDX and NEXT define a plane such that all boundary */
/*     vectors lie in a half-space bounded by that plane. */

/*     We're now going to define a set of orthonormal basis vectors: */

/*        +X  points along the angle bisector of the bounding vectors */
/*            of the exterior face. */

/*        +Y  points along CP. */

/*        +Z  is the cross product of +X and +Y. */

/*     We'll call the reference frame having these basis vectors */
/*     the "face frame." */


    vhat_(__global_state, &bounds[(i__1 = i__ * 3 - 3) < 3 * bounds_dim2 && 0 
	    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "bounds", i__1, 
	    "zzhullax_", (ftnlen)683)], ray1);
    vhat_(__global_state, &bounds[(i__1 = next * 3 - 3) < 3 * bounds_dim2 && 
	    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "bounds", i__1, 
	    "zzhullax_", (ftnlen)684)], ray2);
    vlcom_(__global_state, &__state->c_b36, ray1, &__state->c_b36, ray2, xvec)
	    ;
    vhatip_(__global_state, xvec);
    vhat_(__global_state, cp, yvec);
    ucrss_(__global_state, xvec, yvec, zvec);

/*     Create a transformation matrix to map the input boundary */
/*     vectors into the face frame. */

    for (i__ = 1; i__ <= 3; ++i__) {
	trans[(i__1 = i__ * 3 - 3) < 9 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "trans", i__1, "zzhullax_", (ftnlen)698)]
		 = xvec[(i__2 = i__ - 1) < 3 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "xvec", i__2, "zzhullax_", (ftnlen)698)];
	trans[(i__1 = i__ * 3 - 2) < 9 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "trans", i__1, "zzhullax_", (ftnlen)699)]
		 = yvec[(i__2 = i__ - 1) < 3 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "yvec", i__2, "zzhullax_", (ftnlen)699)];
	trans[(i__1 = i__ * 3 - 1) < 9 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "trans", i__1, "zzhullax_", (ftnlen)700)]
		 = zvec[(i__2 = i__ - 1) < 3 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "zvec", i__2, "zzhullax_", (ftnlen)700)];
    }

/*     Now we're going to compute the longitude of each boundary in the */
/*     face frame. The vectors with indices XIDX and NEXT are excluded. */
/*     We expect all longitudes to be between MARGIN and pi - MARGIN. */

    minlon = pi_(__global_state);
    maxlon = 0.;
    minix = 1;
    maxix = 1;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i__ != xidx && i__ != next) {

/*           The current vector is not a boundary of our edge, */
/*           so find its longitude. */

	    mxv_(__global_state, trans, &bounds[(i__2 = i__ * 3 - 3) < 3 * 
		    bounds_dim2 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "bounds", i__2, "zzhullax_", (ftnlen)
		    720)], v);
	    reclat_(__global_state, v, &r__, &lon, &lat);

/*           Update the longitude bounds. */

	    if (lon < minlon) {
		minix = i__;
		minlon = lon;
	    }
	    if (lon > maxlon) {
		maxix = i__;
		maxlon = lon;
	    }
	}
    }

/*     If the longitude bounds are not as expected, don't try */
/*     to continue. */

    if (minlon < 2e-12) {
	setmsg_(__global_state, "Minimum boundary vector longitude in exteri"
		"or face frame is # radians. Minimum occurs at index #. This "
		"FOV does not conform to the requirements of this routine. In"
		"strument is #.", (ftnlen)177);
	errdp_(__global_state, "#", &minlon, (ftnlen)1);
	errint_(__global_state, "#", &minix, (ftnlen)1);
	errch_(__global_state, "#", inst, (ftnlen)1, inst_len);
	sigerr_(__global_state, "SPICE(NOTSUPPORTED)", (ftnlen)19);
	chkout_(__global_state, "ZZHULLAX", (ftnlen)8);
	return 0;
    } else if (maxlon > pi_(__global_state) - 2e-12) {
	setmsg_(__global_state, "Maximum boundary vector longitude in exteri"
		"or face frame is # radians. Maximum occurs at index #. This "
		"FOV does not conform to the requirements of this routine. In"
		"strument is #.", (ftnlen)177);
	errdp_(__global_state, "#", &maxlon, (ftnlen)1);
	errint_(__global_state, "#", &maxix, (ftnlen)1);
	errch_(__global_state, "#", inst, (ftnlen)1, inst_len);
	sigerr_(__global_state, "SPICE(FOVTOOWIDE)", (ftnlen)17);
	chkout_(__global_state, "ZZHULLAX", (ftnlen)8);
	return 0;
    }

/*     Let delta represent the amount we can rotate the exterior */
/*     face clockwise about +Z without contacting another boundary */
/*     vector. */

    delta = pi_(__global_state) - maxlon;

/*     Rotate +Y by -DELTA/2 about +Z. The result is our candidate */
/*     FOV axis. Make the axis vector unit length. */

    d__1 = -delta / 2;
    vrotv_(__global_state, yvec, zvec, &d__1, axis);
    vhatip_(__global_state, axis);

/*     If we have a viable result, ALL boundary vectors have */
/*     angular separation less than HALFPI-MARGIN from AXIS. */

    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sep = vsep_(__global_state, &bounds[(i__2 = i__ * 3 - 3) < 3 * 
		bounds_dim2 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c,
		 "bounds", i__2, "zzhullax_", (ftnlen)794)], axis);
	if (sep > halfpi_(__global_state) - 1e-12) {
	    setmsg_(__global_state, "Boundary vector at index # has angular "
		    "separation of # radians from candidate FOV axis. This FO"
		    "V does not conform to the requirements of this routine. "
		    "Instrument is #.", (ftnlen)167);
	    errint_(__global_state, "#", &i__, (ftnlen)1);
	    errdp_(__global_state, "#", &sep, (ftnlen)1);
	    errch_(__global_state, "#", inst, (ftnlen)1, inst_len);
	    sigerr_(__global_state, "SPICE(FOVTOOWIDE)", (ftnlen)17);
	    chkout_(__global_state, "ZZHULLAX", (ftnlen)8);
	    return 0;
	}
    }
    chkout_(__global_state, "ZZHULLAX", (ftnlen)8);
    return 0;
} /* zzhullax_ */

