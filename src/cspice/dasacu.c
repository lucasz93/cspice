/* dasacu.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern dasacu_init_t __dasacu_init;
static inline dasacu_state_t* get_dasacu_state(cspice_t* state) {
	if (!state->dasacu)
		state->dasacu = __cspice_allocate_module(sizeof(
	dasacu_state_t), &__dasacu_init, sizeof(__dasacu_init));
	return state->dasacu;

}

/* $Procedure      DASACU ( DAS add comments from a logical unit ) */
/* Subroutine */ int dasacu_(cspice_t* __global_state, integer *comlun, char *
	begmrk, char *endmrk, logical *insbln, integer *handle, ftnlen 
	begmrk_len, ftnlen endmrk_len)
{
    /* System generated locals */
    integer i__1, i__2, i__3;
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
    integer f_open(f2c_state_t*, olist *);
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen), f_clos(
	    f2c_state_t*, cllist *), s_rnge(f2c_state_t*, char *, integer, 
	    char *, integer), f_rew(f2c_state_t*, alist *);

    /* Local variables */
    char line[255];
    logical more;
    integer i__;
    integer j;
    extern /* Subroutine */ int dasac_(cspice_t*, integer *, integer *, char *
	    , ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    integer ncomc;
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    integer ncomr;
    extern /* Subroutine */ int ljust_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern logical failed_(cspice_t*);
    extern /* Subroutine */ int readla_(cspice_t*, integer *, integer *, 
	    integer *, char *, logical *, ftnlen);
    char ifname[60];
    extern /* Subroutine */ int readln_(cspice_t*, integer *, char *, logical 
	    *, ftnlen);
    char combuf[255*22];
    extern /* Subroutine */ int dassih_(cspice_t*, integer *, char *, ftnlen);
    extern integer lastnb_(cspice_t*, char *, ftnlen);
    integer length;
    integer intchr;
    char idword[8];
    extern /* Subroutine */ int dasrfr_(cspice_t*, integer *, char *, char *, 
	    integer *, integer *, integer *, integer *, ftnlen, ftnlen);
    extern /* Subroutine */ int errfnm_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    integer numcom;
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    integer nresvc;
    extern /* Subroutine */ int getlun_(cspice_t*, integer *);
    integer iostat;
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    integer scrlun;
    extern /* Subroutine */ int writla_(cspice_t*, integer *, char *, integer 
	    *, ftnlen);
    extern logical return_(cspice_t*);
    integer nresvr;
    logical eof;


    /* Module state */
    dasacu_state_t* __state = get_dasacu_state(__global_state);
/* $ Abstract */

/*     Add comments to a previously opened binary DAS file from a */
/*     previously opened text file attached to a Fortran logical unit. */

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

/*     None. */

/* $ Keywords */

/*     None. */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*      COMLUN    I   Logical unit of the open comment text file. */
/*      BEGMRK    I   The begin comments marker in the comment text file. */
/*      ENDMRK    I   The end comments marker in the comment text file. */
/*      INSBLN    I   A flag indicating whether to insert a blank line. */
/*      HANDLE    I   Handle of a DAS file opened with write access. */
/*      LNSIZE    P   Maximum length of comment line. */

/* $ Detailed_Input */

/*     COMLUN   The Fortran logical unit of a previously opened text */
/*              file which contains comments that are to be added to */
/*              the comment area of a binary E-Kernel file. */

/*     BEGMRK   A marker which identifies the beginning of the comments */
/*              in the comment text file. This marker must appear on a */
/*              line by itself, and leading and trailing blanks are not */
/*              significant. */

/*              The line immediately following this marker is the first */
/*              comment line to be placed into the comment area of the */
/*              binary DAS file. */

/*              If the begin marker is blank, BEGMRK .EQ. ' ', then the */
/*              comments are assumed to start at the current location */
/*              in the comment text file. */

/*     ENDMRK   A marker which identifies the end of the comments in the */
/*              comment text file. This marker must appear on a line by */
/*              itself, and leading and trailing blanks are not */
/*              significant. */

/*              The line immediately preceding this marker is the last */
/*              comment line to be placed into the comment area of the */
/*              binary DAS file. */

/*              If the end marker is blank, ENDMRK .EQ. ' ', then the */
/*              comments are assumed to stop at the end of the comment */
/*              text file. */

/*     INSBLN   A logical flag which indicates whether a blank line is */
/*              to be inserted into the comment area of the binary DAS */
/*              file attached to HANDLE before any comments are added */
/*              to the comment area of the DAS file. This is to provide */
/*              a simple mechanism for separating any comments already */
/*              contained in the comment area of a DAS file from those */
/*              comments that are being added. */

/*              If the comment area of a binary DAS file is empty, the */
/*              value of this flag is not significant, the comments will */
/*              simply be placed into the comment area. */

/*     HANDLE   The file handle for a binary DAS file that has been */
/*              opened with write access. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     LNSIZE   is both the maximum length of a comment line that can */
/*              be read from the input file, and the maximum length */
/*              of a comment line that this routine can write to the */
/*              output DAS file. */

/*              LNSIZE is set to 255 characters. */

/*              The DAS file format itself does not impose a limit */
/*              on the length of lines in comment area, other than */
/*              that the character count must be expressible in a */
/*              32-bit signed integer. */

/* $ Exceptions */

/*     1)   If the scratch file for temporarily holding the comments */
/*          culled from the text file cannot be opened, then the */
/*          error SPICE(FILEOPENFAILED) will be signaled. */

/*     2)   If a non printing ASCII character is encountered in the */
/*          comments, the error SPICE(ILLEGALCHARACTER) will be */
/*          signaled. */

/*     3)   If the begin marker cannot be found in the text file, the */
/*          error SPICE(MARKERNOTFOUND) will be signaled. */

/*     4)   If the end marker cannot be found in the text file, the */
/*          error SPICE(MARKERNOTFOUND) will be signaled. */

/* $ Files */

/*     1)   See parameters COMLUN and HANDLE in the $ Detailed_Inputs */
/*          section. */

/*     2)   A scratch file is used to temporarily hold the comments */
/*          culled from the comment text file. This is so we do not */
/*          have to find the place where we started searching for */
/*          comments in the original file. */

/* $ Particulars */

/*     This routine will place all lines between two specified markers, */
/*     a `begin comments marker' and an `end comments marker,' in a */
/*     text file into the comment area of a binary DAS file attached to */
/*     HANDLE. If the `begin comments marker' is blank, then the */
/*     comments are assumed to start at the current location of the */
/*     comment text file attached to COMLUN. If the `end comments */
/*     marker' is blank, then the comments are assumed to stop at the */
/*     end of the comment text file attached to COMLUN. */

/* $ Examples */

/*     We will be using the files `jabber.txt', 'batty.txt', and */
/*     `wndrland.das' in the example which follows. */

/*     `wndrland.das' is a binary DAS file with an empty comment area */
/*                    into which we are going to place the entire file */
/*                    `jabber.txt' and a selected portion of the file */
/*                    `batty.txt'. */

/*     `jabber.txt'   is a text file that is to be placed into the */
/*                    comment area of the binary DAS file `wndrland.das'. */

/*     `batty.txt'    is a text file from which will have a selected */
/*                    portion of its text placed into the comment area */
/*                    of the binary DAS file `wndrland.das'. */

/*     Let -BOF- and -EOF- denote the beginning and end of a file, */
/*     respectively. */

/*     The file `jabber.txt' contains: */

/*        -BOF- */
/*                  The Jabberwock */

/*        'Twas brillig, and the slithy toves */
/*              Did gyre and gimble in the wabe; */
/*        All mimsy were the borogoves, */
/*              And the mome raths outgrabe. */

/*        ``Beware the Jabberwock, my son! */
/*              The jaws that bite, the claws that catch!'' */

/*        And as in uffish thought he stood, */
/*              The Jabberwock, with eyes of flame, */
/*        Came whiffling through the tulgey wood, */
/*              And burbled as it came! */

/*        One, two! One, two! And through and through */
/*              The vorpal blade went snicker-snack! */
/*        He left it dead, and with its head */
/*              He went galumphing back. */

/*        ``And hast thou slain the Jabberwock? */
/*              Come to my arms, my beamish boy! */
/*        O frabjous day! Callooh! Callay!'' */
/*              He chortled in his joy. */

/*               Through the Looking-Glass */
/*               Lewis Carroll */
/*        -EOF- */

/*     The file `batty.txt' contains: */

/*        -BOF- */
/*        This file contains a brief poem about bats. */

/*        BEGIN bat poem */
/*        Twinkle, twinkle, little bat! */
/*        How I wonder what you're at! */
/*        Up above the world you fly! */
/*        Like a teatray in the sky. */

/*               Alice's Adventures in Wonderland */
/*               Lewis Carroll */
/*        END bat poem */

/*        And that's that for bats. */
/*        -EOF- */

/*     Let */

/*           JABLUN   be the logical unit for the file `jabber.txt' */
/*           BATLUN   be the logical unit for the file `batty.txt' */
/*     and */
/*           HANDLE   be the DAS handle for the file `wndrland.das' */

/*     The code fragment */

/*     C */
/*     C      Open the files. */
/*     C */
/*            CALL DASOPW ( `wndrland.das', HANDLE ) */
/*            CALL TXTOPN ( `jabber.txt'  , JABLUN ) */
/*            CALL TXTOPN ( `batty.txt'   , BATLUN ) */
/*     C */
/*     C      Initialize the markers for the file `jabber.txt'. We want */
/*     C      to include the entire file, so both markers are blank. */
/*     C */
/*            BEGMRK = ' ' */
/*            ENDMRK = ' ' */
/*            INSBLN = .TRUE. */
/*     C */
/*     C      Add the comments from the file 'jabber.txt' */
/*     C */
/*            CALL DASACU ( JABLUN, BEGMRK, ENDMRK, INSBLN, HANDLE ) */
/*     C */
/*     C      Initialize the markers for the file `batty.txt'. We want */
/*     C      to include the bat poem only, so we define the begin and */
/*     C      end marker accordingly. */
/*     C */
/*            BEGMRK = 'BEGIN bat poem' */
/*            ENDMRK = 'END bat poem' */
/*            INSBLN = .TRUE. */
/*     C */
/*     C      Add the comments from the file 'batty.txt' */
/*     C */
/*            CALL DASACU ( BATLUN, BEGMRK, ENDMRK, INSBLN, HANDLE ) */
/*     C */
/*     C      Close the files. */

/*            CLOSE       ( JABLUN ) */
/*            CLOSE       ( BATLUN ) */
/*            CALL DASCLS ( HANDLE ) */

/*     will create a comment area in `wndrland.das' which contains: */

/*        -BOC- */
/*                  The Jabberwock */

/*        'Twas brillig, and the slithy toves */
/*              Did gyre and gimble in the wabe; */
/*        All mimsy were the borogoves, */
/*              And the mome raths outgrabe. */

/*        ``Beware the Jabberwock, my son! */
/*              The jaws that bite, the claws that catch!'' */

/*        And as in uffish thought he stood, */
/*              The Jabberwock, with eyes of flame, */
/*        Came whiffling through the tulgey wood, */
/*              And burbled as it came! */

/*        One, two! One, two! And through and through */
/*              The vorpal blade went snicker-snack! */
/*        He left it dead, and with its head */
/*              He went galumphing back. */

/*        ``And hast thou slain the Jabberwock? */
/*              Come to my arms, my beamish boy! */
/*        O frabjous day! Callooh! Callay!'' */
/*              He chortled in his joy. */

/*               Through the Looking-Glass */
/*               Lewis Carroll */

/*        Twinkle, twinkle, little bat! */
/*        How I wonder what you're at! */
/*        Up above the world you fly! */
/*        Like a teatray in the sky. */

/*               Alice's Adventures in Wonderland */
/*               Lewis Carroll */
/*        -EOC- */

/*     where -BOC- and -EOC- represent the beginning and end of the */
/*     comments, respectively. */

/* $ Restrictions */

/*     1)  The begin comments marker, BEGMRK, and the end comments */
/*         marker, ENDMRK, must each appear alone on a line in the */
/*         comment text file if they are not blank. */

/*     2)  The maximum length of a text line in the input comment file */
/*         is specified by the LINLEN parameter defined below. Currently */
/*         this value is 255 characters. */

/*     3)  The maximum length of a single comment line that can be */
/*         written by this routine to the output DAS file's comment area */
/*         is specified by the parameter LINLEN defined below. Currently */
/*         this value is 255 characters. */

/*     4)  This routine uses constants that are specific to the ASCII */
/*         character sequence. The results of using this routine with a */
/*         different character sequence are unpredictable. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     K.R. Gehringer (JPL) */

/* $ Version */

/* -    SPICELIB 1.2.1, 15-MAR-2017 (NJB) */

/*        Added description of parameter LNSIZE. Fixed typos */
/*        throughout the comments. */

/* -    SPICELIB 1.2.0, 07-JUL-1996 (NJB) */

/*        Removed declaration, DATA and SAVE statements for unused */
/*        variable FIRST. */

/* -    Beta Version 1.1.0, 20-SEP-1995 (KRG) */

/*        Added a check of FAILED after the call to GETLUN to trap */
/*        an error, if one is signaled by GETLUN, before attempting to */
/*        open the SCRATCH file. */

/* -    Beta Version 1.0.0, 4-JAN-1993 (KRG) */

/* -& */
/* $ Index_Entries */

/*      add comments from a logical unit to a das file */

/* -& */
/* $ Revisions */


/* -    SPICELIB 1.2.0, 07-JUL-1996 (NJB) */

/*        Removed declaration, DATA and SAVE statements for unused */
/*        variable FIRST. */

/* -    Beta Version 1.1.0, 20-SEP-1995 (KRG) */

/*        Added a check of FAILED after the call to GETLUN to trap */
/*        an error, if one is signaled by GETLUN, before attempting to */
/*        open the SCRATCH file. */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */

/*     Set the value for the maximum length of a text line. */


/*     Set the length of a DAS file ID word. */


/*     Set the length of a DAS file internal filename. */


/*     Set the size of the comment buffer. */


/*     Maximum and minimum decimal values for the printable ASCII */
/*     characters. */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "DASACU", (ftnlen)6);
    }

