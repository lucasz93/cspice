#include "f2c.h"
#include "fio.h"
#include "cspice_user.h"

/* -------------------------------------------------------------------------- */
typedef struct {
logical savok;
} accept_init_t;

typedef struct {
logical savok;
} accept_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char a[2*3];
char an[2*3];
char anword[8*22];
char aword[8*33];
/* Table of constant values */

integer c__33;
integer c__22;
} ana_init_t;

typedef struct {
char a[2*3];
char an[2*3];
char anword[8*22];
char aword[8*33];
/* Table of constant values */

integer c__33;
integer c__22;
integer caps;
integer i__;
char begin[1];
char start[32*7];
char mycase[1];
char myword[32];

} ana_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} bedec_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} bedec_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} benum_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} benum_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical pass1;
/* Table of constant values */

integer c__0;
integer c__127;
integer c__128;
} bltfrm_init_t;

typedef struct {
logical pass1;
/* Table of constant values */

integer c__0;
integer c__127;
integer c__128;
integer i__;
integer j;
integer fcode[127];
integer bidids[128];
integer to;
integer fclsid[127];
integer bididx[128];
char frname[32*127];
integer bidpol[134];
integer fclass[127];
integer corder[127];
integer center[127];
integer bnmidx[128];
integer bidlst[128];
integer bnmpol[134];
char bnmnms[32*128];
integer ctrord[127];
integer bnmlst[128];
} bltfrm_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
logical found;
/* Table of constant values */

integer c__1;
integer c__3;
integer c__200;
integer c__100;
} bodeul_init_t;

typedef struct {
logical first;
logical found;
/* Table of constant values */

integer c__1;
integer c__3;
integer c__200;
integer c__100;
integer j2code;
} bodeul_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} bodfnd_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} bodfnd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} bodvar_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} bodvar_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
integer c__1;
} bodvcd_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
integer c__1;
} bodvcd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__0;
integer c__1;
} bodvrd_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__0;
integer c__1;
logical svfnd1;
integer svctr1[2];
integer svbdid;
char svbdnm[36];
} bodvrd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical ready;
char frames[16*21];
char bases[16*21];
char defs[80*21];
integer dframe;
/* Table of constant values */

doublereal c_b6;
integer c__1;
integer c__9;
integer c__21;
} chgirf_init_t;

typedef struct {
logical ready;
char frames[16*21];
char bases[16*21];
char defs[80*21];
integer dframe;
/* Table of constant values */

doublereal c_b6;
integer c__1;
integer c__9;
integer c__21;
integer axis;
char word[25];
integer b;
integer i__;
integer j;
integer p;
doublereal angle;
doublereal trans[189]	/* was [9][21] */;
char error[25];
doublereal radang;
doublereal tmpmat[9]	/* was [3][3] */;
integer loc;
} chgirf_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical fresub;
integer nft;
integer nit;
integer next;
integer savep;
doublereal savtol;
char status[40];
/* Table of constant values */

integer c_b9;
integer c__5000;
integer c__5;
integer c__2;
integer c__6;
} ckbsr_init_t;

typedef struct {
logical fresub;
integer nft;
integer nit;
integer next;
integer savep;
doublereal savtol;
char status[40];
/* Table of constant values */

integer c_b9;
integer c__5000;
integer c__5;
integer c__2;
integer c__6;
doublereal itlb[100];
doublereal itub[100];
doublereal reqt;
doublereal alpha;
doublereal omega;
integer itbeg[100];
integer slbeg;
integer fthan[5000];
doublereal stdcd[200000]	/* was [2][100000] */;
integer sticd[600000]	/* was [6][100000] */;
integer ithfs[100];
integer sthan[100000];
integer itlfs[100];
integer itins[100];
integer ftnum[5000];
integer itexp[100];
logical avneed;
integer findex;
integer iindex;
logical itchkp[100];
logical newsch;
char stidnt[40*100000];
doublereal itprvd[500]	/* was [5][100] */;
integer itprvf[100];
char itprvi[40*100];
integer itprvh[100];
integer itruex[100];
integer stpool[200012]	/* was [2][100006] */;
integer scinst;
logical fnd;
integer top;

} ckbsr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckcov_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckcov_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__4;
} cke02_init_t;

typedef struct {
/* Table of constant values */

integer c__4;
} cke02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__4;
integer c__3;
} cke03_init_t;

typedef struct {
/* Table of constant values */

integer c__4;
integer c__3;
} cke03_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__4;
} cke04_init_t;

typedef struct {
/* Table of constant values */

integer c__4;
} cke04_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__4;
} cke05_init_t;

typedef struct {
/* Table of constant values */

integer c__4;
} cke05_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckfrot_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckfrot_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckfxfm_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckfxfm_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__2;
integer c__6;
integer c__9;
} ckgpav_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__2;
integer c__6;
integer c__9;
char svref[32];
integer svctr1[2];
integer svrefr;
} ckgpav_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__2;
integer c__6;
integer c__9;
} ckgp_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__2;
integer c__6;
integer c__9;
char svref[32];
integer svctr1[2];
integer svrefr;
} ckgp_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckgr01_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckgr01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__7;
} ckgr02_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__7;
} ckgr02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckgr03_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckgr03_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__7;
doublereal c_b15;
} ckgr04_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__7;
doublereal c_b15;
} ckgr04_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckgr05_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckgr05_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer pktszs[4];
/* Table of constant values */

integer c__2;
integer c__6;
} ckgr06_init_t;

typedef struct {
integer pktszs[4];
/* Table of constant values */

integer c__2;
integer c__6;
} ckgr06_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char base[7];
integer currnt;
logical first;
integer last;
logical nodata;
/* Table of constant values */

integer c__30;
integer c__1;
integer c__0;
integer c__2;
} ckmeta_init_t;

typedef struct {
char base[7];
integer currnt;
logical first;
integer last;
logical nodata;
/* Table of constant values */

integer c__30;
integer c__1;
integer c__0;
integer c__2;
integer this__;
integer spks[30];
integer n;
char agent[32*30];
logical found[2];
integer sclks[30];
logical update;
integer cksord[30];
char mymeta[7];
char lookup[32*2*30];
integer usrctr[60]	/* was [2][30] */;
integer cks[30];

} ckmeta_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckmp06_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckmp06_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} cknm06_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} cknm06_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} cknr01_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} cknr01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} cknr02_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} cknr02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} cknr03_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} cknr03_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__12;
} cknr04_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__12;
} cknr04_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} cknr05_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} cknr05_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckobj_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckobj_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckopn_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckopn_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckpfs_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckpfs_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckr01_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckr01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__7;
} ckr02_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__7;
} ckr02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal prevs;
doublereal prevn;
integer lhand;
integer lbeg;
integer lend;
/* Table of constant values */

integer c__2;
integer c__6;
} ckr03_init_t;

typedef struct {
doublereal prevs;
doublereal prevn;
integer lhand;
integer lbeg;
integer lend;
/* Table of constant values */

integer c__2;
integer c__6;
} ckr03_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__7;
doublereal c_b18;
} ckr04_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__7;
doublereal c_b18;
} ckr04_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer lbeg;
integer lend;
integer lhand;
doublereal prevn;
doublereal prevnn;
doublereal prevs;
/* Table of constant values */

integer c__2;
integer c__6;
} ckr05_init_t;

typedef struct {
integer lbeg;
integer lend;
integer lhand;
doublereal prevn;
doublereal prevnn;
doublereal prevs;
/* Table of constant values */

integer c__2;
integer c__6;
} ckr05_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer mxwnsz[4];
integer svmiix;
integer svminb;
integer svn;
integer svnpkt;
integer svpkdb;
integer svpknd;
integer svpksz;
doublereal svrate;
integer svstyp;
integer svwnsz;
logical pass1;
integer pktszs[4];
integer svbeg;
doublereal svbtim;
doublereal svetim;
logical svfnd;
integer svhan;
logical svlast;
/* Table of constant values */

integer c__196;
integer c__340;
integer c__2;
integer c__6;
} ckr06_init_t;

typedef struct {
integer mxwnsz[4];
integer svmiix;
integer svminb;
integer svn;
integer svnpkt;
integer svpkdb;
integer svpknd;
integer svpksz;
doublereal svrate;
integer svstyp;
integer svwnsz;
logical pass1;
integer pktszs[4];
integer svbeg;
doublereal svbtim;
doublereal svetim;
logical svfnd;
integer svhan;
logical svlast;
/* Table of constant values */

integer c__196;
integer c__340;
integer c__2;
integer c__6;
} ckr06_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__4;
integer c__3;
integer c__1;
} ckw01_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__4;
integer c__3;
integer c__1;
} ckw01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__4;
integer c__3;
integer c__1;
} ckw02_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__4;
integer c__3;
integer c__1;
} ckw02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__4;
integer c__3;
integer c__1;
} ckw03_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__4;
integer c__3;
integer c__1;
} ckw03_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__142;
integer c__7;
doublereal c_b20;
} ckw04a_init_t;

typedef struct {
/* Table of constant values */

integer c__142;
integer c__7;
doublereal c_b20;
} ckw04a_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__0;
integer c__3;
} ckw04b_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__0;
integer c__3;
} ckw04b_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckw04e_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} ckw04e_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__4;
integer c__23;
integer c__2;
integer c__6;
integer c__1;
} ckw05_init_t;

typedef struct {
/* Table of constant values */

integer c__4;
integer c__23;
integer c__2;
integer c__6;
integer c__1;
} ckw05_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer pktszs[4];
/* Table of constant values */

integer c__196;
integer c__340;
integer c__23;
integer c__4;
integer c__2;
integer c__6;
integer c__1;
} ckw06_init_t;

typedef struct {
integer pktszs[4];
/* Table of constant values */

integer c__196;
integer c__340;
integer c__23;
integer c__4;
integer c__2;
integer c__6;
integer c__1;
} ckw06_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char units[16*31];
doublereal cnvrtn[31];
char type__[8*31];
/* Table of constant values */

integer c__31;
integer c__5;
integer c__3;
integer c__9;
} convrt_init_t;

typedef struct {
logical first;
char units[16*31];
doublereal cnvrtn[31];
char type__[8*31];
/* Table of constant values */

integer c__31;
integer c__5;
integer c__3;
integer c__9;
} convrt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} countc_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} countc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Fortran I/O blocks */
cilist io___21;
cilist io___30;
cilist io___31;
cilist io___32;
cilist io___33;
/* Table of constant values */

logical c_false;
integer c__1;
} dafac_init_t;

typedef struct {
logical first;
/* Fortran I/O blocks */
cilist io___21;
cilist io___30;
cilist io___31;
cilist io___32;
cilist io___33;
/* Table of constant values */

logical c_false;
integer c__1;
char eocmrk[1];
char eolmrk[1];
} dafac_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
integer nft;
/* Fortran I/O blocks */
cilist io___25;
cilist io___26;
cilist io___27;
cilist io___28;
cilist io___29;
cilist io___30;
/* Table of constant values */

integer c__5000;
logical c_false;
integer c__2;
integer c__124;
integer c__250;
integer c__125;
integer c__128;
integer c__1;
logical c_true;
} dafah_init_t;

typedef struct {
logical first;
integer nft;
/* Fortran I/O blocks */
cilist io___25;
cilist io___26;
cilist io___27;
cilist io___28;
cilist io___29;
cilist io___30;
/* Table of constant values */

integer c__5000;
logical c_false;
integer c__2;
integer c__124;
integer c__250;
integer c__125;
integer c__128;
integer c__1;
logical c_true;
integer ibff;
char crec[1000];
doublereal drec[128];
integer iarc;
integer iamh;
integer free;
integer ftnd[5000];
integer ftni[5000];
integer i__;
integer bward;
integer fthan[5000];
integer fward;
logical found;
integer ftlnk[5000];
char ttype[4];
char dafnam[255];
integer findex;
char format[8];
char idword[8];
integer fhlist[5006];
integer iostat;
char acc[10];
integer fnb;
integer fnd;
char ifn[60];
integer fni;
integer lun;

} dafah_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
integer sthead;
integer stfptr;
/* Table of constant values */

integer c__5000;
integer c__20;
integer c__1;
integer c__128;
} dafana_init_t;

typedef struct {
logical first;
integer sthead;
integer stfptr;
/* Table of constant values */

integer c__5000;
integer c__20;
integer c__1;
integer c__128;
integer cloc;
integer dloc;
integer free;
integer stfh[20];
integer word;
integer prev;
integer next;
integer i__;
integer p;
integer bward;
integer fward;
logical found;
integer nextp;
doublereal dc[124];
integer ic[250];
integer nd;
char dafnam[255];
integer ni;
char ifname[60];
char namrec[1000];
logical staddg[20];
integer stbegn[20];
integer stfree[20];
char stname[1000*20];
integer narray;
doublereal sumrec[128];
char stifnm[60*20];
integer namsiz;
integer opnset[5006];
integer stlast[20];
integer stpool[20];
integer stfrst[20];
doublereal stlsum[2500]	/* was [125][20] */;
integer sumsiz;

} dafana_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__128;
} dafarr_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__128;
} dafarr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___5;
cilist io___12;
cilist io___13;
cilist io___14;
cilist io___15;
cilist io___23;
cilist io___24;
cilist io___25;
cilist io___27;
cilist io___33;
cilist io___34;
cilist io___35;
cilist io___36;
cilist io___37;
cilist io___38;
/* Table of constant values */

logical c_false;
integer c__1;
integer c__3;
integer c__9;
integer c__5;
} dafb2t_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___5;
cilist io___12;
cilist io___13;
cilist io___14;
cilist io___15;
cilist io___23;
cilist io___24;
cilist io___25;
cilist io___27;
cilist io___33;
cilist io___34;
cilist io___35;
cilist io___36;
cilist io___37;
cilist io___38;
/* Table of constant values */

logical c_false;
integer c__1;
integer c__3;
integer c__9;
integer c__5;
} dafb2t_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___4;
/* Table of constant values */

logical c_false;
integer c__1;
integer c__3;
integer c__2;
} dafbt_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___4;
/* Table of constant values */

logical c_false;
integer c__1;
integer c__3;
integer c__2;
} dafbt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Fortran I/O blocks */
cilist io___29;
cilist io___33;
cilist io___38;
/* Table of constant values */

logical c_false;
integer c__1;
integer c__5000;
} dafec_init_t;

typedef struct {
logical first;
/* Fortran I/O blocks */
cilist io___29;
cilist io___33;
cilist io___38;
/* Table of constant values */

logical c_false;
integer c__1;
integer c__5000;
integer filhan[5000];
char crecrd[1000];
integer filchr[5000];
integer filcnt[5000];
char eocmrk[1];
integer nfiles;
char eolmrk[1];
integer lsthan;
integer lstrec[5000];
integer lstpos[5000];
} dafec_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
logical sthvnr[5000];
integer stfptr;
integer sthead;
/* Table of constant values */

integer c__5000;
integer c__1;
integer c__128;
} daffa_init_t;

typedef struct {
logical first;
logical sthvnr[5000];
integer stfptr;
integer sthead;
/* Table of constant values */

integer c__5000;
integer c__1;
integer c__128;
integer free;
doublereal exdc[124];
integer exic[250];
integer stfh[5000];
integer prev;
char stnr[1000*5000];
doublereal stsr[640000]	/* was [128][5000] */;
integer i__;
integer p;
integer bward;
doublereal newdc[124];
integer fward;
integer newic[250];
integer nextp;
doublereal exsum[124];
integer nd;
char dafnam[255];
integer ni;
char ifname[60];
integer offset;
integer namsiz;
integer stnseg[5000];
integer opnset[5006];
integer stthis[5000];
integer stpool[5000];
integer stcurr[5000];
integer stprev[5000];
integer stnext[5000];
integer sumsiz;
logical fnd;

} daffa_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal equiv_0[125];

} dafps_init_t;

typedef struct {
doublereal equiv_0[125];

} dafps_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___3;
/* Table of constant values */

logical c_false;
integer c__1;
} dafrcr_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___3;
/* Table of constant values */

logical c_false;
integer c__1;
} dafrcr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__128;
} dafrrr_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__128;
} dafrrr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer rbhan[100];
integer rbrec[100];
integer rbreq[100];
doublereal rbdat[12800]	/* was [128][100] */;
integer rbnbr;
integer nread;
integer nreq;
/* Fortran I/O blocks */
cilist io___21;
/* Table of constant values */

logical c_false;
integer c__128;
} dafrwd_init_t;

typedef struct {
integer rbhan[100];
integer rbrec[100];
integer rbreq[100];
doublereal rbdat[12800]	/* was [128][100] */;
integer rbnbr;
integer nread;
integer nreq;
/* Fortran I/O blocks */
cilist io___21;
/* Table of constant values */

logical c_false;
integer c__128;
} dafrwd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___5;
cilist io___6;
cilist io___13;
cilist io___15;
cilist io___17;
cilist io___20;
cilist io___23;
cilist io___25;
cilist io___27;
cilist io___28;
cilist io___29;
cilist io___30;
/* Table of constant values */

integer c__9;
integer c__1;
integer c__3;
integer c__5;
} daft2b_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___5;
cilist io___6;
cilist io___13;
cilist io___15;
cilist io___17;
cilist io___20;
cilist io___23;
cilist io___25;
cilist io___27;
cilist io___28;
cilist io___29;
cilist io___30;
/* Table of constant values */

integer c__9;
integer c__1;
integer c__3;
integer c__5;
} daft2b_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___5;
cilist io___9;
cilist io___27;
cilist io___32;
/* Table of constant values */

integer c__9;
integer c__1;
integer c__2;
integer c__0;
integer c__3;
} daftb_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___5;
cilist io___9;
cilist io___27;
cilist io___32;
/* Table of constant values */

integer c__9;
integer c__1;
integer c__2;
integer c__0;
integer c__3;
} daftb_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___3;
/* Table of constant values */

logical c_false;
integer c__1;
} dafwcr_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___3;
/* Table of constant values */

logical c_false;
integer c__1;
} dafwcr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__128;
} dafwda_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__128;
} dafwda_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___4;
cilist io___14;
/* Table of constant values */

logical c_false;
integer c__1;
} dafwfr_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___4;
cilist io___14;
/* Table of constant values */

logical c_false;
integer c__1;
} dafwfr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer next[3];
logical prvok;
integer tbbase[60]	/* was [3][20] */;
logical tbfast[20];
integer tbfwrd[20];
integer tbhan[20];
integer tbmxad[60]	/* was [3][20] */;
logical tbrdon[20];
integer tbsize[60]	/* was [3][20] */;
integer prev[3];
integer nw[3];
integer rngloc[3];
logical fast;
integer fidx;
logical known;
integer nfiles;
integer prvhan;
/* Table of constant values */

integer c__1;
integer c__256;
integer c__2;
} dasa2l_init_t;

typedef struct {
integer next[3];
logical prvok;
integer tbbase[60]	/* was [3][20] */;
logical tbfast[20];
integer tbfwrd[20];
integer tbhan[20];
integer tbmxad[60]	/* was [3][20] */;
logical tbrdon[20];
integer tbsize[60]	/* was [3][20] */;
integer prev[3];
integer nw[3];
integer rngloc[3];
logical fast;
integer fidx;
logical known;
integer nfiles;
integer prvhan;
/* Table of constant values */

integer c__1;
integer c__256;
integer c__2;
integer free;
integer nrec;
integer i__;
integer j;
integer range[2];
integer ncomc;
logical segok;
integer ncomr;
integer ndirs;
integer ub;
integer hiaddr;
integer baserc;
char access[10];
integer dscloc;
integer dirrec[256];
logical samfil;
integer mxaddr;
integer lstrec[3];
integer nresvc;
integer nxtrec;
integer lstwrd[3];
integer nresvr;
integer ntypes;
integer curtyp;
integer prvtyp;

} dasa2l_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

logical c_false;
} dasac_init_t;

typedef struct {
logical first;
/* Table of constant values */

logical c_false;
char eolmrk[1];
} dasac_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer next[3];
integer prev[3];
/* Table of constant values */

logical c_false;
integer c__3;
integer c__256;
} dasacr_init_t;

typedef struct {
integer next[3];
integer prev[3];
/* Table of constant values */

logical c_false;
integer c__3;
integer c__256;
} dasacr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__22;
integer c__1;
} dasacu_init_t;

typedef struct {
/* Table of constant values */

integer c__22;
integer c__1;
} dasacu_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} dasadc_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} dasadc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
} dasadd_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
} dasadd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
} dasadi_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
} dasadi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

logical c_false;
integer c__1;
integer c__3;
integer c__4;
} dasbt_init_t;

typedef struct {
/* Table of constant values */

logical c_false;
integer c__1;
integer c__3;
integer c__4;
} dasbt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical pass1;
/* Table of constant values */

integer c__5000;
logical c_false;
} dascls_init_t;

typedef struct {
logical pass1;
/* Table of constant values */

integer c__5000;
logical c_false;
integer fhset[5006];
} dascls_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer next[3];
/* Table of constant values */

integer c__3;
integer c__256;
integer c__2;
} dascud_init_t;

typedef struct {
integer next[3];
/* Table of constant values */

integer c__3;
integer c__256;
integer c__2;
} dascud_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

logical c_false;
integer c__5000;
} dasec_init_t;

typedef struct {
logical first;
/* Table of constant values */

logical c_false;
integer c__5000;
integer filhan[5000];
char crecrd[1024];
integer filchr[5000];
integer filcnt[5000];
integer lsthan;
integer nfiles;
integer lstrec[5000];
integer lstpos[5000];
} dasec_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__22;
} dasecu_init_t;

typedef struct {
/* Table of constant values */

integer c__22;
} dasecu_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer ftacc[5000];
integer fthan[5000];
integer ftlnk[5000];
logical pass1;
integer fthead;
integer next[3];
integer prev[3];
integer nw[3];
/* Fortran I/O blocks */
cilist io___42;
cilist io___44;
cilist io___47;
/* Table of constant values */

integer c__5000;
integer c__14;
integer c__3;
logical c_false;
integer c__2;
integer c__0;
integer c__256;
logical c_true;
integer c__1;
} dasfm_init_t;

typedef struct {
integer ftacc[5000];
integer fthan[5000];
integer ftlnk[5000];
logical pass1;
integer fthead;
integer next[3];
integer prev[3];
integer nw[3];
/* Fortran I/O blocks */
cilist io___42;
cilist io___44;
cilist io___47;
/* Table of constant values */

integer c__5000;
integer c__14;
integer c__3;
logical c_false;
integer c__2;
integer c__0;
integer c__256;
logical c_true;
integer c__1;
integer nrec;
char tail[932];
integer last;
integer pool[10012]	/* was [2][5006] */;
integer type__;
integer i__;
integer ldrec[3];
logical found;
integer ftsum[70000]	/* was [14][5000] */;
char ttype[4];
integer endrec;
integer loccch;
char locdas[255];
integer loccrc;
integer dirrec[256];
char locifn[60];
char format[8];
char idword[8];
char locfmt[8];
integer fhlist[5006];
integer findex;
integer inqsta;
integer iostat;
integer dsctyp;
integer ldrmax;
integer locrrc;
integer locrch;
integer maxadr;
integer number;
integer nxtdir;
integer nxtrec;
integer curtyp;
integer prvtyp;
char acc[10];
integer fnb;
integer loc;
integer new__;
integer pos;

} dasfm_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___2;
cilist io___3;
/* Table of constant values */

integer c__1;
} dasioc_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___2;
cilist io___3;
/* Table of constant values */

integer c__1;
} dasioc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___2;
cilist io___3;
/* Table of constant values */

integer c__128;
} dasiod_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___2;
cilist io___3;
/* Table of constant values */

integer c__128;
} dasiod_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___2;
cilist io___3;
/* Table of constant values */

integer c__256;
} dasioi_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___2;
cilist io___3;
/* Table of constant values */

integer c__256;
} dasioi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer next[3];
integer prev[3];
/* Table of constant values */

logical c_false;
integer c__3;
integer c__256;
} dasrcr_init_t;

typedef struct {
integer next[3];
integer prev[3];
/* Table of constant values */

logical c_false;
integer c__3;
integer c__256;
} dasrcr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} dasrdc_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} dasrdc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__1;
} dasrdd_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__1;
} dasrdd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
} dasrdi_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
} dasrdi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical pass1;
integer hnbufi[10];
logical upbufc[10];
logical upbufd[10];
logical upbufi[10];
integer headc;
integer headd;
integer headi;
integer unit;
integer wrunit;
integer usedc;
integer usedd;
integer usedi;
integer rnbufc[10];
integer rnbufd[10];
integer rnbufi[10];
integer hnbufc[10];
integer hnbufd[10];
/* Table of constant values */

integer c__10;
integer c__1;
integer c__128;
logical c_false;
integer c__256;
integer c__1024;
} dasrwr_init_t;

typedef struct {
logical pass1;
integer hnbufi[10];
logical upbufc[10];
logical upbufd[10];
logical upbufi[10];
integer headc;
integer headd;
integer headi;
integer unit;
integer wrunit;
integer usedc;
integer usedd;
integer usedi;
integer rnbufc[10];
integer rnbufd[10];
integer rnbufi[10];
integer hnbufc[10];
integer hnbufd[10];
/* Table of constant values */

integer c__10;
integer c__1;
integer c__128;
logical c_false;
integer c__256;
integer c__1024;
integer node;
integer next;
integer poolc[32]	/* was [2][16] */;
integer poold[32]	/* was [2][16] */;
integer pooli[32]	/* was [2][16] */;
char rcbufc[1024*10];
doublereal rcbufd[1280]	/* was [128][10] */;
integer rcbufi[2560]	/* was [256][10] */;
} dasrwr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer next[3];
integer prev[3];
/* Table of constant values */

integer c__4;
integer c__3;
integer c__1;
integer c__256;
integer c__0;
} dassdr_init_t;

typedef struct {
integer next[3];
integer prev[3];
/* Table of constant values */

integer c__4;
integer c__3;
integer c__1;
integer c__256;
integer c__0;
} dassdr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___3;
cilist io___7;
/* Table of constant values */

integer c__9;
integer c__1;
integer c__0;
logical c_false;
integer c__4;
} dastb_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___3;
cilist io___7;
/* Table of constant values */

integer c__9;
integer c__1;
integer c__0;
logical c_false;
integer c__4;
} dastb_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} dasudc_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} dasudc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
} dasudd_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
} dasudd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
} dasudi_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
} dasudi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___3;
cilist io___13;
/* Table of constant values */

logical c_false;
integer c__1;
} daswfr_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___3;
cilist io___13;
/* Table of constant values */

logical c_false;
integer c__1;
} daswfr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b2;
} dcbrt_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b2;
} dcbrt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char missed[20*5];
/* Table of constant values */

integer c__1;
integer c__2;
integer c__200;
integer c__400;
} deltet_init_t;

typedef struct {
char missed[20*5];
/* Table of constant values */

integer c__1;
integer c__2;
integer c__200;
integer c__400;
} deltet_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal ident[4]	/* was [2][2] */;
/* Table of constant values */

integer c__4;
doublereal c_b6;
integer c__2;
} diags2_init_t;

typedef struct {
doublereal ident[4]	/* was [2][2] */;
/* Table of constant values */

integer c__4;
doublereal c_b6;
integer c__2;
} diags2_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
} dlabbs_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
} dlabbs_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
} dlabfs_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
} dlabfs_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__3;
integer c_n1;
integer c__8;
} dlabns_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__3;
integer c_n1;
integer c__8;
} dlabns_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
} dlaens_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
} dlaens_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c_b8;
integer c_n1;
} dlaopn_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c_b8;
integer c_n1;
} dlaopn_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal gradm[9]	/* was [3][3] */;
doublereal m[9]	/* was [3][3] */;
/* Table of constant values */

doublereal c_b16;
} dnearp_init_t;

typedef struct {
doublereal gradm[9]	/* was [3][3] */;
doublereal m[9]	/* was [3][3] */;
/* Table of constant values */

doublereal c_b16;
} dnearp_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char digits[1*16];
/* Table of constant values */

integer c__2;
} dp2hx_init_t;

typedef struct {
char digits[1*16];
/* Table of constant values */

integer c__2;
} dp2hx_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
logical c_true;
} dpfmt_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
logical c_true;
} dpfmt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__1;
integer c__0;
} dpgrdr_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__1;
integer c__0;
logical svfnd1;
integer svctr1[2];
integer svbdid;
char svbody[36];
} dpgrdr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal value;
} dpr_init_t;

typedef struct {
doublereal value;
} dpr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical doinit;
logical first;
/* Table of constant values */

doublereal c_b19;
doublereal c_b20;
doublereal c_b22;
doublereal c_b23;
doublereal c_b25;
} dpspce_init_t;

