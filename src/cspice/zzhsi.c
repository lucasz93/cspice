/* zzhsi.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


extern zzhsi_init_t __zzhsi_init;
static inline zzhsi_state_t* get_zzhsi_state(cspice_t* state) {
	if (!state->zzhsi)
		state->zzhsi = __cspice_allocate_module(sizeof(zzhsi_state_t),
	 &__zzhsi_init, sizeof(__zzhsi_init));
	return state->zzhsi;

}

/* $Procedure ZZHSI ( Private---Add-only Integer Hash ) */
/* Subroutine */ int zzhsi_0_(cspice_t* __global_state, int n__, integer *
	hashsz, integer *hedlst, integer *collst, integer *items, integer *
	item, char *param, integer *itemat, logical *new__, integer *avail, 
	ftnlen param_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer node;
    logical full;
    integer i__;
    extern /* Subroutine */ int chkin_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errch_(cspice_t*, char *, char *, ftnlen, 
	    ftnlen);
    extern logical failed_(cspice_t*);
    logical lfound;
    integer lookat;
    extern /* Subroutine */ int sigerr_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int chkout_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int setmsg_(cspice_t*, char *, ftnlen);
    extern /* Subroutine */ int errint_(cspice_t*, char *, integer *, ftnlen);
    extern logical return_(cspice_t*);
    extern integer zzhashi_(cspice_t*, integer *, integer *);


    /* Module state */
    zzhsi_state_t* __state = get_zzhsi_state(__global_state);
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Manipulate add-only integer hash. */

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

/*     PRIVATE UTILITY */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Entry */
/*     --------  ---  -------------------------------------------------- */
/*     HASHSZ     I   ZZHSIINI */
/*     HEDLST    I/O  ZZHSIINI, ZZHSIADD, ZZHSICHK, ZZHSIINF */
/*     COLLST    I/O  ZZHSIINI, ZZHSIADD, ZZHSICHK, ZZHSIAVL, ZZHSIINF */
/*     ITEMS     I/O  ZZHSIINI, ZZHSIADD, ZZHSICHK, ZZHSIINF */
/*     ITEM       I   ZZHSIADD, ZZHSICHK */
/*     PARAM      I   ZZHSIINF */
/*     ITEMAT     O   ZZHSIADD, ZZHSICHK */
/*     NEW        O   ZZHSIADD */
/*     AVAIL      O   ZZHSIAVL, ZZHSIINF */

/*     LBPOOL     P   (All) */

/* $ Detailed_Input */

/*     See the ENTRY points for a discussion of their arguments. */

/* $ Detailed_Output */

/*     See the ENTRY points for a discussion of their arguments. */

/* $ Parameters */

/*     LBPOOL      is the lower bound of the collision list array. */

/* $ Exceptions */

/*     1) If ZZHSI is called directly, the error SPICE(BOGUSENTRY) is */
/*        signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     ZZHSI should never be called directly, but should instead be */
/*     accessed only through its entry points. */

/*     The purpose of this routine is to manipulate add-only integer */
/*     hashes used for buffering purposes by various SPICE subsystems. */
/*     This umbrella has the following entry points: */

/*           ZZHSIINI       Initialize a hash. */

/*           ZZHSIADD       Add an item to a hash. */

/*           ZZHSICHK       Check if a item is in a hash. */

/*           ZZHSIAVL       Get available room in hash. */

/*           ZZHSIINF       Get h/k information about hash. */

/*     An add-only hash consists of the head node pointer list (HEDLST), */
/*     hash node collision list (COLLST), and the item list (ITEMS). */

/*     The function ZZHASH2 computes the index of an element in the head */
/*     node pointer list (HEDLST). */

/*     The HEDLST element at this index contains either 0, indicating */
/*     that there is not yet data for this hash value in the hash, or */
/*     the index of the head node and its item in the hash collision */
/*     (COLLST) and item (ITEMS) lists. */

/*     The COLLST element at the head node index contain either 0, */
/*     indicating that there is only one item for this hash value in the */
/*     hash, or the index of the next node and its item in the hash */
/*     collision (COLLST) and item (ITEMS) lists. */

/*     The COLLST element at the next node index contain either 0, */
/*     indicating that this is the last item for this hash value in the */
/*     hash, or the index of the next node and its item in the hash */
/*     collision (COLLST) and item (ITEMS) lists. */

/*     And so on. */

/*     Pictorially the hash looks like this: */

/*                     List of head   List of hash      List of */
/*                        nodes        collisions        items */

/*                       HEDLST          COLLST          ITEMS */

/*                                     +---------+ */
/*                                     |         | */
/*                                     +---------+ */
/*                                         ... */
/*                                     +---------+ */
/*                                     | 1st Free| */
/*                                     +---------+ */
/*                                     |  Size   | */
/*                     +---------+     +---------+     +---------+ */
/*                     |         |     |         |     |         | */
/*                     +---------+ !=0 +---------+     +---------+ */
/*                  .->|Head Node| -.  |         |     |         | */
/*                  |  +---------+  |  +---------+     +---------+ */
/*       ZZHASHI(ITEM) |         |  |  |         |     |         | */
/*                     +---------+  |  +---------+     +---------+ */
/*                     |         |  `->|Head of  |     |Item     | */
/*                     |         |     |collision| !=0 |corresp. | */
/*                     |         |     |list for | -.  |to head  | */
/*                     |         |     | ITEM    |  |  |of list  | */
/*                     +---------+     +---------+  |  +---------+ */
/*                     |         |     |         |  |  |         | */
/*                     +---------+     +---------+  |  +---------+ */
/*                     |         |     |         |<-'  |         | */
/*                     |         |     |Next Node| !=0 |Next Item| */
/*                     |         |     |         |--.  |         | */
/*                     +---------+     +---------+  |  +---------+ */
/*                     |         |     |         |  |  |         | */
/*                     +---------+     +---------+  |  +---------+ */
/*                     |         |     |         |  |  |         | */
/*                     +---------+     +---------+  |  +---------+ */
/*                     |         |     |Next Node|<-'  |Next Item| */
/*                     +---------+     +---------+ etc +---------+ */
/*                        ...              ...            ... */
/*                     +---------+     +---------+     +---------+ */
/*                     |         |     |         |     |         | */
/*                     +---------+     +---------+     +---------+ */


/* $ Examples */

/*     An add-only hash used together with flat data arrays provides a */
/*     simple, fast-access buffering mechanism. The subsystems that need */
/*     such buffering would normally initialize the hash, add items to */
/*     the hash and buffer data associated with items in flat data */
/*     arrays, and find items in the hash and, if found, use buffered */
/*     data associated with the items rather than computing/getting */
/*     their data again. */

/*     An add-only hash is normally used in one of the following ways -- */
/*     set up to never be filled up, stop buffering when filled up, and */
/*     trash when filled up and start buffering again. Three examples */
/*     below illustrate each of these ways. */

/*     Example 1: Set up to never be filled up */
/*     --------------------------------------- */

/*     C */
/*     C     Parameters: list lower boundary, hash size and item */
/*     C     size. */
/*     C */
/*           INTEGER               LBPOOL */
/*           PARAMETER           ( LBPOOL = -5 ) */

/*           INTEGER               HSHSIZ */
/*           PARAMETER           ( HSHSIS = 5003 ) */

/*           INTEGER               NAMSIZ */
/*           PARAMETER           ( NAMSIZ = 32 ) */

/*     C */
/*     C     Hash arrays and data buffer. */
/*     C */
/*           INTEGER               HEDLST  (          HSHSIZ ) */
/*           INTEGER               COLLST  ( LBPOOL : HSHSIZ ) */
/*           INTEGER               ITEMS   (          HSHSIZ ) */
/*           INTEGER               DATBUF  (          HSHSIZ ) */

/*     C */
/*     C     Miscellaneous variables. */
/*     C */
/*           INTEGER               ITEM */

/*           INTEGER               ITEMAT */
/*           INTEGER               MYDATA */

/*           LOGICAL               FIRST */
/*           INTEGER               AVAIL */
/*           LOGICAL               NEW */

/*     C */
/*     C     Data items. */
/*     C */
/*           DATA FIRST             / .TRUE.  / */

/*     C */
/*     C     Initialize hash. */
/*     C */
/*           IF ( FIRST ) THEN */
/*              CALL ZZHSIINI ( HSHSIZ, HEDLST, COLLST ) */
/*              FIRST = .FALSE. */
/*           END IF */
/*           ... */
/*     C */
/*     C     Check for presence of or add an item to the hash. If the */
/*     C     item is in the hash, NEW will be .FALSE. If the item is */
/*     C     not in the hash, it will be added and NEW will be .TRUE. */
/*     C     This call can fail only if the hash fills up which */
/*     C     should not happen because it was declared to never fill */
/*     C     up. */
/*     C */
/*           CALL ZZHSIADD ( HEDLST, COLLST, ITEMS, ITEM, */
/*          .                                ITEMAT, NEW ) */
/*           IF ( FAILED() ) THEN */
/*              RETURN */
/*           END IF */

/*           IF ( .NOT. NEW ) THEN */
/*     C */
/*     C        Simply use buffered value. */
/*     C */
/*              MYDATA = DATBUF( ITEMAT ) */

/*           ELSE */
/*     C */
/*     C        Get value. */
/*     C */
/*              ... */
/*     C */
/*     C        Buffer value. */
/*     C */
/*              DATBUF( ITEMAT ) = MYDATA */

/*           END IF */



/*     Example 2: Stop buffering when filled up */
/*     ---------------------------------------- */

/*     C */
/*     C     Use the same declarations as the first example. */
/*     C */
/*           ... */
/*     C */
/*     C     Initialize hash. */
/*     C */
/*           IF ( FIRST ) THEN */
/*              CALL ZZHSIINI ( HSHSIZ, HEDLST, COLLST ) */
/*              FIRST = .FALSE. */
/*           END IF */
/*           ... */
/*     C */
/*     C     Check if this item is in the hash. */
/*     C */
/*           CALL ZZHSICHK ( HEDLST, COLLST, ITEMS, ITEM, ITEMAT ) */

/*           IF ( ITEMAT .NE. 0 ) THEN */
/*     C */
/*     C        Simply use buffered value. */
/*     C */
/*              MYDATA = DATBUF( ITEMAT ) */

/*           ELSE */
/*     C */
/*     C        Get value. */
/*     C */
/*              ... */
/*     C */
/*     C        Buffer value, but only if the hash is not full. */
/*     C */
/*              CALL ZZHSIAVL( COLLST, AVAIL ) */
/*              IF ( AVAIL .GT. 0 ) THEN */
/*                 CALL ZZHSIADD ( HEDLST, COLLST, ITEMS, ITEM, */
/*          .                                  ITEMAT, NEW ) */
/*                 DATBUF( ITEMAT ) = MYDATA */
/*              END IF */

/*           END IF */


/*     Example 3: Trash when filled up and start buffering again */
/*     --------------------------------------------------------- */

/*     C */
/*     C     Use the same declarations as the first example. */
/*     C */
/*           ... */
/*     C */
/*     C     Initialize hash. */
/*     C */
/*           IF ( FIRST ) THEN */
/*              CALL ZZHSIINI ( HSHSIZ, HEDLST, COLLST ) */
/*              FIRST = .FALSE. */
/*           END IF */
/*           ... */
/*     C */
/*     C     Check if this item is in the hash. */
/*     C */
/*           CALL ZZHSICHK ( HEDLST, COLLST, ITEMS, ITEM, ITEMAT ) */

/*           IF ( ITEMAT .NE. 0 ) THEN */
/*     C */
/*     C        Simply use buffered value. */
/*     C */
/*              MYDATA = DATBUF( ITEMAT ) */

/*           ELSE */
/*     C */
/*     C        Get value. */
/*     C */
/*              ... */
/*     C */
/*     C        Buffer value, if the hash is full trash re-initialize */
/*     C        it first. */
/*     C */
/*              CALL ZZHSIAVL( COLLST, AVAIL ) */
/*              IF ( AVAIL .LE. 0 ) THEN */
/*                 CALL ZZHSIINI ( HSHSIZ, HEDLST, COLLST ) */
/*              END IF */
/*              CALL ZZHSIADD ( HEDLST, COLLST, ITEMS, ITEM, */
/*          .                                  ITEMAT, NEW ) */
/*              DATBUF( ITEMAT ) = MYDATA */

/*           END IF */

/* $ Restrictions */

/*     For sake of speed all entry points do no or minimal error */
/*     checking. It is the responsibility of the caller to ensure that */
/*     all inputs are properly initialized. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     B.V. Semenov    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 01-AUG-2013 (BVS) */

/* -& */
/* $ Index_Entries */

/*     manipulate add-only integer hash */

/* -& */

/*     Hash control area items. */


/*     SPICELIB functions. */


/*     Local variables. */


/*     Standard SPICE error handling. */

    /* Parameter adjustments */
    if (hedlst) {
	}
    if (items) {
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_zzhsiini;
	case 2: goto L_zzhsiadd;
	case 3: goto L_zzhsichk;
	case 4: goto L_zzhsiavl;
	case 5: goto L_zzhsiinf;
	}

    if (return_(__global_state)) {
	return 0;
    } else {
	chkin_(__global_state, "ZZHSI", (ftnlen)5);
    }

/*     Signal bogus entry error and check out. */

    sigerr_(__global_state, "BOGUSENTRY", (ftnlen)10);
    chkout_(__global_state, "ZZHSI", (ftnlen)5);
    return 0;
/* $Procedure ZZHSIINI ( Private---Initialize Add-only Integer Hash ) */

L_zzhsiini:
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Initialize an add-only integer hash. */

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

/*     PRIVATE UTILITY */

/* $ Declarations */

/*     INTEGER               LBPOOL */
/*     PARAMETER           ( LBPOOL = -5 ) */

/*     INTEGER               HASHSZ */
/*     INTEGER               HEDLST  (          * ) */
/*     INTEGER               COLLST  ( LBPOOL : * ) */

/* $ Brief_I/O */

/*     Variable  I/O  Entry */
/*     --------  ---  -------------------------------------------------- */
/*     HASHSZ     I   Hash size */
/*     HEDLST    I/O  Hash head node pointer list */
/*     COLLST    I/O  Hash node collision list */

/*     LBPOOL     P   Collision list array lower bound */

/* $ Detailed_Input */

/*     HASHSZ      is the hash size. For efficiency reasons it must be a */
/*                 positive prime number. */

/*     HEDLST */
/*     COLLST      are the head node pointer list and the node collision */
/*                 list components of an add-only integer hash. */

/* $ Detailed_Output */

/*     HEDLST */
/*     COLLST      are the head node pointer list and the node collision */
/*                 list components of an add-only integer hash with all */
/*                 elements of the head node pointer list HEDLST set to */
/*                 zero and size and first-free elements of the head */
/*                 node pointer list COLLST set to HASHSZ and 1 */
/*                 correspondingly. */

/* $ Parameters */

/*     LBPOOL      is the lower bound of the collision list array. */

/* $ Exceptions */

/*     1) If HASHSZ is less than 1, the error SPICE(INVALIDCOUNT) is */
/*        signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     See the header of the umbrella routine ZZHSI. */

/* $ Examples */

/*     See the header of the umbrella routine ZZHSI. */

/* $ Restrictions */

/*     See the header of the umbrella routine ZZHSI. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     B.V. Semenov    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 01-AUG-2013 (BVS) */

/* -& */
/* $ Index_Entries */

/*     initialize add-only integer hash */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }
    chkin_(__global_state, "ZZHSIINI", (ftnlen)8);

