/* zzdasgrd.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzdasgrd_init_t __zzdasgrd_init;
static zzdasgrd_state_t* get_zzdasgrd_state(cspice_t* state) {
	if (!state->zzdasgrd)
		state->zzdasgrd = __cspice_allocate_module(sizeof(
	zzdasgrd_state_t), &__zzdasgrd_init, sizeof(__zzdasgrd_init));
	return state->zzdasgrd;

}

/* $Procedure ZZDASGRD ( DAS, get record, double precision ) */
/* Subroutine */ int zzdasgrd_(cspice_t* __global_state, integer *handle, 
	integer *recno, doublereal *record)
{
    /* Initialized data */


    /* Builtin functions */
    integer s_rdue(f2c_state_t*, cilist *), do_uio(f2c_state_t*, integer *, 
	    char *, ftnlen), e_rdue(f2c_state_t*);

    /* Local variables */
    integer unit;
    extern /* Subroutine */ int zzddhnfc_(cspice_t*, integer *);
    extern /* Subroutine */ int zzddhnfo_(cspice_t*, integer *, char *, 
	    integer *, integer *, integer *, logical *, ftnlen);
    extern /* Subroutine */ int zzddhhlu_(cspice_t*, integer *, char *, 
	    logical *, integer *, ftnlen);
    extern /* Subroutine */ int zzxlated_(cspice_t*, integer *, char *, 
	    integer *, doublereal *, ftnlen);
    char fname[255];
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    logical found;
    extern logical failed_(cspice_t*);
    char chrrec[1024];
    integer intamh;
    integer intarc;
    extern /* Subroutine */ int errfnm_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    integer iostat;
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);

    /* Fortran I/O blocks */



    /* Module state */
    zzdasgrd_state_t* __state = get_zzdasgrd_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Read DAS double precision physical records from native */
/*     or non-native DAS files. */

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

/*     DAS */

/* $ Keywords */

/*     DAS */
/*     FILES */

/* $ Declarations */

/*     Include file das.inc */

/*     This include file declares public parameters for the DAS */
/*     subsystem. */

/*        Version 1.0.0 10-FEB-2017 (NJB) */

/*     Parameter declarations follow. */


/*     DAS file table size: */

/*        The parameter name is FTSIZE. The value of the parameter is */
/*        defined in the include file */

/*           zzddhman.inc */

/*        That value is duplicated here, since zzddhman.inc contains */
/*        other declarations that conflict with some of those in DAS */
/*        routines. */


/*     Capacity of DAS data records: */

/*        -- NWD double precision numbers. */
/*        -- NWI integers. */
/*        -- NWC characters. */
/*     These parameters are named to enhance ease of maintenance of */
/*     the code; the values should not be changed. */

/*     End of include file das.inc */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle of DAS file. */
/*     RECNO      I   Record number. */
/*     RECORD     O   Double precision data read from record. */
/*     NWD        P   Number of DP numbers in a single DAS DP record. */

/* $ Detailed_Input */

/*     HANDLE         is the handle of an open DAS file. */

/*     RECNO          is the number of a record in a DAS file. */

/* $ Detailed_Output */

/*     RECORD         is a double precision array containing the */
/*                    elements of the specified record. */

/* $ Parameters */

/*     NWD            is the number of DPs in a single DAS record */
/*                    containing DPs. */

/* $ Exceptions */

/*     1)  If the input file handle cannot be mapped to a file */
/*         name, the error SPICE(HANDLENOTFOUND) will be signaled. The */
/*         output argument RECORD will not be modified. */

/*     2)  If a read operation attempted by this routine fails, the */
/*         error SPICE(DASFILEREADFAILED) will be signaled. */

/*     3)  If an error occurs while attempting to translate non-native */
/*         double precision data to native format, the error will be */
/*         diagnosed by a routine in the call tree of this routine. */

/* $ Files */

/*     See the description of the argument HANDLE in $Detailed_Input. */

/* $ Particulars */

/*     Routines outside of SPICELIB will normally have no need to call */
/*     this routine. */

/*     This routine enables DAS routines to read double precision data */
/*     records from native or non-native DAS files. */

/*     This routine should be used to read only records that contain */
/*     double precision data. */

