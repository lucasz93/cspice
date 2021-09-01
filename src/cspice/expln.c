/* expln.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "__cspice_state.h"


typedef int expln_state_t;
static expln_state_t* get_expln_state(cspice_t* state) {
	return 0;
}

/* $Procedure      EXPLN ( Get Explanation for Short Error Message ) */
/* Subroutine */ int expln_(cspice_t* __global_state, char *msg, char *expl, 
	ftnlen msg_len, ftnlen expl_len)
{
    /* Builtin functions */
    integer s_cmp(f2c_state_t*, char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(f2c_state_t*, char *, char *, ftnlen, ftnlen);


    /* Module state */
    expln_state_t* __state = get_expln_state(__global_state);
/* $ Abstract */

/*      Return the explanation of a short error message. */

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

/*      ERROR */

/* $ Keywords */

/*      ERROR */

/* $ Declarations */
/* $ Brief_I/O */

/*      VARIABLE  I/O  DESCRIPTION */
/*      --------  ---  -------------------------------------------------- */
/*      MSG        I   A short error message. */
/*      EXPL       O   The explanation of the short error message. */

/* $ Detailed_Input */

/*      MSG     A ``short'' error message. */
/*              MSG indicates the type of error that has occurred. */

/*              The exact format that MSG must follow is */
/*              described in the required reading file, error.req. */

/* $ Detailed_Output */

/*      EXPL    is a character string containing an one-line */
/*              explanation of the short error message, MSG. */

/*              If there is no explanatory text corresponding */
/*              to the input string, MSG, EXPL is blank. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */


/*      This routine does not detect any errors. */

/*      However, this routine is part of the interface to the */
/*      SPICELIB error handling mechanism.  For this reason, */
/*      this routine does not participate in the trace scheme, */
/*      even though it has external references. */


/* $ Files */

/*      None. */

/* $ Particulars */

/*      None. */

/* $ Examples */


/*      C */
/*      C     We want to find the explanation corresponding to */
/*      C     the short message, 'SPICE(ZERORADIUS)' : */
/*      C */

/*             CALL EXPLN ( 'SPICE(ZERORADIUS)', EXPL ) */


/*      Now, EXPL  = */

/*      'Invalid Radius--Equatorial or Polar Radius is Zero' */


/* $ Restrictions */

/*      None. */

/* $ Literature_References */

/*      None. */

/* $ Author_and_Institution */

/*      N.J. Bachman    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.2, 18-APR-2014 (BVS) */

/*        Minor header edits. */

/* -    SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*        Comment section for permuted index source lines was added */
/*        following the header. */

/* -    SPICELIB Version 1.0.0, 31-JAN-1990 (NJB) */

/* -& */
/* $ Index_Entries */

/*     get explanation for short error message */

/* -& */
/* $ Revisions */

/* -    Beta Version 1.1.0, 27-OCT-1988 (NJB) */

/*        Removed code used to create upper case, left-justified */
/*        copy of the short error message.  The resulting message */
/*        was not used. */

/* -& */

/*     Executable Code: */


/*     Note: the short error messages should be ordered */
/*     alphabetically. */

    if (s_cmp(&__global_state->f2c, msg, "SPICE(BADENDPOINTS)", msg_len, (
	    ftnlen)19) == 0) {
	s_copy(&__global_state->f2c, expl, "Invalid Endpoints--Left Endpoint"
		" Exceeds Right Endpoint", expl_len, (ftnlen)55);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(BADGEFVERSION)", 
	    msg_len, (ftnlen)20) == 0) {
	s_copy(&__global_state->f2c, expl, "Version Identification of GEF Fi"
		"le is Invalid", expl_len, (ftnlen)45);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(BLANKMODULENAME)", 
	    msg_len, (ftnlen)22) == 0) {
	s_copy(&__global_state->f2c, expl, "A blank string was used as a mod"
		"ule name", expl_len, (ftnlen)40);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(BOGUSENTRY)", msg_len, 
	    (ftnlen)17) == 0) {
	s_copy(&__global_state->f2c, expl, "This Entry Point Contains No Exe"
		"cutable Code", expl_len, (ftnlen)44);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(CELLTOOSMALL)", 
	    msg_len, (ftnlen)19) == 0) {
	s_copy(&__global_state->f2c, expl, "Cardinality of Output Cell is To"
		"o Small", expl_len, (ftnlen)39);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(CLUSTERWRITEERROR)", 
	    msg_len, (ftnlen)24) == 0) {
	s_copy(&__global_state->f2c, expl, "Error Writing to Ephemeris File", 
		expl_len, (ftnlen)31);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(DATATYPENOTRECOG)", 
	    msg_len, (ftnlen)23) == 0) {
	s_copy(&__global_state->f2c, expl, "Unrecognized Data Type Specifica"
		"tion was Encountered", expl_len, (ftnlen)52);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(DATEEXPECTED)", 
	    msg_len, (ftnlen)19) == 0) {
	s_copy(&__global_state->f2c, expl, "The Value in the Kernel File was"
		" Expected to be a date.", expl_len, (ftnlen)55);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(DEVICENAMETOOLONG)", 
	    msg_len, (ftnlen)24) == 0) {
	s_copy(&__global_state->f2c, expl, "Name of Device Exceeds 128-Chara"
		"cter Limit", expl_len, (ftnlen)42);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(EMBEDDEDBLANK)", 
	    msg_len, (ftnlen)20) == 0) {
	s_copy(&__global_state->f2c, expl, "Invalid embedded blank was found"
		" in character string", expl_len, (ftnlen)52);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(FILEALREADYOPEN)", 
	    msg_len, (ftnlen)22) == 0) {
	s_copy(&__global_state->f2c, expl, "File Open Failed Because the Fil"
		"e was Already Open", expl_len, (ftnlen)50);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(FILEOPENFAILED)", 
	    msg_len, (ftnlen)21) == 0) {
	s_copy(&__global_state->f2c, expl, "An Attempt to Open a File Failed",
		 expl_len, (ftnlen)32);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(FILEREADFAILED)", 
	    msg_len, (ftnlen)21) == 0) {
	s_copy(&__global_state->f2c, expl, "An Attempt to Read a File Failed",
		 expl_len, (ftnlen)32);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(FILEWRITEFAILED)", 
	    msg_len, (ftnlen)22) == 0) {
	s_copy(&__global_state->f2c, expl, "An Attempt to Write a File Failed"
		, expl_len, (ftnlen)33);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(INCOMPATIBLEUNITS)", 
	    msg_len, (ftnlen)24) == 0) {
	s_copy(&__global_state->f2c, expl, "The Input and Output Units are I"
		"ncompatible", expl_len, (ftnlen)43);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(INVALIDACTION)", 
	    msg_len, (ftnlen)20) == 0) {
	s_copy(&__global_state->f2c, expl, "An Invalid Action Value Was Supp"
		"lied", expl_len, (ftnlen)36);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(INVALIDARGUMENT)", 
	    msg_len, (ftnlen)22) == 0) {
	s_copy(&__global_state->f2c, expl, "An Invalid Function Argument was"
		" Supplied", expl_len, (ftnlen)41);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(INVALIDCHECKOUT)", 
	    msg_len, (ftnlen)22) == 0) {
	s_copy(&__global_state->f2c, expl, "Checkout Was Attempted When No R"
		"outines Were Checked In", expl_len, (ftnlen)55);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(INVALIDCLUSTERNUM)", 
	    msg_len, (ftnlen)24) == 0) {
	s_copy(&__global_state->f2c, expl, "Invalid Cluster Number -- Cluste"
		"r Numbers Must Exceed 1 ", expl_len, (ftnlen)56);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(INVALIDEPOCH)", 
	    msg_len, (ftnlen)19) == 0) {
	s_copy(&__global_state->f2c, expl, "An Invalid Epoch Type Specificat"
		"ion Was Supplied", expl_len, (ftnlen)48);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(INVALIDINDEX)", 
	    msg_len, (ftnlen)19) == 0) {
	s_copy(&__global_state->f2c, expl, "There Is No Element Correspondin"
		"g to the Supplied Index", expl_len, (ftnlen)55);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(INVALIDTIMESTRING)", 
	    msg_len, (ftnlen)24) == 0) {
	s_copy(&__global_state->f2c, expl, "Time String Could Not Be Parsed", 
		expl_len, (ftnlen)31);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(INVALIDLISTITEM)", 
	    msg_len, (ftnlen)22) == 0) {
	s_copy(&__global_state->f2c, expl, "An Invalid Item Was Found in a L"
		"ist", expl_len, (ftnlen)35);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(INVALIDMSGTYPE)", 
	    msg_len, (ftnlen)21) == 0) {
	s_copy(&__global_state->f2c, expl, "An Invalid Error Message Type Wa"
		"s Specified", expl_len, (ftnlen)43);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(INVALIDOPERATION)", 
	    msg_len, (ftnlen)23) == 0) {
	s_copy(&__global_state->f2c, expl, "An Invalid Operation Value Was S"
		"upplied", expl_len, (ftnlen)39);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(INVALIDOPTION)", 
	    msg_len, (ftnlen)20) == 0) {
	s_copy(&__global_state->f2c, expl, "An Invalid Option Value Was Supp"
		"lied", expl_len, (ftnlen)36);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(INVALIDTIMEFORMAT)", 
	    msg_len, (ftnlen)24) == 0) {
	s_copy(&__global_state->f2c, expl, "Specification of Time String For"
		"mat Was Not Recognized", expl_len, (ftnlen)54);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(KERNELVARNOTFOUND)", 
	    msg_len, (ftnlen)24) == 0) {
	s_copy(&__global_state->f2c, expl, "The Variable Was not Found in th"
		"e Kernel Pool.", expl_len, (ftnlen)46);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(NAMETABLEFULL)", 
	    msg_len, (ftnlen)20) == 0) {
	s_copy(&__global_state->f2c, expl, "No Further Symbols Can be Insert"
		"ed; the Name Table is Full", expl_len, (ftnlen)58);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(NOFREELOGICALUNIT)", 
	    msg_len, (ftnlen)24) == 0) {
	s_copy(&__global_state->f2c, expl, "No More Logical Units are Availa"
		"ble for Allocation", expl_len, (ftnlen)50);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(NOINTERVAL)", msg_len, 
	    (ftnlen)17) == 0) {
	s_copy(&__global_state->f2c, expl, "Window Does Not Contain Interval"
		" Corresponding to the Supplied Index", expl_len, (ftnlen)68);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(NOSEGMENT)", msg_len, (
	    ftnlen)16) == 0) {
	s_copy(&__global_state->f2c, expl, "No Applicable Segment Found in E"
		"phemeris File", expl_len, (ftnlen)45);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(NOSUCHSYMBOL)", 
	    msg_len, (ftnlen)19) == 0) {
	s_copy(&__global_state->f2c, expl, "The Symbol Does Not Exist in the"
		" Symbol Table", expl_len, (ftnlen)45);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(NOTDISTINCT)", msg_len,
	     (ftnlen)18) == 0) {
	s_copy(&__global_state->f2c, expl, "The Elements Must Be Distinct", 
		expl_len, (ftnlen)29);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(NUMBEREXPECTED)", 
	    msg_len, (ftnlen)21) == 0) {
	s_copy(&__global_state->f2c, expl, "The Value in the Kernel File was"
		" Expected to be a Number.", expl_len, (ftnlen)57);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(POINTERTABLEFULL)", 
	    msg_len, (ftnlen)23) == 0) {
	s_copy(&__global_state->f2c, expl, "No Further Symbols Can be Insert"
		"ed; the Pointer Table is Full", expl_len, (ftnlen)61);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(REFNOTREC)", msg_len, (
	    ftnlen)16) == 0) {
	s_copy(&__global_state->f2c, expl, "A Reference Frame Specification "
		"was Not Recognized", expl_len, (ftnlen)50);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(SETEXCESS)", msg_len, (
	    ftnlen)16) == 0) {
	s_copy(&__global_state->f2c, expl, "Cardinality of Set Is Too Small "
		"to Contain Result of the Requested Operation", expl_len, (
		ftnlen)76);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(TOOMANYFILESOPEN)", 
	    msg_len, (ftnlen)23) == 0) {
	s_copy(&__global_state->f2c, expl, "The SPICELIB Limit for Number of"
		" Open Files Has Already Been Reached", expl_len, (ftnlen)68);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(TRACEBACKOVERFLOW)", 
	    msg_len, (ftnlen)24) == 0) {
	s_copy(&__global_state->f2c, expl, "No More Entries Can Be Added to "
		"the Traceback Representation", expl_len, (ftnlen)60);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(UNITSNOTREC)", msg_len,
	     (ftnlen)18) == 0) {
	s_copy(&__global_state->f2c, expl, "The Input or Output Units Were N"
		"ot Recognized", expl_len, (ftnlen)45);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(UNMATCHENDPTS)", 
	    msg_len, (ftnlen)20) == 0) {
	s_copy(&__global_state->f2c, expl, "Window Does Not Have an Even Num"
		"ber of Endpoints", expl_len, (ftnlen)48);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(VALUETABLEFULL)", 
	    msg_len, (ftnlen)21) == 0) {
	s_copy(&__global_state->f2c, expl, "No Further Symbols Can be Insert"
		"ed; the Value Table is Full", expl_len, (ftnlen)59);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(WINDOWEXCESS)", 
	    msg_len, (ftnlen)19) == 0) {
	s_copy(&__global_state->f2c, expl, "Cardinality of Window Is Too Sma"
		"ll to Contain Result of the Requested Operation", expl_len, (
		ftnlen)79);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(WINDOWTOOSMALL)", 
	    msg_len, (ftnlen)21) == 0) {
	s_copy(&__global_state->f2c, expl, "Cardinality of Output Window is "
		"Too Small", expl_len, (ftnlen)41);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(WRITEERROR)", msg_len, 
	    (ftnlen)17) == 0) {
	s_copy(&__global_state->f2c, expl, "An Attempt to write to a specifi"
		"ed unit failed.", expl_len, (ftnlen)47);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(ZERORADIUS)", msg_len, 
	    (ftnlen)17) == 0) {
	s_copy(&__global_state->f2c, expl, "Invalid Radius--Equatorial or Po"
		"lar Radius is Zero", expl_len, (ftnlen)50);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(ZEROVECTOR)", msg_len, 
	    (ftnlen)17) == 0) {
	s_copy(&__global_state->f2c, expl, "Input Vector is the Zero Vector", 
		expl_len, (ftnlen)31);
    } else if (s_cmp(&__global_state->f2c, msg, "SPICE(ZEROAXISLENGTH)", 
	    msg_len, (ftnlen)21) == 0) {
	s_copy(&__global_state->f2c, expl, "Input Axis Length is Zero", 
		expl_len, (ftnlen)25);
    } else {
	s_copy(&__global_state->f2c, expl, " ", expl_len, (ftnlen)1);
    }
    return 0;
} /* expln_ */

