/* ckmeta.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern ckmeta_init_t __ckmeta_init;
static ckmeta_state_t* get_ckmeta_state(cspice_t* state) {
	if (!state->ckmeta)
		state->ckmeta = __cspice_allocate_module(sizeof(
	ckmeta_state_t), &__ckmeta_init, sizeof(__ckmeta_init));
	return state->ckmeta;

}

/* $Procedure      CKMETA ( CK ID to associated SCLK ) */
/* Subroutine */ int ckmeta_(cspice_t* __global_state, integer *ckid, char *
	meta, integer *idcode, ftnlen meta_len)
{
    /* Initialized data */


    /* System generated locals */
    address a__1[2];
    integer i__1, i__2, i__3[2];

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer), s_cmp(
	    f2c_state_t*, char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(f2c_state_t*, char *, char **, integer *, 
	    integer *, ftnlen), s_copy(f2c_state_t*, char *, char *, ftnlen, 
	    ftnlen);

    /* Local variables */
    extern /* Subroutine */ int zzcvpool_(cspice_t*, char *, integer *, 
	    logical *, ftnlen);
    extern /* Subroutine */ int zzctruin_(cspice_t*, integer *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern logical failed_(cspice_t*);
    extern /* Subroutine */ int clearc_(cspice_t*, integer *, char *, ftnlen);
    extern integer bschoi_(cspice_t*, integer *, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int orderi_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int gipool_(cspice_t*, char *, integer *, integer 
	    *, integer *, integer *, logical *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int prefix_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    extern /* Subroutine */ int ljucrs_(cspice_t*, integer *, char *, char *, 
	    ftnlen, ftnlen);
    extern /* Subroutine */ int cvpool_(cspice_t*, char *, logical *, ftnlen);
    extern /* Subroutine */ int dwpool_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int suffix_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int intstr_(cspice_t*, integer *, char *, ftnlen);
    extern /* Subroutine */ int swpool_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);

    /* Module state */
    ckmeta_state_t* __state = get_ckmeta_state(__global_state);
/* $ Abstract */

/*     This routine returns (depending upon the users' request) */
/*     the ID code of either the spacecraft or spacecraft clock */
/*     associated with a C-Kernel ID code. */

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
/*     CKID       I   The ID code for some C kernel object. */
/*     META       I   The kind of meta data requested 'SPK' or 'SCLK' */
/*     IDCODE     O   The ID code for the clock of the C kernel. */

/* $ Detailed_Input */

/*     CKID        is the ID code for some object whose attitude */
/*                 and possibly angular velocity are stored in */
/*                 some C-kernel. */

/*     META        is a character string that indicates which piece */
/*                 of meta data to fetch.  Acceptable values are */
/*                 'SCLK' and 'SPK'. The routine is case insensitive. */
/*                 Leading and trailing blanks are insignificant. */
/*                 However, blanks between characters are regarded */
/*                 as being significant and will result in the error */
/*                 'SPICE(UNKNOWNCKMETA)' being signaled. */

/* $ Detailed_Output */

/*     IDCODE      if META is 'SCLK' then the value returned in IDCODE */
/*                 is the "ID code" of the spacecraft clock used for */
/*                 converting ET to TICKS and TICKS to ET for the */
/*                 C-kernel used to represent the attitude of the */
/*                 object with ID code CKID. */

/*                 if META is 'SPK' then the value returned in IDCODE */
/*                 is the "ID code" of the spacecraft on which the */
/*                 platform indicated by CKID is mounted. */

/* $ Parameters */

/*      None. */

/* $ Exceptions */

/*     1) If the variable META is not recognized to be one of the */
/*        inputs 'SPK' or 'SCLK' then the error 'SPICE(UNKNOWNCKMETA)' */
/*        will be signaled. */

/*     2) If CKID is greater than -1000, the associated SCLK and SPK */
/*        ID's must be in the kernel pool.  If they are not present */
/*        a value of zero is returned for the requested item.  Zero */
/*        is never the valid ID of a spacecraft clock or ephemeris */
/*        object. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This is a utility routine for mapping C-kernels to associated */
/*     spacecraft clocks. This is needed to facilitate the writing */
/*     of routines such as CKPG and CKGPAV. */

/* $ Examples */

/*     Suppose you would like to look up the attitude of */
/*     an object in a C-kernel but have ET and seconds as your */
/*     input time and tolerance. */

/*     This routine can be used in conjunction with SCE2C and */
/*     CKGPAV to perform this task. */

/*     CALL CKMETA ( CKID,  'SCLK'      IDCODE ) */

/*     CALL SCE2C  ( IDCODE, ET,        TICKS  ) */
/*     CALL SCE2C  ( IDCODE, ET+SECTOL, TICK2  ) */

/*     TOL = TICK2 - TICKS */

/*     CALL CKGPAV ( CKID, TICKS, TOL, REF, CMAT, AV, CLKOUT, FOUND ) */

/*     IF ( FOUND ) THEN */

/*        CALL SCT2E ( IDCODE, CLKOUT, ETOUT ) */

/*     END IF */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     B.V. Semenov    (JPL) */
/*     W.L. Taber      (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.2.0, 06-SEP-2013 (BVS) */

/*        BUG FIX: the POOL agents now watch both variables -- */
/*        CK_<ID>_SCLK and CK_<ID>_SPK. Before they watched only */
/*        CK_<ID>_SCLK. */

/*        BUG FIX: if a previously available CK_<ID>_SCLK or CK_<ID>_SPK */
/*        variable that was used to populate a saved value disappears, */
/*        the routine now resets and returns the value based on the */
/*        default rule rather than keeping and returning the stale */
/*        POOL-based saved value. */

/*        BUG FIX: the routine now deletes watchers for the CK IDs that */
/*        were bumped from the local buffer. */

/*        Updated to keep track of agent-specific POOL counters and call */
/*        ZZCVPOOL to make use of them. */

/* -    SPICELIB Version 1.1.0, 05-MAR-2009 (NJB) */

/*        This routine now keeps track of whether its kernel pool */
/*        look-up failed. If so, a kernel pool lookup is attempted on */
/*        the next call to this routine. This change is an enhancement, */
/*        not a bug fix (unlike similar modifications in SCLK routines). */

/*        Header sections were put in correct order. */

/* -    SPICELIB Version 1.0.1, 09-MAR-1999 (NJB) */

/*        Comments referring to SCE2T have been updated to refer to */
/*        SCE2C.  Occurrences of "id" replaced by "ID." */

/* -    SPICELIB Version 1.0.0, 4-OCT-1994 (WLT) */


/* -& */
/* $ Index_Entries */

/*     Map C-kernel ID to SCLK and SPK ID */

/* -& */

/*     SPICELIB Functions */


/*     Local parameters */


/*     Local variables */


/*     Saved variables */


/*     Initial values */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "CKMETA", (ftnlen)6);
    if (__state->first) {

/*        Initialize all agent-specific POOL counters to user value. */

	for (__state->n = 1; __state->n <= 30; ++__state->n) {
	    zzctruin_(__global_state, &__state->usrctr[(i__1 = (__state->n << 
		    1) - 2) < 60 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "usrctr", i__1, "ckmeta_", (ftnlen)
		    275)]);
	}

/*        Clear AGENTS array. We will use a non-blank AGENT value as the */
/*        flag to delete previously set watchers. */

	clearc_(__global_state, &__state->c__30, __state->agent, (ftnlen)32);
	__state->first = FALSE_;
    }

/*     Get an upper-case, left-justified copy of the metadata */
/*     type ('SCLK' or 'SPK'). */

    ljucrs_(__global_state, &__state->c__1, meta, __state->mymeta, meta_len, (
	    ftnlen)7);

/*     See if we already have this CK ID in hand. */

    __state->this__ = bschoi_(__global_state, ckid, &__state->currnt, 
	    __state->cks, __state->cksord);
    if (__state->this__ > 0) {

/*        We've got it.  Check to see if its value has been updated. */
/*        (Note that every CK ID  has its own agent and saved POOL */
/*        counter.) */

	zzcvpool_(__global_state, __state->agent + (((i__1 = __state->this__ 
		- 1) < 30 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"agent", i__1, "ckmeta_", (ftnlen)305)) << 5), &
		__state->usrctr[(i__2 = (__state->this__ << 1) - 2) < 60 && 0 
		<= i__2 ? i__2 : s_rnge(&__global_state->f2c, "usrctr", i__2, 
		"ckmeta_", (ftnlen)305)], &__state->update, (ftnlen)32);
	if (__state->update || __state->nodata) {
	    gipool_(__global_state, __state->lookup + (((i__1 = (
		    __state->this__ << 1) - 2) < 60 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "lookup", i__1, "ckmeta_", (
		    ftnlen)309)) << 5), &__state->c__1, &__state->c__1, &
		    __state->n, &__state->sclks[(i__2 = __state->this__ - 1) <
		     30 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "sclks", i__2, "ckmeta_", (ftnlen)309)], __state->found, (
		    ftnlen)32);
	    gipool_(__global_state, __state->lookup + (((i__1 = (
		    __state->this__ << 1) - 1) < 60 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "lookup", i__1, "ckmeta_", (
		    ftnlen)312)) << 5), &__state->c__1, &__state->c__1, &
		    __state->n, &__state->spks[(i__2 = __state->this__ - 1) < 
		    30 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "spks", i__2, "ckmeta_", (ftnlen)312)], &__state->found[1]
		    , (ftnlen)32);
	    if (failed_(__global_state)) {
		__state->nodata = TRUE_;
		chkout_(__global_state, "CKMETA", (ftnlen)6);
		return 0;
	    }