/*     Verify that the DAS file attached to HANDLE is opened with write */
/*     access. */

    dassih_(__global_state, handle, "WRITE", (ftnlen)5);
    if (failed_(__global_state)) {
	chkout_(__global_state, "DASACU", (ftnlen)6);
	return 0;
    }

/*     Get the number of comment characters, and some other stuff that */
/*     we will not be using. */

    dasrfr_(__global_state, handle, idword, ifname, &nresvr, &nresvc, &ncomr, 
	    &ncomc, (ftnlen)8, (ftnlen)60);
    if (failed_(__global_state)) {
	chkout_(__global_state, "DASACU", (ftnlen)6);
	return 0;
    }

/*     Get an available logical unit for the comment scratch file. */

    getlun_(__global_state, &scrlun);
    if (failed_(__global_state)) {
	chkout_(__global_state, "DASACU", (ftnlen)6);
	return 0;
    }

/*     Attempt to open the comment scratch file. */

    o__1.oerr = 1;
    o__1.ounit = scrlun;
    o__1.ofnm = 0;
    o__1.orl = 0;
    o__1.osta = "SCRATCH";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    iostat = f_open(&__global_state->f2c, &o__1);
    if (iostat != 0) {
	setmsg_(__global_state, "Attempt to open a temporary file failed. IO"
		"STAT = #.", (ftnlen)52);
	errint_(__global_state, "#", &iostat, (ftnlen)1);
	sigerr_(__global_state, "SPICE(FILEOPENFAILED)", (ftnlen)21);
	chkout_(__global_state, "DASACU", (ftnlen)6);
	return 0;
    }

