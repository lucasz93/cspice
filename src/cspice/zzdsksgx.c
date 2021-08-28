/* zzdsksgx.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int zzdsksgx_state_t;
static inline zzdsksgx_state_t* get_zzdsksgx_state(cspice_t* state) {
	return 0;
}

/* $Procedure ZZDSKSGX ( DSK, ray-segment intercept ) */
/* Subroutine */ int zzdsksgx_(cspice_t* __global_state, integer *handle, 
	integer *dladsc, integer *dtype, doublereal *et, doublereal *vertex, 
	doublereal *raydir, doublereal *xpt, doublereal *dc, integer *ic, 
	logical *found)
{
    integer plid;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int dskx02_(cspice_t*, integer *, integer *, 
	    doublereal *, doublereal *, integer *, doublereal *, logical *);
    extern doublereal touchd_(cspice_t*, doublereal *);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    doublereal retval;
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    zzdsksgx_state_t* __state = get_zzdsksgx_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due to the */
/*     volatile nature of this routine. */

/*     Find the intersection of a ray and the surface described by */
/*     a single DSK segment. */

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

/*     GEOMETRY */
/*     INTERCEPT */
/*     INTERSECTION */
/*     RAY */
/*     SURFACE */
/*     TOPOGRAPHY */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   DSK file handle. */
/*     DLADSC     I   DLA descriptor of segment. */
/*     DTYPE      I   Data type code. */
/*     ET         I   Epoch, expressed as seconds past J2000 TDB. */
/*     VERTEX     I   Ray's vertex. */
/*     RAYDIR     I   Ray's direction vector. */
/*     XPT        O   Surface intercept, if found. */
/*     DC         O   D.p. component of source info. */
/*     IC         O   Integer component of source info. */
/*     FOUND      O   Found flag. */

/* $ Detailed_Input */

/*     HANDLE     is the handle of a DSK file containing a segment */
/*                to be used in a ray-surface intercept computation. */

/*     DLASDC     is the DLA descriptor of the DSK segment to be used. */

/*     DTYPE      is the data type code of the segment. While this */
/*                information can be retrieved from the DSK descriptor */
/*                of the segment, the availability of this argument */
/*                saves the time needed to do so. */

/*     ET         is the epoch of the intersection computation, */
/*                expressed as seconds past J2000 TDB. This epoch is */
/*                used for DSK segment selection. */

/*     VERTEX, */
/*     RAYDIR     are, respectively, the vertex and direction vector of */
/*                the ray to be used in the intercept computation. */

/*                Both the vertex and ray's direction vector must be */
/*                represented in the reference frame of the segment. The */
/*                vertex is considered to be an offset from the center */
/*                of the reference frame associated with the segment. */

/* $ Detailed_Output */

/*     XPT        is the intercept of the ray on the surface described */
/*                by the segment, if such an intercept exists. If the */
/*                ray intersects the surface at multiple points, the */
/*                one closest to the ray's vertex is selected. XPT is */
/*                valid if and only if FOUND is .TRUE. */

/*                XPT is expressed in the reference frame associated */
/*                with the specified segment. It represents an offset */
/*                from the center of this frame. Note that the frame */
/*                center may differ from the central body of the */
/*                segment. */


/*     DC         is the double precision component of the data */
/*                source information. Contents are data type- */
/*                dependent. DC is valid if and only if FOUND */
/*                is .TRUE. */


/*     IC         is the integer component of the data */
/*                source information. Contents are data type- */
/*                dependent. IC is valid if and only if FOUND */
/*                is .TRUE. */

/*                For type 2 segments, IC contains just the */
/*                intercept plate ID in element 1. */


/*     FOUND      is a logical flag that is set to .TRUE. if and only */
/*                if a ray-surface intercept was found. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the DSK segment data type is not recognized, the error */
/*         SPICE(TYPENOTSUPPORTED) is signaled. */

/* $ Files */

/*     Appropriate kernels must be loaded by the calling program before */
/*     this routine is called. */

/*     The following data are required: */

/*        - DSK data: the DSK file designated by HANDLE and containing */
/*          the segment having the DLA descriptor DLADSC must be loaded */
/*          at the time this routine is called. */

/*     Kernel data are normally loaded once per program run, NOT every */
/*     time this routine is called. */

/* $ Particulars */

/*     This routine sits on top of data DSK type-specific ray-segment */
/*     intercept routines such as DSKX02. */

/* $ Examples */

/*     See usage in ZZDSKBUX. */

/* $ Restrictions */

/*     This is a private routine. It is meant to be used only by the DSK */
/*     subsystem. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 18-FEB-2016 (NJB) */

/*        Based on first version 20-JAN-2015 (NJB) */

/* -& */
/* $ Index_Entries */

/*     find intercept of ray with surface defined by dsk segment */

/* -& */

/*     SPICELIB functions */


/*     Local variables */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "ZZDSKSGX", (ftnlen)8);

/*     Note: input argument ET is provided to support time-dependent */
/*     data types. */

    retval = touchd_(__global_state, et);
    dc[0] = touchd_(__global_state, dc);
    if (*dtype == 2) {

/*        The intercept plate ID is returned in element 1 of */
/*        IC, if an intercept is found. */

	dskx02_(__global_state, handle, dladsc, vertex, raydir, &plid, xpt, 
		found);
	if (*found) {
	    ic[0] = plid;
	}
    } else {
	setmsg_(__global_state, "DSK ray-surface intercepts are not supporte"
		"d for DSK data type #.", (ftnlen)65);
	errint_(__global_state, "#", dtype, (ftnlen)1);
	sigerr_(__global_state, "SPICE(TYPENOTSUPPORTED)", (ftnlen)23);
	chkout_(__global_state, "ZZDSKSGX", (ftnlen)8);
	return 0;
    }
    chkout_(__global_state, "ZZDSKSGX", (ftnlen)8);
    return 0;
} /* zzdsksgx_ */

