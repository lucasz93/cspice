/* sgseqw.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern sgseqw_init_t __sgseqw_init;
static inline sgseqw_state_t* get_sgseqw_state(cspice_t* state) {
	if (!state->sgseqw)
		state->sgseqw = __cspice_allocate_module(sizeof(
	sgseqw_state_t), &__sgseqw_init, sizeof(__sgseqw_init));
	return state->sgseqw;

}

/* $Procedure  SGSEQW ( Generic segements: Sequential writer. ) */
/* Subroutine */ int sgseqw_0_(cspice_t* __global_state, int n__, integer *
	handle, doublereal *descr, char *segid, integer *nconst, doublereal *
	const__, integer *npkts, integer *pktsiz, doublereal *pktdat, integer 
	*nrefs, doublereal *refdat, integer *idxtyp, ftnlen segid_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);
    double d_int(f2c_state_t*, doublereal *);

    /* Local variables */
    integer meta[17];
    integer size;
    integer i__;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    doublereal xmeta[17];
    doublereal myref;
    extern /* Subroutine */ int dafada_(cspice_t*, doublereal *, integer *);
    extern /* Subroutine */ int dafcad_(cspice_t*, integer *);
    extern /* Subroutine */ int dafgda_(cspice_t*, integer *, integer *, 
	    integer *, doublereal *);
    extern /* Subroutine */ int dafbna_(cspice_t*, integer *, doublereal *, 
	    char *, ftnlen);
    char dummy1[60];
    integer dummy2;
    integer dummy3;
    extern /* Subroutine */ int dafena_(cspice_t*);
    integer nc;
    integer nd;
    extern logical failed_(cspice_t*);
    integer begadr;
    integer ni;
    extern /* Subroutine */ int dafhsf_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int dafsih_(cspice_t*, integer *, char *, ftnlen);
    integer refadr;
    extern /* Subroutine */ int dafrfr_(cspice_t*, integer *, integer *, 
	    integer *, char *, integer *, integer *, integer *, ftnlen);
    integer sidlen;
    extern /* Subroutine */ int errhan_(cspice_t*, char *, integer *, ftnlen);
    doublereal myaddr;
    extern integer isrchi_(cspice_t*, integer *, integer *, integer *);
    extern integer lastnb_(cspice_t*, char *, ftnlen);
    integer pktadr;
    doublereal dpksiz;
    extern logical return_(cspice_t*);
    doublereal mysize;
    integer pktpos;
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    integer ich;


    /* Module state */
    sgseqw_state_t* __state = get_sgseqw_state(__global_state);
/* $ Abstract */

/*     This is the umbrella routine for managing the sequential writing */
/*     of generic segments to DAF files. It should never be called */
/*     directly, it provides the mechanism whereby data are shared by */
/*     its entry points. */

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

/*     DAF Required Reading. */

/* $ Keywords */

/*     GENERIC SEGMENTS */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*      HANDLE    I    Handle of a DAF file opened with write access. */
/*      DESCR     I    Descriptor for a generic segment. */
/*      SEGID     I    Identifier for a generic segment. */
/*      NCONST    I    Number of constant values in a generic segment. */
/*      CONST     I    Array of constant values for a generic segment. */
/*      NPKTS     I    Number of data packets to write to a segment. */
/*      PKTSIZ    I    Size of fixed size packets or sizes of variable */
/*                     size packets. */
/*      PKTDAT    I    Array of packet data. */
/*      NREFS     I    Number of reference values. */
/*      REFDAT    I    Reference data. */
/*      IDXTYP    I    Index type for the reference values. */

/* $ Detailed_Input */

/*      HANDLE   Handle of a DAF file opened with write access. This is */
/*               the handle of the file in which a generic segment will */
/*               be started, or the handle of a file in which a generic */
/*               segment is currently being written. */

/*      DESCR    Descriptor for the generic segment that is being */
/*               written. This is the packed form of the DAF double */
/*               precision and integer summaries which contains ND double */
/*               precision numbers and NI integers, respectively. */

/*      SEGID    Identifier for the generic segment that is being */
/*               written. This is a character string containing at most */
/*               NC printing ASCII characters where */

/*                                 /  ND + ( NI + 1 )  \ */
/*                      NC =  8 *  | ----------------- | */
/*                                 \         2         / */

/*                SEGID may be blank. */

/*      NCONST   The number of constant values to be placed in the */
/*               generic segment. */

/*      CONST    An array of NCONST constant values for the generic */
/*               segment. */

/*      NPKTS    Number of data packets to write to a generic segment. */

/*      PKTSIZ   Size of fixed size packets or sizes of variable size */
/*               packets. */

/*               The size of a packet is the number of double precision */
/*               numbers it contains. */

/*               When writing a segment with fixed size packets, only */
/*               the first element of the array, PKTSIZ(1), is used, and */
/*               it should contain the size of the fixed size packets. In */
/*               this instance, the calling program need not declare this */
/*               variable as an array of one integer; it may be declared */
/*               as an integer variable. */

/*               When writing a segment with variable size packets, */
/*               there must be an element in the array PKTSIZ for each of */
/*               the data packets. */

/*      PKTDAT   A singly dimensioned array containing the double */
/*               precision data for the fixed or variable size data */
/*               packets to be added to the generic segment associated */
/*               with HANDLE. */

/*               For fixed size data packets, PKTDAT will have the */
/*               following structure: */

/*               Packet #  Range of locations for the packet data. */
/*               --------  --------------------------------------------- */

/*                     1   PKTDAT(1)              to PKTDAT(PS) */
/*                     2   PKTDAT(PS+1)           to PKTDAT(2*PS) */
/*                     3   PKTDAT(2*PS+1)         to PKTDAT(3*PS) */
/*                     4   PKTDAT(3*PS+1)         to PKTDAT(4*PS) */

/*                                          . */
/*                                          . */
/*                                          . */

/*                 NPKTS   PKTDAT((NPKTS-1)*PS+1) to PKTDAT(NPKTS*PS) */

/*               where PS = PKTSIZ(1). */

/*               For variable size data packets, PKTDAT will have the */
/*               following structure: */

/*               Packet #  Range of locations for the packet data. */
/*               --------  --------------------------------------------- */

/*                     1   PKTDAT(1)           to PKTDAT(P(1)) */
/*                     2   PKTDAT(P(1)+1)      to PKTDAT(P(2)) */
/*                     3   PKTDAT(P(2)+1)      to PKTDAT(P(3)) */
/*                     4   PKTDAT(P(3)+1)      to PKTDAT(P(4)) */

/*                                          . */
/*                                          . */
/*                                          . */

/*                 NPKTS   PKTDAT(P(NPKTS-1)+1) to PKTDAT(P(NPKTS)) */

/*                                I */
/*                               --- */
/*               where P(I) =    >   PKTSIZ(K). */
/*                               --- */
/*                              K = 1 */

/*      NREFS    Number of reference values. */

/*               For implicitly indexed packets, NREFS must have a value */
/*               of two (2). */

/*               When writing packets to a generic segment which uses an */
/*               implicit index type, the value specified by NREFS is */
/*               used only on the first call to SGWFPK or SGWVPK. On all */
/*               subsequent calls to these subroutines for a particular */
/*               implicitly indexed generic segment, the value of NREFS */
/*               is ignored. */

/*               For explicitly indexed packets, NREFS must be equal to */
/*               NPKTS; there should be a reference value for each data */
/*               packet being written to the generic segment. */

/*               When writing packets to a segment which uses an explicit */
/*               index type, the value specified by NREFS is used on */
/*               every call to SGWFPK or SGWVPK and it must always be */
/*               equal to NPKTS. */

/*      REFDAT   Reference data values. */

/*               For implicitly indexed packets, there must be two (2) */
/*               values. The values represent a starting value, which */
/*               will have an index of 1, and a step size between */
/*               reference values, which are used to compute an index and */
/*               a reference value associated with a specified key value. */

/*               In order to avoid, or at least minimize, numerical */
/*               difficulties associated with computing index values for */
/*               generic segments with implicit index types, the value of */
/*               the stepsize must be an integer, i.e., DINT(REFDAT(2)) */
/*               must equal REFDAT(2). In this case, we also recommend */
/*               that REFDAT(1) be an integer, although this is not */
/*               enforced. */

/*               When writing packets to a generic segment which uses an */
/*               implicit index type, the values specified by REFDAT are */
/*               used only on the first call to SGWFPK or SGWVPK. On all */
/*               subsequent calls to these subroutines for a particular */
/*               implicitly indexed generic segment REFDAT is ignored. */

/*               For explicitly indexed packets, there must be NPKTS */
/*               reference values and the values must be in increasing */
/*               order: */

/*                  REFDAT(I) < REFDAT(I+1), I = 1, NPKTS-1 */

/*               When writing packets to a segment which uses an explicit */
/*               index type, the values specified by REFDAT are used on */
/*               every call to SGWFPK or SGWVPK. On all calls to these */
/*               subroutines after the first, the value of REFDAT(1) must */
/*               be strictly greater than than the value of REFDAT(NPKTS) */
/*               from the previous call. This preserves the ordering of */
/*               the reference values for the entire segment. */

/*      IDXTYP   Index type to use for the reference values. */

/*               Two forms of indexing are provided: */

/*                  1) An implicit form of indexing based on using two */
/*                     values, a starting value, which will have an index */
/*                     of 1, and a step size between reference values, */
/*                     which are used to compute an index and a reference */
/*                     value associated with a specified key value. See */
/*                     the descriptions of the implicit types below for */
/*                     the particular formula used in each case. */

/*                  2) An explicit form of indexing based on a reference */
/*                     value for each data packet. */

/*               See the chapter on Generic segments in the DAF required */
/*               or the include file 'sgparam.inc' for more details */
/*               about the index types that are available. */

/* $ Detailed_Output */

/*     None. */

/*     The data passed to the various entry points of this subroutine are */
/*     used to construct a generic segment in one or more DAF files, with */
/*     the current file specified by the input argument HANDLE. */

/* $ Parameters */

/*     The entry points in this subroutine make use of parameters defined */
/*     in the file 'sgparam.inc'. */

/* $ Exceptions */

/*     1) If this subroutine is called directly rather than through one */
/*        of its entry points, the error SPICE(BOGUSENTRY) will be */
/*        signalled. */

/*     See the individual entry points for descriptions of their */
/*     exceptions. */

/* $ Files */

/*     See HANDLE in the $ Detailed_Input section above. */

/* $ Particulars */

/*     This is the umbrella routine for managing the sequential writing */
/*     of generic segments to DAF files. It should never be called */
/*     directly, but provides the mechanism whereby data are shared by */
/*     its entry points. The entry points included in this subroutine */
/*     are: */

/*     SGBWFS ( HANDLE, DESCR, SEGID, NCONST, CONST, PKTSIZ, IDXTYP ) */
/*        Begin writing a generic segment with fixed size packets. */

/*     SGBWVS ( HANDLE, DESCR, SEGID, NCONST, CONST, IDXTYP ) */
/*        Begin writing a generic segment with variable size packets. */

/*     SGWFPK ( HANDLE, NPKTS, PKTDAT, NREFS, REFDAT ) */
/*        Write fixed size packets to a generic segment started by */
/*        calling SGBWFS. */

/*     SGWVPK ( HANDLE, NPKTS, PKTSIZ, PKTDAT, NREFS, REFDAT ) */
/*        Write variable size packets to a generic segment started by */
/*        calling SGBWVS. */

/*     SGWES ( HANDLE ) */
/*        End a generic segment. */

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

/*     The entry points of this subroutine when used together provide the */
/*     following capabilities: */

/*        1) The ability to write a generic segment with fixed size data */
/*           packets to a DAF. */

/*        2) the ability to write a generic segment with variable size */
/*           data packets to a DAF. */

/*        3) The ability to write generic segments to multiple files. */
/*           Only a single generic segment may be written to a particular */
/*           file at any time, but several files may each have a generic */
/*           segment being written to them at the same time. */

/*     Packets may be placed into a generic segment one at a time or N at */
/*     at time, depending upon the whim of the programmer, limitations */
/*     of the computing equipment (memory), or requirements placed upon */
/*     the software that will write a generic segment. */

/*     Packets are retrieved from a generic segment by an index which may */
/*     be obtained by using the subroutine SGFRVI (generic segments fetch */
/*     reference value and index). */

/* $ Examples */

/*     In examples 1 and 3, we make use of the fictitious subroutines */

/*        GET_FIX_PKT ( PACKET, REF, DONE ) */

/*     and */

/*        GET_VAR_PKT ( PACKET, SIZE, REF, DONE ) */

/*     where */

/*        DONE   is a logical flag indicating whether there is more data */
/*               available. DONE = .TRUE. implies there is no more data. */
/*               DONE = .FALSE. implies there is more data available. */

/*        PACKET is a double precision array of an appropriate size to */
/*               hold all of the data returned. */

/*        REF    is a double precision reference value that will be used */
/*               to create an index for the data packets in the segment. */
/*               The values of this variable are always increasing, e.g., */
/*               the value of REF on the second call to GET_FIX_PKT or */
/*               GET_VAR_PKT will be greater than the value on the first */
/*               call to the subroutine. */

/*        SIZE   is an integer for the size of the variable size data */
/*               packet that is returned. */

/*     These subroutines return a fixed size data packet and a variable */
/*     size data packet, respectively. We make use of these fictitious */
/*     subroutines in the examples to avoid adding unnecessary or */
/*     distracting complications. */

/*     You may think of these subroutines as methods for acquiring data */
/*     from a "black-box" process. In the first case, the data is always */
/*     returned in fixed size blocks from a black-box that fills a local */
/*     buffer with data and always returned the entire buffer when data */
/*     is requested, e.g., an instrument that measures the concentrations */
/*     of carbon dioxide, sulfer dioxide, ozone, and other constituents */
/*     of the air. In the second case, the data is returned in variably */
/*     sized blocks from a black-box, e.g., an algorithm which integrates */
/*     a function using polynomials of varying degree; different numbers */
/*     of coefficients are required for polynomials of differing degrees. */

/*     In examples 2 and 4, we make use of the fictitious subroutines */

/*        GET_FIX_PKTS ( NPKTS, PKTS, REFS, DONE ) */

/*     and */

/*        GET_VAR_PKTS ( NPKTS, PKTS, SIZES, REFS, DONE ) */

/*     where */

/*        DONE   is a logical flag indicating whether there is more data */
/*               available. DONE = .TRUE. implies there is no more data. */
/*               DONE = .FALSE. implies there is more data available; */

/*        NPKTS  is the number of data packets returned in the array */
/*               PKTS. */

/*        PKTS   is a double precision array containing NPKTS data */
/*               packets, either fixed size or variable size, and is of */
/*               an appropriate size to hold all of the data returned. */
/*               See the description of PKTDAT above for the exact manner */
/*               in which fixed size packets and variable size packets */
/*               are stored in an array. */

/*        REFS   is a double precision array which contains NPKTS */
/*               reference values that will be used to create an index */
/*               for the data packets in the segment. The values of this */
/*               variable are always increasing, e.g., the first value of */
/*               REFS on the second call to GET_FIX_PKTS or GET_VAR_PKTS */
/*               will be greater than the last value of REFS on the first */
/*               call to the subroutine. */

/*        SIZES  is an array of integers containing the sizes of each of */
/*               the variable size data packets that is returned in PKTS. */

/*     These subroutines return arrays containing one or more fixed size */
/*     data packets and one or more variable size data packets, */
/*     respectively. We make use of these fictitious subroutines in the */
/*     examples to avoid adding unnecessary or distracting complications. */

/*     For each example, we provide a simple code fragment that */
/*     demonstrates the use of the entry points to create generic */
/*     segments. We assume that all of the relevant variables are defined */
/*     at the time that the entry points are invoked. These code */
/*     fragments are for illustrative purposes; they do not necessarily */
/*     conform to what would be considered good programming practice. */

/*     Example 1-A: Adding fixed size packets one at a time. */

/*        For this example, we make no assumptions about the reference */
/*        values returned by GET_VAR_PKT other than they are increasing. */
/*        Having no other information about the reference values, we must */
/*        use an explicit indexing method to store the packets. */

/*                                . */
/*                                . */
/*                                . */
/*        C */
/*        C     First we begin a fixed size segment. To do this, we */
/*        C     need: */
/*        C */
/*        C        HANDLE -- The handle of a DAF opened with write */
/*        C                  access. */
/*        C        DESCR  -- The packed descriptor for the segment that */
/*        C                  we want to create. */
/*        C        SEGID  -- A short character string that provides an */
/*        C                  identifier for the segment. */
/*        C        NCONST -- The number of constant values to be */
/*        C                  associated with all of the packets in the */
/*        C                  segment. */
/*        C        CONST  -- An array of constant values to be associated */
/*        C                  with all of the packets in a segment. */
/*        C        PKTSIZ -- The size of the packets that will be stored */
/*        C                  in this segment, i.e., the number of double */
/*        C                  precision numbers necessary to store a */
/*        C                  complete data packet. */
/*        C        EXPCLS -- The type of indexing scheme that we will use */
/*        C                  for searching the segment to obtain a data */
/*        C                  packet. In this case, we are going to use */
/*        C                  an exlicit index, which requires a reference */
/*        C                  value for each data packet, and when */
/*        C                  searching for a data packet we will choose */
/*        C                  the packet with a reference value closest to */
/*        C                  the requested value. See the include file */
/*        C                  'sgparam.inc' for the value of EXPCLS. */
/*        C */
/*              CALL SGBWFS ( HANDLE, DESCR,  SEGID,  NCONST, */
/*             .              CONST,  PKTSIZ, EXPCLS          ) */
/*        C */
/*        C     We loop until done, obtaining a fixed size packet */
/*        C     and writing it to the generic segment in the file. */
/*        C */
/*              DONE = .FALSE. */
/*              DO WHILE ( .NOT. DONE ) */
/*        C */
/*        C        Get a fixed size packet and a reference value. */
/*        C */
/*                 CALL GET_FIX_PKT ( PACKET, REF, DONE ) */
/*        C */
/*        C        Write the packet to the segment, unless we're done. */
/*        C */
/*                 IF ( .NOT. DONE ) THEN */

/*                    CALL SGWFPK ( HANDLE, 1, PACKET, 1, REF ) */

/*                 END IF */

/*              END DO */
/*        C */
/*        C     End the segment and move on to other things. */
/*        C */
/*              CALL SGWES ( HANDLE ) */
/*                                . */
/*                                . */
/*                                . */

/*     Example 1-B: Adding fixed size packets with uniformly spaced */
/*                  reference values. */

