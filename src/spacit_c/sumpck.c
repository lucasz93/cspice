/* sumpck.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__2 = 2;
static integer c__6 = 6;
static integer c__5 = 5;
static integer c__9 = 9;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__0 = 0;

/* $Procedure      SUMPCK ( Summarize an PCK file ) */
/* Subroutine */ int sumpck_(integer *handle, char *binfnm, char *lpsfnm, 
	logical *logfil, integer *loglun, ftnlen binfnm_len, ftnlen 
	lpsfnm_len)
{
    /* Initialized data */

    static char menutl[20] = "PCK Summary Options ";
    static char menuvl[20*5] = "QUIT                " "Skip                " 
	    "ENTIRE_FILE         " "BY_BODY_ID          " "BY_TIME_INTERVAL "
	    "   ";
    static char menutx[40*5] = "Quit, returning to main menu.           " 
	    "Skip                                    " "Summarize entire fil"
	    "e.                  " "Summarize by NAIF body ID code.         " 
	    "Summarize by time interval.             ";
    static char menunm[1*5] = "Q" "." "F" "B" "T";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rnge(char *, integer, char *, integer), s_cmp(char *, char *, 
	    ftnlen, ftnlen), s_wsle(cilist *), e_wsle(void), do_lio(integer *,
	     integer *, char *, ftnlen);

    /* Local variables */
    static logical done;
    static char line[255];
    extern integer cardd_(doublereal *);
    static doublereal beget;
    static char segid[40];
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    static doublereal endet;
    extern /* Subroutine */ int repmc_(char *, char *, char *, char *, ftnlen,
	     ftnlen, ftnlen, ftnlen);
    static char separ[80];
    static logical found;
    extern /* Subroutine */ int repmi_(char *, char *, integer *, char *, 
	    ftnlen, ftnlen, ftnlen), reset_(void);
    static logical error;
    extern integer rtrim_(char *, ftnlen);
    extern /* Subroutine */ int utc2et_(char *, doublereal *, ftnlen), 
	    et2utc_(doublereal *, char *, integer *, char *, ftnlen, ftnlen), 
	    daffna_(logical *);
    extern logical failed_(void);
    static integer segbad;
    extern /* Subroutine */ int dafbfs_(integer *);
    static integer segead;
    extern /* Subroutine */ int scardd_(integer *, doublereal *);
    static integer segbod;
    static logical segfnd;
    static char begutc[32];
    static integer bodyid;
    extern /* Subroutine */ int cnfirm_(char *, logical *, ftnlen), getchr_(
	    char *, char *, logical *, logical *, char *, ftnlen, ftnlen, 
	    ftnlen);
    static logical haveit;
    static char endutc[32];
    static integer segfrm;
    static doublereal segbtm, segetm;
    static logical anyseg;
    static doublereal segint[8];
    extern /* Subroutine */ int getint_(char *, integer *, logical *, logical 
	    *, char *, ftnlen, ftnlen), pckgss_(char *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, integer *, 
	    ftnlen), chkout_(char *, ftnlen);
    static char errmsg[320], option[20], sumsep[80];
    extern logical return_(void);
    static char fnmout[255];
    static integer menuop, segtyp;
    static char lpsout[255];
    static doublereal intrvl[8], intsct[8];
    static char tmpstr[80];
    static logical contnu, tryagn;
    extern /* Subroutine */ int ssized_(integer *, doublereal *), writln_(
	    char *, integer *, ftnlen), getopt_(char *, integer *, char *, 
	    char *, integer *, ftnlen, ftnlen, ftnlen), wninsd_(doublereal *, 
	    doublereal *, doublereal *), wnintd_(doublereal *, doublereal *, 
	    doublereal *), pckwss_(integer *, char *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, ftnlen);
    static char typout[255];

    /* Fortran I/O blocks */
    static cilist io___22 = { 0, 6, 0, 0, 0 };
    static cilist io___23 = { 0, 6, 0, 0, 0 };
    static cilist io___24 = { 0, 6, 0, 0, 0 };
    static cilist io___25 = { 0, 6, 0, 0, 0 };
    static cilist io___26 = { 0, 6, 0, 0, 0 };
    static cilist io___27 = { 0, 6, 0, 0, 0 };
    static cilist io___28 = { 0, 6, 0, 0, 0 };
    static cilist io___29 = { 0, 6, 0, 0, 0 };
    static cilist io___31 = { 0, 6, 0, 0, 0 };
    static cilist io___32 = { 0, 6, 0, 0, 0 };
    static cilist io___33 = { 0, 6, 0, 0, 0 };
    static cilist io___35 = { 0, 6, 0, 0, 0 };
    static cilist io___36 = { 0, 6, 0, 0, 0 };
    static cilist io___37 = { 0, 6, 0, 0, 0 };
    static cilist io___38 = { 0, 6, 0, 0, 0 };
    static cilist io___40 = { 0, 6, 0, 0, 0 };
    static cilist io___41 = { 0, 6, 0, 0, 0 };
    static cilist io___42 = { 0, 6, 0, 0, 0 };
    static cilist io___43 = { 0, 6, 0, 0, 0 };
    static cilist io___45 = { 0, 6, 0, 0, 0 };
    static cilist io___46 = { 0, 6, 0, 0, 0 };
    static cilist io___47 = { 0, 6, 0, 0, 0 };
    static cilist io___48 = { 0, 6, 0, 0, 0 };
    static cilist io___50 = { 0, 6, 0, 0, 0 };


/* $ Abstract */

/*     Summarize an PCK file. */

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

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     HANDLE     I   Handle of the PCK file to be summarized. */
/*     LOGFIL     I   Write the summary to a log file and to screen? */
/*     LOGLUN     I   Logical unit connected to the log file. */
/*     NDC        P   Number of d.p. components in PCK descriptor. */
/*     NIC        P   Number of integer components in PCK descriptor. */
/*     NC         P   Size of packed PCK descriptor. */
/*     IDSIZ      P   Length of PCK segment identifier. */
/*     LBCELL     P   Lower bound for the SPICELIB CELL data structure. */

/* $ Detailed_Input */

/*     HANDLE     is the integer handle of the PCK file to be summarized. */

/*     LOGFIL     if TRUE means that the summary will be written to */
/*                a log file as well as displayed on the terminal */
/*                screen.  Otherwise, the summary will not be written */
/*                to a file. */

/*     UNIT       is the logical unit connected to a log file to which */
/*                the summary is to be written if LOGFIL is TRUE. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     NDC        is the number of double precision components in an */
/*                unpacked PCK descriptor. */

/*     NIC        is the number of integer components in an unpacked */
/*                PCK descriptor. */

/*     NC         is the size of a packed PCK descriptor. */

/*     IDSIZ      is the length of an PCK segment identifier. */

/*     LBCELL     is the lower bound for the SPICELIB CELL data */
/*                structure. */

/* $ Exceptions */

/*     None. */

/* $ Files */

/*     The PCK file to be summarized is referred throughout this routine */
/*     by its handle. The file should already be opened for read. */

/* $ Particulars */



/* $ Restrictions */



/* $ Author_and_Institution */

/*     K.R. Gehringer  (JPL) */
/*     M.J. Spencer    (JPL) */
/*     J.E. McLean     (JPL) */
/*     R.E. Thurman    (JPL) */

/* $ Version */


/* -    Beta Version 2.0.0  21-JUL-1995 (KRG) */

/*        Added several arguments to the call of this subroutine and */
/*        made other modifications to allow it to perform its own */
/*        formatting of the summary, including filenames and separators. */

/* -& */
/* $ Index_Entries */

/*      summarize the segments in a binary pck file */

/* -& */

/*     SPICELIB functions */


/*     Local Parameters */

/*     Set value for a separator */


/*     Set up the ID code prompt. */


/*     Set up the UTC time string prompt. */


/*     Set up labels for various output things. */


/*     Set the length for a line of text. */


/*     Set the length for an output line. */


/*     Set the length for an error message. */


/*     Set the length for a UTC time string. */


/*     Set the precision for the fractional part of UTC times. */


/*     Set a length for the option values. */


/*     Set a length for the title of a menu. */


/*     Set the length of the text description of an option on a menu. */


/*     The number of options available on the main menu. */


/*     Parameter for the standard output unit. */


/*     Local variables */


/*     Save everything to keep configuration control happy. */


/*     Initial Values */


/*     Define the menu title ... */


/*     Define the menu option values ... */


/*     Define the menu descriptive text for each option ... */


/*     Define the menu option names ... */


/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    } else {
	chkin_("SUMPCK", (ftnlen)6);
    }

