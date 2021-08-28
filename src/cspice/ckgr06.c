/* ckgr06.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern ckgr06_init_t __ckgr06_init;
static inline ckgr06_state_t* get_ckgr06_state(cspice_t* state) {
	if (!state->ckgr06)
		state->ckgr06 = __cspice_allocate_module(sizeof(
	ckgr06_state_t), &__ckgr06_init, sizeof(__ckgr06_init));
	return state->ckgr06;

}

/* $Procedure CKGR06 ( C-kernel, get record, type 06 ) */
/* Subroutine */ int ckgr06_(cspice_t* __global_state, integer *handle, 
	doublereal *descr, integer *msno, integer *recno, doublereal *record)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer i_dnnt(f2c_state_t*, doublereal *), s_rnge(f2c_state_t*, char *, 
	    integer, char *, integer);

    /* Local variables */
    integer nrec;
    doublereal rate;
    integer baddr;
    integer eaddr;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer minib;
    integer minie;
    extern /* Subroutine */ int dafus_(cspice_t*, doublereal *, integer *, 
	    integer *, doublereal *, integer *);
    extern /* Subroutine */ int dafgda_(cspice_t*, integer *, integer *, 
	    integer *, doublereal *);
    doublereal dc[2];
    integer ic[6];
    extern logical failed_(cspice_t*);
    doublereal dpdata[1];
    integer epcbas;
    integer epaddr;
    integer bufbas;
    doublereal buffer[4];
    integer nepdir;
    integer ptrbas;
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    integer nintvl;
    extern logical return_(cspice_t*);
    integer pktsiz;
    integer subtyp;


    /* Module state */
    ckgr06_state_t* __state = get_ckgr06_state(__global_state);
/* $ Abstract */

/*     Given the handle and descriptor of a type 6 segment in a CK file, */
/*     return a specified pointing record from that segment. */

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

/*     CK */
/*     DAF */

/* $ Keywords */

/*     POINTING */

/* $ Declarations */
/* $ Abstract */

/*     Declare parameters specific to CK type 06. */

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

/*     CK */

/* $ Keywords */

/*     CK */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman      (JPL) */
/*     B.V. Semenov      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 10-MAR-2014 (NJB) (BVS) */

/* -& */

/*     Maximum polynomial degree supported by the current */
/*     implementation of this CK type. */


/*     Integer code indicating `true': */


/*     Integer code indicating `false': */


/*     CK type 6 subtype codes: */


/*     Subtype 0:  Hermite interpolation, 8-element packets. Quaternion */
/*                 and quaternion derivatives only, no angular velocity */
/*                 vector provided. Quaternion elements are listed */
/*                 first, followed by derivatives. Angular velocity is */
/*                 derived from the quaternions and quaternion */
/*                 derivatives. */


/*     Subtype 1:  Lagrange interpolation, 4-element packets. Quaternion */
/*                 only. Angular velocity is derived by differentiating */
/*                 the interpolating polynomials. */


/*     Subtype 2:  Hermite interpolation, 14-element packets. */
/*                 Quaternion and angular angular velocity vector, as */
/*                 well as derivatives of each, are provided. The */
/*                 quaternion comes first, then quaternion derivatives, */
/*                 then angular velocity and its derivatives. */


/*     Subtype 3:  Lagrange interpolation, 7-element packets. Quaternion */
/*                 and angular velocity vector provided.  The quaternion */
/*                 comes first. */


/*     Number of subtypes: */


/*     Packet sizes associated with the various subtypes: */


/*     Maximum packet size for type 6: */


/*     Minimum packet size for type 6: */


/*     The CKPFS record size declared in ckparam.inc must be at least as */
/*     large as the maximum possible size of a CK type 6 record. */

/*     The largest possible CK type 6 record has subtype 3 (note that */
/*     records of subtype 2 have half as many epochs as those of subtype */
/*     3, for a given polynomial degree). A subtype 3 record contains */

/*        - The evaluation epoch */
/*        - The subtype and packet count */
/*        - MAXDEG+1 packets of size C06PS3 */
/*        - MAXDEG+1 time tags */


/*     End of file ck06.inc. */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   The handle of the file containing the segment. */
/*     DESCR      I   The segment descriptor. */
/*     MSNO       I   Index of the mini-segment containing the record. */
/*     RECNO      I   Index of the pointing record to be returned. */
/*     RECORD     O   The pointing record. */

/* $ Detailed_Input */