typedef struct {
logical doinit;
logical first;
/* Table of constant values */

doublereal c_b19;
doublereal c_b20;
doublereal c_b22;
doublereal c_b23;
doublereal c_b25;
doublereal coef;
doublereal eeta;
doublereal aodp;
doublereal delo;
doublereal capu;
doublereal uang;
doublereal xmdf;
doublereal xinc;
doublereal xmam;
doublereal aynl;
doublereal elsq;
doublereal temp;
logical cont;
doublereal rdot;
doublereal cosu;
doublereal sinu;
doublereal coef1;
doublereal t2cof;
doublereal temp1;
doublereal temp2;
doublereal temp3;
doublereal temp4;
doublereal temp5;
doublereal cos2u;
doublereal temp6;
doublereal sin2u;
doublereal a;
doublereal e;
integer i__;
doublereal m[3];
doublereal n[3];
doublereal s;
doublereal u[3];
doublereal v[3];
doublereal betal;
doublereal scale;
doublereal betao;
doublereal epoch;
doublereal ecose;
doublereal aycof;
doublereal esine;
doublereal a3ovk2;
doublereal tempa;
doublereal tempe;
doublereal bstar;
doublereal cosio;
doublereal xincl;
doublereal etasq;
doublereal rfdot;
doublereal sinio;
doublereal a1;
doublereal rdotk;
doublereal c1;
doublereal c2;
doublereal cosuk;
doublereal c4;
doublereal qoms24;
doublereal sinuk;
doublereal templ;
doublereal x1m5th;
doublereal x1mth2;
doublereal x3thm1;
doublereal x7thm1;
doublereal psisq;
doublereal xinck;
doublereal xlcof;
doublereal xmdot;
doublereal xnode;
doublereal xnodp;
doublereal s4;
doublereal betao2;
doublereal theta2;
doublereal ae;
doublereal xhdot1;
doublereal ao;
doublereal em;
doublereal eo;
doublereal qoms2t;
doublereal pl;
doublereal omgadf;
doublereal rk;
doublereal qo;
doublereal uk;
doublereal so;
doublereal xl;
doublereal xn;
doublereal omegao;
doublereal perige;
doublereal xnodcf;
doublereal xnoddf;
doublereal tsince;
doublereal xnodek;
doublereal omgdot;
doublereal rfdotk;
doublereal xnodeo;
doublereal ck2;
doublereal lstelm[10];
doublereal ck4;
doublereal cosepw;
doublereal sinepw;
doublereal xkmper;
doublereal xnodot;
doublereal lstphs[8];
doublereal pinvsq;
doublereal xj2;
doublereal xj3;
doublereal xj4;
doublereal eta;
doublereal axn;
doublereal xke;
doublereal ayn;
doublereal epw;
doublereal tsi;
doublereal xll;
doublereal xmo;
doublereal xno;
doublereal tsq;
doublereal xlt;
doublereal del1;
doublereal pio2;
doublereal pix2;

} dpspce_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal power[18];
doublereal ipower[18];
char digits[1*10];
doublereal values[10];
char vaxexp[2*41];
/* Table of constant values */

integer c__2;
} dpstr_init_t;

typedef struct {
doublereal power[18];
doublereal ipower[18];
char digits[1*10];
doublereal values[10];
char vaxexp[2*41];
/* Table of constant values */

integer c__2;
} dpstr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c_n1;
logical c_false;
logical c_true;
} dpstrf_init_t;

typedef struct {
/* Table of constant values */

integer c_n1;
logical c_false;
logical c_true;
} dpstrf_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__1;
integer c__0;
} drdpgr_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__1;
integer c__0;
logical svfnd1;
integer svctr1[2];
integer svbdid;
char svbody[36];
} drdpgr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer indexs[5];
} drotat_init_t;

typedef struct {
integer indexs[5];
} drotat_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__6;
} dskb02_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__6;
} dskb02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} dskd02_init_t;

typedef struct {
logical first;
integer nv;
integer prvhan;
integer prvbas;
} dskd02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} dski02_init_t;

typedef struct {
logical first;
integer cgscal;
integer np;
integer nv;
integer nvxtot;
integer prvbas;
integer prvhan;
integer voxnpl;
integer voxnpt;
integer vtxnpl;
} dski02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c_b14;
integer c_b20;
} dskmi2_init_t;

typedef struct {
/* Table of constant values */

integer c_b14;
integer c_b20;
} dskmi2_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

logical c_false;
integer c__9;
integer c__3;
integer c__19;
} dskn02_init_t;

typedef struct {
/* Table of constant values */

logical c_false;
integer c__9;
integer c__3;
integer c__19;
} dskn02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__8;
logical c_false;
} dskobj_init_t;

typedef struct {
/* Table of constant values */

integer c__8;
logical c_false;
} dskobj_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

logical c_false;
integer c__9;
} dskp02_init_t;

typedef struct {
/* Table of constant values */

logical c_false;
integer c__9;
} dskp02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal origin[3];
/* Table of constant values */

doublereal c_b4;
} dskrb2_init_t;

typedef struct {
doublereal origin[3];
/* Table of constant values */

doublereal c_b4;
} dskrb2_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__8;
logical c_false;
} dsksrf_init_t;

typedef struct {
/* Table of constant values */

integer c__8;
logical c_false;
} dsksrf_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal dppars[6];
logical isfixd[6];
char names[6*6];
/* Table of constant values */

integer c__6;
} dsktol_init_t;

typedef struct {
doublereal dppars[6];
logical isfixd[6];
char names[6*6];
/* Table of constant values */

integer c__6;
} dsktol_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

logical c_false;
integer c__19;
} dskv02_init_t;

typedef struct {
/* Table of constant values */

logical c_false;
integer c__19;
} dskv02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c_b116;
integer c_b122;
integer c__6;
integer c__3;
integer c_b145;
doublereal c_b154;
integer c_b168;
integer c__24;
integer c__10;
integer c__1;
} dskw02_init_t;

typedef struct {
/* Table of constant values */

integer c_b116;
integer c_b122;
integer c__6;
integer c__3;
integer c_b145;
doublereal c_b154;
integer c_b168;
integer c__24;
integer c__10;
integer c__1;
} dskw02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal grdext[3];
integer prvhan;
integer prvdsc[8];
/* Table of constant values */

integer c__200;
integer c_b27;
integer c__14;
integer c__1;
integer c__8;
integer c__50000;
doublereal c_b40;
doublereal c_b41;
integer c__10;
integer c__11;
integer c_b89;
integer c__9;
integer c__3;
integer c__19;
integer c__2;
integer c__0;
} dskx02_init_t;

typedef struct {
doublereal grdext[3];
integer prvhan;
integer prvdsc[8];
/* Table of constant values */

integer c__200;
integer c_b27;
integer c__14;
integer c__1;
integer c__8;
integer c__50000;
doublereal c_b40;
doublereal c_b41;
integer c__10;
integer c__11;
integer c_b89;
integer c__9;
integer c__3;
integer c__19;
integer c__2;
integer c__0;
integer ncgr;
doublereal xtol;
doublereal vbuff[600]	/* was [3][200] */;
integer vxlcg[150000]	/* was [3][50000] */;
integer vidxs[200];
integer cgscl2;
integer cgscal;
integer np;
integer nv;
doublereal dskdsc[24];
doublereal grdtol;
doublereal voxori[3];
doublereal voxsiz;
doublereal vtxbds[6]	/* was [2][3] */;
integer cgrext[3];
integer cgrptr[100000];
integer corsys;
integer nvxtot;
integer ordvec[256000];
integer platid[256000];
integer source[256000];
integer vgrext[3];
integer voxlst[150000]	/* was [3][50000] */;
integer voxnpl;
integer voxnpt;
integer vtxnpl;
integer vxlout[50000];
integer vxlstr[50000];
} dskx02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char prvfrm[32];
integer prvtcd;
/* Table of constant values */

integer c__1;
} dskxsi_init_t;

typedef struct {
logical first;
char prvfrm[32];
integer prvtcd;
/* Table of constant values */

integer c__1;
integer trgcde;
integer fixfid;
integer svtcde;
integer frmctr[2];
integer trgctr[2];
char svtnam[36];
logical svtfnd;
} dskxsi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char prvfrm[32];
integer prvtcd;
} dskxv_init_t;

typedef struct {
logical first;
char prvfrm[32];
integer prvtcd;
integer trgcde;
integer fixfid;
integer svtcde;
integer frmctr[2];
integer trgctr[2];
logical svtfnd;
char svtnam[36];
} dskxv_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__2;
} dskz02_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__2;
} dskz02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__6;
} ducrss_init_t;

typedef struct {
/* Table of constant values */

integer c__6;
} ducrss_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b18;
integer c__9;
} edlimb_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b18;
integer c__9;
} edlimb_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b25;
} ednmpt_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b25;
} ednmpt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__3;
} edterm_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__3;
logical svfnd1;
logical svfnd2;
logical svfnd3;
integer svctr1[2];
integer svctr2[2];
integer svctr3[2];
integer svctr4[2];
integer svfrcd;
char svfref[32];
integer svtgid;
char svtarg[36];
char svscre[36];
integer svobsi;
integer svsrci;
char svobsr[36];
} edterm_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__512;
integer c__32;
integer c__1;
integer c__100;
} ekbseg_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__512;
integer c__32;
integer c__1;
integer c__100;
integer idspec[518];
} ekbseg_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
} ekdelr_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
} ekdelr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__27869;
integer c__100;
integer c__500;
} ekfind_init_t;

typedef struct {
/* Table of constant values */

integer c__27869;
integer c__100;
integer c__500;
} ekfind_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__254;
integer c_n1;
integer c__252;
integer c__3;
logical c_false;
integer c__1;
} ekinsr_init_t;

typedef struct {
/* Table of constant values */

integer c__254;
integer c_n1;
integer c__252;
integer c__3;
logical c_false;
integer c__1;
} ekinsr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} eknseg_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} eknseg_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
} ekopn_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
} ekopn_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
} ekops_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
} ekops_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char chrtyp[4*4];
/* Table of constant values */

integer c__27869;
integer c__100;
} ekpsel_init_t;

typedef struct {
char chrtyp[4*4];
/* Table of constant values */

integer c__27869;
integer c__100;
} ekpsel_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer lelts[1000];
integer oelts[10];
integer relts[1000];
char chtype[4*4];
integer fthead;
integer tbhead;
logical first;
/* Table of constant values */

integer c__20;
integer c__200;
integer c__10000;
integer c__500;
integer c__100;
integer c__24;
integer c__11;
integer c__10;
integer c__1000;
integer c__1;
integer c__0;
integer c__11000;
} ekqmgr_init_t;

typedef struct {
integer lelts[1000];
integer oelts[10];
integer relts[1000];
char chtype[4*4];
integer fthead;
integer tbhead;
logical first;
/* Table of constant values */

integer c__20;
integer c__200;
integer c__10000;
integer c__500;
integer c__100;
integer c__24;
integer c__11;
integer c__10;
integer c__1000;
integer c__1;
integer c__0;
integer c__11000;
integer begidx;
integer cdscrs[5500]	/* was [11][500] */;
integer cjrows;
integer cjsize;
integer cnstyp[1000];
integer col;
integer colptr;
integer delseg;
integer endidx;
integer key;
integer keydsc[11];
integer ldscrs[11000]	/* was [11][1000] */;
integer ltbidx[1000];
integer new__;
integer nmatch;
integer norder;
integer nsv;
integer ops[1000];
integer ordbas;
integer ptroff;
integer nact;
integer ntab;
integer rbas[10];
integer rdscrs[11000]	/* was [11][1000] */;
integer conj;
integer resbas;
integer rowidx;
integer nseg;
integer rowvec[10];
integer rtbidx[1000];
integer rtotal;
integer nsel;
integer rwvbas;
integer selcol[50];
integer selctp[50];
integer seltab[50];
integer seg;
integer segdsc[24];
integer segvec[10];
integer sgvbas;
integer tab;
integer tabidx;
integer next;
integer tbcurr;
integer top;
integer tptvec[16];
integer unrows;
logical activc[1000];
logical activv[1000];
logical attmch;
logical dosort;
logical fnd;
logical indexd;
logical keyfnd;
logical nulsok;
logical presnt;
logical sorted;
integer i__;
integer cjbeg;
integer j;
integer k;
integer cbegs[1000];
integer cjend;
integer l;
integer r__;
integer t;
integer cends[1000];
logical cmtch;
integer ubase[200];
integer fthan[20];
char cnams[32*500];
integer lxbeg;
integer lcidx[1000];
integer cvlen;
doublereal dvals[1000];
integer lxend;
integer nconj;
integer sthan[200];
integer ivals[1000];
integer ncols;
char state[80];
integer ctnew;
integer dtnew;
integer dtype[1000];
integer jsize;
integer npcol;
integer ocols[10];
integer otabs[10];
integer jbase1;
integer jbase2;
integer rcidx[1000];
integer rsize[200];
integer sense[10];
integer sizes[1000];
integer stnew;
integer usize;
logical vmtch;
integer ctclas[500];
integer ftpool[52]	/* was [2][26] */;
integer tbpool[212]	/* was [2][106] */;
integer tbstpt[100];
integer tbncol[100];
char tbnams[64*100];
integer tbctpt[100];
integer tbfils[2000]	/* was [20][100] */;
integer tbflsz[100];
integer stpool[412]	/* was [2][206] */;
integer stsidx[200];
integer stdscs[4800]	/* was [24][200] */;
integer stnrow[200];
integer stncol[200];
integer stdtpt[200];
integer dtpool[20012]	/* was [2][10006] */;
integer dtdscs[110000]	/* was [11][10000] */;
integer ctpool[1012]	/* was [2][506] */;
char ctnams[32*500];
integer cttyps[500];
integer ctlens[500];
logical ctfixd[500];
integer ctsizs[500];
logical ctindx[500];
logical ctnull[500];
char cnmset[32*506];
char colnam[32];
char frmals[64*10];
char frmtab[64*10];
char lcname[32];
char ltname[64];
char problm[80];
char rcname[32];
char rtname[64];
char tabnam[64];
char tabvec[64*16];

} ekqmgr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} ekrcec_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} ekrcec_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} ekrced_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} ekrced_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} ekrcei_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} ekrcei_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char typstr[4*4];
} ekssum_init_t;

typedef struct {
char typstr[4*4];
} ekssum_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} eqchr_init_t;

typedef struct {
logical first;
integer i__;
integer j;
integer uvalue[256];

} eqchr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

doublereal c_b13;
} eqncpv_init_t;

typedef struct {
logical first;
/* Table of constant values */

doublereal c_b13;
doublereal pi2;
} eqncpv_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char actns[7*5];
/* Table of constant values */

integer c__5;
integer c__2;
} erract_init_t;

typedef struct {
char actns[7*5];
/* Table of constant values */

integer c__5;
integer c__2;
} erract_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__2;
} errch_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__2;
} errch_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
} errdev_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
} errdev_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__14;
integer c__3;
integer c__2;
} errdp_init_t;

typedef struct {
/* Table of constant values */

integer c__14;
integer c__3;
integer c__2;
} errdp_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__0;
} errhan_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__0;
} errhan_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__2;
} errint_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__2;
} errint_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
integer c__10;
integer c__2;
} errprt_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
integer c__10;
integer c__2;
} errprt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b4;
doublereal c_b6;
integer c__10;
integer c__2;
integer c__1;
doublereal c_b32;
doublereal c_b33;
doublereal c_b34;
doublereal c_b35;
integer c__5;
integer c__7;
} et2lst_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b4;
doublereal c_b6;
integer c__10;
integer c__2;
integer c__1;
doublereal c_b32;
doublereal c_b33;
doublereal c_b34;
doublereal c_b35;
integer c__5;
integer c__7;
} et2lst_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char mthnam[3*12];
/* Table of constant values */

integer c__0;
doublereal c_b22;
integer c__1;
} et2utc_init_t;

typedef struct {
char mthnam[3*12];
/* Table of constant values */

integer c__0;
doublereal c_b22;
integer c__1;
integer bday;
integer eday;
integer year;
doublereal tvec[8];
integer hour;
integer i__;
doublereal scale;
char fract[80];
integer month;
doublereal frcsec;
integer second;
doublereal whlsec;
integer bmonth;
integer emonth;
char endstr[80];
integer myprec;
integer minute;
integer bsc;
integer esc;
integer bhr;
integer bmn;
doublereal tai;
integer day;
integer ehr;
integer emn;
char fmt[4];
char str[80];

} et2utc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
integer extra[12];
integer dpjan0[12];
integer dpbegl[12];
char months[3*12];
/* Table of constant values */

integer c__2000;
integer c__1;
integer c__12;
integer c__6;
} etcal_init_t;

typedef struct {
logical first;
integer extra[12];
integer dpjan0[12];
integer dpbegl[12];
char months[3*12];
/* Table of constant values */

integer c__2000;
integer c__1;
integer c__12;
integer c__6;
integer dn2000;
doublereal dp2000;
doublereal frac;
char date[180];
doublereal remd;
doublereal secs;
integer year;
integer mins;
char dstr[16];
char hstr[16];
char mstr[16];
char sstr[16];
char ystr[16];
doublereal halfd;
doublereal q;
integer tsecs;
integer dofyr;
integer month;
integer hours;
doublereal mynum;
integer bh;
integer bm;
integer iq;
doublereal secspd;
char messge[16];
integer offset;
doublereal dmnint;
logical adjust;
integer daynum;
doublereal dmxint;
doublereal mydnom;
integer yr1;
integer yr4;
char era[16];
integer day;
integer rem;
integer yr100;
integer yr400;

} etcal_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical doinit;
/* Table of constant values */

doublereal c_b91;
doublereal c_b92;
doublereal c_b153;
integer c__20;
} ev2lin_init_t;

typedef struct {
logical doinit;
/* Table of constant values */

doublereal c_b91;
doublereal c_b92;
doublereal c_b153;
integer c__20;
integer head;
doublereal coef;
doublereal eeta;
doublereal delm;
doublereal aodp;
doublereal delo;
doublereal capu;
doublereal xmdf;
doublereal aynl;
doublereal elsq;
doublereal temp;
integer last;
doublereal rdot;
doublereal cosu;
doublereal tokm;
integer list[12]	/* was [2][6] */;
doublereal sinu;
doublereal coef1;
doublereal t2cof;
doublereal t3cof;
doublereal t4cof;
doublereal t5cof;
doublereal temp1;
doublereal temp2;
doublereal temp3;
doublereal temp4;
doublereal temp5;
doublereal cos2u;
doublereal temp6;
doublereal mov1m;
doublereal sin2u;
doublereal a;
doublereal e;
doublereal f;
integer i__;
integer j;
doublereal m;
integer n;
doublereal r__;
doublereal s;
doublereal u;
doublereal betal;
doublereal omega;
doublereal betao;
doublereal epoch;
doublereal ecose;
doublereal aycof;
doublereal delmo;
doublereal esine;
doublereal a3ovk2;
doublereal tcube;
doublereal cosik;
doublereal tempa;
doublereal bstar;
doublereal cosio;
doublereal xincl;
doublereal etasq;
doublereal rfdot;
doublereal sinik;
doublereal a1;
doublereal rdotk;
doublereal c1;
doublereal c2;
doublereal c3;
doublereal c4;
doublereal c5;
doublereal cosuk;
doublereal d2;
doublereal d3;
doublereal j2;
doublereal j3;
doublereal j4;
doublereal qomso;
doublereal d4;
doublereal lower;
doublereal q1;
doublereal q2;
doublereal psisq;
doublereal qoms24;
doublereal s4;
doublereal sinio;
doublereal sinmo;
doublereal sinuk;
doublereal tempe;
doublereal betao2;
doublereal betao3;
doublereal betao4;
doublereal templ;
doublereal tfour;
doublereal upper;
doublereal x1m5th;
doublereal x1mth2;
doublereal x3thm1;
doublereal x7thm1;
doublereal fmod2p;
doublereal theta2;
doublereal theta4;
doublereal xinck;
doublereal xlcof;
doublereal xmcof;
doublereal xmdot;
doublereal xnode;
doublereal xnodp;
integer count;
doublereal xndd6o;
integer after;
logical recog;
logical unrec;
doublereal ae;
doublereal xhdot1;
doublereal xndt2o;
doublereal ke;
doublereal ao;
doublereal fl;
doublereal eo;
doublereal qoms2t;
doublereal er;
doublereal fu;
doublereal pl;
doublereal omgadf;
doublereal rk;
doublereal qo;
doublereal uk;
doublereal so;
doublereal xl;
integer before;
doublereal xn;
doublereal omegao;
doublereal delomg;
doublereal omgcof;
doublereal perige;
doublereal ux;
doublereal uy;
doublereal uz;
doublereal fprime;
doublereal elemnt[60]	/* was [10][6] */;
doublereal tsince;
doublereal ae2;
doublereal ae3;
doublereal ae4;
doublereal epsiln;
doublereal xnodeo;
doublereal cosnok;
doublereal lstgeo[8];
doublereal omgdot;
doublereal ck2;
doublereal cosepw;
doublereal ck4;
doublereal prelim[174]	/* was [29][6] */;
doublereal rfdotk;
doublereal sinepw;
doublereal sinnok;
doublereal vx;
doublereal tokmps;
doublereal vy;
doublereal pinvsq;
doublereal vz;
doublereal xnodcf;
doublereal xnoddf;
doublereal xnodek;
doublereal epwnxt;
doublereal xnodot;
logical newgeo;
doublereal eta;
doublereal axn;
doublereal ayn;
doublereal epw;
doublereal est;
doublereal tsi;
doublereal xll;
doublereal xmo;
doublereal xno;
doublereal xmp;
doublereal tsq;
doublereal xlt;
doublereal xmx;
doublereal xmy;
doublereal del1;
doublereal c1sq;
doublereal pix2;

} ev2lin_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__0;
} excess_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__0;
} excess_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer last;
logical first;
integer resnum[3];
} fndlun_init_t;

typedef struct {
integer last;
logical first;
integer resnum[3];
integer i__;
logical resvd[99];
logical opened;
integer iostat;

} fndlun_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal raydir[3];
} fovtrg_init_t;

typedef struct {
doublereal raydir[3];
} fovtrg_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__5209;
integer c__127;
integer c__0;
integer c__1;
integer c__8;
integer c__100;
} framex_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__5209;
integer c__127;
integer c__0;
integer c__1;
integer c__8;
integer c__100;
char name__[32*127];
char line[80*8];
integer item;
logical lnew;
integer type__[127];
char look2[32];
integer i__;
integer n;
char kname[32*5209];
char pname[32];
integer kcent[5209];
logical gotit;
integer start;
integer id;
integer idcode[127];
integer bidids[127];
char lcname[36];
integer bididx[127];
char lcfram[32];
integer kidids[5209];
integer kclsid[5209];
integer kvclid;
integer bidpol[133];
integer centrd[127];
integer center[127];
char kvbuff[32*100];
integer kidpol[5215];
integer knmids[5209];
integer kclass[5209];
integer kidlst[5209];
integer bnmpol[133];
integer typeid[127];
integer values[8];
integer knmpol[5215];
logical lupdte;
char knmnms[32*5209];
char dattyp[1];
char lookup[32];
integer kvclss;
integer pulctr[2];
integer knmlst[5209];
integer bnmlst[127];
char bnmnms[32*127];
integer bnmidx[127];
integer bidlst[127];
logical fnd;

} framex_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
} frmchg_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
} frmchg_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__36;
integer c__1;
} frmget_init_t;

typedef struct {
/* Table of constant values */

integer c__36;
integer c__1;
} frmget_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b11;
} georec_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b11;
} georec_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___14;
/* Table of constant values */

logical c_false;
integer c__1;
} getfat_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___14;
/* Table of constant values */

logical c_false;
integer c__1;
} getfat_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char shapid[32*4];
char angshp[32*3];
/* Table of constant values */

integer c__1;
integer c__4;
integer c__3;
integer c__0;
} getfov_init_t;

typedef struct {
char shapid[32*4];
char angshp[32*3];
/* Table of constant values */

integer c__1;
integer c__4;
integer c__3;
integer c__0;
} getfov_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
} getmsg_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
} getmsg_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__5;
integer c_n1;
integer c__3;
integer c__0;
logical c_false;
} gfdist_init_t;

typedef struct {
/* Table of constant values */

integer c__5;
integer c_n1;
integer c__3;
integer c__0;
logical c_false;
} gfdist_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char dref[80];
logical first;
char qnames[80*8];
char cnames[80*7];
char qpars[80*10*8];
/* Table of constant values */

integer c__8;
integer c__10;
integer c__7;
} gfevnt_init_t;

typedef struct {
char dref[80];
logical first;
char qnames[80*8];
char cnames[80*7];
char qpars[80*10*8];
/* Table of constant values */

integer c__8;
integer c__10;
integer c__7;
char srcpre[55*2*8];
char srcsuf[13*2*8];
} gfevnt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__5;
integer c__3;
integer c_n1;
integer c__0;
integer c__8;
logical c_false;
} gfilum_init_t;

typedef struct {
/* Table of constant values */

integer c__5;
integer c__3;
integer c_n1;
integer c__0;
integer c__8;
logical c_false;
} gfilum_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
logical c_false;
doublereal c_b21;
} gfocce_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
logical c_false;
doublereal c_b21;
} gfocce_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c_n1;
integer c__3;
logical c_false;
} gfoclt_init_t;

typedef struct {
/* Table of constant values */

integer c_n1;
integer c__3;
logical c_false;
} gfoclt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__5;
integer c_n1;
integer c__3;
integer c__0;
integer c__4;
logical c_false;
} gfpa_init_t;

typedef struct {
/* Table of constant values */

integer c__5;
integer c_n1;
integer c__3;
integer c__0;
integer c__4;
logical c_false;
} gfpa_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal dvec[3];
char dref[80];
/* Table of constant values */

integer c_n1;
integer c__3;
integer c__0;
integer c__10;
logical c_false;
} gfposc_init_t;

typedef struct {
doublereal dvec[3];
char dref[80];
/* Table of constant values */

integer c_n1;
integer c__3;
integer c__0;
integer c__10;
logical c_false;
} gfposc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c_n1;
integer c__3;
logical c_false;
} gfrfov_init_t;

typedef struct {
/* Table of constant values */

integer c_n1;
integer c__3;
logical c_false;
} gfrfov_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__55;
integer c__13;
doublereal c_b26;
integer c__4;
doublereal c_b44;
integer c__1;
} gfrprt_init_t;

typedef struct {
/* Table of constant values */

integer c__55;
integer c__13;
doublereal c_b26;
integer c__4;
doublereal c_b44;
integer c__1;
char copyb[55];
char copye[13];
doublereal t0;
doublereal remain;
} gfrprt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__5;
integer c_n1;
integer c__3;
integer c__0;
logical c_false;
} gfrr_init_t;

typedef struct {
/* Table of constant values */

integer c__5;
integer c_n1;
integer c__3;
integer c__0;
logical c_false;
} gfrr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__5;
integer c_n1;
integer c__3;
integer c__0;
integer c__8;
logical c_false;
} gfsep_init_t;

typedef struct {
/* Table of constant values */

integer c__5;
integer c_n1;
integer c__3;
integer c__0;
integer c__8;
logical c_false;
} gfsep_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c_n1;
integer c__3;
integer c__0;
integer c__10;
logical c_false;
} gfsntc_init_t;

typedef struct {
/* Table of constant values */

integer c_n1;
integer c__3;
integer c__0;
integer c__10;
logical c_false;
} gfsntc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical svinit;
doublereal svstep;
} gfstep_init_t;

typedef struct {
logical svinit;
doublereal svstep;
} gfstep_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c_n2;
integer c__3;
} gfstol_init_t;

typedef struct {
/* Table of constant values */

integer c_n2;
integer c__3;
} gfstol_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal dvec[3];
char dref[80];
/* Table of constant values */

integer c_n1;
integer c__3;
integer c__0;
integer c__10;
logical c_false;
} gfsubc_init_t;

typedef struct {
doublereal dvec[3];
char dref[80];
/* Table of constant values */

integer c_n1;
integer c__3;
integer c__0;
integer c__10;
logical c_false;
} gfsubc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal raydir[3];
/* Table of constant values */

integer c_n1;
integer c__3;
logical c_false;
} gftfov_init_t;

typedef struct {
doublereal raydir[3];
/* Table of constant values */

integer c_n1;
integer c__3;
logical c_false;
} gftfov_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c_n1;
integer c__3;
integer c__0;
logical c_false;
} gfudb_init_t;

typedef struct {
/* Table of constant values */

integer c_n1;
integer c__3;
integer c__0;
logical c_false;
} gfudb_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__5;
integer c_n1;
integer c__3;
integer c__0;
logical c_false;
} gfuds_init_t;

typedef struct {
/* Table of constant values */

integer c__5;
integer c_n1;
integer c__3;
integer c__0;
logical c_false;
} gfuds_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal value;
} halfpi_init_t;

typedef struct {
doublereal value;
} halfpi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal dpval[16];
logical first;
} hx2dp_init_t;

typedef struct {
doublereal dpval[16];
logical first;
doublereal mindp;
doublereal maxdp;
integer iplus;
integer lccbeg;
integer digbeg;
integer lccend;
integer uccbeg;
integer digend;
integer uccend;
integer ispace;
doublereal scales[31];
integer iexpch;
integer iminus;
} hx2dp_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} hx2int_init_t;

typedef struct {
logical first;
integer mini;
integer maxi;
integer iplus;
integer lccbeg;
integer digbeg;
integer lccend;
integer uccbeg;
integer digend;
integer uccend;
integer ispace;
integer minmod;
integer maxmod;
integer iminus;
} hx2int_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} hyptof_init_t;

