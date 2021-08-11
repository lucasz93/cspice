/* ev2lin.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern ev2lin_init_t __ev2lin_init;
static ev2lin_state_t* get_ev2lin_state() {
	cspice_t* state =  __cspice_get_state();
	if (!state->ev2lin)
		state->ev2lin = __cspice_allocate_module(sizeof(
	ev2lin_state_t), &__ev2lin_init, sizeof(__ev2lin_init));
	return state->ev2lin;

}

/* $Procedure      EV2LIN ( Evaluate "two-line" element data) */
/* Subroutine */ int ev2lin_(doublereal *et, doublereal *geophs, doublereal *
	elems, doublereal *state)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_rnge(char *, integer, char *, integer);
    double cos(doublereal), sin(doublereal), sqrt(doublereal), pow_dd(
	    doublereal *, doublereal *), d_mod(doublereal *, doublereal *), 
	    atan2(doublereal, doublereal);

    /* Local variables */
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    extern doublereal twopi_(void);
    extern /* Subroutine */ int errdp_(char *, doublereal *, ftnlen);
    extern doublereal brcktd_(doublereal *, doublereal *, doublereal *);
    extern /* Subroutine */ int setmsg_(char *, ftnlen);
    extern /* Subroutine */ int errint_(char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(char *, ftnlen);
    extern /* Subroutine */ int chkout_(char *, ftnlen);

    /* Module state */
    ev2lin_state_t* __state = get_ev2lin_state();
/* $ Abstract */

/*     This routine evaluates NORAD two-line element data for */
/*     near-earth orbiting spacecraft (that is spacecraft with */
/*     orbital periods less than 225 minutes). */

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

/*      None. */

/* $ Keywords */

/*       EPHEMERIS */

/* $ Declarations */
/* $ Brief_I/O */

/*      VARIABLE  I/O  DESCRIPTION */
/*      --------  ---  -------------------------------------------------- */
/*     ET          I   Epoch in seconds past ephemeris epoch J2000. */
/*     GEOPHS      I   Geophysical constants */
/*     ELEMS       I   Two-line element data */
/*     STATE       O   Evaluated state */
/*     NMODL       P   Parameter controlling number of buffered elements. */

/* $ Detailed_Input */

/*     ET          is the poch in seconds past ephemeris epoch J2000 */
/*                 at which a state should be produced from the */
/*                 input elements. */

/*     GEOPHS      is a collection of 8 geophysical constants needed */
/*                 for computing a state.  The order of these */
/*                 constants must be: */

/*                 GEOPHS(1) = J2 gravitational harmonic for earth */
/*                 GEOPHS(2) = J3 gravitational harmonic for earth */
/*                 GEOPHS(3) = J4 gravitational harmonic for earth */

/*                 These first three constants are dimensionless. */

/*                 GEOPHS(4) = KE: Square root of the GM for earth where */
/*                             GM is expressed in earth radii cubed per */
/*                             minutes squared. */

/*                 GEOPHS(5) = QO: Low altitude bound for atmospheric */
/*                             model in km. */

/*                 GEOPHS(6) = SO: High altitude bound for atmospheric */
/*                             model in km. */

/*                 GEOPHS(7) = RE: Equatorial radius of the earth in km. */


/*                 GEOPHS(8) = AE: Distance units/earth radius */
/*                             (normally 1) */

/*                 Below are currently recommended values for these */
/*                 items: */

/*                   J2 =    1.082616D-3 */
/*                   J3 =   -2.53881D-6 */
/*                   J4 =   -1.65597D-6 */

/*                 The next item is the square root of GM for the */
/*                 earth given in units of earth-radii**1.5/Minute */

/*                   KE =    7.43669161D-2 */

/*                 The next two items give the top and */
/*                 bottom of the atmospheric drag model */
/*                 used by the type 10 ephemeris type. */
/*                 Don't adjust these unless you understand */
/*                 the full implications of such changes. */

/*                   QO =  120.0D0 */
/*                   SO =   78.0D0 */

/*                 The following is the equatorial radius */
/*                 of the earth as used by NORAD in km. */

/*                   ER = 6378.135D0 */

/*                 The value of AE is the number of */
/*                 distance units per earth radii used by */
/*                 the NORAD state propagation software. */
/*                 The value should be 1 unless you've got */
/*                 a very good understanding of the NORAD */
/*                 routine SGP4 and the affect of changing */
/*                 this value.. */

/*                   AE =    1.0D0 */

/*     ELEMS       is an array containg two-line element data */
/*                 as prescribed below. The elements XNDD6O and BSTAR */
/*                 must already be scaled by the proper exponent stored */
/*                 in the two line elements set.  Moreover, the */
/*                 various items must be converted to the units shown */
/*                 here. */

/*                    ELEMS (  1 ) = XNDT2O in radians/minute**2 */
/*                    ELEMS (  2 ) = XNDD6O in radians/minute**3 */
/*                    ELEMS (  3 ) = BSTAR */
/*                    ELEMS (  4 ) = XINCL  in radians */
/*                    ELEMS (  5 ) = XNODEO in radians */
/*                    ELEMS (  6 ) = EO */
/*                    ELEMS (  7 ) = OMEGAO in radians */
/*                    ELEMS (  8 ) = XMO    in radians */
/*                    ELEMS (  9 ) = XNO    in radians/minute */
/*                    ELEMS ( 10 ) = EPOCH of the elements in seconds */
/*                                   past ephemeris epoch J2000. */

/* $ Detailed_Output */

/*     STATE       is the state produced by evaluating the input elements */
/*                 at the input epoch ET. Units are km and km/sec. */

/* $ Parameters */

/*      NMODL      is a parameter that controls how many element sets */
/*                 can be buffered internally.  Since there are a lot */
/*                 of computations that are independent of time these */
/*                 are buffered and only computed if an unbuffered */
/*                 model is supplied.  This value should always */
/*                 be at least 2.  Increasing it a great deal is not */
/*                 advised since the time needed to search the */
/*                 buffered elements for a match increases linearly */
/*                 with the NMODL.  Imperically, 6 seems to be a good */
/*                 break even value for NMODL. */

/* $ Exceptions */

/*     1) No checks are made on the reasonableness of the inputs. */

/*     2) SPICE(ITERATIONEXCEEDED) signals if the EST calculation loop */
/*        exceds the MXLOOP value. This error should signal only for */
/*        bad (nonphysical) TLEs. */

/* $ Files */

/*      None. */

/* $ Particulars */

/*     This routine evaluates NORAD two-line element sets for */
/*     near-earth orbitting satellites.  Near earth is defined to */
/*     be a satellite with an orbital period of less than 225 */
/*     minutes.  This code is an adaptation of the NORAD routine */
/*     SGP4 to elliminate common blocks, allow buffering of models */
/*     and intermediate parameters and double precision calculations. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*      None. */

/* $ Author_and_Institution */

/*      W.L. Taber      (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 15-SEP-2014 (EDW) */

/*        Added error check to prevent infinite loop in */
/*        calculation of EST. */

/* -    SPICELIB Version 1.0.3, 02-JAN-2008 (EDW) */

/*        Corrected error in the calculation of the C4 term */
/*        identified by Curtis Haase. */

/*        Minor edit to the COEF1 declaration strictly */
/*        identifying the constant as a double. */

/*        From: */

/*           COEF1  = COEF  / PSISQ**3.5 */

/*        To: */

/*           COEF1  = COEF  / PSISQ**3.5D0 */

/* -    SPICELIB Version 1.0.2, 08-JUL-2004 (EDW) */

/*        Corrected error in the calculation of the C2 term. */
/*        Reordered C1, C2 calculations to avoid division */
/*        by BSTAR. */

/* -    SPICELIB Version 1.0.1, 10-MAR-1998 (EDW) */

/*        Corrected error in header describing the GEOPHS array. */

/* -    SPICELIB Version 1.0.0, 14-JAN-1994 (WLT) */

/* -& */
/* $ Index_Entries */

/*     Evaluate NORAD two-line element data. */

/* -& */

/*     Spicelib functions */


/*     Local Parameters */


/*     The following parameters give the location of the various */
/*     geophysical parameters needed for the two line element */
/*     sets. */

/*     KJ2  --- location of J2 */
/*     KJ3  --- location of J3 */
/*     KJ4  --- location if J4 */
/*     KKE  --- location of KE = sqrt(GM) in eart-radii**1.5/MIN */
/*     KQO  --- upper bound of atmospheric model in KM */
/*     KSO  --- lower bound of atmospheric model in KM */
/*     KER  --- earth equatorial radius in KM. */
/*     KAE  --- distance units/earth radius */



/*     An enumeration of the various components of the */
/*     elements array---ELEMS */

/*     KNDT20 */
/*     KNDD60 */
/*     KBSTAR */
/*     KINCL */
/*     KNODE0 */
/*     KECC */
/*     KOMEGA */
/*     KMO */
/*     KNO */


/*     The parameters NEXT and PREV are used in our linked list */
/*     LIST(NEXT,I) points to the list item the occurs after */
/*     list item I.  LIST ( PREV, I ) points to the list item */
/*     that preceeds list item I. */
/*     NEXT */
/*     PREV */


/*     There are a number of preliminary quantities that are needed */
/*     to compute the state.  Those that are not time dependent and */
/*     depend only upon the elements are stored in a buffer so that */
/*     if an element set matches a saved set, these preliminary */
/*     quantities  will not be recomputed.  PRSIZE is the parameter */
/*     used to declare the needed room. */


/*     When we perform bisection in the solution of Kepler's equation */
/*     we don't want to bisect too many times. */


/*     Numerical Constants */


/*     Local variables */

/*     Geophysical Quantities */


/*     Elements */


/*     Intermediate quantities. The time independent quantities */
/*     are calculated only as new elements come into the routine. */

    chkin_("EV2LIN", (ftnlen)6);

/*     Rather than always making function calls we store the */
/*     values of the PI dependent constants the first time */
/*     through the routine. */

    if (__state->doinit) {
	__state->doinit = FALSE_;
	__state->pix2 = twopi_();
	for (__state->i__ = 1; __state->i__ <= 8; ++__state->i__) {
	    __state->lstgeo[(i__1 = __state->i__ - 1) < 8 && 0 <= i__1 ? i__1 
		    : s_rnge("lstgeo", i__1, "ev2lin_", (ftnlen)605)] = 0.;
	}
	for (__state->i__ = 1; __state->i__ <= 6; ++__state->i__) {
	    for (__state->j = 1; __state->j <= 10; ++__state->j) {
		__state->elemnt[(i__1 = __state->j + __state->i__ * 10 - 11) <
			 60 && 0 <= i__1 ? i__1 : s_rnge("elemnt", i__1, 
			"ev2lin_", (ftnlen)610)] = 0.;
	    }
	}

/*        Set up our doubly linked list of most recently used */
/*        models.  Here's how things are supposed to be arranged: */

/*        LIST(NEXT,I)   points to the ephemeris model that was used */
/*                       most recently after ephemeris model I. */
/*        LIST(PREV,I)   points to the latest ephemeris model used */
/*                       that was used more recently than I. */

/*        HEAD           points to the most recently used ephemris */
/*                       model. */


	__state->head = 1;
	__state->list[(i__1 = (__state->head << 1) - 1) < 12 && 0 <= i__1 ? 
		i__1 : s_rnge("list", i__1, "ev2lin_", (ftnlen)629)] = 0;
	__state->list[0] = 2;
	for (__state->i__ = 2; __state->i__ <= 5; ++__state->i__) {
	    __state->list[(i__1 = (__state->i__ << 1) - 2) < 12 && 0 <= i__1 ?
		     i__1 : s_rnge("list", i__1, "ev2lin_", (ftnlen)634)] = 
		    __state->i__ + 1;
	    __state->list[(i__1 = (__state->i__ << 1) - 1) < 12 && 0 <= i__1 ?
		     i__1 : s_rnge("list", i__1, "ev2lin_", (ftnlen)635)] = 
		    __state->i__ - 1;
	}
	__state->list[10] = 0;
	__state->list[11] = 5;
    }

/*     We update the geophysical parameters only if there */
/*     has been a change from the last time they were */
/*     supplied. */

    if (__state->lstgeo[7] != geophs[7] || __state->lstgeo[6] != geophs[6] || 
	    __state->lstgeo[0] != geophs[0] || __state->lstgeo[1] != geophs[1]
	     || __state->lstgeo[2] != geophs[2] || __state->lstgeo[3] != 
	    geophs[3] || __state->lstgeo[4] != geophs[4] || __state->lstgeo[5]
	     != geophs[5]) {
	for (__state->i__ = 1; __state->i__ <= 8; ++__state->i__) {
	    __state->lstgeo[(i__1 = __state->i__ - 1) < 8 && 0 <= i__1 ? i__1 
		    : s_rnge("lstgeo", i__1, "ev2lin_", (ftnlen)657)] = 
		    geophs[__state->i__ - 1];
	}
	__state->j2 = geophs[0];
	__state->j3 = geophs[1];
	__state->j4 = geophs[2];
	__state->ke = geophs[3];
	__state->qo = geophs[4];
	__state->so = geophs[5];
	__state->er = geophs[6];
	__state->ae = geophs[7];
	__state->ae2 = __state->ae * __state->ae;
	__state->ae3 = __state->ae * __state->ae2;
	__state->ae4 = __state->ae * __state->ae3;
	__state->ck2 = __state->j2 * .5 * __state->ae2;
	__state->a3ovk2 = __state->j3 * -2. * __state->ae / __state->j2;
	__state->ck4 = __state->j4 * -.375 * __state->ae4;
	__state->qomso = __state->qo - __state->so;
	__state->q1 = __state->qomso * __state->ae / __state->er;
	__state->q2 = __state->q1 * __state->q1;
	__state->qoms2t = __state->q2 * __state->q2;
	__state->s = __state->ae * (__state->so / __state->er + 1.);

/*        When we've finished up we will need to convert everything */
/*        back to KM and KM/SEC  the two variables below give the */
/*        factors we shall need to do this. */

	__state->tokm = __state->er / __state->ae;
	__state->tokmps = __state->tokm / 60.;
	__state->newgeo = TRUE_;
    } else {
	__state->newgeo = FALSE_;
    }

/*     Fetch all of the pieces of this model. */

    __state->epoch = elems[9];
    __state->xndt2o = elems[0];
    __state->xndd6o = elems[1];
    __state->bstar = elems[2];
    __state->xincl = elems[3];
    __state->xnodeo = elems[4];
    __state->eo = elems[5];
    __state->omegao = elems[6];
    __state->xmo = elems[7];
    __state->xno = elems[8];

/*     See if this model is already buffered, start at the first */
/*     model in the list (the most recently used model). */

    __state->unrec = TRUE_;
    __state->n = __state->head;
    while(__state->n != 0 && __state->unrec) {

/*        The actual order of the elements is such that we can */
/*        usually tell that a stored model is different from */
/*        the one under consideration by looking at the */
/*        end of the list first.  Hence we start with I = NELEMS */
/*        and decrement I until we have looked at everything */
/*        or found a mismatch. */

	__state->recog = TRUE_;
	__state->i__ = 10;
	while(__state->recog && __state->i__ > 0) {
	    __state->recog = __state->recog && __state->elemnt[(i__1 = 
		    __state->i__ + __state->n * 10 - 11) < 60 && 0 <= i__1 ? 
		    i__1 : s_rnge("elemnt", i__1, "ev2lin_", (ftnlen)733)] == 
		    elems[__state->i__ - 1];
	    --__state->i__;
	}
	__state->unrec = ! __state->recog;
	if (__state->unrec) {
	    __state->last = __state->n;
	    __state->n = __state->list[(i__1 = (__state->n << 1) - 2) < 12 && 
		    0 <= i__1 ? i__1 : s_rnge("list", i__1, "ev2lin_", (
		    ftnlen)741)];
	}
    }
    if (__state->n == 0) {
	__state->n = __state->last;
    }

/*     Either N points to a recognized item or it points to the */
/*     tail of the list where the least recently used items is */
/*     located.  In either case N must be made the head of the */
/*     list.  (If it is already the head of the list we don't */
/*     have to bother with anything.) */

    if (__state->n != __state->head) {

/*        Find the items that come before and after N and */
/*        link them together. */

	__state->before = __state->list[(i__1 = (__state->n << 1) - 1) < 12 &&
		 0 <= i__1 ? i__1 : s_rnge("list", i__1, "ev2lin_", (ftnlen)
		762)];
	__state->after = __state->list[(i__1 = (__state->n << 1) - 2) < 12 && 
		0 <= i__1 ? i__1 : s_rnge("list", i__1, "ev2lin_", (ftnlen)
		763)];
	__state->list[(i__1 = (__state->before << 1) - 2) < 12 && 0 <= i__1 ? 
		i__1 : s_rnge("list", i__1, "ev2lin_", (ftnlen)765)] = 
		__state->after;
	if (__state->after != 0) {
	    __state->list[(i__1 = (__state->after << 1) - 1) < 12 && 0 <= 
		    i__1 ? i__1 : s_rnge("list", i__1, "ev2lin_", (ftnlen)768)
		    ] = __state->before;
	}

/*        Now the guy that will come after N is the current */
/*        head of the list.  N will have no predecessor. */

	__state->list[(i__1 = (__state->n << 1) - 2) < 12 && 0 <= i__1 ? i__1 
		: s_rnge("list", i__1, "ev2lin_", (ftnlen)774)] = 
		__state->head;
	__state->list[(i__1 = (__state->n << 1) - 1) < 12 && 0 <= i__1 ? i__1 
		: s_rnge("list", i__1, "ev2lin_", (ftnlen)775)] = 0;

/*        The predecessor the current head of the list becomes N */

	__state->list[(i__1 = (__state->head << 1) - 1) < 12 && 0 <= i__1 ? 
		i__1 : s_rnge("list", i__1, "ev2lin_", (ftnlen)779)] = 
		__state->n;

/*        and finally, N becomes the head of the list. */

	__state->head = __state->n;
    }
    if (__state->recog && ! __state->newgeo) {

/*        We can just look up the intermediate values from */
/*        computations performed on a previous call to this */
/*        routine. */

	__state->aodp = __state->prelim[(i__1 = __state->n * 29 - 29) < 174 &&
		 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)
		794)];
	__state->aycof = __state->prelim[(i__1 = __state->n * 29 - 28) < 174 
		&& 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (
		ftnlen)795)];
	__state->c1 = __state->prelim[(i__1 = __state->n * 29 - 27) < 174 && 
		0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)
		796)];
	__state->c4 = __state->prelim[(i__1 = __state->n * 29 - 26) < 174 && 
		0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)
		797)];
	__state->c5 = __state->prelim[(i__1 = __state->n * 29 - 25) < 174 && 
		0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)
		798)];
	__state->cosio = __state->prelim[(i__1 = __state->n * 29 - 24) < 174 
		&& 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (
		ftnlen)799)];
	__state->d2 = __state->prelim[(i__1 = __state->n * 29 - 23) < 174 && 
		0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)
		800)];
	__state->d3 = __state->prelim[(i__1 = __state->n * 29 - 22) < 174 && 
		0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)
		801)];
	__state->d4 = __state->prelim[(i__1 = __state->n * 29 - 21) < 174 && 
		0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)
		802)];
	__state->delmo = __state->prelim[(i__1 = __state->n * 29 - 20) < 174 
		&& 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (
		ftnlen)803)];
	__state->eta = __state->prelim[(i__1 = __state->n * 29 - 19) < 174 && 
		0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)
		804)];
	__state->omgcof = __state->prelim[(i__1 = __state->n * 29 - 18) < 174 
		&& 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (
		ftnlen)805)];
	__state->omgdot = __state->prelim[(i__1 = __state->n * 29 - 17) < 174 
		&& 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (
		ftnlen)806)];
	__state->perige = __state->prelim[(i__1 = __state->n * 29 - 16) < 174 
		&& 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (
		ftnlen)807)];
	__state->sinio = __state->prelim[(i__1 = __state->n * 29 - 15) < 174 
		&& 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (
		ftnlen)808)];
	__state->sinmo = __state->prelim[(i__1 = __state->n * 29 - 14) < 174 
		&& 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (
		ftnlen)809)];
	__state->t2cof = __state->prelim[(i__1 = __state->n * 29 - 13) < 174 
		&& 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (
		ftnlen)810)];
	__state->t3cof = __state->prelim[(i__1 = __state->n * 29 - 12) < 174 
		&& 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (
		ftnlen)811)];
	__state->t4cof = __state->prelim[(i__1 = __state->n * 29 - 11) < 174 
		&& 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (
		ftnlen)812)];
	__state->t5cof = __state->prelim[(i__1 = __state->n * 29 - 10) < 174 
		&& 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (
		ftnlen)813)];
	__state->x1mth2 = __state->prelim[(i__1 = __state->n * 29 - 9) < 174 
		&& 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (
		ftnlen)814)];
	__state->x3thm1 = __state->prelim[(i__1 = __state->n * 29 - 8) < 174 
		&& 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (
		ftnlen)815)];
	__state->x7thm1 = __state->prelim[(i__1 = __state->n * 29 - 7) < 174 
		&& 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (
		ftnlen)816)];
	__state->xlcof = __state->prelim[(i__1 = __state->n * 29 - 6) < 174 &&
		 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)
		817)];
	__state->xmcof = __state->prelim[(i__1 = __state->n * 29 - 5) < 174 &&
		 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)
		818)];
	__state->xmdot = __state->prelim[(i__1 = __state->n * 29 - 4) < 174 &&
		 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)
		819)];
	__state->xnodcf = __state->prelim[(i__1 = __state->n * 29 - 3) < 174 
		&& 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (
		ftnlen)820)];
	__state->xnodot = __state->prelim[(i__1 = __state->n * 29 - 2) < 174 
		&& 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (
		ftnlen)821)];
	__state->xnodp = __state->prelim[(i__1 = __state->n * 29 - 1) < 174 &&
		 0 <= i__1 ? i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)
		822)];
    } else {

/*        Compute all of the intermediate items needed. */
/*        First, the inclination dependent constants. */

	__state->cosio = cos(__state->xincl);
	__state->sinio = sin(__state->xincl);
	__state->theta2 = __state->cosio * __state->cosio;
	__state->theta4 = __state->theta2 * __state->theta2;
	__state->x3thm1 = __state->theta2 * 3. - 1.;
	__state->x7thm1 = __state->theta2 * 7. - 1.;
	__state->x1mth2 = 1. - __state->theta2;
	__state->x1m5th = 1. - __state->theta2 * 5.;

/*        Eccentricity dependent constants */

	__state->betao = sqrt(1. - __state->eo * __state->eo);
	__state->betao2 = 1. - __state->eo * __state->eo;
	__state->betao3 = __state->betao * __state->betao2;
	__state->betao4 = __state->betao2 * __state->betao2;

/*        Semi-major axis and ascending node related constants. */

	d__1 = __state->ke / __state->xno;
	__state->a1 = pow_dd(&d__1, &__state->c_b91);
	__state->del1 = __state->ck2 * 1.5 * __state->x3thm1 / (__state->a1 * 
		__state->a1 * __state->betao3);
	__state->ao = __state->a1 * (1. - __state->del1 * (__state->del1 * (
		__state->del1 * 134. / 81. + 1.) + .33333333333333331));
	__state->delo = __state->ck2 * 1.5 * __state->x3thm1 / (__state->ao * 
		__state->ao * __state->betao3);
	__state->xnodp = __state->xno / (__state->delo + 1.);
	__state->aodp = __state->ao / (1. - __state->delo);
	__state->s4 = __state->s;
	__state->qoms24 = __state->qoms2t;
	__state->perige = __state->er * (__state->aodp * (1. - __state->eo) - 
		__state->ae);

/*        For perigee below 156 km, the values of S and QOMS2T are */
/*        altered. */

	if (__state->perige < 156.) {
	    __state->s4 = __state->perige - 78.;
	    if (__state->perige <= 98.) {
		__state->s4 = 20.;
	    }
/* Computing 4th power */
	    d__1 = (120. - __state->s4) * __state->ae / __state->er, d__1 *= 
		    d__1;
	    __state->qoms24 = d__1 * d__1;
	    __state->s4 = __state->ae + __state->s4 / __state->er;
	}

/*        The next block is simply a pretty print of the code in */
/*        sgp4 from label number 10 through the label 90. */

	__state->pinvsq = 1. / (__state->aodp * __state->aodp * 
		__state->betao4);
	__state->tsi = 1. / (__state->aodp - __state->s4);
	__state->eta = __state->aodp * __state->eo * __state->tsi;
	__state->etasq = __state->eta * __state->eta;
	__state->eeta = __state->eo * __state->eta;
/* Computing 4th power */
	d__1 = __state->tsi, d__1 *= d__1;
	__state->coef = __state->qoms24 * (d__1 * d__1);
	__state->psisq = (d__1 = 1. - __state->etasq, abs(d__1));
	__state->coef1 = __state->coef / pow_dd(&__state->psisq, &
		__state->c_b92);
	__state->c2 = __state->coef1 * __state->xnodp * (__state->aodp * (
		__state->etasq * 1.5 + 1. + __state->eeta * (__state->etasq + 
		4.)) + __state->ck2 * .75 * (__state->tsi / __state->psisq) * 
		__state->x3thm1 * (__state->etasq * (__state->etasq * 3. + 
		24.) + 8.));
	__state->c1 = __state->c2 * __state->bstar;
	__state->c3 = __state->coef * __state->tsi * __state->a3ovk2 * 
		__state->xnodp * __state->ae * __state->sinio / __state->eo;
	__state->c4 = __state->xnodp * 2. * __state->coef1 * __state->aodp * 
		__state->betao2 * (__state->eta * (__state->etasq * .5 + 2.) 
		+ __state->eo * (__state->etasq * 2. + .5) - __state->ck2 * 
		__state->tsi / (__state->aodp * __state->psisq) * 2. * (
		__state->x3thm1 * -3. * (1. - __state->eeta * 2. + 
		__state->etasq * (1.5 - __state->eeta * .5)) + cos(
		__state->omegao * 2.) * .75 * __state->x1mth2 * (
		__state->etasq * 2. - __state->eeta * (__state->etasq + 1.))))
		;
	__state->c5 = __state->coef1 * 2. * __state->aodp * __state->betao2 * 
		((__state->etasq + __state->eeta) * 2.75 + 1. + __state->eeta 
		* __state->etasq);
	__state->temp1 = __state->ck2 * 3. * __state->pinvsq * __state->xnodp;
	__state->temp2 = __state->temp1 * __state->ck2 * __state->pinvsq;
	__state->temp3 = __state->ck4 * 1.25 * __state->pinvsq * 
		__state->pinvsq * __state->xnodp;
	__state->xmdot = __state->xnodp + __state->temp1 * .5 * 
		__state->betao * __state->x3thm1 + __state->temp2 * .0625 * 
		__state->betao * (13. - __state->theta2 * 78. + 
		__state->theta4 * 137.);
	__state->omgdot = __state->temp1 * -.5 * __state->x1m5th + 
		__state->temp2 * .0625 * (7. - __state->theta2 * 114. + 
		__state->theta4 * 395.) + __state->temp3 * (3. - 
		__state->theta2 * 36. + __state->theta4 * 49.);
	__state->xhdot1 = -__state->temp1 * __state->cosio;
	__state->xnodot = __state->xhdot1 + __state->cosio * (__state->temp2 *
		 .5 * (4. - __state->theta2 * 19.) + __state->temp3 * 2. * (
		3. - __state->theta2 * 7.));
	__state->omgcof = __state->bstar * __state->c3 * cos(__state->omegao);
	__state->xmcof = -__state->bstar * .66666666666666663 * __state->coef 
		* __state->ae / __state->eeta;
	__state->xnodcf = __state->betao2 * 3.5 * __state->xhdot1 * 
		__state->c1;
	__state->t2cof = __state->c1 * 1.5;
	__state->aycof = __state->a3ovk2 * .25 * __state->sinio;
	__state->xlcof = __state->aycof * .5 * (__state->cosio * 5. + 3.) / (
		__state->cosio + 1.);
/* Computing 3rd power */
	d__1 = __state->eta * cos(__state->xmo) + 1.;
	__state->delmo = d__1 * (d__1 * d__1);
	__state->sinmo = sin(__state->xmo);

/*        For perigee less than 220 kilometers, the ISIMP flag is set */
/*        and the equations are truncated to linear variation in SQRT */
/*        A and quadratic variation in mean anomaly.  Also, the C3 */
/*        term, the Delta OMEGA term, and the Delta M term are */
/*        dropped.  (Note: Normally we would just use */

	if (__state->perige >= 220.) {
	    __state->c1sq = __state->c1 * __state->c1;
	    __state->d2 = __state->tsi * 4. * __state->c1sq * __state->aodp;
	    __state->temp = __state->d2 * __state->tsi * __state->c1 * 
		    .33333333333333331;
	    __state->d3 = __state->temp * (__state->s4 + __state->aodp * 17.);
	    __state->d4 = __state->temp * __state->tsi * __state->c1 * 
		    __state->aodp * .5 * (__state->aodp * 221. + __state->s4 *
		     31.);
	    __state->t3cof = __state->d2 + __state->c1sq * 2.;
	    __state->t4cof = (__state->d3 * 3. + __state->c1 * (__state->d2 * 
		    12. + __state->c1sq * 10.)) * .25;
	    __state->t5cof = (__state->d4 * 3. + __state->c1 * 12. * 
		    __state->d3 + __state->d2 * 6. * __state->d2 + 
		    __state->c1sq * 15. * (__state->d2 * 2. + __state->c1sq)) 
		    * .2;
	}

/*        Now store the intermediate computations so that if we */
/*        should hit this model again we can just look up the needed */
/*        results from the above computations. */

	__state->prelim[(i__1 = __state->n * 29 - 29) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)992)] = 
		__state->aodp;
	__state->prelim[(i__1 = __state->n * 29 - 28) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)993)] = 
		__state->aycof;
	__state->prelim[(i__1 = __state->n * 29 - 27) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)994)] = 
		__state->c1;
	__state->prelim[(i__1 = __state->n * 29 - 26) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)995)] = 
		__state->c4;
	__state->prelim[(i__1 = __state->n * 29 - 25) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)996)] = 
		__state->c5;
	__state->prelim[(i__1 = __state->n * 29 - 24) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)997)] = 
		__state->cosio;
	__state->prelim[(i__1 = __state->n * 29 - 23) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)998)] = 
		__state->d2;
	__state->prelim[(i__1 = __state->n * 29 - 22) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)999)] = 
		__state->d3;
	__state->prelim[(i__1 = __state->n * 29 - 21) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1000)] = 
		__state->d4;
	__state->prelim[(i__1 = __state->n * 29 - 20) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1001)] = 
		__state->delmo;
	__state->prelim[(i__1 = __state->n * 29 - 19) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1002)] = 
		__state->eta;
	__state->prelim[(i__1 = __state->n * 29 - 18) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1003)] = 
		__state->omgcof;
	__state->prelim[(i__1 = __state->n * 29 - 17) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1004)] = 
		__state->omgdot;
	__state->prelim[(i__1 = __state->n * 29 - 16) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1005)] = 
		__state->perige;
	__state->prelim[(i__1 = __state->n * 29 - 15) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1006)] = 
		__state->sinio;
	__state->prelim[(i__1 = __state->n * 29 - 14) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1007)] = 
		__state->sinmo;
	__state->prelim[(i__1 = __state->n * 29 - 13) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1008)] = 
		__state->t2cof;
	__state->prelim[(i__1 = __state->n * 29 - 12) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1009)] = 
		__state->t3cof;
	__state->prelim[(i__1 = __state->n * 29 - 11) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1010)] = 
		__state->t4cof;
	__state->prelim[(i__1 = __state->n * 29 - 10) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1011)] = 
		__state->t5cof;
	__state->prelim[(i__1 = __state->n * 29 - 9) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1012)] = 
		__state->x1mth2;
	__state->prelim[(i__1 = __state->n * 29 - 8) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1013)] = 
		__state->x3thm1;
	__state->prelim[(i__1 = __state->n * 29 - 7) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1014)] = 
		__state->x7thm1;
	__state->prelim[(i__1 = __state->n * 29 - 6) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1015)] = 
		__state->xlcof;
	__state->prelim[(i__1 = __state->n * 29 - 5) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1016)] = 
		__state->xmcof;
	__state->prelim[(i__1 = __state->n * 29 - 4) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1017)] = 
		__state->xmdot;
	__state->prelim[(i__1 = __state->n * 29 - 3) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1018)] = 
		__state->xnodcf;
	__state->prelim[(i__1 = __state->n * 29 - 2) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1019)] = 
		__state->xnodot;
	__state->prelim[(i__1 = __state->n * 29 - 1) < 174 && 0 <= i__1 ? 
		i__1 : s_rnge("prelim", i__1, "ev2lin_", (ftnlen)1020)] = 
		__state->xnodp;