/*     HANDLE     is the handle of the binary CK file containing the */
/*                segment. Normally the CK file should be open for read */
/*                access. See the Files section below for details. */

/*     DESCR      is the DAF descriptor of the type 6 segment. */

/*     RECNO      is the number of the discrete pointing instance to be */
/*                returned from the specified type 6 segment. */

/* $ Detailed_Output */

/*     RECORD     is the pointing record indexed by RECNO in the */
/*                segment. The contents are as follows: */

/*                   RECORD( 1 ) = CLKOUT */

/*                CLKOUT is the encoded spacecraft clock time associated */
/*                with the returned pointing values. */

/*                   RECORD( 2 ) = SUBTYP */

/*                SUBTYP is the CK type 6 subtype code. This code */
/*                identifies the structure and meaning of the rest */
/*                of the record. However, all subtypes have a */
/*                quaternion stored in elements 4-7. */

/*                   RECORD( 3 ) = RATE */

/*                RATE is the nominal SCLK rate expressed in units of */
/*                seconds per tick. This rate is required to convert */
/*                quaternion or angular velocity derivatives from units */
/*                of radians/tick to radians/s. */

/*                   RECORD( 4 ) = q0 */
/*                   RECORD( 5 ) = q1 */
/*                   RECORD( 6 ) = q2 */
/*                   RECORD( 7 ) = q3 */

/*                Subtype 1 ends here; there are no angular velocity */
/*                data. Angular velocity is derived by differentiating */
/*                Lagrange interpolating polynomials. */

/*                   RECORD(  8 ) =  ] */
/*                   RECORD(  9 ) =  ] --- For subtypes 0 and 2, these */
/*                   RECORD( 10 ) =  ]     elements contain a quaternion */
/*                   RECORD( 11 ) =  ]     derivative. For subtype 3, */
/*                                         elements 8-10 contain an */
/*                                         angular velocity vector; */
/*                                         element 11 is unassigned. */

/*                                         All subtypes except subtype */
/*                                         2 stop here. */

/*                   RECORD( 12 ) =  ] */
/*                   RECORD( 13 ) =  ] --- For subtype 2, these */
/*                   RECORD( 14 ) =  ]     elements contain an angular */
/*                                         velocity vector. */


/*                   RECORD( 15 ) =  ] */
/*                   RECORD( 16 ) =  ] --- For subtype 2, these */
/*                   RECORD( 17 ) =  ]     elements contain the */
/*                                         derivative of an angular */
/*                                         velocity vector. */

/*                The quantities q0 - q3 are the components of the */
/*                quaternion that represents the C-matrix that transforms */
/*                vectors from the inertial reference frame of the */
/*                segment to the instrument frame at time CLKOUT. */

/*                Quaternion derivatives, angular velocity, or the */
/*                derivative of angular velocity are valid only if */
/*                these are supported by the segment subtype and */
/*                if the segment descriptor indicates that angular */
/*                velocity is present. */

/*                The components of the angular velocity vector are */
/*                specified relative to the inertial reference frame of */
/*                the segment. */

/*                Units of angular velocity and of quaternion */
/*                derivatives are radians/second and 1/second */
/*                respectively. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the segment is not of data type 6, the error */
/*         SPICE(CKWRONGDATATYPE) is signaled. */

/*     2)  If MSNO is less than one or greater than the number of */
/*         mini-segments in the specified segment, the error */
/*         SPICE(INDEXOUTOFRANGE) is signaled. */

/*     3)  If RECNO is less than one or greater than the number of */
/*         records in the specified segment, the error */
/*         SPICE(CKNONEXISTREC) is signaled. */

/*     4)  If the specified handle does not belong to any DAF file that */
/*         is currently known to be open, an error is diagnosed by a */
/*         routine in the call tree of this routine. */

/*     5)  If DESCR is not a valid descriptor of a valid segment in the */
/*         CK file specified by HANDLE, the results of this routine are */
/*         unpredictable. */

/*     6)  If the segment subtype is not recognized, the error */
/*         SPICE(NOTSUPPORTED) is signaled. */

/* $ Files */

/*     The CK file specified by HANDLE may be open for read or write */
/*     access. Normally, the file should have been opened for read */
/*     access. If the file is open for write access, the calling */
/*     application must ensure integrity of the CK segment being read. */
/*     If the structure of the segment is invalid---for example, if the */
/*     segment has been partially written---this routine will either */
/*     return invalid results, or it will cause a system-level runtime */
/*     error. */

