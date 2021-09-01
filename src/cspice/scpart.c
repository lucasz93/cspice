/* scpart.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern scpart_init_t __scpart_init;
static scpart_state_t* get_scpart_state(cspice_t* state) {
	if (!state->scpart)
		state->scpart = __cspice_allocate_module(sizeof(
	scpart_state_t), &__scpart_init, sizeof(__scpart_init));
	return state->scpart;

}

/* $Procedure      SCPART ( Spacecraft Clock Partition Information ) */
/* Subroutine */ int scpart_(cspice_t* __global_state, integer *sc, integer *
	nparts, doublereal *pstart, doublereal *pstop)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);
    double d_nint(f2c_state_t*, doublereal *);

    /* Local variables */
    extern /* Subroutine */ int zzcvpool_(cspice_t*, char *, integer *, 
	    logical *, ftnlen);
    extern /* Subroutine */ int zzctruin_(cspice_t*, integer *);
    integer i__;
    extern /* Subroutine */ int scld01_(cspice_t*, char *, integer *, integer 
	    *, integer *, doublereal *, ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int repmi_(cspice_t*, char *, char *, integer *, 
	    char *, ftnlen, ftnlen, ftnlen);
    extern logical failed_(cspice_t*);
    char kvname[60*2];
    logical update;
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int suffix_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    integer nprtsa;
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int swpool_(cspice_t*, char *, integer *, char *, 
	    ftnlen, ftnlen);
    integer nprtso;

    /* Module state */
    scpart_state_t* __state = get_scpart_state(__global_state);
/* $ Abstract */

/*     Get spacecraft clock partition information from a spacecraft */
/*     clock kernel file. */

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

/*     SCLK */

/* $ Keywords */

/*     TIME */

/* $ Declarations */
/* $ Abstract */

/*     Include file sclk.inc */

/*     SPICE private file intended solely for the support of SPICE */
/*     routines.  Users should not include this file directly due */
/*     to the volatile nature of this file */

/*     The parameters below define sizes and limits used by */
/*     the SCLK system. */

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

/*     See the declaration section below. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 24-MAY-2010 (NJB) */

/*        Increased value of maximum coefficient record count */
/*        parameter MXCOEF from 10K to 50K. */

/* -    SPICELIB Version 1.0.0, 11-FEB-2008 (NJB) */

/* -& */

/*     Number of supported SCLK field delimiters: */


/*     Supported SCLK string field delimiters: */


/*     Maximum number of partitions: */


/*     Partition string length. */

/*     Since the maximum number of partitions is given by MXPART is */
/*     9999, PRTSTR needs at most 4 characters for the partition number */
/*     and one character for the slash. */


/*     Maximum number of coefficient records: */


/*     Maximum number of fields in an SCLK string: */


/*     Length of strings used to represent D.P. */
/*     numbers: */


/*     Maximum number of supported parallel time systems: */


/*     End of include file sclk.inc */

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
/*     SC         I   NAIF spacecraft identification code. */
/*     NPARTS     O   The number of spacecraft clock partitions. */
/*     PSTART     O   Array of partition start times. */
/*     PSTOP      O   Array of partition stop times. */
/*     MXPART     P   Maximum number of partitions. */

/* $ Detailed_Input */

/*     SC         is the NAIF ID for the spacecraft whose clock partition */
/*                information is being requested. */

/* $ Detailed_Output */

/*     NPARTS     is the number of spacecraft clock time partitions */
/*                described in the kernel file for spacecraft SC. */

/*     PSTART     is an array containing NPARTS partition start times */
/*                represented as double precision, encoded SCLK */
/*                ("ticks"). The values contained in PSTART are whole */
/*                numbers. */

/*     PSTOP      is an array containing NPARTS partition end times */
/*                represented as double precision, encoded SCLK */
/*                ("ticks"). The values contained in PSTOP are whole */
/*                numbers. */

/* $ Parameters */

/*     MXPART     is the maximum number of partitions for any spacecraft */
/*                clock. SCLK kernels contain start and stop times for */
/*                each partition. See the INCLUDE file sclk.inc for this */
/*                parameter's value. */

/* $ Exceptions */

/*     1)  If the kernel variables containing the spacecraft clock */
/*         partition start and stop times have not been loaded in the */
/*         kernel pool, the error will be diagnosed by routines called */
/*         by this routine. */

/*     2)  If the number of start and stop times are different then */
/*         the error SPICE(NUMPARTSUNEQUAL) is signaled. */

/* $ Files */

/*     An SCLK kernel containing spacecraft clock partition start */
/*     and stop times for the spacecraft clock indicated by SC must */
/*     be loaded into the kernel pool. */

/* $ Particulars */

/*     SCPART looks for two variables in the kernel pool for each */
/*     spacecraft's partition information. If SC = -nn, then the names of */
/*     the variables are */

/*         'SCLK_PARTITION_START_nn' and */
/*         'SCLK_PARTITION_END_nn'. */

/*     The start and stop times returned are in units of "ticks". */

/* $ Examples */

/*     1)  The following program fragment finds and prints out partition */
/*         start and stop times in clock format for the Galileo mission. */
/*         In this example, Galileo partition times are assumed to be */
/*         in the kernel file SCLK.KER. */

/*            CHARACTER*(30)        START */
/*            CHARACTER*(30)        STOP */

/*            CALL FURNSH ( 'SCLK.KER' ) */

/*            SC = -77 */

/*            CALL SCPART ( SC, NPARTS, PSTART, PSTOP ) */

/*            DO I = 1, NPARTS */

/*               CALL SCFMT ( SC, PSTART( I ), START ) */
/*               CALL SCFMT ( SC, PSTOP ( I ), STOP  ) */

/*               WRITE (*,*) */
/*               WRITE (*,*) 'Partition ', I, ':' */
/*               WRITE (*,*) 'Start = ', START */
/*               WRITE (*,*) 'Stop  = ', STOP */

/*            END DO */

/* $ Restrictions */

/*     1) This routine assumes that an SCLK kernel appropriate to the */
/*        spacecraft identified by SC has been loaded into the kernel */
/*        pool. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     J.M. Lynch     (JPL) */
/*     B.V. Semenov   (JPL) */
/*     R.E. Thurman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.3.1, 19-MAR-2014 (NJB) */

/*        Minor header comment updates were made. */

/* -    SPICELIB Version 2.3.0, 09-SEP-2013 (BVS) */

/*        Updated to keep track of the POOL counter and call ZZCVPOOL. */

/* -    SPICELIB Version 2.2.0, 05-MAR-2009 (NJB) */

/*        Bug fix: this routine now keeps track of whether its */
/*        kernel pool look-up succeeded. If not, a kernel pool */
/*        lookup is attempted on the next call to this routine. */

/* -    SPICELIB Version 2.1.0, 05-FEB-2008 (NJB) */

/*        The values of the parameter MXPART is now */
/*        provided by the INCLUDE file sclk.inc. */

/* -    SPICELIB Version 1.1.1, 22-AUG-2006 (EDW) */

/*        Replaced references to LDPOOL with references */
/*        to FURNSH. */

/* -    SPICELIB Version 1.1.0, 22-MAR-1993 (JML) */

/*        The routine now uses the kernel pool watch capability. */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 03-SEP-1990 (NJB) (JML) (RET) */

/* -& */
/* $ Index_Entries */

/*     spacecraft_clock partition information */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     Saved variables */


/*     Initial values */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "SCPART", (ftnlen)6);