/*        Finally, move these elements in the storage area */
/*        for checking the next time through. */

	for (__state->i__ = 1; __state->i__ <= 10; ++__state->i__) {
	    __state->elemnt[(i__1 = __state->i__ + __state->n * 10 - 11) < 60 
		    && 0 <= i__1 ? i__1 : s_rnge("elemnt", i__1, "ev2lin_", (
		    ftnlen)1026)] = elems[__state->i__ - 1];
	}
    }

/*     Now that all of the introductions are out of the way */
/*     we can get down to business. */

/*     Compute the time since the epoch for this model. */

    __state->tsince = *et - __state->epoch;

/*     and convert it to minutes */

    __state->tsince /= 60.;
    __state->xmdf = __state->xmo + __state->xmdot * __state->tsince;
    __state->omgadf = __state->omegao + __state->omgdot * __state->tsince;
    __state->xnoddf = __state->xnodeo + __state->xnodot * __state->tsince;
    __state->omega = __state->omgadf;
    __state->xmp = __state->xmdf;
    __state->tsq = __state->tsince * __state->tsince;
    __state->xnode = __state->xnoddf + __state->xnodcf * __state->tsq;
    __state->tempa = 1. - __state->c1 * __state->tsince;
    __state->tempe = __state->bstar * __state->c4 * __state->tsince;
    __state->templ = __state->t2cof * __state->tsq;
    if (__state->perige > 220.) {
	__state->tcube = __state->tsq * __state->tsince;
	__state->tfour = __state->tcube * __state->tsince;
	__state->delomg = __state->omgcof * __state->tsince;
/* Computing 3rd power */
	d__1 = __state->eta * cos(__state->xmdf) + 1.;
	__state->delm = __state->xmcof * (d__1 * (d__1 * d__1) - 
		__state->delmo);
	__state->temp = __state->delomg + __state->delm;
	__state->xmp = __state->xmdf + __state->temp;
	__state->omega = __state->omgadf - __state->temp;
	__state->tempa = __state->tempa - __state->d2 * __state->tsq - 
		__state->d3 * __state->tcube - __state->d4 * __state->tfour;
	__state->tempe += __state->bstar * __state->c5 * (sin(__state->xmp) - 
		__state->sinmo);
	__state->templ = __state->templ + __state->tcube * __state->t3cof + 
		__state->tfour * (__state->t4cof + __state->tsince * 
		__state->t5cof);
    }
