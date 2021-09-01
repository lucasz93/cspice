/* zzprscor.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzprscor_init_t __zzprscor_init;
static zzprscor_state_t* get_zzprscor_state(cspice_t* state) {
	if (!state->zzprscor)
		state->zzprscor = __cspice_allocate_module(sizeof(
	zzprscor_state_t), &__zzprscor_init, sizeof(__zzprscor_init));
	return state->zzprscor;

}

/* $Procedure ZZPRSCOR ( Parse aberration correction ) */
/* Subroutine */ int zzprscor_(cspice_t* __global_state, char *abcorr, 
	logical *attblk, ftnlen abcorr_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);

    /* Local variables */
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern integer bsrchc_(cspice_t*, char *, integer *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int orderc_(cspice_t*, char *, integer *, integer 
	    *, ftnlen);
    extern /* Subroutine */ int reordc_(cspice_t*, integer *, integer *, char 
	    *, ftnlen);
    integer ordvec[15];
    extern /* Subroutine */ int reordl_(cspice_t*, integer *, integer *, 
	    logical *);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int ljucrs_(cspice_t*, integer *, char *, char *, 
	    ftnlen, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    char tmpcor[5];
    extern logical return_(cspice_t*);
    integer loc;


    /* Module state */
    zzprscor_state_t* __state = get_zzprscor_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Parse an aberration correction string; return attributes. */

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

/*     ABERRATION */
/*     PARSING */
/*     PRIVATE */
/*     UTILITY */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  ------------------------------------------------- */
/*     ABCORR     I   Aberration correction string. */
/*     ATTBLK     O   Aberration correction attribute block. */

/* $ Detailed_Input */

/*     ABCORR         is a string representing a aberration */
/*                    correction.  The supported values are: */

/*                       'CN' */
/*                       'CN+S' */
/*                       'LT' */
/*                       'LT+S' */
/*                       'NONE' */
/*                       'RL' */
/*                       'RL+S' */
/*                       'S' */
/*                       'XCN' */
/*                       'XCN+S' */
/*                       'XLT' */
/*                       'XLT+S' */
/*                       'XRL' */
/*                       'XRL+S' */
/*                       'XS' */

/*                    Note that some values not supported by the */
/*                    SPICELIB SPK subsystem are supported by */
/*                    this routine: */

/*                       - The letter 'R' indicates relativistic */
/*                         corrections. */

/*                       - Stellar aberration-only corrections are */
/*                         indicated by the strings */

/*                            'S' */
/*                            'XS' */

/*                    Case and embedded blanks are not significant in */
/*                    ABCORR. */

/* $ Detailed_Output */

/*     ATTBLK         is a block of logical flags indicating the */
/*                    attributes of the aberration correction */
/*                    specified by ABCORR.  The attributes are: */

/*                       - Is the correction "geometric"? */

/*                       - Is light time correction indicated? */

/*                       - Is stellar aberration correction indicated? */

/*                       - Is the light time correction of the */
/*                         "converged Newtonian" variety? */

/*                       - Is the correction for the transmission */
/*                         case? */

/*                       - Is the correction relativistic? */

/*                    The structure of ATTBLK is defined in the */
/*                    include file */

/*                       zzabcorr.inc */

/*                    The size of ATTBLK and the offsets of the */
/*                    component flags are defined there. */

/* $ Parameters */

/*     See INCLUDE file zzabcorr.inc. */

/* $ Exceptions */

/*     1) If the input aberration correction choice is not recognized, */
/*        the error SPICE(INVALIDOPTION) is signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     Many SPICELIB routines have logic branches based on the */
/*     attributes of aberration corrections.  Much duplicated */
/*     parsing code can be avoided by using this routine. */

/*     In particular, the routine ZZCOREPC uses this routine */
/*     to combine an epoch and light time value to compute */
/*     a light-time-adjusted epoch. */

/* $ Examples */

/*     See ZZCOREPC. */

/* $ Restrictions */

/*     1) This is a SPICE private routine; the routine is subject */
/*        to change without notice.  User applications should not */
/*        call this routine. */

/*     2) This routine recognizes some aberration corrections not */
/*        handled by most SPICELIB routines.  Callers should do */
/*        their own checking to ensure the parsed correction is */
/*        acceptable. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     B.V. Semenov    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 21-SEP-2013 (BVS) */

/*        Efficiency updates: moved CHKIN inside the exception block; */
/*        replaced CMPRSS/UCASE with LJUCRS. */

/* -    SPICELIB Version 1.0.0, 13-DEC-2004 (NJB) */

/* -& */

/*     SPICELIB functions */

/* $ Abstract */

/*     Include file zzabcorr.inc */

/*     SPICE private file intended solely for the support of SPICE */
/*     routines.  Users should not include this file directly due */
/*     to the volatile nature of this file */

/*     The parameters below define the structure of an aberration */
/*     correction attribute block. */

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

/*     An aberration correction attribute block is an array of logical */
/*     flags indicating the attributes of the aberration correction */
/*     specified by an aberration correction string.  The attributes */
/*     are: */

/*        - Is the correction "geometric"? */

/*        - Is light time correction indicated? */

/*        - Is stellar aberration correction indicated? */

/*        - Is the light time correction of the "converged */
/*          Newtonian" variety? */

/*        - Is the correction for the transmission case? */

/*        - Is the correction relativistic? */

/*    The parameters defining the structure of the block are as */
/*    follows: */

/*       NABCOR    Number of aberration correction choices. */

/*       ABATSZ    Number of elements in the aberration correction */
/*                 block. */

/*       GEOIDX    Index in block of geometric correction flag. */

/*       LTIDX     Index of light time flag. */

/*       STLIDX    Index of stellar aberration flag. */

/*       CNVIDX    Index of converged Newtonian flag. */

/*       XMTIDX    Index of transmission flag. */

/*       RELIDX    Index of relativistic flag. */

/*    The following parameter is not required to define the block */
/*    structure, but it is convenient to include it here: */

/*       CORLEN    The maximum string length required by any aberration */
/*                 correction string */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 18-DEC-2004 (NJB) */

/* -& */
/*     Number of aberration correction choices: */


/*     Aberration correction attribute block size */
/*     (number of aberration correction attributes): */


/*     Indices of attributes within an aberration correction */
/*     attribute block: */


/*     Maximum length of an aberration correction string: */


/*     End of include file zzabcorr.inc */


/*     Local variables */


/*     Saved variables */


/*     Initial values */


/*     It is recommended that, for maintainability, the correction */
/*     strings be kept in increasing order in this list.  However, */
/*     this routine does not rely on the strings being ordered */
/*     in this data statement:  the strings and associated values */
/*     are ordered at run time. */

    if (return_(__global_state)) {
	return 0;
    }
    if (__state->first) {

/*        The first time this routine is called, we sort the */
/*        aberration correction strings and the associated flag */
/*        lists.  This ensures we have an ordered list suitable */
/*        for a binary search. */

/*        Find the sorted order of the aberration correction strings. */

	orderc_(__global_state, __state->corlst, &__state->c__15, ordvec, (
		ftnlen)5);

/*        Put the aberration correction strings and the associated */
/*        arrays into increasing order. */

	reordc_(__global_state, ordvec, &__state->c__15, __state->corlst, (
		ftnlen)5);
	reordl_(__global_state, ordvec, &__state->c__15, __state->geo);
	reordl_(__global_state, ordvec, &__state->c__15, __state->lt);
	reordl_(__global_state, ordvec, &__state->c__15, __state->stl);
	reordl_(__global_state, ordvec, &__state->c__15, __state->conv);
	reordl_(__global_state, ordvec, &__state->c__15, __state->xmit);
	reordl_(__global_state, ordvec, &__state->c__15, __state->rel);
	__state->first = FALSE_;
    }

/*     Obtain a blank-free, upper-case copy of the aberration */
/*     correction string. */

    ljucrs_(__global_state, &__state->c__0, abcorr, tmpcor, abcorr_len, (
	    ftnlen)5);

/*     Search the list for the aberration correction string. */

    loc = bsrchc_(__global_state, tmpcor, &__state->c__15, __state->corlst, (
	    ftnlen)5, (ftnlen)5);
    if (loc == 0) {
	chkin_(__global_state, "ZZPRSCOR", (ftnlen)8);
	setmsg_(__global_state, "Aberration correction specification # is no"
		"t recognized.", (ftnlen)56);
	errch_(__global_state, "#", abcorr, (ftnlen)1, abcorr_len);
	sigerr_(__global_state, "SPICE(INVALIDOPTION)", (ftnlen)20);
	chkout_(__global_state, "ZZPRSCOR", (ftnlen)8);
	return 0;
    }

/*     Set the output flags. */

    attblk[0] = __state->geo[(i__1 = loc - 1) < 15 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "geo", i__1, "zzprscor_", (ftnlen)
	    318)];
    attblk[1] = __state->lt[(i__1 = loc - 1) < 15 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "lt", i__1, "zzprscor_", (ftnlen)319)
	    ];
    attblk[2] = __state->stl[(i__1 = loc - 1) < 15 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "stl", i__1, "zzprscor_", (ftnlen)
	    320)];
    attblk[3] = __state->conv[(i__1 = loc - 1) < 15 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "conv", i__1, "zzprscor_", (ftnlen)
	    321)];
    attblk[4] = __state->xmit[(i__1 = loc - 1) < 15 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "xmit", i__1, "zzprscor_", (ftnlen)
	    322)];
    attblk[5] = __state->rel[(i__1 = loc - 1) < 15 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "rel", i__1, "zzprscor_", (ftnlen)
	    323)];
    return 0;
} /* zzprscor_ */

