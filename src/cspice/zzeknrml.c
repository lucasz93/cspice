/* zzeknrml.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzeknrml_init_t __zzeknrml_init;
static zzeknrml_state_t* get_zzeknrml_state(cspice_t* state) {
	if (!state->zzeknrml)
		state->zzeknrml = __cspice_allocate_module(sizeof(
	zzeknrml_state_t), &__zzeknrml_init, sizeof(__zzeknrml_init));
	return state->zzeknrml;

}

/* $Procedure      ZZEKNRML ( EK, normalize WHERE clause ) */
/* Subroutine */ int zzeknrml_(cspice_t* __global_state, char *query, integer 
	*ntoken, integer *lxbegs, integer *lxends, integer *tokens, integer *
	values, doublereal *numvls, char *chrbuf, integer *chbegs, integer *
	chends, integer *eqryi, char *eqryc, doublereal *eqryd, logical *
	error, char *prserr, ftnlen query_len, ftnlen chrbuf_len, ftnlen 
	eqryc_len, ftnlen prserr_len)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    integer s_rnge(f2c_state_t*, char *, integer, char *, integer);

    /* Local variables */
    extern /* Subroutine */ int zzekinqc_(cspice_t*, char *, integer *, 
	    integer *, integer *, integer *, char *, integer *, ftnlen, 
	    ftnlen);
    extern /* Subroutine */ int zzektloc_(cspice_t*, integer *, integer *, 
	    integer *, integer *, integer *, integer *, logical *);
    extern /* Subroutine */ int zzekinqn_(cspice_t*, doublereal *, integer *, 
	    integer *, integer *, integer *, doublereal *, integer *);
    extern /* Subroutine */ int zzekweqi_(cspice_t*, char *, integer *, 
	    integer *, ftnlen);
    extern integer cardi_(cspice_t*, integer *);
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern integer lnkhl_(cspice_t*, integer *, integer *);
    extern integer lnktl_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int repmi_(cspice_t*, char *, char *, integer *, 
	    char *, ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int lnkan_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int repmc_(cspice_t*, char *, char *, char *, 
	    char *, ftnlen, ftnlen, ftnlen, ftnlen);
    extern integer isrchi_(cspice_t*, integer *, integer *, integer *);
    extern integer lnknfn_(cspice_t*, integer *);
    extern integer lnknxt_(cspice_t*, integer *, integer *);
    extern integer lnkprv_(cspice_t*, integer *, integer *);
    extern logical return_(cspice_t*);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int lnkini_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int lnkila_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int lnkfsl_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int cleari_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int lnkilb_(cspice_t*, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int ssizei_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int insrti_(cspice_t*, integer *, integer *);
    extern /* Subroutine */ int appndi_(cspice_t*, integer *, integer *);


    /* Module state */
    zzeknrml_state_t* __state = get_zzeknrml_state(__global_state);
/* $ Abstract */

/*     Convert the WHERE clause of an EK query to a normalized form. */

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

/*     EK */

/* $ Keywords */

/*     EK */
/*     PRIVATE */

/* $ Declarations */
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


/*     Include Section:  EK Keyword Code Parameters */

/*        ekkeyw.inc  Version 4    24-JAN-1995 (NJB) */



/*     The EK query language keywords and codes are: */

/*        ALL */
/*        AND */
/*        ASC */
/*        AVG */
/*        BETWEEN */
/*        BY */
/*        COUNT */
/*        DESC */
/*        DISTINCT */
/*        EQ */
/*        FROM */
/*        GE */
/*        GROUP */
/*        GT */
/*        HAVING */
/*        IS */
/*        LE */
/*        LT */
/*        LIKE */
/*        MAX */
/*        MIN */
/*        NE */
/*        NOT */
/*        NULL */
/*        OR */
/*        ORDER */
/*        SELECT */
/*        SUM */
/*        WHERE */


/*     End Include Section:  EK Keyword Code Parameters */

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


/*     Include Section:  EK Operator Codes */

/*        ekopcd.inc  Version 1  30-DEC-1994 (NJB) */


/*     Within the EK system, operators used in EK queries are */
/*     represented by integer codes.  The codes and their meanings are */
/*     listed below. */

/*     Relational expressions in EK queries have the form */

/*        <column name> <operator> <value> */

/*     For columns containing numeric values, the operators */

/*        EQ,  GE,  GT,  LE,  LT,  NE */

/*     may be used; these operators have the same meanings as their */
/*     Fortran counterparts.  For columns containing character values, */
/*     the list of allowed operators includes those in the above list, */
/*     and in addition includes the operators */

/*        LIKE,  UNLIKE */

/*     which are used to compare strings to a template.  In the character */
/*     case, the meanings of the parameters */

/*        GE,  GT,  LE,  LT */

/*     match those of the Fortran lexical functions */

/*        LGE, LGT, LLE, LLT */


/*     The additional unary operators */

/*        ISNULL, NOTNUL */

/*     are used to test whether a value of any type is null. */



/*     End Include Section:  EK Operator Codes */

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


/*     Include Section:  EK Query Limit Parameters */

/*        ekqlimit.inc  Version 3    16-NOV-1995 (NJB) */

/*           Parameter MAXCON increased to 1000. */

/*        ekqlimit.inc  Version 2    01-AUG-1995 (NJB) */

/*           Updated to support SELECT clause. */


/*        ekqlimit.inc  Version 1    07-FEB-1995 (NJB) */


/*     These limits apply to character string queries input to the */
/*     EK scanner.  This limits are part of the EK system's user */
/*     interface:  the values should be advertised in the EK required */
/*     reading document. */


/*     Maximum length of an input query:  MAXQRY.  This value is */
/*     currently set to twenty-five 80-character lines. */


/*     Maximum number of columns that may be listed in the */
/*     `order-by clause' of a query:  MAXSEL.  MAXSEL = 50. */


/*     Maximum number of tables that may be listed in the `FROM */
/*     clause' of a query: MAXTAB. */


/*     Maximum number of relational expressions that may be listed */
/*     in the `constraint clause' of a query: MAXCON. */

/*     This limit applies to a query when it is represented in */
/*     `normalized form': that is, the constraints have been */
/*     expressed as a disjunction of conjunctions of relational */
/*     expressions. The number of relational expressions in a query */
/*     that has been expanded in this fashion may be greater than */
/*     the number of relations in the query as orginally written. */
/*     For example, the expression */

/*             ( ( A LT 1 ) OR ( B GT 2 ) ) */
/*        AND */
/*             ( ( C NE 3 ) OR ( D EQ 4 ) ) */

/*     which contains 4 relational expressions, expands to the */
/*     equivalent normalized constraint */

/*             (  ( A LT 1 ) AND ( C NE 3 )  ) */
/*        OR */
/*             (  ( A LT 1 ) AND ( D EQ 4 )  ) */
/*        OR */
/*             (  ( B GT 2 ) AND ( C NE 3 )  ) */
/*        OR */
/*             (  ( B GT 2 ) AND ( D EQ 4 )  ) */

/*     which contains eight relational expressions. */



/*     MXJOIN is the maximum number of tables that can be joined. */


/*     MXJCON is the maximum number of join constraints allowed. */


/*     Maximum number of order-by columns that may be used in the */
/*     `order-by clause' of a query: MAXORD. MAXORD = 10. */


/*     Maximum number of tokens in a query: 500. Tokens are reserved */
/*     words, column names, parentheses, and values. Literal strings */
/*     and time values count as single tokens. */


/*     Maximum number of numeric tokens in a query: */


/*     Maximum total length of character tokens in a query: */


/*     Maximum length of literal string values allowed in queries: */
/*     MAXSTR. */


/*     End Include Section:  EK Query Limit Parameters */

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


/*     Include Section:  EK Encoded Query Internal Parameters */

/*        ekquery.inc  Version 3    16-NOV-1995 (NJB) */

/*           Updated to reflect increased value of MAXCON in */
/*           ekqlimit.inc. */

/*        ekquery.inc  Version 2    03-AUG-1995 (NJB) */

/*           Updated to support representation of the SELECT clause. */


/*        ekquery.inc  Version 1    12-JAN-1995 (NJB) */


/*     An encoded EK query is an abstract data type implemented */
/*     as an integer cell, along with a double precision cell and */
/*     a character string.  The d.p. cell and string contain numeric */
/*     and string values from the query string represented by the */
/*     encoded query. */

/*     The parameters in this file are intended for use only by the */
/*     EK encoded query access routines.  Callers of EK routines should */
/*     not use these parameters. */

/*     The following parameters are indices of specified elements */
/*     in the integer portion of the encoded query. */

/*     Encoded query architecture type: */


/*     `Name resolution' consists of: */

/*        - Verifying existence of tables:  any table names listed */
/*          in the FROM clause of a query must be loaded. */

/*        - Validating table aliases used to qualify column names. */

/*        - Verifying existence of columns and obtaining data types */
/*          for columns. */

/*        - Setting data type codes for literal values in the encoded */
/*          query. */

/*        - Checking consistency of operators and operand data types. */

/*        - Making sure unqualified column names are unambiguous. */

/*        - For constraints, mapping the table names used to qualify */
/*          column names to the ordinal position in the FROM clause */
/*          of the corresponding table. */


/*     Initialization status---this flag indicates whether the encoded */
/*     query has been initialized.  Values are ITRUE or IFALSE.  See the */
/*     include file ekbool.inc for parameter values. */


/*     Parse status---this flag indicates whether the parsing operation */
/*     that produced an encoded query has been completed. Values are */
/*     ITRUE or IFALSE. */


/*     Name resolution status---this flag indicates whether names */
/*     have been resolved in an encoded query.  Values are ITRUE or */
/*     IFALSE. */


/*     Time resolution status---this flag indicates whether time values */
/*     have been resolved in an encoded query.  Time resolution */
/*     consists of converting strings representing time values to ET. */
/*     Values of the status are ITRUE or IFALSE. */


/*     Semantic check status---this flag indicates whether semantic */
/*     checking of constraints has been performed. */


/*     Number of tables specified in FROM clause: */


/*     Number of constraints in query: */


/*     A special value is used to indicate the `maximal' constraint--- */
/*     one that logically cannot be satisfied.  If the constraints */
/*     are equivalent to the maximal constraint, the location EQNCNS */
/*     is assigned the value EQMXML */


/*     Number of constraint conjunctions: */


/*     Number of order-by columns: */


/*     Number of SELECT columns: */


/*     Size of double precision buffer: */


/*     `Free' pointer into double precision buffer: */


/*     Size of character string buffer: */


/*     `Free' pointer into character string buffer: */


/*     The following four base pointers will be valid after a query */
/*     has been parsed: */

/*     Base pointer for SELECT column descriptors: */


/*     Base pointer for constraint descriptors: */


/*     Base pointer for conjunction sizes: */


/*     Base pointer for order-by column descriptors: */


/*     After the quantities named above, the integer array contains */
/*     series of descriptors for tables, constraints, and order-by */
/*     columns, as well as a list of `conjunction sizes'---that is, */
/*     the sizes of the groups of constraints that form conjunctions, */
/*     after the input query has been re-arranged as a disjunction of */
/*     conjunctions of constraints. */


/*     The offsets of specific elements within descriptors are */
/*     parameterized. The base addresses of the descriptors themselves */
/*     must be  calculated using the counts and sizes of the items */
/*     preceding them. */

/*     A diagram of the structure of the variable-size portion of the */
/*     integer array is shown below: */


/*        +-------------------------------------+ */
/*        | Fixed-size portion of encoded query | */
/*        +-------------------------------------+ */
/*        |         Encoded FROM clause         | */
/*        +-------------------------------------+ */
/*        |      Encoded constraint clause      | */
/*        +-------------------------------------+ */
/*        |          Conjunction sizes          | */
/*        +-------------------------------------+ */
/*        |       Encoded ORDER BY clause       | */
/*        +-------------------------------------+ */
/*        |        Encoded SELECT clause        | */
/*        +-------------------------------------+ */


/*     Value Descriptors */
/*     ---------------- */

/*     In order to discuss the various descriptors below, we'll make use */
/*     of sub-structures called `value descriptors'.  These descriptors */
/*     come in two flavors:  character and double precision.  For */
/*     strings, a descriptor is a set of begin and end pointers that */
/*     indicate the location of the string in the character portion of an */
/*     encoded query, along with the begin and end pointers for the */
/*     corresponding lexeme in the original query.  The pointers are set */
/*     to zero when they are not in use, for example if they refer to an */
/*     optional lexeme that did not appear in the input query. */

/*     All value descriptors start with a data type indicator; values */
/*     are from ektype.inc.  Integer and time values are referred to */
/*     by double precision descriptors. */

/*     Parameters for string value descriptor elements: */


/*     Numeric value descriptors are similar to those for string values, */
/*     the difference being that they have only one pointer to the value */
/*     they represent.  This pointer is the index of the value in the */
/*     encoded query's numeric buffer. */


/*     All value descriptors have the same size.  In order to allow */
/*     table descriptors to have the same size as value descriptors, */
/*     we include an extra element in the descriptor. */


/*     Column Descriptors */
/*     ----------------- */

/*     Each column descriptor consists of a character descriptor for the */
/*     name of the column, followed by an index, which gives the ordinal */
/*     position of the column in the logical table to which the column */
/*     belongs.  The index element is filled in during name resolution. */


/*     Table Descriptors */
/*     ----------------- */

/*     Each table descriptor consists of a character descriptor for the */
/*     name of the table, followed by an index, which gives the ordinal */
/*     position of the table in the FROM clause in the original query. */
/*     The index element is filled in during name resolution.  Aliases */
/*     and table names have identical descriptor structures. */


/*     Constraint descriptors */
/*     ------------------ */

/*     Each constraint is characterized by: */

/*        - A code indicating whether the constraint compares values */
/*          in two columns or the value in a column and a literal */
/*          value.  The values of this element are EQCOL and EQVAL. */



/*        - A descriptor for the table used to qualify the */
/*          column name on the left side of the constraint. */


/*        - A character value descriptor for the column name on the left */
/*          side of the query. */


/*        - An operator code indicating the relational operator used */
/*          in the constraint. */


/*        If the constraint compares values from two columns, the */
/*        next items are table and column name descriptors that apply to */
/*        the column named on the right side of the relational operator. */


/*        If the constraint has a literal value on the right side, the */
/*        operator code is followed by... */

/*        - a value descriptor. */


/*        - Size of a constraint descriptor: */


/*     Conjunction sizes */
/*     ----------------- */

/*     The size of each conjunction of constraints occupies a single */
/*     integer. */




/*     Order-by Column Descriptors */
/*     --------------------------- */

/*     Each order-by column descriptor contains descriptors for */
/*     the table containing the column and for the name of the column */
/*     itself; one additional element is used to indicate the direction */
/*     of the ordering (ascending vs descending). */


/*        - The last integer in the descriptor indicates whether the */
/*          order direction is ascending or descending. */


/*        - Size of an order-by column descriptor: */


/*     Codes indicating sense of ordering (ascending vs descending): */


/*     SELECT Column Descriptors */
/*     --------------------------- */

/*     Each SELECT column descriptor contains descriptors for */
/*     the table containing the column and for the name of the column */
/*     itself. */


/*        - Size of a SELECT column descriptor: */


/*     Miscellaneous parameters: */


/*     EQIMIN is the minimum size of the integer portion of */
/*     an encoded query.  EQIMIN depends on the parameters */

/*        MAXTAB */
/*        MAXCON */
/*        MAXORD */
/*        MAXSEL */

/*     all of which are declared in the include file ekqlimit.inc. */
/*     The functional definition of EQIMIN is: */

/*     INTEGER               EQIMIN */
/*     PARAMETER           ( EQIMIN =   EQVBAS */
/*    .                              +  MAXTAB * EQVDSZ * 2 */
/*    .                              +  MAXCON * EQCDSZ */
/*    .                              +  MAXCON */
/*    .                              +  MAXORD * EQODSZ */
/*    .                              +  MAXSEL * EQSDSZ     ) */


/*     End Include Section:  EK Encoded Query Internal Parameters */

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


/*     Include Section:  EK Token Code Parameters */

/*        ektokn.inc  Version 2    25-JAN-1995 (NJB) */

/*           Updated to distinguish between special characters. */


/*        ektokn.inc  Version 1    05-DEC-1994 (NJB) */


/*     The EK query language tokens and codes are: */

/*        <keyword> */
/*        <identifier> */
/*        <integer> */
/*        <d.p. number> */
/*        <quoted string> */
/*        <left parenthesis> */
/*        <right parenthesis> */
/*        <comma> */
/*        <period> */
/*        <end of query> */



/*     End Include Section:  EK Token Code Parameters */

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


/*     Include Section:  EK Data Types */

/*        ektype.inc Version 1  27-DEC-1994 (NJB) */


/*     Within the EK system, data types of EK column contents are */
/*     represented by integer codes.  The codes and their meanings */
/*     are listed below. */

/*     Integer codes are also used within the DAS system to indicate */
/*     data types; the EK system makes no assumptions about compatibility */
/*     between the codes used here and those used in the DAS system. */


/*     Character type: */


/*     Double precision type: */


/*     Integer type: */


/*     `Time' type: */

/*     Within the EK system, time values are represented as ephemeris */
/*     seconds past J2000 (TDB), and double precision numbers are used */
/*     to store these values.  However, since time values require special */
/*     treatment both on input and output, and since the `TIME' column */
/*     has a special role in the EK specification and code, time values */
/*     are identified as a type distinct from double precision numbers. */


/*     End Include Section:  EK Data Types */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     QUERY      I   Input EK query. */
/*     NTOKEN     I   Number of tokens in query. */
/*     LXBEGS     I   Start positions of lexemes comprising WHERE clause. */
/*     LXENDS     I   End positions of lexemes comprising WHERE clause. */
/*     TOKENS     I   Tokens comprising query. */
/*     VALUES     I   Values associated with tokens. */
/*     NUMVLS     I   Buffer containing numeric token values. */
/*     CHRBUF     I   Buffer containing string token values. */
/*     CHBEGS, */
/*     CHENDS     I   String token begin and end character positions. */
/*     EQRYI, */
/*     EQRYC, */
/*     EQRYD      O   Parsed query and string and number value buffers. */
/*     ERROR      O   Parse error flag. */
/*     PRSERR     O   Parse error message. */

/* $ Detailed_Input */

/*     QUERY          is an EK query to be parsed.  The tokens of the */
/*                    query have been found already.  See the header */
/*                    of the subroutine EKFIND for a detailed */
/*                    description of the EK query language. */

/*     NTOKEN         is the number of tokens in the input query. */

/*     LXBEGS, */
/*     LXENDS         are lexeme begin and end pointers; the Ith */
/*                    lexeme in the query is */

/*                       QUERY ( LXBEGS(I) : LXENDS(I) ) */

/*                    (Lexemes are strings that correspond to tokens */
/*                     in the language.) */

/*     TOKENS         is an array of token codes.  The Ith element of */
/*                    TOKENS represents the Ith token in the scanned */
/*                    query. */

/*     VALUES         is an array of values associated with tokens; the */
/*                    Ith element of VALUES corresponds to the Ith */
/*                    token.  Keywords, for example, are distinguished */
/*                    by codes in the VALUES array.  Literal numeric */
/*                    and string tokens use the VALUES array to point */
/*                    to elements of NUMVLS or CHBEGS and CHENDS, */
/*                    respectively.  Some tokens don't need to use */
/*                    VALUES, but to simplify indexing, each token gets */
/*                    an element of this array. */

/*     NUMVLS         is an array of double precision numbers used to */
/*                    store the values corresponding to literal numeric */
/*                    tokens. */

/*     CHRBUF         is a string used to store the values of literal */
/*                    string tokens. */

/*     CHBEGS, */
/*     CHENDS         are pairs of begin and end pointers into CHRBUF. */
/*                    These pointers delimit character values */
/*                    associated with literal string tokens. */

/* $ Detailed_Output */

/*     EQRYI, */
/*     EQRYC, */
/*     EQRYD          are the integer, character, and numeric portions */
/*                    of an encoded form of the input query.  The WHERE */
/*                    clause of the input query is represented in this */
/*                    encoding.  The WHERE clause constraints have been */
/*                    normalized. */

/*                    Normalized queries have their constraints grouped */
/*                    into a disjunction of conjunctions of relational */
/*                    expressions, as symbolized below: */

/*                          ( <rel_exp_1_1> and <rel_exp_1_2> and ... ) */
/*                       or ( <rel_exp_2_1> and <rel_exp_2_2> and ... ) */
/*                                     . */
/*                                     . */
/*                                     . */
/*                       or ( <rel_exp_N_1> and <rel_exp_N_2> and ... ) */

/*     ERROR, */
/*     PRSERR         are, respectively, a flag indicating whether the */
/*                    input query parsed correctly, and a message */
/*                    describing the parse error, if one occurred.  If */
/*                    no error occurred, ERROR is .FALSE. and PRSERR */
/*                    is blank. */
/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     No matter how ridiculous the query passed to ZZEKNRML, the */
/*     routine diagnoses errors via the output arguments ERROR and */
/*     PRSERR.  No errors are signalled.  The possible error messages */
/*     returned by this routine are: */


/*        Conjunction table is full. */

/*        Disjunction table is full. */

/*        Empty WHERE clause. */

/*        Missing WHERE keyword. */

/*        More tokens expected. */

/*        NULL values are not allowed in BETWEEN or NOT BETWEEN clauses. */

/*        NULL values can only be used with the operators */
/*        "IS NULL", "NOT NULL" or equivalents. */

/*        Relation table is full. */

/*        Stack is full. */

/*        Syntax error:  badly formed WHERE clause. */

/*        Token following BETWEEN operator is invalid. */

/*        Token following NOT operator was invalid. */

/*        Token must be followed by a comparison operator. */

/*        Token must be followed by the AND operator. */

/*        Token sequence must be followed by a value. */

/*        Tokens were missing from comparison relation. */

/*        Tokens were missing from logical expression. */

/*        Too few tokens in WHERE clause. */

/*        Too many tokens in query; max allowed is #. */

/*        Unexpected keyword # found at location #. */

/*        Unexpected right parenthesis found. */

/*        Unexpected token # found at location #. */

/*        Unexpected token found following valid expression. */

/*        Unexpected token found. */

/*        WHERE clause ran out of tokens unexpectedly. */
/*        This may be due to an extra left parenthesis. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     Here is the grammar for the EK WHERE clause: */

/*        <WHERE clause>           =>   WHERE <relational expression> */


/*        <relational expression>  =>   <simple expression> */

/*                                      <NULL value expression> */

/*                                    | NOT <relational expression> */

/*                                    |   ( <relational expression> ) */

/*                                    |     <relational expression> */
/*                                      AND <relational expression> */

/*                                    |     <relational expression> */
/*                                      OR  <relational expression> */


/*        <simple expression>      =>   <LHS> <operator> <RHS> */

/*                                    | <LHS> BETWEEN     <RHS> AND <RHS> */

/*                                    | <LHS> NOT BETWEEN <RHS> AND <RHS> */


/*        <NULL value expression>  =>   <LHS> <Null operator> NULL */


/*        <LHS>                    =>   <name> */


/*        <RHS>                    =>   <name> */
/*                                    | <value> */


/*        <name>                   =>   <identifier> . <identifier> */
/*                                    | <identifier> */


/*        <operator>               =>   EQ */
/*                                    | GE */
/*                                    | GT */
/*                                    | LE */
/*                                    | LT */
/*                                    | NE */
/*                                    | LIKE */
/*                                    | NOT LIKE */
/*                                    | = */
/*                                    | >= */
/*                                    | > */
/*                                    | <= */
/*                                    | < */
/*                                    | != */
/*                                    | <> */


/*        <NULL operator>         =>    IS */
/*                                    | IS NOT */
/*                                    | EQ */
/*                                    | NE */
/*                                    | = */
/*                                    | != */
/*                                    | <> */


/*        <value>                 =>    <character value> */
/*                                    | <d.p. value> */
/*                                    | <integer value> */

/* $ Examples */

/*     1)  This routine breaks down the constraints of the WHERE clause */

/*             WHERE        ( ( COL1 EQ VAL1 ) OR ( COL2 NE VAL2 ) ) */
/*                     AND  ( ( COL3 LE VAL3 ) OR ( COL4 GT VAL4 ) ) */

/*         as */

/*                          (  ( COL1 EQ VAL1 ) AND ( COL3 LE VAL3 ) ) */
/*                     OR   (  ( COL1 EQ VAL1 ) AND ( COL4 GT VAL4 ) ) */
/*                     OR   (  ( COL2 NE VAL2 ) AND ( COL3 LE VAL3 ) ) */
/*                     OR   (  ( COL2 NE VAL2 ) AND ( COL4 GT VAL4 ) ) */



/*     2)  This routine breaks down the constraints of the WHERE clause */

/*             WHERE  NOT ( ( COL1 EQ VAL1 ) OR ( COL2 NE VAL2 ) ) */

/*          as */
/*                          ( COL1 NE VAL1 ) AND ( COL3 EQ VAL3 ) */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    Beta Version 3.0.0, 17-NOV-1995 (NJB) */

/*        Significantly re-written for architecture 3. */

/* -& */


/*     SPICELIB functions */



/*     Local parameters */


/*     Data structure bounds: */


/*     MAXREL is the maximum number of relations that can be handled */
/*     by this routine. */


/*     MAXMET is the maximum number of meta-tokens making up any */
/*     expression. */


/*     LBPOOL is the lower bound of the second index of a linked list */
/*     pool array. */



/*     Stack parameters: */



/*     Operator parameters: */


/*     NLOGOP is the number of recognized logical operators.  These */
/*     are AND, OR, and NOT. */


/*     NRELOP is the number of arithmetic and character comparision */
/*     operators. */



/*     Meta-token codes, excluding codes for relational operators: */


/*     Number of keywords that can terminate a WHERE clause. */



/*     State parameters: */



/*     'Pop condition' codes: */


/*     Token descriptor size: */


/*     Local variables */


/*     Each comparison relation is expressed by three tokens, so the */
/*     comparison relations are represented by a 3 x MAXREL array.  The */
/*     first and third elements of each row of RELS are array indices */
/*     that point into the input array TOKENS; the middle element */
/*     of each row is an operator code.  The set of triples representing */
/*     comparison relations is indexed by a doubly linked list pool. */
/*     Each conjunction of comparison relations is represented by a */
/*     linked list of pointers to entries in the RELS array.  These */
/*     pointers are contained in the CJPTRS array.  The pointers are */
/*     linked via entries in the double linked list pool CJPOOL. */


/*     Each normalized expression is a disjunction of conjunctions.  Each */
/*     such disjunction is represented by a linked list of nodes */
/*     associated with pointers to entries in the CJPOOL array.  DJPTRS */
/*     is the parallel array used to associate each node of a disjunction */
/*     with the head node of a conjunction list in CJPOOL. */


/*     Meta-tokens are groups of tokens that comprise syntactic units */
/*     in a query.  Each symbol that appears on the left hand side of */
/*     a production rule in the grammar corresponds to a type of */
/*     meta-token. */

/*     Throughout the parsing process, the meta-tokens representing the */
/*     query are organized as a linked list.  Each meta-token is also */
/*     associated with a more detailed classification MTCODE. */

/*     For each meta-token that represents an identifier, a value, */
/*     a name, or an expression, there is a corresponding element of */
/*     MTEXPR.  This element contains a pointer to a token or to a */
/*     normalized expression.  In the latter case, the pointer is the */
/*     head node of a list in the disjunction table. */


/*     Stack variables */

/*     These variables have the following meanings: */

/*        MSTART is the node number of the first meta-token of */
/*        the current expression being parsed. */

/*        NMETA is the number of meta-tokens in the query. */

/*        POPCND is the `pop condition'.  This is a code indicating */
/*        what event must occur to trigger popping the current state. */
/*        The two events that can cause the state to be popped are */
/*        the execution of a reduction and encountering a right grouper. */



/*     Other local variables */


/*     Saved variables */



/*     Initial values */


/*     Note:  there is no "UNLIKE" keyword, but there is an UNLIKE */
/*     operator, which is the complement of the LIKE operator. */



/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "ZZEKNRML", (ftnlen)8);
    }

