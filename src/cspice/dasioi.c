/* dasioi.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern dasioi_init_t __dasioi_init;
static inline dasioi_state_t* get_dasioi_state(cspice_t* state) {
	if (!state->dasioi)
		state->dasioi = __cspice_allocate_module(sizeof(
	dasioi_state_t), &__dasioi_init, sizeof(__dasioi_init));
	return state->dasioi;

}

/* $Procedure      DASIOI ( DAS, Fortran I/O, integer ) */
/* Subroutine */ int dasioi_(cspice_t* __global_state, char *action, integer *
	unit, integer *recno, integer *record, ftnlen action_len)
{
    /* Builtin functions */
    integer s_rdue(f2c_state_t*, cilist *), do_uio(f2c_state_t*, integer *, 
	    char *, ftnlen), e_rdue(f2c_state_t*), s_wdue(f2c_state_t*, 
	    cilist *), e_wdue(f2c_state_t*);

    /* Local variables */
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern logical eqstr_(cspice_t*, char *, char *, ftnlen, ftnlen);
    extern /* Subroutine */ int errfnm_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    integer iostat;
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);

    /* Fortran I/O blocks */



    /* Module state */
    dasioi_state_t* __state = get_dasioi_state(__global_state);
/* $ Abstract */

/*     Perform Fortran reads and writes of DAS integer records. */
/*     This routine operates on DAS files having native binary */
/*     format. */

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
/*     UTILITY */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ACTION     I   Action to take (read or write). */
/*     UNIT       I   Fortran unit connected to DAS file. */
/*     RECNO      I   Number of record to read or write. */
/*     RECORD    I-O  DAS integer record. */

/* $ Detailed_Input */

/*     ACTION         is a character string specifying whether to read */
/*                    from or write to the specified DAS file.  Possible */
/*                    values are: */

/*                       'READ' */
/*                       'WRITE' */

/*                    Case and leading or trailing blanks are not */
/*                    significant. */


/*     UNIT           is the Fortran unit number connected to the DAS */
/*                    file that is to be read or written.  Given the */
/*                    handle of the DAS file, the unit number can be */
/*                    obtained using ZZDDHHLU. */

/*     RECNO          is the Fortran record number of the record to be */
/*                    read or written. */

/*     RECORD         is an integer array whose contents are to be */
/*                    written to record RECNO, if ACTION is WRITE. */

/* $ Detailed_Output */

/*     RECORD         is an integer array whose contents are to be */
/*                    set equal to those of record RECNO, if ACTION */
/*                    is READ. */

/* $ Parameters */

/*     NWI            is the number of elements in a DAS integer record. */

/* $ Exceptions */

/*     1)  If the value of ACTION is not recognized, the error */
/*         SPICE(UNRECOGNIZEDACTION) is signaled. */

/*     2)  If a Fortran read error occurs, the error */
/*         SPICE(DASFILEREADFAILED) is signaled. */

/*     3)  If a Fortran write error occurs, the error */
/*         SPICE(DASFILEWRITEFAILED) is signaled. */

/* $ Files */

/*     See the description of the argument UNIT in $Detailed_Input. */

/* $ Particulars */

/*     This routine may be used to write to and read from DAS files */
/*     having the native binary file format of the host system. The */
/*     routine ZZDASGDI should be used to read integer records from DAS */
/*     files that may have either native or non-native format. */

/*     Normally, routines outside of SPICELIB will not need to call this */
/*     routine directly. Writes to DAS files should be performed using */
/*     the DASADx and DASUDx routines; reads should be performed using */
/*     the DASRDx routines. */

/*     This routine centralizes I/O and the concomitant error handling */
/*     for DAS integer records. */

/*     Although most DAS routines use file handles to identify DAS */
/*     files, this routine uses Fortran logical units for this purpose. */
/*     Using unit numbers allows the DASIOx routines to be called from */
/*     any DAS routine, including entry points of DASFM. */

/* $ Examples */

/*     1)  Read and print to the screen integer records number 10 */
/*         through 20 from the DAS file designated by HANDLE. */

/*            INTEGER               RECORD ( NWI ) */
/*                           . */
/*                           . */
/*                           . */

/*            CALL ZZDDHHLU ( HANDLE, 'DAS', .FALSE., UNIT ) */
/*            CALL DASHFN   ( HANDLE, NAME ) */

/*            DO I = 1, 20 */

/*               CALL DASIOI ( 'READ', UNIT, 10, RECORD ) */

