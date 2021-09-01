/* tisbod.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern tisbod_init_t __tisbod_init;
static tisbod_state_t* get_tisbod_state(cspice_t* state) {
	if (!state->tisbod)
		state->tisbod = __cspice_allocate_module(sizeof(
	tisbod_state_t), &__tisbod_init, sizeof(__tisbod_init));
	return state->tisbod;

}

/* $Procedure      TISBOD ( Transformation, inertial state to bodyfixed ) */
/* Subroutine */ int tisbod_(cspice_t* __global_state, char *ref, integer *
	body, doublereal *et, doublereal *tsipm, ftnlen ref_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1;

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer i_dnnt(f2c_state_t*, doublereal *);
    double sin(doublereal), cos(doublereal), d_mod(f2c_state_t*, doublereal *,
	     doublereal *);

    /* Local variables */
    extern /* Subroutine */ int zzhsiadd_(cspice_t*, integer *, integer *, 
	    integer *, integer *, integer *, logical *);
    extern /* Subroutine */ int zzhsichk_(cspice_t*, integer *, integer *, 
	    integer *, integer *, integer *);
    extern integer zzbodbry_(cspice_t*, integer *);
    extern /* Subroutine */ int zzhsiini_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int zzpctrck_(cspice_t*, integer *, logical *);
    extern /* Subroutine */ int zzhsiavl_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int zzctruin_(cspice_t*, integer *);
    extern /* Subroutine */ int etcal_(cspice_t*, doublereal *, char *, 
	    ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int vpack_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *, doublereal *);
    extern /* Subroutine */ int moved_(cspice_t*, doublereal *, integer *, 
	    doublereal *);
    extern /* Subroutine */ int repmi_(cspice_t*, char *, char *, integer *, 
	    char *, ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    extern doublereal vdotg_(cspice_t*, doublereal *, doublereal *, integer *)
	    ;
    extern doublereal twopi_(cspice_t*);
    extern /* Subroutine */ int eul2xf_(cspice_t*, doublereal *, integer *, 
	    integer *, integer *, doublereal *);
    extern logical failed_(cspice_t*);
    extern logical bodfnd_(cspice_t*, integer *, char *, ftnlen);
    extern doublereal halfpi_(cspice_t*);
    extern /* Subroutine */ int pckmat_(cspice_t*, integer *, doublereal *, 
	    integer *, doublereal *, logical *);
    extern /* Subroutine */ int irfnum_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int dtpool_(cspice_t*, char *, logical *, integer 
	    *, char *, ftnlen, ftnlen);
    extern /* Subroutine */ int ccifrm_(cspice_t*, integer *, integer *, 
	    integer *, char *, integer *, logical *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int suffix_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int gdpool_(cspice_t*, char *, integer *, integer 
	    *, integer *, doublereal *, logical *, ftnlen);
    extern /* Subroutine */ int cleard_(cspice_t*, integer *, doublereal *);
    extern /* Subroutine */ int bodvcd_(cspice_t*, integer *, char *, integer 
	    *, integer *, doublereal *, ftnlen);
    extern /* Subroutine */ int irfrot_(cspice_t*, integer *, integer *, 
	    doublereal *);
    extern doublereal j2000_(cspice_t*);
    extern doublereal rpd_(cspice_t*);
    extern doublereal spd_(cspice_t*);
    extern /* Subroutine */ int mxm_(cspice_t*, doublereal *, doublereal *, 
	    doublereal *);

    /* Module state */
    tisbod_state_t* __state = get_tisbod_state(__global_state);
/* $ Abstract */

/*     Return a 6x6 matrix that transforms states in inertial */
/*     coordinates to states in body-equator-and-prime-meridian */
/*     coordinates. */

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

/*     PCK */
/*     NAIF_IDS */
/*     ROTATION */
/*     TIME */

/* $ Keywords */

/*     TRANSFORMATION */
/*     ROTATION */

/* $ Declarations */
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


/*     Include File:  SPICELIB Error Handling Parameters */

/*        errhnd.inc  Version 2    18-JUN-1997 (WLT) */

/*           The size of the long error message was */
/*           reduced from 25*80 to 23*80 so that it */
/*           will be accepted by the Microsoft Power Station */
/*           FORTRAN compiler which has an upper bound */
/*           of 1900 for the length of a character string. */

/*        errhnd.inc  Version 1    29-JUL-1997 (NJB) */



/*     Maximum length of the long error message: */


/*     Maximum length of the short error message: */


/*     End Include File:  SPICELIB Error Handling Parameters */

/* $ Abstract */

/*     The parameters below form an enumerated list of the recognized */
/*     frame types.  They are: INERTL, PCK, CK, TK, DYN.  The meanings */
/*     are outlined below. */

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

/*     INERTL      an inertial frame that is listed in the routine */
/*                 CHGIRF and that requires no external file to */
/*                 compute the transformation from or to any other */
/*                 inertial frame. */

/*     PCK         is a frame that is specified relative to some */
/*                 INERTL frame and that has an IAU model that */
/*                 may be retrieved from the PCK system via a call */
/*                 to the routine TISBOD. */

/*     CK          is a frame defined by a C-kernel. */

/*     TK          is a "text kernel" frame.  These frames are offset */
/*                 from their associated "relative" frames by a */
/*                 constant rotation. */

/*     DYN         is a "dynamic" frame.  These currently are */
/*                 parameterized, built-in frames where the full frame */
/*                 definition depends on parameters supplied via a */
/*                 frame kernel. */

/*     ALL         indicates any of the above classes. This parameter */
/*                 is used in APIs that fetch information about frames */
/*                 of a specified class. */


/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     W.L. Taber      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 4.0.0, 08-MAY-2012 (NJB) */

/*       The parameter ALL was added to support frame fetch APIs. */

/* -    SPICELIB Version 3.0.0, 28-MAY-2004 (NJB) */

/*       The parameter DYN was added to support the dynamic frame class. */

/* -    SPICELIB Version 2.0.0, 12-DEC-1996 (WLT) */

/*        Various unused frames types were removed and the */
/*        frame time TK was added. */

/* -    SPICELIB Version 1.0.0, 10-DEC-1995 (WLT) */

/* -& */

/*     End of INCLUDE file frmtyp.inc */

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
/*     REF        I   ID of inertial reference frame to transform from */
/*     BODY       I   ID code of body */
/*     ET         I   Epoch of transformation */
/*     TSIPM      O   Transformation (state), inertial to prime meridian */

/* $ Detailed_Input */

/*     REF         is the NAIF name for an inertial reference frame. */
/*                 Acceptable names include: */

/*                    Name       Description */
/*                    --------   -------------------------------- */
/*                    'J2000'    Earth mean equator, dynamical */
/*                               equinox of J2000 */

/*                    'B1950'    Earth mean equator, dynamical */
/*                               equinox of B1950 */

/*                    'FK4'      Fundamental Catalog (4) */

/*                    'DE-118'   JPL Developmental Ephemeris (118) */

/*                    'DE-96'    JPL Developmental Ephemeris ( 96) */

/*                    'DE-102'   JPL Developmental Ephemeris (102) */

/*                    'DE-108'   JPL Developmental Ephemeris (108) */

/*                    'DE-111'   JPL Developmental Ephemeris (111) */

/*                    'DE-114'   JPL Developmental Ephemeris (114) */

/*                    'DE-122'   JPL Developmental Ephemeris (122) */

/*                    'DE-125'   JPL Developmental Ephemeris (125) */

/*                    'DE-130'   JPL Developmental Ephemeris (130) */

/*                    'GALACTIC' Galactic System II */

/*                    'DE-200'   JPL Developmental Ephemeris (200) */

/*                    'DE-202'   JPL Developmental Ephemeris (202) */

/*                 (See the routine CHGIRF for a full list of names.) */

/*                 The output TIPM will give the transformation */
/*                 from this frame to the bodyfixed frame specified by */
/*                 BODY at the epoch specified by ET. */

/*     BODY        is the integer ID code of the body for which the */
/*                 state transformation matrix is requested. Bodies */
/*                 are numbered according to the standard NAIF */
/*                 numbering scheme. The numbering scheme is */
/*                 explained in the NAIF_IDS required reading file. */

/*     ET          is the epoch at which the state transformation */
/*                 matrix is requested. (This is typically the */
/*                 epoch of observation minus the one-way light time */
/*                 from the observer to the body at the epoch of */
/*                 observation.) */

/* $ Detailed_Output */

/*     TSIPM       is a 6x6 transformation matrix. It is used to */
/*                 transform states from inertial coordinates to body */
/*                 fixed (also called equator and prime meridian --- */
/*                 PM) coordinates. */

/*                 Given a state S in the inertial reference frame */
/*                 specified by REF, the corresponding bodyfixed state */
/*                 is given by the matrix vector product: */

/*                    TSIPM * S */

/*                 The X axis of the PM system is directed  to the */
/*                 intersection of the equator and prime meridian. */
/*                 The Z axis points along  the spin axis and points */
/*                 towards the same side of the invariable plane of */
/*                 the solar system as does earth's north pole. */

/*                 NOTE: The inverse of TSIPM is NOT its transpose. */
/*                       The matrix, TSIPM, has a structure as shown */
/*                       below: */

/*                             -            - */
/*                            |       :      | */
/*                            |   R   :  0   | */
/*                            | ......:......| */
/*                            |       :      | */
/*                            | dR_dt :  R   | */
/*                            |       :      | */
/*                             -            - */

/*                       where R is a time varying rotation matrix and */
/*                       dR_dt is its derivative. The inverse of this */
/*                       matrix is: */

/*                             -              - */
/*                            |     T  :       | */
/*                            |    R   :  0    | */
/*                            | .......:.......| */
/*                            |        :       | */
/*                            |      T :   T   | */
/*                            | dR_dt  :  R    | */
/*                            |        :       | */
/*                             -              - */

/*                       The SPICE routine INVSTM is available for */
/*                       producing this inverse. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If data required to define the body-fixed frame associated */
/*        with BODY are not found in the binary PCK system or the kernel */
/*        pool, the error SPICE(FRAMEDATANOTFOUND) is signaled. In */
/*        the case of IAU style body-fixed frames, the absence of */
/*        prime meridian polynomial data (which are required) is used */
/*        as an indicator of missing data. */

/*     2) If the test for exception (1) passes, but in fact requested */
/*        data are not available in the kernel pool, the error will be */
/*        signaled by routines in the call tree of this routine. */

/*     3) If the kernel pool does not contain all of the data required */
/*        to define the number of nutation precession angles */
/*        corresponding to the available nutation precession */
/*        coefficients, the error SPICE(INSUFFICIENTANGLES) is */
/*        signaled. */

/*     4) If the reference frame REF is not recognized, a routine */
/*        called by TISBOD will diagnose the condition and invoke the */
/*        SPICE error handling system. */

/*     5) If the specified body code BODY is not recognized, the */
/*        error is diagnosed by a routine called by TISBOD. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     The matrix for transforming inertial states to bodyfixed */
/*     states is the 6x6 matrix shown below as a block structured */
/*     matrix. */

/*                 -            - */
/*                |       :      | */
/*                | TIPM  :  0   | */
/*                | ......:......| */
/*                |       :      | */
/*                | DTIPM : TIPM | */
/*                |       :      | */
/*                 -            - */

/*     This can also be expressed in terms of Euler angles */
/*     PHI, DELTA and W. The transformation from inertial to */
/*     bodyfixed coordinates is represented in the SPICE kernel */
/*     pool as: */

/*            TIPM = [W] [DELTA] [PHI] */
/*                      3       1     3 */
/*     Thus */

/*           DTIPM = d[W] /dt [DELTA] [PHI] */
/*                       3           1     3 */

/*                 + [W] d[DELTA] /dt [PHI] */
/*                      3             1     3 */

/*                 + [W] [DELTA] d[PHI] /dt */
/*                      3       1          3 */


/*     If a binary PCK file record can be used for the time and */
/*     body requested, it will be used. The most recently loaded */
/*     binary PCK file has first priority, followed by previously */
/*     loaded binary PCK files in backward time order. If no */
/*     binary PCK file has been loaded, the text P_constants */
/*     kernel file is used. */

/*     If there is only text PCK kernel information, it is */
/*     expressed in terms of RA, DEC and W (same W as above), where */

/*        RA    = PHI - HALFPI() */
/*        DEC   = HALFPI() - DELTA */

/*     The angles RA, DEC, and W are defined as follows in the */
/*     text PCK file: */

/*                                         2      ____ */
/*                                    RA2*t       \ */
/*            RA  = RA0  + RA1*t/T  + ------   +  /     a  sin theta */
/*                                       2        ----   i          i */
/*                                      T           i */

/*                                          2     ____ */
/*                                    DEC2*t      \ */
/*            DEC = DEC0 + DEC1*t/T + -------  +  /    d  cos theta */
/*                                        2       ----  i          i */
/*                                       T          i */


/*                                        2      ____ */
/*                                    W2*t       \ */
/*            W   = W0   + W1*t/d   + -----   +  /     w  sin theta */
/*                                       2       ----   i          i */
/*                                      d          i */


/*     where: */

/*            d = seconds/day */

/*            T = seconds/Julian century */

/*            a , d , and w  arrays apply to satellites only. */
/*             i   i       i */

/*            theta  = THETA0(i) + THETA1(i)*t/T are specific to each */
/*                 i */

/*            planet. */


/*     These angles -- typically nodal rates -- vary in number and */
/*     definition from one planetary system to the next. */

/*     Thus */
/*                                         ____ */
/*                             2*RA2*t     \ */
/*          dRA/dt  = RA1/T  + -------   + /   a THETA1(i)/T cos theta */
/*                                 2       ---- i                     i */
/*                                T          i */

/*                                         ____ */
/*                             2*DEC2*t    \ */
/*          dDEC/dt = DEC1/T + --------  - /    d  THETA1(i)/T sin theta */
/*                                 2       ----  i                      i */
/*                                T          i */

/*                                         ____ */
/*                             2*W2*t      \ */
/*          dW/dt   = W1/d   + ------    + /    w  THETA1(i)/T cos theta */
/*                                 2       ----  i                      i */
/*                                d          i */


/* $ Examples */

/*     Note that the data needed to compute the output state transition */
/*     matrix must have been made available to your program by having */
/*     loaded an appropriate binary or text PCK file via FURNSH. */

/*     Example 1. */

/*     In the following code fragment, TISBOD is used to transform */
/*     a state in J2000 inertial coordinates to a state in bodyfixed */
/*     coordinates. */

/*     The 6-vectors EULANG represents the inertial state (position and */
/*     velocity) of an object with respect to the center of the body */
/*     at time ET. */

/*     C */
/*     C     First load the kernel pool. */
/*     C */
/*           CALL FURNSH ( 'PLANETARY_CONSTANTS.KER' ) */

/*     C */
/*     C     Next get the transformation and its derivative. */
/*     C */
/*           CALL TISBOD ( 'J2000', BODY, ET, TSIPM ) */

/*     C */
/*     C     Convert position to bodyfixed coordinates. */
/*     C */
/*           CALL MXVG    ( TSIPM, EULANG, 6, 6, BDSTAT ) */


/*     Example 2. */

/*     In the example below, TISBOD is used to compute */
/*     the angular velocity vector (with respect to an inertial frame) */
/*     of the specified body at time ET. */

/*     C */
/*     C     First get the state transformation matrix. */
/*     C */
/*           CALL TISBOD ( BODY,  ET,   TSIPM ) */

/*     C */
/*     C     This matrix has the form: */
/*     C */
/*     C           -            - */
/*     C          |       :      | */
/*     C          | TIPM  :  0   | */
/*     C          | ......:......| */
/*     C          |       :      | */
/*     C          | DTIPM : TIPM | */
/*     C          |       :      | */
/*     C           -            - */
/*     C */
/*     C     We extract TIPM and DTIPM */
/*     C */

/*           DO  I = 1,3 */
/*              DO  J = 1,3 */

/*                 TIPM  ( I, J ) = TSIPM ( I,   J ) */
/*                 DTIPM ( I, J ) = TSIPM ( I+3, J ) */

/*              END DO */
/*           END DO */

/*     C */
/*     C     The transpose of TIPM and DTIPM, (TPMI and DTPMI), give */
/*     C     the transformation from bodyfixed coordinates to inertial */
/*     C     coordinates. */
/*     C */
/*     C     Here is a fact about the relationship between angular */
/*     C     velocity associated with a time varying rotation matrix */
/*     C     that gives the orientation of a body with respect to */
/*     C     an inertial frame. */
/*     C */
/*     C        The angular velocity vector can be read from the off */
/*     C        diagonal components of the matrix product: */
/*     C */
/*     C                                t */
/*     C        OMEGA =     DTPMI * TPMI */
/*     C */
/*     C                         t */
/*     C              =     DTIPM * TIPM */
/*     C */
/*     C        the components of the angular velocity V will appear */
/*     C        in this matrix as: */
/*     C */
/*     C             _                   _ */
/*     C            |                     | */
/*     C            |   0    -V(3)  V(2)  | */
/*     C            |                     | */
/*     C            |  V(3)    0   -V(1)  | */
/*     C            |                     | */
/*     C            | -V(2)   V(1)   0    | */
/*     C            |_                   _| */
/*     C */
/*     C */
/*           CALL MTXM ( DTIPM, TIPM, OMEGA ) */

/*           V(1) = OMEGA (3,2) */
/*           V(2) = OMEGA (1,3) */
/*           V(3) = OMEGA (2,1) */

/* $ Restrictions */

/*     The kernel pool must be loaded with the appropriate coefficients */
/*     (from the P_constants kernel or binary PCK file) prior to */
/*     calling this routine. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N. J. Bachman   (JPL) */
/*     B. V. Semenov   (JPL) */
/*     W. L. Taber     (JPL) */
/*     K. S. Zukor     (JPL) */

/* $ Version */

/* -    SPICELIB Version 4.5.0, 26-JUL-2016 (BVS) */

/*        The routine was updated to be more efficient by using a hash */
/*        and buffers so save text PCK data instead of doing kernel POOL */
/*        look-ups over an over again. The routine now checks the POOL */
/*        state counter and dumps all buffered data if it changes. */

/*        BUG FIX: changed available room in the BODVCD call */
/*        fetching 'NUT_PREC_ANGLES' from MAXANG to MAXANG*2. */

/* -    SPICELIB Version 4.4.0, 01-FEB-2008 (NJB) */

/*        The routine was updated to improve the error messages created */
/*        when required PCK data are not found. Now in most cases the */
/*        messages are created locally rather than by the kernel pool */
/*        access routines. In particular missing binary PCK data will */
/*        be indicated with a reasonable error message. */

/* -    SPICELIB Version 4.3.0, 13-DEC-2005 (NJB) */

/*        Bug fix:  previous update introduced bug in state */
/*        transformation when REF was unequal to PCK native frame. */

/* -    SPICELIB Version 4.2.0, 23-OCT-2005 (NJB) */

/*        Re-wrote portions of algorithm to simplify source code. */
/*        Updated to remove non-standard use of duplicate arguments */
/*        in MXM and VADDG calls. */

/*        Replaced calls to ZZBODVCD with calls to BODVCD. */

/* -    SPICELIB Version 4.1.0, 05-JAN-2005 (NJB) */

/*        Tests of routine FAILED() were added. */

/* -     SPICELIB Version 4.0.0, 12-FEB-2004 (NJB) */

/*         Code has been updated to support satellite ID codes in the */
/*         range 10000 to 99999 and to allow nutation precession angles */
/*         to be associated with any object. */

/*         Implementation changes were made to improve robustness */
/*         of the code. */

/* -     SPICELIB Version 3.3.0, 29-MAR-1995 (WLT) */

/*         Properly initialized the variable NPAIRS. */

/* -     SPICELIB Version 3.2.0, 22-MAR-1995 (KSZ) */

/*         Changed to call PCKMAT rather than PCKEUL. */

/* -     SPICELIB Version 3.1.0, 18-OCT-1994 (KSZ) */

/*         Fixed bug which incorrectly modded DW by two pi. */

/* -     SPICELIB Version 3.0.0, 10-MAR-1994 (KSZ) */

/*         Changed to look for binary PCK file, and used this */
/*         to find Euler angles, if such data has been loaded. */

/* -     SPICELIB Version 2.0.1, 10-MAR-1992 (WLT) */

/*         Comment section for permuted index source lines was added */
/*         following the header. */

/* -     SPICELIB Version 2.0.0, 04-SEP-1991 (NJB) */

/*         Updated to handle P_constants referenced to different epochs */
/*         and inertial reference frames. */

/*         $Required_Reading and $Literature_References sections were */
/*         updated. */

/* -     SPICELIB Version 1.0.0, 05-NOV-1990 (WLT) */

/* -& */
/* $ Index_Entries */

/*     transformation from inertial state to bodyfixed */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 4.5.0, 02-MAR-2016 (BVS) */

/*        The routine was updated to be more efficient by using a hash */
/*        and buffers so save text PCK data instead of doing kernel POOL */
/*        look-ups over an over again. The routine now checks the POOL */
/*        state counter and dumps all buffered data if it changes. */

/* -    SPICELIB Version 4.2.0, 06-SEP-2005 (NJB) */

/*        Re-wrote portions of algorithm to simplify source code. */
/*        The routine now takes advantage of EUL2XF, which wasn't */
/*        available when the first version of this routine was written. */

/*        Updated to remove non-standard use of duplicate arguments */
/*        in MXM and VADDG calls. */

/*        Replaced calls to ZZBODVCD with calls to BODVCD. */

/* -    SPICELIB Version 1.1.0, 05-JAN-2005 (NJB) */

/*        Tests of routine FAILED() were added. The new checks */
/*        are intended to prevent arithmetic operations from */
/*        being performed with uninitialized or invalid data. */

/* -     SPICELIB Version 4.0.0, 27-JAN-2004 (NJB) */

/*         Code has been updated to support satellite ID codes in the */
/*         range 10000 to 99999 and to allow nutation precession angles */
/*         to be associated with any object. */

/*         Calls to deprecated kernel pool access routine RTPOOL */
/*         were replaced by calls to GDPOOL. */

/*         Calls to BODVAR have been replaced with calls to */
/*         ZZBODVCD. */

/* -     SPICELIB Version 3.3.0, 29-MAR-1995 (WLT) */

/*        The variable NPAIRS is now initialized */
/*        at the same point as NA, NTHETA, ND, and NW to be */
/*        zero. This prevents the routine from performing */
/*        needless calculations for planets and avoids possible */
/*        floating point exceptions. */

/* -     SPICELIB Version 3.2.0, 22-MAR-1995 (KSZ) */

/*        TISBOD now gets the TSIPM matrix from PCKMAT. */
/*        Reference frame calculation moved to end. */

/* -     SPICELIB Version 3.0.1, 07-OCT-1994 (KSZ) */

/*        TISBOD bug which mistakenly moded DW by 2PI */
/*        was removed. */

/* -     SPICELIB Version 3.0.0, 10-MAR-1994 (KSZ) */

/*        TISBOD now uses new software to check for the */
/*        existence of binary PCK files, search the for */
/*        data corresponding to the requested body and time, */
/*        and return the appropriate Euler angles. Otherwise */
/*        the code calculates the Euler angles from the */
/*        P_constants kernel file. */

/* -     SPICELIB Version 2.0.0, 04-SEP-1991 (NJB) */

/*         Updated to handle P_constants referenced to different epochs */
/*         and inertial reference frames. */

/*         TISBOD now checks the kernel pool for presence of the */
/*         variables */

/*            BODY#_CONSTANTS_REF_FRAME */

/*         and */

/*            BODY#_CONSTANTS_JED_EPOCH */

/*         where # is the NAIF integer code of the barycenter of a */
/*         planetary system or of a body other than a planet or */
/*         satellite. If either or both of these variables are */
/*         present, the P_constants for BODY are presumed to be */
/*         referenced to the specified inertial frame or epoch. */
/*         If the epoch of the constants is not J2000, the input */
/*         time ET is converted to seconds past the reference epoch. */
/*         If the frame of the constants is not the frame specified */
/*         by REF, the rotation from the P_constants' frame to */
/*         body-fixed coordinates is transformed to the rotation from */
/*         the requested frame to body-fixed coordinates. The same */
/*         transformation is applied to the derivative of this */
/*         rotation. */

/*         Due to the prescience of the original author, the code */
/*         was already prepared to handle the possibility of */
/*         specification of a P_constants inertial reference frame via */
/*         kernel pool variables. */


/*         Also, the $Required_Reading and $Literature_References */
/*         sections were updated. The SPK required reading has been */
/*         deleted from the $Literature_References section, and the */
/*         NAIF_IDS, KERNEL, and TIME Required Reading files have */
/*         been added in the $Required_Reading section. */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     POOL state counter. */


/*     ID-based hash for text PCK data. KIDLST, KIDPOL, and KIDIDS */
/*     provide the index in the body PCK data arrays at which the data */
/*     of the body with a given ID are stored. */


/*     Saved variables */

/*     Because we need to save almost everything, we save everything */
/*     rather than taking a chance and accidentally leaving something */
/*     off the list. */


/*     Initial values */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "TISBOD", (ftnlen)6);
    }

/*     Perform any needed first pass initializations. */

    if (__state->first) {

/*        Initialize POOL state counter to the user value. */

	zzctruin_(__global_state, __state->pulctr);

/*        Initialize kernel POOL frame hashes. */

	zzhsiini_(__global_state, &__state->c__157, __state->bidlst, 
		__state->bidpol);

/*        Get the code for the J2000 frame. */

	irfnum_(__global_state, "J2000", &__state->j2code, (ftnlen)5);

/*        Set seconds per day and per century. */

	__state->d__ = spd_(__global_state);
	__state->t = __state->d__ * 36525.;
	__state->first = FALSE_;
    }
    irfnum_(__global_state, ref, &__state->reqref, ref_len);

/*     Get state transformation matrix from high precision PCK file, if */
/*     available. */

    pckmat_(__global_state, body, et, &__state->pcref, tsipm, &__state->found)
	    ;
    if (! __state->found) {

/*        The data for the frame of interest are not available in a */
/*        loaded binary PCK file. This is not an error: the data may be */
/*        present in the kernel pool. */

/*        Check the POOL counter. If it changed, dump all buffered */
/*        constants data. */

	zzpctrck_(__global_state, __state->pulctr, &__state->update);
	if (__state->update) {
	    zzhsiini_(__global_state, &__state->c__157, __state->bidlst, 
		    __state->bidpol);
	}

/*        Check if we have data for this body in our buffers. */

	zzhsichk_(__global_state, __state->bidlst, __state->bidpol, 
		__state->bidids, body, &__state->at);
	if (__state->at != 0) {

/*           Set PCREF as it is used after the text PCK "IF". */

	    __state->pcref = __state->bpcref[(i__1 = __state->at - 1) < 157 &&
		     0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "bpcref",
		     i__1, "tisbod_", (ftnlen)867)];
	} else {

/*           Conduct a non-error-signaling check for the presence of a */
/*           kernel variable that is required to implement an IAU style */
/*           body-fixed reference frame. If the data aren't available, */
/*           we don't want BODVCD to signal a SPICE(KERNELVARNOTFOUND) */
/*           error; we want to issue the error signal locally, with a */
/*           better error message. */

	    s_copy(&__global_state->f2c, __state->item, "BODY#_PM", (ftnlen)
		    32, (ftnlen)8);
	    repmi_(__global_state, __state->item, "#", body, __state->item, (
		    ftnlen)32, (ftnlen)1, (ftnlen)32);
	    dtpool_(__global_state, __state->item, &__state->found, &
		    __state->nw, __state->dtype, (ftnlen)32, (ftnlen)1);
	    if (! __state->found) {

/*              Now we do have an error. */

/*              We don't have the data we'll need to produced the */
/*              requested state transformation matrix. In order to */
/*              create an error message understandable to the user, */
/*              find, if possible, the name of the reference frame */
/*              associated with the input body. Note that the body is */
/*              really identified by a PCK frame class ID code, though */
/*              most of the documentation just calls it a body ID code. */

		ccifrm_(__global_state, &__state->c__2, body, &
			__state->frcode, __state->fixfrm, &__state->cent, &
			__state->found, (ftnlen)32);
		etcal_(__global_state, et, __state->timstr, (ftnlen)35);
		s_copy(&__global_state->f2c, __state->errmsg, "PCK data requ"
			"ired to compute the orientation of the # # for epoch"
			" # TDB were not found. If these data were to be prov"
			"ided by a binary PCK file, then it is possible that "
			"the PCK file does not have coverage for the specifie"
			"d body-fixed frame at the time of interest. If the d"
			"ata were to be provided by a text PCK file, then pos"
			"sibly the file does not contain data for the specifi"
			"ed body-fixed frame. In either case it is possible t"
			"hat a required PCK file was not loaded at all.", (
			ftnlen)1840, (ftnlen)475);

/*              Fill in the variable data in the error message. */

		if (__state->found) {

/*                 The frame system knows the name of the body-fixed */
/*                 frame. */

		    setmsg_(__global_state, __state->errmsg, (ftnlen)1840);
		    errch_(__global_state, "#", "body-fixed frame", (ftnlen)1,
			     (ftnlen)16);
		    errch_(__global_state, "#", __state->fixfrm, (ftnlen)1, (
			    ftnlen)32);
		    errch_(__global_state, "#", __state->timstr, (ftnlen)1, (
			    ftnlen)35);
		} else {

/*                 The frame system doesn't know the name of the */
/*                 body-fixed frame, most likely due to a missing */
/*                 frame kernel. */

		    suffix_(__global_state, "#", &__state->c__1, 
			    __state->errmsg, (ftnlen)1, (ftnlen)1840);
		    setmsg_(__global_state, __state->errmsg, (ftnlen)1840);
		    errch_(__global_state, "#", "body-fixed frame associated"
			    " with the ID code", (ftnlen)1, (ftnlen)44);
		    errint_(__global_state, "#", body, (ftnlen)1);
		    errch_(__global_state, "#", __state->timstr, (ftnlen)1, (
			    ftnlen)35);
		    errch_(__global_state, "#", "Also, a frame kernel defini"
			    "ng the body-fixed frame associated with body # m"
			    "ay need to be loaded.", (ftnlen)1, (ftnlen)96);
		    errint_(__global_state, "#", body, (ftnlen)1);
		}
		sigerr_(__global_state, "SPICE(FRAMEDATANOTFOUND)", (ftnlen)
			24);
		chkout_(__global_state, "TISBOD", (ftnlen)6);
		return 0;
	    }

/*           Find the body code used to label the reference frame and */
/*           epoch specifiers for the orientation constants for BODY. */

/*           For planetary systems, the reference frame and epoch for */
/*           the orientation constants is associated with the system */
/*           barycenter, not with individual bodies in the system. For */
/*           any other bodies, (the Sun or asteroids, for example) the */
/*           body's own code is used as the label. */

	    __state->refid = zzbodbry_(__global_state, body);

/*           Look up the epoch of the constants. The epoch is specified */
/*           as a Julian ephemeris date. The epoch defaults to J2000. */

	    s_copy(&__global_state->f2c, __state->item, "BODY#_CONSTANTS_JED"
		    "_EPOCH", (ftnlen)32, (ftnlen)25);
	    repmi_(__global_state, __state->item, "#", &__state->refid, 
		    __state->item, (ftnlen)32, (ftnlen)1, (ftnlen)32);
	    gdpool_(__global_state, __state->item, &__state->c__1, &
		    __state->c__1, &__state->dim, &__state->pckepc, &
		    __state->found, (ftnlen)32);
	    if (! __state->found) {
		__state->pckepc = j2000_(__global_state);
	    }

/*           Look up the reference frame of the constants. The reference */
/*           frame is specified by a code recognized by CHGIRF. The */
/*           default frame is J2000, symbolized by the code J2CODE. */

	    s_copy(&__global_state->f2c, __state->item, "BODY#_CONSTANTS_REF"
		    "_FRAME", (ftnlen)32, (ftnlen)25);
	    repmi_(__global_state, __state->item, "#", &__state->refid, 
		    __state->item, (ftnlen)32, (ftnlen)1, (ftnlen)32);
	    gdpool_(__global_state, __state->item, &__state->c__1, &
		    __state->c__1, &__state->dim, &__state->pckref, &
		    __state->found, (ftnlen)32);
	    if (__state->found) {
		__state->pcref = i_dnnt(&__global_state->f2c, &
			__state->pckref);
	    } else {
		__state->pcref = __state->j2code;
	    }

/*           Whatever the body, it has quadratic time polynomials for */
/*           the RA and Dec of the pole, and for the rotation of the */
/*           Prime Meridian. */

	    s_copy(&__global_state->f2c, __state->item, "POLE_RA", (ftnlen)32,
		     (ftnlen)7);
	    cleard_(__global_state, &__state->c__3, __state->rcoef);
	    bodvcd_(__global_state, body, __state->item, &__state->c__3, &
		    __state->na, __state->rcoef, (ftnlen)32);
	    if (failed_(__global_state)) {
		chkout_(__global_state, "TISBOD", (ftnlen)6);
		return 0;
	    }
	    s_copy(&__global_state->f2c, __state->item, "POLE_DEC", (ftnlen)
		    32, (ftnlen)8);
	    cleard_(__global_state, &__state->c__3, __state->dcoef);
	    bodvcd_(__global_state, body, __state->item, &__state->c__3, &
		    __state->nd, __state->dcoef, (ftnlen)32);
	    if (failed_(__global_state)) {
		chkout_(__global_state, "TISBOD", (ftnlen)6);
		return 0;
	    }
	    s_copy(&__global_state->f2c, __state->item, "PM", (ftnlen)32, (
		    ftnlen)2);
	    cleard_(__global_state, &__state->c__3, __state->wcoef);
	    bodvcd_(__global_state, body, __state->item, &__state->c__3, &
		    __state->nw, __state->wcoef, (ftnlen)32);
	    if (failed_(__global_state)) {
		chkout_(__global_state, "TISBOD", (ftnlen)6);
		return 0;
	    }

/*           If the body is a satellite, there may be additional */
/*           nutation and libration (THETA) terms. */

	    __state->ntheta = 0;
	    __state->npairs = 0;
	    __state->na = 0;
	    __state->nd = 0;
	    __state->nw = 0;
	    s_copy(&__global_state->f2c, __state->item, "NUT_PREC_ANGLES", (
		    ftnlen)32, (ftnlen)15);

/*           There is something a bit obscure going on below. We are */
/*           passing a two dimensional array ( TCOEF(2, MAXANG) ). But */
/*           BODVCD is expecting a 1- dimensional array. BODVCD loads */
/*           the array TCOEF in the following order */

/*              TCOEF(1,1), TCOEF(2,1), TCOEF(1,2), TCOEF(2,2),   ... */

/*           The NTHETA that comes back is the total number of items */
/*           loaded, but we will need the actual limit on the second */
/*           dimension. That is --- NTHETA / 2. */

	    if (bodfnd_(__global_state, &__state->refid, __state->item, (
		    ftnlen)32)) {
		bodvcd_(__global_state, &__state->refid, __state->item, &
			__state->c__200, &__state->ntheta, __state->tcoef, (
			ftnlen)32);
		if (failed_(__global_state)) {
		    chkout_(__global_state, "TISBOD", (ftnlen)6);
		    return 0;
		}
		__state->npairs = __state->ntheta / 2;
	    }

/*           Look up the right ascension nutations in the precession of */
/*           the pole. NA is the number of Ascension coefficients. AC */
/*           are the Ascension coefficients. */

	    s_copy(&__global_state->f2c, __state->item, "NUT_PREC_RA", (
		    ftnlen)32, (ftnlen)11);
	    if (bodfnd_(__global_state, body, __state->item, (ftnlen)32)) {
		bodvcd_(__global_state, body, __state->item, &__state->c__100,
			 &__state->na, __state->ac, (ftnlen)32);
		if (failed_(__global_state)) {
		    chkout_(__global_state, "TISBOD", (ftnlen)6);
		    return 0;
		}
	    }

/*           Look up the declination nutations in the precession of the */
/*           pole. ND is the number of Declination coefficients. DC are */
/*           the Declination coefficients. */

	    s_copy(&__global_state->f2c, __state->item, "NUT_PREC_DEC", (
		    ftnlen)32, (ftnlen)12);
	    if (bodfnd_(__global_state, body, __state->item, (ftnlen)32)) {
		bodvcd_(__global_state, body, __state->item, &__state->c__100,
			 &__state->nd, __state->dc, (ftnlen)32);
		if (failed_(__global_state)) {
		    chkout_(__global_state, "TISBOD", (ftnlen)6);
		    return 0;
		}
	    }

/*           Finally look up the prime meridian nutations. NW is the */
/*           number of coefficients. WC is the array of coefficients. */

	    s_copy(&__global_state->f2c, __state->item, "NUT_PREC_PM", (
		    ftnlen)32, (ftnlen)11);
	    if (bodfnd_(__global_state, body, __state->item, (ftnlen)32)) {
		bodvcd_(__global_state, body, __state->item, &__state->c__100,
			 &__state->nw, __state->wc, (ftnlen)32);
		if (failed_(__global_state)) {
		    chkout_(__global_state, "TISBOD", (ftnlen)6);
		    return 0;
		}
	    }

/*           The number of coefficients returned had better not be */
/*           bigger than the number of angles we are going to compute. */
/*           If it is we simply signal an error and bag it, for sure. */

/* Computing MAX */
	    i__1 = max(__state->na,__state->nd);
	    if (max(i__1,__state->nw) > __state->npairs) {
		setmsg_(__global_state, "Insufficient number of nutation/pre"
			"cession angles for body * at time #.", (ftnlen)71);
		errint_(__global_state, "*", body, (ftnlen)1);
		errdp_(__global_state, "#", et, (ftnlen)1);
		sigerr_(__global_state, "SPICE(INSUFFICIENTANGLES)", (ftnlen)
			25);
		chkout_(__global_state, "TISBOD", (ftnlen)6);
		return 0;
	    }

/*           We succeeded to fetch all data for this body. Save it in */
/*           the buffers. First check if there is room. If not, dump the */
/*           buffers to make room. */

	    zzhsiavl_(__global_state, __state->bidpol, &__state->avail);
	    if (__state->avail <= 0) {
		zzhsiini_(__global_state, &__state->c__157, __state->bidlst, 
			__state->bidpol);
	    }

/*           Add this body to the hash and save its data in the buffers. */

	    zzhsiadd_(__global_state, __state->bidlst, __state->bidpol, 
		    __state->bidids, body, &__state->at, &__state->new__);
	    __state->bpckep[(i__1 = __state->at - 1) < 157 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "bpckep", i__1, "tis"
		    "bod_", (ftnlen)1147)] = __state->pckepc;
	    __state->bpcref[(i__1 = __state->at - 1) < 157 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "bpcref", i__1, "tis"
		    "bod_", (ftnlen)1148)] = __state->pcref;
	    __state->bnpair[(i__1 = __state->at - 1) < 157 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "bnpair", i__1, "tis"
		    "bod_", (ftnlen)1149)] = __state->npairs;
	    __state->bna[(i__1 = __state->at - 1) < 157 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "bna", i__1, "tisbod_", (
		    ftnlen)1150)] = __state->na;
	    __state->bnd[(i__1 = __state->at - 1) < 157 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "bnd", i__1, "tisbod_", (
		    ftnlen)1151)] = __state->nd;
	    __state->bnw[(i__1 = __state->at - 1) < 157 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "bnw", i__1, "tisbod_", (
		    ftnlen)1152)] = __state->nw;
	    moved_(__global_state, __state->rcoef, &__state->c__3, &
		    __state->brcoef[(i__1 = __state->at * 3 - 3) < 471 && 0 <=
		     i__1 ? i__1 : s_rnge(&__global_state->f2c, "brcoef", 
		    i__1, "tisbod_", (ftnlen)1154)]);
	    moved_(__global_state, __state->dcoef, &__state->c__3, &
		    __state->bdcoef[(i__1 = __state->at * 3 - 3) < 471 && 0 <=
		     i__1 ? i__1 : s_rnge(&__global_state->f2c, "bdcoef", 
		    i__1, "tisbod_", (ftnlen)1155)]);
	    moved_(__global_state, __state->wcoef, &__state->c__3, &
		    __state->bwcoef[(i__1 = __state->at * 3 - 3) < 471 && 0 <=
		     i__1 ? i__1 : s_rnge(&__global_state->f2c, "bwcoef", 
		    i__1, "tisbod_", (ftnlen)1156)]);
	    moved_(__global_state, __state->tcoef, &__state->c__200, &
		    __state->btcoef[(i__1 = (__state->at * 100 + 1 << 1) - 
		    202) < 31400 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "btcoef", i__1, "tisbod_", (ftnlen)
		    1157)]);
	    moved_(__global_state, __state->ac, &__state->c__100, &
		    __state->bac[(i__1 = __state->at * 100 - 100) < 15700 && 
		    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "bac", 
		    i__1, "tisbod_", (ftnlen)1158)]);
	    moved_(__global_state, __state->dc, &__state->c__100, &
		    __state->bdc[(i__1 = __state->at * 100 - 100) < 15700 && 
		    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "bdc", 
		    i__1, "tisbod_", (ftnlen)1159)]);
	    moved_(__global_state, __state->wc, &__state->c__100, &
		    __state->bwc[(i__1 = __state->at * 100 - 100) < 15700 && 
		    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "bwc", 
		    i__1, "tisbod_", (ftnlen)1160)]);
	}