/*     No error at this point. */

    *error = FALSE_;
    s_copy(&__global_state->f2c, prserr, " ", prserr_len, (ftnlen)1);
    if (*ntoken > 500) {
	*error = TRUE_;
	s_copy(&__global_state->f2c, prserr, "Too many tokens in query; max "
		"allowed is #.", prserr_len, (ftnlen)43);
	repmi_(__global_state, prserr, "#", &__state->c__500, prserr, 
		prserr_len, (ftnlen)1, prserr_len);
	chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
	return 0;
    }

/*     Find out the start and end indices of the tokens comprising the */
/*     WHERE clause.  If there are no tokens in the WHERE clause, we may */
/*     as well go home. */

    zzektloc_(__global_state, &__state->c__1, &__state->c__29, ntoken, tokens,
	     values, &__state->whrbeg, &__state->fnd);
    ++__state->whrbeg;
    if (! __state->fnd) {
	*error = TRUE_;
	s_copy(&__global_state->f2c, prserr, "Missing WHERE keyword.", 
		prserr_len, (ftnlen)22);
	chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
	return 0;
    }

/*     The WHERE clause is terminated by the end of the query or by */
/*     the first keyword of the set {SELECT, FROM, ORDER} that follows */
/*     the WHERE keyword. */

    __state->whrend = *ntoken;
    for (__state->i__ = 1; __state->i__ <= 3; ++__state->i__) {
	zzektloc_(__global_state, &__state->c__1, &__state->endkw[(i__1 = 
		__state->i__ - 1) < 3 && 0 <= i__1 ? i__1 : s_rnge(&
		__global_state->f2c, "endkw", i__1, "zzeknrml_", (ftnlen)728)]
		, ntoken, tokens, values, &__state->endloc, &__state->fnd);
	if (__state->fnd) {
	    if (__state->endloc < __state->whrend && __state->endloc > 
		    __state->whrbeg) {
		__state->whrend = __state->endloc - 1;
	    }
	}
    }
    __state->whrsiz = __state->whrend - __state->whrbeg + 1;
    if (__state->whrsiz == 0) {
	*error = TRUE_;
	s_copy(&__global_state->f2c, prserr, "Empty WHERE clause.", 
		prserr_len, (ftnlen)19);
	chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
	return 0;
    }

/*     Initialize the pools. */

    lnkini_(__global_state, &__state->c__5000, __state->rlpool);
    lnkini_(__global_state, &__state->c__5000, __state->cjpool);
    lnkini_(__global_state, &__state->c__5000, __state->djpool);
    lnkini_(__global_state, &__state->c__500, __state->mtpool);
    lnkini_(__global_state, &__state->c__5000, __state->dspool);

/*     Loop through our token list and classify the tokens.  Initialize */
/*     the meta-token list. */

    __state->nmeta = 0;
    __state->tail = 0;
    __state->i__ = __state->whrbeg;
    while(__state->i__ <= __state->whrend) {

/*        Allocate a node and link it in at the tail of the meta-token */
/*        list. */

	lnkan_(__global_state, __state->mtpool, &__state->node);
	lnkila_(__global_state, &__state->tail, &__state->node, 
		__state->mtpool);
	__state->tail = __state->node;

/*        Each meta-token's expression pointer points to its original */
/*        token index, by default. */

	__state->mtexpr[(i__1 = __state->node - 1) < 500 && 0 <= i__1 ? i__1 :
		 s_rnge(&__global_state->f2c, "mtexpr", i__1, "zzeknrml_", (
		ftnlen)784)] = __state->i__;
	if (tokens[__state->i__ - 1] == 6) {
	    __state->mtcode[(i__1 = __state->node - 1) < 500 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "mtcode", i__1, "zze"
		    "knrml_", (ftnlen)789)] = -2;
	} else if (tokens[__state->i__ - 1] == 7) {
	    __state->mtcode[(i__1 = __state->node - 1) < 500 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "mtcode", i__1, "zze"
		    "knrml_", (ftnlen)794)] = -1;
	} else if (tokens[__state->i__ - 1] == 3 || tokens[__state->i__ - 1] 
		== 4) {

/*           Numeric values must be added to the encoded query.  We */
/*           allocate a descriptor from the descriptor pool for */
/*           each identifier.  The expression pointer for the */
/*           identifier points to the descriptor.  Note:  the */
/*           allocation should be safe, since we've checked the total */
/*           number of tokens in the query. */

	    __state->mtcode[(i__1 = __state->node - 1) < 500 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "mtcode", i__1, "zze"
		    "knrml_", (ftnlen)807)] = -8;
	    lnkan_(__global_state, __state->dspool, &__state->mtexpr[(i__1 = 
		    __state->node - 1) < 500 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "mtexpr", i__1, "zzeknrml_", (ftnlen)
		    809)]);
	    if (tokens[__state->i__ - 1] == 3) {
		__state->type__ = 3;
	    } else {
		__state->type__ = 2;
	    }
	    zzekinqn_(__global_state, &numvls[values[__state->i__ - 1] - 1], &
		    __state->type__, &lxbegs[__state->i__ - 1], &lxends[
		    __state->i__ - 1], eqryi, eqryd, &__state->dscbuf[(i__2 = 
		    __state->mtexpr[(i__1 = __state->node - 1) < 500 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtexpr", i__1,
		     "zzeknrml_", (ftnlen)817)] * 7 - 7) < 35000 && 0 <= i__2 
		    ? i__2 : s_rnge(&__global_state->f2c, "dscbuf", i__2, 
		    "zzeknrml_", (ftnlen)817)]);