/*     The requested number of nodes must be valid. ZZHASHI will check */
/*     that. */

    i__ = zzhashi_(__global_state, &__state->c__1, hashsz);
    if (failed_(__global_state)) {
	chkout_(__global_state, "ZZHSIINI", (ftnlen)8);
	return 0;
    }

/*     Wipe out head node pointer list. */

    i__1 = *hashsz;
    for (i__ = 1; i__ <= i__1; ++i__) {
	hedlst[i__ - 1] = 0;
    }

/*     Reset control area. */

    collst[5] = *hashsz;
    collst[4] = 1;
    chkout_(__global_state, "ZZHSIINI", (ftnlen)8);
    return 0;
/* $Procedure ZZHSIADD ( Private---Add an Item to Add-only Integer Hash ) */

L_zzhsiadd:
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Find or add, if not present, an item to an add-only integer */
/*     hash. */

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

/*     PRIVATE UTILITY */

/* $ Declarations */

/*     INTEGER               LBPOOL */
/*     PARAMETER           ( LBPOOL = -5 ) */

/*     INTEGER               HEDLST  (          * ) */
/*     INTEGER               COLLST  ( LBPOOL : * ) */
/*     INTEGER               ITEMS   (          * ) */
/*     INTEGER               ITEM */
/*     INTEGER               ITEMAT */
/*     LOGICAL               NEW */