/*        The reference epoch in the PCK is given as JED. Convert to */
/*        ephemeris seconds past J2000. Then convert the input ET to */
/*        seconds past the reference epoch. */

	__state->tmpepc = spd_(__global_state) * (__state->bpckep[(i__1 = 
		__state->at - 1) < 157 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "bpckep", i__1, "tisbod_", (ftnlen)1169)]
		 - j2000_(__global_state));
	__state->epoch = *et - __state->tmpepc;

/*        Evaluate the time polynomials and their derivatives w.r.t. */
/*        EPOCH at EPOCH. */

/*        Evaluate the time polynomials at EPOCH. */

	__state->ra = __state->brcoef[(i__1 = __state->at * 3 - 3) < 471 && 0 
		<= i__1 ? i__1 : s_rnge(&__global_state->f2c, "brcoef", i__1, 
		"tisbod_", (ftnlen)1178)] + __state->epoch / __state->t * (
		__state->brcoef[(i__2 = __state->at * 3 - 2) < 471 && 0 <= 
		i__2 ? i__2 : s_rnge(&__global_state->f2c, "brcoef", i__2, 
		"tisbod_", (ftnlen)1178)] + __state->epoch / __state->t * 
		__state->brcoef[(i__3 = __state->at * 3 - 1) < 471 && 0 <= 
		i__3 ? i__3 : s_rnge(&__global_state->f2c, "brcoef", i__3, 
		"tisbod_", (ftnlen)1178)]);
	__state->dec = __state->bdcoef[(i__1 = __state->at * 3 - 3) < 471 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "bdcoef", 
		i__1, "tisbod_", (ftnlen)1180)] + __state->epoch / __state->t 
		* (__state->bdcoef[(i__2 = __state->at * 3 - 2) < 471 && 0 <= 
		i__2 ? i__2 : s_rnge(&__global_state->f2c, "bdcoef", i__2, 
		"tisbod_", (ftnlen)1180)] + __state->epoch / __state->t * 
		__state->bdcoef[(i__3 = __state->at * 3 - 1) < 471 && 0 <= 
		i__3 ? i__3 : s_rnge(&__global_state->f2c, "bdcoef", i__3, 
		"tisbod_", (ftnlen)1180)]);
	__state->w = __state->bwcoef[(i__1 = __state->at * 3 - 3) < 471 && 0 
		<= i__1 ? i__1 : s_rnge(&__global_state->f2c, "bwcoef", i__1, 
		"tisbod_", (ftnlen)1182)] + __state->epoch / __state->d__ * (
		__state->bwcoef[(i__2 = __state->at * 3 - 2) < 471 && 0 <= 
		i__2 ? i__2 : s_rnge(&__global_state->f2c, "bwcoef", i__2, 
		"tisbod_", (ftnlen)1182)] + __state->epoch / __state->d__ * 
		__state->bwcoef[(i__3 = __state->at * 3 - 1) < 471 && 0 <= 
		i__3 ? i__3 : s_rnge(&__global_state->f2c, "bwcoef", i__3, 
		"tisbod_", (ftnlen)1182)]);
	__state->dra = (__state->brcoef[(i__1 = __state->at * 3 - 2) < 471 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "brcoef", 
		i__1, "tisbod_", (ftnlen)1185)] + __state->epoch / __state->t 
		* 2. * __state->brcoef[(i__2 = __state->at * 3 - 1) < 471 && 
		0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "brcoef", 
		i__2, "tisbod_", (ftnlen)1185)]) / __state->t;
	__state->ddec = (__state->bdcoef[(i__1 = __state->at * 3 - 2) < 471 &&
		 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "bdcoef", 
		i__1, "tisbod_", (ftnlen)1186)] + __state->epoch / __state->t 
		* 2. * __state->bdcoef[(i__2 = __state->at * 3 - 1) < 471 && 
		0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "bdcoef", 
		i__2, "tisbod_", (ftnlen)1186)]) / __state->t;
	__state->dw = (__state->bwcoef[(i__1 = __state->at * 3 - 2) < 471 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "bwcoef", 
		i__1, "tisbod_", (ftnlen)1187)] + __state->epoch / 
		__state->d__ * 2. * __state->bwcoef[(i__2 = __state->at * 3 - 
		1) < 471 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		"bwcoef", i__2, "tisbod_", (ftnlen)1187)]) / __state->d__;