/*           Set the descriptor to indicate that it represents a value. */

	    __state->dscbuf[(i__2 = __state->mtexpr[(i__1 = __state->node - 1)
		     < 500 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "mtexpr", i__1, "zzeknrml_", (ftnlen)828)] * 7 - 1) < 
		    35000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "dscbuf", i__2, "zzeknrml_", (ftnlen)828)] = -8;
	} else if (tokens[__state->i__ - 1] == 5) {

/*           The treatment of strings is analogous to that of numbers. */

	    __state->mtcode[(i__1 = __state->node - 1) < 500 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "mtcode", i__1, "zze"
		    "knrml_", (ftnlen)835)] = -8;
	    lnkan_(__global_state, __state->dspool, &__state->mtexpr[(i__1 = 
		    __state->node - 1) < 500 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "mtexpr", i__1, "zzeknrml_", (ftnlen)
		    837)]);
	    __state->b = chbegs[values[__state->i__ - 1] - 1];
	    __state->e = chends[values[__state->i__ - 1] - 1];
	    i__3 = __state->e - __state->b + 1;
	    zzekinqc_(__global_state, chrbuf + (__state->b - 1), &i__3, &
		    lxbegs[__state->i__ - 1], &lxends[__state->i__ - 1], 
		    eqryi, eqryc, &__state->dscbuf[(i__2 = __state->mtexpr[(
		    i__1 = __state->node - 1) < 500 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "mtexpr", i__1, "zzeknrml_", 
		    (ftnlen)842)] * 7 - 7) < 35000 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "dscbuf", i__2, "zzeknrml_", 
		    (ftnlen)842)], __state->e - (__state->b - 1), eqryc_len);

/*           Set the descriptor to indicate that it represents a value. */

	    __state->dscbuf[(i__2 = __state->mtexpr[(i__1 = __state->node - 1)
		     < 500 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "mtexpr", i__1, "zzeknrml_", (ftnlen)853)] * 7 - 1) < 
		    35000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "dscbuf", i__2, "zzeknrml_", (ftnlen)853)] = -8;
	} else if (tokens[__state->i__ - 1] == 2) {

/*           Identifiers must be added to the encoded query.  We */
/*           allocate a descriptor from the descriptor pool for */
/*           each identifier.  The expression pointer for the */
/*           identifier points to the descriptor. */

	    __state->mtcode[(i__1 = __state->node - 1) < 500 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "mtcode", i__1, "zze"
		    "knrml_", (ftnlen)863)] = -7;
	    lnkan_(__global_state, __state->dspool, &__state->mtexpr[(i__1 = 
		    __state->node - 1) < 500 && 0 <= i__1 ? i__1 : s_rnge(&
		    __global_state->f2c, "mtexpr", i__1, "zzeknrml_", (ftnlen)
		    865)]);
	    __state->b = chbegs[values[__state->i__ - 1] - 1];
	    __state->e = chends[values[__state->i__ - 1] - 1];
	    i__3 = __state->e - __state->b + 1;
	    zzekinqc_(__global_state, chrbuf + (__state->b - 1), &i__3, &
		    lxbegs[__state->i__ - 1], &lxends[__state->i__ - 1], 
		    eqryi, eqryc, &__state->dscbuf[(i__2 = __state->mtexpr[(
		    i__1 = __state->node - 1) < 500 && 0 <= i__1 ? i__1 : 
		    s_rnge(&__global_state->f2c, "mtexpr", i__1, "zzeknrml_", 
		    (ftnlen)870)] * 7 - 7) < 35000 && 0 <= i__2 ? i__2 : 
		    s_rnge(&__global_state->f2c, "dscbuf", i__2, "zzeknrml_", 
		    (ftnlen)870)], __state->e - (__state->b - 1), eqryc_len);

/*           Set the descriptor to indicate that it represents an */
/*           identifier. */

	    __state->dscbuf[(i__2 = __state->mtexpr[(i__1 = __state->node - 1)
		     < 500 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "mtexpr", i__1, "zzeknrml_", (ftnlen)882)] * 7 - 1) < 
		    35000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
		    "dscbuf", i__2, "zzeknrml_", (ftnlen)882)] = -7;
	} else if (tokens[__state->i__ - 1] == 9) {
	    __state->mtcode[(i__1 = __state->node - 1) < 500 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "mtcode", i__1, "zze"
		    "knrml_", (ftnlen)887)] = -9;
	} else if (tokens[__state->i__ - 1] == 1) {

/*           We have a keyword.  Identify it and locate the corresponding */
/*           code. */

	    __state->j = isrchi_(__global_state, &values[__state->i__ - 1], &
		    __state->c__3, __state->logops);
	    __state->k = isrchi_(__global_state, &values[__state->i__ - 1], &
		    __state->c__7, __state->cmpops);
	    if (__state->j > 0) {

/*              We have a logical operator, unless we have the NOT LIKE */
/*               or NOT BETWEEN sequence. */

		if (__state->logcde[(i__1 = __state->j - 1) < 3 && 0 <= i__1 ?
			 i__1 : s_rnge(&__global_state->f2c, "logcde", i__1, 
			"zzeknrml_", (ftnlen)904)] != -12) {
		    __state->mtcode[(i__1 = __state->node - 1) < 500 && 0 <= 
			    i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtco"
			    "de", i__1, "zzeknrml_", (ftnlen)906)] = 
			    __state->logcde[(i__2 = __state->j - 1) < 3 && 0 
			    <= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
			    "logcde", i__2, "zzeknrml_", (ftnlen)906)];
		} else {
		    if (__state->i__ <= __state->whrend) {
			if (tokens[__state->i__] == 1 && values[__state->i__] 
				== 18) {

/*                       Replace the NOT LIKE sequence with the */
/*                       UNLIKE operator.  Skip over the LIKE token. */

			    __state->mtcode[(i__1 = __state->node - 1) < 500 
				    && 0 <= i__1 ? i__1 : s_rnge(&
				    __global_state->f2c, "mtcode", i__1, 
				    "zzeknrml_", (ftnlen)918)] = 8;
			    ++__state->i__;
			} else if (tokens[__state->i__] == 1 && values[
				__state->i__] == 5) {

/*                       Replace the NOT BETWEEN sequence with the */
/*                       NOTBTW operator.  Skip over the BETWEEN token. */

			    __state->mtcode[(i__1 = __state->node - 1) < 500 
				    && 0 <= i__1 ? i__1 : s_rnge(&
				    __global_state->f2c, "mtcode", i__1, 
				    "zzeknrml_", (ftnlen)927)] = -4;
			    ++__state->i__;
			} else {
			    __state->mtcode[(i__1 = __state->node - 1) < 500 
				    && 0 <= i__1 ? i__1 : s_rnge(&
				    __global_state->f2c, "mtcode", i__1, 
				    "zzeknrml_", (ftnlen)931)] = -12;
			}
		    } else {
			__state->mtcode[(i__1 = __state->node - 1) < 500 && 0 
				<= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
				"mtcode", i__1, "zzeknrml_", (ftnlen)935)] = 
				-12;
		    }
		}
	    } else if (__state->k > 0) {
		__state->mtcode[(i__1 = __state->node - 1) < 500 && 0 <= i__1 
			? i__1 : s_rnge(&__global_state->f2c, "mtcode", i__1, 
			"zzeknrml_", (ftnlen)942)] = __state->cmpcde[(i__2 = 
			__state->k - 1) < 8 && 0 <= i__2 ? i__2 : s_rnge(&
			__global_state->f2c, "cmpcde", i__2, "zzeknrml_", (
			ftnlen)942)];
	    } else if (values[__state->i__ - 1] == 5) {
		__state->mtcode[(i__1 = __state->node - 1) < 500 && 0 <= i__1 
			? i__1 : s_rnge(&__global_state->f2c, "mtcode", i__1, 
			"zzeknrml_", (ftnlen)946)] = -3;
	    } else if (values[__state->i__ - 1] == 16) {

/*              The token IS translates to EQ; the token sequence */
/*              IS NOT translates to NE. */

		if (__state->i__ < __state->whrend) {
		    if (tokens[__state->i__] == 1 && values[__state->i__] == 
			    23) {

/*                    We have an IS NOT sequence.  Skip over the NOT */
/*                    token; indicate the sequence with a single NE */
/*                    meta-token. */

			__state->mtcode[(i__1 = __state->node - 1) < 500 && 0 
				<= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
				"mtcode", i__1, "zzeknrml_", (ftnlen)963)] = 
				6;
			++__state->i__;
		    } else {
			__state->mtcode[(i__1 = __state->node - 1) < 500 && 0 
				<= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
				"mtcode", i__1, "zzeknrml_", (ftnlen)966)] = 
				1;
		    }
		} else {
		    __state->mtcode[(i__1 = __state->node - 1) < 500 && 0 <= 
			    i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtco"
			    "de", i__1, "zzeknrml_", (ftnlen)970)] = 1;
		}
	    } else if (values[__state->i__ - 1] == 24) {

/*              The expression pointer for null values is NIL. */

		__state->mtcode[(i__1 = __state->node - 1) < 500 && 0 <= i__1 
			? i__1 : s_rnge(&__global_state->f2c, "mtcode", i__1, 
			"zzeknrml_", (ftnlen)978)] = -8;
		__state->mtexpr[(i__1 = __state->node - 1) < 500 && 0 <= i__1 
			? i__1 : s_rnge(&__global_state->f2c, "mtexpr", i__1, 
			"zzeknrml_", (ftnlen)979)] = 0;
	    } else {

/*              Sorry, that was the last chance for valid keywords. */

		__state->lxb = lxbegs[__state->i__ - 1];
		__state->lxe = lxends[__state->i__ - 1];
		*error = TRUE_;
		s_copy(&__global_state->f2c, prserr, "Unexpected keyword # f"
			"ound at location #.", prserr_len, (ftnlen)41);
		repmc_(__global_state, prserr, "#", query + (__state->lxb - 1)
			, prserr, prserr_len, (ftnlen)1, __state->lxe - (
			__state->lxb - 1), prserr_len);
		repmi_(__global_state, prserr, "#", &__state->lxb, prserr, 
			prserr_len, (ftnlen)1, prserr_len);
		chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
		return 0;
	    }
	} else {

/*           Sorry, that was the last chance, period. */

	    __state->lxb = lxbegs[__state->i__ - 1];
	    __state->lxe = lxends[__state->i__ - 1];
	    *error = TRUE_;
	    s_copy(&__global_state->f2c, prserr, "Unexpected token # found a"
		    "t location #.", prserr_len, (ftnlen)39);
	    repmc_(__global_state, prserr, "#", query + (__state->lxb - 1), 
		    prserr, prserr_len, (ftnlen)1, __state->lxe - (
		    __state->lxb - 1), prserr_len);
	    repmi_(__global_state, prserr, "#", &__state->lxb, prserr, 
		    prserr_len, (ftnlen)1, prserr_len);
	    chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
	    return 0;
	}

/*        At this point, we've classified the Ith token.  MTCODE(NODE) */
/*        is the meta-token code for this token. */

	++__state->i__;
	++__state->nmeta;
    }

/*     Initialize the head of the meta-token list. */

    __state->metahd = lnkhl_(__global_state, &__state->tail, __state->mtpool);

/*     Filter out extraneous parentheses around column names or */
/*     values. */

    __state->node = __state->metahd;
    while(__state->node > 0) {
	if (__state->mtcode[(i__1 = __state->node - 1) < 500 && 0 <= i__1 ? 
		i__1 : s_rnge(&__global_state->f2c, "mtcode", i__1, "zzeknrm"
		"l_", (ftnlen)1032)] == -6 || __state->mtcode[(i__2 = 
		__state->node - 1) < 500 && 0 <= i__2 ? i__2 : s_rnge(&
		__global_state->f2c, "mtcode", i__2, "zzeknrml_", (ftnlen)
		1032)] == -8) {

/*           If the current metatoken is bracketed by parentheses, */
/*           remove them and update the metatoken count accordingly. */

	    __state->prev = lnkprv_(__global_state, &__state->node, 
		    __state->mtpool);
	    __state->next = lnknxt_(__global_state, &__state->node, 
		    __state->mtpool);
	    if (__state->prev > 0 && __state->next > 0) {
		if (__state->mtcode[(i__1 = __state->prev - 1) < 500 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtcode", 
			i__1, "zzeknrml_", (ftnlen)1043)] == -2 && 
			__state->mtcode[(i__2 = __state->next - 1) < 500 && 0 
			<= i__2 ? i__2 : s_rnge(&__global_state->f2c, "mtcode"
			, i__2, "zzeknrml_", (ftnlen)1043)] == -1) {
		    lnkfsl_(__global_state, &__state->prev, &__state->prev, 
			    __state->mtpool);
		    lnkfsl_(__global_state, &__state->next, &__state->next, 
			    __state->mtpool);
		    __state->metahd = lnkhl_(__global_state, &__state->node, 
			    __state->mtpool);
		    __state->nmeta += -2;

/*                 We don't advance the current token in this case */
/*                 because there may be more parentheses to remove. */

		} else {

/*                 This token is not bracketed by parentheses; look at */
/*                 the next metatoken. */

		    __state->node = __state->next;
		}
	    } else {

/*              This token is not bracketed by tokens on both sides; look */
/*              at the next metatoken.  It's ok for the next token to be */
/*              NIL. */

		__state->node = __state->next;
	    }
	} else {

/*           The current token is not a name or value; look at the next */
/*           token. */

	    __state->node = lnknxt_(__global_state, &__state->node, 
		    __state->mtpool);
	}
    }


/*     Now it's time to parse our expression.  We will validate the */
/*     expression by using our grammar rules to condense groups of */
/*     meta-tokens that correspond to the right-hand sides of grammatical */
/*     rules into meta-tokens that correspond to the left-hand sides */
/*     of those same rules.  Each such application of a grammar rule */
/*     is called a `reduction.'  When we're left with a single */
/*     meta-token of type <relational expression>, we're done. */

/*     If, before reaching the desired final state, we get to a point */
/*     where no reductions can be performed, we have a syntax error. */

/*     As parsing advances, we'll start to get meta-tokens that are */
/*     logical expressions.  Each logical expression will be represented */
/*     by a data structure that organizes the expression in a way that */
/*     we'll refer to as `normalized':  the expression will be */
/*     represented as a disjuction of conjunctions, for example */

/*        ( A AND B AND C ) OR ( D AND E ) OR ( F ) OR ( G AND H AND I ) */

/*     Each metatoken that represents a logical expression will */
/*     refer to it through a pointer which is a member of the MTEXPR */
/*     array. */

    if (__state->whrsiz < 3) {
	*error = TRUE_;
	s_copy(&__global_state->f2c, prserr, "Too few tokens in WHERE clause."
		, prserr_len, (ftnlen)31);
	chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
	return 0;
    } else {
	__state->level = 1;
	__state->mstart[(i__1 = __state->level - 1) < 500 && 0 <= i__1 ? i__1 
		: s_rnge(&__global_state->f2c, "mstart", i__1, "zzeknrml_", (
		ftnlen)1121)] = __state->metahd;
	__state->popcnd[(i__1 = __state->level - 1) < 500 && 0 <= i__1 ? i__1 
		: s_rnge(&__global_state->f2c, "popcnd", i__1, "zzeknrml_", (
		ftnlen)1122)] = 0;
	__state->state = 2;
    }
    while(__state->state != 4) {
	if (__state->state == 2) {

/*           If the input query is valid, we're looking at the leftmost */
/*           meta-token of an expression that matches the right-hand */
/*           side of one of the grammar rules.  Referring back to the */
/*           rules, we see that there are only a few meta-tokens that are */
/*           valid as the first token of such an expression: */

/*              - A left grouper */
/*              - An identifier */
/*              - A name */
/*              - An expression */
/*              - A unary operator (`NOT' ) */

/*           We'll see if we can perform a reduction.  The reductions */
/*           that are possible depend on how many meta-tokens are */
/*           present in the expression we're looking at. */

/*           FIRST is the node number of the first meta-token to look */
/*           at, in an attempt to perform a reduction.  SECOND, THIRD, */
/*           and FOURTH have the obvious meanings; some of these may */
/*           be 0. */

	    __state->first = __state->mstart[(i__1 = __state->level - 1) < 
		    500 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "mstart", i__1, "zzeknrml_", (ftnlen)1155)];
	    if (__state->first > 0) {
		__state->second = lnknxt_(__global_state, &__state->first, 
			__state->mtpool);
	    } else {
		__state->second = 0;
	    }
	    if (__state->second > 0) {
		__state->third = lnknxt_(__global_state, &__state->second, 
			__state->mtpool);
	    } else {
		__state->third = 0;
	    }
	    if (__state->third > 0) {
		__state->fourth = lnknxt_(__global_state, &__state->third, 
			__state->mtpool);
	    } else {
		__state->fourth = 0;
	    }
	    if (__state->first <= 0) {

/*              This never happens to good commands. */

		*error = TRUE_;
		s_copy(&__global_state->f2c, prserr, "WHERE clause ran out o"
			"f tokens unexpectedly.  This may be due to an extra "
			"left parenthesis.", prserr_len, (ftnlen)91);
		chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
		return 0;
	    }

/*           We have at least one meta-token to work with.  We'll */
/*           take different actions depending on its type. */

	    if (__state->mtcode[(i__1 = __state->first - 1) < 500 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtcode", i__1,
		     "zzeknrml_", (ftnlen)1195)] == -7) {

/*              This is a simple case to deal with:  in valid queries, */
/*              we have either the sequence */

/*                 <identifier> . <identifier> */

/*              or */

/*                 <identifier> */

/*              Both of these token sequences represent a column name; */
/*              in the former case, the name is qualified by a table */
/*              name, in the latter, the column name is unqualified. */
/*              If the table name is absent, we'll simply save a null */
/*              descriptor for it.  The descriptors will be linked, with */
/*              the table descriptor coming first, and the NAME token */
/*              resulting from reducing this token sequence will point to */
/*              the list of descriptors via the MTEXPR pointer. */


		if (__state->third > 0) {

/*                 We can look at the following two tokens. */

		    if (__state->mtcode[(i__1 = __state->second - 1) < 500 && 
			    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			    "mtcode", i__1, "zzeknrml_", (ftnlen)1220)] == -9 
			    && __state->mtcode[(i__2 = __state->third - 1) < 
			    500 && 0 <= i__2 ? i__2 : s_rnge(&
			    __global_state->f2c, "mtcode", i__2, "zzeknrml_", 
			    (ftnlen)1220)] == -7) {
			__state->qual = TRUE_;
		    } else {
			__state->qual = FALSE_;
		    }
		} else {

/*                 There aren't enough tokens for this name to be */
/*                 qualified. */

		    __state->qual = FALSE_;
		}
		if (__state->qual) {

/*                 We have a fully qualified column name.  Hook up the */
/*                 table and column name descriptors. */

		    __state->tabptr = __state->mtexpr[(i__1 = __state->first 
			    - 1) < 500 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "mtexpr", i__1, "zzeknrml_", 
			    (ftnlen)1243)];
		    __state->colptr = __state->mtexpr[(i__1 = __state->third 
			    - 1) < 500 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "mtexpr", i__1, "zzeknrml_", 
			    (ftnlen)1244)];
		    lnkila_(__global_state, &__state->tabptr, &
			    __state->colptr, __state->dspool);

