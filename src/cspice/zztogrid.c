/* zztogrid.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int zztogrid_state_t;
static inline zztogrid_state_t* get_zztogrid_state(cspice_t* state) {
	return 0;
}

/* $Procedure ZZTOGRID ( Model coordinates to voxel grid coordinates ) */
/* Subroutine */ int zztogrid_(cspice_t* __global_state, doublereal *modxyz, 
	doublereal *voxori, doublereal *voxsiz, doublereal *grdxyz)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);

    /* Local variables */
    integer i__;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    zztogrid_state_t* __state = get_zztogrid_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Shift and scale plate model coordinates to zero-based, double */
/*     precision voxel grid coordinates. */

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
/*     PLATE */
/*     TOPOGRAPHY */
/*     VOXEL */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     MODXYZ     I   Coordinates of point in model coordinates. */
/*     VOXORI     I   Origin of voxel grid in model coordinates. */
/*     VOXSIZ     I   Voxel size in model coordinates. */
/*     GRDXYZ     O   Coordinates of point in voxel grid coordinates. */

/* $ Detailed_Input */

/*     MODXYZ     Coordinates of point in model coordinates. The */
/*                point is expressed as an offset from the center */
/*                of a body-fixed reference frame associated with */
/*                a target body. Units are km. */


/*     VOXORI     Origin of voxel grid in model coordinates. VOXORI */
/*                is expressed in the same reference frame as MODXYZ. */
/*                Units are km. */


/*     VOXSIZ     Voxel size in model coordinates. VOXSIZ is the */
/*                voxel's edge length. Units are km. */


/* $ Detailed_Output */

/*     GRDXYZ     Coordinates of the input point, scaled to voxel grid */
/*                coordinates, and expressed as an offset from the voxel */
/*                grid origin. These coordinates are zero-based, double */
/*                precision values. The units are the voxel edge length */
/*                multiplied by km. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If VOXSIZ is less than or equal to zero, the error */
/*         SPICE(NONPOSITIVEVALUE) is signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine supports DSKX02. */

/* $ Examples */

/*   C */
/*   C     Some position in model coordinates, i.e. the body fixed */
/*   C     units and frame coordinates. */
/*   C */
/*         DOUBLE PRECISION       POS(3) */

/*               ... */

/*   C */
/*   C     Retrieve the voxel grid geometry description. */
/*   C */
/*         CALL VOXDIM ( NVOX, VOXSIZ, VOXORI) */

/*   C */
/*   C     Convert the coordinate POS to voxel grid coordinates. */
/*   C */
/*         CALL ZZTOGRID ( POS, VOXORI, VOXSIZ, POSVOX ) */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     J.A. Bytof      (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 18-MAY-2016 (NJB) */

/*        Added error check for non-positive voxel size. */

/*        02-FEB-2016 (NJB) (JAB) */

/*           Renamed routine to ZZTOGRID. */

/*        08-OCT-2009 (NJB) */

/*           Updated header. */

/*        19-OCT-2004 (EDW) */

/*           Added Examples section, edits to comments. */

/*        03-FEB-1999 (JAB) */

/*           Original version. */

/* -& */
/* $ Index_Entries */

/*     scale plate model coordinates to voxel grid coordinates */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Use discovery check-in. */

    if (return_(__global_state)) {
	return 0;
    }
    if (*voxsiz <= 0.) {
	chkin_(__global_state, "ZZTOGRID", (ftnlen)8);
	setmsg_(__global_state, "Voxel size was #; must be positive.", (
		ftnlen)35);
	errdp_(__global_state, "#", voxsiz, (ftnlen)1);
	sigerr_(__global_state, "SPICE(NONPOSITIVEVALUE)", (ftnlen)23);
	chkout_(__global_state, "ZZTOGRID", (ftnlen)8);
	return 0;
    }

/*     Convert model coordinates to voxel grid coordinates */
/*     via a Galilean transform. */

    for (i__ = 1; i__ <= 3; ++i__) {
	grdxyz[(i__1 = i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "grdxyz", i__1, "zztogrid_", (ftnlen)206)
		] = (modxyz[(i__2 = i__ - 1) < 3 && 0 <= i__2 ? i__2 : s_rnge(
		&__global_state->f2c, "modxyz", i__2, "zztogrid_", (ftnlen)
		206)] - voxori[(i__3 = i__ - 1) < 3 && 0 <= i__3 ? i__3 : 
		s_rnge(&__global_state->f2c, "voxori", i__3, "zztogrid_", (
		ftnlen)206)]) / *voxsiz;
    }
    return 0;
} /* zztogrid_ */