/*        Compute the nutations and librations (and their derivatives) */
/*        as appropriate. */

	i__2 = __state->bnpair[(i__1 = __state->at - 1) < 157 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "bnpair", i__1, "tisbod_",
		 (ftnlen)1194)];
	for (__state->i__ = 1; __state->i__ <= i__2; ++__state->i__) {
	    __state->theta = (__state->btcoef[(i__1 = (__state->i__ + 
		    __state->at * 100 << 1) - 202) < 31400 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "btcoef", i__1, "tis"
		    "bod_", (ftnlen)1196)] + __state->epoch / __state->t * 
		    __state->btcoef[(i__3 = (__state->i__ + __state->at * 100 
		    << 1) - 201) < 31400 && 0 <= i__3 ? i__3 : s_rnge(&
		    __global_state->f2c, "btcoef", i__3, "tisbod_", (ftnlen)
		    1196)]) * rpd_(__global_state);
	    __state->dtheta = __state->btcoef[(i__1 = (__state->i__ + 
		    __state->at * 100 << 1) - 201) < 31400 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "btcoef", i__1, "tis"
		    "bod_", (ftnlen)1198)] / __state->t * rpd_(__global_state);
	    __state->sintmp = sin(__state->theta);
	    __state->costmp = cos(__state->theta);
	    __state->sinth[(i__1 = __state->i__ - 1) < 100 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "sinth", i__1, "tisb"
		    "od_", (ftnlen)1203)] = __state->sintmp;
	    __state->costh[(i__1 = __state->i__ - 1) < 100 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "costh", i__1, "tisb"
		    "od_", (ftnlen)1204)] = __state->costmp;
	    __state->dsinth[(i__1 = __state->i__ - 1) < 100 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "dsinth", i__1, "tis"
		    "bod_", (ftnlen)1205)] = __state->costmp * __state->dtheta;
	    __state->dcosth[(i__1 = __state->i__ - 1) < 100 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "dcosth", i__1, "tis"
		    "bod_", (ftnlen)1206)] = -__state->sintmp * 
		    __state->dtheta;
	}