/* Computing 2nd power */
    d__1 = __state->tempa;
    __state->a = __state->aodp * (d__1 * d__1);
    __state->xl = __state->xmp + __state->omega + __state->xnode + 
	    __state->xnodp * __state->templ;
    __state->e = __state->eo - __state->tempe;

/*     The parameter BETA used to be needed, but it's only use */
/*     was in the computation of TEMP below where it got squared */
/*     so we'll remove it from the list of things to compute. */

/*     BETA =  DSQRT( 1.0D0 - E*E ) */

    __state->xn = __state->ke / pow_dd(&__state->a, &__state->c_b153);

/*     Long period periodics */

    __state->temp = 1. / (__state->a * (1. - __state->e * __state->e));
    __state->aynl = __state->temp * __state->aycof;
    __state->ayn = __state->e * sin(__state->omega) + __state->aynl;
    __state->axn = __state->e * cos(__state->omega);
    __state->xll = __state->temp * __state->xlcof * __state->axn;
    __state->xlt = __state->xl + __state->xll;

/*     Solve keplers equation. */

/*     We are going to solve for the roots of this equation by */
/*     using a mixture of Newton's method and the prescription for */
/*     root finding outlined in the SPICE routine UNITIM. */

/*     We are going to solve the equation */

/*           U = EPW - AXN * SIN(EPW)  +  AYN * COS(EPW) */

