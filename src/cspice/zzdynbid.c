/* zzdynbid.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzdynbid_init_t __zzdynbid_init;
static zzdynbid_state_t* get_zzdynbid_state(cspice_t* state) {
	if (!state->zzdynbid)
		state->zzdynbid = __cspice_allocate_module(sizeof(
	zzdynbid_state_t), &__zzdynbid_init, sizeof(__zzdynbid_init));
	return state->zzdynbid;

}

/* $Procedure ZZDYNBID ( Fetch body ID kernel variable ) */
/* Subroutine */ int zzdynbid_(cspice_t* __global_state, char *frname, 
	integer *frcode, char *item, integer *idcode, ftnlen frname_len, 
	ftnlen item_len)
{
    integer n;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int repmc_(cspice_t*, char *, char *, char *, 
	    char *, ftnlen, ftnlen, ftnlen, ftnlen);
    logical found;
    extern /* Subroutine */ int repmi_(cspice_t*, char *, char *, integer *, 
	    char *, ftnlen, ftnlen, ftnlen);
    char dtype[1];
    extern integer rtrim_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int bods2c_(cspice_t*, char *, integer *, logical 
	    *, ftnlen);
    extern logical failed_(cspice_t*);
    char bodnam[36];
    integer codeln;
    integer nameln;
    char kvname[32];
    char cdestr[32];
    integer itemln;
    integer reqnam;
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);
    integer reqnum;
    extern /* Subroutine */ int intstr_(cspice_t*, integer *, char *, ftnlen);
    extern /* Subroutine */ int dtpool_(cspice_t*, char *, logical *, integer 
	    *, char *, ftnlen, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int gcpool_(cspice_t*, char *, integer *, integer 
	    *, integer *, char *, logical *, ftnlen, ftnlen);
    extern /* Subroutine */ int gipool_(cspice_t*, char *, integer *, integer 
	    *, integer *, integer *, logical *, ftnlen);


    /* Module state */
    zzdynbid_state_t* __state = get_zzdynbid_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Look up a frame definition kernel variable whose associated value */
/*     is a body name or body ID code.  The returned value is always an */
/*     ID code.  The frame name or frame ID may be used as part of the */
/*     variable's name. */

/*     If the kernel variable is not present, or if the variable */
/*     is not a body name or a numeric value, signal an error. */

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

/*     FRAMES */
/*     KERNEL */
/*     PRIVATE */
/*     UTILITY */

/* $ Declarations */
/* $ Abstract */

/*     This include file lists the parameter collection */
/*     defining the number of SPICE ID -> NAME mappings. */

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

/*     MAXL        is the maximum length of a body name. */

/*     MAXP        is the maximum number of additional names that may */
/*                 be added via the ZZBODDEF interface. */

/*     NPERM       is the count of the mapping assignments built into */
/*                 SPICE. */

/*     MAXE        is the size of the lists and hashes storing combined */
/*                 built-in and ZZBODDEF-defined name/ID mappings. To */
/*                 ensure efficient hashing this size is the set to the */
/*                 first prime number greater than ( MAXP + NPERM ). */

/*     NROOM       is the size of the lists and hashes storing the */
/*                 POOL-defined name/ID mappings. To ensure efficient */
/*                 hashing and to provide the ability to store nearly as */
/*                 many names as can fit in the POOL, this size is */
/*                 set to the first prime number less than MAXLIN */
/*                 defined in the POOL umbrella routine. */

/* $ Required_Reading */

/*     naif_ids.req */

/* $ Keywords */

/*     BODY */
/*     CONVERSION */

/* $ Author_and_Institution */

/*     B.V. Semenov (JPL) */
/*     E.D. Wright  (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 04-APR-2017 (BVS)(EDW) */

/*        Increased NROOM to 14983. Added a comment note explaining */
/*        NROOM and MAXE */

/* -    SPICELIB Version 1.0.0, 20-MAY-2010 (EDW) */

/*        N0064 version with MAXP = 150, NPERM = 563, */
/*        MAXE = MAXP + NPERM, and NROOM = 2000. */

/*     A script generates this file. Do not edit by hand. */
/*     Edit the creation script to modify the contents of */
/*     ZZBODTRN.INC. */


/*     Maximum size of a NAME string */


/*     Maximum number of additional names that may be added via the */
/*     ZZBODDEF interface. */


/*     Count of default SPICE mapping assignments. */


/*     Size of the lists and hashes storing the built-in and */
/*     ZZBODDEF-defined name/ID mappings. To ensure efficient hashing */
/*     this size is the set to the first prime number greater than */
/*     ( MAXP + NPERM ). */


/*     Size of the lists and hashes storing the POOL-defined name/ID */
/*     mappings. To ensure efficient hashing and to provide the ability */
/*     to store nearly as many names as can fit in the POOL, this size */
/*     is set to the first prime number less than MAXLIN defined in */
/*     the POOL umbrella routine. */

/* $ Abstract */

/*     Include file zzdyn.inc */

/*     SPICE private file intended solely for the support of SPICE */
/*     routines.  Users should not include this file directly due */
/*     to the volatile nature of this file */

/*     The parameters defined below are used by the SPICELIB dynamic */
/*     frame subsystem. */

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

/*     This file declares parameters required by the dynamic */
/*     frame routines of the SPICELIB frame subsystem. */

/* $ Restrictions */

/*     The parameter BDNMLN is this routine must be kept */
/*     consistent with the parameter MAXL defined in */

/*        zzbodtrn.inc */


/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 12-JAN-2005 (NJB) */

/*        Parameters KWX, KWY, KWZ renamed to KVX, KVY, KVZ. */

/* -    SPICELIB Version 1.0.0, 22-DEC-2004 (NJB) */

/* -& */

/*     String length parameters */
/*     ======================== */


/*     Kernel variable name length.  This parameter must be */
/*     kept consistent with the parameter MAXLEN used in the */
/*     POOL umbrella routine. */


/*     Length of a character kernel pool datum. This parameter must be */
/*     kept consistent with the parameter MAXCHR used in the POOL */
/*     umbrella routine. */


/*     Reference frame name length.  This parameter must be */
/*     kept consistent with the parameter WDSIZE used in the */
/*     FRAMEX umbrella routine. */


/*     Body name length.  This parameter is used to provide a level */
/*     of indirection so the dynamic frame source code doesn't */
/*     have to change if the name of this SPICELIB-scope parameter */
/*     is changed.  The value MAXL used here is defined in the */
/*     INCLUDE file */

/*        zzbodtrn.inc */

/*     Current value of MAXL = 36 */


/*     Numeric parameters */
/*     =================================== */

/*     The parameter MAXCOF is the maximum number of polynomial */
/*     coefficients that may be used to define an Euler angle */
/*     in an "Euler frame" definition */


/*     The parameter LBSEP is the default angular separation limit for */
/*     the vectors defining a two-vector frame.  The angular separation */
/*     of the vectors must differ from Pi and 0 by at least this amount. */


/*     The parameter QEXP is used to determine the width of */
/*     the interval DELTA used for the discrete differentiation */
/*     of velocity in the routines ZZDYNFRM, ZZDYNROT, and their */
/*     recursive analogs.  This parameter is appropriate for */
/*     64-bit IEEE double precision numbers; when SPICELIB */
/*     is hosted on platforms where longer mantissas are supported, */
/*     this parameter (and hence this INCLUDE file) will become */
/*     platform-dependent. */

/*     The choice of QEXP is based on heuristics.  It's believed to */
/*     be a reasonable choice obtainable without expensive computation. */

/*     QEXP is the largest power of 2 such that */

/*        1.D0 + 2**QEXP  =  1.D0 */

/*     Given an epoch T0 at which a discrete derivative is to be */
/*     computed, this choice provides a value of DELTA that usually */
/*     contributes no round-off error in the computation of the function */
/*     evaluation epochs */

/*        T0 +/- DELTA */

/*     while providing the largest value of DELTA having this form that */
/*     causes the order of the error term O(DELTA**2) in the quadratric */
/*     function approximation to round to zero.  Note that the error */
/*     itself will normally be small but doesn't necessarily round to */
/*     zero.  Note also that the small function approximation error */
/*     is not a measurement of the error in the discrete derivative */
/*     itself. */

/*     For ET values T0 > 2**27 seconds past J2000, the value of */
/*     DELTA will be set to */

/*        T0 * 2**QEXP */

/*     For smaller values of T0, DELTA should be set to 1.D0. */


/*     Frame kernel parameters */
/*     ======================= */

/*     Parameters relating to kernel variable names (keywords) start */
/*     with the letters */

/*        KW */

/*     Parameters relating to kernel variable values start with the */
/*     letters */

/*        KV */


/*     Generic parameters */
/*     --------------------------------- */

/*     Token used to build the base frame keyword: */


/*     Frame definition style parameters */
/*     --------------------------------- */

/*     Token used to build the frame definition style keyword: */


/*     Token indicating parameterized dynamic frame. */


/*     Freeze epoch parameters */
/*     --------------------------------- */

/*     Token used to build the freeze epoch keyword: */


/*     Rotation state parameters */
/*     --------------------------------- */

/*     Token used to build the rotation state keyword: */


/*     Token indicating rotating rotation state: */


/*     Token indicating inertial rotation state: */


/*     Frame family parameters */
/*     --------------------------------- */

/*     Token used to build the frame family keyword: */


/*     Token indicating mean equator and equinox of date frame. */


/*     Token indicating mean ecliptic and equinox of date frame. */


/*     Token indicating true equator and equinox of date frame. */


/*     Token indicating two-vector frame. */


/*     Token indicating Euler frame. */


/*     "Of date" frame family parameters */
/*     --------------------------------- */

/*     Token used to build the precession model keyword: */


/*     Token used to build the nutation model keyword: */


/*     Token used to build the obliquity model keyword: */


/*     Mathematical models used to define "of date" frames will */
/*     likely accrue over time.  We will simply assign them */
/*     numbers. */


/*     Token indicating the Lieske earth precession model: */


/*     Token indicating the IAU 1980 earth nutation model: */


/*     Token indicating the IAU 1980 earth mean obliqity of */
/*     date model.  Note the name matches that of the preceding */
/*     nutation model---this is intentional.  The keyword */
/*     used in the kernel variable definition indicates what */
/*     kind of model is being defined. */


/*     Two-vector frame family parameters */
/*     --------------------------------- */

/*     Token used to build the vector axis keyword: */


/*     Tokens indicating axis values: */


/*     Prefixes used for primary and secondary vector definition */
/*     keywords: */


/*     Token used to build the vector definition keyword: */


/*     Token indicating observer-target position vector: */


/*     Token indicating observer-target velocity vector: */


/*     Token indicating observer-target near point vector: */


/*     Token indicating constant vector: */


/*     Token used to build the vector observer keyword: */


/*     Token used to build the vector target keyword: */


/*     Token used to build the vector frame keyword: */


/*     Token used to build the vector aberration correction keyword: */


/*     Token used to build the constant vector specification keyword: */


/*     Token indicating rectangular coordinates used to */
/*     specify constant vector: */


/*     Token indicating latitudinal coordinates used to */
/*     specify constant vector: */


/*     Token indicating RA/DEC coordinates used to */
/*     specify constant vector: */


/*     Token used to build the cartesian vector literal keyword: */


/*     Token used to build the constant vector latitude keyword: */


/*     Token used to build the constant vector longitude keyword: */


/*     Token used to build the constant vector right ascension keyword: */


/*     Token used to build the constant vector declination keyword: */


/*     Token used to build the angular separation tolerance keyword: */


/*     See the section "Physical unit parameters" below for additional */
/*     parameters applicable to two-vector frames. */


/*     Euler frame family parameters */
/*     --------------------------------- */

/*     Token used to build the epoch keyword: */


/*     Token used to build the Euler axis sequence keyword: */


/*     Tokens used to build the Euler angle coefficients keywords: */


/*     See the section "Physical unit parameters" below for additional */
/*     parameters applicable to Euler frames. */


/*     Physical unit parameters */
/*     --------------------------------- */

/*     Token used to build the units keyword: */


/*     Token indicating radians: */


/*     Token indicating degrees: */


/*     End of include file zzdyn.inc */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  ------------------------------------------------- */
/*     FRNAME     I   Frame name. */
/*     FRCODE     I   Frame ID code. */
/*     ITEM       I   Item associated with frame definition. */
/*     IDCODE     O   Body ID code. */

/* $ Detailed_Input */

/*     FRNAME         is the name of the reference frame with which */
/*                    the requested variable is associated. */

/*     FRCODE         is the frame ID code of the reference frame with */
/*                    which the requested variable is associated. */

/*     ITEM           is a string identifying the specific datum */
/*                    to be fetched.  The kernel variable name */
/*                    has the form */

/*                       FRAME_<frame ID code>_<ITEM> */

/*                    or */

/*                       FRAME_<frame name>_<ITEM> */

/*                    The former of the two names takes precedence: */
/*                    this routine will look for a numeric variable */
/*                    of that name first. */

/*                    The value associated with the kernel variable */
/*                    must be one of */

/*                       - a nbody ID code */

/*                       - a string representation of an integer, */
/*                         for example '5' */

/*                       - a body frame name */

/* $ Detailed_Output */

/*     IDCODE         is the requested body ID code. */

/*                    The kernel variable name of the form */

/*                       FRAME_<frame ID code>_<ITEM> */

/*                    will be looked up first; if this variable */
/*                    is found and has numeric type, the associated */
/*                    value will be returned.  If this variable is */
/*                    found and has character type, the value will */
/*                    be converted to a body ID code, and that */
/*                    code will be returned. */

/*                    If this variable is not found, the variable */

/*                       FRAME_<frame name>_<ITEM> */

/*                    will be looked up.  If this variable is found and */
/*                    has numeric type, the associated value will be */
/*                    returned.  If this variable is found and has */
/*                    character type, the value will be converted to a */
/*                    body ID code, and that code will be returned. */

/*                    If a numeric value associated with the selected */
/*                    kernel variable is not integral, it will be */
/*                    rounded to the closest integer. */

/* $ Parameters */

/*     See zzdyn.inc for definition of KVNMLN. */

/* $ Exceptions */

/*     1) If neither the frame-ID-based or frame-name-based form of the */
/*        requested kernel variable name matches a kernel variable */
/*        present in the kernel pool, the error SPICE(KERNELVARNOTFOUND) */
/*        will be signaled. */

/*     2) If either the frame-ID-based or frame-name-based form of the */
/*        requested kernel variable name has length greater than KVNMLN, */
/*        that variable will not be searched for. */

/*     3) If both the frame-ID-based and frame-name-based forms of the */
/*        requested kernel variable name have length greater than KVNMLN, */
/*        the error SPICE(VARNAMETOOLONG) will be signaled. */

/*     4) If kernel variable matching one form of the requested kernel */
/*        variable names is found, but that variable has more than 1 */
/*        associated value, the error SPICE(BADVARIABLESIZE) will be */
/*        signaled. */

/*     5) If a name match is found for a character kernel variable, but */
/*        the value associated with the variable cannot be mapped to a */
/*        body ID code, the error SPICE(NOTRANSLATION) will be */
/*        signaled. */

/*     6) If a name match is found for a numeric kernel variable, */
/*        but that variable has a value that cannot be rounded to an */
/*        integer representable on the host platform, an error will */
/*        be signaled by a routine in the call tree of this routine. */

/* $ Files */

/*     1) Kernel variables fetched by this routine are normally */
/*        introduced into the kernel pool by loading one or more */
/*        frame kernels.  See the Frames Required Reading for */
/*        details. */

/* $ Particulars */

/*     This routine centralizes logic for kernel variable lookups that */
/*     must be performed by the SPICELIB frame subsystem. Part of the */
/*     functionality of this routine consists of handling error */
/*     conditions such as the unavailability of required kernel */
/*     variables; hence no "found" flag is returned to the caller. */

/*     As indicated above, the requested kernel variable may have a name */
/*     of the form */

/*        FRAME_<frame ID code>_<ITEM> */

/*     or */

/*        FRAME_<frame name>_<ITEM> */

/*     Because most frame definition keywords have the first form, this */
/*     routine looks for a name of that form first. */

/*     Note that although this routine considers the two forms of the */
/*     names to be synonymous, from the point of view of the kernel pool */
/*     access routines, these names are distinct.  Hence kernel */
/*     variables having names of both forms, but having possibly */
/*     different attributes, can be simultaneously present in the kernel */
/*     pool. Intentional use of this kernel pool feature is discouraged. */

/* $ Examples */

/*     1) See ZZDYNFRM. */

/*     2) Applications of this routine include finding ID codes of */
/*        observer or target bodies serving to define two-vector dynamic */
/*        frames. */

/* $ Restrictions */

/*     1) This is a SPICE private routine; the routine is subject */
/*        to change without notice.  User applications should not */
/*        call this routine. */

/*     2) An array-valued kernel variable matching the "ID code form" */
/*        of the requested kernel variable name could potentially */
/*        mask a scalar-valued kernel variable matching the "name */
/*        form" of the requested name.  This problem can be prevented */
/*        by sensible frame kernel design. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 05-AUG-2005 (NJB) */

/*        References to parameterized dynamic frames in long error */
/*        messages were changed to references to "reference frames." */
/*        This change was made to enable this utility to support */
/*        kernel variable look-ups for non-dynamic frames. */

/* -    SPICELIB Version 1.0.0, 18-DEC-2004 (NJB) */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 2.0.0, 05-AUG-2005 (NJB) */

/*        References to parameterized dynamic frames in long error */
/*        messages were changed to references to "reference frames." */
/*        This change was made to enable this utility to support */
/*        kernel variable look-ups for non-dynamic frames. */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     TEMPLN is the length of the keyword template, minus */
/*     the sum of the lengths of the two substitution markers ('#'). */


/*     Local variables */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "ZZDYNBID", (ftnlen)8);