/* $ Particulars */

/*     Note that the mini-segment interpolation window size is not */
/*     returned in the pointing record; this parameter is not required */
/*     in order to interpret the record. Call CKMP06 to obtain the */
/*     window size. */

/*     For a complete description of the internal structure of a type 6 */
/*     segment, see the CK Required Reading. */

/*     This routine is normally used in conjunction with CKNM06 and */
/*     CKGM06 to obtain time tags and packet data from a specified type */
/*     6 CK segment. */

/* $ Examples */

/*     The numerical results shown for this example may differ across */
/*     platforms. The results depend on the SPICE kernels used as */
/*     input, the compiler and supporting libraries, and the machine */
/*     specific arithmetic implementation. */


/*     1) The following program dumps records from a CK file that */
/*        contains only type 6 segments. */

/*        Example code begins here. */


/*             PROGRAM GREX1 */
/*             IMPLICIT NONE */
/*       C */
/*       C     Dump all records from a CK that */
/*       C     contains only segments of type 6. */
/*       C */

/*             INCLUDE 'ck06.inc' */
/*       C */
/*       C     Local parameters */
/*       C */
/*             INTEGER               ND */
/*             PARAMETER           ( ND     = 2 ) */

/*             INTEGER               NI */
/*             PARAMETER           ( NI     = 6 ) */

/*             INTEGER               DSCSIZ */
/*             PARAMETER           ( DSCSIZ = 5 ) */

/*             INTEGER               FILSIZ */
/*             PARAMETER           ( FILSIZ = 255 ) */

/*       C */
/*       C     RECSIZ is the size of the largest pointing */
/*       C     record, which corresponds to subtype 2. */
/*       C */
/*             INTEGER               RECSIZ */
/*             PARAMETER           ( RECSIZ = C06PS2 + 3 ) */

/*       C */
/*       C     Local variables */
/*       C */
/*             CHARACTER*(FILSIZ)    CK */

/*             DOUBLE PRECISION      DC     ( ND ) */
/*             DOUBLE PRECISION      DESCR  ( DSCSIZ ) */
/*             DOUBLE PRECISION      IVLBDS ( 2 ) */
/*             DOUBLE PRECISION      LSTEPC */
/*             DOUBLE PRECISION      RATE */
/*             DOUBLE PRECISION      RECORD ( RECSIZ ) */

/*             INTEGER               DTYPE */
/*             INTEGER               HANDLE */
/*             INTEGER               IC     ( NI ) */
/*             INTEGER               RECNO */
/*             INTEGER               MSNO */
/*             INTEGER               NMINI */
/*             INTEGER               NREC */
/*             INTEGER               SEGNO */
/*             INTEGER               SUBTYP */
/*             INTEGER               WINSIZ */

/*             LOGICAL               FOUND */


/*             CALL PROMPT ( 'Enter name of CK to dump > ', CK ) */

/*             CALL DAFOPR ( CK, HANDLE ) */
/*       C */
/*       C     Dump data from each CK segment. */
/*       C */
/*             SEGNO = 0 */

/*             CALL DAFBFS ( HANDLE ) */
/*             CALL DAFFNA ( FOUND  ) */

/*             DO WHILE ( FOUND ) */

/*                SEGNO = SEGNO + 1 */

/*                WRITE (*,*) ' ' */
/*                WRITE (*,*) ' ' */
/*                WRITE (*,*) 'Segment number: ', SEGNO */

/*       C */
/*       C        Fetch and unpack the descriptor of the */
/*       C        current segment; check the data type. */
/*       C */
/*                CALL DAFGS ( DESCR ) */
/*                CALL DAFUS ( DESCR, ND, NI, DC, IC ) */

/*                DTYPE = IC(3) */

/*                IF ( DTYPE .NE. 6 ) THEN */

/*                   CALL SETMSG ( 'Data type must be 6 but was #.' ) */
/*                   CALL ERRINT ( '#',  DTYPE                      ) */
/*                   CALL SIGERR ( 'SPICE(NOTSUPPORTED)'            ) */

/*                END IF */
/*       C */
/*       C        Get the mini-segment count for this */
/*       C        segment. */
/*       C */
/*                CALL CKNM06 ( HANDLE, DESCR, NMINI ) */
/*       C */
/*       C        Dump data from each mini-segment. */
/*       C */
/*                DO MSNO = 1, NMINI */
/*       C */
/*       C           Get the mini-segment's record count */
/*       C           and time bounds. */
/*       C */
/*                   CALL CKMP06 ( HANDLE, DESCR, MSNO,   RATE,  SUBTYP, */
/*            .                    WINSIZ, NREC,  IVLBDS, LSTEPC        ) */