/*        In the previous example, we made no assumptions about the */
/*        reference values other than that they were increasing. We now */
/*        will assume that the reference values are also equally spaced */
/*        and that we have a priori values for a beginning reference */
/*        value, BEGIN_REF, and a stepsize, STEP_SIZE, that is the */
/*        difference between two consecutive reference values. We have */

/*           BEGIN_REF <= REF <= BEGIN_REF + (N-1) * STEP_SIZE */

/*        where BEGIN_REF equals the first reference value returned by */
/*        GET_FIX_PKT and BEGIN_REF + (N-1) * STEP_SIZE equals the last */
/*        reference value returned. Under these assumptions we can use an */
/*        implicit index for the data packets which will provide a more */
/*        space efficient method for putting the data packets into a */
/*        generic segment.  We repeat the example under these assumptions */
/*        using an implicit indexing method. Nothing else has changed. */

/*        The index for a data packet in the implicitly indexed generic */
/*        segment we create is computed from the formula: */

/*                          /          VALUE - REFDAT(1)    \ */
/*            INDEX = IDINT | 1.5 + ----------------------- | */
/*                          \              REFDAT(2)        / */

/*        where the index for the data packet associated with VALUE is */
/*        desired. */

/*        The reference value associated with this index is: */

/*            REF   =  REFDAT(1) + REFDAT*(INDEX - 1) */

/*                                . */
/*                                . */
/*                                . */
/*        C */
/*        C     First we begin a fixed size segment. To do this, we */
/*        C     need: */
/*        C */
/*        C        HANDLE -- The handle of a DAF opened with write */
/*        C                  access. */
/*        C        DESCR  -- The packed descriptor for the segment that */
/*        C                  we want to create. */
/*        C        SEGID  -- A short character string that provides an */
/*        C                  identifier for the segment. */
/*        C        NCONST -- The number of constant values to be */
/*        C                  associated with all of the packets in the */
/*        C                  segment. */
/*        C        CONST  -- An array of constant values to be associated */
/*        C                  with all of the packets in a segment. */
/*        C        PKTSIZ -- The size of the packets that will be stored */
/*        C                  in this segment, i.e., the number of double */
/*        C                  precision numbers necessary to store a */
/*        C                  complete data packet. */
/*        C        IMPCLS -- The type of indexing scheme that we will use */
/*        C                  for searching the segment to obtain a data */
/*        C                  packet. In this case, we are going to use */
/*        C                  an implicit index, which requires beginning */
/*        C                  and ending times which bound all reference */
/*        C                  values, and when searching for a data packet */
/*        C                  we will choose the packet whose index is */
/*        C                  computed by the formula above. See the */
/*        C                  include file 'sgparam.inc' for the value */
/*        C                  of IMPCLS */
/*        C */
/*              CALL SGBWFS ( HANDLE, DESCR,  SEGID,  NCONST, */
/*             .              CONST,  PKTSIZ, IMPCLS          ) */
/*        C */
/*        C     Set the beginning and ending reference values for the */
/*        C     implicit indexing method. */
/*        C */
/*              REFS(1) = BEGIN_REF */
/*              REFS(2) = STEP_SIZE */
/*        C */
/*        C     Get the first data packet and put it in the generic */
/*        C     segment. At the same time, we write the bounds used for */
/*        C     the implicit indexing. We ignore the value of REF since */
/*        C     the reference values are equally spaced and we are using */
/*        C     an implicit indexing method. We do not check DONE here */
/*        C     because we assume that there is at least one data packet. */
/*        C */
/*              CALL GET_FIX_PKT ( PACKET, REF, DONE ) */

/*              CALL SGWFPK ( HANDLE, 1, PACKET, 2, REFS ) */
/*        C */
/*        C     We loop until done, obtaining a fixed size packet */
/*        C     and writing it to the generic segment in the file. */
/*        C */
/*              DO WHILE ( .NOT. DONE ) */
/*        C */
/*        C        Get a fixed size packet and a reference value. */
/*        C */
/*                 CALL GET_FIX_PKT ( PACKET, REF, DONE ) */
/*        C */
/*        C        Write the packet to the segment, unless we're done. */
/*        C        Because this segment is implicitly indexed, the last */
/*        C        two calling arguments are only used in the first call */
/*        C        to SGWFPK above. they are ignored in all subsequent */
/*        C        calls, so we may pass "dummy" arguments. */
/*        C */
/*                 IF ( .NOT. DONE ) THEN */

/*                    CALL SGWFPK ( HANDLE, 1, PACKET, DUM1, DUM2 ) */

/*                 END IF */

/*              END DO */
/*        C */
/*        C     End the segment and move on to other things. */
/*        C */
/*              CALL SGWES ( HANDLE ) */
/*                                . */
/*                                . */
/*                                . */

/*     Example 2: Adding fixed size packets more efficiently. */

/*        It is possible to add more than one fixed size data packet to a */
/*        generic segment at one time. Doing this will usually prove to */
/*        be a more efficient way of adding the data packets, provided */
/*        there is sufficient storage to hold more than one data packet */
/*        available. This example demonstrates this capability. */

/*        For this example, we make no assumptions about the reference */
/*        values returned by GET_FIX_PKTS other than they are increasing. */
/*        Having no other information about the reference values, we must */
/*        use an explicit indexing method to store the packets. */

/*                                . */
/*                                . */
/*                                . */
/*        C */
/*        C     First we begin a fixed size segment. To do this, we */
/*        C     need: */
/*        C */
/*        C        HANDLE -- The handle of a DAF opened with write */
/*        C                  access. */
/*        C        DESCR  -- The packed descriptor for the segment that */
/*        C                  we want to create. */
/*        C        SEGID  -- A short character string that provides an */
/*        C                  identifier for the segment. */
/*        C        NCONST -- The number of constant values to be */
/*        C                  associated with all of the packets in the */
/*        C                  segment. */
/*        C        CONST  -- An array of constant values to be associated */
/*        C                  with all of the packets in a segment. */
/*        C        PKTSIZ -- The size of the packets that will be stored */
/*        C                  in this segment, i.e., the number of double */
/*        C                  precision numbers necessary to store a */
/*        C                  complete data packet. */
/*        C        EXPCLS -- The type of indexing scheme that we will use */
/*        C                  for searching the segment to obtain a data */
/*        C                  packet. In this case, we are going to use */
/*        C                  an exlicit index, which requires a reference */
/*        C                  value for each data packet, and when */
/*        C                  searching for a data packet we will choose */
/*        C                  the packet with a reference value closest to */
/*        C                  the requested value. See the include file */
/*        C                  'sgparam.inc' for the value of EXPCLS */
/*        C */
/*              CALL SGBWFS ( HANDLE, DESCR,  SEGID,  NCONST, */
/*             .              CONST,  PKTSIZ, EXPCLS          ) */
/*        C */
/*        C     We loop until done, obtaining a fixed size packet */
/*        C     and writing it to the generic segment in the file. */
/*        C */
/*              DONE = .FALSE. */
/*              DO WHILE ( .NOT. DONE ) */
/*        C */
/*        C        Get a collection of fixed size packet and associated */
/*        C        array of increasing reference values. */
/*        C */
/*                 CALL GET_FIX_PKTS ( NPKTS, PKTS, REFS, DONE ) */
/*        C */
/*        C        Write the packets to the segment if we have any. Since */
/*        C        we are using an explicit index, the number of */
/*        C        reference values is the same as the number of data */
/*        C        packets. */
/*        C */
/*                 IF ( .NOT. DONE ) THEN */

/*                    CALL SGWFPK ( HANDLE, NPKTS, PKTS, NPKTS, REFS ) */

/*                 END IF */

/*              END DO */
/*        C */
/*        C     End the segment and move on to other things. */
/*        C */
/*              CALL SGWES ( HANDLE ) */
/*                                . */
/*                                . */
/*                                . */

/*        If we are using an implicit indexing method, multiple data */
/*        packets may be added with one call to SGWFPK as in the above */
/*        example for an explicit index, with the exception that there */
/*        are only two reference values, and they are specified on the */
/*        first call to SGWFPK, as in Example 1-B. */

/*     Example 3-A: Adding variable size packets one at a time. */

/*        For this example, we make no assumptions about the reference */
/*        values returned by GET_VAR_PKT other than they are increasing. */
/*        Having no other information about the reference values, we must */
/*        use an explicit indexing method to store the packets. */

/*                                . */
/*                                . */
/*                                . */
/*        C */
/*        C     First we begin a variable size segment. To do this, we */
/*        C     need: */
/*        C */
/*        C        HANDLE -- The handle of a DAF opened with write */
/*        C                  access. */
/*        C        DESCR  -- The packed descriptor for the segment that */
/*        C                  we want to create. */
/*        C        SEGID  -- A short character string that provides an */
/*        C                  identifier for the segment. */
/*        C        NCONST -- The number of constant values to be */
/*        C                  associated with all of the packets in the */
/*        C                  segment. */
/*        C        CONST  -- An array of constant values to be associated */
/*        C                  with all of the packets in a segment. */
/*        C        EXPCLS -- The type of indexing scheme that we will use */
/*        C                  for searching the segment to obtain a data */
/*        C                  packet. In this case, we are going to use */
/*        C                  an exlicit index, which requires a reference */
/*        C                  value for each data packet, and when */
/*        C                  searching for a data packet we will choose */
/*        C                  the packet with a reference value closest to */
/*        C                  the requested value. See the include file */
/*        C                  'sgparam.inc' for the value of EXPCLS. */
/*        C */
/*              CALL SGBVFS ( HANDLE, DESCR, SEGID, */
/*             .              NCONST, CONST, EXPCLS ) */
/*        C */
/*        C     We loop until done, obtaining a variable size packet */
/*        C     and writing it to the generic segment in the file. */
/*        C */
/*              DONE = .FALSE. */
/*              DO WHILE ( .NOT. DONE ) */
/*        C */
/*        C        Get a variable size packet and a reference value. */
/*        C */
/*                 CALL GET_VAR_PKT ( PACKET, SIZE, REF, DONE ) */
/*        C */
/*        C        Write the packet to the segment, unless we're done. */
/*        C */
/*                 IF ( .NOT. DONE ) THEN */

/*                    CALL SGWVPK ( HANDLE, 1, SIZE, PACKET, 1, REF ) */

/*                 END IF */

/*              END DO */
/*        C */
/*        C     End the segment and move on to other things. */
/*        C */
/*              CALL SGWES ( HANDLE ) */
/*                                . */
/*                                . */
/*                                . */

/*     Example 3-B: Adding variable size packets one at a time with */
/*                  uniformly spaced reference values. */

/*        In the previous example, we made no assumptions about the */
/*        reference values other than that they were increasing. We now */
/*        will assume that the reference values are also equally spaced */
/*        and that we have a priori values for a beginning reference */
/*        value, BEGIN_REF, and a stepsize, STEP_SIZE, that is the */
/*        difference between two consecutive reference values. We have */

/*           BEGIN_REF <= REF <= BEGIN_REF + (N-1) * STEP_SIZE */

/*        where BEGIN_REF equals the first reference value returned by */
/*        GET_VAR_PKT and BEGIN_REF + (N-1) * STEP_SIZE equals the last */
/*        reference value returned. Putting all of this together means */
/*        that we can use an implicit index for the data packets which */
/*        will provide a more space efficient method for putting the data */
/*        packets into a generic segment.  We repeat the example under */
/*        these assumptions using an implicit indexing method. Nothing */
/*        else has changed. */

/*        The index for a data packet in the implicitly indexed generic */
/*        segment we create is computed from the formula: */

/*                          /          VALUE - REFDAT(1)    \ */
/*            INDEX = IDINT | 1.5 + ----------------------- | */
/*                          \              REFDAT(2)        / */

/*        where the index for the data packet associated with VALUE is */
/*        desired. */

/*        The reference value associated with this index is: */

/*            REF   =  REFDAT(1) + REFDAT*(INDEX - 1) */

/*                                . */
/*                                . */
/*                                . */
/*        C */
/*        C     First we begin a variable size segment. To do this, we */
/*        C     need: */
/*        C */
/*        C        HANDLE -- The handle of a DAF opened with write */
/*        C                  access. */
/*        C        DESCR  -- The packed descriptor for the segment that */
/*        C                  we want to create. */
/*        C        SEGID  -- A short character string that provides an */
/*        C                  identifier for the segment. */
/*        C        NCONST -- The number of constant values to be */
/*        C                  associated with all of the packets in the */
/*        C                  segment. */
/*        C        CONST  -- An array of constant values to be associated */
/*        C                  with all of the packets in a segment. */
/*        C        IMPCLS -- The type of indexing scheme that we will use */
/*        C                  for searching the segment to obtain a data */
/*        C                  packet. In this case, we are going to use */
/*        C                  an implicit index, which requires beginning */
/*        C                  and ending times which bound all reference */
/*        C                  values, and when searching for a data packet */
/*        C                  we will choose the packet whose index is */
/*        C                  computed by the formula above. See the */
/*        C                  include file 'sgparam.inc' for the value of */
/*        C                  IMPCLS. */
/*        C */
/*              CALL SGBWVS ( HANDLE, DESCR,  SEGID,  NCONST, */
/*             .              CONST,  IMPCLS                   ) */
/*        C */
/*        C     Set the beginning and ending reference values for the */
/*        C     implicit indexing method. */
/*        C */
/*              REFS(1) = BEGIN_REF */
/*              REFS(2) = STEP_SIZE */
/*        C */
/*        C     Get the first data packet and put it in the generic */
/*        C     segment. At the same time, we write the bounds used for */
/*        C     the implicit indexing. We ignore the value of REF since */
/*        C     the reference values are equally spaced and we are using */
/*        C     an implicit indexing method. We do not check DONE here */
/*        C     because we assume that there is at least one data packet. */
/*        C */
/*              CALL GET_VAR_PKT ( PACKET, SIZE, REF, DONE ) */

/*              CALL SGWVPK ( HANDLE, 1, SIZE, PACKET, 2, REFS ) */
/*        C */
/*        C     We loop until done, obtaining a fixed size packet */
/*        C     and writing it to the generic segment in the file. */
/*        C */
/*              DO WHILE ( .NOT. DONE ) */
/*        C */
/*        C        Get a variable size packet and a unique reference */
/*        C        value. */
/*        C */
/*                 CALL GET_VAR_PKT ( PACKET, SIZE, REF, DONE ) */
/*        C */
/*        C        Write the packet to the segment, unless we're done. */
/*        C        Because this segment is implicitly indexed, the last */
/*        C        two calling arguments are only used in the first call */
/*        C        to SGWFPK above. they are ignored in all subsequent */
/*        C        calls, so we may pass "dummy" arguments. */
/*        C */
/*                 IF ( .NOT. DONE ) THEN */

/*                    CALL SGVFPK ( HANDLE, 1, SIZE, PACKET, DUM1, DUM2 ) */

/*                 END IF */

/*              END DO */
/*        C */
/*        C     End the segment and move on to other things. */
/*        C */
/*              CALL SGWES ( HANDLE ) */
/*                                . */
/*                                . */
/*                                . */

/*     Example 4: Adding variable size packets more efficiently. */

/*        It is possible to add more than one variable size data packet */
/*        to a generic segment at one time. Doing this will usually prove */
/*        to be a more efficient way of adding the data packets, provided */
/*        there is sufficient storage to hold more than one data packet */
/*        available. This example demonstrates this capability. */

/*        For this example, we make no assumptions about the reference */
/*        values returned by GET_VAR_PKTS other than they are increasing. */
/*        Having no other information about the reference values, we must */
/*        use an explicit indexing method to store the packets. */

/*                                . */
/*                                . */
/*                                . */
/*        C */
/*        C     First we begin a variable size segment. To do this, we */
/*        C     need: */
/*        C */
/*        C        HANDLE -- The handle of a DAF opened with write */
/*        C                  access. */
/*        C        DESCR  -- The packed descriptor for the segment that */
/*        C                  we want to create. */
/*        C        SEGID  -- A short character string that provides an */
/*        C                  identifier for the segment. */
/*        C        NCONST -- The number of constant values to be */
/*        C                  associated with all of the packets in the */
/*        C                  segment. */
/*        C        CONST  -- An array of constant values to be associated */
/*        C                  with all of the packets in a segment. */
/*        C        EXPCLS -- The type of indexing scheme that we will use */
/*        C                  for searching the segment to obtain a data */
/*        C                  packet. In this case, we are going to use */
/*        C                  an exlicit index, which requires a reference */
/*        C                  value for each data packet, and when */
/*        C                  searching for a data packet we will choose */
/*        C                  the packet with a reference value closest to */
/*        C                  the requested value. See the include file */
/*        C                  sgparam.inc for the value of EXPCLS. */
/*        C */
/*              CALL SGBWVS ( HANDLE, DESCR,  SEGID, */
/*        C    .              NCONST, CONST, EXPCLS  ) */
/*        C */
/*        C     We loop until done, obtaining a fixed size packet */
/*        C     and writing it to the generic segment in the file. */
/*        C */
/*              DONE = .FALSE. */
/*              DO WHILE ( .NOT. DONE ) */
/*        C */
/*        C        Get a collection of variable size packets and an */
/*        C        array of increasing reference values. */
/*        C */
/*                 GET_VAR_PKTS ( NPKTS, PKTS, SIZES, REFS, DONE ) */
/*        C */
/*        C        Write the packets to the segment if we have any. Since */
/*        C        we are using an explicit index, the number of */
/*        C        reference values is the same as the number of data */
/*        C        packets. */
/*        C */
/*                 IF ( NPKTS .GT. 0 ) THEN */

/*                    CALL SGWVPK ( HANDLE, NPKTS, SIZES, */
/*             .                    PKTS,   NPKTS, REFS   ) */

/*                 END IF */

/*              END DO */
/*        C */
/*        C     End the segment and move on to other things. */
/*        C */
/*              CALL SGWES ( HANDLE ) */
/*                                . */
/*                                . */
/*                                . */

/*        If we are using an implicit indexing method, multiple data */
/*        packets may be added with one call to SGWVPK as in the above */
/*        example for an explicit index, with the exception that there */
/*        are only two reference values, and they are specified on the */
/*        first call to SGWVPK, as in Example 3-B. */

/*     Example 5: Adding packets to multiple files. */

/*        It is possible to write multiple generic segments to different */
/*        DAFs at the same time. Only one generic segment may be written */
/*        to a particular DAF at any given time, however. */

