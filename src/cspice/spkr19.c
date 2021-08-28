/* spkr19.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern spkr19_init_t __spkr19_init;
static inline spkr19_state_t* get_spkr19_state(cspice_t* state) {
	if (!state->spkr19)
		state->spkr19 = __cspice_allocate_module(sizeof(
	spkr19_state_t), &__spkr19_init, sizeof(__spkr19_init));
	return state->spkr19;

}

/* $Procedure  SPKR19 ( SPK, read record from segment, type 19 ) */
/* Subroutine */ int spkr19_(cspice_t* __global_state, integer *handle, 
	doublereal *descr, doublereal *et, doublereal *record)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer i_dnnt(f2c_state_t*, doublereal *), s_rnge(f2c_state_t*, char *, 
	    integer, char *, integer);

    /* Local variables */
    integer high;
    integer isel;
    integer ndir;
    integer last;
    integer npkt;
    integer type__;
    integer i__;
    integer baddr;
    integer n;
    integer eaddr;
    integer nread;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer minib;
    integer minie;
    extern /* Subroutine */ int dafus_(cspice_t*, doublereal *, integer *, 
	    integer *, doublereal *, integer *);
    integer ivbas;
    extern /* Subroutine */ int errdp_(cspice_t*, char *, doublereal *, 
	    ftnlen);
    integer ivbix;
    integer iveix;
    integer lsize;
    integer first;
    integer group;
    integer rsize;
    logical prvok;
    extern /* Subroutine */ int dafgda_(cspice_t*, integer *, integer *, 
	    integer *, doublereal *);
    doublereal dc[2];
    integer ic[6];
    extern logical failed_(cspice_t*);
    integer begidx;
    integer bufbas;
    integer dirbas;
    integer pkdbas;
    doublereal buffer[101];
    integer endidx;
    integer remain;
    integer timbas;
    logical samseg;
    extern integer lstled_(cspice_t*, doublereal *, integer *, doublereal *);
    integer npkdir;
    logical samivl;
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    doublereal mintim[2];
    integer maxwnd;
    integer miniix;
    doublereal contrl[3];
    integer nrcpkt;
    extern integer lstltd_(cspice_t*, doublereal *, integer *, doublereal *);
    logical ivlsel;
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    integer wndsiz;
    extern logical return_(cspice_t*);
    integer pktsiz;
    integer subtyp;
    extern logical odd_(cspice_t*, integer *);
    integer low;


    /* Module state */
    spkr19_state_t* __state = get_spkr19_state(__global_state);
/* $ Abstract */

/*     Read a single SPK data record from a segment of type 19 */
/*     (ESOC/DDID Piecewise Interpolation). */

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

/*     Declare parameters specific to SPK type 19. */

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

/*     SPK */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman      (JPL) */
/*     B.V. Semenov      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 11-MAY-2015 (NJB) */

/*        Updated to support subtype 2. */

/* -    SPICELIB Version 1.0.0, 07-MAR-2014 (NJB) (BVS) */

/* -& */

/*     Maximum polynomial degree supported by the current */
/*     implementation of this SPK type. */

/*     The degree is compatible with the maximum degrees */
/*     supported by types 13 and 21. */


/*     Integer code indicating `true': */


/*     Integer code indicating `false': */


/*     SPK type 19 subtype codes: */


/*     Subtype 0:  Hermite interpolation, 12-element packets. */


/*     Subtype 1:  Lagrange interpolation, 6-element packets. */


/*     Subtype 2:  Hermite interpolation, 6-element packets. */


/*     Packet sizes associated with the various subtypes: */


/*     Number of subtypes: */


/*     Maximum packet size for type 19: */


/*     Minimum packet size for type 19: */


/*     The SPKPVN record size declared in spkrec.inc must be at least as */
/*     large as the maximum possible size of an SPK type 19 record. */

/*     The largest possible SPK type 19 record has subtype 1 (note that */
/*     records of subtype 0 have half as many epochs as those of subtype */
/*     1, for a given polynomial degree). A type 1 record contains */

/*        - The subtype and packet count */
/*        - MAXDEG+1 packets of size S19PS1 */
/*        - MAXDEG+1 time tags */


/*     End of include file spk19.inc. */

/* $ Abstract */

/*     Declare SPK data record size.  This record is declared in */
/*     SPKPVN and is passed to SPK reader (SPKRxx) and evaluator */
/*     (SPKExx) routines. */

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

/*     SPK */

/* $ Restrictions */

/*     1) If new SPK types are added, it may be necessary to */
/*        increase the size of this record.  The header of SPKPVN */
/*        should be updated as well to show the record size */
/*        requirement for each data type. */

/* $ Author_and_Institution */

/*     N.J. Bachman      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 05-OCT-2012 (NJB) */

/*        Updated to support increase of maximum degree to 27 for types */
/*        2, 3, 8, 9, 12, 13, 18, and 19. See SPKPVN for a list */
/*        of record size requirements as a function of data type. */

