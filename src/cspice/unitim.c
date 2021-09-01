/* unitim.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern unitim_init_t __unitim_init;
static unitim_state_t* get_unitim_state(cspice_t* state) {
	if (!state->unitim)
		state->unitim = __cspice_allocate_module(sizeof(
	unitim_state_t), &__unitim_init, sizeof(__unitim_init));
	return state->unitim;

}

/* $Procedure      UNITIM ( Uniform time scale transformation ) */
doublereal unitim_(cspice_t* __global_state, doublereal *epoch, char *insys, 
	char *outsys, ftnlen insys_len, ftnlen outsys_len)
{
    /* Initialized data */


    /* System generated locals */
    address a__1[14];
    integer i__1[14], i__2;
    doublereal ret_val;
    char ch__1[714];

    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen),
	     s_cat(f2c_state_t*, char *, char **, integer *, integer *, 
	    ftnlen);
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer), s_cmp(
	    f2c_state_t*, char *, char *, ftnlen, ftnlen);
    double sin(doublereal);

    /* Local variables */
    extern logical setc_(cspice_t*, char *, char *, char *, ftnlen, ftnlen, 
	    ftnlen);
    char myin[8];
    extern /* Subroutine */ int zzcvpool_(cspice_t*, char *, integer *, 
	    logical *, ftnlen);
    extern /* Subroutine */ int zzctruin_(cspice_t*, integer *);
    integer i__;
    integer n;
    extern logical elemc_(cspice_t*, char *, char *, ftnlen, ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    logical intdb;
    extern /* Subroutine */ int ucase_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    logical found[4];
    logical intdt;
    char types[8*8];
    char myout[8];
    extern logical failed_(cspice_t*);
    extern /* Subroutine */ int validc_(cspice_t*, integer *, integer *, char 
	    *, ftnlen);
    logical update;
    extern /* Subroutine */ int gdpool_(cspice_t*, char *, integer *, integer 
	    *, integer *, doublereal *, logical *, ftnlen);
    extern /* Subroutine */ int unionc_(cspice_t*, char *, char *, char *, 
	    ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int ssizec_(cspice_t*, integer *, char *, ftnlen);
    logical outtdb;
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical somfls_(cspice_t*, logical *, integer *);
    doublereal mytime;
    extern /* Subroutine */ int insrtc_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern logical return_(cspice_t*);
    logical outtdt;
    extern /* Subroutine */ int swpool_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    extern doublereal j2000_(cspice_t*);
    doublereal tdb;
    extern doublereal spd_(cspice_t*);
    doublereal tdt;

    /* Module state */
    unitim_state_t* __state = get_unitim_state(__global_state);
/* $ Abstract */

/*     Transform time from one uniform scale to another.  The uniform */
/*     time scales are TAI, TDT, TDB, ET, JED, JDTDB, JDTDT. */

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

/*     TIME */

/* $ Keywords */

/*     TIME */
/*     CONVERSION */
/*     UTILITY */

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
/*     EPOCH      I   An epoch. */
/*     INSYS      I   The time scale associated with the input EPOCH. */
/*     OUTSYS     I   The time scale associated with the function value. */

/*     The function returns the d.p. in OUTSYS that is equivalent to the */
/*     EPOCH on the INSYS time scale. */

/* $ Detailed_Input */

/*     EPOCH      is an epoch relative to the INSYS time scale. */

/*     INSYS      is a time scale.  Acceptable values are: */

/*                'TAI'     International Atomic Time. */
/*                'TDB'     Barycentric Dynamical Time. */
/*                'TDT'     Terrestrial Dynamical Time. */
/*                'ET'      Ephemeris time (in the SPICE system, this is */
/*                          equivalent to TDB). */
/*                'JDTDB'   Julian Date relative to TDB. */
/*                'JDTDT'   Julian Date relative to TDT. */
/*                'JED'     Julian Ephemeris date (in the SPICE system */
/*                          this is equivalent to JDTDB). */

/*                The routine is not sensitive to the case of the */
/*                characters in INSYS;  'tai' 'Tai' and 'TAI' are */
/*                all equivalent from the point of view of this routine. */

/*     OUTSYS     is the time scale to which EPOCH should be converted. */
/*                Acceptable values are the same as for INSYS.  The */
/*                routine is not sensitive to the case of OUTSYS. */

/* $ Detailed_Output */

/*     The function returns the time in the system specified by OUTSYS */
/*     that is equivalent to the EPOCH in the INSYS time scale. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) The kernel pool must contain the variables: */

/*           'DELTET/DELTA_T_A' */
/*           'DELTET/K' */
/*           'DELTET/EB' */
/*           'DELTET/M' */

/*        If these are not present, the error 'SPICE(MISSINGTIMEINFO)' */
/*        will be signalled.  (These variables are typically inserted */
/*        into the kernel pool by loading a leapseconds kernel with */
/*        the SPICE routine FURNSH.) */

/*     2) If the names of either the input or output time types are */
/*        unrecognized, the error 'SPICE(BADTIMETYPE)' will be signalled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     We use the term uniform time scale to refer to those */
/*     representations of time that are numeric (each epoch is */
/*     represented by a number) and additive.  A numeric time */
/*     system is additive if given the representations, E1 and E2, */
/*     of any pair of successive epochs, the time elapsed between */
/*     the epochs is given by E2 - E1. */

/*     Given an epoch in one of the uniform time scales */
/*     specified by INSYS, the function returns the equivalent */
/*     representation in the scale specified by OUTSYS.  A list */
/*     of the recognized uniform time scales is given in the */
/*     detailed input for INSYS. */

/* $ Examples */

/*     To convert an epoch with respect to the International Atomic */
/*     Time (TAI) scale to ET (Barycentric Dynamical Time), make the */
/*     following assignment. */

/*           ET = UNITIM ( TAI, 'TAI', 'ET' ) */

/* $ Restrictions */

/*     The appropriate variable must be loaded into the SPICE kernel pool */
/*     (normally by loading a leapseconds kernel with FURNSH) prior to */
/*     calling this routine. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     H.A. Neilan    (JPL) */
/*     W.L. Taber     (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.4.0, 09-SEP-2013 (BVS) */

/*        Updated to keep track of the POOL counter and call ZZCVPOOL. */

/* -    SPICELIB Version 1.3.0, 05-MAR-2009 (NJB) */

/*        This routine now keeps track of whether its kernel pool */
/*        look-up failed. If so, a kernel pool lookup is attempted on */
/*        the next call to this routine. This change is an enhancement, */
/*        not a bug fix (unlike similar modifications in SCLK routines). */

/* -    SPICELIB Version 1.2.1, 15-NOV-2006 (EDW) (NJB) */

/*        Replaced references to LDPOOL with references to FURNSH. */
/*        Replaced references to RTPOOL with references to GDPOOL. */
/*        Enhanced long error message associated with missing kernel */
/*        variables. */

/* -    SPICELIB Version 1.2.0, 17-FEB-1999 (WLT) */

/*        Added a second call to SWPOOL in the event some required */
/*        kernel pool variable is not supplied. */

/* -    SPICELIB Version 1.1.0, 17-MAY-1994 (HAN) */

/*        If the value of the function RETURN is TRUE upon execution of */
/*        this module, this function is assigned a default value of */
/*        either 0, 0.0D0, .FALSE., or blank depending on the type of */
/*        the function. */

/* -    SPICELIB Version 1.0.0, 28-MAR-1992 (WLT) */

/* -& */
/* $ Index_Entries */

/*     Transform between two uniform numeric time systems */
/*     Transform between two additive numeric time systems */
/*     Convert one uniform numeric time system to another */
/*     Convert one additive numeric time system to another */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     LBCELL is the bottom slot of a cell. */


/*     NEEDED is the number of kernel pool variables needed by this */
/*     routine. */


/*     LNGVAR is the length of the longest kernel pool variable name */
/*     that is used by this routine. */


/*     MISLEN is the length required by the MISSED array of strings */
/*     used for error messages. */


/*     TYPLEN is the maximum length allowed for names of uniform */
/*     time types. */


/*     NTDT is the number of time types based on terrestrial dynamical */
/*     time (TDT). */


/*     NTDB is the number of time types base on barycentric dynamical */
/*     time (TDB). */


/*     NRECOG is the total number of recognized types. */


/*     Local variables */


/*     Saved variables */


/*     Initial values */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	ret_val = 0.;
	return ret_val;
    }
    chkin_(__global_state, "UNITIM", (ftnlen)6);
    if (__state->first) {
	__state->first = FALSE_;

/*        Initialize the backslash character.  We use this for error */
/*        message construction. */

	*(unsigned char *)__state->bslash = '\\';

/*        Set up the parameters that we are going to need often. */

	__state->secspd = spd_(__global_state);
	__state->jd2000 = j2000_(__global_state);

/*        Initialize the sets that we will use. */

	s_copy(&__global_state->f2c, __state->typtdt + 48, "JDTDT", (ftnlen)8,
		 (ftnlen)5);
	s_copy(&__global_state->f2c, __state->typtdt + 56, "TAI", (ftnlen)8, (
		ftnlen)3);
	s_copy(&__global_state->f2c, __state->typtdt + 64, "TDT", (ftnlen)8, (
		ftnlen)3);
	s_copy(&__global_state->f2c, __state->typtdb + 48, "ET", (ftnlen)8, (
		ftnlen)2);
	s_copy(&__global_state->f2c, __state->typtdb + 56, "JDTDB", (ftnlen)8,
		 (ftnlen)5);
	s_copy(&__global_state->f2c, __state->typtdb + 64, "JED", (ftnlen)8, (
		ftnlen)3);
	s_copy(&__global_state->f2c, __state->typtdb + 72, "TDB", (ftnlen)8, (
		ftnlen)3);
	validc_(__global_state, &__state->c__3, &__state->c__3, 
		__state->typtdt, (ftnlen)8);
	validc_(__global_state, &__state->c__4, &__state->c__4, 
		__state->typtdb, (ftnlen)8);
	ssizec_(__global_state, &__state->c__7, __state->recog, (ftnlen)8);
	unionc_(__global_state, __state->typtdt, __state->typtdb, 
		__state->recog, (ftnlen)8, (ftnlen)8, (ftnlen)8);

/*        Initialize the local POOL counter to user value. */

	zzctruin_(__global_state, __state->usrctr);

/*        Set up the kernel pool watchers */

	swpool_(__global_state, "UNITIM", &__state->c__4, __state->vars__, (
		ftnlen)6, (ftnlen)16);
    }

/*     Check to see if any of the kernel items required by this */
/*     routine have been updated since the last call to this */
/*     entry point. */

    zzcvpool_(__global_state, "UNITIM", __state->usrctr, &update, (ftnlen)6);
    if (update || __state->nodata) {

/*        Fetch all of the time parameters from the kernel pool. */

	gdpool_(__global_state, "DELTET/DELTA_T_A", &__state->c__1, &
		__state->c__1, &n, &__state->dta, found, (ftnlen)16);
	gdpool_(__global_state, "DELTET/K", &__state->c__1, &__state->c__1, &
		n, &__state->k, &found[1], (ftnlen)8);
	gdpool_(__global_state, "DELTET/EB", &__state->c__1, &__state->c__1, &
		n, &__state->eb, &found[2], (ftnlen)9);
	gdpool_(__global_state, "DELTET/M", &__state->c__1, &__state->c__2, &
		n, __state->m, &found[3], (ftnlen)8);
	if (failed_(__global_state)) {
	    __state->nodata = TRUE_;
	    ret_val = 0.;
	    chkout_(__global_state, "UNITIM", (ftnlen)6);
	    return ret_val;
	}

/*        If anything wasn't found, it's an error dude. */

	if (somfls_(__global_state, found, &__state->c__4)) {
	    __state->nodata = TRUE_;

/*           If we didn't get all of the things we needed for time */
/*           conversion, we need to reset the watch.  Otherwise */
/*           subsequent calls to this routine will never have the */
/*           needed data. */

	    swpool_(__global_state, "UNITIM", &__state->c__4, __state->vars__,
		     (ftnlen)6, (ftnlen)16);
/* Writing concatenation */
	    i__1[0] = 281, a__1[0] = "The following, needed to convert betwe"
		    "en the input uniform time scales, were not found in the "
		    "kernel pool: # Your program may have failed to load a le"
		    "apseconds kernel.  Other possible causes of this problem"
		    " include loading an invalid leapseconds kernel---one tha"
		    "t lacks an initial ";
	    i__1[1] = 1, a__1[1] = __state->bslash;
	    i__1[2] = 10, a__1[2] = "begindata ";
	    i__1[3] = 41, a__1[3] = "marker or final newline character, or i"
		    "s ";
	    i__1[4] = 42, a__1[4] = "otherwise corrupted---or deleting previ"
		    "ous";
	    i__1[5] = 42, a__1[5] = "ly loaded kernel pool variables via cal"
		    "ls ";
	    i__1[6] = 30, a__1[6] = "to UNLOAD, KCLEAR, or CLPOOL. ";
	    i__1[7] = 41, a__1[7] = "Use the SPICE routine FURNSH (in Fortra"
		    "n ";
	    i__1[8] = 38, a__1[8] = "Toolkits, FURNSH is an entry point of ";
	    i__1[9] = 38, a__1[9] = "KEEPER) to load a leapseconds kernel; ";
	    i__1[10] = 36, a__1[10] = "make sure the kernel is up to date. ";
	    i__1[11] = 41, a__1[11] = "See the Kernel and Time Required Read"
		    "ing ";
	    i__1[12] = 39, a__1[12] = "or the \"Intro to Kernels\" and \"LSK"
		    " and ";
	    i__1[13] = 34, a__1[13] = "SCLK\" SPICE Tutorials for details.";
	    s_cat(&__global_state->f2c, ch__1, a__1, i__1, &__state->c__14, (
		    ftnlen)714);
	    setmsg_(__global_state, ch__1, (ftnlen)714);
	    for (i__ = 1; i__ <= 4; ++i__) {
		if (! found[(i__2 = i__ - 1) < 4 && 0 <= i__2 ? i__2 : s_rnge(
			&__global_state->f2c, "found", i__2, "unitim_", (
			ftnlen)465)]) {
		    errch_(__global_state, "#", __state->missed + ((i__2 = 
			    i__ - 1) < 4 && 0 <= i__2 ? i__2 : s_rnge(&
			    __global_state->f2c, "missed", i__2, "unitim_", (
			    ftnlen)466)) * 20, (ftnlen)1, (ftnlen)20);
		}
	    }
	    errch_(__global_state, ", #", ".", (ftnlen)3, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(MISSINGTIMEINFO)", (ftnlen)22);
	    chkout_(__global_state, "UNITIM", (ftnlen)6);
	    ret_val = *epoch;
	    return ret_val;
	}

/*        At this point the kernel data checks are done. */

	__state->nodata = FALSE_;
    }

/*     Normalize the IN and OUT scale variables */

    ucase_(__global_state, insys, myin, insys_len, (ftnlen)8);
    ucase_(__global_state, outsys, myout, outsys_len, (ftnlen)8);
    ssizec_(__global_state, &__state->c__2, types, (ftnlen)8);
    insrtc_(__global_state, myin, types, (ftnlen)8, (ftnlen)8);
    insrtc_(__global_state, myout, types, (ftnlen)8, (ftnlen)8);

/*     We will work with a local copy of EPOCH. */

    mytime = *epoch;

/*     First make sure both types are recognized. */

    if (! setc_(__global_state, types, "<", __state->recog, (ftnlen)8, (
	    ftnlen)1, (ftnlen)8)) {
	setmsg_(__global_state, "The time types recognized by UNITIM are: TA"
		"I, TDT, JDTDT, TDB, ET, JED, JDTDB.  At least one of the inp"
		"uts (#, #) was not in the list of recognized types. ", (
		ftnlen)155);
	errch_(__global_state, "#", myin, (ftnlen)1, (ftnlen)8);
	errch_(__global_state, "#", myout, (ftnlen)1, (ftnlen)8);
	sigerr_(__global_state, "SPICE(BADTIMETYPE)", (ftnlen)18);
	chkout_(__global_state, "UNITIM", (ftnlen)6);
	ret_val = *epoch;
	return ret_val;
    }

/*     If the input and output types are the same, just copy the input */
/*     epoch to the output and call it quits. */

    if (s_cmp(&__global_state->f2c, myin, myout, (ftnlen)8, (ftnlen)8) == 0) {
	ret_val = mytime;
	chkout_(__global_state, "UNITIM", (ftnlen)6);
	return ret_val;
    }

/*     Determine the base types of the input and output types. */

    intdt = elemc_(__global_state, myin, __state->typtdt, (ftnlen)8, (ftnlen)
	    8);
    outtdt = elemc_(__global_state, myout, __state->typtdt, (ftnlen)8, (
	    ftnlen)8);
    intdb = ! intdt;
    outtdb = ! outtdt;

/*     The two types, TDT and TDB, will be used as the fundamental */
/*     base used in conversions. */

/*        TAI and JDTDT will be converted to TDT */
/*        JED and JDTDB will be converted to TDB. */
/*        (ET is already TDB.) */


    if (s_cmp(&__global_state->f2c, myin, "TAI", (ftnlen)8, (ftnlen)3) == 0) {
	mytime += __state->dta;
    } else if (s_cmp(&__global_state->f2c, myin, "JDTDT", (ftnlen)8, (ftnlen)
	    5) == 0) {
	mytime = (mytime - __state->jd2000) * __state->secspd;
    } else if (s_cmp(&__global_state->f2c, myin, "JED", (ftnlen)8, (ftnlen)3) 
	    == 0) {
	mytime = (mytime - __state->jd2000) * __state->secspd;
    } else if (s_cmp(&__global_state->f2c, myin, "JDTDB", (ftnlen)8, (ftnlen)
	    5) == 0) {
	mytime = (mytime - __state->jd2000) * __state->secspd;
    }

/*     At this point, MYTIME has been converted from its input */
/*     to one of the base types. */

/*     Next change type from TDB to TDT or vice versa, if */
/*     required.  (The time is already in TDT or TDB). */

    if (intdt && outtdb) {
	tdt = mytime;
	tdb = tdt + __state->k * sin(__state->m[0] + __state->m[1] * tdt + 
		__state->eb * sin(__state->m[0] + __state->m[1] * tdt));
	mytime = tdb;
    } else if (intdb && outtdt) {

/*        What we have to do here is invert the formula used to get */
/*        TDB from TDT that was used above. */

/*        Of course solving the equation */

/*           TDB = TDT + K*SIN { M0 + M1*TDT + EB*SIN( MO + M1*TDT ) } */

/*        analytically for TDT if given TDB is no piece of cake. */
/*        However, we can get as close as we want to TDT if */
/*        we notice a few tricks.  First, let's let f(t) denote the */
/*        function */

/*           f(t) = SIN( M0 + M1*t + EB*SIN( M0 + M1*t ) ) */

/*        With this simpler notation we can rewrite our problem */
/*        as that of solving the equation */

/*           y = t + K*f(t) */

/*        for t given y.  Whichever t satisfies this equation will be */
/*        unique. The uniqueness of the solution is ensured because the */
/*        expression on the right-hand side of the equation is */
/*        monotone increasing in t. */

/*        Let's suppose that t is the solution, then the following */
/*        is true. */

/*           t = y - K*f(t) */

/*        but we can also replace the t on the right hand side of the */
/*        equation by y - K*f(t).  Thus */

/*           t = y - K*f( y - K*f(t)) */

/*             = y - K*f( y - K*f( y - K*f(t))) */

/*             = y - K*f( y - K*f( y - K*f( y - K*f(t)))) */

/*             = y - K*f( y - K*f( y - K*f( y - K*f( y - K*f(t))))) */
/*             . */
/*             . */
/*             . */
/*             = y - K*f( y - K*f( y - K*f( y - K*f( y - K*f(y - ... ))) */

/*        and so on, for as long as we have patience to perform the */
/*        substitutions. */

/*        The point of doing this recursive substitution is that we */
/*        hope to move t to an insignificant part of the computation. */
/*        This would seem to have a reasonable chance of success since */
/*        K is a small number and f is bounded by 1. */

/*        Following this idea, we will attempt to solve for t using */
/*        the recursive method outlined below. */

/*        We will make our first guess at t, call it t_0. */

/*         t_0 = y */

/*        Our next guess, t_1, is given by: */

/*         t_1 = y - K*f(t_0) */

/*        And so on: */

/*         t_2 = y - K*f(t_1)        [ = y - K*f(y - K*f(y))            ] */
/*         t_3 = y - K*f(t_2)        [ = y - K*f(y - K*f(y - K*f(y)))   ] */
/*             . */
/*             . */
/*             . */
/*         t_n = y - K*f(t_(n-1))    [ = y - K*f(y - K*f(y - K*f(y...)))] */

/*        The questions to ask at this point are: */

/*           1) Do the t_i's converge? */
/*           2) If they converge, do they converge to t? */
/*           3) If they converge to t, how fast do they get there? */

/*        1) The sequence of approximations converges. */

/*           | t_n - t_(n-1) | =    [ y - K*f( t_(n-1) ) ] */
/*                               -  [ y - K*f( t_(n-2) ) ] */

/*                             =  K*[ f( t_(n-2) ) - f( t_(n-1) ) ] */

/*           The function f has an important property. The absolute */
/*           value of its derivative is always less than M1*(1+EB). */
/*           This means that for any pair of real numbers s,t */

/*              | f(t) - f(s) |  < M1*(1+EB)*| t - s |. */

/*           From this observation, we can see that */

/*             | t_n - t_(n-1) | < K*M1*(1+EB)*| t_(n-1) - t_(n-2) | */

/*           With this fact available, we could (with a bit more work) */
/*           conclude that the sequence of t_i's converges and that */
/*           it converges at a rate that is at least as fast as the */
/*           sequence L, L**2, L**3, .... */

/*           Where L = K*M1*(1+EB) << 1. */

/*         2) If we let t be the limit of the t_i's then it follows */
/*            that */

/*               t = y - K*f(t). */

/*            or that */

/*               y = t + K*f(t). */

/*         3) As we already pointed out, the sequence of t_i's */
/*            converges at least as fast as the geometric series */
/*            L, L**2, ... */


/*        Since K*M1*(1+EB) is quite small (on the order of 10**-9) */
/*        3 iterations should get us as close as we can get to the */
/*        solution for TDT */

	tdb = mytime;
	tdt = tdb;
	for (i__ = 1; i__ <= 3; ++i__) {
	    tdt = tdb - __state->k * sin(__state->m[0] + __state->m[1] * tdt 
		    + __state->eb * sin(__state->m[0] + __state->m[1] * tdt));
	}
	mytime = tdt;
    }

/*     Now MYTIME is in the base type of the requested output. */
/*     If further conversion is required, we do it here. */

    if (s_cmp(&__global_state->f2c, myout, "TAI", (ftnlen)8, (ftnlen)3) == 0) 
	    {
	mytime -= __state->dta;
    } else if (s_cmp(&__global_state->f2c, myout, "JDTDT", (ftnlen)8, (ftnlen)
	    5) == 0) {
	mytime = mytime / __state->secspd + __state->jd2000;
    } else if (s_cmp(&__global_state->f2c, myout, "JED", (ftnlen)8, (ftnlen)3)
	     == 0) {
	mytime = mytime / __state->secspd + __state->jd2000;
    } else if (s_cmp(&__global_state->f2c, myout, "JDTDB", (ftnlen)8, (ftnlen)
	    5) == 0) {
	mytime = mytime / __state->secspd + __state->jd2000;
    }
    ret_val = mytime;
    chkout_(__global_state, "UNITIM", (ftnlen)6);
    return ret_val;
} /* unitim_ */