/*           Note that failure to find data is not an error in this */
/*           routine; it's just SPICE errors that are a problem. */

	    __state->nodata = FALSE_;
	} else {

/*           The POOL variables did not change since the last check and */
/*           we have already buffered IDs for this CK ID. Set found */
/*           flags to make use of saved values. */

	    __state->found[0] = TRUE_;
	    __state->found[1] = TRUE_;
	}
    } else {

/*        We don't have this on our handy list. Find a place to put it. */

	if (__state->currnt < 30) {
	    ++__state->currnt;
	    __state->last = __state->currnt;
	} else {
	    ++__state->last;
	    if (__state->last > 30) {
		__state->last = 1;
	    }
	}
	__state->this__ = __state->last;

/*        If we already have a watcher at this index, delete it. Note */
/*        we may have an update pending for this watcher, so we will */
/*        check it first to clear it. */

	if (s_cmp(&__global_state->f2c, __state->agent + (((i__1 = 
		__state->this__ - 1) < 30 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "agent", i__1, "ckmeta_", (ftnlen)370)) 
		<< 5), " ", (ftnlen)32, (ftnlen)1) != 0) {
	    cvpool_(__global_state, __state->agent + (((i__1 = 
		    __state->this__ - 1) < 30 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "agent", i__1, "ckmeta_", (ftnlen)
		    371)) << 5), &__state->update, (ftnlen)32);
	    dwpool_(__global_state, __state->agent + (((i__1 = 
		    __state->this__ - 1) < 30 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "agent", i__1, "ckmeta_", (ftnlen)
		    372)) << 5), (ftnlen)32);
	}

