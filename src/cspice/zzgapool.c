/* zzgapool.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzgapool_init_t __zzgapool_init;
static inline zzgapool_state_t* get_zzgapool_state(cspice_t* state) {
	if (!state->zzgapool)
		state->zzgapool = __cspice_allocate_module(sizeof(
	zzgapool_state_t), &__zzgapool_init, sizeof(__zzgapool_init));
	return state->zzgapool;

}

/* $Procedure ZZGAPOOL ( Private: get agent set for watched variable ) */
/* Subroutine */ int zzgapool_(cspice_t* __global_state, char *varnam, char *
	wtvars, integer *wtptrs, integer *wtpool, char *wtagnt, char *agtset, 
	ftnlen varnam_len, ftnlen wtvars_len, ftnlen wtagnt_len, ftnlen 
	agtset_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer node;
    extern integer cardc_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern integer sizec_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int scardc_(cspice_t*, integer *, char *, ftnlen);
    extern /* Subroutine */ int validc_(cspice_t*, integer *, integer *, char 
	    *, ftnlen);
    extern integer bsrchc_(cspice_t*, char *, integer *, char *, ftnlen, 
	    ftnlen);
    integer nfetch;
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern integer lnknxt_(cspice_t*, integer *, integer *);
    extern logical return_(cspice_t*);
    integer loc;


    /* Module state */
    zzgapool_state_t* __state = get_zzgapool_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines.  Users should not call this routine directly due to the */
/*     volatile nature of this routine. */

/*     Return a SPICE set containing the names of agents watching */
/*     a specified kernel variable. */

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

/*     KERNEL */

/* $ Keywords */

/*     KERNEL */
/*     PRIVATE */
/*     UTILITY */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     VARNAM     I   Kernel variable name. */
/*     WTVARS     I   Watched kernel variable set. */
/*     WTPTRS     I   Pointers from variables into the watch pool. */
/*     WTPOOL     I   Watch pool used for managing agent names. */
/*     WTAGNT     I   Array of agent names. */
/*     AGTSET     O   Set of agents for VARNAM. */

/* $ Detailed_Input */

/*     VARNAM      is the name of a kernel variable. */

/*     WTVARS      is a SPICE set containing the contents of the kernel */
/*                 pool watcher system's set WTVARS. */

/*     WTPTRS      is an array containing the contents of the kernel */
/*                 pool watcher system's array WTPTRS. */

/*     WTPOOL      is a SPICE doubly linked list pool containing the */
/*                 contents of the kernel pool watcher system's pool */
/*                 WTPOOL. */

/*     WTAGNT      is an array containing the contents of the kernel */
/*                 pool watcher system's array WTAGNT. */

/* $ Detailed_Output */

/*     AGTSET      is a SPICE set containing the names of the agents */
/*                 associated with the kernel variable designated by */
/*                 VARNAM. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If the output set AGTSET is too small to hold the set of */
/*        agents watching VARNAM, the error will be diagnosed by routines */
/*        in the call tree of this routine. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine is not part of the SPICELIB API. This routine */
/*     may be removed in a later version of the SPICE Toolkit, or */
/*     its interface may change. */

/*     SPICE-based application code should not call this routine. */

/* $ Examples */

/*     See POOL entry point SWPOOL. */

/* $ Restrictions */

/*     1) This is a private routine. See $Particulars above. */

/*     2) Contents of the input arrays are assumed to be valid. */
/*        The output returned by this routine is meaningless */
/*        otherwise. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 17-MAR-2009 (NJB) */

/* -& */
/* $ Index_Entries */

/*     get agent set for watched kernel variable */

/* -& */
/* $ Revisions */

/*     None. */

/* -& */

/*     SPICELIB functions */


/*     Local variables */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "ZZGAPOOL", (ftnlen)8);

/*     The output agent set is empty until we find any */
/*     agents. */

    scardc_(__global_state, &__state->c__0, agtset, agtset_len);

/*     Find the location of VARNAM in the set of watched */
/*     variables. */

    i__1 = cardc_(__global_state, wtvars, wtvars_len);
    loc = bsrchc_(__global_state, varnam, &i__1, wtvars + wtvars_len * 6, 
	    varnam_len, wtvars_len);
    if (loc == 0) {

/*        This variable is not watched. The agent set is */
/*        empty. */

	chkout_(__global_state, "ZZGAPOOL", (ftnlen)8);
	return 0;
    }

/*     Set NODE to the head node of the agent list for VARNAM. */
/*     Traverse the agent list for VARNAM. Collect the agents */
/*     as an unordered list, then turn the list into a set. */

    node = wtptrs[loc - 1];
    nfetch = 0;
    while(node > 0) {
	++nfetch;
	s_copy(&__global_state->f2c, agtset + (nfetch + 5) * agtset_len, 
		wtagnt + (node - 1) * wtagnt_len, agtset_len, wtagnt_len);
	node = lnknxt_(__global_state, &node, wtpool);
    }
    i__1 = sizec_(__global_state, agtset, agtset_len);
    validc_(__global_state, &i__1, &nfetch, agtset, agtset_len);
    chkout_(__global_state, "ZZGAPOOL", (ftnlen)8);
    return 0;
} /* zzgapool_ */

