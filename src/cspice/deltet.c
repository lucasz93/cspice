/* deltet.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern deltet_init_t __deltet_init;
static deltet_state_t* get_deltet_state(cspice_t* state) {
	if (!state->deltet)
		state->deltet = __cspice_allocate_module(sizeof(
	deltet_state_t), &__deltet_init, sizeof(__deltet_init));
	return state->deltet;

}

/* $Procedure      DELTET ( Delta ET, ET - UTC ) */
/* Subroutine */ int deltet_(cspice_t* __global_state, doublereal *epoch, 
	char *eptype, doublereal *delta, ftnlen eptype_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1;

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer), s_cmp(
	    f2c_state_t*, char *, char *, ftnlen, ftnlen);
    double d_nint(f2c_state_t*, doublereal *), sin(doublereal);

    /* Local variables */
    char type__[4];
    integer i__;
    doublereal k;
    doublereal m[2];
    integer n;
    doublereal dleap[400]	/* was [2][200] */;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer nleap;
    extern /* Subroutine */ int ucase_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    doublereal leaps;
    doublereal ettai;
    logical found[5];
    char dtype[1];
    doublereal ea;
    doublereal eb;
    doublereal ma;
    doublereal et;
    extern /* Subroutine */ int gdpool_(cspice_t*, char *, integer *, integer 
	    *, integer *, doublereal *, logical *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int dtpool_(cspice_t*, char *, logical *, integer 
	    *, char *, ftnlen, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);
    doublereal dta;
    doublereal aet;


    /* Module state */
    deltet_state_t* __state = get_deltet_state(__global_state);
/* $ Abstract */

/*     Return the value of Delta ET (ET-UTC) for an input epoch. */

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
/*     KERNEL */

/* $ Keywords */

/*     TIME */

/* $ Declarations */
/* $ Brief_I/O */

/*      VARIABLE  I/O  DESCRIPTION */
/*      --------  ---  -------------------------------------------------- */
/*      EPOCH      I   Input epoch (seconds past J2000). */
/*      EPTYPE     I   Type of input epoch ('UTC' or 'ET'). */
/*      DELTA      O   Delta ET (ET-UTC) at input epoch. */

/* $ Detailed_Input */

/*      EPOCH       is the epoch at which Delta ET is to be computed. */
/*                  This may be either UTC or ephemeris seconds past */
/*                  J2000, as specified by EPTYPE. */

/*      EPTYPE      indicates the type of input epoch. It may be either */
/*                  of the following: */

/*                     'UTC'    input is UTC seconds past J2000. */
/*                     'ET'     input is ephemeris seconds past J2000. */


/* $ Detailed_Output */

/*      DELTA       is the value of */

/*                     Delta ET = ET - UTC */

/*                  at the input epoch. This is added to UTC to give */
/*                  ET, or subtracted from ET to give UTC. The routine */
/*                  is reversible: that is, given the following calls, */

/*                     CALL DELTET ( UTC,      'UTC', DEL1 ) */
/*                     CALL DELTET ( UTC+DEL1, 'ET',  DEL2 ) */

/*                  the expression */

/*                     ( DEL1 .EQ. DEL2 ) */

/*                  is always true. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If the input epoch is not recognized, the error */
/*        SPICE(INVALIDEPOCH) is signaled. */

/*     2) If the variables necessary for the computation of DELTA */
/*        have not been loaded into the kernel pool, the error */
/*        SPICE(KERNELVARNOTFOUND) is signaled. */

/*     3) If the number of leapseconds in the pool is greater than */
/*        the local leapseconds buffer size, the error */
/*        SPICE(BUFFEROVERFLOW) is signaled. */

/* $ Files */

/*      None. */

/* $ Particulars */

/*      The constants necessary for computing the offset are taken */
/*      from the kernel pool, where they are assumed to have been */
/*      loaded from a kernel file. */

/*      The tables are consulted to determine the number of leap seconds */
/*      preceding the input epoch. Also, an approximation to the periodic */
/*      yearly variation (which has an amplitude of just under two */
/*      milliseconds) in the difference between ET and TAI (Atomic Time) */
/*      is computed. The final value of Delta ET is given by */

/*            Delta ET = ( ET - TAI ) + leap seconds */

/* $ Examples */

/*      The following example shows how DELTET may be used to convert */
/*      from UTC seconds past J2000 to ephemeris seconds past J2000. */

/*            CALL DELTET ( UTCSEC, 'UTC', DELTA ) */
/*            ET = UTCSEC + DELTA */

/*      The following example shows how DELTET may be used to convert */
/*      from ephemeris seconds past J2000 to UTC seconds past J2000. */

/*            CALL DELTET ( ET, 'ET', DELTA ) */
/*            UTCSEC = ET - DELTA */

/*      See the TIME required reading for further examples. */

/* $ Restrictions */

/*      The routines UTC2ET and ET2UTC are preferred for conversions */
/*      between UTC and ET. This routine is provided mainly as a utility */
/*      for UTC2ET and ET2UTC. */

/*      The kernel pool containing leapseconds and relativistic terms */
/*      MUST be loaded prior to calling this subroutine. Examples */
/*      demonstrating how to load a kernel pool are included in the */
/*      Required Reading file time.req and in the "Examples" */
/*      section of this header. For more general information about */
/*      kernel pools, please consult the Required Reading file */
/*      kernel.req. */

/* $ Literature_References */

/*      Astronomical Almanac. */

/* $ Author_and_Institution */

/*      W.M. Owen       (JPL) */
/*      I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.2.2, 18-APR-2014 (BVS) */

/*        Minor header edits. */

/* -    SPICELIB Version 1.2.1, 18-MAY-2010 (BVS) */

/*        Removed "C$" marker from text in the header. */

/* -    SPICELIB Version 1.2.0, 24-AUG-1998 (WLT) */

/*        The previous upgrade introduced an error in the fetch */
/*        of the variable DELTET/M from the kernel pool.  This */
/*        error was corrected. */

/* -    SPICELIB Version 1.1.0, 20-APR-1998 (NJB) */

/*        Calls to RTPOOL were replaced with calls to GDPOOL, which */
/*        does more robust error checking.  Check for buffer overflow */
/*        was added.  Local declarations were re-organized. */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (WMO) (IMU) */

/* -& */
/* $ Index_Entries */

/*     difference between ephemeris time and utc */

/* -& */
/* $ Revisions */

/* -     SPICELIB Version 1.2.0, 24-AUG-1998 (WLT) */

/*         The previous upgrade introduced an error in the fetch */
/*         of the variable DELTET/M from the kernel pool.  This */
/*         error was corrected. */

/* -     SPICELIB Version 1.1.0, 20-APR-1998 (NJB) */

/*         Calls to RTPOOL were replaced with calls to GDPOOL, which */
/*         does more robust error checking. */

/* -     Beta Version 1.1.0, 06-OCT-1988 (IMU) */

/*         Tim Colvin of Rand noticed that times returned by UTC2ET */
/*         and TPARSE differed by one second. Upon closer inspection, */
/*         crack NAIF staff members deduced that in fact Mr. Colvin */
/*         had not loaded the kernel pool, and were surprised to learn */
/*         that no error had occurred. */

/*         Multiple FOUND flags and a bevy of new error messages were */
/*         implemented to cope with this unfortunate oversight. */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     Saved variables */


/*     Initial values */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "DELTET", (ftnlen)6);
    }