/* $ Examples */

/*     See usage in DASRRD. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 10-FEB-2017 (NJB) */

/* -& */
/* $ Index_Entries */

/*     read DAS d.p. physical records for arbitrary BFF */
/*     read DAS d.p. records for native or non-native DAS */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     Saved variables */


/*     Initial values */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "ZZDASGRD", (ftnlen)8);
    if (__state->first) {

/*        Get the integer code for the host binary file format. */

	zzddhnfc_(__global_state, &__state->natbff);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "ZZDASGRD", (ftnlen)8);
	    return 0;
	}
	__state->first = FALSE_;
    }

/*     Get a logical unit for this file. */

    zzddhhlu_(__global_state, handle, "DAS", &__state->c_false, &unit, (
	    ftnlen)3);

/*     Get the binary file format of the file designated by HANDLE. */

    zzddhnfo_(__global_state, handle, fname, &intarc, &__state->intbff, &
	    intamh, &found, (ftnlen)255);
    if (failed_(__global_state)) {
	chkout_(__global_state, "ZZDASGRD", (ftnlen)8);
	return 0;
    }
    if (! found) {
	setmsg_(__global_state, "Unable to locate file associated with HANDL"
		"E, #. The most likely cause of this is the file that you are"
		" trying to read has been closed.", (ftnlen)135);
	errint_(__global_state, "#", handle, (ftnlen)1);
	sigerr_(__global_state, "SPICE(HANDLENOTFOUND)", (ftnlen)21);
	chkout_(__global_state, "ZZDASGRD", (ftnlen)8);
	return 0;
    }
    if (__state->intbff == __state->natbff) {

/*        The file has native format. */

	__state->io___10.ciunit = unit;
	__state->io___10.cirec = *recno;
	iostat = s_rdue(&__global_state->f2c, &__state->io___10);
	if (iostat != 0) {
	    goto L100001;
	}
	iostat = do_uio(&__global_state->f2c, &__state->c__128, (char *)&
		record[0], (ftnlen)sizeof(doublereal));
	if (iostat != 0) {
	    goto L100001;
	}
	iostat = e_rdue(&__global_state->f2c);
L100001:
	if (iostat != 0) {
	    setmsg_(__global_state, "Could not read DAS d.p. record. File = "
		    "# Record number = #. IOSTAT = #.", (ftnlen)71);
	    errfnm_(__global_state, "#", &unit, (ftnlen)1);
	    errint_(__global_state, "#", recno, (ftnlen)1);
	    errint_(__global_state, "#", &iostat, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(DASFILEREADFAILED)", (ftnlen)24);
	    chkout_(__global_state, "ZZDASGRD", (ftnlen)8);
	    return 0;
	}
    } else {

/*        Read the record as a character string, then translate it */
/*        to an array of d.p. numbers. */

	__state->io___11.ciunit = unit;
	__state->io___11.cirec = *recno;
	iostat = s_rdue(&__global_state->f2c, &__state->io___11);
	if (iostat != 0) {
	    goto L100002;
	}
	iostat = do_uio(&__global_state->f2c, &__state->c__1, chrrec, (ftnlen)
		1024);
	if (iostat != 0) {
	    goto L100002;
	}
	iostat = e_rdue(&__global_state->f2c);
L100002:
	if (iostat != 0) {
	    setmsg_(__global_state, "Could not read non-native DAS d.p. reco"
		    "rd into character array. File = # Record number = #. IOS"
		    "TAT = #.", (ftnlen)103);
	    errfnm_(__global_state, "#", &unit, (ftnlen)1);
	    errint_(__global_state, "#", recno, (ftnlen)1);
	    errint_(__global_state, "#", &iostat, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(DASFILEREADFAILED)", (ftnlen)24);
	    chkout_(__global_state, "ZZDASGRD", (ftnlen)8);
	    return 0;
	}

/*        Translate the character record to double precision type. */

	zzxlated_(__global_state, &__state->intbff, chrrec, &__state->c__128, 
		record, (ftnlen)1024);

/*        We don't test FAILED here because the routine */
/*        will return from this point. */

    }
    chkout_(__global_state, "ZZDASGRD", (ftnlen)8);
    return 0;
} /* zzdasgrd_ */

