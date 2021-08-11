/* stcc01.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern stcc01_init_t __stcc01_init;
static stcc01_state_t* get_stcc01_state() {
	cspice_t* state =  __cspice_get_state();
	if (!state->stcc01)
		state->stcc01 = __cspice_allocate_module(sizeof(
	stcc01_state_t), &__stcc01_init, sizeof(__stcc01_init));
	return state->stcc01;

}

/* $Procedure   STCC01 ( STAR catalog type 1, check whether type 1 ) */
/* Subroutine */ int stcc01_(char *catfnm, char *tabnam, logical *istyp1, 
	char *errmsg, ftnlen catfnm_len, ftnlen tabnam_len, ftnlen errmsg_len)
{
    /* Initialized data */


    /* System generated locals */
    address a__1[4];
    integer i__1, i__2, i__3, i__4[4];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_rnge(char *, integer, 
	    char *, integer);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    extern integer nblen_(char *, ftnlen);
    extern /* Subroutine */ int ekcls_(integer *);
    extern /* Subroutine */ int ekopr_(char *, integer *, ftnlen);
    extern integer isrchc_(char *, integer *, char *, ftnlen, ftnlen);
    extern integer eknseg_(integer *);
    extern /* Subroutine */ int chkout_(char *, ftnlen);
    extern /* Subroutine */ int ekssum_(integer *, integer *, char *, integer 
	    *, integer *, char *, char *, integer *, integer *, logical *, 
	    logical *, ftnlen, ftnlen, ftnlen);
    extern logical return_(void);

    /* Module state */
    stcc01_state_t* __state = get_stcc01_state();
/* $ Abstract */

/*     Check whether a file is a type 1 star catalog and return the */
/*     catalog's table name if it is. */

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

/*     EK */

/* $ Keywords */

/*     None. */

/* $ Declarations */
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


/*     Include Section:  EK Column Name Size */

/*        ekcnamsz.inc Version 1    17-JAN-1995 (NJB) */


/*     Size of column name, in characters. */


/*     End Include Section:  EK Column Name Size */

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


/*     Include Section:  EK Table Name Size */

/*        ektnamsz.inc Version 1    17-JAN-1995 (NJB) */


/*     Size of table name, in characters. */


/*     End Include Section:  EK Table Name Size */

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


/*     Include Section:  EK General Limit Parameters */

/*        ekglimit.inc  Version 1    21-MAY-1995 (NJB) */


/*     This file contains general limits for the EK system. */

/*     MXCLSG is the maximum number of columns allowed in a segment. */
/*     This limit applies to logical tables as well, since all segments */
/*     in a logical table must have the same column definitions. */


/*     End Include Section:  EK General Limit Parameters */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     CATFNM      I   Catalog file name. */
/*     TABNAM      O   Catalog table name. */
/*     ISTYP1      O   True when file is type 1 star catalog. */
/*     ERRMSG      O   Error message. */

/* $ Detailed_Input */

/*     CATFNM      is the name of the catalog file. */

/* $ Detailed_Output */

/*     TABNAM      is the name of the data table contained in the */
/*                 catalog. Set to blank if file is not a type 1 star */
/*                 catalog. */

/*     ISTYP1      is TRUE when the file is a type 1 star catalog. FALSE */
/*                 otherwise. */

/*     ERRMSG      is a diagnostic message indicating why the file is */
/*                 not a type 1 star catalog. Set to blank if the file */
/*                 is a type 1 star catalog. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the indicated file cannot be opened, the error will be */
/*         diagnosed by routines called by this routine. */

/*     2)  If the indicated file has the wrong architecture version, the */
/*         error will be diagnosed by routines called by this routine. */

/*     3)  If an I/O error occurs while reading the indicated file, the */
/*         error will be diagnosed by routines called by this routine. */

/* $ Files */

/*     This routine checks whether file is really SPICE type 1 star */
/*     catalog file. */

/*     SPICE type 1 star catalog files MUST contain a single data table. */
/*     It can occupy a single segment or it can spread across multiple */
/*     segments. This table MUST include the following columns: */

/*        column name                data type          units */
/*     ------------------------------------------------------- */
/*        RA                   DOUBLE PRECISION        DEGREES */
/*        DEC                  DOUBLE PRECISION        DEGREES */
/*        RA_SIGMA             DOUBLE PRECISION        DEGREES */
/*        DEC_SIGMA            DOUBLE PRECISION        DEGREES */
/*        CATALOG_NUMBER       INTEGER */
/*        SPECTRAL_TYPE        CHARACTER*(4) */
/*        VISUAL_MAGNITUDE     DOUBLE PRECISION */

/*     Nulls are not allowed in any of the columns. */
/*     Other columns can also be present in the table but their data */
/*     will NOT be accessible through type 1 star catalog access */
/*     routines. Note that the names and attributes of these additional */
/*     columns must be identical for all segments containing this table. */

/* $ Particulars */

/*     This routine does not need to be called by the user's program. */
/*     It is used by star catalog loader routines to check */
/*     whether a particular file is a type 1 star catalog before loading */
/*     the file. */

/* $ Examples */

/*     In the following code fragment, STCC01 is used to determine */
/*     whether a file is a SPICE type 1 star catalog. */

/*     C */
/*     C     Call STCC01 to determine whether the file is type 1 star */
/*     C     catalog file. */
/*     C */
/*           CALL STCC01 ( CATFNM, TABNAM, ISTYP1, ERRMSG ) */

/*     C */
/*     C     Check ISTYP1 flag and stop execution and report an */
/*     C     error if file is not type 1 star catalog file. */
/*     C */
/*           IF ( .NOT. ISTYP1 ) THEN */
/*          .   WRITE (*,*) 'The file:' */
/*          .   WRITE (*,*) '  ',CATFNM(1:RTRIM(CATFNM)) */
/*          .   WRITE (*,*) 'is not a type 1 star catalog.' */
/*          .   WRITE (*,*) ERRMSG */
/*              STOP */
/*           END IF */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     B.V. Semenov    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 15-MAY-1996 (BVS) */

/* -& */
/* $ Index_Entries */

/*     check whether a file is a type 1 star catalog */

/* -& */


/*     SPICELIB functions */


/*     Local parameters. */


/*     Local variables */


/*     Initial values. */


/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    } else {
	chkin_("STCC01", (ftnlen)6);
    }