/*                   WRITE (*,*) ' ' */
/*                   WRITE (*,*) '   Mini-segment number: ', MSNO */
/*                   WRITE (*,*) '      Rate:           ',   RATE */
/*                   WRITE (*,*) '      Subtype:        ',   SUBTYP */
/*                   WRITE (*,*) '      Window size:    ',   WINSIZ */
/*                   WRITE (*,*) '      Interval start: ',   IVLBDS(1) */
/*                   WRITE (*,*) '      Interval stop:  ',   IVLBDS(2) */
/*                   WRITE (*,*) '      Last epoch:     ',   LSTEPC */
/*                   WRITE (*,*) ' ' */

/*                   DO RECNO = 1, NREC */

/*                      CALL CKGR06 ( HANDLE, DESCR, */
/*            .                       MSNO,   RECNO,  RECORD ) */

/*                      WRITE (*,*) '      Record number: ', RECNO */
/*                      WRITE (*,*) '         SCLKDP:     ', RECORD(1) */
/*                      WRITE (*,*) '         Clock rate: ', RECORD(3) */

/*                      IF ( SUBTYP .EQ. C06TP0 ) THEN */

/*                         WRITE (*,*) '         Q(0): ', RECORD(4) */
/*                         WRITE (*,*) '         Q(1): ', RECORD(5) */
/*                         WRITE (*,*) '         Q(2): ', RECORD(6) */
/*                         WRITE (*,*) '         Q(3): ', RECORD(7) */
/*                         WRITE (*,*) '    d Q(0)/dt: ', RECORD(8) */
/*                         WRITE (*,*) '    d Q(1)/dt: ', RECORD(9) */
/*                         WRITE (*,*) '    d Q(2)/dt: ', RECORD(10) */
/*                         WRITE (*,*) '    d Q(3)/dt: ', RECORD(11) */

/*                      ELSE IF ( SUBTYP .EQ. C06TP1 ) THEN */

/*                         WRITE (*,*) '         Q(0): ', RECORD(4) */
/*                         WRITE (*,*) '         Q(1): ', RECORD(5) */
/*                         WRITE (*,*) '         Q(2): ', RECORD(6) */
/*                         WRITE (*,*) '         Q(3): ', RECORD(7) */

/*                      ELSE IF ( SUBTYP .EQ. C06TP2 ) THEN */

/*                         WRITE (*,*) '         Q(0): ', RECORD(4) */
/*                         WRITE (*,*) '         Q(1): ', RECORD(5) */
/*                         WRITE (*,*) '         Q(2): ', RECORD(6) */
/*                         WRITE (*,*) '         Q(3): ', RECORD(7) */
/*                         WRITE (*,*) '    d Q(0)/dt: ', RECORD(8) */
/*                         WRITE (*,*) '    d Q(1)/dt: ', RECORD(9) */
/*                         WRITE (*,*) '    d Q(2)/dt: ', RECORD(10) */
/*                         WRITE (*,*) '    d Q(3)/dt: ', RECORD(11) */
/*                         WRITE (*,*) '        AV(1): ', RECORD(12) */
/*                         WRITE (*,*) '        AV(2): ', RECORD(13) */
/*                         WRITE (*,*) '        AV(3): ', RECORD(14) */
/*                         WRITE (*,*) '   d AV(1)/dt: ', RECORD(15) */
/*                         WRITE (*,*) '   d AV(2)/dt: ', RECORD(16) */
/*                         WRITE (*,*) '   d AV(3)/dt: ', RECORD(17) */

/*                      ELSE IF ( SUBTYP .EQ. C06TP3 ) THEN */

/*                         WRITE (*,*) '         Q(0): ', RECORD(4) */
/*                         WRITE (*,*) '         Q(1): ', RECORD(5) */
/*                         WRITE (*,*) '         Q(2): ', RECORD(6) */
/*                         WRITE (*,*) '         Q(3): ', RECORD(7) */
/*                         WRITE (*,*) '        AV(1): ', RECORD(8) */
/*                         WRITE (*,*) '        AV(2): ', RECORD(9) */
/*                         WRITE (*,*) '        AV(3): ', RECORD(10) */

