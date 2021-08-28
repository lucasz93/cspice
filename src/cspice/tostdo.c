/* tostdo.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern tostdo_init_t __tostdo_init;
static inline tostdo_state_t* get_tostdo_state(cspice_t* state) {
	if (!state->tostdo)
		state->tostdo = __cspice_allocate_module(sizeof(
	tostdo_state_t), &__tostdo_init, sizeof(__tostdo_init));
	return state->tostdo;

}

/* $Procedure      TOSTDO ( To Standard Output) */
/* Subroutine */ int tostdo_(cspice_t* __global_state, char *line, ftnlen 
	line_len)
{
    /* Initialized data */


    extern /* Subroutine */ int stdio_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int writln_(cspice_t*, char *, integer *, ftnlen);

    /* Module state */
    tostdo_state_t* __state = get_tostdo_state(__global_state);
/* $ Abstract */

/*    Write a line of text to standard output. */

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

/*     UTILITY */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     LINE       I   is a line of text to be written to standard output */

/* $ Detailed_Input */

/*     LINE       is a character string containing text to be written */
/*                to standard output. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     None. */

/* $ Particulars */

/*     This routine is a macro for the subroutine call */

/*        CALL WRITLN ( LINE, STDOUT ) */

/*     Where STDOUT is the logical unit connected to standard output. */

/* $ Examples */

/*     Suppose you need to create a message to be printed on the */
/*     user's terminal.  Here is how to use TOSTDO to handle this */
/*     task. */

/*        CALL TOSTDO ( 'Hello. '         ) */
/*        CALL TOSTDO ( 'My Name is HAL.' ) */
/*        CALL TOSTDO ( 'I became operational January 12, 1997 on the ' ) */
/*        CALL TOSTDO ( 'campus of the University of Illinois in '      ) */
/*        CALL TOSTDO ( 'Urbana, Illinois.' ) */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 18-SEP-1996 (WLT) */


/* -& */
/* $ Index_Entries */

/*     Write a line of text to standard output. */

/* -& */
    if (__state->first) {
	stdio_(__global_state, "STDOUT", &__state->stdout, (ftnlen)6);
	__state->first = FALSE_;
    }
    writln_(__global_state, line, &__state->stdout, line_len);
    return 0;
} /* tostdo_ */