typedef struct {
logical first;
doublereal maxlog;
} hyptof_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} idw2at_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} idw2at_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__10;
integer c__3;
} illum_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__10;
integer c__3;
logical svfnd1;
logical svfnd2;
integer svctr1[2];
integer svctr2[2];
integer svtcde;
integer svobsc;
char svtarg[36];
char svobsr[36];
} illum_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
logical pri;
integer nsurf;
char prvcor[5];
char prvmth[500];
integer shape;
/* Table of constant values */

integer c__100;
integer c__3;
doublereal c_b56;
} illumf_init_t;

typedef struct {
logical first;
logical pri;
integer nsurf;
char prvcor[5];
char prvmth[500];
integer shape;
/* Table of constant values */

integer c__100;
integer c__3;
doublereal c_b56;
logical xmit;
logical uselt;
logical svfnd1;
logical svfnd2;
integer svctr1[2];
integer svctr2[2];
integer svctr3[2];
integer svctr4[2];
integer trgcde;
integer center;
integer srflst[100];
char svtarg[36];
integer svtcde;
char svobsr[36];
integer svobsc;
char svfref[32];
integer svrefc;
} illumf_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer shape;
logical first;
char prvcor[5];
char prvmth[80];
/* Table of constant values */

integer c__100;
integer c__3;
} illumg_init_t;

typedef struct {
integer shape;
logical first;
char prvcor[5];
char prvmth[80];
/* Table of constant values */

integer c__100;
integer c__3;
logical xmit;
integer nsurf;
logical uselt;
logical svfnd1;
logical svfnd2;
integer svctr1[2];
integer svctr2[2];
integer svctr3[2];
integer svctr4[2];
integer trgcde;
integer center;
integer srflst[100];
char svtarg[36];
integer svtcde;
char svobsr[36];
integer svobsc;
char svfref[32];
integer svrefc;
logical pri;

} illumg_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal origin[3];
doublereal y[3];
doublereal z__[3];
} incnsg_init_t;

typedef struct {
doublereal origin[3];
doublereal y[3];
doublereal z__[3];
} incnsg_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b32;
doublereal c_b33;
} inedpl_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b32;
doublereal c_b33;
} inedpl_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
doublereal c_b26;
} inelpl_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
doublereal c_b26;
} inelpl_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
doublereal c_b16;
} inrypl_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
doublereal c_b16;
} inrypl_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char digits[1*16];
} int2hx_init_t;

typedef struct {
char digits[1*16];
} int2hx_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} intord_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} intord_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char digits[1*10];
} intstr_init_t;

typedef struct {
char digits[1*10];
} intstr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char tens[9*9];
char number[9*19];
/* Table of constant values */

integer c__1;
integer c__0;
} inttxt_init_t;

typedef struct {
char tens[9*9];
char number[9*19];
/* Table of constant values */

integer c__1;
integer c__0;
} inttxt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b2;
integer c__9;
} invert_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b2;
integer c__9;
} invert_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} invort_init_t;

typedef struct {
logical first;
doublereal bound;
} invort_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__6;
integer c__3;
} invstm_init_t;

typedef struct {
/* Table of constant values */

integer c__6;
integer c__3;
} invstm_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__0;
integer c__2;
} ioerr_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__0;
integer c__2;
} ioerr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char months[3*13];
char imonth[2*12];
/* Table of constant values */

integer c__1;
integer c__2;
integer c__3;
integer c__4;
integer c__5;
integer c__6;
integer c__7;
integer c__8;
integer c__9;
integer c__10;
integer c__12;
integer c__11;
integer c__13;
integer c__14;
integer c__15;
integer c__16;
integer c__17;
integer c__18;
integer c__19;
} iso2utc_init_t;

typedef struct {
char months[3*13];
char imonth[2*12];
/* Table of constant values */

integer c__1;
integer c__2;
integer c__3;
integer c__4;
integer c__5;
integer c__6;
integer c__7;
integer c__8;
integer c__9;
integer c__10;
integer c__12;
integer c__11;
integer c__13;
integer c__14;
integer c__15;
integer c__16;
integer c__17;
integer c__18;
integer c__19;
} iso2utc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
integer extra[12];
integer dpjan0[12];
integer dpbegl[12];
/* Table of constant values */

integer c__1582;
integer c__10;
integer c__15;
integer c__4;
integer c__100;
integer c__400;
integer c__5;
integer c__12;
integer c_b27;
integer c__1461;
} jul2gr_init_t;

typedef struct {
logical first;
integer extra[12];
integer dpjan0[12];
integer dpbegl[12];
/* Table of constant values */

integer c__1582;
integer c__10;
integer c__15;
integer c__4;
integer c__100;
integer c__400;
integer c__5;
integer c__12;
integer c_b27;
integer c__1461;
integer dayg;
integer dayj;
integer m;
integer rdayg;
integer rdayj;
integer dofyr;
integer yroff;
integer m4;
integer tmpyr;
integer dy;
integer yr;
integer offset;
integer offstg;
integer offstj;
integer m100;
integer tmpday;
integer m400;
integer mon;

} jul2gr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
integer loaded;
/* Table of constant values */

integer c__3;
integer c__255;
integer c__5300;
integer c__1;
} keeper_init_t;

typedef struct {
logical first;
integer loaded;
/* Table of constant values */

integer c__3;
integer c__255;
integer c__5300;
integer c__1;
char files[255*5300];
integer srces[5300];
char known[32*3];
char types[8*5300];
integer handls[5300];
} keeper_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
integer c__1;
integer c__100;
} kplfrm_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
integer c__1;
integer c__100;
} kplfrm_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char prvmth[500];
integer svprvt;
/* Table of constant values */

integer c__100;
integer c__3;
doublereal c_b43;
} latsrf_init_t;

typedef struct {
logical first;
char prvmth[500];
integer svprvt;
/* Table of constant values */

integer c__100;
integer c__3;
doublereal c_b43;
integer shape;
integer nsurf;
logical svfnd1;
integer svctr1[2];
integer svctr2[2];
integer svctr3[2];
integer srfctr[2];
integer srflst[100];
char svtarg[36];
integer svtcde;
char svfref[32];
integer svfxfc;
doublereal svradi[3];
logical pri;

} latsrf_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} lbuild_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} lbuild_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} lcase_init_t;

typedef struct {
logical first;
integer shift;
integer uppera;
integer upperz;
} lcase_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char prvcor[5];
char prvloc[25];
char prvmth[500];
integer prvtrg;
integer svnrad;
logical usecn;
logical uselt;
logical usestl;
/* Table of constant values */

integer c__100;
integer c__1;
integer c__3;
integer c__2000;
doublereal c_b121;
integer c__0;
doublereal c_b124;
doublereal c_b129;
} limbpt_init_t;

typedef struct {
logical first;
char prvcor[5];
char prvloc[25];
char prvmth[500];
integer prvtrg;
integer svnrad;
logical usecn;
logical uselt;
logical usestl;
/* Table of constant values */

integer c__100;
integer c__1;
integer c__3;
integer c__2000;
doublereal c_b121;
integer c__0;
doublereal c_b124;
doublereal c_b129;
integer shape;
integer nsurf;
logical svfnd1;
logical svfnd2;
integer svctr1[2];
integer svctr2[2];
integer svctr3[2];
integer svctr4[2];
integer svctr5[2];
integer loccde;
char subtyp[20];
doublereal pntbuf[6000]	/* was [3][2000] */;
integer lmbtyp;
integer srflst[100];
logical pri;
char svtarg[36];
integer svtcde;
char svobsr[36];
integer svobsc;
char svfref[32];
integer svfxfc;
doublereal svradi[3];
} limbpt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} ljucrs_init_t;

typedef struct {
logical first;
integer lowa;
integer lowz;
integer shift;
} ljucrs_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} lnkfsl_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} lnkfsl_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} lnkhl_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} lnkhl_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} lnkila_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} lnkila_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} lnkilb_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} lnkilb_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} lnknxt_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} lnknxt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} lnkprv_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} lnkprv_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} lnktl_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} lnktl_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} lnkxsl_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} lnkxsl_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} locln_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} locln_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} lparss_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} lparss_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__10;
integer c__3;
integer c__2;
} lspcn_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__10;
integer c__3;
integer c__2;
logical svfnd1;
integer svctr1[2];
integer svidcd;
char svbody[36];
} lspcn_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical doinit;
} lx4uns_init_t;

typedef struct {
logical doinit;
integer i__;
integer l;
logical digit[384];

} lx4uns_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__255;
integer c__0;
} lxname_init_t;

typedef struct {
/* Table of constant values */

integer c__255;
integer c__0;
} lxname_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer next[3];
/* Table of constant values */

doublereal c_b15;
integer c__9;
} m2eul_init_t;

typedef struct {
integer next[3];
/* Table of constant values */

doublereal c_b15;
integer c__9;
} m2eul_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b2;
} m2q_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b2;
} m2q_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} matchi_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} matchi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} matchw_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} matchw_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__9;
} mequ_init_t;

typedef struct {
/* Table of constant values */

integer c__9;
} mequ_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__9;
} mtxm_init_t;

typedef struct {
/* Table of constant values */

integer c__9;
} mtxm_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__9;
} mxm_init_t;

typedef struct {
/* Table of constant values */

integer c__9;
} mxm_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__9;
} mxmt_init_t;

typedef struct {
/* Table of constant values */

integer c__9;
} mxmt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char mssg[80*7];
/* Table of constant values */

integer c__3;
doublereal c_b36;
integer c__2048;
doublereal c_b108;
} nearpt_init_t;

typedef struct {
char mssg[80*7];
/* Table of constant values */

integer c__3;
doublereal c_b36;
integer c__2048;
doublereal c_b108;
} nearpt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal lookup[11];
logical first;
doublereal values[128];
integer class__[129];
/* Table of constant values */

integer c__1;
} nparsd_init_t;

typedef struct {
doublereal lookup[11];
logical first;
doublereal values[128];
integer class__[129];
/* Table of constant values */

integer c__1;
doublereal next;
integer b;
integer i__;
integer l;
integer m;
logical dodec;
integer blank;
logical bpiok;
logical epiok;
doublereal value;
logical doint;
logical doexp;
integer thisi;
logical expok;
integer nexti;
logical zeroi;
logical pntok;
integer id;
integer nl;
doublereal decval;
doublereal factor;
doublereal intbnd;
doublereal smlbnd;
logical sigchr;
char toobig[160];
doublereal dpsign[2];
logical mantsa;
logical signok;
logical roundd;
integer signdx;
char blnkst[160];
doublereal ecount;
doublereal divisr;
doublereal expval;
doublereal intval;
doublereal maxexp;
char unxpch[160];
doublereal minexp;
logical roundi;
char unrcst[160];
char unxpsn[160];
char unxppt[160];
integer exp__;

} nparsd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} nparsi_init_t;

typedef struct {
logical first;
doublereal xmnint;
doublereal xmxint;

} nparsi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b12;
doublereal c_b26;
} npedln_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b12;
doublereal c_b26;
} npedln_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__2;
doublereal c_b10;
doublereal c_b11;
doublereal c_b12;
} npelpt_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__2;
doublereal c_b10;
doublereal c_b11;
doublereal c_b12;
} npelpt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char occtyp[9*3];
/* Table of constant values */

integer c__100;
} occult_init_t;

typedef struct {
char occtyp[9*3];
/* Table of constant values */

integer c__100;
} occult_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal zvec[3];
/* Table of constant values */

doublereal c_b16;
doublereal c_b17;
doublereal c_b18;
} oscelt_init_t;

typedef struct {
doublereal zvec[3];
/* Table of constant values */

doublereal c_b16;
doublereal c_b17;
doublereal c_b18;
} oscelt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical pass1;
doublereal limit;
/* Table of constant values */

integer c__12;
doublereal c_b5;
doublereal c_b6;
integer c__1;
integer c__3;
doublereal c_b13;
doublereal c_b14;
doublereal c_b15;
} oscltx_init_t;

typedef struct {
logical pass1;
doublereal limit;
/* Table of constant values */

integer c__12;
doublereal c_b5;
doublereal c_b6;
integer c__1;
integer c__3;
doublereal c_b13;
doublereal c_b14;
doublereal c_b15;
} oscltx_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char defmsg[80*4];
logical first;
/* Table of constant values */

integer c__5;
integer c__2;
integer c__3;
integer c__0;
integer c__1;
} outmsg_init_t;

typedef struct {
char defmsg[80*4];
logical first;
/* Table of constant values */

integer c__5;
integer c__2;
integer c__3;
integer c__0;
integer c__1;
char border[80];
} outmsg_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
} pck03b_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
} pck03b_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer nft;
integer nbt;
integer next;
/* Table of constant values */

integer c__5000;
integer c__5;
integer c__2;
} pckbsr_init_t;

typedef struct {
integer nft;
integer nbt;
integer next;
/* Table of constant values */

integer c__5000;
integer c__5;
integer c__2;
doublereal btlb[20];
doublereal btub[20];
integer btbeg[20];
integer btbod[20];
integer fthan[5000];
integer bthfs[20];
integer btlfs[20];
integer sthan[5000];
integer btexp[20];
doublereal stdes[25000]	/* was [5][5000] */;
integer ftnum[5000];
logical btchkp[20];
doublereal btprvd[100]	/* was [5][20] */;
integer btprvh[20];
char btprvi[40*20];
char stidnt[40*5000];
integer btruex[20];
integer stpool[10012]	/* was [2][5006] */;
} pckbsr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} pckcov_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} pckcov_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
} pcke03_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
} pcke03_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__5;
} pckeul_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__5;
} pckeul_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} pckfrm_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} pckfrm_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__5;
integer c__3;
integer c__1;
integer c__130;
} pckmat_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__5;
integer c__3;
integer c__1;
integer c__130;
} pckmat_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__5;
} pckopn_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__5;
} pckopn_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__5;
} pckpds_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__5;
} pckpds_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__5;
} pckr02_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__5;
} pckr02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} pckr03_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} pckr03_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__1;
integer c__3;
} pckr20_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__1;
integer c__3;
} pckr20_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__5;
} pckuds_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__5;
} pckuds_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__40;
integer c__2;
integer c__5;
integer c__1;
} pckw02_init_t;

typedef struct {
/* Table of constant values */

integer c__40;
integer c__2;
integer c__5;
integer c__1;
} pckw02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__50;
integer c__40;
integer c__2;
integer c__5;
integer c__1;
} pckw20_init_t;

typedef struct {
/* Table of constant values */

integer c__50;
integer c__40;
integer c__2;
integer c__5;
integer c__1;
} pckw20_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__1;
integer c__0;
} pgrrec_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__1;
integer c__0;
logical svfnd1;
integer svctr1[2];
integer svbdid;
char svbody[36];
} pgrrec_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__0;
} phaseq_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__0;
logical svfnd1;
logical svfnd2;
logical svfnd3;
integer svctr1[2];
integer svctr2[2];
integer svctr3[2];
integer svicde;
integer svtgid;
char svtarg[36];
char svilmn[36];
integer svobsn;
char svobsr[36];
} phaseq_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal value;
} pi_init_t;

typedef struct {
doublereal value;
} pi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__1;
} plnsns_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__1;
} plnsns_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__26003;
integer c_b8;
integer c__15000;
integer c__1000;
integer c_b11;
integer c__1;
integer c__32;
} pool_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__26003;
integer c_b8;
integer c__15000;
integer c__1000;
integer c_b11;
integer c__1;
integer c__32;
integer head;
integer code;
integer need;
integer free;
integer node;
char line[132];
integer tail;
integer hits;
integer i__;
integer j;
integer k;
integer r__;
integer begin;
integer dnode;
integer space;
integer avail;
integer nnode;
doublereal small;
logical gotit;
integer nvars__;
integer nptrs;
integer datahd;
char begdat[10];
logical dp;
integer agnode;
integer chnode;
integer nameat;
integer nfetch;
integer nw;
integer dpnode;
char active[32*130021];
integer margin;
char cvalue[132];
char pnames[32*26003];
char begtxt[10];
integer namlst[26003];
integer datlst[26003];
integer nmpool[52018]	/* was [2][26009] */;
integer chpool[30012]	/* was [2][15006] */;
integer dppool[800012]	/* was [2][400006] */;
char chvals[80*15000];
doublereal dpvals[400000];
char wtagnt[32*130015];
char agents[32*130021];
integer wtpool[260042]	/* was [2][130021] */;
char wtvars[32*26009];
char notify[32*130021];
integer subctr[2];
char finish[2];
char varnam[32];
doublereal dvalue;
integer iostat;
integer iquote;
integer linnum;
integer lookat;
integer nnodes;
integer tofree;
integer wtptrs[26003];
integer varlen;
logical noagnt;
logical succes;
logical vector;
doublereal big;
logical eof;
logical chr;
} pool_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} prompt_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} prompt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer nsaved;
integer newest[3];
/* Table of constant values */

integer c__1;
integer c__3;
integer c__6;
} prop2b_init_t;

typedef struct {
integer nsaved;
integer newest[3];
/* Table of constant values */

integer c__1;
integer c__3;
integer c__6;
doublereal hvec[3];
doublereal logf;
doublereal maxc;
doublereal kfun;
doublereal oldx;
doublereal sb2rv[3];
doublereal b;
doublereal e;
doublereal f;
doublereal qovr0;
integer i__;
integer k;
doublereal q;
doublereal x;
doublereal fixed;
doublereal eqvec[3];
doublereal bound;
doublereal pcdot;
doublereal kfunl;
doublereal vcdot;
doublereal c0;
doublereal c1;
doublereal c2;
doublereal c3;
integer mostc;
doublereal kfunu;
doublereal lower;
doublereal h2;
doublereal upper;
doublereal rootf;
doublereal r0;
doublereal x2;
doublereal x3;
doublereal bq;
doublereal br;
doublereal pc;
doublereal vc;
doublereal sf[3];
doublereal sqovr0[3];
doublereal logbnd;
doublereal rv;
integer bumped;
doublereal savegm[3];
doublereal logdpm;
doublereal logmxc;
doublereal sbound[3];
doublereal tmpvec[3];
doublereal br0;
doublereal savepv[18]	/* was [6][3] */;
integer lcount;
doublereal fx2;
doublereal sbq[3];
doublereal vel[3];
logical new__;
doublereal pos[3];
doublereal sbr0[3];
doublereal b2rv;

} prop2b_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical svshrt;
logical svexpl;
logical svlong;
logical svtrac;
logical svdflt;
/* Table of constant values */

integer c__2;
} prtpkg_init_t;

typedef struct {
logical svshrt;
logical svexpl;
logical svlong;
logical svtrac;
logical svdflt;
/* Table of constant values */

integer c__2;
} prtpkg_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer savact;
} putact_init_t;

typedef struct {
integer savact;
} putact_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char savdev[255];
} putdev_init_t;

typedef struct {
char savdev[255];
} putdev_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char savmsg[1840];
} putlms_init_t;

typedef struct {
char savmsg[1840];
} putlms_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char savmsg[25];
} putsms_init_t;

typedef struct {
char savmsg[25];
} putsms_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} pxform_init_t;

typedef struct {
logical first;
char svto[32];
integer svctr1[2];
integer svctr2[2];
integer svfcod;
integer svtcde;
char svfrom[32];
} pxform_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__1;
} pxfrm2_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__1;
char svto[32];
integer svctr1[2];
integer svctr2[2];
integer svfcod;
integer svtcde;
char svfrom[32];
} pxfrm2_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__4;
doublereal c_b3;
} qdq2av_init_t;

typedef struct {
/* Table of constant values */

integer c__4;
doublereal c_b3;
} qdq2av_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__0;
} quote_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__0;
} quote_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b2;
} qxq_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b2;
} qxq_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___11;
/* Table of constant values */

integer c__9;
integer c__1;
} rdencc_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___11;
/* Table of constant values */

integer c__9;
integer c__1;
} rdencc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___4;
/* Table of constant values */

integer c__9;
integer c__1;
} rdencd_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___4;
/* Table of constant values */

integer c__9;
integer c__1;
} rdencd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___4;
/* Table of constant values */

integer c__9;
integer c__1;
} rdenci_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___4;
/* Table of constant values */

integer c__9;
integer c__1;
} rdenci_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical frstim;
char file[255];
integer linnum;
} rdker_init_t;

typedef struct {
logical frstim;
char file[255];
integer linnum;
integer i__;
integer r__;
char first[80];
char begdat[10];
char begtxt[10];
integer status;
logical end;

} rdker_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
} rdkvar_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
} rdkvar_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer n;
char lstfil[255];
/* Table of constant values */

integer c__1;
} rdtext_init_t;

typedef struct {
integer n;
char lstfil[255];
/* Table of constant values */

integer c__1;
integer index;
integer units[96];
integer lstunt;

} rdtext_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} readln_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} readln_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__1;
integer c__0;
doublereal c_b34;
} recpgr_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__1;
integer c__0;
doublereal c_b34;
logical svfnd1;
integer svctr1[2];
integer svbdid;
char svbody[36];
} recpgr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
} refchg_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
} refchg_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
} repsub_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
} repsub_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

logical c_false;
logical c_true;
} reset_init_t;

typedef struct {
/* Table of constant values */

logical c_false;
logical c_true;
} reset_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer indexs[5];
} rotate_init_t;

typedef struct {
integer indexs[5];
} rotate_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__9;
integer c__1;
} rotget_init_t;

typedef struct {
/* Table of constant values */

integer c__9;
integer c__1;
} rotget_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer indexs[5];
/* Table of constant values */

integer c__9;
} rotmat_init_t;

typedef struct {
integer indexs[5];
/* Table of constant values */

integer c__9;
} rotmat_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer indexs[5];
} rotvec_init_t;

typedef struct {
integer indexs[5];
} rotvec_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal value;
} rpd_init_t;

typedef struct {
doublereal value;
} rpd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
} rquad_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
} rquad_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
} saelgv_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
} saelgv_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char bvlmsg[320];
char del[1*5];
logical first;
char namlst[60*9];
logical nodata;
integer oldsc;
/* Table of constant values */

integer c__9;
integer c__0;
integer c__1;
integer c_b22;
integer c__9999;
integer c__10;
integer c__30;
} sc01_init_t;

typedef struct {
char bvlmsg[320];
char del[1*5];
logical first;
char namlst[60*9];
logical nodata;
integer oldsc;
/* Table of constant values */

integer c__9;
integer c__0;
integer c__1;
integer c_b22;
integer c__9999;
integer c__10;
integer c__30;
doublereal rate;
integer pntr;
integer i__;
integer j;
integer n;
doublereal prend[9999];
integer npart;
doublereal const__;
integer lower;
char error[240];
integer upper;
integer ntsys;
integer delcde;
integer needed;
integer middle;
integer ncoeff;
char dpchar[30];
integer nfield;
doublereal coeffs[150000]	/* was [3][50000] */;
doublereal tikdif;
char kvname[60*9];
doublereal cmpval[10];
doublereal moduli[10];
doublereal maxwid;
doublereal cmptks[10];
doublereal mxtick;
doublereal offset[10];
doublereal partim;
doublereal tikmsc;
doublereal timdif;
integer cmpwid[10];
integer length[10];
logical update;
integer usrctr[2];
integer timsys;
doublereal prstrt[9999];
integer pad;
integer end;
char cmp[30*10];
doublereal rem;

} sc01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__9999;
integer c__0;
} scdecd_init_t;

typedef struct {
/* Table of constant values */

integer c__9999;
integer c__0;
} scdecd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__9999;
} scencd_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__9999;
} scencd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char namlst[80*9];
integer lb[9];
char nfdmsg[320];
char nummsg[320];
char bvlmsg[320];
/* Table of constant values */

integer c__0;
integer c__1;
integer c__9;
integer c__14;
} sclu01_init_t;

typedef struct {
char namlst[80*9];
integer lb[9];
char nfdmsg[320];
char nummsg[320];
char bvlmsg[320];
/* Table of constant values */

integer c__0;
integer c__1;
integer c__9;
integer c__14;
} sclu01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__9999;
} scpars_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__9999;
} scpars_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
logical nodata;
integer oldsc;
/* Table of constant values */

integer c__0;
integer c__2;
integer c__9999;
} scpart_init_t;

typedef struct {
logical first;
logical nodata;
integer oldsc;
/* Table of constant values */

integer c__0;
integer c__2;
integer c__9999;
doublereal prtsa[9999];
doublereal prtso[9999];
integer usrctr[2];
integer lstprt;

} scpart_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char namlst[60*3];
/* Table of constant values */

integer c__10;
} scps01_init_t;

typedef struct {
char namlst[60*3];
/* Table of constant values */

integer c__10;
integer pntr;
integer i__;
integer n;
integer nfield;
doublereal cmpval[10];
doublereal moduli[10];
doublereal offset[10];
doublereal cmptks[10];
char strerr[240];
char cmp[30*10];

} scps01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} sctran_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} sctran_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
logical nodata;
integer oldsc;
/* Table of constant values */

integer c__0;
integer c__1;
} sctype_init_t;

typedef struct {
logical first;
logical nodata;
integer oldsc;
/* Table of constant values */

integer c__0;
integer c__1;
integer type__;
integer usrctr[2];
} sctype_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} sepool_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} sepool_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical svstat;
} seterr_init_t;

typedef struct {
logical svstat;
} seterr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__2;
} sgfcon_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__2;
} sgfcon_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__12;
integer c__10;
integer c__16;
integer c__15;
integer c__11;
integer c__8;
integer c__9;
} sgfpkt_init_t;

typedef struct {
/* Table of constant values */

integer c__12;
integer c__10;
integer c__16;
integer c__15;
integer c__11;
integer c__8;
integer c__9;
} sgfpkt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__6;
integer c__5;
integer c__7;
} sgfref_init_t;

typedef struct {
/* Table of constant values */

integer c__6;
integer c__5;
integer c__7;
} sgfref_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__12;
integer c__7;
integer c__5;
integer c__6;
integer c__0;
integer c__4;
integer c__3;
} sgfrvi_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__12;
integer c__7;
integer c__5;
integer c__6;
integer c__0;
integer c__4;
integer c__3;
} sgfrvi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer lstbeg;
integer lsthan;
doublereal equiv_0[2];
/* Table of constant values */

integer c__1;
integer c__2;
integer c__15;
} sgmeta_init_t;

typedef struct {
integer lstbeg;
integer lsthan;
doublereal equiv_0[2];
/* Table of constant values */

integer c__1;
integer c__2;
integer c__15;
integer meta[17];
logical nieven;
integer ioffst;
integer metasz;
} sgmeta_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer numfxd;
integer numvar;
integer nft;
/* Table of constant values */

integer c__0;
integer c__4;
integer c__1;
integer c__17;
} sgseqw_init_t;

typedef struct {
integer numfxd;
integer numvar;
integer nft;
/* Table of constant values */

integer c__0;
integer c__4;
integer c__1;
integer c__17;
integer fthan[20];
integer ftoff[20];
integer index;
integer ftbadr[20];
logical fxdseg;
integer lsthan;
doublereal ftrefs[40]	/* was [2][20] */;
integer ftncon[20];
logical explct;
integer ftnpkt[20];
integer ftnref[20];
integer ftnres[20];
integer ftityp[20];
integer ftpksz[20];
logical ftfixd[20];
logical ftexpl[20];
integer ftmxsz[20];
} sgseqw_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} sigdgt_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} sigdgt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char defmsg[40];
char errmsg[40];
/* Table of constant values */

logical c_true;
logical c_false;
} sigerr_init_t;

typedef struct {
char defmsg[40];
char errmsg[40];
/* Table of constant values */

logical c_true;
logical c_false;
logical stat;
integer action;
} sigerr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char prvcor[5];
char prvmth[500];
logical usecn;
logical uselt;
logical usestl;
logical xmit;
/* Table of constant values */

integer c__100;
} sincpt_init_t;

typedef struct {
logical first;
char prvcor[5];
char prvmth[500];
logical usecn;
logical uselt;
logical usestl;
logical xmit;
/* Table of constant values */

integer c__100;
integer shape;
integer nsurf;
logical svfnd1;
logical svfnd2;
integer svctr1[2];
integer svctr2[2];
integer svctr3[2];
integer svctr4[2];
integer svctr5[2];
integer srflst[100];
char svtarg[36];
integer svtcde;
char svobsr[36];
integer svobsc;
char svfref[32];
integer svfxfc;
char svdref[32];
integer svdfrc;
logical pri;
} sincpt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___24;
cilist io___33;
cilist io___34;
/* Table of constant values */

logical c_false;
integer c__1;
} spcac_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___24;
cilist io___33;
cilist io___34;
/* Table of constant values */

logical c_false;
integer c__1;
} spcac_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___2;
cilist io___4;
/* Table of constant values */

integer c__9;
integer c__1;
} spcb2t_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___2;
cilist io___4;
/* Table of constant values */

integer c__9;
integer c__1;
} spcb2t_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___16;
cilist io___18;
/* Table of constant values */

logical c_false;
integer c__1;
} spcec_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___16;
cilist io___18;
/* Table of constant values */

logical c_false;
integer c__1;
} spcec_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__0;
} spcopn_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__0;
} spcopn_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___16;
cilist io___21;
cilist io___24;
/* Table of constant values */

