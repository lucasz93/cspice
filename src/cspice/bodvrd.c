/* bodvrd.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern bodvrd_init_t __bodvrd_init;
static bodvrd_state_t* get_bodvrd_state(cspice_t* state) {
	if (!state->bodvrd)
		state->bodvrd = __cspice_allocate_module(sizeof(
	bodvrd_state_t), &__bodvrd_init, sizeof(__bodvrd_init));
	return state->bodvrd;

}

/* $Procedure      BODVRD ( Return d.p. values from the kernel pool ) */
/* Subroutine */ int bodvrd_(cspice_t* __global_state, char *bodynm, char *
	item, integer *maxn, integer *dim, doublereal *values, ftnlen 
	bodynm_len, ftnlen item_len)
{
    /* Initialized data */


    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    char code[16];
    extern /* Subroutine */ int zzbods2c_(cspice_t*, integer *, char *, 
	    integer *, logical *, char *, integer *, logical *, ftnlen, 
	    ftnlen);
    char type__[1];
    extern /* Subroutine */ int zzctruin_(cspice_t*, integer *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    logical found;
    integer bodyid;
    char varnam[32];
    extern /* Subroutine */ int gdpool_(cspice_t*, char *, integer *, integer 
	    *, integer *, doublereal *, logical *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int dtpool_(cspice_t*, char *, logical *, integer 
	    *, char *, ftnlen, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int suffix_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int intstr_(cspice_t*, integer *, char *, ftnlen);


    /* Module state */
    bodvrd_state_t* __state = get_bodvrd_state(__global_state);
/* $ Abstract */

/*     Fetch from the kernel pool the double precision values */
/*     of an item associated with a body. */

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

/*     KERNEL */
/*     NAIF_IDS */

/* $ Keywords */

/*     CONSTANTS */

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
/*     BODYNM     I   Body name. */
/*     ITEM       I   Item for which values are desired. ('RADII', */
/*                    'NUT_PREC_ANGLES', etc. ) */
/*     MAXN       I   Maximum number of values that may be returned. */
/*     DIM        O   Number of values returned. */
/*     VALUES     O   Values. */

/* $ Detailed_Input */

/*     BODYNM     is the name of the body for which ITEM is requested. */
/*                BODYNM is case-insensitive, and leading and trailing */
/*                blanks in BODYNM are not significant. Optionally, you */
/*                may supply the integer ID code for the object as an */
/*                integer string.  For example both 'MOON' and '301' are */
/*                legitimate strings that indicate the moon is the body */
/*                of interest. */

/*     ITEM       is the item to be returned. Together, the NAIF ID */
/*                code of the body and the item name combine to form a */
/*                kernel variable name, e.g., */

/*                      'BODY599_RADII' */
/*                      'BODY401_POLE_RA' */

/*                The values associated with the kernel variable having */
/*                the name constructed as shown are sought.  Below */
/*                we'll take the shortcut of calling this kernel variable */
/*                the "requested kernel variable." */

/*                Note that ITEM *is* case-sensitive.  This attribute */
/*                is inherited from the case-sensitivity of kernel */
/*                variable names. */

/*     MAXN       is the maximum number of values that may be returned. */
/*                The output array VALUES must be declared with size at */
/*                least MAXN.  It's an error to supply an output array */
/*                that is too small to hold all of the values associated */
/*                with the requested kernel variable. */

/* $ Detailed_Output */

/*     DIM        is the number of values returned; this is always the */
/*                number of values associated with the requested kernel */
/*                variable unless an error has been signaled. */

/*     VALUES     is the array of values associated with the requested */
/*                kernel variable.  If VALUES is too small to hold all */
/*                of the values associated with the kernel variable, the */
/*                returned values of DIM and VALUES are undefined. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If the input body name cannot be translated to an ID code, */
/*        and if the name is not a string representation of an integer */
/*        (for example, '399'), the error SPICE(NOTRANSLATION) is */
/*        signaled. */

/*     2) If the requested kernel variable is not found in the kernel */
/*        pool, the error SPICE(KERNELVARNOTFOUND) is signaled. */

/*     3) If the requested kernel variable is found but the associated */
/*        values aren't numeric, the error SPICE(TYPEMISMATCH) is */
/*        signaled. */

/*     4) The output array VALUES must be declared with sufficient size */
/*        to contain all of the values associated with the requested */
/*        kernel variable.  If the dimension of */
/*        VALUES indicated by MAXN is too small to contain the */
/*        requested values, the error SPICE(ARRAYTOOSMALL) is signaled. */

/*     5) If the input dimension MAXN indicates there is more room */
/*        in VALUES than there really is---for example, if MAXN is */
/*        10 but values is declared with dimension 5---and the dimension */
/*        of the requested kernel variable is larger than the actual */
/*        dimension of VALUES, then this routine may overwrite */
/*        memory.  The results are unpredictable. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine simplifies looking up PCK kernel variables by */
/*     constructing names of requested kernel variables and by */
/*     performing error checking. */

/*     This routine is intended for use in cases where the maximum */
/*     number of values that may be returned is known at compile */
/*     time.  The caller fetches all of the values associated with */
/*     the specified kernel variable via a single call to this */
/*     routine.  If the number of values to be fetched cannot be */
/*     known until run time, the lower-level routine  GDPOOL (an */
/*     entry point of POOL) should be used instead.  GDPOOL supports */
/*     fetching arbitrary amounts of data in multiple "chunks." */

/*     This routine is intended for use in cases where the requested */
/*     kernel variable is expected to be present in the kernel pool.  If */
/*     the variable is not found or has the wrong data type, this */
/*     routine signals an error.  In cases where it is appropriate to */
/*     indicate absence of an expected kernel variable by returning a */
/*     boolean "found flag" with the value .FALSE., again the routine */
/*     GDPOOL should be used. */

/* $ Examples */

/*     1)  When the kernel variable */

/*            BODY399_RADII */

/*         is present in the kernel pool---normally because a PCK */
/*         defining this variable has been loaded---the call */

/*            CALL BODVRD ( 'EARTH', 'RADII', 3, DIM, VALUES ) */

/*         returns the dimension and values associated with the variable */
/*         'BODY399_RADII', for example, */

/*            DIM       = 3 */
/*            VALUES(1) = 6378.140 */
/*            VALUES(2) = 6378.140 */
/*            VALUES(3) = 6356.755 */


/*     2)  The call */

/*            CALL BODVRD ( 'earth', 'RADII', 3, DIM, VALUES ) */

/*         will produce the same results shown in example (1), */
/*         since the case of the input argument BODYNM is */
/*         not significant. */


/*     3)  The call */

/*            CALL BODVRD ( '399', 'RADII', 3, DIM, VALUES ) */

/*         will produce the same results shown in example (1), */
/*         since strings containing integer codes are accepted */
/*         by this routine. */


/*     4) The call */

/*           CALL BODVRD ( 'EARTH', 'radii', 3, DIM, VALUES ) */

/*        usually will cause a SPICE(KERNELVARNOTFOUND) error to be */
/*        signaled, because this call will attempt to look up the */
/*        values associated with a kernel variable of the name */

/*           'BODY399_radii' */

/*        Since kernel variable names are case sensitive, this */
/*        name is not considered to match the name */

/*           'BODY399_RADII' */

/*        which normally would be present after a text PCK */
/*        containing data for all planets and satellites has */
/*        been loaded. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     B.V. Semenov    (JPL) */
/*     W.L. Taber      (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.2.0, 19-SEP-2013 (BVS) */

/*        Updated to save the input body name and ZZBODTRN state counter */
/*        and to do name-ID conversion only if the counter has changed. */

/* -    SPICELIB Version 1.1.0, 22-JUL-2004 (NJB) */

/*        Updated to use BODS2C. */

/* -    SPICELIB Version 1.0.0, 23-FEB-2004 (NJB) (BVS) (WLT) (IMU) */

/* -& */
/* $ Index_Entries */

/*     fetch constants for a body from the kernel pool */
/*     physical constants for a body */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.1.0, 22-JUL-2004 (NJB) */

/*        Updated to use BODS2C.  This simplifies the name-to-ID */
/*        mapping code. */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Saved body name length. */


/*     Local variables */


/*     Saved name/ID item declarations. */


/*     Saved name/ID items. */


/*     Initial values. */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "BODVRD", (ftnlen)6);
    }

/*     Initialization. */

    if (__state->first) {

/*        Initialize counter. */

	zzctruin_(__global_state, __state->svctr1);
	__state->first = FALSE_;
    }

/*     Translate the input name to an ID code. */

    zzbods2c_(__global_state, __state->svctr1, __state->svbdnm, &
	    __state->svbdid, &__state->svfnd1, bodynm, &bodyid, &found, (
	    ftnlen)36, bodynm_len);
    if (! found) {
	setmsg_(__global_state, "The body name # could not be translated to "
		"a NAIF ID code.  The cause of this problem may be that you n"
		"eed an updated version of the SPICE Toolkit.", (ftnlen)147);
	errch_(__global_state, "#", bodynm, (ftnlen)1, bodynm_len);
	sigerr_(__global_state, "SPICE(NOTRANSLATION)", (ftnlen)20);
	chkout_(__global_state, "BODVRD", (ftnlen)6);
	return 0;
    }

/*     Construct the variable name from BODY and ITEM. */

    s_copy(&__global_state->f2c, varnam, "BODY", (ftnlen)32, (ftnlen)4);
    intstr_(__global_state, &bodyid, code, (ftnlen)16);
    suffix_(__global_state, code, &__state->c__0, varnam, (ftnlen)16, (ftnlen)
	    32);
    suffix_(__global_state, "_", &__state->c__0, varnam, (ftnlen)1, (ftnlen)
	    32);
    suffix_(__global_state, item, &__state->c__0, varnam, item_len, (ftnlen)
	    32);

/*     Make sure the item is present in the kernel pool. */

    dtpool_(__global_state, varnam, &found, dim, type__, (ftnlen)32, (ftnlen)
	    1);
    if (! found) {
	setmsg_(__global_state, "The variable # could not be found in the ke"
		"rnel pool.", (ftnlen)53);
	errch_(__global_state, "#", varnam, (ftnlen)1, (ftnlen)32);
	sigerr_(__global_state, "SPICE(KERNELVARNOTFOUND)", (ftnlen)24);
	chkout_(__global_state, "BODVRD", (ftnlen)6);
	return 0;
    }

/*     Make sure the item's data type is numeric. */

    if (*(unsigned char *)type__ != 'N') {
	setmsg_(__global_state, "The data associated with variable # are not"
		" of numeric type.", (ftnlen)60);
	errch_(__global_state, "#", varnam, (ftnlen)1, (ftnlen)32);
	sigerr_(__global_state, "SPICE(TYPEMISMATCH)", (ftnlen)19);
	chkout_(__global_state, "BODVRD", (ftnlen)6);
	return 0;
    }

/*     Make sure there's enough room in the array VALUES to hold */
/*     the requested data. */

    if (*maxn < *dim) {
	setmsg_(__global_state, "The data array associated with variable # h"
		"as dimension #, which is larger than the available space # i"
		"n the output array.", (ftnlen)122);
	errch_(__global_state, "#", varnam, (ftnlen)1, (ftnlen)32);
	errint_(__global_state, "#", dim, (ftnlen)1);
	errint_(__global_state, "#", maxn, (ftnlen)1);
	sigerr_(__global_state, "SPICE(ARRAYTOOSMALL)", (ftnlen)20);
	chkout_(__global_state, "BODVRD", (ftnlen)6);
	return 0;
    }

/*     Grab the values.  We know at this point they're present in */
/*     the kernel pool, so we don't check the FOUND flag. */

    gdpool_(__global_state, varnam, &__state->c__1, maxn, dim, values, &found,
	     (ftnlen)32);
    chkout_(__global_state, "BODVRD", (ftnlen)6);
    return 0;
} /* bodvrd_ */