/*        For this example we assume that we have previously opened four */
/*        DAF files, having the handles HANDL1, HANDL2, HANDL3, HANDL4. */
/*        We will be writing fixed size data packets to the DAFs */
/*        associated with handles HANDL2 and HANDL3, with packet sizes of */
/*        21 and 53, respectively. We will be writing variable size data */
/*        packets to the DAFs associated with handles HANDL1 and HANDL4. */
/*        We will be writing individual data packets to the files */
/*        associated with handles HANDL2 and HANDL4, and one or more data */
/*        packets to the files associated with handles HANDL1 and HANDL3. */
/*        On each trip through the loop in the example below, we will add */
/*        data to any of the segments whose status flags are not set. We */
/*        are done with the loop below when we have finished each of the */
/*        segments, as indicated by its status flag. */

/*        For this example, we make no assumptions about the reference */
/*        values returned by the GET_*_* subroutines other than they are */
/*        increasing. Having no other information about the reference */
/*        values, we must use an explicit indexing method to store the */
/*        packets. */

/*                                . */
/*                                . */
/*                                . */
/*        C */
/*        C     First we begin a generic segment of the appropriate type */
/*        C     in each of the files. segment. To do this, we need: */
/*        C */
/*        C        HANDL1, HANDL2, HANDL3, HANDL4 -- */
/*        C */
/*        C           The handles of a DAFs opened with write access to */
/*        C           which we wish to add a new generic segment. */
/*        C */
/*        C        DESCR1, DESCR2, DESCR3, DESCR4  -- */
/*        C */
/*        C           The packed descriptors for the segments that */
/*        C           we want to create. */
/*        C */
/*        C        SEGID1, SEGID2, SEGID3, SEGID4 -- */
/*        C */
/*        C           A short character string that provides an */
/*        C           identifier for each of the segments we will be */
/*        C           creating. */
/*        C */
/*        C        NCON1, NCON2, NCON3, NCON4 -- */
/*        C */
/*        C           The number of constant values to be associated with */
/*        C           all of the packets in each the segments we will be */
/*        C           creating. */
/*        C */
/*        C */
/*        C        CONST1, CONST2, CONST3, CONST4 -- */
/*        C */
/*        C           An array of constant values to be associated with */
/*        C           all of the packets in each of the segments that we */
/*        C           are creating. */
/*        C */
/*        C        IDXT1, IDXT2, IDXT3, IDXT4 -- */
/*        C */
/*        C          The type of indexing scheme that we will use for */
/*        C          searching each of the segments to obtain a data */
/*        C          packet. In this example, each of the generic */
/*        C          segments will use an explicit index, which requires */
/*        C          a reference value for each data packet. When */
/*        C          searching for a data packet we will choose the */
/*        C          packet with a reference value closest to the */
/*        C          requested value. */
/*        C */
/*        C            IDXT1 = EXPCLS */
/*        C            IDXT2 = EXPCLS */
/*        C            IDXT3 = EXPCLS */
/*        C            IDXT4 = EXPCLS */
/*        C */
/*              CALL SGBWVS ( HANDL1, DESCR1, SEGID1, */
/*             .              NCON1,  CONST1, IDXT1   ) */
/*              CALL SGBWFS ( HANDL2, DESCR2, SEGID2, 21, */
/*             .              NCON2,  CONST2, IDXT2   ) */
/*              CALL SGBWFS ( HANDL3, DESCR3, SEGID3, 53, */
/*             .              NCON3,  CONST3, IDXT3   ) */
/*              CALL SGBWVS ( HANDL4, DESCR4, SEGID4, */
/*             .              NCON4,  CONST4, IDXT4   ) */
/*        C */
/*        C     We loop until done, obtaining data packets and writing */
/*        C     them to the generic segments in the appropriate DAFs. */
/*        C */
/*        C     We keep track of a status flag, DONE1, DONE2, DONE3, */
/*        C     DONE4, for each of the segments we are writing. When we */
/*        C     have finished writing all of the segments, we exit the */
/*        C     loop. */
/*        C */
/*              DONE  = .FALSE. */
/*              DONE1 = .FALSE. */
/*              DONE2 = .FALSE. */
/*              DONE3 = .FALSE. */
/*              DONE4 = .FALSE. */

/*              DO WHILE ( .NOT. DONE ) */
/*        C */
/*        C        Get data packets and reference values for HANDL1 and */
/*        C        write them to the generic segment in that file. */
/*        C */
/*                 IF ( .NOT. DONE1 ) THEN */
/*                    GET_VAR_PKTS ( NPKTS, PKTS, SIZES, REFS, DONE1 ) */

/*                    IF ( NPKTS .GT. 0 ) THEN */
/*                       CALL SGWVPK ( HANDL1, NPKTS, SIZES, */
/*             .                       PKTS,   NPKTS, REFS   ) */
/*                    END IF */
/*                 END IF */
/*        C */
/*        C        Get a data packet and reference value for HANDL2 and */
/*        C        write it to the generic segment in that file. */
/*        C */
/*                 IF ( .NOT. DONE2 ) THEN */
/*                    CALL GET_FIX_PKT ( PACKET, REF, DONE2 ) */

/*                    IF ( .NOT. DONE2 ) THEN */
/*                       CALL SGWFPK ( HANDL2, 1, PACKET, 1, REF ) */
/*                    END IF */
/*                 END IF */
/*        C */
/*        C        Get data packets and reference values for HANDL3 and */
/*        C        write them to the generic segment in that file. */
/*        C */
/*                 IF ( .NOT. DONE3 ) THEN */
/*                    CALL GET_FIX_PKTS ( NPKTS, PKTS, REFS, DONE3 ) */

/*                    IF ( NPKTS .GT. 0 ) THEN */
/*                       CALL SGWFPK ( HANDL3, NPKTS, PKTS, NPKTS, REFS ) */
/*                    END IF */
/*                 END IF */
/*        C */
/*        C        Get a data packet and reference value for HANDL4 and */
/*        C        write it to the generic segment in that file. */
/*        C */
/*                 IF ( .NOT. DONE4 ) THEN */
/*                    GET_VAR_PKT ( PACKET, SIZE, REF, DONE4 ) */

/*                    IF ( .NOT. DONE4 ) THEN */
/*                       CALL SGWVPK ( HANDL4, 1, SIZES, PKTS, 1, REFS ) */
/*                    END IF */
/*                 END IF */
/*        C */
/*        C        Set the DONE flag. */
/*        C */
/*                 DONE = DONE1 .AND. DONE2 .AND. DONE3 .AND. DONE4 */

/*              END DO */
/*        C */
/*        C     End the segments and move on to other things. */
/*        C */
/*              CALL SGWES ( HANDL1 ) */
/*              CALL SGWES ( HANDL2 ) */
/*              CALL SGWES ( HANDL3 ) */
/*              CALL SGWES ( HANDL4 ) */
/*                                . */
/*                                . */
/*                                . */

/* $ Restrictions */

/*     See the individual entry points for any restrictions thay may */
/*     have. */

/* $ Author_and_Institution */

/*     K.R. Gehringer    (JPL) */
/*     W.L. Taber        (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.2.0, 07-SEP-2001 (EDW) */

/*        Replaced DAFRDA calls with DAFGDA. */
/*        Removed DAFHLU calls; replaced ERRFN calls with ERRHAN. */

/* -    SPICELIB Version 1.1.0, 30-JUL-1996 (KRG) (NJB) */

/*        Fixed an annoying little bug in the variable segments code */
/*        when ending a segment. Rather than storing an appropriate */
/*        offset from the beginning of the segment as the packet */
/*        address in the packet directory, the absolute address, the */
/*        DAF address, was stored. This bug has been fixed. */

/*        See SGWES for the details of the changes. */

/* -    SPICELIB Version 1.0.0, 03-APR-1995 (KRG) (WLT) */

/* -& */
/* $ Index_Entries */

/*     generic segments sequential writer */

/* -& */

/*     SPICELIB Functions */


/*     Local parameters */

/*     FPRINT is the integer value of the first printable ASCII */
/*     character. */

/*     LPRINT is the integer value of the last printable ASCII character. */


/*     The number of reference values it takes to get a reference */
/*     directory value. */


/*     The length of a DAF internal filename. */


/*     The file table size. This needs to be the same as the file table */
/*     size in DAFAH. */


/*     Include the mnemonic values for the generic segment declarations */
/*     and the meta data information. */


/*     Local variables */

/*     Variables with the name DUMMY* are used as place holders when */
/*     calling various subroutines. Their values are not used in any of */
/*     the entry points of this subroutine. */


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


/*     File table declarations. The file table is used to keep track of */
/*     the vital statistics for each of the generic segments being */
/*     written. */


/*     Saved values. */


/*     Save the file table. */


/*     Initial values */

    /* Parameter adjustments */
    if (descr) {
	}
    if (const__) {
	}
    if (pktsiz) {
	}
    if (pktdat) {
	}
    if (refdat) {
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_sgbwfs;
	case 2: goto L_sgbwvs;
	case 3: goto L_sgwfpk;
	case 4: goto L_sgwvpk;
	case 5: goto L_sgwes;
	}


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }

/*     Signal an error if this routine is called directly. */

    chkin_(__global_state, "SGSEQW", (ftnlen)6);
    setmsg_(__global_state, "This routine should never be called directly. I"
	    "t exists as an umbrella routine to maintain all of the variables"
	    " for the generic segment sequential writing entry points.", (
	    ftnlen)168);
    sigerr_(__global_state, "SPICE(BOGUSENTRY)", (ftnlen)17);
    chkout_(__global_state, "SGSEQW", (ftnlen)6);
    return 0;
/* $Procedure SGBWFS ( Generic segements: Begin a fixed size segment. ) */

L_sgbwfs:
/* $ Abstract */

/*     Begin writing a generic segment that will contain fixed size data */
/*     packets. */

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

/*     DAF Required Reading. */

/* $ Keywords */

/*     GENERIC SEGMENTS */

/* $ Declarations */

/*     INTEGER               HANDLE */
/*     DOUBLE PRECISION      DESCR  ( * ) */
/*     CHARACTER*(*)         SEGID */
/*     INTEGER               NCONST */
/*     DOUBLE PRECISION      CONST  ( * ) */
/*     INTEGER               PKTSIZ */
/*     INTEGER               IDXTYP */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*      HANDLE    I    Handle of a DAF file opened with write access. */
/*      DESCR     I    Descriptor for a generic segment. */
/*      SEGID     I    Identifier for a generic segment. */
/*      NCONST    I    Number of constant values in a generic segment. */
/*      CONST     I    Array of constant values for a generic segment. */
/*      PKTSIZ    I    Size of the data packets. */
/*      IDXTYP    I    Index type for the reference values. */

/* $ Detailed_Input */

/*      HANDLE   Handle of a DAF file opened with write access. This is */
/*               the handle of the file in which a generic segment will */
/*               be written. */

/*      DESCR    Descriptor for a segment that is being written. This is */
/*               the packed form of the DAF double precision and integer */
/*               summaries which contain ND double precision numbers and */
/*               NI integers. */

/*      SEGID    Identifier for a segment that is being written. This is */
/*               a character string containing at most NC printing ASCII */
/*               characters where */

/*                                 /  ND + ( NI + 1 )  \ */
/*                      NC =  8 *  | ----------------- | */
/*                                 \         2         / */

/*                SEGID may be blank. */

/*      NCONST   The number of constant values to be placed in a segment. */

/*      CONST    An array of NCONST constant values for a segment. */

/*      PKTSIZ   Size of fixed size packets. The size of a packet */
/*               is the number of double precision numbers contained in */
/*               the data packet. */

/*      IDXTYP   Index type to use for the reference values. */

/*               Two forms of indexing are provided: */

/*                  1) An implicit form of indexing based on using two */
/*                     values, a starting value, which will have an index */
/*                     of 1, and a step size between reference values, */
/*                     which are used to compute an index and a reference */
/*                     value associated with a specified key value. See */
/*                     the descriptions of the implicit types below for */
/*                     the particular formula used in each case. */

/*                  2) An explicit form of indexing based on a reference */
/*                     value for each data packet. */

/*               See the chapter on generic segments in the DAF required */
/*               or the include file 'sgparam.inc' for more details */
/*               about the index types that are available. */


/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     This subroutine makes use of parameters defined in the file */
/*     'sgparam.inc'. */

/* $ Exceptions */

/*     1) If this routine is called more than once for a particular file */
/*        and segment, the error SPICE(CALLEDOUTOFORDER) will be */
/*        signalled. */

/*     2) If the length of the segment identifier, SEGID, is greater than */
/*        NC, as determined from the ND and NI values for a particular */
/*        DAF file, the error SPICE(SEGIDTOOLONG) will be signalled. */

/*     3) If the segment identifier contains nonprinting characters, the */
/*        error SPICE(NONPRINTINGCHARS) will be signalled. */

/*     4) If the number of constant values, NCONST, is negative, the */
/*        error SPICE(NUMCONSTANTSNEG) will be signalled. */

/*     5) If the packet size, PKTSIZ, is not positive, the error */
/*        SPICE(NONPOSPACKETSIZE) will be signalled. */

/*     6) If the index type for the reference values is not recognized, */
/*        the error SPICE(UNKNOWNINDEXTYPE) will be signalled. */

/*     7) If the file table is full, the error SPICE(FILETABLEFULL) will */
/*        be signalled. */

/* $ Files */

/*     See HANDLE in the $ Detailed_Input section. */

/* $ Particulars */

/*     Begin writing a generic segment for fixed size data packets to */
/*     the DAF file associated with HANDLE. */

/* $ Examples */

/*     See the $ Examples section in the header for the main subroutine. */
/*     It contains examples wich demonstrate the use of the entry points */
/*     in the generic segments sequential writer. The entry points which */
/*     comprise the generic segments sequential writer must be used */
/*     together in the proper manner. Rather than repeating the examples */
/*     for each entry point they are provided in a single location. */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     K.R. Gehringer    (JPL) */
/*     W.L. Taber        (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 05-APR-1995 (KRG) (WLT) */


/* -& */
/* $ Index_Entries */

/*     begin writing a fixed packet size generic segment */

/* -& */

/*     SPICELIB functions */

/*     INTEGER               LASTNB */
/*     INTEGER               ISRCHI */

/*     LOGICAL               FAILED */
/*     LOGICAL               RETURN */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "SGBWFS", (ftnlen)6);

/*     We need to do some sanity checks on our input arguments before we */
/*     should attempt to write anything to the file. So, let's start with */
/*     that. */

/*     Check to see if the file attached to the handle is open for */
/*     writing. If not, an error is signalled. */

    dafsih_(__global_state, handle, "WRITE", (ftnlen)5);
    if (failed_(__global_state)) {
	chkout_(__global_state, "SGBWFS", (ftnlen)6);
	return 0;
    }

/*     Check to see if the handle is currently in the file table. If it */
/*     is, we've got a problem. This routine may only be called once for */
/*     each segment that is to contain fixed size packets, and it places */
/*     a handle in the file table. If the handle is currently in the */
/*     file table a segment has already been started by this routine or */
/*     SGBWVS. In either case, we cannot continue, so we signal an error. */

    if (__state->nft > 0) {
	__state->index = isrchi_(__global_state, handle, &__state->nft, 
		__state->fthan);
	if (__state->index != 0) {
	    setmsg_(__global_state, "A segment is already being written to t"
		    "he file '#'. A new segment cannot be started for this fi"
		    "le until the current segment is finished. ", (ftnlen)137);
	    errhan_(__global_state, "#", handle, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(CALLEDOUTOFORDER)", (ftnlen)23);
	    chkout_(__global_state, "SGBWFS", (ftnlen)6);
	    return 0;
	}
    }

/*     Get the ND and NI values from the DAF file. We need these to know */
/*     the size of the descriptor and the length of the segment ID. The */
/*     length of the segment ID is determined by the following formula */
/*     using integer division: */

/*                                 /  ND + ( NI + 1 )  \ */
/*                      NC =  8 *  | ----------------- | */
/*                                 \         2         / */

    dafhsf_(__global_state, handle, &nd, &ni);
    if (failed_(__global_state)) {
	chkout_(__global_state, "SGBWFS", (ftnlen)6);
	return 0;
    }
    nc = nd + (ni + 1) / 2 << 3;

/*     Get the length of the segment ID. Leading blanks are considered to */
/*     be important. A blank segment ID is OK too. */

    sidlen = lastnb_(__global_state, segid, segid_len);

/*     Check the segment ID to see if it is OK. Its length must be less */
/*     than NC and it must consist of only printing ASCII characters. */

    if (sidlen > nc) {
	setmsg_(__global_state, "Segment identifier contains more than # cha"
		"racters.", (ftnlen)51);
	errint_(__global_state, "#", &nc, (ftnlen)1);
	sigerr_(__global_state, "SPICE(SEGIDTOOLONG)", (ftnlen)19);
	chkout_(__global_state, "SGBWFS", (ftnlen)6);
	return 0;
    }
    i__1 = sidlen;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ich = *(unsigned char *)&segid[i__ - 1];
	if (ich < 32 || ich > 126) {
	    setmsg_(__global_state, "The segment identifier contains  a nonp"
		    "rinting character at location #.", (ftnlen)71);
	    errint_(__global_state, "#", &i__, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(NONPRINTINGCHARS)", (ftnlen)23);
	    chkout_(__global_state, "SGBWFS", (ftnlen)6);
	    return 0;
	}
    }

/*     Check to see if the number of constants is negative. This is all */
/*     we can do here, we cannot check the constant values. */

    if (*nconst < 0) {
	setmsg_(__global_state, "The number of constants specified was #. Th"
		"is number must be non-negative. Perhaps the variable was not"
		" properlyinitialized. ", (ftnlen)125);
	errint_(__global_state, "#", nconst, (ftnlen)1);
	sigerr_(__global_state, "SPICE(NUMCONSTANTSNEG) ", (ftnlen)23);
	chkout_(__global_state, "SGBWFS", (ftnlen)6);
	return 0;
    }

/*     Check to see that the packet size is OK. It should be positive. */

    if (pktsiz[0] <= 0) {
	setmsg_(__global_state, "The size of the data packets must be positi"
		"ve. It was specified as #. Perhaps the input variable was no"
		"t properly initialized. ", (ftnlen)127);
	errint_(__global_state, "#", pktsiz, (ftnlen)1);
	sigerr_(__global_state, "SPICE(NONPOSPACKETSIZE)", (ftnlen)23);
	chkout_(__global_state, "SGBWFS", (ftnlen)6);
	return 0;
    }

/*     Check to see if the index type is one that we recognize. */

    if (*idxtyp < 0 || *idxtyp > 4) {
	setmsg_(__global_state, "The index type specified was #.  This is no"
		"t a valid index type. Valid types are in the range from # to"
		" #.", (ftnlen)106);
	errint_(__global_state, "#", idxtyp, (ftnlen)1);
	errint_(__global_state, "#", &__state->c__0, (ftnlen)1);
	errint_(__global_state, "#", &__state->c__4, (ftnlen)1);
	sigerr_(__global_state, "SPICE(UNKNOWNINDEXTYPE)", (ftnlen)23);
	chkout_(__global_state, "SGBWFS", (ftnlen)6);
	return 0;
    }

/*     Check to see whether we still have room in the file table. */

    if (__state->nft == 20) {
	setmsg_(__global_state, "There are already # files being written by "
		"generic segment writing routines. No more files may be writt"
		"en by the generic segment writers until one of those current"
		"ly being written is closed via a call to SGWES.", (ftnlen)210)
		;
	errint_(__global_state, "#", &__state->nft, (ftnlen)1);
	sigerr_(__global_state, "SPICE(FILETABLEFULL)", (ftnlen)20);
	chkout_(__global_state, "SGBWFS", (ftnlen)6);
	return 0;
    }

/*     Set the flag which indicate whether this index type is an */
/*     explicit type or an implicit type. */

    __state->explct = *idxtyp == 2 || *idxtyp == 3 || *idxtyp == 4;

/*     At this point, we know that the input data is OK, in so far as we */
/*     can validate it, and we have room in the file table. So we proceed */
/*     with starting a segment for fixed size packets. */

/*     Set the flag that indicate that this segment is a fixed size */
/*     segment. */

    __state->fxdseg = TRUE_;

/*     Get the address for the beginning of the array that we are going */
/*     to create. We have to get this by reading the file record. */

    dafrfr_(__global_state, handle, &nd, &ni, dummy1, &dummy2, &dummy3, &
	    begadr, (ftnlen)60);

/*     Begin a new segment in the DAF file. */

    dafbna_(__global_state, handle, descr, segid, segid_len);
    if (failed_(__global_state)) {
	chkout_(__global_state, "SGBWFS", (ftnlen)6);
	return 0;
    }

/*     Write out the constants to the new segment, if there are any */
/*     constants. */

    if (*nconst > 0) {
	dafada_(__global_state, const__, nconst);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "SGBWFS", (ftnlen)6);
	    return 0;
	}
    }