/*     Start looking for the begin comment marker. If the begin marker */
/*     is a blank line, then the comments begin on the first line of the */
/*     comment file. Otherwise, the comments begin on the line */
/*     immediately following the line which contains the begin comments */
/*     marker. */

    s_copy(&__global_state->f2c, line, " ", (ftnlen)255, (ftnlen)1);
    eof = FALSE_;
    while(s_cmp(&__global_state->f2c, line, begmrk, (ftnlen)255, begmrk_len) 
	    != 0) {
	readln_(__global_state, comlun, line, &eof, (ftnlen)255);
	ljust_(__global_state, line, line, (ftnlen)255, (ftnlen)255);
	if (failed_(__global_state)) {
	    cl__1.cerr = 0;
	    cl__1.cunit = scrlun;
	    cl__1.csta = 0;
	    f_clos(&__global_state->f2c, &cl__1);
	    chkout_(__global_state, "DASACU", (ftnlen)6);
	    return 0;
	}

/*        If we have encountered the end of file  here, we have a */
/*        problem: We did not find the begin comments marker in the */
/*        text file. So, set an appropriate error message and signal */
/*        the error. don't forget to close the scratch file. */

	if (eof) {
	    cl__1.cerr = 0;
	    cl__1.cunit = scrlun;
	    cl__1.csta = 0;
	    f_clos(&__global_state->f2c, &cl__1);
	    setmsg_(__global_state, "The begin comments marker '#' was not f"
		    "ound in the comment file '#'.", (ftnlen)68);
	    errch_(__global_state, "#", begmrk, (ftnlen)1, begmrk_len);
	    errfnm_(__global_state, "#", comlun, (ftnlen)1);
	    sigerr_(__global_state, "SPICE(MARKERNOTFOUND)", (ftnlen)21);
	    chkout_(__global_state, "DASACU", (ftnlen)6);
	    return 0;
	}
    }

