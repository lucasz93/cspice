/*

-Header_File SpiceZfc.h ( f2c'd SPICELIB prototypes )

-Abstract

   Define prototypes for functions produced by converting Fortran
   SPICELIB routines to C using f2c.

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

-Literature_References

   None.

-Author_and_Institution

   N.J. Bachman       (JPL)
   K.R. Gehringer     (JPL)
   B.V. Semenov       (JPL)
   E.D. Wright        (JPL)

-Version

   -CSPICE Version 7.0.0, 10-MAR-2014 (BVS)

      Reformatted version lines.

      Now this header conditionally includes SpiceUsr.h.

      Updated for:
       
         PC-CYGWIN-64BIT-GCC_C
          
      environment. Added the corresponding tag:
       
         CSPICE_PC_CYGWIN_64BIT_GCC

      tag to the #ifdefs set.
        
   -CSPICE Version 6.1.0, 14-MAY-2010 (EDW)(BVS)

      Updated for:

         MAC-OSX-64BIT-INTEL_C
         SUN-SOLARIS-64BIT-NATIVE_C
         SUN-SOLARIS-INTEL-64BIT-CC_C

      environments. Added the corresponding tags:

         CSPICE_MAC_OSX_INTEL_64BIT_GCC
         CSPICE_SUN_SOLARIS_64BIT_NATIVE
         CSPICE_SUN_SOLARIS_INTEL_64BIT_CC

      tag to the #ifdefs set.
        
   -CSPICE Version 6.0.0, 21-FEB-2006 (NJB)

      Added typedefs for the PC-LINUX-64BIT-GCC_C
      environment (these are identical to those for the 
      ALPHA-DIGITAL-UNIX_C environment).

   -CSPICE Version 5.0.0, 06-MAR-2005 (NJB)

      Added typedefs for pointers to functions.  This change was
      made to support CSPICE wrappers for geometry finder routines.

      Added typedefs for the SUN-SOLARIS-64BIT-GCC_C
      environment (these are identical to those for the 
      ALPHA-DIGITAL-UNIX_C environment).

   -CSPICE Version 4.1.0, 24-MAY-2001 (WLT)

      Moved the #ifdef __cplusplus so that it appears after the
      typedefs.  This allows us to more easily wrap CSPICE in a
      namespace for C++.

   -CSPICE Version 4.0.0, 09-FEB-1999 (NJB)  
   
      Updated to accommodate the Alpha/Digital Unix platform.
      Also updated to support inclusion in C++ code.
                  
   -CSPICE Version 3.0.0, 02-NOV-1998 (NJB)  
   
      Updated for SPICELIB version N0049.
        
   -CSPICE Version 2.0.0, 15-SEP-1997 (NJB)  
   
      Changed variable name "typid" to "typid" in prototype
      for zzfdat_.  This was done to enable compilation under
      Borland C++.
        
   -CSPICE Version 1.0.0, 15-SEP-1997 (NJB) (KRG)

-Index_Entries

   prototypes of f2c'd SPICELIB functions

*/


/*  
   Include SpiceUsr.h if it hasn't already been included
   by the current compilation unit.
*/
#ifndef HAVE_SPICE_USER
   #include "SpiceUsr.h"
#endif



#ifndef HAVE_SPICEF2C_H
#define HAVE_SPICEF2C_H


/*
   Include Files:

   Many of the prototypes below use data types defined by f2c.  We
   copy here the f2c definitions that occur in prototypes of functions
   produced by running f2c on Fortran SPICELIB routines.
   
   The reason we don't simply conditionally include f2c.h itself here
   is that f2c.h defines macros that conflict with stdlib.h on some
   systems.  It's simpler to just replicate the few typedefs we need.
*/
#ifndef F2C_INCLUDE
#if (    defined( CSPICE_ALPHA_DIGITAL_UNIX    )      \
      || defined( CSPICE_PC_CYGWIN_64BIT_GCC )        \
      || defined( CSPICE_PC_LINUX_64BIT_GCC    )      \
      || defined( CSPICE_MAC_OSX_INTEL_64BIT_GCC )    \
      || defined( CSPICE_SUN_SOLARIS_INTEL_64BIT_CC ) \
      || defined( CSPICE_SUN_SOLARIS_64BIT_NATIVE)    \
      || defined( CSPICE_SUN_SOLARIS_64BIT_GCC )        )

   #define VOID      void
   
   typedef VOID      H_f;
   typedef int       integer;
   typedef double    doublereal;
   typedef int       logical;
   typedef int       ftnlen;
 

   /*
   Type H_fp is used for character return type.
   Type S_fp is used for subroutines.
   Type U_fp is used for functions of unknown type.
   */
   typedef VOID       (*H_fp)(void *state, ...);
   typedef doublereal (*D_fp)(void *state, ...);
   typedef doublereal (*E_fp)(void *state, ...);
   typedef int        (*S_fp)(void *state, ...);
   typedef int        (*U_fp)(void *state, ...);
   typedef integer    (*I_fp)(void *state, ...);
   typedef logical    (*L_fp)(void *state, ...);

#else

   #define VOID      void
   
   typedef VOID      H_f;
   typedef long      integer;
   typedef double    doublereal;
   typedef long      logical;
   typedef long      ftnlen;

   /*
   Type H_fp is used for character return type.
   Type S_fp is used for subroutines.
   Type U_fp is used for functions of unknown type.
   */
   typedef VOID       (*H_fp)(void *state, ...);
   typedef doublereal (*D_fp)(void *state, ...);
   typedef doublereal (*E_fp)(void *state, ...);
   typedef int        (*S_fp)(void *state, ...);
   typedef int        (*U_fp)(void *state, ...);
   typedef integer    (*I_fp)(void *state, ...);
   typedef logical    (*L_fp)(void *state, ...);

#endif
#endif /* !F2C_INCLUDE */

#ifdef __cplusplus
   extern "C" { 
#endif


/*
   Function prototypes for functions created by f2c are listed below.
   See the headers of the Fortran routines for descriptions of the
   routines' interfaces.

   The functions listed below are those expected to be called by
   C-SPICELIB wrappers.  Prototypes are not currently provided for other
   f2c'd functions.

*/

/*
-Prototypes
*/

extern logical accept_(void *cspice_state, logical *ok);
extern logical allowd_(void *cspice_state);
 
extern logical alltru_(void *cspice_state, logical *logcls, integer *n);
 
extern H_f ana_(void *cspice_state, char *ret_val, ftnlen ret_val_len, char *word, char *case__, ftnlen word_len, ftnlen case_len);
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: replch_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
 
extern int appndc_(void *cspice_state, char *item, char *cell, ftnlen item_len, ftnlen cell_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: sizec_ 4 2 13 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int appndd_(void *cspice_state, doublereal *item, doublereal *cell);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: sized_ 4 1 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int appndi_(void *cspice_state, integer *item, integer *cell);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: sizei_ 4 1 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern logical approx_(void *cspice_state, doublereal *x, doublereal *y, doublereal *tol);
 
extern int astrip_(void *cspice_state, char *instr, char *asciib, char *asciie, char *outstr, ftnlen instr_len, ftnlen asciib_len, ftnlen asciie_len, ftnlen outstr_len);
/*:ref: lastnb_ 4 2 13 124 */
 
extern int axisar_(void *cspice_state, doublereal *axis, doublereal *angle, doublereal *r__);
/*:ref: ident_ 14 1 7 */
/*:ref: vrotv_ 14 4 7 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
 
extern doublereal b1900_(void *cspice_state);
 
extern doublereal b1950_(void *cspice_state);
 
extern logical badkpv_(void *cspice_state, char *caller, char *name__, char *comp, integer *size, integer *divby, char *type__, ftnlen caller_len, ftnlen name_len, ftnlen comp_len, ftnlen type_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: eqchr_ 12 4 13 13 124 124 */
 
extern logical bedec_(void *cspice_state, char *string, ftnlen string_len);
/*:ref: pos_ 4 5 13 13 4 124 124 */
/*:ref: beint_ 12 2 13 124 */
/*:ref: beuns_ 12 2 13 124 */
 
extern logical beint_(void *cspice_state, char *string, ftnlen string_len);
/*:ref: frstnb_ 4 2 13 124 */
/*:ref: beuns_ 12 2 13 124 */
 
extern logical benum_(void *cspice_state, char *string, ftnlen string_len);
/*:ref: cpos_ 4 5 13 13 4 124 124 */
/*:ref: bedec_ 12 2 13 124 */
/*:ref: beint_ 12 2 13 124 */
 
extern logical beuns_(void *cspice_state, char *string, ftnlen string_len);
/*:ref: frstnb_ 4 2 13 124 */
 
extern int bltfrm_(void *cspice_state, integer *frmcls, integer *idset);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: zzfdat_ 14 18 4 4 13 4 4 4 4 4 4 4 13 4 4 4 4 4 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: sizei_ 4 1 4 */
/*:ref: orderi_ 14 3 4 4 4 */
 
extern int bodc2n_(void *cspice_state, integer *code, char *name__, logical *found, ftnlen name_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzbodc2n_ 14 4 4 13 12 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int bodc2s_(void *cspice_state, integer *code, char *name__, ftnlen name_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzbodc2n_ 14 4 4 13 12 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: intstr_ 14 3 4 13 124 */
 
extern int boddef_(void *cspice_state, char *name__, integer *code, ftnlen name_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzboddef_ 14 3 13 4 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int bodeul_(void *cspice_state, integer *body, doublereal *et, doublereal *ra, doublereal *dec, doublereal *w, doublereal *lambda);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: pckeul_ 14 6 4 7 12 13 7 124 */
/*:ref: bodfnd_ 12 3 4 13 124 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: rpd_ 7 0 */
/*:ref: twopi_ 7 0 */
/*:ref: zzbodbry_ 4 1 4 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: gdpool_ 14 7 13 4 4 4 7 12 124 */
/*:ref: spd_ 7 0 */
/*:ref: j2000_ 7 0 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vdotg_ 7 3 7 7 4 */
/*:ref: halfpi_ 7 0 */
/*:ref: irfrot_ 14 3 4 4 7 */
/*:ref: eul2m_ 14 7 7 7 7 4 4 4 7 */
/*:ref: mxm_ 14 3 7 7 7 */
/*:ref: m2eul_ 14 7 7 4 4 4 7 7 7 */
 
extern logical bodfnd_(void *cspice_state, integer *body, char *item, ftnlen item_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int bodmat_(void *cspice_state, integer *body, doublereal *et, doublereal *tipm);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: tisbod_ 14 5 13 4 7 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int bodn2c_(void *cspice_state, char *name__, integer *code, logical *found, ftnlen name_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzbodn2c_ 14 4 13 4 12 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int bods2c_(void *cspice_state, char *name__, integer *code, logical *found, ftnlen name_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzbodn2c_ 14 4 13 4 12 124 */
/*:ref: beint_ 12 2 13 124 */
/*:ref: nparsi_ 14 6 13 4 13 4 124 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int bodvar_(void *cspice_state, integer *body, char *item, integer *dim, doublereal *values, ftnlen item_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: rtpool_ 14 5 13 4 7 12 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int bodvcd_(void *cspice_state, integer *bodyid, char *item, integer *maxn, integer *dim, doublereal *values, ftnlen item_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: gdpool_ 14 7 13 4 4 4 7 12 124 */
 
extern int bodvrd_(void *cspice_state, char *bodynm, char *item, integer *maxn, integer *dim, doublereal *values, ftnlen bodynm_len, ftnlen item_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: gdpool_ 14 7 13 4 4 4 7 12 124 */
 
extern doublereal brcktd_(void *cspice_state, doublereal *number, doublereal *end1, doublereal *end2);
 
extern integer brckti_(void *cspice_state, integer *number, integer *end1, integer *end2);
 
extern integer bschoc_(void *cspice_state, char *value, integer *ndim, char *array, integer *order, ftnlen value_len, ftnlen array_len);
 
extern integer bschoi_(void *cspice_state, integer *value, integer *ndim, integer *array, integer *order);
 
extern integer bsrchc_(void *cspice_state, char *value, integer *ndim, char *array, ftnlen value_len, ftnlen array_len);
 
extern integer bsrchd_(void *cspice_state, doublereal *value, integer *ndim, doublereal *array);
 
extern integer bsrchi_(void *cspice_state, integer *value, integer *ndim, integer *array);
 
extern integer cardc_(void *cspice_state, char *cell, ftnlen cell_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dechar_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern integer cardd_(void *cspice_state, doublereal *cell);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern integer cardi_(void *cspice_state, integer *cell);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int cgv2el_(void *cspice_state, doublereal *center, doublereal *vec1, doublereal *vec2, doublereal *ellips);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: saelgv_ 14 4 7 7 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern integer chbase_(void *cspice_state);
 
extern int chbder_(void *cspice_state, doublereal *cp, integer *degp, doublereal *x2s, doublereal *x, integer *nderiv, doublereal *partdp, doublereal *dpdxs);
 
extern int chbigr_(void *cspice_state, integer *degp, doublereal *cp, doublereal *x2s, doublereal *x, doublereal *p, doublereal *itgrlp);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
 
extern int chbint_(void *cspice_state, doublereal *cp, integer *degp, doublereal *x2s, doublereal *x, doublereal *p, doublereal *dpdx);
 
extern int chbval_(void *cspice_state, doublereal *cp, integer *degp, doublereal *x2s, doublereal *x, doublereal *p);
 
extern int chckid_(void *cspice_state, char *class__, integer *maxlen, char *id, ftnlen class_len, ftnlen id_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: frstnp_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
 
extern int chgirf_(void *cspice_state, integer *refa, integer *refb, doublereal *rotab, char *name__, integer *index, ftnlen name_len);
extern int irfrot_(void *cspice_state, integer *refa, integer *refb, doublereal *rotab);
extern int irfnum_(void *cspice_state, char *name__, integer *index, ftnlen name_len);
extern int irfnam_(void *cspice_state, integer *index, char *name__, ftnlen name_len);
extern int irfdef_(void *cspice_state, integer *index);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rotate_ 14 3 7 4 7 */
/*:ref: wdcnt_ 4 2 13 124 */
/*:ref: nthwd_ 14 6 13 4 13 4 124 124 */
/*:ref: nparsi_ 14 6 13 4 13 4 124 124 */
/*:ref: nparsd_ 14 6 13 7 13 4 124 124 */
/*:ref: convrt_ 14 6 7 13 13 7 124 124 */
/*:ref: rotmat_ 14 4 7 7 4 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: mxm_ 14 3 7 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: mxmt_ 14 3 7 7 7 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: esrchc_ 4 5 13 4 13 124 124 */
 
extern int ckbsr_(void *cspice_state, char *fname, integer *handle, integer *inst, doublereal *sclkdp, doublereal *tol, logical *needav, doublereal *descr, char *segid, logical *found, ftnlen fname_len, ftnlen segid_len);
extern int cklpf_(void *cspice_state, char *fname, integer *handle, ftnlen fname_len);
extern int ckupf_(void *cspice_state, integer *handle);
extern int ckbss_(void *cspice_state, integer *inst, doublereal *sclkdp, doublereal *tol, logical *needav);
extern int cksns_(void *cspice_state, integer *handle, doublereal *descr, char *segid, logical *found, ftnlen segid_len);
extern int ckhave_(void *cspice_state, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lnktl_ 4 2 4 4 */
/*:ref: lnkfsl_ 14 3 4 4 4 */
/*:ref: lnkini_ 14 2 4 4 */
/*:ref: dafopr_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: dafcls_ 14 1 4 */
/*:ref: lnknxt_ 4 2 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: intmax_ 4 0 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: lnkprv_ 4 2 4 4 */
/*:ref: dpmin_ 7 0 */
/*:ref: dpmax_ 7 0 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: dafbfs_ 14 1 4 */
/*:ref: daffna_ 14 1 12 */
/*:ref: dafgs_ 14 1 7 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: dafbbs_ 14 1 4 */
/*:ref: daffpa_ 14 1 12 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: lnknfn_ 4 1 4 */
/*:ref: lnkan_ 14 2 4 4 */
/*:ref: dafgn_ 14 2 13 124 */
/*:ref: lnkilb_ 14 3 4 4 4 */
/*:ref: lnkila_ 14 3 4 4 4 */
 
extern int ckcls_(void *cspice_state, integer *handle);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafbfs_ 14 1 4 */
/*:ref: daffna_ 14 1 12 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: dafcls_ 14 1 4 */
 
extern int ckcov_(void *cspice_state, char *ck, integer *idcode, logical *needav, char *level, doublereal *tol, char *timsys, doublereal *cover, ftnlen ck_len, ftnlen level_len, ftnlen timsys_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: getfat_ 14 6 13 13 13 124 124 124 */
/*:ref: ckmeta_ 14 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafopr_ 14 3 13 4 124 */
/*:ref: dafbfs_ 14 1 4 */
/*:ref: daffna_ 14 1 12 */
/*:ref: dafgs_ 14 1 7 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: sct2e_ 14 3 4 7 7 */
/*:ref: wninsd_ 14 3 7 7 7 */
/*:ref: zzckcv01_ 14 8 4 4 4 4 7 13 7 124 */
/*:ref: zzckcv02_ 14 8 4 4 4 4 7 13 7 124 */
/*:ref: zzckcv03_ 14 8 4 4 4 4 7 13 7 124 */
/*:ref: zzckcv04_ 14 8 4 4 4 4 7 13 7 124 */
/*:ref: zzckcv05_ 14 9 4 4 4 4 7 7 13 7 124 */
/*:ref: zzckcv06_ 14 9 4 4 4 4 7 7 13 7 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: dafcls_ 14 1 4 */
 
extern int cke01_(void *cspice_state, logical *needav, doublereal *record, doublereal *cmat, doublereal *av, doublereal *clkout);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: q2m_ 14 2 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int cke02_(void *cspice_state, logical *needav, doublereal *record, doublereal *cmat, doublereal *av, doublereal *clkout);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: vequg_ 14 3 7 4 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: axisar_ 14 3 7 7 7 */
/*:ref: q2m_ 14 2 7 7 */
/*:ref: mxmt_ 14 3 7 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int cke03_(void *cspice_state, logical *needav, doublereal *record, doublereal *cmat, doublereal *av, doublereal *clkout);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: q2m_ 14 2 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: mtxm_ 14 3 7 7 7 */
/*:ref: raxisa_ 14 3 7 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: axisar_ 14 3 7 7 7 */
/*:ref: mxmt_ 14 3 7 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
 
extern int cke04_(void *cspice_state, logical *needav, doublereal *record, doublereal *cmat, doublereal *av, doublereal *clkout);
/*:ref: chbval_ 14 5 7 4 7 7 7 */
/*:ref: vhatg_ 14 3 7 4 7 */
/*:ref: q2m_ 14 2 7 7 */
 
extern int cke05_(void *cspice_state, logical *needav, doublereal *record, doublereal *cmat, doublereal *av, doublereal *clkout);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vminug_ 14 3 7 4 7 */
/*:ref: vdistg_ 7 3 7 7 4 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: xpsgip_ 14 3 4 4 7 */
/*:ref: lgrind_ 14 7 4 7 7 7 7 7 7 */
/*:ref: vnormg_ 7 2 7 4 */
/*:ref: vsclg_ 14 4 7 7 4 7 */
/*:ref: vdotg_ 7 3 7 7 4 */
/*:ref: vsubg_ 14 4 7 7 4 7 */
/*:ref: qdq2av_ 14 3 7 7 7 */
/*:ref: vsclip_ 14 2 7 7 */
/*:ref: lgrint_ 7 5 4 7 7 7 7 */
/*:ref: vhatg_ 14 3 7 4 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: hrmint_ 14 7 4 7 7 7 7 7 7 */
/*:ref: q2m_ 14 2 7 7 */
 
extern int cke06_(void *cspice_state, logical *needav, doublereal *record, doublereal *cmat, doublereal *av, doublereal *clkout);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cke05_ 14 5 12 7 7 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int ckfrot_(void *cspice_state, integer *inst, doublereal *et, doublereal *rotate, integer *ref, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ckhave_ 14 1 12 */
/*:ref: ckmeta_ 14 4 4 13 4 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzsclk_ 12 2 4 4 */
/*:ref: sce2c_ 14 3 4 7 7 */
/*:ref: ckbss_ 14 4 4 7 7 12 */
/*:ref: cksns_ 14 5 4 7 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: ckpfs_ 14 9 4 7 7 7 12 7 7 7 12 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: xpose_ 14 2 7 7 */
 
extern int ckfxfm_(void *cspice_state, integer *inst, doublereal *et, doublereal *xform, integer *ref, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ckmeta_ 14 4 4 13 4 124 */
/*:ref: ckhave_ 14 1 12 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzsclk_ 12 2 4 4 */
/*:ref: sce2c_ 14 3 4 7 7 */
/*:ref: ckbss_ 14 4 4 7 7 12 */
/*:ref: cksns_ 14 5 4 7 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: ckpfs_ 14 9 4 7 7 7 12 7 7 7 12 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: rav2xf_ 14 3 7 7 7 */
/*:ref: invstm_ 14 2 7 7 */
 
extern int ckgp_(void *cspice_state, integer *inst, doublereal *sclkdp, doublereal *tol, char *ref, doublereal *cmat, doublereal *clkout, logical *found, ftnlen ref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ckbss_ 14 4 4 7 7 12 */
/*:ref: cksns_ 14 5 4 7 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: ckpfs_ 14 9 4 7 7 7 12 7 7 7 12 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: ckmeta_ 14 4 4 13 4 124 */
/*:ref: sct2e_ 14 3 4 7 7 */
/*:ref: refchg_ 14 4 4 4 7 7 */
/*:ref: mxm_ 14 3 7 7 7 */
/*:ref: moved_ 14 3 7 4 7 */
 
extern int ckgpav_(void *cspice_state, integer *inst, doublereal *sclkdp, doublereal *tol, char *ref, doublereal *cmat, doublereal *av, doublereal *clkout, logical *found, ftnlen ref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ckbss_ 14 4 4 7 7 12 */
/*:ref: cksns_ 14 5 4 7 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: ckpfs_ 14 9 4 7 7 7 12 7 7 7 12 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: ckmeta_ 14 4 4 13 4 124 */
/*:ref: sct2e_ 14 3 4 7 7 */
/*:ref: frmchg_ 14 4 4 4 7 7 */
/*:ref: xf2rav_ 14 3 7 7 7 */
/*:ref: mxm_ 14 3 7 7 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: mtxv_ 14 3 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
 
extern int ckgr01_(void *cspice_state, integer *handle, doublereal *descr, integer *recno, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
 
extern int ckgr02_(void *cspice_state, integer *handle, doublereal *descr, integer *recno, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: cknr02_ 14 3 4 7 4 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: moved_ 14 3 7 4 7 */
 
extern int ckgr03_(void *cspice_state, integer *handle, doublereal *descr, integer *recno, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
 
extern int ckgr04_(void *cspice_state, integer *handle, doublereal *descr, integer *recno, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: cknr04_ 14 3 4 7 4 */
/*:ref: sgfpkt_ 14 6 4 7 4 4 7 4 */
/*:ref: zzck4d2i_ 14 4 7 4 7 4 */
 
extern int ckgr05_(void *cspice_state, integer *handle, doublereal *descr, integer *recno, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
 
extern int ckgr06_(void *cspice_state, integer *handle, doublereal *descr, integer *msno, integer *recno, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: failed_ 12 0 */
 
extern int ckmeta_(void *cspice_state, integer *ckid, char *meta, integer *idcode, ftnlen meta_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: clearc_ 14 3 4 13 124 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: bschoi_ 4 4 4 4 4 4 */
/*:ref: zzcvpool_ 14 4 13 4 12 124 */
/*:ref: gipool_ 14 7 13 4 4 4 4 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: cvpool_ 14 3 13 12 124 */
/*:ref: dwpool_ 14 2 13 124 */
/*:ref: orderi_ 14 3 4 4 4 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: swpool_ 14 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern int ckmp06_(void *cspice_state, integer *handle, doublereal *descr, integer *msno, doublereal *rate, integer *subtyp, integer *winsiz, integer *nrec, doublereal *ivlbds, doublereal *lstepc);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: failed_ 12 0 */
 
extern int cknm06_(void *cspice_state, integer *handle, doublereal *descr, integer *nmini);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: failed_ 12 0 */
 
extern int cknr01_(void *cspice_state, integer *handle, doublereal *descr, integer *nrec);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
 
extern int cknr02_(void *cspice_state, integer *handle, doublereal *descr, integer *nrec);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int cknr03_(void *cspice_state, integer *handle, doublereal *descr, integer *nrec);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
 
extern int cknr04_(void *cspice_state, integer *handle, doublereal *descr, integer *nrec);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sgmeta_ 14 4 4 7 4 4 */
 
extern int cknr05_(void *cspice_state, integer *handle, doublereal *descr, integer *nrec);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
 
extern int ckobj_(void *cspice_state, char *ck, integer *ids, ftnlen ck_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: getfat_ 14 6 13 13 13 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafopr_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafbfs_ 14 1 4 */
/*:ref: daffna_ 14 1 12 */
/*:ref: dafgs_ 14 1 7 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: insrti_ 14 2 4 4 */
/*:ref: dafcls_ 14 1 4 */
 
extern int ckopn_(void *cspice_state, char *name__, char *ifname, integer *ncomch, integer *handle, ftnlen name_len, ftnlen ifname_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafonw_ 14 10 13 13 4 4 13 4 4 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int ckpfs_(void *cspice_state, integer *handle, doublereal *descr, doublereal *sclkdp, doublereal *tol, logical *needav, doublereal *cmat, doublereal *av, doublereal *clkout, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: ckr01_ 14 7 4 7 7 7 12 7 12 */
/*:ref: cke01_ 14 5 12 7 7 7 7 */
/*:ref: ckr02_ 14 6 4 7 7 7 7 12 */
/*:ref: cke02_ 14 5 12 7 7 7 7 */
/*:ref: ckr03_ 14 7 4 7 7 7 12 7 12 */
/*:ref: cke03_ 14 5 12 7 7 7 7 */
/*:ref: ckr04_ 14 7 4 7 7 7 12 7 12 */
/*:ref: cke04_ 14 5 12 7 7 7 7 */
/*:ref: ckr05_ 14 7 4 7 7 7 12 7 12 */
/*:ref: cke05_ 14 5 12 7 7 7 7 */
/*:ref: ckr06_ 14 7 4 7 7 7 12 7 12 */
/*:ref: cke06_ 14 5 12 7 7 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int ckr01_(void *cspice_state, integer *handle, doublereal *descr, doublereal *sclkdp, doublereal *tol, logical *needav, doublereal *record, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: lstled_ 4 3 7 4 7 */
/*:ref: lstcld_ 4 3 7 4 7 */
 
extern int ckr02_(void *cspice_state, integer *handle, doublereal *descr, doublereal *sclkdp, doublereal *tol, doublereal *record, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: lstled_ 4 3 7 4 7 */
/*:ref: vequg_ 14 3 7 4 7 */
 
extern int ckr03_(void *cspice_state, integer *handle, doublereal *descr, doublereal *sclkdp, doublereal *tol, logical *needav, doublereal *record, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: failed_ 12 0 */
/*:ref: lstltd_ 4 3 7 4 7 */
/*:ref: lstled_ 4 3 7 4 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: dpmax_ 7 0 */
 
extern int ckr04_(void *cspice_state, integer *handle, doublereal *descr, doublereal *sclkdp, doublereal *tol, logical *needav, doublereal *record, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: cknr04_ 14 3 4 7 4 */
/*:ref: sgfrvi_ 14 6 4 7 7 7 4 12 */
/*:ref: failed_ 12 0 */
/*:ref: sgfpkt_ 14 6 4 7 4 4 7 4 */
/*:ref: zzck4d2i_ 14 4 7 4 7 4 */
 
extern int ckr05_(void *cspice_state, integer *handle, doublereal *descr, doublereal *sclkdp, doublereal *tol, logical *needav, doublereal *record, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: brcktd_ 7 3 7 7 7 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: failed_ 12 0 */
/*:ref: odd_ 12 1 4 */
/*:ref: lstltd_ 4 3 7 4 7 */
/*:ref: lstled_ 4 3 7 4 7 */
/*:ref: dpmax_ 7 0 */
/*:ref: moved_ 14 3 7 4 7 */
 
extern int ckr06_(void *cspice_state, integer *handle, doublereal *descr, doublereal *sclkdp, doublereal *tol, logical *needav, doublereal *record, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: touchl_ 12 1 12 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: brcktd_ 7 3 7 7 7 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: failed_ 12 0 */
/*:ref: lstled_ 4 3 7 4 7 */
/*:ref: lstltd_ 4 3 7 4 7 */
/*:ref: odd_ 12 1 4 */
 
extern int ckw01_(void *cspice_state, integer *handle, doublereal *begtim, doublereal *endtim, integer *inst, char *ref, logical *avflag, char *segid, integer *nrec, doublereal *sclkdp, doublereal *quats, doublereal *avvs, ftnlen ref_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: vzerog_ 12 2 7 4 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern int ckw02_(void *cspice_state, integer *handle, doublereal *begtim, doublereal *endtim, integer *inst, char *ref, char *segid, integer *nrec, doublereal *start, doublereal *stop, doublereal *quats, doublereal *avvs, doublereal *rates, ftnlen ref_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: vzerog_ 12 2 7 4 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern int ckw03_(void *cspice_state, integer *handle, doublereal *begtim, doublereal *endtim, integer *inst, char *ref, logical *avflag, char *segid, integer *nrec, doublereal *sclkdp, doublereal *quats, doublereal *avvs, integer *nints, doublereal *starts, ftnlen ref_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: vzerog_ 12 2 7 4 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern int ckw04a_(void *cspice_state, integer *handle, integer *npkts, integer *pktsiz, doublereal *pktdat, doublereal *sclkdp);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzck4i2d_ 14 4 4 4 7 7 */
/*:ref: sgwvpk_ 14 6 4 4 4 7 4 7 */
 
extern int ckw04b_(void *cspice_state, integer *handle, doublereal *begtim, integer *inst, char *ref, logical *avflag, char *segid, ftnlen ref_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: sgbwvs_ 14 7 4 7 13 4 7 4 124 */
 
extern int ckw04e_(void *cspice_state, integer *handle, doublereal *endtim);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sgwes_ 14 1 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafbbs_ 14 1 4 */
/*:ref: daffpa_ 14 1 12 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: dafgs_ 14 1 7 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: dafrs_ 14 1 7 */
 
extern int ckw05_(void *cspice_state, integer *handle, integer *subtyp, integer *degree, doublereal *begtim, doublereal *endtim, integer *inst, char *ref, logical *avflag, char *segid, integer *n, doublereal *sclkdp, doublereal *packts, doublereal *rate, integer *nints, doublereal *starts, ftnlen ref_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: bsrchd_ 4 3 7 4 7 */
/*:ref: vzerog_ 12 2 7 4 */
/*:ref: odd_ 12 1 4 */
/*:ref: lstltd_ 4 3 7 4 7 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern int ckw06_(void *cspice_state, integer *handle, integer *inst, char *ref, logical *avflag, doublereal *first, doublereal *last, char *segid, integer *nmini, integer *npkts, integer *subtps, integer *degres, doublereal *packts, doublereal *rates, doublereal *sclkdp, doublereal *ivlbds, logical *sellst, ftnlen ref_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: odd_ 12 1 4 */
/*:ref: vzerog_ 12 2 7 4 */
/*:ref: even_ 12 1 4 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: vminug_ 14 3 7 4 7 */
/*:ref: vdistg_ 7 3 7 7 4 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern int clearc_(void *cspice_state, integer *ndim, char *array, ftnlen array_len);
 
extern int cleard_(void *cspice_state, integer *ndim, doublereal *array);
 
extern int cleari_(void *cspice_state, integer *ndim, integer *array);
 
extern doublereal clight_(void *cspice_state);
 
extern int cmprss_(void *cspice_state, char *delim, integer *n, char *input, char *output, ftnlen delim_len, ftnlen input_len, ftnlen output_len);
 
extern int conics_(void *cspice_state, doublereal *elts, doublereal *et, doublereal *state);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vscl_ 14 3 7 7 7 */
/*:ref: twopi_ 7 0 */
/*:ref: prop2b_ 14 4 7 7 7 7 */
 
extern int convrt_(void *cspice_state, doublereal *x, char *in, char *out, doublereal *y, ftnlen in_len, ftnlen out_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dpr_ 7 0 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int copyc_(void *cspice_state, char *cell, char *copy, ftnlen cell_len, ftnlen copy_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: sizec_ 4 2 13 124 */
/*:ref: lastpc_ 4 2 13 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: excess_ 14 3 4 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern int copyd_(void *cspice_state, doublereal *cell, doublereal *copy);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: sized_ 4 1 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: excess_ 14 3 4 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int copyi_(void *cspice_state, integer *cell, integer *copy);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: sizei_ 4 1 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: excess_ 14 3 4 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern integer countc_(void *cspice_state, integer *unit, integer *bline, integer *eline, char *line, ftnlen line_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: astrip_ 14 8 13 13 13 13 124 124 124 124 */
 
extern integer cpos_(void *cspice_state, char *str, char *chars, integer *start, ftnlen str_len, ftnlen chars_len);
 
extern integer cposr_(void *cspice_state, char *str, char *chars, integer *start, ftnlen str_len, ftnlen chars_len);
 
extern int cyacip_(void *cspice_state, integer *nelt, char *dir, integer *ncycle, char *array, ftnlen dir_len, ftnlen array_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: nbwid_ 4 3 13 4 124 */
/*:ref: gcd_ 4 2 4 4 */
 
extern int cyadip_(void *cspice_state, integer *nelt, char *dir, integer *ncycle, doublereal *array, ftnlen dir_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: gcd_ 4 2 4 4 */
 
extern int cyaiip_(void *cspice_state, integer *nelt, char *dir, integer *ncycle, integer *array, ftnlen dir_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: gcd_ 4 2 4 4 */
 
extern int cyclac_(void *cspice_state, char *array, integer *nelt, char *dir, integer *ncycle, char *out, ftnlen array_len, ftnlen dir_len, ftnlen out_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: movec_ 14 5 13 4 13 124 124 */
/*:ref: nbwid_ 4 3 13 4 124 */
/*:ref: gcd_ 4 2 4 4 */
 
extern int cyclad_(void *cspice_state, doublereal *array, integer *nelt, char *dir, integer *ncycle, doublereal *out, ftnlen dir_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: gcd_ 4 2 4 4 */
 
extern int cyclai_(void *cspice_state, integer *array, integer *nelt, char *dir, integer *ncycle, integer *out, ftnlen dir_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: gcd_ 4 2 4 4 */
 
extern int cyclec_(void *cspice_state, char *instr, char *dir, integer *ncycle, char *outstr, ftnlen instr_len, ftnlen dir_len, ftnlen outstr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: gcd_ 4 2 4 4 */
 
extern int cyllat_(void *cspice_state, doublereal *r__, doublereal *longc, doublereal *z__, doublereal *radius, doublereal *long__, doublereal *lat);
 
extern int cylrec_(void *cspice_state, doublereal *r__, doublereal *long__, doublereal *z__, doublereal *rectan);
 
extern int cylsph_(void *cspice_state, doublereal *r__, doublereal *longc, doublereal *z__, doublereal *radius, doublereal *colat, doublereal *long__);
 
extern doublereal dacosh_(void *cspice_state, doublereal *x);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern doublereal dacosn_(void *cspice_state, doublereal *arg, doublereal *tol);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int dafa2b_(void *cspice_state, char *ascii, char *binary, integer *resv, ftnlen ascii_len, ftnlen binary_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: txtopr_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: daft2b_ 14 4 4 13 4 124 */
 
extern int dafac_(void *cspice_state, integer *handle, integer *n, char *buffer, ftnlen buffer_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafsih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: dafrfr_ 14 8 4 4 4 13 4 4 4 124 */
/*:ref: cpos_ 4 5 13 13 4 124 124 */
/*:ref: ncpos_ 4 5 13 13 4 124 124 */
/*:ref: dafarr_ 14 2 4 4 */
 
extern int dafah_(void *cspice_state, char *fname, char *ftype, integer *nd, integer *ni, char *ifname, integer *resv, integer *handle, integer *unit, integer *fhset, char *access, ftnlen fname_len, ftnlen ftype_len, ftnlen ifname_len, ftnlen access_len);
extern int dafopr_(void *cspice_state, char *fname, integer *handle, ftnlen fname_len);
extern int dafopw_(void *cspice_state, char *fname, integer *handle, ftnlen fname_len);
extern int dafonw_(void *cspice_state, char *fname, char *ftype, integer *nd, integer *ni, char *ifname, integer *resv, integer *handle, ftnlen fname_len, ftnlen ftype_len, ftnlen ifname_len);
extern int dafopn_(void *cspice_state, char *fname, integer *nd, integer *ni, char *ifname, integer *resv, integer *handle, ftnlen fname_len, ftnlen ifname_len);
extern int dafcls_(void *cspice_state, integer *handle);
extern int dafhsf_(void *cspice_state, integer *handle, integer *nd, integer *ni);
extern int dafhlu_(void *cspice_state, integer *handle, integer *unit);
extern int dafluh_(void *cspice_state, integer *unit, integer *handle);
extern int dafhfn_(void *cspice_state, integer *handle, char *fname, ftnlen fname_len);
extern int daffnh_(void *cspice_state, char *fname, integer *handle, ftnlen fname_len);
extern int dafhof_(void *cspice_state, integer *fhset);
extern int dafsih_(void *cspice_state, integer *handle, char *access, ftnlen access_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ssizei_ 14 2 4 4 */
/*:ref: zzddhopn_ 14 7 13 13 13 4 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: zzdafgfr_ 14 11 4 13 4 4 13 4 4 4 12 124 124 */
/*:ref: zzddhcls_ 14 4 4 13 12 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: insrti_ 14 2 4 4 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: ltrim_ 4 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: dafrwa_ 14 3 4 4 4 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: zzplatfm_ 14 4 13 13 124 124 */
/*:ref: zzdafnfr_ 14 12 4 13 4 4 13 4 4 4 13 124 124 124 */
/*:ref: removi_ 14 2 4 4 */
/*:ref: zzddhluh_ 14 3 4 4 12 */
/*:ref: zzddhnfo_ 14 7 4 13 4 4 4 12 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: zzddhfnh_ 14 4 13 4 12 124 */
/*:ref: copyi_ 14 2 4 4 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: elemi_ 12 2 4 4 */
 
extern int dafana_(void *cspice_state, integer *handle, doublereal *sum, char *name__, doublereal *data, integer *n, ftnlen name_len);
extern int dafbna_(void *cspice_state, integer *handle, doublereal *sum, char *name__, ftnlen name_len);
extern int dafada_(void *cspice_state, doublereal *data, integer *n);
extern int dafena_(void *cspice_state);
extern int dafcad_(void *cspice_state, integer *handle);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafsih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: ssizei_ 14 2 4 4 */
/*:ref: dafrfr_ 14 8 4 4 4 13 4 4 4 124 */
/*:ref: dafhof_ 14 1 4 */
/*:ref: elemi_ 12 2 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: dafhsf_ 14 3 4 4 4 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: dafhfn_ 14 3 4 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: dafwda_ 14 4 4 4 4 7 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: dafrdr_ 14 6 4 4 4 4 7 12 */
/*:ref: dafrcr_ 14 4 4 4 13 124 */
/*:ref: dafwdr_ 14 3 4 4 7 */
/*:ref: dafwcr_ 14 4 4 4 13 124 */
/*:ref: dafarw_ 14 3 4 4 4 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: dafrwa_ 14 3 4 4 4 */
/*:ref: dafwfr_ 14 8 4 4 4 13 4 4 4 124 */
 
extern int dafarr_(void *cspice_state, integer *handle, integer *resv);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafsih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafrfr_ 14 8 4 4 4 13 4 4 4 124 */
/*:ref: dafarw_ 14 3 4 4 4 */
/*:ref: dafwdr_ 14 3 4 4 7 */
/*:ref: dafrdr_ 14 6 4 4 4 4 7 12 */
/*:ref: dafrcr_ 14 4 4 4 13 124 */
/*:ref: dafwcr_ 14 4 4 4 13 124 */
/*:ref: dafwfr_ 14 8 4 4 4 13 4 4 4 124 */
/*:ref: dafbfs_ 14 1 4 */
/*:ref: daffna_ 14 1 12 */
/*:ref: dafgs_ 14 1 7 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: dafws_ 14 1 7 */
 
extern int dafb2a_(void *cspice_state, char *binary, char *ascii, ftnlen binary_len, ftnlen ascii_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: txtopn_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafb2t_ 14 3 13 4 124 */
 
extern int dafb2t_(void *cspice_state, char *binary, integer *text, ftnlen binary_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafopr_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: dafrfr_ 14 8 4 4 4 13 4 4 4 124 */
/*:ref: dafcls_ 14 1 4 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: dafbfs_ 14 1 4 */
/*:ref: daffna_ 14 1 12 */
/*:ref: dafgs_ 14 1 7 */
/*:ref: dafgn_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
 
extern int dafbt_(void *cspice_state, char *binfil, integer *xfrlun, ftnlen binfil_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafopr_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: dafrfr_ 14 8 4 4 4 13 4 4 4 124 */
/*:ref: wrenci_ 14 3 4 4 4 */
/*:ref: dafbfs_ 14 1 4 */
/*:ref: daffna_ 14 1 12 */
/*:ref: dafgs_ 14 1 7 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: dafgn_ 14 2 13 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: wrencd_ 14 3 4 4 7 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: dafcls_ 14 1 4 */
 
extern int dafdc_(void *cspice_state, integer *handle);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafsih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafrfr_ 14 8 4 4 4 13 4 4 4 124 */
/*:ref: dafrrr_ 14 2 4 4 */
 
extern int dafec_(void *cspice_state, integer *handle, integer *bufsiz, integer *n, char *buffer, logical *done, ftnlen buffer_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafsih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: dafrfr_ 14 8 4 4 4 13 4 4 4 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: cpos_ 4 5 13 13 4 124 124 */
/*:ref: ncpos_ 4 5 13 13 4 124 124 */
 
extern int daffa_(void *cspice_state, integer *handle, doublereal *sum, char *name__, logical *found, ftnlen name_len);
extern int dafbfs_(void *cspice_state, integer *handle);
extern int daffna_(void *cspice_state, logical *found);
extern int dafbbs_(void *cspice_state, integer *handle);
extern int daffpa_(void *cspice_state, logical *found);
extern int dafgs_(void *cspice_state, doublereal *sum);
extern int dafgn_(void *cspice_state, char *name__, ftnlen name_len);
extern int dafgh_(void *cspice_state, integer *handle);
extern int dafrs_(void *cspice_state, doublereal *sum);
extern int dafrn_(void *cspice_state, char *name__, ftnlen name_len);
extern int dafws_(void *cspice_state, doublereal *sum);
extern int dafcs_(void *cspice_state, integer *handle);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafsih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: ssizei_ 14 2 4 4 */
/*:ref: dafhof_ 14 1 4 */
/*:ref: elemi_ 12 2 4 4 */
/*:ref: dafrfr_ 14 8 4 4 4 13 4 4 4 124 */
/*:ref: dafgsr_ 14 6 4 4 4 4 7 12 */
/*:ref: dafhfn_ 14 3 4 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: dafhsf_ 14 3 4 4 4 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: dafrcr_ 14 4 4 4 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: dafwdr_ 14 3 4 4 7 */
/*:ref: dafwcr_ 14 4 4 4 13 124 */
 
extern int dafgda_(void *cspice_state, integer *handle, integer *begin, integer *end, doublereal *data);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafarw_ 14 3 4 4 4 */
/*:ref: dafgdr_ 14 6 4 4 4 4 7 12 */
/*:ref: cleard_ 14 2 4 7 */
 
extern int dafps_(void *cspice_state, integer *nd, integer *ni, doublereal *dc, integer *ic, doublereal *sum);
extern int dafus_(void *cspice_state, doublereal *sum, integer *nd, integer *ni, doublereal *dc, integer *ic);
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: movei_ 14 3 4 4 4 */
 
extern int dafra_(void *cspice_state, integer *handle, integer *iorder, integer *n);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: isordv_ 12 2 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: dafbfs_ 14 1 4 */
/*:ref: daffna_ 14 1 12 */
/*:ref: failed_ 12 0 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: dafgs_ 14 1 7 */
/*:ref: dafgn_ 14 2 13 124 */
/*:ref: dafws_ 14 1 7 */
/*:ref: dafrn_ 14 2 13 124 */
 
extern int dafrcr_(void *cspice_state, integer *handle, integer *recno, char *crec, ftnlen crec_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafsih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
 
extern int dafrda_(void *cspice_state, integer *handle, integer *begin, integer *end, doublereal *data);
/*:ref: return_ 12 0 */
/*:ref: zzddhisn_ 14 3 4 12 12 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: dafarw_ 14 3 4 4 4 */
/*:ref: dafrdr_ 14 6 4 4 4 4 7 12 */
/*:ref: cleard_ 14 2 4 7 */
 
extern int dafrfr_(void *cspice_state, integer *handle, integer *nd, integer *ni, char *ifname, integer *fward, integer *bward, integer *free, ftnlen ifname_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafsih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzdafgfr_ 14 11 4 13 4 4 13 4 4 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern int dafrrr_(void *cspice_state, integer *handle, integer *resv);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafsih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafrfr_ 14 8 4 4 4 13 4 4 4 124 */
/*:ref: dafrdr_ 14 6 4 4 4 4 7 12 */
/*:ref: dafarw_ 14 3 4 4 4 */
/*:ref: dafwdr_ 14 3 4 4 7 */
/*:ref: dafrcr_ 14 4 4 4 13 124 */
/*:ref: dafwcr_ 14 4 4 4 13 124 */
/*:ref: dafwfr_ 14 8 4 4 4 13 4 4 4 124 */
/*:ref: dafbfs_ 14 1 4 */
/*:ref: daffna_ 14 1 12 */
/*:ref: dafgs_ 14 1 7 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: dafws_ 14 1 7 */
 
extern int dafrwa_(void *cspice_state, integer *recno, integer *wordno, integer *addr__);
extern int dafarw_(void *cspice_state, integer *addr__, integer *recno, integer *wordno);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int dafrwd_(void *cspice_state, integer *handle, integer *recno, integer *begin, integer *end, doublereal *drec, doublereal *data, logical *found, integer *reads, integer *reqs);
extern int dafgdr_(void *cspice_state, integer *handle, integer *recno, integer *begin, integer *end, doublereal *data, logical *found);
extern int dafgsr_(void *cspice_state, integer *handle, integer *recno, integer *begin, integer *end, doublereal *data, logical *found);
extern int dafrdr_(void *cspice_state, integer *handle, integer *recno, integer *begin, integer *end, doublereal *data, logical *found);
extern int dafwdr_(void *cspice_state, integer *handle, integer *recno, doublereal *drec);
extern int dafnrr_(void *cspice_state, integer *reads, integer *reqs);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: minai_ 14 4 4 4 4 4 */
/*:ref: zzdafgdr_ 14 4 4 4 7 12 */
/*:ref: failed_ 12 0 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: zzddhrcm_ 14 3 4 4 4 */
/*:ref: dafhsf_ 14 3 4 4 4 */
/*:ref: zzdafgsr_ 14 6 4 4 4 4 7 12 */
/*:ref: zzddhisn_ 14 3 4 12 12 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern int daft2b_(void *cspice_state, integer *text, char *binary, integer *resv, ftnlen binary_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: idw2at_ 14 6 13 13 13 124 124 124 */
/*:ref: dafopn_ 14 8 13 4 4 13 4 4 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafcls_ 14 1 4 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: dafena_ 14 0 */
 
extern int daftb_(void *cspice_state, integer *xfrlun, char *binfil, ftnlen binfil_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: idw2at_ 14 6 13 13 13 124 124 124 */
/*:ref: rdenci_ 14 3 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: dafonw_ 14 10 13 13 4 4 13 4 4 124 124 124 */
/*:ref: dafopn_ 14 8 13 4 4 13 4 4 124 124 */
/*:ref: nextwd_ 14 6 13 13 13 124 124 124 */
/*:ref: nparsi_ 14 6 13 4 13 4 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: rdencd_ 14 3 4 4 7 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
/*:ref: dafcls_ 14 1 4 */
 
extern int dafwcr_(void *cspice_state, integer *handle, integer *recno, char *crec, ftnlen crec_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: dafsih_ 14 3 4 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int dafwda_(void *cspice_state, integer *handle, integer *begin, integer *end, doublereal *data);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafarw_ 14 3 4 4 4 */
/*:ref: dafrdr_ 14 6 4 4 4 4 7 12 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: dafwdr_ 14 3 4 4 7 */
 
extern int dafwfr_(void *cspice_state, integer *handle, integer *nd, integer *ni, char *ifname, integer *fward, integer *bward, integer *free, ftnlen ifname_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafsih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern int dasa2l_(void *cspice_state, integer *handle, integer *type__, integer *addrss, integer *clbase, integer *clsize, integer *recno, integer *wordno);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: dasham_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: dashfs_ 14 9 4 4 4 4 4 4 4 4 4 */
/*:ref: dasrri_ 14 5 4 4 4 4 4 */
 
extern int dasac_(void *cspice_state, integer *handle, integer *n, char *buffer, ftnlen buffer_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dassih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: dasrfr_ 14 9 4 13 13 4 4 4 4 124 124 */
/*:ref: dasacr_ 14 2 4 4 */
/*:ref: dasioc_ 14 6 13 4 4 13 124 124 */
/*:ref: daswfr_ 14 9 4 13 13 4 4 4 4 124 124 */
 
extern int dasacr_(void *cspice_state, integer *handle, integer *n);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dassih_ 14 3 4 13 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: daswbr_ 14 1 4 */
/*:ref: dashfs_ 14 9 4 4 4 4 4 4 4 4 4 */
/*:ref: maxai_ 14 4 4 4 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: dasioi_ 14 5 13 4 4 4 124 */
/*:ref: dasioc_ 14 6 13 4 4 13 124 124 */
/*:ref: dasiod_ 14 5 13 4 4 7 124 */
/*:ref: dasufs_ 14 9 4 4 4 4 4 4 4 4 4 */
 
extern int dasacu_(void *cspice_state, integer *comlun, char *begmrk, char *endmrk, logical *insbln, integer *handle, ftnlen begmrk_len, ftnlen endmrk_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dassih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrfr_ 14 9 4 13 13 4 4 4 4 124 124 */
/*:ref: getlun_ 14 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: readln_ 14 4 4 13 12 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: readla_ 14 6 4 4 4 13 12 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: writla_ 14 4 4 13 4 124 */
/*:ref: dasac_ 14 4 4 4 13 124 */
 
extern int dasadc_(void *cspice_state, integer *handle, integer *n, integer *bpos, integer *epos, char *data, ftnlen data_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dashfs_ 14 9 4 4 4 4 4 4 4 4 4 */
/*:ref: dasa2l_ 14 7 4 4 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: daswrc_ 14 4 4 4 13 124 */
/*:ref: dasurc_ 14 6 4 4 4 4 13 124 */
/*:ref: dascud_ 14 3 4 4 4 */
 
extern int dasadd_(void *cspice_state, integer *handle, integer *n, doublereal *data);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dashfs_ 14 9 4 4 4 4 4 4 4 4 4 */
/*:ref: dasa2l_ 14 7 4 4 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: daswrd_ 14 3 4 4 7 */
/*:ref: dasurd_ 14 5 4 4 4 4 7 */
/*:ref: dascud_ 14 3 4 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int dasadi_(void *cspice_state, integer *handle, integer *n, integer *data);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dashfs_ 14 9 4 4 4 4 4 4 4 4 4 */
/*:ref: dasa2l_ 14 7 4 4 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: daswri_ 14 3 4 4 4 */
/*:ref: dasuri_ 14 5 4 4 4 4 4 */
/*:ref: dascud_ 14 3 4 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int dasbt_(void *cspice_state, char *binfil, integer *xfrlun, ftnlen binfil_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dasopr_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrfr_ 14 9 4 13 13 4 4 4 4 124 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: dascls_ 14 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: wrenci_ 14 3 4 4 4 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: dasioc_ 14 6 13 4 4 13 124 124 */
/*:ref: wrencc_ 14 4 4 4 13 124 */
/*:ref: daslla_ 14 4 4 4 4 4 */
/*:ref: dasrdc_ 14 7 4 4 4 4 4 13 124 */
/*:ref: dasrdd_ 14 4 4 4 4 7 */
/*:ref: wrencd_ 14 3 4 4 7 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
 
extern int dascls_(void *cspice_state, integer *handle);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ssizei_ 14 2 4 4 */
/*:ref: dashof_ 14 1 4 */
/*:ref: elemi_ 12 2 4 4 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasham_ 14 3 4 13 124 */
/*:ref: daswbr_ 14 1 4 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: dassdr_ 14 1 4 */
/*:ref: dasllc_ 14 1 4 */
 
extern int dascud_(void *cspice_state, integer *handle, integer *type__, integer *nwords);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dashfs_ 14 9 4 4 4 4 4 4 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: maxai_ 14 4 4 4 4 4 */
/*:ref: dasuri_ 14 5 4 4 4 4 4 */
/*:ref: dasufs_ 14 9 4 4 4 4 4 4 4 4 4 */
/*:ref: dasrri_ 14 5 4 4 4 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: daswri_ 14 3 4 4 4 */
 
extern int dasdc_(void *cspice_state, integer *handle);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dassih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrfr_ 14 9 4 13 13 4 4 4 4 124 124 */
/*:ref: dasrcr_ 14 2 4 4 */
/*:ref: daswfr_ 14 9 4 13 13 4 4 4 4 124 124 */
 
extern int dasec_(void *cspice_state, integer *handle, integer *bufsiz, integer *n, char *buffer, logical *done, ftnlen buffer_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dassih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: dasrfr_ 14 9 4 13 13 4 4 4 4 124 124 */
/*:ref: dasioc_ 14 6 13 4 4 13 124 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
 
extern int dasecu_(void *cspice_state, integer *handle, integer *comlun, logical *comnts);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dassih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasec_ 14 6 4 4 4 13 12 124 */
/*:ref: writla_ 14 4 4 13 4 124 */
 
extern int dasfm_(void *cspice_state, char *fname, char *ftype, char *ifname, integer *handle, integer *unit, integer *free, integer *lastla, integer *lastrc, integer *lastwd, integer *nresvr, integer *nresvc, integer *ncomr, integer *ncomc, integer *fhset, char *access, ftnlen fname_len, ftnlen ftype_len, ftnlen ifname_len, ftnlen access_len);
extern int dasopr_(void *cspice_state, char *fname, integer *handle, ftnlen fname_len);
extern int dasopw_(void *cspice_state, char *fname, integer *handle, ftnlen fname_len);
extern int dasonw_(void *cspice_state, char *fname, char *ftype, char *ifname, integer *ncomr, integer *handle, ftnlen fname_len, ftnlen ftype_len, ftnlen ifname_len);
extern int dasopn_(void *cspice_state, char *fname, char *ifname, integer *handle, ftnlen fname_len, ftnlen ifname_len);
extern int dasops_(void *cspice_state, integer *handle);
extern int dasllc_(void *cspice_state, integer *handle);
extern int dashfs_(void *cspice_state, integer *handle, integer *nresvr, integer *nresvc, integer *ncomr, integer *ncomc, integer *free, integer *lastla, integer *lastrc, integer *lastwd);
extern int dasufs_(void *cspice_state, integer *handle, integer *nresvr, integer *nresvc, integer *ncomr, integer *ncomc, integer *free, integer *lastla, integer *lastrc, integer *lastwd);
extern int dashlu_(void *cspice_state, integer *handle, integer *unit);
extern int dasluh_(void *cspice_state, integer *unit, integer *handle);
extern int dashfn_(void *cspice_state, integer *handle, char *fname, ftnlen fname_len);
extern int dasfnh_(void *cspice_state, char *fname, integer *handle, ftnlen fname_len);
extern int dashof_(void *cspice_state, integer *fhset);
extern int dassih_(void *cspice_state, integer *handle, char *access, ftnlen access_len);
extern int dasham_(void *cspice_state, integer *handle, char *access, ftnlen access_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lnkini_ 14 2 4 4 */
/*:ref: ssizei_ 14 2 4 4 */
/*:ref: zzddhopn_ 14 7 13 13 13 4 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: lnknxt_ 4 2 4 4 */
/*:ref: lnknfn_ 4 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: zzdasrfr_ 14 9 4 13 13 4 4 4 4 124 124 */
/*:ref: lnkan_ 14 2 4 4 */
/*:ref: lnkilb_ 14 3 4 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: zzdasgri_ 14 3 4 4 4 */
/*:ref: maxai_ 14 4 4 4 4 4 */
/*:ref: insrti_ 14 2 4 4 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: dasioi_ 14 5 13 4 4 4 124 */
/*:ref: ltrim_ 4 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: zzplatfm_ 14 4 13 13 124 124 */
/*:ref: zzdasnfr_ 14 11 4 13 13 4 4 4 4 13 124 124 124 */
/*:ref: zzddhcls_ 14 4 4 13 12 124 */
/*:ref: lnkfsl_ 14 3 4 4 4 */
/*:ref: removi_ 14 2 4 4 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: zzddhluh_ 14 3 4 4 12 */
/*:ref: zzddhfnh_ 14 4 13 4 12 124 */
/*:ref: copyi_ 14 2 4 4 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: elemi_ 12 2 4 4 */
 
extern doublereal dasine_(void *cspice_state, doublereal *arg, doublereal *tol);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int dasioc_(void *cspice_state, char *action, integer *unit, integer *recno, char *record, ftnlen action_len, ftnlen record_len);
/*:ref: return_ 12 0 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
 
extern int dasiod_(void *cspice_state, char *action, integer *unit, integer *recno, doublereal *record, ftnlen action_len);
/*:ref: return_ 12 0 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
 
extern int dasioi_(void *cspice_state, char *action, integer *unit, integer *recno, integer *record, ftnlen action_len);
/*:ref: return_ 12 0 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
 
extern int daslla_(void *cspice_state, integer *handle, integer *lastc, integer *lastd, integer *lasti);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dashfs_ 14 9 4 4 4 4 4 4 4 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int dasrcr_(void *cspice_state, integer *handle, integer *n);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dassih_ 14 3 4 13 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: daswbr_ 14 1 4 */
/*:ref: dashfs_ 14 9 4 4 4 4 4 4 4 4 4 */
/*:ref: maxai_ 14 4 4 4 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: dasioi_ 14 5 13 4 4 4 124 */
/*:ref: dasioc_ 14 6 13 4 4 13 124 124 */
/*:ref: dasiod_ 14 5 13 4 4 7 124 */
/*:ref: dasufs_ 14 9 4 4 4 4 4 4 4 4 4 */
 
extern int dasrdc_(void *cspice_state, integer *handle, integer *first, integer *last, integer *bpos, integer *epos, char *data, ftnlen data_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasa2l_ 14 7 4 4 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: dasrrc_ 14 6 4 4 4 4 13 124 */
 
extern int dasrdd_(void *cspice_state, integer *handle, integer *first, integer *last, doublereal *data);
/*:ref: dasa2l_ 14 7 4 4 4 4 4 4 4 */
/*:ref: dasrrd_ 14 5 4 4 4 4 7 */
/*:ref: failed_ 12 0 */
 
extern int dasrdi_(void *cspice_state, integer *handle, integer *first, integer *last, integer *data);
/*:ref: dasa2l_ 14 7 4 4 4 4 4 4 4 */
/*:ref: dasrri_ 14 5 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
 
extern int dasrfr_(void *cspice_state, integer *handle, char *idword, char *ifname, integer *nresvr, integer *nresvc, integer *ncomr, integer *ncomc, ftnlen idword_len, ftnlen ifname_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzdasrfr_ 14 9 4 13 13 4 4 4 4 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int dasrwr_(void *cspice_state, integer *handle, integer *recno, char *recc, doublereal *recd, integer *reci, integer *first, integer *last, doublereal *datad, integer *datai, char *datac, ftnlen recc_len, ftnlen datac_len);
extern int dasrrd_(void *cspice_state, integer *handle, integer *recno, integer *first, integer *last, doublereal *datad);
extern int dasrri_(void *cspice_state, integer *handle, integer *recno, integer *first, integer *last, integer *datai);
extern int dasrrc_(void *cspice_state, integer *handle, integer *recno, integer *first, integer *last, char *datac, ftnlen datac_len);
extern int daswrd_(void *cspice_state, integer *handle, integer *recno, doublereal *recd);
extern int daswri_(void *cspice_state, integer *handle, integer *recno, integer *reci);
extern int daswrc_(void *cspice_state, integer *handle, integer *recno, char *recc, ftnlen recc_len);
extern int dasurd_(void *cspice_state, integer *handle, integer *recno, integer *first, integer *last, doublereal *datad);
extern int dasuri_(void *cspice_state, integer *handle, integer *recno, integer *first, integer *last, integer *datai);
extern int dasurc_(void *cspice_state, integer *handle, integer *recno, integer *first, integer *last, char *datac, ftnlen datac_len);
extern int daswbr_(void *cspice_state, integer *handle);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lnkini_ 14 2 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: lnkxsl_ 14 3 4 4 4 */
/*:ref: lnkilb_ 14 3 4 4 4 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: lnktl_ 4 2 4 4 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: dasiod_ 14 5 13 4 4 7 124 */
/*:ref: lnkan_ 14 2 4 4 */
/*:ref: zzdasgrd_ 14 3 4 4 7 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: dasioi_ 14 5 13 4 4 4 124 */
/*:ref: zzdasgri_ 14 3 4 4 4 */
/*:ref: dasioc_ 14 6 13 4 4 13 124 124 */
/*:ref: dassih_ 14 3 4 13 124 */
/*:ref: lnkfsl_ 14 3 4 4 4 */
 
extern int dassdr_(void *cspice_state, integer *handle);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dassih_ 14 3 4 13 124 */
/*:ref: dashlu_ 14 2 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: daswbr_ 14 1 4 */
/*:ref: dasops_ 14 1 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: dashfs_ 14 9 4 4 4 4 4 4 4 4 4 */
/*:ref: maxai_ 14 4 4 4 4 4 */
/*:ref: dasrri_ 14 5 4 4 4 4 4 */
/*:ref: dasadi_ 14 3 4 4 4 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: dasioc_ 14 6 13 4 4 13 124 124 */
/*:ref: dasiod_ 14 5 13 4 4 7 124 */
/*:ref: dasioi_ 14 5 13 4 4 4 124 */
/*:ref: dasufs_ 14 9 4 4 4 4 4 4 4 4 4 */
/*:ref: dasllc_ 14 1 4 */
 
extern int dastb_(void *cspice_state, integer *xfrlun, char *binfil, ftnlen binfil_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: idw2at_ 14 6 13 13 13 124 124 124 */
/*:ref: dasonw_ 14 8 13 13 13 4 4 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: daswfr_ 14 9 4 13 13 4 4 4 4 124 124 */
/*:ref: dascls_ 14 1 4 */
/*:ref: rdenci_ 14 3 4 4 4 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: dasacr_ 14 2 4 4 */
/*:ref: nextwd_ 14 6 13 13 13 124 124 124 */
/*:ref: nparsi_ 14 6 13 4 13 4 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: rdencc_ 14 4 4 4 13 124 */
/*:ref: dasioc_ 14 6 13 4 4 13 124 124 */
/*:ref: dasadc_ 14 6 4 4 4 4 13 124 */
/*:ref: rdencd_ 14 3 4 4 7 */
/*:ref: dasadd_ 14 3 4 4 7 */
/*:ref: dasadi_ 14 3 4 4 4 */
 
extern int dasudc_(void *cspice_state, integer *handle, integer *first, integer *last, integer *bpos, integer *epos, char *data, ftnlen data_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: daslla_ 14 4 4 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasa2l_ 14 7 4 4 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: dasurc_ 14 6 4 4 4 4 13 124 */
 
extern int dasudd_(void *cspice_state, integer *handle, integer *first, integer *last, doublereal *data);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: daslla_ 14 4 4 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasa2l_ 14 7 4 4 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: dasurd_ 14 5 4 4 4 4 7 */
 
extern int dasudi_(void *cspice_state, integer *handle, integer *first, integer *last, integer *data);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: daslla_ 14 4 4 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasa2l_ 14 7 4 4 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: dasuri_ 14 5 4 4 4 4 4 */
 
extern int daswfr_(void *cspice_state, integer *handle, char *idword, char *ifname, integer *nresvr, integer *nresvc, integer *ncomr, integer *ncomc, ftnlen idword_len, ftnlen ifname_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dassih_ 14 3 4 13 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: dashfs_ 14 9 4 4 4 4 4 4 4 4 4 */
/*:ref: dasufs_ 14 9 4 4 4 4 4 4 4 4 4 */
 
extern doublereal datanh_(void *cspice_state, doublereal *x);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern doublereal dcbrt_(void *cspice_state, doublereal *x);
 
extern int dcyldr_(void *cspice_state, doublereal *x, doublereal *y, doublereal *z__, doublereal *jacobi);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vpack_ 14 4 7 7 7 7 */
/*:ref: reccyl_ 14 4 7 7 7 7 */
/*:ref: drdcyl_ 14 4 7 7 7 7 */
/*:ref: invort_ 14 2 7 7 */
 
extern int delfil_(void *cspice_state, char *filnam, ftnlen filnam_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: getlun_ 14 1 4 */
 
extern int deltet_(void *cspice_state, doublereal *epoch, char *eptype, doublereal *delta, ftnlen eptype_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: gdpool_ 14 7 13 4 4 4 7 12 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
 
extern doublereal det_(void *cspice_state, doublereal *m1);
 
extern int dgeodr_(void *cspice_state, doublereal *x, doublereal *y, doublereal *z__, doublereal *re, doublereal *f, doublereal *jacobi);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vpack_ 14 4 7 7 7 7 */
/*:ref: recgeo_ 14 6 7 7 7 7 7 7 */
/*:ref: drdgeo_ 14 6 7 7 7 7 7 7 */
/*:ref: invort_ 14 2 7 7 */
 
extern doublereal dhfa_(void *cspice_state, doublereal *state, doublereal *bodyr);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: unorm_ 14 3 7 7 7 */
/*:ref: vzero_ 12 1 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: errdp_ 14 3 13 7 124 */
 
extern int diags2_(void *cspice_state, doublereal *symmat, doublereal *diag, doublereal *rotate);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rquad_ 14 5 7 7 7 7 7 */
/*:ref: vhatg_ 14 3 7 4 7 */
 
extern int diffc_(void *cspice_state, char *a, char *b, char *c__, ftnlen a_len, ftnlen b_len, ftnlen c_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: sizec_ 4 2 13 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: excess_ 14 3 4 13 124 */
 
extern int diffd_(void *cspice_state, doublereal *a, doublereal *b, doublereal *c__);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: sized_ 4 1 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: excess_ 14 3 4 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int diffi_(void *cspice_state, integer *a, integer *b, integer *c__);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: sizei_ 4 1 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: excess_ 14 3 4 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int dlabbs_(void *cspice_state, integer *handle, integer *descr, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int dlabfs_(void *cspice_state, integer *handle, integer *descr, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int dlabns_(void *cspice_state, integer *handle);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dassih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: daslla_ 14 4 4 4 4 4 */
/*:ref: filli_ 14 3 4 4 4 */
/*:ref: dasadi_ 14 3 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
 
extern int dlaens_(void *cspice_state, integer *handle);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: daslla_ 14 4 4 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int dlafns_(void *cspice_state, integer *handle, integer *descr, integer *nxtdsc, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
 
extern int dlafps_(void *cspice_state, integer *handle, integer *descr, integer *prvdsc, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
 
extern int dlaopn_(void *cspice_state, char *fname, char *ftype, char *ifname, integer *ncomch, integer *handle, ftnlen fname_len, ftnlen ftype_len, ftnlen ifname_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasonw_ 14 8 13 13 13 4 4 124 124 124 */
/*:ref: dasadi_ 14 3 4 4 4 */
 
extern logical dlassg_(void *cspice_state, integer *han1, integer *han2, integer *dsc1, integer *dsc2);
 
extern int dlatdr_(void *cspice_state, doublereal *x, doublereal *y, doublereal *z__, doublereal *jacobi);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vpack_ 14 4 7 7 7 7 */
/*:ref: reclat_ 14 4 7 7 7 7 */
/*:ref: drdlat_ 14 4 7 7 7 7 */
/*:ref: invort_ 14 2 7 7 */
 
extern int dnearp_(void *cspice_state, doublereal *state, doublereal *a, doublereal *b, doublereal *c__, doublereal *dnear, doublereal *dalt, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: nearpt_ 14 6 7 7 7 7 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: unorm_ 14 3 7 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vtmv_ 7 3 7 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
 
extern int dp2hx_(void *cspice_state, doublereal *number, char *string, integer *length, ftnlen string_len);
/*:ref: int2hx_ 14 4 4 13 4 124 */
 
extern int dpfmt_(void *cspice_state, doublereal *x, char *pictur, char *str, ftnlen pictur_len, ftnlen str_len);
/*:ref: pos_ 4 5 13 13 4 124 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzvststr_ 14 4 7 13 4 124 */
/*:ref: dpstr_ 14 4 7 4 13 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: rjust_ 14 4 13 13 124 124 */
/*:ref: zzvsbstr_ 14 6 4 4 12 13 12 124 */
/*:ref: ncpos_ 4 5 13 13 4 124 124 */
 
extern int dpgrdr_(void *cspice_state, char *body, doublereal *x, doublereal *y, doublereal *z__, doublereal *re, doublereal *f, doublereal *jacobi, ftnlen body_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: gcpool_ 14 8 13 4 4 4 13 12 124 124 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: plnsns_ 4 1 4 */
/*:ref: dgeodr_ 14 6 7 7 7 7 7 7 */
 
extern doublereal dpr_(void *cspice_state);
 
extern int dpspce_(void *cspice_state, doublereal *time, doublereal *geophs, doublereal *elems, doublereal *state);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: twopi_ 7 0 */
/*:ref: halfpi_ 7 0 */
/*:ref: zzdpinit_ 14 6 7 7 7 7 7 7 */
/*:ref: zzdpsec_ 14 9 7 7 7 7 7 7 7 7 7 */
/*:ref: zzdpper_ 14 6 7 7 7 7 7 7 */
/*:ref: latrec_ 14 4 7 7 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int dpstr_(void *cspice_state, doublereal *x, integer *sigdig, char *string, ftnlen string_len);
/*:ref: intstr_ 14 3 4 13 124 */
 
extern int dpstrf_(void *cspice_state, doublereal *x, integer *sigdig, char *format, char *string, ftnlen format_len, ftnlen string_len);
/*:ref: dpstr_ 14 4 7 4 13 124 */
/*:ref: zzvststr_ 14 4 7 13 4 124 */
/*:ref: zzvsbstr_ 14 6 4 4 12 13 12 124 */
 
extern int drdcyl_(void *cspice_state, doublereal *r__, doublereal *long__, doublereal *z__, doublereal *jacobi);
 
extern int drdgeo_(void *cspice_state, doublereal *long__, doublereal *lat, doublereal *alt, doublereal *re, doublereal *f, doublereal *jacobi);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int drdlat_(void *cspice_state, doublereal *r__, doublereal *long__, doublereal *lat, doublereal *jacobi);
 
extern int drdpgr_(void *cspice_state, char *body, doublereal *lon, doublereal *lat, doublereal *alt, doublereal *re, doublereal *f, doublereal *jacobi, ftnlen body_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: gcpool_ 14 8 13 4 4 4 13 12 124 124 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: plnsns_ 4 1 4 */
/*:ref: drdgeo_ 14 6 7 7 7 7 7 7 */
 
extern int drdsph_(void *cspice_state, doublereal *r__, doublereal *colat, doublereal *long__, doublereal *jacobi);
 
extern int drotat_(void *cspice_state, doublereal *angle, integer *iaxis, doublereal *dmout);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int dskb02_(void *cspice_state, integer *handle, integer *dladsc, integer *nv, integer *np, integer *nvxtot, doublereal *vtxbds, doublereal *voxsiz, doublereal *voxori, integer *vgrext, integer *cgscal, integer *vtxnpl, integer *voxnpt, integer *voxnpl);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: dasrdd_ 14 4 4 4 4 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int dskcls_(void *cspice_state, integer *handle, logical *optmiz);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dascls_ 14 1 4 */
/*:ref: dasham_ 14 3 4 13 124 */
/*:ref: daswbr_ 14 1 4 */
/*:ref: dasllc_ 14 1 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int dskd02_(void *cspice_state, integer *handle, integer *dladsc, integer *item, integer *start, integer *room, integer *n, doublereal *values);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: dasrdd_ 14 4 4 4 4 7 */
 
extern int dskgd_(void *cspice_state, integer *handle, integer *dladsc, doublereal *dskdsc);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdd_ 14 4 4 4 4 7 */
 
extern int dski02_(void *cspice_state, integer *handle, integer *dladsc, integer *item, integer *start, integer *room, integer *n, integer *values);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
 
extern int dskmi2_(void *cspice_state, integer *nv, doublereal *vrtces, integer *np, integer *plates, doublereal *finscl, integer *corscl, integer *worksz, integer *voxpsz, integer *voxlsz, logical *makvtl, integer *spxisz, integer *work, doublereal *spaixd, integer *spaixi);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzmkspin_ 14 19 4 4 7 7 4 4 4 4 4 4 7 7 4 4 4 4 4 7 4 */
/*:ref: failed_ 12 0 */
/*:ref: zzvrtplt_ 14 9 4 4 4 4 4 4 4 4 4 */
 
extern int dskn02_(void *cspice_state, integer *handle, integer *dladsc, integer *plid, doublereal *normal);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dskgd_ 14 3 4 4 7 */
/*:ref: dskz02_ 14 4 4 4 4 4 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dski02_ 14 7 4 4 4 4 4 4 4 */
/*:ref: dskd02_ 14 7 4 4 4 4 4 4 7 */
/*:ref: failed_ 12 0 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: ucrss_ 14 3 7 7 7 */
 
extern int dskobj_(void *cspice_state, char *dsk, integer *bodids, ftnlen dsk_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: getfat_ 14 6 13 13 13 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasopr_ 14 3 13 4 124 */
/*:ref: dlabfs_ 14 3 4 4 12 */
/*:ref: failed_ 12 0 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: dskgd_ 14 3 4 4 7 */
/*:ref: cardi_ 4 1 4 */
/*:ref: sizei_ 4 1 4 */
/*:ref: dskcls_ 14 2 4 12 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: appndi_ 14 2 4 4 */
/*:ref: dlafns_ 14 4 4 4 4 12 */
/*:ref: validi_ 14 3 4 4 4 */
/*:ref: dascls_ 14 1 4 */
 
extern int dskopn_(void *cspice_state, char *fname, char *ifname, integer *ncomch, integer *handle, ftnlen fname_len, ftnlen ifname_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dlaopn_ 14 8 13 13 13 4 4 124 124 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int dskp02_(void *cspice_state, integer *handle, integer *dladsc, integer *start, integer *room, integer *n, integer *plates);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dskgd_ 14 3 4 4 7 */
/*:ref: dskz02_ 14 4 4 4 4 4 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dski02_ 14 7 4 4 4 4 4 4 4 */
 
extern int dskrb2_(void *cspice_state, integer *nv, doublereal *vrtces, integer *np, integer *plates, integer *corsys, doublereal *corpar, doublereal *mncor3, doublereal *mxcor3);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: dpmax_ 7 0 */
/*:ref: pltnp_ 14 6 7 7 7 7 7 7 */
/*:ref: dpmin_ 7 0 */
/*:ref: recgeo_ 14 6 7 7 7 7 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vlcom3_ 14 7 7 7 7 7 7 7 7 */
/*:ref: vdist_ 7 2 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern int dsksrf_(void *cspice_state, char *dsk, integer *bodyid, integer *srfids, ftnlen dsk_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: getfat_ 14 6 13 13 13 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasopr_ 14 3 13 4 124 */
/*:ref: dlabfs_ 14 3 4 4 12 */
/*:ref: failed_ 12 0 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: dskgd_ 14 3 4 4 7 */
/*:ref: cardi_ 4 1 4 */
/*:ref: sizei_ 4 1 4 */
/*:ref: dskcls_ 14 2 4 12 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: appndi_ 14 2 4 4 */
/*:ref: dlafns_ 14 4 4 4 4 12 */
/*:ref: validi_ 14 3 4 4 4 */
/*:ref: dascls_ 14 1 4 */
 
extern int dsktol_(void *cspice_state, integer *keywrd, doublereal *dpval);
extern int dskgtl_(void *cspice_state, integer *keywrd, doublereal *dpval);
extern int dskstl_(void *cspice_state, integer *keywrd, doublereal *dpval);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: return_ 12 0 */
/*:ref: errch_ 14 4 13 13 124 124 */
 
extern int dskv02_(void *cspice_state, integer *handle, integer *dladsc, integer *start, integer *room, integer *n, doublereal *vrtces);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dskgd_ 14 3 4 4 7 */
/*:ref: dskz02_ 14 4 4 4 4 4 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dskd02_ 14 7 4 4 4 4 4 4 7 */
 
extern int dskw02_(void *cspice_state, integer *handle, integer *center, integer *surfid, integer *dclass, char *frame, integer *corsys, doublereal *corpar, doublereal *mncor1, doublereal *mxcor1, doublereal *mncor2, doublereal *mxcor2, doublereal *mncor3, doublereal *mxcor3, doublereal *first, doublereal *last, integer *nv, doublereal *vrtces, integer *np, integer *plates, doublereal *spaixd, integer *spaixi, ftnlen frame_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: dpr_ 7 0 */
/*:ref: twopi_ 7 0 */
/*:ref: halfpi_ 7 0 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: dlabns_ 14 1 4 */
/*:ref: failed_ 12 0 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: dasadd_ 14 3 4 4 7 */
/*:ref: dasadi_ 14 3 4 4 4 */
/*:ref: dlaens_ 14 1 4 */
 
extern int dskx02_(void *cspice_state, integer *handle, integer *dladsc, doublereal *vertex, doublereal *raydir, integer *plid, doublereal *xpt, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dpmax_ 7 0 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: vzero_ 12 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: dskb02_ 14 13 4 4 4 4 4 7 7 7 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: dski02_ 14 7 4 4 4 4 4 4 4 */
/*:ref: dskgd_ 14 3 4 4 7 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: dskgtl_ 14 2 4 7 */
/*:ref: zzraybox_ 14 6 7 7 7 7 7 12 */
/*:ref: zztogrid_ 14 4 7 7 7 7 */
/*:ref: xdda_ 14 6 7 7 4 4 4 4 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vlcom3_ 14 7 7 7 7 7 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: filli_ 14 3 4 4 4 */
/*:ref: orderi_ 14 3 4 4 4 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: dskd02_ 14 7 4 4 4 4 4 4 7 */
/*:ref: vsubg_ 14 4 7 7 4 7 */
/*:ref: pltexp_ 14 3 7 7 7 */
/*:ref: insang_ 14 6 7 7 7 7 12 7 */
/*:ref: pltnrm_ 14 4 7 7 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: zzinvelt_ 14 7 7 4 7 7 7 4 12 */
 
extern int dskxsi_(void *cspice_state, logical *pri, char *target, integer *nsurf, integer *srflst, doublereal *et, char *fixref, doublereal *vertex, doublereal *raydir, integer *maxd, integer *maxi, doublereal *xpt, integer *handle, integer *dladsc, doublereal *dskdsc, doublereal *dc, integer *ic, logical *found, ftnlen target_len, ftnlen fixref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: zzpctrck_ 14 2 4 12 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: zzsbfxri_ 14 14 4 4 4 7 4 7 7 7 4 4 7 7 4 12 */
 
extern int dskxv_(void *cspice_state, logical *pri, char *target, integer *nsurf, integer *srflst, doublereal *et, char *fixref, integer *nrays, doublereal *vtxarr, doublereal *dirarr, doublereal *xptarr, logical *fndarr, ftnlen target_len, ftnlen fixref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: zzpctrck_ 14 2 4 12 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: zzsbfxr_ 14 9 4 4 4 7 4 7 7 7 12 */
 
extern int dskz02_(void *cspice_state, integer *handle, integer *dladsc, integer *nv, integer *np);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dski02_ 14 7 4 4 4 4 4 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int dsphdr_(void *cspice_state, doublereal *x, doublereal *y, doublereal *z__, doublereal *jacobi);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vpack_ 14 4 7 7 7 7 */
/*:ref: recsph_ 14 4 7 7 7 7 */
/*:ref: drdsph_ 14 4 7 7 7 7 */
/*:ref: invort_ 14 2 7 7 */
 
extern int ducrss_(void *cspice_state, doublereal *s1, doublereal *s2, doublereal *sout);
/*:ref: vsclg_ 14 4 7 7 4 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: dvcrss_ 14 3 7 7 7 */
/*:ref: dvhat_ 14 2 7 7 */
 
extern int dvcrss_(void *cspice_state, doublereal *s1, doublereal *s2, doublereal *sout);
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
 
extern doublereal dvdot_(void *cspice_state, doublereal *s1, doublereal *s2);
 
extern int dvhat_(void *cspice_state, doublereal *s1, doublereal *sout);
/*:ref: unorm_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vperp_ 14 3 7 7 7 */
/*:ref: vsclip_ 14 2 7 7 */
 
extern doublereal dvnorm_(void *cspice_state, doublereal *state);
/*:ref: vnorm_ 7 1 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vdot_ 7 2 7 7 */
 
extern doublereal dvsep_(void *cspice_state, doublereal *s1, doublereal *s2);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dvhat_ 14 2 7 7 */
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: vzero_ 12 1 7 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: zzdiv_ 7 2 7 7 */
 
extern int dxtrct_(void *cspice_state, char *keywd, integer *maxwds, char *string, integer *nfound, integer *parsed, doublereal *values, ftnlen keywd_len, ftnlen string_len);
/*:ref: wdindx_ 4 4 13 13 124 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: nblen_ 4 2 13 124 */
/*:ref: fndnwd_ 14 5 13 4 4 4 124 */
/*:ref: nparsd_ 14 6 13 7 13 4 124 124 */
 
extern int edlimb_(void *cspice_state, doublereal *a, doublereal *b, doublereal *c__, doublereal *viewpt, doublereal *limb);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vscl_ 14 3 7 7 7 */
/*:ref: nvc2pl_ 14 3 7 7 7 */
/*:ref: inedpl_ 14 6 7 7 7 7 7 12 */
/*:ref: vsclg_ 14 4 7 7 4 7 */
/*:ref: moved_ 14 3 7 4 7 */
 
extern int ednmpt_(void *cspice_state, doublereal *a, doublereal *b, doublereal *c__, doublereal *normal, doublereal *point);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: touchd_ 7 1 7 */
/*:ref: vzero_ 12 1 7 */
 
extern int edpnt_(void *cspice_state, doublereal *p, doublereal *a, doublereal *b, doublereal *c__, doublereal *ep);
/*:ref: failed_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vzero_ 12 1 7 */
/*:ref: touchd_ 7 1 7 */
 
extern int edterm_(void *cspice_state, char *trmtyp, char *source, char *target, doublereal *et, char *fixref, char *abcorr, char *obsrvr, integer *npts, doublereal *trgepc, doublereal *obspos, doublereal *trmpts, ftnlen trmtyp_len, ftnlen source_len, ftnlen target_len, ftnlen fixref_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: spkezp_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: zzcorepc_ 14 5 13 7 7 7 124 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: zzedterm_ 14 9 13 7 7 7 7 7 4 7 124 */
 
extern int ekacec_(void *cspice_state, integer *handle, integer *segno, integer *recno, char *column, integer *nvals, char *cvals, logical *isnull, ftnlen column_len, ftnlen cvals_len);
/*:ref: zzeksdsc_ 14 3 4 4 4 */
/*:ref: zzekcdsc_ 14 5 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzektrdp_ 14 4 4 4 4 4 */
/*:ref: zzekad03_ 14 7 4 4 4 4 13 12 124 */
/*:ref: zzekad06_ 14 8 4 4 4 4 4 13 12 124 */
 
extern int ekaced_(void *cspice_state, integer *handle, integer *segno, integer *recno, char *column, integer *nvals, doublereal *dvals, logical *isnull, ftnlen column_len);
/*:ref: zzeksdsc_ 14 3 4 4 4 */
/*:ref: zzekcdsc_ 14 5 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzektrdp_ 14 4 4 4 4 4 */
/*:ref: zzekad02_ 14 6 4 4 4 4 7 12 */
/*:ref: zzekad05_ 14 7 4 4 4 4 4 7 12 */
 
extern int ekacei_(void *cspice_state, integer *handle, integer *segno, integer *recno, char *column, integer *nvals, integer *ivals, logical *isnull, ftnlen column_len);
/*:ref: zzeksdsc_ 14 3 4 4 4 */
/*:ref: zzekcdsc_ 14 5 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzektrdp_ 14 4 4 4 4 4 */
/*:ref: zzekad01_ 14 6 4 4 4 4 4 12 */
/*:ref: zzekad04_ 14 7 4 4 4 4 4 4 12 */
 
extern int ekaclc_(void *cspice_state, integer *handle, integer *segno, char *column, char *cvals, integer *entszs, logical *nlflgs, integer *rcptrs, integer *wkindx, ftnlen column_len, ftnlen cvals_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzeksdsc_ 14 3 4 4 4 */
/*:ref: zzekcdsc_ 14 5 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzekac03_ 14 8 4 4 4 13 12 4 4 124 */
/*:ref: zzekac06_ 14 7 4 4 4 13 4 12 124 */
/*:ref: zzekac09_ 14 7 4 4 4 13 12 4 124 */
 
extern int ekacld_(void *cspice_state, integer *handle, integer *segno, char *column, doublereal *dvals, integer *entszs, logical *nlflgs, integer *rcptrs, integer *wkindx, ftnlen column_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzeksdsc_ 14 3 4 4 4 */
/*:ref: zzekcdsc_ 14 5 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzekac02_ 14 7 4 4 4 7 12 4 4 */
/*:ref: zzekac05_ 14 6 4 4 4 7 4 12 */
/*:ref: zzekac08_ 14 6 4 4 4 7 12 4 */
 
extern int ekacli_(void *cspice_state, integer *handle, integer *segno, char *column, integer *ivals, integer *entszs, logical *nlflgs, integer *rcptrs, integer *wkindx, ftnlen column_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzeksdsc_ 14 3 4 4 4 */
/*:ref: zzekcdsc_ 14 5 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzekac01_ 14 7 4 4 4 4 12 4 4 */
/*:ref: zzekac04_ 14 6 4 4 4 4 4 12 */
/*:ref: zzekac07_ 14 6 4 4 4 4 12 4 */
 
extern int ekappr_(void *cspice_state, integer *handle, integer *segno, integer *recno);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekmloc_ 14 4 4 4 4 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: ekinsr_ 14 3 4 4 4 */
 
extern int ekbseg_(void *cspice_state, integer *handle, char *tabnam, integer *ncols, char *cnames, char *decls, integer *segno, ftnlen tabnam_len, ftnlen cnames_len, ftnlen decls_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ssizei_ 14 2 4 4 */
/*:ref: lxdfid_ 14 1 4 */
/*:ref: chckid_ 14 5 13 4 13 124 124 */
/*:ref: lxidnt_ 14 6 4 13 4 4 4 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzekpdec_ 14 3 13 4 124 */
/*:ref: zzekstyp_ 4 2 4 4 */
/*:ref: zzekbs01_ 14 8 4 13 4 13 4 4 124 124 */
/*:ref: zzekbs02_ 14 8 4 13 4 13 4 4 124 124 */
 
extern int ekcls_(void *cspice_state, integer *handle);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dascls_ 14 1 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int ekdelr_(void *cspice_state, integer *handle, integer *segno, integer *recno);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekmloc_ 14 4 4 4 4 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: zzekrbck_ 14 6 13 4 4 4 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzektrdp_ 14 4 4 4 4 4 */
/*:ref: zzekde01_ 14 4 4 4 4 4 */
/*:ref: zzekde02_ 14 4 4 4 4 4 */
/*:ref: zzekde03_ 14 4 4 4 4 4 */
/*:ref: zzekde04_ 14 4 4 4 4 4 */
/*:ref: zzekde05_ 14 4 4 4 4 4 */
/*:ref: zzekde06_ 14 4 4 4 4 4 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: dashlu_ 14 2 4 4 */
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: zzekpgpg_ 14 4 4 4 4 4 */
/*:ref: zzekglnk_ 14 4 4 4 4 4 */
/*:ref: zzekslnk_ 14 4 4 4 4 4 */
/*:ref: zzekdps_ 14 4 4 4 4 4 */
/*:ref: zzektrdl_ 14 3 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
 
extern int ekffld_(void *cspice_state, integer *handle, integer *segno, integer *rcptrs);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzeksdsc_ 14 3 4 4 4 */
/*:ref: zzekff01_ 14 3 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int ekfind_(void *cspice_state, char *query, integer *nmrows, logical *error, char *errmsg, ftnlen query_len, ftnlen errmsg_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekqini_ 14 6 4 4 4 13 7 124 */
/*:ref: zzekscan_ 14 17 13 4 4 4 4 4 4 4 7 13 4 4 12 13 124 124 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekpars_ 14 19 13 4 4 4 4 4 7 13 4 4 4 13 7 12 13 124 124 124 124 */
/*:ref: zzeknres_ 14 9 13 4 13 12 13 4 124 124 124 */
/*:ref: zzektres_ 14 10 13 4 13 7 12 13 4 124 124 124 */
/*:ref: zzeksemc_ 14 9 13 4 13 12 13 4 124 124 124 */
/*:ref: eksrch_ 14 8 4 13 7 4 12 13 124 124 */
 
extern int ekifld_(void *cspice_state, integer *handle, char *tabnam, integer *ncols, integer *nrows, char *cnames, char *decls, integer *segno, integer *rcptrs, ftnlen tabnam_len, ftnlen cnames_len, ftnlen decls_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ekbseg_ 14 9 4 13 4 13 13 4 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: zzekmloc_ 14 4 4 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzeksdsc_ 14 3 4 4 4 */
/*:ref: zzekif01_ 14 3 4 4 4 */
/*:ref: zzekif02_ 14 2 4 4 */
 
extern int ekinsr_(void *cspice_state, integer *handle, integer *segno, integer *recno);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekmloc_ 14 4 4 4 4 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: filli_ 14 3 4 4 4 */
/*:ref: ekshdw_ 14 2 4 12 */
/*:ref: zzekpgbs_ 14 3 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzekaps_ 14 6 4 4 4 12 4 4 */
/*:ref: zzektrin_ 14 4 4 4 4 4 */
/*:ref: zzekrbck_ 14 6 13 4 4 4 4 124 */
 
extern integer eknseg_(void *cspice_state, integer *handle);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzektrbs_ 4 1 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: zzektrsz_ 4 2 4 4 */
 
extern int ekopn_(void *cspice_state, char *fname, char *ifname, integer *ncomch, integer *handle, ftnlen fname_len, ftnlen ifname_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasonw_ 14 8 13 13 13 4 4 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: zzekpgin_ 14 1 4 */
/*:ref: zzekpgan_ 14 4 4 4 4 4 */
/*:ref: zzektrit_ 14 2 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
 
extern int ekopr_(void *cspice_state, char *fname, integer *handle, ftnlen fname_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dasopr_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
 
extern int ekops_(void *cspice_state, integer *handle);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dasops_ 14 1 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekpgin_ 14 1 4 */
/*:ref: zzekpgan_ 14 4 4 4 4 4 */
/*:ref: zzektrit_ 14 2 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
 
extern int ekopw_(void *cspice_state, char *fname, integer *handle, ftnlen fname_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dasopw_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
 
extern int ekpsel_(void *cspice_state, char *query, integer *n, integer *xbegs, integer *xends, char *xtypes, char *xclass, char *tabs, char *cols, logical *error, char *errmsg, ftnlen query_len, ftnlen xtypes_len, ftnlen xclass_len, ftnlen tabs_len, ftnlen cols_len, ftnlen errmsg_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekqini_ 14 6 4 4 4 13 7 124 */
/*:ref: zzekencd_ 14 10 13 4 13 7 12 13 4 124 124 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekreqi_ 14 4 4 13 4 124 */
/*:ref: zzekqsel_ 14 12 4 13 4 4 4 13 4 13 4 124 124 124 */
/*:ref: zzekqtab_ 14 8 4 13 4 13 13 124 124 124 */
/*:ref: ekcii_ 14 6 13 4 13 4 124 124 */
 
extern int ekqmgr_(void *cspice_state, integer *cindex, integer *elment, char *eqryc, doublereal *eqryd, integer *eqryi, char *fname, integer *row, integer *selidx, char *column, integer *handle, integer *n, char *table, integer *attdsc, integer *ccount, logical *found, integer *nelt, integer *nmrows, logical *semerr, char *errmsg, char *cdata, doublereal *ddata, integer *idata, logical *null, ftnlen eqryc_len, ftnlen fname_len, ftnlen column_len, ftnlen table_len, ftnlen errmsg_len, ftnlen cdata_len);
extern int eklef_(void *cspice_state, char *fname, integer *handle, ftnlen fname_len);
extern int ekuef_(void *cspice_state, integer *handle);
extern int ekntab_(void *cspice_state, integer *n);
extern int ektnam_(void *cspice_state, integer *n, char *table, ftnlen table_len);
extern int ekccnt_(void *cspice_state, char *table, integer *ccount, ftnlen table_len);
extern int ekcii_(void *cspice_state, char *table, integer *cindex, char *column, integer *attdsc, ftnlen table_len, ftnlen column_len);
extern int eksrch_(void *cspice_state, integer *eqryi, char *eqryc, doublereal *eqryd, integer *nmrows, logical *semerr, char *errmsg, ftnlen eqryc_len, ftnlen errmsg_len);
extern int eknelt_(void *cspice_state, integer *selidx, integer *row, integer *nelt);
extern int ekgc_(void *cspice_state, integer *selidx, integer *row, integer *elment, char *cdata, logical *null, logical *found, ftnlen cdata_len);
extern int ekgd_(void *cspice_state, integer *selidx, integer *row, integer *elment, doublereal *ddata, logical *null, logical *found);
extern int ekgi_(void *cspice_state, integer *selidx, integer *row, integer *elment, integer *idata, logical *null, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lnkini_ 14 2 4 4 */
/*:ref: ekopr_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: dascls_ 14 1 4 */
/*:ref: lnknxt_ 4 2 4 4 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: lnknfn_ 4 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: ekcls_ 14 1 4 */
/*:ref: eknseg_ 4 1 4 */
/*:ref: lnkan_ 14 2 4 4 */
/*:ref: lnkilb_ 14 3 4 4 4 */
/*:ref: zzeksinf_ 14 8 4 4 13 4 13 4 124 124 */
/*:ref: ssizec_ 14 3 4 13 124 */
/*:ref: movec_ 14 5 13 4 13 124 124 */
/*:ref: validc_ 14 4 4 4 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: lnkfsl_ 14 3 4 4 4 */
/*:ref: lnktl_ 4 2 4 4 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: zzekreqi_ 14 4 4 13 4 124 */
/*:ref: zzekqtab_ 14 8 4 13 4 13 13 124 124 124 */
/*:ref: ssizei_ 14 2 4 4 */
/*:ref: appndc_ 14 4 13 13 124 124 */
/*:ref: appndi_ 14 2 4 4 */
/*:ref: zzekstop_ 14 1 4 */
/*:ref: zzeksdec_ 14 1 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: zzekqcnj_ 14 3 4 4 4 */
/*:ref: zzekqcon_ 14 24 4 13 7 4 4 13 4 13 4 4 13 4 13 4 4 4 4 7 4 124 124 124 124 124 */
/*:ref: zzekspsh_ 14 2 4 4 */
/*:ref: zzeksupd_ 14 3 4 4 4 */
/*:ref: zzekkey_ 14 20 4 4 4 4 4 4 4 4 13 4 4 7 4 12 4 4 4 4 12 124 */
/*:ref: zzekixlk_ 14 4 4 4 4 4 */
/*:ref: zzekrplk_ 14 4 4 4 4 4 */
/*:ref: zzekrmch_ 12 15 4 12 4 4 4 4 4 4 4 13 4 4 7 4 124 */
/*:ref: zzekvmch_ 12 13 4 12 4 4 4 4 4 4 4 4 4 4 4 */
/*:ref: zzekjsqz_ 14 1 4 */
/*:ref: zzekjoin_ 14 18 4 4 4 12 4 4 4 4 4 4 4 4 4 4 4 4 4 4 */
/*:ref: zzeksrd_ 14 3 4 4 4 */
/*:ref: zzekweed_ 14 3 4 4 4 */
/*:ref: zzekvset_ 14 2 4 4 */
/*:ref: zzekqsel_ 14 12 4 13 4 4 4 13 4 13 4 124 124 124 */
/*:ref: zzekqord_ 14 11 4 13 4 13 4 13 4 4 124 124 124 */
/*:ref: zzekjsrt_ 14 13 4 4 4 4 4 4 4 4 4 4 4 4 4 */
/*:ref: zzekvcal_ 14 3 4 4 4 */
/*:ref: zzekesiz_ 4 4 4 4 4 4 */
/*:ref: zzekrsc_ 14 10 4 4 4 4 4 4 13 12 12 124 */
/*:ref: zzekrsd_ 14 8 4 4 4 4 4 7 12 12 */
/*:ref: zzekrsi_ 14 8 4 4 4 4 4 4 12 12 */
 
extern int ekrcec_(void *cspice_state, integer *handle, integer *segno, integer *recno, char *column, integer *nvals, char *cvals, logical *isnull, ftnlen column_len, ftnlen cvals_len);
/*:ref: zzeksdsc_ 14 3 4 4 4 */
/*:ref: zzekcdsc_ 14 5 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzektrdp_ 14 4 4 4 4 4 */
/*:ref: zzekrd03_ 14 8 4 4 4 4 4 13 12 124 */
/*:ref: zzekesiz_ 4 4 4 4 4 4 */
/*:ref: zzekrd06_ 14 10 4 4 4 4 4 4 13 12 12 124 */
/*:ref: zzekrd09_ 14 8 4 4 4 4 4 13 12 124 */
 
extern int ekrced_(void *cspice_state, integer *handle, integer *segno, integer *recno, char *column, integer *nvals, doublereal *dvals, logical *isnull, ftnlen column_len);
/*:ref: zzeksdsc_ 14 3 4 4 4 */
/*:ref: zzekcdsc_ 14 5 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzektrdp_ 14 4 4 4 4 4 */
/*:ref: zzekrd02_ 14 6 4 4 4 4 7 12 */
/*:ref: zzekesiz_ 4 4 4 4 4 4 */
/*:ref: zzekrd05_ 14 9 4 4 4 4 4 4 7 12 12 */
/*:ref: zzekrd08_ 14 6 4 4 4 4 7 12 */
 
extern int ekrcei_(void *cspice_state, integer *handle, integer *segno, integer *recno, char *column, integer *nvals, integer *ivals, logical *isnull, ftnlen column_len);
/*:ref: zzeksdsc_ 14 3 4 4 4 */
/*:ref: zzekcdsc_ 14 5 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzektrdp_ 14 4 4 4 4 4 */
/*:ref: zzekrd01_ 14 6 4 4 4 4 4 12 */
/*:ref: zzekesiz_ 4 4 4 4 4 4 */
/*:ref: zzekrd04_ 14 9 4 4 4 4 4 4 4 12 12 */
/*:ref: zzekrd07_ 14 6 4 4 4 4 4 12 */
 
extern int ekshdw_(void *cspice_state, integer *handle, logical *isshad);
 
extern int ekssum_(void *cspice_state, integer *handle, integer *segno, char *tabnam, integer *nrows, integer *ncols, char *cnames, char *dtypes, integer *sizes, integer *strlns, logical *indexd, logical *nullok, ftnlen tabnam_len, ftnlen cnames_len, ftnlen dtypes_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzeksinf_ 14 8 4 4 13 4 13 4 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int ekucec_(void *cspice_state, integer *handle, integer *segno, integer *recno, char *column, integer *nvals, char *cvals, logical *isnull, ftnlen column_len, ftnlen cvals_len);
/*:ref: zzeksdsc_ 14 3 4 4 4 */
/*:ref: zzekcdsc_ 14 5 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzektrdp_ 14 4 4 4 4 4 */
/*:ref: ekshdw_ 14 2 4 12 */
/*:ref: zzekrbck_ 14 6 13 4 4 4 4 124 */
/*:ref: zzekue03_ 14 7 4 4 4 4 13 12 124 */
/*:ref: zzekue06_ 14 8 4 4 4 4 4 13 12 124 */
 
extern int ekuced_(void *cspice_state, integer *handle, integer *segno, integer *recno, char *column, integer *nvals, doublereal *dvals, logical *isnull, ftnlen column_len);
/*:ref: zzeksdsc_ 14 3 4 4 4 */
/*:ref: zzekcdsc_ 14 5 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzektrdp_ 14 4 4 4 4 4 */
/*:ref: ekshdw_ 14 2 4 12 */
/*:ref: zzekrbck_ 14 6 13 4 4 4 4 124 */
/*:ref: zzekue02_ 14 6 4 4 4 4 7 12 */
/*:ref: zzekue05_ 14 7 4 4 4 4 4 7 12 */
 
extern int ekucei_(void *cspice_state, integer *handle, integer *segno, integer *recno, char *column, integer *nvals, integer *ivals, logical *isnull, ftnlen column_len);
/*:ref: zzeksdsc_ 14 3 4 4 4 */
/*:ref: zzekcdsc_ 14 5 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzektrdp_ 14 4 4 4 4 4 */
/*:ref: ekshdw_ 14 2 4 12 */
/*:ref: zzekrbck_ 14 6 13 4 4 4 4 124 */
/*:ref: zzekue01_ 14 6 4 4 4 4 4 12 */
/*:ref: zzekue04_ 14 7 4 4 4 4 4 4 12 */
 
extern int el2cgv_(void *cspice_state, doublereal *ellips, doublereal *center, doublereal *smajor, doublereal *sminor);
/*:ref: vequ_ 14 2 7 7 */
 
extern logical elemc_(void *cspice_state, char *item, char *a, ftnlen item_len, ftnlen a_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern logical elemd_(void *cspice_state, doublereal *item, doublereal *a);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: bsrchd_ 4 3 7 4 7 */
/*:ref: cardd_ 4 1 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern logical elemi_(void *cspice_state, integer *item, integer *a);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: bsrchi_ 4 3 4 4 4 */
/*:ref: cardi_ 4 1 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int elltof_(void *cspice_state, doublereal *ma, doublereal *ecc, doublereal *e);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: pi_ 7 0 */
/*:ref: twopi_ 7 0 */
/*:ref: halfpi_ 7 0 */
/*:ref: dcbrt_ 7 1 7 */
 
extern int enchar_(void *cspice_state, integer *number, char *string, ftnlen string_len);
extern int dechar_(void *cspice_state, char *string, integer *number, ftnlen string_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: chbase_ 4 0 */
 
extern logical eqchr_(void *cspice_state, char *a, char *b, ftnlen a_len, ftnlen b_len);
extern logical nechr_(void *cspice_state, char *a, char *b, ftnlen a_len, ftnlen b_len);
 
extern int eqncpv_(void *cspice_state, doublereal *et, doublereal *epoch, doublereal *eqel, doublereal *rapol, doublereal *decpol, doublereal *state);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: twopi_ 7 0 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: kepleq_ 7 3 7 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: vlcom3_ 14 7 7 7 7 7 7 7 7 */
/*:ref: mxv_ 14 3 7 7 7 */
 
extern logical eqstr_(void *cspice_state, char *a, char *b, ftnlen a_len, ftnlen b_len);
 
extern int erract_(void *cspice_state, char *op, char *action, ftnlen op_len, ftnlen action_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: getact_ 14 1 4 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: putact_ 14 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int errch_(void *cspice_state, char *marker, char *string, ftnlen marker_len, ftnlen string_len);
/*:ref: allowd_ 12 0 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: getlms_ 14 2 13 124 */
/*:ref: frstnb_ 4 2 13 124 */
/*:ref: nblen_ 4 2 13 124 */
/*:ref: putlms_ 14 2 13 124 */
 
extern int errdev_(void *cspice_state, char *op, char *device, ftnlen op_len, ftnlen device_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: getdev_ 14 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: putdev_ 14 2 13 124 */
 
extern int errdp_(void *cspice_state, char *marker, doublereal *dpnum, ftnlen marker_len);
/*:ref: allowd_ 12 0 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: getlms_ 14 2 13 124 */
/*:ref: dpstr_ 14 4 7 4 13 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: frstnb_ 4 2 13 124 */
/*:ref: putlms_ 14 2 13 124 */
 
extern int errfnm_(void *cspice_state, char *marker, integer *unit, ftnlen marker_len);
/*:ref: errch_ 14 4 13 13 124 124 */
 
extern int errhan_(void *cspice_state, char *marker, integer *handle, ftnlen marker_len);
/*:ref: zzddhnfo_ 14 7 4 13 4 4 4 12 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
 
extern int errint_(void *cspice_state, char *marker, integer *integr, ftnlen marker_len);
/*:ref: allowd_ 12 0 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: getlms_ 14 2 13 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: frstnb_ 4 2 13 124 */
/*:ref: putlms_ 14 2 13 124 */
 
extern int errprt_(void *cspice_state, char *op, char *list, ftnlen op_len, ftnlen list_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: msgsel_ 12 2 13 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: lparse_ 14 8 13 13 4 4 13 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: setprt_ 12 5 12 12 12 12 12 */
/*:ref: chkout_ 14 2 13 124 */
 
extern integer esrchc_(void *cspice_state, char *value, integer *ndim, char *array, ftnlen value_len, ftnlen array_len);
/*:ref: eqstr_ 12 4 13 13 124 124 */
 
extern int et2lst_(void *cspice_state, doublereal *et, integer *body, doublereal *long__, char *type__, integer *hr, integer *mn, integer *sc, char *time, char *ampm, ftnlen type_len, ftnlen time_len, ftnlen ampm_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: bodc2n_ 14 4 4 13 12 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: pgrrec_ 14 8 13 7 7 7 7 7 7 124 */
/*:ref: reclat_ 14 4 7 7 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: cidfrm_ 14 5 4 4 13 12 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: spkez_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: rmaind_ 14 4 7 7 7 7 */
/*:ref: twopi_ 7 0 */
/*:ref: pi_ 7 0 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: gdpool_ 14 7 13 4 4 4 7 12 124 */
/*:ref: brcktd_ 7 3 7 7 7 */
/*:ref: dpfmt_ 14 5 7 13 13 124 124 */
 
extern int et2utc_(void *cspice_state, doublereal *et, char *format, integer *prec, char *utcstr, ftnlen format_len, ftnlen utcstr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ttrans_ 14 5 13 13 7 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: dpstrf_ 14 6 7 4 13 13 124 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: unitim_ 7 5 7 13 13 124 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern int etcal_(void *cspice_state, doublereal *et, char *string, ftnlen string_len);
/*:ref: spd_ 7 0 */
/*:ref: intmax_ 4 0 */
/*:ref: intmin_ 4 0 */
/*:ref: lstlti_ 4 3 4 4 4 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: dpstrf_ 14 6 7 4 13 13 124 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
 
extern int eul2m_(void *cspice_state, doublereal *angle3, doublereal *angle2, doublereal *angle1, integer *axis3, integer *axis2, integer *axis1, doublereal *r__);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rotate_ 14 3 7 4 7 */
/*:ref: rotmat_ 14 4 7 7 4 7 */
 
extern int ev2lin_(void *cspice_state, doublereal *et, doublereal *geophs, doublereal *elems, doublereal *state);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: twopi_ 7 0 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: brcktd_ 7 3 7 7 7 */
 
extern logical even_(void *cspice_state, integer *i__);
 
extern doublereal exact_(void *cspice_state, doublereal *number, doublereal *value, doublereal *tol);
 
extern int excess_(void *cspice_state, integer *number, char *struct__, ftnlen struct_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern logical exists_(void *cspice_state, char *file, ftnlen file_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern int expln_(void *cspice_state, char *msg, char *expl, ftnlen msg_len, ftnlen expl_len);
 
extern integer fetchc_(void *cspice_state, integer *nth, char *set, ftnlen set_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern integer fetchd_(void *cspice_state, integer *nth, doublereal *set);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern integer fetchi_(void *cspice_state, integer *nth, integer *set);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int fillc_(void *cspice_state, char *value, integer *ndim, char *array, ftnlen value_len, ftnlen array_len);
 
extern int filld_(void *cspice_state, doublereal *value, integer *ndim, doublereal *array);
 
extern int filli_(void *cspice_state, integer *value, integer *ndim, integer *array);
 
extern int fn2lun_(void *cspice_state, char *filnam, integer *lunit, ftnlen filnam_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern int fndlun_(void *cspice_state, integer *unit);
extern int reslun_(void *cspice_state, integer *unit);
extern int frelun_(void *cspice_state, integer *unit);
 
extern int fndnwd_(void *cspice_state, char *string, integer *start, integer *b, integer *e, ftnlen string_len);
 
extern int fovray_(void *cspice_state, char *inst, doublereal *raydir, char *rframe, char *abcorr, char *obsrvr, doublereal *et, logical *visibl, ftnlen inst_len, ftnlen rframe_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzgffvin_ 14 13 13 13 7 13 13 13 13 124 124 124 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzgffvst_ 14 2 7 12 */
 
extern int fovtrg_(void *cspice_state, char *inst, char *target, char *tshape, char *tframe, char *abcorr, char *obsrvr, doublereal *et, logical *visibl, ftnlen inst_len, ftnlen target_len, ftnlen tshape_len, ftnlen tframe_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzgffvin_ 14 13 13 13 7 13 13 13 13 124 124 124 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: zzgffvst_ 14 2 7 12 */
 
extern int frame_(void *cspice_state, doublereal *x, doublereal *y, doublereal *z__);
/*:ref: vhatip_ 14 1 7 */
 
extern int framex_(void *cspice_state, char *cname, char *frname, integer *frcode, integer *cent, integer *class__, integer *clssid, logical *found, ftnlen cname_len, ftnlen frname_len);
extern int namfrm_(void *cspice_state, char *frname, integer *frcode, ftnlen frname_len);
extern int frmnam_(void *cspice_state, integer *frcode, char *frname, ftnlen frname_len);
extern int frinfo_(void *cspice_state, integer *frcode, integer *cent, integer *class__, integer *clssid, logical *found);
extern int cidfrm_(void *cspice_state, integer *cent, integer *frcode, char *frname, logical *found, ftnlen frname_len);
extern int cnmfrm_(void *cspice_state, char *cname, integer *frcode, char *frname, logical *found, ftnlen cname_len, ftnlen frname_len);
extern int ccifrm_(void *cspice_state, integer *class__, integer *clssid, integer *frcode, char *frname, integer *cent, logical *found, ftnlen frname_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: return_ 12 0 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzhsiini_ 14 3 4 4 4 */
/*:ref: zzhscini_ 14 3 4 4 4 */
/*:ref: zzfdat_ 14 18 4 4 13 4 4 4 4 4 4 4 13 4 4 4 4 4 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: zzhscchk_ 14 7 4 4 13 13 4 124 124 */
/*:ref: zzpctrck_ 14 2 4 12 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: gipool_ 14 7 13 4 4 4 4 12 124 */
/*:ref: zzhscadd_ 14 8 4 4 13 13 4 12 124 124 */
/*:ref: zzhsichk_ 14 5 4 4 4 4 4 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: gcpool_ 14 8 13 4 4 4 13 12 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: zzdynbid_ 14 6 13 4 13 4 124 124 */
/*:ref: zzdynvai_ 14 8 13 4 13 4 4 4 124 124 */
/*:ref: zzhsiadd_ 14 6 4 4 4 4 4 12 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: bodc2n_ 14 4 4 13 12 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: bschoi_ 4 4 4 4 4 4 */
/*:ref: bodn2c_ 14 4 13 4 12 124 */
/*:ref: gnpool_ 14 8 13 4 4 4 13 12 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
 
extern int frmchg_(void *cspice_state, integer *frame1, integer *frame2, doublereal *et, doublereal *xform);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: frmget_ 14 5 4 7 7 4 12 */
/*:ref: zzmsxf_ 14 3 7 4 7 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: zznofcon_ 14 7 7 4 4 4 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: invstm_ 14 2 7 7 */
 
extern int frmget_(void *cspice_state, integer *infrm, doublereal *et, doublereal *xform, integer *outfrm, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: irfrot_ 14 3 4 4 7 */
/*:ref: failed_ 12 0 */
/*:ref: tisbod_ 14 5 13 4 7 7 124 */
/*:ref: invstm_ 14 2 7 7 */
/*:ref: ckfxfm_ 14 5 4 7 7 4 12 */
/*:ref: tkfram_ 14 4 4 7 4 12 */
/*:ref: zzdynfrm_ 14 5 4 4 7 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern integer frstnb_(void *cspice_state, char *string, ftnlen string_len);
 
extern integer frstnp_(void *cspice_state, char *string, ftnlen string_len);
 
extern integer frstpc_(void *cspice_state, char *string, ftnlen string_len);
 
extern integer gcd_(void *cspice_state, integer *a, integer *b);
 
extern int georec_(void *cspice_state, doublereal *long__, doublereal *lat, doublereal *alt, doublereal *re, doublereal *f, doublereal *rectan);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: surfnm_ 14 5 7 7 7 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
 
extern int getelm_(void *cspice_state, integer *frstyr, char *lines, doublereal *epoch, doublereal *elems, ftnlen lines_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzgetelm_ 14 8 4 13 7 7 12 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int getfat_(void *cspice_state, char *file, char *arch, char *kertyp, ftnlen file_len, ftnlen arch_len, ftnlen kertyp_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzddhfnh_ 14 4 13 4 12 124 */
/*:ref: zzddhnfo_ 14 7 4 13 4 4 4 12 124 */
/*:ref: zzddhgsd_ 14 5 13 4 13 124 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: getlun_ 14 1 4 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: nextwd_ 14 6 13 13 13 124 124 124 */
/*:ref: idw2at_ 14 6 13 13 13 124 124 124 */
/*:ref: dafopr_ 14 3 13 4 124 */
/*:ref: zzckspk_ 14 3 4 13 124 */
/*:ref: dafcls_ 14 1 4 */
 
extern int getfov_(void *cspice_state, integer *instid, integer *room, char *shape, char *frame, doublereal *bsight, integer *n, doublereal *bounds, ftnlen shape_len, ftnlen frame_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: gcpool_ 14 8 13 4 4 4 13 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: gdpool_ 14 7 13 4 4 4 7 12 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: convrt_ 14 6 7 13 13 7 124 124 */
/*:ref: vrotv_ 14 4 7 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: unorm_ 14 3 7 7 7 */
/*:ref: vperp_ 14 3 7 7 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: vscl_ 14 3 7 7 7 */
 
extern int getlun_(void *cspice_state, integer *unit);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: fndlun_ 14 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern int getmsg_(void *cspice_state, char *option, char *msg, ftnlen option_len, ftnlen msg_len);
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: getsms_ 14 2 13 124 */
/*:ref: expln_ 14 4 13 13 124 124 */
/*:ref: getlms_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern logical gfbail_(void *cspice_state);
 
extern int gfdist_(void *cspice_state, char *target, char *abcorr, char *obsrvr, char *relate, doublereal *refval, doublereal *adjust, doublereal *step, doublereal *cnfine, integer *mw, integer *nw, doublereal *work, doublereal *result, ftnlen target_len, ftnlen abcorr_len, ftnlen obsrvr_len, ftnlen relate_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: gfsstp_ 14 1 7 */
/*:ref: zzholdd_ 14 4 4 4 12 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: gfevnt_ 14 28 200 200 13 4 13 13 7 4 12 13 7 7 7 7 12 200 200 200 4 4 7 12 212 7 124 124 124 124 */
/*:ref: gfbail_ 12 :*/
 
extern int gfevnt_(void *cspice_state, U_fp udstep, U_fp udrefn, char *gquant, integer *qnpars, char *qpnams, char *qcpars, doublereal *qdpars, integer *qipars, logical *qlpars, char *op, doublereal *refval, doublereal *tol, doublereal *adjust, doublereal *cnfine, logical *rpt, U_fp udrepi, U_fp udrepu, U_fp udrepf, integer *mw, integer *nw, doublereal *work, logical *bail, L_fp udbail, doublereal *result, ftnlen gquant_len, ftnlen qpnams_len, ftnlen qcpars_len, ftnlen op_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: zzgfspin_ 14 10 13 13 13 13 13 124 124 124 124 124 */
/*:ref: zzgfrelx_ 14 25 200 200 200 200 200 13 7 7 7 7 4 4 7 12 200 200 200 13 13 12 212 7 124 124 124 */
/*:ref: zzgfdiin_ 14 6 13 13 13 124 124 124 */
/*:ref: zzgfcslv_ 14 37 13 13 13 13 13 13 13 7 13 13 13 7 7 7 200 200 12 200 200 200 12 212 4 4 7 7 7 124 124 124 124 124 124 124 124 124 124 */
/*:ref: zzgfrrin_ 14 7 13 13 13 7 124 124 124 */
/*:ref: zzgfpain_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: zzgfilin_ 14 15 13 13 13 13 13 13 13 7 124 124 124 124 124 124 124 */
 
extern int gffove_(void *cspice_state, char *inst, char *tshape, doublereal *raydir, char *target, char *tframe, char *abcorr, char *obsrvr, doublereal *tol, U_fp udstep, U_fp udrefn, logical *rpt, S_fp udrepi, U_fp udrepu, S_fp udrepf, logical *bail, L_fp udbail, doublereal *cnfine, doublereal *result, ftnlen inst_len, ftnlen tshape_len, ftnlen target_len, ftnlen tframe_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: zzgffvin_ 14 13 13 13 7 13 13 13 13 124 124 124 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: wncard_ 4 1 7 */
/*:ref: wnfetd_ 14 4 7 4 7 7 */
/*:ref: zzgfsolv_ 14 13 200 200 200 12 212 12 7 7 7 7 12 200 7 */
 
extern int gfilum_(void *cspice_state, char *method, char *angtyp, char *target, char *illmn, char *fixref, char *abcorr, char *obsrvr, doublereal *spoint, char *relate, doublereal *refval, doublereal *adjust, doublereal *step, doublereal *cnfine, integer *mw, integer *nw, doublereal *work, doublereal *result, ftnlen method_len, ftnlen angtyp_len, ftnlen target_len, ftnlen illmn_len, ftnlen fixref_len, ftnlen abcorr_len, ftnlen obsrvr_len, ftnlen relate_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: gfsstp_ 14 1 7 */
/*:ref: zzholdd_ 14 4 4 4 12 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: gfevnt_ 14 28 200 200 13 4 13 13 7 4 12 13 7 7 7 7 12 200 200 200 4 4 7 12 212 7 124 124 124 124 */
/*:ref: gfbail_ 12 :*/
 
extern int gfocce_(void *cspice_state, char *occtyp, char *front, char *fshape, char *fframe, char *back, char *bshape, char *bframe, char *abcorr, char *obsrvr, doublereal *tol, U_fp udstep, U_fp udrefn, logical *rpt, S_fp udrepi, U_fp udrepu, S_fp udrepf, logical *bail, L_fp udbail, doublereal *cnfine, doublereal *result, ftnlen occtyp_len, ftnlen front_len, ftnlen fshape_len, ftnlen fframe_len, ftnlen back_len, ftnlen bshape_len, ftnlen bframe_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: zzgfocin_ 14 18 13 13 13 13 13 13 13 13 13 124 124 124 124 124 124 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: wncard_ 4 1 7 */
/*:ref: wnfetd_ 14 4 7 4 7 7 */
/*:ref: zzgfsolv_ 14 13 200 200 200 12 212 12 7 7 7 7 12 200 7 */
 
extern int gfoclt_(void *cspice_state, char *occtyp, char *front, char *fshape, char *fframe, char *back, char *bshape, char *bframe, char *abcorr, char *obsrvr, doublereal *step, doublereal *cnfine, doublereal *result, ftnlen occtyp_len, ftnlen front_len, ftnlen fshape_len, ftnlen fframe_len, ftnlen back_len, ftnlen bshape_len, ftnlen bframe_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: gfsstp_ 14 1 7 */
/*:ref: zzholdd_ 14 4 4 4 12 7 */
/*:ref: gfocce_ 14 29 13 13 13 13 13 13 13 13 13 7 200 200 12 200 200 200 12 212 7 7 124 124 124 124 124 124 124 124 124 */
/*:ref: gfbail_ 12 :*/
 
extern int gfpa_(void *cspice_state, char *target, char *illmn, char *abcorr, char *obsrvr, char *relate, doublereal *refval, doublereal *adjust, doublereal *step, doublereal *cnfine, integer *mw, integer *nw, doublereal *work, doublereal *result, ftnlen target_len, ftnlen illmn_len, ftnlen abcorr_len, ftnlen obsrvr_len, ftnlen relate_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: odd_ 12 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: gfsstp_ 14 1 7 */
/*:ref: zzholdd_ 14 4 4 4 12 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: gfevnt_ 14 28 200 200 13 4 13 13 7 4 12 13 7 7 7 7 12 200 200 200 4 4 7 12 212 7 124 124 124 124 */
/*:ref: gfbail_ 12 :*/
 
extern int gfposc_(void *cspice_state, char *target, char *frame, char *abcorr, char *obsrvr, char *crdsys, char *coord, char *relate, doublereal *refval, doublereal *adjust, doublereal *step, doublereal *cnfine, integer *mw, integer *nw, doublereal *work, doublereal *result, ftnlen target_len, ftnlen frame_len, ftnlen abcorr_len, ftnlen obsrvr_len, ftnlen crdsys_len, ftnlen coord_len, ftnlen relate_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: even_ 12 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: gfsstp_ 14 1 7 */
/*:ref: zzholdd_ 14 4 4 4 12 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: gfevnt_ 14 28 200 200 13 4 13 13 7 4 12 13 7 7 7 7 12 200 200 200 4 4 7 12 212 7 124 124 124 124 */
/*:ref: gfbail_ 12 :*/
 
extern int gfrefn_(void *cspice_state, doublereal *t1, doublereal *t2, logical *s1, logical *s2, doublereal *t);
/*:ref: brcktd_ 7 3 7 7 7 */
 
extern int gfrfov_(void *cspice_state, char *inst, doublereal *raydir, char *rframe, char *abcorr, char *obsrvr, doublereal *step, doublereal *cnfine, doublereal *result, ftnlen inst_len, ftnlen rframe_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: gfsstp_ 14 1 7 */
/*:ref: zzholdd_ 14 4 4 4 12 7 */
/*:ref: gffove_ 14 24 13 13 7 13 13 13 13 7 200 200 12 200 200 200 12 212 7 7 124 124 124 124 124 124 */
/*:ref: gfbail_ 12 :*/
 
extern int gfrprt_(void *cspice_state, doublereal *window, char *begmss, char *endmss, doublereal *ivbeg, doublereal *ivend, doublereal *time, ftnlen begmss_len, ftnlen endmss_len);
extern int gfrepi_(void *cspice_state, doublereal *window, char *begmss, char *endmss, ftnlen begmss_len, ftnlen endmss_len);
extern int gfrepu_(void *cspice_state, doublereal *ivbeg, doublereal *ivend, doublereal *time);
extern int gfrepf_(void *cspice_state);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: return_ 12 0 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: wnsumd_ 14 6 7 7 7 7 4 4 */
/*:ref: zzgftswk_ 14 7 7 7 4 13 13 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: cardd_ 4 1 7 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: zzgfwkin_ 14 1 7 */
/*:ref: zzgfwkad_ 14 6 7 4 13 13 124 124 */
/*:ref: zzgfwkmo_ 14 9 4 7 7 4 13 13 7 124 124 */
/*:ref: stdio_ 14 3 13 4 124 */
/*:ref: zzgfdsps_ 14 6 4 13 13 4 124 124 */
 
extern int gfrr_(void *cspice_state, char *target, char *abcorr, char *obsrvr, char *relate, doublereal *refval, doublereal *adjust, doublereal *step, doublereal *cnfine, integer *mw, integer *nw, doublereal *work, doublereal *result, ftnlen target_len, ftnlen abcorr_len, ftnlen obsrvr_len, ftnlen relate_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: odd_ 12 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: gfsstp_ 14 1 7 */
/*:ref: zzholdd_ 14 4 4 4 12 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: gfevnt_ 14 28 200 200 13 4 13 13 7 4 12 13 7 7 7 7 12 200 200 200 4 4 7 12 212 7 124 124 124 124 */
/*:ref: gfbail_ 12 :*/
 
extern int gfsep_(void *cspice_state, char *targ1, char *shape1, char *frame1, char *targ2, char *shape2, char *frame2, char *abcorr, char *obsrvr, char *relate, doublereal *refval, doublereal *adjust, doublereal *step, doublereal *cnfine, integer *mw, integer *nw, doublereal *work, doublereal *result, ftnlen targ1_len, ftnlen shape1_len, ftnlen frame1_len, ftnlen targ2_len, ftnlen shape2_len, ftnlen frame2_len, ftnlen abcorr_len, ftnlen obsrvr_len, ftnlen relate_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: even_ 12 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: gfsstp_ 14 1 7 */
/*:ref: zzholdd_ 14 4 4 4 12 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: gfevnt_ 14 28 200 200 13 4 13 13 7 4 12 13 7 7 7 7 12 200 200 200 4 4 7 12 212 7 124 124 124 124 */
/*:ref: gfbail_ 12 :*/
 
extern int gfsntc_(void *cspice_state, char *target, char *fixref, char *method, char *abcorr, char *obsrvr, char *dref, doublereal *dvec, char *crdsys, char *coord, char *relate, doublereal *refval, doublereal *adjust, doublereal *step, doublereal *cnfine, integer *mw, integer *nw, doublereal *work, doublereal *result, ftnlen target_len, ftnlen fixref_len, ftnlen method_len, ftnlen abcorr_len, ftnlen obsrvr_len, ftnlen dref_len, ftnlen crdsys_len, ftnlen coord_len, ftnlen relate_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: even_ 12 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: gfsstp_ 14 1 7 */
/*:ref: zzholdd_ 14 4 4 4 12 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: gfevnt_ 14 28 200 200 13 4 13 13 7 4 12 13 7 7 7 7 12 200 200 200 4 4 7 12 212 7 124 124 124 124 */
/*:ref: gfbail_ 12 :*/
 
extern int gfstep_(void *cspice_state, doublereal *time, doublereal *step);
extern int gfsstp_(void *cspice_state, doublereal *step);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
 
extern int gfstol_(void *cspice_state, doublereal *value);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzholdd_ 14 4 4 4 12 7 */
 
extern int gfsubc_(void *cspice_state, char *target, char *fixref, char *method, char *abcorr, char *obsrvr, char *crdsys, char *coord, char *relate, doublereal *refval, doublereal *adjust, doublereal *step, doublereal *cnfine, integer *mw, integer *nw, doublereal *work, doublereal *result, ftnlen target_len, ftnlen fixref_len, ftnlen method_len, ftnlen abcorr_len, ftnlen obsrvr_len, ftnlen crdsys_len, ftnlen coord_len, ftnlen relate_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: even_ 12 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: gfsstp_ 14 1 7 */
/*:ref: zzholdd_ 14 4 4 4 12 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: gfevnt_ 14 28 200 200 13 4 13 13 7 4 12 13 7 7 7 7 12 200 200 200 4 4 7 12 212 7 124 124 124 124 */
/*:ref: gfbail_ 12 :*/
 
extern int gftfov_(void *cspice_state, char *inst, char *target, char *tshape, char *tframe, char *abcorr, char *obsrvr, doublereal *step, doublereal *cnfine, doublereal *result, ftnlen inst_len, ftnlen target_len, ftnlen tshape_len, ftnlen tframe_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: gfsstp_ 14 1 7 */
/*:ref: zzholdd_ 14 4 4 4 12 7 */
/*:ref: gffove_ 14 24 13 13 7 13 13 13 13 7 200 200 12 200 200 200 12 212 7 7 124 124 124 124 124 124 */
/*:ref: gfbail_ 12 :*/
 
extern int gfudb_(void *cspice_state, U_fp udfuns, U_fp udfunb, doublereal *step, doublereal *cnfine, doublereal *result);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: odd_ 12 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: gfsstp_ 14 1 7 */
/*:ref: zzholdd_ 14 4 4 4 12 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: zzgfudb_ 14 13 200 200 7 200 200 12 200 200 200 12 212 7 7 */
/*:ref: gfbail_ 12 :*/
 
extern int gfuds_(void *cspice_state, U_fp udfuns, U_fp udqdec, char *relate, doublereal *refval, doublereal *adjust, doublereal *step, doublereal *cnfine, integer *mw, integer *nw, doublereal *work, doublereal *result, ftnlen relate_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: odd_ 12 1 4 */
/*:ref: sized_ 4 1 7 */
/*:ref: gfsstp_ 14 1 7 */
/*:ref: zzholdd_ 14 4 4 4 12 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: zzgfrelx_ 14 25 200 200 200 200 200 13 7 7 7 7 4 4 7 12 200 200 200 13 13 12 212 7 124 124 124 */
/*:ref: gfbail_ 12 :*/
 
extern doublereal halfpi_(void *cspice_state);
 
extern int hrmesp_(void *cspice_state, integer *n, doublereal *first, doublereal *step, doublereal *yvals, doublereal *x, doublereal *work, doublereal *f, doublereal *df);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int hrmint_(void *cspice_state, integer *n, doublereal *xvals, doublereal *yvals, doublereal *x, doublereal *work, doublereal *f, doublereal *df);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
 
extern int hx2dp_(void *cspice_state, char *string, doublereal *number, logical *error, char *errmsg, ftnlen string_len, ftnlen errmsg_len);
/*:ref: dpmin_ 7 0 */
/*:ref: dpmax_ 7 0 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: hx2int_ 14 6 13 4 12 13 124 124 */
 
extern int hx2int_(void *cspice_state, char *string, integer *number, logical *error, char *errmsg, ftnlen string_len, ftnlen errmsg_len);
/*:ref: intmin_ 4 0 */
/*:ref: intmax_ 4 0 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
 
extern int hyptof_(void *cspice_state, doublereal *ma, doublereal *ecc, doublereal *f);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dpmax_ 7 0 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dcbrt_ 7 1 7 */
 
extern int ident_(void *cspice_state, doublereal *matrix);
 
extern int idw2at_(void *cspice_state, char *idword, char *arch, char *type__, ftnlen idword_len, ftnlen arch_len, ftnlen type_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: pos_ 4 5 13 13 4 124 124 */
 
extern int illum_(void *cspice_state, char *target, doublereal *et, char *abcorr, char *obsrvr, doublereal *spoint, doublereal *phase, doublereal *solar, doublereal *emissn, ftnlen target_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: cidfrm_ 14 5 4 4 13 12 124 */
/*:ref: spkez_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: surfnm_ 14 5 7 7 7 7 7 */
/*:ref: vsep_ 7 2 7 7 */
 
extern int illumf_(void *cspice_state, char *method, char *target, char *ilusrc, doublereal *et, char *fixref, char *abcorr, char *obsrvr, doublereal *spoint, doublereal *trgepc, doublereal *srfvec, doublereal *phase, doublereal *incdnc, doublereal *emissn, logical *visibl, logical *lit, ftnlen method_len, ftnlen target_len, ftnlen ilusrc_len, ftnlen fixref_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzsrftrk_ 14 2 4 12 */
/*:ref: zzprsmet_ 14 15 4 13 4 13 13 12 4 4 13 13 124 124 124 124 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: spkcpt_ 14 16 7 13 13 7 13 13 13 13 7 7 124 124 124 124 124 124 */
/*:ref: spkcpo_ 14 16 13 7 13 13 13 7 13 13 7 7 124 124 124 124 124 124 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: surfnm_ 14 5 7 7 7 7 7 */
/*:ref: zzsudski_ 14 4 4 4 4 4 */
/*:ref: zzsbfnrm_ 14 7 4 4 4 7 4 7 7 */
/*:ref: vhatip_ 14 1 7 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: halfpi_ 7 0 */
/*:ref: zzmaxrad_ 14 1 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: zzraysfx_ 14 5 7 7 7 7 12 */
 
extern int illumg_(void *cspice_state, char *method, char *target, char *ilusrc, doublereal *et, char *fixref, char *abcorr, char *obsrvr, doublereal *spoint, doublereal *trgepc, doublereal *srfvec, doublereal *phase, doublereal *incdnc, doublereal *emissn, ftnlen method_len, ftnlen target_len, ftnlen ilusrc_len, ftnlen fixref_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzsrftrk_ 14 2 4 12 */
/*:ref: zzprsmet_ 14 15 4 13 4 13 13 12 4 4 13 13 124 124 124 124 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: spkcpt_ 14 16 7 13 13 7 13 13 13 13 7 7 124 124 124 124 124 124 */
/*:ref: spkcpo_ 14 16 13 7 13 13 13 7 13 13 7 7 124 124 124 124 124 124 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: surfnm_ 14 5 7 7 7 7 7 */
/*:ref: zzsbfnrm_ 14 7 4 4 4 7 4 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: vsep_ 7 2 7 7 */
 
extern int ilumin_(void *cspice_state, char *method, char *target, doublereal *et, char *fixref, char *abcorr, char *obsrvr, doublereal *spoint, doublereal *trgepc, doublereal *srfvec, doublereal *phase, doublereal *solar, doublereal *emissn, ftnlen method_len, ftnlen target_len, ftnlen fixref_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: illumg_ 14 19 13 13 13 7 13 13 13 7 7 7 7 7 7 124 124 124 124 124 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int incnsg_(void *cspice_state, doublereal *apex, doublereal *axis, doublereal *angle, doublereal *endpt1, doublereal *endpt2, integer *nxpts, doublereal *xpt1, doublereal *xpt2);
/*:ref: return_ 12 0 */
/*:ref: unorm_ 14 3 7 7 7 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: pi_ 7 0 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: nvp2pl_ 14 3 7 7 7 */
/*:ref: inrypl_ 14 5 7 7 7 4 7 */
/*:ref: vdist_ 7 2 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: zzcnquad_ 14 7 7 7 7 7 4 7 7 */
/*:ref: zzcxbrut_ 14 7 7 7 7 7 7 7 12 */
/*:ref: frame_ 14 3 7 7 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: zzsglatx_ 14 6 7 7 7 7 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: halfpi_ 7 0 */
/*:ref: mtxv_ 14 3 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
 
extern int inedpl_(void *cspice_state, doublereal *a, doublereal *b, doublereal *c__, doublereal *plane, doublereal *ellips, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: pl2nvc_ 14 3 7 7 7 */
/*:ref: vzero_ 12 1 7 */
/*:ref: pl2psv_ 14 4 7 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: psv2pl_ 14 4 7 7 7 7 */
/*:ref: brcktd_ 7 3 7 7 7 */
/*:ref: vsclip_ 14 2 7 7 */
/*:ref: cgv2el_ 14 4 7 7 7 7 */
 
extern int inelpl_(void *cspice_state, doublereal *ellips, doublereal *plane, integer *nxpts, doublereal *xpt1, doublereal *xpt2);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: pl2nvc_ 14 3 7 7 7 */
/*:ref: vzero_ 12 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: el2cgv_ 14 4 7 7 7 7 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: halfpi_ 7 0 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: pl2nvp_ 14 3 7 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: nvp2pl_ 14 3 7 7 7 */
/*:ref: vzerog_ 12 2 7 4 */
/*:ref: vnormg_ 7 2 7 4 */
/*:ref: vlcom3_ 14 7 7 7 7 7 7 7 7 */
 
extern int inrypl_(void *cspice_state, doublereal *vertex, doublereal *dir, doublereal *plane, integer *nxpts, doublereal *xpt);
/*:ref: return_ 12 0 */
/*:ref: dpmax_ 7 0 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: pl2nvc_ 14 3 7 7 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vzero_ 12 1 7 */
/*:ref: vscl_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: smsgnd_ 12 2 7 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: vsclip_ 14 2 7 7 */
 
extern int insang_(void *cspice_state, doublereal *v, doublereal *e1, doublereal *e2, doublereal *e3, logical *found, doublereal *scale);
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: vdot_ 7 2 7 7 */
 
extern int inslac_(void *cspice_state, char *elts, integer *ne, integer *loc, char *array, integer *na, ftnlen elts_len, ftnlen array_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int inslad_(void *cspice_state, doublereal *elts, integer *ne, integer *loc, doublereal *array, integer *na);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int inslai_(void *cspice_state, integer *elts, integer *ne, integer *loc, integer *array, integer *na);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int insrtc_(void *cspice_state, char *item, char *a, ftnlen item_len, ftnlen a_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sizec_ 4 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: lstlec_ 4 5 13 4 13 124 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int insrtd_(void *cspice_state, doublereal *item, doublereal *a);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: cardd_ 4 1 7 */
/*:ref: lstled_ 4 3 7 4 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int insrti_(void *cspice_state, integer *item, integer *a);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sizei_ 4 1 4 */
/*:ref: cardi_ 4 1 4 */
/*:ref: lstlei_ 4 3 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int inssub_(void *cspice_state, char *in, char *sub, integer *loc, char *out, ftnlen in_len, ftnlen sub_len, ftnlen out_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int int2hx_(void *cspice_state, integer *number, char *string, integer *length, ftnlen string_len);
 
extern int interc_(void *cspice_state, char *a, char *b, char *c__, ftnlen a_len, ftnlen b_len, ftnlen c_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: sizec_ 4 2 13 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: excess_ 14 3 4 13 124 */
 
extern int interd_(void *cspice_state, doublereal *a, doublereal *b, doublereal *c__);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: sized_ 4 1 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: excess_ 14 3 4 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int interi_(void *cspice_state, integer *a, integer *b, integer *c__);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: sizei_ 4 1 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: excess_ 14 3 4 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int intord_(void *cspice_state, integer *n, char *string, ftnlen string_len);
/*:ref: inttxt_ 14 3 4 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
 
extern int intstr_(void *cspice_state, integer *number, char *string, ftnlen string_len);
 
extern int inttxt_(void *cspice_state, integer *n, char *string, ftnlen string_len);
/*:ref: suffix_ 14 5 13 4 13 124 124 */
 
extern int invert_(void *cspice_state, doublereal *m1, doublereal *mout);
/*:ref: det_ 7 1 7 */
/*:ref: filld_ 14 3 7 4 7 */
/*:ref: vsclg_ 14 4 7 7 4 7 */
 
extern int invort_(void *cspice_state, doublereal *m, doublereal *mit);
/*:ref: dpmax_ 7 0 */
/*:ref: unorm_ 14 3 7 7 7 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: vsclip_ 14 2 7 7 */
/*:ref: xpose_ 14 2 7 7 */
 
extern int invstm_(void *cspice_state, doublereal *mat, doublereal *invmat);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: xposbl_ 14 5 7 4 4 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int ioerr_(void *cspice_state, char *action, char *file, integer *iostat, ftnlen action_len, ftnlen file_len);
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
 
extern int irftrn_(void *cspice_state, char *refa, char *refb, doublereal *rotab, ftnlen refa_len, ftnlen refb_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: irfrot_ 14 3 4 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int iso2utc_(void *cspice_state, char *tstrng, char *utcstr, char *error, ftnlen tstrng_len, ftnlen utcstr_len, ftnlen error_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern logical isopen_(void *cspice_state, char *file, ftnlen file_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern logical isordv_(void *cspice_state, integer *array, integer *n);
 
extern integer isrchc_(void *cspice_state, char *value, integer *ndim, char *array, ftnlen value_len, ftnlen array_len);
 
extern integer isrchd_(void *cspice_state, doublereal *value, integer *ndim, doublereal *array);
 
extern integer isrchi_(void *cspice_state, integer *value, integer *ndim, integer *array);
 
extern logical isrot_(void *cspice_state, doublereal *m, doublereal *ntol, doublereal *dtol);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: unorm_ 14 3 7 7 7 */
/*:ref: det_ 7 1 7 */
/*:ref: brcktd_ 7 3 7 7 7 */
 
extern doublereal j1900_(void *cspice_state);
 
extern doublereal j1950_(void *cspice_state);
 
extern doublereal j2000_(void *cspice_state);
 
extern doublereal j2100_(void *cspice_state);
 
extern int jul2gr_(void *cspice_state, integer *year, integer *month, integer *day, integer *doy);
extern int gr2jul_(void *cspice_state, integer *year, integer *month, integer *day, integer *doy);
/*:ref: rmaini_ 14 4 4 4 4 4 */
/*:ref: lstlti_ 4 3 4 4 4 */
 
extern doublereal jyear_(void *cspice_state);
 
extern int keeper_(void *cspice_state, integer *which, char *kind, char *file, integer *count, char *filtyp, integer *handle, char *source, logical *found, ftnlen kind_len, ftnlen file_len, ftnlen filtyp_len, ftnlen source_len);
extern int furnsh_(void *cspice_state, char *file, ftnlen file_len);
extern int ktotal_(void *cspice_state, char *kind, integer *count, ftnlen kind_len);
extern int kdata_(void *cspice_state, integer *which, char *kind, char *file, char *filtyp, char *source, integer *handle, logical *found, ftnlen kind_len, ftnlen file_len, ftnlen filtyp_len, ftnlen source_len);
extern int kinfo_(void *cspice_state, char *file, char *filtyp, char *source, integer *handle, logical *found, ftnlen file_len, ftnlen filtyp_len, ftnlen source_len);
extern int kclear_(void *cspice_state);
extern int unload_(void *cspice_state, char *file, ftnlen file_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: return_ 12 0 */
/*:ref: swpool_ 14 5 13 4 13 124 124 */
/*:ref: cvpool_ 14 3 13 12 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzldker_ 14 7 13 13 13 4 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: stpool_ 14 9 13 4 13 13 4 12 124 124 124 */
/*:ref: sepool_ 14 10 13 4 13 13 4 4 12 124 124 124 */
/*:ref: pos_ 4 5 13 13 4 124 124 */
/*:ref: gcpool_ 14 8 13 4 4 4 13 12 124 124 */
/*:ref: samsub_ 12 8 13 4 4 13 4 4 124 124 */
/*:ref: repsub_ 14 8 13 4 4 13 13 124 124 124 */
/*:ref: repmot_ 14 9 13 13 4 13 13 124 124 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: dvpool_ 14 2 13 124 */
/*:ref: fndnwd_ 14 5 13 4 4 4 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: spkuef_ 14 1 4 */
/*:ref: ckupf_ 14 1 4 */
/*:ref: pckuof_ 14 1 4 */
/*:ref: ekuef_ 14 1 4 */
/*:ref: zzdskusf_ 14 1 4 */
/*:ref: clpool_ 14 0 */
/*:ref: remlac_ 14 5 4 4 13 4 124 */
/*:ref: remlai_ 14 4 4 4 4 4 */
/*:ref: ldpool_ 14 2 13 124 */
/*:ref: spklef_ 14 3 13 4 124 */
/*:ref: cklpf_ 14 3 13 4 124 */
/*:ref: zzdsklsf_ 14 3 13 4 124 */
/*:ref: pcklof_ 14 3 13 4 124 */
/*:ref: eklef_ 14 3 13 4 124 */
 
extern doublereal kepleq_(void *cspice_state, doublereal *ml, doublereal *h__, doublereal *k);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: kpsolv_ 7 1 7 */
 
extern int kplfrm_(void *cspice_state, integer *frmcls, integer *idset);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: gnpool_ 14 8 13 4 4 4 13 12 124 124 */
/*:ref: gcpool_ 14 8 13 4 4 4 13 12 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: gipool_ 14 7 13 4 4 4 4 12 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: sizei_ 4 1 4 */
/*:ref: validi_ 14 3 4 4 4 */
 
extern doublereal kpsolv_(void *cspice_state, doublereal *evec);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int kxtrct_(void *cspice_state, char *keywd, char *terms, integer *nterms, char *string, logical *found, char *substr, ftnlen keywd_len, ftnlen terms_len, ftnlen string_len, ftnlen substr_len);
/*:ref: wdindx_ 4 4 13 13 124 124 */
/*:ref: nblen_ 4 2 13 124 */
/*:ref: fndnwd_ 14 5 13 4 4 4 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: shiftl_ 14 7 13 4 13 13 124 124 124 */
 
extern integer lastnb_(void *cspice_state, char *string, ftnlen string_len);
 
extern integer lastpc_(void *cspice_state, char *string, ftnlen string_len);
 
extern int latcyl_(void *cspice_state, doublereal *radius, doublereal *long__, doublereal *lat, doublereal *r__, doublereal *longc, doublereal *z__);
 
extern int latrec_(void *cspice_state, doublereal *radius, doublereal *long__, doublereal *lat, doublereal *rectan);
 
extern int latsph_(void *cspice_state, doublereal *radius, doublereal *long__, doublereal *lat, doublereal *rho, doublereal *colat, doublereal *longs);
/*:ref: halfpi_ 7 0 */
 
extern int latsrf_(void *cspice_state, char *method, char *target, doublereal *et, char *fixref, integer *npts, doublereal *lonlat, doublereal *srfpts, ftnlen method_len, ftnlen target_len, ftnlen fixref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: failed_ 12 0 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzsrftrk_ 14 2 4 12 */
/*:ref: zzprsmet_ 14 15 4 13 4 13 13 12 4 4 13 13 124 124 124 124 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: zzbodvcd_ 14 7 4 13 4 4 4 7 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: latrec_ 14 4 7 7 7 7 */
/*:ref: edpnt_ 14 5 7 7 7 7 7 */
/*:ref: zzsudski_ 14 4 4 4 4 4 */
/*:ref: zzmaxrad_ 14 1 7 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: zzraysfx_ 14 5 7 7 7 7 12 */
/*:ref: dpr_ 7 0 */
/*:ref: vdot_ 7 2 7 7 */
 
extern int lbuild_(void *cspice_state, char *items, integer *n, char *delim, char *list, ftnlen items_len, ftnlen delim_len, ftnlen list_len);
/*:ref: frstnb_ 4 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
 
extern int lcase_(void *cspice_state, char *in, char *out, ftnlen in_len, ftnlen out_len);
 
extern doublereal lgresp_(void *cspice_state, integer *n, doublereal *first, doublereal *step, doublereal *yvals, doublereal *work, doublereal *x);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int lgrind_(void *cspice_state, integer *n, doublereal *xvals, doublereal *yvals, doublereal *work, doublereal *x, doublereal *p, doublereal *dp);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
 
extern doublereal lgrint_(void *cspice_state, integer *n, doublereal *xvals, doublereal *yvals, doublereal *work, doublereal *x);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
 
extern int limbpt_(void *cspice_state, char *method, char *target, doublereal *et, char *fixref, char *abcorr, char *corloc, char *obsrvr, doublereal *refvec, doublereal *rolstp, integer *ncuts, doublereal *schstp, doublereal *soltol, integer *maxn, integer *npts, doublereal *points, doublereal *epochs, doublereal *tangts, ftnlen method_len, ftnlen target_len, ftnlen fixref_len, ftnlen abcorr_len, ftnlen corloc_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzsrftrk_ 14 2 4 12 */
/*:ref: zzprsmet_ 14 15 4 13 4 13 13 12 4 4 13 13 124 124 124 124 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: vzero_ 12 1 7 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: zzsudski_ 14 4 4 4 4 4 */
/*:ref: zzbodvcd_ 14 7 4 13 4 4 4 7 124 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: ssized_ 14 2 4 7 */
/*:ref: spkpos_ 14 11 13 7 13 13 13 7 7 124 124 124 124 */
/*:ref: zzcorepc_ 14 5 13 7 7 7 124 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: edlimb_ 14 5 7 7 7 7 7 */
/*:ref: el2cgv_ 14 4 7 7 7 7 */
/*:ref: ucrss_ 14 3 7 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vsclip_ 14 2 7 7 */
/*:ref: zzmaxrad_ 14 1 7 */
/*:ref: vrotv_ 14 4 7 7 7 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: zztangnt_ 14 14 4 7 4 4 4 4 4 7 7 7 7 7 7 7 */
/*:ref: cardd_ 4 1 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: zzraysfx_ 14 5 7 7 7 7 12 */
/*:ref: surfpt_ 14 7 7 7 7 7 7 7 12 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: spkssb_ 14 5 4 7 13 7 124 */
/*:ref: touchd_ 7 1 7 */
/*:ref: spkgps_ 14 7 4 7 13 4 7 7 124 */
/*:ref: stelab_ 14 3 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: pxform_ 14 6 13 13 7 7 124 124 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: mtxv_ 14 3 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
 
extern int ljucrs_(void *cspice_state, integer *n, char *input, char *output, ftnlen input_len, ftnlen output_len);
 
extern int ljust_(void *cspice_state, char *input, char *output, ftnlen input_len, ftnlen output_len);
 
extern int lnkan_(void *cspice_state, integer *pool, integer *new__);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int lnkfsl_(void *cspice_state, integer *head, integer *tail, integer *pool);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern integer lnkhl_(void *cspice_state, integer *node, integer *pool);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int lnkila_(void *cspice_state, integer *prev, integer *list, integer *pool);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int lnkilb_(void *cspice_state, integer *list, integer *next, integer *pool);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int lnkini_(void *cspice_state, integer *size, integer *pool);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern integer lnknfn_(void *cspice_state, integer *pool);
 
extern integer lnknxt_(void *cspice_state, integer *node, integer *pool);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern integer lnkprv_(void *cspice_state, integer *node, integer *pool);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern integer lnksiz_(void *cspice_state, integer *pool);
 
extern integer lnktl_(void *cspice_state, integer *node, integer *pool);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int lnkxsl_(void *cspice_state, integer *head, integer *tail, integer *pool);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int locati_(void *cspice_state, integer *id, integer *idsz, integer *list, integer *pool, integer *at, logical *presnt);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: lnknfn_ 4 1 4 */
/*:ref: lnksiz_ 4 1 4 */
/*:ref: lnkan_ 14 2 4 4 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: lnkxsl_ 14 3 4 4 4 */
/*:ref: lnkilb_ 14 3 4 4 4 */
 
extern int locln_(void *cspice_state, integer *unit, char *bmark, char *emark, char *line, integer *bline, integer *eline, logical *found, ftnlen bmark_len, ftnlen emark_len, ftnlen line_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ltrim_ 4 2 13 124 */
 
extern int lparse_(void *cspice_state, char *list, char *delim, integer *nmax, integer *n, char *items, ftnlen list_len, ftnlen delim_len, ftnlen items_len);
 
extern int lparsm_(void *cspice_state, char *list, char *delims, integer *nmax, integer *n, char *items, ftnlen list_len, ftnlen delims_len, ftnlen items_len);
 
extern int lparss_(void *cspice_state, char *list, char *delims, char *set, ftnlen list_len, ftnlen delims_len, ftnlen set_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sizec_ 4 2 13 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: insrtc_ 14 4 13 13 124 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: validc_ 14 4 4 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern doublereal lspcn_(void *cspice_state, char *body, doublereal *et, char *abcorr, ftnlen body_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: tipbod_ 14 5 13 4 7 7 124 */
/*:ref: spkgeo_ 14 7 4 7 13 4 7 7 124 */
/*:ref: ucrss_ 14 3 7 7 7 */
/*:ref: twovec_ 14 5 7 4 7 4 7 */
/*:ref: failed_ 12 0 */
/*:ref: spkezr_ 14 11 13 7 13 13 13 7 7 124 124 124 124 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: recrad_ 14 4 7 7 7 7 */
 
extern integer lstcld_(void *cspice_state, doublereal *x, integer *n, doublereal *array);
 
extern integer lstcli_(void *cspice_state, integer *x, integer *n, integer *array);
 
extern integer lstlec_(void *cspice_state, char *string, integer *n, char *array, ftnlen string_len, ftnlen array_len);
 
extern integer lstled_(void *cspice_state, doublereal *x, integer *n, doublereal *array);
 
extern integer lstlei_(void *cspice_state, integer *x, integer *n, integer *array);
 
extern integer lstltc_(void *cspice_state, char *string, integer *n, char *array, ftnlen string_len, ftnlen array_len);
 
extern integer lstltd_(void *cspice_state, doublereal *x, integer *n, doublereal *array);
 
extern integer lstlti_(void *cspice_state, integer *x, integer *n, integer *array);
 
extern int ltime_(void *cspice_state, doublereal *etobs, integer *obs, char *dir, integer *targ, doublereal *ettarg, doublereal *elapsd, ftnlen dir_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: clight_ 7 0 */
/*:ref: spkgeo_ 14 7 4 7 13 4 7 7 124 */
/*:ref: vdist_ 7 2 7 7 */
/*:ref: failed_ 12 0 */
 
extern integer ltrim_(void *cspice_state, char *string, ftnlen string_len);
/*:ref: frstnb_ 4 2 13 124 */
 
extern int lun2fn_(void *cspice_state, integer *lunit, char *filnam, ftnlen filnam_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int lx4dec_(void *cspice_state, char *string, integer *first, integer *last, integer *nchar, ftnlen string_len);
/*:ref: lx4uns_ 14 5 13 4 4 4 124 */
/*:ref: lx4sgn_ 14 5 13 4 4 4 124 */
 
extern int lx4num_(void *cspice_state, char *string, integer *first, integer *last, integer *nchar, ftnlen string_len);
/*:ref: lx4dec_ 14 5 13 4 4 4 124 */
/*:ref: lx4sgn_ 14 5 13 4 4 4 124 */
 
extern int lx4sgn_(void *cspice_state, char *string, integer *first, integer *last, integer *nchar, ftnlen string_len);
/*:ref: lx4uns_ 14 5 13 4 4 4 124 */
 
extern int lx4uns_(void *cspice_state, char *string, integer *first, integer *last, integer *nchar, ftnlen string_len);
 
extern int lxname_(void *cspice_state, char *hdchrs, char *tlchrs, char *string, integer *first, integer *last, integer *idspec, integer *nchar, ftnlen hdchrs_len, ftnlen tlchrs_len, ftnlen string_len);
extern int lxidnt_(void *cspice_state, integer *idspec, char *string, integer *first, integer *last, integer *nchar, ftnlen string_len);
extern int lxdfid_(void *cspice_state, integer *idspec);
extern int lxcsid_(void *cspice_state, char *hdchrs, char *tlchrs, integer *idspec, ftnlen hdchrs_len, ftnlen tlchrs_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: bsrchi_ 4 3 4 4 4 */
/*:ref: ssizei_ 14 2 4 4 */
/*:ref: validi_ 14 3 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: appndi_ 14 2 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: insrti_ 14 2 4 4 */
/*:ref: cardi_ 4 1 4 */
 
extern int lxqstr_(void *cspice_state, char *string, char *qchar, integer *first, integer *last, integer *nchar, ftnlen string_len, ftnlen qchar_len);
 
extern int m2eul_(void *cspice_state, doublereal *r__, integer *axis3, integer *axis2, integer *axis1, doublereal *angle3, doublereal *angle2, doublereal *angle1);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: isrot_ 12 3 7 7 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: mxm_ 14 3 7 7 7 */
/*:ref: mtxm_ 14 3 7 7 7 */
 
extern int m2q_(void *cspice_state, doublereal *r__, doublereal *q);
/*:ref: isrot_ 12 3 7 7 7 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern logical matchi_(void *cspice_state, char *string, char *templ, char *wstr, char *wchr, ftnlen string_len, ftnlen templ_len, ftnlen wstr_len, ftnlen wchr_len);
/*:ref: frstnb_ 4 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: samch_ 12 6 13 4 13 4 124 124 */
/*:ref: nechr_ 12 4 13 13 124 124 */
/*:ref: samchi_ 12 6 13 4 13 4 124 124 */
 
extern logical matchw_(void *cspice_state, char *string, char *templ, char *wstr, char *wchr, ftnlen string_len, ftnlen templ_len, ftnlen wstr_len, ftnlen wchr_len);
/*:ref: frstnb_ 4 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: samch_ 12 6 13 4 13 4 124 124 */
 
extern int maxac_(void *cspice_state, char *array, integer *ndim, char *maxval, integer *loc, ftnlen array_len, ftnlen maxval_len);
 
extern int maxad_(void *cspice_state, doublereal *array, integer *ndim, doublereal *maxval, integer *loc);
 
extern int maxai_(void *cspice_state, integer *array, integer *ndim, integer *maxval, integer *loc);
 
extern int mequ_(void *cspice_state, doublereal *m1, doublereal *mout);
/*:ref: moved_ 14 3 7 4 7 */
 
extern int mequg_(void *cspice_state, doublereal *m1, integer *nr, integer *nc, doublereal *mout);
/*:ref: moved_ 14 3 7 4 7 */
 
extern int minac_(void *cspice_state, char *array, integer *ndim, char *minval, integer *loc, ftnlen array_len, ftnlen minval_len);
 
extern int minad_(void *cspice_state, doublereal *array, integer *ndim, doublereal *minval, integer *loc);
 
extern int minai_(void *cspice_state, integer *array, integer *ndim, integer *minval, integer *loc);
 
extern int movec_(void *cspice_state, char *arrfrm, integer *ndim, char *arrto, ftnlen arrfrm_len, ftnlen arrto_len);
 
extern int movei_(void *cspice_state, integer *arrfrm, integer *ndim, integer *arrto);
 
extern int mtxm_(void *cspice_state, doublereal *m1, doublereal *m2, doublereal *mout);
/*:ref: moved_ 14 3 7 4 7 */
 
extern int mtxmg_(void *cspice_state, doublereal *m1, doublereal *m2, integer *nc1, integer *nr1r2, integer *nc2, doublereal *mout);
 
extern int mtxv_(void *cspice_state, doublereal *matrix, doublereal *vin, doublereal *vout);
 
extern int mtxvg_(void *cspice_state, doublereal *m1, doublereal *v2, integer *nc1, integer *nr1r2, doublereal *vout);
 
extern int mxm_(void *cspice_state, doublereal *m1, doublereal *m2, doublereal *mout);
/*:ref: moved_ 14 3 7 4 7 */
 
extern int mxmg_(void *cspice_state, doublereal *m1, doublereal *m2, integer *row1, integer *col1, integer *col2, doublereal *mout);
 
extern int mxmt_(void *cspice_state, doublereal *m1, doublereal *m2, doublereal *mout);
/*:ref: moved_ 14 3 7 4 7 */
 
extern int mxmtg_(void *cspice_state, doublereal *m1, doublereal *m2, integer *nr1, integer *nc1c2, integer *nr2, doublereal *mout);
 
extern int mxv_(void *cspice_state, doublereal *matrix, doublereal *vin, doublereal *vout);
 
extern int mxvg_(void *cspice_state, doublereal *m1, doublereal *v2, integer *nr1, integer *nc1r2, doublereal *vout);
 
extern integer nblen_(void *cspice_state, char *string, ftnlen string_len);
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: frstnb_ 4 2 13 124 */
 
extern integer nbwid_(void *cspice_state, char *array, integer *nelt, ftnlen array_len);
 
extern integer ncpos_(void *cspice_state, char *str, char *chars, integer *start, ftnlen str_len, ftnlen chars_len);
 
extern integer ncposr_(void *cspice_state, char *str, char *chars, integer *start, ftnlen str_len, ftnlen chars_len);
 
extern int nearpt_(void *cspice_state, doublereal *positn, doublereal *a, doublereal *b, doublereal *c__, doublereal *npoint, doublereal *alt);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: orderd_ 14 3 7 4 4 */
/*:ref: reordd_ 14 3 4 4 7 */
/*:ref: vsclip_ 14 2 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: dpmax_ 7 0 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: touchd_ 7 1 7 */
/*:ref: brcktd_ 7 3 7 7 7 */
/*:ref: approx_ 12 3 7 7 7 */
/*:ref: vdist_ 7 2 7 7 */
/*:ref: surfnm_ 14 5 7 7 7 7 7 */
/*:ref: vperp_ 14 3 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
 
extern int nextwd_(void *cspice_state, char *string, char *next, char *rest, ftnlen string_len, ftnlen next_len, ftnlen rest_len);
/*:ref: ljust_ 14 4 13 13 124 124 */
 
extern logical notru_(void *cspice_state, logical *logcls, integer *n);
 
extern int nparsd_(void *cspice_state, char *string, doublereal *x, char *error, integer *ptr, ftnlen string_len, ftnlen error_len);
/*:ref: dpmax_ 7 0 */
/*:ref: zzinssub_ 14 7 13 13 4 13 124 124 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: pi_ 7 0 */
 
extern int nparsi_(void *cspice_state, char *string, integer *n, char *error, integer *pnter, ftnlen string_len, ftnlen error_len);
/*:ref: intmax_ 4 0 */
/*:ref: intmin_ 4 0 */
/*:ref: nparsd_ 14 6 13 7 13 4 124 124 */
 
extern int npedln_(void *cspice_state, doublereal *a, doublereal *b, doublereal *c__, doublereal *linept, doublereal *linedr, doublereal *pnear, doublereal *dist);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: unorm_ 14 3 7 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: surfpt_ 14 7 7 7 7 7 7 7 12 */
/*:ref: vscl_ 14 3 7 7 7 */
/*:ref: nvc2pl_ 14 3 7 7 7 */
/*:ref: inedpl_ 14 6 7 7 7 7 7 12 */
/*:ref: pjelpl_ 14 3 7 7 7 */
/*:ref: vprjp_ 14 3 7 7 7 */
/*:ref: npelpt_ 14 4 7 7 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: vprjpi_ 14 5 7 7 7 7 12 */
/*:ref: vsclip_ 14 2 7 7 */
 
extern int npelpt_(void *cspice_state, doublereal *point, doublereal *ellips, doublereal *pnear, doublereal *dist);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: el2cgv_ 14 4 7 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vsclip_ 14 2 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: twovec_ 14 5 7 4 7 4 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vpack_ 14 4 7 7 7 7 */
/*:ref: nearpt_ 14 6 7 7 7 7 7 7 */
/*:ref: mtxv_ 14 3 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: vdist_ 7 2 7 7 */
 
extern int nplnpt_(void *cspice_state, doublereal *linpt, doublereal *lindir, doublereal *point, doublereal *pnear, doublereal *dist);
/*:ref: return_ 12 0 */
/*:ref: vzero_ 12 1 7 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vproj_ 14 3 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: vdist_ 7 2 7 7 */
 
extern int npsgpt_(void *cspice_state, doublereal *ep1, doublereal *ep2, doublereal *point, doublereal *pnear, doublereal *dist);
/*:ref: return_ 12 0 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vzero_ 12 1 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vdist_ 7 2 7 7 */
/*:ref: nplnpt_ 14 5 7 7 7 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: vdot_ 7 2 7 7 */
 
extern int nthwd_(void *cspice_state, char *string, integer *nth, char *word, integer *loc, ftnlen string_len, ftnlen word_len);
 
extern int nvc2pl_(void *cspice_state, doublereal *normal, doublereal *const__, doublereal *plane);
/*:ref: return_ 12 0 */
/*:ref: unorm_ 14 3 7 7 7 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: vequ_ 14 2 7 7 */
 
extern int nvp2pl_(void *cspice_state, doublereal *normal, doublereal *point, doublereal *plane);
/*:ref: return_ 12 0 */
/*:ref: vzero_ 12 1 7 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: vequ_ 14 2 7 7 */
 
extern int occult_(void *cspice_state, char *targ1, char *shape1, char *frame1, char *targ2, char *shape2, char *frame2, char *abcorr, char *obsrvr, doublereal *et, integer *ocltid, ftnlen targ1_len, ftnlen shape1_len, ftnlen frame1_len, ftnlen targ2_len, ftnlen shape2_len, ftnlen frame2_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: bods2c_ 14 4 13 4 12 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzprsmet_ 14 15 4 13 4 13 13 12 4 4 13 13 124 124 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: zzgfocin_ 14 18 13 13 13 13 13 13 13 13 13 124 124 124 124 124 124 124 124 124 */
/*:ref: zzgfocst_ 14 2 7 12 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern logical odd_(void *cspice_state, integer *i__);
 
extern logical opsgnd_(void *cspice_state, doublereal *x, doublereal *y);
 
extern logical opsgni_(void *cspice_state, integer *x, integer *y);
 
extern integer ordc_(void *cspice_state, char *item, char *set, ftnlen item_len, ftnlen set_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern integer ordd_(void *cspice_state, doublereal *item, doublereal *set);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: bsrchd_ 4 3 7 4 7 */
/*:ref: cardd_ 4 1 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int orderc_(void *cspice_state, char *array, integer *ndim, integer *iorder, ftnlen array_len);
/*:ref: swapi_ 14 2 4 4 */
 
extern int orderd_(void *cspice_state, doublereal *array, integer *ndim, integer *iorder);
/*:ref: swapi_ 14 2 4 4 */
 
extern int orderi_(void *cspice_state, integer *array, integer *ndim, integer *iorder);
/*:ref: swapi_ 14 2 4 4 */
 
extern integer ordi_(void *cspice_state, integer *item, integer *set);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: bsrchi_ 4 3 4 4 4 */
/*:ref: cardi_ 4 1 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int oscelt_(void *cspice_state, doublereal *state, doublereal *et, doublereal *mu, doublereal *elts);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vzero_ 12 1 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: vpack_ 14 4 7 7 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vsclip_ 14 2 7 7 */
/*:ref: exact_ 7 3 7 7 7 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: pi_ 7 0 */
/*:ref: twopi_ 7 0 */
/*:ref: ucrss_ 14 3 7 7 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: dacosh_ 7 1 7 */
 
extern int oscltx_(void *cspice_state, doublereal *state, doublereal *et, doublereal *mu, doublereal *elts);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dpmax_ 7 0 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: oscelt_ 14 4 7 7 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: unorm_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: exact_ 7 3 7 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: ucrss_ 14 3 7 7 7 */
/*:ref: twovec_ 14 5 7 4 7 4 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: recrad_ 14 4 7 7 7 7 */
/*:ref: twopi_ 7 0 */
 
extern int outmsg_(void *cspice_state, char *list, ftnlen list_len);
/*:ref: lparse_ 14 8 13 13 4 4 13 124 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: getdev_ 14 2 13 124 */
/*:ref: wrline_ 14 4 13 13 124 124 */
/*:ref: msgsel_ 12 2 13 124 */
/*:ref: tkvrsn_ 14 4 13 13 124 124 */
/*:ref: getsms_ 14 2 13 124 */
/*:ref: expln_ 14 4 13 13 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: getlms_ 14 2 13 124 */
/*:ref: wdcnt_ 4 2 13 124 */
/*:ref: nextwd_ 14 6 13 13 13 124 124 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: trcdep_ 14 1 4 */
/*:ref: trcnam_ 14 3 4 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
 
extern int packac_(void *cspice_state, char *in, integer *pack, integer *npack, integer *maxout, integer *nout, char *out, ftnlen in_len, ftnlen out_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int packad_(void *cspice_state, doublereal *in, integer *pack, integer *npack, integer *maxout, integer *nout, doublereal *out);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int packai_(void *cspice_state, integer *in, integer *pack, integer *npack, integer *maxout, integer *nout, integer *out);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int parsqs_(void *cspice_state, char *string, char *qchar, char *value, integer *length, logical *error, char *errmsg, integer *ptr, ftnlen string_len, ftnlen qchar_len, ftnlen value_len, ftnlen errmsg_len);
/*:ref: frstnb_ 4 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
 
extern int partof_(void *cspice_state, doublereal *ma, doublereal *d__);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dcbrt_ 7 1 7 */
 
extern int pck03a_(void *cspice_state, integer *handle, integer *ncsets, doublereal *coeffs, doublereal *epochs);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sgwfpk_ 14 5 4 4 7 4 7 */
 
extern int pck03b_(void *cspice_state, integer *handle, char *segid, integer *body, char *frame, doublereal *first, doublereal *last, integer *chbdeg, ftnlen segid_len, ftnlen frame_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: pckpds_ 14 7 4 13 4 7 7 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: sgbwfs_ 14 8 4 7 13 4 7 4 4 124 */
 
extern int pck03e_(void *cspice_state, integer *handle);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sgwes_ 14 1 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int pckbsr_(void *cspice_state, char *fname, integer *handle, integer *body, doublereal *et, doublereal *descr, char *ident, logical *found, ftnlen fname_len, ftnlen ident_len);
extern int pcklof_(void *cspice_state, char *fname, integer *handle, ftnlen fname_len);
extern int pckuof_(void *cspice_state, integer *handle);
extern int pcksfs_(void *cspice_state, integer *body, doublereal *et, integer *handle, doublereal *descr, char *ident, logical *found, ftnlen ident_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lnkini_ 14 2 4 4 */
/*:ref: dafopr_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: dafcls_ 14 1 4 */
/*:ref: lnknxt_ 4 2 4 4 */
/*:ref: lnkfsl_ 14 3 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: intmax_ 4 0 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: lnkprv_ 4 2 4 4 */
/*:ref: dpmin_ 7 0 */
/*:ref: dpmax_ 7 0 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: dafbfs_ 14 1 4 */
/*:ref: daffna_ 14 1 12 */
/*:ref: dafgs_ 14 1 7 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: dafbbs_ 14 1 4 */
/*:ref: daffpa_ 14 1 12 */
/*:ref: lnknfn_ 4 1 4 */
/*:ref: lnkan_ 14 2 4 4 */
/*:ref: dafgn_ 14 2 13 124 */
/*:ref: lnkilb_ 14 3 4 4 4 */
/*:ref: lnkila_ 14 3 4 4 4 */
/*:ref: lnktl_ 4 2 4 4 */
 
extern int pckcls_(void *cspice_state, integer *handle);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafbfs_ 14 1 4 */
/*:ref: daffna_ 14 1 12 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: dafcls_ 14 1 4 */
 
extern int pckcov_(void *cspice_state, char *pck, integer *idcode, doublereal *cover, ftnlen pck_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: getfat_ 14 6 13 13 13 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafopr_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafbfs_ 14 1 4 */
/*:ref: daffna_ 14 1 12 */
/*:ref: dafgs_ 14 1 7 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: wninsd_ 14 3 7 7 7 */
/*:ref: dafcls_ 14 1 4 */
 
extern int pcke02_(void *cspice_state, doublereal *et, doublereal *record, doublereal *eulang);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: spke02_ 14 3 7 7 7 */
/*:ref: twopi_ 7 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int pcke03_(void *cspice_state, doublereal *et, doublereal *record, doublereal *rotmat);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chbval_ 14 5 7 4 7 7 7 */
/*:ref: rpd_ 7 0 */
/*:ref: halfpi_ 7 0 */
/*:ref: eul2m_ 14 7 7 7 7 4 4 4 7 */
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int pcke20_(void *cspice_state, doublereal *et, doublereal *record, doublereal *eulang);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: spke20_ 14 3 7 7 7 */
/*:ref: twopi_ 7 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int pckeul_(void *cspice_state, integer *body, doublereal *et, logical *found, char *ref, doublereal *eulang, ftnlen ref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: pcksfs_ 14 7 4 7 4 7 13 12 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: irfnam_ 14 3 4 13 124 */
/*:ref: pckr02_ 14 4 4 7 7 7 */
/*:ref: pcke02_ 14 3 7 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int pckfrm_(void *cspice_state, char *pck, integer *ids, ftnlen pck_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: getfat_ 14 6 13 13 13 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafopr_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafbfs_ 14 1 4 */
/*:ref: daffna_ 14 1 12 */
/*:ref: dafgs_ 14 1 7 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: insrti_ 14 2 4 4 */
/*:ref: dafcls_ 14 1 4 */
 
extern int pckmat_(void *cspice_state, integer *body, doublereal *et, integer *ref, doublereal *tsipm, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: pcksfs_ 14 7 4 7 4 7 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: pckr02_ 14 4 4 7 7 7 */
/*:ref: pcke02_ 14 3 7 7 7 */
/*:ref: eul2xf_ 14 5 7 4 4 4 7 */
/*:ref: sgfcon_ 14 5 4 7 4 4 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: pckr03_ 14 4 4 7 7 7 */
/*:ref: pcke03_ 14 3 7 7 7 */
/*:ref: pckr20_ 14 4 4 7 7 7 */
/*:ref: pcke20_ 14 3 7 7 7 */
 
extern int pckopn_(void *cspice_state, char *name__, char *ifname, integer *ncomch, integer *handle, ftnlen name_len, ftnlen ifname_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafonw_ 14 10 13 13 4 4 13 4 4 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int pckpds_(void *cspice_state, integer *body, char *frame, integer *type__, doublereal *first, doublereal *last, doublereal *descr, ftnlen frame_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
 
extern int pckr02_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int pckr03_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sgfcon_ 14 5 4 7 4 4 7 */
/*:ref: sgfrvi_ 14 6 4 7 7 7 4 12 */
/*:ref: sgfpkt_ 14 6 4 7 4 4 7 4 */
 
extern int pckr20_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: j2000_ 7 0 */
/*:ref: spd_ 7 0 */
/*:ref: remlad_ 14 4 4 4 7 4 */
/*:ref: vsclip_ 14 2 7 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int pckuds_(void *cspice_state, doublereal *descr, integer *body, integer *frame, integer *type__, doublereal *first, doublereal *last, integer *begin, integer *end);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int pckw02_(void *cspice_state, integer *handle, integer *body, char *frame, doublereal *first, doublereal *last, char *segid, doublereal *intlen, integer *n, integer *polydg, doublereal *cdata, doublereal *btime, ftnlen frame_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: chckid_ 14 5 13 4 13 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern int pckw20_(void *cspice_state, integer *handle, integer *clssid, char *frame, doublereal *first, doublereal *last, char *segid, doublereal *intlen, integer *n, integer *polydg, doublereal *cdata, doublereal *ascale, doublereal *tscale, doublereal *initjd, doublereal *initfr, ftnlen frame_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: spd_ 7 0 */
/*:ref: j2000_ 7 0 */
/*:ref: chckid_ 14 5 13 4 13 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern integer pcwid_(void *cspice_state, char *array, integer *nelt, ftnlen array_len);
 
extern int pgrrec_(void *cspice_state, char *body, doublereal *lon, doublereal *lat, doublereal *alt, doublereal *re, doublereal *f, doublereal *rectan, ftnlen body_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: gcpool_ 14 8 13 4 4 4 13 12 124 124 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: plnsns_ 4 1 4 */
/*:ref: georec_ 14 6 7 7 7 7 7 7 */
 
extern doublereal phaseq_(void *cspice_state, doublereal *et, char *target, char *illmn, char *obsrvr, char *abcorr, ftnlen target_len, ftnlen illmn_len, ftnlen obsrvr_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: zzgfpaq_ 14 7 7 4 4 4 13 7 124 */
 
extern doublereal pi_(void *cspice_state);
 
extern int pjelpl_(void *cspice_state, doublereal *elin, doublereal *plane, doublereal *elout);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: el2cgv_ 14 4 7 7 7 7 */
/*:ref: pl2nvc_ 14 3 7 7 7 */
/*:ref: vperp_ 14 3 7 7 7 */
/*:ref: vprjp_ 14 3 7 7 7 */
/*:ref: cgv2el_ 14 4 7 7 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int pl2nvc_(void *cspice_state, doublereal *plane, doublereal *normal, doublereal *const__);
/*:ref: vequ_ 14 2 7 7 */
 
extern int pl2nvp_(void *cspice_state, doublereal *plane, doublereal *normal, doublereal *point);
/*:ref: pl2nvc_ 14 3 7 7 7 */
/*:ref: vscl_ 14 3 7 7 7 */
 
extern int pl2psv_(void *cspice_state, doublereal *plane, doublereal *point, doublereal *span1, doublereal *span2);
/*:ref: pl2nvp_ 14 3 7 7 7 */
/*:ref: frame_ 14 3 7 7 7 */
 
extern integer plnsns_(void *cspice_state, integer *bodid);
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: gdpool_ 14 7 13 4 4 4 7 12 124 */
 
extern doublereal pltar_(void *cspice_state, integer *nv, doublereal *vrtces, integer *np, integer *plates);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
 
extern int pltexp_(void *cspice_state, doublereal *iverts, doublereal *delta, doublereal *overts);
 
extern int pltnp_(void *cspice_state, doublereal *point, doublereal *v1, doublereal *v2, doublereal *v3, doublereal *pnear, doublereal *dist);
/*:ref: return_ 12 0 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: vzero_ 12 1 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vdist_ 7 2 7 7 */
/*:ref: npsgpt_ 14 5 7 7 7 7 7 */
/*:ref: vperp_ 14 3 7 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
 
extern int pltnrm_(void *cspice_state, doublereal *v1, doublereal *v2, doublereal *v3, doublereal *normal);
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vcrss_ 14 3 7 7 7 */
 
extern doublereal pltvol_(void *cspice_state, integer *nv, doublereal *vrtces, integer *np, integer *plates);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: det_ 7 1 7 */
 
extern int polyds_(void *cspice_state, doublereal *coeffs, integer *deg, integer *nderiv, doublereal *t, doublereal *p);
 
extern int pool_(void *cspice_state, char *kernel, integer *unit, char *name__, char *names, integer *nnames, char *agent, integer *n, doublereal *values, logical *found, logical *update, integer *start, integer *room, char *cvals, integer *ivals, char *type__, char *uwvars, integer *uwptrs, integer *uwpool, char *uwagnt, integer *usrctr, ftnlen kernel_len, ftnlen name_len, ftnlen names_len, ftnlen agent_len, ftnlen cvals_len, ftnlen type_len, ftnlen uwvars_len, ftnlen uwagnt_len);
extern int clpool_(void *cspice_state);
extern int ldpool_(void *cspice_state, char *kernel, ftnlen kernel_len);
extern int rtpool_(void *cspice_state, char *name__, integer *n, doublereal *values, logical *found, ftnlen name_len);
extern int expool_(void *cspice_state, char *name__, logical *found, ftnlen name_len);
extern int wrpool_(void *cspice_state, integer *unit);
extern int swpool_(void *cspice_state, char *agent, integer *nnames, char *names, ftnlen agent_len, ftnlen names_len);
extern int cvpool_(void *cspice_state, char *agent, logical *update, ftnlen agent_len);
extern int gcpool_(void *cspice_state, char *name__, integer *start, integer *room, integer *n, char *cvals, logical *found, ftnlen name_len, ftnlen cvals_len);
extern int gdpool_(void *cspice_state, char *name__, integer *start, integer *room, integer *n, doublereal *values, logical *found, ftnlen name_len);
extern int gipool_(void *cspice_state, char *name__, integer *start, integer *room, integer *n, integer *ivals, logical *found, ftnlen name_len);
extern int dtpool_(void *cspice_state, char *name__, logical *found, integer *n, char *type__, ftnlen name_len, ftnlen type_len);
extern int pcpool_(void *cspice_state, char *name__, integer *n, char *cvals, ftnlen name_len, ftnlen cvals_len);
extern int pdpool_(void *cspice_state, char *name__, integer *n, doublereal *values, ftnlen name_len);
extern int pipool_(void *cspice_state, char *name__, integer *n, integer *ivals, ftnlen name_len);
extern int lmpool_(void *cspice_state, char *cvals, integer *n, ftnlen cvals_len);
extern int szpool_(void *cspice_state, char *name__, integer *n, logical *found, ftnlen name_len);
extern int dvpool_(void *cspice_state, char *name__, ftnlen name_len);
extern int gnpool_(void *cspice_state, char *name__, integer *start, integer *room, integer *n, char *cvals, logical *found, ftnlen name_len, ftnlen cvals_len);
extern int dwpool_(void *cspice_state, char *agent, ftnlen agent_len);
extern int zzvupool_(void *cspice_state, char *uwvars, integer *uwptrs, integer *uwpool, char *uwagnt, ftnlen uwvars_len, ftnlen uwagnt_len);
extern int zzpctrck_(void *cspice_state, integer *usrctr, logical *update);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzpini_ 14 28 12 4 4 4 13 13 4 4 4 4 4 4 4 13 4 4 13 13 13 13 4 124 124 124 124 124 124 124 */
/*:ref: zzctrinc_ 14 1 4 */
/*:ref: lnkini_ 14 2 4 4 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: zznwpool_ 14 14 13 13 4 4 13 13 13 13 124 124 124 124 124 124 */
/*:ref: rdknew_ 14 2 13 124 */
/*:ref: zzrvar_ 14 13 4 4 13 4 4 7 4 13 13 12 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: elemc_ 12 4 13 13 124 124 */
/*:ref: cltext_ 14 2 13 124 */
/*:ref: zzhash_ 4 2 13 124 */
/*:ref: ioerr_ 14 5 13 13 4 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sizec_ 4 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzgapool_ 14 10 13 13 4 4 13 13 124 124 124 124 */
/*:ref: lnknfn_ 4 1 4 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: lnkan_ 14 2 4 4 */
/*:ref: lnktl_ 4 2 4 4 */
/*:ref: lnkila_ 14 3 4 4 4 */
/*:ref: lstltc_ 4 5 13 4 13 124 124 */
/*:ref: inslac_ 14 7 13 4 4 13 4 124 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: inslai_ 14 5 4 4 4 4 4 */
/*:ref: insrtc_ 14 4 13 13 124 124 */
/*:ref: removc_ 14 4 13 13 124 124 */
/*:ref: intmax_ 4 0 */
/*:ref: intmin_ 4 0 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: zzgpnm_ 14 15 4 4 13 4 4 7 4 13 13 12 4 4 124 124 124 */
/*:ref: zzcln_ 14 7 4 4 4 4 4 4 4 */
/*:ref: lnkfsl_ 14 3 4 4 4 */
/*:ref: zzrvbf_ 14 17 13 4 4 4 4 13 4 4 7 4 13 13 12 124 124 124 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: matchi_ 12 8 13 13 13 13 124 124 124 124 */
/*:ref: lnknxt_ 4 2 4 4 */
/*:ref: remlai_ 14 4 4 4 4 4 */
/*:ref: copyc_ 14 4 13 13 124 124 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: movec_ 14 5 13 4 13 124 124 */
/*:ref: zzctrchk_ 14 3 4 4 12 */
 
extern integer pos_(void *cspice_state, char *str, char *substr, integer *start, ftnlen str_len, ftnlen substr_len);
 
extern integer posr_(void *cspice_state, char *str, char *substr, integer *start, ftnlen str_len, ftnlen substr_len);
 
extern int prefix_(void *cspice_state, char *pref, integer *spaces, char *string, ftnlen pref_len, ftnlen string_len);
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: shiftr_ 14 7 13 4 13 13 124 124 124 */
 
extern doublereal prodad_(void *cspice_state, doublereal *array, integer *n);
 
extern integer prodai_(void *cspice_state, integer *array, integer *n);
 
extern int prompt_(void *cspice_state, char *prmpt, char *string, ftnlen prmpt_len, ftnlen string_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern int prop2b_(void *cspice_state, doublereal *gm, doublereal *pvinit, doublereal *dt, doublereal *pvprop);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vzero_ 12 1 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: dpmax_ 7 0 */
/*:ref: brckti_ 4 3 4 4 4 */
/*:ref: brcktd_ 7 3 7 7 7 */
/*:ref: stmp03_ 14 5 7 7 7 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: vequg_ 14 3 7 4 7 */
 
extern int prsdp_(void *cspice_state, char *string, doublereal *dpval, ftnlen string_len);
/*:ref: nparsd_ 14 6 13 7 13 4 124 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int prsint_(void *cspice_state, char *string, integer *intval, ftnlen string_len);
/*:ref: nparsi_ 14 6 13 4 13 4 124 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int prtenc_(void *cspice_state, integer *number, char *string, ftnlen string_len);
extern int prtdec_(void *cspice_state, char *string, integer *number, ftnlen string_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern logical prtpkg_(void *cspice_state, logical *short__, logical *long__, logical *expl, logical *trace, logical *dfault, char *type__, ftnlen type_len);
extern logical setprt_(void *cspice_state, logical *short__, logical *expl, logical *long__, logical *trace, logical *dfault);
extern logical msgsel_(void *cspice_state, char *type__, ftnlen type_len);
/*:ref: getdev_ 14 2 13 124 */
/*:ref: wrline_ 14 4 13 13 124 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
 
extern int psv2pl_(void *cspice_state, doublereal *point, doublereal *span1, doublereal *span2, doublereal *plane);
/*:ref: return_ 12 0 */
/*:ref: ucrss_ 14 3 7 7 7 */
/*:ref: vzero_ 12 1 7 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: vequ_ 14 2 7 7 */
 
extern int putact_(void *cspice_state, integer *action);
extern int getact_(void *cspice_state, integer *action);
 
extern int putdev_(void *cspice_state, char *device, ftnlen device_len);
extern int getdev_(void *cspice_state, char *device, ftnlen device_len);
 
extern int putlms_(void *cspice_state, char *msg, ftnlen msg_len);
extern int getlms_(void *cspice_state, char *msg, ftnlen msg_len);
 
extern int putsms_(void *cspice_state, char *msg, ftnlen msg_len);
extern int getsms_(void *cspice_state, char *msg, ftnlen msg_len);
 
extern int pxform_(void *cspice_state, char *from, char *to, doublereal *et, doublereal *rotate, ftnlen from_len, ftnlen to_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: refchg_ 14 4 4 4 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int pxfrm2_(void *cspice_state, char *from, char *to, doublereal *etfrom, doublereal *etto, doublereal *rotate, ftnlen from_len, ftnlen to_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: refchg_ 14 4 4 4 7 7 */
/*:ref: mxm_ 14 3 7 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int q2m_(void *cspice_state, doublereal *q, doublereal *r__);
 
extern int qderiv_(void *cspice_state, integer *n, doublereal *f0, doublereal *f2, doublereal *delta, doublereal *dfdt);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vlcomg_ 14 6 4 7 7 7 7 7 */
 
extern int qdq2av_(void *cspice_state, doublereal *q, doublereal *dq, doublereal *av);
/*:ref: vhatg_ 14 3 7 4 7 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: qxq_ 14 3 7 7 7 */
/*:ref: vscl_ 14 3 7 7 7 */
 
extern int quote_(void *cspice_state, char *in, char *left, char *right, char *out, ftnlen in_len, ftnlen left_len, ftnlen right_len, ftnlen out_len);
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: frstnb_ 4 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
 
extern int qxq_(void *cspice_state, doublereal *q1, doublereal *q2, doublereal *qout);
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: vlcom3_ 14 7 7 7 7 7 7 7 7 */
 
extern int radrec_(void *cspice_state, doublereal *range, doublereal *ra, doublereal *dec, doublereal *rectan);
/*:ref: latrec_ 14 4 7 7 7 7 */
 
extern int rav2xf_(void *cspice_state, doublereal *rot, doublereal *av, doublereal *xform);
/*:ref: mxm_ 14 3 7 7 7 */
 
extern int raxisa_(void *cspice_state, doublereal *matrix, doublereal *axis, doublereal *angle);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: m2q_ 14 2 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vzero_ 12 1 7 */
/*:ref: pi_ 7 0 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vnorm_ 7 1 7 */
 
extern int rdencc_(void *cspice_state, integer *unit, integer *n, char *data, ftnlen data_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: hx2int_ 14 6 13 4 12 13 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
 
extern int rdencd_(void *cspice_state, integer *unit, integer *n, doublereal *data);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: hx2dp_ 14 6 13 7 12 13 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
 
extern int rdenci_(void *cspice_state, integer *unit, integer *n, integer *data);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: hx2int_ 14 6 13 4 12 13 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
 
extern int rdker_(void *cspice_state, char *kernel, char *line, integer *number, logical *eof, ftnlen kernel_len, ftnlen line_len);
extern int rdknew_(void *cspice_state, char *kernel, ftnlen kernel_len);
extern int rdkdat_(void *cspice_state, char *line, logical *eof, ftnlen line_len);
extern int rdklin_(void *cspice_state, char *kernel, integer *number, ftnlen kernel_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: cltext_ 14 2 13 124 */
/*:ref: zzsetnnread_ 14 1 12 */
/*:ref: rdtext_ 14 5 13 13 12 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: failed_ 12 0 */
 
extern int rdkvar_(void *cspice_state, char *tabsym, integer *tabptr, doublereal *tabval, char *name__, logical *eof, ftnlen tabsym_len, ftnlen name_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: rdkdat_ 14 3 13 12 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: replch_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: nextwd_ 14 6 13 13 13 124 124 124 */
/*:ref: sydeld_ 14 6 13 13 4 7 124 124 */
/*:ref: tparse_ 14 5 13 7 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: nparsd_ 14 6 13 7 13 4 124 124 */
/*:ref: syenqd_ 14 7 13 7 13 4 7 124 124 */
 
extern int rdnbl_(void *cspice_state, char *file, char *line, logical *eof, ftnlen file_len, ftnlen line_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: rdtext_ 14 5 13 13 12 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int rdtext_(void *cspice_state, char *file, char *line, logical *eof, ftnlen file_len, ftnlen line_len);
extern int cltext_(void *cspice_state, char *file, ftnlen file_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: getlun_ 14 1 4 */
 
extern int readla_(void *cspice_state, integer *unit, integer *maxlin, integer *numlin, char *array, logical *eof, ftnlen array_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: readln_ 14 4 4 13 12 124 */
/*:ref: failed_ 12 0 */
 
extern int readln_(void *cspice_state, integer *unit, char *line, logical *eof, ftnlen line_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int reccyl_(void *cspice_state, doublereal *rectan, doublereal *r__, doublereal *long__, doublereal *z__);
/*:ref: twopi_ 7 0 */
 
extern int recgeo_(void *cspice_state, doublereal *rectan, doublereal *re, doublereal *f, doublereal *long__, doublereal *lat, doublereal *alt);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: nearpt_ 14 6 7 7 7 7 7 7 */
/*:ref: surfnm_ 14 5 7 7 7 7 7 */
/*:ref: reclat_ 14 4 7 7 7 7 */
 
extern int reclat_(void *cspice_state, doublereal *rectan, doublereal *radius, doublereal *long__, doublereal *lat);
 
extern int recpgr_(void *cspice_state, char *body, doublereal *rectan, doublereal *re, doublereal *f, doublereal *lon, doublereal *lat, doublereal *alt, ftnlen body_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: gcpool_ 14 8 13 4 4 4 13 12 124 124 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: plnsns_ 4 1 4 */
/*:ref: recgeo_ 14 6 7 7 7 7 7 7 */
/*:ref: twopi_ 7 0 */
/*:ref: brcktd_ 7 3 7 7 7 */
 
extern int recrad_(void *cspice_state, doublereal *rectan, doublereal *range, doublereal *ra, doublereal *dec);
/*:ref: reclat_ 14 4 7 7 7 7 */
/*:ref: twopi_ 7 0 */
 
extern int recsph_(void *cspice_state, doublereal *rectan, doublereal *r__, doublereal *colat, doublereal *long__);
 
extern int refchg_(void *cspice_state, integer *frame1, integer *frame2, doublereal *et, doublereal *rotate);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ident_ 14 1 7 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: rotget_ 14 5 4 7 7 4 12 */
/*:ref: zzrxr_ 14 3 7 4 7 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: zznofcon_ 14 7 7 4 4 4 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: xpose_ 14 2 7 7 */
 
extern int remlac_(void *cspice_state, integer *ne, integer *loc, char *array, integer *na, ftnlen array_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int remlad_(void *cspice_state, integer *ne, integer *loc, doublereal *array, integer *na);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int remlai_(void *cspice_state, integer *ne, integer *loc, integer *array, integer *na);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int removc_(void *cspice_state, char *item, char *a, ftnlen item_len, ftnlen a_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int removd_(void *cspice_state, doublereal *item, doublereal *a);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: bsrchd_ 4 3 7 4 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int removi_(void *cspice_state, integer *item, integer *a);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: bsrchi_ 4 3 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int remsub_(void *cspice_state, char *in, integer *left, integer *right, char *out, ftnlen in_len, ftnlen out_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
 
extern int reordc_(void *cspice_state, integer *iorder, integer *ndim, char *array, ftnlen array_len);
 
extern int reordd_(void *cspice_state, integer *iorder, integer *ndim, doublereal *array);
 
extern int reordi_(void *cspice_state, integer *iorder, integer *ndim, integer *array);
 
extern int reordl_(void *cspice_state, integer *iorder, integer *ndim, logical *array);
 
extern int replch_(void *cspice_state, char *instr, char *old, char *new__, char *outstr, ftnlen instr_len, ftnlen old_len, ftnlen new_len, ftnlen outstr_len);
 
extern int replwd_(void *cspice_state, char *instr, integer *nth, char *new__, char *outstr, ftnlen instr_len, ftnlen new_len, ftnlen outstr_len);
/*:ref: nthwd_ 14 6 13 4 13 4 124 124 */
/*:ref: fndnwd_ 14 5 13 4 4 4 124 */
/*:ref: frstnb_ 4 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
 
extern int repmc_(void *cspice_state, char *in, char *marker, char *value, char *out, ftnlen in_len, ftnlen marker_len, ftnlen value_len, ftnlen out_len);
/*:ref: frstnb_ 4 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: zzrepsub_ 14 8 13 4 4 13 13 124 124 124 */
 
extern int repmct_(void *cspice_state, char *in, char *marker, integer *value, char *case__, char *out, ftnlen in_len, ftnlen marker_len, ftnlen case_len, ftnlen out_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: frstnb_ 4 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: inttxt_ 14 3 4 13 124 */
/*:ref: lcase_ 14 4 13 13 124 124 */
/*:ref: repsub_ 14 8 13 4 4 13 13 124 124 124 */
 
extern int repmd_(void *cspice_state, char *in, char *marker, doublereal *value, integer *sigdig, char *out, ftnlen in_len, ftnlen marker_len, ftnlen out_len);
/*:ref: frstnb_ 4 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: dpstr_ 14 4 7 4 13 124 */
/*:ref: zzrepsub_ 14 8 13 4 4 13 13 124 124 124 */
 
extern int repmf_(void *cspice_state, char *in, char *marker, doublereal *value, integer *sigdig, char *format, char *out, ftnlen in_len, ftnlen marker_len, ftnlen format_len, ftnlen out_len);
/*:ref: frstnb_ 4 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: dpstrf_ 14 6 7 4 13 13 124 124 */
/*:ref: zzrepsub_ 14 8 13 4 4 13 13 124 124 124 */
 
extern int repmi_(void *cspice_state, char *in, char *marker, integer *value, char *out, ftnlen in_len, ftnlen marker_len, ftnlen out_len);
/*:ref: frstnb_ 4 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: zzrepsub_ 14 8 13 4 4 13 13 124 124 124 */
 
extern int repmot_(void *cspice_state, char *in, char *marker, integer *value, char *case__, char *out, ftnlen in_len, ftnlen marker_len, ftnlen case_len, ftnlen out_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: frstnb_ 4 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: intord_ 14 3 4 13 124 */
/*:ref: lcase_ 14 4 13 13 124 124 */
/*:ref: repsub_ 14 8 13 4 4 13 13 124 124 124 */
 
extern int repsub_(void *cspice_state, char *in, integer *left, integer *right, char *string, char *out, ftnlen in_len, ftnlen string_len, ftnlen out_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sumai_ 4 2 4 4 */
 
extern int reset_(void *cspice_state);
/*:ref: seterr_ 12 1 12 */
/*:ref: putsms_ 14 2 13 124 */
/*:ref: putlms_ 14 2 13 124 */
/*:ref: accept_ 12 1 12 */
 
extern logical return_(void *cspice_state);
/*:ref: failed_ 12 0 */
/*:ref: getact_ 14 1 4 */
 
extern int rjust_(void *cspice_state, char *input, char *output, ftnlen input_len, ftnlen output_len);
/*:ref: frstnb_ 4 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
 
extern int rmaind_(void *cspice_state, doublereal *num, doublereal *denom, doublereal *q, doublereal *rem);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int rmaini_(void *cspice_state, integer *num, integer *denom, integer *q, integer *rem);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int rmdupc_(void *cspice_state, integer *nelt, char *array, ftnlen array_len);
/*:ref: shellc_ 14 3 4 13 124 */
 
extern int rmdupd_(void *cspice_state, integer *nelt, doublereal *array);
/*:ref: shelld_ 14 2 4 7 */
 
extern int rmdupi_(void *cspice_state, integer *nelt, integer *array);
/*:ref: shelli_ 14 2 4 4 */
 
extern int rotate_(void *cspice_state, doublereal *angle, integer *iaxis, doublereal *mout);
 
extern int rotget_(void *cspice_state, integer *infrm, doublereal *et, doublereal *rotate, integer *outfrm, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: irfrot_ 14 3 4 4 7 */
/*:ref: failed_ 12 0 */
/*:ref: tipbod_ 14 5 13 4 7 7 124 */
/*:ref: xpose_ 14 2 7 7 */
/*:ref: ckfrot_ 14 5 4 7 7 4 12 */
/*:ref: tkfram_ 14 4 4 7 4 12 */
/*:ref: zzdynrot_ 14 5 4 4 7 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern int rotmat_(void *cspice_state, doublereal *m1, doublereal *angle, integer *iaxis, doublereal *mout);
/*:ref: moved_ 14 3 7 4 7 */
 
extern int rotvec_(void *cspice_state, doublereal *v1, doublereal *angle, integer *iaxis, doublereal *vout);
 
extern doublereal rpd_(void *cspice_state);
 
extern int rquad_(void *cspice_state, doublereal *a, doublereal *b, doublereal *c__, doublereal *root1, doublereal *root2);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: moved_ 14 3 7 4 7 */
 
extern integer rtrim_(void *cspice_state, char *string, ftnlen string_len);
/*:ref: lastnb_ 4 2 13 124 */
 
extern int saelgv_(void *cspice_state, doublereal *vec1, doublereal *vec2, doublereal *smajor, doublereal *sminor);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: diags2_ 14 3 7 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: vsclip_ 14 2 7 7 */
 
extern logical samch_(void *cspice_state, char *str1, integer *l1, char *str2, integer *l2, ftnlen str1_len, ftnlen str2_len);
 
extern logical samchi_(void *cspice_state, char *str1, integer *l1, char *str2, integer *l2, ftnlen str1_len, ftnlen str2_len);
/*:ref: eqchr_ 12 4 13 13 124 124 */
 
extern logical sameai_(void *cspice_state, integer *a1, integer *a2, integer *ndim);
 
extern logical samsbi_(void *cspice_state, char *str1, integer *b1, integer *e1, char *str2, integer *b2, integer *e2, ftnlen str1_len, ftnlen str2_len);
/*:ref: nechr_ 12 4 13 13 124 124 */
 
extern logical samsub_(void *cspice_state, char *str1, integer *b1, integer *e1, char *str2, integer *b2, integer *e2, ftnlen str1_len, ftnlen str2_len);
 
extern int sc01_(void *cspice_state, integer *sc, char *clkstr, doublereal *ticks, doublereal *sclkdp, doublereal *et, ftnlen clkstr_len);
extern int sctk01_(void *cspice_state, integer *sc, char *clkstr, doublereal *ticks, ftnlen clkstr_len);
extern int scfm01_(void *cspice_state, integer *sc, doublereal *ticks, char *clkstr, ftnlen clkstr_len);
extern int scte01_(void *cspice_state, integer *sc, doublereal *sclkdp, doublereal *et);
extern int scet01_(void *cspice_state, integer *sc, doublereal *et, doublereal *sclkdp);
extern int scec01_(void *cspice_state, integer *sc, doublereal *et, doublereal *sclkdp);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: movec_ 14 5 13 4 13 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: swpool_ 14 5 13 4 13 124 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzcvpool_ 14 4 13 4 12 124 */
/*:ref: scli01_ 14 6 13 4 4 4 4 124 */
/*:ref: scld01_ 14 6 13 4 4 4 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: lparsm_ 14 8 13 13 4 4 13 124 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: nparsd_ 14 6 13 7 13 4 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: dpstrf_ 14 6 7 4 13 13 124 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: unitim_ 7 5 7 13 13 124 124 */
 
extern int scanit_(void *cspice_state, char *string, integer *start, integer *room, integer *nmarks, char *marks, integer *mrklen, integer *pnters, integer *ntokns, integer *ident, integer *beg, integer *end, ftnlen string_len, ftnlen marks_len);
extern int scanpr_(void *cspice_state, integer *nmarks, char *marks, integer *mrklen, integer *pnters, ftnlen marks_len);
extern int scan_(void *cspice_state, char *string, char *marks, integer *mrklen, integer *pnters, integer *room, integer *start, integer *ntokns, integer *ident, integer *beg, integer *end, ftnlen string_len, ftnlen marks_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: rmdupc_ 14 3 4 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: ncpos_ 4 5 13 13 4 124 124 */
 
extern int scanrj_(void *cspice_state, integer *ids, integer *n, integer *ntokns, integer *ident, integer *beg, integer *end);
/*:ref: isrchi_ 4 3 4 4 4 */
 
extern int scardc_(void *cspice_state, integer *card, char *cell, ftnlen cell_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dechar_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: enchar_ 14 3 4 13 124 */
 
extern int scardd_(void *cspice_state, integer *card, doublereal *cell);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int scardi_(void *cspice_state, integer *card, integer *cell);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int scdecd_(void *cspice_state, integer *sc, doublereal *sclkdp, char *sclkch, ftnlen sclkch_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: scpart_ 14 4 4 4 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: lstled_ 4 3 7 4 7 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: scfmt_ 14 4 4 7 13 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
 
extern int sce2c_(void *cspice_state, integer *sc, doublereal *et, doublereal *sclkdp);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sctype_ 4 1 4 */
/*:ref: scec01_ 14 3 4 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sce2s_(void *cspice_state, integer *sc, doublereal *et, char *sclkch, ftnlen sclkch_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sce2t_ 14 3 4 7 7 */
/*:ref: scdecd_ 14 4 4 7 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sce2t_(void *cspice_state, integer *sc, doublereal *et, doublereal *sclkdp);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sctype_ 4 1 4 */
/*:ref: scet01_ 14 3 4 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int scencd_(void *cspice_state, integer *sc, char *sclkch, doublereal *sclkdp, ftnlen sclkch_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cpos_ 4 5 13 13 4 124 124 */
/*:ref: sctiks_ 14 4 4 13 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: scpart_ 14 4 4 4 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: nparsi_ 14 6 13 4 13 4 124 124 */
 
extern int scfmt_(void *cspice_state, integer *sc, doublereal *ticks, char *clkstr, ftnlen clkstr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sctype_ 4 1 4 */
/*:ref: scfm01_ 14 4 4 7 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sclu01_(void *cspice_state, char *name__, integer *sc, integer *maxnv, integer *n, integer *ival, doublereal *dval, ftnlen name_len);
extern int scli01_(void *cspice_state, char *name__, integer *sc, integer *maxnv, integer *n, integer *ival, ftnlen name_len);
extern int scld01_(void *cspice_state, char *name__, integer *sc, integer *maxnv, integer *n, doublereal *dval, ftnlen name_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: gipool_ 14 7 13 4 4 4 4 12 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: gdpool_ 14 7 13 4 4 4 7 12 124 */
/*:ref: repmd_ 14 8 13 13 7 4 13 124 124 124 */
 
extern int scpars_(void *cspice_state, integer *sc, char *sclkch, logical *error, char *msg, doublereal *sclkdp, ftnlen sclkch_len, ftnlen msg_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: cpos_ 4 5 13 13 4 124 124 */
/*:ref: sctype_ 4 1 4 */
/*:ref: failed_ 12 0 */
/*:ref: scps01_ 14 7 4 13 12 13 7 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: scpart_ 14 4 4 4 7 7 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: nparsi_ 14 6 13 4 13 4 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
 
extern int scpart_(void *cspice_state, integer *sc, integer *nparts, doublereal *pstart, doublereal *pstop);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: swpool_ 14 5 13 4 13 124 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzcvpool_ 14 4 13 4 12 124 */
/*:ref: scld01_ 14 6 13 4 4 4 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern int scps01_(void *cspice_state, integer *sc, char *clkstr, logical *error, char *msg, doublereal *ticks, ftnlen clkstr_len, ftnlen msg_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: scli01_ 14 6 13 4 4 4 4 124 */
/*:ref: scld01_ 14 6 13 4 4 4 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lparsm_ 14 8 13 13 4 4 13 124 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: nparsd_ 14 6 13 7 13 4 124 124 */
 
extern int scs2e_(void *cspice_state, integer *sc, char *sclkch, doublereal *et, ftnlen sclkch_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: scencd_ 14 4 4 13 7 124 */
/*:ref: sct2e_ 14 3 4 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sct2e_(void *cspice_state, integer *sc, doublereal *sclkdp, doublereal *et);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sctype_ 4 1 4 */
/*:ref: scte01_ 14 3 4 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sctiks_(void *cspice_state, integer *sc, char *clkstr, doublereal *ticks, ftnlen clkstr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sctype_ 4 1 4 */
/*:ref: sctk01_ 14 4 4 13 7 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sctran_(void *cspice_state, char *clknam, integer *clkid, logical *found, ftnlen clknam_len);
extern int scn2id_(void *cspice_state, char *clknam, integer *clkid, logical *found, ftnlen clknam_len);
extern int scid2n_(void *cspice_state, integer *clkid, char *clknam, logical *found, ftnlen clknam_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: posr_ 4 5 13 13 4 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: bodn2c_ 14 4 13 4 12 124 */
/*:ref: bodc2n_ 14 4 4 13 12 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
 
extern integer sctype_(void *cspice_state, integer *sc);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: swpool_ 14 5 13 4 13 124 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzcvpool_ 14 4 13 4 12 124 */
/*:ref: scli01_ 14 6 13 4 4 4 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sdiffc_(void *cspice_state, char *a, char *b, char *c__, ftnlen a_len, ftnlen b_len, ftnlen c_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: sizec_ 4 2 13 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: excess_ 14 3 4 13 124 */
 
extern int sdiffd_(void *cspice_state, doublereal *a, doublereal *b, doublereal *c__);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: sized_ 4 1 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: excess_ 14 3 4 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sdiffi_(void *cspice_state, integer *a, integer *b, integer *c__);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: sizei_ 4 1 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: excess_ 14 3 4 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sepool_(void *cspice_state, char *item, integer *fidx, char *contin, char *string, integer *size, integer *lidx, logical *found, ftnlen item_len, ftnlen contin_len, ftnlen string_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: gcpool_ 14 8 13 4 4 4 13 12 124 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
 
extern logical setc_(void *cspice_state, char *a, char *op, char *b, ftnlen a_len, ftnlen op_len, ftnlen b_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern logical setd_(void *cspice_state, doublereal *a, char *op, doublereal *b, ftnlen op_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern logical seterr_(void *cspice_state, logical *status);
extern logical failed_(void *cspice_state);
 
extern logical seti_(void *cspice_state, integer *a, char *op, integer *b, ftnlen op_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern int setmsg_(void *cspice_state, char *msg, ftnlen msg_len);
/*:ref: allowd_ 12 0 */
/*:ref: putlms_ 14 2 13 124 */
 
extern int sgfcon_(void *cspice_state, integer *handle, doublereal *descr, integer *first, integer *last, doublereal *values);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sgmeta_ 14 4 4 7 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
 
extern int sgfpkt_(void *cspice_state, integer *handle, doublereal *descr, integer *first, integer *last, doublereal *values, integer *ends);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sgmeta_ 14 4 4 7 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
 
extern int sgfref_(void *cspice_state, integer *handle, doublereal *descr, integer *first, integer *last, doublereal *values);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sgmeta_ 14 4 4 7 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
 
extern int sgfrvi_(void *cspice_state, integer *handle, doublereal *descr, doublereal *x, doublereal *value, integer *indx, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: intmax_ 4 0 */
/*:ref: sgmeta_ 14 4 4 7 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: lstled_ 4 3 7 4 7 */
/*:ref: errdp_ 14 3 13 7 124 */
 
extern int sgmeta_(void *cspice_state, integer *handle, doublereal *descr, integer *mnemon, integer *value);
/*:ref: return_ 12 0 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafhsf_ 14 3 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
 
extern int sgseqw_(void *cspice_state, integer *handle, doublereal *descr, char *segid, integer *nconst, doublereal *const__, integer *npkts, integer *pktsiz, doublereal *pktdat, integer *nrefs, doublereal *refdat, integer *idxtyp, ftnlen segid_len);
extern int sgbwfs_(void *cspice_state, integer *handle, doublereal *descr, char *segid, integer *nconst, doublereal *const__, integer *pktsiz, integer *idxtyp, ftnlen segid_len);
extern int sgbwvs_(void *cspice_state, integer *handle, doublereal *descr, char *segid, integer *nconst, doublereal *const__, integer *idxtyp, ftnlen segid_len);
extern int sgwfpk_(void *cspice_state, integer *handle, integer *npkts, doublereal *pktdat, integer *nrefs, doublereal *refdat);
extern int sgwvpk_(void *cspice_state, integer *handle, integer *npkts, integer *pktsiz, doublereal *pktdat, integer *nrefs, doublereal *refdat);
extern int sgwes_(void *cspice_state, integer *handle);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafsih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: dafhsf_ 14 3 4 4 4 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: dafrfr_ 14 8 4 4 4 13 4 4 4 124 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafcad_ 14 1 4 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: dafena_ 14 0 */
 
extern int sharpr_(void *cspice_state, doublereal *rot);
/*:ref: vhatip_ 14 1 7 */
/*:ref: ucrss_ 14 3 7 7 7 */
 
extern int shellc_(void *cspice_state, integer *ndim, char *array, ftnlen array_len);
/*:ref: swapc_ 14 4 13 13 124 124 */
 
extern int shelld_(void *cspice_state, integer *ndim, doublereal *array);
/*:ref: swapd_ 14 2 7 7 */
 
extern int shelli_(void *cspice_state, integer *ndim, integer *array);
/*:ref: swapi_ 14 2 4 4 */
 
extern int shiftc_(void *cspice_state, char *in, char *dir, integer *nshift, char *fillc, char *out, ftnlen in_len, ftnlen dir_len, ftnlen fillc_len, ftnlen out_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: shiftl_ 14 7 13 4 13 13 124 124 124 */
/*:ref: shiftr_ 14 7 13 4 13 13 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int shiftl_(void *cspice_state, char *in, integer *nshift, char *fillc, char *out, ftnlen in_len, ftnlen fillc_len, ftnlen out_len);
 
extern int shiftr_(void *cspice_state, char *in, integer *nshift, char *fillc, char *out, ftnlen in_len, ftnlen fillc_len, ftnlen out_len);
 
extern int sigdgt_(void *cspice_state, char *in, char *out, ftnlen in_len, ftnlen out_len);
/*:ref: frstnb_ 4 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: cpos_ 4 5 13 13 4 124 124 */
 
extern int sigerr_(void *cspice_state, char *msg, ftnlen msg_len);
/*:ref: getact_ 14 1 4 */
/*:ref: failed_ 12 0 */
/*:ref: seterr_ 12 1 12 */
/*:ref: putsms_ 14 2 13 124 */
/*:ref: freeze_ 14 0 */
/*:ref: outmsg_ 14 2 13 124 */
/*:ref: accept_ 12 1 12 */
/*:ref: byebye_ 14 2 13 124 */
 
extern int sincpt_(void *cspice_state, char *method, char *target, doublereal *et, char *fixref, char *abcorr, char *obsrvr, char *dref, doublereal *dvec, doublereal *spoint, doublereal *trgepc, doublereal *srfvec, logical *found, ftnlen method_len, ftnlen target_len, ftnlen fixref_len, ftnlen abcorr_len, ftnlen obsrvr_len, ftnlen dref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: vzero_ 12 1 7 */
/*:ref: zzsrftrk_ 14 2 4 12 */
/*:ref: zzprsmet_ 14 15 4 13 4 13 13 12 4 4 13 13 124 124 124 124 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: zzsuelin_ 14 1 4 */
/*:ref: zzsudski_ 14 4 4 4 4 4 */
/*:ref: zzsfxcor_ 14 22 200 200 200 4 7 13 12 12 12 12 13 4 4 4 4 7 7 7 7 12 124 124 */
 
extern integer sizec_(void *cspice_state, char *cell, ftnlen cell_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dechar_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern integer sized_(void *cspice_state, doublereal *cell);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern integer sizei_(void *cspice_state, integer *cell);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern logical smsgnd_(void *cspice_state, doublereal *x, doublereal *y);
 
extern logical smsgni_(void *cspice_state, integer *x, integer *y);
 
extern logical somfls_(void *cspice_state, logical *logcls, integer *n);
 
extern logical somtru_(void *cspice_state, logical *logcls, integer *n);
 
extern int spca2b_(void *cspice_state, char *text, char *binary, ftnlen text_len, ftnlen binary_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: txtopr_ 14 3 13 4 124 */
/*:ref: spct2b_ 14 3 4 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spcac_(void *cspice_state, integer *handle, integer *unit, char *bmark, char *emark, ftnlen bmark_len, ftnlen emark_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafsih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: locln_ 14 10 4 13 13 13 4 4 12 124 124 124 */
/*:ref: countc_ 4 5 4 4 4 13 124 */
/*:ref: dafrfr_ 14 8 4 4 4 13 4 4 4 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: dafarr_ 14 2 4 4 */
/*:ref: lastnb_ 4 2 13 124 */
 
extern int spcb2a_(void *cspice_state, char *binary, char *text, ftnlen binary_len, ftnlen text_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: txtopn_ 14 3 13 4 124 */
/*:ref: spcb2t_ 14 3 13 4 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spcb2t_(void *cspice_state, char *binary, integer *unit, ftnlen binary_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafb2t_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafopr_ 14 3 13 4 124 */
/*:ref: spcec_ 14 2 4 4 */
/*:ref: dafcls_ 14 1 4 */
 
extern int spcdc_(void *cspice_state, integer *handle);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafrfr_ 14 8 4 4 4 13 4 4 4 124 */
/*:ref: dafrrr_ 14 2 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spcec_(void *cspice_state, integer *handle, integer *unit);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafsih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafrfr_ 14 8 4 4 4 13 4 4 4 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern int spcopn_(void *cspice_state, char *spc, char *ifname, integer *handle, ftnlen spc_len, ftnlen ifname_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafopn_ 14 8 13 4 4 13 4 4 124 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spcrfl_(void *cspice_state, integer *handle, char *line, logical *eoc, ftnlen line_len);
extern int spcrnl_(void *cspice_state, char *line, logical *eoc, ftnlen line_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafrfr_ 14 8 4 4 4 13 4 4 4 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: pos_ 4 5 13 13 4 124 124 */
 
extern int spct2b_(void *cspice_state, integer *unit, char *binary, ftnlen binary_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: daft2b_ 14 4 4 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ltrim_ 4 2 13 124 */
/*:ref: getlun_ 14 1 4 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: dafopw_ 14 3 13 4 124 */
/*:ref: spcac_ 14 6 4 4 13 13 124 124 */
/*:ref: dafcls_ 14 1 4 */
 
extern doublereal spd_(void *cspice_state);
 
extern int sphcyl_(void *cspice_state, doublereal *radius, doublereal *colat, doublereal *slong, doublereal *r__, doublereal *long__, doublereal *z__);
 
extern int sphlat_(void *cspice_state, doublereal *r__, doublereal *colat, doublereal *longs, doublereal *radius, doublereal *long__, doublereal *lat);
/*:ref: halfpi_ 7 0 */
 
extern int sphrec_(void *cspice_state, doublereal *r__, doublereal *colat, doublereal *long__, doublereal *rectan);
 
extern doublereal sphsd_(void *cspice_state, doublereal *radius, doublereal *long1, doublereal *lat1, doublereal *long2, doublereal *lat2);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: brcktd_ 7 3 7 7 7 */
 
extern int spk14a_(void *cspice_state, integer *handle, integer *ncsets, doublereal *coeffs, doublereal *epochs);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sgwfpk_ 14 5 4 4 7 4 7 */
 
extern int spk14b_(void *cspice_state, integer *handle, char *segid, integer *body, integer *center, char *frame, doublereal *first, doublereal *last, integer *chbdeg, ftnlen segid_len, ftnlen frame_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: spkpds_ 14 8 4 4 13 4 7 7 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: sgbwfs_ 14 8 4 7 13 4 7 4 4 124 */
 
extern int spk14e_(void *cspice_state, integer *handle);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sgwes_ 14 1 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spkacs_(void *cspice_state, integer *targ, doublereal *et, char *ref, char *abcorr, integer *obs, doublereal *starg, doublereal *lt, doublereal *dlt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzprscor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: spkgeo_ 14 7 4 7 13 4 7 7 124 */
/*:ref: qderiv_ 14 5 4 7 7 7 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: spkaps_ 14 11 4 7 13 13 7 7 7 7 7 124 124 */
 
extern int spkapo_(void *cspice_state, integer *targ, doublereal *et, char *ref, doublereal *sobs, char *abcorr, doublereal *ptarg, doublereal *lt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: odd_ 12 1 4 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: spkgps_ 14 7 4 7 13 4 7 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
/*:ref: stlabx_ 14 3 7 7 7 */
/*:ref: stelab_ 14 3 7 7 7 */
 
extern int spkapp_(void *cspice_state, integer *targ, doublereal *et, char *ref, doublereal *sobs, char *abcorr, doublereal *starg, doublereal *lt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: odd_ 12 1 4 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: spkssb_ 14 5 4 7 13 7 124 */
/*:ref: vsubg_ 14 4 7 7 4 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
/*:ref: stlabx_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: stelab_ 14 3 7 7 7 */
 
extern int spkaps_(void *cspice_state, integer *targ, doublereal *et, char *ref, char *abcorr, doublereal *stobs, doublereal *accobs, doublereal *starg, doublereal *lt, doublereal *dlt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzprscor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: spkltc_ 14 10 4 7 13 13 7 7 7 7 124 124 */
/*:ref: zzstelab_ 14 6 12 7 7 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
 
extern int spkbsr_(void *cspice_state, char *fname, integer *handle, integer *body, doublereal *et, doublereal *descr, char *ident, logical *found, ftnlen fname_len, ftnlen ident_len);
extern int spklef_(void *cspice_state, char *fname, integer *handle, ftnlen fname_len);
extern int spkuef_(void *cspice_state, integer *handle);
extern int spksfs_(void *cspice_state, integer *body, doublereal *et, integer *handle, doublereal *descr, char *ident, logical *found, ftnlen ident_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lnkini_ 14 2 4 4 */
/*:ref: dafopr_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: dafcls_ 14 1 4 */
/*:ref: lnknxt_ 4 2 4 4 */
/*:ref: lnkfsl_ 14 3 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: intmax_ 4 0 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: lnkprv_ 4 2 4 4 */
/*:ref: dpmin_ 7 0 */
/*:ref: dpmax_ 7 0 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: dafbfs_ 14 1 4 */
/*:ref: daffna_ 14 1 12 */
/*:ref: dafgs_ 14 1 7 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: dafbbs_ 14 1 4 */
/*:ref: daffpa_ 14 1 12 */
/*:ref: lnknfn_ 4 1 4 */
/*:ref: lnkan_ 14 2 4 4 */
/*:ref: dafgn_ 14 2 13 124 */
/*:ref: lnkilb_ 14 3 4 4 4 */
/*:ref: lnkila_ 14 3 4 4 4 */
/*:ref: lnktl_ 4 2 4 4 */
 
extern int spkcls_(void *cspice_state, integer *handle);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafbfs_ 14 1 4 */
/*:ref: daffna_ 14 1 12 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: dafcls_ 14 1 4 */
 
extern int spkcov_(void *cspice_state, char *spk, integer *idcode, doublereal *cover, ftnlen spk_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: getfat_ 14 6 13 13 13 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafopr_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafbfs_ 14 1 4 */
/*:ref: daffna_ 14 1 12 */
/*:ref: dafgs_ 14 1 7 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: wninsd_ 14 3 7 7 7 */
/*:ref: dafcls_ 14 1 4 */
 
extern int spkcpo_(void *cspice_state, char *target, doublereal *et, char *outref, char *refloc, char *abcorr, doublereal *obspos, char *obsctr, char *obsref, doublereal *state, doublereal *lt, ftnlen target_len, ftnlen outref_len, ftnlen refloc_len, ftnlen abcorr_len, ftnlen obsctr_len, ftnlen obsref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: spkcvo_ 14 17 13 7 13 13 13 7 7 13 13 7 7 124 124 124 124 124 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spkcpt_(void *cspice_state, doublereal *trgpos, char *trgctr, char *trgref, doublereal *et, char *outref, char *refloc, char *abcorr, char *obsrvr, doublereal *state, doublereal *lt, ftnlen trgctr_len, ftnlen trgref_len, ftnlen outref_len, ftnlen refloc_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: spkcvt_ 14 17 7 7 13 13 7 13 13 13 13 7 7 124 124 124 124 124 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spkcvo_(void *cspice_state, char *target, doublereal *et, char *outref, char *refloc, char *abcorr, doublereal *obssta, doublereal *obsepc, char *obsctr, char *obsref, doublereal *state, doublereal *lt, ftnlen target_len, ftnlen outref_len, ftnlen refloc_len, ftnlen abcorr_len, ftnlen obsctr_len, ftnlen obsref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: esrchc_ 4 5 13 4 13 124 124 */
/*:ref: zzcvssta_ 14 5 7 4 7 13 124 */
/*:ref: zzspkfzo_ 14 9 4 7 13 13 200 7 7 124 124 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: frmchg_ 14 4 4 4 7 7 */
/*:ref: mxvg_ 14 5 7 7 4 4 7 */
/*:ref: zzspkfao_ 14 10 4 7 13 13 200 7 7 7 124 124 */
/*:ref: zzcorsxf_ 14 4 12 7 7 7 */
 
extern int spkcvt_(void *cspice_state, doublereal *trgsta, doublereal *trgepc, char *trgctr, char *trgref, doublereal *et, char *outref, char *refloc, char *abcorr, char *obsrvr, doublereal *state, doublereal *lt, ftnlen trgctr_len, ftnlen trgref_len, ftnlen outref_len, ftnlen refloc_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: esrchc_ 4 5 13 4 13 124 124 */
/*:ref: zzcvssta_ 14 5 7 4 7 13 124 */
/*:ref: zzspkfzt_ 14 9 200 7 13 13 4 7 7 124 124 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: frmchg_ 14 4 4 4 7 7 */
/*:ref: mxvg_ 14 5 7 7 4 4 7 */
/*:ref: zzspkfat_ 14 10 200 7 13 13 4 7 7 7 124 124 */
/*:ref: zzcorsxf_ 14 4 12 7 7 7 */
 
extern int spke01_(void *cspice_state, doublereal *et, doublereal *record, doublereal *state);
/*:ref: return_ 12 0 */
/*:ref: moved_ 14 3 7 4 7 */
 
extern int spke02_(void *cspice_state, doublereal *et, doublereal *record, doublereal *xyzdot);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: chbint_ 14 6 7 4 7 7 7 7 */
 
extern int spke03_(void *cspice_state, doublereal *et, doublereal *record, doublereal *state);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: chbval_ 14 5 7 4 7 7 7 */
 
extern int spke05_(void *cspice_state, doublereal *et, doublereal *record, doublereal *state);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: prop2b_ 14 4 7 7 7 7 */
/*:ref: pi_ 7 0 */
/*:ref: vlcomg_ 14 6 4 7 7 7 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spke08_(void *cspice_state, doublereal *et, doublereal *record, doublereal *state);
/*:ref: return_ 12 0 */
/*:ref: xposeg_ 14 4 7 4 4 7 */
/*:ref: lgresp_ 7 6 4 7 7 7 7 7 */
 
extern int spke09_(void *cspice_state, doublereal *et, doublereal *record, doublereal *state);
/*:ref: return_ 12 0 */
/*:ref: xposeg_ 14 4 7 4 4 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: lgrint_ 7 5 4 7 7 7 7 */
 
extern int spke10_(void *cspice_state, doublereal *et, doublereal *record, doublereal *state);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: pi_ 7 0 */
/*:ref: twopi_ 7 0 */
/*:ref: xxsgp4i_ 14 3 7 7 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: xxsgp4e_ 14 2 7 7 */
/*:ref: vlcomg_ 14 6 4 7 7 7 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: zzteme_ 14 2 7 7 */
/*:ref: invstm_ 14 2 7 7 */
/*:ref: mxvg_ 14 5 7 7 4 4 7 */
/*:ref: moved_ 14 3 7 4 7 */
 
extern int spke12_(void *cspice_state, doublereal *et, doublereal *record, doublereal *state);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: hrmesp_ 14 8 4 7 7 7 7 7 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spke13_(void *cspice_state, doublereal *et, doublereal *record, doublereal *state);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: hrmint_ 14 7 4 7 7 7 7 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spke14_(void *cspice_state, doublereal *et, doublereal *record, doublereal *state);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chbval_ 14 5 7 4 7 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spke15_(void *cspice_state, doublereal *et, doublereal *recin, doublereal *state);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vzero_ 12 1 7 */
/*:ref: vhatip_ 14 1 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: dpr_ 7 0 */
/*:ref: vscl_ 14 3 7 7 7 */
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: vsclip_ 14 2 7 7 */
/*:ref: prop2b_ 14 4 7 7 7 7 */
/*:ref: twopi_ 7 0 */
/*:ref: pi_ 7 0 */
/*:ref: vrotv_ 14 4 7 7 7 7 */
/*:ref: moved_ 14 3 7 4 7 */
 
extern int spke17_(void *cspice_state, doublereal *et, doublereal *recin, doublereal *state);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: eqncpv_ 14 6 7 7 7 7 7 7 */
 
extern int spke18_(void *cspice_state, doublereal *et, doublereal *record, doublereal *state);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: xpsgip_ 14 3 4 4 7 */
/*:ref: lgrint_ 7 5 4 7 7 7 7 */
/*:ref: hrmint_ 14 7 4 7 7 7 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
 
extern int spke19_(void *cspice_state, doublereal *et, doublereal *record, doublereal *state);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: hrmint_ 14 7 4 7 7 7 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: xpsgip_ 14 3 4 4 7 */
/*:ref: lgrint_ 7 5 4 7 7 7 7 */
 
extern int spke20_(void *cspice_state, doublereal *et, doublereal *record, doublereal *xyzdot);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: chbigr_ 14 6 4 7 7 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
 
extern int spke21_(void *cspice_state, doublereal *et, doublereal *record, doublereal *state);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: moved_ 14 3 7 4 7 */
 
extern int spkez_(void *cspice_state, integer *targ, doublereal *et, char *ref, char *abcorr, integer *obs, doublereal *starg, doublereal *lt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: spkgeo_ 14 7 4 7 13 4 7 7 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: spkacs_ 14 10 4 7 13 13 4 7 7 7 124 124 */
/*:ref: spkssb_ 14 5 4 7 13 7 124 */
/*:ref: spkltc_ 14 10 4 7 13 13 7 7 7 7 124 124 */
/*:ref: frmchg_ 14 4 4 4 7 7 */
/*:ref: vsclip_ 14 2 7 7 */
/*:ref: mxvg_ 14 5 7 7 4 4 7 */
 
extern int spkezp_(void *cspice_state, integer *targ, doublereal *et, char *ref, char *abcorr, integer *obs, doublereal *ptarg, doublereal *lt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: ltrim_ 4 2 13 124 */
/*:ref: eqchr_ 12 4 13 13 124 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: spkgps_ 14 7 4 7 13 4 7 7 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: failed_ 12 0 */
/*:ref: spkssb_ 14 5 4 7 13 7 124 */
/*:ref: spkapo_ 14 9 4 7 13 7 13 7 7 124 124 */
/*:ref: refchg_ 14 4 4 4 7 7 */
/*:ref: mxv_ 14 3 7 7 7 */
 
extern int spkezr_(void *cspice_state, char *targ, doublereal *et, char *ref, char *abcorr, char *obs, doublereal *starg, doublereal *lt, ftnlen targ_len, ftnlen ref_len, ftnlen abcorr_len, ftnlen obs_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: spkez_ 14 9 4 7 13 13 4 7 7 124 124 */
 
extern int spkgeo_(void *cspice_state, integer *targ, doublereal *et, char *ref, integer *obs, doublereal *state, doublereal *lt, ftnlen ref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: frstnp_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: spksfs_ 14 7 4 7 4 7 13 12 124 */
/*:ref: spkpvn_ 14 6 4 7 7 4 7 4 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: irfrot_ 14 3 4 4 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: frmchg_ 14 4 4 4 7 7 */
/*:ref: mxvg_ 14 5 7 7 4 4 7 */
/*:ref: vaddg_ 14 4 7 7 4 7 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: bodc2n_ 14 4 4 13 12 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: vsubg_ 14 4 7 7 4 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
 
extern int spkgps_(void *cspice_state, integer *targ, doublereal *et, char *ref, integer *obs, doublereal *pos, doublereal *lt, ftnlen ref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: frstnp_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: spksfs_ 14 7 4 7 4 7 13 12 124 */
/*:ref: spkpvn_ 14 6 4 7 7 4 7 4 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: irfrot_ 14 3 4 4 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: refchg_ 14 4 4 4 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: bodc2n_ 14 4 4 13 12 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
 
extern int spkltc_(void *cspice_state, integer *targ, doublereal *et, char *ref, char *abcorr, doublereal *stobs, doublereal *starg, doublereal *lt, doublereal *dlt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: spkgeo_ 14 7 4 7 13 4 7 7 124 */
/*:ref: vsubg_ 14 4 7 7 4 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: touchd_ 7 1 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
 
extern int spkobj_(void *cspice_state, char *spk, integer *ids, ftnlen spk_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: getfat_ 14 6 13 13 13 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafopr_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafbfs_ 14 1 4 */
/*:ref: daffna_ 14 1 12 */
/*:ref: dafgs_ 14 1 7 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: insrti_ 14 2 4 4 */
/*:ref: dafcls_ 14 1 4 */
 
extern int spkopa_(void *cspice_state, char *file, integer *handle, ftnlen file_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: exists_ 12 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: getfat_ 14 6 13 13 13 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafopw_ 14 3 13 4 124 */
 
extern int spkopn_(void *cspice_state, char *name__, char *ifname, integer *ncomch, integer *handle, ftnlen name_len, ftnlen ifname_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafonw_ 14 10 13 13 4 4 13 4 4 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spkpds_(void *cspice_state, integer *body, integer *center, char *frame, integer *type__, doublereal *first, doublereal *last, doublereal *descr, ftnlen frame_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
 
extern int spkpos_(void *cspice_state, char *targ, doublereal *et, char *ref, char *abcorr, char *obs, doublereal *ptarg, doublereal *lt, ftnlen targ_len, ftnlen ref_len, ftnlen abcorr_len, ftnlen obs_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: spkezp_ 14 9 4 7 13 13 4 7 7 124 124 */
 
extern int spkpv_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, char *ref, doublereal *state, integer *center, ftnlen ref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: spkpvn_ 14 6 4 7 7 4 7 4 */
/*:ref: frmchg_ 14 4 4 4 7 7 */
/*:ref: mxvg_ 14 5 7 7 4 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spkpvn_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, integer *ref, doublereal *state, integer *center);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: spkr01_ 14 4 4 7 7 7 */
/*:ref: spke01_ 14 3 7 7 7 */
/*:ref: spkr02_ 14 4 4 7 7 7 */
/*:ref: spke02_ 14 3 7 7 7 */
/*:ref: spkr03_ 14 4 4 7 7 7 */
/*:ref: spke03_ 14 3 7 7 7 */
/*:ref: spkr05_ 14 4 4 7 7 7 */
/*:ref: spke05_ 14 3 7 7 7 */
/*:ref: spkr08_ 14 4 4 7 7 7 */
/*:ref: spke08_ 14 3 7 7 7 */
/*:ref: spkr09_ 14 4 4 7 7 7 */
/*:ref: spke09_ 14 3 7 7 7 */
/*:ref: spkr10_ 14 4 4 7 7 7 */
/*:ref: spke10_ 14 3 7 7 7 */
/*:ref: spkr12_ 14 4 4 7 7 7 */
/*:ref: spke12_ 14 3 7 7 7 */
/*:ref: spkr13_ 14 4 4 7 7 7 */
/*:ref: spke13_ 14 3 7 7 7 */
/*:ref: sgfcon_ 14 5 4 7 4 4 7 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: spkr14_ 14 4 4 7 7 7 */
/*:ref: spke14_ 14 3 7 7 7 */
/*:ref: spkr15_ 14 4 4 7 7 7 */
/*:ref: spke15_ 14 3 7 7 7 */
/*:ref: spkr17_ 14 4 4 7 7 7 */
/*:ref: spke17_ 14 3 7 7 7 */
/*:ref: spkr18_ 14 4 4 7 7 7 */
/*:ref: spke18_ 14 3 7 7 7 */
/*:ref: spkr19_ 14 4 4 7 7 7 */
/*:ref: spke19_ 14 3 7 7 7 */
/*:ref: spkr20_ 14 4 4 7 7 7 */
/*:ref: spke20_ 14 3 7 7 7 */
/*:ref: spkr21_ 14 4 4 7 7 7 */
/*:ref: spke21_ 14 3 7 7 7 */
 
extern int spkr01_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: lstltd_ 4 3 7 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spkr02_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spkr03_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spkr05_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: lstltd_ 4 3 7 4 7 */
/*:ref: moved_ 14 3 7 4 7 */
 
extern int spkr08_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: odd_ 12 1 4 */
 
extern int spkr09_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: lstltd_ 4 3 7 4 7 */
/*:ref: odd_ 12 1 4 */
 
extern int spkr10_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sgfcon_ 14 5 4 7 4 4 7 */
/*:ref: sgfrvi_ 14 6 4 7 7 7 4 12 */
/*:ref: sgmeta_ 14 4 4 7 4 4 */
/*:ref: sgfpkt_ 14 6 4 7 4 4 7 4 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spkr12_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: spkr08_ 14 4 4 7 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spkr13_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: spkr09_ 14 4 4 7 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spkr14_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sgfcon_ 14 5 4 7 4 4 7 */
/*:ref: sgfrvi_ 14 6 4 7 7 7 4 12 */
/*:ref: sgfpkt_ 14 6 4 7 4 4 7 4 */
 
extern int spkr15_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
 
extern int spkr17_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
 
extern int spkr18_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: failed_ 12 0 */
/*:ref: odd_ 12 1 4 */
/*:ref: lstltd_ 4 3 7 4 7 */
 
extern int spkr19_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: failed_ 12 0 */
/*:ref: lstled_ 4 3 7 4 7 */
/*:ref: lstltd_ 4 3 7 4 7 */
/*:ref: odd_ 12 1 4 */
 
extern int spkr20_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: j2000_ 7 0 */
/*:ref: spd_ 7 0 */
/*:ref: remlad_ 14 4 4 4 7 4 */
/*:ref: vsclip_ 14 2 7 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spkr21_(void *cspice_state, integer *handle, doublereal *descr, doublereal *et, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lstltd_ 4 3 7 4 7 */
 
extern int spks01_(void *cspice_state, integer *handle, integer *baddr, integer *eaddr, doublereal *begin, doublereal *end);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spks02_(void *cspice_state, integer *handle, integer *baddr, integer *eaddr, doublereal *begin, doublereal *end);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spks03_(void *cspice_state, integer *handle, integer *baddr, integer *eaddr, doublereal *begin, doublereal *end);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spks05_(void *cspice_state, integer *handle, integer *baddr, integer *eaddr, doublereal *begin, doublereal *end);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spks08_(void *cspice_state, integer *handle, integer *baddr, integer *eaddr, doublereal *begin, doublereal *end);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafada_ 14 2 7 4 */
 
extern int spks09_(void *cspice_state, integer *handle, integer *baddr, integer *eaddr, doublereal *begin, doublereal *end);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: dafada_ 14 2 7 4 */
 
extern int spks10_(void *cspice_state, integer *srchan, doublereal *srcdsc, integer *dsthan, doublereal *dstdsc, char *dstsid, ftnlen dstsid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: sgfcon_ 14 5 4 7 4 4 7 */
/*:ref: sgbwfs_ 14 8 4 7 13 4 7 4 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sgfrvi_ 14 6 4 7 7 7 4 12 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: sgmeta_ 14 4 4 7 4 4 */
/*:ref: sgfpkt_ 14 6 4 7 4 4 7 4 */
/*:ref: sgfref_ 14 5 4 7 4 4 7 */
/*:ref: sgwfpk_ 14 5 4 4 7 4 7 */
/*:ref: sgwes_ 14 1 4 */
 
extern int spks12_(void *cspice_state, integer *handle, integer *baddr, integer *eaddr, doublereal *begin, doublereal *end);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: spks08_ 14 5 4 4 4 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spks13_(void *cspice_state, integer *handle, integer *baddr, integer *eaddr, doublereal *begin, doublereal *end);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: spks09_ 14 5 4 4 4 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spks14_(void *cspice_state, integer *srchan, doublereal *srcdsc, integer *dsthan, doublereal *dstdsc, char *dstsid, ftnlen dstsid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: irfnam_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sgfcon_ 14 5 4 7 4 4 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: sgfrvi_ 14 6 4 7 7 7 4 12 */
/*:ref: spk14b_ 14 10 4 13 4 4 13 7 7 4 124 124 */
/*:ref: sgfpkt_ 14 6 4 7 4 4 7 4 */
/*:ref: sgfref_ 14 5 4 7 4 4 7 */
/*:ref: spk14a_ 14 4 4 4 7 7 */
/*:ref: spk14e_ 14 1 4 */
 
extern int spks15_(void *cspice_state, integer *handle, integer *baddr, integer *eaddr, doublereal *begin, doublereal *end);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: dafada_ 14 2 7 4 */
 
extern int spks17_(void *cspice_state, integer *handle, integer *baddr, integer *eaddr, doublereal *begin, doublereal *end);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: dafada_ 14 2 7 4 */
 
extern int spks18_(void *cspice_state, integer *handle, integer *baddr, integer *eaddr, doublereal *begin, doublereal *end);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: dafada_ 14 2 7 4 */
 
extern int spks19_(void *cspice_state, integer *handle, integer *baddr, integer *eaddr, doublereal *begin, doublereal *end);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: failed_ 12 0 */
/*:ref: lstltd_ 4 3 7 4 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: lstled_ 4 3 7 4 7 */
/*:ref: dafhfn_ 14 3 4 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: dafada_ 14 2 7 4 */
 
extern int spks20_(void *cspice_state, integer *handle, integer *baddr, integer *eaddr, doublereal *begin, doublereal *end);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: j2000_ 7 0 */
/*:ref: spd_ 7 0 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spks21_(void *cspice_state, integer *handle, integer *baddr, integer *eaddr, doublereal *begin, doublereal *end);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spkssb_(void *cspice_state, integer *targ, doublereal *et, char *ref, doublereal *starg, ftnlen ref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: spkgeo_ 14 7 4 7 13 4 7 7 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spksub_(void *cspice_state, integer *handle, doublereal *descr, char *ident, doublereal *begin, doublereal *end, integer *newh, ftnlen ident_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: spks01_ 14 5 4 4 4 7 7 */
/*:ref: dafena_ 14 0 */
/*:ref: spks02_ 14 5 4 4 4 7 7 */
/*:ref: spks03_ 14 5 4 4 4 7 7 */
/*:ref: spks05_ 14 5 4 4 4 7 7 */
/*:ref: spks08_ 14 5 4 4 4 7 7 */
/*:ref: spks09_ 14 5 4 4 4 7 7 */
/*:ref: spks10_ 14 6 4 7 4 7 13 124 */
/*:ref: spks12_ 14 5 4 4 4 7 7 */
/*:ref: spks13_ 14 5 4 4 4 7 7 */
/*:ref: spks14_ 14 6 4 7 4 7 13 124 */
/*:ref: spks15_ 14 5 4 4 4 7 7 */
/*:ref: spks17_ 14 5 4 4 4 7 7 */
/*:ref: spks18_ 14 5 4 4 4 7 7 */
/*:ref: spks19_ 14 5 4 4 4 7 7 */
/*:ref: spks20_ 14 5 4 4 4 7 7 */
/*:ref: spks21_ 14 5 4 4 4 7 7 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern int spkuds_(void *cspice_state, doublereal *descr, integer *body, integer *center, integer *frame, integer *type__, doublereal *first, doublereal *last, integer *begin, integer *end);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int spkw01_(void *cspice_state, integer *handle, integer *body, integer *center, char *frame, doublereal *first, doublereal *last, char *segid, integer *n, doublereal *dlines, doublereal *epochs, ftnlen frame_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: spkpds_ 14 8 4 4 13 4 7 7 7 124 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern int spkw02_(void *cspice_state, integer *handle, integer *body, integer *center, char *frame, doublereal *first, doublereal *last, char *segid, doublereal *intlen, integer *n, integer *polydg, doublereal *cdata, doublereal *btime, ftnlen frame_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: chckid_ 14 5 13 4 13 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern int spkw03_(void *cspice_state, integer *handle, integer *body, integer *center, char *frame, doublereal *first, doublereal *last, char *segid, doublereal *intlen, integer *n, integer *polydg, doublereal *cdata, doublereal *btime, ftnlen frame_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: chckid_ 14 5 13 4 13 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern int spkw05_(void *cspice_state, integer *handle, integer *body, integer *center, char *frame, doublereal *first, doublereal *last, char *segid, doublereal *gm, integer *n, doublereal *states, doublereal *epochs, ftnlen frame_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern int spkw08_(void *cspice_state, integer *handle, integer *body, integer *center, char *frame, doublereal *first, doublereal *last, char *segid, integer *degree, integer *n, doublereal *states, doublereal *epoch1, doublereal *step, ftnlen frame_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern int spkw09_(void *cspice_state, integer *handle, integer *body, integer *center, char *frame, doublereal *first, doublereal *last, char *segid, integer *degree, integer *n, doublereal *states, doublereal *epochs, ftnlen frame_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern int spkw10_(void *cspice_state, integer *handle, integer *body, integer *center, char *frame, doublereal *first, doublereal *last, char *segid, doublereal *consts, integer *n, doublereal *elems, doublereal *epochs, ftnlen frame_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: spkpds_ 14 8 4 4 13 4 7 7 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sgbwfs_ 14 8 4 7 13 4 7 4 4 124 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: zzwahr_ 14 2 7 7 */
/*:ref: sgwfpk_ 14 5 4 4 7 4 7 */
/*:ref: sgwes_ 14 1 4 */
 
extern int spkw12_(void *cspice_state, integer *handle, integer *body, integer *center, char *frame, doublereal *first, doublereal *last, char *segid, integer *degree, integer *n, doublereal *states, doublereal *epoch1, doublereal *step, ftnlen frame_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: even_ 12 1 4 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: spkpds_ 14 8 4 4 13 4 7 7 7 124 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern int spkw13_(void *cspice_state, integer *handle, integer *body, integer *center, char *frame, doublereal *first, doublereal *last, char *segid, integer *degree, integer *n, doublereal *states, doublereal *epochs, ftnlen frame_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: even_ 12 1 4 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: spkpds_ 14 8 4 4 13 4 7 7 7 124 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern int spkw15_(void *cspice_state, integer *handle, integer *body, integer *center, char *frame, doublereal *first, doublereal *last, char *segid, doublereal *epoch, doublereal *tp, doublereal *pa, doublereal *p, doublereal *ecc, doublereal *j2flg, doublereal *pv, doublereal *gm, doublereal *j2, doublereal *radius, ftnlen frame_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vzero_ 12 1 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: dpr_ 7 0 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: spkpds_ 14 8 4 4 13 4 7 7 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern int spkw17_(void *cspice_state, integer *handle, integer *body, integer *center, char *frame, doublereal *first, doublereal *last, char *segid, doublereal *epoch, doublereal *eqel, doublereal *rapol, doublereal *decpol, ftnlen frame_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: spkpds_ 14 8 4 4 13 4 7 7 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern int spkw18_(void *cspice_state, integer *handle, integer *subtyp, integer *body, integer *center, char *frame, doublereal *first, doublereal *last, char *segid, integer *degree, integer *n, doublereal *packts, doublereal *epochs, ftnlen frame_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: odd_ 12 1 4 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern int spkw19_(void *cspice_state, integer *handle, integer *body, integer *center, char *frame, doublereal *first, doublereal *last, char *segid, integer *nintvl, integer *npkts, integer *subtps, integer *degres, doublereal *packts, doublereal *epochs, doublereal *ivlbds, logical *sellst, ftnlen frame_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: odd_ 12 1 4 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern int spkw20_(void *cspice_state, integer *handle, integer *body, integer *center, char *frame, doublereal *first, doublereal *last, char *segid, doublereal *intlen, integer *n, integer *polydg, doublereal *cdata, doublereal *dscale, doublereal *tscale, doublereal *initjd, doublereal *initfr, ftnlen frame_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: spd_ 7 0 */
/*:ref: j2000_ 7 0 */
/*:ref: chckid_ 14 5 13 4 13 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern int spkw21_(void *cspice_state, integer *handle, integer *body, integer *center, char *frame, doublereal *first, doublereal *last, char *segid, integer *n, integer *dlsize, doublereal *dlines, doublereal *epochs, ftnlen frame_len, ftnlen segid_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: spkpds_ 14 8 4 4 13 4 7 7 7 124 */
/*:ref: dafbna_ 14 4 4 7 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: dafada_ 14 2 7 4 */
/*:ref: dafena_ 14 0 */
 
extern int srfc2s_(void *cspice_state, integer *code, integer *bodyid, char *srfstr, logical *isname, ftnlen srfstr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzsrfc2n_ 14 5 4 4 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: intstr_ 14 3 4 13 124 */
 
extern int srfcss_(void *cspice_state, integer *code, char *bodstr, char *srfstr, logical *isname, ftnlen bodstr_len, ftnlen srfstr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: bods2c_ 14 4 13 4 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzsrfc2n_ 14 5 4 4 13 12 124 */
/*:ref: intstr_ 14 3 4 13 124 */
 
extern int srfnrm_(void *cspice_state, char *method, char *target, doublereal *et, char *fixref, integer *npts, doublereal *srfpts, doublereal *normls, ftnlen method_len, ftnlen target_len, ftnlen fixref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzsrftrk_ 14 2 4 12 */
/*:ref: zzprsmet_ 14 15 4 13 4 13 13 12 4 4 13 13 124 124 124 124 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: zzbodvcd_ 14 7 4 13 4 4 4 7 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: dskgtl_ 14 2 4 7 */
/*:ref: surfnm_ 14 5 7 7 7 7 7 */
/*:ref: zzsbfnrm_ 14 7 4 4 4 7 4 7 7 */
/*:ref: vhatip_ 14 1 7 */
 
extern int srfrec_(void *cspice_state, integer *body, doublereal *long__, doublereal *lat, doublereal *rectan);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: latrec_ 14 4 7 7 7 7 */
/*:ref: edpnt_ 14 5 7 7 7 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int srfs2c_(void *cspice_state, char *srfstr, char *bodstr, integer *code, logical *found, ftnlen srfstr_len, ftnlen bodstr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: bods2c_ 14 4 13 4 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzsrfn2c_ 14 5 13 4 4 12 124 */
/*:ref: nparsi_ 14 6 13 4 13 4 124 124 */
 
extern int srfscc_(void *cspice_state, char *srfstr, integer *bodyid, integer *code, logical *found, ftnlen srfstr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzsrfn2c_ 14 5 13 4 4 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: nparsi_ 14 6 13 4 13 4 124 124 */
 
extern int srfxpt_(void *cspice_state, char *method, char *target, doublereal *et, char *abcorr, char *obsrvr, char *dref, doublereal *dvec, doublereal *spoint, doublereal *dist, doublereal *trgepc, doublereal *obspos, logical *found, ftnlen method_len, ftnlen target_len, ftnlen abcorr_len, ftnlen obsrvr_len, ftnlen dref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: eqchr_ 12 4 13 13 124 124 */
/*:ref: cidfrm_ 14 5 4 4 13 12 124 */
/*:ref: spkezp_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: pxform_ 14 6 13 13 7 7 124 124 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: spkssb_ 14 5 4 7 13 7 124 */
/*:ref: stelab_ 14 3 7 7 7 */
/*:ref: stlabx_ 14 3 7 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: dasine_ 7 2 7 7 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: surfpt_ 14 7 7 7 7 7 7 7 12 */
/*:ref: vdist_ 7 2 7 7 */
/*:ref: npedln_ 14 7 7 7 7 7 7 7 7 */
/*:ref: clight_ 7 0 */
/*:ref: touchd_ 7 1 7 */
 
extern int ssizec_(void *cspice_state, integer *size, char *cell, ftnlen cell_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: enchar_ 14 3 4 13 124 */
 
extern int ssized_(void *cspice_state, integer *size, doublereal *cell);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int ssizei_(void *cspice_state, integer *size, integer *cell);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int stcc01_(void *cspice_state, char *catfnm, char *tabnam, logical *istyp1, char *errmsg, ftnlen catfnm_len, ftnlen tabnam_len, ftnlen errmsg_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ekopr_ 14 3 13 4 124 */
/*:ref: eknseg_ 4 1 4 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ekssum_ 14 14 4 4 13 4 4 13 13 4 4 12 12 124 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: nblen_ 4 2 13 124 */
/*:ref: ekcls_ 14 1 4 */
 
extern int stcf01_(void *cspice_state, char *catnam, doublereal *westra, doublereal *eastra, doublereal *sthdec, doublereal *nthdec, integer *nstars, ftnlen catnam_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dpr_ 7 0 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: repmd_ 14 8 13 13 7 4 13 124 124 124 */
/*:ref: ekfind_ 14 6 13 4 12 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int stcg01_(void *cspice_state, integer *index, doublereal *ra, doublereal *dec, doublereal *rasig, doublereal *decsig, integer *catnum, char *sptype, doublereal *vmag, ftnlen sptype_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ekgd_ 14 6 4 4 4 7 12 12 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ekgi_ 14 6 4 4 4 4 12 12 */
/*:ref: ekgc_ 14 7 4 4 4 13 12 12 124 */
/*:ref: rpd_ 7 0 */
 
extern int stcl01_(void *cspice_state, char *catfnm, char *tabnam, integer *handle, ftnlen catfnm_len, ftnlen tabnam_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: stcc01_ 14 7 13 13 12 13 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: eklef_ 14 3 13 4 124 */
 
extern int stdio_(void *cspice_state, char *name__, integer *unit, ftnlen name_len);
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int stelab_(void *cspice_state, doublereal *pobj, doublereal *vobs, doublereal *appobj);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: clight_ 7 0 */
/*:ref: vscl_ 14 3 7 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: vrotv_ 14 4 7 7 7 7 */
/*:ref: moved_ 14 3 7 4 7 */
 
extern int stlabx_(void *cspice_state, doublereal *pobj, doublereal *vobs, doublereal *corpos);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: stelab_ 14 3 7 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int stmp03_(void *cspice_state, doublereal *x, doublereal *c0, doublereal *c1, doublereal *c2, doublereal *c3);
/*:ref: dpmax_ 7 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int stpool_(void *cspice_state, char *item, integer *nth, char *contin, char *string, integer *size, logical *found, ftnlen item_len, ftnlen contin_len, ftnlen string_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: gcpool_ 14 8 13 4 4 4 13 12 124 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int str2et_(void *cspice_state, char *string, doublereal *et, ftnlen string_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: timdef_ 14 6 13 13 13 124 124 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: zzutcpm_ 14 7 13 4 7 7 4 12 124 */
/*:ref: tpartv_ 14 15 13 7 4 13 13 12 12 12 13 13 124 124 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: ttrans_ 14 5 13 13 7 124 124 */
/*:ref: tchckd_ 14 2 13 124 */
/*:ref: tparch_ 14 2 13 124 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: tcheck_ 14 9 7 13 12 13 12 13 124 124 124 */
/*:ref: texpyr_ 14 1 4 */
/*:ref: jul2gr_ 14 4 4 4 4 4 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: dpfmt_ 14 5 7 13 13 124 124 */
/*:ref: gr2jul_ 14 4 4 4 4 4 */
 
extern int subpnt_(void *cspice_state, char *method, char *target, doublereal *et, char *fixref, char *abcorr, char *obsrvr, doublereal *spoint, doublereal *trgepc, doublereal *srfvec, ftnlen method_len, ftnlen target_len, ftnlen fixref_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzsrftrk_ 14 2 4 12 */
/*:ref: zzprsmet_ 14 15 4 13 4 13 13 12 4 4 13 13 124 124 124 124 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: zzsudski_ 14 4 4 4 4 4 */
/*:ref: spkezp_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: nearpt_ 14 6 7 7 7 7 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: zzsbfxr_ 14 9 4 4 4 7 4 7 7 7 12 */
/*:ref: surfpt_ 14 7 7 7 7 7 7 7 12 */
/*:ref: vdist_ 7 2 7 7 */
/*:ref: clight_ 7 0 */
/*:ref: spkssb_ 14 5 4 7 13 7 124 */
/*:ref: pxform_ 14 6 13 13 7 7 124 124 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: mtxv_ 14 3 7 7 7 */
/*:ref: stlabx_ 14 3 7 7 7 */
/*:ref: stelab_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: touchd_ 7 1 7 */
 
extern int subpt_(void *cspice_state, char *method, char *target, doublereal *et, char *abcorr, char *obsrvr, doublereal *spoint, doublereal *alt, ftnlen method_len, ftnlen target_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: cidfrm_ 14 5 4 4 13 12 124 */
/*:ref: spkez_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: nearpt_ 14 6 7 7 7 7 7 7 */
/*:ref: surfpt_ 14 7 7 7 7 7 7 7 12 */
/*:ref: vdist_ 7 2 7 7 */
 
extern int subslr_(void *cspice_state, char *method, char *target, doublereal *et, char *fixref, char *abcorr, char *obsrvr, doublereal *spoint, doublereal *trgepc, doublereal *srfvec, ftnlen method_len, ftnlen target_len, ftnlen fixref_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzsrftrk_ 14 2 4 12 */
/*:ref: zzprsmet_ 14 15 4 13 4 13 13 12 4 4 13 13 124 124 124 124 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: zzsudski_ 14 4 4 4 4 4 */
/*:ref: spkezp_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: nearpt_ 14 6 7 7 7 7 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: zzsbfxr_ 14 9 4 4 4 7 4 7 7 7 12 */
/*:ref: surfpt_ 14 7 7 7 7 7 7 7 12 */
/*:ref: vdist_ 7 2 7 7 */
/*:ref: clight_ 7 0 */
/*:ref: spkssb_ 14 5 4 7 13 7 124 */
/*:ref: pxform_ 14 6 13 13 7 7 124 124 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: spkcpo_ 14 16 13 7 13 13 13 7 13 13 7 7 124 124 124 124 124 124 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: touchd_ 7 1 7 */
/*:ref: spkcpt_ 14 16 7 13 13 7 13 13 13 13 7 7 124 124 124 124 124 124 */
/*:ref: vequ_ 14 2 7 7 */
 
extern int subsol_(void *cspice_state, char *method, char *target, doublereal *et, char *abcorr, char *obsrvr, doublereal *spoint, ftnlen method_len, ftnlen target_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: cidfrm_ 14 5 4 4 13 12 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: ltime_ 14 7 7 4 13 4 7 7 124 */
/*:ref: spkpos_ 14 11 13 7 13 13 13 7 7 124 124 124 124 */
/*:ref: nearpt_ 14 6 7 7 7 7 7 7 */
/*:ref: surfpt_ 14 7 7 7 7 7 7 7 12 */
 
extern int suffix_(void *cspice_state, char *suff, integer *spaces, char *string, ftnlen suff_len, ftnlen string_len);
/*:ref: lastnb_ 4 2 13 124 */
 
extern doublereal sumad_(void *cspice_state, doublereal *array, integer *n);
 
extern integer sumai_(void *cspice_state, integer *array, integer *n);
 
extern int surfnm_(void *cspice_state, doublereal *a, doublereal *b, doublereal *c__, doublereal *point, doublereal *normal);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vhatip_ 14 1 7 */
 
extern int surfpt_(void *cspice_state, doublereal *positn, doublereal *u, doublereal *a, doublereal *b, doublereal *c__, doublereal *point, logical *found);
/*:ref: return_ 12 0 */
/*:ref: vzero_ 12 1 7 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: vperp_ 14 3 7 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
 
extern int surfpv_(void *cspice_state, doublereal *stvrtx, doublereal *stdir, doublereal *a, doublereal *b, doublereal *c__, doublereal *stx, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: surfpt_ 14 7 7 7 7 7 7 7 12 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dvhat_ 14 2 7 7 */
/*:ref: surfnm_ 14 5 7 7 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vscl_ 14 3 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: dpmax_ 7 0 */
/*:ref: vlcom3_ 14 7 7 7 7 7 7 7 7 */
 
extern int swapac_(void *cspice_state, integer *n, integer *locn, integer *m, integer *locm, char *array, ftnlen array_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: swapc_ 14 4 13 13 124 124 */
/*:ref: cyacip_ 14 6 4 13 4 13 124 124 */
 
extern int swapad_(void *cspice_state, integer *n, integer *locn, integer *m, integer *locm, doublereal *array);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: swapd_ 14 2 7 7 */
/*:ref: cyadip_ 14 5 4 13 4 7 124 */
 
extern int swapai_(void *cspice_state, integer *n, integer *locn, integer *m, integer *locm, integer *array);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: swapi_ 14 2 4 4 */
/*:ref: cyaiip_ 14 5 4 13 4 4 124 */
 
extern int swapc_(void *cspice_state, char *a, char *b, ftnlen a_len, ftnlen b_len);
 
extern int swapd_(void *cspice_state, doublereal *a, doublereal *b);
 
extern int swapi_(void *cspice_state, integer *a, integer *b);
 
extern int sxform_(void *cspice_state, char *from, char *to, doublereal *et, doublereal *xform, ftnlen from_len, ftnlen to_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: frmchg_ 14 4 4 4 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sydelc_(void *cspice_state, char *name__, char *tabsym, integer *tabptr, char *tabval, ftnlen name_len, ftnlen tabsym_len, ftnlen tabval_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: remlac_ 14 5 4 4 13 4 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: remlai_ 14 4 4 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sydeld_(void *cspice_state, char *name__, char *tabsym, integer *tabptr, doublereal *tabval, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: cardd_ 4 1 7 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: remlac_ 14 5 4 4 13 4 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: remlai_ 14 4 4 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: remlad_ 14 4 4 4 7 4 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sydeli_(void *cspice_state, char *name__, char *tabsym, integer *tabptr, integer *tabval, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: remlac_ 14 5 4 4 13 4 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: remlai_ 14 4 4 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern integer sydimc_(void *cspice_state, char *name__, char *tabsym, integer *tabptr, char *tabval, ftnlen name_len, ftnlen tabsym_len, ftnlen tabval_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern integer sydimd_(void *cspice_state, char *name__, char *tabsym, integer *tabptr, doublereal *tabval, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern integer sydimi_(void *cspice_state, char *name__, char *tabsym, integer *tabptr, integer *tabval, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sydupc_(void *cspice_state, char *name__, char *copy, char *tabsym, integer *tabptr, char *tabval, ftnlen name_len, ftnlen copy_len, ftnlen tabsym_len, ftnlen tabval_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: lstlec_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: sizec_ 4 2 13 124 */
/*:ref: sizei_ 4 1 4 */
/*:ref: remlac_ 14 5 4 4 13 4 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: inslac_ 14 7 13 4 4 13 4 124 124 */
/*:ref: inslai_ 14 5 4 4 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sydupd_(void *cspice_state, char *name__, char *copy, char *tabsym, integer *tabptr, doublereal *tabval, ftnlen name_len, ftnlen copy_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: cardd_ 4 1 7 */
/*:ref: lstlec_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: sizec_ 4 2 13 124 */
/*:ref: sizei_ 4 1 4 */
/*:ref: sized_ 4 1 7 */
/*:ref: remlad_ 14 4 4 4 7 4 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: inslac_ 14 7 13 4 4 13 4 124 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: inslai_ 14 5 4 4 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sydupi_(void *cspice_state, char *name__, char *copy, char *tabsym, integer *tabptr, integer *tabval, ftnlen name_len, ftnlen copy_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: lstlec_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: sizec_ 4 2 13 124 */
/*:ref: sizei_ 4 1 4 */
/*:ref: remlai_ 14 4 4 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: inslac_ 14 7 13 4 4 13 4 124 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: inslai_ 14 5 4 4 4 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int syenqc_(void *cspice_state, char *name__, char *value, char *tabsym, integer *tabptr, char *tabval, ftnlen name_len, ftnlen value_len, ftnlen tabsym_len, ftnlen tabval_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: lstlec_ 4 5 13 4 13 124 124 */
/*:ref: sysetc_ 14 9 13 13 13 4 13 124 124 124 124 */
/*:ref: sizec_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: inslac_ 14 7 13 4 4 13 4 124 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int syenqd_(void *cspice_state, char *name__, doublereal *value, char *tabsym, integer *tabptr, doublereal *tabval, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: lstlec_ 4 5 13 4 13 124 124 */
/*:ref: sysetd_ 14 7 13 7 13 4 7 124 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: inslad_ 14 5 7 4 4 7 4 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int syenqi_(void *cspice_state, char *name__, integer *value, char *tabsym, integer *tabptr, integer *tabval, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: lstlec_ 4 5 13 4 13 124 124 */
/*:ref: syseti_ 14 7 13 4 13 4 4 124 124 */
/*:ref: sizei_ 4 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: inslai_ 14 5 4 4 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int syfetc_(void *cspice_state, integer *nth, char *tabsym, integer *tabptr, char *tabval, char *name__, logical *found, ftnlen tabsym_len, ftnlen tabval_len, ftnlen name_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int syfetd_(void *cspice_state, integer *nth, char *tabsym, integer *tabptr, doublereal *tabval, char *name__, logical *found, ftnlen tabsym_len, ftnlen name_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int syfeti_(void *cspice_state, integer *nth, char *tabsym, integer *tabptr, integer *tabval, char *name__, logical *found, ftnlen tabsym_len, ftnlen name_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sygetc_(void *cspice_state, char *name__, char *tabsym, integer *tabptr, char *tabval, integer *n, char *values, logical *found, ftnlen name_len, ftnlen tabsym_len, ftnlen tabval_len, ftnlen values_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: movec_ 14 5 13 4 13 124 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sygetd_(void *cspice_state, char *name__, char *tabsym, integer *tabptr, doublereal *tabval, integer *n, doublereal *values, logical *found, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sygeti_(void *cspice_state, char *name__, char *tabsym, integer *tabptr, integer *tabval, integer *n, integer *values, logical *found, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int synthc_(void *cspice_state, char *name__, integer *nth, char *tabsym, integer *tabptr, char *tabval, char *value, logical *found, ftnlen name_len, ftnlen tabsym_len, ftnlen tabval_len, ftnlen value_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int synthd_(void *cspice_state, char *name__, integer *nth, char *tabsym, integer *tabptr, doublereal *tabval, doublereal *value, logical *found, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int synthi_(void *cspice_state, char *name__, integer *nth, char *tabsym, integer *tabptr, integer *tabval, integer *value, logical *found, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int syordc_(void *cspice_state, char *name__, char *tabsym, integer *tabptr, char *tabval, ftnlen name_len, ftnlen tabsym_len, ftnlen tabval_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: shellc_ 14 3 4 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int syordd_(void *cspice_state, char *name__, char *tabsym, integer *tabptr, doublereal *tabval, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: shelld_ 14 2 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int syordi_(void *cspice_state, char *name__, char *tabsym, integer *tabptr, integer *tabval, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: shelli_ 14 2 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sypopc_(void *cspice_state, char *name__, char *tabsym, integer *tabptr, char *tabval, char *value, logical *found, ftnlen name_len, ftnlen tabsym_len, ftnlen tabval_len, ftnlen value_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: remlac_ 14 5 4 4 13 4 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: remlai_ 14 4 4 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sypopd_(void *cspice_state, char *name__, char *tabsym, integer *tabptr, doublereal *tabval, doublereal *value, logical *found, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: cardd_ 4 1 7 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: remlad_ 14 4 4 4 7 4 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: remlac_ 14 5 4 4 13 4 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: remlai_ 14 4 4 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sypopi_(void *cspice_state, char *name__, char *tabsym, integer *tabptr, integer *tabval, integer *value, logical *found, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: remlai_ 14 4 4 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: remlac_ 14 5 4 4 13 4 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sypshc_(void *cspice_state, char *name__, char *value, char *tabsym, integer *tabptr, char *tabval, ftnlen name_len, ftnlen value_len, ftnlen tabsym_len, ftnlen tabval_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: lstlec_ 4 5 13 4 13 124 124 */
/*:ref: sysetc_ 14 9 13 13 13 4 13 124 124 124 124 */
/*:ref: sizec_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: inslac_ 14 7 13 4 4 13 4 124 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sypshd_(void *cspice_state, char *name__, doublereal *value, char *tabsym, integer *tabptr, doublereal *tabval, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: lstlec_ 4 5 13 4 13 124 124 */
/*:ref: sysetd_ 14 7 13 7 13 4 7 124 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: inslad_ 14 5 7 4 4 7 4 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sypshi_(void *cspice_state, char *name__, integer *value, char *tabsym, integer *tabptr, integer *tabval, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: lstlec_ 4 5 13 4 13 124 124 */
/*:ref: syseti_ 14 7 13 4 13 4 4 124 124 */
/*:ref: sizei_ 4 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: inslai_ 14 5 4 4 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int syputc_(void *cspice_state, char *name__, char *values, integer *n, char *tabsym, integer *tabptr, char *tabval, ftnlen name_len, ftnlen values_len, ftnlen tabsym_len, ftnlen tabval_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: lstlec_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: sizec_ 4 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sizei_ 4 1 4 */
/*:ref: remlac_ 14 5 4 4 13 4 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: inslac_ 14 7 13 4 4 13 4 124 124 */
/*:ref: inslai_ 14 5 4 4 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
 
extern int syputd_(void *cspice_state, char *name__, doublereal *values, integer *n, char *tabsym, integer *tabptr, doublereal *tabval, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: cardd_ 4 1 7 */
/*:ref: lstlec_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: sizec_ 4 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sizei_ 4 1 4 */
/*:ref: sized_ 4 1 7 */
/*:ref: remlad_ 14 4 4 4 7 4 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: inslac_ 14 7 13 4 4 13 4 124 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: inslai_ 14 5 4 4 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: inslad_ 14 5 7 4 4 7 4 */
 
extern int syputi_(void *cspice_state, char *name__, integer *values, integer *n, char *tabsym, integer *tabptr, integer *tabval, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: lstlec_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: sizec_ 4 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sizei_ 4 1 4 */
/*:ref: remlai_ 14 4 4 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: inslac_ 14 7 13 4 4 13 4 124 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: inslai_ 14 5 4 4 4 4 4 */
 
extern int syrenc_(void *cspice_state, char *old, char *new__, char *tabsym, integer *tabptr, char *tabval, ftnlen old_len, ftnlen new_len, ftnlen tabsym_len, ftnlen tabval_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: sydelc_ 14 7 13 13 4 13 124 124 124 */
/*:ref: lstlec_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: swapac_ 14 6 4 4 4 4 13 124 */
/*:ref: swapai_ 14 5 4 4 4 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int syrend_(void *cspice_state, char *old, char *new__, char *tabsym, integer *tabptr, doublereal *tabval, ftnlen old_len, ftnlen new_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: sydeld_ 14 6 13 13 4 7 124 124 */
/*:ref: lstlec_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: swapad_ 14 5 4 4 4 4 7 */
/*:ref: swapac_ 14 6 4 4 4 4 13 124 */
/*:ref: swapai_ 14 5 4 4 4 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int syreni_(void *cspice_state, char *old, char *new__, char *tabsym, integer *tabptr, integer *tabval, ftnlen old_len, ftnlen new_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: sydeli_ 14 6 13 13 4 4 124 124 */
/*:ref: lstlec_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: swapai_ 14 5 4 4 4 4 4 */
/*:ref: swapac_ 14 6 4 4 4 4 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int syselc_(void *cspice_state, char *name__, integer *begin, integer *end, char *tabsym, integer *tabptr, char *tabval, char *values, logical *found, ftnlen name_len, ftnlen tabsym_len, ftnlen tabval_len, ftnlen values_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: movec_ 14 5 13 4 13 124 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int syseld_(void *cspice_state, char *name__, integer *begin, integer *end, char *tabsym, integer *tabptr, doublereal *tabval, doublereal *values, logical *found, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int syseli_(void *cspice_state, char *name__, integer *begin, integer *end, char *tabsym, integer *tabptr, integer *tabval, integer *values, logical *found, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sysetc_(void *cspice_state, char *name__, char *value, char *tabsym, integer *tabptr, char *tabval, ftnlen name_len, ftnlen value_len, ftnlen tabsym_len, ftnlen tabval_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: lstlec_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: remlac_ 14 5 4 4 13 4 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: sizec_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: sizei_ 4 1 4 */
/*:ref: inslac_ 14 7 13 4 4 13 4 124 124 */
/*:ref: inslai_ 14 5 4 4 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sysetd_(void *cspice_state, char *name__, doublereal *value, char *tabsym, integer *tabptr, doublereal *tabval, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: cardd_ 4 1 7 */
/*:ref: lstlec_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: remlad_ 14 4 4 4 7 4 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: sizec_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: sizei_ 4 1 4 */
/*:ref: sized_ 4 1 7 */
/*:ref: inslac_ 14 7 13 4 4 13 4 124 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: inslai_ 14 5 4 4 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: inslad_ 14 5 7 4 4 7 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int syseti_(void *cspice_state, char *name__, integer *value, char *tabsym, integer *tabptr, integer *tabval, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: lstlec_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: remlai_ 14 4 4 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: sizec_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: sizei_ 4 1 4 */
/*:ref: inslac_ 14 7 13 4 4 13 4 124 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: inslai_ 14 5 4 4 4 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sytrnc_(void *cspice_state, char *name__, integer *i__, integer *j, char *tabsym, integer *tabptr, char *tabval, ftnlen name_len, ftnlen tabsym_len, ftnlen tabval_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: swapc_ 14 4 13 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sytrnd_(void *cspice_state, char *name__, integer *i__, integer *j, char *tabsym, integer *tabptr, doublereal *tabval, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: swapd_ 14 2 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int sytrni_(void *cspice_state, char *name__, integer *i__, integer *j, char *tabsym, integer *tabptr, integer *tabval, ftnlen name_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: sumai_ 4 2 4 4 */
/*:ref: swapi_ 14 2 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int tcheck_(void *cspice_state, doublereal *tvec, char *type__, logical *mods, char *modify, logical *ok, char *error, ftnlen type_len, ftnlen modify_len, ftnlen error_len);
extern int tparch_(void *cspice_state, char *type__, ftnlen type_len);
extern int tchckd_(void *cspice_state, char *type__, ftnlen type_len);
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: repmd_ 14 8 13 13 7 4 13 124 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
 
extern int termpt_(void *cspice_state, char *method, char *ilusrc, char *target, doublereal *et, char *fixref, char *abcorr, char *corloc, char *obsrvr, doublereal *refvec, doublereal *rolstp, integer *ncuts, doublereal *schstp, doublereal *soltol, integer *maxn, integer *npts, doublereal *points, doublereal *epochs, doublereal *trmvcs, ftnlen method_len, ftnlen ilusrc_len, ftnlen target_len, ftnlen fixref_len, ftnlen abcorr_len, ftnlen corloc_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzsrftrk_ 14 2 4 12 */
/*:ref: zzprsmet_ 14 15 4 13 4 13 13 12 4 4 13 13 124 124 124 124 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: vzero_ 12 1 7 */
/*:ref: zzsudski_ 14 4 4 4 4 4 */
/*:ref: zzmaxrad_ 14 1 7 */
/*:ref: zzbodvcd_ 14 7 4 13 4 4 4 7 124 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: ssized_ 14 2 4 7 */
/*:ref: spkpos_ 14 11 13 7 13 13 13 7 7 124 124 124 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: zzcorepc_ 14 5 13 7 7 7 124 */
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: vrotv_ 14 4 7 7 7 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: zztangnt_ 14 14 4 7 4 4 4 4 4 7 7 7 7 7 7 7 */
/*:ref: cardd_ 4 1 7 */
/*:ref: zzedtmpt_ 14 8 12 7 7 7 7 7 7 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vscl_ 14 3 7 7 7 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: zzraysfx_ 14 5 7 7 7 7 12 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: spkssb_ 14 5 4 7 13 7 124 */
/*:ref: spkgps_ 14 7 4 7 13 4 7 7 124 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: spkezp_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: pxform_ 14 6 13 13 7 7 124 124 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: touchd_ 7 1 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
/*:ref: mtxv_ 14 3 7 7 7 */
/*:ref: stelab_ 14 3 7 7 7 */
 
extern int texpyr_(void *cspice_state, integer *year);
extern int tsetyr_(void *cspice_state, integer *year);
 
extern int timdef_(void *cspice_state, char *action, char *item, char *value, ftnlen action_len, ftnlen item_len, ftnlen value_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: zzutcpm_ 14 7 13 4 7 7 4 12 124 */
 
extern int timout_(void *cspice_state, doublereal *et, char *pictur, char *output, ftnlen pictur_len, ftnlen output_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: scanpr_ 14 5 4 13 4 4 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: scan_ 14 12 13 13 4 4 4 4 4 4 4 4 124 124 */
/*:ref: timdef_ 14 6 13 13 13 124 124 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: zzutcpm_ 14 7 13 4 7 7 4 12 124 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: scanrj_ 14 6 4 4 4 4 4 4 */
/*:ref: unitim_ 7 5 7 13 13 124 124 */
/*:ref: spd_ 7 0 */
/*:ref: j2000_ 7 0 */
/*:ref: j1950_ 7 0 */
/*:ref: brckti_ 4 3 4 4 4 */
/*:ref: brcktd_ 7 3 7 7 7 */
/*:ref: dpfmt_ 14 5 7 13 13 124 124 */
/*:ref: ttrans_ 14 5 13 13 7 124 124 */
/*:ref: gr2jul_ 14 4 4 4 4 4 */
/*:ref: jul2gr_ 14 4 4 4 4 4 */
/*:ref: rmaind_ 14 4 7 7 7 7 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: lcase_ 14 4 13 13 124 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int tipbod_(void *cspice_state, char *ref, integer *body, doublereal *et, doublereal *tipm, ftnlen ref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: tisbod_ 14 5 13 4 7 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int tisbod_(void *cspice_state, char *ref, integer *body, doublereal *et, doublereal *tsipm, ftnlen ref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzhsiini_ 14 3 4 4 4 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: spd_ 7 0 */
/*:ref: pckmat_ 14 5 4 7 4 7 12 */
/*:ref: zzpctrck_ 14 2 4 12 */
/*:ref: zzhsichk_ 14 5 4 4 4 4 4 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: ccifrm_ 14 7 4 4 4 13 4 12 124 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzbodbry_ 4 1 4 */
/*:ref: gdpool_ 14 7 13 4 4 4 7 12 124 */
/*:ref: j2000_ 7 0 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: bodfnd_ 12 3 4 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: zzhsiavl_ 14 2 4 4 */
/*:ref: zzhsiadd_ 14 6 4 4 4 4 4 12 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: rpd_ 7 0 */
/*:ref: vdotg_ 7 3 7 7 4 */
/*:ref: twopi_ 7 0 */
/*:ref: halfpi_ 7 0 */
/*:ref: vpack_ 14 4 7 7 7 7 */
/*:ref: eul2xf_ 14 5 7 4 4 4 7 */
/*:ref: irfrot_ 14 3 4 4 7 */
/*:ref: mxm_ 14 3 7 7 7 */
 
extern int tkfram_(void *cspice_state, integer *id, doublereal *rot, integer *frame, logical *found);
/*:ref: lnkini_ 14 2 4 4 */
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lnknfn_ 4 1 4 */
/*:ref: lnktl_ 4 2 4 4 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: locati_ 14 6 4 4 4 4 4 12 */
/*:ref: cvpool_ 14 3 13 12 124 */
/*:ref: dwpool_ 14 2 13 124 */
/*:ref: ident_ 14 1 7 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: frmnam_ 14 3 4 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: badkpv_ 12 10 13 13 13 4 4 13 124 124 124 124 */
/*:ref: gcpool_ 14 8 13 4 4 4 13 12 124 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: gdpool_ 14 7 13 4 4 4 7 12 124 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: sharpr_ 14 1 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vsclip_ 14 2 7 7 */
/*:ref: gipool_ 14 7 13 4 4 4 4 12 124 */
/*:ref: convrt_ 14 6 7 13 13 7 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: eul2m_ 14 7 7 7 7 4 4 4 7 */
/*:ref: vhatg_ 14 3 7 4 7 */
/*:ref: q2m_ 14 2 7 7 */
/*:ref: swpool_ 14 5 13 4 13 124 124 */
 
extern int tkvrsn_(void *cspice_state, char *item, char *verstr, ftnlen item_len, ftnlen verstr_len);
/*:ref: eqstr_ 12 4 13 13 124 124 */
 
extern int tostdo_(void *cspice_state, char *line, ftnlen line_len);
/*:ref: stdio_ 14 3 13 4 124 */
/*:ref: writln_ 14 3 13 4 124 */
 
extern H_f touchc_(void *cspice_state, char *ret_val, ftnlen ret_val_len, char *string, ftnlen string_len);
 
extern doublereal touchd_(void *cspice_state, doublereal *dp);
 
extern integer touchi_(void *cspice_state, integer *int__);
 
extern logical touchl_(void *cspice_state, logical *log__);
 
extern int tparse_(void *cspice_state, char *string, doublereal *sp2000, char *error, ftnlen string_len, ftnlen error_len);
/*:ref: tpartv_ 14 15 13 7 4 13 13 12 12 12 13 13 124 124 124 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: j2000_ 7 0 */
/*:ref: spd_ 7 0 */
/*:ref: tcheck_ 14 9 7 13 12 13 12 13 124 124 124 */
/*:ref: texpyr_ 14 1 4 */
/*:ref: rmaini_ 14 4 4 4 4 4 */
 
extern int tpartv_(void *cspice_state, char *string, doublereal *tvec, integer *ntvec, char *type__, char *modify, logical *mods, logical *yabbrv, logical *succes, char *pictur, char *error, ftnlen string_len, ftnlen type_len, ftnlen modify_len, ftnlen pictur_len, ftnlen error_len);
/*:ref: zztpats_ 12 6 4 4 13 13 124 124 */
/*:ref: zztokns_ 12 4 13 13 124 124 */
/*:ref: zzcmbt_ 12 5 13 13 12 124 124 */
/*:ref: zzsubt_ 12 5 13 13 12 124 124 */
/*:ref: zzrept_ 12 5 13 13 12 124 124 */
/*:ref: zzremt_ 12 2 13 124 */
/*:ref: zzist_ 12 2 13 124 */
/*:ref: zznote_ 12 4 13 4 4 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: zzunpck_ 12 11 13 12 7 4 13 13 13 124 124 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: intmax_ 4 0 */
/*:ref: zzvalt_ 12 6 13 4 4 13 124 124 */
/*:ref: zzgrep_ 12 2 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: zzispt_ 12 4 13 4 4 124 */
/*:ref: zzinssub_ 14 7 13 13 4 13 124 124 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
 
extern int tpictr_(void *cspice_state, char *sample, char *pictur, logical *ok, char *error, ftnlen sample_len, ftnlen pictur_len, ftnlen error_len);
/*:ref: tpartv_ 14 15 13 7 4 13 13 12 12 12 13 13 124 124 124 124 124 */
 
extern doublereal trace_(void *cspice_state, doublereal *matrix);
 
extern doublereal traceg_(void *cspice_state, doublereal *matrix, integer *ndim);
 
extern int trcpkg_(void *cspice_state, integer *depth, integer *index, char *module, char *trace, char *name__, ftnlen module_len, ftnlen trace_len, ftnlen name_len);
extern int chkin_(void *cspice_state, char *module, ftnlen module_len);
extern int chkout_(void *cspice_state, char *module, ftnlen module_len);
extern int trcdep_(void *cspice_state, integer *depth);
extern int trcmxd_(void *cspice_state, integer *depth);
extern int trcnam_(void *cspice_state, integer *index, char *name__, ftnlen name_len);
extern int qcktrc_(void *cspice_state, char *trace, ftnlen trace_len);
extern int freeze_(void *cspice_state);
extern int trcoff_(void *cspice_state);
/*:ref: wrline_ 14 4 13 13 124 124 */
/*:ref: frstnb_ 4 2 13 124 */
/*:ref: getdev_ 14 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: getact_ 14 1 4 */
/*:ref: failed_ 12 0 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
 
extern int ttrans_(void *cspice_state, char *from, char *to, doublereal *tvec, ftnlen from_len, ftnlen to_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: spd_ 7 0 */
/*:ref: j2000_ 7 0 */
/*:ref: ssizec_ 14 3 4 13 124 */
/*:ref: insrtc_ 14 4 13 13 124 124 */
/*:ref: orderc_ 14 4 13 4 4 124 */
/*:ref: reordc_ 14 4 4 4 13 124 */
/*:ref: reordi_ 14 3 4 4 4 */
/*:ref: reordl_ 14 3 4 4 12 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: swpool_ 14 5 13 4 13 124 124 */
/*:ref: zzcvpool_ 14 4 13 4 12 124 */
/*:ref: gdpool_ 14 7 13 4 4 4 7 12 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: nextwd_ 14 6 13 13 13 124 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: rmaini_ 14 4 4 4 4 4 */
/*:ref: lstlei_ 4 3 4 4 4 */
/*:ref: odd_ 12 1 4 */
/*:ref: rmaind_ 14 4 7 7 7 7 */
/*:ref: elemc_ 12 4 13 13 124 124 */
/*:ref: unitim_ 7 5 7 13 13 124 124 */
/*:ref: lstled_ 4 3 7 4 7 */
/*:ref: lstlti_ 4 3 4 4 4 */
 
extern doublereal twopi_(void *cspice_state);
 
extern int twovec_(void *cspice_state, doublereal *axdef, integer *indexa, doublereal *plndef, integer *indexp, doublereal *mout);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: ucrss_ 14 3 7 7 7 */
/*:ref: xpose_ 14 2 7 7 */
/*:ref: moved_ 14 3 7 4 7 */
 
extern int twovxf_(void *cspice_state, doublereal *axdef, integer *indexa, doublereal *plndef, integer *indexp, doublereal *xform);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zztwovxf_ 14 5 7 4 7 4 7 */
/*:ref: invstm_ 14 2 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int txtopn_(void *cspice_state, char *fname, integer *unit, ftnlen fname_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: getlun_ 14 1 4 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern int txtopr_(void *cspice_state, char *fname, integer *unit, ftnlen fname_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: getlun_ 14 1 4 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern doublereal tyear_(void *cspice_state);
 
extern int ucase_(void *cspice_state, char *in, char *out, ftnlen in_len, ftnlen out_len);
 
extern int ucrss_(void *cspice_state, doublereal *v1, doublereal *v2, doublereal *vout);
/*:ref: vnorm_ 7 1 7 */
 
extern int uddc_(void *cspice_state, U_fp udfunc, doublereal *x, doublereal *dx, logical *isdecr);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: uddf_ 14 4 200 7 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int uddf_(void *cspice_state, S_fp udfunc, doublereal *x, doublereal *dx, doublereal *deriv);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: qderiv_ 14 5 4 7 7 7 7 */
 
extern int udf_(void *cspice_state, doublereal *x, doublereal *value);
 
extern int unionc_(void *cspice_state, char *a, char *b, char *c__, ftnlen a_len, ftnlen b_len, ftnlen c_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: sizec_ 4 2 13 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: excess_ 14 3 4 13 124 */
 
extern int uniond_(void *cspice_state, doublereal *a, doublereal *b, doublereal *c__);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: sized_ 4 1 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: excess_ 14 3 4 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int unioni_(void *cspice_state, integer *a, integer *b, integer *c__);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: sizei_ 4 1 4 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: excess_ 14 3 4 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern doublereal unitim_(void *cspice_state, doublereal *epoch, char *insys, char *outsys, ftnlen insys_len, ftnlen outsys_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: spd_ 7 0 */
/*:ref: j2000_ 7 0 */
/*:ref: validc_ 14 4 4 4 13 124 */
/*:ref: ssizec_ 14 3 4 13 124 */
/*:ref: unionc_ 14 6 13 13 13 124 124 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: swpool_ 14 5 13 4 13 124 124 */
/*:ref: zzcvpool_ 14 4 13 4 12 124 */
/*:ref: gdpool_ 14 7 13 4 4 4 7 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: somfls_ 12 2 12 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: insrtc_ 14 4 13 13 124 124 */
/*:ref: setc_ 12 6 13 13 13 124 124 124 */
/*:ref: elemc_ 12 4 13 13 124 124 */
 
extern int unorm_(void *cspice_state, doublereal *v1, doublereal *vout, doublereal *vmag);
/*:ref: vnorm_ 7 1 7 */
 
extern int unormg_(void *cspice_state, doublereal *v1, integer *ndim, doublereal *vout, doublereal *vmag);
/*:ref: vnormg_ 7 2 7 4 */
 
extern int utc2et_(void *cspice_state, char *utcstr, doublereal *et, ftnlen utcstr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: tpartv_ 14 15 13 7 4 13 13 12 12 12 13 13 124 124 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: tcheck_ 14 9 7 13 12 13 12 13 124 124 124 */
/*:ref: texpyr_ 14 1 4 */
/*:ref: ttrans_ 14 5 13 13 7 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
 
extern int vadd_(void *cspice_state, doublereal *v1, doublereal *v2, doublereal *vout);
 
extern int vaddg_(void *cspice_state, doublereal *v1, doublereal *v2, integer *ndim, doublereal *vout);
 
extern int validc_(void *cspice_state, integer *size, integer *n, char *a, ftnlen a_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rmdupc_ 14 3 4 13 124 */
/*:ref: ssizec_ 14 3 4 13 124 */
/*:ref: scardc_ 14 3 4 13 124 */
 
extern int validd_(void *cspice_state, integer *size, integer *n, doublereal *a);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rmdupd_ 14 2 4 7 */
/*:ref: ssized_ 14 2 4 7 */
/*:ref: scardd_ 14 2 4 7 */
 
extern int validi_(void *cspice_state, integer *size, integer *n, integer *a);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rmdupi_ 14 2 4 4 */
/*:ref: ssizei_ 14 2 4 4 */
/*:ref: scardi_ 14 2 4 4 */
 
extern int vcrss_(void *cspice_state, doublereal *v1, doublereal *v2, doublereal *vout);
 
extern doublereal vdist_(void *cspice_state, doublereal *v1, doublereal *v2);
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
 
extern doublereal vdistg_(void *cspice_state, doublereal *v1, doublereal *v2, integer *ndim);
 
extern doublereal vdot_(void *cspice_state, doublereal *v1, doublereal *v2);
 
extern doublereal vdotg_(void *cspice_state, doublereal *v1, doublereal *v2, integer *ndim);
 
extern int vequ_(void *cspice_state, doublereal *vin, doublereal *vout);
 
extern int vequg_(void *cspice_state, doublereal *vin, integer *ndim, doublereal *vout);
 
extern int vhat_(void *cspice_state, doublereal *v1, doublereal *vout);
/*:ref: vnorm_ 7 1 7 */
 
extern int vhatg_(void *cspice_state, doublereal *v1, integer *ndim, doublereal *vout);
/*:ref: vnormg_ 7 2 7 4 */
 
extern int vhatip_(void *cspice_state, doublereal *v);
/*:ref: vnorm_ 7 1 7 */
 
extern int vlcom_(void *cspice_state, doublereal *a, doublereal *v1, doublereal *b, doublereal *v2, doublereal *sum);
 
extern int vlcom3_(void *cspice_state, doublereal *a, doublereal *v1, doublereal *b, doublereal *v2, doublereal *c__, doublereal *v3, doublereal *sum);
 
extern int vlcomg_(void *cspice_state, integer *n, doublereal *a, doublereal *v1, doublereal *b, doublereal *v2, doublereal *sum);
 
extern int vminug_(void *cspice_state, doublereal *vin, integer *ndim, doublereal *vout);
 
extern int vminus_(void *cspice_state, doublereal *v1, doublereal *vout);
 
extern doublereal vnorm_(void *cspice_state, doublereal *v1);
 
extern doublereal vnormg_(void *cspice_state, doublereal *v1, integer *ndim);
 
extern int vpack_(void *cspice_state, doublereal *x, doublereal *y, doublereal *z__, doublereal *v);
 
extern int vperp_(void *cspice_state, doublereal *a, doublereal *b, doublereal *p);
/*:ref: vproj_ 14 3 7 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vsclip_ 14 2 7 7 */
 
extern int vprjp_(void *cspice_state, doublereal *vin, doublereal *plane, doublereal *vout);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: pl2nvc_ 14 3 7 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int vprjpi_(void *cspice_state, doublereal *vin, doublereal *projpl, doublereal *invpl, doublereal *vout, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: pl2nvc_ 14 3 7 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: dpmax_ 7 0 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int vproj_(void *cspice_state, doublereal *a, doublereal *b, doublereal *p);
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vscl_ 14 3 7 7 7 */
 
extern int vprojg_(void *cspice_state, doublereal *a, doublereal *b, integer *ndim, doublereal *p);
/*:ref: vdotg_ 7 3 7 7 4 */
/*:ref: vsclg_ 14 4 7 7 4 7 */
 
extern doublereal vrel_(void *cspice_state, doublereal *v1, doublereal *v2);
/*:ref: vdist_ 7 2 7 7 */
/*:ref: vnorm_ 7 1 7 */
 
extern doublereal vrelg_(void *cspice_state, doublereal *v1, doublereal *v2, integer *ndim);
/*:ref: vdistg_ 7 3 7 7 4 */
/*:ref: vnormg_ 7 2 7 4 */
 
extern int vrotv_(void *cspice_state, doublereal *v, doublereal *axis, doublereal *theta, doublereal *r__);
/*:ref: vnorm_ 7 1 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vproj_ 14 3 7 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
 
extern int vscl_(void *cspice_state, doublereal *s, doublereal *v1, doublereal *vout);
 
extern int vsclg_(void *cspice_state, doublereal *s, doublereal *v1, integer *ndim, doublereal *vout);
 
extern int vsclip_(void *cspice_state, doublereal *s, doublereal *v);
 
extern doublereal vsep_(void *cspice_state, doublereal *v1, doublereal *v2);
/*:ref: unorm_ 14 3 7 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: pi_ 7 0 */
 
extern doublereal vsepg_(void *cspice_state, doublereal *v1, doublereal *v2, integer *ndim);
/*:ref: vnormg_ 7 2 7 4 */
/*:ref: vdotg_ 7 3 7 7 4 */
/*:ref: pi_ 7 0 */
 
extern int vsub_(void *cspice_state, doublereal *v1, doublereal *v2, doublereal *vout);
 
extern int vsubg_(void *cspice_state, doublereal *v1, doublereal *v2, integer *ndim, doublereal *vout);
 
extern doublereal vtmv_(void *cspice_state, doublereal *v1, doublereal *matrix, doublereal *v2);
 
extern doublereal vtmvg_(void *cspice_state, doublereal *v1, doublereal *matrix, doublereal *v2, integer *nrow, integer *ncol);
 
extern int vupack_(void *cspice_state, doublereal *v, doublereal *x, doublereal *y, doublereal *z__);
 
extern logical vzero_(void *cspice_state, doublereal *v);
 
extern logical vzerog_(void *cspice_state, doublereal *v, integer *ndim);
 
extern integer wdcnt_(void *cspice_state, char *string, ftnlen string_len);
 
extern integer wdindx_(void *cspice_state, char *string, char *word, ftnlen string_len, ftnlen word_len);
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: frstnb_ 4 2 13 124 */
 
extern integer wncard_(void *cspice_state, doublereal *window);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: even_ 12 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int wncomd_(void *cspice_state, doublereal *left, doublereal *right, doublereal *window, doublereal *result);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: wninsd_ 14 3 7 7 7 */
/*:ref: failed_ 12 0 */
 
extern int wncond_(void *cspice_state, doublereal *left, doublereal *right, doublereal *window);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: wnexpd_ 14 3 7 7 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int wndifd_(void *cspice_state, doublereal *a, doublereal *b, doublereal *c__);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: sized_ 4 1 7 */
/*:ref: ssized_ 14 2 4 7 */
/*:ref: copyd_ 14 2 7 7 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern logical wnelmd_(void *cspice_state, doublereal *point, doublereal *window);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int wnexpd_(void *cspice_state, doublereal *left, doublereal *right, doublereal *window);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int wnextd_(void *cspice_state, char *side, doublereal *window, ftnlen side_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int wnfetd_(void *cspice_state, doublereal *window, integer *n, doublereal *left, doublereal *right);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int wnfild_(void *cspice_state, doublereal *small, doublereal *window);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int wnfltd_(void *cspice_state, doublereal *small, doublereal *window);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern logical wnincd_(void *cspice_state, doublereal *left, doublereal *right, doublereal *window);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int wninsd_(void *cspice_state, doublereal *left, doublereal *right, doublereal *window);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: cardd_ 4 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: excess_ 14 3 4 13 124 */
 
extern int wnintd_(void *cspice_state, doublereal *a, doublereal *b, doublereal *c__);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: sized_ 4 1 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: excess_ 14 3 4 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern logical wnreld_(void *cspice_state, doublereal *a, char *op, doublereal *b, ftnlen op_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: wnincd_ 12 3 7 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int wnsumd_(void *cspice_state, doublereal *window, doublereal *meas, doublereal *avg, doublereal *stddev, integer *short__, integer *long__);
/*:ref: return_ 12 0 */
/*:ref: cardd_ 4 1 7 */
/*:ref: even_ 12 1 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int wnunid_(void *cspice_state, doublereal *a, doublereal *b, doublereal *c__);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: sized_ 4 1 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: excess_ 14 3 4 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int wnvald_(void *cspice_state, integer *size, integer *n, doublereal *a);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: odd_ 12 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ssized_ 14 2 4 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: wninsd_ 14 3 7 7 7 */
 
extern int wrencc_(void *cspice_state, integer *unit, integer *n, char *data, ftnlen data_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int wrencd_(void *cspice_state, integer *unit, integer *n, doublereal *data);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dp2hx_ 14 4 7 13 4 124 */
 
extern int wrenci_(void *cspice_state, integer *unit, integer *n, integer *data);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: int2hx_ 14 4 4 13 4 124 */
 
extern int writla_(void *cspice_state, integer *numlin, char *array, integer *unit, ftnlen array_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: writln_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
 
extern int writln_(void *cspice_state, char *line, integer *unit, ftnlen line_len);
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int wrkvar_(void *cspice_state, integer *unit, char *name__, char *dirctv, char *tabsym, integer *tabptr, doublereal *tabval, ftnlen name_len, ftnlen dirctv_len, ftnlen tabsym_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sydimd_ 4 6 13 13 4 7 124 124 */
/*:ref: synthd_ 14 9 13 4 13 4 7 7 12 124 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: rjust_ 14 4 13 13 124 124 */
/*:ref: ioerr_ 14 5 13 13 4 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int wrline_(void *cspice_state, char *device, char *line, ftnlen device_len, ftnlen line_len);
extern int clline_(void *cspice_state, char *device, ftnlen device_len);
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: ltrim_ 4 2 13 124 */
/*:ref: fndlun_ 14 1 4 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: intstr_ 14 3 4 13 124 */
 
extern int xdda_(void *cspice_state, doublereal *vertex, doublereal *raydir, integer *grdext, integer *maxnvx, integer *nvx, integer *voxlst);
/*:ref: return_ 12 0 */
/*:ref: vzero_ 12 1 7 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: brckti_ 4 3 4 4 4 */
/*:ref: brcktd_ 7 3 7 7 7 */
/*:ref: dpmax_ 7 0 */
/*:ref: zzingrd_ 12 2 4 4 */
 
extern int xf2eul_(void *cspice_state, doublereal *xform, integer *axisa, integer *axisb, integer *axisc, doublereal *eulang, logical *unique);
extern int eul2xf_(void *cspice_state, doublereal *eulang, integer *axisa, integer *axisb, integer *axisc, doublereal *xform);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: m2eul_ 14 7 7 4 4 4 7 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: mxmt_ 14 3 7 7 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: eul2m_ 14 7 7 7 7 4 4 4 7 */
/*:ref: mxm_ 14 3 7 7 7 */
 
extern int xf2rav_(void *cspice_state, doublereal *xform, doublereal *rot, doublereal *av);
/*:ref: mtxm_ 14 3 7 7 7 */
 
extern int xfmsta_(void *cspice_state, doublereal *istate, char *icosys, char *ocosys, char *body, doublereal *ostate, ftnlen icosys_len, ftnlen ocosys_len, ftnlen body_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vequg_ 14 3 7 4 7 */
/*:ref: zzbods2c_ 14 9 4 13 4 12 13 4 12 124 124 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: dpmax_ 7 0 */
/*:ref: cylrec_ 14 4 7 7 7 7 */
/*:ref: drdcyl_ 14 4 7 7 7 7 */
/*:ref: latrec_ 14 4 7 7 7 7 */
/*:ref: drdlat_ 14 4 7 7 7 7 */
/*:ref: sphrec_ 14 4 7 7 7 7 */
/*:ref: drdsph_ 14 4 7 7 7 7 */
/*:ref: georec_ 14 6 7 7 7 7 7 7 */
/*:ref: drdgeo_ 14 6 7 7 7 7 7 7 */
/*:ref: pgrrec_ 14 8 13 7 7 7 7 7 7 124 */
/*:ref: drdpgr_ 14 8 13 7 7 7 7 7 7 124 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vpack_ 14 4 7 7 7 7 */
/*:ref: reccyl_ 14 4 7 7 7 7 */
/*:ref: reclat_ 14 4 7 7 7 7 */
/*:ref: recsph_ 14 4 7 7 7 7 */
/*:ref: recgeo_ 14 6 7 7 7 7 7 7 */
/*:ref: recpgr_ 14 8 13 7 7 7 7 7 7 124 */
/*:ref: dcyldr_ 14 4 7 7 7 7 */
/*:ref: dlatdr_ 14 4 7 7 7 7 */
/*:ref: dsphdr_ 14 4 7 7 7 7 */
/*:ref: dgeodr_ 14 6 7 7 7 7 7 7 */
/*:ref: dpgrdr_ 14 8 13 7 7 7 7 7 7 124 */
 
extern int xposbl_(void *cspice_state, doublereal *bmat, integer *nrow, integer *ncol, integer *bsize, doublereal *btmat);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int xpose_(void *cspice_state, doublereal *m1, doublereal *mout);
 
extern int xposeg_(void *cspice_state, doublereal *matrix, integer *nrow, integer *ncol, doublereal *xposem);
 
extern int xpsgip_(void *cspice_state, integer *nrow, integer *ncol, doublereal *matrix);
 
extern int zzaddlnk_(void *cspice_state, integer *aval, integer *bval, integer *maxa, integer *cellsz, integer *pntrs, integer *ncell, integer *cells);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzascii_(void *cspice_state, char *file, char *line, logical *check, char *termin, ftnlen file_len, ftnlen line_len, ftnlen termin_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzplatfm_ 14 4 13 13 124 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: getlun_ 14 1 4 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern int zzasryel_(void *cspice_state, char *extrem, doublereal *ellips, doublereal *vertex, doublereal *dir, doublereal *angle, doublereal *extpt, ftnlen extrem_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: el2cgv_ 14 4 7 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: vzero_ 12 1 7 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: psv2pl_ 14 4 7 7 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: vprjp_ 14 3 7 7 7 */
/*:ref: vdist_ 7 2 7 7 */
/*:ref: inrypl_ 14 5 7 7 7 4 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: twopi_ 7 0 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vlcom3_ 14 7 7 7 7 7 7 7 7 */
/*:ref: touchd_ 7 1 7 */
/*:ref: swapd_ 14 2 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: vsep_ 7 2 7 7 */
 
extern int zzbodblt_(void *cspice_state, integer *room, char *names, char *nornam, integer *codes, integer *nvals, char *device, char *reqst, ftnlen names_len, ftnlen nornam_len, ftnlen device_len, ftnlen reqst_len);
extern int zzbodget_(void *cspice_state, integer *room, char *names, char *nornam, integer *codes, integer *nvals, ftnlen names_len, ftnlen nornam_len);
extern int zzbodlst_(void *cspice_state, char *device, char *reqst, ftnlen device_len, ftnlen reqst_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzidmap_ 14 3 4 13 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: movec_ 14 5 13 4 13 124 124 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: wrline_ 14 4 13 13 124 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: orderi_ 14 3 4 4 4 */
/*:ref: orderc_ 14 4 13 4 4 124 */
 
extern integer zzbodbry_(void *cspice_state, integer *body);
 
extern int zzbodini_(void *cspice_state, char *names, char *nornam, integer *codes, integer *nvals, integer *maxval, integer *bnmlst, integer *bnmpol, char *bnmnms, integer *bnmidx, integer *bidlst, integer *bidpol, integer *bidids, integer *bididx, ftnlen names_len, ftnlen nornam_len, ftnlen bnmnms_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzhsiini_ 14 3 4 4 4 */
/*:ref: zzhscini_ 14 3 4 4 4 */
/*:ref: zzhscadd_ 14 8 4 4 13 13 4 12 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: zzhsiadd_ 14 6 4 4 4 4 4 12 */
 
extern int zzbodker_(void *cspice_state, char *names, char *nornam, integer *codes, integer *nvals, logical *extker, integer *bnmlst, integer *bnmpol, char *bnmnms, integer *bnmidx, integer *bidlst, integer *bidpol, integer *bidids, integer *bididx, ftnlen names_len, ftnlen nornam_len, ftnlen bnmnms_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: gcpool_ 14 8 13 4 4 4 13 12 124 124 */
/*:ref: gipool_ 14 7 13 4 4 4 4 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: zzbodini_ 14 16 13 13 4 4 4 4 4 13 4 4 4 4 4 124 124 124 */
 
extern int zzbods2c_(void *cspice_state, integer *usrctr, char *savnam, integer *savcde, logical *savfnd, char *name__, integer *code, logical *found, ftnlen savnam_len, ftnlen name_len);
/*:ref: return_ 12 0 */
/*:ref: zzbctrck_ 14 2 4 12 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: bods2c_ 14 4 13 4 12 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzbodtrn_(void *cspice_state, char *name__, integer *code, logical *found, integer *usrctr, logical *update, ftnlen name_len);
extern int zzbodn2c_(void *cspice_state, char *name__, integer *code, logical *found, ftnlen name_len);
extern int zzbodc2n_(void *cspice_state, integer *code, char *name__, logical *found, ftnlen name_len);
extern int zzboddef_(void *cspice_state, char *name__, integer *code, ftnlen name_len);
extern int zzbodkik_(void *cspice_state);
extern int zzbodrst_(void *cspice_state);
extern int zzbctrck_(void *cspice_state, integer *usrctr, logical *update);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzctrsin_ 14 1 4 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzbodget_ 14 7 4 13 13 4 4 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: zzbodini_ 14 16 13 13 4 4 4 4 4 13 4 4 4 4 4 124 124 124 */
/*:ref: swpool_ 14 5 13 4 13 124 124 */
/*:ref: zzcvpool_ 14 4 13 4 12 124 */
/*:ref: zzctrinc_ 14 1 4 */
/*:ref: zzbodker_ 14 16 13 13 4 4 12 4 4 13 4 4 4 4 4 124 124 124 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: zzhscchk_ 14 7 4 4 13 13 4 124 124 */
/*:ref: zzhsichk_ 14 5 4 4 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: zzctrchk_ 14 3 4 4 12 */
 
extern int zzbodvcd_(void *cspice_state, integer *bodyid, char *item, integer *maxn, integer *varctr, integer *n, doublereal *values, ftnlen item_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzpctrck_ 14 2 4 12 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzbquad_(void *cspice_state, doublereal *a, doublereal *b, doublereal *c__, doublereal *ub, integer *n, integer *nx, doublereal *r1, doublereal *r2);
/*:ref: return_ 12 0 */
/*:ref: dpmax_ 7 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: touchd_ 7 1 7 */
 
extern int zzchrlat_(void *cspice_state, doublereal *midlat, doublereal *dlon, doublereal *eptlat);
/*:ref: return_ 12 0 */
/*:ref: pi_ 7 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: halfpi_ 7 0 */
/*:ref: brcktd_ 7 3 7 7 7 */
 
extern int zzck4d2i_(void *cspice_state, doublereal *dpcoef, integer *nsets, doublereal *parcod, integer *i__);
 
extern int zzck4i2d_(void *cspice_state, integer *i__, integer *nsets, doublereal *parcod, doublereal *dpcoef);
 
extern int zzckcv01_(void *cspice_state, integer *handle, integer *arrbeg, integer *arrend, integer *sclkid, doublereal *tol, char *timsys, doublereal *schedl, ftnlen timsys_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sct2e_ 14 3 4 7 7 */
/*:ref: wninsd_ 14 3 7 7 7 */
 
extern int zzckcv02_(void *cspice_state, integer *handle, integer *arrbeg, integer *arrend, integer *sclkid, doublereal *tol, char *timsys, doublereal *schedl, ftnlen timsys_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: sct2e_ 14 3 4 7 7 */
/*:ref: wninsd_ 14 3 7 7 7 */
 
extern int zzckcv03_(void *cspice_state, integer *handle, integer *arrbeg, integer *arrend, integer *sclkid, doublereal *tol, char *timsys, doublereal *schedl, ftnlen timsys_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sct2e_ 14 3 4 7 7 */
/*:ref: wninsd_ 14 3 7 7 7 */
 
extern int zzckcv04_(void *cspice_state, integer *handle, integer *arrbeg, integer *arrend, integer *sclkid, doublereal *tol, char *timsys, doublereal *schedl, ftnlen timsys_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: intmax_ 4 0 */
/*:ref: dafps_ 14 5 4 4 7 4 7 */
/*:ref: cknr04_ 14 3 4 7 4 */
/*:ref: sgfpkt_ 14 6 4 7 4 4 7 4 */
/*:ref: sct2e_ 14 3 4 7 7 */
/*:ref: wninsd_ 14 3 7 7 7 */
 
extern int zzckcv05_(void *cspice_state, integer *handle, integer *arrbeg, integer *arrend, integer *sclkid, doublereal *dc, doublereal *tol, char *timsys, doublereal *schedl, ftnlen timsys_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: errint_ 14 3 13 7 124 */
/*:ref: sct2e_ 14 3 4 7 7 */
/*:ref: wninsd_ 14 3 7 7 7 */
 
extern int zzckcv06_(void *cspice_state, integer *handle, integer *arrbeg, integer *arrend, integer *sclkid, doublereal *dc, doublereal *tol, char *timsys, doublereal *schedl, ftnlen timsys_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
/*:ref: failed_ 12 0 */
/*:ref: sct2e_ 14 3 4 7 7 */
/*:ref: wninsd_ 14 3 7 7 7 */
 
extern int zzckspk_(void *cspice_state, integer *handle, char *ckspk, ftnlen ckspk_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dafhsf_ 14 3 4 4 4 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dafbfs_ 14 1 4 */
/*:ref: daffna_ 14 1 12 */
/*:ref: failed_ 12 0 */
/*:ref: dafgs_ 14 1 7 */
/*:ref: dafus_ 14 5 7 4 4 7 4 */
/*:ref: zzsizeok_ 14 6 4 4 4 4 12 4 */
/*:ref: dafgda_ 14 4 4 4 4 7 */
 
extern int zzcln_(void *cspice_state, integer *lookat, integer *nameat, integer *namlst, integer *datlst, integer *nmpool, integer *chpool, integer *dppool);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: lnkfsl_ 14 3 4 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzcnquad_(void *cspice_state, doublereal *a, doublereal *b, doublereal *c__, doublereal *ub, integer *n, doublereal *r1, doublereal *r2);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dpmax_ 7 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: touchd_ 7 1 7 */
/*:ref: zzbquad_ 14 8 7 7 7 7 4 4 7 7 */
 
extern int zzcorepc_(void *cspice_state, char *abcorr, doublereal *et, doublereal *lt, doublereal *etcorr, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzprscor_ 14 3 13 12 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzcorsxf_(void *cspice_state, logical *xmit, doublereal *dlt, doublereal *xform, doublereal *corxfm);
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: vsclip_ 14 2 7 7 */
 
extern int zzcputim_(void *cspice_state, doublereal *tvec);
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzctr_(void *cspice_state, integer *newctr, integer *oldctr, logical *update);
extern int zzctruin_(void *cspice_state, integer *oldctr);
extern int zzctrsin_(void *cspice_state, integer *oldctr);
extern int zzctrinc_(void *cspice_state, integer *oldctr);
extern int zzctrchk_(void *cspice_state, integer *newctr, integer *oldctr, logical *update);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: intmax_ 4 0 */
/*:ref: intmin_ 4 0 */
 
extern int zzcvpool_(void *cspice_state, char *agent, integer *usrctr, logical *update, ftnlen agent_len);
/*:ref: return_ 12 0 */
/*:ref: zzpctrck_ 14 2 4 12 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cvpool_ 14 3 13 12 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzcvstat_(void *cspice_state, doublereal *et, char *ref, integer *center, doublereal *state, ftnlen ref_len);
extern int zzcvxsta_(void *cspice_state, doublereal *et, char *ref, integer *center, doublereal *state, ftnlen ref_len);
extern int zzcvssta_(void *cspice_state, doublereal *state, integer *center, doublereal *et, char *ref, ftnlen ref_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: return_ 12 0 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: sxform_ 14 6 13 13 7 7 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: mxvg_ 14 5 7 7 4 4 7 */
/*:ref: moved_ 14 3 7 4 7 */
 
extern int zzcxbrut_(void *cspice_state, doublereal *apex, doublereal *axis, doublereal *angle, doublereal *endpt1, doublereal *endpt2, doublereal *xpt, logical *isbrck);
/*:ref: return_ 12 0 */
/*:ref: vzero_ 12 1 7 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: halfpi_ 7 0 */
/*:ref: pi_ 7 0 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vhatip_ 14 1 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
 
extern int zzdafgdr_(void *cspice_state, integer *handle, integer *recno, doublereal *dprec, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzddhgsd_ 14 5 13 4 13 124 124 */
/*:ref: zzplatfm_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzddhnfo_ 14 7 4 13 4 4 4 12 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: zzxlated_ 14 5 4 13 4 7 124 */
/*:ref: moved_ 14 3 7 4 7 */
 
extern int zzdafgfr_(void *cspice_state, integer *handle, char *idword, integer *nd, integer *ni, char *ifname, integer *fward, integer *bward, integer *free, logical *found, ftnlen idword_len, ftnlen ifname_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzddhgsd_ 14 5 13 4 13 124 124 */
/*:ref: zzplatfm_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzddhnfo_ 14 7 4 13 4 4 4 12 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: zzxlatei_ 14 5 4 13 4 4 124 */
 
extern int zzdafgsr_(void *cspice_state, integer *handle, integer *recno, integer *nd, integer *ni, doublereal *dprec, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzddhgsd_ 14 5 13 4 13 124 124 */
/*:ref: zzplatfm_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzddhnfo_ 14 7 4 13 4 4 4 12 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: zzxlated_ 14 5 4 13 4 7 124 */
/*:ref: zzxlatei_ 14 5 4 13 4 4 124 */
/*:ref: moved_ 14 3 7 4 7 */
 
extern int zzdafnfr_(void *cspice_state, integer *lun, char *idword, integer *nd, integer *ni, char *ifname, integer *fward, integer *bward, integer *free, char *format, ftnlen idword_len, ftnlen ifname_len, ftnlen format_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzftpstr_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzdasgrd_(void *cspice_state, integer *handle, integer *recno, doublereal *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzddhnfc_ 14 1 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: zzddhnfo_ 14 7 4 13 4 4 4 12 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: zzxlated_ 14 5 4 13 4 7 124 */
 
extern int zzdasgri_(void *cspice_state, integer *handle, integer *recno, integer *record);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzddhnfc_ 14 1 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: zzddhnfo_ 14 7 4 13 4 4 4 12 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: zzxlatei_ 14 5 4 13 4 4 124 */
 
extern int zzdasnfr_(void *cspice_state, integer *lun, char *idword, char *ifname, integer *nresvr, integer *nresvc, integer *ncomr, integer *ncomc, char *format, ftnlen idword_len, ftnlen ifname_len, ftnlen format_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzftpstr_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzdasrfr_(void *cspice_state, integer *handle, char *idword, char *ifname, integer *nresvr, integer *nresvc, integer *ncomr, integer *ncomc, ftnlen idword_len, ftnlen ifname_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzddhnfc_ 14 1 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzddhhlu_ 14 5 4 13 12 4 124 */
/*:ref: zzddhppf_ 14 3 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzxlatei_ 14 5 4 13 4 4 124 */
 
extern integer zzddhclu_(void *cspice_state, logical *utlck, integer *nut);
 
extern int zzddhf2h_(void *cspice_state, char *fname, integer *ftabs, integer *ftamh, integer *ftarc, integer *ftbff, integer *fthan, char *ftnam, integer *ftrtm, doublereal *ftmnm, integer *nft, integer *utcst, integer *uthan, logical *utlck, integer *utlun, integer *nut, logical *exists, logical *opened, integer *handle, logical *found, doublereal *mnm, ftnlen fname_len, ftnlen ftnam_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: zzddhgtu_ 14 6 4 4 12 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: zzddhrmu_ 14 7 4 4 4 4 12 4 4 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: zzddhmnm_ 7 1 4 */
 
extern int zzddhgsd_(void *cspice_state, char *class__, integer *id, char *label, ftnlen class_len, ftnlen label_len);
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
 
extern int zzddhgtu_(void *cspice_state, integer *utcst, integer *uthan, logical *utlck, integer *utlun, integer *nut, integer *uindex);
/*:ref: return_ 12 0 */
/*:ref: getlun_ 14 1 4 */
/*:ref: failed_ 12 0 */
/*:ref: orderi_ 14 3 4 4 4 */
/*:ref: frelun_ 14 1 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzddhini_(void *cspice_state, integer *natbff, integer *supbff, integer *numsup, char *stramh, char *strarc, char *strbff, ftnlen stramh_len, ftnlen strarc_len, ftnlen strbff_len);
/*:ref: return_ 12 0 */
/*:ref: zzddhgsd_ 14 5 13 4 13 124 124 */
/*:ref: zzplatfm_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: nextwd_ 14 6 13 13 13 124 124 124 */
 
extern int zzddhivf_(void *cspice_state, char *nsum, integer *bff, logical *found, ftnlen nsum_len);
 
extern int zzddhman_(void *cspice_state, logical *lock, char *arch, char *fname, char *method, integer *handle, integer *unit, integer *intamh, integer *intarc, integer *intbff, logical *native, logical *found, logical *kill, ftnlen arch_len, ftnlen fname_len, ftnlen method_len);
extern int zzddhopn_(void *cspice_state, char *fname, char *method, char *arch, integer *handle, ftnlen fname_len, ftnlen method_len, ftnlen arch_len);
extern int zzddhcls_(void *cspice_state, integer *handle, char *arch, logical *kill, ftnlen arch_len);
extern int zzddhhlu_(void *cspice_state, integer *handle, char *arch, logical *lock, integer *unit, ftnlen arch_len);
extern int zzddhunl_(void *cspice_state, integer *handle, char *arch, ftnlen arch_len);
extern int zzddhnfo_(void *cspice_state, integer *handle, char *fname, integer *intarc, integer *intbff, integer *intamh, logical *found, ftnlen fname_len);
extern int zzddhisn_(void *cspice_state, integer *handle, logical *native, logical *found);
extern int zzddhfnh_(void *cspice_state, char *fname, integer *handle, logical *found, ftnlen fname_len);
extern int zzddhluh_(void *cspice_state, integer *unit, integer *handle, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzddhini_ 14 9 4 4 4 13 13 13 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: zzpltchk_ 14 1 12 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: zzddhclu_ 4 2 12 4 */
/*:ref: zzddhf2h_ 14 22 13 4 4 4 4 4 13 4 7 4 4 4 12 4 4 12 12 4 12 7 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: bsrchi_ 4 3 4 4 4 */
/*:ref: zzddhrcm_ 14 3 4 4 4 */
/*:ref: zzddhgtu_ 14 6 4 4 12 4 4 4 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: zzddhppf_ 14 3 4 4 4 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: zzddhrmu_ 14 7 4 4 4 4 12 4 4 */
/*:ref: frelun_ 14 1 4 */
 
extern doublereal zzddhmnm_(void *cspice_state, integer *unit);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzddhini_ 14 9 4 4 4 13 13 13 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: idw2at_ 14 6 13 13 13 124 124 124 */
/*:ref: zzddhppf_ 14 3 4 4 4 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: zzxlatei_ 14 5 4 13 4 4 124 */
 
extern int zzddhnfc_(void *cspice_state, integer *natbff);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzddhgsd_ 14 5 13 4 13 124 124 */
/*:ref: zzplatfm_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzddhppf_(void *cspice_state, integer *unit, integer *arch, integer *bff);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzddhgsd_ 14 5 13 4 13 124 124 */
/*:ref: zzftpstr_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errfnm_ 14 3 13 4 124 */
/*:ref: idw2at_ 14 6 13 13 13 124 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: zzftpchk_ 14 3 13 12 124 */
/*:ref: pos_ 4 5 13 13 4 124 124 */
/*:ref: zzplatfm_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: zzddhivf_ 14 4 13 4 12 124 */
 
extern int zzddhrcm_(void *cspice_state, integer *nut, integer *utcst, integer *reqcnt);
/*:ref: intmax_ 4 0 */
 
extern int zzddhrmu_(void *cspice_state, integer *uindex, integer *nft, integer *utcst, integer *uthan, logical *utlck, integer *utlun, integer *nut);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: reslun_ 14 1 4 */
 
extern doublereal zzdiv_(void *cspice_state, doublereal *numr, doublereal *denom);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dpmax_ 7 0 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzdscm_(void *cspice_state, doublereal *epoch, doublereal *eccp, doublereal *argpp, doublereal *tc, doublereal *inclp, doublereal *nodep, doublereal *np, doublereal *snodm, doublereal *cnodm, doublereal *sinim, doublereal *cosim, doublereal *sinomm, doublereal *cosomm, doublereal *day, doublereal *e3, doublereal *ee2, doublereal *eccm, doublereal *emsq, doublereal *gam, doublereal *peo, doublereal *pgho, doublereal *pho, doublereal *pinco, doublereal *plo, doublereal *rtemsq, doublereal *se2, doublereal *se3, doublereal *sgh2, doublereal *sgh3, doublereal *sgh4, doublereal *sh2, doublereal *sh3, doublereal *si2, doublereal *si3, doublereal *sl2, doublereal *sl3, doublereal *sl4, doublereal *s1, doublereal *s2, doublereal *s3, doublereal *s4, doublereal *s5, doublereal *s6, doublereal *s7, doublereal *ss1, doublereal *ss2, doublereal *ss3, doublereal *ss4, doublereal *ss5, doublereal *ss6, doublereal *ss7, doublereal *sz1, doublereal *sz2, doublereal *sz3, doublereal *sz11, doublereal *sz12, doublereal *sz13, doublereal *sz21, doublereal *sz22, doublereal *sz23, doublereal *sz31, doublereal *sz32, doublereal *sz33, doublereal *xgh2, doublereal *xgh3, doublereal *xgh4, doublereal *xh2, doublereal *xh3, doublereal *xi2, doublereal *xi3, doublereal *xl2, doublereal *xl3, doublereal *xl4, doublereal *xn, doublereal *z1, doublereal *z2, doublereal *z3, doublereal *z11, doublereal *z12, doublereal *z13, doublereal *z21, doublereal *z22, doublereal *z23, doublereal *z31, doublereal *z32, doublereal *z33, doublereal *zmol, doublereal *zmos);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: twopi_ 7 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzdsin_(void *cspice_state, doublereal *geophs, doublereal *cosim, doublereal *emsq, doublereal *argpo, doublereal *s1, doublereal *s2, doublereal *s3, doublereal *s4, doublereal *s5, doublereal *sinim, doublereal *ss1, doublereal *ss2, doublereal *ss3, doublereal *ss4, doublereal *ss5, doublereal *sz1, doublereal *sz3, doublereal *sz11, doublereal *sz13, doublereal *sz21, doublereal *sz23, doublereal *sz31, doublereal *sz33, doublereal *t, doublereal *tc, doublereal *gsto, doublereal *mo, doublereal *mdot, doublereal *no, doublereal *nodeo, doublereal *nodedot, doublereal *xpidot, doublereal *z1, doublereal *z3, doublereal *z11, doublereal *z13, doublereal *z21, doublereal *z23, doublereal *z31, doublereal *z33, doublereal *ecco, doublereal *eccsq, doublereal *eccm, doublereal *argpm, doublereal *inclm, doublereal *mm, doublereal *xn, doublereal *nodem, integer *irez, doublereal *atime, doublereal *d2201, doublereal *d2211, doublereal *d3210, doublereal *d3222, doublereal *d4410, doublereal *d4422, doublereal *d5220, doublereal *d5232, doublereal *d5421, doublereal *d5433, doublereal *dedt, doublereal *didt, doublereal *dmdt, doublereal *dndt, doublereal *dnodt, doublereal *domdt, doublereal *del1, doublereal *del2, doublereal *del3, doublereal *xfact, doublereal *xlamo, doublereal *xli, doublereal *xni);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: pi_ 7 0 */
/*:ref: twopi_ 7 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzdskbbl_(void *cspice_state, integer *bodyid);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzdskchk_ 14 2 4 12 */
/*:ref: zzdskbss_ 14 1 4 */
/*:ref: zzdsksns_ 14 5 200 4 4 7 12 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzdskbsr_(void *cspice_state, char *fname, integer *bodyid, integer *handle, L_fp cmpfun, integer *usrctr, logical *update, integer *dladsc, doublereal *dskdsc, logical *found, ftnlen fname_len);
extern int zzdsklsf_(void *cspice_state, char *fname, integer *handle, ftnlen fname_len);
extern int zzdskusf_(void *cspice_state, integer *handle);
extern int zzdskbss_(void *cspice_state, integer *bodyid);
extern int zzdsksns_(void *cspice_state, L_fp cmpfun, integer *handle, integer *dladsc, doublereal *dskdsc, logical *found);
extern int zzdskchk_(void *cspice_state, integer *usrctr, logical *update);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzctrsin_ 14 1 4 */
/*:ref: zzctrinc_ 14 1 4 */
/*:ref: lnkini_ 14 2 4 4 */
/*:ref: dasopr_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: dascls_ 14 1 4 */
/*:ref: lnknxt_ 4 2 4 4 */
/*:ref: lnkfsl_ 14 3 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: intmax_ 4 0 */
/*:ref: lnkprv_ 4 2 4 4 */
/*:ref: dlabfs_ 14 3 4 4 12 */
/*:ref: dlafns_ 14 4 4 4 4 12 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: dskgd_ 14 3 4 4 7 */
/*:ref: dlabbs_ 14 3 4 4 12 */
/*:ref: dlafps_ 14 4 4 4 4 12 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: lnknfn_ 4 1 4 */
/*:ref: lnkan_ 14 2 4 4 */
/*:ref: lnkilb_ 14 3 4 4 4 */
/*:ref: lnkila_ 14 3 4 4 4 */
/*:ref: zzctrchk_ 14 3 4 4 12 */
 
extern int zzdskbun_(void *cspice_state, integer *bodyid, integer *nsurf, integer *srflst, doublereal *et, integer *fixfid, integer *nseg, integer *hanbuf, integer *dlabuf, doublereal *dskbuf, doublereal *offbuf, doublereal *ctrbuf, doublereal *radbuf, doublereal *point, doublereal *normal);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dskgtl_ 14 2 4 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: refchg_ 14 4 4 4 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vdist_ 7 2 7 7 */
/*:ref: zzinlat_ 14 5 7 7 7 4 12 */
/*:ref: zzinrec_ 14 5 7 7 7 4 12 */
/*:ref: zzinpdt_ 14 6 7 7 7 7 4 12 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: zzptpl02_ 14 8 4 4 7 7 4 4 7 12 */
/*:ref: pltnrm_ 14 4 7 7 7 7 */
/*:ref: vhatip_ 14 1 7 */
/*:ref: mtxv_ 14 3 7 7 7 */
 
extern int zzdskbux_(void *cspice_state, integer *bodyid, integer *nsurf, integer *srflst, doublereal *et, integer *fixfid, integer *nseg, integer *hanbuf, integer *dlabuf, doublereal *dskbuf, doublereal *offbuf, doublereal *ctrbuf, doublereal *radbuf, doublereal *vertex, doublereal *raydir, doublereal *xpt, integer *segidx, doublereal *dc, integer *ic, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dskgtl_ 14 2 4 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: zzdsksph_ 14 5 4 4 4 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: surfpt_ 14 7 7 7 7 7 7 7 12 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: refchg_ 14 4 4 4 7 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: nplnpt_ 14 5 7 7 7 7 7 */
/*:ref: zzrytelt_ 14 6 7 7 7 7 4 7 */
/*:ref: vdist_ 7 2 7 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: orderd_ 14 3 7 4 4 */
/*:ref: zzdsksgx_ 14 10 4 4 4 7 7 7 7 7 4 12 */
/*:ref: vzero_ 12 1 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: mtxv_ 14 3 7 7 7 */
 
extern int zzdsksba_(void *cspice_state, integer *bodyid, integer *maxbod, integer *stsize, integer *btbody, integer *btnbod, integer *btsegp, integer *btstsz, integer *sthan, doublereal *stdscr, integer *stdlad, integer *stfree, doublereal *stoff, doublereal *stctr, doublereal *strad);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzdskbbl_ 14 1 4 */
/*:ref: failed_ 12 0 */
/*:ref: zzdsksbd_ 12 1 4 */
/*:ref: zzdskbss_ 14 1 4 */
/*:ref: zzdsksns_ 14 5 200 4 4 7 12 */
/*:ref: zzdsksbr_ 14 14 4 4 4 4 4 4 4 4 7 4 4 7 7 7 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: zzsegbox_ 14 3 7 7 7 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: frmnam_ 14 3 4 13 124 */
/*:ref: spkgps_ 14 7 4 7 13 4 7 7 124 */
 
extern int zzdsksbf_(void *cspice_state, integer *bodyid, integer *nsurf, integer *srflst, doublereal *et, integer *fixfid, doublereal *vertex, doublereal *raydir, doublereal *point, doublereal *xpt, integer *handle, integer *dladsc, doublereal *dskdsc, doublereal *dc, integer *ic, logical *found, doublereal *normal);
extern int zzsbfxr_(void *cspice_state, integer *bodyid, integer *nsurf, integer *srflst, doublereal *et, integer *fixfid, doublereal *vertex, doublereal *raydir, doublereal *xpt, logical *found);
extern int zzsbfxri_(void *cspice_state, integer *bodyid, integer *nsurf, integer *srflst, doublereal *et, integer *fixfid, doublereal *vertex, doublereal *raydir, doublereal *xpt, integer *handle, integer *dladsc, doublereal *dskdsc, doublereal *dc, integer *ic, logical *found);
extern int zzsbfnrm_(void *cspice_state, integer *bodyid, integer *nsurf, integer *srflst, doublereal *et, integer *fixfid, doublereal *point, doublereal *normal);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzdskchk_ 14 2 4 12 */
/*:ref: zzdskbbl_ 14 1 4 */
/*:ref: zzdsksbi_ 14 13 4 4 4 4 4 4 4 7 4 4 7 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: zzdsksba_ 14 14 4 4 4 4 4 4 4 4 7 4 4 7 7 7 */
/*:ref: zzdskbux_ 14 19 4 4 4 7 4 4 4 4 7 7 7 7 7 7 7 4 7 4 12 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: zzdskbun_ 14 14 4 4 4 7 4 4 4 4 7 7 7 7 7 7 */
 
extern int zzdsksbi_(void *cspice_state, integer *maxbod, integer *stsize, integer *btbody, integer *btnbod, integer *btsegp, integer *btstsz, integer *sthan, doublereal *stdscr, integer *stdlad, integer *stfree, doublereal *stoff, doublereal *stctr, doublereal *strad);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzdsksbr_(void *cspice_state, integer *needed, integer *maxbod, integer *stsize, integer *btbody, integer *btnbod, integer *btsegp, integer *btstsz, integer *sthan, doublereal *stdscr, integer *stdlad, integer *stfree, doublereal *stoff, doublereal *stctr, doublereal *strad);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: movei_ 14 3 4 4 4 */
 
extern logical zzdsksel_(void *cspice_state, integer *surfid, integer *nsurf, integer *srflst, integer *bodyid, integer *dclass, integer *corsys, doublereal *corpar, doublereal *cor1, doublereal *cor2, integer *framid, doublereal *pos, doublereal *et, integer *handle, integer *dladsc, doublereal *dskdsc);
extern logical zzdsksbd_(void *cspice_state, integer *bodyid);
extern logical zzdskbdc_(void *cspice_state, integer *handle, integer *dladsc, doublereal *dskdsc);
extern logical zzdsknot_(void *cspice_state, integer *handle, integer *dladsc, doublereal *dskdsc);
extern logical zzdsksit_(void *cspice_state, integer *bodyid, integer *nsurf, integer *srflst, doublereal *et);
extern logical zzdskcit_(void *cspice_state, integer *handle, integer *dladsc, doublereal *dskdsc);
extern logical zzdskusc_(void *cspice_state, integer *bodyid, doublereal *et, doublereal *cor1, doublereal *cor2);
extern logical zzdskumc_(void *cspice_state, integer *handle, integer *dladsc, doublereal *dskdsc);
extern logical zzdskmsc_(void *cspice_state, integer *bodyid, integer *surfid, integer *framid, integer *corsys, doublereal *corpar, doublereal *et, doublereal *cor1, doublereal *cor2);
extern logical zzdskmmc_(void *cspice_state, integer *handle, integer *dladsc, doublereal *dskdsc);
extern logical zzdsksrc_(void *cspice_state, integer *surfid, integer *bodyid, integer *dclass, doublereal *et, integer *framid, doublereal *pos);
extern logical zzdskmrc_(void *cspice_state, integer *handle, integer *dladsc, doublereal *dskdsc);
/*:ref: touchi_ 4 1 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: shelli_ 14 2 4 4 */
/*:ref: bsrchi_ 4 3 4 4 4 */
/*:ref: twopi_ 7 0 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: refchg_ 14 4 4 4 7 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: reclat_ 14 4 7 7 7 7 */
/*:ref: recgeo_ 14 6 7 7 7 7 7 7 */
 
extern doublereal zzdsksgr_(void *cspice_state, doublereal *dskdsc);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern int zzdsksgx_(void *cspice_state, integer *handle, integer *dladsc, integer *dtype, doublereal *et, doublereal *vertex, doublereal *raydir, doublereal *xpt, doublereal *dc, integer *ic, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: touchd_ 7 1 7 */
/*:ref: dskx02_ 14 7 4 4 7 7 4 7 12 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzdsksph_(void *cspice_state, integer *bodyid, integer *nsurf, integer *srflst, doublereal *minrad, doublereal *maxrad);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzdskchk_ 14 2 4 12 */
/*:ref: dpmax_ 7 0 */
/*:ref: zzdskbbl_ 14 1 4 */
/*:ref: failed_ 12 0 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: zzdskbss_ 14 1 4 */
/*:ref: zzdsksbd_ 14 1 4 */
/*:ref: zzdsksns_ 14 5 200 4 4 7 12 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: frmnam_ 14 3 4 13 124 */
/*:ref: spkgps_ 14 7 4 7 13 4 7 7 124 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: zzrecbox_ 14 6 7 7 7 7 7 7 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: movei_ 14 3 4 4 4 */
 
extern int zzdspc_(void *cspice_state, integer *irez, doublereal *d2201, doublereal *d2211, doublereal *d3210, doublereal *d3222, doublereal *d4410, doublereal *d4422, doublereal *d5220, doublereal *d5232, doublereal *d5421, doublereal *d5433, doublereal *dedt, doublereal *del1, doublereal *del2, doublereal *del3, doublereal *didt, doublereal *dmdt, doublereal *dnodt, doublereal *domdt, doublereal *argpo, doublereal *argpdot, doublereal *t, doublereal *tc, doublereal *gsto, doublereal *xfact, doublereal *xlamo, doublereal *no, doublereal *atime, doublereal *eccm, doublereal *argpm, doublereal *inclm, doublereal *xli, doublereal *mm, doublereal *xni, doublereal *nodem, doublereal *dndt, doublereal *xn);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: twopi_ 7 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzdspr_(void *cspice_state, integer *opmode, doublereal *e3, doublereal *ee2, doublereal *peo, doublereal *pgho, doublereal *pho, doublereal *pinco, doublereal *plo, doublereal *se2, doublereal *se3, doublereal *sgh2, doublereal *sgh3, doublereal *sgh4, doublereal *sh2, doublereal *sh3, doublereal *si2, doublereal *si3, doublereal *sl2, doublereal *sl3, doublereal *sl4, doublereal *t, doublereal *xgh2, doublereal *xgh3, doublereal *xgh4, doublereal *xh2, doublereal *xh3, doublereal *xi2, doublereal *xi3, doublereal *xl2, doublereal *xl3, doublereal *xl4, doublereal *zmol, doublereal *zmos, doublereal *inclo, logical *doinit, doublereal *eccp, doublereal *inclp, doublereal *nodep, doublereal *argpp, doublereal *mp);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: twopi_ 7 0 */
/*:ref: pi_ 7 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzdynbid_(void *cspice_state, char *frname, integer *frcode, char *item, integer *idcode, ftnlen frname_len, ftnlen item_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: gcpool_ 14 8 13 4 4 4 13 12 124 124 */
/*:ref: bods2c_ 14 4 13 4 12 124 */
/*:ref: gipool_ 14 7 13 4 4 4 4 12 124 */
 
extern int zzdynfid_(void *cspice_state, char *frname, integer *frcode, char *item, integer *idcode, ftnlen frname_len, ftnlen item_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: gcpool_ 14 8 13 4 4 4 13 12 124 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: beint_ 12 2 13 124 */
/*:ref: prsint_ 14 3 13 4 124 */
/*:ref: gipool_ 14 7 13 4 4 4 4 12 124 */
 
extern int zzdynfr0_(void *cspice_state, integer *infram, integer *center, doublereal *et, doublereal *xform, integer *basfrm);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: bodn2c_ 14 4 13 4 12 124 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: frmnam_ 14 3 4 13 124 */
/*:ref: zzdynfid_ 14 6 13 4 13 4 124 124 */
/*:ref: zzdynvac_ 14 9 13 4 13 4 4 13 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: zzdynoad_ 14 9 13 4 13 4 4 7 12 124 124 */
/*:ref: zzdynoac_ 14 10 13 4 13 4 4 13 12 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: bodc2n_ 14 4 4 13 12 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: zzeprc76_ 14 2 7 7 */
/*:ref: invstm_ 14 2 7 7 */
/*:ref: zzenut80_ 14 2 7 7 */
/*:ref: mxmg_ 14 6 7 7 4 4 4 7 */
/*:ref: zzmobliq_ 14 3 7 7 7 */
/*:ref: eul2xf_ 14 5 7 4 4 4 7 */
/*:ref: zzfrmch1_ 14 4 4 4 7 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzdynbid_ 14 6 13 4 13 4 124 124 */
/*:ref: zzspkez1_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: vpack_ 14 4 7 7 7 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: qderiv_ 14 5 4 7 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: zzprscor_ 14 3 13 12 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: zzspkzp1_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: zzcorepc_ 14 5 13 7 7 7 124 */
/*:ref: mxvg_ 14 5 7 7 4 4 7 */
/*:ref: cidfrm_ 14 5 4 4 13 12 124 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: vminug_ 14 3 7 4 7 */
/*:ref: dnearp_ 14 7 7 7 7 7 7 7 12 */
/*:ref: vsubg_ 14 4 7 7 4 7 */
/*:ref: zzspksb1_ 14 5 4 7 13 7 124 */
/*:ref: zzdynvad_ 14 8 13 4 13 4 4 7 124 124 */
/*:ref: convrt_ 14 6 7 13 13 7 124 124 */
/*:ref: latrec_ 14 4 7 7 7 7 */
/*:ref: stlabx_ 14 3 7 7 7 */
/*:ref: stelab_ 14 3 7 7 7 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: zztwovxf_ 14 5 7 4 7 4 7 */
/*:ref: zzdynvai_ 14 8 13 4 13 4 4 4 124 124 */
/*:ref: polyds_ 14 5 7 4 4 7 7 */
 
extern int zzdynfrm_(void *cspice_state, integer *infram, integer *center, doublereal *et, doublereal *xform, integer *basfrm);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: bodn2c_ 14 4 13 4 12 124 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: frmnam_ 14 3 4 13 124 */
/*:ref: zzdynfid_ 14 6 13 4 13 4 124 124 */
/*:ref: zzdynvac_ 14 9 13 4 13 4 4 13 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: zzdynoad_ 14 9 13 4 13 4 4 7 12 124 124 */
/*:ref: zzdynoac_ 14 10 13 4 13 4 4 13 12 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: bodc2n_ 14 4 4 13 12 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: zzeprc76_ 14 2 7 7 */
/*:ref: invstm_ 14 2 7 7 */
/*:ref: zzenut80_ 14 2 7 7 */
/*:ref: mxmg_ 14 6 7 7 4 4 4 7 */
/*:ref: zzmobliq_ 14 3 7 7 7 */
/*:ref: eul2xf_ 14 5 7 4 4 4 7 */
/*:ref: zzfrmch0_ 14 4 4 4 7 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzdynbid_ 14 6 13 4 13 4 124 124 */
/*:ref: zzspkez0_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: vpack_ 14 4 7 7 7 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: qderiv_ 14 5 4 7 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: zzprscor_ 14 3 13 12 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: zzspkzp0_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: zzcorepc_ 14 5 13 7 7 7 124 */
/*:ref: mxvg_ 14 5 7 7 4 4 7 */
/*:ref: cidfrm_ 14 5 4 4 13 12 124 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: vminug_ 14 3 7 4 7 */
/*:ref: dnearp_ 14 7 7 7 7 7 7 7 12 */
/*:ref: vsubg_ 14 4 7 7 4 7 */
/*:ref: zzspksb0_ 14 5 4 7 13 7 124 */
/*:ref: zzdynvad_ 14 8 13 4 13 4 4 7 124 124 */
/*:ref: convrt_ 14 6 7 13 13 7 124 124 */
/*:ref: latrec_ 14 4 7 7 7 7 */
/*:ref: stlabx_ 14 3 7 7 7 */
/*:ref: stelab_ 14 3 7 7 7 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: zztwovxf_ 14 5 7 4 7 4 7 */
/*:ref: zzdynvai_ 14 8 13 4 13 4 4 4 124 124 */
/*:ref: polyds_ 14 5 7 4 4 7 7 */
 
extern int zzdynoac_(void *cspice_state, char *frname, integer *frcode, char *item, integer *maxn, integer *n, char *values, logical *found, ftnlen frname_len, ftnlen item_len, ftnlen values_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: gcpool_ 14 8 13 4 4 4 13 12 124 124 */
 
extern int zzdynoad_(void *cspice_state, char *frname, integer *frcode, char *item, integer *maxn, integer *n, doublereal *values, logical *found, ftnlen frname_len, ftnlen item_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: gdpool_ 14 7 13 4 4 4 7 12 124 */
 
extern int zzdynrot_(void *cspice_state, integer *infram, integer *center, doublereal *et, doublereal *rotate, integer *basfrm);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: bodn2c_ 14 4 13 4 12 124 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: frmnam_ 14 3 4 13 124 */
/*:ref: zzdynfid_ 14 6 13 4 13 4 124 124 */
/*:ref: zzdynvac_ 14 9 13 4 13 4 4 13 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: zzdynoad_ 14 9 13 4 13 4 4 7 12 124 124 */
/*:ref: zzdynoac_ 14 10 13 4 13 4 4 13 12 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: bodc2n_ 14 4 4 13 12 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: zzeprc76_ 14 2 7 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: xpose_ 14 2 7 7 */
/*:ref: zzenut80_ 14 2 7 7 */
/*:ref: mxm_ 14 3 7 7 7 */
/*:ref: zzmobliq_ 14 3 7 7 7 */
/*:ref: eul2m_ 14 7 7 7 7 4 4 4 7 */
/*:ref: zzrefch0_ 14 4 4 4 7 7 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzdynbid_ 14 6 13 4 13 4 124 124 */
/*:ref: zzspkzp0_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: zzspkez0_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: zzprscor_ 14 3 13 12 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: zzcorepc_ 14 5 13 7 7 7 124 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: cidfrm_ 14 5 4 4 13 12 124 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: nearpt_ 14 6 7 7 7 7 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: zzspksb0_ 14 5 4 7 13 7 124 */
/*:ref: zzdynvad_ 14 8 13 4 13 4 4 7 124 124 */
/*:ref: convrt_ 14 6 7 13 13 7 124 124 */
/*:ref: latrec_ 14 4 7 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: stlabx_ 14 3 7 7 7 */
/*:ref: stelab_ 14 3 7 7 7 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: twovec_ 14 5 7 4 7 4 7 */
/*:ref: zzdynvai_ 14 8 13 4 13 4 4 4 124 124 */
/*:ref: polyds_ 14 5 7 4 4 7 7 */
 
extern int zzdynrt0_(void *cspice_state, integer *infram, integer *center, doublereal *et, doublereal *rotate, integer *basfrm);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: bodn2c_ 14 4 13 4 12 124 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: frmnam_ 14 3 4 13 124 */
/*:ref: zzdynfid_ 14 6 13 4 13 4 124 124 */
/*:ref: zzdynvac_ 14 9 13 4 13 4 4 13 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: zzdynoad_ 14 9 13 4 13 4 4 7 12 124 124 */
/*:ref: zzdynoac_ 14 10 13 4 13 4 4 13 12 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: bodc2n_ 14 4 4 13 12 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: zzeprc76_ 14 2 7 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: xpose_ 14 2 7 7 */
/*:ref: zzenut80_ 14 2 7 7 */
/*:ref: mxm_ 14 3 7 7 7 */
/*:ref: zzmobliq_ 14 3 7 7 7 */
/*:ref: eul2m_ 14 7 7 7 7 4 4 4 7 */
/*:ref: zzrefch1_ 14 4 4 4 7 7 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzdynbid_ 14 6 13 4 13 4 124 124 */
/*:ref: zzspkzp1_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: zzspkez1_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: zzprscor_ 14 3 13 12 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: zzcorepc_ 14 5 13 7 7 7 124 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: cidfrm_ 14 5 4 4 13 12 124 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: nearpt_ 14 6 7 7 7 7 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: zzspksb1_ 14 5 4 7 13 7 124 */
/*:ref: zzdynvad_ 14 8 13 4 13 4 4 7 124 124 */
/*:ref: convrt_ 14 6 7 13 13 7 124 124 */
/*:ref: latrec_ 14 4 7 7 7 7 */
/*:ref: stlabx_ 14 3 7 7 7 */
/*:ref: stelab_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: twovec_ 14 5 7 4 7 4 7 */
/*:ref: zzdynvai_ 14 8 13 4 13 4 4 4 124 124 */
/*:ref: polyds_ 14 5 7 4 4 7 7 */
 
extern int zzdynvac_(void *cspice_state, char *frname, integer *frcode, char *item, integer *maxn, integer *n, char *values, ftnlen frname_len, ftnlen item_len, ftnlen values_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: gcpool_ 14 8 13 4 4 4 13 12 124 124 */
 
extern int zzdynvad_(void *cspice_state, char *frname, integer *frcode, char *item, integer *maxn, integer *n, doublereal *values, ftnlen frname_len, ftnlen item_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: gdpool_ 14 7 13 4 4 4 7 12 124 */
 
extern int zzdynvai_(void *cspice_state, char *frname, integer *frcode, char *item, integer *maxn, integer *n, integer *values, ftnlen frname_len, ftnlen item_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: gipool_ 14 7 13 4 4 4 4 12 124 */
 
extern int zzedterm_(void *cspice_state, char *type__, doublereal *a, doublereal *b, doublereal *c__, doublereal *srcrad, doublereal *srcpos, integer *npts, doublereal *trmpts, ftnlen type_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: frame_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: twopi_ 7 0 */
/*:ref: latrec_ 14 4 7 7 7 7 */
/*:ref: halfpi_ 7 0 */
/*:ref: touchd_ 7 1 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: nvp2pl_ 14 3 7 7 7 */
/*:ref: pl2nvc_ 14 3 7 7 7 */
/*:ref: vpack_ 14 4 7 7 7 7 */
/*:ref: vscl_ 14 3 7 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: vdot_ 7 2 7 7 */
 
extern int zzedtmpt_(void *cspice_state, logical *umbral, doublereal *a, doublereal *b, doublereal *c__, doublereal *r__, doublereal *axis, doublereal *plnvec, doublereal *point);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vzero_ 12 1 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: dasine_ 7 2 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: halfpi_ 7 0 */
/*:ref: vrotv_ 14 4 7 7 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vscl_ 14 3 7 7 7 */
/*:ref: ednmpt_ 14 5 7 7 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: touchd_ 7 1 7 */
/*:ref: vperp_ 14 3 7 7 7 */
/*:ref: vdist_ 7 2 7 7 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern int zzekac01_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *ivals, logical *nlflgs, integer *rcptrs, integer *wkindx);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekspsh_ 14 2 4 4 */
/*:ref: zzekaps_ 14 6 4 4 4 12 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: zzekpgwi_ 14 3 4 4 4 */
/*:ref: zzekordi_ 14 5 4 12 12 4 4 */
/*:ref: zzektrit_ 14 2 4 4 */
/*:ref: zzektr1s_ 14 4 4 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
 
extern int zzekac02_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, doublereal *dvals, logical *nlflgs, integer *rcptrs, integer *wkindx);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekspsh_ 14 2 4 4 */
/*:ref: zzekaps_ 14 6 4 4 4 12 4 4 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: zzekpgwd_ 14 3 4 4 7 */
/*:ref: zzekordd_ 14 5 7 12 12 4 4 */
/*:ref: zzektrit_ 14 2 4 4 */
/*:ref: zzektr1s_ 14 4 4 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
 
extern int zzekac03_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, char *cvals, logical *nlflgs, integer *rcptrs, integer *wkindx, ftnlen cvals_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekspsh_ 14 2 4 4 */
/*:ref: zzekaps_ 14 6 4 4 4 12 4 4 */
/*:ref: prtenc_ 14 3 4 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: prtdec_ 14 3 13 4 124 */
/*:ref: zzekpgwc_ 14 4 4 4 13 124 */
/*:ref: zzekordc_ 14 6 13 12 12 4 4 124 */
/*:ref: zzektrit_ 14 2 4 4 */
/*:ref: zzektr1s_ 14 4 4 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
 
extern int zzekac04_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *ivals, integer *entszs, logical *nlflgs);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekspsh_ 14 2 4 4 */
/*:ref: zzekaps_ 14 6 4 4 4 12 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: zzekpgwi_ 14 3 4 4 4 */
/*:ref: zzeksfwd_ 14 4 4 4 4 4 */
 
extern int zzekac05_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, doublereal *dvals, integer *entszs, logical *nlflgs);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekspsh_ 14 2 4 4 */
/*:ref: zzekaps_ 14 6 4 4 4 12 4 4 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: zzekpgwd_ 14 3 4 4 7 */
/*:ref: zzeksfwd_ 14 4 4 4 4 4 */
 
extern int zzekac06_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, char *cvals, integer *entszs, logical *nlflgs, ftnlen cvals_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekspsh_ 14 2 4 4 */
/*:ref: zzekaps_ 14 6 4 4 4 12 4 4 */
/*:ref: prtenc_ 14 3 4 13 124 */
/*:ref: zzekpgwc_ 14 4 4 4 13 124 */
/*:ref: zzeksfwd_ 14 4 4 4 4 4 */
 
extern int zzekac07_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *ivals, logical *nlflgs, integer *wkindx);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekacps_ 14 6 4 4 4 4 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: zzekpgwi_ 14 3 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzekordi_ 14 5 4 12 12 4 4 */
/*:ref: zzekwpai_ 14 6 4 4 4 4 4 4 */
/*:ref: zzekwpal_ 14 6 4 4 4 12 4 4 */
 
extern int zzekac08_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, doublereal *dvals, logical *nlflgs, integer *wkindx);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekacps_ 14 6 4 4 4 4 4 4 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: zzekpgwd_ 14 3 4 4 7 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzekordd_ 14 5 7 12 12 4 4 */
/*:ref: zzekwpai_ 14 6 4 4 4 4 4 4 */
/*:ref: zzekwpal_ 14 6 4 4 4 12 4 4 */
 
extern int zzekac09_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, char *cvals, logical *nlflgs, integer *wkindx, ftnlen cvals_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekacps_ 14 6 4 4 4 4 4 4 */
/*:ref: zzekpgwc_ 14 4 4 4 13 124 */
/*:ref: zzekslnk_ 14 4 4 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzekordc_ 14 6 13 12 12 4 4 124 */
/*:ref: zzekwpai_ 14 6 4 4 4 4 4 4 */
/*:ref: zzekwpal_ 14 6 4 4 4 12 4 4 */
 
extern int zzekacps_(void *cspice_state, integer *handle, integer *segdsc, integer *type__, integer *n, integer *p, integer *base);
/*:ref: zzekpgan_ 14 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: zzekslnk_ 14 4 4 4 4 4 */
/*:ref: zzeksfwd_ 14 4 4 4 4 4 */
/*:ref: zzektrap_ 14 4 4 4 4 4 */
 
extern int zzekad01_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, integer *ival, logical *isnull);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzekpgbs_ 14 3 4 4 4 */
/*:ref: zzekglnk_ 14 4 4 4 4 4 */
/*:ref: zzekslnk_ 14 4 4 4 4 4 */
/*:ref: zzekaps_ 14 6 4 4 4 12 4 4 */
/*:ref: zzekiii1_ 14 6 4 4 4 4 4 12 */
 
extern int zzekad02_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, doublereal *dval, logical *isnull);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzekpgbs_ 14 3 4 4 4 */
/*:ref: dasudd_ 14 4 4 4 4 7 */
/*:ref: zzekglnk_ 14 4 4 4 4 4 */
/*:ref: zzekslnk_ 14 4 4 4 4 4 */
/*:ref: zzekaps_ 14 6 4 4 4 12 4 4 */
/*:ref: zzekiid1_ 14 6 4 4 4 7 4 12 */
 
extern int zzekad03_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, char *cval, logical *isnull, ftnlen cval_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzekpgbs_ 14 3 4 4 4 */
/*:ref: zzeksei_ 14 3 4 4 4 */
/*:ref: dasudc_ 14 7 4 4 4 4 4 13 124 */
/*:ref: zzekglnk_ 14 4 4 4 4 4 */
/*:ref: zzekslnk_ 14 4 4 4 4 4 */
/*:ref: zzekaps_ 14 6 4 4 4 12 4 4 */
/*:ref: zzeksfwd_ 14 4 4 4 4 4 */
/*:ref: zzekiic1_ 14 7 4 4 4 13 4 12 124 */
 
extern int zzekad04_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, integer *nvals, integer *ivals, logical *isnull);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzekpgbs_ 14 3 4 4 4 */
/*:ref: zzekglnk_ 14 4 4 4 4 4 */
/*:ref: zzekslnk_ 14 4 4 4 4 4 */
/*:ref: zzekaps_ 14 6 4 4 4 12 4 4 */
/*:ref: zzeksfwd_ 14 4 4 4 4 4 */
 
extern int zzekad05_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, integer *nvals, doublereal *dvals, logical *isnull);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzekpgbs_ 14 3 4 4 4 */
/*:ref: dasudd_ 14 4 4 4 4 7 */
/*:ref: zzekglnk_ 14 4 4 4 4 4 */
/*:ref: zzekslnk_ 14 4 4 4 4 4 */
/*:ref: zzekaps_ 14 6 4 4 4 12 4 4 */
/*:ref: zzeksfwd_ 14 4 4 4 4 4 */
 
extern int zzekad06_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, integer *nvals, char *cvals, logical *isnull, ftnlen cvals_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzekpgbs_ 14 3 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: zzeksei_ 14 3 4 4 4 */
/*:ref: zzekglnk_ 14 4 4 4 4 4 */
/*:ref: zzekslnk_ 14 4 4 4 4 4 */
/*:ref: dasudc_ 14 7 4 4 4 4 4 13 124 */
/*:ref: zzekaps_ 14 6 4 4 4 12 4 4 */
/*:ref: zzeksfwd_ 14 4 4 4 4 4 */
 
extern int zzekaps_(void *cspice_state, integer *handle, integer *segdsc, integer *type__, logical *new__, integer *p, integer *base);
/*:ref: zzekpgan_ 14 4 4 4 4 4 */
/*:ref: zzekpgal_ 14 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: zzekslnk_ 14 4 4 4 4 4 */
/*:ref: zzeksfwd_ 14 4 4 4 4 4 */
/*:ref: zzektrap_ 14 4 4 4 4 4 */
 
extern int zzekbs01_(void *cspice_state, integer *handle, char *tabnam, integer *ncols, char *cnames, integer *cdscrs, integer *segno, ftnlen tabnam_len, ftnlen cnames_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekpgan_ 14 4 4 4 4 4 */
/*:ref: zzektrit_ 14 2 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: eknseg_ 4 1 4 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: zzekpgwc_ 14 4 4 4 13 124 */
/*:ref: zzekcix1_ 14 2 4 4 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: zzekpgwi_ 14 3 4 4 4 */
/*:ref: zzekpgbs_ 14 3 4 4 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: zzektrap_ 14 4 4 4 4 4 */
 
extern int zzekbs02_(void *cspice_state, integer *handle, char *tabnam, integer *ncols, char *cnames, integer *cdscrs, integer *segno, ftnlen tabnam_len, ftnlen cnames_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekpgan_ 14 4 4 4 4 4 */
/*:ref: zzektrit_ 14 2 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: eknseg_ 4 1 4 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: zzekpgwc_ 14 4 4 4 13 124 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: zzekpgwi_ 14 3 4 4 4 */
/*:ref: zzekpgbs_ 14 3 4 4 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: zzektrap_ 14 4 4 4 4 4 */
 
extern int zzekcchk_(void *cspice_state, char *query, integer *eqryi, char *eqryc, integer *ntab, char *tablst, char *alslst, integer *base, logical *error, char *errmsg, integer *errptr, ftnlen query_len, ftnlen eqryc_len, ftnlen tablst_len, ftnlen alslst_len, ftnlen errmsg_len);
/*:ref: zzekreqi_ 14 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: ekccnt_ 14 3 13 4 124 */
/*:ref: ekcii_ 14 6 13 4 13 4 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
 
extern int zzekcdsc_(void *cspice_state, integer *handle, integer *segdsc, char *column, integer *coldsc, ftnlen column_len);
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: dasrdc_ 14 7 4 4 4 4 4 13 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzekcix1_(void *cspice_state, integer *handle, integer *coldsc);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzektrit_ 14 2 4 4 */
 
extern int zzekcnam_(void *cspice_state, integer *handle, integer *coldsc, char *column, ftnlen column_len);
/*:ref: dasrdc_ 14 7 4 4 4 4 4 13 124 */
 
extern int zzekde01_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: zzekixdl_ 14 4 4 4 4 4 */
/*:ref: zzekpgpg_ 14 4 4 4 4 4 */
/*:ref: zzekglnk_ 14 4 4 4 4 4 */
/*:ref: zzekslnk_ 14 4 4 4 4 4 */
/*:ref: zzekdps_ 14 4 4 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern int zzekde02_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: zzekixdl_ 14 4 4 4 4 4 */
/*:ref: zzekpgpg_ 14 4 4 4 4 4 */
/*:ref: zzekglnk_ 14 4 4 4 4 4 */
/*:ref: zzekslnk_ 14 4 4 4 4 4 */
/*:ref: zzekdps_ 14 4 4 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern int zzekde03_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: zzekixdl_ 14 4 4 4 4 4 */
/*:ref: zzekgei_ 14 3 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzekpgpg_ 14 4 4 4 4 4 */
/*:ref: zzekgfwd_ 14 4 4 4 4 4 */
/*:ref: zzekglnk_ 14 4 4 4 4 4 */
/*:ref: zzekslnk_ 14 4 4 4 4 4 */
/*:ref: zzekdps_ 14 4 4 4 4 4 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern int zzekde04_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzekpgpg_ 14 4 4 4 4 4 */
/*:ref: zzekgfwd_ 14 4 4 4 4 4 */
/*:ref: zzekglnk_ 14 4 4 4 4 4 */
/*:ref: zzekslnk_ 14 4 4 4 4 4 */
/*:ref: zzekdps_ 14 4 4 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern int zzekde05_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: dasrdd_ 14 4 4 4 4 7 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzekpgpg_ 14 4 4 4 4 4 */
/*:ref: zzekgfwd_ 14 4 4 4 4 4 */
/*:ref: zzekglnk_ 14 4 4 4 4 4 */
/*:ref: zzekslnk_ 14 4 4 4 4 4 */
/*:ref: zzekdps_ 14 4 4 4 4 4 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern int zzekde06_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: zzekgei_ 14 3 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzekpgpg_ 14 4 4 4 4 4 */
/*:ref: zzekgfwd_ 14 4 4 4 4 4 */
/*:ref: zzekglnk_ 14 4 4 4 4 4 */
/*:ref: zzekslnk_ 14 4 4 4 4 4 */
/*:ref: zzekdps_ 14 4 4 4 4 4 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern int zzekdps_(void *cspice_state, integer *handle, integer *segdsc, integer *type__, integer *p);
/*:ref: zzekpgfr_ 14 3 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzektrls_ 4 3 4 4 4 */
/*:ref: zzektrdl_ 14 3 4 4 4 */
 
extern integer zzekecmp_(void *cspice_state, integer *hans, integer *sgdscs, integer *cldscs, integer *rows, integer *elts);
/*:ref: zzekrsi_ 14 8 4 4 4 4 4 4 12 12 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekrsd_ 14 8 4 4 4 4 4 7 12 12 */
/*:ref: zzekrsc_ 14 10 4 4 4 4 4 4 13 12 12 124 */
 
extern int zzekencd_(void *cspice_state, char *query, integer *eqryi, char *eqryc, doublereal *eqryd, logical *error, char *errmsg, integer *errptr, ftnlen query_len, ftnlen eqryc_len, ftnlen errmsg_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekqini_ 14 6 4 4 4 13 7 124 */
/*:ref: zzekscan_ 14 17 13 4 4 4 4 4 4 4 7 13 4 4 12 13 124 124 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekpars_ 14 19 13 4 4 4 4 4 7 13 4 4 4 13 7 12 13 124 124 124 124 */
/*:ref: zzeknres_ 14 9 13 4 13 12 13 4 124 124 124 */
/*:ref: zzektres_ 14 10 13 4 13 7 12 13 4 124 124 124 */
/*:ref: zzeksemc_ 14 9 13 4 13 12 13 4 124 124 124 */
 
extern int zzekerc1_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, char *ckey, integer *recptr, logical *null, integer *prvidx, integer *prvptr, ftnlen ckey_len);
/*:ref: failed_ 12 0 */
/*:ref: zzektrsz_ 4 2 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzektrdp_ 14 4 4 4 4 4 */
/*:ref: zzekscmp_ 12 12 4 4 4 4 4 4 4 13 7 4 12 124 */
 
extern int zzekerd1_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, doublereal *dkey, integer *recptr, logical *null, integer *prvidx, integer *prvptr);
/*:ref: failed_ 12 0 */
/*:ref: zzektrsz_ 4 2 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzektrdp_ 14 4 4 4 4 4 */
/*:ref: zzekscmp_ 12 12 4 4 4 4 4 4 4 13 7 4 12 124 */
 
extern int zzekeri1_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *ikey, integer *recptr, logical *null, integer *prvidx, integer *prvptr);
/*:ref: failed_ 12 0 */
/*:ref: zzektrsz_ 4 2 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzektrdp_ 14 4 4 4 4 4 */
/*:ref: zzekscmp_ 12 12 4 4 4 4 4 4 4 13 7 4 12 124 */
 
extern integer zzekesiz_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr);
/*:ref: zzeksz04_ 4 4 4 4 4 4 */
/*:ref: zzeksz05_ 4 4 4 4 4 4 */
/*:ref: zzeksz06_ 4 4 4 4 4 4 */
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzekff01_(void *cspice_state, integer *handle, integer *segno, integer *rcptrs);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzeksrd_ 14 3 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekmloc_ 14 4 4 4 4 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: zzekpgpg_ 14 4 4 4 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: zzekpgwi_ 14 3 4 4 4 */
/*:ref: zzektrit_ 14 2 4 4 */
/*:ref: zzektr1s_ 14 4 4 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
 
extern int zzekfrx_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, integer *pos);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekrsc_ 14 10 4 4 4 4 4 4 13 12 12 124 */
/*:ref: zzekrsd_ 14 8 4 4 4 4 4 7 12 12 */
/*:ref: zzekrsi_ 14 8 4 4 4 4 4 4 12 12 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: zzeklerc_ 14 9 4 4 4 13 4 12 4 4 124 */
/*:ref: zzeklerd_ 14 8 4 4 4 7 4 12 4 4 */
/*:ref: zzekleri_ 14 8 4 4 4 4 4 12 4 4 */
 
extern int zzekgcdp_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, integer *datptr);
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
 
extern int zzekgei_(void *cspice_state, integer *handle, integer *addrss, integer *ival);
/*:ref: dasrdc_ 14 7 4 4 4 4 4 13 124 */
/*:ref: prtdec_ 14 3 13 4 124 */
 
extern int zzekgfwd_(void *cspice_state, integer *handle, integer *type__, integer *p, integer *fward);
/*:ref: zzekpgbs_ 14 3 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: zzekgei_ 14 3 4 4 4 */
/*:ref: dasrdd_ 14 4 4 4 4 7 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
 
extern int zzekglnk_(void *cspice_state, integer *handle, integer *type__, integer *p, integer *nlinks);
/*:ref: zzekpgbs_ 14 3 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: zzekgei_ 14 3 4 4 4 */
/*:ref: dasrdd_ 14 4 4 4 4 7 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
 
extern int zzekgrcp_(void *cspice_state, integer *handle, integer *recptr, integer *ptr);
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
 
extern int zzekgrs_(void *cspice_state, integer *handle, integer *recptr, integer *status);
/*:ref: dasrdi_ 14 4 4 4 4 4 */
 
extern int zzekif01_(void *cspice_state, integer *handle, integer *segno, integer *rcptrs);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzeksdsc_ 14 3 4 4 4 */
/*:ref: zzekstop_ 14 1 4 */
/*:ref: zzeksdec_ 14 1 4 */
/*:ref: zzekspsh_ 14 2 4 4 */
/*:ref: zzekaps_ 14 6 4 4 4 12 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzekif02_(void *cspice_state, integer *handle, integer *segno);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekmloc_ 14 4 4 4 4 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: zzekaps_ 14 6 4 4 4 12 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzekiic1_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, char *ckey, integer *recptr, logical *null, ftnlen ckey_len);
/*:ref: failed_ 12 0 */
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzeklerc_ 14 9 4 4 4 13 4 12 4 4 124 */
/*:ref: zzektrin_ 14 4 4 4 4 4 */
 
extern int zzekiid1_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, doublereal *dkey, integer *recptr, logical *null);
/*:ref: failed_ 12 0 */
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzeklerd_ 14 8 4 4 4 7 4 12 4 4 */
/*:ref: zzektrin_ 14 4 4 4 4 4 */
 
extern int zzekiii1_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *ikey, integer *recptr, logical *null);
/*:ref: failed_ 12 0 */
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzekleri_ 14 8 4 4 4 4 4 12 4 4 */
/*:ref: zzektrin_ 14 4 4 4 4 4 */
 
extern integer zzekille_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *nrows, integer *dtype, char *cval, doublereal *dval, integer *ival, ftnlen cval_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekllec_ 14 7 4 4 4 13 4 4 124 */
/*:ref: zzeklled_ 14 6 4 4 4 7 4 4 */
/*:ref: zzekllei_ 14 6 4 4 4 4 4 4 */
 
extern integer zzekillt_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *nrows, integer *dtype, char *cval, doublereal *dval, integer *ival, ftnlen cval_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzeklltc_ 14 7 4 4 4 13 4 4 124 */
/*:ref: zzeklltd_ 14 6 4 4 4 7 4 4 */
/*:ref: zzekllti_ 14 6 4 4 4 4 4 4 */
 
extern int zzekinqc_(void *cspice_state, char *value, integer *length, integer *lexbeg, integer *lexend, integer *eqryi, char *eqryc, integer *descr, ftnlen value_len, ftnlen eqryc_len);
/*:ref: zzekreqi_ 14 4 4 13 4 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: zzekweqi_ 14 4 13 4 4 124 */
 
extern int zzekinqn_(void *cspice_state, doublereal *value, integer *type__, integer *lexbeg, integer *lexend, integer *eqryi, doublereal *eqryd, integer *descr);
/*:ref: zzekreqi_ 14 4 4 13 4 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: zzekweqi_ 14 4 13 4 4 124 */
 
extern int zzekixdl_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekfrx_ 14 5 4 4 4 4 4 */
/*:ref: zzektrdl_ 14 3 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: errhan_ 14 3 13 4 124 */
 
extern int zzekixlk_(void *cspice_state, integer *handle, integer *coldsc, integer *key, integer *recptr);
/*:ref: zzektrdp_ 14 4 4 4 4 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzekjoin_(void *cspice_state, integer *jbase1, integer *jbase2, integer *njcnst, logical *active, integer *cpidx1, integer *clidx1, integer *elts1, integer *ops, integer *cpidx2, integer *clidx2, integer *elts2, integer *sthan, integer *stsdsc, integer *stdtpt, integer *dtpool, integer *dtdscs, integer *jbase3, integer *nrows);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzeksrd_ 14 3 4 4 4 */
/*:ref: zzekstop_ 14 1 4 */
/*:ref: zzekspsh_ 14 2 4 4 */
/*:ref: zzeksupd_ 14 3 4 4 4 */
/*:ref: zzekjprp_ 14 23 4 4 4 4 4 4 4 4 4 4 12 4 4 4 4 4 4 4 4 4 4 4 4 */
/*:ref: zzekjnxt_ 14 2 12 4 */
 
extern int zzekjsqz_(void *cspice_state, integer *jrsbas);
/*:ref: zzeksrd_ 14 3 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: zzeksupd_ 14 3 4 4 4 */
 
extern int zzekjsrt_(void *cspice_state, integer *njrs, integer *ubases, integer *norder, integer *otabs, integer *ocols, integer *oelts, integer *senses, integer *sthan, integer *stsdsc, integer *stdtpt, integer *dtpool, integer *dtdscs, integer *ordbas);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzeksrd_ 14 3 4 4 4 */
/*:ref: zzekvset_ 14 2 4 4 */
/*:ref: zzekvcal_ 14 3 4 4 4 */
/*:ref: lnknxt_ 4 2 4 4 */
/*:ref: zzekrsc_ 14 10 4 4 4 4 4 4 13 12 12 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: zzekrsd_ 14 8 4 4 4 4 4 7 12 12 */
/*:ref: zzekrsi_ 14 8 4 4 4 4 4 4 12 12 */
/*:ref: zzekvcmp_ 12 15 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 */
/*:ref: swapi_ 14 2 4 4 */
/*:ref: zzekstop_ 14 1 4 */
/*:ref: zzekspsh_ 14 2 4 4 */
/*:ref: zzeksupd_ 14 3 4 4 4 */
 
extern int zzekjtst_(void *cspice_state, integer *segvec, integer *jbase1, integer *nt1, integer *rb1, integer *nr1, integer *jbase2, integer *nt2, integer *rb2, integer *nr2, integer *njcnst, logical *active, integer *cpidx1, integer *clidx1, integer *elts1, integer *ops, integer *cpidx2, integer *clidx2, integer *elts2, integer *sthan, integer *stsdsc, integer *stdtpt, integer *dtpool, integer *dtdscs, logical *found, integer *rowvec);
extern int zzekjprp_(void *cspice_state, integer *segvec, integer *jbase1, integer *nt1, integer *rb1, integer *nr1, integer *jbase2, integer *nt2, integer *rb2, integer *nr2, integer *njcnst, logical *active, integer *cpidx1, integer *clidx1, integer *elts1, integer *ops, integer *cpidx2, integer *clidx2, integer *elts2, integer *sthan, integer *stsdsc, integer *stdtpt, integer *dtpool, integer *dtdscs);
extern int zzekjnxt_(void *cspice_state, logical *found, integer *rowvec);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: return_ 12 0 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: lnknxt_ 4 2 4 4 */
/*:ref: zzekstop_ 14 1 4 */
/*:ref: zzekspsh_ 14 2 4 4 */
/*:ref: zzeksrd_ 14 3 4 4 4 */
/*:ref: zzeksupd_ 14 3 4 4 4 */
/*:ref: zzekjsrt_ 14 13 4 4 4 4 4 4 4 4 4 4 4 4 4 */
/*:ref: zzekrcmp_ 12 12 4 4 4 4 4 4 4 4 4 4 4 4 */
/*:ref: zzekvmch_ 12 13 4 12 4 4 4 4 4 4 4 4 4 4 4 */
 
extern int zzekkey_(void *cspice_state, integer *handle, integer *segdsc, integer *nrows, integer *ncnstr, integer *clidxs, integer *dsclst, integer *ops, integer *dtypes, char *chrbuf, integer *cbegs, integer *cends, doublereal *dvals, integer *ivals, logical *active, integer *key, integer *keydsc, integer *begidx, integer *endidx, logical *found, ftnlen chrbuf_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ssizei_ 14 2 4 4 */
/*:ref: insrti_ 14 2 4 4 */
/*:ref: cardi_ 4 1 4 */
/*:ref: zzekillt_ 4 9 4 4 4 4 4 13 7 4 124 */
/*:ref: zzekille_ 4 9 4 4 4 4 4 13 7 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: ordi_ 4 2 4 4 */
/*:ref: movei_ 14 3 4 4 4 */
 
extern int zzeklerc_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, char *ckey, integer *recptr, logical *null, integer *prvidx, integer *prvptr, ftnlen ckey_len);
/*:ref: failed_ 12 0 */
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzekerc1_ 14 9 4 4 4 13 4 12 4 4 124 */
 
extern int zzeklerd_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, doublereal *dkey, integer *recptr, logical *null, integer *prvidx, integer *prvptr);
/*:ref: failed_ 12 0 */
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzekerd1_ 14 8 4 4 4 7 4 12 4 4 */
 
extern int zzekleri_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *ikey, integer *recptr, logical *null, integer *prvidx, integer *prvptr);
/*:ref: failed_ 12 0 */
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzekeri1_ 14 8 4 4 4 4 4 12 4 4 */
 
extern int zzekllec_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, char *ckey, integer *prvloc, integer *prvptr, ftnlen ckey_len);
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzekixlk_ 14 4 4 4 4 4 */
/*:ref: zzekscmp_ 12 12 4 4 4 4 4 4 4 13 7 4 12 124 */
 
extern int zzeklled_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, doublereal *dkey, integer *prvloc, integer *prvptr);
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzekixlk_ 14 4 4 4 4 4 */
/*:ref: zzekscmp_ 12 12 4 4 4 4 4 4 4 13 7 4 12 124 */
 
extern int zzekllei_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *ikey, integer *prvloc, integer *prvptr);
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzekixlk_ 14 4 4 4 4 4 */
/*:ref: zzekscmp_ 12 12 4 4 4 4 4 4 4 13 7 4 12 124 */
 
extern int zzeklltc_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, char *ckey, integer *prvloc, integer *prvptr, ftnlen ckey_len);
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzekixlk_ 14 4 4 4 4 4 */
/*:ref: zzekscmp_ 12 12 4 4 4 4 4 4 4 13 7 4 12 124 */
 
extern int zzeklltd_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, doublereal *dkey, integer *prvloc, integer *prvptr);
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzekixlk_ 14 4 4 4 4 4 */
/*:ref: zzekscmp_ 12 12 4 4 4 4 4 4 4 13 7 4 12 124 */
 
extern int zzekllti_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *ikey, integer *prvloc, integer *prvptr);
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzekixlk_ 14 4 4 4 4 4 */
/*:ref: zzekscmp_ 12 12 4 4 4 4 4 4 4 13 7 4 12 124 */
 
extern int zzekmloc_(void *cspice_state, integer *handle, integer *segno, integer *page, integer *base);
/*:ref: eknseg_ 4 1 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzektrbs_ 4 1 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: zzektrdp_ 14 4 4 4 4 4 */
 
extern int zzeknres_(void *cspice_state, char *query, integer *eqryi, char *eqryc, logical *error, char *errmsg, integer *errptr, ftnlen query_len, ftnlen eqryc_len, ftnlen errmsg_len);
/*:ref: zzekreqi_ 14 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekqtab_ 14 8 4 13 4 13 13 124 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: ekntab_ 14 1 4 */
/*:ref: ektnam_ 14 3 4 13 124 */
/*:ref: ekccnt_ 14 3 13 4 124 */
/*:ref: zzekcchk_ 14 15 13 4 13 4 13 13 4 12 13 4 124 124 124 124 124 */
/*:ref: zzekweqi_ 14 4 13 4 4 124 */
 
extern int zzeknrml_(void *cspice_state, char *query, integer *ntoken, integer *lxbegs, integer *lxends, integer *tokens, integer *values, doublereal *numvls, char *chrbuf, integer *chbegs, integer *chends, integer *eqryi, char *eqryc, doublereal *eqryd, logical *error, char *prserr, ftnlen query_len, ftnlen chrbuf_len, ftnlen eqryc_len, ftnlen prserr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzektloc_ 14 7 4 4 4 4 4 4 12 */
/*:ref: lnkini_ 14 2 4 4 */
/*:ref: lnkan_ 14 2 4 4 */
/*:ref: lnkila_ 14 3 4 4 4 */
/*:ref: zzekinqn_ 14 7 7 4 4 4 4 7 4 */
/*:ref: zzekinqc_ 14 9 13 4 4 4 4 13 4 124 124 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: lnkhl_ 4 2 4 4 */
/*:ref: lnkprv_ 4 2 4 4 */
/*:ref: lnknxt_ 4 2 4 4 */
/*:ref: lnkfsl_ 14 3 4 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: lnkilb_ 14 3 4 4 4 */
/*:ref: lnknfn_ 4 1 4 */
/*:ref: lnktl_ 4 2 4 4 */
/*:ref: ssizei_ 14 2 4 4 */
/*:ref: insrti_ 14 2 4 4 */
/*:ref: cardi_ 4 1 4 */
/*:ref: appndi_ 14 2 4 4 */
/*:ref: zzekweqi_ 14 4 13 4 4 124 */
 
extern int zzekordc_(void *cspice_state, char *cvals, logical *nullok, logical *nlflgs, integer *nvals, integer *iorder, ftnlen cvals_len);
/*:ref: swapi_ 14 2 4 4 */
 
extern int zzekordd_(void *cspice_state, doublereal *dvals, logical *nullok, logical *nlflgs, integer *nvals, integer *iorder);
/*:ref: swapi_ 14 2 4 4 */
 
extern int zzekordi_(void *cspice_state, integer *ivals, logical *nullok, logical *nlflgs, integer *nvals, integer *iorder);
/*:ref: swapi_ 14 2 4 4 */
 
extern int zzekpage_(void *cspice_state, integer *handle, integer *type__, integer *addrss, char *stat, integer *p, char *pagec, doublereal *paged, integer *pagei, integer *base, integer *value, ftnlen stat_len, ftnlen pagec_len);
extern int zzekpgin_(void *cspice_state, integer *handle);
extern int zzekpgan_(void *cspice_state, integer *handle, integer *type__, integer *p, integer *base);
extern int zzekpgal_(void *cspice_state, integer *handle, integer *type__, integer *p, integer *base);
extern int zzekpgfr_(void *cspice_state, integer *handle, integer *type__, integer *p);
extern int zzekpgrc_(void *cspice_state, integer *handle, integer *p, char *pagec, ftnlen pagec_len);
extern int zzekpgrd_(void *cspice_state, integer *handle, integer *p, doublereal *paged);
extern int zzekpgri_(void *cspice_state, integer *handle, integer *p, integer *pagei);
extern int zzekpgwc_(void *cspice_state, integer *handle, integer *p, char *pagec, ftnlen pagec_len);
extern int zzekpgwd_(void *cspice_state, integer *handle, integer *p, doublereal *paged);
extern int zzekpgwi_(void *cspice_state, integer *handle, integer *p, integer *pagei);
extern int zzekpgbs_(void *cspice_state, integer *type__, integer *p, integer *base);
extern int zzekpgpg_(void *cspice_state, integer *type__, integer *addrss, integer *p, integer *base);
extern int zzekpgst_(void *cspice_state, integer *handle, char *stat, integer *value, ftnlen stat_len);
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dassih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: daslla_ 14 4 4 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: fillc_ 14 5 13 4 13 124 124 */
/*:ref: filld_ 14 3 7 4 7 */
/*:ref: filli_ 14 3 4 4 4 */
/*:ref: dasadi_ 14 3 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: dasadc_ 14 6 4 4 4 4 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: dasadd_ 14 3 4 4 7 */
/*:ref: dasrdc_ 14 7 4 4 4 4 4 13 124 */
/*:ref: prtdec_ 14 3 13 4 124 */
/*:ref: dasrdd_ 14 4 4 4 4 7 */
/*:ref: prtenc_ 14 3 4 13 124 */
/*:ref: dasudc_ 14 7 4 4 4 4 4 13 124 */
/*:ref: dasudd_ 14 4 4 4 4 7 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
 
extern int zzekpars_(void *cspice_state, char *query, integer *ntoken, integer *lxbegs, integer *lxends, integer *tokens, integer *values, doublereal *numvls, char *chrbuf, integer *chbegs, integer *chends, integer *eqryi, char *eqryc, doublereal *eqryd, logical *error, char *prserr, ftnlen query_len, ftnlen chrbuf_len, ftnlen eqryc_len, ftnlen prserr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekqini_ 14 6 4 4 4 13 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzektloc_ 14 7 4 4 4 4 4 4 12 */
/*:ref: zzekinqc_ 14 9 13 4 4 4 4 13 4 124 124 */
/*:ref: appndi_ 14 2 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: zzekweqi_ 14 4 13 4 4 124 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: cardi_ 4 1 4 */
/*:ref: zzeknrml_ 14 19 13 4 4 4 4 4 7 13 4 4 4 13 7 12 13 124 124 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
 
extern int zzekpcol_(void *cspice_state, char *qcol, integer *eqryi, char *eqryc, char *table, char *alias, integer *tabidx, char *column, integer *colidx, logical *error, char *errmsg, ftnlen qcol_len, ftnlen eqryc_len, ftnlen table_len, ftnlen alias_len, ftnlen column_len, ftnlen errmsg_len);
/*:ref: zzekreqi_ 14 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekscan_ 14 17 13 4 4 4 4 4 4 4 7 13 4 4 12 13 124 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: zzekqtab_ 14 8 4 13 4 13 13 124 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: ekccnt_ 14 3 13 4 124 */
/*:ref: ekcii_ 14 6 13 4 13 4 124 124 */
 
extern int zzekpdec_(void *cspice_state, char *decl, integer *pardsc, ftnlen decl_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: lparsm_ 14 8 13 13 4 4 13 124 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: nparsi_ 14 6 13 4 13 4 124 124 */
 
extern int zzekpgch_(void *cspice_state, integer *handle, char *access, ftnlen access_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dassih_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: daslla_ 14 4 4 4 4 4 */
 
extern int zzekqcnj_(void *cspice_state, integer *eqryi, integer *n, integer *size);
/*:ref: zzekreqi_ 14 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern int zzekqcon_(void *cspice_state, integer *eqryi, char *eqryc, doublereal *eqryd, integer *n, integer *cnstyp, char *ltname, integer *ltidx, char *lcname, integer *lcidx, integer *opcode, char *rtname, integer *rtidx, char *rcname, integer *rcidx, integer *dtype, integer *cbeg, integer *cend, doublereal *dval, integer *ival, ftnlen eqryc_len, ftnlen ltname_len, ftnlen lcname_len, ftnlen rtname_len, ftnlen rcname_len);
/*:ref: zzekreqi_ 14 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern int zzekqini_(void *cspice_state, integer *isize, integer *dsize, integer *eqryi, char *eqryc, doublereal *eqryd, ftnlen eqryc_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ssizei_ 14 2 4 4 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: appndi_ 14 2 4 4 */
/*:ref: cleari_ 14 2 4 4 */
 
extern int zzekqord_(void *cspice_state, integer *eqryi, char *eqryc, integer *n, char *table, integer *tabidx, char *column, integer *colidx, integer *sense, ftnlen eqryc_len, ftnlen table_len, ftnlen column_len);
/*:ref: zzekreqi_ 14 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern int zzekqsel_(void *cspice_state, integer *eqryi, char *eqryc, integer *n, integer *lxbeg, integer *lxend, char *table, integer *tabidx, char *column, integer *colidx, ftnlen eqryc_len, ftnlen table_len, ftnlen column_len);
/*:ref: zzekreqi_ 14 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern int zzekqtab_(void *cspice_state, integer *eqryi, char *eqryc, integer *n, char *table, char *alias, ftnlen eqryc_len, ftnlen table_len, ftnlen alias_len);
/*:ref: zzekreqi_ 14 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern int zzekrbck_(void *cspice_state, char *action, integer *handle, integer *segdsc, integer *coldsc, integer *recno, ftnlen action_len);
 
extern logical zzekrcmp_(void *cspice_state, integer *op, integer *ncols, integer *han1, integer *sgdsc1, integer *cdlst1, integer *row1, integer *elts1, integer *han2, integer *sgdsc2, integer *cdlst2, integer *row2, integer *elts2);
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: zzekecmp_ 4 5 4 4 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzekrd01_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, integer *ival, logical *isnull);
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
 
extern int zzekrd02_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, doublereal *dval, logical *isnull);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: dasrdd_ 14 4 4 4 4 7 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: errhan_ 14 3 13 4 124 */
 
extern int zzekrd03_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, integer *cvlen, char *cval, logical *isnull, ftnlen cval_len);
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: zzekgei_ 14 3 4 4 4 */
/*:ref: zzekpgpg_ 14 4 4 4 4 4 */
/*:ref: dasrdc_ 14 7 4 4 4 4 4 13 124 */
/*:ref: zzekpgbs_ 14 3 4 4 4 */
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
 
extern int zzekrd04_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, integer *beg, integer *end, integer *ivals, logical *isnull, logical *found);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: zzekpgpg_ 14 4 4 4 4 4 */
/*:ref: zzekpgbs_ 14 3 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: zzekgfwd_ 14 4 4 4 4 4 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: errhan_ 14 3 13 4 124 */
 
extern int zzekrd05_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, integer *beg, integer *end, doublereal *dvals, logical *isnull, logical *found);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: dasrdd_ 14 4 4 4 4 7 */
/*:ref: zzekpgpg_ 14 4 4 4 4 4 */
/*:ref: zzekgfwd_ 14 4 4 4 4 4 */
/*:ref: zzekpgbs_ 14 3 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: errhan_ 14 3 13 4 124 */
 
extern int zzekrd06_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, integer *beg, integer *end, char *cvals, logical *isnull, logical *found, ftnlen cvals_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: zzekgei_ 14 3 4 4 4 */
/*:ref: zzekpgpg_ 14 4 4 4 4 4 */
/*:ref: zzekpgbs_ 14 3 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: dasrdc_ 14 7 4 4 4 4 4 13 124 */
 
extern int zzekrd07_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, integer *ival, logical *isnull);
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: dasrdc_ 14 7 4 4 4 4 4 13 124 */
 
extern int zzekrd08_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, doublereal *dval, logical *isnull);
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: dasrdc_ 14 7 4 4 4 4 4 13 124 */
/*:ref: dasrdd_ 14 4 4 4 4 7 */
 
extern int zzekrd09_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recno, integer *cvlen, char *cval, logical *isnull, ftnlen cval_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: dasrdc_ 14 7 4 4 4 4 4 13 124 */
 
extern int zzekreqi_(void *cspice_state, integer *eqryi, char *name__, integer *value, ftnlen name_len);
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern logical zzekrmch_(void *cspice_state, integer *ncnstr, logical *active, integer *handle, integer *segdsc, integer *cdscrs, integer *row, integer *elts, integer *ops, integer *vtypes, char *chrbuf, integer *cbegs, integer *cends, doublereal *dvals, integer *ivals, ftnlen chrbuf_len);
/*:ref: zzekscmp_ 12 12 4 4 4 4 4 4 4 13 7 4 12 124 */
 
extern integer zzekrp2n_(void *cspice_state, integer *handle, integer *segno, integer *recptr);
/*:ref: zzeksdsc_ 14 3 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: zzektrls_ 4 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzekrplk_(void *cspice_state, integer *handle, integer *segdsc, integer *n, integer *recptr);
/*:ref: zzektrdp_ 14 4 4 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzekrsc_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, integer *eltidx, integer *cvlen, char *cval, logical *isnull, logical *found, ftnlen cval_len);
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekrd03_ 14 8 4 4 4 4 4 13 12 124 */
/*:ref: zzekrd06_ 14 10 4 4 4 4 4 4 13 12 12 124 */
/*:ref: zzekrd09_ 14 8 4 4 4 4 4 13 12 124 */
 
extern int zzekrsd_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, integer *eltidx, doublereal *dval, logical *isnull, logical *found);
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekrd02_ 14 6 4 4 4 4 7 12 */
/*:ref: zzekrd05_ 14 9 4 4 4 4 4 4 7 12 12 */
/*:ref: zzekrd08_ 14 6 4 4 4 4 7 12 */
 
extern int zzekrsi_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, integer *eltidx, integer *ival, logical *isnull, logical *found);
/*:ref: zzekcnam_ 14 4 4 4 13 124 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekrd01_ 14 6 4 4 4 4 4 12 */
/*:ref: zzekrd04_ 14 9 4 4 4 4 4 4 4 12 12 */
/*:ref: zzekrd07_ 14 6 4 4 4 4 4 12 */
 
extern int zzeksca_(void *cspice_state, integer *n, integer *beg, integer *end, integer *idata, integer *top);
extern int zzekstop_(void *cspice_state, integer *top);
extern int zzekspsh_(void *cspice_state, integer *n, integer *idata);
extern int zzekspop_(void *cspice_state, integer *n, integer *idata);
extern int zzeksdec_(void *cspice_state, integer *n);
extern int zzeksupd_(void *cspice_state, integer *beg, integer *end, integer *idata);
extern int zzeksrd_(void *cspice_state, integer *beg, integer *end, integer *idata);
extern int zzekscln_(void *cspice_state);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasops_ 14 1 4 */
/*:ref: failed_ 12 0 */
/*:ref: daslla_ 14 4 4 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: dasadi_ 14 3 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: daswbr_ 14 1 4 */
/*:ref: dasllc_ 14 1 4 */
 
extern int zzekscan_(void *cspice_state, char *query, integer *maxntk, integer *maxnum, integer *ntoken, integer *tokens, integer *lxbegs, integer *lxends, integer *values, doublereal *numvls, char *chrbuf, integer *chbegs, integer *chends, logical *scnerr, char *errmsg, ftnlen query_len, ftnlen chrbuf_len, ftnlen errmsg_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ssizei_ 14 2 4 4 */
/*:ref: lxcsid_ 14 5 13 13 4 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lxqstr_ 14 7 13 13 4 4 4 124 124 */
/*:ref: parsqs_ 14 11 13 13 13 4 12 13 4 124 124 124 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: lx4num_ 14 5 13 4 4 4 124 */
/*:ref: nparsd_ 14 6 13 7 13 4 124 124 */
/*:ref: beint_ 12 2 13 124 */
/*:ref: lxidnt_ 14 6 4 13 4 4 4 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: frstpc_ 4 2 13 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
 
extern int zzekscdp_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, integer *datptr);
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
 
extern logical zzekscmp_(void *cspice_state, integer *op, integer *handle, integer *segdsc, integer *coldsc, integer *row, integer *eltidx, integer *dtype, char *cval, doublereal *dval, integer *ival, logical *null, ftnlen cval_len);
/*:ref: zzekrsc_ 14 10 4 4 4 4 4 4 13 12 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: zzekrsd_ 14 8 4 4 4 4 4 7 12 12 */
/*:ref: zzekrsi_ 14 8 4 4 4 4 4 4 12 12 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: matchi_ 12 8 13 13 13 13 124 124 124 124 */
 
extern int zzeksdsc_(void *cspice_state, integer *handle, integer *segno, integer *segdsc);
/*:ref: zzekmloc_ 14 4 4 4 4 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
 
extern int zzeksei_(void *cspice_state, integer *handle, integer *addrss, integer *ival);
/*:ref: prtenc_ 14 3 4 13 124 */
/*:ref: dasudc_ 14 7 4 4 4 4 4 13 124 */
 
extern int zzeksemc_(void *cspice_state, char *query, integer *eqryi, char *eqryc, logical *error, char *errmsg, integer *errptr, ftnlen query_len, ftnlen eqryc_len, ftnlen errmsg_len);
/*:ref: zzekreqi_ 14 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekqtab_ 14 8 4 13 4 13 13 124 124 124 */
/*:ref: ekcii_ 14 6 13 4 13 4 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: zzekweqi_ 14 4 13 4 4 124 */
 
extern int zzeksfwd_(void *cspice_state, integer *handle, integer *type__, integer *p, integer *fward);
/*:ref: zzekpgbs_ 14 3 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: zzeksei_ 14 3 4 4 4 */
/*:ref: dasudd_ 14 4 4 4 4 7 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
 
extern int zzeksinf_(void *cspice_state, integer *handle, integer *segno, char *tabnam, integer *segdsc, char *cnames, integer *cdscrs, ftnlen tabnam_len, ftnlen cnames_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: eknseg_ 4 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzekmloc_ 14 4 4 4 4 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: dasrdc_ 14 7 4 4 4 4 4 13 124 */
 
extern int zzekslnk_(void *cspice_state, integer *handle, integer *type__, integer *p, integer *nlinks);
/*:ref: zzekpgbs_ 14 3 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: zzeksei_ 14 3 4 4 4 */
/*:ref: dasudd_ 14 4 4 4 4 7 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
 
extern int zzeksrcp_(void *cspice_state, integer *handle, integer *recptr, integer *recno);
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
 
extern int zzeksrs_(void *cspice_state, integer *handle, integer *recptr, integer *status);
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
 
extern integer zzekstyp_(void *cspice_state, integer *ncols, integer *cdscrs);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern integer zzeksz04_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
 
extern integer zzeksz05_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: dasrdd_ 14 4 4 4 4 7 */
 
extern integer zzeksz06_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: zzekgei_ 14 3 4 4 4 */
 
extern int zzektcnv_(void *cspice_state, char *timstr, doublereal *et, logical *error, char *errmsg, ftnlen timstr_len, ftnlen errmsg_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: posr_ 4 5 13 13 4 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: scn2id_ 14 4 13 4 12 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: scpars_ 14 7 4 13 12 13 7 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: sct2e_ 14 3 4 7 7 */
/*:ref: tpartv_ 14 15 13 7 4 13 13 12 12 12 13 13 124 124 124 124 124 */
/*:ref: str2et_ 14 3 13 7 124 */
 
extern int zzektloc_(void *cspice_state, integer *tokid, integer *kwcode, integer *ntoken, integer *tokens, integer *values, integer *loc, logical *found);
 
extern int zzektr13_(void *cspice_state, integer *handle, integer *tree);
/*:ref: zzekpgri_ 14 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekpgal_ 14 4 4 4 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: zzekpgwi_ 14 3 4 4 4 */
 
extern int zzektr1s_(void *cspice_state, integer *handle, integer *tree, integer *size, integer *values);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzektrsz_ 4 2 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekpgri_ 14 3 4 4 4 */
/*:ref: zzekpgal_ 14 4 4 4 4 4 */
/*:ref: zzekpgwi_ 14 3 4 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: zzektrbs_ 4 1 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
 
extern int zzektr23_(void *cspice_state, integer *handle, integer *tree, integer *left, integer *right, integer *parent, integer *pkidx, logical *overfl);
/*:ref: zzekpgri_ 14 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekpgal_ 14 4 4 4 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: zzektrbs_ 4 1 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzekpgwi_ 14 3 4 4 4 */
 
extern int zzektr31_(void *cspice_state, integer *handle, integer *tree);
/*:ref: zzekpgri_ 14 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: zzekpgwi_ 14 3 4 4 4 */
/*:ref: zzekpgfr_ 14 3 4 4 4 */
 
extern int zzektr32_(void *cspice_state, integer *handle, integer *tree, integer *left, integer *middle, integer *right, integer *parent, integer *lpkidx, logical *undrfl);
/*:ref: zzekpgri_ 14 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: zzektrbs_ 4 1 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzekpgwi_ 14 3 4 4 4 */
/*:ref: zzekpgfr_ 14 3 4 4 4 */
 
extern int zzektrap_(void *cspice_state, integer *handle, integer *tree, integer *value, integer *key);
/*:ref: zzektrsz_ 4 2 4 4 */
/*:ref: zzektrin_ 14 4 4 4 4 4 */
 
extern int zzektrbn_(void *cspice_state, integer *handle, integer *tree, integer *left, integer *right, integer *parent, integer *pkidx);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzektrnk_ 4 3 4 4 4 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzektrrk_ 14 7 4 4 4 4 4 4 4 */
 
extern integer zzektrbs_(void *cspice_state, integer *node);
/*:ref: zzekpgbs_ 14 3 4 4 4 */
 
extern int zzektrdl_(void *cspice_state, integer *handle, integer *tree, integer *key);
/*:ref: zzektrud_ 14 5 4 4 4 4 12 */
/*:ref: failed_ 12 0 */
/*:ref: zzektrlk_ 14 8 4 4 4 4 4 4 4 4 */
/*:ref: zzektrsb_ 14 7 4 4 4 4 4 4 4 */
/*:ref: zzektrnk_ 4 3 4 4 4 */
/*:ref: zzektrpi_ 14 12 4 4 4 4 4 4 4 4 4 4 4 4 */
/*:ref: zzektrrk_ 14 7 4 4 4 4 4 4 4 */
/*:ref: zzektrbn_ 14 6 4 4 4 4 4 4 */
/*:ref: zzektrki_ 14 5 4 4 4 4 4 */
/*:ref: zzektr32_ 14 8 4 4 4 4 4 4 4 12 */
/*:ref: zzektr31_ 14 2 4 4 */
 
extern int zzektrdp_(void *cspice_state, integer *handle, integer *tree, integer *key, integer *ptr);
/*:ref: zzektrlk_ 14 8 4 4 4 4 4 4 4 4 */
 
extern int zzektres_(void *cspice_state, char *query, integer *eqryi, char *eqryc, doublereal *eqryd, logical *error, char *errmsg, integer *errptr, ftnlen query_len, ftnlen eqryc_len, ftnlen errmsg_len);
/*:ref: zzekreqi_ 14 4 4 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekqtab_ 14 8 4 13 4 13 13 124 124 124 */
/*:ref: ekcii_ 14 6 13 4 13 4 124 124 */
/*:ref: zzektcnv_ 14 6 13 7 12 13 124 124 */
/*:ref: zzekinqn_ 14 7 7 4 4 4 4 7 4 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: zzekweqi_ 14 4 13 4 4 124 */
 
extern int zzektrfr_(void *cspice_state, integer *handle, integer *tree);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekpgri_ 14 3 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekpgfr_ 14 3 4 4 4 */
 
extern int zzektrin_(void *cspice_state, integer *handle, integer *tree, integer *key, integer *value);
/*:ref: zzektrui_ 14 5 4 4 4 4 12 */
/*:ref: failed_ 12 0 */
/*:ref: zzektrlk_ 14 8 4 4 4 4 4 4 4 4 */
/*:ref: zzektrpi_ 14 12 4 4 4 4 4 4 4 4 4 4 4 4 */
/*:ref: zzektrnk_ 4 3 4 4 4 */
/*:ref: zzektrbn_ 14 6 4 4 4 4 4 4 */
/*:ref: zzektrki_ 14 5 4 4 4 4 4 */
/*:ref: zzektr23_ 14 7 4 4 4 4 4 4 12 */
/*:ref: zzektr13_ 14 2 4 4 */
 
extern int zzektrit_(void *cspice_state, integer *handle, integer *tree);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekpgal_ 14 4 4 4 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: zzekpgwi_ 14 3 4 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzektrki_(void *cspice_state, integer *handle, integer *tree, integer *nodkey, integer *n, integer *key);
/*:ref: zzektrlk_ 14 8 4 4 4 4 4 4 4 4 */
/*:ref: zzektrnk_ 4 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzektrbs_ 4 1 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
 
extern int zzektrlk_(void *cspice_state, integer *handle, integer *tree, integer *key, integer *idx, integer *node, integer *noffst, integer *level, integer *value);
/*:ref: dasham_ 14 3 4 13 124 */
/*:ref: zzekpgri_ 14 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lstlei_ 4 3 4 4 4 */
 
extern integer zzektrls_(void *cspice_state, integer *handle, integer *tree, integer *ival);
/*:ref: zzektrsz_ 4 2 4 4 */
/*:ref: zzektrdp_ 14 4 4 4 4 4 */
 
extern integer zzektrnk_(void *cspice_state, integer *handle, integer *tree, integer *node);
/*:ref: zzektrbs_ 4 1 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
 
extern int zzektrpi_(void *cspice_state, integer *handle, integer *tree, integer *key, integer *parent, integer *pkey, integer *poffst, integer *lpidx, integer *lpkey, integer *lsib, integer *rpidx, integer *rpkey, integer *rsib);
/*:ref: zzekpgri_ 14 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lstlei_ 4 3 4 4 4 */
 
extern int zzektrrk_(void *cspice_state, integer *handle, integer *tree, integer *left, integer *right, integer *parent, integer *pkidx, integer *nrot);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekpgri_ 14 3 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: zzekpgwi_ 14 3 4 4 4 */
 
extern int zzektrsb_(void *cspice_state, integer *handle, integer *tree, integer *key, integer *lsib, integer *lkey, integer *rsib, integer *rkey);
/*:ref: zzektrpi_ 14 12 4 4 4 4 4 4 4 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: zzektrbs_ 4 1 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
 
extern integer zzektrsz_(void *cspice_state, integer *handle, integer *tree);
/*:ref: zzektrbs_ 4 1 4 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
 
extern int zzektrud_(void *cspice_state, integer *handle, integer *tree, integer *key, integer *trgkey, logical *undrfl);
/*:ref: zzekpgri_ 14 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekpgwi_ 14 3 4 4 4 */
/*:ref: zzektrlk_ 14 8 4 4 4 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: zzektrpi_ 14 12 4 4 4 4 4 4 4 4 4 4 4 4 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern int zzektrui_(void *cspice_state, integer *handle, integer *tree, integer *key, integer *value, logical *overfl);
/*:ref: zzekpgri_ 14 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekpgwi_ 14 3 4 4 4 */
/*:ref: zzektrlk_ 14 8 4 4 4 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: zzektrpi_ 14 12 4 4 4 4 4 4 4 4 4 4 4 4 */
 
extern int zzekue01_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, integer *ival, logical *isnull);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: zzekixdl_ 14 4 4 4 4 4 */
/*:ref: zzekiii1_ 14 6 4 4 4 4 4 12 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzekpgpg_ 14 4 4 4 4 4 */
/*:ref: zzekglnk_ 14 4 4 4 4 4 */
/*:ref: zzekslnk_ 14 4 4 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: zzekad01_ 14 6 4 4 4 4 4 12 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: errhan_ 14 3 13 4 124 */
 
extern int zzekue02_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, doublereal *dval, logical *isnull);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekpgch_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dasrdi_ 14 4 4 4 4 4 */
/*:ref: zzekixdl_ 14 4 4 4 4 4 */
/*:ref: zzekiid1_ 14 6 4 4 4 7 4 12 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzekpgpg_ 14 4 4 4 4 4 */
/*:ref: zzekglnk_ 14 4 4 4 4 4 */
/*:ref: zzekslnk_ 14 4 4 4 4 4 */
/*:ref: dasudi_ 14 4 4 4 4 4 */
/*:ref: dasudd_ 14 4 4 4 4 7 */
/*:ref: zzekad02_ 14 6 4 4 4 4 7 12 */
/*:ref: zzekrp2n_ 4 3 4 4 4 */
/*:ref: errhan_ 14 3 13 4 124 */
 
extern int zzekue03_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, char *cval, logical *isnull, ftnlen cval_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekde03_ 14 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekad03_ 14 7 4 4 4 4 13 12 124 */
 
extern int zzekue04_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, integer *nvals, integer *ivals, logical *isnull);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekde04_ 14 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekad04_ 14 7 4 4 4 4 4 4 12 */
 
extern int zzekue05_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, integer *nvals, doublereal *dvals, logical *isnull);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekde05_ 14 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekad05_ 14 7 4 4 4 4 4 7 12 */
 
extern int zzekue06_(void *cspice_state, integer *handle, integer *segdsc, integer *coldsc, integer *recptr, integer *nvals, char *cvals, logical *isnull, ftnlen cvals_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekde06_ 14 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekad06_ 14 8 4 4 4 4 4 13 12 124 */
 
extern int zzekvadr_(void *cspice_state, integer *njrs, integer *bases, integer *rwvidx, integer *rwvbas, integer *sgvbas);
extern int zzekvset_(void *cspice_state, integer *njrs, integer *bases);
extern int zzekvcal_(void *cspice_state, integer *rwvidx, integer *rwvbas, integer *sgvbas);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzekstop_ 14 1 4 */
/*:ref: zzeksrd_ 14 3 4 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: lstlei_ 4 3 4 4 4 */
 
extern logical zzekvcmp_(void *cspice_state, integer *op, integer *ncols, integer *tabs, integer *cols, integer *elts, integer *senses, integer *sthan, integer *stsdsc, integer *stdtpt, integer *dtpool, integer *dtdscs, integer *sgvec1, integer *rwvec1, integer *sgvec2, integer *rwvec2);
/*:ref: lnknxt_ 4 2 4 4 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: zzekecmp_ 4 5 4 4 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern logical zzekvmch_(void *cspice_state, integer *ncnstr, logical *active, integer *lhans, integer *lsdscs, integer *lcdscs, integer *lrows, integer *lelts, integer *ops, integer *rhans, integer *rsdscs, integer *rcdscs, integer *rrows, integer *relts);
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: zzekecmp_ 4 5 4 4 4 4 4 */
/*:ref: zzekrsc_ 14 10 4 4 4 4 4 4 13 12 12 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errhan_ 14 3 13 4 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: matchi_ 12 8 13 13 13 13 124 124 124 124 */
 
extern int zzekweed_(void *cspice_state, integer *njrs, integer *bases, integer *nrows);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekvset_ 14 2 4 4 */
/*:ref: zzeksrd_ 14 3 4 4 4 */
/*:ref: sameai_ 12 3 4 4 4 */
/*:ref: zzeksupd_ 14 3 4 4 4 */
/*:ref: zzekjsqz_ 14 1 4 */
 
extern int zzekweqi_(void *cspice_state, char *name__, integer *value, integer *eqryi, ftnlen name_len);
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzekwpac_(void *cspice_state, integer *handle, integer *segdsc, integer *nvals, integer *l, char *cvals, integer *p, integer *base, ftnlen cvals_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzekacps_ 14 6 4 4 4 4 4 4 */
/*:ref: zzekpgwc_ 14 4 4 4 13 124 */
/*:ref: zzekslnk_ 14 4 4 4 4 4 */
 
extern int zzekwpai_(void *cspice_state, integer *handle, integer *segdsc, integer *nvals, integer *ivals, integer *p, integer *base);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekacps_ 14 6 4 4 4 4 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: zzekpgwi_ 14 3 4 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzekwpal_(void *cspice_state, integer *handle, integer *segdsc, integer *nvals, logical *lvals, integer *p, integer *base);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzekacps_ 14 6 4 4 4 4 4 4 */
/*:ref: zzekpgwc_ 14 4 4 4 13 124 */
/*:ref: zzekslnk_ 14 4 4 4 4 4 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzellbds_(void *cspice_state, doublereal *a, doublereal *b, doublereal *hmax, doublereal *hmin, doublereal *amax, doublereal *bmax, doublereal *amin, doublereal *bmin);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzelnaxx_(void *cspice_state, doublereal *a, doublereal *b, doublereal *lat, doublereal *xxpt, doublereal *yxpt);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ednmpt_ 14 5 7 7 7 7 7 */
 
extern int zzelvupy_(void *cspice_state, doublereal *ellips, doublereal *vertex, doublereal *axis, integer *n, doublereal *bounds, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: el2cgv_ 14 4 7 7 7 7 */
/*:ref: saelgv_ 14 4 7 7 7 7 */
/*:ref: vzero_ 12 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: cgv2el_ 14 4 7 7 7 7 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: pi_ 7 0 */
/*:ref: ucrss_ 14 3 7 7 7 */
/*:ref: repmot_ 14 9 13 13 4 13 13 124 124 124 124 */
/*:ref: vdist_ 7 2 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: nvp2pl_ 14 3 7 7 7 */
/*:ref: inrypl_ 14 5 7 7 7 4 7 */
/*:ref: zzwind_ 4 4 7 4 7 7 */
/*:ref: psv2pl_ 14 4 7 7 7 7 */
/*:ref: inelpl_ 14 5 7 7 4 7 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
 
extern int zzenut80_(void *cspice_state, doublereal *et, doublereal *nutxf);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzwahr_ 14 2 7 7 */
/*:ref: zzmobliq_ 14 3 7 7 7 */
/*:ref: eul2xf_ 14 5 7 4 4 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzeprc76_(void *cspice_state, doublereal *et, doublereal *precxf);
/*:ref: jyear_ 7 0 */
/*:ref: rpd_ 7 0 */
/*:ref: eul2xf_ 14 5 7 4 4 4 7 */
 
extern int zzeprcss_(void *cspice_state, doublereal *et, doublereal *precm);
/*:ref: jyear_ 7 0 */
/*:ref: rpd_ 7 0 */
/*:ref: eul2m_ 14 7 7 7 7 4 4 4 7 */
 
extern int zzfdat_(void *cspice_state, integer *ncount, integer *maxbfr, char *name__, integer *idcode, integer *center, integer *type__, integer *typid, integer *centrd, integer *bnmlst, integer *bnmpol, char *bnmnms, integer *bnmidx, integer *bidlst, integer *bidpol, integer *bidids, integer *bididx, ftnlen name_len, ftnlen bnmnms_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: irfnam_ 14 3 4 13 124 */
/*:ref: orderi_ 14 3 4 4 4 */
/*:ref: zzhscini_ 14 3 4 4 4 */
/*:ref: zzhsiini_ 14 3 4 4 4 */
/*:ref: zzhscadd_ 14 8 4 4 13 13 4 12 124 124 */
/*:ref: zzhsiadd_ 14 6 4 4 4 4 4 12 */
 
extern int zzfovaxi_(void *cspice_state, char *inst, integer *n, doublereal *bounds, doublereal *axis, ftnlen inst_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: vzero_ 12 1 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vsclip_ 14 2 7 7 */
/*:ref: halfpi_ 7 0 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: zzhullax_ 14 5 13 4 7 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: vhatip_ 14 1 7 */
 
extern int zzfrmch0_(void *cspice_state, integer *frame1, integer *frame2, doublereal *et, doublereal *xform);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzfrmgt0_ 14 5 4 7 7 4 12 */
/*:ref: zzmsxf_ 14 3 7 4 7 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: zznofcon_ 14 7 7 4 4 4 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: invstm_ 14 2 7 7 */
 
extern int zzfrmch1_(void *cspice_state, integer *frame1, integer *frame2, doublereal *et, doublereal *xform);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzfrmgt1_ 14 5 4 7 7 4 12 */
/*:ref: zzmsxf_ 14 3 7 4 7 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: zznofcon_ 14 7 7 4 4 4 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: invstm_ 14 2 7 7 */
 
extern int zzfrmgt0_(void *cspice_state, integer *infrm, doublereal *et, doublereal *xform, integer *outfrm, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: tisbod_ 14 5 13 4 7 7 124 */
/*:ref: invstm_ 14 2 7 7 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: irfrot_ 14 3 4 4 7 */
/*:ref: ckfxfm_ 14 5 4 7 7 4 12 */
/*:ref: tkfram_ 14 4 4 7 4 12 */
/*:ref: zzdynfr0_ 14 5 4 4 7 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: failed_ 12 0 */
 
extern int zzfrmgt1_(void *cspice_state, integer *infrm, doublereal *et, doublereal *xform, integer *outfrm, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: tisbod_ 14 5 13 4 7 7 124 */
/*:ref: invstm_ 14 2 7 7 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: irfrot_ 14 3 4 4 7 */
/*:ref: ckfxfm_ 14 5 4 7 7 4 12 */
/*:ref: tkfram_ 14 4 4 7 4 12 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: failed_ 12 0 */
 
extern int zzftpchk_(void *cspice_state, char *string, logical *ftperr, ftnlen string_len);
/*:ref: zzftpstr_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: zzrbrkst_ 14 10 13 13 13 13 4 12 124 124 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: pos_ 4 5 13 13 4 124 124 */
 
extern int zzftpstr_(void *cspice_state, char *tstcom, char *lend, char *rend, char *delim, ftnlen tstcom_len, ftnlen lend_len, ftnlen rend_len, ftnlen delim_len);
/*:ref: suffix_ 14 5 13 4 13 124 124 */
 
extern int zzgapool_(void *cspice_state, char *varnam, char *wtvars, integer *wtptrs, integer *wtpool, char *wtagnt, char *agtset, ftnlen varnam_len, ftnlen wtvars_len, ftnlen wtagnt_len, ftnlen agtset_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: scardc_ 14 3 4 13 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lnknxt_ 4 2 4 4 */
/*:ref: validc_ 14 4 4 4 13 124 */
/*:ref: sizec_ 4 2 13 124 */
 
extern int zzgetbff_(void *cspice_state, integer *bffid);
 
extern int zzgetelm_(void *cspice_state, integer *frstyr, char *lines, doublereal *epoch, doublereal *elems, logical *ok, char *error, ftnlen lines_len, ftnlen error_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: rpd_ 7 0 */
/*:ref: twopi_ 7 0 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: nparsi_ 14 6 13 4 13 4 124 124 */
/*:ref: nparsd_ 14 6 13 7 13 4 124 124 */
/*:ref: repmd_ 14 8 13 13 7 4 13 124 124 124 */
/*:ref: ttrans_ 14 5 13 13 7 124 124 */
 
extern int zzgetvox_(void *cspice_state, doublereal *voxsiz, doublereal *voxori, integer *nvox, doublereal *xyz, logical *inbox, integer *voxcor);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzgfcoq_(void *cspice_state, char *vecdef, char *method, integer *trgid, doublereal *et, char *ref, char *abcorr, integer *obsid, char *dref, doublereal *dvec, char *crdsys, integer *ctrid, doublereal *re, doublereal *f, char *crdnam, doublereal *value, logical *found, ftnlen vecdef_len, ftnlen method_len, ftnlen ref_len, ftnlen abcorr_len, ftnlen dref_len, ftnlen crdsys_len, ftnlen crdnam_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: bodc2s_ 14 3 4 13 124 */
/*:ref: spkezp_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: subpnt_ 14 14 13 13 7 13 13 13 7 7 7 124 124 124 124 124 */
/*:ref: sincpt_ 14 18 13 13 7 13 13 13 13 7 7 7 7 12 124 124 124 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: reclat_ 14 4 7 7 7 7 */
/*:ref: recrad_ 14 4 7 7 7 7 */
/*:ref: recsph_ 14 4 7 7 7 7 */
/*:ref: reccyl_ 14 4 7 7 7 7 */
/*:ref: recgeo_ 14 6 7 7 7 7 7 7 */
/*:ref: recpgr_ 14 8 13 7 7 7 7 7 7 124 */
 
extern int zzgfcost_(void *cspice_state, char *vecdef, char *method, integer *trgid, doublereal *et, char *ref, char *abcorr, integer *obsid, char *dref, integer *dctr, doublereal *dvec, doublereal *radii, doublereal *state, logical *found, ftnlen vecdef_len, ftnlen method_len, ftnlen ref_len, ftnlen abcorr_len, ftnlen dref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: spkez_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: zzgfssob_ 14 11 13 4 7 13 13 4 7 7 124 124 124 */
/*:ref: zzgfssin_ 14 16 13 4 7 13 13 4 13 4 7 7 7 12 124 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzgfcou_(void *cspice_state, char *vecdef, char *method, char *target, doublereal *et, char *ref, char *abcorr, char *obsrvr, char *dref, doublereal *dvec, char *crdsys, char *crdnam, logical *decres, doublereal *crdval, logical *crdfnd, U_fp udfunc, ftnlen vecdef_len, ftnlen method_len, ftnlen target_len, ftnlen ref_len, ftnlen abcorr_len, ftnlen obsrvr_len, ftnlen dref_len, ftnlen crdsys_len, ftnlen crdnam_len);
extern int zzgfcoin_(void *cspice_state, char *vecdef, char *method, char *target, char *ref, char *abcorr, char *obsrvr, char *dref, doublereal *dvec, char *crdsys, char *crdnam, ftnlen vecdef_len, ftnlen method_len, ftnlen target_len, ftnlen ref_len, ftnlen abcorr_len, ftnlen obsrvr_len, ftnlen dref_len, ftnlen crdsys_len, ftnlen crdnam_len);
extern int zzgfcog_(void *cspice_state, doublereal *et, doublereal *crdval);
extern int zzgfcodc_(void *cspice_state, U_fp udfunc, doublereal *et, logical *decres);
extern int zzgfcoex_(void *cspice_state, U_fp udfunc, doublereal *et, logical *crdfnd);
extern int zzgfcocg_(void *cspice_state, doublereal *et, doublereal *crdval);
extern int zzgfcosg_(void *cspice_state, doublereal *et, doublereal *crdval);
extern int zzgfcocd_(void *cspice_state, U_fp udfunc, doublereal *et, logical *decres);
extern int zzgfcosd_(void *cspice_state, U_fp udfunc, doublereal *et, logical *decres);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: bods2c_ 14 4 13 4 12 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: bodfnd_ 12 3 4 13 124 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: bodc2s_ 14 3 4 13 124 */
/*:ref: recpgr_ 14 8 13 7 7 7 7 7 7 124 */
/*:ref: pi_ 7 0 */
/*:ref: vzero_ 12 1 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: zzgfcoq_ 14 23 13 13 4 7 13 13 4 13 7 13 4 7 7 13 7 12 124 124 124 124 124 124 124 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: zzgfcost_ 14 18 13 13 4 7 13 13 4 13 4 7 7 7 12 124 124 124 124 124 */
/*:ref: zzgfcprx_ 14 7 7 13 7 7 4 4 124 */
/*:ref: reclat_ 14 4 7 7 7 7 */
/*:ref: recrad_ 14 4 7 7 7 7 */
/*:ref: recsph_ 14 4 7 7 7 7 */
/*:ref: reccyl_ 14 4 7 7 7 7 */
/*:ref: recgeo_ 14 6 7 7 7 7 7 7 */
 
extern int zzgfcprx_(void *cspice_state, doublereal *state, char *corsys, doublereal *re, doublereal *f, integer *sense, integer *cdsign, ftnlen corsys_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vzero_ 12 1 7 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: recgeo_ 14 6 7 7 7 7 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: latrec_ 14 4 7 7 7 7 */
/*:ref: vpack_ 14 4 7 7 7 7 */
/*:ref: vhatip_ 14 1 7 */
/*:ref: zzrtnmat_ 14 2 7 7 */
/*:ref: mxv_ 14 3 7 7 7 */
 
extern int zzgfcslv_(void *cspice_state, char *vecdef, char *method, char *target, char *ref, char *abcorr, char *obsrvr, char *dref, doublereal *dvec, char *crdsys, char *crdnam, char *relate, doublereal *refval, doublereal *tol, doublereal *adjust, U_fp udstep, U_fp udrefn, logical *rpt, S_fp udrepi, U_fp udrepu, S_fp udrepf, logical *bail, L_fp udbail, integer *mw, integer *nw, doublereal *work, doublereal *cnfine, doublereal *result, ftnlen vecdef_len, ftnlen method_len, ftnlen target_len, ftnlen ref_len, ftnlen abcorr_len, ftnlen obsrvr_len, ftnlen dref_len, ftnlen crdsys_len, ftnlen crdnam_len, ftnlen relate_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: ssized_ 14 2 4 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: zzgfcoin_ 14 19 13 13 13 13 13 13 13 7 13 13 124 124 124 124 124 124 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: wncard_ 4 1 7 */
/*:ref: wnfetd_ 14 4 7 4 7 7 */
/*:ref: zzgfsolvx_ 14 14 200 200 200 200 12 212 12 7 7 7 7 12 200 7 */
/*:ref: wncond_ 14 3 7 7 7 */
/*:ref: copyd_ 14 2 7 7 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: zzgflong_ 14 37 13 13 13 13 13 13 13 7 13 13 13 7 7 7 200 200 12 214 200 214 12 212 4 4 7 7 7 124 124 124 124 124 124 124 124 124 124 */
/*:ref: zzgfrelx_ 14 25 200 200 200 200 200 13 7 7 7 7 4 4 7 12 214 200 214 13 13 12 212 7 124 124 124 */
 
extern int zzgfdiq_(void *cspice_state, integer *targid, doublereal *et, char *abcorr, integer *obsid, doublereal *dist, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: spkezp_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vnorm_ 7 1 7 */
 
extern int zzgfdiu_(void *cspice_state, char *target, char *abcorr, char *obsrvr, U_fp udfunc, doublereal *et, logical *decres, doublereal *dist, ftnlen target_len, ftnlen abcorr_len, ftnlen obsrvr_len);
extern int zzgfdiin_(void *cspice_state, char *target, char *abcorr, char *obsrvr, ftnlen target_len, ftnlen abcorr_len, ftnlen obsrvr_len);
extern int zzgfdidc_(void *cspice_state, U_fp udfunc, doublereal *et, logical *decres);
extern int zzgfdigq_(void *cspice_state, doublereal *et, doublereal *dist);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: return_ 12 0 */
/*:ref: bods2c_ 14 4 13 4 12 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: spkez_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: zzgfdiq_ 14 6 4 7 13 4 7 124 */
 
extern int zzgfdsps_(void *cspice_state, integer *nlead, char *string, char *fmt, integer *ntrail, ftnlen string_len, ftnlen fmt_len);
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzgffvu_(void *cspice_state, char *inst, char *tshape, doublereal *raydir, char *target, char *tframe, char *abcorr, char *obsrvr, doublereal *time, logical *vistat, ftnlen inst_len, ftnlen tshape_len, ftnlen target_len, ftnlen tframe_len, ftnlen abcorr_len, ftnlen obsrvr_len);
extern int zzgffvin_(void *cspice_state, char *inst, char *tshape, doublereal *raydir, char *target, char *tframe, char *abcorr, char *obsrvr, ftnlen inst_len, ftnlen tshape_len, ftnlen target_len, ftnlen tframe_len, ftnlen abcorr_len, ftnlen obsrvr_len);
extern int zzgffvst_(void *cspice_state, doublereal *time, logical *vistat);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: return_ 12 0 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: bods2c_ 14 4 13 4 12 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zzprscor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: vzero_ 12 1 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: getfov_ 14 9 4 4 13 13 7 4 7 124 124 */
/*:ref: zzfovaxi_ 14 5 13 4 7 7 124 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: halfpi_ 7 0 */
/*:ref: dpr_ 7 0 */
/*:ref: nvc2pl_ 14 3 7 7 7 */
/*:ref: vrotv_ 14 4 7 7 7 7 */
/*:ref: inrypl_ 14 5 7 7 7 4 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: vscl_ 14 3 7 7 7 */
/*:ref: ucrss_ 14 3 7 7 7 */
/*:ref: frame_ 14 3 7 7 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: spkezp_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: zzcorepc_ 14 5 13 7 7 7 124 */
/*:ref: pxform_ 14 6 13 13 7 7 124 124 */
/*:ref: mxm_ 14 3 7 7 7 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: edlimb_ 14 5 7 7 7 7 7 */
/*:ref: el2cgv_ 14 4 7 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: cgv2el_ 14 4 7 7 7 7 */
/*:ref: zzelvupy_ 14 6 7 7 7 4 7 12 */
/*:ref: zzocced_ 4 5 7 7 7 7 7 */
/*:ref: spkssb_ 14 5 4 7 13 7 124 */
/*:ref: stlabx_ 14 3 7 7 7 */
/*:ref: stelab_ 14 3 7 7 7 */
/*:ref: mtxv_ 14 3 7 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: zzwind2d_ 4 3 4 7 7 */
 
extern int zzgfilu_(void *cspice_state, char *method, char *angtyp, char *target, char *illum, char *fixref, char *abcorr, char *obsrvr, doublereal *spoint, doublereal *et, U_fp udfunc, logical *decres, doublereal *angle, ftnlen method_len, ftnlen angtyp_len, ftnlen target_len, ftnlen illum_len, ftnlen fixref_len, ftnlen abcorr_len, ftnlen obsrvr_len);
extern int zzgfilin_(void *cspice_state, char *method, char *angtyp, char *target, char *illum, char *fixref, char *abcorr, char *obsrvr, doublereal *spoint, ftnlen method_len, ftnlen angtyp_len, ftnlen target_len, ftnlen illum_len, ftnlen fixref_len, ftnlen abcorr_len, ftnlen obsrvr_len);
extern int zzgfildc_(void *cspice_state, U_fp udfunc, doublereal *et, logical *decres);
extern int zzgfilgq_(void *cspice_state, doublereal *et, doublereal *angle);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: return_ 12 0 */
/*:ref: bods2c_ 14 4 13 4 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: bodvrd_ 14 7 13 13 4 4 7 124 124 */
/*:ref: surfnm_ 14 5 7 7 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: esrchc_ 4 5 13 4 13 124 124 */
/*:ref: zzilusta_ 14 18 13 13 13 7 13 13 13 7 7 7 7 7 124 124 124 124 124 124 */
/*:ref: illumg_ 14 19 13 13 13 7 13 13 13 7 7 7 7 7 7 124 124 124 124 124 124 */
 
extern int zzgflong_(void *cspice_state, char *vecdef, char *method, char *target, char *ref, char *abcorr, char *obsrvr, char *dref, doublereal *dvec, char *crdsys, char *crdnam, char *relate, doublereal *refval, doublereal *tol, doublereal *adjust, U_fp udstep, U_fp udrefn, logical *rpt, U_fp udrepi, U_fp udrepu, U_fp udrepf, logical *bail, L_fp udbail, integer *mw, integer *nw, doublereal *work, doublereal *cnfine, doublereal *result, ftnlen vecdef_len, ftnlen method_len, ftnlen target_len, ftnlen ref_len, ftnlen abcorr_len, ftnlen obsrvr_len, ftnlen dref_len, ftnlen crdsys_len, ftnlen crdnam_len, ftnlen relate_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ssized_ 14 2 4 7 */
/*:ref: lnkini_ 14 2 4 4 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: zzgfcoin_ 14 19 13 13 13 13 13 13 13 7 13 13 124 124 124 124 124 124 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: wncard_ 4 1 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: copyd_ 14 2 7 7 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: bodc2s_ 14 3 4 13 124 */
/*:ref: recpgr_ 14 8 13 7 7 7 7 7 7 124 */
/*:ref: pi_ 7 0 */
/*:ref: twopi_ 7 0 */
/*:ref: lnkan_ 14 2 4 4 */
/*:ref: zzgfrelx_ 14 25 200 200 200 200 214 13 7 7 7 7 4 4 7 12 200 200 200 13 13 12 212 7 124 124 124 */
/*:ref: zzgfcosg_ 14 2 7 7 */
/*:ref: zzgfcocg_ 14 2 7 7 */
/*:ref: cardd_ 4 1 7 */
/*:ref: smsgnd_ 12 2 7 7 */
/*:ref: wninsd_ 14 3 7 7 7 */
/*:ref: wndifd_ 14 3 7 7 7 */
/*:ref: zzgfcog_ 14 2 7 7 */
/*:ref: wnunid_ 14 3 7 7 7 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: lnkila_ 14 3 4 4 4 */
/*:ref: wnintd_ 14 3 7 7 7 */
/*:ref: ssizei_ 14 2 4 4 */
/*:ref: insrti_ 14 2 4 4 */
/*:ref: lnknxt_ 4 2 4 4 */
/*:ref: elemi_ 12 2 4 4 */
/*:ref: lnkfsl_ 14 3 4 4 4 */
 
extern int zzgfocu_(void *cspice_state, char *occtyp, char *front, char *fshape, char *fframe, char *back, char *bshape, char *bframe, char *obsrvr, char *abcorr, doublereal *time, logical *ocstat, ftnlen occtyp_len, ftnlen front_len, ftnlen fshape_len, ftnlen fframe_len, ftnlen back_len, ftnlen bshape_len, ftnlen bframe_len, ftnlen obsrvr_len, ftnlen abcorr_len);
extern int zzgfocin_(void *cspice_state, char *occtyp, char *front, char *fshape, char *fframe, char *back, char *bshape, char *bframe, char *obsrvr, char *abcorr, ftnlen occtyp_len, ftnlen front_len, ftnlen fshape_len, ftnlen fframe_len, ftnlen back_len, ftnlen bshape_len, ftnlen bframe_len, ftnlen obsrvr_len, ftnlen abcorr_len);
extern int zzgfocst_(void *cspice_state, doublereal *time, logical *ocstat);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: return_ 12 0 */
/*:ref: bods2c_ 14 4 13 4 12 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: zzprsmet_ 14 15 4 13 4 13 13 12 4 4 13 13 124 124 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: minad_ 14 4 7 4 7 4 */
/*:ref: maxad_ 14 4 7 4 7 4 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: zzsudski_ 14 4 4 4 4 4 */
/*:ref: zzminrad_ 14 1 7 */
/*:ref: zzmaxrad_ 14 1 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: spkezp_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: zzcorepc_ 14 5 13 7 7 7 124 */
/*:ref: pxform_ 14 6 13 13 7 7 124 124 */
/*:ref: vscl_ 14 3 7 7 7 */
/*:ref: zzocced_ 4 5 7 7 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: dasine_ 7 2 7 7 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: halfpi_ 7 0 */
/*:ref: sincpt_ 14 18 13 13 7 13 13 13 13 7 7 7 7 12 124 124 124 124 124 124 */
 
extern int zzgfpaq_(void *cspice_state, doublereal *et, integer *targ, integer *illmn, integer *obs, char *abcorr, doublereal *value, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: spkezp_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: pi_ 7 0 */
 
extern int zzgfpau_(void *cspice_state, char *target, char *illmn, char *abcorr, char *obsrvr, U_fp udfunc, doublereal *et, logical *decres, doublereal *rvl, integer *xtarg, integer *xillmn, char *xabcor, integer *xobs, logical *xablk, ftnlen target_len, ftnlen illmn_len, ftnlen abcorr_len, ftnlen obsrvr_len, ftnlen xabcor_len);
extern int zzgfpain_(void *cspice_state, char *target, char *illmn, char *abcorr, char *obsrvr, ftnlen target_len, ftnlen illmn_len, ftnlen abcorr_len, ftnlen obsrvr_len);
extern int zzgfpadc_(void *cspice_state, U_fp udfunc, doublereal *et, logical *decres);
extern int zzgfpagq_(void *cspice_state, doublereal *et, doublereal *rvl);
extern int zzgfpax_(void *cspice_state, integer *xtarg, integer *xillmn, char *xabcor, integer *xobs, logical *xablk, ftnlen xabcor_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: return_ 12 0 */
/*:ref: bods2c_ 14 4 13 4 12 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: spkez_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: clight_ 7 0 */
/*:ref: vsclip_ 14 2 7 7 */
/*:ref: dvsep_ 7 2 7 7 */
/*:ref: zzgfpaq_ 14 7 7 4 4 4 13 7 124 */
 
extern int zzgfref_(void *cspice_state, doublereal *refval);
/*:ref: zzholdd_ 14 4 4 4 12 7 */
 
extern int zzgfrel_(void *cspice_state, U_fp udstep, U_fp udrefn, U_fp udqdec, U_fp udcond, S_fp udfunc, S_fp udqref, char *relate, doublereal *refval, doublereal *tol, doublereal *adjust, doublereal *cnfine, integer *mw, integer *nw, doublereal *work, logical *rpt, S_fp udrepi, U_fp udrepu, S_fp udrepf, char *rptpre, char *rptsuf, logical *bail, L_fp udbail, doublereal *result, ftnlen relate_len, ftnlen rptpre_len, ftnlen rptsuf_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: ssized_ 14 2 4 7 */
/*:ref: failed_ 12 0 */
/*:ref: copyd_ 14 2 7 7 */
/*:ref: wnexpd_ 14 3 7 7 7 */
/*:ref: wncard_ 4 1 7 */
/*:ref: wnfetd_ 14 4 7 4 7 7 */
/*:ref: zzgfsolv_ 14 13 200 200 200 12 212 12 7 7 7 7 12 200 7 */
/*:ref: wnextd_ 14 3 13 7 124 */
/*:ref: zzgfwsts_ 14 5 7 7 13 7 124 */
/*:ref: wnintd_ 14 3 7 7 7 */
/*:ref: wndifd_ 14 3 7 7 7 */
/*:ref: zzwninsd_ 14 5 7 7 13 7 124 */
/*:ref: swapi_ 14 2 4 4 */
 
extern int zzgfrelx_(void *cspice_state, U_fp udstep, U_fp udrefn, U_fp udqdec, U_fp udcond, S_fp udfunc, char *relate, doublereal *refval, doublereal *tol, doublereal *adjust, doublereal *cnfine, integer *mw, integer *nw, doublereal *work, logical *rpt, S_fp udrepi, U_fp udrepu, S_fp udrepf, char *rptpre, char *rptsuf, logical *bail, L_fp udbail, doublereal *result, ftnlen relate_len, ftnlen rptpre_len, ftnlen rptsuf_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: ssized_ 14 2 4 7 */
/*:ref: failed_ 12 0 */
/*:ref: copyd_ 14 2 7 7 */
/*:ref: wnexpd_ 14 3 7 7 7 */
/*:ref: zzgfref_ 14 1 7 */
/*:ref: wncard_ 4 1 7 */
/*:ref: wnfetd_ 14 4 7 4 7 7 */
/*:ref: zzgfsolvx_ 14 14 214 200 200 200 12 212 12 7 7 7 7 12 200 7 */
/*:ref: wnextd_ 14 3 13 7 124 */
/*:ref: zzgfwsts_ 14 5 7 7 13 7 124 */
/*:ref: wnintd_ 14 3 7 7 7 */
/*:ref: wndifd_ 14 3 7 7 7 */
/*:ref: zzwninsd_ 14 5 7 7 13 7 124 */
/*:ref: swapi_ 14 2 4 4 */
 
extern int zzgfrpwk_(void *cspice_state, integer *unit, doublereal *total, doublereal *freq, integer *tcheck, char *begin, char *end, doublereal *incr, ftnlen begin_len, ftnlen end_len);
extern int zzgftswk_(void *cspice_state, doublereal *total, doublereal *freq, integer *tcheck, char *begin, char *end, ftnlen begin_len, ftnlen end_len);
extern int zzgfwkin_(void *cspice_state, doublereal *incr);
extern int zzgfwkad_(void *cspice_state, doublereal *freq, integer *tcheck, char *begin, char *end, ftnlen begin_len, ftnlen end_len);
extern int zzgfwkun_(void *cspice_state, integer *unit);
extern int zzgfwkmo_(void *cspice_state, integer *unit, doublereal *total, doublereal *freq, integer *tcheck, char *begin, char *end, doublereal *incr, ftnlen begin_len, ftnlen end_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: return_ 12 0 */
/*:ref: stdio_ 14 3 13 4 124 */
/*:ref: zzcputim_ 14 1 7 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: zzgfdsps_ 14 6 4 13 13 4 124 124 */
/*:ref: writln_ 14 3 13 4 124 */
/*:ref: brcktd_ 7 3 7 7 7 */
/*:ref: dpfmt_ 14 5 7 13 13 124 124 */
 
extern int zzgfrrq_(void *cspice_state, doublereal *et, integer *targ, integer *obs, char *abcorr, doublereal *value, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: spkez_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dvnorm_ 7 1 7 */
 
extern int zzgfrru_(void *cspice_state, char *target, char *abcorr, char *obsrvr, doublereal *dt, U_fp udfunc, doublereal *et, logical *decres, doublereal *rvl, integer *xtarg, char *xabcor, integer *xobs, doublereal *xdt, ftnlen target_len, ftnlen abcorr_len, ftnlen obsrvr_len, ftnlen xabcor_len);
extern int zzgfrrin_(void *cspice_state, char *target, char *abcorr, char *obsrvr, doublereal *dt, ftnlen target_len, ftnlen abcorr_len, ftnlen obsrvr_len);
extern int zzgfrrdc_(void *cspice_state, U_fp udfunc, doublereal *et, logical *decres);
extern int zzgfrrgq_(void *cspice_state, doublereal *et, doublereal *rvl);
extern int zzgfrrx_(void *cspice_state, integer *xtarg, char *xabcor, integer *xobs, doublereal *xdt, ftnlen xabcor_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: return_ 12 0 */
/*:ref: bods2c_ 14 4 13 4 12 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: spkez_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: qderiv_ 14 5 4 7 7 7 7 */
/*:ref: dvhat_ 14 2 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: zzgfrrq_ 14 6 7 4 4 13 7 124 */
 
extern int zzgfsolv_(void *cspice_state, S_fp udcond, S_fp udstep, S_fp udrefn, logical *bail, L_fp udbail, logical *cstep, doublereal *step, doublereal *start, doublereal *finish, doublereal *tol, logical *rpt, S_fp udrepu, doublereal *result);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: dpmax_ 7 0 */
/*:ref: touchd_ 7 1 7 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: brcktd_ 7 3 7 7 7 */
/*:ref: zzwninsd_ 14 5 7 7 13 7 124 */
 
extern int zzgfsolvx_(void *cspice_state, U_fp udfuns, S_fp udfunb, S_fp udstep, S_fp udrefn, logical *bail, L_fp udbail, logical *cstep, doublereal *step, doublereal *start, doublereal *finish, doublereal *tol, logical *rpt, S_fp udrepu, doublereal *result);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: dpmax_ 7 0 */
/*:ref: touchd_ 7 1 7 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: brcktd_ 7 3 7 7 7 */
/*:ref: zzwninsd_ 14 5 7 7 13 7 124 */
 
extern int zzgfspq_(void *cspice_state, doublereal *et, integer *targ1, integer *targ2, doublereal *r1, doublereal *r2, integer *obs, char *abcorr, char *ref, doublereal *value, ftnlen abcorr_len, ftnlen ref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: spkezp_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: dasine_ 7 2 7 7 */
/*:ref: halfpi_ 7 0 */
/*:ref: vsep_ 7 2 7 7 */
 
extern int zzgfspu_(void *cspice_state, char *of, char *from, char *shape, char *frame, doublereal *et, U_fp udfunc, char *abcorr, logical *decres, doublereal *sep, char *xabcr, integer *xbod, char *yref, char *xref, integer *xobs, doublereal *xrad, integer *xshp, ftnlen of_len, ftnlen from_len, ftnlen shape_len, ftnlen frame_len, ftnlen abcorr_len, ftnlen xabcr_len, ftnlen yref_len, ftnlen xref_len);
extern int zzgfspin_(void *cspice_state, char *of, char *from, char *shape, char *frame, char *abcorr, ftnlen of_len, ftnlen from_len, ftnlen shape_len, ftnlen frame_len, ftnlen abcorr_len);
extern int zzgfspdc_(void *cspice_state, U_fp udfunc, doublereal *et, logical *decres);
extern int zzgfspgq_(void *cspice_state, doublereal *et, doublereal *sep);
extern int zzgfspx_(void *cspice_state, char *xabcr, integer *xbod, char *yref, char *xref, integer *xobs, doublereal *xrad, integer *xshp, ftnlen xabcr_len, ftnlen yref_len, ftnlen xref_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: return_ 12 0 */
/*:ref: bods2c_ 14 4 13 4 12 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: zzgftreb_ 14 2 4 7 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: spkez_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: dvsep_ 7 2 7 7 */
/*:ref: dhfa_ 7 2 7 7 */
/*:ref: zzgfspq_ 14 11 7 4 4 7 7 4 13 13 7 124 124 */
 
extern int zzgfssin_(void *cspice_state, char *method, integer *trgid, doublereal *et, char *fixref, char *abcorr, integer *obsid, char *dref, integer *dctr, doublereal *dvec, doublereal *radii, doublereal *state, logical *found, ftnlen method_len, ftnlen fixref_len, ftnlen abcorr_len, ftnlen dref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: bodc2s_ 14 3 4 13 124 */
/*:ref: zzprscor_ 14 3 13 12 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sxform_ 14 6 13 13 7 7 124 124 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: mxvg_ 14 5 7 7 4 4 7 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: failed_ 12 0 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: spkgeo_ 14 7 4 7 13 4 7 7 124 */
/*:ref: vminug_ 14 3 7 4 7 */
/*:ref: surfpv_ 14 7 7 7 7 7 7 7 12 */
/*:ref: spkacs_ 14 10 4 7 13 13 4 7 7 7 124 124 */
/*:ref: zzcorsxf_ 14 4 12 7 7 7 */
/*:ref: sincpt_ 14 18 13 13 7 13 13 13 13 7 7 7 7 12 124 124 124 124 124 124 */
/*:ref: spkssb_ 14 5 4 7 13 7 124 */
/*:ref: qderiv_ 14 5 4 7 7 7 7 */
/*:ref: vscl_ 14 3 7 7 7 */
/*:ref: vsubg_ 14 4 7 7 4 7 */
/*:ref: invstm_ 14 2 7 7 */
/*:ref: vaddg_ 14 4 7 7 4 7 */
/*:ref: zzstelab_ 14 6 12 7 7 7 7 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: clight_ 7 0 */
 
extern int zzgfssob_(void *cspice_state, char *method, integer *trgid, doublereal *et, char *fixref, char *abcorr, integer *obsid, doublereal *radii, doublereal *state, ftnlen method_len, ftnlen fixref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: bodc2s_ 14 3 4 13 124 */
/*:ref: zzprscor_ 14 3 13 12 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: failed_ 12 0 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: spkgeo_ 14 7 4 7 13 4 7 7 124 */
/*:ref: vminug_ 14 3 7 4 7 */
/*:ref: dnearp_ 14 7 7 7 7 7 7 7 12 */
/*:ref: surfpv_ 14 7 7 7 7 7 7 7 12 */
/*:ref: subpnt_ 14 14 13 13 7 13 13 13 7 7 7 124 124 124 124 124 */
/*:ref: spkssb_ 14 5 4 7 13 7 124 */
/*:ref: sxform_ 14 6 13 13 7 7 124 124 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: qderiv_ 14 5 4 7 7 7 7 */
/*:ref: vscl_ 14 3 7 7 7 */
/*:ref: vsubg_ 14 4 7 7 4 7 */
/*:ref: zzcorsxf_ 14 4 12 7 7 7 */
/*:ref: invstm_ 14 2 7 7 */
/*:ref: mxvg_ 14 5 7 7 4 4 7 */
/*:ref: vaddg_ 14 4 7 7 4 7 */
/*:ref: zzstelab_ 14 6 12 7 7 7 7 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: clight_ 7 0 */
 
extern int zzgftreb_(void *cspice_state, integer *body, doublereal *axes);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzgfudb_(void *cspice_state, U_fp udfuns, U_fp udfunb, doublereal *tol, U_fp udstep, U_fp udrefn, logical *rpt, S_fp udrepi, U_fp udrepu, S_fp udrepf, logical *bail, L_fp udbail, doublereal *cnfine, doublereal *result);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: wncard_ 4 1 7 */
/*:ref: wnfetd_ 14 4 7 4 7 7 */
/*:ref: zzgfsolvx_ 14 14 200 200 200 200 12 212 12 7 7 7 7 12 200 7 */
/*:ref: failed_ 12 0 */
 
extern int zzgfudlt_(void *cspice_state, S_fp udfunc, doublereal *et, logical *isless);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzholdd_ 14 4 4 4 12 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern int zzgfwsts_(void *cspice_state, doublereal *wndw1, doublereal *wndw2, char *inclsn, doublereal *wndw3, ftnlen inclsn_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: ssized_ 14 2 4 7 */
/*:ref: cardd_ 4 1 7 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: scardd_ 14 2 4 7 */
 
extern int zzgpnm_(void *cspice_state, integer *namlst, integer *nmpool, char *names, integer *datlst, integer *dppool, doublereal *dpvals, integer *chpool, char *chvals, char *varnam, logical *found, integer *lookat, integer *nameat, ftnlen names_len, ftnlen chvals_len, ftnlen varnam_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzhash_ 4 2 13 124 */
/*:ref: lnknfn_ 4 1 4 */
/*:ref: lnkan_ 14 2 4 4 */
/*:ref: lnkila_ 14 3 4 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzgrav_(void *cspice_state, doublereal *grav);
 
extern integer zzhashi_(void *cspice_state, integer *n, integer *m);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzholdd_(void *cspice_state, integer *op, integer *id, logical *ok, doublereal *value);
/*:ref: return_ 12 0 */
/*:ref: brckti_ 4 3 4 4 4 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzhsc_(void *cspice_state, integer *hashsz, integer *hedlst, integer *collst, char *items, char *item, integer *itemat, logical *new__, integer *avail, ftnlen items_len, ftnlen item_len);
extern int zzhscini_(void *cspice_state, integer *hashsz, integer *hedlst, integer *collst);
extern int zzhscadd_(void *cspice_state, integer *hedlst, integer *collst, char *items, char *item, integer *itemat, logical *new__, ftnlen items_len, ftnlen item_len);
extern int zzhscchk_(void *cspice_state, integer *hedlst, integer *collst, char *items, char *item, integer *itemat, ftnlen items_len, ftnlen item_len);
extern int zzhscavl_(void *cspice_state, integer *collst, integer *avail);
extern int zzhscinf_(void *cspice_state, integer *hedlst, integer *collst, char *items, char *item, integer *avail, ftnlen items_len, ftnlen item_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzhash2_ 4 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
 
extern int zzhsi_(void *cspice_state, integer *hashsz, integer *hedlst, integer *collst, integer *items, integer *item, char *param, integer *itemat, logical *new__, integer *avail, ftnlen param_len);
extern int zzhsiini_(void *cspice_state, integer *hashsz, integer *hedlst, integer *collst);
extern int zzhsiadd_(void *cspice_state, integer *hedlst, integer *collst, integer *items, integer *item, integer *itemat, logical *new__);
extern int zzhsichk_(void *cspice_state, integer *hedlst, integer *collst, integer *items, integer *item, integer *itemat);
extern int zzhsiavl_(void *cspice_state, integer *collst, integer *avail);
extern int zzhsiinf_(void *cspice_state, integer *hedlst, integer *collst, integer *items, char *param, integer *avail, ftnlen param_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzhashi_ 4 2 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
 
extern int zzhullax_(void *cspice_state, char *inst, integer *n, doublereal *bounds, doublereal *axis, ftnlen inst_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: vzero_ 12 1 7 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: halfpi_ 7 0 */
/*:ref: vsclip_ 14 2 7 7 */
/*:ref: pi_ 7 0 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: vhatip_ 14 1 7 */
/*:ref: ucrss_ 14 3 7 7 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: reclat_ 14 4 7 7 7 7 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: vrotv_ 14 4 7 7 7 7 */
 
extern int zzidmap_(void *cspice_state, integer *bltcod, char *bltnam, ftnlen bltnam_len);
 
extern int zzilusta_(void *cspice_state, char *method, char *target, char *illum, doublereal *et, char *fixref, char *abcorr, char *obsrvr, doublereal *spoint, doublereal *normal, doublereal *phssta, doublereal *incsta, doublereal *emista, ftnlen method_len, ftnlen target_len, ftnlen illum_len, ftnlen fixref_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vzero_ 12 1 7 */
/*:ref: spkcpt_ 14 16 7 13 13 7 13 13 13 13 7 7 124 124 124 124 124 124 */
/*:ref: zzcorepc_ 14 5 13 7 7 7 124 */
/*:ref: spkcpo_ 14 16 13 7 13 13 13 7 13 13 7 7 124 124 124 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: sxform_ 14 6 13 13 7 7 124 124 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: clight_ 7 0 */
/*:ref: zzcorsxf_ 14 4 12 7 7 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: mxvg_ 14 5 7 7 4 4 7 */
/*:ref: vsclip_ 14 2 7 7 */
/*:ref: vminug_ 14 3 7 4 7 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: dvsep_ 7 2 7 7 */
 
extern logical zzingrd_(void *cspice_state, integer *nvox, integer *voxel);
 
extern int zzinil_(void *cspice_state, doublereal *geophs, integer *opmode, doublereal *ecco, doublereal *epoch, doublereal *inclo, doublereal *no, doublereal *ainv, doublereal *ao, doublereal *con41, doublereal *con42, doublereal *cosio, doublereal *cosio2, doublereal *eccsq, doublereal *omeosq, doublereal *posq, doublereal *rp, doublereal *rteosq, doublereal *sinio, doublereal *gsto);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: twopi_ 7 0 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzinilnk_(void *cspice_state, integer *maxp, integer *maxc, integer *ncell, integer *pntrs, integer *cells);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzinlat_(void *cspice_state, doublereal *p, doublereal *bounds, doublereal *margin, integer *exclud, logical *inside);
/*:ref: return_ 12 0 */
/*:ref: twopi_ 7 0 */
/*:ref: halfpi_ 7 0 */
/*:ref: reclat_ 14 4 7 7 7 7 */
/*:ref: zzinlat0_ 14 6 7 7 7 7 4 12 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zznrmlon_ 14 5 7 7 7 7 7 */
 
extern int zzinlat0_(void *cspice_state, doublereal *r__, doublereal *lon, doublereal *lat, doublereal *bounds, integer *exclud, logical *inside);
/*:ref: twopi_ 7 0 */
/*:ref: zznrmlon_ 14 5 7 7 7 7 7 */
 
extern int zzinpdt_(void *cspice_state, doublereal *p, doublereal *bounds, doublereal *corpar, doublereal *margin, integer *exclud, logical *inside);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: halfpi_ 7 0 */
/*:ref: twopi_ 7 0 */
/*:ref: pi_ 7 0 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: reclat_ 14 4 7 7 7 7 */
/*:ref: zzinpdt0_ 14 6 7 7 7 7 4 12 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: zzpdcmpl_ 14 5 7 7 7 7 4 */
/*:ref: failed_ 12 0 */
/*:ref: zznrmlon_ 14 5 7 7 7 7 7 */
 
extern int zzinpdt0_(void *cspice_state, doublereal *p, doublereal *lon, doublereal *bounds, doublereal *corpar, integer *exclud, logical *inside);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: twopi_ 7 0 */
/*:ref: halfpi_ 7 0 */
/*:ref: zzpdcmpl_ 14 5 7 7 7 7 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zznrmlon_ 14 5 7 7 7 7 7 */
/*:ref: zzellbds_ 14 8 7 7 7 7 7 7 7 7 */
 
extern int zzinrec_(void *cspice_state, doublereal *p, doublereal *bounds, doublereal *margin, integer *exclud, logical *inside);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern int zzinrypl_(void *cspice_state, doublereal *vertex, doublereal *udir, doublereal *uplnml, doublereal *const__, doublereal *maxd, integer *nxpts, doublereal *xpt);
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vequ_ 14 2 7 7 */
 
extern int zzinssub_(void *cspice_state, char *in, char *sub, integer *loc, char *out, ftnlen in_len, ftnlen sub_len, ftnlen out_len);
 
extern int zzinvelt_(void *cspice_state, doublereal *p, integer *corsys, doublereal *corpar, doublereal *bounds, doublereal *margin, integer *exclud, logical *inside);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzinlat_ 14 5 7 7 7 4 12 */
/*:ref: zzinpdt_ 14 6 7 7 7 7 4 12 */
/*:ref: zzinrec_ 14 5 7 7 7 4 12 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern int zzlatbox_(void *cspice_state, doublereal *bounds, doublereal *center, doublereal *lr, doublereal *lt, doublereal *lz, doublereal *radius);
/*:ref: return_ 12 0 */
/*:ref: twopi_ 7 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: halfpi_ 7 0 */
/*:ref: cylrec_ 14 4 7 7 7 7 */
/*:ref: vpack_ 14 4 7 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
 
extern int zzldker_(void *cspice_state, char *file, char *nofile, char *filtyp, integer *handle, ftnlen file_len, ftnlen nofile_len, ftnlen filtyp_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: exists_ 12 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: getfat_ 14 6 13 13 13 124 124 124 */
/*:ref: spklef_ 14 3 13 4 124 */
/*:ref: cklpf_ 14 3 13 4 124 */
/*:ref: pcklof_ 14 3 13 4 124 */
/*:ref: tkvrsn_ 14 4 13 13 124 124 */
/*:ref: eklef_ 14 3 13 4 124 */
/*:ref: zzdsklsf_ 14 3 13 4 124 */
/*:ref: ldpool_ 14 2 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: zzbodkik_ 14 0 */
 
extern int zzlexmet_(void *cspice_state, char *method, integer *maxn, integer *n, integer *begs, integer *ends, ftnlen method_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: cpos_ 4 5 13 13 4 124 124 */
/*:ref: ltrim_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: lxqstr_ 14 7 13 13 4 4 4 124 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
 
extern int zzmkpc_(void *cspice_state, char *pictur, integer *b, integer *e, char *mark, char *pattrn, ftnlen pictur_len, ftnlen mark_len, ftnlen pattrn_len);
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: zzrepsub_ 14 8 13 4 4 13 13 124 124 124 */
 
extern int zzmkspin_(void *cspice_state, integer *np, integer *plates, doublereal *vrtces, doublereal *voxscl, integer *cgscal, integer *maxptr, integer *mxcell, integer *maxvxl, integer *cells, integer *nvox, doublereal *voxsiz, doublereal *voxori, integer *nvxtot, integer *nvxptr, integer *vxptr, integer *nvxlst, integer *vxlist, doublereal *extent, integer *cgrptr);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dpmax_ 7 0 */
/*:ref: dpmin_ 7 0 */
/*:ref: zzinilnk_ 14 5 4 4 4 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: brcktd_ 7 3 7 7 7 */
/*:ref: vpack_ 14 4 7 7 7 7 */
/*:ref: zzgetvox_ 14 6 7 7 4 7 12 4 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: zzvoxcvo_ 14 6 4 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: zzvox2id_ 4 2 4 4 */
/*:ref: zzaddlnk_ 14 7 4 4 4 4 4 4 4 */
/*:ref: zzuntngl_ 14 7 4 4 4 4 4 4 4 */
 
extern int zzmobliq_(void *cspice_state, doublereal *et, doublereal *mob, doublereal *dmob);
/*:ref: jyear_ 7 0 */
/*:ref: rpd_ 7 0 */
 
extern int zzmsxf_(void *cspice_state, doublereal *matrix, integer *n, doublereal *output);
 
extern doublereal zzmult_(void *cspice_state, doublereal *a, doublereal *b);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dpmax_ 7 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern int zznamfrm_(void *cspice_state, integer *usrctr, char *savnam, integer *savcde, char *frname, integer *frcode, ftnlen savnam_len, ftnlen frname_len);
/*:ref: return_ 12 0 */
/*:ref: zzpctrck_ 14 2 4 12 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zznofcon_(void *cspice_state, doublereal *et, integer *frame1, integer *endp1, integer *frame2, integer *endp2, char *errmsg, ftnlen errmsg_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: frmnam_ 14 3 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: repmf_ 14 10 13 13 7 4 13 13 124 124 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: ckmeta_ 14 4 4 13 4 124 */
/*:ref: zzsclk_ 12 2 4 4 */
 
extern int zznrddp_(void *cspice_state, doublereal *ao, doublereal *elems, doublereal *em, doublereal *omgasm, doublereal *omgdot, doublereal *t, doublereal *xinc, doublereal *xll, doublereal *xlldot, doublereal *xn, doublereal *xnodes, doublereal *xnodot, doublereal *xnodp);
extern int zzdpinit_(void *cspice_state, doublereal *ao, doublereal *xlldot, doublereal *omgdot, doublereal *xnodot, doublereal *xnodp, doublereal *elems);
extern int zzdpsec_(void *cspice_state, doublereal *xll, doublereal *omgasm, doublereal *xnodes, doublereal *em, doublereal *xinc, doublereal *xn, doublereal *t, doublereal *elems, doublereal *omgdot);
extern int zzdpper_(void *cspice_state, doublereal *t, doublereal *em, doublereal *xinc, doublereal *omgasm, doublereal *xnodes, doublereal *xll);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: pi_ 7 0 */
/*:ref: twopi_ 7 0 */
/*:ref: j2000_ 7 0 */
/*:ref: spd_ 7 0 */
/*:ref: j1950_ 7 0 */
/*:ref: zzsecprt_ 14 12 4 7 7 7 7 7 7 7 7 7 7 7 */
 
extern int zznrmlon_(void *cspice_state, doublereal *inmin, doublereal *inmax, doublereal *tol, doublereal *outmin, doublereal *outmax);
/*:ref: twopi_ 7 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dpr_ 7 0 */
/*:ref: touchd_ 7 1 7 */
 
extern int zznwpool_(void *cspice_state, char *varnam, char *wtvars, integer *wtptrs, integer *wtpool, char *wtagnt, char *agtwrk, char *notify, char *agents, ftnlen varnam_len, ftnlen wtvars_len, ftnlen wtagnt_len, ftnlen agtwrk_len, ftnlen notify_len, ftnlen agents_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzgapool_ 14 10 13 13 4 4 13 13 124 124 124 124 */
/*:ref: unionc_ 14 6 13 13 13 124 124 124 */
/*:ref: copyc_ 14 4 13 13 124 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern integer zzocced_(void *cspice_state, doublereal *viewpt, doublereal *centr1, doublereal *semax1, doublereal *centr2, doublereal *semax2);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: unorm_ 14 3 7 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: isrot_ 12 3 7 7 7 */
/*:ref: det_ 7 1 7 */
/*:ref: mtxv_ 14 3 7 7 7 */
/*:ref: dasine_ 7 2 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: edlimb_ 14 5 7 7 7 7 7 */
/*:ref: el2cgv_ 14 4 7 7 7 7 */
/*:ref: psv2pl_ 14 4 7 7 7 7 */
/*:ref: vprjp_ 14 3 7 7 7 */
/*:ref: vdist_ 7 2 7 7 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: halfpi_ 7 0 */
/*:ref: xpose_ 14 2 7 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: mxm_ 14 3 7 7 7 */
/*:ref: saelgv_ 14 4 7 7 7 7 */
/*:ref: cgv2el_ 14 4 7 7 7 7 */
/*:ref: zzasryel_ 14 7 13 7 7 7 7 7 124 */
/*:ref: ucrss_ 14 3 7 7 7 */
/*:ref: pi_ 7 0 */
 
extern int zzpdcmpl_(void *cspice_state, doublereal *re, doublereal *f, doublereal *p, doublereal *lat, integer *rel);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: halfpi_ 7 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzelnaxx_ 14 5 7 7 7 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: reclat_ 14 4 7 7 7 7 */
 
extern logical zzpdpltc_(void *cspice_state, doublereal *re, doublereal *f, doublereal *p, doublereal *lat);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzelnaxx_ 14 5 7 7 7 7 7 */
/*:ref: failed_ 12 0 */
 
extern int zzpdtbox_(void *cspice_state, doublereal *bounds, doublereal *corpar, doublereal *center, doublereal *lr, doublereal *lt, doublereal *lz, doublereal *radius);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: twopi_ 7 0 */
/*:ref: halfpi_ 7 0 */
/*:ref: georec_ 14 6 7 7 7 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: cylrec_ 14 4 7 7 7 7 */
/*:ref: vpack_ 14 4 7 7 7 7 */
 
extern integer zzphsh_(void *cspice_state, char *word, integer *m, integer *m2, ftnlen word_len);
extern integer zzshsh_(void *cspice_state, integer *m);
extern integer zzhash_(void *cspice_state, char *word, ftnlen word_len);
extern integer zzhash2_(void *cspice_state, char *word, integer *m2, ftnlen word_len);
/*:ref: intmax_ 4 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
 
extern int zzpini_(void *cspice_state, logical *first, integer *maxvar, integer *maxval, integer *maxlin, char *begdat, char *begtxt, integer *nmpool, integer *dppool, integer *chpool, integer *namlst, integer *datlst, integer *maxagt, integer *mxnote, char *wtvars, integer *wtptrs, integer *wtpool, char *wtagnt, char *agents, char *active, char *notify, integer *subctr, ftnlen begdat_len, ftnlen begtxt_len, ftnlen wtvars_len, ftnlen wtagnt_len, ftnlen agents_len, ftnlen active_len, ftnlen notify_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzshsh_ 4 1 4 */
/*:ref: touchi_ 4 1 4 */
/*:ref: lnkini_ 14 2 4 4 */
/*:ref: ssizec_ 14 3 4 13 124 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: clearc_ 14 3 4 13 124 */
/*:ref: zzctrsin_ 14 1 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzplatfm_(void *cspice_state, char *key, char *value, ftnlen key_len, ftnlen value_len);
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
 
extern int zzpltchk_(void *cspice_state, logical *ok);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzplatfm_ 14 4 13 13 124 124 */
/*:ref: zzgetbff_ 14 1 4 */
/*:ref: zzddhgsd_ 14 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzprscor_(void *cspice_state, char *abcorr, logical *attblk, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: orderc_ 14 4 13 4 4 124 */
/*:ref: reordc_ 14 4 4 4 13 124 */
/*:ref: reordl_ 14 3 4 4 12 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: bsrchc_ 4 5 13 4 13 124 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzprsmet_(void *cspice_state, integer *bodyid, char *method, integer *mxnsrf, char *shape, char *subtyp, logical *pri, integer *nsurf, integer *srflst, char *pntdef, char *trmtyp, ftnlen method_len, ftnlen shape_len, ftnlen subtyp_len, ftnlen pntdef_len, ftnlen trmtyp_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: zzlexmet_ 14 6 13 4 4 4 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: srfscc_ 14 5 13 4 4 12 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
 
extern int zzptpl02_(void *cspice_state, integer *handle, integer *dladsc, doublereal *dskdsc, doublereal *point, integer *plid, integer *plate, doublereal *verts, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: dlassg_ 12 4 4 4 4 4 */
/*:ref: dskd02_ 14 7 4 4 4 4 4 4 7 */
/*:ref: dski02_ 14 7 4 4 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzsegbox_ 14 3 7 7 7 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: dskgtl_ 14 2 4 7 */
/*:ref: zzinvelt_ 14 7 7 4 7 7 7 4 12 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: brckti_ 4 3 4 4 4 */
/*:ref: zzvoxcvo_ 14 6 4 4 4 4 4 4 */
/*:ref: zzvox2id_ 4 2 4 4 */
/*:ref: dpmax_ 7 0 */
/*:ref: pltexp_ 14 3 7 7 7 */
/*:ref: pltnrm_ 14 4 7 7 7 7 */
/*:ref: vhatip_ 14 1 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: pltnp_ 14 6 7 7 7 7 7 7 */
/*:ref: moved_ 14 3 7 4 7 */
 
extern int zzraybox_(void *cspice_state, doublereal *vertex, doublereal *raydir, doublereal *boxori, doublereal *extent, doublereal *xpt, logical *found);
/*:ref: return_ 12 0 */
/*:ref: vzero_ 12 1 7 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: surfpt_ 14 7 7 7 7 7 7 7 12 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
 
extern int zzrbrkst_(void *cspice_state, char *string, char *lftend, char *rgtend, char *substr, integer *length, logical *bkpres, ftnlen string_len, ftnlen lftend_len, ftnlen rgtend_len, ftnlen substr_len);
/*:ref: posr_ 4 5 13 13 4 124 124 */
 
extern int zzrecbox_(void *cspice_state, doublereal *bounds, doublereal *center, doublereal *lx, doublereal *ly, doublereal *lz, doublereal *radius);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vpack_ 14 4 7 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
 
extern int zzrefch0_(void *cspice_state, integer *frame1, integer *frame2, doublereal *et, doublereal *rotate);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ident_ 14 1 7 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzrotgt0_ 14 5 4 7 7 4 12 */
/*:ref: zzrxr_ 14 3 7 4 7 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: zznofcon_ 14 7 7 4 4 4 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: xpose_ 14 2 7 7 */
 
extern int zzrefch1_(void *cspice_state, integer *frame1, integer *frame2, doublereal *et, doublereal *rotate);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ident_ 14 1 7 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzrotgt1_ 14 5 4 7 7 4 12 */
/*:ref: zzrxr_ 14 3 7 4 7 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: zznofcon_ 14 7 7 4 4 4 4 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: xpose_ 14 2 7 7 */
 
extern int zzrepsub_(void *cspice_state, char *in, integer *left, integer *right, char *string, char *out, ftnlen in_len, ftnlen string_len, ftnlen out_len);
/*:ref: sumai_ 4 2 4 4 */
 
extern logical zzrept_(void *cspice_state, char *sub, char *replac, logical *l2r, ftnlen sub_len, ftnlen replac_len);
/*:ref: zzsubt_ 12 5 13 13 12 124 124 */
/*:ref: zzremt_ 12 2 13 124 */
 
extern int zzrotgt0_(void *cspice_state, integer *infrm, doublereal *et, doublereal *rotate, integer *outfrm, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: irfrot_ 14 3 4 4 7 */
/*:ref: tipbod_ 14 5 13 4 7 7 124 */
/*:ref: xpose_ 14 2 7 7 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: ckfrot_ 14 5 4 7 7 4 12 */
/*:ref: tkfram_ 14 4 4 7 4 12 */
/*:ref: zzdynrt0_ 14 5 4 4 7 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern int zzrotgt1_(void *cspice_state, integer *infrm, doublereal *et, doublereal *rotate, integer *outfrm, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: irfrot_ 14 3 4 4 7 */
/*:ref: tipbod_ 14 5 13 4 7 7 124 */
/*:ref: xpose_ 14 2 7 7 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: ckfrot_ 14 5 4 7 7 4 12 */
/*:ref: tkfram_ 14 4 4 7 4 12 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
 
extern int zzrtnmat_(void *cspice_state, doublereal *v, doublereal *m);
/*:ref: return_ 12 0 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ucrss_ 14 3 7 7 7 */
/*:ref: vhat_ 14 2 7 7 */
 
extern int zzrvar_(void *cspice_state, integer *namlst, integer *nmpool, char *names, integer *datlst, integer *dppool, doublereal *dpvals, integer *chpool, char *chvals, char *varnam, logical *eof, ftnlen names_len, ftnlen chvals_len, ftnlen varnam_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: rdkdat_ 14 3 13 12 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rdklin_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: lastpc_ 4 2 13 124 */
/*:ref: zzhash_ 4 2 13 124 */
/*:ref: lnknfn_ 4 1 4 */
/*:ref: lnkan_ 14 2 4 4 */
/*:ref: lnkila_ 14 3 4 4 4 */
/*:ref: lnkfsl_ 14 3 4 4 4 */
/*:ref: zzcln_ 14 7 4 4 4 4 4 4 4 */
/*:ref: tparse_ 14 5 13 7 13 124 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: nparsd_ 14 6 13 7 13 4 124 124 */
 
extern int zzrvbf_(void *cspice_state, char *buffer, integer *bsize, integer *linnum, integer *namlst, integer *nmpool, char *names, integer *datlst, integer *dppool, doublereal *dpvals, integer *chpool, char *chvals, char *varnam, logical *eof, ftnlen buffer_len, ftnlen names_len, ftnlen chvals_len, ftnlen varnam_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: lastpc_ 4 2 13 124 */
/*:ref: zzhash_ 4 2 13 124 */
/*:ref: lnknfn_ 4 1 4 */
/*:ref: lnkan_ 14 2 4 4 */
/*:ref: lnkila_ 14 3 4 4 4 */
/*:ref: lnkfsl_ 14 3 4 4 4 */
/*:ref: zzcln_ 14 7 4 4 4 4 4 4 4 */
/*:ref: tparse_ 14 5 13 7 13 124 124 */
/*:ref: nparsd_ 14 6 13 7 13 4 124 124 */
 
extern int zzrxr_(void *cspice_state, doublereal *matrix, integer *n, doublereal *output);
/*:ref: ident_ 14 1 7 */
 
extern int zzrytelt_(void *cspice_state, doublereal *vertex, doublereal *raydir, doublereal *dskdsc, doublereal *margin, integer *nxpts, doublereal *xpt);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzrytlat_ 14 6 7 7 7 7 4 7 */
/*:ref: zzrytrec_ 14 6 7 7 7 7 4 7 */
/*:ref: zzrytpdt_ 14 7 7 7 7 7 7 4 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzrytlat_(void *cspice_state, doublereal *vertex, doublereal *raydir, doublereal *bounds, doublereal *margin, integer *nxpts, doublereal *xpt);
/*:ref: zzinlat_ 14 5 7 7 7 4 12 */
/*:ref: failed_ 12 0 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: zznrmlon_ 14 5 7 7 7 7 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: dpmax_ 7 0 */
/*:ref: zzryxsph_ 14 5 7 7 7 7 12 */
/*:ref: reclat_ 14 4 7 7 7 7 */
/*:ref: vdist_ 7 2 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: halfpi_ 7 0 */
/*:ref: incnsg_ 14 8 7 7 7 7 7 4 7 7 */
/*:ref: vpack_ 14 4 7 7 7 7 */
/*:ref: zzinrypl_ 14 7 7 7 7 7 7 4 7 */
/*:ref: ucrss_ 14 3 7 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vminus_ 14 2 7 7 */
 
extern int zzrytpdt_(void *cspice_state, doublereal *vertex, doublereal *raydir, doublereal *bounds, doublereal *corpar, doublereal *margin, integer *nxpts, doublereal *xpt);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vzero_ 12 1 7 */
/*:ref: zzinpdt_ 14 6 7 7 7 7 4 12 */
/*:ref: failed_ 12 0 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: zznrmlon_ 14 5 7 7 7 7 7 */
/*:ref: zzellbds_ 14 8 7 7 7 7 7 7 7 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: dpmax_ 7 0 */
/*:ref: surfpt_ 14 7 7 7 7 7 7 7 12 */
/*:ref: vdist_ 7 2 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: halfpi_ 7 0 */
/*:ref: zzelnaxx_ 14 5 7 7 7 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: incnsg_ 14 8 7 7 7 7 7 4 7 7 */
/*:ref: zzpdpltc_ 12 4 7 7 7 7 */
/*:ref: vpack_ 14 4 7 7 7 7 */
/*:ref: zzinrypl_ 14 7 7 7 7 7 7 4 7 */
/*:ref: ucrss_ 14 3 7 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vminus_ 14 2 7 7 */
 
extern int zzrytrec_(void *cspice_state, doublereal *vertex, doublereal *raydir, doublereal *bounds, doublereal *margin, integer *nxpts, doublereal *xpt);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzinrec_ 14 5 7 7 7 4 12 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: zzraybox_ 14 6 7 7 7 7 7 12 */
 
extern int zzryxsph_(void *cspice_state, doublereal *vertex, doublereal *udir, doublereal *r__, doublereal *xpt, logical *found);
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
 
extern logical zzsclk_(void *cspice_state, integer *ckid, integer *sclkid);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ssizei_ 14 2 4 4 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: elemi_ 12 2 4 4 */
/*:ref: cvpool_ 14 3 13 12 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: sizei_ 4 1 4 */
/*:ref: insrti_ 14 2 4 4 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: swpool_ 14 5 13 4 13 124 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: removi_ 14 2 4 4 */
 
extern int zzsecprt_(void *cspice_state, integer *isynfl, doublereal *dg, doublereal *del, doublereal *xni, doublereal *omegao, doublereal *atime, doublereal *omgdot, doublereal *xli, doublereal *xfact, doublereal *xldot, doublereal *xndot, doublereal *xnddt);
 
extern int zzsegbox_(void *cspice_state, doublereal *dskdsc, doublereal *boxctr, doublereal *maxr);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzlatbox_ 14 6 7 7 7 7 7 7 */
/*:ref: zzrecbox_ 14 6 7 7 7 7 7 7 */
/*:ref: zzpdtbox_ 14 7 7 7 7 7 7 7 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzsfxcor_(void *cspice_state, S_fp udnear, S_fp udmaxr, S_fp udrayx, integer *trgcde, doublereal *et, char *abcorr, logical *uselt, logical *usecn, logical *usestl, logical *xmit, char *fixref, integer *obscde, integer *dfrcde, integer *dclass, integer *dcentr, doublereal *dvec, doublereal *spoint, doublereal *trgepc, doublereal *srfvec, logical *found, ftnlen abcorr_len, ftnlen fixref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: vzero_ 12 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: spkezp_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: refchg_ 14 4 4 4 7 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: pxform_ 14 6 13 13 7 7 124 124 */
/*:ref: spkssb_ 14 5 4 7 13 7 124 */
/*:ref: stelab_ 14 3 7 7 7 */
/*:ref: stlabx_ 14 3 7 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: dasine_ 7 2 7 7 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: vdist_ 7 2 7 7 */
/*:ref: clight_ 7 0 */
/*:ref: touchd_ 7 1 7 */
/*:ref: vhatip_ 14 1 7 */
/*:ref: vscl_ 14 3 7 7 7 */
 
extern int zzsglatx_(void *cspice_state, doublereal *p1, doublereal *p2, doublereal *minlat, doublereal *minp, doublereal *maxlat, doublereal *maxp);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: reclat_ 14 4 7 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: vzero_ 12 1 7 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vhatip_ 14 1 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: opsgnd_ 12 2 7 7 */
/*:ref: nvc2pl_ 14 3 7 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: inrypl_ 14 5 7 7 7 4 7 */
/*:ref: failed_ 12 0 */
 
extern int zzsgp4_(void *cspice_state, doublereal *geophs, doublereal *elems, integer *opmode, doublereal *t, doublereal *state);
extern int xxsgp4i_(void *cspice_state, doublereal *geophs, doublereal *elems, integer *opmode);
extern int xxsgp4e_(void *cspice_state, doublereal *t, doublereal *state);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: return_ 12 0 */
/*:ref: ttrans_ 14 5 13 13 7 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: zzinil_ 14 19 7 4 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 */
/*:ref: twopi_ 7 0 */
/*:ref: zzdscm_ 14 88 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 */
/*:ref: zzdspr_ 14 40 4 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 12 7 7 7 7 7 */
/*:ref: zzdsin_ 14 73 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 4 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 */
/*:ref: zzdspc_ 14 37 4 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: pi_ 7 0 */
 
extern int zzsinutl_(void *cspice_state, integer *trgcde, integer *nsurf, integer *srflst, doublereal *et, integer *fixfid, doublereal *vertex, doublereal *raydir, doublereal *spoint, logical *found, doublereal *minrad, doublereal *maxrad, doublereal *pnear, doublereal *dist);
extern int zzsuelin_(void *cspice_state, integer *trgcde);
extern int zzsudski_(void *cspice_state, integer *trgcde, integer *nsurf, integer *srflst, integer *fixfid);
extern int zzraysfx_(void *cspice_state, doublereal *vertex, doublereal *raydir, doublereal *et, doublereal *spoint, logical *found);
extern int zzmaxrad_(void *cspice_state, doublereal *maxrad);
extern int zzminrad_(void *cspice_state, doublereal *minrad);
extern int zzraynp_(void *cspice_state, doublereal *vertex, doublereal *raydir, doublereal *et, doublereal *pnear, doublereal *dist);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: zzdsksph_ 14 5 4 4 4 7 7 */
/*:ref: surfpt_ 14 7 7 7 7 7 7 7 12 */
/*:ref: zzsbfxr_ 14 9 4 4 4 7 4 7 7 7 12 */
/*:ref: npedln_ 14 7 7 7 7 7 7 7 7 */
 
extern int zzsizeok_(void *cspice_state, integer *size, integer *psize, integer *dsize, integer *offset, logical *ok, integer *n);
/*:ref: rmaini_ 14 4 4 4 4 4 */
 
extern int zzspkac0_(void *cspice_state, integer *targ, doublereal *et, char *ref, char *abcorr, integer *obs, doublereal *starg, doublereal *lt, doublereal *dlt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzprscor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzspkgo0_ 14 7 4 7 13 4 7 7 124 */
/*:ref: qderiv_ 14 5 4 7 7 7 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: zzspkas0_ 14 11 4 7 13 13 7 7 7 7 7 124 124 */
 
extern int zzspkac1_(void *cspice_state, integer *targ, doublereal *et, char *ref, char *abcorr, integer *obs, doublereal *starg, doublereal *lt, doublereal *dlt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzprscor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzspkgo1_ 14 7 4 7 13 4 7 7 124 */
/*:ref: qderiv_ 14 5 4 7 7 7 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: zzspkas1_ 14 11 4 7 13 13 7 7 7 7 7 124 124 */
 
extern int zzspkap0_(void *cspice_state, integer *targ, doublereal *et, char *ref, doublereal *sobs, char *abcorr, doublereal *starg, doublereal *lt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: odd_ 12 1 4 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: zzspksb0_ 14 5 4 7 13 7 124 */
/*:ref: vsubg_ 14 4 7 7 4 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
/*:ref: stlabx_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: stelab_ 14 3 7 7 7 */
 
extern int zzspkap1_(void *cspice_state, integer *targ, doublereal *et, char *ref, doublereal *sobs, char *abcorr, doublereal *starg, doublereal *lt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: odd_ 12 1 4 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: zzspksb1_ 14 5 4 7 13 7 124 */
/*:ref: vsubg_ 14 4 7 7 4 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
/*:ref: stlabx_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: stelab_ 14 3 7 7 7 */
 
extern int zzspkas0_(void *cspice_state, integer *targ, doublereal *et, char *ref, char *abcorr, doublereal *stobs, doublereal *accobs, doublereal *starg, doublereal *lt, doublereal *dlt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzprscor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: zzspklt0_ 14 10 4 7 13 13 7 7 7 7 124 124 */
/*:ref: zzstelab_ 14 6 12 7 7 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
 
extern int zzspkas1_(void *cspice_state, integer *targ, doublereal *et, char *ref, char *abcorr, doublereal *stobs, doublereal *accobs, doublereal *starg, doublereal *lt, doublereal *dlt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzprscor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: zzspklt1_ 14 10 4 7 13 13 7 7 7 7 124 124 */
/*:ref: zzstelab_ 14 6 12 7 7 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
 
extern int zzspkez0_(void *cspice_state, integer *targ, doublereal *et, char *ref, char *abcorr, integer *obs, doublereal *starg, doublereal *lt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: zzspkgo0_ 14 7 4 7 13 4 7 7 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: zzspkac0_ 14 10 4 7 13 13 4 7 7 7 124 124 */
/*:ref: zzspksb0_ 14 5 4 7 13 7 124 */
/*:ref: zzspklt0_ 14 10 4 7 13 13 7 7 7 7 124 124 */
/*:ref: zzfrmch0_ 14 4 4 4 7 7 */
/*:ref: vsclip_ 14 2 7 7 */
/*:ref: mxvg_ 14 5 7 7 4 4 7 */
 
extern int zzspkez1_(void *cspice_state, integer *targ, doublereal *et, char *ref, char *abcorr, integer *obs, doublereal *starg, doublereal *lt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: zzspkgo1_ 14 7 4 7 13 4 7 7 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: zzspkac1_ 14 10 4 7 13 13 4 7 7 7 124 124 */
/*:ref: zzspksb1_ 14 5 4 7 13 7 124 */
/*:ref: zzspklt1_ 14 10 4 7 13 13 7 7 7 7 124 124 */
/*:ref: zzfrmch1_ 14 4 4 4 7 7 */
/*:ref: vsclip_ 14 2 7 7 */
/*:ref: mxvg_ 14 5 7 7 4 4 7 */
 
extern int zzspkfao_(void *cspice_state, integer *targ, doublereal *et, char *ref, char *abcorr, S_fp obssub, doublereal *starg, doublereal *lt, doublereal *dlt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: spkssb_ 14 5 4 7 13 7 124 */
/*:ref: vaddg_ 14 4 7 7 4 7 */
/*:ref: qderiv_ 14 5 4 7 7 7 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: spkaps_ 14 11 4 7 13 13 7 7 7 7 7 124 124 */
 
extern int zzspkfap_(void *cspice_state, U_fp trgsub, doublereal *et, char *ref, char *abcorr, doublereal *stobs, doublereal *accobs, doublereal *starg, doublereal *lt, doublereal *dlt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzspkflt_ 14 10 200 7 13 13 7 7 7 7 124 124 */
/*:ref: zzstelab_ 14 6 12 7 7 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
 
extern int zzspkfat_(void *cspice_state, U_fp trgsub, doublereal *et, char *ref, char *abcorr, integer *obs, doublereal *starg, doublereal *lt, doublereal *dlt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: spkgeo_ 14 7 4 7 13 4 7 7 124 */
/*:ref: qderiv_ 14 5 4 7 7 7 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: zzspkfap_ 14 11 200 7 13 13 7 7 7 7 7 124 124 */
 
extern int zzspkflt_(void *cspice_state, S_fp trgsub, doublereal *et, char *ref, char *abcorr, doublereal *stobs, doublereal *starg, doublereal *lt, doublereal *dlt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: spkssb_ 14 5 4 7 13 7 124 */
/*:ref: vaddg_ 14 4 7 7 4 7 */
/*:ref: vsubg_ 14 4 7 7 4 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: touchd_ 7 1 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
 
extern int zzspkfzo_(void *cspice_state, integer *targ, doublereal *et, char *ref, char *abcorr, S_fp obssub, doublereal *starg, doublereal *lt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: spkgeo_ 14 7 4 7 13 4 7 7 124 */
/*:ref: vsubg_ 14 4 7 7 4 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: zzspkfao_ 14 10 4 7 13 13 214 7 7 7 124 124 */
/*:ref: spkssb_ 14 5 4 7 13 7 124 */
/*:ref: vaddg_ 14 4 7 7 4 7 */
/*:ref: spkltc_ 14 10 4 7 13 13 7 7 7 7 124 124 */
/*:ref: frmchg_ 14 4 4 4 7 7 */
/*:ref: zzcorsxf_ 14 4 12 7 7 7 */
/*:ref: mxvg_ 14 5 7 7 4 4 7 */
 
extern int zzspkfzt_(void *cspice_state, S_fp trgsub, doublereal *et, char *ref, char *abcorr, integer *obs, doublereal *starg, doublereal *lt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: spkgeo_ 14 7 4 7 13 4 7 7 124 */
/*:ref: vaddg_ 14 4 7 7 4 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: zzspkfat_ 14 10 214 7 13 13 4 7 7 7 124 124 */
/*:ref: spkssb_ 14 5 4 7 13 7 124 */
/*:ref: spkltc_ 14 10 4 7 13 13 7 7 7 7 124 124 */
/*:ref: frmchg_ 14 4 4 4 7 7 */
/*:ref: zzcorsxf_ 14 4 12 7 7 7 */
/*:ref: mxvg_ 14 5 7 7 4 4 7 */
 
extern int zzspkgo0_(void *cspice_state, integer *targ, doublereal *et, char *ref, integer *obs, doublereal *state, doublereal *lt, ftnlen ref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: frstnp_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: spksfs_ 14 7 4 7 4 7 13 12 124 */
/*:ref: spkpvn_ 14 6 4 7 7 4 7 4 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: irfrot_ 14 3 4 4 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: zzfrmch0_ 14 4 4 4 7 7 */
/*:ref: mxvg_ 14 5 7 7 4 4 7 */
/*:ref: vaddg_ 14 4 7 7 4 7 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: bodc2n_ 14 4 4 13 12 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: vsubg_ 14 4 7 7 4 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
 
extern int zzspkgo1_(void *cspice_state, integer *targ, doublereal *et, char *ref, integer *obs, doublereal *state, doublereal *lt, ftnlen ref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: frstnp_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: spksfs_ 14 7 4 7 4 7 13 12 124 */
/*:ref: spkpvn_ 14 6 4 7 7 4 7 4 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: irfrot_ 14 3 4 4 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: zzfrmch1_ 14 4 4 4 7 7 */
/*:ref: mxvg_ 14 5 7 7 4 4 7 */
/*:ref: vaddg_ 14 4 7 7 4 7 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: bodc2n_ 14 4 4 13 12 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: vsubg_ 14 4 7 7 4 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
 
extern int zzspkgp0_(void *cspice_state, integer *targ, doublereal *et, char *ref, integer *obs, doublereal *pos, doublereal *lt, ftnlen ref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: frstnp_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: spksfs_ 14 7 4 7 4 7 13 12 124 */
/*:ref: spkpvn_ 14 6 4 7 7 4 7 4 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: irfrot_ 14 3 4 4 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: zzrefch0_ 14 4 4 4 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: bodc2n_ 14 4 4 13 12 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
 
extern int zzspkgp1_(void *cspice_state, integer *targ, doublereal *et, char *ref, integer *obs, doublereal *pos, doublereal *lt, ftnlen ref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: frstnp_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: spksfs_ 14 7 4 7 4 7 13 12 124 */
/*:ref: spkpvn_ 14 6 4 7 7 4 7 4 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: irfrot_ 14 3 4 4 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: zzrefch1_ 14 4 4 4 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: isrchi_ 4 3 4 4 4 */
/*:ref: bodc2n_ 14 4 4 13 12 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: etcal_ 14 3 7 13 124 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
 
extern int zzspklt0_(void *cspice_state, integer *targ, doublereal *et, char *ref, char *abcorr, doublereal *stobs, doublereal *starg, doublereal *lt, doublereal *dlt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzspkgo0_ 14 7 4 7 13 4 7 7 124 */
/*:ref: vsubg_ 14 4 7 7 4 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: touchd_ 7 1 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
 
extern int zzspklt1_(void *cspice_state, integer *targ, doublereal *et, char *ref, char *abcorr, doublereal *stobs, doublereal *starg, doublereal *lt, doublereal *dlt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzvalcor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: zzspkgo1_ 14 7 4 7 13 4 7 7 124 */
/*:ref: vsubg_ 14 4 7 7 4 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: touchd_ 7 1 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
 
extern int zzspkpa0_(void *cspice_state, integer *targ, doublereal *et, char *ref, doublereal *sobs, char *abcorr, doublereal *ptarg, doublereal *lt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: odd_ 12 1 4 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: zzspkgp0_ 14 7 4 7 13 4 7 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
/*:ref: stlabx_ 14 3 7 7 7 */
/*:ref: stelab_ 14 3 7 7 7 */
 
extern int zzspkpa1_(void *cspice_state, integer *targ, doublereal *et, char *ref, doublereal *sobs, char *abcorr, doublereal *ptarg, doublereal *lt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: odd_ 12 1 4 */
/*:ref: irfnum_ 14 3 13 4 124 */
/*:ref: zzspkgp1_ 14 7 4 7 13 4 7 7 124 */
/*:ref: failed_ 12 0 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
/*:ref: stlabx_ 14 3 7 7 7 */
/*:ref: stelab_ 14 3 7 7 7 */
 
extern int zzspksb0_(void *cspice_state, integer *targ, doublereal *et, char *ref, doublereal *starg, ftnlen ref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzspkgo0_ 14 7 4 7 13 4 7 7 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzspksb1_(void *cspice_state, integer *targ, doublereal *et, char *ref, doublereal *starg, ftnlen ref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzspkgo1_ 14 7 4 7 13 4 7 7 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzspkzp0_(void *cspice_state, integer *targ, doublereal *et, char *ref, char *abcorr, integer *obs, doublereal *ptarg, doublereal *lt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: ltrim_ 4 2 13 124 */
/*:ref: eqchr_ 12 4 13 13 124 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: zzspkgp0_ 14 7 4 7 13 4 7 7 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: failed_ 12 0 */
/*:ref: zzspksb0_ 14 5 4 7 13 7 124 */
/*:ref: zzspkpa0_ 14 9 4 7 13 7 13 7 7 124 124 */
/*:ref: zzrefch0_ 14 4 4 4 7 7 */
/*:ref: mxv_ 14 3 7 7 7 */
 
extern int zzspkzp1_(void *cspice_state, integer *targ, doublereal *et, char *ref, char *abcorr, integer *obs, doublereal *ptarg, doublereal *lt, ftnlen ref_len, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: ltrim_ 4 2 13 124 */
/*:ref: eqchr_ 12 4 13 13 124 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: zzspkgp1_ 14 7 4 7 13 4 7 7 124 */
/*:ref: zznamfrm_ 14 7 4 13 4 13 4 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: failed_ 12 0 */
/*:ref: zzspksb1_ 14 5 4 7 13 7 124 */
/*:ref: zzspkpa1_ 14 9 4 7 13 7 13 7 7 124 124 */
/*:ref: zzrefch1_ 14 4 4 4 7 7 */
/*:ref: mxv_ 14 3 7 7 7 */
 
extern int zzsrfini_(void *cspice_state, char *nornam, integer *codes, integer *bodies, integer *nvals, integer *maxval, integer *snmhls, integer *snmpol, integer *snmidx, integer *sidhls, integer *sidpol, integer *sididx, ftnlen nornam_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzhsiini_ 14 3 4 4 4 */
/*:ref: zzhscini_ 14 3 4 4 4 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: zzhash2_ 4 3 13 4 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: zzhashi_ 4 2 4 4 */
 
extern int zzsrfker_(void *cspice_state, char *kernam, char *nornam, integer *kersid, integer *kerbid, logical *extker, integer *nkvar, integer *snmhls, integer *snmpol, integer *snmidx, integer *sidhls, integer *sidpol, integer *sididx, ftnlen kernam_len, ftnlen nornam_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: swpool_ 14 5 13 4 13 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dtpool_ 14 6 13 12 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: gcpool_ 14 8 13 4 4 4 13 12 124 124 */
/*:ref: gipool_ 14 7 13 4 4 4 4 12 124 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: zzsrfini_ 14 12 13 4 4 4 4 4 4 4 4 4 4 124 */
 
extern int zzsrftrn_(void *cspice_state, integer *bodyid, char *srfnam, integer *surfid, integer *usrctr, logical *found, logical *update, ftnlen srfnam_len);
extern int zzsrfn2c_(void *cspice_state, char *srfnam, integer *bodyid, integer *surfid, logical *found, ftnlen srfnam_len);
extern int zzsrfc2n_(void *cspice_state, integer *surfid, integer *bodyid, char *srfnam, logical *found, ftnlen srfnam_len);
extern int zzsrftrk_(void *cspice_state, integer *usrctr, logical *update);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzctrsin_ 14 1 4 */
/*:ref: zzctruin_ 14 1 4 */
/*:ref: zzsrfker_ 14 14 13 13 4 4 12 4 4 4 4 4 4 4 124 124 */
/*:ref: zzcvpool_ 14 4 13 4 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: zzctrinc_ 14 1 4 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: zzhash2_ 4 3 13 4 124 */
/*:ref: zzhashi_ 4 2 4 4 */
/*:ref: zzctrchk_ 14 3 4 4 12 */
 
extern int zzstelab_(void *cspice_state, logical *xmit, doublereal *accobs, doublereal *vobs, doublereal *starg, doublereal *scorr, doublereal *dscorr);
/*:ref: return_ 12 0 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: dvhat_ 14 2 7 7 */
/*:ref: vperp_ 14 3 7 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vzero_ 12 1 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: vlcom3_ 14 7 7 7 7 7 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: qderiv_ 14 5 4 7 7 7 7 */
 
extern int zztangnt_(void *cspice_state, integer *curve, doublereal *srcrad, integer *shape, integer *trgcde, integer *nsurf, integer *srflst, integer *fixfid, doublereal *et, doublereal *plnvec, doublereal *axis, doublereal *schstp, doublereal *soltol, doublereal *result, doublereal *points);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: vrotv_ 14 4 7 7 7 7 */
/*:ref: pi_ 7 0 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: zztanini_ 14 10 4 7 4 4 4 4 4 7 7 7 */
/*:ref: zzmaxrad_ 14 1 7 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: dasine_ 7 2 7 7 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: zztanslv_ 14 11 200 200 200 12 7 7 7 7 7 7 12 */
/*:ref: cardd_ 4 1 7 */
 
extern int zztanslv_(void *cspice_state, S_fp udcond, S_fp udstep, S_fp udrefn, logical *cstep, doublereal *step, doublereal *start, doublereal *finish, doublereal *tol, doublereal *result, doublereal *points, logical *endflg);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: touchd_ 7 1 7 */
/*:ref: sized_ 4 1 7 */
/*:ref: failed_ 12 0 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: brcktd_ 7 3 7 7 7 */
/*:ref: zzwninsd_ 14 5 7 7 13 7 124 */
 
extern int zztanutl_(void *cspice_state, integer *curve, doublereal *srcrad, integer *shape, integer *trgcde, integer *nsurf, integer *srflst, integer *fixfid, doublereal *et, doublereal *plnvec, doublereal *axis, doublereal *angle, logical *ocultd, doublereal *point);
extern int zztanini_(void *cspice_state, integer *curve, doublereal *srcrad, integer *shape, integer *trgcde, integer *nsurf, integer *srflst, integer *fixfid, doublereal *et, doublereal *plnvec, doublereal *axis);
extern int zztansta_(void *cspice_state, doublereal *angle, logical *ocultd, doublereal *point);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: return_ 12 0 */
/*:ref: vzero_ 12 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: vhatip_ 14 1 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: zzsuelin_ 14 1 4 */
/*:ref: zzsudski_ 14 4 4 4 4 4 */
/*:ref: vrotv_ 14 4 7 7 7 7 */
/*:ref: zzraysfx_ 14 5 7 7 7 7 12 */
/*:ref: pi_ 7 0 */
/*:ref: vsclip_ 14 2 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
 
extern int zzteme_(void *cspice_state, doublereal *et, doublereal *mt);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzeprc76_ 14 2 7 7 */
/*:ref: invstm_ 14 2 7 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: zzenut80_ 14 2 7 7 */
/*:ref: mxvg_ 14 5 7 7 4 4 7 */
/*:ref: zztwovxf_ 14 5 7 4 7 4 7 */
/*:ref: chkout_ 14 2 13 124 */
 
extern logical zztime_(void *cspice_state, char *string, char *transl, char *letter, char *error, char *pic, doublereal *tvec, integer *b, integer *e, logical *l2r, logical *yabbrv, ftnlen string_len, ftnlen transl_len, ftnlen letter_len, ftnlen error_len, ftnlen pic_len);
extern logical zzcmbt_(void *cspice_state, char *string, char *letter, logical *l2r, ftnlen string_len, ftnlen letter_len);
extern logical zzgrep_(void *cspice_state, char *string, ftnlen string_len);
extern logical zzispt_(void *cspice_state, char *string, integer *b, integer *e, ftnlen string_len);
extern logical zzist_(void *cspice_state, char *letter, ftnlen letter_len);
extern logical zznote_(void *cspice_state, char *letter, integer *b, integer *e, ftnlen letter_len);
extern logical zzremt_(void *cspice_state, char *letter, ftnlen letter_len);
extern logical zzsubt_(void *cspice_state, char *string, char *transl, logical *l2r, ftnlen string_len, ftnlen transl_len);
extern logical zztokns_(void *cspice_state, char *string, char *error, ftnlen string_len, ftnlen error_len);
extern logical zzunpck_(void *cspice_state, char *string, logical *yabbrv, doublereal *tvec, integer *e, char *transl, char *pic, char *error, ftnlen string_len, ftnlen transl_len, ftnlen pic_len, ftnlen error_len);
extern logical zzvalt_(void *cspice_state, char *string, integer *b, integer *e, char *letter, ftnlen string_len, ftnlen letter_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: pos_ 4 5 13 13 4 124 124 */
/*:ref: posr_ 4 5 13 13 4 124 124 */
/*:ref: zzrepsub_ 14 8 13 4 4 13 13 124 124 124 */
/*:ref: cpos_ 4 5 13 13 4 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: lx4uns_ 14 5 13 4 4 4 124 */
/*:ref: zztknerr_ 14 9 13 13 13 13 12 124 124 124 124 */
/*:ref: zzinssub_ 14 7 13 13 4 13 124 124 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: samsbi_ 12 8 13 4 4 13 4 4 124 124 */
/*:ref: samchi_ 12 6 13 4 13 4 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: nparsd_ 14 6 13 7 13 4 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: zzmkpc_ 14 8 13 4 4 13 13 124 124 124 */
/*:ref: nparsi_ 14 6 13 4 13 4 124 124 */
 
extern int zztknerr_(void *cspice_state, char *templt, char *string, char *token, char *error, logical *status, ftnlen templt_len, ftnlen string_len, ftnlen token_len, ftnlen error_len);
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
 
extern int zztogrid_(void *cspice_state, doublereal *modxyz, doublereal *voxori, doublereal *voxsiz, doublereal *grdxyz);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern logical zztpats_(void *cspice_state, integer *room, integer *nknown, char *known, char *meanng, ftnlen known_len, ftnlen meanng_len);
/*:ref: orderc_ 14 4 13 4 4 124 */
/*:ref: reordc_ 14 4 4 4 13 124 */
 
extern int zztrvlnk_(void *cspice_state, integer *aval, integer *maxa, integer *pntrs, integer *cellsz, integer *cells, integer *maxb, integer *nb, integer *blist);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zztwovxf_(void *cspice_state, doublereal *axdef, integer *indexa, doublereal *plndef, integer *indexp, doublereal *xform);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dvhat_ 14 2 7 7 */
/*:ref: ducrss_ 14 3 7 7 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: vzero_ 12 1 7 */
 
extern int zzuntngl_(void *cspice_state, integer *nptr, integer *maxcel, integer *cells, integer *maxb, integer *pntrs, integer *nout, integer *outlst);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zztrvlnk_ 14 8 4 4 4 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
 
extern int zzutcpm_(void *cspice_state, char *string, integer *start, doublereal *hoff, doublereal *moff, integer *last, logical *succes, ftnlen string_len);
/*:ref: lx4uns_ 14 5 13 4 4 4 124 */
/*:ref: nparsd_ 14 6 13 7 13 4 124 124 */
/*:ref: samch_ 12 6 13 4 13 4 124 124 */
 
extern int zzvalcor_(void *cspice_state, char *abcorr, logical *attblk, ftnlen abcorr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzprscor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
 
extern integer zzvox2id_(void *cspice_state, integer *vixyz, integer *nvox);
 
extern int zzvoxcvo_(void *cspice_state, integer *vixyz, integer *nvox, integer *cgrscl, integer *cgxyz, integer *cgoff, integer *cgof1d);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
 
extern int zzvrtplt_(void *cspice_state, integer *nv, integer *np, integer *plates, integer *cellsz, integer *maxlst, integer *cells, integer *vrtptr, integer *nlist, integer *pltlst);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: zzinilnk_ 14 5 4 4 4 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: zzaddlnk_ 14 7 4 4 4 4 4 4 4 */
/*:ref: zzuntngl_ 14 7 4 4 4 4 4 4 4 */
 
extern int zzvstrng_(void *cspice_state, doublereal *x, char *fill, integer *from, integer *to, logical *rnd, integer *expont, char *substr, logical *did, ftnlen fill_len, ftnlen substr_len);
extern int zzvststr_(void *cspice_state, doublereal *x, char *fill, integer *expont, ftnlen fill_len);
extern int zzvsbstr_(void *cspice_state, integer *from, integer *to, logical *rnd, char *substr, logical *did, ftnlen substr_len);
/*:ref: dpstr_ 14 4 7 4 13 124 */
 
extern int zzwahr_(void *cspice_state, doublereal *et, doublereal *dvnut);
/*:ref: pi_ 7 0 */
/*:ref: twopi_ 7 0 */
/*:ref: spd_ 7 0 */
 
extern integer zzwind_(void *cspice_state, doublereal *plane, integer *n, doublereal *vertcs, doublereal *point);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: pl2nvc_ 14 3 7 7 7 */
/*:ref: vzero_ 12 1 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vperp_ 14 3 7 7 7 */
/*:ref: vsep_ 7 2 7 7 */
/*:ref: ucrss_ 14 3 7 7 7 */
/*:ref: twopi_ 7 0 */
 
extern integer zzwind2d_(void *cspice_state, integer *n, doublereal *vertcs, doublereal *point);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vsubg_ 14 4 7 7 4 7 */
/*:ref: vsepg_ 7 3 7 7 4 */
/*:ref: vdotg_ 7 3 7 7 4 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: twopi_ 7 0 */
 
extern int zzwninsd_(void *cspice_state, doublereal *left, doublereal *right, char *context, doublereal *window, ftnlen context_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: cardd_ 4 1 7 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: errint_ 14 3 13 4 124 */
 
extern int zzxlated_(void *cspice_state, integer *inbff, char *input, integer *space, doublereal *output, ftnlen input_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzddhgsd_ 14 5 13 4 13 124 124 */
/*:ref: zzplatfm_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: intmin_ 4 0 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: moved_ 14 3 7 4 7 */
 
extern int zzxlatei_(void *cspice_state, integer *inbff, char *input, integer *space, integer *output, ftnlen input_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzddhgsd_ 14 5 13 4 13 124 124 */
/*:ref: zzplatfm_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: intmin_ 4 0 */
/*:ref: errint_ 14 3 13 4 124 */
 
 
#ifdef __cplusplus
   }
#endif
 
#endif
 