/*                      ELSE */
/*                         CALL SETMSG ( 'Subtype # is not ' */
/*            .            //            'recognized.'         ) */
/*                         CALL ERRINT ( '#', SUBTYP           ) */
/*                         CALL SIGERR ( 'SPICE(NOTSUPPORTED)' ) */
/*                      END IF */

/*                      WRITE (*,*) ' ' */

/*                  END DO */

/*                END DO */

/*                CALL DAFFNA ( FOUND ) */

/*             END DO */

/*             END */


/*     An initial portion of the output created by this program, when */
/*     the program was executed on a PC/Linux/gfortran platform, for */
/*     a sample CK containing type 6 segments, is shown below: */


/*        Segment number:            1 */

/*           Mini-segment number:            1 */
/*              Rate:             1.52587890625000000E-005 */
/*              Subtype:                   1 */
/*              Window size:              10 */
/*              Interval start:    11288914762710.869 */
/*              Interval stop:     11290384616127.203 */
/*              Last epoch:        11290384616127.203 */

/*              Record number:            1 */
/*                 SCLKDP:        11288914762710.869 */
/*                 Clock rate:   1.52587890625000000E-005 */
/*                 Q(0):   0.46164827229286126 */
/*                 Q(1):  -0.70575355403199758 */
/*                 Q(2):  -0.29319084125475281 */
/*                 Q(3):  -0.45036865373250068 */

/*              Record number:            2 */
/*                 SCLKDP:        11288998883607.230 */
/*                 Clock rate:   1.52587890625000000E-005 */
/*                 Q(0):   0.46162099825988423 */
/*                 Q(1):  -0.70570932104748119 */
/*                 Q(2):  -0.29323821047130305 */
/*                 Q(3):  -0.45043507864268195 */

/*              Record number:            3 */
/*                 SCLKDP:        11289077342579.063 */
/*                 Clock rate:   1.52587890625000000E-005 */
/*                 Q(0):   0.46159435700379842 */
/*                 Q(1):  -0.70566850733850173 */
/*                 Q(2):  -0.29328062251407311 */
/*                 Q(3):  -0.45049870564815003 */


/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman     (JPL) */
/*     J.M. Lynch       (JPL) */
/*     B.V. Semenov     (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 14-MAR-2014 (NJB) (JML) (BVS) */

/* -& */
/* $ Index_Entries */

/*     get ck type_6 record */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */

/*        ND         is the number of double precision components in an */
/*                   unpacked C-kernel descriptor. */

/*        NI         is the number of integer components in an unpacked */
/*                   C-kernel descriptor. */

/*        DTYPE      is the data type of the segment that this routine */
/*                   operates on. */


/*     Mini-segment control area size: */


/*     Local variables */


/*     Saved variables */


/*     Initial values */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "CKGR06", (ftnlen)6);

/*     The number of discrete pointing instances contained in a data */
/*     type 6 segment is stored in the last double precision word of the */
/*     segment. Since the address of the last word is stored in the */
/*     sixth integer component of the segment descriptor, it is a */
/*     trivial matter to extract the count. */

/*     The unpacked descriptor contains the following information */
/*     about the segment: */

/*        DC(1)  Initial encoded SCLK */
/*        DC(2)  Final encoded SCLK */

/*        IC(1)  CK frame class ID (aka "instrument") */
/*        IC(2)  Inertial reference frame */
/*        IC(3)  Data type */
/*        IC(4)  Angular velocity flag */
/*        IC(5)  Initial address of segment data */
/*        IC(6)  Final address of segment data */


    dafus_(__global_state, descr, &__state->c__2, &__state->c__6, dc, ic);

/*     If this segment is not of data type 6, then signal an error. */

    if (ic[2] != 6) {
	setmsg_(__global_state, "Data type of the segment should be 6: Passe"
		"d descriptor shows type = #.", (ftnlen)71);
	errint_(__global_state, "#", &ic[2], (ftnlen)1);
	sigerr_(__global_state, "SPICE(CKWRONGDATATYPE)", (ftnlen)22);
	chkout_(__global_state, "CKGR06", (ftnlen)6);
	return 0;
    }

/*     Check the mini-segment index. */

