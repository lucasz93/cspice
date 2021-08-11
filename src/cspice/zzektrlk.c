/* zzektrlk.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzektrlk_init_t __zzektrlk_init;
static zzektrlk_state_t* get_zzektrlk_state() {
	cspice_t* state =  __cspice_get_state();
	if (!state->zzektrlk)
		state->zzektrlk = __cspice_allocate_module(sizeof(
	zzektrlk_state_t), &__zzektrlk_init, sizeof(__zzektrlk_init));
	return state->zzektrlk;

}

/* $Procedure      ZZEKTRLK ( EK tree, locate key ) */
/* Subroutine */ int zzektrlk_(integer *handle, integer *tree, integer *key, 
	integer *idx, integer *node, integer *noffst, integer *level, integer 
	*value)
{
    /* Initialized data */


    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_rnge(char *, integer, 
	    char *, integer);

    /* Local variables */
    extern /* Subroutine */ int zzekpgri_(integer *, integer *, integer *);
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    extern /* Subroutine */ int dasham_(integer *, char *, ftnlen);
    extern integer lstlei_(integer *, integer *, integer *);
    extern /* Subroutine */ int setmsg_(char *, ftnlen);
    extern /* Subroutine */ int errint_(char *, integer *, ftnlen);
    extern /* Subroutine */ int errhan_(char *, integer *, ftnlen);
    extern /* Subroutine */ int sigerr_(char *, ftnlen);
    extern /* Subroutine */ int chkout_(char *, ftnlen);


    /* Module state */
    zzektrlk_state_t* __state = get_zzektrlk_state();
/* $ Abstract */

/*     Locate a specified key.  Return metadata describing the node */
/*     containing the key. */

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


/*     Include Section:  EK Das Paging Parameters */

/*        ekpage.inc  Version 4    25-AUG-1995 (NJB) */



/*     The EK DAS paging system makes use of the integer portion */
/*     of an EK file's DAS address space to store the few numbers */
/*     required to describe the system's state.  The allocation */
/*     of DAS integer addresses is shown below. */


/*                       DAS integer array */

/*        +--------------------------------------------+ */
/*        |            EK architecture code            |  Address = 1 */
/*        +--------------------------------------------+ */
/*        |      Character page size (in DAS words)    | */
/*        +--------------------------------------------+ */
/*        |        Character page base address         | */
/*        +--------------------------------------------+ */
/*        |      Number of character pages in file     | */
/*        +--------------------------------------------+ */
/*        |   Number of character pages on free list   | */
/*        +--------------------------------------------+ */
/*        |      Character free list head pointer      |  Address = 6 */
/*        +--------------------------------------------+ */
/*        |                                            |  Addresses = */
/*        |           Metadata for d.p. pages          |    7--11 */
/*        |                                            | */
/*        +--------------------------------------------+ */
/*        |                                            |  Addresses = */
/*        |         Metadata for integer pages         |    12--16 */
/*        |                                            | */
/*        +--------------------------------------------+ */
/*                              . */
/*                              . */
/*                              . */
/*        +--------------------------------------------+ */
/*        |                                            |  End Address = */
/*        |                Unused space                |  integer page */
/*        |                                            |  end */
/*        +--------------------------------------------+ */
/*        |                                            |  Start Address = */
/*        |             First integer page             |  integer page */
/*        |                                            |  base */
/*        +--------------------------------------------+ */
/*                              . */
/*                              . */
/*                              . */
/*        +--------------------------------------------+ */
/*        |                                            | */
/*        |              Last integer page             | */
/*        |                                            | */
/*        +--------------------------------------------+ */

/*     The following parameters indicate positions of elements in the */
/*     paging system metadata array: */



/*     Number of metadata items per data type: */


/*     Character metadata indices: */


/*     Double precision metadata indices: */


/*     Integer metadata indices: */


/*     Size of metadata area: */


/*     Page sizes, in units of DAS words of the appropriate type: */


/*     Default page base addresses: */


/*     End Include Section:  EK Das Paging Parameters */

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


/*     Include Section:  EK Tree Parameters */

/*        ektree.inc  Version 3    22-OCT-1995 (NJB) */


/*     The parameters in this file define the tree structure */
/*     used by the EK system.  This structure is a variant of the */
/*     B*-tree structure described in Knuth's book, that is */

/*         Knuth, Donald E.  "The Art of Computer Programming, */
/*         Volume 3/Sorting and Searching" 1973, pp 471-479. */

/*     The trees used in the EK system differ from generic B*-trees */
/*     primarily in the way keys are treated.  Rather than storing */
/*     unique primary key values in each node, EK trees store integer */
/*     counts that represent the ordinal position of each data value, */
/*     counting from the lowest indexed element in the subtree whose */
/*     root is the node in question.  Thus the keys are unique within */
/*     a node but not across multiple nodes:  in fact the Nth key in */
/*     every leaf node is N.  The absolute ordinal position of a data */
/*     item is defined recursively as the sum of the key of the data item */
/*     and the absolute ordinal position of the data item in the parent */
/*     node that immediately precedes all elements of the node in */
/*     question.  This data structure allows EK trees to support lookup */
/*     of data items based on their ordinal position in a data set.  The */
/*     two prime applications of this capability in the EK system are: */

/*        1) Using trees to index the records in a table, allowing */
/*           the Nth record to be located efficiently. */

/*        2) Using trees to implement order vectors that can be */
/*           maintained when insertions and deletions are done. */



/*                           Root node */

/*        +--------------------------------------------+ */
/*        |              Tree version code             | */
/*        +--------------------------------------------+ */
/*        |           Number of nodes in tree          | */
/*        +--------------------------------------------+ */
/*        |            Number of keys in tree          | */
/*        +--------------------------------------------+ */
/*        |                Depth of tree               | */
/*        +--------------------------------------------+ */
/*        |            Number of keys in root          | */
/*        +--------------------------------------------+ */
/*        |              Space for n keys,             | */
/*        |                                            | */
/*        |        n = 2 * INT( ( 2*m - 2 )/3 )        | */
/*        |                                            | */
/*        |  where m is the max number of children per | */
/*        |          node in the child nodes           | */
/*        +--------------------------------------------+ */
/*        |        Space for n+1 child pointers,       | */
/*        |         where n is as defined above.       | */
/*        +--------------------------------------------+ */
/*        |          Space for n data pointers,        | */
/*        |         where n is as defined above.       | */
/*        +--------------------------------------------+ */


/*                           Child node */

/*        +--------------------------------------------+ */
/*        |        Number of keys present in node      | */
/*        +--------------------------------------------+ */
/*        |              Space for m-1 keys            | */
/*        +--------------------------------------------+ */
/*        |         Space for m child pointers         | */
/*        +--------------------------------------------+ */
/*        |         Space for m-1 data pointers        | */
/*        +--------------------------------------------+ */




/*     The following parameters give the maximum number of children */
/*     allowed in the root and child nodes.  During insertions, the */
/*     number of children may overflow by 1. */


/*     Maximum number of children allowed in a child node: */


/*     Maximum number of keys allowed in a child node: */


/*     Minimum number of children allowed in a child node: */


/*     Minimum number of keys allowed in a child node: */


/*     Maximum number of children allowed in the root node: */


/*     Maximum number of keys allowed in the root node: */


/*     Minimum number of children allowed in the root node: */



/*     The following parameters indicate positions of elements in the */
/*     tree node structures shown above. */


/*     The following parameters are for the root node only: */


/*     Location of version code: */


/*     Version code: */


/*     Location of node count: */


/*     Location of total key count for the tree: */


/*     Location of tree depth: */


/*     Location of count of keys in root node: */


/*     Base address of keys in the root node: */


/*     Base address of child pointers in root node: */


/*     Base address of data pointers in the root node (allow room for */
/*     overflow): */


/*     Size of root node: */


/*     The following parameters are for child nodes only: */


/*     Location of number of keys in node: */


/*     Base address of keys in child nodes: */


/*     Base address of child pointers in child nodes: */


/*     Base address of data pointers in child nodes (allow room */
/*     for overflow): */


/*     Size of child node: */


/*     A number of EK tree routines must declare stacks of fixed */
/*     depth; this depth limit imposes a limit on the maximum depth */
/*     that an EK tree can have.  Because of the large branching */
/*     factor of EK trees, the depth limit is of no practical */
/*     importance:  The number of keys that can be held in an EK */
/*     tree of depth N is */

/*                           N-1 */
/*                     MXKIDC   -  1 */
/*         MXKIDR  *   ------------- */
/*                      MXKIDC  - 1 */


/*     This formula yields a capacity of over 1 billion keys for a */
/*     tree of depth 6. */


/*     End Include Section:  EK Tree Parameters */

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
/*     HANDLE     I   File handle. */
/*     TREE       I   Root of tree. */
/*     KEY        I   Key corresponding to value. */
/*     IDX        O   Node-relative index of KEY. */
/*     NODE       O   Node containing key. */
/*     NOFFST     O   Offset of NODE. */
/*     LEVEL      O   Level of NODE. */
/*     VALUE      O   Value associated with KEY. */

/* $ Detailed_Input */

/*     HANDLE         is a file handle of an EK open for write access. */

/*     TREE           is the root node number of the tree of interest. */

/*     KEY            is an absolute key.  In EK trees, absolute keys are */
/*                    just ordinal positions relative to the leftmost */
/*                    element of the tree, with the leftmost element */
/*                    having position 1.  So setting KEY to 10, for */
/*                    example, indicates that the output VALUE is the */
/*                    10th item in the tree. */

/*                    KEY must be in the range 1 : NKEYS, where */
/*                    NKEYS is the number of keys in the tree. */

/* $ Detailed_Output */

/*     IDX            is the node-relative index of KEY:  this is the */
/*                    ordinal position of KEY relative to other keys */
/*                    in the same node. */

/*     NODE           is the number of the node containing KEY. */

/*     NOFFST         is the offset of NODE.  This is the count of the */
/*                    keys that precede every key in the subtree headed */
/*                    by NODE.  Adding NOFFST to any relative key stored */
/*                    in NODE will convert that key to an absolute key. */

/*     LEVEL          is the level of NODE in the tree.  The root is at */
/*                    level 1, children of the root are at level 2, and */
/*                    so on. */

/*     VALUE          is the integer value associated with the input key. */
/*                    Normally, this value is a data pointer. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If HANDLE is invalid, the error will be diagnosed by routines */
/*         called by this routine.  The file will not be modified. */

/*     2)  If an I/O error occurs while reading or writing the indicated */
/*         file, the error will be diagnosed by routines called by this */
/*         routine. */

/*     3)  If the input key is out of range, the error */
/*         SPICE(INDEXOUTOFRANGE) is signaled. */


/*     4)  If the tree traversal fails to terminate at the leaf node */
/*         level, the error SPICE(BUG) is signaled. */

/*     5)  If the key is in range, but the key is not found, the error */
/*         SPICE(BUG) is signaled. */

/* $ Files */

/*     See the EK Required Reading for a discussion of the EK file */
/*     format. */

/* $ Particulars */

/*     This routine obtains the value associated with a key, and also */
/*     returns metadata describing the node containing the key and the */
/*     key's position in the node. */

/* $ Examples */

/*     See ZZEKTRUI. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     1)  Knuth, Donald E.  "The Art of Computer Programming, Volume */
/*         3/Sorting and Searching" 1973, pp 471-479. */

/*         EK trees are closely related to the B* trees described by */
/*         Knuth. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.1.0, 09-FEB-2015 (NJB) */

/*        Now uses ERRHAN to insert DAS file name into */
/*        long error messages. */

/*        Added initializers for variables used to save old */
/*        values. */

/* -    Beta Version 1.0.0, 26-OCT-1995 (NJB) */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     Saved variables */


/*     Initial values */


/*     Use discovery check-in in this puppy. */

/*     Nothing found to begin with. */

    __state->found = FALSE_;
    if (__state->first) {

/*        Find out the access method for the current file. */

	dasham_(handle, __state->access, (ftnlen)15);
	__state->rdonly = s_cmp(__state->access, "READ", (ftnlen)15, (ftnlen)
		4) == 0;
	__state->samkey = FALSE_;
	__state->samtre = FALSE_;
	__state->leaf = FALSE_;
	__state->first = FALSE_;
    } else {

/*        See whether we're looking at the same key, or at least */
/*        the same tree, as last time.  Note that for the tree to */
/*        be guaranteed to be the same, it must belong to a file open */
/*        for read access only. */

	if (*handle != __state->oldhan) {
	    dasham_(handle, __state->access, (ftnlen)15);
	    __state->rdonly = s_cmp(__state->access, "READ", (ftnlen)15, (
		    ftnlen)4) == 0;
	    __state->samtre = FALSE_;
	    __state->samkey = FALSE_;
	} else {
	    __state->samtre = *tree == __state->oldtre && __state->rdonly;
	    __state->samkey = *key == __state->oldkey && __state->samtre;
	}
    }

/*     If we're lucky enough to be getting a request for the previously */
/*     returned key, we're set.  If we've been asked for a key that is */
/*     very close to the previously requested key, we still may make */
/*     out pretty well. */

    if (__state->samkey) {

/*        It's the same key as last time. */

	*idx = __state->oldidx;
	*node = __state->oldnod;
	*noffst = __state->oldnof;
	*level = __state->oldlvl;
	*value = __state->oldval;
	return 0;
    } else if (__state->samtre && __state->leaf) {

/*        Compute the margins around the old key.  Keys that fall within */
/*        the interval defined by the old key and these margins are on */
/*        the same page as the old key. */

	__state->plus = __state->oldmax - __state->oldidx;
	__state->minus = __state->oldidx - 1;
	if (*key <= __state->oldkey + __state->plus && *key >= 
		__state->oldkey - __state->minus) {

/*           The requested key lies on the same page as the old key. */

	    *level = __state->oldlvl;
	    if (*level == 1) {
		__state->datbas = 172;
	    } else {
		__state->datbas = 128;
	    }
	    *idx = __state->oldidx + (*key - __state->oldkey);
	    *node = __state->oldnod;
	    *noffst = __state->oldnof;
	    *value = __state->page[(i__1 = __state->datbas + *idx - 1) < 256 
		    && 0 <= i__1 ? i__1 : s_rnge("page", i__1, "zzektrlk_", (
		    ftnlen)332)];
	    __state->oldidx = *idx;
	    __state->oldkey = *key;
	    __state->oldval = *value;
	    return 0;
	}
    }

/*     If we arrived here, we have some actual work to do. */
/*     Start out by looking at the root page.  Save the tree depth; */
/*     we'll use this for error checking. */

    zzekpgri_(handle, tree, __state->page);
    __state->depth = __state->page[3];
    *level = 1;

/*     Find out how many keys are in the tree.  If KEY is outside */
/*     this range, we won't find it. */

    __state->totkey = __state->page[2];
    if (*key < 1 || *key > __state->totkey) {
	chkin_("ZZEKTRLK", (ftnlen)8);
	setmsg_("Key = #; valid range = 1:#. Tree = #, file = #", (ftnlen)46);
	errint_("#", key, (ftnlen)1);
	errint_("#", &__state->totkey, (ftnlen)1);
	errint_("#", tree, (ftnlen)1);
	errhan_("#", handle, (ftnlen)1);
	sigerr_("SPICE(INDEXOUTOFRANGE)", (ftnlen)22);
	chkout_("ZZEKTRLK", (ftnlen)8);
	return 0;
    }

/*     Find the last key at this level that is less than or equal to */
/*     the requested key. */

    __state->prev = lstlei_(key, &__state->page[4], &__state->page[5]);
    if (__state->prev > 0) {
	__state->prvkey = __state->page[(i__1 = __state->prev + 4) < 256 && 0 
		<= i__1 ? i__1 : s_rnge("page", i__1, "zzektrlk_", (ftnlen)
		381)];
    } else {
	__state->prvkey = 0;
    }

/*     If we were lucky enough to get an exact match, set our outputs */
/*     and return.  The key offset in the root is zero. */

    if (__state->prvkey == *key) {
	*noffst = 0;
	*idx = __state->prev;
	*node = *tree;
	*value = __state->page[(i__1 = *idx + 171) < 256 && 0 <= i__1 ? i__1 :
		 s_rnge("page", i__1, "zzektrlk_", (ftnlen)395)];
	__state->oldhan = *handle;
	__state->oldtre = *tree;
	__state->oldkey = *key;
	__state->oldnof = *noffst;
	__state->oldnod = *node;
	__state->oldidx = *idx;
	__state->oldlvl = *level;
	__state->oldval = *value;
	__state->oldmax = __state->page[4];
	__state->leaf = *level == __state->depth;

/*        The root has no parent or siblings, so these values */
/*        remain set to zero.  The same is true of the parent keys. */

	return 0;
    }

/*     Still here?  Traverse the pointer path until we find the key */
/*     or run out of progeny. */

    __state->child = __state->page[(i__1 = __state->prev + 88) < 256 && 0 <= 
	    i__1 ? i__1 : s_rnge("page", i__1, "zzektrlk_", (ftnlen)421)];
    *noffst = __state->prvkey;
    while(__state->child > 0 && ! __state->found) {

/*        Look up the child node. */

	zzekpgri_(handle, &__state->child, __state->page);
	++(*level);
	if (*level > __state->depth) {
	    chkin_("ZZEKTRLK", (ftnlen)8);
	    setmsg_("Runaway node pointer chain.  Key = #; valid range = 1:#"
		    ". Tree = #, file = #", (ftnlen)75);
	    errint_("#", key, (ftnlen)1);
	    errint_("#", &__state->totkey, (ftnlen)1);
	    errint_("#", tree, (ftnlen)1);
	    errhan_("#", handle, (ftnlen)1);
	    sigerr_("SPICE(BUG)", (ftnlen)10);
	    chkout_("ZZEKTRLK", (ftnlen)8);
	    return 0;
	}

/*        Find the last key at this level that is less than or equal to */
/*        the requested key.  Since the keys we're looking at now are */
/*        ordinal positions relative to the subtree whose root is the */
/*        current node, we must subtract from KEY the position of the */
/*        node preceding the first key of this subtree. */

	__state->newkey = *key - *noffst;
	__state->prev = lstlei_(&__state->newkey, __state->page, &
		__state->page[1]);
	if (__state->prev > 0) {
	    __state->prvkey = __state->page[(i__1 = __state->prev) < 256 && 0 
		    <= i__1 ? i__1 : s_rnge("page", i__1, "zzektrlk_", (
		    ftnlen)460)];
	} else {
	    __state->prvkey = 0;
	}

/*        If we were lucky enough to get an exact match, set our outputs */
/*        and return.  The key offset for the current node is stored */
/*        in NOFFST. */

	if (__state->prvkey == __state->newkey) {
	    __state->found = TRUE_;
	    *idx = __state->prev;
	    *node = __state->child;
	    *value = __state->page[(i__1 = *idx + 127) < 256 && 0 <= i__1 ? 
		    i__1 : s_rnge("page", i__1, "zzektrlk_", (ftnlen)475)];
	    __state->oldhan = *handle;
	    __state->oldtre = *tree;
	    __state->oldkey = *key;
	    __state->oldnof = *noffst;
	    __state->oldnod = *node;
	    __state->oldidx = *idx;
	    __state->oldlvl = *level;
	    __state->oldval = *value;
	    __state->oldmax = __state->page[0];
	    __state->leaf = *level == __state->depth;
	} else {
	    __state->child = __state->page[(i__1 = __state->prev + 64) < 256 
		    && 0 <= i__1 ? i__1 : s_rnge("page", i__1, "zzektrlk_", (
		    ftnlen)491)];
	    *noffst = __state->prvkey + *noffst;
	}
    }

/*     If we found the key, our outputs are already set.  If not, we've */
/*     got trouble. */

    if (! __state->found) {
	chkin_("ZZEKTRLK", (ftnlen)8);
	setmsg_("Key #; valid range = 1:#. Tree = #, file = #.  Key was not "
		"found.  This probably indicates a corrupted file or a bug in"
		" the EK code.", (ftnlen)132);
	errint_("#", key, (ftnlen)1);
	errint_("#", &__state->totkey, (ftnlen)1);
	errint_("#", tree, (ftnlen)1);
	errhan_("#", handle, (ftnlen)1);
	sigerr_("SPICE(BUG)", (ftnlen)10);
	chkout_("ZZEKTRLK", (ftnlen)8);
	return 0;
    }
    return 0;
} /* zzektrlk_ */