/* $ Brief_I/O */

/*     Variable  I/O  Entry */
/*     --------  ---  -------------------------------------------------- */
/*     HEDLST    I/O  Hash head node pointer list */
/*     COLLST    I/O  Hash node collision list */
/*     ITEMS     I/O  Hash item list */
/*     ITEM       I   Item to be checked for/added */
/*     ITEMAT     O   Item index in node collision and item lists */
/*     NEW        O   Flag indicting if item was added */

/*     LBPOOL     P   Collision list array lower bound */

/* $ Detailed_Input */

/*     HEDLST */
/*     COLLST */
/*     ITEMS       are the components of an add-only integer */
/*                 hash. */

/*     ITEM        is an item to find and, if needed, add to the hash. */

/* $ Detailed_Output */

/*     HEDLST */
/*     COLLST */
/*     ITEMS       are the components of an add-only integer */
/*                 hash with the new item added to it if needed. */

/*     ITEMAT      is the index of the item in the node collision and */
/*                 item lists. If the item could not be found in or */
/*                 added to the hash, ITEMAT is set to 0. */

/*     NEW         is a flag indicting if item was added to the hash. */

/* $ Parameters */

/*     LBPOOL      is the lower bound of the collision list array. */

/* $ Exceptions */

/*     1) If the hash is full, the error SPICE(HASHISFULL) is signaled. */