/*     Convert the epoch type to uppercase, to simplify comparisons. */

    ucase_(__global_state, eptype, type__, eptype_len, (ftnlen)4);

/*     Extract the necessary constants from the kernel pool. */
/*     Leap seconds and their epochs are interleaved in DELTA_AT. */

/*     DLEAP(1,i) is the number of leap seconds at DLEAP(2,i) UTC */
/*     seconds past J2000. */

    gdpool_(__global_state, "DELTET/DELTA_T_A", &__state->c__1, &
	    __state->c__1, &n, &dta, found, (ftnlen)16);
    gdpool_(__global_state, "DELTET/K", &__state->c__1, &__state->c__1, &n, &
	    k, &found[1], (ftnlen)8);
    gdpool_(__global_state, "DELTET/EB", &__state->c__1, &__state->c__1, &n, &
	    eb, &found[2], (ftnlen)9);
    gdpool_(__global_state, "DELTET/M", &__state->c__1, &__state->c__2, &n, m,
	     &found[3], (ftnlen)8);

/*     Check that the number of leapseconds is not too great for our */
/*     buffer size (not likely). */

    dtpool_(__global_state, "DELTET/DELTA_AT", &found[4], &nleap, dtype, (
	    ftnlen)15, (ftnlen)1);
    if (nleap > 400) {
	setmsg_(__global_state, "Number of leapseconds, #, is greater than t"
		"he number that can be buffered, #.", (ftnlen)77);
	i__1 = nleap / 2;
	errint_(__global_state, "#", &i__1, (ftnlen)1);
	errint_(__global_state, "#", &__state->c__200, (ftnlen)1);
	sigerr_(__global_state, "SPICE(BUFFERTOOSMALL)", (ftnlen)21);
	chkout_(__global_state, "DELTET", (ftnlen)6);
	return 0;
    }
    gdpool_(__global_state, "DELTET/DELTA_AT", &__state->c__1, &
	    __state->c__400, &nleap, dleap, &found[4], (ftnlen)15);
    nleap /= 2;
    if (! (found[0] && found[1] && found[2] && found[3] && found[4])) {
	setmsg_(__global_state, "The following, needed to compute Delta ET ("
		"ET - UTC), could not be found in the kernel pool: #", (ftnlen)
		94);
	for (i__ = 1; i__ <= 5; ++i__) {
	    if (! found[(i__1 = i__ - 1) < 5 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "found", i__1, "deltet_", (ftnlen)
		    341)]) {
		errch_(__global_state, "#", __state->missed + ((i__1 = i__ - 
			1) < 5 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "missed", i__1, "deltet_", (
			ftnlen)342)) * 20, (ftnlen)1, (ftnlen)20);
	    }
	}
	errch_(__global_state, ", #", ".", (ftnlen)3, (ftnlen)1);
	sigerr_(__global_state, "SPICE(KERNELVARNOTFOUND)", (ftnlen)24);
	chkout_(__global_state, "DELTET", (ftnlen)6);
	return 0;
    }

