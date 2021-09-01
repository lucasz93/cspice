/*

-Procedure limb_pl02 ( Limb using DSK type 2 plate model )

-Abstract
 
   Deprecated: This routine has been superseded by the CSPICE routine
   limbpt_c. This routine is supported for purposes of backward
   compatibility only.

   Compute a set of points on the limb of a specified target body,
   where the target body's surface is represented by a triangular plate
   model contained in a type 2 DSK segment.
 
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
 
   NAIF_IDS
   PCK
   SPK
   TIME
 
-Keywords
 
   BODY 
   GEOMETRY 
   MATH 
 
*/
   #include <math.h>
   #include "SpiceUsr.h"
   #include "SpiceZfc.h"
   #include "SpiceZmc.h"
   #include "SpiceZst.h"

   void limb_pl02 ( void                * naif_state,
                    SpiceInt              handle,
                    ConstSpiceDLADescr  * dladsc,
                    ConstSpiceChar      * target,
                    SpiceDouble           et,
                    ConstSpiceChar      * fixref,
                    ConstSpiceChar      * abcorr,
                    ConstSpiceChar      * obsrvr,
                    SpiceInt              npoints,
                    SpiceDouble         * trgepc,
                    SpiceDouble           obspos   [3],
                    SpiceDouble           limbpts  [][3],
                    SpiceInt              plateIDs []     )

