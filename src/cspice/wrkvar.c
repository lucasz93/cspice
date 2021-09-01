/* wrkvar.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern wrkvar_init_t __wrkvar_init;
static wrkvar_state_t* get_wrkvar_state(cspice_t* state) {
	if (!state->wrkvar)
		state->wrkvar = __cspice_allocate_module(sizeof(
	wrkvar_state_t), &__wrkvar_init, sizeof(__wrkvar_init));
	return state->wrkvar;

}

/* $Procedure      WRKVAR ( Write a variable to a kernel file ) */
/* Subroutine */ int wrkvar_(cspice_t* __global_state, integer *unit, char *
	name__, char *dirctv, char *tabsym, integer *tabptr, doublereal *
	tabval, ftnlen name_len, ftnlen dirctv_len, ftnlen tabsym_len)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer i_len(f2c_state_t*, char *, ftnlen);
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer s_wsle(f2c_state_t*, cilist *), do_lio(f2c_state_t*, integer *, 
	    integer *, char *, ftnlen), e_wsle(f2c_state_t*);

    /* Local variables */
    char line[132];
    integer i__;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    logical found;
    extern /* Subroutine */ int ioerr_(cspice_t*, char *, char *, integer *, 
	    ftnlen, ftnlen);
    extern /* Subroutine */ int ljust_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int rjust_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    integer margin;
    doublereal dvalue;
    integer vardim;
    integer varlen;
    extern integer sydimd_(cspice_t*, char *, char *, integer *, doublereal *,
	     ftnlen, ftnlen);
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    integer iostat;
    extern /* Subroutine */ int synthd_(cspice_t*, char *, integer *, char *, 
	    integer *, doublereal *, doublereal *, logical *, ftnlen, ftnlen);
    extern logical return_(cspice_t*);

    /* Fortran I/O blocks */



    /* Module state */
    wrkvar_state_t* __state = get_wrkvar_state(__global_state);
/* $ Abstract */

/*     Write the value of a variable in a double precision symbol */
/*     table to a NAIF ASCII kernel file. */

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

/*     KERNEL, SYMBOLS */

/* $ Keywords */

/*     FILES */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     UNIT       I   Output logical unit. */
/*     NAME       I   Name of the variable. */
/*     DIRCTV     I   Kernel directive: '=' or '+='. */
/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL    I/O  Symbol table. */

/* $ Detailed_Input */

/*     UNIT        is the logical unit to which the variable will be */
/*                 written. This is usually the logical unit to which */
/*                 the output kernel file is connected. */

/*     NAME        is the name of the variable to be written to UNIT. */

/*     DIRCTV      is the directive linking NAME and its associated */
/*                 values in the kernel file. This may be any of the */
/*                 directives recognized by RDKVAR. */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL      are the components of a double precision symbol */
/*                 table. On input, the table may or may not contain */
/*                 any variables. */

/* $ Detailed_Output */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL      are the components of a double precision symbol */
/*                 table. This subroutine does not change the components; */
/*                 they contain the same values on output as they did */
/*                 on input. */

/* $ Parameters */

/*      None. */

/* $ Files */

/*     If the variable is to be written to an output kernel file, the */
/*     file should be opened with a logical unit determined by the */
/*     calling program. */

/* $ Exceptions */

/*     1) If an error occurs writing the variable to UNIT, the */
/*        error SPICE(WRITEERROR) is signalled. */

/* $ Particulars */

/*     If the table symbol table does not contain any variables, nothing */
/*     will be written to UNIT. */

/* $ Examples */

/*     If  NAME   = 'MEAN_ANOM' */
/*         DIRCTV = '=' */

/*     And the contents of the symbol table are: */

/*          DELTA_T_A  -->   32.184 */
/*          K          -->    0.D0 */
/*          MEAN_ANOM  -->    6.239996D0 */
/*                            1.99096871D-7 */
/*          ORBIT_ECC  -->    1.671D-2 */

/*     The output to UNIT might look like this, depending on the */
/*     length of the symbol table variables: */

/*     MEAN_ANOM   = ( 6.239996D0, */
/*                     1.99096871D-7  ) */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) */

/* -& */
/* $ Index_Entries */

/*     write a variable to a kernel file */

/* -& */
/* $ Revisions */

/* -    Beta Version 1.1.0, 20-DEC-1988 (NJB) */

/*        Call to IOERR changed to be consistent with new calling */
/*        protocol.  SETMSG call deleted, since IOERR now calls SETMSG. */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "WRKVAR", (ftnlen)6);
    }

/*     Preliminary measurements. */

    varlen = i_len(&__global_state->f2c, tabsym + tabsym_len * 6, tabsym_len);
    margin = varlen + 6;
    vardim = sydimd_(__global_state, name__, tabsym, tabptr, tabval, name_len,
	     tabsym_len);