/*                 Reduce the expression to a <name> metatoken. */

		    __state->mtcode[(i__1 = __state->first - 1) < 500 && 0 <= 
			    i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtco"
			    "de", i__1, "zzeknrml_", (ftnlen)1251)] = -6;
		    lnkfsl_(__global_state, &__state->second, &__state->third,
			     __state->mtpool);
		    __state->nmeta += -2;
		} else {

/*                 We have an unqualified column name.  Allocate a table */
/*                 descriptor.  Set the table descriptor to indicate a */
/*                 null character descriptor.  Link this descriptor in */
/*                 before the column descriptor. */

		    lnkan_(__global_state, __state->dspool, &__state->tabptr);
		    cleari_(__global_state, &__state->c__7, &__state->dscbuf[(
			    i__1 = __state->tabptr * 7 - 7) < 35000 && 0 <= 
			    i__1 ? i__1 : s_rnge(&__global_state->f2c, "dscb"
			    "uf", i__1, "zzeknrml_", (ftnlen)1266)]);
		    __state->dscbuf[(i__1 = __state->tabptr * 7 - 7) < 35000 
			    && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c,
			     "dscbuf", i__1, "zzeknrml_", (ftnlen)1267)] = 1;
		    __state->dscbuf[(i__1 = __state->tabptr * 7 - 1) < 35000 
			    && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c,
			     "dscbuf", i__1, "zzeknrml_", (ftnlen)1268)] = -7;
		    __state->colptr = __state->mtexpr[(i__1 = __state->first 
			    - 1) < 500 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "mtexpr", i__1, "zzeknrml_", 
			    (ftnlen)1270)];
		    lnkila_(__global_state, &__state->tabptr, &
			    __state->colptr, __state->dspool);

/*                 Reduce the expression to a <name> metatoken. */
/*                 The reduction doesn't change the number of metatokens. */

		    __state->mtexpr[(i__1 = __state->first - 1) < 500 && 0 <= 
			    i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtex"
			    "pr", i__1, "zzeknrml_", (ftnlen)1278)] = 
			    __state->tabptr;
		    __state->mtcode[(i__1 = __state->first - 1) < 500 && 0 <= 
			    i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtco"
			    "de", i__1, "zzeknrml_", (ftnlen)1279)] = -6;
		}

/*              Decide the next state. */

		__state->state = 3;
	    } else if (__state->mtcode[(i__1 = __state->first - 1) < 500 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtcode", 
		    i__1, "zzeknrml_", (ftnlen)1290)] == -8) {

/*              If the query is valid, the sequence of meta-tokens */
/*              should be one of */

/*                 <value>  AND  <name> */
/*                 <value>  AND  <value> */

/*              Both of these reduce to the symbol <BETWEEN expr>. */


		if (__state->third <= 0) {
		    *error = TRUE_;
		    s_copy(&__global_state->f2c, prserr, "Tokens were missin"
			    "g from comparison relation.", prserr_len, (ftnlen)
			    45);
		    chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
		    return 0;
		}

/*              Null values are not allowed in BETWEEN expressions. */

		if (__state->mtexpr[(i__1 = __state->first - 1) < 500 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtexpr", 
			i__1, "zzeknrml_", (ftnlen)1314)] == 0 || 
			__state->mtexpr[(i__2 = __state->third - 1) < 500 && 
			0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "mte"
			"xpr", i__2, "zzeknrml_", (ftnlen)1314)] == 0) {
		    *error = TRUE_;
		    s_copy(&__global_state->f2c, prserr, "NULL values are no"
			    "t allowed in BETWEEN or NOT BETWEEN clauses.", 
			    prserr_len, (ftnlen)62);
		    chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
		    return 0;
		}
		if (__state->mtcode[(i__1 = __state->third - 1) < 500 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtcode", 
			i__1, "zzeknrml_", (ftnlen)1326)] == -7) {

/*                 We'll need to reduce the IDENT before proceeding. */

		    __state->start = __state->third;
		    __state->retcnd = 1;
		    __state->state = 0;
		} else if (__state->mtcode[(i__1 = __state->second - 1) < 500 
			&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			"mtcode", i__1, "zzeknrml_", (ftnlen)1335)] == -10 && 
			(__state->mtcode[(i__2 = __state->third - 1) < 500 && 
			0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "mtc"
			"ode", i__2, "zzeknrml_", (ftnlen)1335)] == -6 || 
			__state->mtcode[(i__3 = __state->third - 1) < 500 && 
			0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, "mtc"
			"ode", i__3, "zzeknrml_", (ftnlen)1335)] == -8)) {

/*                 This sequence of tokens, when seen in the PARSE */
/*                 state, is a set of value bounds for a BETWEEN or */
/*                 NOT BETWEEN expression.  Note that this token sequence */
/*                 can occur elsewhere, but not in the PARSE state. */
/*                 This is because the meta-token sequences */

/*                    <value>  AND  <name> */
/*                    <value>  AND  <value> */

/*                 occur at the start of the RHS of only two */
/*                 productions, namely */

/*                    <BETWEEN expr>  =>  <value>  AND  <name> */
/*                    <BETWEEN expr>  =>  <value>  AND  <value> */


/*                 Hook up the name or value descriptors. */

		    lnkilb_(__global_state, &__state->mtexpr[(i__1 = 
			    __state->first - 1) < 500 && 0 <= i__1 ? i__1 : 
			    s_rnge(&__global_state->f2c, "mtexpr", i__1, 
			    "zzeknrml_", (ftnlen)1358)], &__state->mtexpr[(
			    i__2 = __state->third - 1) < 500 && 0 <= i__2 ? 
			    i__2 : s_rnge(&__global_state->f2c, "mtexpr", 
			    i__2, "zzeknrml_", (ftnlen)1358)], 
			    __state->dspool);
		    __state->mtcode[(i__1 = __state->first - 1) < 500 && 0 <= 
			    i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtco"
			    "de", i__1, "zzeknrml_", (ftnlen)1360)] = -5;
		    lnkfsl_(__global_state, &__state->second, &__state->third,
			     __state->mtpool);
		    __state->nmeta += -2;

/*                 Decide the next state. */

		    __state->state = 3;
		} else if (__state->mtcode[(i__1 = __state->second - 1) < 500 
			&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			"mtcode", i__1, "zzeknrml_", (ftnlen)1372)] > 0) {

/*                 The third meta-token is in the wrong place at the */
/*                 wrong time. */

		    *error = TRUE_;
		    s_copy(&__global_state->f2c, prserr, "Token sequence mus"
			    "t be followed by a value.", prserr_len, (ftnlen)
			    43);
		    chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
		    return 0;
		} else {

/*                 The second meta-token is supposed to be the AND token, */
/*                 but it's actually something else. */

		    *error = TRUE_;
		    s_copy(&__global_state->f2c, prserr, "Token must be foll"
			    "owed by the AND operator.", prserr_len, (ftnlen)
			    43);
		    chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
		    return 0;
		}
	    } else if (__state->mtcode[(i__1 = __state->first - 1) < 500 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtcode", 
		    i__1, "zzeknrml_", (ftnlen)1402)] == -6) {

/*              If the query is valid, the sequence of meta-tokens */
/*              should be any of */

/*                 <name>  <comparison operator> <value> */
/*                 <name>  <comparison operator> <name> */
/*                 <name>  <comparison operator> <ident> */

/*              or */

/*                 <name>  AND  <name> */
/*                 <name>  AND  <value> */
/*                 <name>  AND  <ident> */

/*              or */

/*                 <name>  BETWEEN  <BETWEEN expr> */
/*                 <name>  BETWEEN  <name> */
/*                 <name>  BETWEEN  <value> */
/*                 <name>  BETWEEN  <ident> */

/*              or */

/*                 <name>  <NOT BETWEEN>  <BETWEEN expr> */
/*                 <name>  <NOT BETWEEN>  <name> */
/*                 <name>  <NOT BETWEEN>  <value> */
/*                 <name>  <NOT BETWEEN>  <ident> */

/*              There must be at least three meta-tokens here. */


		if (__state->third <= 0) {
		    *error = TRUE_;
		    s_copy(&__global_state->f2c, prserr, "Tokens were missin"
			    "g from comparison relation.", prserr_len, (ftnlen)
			    45);
		    chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
		    return 0;
		}
		if (__state->mtcode[(i__1 = __state->third - 1) < 500 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtcode", 
			i__1, "zzeknrml_", (ftnlen)1445)] == -7) {

/*                 We'll need to reduce the IDENT before proceeding. */

		    __state->start = __state->third;
		    __state->retcnd = 1;
		    __state->state = 0;
		} else if (__state->mtcode[(i__1 = __state->second - 1) < 500 
			&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			"mtcode", i__1, "zzeknrml_", (ftnlen)1454)] == -10 && 
			(__state->mtcode[(i__2 = __state->third - 1) < 500 && 
			0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "mtc"
			"ode", i__2, "zzeknrml_", (ftnlen)1454)] == -6 || 
			__state->mtcode[(i__3 = __state->third - 1) < 500 && 
			0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, "mtc"
			"ode", i__3, "zzeknrml_", (ftnlen)1454)] == -8)) {

/*                 This sequence of tokens, when seen in the PARSE */
/*                 state, is a set of value bounds for a BETWEEN or */
/*                 NOT BETWEEN expression.  Note that this token sequence */
/*                 can occur elsewhere, but not in the PARSE state. */
/*                 This is because the meta-token sequences */

/*                    <name>  AND  <name> */
/*                    <name>  AND  <value> */

/*                 occur at the start of the RHS of only two */
/*                 productions, namely */

/*                    <BETWEEN expr>  =>  <name>   AND  <name> */
/*                    <BETWEEN expr>  =>  <name>   AND  <value> */


/*                 Null values are not allowed in BETWEEN expressions. */

		    if (__state->mtexpr[(i__1 = __state->first - 1) < 500 && 
			    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			    "mtexpr", i__1, "zzeknrml_", (ftnlen)1477)] == 0 
			    || __state->mtexpr[(i__2 = __state->third - 1) < 
			    500 && 0 <= i__2 ? i__2 : s_rnge(&
			    __global_state->f2c, "mtexpr", i__2, "zzeknrml_", 
			    (ftnlen)1477)] == 0) {
			*error = TRUE_;
			s_copy(&__global_state->f2c, prserr, "NULL values ar"
				"e not allowed in BETWEEN or NOT BETWEEN clau"
				"ses.", prserr_len, (ftnlen)62);
			chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
			return 0;
		    }

/*                 Hook up the name or value descriptors. */

		    lnkilb_(__global_state, &__state->mtexpr[(i__1 = 
			    __state->first - 1) < 500 && 0 <= i__1 ? i__1 : 
			    s_rnge(&__global_state->f2c, "mtexpr", i__1, 
			    "zzeknrml_", (ftnlen)1491)], &__state->mtexpr[(
			    i__2 = __state->third - 1) < 500 && 0 <= i__2 ? 
			    i__2 : s_rnge(&__global_state->f2c, "mtexpr", 
			    i__2, "zzeknrml_", (ftnlen)1491)], 
			    __state->dspool);
		    __state->mtcode[(i__1 = __state->first - 1) < 500 && 0 <= 
			    i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtco"
			    "de", i__1, "zzeknrml_", (ftnlen)1493)] = -5;
		    lnkfsl_(__global_state, &__state->second, &__state->third,
			     __state->mtpool);
		    __state->nmeta += -2;

/*                 Decide the next state. */

		    __state->state = 3;
		} else if (__state->mtcode[(i__1 = __state->second - 1) < 500 
			&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			"mtcode", i__1, "zzeknrml_", (ftnlen)1506)] > 0 && (
			__state->mtcode[(i__2 = __state->third - 1) < 500 && 
			0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "mtc"
			"ode", i__2, "zzeknrml_", (ftnlen)1506)] == -6 || 
			__state->mtcode[(i__3 = __state->third - 1) < 500 && 
			0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, "mtc"
			"ode", i__3, "zzeknrml_", (ftnlen)1506)] == -8)) {

/*                 Positive meta-token codes denote comparison */
/*                 operators. */

/*                 We have an arithmetic, string, or column comparison */
/*                 expression.  This is a trivial normalized */
/*                 relational expression.  All we have to do */
/*                 is store the expression in the relation table, */
/*                 and free the second and third meta-tokens. */

		    if (lnknfn_(__global_state, __state->rlpool) < 1) {
			*error = TRUE_;
			s_copy(&__global_state->f2c, prserr, "Relation table"
				" is full.", prserr_len, (ftnlen)23);
			chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
			return 0;
		    }
		    lnkan_(__global_state, __state->rlpool, &__state->newrel);
		    __state->rels[(i__1 = __state->newrel * 3 - 3) < 15000 && 
			    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			    "rels", i__1, "zzeknrml_", (ftnlen)1529)] = 
			    __state->mtexpr[(i__2 = __state->first - 1) < 500 
			    && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c,
			     "mtexpr", i__2, "zzeknrml_", (ftnlen)1529)];
		    __state->rels[(i__1 = __state->newrel * 3 - 2) < 15000 && 
			    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			    "rels", i__1, "zzeknrml_", (ftnlen)1530)] = 
			    __state->mtcode[(i__2 = __state->second - 1) < 
			    500 && 0 <= i__2 ? i__2 : s_rnge(&
			    __global_state->f2c, "mtcode", i__2, "zzeknrml_", 
			    (ftnlen)1530)];
		    __state->rels[(i__1 = __state->newrel * 3 - 1) < 15000 && 
			    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			    "rels", i__1, "zzeknrml_", (ftnlen)1531)] = 
			    __state->mtexpr[(i__2 = __state->third - 1) < 500 
			    && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c,
			     "mtexpr", i__2, "zzeknrml_", (ftnlen)1531)];
		    lnkfsl_(__global_state, &__state->second, &__state->third,
			     __state->mtpool);
		    __state->nmeta += -2;

/*                 Now allocate an entry in the conjunction pool */
/*                 and make this entry point to the relation table */
/*                 entry. */

		    if (lnknfn_(__global_state, __state->cjpool) < 1) {
			*error = TRUE_;
			s_copy(&__global_state->f2c, prserr, "Conjunction ta"
				"ble is full.", prserr_len, (ftnlen)26);
			chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
			return 0;
		    }
		    lnkan_(__global_state, __state->cjpool, &__state->newcj);
		    __state->cjptrs[(i__1 = __state->newcj - 1) < 5000 && 0 <=
			     i__1 ? i__1 : s_rnge(&__global_state->f2c, "cjp"
			    "trs", i__1, "zzeknrml_", (ftnlen)1552)] = 
			    __state->newrel;

/*                 Now allocate an entry in the disjunction pool */
/*                 and make this entry point to the conjunction pool */
/*                 entry. */

		    if (lnknfn_(__global_state, __state->djpool) < 1) {
			*error = TRUE_;
			s_copy(&__global_state->f2c, prserr, "Disjunction ta"
				"ble is full.", prserr_len, (ftnlen)26);
			chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
			return 0;
		    }
		    lnkan_(__global_state, __state->djpool, &__state->newdj);
		    __state->djptrs[(i__1 = __state->newdj - 1) < 5000 && 0 <=
			     i__1 ? i__1 : s_rnge(&__global_state->f2c, "djp"
			    "trs", i__1, "zzeknrml_", (ftnlen)1568)] = 
			    __state->newcj;