/*     Store the information for this file and segment in the file table. */

    ++__state->nft;
    __state->ftityp[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftityp", i__1, "sgseqw_", (ftnlen)
	    1781)] = *idxtyp;
    __state->ftpksz[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftpksz", i__1, "sgseqw_", (ftnlen)
	    1782)] = pktsiz[0];
    __state->ftmxsz[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftmxsz", i__1, "sgseqw_", (ftnlen)
	    1783)] = 0;
    __state->ftncon[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftncon", i__1, "sgseqw_", (ftnlen)
	    1785)] = *nconst;
    __state->ftnpkt[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftnpkt", i__1, "sgseqw_", (ftnlen)
	    1786)] = 0;
    __state->ftnref[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftnref", i__1, "sgseqw_", (ftnlen)
	    1787)] = 0;
    __state->ftnres[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftnres", i__1, "sgseqw_", (ftnlen)
	    1788)] = 0;
    __state->ftexpl[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftexpl", i__1, "sgseqw_", (ftnlen)
	    1790)] = __state->explct;
    __state->ftfixd[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftfixd", i__1, "sgseqw_", (ftnlen)
	    1792)] = __state->fxdseg;
    __state->fthan[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "fthan", i__1, "sgseqw_", (ftnlen)
	    1794)] = *handle;
    __state->ftbadr[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftbadr", i__1, "sgseqw_", (ftnlen)
	    1795)] = begadr;
    __state->ftrefs[(i__1 = (__state->nft << 1) - 2) < 40 && 0 <= i__1 ? i__1 
	    : s_rnge(&__global_state->f2c, "ftrefs", i__1, "sgseqw_", (ftnlen)
	    1797)] = 0.;
    __state->ftrefs[(i__1 = (__state->nft << 1) - 1) < 40 && 0 <= i__1 ? i__1 
	    : s_rnge(&__global_state->f2c, "ftrefs", i__1, "sgseqw_", (ftnlen)
	    1798)] = 0.;
    if (__state->explct) {
	__state->ftoff[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "ftoff", i__1, "sgseqw_", (
		ftnlen)1801)] = 1;
    } else {
	__state->ftoff[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "ftoff", i__1, "sgseqw_", (
		ftnlen)1803)] = 0;
    }
    __state->lsthan = *handle;
    __state->index = __state->nft;
    ++__state->numfxd;
    chkout_(__global_state, "SGBWFS", (ftnlen)6);
    return 0;
/* $Procedure SGBWVS ( Generic segements: Begin a variable size segment. ) */

L_sgbwvs:
/* $ Abstract */

/*     Begin writing a generic segment that will contain variable size */
/*     data packets. */

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

/*     DAF Required Reading. */

/* $ Keywords */

/*     GENERIC SEGMENTS */

/* $ Declarations */

/*     INTEGER               HANDLE */
/*     DOUBLE PRECISION      DESCR  ( * ) */
/*     CHARACTER*(*)         SEGID */
/*     INTEGER               NCONST */
/*     DOUBLE PRECISION      CONST  ( * ) */
/*     INTEGER               IDXTYP */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*      HANDLE    I    Handle of a DAF file opened with write access. */
/*      DESCR     I    Descriptor for a segment. */
/*      SEGID     I    Identifier for a segment. */
/*      NCONST    I    Number of constant values in a segment. */
/*      CONST     I    Array of constant values for a segment. */
/*      IDXTYP    I    Index type for the reference values. */

/* $ Detailed_Input */

/*      HANDLE   Handle of a DAF file opened with write access. This is */
/*               the handle of the file in which a generic segment will */
/*               be written. */

/*      DESCR    Descriptor for a segment that is being written. This is */
/*               the packed form of the DAF double precision and integer */
/*               summaries which contain ND double precision numbers and */
/*               NI integers. */

/*      SEGID    Identifier for a segment that is being written. This is */
/*               a character string containing at most NC printing ASCII */
/*               characters where */

/*                                 /  ND + ( NI + 1 )  \ */
/*                      NC =  8 *  | ----------------- | */
/*                                 \         2         / */

/*                SEGID may be blank. */

/*      NCONST   The number of constant values to be placed in a segment. */

/*      CONST    An array of NCONST constant values for a segment. */

/*      IDXTYP   Index type to use for the reference values. */

/*               Two forms of indexing are provided: */

/*                  1) An implicit form of indexing based on using two */
/*                     values, a starting value, which will have an index */
/*                     of 1, and a step size between reference values, */
/*                     which are used to compute an index and a reference */
/*                     value associated with a specified key value. See */
/*                     the descriptions of the implicit types below for */
/*                     the particular formula used in each case. */

/*                  2) An explicit form of indexing based on a reference */
/*                     value for each data packet. */

/*               See the chapter on generic segments in the DAF required */
/*               or the include file 'sgparam.inc' for more details */
/*               about the index types that are available. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     This subroutine makes use of parameters defined in the file */
/*     'sgparam.inc'. */

/* $ Exceptions */

/*     1) If this routine is called more than once for a particular file */
/*        and segment, the error SPICE(CALLEDOUTOFORDER) will be */
/*        signalled. */

/*     2) If the length of the segment identifier, SEGID, is greater than */
/*        NC, as determined from the ND and NI values for a particular */
/*        DAF file, the error SPICE(SEGIDTOOLONG) will be signalled. */

/*     3) If the segment identifier contains nonprinting characters, the */
/*        error SPICE(NONPRINTINGCHARS) will be signalled. */

/*     4) If the number of constant values, NCONST, is negative, the */
/*        error SPICE(NUMCONSTANTSNEG) will be signalled. */

/*     5) If the index type for the reference values is not recognized, */
/*        the error SPICE(UNKNOWNINDEXTYPE) will be signalled. */

/*     6) If the file table is full, the error SPICE(FILETABLEFULL) will */
/*        be signalled. */

/* $ Files */

/*     See HANDLE in the $ Detailed_Input section. */

/* $ Particulars */

/*     Begin writing a generic segment for variable size data packets to */
/*     the DAF file associated with HANDLE. */

/* $ Examples */

/*     See the $ Examples section in the header for the main subroutine. */
/*     It contains examples wich demonstrate the use of the entry points */
/*     in the generic segments sequential writer. The entry points which */
/*     comprise the generic segments sequential writer must be used */
/*     together in the proper manner. Rather than repeating the examples */
/*     for each entry point they are provided in a single location. */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     K.R. Gehringer    (JPL) */
/*     W.L. Taber        (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 05-APR-1995 (KRG) (WLT) */


/* -& */
/* $ Index_Entries */

/*     begin writing a variable packet size generic segment */

/* -& */

/*     SPICELIB functions */

/*     INTEGER               LASTNB */
/*     INTEGER               ISRCHI */

/*     LOGICAL               FAILED */
/*     LOGICAL               RETURN */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "SGBWVS", (ftnlen)6);

/*     We need to do some sanity checks on our input arguments before we */
/*     should attempt to write anything to the file. So, let's start with */
/*     that. */

/*     Check to see if the file attached to the handle is open for */
/*     writing. If not, an error is signalled. */

    dafsih_(__global_state, handle, "WRITE", (ftnlen)5);
    if (failed_(__global_state)) {
	chkout_(__global_state, "SGBWVS", (ftnlen)6);
	return 0;
    }

/*     Check to see if the handle is currently in the file table. If it */
/*     is, we've got a problem. This routine may only be called once for */
/*     each segment that is to contain variable size packets, and it */
/*     places a handle into the file table. If the handle is currently in */
/*     the file table a segment has already been started by this routine */
/*     or SGBWFS. In either case, we cannot continue, so we signal an */
/*     error. */

    if (__state->nft > 0) {
	__state->index = isrchi_(__global_state, handle, &__state->nft, 
		__state->fthan);
	if (__state->index != 0) {
	    setmsg_(__global_state, "A segment is already being written to t"
		    "he file '#'. A new segment cannot be started for this fi"
		    "le until the current segment is finished. ", (ftnlen)137);
	    errhan_(__global_state, "#", handle, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(CALLEDOUTOFORDER)", (ftnlen)23);
	    chkout_(__global_state, "SGBWVS", (ftnlen)6);
	    return 0;
	}
    }

/*     Get the ND and NI values from the DAF file. We need these to know */
/*     the size of the descriptor and the length of the segment ID. The */
/*     length of the segment ID is determined by the following formula */
/*     using integer division: */

/*                                 /  ND + ( NI + 1 )  \ */
/*                      NC =  8 *  | ----------------- | */
/*                                 \         2         / */

    dafhsf_(__global_state, handle, &nd, &ni);
    if (failed_(__global_state)) {
	chkout_(__global_state, "SGBWVS", (ftnlen)6);
	return 0;
    }
    nc = nd + (ni + 1) / 2 << 3;

/*     Get the length of the segment ID. Leading blanks are considered to */
/*     be important. A blank segment ID is OK too. */

    sidlen = lastnb_(__global_state, segid, segid_len);

/*     Check the segment ID to see if it is OK. Its length must be less */
/*     than NC and it must consist of only printing ASCII characters. */

    if (sidlen > nc) {
	setmsg_(__global_state, "Segment identifier contains more than # cha"
		"racters.", (ftnlen)51);
	errint_(__global_state, "#", &nc, (ftnlen)1);
	sigerr_(__global_state, "SPICE(SEGIDTOOLONG)", (ftnlen)19);
	chkout_(__global_state, "SGBWVS", (ftnlen)6);
	return 0;
    }
    i__1 = sidlen;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ich = *(unsigned char *)&segid[i__ - 1];
	if (ich < 32 || ich > 126) {
	    setmsg_(__global_state, "The segment identifier contains  a nonp"
		    "rinting character at location #.", (ftnlen)71);
	    errint_(__global_state, "#", &i__, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(NONPRINTINGCHARS)", (ftnlen)23);
	    chkout_(__global_state, "SGBWVS", (ftnlen)6);
	    return 0;
	}
    }

/*     Check to see if the number of constants is negative. This is all */
/*     we can do here, we cannot check the constant values. */

    if (*nconst < 0) {
	setmsg_(__global_state, "The number of constants specified was #. Th"
		"is number must be non-negative. Perhaps the variable was not"
		" initialized. ", (ftnlen)117);
	errint_(__global_state, "#", nconst, (ftnlen)1);
	sigerr_(__global_state, "SPICE(NUMCONSTANTSNEG) ", (ftnlen)23);
	chkout_(__global_state, "SGBWVS", (ftnlen)6);
	return 0;
    }

/*     Check to see if the index type is one that we recognize. */

    if (*idxtyp < 0 || *idxtyp > 4) {
	setmsg_(__global_state, "The index type specified was #.  This is no"
		"t a valid index type. Valid types are in the range from # to"
		" #.", (ftnlen)106);
	errint_(__global_state, "#", idxtyp, (ftnlen)1);
	errint_(__global_state, "#", &__state->c__0, (ftnlen)1);
	errint_(__global_state, "#", &__state->c__4, (ftnlen)1);
	sigerr_(__global_state, "SPICE(UNKNOWNINDEXTYPE)", (ftnlen)23);
	chkout_(__global_state, "SGBWVS", (ftnlen)6);
	return 0;
    }

/*     Check to see if there is room in the file table. */

    if (__state->nft == 20) {
	setmsg_(__global_state, "There are already # files being written by "
		"generic segment writing routines. No more files may be writt"
		"en by the generic segment writers until one of those current"
		"ly being written is closed via a call to SGWES. ", (ftnlen)
		211);
	errint_(__global_state, "#", &__state->nft, (ftnlen)1);
	sigerr_(__global_state, "SPICE(FILETABLEFULL)", (ftnlen)20);
	chkout_(__global_state, "SGBWVS", (ftnlen)6);
	return 0;
    }

/*     Set the flag which indicate whether this index type is an */
/*     explicit type or an implicit type. */

    __state->explct = *idxtyp == 2 || *idxtyp == 3 || *idxtyp == 4;

/*     At this point, we know that the input data is OK, in so far as we */
/*     can validate it and that there is room in the file table. So we */
/*     proceed with starting a segment for fixed size packets. */

/*     Set the flag that indicate that this segment is a variable size */
/*     segment. */

    __state->fxdseg = FALSE_;

/*     Get the address for the beginning of the array that we are going */
/*     to create. We have to get this by reading the file record. */

    dafrfr_(__global_state, handle, &nd, &ni, dummy1, &dummy2, &dummy3, &
	    begadr, (ftnlen)60);

/*     Begin a new segment in the DAF file. */

    dafbna_(__global_state, handle, descr, segid, segid_len);
    if (failed_(__global_state)) {
	chkout_(__global_state, "SGBWVS", (ftnlen)6);
	return 0;
    }

/*     Write out the constants to the new segment, if there are any */
/*     constants. */

    if (*nconst > 0) {
	dafada_(__global_state, const__, nconst);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "SGBWVS", (ftnlen)6);
	    return 0;
	}
    }

/*     Save the information for this file and segment in the file table. */

    ++__state->nft;
    __state->ftityp[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftityp", i__1, "sgseqw_", (ftnlen)
	    2209)] = *idxtyp;
    __state->ftpksz[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftpksz", i__1, "sgseqw_", (ftnlen)
	    2210)] = 0;
    __state->ftmxsz[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftmxsz", i__1, "sgseqw_", (ftnlen)
	    2211)] = 0;
    __state->ftncon[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftncon", i__1, "sgseqw_", (ftnlen)
	    2213)] = *nconst;
    __state->ftnpkt[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftnpkt", i__1, "sgseqw_", (ftnlen)
	    2214)] = 0;
    __state->ftnref[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftnref", i__1, "sgseqw_", (ftnlen)
	    2215)] = 0;
    __state->ftnres[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftnres", i__1, "sgseqw_", (ftnlen)
	    2216)] = 0;
    __state->ftexpl[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftexpl", i__1, "sgseqw_", (ftnlen)
	    2218)] = __state->explct;
    __state->ftfixd[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftfixd", i__1, "sgseqw_", (ftnlen)
	    2220)] = __state->fxdseg;
    __state->fthan[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "fthan", i__1, "sgseqw_", (ftnlen)
	    2222)] = *handle;
    __state->ftbadr[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
	    s_rnge(&__global_state->f2c, "ftbadr", i__1, "sgseqw_", (ftnlen)
	    2223)] = begadr;
    __state->ftrefs[(i__1 = (__state->nft << 1) - 2) < 40 && 0 <= i__1 ? i__1 
	    : s_rnge(&__global_state->f2c, "ftrefs", i__1, "sgseqw_", (ftnlen)
	    2225)] = 0.;
    __state->ftrefs[(i__1 = (__state->nft << 1) - 1) < 40 && 0 <= i__1 ? i__1 
	    : s_rnge(&__global_state->f2c, "ftrefs", i__1, "sgseqw_", (ftnlen)
	    2226)] = 0.;
    if (__state->explct) {
	__state->ftoff[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "ftoff", i__1, "sgseqw_", (
		ftnlen)2229)] = 2;
    } else {
	__state->ftoff[(i__1 = __state->nft - 1) < 20 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "ftoff", i__1, "sgseqw_", (
		ftnlen)2231)] = 1;
    }
    __state->lsthan = *handle;
    __state->index = __state->nft;
    ++__state->numvar;
    chkout_(__global_state, "SGBWVS", (ftnlen)6);
    return 0;
/* $Procedure SGWFPK ( Generic segements: Write fixed size packets. ) */

L_sgwfpk:
/* $ Abstract */

/*     Write one or more fixed size data packets to the generic segment */
/*     currently being written to the DAF file associated with HANDLE. */

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

/*     DAF Required Reading. */

/* $ Keywords */

/*     GENERIC SEGMENTS */

/* $ Declarations */

/*     INTEGER               HANDLE */
/*     INTEGER               NPKTS */
/*     DOUBLE PRECISION      PKTDAT ( * ) */
/*     INTEGER               NREFS */
/*     DOUBLE PRECISION      REFDAT ( * ) */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*      HANDLE    I    Handle of a DAF file opened with write access. */
/*      NPKTS     I    Number of data packets to write to a segment. */
/*      PKTDAT    I    Array of packet data. */
/*      NREFS     I    Number of reference values. */
/*      REFDAT    I    Reference data. */

/* $ Detailed_Input */

/*      HANDLE   Handle of a DAF file opened with write access. This is */
/*               the handle of a file in which a generic segment has */
/*               been started and is currently being written. */

/*      NPKTS    Number of data packets to write to a segment. */

