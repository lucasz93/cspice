/* stcl01.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern stcl01_init_t __stcl01_init;
static stcl01_state_t* get_stcl01_state(cspice_t* state) {
	if (!state->stcl01)
		state->stcl01 = __cspice_allocate_module(sizeof(
	stcl01_state_t), &__stcl01_init, sizeof(__stcl01_init));
	return state->stcl01;

}

/* $Procedure   STCL01 ( STAR catalog type 1, load catalog file ) */
/* Subroutine */ int stcl01_(cspice_t* __global_state, char *catfnm, char *
	tabnam, integer *handle, ftnlen catfnm_len, ftnlen tabnam_len)
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2];
    char ch__1[295];

    /* Builtin functions */
    /* Subroutine */ int s_cat(f2c_state_t*, char *, char **, integer *, 
	    integer *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int eklef_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int stcc01_(cspice_t*, char *, char *, logical *, 
	    char *, ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    logical istyp1;
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    char errmsg[256];
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    stcl01_state_t* __state = get_stcl01_state(__global_state);
/* $ Abstract */

/*     Load SPICE type 1 star catalog and return the catalog's */
/*     table name. */

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
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     CATFNM      I   Catalog file name. */
/*     TABNAM      O   Catalog table name. */
/*     HANDLE      O   Catalog file handle. */

/* $ Detailed_Input */

/*     CATFNM      is the name of the catalog file. */

/* $ Detailed_Output */

/*     TABNAM      is the name of the table loaded from the catalog */
/*                 file. This name must be provided as an input argument */
/*                 to STCF01 catalog search routine. Multiple catalogs */
/*                 contaning the table TABNAM may be loaded. Sets of */
/*                 columns, column names and attribites must be */
/*                 identical through all these files. */

/*     HANDLE      is the integer handle of the catalog file. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the indicated file cannot be opened, the error will be */
/*         diagnosed by routines called by this routine. */

/*     2)  If the indicated file has the wrong architecture version, the */
/*         error will be diagnosed by routines called by this routine. */

/*     3)  If an I/O error occurs while reading the indicated file, the */
/*         error will be diagnosed by routines called by this routine. */

/*     4)  If the catalog file is not a type 1 star catalog file */
/*         then the error 'SPICE(BADCATALOGFILE)' is signalled. */

/* $ Files */

/*     This routine loads a SPICE type 1 star catalog file. */

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
/*     will NOT be accessible through STCF01 and STCG01 -- */
/*     the interface used to access data in the catalog. Note */
/*     that the names and attributes of these additional columns */
/*     must be identical for all segments containing this table. */

/* $ Particulars */

/*     This STCL01 routine is intended to be part of the user */
/*     interface to the SPICE type 1 star catalog. It loads a */
/*     SPICE type 1 star catalog file and makes its data available */
/*     for searches and retrieval. */

/*     Other routines in SPICE type 1 star catalog access family are: */

/*        STCF01  search through the catalog for all stars within */
/*                a specified RA-DEC rectangle. */

/*        STCG01  retrieve position and characteristics for */
/*                every single star found. */

/* $ Examples */

/*     In the following code fragment, STCL01 is used to load */
/*     a SPICE type 1 star catalog. */

/*     C */
/*     C     Load catalog file. */
/*     C */
/*           CALL STCL01 ( CATFN, TABNAM, HANDLE ) */
/*     C */
/*     C     Search through the loaded catalog. */
/*     C */
/*           CALL STCF01 ( TABNAM, RAMIN,  RAMAX, */
/*          .              DECMIN, DECMAX, NSTARS ) */
/*     C */
/*     C     Retrieve data for every star that matched the */
/*     C     search criteria. */
/*     C */
/*           DO I = 1, NSTARS */

/*              CALL STCG01 ( I, RA, DEC, RASIG, DECSIG, */
/*          .                 CATNUM, SPTYPE, VMAG ) */

/*           END DO */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     B.V. Semenov    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 18-JUN-1999 (WLT) */

/*        Balanced calls to CHKIN/CHKOUT. */

/* -    SPICELIB Version 1.0.0, 15-MAY-1996 (BVS) */

/* -& */
/* $ Index_Entries */

/*     load a type 1 star catalog file */

/* -& */


/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "STCL01", (ftnlen)6);
    }

/*     Check whether the file is really a type 1 star catalog file. */
/*     If not then signal an error. */

    stcc01_(__global_state, catfnm, tabnam, &istyp1, errmsg, catfnm_len, 
	    tabnam_len, (ftnlen)256);
    if (! istyp1) {
/* Writing concatenation */
	i__1[0] = 39, a__1[0] = "File # is not type 1 star catalog file.";
	i__1[1] = 256, a__1[1] = errmsg;
	s_cat(&__global_state->f2c, ch__1, a__1, i__1, &__state->c__2, (
		ftnlen)295);
	setmsg_(__global_state, ch__1, (ftnlen)295);
	errch_(__global_state, "#", catfnm, (ftnlen)1, catfnm_len);
	sigerr_(__global_state, "SPICE(BADCATALOGFILE)", (ftnlen)21);
	chkout_(__global_state, "STCL01", (ftnlen)6);
	return 0;
    }

/*     Load the catalog file with the high level EK loader. */

    eklef_(__global_state, catfnm, handle, catfnm_len);
    chkout_(__global_state, "STCL01", (ftnlen)6);
    return 0;
} /* stcl01_ */

