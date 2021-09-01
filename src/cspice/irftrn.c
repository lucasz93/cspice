/* irftrn.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int irftrn_state_t;
static irftrn_state_t* get_irftrn_state(cspice_t* state) {
	return 0;
}

/* $Procedure      IRFTRN ( Inertial reference frame transformation ) */
/* Subroutine */ int irftrn_(cspice_t* __global_state, char *refa, char *refb,
	 doublereal *rotab, ftnlen refa_len, ftnlen refb_len)
{
    integer codea;
    integer codeb;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int irfnum_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int irfrot_(cspice_t*, integer *, integer *, 
	    doublereal *);
    extern logical return_(cspice_t*);


    /* Module state */
    irftrn_state_t* __state = get_irftrn_state(__global_state);
/* $ Abstract */

/*     Return the matrix that transforms vectors from one specified */
/*     inertial reference frame to another. */

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

/*     SPK */

/* $ Keywords */

/*     CONVERSION */
/*     COORDINATES */
/*     FRAMES */
/*     MATRIX */
/*     ROTATION */
/*     TRANSFORMATION */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     REFA       I   Name of reference frame to transform vectors FROM. */
/*     REFB       I   Name of reference frame to transform vectors TO. */
/*     ROTAB      O   REFA-to-REFB transformation matrix. */

/* $ Detailed_Input */

/*     REFA, */
/*     REFB           Names of two inertial reference frames.  Any names */
/*                    accepted by the routine IRFNUM may be used.  See */
/*                    $Particulars for a list of some of the more */
/*                    commonly used inertial reference frame names. */

/* $ Detailed_Output */

/*     ROTAB          is a rotation matrix that transforms the */
/*                    coordinates of a vector V relative to the */
/*                    reference frame specified by REFA to the */
/*                    coordinates of V relative to the reference frame */
/*                    specified by REFB.  The transformation is carried */
/*                    out by the matrix multiplication */

/*                       V = ROTAB * V. */
/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If either of the input reference frame names is invalid, the */
/*         error will be diagnosed by routines called by this routine. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     Normally applications should call the more general, higher level */
/*     routine PXFORM instead of this routine. */

/*     This routine is a macro that replaces the code fragment */

/*        CALL IRFNUM ( REFA,  CODEA        ) */
/*        CALL IRFNUM ( REFB,  CODEB        ) */
/*        CALL IRFROT ( CODEA, CODEB, ROTAB ) */


/*     Among the reference frame names accepted by IRFNUM are: */

/*        'J2000' */
/*        'B1950' */
/*        'FK4' */
/*        'DE-96' */
/*        'DE-102' */
/*        'DE-108' */
/*        'DE-111' */
/*        'DE-114' */
/*        'DE-118' */
/*        'DE-122' */
/*        'DE-125' */
/*        'DE-130' */
/*        'DE-200' */
/*        'DE-202' */
/*        'GALACTIC' */

/*     See the SPICELIB routine GHGIRF for details. */


/* $ Examples */

/*     1)  Transform a vector V1950 from the B1950 to the J2000 */
/*         reference frame. */

/*            C */
/*            C     Ask IRFTRN for the matrix that transforms vectors */
/*            C     from the B1950 to the J2000 reference frame. */
/*            C */
/*                  CALL IRFTRN ( 'B1950', 'J2000', TRANS ) */

/*            C */
/*            C     Now transform V1950 to the J2000 reference frame. */
/*            C */
/*                  CALL MXV ( TRANS, V1950, V2000 ) */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.2, 28-SEP-2004 (NJB) */

/*        Corrected comment in code example in header.  Made other minor */
/*        updates to header. */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 30-AUG-1991 (NJB) */

/* -& */
/* $ Index_Entries */

/*     tranformation from one inertial frame to another */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "IRFTRN", (ftnlen)6);
    }

/*     Encode the reference frame names, and find the transformation */
/*     matrix. */

    irfnum_(__global_state, refa, &codea, refa_len);
    irfnum_(__global_state, refb, &codeb, refb_len);
    irfrot_(__global_state, &codea, &codeb, rotab);
    chkout_(__global_state, "IRFTRN", (ftnlen)6);
    return 0;
} /* irftrn_ */

