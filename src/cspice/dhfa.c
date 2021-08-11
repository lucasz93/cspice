/* dhfa.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int dhfa_state_t;
static dhfa_state_t* get_dhfa_state() {
	cspice_t* state =  __cspice_get_state();
	return 0;
}

/* $Procedure DHFA ( Time derivative of half angle ) */
doublereal dhfa_(doublereal *state, doublereal *bodyr)
{
    /* System generated locals */
    doublereal ret_val, d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    doublereal base;
    extern doublereal vdot_(doublereal *, doublereal *);
    doublereal p[3];
    doublereal r__;
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    extern /* Subroutine */ int errdp_(char *, doublereal *, ftnlen);
    extern /* Subroutine */ int unorm_(doublereal *, doublereal *, doublereal 
	    *);
    extern logical vzero_(doublereal *);
    extern /* Subroutine */ int sigerr_(char *, ftnlen);
    doublereal rngrat;
    extern /* Subroutine */ int chkout_(char *, ftnlen);
    extern /* Subroutine */ int setmsg_(char *, ftnlen);
    extern logical return_(void);


    /* Module state */
    dhfa_state_t* __state = get_dhfa_state();
/* $ Abstract */

/*     Calculate the value of the time derivative of the */
/*     half angle of a spherical body given a state vector */
/*     STATE and body radius BODYR. */

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

/*     None. */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     STATE      I   SPICE state vector */
/*     BODYR      I   Radius of body */

/* $ Detailed_Input */

/*     STATE      the state vector of a target body as seen from an */
/*                observer. */

/*     BODYR      the radius of the target body observed from the */
/*                position in STATE; the target body assumed as a sphere. */

/* $ Detailed_Output */

/*     The function returns the double precision value of the time */
/*     derivative of the half angle of a spherical body in radians */
/*     per second. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) A negative value for BODYR causes SPICE(BADRADIUS) to signal. */

/*     2) A position component of STATE equaling the zero vector */
/*        causes SPICE(DEGENERATECASE) to signal. */

/*     3) A condition where the body radius exceeds the distance from */
/*        the body to the observer causes SPICE(BADGEOMETRY) to signal. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     In this discussion, the notation */

/*        < V1, V2 > */

/*     indicates the dot product of vectors V1 and V2. */

/*     The expression */

/*                     body_radius */
/*        sin(ALPHA) = -----------                                  (1) */
/*                       range */

/*     describes the half angle (ALPHA) of a spherical body, i.e. the */
/*     angular radius of the spherical body as viewed by an observer at */
/*     distance 'range'. */

/*     Solve for ALPHA */

/*                   -1  body_radius */
/*        ALPHA = sin  ( ----------- )                              (2) */
/*                         range */

/*     Take the derivative of ALPHA with respect to time */

/*      d                   1                   d    body_radius */
/*      --(ALPHA) =  --------------------- *    __ (----------- )   (3) */
/*      dt           1 -   body_radius  2   1/2 dt    range */
/*                (      [ ----------- ]   ) */
/*                          range */

/*      d              - body_radius             1      d */
/*      --(ALPHA) =  --------------------- *   ------ * __(range)   (4) */
/*      dt           1 -   body_radius  2  1/2      2   dt */
/*                (      [ ----------- ]  )    range */
/*                          range */

/*      With */
/*                        _  _ */
/*      d               < R, V >              - */
/*      -- ( range )  = -------- ,  range = ||R||                   (5) */
/*      dt                 - */
/*                       ||R|| */

/*     Apply (5) to equation (4) */
/*                                                        _  _ */
/*      d              - body_radius             1      < R, V > */
/*      --(ALPHA) =  --------------------- *   ------ *  --------   (6) */
/*      dt           1 -   body_radius  2  1/2     2     range */
/*                (      [ ----------- ]  )    range */
/*                            range */

/*     Carry range through the denominator gives */

/*                                                _  _ */
/*      d              - body_radius            < R, V > */
/*      --(ALPHA) =  --------------------- *    --------            (7) */
/*      dt                 2            2  1/2        2 */
/*                   (range - body_radius )      range */

/*      So since */
/*                       -    -         _  _ */
/*         ^  -       <  R,   V >     < R, V > */
/*       < R, V >   =   ---        =  -------- */
/*                       -              range */
/*                     ||R|| */

/*                                                ^  _ */
/*      d              - body_radius            < R, V > */
/*      --(ALPHA) =  --------------------- *    --------            (8) */
/*      dt                 2            2  1/2 */
/*                   (range - body_radius )      range */


/* $ Examples */

/*           PROGRAM DHFA_EX */
/*           IMPLICIT              NONE */

/*           INTEGER               DIM */

/*           DOUBLE PRECISION      ET */
/*           DOUBLE PRECISION      LT */
/*           DOUBLE PRECISION      DHADT */
/*           DOUBLE PRECISION      RAD   (3) */
/*           DOUBLE PRECISION      STATE (6) */

/*           INTEGER               STRLEN */
/*           PARAMETER           ( STRLEN = 64 ) */

/*           CHARACTER*(STRLEN)    BEGSTR */


/*           DOUBLE PRECISION      SPD */
/*           DOUBLE PRECISION      DHFA */
/*     C */
/*     C     Load kernels. */
/*     C */
/*           CALL FURNSH ('standard.tm') */

/*     C */
/*     C     An approximate time corresponding to a maximal angular */
/*     C     separation between the earth and Moon as seen from the sun. */
/*     C */
/*           BEGSTR = '2007-DEC-17 04:04:46.935443 (TDB)' */
/*           CALL STR2ET( BEGSTR, ET ) */

/*           CALL BODVRD ('SUN', 'RADII', 3, DIM, RAD ) */

/*           CALL SPKEZR ('MOON', ET, 'J2000', 'NONE', 'SUN', STATE, LT ) */

/*     C */
/*     C     The derivative of the half angle at ET should have a near-to */
/*     C     maximal value as the Moon velocity vector points either */
/*     C     towards the sun or away. */
/*     C */
/*           DHADT = DHFA( STATE, RAD(1) ) */
/*           WRITE(*,*) 'Half angle derivative at begin time  : ', DHADT */

/*     C */
/*     C     Two weeks later the derivate should have a similar */
/*     C     magnitude but the opposite sign. */
/*     C */
/*           ET = SPD() * 14.D0 + ET */

/*           CALL SPKEZR ('MOON', ET, 'J2000', 'NONE', 'SUN', STATE, LT ) */

/*           DHADT = DHFA( STATE, RAD(1) ) */
/*           WRITE(*,*) 'Half angle derivative two weeks later: ', DHADT */

/*           END */

/*   The program compiled on OS X with g77 outputs (radians/sec): */

/*     Half angle derivative at begin time  :  -2.53879935E-11 */
/*     Half angle derivative two weeks later:   2.94362059E-11 */

/*   As expected, the derivate values have similar magnitudes but */
/*   opposite signs. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     E.D. Wright    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.1, 06-JUL-2009 (EDW) */

/*        Rename of the ZZDHA call to DHFA. */

/* -    SPICELIB Version 1.0.0, 10-FEB-2009 (EDW) (NJB) */

/* -& */
/* $ Index_Entries */

/*   time derivative of half angle */

/* -& */

/*     SPICELIB functions */

    if (return_()) {
	ret_val = 0.;
	return ret_val;
    } else {
	chkin_("DHFA", (ftnlen)4);
    }

/*     A zero body radius (point object) returns a zero for the */
/*     derivative. A negative value indicates an error */
/*     the caller should diagnose. */

    if (*bodyr == 0.) {
	ret_val = 0.;
	chkout_("DHFA", (ftnlen)4);
	return ret_val;
    } else if (*bodyr < 0.) {
	ret_val = 0.;
	setmsg_("Non physical case. The input body radius has a negative val"
		"ue.", (ftnlen)62);
	sigerr_("SPICE(BADRADIUS)", (ftnlen)16);
	chkout_("DHFA", (ftnlen)4);
	return ret_val;
    }

/*     Normalize the position component of STATE. Store the unit vector */
/*     in P. */

    unorm_(state, p, &r__);
    if (vzero_(p)) {
	ret_val = 0.;
	setmsg_("The position component of the input state vector equals the"
		" zero vector.", (ftnlen)72);
	sigerr_("SPICE(DEGENERATECASE)", (ftnlen)21);
	chkout_("DHFA", (ftnlen)4);
	return ret_val;
    }

/*     Calculate the range rate. */

    rngrat = vdot_(p, &state[3]);

/*     Confirm R > BODYR. */

/* Computing 2nd power */
    d__1 = r__;
/* Computing 2nd power */
    d__2 = *bodyr;
    base = d__1 * d__1 - d__2 * d__2;
    if (base <= 0.) {
	ret_val = 0.;
	setmsg_("Invalid case. The body radius, #1, equals or exceeds the ra"
		"nge to the target, #2.", (ftnlen)81);
	errdp_("#1", bodyr, (ftnlen)2);
	errdp_("#2", &r__, (ftnlen)2);
	sigerr_("SPICE(BADGEOMETRY)", (ftnlen)18);
	chkout_("DHFA", (ftnlen)4);
	return ret_val;
    }

/*     Now we safely take the square root of BASE. */

    base = sqrt(base);
    ret_val = -(rngrat * *bodyr) / (base * r__);
    chkout_("DHFA", (ftnlen)4);
    return ret_val;
} /* dhfa_ */