/* -    SPICELIB Version 1.0.0, 16-AUG-2002 (NJB) */

/* -& */

/*     End include file spkrec.inc */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   File handle. */
/*     DESCR      I   Segment descriptor. */
/*     ET         I   Target epoch. */
/*     RECORD     O   Data record. */

/* $ Detailed_Input */

/*     HANDLE, */
/*     DESCR       are the file handle and segment descriptor for an SPK */
/*                 segment of type 19. The SPK file designated by HANDLE */
/*                 must be open for read access. */

/*     ET          is an epoch for which a data record from a specific */
/*                 segment is required. ET is expressed as seconds past */
/*                 J2000 TDB. */

/* $ Detailed_Output */

/*     RECORD      is an array of data from the specified segment which, */
/*                 when evaluated at epoch ET, will give the state */
/*                 (position and velocity) of the target body identified */
/*                 by the input segment descriptor. The descriptor */
/*                 specifies the center of motion and reference frame of */
/*                 the state. */

/*                 The structure of the record is as follows: */

/*                    +----------------------+ */
/*                    | subtype code         | */
/*                    +----------------------+ */
/*                    | number of packets (n)| */
/*                    +----------------------+ */
/*                    | packet 1             | */
/*                    +----------------------+ */
/*                    | packet 2             | */
/*                    +----------------------+ */
/*                                . */
/*                                . */
/*                                . */
/*                    +----------------------+ */
/*                    | packet n             | */
/*                    +----------------------+ */
/*                    | epochs 1--n          | */
/*                    +----------------------+ */

/*                 The packet size is a function of the type 19 subtype. */
/*                 All packets in a record have the same size. */

/* $ Parameters */

/*     See the Fortran INCLUDE file spk19.inc. */

/* $ Exceptions */

/*     1) If the input HANDLE does not designate a loaded SPK file, the */
/*        error will be diagnosed by routines called by this routine. */

/*     2) If the segment specified by DESCR is not of data type 19, */
/*        the error 'SPICE(WRONGSPKTYPE)' is signaled. */

/*     3) If the input ET value is not within the range specified */
/*        in the segment descriptor, the error SPICE(TIMEOUTOFBOUNDS) */
/*        is signaled. */

/*     4) If the window size is non-positive or greater than the */
/*        maximum allowed value, the error SPICE(INVALIDVALUE) is */
/*        signaled. */

/*     5) If the window size is not compatible with the segment */
/*        subtype, the error SPICE(INVALIDVALUE) is signaled. */

/*     6) If the segment subtype is not recognized, the error */
/*        SPICE(NOTSUPPORTED) is signaled. */

/* $ Files */

/*     See argument HANDLE. */

/* $ Particulars */

/*     SPICE user applications normally will have no need to call this */
/*     routine directly. For further information, see the headers of the */
/*     SPICE SPK APIs */

/*        SPKEZR */
/*        SPKPOS */

/*     the SPK Required Reading file spk.req, and the SPICE SPK */
/*     tutorial. */

/*     See the SPK Required Reading file for a description of the */
/*     structure of a data type 19 segment. */

/* $ Examples */

/*     The data returned by the SPKRnn routine is in its rawest form, */
/*     taken directly from the segment.  As such, it will be meaningless */
/*     to a user unless he/she understands the structure of the data type */
/*     completely.  Given that understanding, however, the SPKRxx */
/*     routines might be used to "dump" and check segment data for a */
/*     particular epoch. */


/*     C */
/*     C     Get a segment applicable to a specified body and epoch. */
/*     C */
/*           CALL SPKSFS ( BODY, ET, HANDLE, DESCR, IDENT, FOUND ) */

/*     C */
/*     C     Look at parts of the descriptor. */
/*     C */
/*           CALL DAFUS ( DESCR, 2, 6, DCD, ICD ) */
/*           CENTER = ICD( 2 ) */
/*           REF    = ICD( 3 ) */
/*           TYPE   = ICD( 4 ) */

/*           IF ( TYPE .EQ. 19 ) THEN */
/*              CALL SPKR19 ( HANDLE, DESCR, ET, RECORD ) */
/*                  . */
/*                  .  Look at the RECORD data. */
/*                  . */
/*           END IF */

/* $ Restrictions */

/*     1)  Correctness of inputs must be ensured by the caller of */
/*         this routine. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     B.V. Semenov    (JPL) */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 11-MAY-2015 (NJB) */

/*        Updated to support subtype 2. */

/* -    SPICELIB Version 1.0.0, 14-MAR-2014 (NJB) (BVS) */

/* -& */
/* $ Index_Entries */

/*     read record from type_19 spk segment */

/* -& */
/* $ Revisions */

/*     None. */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Maximum window sizes, based on subtypes: */


/*     Local variables */


/*     Saved variables */


/*     Initial values */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "SPKR19", (ftnlen)6);

