/* unionc.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int unionc_state_t;
static unionc_state_t* get_unionc_state(cspice_t* state) {
	return 0;
}

/* $Procedure      UNIONC ( Union two character sets ) */
/* Subroutine */ int unionc_(cspice_t* __global_state, char *a, char *b, char 
	*c__, ftnlen a_len, ftnlen b_len, ftnlen c_len)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer i_len(f2c_state_t*, char *, ftnlen);
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    logical l_lt(f2c_state_t*, char *, char *, ftnlen, ftnlen), l_gt(
	    f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer over;
    integer acard;
    integer bcard;
    extern integer cardc_(cspice_t*, char *, ftnlen);
    integer ccard;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern integer sizec_(cspice_t*, char *, ftnlen);
    integer csize;
    extern /* Subroutine */ int scardc_(cspice_t*, integer *, char *, ftnlen);
    integer apoint;
    integer bpoint;
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int excess_(cspice_t*, integer *, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);


    /* Module state */
    unionc_state_t* __state = get_unionc_state(__global_state);
/* $ Abstract */

/*      Union two character sets to form a third set. */

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

/*      SETS */

/* $ Keywords */

/*      CELLS, SETS */

/* $ Declarations */
/* $ Brief_I/O */

/*      VARIABLE  I/O  DESCRIPTION */
/*      --------  ---  -------------------------------------------------- */
/*      A          I   First input set. */
/*      B          I   Second input set. */
/*      C          O   Union of A and B. */

/* $ Detailed_Input */


/*      A           is a set. */


/*      B           is a set, distinct from A. */

/* $ Detailed_Output */

/*      C           is a set, distinct from sets A and B, which */
/*                  contains the union of A and B (that is, all of */
/*                  the elements which are in A or B or both). */

/*                  If the size (maximum cardinality) of C is smaller */
/*                  than the cardinality of the union of A and B, */
/*                  then only as many items as will fit in C are */
/*                  included, and an error is signalled. */

/* $ Parameters */

/*      None. */

/* $ Particulars */

/*      None. */

/* $ Examples */

/*      The UNION of two sets contains every element which is */
/*      in the first set, or in the second set, or in both sets. */

/*            {a,b}      union  {c,d}     =  {a,b,c,d} */
/*            {a,b,c}           {b,c,d}      {a,b,c,d} */
/*            {a,b,c,d}         {}           {a,b,c,d} */
/*            {}                {a,b,c,d}    {a,b,c,d} */
/*            {}                {}           {} */

/*      The following call */

/*            CALL UNIONC  ( PLANETS, ASTEROIDS, RESULT ) */

/*      places the union of the character sets PLANETS and */
/*      ASTEROIDS into the character set RESULT. */

/*      The output set must be distinct from both of the input sets. */
/*      For example, the following calls are invalid. */

/*            CALL UNIONI  ( CURRENT,     NEW, CURRENT ) */
/*            CALL UNIONI  (     NEW, CURRENT, CURRENT ) */

/*      In each of the examples above, whether or not the subroutine */
/*      signals an error, the results will almost certainly be wrong. */
/*      Nearly the same effect can be achieved, however, by placing the */
/*      result into a temporary set, which is immediately copied back */
/*      into one of the input sets, as shown below. */

/*            CALL UNIONI ( CURRENT, NEW,  TEMP ) */
/*            CALL COPYI  ( TEMP,    NEW ) */

/* $ Restrictions */

/*      None. */

/* $ Exceptions */

/*      1) If the union of the two sets causes an excess of elements, the */
/*         error SPICE(SETEXCESS) is signalled. */

/*      2) If length of the elements of the output set is < the */
/*         maximum of the lengths of the elements of the input */
/*         sets, the error SPICE(ELEMENTSTOOSHORT) is signalled. */

/* $ Files */

/*      None. */

/* $ Literature_References */

/*      None. */

/* $ Author_and_Institution */

/*      N.J. Bachman    (JPL) */
/*      C.A. Curzon     (JPL) */
/*      W.L. Taber      (JPL) */
/*      I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 18-JUN-1999 (WLT) */

/*        Made CHKOUT calls consistent with CHKIN. */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (CAC) (WLT) (IMU) */

/* -& */
/* $ Index_Entries */

/*     union two character sets */

/* -& */
/* $ Revisions */

/* -    Beta Version 2.0.0, 05-JAN-1989 (NJB) */

/*        Error signalled if output set elements are not long enough. */
/*        Length must be at least max of lengths of input elements. */
/*        Also, calling protocol for EXCESS has been changed. */
/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Set up the error processing. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "UNIONC", (ftnlen)6);