/*                 Change the type of the first meta-token to EXPR and */
/*                 have that meta-token point to this table entry.  Bag */
/*                 the other two meta-tokens. */

		    __state->mtcode[(i__1 = __state->first - 1) < 500 && 0 <= 
			    i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtco"
			    "de", i__1, "zzeknrml_", (ftnlen)1575)] = -13;
		    __state->mtexpr[(i__1 = __state->first - 1) < 500 && 0 <= 
			    i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtex"
			    "pr", i__1, "zzeknrml_", (ftnlen)1576)] = 
			    __state->newdj;

/*                 Decide the next state. */

		    __state->state = 3;
		} else if (__state->mtcode[(i__1 = __state->second - 1) < 500 
			&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			"mtcode", i__1, "zzeknrml_", (ftnlen)1584)] == -3 || 
			__state->mtcode[(i__2 = __state->second - 1) < 500 && 
			0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "mtc"
			"ode", i__2, "zzeknrml_", (ftnlen)1584)] == -4) {

/*                 If the command is syntactically correct, the */
/*                 meta-token sequence should be one of: */

/*                    <name>  <BETWEEN>      <BETWEEN expr> */
/*                    <name>  <BETWEEN>      <value> */
/*                    <name>  <BETWEEN>      <name> */
/*                    <name>  <NOT BETWEEN>  <BETWEEN expr> */
/*                    <name>  <NOT BETWEEN>  <value> */
/*                    <name>  <NOT BETWEEN>  <name> */


		    if (__state->mtcode[(i__1 = __state->second - 1) < 500 && 
			    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			    "mtcode", i__1, "zzeknrml_", (ftnlen)1598)] == -3 
			    && __state->mtcode[(i__2 = __state->third - 1) < 
			    500 && 0 <= i__2 ? i__2 : s_rnge(&
			    __global_state->f2c, "mtcode", i__2, "zzeknrml_", 
			    (ftnlen)1598)] == -5) {

/*                    It's a BETWEEN comparison.  We treat this as a */
/*                    disjunction of conjunctions of comparison */
/*                    relations: */
/*                                      <name>   >=   <item1> */
/*                              AND     <name>   <=   <item2> */

/*                         OR */
/*                                      <name>   <=   <item1> */
/*                              AND     <name>   >=   <item2> */

/*                    where item1 and item2 are specified by the */
/*                    descriptors belonging to the third meta-token. */

			for (__state->i__ = 1; __state->i__ <= 4; 
				++__state->i__) {
			    if (__state->i__ == 1 || __state->i__ == 3) {
				__state->k = __state->mtexpr[(i__1 = 
					__state->third - 1) < 500 && 0 <= 
					i__1 ? i__1 : s_rnge(&
					__global_state->f2c, "mtexpr", i__1, 
					"zzeknrml_", (ftnlen)1618)];
			    } else {

/*                          We need the descriptor pointer for the RHS */
/*                          item.  This descriptor is linked to the tail */
/*                          of the descriptor for the LHS item.  The */
/*                          number of nodes to skip over depends on */
/*                          whether the LHS item is a name or value. */

				__state->k = __state->mtexpr[(i__1 = 
					__state->third - 1) < 500 && 0 <= 
					i__1 ? i__1 : s_rnge(&
					__global_state->f2c, "mtexpr", i__1, 
					"zzeknrml_", (ftnlen)1628)];
				if (__state->dscbuf[(i__1 = __state->k * 7 - 
					1) < 35000 && 0 <= i__1 ? i__1 : 
					s_rnge(&__global_state->f2c, "dscbuf",
					 i__1, "zzeknrml_", (ftnlen)1630)] == 
					-7) {
				    __state->skip = 1;
				} else {
				    __state->skip = 0;
				}
				i__1 = __state->skip + 1;
				for (__state->j = 1; __state->j <= i__1; 
					++__state->j) {
				    __state->k = lnknxt_(__global_state, &
					    __state->k, __state->dspool);
				}
			    }
			    if (lnknfn_(__global_state, __state->rlpool) < 1) 
				    {
				*error = TRUE_;
				s_copy(&__global_state->f2c, prserr, "Relati"
					"on table is full.", prserr_len, (
					ftnlen)23);
				chkout_(__global_state, "ZZEKNRML", (ftnlen)8)
					;
				return 0;
			    }
			    lnkan_(__global_state, __state->rlpool, &
				    __state->rel[(i__1 = __state->i__ - 1) < 
				    4 && 0 <= i__1 ? i__1 : s_rnge(&
				    __global_state->f2c, "rel", i__1, "zzekn"
				    "rml_", (ftnlen)1650)]);
			    __state->rels[(i__2 = __state->rel[(i__1 = 
				    __state->i__ - 1) < 4 && 0 <= i__1 ? i__1 
				    : s_rnge(&__global_state->f2c, "rel", 
				    i__1, "zzeknrml_", (ftnlen)1653)] * 3 - 3)
				     < 15000 && 0 <= i__2 ? i__2 : s_rnge(&
				    __global_state->f2c, "rels", i__2, "zzek"
				    "nrml_", (ftnlen)1653)] = __state->mtexpr[(
				    i__3 = __state->first - 1) < 500 && 0 <= 
				    i__3 ? i__3 : s_rnge(&__global_state->f2c,
				     "mtexpr", i__3, "zzeknrml_", (ftnlen)
				    1653)];
			    if (__state->i__ == 1 || __state->i__ == 4) {
				__state->rels[(i__2 = __state->rel[(i__1 = 
					__state->i__ - 1) < 4 && 0 <= i__1 ? 
					i__1 : s_rnge(&__global_state->f2c, 
					"rel", i__1, "zzeknrml_", (ftnlen)
					1656)] * 3 - 2) < 15000 && 0 <= i__2 ?
					 i__2 : s_rnge(&__global_state->f2c, 
					"rels", i__2, "zzeknrml_", (ftnlen)
					1656)] = 2;
			    } else {
				__state->rels[(i__2 = __state->rel[(i__1 = 
					__state->i__ - 1) < 4 && 0 <= i__1 ? 
					i__1 : s_rnge(&__global_state->f2c, 
					"rel", i__1, "zzeknrml_", (ftnlen)
					1658)] * 3 - 2) < 15000 && 0 <= i__2 ?
					 i__2 : s_rnge(&__global_state->f2c, 
					"rels", i__2, "zzeknrml_", (ftnlen)
					1658)] = 4;
			    }
			    __state->rels[(i__2 = __state->rel[(i__1 = 
				    __state->i__ - 1) < 4 && 0 <= i__1 ? i__1 
				    : s_rnge(&__global_state->f2c, "rel", 
				    i__1, "zzeknrml_", (ftnlen)1661)] * 3 - 1)
				     < 15000 && 0 <= i__2 ? i__2 : s_rnge(&
				    __global_state->f2c, "rels", i__2, "zzek"
				    "nrml_", (ftnlen)1661)] = __state->k;
			    if (lnknfn_(__global_state, __state->cjpool) < 1) 
				    {
				*error = TRUE_;
				s_copy(&__global_state->f2c, prserr, "Conjun"
					"ction table is full.", prserr_len, (
					ftnlen)26);
				chkout_(__global_state, "ZZEKNRML", (ftnlen)8)
					;
				return 0;
			    }
			    lnkan_(__global_state, __state->cjpool, &
				    __state->cj[(i__1 = __state->i__ - 1) < 4 
				    && 0 <= i__1 ? i__1 : s_rnge(&
				    __global_state->f2c, "cj", i__1, "zzeknr"
				    "ml_", (ftnlen)1671)]);
			    __state->cjptrs[(i__2 = __state->cj[(i__1 = 
				    __state->i__ - 1) < 4 && 0 <= i__1 ? i__1 
				    : s_rnge(&__global_state->f2c, "cj", i__1,
				     "zzeknrml_", (ftnlen)1673)] - 1) < 5000 
				    && 0 <= i__2 ? i__2 : s_rnge(&
				    __global_state->f2c, "cjptrs", i__2, 
				    "zzeknrml_", (ftnlen)1673)] = 
				    __state->rel[(i__3 = __state->i__ - 1) < 
				    4 && 0 <= i__3 ? i__3 : s_rnge(&
				    __global_state->f2c, "rel", i__3, "zzekn"
				    "rml_", (ftnlen)1673)];
			}

/*                    Link the conjunction nodes to form the two */
/*                    conjunctions shown above. */

			lnkila_(__global_state, __state->cj, &__state->cj[1], 
				__state->cjpool);
			lnkila_(__global_state, &__state->cj[2], &__state->cj[
				3], __state->cjpool);

/*                    Allocate disjunction pool entries and make them */
/*                    point to the two respective conjunctions. */

			for (__state->i__ = 1; __state->i__ <= 2; 
				++__state->i__) {
			    if (lnknfn_(__global_state, __state->djpool) < 1) 
				    {
				*error = TRUE_;
				s_copy(&__global_state->f2c, prserr, "Disjun"
					"ction table is full.", prserr_len, (
					ftnlen)26);
				chkout_(__global_state, "ZZEKNRML", (ftnlen)8)
					;
				return 0;
			    }
			    lnkan_(__global_state, __state->djpool, &
				    __state->dj[(i__1 = __state->i__ - 1) < 2 
				    && 0 <= i__1 ? i__1 : s_rnge(&
				    __global_state->f2c, "dj", i__1, "zzeknr"
				    "ml_", (ftnlen)1697)]);
			    __state->djptrs[(i__2 = __state->dj[(i__1 = 
				    __state->i__ - 1) < 2 && 0 <= i__1 ? i__1 
				    : s_rnge(&__global_state->f2c, "dj", i__1,
				     "zzeknrml_", (ftnlen)1698)] - 1) < 5000 
				    && 0 <= i__2 ? i__2 : s_rnge(&
				    __global_state->f2c, "djptrs", i__2, 
				    "zzeknrml_", (ftnlen)1698)] = __state->cj[
				    (i__3 = (__state->i__ << 1) - 2) < 4 && 0 
				    <= i__3 ? i__3 : s_rnge(&
				    __global_state->f2c, "cj", i__3, "zzeknr"
				    "ml_", (ftnlen)1698)];
			}

/*                    Finally, link the disjunction pool entries, and */
/*                    create an <expression> meta-token.  Free the unused */
/*                    meta-tokens. */

			lnkila_(__global_state, __state->dj, &__state->dj[1], 
				__state->djpool);
			__state->mtcode[(i__1 = __state->first - 1) < 500 && 
				0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "mtcode", i__1, "zzeknr"
				"ml_", (ftnlen)1709)] = -13;
			__state->mtexpr[(i__1 = __state->first - 1) < 500 && 
				0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "mtexpr", i__1, "zzeknr"
				"ml_", (ftnlen)1710)] = __state->dj[0];
			lnkfsl_(__global_state, &__state->second, &
				__state->third, __state->mtpool);
			__state->nmeta += -2;

/*                    Decide the next state. */

			__state->state = 3;
		    } else if (__state->mtcode[(i__1 = __state->second - 1) < 
			    500 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "mtcode", i__1, "zzeknrml_", 
			    (ftnlen)1721)] == -4 && __state->mtcode[(i__2 = 
			    __state->third - 1) < 500 && 0 <= i__2 ? i__2 : 
			    s_rnge(&__global_state->f2c, "mtcode", i__2, 
			    "zzeknrml_", (ftnlen)1721)] == -5) {

/*                    It's a NOT BETWEEN comparison.  We treat */
/*                    this as a disjunction of conjunctions of comparison */
/*                    relations: */

/*                                      <name>   <   <item1> */
/*                              AND     <name>   <   <item2> */

/*                         OR */
/*                                      <name>   >   <item1> */
/*                              AND     <name>   >   <item2> */

/*                    where item1 and item2 are specified by the */
/*                    descriptors belonging to the third meta-token. */

/*                    The actions here are closely analogous to those */
/*                    for the BETWEEN case. */

			for (__state->i__ = 1; __state->i__ <= 4; 
				++__state->i__) {
			    if (__state->i__ == 1 || __state->i__ == 3) {
				__state->k = __state->mtexpr[(i__1 = 
					__state->third - 1) < 500 && 0 <= 
					i__1 ? i__1 : s_rnge(&
					__global_state->f2c, "mtexpr", i__1, 
					"zzeknrml_", (ftnlen)1745)];
			    } else {

/*                          We need the descriptor pointer for the RHS */
/*                          item.  This descriptor is linked to the tail */
/*                          of the descriptor for the LHS item.  The */
/*                          number of nodes to skip over depends on */
/*                          whether the LHS item is a name or value. */

				__state->k = __state->mtexpr[(i__1 = 
					__state->third - 1) < 500 && 0 <= 
					i__1 ? i__1 : s_rnge(&
					__global_state->f2c, "mtexpr", i__1, 
					"zzeknrml_", (ftnlen)1755)];
				if (__state->dscbuf[(i__1 = __state->k * 7 - 
					1) < 35000 && 0 <= i__1 ? i__1 : 
					s_rnge(&__global_state->f2c, "dscbuf",
					 i__1, "zzeknrml_", (ftnlen)1757)] == 
					-7) {
				    __state->skip = 1;
				} else {
				    __state->skip = 0;
				}
				i__1 = __state->skip + 1;
				for (__state->j = 1; __state->j <= i__1; 
					++__state->j) {
				    __state->k = lnknxt_(__global_state, &
					    __state->k, __state->dspool);
				}
			    }
			    if (lnknfn_(__global_state, __state->rlpool) < 1) 
				    {
				*error = TRUE_;
				s_copy(&__global_state->f2c, prserr, "Relati"
					"on table is full.", prserr_len, (
					ftnlen)23);
				chkout_(__global_state, "ZZEKNRML", (ftnlen)8)
					;
				return 0;
			    }
			    lnkan_(__global_state, __state->rlpool, &
				    __state->rel[(i__1 = __state->i__ - 1) < 
				    4 && 0 <= i__1 ? i__1 : s_rnge(&
				    __global_state->f2c, "rel", i__1, "zzekn"
				    "rml_", (ftnlen)1777)]);
			    __state->rels[(i__2 = __state->rel[(i__1 = 
				    __state->i__ - 1) < 4 && 0 <= i__1 ? i__1 
				    : s_rnge(&__global_state->f2c, "rel", 
				    i__1, "zzeknrml_", (ftnlen)1780)] * 3 - 3)
				     < 15000 && 0 <= i__2 ? i__2 : s_rnge(&
				    __global_state->f2c, "rels", i__2, "zzek"
				    "nrml_", (ftnlen)1780)] = __state->mtexpr[(
				    i__3 = __state->first - 1) < 500 && 0 <= 
				    i__3 ? i__3 : s_rnge(&__global_state->f2c,
				     "mtexpr", i__3, "zzeknrml_", (ftnlen)
				    1780)];
			    if (__state->i__ <= 2) {
				__state->rels[(i__2 = __state->rel[(i__1 = 
					__state->i__ - 1) < 4 && 0 <= i__1 ? 
					i__1 : s_rnge(&__global_state->f2c, 
					"rel", i__1, "zzeknrml_", (ftnlen)
					1783)] * 3 - 2) < 15000 && 0 <= i__2 ?
					 i__2 : s_rnge(&__global_state->f2c, 
					"rels", i__2, "zzeknrml_", (ftnlen)
					1783)] = 5;
			    } else {
				__state->rels[(i__2 = __state->rel[(i__1 = 
					__state->i__ - 1) < 4 && 0 <= i__1 ? 
					i__1 : s_rnge(&__global_state->f2c, 
					"rel", i__1, "zzeknrml_", (ftnlen)
					1785)] * 3 - 2) < 15000 && 0 <= i__2 ?
					 i__2 : s_rnge(&__global_state->f2c, 
					"rels", i__2, "zzeknrml_", (ftnlen)
					1785)] = 3;
			    }
			    __state->rels[(i__2 = __state->rel[(i__1 = 
				    __state->i__ - 1) < 4 && 0 <= i__1 ? i__1 
				    : s_rnge(&__global_state->f2c, "rel", 
				    i__1, "zzeknrml_", (ftnlen)1788)] * 3 - 1)
				     < 15000 && 0 <= i__2 ? i__2 : s_rnge(&
				    __global_state->f2c, "rels", i__2, "zzek"
				    "nrml_", (ftnlen)1788)] = __state->k;
			    if (lnknfn_(__global_state, __state->cjpool) < 1) 
				    {
				*error = TRUE_;
				s_copy(&__global_state->f2c, prserr, "Conjun"
					"ction table is full.", prserr_len, (
					ftnlen)26);
				chkout_(__global_state, "ZZEKNRML", (ftnlen)8)
					;
				return 0;
			    }
			    lnkan_(__global_state, __state->cjpool, &
				    __state->cj[(i__1 = __state->i__ - 1) < 4 
				    && 0 <= i__1 ? i__1 : s_rnge(&
				    __global_state->f2c, "cj", i__1, "zzeknr"
				    "ml_", (ftnlen)1798)]);
			    __state->cjptrs[(i__2 = __state->cj[(i__1 = 
				    __state->i__ - 1) < 4 && 0 <= i__1 ? i__1 
				    : s_rnge(&__global_state->f2c, "cj", i__1,
				     "zzeknrml_", (ftnlen)1800)] - 1) < 5000 
				    && 0 <= i__2 ? i__2 : s_rnge(&
				    __global_state->f2c, "cjptrs", i__2, 
				    "zzeknrml_", (ftnlen)1800)] = 
				    __state->rel[(i__3 = __state->i__ - 1) < 
				    4 && 0 <= i__3 ? i__3 : s_rnge(&
				    __global_state->f2c, "rel", i__3, "zzekn"
				    "rml_", (ftnlen)1800)];
			}

/*                    Link the conjunction nodes to form the two */
/*                    conjunctions shown above. */

			lnkila_(__global_state, __state->cj, &__state->cj[1], 
				__state->cjpool);
			lnkila_(__global_state, &__state->cj[2], &__state->cj[
				3], __state->cjpool);

/*                    Allocate disjunction pool entries and make them */
/*                    point to the two respective conjunctions. */

			for (__state->i__ = 1; __state->i__ <= 2; 
				++__state->i__) {
			    if (lnknfn_(__global_state, __state->djpool) < 1) 
				    {
				*error = TRUE_;
				s_copy(&__global_state->f2c, prserr, "Disjun"
					"ction table is full.", prserr_len, (
					ftnlen)26);
				chkout_(__global_state, "ZZEKNRML", (ftnlen)8)
					;
				return 0;
			    }
			    lnkan_(__global_state, __state->djpool, &
				    __state->dj[(i__1 = __state->i__ - 1) < 2 
				    && 0 <= i__1 ? i__1 : s_rnge(&
				    __global_state->f2c, "dj", i__1, "zzeknr"
				    "ml_", (ftnlen)1824)]);
			    __state->djptrs[(i__2 = __state->dj[(i__1 = 
				    __state->i__ - 1) < 2 && 0 <= i__1 ? i__1 
				    : s_rnge(&__global_state->f2c, "dj", i__1,
				     "zzeknrml_", (ftnlen)1825)] - 1) < 5000 
				    && 0 <= i__2 ? i__2 : s_rnge(&
				    __global_state->f2c, "djptrs", i__2, 
				    "zzeknrml_", (ftnlen)1825)] = __state->cj[
				    (i__3 = (__state->i__ << 1) - 2) < 4 && 0 
				    <= i__3 ? i__3 : s_rnge(&
				    __global_state->f2c, "cj", i__3, "zzeknr"
				    "ml_", (ftnlen)1825)];
			}

/*                    Finally, link the disjunction pool entries, and */
/*                    create an <expression> meta-token.  Free the unused */
/*                    meta-tokens. */

			lnkila_(__global_state, __state->dj, &__state->dj[1], 
				__state->djpool);
			__state->mtcode[(i__1 = __state->first - 1) < 500 && 
				0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "mtcode", i__1, "zzeknr"
				"ml_", (ftnlen)1836)] = -13;
			__state->mtexpr[(i__1 = __state->first - 1) < 500 && 
				0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "mtexpr", i__1, "zzeknr"
				"ml_", (ftnlen)1837)] = __state->dj[0];
			lnkfsl_(__global_state, &__state->second, &
				__state->third, __state->mtpool);
			__state->nmeta += -2;

