/* zzsrfker.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzsrfker_init_t __zzsrfker_init;
static inline zzsrfker_state_t* get_zzsrfker_state(cspice_t* state) {
	if (!state->zzsrfker)
		state->zzsrfker = __cspice_allocate_module(sizeof(
	zzsrfker_state_t), &__zzsrfker_init, sizeof(__zzsrfker_init));
	return state->zzsrfker;

}

/* $Procedure ZZSRFKER ( Surface translation, process kernel update ) */
/* Subroutine */ int zzsrfker_(cspice_t* __global_state, char *kernam, char *
	nornam, integer *kersid, integer *kerbid, logical *extker, integer *
	nkvar, integer *snmhls, integer *snmpol, integer *snmidx, integer *
	sidhls, integer *sidpol, integer *sididx, ftnlen kernam_len, ftnlen 
	nornam_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int zzsrfini_(cspice_t*, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, ftnlen);
    integer i__;
    integer ncode;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer nname;
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    integer nbody;
    logical fndcde;
    extern logical failed_(cspice_t*);
    logical fndbod;
    logical fndnam;
    extern /* Subroutine */ int gcpool_(cspice_t*, char *, integer *, integer 
	    *, integer *, char *, logical *, ftnlen, ftnlen);
    char bdtype[1];
    char cdtype[1];
    extern /* Subroutine */ int gipool_(cspice_t*, char *, integer *, integer 
	    *, integer *, integer *, logical *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int dtpool_(cspice_t*, char *, logical *, integer 
	    *, char *, ftnlen, ftnlen);
    char ndtype[1];
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int ljucrs_(cspice_t*, integer *, char *, char *, 
	    ftnlen, ftnlen);
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int swpool_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);


    /* Module state */
    zzsrfker_state_t* __state = get_zzsrfker_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due to the */
/*     volatile nature of this routine. */

/*     Update ZZSRFTRN's name-based and ID-based data structure arrays */
/*     using the contents of kernel variables that define the surface */
/*     name/ID mapping. */

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

/*     UTILITY */

/* $ Declarations */
/* $ Abstract */

/*     Declare public surface name/ID mapping parameters. */

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

/* $ Keywords */

/*     CONVERSION */
/*     NAME */
/*     STRING */
/*     SURFACE */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 02-DEC-2015 (NJB) */

/* -& */

/*     Maximum number of surface name/ID mapping entries: */


/*     Maximum length of a surface name string: */


/*     End of file srftrn.inc. */

/* $ Abstract */

/*     SPICE private include file intended solely for the support of */
/*     SPICE routines. User software should not include this file */
/*     due to the volatile nature of this file. */

/*     Declare private surface name/ID mapping parameters. */

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

/* $ Keywords */

/*     CONVERSION */
/*     NAME */
/*     STRING */
/*     SURFACE */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 04-FEB-2017 (NJB) */

/*        Original version 03-DEC-2015 (NJB) */

/* -& */

/*     Size of the lists and hashes storing the POOL-defined name/ID */
/*     mappings. To ensure efficient hashing, this size is set to the */
/*     first prime number greater than MXNSRF defined in the public */
/*     include file */

/*        srftrn.inc. */


/*     Singly-linked list pool lower bound: */


/*     End of file zzsrftrn.inc. */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     KERNAM     O   Array of surface names from kernel pool. */
/*     NORNAM     O   Array of normalized surface names. */
/*     KERSID     O   Array of surface ID codes from kernel pool. */
/*     KERBID     O   Array of body ID codes from kernel pool. */
/*     EXTKER     O   Logical flag indicating kernel data are present. */
/*     NKVAR      O   Number of surface name, code, body tuples. */
/*     SNMHLS     O   Surface name-based hash head node pointer list */
/*     SNMPOL     O   Surface name-based hash node collision list */
/*     SNMIDX     O   Surface name-based hash index storage array */
/*     SIDHLS     O   Surface ID-based hash head node pointer list */
/*     SIDPOL     O   Surface ID-based hash node collision list */
/*     SIDIDX     O   Surface ID-based hash index storage array */
/*     LBSNGL     P   Lower bound of hash pool arrays */
/*     SFNMLN     P   Maximum length of surface name strings */

/* $ Detailed_Input */

/*     None. */

/* $ Detailed_Output */

/*     KERNAM    is an array containing surface names from kernel pool */
/*               assignments to the kernel variable NAIF_SURFACE_NAME. */

/*               Array elements from masked assignments are not included */
/*               in KERNAM. */

/*     NORNAM    is an array parallel to KERNAM containing normalized */
/*               names. The Ith element of NORNAM is obtained from the */
/*               Ith element of KERNAM by conversion to uppercase, */
/*               left-justification, and compression of consecutive */
/*               embedded blanks to a single blank. */

/*     KERSID    is an array containing surface names from kernel pool */
/*               assignments to the kernel variable NAIF_SURFACE_CODE. */
/*               The Ith element of KERSID is the code associated with */
/*               the Ith element of KERNAM. */

/*     KERBID    is an array containing surface names from kernel pool */
/*               assignments to the kernel variable NAIF_SURFACE_BODY. */
/*               The Ith element of KERBID is the code associated with */
/*               the Ith element of KERNAM. */

/*     EXTKER    is a logical flag indicating whether kernel data */
/*               defining a surface name/ID mapping are available. */
/*               EXTKER is set to .TRUE. if the data are present and is */
/*               .FALSE. otherwise. */

/*     NKVAR     is the count of names in the array KERNAM; the */
/*               arrays NORNAM, KERSID, and KERBID also contain NKVAR */
/*               entries. */

/*     SNMHLS */
/*     SNMPOL    are the surface name-based hash head node pointer and */
/*               collision lists. Together with the arrays SNMIDX, */
/*               NORNAM, KERBID, and KERSID, they enable mapping pairs */
/*               of normalized surface names and body ID codes to */
/*               surface ID codes. */

/*     SNMIDX    is the surface name-based hash index storage array. It */
/*               maps nodes in the name collision list to entries in the */
/*               parallel NORNAM, KERBID, and KERSID arrays. */

/*     SIDHLS */
/*     SIDPOL    are the surface ID-based hash head node pointer and */
/*               collision lists. Together with the arrays SIDIDX, */
/*               KERSID, KERBID, and KERNAM, they enable mapping pairs of */
/*               surface ID codes and body ID codes to surface names. */

/*     SIDIDX    is the surface ID-based hash index storage array. It */
/*               maps nodes in the ID collision list to entries in the */
/*               parallel KERSID, KERBID, and KERNAM arrays. */

/* $ Parameters */

/*     LBSNGL    is the lower bound of the hashes' collision list array. */

/*     SFNMLN    is the maximum length of a surface name. Defined in the */
/*               include file 'srftrn.inc'. */

/* $ Exceptions */

/*     1)  If an error occurs while fetching kernel variables, the error */
/*         will be signaled by a routine in the call tree of this */
/*         routine. */

/*     2)  All three of the kernel variables defining the surface name/ID */
/*         map must be present in the kernel pool, or all must be absent. */
/*         If this condition is not met, the error SPICE(BADSURFACEMAP) */
/*         will be signaled. */

/*     3)  All three of the kernel variables defining the surface name/ID */
/*         map must have the correct data type; if not, the error */
/*         SPICE(BADVARIABLETYPE) will be signaled. */

/*     4)  If any of the kernel variables defining the surface name/ID */
/*         map have size exceeding MXNSRF, the error */
/*         SPICE(TOOMANYSURFACES) will be signaled. */

/*     5)  All three of the kernel variables defining the surface name/ID */
/*         map must have the same number of elements; if not, the error */
/*         SPICE(ARRAYSIZEMISMATCH) will be signaled. */

/*     6)  If any surface name is blank, the error */
/*         SPICE(BLANKNAMEASSIGNED) will be signaled. */

/*     7)  Any error occurring during initialization of the hash data */
/*         structures will be signaled by a routine in the call tree */
/*         of this routine. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine manages updates of the surface name/ID mapping */
/*     subsystem data structures. The outputs of this routine contain */
/*     mapping information provided by kernel variables, as well as */
/*     associated bookkeeping information. */

/*     On the first pass through this routine, the routine sets a watch */
/*     on the kernel variables that define the surface name/ID mapping. */
/*     This routine must be called after any change to these variables. */

/* $ Examples */

/*     See the routine ZZSRFTRN. */

/* $ Restrictions */

/*     1)  This routine is intended only for use by ZZSRFTRN and */
/*         ZZSRFKER. */

/*     2)  All output hash arrays must be declared with the same */
/*         dimension which is greater than or equal to MAXVAL. */

/*     3)  The order of mappings in the input arrays determines the */
/*         priority, with the mapping with the lowest priority being the */
/*         first and the mapping with the highest priority being the */
/*         last. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     B.V. Semenov       (JPL) */
/*     M.J. Spencer       (JPL) */
/*     W.L. Taber         (JPL) */
/*     F.S. Turner        (JPL) */
/*     E.D. Wright        (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 04-DEC-2015 (NJB) (BVS) (EDW) */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     Saved variables */


/*     Initial values */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "ZZSRFKER", (ftnlen)8);

