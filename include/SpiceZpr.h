/*

-Header_File SpiceZpr.h ( CSPICE prototypes )

-Abstract

   Define prototypes for CSPICE user-interface-level functions.

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

-Particulars

   This C header file contains prototypes for CSPICE user-level
   C routines.  Prototypes for the underlying f2c'd SPICELIB routines
   are contained in the separate header file SpiceZfc.  However, those
   routines are not part of the official CSPICE API.

-Author_and_Institution

   N.J. Bachman       (JPL)
   K.R. Gehringer     (JPL)
   W.L. Taber         (JPL)
   F.S. Turner        (JPL)
   E.D. Wright        (JPL)

-Version

   -CSPICE Version 12.14.0, 05-JAN-2017 (EDW) (NJB)

      Added prototypes for

         chbder_c
         cleard_c
         dasdc_c
         dashfn_c
         dasopw_c 
         dasrfr_c
         dlabbs_c 
         dlabfs_c
         dlafns_c
         dlafps_c
         dskb02_c
         dskcls_c
         dskd02_c
         dskgd_c
         dskgtl_c
         dski02_c
         dskmi2_c 
         dskn02_c
         dskobj_c
         dskopn_c
         dskp02_c
         dskrb2_c
         dsksrf_c
         dskstl_c
         dskv02_c
         dskw02_c
         dskx02_c
         dskxsi_c
         dskxv_c
         dskz02_c
         hrmint_c
         illum_pl02
         illum_plid_pl02
         latsrf_c
         lgrind_c
         limb_pl02
         limbpt_c
         llgrid_pl02
         oscltx_c
         pckcls_c
         pckopn_c
         pckw02_c
         pltar_c
         pltexp_c
         pltnp_c
         pltnrm_c
         pltvol_c
         polyds_c
         srfc2s_c
         srfcss_c
         srfnrm_c
         srfs2c_c
         srfscc_c
         subpt_pl02
         subsol_pl02
         term_pl02
         termpt_c

   -CSPICE Version 12.13.0, 03-DEC-2013 (NJB) (SCK) (EDW)

      Correction to argument order for gfsep_c.c prototype.

      Added prototypes for

         bltfrm_c
         ccifrm_c
         edterm_c
         eqncpv_c
         fovray_c
         fovtrg_c
         gfilum_c
         gfpa_c
         gfstol_c
         gfudb_c
         illumg_c
         kplfrm_c
         occult_c
         phaseq_c
         pxfrm2_c
         qcktrc_c
         trcdep_c
         trcnam_c
         spkcpo_c
         spkcpt_c
         spkcvo_c
         spkcvt_c
         spkpvn_c
         spksfs_c
         spkw20_c
         xfmsta_c
         udf_c

   -CSPICE Version 12.12.0, 19-FEB-2010 (EDW) (NJB)

      Added prototypes for

         bodc2s_c
         dafgsr_c
         dafrfr_c
         dp2hx_c
         ducrss_c
         dvcrss_c
         dvnorm_c
         gfrr_c
         gfuds_c
         hx2dp_c
         uddc_c
         uddf_c

   -CSPICE Version 12.11.0, 29-MAR-2009 (EDW) (NJB)

      Added prototypes for

         dvsep_c
         gfbail_c
         gfclrh_c
         gfdist_c
         gfevnt_c
         gffove_c
         gfinth_c
         gfocce_c
         gfoclt_c
         gfposc_c
         gfrefn_c
         gfrepf_c
         gfrepi_c
         gfrepu_c
         gfrfov_c
         gfsep_c
         gfseth_c
         gfsntc_c
         gfsstp_c
         gfstep_c
         gfsubc_c
         gftfov_c
         surfpv_c
         zzgfgeth_c
         zzgfsavh_c

   -CSPICE Version 12.10.0, 30-JAN-2008 (EDW) (NJB)

      Added prototypes for:

         ilumin_c
         pckcov_c
         pckfrm_c
         sincpt_c
         spkacs_c
         spkaps_c
         spkltc_c
         subpnt_c
         subslr_c
         wncard_c

   -CSPICE Version 12.9.0, 16-NOV-2006 (NJB)

      Bug fix:  corrected prototype for vhatg_c.

      Renamed wnfild_c and wnfltd_c arguments `small' to 'smal' for
      compatibility with MS Visual C++.

      Added prototypes for

         dafac_c
         dafdc_c
         dafec_c
         dafgda_c
         dascls_c
         dasopr_c
         kclear_c

   -CSPICE Version 12.8.0, 07-NOV-2005 (NJB)

      Added prototypes for

         bodvcd_c
         qdq2av_c
         qxq_c
         srfrec_c

   -CSPICE Version 12.7.0, 06-JAN-2004 (NJB)

      Added prototypes for

         bods2c_c
         ckcov_c
         ckobj_c
         dafopw_c
         dafrs_c
         dpgrdr_c
         drdpgr_c
         lspcn_c
         pgrrec_c
         recpgr_c
         spkcov_c
         spkobj_c

   -CSPICE Version 12.6.0, 24-FEB-2003 (NJB)

      Added prototype for

         bodvrd_c
         deltet_c
         srfxpt_c

   -CSPICE Version 12.5.0, 14-MAY-2003 (NJB)

      Removed prototype for getcml_.


   -CSPICE Version 12.4.0, 25-FEB-2003 (NJB)

      Added prototypes for

         dasac_c
         dasec_c
         et2lst_c

   -CSPICE Version 12.3.0, 03-SEP-2002 (NJB)

      Added prototypes for

         appndc_c
         appndd_c
         appndi_c
         bschoc_c
         bschoi_c
         bsrchc_c
         bsrchd_c
         bsrchi_c
         card_c
         ckw05_c
         copy_c
         cpos_c
         cposr_c
         diff_c
         elemc_c
         elemd_c
         elemi_c
         esrchc_c
         insrtc_c
         insrtd_c
         insrti_c
         inter_c
         isordv_c
         isrchc_c
         isrchd_c
         isrchi_c
         lparss_c
         lstlec_c
         lstled_c
         lstlei_c
         lstltc_c
         lstltd_c
         lstlti_c
         lx4dec_c
         lx4num_c
         lx4sgn_c
         lx4uns_c
         lxqstr_c
         ncpos_c
         ncposr_c
         ordc_c
         ordd_c
         orderc_c
         orderd_c
         orderi_c
         ordi_c
         pos_c
         posr_c
         prefix_c
         removc_c
         removd_c
         remove_c
         removi_c
         reordc_c
         reordd_c
         reordi_c
         reordl_c
         repmc_c
         repmct_c
         repmd_c
         repmf_c
         repmi_c
         repmot_c
         scard_c
         sdiff_c
         set_c
         shellc_c
         shelld_c
         shelli_c
         size_c
         spkw18_c
         ssize_c
         union_c
         valid_c
         wncomd_c
         wncond_c
         wndifd_c
         wnelmd_c
         wnexpd_c
         wnextd_c
         wnfetd_c
         wnfild_c
         wnfltd_c
         wnincd_c
         wninsd_c
         wnintd_c
         wnreld_c
         wnsumd_c
         wnunid_c
         wnvald_c
         zzsynccl_c

   -CSPICE Version 12.2.0, 23-OCT-2001 (NJB)

      Added prototypes for

         badkpv_c
         dcyldr_c
         dgeodr_c
         dlatdr_c
         drdcyl_c
         drdgeo_c
         drdlat_c
         drdsph_c
         dsphdr_c
         ekacec_c
         ekaced_c
         ekacei_c
         ekappr_c
         ekbseg_c
         ekccnt_c
         ekcii_c
         ekdelr_c
         ekinsr_c
         ekntab_c
         ekrcec_c
         ekrced_c
         ekrcei_c
         ektnam_c
         ekucec_c
         ekuced_c
         ekucei_c
         inelpl_c
         invort_c
         kxtrct_c

      Added const qualifier to input array arguments of

         conics_c
         illum_c
         pdpool_c
         prop2b_c
         q2m_c
         spkuds_c
         xposeg_c

      Added const qualifier to the return value of

         tkvrsn_c

   -CSPICE Version 12.1.0, 12-APR-2000 (FST)

      Added prototype for

         getfov_c

   -CSPICE Version 12.0.0, 22-MAR-2000 (NJB)

      Added prototypes for

         lparse_c
         lparsm_c
         spkw12_c
         spkw13_c


   -CSPICE Version 11.1.0, 17-DEC-1999 (WLT)

      Added prototype for

         dafrda_c

   -CSPICE Version 11.0.0, 07-OCT-1999 (NJB) (EDW)

      Changed ekaclc_c, ekacld_c, ekacli_c prototypes to make input
      pointers const-qualified where appropriate.

      Changed prompt_c prototype to accommodate memory leak bug fix.

      Changed ekpsel_c prototype to be consistent with other interfaces
      having string array outputs.

      Added prototypes for

         axisar_c
         brcktd_c
         brckti_c
         cgv2el_c
         cidfrm_c
         clpool_c
         cmprss_c
         cnmfrm_c
         convrt_c
         cvpool_c
         dafbbs_c
         dafbfs_c
         dafcls_c
         dafcs_c
         daffna_c
         daffpa_c
         dafgh_c
         dafgn_c
         dafgs_c
         dafopr_c
         dafps_c
         dafus_c
         diags2_c
         dtpool_c
         dvdot_c
         dvhat_c
         dvpool_c
         edlimb_c
         ekops_c
         ekopw_c
         eul2xf_c
         ftncls_c
         furnsh_c
         getelm_c
         getmsg_c
         gnpool_c
         ident_c
         illum_c
         inedpl_c
         kdata_c
         kinfo_c
         ktotal_c
         lmpool_c
         matchi_c
         matchw_c
         maxd_c
         maxi_c
         mequ_c
         mind_c
         mini_c
         moved_
         npedln_c
         npelpt_c
         nplnpt_c
         pcpool_c
         pdpool_c
         pipool_c
         pjelpl_c
         pxform_c
         rav2xf_c
         raxisa_c
         rquad_c
         saelgv_c
         spk14a_c
         spk14b_c
         spk14e_c
         spkapo_c
         spkapp_c
         spkcls_c
         spkezp_c
         spkgps_c
         spkopn_c
         spkpds_c
         spkpos_c
         spkssb_c
         spksub_c
         spkuds_c
         spkw02_c
         spkw03_c
         spkw05_c
         spkw08_c
         spkw09_c
         spkw10_c
         spkw15_c
         spkw17_c
         stpool_c
         subpt_c
         subsol_c
         swpool_c
         szpool_c
         tparse_c
         trace_c
         unload_c
         vaddg_c
         vhatg_c
         vlcomg_c
         vminug_c
         vrel_c
         vrelg_c
         vsepg_c
         vtmv_c
         vtmvg_c
         vzerog_c
         xf2eul_c
         xf2rav_c
         xposeg_c

   -CSPICE Version 10.0.0, 09-MAR-1999 (NJB)

      Added prototypes for

         frame_c
         inrypl_c
         nvc2pl_c
         nvp2pl_c
         pl2nvc_c
         pl2nvp_c
         pl2psv_c
         psv2pl_c
         sce2c_c
         vprjp_c
         vprjpi_c

      Now conditionally includes SpiceEll.h and SpicePln.h.


   -CSPICE Version 9.0.0, 25-FEB-1999 (NJB)

      Added prototypes for

         eknseg_c
         eknelt_c
         ekpsel_c
         ekssum_c

      Now conditionally includes SpiceEK.h.


   -CSPICE Version 8.0.0, 20-OCT-1998 (NJB)

      Added const qualifier to all input matrix and vector arguments.

      Added prototypes for

         det_c
         dpmax_c
         dpmax_
         dpmin_c
         dpmin_
         frinfo_c
         frmnam_c
         getfat_c
         intmax_c
         intmax_
         intmin_c
         intmin_
         invert_c
         namfrm_c
         vrotv_c
         vsclg_c


   -CSPICE Version 7.0.0, 02-APR-1998 (EDW)

      Added prototypes for

         mequg_c
         unormg_g
         vdistg_c
         vdotg_c
         vequg_c
         vnormg_c

   -CSPICE Version 6.0.0, 31-MAR-1998 (NJB)

      Added prototypes for

         ekaclc_c
         ekacld_c
         ekacli_c
         ekcls_c
         ekffld_c
         ekfind_c
         ekgc_c
         ekgd_c
         ekgi_c
         ekifld_c
         eklef_c
         ekopr_c
         ekopn_c
         ekuef_c

   -CSPICE Version 5.0.1, 05-MAR-1998 (EDW)

      Remove some non printing characters.

   -CSPICE Version 5.0.0, 03-MAR-1998 (NJB)

      Added prototypes for

         etcal_c
         ltime_c
         stelab_c
         tpictr_c
         twovec_c
         vsubg_c

   -CSPICE Version 4.0.0, 11-FEB-1998 (EDW)

      Added prototypes for

         timdef_c
         tsetyr_c


   -CSPICE Version 3.0.0, 02-FEB-1998 (NJB)

      Added prototypes for

         pckuof_c
         tipbod_c

      Type SpiceVoid was replaced with void.

   -CSPICE Version 2.0.0, 06-JAN-1998 (NJB)

      Changed all input-only character pointers to type ConstSpiceChar.

   -CSPICE Version 1.0.0, 25-OCT-1997 (NJB) (KRG) (EDW)

-Index_Entries

   prototypes of CSPICE functions

*/


/*
Include Files:
*/


#ifndef  HAVE_SPICEDEFS_H
#include "SpiceZdf.h"
#endif

#ifndef  HAVE_SPICE_CELLS_H
#include "SpiceCel.h"
#endif

#ifndef  HAVE_SPICE_DLA_H
#include "SpiceDLA.h"
#endif

#ifndef  HAVE_SPICE_DSK_H
#include "SpiceDSK.h"
#endif

#ifndef  HAVE_SPICE_EK_H
#include "SpiceEK.h"
#endif

#ifndef  HAVE_SPICE_PLANES_H
#include "SpicePln.h"
#endif

#ifndef  HAVE_SPICE_ELLIPSES_H
#include "SpiceEll.h"
#endif 

#ifndef  HAVE_SPICE_OSC_H
#include "SpiceOsc.h"
#endif

#ifndef  HAVE_SPICE_SPK_H
#include "SpiceSPK.h"
#endif

#ifndef HAVE_SPICEWRAPPERS_H
#define HAVE_SPICEWRAPPERS_H




