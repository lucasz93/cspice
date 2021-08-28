/* spks10.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern spks10_init_t __spks10_init;
static inline spks10_state_t* get_spks10_state(cspice_t* state) {
	if (!state->spks10)
		state->spks10 = __cspice_allocate_module(sizeof(
	spks10_state_t), &__spks10_init, sizeof(__spks10_init));
	return state->spks10;

}

/* $Procedure      SPKS10 ( S/P Kernel, subset, type 10 ) */
/* Subroutine */ int spks10_(cspice_t* __global_state, integer *srchan, 
	doublereal *srcdsc, integer *dsthan, doublereal *dstdsc, char *dstsid,
	 ftnlen dstsid_len)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    char time[40];
    integer i__;
    extern /* Subroutine */ int etcal_(cspice_t*, doublereal *, char *, 
	    ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int dafus_(cspice_t*, doublereal *, integer *, 
	    integer *, doublereal *, integer *);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    doublereal dtemp[2];
    logical found;
    integer itemp[6];
    doublereal myref;
    extern /* Subroutine */ int sgwes_(cspice_t*, integer *);
    integer dummy;
    extern logical failed_(cspice_t*);
    integer begidx;
    doublereal begtim;
    doublereal packet[14];
    integer endidx;
    integer nepoch;
    doublereal endtim;
    extern /* Subroutine */ int sgfcon_(cspice_t*, integer *, doublereal *, 
	    integer *, integer *, doublereal *);
    extern /* Subroutine */ int sgbwfs_(cspice_t*, integer *, doublereal *, 
	    char *, integer *, doublereal *, integer *, integer *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int sgfrvi_(cspice_t*, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, logical *);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int sgmeta_(cspice_t*, integer *, doublereal *, 
	    integer *, integer *);
    extern /* Subroutine */ int sgfpkt_(cspice_t*, integer *, doublereal *, 
	    integer *, integer *, doublereal *, integer *);
    extern /* Subroutine */ int sgfref_(cspice_t*, integer *, doublereal *, 
	    integer *, integer *, doublereal *);
    doublereal consts[8];
    extern /* Subroutine */ int sgwfpk_(cspice_t*, integer *, integer *, 
	    doublereal *, integer *, doublereal *);
    extern logical return_(cspice_t*);


    /* Module state */
    spks10_state_t* __state = get_spks10_state(__global_state);
/* $ Abstract */

/*     Extract a subset of the data in a type 10 SPK segment into a new */
/*     type 10 segment. */

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

/*     SPK */

/* $ Keywords */

/*     EPHEMERIS */

/* $ Declarations */

/* $ Abstract */

/*     Parameter declarations for the generic segments subroutines. */

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

/*      DAF Required Reading */

/* $ Keywords */

/*       GENERIC SEGMENTS */

/* $ Particulars */

/*     This include file contains the parameters used by the generic */
/*     segments subroutines, SGxxxx. A generic segment is a */
/*     generalization of a DAF array which places a particular structure */
/*     on the data contained in the array, as described below. */

/*     This file defines the mnemonics that are used for the index types */
/*     allowed in generic segments as well as mnemonics for the meta data */
/*     items which are used to describe a generic segment. */

/*     A DAF generic segment contains several logical data partitions: */

/*        1) A partition for constant values to be associated with each */
/*           data packet in the segment. */

/*        2) A partition for the data packets. */

/*        3) A partition for reference values. */

/*        4) A partition for a packet directory, if the segment contains */
/*           variable sized packets. */

/*        5) A partition for a reference value directory. */

/*        6) A reserved partition that is not currently used. This */
/*           partition is only for the use of the NAIF group at the Jet */
/*           Propulsion Laboratory (JPL). */

/*        7) A partition for the meta data which describes the locations */
/*           and sizes of other partitions as well as providing some */
/*           additional descriptive information about the generic */
/*           segment. */

/*                 +============================+ */
/*                 |         Constants          | */
/*                 +============================+ */
/*                 |          Packet 1          | */
/*                 |----------------------------| */
/*                 |          Packet 2          | */
/*                 |----------------------------| */
/*                 |              .             | */
/*                 |              .             | */
/*                 |              .             | */
/*                 |----------------------------| */
/*                 |          Packet N          | */
/*                 +============================+ */
/*                 |      Reference Values      | */
/*                 +============================+ */
/*                 |      Packet Directory      | */
/*                 +============================+ */
/*                 |    Reference  Directory    | */
/*                 +============================+ */
/*                 |       Reserved  Area       | */
/*                 +============================+ */
/*                 |     Segment Meta Data      | */
/*                 +----------------------------+ */

/*     Only the placement of the meta data at the end of a generic */
/*     segment is required. The other data partitions may occur in any */
/*     order in the generic segment because the meta data will contain */
/*     pointers to their appropriate locations within the generic */
/*     segment. */

/*     The meta data for a generic segment should only be obtained */
/*     through use of the subroutine SGMETA. The meta data should not be */
/*     written through any mechanism other than the ending of a generic */
/*     segment begun by SGBWFS or SGBWVS using SGWES. */

/* $ Restrictions */

/*     1) If new reference index types are added, the new type(s) should */
/*        be defined to be the consecutive integer(s) after the last */
/*        defined reference index type used. In this way a value for */
/*        the maximum allowed index type may be maintained. This value */
/*        must also be updated if new reference index types are added. */

/*     2) If new meta data items are needed, mnemonics for them must be */
/*        added to the end of the current list of mnemonics and before */
/*        the NMETA mnemonic. In this way compatibility with files having */
/*        a different, but smaller, number of meta data items may be */
/*        maintained. See the description and example below. */

/* $ Author_and_Institution */

/*     N.J. Bachman      (JPL) */
/*     K.R. Gehringer    (JPL) */
/*     W.L. Taber        (JPL) */
/*     F.S. Turner       (JPL) */

/* $ Literature_References */

/*     Generic Segments Required Reading. */
/*     DAF Required Reading. */

/* $ Version */

/* -    SPICELIB Version 1.1.1, 28-JAN-2004 (NJB) */

/*        Header update: equations for comptutations of packet indices */
/*        for the cases of index types 0 and 1 were corrected. */

/* -    SPICELIB Version 1.1.0, 25-09-98 (FST) */

/*        Added parameter MNMETA, the minimum number of meta data items */
/*        that must be present in a generic DAF segment. */

/* -    SPICELIB Version 1.0.0, 04-03-95 (KRG) (WLT) */

/* -& */

/*     Mnemonics for the type of reference value index. */

/*     Two forms of indexing are provided: */

/*        1) An implicit form of indexing based on using two values, a */
/*           starting value, which will have an index of 1, and a step */
/*           size between reference values, which are used to compute an */
/*           index and a reference value associated with a specified key */
/*           value. See the descriptions of the implicit types below for */
/*           the particular formula used in each case. */

/*        2) An explicit form of indexing based on a reference value for */
/*           each data packet. */


/*     Reference Index Type 0 */
/*     ---------------------- */

/*     Implied index. The index and reference value of a data packet */
/*     associated with a specified key value are computed from the two */
/*     generic segment reference values using the formula below. The two */
/*     generic segment reference values, REF(1) and REF(2), represent, */
/*     respectively, a starting value and a step size between reference */
/*     values. The index of the data packet associated with a key value */
/*     of VALUE is given by: */

/*                          /    VALUE - REF(1)    \ */
/*        INDEX = 1  +  INT | -------------------- | */
/*                          \        REF(2)        / */

/*     and the reference value associated with VALUE is given by: */

/*        REFVAL = REF(1) + DBLE (INDEX-1) * REF(2) */


/*     Reference Index Type 1 */
/*     ---------------------- */

/*     Implied index. The index and reference value of a data packet */
/*     associated with a specified key value are computed from the two */
/*     generic segment reference values using the formula below. The two */
/*     generic segment reference values, REF(1) and REF(2), represent, */
/*     respectively, a starting value and a step size between reference */
/*     values. The index of the data packet associated with a key value */
/*     of VALUE is given by: */

/*                          /          VALUE - REF(1)    \ */
/*        INDEX = 1  +  INT | 0.5 + -------------------- | */
/*                          \              REF(2)        / */


/*     and the reference value associated with VALUE is given by: */

/*        REFVAL = REF(1) + DBLE (INDEX-1) * REF(2) */

/*     We get the larger index in the event that VALUE is halfway between */
/*     X(I) and X(I+1), where X(I) = BUFFER(1) + DBLE (I-1) * REFDAT(2). */


/*     Reference Index Type 2 */
/*     ---------------------- */

/*     Explicit index. In this case the number of packets must equal the */
/*     number of reference values. The index of the packet associated */
/*     with a key value of VALUE is the index of the last reference item */
/*     that is strictly less than VALUE. The reference values must be in */
/*     ascending order, REF(I) < REF(I+1). */


/*     Reference Index Type 3 */
/*     ---------------------- */

/*     Explicit index. In this case the number of packets must equal the */
/*     number of reference values. The index of the packet associated */
/*     with a key value of VALUE is the index of the last reference item */
/*     that is less than or equal to VALUE. The reference values must be */
/*     in ascending order, REF(I) < REF(I+1). */


/*     Reference Index Type 4 */
/*     ---------------------- */

/*     Explicit index. In this case the number of packets must equal the */
/*     number of reference values. The index of the packet associated */
/*     with a key value of VALUE is the index of the reference item */
/*     that is closest to the value of VALUE. In the event of a "tie" */
/*     the larger index is selected. The reference values must be in */
/*     ascending order, REF(I) < REF(I+1). */


/*     These parameters define the valid range for the index types. An */
/*     index type code, MYTYPE, for a generic segment must satisfy the */
/*     relation MNIDXT <= MYTYPE <= MXIDXT. */


/*     The following meta data items will appear in all generic segments. */
/*     Other meta data items may be added if a need arises. */

/*       1)  CONBAS  Base Address of the constants in a generic segment. */

/*       2)  NCON    Number of constants in a generic segment. */

/*       3)  RDRBAS  Base Address of the reference directory for a */
/*                   generic segment. */

/*       4)  NRDR    Number of items in the reference directory of a */
/*                   generic segment. */

/*       5)  RDRTYP  Type of the reference directory 0, 1, 2 ... for a */
/*                   generic segment. */

/*       6)  REFBAS  Base Address of the reference items for a generic */
/*                   segment. */

/*       7)  NREF    Number of reference items in a generic segment. */

/*       8)  PDRBAS  Base Address of the Packet Directory for a generic */
/*                   segment. */

/*       9)  NPDR    Number of items in the Packet Directory of a generic */
/*                   segment. */

/*      10)  PDRTYP  Type of the packet directory 0, 1, ... for a generic */
/*                   segment. */

/*      11)  PKTBAS  Base Address of the Packets for a generic segment. */

/*      12)  NPKT    Number of Packets in a generic segment. */

/*      13)  RSVBAS  Base Address of the Reserved Area in a generic */
/*                   segment. */

/*      14)  NRSV    Number of items in the reserved area of a generic */
/*                   segment. */

/*      15)  PKTSZ   Size of the packets for a segment with fixed width */
/*                   data packets or the size of the largest packet for a */
/*                   segment with variable width data packets. */

/*      16)  PKTOFF  Offset of the packet data from the start of a packet */
/*                   record. Each data packet is placed into a packet */
/*                   record which may have some bookkeeping information */
/*                   prepended to the data for use by the generic */
/*                   segments software. */

/*      17)  NMETA   Number of meta data items in a generic segment. */

/*     Meta Data Item  1 */
/*     ----------------- */


/*     Meta Data Item  2 */
/*     ----------------- */


/*     Meta Data Item  3 */
/*     ----------------- */


/*     Meta Data Item  4 */
/*     ----------------- */


/*     Meta Data Item  5 */
/*     ----------------- */


/*     Meta Data Item  6 */
/*     ----------------- */


/*     Meta Data Item  7 */
/*     ----------------- */


/*     Meta Data Item  8 */
/*     ----------------- */


/*     Meta Data Item  9 */
/*     ----------------- */


/*     Meta Data Item 10 */
/*     ----------------- */


/*     Meta Data Item 11 */
/*     ----------------- */


/*     Meta Data Item 12 */
/*     ----------------- */


/*     Meta Data Item 13 */
/*     ----------------- */


/*     Meta Data Item 14 */
/*     ----------------- */


/*     Meta Data Item 15 */
/*     ----------------- */


/*     Meta Data Item 16 */
/*     ----------------- */


/*     If new meta data items are to be added to this list, they should */
/*     be added above this comment block as described below. */

/*        INTEGER               NEW1 */
/*        PARAMETER           ( NEW1   = PKTOFF + 1 ) */

/*        INTEGER               NEW2 */
/*        PARAMETER           ( NEW2   = NEW1   + 1 ) */

/*        INTEGER               NEWEST */
/*        PARAMETER           ( NEWEST = NEW2   + 1 ) */

/*     and then the value of NMETA must be changed as well to be: */

/*        INTEGER               NMETA */
/*        PARAMETER           ( NMETA  = NEWEST + 1 ) */

/*     Meta Data Item 17 */
/*     ----------------- */


/*     Maximum number of meta data items. This is always set equal to */
/*     NMETA. */


/*     Minimum number of meta data items that must be present in a DAF */
/*     generic segment.  This number is to remain fixed even if more */
/*     meta data items are added for compatibility with old DAF files. */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     SRCHAN     I   Handle of the SPK file with the source segment. */
/*     SRCDSC     I   Descriptor for the source segment. */
/*     DSTHAN     I   Handle of the SPK file for the destination segment. */
/*     DSTDSC     I   Descriptor for the destination segment. */
/*     DSTSID     I   Segment identifier for the new segment. */

/* $ Detailed_Input */

/*     SRCHAN   The handle of the SPK file containing the source segment. */

/*     SRCDSC   The SPK descriptor for the source segment. */

/*     DSTHAN   The handle of the SPK file containing the new segment. */

/*     DSTDSC   The SPK descriptor for the destination segment. It */
/*              contains the desired start and stop times for the */
/*              requested subset. */

/*     DSTSID   The segment identifier for the destination segment. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     None. */

/* $ Files */

/*     See arguments SRCHAN, DSTHAN. */

/* $ Particulars */

/*     This subroutine copies a subset of the data form one SPK segment */
/*     to another. */

/*     The exact structure of a segment of SPK type 10 is detailed in */
/*     the SPK Required Reading. Please see this document for details. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     1) We assume that the source descriptor actually describes a */
/*        segment in the source SPK file containing the time coverage */
/*        that is desired for the subsetting operation. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 30-JUN-1997 (KRG) */

/* -& */
/* $ Index_Entries */

/*     subset type_10 spk segment */

/* -& */

/*     SPICELIB functions */


/*     Local Parameters */


/*     DAF ND and NI values for SPK files. */


/*     The number of geophysical constants: */


/*     The number of elements per two-line set: */


/*     Local Variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "SPKS10", (ftnlen)6);
    }

/*     First, unpack the destination segment descriptor and set some */
/*     local variables. */

    dafus_(__global_state, dstdsc, &__state->c__2, &__state->c__6, dtemp, 
	    itemp);
    begtim = dtemp[0];
    endtim = dtemp[1];

/*     Get the constants for the input segment and send them to the */
/*     output segment by beginning a fixed packet size segment. */

    sgfcon_(__global_state, srchan, srcdsc, &__state->c__1, &__state->c__8, 
	    consts);
    sgbwfs_(__global_state, dsthan, dstdsc, dstsid, &__state->c__8, consts, &
	    __state->c__14, &__state->c__4, dstsid_len);
    if (failed_(__global_state)) {
	chkout_(__global_state, "SPKS10", (ftnlen)6);
	return 0;
    }

/*     Get the beginning and ending indices for the packets we need for */
/*     the destination segment.  Note we need to get the preceding */
/*     and succeeding packets (if there are any) corresponding to the */
/*     start and end times of the output segments */

    sgfrvi_(__global_state, srchan, srcdsc, &begtim, &myref, &begidx, &found);
    if (! found) {
	etcal_(__global_state, &begtim, time, (ftnlen)40);
	setmsg_(__global_state, "An error has occurred while attempting to s"
		"ubset the a type 10 SPK segment. The error occurred while at"
		"tempting to locate a packet for the epoch #.  There does not"
		" appear to be such a packet. ", (ftnlen)192);
	errch_(__global_state, "#", time, (ftnlen)1, (ftnlen)40);
	sigerr_(__global_state, "SPICE(CANNOTGETPACKET)", (ftnlen)22);
	chkout_(__global_state, "SPKS10", (ftnlen)6);
	return 0;
    }
    if (myref > begtim) {
/* Computing MAX */
	i__1 = 1, i__2 = begidx - 1;
	begidx = max(i__1,i__2);
    }
    sgfrvi_(__global_state, srchan, srcdsc, &endtim, &myref, &endidx, &found);
    if (! found) {
	etcal_(__global_state, &endtim, time, (ftnlen)40);
	setmsg_(__global_state, "An error has occurred while attempting to s"
		"ubset the a type 10 SPK segment. The error occurred while at"
		"tempting to locate a packet for the epoch #.  There does not"
		" appear to be such a packet. ", (ftnlen)192);
	errch_(__global_state, "#", time, (ftnlen)1, (ftnlen)40);
	sigerr_(__global_state, "SPICE(CANNOTGETPACKET)", (ftnlen)22);
	chkout_(__global_state, "SPKS10", (ftnlen)6);
	return 0;
    }

/*     Get the total number of epochs. */

    sgmeta_(__global_state, srchan, srcdsc, &__state->c__7, &nepoch);
    if (myref < endtim) {
/* Computing MIN */
	i__1 = nepoch, i__2 = endidx + 1;
	endidx = min(i__1,i__2);
    }

/*     Now we get the data one record at a time from the source segment */
/*     and write it out to the destination segment. */

    i__1 = endidx;
    for (i__ = begidx; i__ <= i__1; ++i__) {
	sgfpkt_(__global_state, srchan, srcdsc, &i__, &i__, packet, &dummy);
	sgfref_(__global_state, srchan, srcdsc, &i__, &i__, &myref);
	sgwfpk_(__global_state, dsthan, &__state->c__1, packet, &
		__state->c__1, &myref);
    }

/*     Now all we need to do is end the segment. */

    sgwes_(__global_state, dsthan);
    chkout_(__global_state, "SPKS10", (ftnlen)6);
    return 0;
} /* spks10_ */