/*     2) If the hash size saved in the control area of the collision */
/*        list is less than 1, the error SPICE(UNINITIALIZEDHASH) is */
/*        signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     See the header of the umbrella routine ZZHSI. */

/* $ Examples */

/*     See the header of the umbrella routine ZZHSI. */

/* $ Restrictions */

/*     See the header of the umbrella routine ZZHSI. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     B.V. Semenov    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 01-AUG-2013 (BVS) */

/* -& */
/* $ Index_Entries */

/*     add an item to add-only integer hash */

/* -& */

/*     Standard SPICE error handling. No checking-in here. We will do it */
/*     when we have to. */

    if (return_(__global_state)) {
	return 0;
    }

/*     Set flag indicating whether the hash is full. */

    full = collst[4] > collst[5];

/*     Use simple division hash function to get index of the head node. */

    if (collst[5] < 1) {
	chkin_(__global_state, "ZZHSIADD", (ftnlen)8);
	setmsg_(__global_state, "Uninitialized hash. Size was #.", (ftnlen)31)
		;
	errint_(__global_state, "#", &collst[5], (ftnlen)1);
	sigerr_(__global_state, "SPICE(UNINITIALIZEDHASH)", (ftnlen)24);
	chkout_(__global_state, "ZZHSIADD", (ftnlen)8);
	return 0;
    }
    lookat = zzhashi_(__global_state, item, &collst[5]);
    node = hedlst[lookat - 1];