/*     Before any error checks are done, copy the status from */
/*     the previous call. Set the saved status variable to */
/*     .FALSE. here so it will be .FALSE. on exit unless this */
/*     call is successful. */

    prvok = __state->svok;
    __state->svok = FALSE_;

/*     Terminology: below, the phrase "base address of 'X'" refers to */
/*     the DAF address immediately preceding X. Base addresses simplify */
/*     mapping DAF array (here "array" means an array stored in */
/*     consecutive DAF addresses, not "segment") indices to DAF */
/*     addresses, since the DAF address of the Ith array element is */
/*     obtained by adding I to the DAF array's base address. */

/*     Key variables: */

/*        Name      Meaning */
/*        ----      ------- */
/*        BADDR     Segment begin DAF address. */

/*        DIRBAS    Base address of interpolation interval directory. */

/*        EADDR     Segment end DAF address. */

/*        FIRST     Index (mini-segment-relative) of first time tag in */
/*                  sequence transferred to to output record. */

/*        HIGH      Index (mini-segment-relative) of time tag following */
/*                  the tag at index LOW (see description below). */

/*        IVBIX     Index in the interpolation interval bounds array of */
/*                  the start time of the applicable interval. */

/*        IVLBAS    Base address of interpolation interval time bounds. */

/*        IVLSEL    Interval selection flag: this routine selects the */
/*                  last applicable interval if true; otherwise it */
/*                  selects the first applicable interval. */

/*        LAST      Index (mini-segment-relative) of last time tag in */
/*                  sequence transferred to the output record. */

/*        LOW       Index (mini-segment-relative) of last time tag less */
/*                  than the request time, or of the first time tag if */
/*                  this tag equals the request time. */

/*        MINIB, */
/*        MINIE     Mini-segment begin and end DAF addresses. These */
/*                  addresses are absolute, not segment-relative. */

/*        MINIIX    Interpolation interval/mini-segment index. */

/*        N         Count of interpolation intervals/mini-segments. */

/*        NDIR      Number of interpolation interval time bounds */
/*                  directories. */

/*        NPKDIR    Number of packet directory entries for current */
/*                  mini-segment. */

/*        NPKT      Packet count for current mini-segment. */

/*        NRCPKT    Output record packet count. Note that this count, */
/*                  due to reduction of order at mini-segment */
/*                  boundaries, may be smaller than the window size */
/*                  stored in the current mini-segment. */

/*        PKDBAS    Base address of packet directory for current */
/*                  mini-segment. */

/*        PKTSIZ    Size of packets of current mini-segment. */

/*        SUBTYP    Subtype of current mini-segment. */

/*        TIMBAS    Base address of time tags of current mini-segment. */

/*        WNDSIZ    Interpolation window size of current mini-segment. */


/*     Re-used variables: the variables shown in the list below */
/*     are used as short-duration variables, much like loop index */
/*     variables; they are re-used as needed. */

/*        BUFBAS */
/*        BUFFER */
/*        GROUP */
/*        NREAD */
/*        REMAIN */