/*     Where */

/*        AYN  = E    * SIN(OMEGA)   +    AYNL */
/*        AXN  = E    * COS(OMEGA) */

/*     And */

/*        AYNL =  -0.50D0  * SINIO * AE * J3   / (J2*A*(1.0D0 - E*E)) */

/*     Since this is a low earth orbiter (period less than 225 minutes) */
/*     The maximum value E can take (without having the orbiter */
/*     plowing fields) is approximately 0.47 and AYNL will not be */
/*     more than about .01.  ( Typically E will be much smaller */
/*     on the order of about .1 )  Thus we can initially */
/*     view the problem of solving the equation for EPW as a */
/*     function of the form */

/*     U = EPW + F ( EPW )                                   (1) */

/*     Where F( EPW ) = -AXN*SIN(EPW) + AYN*COS(EPW) */

/*     Note that | F'(EPW) | < M =  DSQRT( AXN**2 + AYN**2 ) < 0.48 */

/*     From the above discussion it is evident that F is a contraction */
/*     mapping.  So that we can employ the same techniques as were */
/*     used in the routine UNITIM to get our first approximations of */
/*     the root.  Once we have some good first approximations, we */
/*     will speed up the root finding by using Newton's method for */
/*     finding a zero of a function.  The function we will work on */
/*     is */