/*

-Brief_I/O
 
   Variable  I/O  Description 
   --------  ---  -------------------------------------------------- 
   handle     I   DSK handle.
   dlasdc     I   DLA descriptor of target body segment.
   target     I   Target body. 
   et         I   Observation epoch. 
   fixref     I   Body-fixed frame associated with target. 
   abcorr     I   Aberration correction. 
   obsrvr     I   Observer. 
   npoints    I   Number of points in limb set. 
   trgepc     O   Epoch associated with target center. 
   obspos     O   Position of observer in body-fixed frame. 
   limbpts    O   Limb point set. 
   plateIDs   O   DSK plate IDs of surface points.
  
-Detailed_Input
  
   handle      is the DAS file handle of a DSK file open for read
               access.  This kernel must contain a type 2 segment that
               provides a plate model representing the entire surface
               of the target body.
 
   dladsc      is the DLA descriptor of a DSK segment representing the
               surface of a target body.
 
 
   target      is the name of the target body. `target' is
               case-insensitive, and leading and trailing blanks in
               `target' are not significant. Optionally, you may supply
               a string containing the integer ID code for the object.
               For example both "MOON" and "301" are legitimate strings
               that indicate the moon is the target body.
 
               This routine assumes that a kernel variable representing
               the target's radii is present in the kernel pool.
               Normally the kernel variable would be defined by loading
               a PCK file.
 
 
   et          is the epoch of participation of the observer, 
               expressed as ephemeris seconds past J2000 TDB: `et' is 
               the epoch at which the observer's position is 
               computed. 
 
               When aberration corrections are not used, `et' is also
               the epoch at which the position and orientation of the
               target body are computed.
 
               When aberration corrections are used, `et' is the epoch
               at which the observer's position relative to the solar
               system barycenter is computed; in this case the position
               and orientation of the target body are computed at
               et-lt, where `lt' is the one-way light time between the
               target body's center and the observer. See the
               description of `abcorr' below for details.
 
 
   fixref      is the name of the reference frame relative to which the
               output limb points are expressed. This must a
               body-centered, body-fixed frame associated with the
               target.  The frame's axes must be compatible with the
               triaxial ellipsoidal shape model associated with the
               target body (normally provide via a PCK): this routine
               assumes that the first, second, and third ellipsoid radii
               correspond, respectively, to the x, y, and z-axes of the
               frame designated by `fixref'.
 
               `fixref' may refer to a built-in frame (documented in 
               the Frames Required Reading) or a frame defined by a 
               loaded frame kernel (FK). 
 
               The orientation of the frame designated by `fixref' is 
               evaluated at epoch of participation of the target 
               body.  See the descriptions of `et' and `abcorr' for 
               details. 
 
 
   abcorr      indicates the aberration correction to be applied 
               when computing the observer-target position, the 
               orientation of the target body, and the target- 
               source position vector.  `abcorr' may be any of 
               the following. 
 
                  "NONE"     Apply no correction.  Compute the limb
                             points using the position of the observer
                             and target, and the orientation of the
                             target, at `et'.
 
               Let `lt' represent the one-way light time between the 
               observer and the target body's center. The following 
               values of `abcorr' apply to the "reception" case in 
               which photons depart from the target body's center at 
               the light-time corrected epoch et-lt and *arrive* at 
               the observer's location at `et': 
 
 
                  "LT"       Correct for one-way light time (also
                             called "planetary aberration") using a
                             Newtonian formulation. This correction
                             yields the location of the limb points at
                             the approximate time they emitted photons
                             arriving at the observer at `et' (the
                             difference between light time to the
                             target center and light time to the limb
                             points is ignored).
  
                             The light time correction uses an 
                             iterative solution of the light time 
                             equation. The solution invoked by the 
                             "LT" option uses one iteration. 
 
                             The target position as seen by the 
                             observer and the rotation of the target 
                             body are corrected for light time. 
 
                  'LT+S'     Correct for one-way light time and stellar
                             aberration using a Newtonian formulation.
                             This option modifies the position obtained
                             with the "LT" option to account for the
                             observer's velocity relative to the solar
                             system barycenter. The result is the
                             apparent limb as seen by the observer.
 
                  "CN"       Converged Newtonian light time correction.
                             In solving the light time equation, the
                             "CN" correction iterates until the
                             solution converges.  The position and
                             rotation of the target body are corrected
                             for light time.
 
                  'CN+S'     Converged Newtonian light time 
                             and stellar aberration corrections. 
 
 
   obsrvr      is the name of the observing body.  This is typically 
               a spacecraft, the Earth, or a surface point on the 
               Earth.  `obsrvr' is case-insensitive, and leading and 
               trailing blanks in `obsrvr' are not significant. 
               Optionally, you may supply a string containing the 
               integer ID code for the object.  For example both 
               "EARTH" and "399" are legitimate strings that indicate 
               the Earth is the observer. 
 
                   
   npoints     is the number of limb points to compute. 
 
    
-Detailed_Output
 
   trgepc      is the "target epoch."  `trgepc' is defined as follows: 
               letting `lt' be the one-way light time between the 
               target center and observer, `trgepc' is either the 
               epoch et-lt or `et' depending on whether the requested 
               aberration correction is, respectively, for received 
               radiation or omitted. `lt' is computed using the 
               method indicated by `abcorr'. 
 
               `trgepc' is expressed as seconds past J2000 TDB. 
 
 
   obspos      is the vector from the center of the target body at 
               epoch `trgepc' to the observer at epoch `et'.  `obspos' is 
               expressed in the target body-fixed reference frame 
               `fixref', which is evaluated at `trgepc'. 
 
               `obspos' is returned to simplify various related 
               computations that would otherwise be cumbersome.  For 
               example, the vector `xvec' from the observer to the 
               Ith limb point can be calculated via the call 
 
                  vminus_c ( limbpts[i], obspos, xvec );
 
               The components of `obspos' are given in units of km. 
 
 
   limbpts     is an array of points on the limb of the target.
               The ith point is contained in the array elements
 
                   limbpts[i][j],  j = 0, 1, 2

               As described above, each limb point lies on a ray
               emanating from the center of the target and passing
               through a limb point on the target's reference
               ellipsoid. Each limb point *on the reference ellipsoid*
               is the point of tangency of a ray that emanates from the
               observer.  Measured in a cylindrical coordinate system
               whose Z-axis is parallel to the observer-target vector,
               the magnitude of the separation in longitude between the
               limb points is
 
                  2*Pi / npoints  
                                       
               The limb points are expressed in the body-fixed 
               reference frame designated by `fixref'; the 
               orientation of the frame is evaluated at `trgepc'.
               Units are km. 
 
 
   plateIDs    is an array of integer ID codes of the plates on which
               the limb points are located.  The ith plate ID
               corresponds to the ith limb point. These ID codes can
               be use to look up data associated with the plates, such
               as the plates' vertices or outward normal vectors.
 
               `plateIDs' should be declared by the caller

                  SpiceInt plateIDs [npoints];


-Parameters
 
   None. 
 
-Exceptions
 
   1)  If the target name `target' cannot be mapped 
       to a body ID code, the error SPICE(IDCODENOTFOUND)
       signaled. 

   2)  If the observer name `obsrvr' cannot be mapped to a body ID
       code, the error SPICE(IDCODENOTFOUND) is signaled. 

   3)  If `obsrvr' and `target' map to the same NAIF integer ID codes,
       the error SPICE(BODIESNOTDISTINCT) is signaled.

   4)  If the input frame name `fixref' cannot be mapped 
       to a frame ID code, the error SPICE(UNKNOWNFRAME) is 
       signaled. 
 
   5)  If the frame designated by `fixref' is not centered 
       on the target, the error SPICE(INVALIDFRAME) is 
       signaled. 
 
   6)  If the set size `npoints' is not at least 1, the error 
       SPICE(INVALIDCOUNT) is signaled.
 
   7)  If any of the reference ellipsoid's semi-axis lengths is
       non-positive, the error will be diagnosed by a routine in the
       call tree of this routine.
 
   8)  If radii for the target body are not available in the kernel
       pool, the error will be diagnosed by a routine in the call tree
       of this routine.  If radii are available but the target body
       does not have three radii, the error SPICE(INVALIDCOUNT) will be
       signaled.
 
   9)  If any SPK look-up fails, the error will be diagnosed by 
       a routine in the call tree of this routine. 
 
  10)  If a DSK providing a DSK type 2 plate model has not been
       loaded prior to calling llgrid_pl02, the error will be
       diagnosed and signaled by a routine in the call tree of this
       routine.

  11)  If the segment associated with the input DLA descriptor is not
       of data type 2, the error SPICE(WRONGDATATYPE) is signaled.

  12)  If a surface point cannot be computed because the ray corresponding
       to a longitude/latitude pair fails to intersect the target
       surface as defined by the plate model, the error will be
       diagnosed by a routine in the call tree of this routine.
 
  13)  If the DSK segment identified by `dladsc' is not for the
       body identified by `target', the error SPICE(DSKTARGETMISMATCH)
       is signaled.

  14)  If any input string pointer is null, the error SPICE(NULLPOINTER)
       will be signaled.
 
  15)  If any input string has length zero, the error SPICE(EMPTYSTRING)
       will be signaled.

-Files
 
   Appropriate DSK, SPK, PCK, and frame kernels must be loaded by the 
   calling program before this routine is called.  
 
   The following data are required: 
 
      - DSK data:  a DSK file containing a plate model representing the
        target body's surface must be loaded. This kernel must contain
        a type 2 segment that contains data for the entire surface of
        the target body.

      - SPK data: ephemeris data for target and observer must be
        loaded. If aberration corrections are used, the states of both
        objects relative to the solar system barycenter must be
        calculable from the available ephemeris data. Typically
        ephemeris data are made available by loading one or more SPK
        files via furnsh_c.
 
      - PCK data: triaxial radii for the target body must be loaded
        into the kernel pool. Typically this is done by loading a text
        PCK file via furnsh_c.
 
      - Further PCK data:  rotation data for the target body must 
        be loaded.  These may be provided in a text or binary PCK 
        file.  
 
      - Frame data:  if a frame definition is required to convert 
        the observer and target states to the target body-fixed 
        frame designated by `fixref', that definition must be 
        available in the kernel pool.  Typically the definitions of 
        frames not already built-in to SPICE are supplied by loading 
        a frame kernel. 
 
   In all cases, kernel data are normally loaded once per program 
   run, NOT every time this routine is called. 
 
-Particulars
  
   Boundaries of visible regions on an arbitrary surface are often
   complicated point sets:  boundaries of mountains and craters, if
   present, may contribute to the overall set.  To make the limb
   computation tractable, we simplify the problem by using a reference
   ellipsoid for guidance.  We compute a set of limb points on the
   reference ellipsoid for the target body, then use those points to
   define the latitudes and longitudes of limb points on the surface
   defined by the specified triangular shape model.  As such, the set
   of limb points found by this routine is just an approximation.
 
-Examples

   The numerical results shown for this example may differ across
   platforms. The results depend on the SPICE kernels used as input,
   the compiler and supporting libraries, and the machine specific
   arithmetic implementation.

 
   1)  Compute sets of limb points on Phobos as seen from Mars. Perform
       a consistency check using the emission angle at each point,
       where the emission angle is computed using both a reference
       ellipsoid and the actual plate model surface and surface normal.
       We expect to see an emission angle of approximately 90 degrees.
 
       This program loads SPICE kernels via a meta-kernel.  The
       contents of the meta-kernel used to produce the results shown 
       below are:


          \begindata

             KERNELS_TO_LOAD = ( 'naif0009.tls'
                                 'pck00009.tpc'
                                 'mar085.bsp' 
                                 'de421.bsp'   )
          \begintext
 

       The DSK is loaded separately (this is a temporary inconvenience
       that will be remedied when the KEEPER system is updated to handle
       DSKs).  The DSK used for this computation is

          phobos.3.3.bds

       Source code follows.
      

          #include <stdio.h>
          #include <math.h>
          #include "SpiceUsr.h"

          int main()
          {
             /.
             Prototypes 
             ./
             void limb_pl02 ( SpiceInt              handle,
                              ConstSpiceDLADescr  * dladsc,
                              ConstSpiceChar      * target,
                              SpiceDouble           et,
                              ConstSpiceChar      * fixref,
                              ConstSpiceChar      * abcorr,
                              ConstSpiceChar      * obsrvr,
                              SpiceInt              npoints,
                              SpiceDouble         * trgepc,
                              SpiceDouble           obspos   [3],
                              SpiceDouble           limbpts   [][3],
                              SpiceInt              plateIDs []     );

             /.
             Local parameters
             ./
             #define  FILSIZ         256 
             #define  NPOINTS        3
             #define  NTYPES         2
             #define  TOL            ( 1.e-12 )
             #define  CORLEN         15
             #define  TYPLEN         81 
             #define  TIMLEN         41

             /.
             Local variables
             ./
             SpiceBoolean            found;

             SpiceChar             * abcorr = "LT+S";
             SpiceChar               dsk     [ FILSIZ  ];
             SpiceChar             * fixref = "IAU_PHOBOS";
             SpiceChar               meta    [ FILSIZ  ];


             SpiceChar             * obsrvr = "Mars";
             SpiceChar             * target = "Phobos";
             SpiceChar             * utcstr = "2007 FEB 9 00:00:00 UTC";
             SpiceChar               timstr  [ TIMLEN];

             SpiceDLADescr           dladsc;

             SpiceDouble             emissn;
             SpiceDouble             obspos    [3];
             SpiceDouble             phase;
             SpiceDouble             radius;
             SpiceDouble             solar;
             SpiceDouble             trgepc;
             SpiceDouble             et;
             SpiceDouble             lat;
             SpiceDouble             lon;
             SpiceDouble             limbpts    [NPOINTS][3];

             SpiceInt                handle;
             SpiceInt                i;
             SpiceInt                plateIDs  [NPOINTS];

             /.
             Prompt for the name of a meta-kernel specifying
             all of the other kernels we need.  Load the
             metakernel.
             ./
             prompt_c ( "Enter meta-kernel name > ", FILSIZ, meta );
             furnsh_c ( meta );

             /.
             Prompt for the name of the DSK to read.
             ./
             prompt_c ( "Enter DSK name         > ", FILSIZ, dsk );

             /.
             Open the DSK file for read access.
             We use the DAS-level interface for
             this function.
             ./
             dasopr_c ( dsk, &handle );

             /.
             Begin a forward search through the
             kernel, treating the file as a DLA.
             In this example, it's a very short
             search.
             ./
             dlabfs_c ( handle, &dladsc, &found );

             if ( !found  )
             {
                /.
                We arrive here only if the kernel
                contains no segments.  This is
                unexpected, but we're prepared for it.
                ./
                setmsg_c ( naif_state, "No segments found in DSK file #.");
                errch_c  ( naif_state, "#",  dsk                         );
                sigerr_c ( naif_state, "SPICE(NODATA)"                   );
             }

             /.
             If we made it this far, `dladsc' is the
             DLA descriptor of the first segment.

             Convert the observation time to seconds past J2000 TDB.
             ./
             str2et_c ( utcstr, &et );

             timout_c ( et, 
                        "YYYY-MON-DD "
                        "HR:MN:SC.### ::TDB(TDB)",
                        TIMLEN,
                        timstr                    );

             printf ( "\n\n"
                      "   Observer:               %s\n" 
                      "   Target:                 %s\n" 
                      "   Observation epoch:      %s\n" 
                      "   Aberration correction:  %s\n"
                      "   Body-fixed frame:       %s\n", 
                      obsrvr,
                      target,
                      timstr,
                      abcorr,
                      fixref                            );

             /.
             Now compute grid of limb points.
             ./
             limb_pl02 ( handle,   &dladsc,   
                         target,   et,       fixref,   abcorr,
                         obsrvr,   NPOINTS,  &trgepc,  obspos,
                         limbpts,   plateIDs                    );

             /.
             Display the limb points. 
             ./
             for ( i = 0;  i < NPOINTS;  i++  )
             {
                printf ( "\n" );

                reclat_c ( limbpts[i], &radius, &lon, &lat );

                printf ( 
                "      Limb point %d:\n"
                "         Radius                     (km):  %f\n" 
                "         Planetocentric longitude   (deg): %f\n" 
                "         Planetocentric latitude    (deg): %f\n"
                "         Plate ID:                         %d\n",
                (int)i,
                radius,
                lon * dpr_c(),
                lat * dpr_c(),
                (int)plateIDs[i]                                );


                /.
                Compute the illumination angles using an ellipsoidal
                representation of the target's surface. The role of
                this representation is to provide an outward surface
                normal.
                ./
                illum_c ( target,  et,         abcorr, 
                          obsrvr,  limbpts[i],  &phase,  
                          &solar,  &emissn             );

                printf ( 
                "            "
                "emission angle derived using\n"
                "            "
                "   - an ellipsoidal reference surface        (deg):"
                " %f\n",              
                emissn  * dpr_c()                                      );

                /.
                Compute the illumination angles at the limb point
                using the actual plate model surface normal.
                ./
                illum_pl02 ( handle, &dladsc, target,   et,
                             abcorr, obsrvr,  limbpts[i], 
                             &phase, &solar,  &emissn      );               

                printf ( 
                "            "
                "   - plate model's surface and normal vector (deg):"
                " %f\n",
                emissn  * dpr_c()                                      );
             }

             printf ( "\n" );

             /.
             Close the kernel.  This isn't necessary in a stand-
             alone program, but it's good practice in subroutines
             because it frees program and system resources.
             ./
             dascls_c ( handle );

             return ( 0 );
          }


   
   When this program was executed on a PC/Linux/gcc platform, 
   the output was:
 

     Enter meta-kernel name > limb_meta
     Enter DSK name         > phobos.3.3.bds


        Observer:               Mars
         Target:                 Phobos
         Observation epoch:      2007-FEB-09 00:01:05.184 (TDB)
         Aberration correction:  LT+S
         Body-fixed frame:       IAU_PHOBOS

            Limb point 0:
               Radius                     (km):  11.548564
               Planetocentric longitude   (deg): 91.916308
               Planetocentric latitude    (deg): -0.001421
               Plate ID:                         229468
                  emission angle derived using
                     - an ellipsoidal reference surface        (deg): 90.002150
                     - plate model's surface and normal vector (deg): 110.821147

            Limb point 1:
               Radius                     (km):  9.539431
               Planetocentric longitude   (deg): -87.644392
               Planetocentric latitude    (deg): 59.998173
               Plate ID:                         235885
                  emission angle derived using
                     - an ellipsoidal reference surface        (deg): 89.999635
                     - plate model's surface and normal vector (deg): 97.682098

            Limb point 2:
               Radius                     (km):  9.040443
               Planetocentric longitude   (deg): -87.860468
               Planetocentric latitude    (deg): -59.996395
               Plate ID:                         17964
                  emission angle derived using
                     - an ellipsoidal reference surface        (deg): 89.996577
                     - plate model's surface and normal vector (deg): 69.169892


-Restrictions
 
   1)  The quality of the results produced by this routine depend on how
       well the target body's surface is approximated by the target's
       reference ellipsoid.  This routine will *not* produce meaningful
       results for body shapes such as "dumbbells."
 
-Literature_References
 
   None. 
 
-Author_and_Institution
 
   N.J. Bachman    (JPL) 
 
-Version
 
   -CSPICE Version 2.0.0, 23-JUL-2016 (NJB) 
 
      Added and moved failed_c calls.

      Include file references have been updated. Integer output
      format in the example program has been updated. Updated
      example program output to reflect bug fix of 29-APR-2014.

   -Beta Version 3.0.0, 24-JUN-2014 (NJB) (EDW)
   
       Added failed_c checks to ensure return before 
       performance of arithmetic computations using
       invalid operands. Added check for target equal
       to observer.

    Last update was 29-APR-2014 (NJB)
       
       Bug fix: corrected limb point selection so that
       points have uniform spacing in longitude, measured
       in a frame centered on the observer-target center 
       line.

       Bug fix: added sigerr_c call in error handling
       branch for invalid value of `npoints'.

       Bug fix: added check for body-fixed frame not 
       centered on target.

       Bug fix: added error handling for null input string
       pointers and empty strings.

       Added check for mismatch between target and central
       body of DSK segment.

       Added test of failed_c after spkpos_c call.

       Changed argument name `fixfrm' to `fixref'.

       The target name to ID conversion is now performed
       in-line. The short error message for a failed 
       conversion is not SPICE(IDCODENOTFOUND).

       Header correction: the error case of an unmapped 
       observer name is now listed.
       

   -Beta Version 2.1.0, 14-MAY-2010 (NJB)

       Updated header example. Added include statement
       for header pl02.h.

   -Beta Version 2.0.0, 12-FEB-2010 (NJB)  

       Updated to include

          SpiceDSK.h

   -Beta Version 1.0.0, 27-FEB-2007 (NJB)

-Index_Entries
 
   find limb on plate model
   find limb on triangular shape model
 
-&
*/