/*        Recompute the order vector for the CKS; construct the */
/*        kernel pool variable names and the agent name. */

	__state->cks[(i__1 = __state->this__ - 1) < 30 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "cks", i__1, "ckmeta_", (ftnlen)
		379)] = *ckid;
	orderi_(__global_state, __state->cks, &__state->currnt, 
		__state->cksord);
	intstr_(__global_state, ckid, __state->lookup + (((i__1 = (
		__state->this__ << 1) - 2) < 60 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "lookup", i__1, "ckmeta_", (ftnlen)383)) 
		<< 5), (ftnlen)32);
	prefix_(__global_state, "CK_", &__state->c__0, __state->lookup + (((
		i__1 = (__state->this__ << 1) - 2) < 60 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "lookup", i__1, "ckmeta_", (
		ftnlen)384)) << 5), (ftnlen)3, (ftnlen)32);
/* Writing concatenation */
	i__3[0] = 7, a__1[0] = __state->base;
	i__3[1] = 32, a__1[1] = __state->lookup + (((i__2 = (__state->this__ 
		<< 1) - 2) < 60 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "lookup", i__2, "ckmeta_", (ftnlen)386)) 
		<< 5);
	s_cat(&__global_state->f2c, __state->agent + (((i__1 = 
		__state->this__ - 1) < 30 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "agent", i__1, "ckmeta_", (ftnlen)386)) 
		<< 5), a__1, i__3, &__state->c__2, (ftnlen)32);
	s_copy(&__global_state->f2c, __state->lookup + (((i__1 = (
		__state->this__ << 1) - 1) < 60 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "lookup", i__1, "ckmeta_", (ftnlen)387)) 
		<< 5), __state->lookup + (((i__2 = (__state->this__ << 1) - 2)
		 < 60 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		"lookup", i__2, "ckmeta_", (ftnlen)387)) << 5), (ftnlen)32, (
		ftnlen)32);
	suffix_(__global_state, "_SCLK", &__state->c__0, __state->lookup + (((
		i__1 = (__state->this__ << 1) - 2) < 60 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "lookup", i__1, "ckmeta_", (
		ftnlen)389)) << 5), (ftnlen)5, (ftnlen)32);
	suffix_(__global_state, "_SPK", &__state->c__0, __state->lookup + (((
		i__1 = (__state->this__ << 1) - 1) < 60 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "lookup", i__1, "ckmeta_", (
		ftnlen)390)) << 5), (ftnlen)4, (ftnlen)32);