/*     Begin reading in the comment lines from the comment file, */
/*     placing them a buffer at a time into the temporary file. */
/*     We also scan each line for non printing characters. */

    s_copy(&__global_state->f2c, line, " ", (ftnlen)255, (ftnlen)1);
    if (s_cmp(&__global_state->f2c, endmrk, " ", endmrk_len, (ftnlen)1) == 0) 
	    {

/*        If the end mark is blank, then we want to go until we hit the */
/*        end of the comment file. */

	while(! eof) {
	    numcom = 0;
	    readla_(__global_state, comlun, &__state->c__22, &numcom, combuf, 
		    &eof, (ftnlen)255);
	    if (failed_(__global_state)) {
		cl__1.cerr = 0;
		cl__1.cunit = scrlun;
		cl__1.csta = 0;
		f_clos(&__global_state->f2c, &cl__1);
		chkout_(__global_state, "DASACU", (ftnlen)6);
		return 0;
	    }

/*           If we got some comments, we need to scan them for non */
/*           printing characters. */

	    if (numcom > 0) {
		i__1 = numcom;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    length = lastnb_(__global_state, combuf + ((i__2 = i__ - 
			    1) < 22 && 0 <= i__2 ? i__2 : s_rnge(&
			    __global_state->f2c, "combuf", i__2, "dasacu_", (
			    ftnlen)587)) * 255, (ftnlen)255);

/*                 Scan the comment line for non printing characters. */

		    i__2 = length;
		    for (j = 1; j <= i__2; ++j) {

/*                    Check to see that the characters in the buffer */
/*                    are all printing ASCII characters. The bounds */
/*                    for printing ASCII characters are given by */
/*                    MAXPCH and MINPCH, which are defined in the */
/*                    $ Local Parameters section of the header. */

			intchr = *(unsigned char *)&combuf[((i__3 = i__ - 1) <
				 22 && 0 <= i__3 ? i__3 : s_rnge(&
				__global_state->f2c, "combuf", i__3, "dasacu_"
				, (ftnlen)599)) * 255 + (j - 1)];
			if (intchr > 126 || intchr < 32) {
			    cl__1.cerr = 0;
			    cl__1.cunit = scrlun;
			    cl__1.csta = 0;
			    f_clos(&__global_state->f2c, &cl__1);
			    setmsg_(__global_state, "A nonprinting character"
				    " was encountered in the comments. Value:"
				    " #", (ftnlen)65);
			    errint_(__global_state, "#", &intchr, (ftnlen)1);
			    sigerr_(__global_state, "SPICE(ILLEGALCHARACTER)",
				     (ftnlen)23);
			    chkout_(__global_state, "DASACU", (ftnlen)6);
			    return 0;
			}
		    }
		}

/*              Write the comments to the temporary file. */

		writla_(__global_state, &numcom, combuf, &scrlun, (ftnlen)255)
			;
	    }
	    if (failed_(__global_state)) {
		cl__1.cerr = 0;
		cl__1.cunit = scrlun;
		cl__1.csta = 0;
		f_clos(&__global_state->f2c, &cl__1);
		chkout_(__global_state, "DASACU", (ftnlen)6);
		return 0;
	    }
	}
    } else {

/*        The endmark is non blank, then  we want to go until we find a */
/*        line in the comment file that matches the end mark that was */
/*        entered. */

	more = TRUE_;
	while(more) {
	    numcom = 0;
	    readla_(__global_state, comlun, &__state->c__22, &numcom, combuf, 
		    &eof, (ftnlen)255);
	    if (failed_(__global_state)) {
		cl__1.cerr = 0;
		cl__1.cunit = scrlun;
		cl__1.csta = 0;
		f_clos(&__global_state->f2c, &cl__1);
		chkout_(__global_state, "DASACU", (ftnlen)6);
		return 0;
	    }

/*           Look for ENDMRK in the current buffer if we got some */
/*           comments. */

	    if (numcom > 0) {
		i__ = 1;
		while(more && i__ <= numcom) {
		    s_copy(&__global_state->f2c, line, combuf + ((i__1 = i__ 
			    - 1) < 22 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "combuf", i__1, "dasacu_", (
			    ftnlen)662)) * 255, (ftnlen)255, (ftnlen)255);
		    ljust_(__global_state, line, line, (ftnlen)255, (ftnlen)
			    255);
		    if (s_cmp(&__global_state->f2c, line, endmrk, (ftnlen)255,
			     endmrk_len) == 0) {
			more = FALSE_;
			numcom = i__ - 1;
		    } else {
			++i__;
		    }
		}
	    }

/*           If we still have some comments, we need to scan them for */
/*           non printing characters. */

	    if (numcom > 0) {
		i__1 = numcom;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    length = lastnb_(__global_state, combuf + ((i__2 = i__ - 
			    1) < 22 && 0 <= i__2 ? i__2 : s_rnge(&
			    __global_state->f2c, "combuf", i__2, "dasacu_", (
			    ftnlen)687)) * 255, (ftnlen)255);

/*                 Scan the comment line for non printinig characters. */

		    i__2 = length;
		    for (j = 1; j <= i__2; ++j) {

/*                    Check to see that the characters in the buffer */
/*                    are all printing ASCII characters. The bounds */
/*                    for printing ASCII characters are given by */
/*                    MAXPCH and MINPCH, which are defined in the */
/*                    $ Local Parameters section of the header. */

			intchr = *(unsigned char *)&combuf[((i__3 = i__ - 1) <
				 22 && 0 <= i__3 ? i__3 : s_rnge(&
				__global_state->f2c, "combuf", i__3, "dasacu_"
				, (ftnlen)699)) * 255 + (j - 1)];
			if (intchr > 126 || intchr < 32) {
			    cl__1.cerr = 0;
			    cl__1.cunit = scrlun;
			    cl__1.csta = 0;
			    f_clos(&__global_state->f2c, &cl__1);
			    setmsg_(__global_state, "A nonprinting character"
				    " was encountered in the comment buffer. "
				    "Value: #", (ftnlen)71);
			    errint_(__global_state, "#", &intchr, (ftnlen)1);
			    sigerr_(__global_state, "SPICE(ILLEGALCHARACTER)",
				     (ftnlen)23);
			    chkout_(__global_state, "DASACU", (ftnlen)6);
			    return 0;
			}
		    }
		}

/*              Write the comments to the temporary file. */

		writla_(__global_state, &numcom, combuf, &scrlun, (ftnlen)255)
			;
	    }
	    if (failed_(__global_state)) {
		cl__1.cerr = 0;
		cl__1.cunit = scrlun;
		cl__1.csta = 0;
		f_clos(&__global_state->f2c, &cl__1);
		chkout_(__global_state, "DASACU", (ftnlen)6);
		return 0;
	    }