/*        Adjust RA, DEC, W and their derivatives by the librations */
/*        and nutations. */

	__state->ra += vdotg_(__global_state, &__state->bac[(i__2 = 
		__state->at * 100 - 100) < 15700 && 0 <= i__2 ? i__2 : s_rnge(
		&__global_state->f2c, "bac", i__2, "tisbod_", (ftnlen)1214)], 
		__state->sinth, &__state->bna[(i__1 = __state->at - 1) < 157 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "bna", 
		i__1, "tisbod_", (ftnlen)1214)]);
	__state->dec += vdotg_(__global_state, &__state->bdc[(i__2 = 
		__state->at * 100 - 100) < 15700 && 0 <= i__2 ? i__2 : s_rnge(
		&__global_state->f2c, "bdc", i__2, "tisbod_", (ftnlen)1215)], 
		__state->costh, &__state->bnd[(i__1 = __state->at - 1) < 157 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "bnd", 
		i__1, "tisbod_", (ftnlen)1215)]);
	__state->w += vdotg_(__global_state, &__state->bwc[(i__2 = 
		__state->at * 100 - 100) < 15700 && 0 <= i__2 ? i__2 : s_rnge(
		&__global_state->f2c, "bwc", i__2, "tisbod_", (ftnlen)1216)], 
		__state->sinth, &__state->bnw[(i__1 = __state->at - 1) < 157 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "bnw", 
		i__1, "tisbod_", (ftnlen)1216)]);
	__state->dra += vdotg_(__global_state, &__state->bac[(i__2 = 
		__state->at * 100 - 100) < 15700 && 0 <= i__2 ? i__2 : s_rnge(
		&__global_state->f2c, "bac", i__2, "tisbod_", (ftnlen)1218)], 
		__state->dsinth, &__state->bna[(i__1 = __state->at - 1) < 157 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "bna", 
		i__1, "tisbod_", (ftnlen)1218)]);
	__state->ddec += vdotg_(__global_state, &__state->bdc[(i__2 = 
		__state->at * 100 - 100) < 15700 && 0 <= i__2 ? i__2 : s_rnge(
		&__global_state->f2c, "bdc", i__2, "tisbod_", (ftnlen)1219)], 
		__state->dcosth, &__state->bnd[(i__1 = __state->at - 1) < 157 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "bnd", 
		i__1, "tisbod_", (ftnlen)1219)]);
	__state->dw += vdotg_(__global_state, &__state->bwc[(i__2 = 
		__state->at * 100 - 100) < 15700 && 0 <= i__2 ? i__2 : s_rnge(
		&__global_state->f2c, "bwc", i__2, "tisbod_", (ftnlen)1220)], 
		__state->dsinth, &__state->bnw[(i__1 = __state->at - 1) < 157 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "bnw", 
		i__1, "tisbod_", (ftnlen)1220)]);