/*     Prepare to check the name of the kernel variable we're about */
/*     to look up. */

/*     Convert the frame code to a string. */

    intstr_(__global_state, frcode, cdestr, (ftnlen)32);
    if (failed_(__global_state)) {
	chkout_(__global_state, "ZZDYNBID", (ftnlen)8);
	return 0;
    }

/*     Get the lengths of the input frame code, name and item. */
/*     Compute the length of the ID-based kernel variable name; */
/*     check this length against the maximum allowed value.  If */
/*     the name is too long, proceed to look up the form of the */
/*     kernel variable name based on the frame name. */

    codeln = rtrim_(__global_state, cdestr, (ftnlen)32);
    nameln = rtrim_(__global_state, frname, frname_len);
    itemln = rtrim_(__global_state, item, item_len);
    reqnum = codeln + itemln + 7;
    if (reqnum <= 32) {

/*        First try looking for a kernel variable including the frame ID */
/*        code. */

/*        Note the template is */

/*            'FRAME_#_#' */

	repmi_(__global_state, "FRAME_#_#", "#", frcode, kvname, (ftnlen)9, (
		ftnlen)1, (ftnlen)32);
	repmc_(__global_state, kvname, "#", item, kvname, (ftnlen)32, (ftnlen)
		1, item_len, (ftnlen)32);
	dtpool_(__global_state, kvname, &found, &n, dtype, (ftnlen)32, (
		ftnlen)1);
    } else {

/*        The ID-based name is too long. We can't find the variable if */
/*        we can't look it up. */

	found = FALSE_;
    }
    if (! found) {

/*        We need to look up the frame name-based kernel variable. */
/*        Determine the length of the name of this variable; make */
/*        sure it's not too long. */

	reqnam = nameln + itemln + 7;
	if (reqnam > 32 && reqnum > 32) {

/*           Both forms of the name are too long. */

	    setmsg_(__global_state, "Kernel variable FRAME_#_# has length #;"
		    " kernel variable FRAME_#_# has length #; maximum allowed"
		    " length is #.  Neither variable could be searched for in"
		    " the kernel pool due to these name length errors.", (
		    ftnlen)200);
	    errint_(__global_state, "#", frcode, (ftnlen)1);
	    errch_(__global_state, "#", item, (ftnlen)1, item_len);
	    errint_(__global_state, "#", &reqnum, (ftnlen)1);
	    errch_(__global_state, "#", frname, (ftnlen)1, frname_len);
	    errch_(__global_state, "#", item, (ftnlen)1, item_len);
	    errint_(__global_state, "#", &reqnam, (ftnlen)1);
	    errint_(__global_state, "#", &__state->c__32, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(VARNAMETOOLONG)", (ftnlen)21);
	    chkout_(__global_state, "ZZDYNBID", (ftnlen)8);
	    return 0;
	} else if (reqnam > 32) {

/*           We couldn't find the variable having the ID-based name, */
/*           and the frame name-based variable name is too long to */
/*           look up. */

/*           Note that at this point KVNAME contains the ID-based */
/*           kernel variable name. */

	    setmsg_(__global_state, "Kernel variable # was expected to be pr"
		    "esent in the kernel pool but was not found.  The alterna"
		    "tive form of kernel variable name FRAME_#_# was not sear"
		    "ched for because this name has excessive length (# chara"
		    "cters vs allowed maximum of #).  One of these variables "
		    "is needed to define the reference frame #.  Usually this"
		    " type of problem is due to a missing keyword assignment "
		    "in a frame kernel.  Another, less likely, possibility is"
		    " that other errors in a frame kernel have confused the f"
		    "rame subsystem into wrongly deciding these variables are"
		    " needed.", (ftnlen)551);
	    errch_(__global_state, "#", kvname, (ftnlen)1, (ftnlen)32);
	    errch_(__global_state, "#", frname, (ftnlen)1, frname_len);
	    errch_(__global_state, "#", item, (ftnlen)1, item_len);
	    errint_(__global_state, "#", &reqnam, (ftnlen)1);
	    errint_(__global_state, "#", &__state->c__32, (ftnlen)1);
	    errch_(__global_state, "#", frname, (ftnlen)1, frname_len);
	    sigerr_(__global_state, "SPICE(KERNELVARNOTFOUND)", (ftnlen)24);
	    chkout_(__global_state, "ZZDYNBID", (ftnlen)8);
	    return 0;
	}

/*        Now try looking for a kernel variable including the frame */
/*        name. */

	repmc_(__global_state, "FRAME_#_#", "#", frname, kvname, (ftnlen)9, (
		ftnlen)1, frname_len, (ftnlen)32);
	repmc_(__global_state, kvname, "#", item, kvname, (ftnlen)32, (ftnlen)
		1, item_len, (ftnlen)32);
	dtpool_(__global_state, kvname, &found, &n, dtype, (ftnlen)32, (
		ftnlen)1);
	if (! found && reqnum > 32) {

/*           The kernel variable's presence (in one form or the other) */
/*           is mandatory:  signal an error.  The error message */
/*           depends on which variables we were able to try to */
/*           look up.  In this case, we never tried to look up the */
/*           frame ID-based name. */

/*           Note that at this point KVNAME contains the name-based */
/*           kernel variable name. */

	    setmsg_(__global_state, "Kernel variable # was expected to be pr"
		    "esent in the kernel pool but was not found.  The alterna"
		    "tive form of kernel variable name FRAME_#_# was not sear"
		    "ched for because this name has excessive length (# chara"
		    "cters vs allowed maximum of #).  One of these variables "
		    "is needed to define the reference frame #.  Usually this"
		    " type of problem is due to a missing keyword assignment "
		    "in a frame kernel.  Another, less likely, possibility is"
		    " that other errors in a frame kernel have confused the f"
		    "rame subsystem into wrongly deciding these variables are"
		    " needed.", (ftnlen)551);
	    errch_(__global_state, "#", kvname, (ftnlen)1, (ftnlen)32);
	    errint_(__global_state, "#", frcode, (ftnlen)1);
	    errch_(__global_state, "#", item, (ftnlen)1, item_len);
	    errint_(__global_state, "#", &reqnum, (ftnlen)1);
	    errint_(__global_state, "#", &__state->c__32, (ftnlen)1);
	    errch_(__global_state, "#", frname, (ftnlen)1, frname_len);
	    sigerr_(__global_state, "SPICE(KERNELVARNOTFOUND)", (ftnlen)24);
	    chkout_(__global_state, "ZZDYNBID", (ftnlen)8);
	    return 0;
	} else if (! found) {

/*           We tried to look up both names and failed. */

	    setmsg_(__global_state, "At least one of the kernel variables FR"
		    "AME_#_# or FRAME_#_# was expected to be present in the k"
		    "ernel pool but neither was found. One of these variables"
		    " is needed to define the reference frame #.  Usually thi"
		    "s type of problem is due to a missing keyword assignment"
		    " in a frame kernel.  Another, less likely, possibility i"
		    "s that other errors in a frame kernel have confused the "
		    "frame subsystem into wrongly deciding these variables ar"
		    "e needed.", (ftnlen)440);
	    errint_(__global_state, "#", frcode, (ftnlen)1);
	    errch_(__global_state, "#", item, (ftnlen)1, item_len);
	    errch_(__global_state, "#", frname, (ftnlen)1, frname_len);
	    errch_(__global_state, "#", item, (ftnlen)1, item_len);
	    errch_(__global_state, "#", frname, (ftnlen)1, frname_len);
	    sigerr_(__global_state, "SPICE(KERNELVARNOTFOUND)", (ftnlen)24);
	    chkout_(__global_state, "ZZDYNBID", (ftnlen)8);
	    return 0;
	}
    }

/*     Getting to this point means we found a kernel variable. The name */
/*     of the variable is KVNAME.  The data type is DTYPE and the */
/*     cardinality is N. */

    if (*(unsigned char *)dtype == 'C') {

/*        Rather than using BADKPV, we check the cardinality of the */
/*        kernel variable in-line so we can create a more detailed error */
/*        message if need be. */

	if (n > 1) {
	    setmsg_(__global_state, "The kernel variable # has used to defin"
		    "e frame # was expected to have size not exceeding 1 but "
		    "in fact has size #. Usually this type of problem is due "
		    "to an error in a frame definition provided in a frame ke"
		    "rnel.", (ftnlen)212);
	    errch_(__global_state, "#", kvname, (ftnlen)1, (ftnlen)32);
	    errch_(__global_state, "#", frname, (ftnlen)1, frname_len);
	    errint_(__global_state, "#", &n, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(BADVARIABLESIZE)", (ftnlen)22);
	    chkout_(__global_state, "ZZDYNBID", (ftnlen)8);
	    return 0;
	}

/*        Look up the kernel variable. */

	gcpool_(__global_state, kvname, &__state->c__1, &__state->c__1, &n, 
		bodnam, &found, (ftnlen)32, (ftnlen)36);
	if (! found) {
	    setmsg_(__global_state, "Variable # not found after DTPOOL indic"
		    "ated it was present in pool.", (ftnlen)67);
	    errch_(__global_state, "#", kvname, (ftnlen)1, (ftnlen)32);
	    sigerr_(__global_state, "SPICE(BUG)", (ftnlen)10);
	    chkout_(__global_state, "ZZDYNBID", (ftnlen)8);
	    return 0;
	}

/*        Convert the body name to a body code. */

	bods2c_(__global_state, bodnam, idcode, &found, (ftnlen)36);
	if (! found) {
	    setmsg_(__global_state, "Body name # could not be translated to "
		    "an ID code.", (ftnlen)50);
	    errch_(__global_state, "#", bodnam, (ftnlen)1, (ftnlen)36);
	    sigerr_(__global_state, "SPICE(NOTRANSLATION)", (ftnlen)20);
	    chkout_(__global_state, "ZZDYNBID", (ftnlen)8);
	    return 0;
	}
    } else {

/*        The variable has numeric type. */

	if (n > 1) {
	    setmsg_(__global_state, "The kernel variable # has used to defin"
		    "e frame # was expected to have size not exceeding 1 but "
		    "in fact has size #. Usually this type of problem is due "
		    "to an error in a frame definition provided in a frame ke"
		    "rnel.", (ftnlen)212);
	    errch_(__global_state, "#", kvname, (ftnlen)1, (ftnlen)32);
	    errch_(__global_state, "#", frname, (ftnlen)1, frname_len);
	    errint_(__global_state, "#", &n, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(BADVARIABLESIZE)", (ftnlen)22);
	    chkout_(__global_state, "ZZDYNBID", (ftnlen)8);
	    return 0;
	}

/*        Look up the kernel variable. */

	gipool_(__global_state, kvname, &__state->c__1, &__state->c__1, &n, 
		idcode, &found, (ftnlen)32);
	if (! found) {
	    setmsg_(__global_state, "Variable # not found after DTPOOL indic"
		    "ated it was present in pool.", (ftnlen)67);
	    errch_(__global_state, "#", kvname, (ftnlen)1, (ftnlen)32);
	    sigerr_(__global_state, "SPICE(BUG)", (ftnlen)10);
	    chkout_(__global_state, "ZZDYNBID", (ftnlen)8);
	    return 0;
	}
    }
    chkout_(__global_state, "ZZDYNBID", (ftnlen)8);
    return 0;
} /* zzdynbid_ */

