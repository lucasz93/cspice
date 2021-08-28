/* sctype.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern sctype_init_t __sctype_init;
static inline sctype_state_t* get_sctype_state(cspice_t* state) {
	if (!state->sctype)
		state->sctype = __cspice_allocate_module(sizeof(
	sctype_state_t), &__sctype_init, sizeof(__sctype_init));
	return state->sctype;

}

/* $Procedure      SCTYPE ( SCLK type ) */
integer sctype_(cspice_t* __global_state, integer *sc)
{
    /* Initialized data */


    /* System generated locals */
    integer ret_val, i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int zzcvpool_(cspice_t*, char *, integer *, 
	    logical *, ftnlen);
    extern /* Subroutine */ int zzctruin_(cspice_t*, integer *);
    integer n;
    extern /* Subroutine */ int scli01_(cspice_t*, char *, integer *, integer 
	    *, integer *, integer *, ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int repmi_(cspice_t*, char *, char *, integer *, 
	    char *, ftnlen, ftnlen, ftnlen);
    extern logical failed_(cspice_t*);
    char kvname[60];
    logical update;
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int suffix_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int swpool_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);


    /* Module state */
    sctype_state_t* __state = get_sctype_state(__global_state);
/* $ Abstract */

/*     Return the spacecraft clock type for a specified spacecraft. */

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

/*     SCLK */

/* $ Keywords */

/*     TIME */

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

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     SC         I   NAIF spacecraft ID code. */

/*     The function returns the spacecraft clock type associated with the */
/*     spacecraft specified by SC. */

/* $ Detailed_Input */

/*     SC             is a NAIF ID code for a spacecraft, whose */
/*                    spacecraft clock `type' is desired. */

/* $ Detailed_Output */

/*     The function returns the spacecraft clock type associated with the */
/*     spacecraft specified by SC. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the kernel variable that assigns a SCLK type to the */
/*         spacecraft specified by SC is not found in the kernel pool, */
/*         the error is diagnosed by routines called by this routine. */
/*         SCTYPE returns the value 0 in this case. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     The raison d'etre of this routine is that it consolidates the code */
/*     that maps spacecraft ID's to clock types.  While any routine may */
/*     call SCTYPE, it is unlikely that there will be a need for */
/*     non-SPICELIB routines to call this routine directly. */

/* $ Examples */

/*     1)  Find the SCLK type for Galileo. */

/*            During program initialization, we load a SCLK kernel file */
/*            into the kernel pool.  We will pretend that the name of */
/*            this file is GLLSCLK.KER.  You must use the actual name of */
/*            an SCLK kernel that is accessible by your program to try */
/*            this example. */

/*                C */
/*                C     Load the SCLK kernel. */
/*                C */
/*                      CALL FURNSH ( 'GLLSCLK.KER' ) */
/*                                 . */
/*                                 . */
/*                                 . */
/*                C */
/*                C     Print out the clock type for Galileo. */
/*                C */
/*                      TYPE = SCTYPE ( -77 ) */

/*                      PRINT *, 'Galileo clock type is ', TYPE */


/*     2)  Find the SCLK type for Mars Observer. */


/*                C */
/*                C     Load the SCLK kernel. */
/*                C */
/*                      CALL FURNSH ( 'MOSCLK.KER' ) */
/*                                 . */
/*                                 . */
/*                                 . */
/*                C */
/*                C     Print out the clock type for Mars Observer. */
/*                C */
/*                      TYPE = SCTYPE ( -94 ) */

/*                      PRINT *, 'Mars Observer clock type is ', TYPE */

/* $ Restrictions */

/*     This routine assumes that an SCLK kernel appropriate to the */
/*     spacecraft specified by SC has been loaded into the kernel pool. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     J.M. Lynch     (JPL) */
/*     B.V. Semenov   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.3.0, 09-SEP-2013 (BVS) */

/*        Updated to keep track of the POOL counter and call ZZCVPOOL. */

/* -    SPICELIB Version 1.2.0, 05-MAR-2009 (NJB) */

/*        Bug fix: this routine now keeps track of whether its */
/*        kernel pool look-up succeeded. If not, a kernel pool */
/*        lookup is attempted on the next call to this routine. */

/* -    SPICELIB Version 1.1.1, 22-AUG-2006 (EDW) */

/*        Replaced references to LDPOOL with references */
/*        to FURNSH. */

/* -    SPICELIB Version 1.1.0, 22-MAR-1993 (JML) */

/*        1) The routine now uses the kernel pool watch capability. */

/*        2) The routine now returns a value of zero if RETURN is */
/*           true on entry. */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 04-SEP-1990 (NJB) */

/* -& */
/* $ Index_Entries */

/*     spacecraft_clock type */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     Saved variables */


/*     Initial values */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	ret_val = 0;
	return ret_val;
    }
    chkin_(__global_state, "SCTYPE", (ftnlen)6);

/*     On the first pass through the subroutine, or if the spacecraft */
/*     ID code changes, set a watch on the SCLK kernel variable for */
/*     the current clock type. */

    if (__state->first || *sc != __state->oldsc) {

/*        Construct the name of the kernel variable that is needed. */

	s_copy(&__global_state->f2c, kvname, "SCLK_DATA_TYPE", (ftnlen)60, (
		ftnlen)14);
	suffix_(__global_state, "_#", &__state->c__0, kvname, (ftnlen)2, (
		ftnlen)60);
	i__1 = -(*sc);
	repmi_(__global_state, kvname, "#", &i__1, kvname, (ftnlen)60, (
		ftnlen)1, (ftnlen)60);

/*        Set a watch on the kernel variable needed. */

	swpool_(__global_state, "SCTYPE", &__state->c__1, kvname, (ftnlen)6, (
		ftnlen)60);

/*        Keep track of the last spacecraft ID encountered. */

	__state->oldsc = *sc;

/*        Initialize the local POOL counter to user value. */

	zzctruin_(__global_state, __state->usrctr);
	__state->first = FALSE_;
    }

/*     If the kernel pool variable that this routine uses has */
/*     been updated, or if the spacecraft id code changes, look */
/*     up the new value from the kernel pool. */

    zzcvpool_(__global_state, "SCTYPE", __state->usrctr, &update, (ftnlen)6);
    if (update || __state->nodata) {

/*        Find the clock type for the specified mission. */

	__state->type__ = 0;
	scli01_(__global_state, "SCLK_DATA_TYPE", sc, &__state->c__1, &n, &
		__state->type__, (ftnlen)14);
	if (failed_(__global_state)) {
	    __state->nodata = TRUE_;
	    ret_val = 0;
	    chkout_(__global_state, "SCTYPE", (ftnlen)6);
	    return ret_val;
	}
	__state->nodata = FALSE_;
    }
    ret_val = __state->type__;
    chkout_(__global_state, "SCTYPE", (ftnlen)6);
    return ret_val;
} /* sctype_ */

