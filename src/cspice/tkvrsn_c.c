/*

-Procedure tkvrsn_c ( Toolkit version strings )

-Abstract
 
   Given an item such as the Toolkit or an entry point name, return 
   the latest version string. 
 
-Disclaimer

   THIS SOFTWARE AND ANY RELATED MATERIALS WERE CREATED BY THE
   CALIFORNIA INSTITUTE OF TECHNOLOGY (CALTECH) UNDER A U.S.
   GOVERNMENT CONTRACT WITH THE NATIONAL AERONAUTICS AND SPACE
   ADMINISTRATION (NASA). THE SOFTWARE IS TECHNOLOGY AND SOFTWARE
   PUBLICLY AVAILABLE UNDER U.S. EXPORT LAWS AND IS PROVIDED "AS-IS"
   TO THE RECIPIENT WITHOUT WARRANTY OF ANY KIND, INCLUDING ANY
   WARRANTIES OF PERFORMANCE OR MERCHANTABILITY OR FITNESS FOR A
   PARTICULAR USE OR PURPOSE (AS SET FORTH IN UNITED STATES UCC
   SECTIONS 2312-2313) OR FOR ANY PURPOSE WHATSOEVER, FOR THE
   SOFTWARE AND RELATED MATERIALS, HOWEVER USED.

   IN NO EVENT SHALL CALTECH, ITS JET PROPULSION LABORATORY, OR NASA
   BE LIABLE FOR ANY DAMAGES AND/OR COSTS, INCLUDING, BUT NOT
   LIMITED TO, INCIDENTAL OR CONSEQUENTIAL DAMAGES OF ANY KIND,
   INCLUDING ECONOMIC DAMAGE OR INJURY TO PROPERTY AND LOST PROFITS,
   REGARDLESS OF WHETHER CALTECH, JPL, OR NASA BE ADVISED, HAVE
   REASON TO KNOW, OR, IN FACT, SHALL KNOW OF THE POSSIBILITY.

   RECIPIENT BEARS ALL RISK RELATING TO QUALITY AND PERFORMANCE OF
   THE SOFTWARE AND ANY RELATED MATERIALS, AND AGREES TO INDEMNIFY
   CALTECH AND NASA FOR ALL THIRD-PARTY CLAIMS RESULTING FROM THE
   ACTIONS OF RECIPIENT IN THE USE OF THE SOFTWARE.

-Required_Reading
 
   None. 
 
-Keywords
 
   UTILITY 
 
*/

   #include "SpiceUsr.h"
   #include "SpiceZfc.h"
   #include "SpiceZmc.h"
   #include "SpiceZst.h"


   ConstSpiceChar  * tkvrsn_c ( void *naif_state, ConstSpiceChar * item ) 

/*

-Brief_I/O
 
   Variable  I/O  Description 
   --------  ---  -------------------------------------------------- 
   item       I   Item for which a version string is desired. 
   
   The function returns a pointer to a version string. 
 
-Detailed_Input
 
   item       is the item for which a version string is to be 
              returned. item may be "TOOLKIT", entry point names, 
              or program names. item is case insensitive. 
 
              Currently, the only item supported is "toolkit" 
              and it will return the toolkit version number. 
 
              Any other item will return "No version found." 
 
-Detailed_Output
 
   The function returns a pointer to the latest version string for the 
   specified item. 
 
   If item is not one of the items haveing a version, a pointer to the 
   string "No version found." will return. 
 
-Parameters
 
   None. 
 
-Exceptions
 
      Error Free. 
 
   1) The routine returns "No version found." for any unknown item
      string. 
 
-Files
 
   None. 
 
-Particulars
 
   None. 
 
-Examples
 
   Suppose you want to find out the recent Toolkit configuration 
   version number. Using the code fragment below: 
 
      ConstSpiceChar  * versn;

      versn = tkvrsn_c ( "TOOLKIT" ); 
 
   The pointer versn would refer to a string similar to the one 
   shown below (except that the version will be current): 
 
      "CSPICE_N0035" 
 
-Restrictions
 
   None.
    
-Literature_References
 
   None. 
 
-Author_and_Institution
 
   N.J. Bachman       (JPL)
   K.R. Gehringer     (JPL) 
   H.A. Neilan        (JPL) 
 
-Version

   -CSPICE Version 2.3.0, 06-FEB-2002 (EDW) (NJB)  

      Changed the return type from (SpiceChar *) to (ConstSpiceChar *).
      Corrected example code to show use of (ConstSpiceChar *) return 
      type. Edited the header.

   -CSPICE Version 2.2.0, 03-SEP-1999 (NJB)  
   
      Return type changed to (SpiceChar *).  Function now cleans
      out version string before writing to it.
       
   -CSPICE Version 2.1.0, 08-FEB-1998 (NJB)  
   
      References to C2F_CreateStr_Sig were removed; code was
      cleaned up accordingly.  String checks are now done using
      the macro CHKFSTR_VAL.
       
   -CSPICE Version 2.0.0, 11-NOV-1997 (NJB)

      Updated to use the SPICELIB routine TKVRSN to obtain
      the version string for SPICELIB.  Updated header to remove
      outdated restrictions.  Changed example to reflect CSPICE
      version string.
      
   -CSPICE Version 1.0.0, 25-OCT-1997 (NJB)

      Based on SPICELIB Version 2.4.0, 31-JUL-1997 (WLT)
      
-Index_Entries
 
   Return version strings 
-&
*/

{ /* Begin tkvrsn_c */

   /*
   Local constants
   */
   #define                 MAXLEN          255
   #define                 CSPICE_PREFIX   "CSPICE_"
   #define                 OFFSET          ( strlen(CSPICE_PREFIX) )
   
   /*
   Static variables
   */
   /* MECHSOFT: Not critical state. Safe to keep thread local. */
   static SpiceChar        verStr [ MAXLEN ];

   /*
   Local variables
   */
   SpiceInt                endPos;
   

   /*
   Participate in error tracing.
   */
   chkin_c ( naif_state, "tkvrsn_c" );


   /*
   Check the input string to make sure the pointer
   is non-null and the string length is non-zero.
   */
   CHKFSTR_VAL ( naif_state, CHK_STANDARD, "tkvrsn_c", item, (ConstSpiceChar *)NULLCPTR );
   
   
   /*
   Make sure verStr is "empty" before filling it in.
   */
   
   verStr[0] = NULLCHAR;
   
   strcpy ( verStr, CSPICE_PREFIX );
   
   tkvrsn_ ( naif_state,
             ( char * ) item,
             ( char * ) (verStr+OFFSET),
             ( ftnlen ) strlen(item),
             ( ftnlen ) MAXLEN-OFFSET-1 );
   
   /*
   Null-terminate the returned string.
   */ 
   endPos = F_StrLen ( naif_state, MAXLEN-1, verStr );
   
   * ( verStr + endPos ) = NULLCHAR;
      
      
   
   if ( eqstr_c ( naif_state, item, "TOOLKIT" ) )
   {
      /* 
      Return the string including the prefix.
      */
      
      chkout_c ( naif_state, "tkvrsn_c" );

      return ( (ConstSpiceChar *)verStr );
      
   }
   else
   {
      /*
      Return whatever was returned by tkvrsn_.
      */
      
      chkout_c ( naif_state, "tkvrsn_c" );

      return ( (ConstSpiceChar *)verStr+OFFSET );
   }


} /* End tkvrsn_c */