/*      PKTDAT   A singly dimensioned array containing the fixed size */
/*               data packets to be added to the segment associated with */
/*               HANDLE. */

/*               For fixed size data packets, PKTDAT will have the */
/*               following structure: */

/*               Packet #  Range of Locations */
/*               --------  --------------------------------------------- */

/*                     1   PKTDAT(1)              to PKTDAT(PS) */
/*                     2   PKTDAT(PS+1)           to PKTDAT(2*PS) */
/*                     3   PKTDAT(2*PS+1)         to PKTDAT(3*PS) */
/*                     4   PKTDAT(3*PS+1)         to PKTDAT(4*PS) */

/*                                          . */
/*                                          . */
/*                                          . */

/*                 NPKTS   PKTDAT((NPKTS-1)*PS+1) to PKTDAT(NPKTS*PS) */

/*               where PS = PKTSIZ. */

/*      NREFS    Number of reference values. */

/*               For implicitly indexed packets, NREFS must have a value */
/*               of two (2). */

/*               When writing packets to a segment which uses an implicit */
/*               index type, the value specified by NREFS is used only on */
/*               the first call to SGWFPK. On all subsequent calls to */
/*               these subroutines for a particular implicitly indexed */
/*               segment, the value of NREFS is ignored. */

/*               For explicitly indexed packets, NREFS must be equal to */
/*               NPKTS, i.e., there should ba a reference value for each */
/*               data packet being written to the segment. */

/*               When writing packets to a segment which uses an explicit */
/*               index type, the value specified by NREFS is used on */
/*               every call to SGWFPK and it must be equal to NPKTS. */

/*      REFDAT   Reference data values. */

/*               For implicitly indexed packets, there must be two (2) */
/*               values. The reference values represent a starting */
/*               reference value and a stepsize between consecutive */
/*               reference values, respectively. */

/*               In order to avoid, or at least minimize, numerical */
/*               difficulties associated with computing index values for */
/*               generic segments with implicit index types, the value of */
/*               the stepsize must be an integer, i.e., DINT(REFDAT(2)) */
/*               must equal REFDAT(2). */

/*               When writing packets to a segment which uses an implicit */
/*               index type, the values specified by REFDAT are used only */
/*               on the first call to SGWFPK. On all subsequent calls to */
/*               this subroutine for a particular implicitly indexed */
/*               segment, REFDAT is ignored. */

/*               For explicitly indexed packets, there must be NPKTS */
/*               referencevalues and the values must be in increasing */
/*               order: */

/*                  REFDAT(I) < REFDAT(I+1), I = 1, NPKTS-1 */

/*               When writing packets to a segment which uses an explicit */
/*               index type, the values specified by REFDAT are used on */
/*               every call to SGWFPK. On all calls to these subroutines */
/*               after the first, the value of REFDAT(1) must be greater */
/*               than than the value of REFDAT(NPKTS) from the previous */
/*               call. This preserves the ordering of the reference */
/*               values for the entire segment. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     This subroutine makes use of parameters defined in the file */
/*     'sgparam.inc'. */

/* $ Exceptions */

/*     1) If there are no generic segments with fixed packet sizes */
/*        currently being written, the error SPICE(CALLEDOUTOFORDER) will */
/*        be signalled. */

/*     2) If there is not a generic segment with fixed packet size being */
/*        written to the file associated with HANDLE, the error */
/*        SPICE(SEGMENTNOTFOUND) will be signalled. */

/*     3) If the type of generic segment being written to this file is */
/*        not a fixed packet size generic segment, the error */
/*        SPICE(SEGTYPECONFLICT) will be signalled. */

/*     4) If the number of packets to be written to the generic segment */
/*        is not positive, the error SPICE(NUMPACKETSNOTPOS) will be */
/*        signalled. */

/*     5) If an explicitly indexed generic segment is being written and */
/*        the number of reference values, NREFS, is not equal to the */
/*        number of data packets being written, NPKTS, the error */
/*        SPICE(INCOMPATIBLENUMREF) will be signalled. */

/*     6) If an explicitly indexed generic segment is being written and */
/*        the reference values are not in increasing order, the error */
/*        SPICE(UNORDEREDREFS) will be signalled. */

/*     7) If an explicitly indexed generic segment is being written and */
/*        the first reference value on the second or later additions */
/*        of packets to the generic segment is not greater than the last */
/*        reference value from the previous addition of packets, the */
/*        error SPICE(UNORDEREDREFS) will be signalled. */

/*     8) If an implicitly indexed generic segment is being written and */
/*        the number of reference values, NREFS, is not equal to two (2) */
/*        on the first call to this subroutine for a particular segment, */
/*        then the error SPICE(INCOMPATIBLENUMREF) will be signalled. */

/*     9) If an implicitly indexed generic segment is being written and */
/*        the second reference value, the step size used for indexing, is */
/*        not integral, i.e., DINT(REFDAT(2)) .NE. REFDAT(2), the error */
/*        SPICE(REFVALNOTINTEGER) will be signalled. */

/* $ Files */

/*     See HANDLE in the $ Detailed_Input section. */

/* $ Particulars */

/*     This routine will write one or more fixed size data packets to a */
/*     generic segment in the DAF file associated with HANDLE. The */
/*     generic segment must have been started by a call to SGBWFS. */

/* $ Examples */

/*     See the $ Examples section in the header for the main subroutine. */
/*     It contains examples wich demonstrate the use of the entry points */
/*     in the generic segments sequential writer. The entry points which */
/*     comprise the generic segments sequential writer must be used */
/*     together in the proper manner. Rather than repeating the examples */
/*     for each entry point they are provided in a single location. */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     K.R. Gehringer    (JPL) */
/*     W.L. Taber        (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 05-APR-1995 (KRG) (WLT) */


/* -& */
/* $ Index_Entries */

/*     write fixed size packets to a generic segment */

/* -& */

/*     SPICELIB functions */

/*     INTEGER               LASTNB */
/*     INTEGER               ISRCHI */

/*     LOGICAL               FAILED */
/*     LOGICAL               RETURN */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "SGWFPK", (ftnlen)6);

/*     Check to see if this is the first time here. If it is, we have */
/*     been called out of order, so signal an error. */

    if (__state->numfxd == 0) {
	setmsg_(__global_state, "No segment with fixed size packets is curre"
		"ntly being written. This routine has been called out of orde"
		"r. The routine SGBWFS must be called before his routine may "
		"be called.", (ftnlen)173);
	sigerr_(__global_state, "SPICE(CALLEDOUTOFORDER)", (ftnlen)23);
	chkout_(__global_state, "SGWFPK", (ftnlen)6);
	return 0;
    }

/*     Check to see if the last handle used is the same as the current */
/*     handle. This saves us a table lookup to get the appropriate index */
/*     into the file table to restore the information for that handle. */

    if (*handle != __state->lsthan) {
	__state->index = isrchi_(__global_state, handle, &__state->nft, 
		__state->fthan);
	if (__state->index == 0) {
	    setmsg_(__global_state, "No segment with fixed size packets is a"
		    "ssociated with the file '#'. In order to write fixed siz"
		    "e packets to a file the routine SGBWFS must be called to"
		    " begin the segment.", (ftnlen)170);
	    errhan_(__global_state, "#", handle, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(SEGMENTNOTFOUND)", (ftnlen)22);
	    chkout_(__global_state, "SGWFPK", (ftnlen)6);
	    return 0;
	}
	__state->explct = __state->ftexpl[(i__1 = __state->index - 1) < 20 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftexpl", 
		i__1, "sgseqw_", (ftnlen)2539)];
	__state->fxdseg = __state->ftfixd[(i__1 = __state->index - 1) < 20 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftfixd", 
		i__1, "sgseqw_", (ftnlen)2540)];
	__state->lsthan = *handle;
	dafcad_(__global_state, handle);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "SGWFPK", (ftnlen)6);
	    return 0;
	}
    }

/*     Check to see if the segment being written is a fixed size packet */
/*     segment or a variable size packet segment. If the latter, then */
/*     this is the wrong routine. */

    if (! __state->fxdseg) {
	setmsg_(__global_state, "The segment being written to the file  '#' "
		"is a variable packet size segment, not a fixed packet size s"
		"egment.  The routine SGWVPK may be used to write variable si"
		"ze packets.", (ftnlen)174);
	errhan_(__global_state, "#", handle, (ftnlen)1);
	sigerr_(__global_state, "SPICE(SEGTYPECONFLICT)", (ftnlen)22);
	chkout_(__global_state, "SGWFPK", (ftnlen)6);
	return 0;
    }

/*     At this point, we have a good file handle, an index into the file */
/*     table, and we know that we are working with a fixed packet size */
/*     segment. So, what we need to do now is verify the input arguments. */

/*     Check the number of packets to be sure that it is positive. */

    if (*npkts <= 0) {
	setmsg_(__global_state, "The number of packets to store is not posit"
		"ive.  The value supplied was #. Perhaps this packet count wa"
		"s unitialized.", (ftnlen)117);
	errint_(__global_state, "#", npkts, (ftnlen)1);
	sigerr_(__global_state, "SPICE(NUMPACKETSNOTPOS)", (ftnlen)23);
	chkout_(__global_state, "SGWFPK", (ftnlen)6);
	return 0;
    }

/*     Now we get to some of the more interesting bits. We now need to */
/*     differentiate between the explicitly indexed types and the */
/*     implicitly indexed types, because they have different */
/*     characteristics and assumptions about how they are stored. */

    if (__state->explct) {

/*        For explicitly indexed packets the number of reference values */
/*        must be equal to the number of packets. The references must */
/*        also be in increasing order. */

	if (*nrefs != *npkts) {
	    setmsg_(__global_state, "The number of reference values supplied"
		    ", #, is not compatible with explicitly indexed packets. "
		    "Explicitly indexed packets require the number of referen"
		    "ce values to equal the number of packets, in this case, "
		    "#.", (ftnlen)209);
	    errint_(__global_state, "#", nrefs, (ftnlen)1);
	    errint_(__global_state, "#", npkts, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(INCOMPATIBLENUMREF)", (ftnlen)25);
	    chkout_(__global_state, "SGWFPK", (ftnlen)6);
	    return 0;
	}

/*        If this is not the first time we have asdded data to this */
/*        segment, we need to be sure that all of the current reference */
/*        values are greater then the last reference value from the */
/*        previous addition of packets to the segment. */

	if (__state->ftnpkt[(i__1 = __state->index - 1) < 20 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "ftnpkt", i__1, "sgseqw_",
		 (ftnlen)2622)] > 0) {
	    if (__state->ftrefs[(i__1 = (__state->index << 1) - 2) < 40 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftrefs", 
		    i__1, "sgseqw_", (ftnlen)2624)] >= refdat[0]) {
		setmsg_(__global_state, "Reference values are out of order. "
			"The offending value, #, was found to be out of order"
			". The reference values for explicitly indexed packet"
			"s must be in increasing order, and the first referen"
			"ce value is less than or equal to the last reference"
			" value, #, from the previous addition of packets.", (
			ftnlen)292);
		errdp_(__global_state, "#", refdat, (ftnlen)1);
		errdp_(__global_state, "#", &__state->ftrefs[(i__1 = (
			__state->index << 1) - 2) < 40 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "ftrefs", i__1, "sgseqw_"
			, (ftnlen)2635)], (ftnlen)1);
		sigerr_(__global_state, "SPICE(UNORDEREDREFS)", (ftnlen)20);
		chkout_(__global_state, "SGWFPK", (ftnlen)6);
		return 0;
	    }
	}
	i__1 = *nrefs;
	for (i__ = 2; i__ <= i__1; ++i__) {
	    if (refdat[i__ - 2] >= refdat[i__ - 1]) {
		setmsg_(__global_state, "Reference values are out of order. "
			"The offending value, #, was found to be out of order"
			" for index #. The reference values for explicitly in"
			"dexed packets must be in increasing order.", (ftnlen)
			181);
		errdp_(__global_state, "#", &refdat[i__ - 2], (ftnlen)1);
		i__2 = i__ - 1;
		errint_(__global_state, "#", &i__2, (ftnlen)1);
		sigerr_(__global_state, "SPICE(UNORDEREDREFS)", (ftnlen)20);
		chkout_(__global_state, "SGWFPK", (ftnlen)6);
		return 0;
	    }
	}

/*        Add the packets preceded by their reference values to the */
/*        segment. We put the reference values with the packets so that */
/*        we do not need to open a scratch file. We will use them to */
/*        construct a reference directory after all of the packets have */
/*        been added to the segment. */

	i__1 = *npkts;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    dafada_(__global_state, &refdat[i__ - 1], &__state->c__1);
	    dafada_(__global_state, &pktdat[(i__ - 1) * __state->ftpksz[(i__2 
		    = __state->index - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "ftpksz", i__2, "sgseqw_", (ftnlen)
		    2673)]], &__state->ftpksz[(i__3 = __state->index - 1) < 
		    20 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "ftpksz", i__3, "sgseqw_", (ftnlen)2673)]);
	    if (failed_(__global_state)) {
		chkout_(__global_state, "SGWFPK", (ftnlen)6);
		return 0;
	    }
	}

/*        Save the last reference value in the file table so that we */
/*        can use it to verify that the next addition does not violate */
/*        the increasing order of the reference values. */

	__state->ftrefs[(i__1 = (__state->index << 1) - 2) < 40 && 0 <= i__1 ?
		 i__1 : s_rnge(&__global_state->f2c, "ftrefs", i__1, "sgseqw_"
		, (ftnlen)2687)] = refdat[*nrefs - 1];

/*        Update the counts for the number of packets, the number of */
/*        references. */

	__state->ftnpkt[(i__1 = __state->index - 1) < 20 && 0 <= i__1 ? i__1 :
		 s_rnge(&__global_state->f2c, "ftnpkt", i__1, "sgseqw_", (
		ftnlen)2692)] = __state->ftnpkt[(i__2 = __state->index - 1) < 
		20 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftnpkt"
		, i__2, "sgseqw_", (ftnlen)2692)] + *npkts;
	__state->ftnref[(i__1 = __state->index - 1) < 20 && 0 <= i__1 ? i__1 :
		 s_rnge(&__global_state->f2c, "ftnref", i__1, "sgseqw_", (
		ftnlen)2693)] = __state->ftnref[(i__2 = __state->index - 1) < 
		20 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftnref"
		, i__2, "sgseqw_", (ftnlen)2693)] + *nrefs;
    } else {

/*        For implicitly indexed packets the number of reference values */
/*        must be two (2), and the second reference value must be an */
/*        integer, i.e., DINT(REFDAT(2)) .eq. REFDAT(2). The number of */
/*        reference values and the integrality of the second reference */
/*        value are checked only on the first call to add variable length */
/*        data packets to a generic segment. In all subsequent calls, */
/*        these arguments are ignored. */

	if (__state->ftnpkt[(i__1 = __state->index - 1) < 20 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "ftnpkt", i__1, "sgseqw_",
		 (ftnlen)2706)] == 0) {
	    if (*nrefs != 2) {
		setmsg_(__global_state, "The number of reference values supp"
			"lied, #, is not compatible with implicitly indexed p"
			"ackets. Implicitly indexed packets require the numbe"
			"r of reference values to be two (2).", (ftnlen)175);
		errint_(__global_state, "#", nrefs, (ftnlen)1);
		sigerr_(__global_state, "SPICE(INCOMPATIBLENUMREF)", (ftnlen)
			25);
		chkout_(__global_state, "SGWFPK", (ftnlen)6);
		return 0;
	    }
	    if (d_int(&__global_state->f2c, &refdat[1]) != refdat[1]) {
		setmsg_(__global_state, "For implicitly indexed packets the "
			"step size must be an integer.", (ftnlen)64);
		sigerr_(__global_state, "SPICE(REFVALNOTINTEGER)", (ftnlen)23)
			;
		chkout_(__global_state, "SGWFPK", (ftnlen)6);
		return 0;
	    }
	}

/*        Add the packets to the segment. */

	i__2 = __state->ftpksz[(i__1 = __state->index - 1) < 20 && 0 <= i__1 ?
		 i__1 : s_rnge(&__global_state->f2c, "ftpksz", i__1, "sgseqw_"
		, (ftnlen)2736)] * *npkts;
	dafada_(__global_state, pktdat, &i__2);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "SGWFPK", (ftnlen)6);
	    return 0;
	}

/*        Save the last reference values and the number of reference */
/*        values in the file table. We only do this on the first time */
/*        through the routine. */

	if (__state->ftnpkt[(i__1 = __state->index - 1) < 20 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "ftnpkt", i__1, "sgseqw_",
		 (ftnlen)2747)] == 0) {
	    __state->ftnref[(i__1 = __state->index - 1) < 20 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "ftnref", i__1, "sgs"
		    "eqw_", (ftnlen)2749)] = *nrefs;
	    __state->ftrefs[(i__1 = (__state->index << 1) - 2) < 40 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftrefs", i__1,
		     "sgseqw_", (ftnlen)2750)] = refdat[0];
	    __state->ftrefs[(i__1 = (__state->index << 1) - 1) < 40 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftrefs", i__1,
		     "sgseqw_", (ftnlen)2751)] = refdat[1];
	}

/*        Update the count for the number of packets. */

	__state->ftnpkt[(i__1 = __state->index - 1) < 20 && 0 <= i__1 ? i__1 :
		 s_rnge(&__global_state->f2c, "ftnpkt", i__1, "sgseqw_", (
		ftnlen)2757)] = __state->ftnpkt[(i__2 = __state->index - 1) < 
		20 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftnpkt"
		, i__2, "sgseqw_", (ftnlen)2757)] + *npkts;
    }
    chkout_(__global_state, "SGWFPK", (ftnlen)6);
    return 0;
/* $Procedure SGWVPK ( Generic segement: Write variable size packets. ) */

L_sgwvpk:
/* $ Abstract */

/*     Write one or more variable size data packets to the generic */
/*     segment currently being written to the DAF file associated with */
/*     HANDLE. */

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

/*     DAF Required Reading. */

/* $ Keywords */

/*     GENERIC SEGMENTS */

/* $ Declarations */

/*     INTEGER               HANDLE */
/*     INTEGER               NPKTS */
/*     INTEGER               PKTSIZ ( * ) */
/*     DOUBLE PRECISION      PKTDAT ( * ) */
/*     INTEGER               NREFS */
/*     DOUBLE PRECISION      REFDAT ( * ) */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*      HANDLE    I    Handle of a DAF file opened with write access. */
/*      NPKTS     I    Number of data packets to write to a segment. */
/*      PKTSIZ    I    Array of sizes of variable size packets. */
/*      PKTDAT    I    Array of packet data. */
/*      NREFS     I    Number of reference values. */
/*      REFDAT    I    Reference data. */

