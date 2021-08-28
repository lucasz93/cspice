/* gfrprt.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern gfrprt_init_t __gfrprt_init;
static inline gfrprt_state_t* get_gfrprt_state(cspice_t* state) {
	if (!state->gfrprt)
		state->gfrprt = __cspice_allocate_module(sizeof(
	gfrprt_state_t), &__gfrprt_init, sizeof(__gfrprt_init));
	return state->gfrprt;

}

/* $Procedure GFRPRT ( GF, progress reporting package ) */
/* Subroutine */ int gfrprt_0_(cspice_t* __global_state, int n__, doublereal *
	window, char *begmss, char *endmss, doublereal *ivbeg, doublereal *
	ivend, doublereal *time, ftnlen begmss_len, ftnlen endmss_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    doublereal incr;
    doublereal freq;
    integer long__;
    integer unit;
    extern /* Subroutine */ int zzgfwkad_(cspice_t*, doublereal *, integer *, 
	    char *, char *, ftnlen, ftnlen);
    extern /* Subroutine */ int zzgfwkin_(cspice_t*, doublereal *);
    extern /* Subroutine */ int zzgfdsps_(cspice_t*, integer *, char *, char *
	    , integer *, ftnlen, ftnlen);
    extern /* Subroutine */ int zzgfwkmo_(cspice_t*, integer *, doublereal *, 
	    doublereal *, integer *, char *, char *, doublereal *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int zzgftswk_(cspice_t*, doublereal *, doublereal 
	    *, integer *, char *, char *, ftnlen, ftnlen);
    integer i__;
    extern integer cardd_(cspice_t*, doublereal *);
    char begin[55];
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    extern /* Subroutine */ int stdio_(cspice_t*, char *, integer *, ftnlen);
    doublereal total;
    integer short__;
    extern logical failed_(cspice_t*);
    integer tcheck;
    integer chrcod;
    extern integer lastnb_(cspice_t*, char *, ftnlen);
    doublereal stddev;
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    doublereal measur;
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int wnsumd_(cspice_t*, doublereal *, doublereal *,
	     doublereal *, doublereal *, integer *, integer *);
    extern logical return_(cspice_t*);
    integer stdout;
    char end[13];
    doublereal ave;


    /* Module state */
    gfrprt_state_t* __state = get_gfrprt_state(__global_state);
/* $ Abstract */

/*     The entry points contained under this routine provide users */
/*     information regarding the status of a GF search in progress. */

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

/*     GF */

/* $ Keywords */

/*     SEARCH */
/*     UTILITY */

/* $ Declarations */
/* $ Abstract */

/*     SPICE private include file intended solely for the support of */
/*     SPICE routines. Users should not include this routine in their */
/*     source code due to the volatile nature of this file. */

/*     This file contains private, global parameter declarations */
/*     for the SPICELIB Geometry Finder (GF) subsystem. */

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

/*     GF */

/* $ Keywords */

/*     GEOMETRY */
/*     ROOT */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman      (JPL) */
/*     E.D. Wright       (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 17-FEB-2009 (NJB) (EDW) */

/* -& */

/*     The set of supported coordinate systems */

/*        System          Coordinates */
/*        ----------      ----------- */
/*        Rectangular     X, Y, Z */
/*        Latitudinal     Radius, Longitude, Latitude */
/*        Spherical       Radius, Colatitude, Longitude */
/*        RA/Dec          Range, Right Ascension, Declination */
/*        Cylindrical     Radius, Longitude, Z */
/*        Geodetic        Longitude, Latitude, Altitude */
/*        Planetographic  Longitude, Latitude, Altitude */

/*     Below we declare parameters for naming coordinate systems. */
/*     User inputs naming coordinate systems must match these */
/*     when compared using EQSTR. That is, user inputs must */
/*     match after being left justified, converted to upper case, */
/*     and having all embedded blanks removed. */


/*     Below we declare names for coordinates. Again, user */
/*     inputs naming coordinates must match these when */
/*     compared using EQSTR. */


/*     Note that the RA parameter value below matches */

/*        'RIGHT ASCENSION' */

/*     when extra blanks are compressed out of the above value. */


/*     Parameters specifying types of vector definitions */
/*     used for GF coordinate searches: */

/*     All string parameter values are left justified, upper */
/*     case, with extra blanks compressed out. */

/*     POSDEF indicates the vector is defined by the */
/*     position of a target relative to an observer. */


/*     SOBDEF indicates the vector points from the center */
/*     of a target body to the sub-observer point on */
/*     that body, for a given observer and target. */


/*     SOBDEF indicates the vector points from the center */
/*     of a target body to the surface intercept point on */
/*     that body, for a given observer, ray, and target. */


/*     Number of workspace windows used by ZZGFREL: */


/*     Number of additional workspace windows used by ZZGFLONG: */


/*     Index of "existence window" used by ZZGFCSLV: */


/*     Progress report parameters: */

/*     MXBEGM, */
/*     MXENDM    are, respectively, the maximum lengths of the progress */
/*               report message prefix and suffix. */

/*     Note: the sum of these lengths, plus the length of the */
/*     "percent complete" substring, should not be long enough */
/*     to cause wrap-around on any platform's terminal window. */


/*     Total progress report message length upper bound: */


/*     End of file zzgf.inc. */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     LBCELL     P   The SPICELIB cell lower bound. */
/*     MXBEGM     P   Maximum progress report message prefix length. */
/*     MXENDM     P   Maximum progress report message suffix length. */
/*     WINDOW     I   A window over which a job is to be performed. */
/*     BEGMSS     I   Beginning of the text portion of the output message */
/*     ENDMSS     I   End of the text portion of the output message */
/*     IVBEG      I   Current confinement window interval start time. */
/*     IVEND      I   Current confinement window interval stop time. */
/*     TIME       I   Input to the reporting routine. */

/* $ Detailed_Input */

/*     See the individual entry points. */

/* $ Detailed_Output */

/*     See the individual entry points. */

/* $ Parameters */

/*     LBCELL    is the SPICELIB cell lower bound. */

/*     MXBEGM, */
/*     MXENDM    are, respectively, the maximum lengths of the progress */
/*               report message prefix and suffix. */

/* $ Exceptions */

/*     See the individual entry points. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This umbrella routine contains default progress reporting entry */
/*     points that display a report via console I/O. These routines may */
/*     be used by SPICE-based applications as inputs to mid-level GF */
/*     search routines. These routines may be useful even when progress */
/*     reporting is not desired, since the mid-level search routines */
/*     provide some capabilities that aren't supported by the top-level */
/*     GF routines. */

/*     Developers wishing to use their own GF progress reporting */
/*     routines must design them with the same interfaces and should */
/*     assign them the same progress reporting roles as the entry points */
/*     of these routines. */

/*     The entry points contained in this routine are written to */
/*     make reporting of work (such as searching for a geometric event) */
/*     over a particular window easy. This is an important feature for */
/*     interactive programs that may "go away" from the user's control */
/*     for a considerable length of time. It allows the user to see that */
/*     something is still going on (although maybe not too quickly). */

/*     The three entry points contained under this module are: */

/*        GFREPI  used to set up the reporting mechanism. It lets GFRPRT */
/*                know that some task is about to begin that involves */
/*                interaction with some window of times.  It is used */
/*                only to set up and store the constants associated with */
/*                the reporting of the job in progress. */

/*        GFREPU  is used to notify the reporter that work has */
/*                progressed to a given point with respect to the start */
/*                of the confinement window. */

/*        GFREPF  is used to "finish" the reporting of work (set the */
/*                completion value to 100%. */

/*     The progress reporting utilities are called by GF search routines */
/*     as follows: */

/*        1) Given a window over which some work is to be performed, */
/*           CALL GFREPI with the appropriate inputs, to let the routine */
/*           know the intervals over which some work is to be done. */

/*        2) Each time some "good" amount of work has been done, call */
/*           GFREPU so that the total amount of work done can be updated */
/*           and can be reported. */

/*        3) When work is complete call GFREPF to "clean up" the end of */
/*           the progress report. */

/* $ Examples */

/*     1)  This example shows how to call a mid-level GF search API that */
/*         requires as input progress reporting routines. */

/*         If custom progress reporting routines are available, they */
/*         can replace GFREPI, GFREPU, and GFREPF in any GF API calls. */

/*         The code fragment below is from the first code example in the */
/*         header of */

/*            gfocce.for */

/*         Only the portions of that program relevant to use of the */
/*         progress reporting routines are copied here. Deleted portions */
/*         of code are indicated by ellipses. */


/*              PROGRAM EX1 */

/*              IMPLICIT NONE */

/*              ... */

/*              EXTERNAL              GFREPI */
/*              EXTERNAL              GFREPU */
/*              EXTERNAL              GFREPF */

/*              ... */

/*        C */
/*        C     Turn on progress reporting; turn off interrupt */
/*        C     handling. */
/*        C */
/*              RPT  = .TRUE. */
/*              ... */

/*        C */
/*        C     Perform the search. */
/*        C */
/*              CALL GFOCCE ( 'ANY', */
/*             .              'MOON',   'ellipsoid',  'IAU_MOON', */
/*             .              'SUN',    'ellipsoid',  'IAU_SUN', */
/*             .              'LT',     'EARTH',      CNVTOL, */
/*             .              GFSTEP,   GFREFN,       RPT, */
/*             .              GFREPI,   GFREPU,       GFREPF, */
/*             .              BAIL,     GFBAIL,       CNFINE,  RESULT ) */


/*             ... */



/*     2)  The following piece of code provides a more concrete example */
/*         of how these routines might be used.  It is part of code that */
/*         performs a search for the time of an occultation of one body */
/*         by another. It is intended only for illustration and is not */
/*         recommended for use in code that has to do real work. */

/*  C */
/*  C     Prepare the progress reporter if appropriate. */
/*  C */
/*        IF ( RPT ) THEN */
/*           CALL UDREPI ( CNFINE, 'Occultation/transit search ', */
/*       .                         'done.'                        ) */
/*        END IF */

/*  C */
/*  C     Cycle over the intervals in the confining window. */
/*  C */
/*        COUNT = WNCARD(CNFINE) */

/*        DO I = 1, COUNT */
/*  C */
/*  C        Retrieve the bounds for the Ith interval of the confinement */
/*  C        window. Search this interval for occultation events. */
/*  C        Union the result with the contents of the RESULT window. */
/*  C */
/*           CALL WNFETD ( CNFINE, I, START, FINISH  ) */

/*           CALL ZZGFSOLV ( ZZGFOCST,   UDSTEP,   UDREFN,   BAIL, */
/*    .                      UDBAIL,     CSTEP,    STEP,     START, */
/*       .                   FINISH,     TOL,      RPT,      UDREPU, */
/*       .                   RESULT   ) */


/*           IF (  FAILED()  ) THEN */
/*              CALL CHKOUT ( 'GFOCCE'  ) */
/*              RETURN */
/*           END IF */

/*           IF ( BAIL ) THEN */
/*  C */
/*  C           Interrupt handling is enabled. */
/*  C */
/*              IF ( UDBAIL () ) THEN */
/*  C */
/*  C              An interrupt has been issued. Return now regardless of */
/*  C              whether the search has been completed. */
/*  C */
/*                 CALL CHKOUT ( 'GFOCCE' ) */
/*                 RETURN */

/*              END IF */

/*           END IF */

/*        END DO */

/*  C */
/*  C     End the progress report. */
/*  C */
/*        IF ( RPT ) THEN */
/*           CALL UDREPF */
/*        END IF */


/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     L.S. Elson     (JPL) */
/*     W.L. Taber     (JPL) */
/*     I.M. Underwood (JPL) */
/*     B.V. Semenov   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.1 10-FEB-2014 (BVS) */

/*        Added declarations of IVBEG and IVEND to the Declarations */
/*        section of the GFREPU header. */

/*        Corrected declaration of WINDOW in the Declarations */
/*        section and added descriptions of LBCELL to the GFREPI */
/*        header. */

/* -    SPICELIB Version 1.0.0 06-MAR-2009 (NJB) (LSE) (WLT) (IMU) */


/* -& */
/* $ Index_Entries */

/*     GF progress report umbrella */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */

    /* Parameter adjustments */
    if (window) {
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_gfrepi;
	case 2: goto L_gfrepu;
	case 3: goto L_gfrepf;
	}

    chkin_(__global_state, "GFRPRT", (ftnlen)6);
    sigerr_(__global_state, "SPICE(BOGUSENTRY)", (ftnlen)17);
    chkout_(__global_state, "GFRPRT", (ftnlen)6);
    return 0;
/* $Procedure GFREPI ( GF, progress report initialization ) */

L_gfrepi:
/* $ Abstract */

/*     This entry point initializes a search progress report. */

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

/*     GF */

/* $ Keywords */

/*     SEARCH */
/*     UTILITY */

/* $ Declarations */

/*     DOUBLE PRECISION      WINDOW ( LBCELL : * ) */
/*     CHARACTER*(*)         BEGMSS */
/*     CHARACTER*(*)         ENDMSS */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     LBCELL     P   The SPICELIB cell lower bound. */
/*     MXBEGM     P   Maximum progress report message prefix length. */
/*     MXENDM     P   Maximum progress report message suffix length. */
/*     WINDOW     I   A window over which a job is to be performed. */
/*     BEGMSS     I   Beginning of the text portion of the output message */
/*     ENDMSS     I   End of the text portion of the output message */

/* $ Detailed_Input */

/*     WINDOW   is the name of a constraint window. This is the window */
/*              associated with some root finding activity. It is */
/*              used to determine how much total time is being searched */
/*              in order to find the events of interest. */

/*     BEGMSS   is the beginning of the output message reported by the */
/*              routine GFRPWK.  This output message has the form */

/*                 BEGMSS(1:LASTNB(BEGMSS)) // ' xx.xx% ' // ENDMSS */

/*              BEGMSS must have length not greater than MXBEGM */
/*              characters. All characters of BEGMSS must be printable. */

/*     ENDMSS   is the last portion of the output message reported by */
/*              the routine GFRPWK. */

/*              ENDMSS must have length not greater than MXBENM */
/*              characters. All characters of ENDMSS must be printable. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     LBCELL     is the SPICELIB cell lower bound. */

/*     MXBEGM, */
/*     MXENDM    are, respectively, the maximum lengths of the progress */
/*               report message prefix and suffix. See the INCLUDE file */
/*               zzgf.inc for details. */

/* $ Exceptions */

/*     1) If BEGMSS has length greater than MXBEGM characters, or if */
/*        ENDMSS has length greater than MXENDM characters, the error */
/*        SPICE(MESSAGETOOLONG) is signaled. */

/*     2) If either BEGMSS or ENDMSS contains non-printing characters, */
/*        the error SPICE(NOTPRINTABLECHARS) is signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This entry point initializes the GF progress reporting system. It */
/*     is called by the GF root finding utilities once at the start of */
/*     each search pass. See the Particulars section of the main */
/*     subroutine header for further details of its function. */

/* $ Examples */

/*     See the header of the umbrella routine GFRPRT. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     L.S. Elson     (JPL) */
/*     W.L. Taber     (JPL) */
/*     I.M. Underwood (JPL) */
/*     B.V. Semenov   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.1 10-FEB-2014 (BVS) */

/*        Corrected declaration of WINDOW in the Declarations */
/*        section. Added description of LBCELL to the Declarations, */
/*        Brief_I/O, and Parameters sections. */

/* -    SPICELIB Version 1.0.0 21-FEB-2009 (NJB) (LSE) (WLT) (IMU) */

/* -& */
/* $ Index_Entries */

/*     GF initialize a progress report */

/* -& */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "GFREPI", (ftnlen)6);

/*     Check to see if either the message prefix or suffix */
/*     is too long. */

    if (lastnb_(__global_state, begmss, begmss_len) > 55) {
	setmsg_(__global_state, "Progress report prefix message contains # c"
		"haracters; limit is #.", (ftnlen)65);
	i__1 = lastnb_(__global_state, begmss, begmss_len);
	errint_(__global_state, "#", &i__1, (ftnlen)1);
	errint_(__global_state, "#", &__state->c__55, (ftnlen)1);
	sigerr_(__global_state, "SPICE(MESSAGETOOLONG)", (ftnlen)21);
	chkout_(__global_state, "GFREPI", (ftnlen)6);
	return 0;
    }
    if (lastnb_(__global_state, endmss, endmss_len) > 13) {
	setmsg_(__global_state, "Progress report suffix message contains # c"
		"haracters; limit is #.", (ftnlen)65);
	i__1 = lastnb_(__global_state, endmss, endmss_len);
	errint_(__global_state, "#", &i__1, (ftnlen)1);
	errint_(__global_state, "#", &__state->c__13, (ftnlen)1);
	sigerr_(__global_state, "SPICE(MESSAGETOOLONG)", (ftnlen)21);
	chkout_(__global_state, "GFREPI", (ftnlen)6);
	return 0;
    }

/*     Now check that all the characters in the message prefix and */
/*     suffix can be printed. */

    i__1 = lastnb_(__global_state, begmss, begmss_len);
    for (i__ = 1; i__ <= i__1; ++i__) {
	chrcod = *(unsigned char *)&begmss[i__ - 1];
	if (chrcod < 32 || chrcod > 126) {
	    setmsg_(__global_state, "The progress report message prefix cont"
		    "ains a nonprintable character; ASCII code is #.", (ftnlen)
		    86);
	    errint_(__global_state, "#", &chrcod, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(NONPRINTABLECHARS)", (ftnlen)24);
	    chkout_(__global_state, "GFREPI", (ftnlen)6);
	    return 0;
	}
    }
    i__1 = lastnb_(__global_state, endmss, endmss_len);
    for (i__ = 1; i__ <= i__1; ++i__) {
	chrcod = *(unsigned char *)&endmss[i__ - 1];
	if (chrcod < 32 || chrcod > 126) {
	    setmsg_(__global_state, "The progress report message suffix cont"
		    "ains a nonprintable character; ASCII code is #.", (ftnlen)
		    86);
	    errint_(__global_state, "#", &chrcod, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(NONPRINTABLECHARS)", (ftnlen)24);
	    chkout_(__global_state, "GFREPI", (ftnlen)6);
	    return 0;
	}
    }
    s_copy(&__global_state->f2c, __state->copyb, begmss, (ftnlen)55, 
	    begmss_len);
    s_copy(&__global_state->f2c, __state->copye, endmss, (ftnlen)13, 
	    endmss_len);

/*     Find the length of the window. Use that to initialize the work */
/*     reporter. */

    wnsumd_(__global_state, window, &measur, &ave, &stddev, &short__, &long__)
	    ;
    zzgftswk_(__global_state, &measur, &__state->c_b26, &__state->c__4, 
	    begmss, endmss, begmss_len, endmss_len);
    if (failed_(__global_state)) {
	chkout_(__global_state, "GFREPI", (ftnlen)6);
	return 0;
    }

/*     Initialize the time to the start of the confinement window. */
/*     The remaining amount of work in the current interval is */
/*     the measure of the interval. */

    if (cardd_(__global_state, window) >= 2) {
	__state->t0 = window[6];
	__state->remain = window[7] - __state->t0;
    } else {
	__state->remain = 0.;
    }
    chkout_(__global_state, "GFREPI", (ftnlen)6);
    return 0;
/* $Procedure   GFREPU ( GF, progress report update ) */

L_gfrepu:
/* $ Abstract */

/*     This entry point tells the progress reporting system */
/*     how far a search has progressed. */

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

/*     GF */

/* $ Keywords */

/*     SEARCH */
/*     UTILITY */

/* $ Declarations */

/*     DOUBLE PRECISION      IVBEG */
/*     DOUBLE PRECISION      IVEND */
/*     DOUBLE PRECISION      TIME */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     IVBEG      I   Start time of work interval. */
/*     IVEND      I   End time of work interval. */
/*     TIME       I   Current time being examined in the search process */

/* $ Detailed_Input */

/*     IVBEG, */
/*     IVEND    are the bounds of an interval that is contained in some */
/*              interval belonging to the confinement window. The */
/*              confinement window is associated with some root finding */
/*              activity. It is used to determine how much total time is */
/*              being searched in order to find the events of interest. */

/*              In order for a meaningful progress report to be */
/*              displayed, IVBEG and IVEND must satisfy the following */
/*              constraints: */

/*                 - IVBEG must be less than or equal to IVEND. */

/*                 - The interval [ IVBEG, IVEND ] must be contained in */
/*                   some interval of the confinement window. It can be */
/*                   a proper subset of the containing interval; that */
/*                   is, it can be smaller than the interval of the */
/*                   confinement window that contains it. */

/*                 - Over a search pass, the sum of the differences */

/*                      IVEND - IVBEG */

/*                   for all calls to this routine made during the pass */
/*                   must equal the measure of the confinement window. */


/*     TIME     is the current time reached in the search for an event. */
/*              TIME must lie in the interval */

/*                 IVBEG : IVEND */

/*              inclusive. The input values of TIME for a given interval */
/*              need not form an increasing sequence. */

/* $ Detailed_Output */

/*     None. This routine does perform console I/O when progress */
/*     reporting is enabled. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If IVBEG and IVEND are in decreasing order, the error */
/*        SPICE(BADENDPOINTS) is signaled. */

/*     2) If TIME is not in the closed interval [IVBEG, IVEND], the */
/*        error SPICE(VALUEOUTOFRANGE) is signaled. */

/*     3) Any I/O errors resulting from writing to standard output */
/*        will be diagnosed by routines in the call tree of this */
/*        routine. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This entry point is used to indicate the current progress of a */
/*     search. Using information recorded through the initialization */
/*     entry point of this routine, the progress reporting system */
/*     determines how much work has been completed and whether or not to */
/*     report it on the users screen. */

/* $ Examples */

/*     See the header of the umbrella routine GFRPRT. */

/* $ Restrictions */

/*     This routine has no way of enforcing that the input values of */
/*     IVBEG and IVEND are compatible with the input window passed to */
/*     GFREPI. Callers of this routine are responsible for ensuring */
/*     that this requirement is obeyed. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     L.S. Elson     (JPL) */
/*     W.L. Taber     (JPL) */
/*     I.M. Underwood (JPL) */
/*     B.V. Semenov   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.1 10-FEB-2014 (BVS) */

/*        Added declarations of IVBEG and IVEND to the Declarations */
/*        section. */

/* -    SPICELIB Version 1.0.0 21-FEB-2009 (NJB) (LSE) (WLT) (IMU) */

/* -& */
/* $ Index_Entries */

/*     GF update a progress report */

/* -& */
    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "GFREPU", (ftnlen)6);

/*     Do a few error checks before getting started. */

/*     We expect the endpoints of the current window to be in order. */

    if (*ivend < *ivbeg) {
	setmsg_(__global_state, "Interval endpoints are #:#; endpoints must "
		"be in increasing order.", (ftnlen)66);
	errdp_(__global_state, "#", ivbeg, (ftnlen)1);
	errdp_(__global_state, "#", ivend, (ftnlen)1);
	sigerr_(__global_state, "SPICE(BADENDPOINTS)", (ftnlen)19);
	chkout_(__global_state, "GFREPU", (ftnlen)6);
	return 0;
    }

/*     We expect TIME to be in the current interval of the confinement */
/*     window. */

    if (*time < *ivbeg || *time > *ivend) {
	setmsg_(__global_state, "TIME should be in interval #:# but is #.", (
		ftnlen)40);
	errdp_(__global_state, "#", time, (ftnlen)1);
	errdp_(__global_state, "#", ivbeg, (ftnlen)1);
	errdp_(__global_state, "#", ivend, (ftnlen)1);
	sigerr_(__global_state, "SPICE(VALUEOUTOFRANGE)", (ftnlen)22);
	chkout_(__global_state, "GFREPU", (ftnlen)6);
	return 0;
    }

/*     The amount of work done is the difference between the current */
/*     time and the previous time T0, presuming both times are in */
/*     the current interval.  Note this work amount may be negative. */

    if (__state->t0 >= *ivbeg && __state->t0 <= *ivend) {
	incr = *time - __state->t0;
    } else {

/*        T0 is in the previous interval.  The amount of work */
/*        done to complete processing of that interval is REMAIN. */
/*        The amount of work done in the current interval is */
/*        the difference of TIME and the left endpoint of the */
/*        interval. */

	incr = __state->remain + *time - *ivbeg;
    }

/*     The remaining work is the distance from TIME to the right */
/*     endpoint of the current interval. */

    __state->remain = *ivend - *time;

/*     Record the current time as T0. */

    __state->t0 = *time;

/*     Report the work increment. */

    zzgfwkin_(__global_state, &incr);
    chkout_(__global_state, "GFREPU", (ftnlen)6);
    return 0;
/* $Procedure      GFREPF ( GF, progress report finalization ) */

L_gfrepf:
/* $ Abstract */

/*     Finish a progress report. */

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

/*     GF */

/* $ Keywords */

/*     SEARCH */
/*     UTILITY */

/* $ Declarations */

/*     None. */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     None. */

/* $ Detailed_Input */

/*     None. */

/* $ Detailed_Output */

/*     None. This routine does perform console I/O when progress */
/*     reporting is enabled. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Any I/O errors resulting from writing to standard output */
/*        will be diagnosed by routines in the call tree of this */
/*        routine. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This entry point "finishes" a progress report, i.e. updates the */
/*     report to indicate the underlying task is 100% complete. */

/* $ Examples */

/*     See the header of the umbrella routine GFRPRT. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     L.S. Elson     (JPL) */
/*     W.L. Taber     (JPL) */
/*     I.M. Underwood (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0 21-FEB-2009 (NJB) (LSE) (WLT) (IMU) */

/* -& */
/* $ Index_Entries */

/*     GF finish a progress report */

/* -& */
    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "GFREPF", (ftnlen)6);
    zzgfwkad_(__global_state, &__state->c_b44, &__state->c__1, __state->copyb,
	     __state->copye, (ftnlen)55, (ftnlen)13);
    zzgfwkin_(__global_state, &__state->c_b44);

/*     Determine whether progress report output is currently */
/*     being sent to standard output. Fetch the output unit. */

    zzgfwkmo_(__global_state, &unit, &total, &freq, &tcheck, begin, end, &
	    incr, (ftnlen)55, (ftnlen)13);
    stdio_(__global_state, "STDOUT", &stdout, (ftnlen)6);
    if (unit != stdout) {

/*        We're not currently writing to standard output, so we're */
/*        done. */

	chkout_(__global_state, "GFREPF", (ftnlen)6);
	return 0;
    }

/*     Emit a final blank line by moving the cursor down two */
/*     spaces. */

/*     The set of actual arguments passed here is rather funky */
/*     and deserves some explanation: */

/*        The first argument, calling for a leading blank line, moves */
/*        the cursor down so that the next blank line written won't */
/*        overwrite the final status message. That blank line is */
/*        followed with a cursor repositioning command that moves the */
/*        cursor to the beginning of the line that was just written. The */
/*        last argument, calling for another blank line, moves the */
/*        cursor down again. The total cursor movement is down 2 lines. */
/*        This results in one skipped line. */

/*     We could accomplish the same results more simply if were */
/*     were to use I/O statements in this routine; however, in the */
/*     interest of minimizing the number of places where I/O is */
/*     performed, we rely on ZZGFDSPS to do that job. */

    zzgfdsps_(__global_state, &__state->c__1, " ", "A", &__state->c__1, (
	    ftnlen)1, (ftnlen)1);
    chkout_(__global_state, "GFREPF", (ftnlen)6);
    return 0;
} /* gfrprt_ */

