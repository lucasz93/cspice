/* zzgfwsts.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzgfwsts_init_t __zzgfwsts_init;
static inline zzgfwsts_state_t* get_zzgfwsts_state(cspice_t* state) {
	if (!state->zzgfwsts)
		state->zzgfwsts = __cspice_allocate_module(sizeof(
	zzgfwsts_state_t), &__zzgfwsts_init, sizeof(__zzgfwsts_init));
	return state->zzgfwsts;

}

/* $Procedure ZZGFWSTS ( Private --- GF, sift first window thru second ) */
/* Subroutine */ int zzgfwsts_(cspice_t* __global_state, doublereal *wndw1, 
	doublereal *wndw2, char *inclsn, doublereal *wndw3, ftnlen inclsn_len)
{
    /* Builtin functions */
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    logical keep;
    logical left;
    logical open;
    integer begp1;
    integer begp2;
    integer begp3;
    integer endp1;
    integer endp2;
    integer endp3;
    integer size1;
    integer size2;
    extern integer cardd_(cspice_t*, doublereal *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    logical right;
    extern integer sized_(cspice_t*, doublereal *);
    extern /* Subroutine */ int scardd_(cspice_t*, integer *, doublereal *);
    char locinc[2];
    logical closed;
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int ssized_(cspice_t*, integer *, doublereal *);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern /* Subroutine */ int cmprss_(cspice_t*, char *, integer *, char *, 
	    char *, ftnlen, ftnlen, ftnlen);
    integer maxpts;
    integer ovflow;
    extern logical return_(cspice_t*);


    /* Module state */
    zzgfwsts_state_t* __state = get_zzgfwsts_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Determine those intervals of the first window that are */
/*     properly contained in an interval of the second. */

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

/*     INTERVALS,  WINDOWS */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  --------------------------------------------------- */
/*     WNDW1      I   Input window 1. */
/*     WNDW2      I   Input window 2. */
/*     INCLSN     I   Flag indicating inclusion desired. */
/*     WNDW3     I/O  Result of sifting WNDW1 through WNDW2. */

/* $ Detailed_Input */

/*     WNDW1      is an initialized SPICELIB window */

/*     WNDW2      is an initialized SPICELIB window */

/*     INCLSN     is a string indicating how intervals of WNDW1 must */
/*                be contained in WNDW2. Allowed values are: '[]', '(]', */
/*                '[)', and '()', where a square bracket represents a */
/*                closed interval and a curved bracket an open interval. */
/*                Suppose that [a,b] is an interval of WNDW1 and that */
/*                [c,d] is an interval of WNDW2.  Then the table below */
/*                shows the tests used to determine the inclusion of */
/*                [a,b] in the interval from c to d. */

/*                []     ---  [a,b]  is contained in [c,d] */
/*                (]     ---  [a,b]  is contained in (c,d] */
/*                [)     ---  [a,b]  is contained in [c,d) */
/*                ()     ---  [a,b]  is contained in (c,d) */

/*                if INCLSN is not one of these four values, the */
/*                error SPICE(UNKNOWNINCLUSION) is signaled. */



/*     WNDW3      is an initialized SPICELIB window, used on input */
/*                only for the purpose of determining the amount */
/*                of space declared for use in WNDW3. */

/* $ Detailed_Output */

/*     WNDW3    is a window consisting those of intervals in WNDW1 */
/*              that are wholly contained in some interval of WNDW2. */

/* $ Parameters */

/*     LBCELL     is the SPICELIB cell lower bound. */

/* $ Exceptions */

/*     1) If the window WNDW3 does not have sufficient space to */
/*        contain the sifting of WNDW1 through WNDW2 the error */
/*        'SPICE(OUTOFROOM)' is signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine allows the user to specify two closed subsets of the */
/*     real line and to find the intervals of one that are contained */
/*     within the intervals of another. The subsets of the real line */
/*     are assumed to be made up of disjoint unions of closed intervals. */

/* $ Examples */

/*     Suppose that WNDW1 and WNDW2 are described by the tables below. */

/*                    WNDW1                         WNDW2 */
/*                12.3    12.8                  11.7    13.5 */
/*                17.8    20.4                  17.2    18.3 */
/*                21.4    21.7                  18.5    22.6 */
/*                38.2    39.8                  40.1    45.6 */
/*                44.0    59.9 */

/*     Then WNDW3 will be given by: */

/*                    WNDW3 */
/*                12.3    12.8 */
/*                21.4    21.7 */

/* $ Restrictions */

/*     The set WNDW3 must not overwrite WNDW1 or WNDW2. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     W.L. Taber      (JPL) */
/*     L.S. Elson      (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.1, 08-DEC-2010 (EDW) */

/*        Edit to replaced term "schedule" with "window." */

/* -    SPICELIB Version 1.0.0, 05-MAR-2009 (NJB) (LSE) (WLT) */

/* -& */
/* $ Index_Entries */

/* find window intervals contained in an interval of another */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local Variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "ZZGFWSTS", (ftnlen)8);

/*     Store the maximum number of endpoints that can be loaded into */
/*     WNDW3 */

    maxpts = sized_(__global_state, wndw3);
    ssized_(__global_state, &maxpts, wndw3);

/*     Find the number of endpoints in each of the input windows. */

    size1 = cardd_(__global_state, wndw1);
    size2 = cardd_(__global_state, wndw2);

/*     Initialize the place holders for each of the input windows. */

    begp1 = 1;
    begp2 = 1;
    endp1 = 2;
    endp2 = 2;
    begp3 = -1;
    endp3 = 0;
    cmprss_(__global_state, " ", &__state->c__0, inclsn, locinc, (ftnlen)1, 
	    inclsn_len, (ftnlen)2);
    open = s_cmp(&__global_state->f2c, locinc, "()", (ftnlen)2, (ftnlen)2) == 
	    0;
    left = s_cmp(&__global_state->f2c, locinc, "[)", (ftnlen)2, (ftnlen)2) == 
	    0;
    right = s_cmp(&__global_state->f2c, locinc, "(]", (ftnlen)2, (ftnlen)2) ==
	     0;
    closed = s_cmp(&__global_state->f2c, locinc, "[]", (ftnlen)2, (ftnlen)2) 
	    == 0;
    if (! (open || left || right || closed)) {
	setmsg_(__global_state, "The value of the inclusion flag must be one"
		" of the following: '[]', '[)', '(]', or '()'.  However the v"
		"alue supplied was '#'. ", (ftnlen)126);
	errch_(__global_state, "#", inclsn, (ftnlen)1, inclsn_len);
	sigerr_(__global_state, "SPICE(UNKNOWNINCLUSION)", (ftnlen)23);
	chkout_(__global_state, "ZZGFWSTS", (ftnlen)8);
	return 0;
    }

/*     We haven't had a chance to overflow yet. */

    ovflow = 0;
    while(begp1 < size1 && begp2 < size2) {

/*        Using the current interval endpoints determine the overlap of */
/*        the two intervals. */

	if (wndw1[endp1 + 5] < wndw2[begp2 + 5]) {

/*           the end of the first interval precedes the beginning of the */
/*           second */

	    begp1 += 2;
	    endp1 += 2;
	} else if (wndw2[endp2 + 5] < wndw1[begp1 + 5]) {

/*           the end of the second interval precedes the beginning of the */
/*           first */

	    begp2 += 2;
	    endp2 += 2;
	} else {

/*           the intervals intersect.  Is the first contained in the */
/*           second? */

	    if (closed) {
		keep = wndw1[begp1 + 5] >= wndw2[begp2 + 5] && wndw1[endp1 + 
			5] <= wndw2[endp2 + 5];
	    } else if (open) {
		keep = wndw1[begp1 + 5] > wndw2[begp2 + 5] && wndw1[endp1 + 5]
			 < wndw2[endp2 + 5];
	    } else if (left) {
		keep = wndw1[begp1 + 5] >= wndw2[begp2 + 5] && wndw1[endp1 + 
			5] < wndw2[endp2 + 5];
	    } else if (right) {
		keep = wndw1[begp1 + 5] > wndw2[begp2 + 5] && wndw1[endp1 + 5]
			 <= wndw2[endp2 + 5];
	    }
	    if (keep) {
		begp3 += 2;
		endp3 += 2;
		if (begp3 < maxpts) {

/*                 Adequate room is left in WNDW3 to include this */
/*                 interval */

		    wndw3[begp3 + 5] = wndw1[begp1 + 5];
		    wndw3[endp3 + 5] = wndw1[endp1 + 5];
		} else {
		    ovflow += 2;
		}
	    }

/*           Determine which window pointers to increment */

	    if (wndw1[endp1 + 5] < wndw2[endp2 + 5]) {

/*              The first interval lies before the end of the second */

		begp1 += 2;
		endp1 += 2;
	    } else if (wndw2[endp2 + 5] < wndw1[endp1 + 5]) {

/*              The second interval lies before the end of the first */

		begp2 += 2;
		endp2 += 2;
	    } else {

/*              The first and second intervals end at the same place */

		begp1 += 2;
		endp1 += 2;
		begp2 += 2;
		endp2 += 2;
	    }
	}
    }
    if (ovflow > 0) {
	setmsg_(__global_state, "The output window does not have sufficient "
		"memory to contain the result of sifting the two given window"
		"s. The output window requires space for # more values than w"
		"hat has been provided. ", (ftnlen)186);
	errint_(__global_state, "#", &ovflow, (ftnlen)1);
	sigerr_(__global_state, "SPICE(OUTOFROOM)", (ftnlen)16);
    } else {
	scardd_(__global_state, &endp3, wndw3);
    }
    chkout_(__global_state, "ZZGFWSTS", (ftnlen)8);
    return 0;
} /* zzgfwsts_ */