/*
   Function prototypes for CSPICE functions are listed below.
   Each prototype is accompanied by a function abstract and brief I/O
   description.

   See the headers of the C wrappers for detailed descriptions of the
   routines' interfaces.

   The list below should be maintained in alphabetical order.
*/

   void              appndc_c ( void               * naif_state,
                                ConstSpiceChar     * item,
                                SpiceCell          * cell  );


   void              appndd_c ( void               * naif_state,
                                SpiceDouble          item,
                                SpiceCell          * cell  );


   void              appndi_c ( void               * naif_state,
                                SpiceInt             item,
                                SpiceCell          * cell  );


   void              axisar_c ( void               * naif_state,
                                ConstSpiceDouble     axis   [3],
                                SpiceDouble          angle,
                                SpiceDouble          r      [3][3]  );


   SpiceBoolean      badkpv_c ( void               * naif_state,
                                ConstSpiceChar      *caller,
                                ConstSpiceChar      *name,
                                ConstSpiceChar      *comp,
                                SpiceInt             size,
                                SpiceInt             divby,
                                SpiceChar            type   );


   void              bltfrm_c ( void               * naif_state,
                                SpiceInt             frmcls,
                                SpiceCell          * idset  );


   void              bodc2n_c ( void               * naif_state,
                                SpiceInt             code,
                                SpiceInt             namelen,
                                SpiceChar          * name,
                                SpiceBoolean       * found   );


   void              bodc2s_c ( void               * naif_state,
                                SpiceInt             code,
                                SpiceInt             lenout,
                                SpiceChar          * name );

   void              boddef_c ( void               * naif_state,
                                ConstSpiceChar     * name,
                                SpiceInt             code );


   SpiceBoolean      bodfnd_c ( void               * naif_state,
                                SpiceInt             body,
                                ConstSpiceChar     * item );


   void              bodn2c_c ( void               * naif_state,
                                ConstSpiceChar     * name,
                                SpiceInt           * code,
                                SpiceBoolean       * found );


   void              bods2c_c ( void               * naif_state,
                                ConstSpiceChar     * name,
                                SpiceInt           * code,
                                SpiceBoolean       * found );


   void              bodvar_c ( void               * naif_state,
                                SpiceInt             body,
                                ConstSpiceChar     * item,
                                SpiceInt           * dim ,
                                SpiceDouble        * values );


   void              bodvcd_c ( void               * naif_state,
                                SpiceInt             body,
                                ConstSpiceChar     * item,
                                SpiceInt             maxn,
                                SpiceInt           * dim ,
                                SpiceDouble        * values );


   void              bodvrd_c ( void               * naif_state,
                                ConstSpiceChar     * body,
                                ConstSpiceChar     * item,
                                SpiceInt             maxn,
                                SpiceInt           * dim ,
                                SpiceDouble        * values );


   SpiceDouble       brcktd_c ( void               * naif_state,
                                SpiceDouble          number,
                                SpiceDouble          end1,
                                SpiceDouble          end2    );


   SpiceInt          brckti_c ( void               * naif_state,
                                SpiceInt             number,
                                SpiceInt             end1,
                                SpiceInt             end2    );


   SpiceInt          bschoc_c ( void               * naif_state,
                                ConstSpiceChar     * value,
                                SpiceInt             ndim,
                                SpiceInt             lenvals,
                                const void         * array,
                                ConstSpiceInt      * order  );


   SpiceInt          bschoi_c ( void               * naif_state,
                                SpiceInt             value,
                                SpiceInt             ndim,
                                ConstSpiceInt      * array,
                                ConstSpiceInt      * order  );


   SpiceInt          bsrchc_c ( void               * naif_state,
                                ConstSpiceChar     * value,
                                SpiceInt             ndim,
                                SpiceInt             lenvals,
                                const void         * array   );


   SpiceInt          bsrchd_c ( void               * naif_state,
                                SpiceDouble          value,
                                SpiceInt             ndim,
                                ConstSpiceDouble   * array );


   SpiceInt          bsrchi_c ( void               * naif_state,
                                SpiceInt             value,
                                SpiceInt             ndim,
                                ConstSpiceInt      * array );


   SpiceDouble       b1900_c( void               * naif_state );


   SpiceDouble       b1950_c( void               * naif_state );


   SpiceInt          card_c   ( void               * naif_state,
                                 SpiceCell         * cell );


   void              ccifrm_c ( void               * naif_state,
                                SpiceInt            frclss,
                                SpiceInt            clssid,
                                SpiceInt            lenout,
                                SpiceInt          * frcode,
                                SpiceChar         * frname,
                                SpiceInt          * center,
                                SpiceBoolean      * found   );


   void              cgv2el_c ( void               * naif_state,
                                ConstSpiceDouble    center[3],
                                ConstSpiceDouble    vec1  [3],
                                ConstSpiceDouble    vec2  [3],
                                SpiceEllipse      * ellipse   );


   void              chbder_c ( void               * naif_state,
                                ConstSpiceDouble * cp,
                                SpiceInt           degp,
                                SpiceDouble        x2s[2],
                                SpiceDouble        x,
                                SpiceInt           nderiv,
                                SpiceDouble      * partdp,
                                SpiceDouble      * dpdxs );


   void              chkin_c( void               * naif_state,
                                ConstSpiceChar    * module );


   void              chkout_c ( void              * naif_state,
                                ConstSpiceChar    * module );


   void              cidfrm_c ( void               * naif_state,
                                SpiceInt            cent,
                                SpiceInt            lenout,
                                SpiceInt          * frcode,
                                SpiceChar         * frname,
                                SpiceBoolean      * found  );


   void              ckcls_c( void               * naif_state,
                                 SpiceInt            handle );


   void              ckcov_c( void               * naif_state,
                                 ConstSpiceChar    * ck,
                                SpiceInt            idcode,
                                SpiceBoolean        needav,
                                ConstSpiceChar    * level,
                                SpiceDouble         tol,
                                ConstSpiceChar    * timsys,
                                SpiceCell         * cover   );


   void              ckobj_c( void               * naif_state,
                                 ConstSpiceChar    * ck,
                                SpiceCell         * ids );


   void              ckgp_c   ( void               * naif_state,
                                 SpiceInt            inst,
                                SpiceDouble         sclkdp,
                                SpiceDouble         tol,
                                ConstSpiceChar    * ref,
                                SpiceDouble         cmat[3][3],
                                SpiceDouble       * clkout,
                                SpiceBoolean      * found      );


   void              ckgpav_c ( void               * naif_state,
                                SpiceInt            inst,
                                SpiceDouble         sclkdp,
                                SpiceDouble         tol,
                                ConstSpiceChar    * ref,
                                SpiceDouble         cmat[3][3],
                                SpiceDouble         av[3],
                                SpiceDouble       * clkout,
                                SpiceBoolean      * found      );


   void              cklpf_c( void               * naif_state,
                                 ConstSpiceChar    * fname,
                                SpiceInt          * handle    );


   void              ckopn_c( void               * naif_state,
                                 ConstSpiceChar    * name,
                                ConstSpiceChar    * ifname,
                                SpiceInt            ncomch,
                                SpiceInt          * handle  );


   void              ckupf_c( void               * naif_state,
                                 SpiceInt            handle );


   void              ckw01_c( void               * naif_state,
                                 SpiceInt            handle,
                                SpiceDouble         begtime,
                                SpiceDouble         endtime,
                                SpiceInt            inst,
                                ConstSpiceChar    * ref,
                                SpiceBoolean        avflag,
                                ConstSpiceChar    * segid,
                                SpiceInt            nrec,
                                ConstSpiceDouble    sclkdp [],
                                ConstSpiceDouble    quats  [][4],
                                ConstSpiceDouble    avvs   [][3]  );


   void              ckw02_c( void               * naif_state,
                                 SpiceInt            handle,
                                SpiceDouble         begtim,
                                SpiceDouble         endtim,
                                SpiceInt            inst,
                                ConstSpiceChar    * ref,
                                ConstSpiceChar    * segid,
                                SpiceInt            nrec,
                                ConstSpiceDouble    start  [],
                                ConstSpiceDouble    stop   [],
                                ConstSpiceDouble    quats  [][4],
                                ConstSpiceDouble    avvs   [][3],
                                ConstSpiceDouble    rates  []    );


   void              ckw03_c( void               * naif_state,
                                 SpiceInt            handle,
                                SpiceDouble         begtim,
                                SpiceDouble         endtim,
                                SpiceInt            inst,
                                ConstSpiceChar    * ref,
                                SpiceBoolean        avflag,
                                ConstSpiceChar    * segid,
                                SpiceInt            nrec,
                                ConstSpiceDouble    sclkdp [],
                                ConstSpiceDouble    quats  [][4],
                                ConstSpiceDouble    avvs   [][3],
                                SpiceInt            nints,
                                ConstSpiceDouble    starts []     );


   void              ckw05_c( void               * naif_state,
                                 SpiceInt             handle,
                                SpiceCK05Subtype     subtyp,
                                SpiceInt             degree,
                                SpiceDouble          begtim,
                                SpiceDouble          endtim,
                                SpiceInt             inst,
                                ConstSpiceChar     * ref,
                                SpiceBoolean         avflag,
                                ConstSpiceChar     * segid,
                                SpiceInt             n,
                                ConstSpiceDouble     sclkdp[],
                                const void         * packets,
                                SpiceDouble          rate,
                                SpiceInt             nints,
                                ConstSpiceDouble     starts[]     );


   void              cleard_c ( void               * naif_state,
                                SpiceInt             ndim,
                                SpiceDouble        * array );


   SpiceDouble       clight_c ( void               * naif_state );


   void              clpool_c ( void               * naif_state );


   void              cmprss_c ( void               * naif_state,
                                SpiceChar           delim,
                                SpiceInt            n,
                                ConstSpiceChar    * input,
                                SpiceInt            lenout,
                                SpiceChar         * output  );


   void              cnmfrm_c ( void               * naif_state,
                                ConstSpiceChar    * cname,
                                SpiceInt            lenout,
                                SpiceInt          * frcode,
                                SpiceChar         * frname,
                                SpiceBoolean      * found   );


   void              conics_c ( void               * naif_state,
                                ConstSpiceDouble    elts[8],
                                SpiceDouble         et,
                                SpiceDouble         state[6] );


   void              convrt_c ( void               * naif_state,
                                SpiceDouble         x,
                                ConstSpiceChar    * in,
                                ConstSpiceChar    * out,
                                SpiceDouble       * y    );


   void              copy_c   ( void               * naif_state,
                                 SpiceCell         * a,
                                SpiceCell         * b     );



   SpiceInt          cpos_c   ( void               * naif_state,
                                 ConstSpiceChar    * str,
                                ConstSpiceChar    * chars,
                                SpiceInt            start  );


   SpiceInt          cposr_c( void               * naif_state,
                                 ConstSpiceChar    * str,
                                ConstSpiceChar    * chars,
                                SpiceInt            start  );


   void              cvpool_c ( void               * naif_state,
                                ConstSpiceChar    * agent,
                                SpiceBoolean      * update );


   void              cyllat_c ( void               * naif_state,
                                SpiceDouble         r,
                                SpiceDouble         lonc,
                                SpiceDouble         z,
                                SpiceDouble       * radius,
                                SpiceDouble       * lon,
                                SpiceDouble       * lat );


   void              cylrec_c ( void               * naif_state,
                                SpiceDouble         r,
                                SpiceDouble         lon,
                                SpiceDouble         z,
                                SpiceDouble         rectan[3] );


   void              cylsph_c ( void               * naif_state,
                                SpiceDouble         r,
                                SpiceDouble         lonc,
                                SpiceDouble         z,
                                SpiceDouble       * radius,
                                SpiceDouble       * colat,
                                SpiceDouble       * lon );


   void              dafac_c( void               * naif_state,
                                 SpiceInt            handle,
                                SpiceInt            n,
                                SpiceInt            lenvals,
                                const void        * buffer  );


   void              dafbbs_c ( void               * naif_state,
                                SpiceInt            handle );


   void              dafbfs_c ( void               * naif_state,
                                SpiceInt            handle );


   void              dafcls_c ( void               * naif_state,
                                SpiceInt            handle );


   void              dafcs_c( void               * naif_state,
                                 SpiceInt            handle );


   void              dafdc_c( void               * naif_state,
                                 SpiceInt            handle );


   void              dafec_c( void               * naif_state,
                                 SpiceInt            handle,
                                SpiceInt            bufsiz,
                                SpiceInt            lenout,
                                SpiceInt          * n,
                                void              * buffer,
                                SpiceBoolean      * done    );


   void              daffna_c ( void               * naif_state,
                                SpiceBoolean      * found );


   void              daffpa_c ( void               * naif_state,
                                SpiceBoolean      * found );


   void              dafgda_c ( void               * naif_state,
                                SpiceInt            handle,
                                SpiceInt            begin,
                                SpiceInt            end,
                                SpiceDouble       * data );


   void              dafgh_c( void               * naif_state,
                                 SpiceInt          * handle );


   void              dafgn_c( void               * naif_state,
                                 SpiceInt            lenout,
                                SpiceChar         * name   );


   void              dafgs_c( void               * naif_state,
                                 SpiceDouble         sum[] );


   void              dafgsr_c ( void               * naif_state,
                                SpiceInt            handle,
                                SpiceInt            recno,
                                SpiceInt            begin,
                                SpiceInt            end,
                                SpiceDouble       * data,
                                SpiceBoolean      * found  );


   void              dafopr_c ( void               * naif_state,
                                ConstSpiceChar    * fname,
                                SpiceInt          * handle  );


   void              dafopw_c ( void               * naif_state,
                                ConstSpiceChar    * fname,
                                SpiceInt          * handle );


   void              dafps_c( void               * naif_state,
                                 SpiceInt            nd,
                                SpiceInt            ni,
                                ConstSpiceDouble    dc  [],
                                ConstSpiceInt       ic  [],
                                SpiceDouble         sum []  );


   void              dafrda_c ( void               * naif_state,
                                SpiceInt            handle,
                                SpiceInt            begin,
                                SpiceInt            end,
                                SpiceDouble       * data );



   void              dafrfr_c ( void               * naif_state,
                                SpiceInt            handle,
                                SpiceInt            lenout,
                                SpiceInt          * nd,
                                SpiceInt          * ni,
                                SpiceChar         * ifname,
                                SpiceInt          * fward,
                                SpiceInt          * bward,
                                SpiceInt          * free    );



   void              dafrs_c( void               * naif_state,
                                 ConstSpiceDouble  * sum );


   void              dafus_c( void               * naif_state,
                                 ConstSpiceDouble    sum [],
                                SpiceInt            nd,
                                SpiceInt            ni,
                                SpiceDouble         dc  [],
                                SpiceInt            ic  []  );


   void              dasac_c( void               * naif_state,
                                 SpiceInt            handle,
                                SpiceInt            n,
                                SpiceInt            buflen,
                                const void        * buffer  );


   void              dascls_c ( void               * naif_state,
                                SpiceInt            handle );


   void              dasdc_c( void               * naif_state,
                                 SpiceInt            handle );


   void              dasec_c( void               * naif_state,
                                 SpiceInt            handle,
                                SpiceInt            bufsiz,
                                SpiceInt            buflen,
                                SpiceInt          * n,
                                void              * buffer,
                                SpiceBoolean      * done   );


   void              dashfn_c ( void               * naif_state,
                                SpiceInt            handle,
                                SpiceInt            namlen,
                                SpiceChar         * fname  );


   void              dasopr_c ( void               * naif_state,
                                ConstSpiceChar    * fname,
                                SpiceInt          * handle  );


   void              dasopw_c ( void               * naif_state,
                                ConstSpiceChar    * fname,
                                SpiceInt          * handle  );



   void              dasrfr_c ( void               * naif_state,
                                SpiceInt            handle,
                                SpiceInt            idwlen,
                                SpiceInt            ifnlen,
                                SpiceChar         * idword,
                                SpiceChar         * ifname,
                                SpiceInt          * nresvr,
                                SpiceInt          * nresvc,
                                SpiceInt          * ncomr,
                                SpiceInt          * ncomc   );


   void              dcyldr_c ( void               * naif_state,
                                SpiceDouble         x,
                                SpiceDouble         y,
                                SpiceDouble         z,
                                SpiceDouble         jacobi[3][3] );


   void              deltet_c ( void               * naif_state,
                                SpiceDouble         epoch,
                                ConstSpiceChar    * eptype,
                                SpiceDouble       * delta   );


   SpiceDouble       det_c    ( void               * naif_state,
                                 ConstSpiceDouble    m1[3][3] );


   void              diags2_c ( void               * naif_state,
                                ConstSpiceDouble    symmat [2][2],
                                SpiceDouble         diag   [2][2],
                                SpiceDouble         rotate [2][2]  );


   void              diff_c   ( void               * naif_state,
                                 SpiceCell         * a,
                                SpiceCell         * b,
                                SpiceCell         * c  );


   void              dgeodr_c ( void               * naif_state,
                                SpiceDouble         x,
                                SpiceDouble         y,
                                SpiceDouble         z,
                                SpiceDouble         re,
                                SpiceDouble         f,
                                SpiceDouble         jacobi[3][3] );


   void              dlabbs_c ( void               * naif_state,
                                SpiceInt            handle,
                                SpiceDLADescr     * descr,
                                SpiceBoolean      * found  );


   void              dlabfs_c ( void               * naif_state,
                                SpiceInt          handle,
                                SpiceDLADescr   * descr,
                                SpiceBoolean    * found  );


   void              dlafns_c ( void               * naif_state,
                                SpiceInt               handle,
                                ConstSpiceDLADescr   * descr,
                                SpiceDLADescr        * nxtdsc,
                                SpiceBoolean         * found    );


   void              dlafps_c ( void               * naif_state,
                                SpiceInt               handle,
                                ConstSpiceDLADescr   * descr,
                                SpiceDLADescr        * prvdsc,
                                SpiceBoolean         * found   );


   void              dlatdr_c ( void               * naif_state,
                                SpiceDouble         x,
                                SpiceDouble         y,
                                SpiceDouble         z,
                                SpiceDouble         jacobi[3][3] );


   void              dp2hx_c( void               * naif_state,
                                 SpiceDouble   number,
                                SpiceInt      lenout,
                                SpiceChar   * string,
                                SpiceInt    * length  );


   void              dpgrdr_c ( void               * naif_state,
                                ConstSpiceChar    * body,
                                SpiceDouble         x,
                                SpiceDouble         y,
                                SpiceDouble         z,
                                SpiceDouble         re,
                                SpiceDouble         f,
                                SpiceDouble         jacobi[3][3] );


   SpiceDouble       dpmax_c( void               * naif_state );


   SpiceDouble       dpmax_   ( void               * naif_state );


   SpiceDouble       dpmin_c( void               * naif_state );


   SpiceDouble       dpmin_   ( void               * naif_state );


   SpiceDouble       dpr_c    ( void               * naif_state );


   void              drdcyl_c ( void               * naif_state,
                                SpiceDouble         r,
                                SpiceDouble         lon,
                                SpiceDouble         z,
                                SpiceDouble         jacobi[3][3] );


   void              drdgeo_c ( void               * naif_state,
                                SpiceDouble         lon,
                                SpiceDouble         lat,
                                SpiceDouble         alt,
                                SpiceDouble         re,
                                SpiceDouble         f,
                                SpiceDouble         jacobi[3][3] );


   void              drdlat_c ( void               * naif_state,
                                SpiceDouble         r,
                                SpiceDouble         lon,
                                SpiceDouble         lat,
                                SpiceDouble         jacobi[3][3] );


   void              drdpgr_c ( void               * naif_state,
                                ConstSpiceChar    * body,
                                SpiceDouble         lon,
                                SpiceDouble         lat,
                                SpiceDouble         alt,
                                SpiceDouble         re,
                                SpiceDouble         f,
                                SpiceDouble         jacobi[3][3] );


   void              drdsph_c ( void               * naif_state,
                                SpiceDouble         r,
                                SpiceDouble         colat,
                                SpiceDouble         lon,
                                SpiceDouble         jacobi[3][3] );


   void              dskb02_c ( void               * naif_state,
                                SpiceInt               handle,
                                ConstSpiceDLADescr   * dladsc,
                                SpiceInt             * nv,
                                SpiceInt             * np,
                                SpiceInt             * nvxtot,
                                SpiceDouble            vtxbds  [3][2],
                                SpiceDouble          * voxsiz,
                                SpiceDouble            voxori  [3],
                                SpiceInt               vgrext  [3],
                                SpiceInt             * cgscal,
                                SpiceInt             * vtxnpl,
                                SpiceInt             * voxnpt,
                                SpiceInt             * voxnpl          );


   void              dskcls_c ( void               * naif_state,
                                SpiceInt               handle,
                                SpiceBoolean           optmiz );


   void              dskd02_c ( void               * naif_state,
                                SpiceInt               handle,
                                ConstSpiceDLADescr   * dladsc,
                                SpiceInt               item,
                                SpiceInt               start,
                                SpiceInt               room,
                                SpiceInt             * n,
                                SpiceDouble          * values );


   void              dskgd_c( void               * naif_state,
                                 SpiceInt               handle,
                                ConstSpiceDLADescr   * dladsc,
                                SpiceDSKDescr        * dskdsc );


   void              dskgtl_c ( void               * naif_state,
                                SpiceInt               keywrd,
                                SpiceDouble          * dpval  );


   void              dski02_c ( void               * naif_state,
                                SpiceInt              handle,
                                ConstSpiceDLADescr  * dladsc,
                                SpiceInt              item,
                                SpiceInt              start,
                                SpiceInt              room,
                                SpiceInt            * n,
                                SpiceInt            * values   );

   void              dskobj_c ( void               * naif_state,
                                ConstSpiceChar      * dsk,
                                SpiceCell           * bodids );

   void              dskopn_c ( void               * naif_state,
                                ConstSpiceChar      * fname,
                                ConstSpiceChar      * ifname,
                                SpiceInt              ncomch,
                                SpiceInt           *  handle );


   void              dskn02_c ( void               * naif_state,
                                SpiceInt              handle,
                                ConstSpiceDLADescr  * dladsc,
                                SpiceInt              plid,
                                SpiceDouble           normal[3] );


   void              dskmi2_c ( void               * naif_state,
                                SpiceInt              nv,
                                ConstSpiceDouble      vrtces[][3],
                                SpiceInt              np,
                                ConstSpiceInt         plates[][3],
                                SpiceDouble           finscl,
                                SpiceInt              corscl,
                                SpiceInt              worksz,
                                SpiceInt              voxpsz,
                                SpiceInt              voxlsz,
                                SpiceBoolean          makvtl,
                                SpiceInt              spxisz,
                                SpiceInt              work   [][2],
                                SpiceDouble           spaixd [],
                                SpiceInt              spaixi []    );

                    
   void              dskp02_c ( void               * naif_state,
                                SpiceInt              handle,
                                ConstSpiceDLADescr  * dladsc,
                                SpiceInt              start,
                                SpiceInt              room,
                                SpiceInt            * n,
                                SpiceInt              plates[][3] );


   void              dskrb2_c ( void               * naif_state,
                                SpiceInt              nv,
                                ConstSpiceDouble      vrtces[][3],
                                SpiceInt              np,
                                ConstSpiceInt         plates[][3],
                                SpiceInt              corsys,
                                ConstSpiceDouble      corpar[],
                                SpiceDouble         * mncor3,
                                SpiceDouble         * mxcor3       );


   void              dsksrf_c ( void               * naif_state,
                                ConstSpiceChar      * dsk,
                                SpiceInt              bodyid,
                                SpiceCell           * srfids ); 


   void              dskstl_c ( void               * naif_state,
                                SpiceInt               keywrd,
                                SpiceDouble            dpval  );


   void              dskv02_c ( void               * naif_state,
                                SpiceInt               handle,
                                ConstSpiceDLADescr   * dladsc,
                                SpiceInt               start,
                                SpiceInt               room,
                                SpiceInt             * n,
                                SpiceDouble            vrtces[][3] );


   void              dskw02_c ( void               * naif_state,
                                SpiceInt               handle,
                                SpiceInt               center,
                                SpiceInt               surfce,
                                SpiceInt               dclass,
                                ConstSpiceChar       * frame,
                                SpiceInt               corsys,
                                ConstSpiceDouble       corpar[],
                                SpiceDouble            mncor1,
                                SpiceDouble            mxcor1,
                                SpiceDouble            mncor2,
                                SpiceDouble            mxcor2,
                                SpiceDouble            mncor3,
                                SpiceDouble            mxcor3,
                                SpiceDouble            first,
                                SpiceDouble            last,
                                SpiceInt               nv,
                                ConstSpiceDouble       vrtces[][3],
                                SpiceInt               np,
                                ConstSpiceInt          plates[][3],
                                ConstSpiceDouble       spaixd[],
                                ConstSpiceInt          spaixi[]    );


   void              dskx02_c ( void               * naif_state,
                                SpiceInt               handle,
                                ConstSpiceDLADescr   * dladsc,
                                ConstSpiceDouble       vertex  [3],
                                ConstSpiceDouble       raydir  [3],
                                SpiceInt             * plid,
                                SpiceDouble            xpt     [3],
                                SpiceBoolean         * found        );


   void              dskxsi_c ( void               * naif_state,
                                SpiceBoolean           pri,
                                ConstSpiceChar       * target,
                                SpiceInt               nsurf,
                                ConstSpiceInt          srflst [],
                                SpiceDouble            et,
                                ConstSpiceChar       * fixref,
                                ConstSpiceDouble       vertex [3],
                                ConstSpiceDouble       raydir [3],
                                SpiceInt               maxd,
                                SpiceInt               maxi,
                                SpiceDouble            xpt    [3],
                                SpiceInt             * handle,
                                SpiceDLADescr        * dladsc,
                                SpiceDSKDescr        * dskdsc,
                                SpiceDouble            dc     [],
                                SpiceInt               ic     [],
                                SpiceBoolean         * found      );


   void               dskxv_c ( void               * naif_state,
                                SpiceBoolean           pri,
                                ConstSpiceChar       * target,
                                SpiceInt               nsurf,
                                ConstSpiceInt          srflst[],
                                SpiceDouble            et,
                                ConstSpiceChar       * fixref,
                                SpiceInt               nrays,
                                ConstSpiceDouble       vtxarr[][3],
                                ConstSpiceDouble       dirarr[][3],
                                SpiceDouble            xptarr[][3],
                                SpiceBoolean           fndarr[]     );


   void              dskz02_c ( void               * naif_state,
                                SpiceInt               handle,
                                ConstSpiceDLADescr   * dladsc,
                                SpiceInt             * nv,
                                SpiceInt             * np     );


   void              dsphdr_c ( void               * naif_state,
                                SpiceDouble         x,
                                SpiceDouble         y,
                                SpiceDouble         z,
                                SpiceDouble         jacobi[3][3] );


   void              dtpool_c ( void               * naif_state,
                                ConstSpiceChar      * name,
                                SpiceBoolean        * found,
                                SpiceInt            * n,
                                SpiceChar             type [1] );


   void              ducrss_c ( void               * naif_state,
                                ConstSpiceDouble      s1  [6],
                                ConstSpiceDouble      s2  [6],
                                SpiceDouble           sout[6] );


   void              dvcrss_c ( void               * naif_state,
                                ConstSpiceDouble      s1  [6],
                                ConstSpiceDouble      s2  [6],
                                SpiceDouble           sout[6] );


   SpiceDouble       dvdot_c( void               * naif_state,
                                 ConstSpiceDouble      s1 [6],
                                ConstSpiceDouble      s2 [6] );


   void              dvhat_c( void               * naif_state,
                                 ConstSpiceDouble      s1  [6],
                                SpiceDouble           sout[6] );

   SpiceDouble       dvnorm_c ( void               * naif_state,
                                ConstSpiceDouble      state[6] );

   void              dvpool_c ( void               * naif_state,
                                ConstSpiceChar      * name );


   SpiceDouble       dvsep_c( void               * naif_state,
                                 ConstSpiceDouble    * s1,
                                ConstSpiceDouble    * s2 );


   void              edlimb_c ( void               * naif_state,
                                SpiceDouble           a,
                                SpiceDouble           b,
                                SpiceDouble           c,
                                ConstSpiceDouble      viewpt[3],
                                SpiceEllipse        * limb      );


   void              edterm_c ( void               * naif_state,
                                ConstSpiceChar      * trmtyp,
                                ConstSpiceChar      * source,
                                ConstSpiceChar      * target,
                                SpiceDouble           et,
                                ConstSpiceChar      * fixfrm,
                                ConstSpiceChar      * abcorr,
                                ConstSpiceChar      * obsrvr,
                                SpiceInt              npts,
                                SpiceDouble         * trgepc,
                                SpiceDouble           obspos  [3],
                                SpiceDouble           termpts [ ][3] );


   void              ekacec_c ( void               * naif_state,
                                SpiceInt              handle,
                                SpiceInt              segno,
                                SpiceInt              recno,
                                ConstSpiceChar      * column,
                                SpiceInt              nvals,
                                SpiceInt              vallen,
                                const void          * cvals,
                                SpiceBoolean          isnull );


   void              ekaced_c ( void               * naif_state,
                                SpiceInt              handle,
                                SpiceInt              segno,
                                SpiceInt              recno,
                                ConstSpiceChar      * column,
                                SpiceInt              nvals,
                                ConstSpiceDouble    * dvals,
                                SpiceBoolean          isnull );


   void              ekacei_c ( void               * naif_state,
                                SpiceInt              handle,
                                SpiceInt              segno,
                                SpiceInt              recno,
                                ConstSpiceChar      * column,
                                SpiceInt              nvals,
                                ConstSpiceInt       * ivals,
                                SpiceBoolean          isnull );


   void              ekaclc_c ( void               * naif_state,
                                SpiceInt              handle,
                                SpiceInt              segno,
                                ConstSpiceChar      * column,
                                SpiceInt              vallen,
                                const void          * cvals,
                                ConstSpiceInt       * entszs,
                                ConstSpiceBoolean   * nlflgs,
                                ConstSpiceInt       * rcptrs,
                                SpiceInt            * wkindx  );


   void              ekacld_c ( void               * naif_state,
                                SpiceInt              handle,
                                SpiceInt              segno,
                                ConstSpiceChar      * column,
                                ConstSpiceDouble    * dvals,
                                ConstSpiceInt       * entszs,
                                ConstSpiceBoolean   * nlflgs,
                                ConstSpiceInt       * rcptrs,
                                SpiceInt            * wkindx  );


   void              ekacli_c ( void               * naif_state,
                                SpiceInt              handle,
                                SpiceInt              segno,
                                ConstSpiceChar      * column,
                                ConstSpiceInt       * ivals,
                                ConstSpiceInt       * entszs,
                                ConstSpiceBoolean   * nlflgs,
                                ConstSpiceInt       * rcptrs,
                                SpiceInt            * wkindx  );


   void              ekappr_c ( void               * naif_state,
                                SpiceInt              handle,
                                SpiceInt              segno,
                                SpiceInt            * recno  );


   void              ekbseg_c ( void               * naif_state,
                                SpiceInt              handle,
                                ConstSpiceChar      * tabnam,
                                SpiceInt              ncols,
                                SpiceInt              cnmlen,
                                const void          * cnames,
                                SpiceInt              declen,
                                const void          * decls,
                                SpiceInt            * segno  );


   void              ekccnt_c ( void               * naif_state,
                                ConstSpiceChar      * table,
                                SpiceInt            * ccount );


   void              ekcii_c( void               * naif_state,
                                 ConstSpiceChar      * table,
                                SpiceInt              cindex,
                                SpiceInt              lenout,
                                SpiceChar           * column,
                                SpiceEKAttDsc       * attdsc  );


   void              ekcls_c( void               * naif_state,
                                 SpiceInt              handle );


   void              ekdelr_c ( void               * naif_state,
                                SpiceInt              handle,
                                SpiceInt              segno,
                                SpiceInt              recno );


   void              ekffld_c ( void               * naif_state,
                                SpiceInt            handle,
                                SpiceInt            segno,
                                SpiceInt          * rcptrs );


   void              ekfind_c ( void               * naif_state,
                                ConstSpiceChar    * query,
                                SpiceInt            lenout,
                                SpiceInt          * nmrows,
                                SpiceBoolean      * error,
                                SpiceChar         * errmsg );


   void              ekgc_c   ( void               * naif_state,
                                 SpiceInt            selidx,
                                SpiceInt            row,
                                SpiceInt            elment,
                                SpiceInt            lenout,
                                SpiceChar         * cdata,
                                SpiceBoolean      * null,
                                SpiceBoolean      * found  );


   void              ekgd_c   ( void               * naif_state,
                                 SpiceInt            selidx,
                                SpiceInt            row,
                                SpiceInt            elment,
                                SpiceDouble       * ddata,
                                SpiceBoolean      * null,
                                SpiceBoolean      * found  );


   void              ekgi_c   ( void               * naif_state,
                                 SpiceInt            selidx,
                                SpiceInt            row,
                                SpiceInt            elment,
                                SpiceInt          * idata,
                                SpiceBoolean      * null,
                                SpiceBoolean      * found  );


   void              ekifld_c ( void               * naif_state,
                                SpiceInt            handle,
                                ConstSpiceChar    * tabnam,
                                SpiceInt            ncols,
                                SpiceInt            nrows,
                                SpiceInt            cnmlen,
                                const void        * cnames,
                                SpiceInt            declen,
                                const void        * decls,
                                SpiceInt          * segno,
                                SpiceInt          * rcptrs );


   void              ekinsr_c ( void               * naif_state,
                                SpiceInt            handle,
                                SpiceInt            segno,
                                SpiceInt            recno );


   void              eklef_c( void               * naif_state,
                                 ConstSpiceChar    * fname,
                                SpiceInt          * handle );


   SpiceInt          eknelt_c ( void               * naif_state,
                                SpiceInt            selidx,
                                SpiceInt            row     );


   SpiceInt          eknseg_c ( void               * naif_state,
                                SpiceInt            handle );


   void              ekntab_c ( void               * naif_state,
                                SpiceInt            * n );


   void              ekopn_c( void               * naif_state,
                                 ConstSpiceChar    * fname,
                                ConstSpiceChar    * ifname,
                                SpiceInt            ncomch,
                                SpiceInt          * handle );


   void              ekopr_c( void               * naif_state,
                                 ConstSpiceChar    * fname,
                                SpiceInt          * handle );


   void              ekops_c( void               * naif_state,
                                 SpiceInt          * handle );


   void              ekopw_c( void               * naif_state,
                                 ConstSpiceChar    * fname,
                                SpiceInt          * handle );


   void              ekpsel_c ( void               * naif_state,
                                ConstSpiceChar    * query,
                                SpiceInt            msglen,
                                SpiceInt            tablen,
                                SpiceInt            collen,
                                SpiceInt          * n,
                                SpiceInt          * xbegs,
                                SpiceInt          * xends,
                                SpiceEKDataType   * xtypes,
                                SpiceEKExprClass  * xclass,
                                void              * tabs,
                                void              * cols,
                                SpiceBoolean      * error,
                                SpiceChar         * errmsg );


   void              ekrcec_c ( void               * naif_state,
                                SpiceInt           handle,
                                SpiceInt           segno,
                                SpiceInt           recno,
                                ConstSpiceChar   * column,
                                SpiceInt           lenout,
                                SpiceInt         * nvals,
                                void             * cvals,
                                SpiceBoolean     * isnull );


   void              ekrced_c ( void               * naif_state,
                                SpiceInt           handle,
                                SpiceInt           segno,
                                SpiceInt           recno,
                                ConstSpiceChar   * column,
                                SpiceInt         * nvals,
                                SpiceDouble      * dvals,
                                SpiceBoolean     * isnull );


   void              ekrcei_c ( void               * naif_state,
                                SpiceInt           handle,
                                SpiceInt           segno,
                                SpiceInt           recno,
                                ConstSpiceChar   * column,
                                SpiceInt         * nvals,
                                SpiceInt         * ivals,
                                SpiceBoolean     * isnull );


   void              ekssum_c ( void               * naif_state,
                                SpiceInt            handle,
                                SpiceInt            segno,
                                SpiceEKSegSum     * segsum );


   void              ektnam_c ( void               * naif_state,
                                SpiceInt            n,
                                SpiceInt            lenout,
                                SpiceChar         * table  );


   void              ekucec_c ( void               * naif_state,
                                SpiceInt              handle,
                                SpiceInt              segno,
                                SpiceInt              recno,
                                ConstSpiceChar      * column,
                                SpiceInt              nvals,
                                SpiceInt              vallen,
                                const void          * cvals,
                                SpiceBoolean          isnull );


   void              ekuced_c ( void               * naif_state,
                                SpiceInt              handle,
                                SpiceInt              segno,
                                SpiceInt              recno,
                                ConstSpiceChar      * column,
                                SpiceInt              nvals,
                                ConstSpiceDouble    * dvals,
                                SpiceBoolean          isnull );


   void              ekucei_c ( void               * naif_state,
                                SpiceInt              handle,
                                SpiceInt              segno,
                                SpiceInt              recno,
                                ConstSpiceChar      * column,
                                SpiceInt              nvals,
                                ConstSpiceInt       * ivals,
                                SpiceBoolean          isnull );


   void              ekuef_c( void               * naif_state,
                                 SpiceInt            handle );


   SpiceBoolean      elemc_c( void               * naif_state,
                                 ConstSpiceChar     * item,
                                SpiceCell          * set   );


   SpiceBoolean      elemd_c( void               * naif_state,
                                 SpiceDouble          item,
                                SpiceCell          * set   );


   SpiceBoolean      elemi_c( void               * naif_state,
                                 SpiceInt             item,
                                SpiceCell          * set   );


   void              eqncpv_c ( void               * naif_state,
                                SpiceDouble          et,
                                SpiceDouble          epoch,
                                ConstSpiceDouble     eqel[9],
                                SpiceDouble          rapol,
                                SpiceDouble          decpol,
                                SpiceDouble          state[6] );


   SpiceBoolean      eqstr_c( void               * naif_state,
                                 ConstSpiceChar     * a,
                                ConstSpiceChar     * b  );


   void              el2cgv_c ( void               * naif_state,
                                ConstSpiceEllipse * ellipse,
                                SpiceDouble         center[3],
                                SpiceDouble         smajor[3],
                                SpiceDouble         sminor[3]  );


   void              erract_c ( void               * naif_state,
                                ConstSpiceChar    * operation,
                                SpiceInt            lenout,
                                SpiceChar         * action    );


   void              errch_c( void               * naif_state,
                                 ConstSpiceChar    * marker,
                                ConstSpiceChar    * string );


   void              errdev_c ( void               * naif_state,
                                ConstSpiceChar    * operation,
                                SpiceInt            lenout,
                                SpiceChar         * device    );


   void              errdp_c( void               * naif_state,
                                 ConstSpiceChar    * marker,
                                SpiceDouble         number  );


   void              errint_c ( void               * naif_state,
                                ConstSpiceChar    * marker,
                                SpiceInt            number );


   void              errprt_c ( void               * naif_state,
                                ConstSpiceChar    * operation,
                                SpiceInt            lenout,
                                SpiceChar         * list     );


   SpiceInt          esrchc_c ( void               * naif_state,
                                ConstSpiceChar  * value,
                                SpiceInt          ndim,
                                SpiceInt          lenvals,
                                const void      * array   );


   void              etcal_c( void               * naif_state,
                                 SpiceDouble         et,
                                SpiceInt            lenout,
                                SpiceChar         * string  );


   void              et2lst_c ( void               * naif_state,
                                SpiceDouble         et,
                                SpiceInt            body,
                                SpiceDouble         lon,
                                ConstSpiceChar    * type,
                                SpiceInt            timlen,
                                SpiceInt            ampmlen,
                                SpiceInt          * hr,
                                SpiceInt          * mn,
                                SpiceInt          * sc,
                                SpiceChar         * time,
                                SpiceChar         * ampm    );


   void              et2utc_c ( void               * naif_state,
                                SpiceDouble         et ,
                                ConstSpiceChar    * format,
                                SpiceInt            prec,
                                SpiceInt            lenout,
                                SpiceChar         * utcstr );


   void              eul2m_c( void               * naif_state,
                                 SpiceDouble         angle3,
                                SpiceDouble         angle2,
                                SpiceDouble         angle1,
                                SpiceInt            axis3,
                                SpiceInt            axis2,
                                SpiceInt            axis1,
                                SpiceDouble         r [3][3] );


   void              eul2xf_c ( void               * naif_state,
                                ConstSpiceDouble    eulang[6],
                                SpiceInt            axisa,
                                SpiceInt            axisb,
                                SpiceInt            axisc,
                                SpiceDouble         xform [6][6] );


   SpiceBoolean      exists_c ( void               * naif_state,
                                ConstSpiceChar    * name );


   void              expool_c ( void               * naif_state,
                                ConstSpiceChar    * name,
                                SpiceBoolean      * found );


   SpiceBoolean      failed_c ( void               * naif_state );

   void              fovray_c ( void               * naif_state,
                                ConstSpiceChar   * inst,
                                ConstSpiceDouble   raydir [3],
                                ConstSpiceChar   * rframe,
                                ConstSpiceChar   * abcorr,
                                ConstSpiceChar   * obsrvr,
                                SpiceDouble      * et,
                                SpiceBoolean     * visible  );

   void              fovtrg_c ( void               * naif_state,
                                ConstSpiceChar   * inst,
                                ConstSpiceChar   * target,
                                ConstSpiceChar   * tshape,
                                ConstSpiceChar   * tframe,
                                ConstSpiceChar   * abcorr,
                                ConstSpiceChar   * obsrvr,
                                SpiceDouble      * et,
                                SpiceBoolean     * visible  );


   void              frame_c( void               * naif_state,
                                 SpiceDouble         x[3],
                                SpiceDouble         y[3],
                                SpiceDouble         z[3] );


   void              frinfo_c ( void               * naif_state,
                                SpiceInt            frcode,
                                SpiceInt          * cent,
                                SpiceInt          * clss,
                                SpiceInt          * clssid,
                                SpiceBoolean      * found );


   void              frmnam_c ( void               * naif_state,
                                SpiceInt            frcode,
                                SpiceInt            lenout,
                                SpiceChar         * frname  );


   void              ftncls_c ( void               * naif_state,
                                SpiceInt            unit );


   void              furnsh_c ( void               * naif_state,
                                ConstSpiceChar    * file );


   void              gcpool_c ( void               * naif_state,
                                ConstSpiceChar    * name,
                                SpiceInt            start,
                                SpiceInt            room,
                                SpiceInt            lenout,
                                SpiceInt          * n,
                                void              * cvals,
                                SpiceBoolean      * found );


   void              gdpool_c ( void               * naif_state,
                                ConstSpiceChar    * name,
                                SpiceInt            start,
                                SpiceInt            room,
                                SpiceInt          * n,
                                SpiceDouble       * values,
                                SpiceBoolean      * found );


   void              georec_c ( void               * naif_state,
                                SpiceDouble         lon,
                                SpiceDouble         lat,
                                SpiceDouble         alt,
                                SpiceDouble         re,
                                SpiceDouble         f,
                                SpiceDouble         rectan[3] );


   void              getcml_c ( void               * naif_state,
                                SpiceInt          * argc,
                                SpiceChar       *** argv );


   void              getelm_c ( void               * naif_state,
                                SpiceInt            frstyr,
                                SpiceInt            lineln,
                                const void        * lines,
                                SpiceDouble       * epoch,
                                SpiceDouble       * elems   );


   void              getfat_c ( void               * naif_state,
                                ConstSpiceChar    * file,
                                SpiceInt            arclen,
                                SpiceInt            typlen,
                                SpiceChar         * arch,
                                SpiceChar         * type   );


   void              getfov_c ( void               * naif_state,
                                SpiceInt            instid,
                                SpiceInt            room,
                                SpiceInt            shapelen,
                                SpiceInt            framelen,
                                SpiceChar         * shape,
                                SpiceChar         * frame,
                                SpiceDouble         bsight [3],
                                SpiceInt          * n,
                                SpiceDouble         bounds [][3] );


   void              getmsg_c ( void               * naif_state,
                                ConstSpiceChar    * option,
                                SpiceInt            lenout,
                                SpiceChar         * msg     );


   SpiceBoolean      gfbail_c ( void               * naif_state );


   void              gfclrh_c ( void               * naif_state );


   void              gfdist_c ( void               * naif_state,
                                ConstSpiceChar    * target,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * obsrvr,
                                ConstSpiceChar    * relate,
                                SpiceDouble         refval,
                                SpiceDouble         adjust,
                                SpiceDouble         step,
                                SpiceInt            nintvls,
                                SpiceCell         * cnfine,
                                SpiceCell         * result     );



   void  gfevnt_c ( void               * naif_state,
                    void             ( * udstep ) ( void            * naif_state,
                                                    SpiceDouble       et,
                                                    SpiceDouble     * step ),

                    void             ( * udrefn ) ( void            * naif_state,
                                                    SpiceDouble       t1,
                                                    SpiceDouble       t2,
                                                    SpiceBoolean      s1,
                                                    SpiceBoolean      s2,
                                                    SpiceDouble     * t    ),
                   ConstSpiceChar     * gquant,
                   SpiceInt             qnpars,
                   SpiceInt             lenvals,
                   const void         * qpnams,
                   const void         * qcpars,
                   ConstSpiceDouble   * qdpars,
                   ConstSpiceInt      * qipars,
                   ConstSpiceBoolean  * qlpars,
                   ConstSpiceChar     * op,
                   SpiceDouble          refval,
                   SpiceDouble          tol,
                   SpiceDouble          adjust,
                   SpiceBoolean         rpt,

                   void             ( * udrepi ) ( void            * naif_state,
                                                   SpiceCell       * cnfine,
                                                   ConstSpiceChar  * srcpre,
                                                   ConstSpiceChar  * srcsuf ),

                   void             ( * udrepu ) ( void            * naif_state,
                                                   SpiceDouble       ivbeg,
                                                   SpiceDouble       ivend,
                                                   SpiceDouble       et      ),

                   void             ( * udrepf ) ( void            * naif_state ),
                   SpiceInt             nintvls,
                   SpiceBoolean         bail,
                   SpiceBoolean     ( * udbail ) ( void            * naif_state ),
                   SpiceCell          * cnfine,
                   SpiceCell          * result );



   void   gffove_c ( void               * naif_state,
                     ConstSpiceChar    * inst,
                     ConstSpiceChar    * tshape,
                     ConstSpiceDouble    raydir [3],
                     ConstSpiceChar    * target,
                     ConstSpiceChar    * tframe,
                     ConstSpiceChar    * abcorr,
                     ConstSpiceChar    * obsrvr,
                     SpiceDouble         tol,
                     void            ( * udstep ) ( void            * naif_state,
                                                    SpiceDouble       et,
                                                    SpiceDouble     * step ),
                     void            ( * udrefn ) ( void            * naif_state,
                                                    SpiceDouble       t1,
                                                    SpiceDouble       t2,
                                                    SpiceBoolean      s1,
                                                    SpiceBoolean      s2,
                                                    SpiceDouble     * t    ),
                     SpiceBoolean        rpt,
                     void            ( * udrepi ) ( void            * naif_state,
                                                    SpiceCell       * cnfine,
                                                    ConstSpiceChar  * srcpre,
                                                    ConstSpiceChar  * srcsuf ),
                     void            ( * udrepu ) ( void            * naif_state,
                                                    SpiceDouble       ivbeg,
                                                    SpiceDouble       ivend,
                                                    SpiceDouble       et      ),
                     void            ( * udrepf ) ( void            * naif_state ),
                     SpiceBoolean        bail,
                     SpiceBoolean    ( * udbail ) ( void            * naif_state ),
                     SpiceCell         * cnfine,
                     SpiceCell         * result                               );


   void              gfilum_c ( void               * naif_state,
                                ConstSpiceChar     * method,
                                ConstSpiceChar     * angtyp,
                                ConstSpiceChar     * target,
                                ConstSpiceChar     * illum,
                                ConstSpiceChar     * fixref,
                                ConstSpiceChar     * abcorr,
                                ConstSpiceChar     * obsrvr,
                                ConstSpiceDouble     spoint [3],
                                ConstSpiceChar     * relate,
                                SpiceDouble          refval,
                                SpiceDouble          adjust,
                                SpiceDouble          step,
                                SpiceInt             nintvls,
                                SpiceCell          * cnfine,
                                SpiceCell          * result     );


   void              gfinth_c ( void               * naif_state,
                                int sigcode );


   void   gfocce_c ( void              * naif_state,
                     ConstSpiceChar    * occtyp,
                     ConstSpiceChar    * front,
                     ConstSpiceChar    * fshape,
                     ConstSpiceChar    * fframe,
                     ConstSpiceChar    * back,
                     ConstSpiceChar    * bshape,
                     ConstSpiceChar    * bframe,
                     ConstSpiceChar    * obsrvr,
                     ConstSpiceChar    * abcorr,
                     SpiceDouble         tol,
                     void            ( * udstep ) ( void            * naif_state,
                                                    SpiceDouble      et,
                                                    SpiceDouble    * step ),
                     void            ( * udrefn ) ( void            * naif_state,
                                                    SpiceDouble      t1,
                                                    SpiceDouble      t2,
                                                    SpiceBoolean     s1,
                                                    SpiceBoolean     s2,
                                                    SpiceDouble    * t    ),
                     SpiceBoolean        rpt,
                     void            ( * udrepi ) ( void            * naif_state,
                                                    SpiceCell      * cnfine,
                                                    ConstSpiceChar * srcpre,
                                                    ConstSpiceChar * srcsuf ),
                     void            ( * udrepu ) ( void            * naif_state,
                                                    SpiceDouble      ivbeg,
                                                    SpiceDouble      ivend,
                                                    SpiceDouble      et     ),
                     void            ( * udrepf ) ( void            * naif_state ),
                     SpiceBoolean        bail,
                     SpiceBoolean    ( * udbail ) ( void            * naif_state ),
                     SpiceCell         * cnfine,
                     SpiceCell         * result                               );



   void              gfoclt_c ( void               * naif_state,
                                ConstSpiceChar    * occtyp,
                                ConstSpiceChar    * front,
                                ConstSpiceChar    * fshape,
                                ConstSpiceChar    * fframe,
                                ConstSpiceChar    * back,
                                ConstSpiceChar    * bshape,
                                ConstSpiceChar    * bframe,
                                ConstSpiceChar    * obsrvr,
                                ConstSpiceChar    * abcorr,
                                SpiceDouble         step,
                                SpiceCell         * cnfine,
                                SpiceCell         * result );



   void              gfpa_c ( void               * naif_state,
                                ConstSpiceChar     * target,
                              ConstSpiceChar     * illum,
                              ConstSpiceChar     * abcorr,
                              ConstSpiceChar     * obsrvr,
                              ConstSpiceChar     * relate,
                              SpiceDouble          refval,
                              SpiceDouble          adjust,
                              SpiceDouble          step,
                              SpiceInt             nintvls,
                              SpiceCell          * cnfine,
                              SpiceCell          * result  );



   void              gfposc_c ( void               * naif_state,
                                ConstSpiceChar    * target,
                                ConstSpiceChar    * frame,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * obsrvr,
                                ConstSpiceChar    * crdsys,
                                ConstSpiceChar    * coord,
                                ConstSpiceChar    * relate,
                                SpiceDouble         refval,
                                SpiceDouble         adjust,
                                SpiceDouble         step,
                                SpiceInt            nintvls,
                                SpiceCell         * cnfine,
                                SpiceCell         * result  );


   void              gfrefn_c ( void               * naif_state,
                                SpiceDouble         t1,
                                SpiceDouble         t2,
                                SpiceBoolean        s1,
                                SpiceBoolean        s2,
                                SpiceDouble       * t      );


   void              gfrepf_c ( void               * naif_state );


   void              gfrepi_c ( void               * naif_state,
                                SpiceCell         * window,
                                ConstSpiceChar    * begmss,
                                ConstSpiceChar    * endmss );


   void              gfrepu_c ( void               * naif_state,
                                SpiceDouble         ivbeg,
                                SpiceDouble         ivend,
                                SpiceDouble         time    );


   void              gfrfov_c ( void               * naif_state,
                                ConstSpiceChar    * inst,
                                ConstSpiceDouble    raydir [3],
                                ConstSpiceChar    * rframe,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * obsrvr,
                                SpiceDouble         step,
                                SpiceCell         * cnfine,
                                SpiceCell         * result     );


   void               gfrr_c ( void               * naif_state,
                                ConstSpiceChar      * target,
                               ConstSpiceChar     * abcorr,
                               ConstSpiceChar     * obsrvr,
                               ConstSpiceChar     * relate,
                               SpiceDouble          refval,
                               SpiceDouble          adjust,
                               SpiceDouble          step,
                               SpiceInt             nintvls,
                               SpiceCell          * cnfine,
                               SpiceCell          * result  );


   void              gfsep_c( void               * naif_state,
                                  ConstSpiceChar   * targ1,
                                 ConstSpiceChar   * shape1,
                                 ConstSpiceChar   * frame1,
                                 ConstSpiceChar   * targ2,
                                 ConstSpiceChar   * shape2,
                                 ConstSpiceChar   * frame2,
                                 ConstSpiceChar   * abcorr,
                                 ConstSpiceChar   * obsrvr,
                                 ConstSpiceChar   * relate,
                                 SpiceDouble        refval,
                                 SpiceDouble        adjust,
                                 SpiceDouble        step,
                                 SpiceInt           nintvls,
                                 SpiceCell        * cnfine,
                                 SpiceCell        * result  );


   void              gfsntc_c ( void               * naif_state,
                                ConstSpiceChar    * target,
                                ConstSpiceChar    * fixref,
                                ConstSpiceChar    * method,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * obsrvr,
                                ConstSpiceChar    * dref,
                                ConstSpiceDouble    dvec   [3],
                                ConstSpiceChar    * crdsys,
                                ConstSpiceChar    * coord,
                                ConstSpiceChar    * relate,
                                SpiceDouble         refval,
                                SpiceDouble         adjust,
                                SpiceDouble         step,
                                SpiceInt            nintvls,
                                SpiceCell         * cnfine,
                                SpiceCell         * result  );


   void              gfsstp_c ( void               * naif_state,
                                SpiceDouble         step   );


   void              gfstep_c ( void               * naif_state,
                                SpiceDouble         time,
                                SpiceDouble       * step   );


   void              gfstol_c ( void               * naif_state,
                                SpiceDouble         value );


   void              gfsubc_c ( void               * naif_state,
                                ConstSpiceChar    * target,
                                ConstSpiceChar    * fixref,
                                ConstSpiceChar    * method,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * obsrvr,
                                ConstSpiceChar    * crdsys,
                                ConstSpiceChar    * coord,
                                ConstSpiceChar    * relate,
                                SpiceDouble         refval,
                                SpiceDouble         adjust,
                                SpiceDouble         step,
                                SpiceInt            nintvls,
                                SpiceCell         * cnfine,
                                SpiceCell         * result  );


   void              gftfov_c ( void               * naif_state,
                                ConstSpiceChar   * inst,
                                ConstSpiceChar   * target,
                                ConstSpiceChar   * tshape,
                                ConstSpiceChar   * tframe,
                                ConstSpiceChar   * abcorr,
                                ConstSpiceChar   * obsrvr,
                                SpiceDouble        step,
                                SpiceCell        * cnfine,
                                SpiceCell        * result  );



   void              gfudb_c ( void               * naif_state,
                               void ( * udfuns ) ( void            * naif_state,
                                                   SpiceDouble       et,
                                                   SpiceDouble     * value ),

                                void  ( * udfunb ) ( void            * naif_state,
                                                     void ( * udfuns )
                                                        ( void        * naif_state,
                                                          SpiceDouble   et,
                                                          SpiceDouble * value ),

                                                   SpiceDouble       et,
                                                   SpiceBoolean    * xbool ),

                                SpiceDouble          step,
                                SpiceCell          * cnfine,
                                SpiceCell          * result );


   void              gfuds_c ( void               * naif_state,
                                 void ( * udfuns ) ( void           * naif_state,
                                                     SpiceDouble      et,
                                                     SpiceDouble    * value ),

                                void ( * udfunb ) ( void            * naif_state,
                                                    void ( * udfuns )
                                                    ( void         * naif_state,
                                                      SpiceDouble    et,
                                                      SpiceDouble  * value ),

                                                   SpiceDouble       x,
                                                   SpiceBoolean    * xbool ),

                                ConstSpiceChar     * relate,
                                SpiceDouble          refval,
                                SpiceDouble          adjust,
                                SpiceDouble          step,
                                SpiceInt             nintvls,
                                SpiceCell          * cnfine,
                                SpiceCell          * result );


   void              gipool_c ( void               * naif_state,
                                ConstSpiceChar    * name,
                                SpiceInt            start,
                                SpiceInt            room,
                                SpiceInt          * n,
                                SpiceInt          * ivals,
                                SpiceBoolean      * found );


   void              gnpool_c ( void               * naif_state,
                                ConstSpiceChar    * name,
                                SpiceInt            start,
                                SpiceInt            room,
                                SpiceInt            lenout,
                                SpiceInt          * n,
                                void              * kvars,
                                SpiceBoolean      * found  );


  void               hrmint_c ( void               * naif_state,
                                SpiceInt            n,
                                ConstSpiceDouble  * xvals,
                                ConstSpiceDouble  * yvals,
                                SpiceDouble         x,
                                SpiceDouble       * work,
                                SpiceDouble       * f,
                                SpiceDouble       * df );


   SpiceDouble       halfpi_c ( void               * naif_state );


   void              hx2dp_c( void               * naif_state,
                                 ConstSpiceChar  * string,
                                SpiceInt          lenout,
                                SpiceDouble     * number,
                                SpiceBoolean    * error,
                                SpiceChar       * errmsg
                              );


   void              ident_c( void               * naif_state,
                                 SpiceDouble         matrix[3][3] );


   void              ilumin_c ( void               * naif_state,
                                ConstSpiceChar    * method,
                                ConstSpiceChar    * target,
                                SpiceDouble         et,
                                ConstSpiceChar    * fixref,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * obsrvr,
                                ConstSpiceDouble    spoint [3],
                                SpiceDouble       * trgepc,
                                SpiceDouble         srfvec [3],
                                SpiceDouble       * phase,
                                SpiceDouble       * solar,
                                SpiceDouble       * emissn     );


   void              illum_c( void               * naif_state,
                                 ConstSpiceChar    * target,
                                SpiceDouble         et,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * obsrvr,
                                ConstSpiceDouble    spoint [3],
                                SpiceDouble       * phase,
                                SpiceDouble       * solar,
                                SpiceDouble       * emissn     );


   void              illum_pl02 ( void                 * naif_state,
                                  SpiceInt               handle,
                                  ConstSpiceDLADescr   * dladsc,
                                  ConstSpiceChar       * target,
                                  SpiceDouble            et,
                                  ConstSpiceChar       * abcorr,
                                  ConstSpiceChar       * obsrvr,
                                  SpiceDouble            spoint [3],
                                  SpiceDouble          * phase,
                                  SpiceDouble          * solar,
                                  SpiceDouble          * emissn      );


   void              illum_plid_pl02 ( void                 * naif_state,
                                       SpiceInt               handle,
                                       ConstSpiceDLADescr   * dladsc,
                                       ConstSpiceChar       * target,
                                       SpiceDouble            et,
                                       ConstSpiceChar       * abcorr,
                                       ConstSpiceChar       * obsrvr,
                                       SpiceDouble            spoint [3],
                                       SpiceInt               plid,
                                       SpiceDouble          * trgepc,
                                       SpiceDouble            srfvec [3],
                                       SpiceDouble          * phase,
                                       SpiceDouble          * solar,
                                       SpiceDouble          * emissn,
                                       SpiceBoolean         * visible,
                                       SpiceBoolean         * lit       );


   void              illumf_c ( void               * naif_state,
                                ConstSpiceChar    * method,
                                ConstSpiceChar    * target,
                                ConstSpiceChar    * ilusrc,
                                SpiceDouble         et,
                                ConstSpiceChar    * fixref,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * obsrvr,
                                ConstSpiceDouble    spoint [3],
                                SpiceDouble       * trgepc,
                                SpiceDouble         srfvec [3],
                                SpiceDouble       * phase,
                                SpiceDouble       * incdnc,
                                SpiceDouble       * emissn,
                                SpiceBoolean      * visibl,
                                SpiceBoolean      * lit       );


   void              illumg_c ( void               * naif_state,
                                ConstSpiceChar    * method,
                                ConstSpiceChar    * target,
                                ConstSpiceChar    * illum,
                                SpiceDouble         et,
                                ConstSpiceChar    * fixref,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * obsrvr,
                                ConstSpiceDouble    spoint [3],
                                SpiceDouble       * trgepc,
                                SpiceDouble         srfvec [3],
                                SpiceDouble       * phase,
                                SpiceDouble       * solar,
                                SpiceDouble       * emissn     );


   void              inedpl_c ( void               * naif_state,
                                SpiceDouble         a,
                                SpiceDouble         b,
                                SpiceDouble         c,
                                ConstSpicePlane   * plane,
                                SpiceEllipse      * ellipse,
                                SpiceBoolean      * found    );


   void              inelpl_c ( void               * naif_state,
                                ConstSpiceEllipse * ellips,
                                ConstSpicePlane   * plane,
                                SpiceInt          * nxpts,
                                SpiceDouble         xpt1[3],
                                SpiceDouble         xpt2[3] );


   void              insrtc_c ( void               * naif_state,
                                ConstSpiceChar     * item,
                                SpiceCell          * set   );


   void              insrtd_c ( void               * naif_state,
                                SpiceDouble          item,
                                SpiceCell          * set  );


   void              insrti_c ( void               * naif_state,
                                SpiceInt             item,
                                SpiceCell          * set  );


   void              inter_c( void               * naif_state,
                                  SpiceCell        * a,
                                 SpiceCell        * b,
                                 SpiceCell        * c  );


   void              inrypl_c ( void               * naif_state,
                                ConstSpiceDouble    vertex [3],
                                ConstSpiceDouble    dir    [3],
                                ConstSpicePlane   * plane,
                                SpiceInt          * nxpts,
                                SpiceDouble         xpt    [3] );


   SpiceInt          intmax_c ( void               * naif_state );


   SpiceInt          intmax_  ( void               * naif_state );


   SpiceInt          intmin_c ( void               * naif_state );


   SpiceInt          intmin_  ( void               * naif_state );


   void              invert_c ( void               * naif_state,
                                ConstSpiceDouble    m1[3][3],
                                SpiceDouble         m2[3][3]  );


   void              invort_c ( void               * naif_state,
                                ConstSpiceDouble    m  [3][3],
                                SpiceDouble         mit[3][3] );


   SpiceBoolean      isordv_c ( void               * naif_state,
                                ConstSpiceInt     * array,
                                SpiceInt            n      );


   SpiceBoolean      isrot_c( void               * naif_state,
                                 ConstSpiceDouble    m   [3][3],
                                SpiceDouble         ntol,
                                SpiceDouble         dtol       );



   SpiceInt          isrchc_c ( void               * naif_state,
                                ConstSpiceChar  * value,
                                SpiceInt          ndim,
                                SpiceInt          lenvals,
                                const void      * array   );


   SpiceInt          isrchd_c ( void               * naif_state,
                                SpiceDouble          value,
                                SpiceInt             ndim,
                                ConstSpiceDouble   * array );


   SpiceInt          isrchi_c ( void               * naif_state,
                                SpiceInt             value,
                                SpiceInt             ndim,
                                ConstSpiceInt      * array );


   SpiceBoolean      iswhsp_c ( void               * naif_state,
                                ConstSpiceChar    * string );


   SpiceDouble       j1900_c( void               * naif_state );


   SpiceDouble       j1950_c( void               * naif_state );


   SpiceDouble       j2000_c( void               * naif_state );


   SpiceDouble       j2100_c( void               * naif_state );


   SpiceDouble       jyear_c( void               * naif_state );


   void              kclear_c ( void               * naif_state );


   void              kdata_c( void               * naif_state,
                                 SpiceInt          which,
                                ConstSpiceChar  * kind,
                                SpiceInt          fillen,
                                SpiceInt          typlen,
                                SpiceInt          srclen,
                                SpiceChar       * file,
                                SpiceChar       * filtyp,
                                SpiceChar       * source,
                                SpiceInt        * handle,
                                SpiceBoolean    * found   );


   void              kinfo_c( void               * naif_state,
                                 ConstSpiceChar  * file,
                                SpiceInt          typlen,
                                SpiceInt          srclen,
                                SpiceChar       * filtyp,
                                SpiceChar       * source,
                                SpiceInt        * handle,
                                SpiceBoolean    * found  );


   void              kplfrm_c ( void               * naif_state,
                                SpiceInt             frmcls,
                                SpiceCell          * idset  );


   void              ktotal_c ( void               * naif_state,
                                ConstSpiceChar   * kind,
                                SpiceInt         * count );


   void              kxtrct_c ( void               * naif_state,
                                ConstSpiceChar       * keywd,
                                SpiceInt               termlen,
                                const void           * terms,
                                SpiceInt               nterms,
                                SpiceInt               stringlen,
                                SpiceInt               substrlen,
                                SpiceChar            * string,
                                SpiceBoolean         * found,
                                SpiceChar            * substr  );


   SpiceInt          lastnb_c ( void               * naif_state,
                                ConstSpiceChar    * string );


   void              latcyl_c ( void               * naif_state,
                                SpiceDouble         radius,
                                SpiceDouble         lon,
                                SpiceDouble         lat,
                                SpiceDouble       * r,
                                SpiceDouble       * lonc,
                                SpiceDouble       * z      );


   void              latrec_c ( void               * naif_state,
                                SpiceDouble         radius,
                                SpiceDouble         longitude,
                                SpiceDouble         latitude,
                                SpiceDouble         rectan [3] );


   void              latsph_c ( void               * naif_state,
                                SpiceDouble         radius,
                                SpiceDouble         lon,
                                SpiceDouble         lat,
                                SpiceDouble       * rho,
                                SpiceDouble       * colat,
                                SpiceDouble       * lons   );


   void              latsrf_c ( void               * naif_state,
                                ConstSpiceChar    * method,
                                ConstSpiceChar    * target,
                                SpiceDouble         et,
                                ConstSpiceChar    * fixref,
                                SpiceInt            npts,
                                ConstSpiceDouble    lonlat[][2],
                                SpiceDouble         srfpts[][3]  );


   void              lcase_c( void               * naif_state,
                                 SpiceChar         * in,
                                SpiceInt            lenout,
                                SpiceChar         * out     );


   void              ldpool_c ( void               * naif_state,
                                ConstSpiceChar    * filename );


   void              lgrind_c ( void               * naif_state,
                                SpiceInt            n,
                                ConstSpiceDouble  * xvals,
                                ConstSpiceDouble  * yvals,
                                SpiceDouble       * work,
                                SpiceDouble         x,
                                SpiceDouble       * p,
                                SpiceDouble       * dp );


   void              limb_pl02 ( void                * naif_state,
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
                                 SpiceInt              plateIDs []     );


   void              limbpt_c ( void               * naif_state,
                                ConstSpiceChar    * method,
                                ConstSpiceChar    * target,
                                SpiceDouble         et,
                                ConstSpiceChar    * fixref,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * corloc,
                                ConstSpiceChar    * obsrvr,
                                ConstSpiceDouble    refvec[3],
                                SpiceDouble         rolstp,
                                SpiceInt            ncuts,
                                SpiceDouble         schstp,
                                SpiceDouble         soltol,
                                SpiceInt            maxn,
                                SpiceInt            npts  [],
                                SpiceDouble         points[][3],
                                SpiceDouble         epochs[],
                                SpiceDouble         tangts[][3]  );


   void              llgrid_pl02 ( void                 * naif_state,
                                   SpiceInt               handle,
                                   ConstSpiceDLADescr   * dladsc,
                                   SpiceInt               npoints,
                                   ConstSpiceDouble       grid     [][2],
                                   SpiceDouble            spoints  [][3],
                                   SpiceInt               plateIDs []     );


   void              lmpool_c ( void               * naif_state,
                                const void        * cvals,
                                SpiceInt            lenvals,
                                SpiceInt             n       );


   void              lparse_c ( void               * naif_state,
                                ConstSpiceChar    * list,
                                ConstSpiceChar    * delim,
                                SpiceInt            nmax,
                                SpiceInt            lenout,
                                SpiceInt          * n,
                                void              * items   );


   void              lparsm_c ( void               * naif_state,
                                ConstSpiceChar    * list,
                                ConstSpiceChar    * delims,
                                SpiceInt            nmax,
                                SpiceInt            lenout,
                                SpiceInt          * n,
                                void              * items   );


   void              lparss_c ( void               * naif_state,
                                ConstSpiceChar    * list,
                                ConstSpiceChar    * delims,
                                SpiceCell         * set     );


   SpiceDouble       lspcn_c( void               * naif_state,
                                 ConstSpiceChar    * body,
                                SpiceDouble         et,
                                ConstSpiceChar    * abcorr );


   SpiceInt          lstlec_c ( void               * naif_state,
                                ConstSpiceChar    * string,
                                SpiceInt            n,
                                SpiceInt            lenvals,
                                const void        * array   );


   SpiceInt          lstled_c ( void               * naif_state,
                                SpiceDouble         x,
                                SpiceInt            n,
                                ConstSpiceDouble  * array );


   SpiceInt          lstlei_c ( void               * naif_state,
                                SpiceInt            x,
                                SpiceInt            n,
                                ConstSpiceInt     * array );


   SpiceInt          lstltc_c ( void               * naif_state,
                                ConstSpiceChar    * string,
                                SpiceInt            n,
                                SpiceInt            lenvals,
                                const void        * array   );


   SpiceInt          lstltd_c ( void               * naif_state,
                                SpiceDouble         x,
                                SpiceInt            n,
                                ConstSpiceDouble  * array );


   SpiceInt          lstlti_c ( void               * naif_state,
                                SpiceInt            x,
                                SpiceInt            n,
                                ConstSpiceInt     * array );


   void              ltime_c( void               * naif_state,
                                 SpiceDouble         etobs,
                                SpiceInt            obs,
                                ConstSpiceChar    * dir,
                                SpiceInt            targ,
                                SpiceDouble       * ettarg,
                                SpiceDouble       * elapsd  );


   void              lx4dec_c ( void               * naif_state,
                                ConstSpiceChar    * string,
                                SpiceInt            first,
                                SpiceInt          * last,
                                SpiceInt          * nchar  );


   void              lx4num_c ( void               * naif_state,
                                ConstSpiceChar    * string,
                                SpiceInt            first,
                                SpiceInt          * last,
                                SpiceInt          * nchar  );


   void              lx4sgn_c ( void               * naif_state,
                                ConstSpiceChar    * string,
                                SpiceInt            first,
                                SpiceInt          * last,
                                SpiceInt          * nchar  );


   void              lx4uns_c ( void               * naif_state,
                                ConstSpiceChar    * string,
                                SpiceInt            first,
                                SpiceInt          * last,
                                SpiceInt          * nchar  );


   void              lxqstr_c ( void               * naif_state,
                                ConstSpiceChar    * string,
                                SpiceChar           qchar,
                                SpiceInt            first,
                                SpiceInt          * last,
                                SpiceInt          * nchar  );


   void              m2eul_c( void               * naif_state,
                                 ConstSpiceDouble    r[3][3],
                                SpiceInt            axis3,
                                SpiceInt            axis2,
                                SpiceInt            axis1,
                                SpiceDouble       * angle3,
                                SpiceDouble       * angle2,
                                SpiceDouble       * angle1  );


   void              m2q_c    ( void               * naif_state,
                                 ConstSpiceDouble    r[3][3],
                                SpiceDouble         q[4]     );



   SpiceBoolean      matchi_c ( void               * naif_state,
                                ConstSpiceChar    * string,
                                ConstSpiceChar    * templ,
                                SpiceChar           wstr,
                                SpiceChar           wchr   );


   SpiceBoolean      matchw_c ( void               * naif_state,
                                ConstSpiceChar    * string,
                                ConstSpiceChar    * templ,
                                SpiceChar           wstr,
                                SpiceChar           wchr   );


   SpiceDouble       maxd_c( void               * naif_state,
                                 SpiceInt             n,
                                                    ... );


   SpiceInt          maxi_c( void               * naif_state,
                                 SpiceInt             n,
                                                    ... );


   void              mequ_c   ( void               * naif_state,
                                 ConstSpiceDouble    m1  [3][3],
                                SpiceDouble         mout[3][3] );


   void              mequg_c( void               * naif_state,
                                 const void        * m1,
                                SpiceInt            nr,
                                SpiceInt            nc,
                                void              * mout );


   SpiceDouble       mind_c   ( void               * naif_state,
                                 SpiceInt            n,
                                                    ... );


   SpiceInt          mini_c   ( void               * naif_state,
                                 SpiceInt            n,
                                                    ... );


   int               moved_   ( void               * naif_state,
                                SpiceDouble       * arrfrm,
                                SpiceInt          * ndim,
                                SpiceDouble       * arrto  );


   void              mtxm_c   ( void               * naif_state,
                                 ConstSpiceDouble    m1  [3][3],
                                ConstSpiceDouble    m2  [3][3],
                                SpiceDouble         mout[3][3] );


   void              mtxmg_c( void               * naif_state,
                                 const void        * m1,
                                const void        * m2,
                                SpiceInt            row1,
                                SpiceInt            col1,
                                SpiceInt            col2,
                                void              * mout  );


   void              mtxv_c   ( void               * naif_state,
                                 ConstSpiceDouble    m1  [3][3],
                                ConstSpiceDouble    vin [3],
                                SpiceDouble         vout[3]    );


   void              mtxvg_c( void               * naif_state,
                                 const void        * m1,
                                const void        * v2,
                                SpiceInt            ncol1,
                                SpiceInt            nr1r2,
                                void              * vout   );


   void              mxm_c    ( void               * naif_state,
                                 ConstSpiceDouble    m1  [3][3],
                                ConstSpiceDouble    m2  [3][3],
                                SpiceDouble         mout[3][3] );


   void              mxmg_c   ( void               * naif_state,
                                 const void        * m1,
                                const void        * m2,
                                SpiceInt            row1,
                                SpiceInt            col1,
                                SpiceInt            col2,
                                void              * mout  );


   void              mxmt_c   ( void               * naif_state,
                                 ConstSpiceDouble    m1  [3][3],
                                ConstSpiceDouble    m2  [3][3],
                                SpiceDouble         mout[3][3] );


   void              mxmtg_c( void               * naif_state,
                                 const void        * m1,
                                const void        * m2,
                                SpiceInt            nrow1,
                                SpiceInt            nc1c2,
                                SpiceInt            nrow2,
                                void              * mout  );


   void              mxv_c    ( void               * naif_state,
                                 ConstSpiceDouble    m1[3][3],
                                ConstSpiceDouble    vin[3],
                                SpiceDouble         vout[3] );


   void              mxvg_c   ( void               * naif_state,
                                 const void        * m1,
                                const void        * v2,
                                SpiceInt            nrow1,
                                SpiceInt            nc1r2,
                                void              * vout   );


   void              namfrm_c ( void               * naif_state,
                                ConstSpiceChar    * frname,
                                SpiceInt          * frcode );


   SpiceInt          ncpos_c( void               * naif_state,
                                 ConstSpiceChar    * str,
                                ConstSpiceChar    * chars,
                                SpiceInt            start  );


   SpiceInt          ncposr_c ( void               * naif_state,
                                ConstSpiceChar    * str,
                                ConstSpiceChar    * chars,
                                SpiceInt            start  );


   void              nearpt_c ( void               * naif_state,
                                ConstSpiceDouble    positn[3],
                                SpiceDouble         a,
                                SpiceDouble         b,
                                SpiceDouble         c,
                                SpiceDouble         npoint[3],
                                SpiceDouble       * alt        );


   void              npedln_c ( void               * naif_state,
                                SpiceDouble         a,
                                SpiceDouble         b,
                                SpiceDouble         c,
                                ConstSpiceDouble    linept[3],
                                ConstSpiceDouble    linedr[3],
                                SpiceDouble         pnear[3],
                                SpiceDouble       * dist      );


   void              npelpt_c ( void               * naif_state,
                                ConstSpiceDouble    point[3],
                                ConstSpiceEllipse * ellips,
                                SpiceDouble         pnear[3],
                                SpiceDouble       * dist      );


   void              nplnpt_c ( void               * naif_state,
                                ConstSpiceDouble    linpt  [3],
                                ConstSpiceDouble    lindir [3],
                                ConstSpiceDouble    point  [3],
                                SpiceDouble         pnear  [3],
                                SpiceDouble       * dist       );


   void              nvc2pl_c ( void               * naif_state,
                                ConstSpiceDouble    normal[3],
                                SpiceDouble         constant,
                                SpicePlane        * plane     );


   void              nvp2pl_c ( void               * naif_state,
                                ConstSpiceDouble    normal[3],
                                ConstSpiceDouble    point[3],
                                SpicePlane        * plane     );

   void              occult_c ( void               * naif_state,
                                ConstSpiceChar    * target1,
                                ConstSpiceChar    * shape1,
                                ConstSpiceChar    * frame1,
                                ConstSpiceChar    * target2,
                                ConstSpiceChar    * shape2,
                                ConstSpiceChar    * frame2,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * observer,
                                SpiceDouble         time,
                                SpiceInt          * occult_code );

   SpiceInt          ordc_c   ( void               * naif_state,
                                 ConstSpiceChar     * item,
                                SpiceCell          * set   );


   SpiceInt          ordd_c   ( void               * naif_state,
                                 SpiceDouble          item,
                                SpiceCell          * set   );


   SpiceInt          ordi_c   ( void               * naif_state,
                                 SpiceInt             item,
                                SpiceCell          * set   );


   void              orderc_c ( void               * naif_state,
                                SpiceInt            lenvals,
                                const void        * array,
                                SpiceInt            ndim,
                                SpiceInt          * iorder  );


   void              orderd_c ( void               * naif_state,
                                ConstSpiceDouble  * array,
                                SpiceInt            ndim,
                                SpiceInt          * iorder );


   void              orderi_c ( void               * naif_state,
                                ConstSpiceInt     * array,
                                SpiceInt            ndim,
                                SpiceInt          * iorder );


   void              oscelt_c ( void               * naif_state,
                                ConstSpiceDouble    state[6],
                                SpiceDouble         et      ,
                                SpiceDouble         mu      ,
                                SpiceDouble         elts[8]  );


   void              oscltx_c ( void               * naif_state,
                                ConstSpiceDouble    state[6],
                                SpiceDouble         et      ,
                                SpiceDouble         mu      ,
                                SpiceDouble         elts[SPICE_OSCLTX_NELTS] );


   void              pckcls_c ( void               * naif_state,
                                SpiceInt            handle );


   void              pckcov_c ( void               * naif_state,
                                ConstSpiceChar    * pck,
                                SpiceInt            idcode,
                                SpiceCell         * cover   );


   void              pckfrm_c ( void               * naif_state,
                                ConstSpiceChar    * pck,
                                SpiceCell         * ids  );


   void              pcklof_c ( void               * naif_state,
                                ConstSpiceChar    * fname,
                                SpiceInt          * handle );


   void              pckopn_c ( void               * naif_state,
                                ConstSpiceChar    * name,
                                ConstSpiceChar    * ifname,
                                SpiceInt            ncomch,
                                SpiceInt          * handle  );


   void              pckuof_c ( void               * naif_state,
                                SpiceInt            handle );


   void              pckw02_c ( void               * naif_state,
                                SpiceInt            handle,
                                SpiceInt            clssid,
                                ConstSpiceChar    * frame,
                                SpiceDouble         first,
                                SpiceDouble         last,
                                ConstSpiceChar    * segid,
                                SpiceDouble         intlen,
                                SpiceInt            n,
                                SpiceInt            polydg,
                                SpiceDouble         cdata  [],
                                SpiceDouble         btime      );


   void              pcpool_c ( void               * naif_state,
                                ConstSpiceChar   * name,
                                SpiceInt           n,
                                SpiceInt           lenvals,
                                const void        * cvals    );


   void              pdpool_c ( void               * naif_state,
                                ConstSpiceChar    * name,
                                SpiceInt            n,
                                ConstSpiceDouble  * dvals );


   void              pgrrec_c ( void               * naif_state,
                                ConstSpiceChar    * body,
                                SpiceDouble         lon,
                                SpiceDouble         lat,
                                SpiceDouble         alt,
                                SpiceDouble         re,
                                SpiceDouble         f,
                                SpiceDouble         rectan[3] );


   SpiceDouble       phaseq_c ( void               * naif_state,
                                SpiceDouble       et,
                                ConstSpiceChar  * target,
                                ConstSpiceChar  * illumn,
                                ConstSpiceChar  * obsrvr,
                                ConstSpiceChar  * abcorr );


   SpiceDouble       pi_c     ( void               * naif_state );


   void              pipool_c ( void               * naif_state,
                                ConstSpiceChar    * name,
                                SpiceInt            n,
                                ConstSpiceInt     * ivals );


   void              pjelpl_c ( void               * naif_state,
                                ConstSpiceEllipse * elin,
                                ConstSpicePlane   * plane,
                                SpiceEllipse      * elout  );


   void              pl2nvc_c ( void               * naif_state,
                                ConstSpicePlane   * plane,
                                SpiceDouble         normal[3],
                                SpiceDouble       * constant  );


   void              pl2nvp_c ( void               * naif_state,
                                ConstSpicePlane   * plane,
                                SpiceDouble         normal[3],
                                SpiceDouble         point[3]  );


   void              pl2psv_c ( void               * naif_state,
                                ConstSpicePlane   * plane,
                                SpiceDouble         point[3],
                                SpiceDouble         span1[3],
                                SpiceDouble         span2[3]  );


   SpiceDouble       pltar_c( void               * naif_state,
                                 SpiceInt            nv,
                                ConstSpiceDouble    vrtces[][3],
                                SpiceInt            np,
                                ConstSpiceInt       plates[][3] );  


   void              pltexp_c ( void               * naif_state,
                                ConstSpiceDouble    iverts[3][3],
                                SpiceDouble         delta,
                                SpiceDouble         overts[3][3] );


   void              pltnp_c( void               * naif_state,
                                 ConstSpiceDouble    point[3],
                                ConstSpiceDouble    v1   [3],
                                ConstSpiceDouble    v2   [3],
                                ConstSpiceDouble    v3   [3],
                                SpiceDouble         pnear[3],
                                SpiceDouble       * dist      );


   void              pltnrm_c ( void               * naif_state,
                                ConstSpiceDouble   v1[3],
                                ConstSpiceDouble   v2[3],
                                ConstSpiceDouble   v3[3],
                                SpiceDouble        normal[3] );


   SpiceDouble       pltvol_c ( void               * naif_state,
                                SpiceInt           nv,
                                ConstSpiceDouble   vrtces[][3],
                                SpiceInt           np,
                                ConstSpiceInt      plates[][3] );  


   void              polyds_c ( void               * naif_state,
                                ConstSpiceDouble    * coeffs,
                                SpiceInt              deg,
                                SpiceInt              nderiv,
                                SpiceDouble           t,
                                SpiceDouble         * p );


   SpiceInt          pos_c    ( void               * naif_state,
                                 ConstSpiceChar    * str,
                                ConstSpiceChar    * substr,
                                SpiceInt            start   );


   SpiceInt          posr_c   ( void               * naif_state,
                                 ConstSpiceChar    * str,
                                ConstSpiceChar    * substr,
                                SpiceInt            start   );


   void              prefix_c ( void               * naif_state,
                                ConstSpiceChar    * pref,
                                SpiceInt            spaces,
                                SpiceInt            lenout,
                                SpiceChar         * string  );


   SpiceChar       * prompt_c ( void               * naif_state,
                                ConstSpiceChar    * prmptStr,
                                SpiceInt            lenout,
                                SpiceChar         * buffer   );


   void              prop2b_c ( void               * naif_state,
                                SpiceDouble         gm,
                                ConstSpiceDouble    pvinit[6],
                                SpiceDouble         dt,
                                SpiceDouble         pvprop[6] );


   void              prsdp_c( void               * naif_state,
                                 ConstSpiceChar    * string,
                                SpiceDouble       * dpval  );


   void              prsint_c ( void               * naif_state,
                                ConstSpiceChar    * string,
                                SpiceInt          * intval );


   void              psv2pl_c ( void               * naif_state,
                                ConstSpiceDouble    point[3],
                                ConstSpiceDouble    span1[3],
                                ConstSpiceDouble    span2[3],
                                SpicePlane        * plane     );


   void              putcml_c ( void               * naif_state,
                                SpiceInt            argc ,
                                SpiceChar        ** argv  );


   void              pxform_c ( void               * naif_state,
                                ConstSpiceChar    * from,
                                ConstSpiceChar    * to,
                                SpiceDouble         et,
                                SpiceDouble         rotate[3][3] );


   void              pxfrm2_c ( void               * naif_state,
                                ConstSpiceChar    * from,
                                ConstSpiceChar    * to,
                                SpiceDouble         etfrom,
                                SpiceDouble         etto,
                                SpiceDouble         rotate[3][3] );


   void              q2m_c    ( void               * naif_state,
                                 ConstSpiceDouble    q[4],
                                SpiceDouble         r[3][3] );


   void              qcktrc_c ( void               * naif_state,
                                SpiceInt            tracelen,
                                SpiceChar         * trace    );


   void              qdq2av_c ( void               * naif_state,
                                ConstSpiceDouble    q[4],
                                ConstSpiceDouble    dq[4],
                                SpiceDouble         av[3] );


   void              qxq_c    ( void               * naif_state,
                                 ConstSpiceDouble    q1[4],
                                ConstSpiceDouble    q2[4],
                                SpiceDouble         qout[4] );



   void              radrec_c ( void               * naif_state,
                                SpiceDouble         range,
                                SpiceDouble         ra,
                                SpiceDouble         dec,
                                SpiceDouble         rectan[3] );


   void              rav2xf_c ( void               * naif_state,
                                ConstSpiceDouble     rot   [3][3],
                                ConstSpiceDouble     av    [3],
                                SpiceDouble          xform [6][6]  );


   void              raxisa_c ( void               * naif_state,
                                ConstSpiceDouble     matrix[3][3],
                                SpiceDouble          axis  [3],
                                SpiceDouble        * angle       );


   void              rdtext_c ( void               * naif_state,
                                ConstSpiceChar     * file,
                                SpiceInt             lenout,
                                SpiceChar          * line,
                                SpiceBoolean       * eof    );


   void              reccyl_c ( void               * naif_state,
                                ConstSpiceDouble    rectan[3],
                                SpiceDouble       * r,
                                SpiceDouble       * lon,
                                SpiceDouble       * z         );


   void              recgeo_c ( void               * naif_state,
                                ConstSpiceDouble    rectan[3],
                                SpiceDouble         re,
                                SpiceDouble         f,
                                SpiceDouble       * lon,
                                SpiceDouble       * lat,
                                SpiceDouble       * alt );


   void              reclat_c ( void               * naif_state,
                                ConstSpiceDouble    rectan[3],
                                SpiceDouble       * radius,
                                SpiceDouble       * longitude,
                                SpiceDouble       * latitude  );


   void              recpgr_c ( void               * naif_state,
                                ConstSpiceChar    * body,
                                SpiceDouble         rectan[3],
                                SpiceDouble         re,
                                SpiceDouble         f,
                                SpiceDouble       * lon,
                                SpiceDouble       * lat,
                                SpiceDouble       * alt       );


   void              recrad_c ( void               * naif_state,
                                ConstSpiceDouble    rectan[3],
                                SpiceDouble       * radius,
                                SpiceDouble       * ra,
                                SpiceDouble       * dec  );



   void              reordc_c ( void               * naif_state,
                                ConstSpiceInt     * iorder,
                                SpiceInt            ndim,
                                SpiceInt            lenvals,
                                void              * array    );


   void              reordd_c ( void               * naif_state,
                                ConstSpiceInt     * iorder,
                                SpiceInt            ndim,
                                SpiceDouble       * array   );


   void              reordi_c ( void               * naif_state,
                                ConstSpiceInt     * iorder,
                                SpiceInt            ndim,
                                SpiceInt          * array   );


   void              reordl_c ( void               * naif_state,
                                ConstSpiceInt     * iorder,
                                SpiceInt            ndim,
                                SpiceBoolean      * array   );


   void              removc_c ( void               * naif_state,
                                ConstSpiceChar     * item,
                                SpiceCell          * set   );


   void              removd_c ( void               * naif_state,
                                SpiceDouble          item,
                                SpiceCell          * set   );


   void              removi_c ( void               * naif_state,
                                SpiceInt             item,
                                SpiceCell          * set   );


   void              repmc_c( void               * naif_state,
                                 ConstSpiceChar     * in,
                                ConstSpiceChar     * marker,
                                ConstSpiceChar     * value,
                                SpiceInt             lenout,
                                SpiceChar          * out     );


   void              repmct_c ( void               * naif_state,
                                ConstSpiceChar     * in,
                                ConstSpiceChar     * marker,
                                SpiceInt             value,
                                SpiceChar            strCase,
                                SpiceInt             lenout,
                                SpiceChar          * out     );


   void              repmd_c( void               * naif_state,
                                 ConstSpiceChar     * in,
                                ConstSpiceChar     * marker,
                                SpiceDouble          value,
                                SpiceInt             sigdig,
                                SpiceInt             lenout,
                                SpiceChar          * out     );


   void              repmf_c( void               * naif_state,
                                 ConstSpiceChar     * in,
                                ConstSpiceChar     * marker,
                                SpiceDouble          value,
                                SpiceInt             sigdig,
                                SpiceChar            format,
                                SpiceInt             lenout,
                                SpiceChar          * out     );


   void              repmi_c( void               * naif_state,
                                 ConstSpiceChar     * in,
                                ConstSpiceChar     * marker,
                                SpiceInt             value,
                                SpiceInt             lenout,
                                SpiceChar          * out     );


   void              repmot_c ( void               * naif_state,
                                ConstSpiceChar     * in,
                                ConstSpiceChar     * marker,
                                SpiceInt             value,
                                SpiceChar            strCase,
                                SpiceInt             lenout,
                                SpiceChar          * out     );


   void              reset_c( void               * naif_state );


   SpiceBoolean      return_c ( void               * naif_state );


   void              recsph_c ( void               * naif_state,
                                ConstSpiceDouble    rectan[3],
                                SpiceDouble       * r,
                                SpiceDouble       * colat,
                                SpiceDouble       * lon );


   void              rotate_c ( void               * naif_state,
                                SpiceDouble         angle,
                                SpiceInt            iaxis,
                                SpiceDouble         mout[3][3] );


   void              rotmat_c ( void               * naif_state,
                                ConstSpiceDouble    m1[3][3],
                                SpiceDouble         angle,
                                SpiceInt            iaxis,
                                SpiceDouble         mout[3][3] );


   void              rotvec_c ( void               * naif_state,
                                ConstSpiceDouble    v1[3],
                                SpiceDouble         angle,
                                SpiceInt            iaxis,
                                SpiceDouble         vout[3] );


   SpiceDouble       rpd_c    ( void               * naif_state );


   void              rquad_c( void               * naif_state,
                                 SpiceDouble         a,
                                SpiceDouble         b,
                                SpiceDouble         c,
                                SpiceDouble         root1[2],
                                SpiceDouble         root2[2] );


   void              saelgv_c ( void               * naif_state,
                                ConstSpiceDouble    vec1  [3],
                                ConstSpiceDouble    vec2  [3],
                                SpiceDouble         smajor[3],
                                SpiceDouble         sminor[3]  );


   void              scard_c ( void               * naif_state,
                                 SpiceInt            card,
                                SpiceCell         * cell  );


   void              scdecd_c ( void               * naif_state,
                                SpiceInt            sc,
                                SpiceDouble         sclkdp,
                                SpiceInt            sclklen,
                                SpiceChar         * sclkch   );


   void              sce2s_c( void               * naif_state,
                                 SpiceInt            sc,
                                SpiceDouble         et,
                                SpiceInt            sclklen,
                                SpiceChar         * sclkch   );


   void              sce2c_c( void               * naif_state,
                                 SpiceInt            sc,
                                SpiceDouble         et,
                                SpiceDouble       * sclkdp   );


   void              sce2t_c( void               * naif_state,
                                 SpiceInt            sc,
                                SpiceDouble         et,
                                SpiceDouble       * sclkdp   );


   void              scencd_c ( void               * naif_state,
                                SpiceInt            sc,
                                ConstSpiceChar    * sclkch,
                                SpiceDouble       * sclkdp   );


   void              scfmt_c( void               * naif_state,
                                 SpiceInt            sc,
                                SpiceDouble         ticks,
                                SpiceInt            clkstrlen,
                                SpiceChar         * clkstr    );


   void              scpart_c ( void               * naif_state,
                                SpiceInt            sc,
                                SpiceInt          * nparts,
                                SpiceDouble       * pstart,
                                SpiceDouble       * pstop   );


   void              scs2e_c( void               * naif_state,
                                 SpiceInt            sc,
                                ConstSpiceChar    * sclkch,
                                SpiceDouble       * et      );


   void              sct2e_c( void               * naif_state,
                                 SpiceInt            sc,
                                SpiceDouble         sclkdp,
                                SpiceDouble       * et      );


   void              sctiks_c ( void               * naif_state,
                                SpiceInt            sc,
                                ConstSpiceChar    * clkstr,
                                SpiceDouble       * ticks   );


   void              sdiff_c( void               * naif_state,
                                 SpiceCell         * a,
                                SpiceCell         * b,
                                SpiceCell         * c  );


   SpiceBoolean      set_c    ( void               * naif_state,
                                 SpiceCell          * a,
                                ConstSpiceChar     * op,
                                SpiceCell          * b  );


   void              setmsg_c ( void               * naif_state,
                                ConstSpiceChar    * msg );


   void              shellc_c ( void               * naif_state,
                                SpiceInt            ndim,
                                SpiceInt            lenvals,
                                void              * array   );


   void              shelld_c ( void               * naif_state,
                                SpiceInt            ndim,
                                SpiceDouble       * array   );


   void              shelli_c ( void               * naif_state,
                                SpiceInt            ndim,
                                SpiceInt          * array   );


   void              sigerr_c ( void               * naif_state,
                                ConstSpiceChar    * message );


   void              sincpt_c ( void               * naif_state,
                                ConstSpiceChar    * method,
                                ConstSpiceChar    * target,
                                SpiceDouble         et,
                                ConstSpiceChar    * fixref,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * obsrvr,
                                ConstSpiceChar    * dref,
                                ConstSpiceDouble    dvec   [3],
                                SpiceDouble         spoint [3],
                                SpiceDouble       * trgepc,
                                SpiceDouble         srfvec [3],
                                SpiceBoolean      * found         );


   SpiceInt          size_c   ( void               * naif_state,
                                 SpiceCell         * size );


   SpiceDouble       spd_c    ( void               * naif_state );


   void              sphcyl_c ( void               * naif_state,
                                SpiceDouble         radius,
                                SpiceDouble         colat,
                                SpiceDouble         slon,
                                SpiceDouble       * r,
                                SpiceDouble       * lon,
                                SpiceDouble       * z );


   void              sphlat_c ( void               * naif_state,
                                SpiceDouble         r,
                                SpiceDouble         colat,
                                SpiceDouble         lons,
                                SpiceDouble       * radius,
                                SpiceDouble       * lon,
                                SpiceDouble       * lat   );


   void              sphrec_c ( void               * naif_state,
                                SpiceDouble         r,
                                SpiceDouble         colat,
                                SpiceDouble         lon,
                                SpiceDouble         rectan[3] );


   void              spk14a_c ( void               * naif_state,
                                SpiceInt            handle,
                                SpiceInt            ncsets,
                                ConstSpiceDouble    coeffs [],
                                ConstSpiceDouble    epochs []  );


   void              spk14b_c ( void               * naif_state,
                                SpiceInt            handle,
                                ConstSpiceChar    * segid,
                                SpiceInt            body,
                                SpiceInt            center,
                                ConstSpiceChar    * frame,
                                SpiceDouble         first,
                                SpiceDouble         last,
                                SpiceInt            chbdeg  );


   void              spk14e_c ( void               * naif_state,
                                SpiceInt            handle );


   void              spkapo_c ( void               * naif_state,
                                SpiceInt            targ,
                                SpiceDouble         et,
                                ConstSpiceChar    * ref,
                                ConstSpiceDouble    sobs[6],
                                ConstSpiceChar    * abcorr,
                                SpiceDouble         ptarg[3],
                                SpiceDouble       * lt        );


   void              spkapp_c ( void               * naif_state,
                                SpiceInt            targ,
                                SpiceDouble         et,
                                ConstSpiceChar    * ref,
                                ConstSpiceDouble    sobs   [6],
                                ConstSpiceChar    * abcorr,
                                SpiceDouble         starg  [6],
                                SpiceDouble       * lt         );


   void              spkacs_c ( void               * naif_state,
                                SpiceInt            targ,
                                SpiceDouble         et,
                                ConstSpiceChar    * ref,
                                ConstSpiceChar    * abcorr,
                                SpiceInt            obs,
                                SpiceDouble         starg[6],
                                SpiceDouble       * lt,
                                SpiceDouble       * dlt       );


   void              spkaps_c ( void               * naif_state,
                                SpiceInt            targ,
                                SpiceDouble         et,
                                ConstSpiceChar    * ref,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceDouble    stobs[6],
                                ConstSpiceDouble    accobs[6],
                                SpiceDouble         starg[6],
                                SpiceDouble       * lt,
                                SpiceDouble       * dlt      );


   void              spkcls_c ( void               * naif_state,
                                SpiceInt            handle );


   void              spkcov_c ( void               * naif_state,
                                ConstSpiceChar    * spk,
                                SpiceInt            idcode,
                                SpiceCell         * cover   );


   void              spkcpo_c ( void               * naif_state,
                                ConstSpiceChar    * target,
                                SpiceDouble         et,
                                ConstSpiceChar    * outref,
                                ConstSpiceChar    * refloc,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceDouble    obssta [3],
                                ConstSpiceChar    * obsctr,
                                ConstSpiceChar    * obsref,
                                SpiceDouble         state  [6],
                                SpiceDouble       * lt          );


   void              spkcpt_c ( void               * naif_state,
                                ConstSpiceDouble    trgpos [3],
                                ConstSpiceChar    * trgctr,
                                ConstSpiceChar    * trgref,
                                SpiceDouble         et,
                                ConstSpiceChar    * outref,
                                ConstSpiceChar    * refloc,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * obsrvr,
                                SpiceDouble         state  [6],
                                SpiceDouble       * lt          );


   void              spkcvo_c ( void               * naif_state,
                                ConstSpiceChar    * target,
                                SpiceDouble         et,
                                ConstSpiceChar    * outref,
                                ConstSpiceChar    * refloc,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceDouble    obssta [6],
                                SpiceDouble         obsepc,
                                ConstSpiceChar    * obsctr,
                                ConstSpiceChar    * obsref,
                                SpiceDouble         state  [6],
                                SpiceDouble       * lt         );


   void              spkcvt_c ( void               * naif_state,
                                ConstSpiceDouble    trgsta [6],
                                SpiceDouble         trgepc,
                                ConstSpiceChar    * trgctr,
                                ConstSpiceChar    * trgref,
                                SpiceDouble         et,
                                ConstSpiceChar    * outref,
                                ConstSpiceChar    * refloc,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * obsrvr,
                                SpiceDouble         state   [6],
                                SpiceDouble       * lt          );


   void              spkez_c( void               * naif_state,
                                 SpiceInt            target,
                                SpiceDouble         epoch,
                                ConstSpiceChar    * frame,
                                ConstSpiceChar    * abcorr,
                                SpiceInt            observer,
                                SpiceDouble         state[6],
                                SpiceDouble       * lt       );


   void              spkezp_c ( void               * naif_state,
                                SpiceInt            targ,
                                SpiceDouble         et,
                                ConstSpiceChar    * ref,
                                ConstSpiceChar    * abcorr,
                                SpiceInt            obs,
                                SpiceDouble         ptarg[3],
                                SpiceDouble       * lt        );


   void              spkezr_c ( void               * naif_state,
                                ConstSpiceChar    * target,
                                SpiceDouble         epoch,
                                ConstSpiceChar    * frame,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * observer,
                                SpiceDouble         state[6],
                                SpiceDouble       * lt       );


   void              spkgeo_c ( void               * naif_state,
                                SpiceInt            targ,
                                SpiceDouble         et,
                                ConstSpiceChar    * ref,
                                SpiceInt            obs,
                                SpiceDouble         state[6],
                                SpiceDouble       * lt       );


   void              spkgps_c ( void               * naif_state,
                                SpiceInt            targ,
                                SpiceDouble         et,
                                ConstSpiceChar    * ref,
                                SpiceInt            obs,
                                SpiceDouble         pos[3],
                                SpiceDouble       * lt     );


   void              spklef_c ( void               * naif_state,
                                ConstSpiceChar    * filename,
                                SpiceInt          * handle   );


   void              spkltc_c ( void               * naif_state,
                                SpiceInt            targ,
                                SpiceDouble         et,
                                ConstSpiceChar    * ref,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceDouble    stobs[6],
                                SpiceDouble         starg[6],
                                SpiceDouble       * lt,
                                SpiceDouble       * dlt      );


   void              spkobj_c ( void               * naif_state,
                                ConstSpiceChar    * spk,
                                SpiceCell         * ids );


   void              spkopa_c ( void               * naif_state,
                                ConstSpiceChar    * file,
                                SpiceInt          * handle );


   void              spkopn_c ( void               * naif_state,
                                ConstSpiceChar    * name,
                                ConstSpiceChar    * ifname,
                                SpiceInt            ncomch,
                                SpiceInt          * handle  );


   void              spkpds_c ( void               * naif_state,
                                SpiceInt            body,
                                SpiceInt            center,
                                ConstSpiceChar    * frame,
                                SpiceInt            type,
                                SpiceDouble         first,
                                SpiceDouble         last,
                                SpiceDouble         descr[5] );


   void              spkpos_c ( void               * naif_state,
                                ConstSpiceChar    * targ,
                                SpiceDouble         et,
                                ConstSpiceChar    * ref,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * obs,
                                SpiceDouble         ptarg[3],
                                SpiceDouble       * lt        );


   void              spkpvn_c ( void               * naif_state,
                                SpiceInt            handle,
                                ConstSpiceDouble    descr [5],
                                SpiceDouble         et,
                                SpiceInt          * ref,
                                SpiceDouble         state [6],
                                SpiceInt          * center    );


   void              spksfs_c ( void               * naif_state,
                                SpiceInt            body,
                                SpiceDouble         et,
                                SpiceInt            idlen,
                                SpiceInt          * handle,
                                SpiceDouble         descr [5],
                                SpiceChar         * ident,
                                SpiceBoolean      * found  );


   void              spkssb_c ( void               * naif_state,
                                SpiceInt            targ,
                                SpiceDouble         et,
                                ConstSpiceChar    * ref,
                                SpiceDouble         starg[6] );


   void              spksub_c ( void               * naif_state,
                                SpiceInt            handle,
                                SpiceDouble         descr[5],
                                ConstSpiceChar    * ident,
                                SpiceDouble         begin,
                                SpiceDouble         end,
                                SpiceInt            newh    );


   void              spkuds_c ( void               * naif_state,
                                ConstSpiceDouble    descr [5],
                                SpiceInt          * body,
                                SpiceInt          * center,
                                SpiceInt          * frame,
                                SpiceInt          * type,
                                SpiceDouble       * first,
                                SpiceDouble       * last,
                                SpiceInt          * begin,
                                SpiceInt          * end     );


   void              spkuef_c ( void               * naif_state,
                                SpiceInt             handle );


   void              spkw02_c ( void               * naif_state,
                                SpiceInt             handle,
                                SpiceInt             body,
                                SpiceInt             center,
                                ConstSpiceChar     * frame,
                                SpiceDouble          first,
                                SpiceDouble          last,
                                ConstSpiceChar     * segid,
                                SpiceDouble          intlen,
                                SpiceInt             n,
                                SpiceInt             polydg,
                                ConstSpiceDouble     cdata [],
                                SpiceDouble          btime     );


   void              spkw03_c ( void               * naif_state,
                                SpiceInt             handle,
                                SpiceInt             body,
                                SpiceInt             center,
                                ConstSpiceChar     * frame,
                                SpiceDouble          first,
                                SpiceDouble          last,
                                ConstSpiceChar     * segid,
                                SpiceDouble          intlen,
                                SpiceInt             n,
                                SpiceInt             polydg,
                                ConstSpiceDouble     cdata [],
                                SpiceDouble          btime     );


   void              spkw05_c ( void               * naif_state,
                                SpiceInt             handle,
                                SpiceInt             body,
                                SpiceInt             center,
                                ConstSpiceChar     * frame,
                                SpiceDouble          first,
                                SpiceDouble          last,
                                ConstSpiceChar     * segid,
                                SpiceDouble          gm,
                                SpiceInt             n,
                                ConstSpiceDouble     states [][6],
                                ConstSpiceDouble     epochs []     );


   void              spkw08_c ( void               * naif_state,
                                SpiceInt             handle,
                                SpiceInt             body,
                                SpiceInt             center,
                                ConstSpiceChar     * frame,
                                SpiceDouble          first,
                                SpiceDouble          last,
                                ConstSpiceChar     * segid,
                                SpiceInt             degree,
                                SpiceInt             n,
                                ConstSpiceDouble     states[][6],
                                SpiceDouble          epoch1,
                                SpiceDouble          step         );


   void              spkw09_c ( void               * naif_state,
                                SpiceInt             handle,
                                SpiceInt             body,
                                SpiceInt             center,
                                ConstSpiceChar     * frame,
                                SpiceDouble          first,
                                SpiceDouble          last,
                                ConstSpiceChar     * segid,
                                SpiceInt             degree,
                                SpiceInt             n,
                                ConstSpiceDouble     states[][6],
                                ConstSpiceDouble     epochs[]     );


   void              spkw10_c ( void               * naif_state,
                                SpiceInt             handle,
                                SpiceInt             body,
                                SpiceInt             center,
                                ConstSpiceChar     * frame,
                                SpiceDouble          first,
                                SpiceDouble          last,
                                ConstSpiceChar     * segid,
                                ConstSpiceDouble     consts [8],
                                SpiceInt             n,
                                ConstSpiceDouble     elems  [],
                                ConstSpiceDouble     epochs []  );


   void              spkw12_c ( void               * naif_state,
                                SpiceInt             handle,
                                SpiceInt             body,
                                SpiceInt             center,
                                ConstSpiceChar     * frame,
                                SpiceDouble          first,
                                SpiceDouble          last,
                                ConstSpiceChar     * segid,
                                SpiceInt             degree,
                                SpiceInt             n,
                                ConstSpiceDouble     states[][6],
                                SpiceDouble          epoch0,
                                SpiceDouble          step        );


   void              spkw13_c ( void               * naif_state,
                                SpiceInt             handle,
                                SpiceInt             body,
                                SpiceInt             center,
                                ConstSpiceChar     * frame,
                                SpiceDouble          first,
                                SpiceDouble          last,
                                ConstSpiceChar     * segid,
                                SpiceInt             degree,
                                SpiceInt             n,
                                ConstSpiceDouble     states[][6],
                                ConstSpiceDouble     epochs[]     );


   void              spkw15_c ( void               * naif_state,
                                SpiceInt             handle,
                                SpiceInt             body,
                                SpiceInt             center,
                                ConstSpiceChar     * frame,
                                SpiceDouble          first,
                                SpiceDouble          last,
                                ConstSpiceChar     * segid,
                                SpiceDouble          epoch,
                                ConstSpiceDouble     tp     [3],
                                ConstSpiceDouble     pa     [3],
                                SpiceDouble          p,
                                SpiceDouble          ecc,
                                SpiceDouble          j2flg,
                                ConstSpiceDouble     pv     [3],
                                SpiceDouble          gm,
                                SpiceDouble          j2,
                                SpiceDouble          radius     );


   void              spkw17_c ( void               * naif_state,
                                SpiceInt             handle,
                                SpiceInt             body,
                                SpiceInt             center,
                                ConstSpiceChar     * frame,
                                SpiceDouble          first,
                                SpiceDouble          last,
                                ConstSpiceChar     * segid,
                                SpiceDouble          epoch,
                                ConstSpiceDouble     eqel   [9],
                                SpiceDouble          rapol,
                                SpiceDouble          decpol      );


   void              spkw18_c ( void               * naif_state,
                                SpiceInt             handle,
                                SpiceSPK18Subtype    subtyp,
                                SpiceInt             body,
                                SpiceInt             center,
                                ConstSpiceChar     * frame,
                                SpiceDouble          first,
                                SpiceDouble          last,
                                ConstSpiceChar     * segid,
                                SpiceInt             degree,
                                SpiceInt             n,
                                const void         * packts,
                                ConstSpiceDouble     epochs[]     );


   void             spkw20_c( void               * naif_state,
                                 SpiceInt             handle,
                                SpiceInt             body,
                                SpiceInt             center,
                                ConstSpiceChar     * frame,
                                SpiceDouble          first,
                                SpiceDouble          last,
                                ConstSpiceChar     * segid,
                                SpiceDouble          intlen,
                                SpiceInt             n,
                                SpiceInt             polydg,
                                ConstSpiceDouble     cdata[],
                                SpiceDouble          dscale,
                                SpiceDouble          tscale,
                                SpiceDouble          initjd,
                                SpiceDouble          initfr  );



   void              srfrec_c ( void               * naif_state,
                                SpiceInt            body,
                                SpiceDouble         lon,
                                SpiceDouble         lat,
                                SpiceDouble         rectan[3] );


   void              srfc2s_c ( void               * naif_state,
                                SpiceInt             code,
                                SpiceInt             bodyid,
                                SpiceInt             srflen,
                                SpiceChar          * srfstr,
                                SpiceBoolean       * isname  );


   void              srfcss_c ( void               * naif_state,
                                SpiceInt             code,
                                ConstSpiceChar     * bodstr,
                                SpiceInt             srflen,
                                SpiceChar          * srfstr,
                                SpiceBoolean       * isname  );


   void              srfnrm_c ( void               * naif_state,
                                ConstSpiceChar     * method,
                                ConstSpiceChar     * target,
                                SpiceDouble          et,
                                ConstSpiceChar     * fixref,
                                SpiceInt             npts,
                                ConstSpiceDouble     srfpts[][3],
                                SpiceDouble          normls[][3]  );


   void              srfs2c_c ( void               * naif_state,
                                ConstSpiceChar     * srfstr,
                                ConstSpiceChar     * bodstr,
                                SpiceInt           * code,
                                SpiceBoolean       * found  );


   void              srfscc_c ( void               * naif_state,
                                ConstSpiceChar     * surfce,
                                SpiceInt             bodyid,
                                SpiceInt           * surfid,
                                SpiceBoolean       * found  );


   void              srfxpt_c ( void               * naif_state,
                                ConstSpiceChar    * method,
                                ConstSpiceChar    * target,
                                SpiceDouble         et,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * obsrvr,
                                ConstSpiceChar    * dref,
                                ConstSpiceDouble    dvec   [3],
                                SpiceDouble         spoint [3],
                                SpiceDouble       * dist,
                                SpiceDouble       * trgepc,
                                SpiceDouble         obspos [3],
                                SpiceBoolean      * found         );


   void              ssize_c( void               * naif_state,
                                 SpiceInt             size,
                                SpiceCell          * cell  );


   void              stelab_c ( void               * naif_state,
                                ConstSpiceDouble    pobj[3],
                                ConstSpiceDouble    vobs[3],
                                SpiceDouble         appobj[3] );


   void              stpool_c ( void               * naif_state,
                                ConstSpiceChar    * item,
                                SpiceInt            nth,
                                ConstSpiceChar    * contin,
                                SpiceInt            lenout,
                                SpiceChar         * string,
                                SpiceInt          * size,
                                SpiceBoolean      * found  );


   void              str2et_c ( void               * naif_state,
                                ConstSpiceChar    * date,
                                SpiceDouble       * et   );


   void              subpnt_c ( void               * naif_state,
                                ConstSpiceChar    * method,
                                ConstSpiceChar    * target,
                                SpiceDouble         et,
                                ConstSpiceChar    * fixref,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * obsrvr,
                                SpiceDouble         spoint [3],
                                SpiceDouble       * trgepc,
                                SpiceDouble         srfvec [3] );


   void              subpt_c( void               * naif_state,
                                 ConstSpiceChar    * method,
                                ConstSpiceChar    * target,
                                SpiceDouble         et,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * obsrvr,
                                SpiceDouble         spoint [3],
                                SpiceDouble       * alt         );

   void              subpt_pl02( void                 * naif_state,
                                 SpiceInt               handle,
                                 ConstSpiceDLADescr   * dladsc,
                                 ConstSpiceChar       * method,
                                 ConstSpiceChar       * target,
                                 SpiceDouble            et,
                                 ConstSpiceChar       * abcorr,
                                 ConstSpiceChar       * obsrvr,
                                 SpiceDouble            spoint [3],
                                 SpiceDouble          * alt,
                                 SpiceInt             * plateID     );


   void              subslr_c ( void               * naif_state,
                                ConstSpiceChar    * method,
                                ConstSpiceChar    * target,
                                SpiceDouble         et,
                                ConstSpiceChar    * fixref,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * obsrvr,
                                SpiceDouble         spoint [3],
                                SpiceDouble       * trgepc,
                                SpiceDouble         srfvec [3] );


   void              subsol_c ( void               * naif_state,
                                ConstSpiceChar    * method,
                                ConstSpiceChar    * target,
                                SpiceDouble         et,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * obsrvr,
                                SpiceDouble         spoint[3] );


   void              subsol_pl02 ( void                 * naif_state,
                                   SpiceInt               handle,
                                   ConstSpiceDLADescr   * dladsc,
                                   ConstSpiceChar       * method,
                                   ConstSpiceChar       * target,
                                   SpiceDouble            et,
                                   ConstSpiceChar       * abcorr,
                                   ConstSpiceChar       * obsrvr,
                                   SpiceDouble            spoint [3],
                                   SpiceDouble          * dist,
                                   SpiceInt             * plateID   );


   SpiceDouble       sumad_c( void               * naif_state,
                                 ConstSpiceDouble    array[],
                                SpiceInt            n        );


   SpiceInt          sumai_c( void               * naif_state,
                                 ConstSpiceInt       array[],
                                SpiceInt            n        );


   void              surfnm_c ( void               * naif_state,
                                SpiceDouble         a,
                                SpiceDouble         b,
                                SpiceDouble         c,
                                ConstSpiceDouble    point[3],
                                SpiceDouble         normal[3] );


   void              surfpt_c ( void               * naif_state,
                                ConstSpiceDouble    positn[3],
                                ConstSpiceDouble    u[3],
                                SpiceDouble         a,
                                SpiceDouble         b,
                                SpiceDouble         c,
                                SpiceDouble         point[3],
                                SpiceBoolean      * found     );


   void              surfpv_c ( void               * naif_state,
                                ConstSpiceDouble    stvrtx[6],
                                ConstSpiceDouble    stdir [6],
                                SpiceDouble         a,
                                SpiceDouble         b,
                                SpiceDouble         c,
                                SpiceDouble         stx   [6],
                                SpiceBoolean      * found      );


   void              swpool_c ( void               * naif_state,
                                ConstSpiceChar    * agent,
                                SpiceInt            nnames,
                                SpiceInt            lenvals,
                                const void        * names   );


   void              sxform_c ( void               * naif_state,
                                ConstSpiceChar    * from,
                                ConstSpiceChar    * to,
                                SpiceDouble         et,
                                SpiceDouble         xform[6][6] );


   void              szpool_c ( void               * naif_state,
                                ConstSpiceChar    * name,
                                SpiceInt          * n,
                                SpiceBoolean      * found );


   void              term_pl02 ( void                * naif_state,
                                 SpiceInt              handle,
                                 ConstSpiceDLADescr  * dladsc,
                                 ConstSpiceChar      * trmtyp,
                                 ConstSpiceChar      * source,
                                 ConstSpiceChar      * target,
                                 SpiceDouble           et,
                                 ConstSpiceChar      * fixref,
                                 ConstSpiceChar      * abcorr,
                                 ConstSpiceChar      * obsrvr,
                                 SpiceInt              npoints,
                                 SpiceDouble         * trgepc,
                                 SpiceDouble           obspos   [3],
                                 SpiceDouble           trmpts   [][3],
                                 SpiceInt              plateIDs []     );


   void              termpt_c ( void               * naif_state,
                                ConstSpiceChar    * method,
                                ConstSpiceChar    * ilusrc,
                                ConstSpiceChar    * target,
                                SpiceDouble         et,
                                ConstSpiceChar    * fixref,
                                ConstSpiceChar    * abcorr,
                                ConstSpiceChar    * corloc,
                                ConstSpiceChar    * obsrvr,
                                ConstSpiceDouble    refvec[3],
                                SpiceDouble         rolstp,
                                SpiceInt            ncuts,
                                SpiceDouble         schstp,
                                SpiceDouble         soltol,
                                SpiceInt            maxn,
                                SpiceInt            npts  [],
                                SpiceDouble         points[][3],
                                SpiceDouble         epochs[],
                                SpiceDouble         tangts[][3]  );


   void              timdef_c ( void               * naif_state,
                                ConstSpiceChar    * action,
                                ConstSpiceChar    * item,
                                SpiceInt            lenout,
                                SpiceChar         * value );


   void              timout_c ( void               * naif_state,
                                SpiceDouble         et,
                                ConstSpiceChar    * pictur,
                                SpiceInt            lenout,
                                SpiceChar         * output );


   void              tipbod_c ( void               * naif_state,
                                ConstSpiceChar    * ref,
                                SpiceInt            body,
                                SpiceDouble         et,
                                SpiceDouble         tipm[3][3] );


   void              tisbod_c ( void               * naif_state,
                                ConstSpiceChar    * ref,
                                SpiceInt            body,
                                SpiceDouble         et,
                                SpiceDouble         tsipm[6][6] );


   ConstSpiceChar  * tkvrsn_c ( void               * naif_state,
                                ConstSpiceChar    * item );


   void              tparse_c ( void               * naif_state,
                                ConstSpiceChar    * string,
                                SpiceInt            lenout,
                                SpiceDouble       * sp2000,
                                SpiceChar         * errmsg  );


   void              tpictr_c ( void               * naif_state,
                                ConstSpiceChar    * sample,
                                SpiceInt            lenpictur,
                                SpiceInt            lenerror,
                                SpiceChar         * pictur,
                                SpiceBoolean      * ok,
                                SpiceChar         * error     );


   SpiceDouble       trace_c( void               * naif_state,
                                 ConstSpiceDouble    matrix[3][3] );


   void              trcdep_c ( void               * naif_state,
                                SpiceInt          * depth );


   void              trcnam_c ( void               * naif_state,
                                SpiceInt            index,
                                SpiceInt            namelen,
                                SpiceChar         * name     );


   void              trcoff_c ( void               * naif_state );


   void              tsetyr_c ( void               * naif_state,
                                SpiceInt            year );


   SpiceDouble       twopi_c( void               * naif_state );


   void              twovec_c ( void               * naif_state,
                                ConstSpiceDouble    axdef  [3],
                                SpiceInt            indexa,
                                ConstSpiceDouble    plndef [3],
                                SpiceInt            indexp,
                                SpiceDouble         mout   [3][3] );


   SpiceDouble       tyear_c( void               * naif_state );


   void              ucase_c( void               * naif_state,
                                 SpiceChar         * in,
                                SpiceInt            lenout,
                                SpiceChar         * out    );


   void              ucrss_c( void               * naif_state,
                                 ConstSpiceDouble    v1[3],
                                ConstSpiceDouble    v2[3],
                                SpiceDouble         vout[3] );


   void              uddc_c ( void               * naif_state,
                                void       ( * udfunc ) ( void         * naif_state,
                                                          SpiceDouble    x,
                                                          SpiceDouble  * value ),

                              SpiceDouble    x,
                              SpiceDouble    dx,
                              SpiceBoolean * isdecr );


   void              uddf_c ( void         * naif_state,
                                void       ( * udfunc ) ( void         * naif_state,
                                                          SpiceDouble    x,
                                                          SpiceDouble  * value ),
                              SpiceDouble    x,
                              SpiceDouble    dx,
                              SpiceDouble  * deriv );


   void              udf_c   ( void               * naif_state,
                                 SpiceDouble   x,
                               SpiceDouble * value );


   void              union_c( void               * naif_state,
                                 SpiceCell          * a,
                                SpiceCell          * b,
                                SpiceCell          * c  );


   SpiceDouble       unitim_c ( void               * naif_state,
                                SpiceDouble         epoch,
                                ConstSpiceChar    * insys,
                                ConstSpiceChar    * outsys );


   void              unload_c ( void               * naif_state,
                                ConstSpiceChar   * file );


   void              unorm_c( void               * naif_state,
                                 ConstSpiceDouble    v1[3],
                                SpiceDouble         vout[3],
                                SpiceDouble       * vmag    );


   void              unormg_c ( void               * naif_state,
                                ConstSpiceDouble  * v1,
                                SpiceInt            ndim,
                                SpiceDouble       * vout,
                                SpiceDouble       * vmag );


   void              utc2et_c ( void               * naif_state,
                                ConstSpiceChar    * utcstr,
                                SpiceDouble       * et   );


   void              vadd_c   ( void               * naif_state,
                                 ConstSpiceDouble    v1[3],
                                ConstSpiceDouble    v2[3],
                                SpiceDouble         vout[3] ) ;


   void              vaddg_c( void               * naif_state,
                                 ConstSpiceDouble  * v1,
                                ConstSpiceDouble  * v2,
                                SpiceInt            ndim,
                                SpiceDouble       * vout );


   void              valid_c( void               * naif_state,
                                 SpiceInt             size,
                                SpiceInt             n,
                                SpiceCell          * a    );


   void              vcrss_c( void               * naif_state,
                                 ConstSpiceDouble    v1[3],
                                ConstSpiceDouble    v2[3],
                                SpiceDouble         vout[3] );


   SpiceDouble       vdist_c( void               * naif_state,
                                 ConstSpiceDouble    v1[3],
                                ConstSpiceDouble    v2[3] );


   SpiceDouble       vdistg_c ( void               * naif_state,
                                ConstSpiceDouble  * v1,
                                ConstSpiceDouble  * v2,
                                SpiceInt            ndim );


   SpiceDouble       vdot_c   ( void               * naif_state,
                                 ConstSpiceDouble    v1[3],
                                ConstSpiceDouble    v2[3] );

   SpiceDouble       vdotg_c( void               * naif_state,
                                 ConstSpiceDouble  * v1,
                                ConstSpiceDouble  * v2,
                                SpiceInt            ndim );

   void              vequ_c   ( void               * naif_state,
                                 ConstSpiceDouble    vin[3],
                                SpiceDouble         vout[3] );


   void              vequg_c( void               * naif_state,
                                 ConstSpiceDouble  * vin,
                                SpiceInt            ndim,
                                SpiceDouble       * vout );


   void              vhat_c   ( void               * naif_state,
                                 ConstSpiceDouble    v1  [3],
                                SpiceDouble         vout[3] );


   void              vhatg_c( void               * naif_state,
                                 ConstSpiceDouble  * v1,
                                SpiceInt            ndim,
                                SpiceDouble       * vout  );


   void              vlcom_c( void               * naif_state,
                                 SpiceDouble         a,
                                ConstSpiceDouble    v1[3],
                                SpiceDouble         b,
                                ConstSpiceDouble    v2[3],
                                SpiceDouble         sum[3] );


   void              vlcom3_c ( void               * naif_state,
                                SpiceDouble         a,
                                ConstSpiceDouble    v1[3],
                                SpiceDouble         b,
                                ConstSpiceDouble    v2[3],
                                SpiceDouble         c,
                                ConstSpiceDouble    v3[3],
                                SpiceDouble         sum[3] );


   void              vlcomg_c ( void               * naif_state,
                                SpiceInt            n,
                                SpiceDouble         a,
                                ConstSpiceDouble  * v1,
                                SpiceDouble         b,
                                ConstSpiceDouble  * v2,
                                SpiceDouble       * sum );


   void              vminug_c ( void               * naif_state,
                                ConstSpiceDouble  * vin,
                                SpiceInt            ndim,
                                SpiceDouble       * vout );


   void              vminus_c ( void               * naif_state,
                                ConstSpiceDouble    v1[3],
                                SpiceDouble         vout[3] );


   SpiceDouble       vnorm_c( void               * naif_state,
                                 ConstSpiceDouble    v1[3] );


   SpiceDouble       vnormg_c ( void               * naif_state,
                                ConstSpiceDouble  * v1,
                                SpiceInt            ndim );


   void              vpack_c( void               * naif_state,
                                 SpiceDouble         x,
                                SpiceDouble         y,
                                SpiceDouble         z,
                                SpiceDouble         v[3] );


   void              vperp_c( void               * naif_state,
                                 ConstSpiceDouble    a[3],
                                ConstSpiceDouble    b[3],
                                SpiceDouble         p[3] );


   void              vprjp_c( void               * naif_state,
                                 ConstSpiceDouble    vin   [3],
                                ConstSpicePlane   * plane,
                                SpiceDouble         vout  [3] );


   void              vprjpi_c ( void               * naif_state,
                                ConstSpiceDouble    vin    [3],
                                ConstSpicePlane   * projpl,
                                ConstSpicePlane   * invpl,
                                SpiceDouble         vout   [3],
                                SpiceBoolean      * found       );


   void              vproj_c( void               * naif_state,
                                 ConstSpiceDouble    a[3],
                                ConstSpiceDouble    b[3],
                                SpiceDouble         p[3] );


   SpiceDouble       vrel_c   ( void               * naif_state,
                                 ConstSpiceDouble    v1[3],
                                ConstSpiceDouble    v2[3]  );


   SpiceDouble       vrelg_c( void               * naif_state,
                                 ConstSpiceDouble  * v1,
                                ConstSpiceDouble  * v2,
                                SpiceInt            ndim  );


   void              vrotv_c( void               * naif_state,
                                 ConstSpiceDouble    v[3],
                                ConstSpiceDouble    axis[3],
                                SpiceDouble         theta,
                                SpiceDouble         r[3] );


   void              vscl_c   ( void               * naif_state,
                                 SpiceDouble         s,
                                ConstSpiceDouble    v1[3],
                                SpiceDouble         vout[3] );


   void              vsclg_c( void               * naif_state,
                                 SpiceDouble         s,
                                ConstSpiceDouble  * v1,
                                SpiceInt            ndim,
                                SpiceDouble       * vout  );


   SpiceDouble       vsep_c   ( void               * naif_state,
                                 ConstSpiceDouble    v1[3],
                                ConstSpiceDouble    v2[3] );


   void              vsub_c   ( void               * naif_state,
                                 ConstSpiceDouble    v1[3],
                                ConstSpiceDouble    v2[3],
                                SpiceDouble         vout[3] );


   void              vsubg_c( void               * naif_state,
                                 ConstSpiceDouble  * v1,
                                ConstSpiceDouble  * v2,
                                SpiceInt            ndim,
                                SpiceDouble       * vout  );


   SpiceDouble       vsepg_c( void               * naif_state,
                                 ConstSpiceDouble  * v1,
                                ConstSpiceDouble  * v2,
                                SpiceInt            ndim );


   SpiceDouble       vtmv_c   ( void               * naif_state,
                                 ConstSpiceDouble    v1     [3],
                                ConstSpiceDouble    matrix [3][3],
                                ConstSpiceDouble    v2     [3]    );


   SpiceDouble       vtmvg_c( void               * naif_state,
                                 const void        * v1,
                                const void        * matrix,
                                const void        * v2,
                                SpiceInt            nrow,
                                SpiceInt            ncol          );


   void              vupack_c ( void               * naif_state,
                                ConstSpiceDouble    v[3],
                                SpiceDouble       * x,
                                SpiceDouble       * y,
                                SpiceDouble       * z     );

   SpiceBoolean      vzero_c( void               * naif_state,
                                 ConstSpiceDouble     v[3] );


   SpiceBoolean      vzerog_c ( void               * naif_state,
                                ConstSpiceDouble  * v,
                                SpiceInt            ndim );

   SpiceInt          wncard_c ( void               * naif_state,
                                SpiceCell          * window );

   void              wncomd_c ( void               * naif_state,
                                SpiceDouble          left,
                                SpiceDouble          right,
                                SpiceCell          * window,
                                SpiceCell          * result );


   void              wncond_c ( void               * naif_state,
                                SpiceDouble          left,
                                SpiceDouble          right,
                                SpiceCell          * window );


   void              wndifd_c ( void               * naif_state,
                                SpiceCell          * a,
                                SpiceCell          * b,
                                 SpiceCell         * c  );


   SpiceBoolean      wnelmd_c ( void               * naif_state,
                                SpiceDouble          point,
                                SpiceCell          * window );


   void              wnexpd_c ( void               * naif_state,
                                SpiceDouble          left,
                                SpiceDouble          right,
                                SpiceCell          * window );


   void              wnextd_c ( void               * naif_state,
                                SpiceChar            side,
                                SpiceCell          * window );


   void              wnfetd_c ( void               * naif_state,
                                SpiceCell          * window,
                                SpiceInt             n,
                                SpiceDouble        * left,
                                SpiceDouble        * right   );


   void              wnfild_c ( void               * naif_state,
                                SpiceDouble          sml,
                                SpiceCell          * window );


   void              wnfltd_c ( void               * naif_state,
                                SpiceDouble          sml,
                                SpiceCell          * window );


   SpiceBoolean      wnincd_c ( void               * naif_state,
                                SpiceDouble          left,
                                SpiceDouble          right,
                                SpiceCell          * window  );


   void              wninsd_c ( void               * naif_state,
                                SpiceDouble          left,
                                SpiceDouble          right,
                                SpiceCell          * window );


   void              wnintd_c ( void               * naif_state,
                                SpiceCell          * a,
                                SpiceCell          * b,
                                SpiceCell          * c  );


   SpiceBoolean      wnreld_c ( void               * naif_state,
                                SpiceCell          * a,
                                ConstSpiceChar     * op,
                                SpiceCell          * b   );


   void              wnsumd_c ( void               * naif_state,
                                SpiceCell          * window,
                                SpiceDouble        * meas,
                                SpiceDouble        * avg,
                                SpiceDouble        * stddev,
                                SpiceInt           * shortest,
                                SpiceInt           * longest   );


   void              wnunid_c ( void               * naif_state,
                                SpiceCell          * a,
                                SpiceCell          * b,
                                SpiceCell          * c  );


   void              wnvald_c ( void               * naif_state,
                                SpiceInt             size,
                                SpiceInt             n,
                                SpiceCell          * window );



   void              xf2eul_c ( void               * naif_state,
                                ConstSpiceDouble     xform  [6][6],
                                SpiceInt             axisa,
                                SpiceInt             axisb,
                                SpiceInt             axisc,
                                SpiceDouble          eulang [6],
                                SpiceBoolean       * unique         );


   void              xf2rav_c ( void               * naif_state,
                                ConstSpiceDouble     xform [6][6],
                                SpiceDouble          rot   [3][3],
                                SpiceDouble          av    [3]     );

   void              xfmsta_c ( void               * naif_state,
                                ConstSpiceDouble     input_state  [6],
                                ConstSpiceChar    *  input_coord_sys,
                                ConstSpiceChar    *  output_coord_sys,
                                ConstSpiceChar    *  body,
                                SpiceDouble          output_state [6] );

   void              xpose_c( void               * naif_state,
                                 ConstSpiceDouble    m1  [3][3],
                                SpiceDouble         mout[3][3] );


   void              xpose6_c ( void               * naif_state,
                                ConstSpiceDouble    m1  [6][6],
                                SpiceDouble         mout[6][6] );


   void              xposeg_c ( void               * naif_state,
                                const void        * matrix,
                                SpiceInt            nrow,
                                SpiceInt            ncol,
                                void              * xposem );


   void              zzgetcml_c( void               * naif_state,
                                 SpiceInt          * argc,
                                 SpiceChar       *** argv,
                                 SpiceBoolean        init );


   SpiceBoolean      zzgfgeth_c ( void               * naif_state );


   void              zzgfsavh_c( void               * naif_state,
                                 SpiceBoolean        status );


   void              zzsynccl_c( void               * naif_state,
                                 SpiceTransDir       xdir,
                                 SpiceCell         * cell );


#endif
