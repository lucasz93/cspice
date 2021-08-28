/* rdkvar.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern rdkvar_init_t __rdkvar_init;
static inline rdkvar_state_t* get_rdkvar_state(cspice_t* state) {
	if (!state->rdkvar)
		state->rdkvar = __cspice_allocate_module(sizeof(
	rdkvar_state_t), &__rdkvar_init, sizeof(__rdkvar_init));
	return state->rdkvar;

}

/* $Procedure      RDKVAR ( Read the next variable from a kernel file ) */
/* Subroutine */ int rdkvar_(cspice_t* __global_state, char *tabsym, integer *
	tabptr, doublereal *tabval, char *name__, logical *eof, ftnlen 
	tabsym_len, ftnlen name_len)
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2];

    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(f2c_state_t*, char *, char **, integer *, 
	    integer *, ftnlen);

    /* Local variables */
    char line[80];
    integer i__;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    char error[80];
    extern logical failed_(cspice_t*);
    extern /* Subroutine */ int rdkdat_(cspice_t*, char *, logical *, ftnlen);
    extern /* Subroutine */ int replch_(cspice_t*, char *, char *, char *, 
	    char *, ftnlen, ftnlen, ftnlen, ftnlen);
    char cvalue[30];
    doublereal dvalue;
    char varnam[80];
    extern /* Subroutine */ int sydeld_(cspice_t*, char *, char *, integer *, 
	    doublereal *, ftnlen, ftnlen);
    extern /* Subroutine */ int nparsd_(cspice_t*, char *, doublereal *, char 
	    *, integer *, ftnlen, ftnlen);
    char dirctv[3];
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int tparse_(cspice_t*, char *, doublereal *, char 
	    *, ftnlen, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int syenqd_(cspice_t*, char *, doublereal *, char 
	    *, integer *, doublereal *, ftnlen, ftnlen);
    extern /* Subroutine */ int nextwd_(cspice_t*, char *, char *, char *, 
	    ftnlen, ftnlen, ftnlen);
    extern logical return_(cspice_t*);
    char status[6];


    /* Module state */
    rdkvar_state_t* __state = get_rdkvar_state(__global_state);
/* $ Abstract */

/*     Read the next variable from a SPICE ASCII kernel file into a */
/*     double precision symbol table. */

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

/*     KERNEL, SYMBOLS */

/* $ Keywords */

/*     FILES */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL    I/O  Symbol table. */
/*     NAME       O   Name of the variable. */
/*     EOF        O   End of file indicator. */
/*     LINLEN     P   Maximum line length. */

/* $ Detailed_Input */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL      are the components of a double precision symbol */
/*                 table. On input, the table may or may not contain */
/*                 any variables. */

/* $ Detailed_Output */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL      on output, contains the name and values of the next */
/*                 variable in kernel file. Depending on the assignment */
/*                 directive, the values in the file may replace or */
/*                 augment any existing values. */

/*      NAME       is the name of the variable. NAME is blank if */
/*                 no variable is read. */

/*      EOF        is true when the end of the kernel file has been */
/*                 reached, and is false otherwise. The kernel file */
/*                 is closed automatically when the end of the file */
/*                 is reached. */

/* $ Parameters */

/*      LINLEN      is the maximum length of a line in the kernel file. */


/* $ Files */

/*     RDKVAR reads from the file most recently opened by RDKNEW. */

/* $ Exceptions */

/*     1) If an error occurs parsing a date from the kernel file, the */
/*        error SPICE(DATEEXPECTED) is signalled. */

/*     2) If an error occurs parsing a numeric value from the kernel */
/*        file, the error SPICE(NUMBEREXPECTED) is signalled. */

/* $ Particulars */

/*     None. */

/* $ Examples */

/*     In the following example, RDKNEW and RDKVAR are used to read */
/*     the contents of two kernel files into a single symbol table. */
/*     First, the table is cleared. */

/*         CALL SCARDC ( 0, TABSYM ) */
/*         CALL SCARDI ( 0, TABPTR ) */
/*         CALL SCARDD ( 0, TABVAL ) */

/*     Next, the files are opened and read individually. */

/*         DO I = 1, 2 */
/*            CALL RDKNEW ( KERNEL(I), EOF ) */

/*            DO WHILE ( .NOT. EOF ) */
/*               CALL RDKVAR ( TABSYM, TABPTR, TABVAL, NAME, EOF ) */
/*            END DO */
/*         END DO */

/*     Let the files KERNEL(1) and KERNEL(2) contain */

/*         =========================================================== */

/*         \begindata */
/*         DELTA_T_A       =   32.184 */
/*         K               =    1.657D-3 */
/*         ORBIT_ECC       =    1.671D-2 */
/*         MEAN_ANOM       = (  6.239996D0,  1.99096871D-7 ) */

/*         =========================================================== */

/*     and */

/*         =========================================================== */
/*         \begindata */
/*          K               =    0.0D0 */
/*         =========================================================== */

/*     respectively. Then the contents of the symbol table are */

/*          DELTA_T_A  -->   32.184 */
/*          K          -->    0.0D0 */
/*          MEAN_ANOM  -->    6.239996D0 */
/*                            1.99096871D-7 */
/*          ORBIT_ECC  -->    1.671D-2 */

/*     In particular, the value of K read from the second file replaces */
/*     the value read from the first file. */

/* $ Restrictions */

/*     The input file must be opened and initialized by RDKNEW prior */
/*     to the first call to RDKVAR. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     H.A. Neilan     (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 10-MAR-1992 (WLT) */

/*        Changed the length of the local character variable ERROR so */
/*        that it would always have a length greater than the lengths of */
/*        the character strng values placed into it. */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     read the next variable from a kernel file */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.1.0, 10-MAR-1992 (WLT) */

/*        Changed the length of the local character variable ERROR so */
/*        that it would always have a length greater than the lengths of */
/*        the character strng values placed into it. */

/*        The length of the character variable ERROR was changed from 30 */
/*        to 80. */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */
/* -    Beta Version 2.0.0, 23-OCT-1989 (HAN) */

/*        Added a test to FAILED in the main DO-loop to prevent */
/*        infinite looping. If the error mode was set to 'RETURN' */
/*        and an error occurred, the same line could be processed */
/*        forever. */

/* -    Beta Version 1.1.0, 13-JAN-1989 (IMU) */

/*        Variable name may now take up an entire line. The previous */
/*        maximum length (32 characters) was tied to the known length */
/*        used by POOL. That length is now parameterized. Rather than */
/*        have two parameters, which could get out of synch, RDKVAR */
/*        now assumes that a variable name can be as long as an input */
/*        line. */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "RDKVAR", (ftnlen)6);
    }