logical c_false;
integer c__1;
} spcrfl_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___16;
cilist io___21;
cilist io___24;
/* Table of constant values */

logical c_false;
integer c__1;
integer dafu;
integer free;
char temp[1000];
char null[1];
integer bward;
integer fward;
integer nd;
logical called;
integer ni;
char ifname[60];
integer hanbuf;
char record[1000];
logical eocsav;
integer tmplen;
integer iostat;
integer posnul;
integer rec;
integer bol;
integer eol;
char eot[1];
integer nrr;

} spcrfl_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
integer c__1;
} spct2b_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
integer c__1;
} spct2b_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b7;
doublereal c_b8;
} sphsd_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b7;
doublereal c_b8;
} sphsd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__14;
integer c__1;
integer c__3;
} spk14b_init_t;

typedef struct {
/* Table of constant values */

integer c__14;
integer c__1;
integer c__3;
} spk14b_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__3;
doublereal c_b13;
} spkacs_init_t;

typedef struct {
logical first;
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__3;
doublereal c_b13;
logical usestl;
} spkacs_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char flags[5*9];
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__9;
} spkapo_init_t;

typedef struct {
logical first;
char flags[5*9];
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__9;
logical xmit;
logical usecn;
logical uselt;
logical usestl;
} spkapo_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char flags[5*9];
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__9;
integer c__6;
} spkapp_init_t;

typedef struct {
logical first;
char flags[5*9];
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__9;
integer c__6;
logical xmit;
logical usecn;
logical uselt;
logical usestl;
} spkapp_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char prvcor[5];
} spkaps_init_t;

typedef struct {
logical first;
char prvcor[5];
logical xmit;
logical uselt;
logical usestl;

} spkaps_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer nft;
integer nbt;
integer next;
/* Table of constant values */

integer c_b8;
integer c__5000;
integer c__5;
integer c__2;
integer c__6;
} spkbsr_init_t;

typedef struct {
integer nft;
integer nbt;
integer next;
/* Table of constant values */

integer c_b8;
integer c__5000;
integer c__5;
integer c__2;
integer c__6;
doublereal btlb[200];
doublereal btub[200];
integer btbeg[200];
integer btbod[200];
integer fthan[5000];
integer bthfs[200];
integer btlfs[200];
integer sthan[100000];
integer btexp[200];
doublereal stdes[500000]	/* was [5][100000] */;
integer ftnum[5000];
logical btchkp[200];
doublereal btprvd[1000]	/* was [5][200] */;
char btprvi[40*200];
integer btprvh[200];
char stidnt[40*100000];
integer btruex[200];
integer stpool[200012]	/* was [2][100006] */;
} spkbsr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkcov_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkcov_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
} spkcpo_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
} spkcpo_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
} spkcpt_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
} spkcpt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char evlflg[25*3];
logical first;
char prvcor[5];
/* Table of constant values */

integer c__3;
integer c__6;
} spkcvo_init_t;

typedef struct {
char evlflg[25*3];
logical first;
char prvcor[5];
/* Table of constant values */

integer c__3;
integer c__6;
logical xmit;
logical uselt;
integer j2code;
logical svfnd1;
logical svfnd2;
integer svctr1[2];
integer svctr2[2];
integer svctr3[2];
integer svccde;
integer svtcde;
integer svorfc;
char svtarg[36];
char svoref[32];
char svoctr[36];
} spkcvo_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char evlflg[25*3];
logical first;
char prvcor[5];
/* Table of constant values */

integer c__3;
integer c__6;
} spkcvt_init_t;

typedef struct {
char evlflg[25*3];
logical first;
char prvcor[5];
/* Table of constant values */

integer c__3;
integer c__6;
logical xmit;
logical uselt;
integer j2code;
logical svfnd1;
logical svfnd2;
integer svctr1[2];
integer svctr2[2];
integer svctr3[2];
integer svccde;
integer svobsc;
integer svorfc;
char svoref[32];
char svobsr[36];
char svtctr[36];
} spkcvt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal fc[14];
/* Table of constant values */

integer c__1;
integer c__15;
integer c__45;
} spke01_init_t;

typedef struct {
doublereal fc[14];
/* Table of constant values */

integer c__1;
integer c__15;
integer c__45;
doublereal g[15];
integer i__;
integer j;
doublereal w[17];
doublereal delta;
integer kqmax1;
doublereal dt[45]	/* was [15][3] */;
doublereal wc[13];
integer kq[3];
integer ks;
doublereal tl;
integer jx;
doublereal tp;
doublereal refvel[3];
doublereal refpos[3];
integer mq2;
integer ks1;
integer kqq;
doublereal sum;

} spke01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__12;
integer c__6;
} spke05_init_t;

typedef struct {
/* Table of constant values */

integer c__12;
integer c__6;
} spke05_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal work[198];
/* Table of constant values */

integer c__6;
} spke08_init_t;

typedef struct {
doublereal work[198];
/* Table of constant values */

integer c__6;
doublereal locrec[198];
} spke08_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__6;
} spke09_init_t;

typedef struct {
/* Table of constant values */

integer c__6;
} spke09_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__1;
integer c__6;
} spke10_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__1;
integer c__6;
doublereal dwdt;
doublereal mypi;
doublereal my2pi;
doublereal w;
doublereal denom;
doublereal precm[36]	/* was [6][6] */;
doublereal vcomp[3];
doublereal numer;
doublereal s1[6];
doublereal s2[6];
doublereal t1;
doublereal t2;
doublereal dargdt;
doublereal invprc[36]	/* was [6][6] */;
doublereal tmpsta[6];
doublereal arg;
} spke10_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__6;
} spke15_init_t;

typedef struct {
/* Table of constant values */

integer c__6;
} spke15_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal fc[25];
/* Table of constant values */

integer c__25;
integer c__1;
} spke21_init_t;

typedef struct {
doublereal fc[25];
/* Table of constant values */

integer c__25;
integer c__1;
doublereal g[25];
integer i__;
integer j;
doublereal w[27];
doublereal delta;
integer kqmax1;
doublereal dt[75]	/* was [25][3] */;
doublereal wc[24];
integer kq[3];
integer ks;
doublereal tl;
integer jx;
doublereal tp;
integer maxdim;
doublereal refvel[3];
doublereal refpos[3];
integer mq2;
integer ks1;
integer kqq;
doublereal sum;

} spke21_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char prvcor[5];
/* Table of constant values */

integer c__6;
} spkez_init_t;

typedef struct {
logical first;
char prvcor[5];
/* Table of constant values */

integer c__6;
integer fj2000;
doublereal temp[6];
integer type__;
logical xmit;
integer i__;
logical found;
doublereal state[6];
char svref[32];
doublereal stobs[6];
doublereal xform[36]	/* was [6][6] */;
integer svctr1[2];
integer center;
logical attblk[15];
logical usegeo;
doublereal ltcent;
doublereal dltctr;
integer reqfrm;
integer ltsign;
integer typeid;
integer svreqf;
doublereal dlt;

} spkez_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} spkezp_init_t;

typedef struct {
logical first;
integer fj2000;
doublereal temp[3];
doublereal sobs[6];
integer type__;
logical xmit;
integer i__;
logical found;
char svref[32];
doublereal xform[9]	/* was [3][3] */;
doublereal postn[3];
integer svctr1[2];
integer center;
doublereal ltcent;
integer reqfrm;
integer typeid;
integer svreqf;
} spkezp_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} spkezr_init_t;

typedef struct {
logical first;
logical svfnd1;
logical svfnd2;
integer svctr1[2];
integer svctr2[2];
integer svtgid;
integer svobsi;
char svtarg[36];
char svobsn[36];
} spkezr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__6;
integer c__0;
} spkgeo_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__6;
integer c__0;
char svref[32];
integer svctr1[2];
integer svrefi;
} spkgeo_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__3;
integer c__6;
integer c__0;
} spkgps_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__3;
integer c__6;
integer c__0;
char svref[32];
integer svctr1[2];
integer svrefi;
} spkgps_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical pass1;
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__6;
doublereal c_b19;
} spkltc_init_t;

typedef struct {
logical pass1;
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__6;
doublereal c_b19;
logical xmit;
logical usecn;
logical uselt;
} spkltc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkobj_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkobj_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkopn_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkopn_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkpds_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkpds_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} spkpos_init_t;

typedef struct {
logical first;
logical svfnd1;
logical svfnd2;
integer svctr1[2];
integer svctr2[2];
integer svtgid;
integer svobsi;
char svtarg[36];
char svobsn[36];
} spkpos_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__2;
integer c__6;
} spkpv_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__2;
integer c__6;
char svref[32];
integer svctr1[2];
integer svirfr;
} spkpv_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__1;
integer c__198;
} spkpvn_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__1;
integer c__198;
} spkpvn_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__100;
} spkr01_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__100;
} spkr01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkr02_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkr02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkr03_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkr03_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__12;
} spkr05_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__12;
} spkr05_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkr08_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkr08_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkr09_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkr09_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__8;
integer c__7;
integer c__14;
} spkr10_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__8;
integer c__7;
integer c__14;
integer ends[2];
integer indx;
integer from;
integer i__;
logical found;
doublereal value;
integer to;
integer nepoch;
integer getelm;
integer putelm;
integer set1;
integer set2;

} spkr10_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} spkr14_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} spkr14_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkr15_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkr15_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__12;
} spkr17_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__12;
} spkr17_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkr18_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkr18_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer mxwnsz[3];
integer svminb;
integer svn;
integer svnpkt;
logical svok;
integer svpkdb;
integer svpknd;
integer svpksz;
integer svstyp;
integer svwnsz;
logical pass1;
integer pktszs[3];
integer svbeg;
doublereal svbtim;
doublereal svetim;
integer svhan;
logical svlast;
integer svmiix;
/* Table of constant values */

integer c__198;
integer c__2;
integer c__6;
} spkr19_init_t;

typedef struct {
integer mxwnsz[3];
integer svminb;
integer svn;
integer svnpkt;
logical svok;
integer svpkdb;
integer svpknd;
integer svpksz;
integer svstyp;
integer svwnsz;
logical pass1;
integer pktszs[3];
integer svbeg;
doublereal svbtim;
doublereal svetim;
integer svhan;
logical svlast;
integer svmiix;
/* Table of constant values */

integer c__198;
integer c__2;
integer c__6;
} spkr19_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__1;
integer c__3;
} spkr20_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__1;
integer c__3;
} spkr20_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__25;
integer c__100;
} spkr21_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__25;
integer c__100;
} spkr21_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__71;
integer c__1;
} spks01_init_t;

typedef struct {
/* Table of constant values */

integer c__71;
integer c__1;
} spks01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__4;
} spks02_init_t;

typedef struct {
/* Table of constant values */

integer c__4;
} spks02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__4;
} spks03_init_t;

typedef struct {
/* Table of constant values */

integer c__4;
} spks03_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__6;
integer c__1;
} spks05_init_t;

typedef struct {
/* Table of constant values */

integer c__6;
integer c__1;
} spks05_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__6;
integer c__1;
} spks08_init_t;

typedef struct {
/* Table of constant values */

integer c__6;
integer c__1;
} spks08_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__6;
integer c__1;
} spks09_init_t;

typedef struct {
/* Table of constant values */

integer c__6;
integer c__1;
} spks09_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__1;
integer c__8;
integer c__14;
integer c__4;
integer c__7;
} spks10_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__1;
integer c__8;
integer c__14;
integer c__4;
integer c__7;
} spks10_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__1;
integer c__128;
} spks14_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__1;
integer c__128;
} spks14_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__16;
} spks15_init_t;

typedef struct {
/* Table of constant values */

integer c__16;
} spks15_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__12;
} spks17_init_t;

typedef struct {
/* Table of constant values */

integer c__12;
} spks17_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} spks18_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} spks18_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer pktszs[3];
/* Table of constant values */

integer c__1;
doublereal c_b118;
} spks19_init_t;

typedef struct {
integer pktszs[3];
/* Table of constant values */

integer c__1;
doublereal c_b118;
doublereal data[100];
integer npad;
integer isel;
integer ndir;
integer npkt;
integer i__;
integer l;
integer nread;
logical final;
integer minib;
integer minie;
integer shift;
integer nsdir;
integer noivl;
integer start;
doublereal iv1beg;
doublereal iv1end;
integer min1sz;
integer ub;
doublereal ivfbeg;
integer begidx;
integer bufbas;
doublereal ivlbeg;
integer minbep;
doublereal ivfend;
integer bepidx;
integer endidx;
integer eepidx;
integer remain;
integer ivlbas;
doublereal ivlend;
integer minndr;
integer ptrbas;
integer minnpk;
doublereal contrl[3];
integer curivl;
integer minfsz;
integer nintvl;
integer wndsiz;
integer pktsiz;
integer subtyp;
char spk[255];

} spks19_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__7;
} spks20_init_t;

typedef struct {
/* Table of constant values */

integer c__7;
} spks20_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} spks21_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} spks21_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spksub_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spksub_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkuds_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} spkuds_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} spkw01_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} spkw01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__27;
integer c__40;
integer c__2;
integer c__6;
integer c__1;
} spkw02_init_t;

typedef struct {
/* Table of constant values */

integer c__27;
integer c__40;
integer c__2;
integer c__6;
integer c__1;
} spkw02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__27;
integer c__40;
integer c__2;
integer c__6;
integer c__1;
} spkw03_init_t;

typedef struct {
/* Table of constant values */

integer c__27;
integer c__40;
integer c__2;
integer c__6;
integer c__1;
} spkw03_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__1;
} spkw05_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__1;
} spkw05_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__27;
integer c__2;
integer c__6;
integer c__1;
} spkw08_init_t;

typedef struct {
/* Table of constant values */

integer c__27;
integer c__2;
integer c__6;
integer c__1;
} spkw08_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__27;
integer c__2;
integer c__6;
integer c__1;
} spkw09_init_t;

typedef struct {
/* Table of constant values */

integer c__27;
integer c__2;
integer c__6;
integer c__1;
} spkw09_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__10;
integer c__8;
integer c__14;
integer c__4;
integer c__1;
} spkw10_init_t;

typedef struct {
/* Table of constant values */

integer c__10;
integer c__8;
integer c__14;
integer c__4;
integer c__1;
} spkw10_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__27;
integer c__12;
integer c__1;
} spkw12_init_t;

typedef struct {
/* Table of constant values */

integer c__27;
integer c__12;
integer c__1;
} spkw12_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__27;
integer c__13;
integer c__1;
} spkw13_init_t;

typedef struct {
/* Table of constant values */

integer c__27;
integer c__13;
integer c__1;
} spkw13_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__15;
integer c__16;
} spkw15_init_t;

typedef struct {
/* Table of constant values */

integer c__15;
integer c__16;
} spkw15_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__9;
integer c__17;
integer c__12;
} spkw17_init_t;

typedef struct {
/* Table of constant values */

integer c__9;
integer c__17;
integer c__12;
} spkw17_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__15;
integer c__2;
integer c__6;
integer c__1;
} spkw18_init_t;

typedef struct {
/* Table of constant values */

integer c__15;
integer c__2;
integer c__6;
integer c__1;
} spkw18_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer pktszs[3];
/* Table of constant values */

integer c__198;
integer c__27;
integer c__2;
integer c__6;
integer c__1;
} spkw19_init_t;

typedef struct {
integer pktszs[3];
/* Table of constant values */

integer c__198;
integer c__27;
integer c__2;
integer c__6;
integer c__1;
} spkw19_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__50;
integer c__40;
integer c__2;
integer c__6;
integer c__1;
} spkw20_init_t;

typedef struct {
/* Table of constant values */

integer c__50;
integer c__40;
integer c__2;
integer c__6;
integer c__1;
} spkw20_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__71;
integer c__21;
integer c__1;
} spkw21_init_t;

typedef struct {
/* Table of constant values */

integer c__71;
integer c__21;
integer c__1;
} spkw21_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char prvmth[500];
integer svprvt;
/* Table of constant values */

integer c__100;
integer c__3;
integer c__4;
doublereal c_b45;
} srfnrm_init_t;

typedef struct {
logical first;
char prvmth[500];
integer svprvt;
/* Table of constant values */

integer c__100;
integer c__3;
integer c__4;
doublereal c_b45;
doublereal maxr;
integer shape;
integer nsurf;
logical svfnd1;
integer svctr1[2];
integer svctr2[2];
integer svctr3[2];
integer srfctr[2];
integer srflst[100];
char svtarg[36];
integer svtcde;
char svfref[32];
integer svfxfc;
doublereal svradi[3];
logical pri;

} srfnrm_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
doublereal c_b5;
} srfrec_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
doublereal c_b5;
} srfrec_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__3;
doublereal c_b45;
} srfxpt_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__3;
doublereal c_b45;
logical svfnd1;
logical svfnd2;
integer svctr1[2];
integer svctr2[2];
integer svctr3[2];
integer svtcde;
integer svobsc;
char svtarg[36];
char svdref[32];
integer svrefc;
char svobsr[36];
} srfxpt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} ssizec_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} ssizec_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char cat1nm[32*7];
char cat1dt[4*7];
/* Table of constant values */

integer c__4;
} stcc01_init_t;

typedef struct {
char cat1nm[32*7];
char cat1dt[4*7];
/* Table of constant values */

integer c__4;
integer i__;
integer j;
logical found;
integer ncols;
integer sizes[100];
integer nrows;
char cnames[32*100];
logical indexd[100];
integer tmphnd;
integer numseg;
logical nullok[100];
char dtypes[4*100];
char tmptnm[64];
integer strlns[100];
char tnmprv[64];

} stcc01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__15;
} stcf01_init_t;

typedef struct {
/* Table of constant values */

integer c__15;
} stcf01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__2;
integer c__3;
integer c__4;
integer c__5;
integer c__6;
integer c__7;
} stcg01_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__2;
integer c__3;
integer c__4;
integer c__5;
integer c__6;
integer c__7;
} stcg01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
} stcl01_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
} stcl01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
} stelab_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
} stelab_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} stmp03_init_t;

typedef struct {
logical first;
doublereal pairs[20];
doublereal lbound;
} stmp03_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} stpool_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} stpool_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char defzon[16];
char defsys[16];
char mixed[16];
char juln[16];
char gregrn[16];
doublereal dhoff;
doublereal dmoff;
char mname[16*12];
/* Table of constant values */

integer c__0;
integer c__1;
integer c__6;
} str2et_init_t;

typedef struct {
char defzon[16];
char defsys[16];
char mixed[16];
char juln[16];
char gregrn[16];
doublereal dhoff;
doublereal dmoff;
char mname[16*12];
/* Table of constant values */

integer c__0;
integer c__1;
integer c__6;
doublereal frac;
doublereal hoff;
doublereal moff;
doublereal secs;
integer year;
doublereal tvec[8];
logical mods;
integer last;
doublereal hour;
char hstr[2];
char type__[16];
char mstr[2];
integer i__;
char check[16];
integer cyear;
integer gyear;
logical dojul;
doublereal tvecm[8];
char forml[16];
integer ntvec;
logical zoned;
doublereal extra;
integer month;
char error[400];
integer sc;
integer hr;
integer mm;
integer mn;
integer dy;
logical ok;
char calndr[16];
integer yr;
logical succes;
char modify[16*5];
logical yabbrv;
logical adjust;
doublereal minute;
char pictur[80];
logical ok1;
logical ok2;
integer orgnyr;
integer day;
doublereal mdy[2];
doublereal mon[2];
integer doy;
} str2et_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
logical near__;
char prvcor[5];
char prvmth[500];
integer shape;
/* Table of constant values */

integer c__100;
integer c__3;
} subpnt_init_t;

typedef struct {
logical first;
logical near__;
char prvcor[5];
char prvmth[500];
integer shape;
/* Table of constant values */

integer c__100;
integer c__3;
logical xmit;
logical usecn;
integer nsurf;
logical uselt;
logical svfnd1;
logical svfnd2;
integer svctr1[2];
integer svctr2[2];
integer svctr3[2];
integer svctr4[2];
char subtyp[20];
integer srflst[100];
logical usestl;
char svtarg[36];
integer svtcde;
char svobsr[36];
integer svobsc;
char svfref[32];
integer svrefc;
logical pri;
} subpnt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal origin[3];
logical first;
/* Table of constant values */

integer c__3;
} subpt_init_t;

typedef struct {
doublereal origin[3];
logical first;
/* Table of constant values */

integer c__3;
logical svfnd1;
logical svfnd2;
integer svctr1[2];
integer svctr2[2];
integer svtcde;
integer svobsc;
char svtarg[36];
char svobsr[36];
} subpt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
logical near__;
char prvcor[5];
char prvmth[500];
integer shape;
/* Table of constant values */

integer c__100;
integer c__3;
integer c__10;
} subslr_init_t;

typedef struct {
logical first;
logical near__;
char prvcor[5];
char prvmth[500];
integer shape;
/* Table of constant values */

integer c__100;
integer c__3;
integer c__10;
logical xmit;
logical usecn;
integer nsurf;
logical uselt;
logical svfnd1;
logical svfnd2;
integer svctr1[2];
integer svctr2[2];
integer svctr3[2];
integer svctr4[2];
integer srflst[100];
logical usestl;
char svtarg[36];
integer svtcde;
char svobsr[36];
integer svobsc;
char svfref[32];
integer svrefc;
logical pri;
} subslr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal origin[3];
logical first;
/* Table of constant values */

integer c__3;
} subsol_init_t;

typedef struct {
doublereal origin[3];
logical first;
/* Table of constant values */

integer c__3;
logical svfnd1;
logical svfnd2;
integer svctr1[2];
integer svctr2[2];
integer svtcde;
integer svobsc;
char svtarg[36];
char svobsr[36];
} subsol_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char mssg[32*7];
/* Table of constant values */

integer c__2;
} surfnm_init_t;

typedef struct {
char mssg[32*7];
/* Table of constant values */

integer c__2;
doublereal m;
doublereal a1;
doublereal b1;
doublereal c1;
integer bad;

} surfnm_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char mssg[32*7];
/* Table of constant values */

integer c__2;
integer c__3;
doublereal c_b19;
} surfpt_init_t;

typedef struct {
char mssg[32*7];
/* Table of constant values */

integer c__2;
integer c__3;
doublereal c_b19;
} surfpt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b13;
} surfpv_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b13;
} surfpv_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} sxform_init_t;

typedef struct {
logical first;
char svto[32];
integer svctr1[2];
integer svctr2[2];
integer svfcod;
integer svtcde;
char svfrom[32];
} sxform_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} sydelc_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} sydelc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} sydeld_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} sydeld_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} sydeli_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} sydeli_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} sydupc_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} sydupc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} sydupd_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} sydupd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} sydupi_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} sydupi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} syenqc_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} syenqc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} syenqd_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} syenqd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} syenqi_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} syenqi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} sypopc_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} sypopc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} sypopd_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} sypopd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} sypopi_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} sypopi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} sypshc_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} sypshc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} sypshd_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} sypshd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} sypshi_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} sypshi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} syputc_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} syputc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} syputd_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} syputd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} syputi_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} syputi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
integer c__1;
} syrenc_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
integer c__1;
} syrenc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
integer c__1;
} syrend_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
integer c__1;
} syrend_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
integer c__1;
} syreni_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
integer c__1;
} syreni_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} sysetc_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} sysetc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} sysetd_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} sysetd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} syseti_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} syseti_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical dochck;
doublereal dinmon[12];
char mnames[10*12];
char cname[7*4];
/* Table of constant values */

integer c__4;
integer c__100;
integer c__400;
integer c__8;
integer c__3;
integer c__2;
} tcheck_init_t;

typedef struct {
logical dochck;
doublereal dinmon[12];
char mnames[10*12];
char cname[7*4];
/* Table of constant values */

integer c__4;
integer c__100;
integer c__400;
integer c__8;
integer c__3;
integer c__2;
integer comp;
doublereal jun30;
integer year;
integer hour;
integer i__;
integer j;
integer k;
doublereal hlbnd;
doublereal hubnd;
integer myear;
doublereal dinyr;
integer month;
integer second;
integer leapdy;
char messge[200];
integer minute;
integer day;
doublereal doy;

} tcheck_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
logical usestl;
integer nrad;
char prvcor[5];
integer prvilu;
char prvloc[25];
char prvmth[500];
integer prvtrg;
logical usecn;
logical uselt;
/* Table of constant values */

integer c__100;
integer c__1;
integer c__3;
integer c__2000;
integer c__0;
} termpt_init_t;

typedef struct {
logical first;
logical usestl;
integer nrad;
char prvcor[5];
integer prvilu;
char prvloc[25];
char prvmth[500];
integer prvtrg;
logical usecn;
logical uselt;
/* Table of constant values */

integer c__100;
integer c__1;
integer c__3;
integer c__2000;
integer c__0;
logical uflag;
integer shape;
integer nsurf;
logical svfnd1;
logical svfnd2;
logical svfnd3;
integer svctr1[2];
integer svctr2[2];
integer svctr3[2];
integer svctr4[2];
integer svctr5[2];
integer loccde;
integer svctr6[2];
integer svctr7[2];
integer ilucde;
doublereal maxrad;
integer trgcde;
char subtyp[20];
doublereal pntbuf[6000]	/* was [3][2000] */;
integer shadow;
integer srflst[100];
integer svlcod;
integer trmtyp;
logical pri;
char svtarg[36];
integer svtcde;
char svobsr[36];
integer svobsc;
char svilum[36];
integer svicde;
char svfref[32];
integer svfxfc;
doublereal svtrad[3];
doublereal svsrad[3];
} termpt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer centry;
integer lbound;
} texpyr_init_t;

typedef struct {
integer centry;
integer lbound;
} texpyr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char defsys[16];
char defzon[16];
char defcal[16];
char zones[16*8];
char trnslt[16*8];
/* Table of constant values */

integer c__8;
integer c__0;
integer c__1;
} timdef_init_t;

typedef struct {
char defsys[16];
char defzon[16];
char defcal[16];
char zones[16*8];
char trnslt[16*8];
/* Table of constant values */

integer c__8;
integer c__0;
integer c__1;
doublereal hoff;
doublereal moff;
integer last;
integer zone;
char myval[16];
logical succes;
char myactn[16];
char myitem[16];
} timdef_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char months[9*12];
integer mlen[12];
char wkdays[9*7];
integer wklen[7];
logical first;
doublereal power[15];
/* Table of constant values */

integer c__100;
integer c__0;
integer c__1;
integer c__14;
doublereal c_b274;
doublereal c_b275;
doublereal c_b338;
} timout_init_t;

typedef struct {
char months[9*12];
integer mlen[12];
char wkdays[9*7];
integer wklen[7];
logical first;
doublereal power[15];
/* Table of constant values */

integer c__100;
integer c__0;
integer c__1;
integer c__14;
doublereal c_b274;
doublereal c_b275;
doublereal c_b338;
doublereal frac;
doublereal hoff;
logical have[51];
doublereal moff;
integer jday;
integer gday;
doublereal incr;
integer last;
integer dump[10];
doublereal myet;
integer part;
integer type__;
doublereal tvec[8];
integer jdoy;
integer gdoy;
integer indx;
char tsys[16];
integer b;
integer e;
integer i__;
integer j;
doublereal x;
doublereal delta;
logical doera;
integer appnd;
integer ident[100];
integer class__[43];
integer gyear;
doublereal tempd;
integer jyear;
doublereal value;
char marks[8*42];
integer width;
integer ndump;
doublereal ntvec[8];
integer start;
doublereal ptvec[8];
char mymon[9];
integer mylen;
char intyp[16];
char mywkd[9];
integer pntrs[100];
char ywfmt[8];
char mystr[256];
integer wktyp;
logical go2jul;
integer id[51];
logical ok;
logical making;
integer length[51];
doublereal factor;
integer mrklen[42];
doublereal intmed;
integer nmarks;
char orignl[32*51];
integer caltyp;
integer timfmt;
doublereal values[51];
integer compnt[16]	/* was [8][2] */;
char ymdfmt[8];
char string[256];
char bastyp[16];
logical dozone;
integer stopat;
integer trncat;
integer ntokns;
doublereal timpad;
char substr[256];
integer jmonth;
integer gmonth;
integer timtyp;
integer montyp;
logical unknwn;
logical pumpup;
integer numtyp;
logical vanish;
integer beg[100];
char cal[16];
doublereal pad[51];
integer end[100];
char fmt[32];
char zon[32];
} timout_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
logical found;
/* Table of constant values */

integer c__157;
integer c__2;
integer c__1;
integer c__3;
integer c__200;
integer c__100;
} tisbod_init_t;

