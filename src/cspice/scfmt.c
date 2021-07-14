/* scfmt.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* $Procedure      SCFMT ( Convert SCLK "ticks" to character clock format) */
/* Subroutine */ int scfmt_(integer *sc, doublereal *ticks, char *clkstr, 
	ftnlen clkstr_len)
{
    integer type__;
    extern /* Subroutine */ int scfm01_(integer *, doublereal *, char *, 
	    ftnlen), chkin_(char *, ftnlen), sigerr_(char *, ftnlen), chkout_(
	    char *, ftnlen), setmsg_(char *, ftnlen), errint_(char *, integer 
	    *, ftnlen);
    extern integer sctype_(integer *);
    extern logical return_(void);

/* $ Abstract */

/*     Convert encoded spacecraft clock ticks to character clock format. */

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

/*     SCLK */

/* $ Keywords */

/*     CONVERSION */
/*     TIME */

/* $ Declarations */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     SC         I   NAIF spacecraft identification code. */
/*     TICKS      I   Encoded representation of a spacecraft clock count. */
/*     CLKSTR     O   Character representation of a clock count. */

/* $ Detailed_Input */

/*     SC         is the NAIF ID number for the spacecraft whose clock's */
/*                time is being decoded. */

/*     TICKS      is the double precision encoding of a clock time in */
/*                units of ticks.  Partition information is not reflected */
/*                in this value. */

/*                An analogy may be drawn between a spacecraft clock and */
/*                a standard wall clock.  The number of ticks */
/*                corresponding to the wall clock string */

/*                                     hh:mm:ss */

/*                would be the number of seconds represented by that */
/*                time. */

/*                For example, */

/*                         Clock string    Number of ticks */
/*                         ------------    --------------- */
/*                           00:00:10             10 */
/*                           00:01:00             60 */
/*                           00:10:00            600 */
/*                           01:00:00           3600 */
/*                           01:01:00           3660 */

/*                If TICKS contains a fractional part the result is the */
/*                same as if TICKS had been rounded to the nearest whole */
/*                number. */

/*                See the Examples section below for examples of */
/*                actual spacecraft clock conversions. */

/* $ Detailed_Output */

/*     CLKSTR     is the spacecraft clock character string */
/*                corresponding to TICKS.  Partition information is */
/*                not included in CLKSTR. */

/*                Using Galileo as an example, the full format clock */
/*                string is */

/*                               wwwwwwww:xx:y:z */

/*                where z is a mod-8 counter (values 0-7) which */
/*                increments approximately once every 8 1/3 ms., y is a */
/*                mod-10 counter (values 0-9) which increments once */
/*                every time z turns over, i.e., approximately once every */
/*                66 2/3 ms., xx is a mod-91 (values 0-90) counter */
/*                which increments once every time y turns over, i.e., */
/*                once every 2/3 seconds. wwwwwwww is the Real-Time Image */
/*                Count (RIM), which increments once every time xx turns */
/*                over, i.e., once every 60 2/3 seconds. The roll-over */
/*                expression for the RIM is 16777215, which corresponds */
/*                to approximately 32 years. */

/*                wwwwwwww, xx, y, and z are referred to interchangeably */
/*                as the fields or components of the spacecraft clock. */
/*                SCLK components may be separated by any of these five */
/*                characters: ' '  ':'  ','  '-'  '.' */
/*                The delimiter used is determined by a kernel pool */
/*                variable and can be adjusted by the user. */

/*                Some spacecraft clock components have offset, or */
/*                starting, values different from zero.  For example, */
/*                with an offset value of 1, a mod 20 counter would */
/*                cycle from 1 to 20 instead of from 0 to 19. */

/*                See the SCLK required reading for a detailed */
/*                description of the Voyager and Mars Observer clock */
/*                formats. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If the data type for the spacecraft is not supported */
/*        then the error SPICE(NOTSUPPORTED) is signalled. */

/*     2) If the value for TICKS is negative, the error is diagnosed */
/*        by routines called by this routine. */

/*     3) If the SCLK kernel file does not contain data for the */
/*        spacecraft specified by SC, then the error is diagnosed */
/*        by routines called by this routine. */

/*     4) If the declared length of SCLKCH is not large enough to */
/*        contain the output clock string the error */
/*        is diagnosed by a routine called by this routine. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine determines which data type the spacecraft clock */
/*     belongs to and then calls FMTnn, where nn corresponds to the */
/*     data type code.  FMTnn then handles the actual conversion from */
/*     ticks to clock string format. */

/*     The routine SCTIKS performs the inverse operation to SCFMT, */
/*     converting from clock format to number of ticks. */

/*     Note the important difference between SCFMT and SCDECD. SCDECD */
/*     converts some number of ticks since the spacecraft clock start */
/*     time to a character string which includes a partition number. */
/*     SCFMT, which is called by SCDECD, does not make use of partition */
/*     information. */

/* $ Examples */


/*     The following program fragment finds partition start and stop */
/*     times for the Galileo spacecraft from a spacecraft clock partition */
/*     kernel file, called SCLK.KER. Since those times are always */
/*     returned in units of ticks, the program uses SCFMT to print the */
/*     times in Galileo clock format. */


/*     CHARACTER*(30)        START */
/*     CHARACTER*(30)        STOP */

/*     SC = -77 */

/*     CALL FURNSH ( 'SCLK.KER' ) */

/*     CALL SCPART ( SC, NPARTS, PSTART, PSTOP ) */

/*     DO I = 1, NPARTS */

/*        CALL SCFMT ( SC, PSTART( I ), START ) */
/*        CALL SCFMT ( SC, PSTOP ( I ), STOP  ) */

/*        WRITE (*,*) */
/*        WRITE (*,*) 'Partition ', I, ':' */
/*        WRITE (*,*) 'Start = ', START */
/*        WRITE (*,*) 'Stop  = ', STOP */

/*     END DO */



/*      Below are some examples illustrating various input numbers of */
/*      ticks and the resulting clock string outputs for the Galileo */
/*      spacecraft. */

/*         TICKS                 CLKSTR */
/*         ----------------      -------------------- */
/*         -1                    Error: Ticks must be a positive number */
/*         0                     '0:00:0:0' */
/*         1                     '0:00:0:1' */
/*         1.3                   '0:00:0:1' */
/*         1.5                   '0:00:0:2' */
/*         2                     '0:00:0:2' */
/*         7                     '0:00:0:7' */
/*         8                     '0:00:1:0' */
/*         80                    '0:01:0:0' */
/*         88                    '0:01:1:0' */
/*         7279                  '0:90:9:7' */
/*         7280                  '1:00:0:0' */
/*         1234567890            '169583:45:6:2' */

/*     The following examples are for the Voyager 2 spacecraft. */
/*     Note that the third component of the Voyager clock has an */
/*     offset value of one. */

/*         TICKS                 CLKSTR */
/*         ----------------      -------------------- */
/*         -1                    Error: Ticks must be a positive number */
/*         0                     '00000 00 001' */
/*         1                     '00000 00 002' */
/*         1.3                   '00000:00:002' */
/*         1.5                   '00000.00.003' */
/*         2                     '00000-00-003' */
/*         799                   '00000,00,800' */
/*         800                   '00000 01 001' */
/*         47999                 '00000 59 800' */
/*         48000                 '00001 00 001' */
/*         3145727999            '65535 59 800' */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     J.M. Lynch     (JPL) */
/*     R.E. Thurman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.2, 22-AUG-2006 (EDW) */

/*        Replaced references to LDPOOL with references */
/*        to FURNSH. */

/* -    SPICELIB Version 1.0.1, 17-APR-1992 (JML) (WLT) */

/*        The exceptions section was updated to state that an error */
/*        is signalled if SCLKCH is not declared big enough to */
/*        contain the output spacecraft clock string. */

/*        The wording to exception number three was changed. */

/*        Miscellaneous minor updates to the header were performed. */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 06-SEP-1990 (JML) (RET) */

/* -& */
/* $ Index_Entries */

/*     convert spacecraft_clock ticks to character clock format */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    } else {
	chkin_("SCFMT", (ftnlen)5);
    }

/*     If the clock type is supported by NAIF then call FMTnn. */

    type__ = sctype_(sc);
    if (type__ == 1) {
	scfm01_(sc, ticks, clkstr, clkstr_len);
    } else {
	setmsg_("Clock type # is not supported. ", (ftnlen)31);
	errint_("#", &type__, (ftnlen)1);
	sigerr_("SPICE(NOTSUPPORTED)", (ftnlen)19);
	chkout_("SCFMT", (ftnlen)5);
	return 0;
    }
    chkout_("SCFMT", (ftnlen)5);
    return 0;
} /* scfmt_ */