/*     Set initial values. */

    lfound = FALSE_;
    *new__ = FALSE_;

/*     See if this item (or one colliding with it in the hash scheme) */
/*     has already been stored in the item list. */

    if (node > 0) {

/*        Start at the head node and check each item saved for this hash */
/*        value until we find a item that matches or run out of items in */
/*        this conflict resolution list. */

	while(node > 0 && ! lfound) {
	    lfound = items[node - 1] == *item;
	    *itemat = node;
	    node = collst[node + 5];
	}

/*        If we didn't find this item on the conflict resolution list */
/*        and our hash is not full we will add this item to it. */

	if (! lfound && ! full) {

/*           Get next free node. */

	    node = collst[4];

/*           Increment next free node pointer. */

	    ++collst[4];

/*           Set current node pointer to the node we just picked for */
/*           this item. */

	    collst[*itemat + 5] = node;

/*           Set new node pointer to 0, just in case. */

	    collst[node + 5] = 0;

/*           Save item. */

	    items[node - 1] = *item;

/*           Set output node ID and new and found flags. */

	    *itemat = node;
	    *new__ = TRUE_;
	    lfound = TRUE_;
	}
    } else if (! full) {

/*        Nothing like this item (in the hashing sense) has been stored */
/*        so far and the hash is not full. */

/*        Get next free node. */

	node = collst[4];

/*        Increment next free node pointer. */

	++collst[4];

/*        Set new node pointer to 0, just in case. */

	collst[node + 5] = 0;

/*        Set the head node pointer to this node. */

	hedlst[lookat - 1] = node;

/*        Save item. */

	items[node - 1] = *item;

/*        Set output node ID and new and found flags. */

	*itemat = node;
	*new__ = TRUE_;
	lfound = TRUE_;
    }

