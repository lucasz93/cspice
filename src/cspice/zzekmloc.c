/* zzekmloc.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzekmloc_init_t __zzekmloc_init;
static zzekmloc_state_t* get_zzekmloc_state(cspice_t* state) {
	if (!state->zzekmloc)
		state->zzekmloc = __cspice_allocate_module(sizeof(
	zzekmloc_state_t), &__zzekmloc_init, sizeof(__zzekmloc_init));
	return state->zzekmloc;

}

/* $Procedure      ZZEKMLOC ( EK, return integer metadata location ) */
/* Subroutine */ int zzekmloc_(cspice_t* __global_state, integer *handle, 
	integer *segno, integer *page, integer *base)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    integer nseg;
    integer tree;
    extern /* Subroutine */ int zzektrdp_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    extern integer zzektrbs_(cspice_t*, integer *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer tbase;
    extern /* Subroutine */ int dasrdi_(cspice_t*, integer *, integer *, 
	    integer *, integer *);
    extern integer eknseg_(cspice_t*, integer *);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);


    /* Module state */
    zzekmloc_state_t* __state = get_zzekmloc_state(__global_state);
/* $ Abstract */

/*     Return the integer metadata location of a specified segment.  The */
/*     number and DAS integer base address of the first integer */
/*     page of the metadata are returned. */

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

/*     EK */
/*     PRIVATE */

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


/*     Include Section:  EK File Metadata Parameters */

/*        ekfilpar.inc  Version 1  28-MAR-1995 (NJB) */

/*     These parameters apply to EK files using architecture 4. */
/*     These files use a paged DAS file as their underlying file */
/*     structure. */

/*     The metadata for an architecture 4 EK file is very simple:  it */
/*     consists of a single integer, which is a pointer to a tree */
/*     that in turn points to the segments in the EK.  However, in the */
/*     interest of upward compatibility, one integer page is reserved */
/*     for the file's metadata. */


/*     Size of file parameter block: */


/*     All offsets shown below are relative to the beginning of the */
/*     first integer page in the EK. */


/*     Index of the segment pointer tree---this location contains the */
/*     root page number of the tree: */


/*     End Include Section:  EK File Metadata Parameters */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   File handle. */
/*     SEGNO      I   Segment number. */
/*     PAGE       O   Integer metadata start page number. */
/*     BASE       O   Page base. */

/* $ Detailed_Input */

/*     HANDLE         is an EK file handle.  The EK may be open for read */
/*                    or write access. */

/*     SEGNO          is the number of the segment whose integer metadata */
/*                    location is sought. */

/* $ Detailed_Output */

/*    PAGE            is the number of the first page containing integer */
/*                    metadata for the specified segment.  The segment */
/*                    descriptor starts at the first address of this */
/*                    page. */

/*    BASE            is the DAS integer base address of the page */
/*                    whose number is given by PAGE.  BASE is the */
/*                    predecessor of the first DAS integer word */
/*                    belonging to this page. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If HANDLE is invalid, the error will be diagnosed by routines */
/*         called by this routine. */

/*     2)  If SEGNO is out of range, the error SPICE(INVALIDINDEX) */
/*         will be signalled. */

/*     3)  If an I/O error occurs while reading or writing the indicated */
/*         file, the error will be diagnosed by routines called by this */
/*         routine. */

/* $ Files */

/*     See the EK Required Reading for a discussion of the EK file */
/*     format. */

/* $ Particulars */

/*     This routine operates by side effects:  it deletes a record */
/*     from an EK segment.  Deleting a record implies: */

/*        1) All column entries in the record are deleted. */

/*        2) Link counts are decremented for data pages containing */
/*           column entries in the record to be deleted.  Pages whose */
/*           link counts drop to zero are freed. */

/*        3) All column indexes are updated for the parent segment. */

/*        4) The link count is decremented for the page containing the */
/*           record pointer structure of the record to be deleted.  If */
/*           the link count drops to zero, the page is freed. */

/*        5) The pointer to the deleted record is deleted from the */
/*           record tree for the parent segment. */

/*        6) The segment's metadata is updated to reflect the new */
/*           record count. */

/* $ Examples */

/*     See EKINSR. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 18-JUN-1999 (WLT) */

/*        Added the required discovery CHKIN. */

/* -    Beta Version 1.0.0, 19-OCT-1995 (NJB) */

/* -& */

/*     SPICELIB functions */


/*     Non-SPICELIB functions */


/*     Local variables */


/*     Use discovery check-in. */


/*     Validate the segment number to start out. */


/*     Get the segment count; valididate SEGNO. */

    nseg = eknseg_(__global_state, handle);

/*     Check out SEGNO. */

    if (*segno < 1 || *segno > nseg) {
	chkin_(__global_state, "ZZEKMLOC", (ftnlen)8);
	setmsg_(__global_state, "Segment number = #; valid range is 1:#.", (
		ftnlen)39);
	errint_(__global_state, "#", segno, (ftnlen)1);
	errint_(__global_state, "#", &nseg, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INVALIDINDEX )", (ftnlen)20);
	chkout_(__global_state, "ZZEKMLOC", (ftnlen)8);
	return 0;
    }

/*     Find the segment in the segment tree. */
/*     Obtain the base address of the first integer page. */

    tbase = zzektrbs_(__global_state, &__state->c__1);

/*     Look up the head node of the segment tree. */

    i__1 = tbase + 1;
    i__2 = tbase + 1;
    dasrdi_(__global_state, handle, &i__1, &i__2, &tree);

/*     Get the segment pointer for the segment having index SEGNO. */
/*     This pointer is actually the page number we're looking for. */

    zzektrdp_(__global_state, handle, &tree, segno, page);

/*     Return the base address of the metadata page as well. */

    *base = zzektrbs_(__global_state, page);
    return 0;
} /* zzekmloc_ */