/*                    Decide the next state. */

			__state->state = 3;
		    } else if (__state->mtcode[(i__1 = __state->third - 1) < 
			    500 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "mtcode", i__1, "zzeknrml_", 
			    (ftnlen)1847)] == -6 || __state->mtcode[(i__2 = 
			    __state->third - 1) < 500 && 0 <= i__2 ? i__2 : 
			    s_rnge(&__global_state->f2c, "mtcode", i__2, 
			    "zzeknrml_", (ftnlen)1847)] == -8) {

/*                    If the third meta-token is anything other than */
/*                    <BETWEEN expr>, we'll have to parse the portion of */
/*                    the query following the BETWEEN keyword before */
/*                    reducing the <BETWEEN> or <NOT BETWEEN> expression. */

			__state->start = __state->third;
			__state->retcnd = 1;
			__state->state = 0;
		    } else {
			*error = TRUE_;
			s_copy(&__global_state->f2c, prserr, "Token followin"
				"g BETWEEN operator is invalid.", prserr_len, (
				ftnlen)44);
			chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
			return 0;
		    }
		} else if (__state->mtcode[(i__1 = __state->second - 1) < 500 
			&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			"mtcode", i__1, "zzeknrml_", (ftnlen)1870)] > 0) {

/*                 The third meta-token is in the wrong place at the */
/*                 wrong time. */

		    *error = TRUE_;
		    s_copy(&__global_state->f2c, prserr, "Token sequence mus"
			    "t be followed by a value.", prserr_len, (ftnlen)
			    43);
		    chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
		    return 0;
		} else {

/*                 The second meta-token is supposed to be a comparison */
/*                 operator, but it's actually something else. */

		    *error = TRUE_;
		    s_copy(&__global_state->f2c, prserr, "Token must be foll"
			    "owed by a comparison operator.", prserr_len, (
			    ftnlen)48);
		    chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
		    return 0;
		}
	    } else if (__state->mtcode[(i__1 = __state->first - 1) < 500 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtcode", 
		    i__1, "zzeknrml_", (ftnlen)1899)] == -13) {

/*              If the query is valid, the sequence of meta-tokens */
/*              should be one of */

/*                 <expression> */
/*                 <expression>   ) */
/*                 <expression>   OR   <expression> */
/*                 <expression>   OR   NAME */
/*                 <expression>   OR   IDENT */
/*                 <expression>   OR   NOT */
/*                 <expression>   OR   ( */
/*                 <expression>   AND  <expression> */
/*                 <expression>   AND  NAME */
/*                 <expression>   AND  IDENT */
/*                 <expression>   AND  NOT */
/*                 <expression>   AND  ( */

		if (__state->second <= 0) {

/*                 This is the last state we pass through */
/*                 before exiting the loop.  However, some syntax errors */
/*                 can get us here as well. */

		    if (__state->level > 1 || __state->nmeta > 1) {
			*error = TRUE_;
			s_copy(&__global_state->f2c, prserr, "More tokens ex"
				"pected.", prserr_len, (ftnlen)21);
			chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
			return 0;
		    }
		    __state->state = 4;
		} else if (__state->mtcode[(i__1 = __state->second - 1) < 500 
			&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			"mtcode", i__1, "zzeknrml_", (ftnlen)1935)] == -1) {

/*                 We've reached the end of a `parenthesized' */
/*                 expression. */

		    if (__state->level > 1 && __state->popcnd[(i__1 = 
			    __state->level - 1) < 500 && 0 <= i__1 ? i__1 : 
			    s_rnge(&__global_state->f2c, "popcnd", i__1, 
			    "zzeknrml_", (ftnlen)1940)] == 2) {

/*                    Time to pop the state. */

			__state->state = 1;
		    } else {

/*                    There should not be a right grouper here. */

			*error = TRUE_;
			s_copy(&__global_state->f2c, prserr, "Unexpected rig"
				"ht parenthesis found.", prserr_len, (ftnlen)
				35);
			chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
			return 0;
		    }

/*              In all other cases, there must be at least three */
/*              meta-tokens here.  Make sure there are. */

		} else if (__state->third <= 0) {
		    *error = TRUE_;
		    s_copy(&__global_state->f2c, prserr, "More tokens expect"
			    "ed.", prserr_len, (ftnlen)21);
		    chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
		    return 0;

/*              Take care of the cases that will require reducing a sub- */
/*              expression before reducing the current expression. */

		} else if (__state->mtcode[(i__1 = __state->third - 1) < 500 
			&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			"mtcode", i__1, "zzeknrml_", (ftnlen)1975)] == -7 || 
			__state->mtcode[(i__2 = __state->third - 1) < 500 && 
			0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "mtc"
			"ode", i__2, "zzeknrml_", (ftnlen)1975)] == -6 || 
			__state->mtcode[(i__3 = __state->third - 1) < 500 && 
			0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, "mtc"
			"ode", i__3, "zzeknrml_", (ftnlen)1975)] == -12) {
		    __state->start = __state->third;
		    __state->retcnd = 1;
		    __state->state = 0;
		} else if (__state->mtcode[(i__1 = __state->third - 1) < 500 
			&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			"mtcode", i__1, "zzeknrml_", (ftnlen)1984)] == -2) {

/*                 We'll have to push our state before continuing. */

		    __state->start = __state->fourth;
		    __state->retcnd = 2;
		    __state->state = 0;

/*              Now continue with the interesting cases. */

		} else if (__state->mtcode[(i__1 = __state->first - 1) < 500 
			&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			"mtcode", i__1, "zzeknrml_", (ftnlen)1995)] == -13 && 
			__state->mtcode[(i__2 = __state->second - 1) < 500 && 
			0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "mtc"
			"ode", i__2, "zzeknrml_", (ftnlen)1995)] == -11 && 
			__state->mtcode[(i__3 = __state->third - 1) < 500 && 
			0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, "mtc"
			"ode", i__3, "zzeknrml_", (ftnlen)1995)] == -13) {

/*                 We have a disjunction of two normalized */
/*                 expressions.  We're not ready to perform a */
/*                 reduction yet; we need to see whether there's */
/*                 a higher priority operator, namely AND, on the */
/*                 right of the second expression. */

		    __state->donow = TRUE_;
		    if (__state->fourth > 0) {
			if (__state->mtcode[(i__1 = __state->fourth - 1) < 
				500 && 0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "mtcode", i__1, "zzeknr"
				"ml_", (ftnlen)2009)] == -10) {

/*                       The third token is already spoken for: */
/*                       the expression involving the operator */
/*                       to its right must be processed first. */

			    __state->donow = FALSE_;
			}
		    }
		    if (__state->donow) {

/*                    This is an easy case to handle: */
/*                    we can form the resulting normalized */
/*                    expression by just linking together the two */
/*                    lists in the disjunction table. */

			__state->dj[0] = __state->mtexpr[(i__1 = 
				__state->first - 1) < 500 && 0 <= i__1 ? i__1 
				: s_rnge(&__global_state->f2c, "mtexpr", i__1,
				 "zzeknrml_", (ftnlen)2028)];
			__state->dj[1] = __state->mtexpr[(i__1 = 
				__state->third - 1) < 500 && 0 <= i__1 ? i__1 
				: s_rnge(&__global_state->f2c, "mtexpr", i__1,
				 "zzeknrml_", (ftnlen)2029)];
			lnkilb_(__global_state, __state->dj, &__state->dj[1], 
				__state->djpool);

/*                    The first meta-token will point to the resulting */
/*                    normalized expression; we'll discard the other */
/*                    two meta-tokens. */

			lnkfsl_(__global_state, &__state->second, &
				__state->third, __state->mtpool);
			__state->nmeta += -2;

/*                    MTEXPR(FIRST) and MTCODE(FIRST) are already */
/*                    set correctly.  All we need to do is determine */
/*                    our next state.  The next state defaults to */
/*                    PARSE; the other possibility is POP. */

			__state->state = 3;
		    } else {

/*                    We'll have to reduce the expression on the right */
/*                    of the third meta-token before coming back to */
/*                    this expression.  Get ready to push our state. */

/*                    The condition that must be met in order to pop our */
/*                    state will be that we've performed a reduction. */

			__state->retcnd = 1;
			__state->start = __state->third;
			__state->state = 0;
		    }

/*                 Either we've reduced an OR expression, in which case */
/*                 the state has been set to PARSE or POP, or we've */
/*                 found a sub-expression that must be reduced before */
/*                 we attack the current expression, in which case the */
/*                 state has been set to PUSH. */

		} else if (__state->mtcode[(i__1 = __state->first - 1) < 500 
			&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			"mtcode", i__1, "zzeknrml_", (ftnlen)2070)] == -13 && 
			__state->mtcode[(i__2 = __state->second - 1) < 500 && 
			0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "mtc"
			"ode", i__2, "zzeknrml_", (ftnlen)2070)] == -10 && 
			__state->mtcode[(i__3 = __state->third - 1) < 500 && 
			0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, "mtc"
			"ode", i__3, "zzeknrml_", (ftnlen)2070)] == -13) {

/*                 We have the conjunction of two normalized */
/*                 expressions.  This case requires application of */
/*                 DeMorgan's laws to convert the expression to a */
/*                 normalized form. */

/*                 If we have two normalized expressions, say */

/*                    EXPR1 =        ( A11 and A12 and ... ) */
/*                                or ( A21 and A22 and ... ) */
/*                                              . */
/*                                              . */
/*                                              . */
/*                                or ( AM1 and AM2 and ... ) */


/*                    EXPR2 =        ( B11 and B12 and ... ) */
/*                                or ( B21 and B22 and ... ) */
/*                                              . */
/*                                              . */
/*                                              . */
/*                                or ( BN1 and BN2 and ... ) */



/*                 Then ( EXPR1 and EXPR2 ) = */


/*                        or       {  (     ( AI1 and AI2 and ... ) */
/*                    I = 1,...,M       and ( BJ1 and BJ2 and ... ) )  } */
/*                    J = 1,...,N */


/*                 We have the conjunction of two normalized */
/*                 So, to represent the normalized expression resulting */
/*                 from the conjuction of the expressions represented by */
/*                 the meta-tokens FIRST and THIRD, we will loop through */
/*                 each disjunction list and form the disjunction of all */
/*                 conjunctions of pairs of conjunctions, one of which is */
/*                 from the first expression and one of which is from the */
/*                 second.  After doing this, we'll clean up the */
/*                 conjunction and disjunction pools by freeing the */
/*                 elements in those pools used by the original two */
/*                 meta-tokens FIRST and THIRD. */


		    __state->dj[0] = __state->mtexpr[(i__1 = __state->first - 
			    1) < 500 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "mtexpr", i__1, "zzeknrml_", 
			    (ftnlen)2119)];
		    __state->djtail = 0;
		    while(__state->dj[0] > 0) {
			__state->dj[1] = __state->mtexpr[(i__1 = 
				__state->third - 1) < 500 && 0 <= i__1 ? i__1 
				: s_rnge(&__global_state->f2c, "mtexpr", i__1,
				 "zzeknrml_", (ftnlen)2124)];
			while(__state->dj[1] > 0) {

/*                       Allocate a new disjunction table entry, */
/*                       and create a new conjunction that represents */
/*                       the conjunction of the conjunction lists */
/*                       pointed to by DJ(1) and DJ(2). */

			    if (lnknfn_(__global_state, __state->djpool) < 1) 
				    {
				*error = TRUE_;
				s_copy(&__global_state->f2c, prserr, "Disjun"
					"ction table is full.", prserr_len, (
					ftnlen)26);
				chkout_(__global_state, "ZZEKNRML", (ftnlen)8)
					;
				return 0;
			    }
			    lnkan_(__global_state, __state->djpool, &
				    __state->newdj);

/*                       Make copies of the conjunction lists pointed */
/*                       to by DJ(1) and DJ(2). */

			    __state->cj[0] = __state->djptrs[(i__1 = 
				    __state->dj[0] - 1) < 5000 && 0 <= i__1 ? 
				    i__1 : s_rnge(&__global_state->f2c, "djp"
				    "trs", i__1, "zzeknrml_", (ftnlen)2146)];
			    __state->tail = 0;
			    while(__state->cj[0] > 0) {
				if (lnknfn_(__global_state, __state->cjpool) <
					 1) {
				    *error = TRUE_;
				    s_copy(&__global_state->f2c, prserr, 
					    "Conjunction table is full.", 
					    prserr_len, (ftnlen)26);
				    chkout_(__global_state, "ZZEKNRML", (
					    ftnlen)8);
				    return 0;
				}
				lnkan_(__global_state, __state->cjpool, &
					__state->newcj);
				lnkila_(__global_state, &__state->tail, &
					__state->newcj, __state->cjpool);
				__state->tail = __state->newcj;
				__state->cjptrs[(i__1 = __state->tail - 1) < 
					5000 && 0 <= i__1 ? i__1 : s_rnge(&
					__global_state->f2c, "cjptrs", i__1, 
					"zzeknrml_", (ftnlen)2161)] = 
					__state->cjptrs[(i__2 = __state->cj[0]
					 - 1) < 5000 && 0 <= i__2 ? i__2 : 
					s_rnge(&__global_state->f2c, "cjptrs",
					 i__2, "zzeknrml_", (ftnlen)2161)];
				__state->cj[0] = lnknxt_(__global_state, 
					__state->cj, __state->cjpool);
			    }
			    __state->head1 = lnkhl_(__global_state, &
				    __state->tail, __state->cjpool);
			    __state->cj[1] = __state->djptrs[(i__1 = 
				    __state->dj[1] - 1) < 5000 && 0 <= i__1 ? 
				    i__1 : s_rnge(&__global_state->f2c, "djp"
				    "trs", i__1, "zzeknrml_", (ftnlen)2170)];
			    __state->tail = 0;
			    while(__state->cj[1] > 0) {
				if (lnknfn_(__global_state, __state->cjpool) <
					 1) {
				    *error = TRUE_;
				    s_copy(&__global_state->f2c, prserr, 
					    "Conjunction table is full.", 
					    prserr_len, (ftnlen)26);
				    chkout_(__global_state, "ZZEKNRML", (
					    ftnlen)8);
				    return 0;
				}
				lnkan_(__global_state, __state->cjpool, &
					__state->newcj);
				lnkila_(__global_state, &__state->tail, &
					__state->newcj, __state->cjpool);
				__state->tail = __state->newcj;
				__state->cjptrs[(i__1 = __state->tail - 1) < 
					5000 && 0 <= i__1 ? i__1 : s_rnge(&
					__global_state->f2c, "cjptrs", i__1, 
					"zzeknrml_", (ftnlen)2185)] = 
					__state->cjptrs[(i__2 = __state->cj[1]
					 - 1) < 5000 && 0 <= i__2 ? i__2 : 
					s_rnge(&__global_state->f2c, "cjptrs",
					 i__2, "zzeknrml_", (ftnlen)2185)];
				__state->cj[1] = lnknxt_(__global_state, &
					__state->cj[1], __state->cjpool);
			    }
			    __state->head2 = lnkhl_(__global_state, &
				    __state->tail, __state->cjpool);

/*                       Now link these copies and make NEWDJ point to */
/*                       the resulting list. */

			    lnkilb_(__global_state, &__state->head1, &
				    __state->head2, __state->cjpool);
			    __state->djptrs[(i__1 = __state->newdj - 1) < 
				    5000 && 0 <= i__1 ? i__1 : s_rnge(&
				    __global_state->f2c, "djptrs", i__1, 
				    "zzeknrml_", (ftnlen)2199)] = 
				    __state->head1;

/*                       Link NEWDJ in at the tail of the disjunction */
/*                       list. */

			    lnkila_(__global_state, &__state->djtail, &
				    __state->newdj, __state->djpool);
			    __state->djtail = __state->newdj;
			    __state->dj[1] = lnknxt_(__global_state, &
				    __state->dj[1], __state->djpool);
			}
			__state->dj[0] = lnknxt_(__global_state, __state->dj, 
				__state->djpool);
		    }