/*               LABEL = 'Contents of the # record in DAS file #: ' */

/*               CALL REPMOT ( LABEL,  '#',  I,  'L',   LABEL ) */
/*               CALL REPMC  ( LABEL,  '#',      NAME,  LABEL ) */

/*               WRITE (*,*) LABEL */
/*               WRITE (*,*) ' ' */
/*               WRITE (*,*) RECORD */

/*            END DO */



/*     2)  Write the contents of the array RECORD to record number */
/*         10 in the DAS file designated by HANDLE. */


/*            INTEGER               RECORD ( NWI ) */

/*                           . */
/*                           . */
/*                           . */

/*            CALL ZZDDHHLU ( HANDLE,  'DAS', .FALSE., UNIT   ) */
/*            CALL DASIOI   ( 'WRITE', UNIT,  10,      RECORD ) */


/* $ Restrictions */

/*     1) This routine may be used only on DAS files having */
/*        the native binary file format of the host system. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     W.L. Taber     (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.1, 05-FEB-2015 (NJB) */

/*        Header was updated to refer to ZZDDHHLU. Restrictions section */
/*        was updated. */

/* -    SPICELIB Version 1.0.0, 30-JUN-1992 (NJB) (WLT) */

/* -& */
/* $ Index_Entries */

/*     perform Fortran reads of integer records */
/*     perform Fortran writes of integer records */
/*     perform low-level I/O for DAS routines */
/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Use discovery check-in. */

    if (return_(__global_state)) {
	return 0;
    }
    if (eqstr_(__global_state, action, "READ", action_len, (ftnlen)4)) {

/*        We're supposed to read the file. */

	__state->io___2.ciunit = *unit;
	__state->io___2.cirec = *recno;
	iostat = s_rdue(&__global_state->f2c, &__state->io___2);
	if (iostat != 0) {
	    goto L100001;
	}
	iostat = do_uio(&__global_state->f2c, &__state->c__256, (char *)&
		record[0], (ftnlen)sizeof(integer));
	if (iostat != 0) {
	    goto L100001;
	}
	iostat = e_rdue(&__global_state->f2c);
L100001:
	if (iostat != 0) {
	    chkin_(__global_state, "DASIOI", (ftnlen)6);
	    setmsg_(__global_state, "Could not read DAS integer record. File"
		    " = # Record number = #. IOSTAT = #.", (ftnlen)74);
	    errfnm_(__global_state, "#", unit, (ftnlen)1);
	    errint_(__global_state, "#", recno, (ftnlen)1);
	    errint_(__global_state, "#", &iostat, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(DASFILEREADFAILED)", (ftnlen)24);
	    chkout_(__global_state, "DASIOI", (ftnlen)6);
	    return 0;
	}
    } else if (eqstr_(__global_state, action, "WRITE", action_len, (ftnlen)5))
	     {

/*        We're supposed to write to the file. */

	__state->io___3.ciunit = *unit;
	__state->io___3.cirec = *recno;
	iostat = s_wdue(&__global_state->f2c, &__state->io___3);
	if (iostat != 0) {
	    goto L100002;
	}
	iostat = do_uio(&__global_state->f2c, &__state->c__256, (char *)&
		record[0], (ftnlen)sizeof(integer));
	if (iostat != 0) {
	    goto L100002;
	}
	iostat = e_wdue(&__global_state->f2c);
L100002:
	if (iostat != 0) {
	    chkin_(__global_state, "DASIOI", (ftnlen)6);
	    setmsg_(__global_state, "Could not write DAS integer record. Fil"
		    "e = # Record number = #. IOSTAT = #.", (ftnlen)75);
	    errfnm_(__global_state, "#", unit, (ftnlen)1);
	    errint_(__global_state, "#", recno, (ftnlen)1);
	    errint_(__global_state, "#", &iostat, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(DASFILEWRITEFAILED)", (ftnlen)25);
	    chkout_(__global_state, "DASIOI", (ftnlen)6);
	    return 0;
	}
    } else {

/*        The requested action is a little too weird. */

	chkin_(__global_state, "DASIOI", (ftnlen)6);
	setmsg_(__global_state, "Action was #; should be READ or WRITE", (
		ftnlen)37);
	errch_(__global_state, "#", action, (ftnlen)1, action_len);
	sigerr_(__global_state, "SPICE(UNRECOGNIZEDACTION)", (ftnlen)25);
	chkout_(__global_state, "DASIOI", (ftnlen)6);
	return 0;
    }
    return 0;
} /* dasioi_ */