/* Subroutine */ int gfrprt_(cspice_t* __global_state, doublereal *window, 
	char *begmss, char *endmss, doublereal *ivbeg, doublereal *ivend, 
	doublereal *time, ftnlen begmss_len, ftnlen endmss_len)
{
    return gfrprt_0_(0, window, begmss, endmss, ivbeg, ivend, time, 
	    begmss_len, endmss_len);
    }

/* Subroutine */ int gfrepi_(cspice_t* __global_state, doublereal *window, 
	char *begmss, char *endmss, ftnlen begmss_len, ftnlen endmss_len)
{
    return gfrprt_0_(1, window, begmss, endmss, (doublereal *)0, (doublereal *
	    )0, (doublereal *)0, begmss_len, endmss_len);
    }

/* Subroutine */ int gfrepu_(cspice_t* __global_state, doublereal *ivbeg, 
	doublereal *ivend, doublereal *time)
{
    return gfrprt_0_(2, (doublereal *)0, (char *)0, (char *)0, ivbeg, ivend, 
	    time, (ftnint)0, (ftnint)0);
    }

/* Subroutine */ int gfrepf_(cspice_t* __global_state)
{
    return gfrprt_0_(3, (doublereal *)0, (char *)0, (char *)0, (doublereal *)
	    0, (doublereal *)0, (doublereal *)0, (ftnint)0, (ftnint)0);
    }