/*     One value per line. */

    i__1 = vardim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	synthd_(__global_state, name__, &i__, tabsym, tabptr, tabval, &dvalue,
		 &found, name_len, tabsym_len);

/*        The first line contains the variable name, the directive, */
/*        an optional left parenthesis, and the first value. The values */
/*        of a multi-dimensional variable are separated by commas. */

	if (i__ == 1) {
	    ljust_(__global_state, name__, line, name_len, (ftnlen)132);
	    i__2 = margin - 5;
	    rjust_(__global_state, dirctv, line + i__2, dirctv_len, margin - 
		    3 - i__2);
	    if (vardim > 1) {
		i__2 = margin - 2;
		s_copy(&__global_state->f2c, line + i__2, "(", margin - 1 - 
			i__2, (ftnlen)1);
		__state->io___9.ciunit = *unit;
		iostat = s_wsle(&__global_state->f2c, &__state->io___9);
		if (iostat != 0) {
		    goto L100001;
		}
		iostat = do_lio(&__global_state->f2c, &__state->c__9, &
			__state->c__1, line, margin);
		if (iostat != 0) {
		    goto L100001;
		}
		iostat = do_lio(&__global_state->f2c, &__state->c__5, &
			__state->c__1, (char *)&dvalue, (ftnlen)sizeof(
			doublereal));
		if (iostat != 0) {
		    goto L100001;
		}
		iostat = do_lio(&__global_state->f2c, &__state->c__9, &
			__state->c__1, ", ", (ftnlen)2);
		if (iostat != 0) {
		    goto L100001;
		}
		iostat = e_wsle(&__global_state->f2c);
L100001:
		;
	    } else {
		__state->io___10.ciunit = *unit;
		iostat = s_wsle(&__global_state->f2c, &__state->io___10);
		if (iostat != 0) {
		    goto L100002;
		}
		iostat = do_lio(&__global_state->f2c, &__state->c__9, &
			__state->c__1, line, margin);
		if (iostat != 0) {
		    goto L100002;
		}
		iostat = do_lio(&__global_state->f2c, &__state->c__5, &
			__state->c__1, (char *)&dvalue, (ftnlen)sizeof(
			doublereal));
		if (iostat != 0) {
		    goto L100002;
		}
		iostat = e_wsle(&__global_state->f2c);
L100002:
		;
	    }

/*        The last line of a multi-dimensional variable ends with a */
/*        right parenthesis. */

	} else if (i__ > 1 && i__ == vardim) {
	    s_copy(&__global_state->f2c, line, " ", (ftnlen)132, (ftnlen)1);
	    __state->io___11.ciunit = *unit;
	    iostat = s_wsle(&__global_state->f2c, &__state->io___11);
	    if (iostat != 0) {
		goto L100003;
	    }
	    iostat = do_lio(&__global_state->f2c, &__state->c__9, &
		    __state->c__1, line, margin);
	    if (iostat != 0) {
		goto L100003;
	    }
	    iostat = do_lio(&__global_state->f2c, &__state->c__5, &
		    __state->c__1, (char *)&dvalue, (ftnlen)sizeof(doublereal)
		    );
	    if (iostat != 0) {
		goto L100003;
	    }
	    iostat = do_lio(&__global_state->f2c, &__state->c__9, &
		    __state->c__1, "  )", (ftnlen)3);
	    if (iostat != 0) {
		goto L100003;
	    }
	    iostat = e_wsle(&__global_state->f2c);
L100003:
	    ;
	} else {
	    s_copy(&__global_state->f2c, line, " ", (ftnlen)132, (ftnlen)1);
	    __state->io___12.ciunit = *unit;
	    iostat = s_wsle(&__global_state->f2c, &__state->io___12);
	    if (iostat != 0) {
		goto L100004;
	    }
	    iostat = do_lio(&__global_state->f2c, &__state->c__9, &
		    __state->c__1, line, margin);
	    if (iostat != 0) {
		goto L100004;
	    }
	    iostat = do_lio(&__global_state->f2c, &__state->c__5, &
		    __state->c__1, (char *)&dvalue, (ftnlen)sizeof(doublereal)
		    );
	    if (iostat != 0) {
		goto L100004;
	    }
	    iostat = do_lio(&__global_state->f2c, &__state->c__9, &
		    __state->c__1, ", ", (ftnlen)2);
	    if (iostat != 0) {
		goto L100004;
	    }
	    iostat = e_wsle(&__global_state->f2c);
L100004:
	    ;
	}
    }
    if (iostat != 0) {
	ioerr_(__global_state, "writing a variable to the output kernel file",
		 " ", &iostat, (ftnlen)44, (ftnlen)1);
	sigerr_(__global_state, "SPICE(WRITEERROR)", (ftnlen)17);
    }
    chkout_(__global_state, "WRKVAR", (ftnlen)6);
    return 0;
} /* wrkvar_ */