/*     Set ITEMAT to 0 if LFOUND is FALSE. */

    if (! lfound) {
	*itemat = 0;
    }

/*     If the item hash was full and we didn't find this item we've got */
/*     an error. Report it and return. */

    if (full && ! lfound) {
	chkin_(__global_state, "ZZHSIADD", (ftnlen)8);
	setmsg_(__global_state, "The hash has no room for any more items.", (
		ftnlen)40);
	sigerr_(__global_state, "SPICE(HASHISFULL)", (ftnlen)17);
	chkout_(__global_state, "ZZHSIADD", (ftnlen)8);
	return 0;
    }
    return 0;
/* $Procedure ZZHSICHK ( Private---Find an Item in Add-only Integer Hash ) */

L_zzhsichk:
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Find an item in an add-only integer hash. */

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

/*     PRIVATE UTILITY */

/* $ Declarations */

/*     INTEGER               LBPOOL */
/*     PARAMETER           ( LBPOOL = -5 ) */

/*     INTEGER               HEDLST  (          * ) */
/*     INTEGER               COLLST  ( LBPOOL : * ) */
/*     INTEGER               ITEMS   (          * ) */
/*     INTEGER               ITEM */
/*     INTEGER               ITEMAT */

/* $ Brief_I/O */

/*     Variable  I/O  Entry */
/*     --------  ---  -------------------------------------------------- */
/*     HEDLST     I   Hash head node pointer list */
/*     COLLST     I   Hash node collision list */
/*     ITEMS      I   Hash item list */
/*     ITEM       I   Item to find */
/*     ITEMAT     O   Item index in node collision and item lists */

/*     LBPOOL     P   Collision list array lower bound */

/* $ Detailed_Input */

/*     HEDLST */
/*     COLLST */
/*     ITEMS       are the components of an add-only integer */
/*                 hash. */

/*     ITEM        is an item to find in the hash. */

/* $ Detailed_Output */

/*     ITEMAT      is the index of the item in the node collision and */
/*                 item lists. If item is not in the hash, ITEMAT is set */
/*                 to 0. */

/* $ Parameters */

/*     LBPOOL      is the lower bound of the collision list array. */

/* $ Exceptions */

/*     1) If the hash size saved in the control area of the collision */
/*        list is less than 1, the error SPICE(UNINITIALIZEDHASH) is */
/*        signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     See the header of the umbrella routine ZZHSI. */

/* $ Examples */

/*     See the header of the umbrella routine ZZHSI. */

/* $ Restrictions */

/*     See the header of the umbrella routine ZZHSI. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     B.V. Semenov    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 01-AUG-2013 (BVS) */

/* -& */
/* $ Index_Entries */

/*     find item in add-only integer hash */

/* -& */

/*     Standard SPICE error handling. */

    if (return_(__global_state)) {
	return 0;
    }

/*     Use simple division hash function to get index of the head node. */

    if (collst[5] < 1) {
	chkin_(__global_state, "ZZHSIADD", (ftnlen)8);
	setmsg_(__global_state, "Uninitialized hash. Size was #.", (ftnlen)31)
		;
	errint_(__global_state, "#", &collst[5], (ftnlen)1);
	sigerr_(__global_state, "SPICE(UNINITIALIZEDHASH)", (ftnlen)24);
	chkout_(__global_state, "ZZHSIADD", (ftnlen)8);
	return 0;
    }
    lookat = zzhashi_(__global_state, item, &collst[5]);
    node = hedlst[lookat - 1];

/*     Set initial values. */

    lfound = FALSE_;

/*     See if this item (or one colliding with it in the hash scheme) is */
/*     in the item list. */

    if (node > 0) {

/*        Start at the head node and check each item saved for this hash */
/*        value until we find a item that matches or run out of items in */
/*        this conflict resolution list. */

	while(node > 0 && ! lfound) {
	    lfound = items[node - 1] == *item;
	    *itemat = node;
	    node = collst[node + 5];
	}
    }