/*           If we have encountered the end of file here, we have a */
/*           problem: We did not find the end comments marker in the */
/*           text file. So, set an appropriate error message and */
/*           signal the error. */

	    if (more && eof) {
		cl__1.cerr = 0;
		cl__1.cunit = scrlun;
		cl__1.csta = 0;
		f_clos(&__global_state->f2c, &cl__1);
		setmsg_(__global_state, "The end comments marker '#' was not"
			" found in the comment file '#'.", (ftnlen)66);
		errch_(__global_state, "#", endmrk, (ftnlen)1, endmrk_len);
		errfnm_(__global_state, "#", comlun, (ftnlen)1);
		sigerr_(__global_state, "SPICE(MARKERNOTFOUND)", (ftnlen)21);
		chkout_(__global_state, "DASACU", (ftnlen)6);
		return 0;
	    }
	}
    }

/*     If we made it to here, we have culled all of the comments out of */
/*     the text file and they were all OK. So we need to add all of the */
/*     comments to the DAS comment area now. */

/*     If we are supposed to insert a blank line to separate the current */
/*     addition from any previously stored comments, and there are */
/*     comments already in the comment area, indicated by NCOMC > 0, then */
/*     we insert the blank line. Otherwise, just add the comments. */

    if (*insbln && ncomc > 0) {
	dasac_(__global_state, handle, &__state->c__1, " ", (ftnlen)1);
	if (failed_(__global_state)) {
	    cl__1.cerr = 0;
	    cl__1.cunit = scrlun;
	    cl__1.csta = 0;
	    f_clos(&__global_state->f2c, &cl__1);
	    chkout_(__global_state, "DASACU", (ftnlen)6);
	    return 0;
	}
    }