/*        f  (x) = x - U - AXN*SIN(x) + AYN*COS(x)         (2) */

/*     By applying Newton's method we will go from linear to */
/*     quadratic convergence. */

/*     We will keep track of our error bounds along the way so */
/*     that we will know how many iterations to perform in each */
/*     phase of the root extraction. */

/*     few steps using bisection. */


/*     For the benefit of those interested */
/*     here's the basics of what we'll do. */

/*        Whichever EPW satisfies equation (1) will be */
/*        unique. The uniqueness of the solution is ensured because the */
/*        expression on the right-hand side of the equation is */
/*        monotone increasing in EPW. */

/*        Let's suppose that EPW is the solution, then the following */
/*        is true. */

/*           EPW = U - F(EPW) */

/*        but we can also replace the EPW on the right hand side of the */
/*        equation by U - F(EPW).  Thus */

/*           EPW = U - F( U - F(EPW)) */

/*               = U - F( U - F( U - F(EPW))) */

/*               = U - F( U - F( U - F( U - F(EPW)))) */

/*               = U - F( U - F( U - F( U - F( U - F(EPW))))) */
/*               . */
/*               . */
/*               . */
/*               = U - F( U - F( U - F( U - F( U - F(U - ... ))) */

/*        and so on, for as long as we have patience to perform the */
/*        substitutions. */

