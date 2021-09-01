/* zzrtnmat.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzrtnmat_init_t __zzrtnmat_init;
static zzrtnmat_state_t* get_zzrtnmat_state(cspice_t* state) {
	if (!state->zzrtnmat)
		state->zzrtnmat = __cspice_allocate_module(sizeof(
	zzrtnmat_state_t), &__zzrtnmat_init, sizeof(__zzrtnmat_init));
	return state->zzrtnmat;

}

/* $Procedure ZZRTNMAT ( RTN transformation matrix ) */
/* Subroutine */ int zzrtnmat_(cspice_t* __global_state, doublereal *v, 
	doublereal *m)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    double atan2(doublereal, doublereal), cos(doublereal), sin(doublereal);
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);

    /* Local variables */
    doublereal east[3];
    extern /* Subroutine */ int vhat_(cspice_t*, doublereal *, doublereal *);
    doublereal vlon[3];
    integer i__;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    doublereal north[3];
    extern /* Subroutine */ int ucrss_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);
    extern /* Subroutine */ int cleard_(cspice_t*, integer *, doublereal *);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);
    doublereal rad[3];
    doublereal lon;


    /* Module state */
    zzrtnmat_state_t* __state = get_zzrtnmat_state(__global_state);
/* $ Abstract */

/*     Given a vector, return a transformation matrix that maps from the */
/*     vector's base reference frame to the RTN */
/*     (radial-tangential-normal) frame associated with the vector. */

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

/*     ROTATION */

/* $ Keywords */

/*     FRAMES */
/*     MATRIX */
/*     ROTATION */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     V          I   A 3-dimensional vector. */
/*     M          O   Base frame to RTN frame rotation matrix. */

/* $ Detailed_Input */

/*     V              is any vector that does not lie on the Z-axis */
/*                    of the reference frame relative to which the */
/*                    vector is expressed: at least one of V's X or */
/*                    Y components must be non-zero. */

/* $ Detailed_Output */

/*     M              is a rotation matrix that transforms vectors */
/*                    from the base frame of V---that is, the reference */
/*                    frame relative to which V is expressed---to */
/*                    the RTN (radial, tangential, normal) frame */
/*                    defined by V. */

/*                    The basis vectors of the RTN frame are defined */
/*                    as follows: */

/*                       Axis 1: radial direction R. This axis is */
/*                               parallel to V. */

/*                       Axis 2: tangential direction T. This axis */
/*                               is parallel to Z x V, where Z is */
/*                               the third axis of V's base frame. */

/*                       Axis 3: normal direction N. This axis is */
/*                               parallel to R x T. */

/*                   The unit vectors R, T, N are, respectively, the */
/*                   first, second and third rows of M. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If the input vector V has X and Y components equal to zero, */
/*        the error SPICE(DEGENERATECASE) is signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     The RTN frame supported this routine is a generalization of */
/*     the frame defined by a solar system object's spin axis and */
/*     and a position vector (often the position of a spacecraft */
/*     relative to the center of the object). */

/*     If the base frame of the input vector V is the body-fixed, */
/*     body-centered planetocentric frame associated with a solar system */
/*     object such as a planet or satellite, then the R, T, N directions */
/*     correspond to the "up", "East," and "North" directions at the */
/*     location indicated by V. */

/* $ Examples */

/*     1) Get the RTN transformation matrix for the vector ( 1, 0, 1 ): */


/*           IMPLICIT NONE */

/*           DOUBLE PRECISION      V ( 3 ) */
/*           DOUBLE PRECISION      M ( 3, 3 ) */
/*           INTEGER               I */
/*           INTEGER               J */

/*           CALL VPACK    ( 1.D0, 0.D0, 1.D0, V ) */

/*           CALL ZZRTNMAT ( V, M ) */

/*           DO I = 1, 3 */
/*              WRITE(*,'(3E15.7)') ( M(I,J), J = 1, 3 ) */
/*           END DO */

/*           END */

/*        When this program was executed on a PC/Linux/g77 system, the */
/*        output was */

/*            0.7071068E+00  0.0000000E+00  0.7071068E+00 */
/*            0.0000000E+00  0.1000000E+01  0.0000000E+00 */
/*           -0.7071068E+00  0.0000000E+00  0.7071068E+00 */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 05-MAR-2009 (NJB) */

/* -& */
/* $ Index_Entries */

/*     transformation to radial, tangential, normal frame */
/*     transformation to rtn frame */

/* -& */

/*     SPICELIB functions */


/*     Local variables */

/*     Internally, we're going to use the more */
/*     descriptive names EAST for the "tangential" */
/*     direction and NORTH for the "normal" direction. */


/*     Saved variables */


/*     Initial values */


/*     Use discovery check-in. Just test the RETURN status. */

    if (return_(__global_state)) {
	return 0;
    }
    if (v[0] == 0. && v[1] == 0.) {
	cleard_(__global_state, &__state->c__9, m);
	chkin_(__global_state, "ZZRTNMAT", (ftnlen)8);
	setmsg_(__global_state, "Input vector (# # #) lies on Z-axis; tangen"
		"tial and normal directions are undefined.", (ftnlen)84);
	errdp_(__global_state, "#", v, (ftnlen)1);
	errdp_(__global_state, "#", &v[1], (ftnlen)1);
	errdp_(__global_state, "#", &v[2], (ftnlen)1);
	sigerr_(__global_state, "SPICE(DEGENERATECASE)", (ftnlen)21);
	chkout_(__global_state, "ZZRTNMAT", (ftnlen)8);
	return 0;
    } else {

/*        The two-argument arctangent function gives us a */
/*        robust way of determining the longitude of V, even */
/*        when the magnitude of V is very small. */

	lon = atan2(v[1], v[0]);

/*        Let VLON be a unit vector in the x-y plane whose */
/*        longitude is LON. */

	vlon[0] = cos(lon);
	vlon[1] = sin(lon);
	vlon[2] = 0.;

/*        We can compute the East and North vectors */
/*        without much loss of precision, since VLON is */
/*        orthogonal to Z and EAST is orthogonal to V. */

	ucrss_(__global_state, __state->z__, vlon, east);
	ucrss_(__global_state, v, east, north);
	vhat_(__global_state, v, rad);

/*        The rows of M are the basis vectors of */
/*        the radial/East/North frame: */

	for (i__ = 1; i__ <= 3; ++i__) {
	    m[(i__1 = i__ * 3 - 3) < 9 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "m", i__1, "zzrtnmat_", (ftnlen)258)]
		     = rad[(i__2 = i__ - 1) < 3 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "rad", i__2, "zzrtnmat_", (ftnlen)
		    258)];
	    m[(i__1 = i__ * 3 - 2) < 9 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "m", i__1, "zzrtnmat_", (ftnlen)259)]
		     = east[(i__2 = i__ - 1) < 3 && 0 <= i__2 ? i__2 : s_rnge(
		    &__global_state->f2c, "east", i__2, "zzrtnmat_", (ftnlen)
		    259)];
	    m[(i__1 = i__ * 3 - 1) < 9 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "m", i__1, "zzrtnmat_", (ftnlen)260)]
		     = north[(i__2 = i__ - 1) < 3 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "north", i__2, "zzrtnmat_", (
		    ftnlen)260)];
	}
    }
    return 0;
} /* zzrtnmat_ */