/*     More initial values. */

    s_copy(tabnam, " ", tabnam_len, (ftnlen)1);
    s_copy(errmsg, " ", errmsg_len, (ftnlen)1);
    *istyp1 = TRUE_;

/*     Open star catalog file with low level "open for read access" */
/*     EK routine. */

    ekopr_(catfnm, &__state->tmphnd, catfnm_len);

/*     Get the number of segments in the file and check whether it is */
/*     greater than 0 (i.e. some data are is present in the file). If */
/*     not then set an error message and return to the calling routine. */

    __state->numseg = eknseg_(&__state->tmphnd);
    if (__state->numseg <= 0) {
	s_copy(errmsg, "File contains no data.", errmsg_len, (ftnlen)22);
	*istyp1 = FALSE_;
	chkout_("STCC01", (ftnlen)6);
	return 0;
    }

/*     Loop through the segments to find out whether all of them */
/*     contain pieces of the same table. If not then set */
/*     an error message and return to the calling routine. */

    i__1 = __state->numseg;
    for (__state->i__ = 1; __state->i__ <= i__1; ++__state->i__) {
	ekssum_(&__state->tmphnd, &__state->i__, __state->tmptnm, &
		__state->nrows, &__state->ncols, __state->cnames, 
		__state->dtypes, __state->sizes, __state->strlns, 
		__state->indexd, __state->nullok, (ftnlen)64, (ftnlen)32, (
		ftnlen)4);
	if (__state->i__ > 1) {
	    if (s_cmp(__state->tmptnm, __state->tnmprv, (ftnlen)64, (ftnlen)
		    64) != 0) {
		s_copy(errmsg, "File contains more than one data table.", 
			errmsg_len, (ftnlen)39);
		*istyp1 = FALSE_;
		chkout_("STCC01", (ftnlen)6);
		return 0;
	    }
	}
	s_copy(__state->tnmprv, __state->tmptnm, (ftnlen)64, (ftnlen)64);
    }

/*     Check whether the  number of columns is less than it */
/*     is supposed to be in type 1 star catalogs. If so then set */
/*     an error message and return to a calling routine. */

    if (__state->ncols < 7) {
	s_copy(errmsg, "File contains too few data columns.", errmsg_len, (
		ftnlen)35);
	*istyp1 = FALSE_;
	chkout_("STCC01", (ftnlen)6);
	return 0;
    }

/*     Check whether all columns that will be used in catalog search and */
/*     star data fetching are present in the data table. If not */
/*     then set an error message and return to a calling routine. */

    for (__state->i__ = 1; __state->i__ <= 7; ++__state->i__) {
	__state->found = FALSE_;
	__state->j = isrchc_(__state->cat1nm + (((i__1 = __state->i__ - 1) < 
		7 && 0 <= i__1 ? i__1 : s_rnge("cat1nm", i__1, "stcc01_", (
		ftnlen)319)) << 5), &__state->ncols, __state->cnames, (ftnlen)
		32, (ftnlen)32);
	if (__state->j > 0) {
	    __state->found = s_cmp(__state->cat1dt + (((i__1 = __state->i__ - 
		    1) < 7 && 0 <= i__1 ? i__1 : s_rnge("cat1dt", i__1, "stc"
		    "c01_", (ftnlen)322)) << 2), __state->dtypes + (((i__2 = 
		    __state->j - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge("dtyp"
		    "es", i__2, "stcc01_", (ftnlen)322)) << 2), (ftnlen)4, (
		    ftnlen)4) == 0 && ! __state->nullok[(i__3 = __state->j - 
		    1) < 100 && 0 <= i__3 ? i__3 : s_rnge("nullok", i__3, 
		    "stcc01_", (ftnlen)322)];
	}
	if (! __state->found) {
/* Writing concatenation */
	    i__4[0] = 8, a__1[0] = " Column ";
	    i__4[1] = nblen_(__state->cat1nm + (((i__2 = __state->i__ - 1) < 
		    7 && 0 <= i__2 ? i__2 : s_rnge("cat1nm", i__2, "stcc01_", 
		    (ftnlen)326)) << 5), (ftnlen)32), a__1[1] = 
		    __state->cat1nm + (((i__1 = __state->i__ - 1) < 7 && 0 <= 
		    i__1 ? i__1 : s_rnge("cat1nm", i__1, "stcc01_", (ftnlen)
		    326)) << 5);
	    i__4[2] = 16, a__1[2] = " is not found or";
	    i__4[3] = 33, a__1[3] = " improperly declared in the file.";
	    s_cat(errmsg, a__1, i__4, &__state->c__4, errmsg_len);
	    *istyp1 = FALSE_;
	    chkout_("STCC01", (ftnlen)6);
	    return 0;
	}
    }

/*     If we got to this point then all checks were passed successfully */
/*     and the file can be processed as a type 1 star catalog. We */
/*     "return" the table name and close the file with the EK close */
/*     routine. */

    s_copy(tabnam, __state->tmptnm, tabnam_len, (ftnlen)64);
    ekcls_(&__state->tmphnd);
    chkout_("STCC01", (ftnlen)6);
    return 0;
} /* stcc01_ */