/*        The point of doing this recursive substitution is that we */
/*        hope to move EPW to an insignificant part of the computation. */
/*        This would seem to have a reasonable chance of success since */
/*        F is a bounded and has a small derivative. */

/*        Following this idea, we will attempt to solve for EPW using */
/*        the recursive method outlined below. */

/*     We will make our first guess at EPW, call it EPW_0. */

/*        EPW_0 = U */

/*     Our next guess, EPW_1, is given by: */

/*        EPW_1 = U - F(EPW_0) */

/*     And so on: */

/*        EPW_2 = U - F(EPW_1)        [ = U - F(U - F(U))          ] */
/*        EPW_3 = U - F(EPW_2)        [ = U - F(U - F(U - F(U)))   ] */
/*           . */
/*           . */
/*           . */
/*        EPW_n = U - F(EPW_(n-1))    [ = U - F(U - F(U - F(U...)))] */

/*        The questions to ask at this point are: */

/*           1) Do the EPW_i's converge? */
/*           2) If they converge, do they converge to EPW? */
/*           3) If they converge to EPW, how fast do they get there? */

/*        1) The sequence of approximations converges. */

/*           | EPW_n - EPW_(n-1) | =  [ U - F( EPW_(n-1) ) ] */
/*                                 -  [ U - F( EPW_(n-2) ) ] */