/*     If LFOUND is false, set ITEMAT to 0. */

    if (! lfound) {
	*itemat = 0;
    }
    return 0;
/* $Procedure ZZHSIAVL ( Private---Get room available in Add-only Hash ) */

L_zzhsiavl:
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Get room available in an add-only integer hash. */

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

/*     PRIVATE UTILITY */

/* $ Declarations */

/*     INTEGER               LBPOOL */
/*     PARAMETER           ( LBPOOL = -5 ) */

/*     INTEGER               COLLST  ( LBPOOL : * ) */
/*     INTEGER               AVAIL */

/* $ Brief_I/O */

/*     Variable  I/O  Entry */
/*     --------  ---  -------------------------------------------------- */
/*     COLLST     I   Hash node collision list */
/*     AVAIL      O   Room available in the hash */

/*     LBPOOL     P   Collision list array lower bound */

/* $ Detailed_Input */

/*     COLLST      is the add-only integer hash node collision */
/*                 list. */

/* $ Detailed_Output */

/*     AVAIL       is the room (number of vacant slots) available in */
/*                 the hash. */

/* $ Parameters */

/*     LBPOOL      is the lower bound of the collision list array. */

/* $ Exceptions */

/*     Error free. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     See the header of the umbrella routine ZZHSI. */

/* $ Examples */

/*     See the header of the umbrella routine ZZHSI. */

/* $ Restrictions */

/*     See the header of the umbrella routine ZZHSI. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     B.V. Semenov    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 01-AUG-2013 (BVS) */

/* -& */
/* $ Index_Entries */

/*     get room available in add-only integer hash */

/* -& */

/*     Set the number of unoccupied slots in the hash. */

    *avail = collst[5] - collst[4] + 1;
    return 0;
/* $Procedure ZZHSIINF ( Private---Get Information about Add-only Hash ) */

L_zzhsiinf:
/* $ Abstract */

/*     SPICE Private routine intended solely for the support of SPICE */
/*     routines. Users should not call this routine directly due */
/*     to the volatile nature of this routine. */

/*     Get information about an add-only integer hash. */

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

/*     PRIVATE UTILITY */

/* $ Declarations */

/*     INTEGER               LBPOOL */
/*     PARAMETER           ( LBPOOL = -5 ) */

/*     INTEGER               HEDLST  (          * ) */
/*     INTEGER               COLLST  ( LBPOOL : * ) */
/*     INTEGER               ITEMS   (          * ) */
/*     CHARACTER*(*)         PARAM */
/*     INTEGER               AVAIL */

/* $ Brief_I/O */

/*     Variable  I/O  Entry */
/*     --------  ---  -------------------------------------------------- */
/*     HEDLST     I   Hash head node pointer list */
/*     COLLST     I   Hash node collision list */
/*     ITEMS      I   Hash item list */
/*     ITEM       I   parameter to report */
/*     AVAIL      O   parameter Value */

/*     LBPOOL     P   Collision list array lower bound */

/* $ Detailed_Input */

/*     HEDLST */
/*     COLLST */
/*     ITEMS       are the components of an add-only integer */
/*                 hash. */

/*     ITEM        is the parameter to report: */

/*                    'HASH SIZE' */
/*                    'USED HEADNODE COUNT' */
/*                    'UNUSED HEADNODE COUNT' */
/*                    'USED ITEM COUNT' */
/*                    'UNUSED ITEM COUNT' */
/*                    'LONGEST LIST SIZE' */

/* $ Detailed_Output */

/*     AVAIL       is the value of the parameter of interest. */

/* $ Parameters */

/*     LBPOOL      is the lower bound of the collision list array. */

/* $ Exceptions */

/*     1) If the input ITEM is not recognized, the error */
/*        SPICE(ITEMNOTRECOGNIZED) is signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     See the header of the umbrella routine ZZHSC. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     See the header of the umbrella routine ZZHSC. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     B.V. Semenov    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 31-JUL-2013 (BVS) */

/* -& */
/* $ Index_Entries */

/*     get information about add-only integer hash */

/* -& */

/*     Get the hash size. */

    if (s_cmp(&__global_state->f2c, param, "HASH SIZE", param_len, (ftnlen)9) 
	    == 0) {
	*avail = collst[5];

/*     Get the count of used nodes in the head list. */

    } else if (s_cmp(&__global_state->f2c, param, "USED HEADNODE COUNT", 
	    param_len, (ftnlen)19) == 0) {
	*avail = 0;
	i__1 = collst[5];
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (hedlst[i__ - 1] != 0) {
		++(*avail);
	    }
	}