/*     The primary functions performed inline in this routine are */

/*        - Setting a watch on the mapping kernel variables */

/*        - Fetching the mapping kernel variables' values */

/*        - Performing error checks on the kernel variables that define */
/*          the surface name/ID mapping. Initialization of data */
/*          structures is delegated to ZZSRFINI. */


    if (__state->pass1) {

/*        Set watch on kernel variables used for the surface mapping. */

	swpool_(__global_state, "ZZSRFTRN", &__state->c__3, __state->names, (
		ftnlen)8, (ftnlen)32);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "ZZSRFKER", (ftnlen)8);
	    return 0;
	}
	__state->pass1 = FALSE_;
    }

/*     Indicate that no data are available until we find out */
/*     otherwise. */

    *extker = FALSE_;
    *nkvar = 0;

/*     Fetch attributes of the surface mapping kernel variables. */

    dtpool_(__global_state, "NAIF_SURFACE_NAME", &fndnam, &nname, ndtype, (
	    ftnlen)17, (ftnlen)1);
    dtpool_(__global_state, "NAIF_SURFACE_CODE", &fndcde, &ncode, cdtype, (
	    ftnlen)17, (ftnlen)1);
    dtpool_(__global_state, "NAIF_SURFACE_BODY", &fndbod, &nbody, bdtype, (
	    ftnlen)17, (ftnlen)1);
    if (failed_(__global_state)) {
	chkout_(__global_state, "ZZSRFKER", (ftnlen)8);
	return 0;
    }

