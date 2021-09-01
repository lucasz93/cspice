/* sydupc.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern sydupc_init_t __sydupc_init;
static sydupc_state_t* get_sydupc_state(cspice_t* state) {
	if (!state->sydupc)
		state->sydupc = __cspice_allocate_module(sizeof(
	sydupc_state_t), &__sydupc_init, sizeof(__sydupc_init));
	return state->sydupc;

}

/* $Procedure      SYDUPC ( Create a duplicate of a symbol ) */
/* Subroutine */ int sydupc_(cspice_t* __global_state, char *name__, char *
	copy, char *tabsym, integer *tabptr, char *tabval, ftnlen name_len, 
	ftnlen copy_len, ftnlen tabsym_len, ftnlen tabval_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer nval;
    integer nptr;
    integer nsym;
    integer i__;
    extern integer cardc_(cspice_t*, char *, ftnlen);
    extern integer cardi_(cspice_t*, integer *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern integer sizec_(cspice_t*, char *, ftnlen);
    extern integer sumai_(cspice_t*, integer *, integer *);
    extern integer sizei_(cspice_t*, integer *);
    extern /* Subroutine */ int scardc_(cspice_t*, integer *, char *, ftnlen);
    extern /* Subroutine */ int remlac_(cspice_t*, integer *, integer *, char 
	    *, integer *, ftnlen);
    extern /* Subroutine */ int scardi_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int inslac_(cspice_t*, char *, integer *, integer 
	    *, char *, integer *, ftnlen, ftnlen);
    integer dimval[2];
    extern /* Subroutine */ int inslai_(cspice_t*, integer *, integer *, 
	    integer *, integer *, integer *);
    integer locval[2];
    extern integer lstlec_(cspice_t*, char *, integer *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    integer newval;
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    integer locsym[2];
    logical oldsym[2];
    extern logical return_(cspice_t*);
    integer newsym;


    /* Module state */
    sydupc_state_t* __state = get_sydupc_state(__global_state);
/* $ Abstract */

/*     Create a duplicate of a symbol within a character symbol table. */
/*     If a symbol with the new name already exists, its components */
/*     are replaced. */

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

/*     SYMBOLS */

/* $ Keywords */

/*     SYMBOLS */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     NAME       I   Name of the symbol to be duplicated. */
/*     COPY       I   Name of the new symbol. */
/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL    I/O  Components of the symbol table. */


/* $ Detailed_Input */

/*     NAME       is the name of the symbol to be duplicated. The */
/*                components associated with NAME will be given to the */
/*                new symbol COPY. If NAME is not in the symbol table, */
/*                no duplicate symbol can be made. */

/*     COPY       is the name of the new symbol. If a symbol with the */
/*                name COPY already exists in the symbol table, its */
/*                components are replaced by the components of NAME. */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL     are the components of a character symbol table. */

/* $ Detailed_Output */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL      are the components of a character symbol table. */
/*                 On output, the symbol table contains a new symbol COPY */
/*                 whose components are the same as the components of */
/*                 NAME. */

/* $ Parameters */

/*     None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     1) If the symbol NAME is not in the symbol table, the error */
/*        SPICE(NOSUCHSYMBOL) is signalled. */

/*     2) If duplication of the symbol causes an overflow in the */
/*        name table, the error SPICE(NAMETABLEFULL) is signalled. */

/*     3) If duplication of the symbol causes an overflow in the */
/*        pointer table, the error SPICE(POINTERTABLEFULL) is signalled. */

/*     4) If duplication of the symbol causes an overflow in the */
/*        value table, the error SPICE(VALUETABLEFULL) is signalled. */

/* $ Particulars */

/*     If the symbol NAME is not in the symbol table, no duplicate symbol */
/*     can be made. */
/*     If the symbol COPY is already in the symbol table, its components */
/*     are replaced by the components of NAME. */

/* $ Examples */

/*     The contents of the symbol table are: */

/*        BOHR      -->   HYDROGEN ATOM */
/*        EINSTEIN  -->   SPECIAL RELATIVITY */
/*                        PHOTOELECTRIC EFFECT */
/*                        BROWNIAN MOTION */
/*        FERMI     -->   NUCLEAR FISSION */

/*     The code, */

/*     CALL SYDUPC ( 'FERMI', 'HAHN', TABSYM, TABPTR, TABVAL ) */

/*     produces the symbol table: */

/*        BOHR      -->   HYDROGEN ATOM */
/*        EINSTEIN  -->   SPECIAL RELATIVITY */
/*                        PHOTOELECTRIC EFFECT */
/*                        BROWNIAN MOTION */
/*        FERMI     -->   NUCLEAR FISSION */
/*        HAHN      -->   NUCLEAR FISSION */

/*     The code, */

/*     CALL SYDUPC ( 'STRASSMAN', 'HAHN', TABSYM, TABPTR, TABVAL ) */

/*     produces the error SPICE(NOSUCHSYMBOL) because the symbol */
/*     "STRASSMAN" is not in the symbol table. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     H.A. Neilan     (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -     SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*         Comment section for permuted index source lines was added */
/*         following the header. */

/* -     SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) (HAN) */

/* -& */
/* $ Index_Entries */

/*     create a duplicate of a symbol */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "SYDUPC", (ftnlen)6);
    }

/*     How many symbols to start with? */

    nsym = cardc_(__global_state, tabsym, tabsym_len);
    nptr = cardi_(__global_state, tabptr);
    nval = cardc_(__global_state, tabval, tabval_len);

/*     Where do these symbols belong? Are they already in the table? */

    locsym[0] = lstlec_(__global_state, name__, &nsym, tabsym + tabsym_len * 
	    6, name_len, tabsym_len);
    locsym[1] = lstlec_(__global_state, copy, &nsym, tabsym + tabsym_len * 6, 
	    copy_len, tabsym_len);
    oldsym[0] = locsym[0] != 0 && s_cmp(&__global_state->f2c, tabsym + (
	    locsym[0] + 5) * tabsym_len, name__, tabsym_len, name_len) == 0;
    oldsym[1] = locsym[1] != 0 && s_cmp(&__global_state->f2c, tabsym + (
	    locsym[1] + 5) * tabsym_len, copy, tabsym_len, copy_len) == 0;

/*     If the original symbol is not in the table, we can't make a copy. */

    if (! oldsym[0]) {
	setmsg_(__global_state, "SYDUPC: The symbol to be duplicated, #, is "
		"not in the symbol table.", (ftnlen)67);
	errch_(__global_state, "#", name__, (ftnlen)1, name_len);
	sigerr_(__global_state, "SPICE(NOSUCHSYMBOL)", (ftnlen)19);

/*     Otherwise, we need to know the dimension, to check for overflow. */

    } else {
	i__1 = locsym[0] - 1;
	locval[0] = sumai_(__global_state, &tabptr[6], &i__1) + 1;
	dimval[0] = tabptr[locsym[0] + 5];

/*        If the new symbol already exists, we need to know its dimension */
/*        too, for the same reason. */

	if (oldsym[1]) {
	    i__1 = locsym[1] - 1;
	    locval[1] = sumai_(__global_state, &tabptr[6], &i__1) + 1;
	    dimval[1] = tabptr[locsym[1] + 5];
	    newsym = 0;
	} else {
	    locval[1] = sumai_(__global_state, &tabptr[6], &locsym[1]) + 1;
	    dimval[1] = 0;
	    newsym = 1;
	}
	newval = dimval[0] - dimval[1];

/*        Can we make a copy without overflow? */

	if (nsym + newsym > sizec_(__global_state, tabsym, tabsym_len)) {
	    setmsg_(__global_state, "SYDUPC: Duplication of the symbol # cau"
		    "ses an overflow in the name table.", (ftnlen)73);
	    errch_(__global_state, "#", name__, (ftnlen)1, name_len);
	    sigerr_(__global_state, "SPICE(NAMETABLEFULL)", (ftnlen)20);
	} else if (nptr + newsym > sizei_(__global_state, tabptr)) {
	    setmsg_(__global_state, "SYDUPC: Duplication of the symbol # cau"
		    "ses an overflow in the pointer table.", (ftnlen)76);
	    errch_(__global_state, "#", name__, (ftnlen)1, name_len);
	    sigerr_(__global_state, "SPICE(POINTERTABLEFULL)", (ftnlen)23);
	} else if (nval + newval > sizec_(__global_state, tabval, tabval_len))
		 {
	    setmsg_(__global_state, "SYDUPC: Duplication of the symbol # cau"
		    "ses an overflow in the value table.", (ftnlen)74);
	    errch_(__global_state, "#", name__, (ftnlen)1, name_len);
	    sigerr_(__global_state, "SPICE(VALUETABLEFULL)", (ftnlen)21);

/*        Looks like we can. */

	} else {

/*           If the copy exists, remove the current contents and */
/*           change the dimension. Otherwise add the new name and */
/*           dimension to the name and pointer tables. */

	    if (dimval[1] > 0) {
		remlac_(__global_state, &dimval[1], &locval[1], tabval + 
			tabval_len * 6, &nval, tabval_len);
		scardc_(__global_state, &nval, tabval, tabval_len);
		tabptr[locsym[1] + 5] = dimval[0];
		if (locval[0] > locval[1]) {
		    locval[0] -= dimval[1];
		}
	    } else {
		i__1 = locsym[1] + 1;
		inslac_(__global_state, copy, &__state->c__1, &i__1, tabsym + 
			tabsym_len * 6, &nsym, copy_len, tabsym_len);
		scardc_(__global_state, &nsym, tabsym, tabsym_len);
		i__1 = locsym[1] + 1;
		inslai_(__global_state, dimval, &__state->c__1, &i__1, &
			tabptr[6], &nptr);
		scardi_(__global_state, &nptr, tabptr);
	    }

/*           In either case, allocate space for the new symbol values, */
/*           and copy them in one by one. (INSLAx won't work if the */
/*           copy is earlier in the table than the original.) */

	    i__1 = locval[1];
	    for (i__ = nval; i__ >= i__1; --i__) {
		s_copy(&__global_state->f2c, tabval + (i__ + dimval[0] + 5) * 
			tabval_len, tabval + (i__ + 5) * tabval_len, 
			tabval_len, tabval_len);
	    }
	    if (locval[0] > locval[1]) {
		locval[0] += dimval[0];
	    }
	    i__1 = dimval[0] - 1;
	    for (i__ = 0; i__ <= i__1; ++i__) {
		s_copy(&__global_state->f2c, tabval + (locval[1] + i__ + 5) * 
			tabval_len, tabval + (locval[0] + i__ + 5) * 
			tabval_len, tabval_len, tabval_len);
	    }
	    i__1 = nval + dimval[0];
	    scardc_(__global_state, &i__1, tabval, tabval_len);
	}
    }
    chkout_(__global_state, "SYDUPC", (ftnlen)6);
    return 0;
} /* sydupc_ */

