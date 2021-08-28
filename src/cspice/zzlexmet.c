/* zzlexmet.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzlexmet_init_t __zzlexmet_init;
static inline zzlexmet_state_t* get_zzlexmet_state(cspice_t* state) {
	if (!state->zzlexmet)
		state->zzlexmet = __cspice_allocate_module(sizeof(
	zzlexmet_state_t), &__zzlexmet_init, sizeof(__zzlexmet_init));
	return state->zzlexmet;

}

/* $Procedure ZZLEXMET ( Scan method string ) */
/* Subroutine */ int zzlexmet_(cspice_t* __global_state, char *method, 
	integer *maxn, integer *n, integer *begs, integer *ends, ftnlen 
	method_len)
{
    /* Builtin functions */
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern integer cpos_(cspice_t*, char *, char *, integer *, ftnlen, ftnlen)
	    ;
    integer room;
    integer qpos;
    integer b;
    integer e;
    integer i__;
    integer r__;
    integer nchar;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern integer ltrim_(cspice_t*, char *, ftnlen);
    extern integer rtrim_(cspice_t*, char *, ftnlen);
    integer eq;
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int lxqstr_(cspice_t*, char *, char *, integer *, 
	    integer *, integer *, ftnlen, ftnlen);
    integer loc;
    integer tke;


    /* Module state */
    zzlexmet_state_t* __state = get_zzlexmet_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due to the */
/*     volatile nature of this routine. */

/*     Scan a method input string passed by a caller to a SPICE */
/*     high-level geometry API. Return tokens found in the string. */

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

/*     DSK */

/* $ Keywords */

/*     SCANNING */
/*     PARSING */
/*     CONSTANTS */
/*     TOPOGRAPHY */
/*     UTILITY */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     METHOD     I   Method string. */
/*     MAXN       I   Maximum number of tokens that can be returned. */
/*     N          O   Number of tokens found. */
/*     BEGS       O   Beginning indices of tokens. */
/*     ENDS       O   Ending indices of tokens. */

/* $ Detailed_Input */

/*     METHOD     is a "method" string to be parsed. This string */
/*                normally is passed by a caller to a SPICE high-level */
/*                high-level geometry routine. */

/*                METHOD indicates whether a target body surface is */
/*                to be modeled as an ellipsoid or by DSK data. It */
/*                may contain additional, computation-dependent */
/*                parameters. */

/*     MAXN       is the maximum number of tokens that may be returned. */
/*                The output arrays BEGS and ENDS must be declared with */
/*                size at least MAXN.  It's an error to supply output */
/*                arrays that are too small to hold all of the tokens in */
/*                the input method string. */

/* $ Detailed_Output */

/*     N          is the number of tokens found in the method string. */

/*     BEGS, */
/*     ENDS       are, respectively, the indices of the first and last */
/*                characters of each token in the input string METHOD. */
/*                BEGS(I) and ENDS(I) indicate the index range of the */
/*                Ith token. */

/*                See the Particulars section for a list of token */
/*                delimiters. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If an error is found while parsing a quoted string, */
/*         the error SPICE(SYNTAXERROR) is signaled. */

/*     2)  If the number of tokens found in the method string */
/*         is greater than the input limit MAXN, the error */
/*         SPICE(ARRAYTOOSMALL) is signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine supports parsing of the METHOD input argument */
/*     used by SPICE geometry APIs such as, but not limited to: */

/*        GFOCLT */
/*        ILLUMF */
/*        ILLUMG */
/*        ILUMIN */
/*        LATSRF */
/*        LIMBPT */
/*        SINCPT */
/*        SUBPNT */
/*        SUBSLR */
/*        TERMPT */

/*     Token delimiters are */

/*        / = , <blank> */

/*     Strings delimited by double quote characters are treated as */
/*     individual tokens. There is no escape syntax for indicating a */
/*     doubly quoted string within a doubly quoted string. */

/* $ Examples */


/*     Example: */

/*       Method string = */

/*          METHOD = 'INTERCEPT / ' */
/*          //       'DSK/UNPRIORITIZED/SURFACES = "MGS ' */
/*          //       'MOLA 128 PIXEL/DEG", MARS_LOWRES' */

/*       Token list = */

/*          INTERCEPT */
/*          / */
/*          DSK */
/*          / */
/*          UNPRIORITIZED */
/*          / */
/*          SURFACES */
/*          = */
/*          "MGS MOLA 128 PIXEL/DEG" */
/*          , */
/*          MARS_LOWRES */


/* $ Restrictions */

/*     This is a specialized scanning routine. It it meant to */
/*     be used only for the parsing "method" strings as */
/*     described in Particulars. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 02-FEB-2016 (NJB) */

/*        Based on first version 13-JAN-2015 (NJB) */

/* -& */
/* $ Index_Entries */

/*     scan method string for geometry api routines */
/*     lex method string for geometry api routines */
/*     extract tokens from method string for geometry apis */
/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Note the leading blank in DELIM below; this */
/*     indicates that the blank character is a delimiter. */


/*     Local variables */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "ZZLEXMET", (ftnlen)8);
    if (s_cmp(&__global_state->f2c, method, " ", method_len, (ftnlen)1) == 0) 
	    {

/*        No tokens here. */

	*n = 0;
	chkout_(__global_state, "ZZLEXMET", (ftnlen)8);
	return 0;
    }
    *n = 0;
    room = *maxn;
    r__ = rtrim_(__global_state, method, method_len);
    i__ = 1;
    while(i__ <= r__) {

/*        Look ahead in the input string for the start of a */
/*        quoted string. */

	qpos = cpos_(__global_state, method + (i__ - 1), "\"", &__state->c__1,
		 method_len - (i__ - 1), (ftnlen)1);
	b = i__;
	if (qpos == 0) {

/*           There are no quoted string tokens in the input string */
/*           from index I onward. */

	    e = r__;
	} else {
	    e = i__ + qpos - 2;
	}
	if (b <= e) {

/*           Locate any tokens between indices B and E. */

	    i__ = b;
	    while(i__ <= e) {

/*              Find the next delimiter in the substring */
/*              from indices I : E. */

		loc = cpos_(__global_state, method + (i__ - 1), " /,=:", &
			__state->c__1, e - (i__ - 1), (ftnlen)5);
		if (loc == 1) {

/*                 There is a delimiter character at index I in METHOD. */

		    tke = i__ - 1 + loc;
		} else if (loc > 1) {

/*                 There is a delimiter character at index */

/*                    I - 1 + LOC */

/*                 in METHOD. */

		    if (s_cmp(&__global_state->f2c, method + (i__ - 1), " ", 
			    i__ + loc - 2 - (i__ - 1), (ftnlen)1) != 0) {

/*                    There's a token preceding the delimiter. */

			tke = i__ - 2 + loc;
		    } else {

/*                    The delimiter is all we've got. */

			tke = i__ - 1 + loc;
		    }
		} else {

/*                 The token, if any, ends at the end of */
/*                 substring we're considering. */

		    tke = e;
		}

/*              There is a token, which may be blank, between */
/*              indices I and TKE. We don't return blank tokens */
/*              in the output array. */

		if (s_cmp(&__global_state->f2c, method + (i__ - 1), " ", tke 
			- (i__ - 1), (ftnlen)1) != 0) {
		    if (room > 0) {
			++(*n);
			--room;
			begs[*n - 1] = ltrim_(__global_state, method + (i__ - 
				1), tke - (i__ - 1)) + i__ - 1;
			ends[*n - 1] = rtrim_(__global_state, method + (i__ - 
				1), tke - (i__ - 1)) + i__ - 1;
		    } else {
			setmsg_(__global_state, "Need more room in output ar"
				"rays. Token count = #; substring indices = #"
				":#; substring = #.", (ftnlen)89);
			errint_(__global_state, "#", n, (ftnlen)1);
			errint_(__global_state, "#", &i__, (ftnlen)1);
			errint_(__global_state, "#", &tke, (ftnlen)1);
			sigerr_(__global_state, "SPICE(ARRAYTOOSMALL)", (
				ftnlen)20);
			chkout_(__global_state, "ZZLEXMET", (ftnlen)8);
			return 0;
		    }
		}
		i__ = tke + 1;
	    }
	}
	if (e < r__) {

/*           We expect to find at least one quoted string starting */
/*           at index E + 1. */

	    i__ = e + 1;
	    lxqstr_(__global_state, method + (i__ - 1), "\"", &__state->c__1, 
		    &eq, &nchar, method_len - (i__ - 1), (ftnlen)1);
	    if (nchar > 0) {
		if (room > 0) {
		    ++(*n);
		    --room;
		    begs[*n - 1] = i__;
		    ends[*n - 1] = i__ - 1 + eq;
		} else {
		    setmsg_(__global_state, "Need more room in output arrays"
			    ". Token count = #; substring indices = #:#; subs"
			    "tring = #.", (ftnlen)89);
		    errint_(__global_state, "#", n, (ftnlen)1);
		    errint_(__global_state, "#", &i__, (ftnlen)1);
		    errint_(__global_state, "#", &tke, (ftnlen)1);
		    errch_(__global_state, "#", method + (i__ - 1), (ftnlen)1,
			     tke - (i__ - 1));
		    sigerr_(__global_state, "SPICE(ARRAYTOOSMALL)", (ftnlen)
			    20);
		    chkout_(__global_state, "ZZLEXMET", (ftnlen)8);
		    return 0;
		}
	    } else {

/*              We have a syntax error in the input string. */

		setmsg_(__global_state, "Invalid quoted string found startin"
			"g at index #. Substring is #.", (ftnlen)64);
		errint_(__global_state, "#", &i__, (ftnlen)1);
		errch_(__global_state, "#", method + (i__ - 1), (ftnlen)1, 
			method_len - (i__ - 1));
		sigerr_(__global_state, "SPICE(SYNTAXERROR)", (ftnlen)18);
		chkout_(__global_state, "ZZLEXMET", (ftnlen)8);
		return 0;
	    }
	    i__ = ends[*n - 1] + 1;
	}

/*        The index I has been moved forward by at least one position. */

    }
    chkout_(__global_state, "ZZLEXMET", (ftnlen)8);
    return 0;
} /* zzlexmet_ */