/*     On the first pass through the subroutine, or if the */
/*     spacecraft code changes, set watches on the SCLK kernel */
/*     variables for the current clock. */

    if (__state->first || *sc != __state->oldsc) {

/*        Make up a list of names of kernel variables that we'll use. */

	s_copy(&__global_state->f2c, kvname, "SCLK_PARTITION_START", (ftnlen)
		60, (ftnlen)20);
	s_copy(&__global_state->f2c, kvname + 60, "SCLK_PARTITION_END", (
		ftnlen)60, (ftnlen)18);
	for (i__ = 1; i__ <= 2; ++i__) {
	    suffix_(__global_state, "_#", &__state->c__0, kvname + ((i__1 = 
		    i__ - 1) < 2 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "kvname", i__1, "scpart_", (ftnlen)
		    284)) * 60, (ftnlen)2, (ftnlen)60);
	    i__3 = -(*sc);
	    repmi_(__global_state, kvname + ((i__1 = i__ - 1) < 2 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "kvname", i__1,
		     "scpart_", (ftnlen)285)) * 60, "#", &i__3, kvname + ((
		    i__2 = i__ - 1) < 2 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "kvname", i__2, "scpart_", (ftnlen)
		    285)) * 60, (ftnlen)60, (ftnlen)1, (ftnlen)60);
	}

