/* zzdiv.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzdiv_init_t __zzdiv_init;
static zzdiv_state_t* get_zzdiv_state(cspice_t* state) {
	if (!state->zzdiv)
		state->zzdiv = __cspice_allocate_module(sizeof(zzdiv_state_t),
	 &__zzdiv_init, sizeof(__zzdiv_init));
	return state->zzdiv;

}

/* $Procedure ZZDIV ( Safer division ) */
doublereal zzdiv_(cspice_t* __global_state, doublereal *numr, doublereal *
	denom)
{
    /* Initialized data */


    /* System generated locals */
    doublereal ret_val, d__1;

    /* Builtin functions */
    double d_lg10(f2c_state_t*, doublereal *);

    /* Local variables */
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern doublereal dpmax_(cspice_t*);
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    zzdiv_state_t* __state = get_zzdiv_state(__global_state);
/* $ Abstract */

/*     Safely calculate the value NUMR/DENOM, avoiding the possibility */
/*     of floating point exceptions (FPE), due to numeric underflow, */
/*     numeric overflow, or divide-by-zero. */

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

/*     MATH */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     NUMR       I   Numerator of division. */
/*     DENOM      I   Denominator of division. */

/* $ Detailed_Input */

/*     NUMR       Numerator for the division operation. */

/*     DENOM      Denominator for the division operation. */

/* $ Detailed_Output */

/*     ZZDIV      The value NUMR/DENOM. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) SPICE(DIVIDEBYZERO) signals if DENOM equals zero. This */
/*        signal occurs for NUMR/0 and 0/0 cases. */

/*     2) SPICE(NUMERICOVERFLOW) signals if the logarithm base 10 */
/*        of the division is greater than EXPNT (defined */
/*        below). */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     We want to avoid a floating point exception signal from */
/*     the platform. This routine does not trap exceptions, */
/*     the intended purpose is to prevent exceptions. */

/*     Given, for the IEEE 754 double-precision binary */
/*     floating-point format, the order of magnitude of the minimum */
/*     normal positive double equals -307 and the order of magnitude of */
/*     the maximum double equals 308. */

/*       -307 <= LOG10(|NUMR|) - LOG10(|DENOM|) <= 308 */

/*     or */

/*         -307                         308 */
/*        10     <=  |NUMR|/|DENOM| <= 10 */

/*     Satisfying this condition should guarantee no floating */
/*     point exceptions. */

/*     Underflow returns zero without an error signal as per SPICE */
/*     convention. */

/*     Important, this routine does not calculate or enforce a */
/*     precision on the division evaluation. A safe evaluation */
/*     may result in a result unusable due to precision loss. */

/*     The routine does not depend on platform-specific arithmetic */
/*     exception handling, even though the bound for the computed */
/*     ratio is platform-specific. */

/*     The range [-307,308] is valid for IEEE double precision. */
/*     It may occur this routine runs on a non compliant platform, */
/*     so calculate the range based on the DPMAX() value. */

/*     Assign a parameter EXPNT such that EXPNT equals the order of */
/*     DPMAX. The routine uses the range [-(EXPNT-1), EXPNT]. */

/*     This routine checks the difference between the base 10 logarithms */
/*     of NUMR and DENOM to ensure the magnitude of NUMR/DENOM is */
/*     within the range [-(EXPNT-1), EXPNT]. */

/* $ Examples */

/*     Demonstrate the use of ZZDIV with DPMAX and zero as the */
/*     numerator and denominator. */

/*           PROGRAM ZZDIV_T */
/*           IMPLICIT NONE */

/*           DOUBLE PRECISION      NUMR */
/*           DOUBLE PRECISION      DENOM */
/*           DOUBLE PRECISION      DIV */

/*     C */
/*     C     SPICE functions. */
/*     C */
/*           DOUBLE PRECISION      ZZDIV */
/*           DOUBLE PRECISION      DPMAX */


/*     C */
/*     C     Set error reporting to REPORT. */
/*     C */
/*           CALL ERRACT( 'SET', 'REPORT' ) */


/*     C */
/*     C     Standard, safe evaluation. */
/*     C */
/*           NUMR  = 1.D0 */
/*           DENOM = 10.D0 */

/*           DIV = ZZDIV( NUMR, DENOM ) */
/*           WRITE(*,*) 'DIV 1/10      = ', DIV */



/*     C */
/*     C     A numeric underflow event as defined in ZZDIV. */
/*     C */
/*           NUMR  = 1.D0 */
/*           DENOM = DPMAX() */

/*           DIV = ZZDIV( NUMR, DENOM ) */
/*           WRITE(*,*) 'DIV 1/DPMAX() = ', DIV */



/*     C */
/*     C     A numeric overflow event as defined in ZZDIV. */
/*     C */
/*           NUMR  = DPMAX() */
/*           DENOM = 1.D0 */

/*           DIV = ZZDIV( NUMR, DENOM ) */
/*           WRITE(*,*) 'DIV DPMAX()/1 = ', DIV */


/*     C */
/*     C     A divide by zero event. */
/*     C */
/*           NUMR  = 1.D0 */
/*           DENOM = 0.D0 */

/*           DIV = ZZDIV( NUMR, DENOM ) */
/*           WRITE(*,*) 'DIV 1/0       = ', DIV */


/*     C */
/*     C     A 0/0 event. ZZDIV treats this as a divide by zero */
/*     C     event. */
/*     C */
/*           NUMR  = 0.D0 */
/*           DENOM = 0.D0 */

/*           DIV = ZZDIV( NUMR, DENOM ) */
/*           WRITE(*,*) 'DIV 0/0       = ', DIV */


/*           END */

/*   The program outputs: */

/*   -The function returns the evaluation value. No error. */

/*      DIV 1/10      =   0.10000000000000001 */



/*      -The function returns zero for an underflow state. No error. */

/*      DIV 1/DPMAX() =    0.0000000000000000 */



/*   -The function signals a NUMERICOVERFLOW error, and sets the */
/*    return value to zero. */

/*     ================================================================= */

/*     Toolkit version: N0064 */

/*     SPICE(NUMERICOVERFLOW) -- */

/*     Numerical overflow event. Numerator value 1.7976931348623E+308, */
/*     denominator value 1.0000000000000E+00. */

/*     A traceback follows.  The name of the highest level module is */
/*     first. */
/*     ZZDIV */

/*     ================================================================= */
/*      DIV DPMAX()/1 =    0.0000000000000000 */



/*   -The function signals a DIVIDEBYZERO error, and sets the */
/*    return value to zero. */

/*     ================================================================= */

/*     Toolkit version: N0064 */

/*     SPICE(DIVIDEBYZERO) -- */

/*     Numerical divide by zero event. Numerator value */
/*     1.0000000000000E+00. */

/*     A traceback follows.  The name of the highest level module is */
/*     first. */
/*     ZZDIV */

/*     ================================================================= */
/*      DIV 1/0       =    0.0000000000000000 */



/*   -The function signals a DIVIDEBYZERO error, and sets the */
/*    return value to zero. */

/*     ================================================================= */

/*     Toolkit version: N0064 */

/*     SPICE(DIVIDEBYZERO) -- */

/*     Numerical divide by zero event. Numerator value */
/*     0.0000000000000E+00. */

/*     A traceback follows.  The name of the highest level module is */
/*     first. */
/*     ZZDIV */

/*     ================================================================= */
/*      DIV 0/0       =    0.0000000000000000 */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     E.D. Wright    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 31-JAN-2014 (EDW) */

/* -& */
/* $ Index_Entries */

/*     division, avoid floating point exception */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     The bounds on the potential result of the calculation. */


/*     First entry flag. */


/*     Return on error. */

    if (return_(__global_state)) {
	ret_val = 0.;
	return ret_val;
    }

/*     Participate in error tracing. */

    chkin_(__global_state, "ZZDIV", (ftnlen)5);

/*     Calculate the bounds parameter on first entry. */
/*     The double precision maximum value has the form */
/*     "d*(10**EXPNT)." The value of interest is "EXPNT." */

    if (__state->first) {
	__state->first = FALSE_;

/*        A "floor" evaluation. */

	d__1 = dpmax_(__global_state);
	__state->expnt = (doublereal) ((integer) d_lg10(&__global_state->f2c, 
		&d__1));
    }

/*     If the denominator is zero, return zero and signal an error. */
/*     This is equivalent to a signaling NaN (not-a-number) for */
/*     the 0/0 case. */

    if (*denom == 0.) {
	ret_val = 0.;
	setmsg_(__global_state, "Numerical divide by zero event. Numerator v"
		"alue #1.", (ftnlen)51);
	errdp_(__global_state, "#1", numr, (ftnlen)2);
	sigerr_(__global_state, "SPICE(DIVIDEBYZERO)", (ftnlen)19);
	chkout_(__global_state, "ZZDIV", (ftnlen)5);
	return ret_val;
    }

/*     If the numerator is zero, the division is zero. DENOM */
/*     is known non-zero. */

    if (*numr == 0.) {
	ret_val = 0.;
	chkout_(__global_state, "ZZDIV", (ftnlen)5);
	return ret_val;
    }

/*     Calculate base 10 logarithms of the absolute value of the */
/*     numerator and denominator. Recall the base 10 log of a negative */
/*     real is a complex number (an irritating reality). Our interest */
/*     is the magnitude of the result, not the sign. */

/*     An earlier check returned if NUMR or DENOM equals zero, so the */
/*     LOG10 call is safe from an infinite return value. An infinite */
/*     return value defeats the purpose of this routine. */

    d__1 = abs(*numr);
    __state->lognum = d_lg10(&__global_state->f2c, &d__1);
    d__1 = abs(*denom);
    __state->logden = d_lg10(&__global_state->f2c, &d__1);

/*     Local possible overflow check. */

    if (__state->lognum - __state->logden > __state->expnt) {
	ret_val = 0.;
	setmsg_(__global_state, "Numerical overflow event. Numerator value #"
		"1, denominator value #2.", (ftnlen)67);
	errdp_(__global_state, "#1", numr, (ftnlen)2);
	errdp_(__global_state, "#2", denom, (ftnlen)2);
	sigerr_(__global_state, "SPICE(NUMERICOVERFLOW)", (ftnlen)22);
	chkout_(__global_state, "ZZDIV", (ftnlen)5);
	return ret_val;
    }

/*     Local possible underflow check. Accept this may occur, */
/*     return a zero. */

    if (__state->lognum - __state->logden < -(__state->expnt - 1.)) {
	ret_val = 0.;
	chkout_(__global_state, "ZZDIV", (ftnlen)5);
	return ret_val;
    }

/*     This operation should be safe. Probably. */

    ret_val = *numr / *denom;
    chkout_(__global_state, "ZZDIV", (ftnlen)5);
    return ret_val;
} /* zzdiv_ */