typedef struct {
logical first;
logical found;
/* Table of constant values */

integer c__157;
integer c__2;
integer c__1;
integer c__3;
integer c__200;
integer c__100;
doublereal dphi;
integer cent;
char item[32];
doublereal tipm[9]	/* was [3][3] */;
doublereal d__;
integer i__;
integer j;
doublereal dcoef[3];
doublereal t;
doublereal w;
doublereal delta;
integer refid;
integer avail;
doublereal epoch;
doublereal rcoef[3];
doublereal tcoef[200]	/* was [2][100] */;
integer pcref;
doublereal wcoef[3];
doublereal theta;
doublereal dtipm[9]	/* was [3][3] */;
doublereal costh[100];
char dtype[1];
doublereal sinth[100];
doublereal xtipm[9]	/* was [3][3] */;
integer j2code;
doublereal req2pc[9]	/* was [3][3] */;
doublereal ac[100];
doublereal dc[100];
integer na;
integer nd;
doublereal ra;
doublereal bdcoef[471]	/* was [3][157] */;
integer at;
doublereal wc[100];
doublereal dw;
doublereal ddelta;
integer bidids[157];
doublereal brcoef[471]	/* was [3][157] */;
integer bpcref[157];
integer frcode;
doublereal bpckep[157];
doublereal pckepc;
integer nw;
doublereal btcoef[31400]	/* was [2][100][157] */;
doublereal bwcoef[471]	/* was [3][157] */;
doublereal dtheta;
doublereal pckref;
integer bidpol[163];
integer bnpair[157];
integer bidlst[157];
logical update;
integer ntheta;
doublereal dcosth[100];
integer reqref;
doublereal dsinth[100];
doublereal tmpepc;
char fixfrm[32];
char errmsg[1840];
doublereal eulsta[6];
integer npairs;
doublereal xdtipm[9]	/* was [3][3] */;
doublereal costmp;
integer pulctr[2];
doublereal sintmp;
char timstr[35];
doublereal bac[15700]	/* was [100][157] */;
doublereal bdc[15700]	/* was [100][157] */;
doublereal dec;
integer bna[157];
integer bnd[157];
doublereal dra;
integer dim;
doublereal bwc[15700]	/* was [100][157] */;
doublereal phi;
integer bnw[157];
logical new__;
doublereal ddec;

} tisbod_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer at;
logical first;
/* Table of constant values */

integer c__200;
integer c__1;
integer c__2;
integer c__9;
doublereal c_b101;
integer c__3;
integer c__4;
integer c__14;
} tkfram_init_t;

typedef struct {
integer at;
logical first;
/* Table of constant values */

integer c__200;
integer c__1;
integer c__2;
integer c__9;
doublereal c_b101;
integer c__3;
integer c__4;
integer c__14;
char name__[32];
integer tail;
char spec[32];
char item[32*14];
integer idnt[1];
integer axes[3];
logical full;
integer pool[412]	/* was [2][206] */;
char type__[1];
doublereal qtmp[4];
integer i__;
integer n;
integer r__;
doublereal buffd[1800]	/* was [9][200] */;
integer buffi[200]	/* was [1][200] */;
integer oldid;
char agent[32];
doublereal tempd;
char idstr[32];
char versn[8];
char units[32];
integer ar;
char frname[32];
doublereal angles[3];
char oldagt[32];
logical buffrd;
logical update;
char altnat[32];
integer idents[200]	/* was [1][200] */;
doublereal matrix[9]	/* was [3][3] */;
doublereal quatrn[4];
logical fnd;
char alt[32*14];

} tkfram_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} tostdo_init_t;

typedef struct {
logical first;
integer stdout;

} tostdo_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__400;
} tparse_init_t;

typedef struct {
/* Table of constant values */

integer c__400;
} tparse_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char zones[3*8];
char offset[6*8];
/* Table of constant values */

integer c__300;
integer c__1;
integer c__0;
integer c__8;
} tpartv_init_t;

typedef struct {
logical first;
char zones[3*8];
char offset[6*8];
/* Table of constant values */

integer c__300;
integer c__1;
integer c__0;
integer c__8;
integer begs[5];
integer ends[5];
integer from;
integer b;
integer e;
integer i__;
integer r__;
char delim[1*3];
integer mapto;
integer b1;
integer b2;
integer e1;
integer e2;
char known[12*300];
integer to;
char meanng[12*300];
logical havera;
logical havapm;
logical havwdy;
logical havzon;
integer nknown;
logical resolv;
logical havsys;
logical l2r;
logical r2l;
char rep[12];
integer use;
} tpartv_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical notrc;
integer frzcnt;
integer frzovr;
integer maxdep;
integer modcnt;
integer ovrflw;
/* Table of constant values */

integer c__5;
integer c__3;
integer c__1;
integer c__0;
} trcpkg_init_t;

typedef struct {
logical notrc;
integer frzcnt;
integer frzovr;
integer maxdep;
integer modcnt;
integer ovrflw;
/* Table of constant values */

integer c__5;
integer c__3;
integer c__1;
integer c__0;
char stack[32*100];
char frozen[32*100];
} trcpkg_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
integer extra[12];
integer dpjan0[12];
integer dpbegl[12];
logical nodata;
/* Table of constant values */

integer c__2000;
integer c__1;
integer c__4;
integer c__100;
integer c__400;
integer c__1991;
integer c__6;
integer c__21;
integer c__280;
integer c__12;
integer c__7;
doublereal c_b188;
doublereal c_b189;
} ttrans_init_t;

typedef struct {
logical first;
integer extra[12];
integer dpjan0[12];
integer dpbegl[12];
logical nodata;
/* Table of constant values */

integer c__2000;
integer c__1;
integer c__4;
integer c__100;
integer c__400;
integer c__1991;
integer c__6;
integer c__21;
integer c__280;
integer c__12;
integer c__7;
doublereal c_b188;
doublereal c_b189;
doublereal jd1101;
integer dn2000;
doublereal dp2000;
doublereal frac;
integer nref;
integer week;
doublereal secs;
integer year;
doublereal mins;
char vars__[32*1];
integer qint;
char rest[32];
char myto[32];
integer i__;
doublereal halfd;
char recog[8*21];
integer fmday;
doublereal daydp;
logical needy[21];
integer dyear;
doublereal tempd;
logical found;
integer tempi;
logical forml[21];
integer wkday;
doublereal tsecs;
integer dofyr;
integer pfrom;
integer month;
integer dpsun;
doublereal hours;
doublereal dt;
doublereal taitab[280];
integer daytab[280];
doublereal jdsecs;
doublereal daylen;
integer parsed[21];
doublereal formal;
doublereal secspd;
integer ordvec[21];
logical update;
integer doffst;
integer offset;
doublereal exsecs;
doublereal lastdt;
integer daynum;
integer fyrday;
char unifrm[8*27];
integer refptr;
integer dayptr;
integer sunday;
integer taiptr;
char myfrom[32];
integer usrctr[2];
integer yr1;
integer yr4;
doublereal tai;
integer day;
integer rem;
integer pto;
integer yr100;
integer yr400;

} ttrans_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal value;
} twopi_init_t;

typedef struct {
doublereal value;
} twopi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer seqnce[5];
/* Table of constant values */

integer c__9;
} twovec_init_t;

typedef struct {
integer seqnce[5];
/* Table of constant values */

integer c__9;
} twovec_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} ucase_init_t;

typedef struct {
logical first;
integer lowa;
integer lowz;
integer shift;
} ucase_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char missed[20*4];
logical nodata;
char vars__[16*4];
/* Table of constant values */

integer c__3;
integer c__4;
integer c__7;
integer c__1;
integer c__2;
integer c__14;
} unitim_init_t;

typedef struct {
logical first;
char missed[20*4];
logical nodata;
char vars__[16*4];
/* Table of constant values */

integer c__3;
integer c__4;
integer c__7;
integer c__1;
integer c__2;
integer c__14;
doublereal k;
doublereal m[2];
char recog[8*13];
doublereal eb;
char bslash[1];
doublereal secspd;
char typtdb[8*10];
integer usrctr[2];
char typtdt[8*9];
doublereal dta;
doublereal jd2000;

} unitim_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b3;
} vprjp_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b3;
} vprjp_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b3;
} vprjpi_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b3;
} vprjpi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
} vrotv_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
} vrotv_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} wncomd_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} wncomd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} wnexpd_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} wnexpd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
} wninsd_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
} wninsd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} wnvald_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} wnvald_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char hexdig[1*16];
logical first;
/* Table of constant values */

integer c__3;
integer c__1;
} wrencc_init_t;

typedef struct {
char hexdig[1*16];
logical first;
/* Table of constant values */

integer c__3;
integer c__1;
integer intfpc;
integer intesc;
integer intlpc;
integer intquo;

} wrencc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
} wrencd_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
} wrencd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
} wrenci_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
} wrenci_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} writln_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} writln_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___9;
cilist io___10;
cilist io___11;
cilist io___12;
/* Table of constant values */

integer c__9;
integer c__1;
integer c__5;
} wrkvar_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___9;
cilist io___10;
cilist io___11;
cilist io___12;
/* Table of constant values */

integer c__9;
integer c__1;
integer c__5;
} wrkvar_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___6;
cilist io___7;
cilist io___8;
cilist io___9;
cilist io___10;
cilist io___11;
cilist io___12;
cilist io___15;
cilist io___16;
cilist io___17;
cilist io___18;
/* Table of constant values */

integer c__1;
integer c__9;
integer c__3;
integer c__0;
integer c__2;
} wrline_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___6;
cilist io___7;
cilist io___8;
cilist io___9;
cilist io___10;
cilist io___11;
cilist io___12;
cilist io___15;
cilist io___16;
cilist io___17;
cilist io___18;
/* Table of constant values */

integer c__1;
integer c__9;
integer c__3;
integer c__0;
integer c__2;
} wrline_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer next[3];
/* Table of constant values */

integer c__1;
doublereal c_b67;
doublereal c_b68;
} xdda_init_t;

typedef struct {
integer next[3];
/* Table of constant values */

integer c__1;
doublereal c_b67;
doublereal c_b68;
} xdda_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal delta[9]	/* was [3][3] */;
integer next[3];
/* Table of constant values */

integer c__6;
} xf2eul_init_t;

typedef struct {
doublereal delta[9]	/* was [3][3] */;
integer next[3];
/* Table of constant values */

integer c__6;
} xf2eul_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char cosys[40*6];
logical first;
/* Table of constant values */

integer c__0;
integer c__6;
integer c__3;
doublereal c_b65;
} xfmsta_init_t;

typedef struct {
char cosys[40*6];
logical first;
/* Table of constant values */

integer c__0;
integer c__6;
integer c__3;
doublereal c_b65;
logical svfnd1;
integer svctr1[2];
integer svbdid;
char svbody[36];
} xfmsta_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Fortran I/O blocks */
cilist io___5;
/* Table of constant values */

integer c__1;
} zzascii_init_t;

typedef struct {
/* Fortran I/O blocks */
cilist io___5;
/* Table of constant values */

integer c__1;
} zzascii_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
doublereal c_b26;
} zzasryel_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
doublereal c_b26;
} zzasryel_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__1;
integer c__620;
integer c__2;
integer c__3;
} zzbodblt_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__1;
integer c__620;
integer c__2;
integer c__3;
integer bltcod[620];
char bltnam[36*620];
char bltnor[36*620];
} zzbodblt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char nbc[32];
char nbn[32];
/* Table of constant values */

integer c__1;
integer c__14983;
} zzbodker_init_t;

typedef struct {
char nbc[32];
char nbn[32];
/* Table of constant values */

integer c__1;
integer c__14983;
} zzbodker_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical bodchg;
logical first;
logical extker;
logical nodata;
integer nwatch;
char wnames[32*2];
/* Table of constant values */

integer c__773;
integer c__1;
} zzbodtrn_init_t;

typedef struct {
logical bodchg;
logical first;
logical extker;
logical nodata;
integer nwatch;
char wnames[32*2];
/* Table of constant values */

integer c__773;
integer c__1;
integer i__;
integer j;
integer index;
integer defcod[773];
char defnam[36*773];
integer didids[773];
integer dididx[773];
integer kercod[14983];
integer kidids[14983];
integer codidx;
integer didpol[779];
integer kididx[14983];
char defnor[36*773];
char kernam[36*14983];
integer dnmidx[773];
integer defsiz;
integer didlst[773];
integer kidpol[14989];
integer dnmpol[779];
integer knmidx[14983];
integer kidlst[14983];
char dnmnms[36*773];
char tmpnam[36];
logical lupdte;
char kernor[36*14983];
integer dnmlst[773];
integer knmpol[14989];
char knmnms[36*14983];
integer subctr[2];
integer kersiz;
integer knmlst[14983];
integer pulctr[2];
} zzbodtrn_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal big;
logical first;
} zzbquad_init_t;

typedef struct {
doublereal big;
logical first;
} zzbquad_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} zzckcv04_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
} zzckcv04_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__72;
integer c__100;
integer c__0;
integer c__10;
integer c__1;
} zzckspk_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__6;
integer c__72;
integer c__100;
integer c__0;
integer c__10;
integer c__1;
} zzckspk_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
doublereal invub;
/* Table of constant values */

doublereal c_b8;
} zzcnquad_init_t;

typedef struct {
logical first;
doublereal invub;
/* Table of constant values */

doublereal c_b8;
} zzcnquad_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__36;
} zzcorsxf_init_t;

typedef struct {
/* Table of constant values */

integer c__36;
} zzcorsxf_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} zzctr_init_t;

typedef struct {
logical first;
integer ctrhgh;
integer ctrlow;
} zzctr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b6;
integer c__6;
} zzcvstat_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b6;
integer c__6;
doublereal svet;
char svref[32];
integer svctr;
doublereal svstat[6];

} zzcvstat_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b6;
} zzcxbrut_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b6;
} zzcxbrut_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
integer natbff;
/* Fortran I/O blocks */
cilist io___13;
cilist io___15;
/* Table of constant values */

integer c__4;
logical c_false;
integer c__1;
integer c__128;
} zzdafgdr_init_t;

typedef struct {
logical first;
integer natbff;
/* Fortran I/O blocks */
cilist io___13;
cilist io___15;
/* Table of constant values */

integer c__4;
logical c_false;
integer c__1;
integer c__128;
char strbff[8*4];
} zzdafgdr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
integer natbff;
/* Fortran I/O blocks */
cilist io___13;
cilist io___21;
/* Table of constant values */

integer c__4;
logical c_false;
integer c__1;
} zzdafgfr_init_t;

typedef struct {
logical first;
integer natbff;
/* Fortran I/O blocks */
cilist io___13;
cilist io___21;
/* Table of constant values */

integer c__4;
logical c_false;
integer c__1;
char strbff[8*4];
} zzdafgfr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
integer natbff;
doublereal equiv_0[128];
/* Fortran I/O blocks */
cilist io___15;
cilist io___16;
/* Table of constant values */

integer c__4;
logical c_false;
integer c__1;
integer c__128;
} zzdafgsr_init_t;

typedef struct {
logical first;
integer natbff;
doublereal equiv_0[128];
/* Fortran I/O blocks */
cilist io___15;
cilist io___16;
/* Table of constant values */

integer c__4;
logical c_false;
integer c__1;
integer c__128;
char strbff[8*4];
} zzdafgsr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Fortran I/O blocks */
cilist io___15;
/* Table of constant values */

integer c__3;
integer c__1;
} zzdafnfr_init_t;

typedef struct {
logical first;
/* Fortran I/O blocks */
cilist io___15;
/* Table of constant values */

integer c__3;
integer c__1;
char prenul[603];
char ftpstr[28];
char pstnul[297];
} zzdafnfr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Fortran I/O blocks */
cilist io___10;
cilist io___11;
/* Table of constant values */

logical c_false;
integer c__128;
integer c__1;
} zzdasgrd_init_t;

typedef struct {
logical first;
/* Fortran I/O blocks */
cilist io___10;
cilist io___11;
/* Table of constant values */

logical c_false;
integer c__128;
integer c__1;
integer natbff;
integer intbff;
} zzdasgrd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Fortran I/O blocks */
cilist io___10;
cilist io___11;
/* Table of constant values */

logical c_false;
integer c__256;
integer c__1;
} zzdasgri_init_t;

typedef struct {
logical first;
/* Fortran I/O blocks */
cilist io___10;
cilist io___11;
/* Table of constant values */

logical c_false;
integer c__256;
integer c__1;
integer natbff;
integer intbff;
} zzdasgri_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Fortran I/O blocks */
cilist io___15;
/* Table of constant values */

integer c__3;
integer c__1;
} zzdasnfr_init_t;

typedef struct {
logical first;
/* Fortran I/O blocks */
cilist io___15;
/* Table of constant values */

integer c__3;
integer c__1;
char prenul[607];
char ftpstr[28];
char pstnul[297];
} zzdasnfr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
integer natbff;
/* Fortran I/O blocks */
cilist io___6;
cilist io___9;
/* Table of constant values */

logical c_false;
integer c__2;
integer c__1;
} zzdasrfr_init_t;

typedef struct {
logical first;
integer natbff;
/* Fortran I/O blocks */
cilist io___6;
cilist io___9;
/* Table of constant values */

logical c_false;
integer c__2;
integer c__1;
} zzdasrfr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char clslst[8*3];
char stramh[8*4];
char strarc[8*2];
char strbff[8*4];
/* Table of constant values */

integer c__3;
} zzddhgsd_init_t;

typedef struct {
char clslst[8*3];
char stramh[8*4];
char strarc[8*2];
char strbff[8*4];
/* Table of constant values */

integer c__3;
} zzddhgsd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__4;
} zzddhini_init_t;

typedef struct {
/* Table of constant values */

integer c__4;
} zzddhini_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
logical opnfst;
integer nft;
integer next;
integer nut;
integer reqcnt;
/* Table of constant values */

integer c__4;
integer c__2;
integer c__0;
} zzddhman_init_t;

typedef struct {
logical first;
logical opnfst;
integer nft;
integer next;
integer nut;
integer reqcnt;
/* Table of constant values */

integer c__4;
integer c__2;
integer c__0;
integer ftbff[5000];
integer ftabs[5000];
integer ftamh[5000];
integer ftarc[5000];
integer fthan[5000];
char ftnam[255*5000];
integer uthan[23];
doublereal ftmnm[5000];
logical utlck[23];
integer ftrtm[5000];
integer utcst[23];
integer utlun[23];
integer natbff;
char strbff[8*4];
char stramh[8*4];
char strarc[8*2];
integer supbff[4];
integer numsup;
} zzddhman_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
integer natbff;
/* Fortran I/O blocks */
cilist io___10;
cilist io___18;
cilist io___20;
/* Table of constant values */

integer c__1;
integer c__20;
} zzddhmnm_init_t;

typedef struct {
logical first;
integer natbff;
/* Fortran I/O blocks */
cilist io___10;
cilist io___18;
cilist io___20;
/* Table of constant values */

integer c__1;
integer c__20;
integer supbff[4];
integer numsup;
} zzddhmnm_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__4;
} zzddhnfc_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__4;
integer savbff;
char strbff[8*4];
} zzddhnfc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Fortran I/O blocks */
cilist io___11;
cilist io___20;
/* Table of constant values */

integer c__1;
integer c__2;
integer c__5;
integer c__4;
} zzddhppf_init_t;

typedef struct {
logical first;
/* Fortran I/O blocks */
cilist io___11;
cilist io___20;
/* Table of constant values */

integer c__1;
integer c__2;
integer c__5;
integer c__4;
char null[1];
char ftpdlm[1];
char ftpmem[16];
char ftplft[6];
char strarc[8*2];
char strbff[8*5];
char ftprgt[6];
} zzddhppf_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} zzdiv_init_t;

typedef struct {
logical first;
doublereal expnt;
doublereal logden;
doublereal lognum;
} zzdiv_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer ctr[2];
logical first;
integer prvbod;
} zzdskbbl_init_t;

typedef struct {
integer ctr[2];
logical first;
integer prvbod;
} zzdskbbl_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__0;
integer c__1000;
integer c__9;
} zzdskbun_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__0;
integer c__1000;
integer c__9;
} zzdskbun_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__1000;
integer c__9;
} zzdskbux_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__1000;
integer c__9;
} zzdskbux_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__8;
integer c__24;
integer c__3;
} zzdsksba_init_t;

typedef struct {
/* Table of constant values */

integer c__8;
integer c__24;
integer c__3;
} zzdsksba_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer btnbod;
integer btbody[10];
integer bsrctr[2];
logical first;
integer stfree;
/* Table of constant values */

integer c__10;
integer c__10000;
integer c__8;
integer c__24;
} zzdsksbf_init_t;

typedef struct {
integer btnbod;
integer btbody[10];
integer bsrctr[2];
logical first;
integer stfree;
/* Table of constant values */

integer c__10;
integer c__10000;
integer c__8;
integer c__24;
integer sthan[10000];
doublereal strad[10000];
doublereal stoff[30000]	/* was [3][10000] */;
doublereal stctr[30000]	/* was [3][10000] */;
integer stdlad[80000]	/* was [8][10000] */;
integer btsegp[10];
doublereal stdscr[240000]	/* was [24][10000] */;
integer btstsz[10];
} zzdsksbf_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__24;
integer c__8;
integer c__3;
} zzdsksbi_init_t;

typedef struct {
/* Table of constant values */

integer c__24;
integer c__8;
integer c__3;
} zzdsksbi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__24;
integer c__8;
integer c__3;
} zzdsksbr_init_t;

typedef struct {
/* Table of constant values */

integer c__24;
integer c__8;
integer c__3;
} zzdsksbr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__100;
integer c__10;
} zzdsksel_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__100;
integer c__10;
doublereal savet;
doublereal savco1;
doublereal savco2;
integer savbid;
integer savfid;
doublereal savpar[10];
integer savcls;
integer savnsf;
integer savsrf[100];
integer savtrg;
doublereal pi2;
doublereal savpos[3];
integer savsys;
} zzdsksel_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__6;
} zzdsksgr_init_t;

typedef struct {
/* Table of constant values */

integer c__6;
} zzdsksgr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer ctr[2];
logical first;
integer prvfid;
integer prvbod;
integer prvlst[100];
integer prvnls;
doublereal svmaxr;
doublereal svminr;
/* Table of constant values */

integer c__3;
} zzdsksph_init_t;

typedef struct {
integer ctr[2];
logical first;
integer prvfid;
integer prvbod;
integer prvlst[100];
integer prvnls;
doublereal svmaxr;
doublereal svminr;
/* Table of constant values */

integer c__3;
} zzdsksph_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__32;
integer c__1;
} zzdynbid_init_t;

typedef struct {
/* Table of constant values */

integer c__32;
integer c__1;
} zzdynbid_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__32;
integer c__1;
} zzdynfid_init_t;

typedef struct {
/* Table of constant values */

integer c__32;
integer c__1;
} zzdynfid_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char axes[1*3];
logical first;
char itmcof[32*3];
char itmsep[32];
char vname[4*2];
/* Table of constant values */

integer c__2;
integer c__36;
integer c__1;
integer c__0;
integer c__6;
integer c__3;
integer c__12;
doublereal c_b386;
integer c__20;
} zzdynfr0_init_t;

typedef struct {
char axes[1*3];
logical first;
char itmcof[32*3];
char itmsep[32];
char vname[4*2];
/* Table of constant values */

integer c__2;
integer c__36;
integer c__1;
integer c__0;
integer c__6;
integer c__3;
integer c__12;
doublereal c_b386;
integer c__20;
integer earth;
char itmra[32*2];
char itmabc[32*2];
char itmdec[32*2];
char itmaxe[32*2];
char itmfrm[32*2];
char itmlat[32*2];
char itmlon[32*2];
char itmobs[32*2];
char itmspc[32*2];
char itmtrg[32*2];
char itmunt[32*2];
char itmvdf[32*2];
char itmvec[32*2];
integer j2000;
} zzdynfr0_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char axes[1*3];
logical first;
char itmcof[32*3];
char itmsep[32];
char vname[4*2];
/* Table of constant values */

integer c__2;
integer c__36;
integer c__1;
integer c__0;
integer c__6;
integer c__3;
integer c__12;
doublereal c_b386;
integer c__20;
} zzdynfrm_init_t;

typedef struct {
char axes[1*3];
logical first;
char itmcof[32*3];
char itmsep[32];
char vname[4*2];
/* Table of constant values */

integer c__2;
integer c__36;
integer c__1;
integer c__0;
integer c__6;
integer c__3;
integer c__12;
doublereal c_b386;
integer c__20;
integer earth;
char itmra[32*2];
char itmabc[32*2];
char itmdec[32*2];
char itmaxe[32*2];
char itmfrm[32*2];
char itmlat[32*2];
char itmlon[32*2];
char itmobs[32*2];
char itmspc[32*2];
char itmtrg[32*2];
char itmunt[32*2];
char itmvdf[32*2];
char itmvec[32*2];
integer j2000;
} zzdynfrm_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__32;
integer c__1;
} zzdynoac_init_t;

typedef struct {
/* Table of constant values */

integer c__32;
integer c__1;
} zzdynoac_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__32;
integer c__1;
} zzdynoad_init_t;

typedef struct {
/* Table of constant values */

integer c__32;
integer c__1;
} zzdynoad_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char axes[1*3];
logical first;
char itmcof[32*3];
char itmsep[32];
char vname[4*2];
/* Table of constant values */

integer c__2;
integer c__9;
integer c__36;
integer c__1;
integer c__0;
integer c__3;
doublereal c_b192;
integer c__6;
doublereal c_b365;
integer c__20;
} zzdynrot_init_t;

typedef struct {
char axes[1*3];
logical first;
char itmcof[32*3];
char itmsep[32];
char vname[4*2];
/* Table of constant values */

integer c__2;
integer c__9;
integer c__36;
integer c__1;
integer c__0;
integer c__3;
doublereal c_b192;
integer c__6;
doublereal c_b365;
integer c__20;
integer earth;
char itmra[32*2];
char itmabc[32*2];
char itmdec[32*2];
char itmaxe[32*2];
char itmfrm[32*2];
char itmlat[32*2];
char itmlon[32*2];
char itmobs[32*2];
char itmspc[32*2];
char itmtrg[32*2];
char itmunt[32*2];
char itmvdf[32*2];
char itmvec[32*2];
integer j2000;
} zzdynrot_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char axes[1*3];
logical first;
char itmcof[32*3];
char itmsep[32];
char vname[4*2];
/* Table of constant values */

integer c__2;
integer c__9;
integer c__36;
integer c__1;
integer c__0;
integer c__3;
doublereal c_b190;
integer c__6;
doublereal c_b356;
integer c__20;
} zzdynrt0_init_t;

typedef struct {
char axes[1*3];
logical first;
char itmcof[32*3];
char itmsep[32];
char vname[4*2];
/* Table of constant values */

integer c__2;
integer c__9;
integer c__36;
integer c__1;
integer c__0;
integer c__3;
doublereal c_b190;
integer c__6;
doublereal c_b356;
integer c__20;
integer earth;
char itmra[32*2];
char itmabc[32*2];
char itmdec[32*2];
char itmaxe[32*2];
char itmfrm[32*2];
char itmlat[32*2];
char itmlon[32*2];
char itmobs[32*2];
char itmspc[32*2];
char itmtrg[32*2];
char itmunt[32*2];
char itmvdf[32*2];
char itmvec[32*2];
integer j2000;
} zzdynrt0_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__32;
integer c__1;
} zzdynvac_init_t;

typedef struct {
/* Table of constant values */

integer c__32;
integer c__1;
} zzdynvac_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__32;
integer c__1;
} zzdynvad_init_t;

typedef struct {
/* Table of constant values */

integer c__32;
integer c__1;
} zzdynvad_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__32;
integer c__1;
} zzdynvai_init_t;

typedef struct {
/* Table of constant values */

integer c__32;
integer c__1;
} zzdynvai_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b30;
doublereal c_b35;
} zzedterm_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b30;
doublereal c_b35;
} zzedterm_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__9;
doublereal c_b31;
} zzedtmpt_init_t;

typedef struct {
/* Table of constant values */

integer c__9;
doublereal c_b31;
} zzedtmpt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__3;
logical c_false;
integer c__256;
} zzekac01_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__3;
logical c_false;
integer c__256;
} zzekac01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__2;
logical c_false;
integer c__128;
} zzekac02_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__2;
logical c_false;
integer c__128;
} zzekac02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
logical c_false;
integer c__0;
} zzekac03_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
logical c_false;
integer c__0;
} zzekac03_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__3;
logical c_false;
integer c__256;
} zzekac04_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__3;
logical c_false;
integer c__256;
} zzekac04_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__2;
logical c_false;
integer c__128;
} zzekac05_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__2;
logical c_false;
integer c__128;
} zzekac05_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
logical c_false;
} zzekac06_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
logical c_false;
} zzekac06_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__256;
integer c__2;
} zzekac07_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__256;
integer c__2;
} zzekac07_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__128;
} zzekac08_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__128;
} zzekac08_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__2;
} zzekac09_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__2;
} zzekac09_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} zzekacps_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} zzekacps_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c_n2;
integer c__3;
logical c_false;
integer c__1;
} zzekad01_init_t;

typedef struct {
/* Table of constant values */

integer c_n2;
integer c__3;
logical c_false;
integer c__1;
} zzekad01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c_n2;
integer c__2;
logical c_false;
integer c__1;
} zzekad02_init_t;

typedef struct {
/* Table of constant values */

integer c_n2;
integer c__2;
logical c_false;
integer c__1;
} zzekad02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c_n2;
integer c__1;
logical c_false;
integer c__0;
} zzekad03_init_t;

typedef struct {
/* Table of constant values */

integer c_n2;
integer c__1;
logical c_false;
integer c__0;
} zzekad03_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c_n2;
integer c__3;
logical c_false;
integer c__0;
} zzekad04_init_t;