/*     Start with a parameter compatibility check on the first */
/*     pass. */

    if (__state->pass1) {
	if (FALSE_) {
	    setmsg_(__global_state, "SPK type 19 record size may be as large"
		    " as #, but SPKPVN record size (defined in spkrec.inc) is"
		    " #.", (ftnlen)98);
	    errint_(__global_state, "#", &__state->c__198, (ftnlen)1);
	    errint_(__global_state, "#", &__state->c__198, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(BUG)", (ftnlen)10);
	}

/*        Indicate the first pass was completed. */

	__state->pass1 = FALSE_;
    }

/*     Unpack the segment descriptor, and get the start and end */
/*     addresses of the segment. */

    dafus_(__global_state, descr, &__state->c__2, &__state->c__6, dc, ic);
    type__ = ic[3];
    baddr = ic[4];
    eaddr = ic[5];

/*     Check the request time against the bounds in the segment */
/*     descriptor. */

    if (*et < dc[0] || *et > dc[1]) {
	setmsg_(__global_state, "Request time # is outside of descriptor bou"
		"nds # : #.", (ftnlen)53);
	errdp_(__global_state, "#", et, (ftnlen)1);
	errdp_(__global_state, "#", dc, (ftnlen)1);
	errdp_(__global_state, "#", &dc[1], (ftnlen)1);
	sigerr_(__global_state, "SPICE(TIMEOUTOFBOUNDS)", (ftnlen)22);
	chkout_(__global_state, "SPKR19", (ftnlen)6);
	return 0;
    }

/*     Decide whether we're looking at the same segment we saw on the */
/*     previous call, and whether the interpolation interval used on */
/*     that call is still applicable. */

/*     Re-use of data from a previous call requires that the saved */
/*     data were set on a successful call. */

    samseg = *handle == __state->svhan && baddr == __state->svbeg && prvok;

/*     Give SAMIVL an initial value. If we do have the */
/*     same interval, update SAMIVL to indicate this. */

    samivl = FALSE_;
    if (samseg) {

/*        We now assume that all data saved from the last */
/*        read of this segment are valid. */

	if (__state->svlast) {

/*           We pick the last interval containing ET. For */
/*           all intervals but the last, ET must be */
/*           less than the interval end time. */

	    if (__state->svmiix < __state->svn) {
		samivl = *et >= __state->svbtim && *et < __state->svetim;
	    } else {
		samivl = *et >= __state->svbtim && *et <= __state->svetim;
	    }
	} else {

/*           We pick the first interval containing ET. For */
/*           all intervals but the first, ET must be */
/*           greater than the interval start time. */

	    if (__state->svmiix > 1) {
		samivl = *et > __state->svbtim && *et <= __state->svetim;
	    } else {
		samivl = *et >= __state->svbtim && *et <= __state->svetim;
	    }
	}
    }
    if (samseg && samivl) {

/*        We're looking at the same segment as last time, and the */
/*        interpolation interval we looked up last time is applicable */
/*        for the input time ET. */

/*        Simply restore the segment and interval parameters we */
/*        saved from the previous lookup. */

/*        We don't need to restore the segment start DAF address */
/*        BADDR, since we've already extracted it from DESCR. */

/*        Restore */

/*           - The mini-segment's packet directory count */
/*           - The mini-segment's packet directory base address */

	npkdir = __state->svpknd;
	pkdbas = __state->svpkdb;

/*        Restore */

/*           - The mini-segment/interval count */
/*           - The mini-segment/interval index */
/*           - The mini-segment/interval start pointer */

	n = __state->svn;
	miniix = __state->svmiix;
	minib = __state->svminb;

/*        Restore */

/*           - The mini-segment subtype */
/*           - The mini-segment packet size */
/*           - The mini-segment packet count */
/*           - The mini-segment window size */

	subtyp = __state->svstyp;
	pktsiz = __state->svpksz;
	npkt = __state->svnpkt;
	wndsiz = __state->svwnsz;
    } else {

/*        The segment and interval information for the current segment */
/*        must be looked up. */

/*        Perform checks on this segment. */

/*        Make sure that this really is a type 19 data segment. */

	if (type__ != 19) {
	    setmsg_(__global_state, "You are attempting to locate type * dat"
		    "a in a type 19 data segment.", (ftnlen)67);
	    errint_(__global_state, "*", &type__, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(WRONGSPKTYPE)", (ftnlen)19);
	    chkout_(__global_state, "SPKR19", (ftnlen)6);
	    return 0;
	}

/*        Locate the interpolation interval that contains the request */
/*        time. */

/*        Before getting started, we need to determine which interval to */
/*        use if the request time lies on a boundary between two */
/*        intervals. The segment's interval selection flag tells us how */
/*        to resolve this. */

	i__1 = eaddr - 1;
	dafgda_(__global_state, handle, &i__1, &eaddr, contrl);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "SPKR19", (ftnlen)6);
	    return 0;
	}
	isel = i_dnnt(&__global_state->f2c, contrl);
	n = i_dnnt(&__global_state->f2c, &contrl[1]);
	ivlsel = isel == 1;

/*        Determine the number of interval directory entries in the */
/*        segment. Note that for most SPK types, this computation is */
/*        performed by computing */

/*           ( N - 1 ) / DIRSIZ */

/*        where N is the segment's epoch count. */

/*        However the set of items in this case is a sequence */
/*        of N start times followed by a final stop time, so */
/*        the epoch count is */

/*           N + 1 */

/*        and the numerator in the ratio above is incremented by 1. */

	ndir = n / 100;

/*        Note that the directory placement scheme always leaves */
/*        a non-empty set of epochs following the last directory */
/*        entry. */

/*        Let DIRBAS be the base address of the interval directory. */
/*        We'll compute DIRBAS whether or not the interval directory */
/*        is non-empty. */

/*        If the interval directory is non-empty, it spans the address */
/*        range */

/*           DIRBAS+1 : DIRBAS+NDIR */

/*        We compute DIRBAS by starting at the end of the segment */
/*        and skipping over the control area, the mini-segment */
/*        start/stop pointers, and the interval directory itself. */

	dirbas = eaddr - 2 - (n + 1) - ndir;

/*        The way we search the directory depends on the treatment */
/*        of request times that lie on interval boundaries. */

	if (ivlsel) {

/*           If there is an interval directory, search it to determine */
/*           the group of interval times to search next. */

	    if (ndir > 0) {

/*              Find the last directory entry *less than or equal to* */
/*              the request time. The directory entry *after* that one, */
/*              if such exists, is the one to pick. */

		nread = min(ndir,101);
		bufbas = dirbas;

/*              Fetch the current batch of directory entries. */

		i__1 = bufbas + 1;
		i__2 = bufbas + nread;
		dafgda_(__global_state, handle, &i__1, &i__2, buffer);
		if (failed_(__global_state)) {
		    chkout_(__global_state, "SPKR19", (ftnlen)6);
		    return 0;
		}
		remain = ndir - nread;

/*              The variable NREAD always contains a positive value at */
/*              this point, so we can use it as an array index. */

		while(remain > 0 && buffer[(i__1 = nread - 1) < 101 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "buffer", 
			i__1, "spkr19_", (ftnlen)742)] <= *et) {
		    bufbas += nread;
		    nread = min(remain,101);

/*                 Fetch the current batch of directory entries. */

		    i__1 = bufbas + 1;
		    i__2 = bufbas + nread;
		    dafgda_(__global_state, handle, &i__1, &i__2, buffer);
		    if (failed_(__global_state)) {
			chkout_(__global_state, "SPKR19", (ftnlen)6);
			return 0;
		    }
		    remain -= nread;
		}

/*              Count the directory entries that are less than or equal */
/*              to ET. The number we skipped over before the final loop */
/*              iteration is BUFBAS-DIRBAS. The index of the group of */
/*              epochs containing ET exceeds the skipped directory count */
/*              by 1. */

		group = bufbas - dirbas + lstled_(__global_state, et, &nread, 
			buffer) + 1;
	    } else {

/*              There's no question about which group of epochs to */
/*              search. */

		group = 1;
	    }

/*           Let IVBAS be the base address of the sequence of interval */
/*           time bounds. */

	    ivbas = dirbas - (n + 1);

/*           Now find the index of the last interval boundary less than */
/*           or equal to ET. We'll need to read the current group of */
/*           epochs first, so compute the base of the range of addresses */
/*           containing this group. */
	    bufbas = ivbas + (group - 1) * 100;

/*           Compute the number of epochs to read. Note that all groups */
/*           of epochs except the last have DIRSIZ elements. */

	    remain = n + 1 - (group - 1) * 100;

/*           Note that REMAIN is always non-zero, since there's always */
/*           at least one epoch that exceeds the last directory entry. */

	    nread = min(100,remain);
	    i__1 = bufbas + 1;
	    i__2 = bufbas + nread;
	    dafgda_(__global_state, handle, &i__1, &i__2, buffer);
	    if (failed_(__global_state)) {
		chkout_(__global_state, "SPKR19", (ftnlen)6);
		return 0;
	    }

/*           Find the index of the first epoch greater than ET. The case */
/*           where ET matches the final epoch must be handled here, */
/*           since in this case no epoch exceeds ET. */

	    iveix = bufbas - ivbas + lstled_(__global_state, et, &nread, 
		    buffer) + 1;
/* Computing MIN */
	    i__1 = iveix, i__2 = n + 1;
	    iveix = min(i__1,i__2);

/*           Backstop test: */

	    if (iveix < 2) {
		setmsg_(__global_state, "IVEIX = #.", (ftnlen)10);
		errint_(__global_state, "#", &iveix, (ftnlen)1);
		sigerr_(__global_state, "SPICE(BUG)", (ftnlen)10);
		chkout_(__global_state, "SPKR19", (ftnlen)6);
		return 0;
	    }

/*           The epoch at index IVEIX is the end time of the */
/*           interpolation interval we'll use. The index of */
/*           the interval itself is IVEIX - 1. */

	    miniix = iveix - 1;
	} else {

/*           IVLSEL is .FALSE., meaning we must pick the first interval */
/*           containing the request time. */

/*           If there is an interval directory, search it to determine */
/*           the group of interval times to search next. */

	    if (ndir > 0) {

/*              Find the last directory entry *less than* the request */
/*              time. The directory entry *after* that one, if such */
/*              exists, is the one to pick. */

		nread = min(ndir,101);
		bufbas = dirbas;
		remain = ndir - nread;

/*              Fetch the current batch of directory entries. */

		i__1 = bufbas + 1;
		i__2 = bufbas + nread;
		dafgda_(__global_state, handle, &i__1, &i__2, buffer);
		if (failed_(__global_state)) {
		    chkout_(__global_state, "SPKR19", (ftnlen)6);
		    return 0;
		}

/*              The variable NREAD always contains a positive value at */
/*              this point, so we can use it as an array index. */

		while(remain > 0 && buffer[(i__1 = nread - 1) < 101 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "buffer", 
			i__1, "spkr19_", (ftnlen)877)] < *et) {
		    bufbas += nread;
		    nread = min(remain,101);

/*                 Fetch the current batch of directory entries. */

		    i__1 = bufbas + 1;
		    i__2 = bufbas + nread;
		    dafgda_(__global_state, handle, &i__1, &i__2, buffer);
		    if (failed_(__global_state)) {
			chkout_(__global_state, "SPKR19", (ftnlen)6);
			return 0;
		    }
		    remain -= nread;
		}

/*              Count the directory entries that are less than ET. The */
/*              number we skipped over before the final loop iteration */
/*              is BUFBAS-DIRBAS. The index of the group of epochs */
/*              containing ET exceeds the skipped directory count by 1. */

		group = bufbas - dirbas + lstltd_(__global_state, et, &nread, 
			buffer) + 1;
	    } else {

/*              There's no question about which group of epochs to */
/*              search. */

		group = 1;
	    }