/*        Set a watch on all of the kernel variables used. */

	swpool_(__global_state, "SCPART", &__state->c__2, kvname, (ftnlen)6, (
		ftnlen)60);

/*        Keep track of the last spacecraft ID encountered. */

	__state->oldsc = *sc;

/*        Initialize the local POOL counter to user value. */

	zzctruin_(__global_state, __state->usrctr);
	__state->first = FALSE_;
    }

/*     If any of the kernel pool variables that this routine uses */
/*     have been updated, or if the spacecraft ID changes, look up */
/*     the new values from the kernel pool. */

    zzcvpool_(__global_state, "SCPART", __state->usrctr, &update, (ftnlen)6);
    if (update || __state->nodata) {

/*        Read the values from the kernel pool. */

	scld01_(__global_state, "SCLK_PARTITION_START", sc, &__state->c__9999,
		 &nprtsa, __state->prtsa, (ftnlen)20);
	scld01_(__global_state, "SCLK_PARTITION_END", sc, &__state->c__9999, &
		nprtso, __state->prtso, (ftnlen)18);
	if (failed_(__global_state)) {
	    __state->nodata = TRUE_;
	    chkout_(__global_state, "SCPART", (ftnlen)6);
	    return 0;
	}

/*        Error checking. */

	if (nprtsa != nprtso) {
	    __state->nodata = TRUE_;
	    setmsg_(__global_state, "The number of partition start and stop "
		    "times are unequal for spacecraft #.    ", (ftnlen)78);
	    errint_(__global_state, "#", sc, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(NUMPARTSUNEQUAL)", (ftnlen)22);
	    chkout_(__global_state, "SCPART", (ftnlen)6);
	    return 0;
	}

/*        At this point we have the data we sought. We need not */
/*        perform another kernel pool look-up unless there's */
/*        a kernel pool update or change in the SCLK ID. */

	__state->nodata = FALSE_;

/*        Buffer the number of partitions and the partition start */
/*        and stop times. */

	__state->lstprt = nprtsa;

/*        The partition start and stop times must be whole numbers. */

	i__1 = __state->lstprt;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    __state->prtsa[(i__2 = i__ - 1) < 9999 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "prtsa", i__2, "scpart_", (
		    ftnlen)360)] = d_nint(&__global_state->f2c, &
		    __state->prtsa[(i__3 = i__ - 1) < 9999 && 0 <= i__3 ? 
		    i__3 : s_rnge(&__global_state->f2c, "prtsa", i__3, "scpa"
		    "rt_", (ftnlen)360)]);
	    __state->prtso[(i__2 = i__ - 1) < 9999 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "prtso", i__2, "scpart_", (
		    ftnlen)361)] = d_nint(&__global_state->f2c, &
		    __state->prtso[(i__3 = i__ - 1) < 9999 && 0 <= i__3 ? 
		    i__3 : s_rnge(&__global_state->f2c, "prtso", i__3, "scpa"
		    "rt_", (ftnlen)361)]);
	}
    }

/*     Copy the values in local buffers to the output arguments. */

    *nparts = __state->lstprt;
    i__1 = *nparts;
    for (i__ = 1; i__ <= i__1; ++i__) {
	pstart[i__ - 1] = __state->prtsa[(i__2 = i__ - 1) < 9999 && 0 <= i__2 
		? i__2 : s_rnge(&__global_state->f2c, "prtsa", i__2, "scpart_"
		, (ftnlen)372)];
	pstop[i__ - 1] = __state->prtso[(i__2 = i__ - 1) < 9999 && 0 <= i__2 ?
		 i__2 : s_rnge(&__global_state->f2c, "prtso", i__2, "scpart_",
		 (ftnlen)373)];
    }
    chkout_(__global_state, "SCPART", (ftnlen)6);
    return 0;
} /* scpart_ */