/* $ Detailed_Input */

/*      HANDLE   Handle of a DAF file opened with write access. This is */
/*               the handle of a file in which a generic segment has */
/*               been started and is currently being written. */

/*      NPKTS    Number of data packets to write to a segment. */

/*      PKTSIZ   Sizes of variable size packets. */

/*               By the size of a packet we mean the number of double */
/*               precision numbers contained in a data packet. */

/*               When writing a segment with variable size packets, */
/*               there must be an element in the array PKTSIZ for each of */
/*               the variable size data packets. */

/*      PKTDAT   A singly dimensioned array containing the variable */
/*               size data packets to be added to the generic segment */
/*               associated with HANDLE. */

/*               For variable size data packets, PKTDAT will have the */
/*               following structure: */

/*               Packet #  Range of Locations */
/*               --------  --------------------------------------------- */

/*                     1   PKTDAT(1)           to PKTDAT(P(1)) */
/*                     2   PKTDAT(P(1)+1)      to PKTDAT(P(2)) */
/*                     3   PKTDAT(P(2)+1)      to PKTDAT(P(3)) */
/*                     4   PKTDAT(P(3)+1)      to PKTDAT(P(4)) */

/*                                          . */
/*                                          . */
/*                                          . */

/*                 NPKTS   PKTDAT(P(NPKTS-1)+1) to PKTDAT(P(NPKTS)) */

/*                                I */
/*                               --- */
/*               where P(I) =    >   PKTSIZ(K). */
/*                               --- */
/*                              K = 1 */

/*      NREFS    Number of reference values. */

/*               For implicitly indexed packets, NREFS must have a value */
/*               of two (2). */

/*               When writing packets to a segment which uses an implicit */
/*               index type, the value specified by NREFS is used only on */
/*               the first call to SGWVPK. On all subsequent calls to */
/*               these subroutines for a particular implicitly indexed */
/*               segment, the value of NREFS is ignored. */

/*               For explicitly indexed packets, NREFS must be equal to */
/*               NPKTS, i.e., there should be a reference value for each */
/*               data packet being written to the segment. */

/*               When writing packets to a segment which uses an explicit */
/*               index type, the value specified by NREFS is used on */
/*               every call to SGWVPK and it must be equal to NPKTS. */

/*      REFDAT   Reference data values. */

/*               For implicitly indexed packets, there must be two (2) */
/*               values. The reference values represent a starting */
/*               reference value and a stepsize between consecutive */
/*               reference values, respectively. */

/*               In order to avoid, or at least minimize, numerical */
/*               difficulties associated with computing index values for */
/*               generic segments with implicit index types, the value of */
/*               the stepsize must be an integer, i.e., DINT(REFDAT(2)) */
/*               must equal REFDAT(2). */

/*               When writing packets to a segment which uses an implicit */
/*               index type, the values specified by REFDAT are used only */
/*               on the first call to SGWVPK. On all subsequent calls to */
/*               this subroutine for a particular implicitly indexed */
/*               segment, REFDAT is ignored. */

/*               For explicitly indexed packets, there must be NPKTS */
/*               reference values and the values must be in increasing */
/*               order: */

/*                  REFDAT(I) < REFDAT(I+1), I = 1, NPKTS-1 */

/*               When writing packets to a segment which uses an explicit */
/*               index type, the values specified by REFDAT are used on */
/*               every call to SGWVPK. On all calls to this subroutine */
/*               after the first, the value of REFDAT(1) must be greater */
/*               than than the value of REFDAT(NPKTS) from the previous */
/*               call. This preserves the ordering of the reference */
/*               values for the entire segment. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     This subroutine makes use of parameters defined in the file */
/*     'sgparam.inc'. */

/* $ Exceptions */

/*     1) If there are no generic segments with variable packet sizes */
/*        currently being written, the error SPICE(CALLEDOUTOFORDER) will */
/*        be signalled. */

/*     2) If there is not a generic segment with variable packet size */
/*        being written to the file associated with HANDLE, the error */
/*        SPICE(SEGMENTNOTFOUND) will be signalled. */

/*     3) If the type of generic segment being written to this file is */
/*        not a variable packet size generic segment, the error */
/*        SPICE(SEGTYPECONFLICT) will be signalled. */

/*     4) If the number of packets to be written to the generic segment */
/*        is not positive, the error SPICE(NUMPACKETSNOTPOS) will be */
/*        signalled. */

/*     5) If an explicitly indexed generic segment is being written and */
/*        the number of reference values, NREFS, is not equal to the */
/*        number of data packets being written, NPKTS, the error */
/*        SPICE(INCOMPATIBLENUMREF) will be signalled. */

/*     6) If an explicitly indexed generic segment is being written and */
/*        the reference values are not in increasing order, the error */
/*        SPICE(UNORDEREDREFS) will be signalled. */

/*     7) If an explicitly indexed generic segment is being written and */
/*        the first reference value on the second or later additions */
/*        of packets to the generic segment is not greater than the last */
/*        reference value from the previous addition of packets, the */
/*        error SPICE(UNORDEREDREFS) will be signalled. */

/*     8) If an explicitly indexed generic segment is being written and */
/*        one or more of the packet sizes is not positive, the error */
/*        SPICE(NONPOSPACKETSIZE) will be signalled. */

/*     9) If an implicitly indexed generic segment is being written and */
/*        the number of reference values, NREFS, is not equal to two (2) */
/*        on the first call to this subroutine for a particular segment, */
/*        then the error SPICE(INCOMPATIBLENUMREF) will be signalled. */

/*    10) If an implicitly indexed generic segment is being written and */
/*        the second reference value, the step size used for indexing, is */
/*        not integral, i.e., DINT(REFDAT(2)) .NE. REFDAT(2), the error */
/*        SPICE(REFVALNOTINTEGER) will be signalled. */

/* $ Files */

/*     See HANDLE in the $ Detailed_Input section. */

/* $ Particulars */

/*     This routine will write one or more variable size data packets to */
/*     a generic segment in the DAF file associated with HANDLE. The */
/*     generic segment must have been started by a call to SGBWVS. */

/* $ Examples */

/*     See the $ Examples section in the header for the main subroutine. */
/*     It contains examples wich demonstrate the use of the entry points */
/*     in the generic segments sequential writer. The entry points which */
/*     comprise the generic segments sequential writer must be used */
/*     together in the proper manner. Rather than repeating the examples */
/*     for each entry point they are provided in a single location. */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     K.R. Gehringer    (JPL) */
/*     W.L. Taber        (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 05-APR-1995 (KRG) (WLT) */


/* -& */
/* $ Index_Entries */

/*     write variable size packets to a generic segment */

/* -& */

/*     SPICELIB functions */

/*     INTEGER               LASTNB */
/*     INTEGER               ISRCHI */

/*     LOGICAL               FAILED */
/*     LOGICAL               RETURN */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "SGWVPK", (ftnlen)6);

/*     Check to see if this is the first time here. If it is, we have */
/*     been called out of order, so signal an error. */

    if (__state->numvar == 0) {
	setmsg_(__global_state, "No segment with variable size packets is cu"
		"rrently being written. This routine has been called out of o"
		"rder. The routine SGBWVS must be called before his routine m"
		"ay be called.", (ftnlen)176);
	sigerr_(__global_state, "SPICE(CALLEDOUTOFORDER)", (ftnlen)23);
	chkout_(__global_state, "SGWVPK", (ftnlen)6);
	return 0;
    }

/*     Check to see if the last handle used is the same as the current */
/*     handle. This saves us a table lookup to get the appropriate index */
/*     into the file table to restore the information for that handle. */

    if (*handle != __state->lsthan) {
	__state->index = isrchi_(__global_state, handle, &__state->nft, 
		__state->fthan);
	if (__state->index == 0) {
	    setmsg_(__global_state, "No segment with variable size packets i"
		    "s associated with the file '#'. In order to write variab"
		    "le size packets to a file the routine SGBWVS must be cal"
		    "led to begin the segment.", (ftnlen)176);
	    errhan_(__global_state, "#", handle, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(SEGMENTNOTFOUND)", (ftnlen)22);
	    chkout_(__global_state, "SGWVPK", (ftnlen)6);
	    return 0;
	}
	__state->explct = __state->ftexpl[(i__1 = __state->index - 1) < 20 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftexpl", 
		i__1, "sgseqw_", (ftnlen)3082)];
	__state->fxdseg = __state->ftfixd[(i__1 = __state->index - 1) < 20 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftfixd", 
		i__1, "sgseqw_", (ftnlen)3083)];
	__state->lsthan = *handle;
	dafcad_(__global_state, handle);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "SGWVPK", (ftnlen)6);
	    return 0;
	}
    }

/*     Check to see if the segment being written is a fixed size packet */
/*     segment or a variable size packet segment. If the former, then */
/*     this is the wrong routine. */

    if (__state->fxdseg) {
	setmsg_(__global_state, "The segment being written to the file  '#' "
		"is a fixed packet size segment, not a variable packet size s"
		"egment.  The routine SGWFPK may be used to write fixed size "
		"packets.", (ftnlen)171);
	errhan_(__global_state, "#", handle, (ftnlen)1);
	sigerr_(__global_state, "SPICE(SEGTYPECONFLICT)", (ftnlen)22);
	chkout_(__global_state, "SGWVPK", (ftnlen)6);
	return 0;
    }

/*     At this point, we have a good file handle, an index into the file */
/*     table, and we know that we are working with a variable packet */
/*     size segment. So, what we need to do now is verify the input */
/*     arguments. */

/*     Check the number of packets to be sure that it is positive. */

    if (*npkts <= 0) {
	setmsg_(__global_state, "The number of packets to store is not posit"
		"ive.  The value supplied was #. Perhaps this packet count wa"
		"s unitialized.", (ftnlen)117);
	errint_(__global_state, "#", npkts, (ftnlen)1);
	sigerr_(__global_state, "SPICE(NUMPACKETSNOTPOS)", (ftnlen)23);
	chkout_(__global_state, "SGWVPK", (ftnlen)6);
	return 0;
    }

/*     Now we get to some of the more interesting bits. We now need to */
/*     differentiate between the explicitly indexed types and the */
/*     implicitly indexed types, because they have different */
/*     characteristics and assumptions about how they are stored. */

    if (__state->explct) {

/*        For explicitly indexed packets the number of reference values */
/*        must be equal to the number of packets. The references must */
/*        also be in increasing order. */

	if (*nrefs != *npkts) {
	    setmsg_(__global_state, "The number of reference values supplied"
		    ", #, is not compatible with explicitly indexed packets. "
		    "Explicitly indexed packets require the number of referen"
		    "ce values to equal the number of packets, in this case, "
		    "#.", (ftnlen)209);
	    errint_(__global_state, "#", nrefs, (ftnlen)1);
	    errint_(__global_state, "#", npkts, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(INCOMPATIBLENUMREF)", (ftnlen)25);
	    chkout_(__global_state, "SGWVPK", (ftnlen)6);
	    return 0;
	}

/*        If this is not the first time we have added data to this */
/*        segment, we need to be sure that all of the current reference */
/*        values are greater then the last reference value from the */
/*        provious addition of packets to the segment. */

	if (__state->ftnpkt[(i__1 = __state->index - 1) < 20 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "ftnpkt", i__1, "sgseqw_",
		 (ftnlen)3166)] > 0) {
	    if (__state->ftrefs[(i__1 = (__state->index << 1) - 2) < 40 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftrefs", 
		    i__1, "sgseqw_", (ftnlen)3168)] >= refdat[0]) {
		setmsg_(__global_state, "Reference values are out of order. "
			"The offending value, #, was found The reference valu"
			"es for explicitly to be out of order. indexed packet"
			"s must be in increasing order, and the first referen"
			"ce value is less than or equal to the last reference"
			" value, #, from the previous addition of packets.", (
			ftnlen)292);
		errdp_(__global_state, "#", refdat, (ftnlen)1);
		errdp_(__global_state, "#", &__state->ftrefs[(i__1 = (
			__state->index << 1) - 2) < 40 && 0 <= i__1 ? i__1 : 
			s_rnge(&__global_state->f2c, "ftrefs", i__1, "sgseqw_"
			, (ftnlen)3179)], (ftnlen)1);
		sigerr_(__global_state, "SPICE(UNORDEREDREFS)", (ftnlen)20);
		chkout_(__global_state, "SGWVPK", (ftnlen)6);
		return 0;
	    }
	}
	i__1 = *nrefs;
	for (i__ = 2; i__ <= i__1; ++i__) {
	    if (refdat[i__ - 2] >= refdat[i__ - 1]) {
		setmsg_(__global_state, "Reference values are out of order. "
			"The offending value, #, was found to be out of order"
			" for index #. The reference values for explicitly in"
			"dexed packets must be in increasing order.", (ftnlen)
			181);
		errdp_(__global_state, "#", &refdat[i__ - 2], (ftnlen)1);
		i__2 = i__ - 1;
		errint_(__global_state, "#", &i__2, (ftnlen)1);
		sigerr_(__global_state, "SPICE(UNORDEREDREFS)", (ftnlen)20);
		chkout_(__global_state, "SGWVPK", (ftnlen)6);
		return 0;
	    }
	}

/*        Check the packet size to be sure that it is positive. */

	i__1 = *npkts;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (pktsiz[i__ - 1] <= 0) {
		setmsg_(__global_state, "The packet size for packet # was no"
			"t positive. It had a value of #. All packet sizes mu"
			"st be greater then zero.", (ftnlen)111);
		errint_(__global_state, "#", &i__, (ftnlen)1);
		errint_(__global_state, "#", &pktsiz[i__ - 1], (ftnlen)1);
		sigerr_(__global_state, "SPICE(NONPOSPACKETSIZE)", (ftnlen)23)
			;
		chkout_(__global_state, "SGWVPK", (ftnlen)6);
		return 0;
	    }
	}

/*        Add the packets preceded by their reference values and sizes to */
/*        the segment. We put the reference values with the packets so */
/*        that we do not need to open a scratch file. We will use them to */
/*        construct a reference directory after all of the packets have */
/*        been added to the segment. */

	pktpos = 1;
	i__1 = *npkts;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    dpksiz = (doublereal) pktsiz[i__ - 1];
	    dafada_(__global_state, &refdat[i__ - 1], &__state->c__1);
	    dafada_(__global_state, &dpksiz, &__state->c__1);
	    dafada_(__global_state, &pktdat[pktpos - 1], &pktsiz[i__ - 1]);
	    if (failed_(__global_state)) {
		chkout_(__global_state, "SGWVPK", (ftnlen)6);
		return 0;
	    }
	    pktpos += pktsiz[i__ - 1];
	    __state->ftpksz[(i__2 = __state->index - 1) < 20 && 0 <= i__2 ? 
		    i__2 : s_rnge(&__global_state->f2c, "ftpksz", i__2, "sgs"
		    "eqw_", (ftnlen)3250)] = __state->ftpksz[(i__3 = 
		    __state->index - 1) < 20 && 0 <= i__3 ? i__3 : s_rnge(&
		    __global_state->f2c, "ftpksz", i__3, "sgseqw_", (ftnlen)
		    3250)] + pktsiz[i__ - 1];

/*           Remember the maximum packet size encountered. */

	    if (pktsiz[i__ - 1] > __state->ftmxsz[(i__2 = __state->index - 1) 
		    < 20 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "ftmxsz", i__2, "sgseqw_", (ftnlen)3254)]) {
		__state->ftmxsz[(i__2 = __state->index - 1) < 20 && 0 <= i__2 
			? i__2 : s_rnge(&__global_state->f2c, "ftmxsz", i__2, 
			"sgseqw_", (ftnlen)3256)] = pktsiz[i__ - 1];
	    }
	}

/*        Save the last reference value in the file table so that we */
/*        can use it to verify that the next addition does not violate */
/*        the increasing order of the reference values. */

	__state->ftrefs[(i__1 = (__state->index << 1) - 2) < 40 && 0 <= i__1 ?
		 i__1 : s_rnge(&__global_state->f2c, "ftrefs", i__1, "sgseqw_"
		, (ftnlen)3266)] = refdat[*nrefs - 1];

/*        Update the counts for the number of packets, the number of */
/*        references. */

	__state->ftnpkt[(i__1 = __state->index - 1) < 20 && 0 <= i__1 ? i__1 :
		 s_rnge(&__global_state->f2c, "ftnpkt", i__1, "sgseqw_", (
		ftnlen)3271)] = __state->ftnpkt[(i__2 = __state->index - 1) < 
		20 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftnpkt"
		, i__2, "sgseqw_", (ftnlen)3271)] + *npkts;
	__state->ftnref[(i__1 = __state->index - 1) < 20 && 0 <= i__1 ? i__1 :
		 s_rnge(&__global_state->f2c, "ftnref", i__1, "sgseqw_", (
		ftnlen)3272)] = __state->ftnref[(i__2 = __state->index - 1) < 
		20 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftnref"
		, i__2, "sgseqw_", (ftnlen)3272)] + *nrefs;
    } else {

/*        For implicitly indexed packets the number of reference values */
/*        must be two (2), and the second reference value must be an */
/*        integer, i.e., DINT(REFDAT(2)) .eq. REFDAT(2). The number of */
/*        reference values and the integrality of the second reference */
/*        value are checked only on the first call to add variable length */
/*        data packets to a generic segment. In all subsequent calls, */
/*        these arguments are ignored. */

	if (__state->ftnpkt[(i__1 = __state->index - 1) < 20 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "ftnpkt", i__1, "sgseqw_",
		 (ftnlen)3284)] == 0) {
	    if (*nrefs != 2) {
		setmsg_(__global_state, "The number of reference values supp"
			"lied, #, is not compatible with implicitly indexed p"
			"ackets. Implicitly indexed packets require the numbe"
			"r of reference values to be two (2).", (ftnlen)175);
		errint_(__global_state, "#", nrefs, (ftnlen)1);
		sigerr_(__global_state, "SPICE(INCOMPATIBLENUMREF)", (ftnlen)
			25);
		chkout_(__global_state, "SGWVPK", (ftnlen)6);
		return 0;
	    }
	    if (d_int(&__global_state->f2c, &refdat[1]) != refdat[1]) {
		setmsg_(__global_state, "For implicitly indexed packets the "
			"step size must be an integer.", (ftnlen)64);
		sigerr_(__global_state, "SPICE(REFVALNOTINTEGER)", (ftnlen)23)
			;
		chkout_(__global_state, "SGWVPK", (ftnlen)6);
		return 0;
	    }
	}