typedef struct {
/* Table of constant values */

integer c_n2;
integer c__3;
logical c_false;
integer c__0;
} zzekad04_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c_n2;
integer c__2;
logical c_false;
integer c__0;
} zzekad05_init_t;

typedef struct {
/* Table of constant values */

integer c_n2;
integer c__2;
logical c_false;
integer c__0;
} zzekad05_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c_n2;
integer c__1;
logical c_false;
} zzekad06_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c_n2;
integer c__1;
logical c_false;
integer npad;
integer nrec;
integer room;
integer n;
integer p;
integer mbase;
integer pbase;
integer recno;
integer cvlen;
integer nchrs;
integer ncols;
integer lastw;
integer p2;
integer np;
char padbuf[100];
integer padlen;
integer colidx;
integer datptr;
integer eltidx;
integer mnroom;
integer nlinks;
integer nwrite;
integer ptrloc;
integer remain;
integer strlen;
integer wp;
logical fstpag;
logical pad;
integer pos;
} zzekad06_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} zzekaps_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} zzekaps_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
integer c__256;
integer c__11;
} zzekbs01_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
integer c__256;
integer c__11;
} zzekbs01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
integer c__256;
integer c__11;
} zzekbs02_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
integer c__256;
integer c__11;
} zzekbs02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__32;
} zzekcdsc_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__32;
} zzekcdsc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__32;
} zzekcnam_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__32;
} zzekcnam_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c_n1;
} zzekde01_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c_n1;
} zzekde01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c_n1;
} zzekde02_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c_n1;
} zzekde02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c_n1;
integer c__1;
} zzekde03_init_t;

typedef struct {
/* Table of constant values */

integer c_n1;
integer c__1;
} zzekde03_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c_n1;
integer c__3;
integer c__2;
} zzekde04_init_t;

typedef struct {
/* Table of constant values */

integer c_n1;
integer c__3;
integer c__2;
} zzekde04_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c_n1;
integer c__2;
} zzekde05_init_t;

typedef struct {
/* Table of constant values */

integer c_n1;
integer c__2;
} zzekde05_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c_n1;
integer c__1;
integer c__2;
} zzekde06_init_t;

typedef struct {
/* Table of constant values */

integer c_n1;
integer c__1;
integer c__2;
} zzekde06_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1014;
integer c__126;
integer c__254;
} zzekdps_init_t;

typedef struct {
/* Table of constant values */

integer c__1014;
integer c__126;
integer c__254;
} zzekdps_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__27869;
integer c__100;
integer c__500;
} zzekencd_init_t;

typedef struct {
/* Table of constant values */

integer c__27869;
integer c__100;
integer c__500;
} zzekencd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
doublereal c_b11;
integer c__0;
integer c__5;
} zzekerc1_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
doublereal c_b11;
integer c__0;
integer c__5;
} zzekerc1_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
integer c__2;
integer c__0;
integer c__5;
} zzekerd1_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
integer c__2;
integer c__0;
integer c__5;
} zzekerd1_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
doublereal c_b12;
integer c__5;
} zzekeri1_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
doublereal c_b12;
integer c__5;
} zzekeri1_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__2;
integer c__3;
integer c__254;
integer c__1014;
integer c__126;
} zzekff01_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__2;
integer c__3;
integer c__254;
integer c__1014;
integer c__126;
} zzekff01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} zzekfrx_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} zzekfrx_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__5;
} zzekgei_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__5;
} zzekgei_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__3;
logical c_false;
} zzekif01_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__3;
logical c_false;
} zzekif01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
logical c_false;
} zzekif02_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
logical c_false;
} zzekif02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__6;
} zzekinqc_init_t;

typedef struct {
/* Table of constant values */

integer c__6;
} zzekinqc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__6;
} zzekinqn_init_t;

typedef struct {
/* Table of constant values */

integer c__6;
} zzekinqn_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__100;
integer c__9;
integer c__10;
integer c__1;
integer c__0;
} zzekjoin_init_t;

typedef struct {
/* Table of constant values */

integer c__100;
integer c__9;
integer c__10;
integer c__1;
integer c__0;
} zzekjoin_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__4;
} zzekjsrt_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__4;
char cdat[32*250000];
doublereal ddat[250000];
integer idat[250000];
char nf[1*250000];
integer ordvec[250000];
} zzekjsrt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__24;
integer c__11;
integer c__1;
integer c__0;
integer c__7;
integer c__2;
integer c__5;
} zzekjtst_init_t;

typedef struct {
/* Table of constant values */

integer c__24;
integer c__11;
integer c__1;
integer c__0;
integer c__7;
integer c__2;
integer c__5;
integer base;
integer case__;
integer ltab;
logical done;
integer rtab;
integer lcol;
integer lseg;
integer rcol;
integer lelt;
integer rseg;
integer lcur;
integer relt;
integer lptr;
integer lrow;
integer rptr;
integer rrow;
integer svcp1[100];
integer svcp2[100];
integer svrb1;
integer svrb2;
integer i__;
integer j;
integer k;
integer svnr1;
integer svnr2;
integer svnt1;
integer svnt2;
integer jbase;
integer lbase;
integer rbase;
integer lhans[100];
integer lsdsc[2400]	/* was [24][100] */;
integer rhans[100];
integer rsdsc[2400]	/* was [24][100] */;
integer lelts[100];
integer cnstr;
integer relts[100];
integer dtptr;
integer lrows[100];
integer svops[100];
integer rrows[100];
integer svbas1;
integer svbas2;
integer rb;
integer nr;
integer nt;
logical locact[100];
integer addrss;
integer ldscrs[1100]	/* was [11][100] */;
integer lovbas;
integer lrvidx;
integer minirv[2];
integer offset;
integer nt3;
integer rdscrs[1100]	/* was [11][100] */;
integer rovbas;
integer rrvidx;
integer svncon;
integer tab;
integer top;
logical fnd;
logical lsmall;
} zzekjtst_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1000;
integer c__11;
} zzekkey_init_t;

typedef struct {
/* Table of constant values */

integer c__1000;
integer c__11;
} zzekkey_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
doublereal c_b16;
integer c__0;
logical c_false;
integer c__4;
} zzekllec_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
doublereal c_b16;
integer c__0;
logical c_false;
integer c__4;
} zzekllec_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
integer c__2;
integer c__0;
logical c_false;
integer c__4;
} zzeklled_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
integer c__2;
integer c__0;
logical c_false;
integer c__4;
} zzeklled_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
doublereal c_b17;
logical c_false;
integer c__4;
} zzekllei_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__1;
doublereal c_b17;
logical c_false;
integer c__4;
} zzekllei_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__1;
doublereal c_b16;
integer c__0;
logical c_false;
integer c__5;
} zzeklltc_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__1;
doublereal c_b16;
integer c__0;
logical c_false;
integer c__5;
} zzeklltc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__1;
integer c__0;
logical c_false;
integer c__5;
} zzeklltd_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__1;
integer c__0;
logical c_false;
integer c__5;
} zzeklltd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c__1;
integer c__3;
doublereal c_b17;
logical c_false;
integer c__5;
} zzekllti_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c__1;
integer c__3;
doublereal c_b17;
logical c_false;
integer c__5;
} zzekllti_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} zzekmloc_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} zzekmloc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} zzeknres_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} zzeknres_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer logops[3];
integer logcde[3];
integer cmpops[7];
integer cmpcde[8];
integer cmpneg[8];
integer endkw[3];
/* Table of constant values */

integer c__500;
integer c__1;
integer c__29;
integer c__5000;
integer c__3;
integer c__7;
integer c__8;
integer c__0;
} zzeknrml_init_t;

typedef struct {
integer logops[3];
integer logcde[3];
integer cmpops[7];
integer cmpcde[8];
integer cmpneg[8];
integer endkw[3];
/* Table of constant values */

integer c__500;
integer c__1;
integer c__29;
integer c__5000;
integer c__3;
integer c__7;
integer c__8;
integer c__0;
integer node;
integer tail;
integer rels[15000]	/* was [3][5000] */;
integer skip;
logical qual;
integer head1;
integer head2;
integer next;
integer prev;
integer type__;
integer b;
integer e;
integer i__;
integer j;
integer k;
integer nmeta;
integer level;
integer nconj;
integer newcj;
integer first;
integer newdj;
integer nrels;
integer sizes[1000];
integer start;
integer state;
integer third;
logical donow;
integer cj[4];
integer dj[2];
integer op;
integer rlpool[10012]	/* was [2][5006] */;
integer cjpool[10012]	/* was [2][5006] */;
integer cjptrs[5000];
integer djpool[10012]	/* was [2][5006] */;
integer djptrs[5000];
integer mtpool[1012]	/* was [2][506] */;
integer mtcode[500];
integer mtexpr[500];
integer mstart[500];
integer popcnd[500];
integer cjnode;
integer colptr;
integer djnode;
integer djtail;
integer dspool[10012]	/* was [2][5006] */;
integer dscbuf[35000]	/* was [7][5000] */;
integer endloc;
integer exprhd;
integer fourth;
integer lxb;
integer lxe;
integer metahd;
integer newrel;
integer rel[4];
integer relptr;
integer relset[5006];
integer retcnd;
integer rhsptr;
integer second;
integer tabptr;
integer whrbeg;
integer whrend;
integer whrsiz;
logical fnd;
} zzeknrml_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
doublereal c_b15;
integer c__128;
integer c__0;
integer c__256;
integer c__8;
integer c__2;
integer c__1024;
integer c__7;
integer c__12;
integer c__3;
integer c__13;
integer c__4;
integer c__9;
integer c__14;
integer c__6;
integer c__5;
integer c__11;
integer c__10;
integer c__16;
integer c__15;
} zzekpage_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
doublereal c_b15;
integer c__128;
integer c__0;
integer c__256;
integer c__8;
integer c__2;
integer c__1024;
integer c__7;
integer c__12;
integer c__3;
integer c__13;
integer c__4;
integer c__9;
integer c__14;
integer c__6;
integer c__5;
integer c__11;
integer c__10;
integer c__16;
integer c__15;
integer addr__;
integer e;
integer l;
integer freec;
integer freed;
char cfill[1024];
doublereal dfill[128];
integer freei;
integer ifill[256];
integer lastc;
integer lastd;
integer lasti;
doublereal dpptr;
char encpag[5];
integer nfreec;
integer nfreed;
integer nfreei;
integer forwrd;
integer npc;
integer npd;
integer npi;

} zzekpage_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__27869;
integer c__100;
integer c__1;
integer c__11;
integer c__6;
integer c__27;
integer c__29;
integer c__26;
integer c__0;
integer c__10;
integer c__50;
} zzekpars_init_t;

typedef struct {
/* Table of constant values */

integer c__27869;
integer c__100;
integer c__1;
integer c__11;
integer c__6;
integer c__27;
integer c__29;
integer c__26;
integer c__0;
integer c__10;
integer c__50;
} zzekpars_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__0;
} zzekpcol_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__0;
} zzekpcol_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char attkey[32*5];
integer reqkey[1];
/* Table of constant values */

integer c__11;
integer c__20;
integer c__0;
} zzekpdec_init_t;

typedef struct {
char attkey[32*5];
integer reqkey[1];
/* Table of constant values */

integer c__11;
integer c__20;
integer c__0;
} zzekpdec_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__8;
integer c__4;
integer c__9;
integer c__14;
} zzekpgch_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__8;
integer c__4;
integer c__9;
integer c__14;
} zzekpgch_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__27869;
integer c__100;
integer c__2000;
integer c__0;
integer c__19;
} zzekqini_init_t;

typedef struct {
/* Table of constant values */

integer c__27869;
integer c__100;
integer c__2000;
integer c__0;
integer c__19;
} zzekqini_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__24;
integer c__11;
} zzekrcmp_init_t;

typedef struct {
/* Table of constant values */

integer c__24;
integer c__11;
} zzekrcmp_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} zzekrd03_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} zzekrd03_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
} zzekrd04_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
} zzekrd04_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
} zzekrd05_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
} zzekrd05_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} zzekrd06_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} zzekrd06_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} zzekrd07_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} zzekrd07_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} zzekrd08_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} zzekrd08_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} zzekrd09_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} zzekrd09_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char namlst[32*15];
integer namidx[15];
/* Table of constant values */

integer c__15;
} zzekreqi_init_t;

typedef struct {
char namlst[32*15];
integer namidx[15];
/* Table of constant values */

integer c__15;
integer i__;
char tmpnam[32];
} zzekreqi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

logical c_false;
} zzekrmch_init_t;

typedef struct {
/* Table of constant values */

logical c_false;
} zzekrmch_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
integer t;
/* Table of constant values */

integer c__1;
integer c_b65;
} zzeksca_init_t;

typedef struct {
logical first;
integer t;
/* Table of constant values */

integer c__1;
integer c_b65;
integer base;
integer b;
integer e;
integer i__;
integer lastc;
integer lastd;
integer lasti;
integer numrd;
integer start;
integer rb;
integer rt;
integer numadd;
integer remain;
integer scrhan;
integer scrtch[2500000];
} zzeksca_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char keywds[32*29];
integer kwvals[29];
char spcstr[2*13];
integer spctok[13];
integer spcval[13];
logical pass1;
/* Table of constant values */

integer c__512;
integer c__2;
integer c__29;
integer c__13;
} zzekscan_init_t;

typedef struct {
char keywds[32*29];
integer kwvals[29];
char spcstr[2*13];
integer spctok[13];
integer spcval[13];
logical pass1;
/* Table of constant values */

integer c__512;
integer c__2;
integer c__29;
integer c__13;
integer last;
integer cptr;
integer room;
integer i__;
integer j;
integer l;
integer state;
integer nnums;
integer nstrs;
integer chcard;
integer idspec[518];
char hdchrs[80];
integer nchars;
integer length;
char tlchrs[80];
char tquery[2000];
char chr[1];
integer ptr;

} zzekscan_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__5;
} zzeksei_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__5;
} zzeksei_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char typstr[32*4];
/* Table of constant values */

integer c__1;
} zzeksemc_init_t;

typedef struct {
char typstr[32*4];
/* Table of constant values */

integer c__1;
} zzeksemc_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__64;
integer c__32;
} zzeksinf_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__64;
integer c__32;
} zzeksinf_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__0;
integer c__3;
} zzektcnv_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__0;
integer c__3;
} zzektcnv_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__83;
integer c__3;
integer c__256;
integer c__41;
integer c__42;
integer c__82;
} zzektr13_init_t;

typedef struct {
/* Table of constant values */

integer c__83;
integer c__3;
integer c__256;
integer c__41;
integer c__42;
integer c__82;
} zzektr13_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__10;
integer c__3;
integer c__256;
} zzektr1s_init_t;

typedef struct {
/* Table of constant values */

integer c__10;
integer c__3;
integer c__256;
} zzektr1s_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__125;
integer c__3;
integer c__256;
} zzektr23_init_t;

typedef struct {
/* Table of constant values */

integer c__125;
integer c__3;
integer c__256;
} zzektr23_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__81;
integer c__3;
} zzektr31_init_t;

typedef struct {
/* Table of constant values */

integer c__81;
integer c__3;
} zzektr31_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__122;
integer c__3;
} zzektr32_init_t;

typedef struct {
/* Table of constant values */

integer c__122;
integer c__3;
} zzektr32_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__82;
integer c__124;
} zzektrbn_init_t;

typedef struct {
/* Table of constant values */

integer c__82;
integer c__124;
} zzektrbn_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
} zzektrbs_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
} zzektrbs_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c_n1;
} zzektrdl_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c_n1;
} zzektrdl_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__4;
integer c__6;
integer c__1;
} zzektres_init_t;

typedef struct {
/* Table of constant values */

integer c__4;
integer c__6;
integer c__1;
} zzektres_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__10;
integer c__3;
} zzektrfr_init_t;

typedef struct {
/* Table of constant values */

integer c__10;
integer c__3;
} zzektrfr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} zzektrin_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} zzektrin_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__82;
integer c__83;
} zzektrit_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__82;
integer c__83;
} zzektrit_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
integer oldval;
integer page[256];
integer oldhan;
integer oldidx;
integer oldkey;
integer oldlvl;
integer oldmax;
integer oldnod;
integer oldnof;
integer oldtre;
} zzektrlk_init_t;

typedef struct {
logical first;
integer oldval;
integer page[256];
integer oldhan;
integer oldidx;
integer oldkey;
integer oldlvl;
integer oldmax;
integer oldnod;
integer oldnof;
integer oldtre;
logical leaf;
integer prev;
integer plus;
integer child;
integer depth;
logical found;
integer minus;
char access[15];
integer datbas;
integer newkey;
integer prvkey;
integer totkey;
logical samkey;
logical samtre;
logical rdonly;
} zzektrlk_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__40;
integer c__63;
} zzektrrk_init_t;

typedef struct {
/* Table of constant values */

integer c__40;
integer c__63;
} zzektrrk_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__63;
} zzektrud_init_t;

typedef struct {
/* Table of constant values */

integer c__63;
} zzektrud_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__63;
} zzektrui_init_t;

typedef struct {
/* Table of constant values */

integer c__63;
} zzektrui_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c_n2;
integer c_n1;
} zzekue01_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c_n2;
integer c_n1;
} zzekue01_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
integer c_n2;
integer c_n1;
} zzekue02_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
integer c_n2;
integer c_n1;
} zzekue02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__200;
integer c__10;
} zzekvadr_init_t;

typedef struct {
/* Table of constant values */

integer c__200;
integer c__10;
integer rbas[200];
integer i__;
integer j;
integer ntabs;
integer svbas[200];
integer begidx[200];
integer reloff;
integer addrss;
integer jrsidx;
integer maxrwv;
integer svnjrs;
integer top;
integer nsv;
} zzekvadr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__11;
integer c__24;
} zzekvcmp_init_t;

typedef struct {
/* Table of constant values */

integer c__11;
integer c__24;
} zzekvcmp_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__24;
integer c__11;
} zzekvmch_init_t;

typedef struct {
/* Table of constant values */

integer c__24;
integer c__11;
} zzekvmch_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} zzekweed_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} zzekweed_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char namlst[32*15];
integer namidx[15];
/* Table of constant values */

integer c__15;
} zzekweqi_init_t;

typedef struct {
char namlst[32*15];
integer namidx[15];
/* Table of constant values */

integer c__15;
integer i__;
char tmpnam[32];
} zzekweqi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} zzekwpac_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} zzekwpac_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__256;
} zzekwpai_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__256;
} zzekwpai_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} zzekwpal_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} zzekwpal_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal origin[3];
/* Table of constant values */

integer c__10000;
doublereal c_b79;
doublereal c_b90;
} zzelvupy_init_t;

typedef struct {
doublereal origin[3];
/* Table of constant values */

integer c__10000;
doublereal c_b79;
doublereal c_b90;
doublereal work[30000]	/* was [3][10000] */;
} zzelvupy_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__3;
} zzenut80_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__3;
} zzenut80_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__2;
} zzeprc76_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__2;
} zzeprc76_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__2;
} zzeprcss_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__2;
} zzeprcss_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__127;
} zzfdat_init_t;

typedef struct {
/* Table of constant values */

integer c__127;
} zzfdat_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
} zzfovaxi_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
} zzfovaxi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
} zzfrmch0_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
} zzfrmch0_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
} zzfrmch1_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
} zzfrmch1_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} zzfrmgt0_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} zzfrmgt0_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} zzfrmgt1_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} zzfrmgt1_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__1;
} zzftpchk_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__1;
char lftbkt[6];
char rgtbkt[6];
char memstr[16];
} zzftpchk_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char locdlm[1];
char loclnd[6];
char locrnd[6];
/* Table of constant values */

integer c__3;
integer c__2;
integer c__0;
} zzftpstr_init_t;

typedef struct {
logical first;
char locdlm[1];
char loclnd[6];
char locrnd[6];
/* Table of constant values */

integer c__3;
integer c__2;
integer c__0;
char locstr[16];
} zzftpstr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} zzgapool_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} zzgapool_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer int1st[4];
integer int2nd[4];
doublereal equiv_0[1];

} zzgetbff_init_t;

typedef struct {
integer int1st[4];
integer int2nd[4];
doublereal equiv_0[1];

} zzgetbff_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__3;
integer c__2;
integer c__4;
} zzgetelm_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__3;
integer c__2;
integer c__4;
doublereal ndd60;
char cday[32];
doublereal incl;
doublereal ndt20;
integer bexp;
integer year;
doublereal tvec[8];
char term[160*13];
integer nexp;
doublereal node0;
integer i__;
integer k;
char cndd60[32];
char cincl[32];
doublereal omega;
char cndt20[32];
char cyear[32];
char ciexp[32];
integer begyr;
doublereal bstar;
doublereal power[75];
char cnode0[32];
char comega[32];
doublereal mo;
doublereal no;
char cibexp[32];
integer yr;
char cbstar[32];
doublereal d2r;
doublereal pi2;
char errprs[160*13];
doublereal ecc;
doublereal day;
char cmo[32];
char cno[32];
integer ptr;
char cecc[32];

} zzgetelm_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char sysnms[32*7];
char crdnms[32*3*7];
integer prvctr;
integer prvobs;
integer prvtrg;
char obsnam[36];
char trgnam[36];
/* Table of constant values */

integer c__7;
integer c__3;
} zzgfcoq_init_t;

typedef struct {
logical first;
char sysnms[32*7];
char crdnms[32*3*7];
integer prvctr;
integer prvobs;
integer prvtrg;
char obsnam[36];
char trgnam[36];
/* Table of constant values */

integer c__7;
integer c__3;
char ctrnam[36];
} zzgfcoq_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char sysnms[32*7];
char crdnms[32*3*7];
doublereal y[3];
/* Table of constant values */

integer c__0;
integer c__1;
integer c__7;
integer c__3;
} zzgfcou_init_t;

typedef struct {
char sysnms[32*7];
char crdnms[32*3*7];
doublereal y[3];
/* Table of constant values */

integer c__0;
integer c__1;
integer c__7;
integer c__3;
doublereal svre;
char svcrd[32];
char svref[32];
integer svobs;
char svcorr[20];
char svcsys[32];
char svdref[32];
char svmeth[200];
char svrcnm[36];
char svvdef[32];
doublereal svdvec[3];
doublereal svradi[3];
integer svcidx;
integer svdctr;
integer svrctr;
integer svsens;
integer svtarg;
doublereal svf;
} zzgfcou_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
doublereal c_b15;
doublereal c_b39;
} zzgfcprx_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
doublereal c_b15;
doublereal c_b39;
} zzgfcprx_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} zzgfdiu_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
integer svobs;
integer svtarg;
char svcorr[5];
} zzgfdiu_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal svorig[3];
/* Table of constant values */

integer c__30000;
integer c__3;
integer c__20000;
integer c__9;
integer c__4;
integer c__0;
integer c__10000;
doublereal c_b100;
doublereal c_b130;
} zzgffvu_init_t;

typedef struct {
doublereal svorig[3];
/* Table of constant values */

integer c__30000;
integer c__3;
integer c__20000;
integer c__9;
integer c__4;
integer c__0;
integer c__10000;
doublereal c_b100;
doublereal c_b130;
integer svobs;
char svinam[36];
char svifrm[32];
char svishp[9];
char svtfrm[32];
char svtnam[36];
char svtshp[9];
char svcorr[5];
doublereal svarad;
doublereal svbnds[30000]	/* was [3][10000] */;
doublereal svedct[3];
doublereal svfaxi[3];
doublereal svfovm[9]	/* was [3][3] */;
doublereal svfpol[20000]	/* was [2][10000] */;
doublereal svfsmx[9]	/* was [3][3] */;
doublereal svfvct[3];
doublereal svplan[4];
doublereal svrdir[3];
doublereal svsemi[6]	/* was [3][2] */;
doublereal svtrad[3];
doublereal svxmag[2];
integer svinst;
integer svnvrt;
integer svtarg;
logical svuray;
logical svustl;
logical svxmit;
logical svxtrg;
} zzgffvu_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char angnms[50*3];
/* Table of constant values */

integer c__0;
integer c__3;
} zzgfilu_init_t;

typedef struct {
char angnms[50*3];
/* Table of constant values */

integer c__0;
integer c__3;
char svref[32];
integer svobs;
char svinam[36];
char svonam[36];
char svmeth[200];
char svtnam[36];
char svcorr[5];
doublereal svnrml[3];
integer svaidx;
integer svilum;
integer svtarg;
logical svablk[15];
doublereal svsspt[3];

} zzgfilu_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer ncalls;
doublereal svorig[3];
char svtyps[7*4];
/* Table of constant values */

integer c__100;
integer c__4;
integer c__0;
integer c__3;
doublereal c_b199;
} zzgfocu_init_t;

typedef struct {
integer ncalls;
doublereal svorig[3];
char svtyps[7*4];
/* Table of constant values */

integer c__100;
integer c__4;
integer c__0;
integer c__3;
doublereal c_b199;
integer svobs;
char svbfrm[32];
char svbmth[500];
char svbnam[36];
char svbshp[9];
char svcorr[5];
char svffrm[32];
char svfmth[500];
char svfnam[36];
char svfshp[9];
char svonam[36];
char svtype[7];
doublereal svbrad[3];
doublereal svfrad[3];
doublereal svmnbr;
doublereal svmnfr;
doublereal svmxbr;
doublereal svmxfr;
integer svback;
integer svfrnt;
} zzgfocu_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} zzgfpau_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
integer svobs;
char svabco[5];
logical svablk[15];
integer svillm;
integer svtarg;
} zzgfpau_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c_n2;
integer c__2;
} zzgfref_init_t;

typedef struct {
/* Table of constant values */

integer c_n2;
integer c__2;
} zzgfref_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer calls;
integer stdout;
doublereal step;
doublereal svincr;
integer svunit;
integer check;
doublereal done;
doublereal entire;
char finish[13];
logical first;
integer ls;
doublereal lstsec;
char start[55];
/* Table of constant values */

integer c__5;
integer c__1;
integer c__0;
doublereal c_b19;
doublereal c_b20;
} zzgfrpwk_init_t;

typedef struct {
integer calls;
integer stdout;
doublereal step;
doublereal svincr;
integer svunit;
integer check;
doublereal done;
doublereal entire;
char finish[13];
logical first;
integer ls;
doublereal lstsec;
char start[55];
/* Table of constant values */

integer c__5;
integer c__1;
integer c__0;
doublereal c_b19;
doublereal c_b20;
} zzgfrpwk_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} zzgfrru_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
doublereal svdt;
char svref[32];
integer svobs;
char svabco[5];
integer svtarg;
} zzgfrru_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1000;
} zzgfsolv_init_t;

typedef struct {
/* Table of constant values */

integer c__1000;
} zzgfsolv_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b12;
} zzgfspq_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b12;
} zzgfspq_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char svshap[32*2];
char ref[5];
/* Table of constant values */

integer c__0;
integer c__2;
} zzgfspu_init_t;

typedef struct {
char svshap[32*2];
char ref[5];
/* Table of constant values */

integer c__0;
integer c__2;
char svref[32];
integer svobs;
integer svbod1;
integer svbod2;
doublereal svrad1;
doublereal svrad2;
char svref1[32];
char svref2[32];
integer svshp1;
integer svshp2;
char svabcr[32];
} zzgfspu_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
integer prvobs;
integer prvtrg;
char svobs[36];
char svtarg[36];
/* Table of constant values */

integer c__3;
integer c__6;
doublereal c_b50;
} zzgfssin_init_t;

typedef struct {
logical first;
integer prvobs;
integer prvtrg;
char svobs[36];
char svtarg[36];
/* Table of constant values */

integer c__3;
integer c__6;
doublereal c_b50;
} zzgfssin_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
integer prvobs;
integer prvtrg;
char svobs[36];
char svtarg[36];
/* Table of constant values */

integer c__6;
integer c__3;
doublereal c_b40;
} zzgfssob_init_t;

typedef struct {
logical first;
integer prvobs;
integer prvtrg;
char svobs[36];
char svtarg[36];
/* Table of constant values */

integer c__6;
integer c__3;
doublereal c_b40;
} zzgfssob_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
} zzgftreb_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
} zzgftreb_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} zzgfwsts_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} zzgfwsts_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical init;
/* Table of constant values */

integer c__1;
integer c__4;
} zzholdd_init_t;

typedef struct {
logical init;
/* Table of constant values */

integer c__1;
integer c__4;
logical first[4];
doublereal svalue[4];
} zzholdd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} zzhsi_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} zzhsi_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b20;
doublereal c_b36;
} zzhullax_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b20;
doublereal c_b36;
} zzhullax_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

logical c_false;
integer c__36;
integer c__3;
integer c__6;
} zzilusta_init_t;

typedef struct {
/* Table of constant values */

logical c_false;
integer c__36;
integer c__3;
integer c__6;
} zzilusta_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
doublereal pi2;
/* Table of constant values */

doublereal c_b2;
} zzinlat0_init_t;

typedef struct {
logical first;
doublereal pi2;
/* Table of constant values */

doublereal c_b2;
} zzinlat0_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
doublereal pi2;
doublereal hpi;
/* Table of constant values */

doublereal c_b12;
} zzinlat_init_t;

typedef struct {
logical first;
doublereal pi2;
doublereal hpi;
/* Table of constant values */

doublereal c_b12;
} zzinlat_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
doublereal pi2;
/* Table of constant values */