/*        Convert from degrees to radians */

	__state->ra *= rpd_(__global_state);
	__state->dec *= rpd_(__global_state);
	__state->w *= rpd_(__global_state);
	__state->dra *= rpd_(__global_state);
	__state->ddec *= rpd_(__global_state);
	__state->dw *= rpd_(__global_state);

/*        Convert to Euler angles. */

	d__1 = twopi_(__global_state);
	__state->w = d_mod(&__global_state->f2c, &__state->w, &d__1);
	__state->phi = __state->ra + halfpi_(__global_state);
	__state->delta = halfpi_(__global_state) - __state->dec;
	__state->dphi = __state->dra;
	__state->ddelta = -__state->ddec;
	if (failed_(__global_state)) {
	    chkout_(__global_state, "TISBOD", (ftnlen)6);
	    return 0;
	}

/*        Pack the Euler angles and their derivatives into */
/*        a state vector. */

	vpack_(__global_state, &__state->w, &__state->delta, &__state->phi, 
		__state->eulsta);
	vpack_(__global_state, &__state->dw, &__state->ddelta, &__state->dphi,
		 &__state->eulsta[3]);

/*        Find the state transformation defined by the Euler angle */
/*        state vector. The transformation matrix TSIPM has the */
/*        following structure: */

/*            -            - */
/*           |       :      | */
/*           | TIPM  :  0   | */
/*           | ......:......| */
/*           |       :      | */
/*           | DTIPM : TIPM | */
/*           |       :      | */
/*            -            - */

	eul2xf_(__global_state, __state->eulsta, &__state->c__3, &
		__state->c__1, &__state->c__3, tsipm);
    }

