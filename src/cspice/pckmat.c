/* pckmat.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern pckmat_init_t __pckmat_init;
static pckmat_state_t* get_pckmat_state(cspice_t* state) {
	if (!state->pckmat)
		state->pckmat = __cspice_allocate_module(sizeof(
	pckmat_state_t), &__pckmat_init, sizeof(__pckmat_init));
	return state->pckmat;

}

/* $Procedure PCKMAT ( PCK, get transformation matrix at time ) */
/* Subroutine */ int pckmat_(cspice_t* __global_state, integer *body, 
	doublereal *et, integer *ref, doublereal *tsipm, logical *found)
{
    integer type__;
    extern /* Subroutine */ int pcke02_(cspice_t*, doublereal *, doublereal *,
	     doublereal *);
    extern /* Subroutine */ int pcke03_(cspice_t*, doublereal *, doublereal *,
	     doublereal *);
    extern /* Subroutine */ int pcke20_(cspice_t*, doublereal *, doublereal *,
	     doublereal *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    doublereal descr[5];
    extern /* Subroutine */ int pckr02_(cspice_t*, integer *, doublereal *, 
	    doublereal *, doublereal *);
    extern /* Subroutine */ int dafus_(cspice_t*, doublereal *, integer *, 
	    integer *, doublereal *, integer *);
    char ident[40];
    extern /* Subroutine */ int pckr03_(cspice_t*, integer *, doublereal *, 
	    doublereal *, doublereal *);
    extern /* Subroutine */ int pckr20_(cspice_t*, integer *, doublereal *, 
	    doublereal *, doublereal *);
    extern /* Subroutine */ int eul2xf_(cspice_t*, doublereal *, integer *, 
	    integer *, integer *, doublereal *);
    extern logical failed_(cspice_t*);
    integer handle;
    doublereal eulang[6];
    doublereal record[130];
    extern /* Subroutine */ int sgfcon_(cspice_t*, integer *, doublereal *, 
	    integer *, integer *, doublereal *);
    doublereal estate[6];
    extern /* Subroutine */ int pcksfs_(cspice_t*, integer *, doublereal *, 
	    integer *, doublereal *, char *, logical *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    integer recsiz;
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);
    doublereal dcd[2];
    integer icd[5];


    /* Module state */
    pckmat_state_t* __state = get_pckmat_state(__global_state);
/* $ Abstract */

/*      Given a body and epoch, return the name of an inertial */
/*      reference frame and the 6 x 6 state transformation matrix */
/*      from that frame to the body fixed frame. */

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

/*     NAIF_IDS */
/*     ROTATION */
/*     TIME */
/*     PCK */

/* $ Keywords */

/*     TRANSFORMATION */
/*     ROTATION */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     BODY       I   ID code of some body. */
/*     ET         I   Epoch of transformation. */
/*     REF        O   Integer code for inertial reference frame. */
/*     TSIPM      O   Transformation from Inertial to PM for BODY at ET. */
/*     FOUND      O   True if data for BODY and ET are found. */

/* $ Detailed_Input */

/*     BODY        is the integer ID code of the body for which the */
/*                 state transformation matrix is requested. Bodies */
/*                 are numbered according to the standard NAIF */
/*                 numbering scheme.  The numbering scheme is */
/*                 explained in the NAIF_IDS required reading file. */

/*     ET          is the epoch at which the state transformation */
/*                 matrix is requested. */

/* $ Detailed_Output */

/*     REF         is the integer code for the inertial reference frame */
/*                 of the state transformation matrix TSIPM. (See the */
/*                 routine CHGIRF for a full list of inertial reference */
/*                 frame names.) */

/*     TSIPM       is a 6x6 transformation matrix. It is used to */
/*                 transform states from inertial coordinates to body */
/*                 fixed (also called equator and prime meridian --- PM) */
/*                 coordinates. */

/*                 Given a state S in the inertial reference frame */
/*                 specified by REF, the corresponding state in the body */
/*                 fixed reference frame is given by the matrix vector */
/*                 product: */

/*                    TSIPM * S */

/*                 See the PCK required reading for further details */
/*                 concerning PCK reference frames. */

/*                 NOTE: The inverse of TSIPM is NOT its transpose. The */
/*                 matrix, TSIPM, has the structure shown below: */

/*                             -            - */
/*                            |       :      | */
/*                            |   R   :  0   | */
/*                            | ......:......| */
/*                            |       :      | */
/*                            | dR_dt :  R   | */
/*                            |       :      | */
/*                             -            - */

/*                 where R is a time varying rotation matrix and dR_dt */
/*                 is its derivative.  The inverse of this matrix is: */

/*                             -              - */
/*                            |     T  :       | */
/*                            |    R   :  0    | */
/*                            | .......:.......| */
/*                            |        :       | */
/*                            |      T :   T   | */
/*                            | dR_dt  :  R    | */
/*                            |        :       | */
/*                             -              - */

/*                 The SPICE routine INVSTM is available for producing */
/*                 this inverse. */

/*      FOUND      if the data allowing the computation of a state */
/*                 transformation matrix for the requested time and body */
/*                 are found in a binary PCK file, FOUND will have the */
/*                 value .TRUE., otherwise it will have the value */
/*                 .FALSE.. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the size of the type 20 PCK record to be  retrieved is too */
/*         large to fit into RECORD, the error SPICE(PCKRECTOOLARGE) */
/*         will be signaled. */

/*     2)  Any error that occurs while reading PCK data will be */
/*         diagnosed by a routine in the call tree of this routine. */

/*     3)  If the requested transformation matrix cannot be computed */
/*         using data from loaded binary PCK files, FOUND is returned */
/*         with the value .FALSE.. This is not a SPICE error. */

/* $ Files */

/*     This routine computes transformation matrices using data */
/*     provided by a loaded binary PCK kernel. */

/* $ Particulars */

/*     The matrix for transforming an inertial state into a body fixed */
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

/*     If a binary PCK file record can be found for the time and body */
/*     requested, it will be used. The most recently loaded binary PCK */
/*     file has first priority, followed by previously loaded binary PCK */
/*     files in backward time order. If no binary PCK file has been */
/*     loaded, the text P_constants kernel file is used. */


/* $ Examples */

/*     Here we load a binary PCK files and use PCKEUL to get the */
/*     Euler angles. */

/*     C */
/*     C  Load binary PCK file. */
/*     C */
/*        CALL PCKLOF ('example.pck', HANDLE) */

/*     C  Call routine to get transformation matrix. */

/*        CALL PCKMAT ( BODY, ET, REF, TIPM, FOUND ) */

/* $ Restrictions */

/*      None. */

/* $ Literature_References */

/*      None. */

/* $ Author_and_Institution */

/*      K. S. Zukor     (JPL) */
/*      K. R. Gehringer (JPL) */
/*      N. J. Bachman   (JPL) */

/* $ Version */

/* -     SPICELIB Version 3.0.0, 03-JAN-2014 (NJB) (EDW) */

/*         Minor edits to Procedure; clean trailing whitespace. */
/*         Removed unneeded Revisions section. */

/*         Updated to support type 20. Changed long error message */
/*         for the case of RECORD having insufficient room: the */
/*         user is no longer advised to modify the record size. */

/* -     SPICELIB Version 2.0.0, 22-MAR-1995 (KRG) (KSZ) */

/*         Added PCK type 03. Added a new exception. Made some minor */
/*         comment changes. */

/* -     SPICELIB Version 1.0.0, 21-MAR-1995 (KSZ) */

/*         Replaces PCKEUL and returns the transformation */
/*         matrix rather than the Euler angles. */

/* -& */
/* $ Index_Entries */

/*     get state transformation matrix from binary PCK file */

/* -& */

/*     SPICELIB functions */


/*     Local Parameters */

/*     ND and NI values for a PCK file. */


/*     Index for the reference frame code in the integer summary. */


/*     Length of the descriptor for a PCK file. */


/*     Index for the data type code in the integer summary. */


/*     Maximum size allowed for a record in a segment of a binary PCK */
/*     file. */


/*     Number of components in a state vector. */


/*     Local Variables */


/*     Standard SPICE Error handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "PCKMAT", (ftnlen)6);

/*     Get a segment applicable to a specified body and epoch. */

    pcksfs_(__global_state, body, et, &handle, descr, ident, found, (ftnlen)
	    40);
    if (failed_(__global_state)) {
	*found = FALSE_;
	chkout_(__global_state, "PCKMAT", (ftnlen)6);
	return 0;
    }
    if (*found) {

/*        Look at parts of the descriptor. */

	dafus_(__global_state, descr, &__state->c__2, &__state->c__5, dcd, 
		icd);
	type__ = icd[2];
	*ref = icd[1];
	if (type__ == 2) {

/*           Read in Chebyshev coefficients from segment. */

	    pckr02_(__global_state, &handle, descr, et, record);

/*           Call evaluation routine to get Euler angles */
/*           phi, delta, w. */

	    pcke02_(__global_state, et, record, eulang);
	    if (failed_(__global_state)) {
		*found = FALSE_;
		chkout_(__global_state, "PCKMAT", (ftnlen)6);
		return 0;
	    }

/*           From the PCK type two file the Euler angles are */
/*           retrieved in a particular order.  The routine to */
/*           get the TSIPM matrix from expects them in another */
/*           order.  Here we change from EULANG to ESTATE, which */
/*           has this proper order. */

	    estate[0] = eulang[2];
	    estate[1] = eulang[1];
	    estate[2] = eulang[0];
	    estate[3] = eulang[5];
	    estate[4] = eulang[4];
	    estate[5] = eulang[3];

/*           Call routine which takes Euler angles to transformation */
/*           matrix. */

	    eul2xf_(__global_state, estate, &__state->c__3, &__state->c__1, &
		    __state->c__3, tsipm);
	    if (failed_(__global_state)) {
		*found = FALSE_;
		chkout_(__global_state, "PCKMAT", (ftnlen)6);
		return 0;
	    }
	} else if (type__ == 3) {

/*           Fetch the number of Chebyshev coefficients, compute the */
/*           record size needed, and signal an error if there is not */
/*           enough storage in RECORD. The number of coefficients is the */
/*           first constant value in the generic segment. */

	    sgfcon_(__global_state, &handle, descr, &__state->c__1, &
		    __state->c__1, record);
	    if (failed_(__global_state)) {
		*found = FALSE_;
		chkout_(__global_state, "PCKMAT", (ftnlen)6);
		return 0;
	    }
	    recsiz = (integer) record[0] * 6 + 2;
	    if (recsiz > 130) {
		setmsg_(__global_state, "Storage for # double precision numb"
			"ers is needed for a PCK data record and only # locat"
			"ions were available. Notify the NAIF group of this p"
			"roblem.", (ftnlen)146);
		errint_(__global_state, "#", &recsiz, (ftnlen)1);
		errint_(__global_state, "#", &__state->c__130, (ftnlen)1);
		sigerr_(__global_state, "SPICE(PCKKRECTOOLARGE)", (ftnlen)22);
		chkout_(__global_state, "PCKMAT", (ftnlen)6);
		return 0;
	    }
	    pckr03_(__global_state, &handle, descr, et, record);
	    pcke03_(__global_state, et, record, tsipm);
	    if (failed_(__global_state)) {
		*found = FALSE_;
		chkout_(__global_state, "PCKMAT", (ftnlen)6);
		return 0;
	    }
	} else if (type__ == 20) {

/*           Read in Chebyshev coefficients from segment. */

	    pckr20_(__global_state, &handle, descr, et, record);

/*           Call evaluation routine to get Euler angles */
/*           phi, delta, w. */

	    pcke20_(__global_state, et, record, eulang);
	    if (failed_(__global_state)) {
		*found = FALSE_;
		chkout_(__global_state, "PCKMAT", (ftnlen)6);
		return 0;
	    }

/*           From the PCK type 20 file the Euler angles are */
/*           retrieved in a particular order. The routine to */
/*           get the TSIPM matrix from expects them in another */
/*           order. Here we change from EULANG to ESTATE, which */
/*           has this proper order. */

	    estate[0] = eulang[2];
	    estate[1] = eulang[1];
	    estate[2] = eulang[0];
	    estate[3] = eulang[5];
	    estate[4] = eulang[4];
	    estate[5] = eulang[3];

/*           Call routine which takes Euler angles to transformation */
/*           matrix. */

	    eul2xf_(__global_state, estate, &__state->c__3, &__state->c__1, &
		    __state->c__3, tsipm);
	    if (failed_(__global_state)) {
		*found = FALSE_;
		chkout_(__global_state, "PCKMAT", (ftnlen)6);
		return 0;
	    }
	} else {

/*           If data matching the requested body and time was not */
/*           found, FOUND is false. */

	    *found = FALSE_;
	}
    }
    chkout_(__global_state, "PCKMAT", (ftnlen)6);
    return 0;
} /* pckmat_ */