/*                                 =  [ F( EPW_(n-2) ) - F( EPW_(n-1)) ] */

/*     The function F has an important property. The absolute */
/*     value of its derivative is always less than M. */
/*     This means that for any pair of real numbers s,t */

/*        | F(t) - F(s) |  < M*| t - s |. */

/*     From this observation, we can see that */

/*        | EPW_n - EPW_(n-1) | < M*| EPW_(n-1) - EPW_(n-2) | */

/*     With this fact available, we could (with a bit more work) */
/*     conclude that the sequence of EPW_i's converges and that */
/*     it converges at a rate that is at least as fast as the */
/*     sequence M, M**2, M**3.  In fact the difference */
/*        |EPW - EPW_N| < M/(1-M) * | EPW_N - EPW_(N-1) | */

/*                       < M/(1-M) * M**N | EPW_1 - EPW_0 | */

/*     2) If we let EPW be the limit of the EPW_i's then it follows */
/*        that */

/*               EPW = U - F(EPW). */


/*     or that */

/*               U = EPW + F(EPW). */

/*     We will use this technique to get an approximation that */
/*     is within a tolerance of EPW and then switch to */
/*     a Newton's method. (We'll compute the tolerance using */
/*     the value of M given above). */


/*     For the Newton's method portion of the problem, recall */
/*     from Taylor's formula that: */

/*        f(x) = f(x_0) + f'(x_0)(x-x_0) +  f''(c)/2 (x-x_0)**2 */

/*     for some c between x and x_0 */

/*     If x happens to be a zero of f then we can rearrange the */
/*     terms above to get */

/*                       f(x_0)       f''(c) */
/*           x = x_0 -   -------  +  -------- ( x - x_0)**2 */
/*                       f'(x_0)      f'(x_0) */

/*     Thus the error in the Newton approximation */


/*                       f(x_0) */
/*           x = x_0  -  ------- */
/*                       f'(x_0) */

/*     is */

/*                     f''(c) */
/*                    -------- ( x - x_0)**2 */
/*                     f'(x_0) */

/*     Thus if we can bound f'' and pick a good first */
/*     choice for x_0 (using the first method outlined */
/*     above we can get quadratic convergence.) */

/*     In our case we have */

/*        f  (x) = x - U - AXN*SIN(x) + AYN*COS(x) */
/*        f' (x) = 1     - AXN*COS(x) - AYN*SIN(x) */
/*        f''(x) =         AXN*SIN(x) - AYN*COS(x) */

/*     So that: */

/*        f' (x) >  1 - M */

/*        f''(x) <  M */

/*     Thus the error in the Newton's approximation is */
/*     at most */

/*        M/(1-M) * ( x - x_0 )**2 */

/*     Thus as long as our original estimate (determined using */
/*     the contraction method) gets within a reasonable tolerance */
/*     of x, we can use Newton's method to acheive faster */
/*     convergence. */

    __state->m = sqrt(__state->axn * __state->axn + __state->ayn * 
	    __state->ayn);
    __state->mov1m = (d__1 = __state->m / (1. - __state->m), abs(d__1));
    d__1 = __state->xlt - __state->xnode;
    __state->fmod2p = d_mod(&d__1, &__state->pix2);
    if (__state->fmod2p < 0.) {
	__state->fmod2p += __state->pix2;
    }
    __state->capu = __state->fmod2p;
    __state->epw = __state->capu;
    __state->est = 1.;
    __state->count = 0;
    while(__state->est > .125) {
	++__state->count;
	if (__state->count > 20) {
	    setmsg_("EST iteration count of #1 exceeded at time ET #2. This "
		    "error may indicate a bad TLE set.", (ftnlen)88);
	    errint_("#1", &__state->c__20, (ftnlen)2);
	    errdp_("#2", et, (ftnlen)2);
	    sigerr_("SPICE(ITERATIONEXCEEDED)", (ftnlen)24);
	    chkout_("EV2LIN", (ftnlen)6);
	    return 0;
	}
	__state->epwnxt = __state->capu - __state->axn * sin(__state->epw) + 
		__state->ayn * cos(__state->epw);
	__state->est = __state->mov1m * (d__1 = __state->epwnxt - 
		__state->epw, abs(d__1));
	__state->epw = __state->epwnxt;
    }

/*     We need to be able to add something to EPW and not */
/*     get EPW (but not too much). */

    __state->epsiln = __state->est;
    if (__state->epsiln + __state->epw != __state->epw) {

/*        Now we switch over to Newton's method.  Note that */
/*        since our error estimate is less than 1/8, six iterations */
/*        of Newton's method should get us to within 1/2**96 of */
/*        the correct answer (If there were no round off to contend */
/*        with). */

	for (__state->i__ = 1; __state->i__ <= 5; ++__state->i__) {
	    __state->sinepw = sin(__state->epw);
	    __state->cosepw = cos(__state->epw);
	    __state->f = __state->epw - __state->capu - __state->axn * 
		    __state->sinepw + __state->ayn * __state->cosepw;
	    __state->fprime = 1. - __state->axn * __state->cosepw - 
		    __state->ayn * __state->sinepw;
	    __state->epwnxt = __state->epw - __state->f / __state->fprime;

/*           Our new error estimate comes from the discussion */
/*           of convergence of Newton's method. */

	    __state->epw = __state->epwnxt;
	    if (__state->epw + __state->est != __state->epw) {
		__state->epsiln = __state->est;
		__state->est = __state->mov1m * __state->est * __state->est;
	    }
	}
    }

/*     Finally, we use bisection to avoid the problems of */
/*     round-off that may be present in Newton's method.  Since */
/*     we've gotten quite close to the answer (theoretically */
/*     anyway)  we won't have to perform many bisection passes. */

/*     First we must bracket the root.  Note that we will */
/*     increase EPSILN so that we don't spend much time */
/*     determining the bracketing interval.  Also if the first */
/*     addition of EPSILN to EPW doesn't modify it, were set up */
/*     to just quit.  This happens only if F is sufficiently */
/*     close to zero that it can't alter EPW by adding it to */
/*     or subtracting it from EPW. */

    __state->sinepw = sin(__state->epw);
    __state->cosepw = cos(__state->epw);
    __state->f = __state->epw - __state->capu - __state->axn * 
	    __state->sinepw + __state->ayn * __state->cosepw;