doublereal c_b5;
} zzinpdt0_init_t;

typedef struct {
logical first;
doublereal pi2;
/* Table of constant values */

doublereal c_b5;
} zzinpdt0_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
doublereal hpi;
/* Table of constant values */

integer c__1;
doublereal c_b16;
} zzinpdt_init_t;

typedef struct {
logical first;
doublereal hpi;
/* Table of constant values */

integer c__1;
doublereal c_b16;
doublereal altbds[6]	/* was [2][3] */;
doublereal pi2;
} zzinpdt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

logical c_true;
} zzldker_init_t;

typedef struct {
/* Table of constant values */

logical c_true;
} zzldker_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} zzlexmet_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} zzlexmet_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c_b6;
integer c_b36;
doublereal c_b39;
integer c_b53;
} zzmkspin_init_t;

typedef struct {
/* Table of constant values */

integer c_b6;
integer c_b36;
doublereal c_b39;
integer c_b53;
integer cvid;
integer npcg;
doublereal vmod[3];
doublereal xmin;
doublereal ymin;
doublereal xmax;
doublereal ymax;
doublereal zmax;
doublereal zmin;
integer i__;
integer j;
integer q;
integer r__;
integer cgoff[3];
integer ncell;
doublereal bxmin;
doublereal bymin;
doublereal bxmax;
doublereal bymax;
doublereal bzmax;
doublereal bzmin;
integer gxmin;
integer gxmax;
integer gymax;
integer gymin;
doublereal avext;
integer gzmax;
integer gzmin;
logical inbox;
doublereal xvmin;
doublereal yvmin;
doublereal xvmax;
doublereal yvmax;
doublereal zvmax;
doublereal zvmin;
integer cgof1d;
integer cgxyz[3];
integer ixptr;
integer vixyz[3];
integer ncgflg;
integer ix;
integer iy;
integer iz;
integer to;
integer cgrdim[3];
integer nx;
doublereal xp[3];
doublereal yp[3];
doublereal zp[3];
integer ny;
integer nz;
doublereal mdltol;
integer vcoord[3];
doublereal cvxsiz;
doublereal xextnt[6];
} zzmkspin_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} zzmobliq_init_t;

typedef struct {
logical first;
doublereal year;
doublereal t;
doublereal persec;
doublereal rad;
} zzmobliq_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} zzmult_init_t;

typedef struct {
logical first;
doublereal loga;
doublereal logb;
doublereal expnt;
} zzmult_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__14;
integer c__1;
} zznofcon_init_t;

typedef struct {
/* Table of constant values */

integer c__14;
integer c__1;
} zznofcon_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal ctem;
doublereal delt;
doublereal pinc;
doublereal sghl;
logical cont;
doublereal sghs;
doublereal aqnv;
doublereal cosq;
doublereal temp;
doublereal stem;
doublereal eqsq;
doublereal sinq;
doublereal thgr;
doublereal xmao;
doublereal xnoi;
doublereal zmol;
doublereal zmos;
doublereal pinc0;
doublereal ainv2;
doublereal sini2;
doublereal temp1;
doublereal cosq2;
doublereal c__;
integer i__;
doublereal bfact;
doublereal alfdp;
doublereal jdtdb;
doublereal betdp;
doublereal atime;
doublereal theta;
doublereal xfact;
doublereal preep;
doublereal jdut50;
doublereal xincl;
doublereal cosiq;
doublereal cosok;
doublereal cosis;
doublereal xlamo;
doublereal a1;
doublereal a2;
doublereal a3;
doublereal a4;
doublereal a5;
doublereal a6;
doublereal a7;
doublereal a8;
doublereal a9;
doublereal e3;
doublereal f2;
doublereal f3;
doublereal siniq;
doublereal sinis;
doublereal sinok;
doublereal sinzf;
doublereal stepn;
doublereal s1;
doublereal s2;
doublereal s3;
doublereal s4;
doublereal s5;
doublereal s6;
doublereal s7;
doublereal stepp;
doublereal x1;
doublereal x2;
doublereal x3;
doublereal x4;
doublereal x5;
doublereal x6;
doublereal x7;
doublereal x8;
doublereal xldot;
doublereal xnddt;
doublereal xndot;
doublereal xqncl;
doublereal z1;
doublereal z2;
doublereal z3;
doublereal zcosg;
doublereal zcosh;
doublereal zcosi;
doublereal zsing;
doublereal zsinh;
doublereal zsini;
doublereal a10;
doublereal cc;
doublereal dg[10];
doublereal eo;
doublereal pe;
doublereal eq;
doublereal ph;
doublereal et;
doublereal ft;
doublereal se;
doublereal pl;
doublereal sh;
doublereal si;
doublereal sl;
doublereal z11;
doublereal z12;
doublereal z13;
doublereal z21;
doublereal xl;
doublereal z22;
doublereal omegao;
doublereal z23;
doublereal z31;
doublereal z32;
doublereal z33;
doublereal ze;
doublereal zf;
doublereal zm;
doublereal zn;
doublereal xnodce;
doublereal zx;
doublereal zy;
integer iresfl;
doublereal f220;
doublereal f221;
doublereal ee2;
doublereal f311;
doublereal f321;
doublereal cosomo;
doublereal f322;
doublereal f330;
doublereal f441;
doublereal f442;
doublereal f522;
doublereal f523;
doublereal f542;
doublereal f543;
doublereal g200;
doublereal g201;
doublereal g211;
doublereal g300;
doublereal g310;
doublereal g322;
doublereal g410;
doublereal g422;
doublereal g520;
doublereal g521;
doublereal g532;
doublereal g533;
doublereal oxnode;
doublereal pe0;
doublereal ph0;
doublereal pl0;
doublereal rteqsq;
doublereal se2;
doublereal se3;
doublereal sh2;
doublereal sh3;
doublereal si2;
doublereal si3;
doublereal sinomo;
doublereal sl2;
doublereal sl3;
doublereal sl4;
doublereal xh2;
doublereal xh3;
doublereal xi2;
doublereal xi3;
doublereal xl2;
doublereal xl3;
doublereal xl4;
doublereal xnodeo;
doublereal zcosgl;
doublereal zcoshl;
doublereal zcosil;
doublereal zsingl;
doublereal zsinhl;
doublereal zsinil;
integer isynfl;
doublereal gam;
doublereal del[3];
doublereal eoc;
doublereal ds50;
doublereal day;
doublereal pgh;
doublereal sgh;
doublereal sel;
doublereal bsq;
doublereal shl;
doublereal sil;
doublereal ses;
doublereal sll;
doublereal xli;
doublereal shs;
doublereal sis;
doublereal xni;
doublereal sls;
doublereal xmo;
doublereal xls;
doublereal xnq;
doublereal ssx[5];
doublereal pgh0;
doublereal sgh2;
doublereal sgh3;
doublereal sgh4;
doublereal xgh2;
doublereal xgh3;
doublereal xgh4;
doublereal pix1;
doublereal pix2;
doublereal xno2;

} zznrddp_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} zznrmlon_init_t;

typedef struct {
logical first;
doublereal pi2;
} zznrmlon_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b50;
doublereal c_b51;
integer c__9;
} zzocced_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b50;
doublereal c_b51;
integer c__9;
} zzocced_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal apex[3];
} zzpdcmpl_init_t;

typedef struct {
doublereal apex[3];
} zzpdcmpl_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b34;
} zzpdtbox_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b34;
} zzpdtbox_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
integer divisr;
} zzphsh_init_t;

typedef struct {
logical first;
integer divisr;
integer base;
integer f;
integer i__;
integer blank;
integer length;
integer maxdiv;
integer val[129];

} zzphsh_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__6;
} zzplatfm_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__6;
char keyval[64*6];
char attcpy[32*7];

} zzplatfm_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char corlst[5*15];
logical geo[15];
logical lt[15];
logical stl[15];
logical conv[15];
logical xmit[15];
logical rel[15];
logical first;
/* Table of constant values */

integer c__15;
integer c__0;
} zzprscor_init_t;

typedef struct {
char corlst[5*15];
logical geo[15];
logical lt[15];
logical stl[15];
logical conv[15];
logical xmit[15];
logical rel[15];
logical first;
/* Table of constant values */

integer c__15;
integer c__0;
} zzprscor_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
integer c__100;
} zzprsmet_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
integer c__100;
} zzprsmet_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal limit;
logical pass1;
integer prvdsc[8];
integer prvhan;
/* Table of constant values */

integer c__17;
integer c__1;
integer c__3;
integer c__18;
integer c__4;
integer c__5;
integer c__8;
integer c__0;
integer c__14;
integer c__10;
integer c__11;
integer c__9;
integer c__19;
} zzptpl02_init_t;

typedef struct {
doublereal limit;
logical pass1;
integer prvdsc[8];
integer prvhan;
/* Table of constant values */

integer c__17;
integer c__1;
integer c__3;
integer c__18;
integer c__4;
integer c__5;
integer c__8;
integer c__0;
integer c__14;
integer c__10;
integer c__11;
integer c__9;
integer c__19;
doublereal maxr;
doublereal voxori[3];
doublereal voxsiz;
integer cgrscl;
integer corsys;
integer vgrext[3];
} zzptpl02_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b73;
} zzraybox_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b73;
} zzraybox_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
} zzrefch0_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
} zzrefch0_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
} zzrefch1_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
} zzrefch1_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
} zzrepsub_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
} zzrepsub_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} zzrotgt0_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} zzrotgt0_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} zzrotgt1_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} zzrotgt1_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal z__[3];
/* Table of constant values */

integer c__9;
} zzrtnmat_init_t;

typedef struct {
doublereal z__[3];
/* Table of constant values */

integer c__9;
} zzrtnmat_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__32;
integer c__132;
} zzrvar_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__32;
integer c__132;
integer head;
integer code;
integer itab;
char name__[132];
char file[255];
integer free;
integer begs[132];
integer node;
char line[132];
integer tail;
integer ends[132];
logical even;
logical full;
integer type__[132];
integer b;
integer e;
integer i__;
integer j;
integer badat;
logical found;
integer ncomp;
integer lstnb;
integer count;
char error[255];
integer iplus;
integer r1;
integer r2;
integer at;
integer datahd;
integer iblank;
integer chnode;
integer icomma;
integer nameat;
integer dpnode;
integer iequal;
integer ilparn;
integer irparn;
integer itmark;
doublereal dvalue;
integer dirctv;
integer lookat;
integer iquote;
integer number;
integer varlen;
logical intokn;
logical insepf;
logical inquot;
integer status;
integer vartyp;
integer nxttok;
} zzrvar_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__32;
integer c__132;
} zzrvbf_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__32;
integer c__132;
integer head;
integer code;
integer itab;
char name__[132];
integer begs[132];
integer free;
integer node;
char line[132];
integer ends[132];
integer tail;
logical even;
logical full;
integer type__[132];
integer b;
integer e;
integer i__;
integer j;
integer badat;
logical found;
integer ncomp;
integer count;
char error[256];
integer iplus;
integer r1;
integer r2;
integer at;
integer datahd;
integer iblank;
integer chnode;
integer icomma;
integer nameat;
integer dpnode;
integer iequal;
doublereal dvalue;
integer ilparn;
integer irparn;
integer itmark;
integer dirctv;
integer lookat;
integer iquote;
integer varlen;
logical intokn;
logical insepf;
logical inquot;
integer status;
integer vartyp;
integer nxttok;
} zzrvbf_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal origin[3];
doublereal z__[3];
/* Table of constant values */

integer c__0;
doublereal c_b3;
integer c__3;
doublereal c_b5;
integer c__2;
doublereal c_b10;
integer c__1;
} zzrytlat_init_t;

typedef struct {
doublereal origin[3];
doublereal z__[3];
/* Table of constant values */

integer c__0;
doublereal c_b3;
integer c__3;
doublereal c_b5;
integer c__2;
doublereal c_b10;
integer c__1;
} zzrytlat_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal z__[3];
/* Table of constant values */

integer c__0;
doublereal c_b13;
integer c__3;
doublereal c_b21;
integer c__2;
doublereal c_b37;
integer c__1;
} zzrytpdt_init_t;

typedef struct {
doublereal z__[3];
/* Table of constant values */

integer c__0;
doublereal c_b13;
integer c__3;
doublereal c_b21;
integer c__2;
doublereal c_b37;
integer c__1;
} zzrytpdt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} zzrytrec_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} zzrytrec_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b2;
} zzryxsph_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b2;
} zzryxsph_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__10;
integer c__2;
integer c__7;
} zzsclk_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__10;
integer c__2;
integer c__7;
integer known[16];
integer passed[16];
integer dtsize[7];
} zzsclk_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__1;
doublereal c_b27;
} zzsfxcor_init_t;

typedef struct {
logical first;
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__1;
doublereal c_b27;
char loccor[5];
} zzsfxcor_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal z__[3];
/* Table of constant values */

doublereal c_b5;
} zzsglatx_init_t;

typedef struct {
doublereal z__[3];
/* Table of constant values */

doublereal c_b5;
} zzsglatx_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

doublereal c_b10;
doublereal c_b11;
doublereal c_b16;
doublereal c_b22;
logical c_false;
} zzsgp4_init_t;

typedef struct {
/* Table of constant values */

doublereal c_b10;
doublereal c_b11;
doublereal c_b16;
doublereal c_b22;
logical c_false;
doublereal ecco;
doublereal alta;
doublereal dedt;
doublereal con41;
doublereal didt;
doublereal dmdt;
doublereal pgho;
doublereal altp;
doublereal mdot;
doublereal j3oj2;
doublereal gsto;
doublereal zmol;
integer irez;
doublereal zmos;
doublereal t2cof;
doublereal t3cof;
doublereal t4cof;
doublereal t5cof;
doublereal a;
doublereal atime;
doublereal aycof;
doublereal inclo;
doublereal xfact;
doublereal pinco;
doublereal argpo;
doublereal xlcof;
doublereal xmcof;
doublereal bstar;
doublereal xlamo;
doublereal x1mth2;
doublereal delmo;
doublereal d2;
doublereal d3;
doublereal x7thm1;
doublereal e3;
doublereal d4;
doublereal dnodt;
doublereal domdt;
doublereal j2;
doublereal nodeo;
doublereal er;
doublereal mo;
doublereal no;
doublereal omgcof;
doublereal xnodcf;
doublereal cc1;
doublereal sinmao;
doublereal cc4;
doublereal cc5;
doublereal ee2;
doublereal se2;
doublereal se3;
doublereal sh2;
doublereal sh3;
doublereal xh2;
doublereal xh3;
doublereal xi2;
doublereal xi3;
doublereal xl2;
doublereal xl3;
doublereal xl4;
doublereal si2;
doublereal si3;
doublereal sl2;
doublereal sl3;
doublereal sl4;
doublereal d2201;
doublereal d2211;
doublereal d3210;
doublereal d3222;
doublereal d4410;
doublereal d5220;
doublereal d4422;
doublereal d5232;
doublereal d5421;
doublereal d5433;
doublereal eta;
integer svmode;
doublereal peo;
logical dosimp;
logical dodeep;
doublereal pho;
doublereal xke;
doublereal plo;
doublereal xli;
doublereal xni;
doublereal nodedot;
doublereal argpdot;
doublereal del1;
doublereal del2;
doublereal del3;
doublereal sgh2;
doublereal sgh3;
doublereal sgh4;
doublereal xgh2;
doublereal xgh3;
doublereal xgh4;
} zzsgp4_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
integer c__100;
} zzsinutl_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
integer c__100;
integer savfid;
doublereal savrad[3];
integer savnsf;
integer savsrf[100];
doublereal savmnr;
integer savtrg;
doublereal savmxr;
integer savtyp;
} zzsinutl_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__3;
doublereal c_b13;
} zzspkac0_init_t;

typedef struct {
logical first;
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__3;
doublereal c_b13;
logical usestl;
} zzspkac0_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__3;
doublereal c_b13;
} zzspkac1_init_t;

typedef struct {
logical first;
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__3;
doublereal c_b13;
logical usestl;
} zzspkac1_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char flags[5*9];
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__9;
integer c__6;
} zzspkap0_init_t;

typedef struct {
logical first;
char flags[5*9];
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__9;
integer c__6;
logical xmit;
logical usecn;
logical uselt;
logical usestl;
} zzspkap0_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char flags[5*9];
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__9;
integer c__6;
} zzspkap1_init_t;

typedef struct {
logical first;
char flags[5*9];
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__9;
integer c__6;
logical xmit;
logical usecn;
logical uselt;
logical usestl;
} zzspkap1_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char prvcor[5];
} zzspkas0_init_t;

typedef struct {
logical first;
char prvcor[5];
logical xmit;
logical uselt;
logical usestl;

} zzspkas0_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char prvcor[5];
} zzspkas1_init_t;

typedef struct {
logical first;
char prvcor[5];
logical xmit;
logical uselt;
logical usestl;

} zzspkas1_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char prvcor[5];
/* Table of constant values */

integer c__6;
} zzspkez0_init_t;

typedef struct {
logical first;
char prvcor[5];
/* Table of constant values */

integer c__6;
integer fj2000;
doublereal temp[6];
integer type__;
logical xmit;
integer i__;
logical found;
doublereal state[6];
char svref[32];
doublereal stobs[6];
doublereal xform[36]	/* was [6][6] */;
integer svctr1[2];
integer center;
logical attblk[15];
logical usegeo;
doublereal ltcent;
doublereal dltctr;
integer reqfrm;
integer ltsign;
integer typeid;
integer svreqf;
doublereal dlt;

} zzspkez0_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char prvcor[5];
/* Table of constant values */

integer c__6;
} zzspkez1_init_t;

typedef struct {
logical first;
char prvcor[5];
/* Table of constant values */

integer c__6;
integer fj2000;
doublereal temp[6];
integer type__;
logical xmit;
integer i__;
logical found;
doublereal state[6];
char svref[32];
doublereal stobs[6];
doublereal xform[36]	/* was [6][6] */;
integer svctr1[2];
integer center;
logical attblk[15];
logical usegeo;
doublereal ltcent;
doublereal dltctr;
integer reqfrm;
integer ltsign;
integer typeid;
integer svreqf;
doublereal dlt;

} zzspkez1_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical pass1;
char prvcor[5];
} zzspkfap_init_t;

typedef struct {
logical pass1;
char prvcor[5];
logical xmit;
logical uselt;
logical usestl;

} zzspkfap_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical pass1;
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__3;
doublereal c_b15;
} zzspkfat_init_t;

typedef struct {
logical pass1;
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__3;
doublereal c_b15;
logical usestl;
} zzspkfat_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__6;
integer c__0;
} zzspkgo0_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__6;
integer c__0;
char svref[32];
integer svctr1[2];
integer svrefi;
} zzspkgo0_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__6;
integer c__0;
} zzspkgo1_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__6;
integer c__0;
char svref[32];
integer svctr1[2];
integer svrefi;
} zzspkgo1_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__3;
integer c__6;
integer c__0;
} zzspkgp0_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__3;
integer c__6;
integer c__0;
char svref[32];
integer svctr1[2];
integer svrefi;
} zzspkgp0_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
/* Table of constant values */

integer c__3;
integer c__6;
integer c__0;
} zzspkgp1_init_t;

typedef struct {
logical first;
/* Table of constant values */

integer c__3;
integer c__6;
integer c__0;
char svref[32];
integer svctr1[2];
integer svrefi;
} zzspkgp1_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical pass1;
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__6;
doublereal c_b19;
} zzspklt0_init_t;

typedef struct {
logical pass1;
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__6;
doublereal c_b19;
logical xmit;
logical usecn;
logical uselt;
} zzspklt0_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical pass1;
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__6;
doublereal c_b19;
} zzspklt1_init_t;

typedef struct {
logical pass1;
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__6;
doublereal c_b19;
logical xmit;
logical usecn;
logical uselt;
} zzspklt1_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char flags[5*9];
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__9;
} zzspkpa0_init_t;

typedef struct {
logical first;
char flags[5*9];
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__9;
logical xmit;
logical usecn;
logical uselt;
logical usestl;
} zzspkpa0_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
char flags[5*9];
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__9;
} zzspkpa1_init_t;

typedef struct {
logical first;
char flags[5*9];
char prvcor[5];
/* Table of constant values */

integer c__0;
integer c__9;
logical xmit;
logical usecn;
logical uselt;
logical usestl;
} zzspkpa1_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} zzspkzp0_init_t;

typedef struct {
logical first;
integer fj2000;
doublereal temp[3];
doublereal sobs[6];
integer type__;
logical xmit;
integer i__;
logical found;
char svref[32];
doublereal xform[9]	/* was [3][3] */;
doublereal postn[3];
integer svctr1[2];
integer center;
doublereal ltcent;
integer reqfrm;
integer typeid;
integer svreqf;
} zzspkzp0_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
} zzspkzp1_init_t;

typedef struct {
logical first;
integer fj2000;
doublereal temp[3];
doublereal sobs[6];
integer type__;
logical xmit;
integer i__;
logical found;
char svref[32];
doublereal xform[9]	/* was [3][3] */;
doublereal postn[3];
integer svctr1[2];
integer center;
doublereal ltcent;
integer reqfrm;
integer typeid;
integer svreqf;
} zzspkzp1_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
} zzsrfini_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
} zzsrfini_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical pass1;
char names[32*3];
/* Table of constant values */

integer c__3;
integer c__2000;
integer c__1;
integer c__2003;
} zzsrfker_init_t;

typedef struct {
logical pass1;
char names[32*3];
/* Table of constant values */

integer c__3;
integer c__2000;
integer c__1;
integer c__2003;
} zzsrfker_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical extker;
integer polctr[2];
integer srfctr[2];
logical pass1;
/* Table of constant values */

integer c__1;
integer c__0;
} zzsrftrn_init_t;

typedef struct {
logical extker;
integer polctr[2];
integer srfctr[2];
logical pass1;
/* Table of constant values */

integer c__1;
integer c__0;
integer node;
integer nkvar;
integer kerbid[2000];
char kernam[36*2000];
integer kersid[2000];
integer sididx[2003];
integer sidhls[2003];
integer itemat;
integer lookat;
char nornam[36*2000];
integer sidpol[2009];
logical lupdte;
integer snmidx[2003];
char nsrfnm[36];
integer snmhls[2003];
integer snmpol[2009];
char sqshnm[36];
} zzsrftrn_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
doublereal c_b7;
} zzstelab_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
doublereal c_b7;
} zzstelab_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__0;
doublereal c_b9;
} zztangnt_init_t;

typedef struct {
/* Table of constant values */

integer c__0;
doublereal c_b9;
} zztangnt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
doublereal svet;
doublereal svirad;
doublereal svaxis[3];
doublereal svnrml[3];
integer svcurv;
doublereal svvrtx[3];

} zztanutl_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__6;
integer c__3;
integer c__1;
} zzteme_init_t;

typedef struct {
/* Table of constant values */

integer c__6;
integer c__3;
integer c__1;
} zzteme_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer size;
logical first;
char months[3*12];
/* Table of constant values */

integer c__1;
integer c__64;
integer c__320;
integer c__0;
integer c__12;
} zztime_init_t;

typedef struct {
integer size;
logical first;
char months[3*12];
/* Table of constant values */

integer c__1;
integer c__64;
integer c__320;
integer c__0;
integer c__12;
integer case__;
integer begs[64];
integer kind;
integer nsec;
integer ends[64];
logical ampm;
integer nday;
integer item;
integer from;
integer last;
integer nmin;
integer nmon;
char this__[1];
integer ndoy;
integer next;
integer f[95];
integer i__;
integer j;
integer k;
integer l[95];
logical check;
integer r__;
integer blank;
integer w;
integer nchar;
char recog[12*70];
integer pbegs[64];
char names[32*95];
char class__[1*70];
integer pends[64];
integer value;
integer nyear;
integer width[70];
char wkday[12*3*2];
integer pfrom;
char mnmrk[12*3*2];
char month[3];
integer nhour;
char myerr[32];
integer pnext;
integer p1;
integer p2;
integer to;
char spcial[12];
char messge[320];
char picerr[320];
char pictur[320];
char tknerr[320];
integer mnsize[2];
integer wksize[2];
logical did;
integer njd;
integer get;
char rep[64];
doublereal hms[3];
logical got;
integer pto;
integer ptr;
integer put;

} zztime_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer seqnce[5];
/* Table of constant values */

integer c__6;
integer c__3;
} zztwovxf_init_t;

typedef struct {
integer seqnce[5];
/* Table of constant values */

integer c__6;
integer c__3;
} zztwovxf_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__1;
} zzutcpm_init_t;

typedef struct {
/* Table of constant values */

integer c__1;
} zzutcpm_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
integer i__;
integer j;
integer ncell;
} zzvrtplt_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
char string[30];
integer exp__;
char myfill[1];
/* Table of constant values */

integer c__14;
} zzvstrng_init_t;

typedef struct {
char string[30];
integer exp__;
char myfill[1];
/* Table of constant values */

integer c__14;
integer code;
logical incr;
integer lsub;
integer slot;
integer code0;
integer i__;
integer j;
integer blank;
integer value;
logical minus;
char letter[1];

} zzvstrng_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
integer matrix[954]	/* was [9][106] */;
/* Table of constant values */

doublereal c_b2;
} zzwahr_init_t;

typedef struct {
logical first;
integer matrix[954]	/* was [9][106] */;
/* Table of constant values */

doublereal c_b2;
doublereal dddj;
integer i__;
integer j;
doublereal t;
doublereal angle[5];
doublereal rasec;
doublereal factr;
doublereal angrt[5];
doublereal argrt;
doublereal d0;
doublereal d1;
doublereal d2;
doublereal d3;
doublereal f0;
doublereal f1;
doublereal f2;
doublereal f3;
doublereal l0;
doublereal l1;
doublereal l2;
doublereal l3;
doublereal ce;
doublereal dd;
doublereal dj;
doublereal cl;
doublereal radian;
doublereal cosang;
doublereal oneday;
doublereal sinang;
doublereal dd2;
doublereal mg0;
doublereal mg1;
doublereal dtwopi;
doublereal mg2;
doublereal mg3;
doublereal lp0;
doublereal lp1;
doublereal lp2;
doublereal lp3;
doublereal arg;
doublereal dpi;
} zzwahr_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__2;
} zzwind2d_init_t;

typedef struct {
/* Table of constant values */

integer c__2;
} zzwind2d_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
/* Table of constant values */

integer c__3;
} zzwninsd_init_t;

typedef struct {
/* Table of constant values */

integer c__3;
} zzwninsd_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
integer natbff;
doublereal equiv_0[128];
/* Table of constant values */

integer c__4;
integer c__128;
} zzxlated_init_t;

typedef struct {
logical first;
integer natbff;
doublereal equiv_0[128];
/* Table of constant values */

integer c__4;
integer c__128;
integer bigint;
char strbff[8*4];
integer smlint;
} zzxlated_state_t;

/* -------------------------------------------------------------------------- */
typedef struct {
logical first;
integer natbff;
/* Table of constant values */

integer c__4;
} zzxlatei_init_t;

typedef struct {
logical first;
integer natbff;
/* Table of constant values */

integer c__4;
integer bigint;
char strbff[8*4];
integer smlint;
} zzxlatei_state_t;