/*           Let IVBAS be the base address of the sequence of interval */
/*           time bounds. */

	    ivbas = dirbas - (n + 1);

/*           Now find the index of the last interval epoch less than ET. */
/*           We'll need to read the current group of epochs first, so */
/*           compute the base of the range of addresses containing this */
/*           group. */
	    bufbas = ivbas + (group - 1) * 100;

/*           Compute the number of epochs to read. Note that all groups */
/*           of epochs except the last have DIRSIZ elements. */

	    remain = n + 1 - (group - 1) * 100;

/*           Note that REMAIN is always non-zero, since there's always */
/*           at least one epoch that exceeds the last directory entry. */

	    nread = min(100,remain);
	    i__1 = bufbas + 1;
	    i__2 = bufbas + nread;
	    dafgda_(__global_state, handle, &i__1, &i__2, buffer);
	    if (failed_(__global_state)) {
		chkout_(__global_state, "SPKR19", (ftnlen)6);
		return 0;
	    }

/*           Find the index of the last epoch less than ET. The case */
/*           where ET matches the first epoch must be handled here, */
/*           since in this case no epoch precedes ET. */

	    ivbix = bufbas - ivbas + lstltd_(__global_state, et, &nread, 
		    buffer);
	    ivbix = max(ivbix,1);

