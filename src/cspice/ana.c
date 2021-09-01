/* ana.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern ana_init_t __ana_init;
static ana_state_t* get_ana_state(cspice_t* state) {
	if (!state->ana)
		state->ana = __cspice_allocate_module(sizeof(ana_state_t), &
	__ana_init, sizeof(__ana_init));
	return state->ana;

}

/* $Procedure ANA ( AN or A ? ) */
/* Character */ VOID ana_(cspice_t* __global_state, char *ret_val, ftnlen 
	ret_val_len, char *word, char *case__, ftnlen word_len, ftnlen 
	case_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer i_indx(f2c_state_t*, char *, char *, ftnlen, ftnlen), s_rnge(
	    f2c_state_t*, char *, integer, char *, integer);

    /* Local variables */
    extern /* Subroutine */ int ucase_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int ljust_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern integer isrchc_(cspice_t*, char *, integer *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int replch_(cspice_t*, char *, char *, char *, 
	    char *, ftnlen, ftnlen, ftnlen, ftnlen);

    /* Module state */
    ana_state_t* __state = get_ana_state(__global_state);
/* $ Abstract */

/*     Return the correct article "a" or "an" used to modify a word */
/*     and return it capitalized, lower case, or upper case. */

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

/*     WORD */

/* $ Keywords */

/*     UTILITY */
/*     WORD */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     WORD       I   is a word that should be modified by "a" or "an" */
/*     CASE       I   'U', 'L', or 'C' to specify capitalization of ANA. */
/*     ANA        O   'A' or 'AN' appropriately capitalized. */

/* $ Detailed_Input */

/*     WORD       is any english word for which you want to write the */
/*                correct phrase "a(an) response(answer)".  The case */
/*                of the letters of word do not matter. */

/*                Leading white space in word is ignored.  The characters */
/*                " and ' are ignored.  Thus ''' apple '' ' and */
/*                '"apple"' and ' apple' and 'apple' are all treated as */
/*                the same word. */

/*     CASE       is a character that describes how the value returned */
/*                in ANA should be capitalized.  The rules are: */

/*                   'U'  ---  ANA is returned in all caps ( A, AN ) */
/*                   'C'  ---  ANA is returned capitalized ( A, An ) */
/*                   'L'  ---  ANA is returned lower case  ( a, an ) */

/*                The case of CASE does not matter.  Any value other */
/*                than those specified result in ANA being returned */
/*                in all lower case. */

/* $ Detailed_Output */

/*     ANA        is a character function an will return the correct */
/*                indefinite article needed to modify the word contained */
/*                in WORD.  ANA should be declared to be CHARACTER*(2) */
/*                (or CHARACTER*(N) where N > 1) in the calling */
/*                program. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error Free */

/*     1) If the uppercase value of CASE is not 'U', 'C' or 'L', it shall */
/*        be treated as 'L'. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine allows you to construct grammatically correct phrases */
/*     when you need to modify a word by an indefinite article.  Using */
/*     the pronunciations contained in the Webster's Ninth Collegiate */
/*     Dictionary, the phrase */

/*      ANA(WORD, CASE) // ' ' // WORD */

/*     will be grammatically correct. */

/* $ Examples */

/*     Suppose you wished to construct one of the messages */

/*        'a new file' */
/*        'an existing file' */

/*     and that the NEW/EXISTING word was in the variable WORD. Then */
/*     you could write */

/*        MESSAGE = ANA( WORD, 'L' ) // ' ' // WORD // ' file ' */
/*        CALL CMPRSS ( ' ', 1, MESSAGE, MESSAGE ) */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     Webster's Ninth Collegiate Dictionary. */

/* $ Author_and_Institution */

/*     B.V. Semenov    (JPL) */
/*     W.L. Taber      (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.1.2, 28-FEB-2008 (BVS) */

/*        Corrected the contents of the Required_Reading section. */

/* -    SPICELIB Version 1.1.1, 22-SEP-2004 (EDW) */

/*        Added Copyright section. */

/* -    SPICELIB Version 1.1.0, 18-JAN-2001 (WLT) */

/*        Made SCLK and "an" word. */

/* -    SPICELIB Version 1.0.0, 29-NOV-1995 (WLT) */

/* -& */
/* $ Index_Entries */

/*     GET THE CORRECT INDEFINITE ARTICLE */

/* -& */
    ucase_(__global_state, word, __state->myword, word_len, (ftnlen)32);
    replch_(__global_state, __state->myword, "'", " ", __state->myword, (
	    ftnlen)32, (ftnlen)1, (ftnlen)1, (ftnlen)32);
    replch_(__global_state, __state->myword, "\"", " ", __state->myword, (
	    ftnlen)32, (ftnlen)1, (ftnlen)1, (ftnlen)32);
    ljust_(__global_state, __state->myword, __state->myword, (ftnlen)32, (
	    ftnlen)32);
    ucase_(__global_state, case__, __state->mycase, case_len, (ftnlen)1);
    s_copy(&__global_state->f2c, ret_val, " ", ret_val_len, (ftnlen)1);
    if (*(unsigned char *)__state->mycase == 'U') {
	__state->caps = 1;
    } else if (*(unsigned char *)__state->mycase == 'C') {
	__state->caps = 2;
    } else {
	__state->caps = 3;
    }

/*     Handle the obvious things first. */

    *(unsigned char *)__state->begin = *(unsigned char *)__state->myword;
    if (i_indx(&__global_state->f2c, "AI", __state->begin, (ftnlen)2, (ftnlen)
	    1) > 0) {
	s_copy(&__global_state->f2c, ret_val, __state->an + (((i__1 = 
		__state->caps - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "an", i__1, "ana_", (ftnlen)235)) << 1), 
		ret_val_len, (ftnlen)2);
	return ;
    } else if (i_indx(&__global_state->f2c, "BCDGJKPQTVWYZ", __state->begin, (
	    ftnlen)13, (ftnlen)1) > 0) {
	s_copy(&__global_state->f2c, ret_val, __state->a + (((i__1 = 
		__state->caps - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "a", i__1, "ana_", (ftnlen)240)) << 1), 
		ret_val_len, (ftnlen)2);
	return ;
    }

/*     If we are still here, we need to be a bit more careful */
/*     in our determination of ANA. */

/*     Get the beginnings of the input word. */

    for (__state->i__ = 1; __state->i__ <= 7; ++__state->i__) {
	s_copy(&__global_state->f2c, __state->start + (((i__1 = __state->i__ 
		- 1) < 7 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"start", i__1, "ana_", (ftnlen)252)) << 5), __state->myword, (
		ftnlen)32, __state->i__);
    }

/*     Now see if the start of the input word belongs to */
/*     one of the special collections. */

    for (__state->i__ = 7; __state->i__ >= 2; --__state->i__) {
	if (isrchc_(__global_state, __state->start + (((i__1 = __state->i__ - 
		1) < 7 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"start", i__1, "ana_", (ftnlen)261)) << 5), &__state->c__33, 
		__state->aword, (ftnlen)32, (ftnlen)8) != 0) {
	    s_copy(&__global_state->f2c, ret_val, __state->a + (((i__1 = 
		    __state->caps - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "a", i__1, "ana_", (ftnlen)263)) << 
		    1), ret_val_len, (ftnlen)2);
	    return ;
	}
	if (isrchc_(__global_state, __state->start + (((i__1 = __state->i__ - 
		1) < 7 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		"start", i__1, "ana_", (ftnlen)268)) << 5), &__state->c__22, 
		__state->anword, (ftnlen)32, (ftnlen)8) != 0) {
	    s_copy(&__global_state->f2c, ret_val, __state->an + (((i__1 = 
		    __state->caps - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "an", i__1, "ana_", (ftnlen)270)) << 
		    1), ret_val_len, (ftnlen)2);
	    return ;
	}
    }

/*     If we got this far we can determine the ANAe by */
/*     just looking at the beginning of the string. */

    if (i_indx(&__global_state->f2c, "AEIOU", __state->myword, (ftnlen)5, (
	    ftnlen)1) > 0) {
	s_copy(&__global_state->f2c, ret_val, __state->an + (((i__1 = 
		__state->caps - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "an", i__1, "ana_", (ftnlen)282)) << 1), 
		ret_val_len, (ftnlen)2);
    } else {
	s_copy(&__global_state->f2c, ret_val, __state->a + (((i__1 = 
		__state->caps - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "a", i__1, "ana_", (ftnlen)286)) << 1), 
		ret_val_len, (ftnlen)2);
    }
    return ;
} /* ana_ */