/*     The variables must all be present or all be absent. */

    if (fndcde != fndnam || fndbod != fndnam) {
	setmsg_(__global_state, "Surface mapping kernel variables are in an "
		"inconsistent state. # was #; # was #; # was #.", (ftnlen)89);
	errch_(__global_state, "#", "NAIF_SURFACE_NAME", (ftnlen)1, (ftnlen)
		17);
	if (fndnam) {
	    errch_(__global_state, "#", "found", (ftnlen)1, (ftnlen)5);
	} else {
	    errch_(__global_state, "#", "not found", (ftnlen)1, (ftnlen)9);
	}
	errch_(__global_state, "#", "NAIF_SURFACE_CODE", (ftnlen)1, (ftnlen)
		17);
	if (fndcde) {
	    errch_(__global_state, "#", "found", (ftnlen)1, (ftnlen)5);
	} else {
	    errch_(__global_state, "#", "not found", (ftnlen)1, (ftnlen)9);
	}
	errch_(__global_state, "#", "NAIF_SURFACE_BODY", (ftnlen)1, (ftnlen)
		17);
	if (fndbod) {
	    errch_(__global_state, "#", "found", (ftnlen)1, (ftnlen)5);
	} else {
	    errch_(__global_state, "#", "not found", (ftnlen)1, (ftnlen)9);
	}
	sigerr_(__global_state, "SPICE(BADSURFACEMAP)", (ftnlen)20);
	chkout_(__global_state, "ZZSRFKER", (ftnlen)8);
	return 0;
    }

/*     If the variables are not present, leave now. */

    *extker = fndnam && fndcde && fndbod;
    if (! (*extker)) {
	chkout_(__global_state, "ZZSRFKER", (ftnlen)8);
	return 0;
    }

/*     Make sure the kernel variables aren't larger than our arrays. */
/*     Also make sure the variable have matching dimensions. */

/*     Check variable types. */

    if (*(unsigned char *)ndtype != 'C' || *(unsigned char *)cdtype != 'N' || 
	    *(unsigned char *)bdtype != 'N') {
	setmsg_(__global_state, "Surface mapping kernel variable types are: "
		"# = #; # = #; # = #. These types must be, respectively, 'C',"
		" 'N', 'N'.", (ftnlen)113);
	errch_(__global_state, "#", "NAIF_SURFACE_NAME", (ftnlen)1, (ftnlen)
		17);
	errch_(__global_state, "#", ndtype, (ftnlen)1, (ftnlen)1);
	errch_(__global_state, "#", "NAIF_SURFACE_CODE", (ftnlen)1, (ftnlen)
		17);
	errch_(__global_state, "#", cdtype, (ftnlen)1, (ftnlen)1);
	errch_(__global_state, "#", "NAIF_SURFACE_BODY", (ftnlen)1, (ftnlen)
		17);
	errch_(__global_state, "#", bdtype, (ftnlen)1, (ftnlen)1);
	sigerr_(__global_state, "SPICE(BADVARIABLETYPE)", (ftnlen)22);
	chkout_(__global_state, "ZZSRFKER", (ftnlen)8);
	return 0;
    }