/*     Make sure output set elements are long enough. */

/* Computing MAX */
    i__1 = i_len(&__global_state->f2c, a, a_len), i__2 = i_len(&
	    __global_state->f2c, b, b_len);
    if (i_len(&__global_state->f2c, c__, c_len) < max(i__1,i__2)) {
	setmsg_(__global_state, "Length of output cell is #.  Length require"
		"d to contain result is #.", (ftnlen)68);
	i__1 = i_len(&__global_state->f2c, c__, c_len);
	errint_(__global_state, "#", &i__1, (ftnlen)1);
/* Computing MAX */
	i__2 = i_len(&__global_state->f2c, a, a_len), i__3 = i_len(&
		__global_state->f2c, b, b_len);
	i__1 = max(i__2,i__3);
	errint_(__global_state, "#", &i__1, (ftnlen)1);
	sigerr_(__global_state, "SPICE(ELEMENTSTOOSHORT)", (ftnlen)23);
	chkout_(__global_state, "UNIONC", (ftnlen)6);
	return 0;
    }

/*     Find the cardinality of the input sets, and the allowed size */
/*     of the output set. */

    acard = cardc_(__global_state, a, a_len);
    bcard = cardc_(__global_state, b, b_len);
    csize = sizec_(__global_state, c__, c_len);

/*     Begin with the input pointers at the first elements of the */
/*     input sets. The cardinality of the output set is zero. */
/*     And there is no overflow so far. */

    apoint = 1;
    bpoint = 1;
    ccard = 0;
    over = 0;

/*     When the ends of both input sets are reached, we're done. */

    while(apoint <= acard || bpoint <= bcard) {

/*        If there is still space in the output set, fill it */
/*        as necessary. */

	if (ccard < csize) {
	    if (apoint > acard) {
		++ccard;
		s_copy(&__global_state->f2c, c__ + (ccard + 5) * c_len, b + (
			bpoint + 5) * b_len, c_len, b_len);
		++bpoint;
	    } else if (bpoint > bcard) {
		++ccard;
		s_copy(&__global_state->f2c, c__ + (ccard + 5) * c_len, a + (
			apoint + 5) * a_len, c_len, a_len);
		++apoint;
	    } else if (s_cmp(&__global_state->f2c, a + (apoint + 5) * a_len, 
		    b + (bpoint + 5) * b_len, a_len, b_len) == 0) {
		++ccard;
		s_copy(&__global_state->f2c, c__ + (ccard + 5) * c_len, a + (
			apoint + 5) * a_len, c_len, a_len);
		++apoint;
		++bpoint;
	    } else if (l_lt(&__global_state->f2c, a + (apoint + 5) * a_len, b 
		    + (bpoint + 5) * b_len, a_len, b_len)) {
		++ccard;
		s_copy(&__global_state->f2c, c__ + (ccard + 5) * c_len, a + (
			apoint + 5) * a_len, c_len, a_len);
		++apoint;
	    } else if (l_gt(&__global_state->f2c, a + (apoint + 5) * a_len, b 
		    + (bpoint + 5) * b_len, a_len, b_len)) {
		++ccard;
		s_copy(&__global_state->f2c, c__ + (ccard + 5) * c_len, b + (
			bpoint + 5) * b_len, c_len, b_len);
		++bpoint;
	    }

/*        Otherwise, stop filling the array, but continue to count the */
/*        number of elements in excess of the size of the output set. */

	} else {
	    if (apoint > acard) {
		++over;
		++bpoint;
	    } else if (bpoint > bcard) {
		++over;
		++apoint;
	    } else if (s_cmp(&__global_state->f2c, a + (apoint + 5) * a_len, 
		    b + (bpoint + 5) * b_len, a_len, b_len) == 0) {
		++over;
		++apoint;
		++bpoint;
	    } else if (l_lt(&__global_state->f2c, a + (apoint + 5) * a_len, b 
		    + (bpoint + 5) * b_len, a_len, b_len)) {
		++over;
		++apoint;
	    } else if (l_gt(&__global_state->f2c, a + (apoint + 5) * a_len, b 
		    + (bpoint + 5) * b_len, a_len, b_len)) {
		++over;
		++bpoint;
	    }
	}
    }

/*     Set the cardinality of the output set. */

    scardc_(__global_state, &ccard, c__, c_len);

/*     Report any excess. */

    if (over > 0) {
	excess_(__global_state, &over, "set", (ftnlen)3);
	sigerr_(__global_state, "SPICE(SETEXCESS)", (ftnlen)16);
    }
    chkout_(__global_state, "UNIONC", (ftnlen)6);
    return 0;
} /* unionc_ */