/* Computing MAX */
    d__1 = abs(__state->f);
    __state->epsiln = max(d__1,__state->epsiln);
    if (__state->f == 0.) {
	__state->lower = __state->epw;
	__state->upper = __state->epw;
    } else if (__state->f > 0.) {
	__state->fu = __state->f;
	__state->upper = __state->epw;
	__state->lower = __state->epw - __state->epsiln;
	__state->epw = __state->lower;
	while(__state->f > 0. && __state->lower != __state->upper) {
	    __state->epw -= __state->epsiln;
	    __state->f = __state->epw - __state->capu - __state->axn * sin(
		    __state->epw) + __state->ayn * cos(__state->epw);
	    __state->epsiln *= 2.;
	}
	__state->lower = __state->epw;
	__state->fl = __state->f;
	if (__state->f == 0.) {
	    __state->upper = __state->lower;
	}
    } else if (__state->f < 0.) {
	__state->fl = __state->f;
	__state->lower = __state->epw;
	__state->upper = __state->epw + __state->epsiln;
	__state->epw = __state->upper;
	while(__state->f < 0. && __state->lower != __state->upper) {
	    __state->epw += __state->epsiln;
	    __state->f = __state->epw - __state->capu - __state->axn * sin(
		    __state->epw) + __state->ayn * cos(__state->epw);
	    __state->epsiln *= 2.;
	}
	__state->upper = __state->epw;
	__state->fu = __state->f;
	if (__state->f == 0.) {
	    __state->lower = __state->epw;
	}
    }

/*     Finally, bisect until we can do no more. */

    __state->count = 0;
    while(__state->upper > __state->lower && __state->count < 20) {
	++__state->count;
	d__1 = (__state->upper + __state->lower) * .5;
	__state->epw = brcktd_(&d__1, &__state->lower, &__state->upper);

/*        EPW eventually will not be different from one of the */
/*        two bracketing values.  If this is the time, we need */
/*        to decide on a value for EPW.  That's done below. */

	if (__state->epw == __state->upper || __state->epw == __state->lower) 
		{
	    if (-__state->fl < __state->fu) {
		__state->epw = __state->lower;
		__state->upper = __state->lower;
	    } else {
		__state->epw = __state->upper;
		__state->lower = __state->upper;
	    }
	} else {
	    __state->f = __state->epw - __state->capu - __state->axn * sin(
		    __state->epw) + __state->ayn * cos(__state->epw);
	    if (__state->f > 0.) {
		__state->upper = __state->epw;
		__state->fu = __state->f;
	    } else if (__state->f < 0.) {
		__state->lower = __state->epw;
		__state->fl = __state->f;
	    } else {
		__state->lower = __state->epw;
		__state->upper = __state->epw;
	    }
	}
    }

/*     Short period preliminary quantities */

    __state->sinepw = sin(__state->epw);
    __state->cosepw = cos(__state->epw);
    __state->temp3 = __state->axn * __state->sinepw;
    __state->temp4 = __state->ayn * __state->cosepw;
    __state->temp5 = __state->axn * __state->cosepw;
    __state->temp6 = __state->ayn * __state->sinepw;
    __state->ecose = __state->temp5 + __state->temp6;
    __state->esine = __state->temp3 - __state->temp4;
    __state->elsq = __state->axn * __state->axn + __state->ayn * __state->ayn;
    __state->temp = 1. - __state->elsq;
    __state->pl = __state->a * __state->temp;
    __state->r__ = __state->a * (1. - __state->ecose);
    __state->temp1 = 1. / __state->r__;
    __state->rdot = __state->ke * __state->temp1 * sqrt(__state->a) * 
	    __state->esine;
    __state->rfdot = __state->ke * __state->temp1 * sqrt(__state->pl);
    __state->temp2 = __state->a * __state->temp1;
    __state->betal = sqrt(__state->temp);
    __state->temp3 = 1. / (__state->betal + 1.);
    __state->cosu = __state->temp2 * (__state->cosepw - __state->axn + 
	    __state->ayn * __state->esine * __state->temp3);
    __state->sinu = __state->temp2 * (__state->sinepw - __state->ayn - 
	    __state->axn * __state->esine * __state->temp3);

/*     Compute the angle from the x-axis of the point ( COSU, SINU ) */

    if (__state->sinu != 0. || __state->cosu != 0.) {
	__state->u = atan2(__state->sinu, __state->cosu);
	if (__state->u < 0.) {
	    __state->u += __state->pix2;
	}
    } else {
	__state->u = 0.;
    }
    __state->sin2u = __state->sinu * 2. * __state->cosu;
    __state->cos2u = __state->cosu * 2. * __state->cosu - 1.;
    __state->temp = 1. / __state->pl;
    __state->temp1 = __state->ck2 * __state->temp;
    __state->temp2 = __state->temp1 * __state->temp;

/*     Update for short periodics */

    __state->rk = __state->r__ * (1. - __state->temp2 * 1.5 * __state->betal *
	     __state->x3thm1) + __state->temp1 * .5 * __state->x1mth2 * 
	    __state->cos2u;
    __state->uk = __state->u - __state->temp2 * .25 * __state->x7thm1 * 
	    __state->sin2u;
    __state->xnodek = __state->xnode + __state->temp2 * 1.5 * __state->cosio *
	     __state->sin2u;
    __state->xinck = __state->xincl + __state->temp2 * 1.5 * __state->cosio * 
	    __state->cos2u * __state->sinio;
    __state->rdotk = __state->rdot - __state->xn * __state->temp1 * 
	    __state->x1mth2 * __state->sin2u;
    __state->rfdotk = __state->rfdot + __state->xn * __state->temp1 * (
	    __state->x1mth2 * __state->cos2u + __state->x3thm1 * 1.5);

/*     Orientation vectors */

    __state->sinuk = sin(__state->uk);
    __state->cosuk = cos(__state->uk);
    __state->sinik = sin(__state->xinck);
    __state->cosik = cos(__state->xinck);
    __state->sinnok = sin(__state->xnodek);
    __state->cosnok = cos(__state->xnodek);
    __state->xmx = -__state->sinnok * __state->cosik;
    __state->xmy = __state->cosnok * __state->cosik;
    __state->ux = __state->xmx * __state->sinuk + __state->cosnok * 
	    __state->cosuk;
    __state->uy = __state->xmy * __state->sinuk + __state->sinnok * 
	    __state->cosuk;
    __state->uz = __state->sinik * __state->sinuk;
    __state->vx = __state->xmx * __state->cosuk - __state->cosnok * 
	    __state->sinuk;
    __state->vy = __state->xmy * __state->cosuk - __state->sinnok * 
	    __state->sinuk;
    __state->vz = __state->sinik * __state->cosuk;

/*     Position and velocity */

    state[0] = __state->tokm * __state->rk * __state->ux;
    state[1] = __state->tokm * __state->rk * __state->uy;
    state[2] = __state->tokm * __state->rk * __state->uz;
    state[3] = __state->tokmps * (__state->rdotk * __state->ux + 
	    __state->rfdotk * __state->vx);
    state[4] = __state->tokmps * (__state->rdotk * __state->uy + 
	    __state->rfdotk * __state->vy);
    state[5] = __state->tokmps * (__state->rdotk * __state->uz + 
	    __state->rfdotk * __state->vz);
    chkout_("EV2LIN", (ftnlen)6);
    return 0;
} /* ev2lin_ */