/*           Backstop test: */

	    if (ivbix > n) {
		setmsg_(__global_state, "IVBIX = #.", (ftnlen)10);
		errint_(__global_state, "#", &ivbix, (ftnlen)1);
		sigerr_(__global_state, "SPICE(BUG)", (ftnlen)10);
		chkout_(__global_state, "SPKR19", (ftnlen)6);
		return 0;
	    }

/*           The epoch at index IVBIX is the begin time of the */
/*           interpolation interval we'll use. The index of the interval */
/*           itself is also IVBIX. */

	    miniix = ivbix;
	}

/*        This is the end of the IF block that handles mini-segment */
/*        selection for the two possible values of IVLSEL. */

/*        Look up the begin and end pointers of the mini-segment at index */
/*        MINIIX. For the first N-1 mini-segments, the "end pointer" */
/*        of one mini-segment is the "begin" pointer of the next. */

	bufbas = eaddr - 2 - (n + 1) + (miniix - 1);
	i__1 = bufbas + 1;
	i__2 = bufbas + 2;
	dafgda_(__global_state, handle, &i__1, &i__2, buffer);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "SPKR19", (ftnlen)6);
	    return 0;
	}
	minib = i_dnnt(&__global_state->f2c, buffer) + baddr - 1;

/*        Note that the end of the current mini-segment */
/*        precedes the start of the next mini-segment by */
/*        one address. */

	minie = i_dnnt(&__global_state->f2c, &buffer[1]) + baddr - 2;

/*        Look up the time bounds of the mini-segment at index MINIIX. */
/*        These bounds are used quite a bit farther on, when we save */
/*        them for future use. */

	i__1 = ivbas + miniix;
	i__2 = ivbas + miniix + 1;
	dafgda_(__global_state, handle, &i__1, &i__2, mintim);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "SPKR19", (ftnlen)6);
	    return 0;
	}

/*        From this point onward, we'll work with the mini-segment */
/*        that occupies the address range MINIB : MINIE. */

/*        Look up the control area of the mini-segment. */

	i__1 = minie - 2;
	dafgda_(__global_state, handle, &i__1, &minie, contrl);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "SPKR19", (ftnlen)6);
	    return 0;
	}

/*        Fetch the control area parameters for the mini-segment. */

	subtyp = i_dnnt(&__global_state->f2c, contrl);
	wndsiz = i_dnnt(&__global_state->f2c, &contrl[1]);
	npkt = i_dnnt(&__global_state->f2c, &contrl[2]);
	if (subtyp < 0 || subtyp >= 3) {
	    setmsg_(__global_state, "Unexpected SPK type 19 subtype # found "
		    "in type 19 segment within mini-segment #.", (ftnlen)80);
	    errint_(__global_state, "#", &subtyp, (ftnlen)1);
	    errint_(__global_state, "#", &miniix, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(NOTSUPPORTED)", (ftnlen)19);
	    chkout_(__global_state, "SPKR19", (ftnlen)6);
	    return 0;
	}
	pktsiz = __state->pktszs[(i__1 = subtyp) < 3 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "pktszs", i__1, "spkr19_", (
		ftnlen)1047)];
	maxwnd = __state->mxwnsz[(i__1 = subtyp) < 3 && 0 <= i__1 ? i__1 : 
		s_rnge(&__global_state->f2c, "mxwnsz", i__1, "spkr19_", (
		ftnlen)1048)];