/*     Rewind the scratch file to get ready to put the comments into the */
/*     comment area. */

    al__1.aerr = 0;
    al__1.aunit = scrlun;
    f_rew(&__global_state->f2c, &al__1);

/*     Begin reading through the scratch file, placing the comment lines */
/*     into the comment area of the DAS file a buffer at a time */

    eof = FALSE_;
    while(! eof) {
	numcom = 0;

/*        Read in a buffer of comment lines. */

	readla_(__global_state, &scrlun, &__state->c__22, &numcom, combuf, &
		eof, (ftnlen)255);

/*        If we got some, add them to the comment area of the DAS file. */

	if (numcom > 0) {
	    dasac_(__global_state, handle, &numcom, combuf, (ftnlen)255);
	}
	if (failed_(__global_state)) {
	    cl__1.cerr = 0;
	    cl__1.cunit = scrlun;
	    cl__1.csta = 0;
	    f_clos(&__global_state->f2c, &cl__1);
	    chkout_(__global_state, "DASACU", (ftnlen)6);
	    return 0;
	}
    }

/*     Close the scratch file before exiting; it's the only one we */
/*     opened. */

    cl__1.cerr = 0;
    cl__1.cunit = scrlun;
    cl__1.csta = 0;
    f_clos(&__global_state->f2c, &cl__1);
    chkout_(__global_state, "DASACU", (ftnlen)6);
    return 0;
} /* dasacu_ */