/* -------------------------------------------------------------------------- */
typedef struct {
    f2c_state_t f2c;
	accept_state_t* accept;
	ana_state_t* ana;
	bedec_state_t* bedec;
	benum_state_t* benum;
	bltfrm_state_t* bltfrm;
	bodeul_state_t* bodeul;
	bodfnd_state_t* bodfnd;
	bodvar_state_t* bodvar;
	bodvcd_state_t* bodvcd;
	bodvrd_state_t* bodvrd;
	chgirf_state_t* chgirf;
	ckbsr_state_t* ckbsr;
	ckcov_state_t* ckcov;
	cke02_state_t* cke02;
	cke03_state_t* cke03;
	cke04_state_t* cke04;
	cke05_state_t* cke05;
	ckfrot_state_t* ckfrot;
	ckfxfm_state_t* ckfxfm;
	ckgpav_state_t* ckgpav;
	ckgp_state_t* ckgp;
	ckgr01_state_t* ckgr01;
	ckgr02_state_t* ckgr02;
	ckgr03_state_t* ckgr03;
	ckgr04_state_t* ckgr04;
	ckgr05_state_t* ckgr05;
	ckgr06_state_t* ckgr06;
	ckmeta_state_t* ckmeta;
	ckmp06_state_t* ckmp06;
	cknm06_state_t* cknm06;
	cknr01_state_t* cknr01;
	cknr02_state_t* cknr02;
	cknr03_state_t* cknr03;
	cknr04_state_t* cknr04;
	cknr05_state_t* cknr05;
	ckobj_state_t* ckobj;
	ckopn_state_t* ckopn;
	ckpfs_state_t* ckpfs;
	ckr01_state_t* ckr01;
	ckr02_state_t* ckr02;
	ckr03_state_t* ckr03;
	ckr04_state_t* ckr04;
	ckr05_state_t* ckr05;
	ckr06_state_t* ckr06;
	ckw01_state_t* ckw01;
	ckw02_state_t* ckw02;
	ckw03_state_t* ckw03;
	ckw04a_state_t* ckw04a;
	ckw04b_state_t* ckw04b;
	ckw04e_state_t* ckw04e;
	ckw05_state_t* ckw05;
	ckw06_state_t* ckw06;
	convrt_state_t* convrt;
	countc_state_t* countc;
	dafac_state_t* dafac;
	dafah_state_t* dafah;
	dafana_state_t* dafana;
	dafarr_state_t* dafarr;
	dafb2t_state_t* dafb2t;
	dafbt_state_t* dafbt;
	dafec_state_t* dafec;
	daffa_state_t* daffa;
	dafps_state_t* dafps;
	dafrcr_state_t* dafrcr;
	dafrrr_state_t* dafrrr;
	dafrwd_state_t* dafrwd;
	daft2b_state_t* daft2b;
	daftb_state_t* daftb;
	dafwcr_state_t* dafwcr;
	dafwda_state_t* dafwda;
	dafwfr_state_t* dafwfr;
	dasa2l_state_t* dasa2l;
	dasac_state_t* dasac;
	dasacr_state_t* dasacr;
	dasacu_state_t* dasacu;
	dasadc_state_t* dasadc;
	dasadd_state_t* dasadd;
	dasadi_state_t* dasadi;
	dasbt_state_t* dasbt;
	dascls_state_t* dascls;
	dascud_state_t* dascud;
	dasec_state_t* dasec;
	dasecu_state_t* dasecu;
	dasfm_state_t* dasfm;
	dasioc_state_t* dasioc;
	dasiod_state_t* dasiod;
	dasioi_state_t* dasioi;
	dasrcr_state_t* dasrcr;
	dasrdc_state_t* dasrdc;
	dasrdd_state_t* dasrdd;
	dasrdi_state_t* dasrdi;
	dasrwr_state_t* dasrwr;
	dassdr_state_t* dassdr;
	dastb_state_t* dastb;
	dasudc_state_t* dasudc;
	dasudd_state_t* dasudd;
	dasudi_state_t* dasudi;
	daswfr_state_t* daswfr;
	dcbrt_state_t* dcbrt;
	deltet_state_t* deltet;
	diags2_state_t* diags2;
	dlabbs_state_t* dlabbs;
	dlabfs_state_t* dlabfs;
	dlabns_state_t* dlabns;
	dlaens_state_t* dlaens;
	dlaopn_state_t* dlaopn;
	dnearp_state_t* dnearp;
	dp2hx_state_t* dp2hx;
	dpfmt_state_t* dpfmt;
	dpgrdr_state_t* dpgrdr;
	dpr_state_t* dpr;
	dpspce_state_t* dpspce;
	dpstr_state_t* dpstr;
	dpstrf_state_t* dpstrf;
	drdpgr_state_t* drdpgr;
	drotat_state_t* drotat;
	dskb02_state_t* dskb02;
	dskd02_state_t* dskd02;
	dski02_state_t* dski02;
	dskmi2_state_t* dskmi2;
	dskn02_state_t* dskn02;
	dskobj_state_t* dskobj;
	dskp02_state_t* dskp02;
	dskrb2_state_t* dskrb2;
	dsksrf_state_t* dsksrf;
	dsktol_state_t* dsktol;
	dskv02_state_t* dskv02;
	dskw02_state_t* dskw02;
	dskx02_state_t* dskx02;
	dskxsi_state_t* dskxsi;
	dskxv_state_t* dskxv;
	dskz02_state_t* dskz02;
	ducrss_state_t* ducrss;
	edlimb_state_t* edlimb;
	ednmpt_state_t* ednmpt;
	edterm_state_t* edterm;
	ekbseg_state_t* ekbseg;
	ekdelr_state_t* ekdelr;
	ekfind_state_t* ekfind;
	ekinsr_state_t* ekinsr;
	eknseg_state_t* eknseg;
	ekopn_state_t* ekopn;
	ekops_state_t* ekops;
	ekpsel_state_t* ekpsel;
	ekqmgr_state_t* ekqmgr;
	ekrcec_state_t* ekrcec;
	ekrced_state_t* ekrced;
	ekrcei_state_t* ekrcei;
	ekssum_state_t* ekssum;
	eqchr_state_t* eqchr;
	eqncpv_state_t* eqncpv;
	erract_state_t* erract;
	errch_state_t* errch;
	errdev_state_t* errdev;
	errdp_state_t* errdp;
	errhan_state_t* errhan;
	errint_state_t* errint;
	errprt_state_t* errprt;
	et2lst_state_t* et2lst;
	et2utc_state_t* et2utc;
	etcal_state_t* etcal;
	ev2lin_state_t* ev2lin;
	excess_state_t* excess;
	fndlun_state_t* fndlun;
	fovtrg_state_t* fovtrg;
	framex_state_t* framex;
	frmchg_state_t* frmchg;
	frmget_state_t* frmget;
	georec_state_t* georec;
	getfat_state_t* getfat;
	getfov_state_t* getfov;
	getmsg_state_t* getmsg;
	gfdist_state_t* gfdist;
	gfevnt_state_t* gfevnt;
	gfilum_state_t* gfilum;
	gfocce_state_t* gfocce;
	gfoclt_state_t* gfoclt;
	gfpa_state_t* gfpa;
	gfposc_state_t* gfposc;
	gfrfov_state_t* gfrfov;
	gfrprt_state_t* gfrprt;
	gfrr_state_t* gfrr;
	gfsep_state_t* gfsep;
	gfsntc_state_t* gfsntc;
	gfstep_state_t* gfstep;
	gfstol_state_t* gfstol;
	gfsubc_state_t* gfsubc;
	gftfov_state_t* gftfov;
	gfudb_state_t* gfudb;
	gfuds_state_t* gfuds;
	halfpi_state_t* halfpi;
	hx2dp_state_t* hx2dp;
	hx2int_state_t* hx2int;
	hyptof_state_t* hyptof;
	idw2at_state_t* idw2at;
	illum_state_t* illum;
	illumf_state_t* illumf;
	illumg_state_t* illumg;
	incnsg_state_t* incnsg;
	inedpl_state_t* inedpl;
	inelpl_state_t* inelpl;
	inrypl_state_t* inrypl;
	int2hx_state_t* int2hx;
	intord_state_t* intord;
	intstr_state_t* intstr;
	inttxt_state_t* inttxt;
	invert_state_t* invert;
	invort_state_t* invort;
	invstm_state_t* invstm;
	ioerr_state_t* ioerr;
	iso2utc_state_t* iso2utc;
	jul2gr_state_t* jul2gr;
	keeper_state_t* keeper;
	kplfrm_state_t* kplfrm;
	latsrf_state_t* latsrf;
	lbuild_state_t* lbuild;
	lcase_state_t* lcase;
	limbpt_state_t* limbpt;
	ljucrs_state_t* ljucrs;
	lnkfsl_state_t* lnkfsl;
	lnkhl_state_t* lnkhl;
	lnkila_state_t* lnkila;
	lnkilb_state_t* lnkilb;
	lnknxt_state_t* lnknxt;
	lnkprv_state_t* lnkprv;
	lnktl_state_t* lnktl;
	lnkxsl_state_t* lnkxsl;
	locln_state_t* locln;
	lparss_state_t* lparss;
	lspcn_state_t* lspcn;
	lx4uns_state_t* lx4uns;
	lxname_state_t* lxname;
	m2eul_state_t* m2eul;
	m2q_state_t* m2q;
	matchi_state_t* matchi;
	matchw_state_t* matchw;
	mequ_state_t* mequ;
	mtxm_state_t* mtxm;
	mxm_state_t* mxm;
	mxmt_state_t* mxmt;
	nearpt_state_t* nearpt;
	nparsd_state_t* nparsd;
	nparsi_state_t* nparsi;
	npedln_state_t* npedln;
	npelpt_state_t* npelpt;
	occult_state_t* occult;
	oscelt_state_t* oscelt;
	oscltx_state_t* oscltx;
	outmsg_state_t* outmsg;
	pck03b_state_t* pck03b;
	pckbsr_state_t* pckbsr;
	pckcov_state_t* pckcov;
	pcke03_state_t* pcke03;
	pckeul_state_t* pckeul;
	pckfrm_state_t* pckfrm;
	pckmat_state_t* pckmat;
	pckopn_state_t* pckopn;
	pckpds_state_t* pckpds;
	pckr02_state_t* pckr02;
	pckr03_state_t* pckr03;
	pckr20_state_t* pckr20;
	pckuds_state_t* pckuds;
	pckw02_state_t* pckw02;
	pckw20_state_t* pckw20;
	pgrrec_state_t* pgrrec;
	phaseq_state_t* phaseq;
	pi_state_t* pi;
	plnsns_state_t* plnsns;
	pool_state_t* pool;
	prompt_state_t* prompt;
	prop2b_state_t* prop2b;
	prtpkg_state_t* prtpkg;
	putact_state_t* putact;
	putdev_state_t* putdev;
	putlms_state_t* putlms;
	putsms_state_t* putsms;
	pxform_state_t* pxform;
	pxfrm2_state_t* pxfrm2;
	qdq2av_state_t* qdq2av;
	quote_state_t* quote;
	qxq_state_t* qxq;
	rdencc_state_t* rdencc;
	rdencd_state_t* rdencd;
	rdenci_state_t* rdenci;
	rdker_state_t* rdker;
	rdkvar_state_t* rdkvar;
	rdtext_state_t* rdtext;
	readln_state_t* readln;
	recpgr_state_t* recpgr;
	refchg_state_t* refchg;
	repsub_state_t* repsub;
	reset_state_t* reset;
	rotate_state_t* rotate;
	rotget_state_t* rotget;
	rotmat_state_t* rotmat;
	rotvec_state_t* rotvec;
	rpd_state_t* rpd;
	rquad_state_t* rquad;
	saelgv_state_t* saelgv;
	sc01_state_t* sc01;
	scdecd_state_t* scdecd;
	scencd_state_t* scencd;
	sclu01_state_t* sclu01;
	scpars_state_t* scpars;
	scpart_state_t* scpart;
	scps01_state_t* scps01;
	sctran_state_t* sctran;
	sctype_state_t* sctype;
	sepool_state_t* sepool;
	seterr_state_t* seterr;
	sgfcon_state_t* sgfcon;
	sgfpkt_state_t* sgfpkt;
	sgfref_state_t* sgfref;
	sgfrvi_state_t* sgfrvi;
	sgmeta_state_t* sgmeta;
	sgseqw_state_t* sgseqw;
	sigdgt_state_t* sigdgt;
	sigerr_state_t* sigerr;
	sincpt_state_t* sincpt;
	spcac_state_t* spcac;
	spcb2t_state_t* spcb2t;
	spcec_state_t* spcec;
	spcopn_state_t* spcopn;
	spcrfl_state_t* spcrfl;
	spct2b_state_t* spct2b;
	sphsd_state_t* sphsd;
	spk14b_state_t* spk14b;
	spkacs_state_t* spkacs;
	spkapo_state_t* spkapo;
	spkapp_state_t* spkapp;
	spkaps_state_t* spkaps;
	spkbsr_state_t* spkbsr;
	spkcov_state_t* spkcov;
	spkcpo_state_t* spkcpo;
	spkcpt_state_t* spkcpt;
	spkcvo_state_t* spkcvo;
	spkcvt_state_t* spkcvt;
	spke01_state_t* spke01;
	spke05_state_t* spke05;
	spke08_state_t* spke08;
	spke09_state_t* spke09;
	spke10_state_t* spke10;
	spke15_state_t* spke15;
	spke21_state_t* spke21;
	spkez_state_t* spkez;
	spkezp_state_t* spkezp;
	spkezr_state_t* spkezr;
	spkgeo_state_t* spkgeo;
	spkgps_state_t* spkgps;
	spkltc_state_t* spkltc;
	spkobj_state_t* spkobj;
	spkopn_state_t* spkopn;
	spkpds_state_t* spkpds;
	spkpos_state_t* spkpos;
	spkpv_state_t* spkpv;
	spkpvn_state_t* spkpvn;
	spkr01_state_t* spkr01;
	spkr02_state_t* spkr02;
	spkr03_state_t* spkr03;
	spkr05_state_t* spkr05;
	spkr08_state_t* spkr08;
	spkr09_state_t* spkr09;
	spkr10_state_t* spkr10;
	spkr14_state_t* spkr14;
	spkr15_state_t* spkr15;
	spkr17_state_t* spkr17;
	spkr18_state_t* spkr18;
	spkr19_state_t* spkr19;
	spkr20_state_t* spkr20;
	spkr21_state_t* spkr21;
	spks01_state_t* spks01;
	spks02_state_t* spks02;
	spks03_state_t* spks03;
	spks05_state_t* spks05;
	spks08_state_t* spks08;
	spks09_state_t* spks09;
	spks10_state_t* spks10;
	spks14_state_t* spks14;
	spks15_state_t* spks15;
	spks17_state_t* spks17;
	spks18_state_t* spks18;
	spks19_state_t* spks19;
	spks20_state_t* spks20;
	spks21_state_t* spks21;
	spksub_state_t* spksub;
	spkuds_state_t* spkuds;
	spkw01_state_t* spkw01;
	spkw02_state_t* spkw02;
	spkw03_state_t* spkw03;
	spkw05_state_t* spkw05;
	spkw08_state_t* spkw08;
	spkw09_state_t* spkw09;
	spkw10_state_t* spkw10;
	spkw12_state_t* spkw12;
	spkw13_state_t* spkw13;
	spkw15_state_t* spkw15;
	spkw17_state_t* spkw17;
	spkw18_state_t* spkw18;
	spkw19_state_t* spkw19;
	spkw20_state_t* spkw20;
	spkw21_state_t* spkw21;
	srfnrm_state_t* srfnrm;
	srfrec_state_t* srfrec;
	srfxpt_state_t* srfxpt;
	ssizec_state_t* ssizec;
	stcc01_state_t* stcc01;
	stcf01_state_t* stcf01;
	stcg01_state_t* stcg01;
	stcl01_state_t* stcl01;
	stelab_state_t* stelab;
	stmp03_state_t* stmp03;
	stpool_state_t* stpool;
	str2et_state_t* str2et;
	subpnt_state_t* subpnt;
	subpt_state_t* subpt;
	subslr_state_t* subslr;
	subsol_state_t* subsol;
	surfnm_state_t* surfnm;
	surfpt_state_t* surfpt;
	surfpv_state_t* surfpv;
	sxform_state_t* sxform;
	sydelc_state_t* sydelc;
	sydeld_state_t* sydeld;
	sydeli_state_t* sydeli;
	sydupc_state_t* sydupc;
	sydupd_state_t* sydupd;
	sydupi_state_t* sydupi;
	syenqc_state_t* syenqc;
	syenqd_state_t* syenqd;
	syenqi_state_t* syenqi;
	sypopc_state_t* sypopc;
	sypopd_state_t* sypopd;
	sypopi_state_t* sypopi;
	sypshc_state_t* sypshc;
	sypshd_state_t* sypshd;
	sypshi_state_t* sypshi;
	syputc_state_t* syputc;
	syputd_state_t* syputd;
	syputi_state_t* syputi;
	syrenc_state_t* syrenc;
	syrend_state_t* syrend;
	syreni_state_t* syreni;
	sysetc_state_t* sysetc;
	sysetd_state_t* sysetd;
	syseti_state_t* syseti;
	tcheck_state_t* tcheck;
	termpt_state_t* termpt;
	texpyr_state_t* texpyr;
	timdef_state_t* timdef;
	timout_state_t* timout;
	tisbod_state_t* tisbod;
	tkfram_state_t* tkfram;
	tostdo_state_t* tostdo;
	tparse_state_t* tparse;
	tpartv_state_t* tpartv;
	trcpkg_state_t* trcpkg;
	ttrans_state_t* ttrans;
	twopi_state_t* twopi;
	twovec_state_t* twovec;
	ucase_state_t* ucase;
	unitim_state_t* unitim;
	vprjp_state_t* vprjp;
	vprjpi_state_t* vprjpi;
	vrotv_state_t* vrotv;
	wncomd_state_t* wncomd;
	wnexpd_state_t* wnexpd;
	wninsd_state_t* wninsd;
	wnvald_state_t* wnvald;
	wrencc_state_t* wrencc;
	wrencd_state_t* wrencd;
	wrenci_state_t* wrenci;
	writln_state_t* writln;
	wrkvar_state_t* wrkvar;
	wrline_state_t* wrline;
	xdda_state_t* xdda;
	xf2eul_state_t* xf2eul;
	xfmsta_state_t* xfmsta;
	zzascii_state_t* zzascii;
	zzasryel_state_t* zzasryel;
	zzbodblt_state_t* zzbodblt;
	zzbodker_state_t* zzbodker;
	zzbodtrn_state_t* zzbodtrn;
	zzbquad_state_t* zzbquad;
	zzckcv04_state_t* zzckcv04;
	zzckspk_state_t* zzckspk;
	zzcnquad_state_t* zzcnquad;
	zzcorsxf_state_t* zzcorsxf;
	zzctr_state_t* zzctr;
	zzcvstat_state_t* zzcvstat;
	zzcxbrut_state_t* zzcxbrut;
	zzdafgdr_state_t* zzdafgdr;
	zzdafgfr_state_t* zzdafgfr;
	zzdafgsr_state_t* zzdafgsr;
	zzdafnfr_state_t* zzdafnfr;
	zzdasgrd_state_t* zzdasgrd;
	zzdasgri_state_t* zzdasgri;
	zzdasnfr_state_t* zzdasnfr;
	zzdasrfr_state_t* zzdasrfr;
	zzddhgsd_state_t* zzddhgsd;
	zzddhini_state_t* zzddhini;
	zzddhman_state_t* zzddhman;
	zzddhmnm_state_t* zzddhmnm;
	zzddhnfc_state_t* zzddhnfc;
	zzddhppf_state_t* zzddhppf;
	zzdiv_state_t* zzdiv;
	zzdskbbl_state_t* zzdskbbl;
	zzdskbun_state_t* zzdskbun;
	zzdskbux_state_t* zzdskbux;
	zzdsksba_state_t* zzdsksba;
	zzdsksbf_state_t* zzdsksbf;
	zzdsksbi_state_t* zzdsksbi;
	zzdsksbr_state_t* zzdsksbr;
	zzdsksel_state_t* zzdsksel;
	zzdsksgr_state_t* zzdsksgr;
	zzdsksph_state_t* zzdsksph;
	zzdynbid_state_t* zzdynbid;
	zzdynfid_state_t* zzdynfid;
	zzdynfr0_state_t* zzdynfr0;
	zzdynfrm_state_t* zzdynfrm;
	zzdynoac_state_t* zzdynoac;
	zzdynoad_state_t* zzdynoad;
	zzdynrot_state_t* zzdynrot;
	zzdynrt0_state_t* zzdynrt0;
	zzdynvac_state_t* zzdynvac;
	zzdynvad_state_t* zzdynvad;
	zzdynvai_state_t* zzdynvai;
	zzedterm_state_t* zzedterm;
	zzedtmpt_state_t* zzedtmpt;
	zzekac01_state_t* zzekac01;
	zzekac02_state_t* zzekac02;
	zzekac03_state_t* zzekac03;
	zzekac04_state_t* zzekac04;
	zzekac05_state_t* zzekac05;
	zzekac06_state_t* zzekac06;
	zzekac07_state_t* zzekac07;
	zzekac08_state_t* zzekac08;
	zzekac09_state_t* zzekac09;
	zzekacps_state_t* zzekacps;
	zzekad01_state_t* zzekad01;
	zzekad02_state_t* zzekad02;
	zzekad03_state_t* zzekad03;
	zzekad04_state_t* zzekad04;
	zzekad05_state_t* zzekad05;
	zzekad06_state_t* zzekad06;
	zzekaps_state_t* zzekaps;
	zzekbs01_state_t* zzekbs01;
	zzekbs02_state_t* zzekbs02;
	zzekcdsc_state_t* zzekcdsc;
	zzekcnam_state_t* zzekcnam;
	zzekde01_state_t* zzekde01;
	zzekde02_state_t* zzekde02;
	zzekde03_state_t* zzekde03;
	zzekde04_state_t* zzekde04;
	zzekde05_state_t* zzekde05;
	zzekde06_state_t* zzekde06;
	zzekdps_state_t* zzekdps;
	zzekencd_state_t* zzekencd;
	zzekerc1_state_t* zzekerc1;
	zzekerd1_state_t* zzekerd1;
	zzekeri1_state_t* zzekeri1;
	zzekff01_state_t* zzekff01;
	zzekfrx_state_t* zzekfrx;
	zzekgei_state_t* zzekgei;
	zzekif01_state_t* zzekif01;
	zzekif02_state_t* zzekif02;
	zzekinqc_state_t* zzekinqc;
	zzekinqn_state_t* zzekinqn;
	zzekjoin_state_t* zzekjoin;
	zzekjsrt_state_t* zzekjsrt;
	zzekjtst_state_t* zzekjtst;
	zzekkey_state_t* zzekkey;
	zzekllec_state_t* zzekllec;
	zzeklled_state_t* zzeklled;
	zzekllei_state_t* zzekllei;
	zzeklltc_state_t* zzeklltc;
	zzeklltd_state_t* zzeklltd;
	zzekllti_state_t* zzekllti;
	zzekmloc_state_t* zzekmloc;
	zzeknres_state_t* zzeknres;
	zzeknrml_state_t* zzeknrml;
	zzekpage_state_t* zzekpage;
	zzekpars_state_t* zzekpars;
	zzekpcol_state_t* zzekpcol;
	zzekpdec_state_t* zzekpdec;
	zzekpgch_state_t* zzekpgch;
	zzekqini_state_t* zzekqini;
	zzekrcmp_state_t* zzekrcmp;
	zzekrd03_state_t* zzekrd03;
	zzekrd04_state_t* zzekrd04;
	zzekrd05_state_t* zzekrd05;
	zzekrd06_state_t* zzekrd06;
	zzekrd07_state_t* zzekrd07;
	zzekrd08_state_t* zzekrd08;
	zzekrd09_state_t* zzekrd09;
	zzekreqi_state_t* zzekreqi;
	zzekrmch_state_t* zzekrmch;
	zzeksca_state_t* zzeksca;
	zzekscan_state_t* zzekscan;
	zzeksei_state_t* zzeksei;
	zzeksemc_state_t* zzeksemc;
	zzeksinf_state_t* zzeksinf;
	zzektcnv_state_t* zzektcnv;
	zzektr13_state_t* zzektr13;
	zzektr1s_state_t* zzektr1s;
	zzektr23_state_t* zzektr23;
	zzektr31_state_t* zzektr31;
	zzektr32_state_t* zzektr32;
	zzektrbn_state_t* zzektrbn;
	zzektrbs_state_t* zzektrbs;
	zzektrdl_state_t* zzektrdl;
	zzektres_state_t* zzektres;
	zzektrfr_state_t* zzektrfr;
	zzektrin_state_t* zzektrin;
	zzektrit_state_t* zzektrit;
	zzektrlk_state_t* zzektrlk;
	zzektrrk_state_t* zzektrrk;
	zzektrud_state_t* zzektrud;
	zzektrui_state_t* zzektrui;
	zzekue01_state_t* zzekue01;
	zzekue02_state_t* zzekue02;
	zzekvadr_state_t* zzekvadr;
	zzekvcmp_state_t* zzekvcmp;
	zzekvmch_state_t* zzekvmch;
	zzekweed_state_t* zzekweed;
	zzekweqi_state_t* zzekweqi;
	zzekwpac_state_t* zzekwpac;
	zzekwpai_state_t* zzekwpai;
	zzekwpal_state_t* zzekwpal;
	zzelvupy_state_t* zzelvupy;
	zzenut80_state_t* zzenut80;
	zzeprc76_state_t* zzeprc76;
	zzeprcss_state_t* zzeprcss;
	zzfdat_state_t* zzfdat;
	zzfovaxi_state_t* zzfovaxi;
	zzfrmch0_state_t* zzfrmch0;
	zzfrmch1_state_t* zzfrmch1;
	zzfrmgt0_state_t* zzfrmgt0;
	zzfrmgt1_state_t* zzfrmgt1;
	zzftpchk_state_t* zzftpchk;
	zzftpstr_state_t* zzftpstr;
	zzgapool_state_t* zzgapool;
	zzgetbff_state_t* zzgetbff;
	zzgetelm_state_t* zzgetelm;
	zzgfcoq_state_t* zzgfcoq;
	zzgfcou_state_t* zzgfcou;
	zzgfcprx_state_t* zzgfcprx;
	zzgfdiu_state_t* zzgfdiu;
	zzgffvu_state_t* zzgffvu;
	zzgfilu_state_t* zzgfilu;
	zzgfocu_state_t* zzgfocu;
	zzgfpau_state_t* zzgfpau;
	zzgfref_state_t* zzgfref;
	zzgfrpwk_state_t* zzgfrpwk;
	zzgfrru_state_t* zzgfrru;
	zzgfsolv_state_t* zzgfsolv;
	zzgfspq_state_t* zzgfspq;
	zzgfspu_state_t* zzgfspu;
	zzgfssin_state_t* zzgfssin;
	zzgfssob_state_t* zzgfssob;
	zzgftreb_state_t* zzgftreb;
	zzgfwsts_state_t* zzgfwsts;
	zzholdd_state_t* zzholdd;
	zzhsi_state_t* zzhsi;
	zzhullax_state_t* zzhullax;
	zzilusta_state_t* zzilusta;
	zzinlat0_state_t* zzinlat0;
	zzinlat_state_t* zzinlat;
	zzinpdt0_state_t* zzinpdt0;
	zzinpdt_state_t* zzinpdt;
	zzldker_state_t* zzldker;
	zzlexmet_state_t* zzlexmet;
	zzmkspin_state_t* zzmkspin;
	zzmobliq_state_t* zzmobliq;
	zzmult_state_t* zzmult;
	zznofcon_state_t* zznofcon;
	zznrddp_state_t* zznrddp;
	zznrmlon_state_t* zznrmlon;
	zzocced_state_t* zzocced;
	zzpdcmpl_state_t* zzpdcmpl;
	zzpdtbox_state_t* zzpdtbox;
	zzphsh_state_t* zzphsh;
	zzplatfm_state_t* zzplatfm;
	zzprscor_state_t* zzprscor;
	zzprsmet_state_t* zzprsmet;
	zzptpl02_state_t* zzptpl02;
	zzraybox_state_t* zzraybox;
	zzrefch0_state_t* zzrefch0;
	zzrefch1_state_t* zzrefch1;
	zzrepsub_state_t* zzrepsub;
	zzrotgt0_state_t* zzrotgt0;
	zzrotgt1_state_t* zzrotgt1;
	zzrtnmat_state_t* zzrtnmat;
	zzrvar_state_t* zzrvar;
	zzrvbf_state_t* zzrvbf;
	zzrytlat_state_t* zzrytlat;
	zzrytpdt_state_t* zzrytpdt;
	zzrytrec_state_t* zzrytrec;
	zzryxsph_state_t* zzryxsph;
	zzsclk_state_t* zzsclk;
	zzsfxcor_state_t* zzsfxcor;
	zzsglatx_state_t* zzsglatx;
	zzsgp4_state_t* zzsgp4;
	zzsinutl_state_t* zzsinutl;
	zzspkac0_state_t* zzspkac0;
	zzspkac1_state_t* zzspkac1;
	zzspkap0_state_t* zzspkap0;
	zzspkap1_state_t* zzspkap1;
	zzspkas0_state_t* zzspkas0;
	zzspkas1_state_t* zzspkas1;
	zzspkez0_state_t* zzspkez0;
	zzspkez1_state_t* zzspkez1;
	zzspkfap_state_t* zzspkfap;
	zzspkfat_state_t* zzspkfat;
	zzspkgo0_state_t* zzspkgo0;
	zzspkgo1_state_t* zzspkgo1;
	zzspkgp0_state_t* zzspkgp0;
	zzspkgp1_state_t* zzspkgp1;
	zzspklt0_state_t* zzspklt0;
	zzspklt1_state_t* zzspklt1;
	zzspkpa0_state_t* zzspkpa0;
	zzspkpa1_state_t* zzspkpa1;
	zzspkzp0_state_t* zzspkzp0;
	zzspkzp1_state_t* zzspkzp1;
	zzsrfini_state_t* zzsrfini;
	zzsrfker_state_t* zzsrfker;
	zzsrftrn_state_t* zzsrftrn;
	zzstelab_state_t* zzstelab;
	zztangnt_state_t* zztangnt;
	zztanutl_state_t* zztanutl;
	zzteme_state_t* zzteme;
	zztime_state_t* zztime;
	zztwovxf_state_t* zztwovxf;
	zzutcpm_state_t* zzutcpm;
	zzvrtplt_state_t* zzvrtplt;
	zzvstrng_state_t* zzvstrng;
	zzwahr_state_t* zzwahr;
	zzwind2d_state_t* zzwind2d;
	zzwninsd_state_t* zzwninsd;
	zzxlated_state_t* zzxlated;
	zzxlatei_state_t* zzxlatei;
#ifdef USER_T
	cspice_user_state_t user;
#endif
} cspice_t;

extern void* __cspice_allocate_module(int state_sz, void* init, int init_sz);