/*     Check variable dimensions. */

    if (nname > 2000 || ncode > 2000 || nbody > 2000) {
	setmsg_(__global_state, "Surface mapping kernel variable sizes are: "
		"# = #; # = #; # = #. Maximum allowed size is #.", (ftnlen)90);
	errch_(__global_state, "#", "NAIF_SURFACE_NAME", (ftnlen)1, (ftnlen)
		17);
	errint_(__global_state, "#", &nname, (ftnlen)1);
	errch_(__global_state, "#", "NAIF_SURFACE_CODE", (ftnlen)1, (ftnlen)
		17);
	errint_(__global_state, "#", &ncode, (ftnlen)1);
	errch_(__global_state, "#", "NAIF_SURFACE_BODY", (ftnlen)1, (ftnlen)
		17);
	errint_(__global_state, "#", &nbody, (ftnlen)1);
	errint_(__global_state, "#", &__state->c__2000, (ftnlen)1);
	sigerr_(__global_state, "SPICE(TOOMANYSURFACES)", (ftnlen)22);
	chkout_(__global_state, "ZZSRFKER", (ftnlen)8);
	return 0;
    }
    if (ncode != nname || nbody != nname) {
	setmsg_(__global_state, "Surface variable sizes do not match. Size o"
		"f # is #; size of # is #; size of # is #.", (ftnlen)84);
	errch_(__global_state, "#", "NAIF_SURFACE_NAME", (ftnlen)1, (ftnlen)
		17);
	errint_(__global_state, "#", &nname, (ftnlen)1);
	errch_(__global_state, "#", "NAIF_SURFACE_CODE", (ftnlen)1, (ftnlen)
		17);
	errint_(__global_state, "#", &ncode, (ftnlen)1);
	errch_(__global_state, "#", "NAIF_SURFACE_BODY", (ftnlen)1, (ftnlen)
		17);
	errint_(__global_state, "#", &nbody, (ftnlen)1);
	sigerr_(__global_state, "SPICE(ARRAYSIZEMISMATCH)", (ftnlen)24);
	chkout_(__global_state, "ZZSRFKER", (ftnlen)8);
	return 0;
    }

/*     Fetch mapping variables. */

/*     Note that we'll check the variable sizes below. */

    gcpool_(__global_state, "NAIF_SURFACE_NAME", &__state->c__1, &
	    __state->c__2000, &nname, kernam, &fndnam, (ftnlen)17, (ftnlen)36)
	    ;
    gipool_(__global_state, "NAIF_SURFACE_CODE", &__state->c__1, &
	    __state->c__2000, &ncode, kersid, &fndcde, (ftnlen)17);
    gipool_(__global_state, "NAIF_SURFACE_BODY", &__state->c__1, &
	    __state->c__2000, &nbody, kerbid, &fndbod, (ftnlen)17);
    if (failed_(__global_state)) {
	chkout_(__global_state, "ZZSRFKER", (ftnlen)8);
	return 0;
    }
    *nkvar = nname;

/*     Produce normalized name array. Check for blank names */
/*     as we go. */

    i__1 = *nkvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (s_cmp(&__global_state->f2c, kernam + (i__ - 1) * 36, " ", (ftnlen)
		36, (ftnlen)1) == 0) {
	    setmsg_(__global_state, "An attempt to assign the code, #, to a "
		    "blank string was made.  Check loaded text kernels for a "
		    "blank string in the NAIF_SURFACE_NAME array.", (ftnlen)
		    139);
	    errint_(__global_state, "#", &i__, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(BLANKNAMEASSIGNED)", (ftnlen)24);
	    chkout_(__global_state, "ZZSRFKER", (ftnlen)8);
	    return 0;
	}
	ljucrs_(__global_state, &__state->c__1, kernam + (i__ - 1) * 36, 
		nornam + (i__ - 1) * 36, (ftnlen)36, (ftnlen)36);
    }

/*     Initialize hash data structures. */

    zzsrfini_(__global_state, nornam, kersid, kerbid, nkvar, &
	    __state->c__2003, snmhls, snmpol, snmidx, sidhls, sidpol, sididx, 
	    (ftnlen)36);
    chkout_(__global_state, "ZZSRFKER", (ftnlen)8);
    return 0;
} /* zzsrfker_ */

