/* lparsm.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int lparsm_state_t;
static lparsm_state_t* get_lparsm_state(cspice_t* state) {
	return 0;
}

/* $Procedure      LPARSM ( Parse a list of items ) */
/* Subroutine */ int lparsm_(cspice_t* __global_state, char *list, char *
	delims, integer *nmax, integer *n, char *items, ftnlen list_len, 
	ftnlen delims_len, ftnlen items_len)
{
    /* Builtin functions */
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer i_len(f2c_state_t*, char *, ftnlen), i_indx(f2c_state_t*, char *, 
	    char *, ftnlen, ftnlen);

    /* Local variables */
    char bchr[1];
    char echr[1];
    integer b;
    integer e;
    integer eol;


    /* Module state */
    lparsm_state_t* __state = get_lparsm_state(__global_state);
/* $ Abstract */

/*     Parse a list of items separated by multiple delimiters. */

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

/*      CHARACTER */
/*      LIST */
/*      PARSING */
/*      STRING */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     LIST       I    List of items delimited by DELIMS. */
/*     DELIMS     I    Single characters which delimit items. */
/*     NMAX       I    Maximum number of items to return. */
/*     N          O    Number of items in the list. */
/*     ITEMS      O    Items in the list, left justified. */

/* $ Detailed_Input */

/*     LIST        is a list of items delimited by any one of the */
/*                 characters in the string DELIMS. Consecutive */
/*                 delimiters, and delimiters at the beginning and */
/*                 end of the list, are considered to delimit blank */
/*                 items. A blank list is considered to contain */
/*                 a single (blank) item. */

/*     DELIMS      contains the individual characters which delimit */
/*                 the items in the list. These may be any ASCII */
/*                 characters, including blanks. */

/*                 However, by definition, consecutive blanks are NOT */
/*                 considered to be consecutive delimiters. Nor are */
/*                 a blank and any other delimiter considered to be */
/*                 consecutive delimiters. In addition, leading and */
/*                 trailing blanks are ignored. */

/*     NMAX        is the maximum number of items to be returned from */
/*                 the list. This allows the user to guard against */
/*                 overflow from a list containing more items than */
/*                 expected. */

/* $ Detailed_Output */

/*     N           is the number of items in the list. N may be */
/*                 any number between one and NMAX. N is always the */
/*                 number of delimiters plus one. */

/*     ITEMS       are the items in the list, left justified. Any item */
/*                 in the list to long to fit into an element of ITEMS */
/*                 is truncated on the right. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/*     1) If the string length of ITEMS is too short to accommodate */
/*        an item, the item will be truncated on the right. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     None. */

/* $ Examples */

/*     The following examples illustrate the operation of LPARSM. */

/*      1) Let */
/*               LIST   = '  A number of words   separated   by spaces */
/*               DELIMS = ' ' */
/*               NMAX   = 20 */

/*         Then */
/*               ITEMS(1) = 'A' */
/*               ITEMS(2) = 'number' */
/*               ITEMS(3) = 'of' */
/*               ITEMS(4) = 'words' */
/*               ITEMS(5) = 'separated' */
/*               ITEMS(6) = 'by' */
/*               ITEMS(7) = 'spaces' */

/*      2) Let */
/*               LIST   = '  1986-187// 13:15:12.184 ' */
/*               DELIMS = ' ,/-:' */
/*               NMAX   = 20 */

/*         Then */
/*               ITEMS(1) = '1986' */
/*               ITEMS(2) = '187' */
/*               ITEMS(3) = ' ' */
/*               ITEMS(4) = '13' */
/*               ITEMS(5) = '15' */
/*               ITEMS(6) = '12.184' */

/* $ Restrictions */

/*     None. */

/* $ Author_and_Institution */

/*     I.M. Underwood  (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 26-OCT-2005 (NJB) */

/*        Bug fix:  code was modified to avoid out-of-range */
/*        substring bound conditions. */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     parse a list of items */

/* -& */
/* $ Revisions */

/* -    SPICELIB Version 1.1.0, 26-OCT-2005 (NJB) */

/*        Bug fix:  code was modified to avoid out-of-range */
/*        substring bound conditions.  The previous version */
/*        of this routine used DO WHILE statements of the form */

/*                  DO WHILE (      ( B         .LE. EOL   ) */
/*           .                .AND. ( LIST(B:B) .EQ. BLANK ) ) */

/*        Such statements can cause index range violations when the */
/*        index B is greater than the length of the string LIST. */
/*        Whether or not such violations occur is platform-dependent. */

/* -& */

/*     Local parameters */


/*     Local variables */


/*     Because speed is essential in many list parsing applications, */
/*     LPARSM parses the input list in a single pass. What follows */
/*     is nearly identical to LPARSE, except the Fortran INDEX function */
/*     is used to test for delimiters, instead of testing each character */
/*     for simple equality. */


/*     Nothing yet. */

    *n = 0;

/*     Blank list contains a blank item. */

    if (s_cmp(&__global_state->f2c, list, " ", list_len, (ftnlen)1) == 0) {
	*n = 1;
	s_copy(&__global_state->f2c, items, " ", items_len, (ftnlen)1);
    } else {

/*        Eliminate trailing blanks. EOL is the last non-blank */
/*        character in the list. */

	eol = i_len(&__global_state->f2c, list, list_len);
	while(*(unsigned char *)&list[eol - 1] == 32) {
	    --eol;
	}

/*        As the King said to Alice: 'Begin at the beginning. */
/*        Continue until you reach the end. Then stop.' */

/*        When searching for items, B is the beginning of the current */
/*        item; E is the end.  E points to the next non-blank delimiter, */
/*        if any; otherwise E points to either the last character */
/*        preceding the next item, or to the last character of the list. */

	b = 1;
	while(b <= eol) {

/*           Skip any blanks before the next item or delimiter. */

/*           At this point in the loop, we know */

/*              B <= EOL */

	    *(unsigned char *)bchr = *(unsigned char *)&list[b - 1];
	    while(b <= eol && *(unsigned char *)bchr == 32) {
		++b;
		if (b <= eol) {
		    *(unsigned char *)bchr = *(unsigned char *)&list[b - 1];
		}
	    }

/*           At this point B is the index of the next non-blank */
/*           character BCHR, or else */

/*              B == EOL + 1 */

/*           The item ends at the next delimiter. */

	    e = b;
	    if (e <= eol) {
		*(unsigned char *)echr = *(unsigned char *)&list[e - 1];
	    } else {
		*(unsigned char *)echr = ' ';
	    }
	    while(e <= eol && i_indx(&__global_state->f2c, delims, echr, 
		    delims_len, (ftnlen)1) == 0) {
		++e;
		if (e <= eol) {
		    *(unsigned char *)echr = *(unsigned char *)&list[e - 1];
		}
	    }

/*           (This is different from LPARSE. If the delimiter was */
/*           a blank, find the next non-blank character. If it's not */
/*           a delimiter, back up. This prevents constructions */
/*           like 'a , b', where the delimiters are blank and comma, */
/*           from being interpreted as three items instead of two. */
/*           By definition, consecutive blanks, or a blank and any */
/*           other delimiter, do not count as consecutive delimiters.) */

	    if (e <= eol && *(unsigned char *)echr == 32) {

/*              Find the next non-blank character. */

		while(e <= eol && *(unsigned char *)echr == 32) {
		    ++e;
		    if (e <= eol) {
			*(unsigned char *)echr = *(unsigned char *)&list[e - 
				1];
		    }
		}
		if (e <= eol) {
		    if (i_indx(&__global_state->f2c, delims, echr, delims_len,
			     (ftnlen)1) == 0) {

/*                    We're looking at a non-delimiter character. */

/*                    E is guaranteed to be > 1 if we're here, so the */
/*                    following subtraction is valid. */

			--e;
		    }
		}
	    }

/*           The item now lies between B and E. Unless, of course, B and */
/*           E are the same character; this can happen if the list */
/*           starts or ends with a non-blank delimiter, or if we have */
/*           stumbled upon consecutive delimiters. */

	    ++(*n);
	    if (e > b) {
		s_copy(&__global_state->f2c, items + (*n - 1) * items_len, 
			list + (b - 1), items_len, e - 1 - (b - 1));
	    } else {
		s_copy(&__global_state->f2c, items + (*n - 1) * items_len, 
			" ", items_len, (ftnlen)1);
	    }

/*           If there are more items to be found, continue with */
/*           character following E (which is a delimiter). */

	    if (*n < *nmax) {
		b = e + 1;
	    } else {
		return 0;
	    }
	}

/*        If the list ended with a (non-blank) delimiter, add a */
/*        blank item to the end. */

	if (i_indx(&__global_state->f2c, delims, list + (eol - 1), delims_len,
		 (ftnlen)1) != 0 && *n < *nmax) {
	    ++(*n);
	    s_copy(&__global_state->f2c, items + (*n - 1) * items_len, " ", 
		    items_len, (ftnlen)1);
	}
    }
    return 0;
} /* lparsm_ */