/*     Get the count of unused nodes in the head list. */

    } else if (s_cmp(&__global_state->f2c, param, "UNUSED HEADNODE COUNT", 
	    param_len, (ftnlen)21) == 0) {
	*avail = 0;
	i__1 = collst[5];
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (hedlst[i__ - 1] == 0) {
		++(*avail);
	    }
	}

/*     Get the count of used slots in the item list. */

    } else if (s_cmp(&__global_state->f2c, param, "USED ITEM COUNT", 
	    param_len, (ftnlen)15) == 0) {
	*avail = collst[4] - 1;

/*     Get the count of unused slots in the item list. */

    } else if (s_cmp(&__global_state->f2c, param, "UNUSED ITEM COUNT", 
	    param_len, (ftnlen)17) == 0) {
	*avail = collst[5] - collst[4] + 1;

/*     Get the size of the longest item list for any hash value. */

    } else if (s_cmp(&__global_state->f2c, param, "LONGEST LIST SIZE", 
	    param_len, (ftnlen)17) == 0) {
	*avail = 0;
	i__1 = collst[5];
	for (i__ = 1; i__ <= i__1; ++i__) {
	    node = hedlst[i__ - 1];
	    lookat = 0;
	    while(node > 0) {
		++lookat;
		node = collst[node + 5];
	    }
	    *avail = max(*avail,lookat);
	}

/*     This parameter is not supported. */

    } else {
	*avail = 0;
	chkin_(__global_state, "ZZHSIINF", (ftnlen)8);
	setmsg_(__global_state, "Parameter '#' is not recognized.", (ftnlen)
		32);
	errch_(__global_state, "#", param, (ftnlen)1, param_len);
	sigerr_(__global_state, "SPICE(ITEMNOTRECOGNIZED)", (ftnlen)24);
	chkout_(__global_state, "ZZHSIINF", (ftnlen)8);
    }
    return 0;
} /* zzhsi_ */

/* Subroutine */ int zzhsi_(cspice_t* __global_state, integer *hashsz, 
	integer *hedlst, integer *collst, integer *items, integer *item, char 
	*param, integer *itemat, logical *new__, integer *avail, ftnlen 
	param_len)
{
    return zzhsi_0_(0, hashsz, hedlst, collst, items, item, param, itemat, 
	    new__, avail, param_len);
    }

/* Subroutine */ int zzhsiini_(cspice_t* __global_state, integer *hashsz, 
	integer *hedlst, integer *collst)
{
    return zzhsi_0_(1, hashsz, hedlst, collst, (integer *)0, (integer *)0, (
	    char *)0, (integer *)0, (logical *)0, (integer *)0, (ftnint)0);
    }

/* Subroutine */ int zzhsiadd_(cspice_t* __global_state, integer *hedlst, 
	integer *collst, integer *items, integer *item, integer *itemat, 
	logical *new__)
{
    return zzhsi_0_(2, (integer *)0, hedlst, collst, items, item, (char *)0, 
	    itemat, new__, (integer *)0, (ftnint)0);
    }

/* Subroutine */ int zzhsichk_(cspice_t* __global_state, integer *hedlst, 
	integer *collst, integer *items, integer *item, integer *itemat)
{
    return zzhsi_0_(3, (integer *)0, hedlst, collst, items, item, (char *)0, 
	    itemat, (logical *)0, (integer *)0, (ftnint)0);
    }

/* Subroutine */ int zzhsiavl_(cspice_t* __global_state, integer *collst, 
	integer *avail)
{
    return zzhsi_0_(4, (integer *)0, (integer *)0, collst, (integer *)0, (
	    integer *)0, (char *)0, (integer *)0, (logical *)0, avail, (
	    ftnint)0);
    }

/* Subroutine */ int zzhsiinf_(cspice_t* __global_state, integer *hedlst, 
	integer *collst, integer *items, char *param, integer *avail, ftnlen 
	param_len)
{
    return zzhsi_0_(5, (integer *)0, hedlst, collst, items, (integer *)0, 
	    param, (integer *)0, (logical *)0, avail, param_len);
    }

