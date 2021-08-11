/* cknm06.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern cknm06_init_t __cknm06_init;
static cknm06_state_t* get_cknm06_state() {
	cspice_t* state =  __cspice_get_state();
	if (!state->cknm06)
		state->cknm06 = __cspice_allocate_module(sizeof(
	cknm06_state_t), &__cknm06_init, sizeof(__cknm06_init));
	return state->cknm06;

}

/* $Procedure CKNM06 ( C-kernel, number of mini-segments, type 06 ) */
/* Subroutine */ int cknm06_(integer *handle, doublereal *descr, integer *
	nmini)
{
    /* Builtin functions */
    integer i_dnnt(doublereal *);

    /* Local variables */
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    extern /* Subroutine */ int dafus_(doublereal *, integer *, integer *, 
	    doublereal *, integer *);
    extern /* Subroutine */ int dafgda_(integer *, integer *, integer *, 
	    doublereal *);
    doublereal dc[2];
    integer ic[6];
    extern logical failed_(void);
    doublereal dpdata[1];
    extern /* Subroutine */ int sigerr_(char *, ftnlen);
    extern /* Subroutine */ int chkout_(char *, ftnlen);
    extern /* Subroutine */ int setmsg_(char *, ftnlen);
    extern /* Subroutine */ int errint_(char *, integer *, ftnlen);
    extern logical return_(void);


    /* Module state */
    cknm06_state_t* __state = get_cknm06_state();
/* $ Abstract */

/*     Given the handle of a CK file and the descriptor of a type 6 */
/*     segment in that file, return the number of mini-segments */
/*     in the segment. */

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
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   The handle of the file containing the segment. */
/*     DESCR      I   The descriptor of the type 6 segment. */
/*     NMINI      O   The number of pointing instances in the segment. */

/* $ Detailed_Input */

/*     HANDLE     is the handle of the binary CK file containing the */
/*                segment. Normally the CK file should be open for */
/*                read access. See the Files section below for details. */

/*     DESCR      The DAF descriptor of a CK data type 6 segment. */

/* $ Detailed_Output */

/*     NMINI      The number of mini-segments in the CK segment */
/*                identified by HANDLE and DESCR. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the segment indicated by DESCR is not a type 6 segment, */
/*         the error 'SPICE(CKWRONGDATATYPE)' is signaled. */

/*     2)  If the specified handle does not belong to any DAF file that */
/*         is currently known to be open, an error is diagnosed by a */
/*         routine that this routine calls. */

/*     3)  If DESCR is not a valid descriptor of a valid segment in the */
/*         CK file specified by HANDLE, the results of this routine are */
/*         unpredictable. */

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

/*     For a complete description of the internal structure of a type 6 */
/*     segment, see the CK required reading. */

/*     This routine returns the number of discrete pointing instances */
/*     contained in the specified segment. It is normally used in */
/*     conjunction with CKMN06, which returns mini-segment parameters, */
/*     and with CKGR06, which returns a specified pointing instance */
/*     from a mini-segment. */

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

/*     number of mini-segments in ck type_6 segment */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */

/*        ND         is the number of double precision components in an */
/*                   unpacked C-kernel descriptor. */

/*        NI         is the number of integer components in an unpacked */
/*                   C-kernel descriptor. */

/*        DTYPE      is the data type of the segment that this routine */
/*                   operates on. */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    }
    chkin_("CKNM06", (ftnlen)6);

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


    dafus_(descr, &__state->c__2, &__state->c__6, dc, ic);

/*     If this segment is not of data type 6, then signal an error. */

    if (ic[2] != 6) {
	setmsg_("Data type of the segment should be 6: Passed descriptor sho"
		"ws type = #.", (ftnlen)71);
	errint_("#", &ic[2], (ftnlen)1);
	sigerr_("SPICE(CKWRONGDATATYPE)", (ftnlen)22);
	chkout_("CKNM06", (ftnlen)6);
	return 0;
    }

/*     The number of mini-segments is the final word in the segment. */

    dafgda_(handle, &ic[5], &ic[5], dpdata);
    if (failed_()) {
	chkout_("CKNM06", (ftnlen)6);
	return 0;
    }
    *nmini = i_dnnt(dpdata);
    chkout_("CKNM06", (ftnlen)6);
    return 0;
} /* cknm06_ */