/*        Check the window size. */

	if (wndsiz < 2 || wndsiz > maxwnd) {
	    setmsg_(__global_state, "Window size in type 19 segment was #; m"
		    "ust be in the range 2:# for subtype #. Mini-segment inde"
		    "x is #.", (ftnlen)102);
	    errint_(__global_state, "#", &wndsiz, (ftnlen)1);
	    errint_(__global_state, "#", &maxwnd, (ftnlen)1);
	    errint_(__global_state, "#", &subtyp, (ftnlen)1);
	    errint_(__global_state, "#", &miniix, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(INVALIDVALUE)", (ftnlen)19);
	    chkout_(__global_state, "SPKR19", (ftnlen)6);
	    return 0;
	}
	if (odd_(__global_state, &wndsiz)) {
	    setmsg_(__global_state, "Window size in type 19 segment was #; m"
		    "ust be even for subtype #. Mini-segment index is #.", (
		    ftnlen)90);
	    errint_(__global_state, "#", &wndsiz, (ftnlen)1);
	    errint_(__global_state, "#", &subtyp, (ftnlen)1);
	    errint_(__global_state, "#", &miniix, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(INVALIDVALUE)", (ftnlen)19);
	    chkout_(__global_state, "SPKR19", (ftnlen)6);
	    return 0;
	}

/*        Compute the number of packet directory entries for */
/*        the current mini-segment/interval. */

	npkdir = (npkt - 1) / 100;

/*        Compute the base address of the sequence of packet */
/*        directory entries for the current mini-segment/interval. */

	pkdbas = minib - 1 + npkt * (pktsiz + 1);

/*        The test below is done for safety. No SPICE error s */
/*        should ever be detected at this point. */

	if (failed_(__global_state)) {
	    chkout_(__global_state, "SPKR19", (ftnlen)6);
	    return 0;
	}

/*        If we made it this far, we did so without a SPICE error. We */
/*        have valid segment parameters which can be saved for the next */
/*        call. */

/*        Save */

/*           - The DAF handle */
/*           - The segment begin DAF address */
/*           - The segment's "select last/first interval" flag */

	__state->svhan = *handle;
	__state->svbeg = baddr;
	__state->svlast = ivlsel;

/*        Save the time bounds of the applicable mini-segment/interval. */

	__state->svbtim = mintim[0];
	__state->svetim = mintim[1];

/*        Save */

/*           - The mini-segment/interval directory count */
/*           - The mini-segment/interval directory base address */

	__state->svpknd = npkdir;
	__state->svpkdb = pkdbas;

/*        Save */

/*           - The mini-segment/interval count */
/*           - The mini-segment/interval index */
/*           - The mini-segment/interval start pointer */

	__state->svn = n;
	__state->svmiix = miniix;
	__state->svminb = minib;

/*        Save */

/*           - The mini-segment subtype */
/*           - The mini-segment packet size */
/*           - The mini-segment packet count */
/*           - The mini-segment window size */

	__state->svstyp = subtyp;
	__state->svpksz = pktsiz;
	__state->svnpkt = npkt;
	__state->svwnsz = wndsiz;
    }

/*     We're ready to construct the output record. The first step is to */
/*     identify the indices of the packets and epochs corresponding to */
/*     the request. */

/*     We'll now select the set of packets that define the interpolating */
/*     polynomials.   We'll start out by finding the first directory */
/*     entry that is greater than or equal to the request epoch.  We'll */
/*     use the variable GROUP to indicate the set of epochs to search */
/*     within, once we've found the right directory entry. */

    if (npkdir == 0) {

/*        There's no mystery about which group of epochs to search. */

	group = 1;
    } else {

/*        There's at least one directory entry. Find the first directory */
/*        entry whose time is greater than or equal to the request time, */
/*        if there is such an entry.  We'll search linearly through the */
/*        directory entries, reading up to DIRSIZ of them at a time. */
/*        Having found the correct set of directory entries, we'll */
/*        perform a binary search within that set for the desired entry. */

	bufbas = pkdbas;
	nread = min(npkdir,100);
	remain = npkdir - nread;
	i__1 = bufbas + 1;
	i__2 = bufbas + nread;
	dafgda_(__global_state, handle, &i__1, &i__2, buffer);
	if (failed_(__global_state)) {
	    chkout_(__global_state, "SPKR19", (ftnlen)6);
	    return 0;
	}
	while(buffer[(i__1 = nread - 1) < 101 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "buffer", i__1, "spkr19_", (ftnlen)1196)]
		 < *et && remain > 0) {
	    bufbas += nread;
	    nread = min(remain,100);
	    remain -= nread;

/*           Note:  NREAD is always > 0 here. */

	    i__1 = bufbas + 1;
	    i__2 = bufbas + nread;
	    dafgda_(__global_state, handle, &i__1, &i__2, buffer);
	    if (failed_(__global_state)) {
		chkout_(__global_state, "SPKR19", (ftnlen)6);
		return 0;
	    }
	}

/*        At this point, BUFBAS - PKDBAS is the number of directory */
/*        entries preceding the one contained in BUFFER(1). */

	group = bufbas - pkdbas + lstltd_(__global_state, et, &nread, buffer) 
		+ 1;
    }

