/* pxform.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern pxform_init_t __pxform_init;
static pxform_state_t* get_pxform_state(cspice_t* state) {
	if (!state->pxform)
		state->pxform = __cspice_allocate_module(sizeof(
	pxform_state_t), &__pxform_init, sizeof(__pxform_init));
	return state->pxform;

}

/* $Procedure      PXFORM ( Position Transformation Matrix ) */
/* Subroutine */ int pxform_(cspice_t* __global_state, char *from, char *to, 
	doublereal *et, doublereal *rotate, ftnlen from_len, ftnlen to_len)
{
    /* Initialized data */


    extern /* Subroutine */ int zznamfrm_(cspice_t*, integer *, char *, 
	    integer *, char *, integer *, ftnlen, ftnlen);
    extern /* Subroutine */ int zzctruin_(cspice_t*, integer *);
    integer fcode;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer tcode;
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int refchg_(cspice_t*, integer *, integer *, 
	    doublereal *, doublereal *);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    pxform_state_t* __state = get_pxform_state(__global_state);
/* $ Abstract */

/*     Return the matrix that transforms position vectors from one */
/*     specified frame to another at a specified epoch. */

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

/*      FRAMES */

/* $ Keywords */

/*      FRAMES */

/* $ Declarations */
/* $ Abstract */

/*     This include file defines the dimension of the counter */
/*     array used by various SPICE subsystems to uniquely identify */
/*     changes in their states. */

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

/* $ Parameters */

/*     CTRSIZ      is the dimension of the counter array used by */
/*                 various SPICE subsystems to uniquely identify */
/*                 changes in their states. */

/* $ Author_and_Institution */

/*     B.V. Semenov    (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 29-JUL-2013 (BVS) */

/* -& */

/*     End of include file. */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     FROM       I   Name of the frame to transform from. */
/*     TO         I   Name of the frame to transform to. */
/*     ET         I   Epoch of the rotation matrix. */
/*     ROTATE     O   A rotation matrix */

/* $ Detailed_Input */

/*     FROM        is the name of some reference frame in which */
/*                 a position vector is known. */

/*     TO          is the name of a reference frame in which it */
/*                 is desired to represent a position vector. */

/*     ET          is the epoch in ephemeris seconds past the epoch */
/*                 of J2000 (TDB) at which the position transformation */
/*                 matrix ROTATE should be evaluated. */

/* $ Detailed_Output */

/*     ROTATE      is the matrix that transforms position vectors from */
/*                 the reference frame FROM to the frame TO at epoch ET. */
/*                 If (x, y, z) is a position relative to the frame FROM */
/*                 then the vector ( x', y', z') is the same position */
/*                 relative to the frame TO at epoch ET.  Here the */
/*                 vector ( x', y', z' ) is defined by the equation: */

/*                   -   -       -        -     -  - */
/*                  | x'  |     |          |   | x  | */
/*                  | y'  |     |  ROTATE  |   | y  | */
/*                  | z'  |  =  |          |   | z  | */
/*                   -   -       -        -     -  - */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If sufficient information has not been supplied via loaded */
/*        SPICE kernels to compute the transformation between the */
/*        two frames, the error will be diagnosed by a routine */
/*        in the call tree to this routine. */

/*     2) If either frame FROM or TO is not recognized the error */
/*        'SPICE(UNKNOWNFRAME)' will be signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine provides the user level interface to computing */
/*     position transformations from one reference frame to another. */

/*     Note that the reference frames may be inertial or non-inertial. */
/*     However, the user must take care that sufficient SPICE kernel */
/*     information is loaded to provide a complete position */
/*     transformation path from the FROM frame to the TO frame. */

/* $ Examples */

/*     Suppose that you have geodetic coordinates of a station on the */
/*     surface of the earth and that you need the inertial (J2000) */
/*     position of this station.  The following code fragment */
/*     illustrates how to transform the position of the station to a */
/*     J2000 position. */

/*        CALL BODVRD ( 'EARTH', RADII, 3, N, ABC  ) */

/*        EQUATR   =  ABC(1) */
/*        POLAR    =  ABC(3) */
/*        F        = (EQUATR - POLAR) / EQUATR */

/*        CALL GEOREC ( LONG, LAT, 0.0D0,  EQUATR, F, EPOS ) */

/*        CALL PXFORM ( 'IAU_EARTH', 'J2000', ET,  ROTATE  ) */
/*        CALL MXV    (  ROTATE,      EPOS,   JPOS         ) */

/*     The state JPOS is the desired J2000 position of the station. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*      None. */

/* $ Author_and_Institution */

/*     C.H. Acton      (JPL) */
/*     N.J. Bachman    (JPL) */
/*     B.V. Semenov    (JPL) */
/*     W.L. Taber      (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 23-SEP-2013 (BVS) */

/*        Updated to save the input frame names and POOL state counters */
/*        and to do frame name-ID conversions only if the counters have */
/*        changed. */

/* -    SPICELIB Version 1.0.3, 27-FEB-2008 (BVS) */

/*        Added FRAMES to the Required_Reading section. */

/* -    SPICELIB Version 1.0.2, 23-OCT-2005 (NJB) */

/*        Header example had invalid flattening factor computation; */
/*        this was corrected.  Reference to BODVAR in header was */
/*        replaced with reference to BODVRD. */

/* -    SPICELIB Version 1.0.1, 29-JUL-2003 (NJB) (CHA) */

/*        Various header corrections were made. */

/* -    SPICELIB Version 1.0.0, 05-APR-1999 (WLT) */


/* -& */
/* $ Index_Entries */

/*     Find a position transformation matrix */

/* -& */

/*     Spicelib Functions */


/*     Local parameters. */


/*     Saved frame name length. */


/*     Local Variables. */


/*     Saved frame name/ID item declarations. */


/*     Saved frame name/ID items. */


/*     Initial values. */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "PXFORM", (ftnlen)6);