/*     At this point the base frame PCREF has been determined. */

/*     If the requested base frame is not base frame associated with the */
/*     PCK data, adjust the transformation matrix TSIPM to map from the */
/*     requested frame to the body-fixed frame. */

    if (__state->reqref != __state->pcref) {

/*        Next get the position transformation from the user specified */
/*        inertial frame to the native PCK inertial frame. */

	irfrot_(__global_state, &__state->reqref, &__state->pcref, 
		__state->req2pc);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "TISBOD", (ftnlen)6);
	    return 0;
	}

/*        Since we're applying an inertial transformation to TSIPM, */
/*        we can rotate the non-zero blocks of TSIPM. This saves */
/*        a bunch of double precision multiplications. */

/*        Extract the upper and lower left blocks of TSIPM. */

	for (__state->i__ = 1; __state->i__ <= 3; ++__state->i__) {
	    for (__state->j = 1; __state->j <= 3; ++__state->j) {
		__state->tipm[(i__2 = __state->i__ + __state->j * 3 - 4) < 9 
			&& 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
			"tipm", i__2, "tisbod_", (ftnlen)1304)] = tsipm[(i__1 
			= __state->i__ + __state->j * 6 - 7) < 36 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "tsipm", 
			i__1, "tisbod_", (ftnlen)1304)];
		__state->dtipm[(i__2 = __state->i__ + __state->j * 3 - 4) < 9 
			&& 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
			"dtipm", i__2, "tisbod_", (ftnlen)1305)] = tsipm[(
			i__1 = __state->i__ + 3 + __state->j * 6 - 7) < 36 && 
			0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "tsi"
			"pm", i__1, "tisbod_", (ftnlen)1305)];
	    }
	}