{ /* Begin limb_pl02 */


   /*
   Prototypes 
   */      


   /*
   Local variables
   */
   
   /*
   Pointer for a dynamically allocated lon/lat grid 
   (the type of this pointer is "pointer to an
   array of two SpiceDoubles").
   */
   SpiceBoolean            found;

   SpiceDSKDescr           dskdsc;

   SpiceDouble             center   [3];
   SpiceDouble             delta;
   SpiceDouble             dir      [3];
   SpiceDouble             invpt    [3];
   SpiceDouble         ( * lonLatGridPtr )[2];
   SpiceDouble             lt;
   SpiceDouble             projpt   [3];
   SpiceDouble             pvec     [3];
   SpiceDouble             pvproj   [3];
   SpiceDouble             radius;
   SpiceDouble             smajor   [3];
   SpiceDouble             sminor   [3];
   SpiceDouble             theta;
   SpiceDouble             trgpos   [3];
   SpiceDouble             trgRadii [3];

   SpiceEllipse            limb;

   SpiceInt                frcent;
   SpiceInt                frclid;
   SpiceInt                frclss;
   SpiceInt                frcode;
   SpiceInt                i;
   SpiceInt                n;
   SpiceInt                nBytes;
   SpiceInt                obscde;
   SpiceInt                trgcde;

   SpicePlane              limbPlane;
   SpicePlane              perpPlane;


   /*
   Participate in error tracing.
   */
   chkin_c ( naif_state, "limb_pl02" );

   /*
   Check the input strings. Make sure none of the pointers are null and
   that each string contains at least one non-null character.
   */
   CHKFSTR ( naif_state, CHK_STANDARD, "limb_pl02", target );
   CHKFSTR ( naif_state, CHK_STANDARD, "limb_pl02", fixref );
   CHKFSTR ( naif_state, CHK_STANDARD, "limb_pl02", abcorr );
   CHKFSTR ( naif_state, CHK_STANDARD, "limb_pl02", obsrvr );

   /*
   Map the target name to an ID code.
   */
   bods2c_c ( naif_state, target, &trgcde, &found );

   if ( failed_c(naif_state) ) 
   {
      chkout_c ( naif_state, "limb_pl02" );
      return;
   }

   if ( !found ) 
   {
      setmsg_c ( naif_state, "The target name # could not be mapped "
                 "to an ID code."                        );
      errch_c  ( naif_state, "#", target                             );
      sigerr_c ( naif_state, "SPICE(IDCODENOTFOUND)"                 );
      chkout_c ( naif_state, "limb_pl02"                             );
      return;      
   }

   /*
   Map the observer name to an ID code.
   */
   bods2c_c ( naif_state, obsrvr, &obscde, &found );

   if ( failed_c(naif_state) ) 
   {
      chkout_c ( naif_state, "limb_pl02" );
      return;
   }

   if ( !found ) 
   {
      setmsg_c ( naif_state, "The observer name # could not be mapped "
                 "to an ID code."                        );
      errch_c  ( naif_state, "#", obsrvr                             );
      sigerr_c ( naif_state, "SPICE(IDCODENOTFOUND)"                 );
      chkout_c ( naif_state, "limb_pl02"                             );
      return;      
   }

   /*
   Make sure target and observer don't coincide. 
   */
   if ( trgcde == obscde  )
   {
      setmsg_c ( naif_state, "Both target and observer have the same integer "
                 "ID code #.  These objects must be distinct."     );
      errint_c ( naif_state, "#", obscde                                       );
      sigerr_c ( naif_state, "SPICE(BODIESNOTDISTINCT)"                        );
      chkout_c ( naif_state, "limb_pl02"                                       );
      return;
   }

   /*
   Check the DSK descriptor of the DSK segment; make sure it's
   for the correct body.
   */
   dskgd_c ( naif_state, handle, dladsc, &dskdsc );

   if ( failed_c(naif_state) ) 
   {
      chkout_c ( naif_state, "limb_pl02" );
      return;
   }

   if ( dskdsc.center != trgcde )
   {
      setmsg_c ( naif_state, "The target is # but the input DSK "
                 "segment is for body #."            );
      errint_c ( naif_state, "#", dskdsc.center                  );
      sigerr_c ( naif_state, "SPICE(DSKTARGETMISMATCH)"          );
      chkout_c ( naif_state, "limb_pl02"                         );
      return;            
   }


   /*
   Check npoints.
   */
   if ( npoints < 1 )
   {
      setmsg_c ( naif_state, "The requested number of limb points must be "
                 "positive but was #."                          );
      errint_c ( naif_state, "#", npoints                                   );
      sigerr_c ( naif_state, "SPICE(INVALIDCOUNT)"                          );
      chkout_c ( naif_state, "limb_pl02"                                    );
      return;
   }

   /*
   Make sure fixref is centered on the target.
   */
   namfrm_c ( naif_state, fixref, &frcode );

   if ( failed_c(naif_state) ) 
   {
      chkout_c ( naif_state, "limb_pl02" );
      return;
   }
   
   if ( frcode == 0 ) 
   {
      setmsg_c ( naif_state, "The reference frame name # could not be mapped "
                 "to an ID code."                                );
      errch_c  ( naif_state, "#", fixref                                     );
      sigerr_c ( naif_state, "SPICE(UNKNOWNFRAME)"                           );
      chkout_c ( naif_state, "limb_pl02"                                     );
      return;
   }

   frinfo_c ( naif_state, frcode, &frcent, &frclss, &frclid, &found );

   if ( failed_c(naif_state) ) 
   {
      chkout_c ( naif_state, "limb_pl02" );
      return;
   }

   if ( !found )
   {
      setmsg_c ( naif_state, "The reference frame name # could not be mapped "
                 "to a frame specification."                     );
      errch_c  ( naif_state, "#", fixref                                     );
      sigerr_c ( naif_state, "SPICE(UNKNOWNFRAME)"                           );
      chkout_c ( naif_state, "limb_pl02"                                     );
      return;
   }

   if ( frcent != trgcde )
   {
      setmsg_c ( naif_state, "The body-fixed reference frame # must be "
                 "centered on the target #, but is centered "
                 "on body #."                                 );
      errch_c  ( naif_state, "#", fixref                                  );
      errch_c  ( naif_state, "#", target                                  );
      errint_c ( naif_state, "#", frcent                                  );
      sigerr_c ( naif_state, "SPICE(INVALIDFRAME)"                        );
      chkout_c ( naif_state, "limb_pl02"                                  );
      return;            
   }


   /*
   First step:  find the limb on the reference ellipsoid.
   Note in particular that if a PCK file providing radii for the target
   reference ellipsoid hasn't been loaded, we'll find out here.

   Get the aberration-corrected target position as seen from the
   observer in the target body-fixed frame.  Negate this vector
   to obtain the observer's position relative to the target body center.
   */
   bodvrd_c ( naif_state, target, "RADII", 3, &n, trgRadii );

   if ( failed_c(naif_state) ) 
   {
      chkout_c ( naif_state, "limb_pl02" );
      return;
   }

   if ( n < 3 )
   {
      setmsg_c ( naif_state, "There must be three target radii but the "
                 "actual count was #."                      );
      errint_c ( naif_state, "#", npoints                               );
      sigerr_c ( naif_state, "SPICE(INVALIDCOUNT)"                      );
      chkout_c ( naif_state, "limb_pl02"                                );
      return;
   }

   spkpos_c ( naif_state, target, et, fixref, abcorr, obsrvr, trgpos, &lt );

   if ( failed_c(naif_state) ) 
   {
      chkout_c ( naif_state, "limb_pl02" );
      return;
   }

   vminus_c ( naif_state, trgpos, obspos );

   edlimb_c ( naif_state, trgRadii[0], trgRadii[1], trgRadii[2], obspos, &limb );

   if ( failed_c(naif_state) ) 
   {
      chkout_c ( naif_state, "limb_pl02" );
      return;
   }

   /*
   Find the center and semi-axis vectors of the limb of the
   reference ellipsoid.
   */
   el2cgv_c ( naif_state, &limb, center, smajor, sminor );

   /*
   Generate a set of points on the limb.  Note we need not worry about
   division by zero here; we've already checked `npoints'.
 
   We want the points to have uniform separation in longitude, measured
   in a plane orthogonal to the observer-target line. We'll create such
   a plane; this plate will the limb's center. (Note that for all 
   ellipsoids, the limb center lies on the observer-target center line).
   */
   nvp2pl_c ( naif_state, obspos, center, &perpPlane );

   /*
   Map an endpoint of a semi-major axis to the "orthogonal" plane
   via orthogonal projection.
   */
   psv2pl_c ( naif_state, center, smajor, sminor, &limbPlane );

   if ( failed_c(naif_state) ) 
   {
      chkout_c ( naif_state, "limb_pl02" );
      return;
   }

   vadd_c  ( naif_state, center, smajor,     pvec   );  
   vprjp_c ( naif_state, pvec,   &perpPlane, pvproj );
   
   if ( failed_c(naif_state) ) 
   {
      chkout_c ( naif_state, "limb_pl02" );
      return;
   }


   delta = twopi_c(naif_state) / npoints;

   for ( i = 0;  i < npoints;  i++ )
   {
      theta = i * delta;

      vrotv_c ( naif_state, pvproj, obspos, theta, projpt );

      /*
      Find the point on the limb plane that maps to prjpt
      under orthogonal projection onto the orthogonal plane. 
 
      The vector from the limb center to this inverse projection
      gives us the direction from the center toward the desired
      limb point.
      */
      vprjpi_c ( naif_state, projpt, &perpPlane, &limbPlane, invpt, &found );

      if ( failed_c(naif_state) ) 
      {
         chkout_c ( naif_state, "limb_pl02" );
         return;
      }

      if ( !found )
      {
         setmsg_c ( naif_state, "Could not invert orthogonal projection "
                    "for the limb point at index #."         );
         errint_c ( naif_state, "#", i                                   );
         sigerr_c ( naif_state, "SPICE(DEGENERATECASE)"                  );
         chkout_c ( naif_state, "limb_pl02"                              );
         return;
      }

      vsub_c   ( naif_state, invpt, center, dir );

      surfpt_c ( naif_state,
                 center,      dir,         trgRadii[0], 
                 trgRadii[1], trgRadii[2], limbpts[i],  &found );

      if ( failed_c(naif_state) ) 
      {
         chkout_c ( naif_state, "limb_pl02" );
         return;
      }

      if ( !found )
      {
         setmsg_c ( naif_state, "Could not find ray-ellipsoid intercept "
                    "for the limb point at index #."         );
         errint_c ( naif_state, "#", i                                   );
         sigerr_c ( naif_state, "SPICE(DEGENERATECASE)"                  );
         chkout_c ( naif_state, "limb_pl02"                              );
         return;
      }

   }

   /*
   Set the target's epoch of participation. 
   */
   zzcorepc_ ( naif_state,
               ( char       * ) abcorr,
               ( doublereal * ) &et,
               ( doublereal * ) &lt,
               ( doublereal * ) trgepc,
               ( ftnlen       ) strlen(abcorr) );

   if ( failed_c(naif_state) ) 
   {
      chkout_c ( naif_state, "limb_pl02" );
      return;
   }

   /*
   At this point, the outputs

      trgepc
      obspos

   have been set. 

   Allocate an array to hold longitude/latitude coordinates
   corresponding to the limb points on the reference ellipsoid.
   */
   nBytes        =   npoints * 2 * sizeof( SpiceDouble );

   lonLatGridPtr = ( SpiceDouble(*)[2] ) malloc( nBytes ); 
   
   if ( !lonLatGridPtr )
   {
      setmsg_c ( naif_state, "Call to malloc to allocate # bytes of memory "
                 "for the lon/lat array failed."                 );
      errint_c ( naif_state, "#",  nBytes                                    );
      chkout_c ( naif_state, "limb_pl02"                                     );
      return;
   }

   /*
   Fill in the longitude/latitude grid. 
   */
   for ( i = 0;  i < npoints;  i++ )
   {
      /*
      Convert the ith limb point on the reference ellipsoid
      from rectangular to latitudinal coordinates.   
      */
      reclat_c (  naif_state,
                  limbpts[i], 
                  &radius, 
                  &( lonLatGridPtr[i][0] ),
                  &( lonLatGridPtr[i][1] )   );      
   }

   /*
   Find the plate model's surface points at the lon/lat locations 
   we've computed.  Find the plate ID corresponding to each surface
   point as well.

   We cast the lon/lat grid pointer to "pointer to const array of two
   SpiceDoubles" for compatibility with the prototype of llgrid_pl02.
   Only the const qualifier is new; the size is unchanged.
   */
   llgrid_pl02 ( naif_state,
                 handle,                                  
                 dladsc,  
                 npoints, 
                 (ConstSpiceDouble (*)[2]) lonLatGridPtr,  
                 limbpts,  
                 plateIDs                                 );

   /*
   If no error occurred, the outputs
  
      limbpts
      plateIDs

   are set.  

   Free the dynamically allocated lon/lat array. 
   */
   free ( lonLatGridPtr );

   chkout_c ( naif_state, "limb_pl02" );

} /* End limb_pl02 */