/*     Initialization. */

    if (__state->first) {

/*        Initialize counters. */

	zzctruin_(__global_state, __state->svctr1);
	zzctruin_(__global_state, __state->svctr2);
	__state->first = FALSE_;
    }
    zznamfrm_(__global_state, __state->svctr1, __state->svfrom, &
	    __state->svfcod, from, &fcode, (ftnlen)32, from_len);
    zznamfrm_(__global_state, __state->svctr2, __state->svto, &
	    __state->svtcde, to, &tcode, (ftnlen)32, to_len);

/*     Only non-zero id-codes are legitimate frame id-codes.  Zero */
/*     indicates that the frame wasn't recognized. */

    if (fcode != 0 && tcode != 0) {
	refchg_(__global_state, &fcode, &tcode, et, rotate);
    } else if (fcode == 0 && tcode == 0) {
	setmsg_(__global_state, "Neither of the frames # or # was recognized"
		" as a known reference frame. ", (ftnlen)72);
	errch_(__global_state, "#", from, (ftnlen)1, from_len);
	errch_(__global_state, "#", to, (ftnlen)1, to_len);
	sigerr_(__global_state, "SPICE(UNKNOWNFRAME)", (ftnlen)19);
    } else if (fcode == 0) {
	setmsg_(__global_state, "The frame # was not recognized as a known r"
		"eference frame. ", (ftnlen)59);
	errch_(__global_state, "#", from, (ftnlen)1, from_len);
	sigerr_(__global_state, "SPICE(UNKNOWNFRAME)", (ftnlen)19);
    } else if (tcode == 0) {
	setmsg_(__global_state, "The frame # was not recognized as a known r"
		"eference frame. ", (ftnlen)59);
	errch_(__global_state, "#", to, (ftnlen)1, to_len);
	sigerr_(__global_state, "SPICE(UNKNOWNFRAME)", (ftnlen)19);
    }
    chkout_(__global_state, "PXFORM", (ftnlen)6);
    return 0;
} /* pxform_ */