/*        Add the packets to the segment preceded by the size of the */
/*        packet. */

	pktpos = 1;
	i__1 = *npkts;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    dpksiz = (doublereal) pktsiz[i__ - 1];
	    dafada_(__global_state, &dpksiz, &__state->c__1);
	    dafada_(__global_state, &pktdat[pktpos - 1], &pktsiz[i__ - 1]);
	    if (failed_(__global_state)) {
		chkout_(__global_state, "SGWVPK", (ftnlen)6);
		return 0;
	    }
	    pktpos += pktsiz[i__ - 1];
	    __state->ftpksz[(i__2 = __state->index - 1) < 20 && 0 <= i__2 ? 
		    i__2 : s_rnge(&__global_state->f2c, "ftpksz", i__2, "sgs"
		    "eqw_", (ftnlen)3331)] = __state->ftpksz[(i__3 = 
		    __state->index - 1) < 20 && 0 <= i__3 ? i__3 : s_rnge(&
		    __global_state->f2c, "ftpksz", i__3, "sgseqw_", (ftnlen)
		    3331)] + pktsiz[i__ - 1];
	}

/*        Save the reference values and the number of reference values */
/*        in the file table. We only do this on the first time through */
/*        the routine. */

	if (__state->ftnpkt[(i__1 = __state->index - 1) < 20 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "ftnpkt", i__1, "sgseqw_",
		 (ftnlen)3339)] == 0) {
	    __state->ftnref[(i__1 = __state->index - 1) < 20 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "ftnref", i__1, "sgs"
		    "eqw_", (ftnlen)3341)] = *nrefs;
	    __state->ftrefs[(i__1 = (__state->index << 1) - 2) < 40 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftrefs", i__1,
		     "sgseqw_", (ftnlen)3342)] = refdat[0];
	    __state->ftrefs[(i__1 = (__state->index << 1) - 1) < 40 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftrefs", i__1,
		     "sgseqw_", (ftnlen)3343)] = refdat[1];
	}

/*        Update the counts for the number of packets. */

	__state->ftnpkt[(i__1 = __state->index - 1) < 20 && 0 <= i__1 ? i__1 :
		 s_rnge(&__global_state->f2c, "ftnpkt", i__1, "sgseqw_", (
		ftnlen)3349)] = __state->ftnpkt[(i__2 = __state->index - 1) < 
		20 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftnpkt"
		, i__2, "sgseqw_", (ftnlen)3349)] + *npkts;
    }
    chkout_(__global_state, "SGWVPK", (ftnlen)6);
    return 0;
/* $Procedure SGWES ( Generic segements: End a segment. ) */

L_sgwes:
/* $ Abstract */

/*     End the generic segment in the DAF file associated with HANDLE. */

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

/*     DAF Required Reading. */

/* $ Keywords */

/*     GENERIC SEGMENTS */

/* $ Declarations */

/*     INTEGER               HANDLE */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*      HANDLE    I    Handle of a DAF file opened with write access. */

/* $ Detailed_Input */

/*      HANDLE   Handle of a DAF file opened with write access. This is */
/*               the handle of the file which contains the generic */
/*               segment that we wish to end. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     This subroutine makes use of parameters defined in the file */
/*     'sgparam.inc'. */

/* $ Exceptions */

/*     1) If there are no generic segments currently being written, the */
/*        error SPICE(CALLEDOUTOFORDER) will be signalled. */

/*     2) If there is no generic segment being written to the file */
/*        associated with HANDLE, the error SPICE(SEGMENTNOTFOUND) will */
/*        be signalled. */

/* $ Files */

/*     See HANDLE in the $ Detailed_Input section. */

/* $ Particulars */

/*     This routine will end the generic segment started by a call to */
/*     either SGBWFS or SGBWVS that is currently being written to the DAF */
/*     file associated with HANDLE. */

/* $ Examples */

/*     See the $ Examples section in the header for the main subroutine. */
/*     It contains examples wich demonstrate the use of the entry points */
/*     in the generic segments sequential writer. The entry points which */
/*     comprise the generic segments sequential writer must be used */
/*     together in the proper manner. Rather than repeating the examples */
/*     for each entry point they are provided in a single location. */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     K.R. Gehringer    (JPL) */
/*     W.L. Taber        (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 30-JUL-1996 (KRG) (NJB) */

/*        Fixed an annoying little bug in the variable segments code */
/*        when ending a segment. Rather than storing an appropriate */
/*        offset from the beginning of the segment as the packet */
/*        address in the packet directory, the absolute address, the */
/*        DAF address, was stored. This bug has been fixed. */

/*        The address calculations, see the variable MYADDR, were fixed. */
/*        This involved initializing the variable outside of the loop */
/*        that scans throught the packet data and then incrementing this */
/*        variable in the same way as PKTADR. */

/*        The changes were made in two places, for the explicitly indexed */
/*        case and for the implicitly indexed case. */

/* -    SPICELIB Version 1.0.0, 05-APR-1995 (KRG) (WLT) */

/* -& */
/* $ Index_Entries */

/*     end a generic segment */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.1.0, 30-JUL-1996 (KRG) (NJB) */

/*        Fixed an annoying little bug in the variable segments code */
/*        when ending a segment. Rather than storing an appropriate */
/*        offset from the beginning of the segment as the packet */
/*        address in the packet directory, the absolute address, the */
/*        DAF address, was stored. This bug has been fixed. */

/*        The address calculations, see the variable MYADDR, were fixed. */
/*        This involved initializing the variable outside of the loop */
/*        that scans throught the packet data and then incrementing this */
/*        variable in the same way as PKTADR. */

/*        The changes were made in two places, for the explicitly indexed */
/*        case and for the implicitly indexed case. */

/* -& */

/*     SPICELIB functions */

/*     INTEGER               LASTNB */
/*     INTEGER               ISRCHI */

/*     LOGICAL               FAILED */
/*     LOGICAL               RETURN */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "SGWES", (ftnlen)5);

/*     Check to see if we have any fixed or variable segments being */
/*     written. */

    if (__state->nft == 0) {
	setmsg_(__global_state, "No segment is currently being written. This"
		" routine has been called out of order. One of the routines S"
		"GBWFS or SGBWVS must be called before his routine may be cal"
		"led.", (ftnlen)167);
	sigerr_(__global_state, "SPICE(CALLEDOUTOFORDER)", (ftnlen)23);
	chkout_(__global_state, "SGWES", (ftnlen)5);
	return 0;
    }

/*     Check to see if the last handle used is the same as the current */
/*     handle. This saves us a table lookup to get the appropriate index */
/*     into the file table to restore the information for that handle. */

    if (*handle != __state->lsthan) {
	__state->index = isrchi_(__global_state, handle, &__state->nft, 
		__state->fthan);
	if (__state->index == 0) {
	    setmsg_(__global_state, "No segment is associated with the file "
		    "'#'. In order to write packets to a segment one of the r"
		    "outines SGBWFS or SGBWVS must be called to begin a segme"
		    "nt.", (ftnlen)154);
	    errhan_(__global_state, "#", handle, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(SEGMENTNOTFOUND)", (ftnlen)22);
	    chkout_(__global_state, "SGWES", (ftnlen)5);
	    return 0;
	}
	__state->explct = __state->ftexpl[(i__1 = __state->index - 1) < 20 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftexpl", 
		i__1, "sgseqw_", (ftnlen)3569)];
	__state->fxdseg = __state->ftfixd[(i__1 = __state->index - 1) < 20 && 
		0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftfixd", 
		i__1, "sgseqw_", (ftnlen)3570)];
	__state->lsthan = *handle;
	dafcad_(__global_state, handle);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "SGWES", (ftnlen)5);
	    return 0;
	}
    }

/*     We need to do different things depending on whether the reference */
/*     values are implicitly or explicitly defined. We will also need to */
/*     treat the cases of fixed size packets and variable size packets */
/*     differently. */

    if (__state->explct) {

/*        We have an explicit segment. */

	if (__state->fxdseg) {

/*           We need to do a little bit of work to finish this case off. */
/*           We know that we do not need a list of packet starting */
/*           addresses or a packet directory, but we do need to store in */
/*           a contiguous block the references and a reference directory */
/*           if the number of references is greater than DIRSIZ. */

/*           We need to do the following things: */

/*           1) Initialize the offset of the packet data from the */
/*              beginning of the packet, set the size of the packet, and */
/*              set the beginning address of the packet data area in the */
/*              segment. */

	    size = __state->ftoff[(i__1 = __state->index - 1) < 20 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftoff", i__1, 
		    "sgseqw_", (ftnlen)3606)] + __state->ftpksz[(i__2 = 
		    __state->index - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "ftpksz", i__2, "sgseqw_", (ftnlen)
		    3606)];
	    refadr = __state->ftbadr[(i__1 = __state->index - 1) < 20 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftbadr", i__1,
		     "sgseqw_", (ftnlen)3607)] + __state->ftncon[(i__2 = 
		    __state->index - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "ftncon", i__2, "sgseqw_", (ftnlen)
		    3607)];

/*           2) Collect all of the references stored with the packets */
/*              when they were written, and copy them into the */
/*              reference area. */

	    i__2 = __state->ftnpkt[(i__1 = __state->index - 1) < 20 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftnpkt", i__1,
		     "sgseqw_", (ftnlen)3613)];
	    for (i__ = 1; i__ <= i__2; ++i__) {
		dafgda_(__global_state, handle, &refadr, &refadr, &myref);
		dafada_(__global_state, &myref, &__state->c__1);
		if (failed_(__global_state)) {
		    chkout_(__global_state, "SGWES", (ftnlen)5);
		    return 0;
		}
		refadr += size;
	    }

/*           3) Create a reference directory if the number of */
/*              references is greater than DIRSIZ. */

	    if (__state->ftnref[(i__2 = __state->index - 1) < 20 && 0 <= i__2 
		    ? i__2 : s_rnge(&__global_state->f2c, "ftnref", i__2, 
		    "sgseqw_", (ftnlen)3630)] > 100) {
		refadr = __state->ftbadr[(i__2 = __state->index - 1) < 20 && 
			0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftb"
			"adr", i__2, "sgseqw_", (ftnlen)3632)] + 
			__state->ftncon[(i__1 = __state->index - 1) < 20 && 0 
			<= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftncon"
			, i__1, "sgseqw_", (ftnlen)3632)];
		refadr = refadr + __state->ftnpkt[(i__2 = __state->index - 1) 
			< 20 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "ftnpkt", i__2, "sgseqw_", (
			ftnlen)3633)] * size + 99;
		i__1 = (__state->ftnref[(i__2 = __state->index - 1) < 20 && 0 
			<= i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftnref"
			, i__2, "sgseqw_", (ftnlen)3635)] - 1) / 100;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    dafgda_(__global_state, handle, &refadr, &refadr, &myref);
		    dafada_(__global_state, &myref, &__state->c__1);
		    if (failed_(__global_state)) {
			chkout_(__global_state, "SGWES", (ftnlen)5);
			return 0;
		    }
		    refadr += 100;
		}
	    }

/*           4) Construct the meta data for the segment. */

	    size = (__state->ftoff[(i__1 = __state->index - 1) < 20 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftoff", i__1, 
		    "sgseqw_", (ftnlen)3653)] + __state->ftpksz[(i__2 = 
		    __state->index - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "ftpksz", i__2, "sgseqw_", (ftnlen)
		    3653)]) * __state->ftnpkt[(i__3 = __state->index - 1) < 
		    20 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "ftnpkt", i__3, "sgseqw_", (ftnlen)3653)];
	    meta[0] = 0;
	    meta[1] = __state->ftncon[(i__1 = __state->index - 1) < 20 && 0 <=
		     i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftncon", 
		    i__1, "sgseqw_", (ftnlen)3656)];
	    meta[10] = meta[0] + meta[1];
	    meta[11] = __state->ftnpkt[(i__1 = __state->index - 1) < 20 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftnpkt", 
		    i__1, "sgseqw_", (ftnlen)3658)];
	    meta[15] = __state->ftoff[(i__1 = __state->index - 1) < 20 && 0 <=
		     i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftoff", i__1,
		     "sgseqw_", (ftnlen)3659)];
	    meta[7] = 0;
	    meta[8] = 0;
	    meta[9] = 0;
	    meta[5] = meta[10] + size;
	    meta[6] = __state->ftnref[(i__1 = __state->index - 1) < 20 && 0 <=
		     i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftnref", 
		    i__1, "sgseqw_", (ftnlen)3664)];
	    meta[2] = meta[5] + meta[6];
	    meta[3] = (__state->ftnref[(i__1 = __state->index - 1) < 20 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftnref", 
		    i__1, "sgseqw_", (ftnlen)3666)] - 1) / 100;
	    meta[4] = __state->ftityp[(i__1 = __state->index - 1) < 20 && 0 <=
		     i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftityp", 
		    i__1, "sgseqw_", (ftnlen)3667)];
	    meta[12] = 0;
	    meta[13] = 0;
	    meta[14] = __state->ftpksz[(i__1 = __state->index - 1) < 20 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftpksz", 
		    i__1, "sgseqw_", (ftnlen)3670)];
	    meta[16] = 17;
	} else {

/*           We need to do a little bit of work to finish this case off. */
/*           We know that we need a packet directory and we need to store */
/*           in a contiguous block the references and a reference */
/*           directory if the number of references is greater than */
/*           DIRSIZ. */

/*           We need to do the following things: */

/*           1) Set the beginning address of the packet data area in the */
/*              segment and initialize the address of the first data */
/*              packet. */

	    pktadr = __state->ftbadr[(i__1 = __state->index - 1) < 20 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftbadr", i__1,
		     "sgseqw_", (ftnlen)3687)] + __state->ftncon[(i__2 = 
		    __state->index - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "ftncon", i__2, "sgseqw_", (ftnlen)
		    3687)] + __state->ftoff[(i__3 = __state->index - 1) < 20 
		    && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, "ftoff"
		    , i__3, "sgseqw_", (ftnlen)3687)];
	    myaddr = (doublereal) (__state->ftoff[(i__1 = __state->index - 1) 
		    < 20 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "ftoff", i__1, "sgseqw_", (ftnlen)3688)] + 1);

/*           2) Create a packet directory. The packet directory consists */
/*              of the beginning addresses for each of the packets and a */
/*              fake beginning for an extra packet so that we can easily */
/*              compute the size of the last packet. */

	    i__2 = __state->ftnpkt[(i__1 = __state->index - 1) < 20 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftnpkt", i__1,
		     "sgseqw_", (ftnlen)3695)];
	    for (i__ = 1; i__ <= i__2; ++i__) {
		i__1 = pktadr - 1;
		i__3 = pktadr - 1;
		dafgda_(__global_state, handle, &i__1, &i__3, &mysize);
		dafada_(__global_state, &myaddr, &__state->c__1);
		if (failed_(__global_state)) {
		    chkout_(__global_state, "SGWES", (ftnlen)5);
		    return 0;
		}
		size = (integer) mysize;
		pktadr = pktadr + size + __state->ftoff[(i__1 = 
			__state->index - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge(
			&__global_state->f2c, "ftoff", i__1, "sgseqw_", (
			ftnlen)3707)];
		myaddr += (doublereal) (size + __state->ftoff[(i__1 = 
			__state->index - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge(
			&__global_state->f2c, "ftoff", i__1, "sgseqw_", (
			ftnlen)3708)]);
	    }

/*           Put in the fake beginning for an extra packet. PKTADR should */
/*           contain the proper value. */

	    myaddr = myaddr;
	    dafada_(__global_state, &myaddr, &__state->c__1);
	    if (failed_(__global_state)) {
		chkout_(__global_state, "SGWES", (ftnlen)5);
		return 0;
	    }

/*           3) Collect all of the references, stored with the packets */
/*              when they were written, and copy them into the */
/*              reference area. */

	    refadr = __state->ftbadr[(i__2 = __state->index - 1) < 20 && 0 <= 
		    i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftbadr", i__2,
		     "sgseqw_", (ftnlen)3729)] + __state->ftncon[(i__1 = 
		    __state->index - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "ftncon", i__1, "sgseqw_", (ftnlen)
		    3729)];
	    i__1 = __state->ftnpkt[(i__2 = __state->index - 1) < 20 && 0 <= 
		    i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftnpkt", i__2,
		     "sgseqw_", (ftnlen)3731)];
	    for (i__ = 1; i__ <= i__1; ++i__) {
		dafgda_(__global_state, handle, &refadr, &refadr, &myref);
		i__2 = refadr + 1;
		i__3 = refadr + 1;
		dafgda_(__global_state, handle, &i__2, &i__3, &mysize);
		dafada_(__global_state, &myref, &__state->c__1);
		if (failed_(__global_state)) {
		    chkout_(__global_state, "SGWES", (ftnlen)5);
		    return 0;
		}
		size = (integer) mysize;
		refadr = refadr + size + __state->ftoff[(i__2 = 
			__state->index - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(
			&__global_state->f2c, "ftoff", i__2, "sgseqw_", (
			ftnlen)3743)];
	    }

/*           3) Create a reference directory if the number of */
/*              references is greater than DIRSIZ. Note that we have one */
/*              more packet directory item than we have data packets. */
/*              This allows us to compute the size of the last data */
/*              packet. */

	    if (__state->ftnref[(i__1 = __state->index - 1) < 20 && 0 <= i__1 
		    ? i__1 : s_rnge(&__global_state->f2c, "ftnref", i__1, 
		    "sgseqw_", (ftnlen)3753)] > 100) {
		refadr = __state->ftbadr[(i__1 = __state->index - 1) < 20 && 
			0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftb"
			"adr", i__1, "sgseqw_", (ftnlen)3755)] + 
			__state->ftncon[(i__2 = __state->index - 1) < 20 && 0 
			<= i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftncon"
			, i__2, "sgseqw_", (ftnlen)3755)];
		refadr += __state->ftpksz[(i__1 = __state->index - 1) < 20 && 
			0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftp"
			"ksz", i__1, "sgseqw_", (ftnlen)3756)];
		refadr += __state->ftoff[(i__1 = __state->index - 1) < 20 && 
			0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "fto"
			"ff", i__1, "sgseqw_", (ftnlen)3757)] * 
			__state->ftnpkt[(i__2 = __state->index - 1) < 20 && 0 
			<= i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftnpkt"
			, i__2, "sgseqw_", (ftnlen)3757)];
		refadr = refadr + __state->ftnpkt[(i__1 = __state->index - 1) 
			< 20 && 0 <= i__1 ? i__1 : s_rnge(&
			__global_state->f2c, "ftnpkt", i__1, "sgseqw_", (
			ftnlen)3758)] + 1;
		refadr += 99;
		i__2 = (__state->ftnref[(i__1 = __state->index - 1) < 20 && 0 
			<= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftnref"
			, i__1, "sgseqw_", (ftnlen)3761)] - 1) / 100;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    dafgda_(__global_state, handle, &refadr, &refadr, &myref);
		    dafada_(__global_state, &myref, &__state->c__1);
		    if (failed_(__global_state)) {
			chkout_(__global_state, "SGWES", (ftnlen)5);
			return 0;
		    }
		    refadr += 100;
		}
	    }