/*     No variable yet. */

    s_copy(&__global_state->f2c, name__, " ", name_len, (ftnlen)1);

/*     No parsing error has occurred yet. */

    s_copy(&__global_state->f2c, error, " ", (ftnlen)80, (ftnlen)1);

/*     Get the next data line. Unless something is terribly wrong, */
/*     this will begin a new variable definition. We have to read */
/*     the whole variable, unless we luck out and get an error, in */
/*     which case we can quit. */

    s_copy(&__global_state->f2c, status, "BEGIN", (ftnlen)6, (ftnlen)5);
    while(s_cmp(&__global_state->f2c, status, "DONE", (ftnlen)6, (ftnlen)4) !=
	     0 && ! failed_(__global_state)) {
	rdkdat_(__global_state, line, eof, (ftnlen)80);
	if (*eof) {
	    chkout_(__global_state, "RDKVAR", (ftnlen)6);
	    return 0;
	}

/*        Replace commas with blanks. We make no distinctions between */
/*        the two. */

	replch_(__global_state, line, ",", " ", line, (ftnlen)80, (ftnlen)1, (
		ftnlen)1, (ftnlen)80);

/*        The first word on the first line should be the name of a */
/*        variable. The second word should be a directive: = or +=. */

	if (s_cmp(&__global_state->f2c, status, "BEGIN", (ftnlen)6, (ftnlen)5)
		 == 0) {
	    nextwd_(__global_state, line, varnam, line, (ftnlen)80, (ftnlen)
		    80, (ftnlen)80);
	    nextwd_(__global_state, line, dirctv, line, (ftnlen)80, (ftnlen)3,
		     (ftnlen)80);

/*           If this is replacement (=) and not an addition (+=), */
/*           delete the values currently associated with the variable. */
/*           They will be replaced later. */

	    if (s_cmp(&__global_state->f2c, dirctv, "=", (ftnlen)3, (ftnlen)1)
		     == 0) {
		sydeld_(__global_state, varnam, tabsym, tabptr, tabval, (
			ftnlen)80, tabsym_len);
	    }

/*           If this is a vector, the next thing on the line will be a */
/*           left parenthesis. Otherwise, assume that this is a scalar. */
/*           If it's a vector, get the first value. If it's a scalar, */
/*           plant a bogus right parenthesis, to make the following loop */
/*           terminate after one iteration. */

	    nextwd_(__global_state, line, cvalue, line, (ftnlen)80, (ftnlen)
		    30, (ftnlen)80);
	    if (s_cmp(&__global_state->f2c, cvalue, "(", (ftnlen)30, (ftnlen)
		    1) == 0) {
		nextwd_(__global_state, line, cvalue, line, (ftnlen)80, (
			ftnlen)30, (ftnlen)80);
	    } else {
		s_copy(&__global_state->f2c, line, ")", (ftnlen)80, (ftnlen)1)
			;
	    }

/*        For subsequent lines, treat everything as a new value. */

	} else {
	    nextwd_(__global_state, line, cvalue, line, (ftnlen)80, (ftnlen)
		    30, (ftnlen)80);
	}

/*        We have a value anyway. Store it in the table. */

/*        Keep going until the other shoe (the right parenthesis) */
/*        drops, or until the end of the line is reached. */

/*        Dates begin with @; anything else is presumed to be a number. */

	while(s_cmp(&__global_state->f2c, cvalue, ")", (ftnlen)30, (ftnlen)1) 
		!= 0 && s_cmp(&__global_state->f2c, cvalue, " ", (ftnlen)30, (
		ftnlen)1) != 0) {
	    if (*(unsigned char *)cvalue == '@') {
		tparse_(__global_state, cvalue + 1, &dvalue, error, (ftnlen)
			29, (ftnlen)80);
		if (s_cmp(&__global_state->f2c, error, " ", (ftnlen)80, (
			ftnlen)1) != 0) {
/* Writing concatenation */
		    i__1[0] = 14, a__1[0] = "Encountered : ";
		    i__1[1] = 29, a__1[1] = cvalue + 1;
		    s_cat(&__global_state->f2c, error, a__1, i__1, &
			    __state->c__2, (ftnlen)80);
		    setmsg_(__global_state, error, (ftnlen)80);
		    sigerr_(__global_state, "SPICE(DATEEXPECTED)", (ftnlen)19)
			    ;
		    chkout_(__global_state, "RDKVAR", (ftnlen)6);
		    return 0;
		}
	    } else {
		nparsd_(__global_state, cvalue, &dvalue, error, &i__, (ftnlen)
			30, (ftnlen)80);
		if (s_cmp(&__global_state->f2c, error, " ", (ftnlen)80, (
			ftnlen)1) != 0) {
/* Writing concatenation */
		    i__1[0] = 14, a__1[0] = "Encountered : ";
		    i__1[1] = 30, a__1[1] = cvalue;
		    s_cat(&__global_state->f2c, error, a__1, i__1, &
			    __state->c__2, (ftnlen)80);
		    setmsg_(__global_state, error, (ftnlen)80);
		    sigerr_(__global_state, "SPICE(NUMBEREXPECTED)", (ftnlen)
			    21);
		    chkout_(__global_state, "RDKVAR", (ftnlen)6);
		    return 0;
		}
	    }
	    syenqd_(__global_state, varnam, &dvalue, tabsym, tabptr, tabval, (
		    ftnlen)80, tabsym_len);
	    nextwd_(__global_state, line, cvalue, line, (ftnlen)80, (ftnlen)
		    30, (ftnlen)80);
	}
	if (s_cmp(&__global_state->f2c, cvalue, ")", (ftnlen)30, (ftnlen)1) ==
		 0) {
	    s_copy(&__global_state->f2c, status, "DONE", (ftnlen)6, (ftnlen)4)
		    ;
	} else {
	    s_copy(&__global_state->f2c, status, "INVAR", (ftnlen)6, (ftnlen)
		    5);
	}
    }

/*     Return the name of the variable, but only if everything went okay. */

    s_copy(&__global_state->f2c, name__, varnam, name_len, (ftnlen)80);
    chkout_(__global_state, "RDKVAR", (ftnlen)6);
    return 0;
} /* rdkvar_ */

