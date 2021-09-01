/* prsdp.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int prsdp_state_t;
static prsdp_state_t* get_prsdp_state(cspice_t* state) {
	return 0;
}

/* $Procedure   PRSDP   ( Parse d.p. number with error checking ) */
/* Subroutine */ int prsdp_(cspice_t* __global_state, char *string, 
	doublereal *dpval, ftnlen string_len)
{
    /* Builtin functions */
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int nparsd_(cspice_t*, char *, doublereal *, char 
	    *, integer *, ftnlen, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    char errmsg[320];
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    integer ptr;


    /* Module state */
    prsdp_state_t* __state = get_prsdp_state(__global_state);
/* $ Abstract */

/*     Parse a string as a double precision number, encapsulating error */
/*     handling. */

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

/*     NUMBER */
/*     PARSING */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     STRING     I   String representing a d.p. number. */
/*     DPVAL      O   D.p. value obtained by parsing STRING. */

/* $ Detailed_Input */

/*     STRING         is a string representing a double precision */
/*                    number.  Any string acceptable to the SPICELIB */
/*                    routine NPARSD is allowed. */

/* $ Detailed_Output */

/*     DPVAL          is the double precision number obtained by parsing */
/*                    STRING. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If the input string cannot be parsed, the error */
/*        SPICE(NOTADPNUMBER) is signalled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     The purpose of this routine is to enable safe parsing of double */
/*     precision numbers without the necessity of in-line error checking. */
/*     This routine is based on the SPICELIB routine NPARSD. */

/* $ Examples */

/*     See the routine NPARSD for an examples of allowed strings. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman       (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 15-SEP-1997 (NJB) */

/*        Bug fix:  output argument declaration changed from INTEGER */
/*        to DOUBLE PRECISION. */

/* -    SPICELIB Version 1.0.0, 22-JUL-1997 (NJB) */

/* -& */
/* $ Index_Entries */

/*     parse d.p. number with encapsulated error handling */

/* -& */

/*     Local parameters */


/*     Local variables */


/*     Use discovery check-in. */

    nparsd_(__global_state, string, dpval, errmsg, &ptr, string_len, (ftnlen)
	    320);
    if (s_cmp(&__global_state->f2c, errmsg, " ", (ftnlen)320, (ftnlen)1) != 0)
	     {
	chkin_(__global_state, "PRSDP", (ftnlen)5);
	setmsg_(__global_state, errmsg, (ftnlen)320);
	sigerr_(__global_state, "SPICE(NOTADPNUMBER)", (ftnlen)19);
	chkout_(__global_state, "PRSDP", (ftnlen)5);
	return 0;
    }
    return 0;
} /* prsdp_ */