/*     There are two separate quantities to be determined. First, */
/*     the appropriate number of leap seconds. Second, the size of */
/*     the periodic term ET-TAI. */


/*     For epochs before the first leap second, return Delta ET at */
/*     the epoch of the leap second minus one second. */

    leaps = dleap[0] - 1;

/*     When counting leap seconds for UTC epochs, we can compare */
/*     directly against the values in DLEAP. */

    if (s_cmp(&__global_state->f2c, type__, "UTC", (ftnlen)4, (ftnlen)3) == 0)
	     {
	i__1 = nleap;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (*epoch >= dleap[(i__2 = (i__ << 1) - 1) < 400 && 0 <= i__2 ? 
		    i__2 : s_rnge(&__global_state->f2c, "dleap", i__2, "delt"
		    "et_", (ftnlen)375)]) {
		leaps = dleap[(i__2 = (i__ << 1) - 2) < 400 && 0 <= i__2 ? 
			i__2 : s_rnge(&__global_state->f2c, "dleap", i__2, 
			"deltet_", (ftnlen)376)];
	    }
	}

/*     For ET epochs, things are a little tougher. In order to compare */
/*     the input epoch against the epochs of the leap seconds, we need */
/*     to compute ET-TAI at each of the leap epochs. To make sure that */
/*     the computation is reversible, it is always done at the nearest */
/*     ET second (the "approximate ET", or AET). */

/*     There must be a hundred ways to do this more efficiently. */
/*     For now, we'll settle for one that works. */

    } else if (s_cmp(&__global_state->f2c, type__, "ET", (ftnlen)4, (ftnlen)2)
	     == 0) {
	i__1 = nleap;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (*epoch > dleap[(i__2 = (i__ << 1) - 1) < 400 && 0 <= i__2 ? 
		    i__2 : s_rnge(&__global_state->f2c, "dleap", i__2, "delt"
		    "et_", (ftnlen)393)]) {
		d__1 = dleap[(i__2 = (i__ << 1) - 1) < 400 && 0 <= i__2 ? 
			i__2 : s_rnge(&__global_state->f2c, "dleap", i__2, 
			"deltet_", (ftnlen)395)] + dta + dleap[(i__3 = (i__ <<
			 1) - 2) < 400 && 0 <= i__3 ? i__3 : s_rnge(&
			__global_state->f2c, "dleap", i__3, "deltet_", (
			ftnlen)395)];
		aet = d_nint(&__global_state->f2c, &d__1);
		ma = m[0] + m[1] * aet;
		ea = ma + eb * sin(ma);
		ettai = k * sin(ea);
		et = dleap[(i__2 = (i__ << 1) - 1) < 400 && 0 <= i__2 ? i__2 :
			 s_rnge(&__global_state->f2c, "dleap", i__2, "deltet_"
			, (ftnlen)401)] + dta + dleap[(i__3 = (i__ << 1) - 2) 
			< 400 && 0 <= i__3 ? i__3 : s_rnge(&
			__global_state->f2c, "dleap", i__3, "deltet_", (
			ftnlen)401)] + ettai;
		if (*epoch >= et) {
		    leaps = dleap[(i__2 = (i__ << 1) - 2) < 400 && 0 <= i__2 ?
			     i__2 : s_rnge(&__global_state->f2c, "dleap", 
			    i__2, "deltet_", (ftnlen)404)];
		}
	    }
	}

/*     Uh, those are the only choices. */

    } else {
	setmsg_(__global_state, "Epoch type was #", (ftnlen)16);
	errch_(__global_state, "#", type__, (ftnlen)1, (ftnlen)4);
	sigerr_(__global_state, "SPICE(INVALIDEPOCH)", (ftnlen)19);
	chkout_(__global_state, "DELTET", (ftnlen)6);
	return 0;
    }

/*     Add the constant offset, leap seconds, and the relativistic term */
/*     (as before, computed at the nearest ET second). */

    if (s_cmp(&__global_state->f2c, type__, "ET", (ftnlen)4, (ftnlen)2) == 0) 
	    {
	aet = d_nint(&__global_state->f2c, epoch);
    } else if (s_cmp(&__global_state->f2c, type__, "UTC", (ftnlen)4, (ftnlen)
	    3) == 0) {
	d__1 = *epoch + dta + leaps;
	aet = d_nint(&__global_state->f2c, &d__1);
    }
    ma = m[0] + m[1] * aet;
    ea = ma + eb * sin(ma);
    ettai = k * sin(ea);
    *delta = dta + leaps + ettai;
    chkout_(__global_state, "DELTET", (ftnlen)6);
    return 0;
} /* deltet_ */

