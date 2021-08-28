/*

-Procedure dafgs_c ( DAF, get summary )

-Abstract

   Return (get) the summary for the current array in the current
   DAF.

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

   DAF

-Keywords

   FILES

*/

   #include "SpiceUsr.h"
   #include "SpiceZfc.h"


   void dafgs_c ( SpiceDouble sum[] )

/*

-Brief_I/O

   Variable  I/O  Description
   --------  ---  --------------------------------------------------
   sum        O   Summary for current array.

-Detailed_Input

   None.

-Detailed_Output

   sum         is the summary for the current array (the array
               found by the latest call to daffna_c or daffpa_c).
               Summaries are also called "segment descriptors."

-Parameters

   None.

-Exceptions

   1)  If this routine is called when no search is in progress in the
       the current DAF, the error SPICE(DAFNOSEARCH) is signalled.

   2)  If the DAF for which the "current" array's summary is to be
       returned has actually been closed, the error will be diagnosed
       by routines called by this routine.

   3)  If no array is current in the current DAF, the error
       SPICE(NOCURRENTARRAY) is signalled.  There is no current
       array when a search is started by dafbfs_c or dafbbs_c, but no
       calls to daffna_c or dafbna_c have been made yet, or whenever
       daffna_c or daffpa_c return the value SPICEFALSE in the found
       argument.

-Files

   None.

-Particulars

   The DAF search routines are:


      dafbfs_c       Begin forward search.
      daffna         Find next array.

      dafbbs_c       Begin backward search.
      daffpa_c       Find previous array.

      dafgs_c        Get summary.
      dafgn_c        Get name.
      dafgh_c        Get handle.

      dafcs_c        Continue search.

   The main function of these entry points is to allow the
   contents of any DAF to be examined on an array-by-array
   basis.

   Conceptually, the arrays in a DAF form a doubly linked list,
   which can be searched in either of two directions: forward or
   backward. It is possible to search multiple DAFs simultaneously.

   dafbfs_c (begin forward search) and daffna are used to search the
   arrays in a DAF in forward order.  In applications that search a
   single DAF at a time, the normal usage is

      dafbfs_c ( handle );
      daffna_c ( &found );

      while ( found )
      {
         dafgs_c ( sum  );
         dafgn_c ( name );
          .
          .

         daffna_c ( &found );
      }


   dafbbs_c (begin backward search) and daffpa_c are used to search the
   arrays in a DAF in backward order.  In applications that search
   a single DAF at a time, the normal usage is

      dafbbs_c ( handle );
      daffpa_c ( &found );

      while ( found )
      {
         dafgs_c ( sum  );
         dafgn_c ( name );
          .
          .

         daffpa_c ( &found );
      }


   In applications that conduct multiple searches simultaneously,
   the above usage must be modified to specify the handle of the
   file to operate on, in any case where the file may not be the
   last one specified by dafbfs_c or dafbbs_c.  The routine dafcs_c
   (DAF, continue search) is used for this purpose.  Below, we
   give an example of an interleaved search of two files specified
   by the handles handl1 and handl2.  The directions of searches
   in different DAFs are independent; here we conduct a forward
   search on one file and a backward search on the other.
   Throughout, we use dafcs to specify which file to operate on,
   before calling daffna_c, daffpa_c, dafgs_c, or dafgn_c.


      dafbfs_c ( handl1 );
      dafbbs_c ( handl2 );

      dafcs_c  ( handl1  );
      daffna_c ( &found1 );

      dafcs_c  ( handl2  );
      daffpa_c ( &found2 );

      while ( found1 || found2 )
      {
         if ( found1 )
         {
            dafcs_c ( handl1 );
            dafgs_c ( sum    );
            dafgn_c ( name   );
             .
             .
            dafcs_c  ( &handl1 );
            daffna_c ( &found1 );
         }

         if ( found2 )
         {
            dafcs_c ( handl2 );
            dafgs_c ( sum    );
            dafgn_c ( name   );
             .
             .
            dafcs_c  ( handl2  );
            daffpa_c ( &found2 );
         }
      }


   At any time, the latest array found (whether by daffna_c or daffpa_c)
   is regarded as the "current" array for the file in which the
   array was found.  The last DAF in which a search was started,
   executed, or continued by any of dafbfs_c, dafbbs_c, daffna_c,
   daffpa_c or dafcs_c is regarded as the "current" DAF.  The summary
   and name for the current array in the current DAF can be obtained
   separately, as shown above, by calls to DAFGS (get summary) and
   dafgn_c (get name).  The handle of the current DAF can also be
   obtained by calling dafgh_c (get handle).

   Once a search has been begun, it may be continued in either
   direction. That is, daffpa_c may be used to back up during a
   forward search, and daffna_c may be used to advance during a
   backward search.

-Examples

   Example (1):

      See Particulars.

   Example (2):

   Use a simple routine to output the double precision and integer
   values stored in an SPK's segments descriptors. This function
   opens a DAF for read, performs a forwards search for the DAF
   arrays, prints segments description for each array found, then
   closes the DAF.

      #include <stdio.h>
      #include "SpiceUsr.h"

      int main()
         {

         /.
         Local constants
         ./

         /.
         Define the summary parameters appropriate
         for an SPK file.
         ./

         #define ND              2
         #define NI              6
         #define MAXSUM          125

         SpiceInt                ic  [ NI ];
         SpiceInt                handle;

         SpiceDouble             dc  [ ND ];
         SpiceDouble             sum [ MAXSUM ];

         SpiceChar             * kernel = "de421.bsp";

         SpiceBoolean            found;


         /.
         Open a DAF for read. Return a handle referring to the file.
         ./
         dafopr_c ( kernel, &handle );

         /.
         Begin a forward search on the file.
         ./
         dafbfs_c ( handle );

         /.
         Search until a DAF array is found.
         ./
         daffna_c ( &found );

         /.
         Loop while the search finds subsequent DAF arrays.
         ./
         while ( found )
            {

            dafgs_c ( sum );
            dafus_c ( sum, ND, NI, dc, ic );

            printf( " Doubles: %f %f \n", dc[0], dc[1] );
            printf( "Integers: %d %d %d %d %d %d\n\n",
                       (int)ic[0], (int)ic[1], (int)ic[2],
                       (int)ic[3], (int)ic[4], (int)ic[5] );


            /.
            Check for another segment.
            ./
            daffna_c ( &found );
            }

         /.
         Safely close the DAF.
         ./
         dafcls_c ( handle  );

         return ( 0 );
         }

   The program outputs:

       Doubles: -3169195200.000000 1696852800.000000 
      Integers: 1 0 1 2 641 310404
      
       Doubles: -3169195200.000000 1696852800.000000 
      Integers: 2 0 1 2 310405 423048
      
       Doubles: -3169195200.000000 1696852800.000000 
      Integers: 3 0 1 2 423049 567372
      
       Doubles: -3169195200.000000 1696852800.000000 
      Integers: 4 0 1 2 567373 628976
      
       Doubles: -3169195200.000000 1696852800.000000 
      Integers: 5 0 1 2 628977 674740
      
       Doubles: -3169195200.000000 1696852800.000000 
      Integers: 6 0 1 2 674741 715224
      
       Doubles: -3169195200.000000 1696852800.000000 
      Integers: 7 0 1 2 715225 750428
      
       Doubles: -3169195200.000000 1696852800.000000 
      Integers: 8 0 1 2 750429 785632
      
       Doubles: -3169195200.000000 1696852800.000000 
      Integers: 9 0 1 2 785633 820836
      
       Doubles: -3169195200.000000 1696852800.000000 
      Integers: 10 0 1 2 820837 944040
      
       Doubles: -3169195200.000000 1696852800.000000 
      Integers: 301 3 1 2 944041 1521324
      
       Doubles: -3169195200.000000 1696852800.000000 
      Integers: 399 3 1 2 1521325 2098608
      
       Doubles: -3169195200.000000 1696852800.000000 
      Integers: 199 1 1 2 2098609 2098620
      
       Doubles: -3169195200.000000 1696852800.000000 
      Integers: 299 2 1 2 2098621 2098632
      
       Doubles: -3169195200.000000 1696852800.000000 
      Integers: 499 4 1 2 2098633 2098644

      Note, the final entries in the integer array contains the segment
      start/end indexes. The output indicates the search proceeded
      from the start of the file (low value index) towards the end
      (high value index).

-Restrictions

   None.

-Literature_References

   None.

-Author_and_Institution

   N.J. Bachman    (JPL)
   W.L. Taber      (JPL)
   I.M. Underwood  (JPL)

-Version

   -CSPICE Version 1.0.2, 28-JUN-2016 (EDW)

      Edit to Example code, SpiceInts output as ints using 
      explicit casting.

   -CSPICE Version 1.0.1, 10-OCT-2012 (EDW)

      Added a functional code example to the Examples section.

      Removed the obsolete Reference citation to "NAIF
      Document 167.0."

   -CSPICE Version 1.0.0, 31-JUL-1999 (NJB) (WLT) (IMU)

-Index_Entries

   get daf summary

-&
*/

{ /* Begin dafgs_c */


   /*
   Participate in error tracing.
   */
   chkin_c ( naif_state, "dafgs_c" );


   dafgs_ ( ( doublereal * ) sum );


   chkout_c ( "dafgs_c" );

} /* End dafgs_c */