/*        Set a watch for this item and fetch the current value */
/*        from the kernel pool (if there is a value there). */

	swpool_(__global_state, __state->agent + (((i__1 = __state->this__ - 
		1) < 30 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"agent", i__1, "ckmeta_", (ftnlen)396)) << 5), &__state->c__2,
		 __state->lookup + (((i__2 = (__state->this__ << 1) - 2) < 60 
		&& 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "lookup", 
		i__2, "ckmeta_", (ftnlen)396)) << 5), (ftnlen)32, (ftnlen)32);
	cvpool_(__global_state, __state->agent + (((i__1 = __state->this__ - 
		1) < 30 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"agent", i__1, "ckmeta_", (ftnlen)398)) << 5), &
		__state->update, (ftnlen)32);
	gipool_(__global_state, __state->lookup + (((i__1 = (__state->this__ 
		<< 1) - 2) < 60 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "lookup", i__1, "ckmeta_", (ftnlen)400)) 
		<< 5), &__state->c__1, &__state->c__1, &__state->n, &
		__state->sclks[(i__2 = __state->this__ - 1) < 30 && 0 <= i__2 
		? i__2 : s_rnge(&__global_state->f2c, "sclks", i__2, "ckmeta_"
		, (ftnlen)400)], __state->found, (ftnlen)32);
	gipool_(__global_state, __state->lookup + (((i__1 = (__state->this__ 
		<< 1) - 1) < 60 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "lookup", i__1, "ckmeta_", (ftnlen)403)) 
		<< 5), &__state->c__1, &__state->c__1, &__state->n, &
		__state->spks[(i__2 = __state->this__ - 1) < 30 && 0 <= i__2 ?
		 i__2 : s_rnge(&__global_state->f2c, "spks", i__2, "ckmeta_", 
		(ftnlen)403)], &__state->found[1], (ftnlen)32);
	if (failed_(__global_state)) {
	    __state->nodata = TRUE_;
	    chkout_(__global_state, "CKMETA", (ftnlen)6);
	    return 0;
	}

/*        Note that failure to find data is not an error in this */
/*        routine; it's just SPICE errors that are a problem. */

/*        At this point, kernel data checks are done. */

	__state->nodata = FALSE_;
    }

/*     If we didn't find either _SCLK or _SPK variable, we manufacture */
/*     an ID code based upon the "convention" used for all CKS so far. */
/*     However, the convention assumes that the CK ID will be less than */
/*     -1000 if it's not there is no sensible ID to return.  We return */
/*     zero in that case. */

    if (! __state->found[0]) {
	if (__state->cks[(i__1 = __state->this__ - 1) < 30 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "cks", i__1, "ckmeta_", (
		ftnlen)435)] <= -1000) {
	    __state->sclks[(i__1 = __state->this__ - 1) < 30 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "sclks", i__1, "ckme"
		    "ta_", (ftnlen)437)] = __state->cks[(i__2 = 
		    __state->this__ - 1) < 30 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "cks", i__2, "ckmeta_", (ftnlen)437)]
		     / 1000;
	} else {
	    __state->sclks[(i__1 = __state->this__ - 1) < 30 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "sclks", i__1, "ckme"
		    "ta_", (ftnlen)441)] = 0;
	}
    }
    if (! __state->found[1]) {
	if (__state->cks[(i__1 = __state->this__ - 1) < 30 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "cks", i__1, "ckmeta_", (
		ftnlen)449)] <= -1000) {
	    __state->spks[(i__1 = __state->this__ - 1) < 30 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "spks", i__1, "ckmet"
		    "a_", (ftnlen)451)] = __state->cks[(i__2 = __state->this__ 
		    - 1) < 30 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "cks", i__2, "ckmeta_", (ftnlen)451)]
		     / 1000;
	} else {
	    __state->spks[(i__1 = __state->this__ - 1) < 30 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "spks", i__1, "ckmet"
		    "a_", (ftnlen)455)] = 0;
	}
    }

/*     Set output ID. */

    if (s_cmp(&__global_state->f2c, __state->mymeta, "SPK", (ftnlen)7, (
	    ftnlen)3) == 0) {
	*idcode = __state->spks[(i__1 = __state->this__ - 1) < 30 && 0 <= 
		i__1 ? i__1 : s_rnge(&__global_state->f2c, "spks", i__1, 
		"ckmeta_", (ftnlen)466)];
    } else if (s_cmp(&__global_state->f2c, __state->mymeta, "SCLK", (ftnlen)7,
	     (ftnlen)4) == 0) {
	*idcode = __state->sclks[(i__1 = __state->this__ - 1) < 30 && 0 <= 
		i__1 ? i__1 : s_rnge(&__global_state->f2c, "sclks", i__1, 
		"ckmeta_", (ftnlen)470)];
    } else {
	*idcode = 0;
	setmsg_(__global_state, "The CK meta data item \"#\" is not a recogn"
		"ized meta data item for the routine CKMETA. The recognized v"
		"alue are \"SPK\" and \"SCLK\". ", (ftnlen)128);
	errch_(__global_state, "#", meta, (ftnlen)1, meta_len);
	sigerr_(__global_state, "SPICE(UNKNOWNCKMETA)", (ftnlen)20);
	chkout_(__global_state, "CKMETA", (ftnlen)6);
	return 0;
    }
    chkout_(__global_state, "CKMETA", (ftnlen)6);
    return 0;
} /* ckmeta_ */