/*                 We've now created the new normalized expression that */
/*                 represents the conjunction of our original two */
/*                 expressions. */

/*                 Before continuing, we should clean up the entries in */
/*                 the disjunction and conjunction pools used by the */
/*                 original expressions.  We can save a little work */
/*                 by linking those entries before freeing them. */

		    lnkilb_(__global_state, &__state->mtexpr[(i__1 = 
			    __state->first - 1) < 500 && 0 <= i__1 ? i__1 : 
			    s_rnge(&__global_state->f2c, "mtexpr", i__1, 
			    "zzeknrml_", (ftnlen)2226)], &__state->mtexpr[(
			    i__2 = __state->third - 1) < 500 && 0 <= i__2 ? 
			    i__2 : s_rnge(&__global_state->f2c, "mtexpr", 
			    i__2, "zzeknrml_", (ftnlen)2226)], 
			    __state->djpool);
		    __state->djnode = __state->mtexpr[(i__1 = __state->first 
			    - 1) < 500 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "mtexpr", i__1, "zzeknrml_", 
			    (ftnlen)2228)];
		    while(__state->djnode > 0) {

/*                    Free the conjunction list pointed to by DJNODE. */

			__state->cjnode = __state->djptrs[(i__1 = 
				__state->djnode - 1) < 5000 && 0 <= i__1 ? 
				i__1 : s_rnge(&__global_state->f2c, "djptrs", 
				i__1, "zzeknrml_", (ftnlen)2234)];
			i__1 = lnktl_(__global_state, &__state->cjnode, 
				__state->cjpool);
			lnkfsl_(__global_state, &__state->cjnode, &i__1, 
				__state->cjpool);
			__state->djnode = lnknxt_(__global_state, &
				__state->djnode, __state->djpool);
		    }

/*                 Free the disjunction list that starts with */
/*                 MTEXPR(FIRST). */

		    i__3 = lnktl_(__global_state, &__state->mtexpr[(i__2 = 
			    __state->first - 1) < 500 && 0 <= i__2 ? i__2 : 
			    s_rnge(&__global_state->f2c, "mtexpr", i__2, 
			    "zzeknrml_", (ftnlen)2247)], __state->djpool);
		    lnkfsl_(__global_state, &__state->mtexpr[(i__1 = 
			    __state->first - 1) < 500 && 0 <= i__1 ? i__1 : 
			    s_rnge(&__global_state->f2c, "mtexpr", i__1, 
			    "zzeknrml_", (ftnlen)2247)], &i__3, 
			    __state->djpool);

/*                 NEWDJ is the tail node of the list of disjunctions */
/*                 we've just finished.  The first meta-token should */
/*                 point to the head of this disjunction list. */

		    __state->mtexpr[(i__1 = __state->first - 1) < 500 && 0 <= 
			    i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtex"
			    "pr", i__1, "zzeknrml_", (ftnlen)2256)] = lnkhl_(
			    __global_state, &__state->newdj, __state->djpool);

/*                 We no longer need the other two meta-tokens. */

		    lnkfsl_(__global_state, &__state->second, &__state->third,
			     __state->mtpool);
		    __state->nmeta += -2;

/*                 Decide the next state. */

		    __state->state = 3;
		} else {

/*                 There are no other valid cases in which the first */
/*                 meta-token is an expression. */

		    *error = TRUE_;
		    s_copy(&__global_state->f2c, prserr, "Unexpected token f"
			    "ound following valid expression.", prserr_len, (
			    ftnlen)50);
		    chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
		    return 0;
		}
	    } else if (__state->mtcode[(i__1 = __state->first - 1) < 500 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtcode", 
		    i__1, "zzeknrml_", (ftnlen)2284)] == -12) {

/*              There are four valid token sequences that we could */
/*              see here: */

/*                 NOT  <expression> */
/*                 NOT  IDENT */
/*                 NOT  NAME */
/*                 NOT  NOT */
/*                 NOT  ( */

		if (__state->second <= 0) {
		    *error = TRUE_;
		    s_copy(&__global_state->f2c, prserr, "Tokens were missin"
			    "g from logical expression.", prserr_len, (ftnlen)
			    44);
		    chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
		    return 0;
		} else if (__state->mtcode[(i__1 = __state->second - 1) < 500 
			&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			"mtcode", i__1, "zzeknrml_", (ftnlen)2303)] == -2) {

/*                 We'll have to push our state before continuing. */

		    __state->start = __state->third;
		    __state->retcnd = 2;
		    __state->state = 0;
		} else if (__state->mtcode[(i__1 = __state->second - 1) < 500 
			&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			"mtcode", i__1, "zzeknrml_", (ftnlen)2312)] == -12 || 
			__state->mtcode[(i__2 = __state->second - 1) < 500 && 
			0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "mtc"
			"ode", i__2, "zzeknrml_", (ftnlen)2312)] == -7 || 
			__state->mtcode[(i__3 = __state->second - 1) < 500 && 
			0 <= i__3 ? i__3 : s_rnge(&__global_state->f2c, "mtc"
			"ode", i__3, "zzeknrml_", (ftnlen)2312)] == -6) {
		    __state->start = __state->second;
		    __state->retcnd = 1;
		    __state->state = 0;
		} else if (__state->mtcode[(i__1 = __state->second - 1) < 500 
			&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			"mtcode", i__1, "zzeknrml_", (ftnlen)2321)] == -13) {

/*                 We have the negation of a normalized expression. Since */
/*                 the NOT operator has higher precedence than any other, */
/*                 we need not concern ourselves with the token on the */
/*                 right of the expression. */

/*                 This case requires application of DeMorgan's laws to */
/*                 convert the expression to a normalized form. */


/*                 If we have a normalized expression, say */

/*                    EXPR  =         ( A11 and A12 and ... ) */
/*                                 or ( A21 and A22 and ... ) */
/*                                              . */
/*                                              . */
/*                                              . */
/*                                 or ( AM1 and AM2 and ... ) */

/*                 Then (using the tilde to express negation): */

/*                    ~EXPR =          ( ~A11 or ~A12 or ... ) */
/*                                 and ( ~A21 or ~A22 or ... ) */
/*                                              . */
/*                                              . */
/*                                              . */
/*                                 and ( ~AM1 or ~AM2 or ... ) */

/*                 Since each parenthesized expression above is a */
/*                 normalized expression, we can convert the conjunction */
/*                 of any of these expressions and a second normalized */
/*                 expression to normalized form using the method of the */
/*                 AND case above. */

/*                 We'll first build the expression */

/*                    ( ~A11 or ~A12 or ... ) */

/*                 and then combine the others with it, one by one. */
/*                 When we're all done, we'll negate the operators used */
/*                 in the comparison relations. */

/*                 The pointer EXPRHD will denote the head of the */
/*                 combined normalized expression. */

		    __state->djnode = __state->mtexpr[(i__1 = __state->second 
			    - 1) < 500 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "mtexpr", i__1, "zzeknrml_", 
			    (ftnlen)2367)];
		    __state->cjnode = __state->djptrs[(i__1 = __state->djnode 
			    - 1) < 5000 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "djptrs", i__1, "zzeknrml_", 
			    (ftnlen)2369)];
		    __state->tail = 0;
		    while(__state->cjnode > 0) {

/*                    Create a new singleton disjunction list */
/*                    that points to the relation pointed to by */
/*                    CJNODE. */

			if (lnknfn_(__global_state, __state->djpool) < 1) {
			    *error = TRUE_;
			    s_copy(&__global_state->f2c, prserr, "Disjunctio"
				    "n table is full.", prserr_len, (ftnlen)26)
				    ;
			    chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
			    return 0;
			}
			lnkan_(__global_state, __state->djpool, &
				__state->newdj);
			if (lnknfn_(__global_state, __state->cjpool) < 1) {
			    *error = TRUE_;
			    s_copy(&__global_state->f2c, prserr, "Conjunctio"
				    "n table is full.", prserr_len, (ftnlen)26)
				    ;
			    chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
			    return 0;
			}
			lnkan_(__global_state, __state->cjpool, &
				__state->newcj);
			__state->cjptrs[(i__1 = __state->newcj - 1) < 5000 && 
				0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "cjptrs", i__1, "zzeknr"
				"ml_", (ftnlen)2396)] = __state->cjptrs[(i__2 =
				 __state->cjnode - 1) < 5000 && 0 <= i__2 ? 
				i__2 : s_rnge(&__global_state->f2c, "cjptrs", 
				i__2, "zzeknrml_", (ftnlen)2396)];
			__state->djptrs[(i__1 = __state->newdj - 1) < 5000 && 
				0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "djptrs", i__1, "zzeknr"
				"ml_", (ftnlen)2397)] = __state->newcj;

/*                    Now link the new singleton disjunction list in */
/*                    at the tail of the disjunction list that */
/*                    parallels the conjunction list we're currently */
/*                    traversing. */

			lnkila_(__global_state, &__state->tail, &
				__state->newdj, __state->djpool);
			__state->tail = __state->newdj;
			__state->cjnode = lnknxt_(__global_state, &
				__state->cjnode, __state->cjpool);
		    }

/*                 Keep track of the head of the new normalized */
/*                 expression. */

		    __state->exprhd = lnkhl_(__global_state, &__state->tail, 
			    __state->djpool);

/*                 Now, for every remaining conjunction in the original */
/*                 expression, we'll form the normalized expression */
/*                 resulting from the conjunction of its negation and */
/*                 of our cumulative normalized expression.  As mentioned */
/*                 before, we won't negate the comparison operators */
/*                 just yet. */


		    __state->djnode = lnknxt_(__global_state, &
			    __state->djnode, __state->djpool);
		    while(__state->djnode > 0) {

/*                    Loop through our existing cumulative */
/*                    expression and the latest conjunction, forming */
/*                    all pairwise conjunctions. */

			__state->dj[0] = __state->exprhd;
			__state->djtail = 0;
			while(__state->dj[0] > 0) {
			    __state->cj[1] = __state->djptrs[(i__1 = 
				    __state->djnode - 1) < 5000 && 0 <= i__1 ?
				     i__1 : s_rnge(&__global_state->f2c, 
				    "djptrs", i__1, "zzeknrml_", (ftnlen)2439)
				    ];
			    while(__state->cj[1] > 0) {

/*                          Make a copy of the conjunction list pointed */
/*                          to by DJPTRS(DJ(1)). */

				__state->cjnode = __state->djptrs[(i__1 = 
					__state->dj[0] - 1) < 5000 && 0 <= 
					i__1 ? i__1 : s_rnge(&
					__global_state->f2c, "djptrs", i__1, 
					"zzeknrml_", (ftnlen)2446)];
				__state->tail = 0;
				while(__state->cjnode > 0) {
				    if (lnknfn_(__global_state, 
					    __state->cjpool) < 1) {
					*error = TRUE_;
					s_copy(&__global_state->f2c, prserr, 
						"Conjunction table is full.", 
						prserr_len, (ftnlen)26);
					chkout_(__global_state, "ZZEKNRML", (
						ftnlen)8);
					return 0;
				    }
				    lnkan_(__global_state, __state->cjpool, &
					    __state->newcj);
				    lnkila_(__global_state, &__state->tail, &
					    __state->newcj, __state->cjpool);
				    __state->cjptrs[(i__1 = __state->newcj - 
					    1) < 5000 && 0 <= i__1 ? i__1 : 
					    s_rnge(&__global_state->f2c, 
					    "cjptrs", i__1, "zzeknrml_", (
					    ftnlen)2461)] = __state->cjptrs[(
					    i__2 = __state->cjnode - 1) < 
					    5000 && 0 <= i__2 ? i__2 : s_rnge(
					    &__global_state->f2c, "cjptrs", 
					    i__2, "zzeknrml_", (ftnlen)2461)];
				    __state->tail = __state->newcj;
				    __state->cjnode = lnknxt_(__global_state, 
					    &__state->cjnode, __state->cjpool)
					    ;
				}
				__state->cj[0] = lnkhl_(__global_state, &
					__state->tail, __state->cjpool);

/*                          Allocate a new conjunction table entry for */
/*                          the conjunction of the expressions */
/*                          pointed to by CJ(1) and CJ(2).  Allocate a */
/*                          new disjunction table entry to point to this */
/*                          new conjunction. */

				if (lnknfn_(__global_state, __state->cjpool) <
					 1) {
				    *error = TRUE_;
				    s_copy(&__global_state->f2c, prserr, 
					    "Conjunction table is full.", 
					    prserr_len, (ftnlen)26);
				    chkout_(__global_state, "ZZEKNRML", (
					    ftnlen)8);
				    return 0;
				}
				lnkan_(__global_state, __state->cjpool, &
					__state->newcj);
				__state->cjptrs[(i__1 = __state->newcj - 1) < 
					5000 && 0 <= i__1 ? i__1 : s_rnge(&
					__global_state->f2c, "cjptrs", i__1, 
					"zzeknrml_", (ftnlen)2484)] = 
					__state->cjptrs[(i__2 = __state->cj[1]
					 - 1) < 5000 && 0 <= i__2 ? i__2 : 
					s_rnge(&__global_state->f2c, "cjptrs",
					 i__2, "zzeknrml_", (ftnlen)2484)];
				if (lnknfn_(__global_state, __state->djpool) <
					 1) {
				    *error = TRUE_;
				    s_copy(&__global_state->f2c, prserr, 
					    "Disjunction table is full.", 
					    prserr_len, (ftnlen)26);
				    chkout_(__global_state, "ZZEKNRML", (
					    ftnlen)8);
				    return 0;
				}
				lnkan_(__global_state, __state->djpool, &
					__state->newdj);

/*                          Hook everything up. */

				lnkilb_(__global_state, __state->cj, &
					__state->newcj, __state->cjpool);
				__state->djptrs[(i__1 = __state->newdj - 1) < 
					5000 && 0 <= i__1 ? i__1 : s_rnge(&
					__global_state->f2c, "djptrs", i__1, 
					"zzeknrml_", (ftnlen)2500)] = 
					__state->cj[0];
				lnkila_(__global_state, &__state->djtail, &
					__state->newdj, __state->djpool);
				__state->djtail = __state->newdj;
				__state->cj[1] = lnknxt_(__global_state, &
					__state->cj[1], __state->cjpool);
			    }
			    __state->dj[0] = lnknxt_(__global_state, 
				    __state->dj, __state->djpool);
			}

/*                    Before going on, clean up the conjunction and */
/*                    disjunction pool entries used by our last */
/*                    version of the cumulative expression. */

			__state->dj[0] = __state->exprhd;
			while(__state->dj[0] > 0) {
			    __state->cj[0] = __state->djptrs[(i__1 = 
				    __state->dj[0] - 1) < 5000 && 0 <= i__1 ? 
				    i__1 : s_rnge(&__global_state->f2c, "djp"
				    "trs", i__1, "zzeknrml_", (ftnlen)2522)];
			    __state->cj[1] = lnktl_(__global_state, 
				    __state->cj, __state->cjpool);
			    lnkfsl_(__global_state, __state->cj, &__state->cj[
				    1], __state->cjpool);
			    __state->dj[0] = lnknxt_(__global_state, 
				    __state->dj, __state->djpool);
			}
			i__1 = lnktl_(__global_state, &__state->exprhd, 
				__state->djpool);
			lnkfsl_(__global_state, &__state->exprhd, &i__1, 
				__state->djpool);

/*                    Set EXPRHD to be the head of our updated, */
/*                    cumulative expression.  Start to work on the */
/*                    next conjunction. */

			__state->exprhd = lnkhl_(__global_state, &
				__state->djtail, __state->djpool);
			__state->djnode = lnknxt_(__global_state, &
				__state->djnode, __state->djpool);
		    }