/*     Initialize the separator. */

    s_copy(separ, "*********************************************************"
	    "***********************", (ftnlen)80, (ftnlen)80);

/*     Initialize the segment separator. */

    s_copy(sumsep, "--------------------------------------------------------"
	    "------------------------", (ftnlen)80, (ftnlen)80);

/*     Set the sizes of the window cells that we will use if the file */
/*     is to be summarized by time. */

    ssized_(&c__2, intrvl);
    ssized_(&c__2, segint);
    ssized_(&c__2, intsct);

/*     Initialize a few things before we start. */

    bodyid = 0;
    done = FALSE_;
    while(! done) {

/*        Initialize those things we reuse on every iteration. */

	contnu = TRUE_;
	writln_(" ", &c__6, (ftnlen)1);
	getopt_(menutl, &c__5, menunm, menutx, &menuop, (ftnlen)20, (ftnlen)1,
		 (ftnlen)40);
	if (failed_()) {
	    contnu = FALSE_;
	}
	if (contnu) {

/*           Perform all of the setup necessary to perform the summary. */
/*           This include prompting for input values required, etc. */

	    repmc_("Summary for PCK file: #", "#", binfnm, fnmout, (ftnlen)23,
		     (ftnlen)1, binfnm_len, (ftnlen)255);
	    repmc_("Leapseconds File    : #", "#", lpsfnm, lpsout, (ftnlen)23,
		     (ftnlen)1, lpsfnm_len, (ftnlen)255);
	    s_copy(option, menuvl + ((i__1 = menuop - 1) < 5 && 0 <= i__1 ? 
		    i__1 : s_rnge("menuvl", i__1, "sumpck_", (ftnlen)367)) * 
		    20, (ftnlen)20, (ftnlen)20);
	    if (s_cmp(option, "QUIT", (ftnlen)20, (ftnlen)4) == 0) {
		contnu = FALSE_;
		done = TRUE_;
	    } else if (s_cmp(option, "ENTIRE_FILE", (ftnlen)20, (ftnlen)11) ==
		     0) {

/*              Summarize the entire file. Write the type */
/*              of summary to the log file if we need to. */


/*              Summarize the entire file. */

		repmc_("Summary Type        : #", "#", "Entire File", typout, 
			(ftnlen)23, (ftnlen)1, (ftnlen)11, (ftnlen)255);
	    } else if (s_cmp(option, "BY_BODY_ID", (ftnlen)20, (ftnlen)10) == 
		    0) {

/*              Summarize for a specified body. */

/*              First, we need to get the body ID code. */

		s_copy(errmsg, " ", (ftnlen)320, (ftnlen)1);
		haveit = FALSE_;
		tryagn = TRUE_;
		while(tryagn) {
		    error = FALSE_;
		    s_wsle(&io___22);
		    e_wsle();
		    s_wsle(&io___23);
		    do_lio(&c__9, &c__1, "Enter the desired NAIF body ID cod"
			    "e.", (ftnlen)36);
		    e_wsle();
		    s_wsle(&io___24);
		    e_wsle();
		    getint_("ID code? ", &bodyid, &haveit, &error, errmsg, (
			    ftnlen)9, (ftnlen)320);
		    if (! haveit || error) {
			if (error) {
			    s_wsle(&io___25);
			    e_wsle();
			    s_wsle(&io___26);
			    do_lio(&c__9, &c__1, errmsg, rtrim_(errmsg, (
				    ftnlen)320));
			    e_wsle();
			}
			if (! haveit) {
			    s_wsle(&io___27);
			    e_wsle();
			    s_wsle(&io___28);
			    do_lio(&c__9, &c__1, "A NAIF body ID code must b"
				    "e entered for this option.", (ftnlen)52);
			    e_wsle();
			}
			if (! haveit || error) {
			    s_wsle(&io___29);
			    e_wsle();
			    cnfirm_("Try Again? (Yes/No) ", &tryagn, (ftnlen)
				    20);
			    if (! tryagn) {
				contnu = FALSE_;
			    }
			}
		    } else {
			tryagn = FALSE_;
		    }
		}

/*              Write the type of summary to the log file if we need to. */

		if (contnu) {
		    s_copy(tmpstr, "By segments for body: #", (ftnlen)80, (
			    ftnlen)23);
		    repmc_("Summary Type        : #", "#", tmpstr, typout, (
			    ftnlen)23, (ftnlen)1, (ftnlen)80, (ftnlen)255);
		    repmi_(typout, "#", &bodyid, typout, (ftnlen)255, (ftnlen)
			    1, (ftnlen)255);
		}
	    } else if (s_cmp(option, "BY_TIME_INTERVAL", (ftnlen)20, (ftnlen)
		    16) == 0) {

/*              Summarize for given time interval. */

/*              First, we need to get the UTC time string for the */
/*              begin time. */

		s_copy(errmsg, " ", (ftnlen)320, (ftnlen)1);
		haveit = FALSE_;
		tryagn = TRUE_;
		while(tryagn) {
		    error = FALSE_;
		    s_wsle(&io___31);
		    e_wsle();
		    s_wsle(&io___32);
		    do_lio(&c__9, &c__1, "Enter the desired beginning UTC ti"
			    "me.", (ftnlen)37);
		    e_wsle();
		    s_wsle(&io___33);
		    e_wsle();
		    getchr_("UTC time? ", begutc, &haveit, &error, errmsg, (
			    ftnlen)10, (ftnlen)32, (ftnlen)320);
		    if (! haveit || error) {
			if (error) {
			    s_wsle(&io___35);
			    e_wsle();
			    s_wsle(&io___36);
			    do_lio(&c__9, &c__1, errmsg, rtrim_(errmsg, (
				    ftnlen)320));
			    e_wsle();
			}
			if (! haveit) {
			    s_wsle(&io___37);
			    e_wsle();
			    s_wsle(&io___38);
			    do_lio(&c__9, &c__1, "A beginning UTC time strin"
				    "g must be entered for this option.", (
				    ftnlen)60);
			    e_wsle();
			}
		    } else {
			tryagn = FALSE_;
		    }

/*                 We now have the beginning time in UTC, so attempt */
/*                 to convert it to ET. If the conversion fails, we */
/*                 need to immediately reset the error handling so that */
/*                 we can continue processing. Remember, we are in a */
/*                 menuing subroutine, and we are not allowed to exit */
/*                 on an error: we must go back to the menu. thus the */
/*                 need for a resetting of the error handler here. If */
/*                 we got to here, there were no errors, so as long as */
/*                 we maintain that status, everything will be hunky */
/*                 dory. We also convert the ET back into UTC to get */
/*                 a consistent format for display. */

		    if (haveit) {
			utc2et_(begutc, &beget, (ftnlen)32);
			et2utc_(&beget, "C", &c__3, begutc, (ftnlen)1, (
				ftnlen)32);
			if (failed_()) {
			    reset_();
			    error = TRUE_;
			}
		    }

/*                 Check to see if they want to try and enter the */
/*                 beginning UTC time string again. */

		    if (! haveit || error) {
			s_wsle(&io___40);
			e_wsle();
			cnfirm_("Try Again? (Yes/No) ", &tryagn, (ftnlen)20);
			if (! tryagn) {
			    contnu = FALSE_;
			}
		    }
		}
/*              Now, if we can, we need to get the UTC time string for */
/*              the end time. */

		if (contnu) {
		    s_copy(errmsg, " ", (ftnlen)320, (ftnlen)1);
		    haveit = FALSE_;
		    tryagn = TRUE_;
		    while(tryagn) {
			error = FALSE_;
			s_wsle(&io___41);
			e_wsle();
			s_wsle(&io___42);
			do_lio(&c__9, &c__1, "Enter the desired ending UTC t"
				"ime.", (ftnlen)34);
			e_wsle();
			s_wsle(&io___43);
			e_wsle();
			getchr_("UTC time? ", endutc, &haveit, &error, errmsg,
				 (ftnlen)10, (ftnlen)32, (ftnlen)320);
			if (! haveit || error) {
			    if (error) {
				s_wsle(&io___45);
				e_wsle();
				s_wsle(&io___46);
				do_lio(&c__9, &c__1, errmsg, rtrim_(errmsg, (
					ftnlen)320));
				e_wsle();
			    }
			    if (! haveit) {
				s_wsle(&io___47);
				e_wsle();
				s_wsle(&io___48);
				do_lio(&c__9, &c__1, "An ending UTC time str"
					"ing must be entered for this option.",
					 (ftnlen)58);
				e_wsle();
			    }
			} else {
			    tryagn = FALSE_;
			}

/*                    We now have the ending time in UTC, so attempt */
/*                    to convert it to ET. If the conversion fails, we */
/*                    need to immediately reset the error handling so */
/*                    that we can continue processing. Remember, we are */
/*                    in a menuing subroutine, and we are not allowed */
/*                    to exit on an error: we must go back to the menu. */
/*                    thus the need for a resetting of the error handler */
/*                    here. If we got to here, there were no errors, so */
/*                    as long as we maintain that status, everything */
/*                    will be hunky dory. We also convert the ET back */
/*                    into UTC to get a consistent format for display. */

			if (haveit) {
			    utc2et_(endutc, &endet, (ftnlen)32);
			    et2utc_(&endet, "C", &c__3, endutc, (ftnlen)1, (
				    ftnlen)32);
			    if (failed_()) {
				reset_();
				error = TRUE_;
			    }
			}

/*                    Check to see if they want to try and enter the */
/*                    ending UTC time string again. */

			if (! haveit || error) {
			    s_wsle(&io___50);
			    e_wsle();
			    cnfirm_("Try Again? (Yes/No) ", &tryagn, (ftnlen)
				    20);
			    if (! tryagn) {
				contnu = FALSE_;
			    }
			} else {
			    tryagn = FALSE_;
			}
		    }
		}

/*              Create an interval out of the begin and end ET times, */
/*              if we can. */

		if (contnu) {
		    scardd_(&c__0, intrvl);
		    wninsd_(&beget, &endet, intrvl);
		    if (failed_()) {
			contnu = FALSE_;
		    }
		}

/*              Write the type of summary to the output file, if we can. */

		if (contnu) {
		    s_copy(tmpstr, "By # Time Interval #", (ftnlen)80, (
			    ftnlen)20);
		    repmc_("Summary Type        : #", "#", tmpstr, typout, (
			    ftnlen)23, (ftnlen)1, (ftnlen)80, (ftnlen)255);
		    repmc_(typout, "#", "UTC", typout, (ftnlen)255, (ftnlen)1,
			     (ftnlen)3, (ftnlen)255);
		    repmc_(typout, "#", "(#, #)", typout, (ftnlen)255, (
			    ftnlen)1, (ftnlen)6, (ftnlen)255);
		    repmc_(typout, "#", begutc, typout, (ftnlen)255, (ftnlen)
			    1, (ftnlen)32, (ftnlen)255);
		    repmc_(typout, "#", endutc, typout, (ftnlen)255, (ftnlen)
			    1, (ftnlen)32, (ftnlen)255);
		}
	    }

/*           Now, if we can, search through the file from the beginning. */
/*           Keep track of whether or not any segments satisfy the search */
/*           criteria. */

	    if (contnu) {
		writln_(" ", &c__6, (ftnlen)1);
		writln_(separ, &c__6, (ftnlen)80);
		writln_(" ", &c__6, (ftnlen)1);
		writln_(fnmout, &c__6, (ftnlen)255);
		writln_(lpsout, &c__6, (ftnlen)255);
		writln_(typout, &c__6, (ftnlen)255);
		writln_(" ", &c__6, (ftnlen)1);
		if (*logfil) {
		    writln_(" ", loglun, (ftnlen)1);
		    writln_(separ, loglun, (ftnlen)80);
		    writln_(" ", loglun, (ftnlen)1);
		    writln_(fnmout, loglun, (ftnlen)255);
		    writln_(lpsout, loglun, (ftnlen)255);
		    writln_(typout, loglun, (ftnlen)255);
		    writln_(" ", loglun, (ftnlen)1);
		}
		anyseg = FALSE_;
		dafbfs_(handle);
		daffna_(&found);
		while(found && contnu) {

/*                 On each iteration of the loop, we have not found */
/*                 anything initially. */

		    segfnd = FALSE_;
		    scardd_(&c__0, intsct);
		    scardd_(&c__0, segint);

/*                 Get the summary for the curent segment. */

		    pckgss_(segid, &segbod, &segfrm, &segtyp, &segbtm, &
			    segetm, &segbad, &segead, (ftnlen)40);

/*                 Check to see if the current segment satisfies the */
/*                 current search criteria. */

		    if (s_cmp(option, "ENTIRE_FILE", (ftnlen)20, (ftnlen)11) 
			    == 0) {
			segfnd = TRUE_;
		    } else if (s_cmp(option, "BY_BODY_ID", (ftnlen)20, (
			    ftnlen)10) == 0) {
			segfnd = bodyid == segbod;
		    } else if (s_cmp(option, "BY_TIME_INTERVAL", (ftnlen)20, (
			    ftnlen)16) == 0) {

/*                    Create an interval out of the epochs in the */
/*                    segment. */

			wninsd_(&segbtm, &segetm, segint);

/*                    Intersect it with the input interval. */

			wnintd_(segint, intrvl, intsct);
			if (failed_()) {
			    reset_();
			    contnu = FALSE_;
			} else {
			    segfnd = cardd_(intsct) > 0;
			}
		    }
		    if (contnu && segfnd) {
			anyseg = TRUE_;

/*                    Display the segment. */

			writln_(sumsep, &c__6, (ftnlen)80);
			if (*logfil) {
			    writln_(sumsep, loglun, (ftnlen)80);
			}
			pckwss_(&c__6, segid, &segbod, &segfrm, &segtyp, &
				segbtm, &segetm, (ftnlen)40);
			if (*logfil) {
			    pckwss_(loglun, segid, &segbod, &segfrm, &segtyp, 
				    &segbtm, &segetm, (ftnlen)40);
			}
			writln_(sumsep, &c__6, (ftnlen)80);
			if (*logfil) {
			    writln_(sumsep, loglun, (ftnlen)80);
			}
		    }

/*                 Find that next segment. */

		    daffna_(&found);
		    if (failed_()) {
			contnu = FALSE_;
		    }
		}
	    }

/*           Better say something if no segments were matching the */
/*           search criteria were found. */

	    if (contnu && ! anyseg) {
		s_copy(line, "No matching segments were found.", (ftnlen)255, 
			(ftnlen)32);
		writln_(line, &c__6, (ftnlen)255);
		if (*logfil) {
		    writln_(line, loglun, (ftnlen)255);
		}
	    }
	    if (contnu) {
		writln_(" ", &c__6, (ftnlen)1);
		writln_(separ, &c__6, (ftnlen)80);
		writln_(" ", &c__6, (ftnlen)1);
		if (*logfil) {
		    writln_(" ", loglun, (ftnlen)1);
		    writln_(separ, loglun, (ftnlen)80);
		    writln_(" ", loglun, (ftnlen)1);
		}
	    }
	}

/*        Reset the error handling if anything failed during the search */
/*        time conversions, or window building. */

	if (failed_()) {
	    reset_();
	}
    }
    chkout_("SUMPCK", (ftnlen)6);
    return 0;
} /* sumpck_ */