/*           4) Construct the meta data for the segment. */

	    meta[0] = 0;
	    meta[1] = __state->ftncon[(i__2 = __state->index - 1) < 20 && 0 <=
		     i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftncon", 
		    i__2, "sgseqw_", (ftnlen)3780)];
	    meta[10] = meta[0] + meta[1];
	    meta[11] = __state->ftnpkt[(i__2 = __state->index - 1) < 20 && 0 
		    <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftnpkt", 
		    i__2, "sgseqw_", (ftnlen)3782)];
	    meta[15] = __state->ftoff[(i__2 = __state->index - 1) < 20 && 0 <=
		     i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftoff", i__2,
		     "sgseqw_", (ftnlen)3783)];
	    meta[7] = meta[10] + __state->ftpksz[(i__2 = __state->index - 1) <
		     20 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "ftpksz", i__2, "sgseqw_", (ftnlen)3784)] + 
		    __state->ftoff[(i__1 = __state->index - 1) < 20 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftoff", i__1, 
		    "sgseqw_", (ftnlen)3784)] * __state->ftnpkt[(i__3 = 
		    __state->index - 1) < 20 && 0 <= i__3 ? i__3 : s_rnge(&
		    __global_state->f2c, "ftnpkt", i__3, "sgseqw_", (ftnlen)
		    3784)];
	    meta[8] = __state->ftnpkt[(i__2 = __state->index - 1) < 20 && 0 <=
		     i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftnpkt", 
		    i__2, "sgseqw_", (ftnlen)3786)] + 1;
	    meta[9] = 1;
	    meta[5] = meta[7] + meta[8];
	    meta[6] = __state->ftnref[(i__2 = __state->index - 1) < 20 && 0 <=
		     i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftnref", 
		    i__2, "sgseqw_", (ftnlen)3789)];
	    meta[2] = meta[5] + meta[6];
	    meta[3] = (__state->ftnref[(i__2 = __state->index - 1) < 20 && 0 
		    <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftnref", 
		    i__2, "sgseqw_", (ftnlen)3791)] - 1) / 100;
	    meta[4] = __state->ftityp[(i__2 = __state->index - 1) < 20 && 0 <=
		     i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftityp", 
		    i__2, "sgseqw_", (ftnlen)3792)];
	    meta[12] = 0;
	    meta[13] = 0;
	    meta[14] = __state->ftmxsz[(i__2 = __state->index - 1) < 20 && 0 
		    <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftmxsz", 
		    i__2, "sgseqw_", (ftnlen)3795)];
	    meta[16] = 17;
	}
    } else {

/*        We have an implicitly indexed segment. */

	if (__state->fxdseg) {

/*           There is no packet directory, so we just write the reference */
/*           values. There is no reference directory either, because */
/*           implicitly indexed packets only have two (2) reference */
/*           values. */

	    dafada_(__global_state, &__state->ftrefs[(i__2 = (__state->index 
		    << 1) - 2) < 40 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "ftrefs", i__2, "sgseqw_", (ftnlen)
		    3811)], &__state->ftnref[(i__1 = __state->index - 1) < 20 
		    && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftnr"
		    "ef", i__1, "sgseqw_", (ftnlen)3811)]);
	    if (failed_(__global_state)) {
		chkout_(__global_state, "SGWES", (ftnlen)5);
		return 0;
	    }

/*           Now we need to construct the meta data for this segment. We */
/*           will write it to the file a bit later. */

	    size = (__state->ftoff[(i__2 = __state->index - 1) < 20 && 0 <= 
		    i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftoff", i__2, 
		    "sgseqw_", (ftnlen)3821)] + __state->ftpksz[(i__1 = 
		    __state->index - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "ftpksz", i__1, "sgseqw_", (ftnlen)
		    3821)]) * __state->ftnpkt[(i__3 = __state->index - 1) < 
		    20 && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, 
		    "ftnpkt", i__3, "sgseqw_", (ftnlen)3821)];
	    meta[0] = 0;
	    meta[1] = __state->ftncon[(i__2 = __state->index - 1) < 20 && 0 <=
		     i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftncon", 
		    i__2, "sgseqw_", (ftnlen)3824)];
	    meta[10] = meta[0] + meta[1];
	    meta[11] = __state->ftnpkt[(i__2 = __state->index - 1) < 20 && 0 
		    <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftnpkt", 
		    i__2, "sgseqw_", (ftnlen)3826)];
	    meta[15] = __state->ftoff[(i__2 = __state->index - 1) < 20 && 0 <=
		     i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftoff", i__2,
		     "sgseqw_", (ftnlen)3827)];
	    meta[7] = 0;
	    meta[8] = 0;
	    meta[9] = 0;
	    meta[5] = meta[10] + size;
	    meta[6] = __state->ftnref[(i__2 = __state->index - 1) < 20 && 0 <=
		     i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftnref", 
		    i__2, "sgseqw_", (ftnlen)3832)];
	    meta[2] = meta[5] + meta[6];
	    meta[3] = 0;
	    meta[4] = __state->ftityp[(i__2 = __state->index - 1) < 20 && 0 <=
		     i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftityp", 
		    i__2, "sgseqw_", (ftnlen)3835)];
	    meta[12] = 0;
	    meta[13] = 0;
	    meta[14] = __state->ftpksz[(i__2 = __state->index - 1) < 20 && 0 
		    <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftpksz", 
		    i__2, "sgseqw_", (ftnlen)3838)];
	    meta[16] = 17;
	} else {

/*           We need to do a little bit of work to finish this case off. */
/*           We know that we need a packet directory, but we do not need */
/*           a reference directory. */

/*           We need to do the following things: */

/*           1) Set the beginning address of the packet data area in the */
/*              segment and initialize the address of the first data */
/*              packet. */

	    pktadr = __state->ftbadr[(i__2 = __state->index - 1) < 20 && 0 <= 
		    i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftbadr", i__2,
		     "sgseqw_", (ftnlen)3853)] + __state->ftncon[(i__1 = 
		    __state->index - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "ftncon", i__1, "sgseqw_", (ftnlen)
		    3853)] + __state->ftoff[(i__3 = __state->index - 1) < 20 
		    && 0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, "ftoff"
		    , i__3, "sgseqw_", (ftnlen)3853)];
	    myaddr = (doublereal) (__state->ftoff[(i__2 = __state->index - 1) 
		    < 20 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "ftoff", i__2, "sgseqw_", (ftnlen)3854)] + 1);

/*           2) Create a packet directory. The packet directory consists */
/*              of the beginning addresses for each of the packets and a */
/*              fake beginning for an extra packet so that we can easily */
/*              compute the size of the last packet. */

	    i__1 = __state->ftnpkt[(i__2 = __state->index - 1) < 20 && 0 <= 
		    i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftnpkt", i__2,
		     "sgseqw_", (ftnlen)3861)];
	    for (i__ = 1; i__ <= i__1; ++i__) {
		i__2 = pktadr - 1;
		i__3 = pktadr - 1;
		dafgda_(__global_state, handle, &i__2, &i__3, &mysize);
		dafada_(__global_state, &myaddr, &__state->c__1);
		if (failed_(__global_state)) {
		    chkout_(__global_state, "SGWES", (ftnlen)5);
		    return 0;
		}
		size = (integer) mysize;
		pktadr = pktadr + size + __state->ftoff[(i__2 = 
			__state->index - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(
			&__global_state->f2c, "ftoff", i__2, "sgseqw_", (
			ftnlen)3872)];
		myaddr += (doublereal) (size + __state->ftoff[(i__2 = 
			__state->index - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(
			&__global_state->f2c, "ftoff", i__2, "sgseqw_", (
			ftnlen)3873)]);
	    }

/*           Put in the fake beginning for an extra packet. PKTADR should */
/*           contain the proper value. */

	    myaddr = (doublereal) (pktadr - __state->ftbadr[(i__1 = 
		    __state->index - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "ftbadr", i__1, "sgseqw_", (ftnlen)
		    3880)]);
	    dafada_(__global_state, &myaddr, &__state->c__1);
	    if (failed_(__global_state)) {
		chkout_(__global_state, "SGWES", (ftnlen)5);
		return 0;
	    }

/*           3) Construct the meta data for the segment. */

	    meta[0] = 0;
	    meta[1] = __state->ftncon[(i__1 = __state->index - 1) < 20 && 0 <=
		     i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftncon", 
		    i__1, "sgseqw_", (ftnlen)3892)];
	    meta[10] = meta[0] + meta[1];
	    meta[11] = __state->ftnpkt[(i__1 = __state->index - 1) < 20 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftnpkt", 
		    i__1, "sgseqw_", (ftnlen)3894)];
	    meta[15] = __state->ftoff[(i__1 = __state->index - 1) < 20 && 0 <=
		     i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftoff", i__1,
		     "sgseqw_", (ftnlen)3895)];
	    meta[7] = meta[10] + __state->ftpksz[(i__1 = __state->index - 1) <
		     20 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "ftpksz", i__1, "sgseqw_", (ftnlen)3896)] + 
		    __state->ftoff[(i__2 = __state->index - 1) < 20 && 0 <= 
		    i__2 ? i__2 : s_rnge(&__global_state->f2c, "ftoff", i__2, 
		    "sgseqw_", (ftnlen)3896)] * __state->ftnpkt[(i__3 = 
		    __state->index - 1) < 20 && 0 <= i__3 ? i__3 : s_rnge(&
		    __global_state->f2c, "ftnpkt", i__3, "sgseqw_", (ftnlen)
		    3896)];
	    meta[8] = __state->ftnpkt[(i__1 = __state->index - 1) < 20 && 0 <=
		     i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftnpkt", 
		    i__1, "sgseqw_", (ftnlen)3898)] + 1;
	    meta[9] = 1;
	    meta[5] = meta[7] + meta[8];
	    meta[6] = __state->ftnref[(i__1 = __state->index - 1) < 20 && 0 <=
		     i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftnref", 
		    i__1, "sgseqw_", (ftnlen)3901)];
	    meta[2] = meta[5] + meta[6];
	    meta[3] = 0;
	    meta[4] = __state->ftityp[(i__1 = __state->index - 1) < 20 && 0 <=
		     i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftityp", 
		    i__1, "sgseqw_", (ftnlen)3904)];
	    meta[12] = 0;
	    meta[13] = 0;
	    meta[14] = __state->ftmxsz[(i__1 = __state->index - 1) < 20 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "ftmxsz", 
		    i__1, "sgseqw_", (ftnlen)3907)];
	    meta[16] = 17;
	}
    }

/*     Write the meta data to the segment and end the segment. */

    for (i__ = 1; i__ <= 17; ++i__) {
	xmeta[(i__1 = i__ - 1) < 17 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "xmeta", i__1, "sgseqw_", (ftnlen)3917)] 
		= (doublereal) meta[(i__2 = i__ - 1) < 17 && 0 <= i__2 ? i__2 
		: s_rnge(&__global_state->f2c, "meta", i__2, "sgseqw_", (
		ftnlen)3917)];
    }
    dafada_(__global_state, xmeta, &__state->c__17);

/*     End the segment. */

    dafena_(__global_state);
    if (failed_(__global_state)) {
	chkout_(__global_state, "SGWES", (ftnlen)5);
	return 0;
    }

/*     Now we need to clean up after ourselves, removing the information */
/*     for the segment we just ended from the file table. */

    --__state->nft;
    i__1 = __state->nft;
    for (i__ = __state->index; i__ <= i__1; ++i__) {
	__state->ftbadr[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "ftbadr", i__2, "sgseqw_", (ftnlen)3937)]
		 = __state->ftbadr[(i__3 = i__) < 20 && 0 <= i__3 ? i__3 : 
		s_rnge(&__global_state->f2c, "ftbadr", i__3, "sgseqw_", (
		ftnlen)3937)];
	__state->fthan[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "fthan", i__2, "sgseqw_", (ftnlen)3938)] 
		= __state->fthan[(i__3 = i__) < 20 && 0 <= i__3 ? i__3 : 
		s_rnge(&__global_state->f2c, "fthan", i__3, "sgseqw_", (
		ftnlen)3938)];
	__state->ftityp[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "ftityp", i__2, "sgseqw_", (ftnlen)3939)]
		 = __state->ftityp[(i__3 = i__) < 20 && 0 <= i__3 ? i__3 : 
		s_rnge(&__global_state->f2c, "ftityp", i__3, "sgseqw_", (
		ftnlen)3939)];
	__state->ftncon[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "ftncon", i__2, "sgseqw_", (ftnlen)3940)]
		 = __state->ftncon[(i__3 = i__) < 20 && 0 <= i__3 ? i__3 : 
		s_rnge(&__global_state->f2c, "ftncon", i__3, "sgseqw_", (
		ftnlen)3940)];
	__state->ftnpkt[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "ftnpkt", i__2, "sgseqw_", (ftnlen)3941)]
		 = __state->ftnpkt[(i__3 = i__) < 20 && 0 <= i__3 ? i__3 : 
		s_rnge(&__global_state->f2c, "ftnpkt", i__3, "sgseqw_", (
		ftnlen)3941)];
	__state->ftnref[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "ftnref", i__2, "sgseqw_", (ftnlen)3942)]
		 = __state->ftnref[(i__3 = i__) < 20 && 0 <= i__3 ? i__3 : 
		s_rnge(&__global_state->f2c, "ftnref", i__3, "sgseqw_", (
		ftnlen)3942)];
	__state->ftnres[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "ftnres", i__2, "sgseqw_", (ftnlen)3943)]
		 = __state->ftnres[(i__3 = i__) < 20 && 0 <= i__3 ? i__3 : 
		s_rnge(&__global_state->f2c, "ftnres", i__3, "sgseqw_", (
		ftnlen)3943)];
	__state->ftoff[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "ftoff", i__2, "sgseqw_", (ftnlen)3944)] 
		= __state->ftoff[(i__3 = i__) < 20 && 0 <= i__3 ? i__3 : 
		s_rnge(&__global_state->f2c, "ftoff", i__3, "sgseqw_", (
		ftnlen)3944)];
	__state->ftpksz[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "ftpksz", i__2, "sgseqw_", (ftnlen)3945)]
		 = __state->ftpksz[(i__3 = i__) < 20 && 0 <= i__3 ? i__3 : 
		s_rnge(&__global_state->f2c, "ftpksz", i__3, "sgseqw_", (
		ftnlen)3945)];
	__state->ftfixd[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "ftfixd", i__2, "sgseqw_", (ftnlen)3946)]
		 = __state->ftfixd[(i__3 = i__) < 20 && 0 <= i__3 ? i__3 : 
		s_rnge(&__global_state->f2c, "ftfixd", i__3, "sgseqw_", (
		ftnlen)3946)];
	__state->ftexpl[(i__2 = i__ - 1) < 20 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "ftexpl", i__2, "sgseqw_", (ftnlen)3947)]
		 = __state->ftexpl[(i__3 = i__) < 20 && 0 <= i__3 ? i__3 : 
		s_rnge(&__global_state->f2c, "ftexpl", i__3, "sgseqw_", (
		ftnlen)3947)];
    }
    if (__state->fxdseg) {
	--__state->numfxd;
    } else {
	--__state->numvar;
    }
    chkout_(__global_state, "SGWES", (ftnlen)5);
    return 0;
} /* sgseqw_ */

/* Subroutine */ int sgseqw_(cspice_t* __global_state, integer *handle, 
	doublereal *descr, char *segid, integer *nconst, doublereal *const__, 
	integer *npkts, integer *pktsiz, doublereal *pktdat, integer *nrefs, 
	doublereal *refdat, integer *idxtyp, ftnlen segid_len)
{
    return sgseqw_0_(0, handle, descr, segid, nconst, const__, npkts, pktsiz, 
	    pktdat, nrefs, refdat, idxtyp, segid_len);
    }

/* Subroutine */ int sgbwfs_(cspice_t* __global_state, integer *handle, 
	doublereal *descr, char *segid, integer *nconst, doublereal *const__, 
	integer *pktsiz, integer *idxtyp, ftnlen segid_len)
{
    return sgseqw_0_(1, handle, descr, segid, nconst, const__, (integer *)0, 
	    pktsiz, (doublereal *)0, (integer *)0, (doublereal *)0, idxtyp, 
	    segid_len);
    }

/* Subroutine */ int sgbwvs_(cspice_t* __global_state, integer *handle, 
	doublereal *descr, char *segid, integer *nconst, doublereal *const__, 
	integer *idxtyp, ftnlen segid_len)
{
    return sgseqw_0_(2, handle, descr, segid, nconst, const__, (integer *)0, (
	    integer *)0, (doublereal *)0, (integer *)0, (doublereal *)0, 
	    idxtyp, segid_len);
    }

/* Subroutine */ int sgwfpk_(cspice_t* __global_state, integer *handle, 
	integer *npkts, doublereal *pktdat, integer *nrefs, doublereal *
	refdat)
{
    return sgseqw_0_(3, handle, (doublereal *)0, (char *)0, (integer *)0, (
	    doublereal *)0, npkts, (integer *)0, pktdat, nrefs, refdat, (
	    integer *)0, (ftnint)0);
    }

/* Subroutine */ int sgwvpk_(cspice_t* __global_state, integer *handle, 
	integer *npkts, integer *pktsiz, doublereal *pktdat, integer *nrefs, 
	doublereal *refdat)
{
    return sgseqw_0_(4, handle, (doublereal *)0, (char *)0, (integer *)0, (
	    doublereal *)0, npkts, pktsiz, pktdat, nrefs, refdat, (integer *)
	    0, (ftnint)0);
    }

/* Subroutine */ int sgwes_(cspice_t* __global_state, integer *handle)
{
    return sgseqw_0_(5, handle, (doublereal *)0, (char *)0, (integer *)0, (
	    doublereal *)0, (integer *)0, (integer *)0, (doublereal *)0, (
	    integer *)0, (doublereal *)0, (integer *)0, (ftnint)0);
    }