/*                 EXPRHD now points to a new expression that will */
/*                 represent the negation of the expression pointed */
/*                 to by MTEXPR(SECOND), as soon as we negate the */
/*                 comparison operators referenced in the expression. */
/*                 Take care of this last step now.  To make sure that */
/*                 we negate each operator exactly once, we build a set */
/*                 of relations to be negated, then negate each relation */
/*                 in the set. */

		    ssizei_(__global_state, &__state->c__5000, 
			    __state->relset);
		    __state->djnode = __state->mtexpr[(i__1 = __state->second 
			    - 1) < 500 && 0 <= i__1 ? i__1 : s_rnge(&
			    __global_state->f2c, "mtexpr", i__1, "zzeknrml_", 
			    (ftnlen)2557)];
		    while(__state->djnode > 0) {
			__state->cjnode = __state->djptrs[(i__1 = 
				__state->djnode - 1) < 5000 && 0 <= i__1 ? 
				i__1 : s_rnge(&__global_state->f2c, "djptrs", 
				i__1, "zzeknrml_", (ftnlen)2562)];
			while(__state->cjnode > 0) {
			    __state->relptr = __state->cjptrs[(i__1 = 
				    __state->cjnode - 1) < 5000 && 0 <= i__1 ?
				     i__1 : s_rnge(&__global_state->f2c, 
				    "cjptrs", i__1, "zzeknrml_", (ftnlen)2566)
				    ];
			    insrti_(__global_state, &__state->relptr, 
				    __state->relset);
			    __state->cjnode = lnknxt_(__global_state, &
				    __state->cjnode, __state->cjpool);
			}
			__state->djnode = lnknxt_(__global_state, &
				__state->djnode, __state->djpool);
		    }
		    i__1 = cardi_(__global_state, __state->relset);
		    for (__state->i__ = 1; __state->i__ <= i__1; 
			    ++__state->i__) {
			__state->relptr = __state->relset[(i__2 = 
				__state->i__ + 5) < 5006 && 0 <= i__2 ? i__2 :
				 s_rnge(&__global_state->f2c, "relset", i__2, 
				"zzeknrml_", (ftnlen)2580)];
			__state->j = isrchi_(__global_state, &__state->rels[(
				i__2 = __state->relptr * 3 - 2) < 15000 && 0 
				<= i__2 ? i__2 : s_rnge(&__global_state->f2c, 
				"rels", i__2, "zzeknrml_", (ftnlen)2581)], &
				__state->c__8, __state->cmpcde);
			__state->rels[(i__2 = __state->relptr * 3 - 2) < 
				15000 && 0 <= i__2 ? i__2 : s_rnge(&
				__global_state->f2c, "rels", i__2, "zzeknrml_"
				, (ftnlen)2584)] = __state->cmpneg[(i__3 = 
				__state->j - 1) < 8 && 0 <= i__3 ? i__3 : 
				s_rnge(&__global_state->f2c, "cmpneg", i__3, 
				"zzeknrml_", (ftnlen)2584)];
		    }

/*                 Set the pointer of the first meta-token to point */
/*                 to our normalized expression, and change the */
/*                 meta-token's code to <expr>. */

		    __state->mtexpr[(i__1 = __state->first - 1) < 500 && 0 <= 
			    i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtex"
			    "pr", i__1, "zzeknrml_", (ftnlen)2593)] = 
			    __state->exprhd;
		    __state->mtcode[(i__1 = __state->first - 1) < 500 && 0 <= 
			    i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtco"
			    "de", i__1, "zzeknrml_", (ftnlen)2594)] = -13;

/*                 Get rid of the second meta-token, and determine the */
/*                 next state. */

		    lnkfsl_(__global_state, &__state->second, &
			    __state->second, __state->mtpool);
		    --__state->nmeta;
		    __state->state = 3;
		} else {

/*                 The second token is invalid in this context. */

		    *error = TRUE_;
		    s_copy(&__global_state->f2c, prserr, "Token following NO"
			    "T operator was invalid.", prserr_len, (ftnlen)41);
		    chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
		    return 0;
		}

/*              This is the end of the NOT case. */

	    } else if (__state->mtcode[(i__1 = __state->first - 1) < 500 && 0 
		    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtcode", 
		    i__1, "zzeknrml_", (ftnlen)2621)] == -2) {

/*              We're looking at the start of a `parenthesized' */
/*              sub-expression. */

/*              Push our state, and start parsing at meta-token */
/*              SECOND.  The condition for popping our state will be */
/*              that we encounter a right grouper. */

		__state->retcnd = 2;
		__state->start = __state->second;
		__state->state = 0;
	    } else {

/*              Only a syntax error could get us here. */

		*error = TRUE_;
		s_copy(&__global_state->f2c, prserr, "Unexpected token found."
			, prserr_len, (ftnlen)23);
		chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
		return 0;
	    }

/*           This is the end of the code for the PARSE state.  We've */
/*           determined the next parsing state at this point. */

	} else if (__state->state == 3) {

/*           A reduction has been done.  Decide the next state. */

	    __state->state = 3;
	    if (__state->popcnd[(i__1 = __state->level - 1) < 500 && 0 <= 
		    i__1 ? i__1 : s_rnge(&__global_state->f2c, "popcnd", i__1,
		     "zzeknrml_", (ftnlen)2657)] == 1) {
		__state->state = 1;
	    } else {
		__state->mstart[(i__1 = __state->level - 1) < 500 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "mstart", 
			i__1, "zzeknrml_", (ftnlen)2660)] = __state->first;
		__state->state = 2;
	    }
	} else if (__state->state == 0) {

/*           Increment the stack level, and save the current */
/*           starting point and pop condition. */

	    ++__state->level;
	    if (__state->level > 500) {
		*error = TRUE_;
		s_copy(&__global_state->f2c, prserr, "Stack is full", 
			prserr_len, (ftnlen)13);
		__state->state = 4;
	    } else {
		__state->mstart[(i__1 = __state->level - 1) < 500 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "mstart", 
			i__1, "zzeknrml_", (ftnlen)2678)] = __state->start;
		__state->popcnd[(i__1 = __state->level - 1) < 500 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "popcnd", 
			i__1, "zzeknrml_", (ftnlen)2679)] = __state->retcnd;
		__state->state = 2;
	    }
	} else if (__state->state == 1) {

/*           If we can, pop the state. */

	    if (__state->level > 1) {
		if (__state->popcnd[(i__1 = __state->level - 1) < 500 && 0 <= 
			i__1 ? i__1 : s_rnge(&__global_state->f2c, "popcnd", 
			i__1, "zzeknrml_", (ftnlen)2690)] == 2) {

/*                 If we're popping the state because we encountered a */
/*                 right grouper, we have a meta-token sequence that */
/*                 looks like this: */

/*                    (  EXPR  ) */

/*                        ^    ^ */
/*                     FIRST  SECOND */

/*                 We need to remove the grouping tokens, taking care to */
/*                 update the starting token at the next lower level, if */
/*                 the left grouper was the starting token. */

		    __state->prev = lnkprv_(__global_state, &__state->first, 
			    __state->mtpool);
		    if (__state->mstart[(i__1 = __state->level - 2) < 500 && 
			    0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			    "mstart", i__1, "zzeknrml_", (ftnlen)2707)] == 
			    __state->prev) {
			__state->mstart[(i__1 = __state->level - 2) < 500 && 
				0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "mstart", i__1, "zzeknr"
				"ml_", (ftnlen)2708)] = __state->first;
		    }
		    if (__state->metahd == __state->prev) {
			__state->metahd = __state->first;
		    }
		    lnkfsl_(__global_state, &__state->prev, &__state->prev, 
			    __state->mtpool);
		    lnkfsl_(__global_state, &__state->second, &
			    __state->second, __state->mtpool);
		    __state->nmeta += -2;
		}
		--__state->level;
		__state->state = 2;
	    } else {
		*error = TRUE_;
		s_copy(&__global_state->f2c, prserr, "Syntax error:  badly f"
			"ormed WHERE clause.", prserr_len, (ftnlen)41);
		chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
		return 0;
	    }
	}

/*        We've considered all states. */

    }

/*     At this point, there should be a single meta-token of type EXPR. */
/*     This meta-token should point to a normalized expression.  We'll */
/*     set the encoded query to represent this expression.  For each */
/*     constraint, we'll add a constraint descriptor to the encoded */
/*     query.  We'll also update the count of constraints, the count of */
/*     conjunctions, and we'll add a list of conjunction sizes. */

    __state->djnode = __state->mtexpr[(i__1 = __state->first - 1) < 500 && 0 
	    <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "mtexpr", i__1, 
	    "zzeknrml_", (ftnlen)2750)];
    __state->nconj = 0;
    __state->nrels = 0;
    while(__state->djnode > 0) {
	++__state->nconj;
	__state->sizes[(i__1 = __state->nconj - 1) < 1000 && 0 <= i__1 ? i__1 
		: s_rnge(&__global_state->f2c, "sizes", i__1, "zzeknrml_", (
		ftnlen)2757)] = 0;
	__state->cjnode = __state->djptrs[(i__1 = __state->djnode - 1) < 5000 
		&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, "djptrs", 
		i__1, "zzeknrml_", (ftnlen)2758)];
	while(__state->cjnode > 0) {
	    ++__state->nrels;
	    __state->sizes[(i__1 = __state->nconj - 1) < 1000 && 0 <= i__1 ? 
		    i__1 : s_rnge(&__global_state->f2c, "sizes", i__1, "zzek"
		    "nrml_", (ftnlen)2763)] = __state->sizes[(i__2 = 
		    __state->nconj - 1) < 1000 && 0 <= i__2 ? i__2 : s_rnge(&
		    __global_state->f2c, "sizes", i__2, "zzeknrml_", (ftnlen)
		    2763)] + 1;
	    __state->relptr = __state->cjptrs[(i__1 = __state->cjnode - 1) < 
		    5000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "cjptrs", i__1, "zzeknrml_", (ftnlen)2764)];
	    __state->tabptr = __state->rels[(i__1 = __state->relptr * 3 - 3) <
		     15000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "rels", i__1, "zzeknrml_", (ftnlen)2766)];
	    __state->op = __state->rels[(i__1 = __state->relptr * 3 - 2) < 
		    15000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "rels", i__1, "zzeknrml_", (ftnlen)2767)];
	    __state->rhsptr = __state->rels[(i__1 = __state->relptr * 3 - 1) <
		     15000 && 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
		    "rels", i__1, "zzeknrml_", (ftnlen)2768)];

/*           Add a constraint descriptor to the encoded query.  The */
/*           structure of these descriptors is documented in the include */
/*           file for encoded query parameters. */

/*           First, save space for the constraint type.  We'll fill this */
/*           in after finding out what's on the right hand side. */

	    appndi_(__global_state, &__state->c__0, eqryi);
	    __state->k = cardi_(__global_state, eqryi);

/*           Next, add name descriptors for the table and column on */
/*           the left-hand side.  These descriptors are linked and */
/*           pointed to by NAMPTR. */

	    for (__state->i__ = 1; __state->i__ <= 6; ++__state->i__) {
		appndi_(__global_state, &__state->dscbuf[(i__1 = __state->i__ 
			+ __state->tabptr * 7 - 8) < 35000 && 0 <= i__1 ? 
			i__1 : s_rnge(&__global_state->f2c, "dscbuf", i__1, 
			"zzeknrml_", (ftnlen)2787)], eqryi);
	    }
	    __state->colptr = lnknxt_(__global_state, &__state->tabptr, 
		    __state->dspool);
	    for (__state->i__ = 1; __state->i__ <= 6; ++__state->i__) {
		appndi_(__global_state, &__state->dscbuf[(i__1 = __state->i__ 
			+ __state->colptr * 7 - 8) < 35000 && 0 <= i__1 ? 
			i__1 : s_rnge(&__global_state->f2c, "dscbuf", i__1, 
			"zzeknrml_", (ftnlen)2793)], eqryi);
	    }

/*           What happens next depends on whether the query has a null */
/*           value on the right hand side.  This is indicated by the */
/*           relation's value pointer being NIL. */

	    if (__state->rhsptr == 0) {

/*              For constraints involving null values, we change the */
/*              operator to ISNULL or NOTNUL as appropriate. */

		if (__state->op == 1) {
		    __state->op = 9;
		} else if (__state->op == 6) {
		    __state->op = 10;
		} else {
		    *error = TRUE_;
		    s_copy(&__global_state->f2c, prserr, "NULL values can on"
			    "ly be used with the operators \"IS NULL\", \"NOT"
			    " NULL\", or equivalents.", prserr_len, (ftnlen)86)
			    ;
		    chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
		    return 0;
		}

/*              Set the operator code. */

		appndi_(__global_state, &__state->op, eqryi);

/*              Pad the constraint descriptor up to the full length. */

		for (__state->i__ = 1; __state->i__ <= 12; ++__state->i__) {
		    appndi_(__global_state, &__state->c__0, eqryi);
		}

/*              Set the descriptor's type by updating the reserved */
/*              location. */

		eqryi[__state->k + 5] = 2;
	    } else {

/*              For `normal' constraints, that is, constraints that don't */
/*              involve null values, we set the operator code, then */
/*              fill in the information describing the RHS of the */
/*              constraint. */

		appndi_(__global_state, &__state->op, eqryi);
		if (__state->dscbuf[(i__1 = __state->rhsptr * 7 - 1) < 35000 
			&& 0 <= i__1 ? i__1 : s_rnge(&__global_state->f2c, 
			"dscbuf", i__1, "zzeknrml_", (ftnlen)2851)] == -8) {

/*                 The RHS contains a value.  Append the descriptor */
/*                 for the value, then pad the constraint descriptor. */

		    for (__state->i__ = 1; __state->i__ <= 6; ++__state->i__) 
			    {
			appndi_(__global_state, &__state->dscbuf[(i__1 = 
				__state->i__ + __state->rhsptr * 7 - 8) < 
				35000 && 0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "dscbuf", i__1, "zzeknr"
				"ml_", (ftnlen)2857)], eqryi);
		    }
		    for (__state->i__ = 1; __state->i__ <= 6; ++__state->i__) 
			    {
			appndi_(__global_state, &__state->c__0, eqryi);
		    }

/*                 Set the descriptor's type by updating the reserved */
/*                 location. */

		    eqryi[__state->k + 5] = 2;
		} else {

/*                 The RHS contains a column name.  Append the */
/*                 descriptors for the table and column. */

		    for (__state->i__ = 1; __state->i__ <= 6; ++__state->i__) 
			    {
			appndi_(__global_state, &__state->dscbuf[(i__1 = 
				__state->i__ + __state->rhsptr * 7 - 8) < 
				35000 && 0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "dscbuf", i__1, "zzeknr"
				"ml_", (ftnlen)2877)], eqryi);
		    }
		    __state->colptr = lnknxt_(__global_state, &
			    __state->rhsptr, __state->dspool);
		    for (__state->i__ = 1; __state->i__ <= 6; ++__state->i__) 
			    {
			appndi_(__global_state, &__state->dscbuf[(i__1 = 
				__state->i__ + __state->colptr * 7 - 8) < 
				35000 && 0 <= i__1 ? i__1 : s_rnge(&
				__global_state->f2c, "dscbuf", i__1, "zzeknr"
				"ml_", (ftnlen)2883)], eqryi);
		    }

/*                 Set the descriptor's type by updating the reserved */
/*                 location. */

		    eqryi[__state->k + 5] = 1;
		}
	    }

/*           We've updated the encoded query to reflect the current */
/*           constraint relation. */

	    __state->cjnode = lnknxt_(__global_state, &__state->cjnode, 
		    __state->cjpool);
	}

/*        We've set the array element SIZES(NCONJ). */

	__state->djnode = lnknxt_(__global_state, &__state->djnode, 
		__state->djpool);
    }

/*     Set the counts of constraints and conjunctions in the encoded */
/*     query. */

    zzekweqi_(__global_state, "NUM_CONSTRAINTS", &__state->nrels, eqryi, (
	    ftnlen)15);
    zzekweqi_(__global_state, "NUM_CONJUNCTIONS", &__state->nconj, eqryi, (
	    ftnlen)16);

/*     Add the conjunction size list to the encoded query. */

    i__1 = __state->nconj;
    for (__state->i__ = 1; __state->i__ <= i__1; ++__state->i__) {
	appndi_(__global_state, &__state->sizes[(i__2 = __state->i__ - 1) < 
		1000 && 0 <= i__2 ? i__2 : s_rnge(&__global_state->f2c, "siz"
		"es", i__2, "zzeknrml_", (ftnlen)2920)], eqryi);
    }
    chkout_(__global_state, "ZZEKNRML", (ftnlen)8);
    return 0;
} /* zzeknrml_ */