/*        Rotate the blocks. Note this is a right multiplication. */

	mxm_(__global_state, __state->tipm, __state->req2pc, __state->xtipm);
	mxm_(__global_state, __state->dtipm, __state->req2pc, __state->xdtipm)
		;

/*        Replace the non-zero blocks of TSIPM. This gives us the */
/*        transformation from the requested frame to the */
/*        bodyfixed frame. */

	for (__state->i__ = 1; __state->i__ <= 3; ++__state->i__) {
	    for (__state->j = 1; __state->j <= 3; ++__state->j) {
		tsipm[(i__2 = __state->i__ + __state->j * 6 - 7) < 36 && 0 <= 
			i__2 ? i__2 : s_rnge(&__global_state->f2c, "tsipm", 
			i__2, "tisbod_", (ftnlen)1326)] = __state->xtipm[(
			i__1 = __state->i__ + __state->j * 3 - 4) < 9 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "xtipm", 
			i__1, "tisbod_", (ftnlen)1326)];
		tsipm[(i__2 = __state->i__ + 3 + (__state->j + 3) * 6 - 7) < 
			36 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
			"tsipm", i__2, "tisbod_", (ftnlen)1327)] = 
			__state->xtipm[(i__1 = __state->i__ + __state->j * 3 
			- 4) < 9 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "xtipm", i__1, "tisbod_", (
			ftnlen)1327)];
		tsipm[(i__2 = __state->i__ + 3 + __state->j * 6 - 7) < 36 && 
			0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "tsi"
			"pm", i__2, "tisbod_", (ftnlen)1328)] = 
			__state->xdtipm[(i__1 = __state->i__ + __state->j * 3 
			- 4) < 9 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "xdtipm", i__1, "tisbod_", (
			ftnlen)1328)];
	    }
	}
    }

/*     That's all folks. Check out and get out. */

    chkout_(__global_state, "TISBOD", (ftnlen)6);
    return 0;
} /* tisbod_ */