/*     The number of mini-segments is the final word in the segment. */

    baddr = ic[4];
    eaddr = ic[5];
    dafgda_(__global_state, handle, &eaddr, &eaddr, dpdata);
    if (failed_(__global_state)) {
	chkout_(__global_state, "CKGR06", (ftnlen)6);
	return 0;
    }
    nintvl = i_dnnt(&__global_state->f2c, dpdata);
    if (*msno < 1 || *msno > nintvl) {
	setmsg_(__global_state, "Mini-segment index must be in range 1:# but"
		" was #.", (ftnlen)50);
	errint_(__global_state, "#", &nintvl, (ftnlen)1);
	errint_(__global_state, "#", msno, (ftnlen)1);
	sigerr_(__global_state, "SPICE(INDEXOUTOFRANGE)", (ftnlen)22);
	chkout_(__global_state, "CKGR06", (ftnlen)6);
	return 0;
    }

/*     Set the base address of the mini-segment pointers. There */
/*     are NINTVL+1 pointers, and these precede the control area. */

    ptrbas = eaddr - 2 - (nintvl + 1);

/*     Compute the mini-segment pointers as absolute */
/*     DAF addresses. The stored value is a relative address. */

    bufbas = ptrbas + *msno - 1;
    i__1 = bufbas + 1;
    i__2 = bufbas + 2;
    dafgda_(__global_state, handle, &i__1, &i__2, buffer);
    if (failed_(__global_state)) {
	chkout_(__global_state, "CKGR06", (ftnlen)6);
	return 0;
    }
    minib = baddr - 1 + i_dnnt(&__global_state->f2c, buffer);
    minie = baddr - 1 + i_dnnt(&__global_state->f2c, &buffer[1]) - 1;

/*     Fetch the control area of the mini-segment. */

    bufbas = minie - 4;
    i__1 = bufbas + 1;
    i__2 = bufbas + 4;
    dafgda_(__global_state, handle, &i__1, &i__2, buffer);
    if (failed_(__global_state)) {
	chkout_(__global_state, "CKGR06", (ftnlen)6);
	return 0;
    }

/*     Fetch the SCLK rate (seconds per tick), mini-segment */
/*     subtype, and record count. */

    rate = buffer[0];
    subtyp = i_dnnt(&__global_state->f2c, &buffer[1]);
    nrec = i_dnnt(&__global_state->f2c, &buffer[3]);

/*     Compute the packet size for this mini-segment. This will */
/*     be used a bit later. We'll also check the subtype. */

    if (subtyp < 0 || subtyp > 3) {
	setmsg_(__global_state, "Unexpected CK type 6 subtype # found in min"
		"i-segment #.", (ftnlen)55);
	errint_(__global_state, "#", &subtyp, (ftnlen)1);
	errint_(__global_state, "#", msno, (ftnlen)1);
	sigerr_(__global_state, "SPICE(NOTSUPPORTED)", (ftnlen)19);
	chkout_(__global_state, "CKGR06", (ftnlen)6);
	return 0;
    }
    pktsiz = __state->pktszs[(i__1 = subtyp) < 4 && 0 <= i__1 ? i__1 : s_rnge(
	    &__global_state->f2c, "pktszs", i__1, "ckgr06_", (ftnlen)686)];

/*     Check the record index. */

    if (*recno < 1 || *recno > nrec) {
	setmsg_(__global_state, "Record index must be in range 1:# but was #."
		, (ftnlen)44);
	errint_(__global_state, "#", &nrec, (ftnlen)1);
	errint_(__global_state, "#", recno, (ftnlen)1);
	sigerr_(__global_state, "SPICE(CKNONEXISTREC)", (ftnlen)20);
	chkout_(__global_state, "CKGR06", (ftnlen)6);
	return 0;
    }

/*     The epochs of the mini-segment precede the */
/*     mini-segment's control area and the epoch directories. */

    nepdir = (nrec - 1) / 100;
    epcbas = minie - 4 - nepdir - nrec;

/*     Fetch the mini-segment's epoch at index RECNO into */
/*     element 1 of the output record. */

    epaddr = epcbas + *recno;
    dafgda_(__global_state, handle, &epaddr, &epaddr, record);

/*     Transfer the subtype and rate to the output record. */

    record[1] = (doublereal) subtyp;
    record[2] = rate;

/*     Locate the data packet at index RECNO. */

    bufbas = minib - 1 + (*recno - 1) * pktsiz;
    i__1 = bufbas + 1;
    i__2 = bufbas + pktsiz;
    dafgda_(__global_state, handle, &i__1, &i__2, &record[3]);

/*     The record is complete if DAFGDA did its job. We don't */
/*     check FAILED here since we're about to return. */

    chkout_(__global_state, "CKGR06", (ftnlen)6);
    return 0;
} /* ckgr06_ */