/*     GROUP now indicates the set of epochs in which to search for the */
/*     request epoch.  If GROUP is 1, the request time lies within the */
/*     inclusive time interval bounded by the first and last epochs of */
/*     the first group.  Otherwise, the request time lies in the time */
/*     interval bounded by the last element of the preceding group and */
/*     the last element of the current group. */

/*     We'll use the variable names BEGIDX and ENDIDX to refer to */
/*     the indices, relative to the set of time tags, of the first */
/*     and last time tags in the set we're going to look up. */

    if (group == 1) {
	begidx = 1;
	endidx = min(npkt,100);
    } else {

/*        If the group index is greater than 1, we'll include the last */
/*        time tag of the previous group in the set of time tags we look */
/*        up.  That way, the request time is bracketed by the time tag */
/*        set we look up. */

	begidx = (group - 1) * 100;
/* Computing MIN */
	i__1 = begidx + 100;
	endidx = min(i__1,npkt);
    }
    timbas = pkdbas - npkt;
    i__1 = timbas + begidx;
    i__2 = timbas + endidx;
    dafgda_(__global_state, handle, &i__1, &i__2, buffer);
    if (failed_(__global_state)) {
	chkout_(__global_state, "SPKR19", (ftnlen)6);
	return 0;
    }

/*     Find two adjacent epochs bounding the request epoch.  The request */
/*     time cannot be greater than all of epochs in the group, and it */
/*     cannot precede the first element of the group. */

    i__1 = endidx - begidx + 1;
    i__ = lstltd_(__global_state, et, &i__1, buffer);

/*     The variables LOW and high are the indices of a pair of time */
/*     tags that bracket the request time. */

    if (i__ == 0) {
	low = 1;
    } else {
	low = begidx + i__ - 1;
    }
    high = low + 1;

/*     Now select the set of packets used for interpolation.  Note */
/*     that the window size is known to be even. */

/*     Unlike SPK types 8, 9, 12, and 13, for type 19 we allow the */
/*     window size to shrink when the window must be truncated due to */
/*     proximity to an interval boundary. */

/*     The nominal bracketing epochs we've found are the (WNDSIZ/2)nd */
/*     and (WNDSIZ/2 + 1)st of the interpolating set.  If the */
/*     request time is too close to one end of the coverage interval, */
/*     we reduce the window size, after which one endpoint of the */
/*     window will coincide with an endpoint of the coverage interval. */

/*     Let LSIZE be the size of the "left half" of the window:  the */
/*     size set of window epochs to the left of the request time. */
/*     We want this size to be WNDSIZ/2, but if not enough states are */
/*     available, the set ranges from index 1 to index LOW. */

/* Computing MIN */
    i__1 = wndsiz / 2;
    lsize = min(i__1,low);

/*     RSIZE is defined analogously for the right half of the window. */

/* Computing MIN */
    i__1 = wndsiz / 2, i__2 = npkt - high + 1;
    rsize = min(i__1,i__2);

/*     The actual window size is simply the sum of LSIZE and RSIZE. */

    nrcpkt = lsize + rsize;

/*     FIRST and LAST are the endpoints of the range of indices of */
/*     time tags (and packets) we'll collect in the output record. */

    first = low - lsize + 1;
    last = first + nrcpkt - 1;

/*     We're ready to construct the output record. */

/*     Put the subtype and window size into the output record. */

    record[0] = (doublereal) subtyp;
    record[1] = (doublereal) nrcpkt;

/*     Read the packets. */

    i__1 = minib + (first - 1) * pktsiz;
    i__2 = minib + last * pktsiz - 1;
    dafgda_(__global_state, handle, &i__1, &i__2, &record[2]);

/*     Finally, add the epochs to the output record. */
/*     Read the sequence of time tags. */

    bufbas = minib - 1 + npkt * pktsiz + (first - 1);
    i__1 = bufbas + 1;
    i__2 = bufbas + nrcpkt;
    dafgda_(__global_state, handle, &i__1, &i__2, &record[nrcpkt * pktsiz + 2]
	    );
    if (failed_(__global_state)) {
	chkout_(__global_state, "SPKR19", (ftnlen)6);
	return 0;
    }

/*     The call was successful. Record this fact so that saved */
/*     interval data are available for re-use. */

    __state->svok = TRUE_;
    chkout_(__global_state, "SPKR19", (ftnlen)6);
    return 0;
} /* spkr19_ */

