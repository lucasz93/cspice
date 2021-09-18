#ifndef __FPROCS_H__
#define __FPROCS_H__

#ifdef KR_headers

extern double  f__cabs();
extern int     f__canseek();
extern char *  f__icvt();
extern void    f__fatal();
extern int     f__nowreading(), f__nowwriting(), err__fl(), f__putbuf();
extern long    f__inode();

extern void    b_char();

extern int     c_dfe(), c_due(), c_si(), c_sfe(), c_le(), c_sue();

extern double  c_abs();
extern void    c_cos(), c_div(), c_exp(), c_sin(), c_sqrt();

extern double  d_abs(), d_asin(), d_atan(), d_atn2();
extern void    d_cnjg();
extern double  d_cos(), d_dim(), d_exp(), d_imag(), d_int(), d_lg10(), d_log(), d_mod(), d_nint(), d_prod(), d_sign(), d_sin(), d_sinh(), d_sqrt(), d_tan(), d_tanh();

extern integer do_lio(), do_fio(), do_us(), do_ud(), do_uio();

extern double  derf_, dtime_();

extern integer e_rsli(), e_rsfi(), e_wsfi(), e_rdue(), e_wdue(), e_rsle(), e_rsfe(), e_wsfe(), e_wsue(), e_rsue(), e_wsle(), ef1asc_(), en_fio();
extern double  erf_(), etime_();
extern void    exit_();

extern char *  F77_aloc();

extern int     f_back(), f_clos(), f_end(), f_init(), f_inqu(), f_open(), fk_open(), f_rew();
extern void    f_exit();
extern int     ftell_(), fseek_();
extern int     flush_();
extern void    fmt_bg();

extern void    getenv_();

extern void    g_char();

extern shortint h_abs(), h_dim(), h_indx(), h_len(), h_mod(), h_nint(), h_sign();

extern shortlogical hl_ge(), hl_gt(), hl_le(), hl_lt();

extern integer i_abs(), i_dim(), i_dnnt(), i_indx(), i_len(), i_mod(), i_nint(), i_sign();

extern logical l_ge(), l_gt(), l_le(), l_lt();

extern int     l_read(), l_write();

extern integer lbit_bits(), lbit_cshift(), lbit_shift();

extern int     iw_rev();

extern double  r_abs(), r_acos(), r_asin(), r_atan(), r_atn2(), r_cos(), r_cosh(), r_dim(), r_exp(), r_imag(), r_int(), r_lg10(), r_log(), r_mod(), r_nint(), r_sign(), r_sin(), r_sinh(), r_sqrt(), r_tan(), r_tanh();
extern void    r_cnjg();

extern int     pars_f();
extern void    pow_ci(), pow_zi(), pow_zz();
extern double  pow_dd(), pow_di(), pow_ri();
extern shortint pow_hh();
extern integer pow_ii();

extern int     rd_ed(), rd_ned();

extern integer s_cmp();
extern int     s_cat(), s_copy(), s_paus(), s_stop();

extern integer s_rsfe(), s_rsfi(), s_wsfi(), s_rdfe(), s_wdfe(), s_rdue(), s_wdue(), s_wsni(), s_wsli(), s_rsle(), s_rsli(), s_rsni(), s_rsne(), s_rsue(), s_wsue(), s_wsle(), s_wsne(), s_wsfe();

extern int     t_getc(), t_runc();

extern int     w_ed();
extern int     w_ned();

extern int     wrt_E(), wrt_F(), wrt_L();

extern void    x_putc();
extern int     x_rsne();
extern int     x_wsne();

extern int     x_wSL();

extern int     z_getc(), z_rnew(), z_wnew();
extern void    z_putc();

extern double  z_abs();
extern void    z_cos(), z_div(), z_exp(), z_log(), z_sin(), z_sqrt();

#else

extern double  f__cabs(double, double);
extern int     f__canseek(FILE *f);
extern char *  f__icvt(struct f2c_state_s *f2c, longint value, int *ndigit, int *sign, int base);
extern void    f__fatal(struct f2c_state_s *f2c, int n, char *s);
extern int     f__nowreading(struct f2c_state_s *f2c, unit *x);
extern int     f__nowwriting(struct f2c_state_s *f2c, unit *x);
extern int     f__putbuf(struct f2c_state_s *f2c, int c);
extern long    f__inode(struct f2c_state_s *f2c, char *a, int *dev);
extern int     err__fl(struct f2c_state_s *f2c, int f, int m, char *s);

extern int     abort_(struct f2c_state_s *f2c);

extern void    b_char(struct f2c_state_s *f2c, char *a, char *b, ftnlen blen);

extern int     c_dfe(struct f2c_state_s *f2c, cilist *a);
extern int     c_due(struct f2c_state_s *f2c, cilist *a);
extern int     c_si(struct f2c_state_s *f2c, icilist *a);
extern int     c_sfe(struct f2c_state_s *f2c, cilist *a);
extern integer c_sue(struct f2c_state_s *f2c, cilist *a);
extern int     c_le(struct f2c_state_s *f2c, cilist *a);

extern double  c_abs(struct f2c_state_s *f2c, complex *z);
extern void    c_cos(struct f2c_state_s *f2c, complex *r, complex *z);
extern void    c_div(struct f2c_state_s *f2c, complex *c, complex *a, complex *b);
extern void    c_exp(struct f2c_state_s *f2c, complex *r, complex *z);
extern void    c_sin(struct f2c_state_s *f2c, complex *r, complex *z);
extern void    c_sqrt(struct f2c_state_s *f2c, complex *r, complex *z);

extern double  d_abs(struct f2c_state_s *f2c, doublereal *x);
extern double  d_asin(struct f2c_state_s *f2c, doublereal *x);
extern double  d_atan(struct f2c_state_s *f2c, doublereal *x);
extern double  d_atn2(struct f2c_state_s *f2c, doublereal *x, doublereal *y);
extern void    d_cnjg(struct f2c_state_s *f2c, doublecomplex *r, doublecomplex *z);
extern double  d_cos(struct f2c_state_s *f2c, doublereal *x);
extern double  d_dim(struct f2c_state_s *f2c, doublereal *a, doublereal *b);
extern double  d_exp(struct f2c_state_s *f2c, doublereal *x);
extern double  d_imag(struct f2c_state_s *f2c, doublecomplex *z);
extern double  d_int(struct f2c_state_s *f2c, doublereal *x);
extern double  d_lg10(struct f2c_state_s *f2c, doublereal *x);
extern double  d_log(struct f2c_state_s *f2c, doublereal *x);
extern double  d_mod(struct f2c_state_s *f2c, doublereal *x, doublereal *y);
extern double  d_nint(struct f2c_state_s *f2c, doublereal *x);
extern double  d_prod(struct f2c_state_s *f2c, real *x, real *y);
extern double  d_sign(struct f2c_state_s *f2c, doublereal *a, doublereal *b);
extern double  d_sin(struct f2c_state_s *f2c, doublereal *x);
extern double  d_sinh(struct f2c_state_s *f2c, doublereal *x);
extern double  d_sqrt(struct f2c_state_s *f2c, doublereal *x);
extern double  d_tan(struct f2c_state_s *f2c, doublereal *x);
extern double  d_tanh(struct f2c_state_s *f2c, doublereal *x);

extern integer do_lio(struct f2c_state_s *f2c, ftnint *type, ftnint *number, char *ptr, ftnlen len);
extern integer do_fio(struct f2c_state_s *f2c, ftnint *number, char *ptr, ftnlen len);
extern int     do_us(struct f2c_state_s *f2c, ftnint *number, char *ptr, ftnlen len);
extern integer do_ud(struct f2c_state_s *f2c, ftnint *number, char *ptr, ftnlen len);
extern integer do_uio(struct f2c_state_s *f2c, ftnint *number, char *ptr, ftnlen len);

extern double  derf_(struct f2c_state_s *f2c, doublereal *x);
extern double  dtime_(struct f2c_state_s *f2c, float *tarray);

extern integer e_rsli();
extern integer e_rsfi(struct f2c_state_s *f2c);
extern integer e_wsfi(struct f2c_state_s *f2c);
extern integer e_rdue(struct f2c_state_s *f2c);
extern integer e_wdue(struct f2c_state_s *f2c);
extern integer e_rsle(struct f2c_state_s *f2c);
extern integer e_rsfe(struct f2c_state_s *f2c);
extern integer e_wsfe(struct f2c_state_s *f2c);
extern integer e_wsue(struct f2c_state_s *f2c);
extern integer e_rsue(struct f2c_state_s *f2c);
extern integer e_wsle(struct f2c_state_s *f2c);

extern int     ef1asc_(struct f2c_state_s *f2c, ftnint *a, ftnlen *la, ftnint *b, ftnlen *lb);
extern int     en_fio(struct f2c_state_s *f2c);
extern double  erf_(struct f2c_state_s *f2c, real *x);
extern double  etime_(struct f2c_state_s *f2c, float *tarray);
extern void    exit_(struct f2c_state_s *f2c, integer *rc);

extern char *  F77_aloc(struct f2c_state_s *f2c, integer Len, char *whence);

extern integer f_back(struct f2c_state_s *f2c, alist *a);
extern integer f_clos(struct f2c_state_s *, cllist *a);
extern integer f_end(struct f2c_state_s *f2c, alist *a);
extern void    f_exit(struct f2c_state_s *);
extern void    f_init(struct f2c_state_s *f2c);
extern integer f_inqu(struct f2c_state_s *f2c, inlist *a);
extern integer f_open(struct f2c_state_s *f2c, olist *a);
extern int     fk_open(struct f2c_state_s *f2c, int seq, int fmt, ftnint n);
extern integer f_rew(struct f2c_state_s *f2c, alist *a);

extern integer ftell_(struct f2c_state_s *f2c, integer *Unit);
extern int     fseek_(struct f2c_state_s *f2c, integer *Unit, integer *offset, integer *whence);

extern int     flush_(struct f2c_state_s *f2c);
extern void    fmt_bg(struct f2c_state_s *f2c);

extern void    getenv_(struct f2c_state_s *f2c, char *fname, char *value, ftnlen flen, ftnlen vlen);

extern void    g_char(struct f2c_state_s *f2c, char *a, ftnlen alen, char *b);

extern shortint h_abs(struct f2c_state_s *f2c, shortint *x);
extern shortint h_dim(struct f2c_state_s *f2c, shortint *a, shortint *b);
extern shortint h_indx(struct f2c_state_s *f2c, char *a, char *b, ftnlen la, ftnlen lb);
extern shortint h_len(struct f2c_state_s *f2c, char *s, ftnlen n);
extern shortint h_mod(struct f2c_state_s *f2c, short *a, short *b);
extern shortint h_nint(struct f2c_state_s *f2c, real *x);
extern shortint h_sign(struct f2c_state_s *f2c, shortint *a, shortint *b);

extern shortlogical hl_ge(struct f2c_state_s *f2c, char *a, char *b, ftnlen la, ftnlen lb);
extern shortlogical hl_gt(struct f2c_state_s *f2c, char *a, char *b, ftnlen la, ftnlen lb);
extern shortlogical hl_le(struct f2c_state_s *f2c, char *a, char *b, ftnlen la, ftnlen lb);
extern shortlogical hl_lt(struct f2c_state_s *f2c, char *a, char *b, ftnlen la, ftnlen lb);

extern integer i_abs(struct f2c_state_s *f2c, integer *x);
extern integer i_dim(struct f2c_state_s *f2c, integer *a, integer *b);
extern integer i_dnnt(struct f2c_state_s *f2c, doublereal *x);
extern integer i_indx(struct f2c_state_s *f2c, char *a, char *b, ftnlen la, ftnlen lb);
extern integer i_len(struct f2c_state_s *f2c, char *s, ftnlen n);
extern integer i_mod(struct f2c_state_s *f2c, integer *a, integer *b);
extern integer i_nint(struct f2c_state_s *f2c, real *x);
extern integer i_sign(struct f2c_state_s *f2c, integer *a, integer *b);

extern logical l_ge(struct f2c_state_s *f2c, char *a, char *b, ftnlen la, ftnlen lb);
extern logical l_gt(struct f2c_state_s *f2c, char *a, char *b, ftnlen la, ftnlen lb);
extern logical l_le(struct f2c_state_s *f2c, char *a, char *b, ftnlen la, ftnlen lb);
extern logical l_lt(struct f2c_state_s *f2c, char *a, char *b, ftnlen la, ftnlen lb);

extern int     l_read(struct f2c_state_s *f2c, ftnint *number, char *ptr, ftnlen len, ftnint type);
extern int     l_write(struct f2c_state_s *f2c, ftnint *number, char *ptr, ftnlen len, ftnint type);

extern integer lbit_bits(struct f2c_state_s *f2c, integer a, integer b, integer len);
extern integer lbit_cshift(struct f2c_state_s *f2c, integer a, integer b, integer len);
extern integer lbit_shift(struct f2c_state_s *f2c, integer a, integer b);

extern int     iw_rev(struct f2c_state_s *f2c);

extern double  r_abs(struct f2c_state_s *f2c, real *x);
extern double  r_acos(struct f2c_state_s *f2c, real *x);
extern double  r_asin(struct f2c_state_s *f2c, real *x);
extern double  r_atan(struct f2c_state_s *f2c, real *x);
extern double  r_atn2(struct f2c_state_s *f2c, real *x, real *y);
extern void    r_cnjg(struct f2c_state_s *f2c, complex *r, complex *z);
extern double  r_cos(struct f2c_state_s *f2c, real *x);
extern double  r_cosh(struct f2c_state_s *f2c, real *x);
extern double  r_dim(struct f2c_state_s *f2c, real *a, real *b);
extern double  r_exp(struct f2c_state_s *f2c, real *x);
extern double  r_imag(struct f2c_state_s *f2c, complex *z);
extern double  r_int(struct f2c_state_s *f2c, real *x);
extern double  r_lg10(struct f2c_state_s *f2c, real *x);
extern double  r_log(struct f2c_state_s *f2c, real *x);
extern double  r_mod(struct f2c_state_s *f2c, real *x, real *y);
extern double  r_nint(struct f2c_state_s *f2c, real *x);
extern double  r_sign(struct f2c_state_s *f2c, real *a, real *b);
extern double  r_sin(struct f2c_state_s *f2c, real *x);
extern double  r_sinh(struct f2c_state_s *f2c, real *x);
extern double  r_sqrt(struct f2c_state_s *f2c, real *x);
extern double  r_tan(struct f2c_state_s *f2c, real *x);
extern double  r_tanh(struct f2c_state_s *f2c, real *x);

extern int     pars_f(struct f2c_state_s *f2c, char *s);
extern void    pow_ci(struct f2c_state_s *f2c, complex *p, complex *a, integer *b);
extern double  pow_dd(struct f2c_state_s *f2c, doublereal *ap, doublereal *bp);
extern double  pow_di(struct f2c_state_s *f2c, doublereal *ap, integer *bp);
extern shortint pow_hh(struct f2c_state_s *f2c, shortint *ap, shortint *bp);
extern integer pow_ii(struct f2c_state_s *f2c, integer *ap, integer *bp);
extern double  pow_ri(struct f2c_state_s *f2c, real *ap, integer *bp);
extern void    pow_zi(struct f2c_state_s *f2c, doublecomplex*, doublecomplex*, integer*);
extern void    pow_zz(struct f2c_state_s *f2c, doublecomplex *r, doublecomplex *a, doublecomplex *b);

extern int     rd_ed(struct f2c_state_s *f2c, struct syl *p, char *ptr, ftnlen len);
extern int     rd_ned(struct f2c_state_s *f2c, struct syl *p);

extern void    sig_die(struct f2c_state_s *f2c, register char *s, int kill);

extern int     s_cat(struct f2c_state_s *f2c, char *lp, char *rpp[], ftnlen rnp[], ftnlen *np, ftnlen ll);
extern integer s_cmp(struct f2c_state_s *,char*,char*,ftnlen,ftnlen);
extern int     s_copy(struct f2c_state_s *,char*,char*,ftnlen,ftnlen);
extern int     s_paus(struct f2c_state_s *f2c, char *s, ftnlen n);
extern int     s_stop(struct f2c_state_s *f2c, char *s, ftnlen n);

extern integer s_rsfe(struct f2c_state_s *f2c, cilist *a);
extern integer s_rsfi(struct f2c_state_s *f2c, icilist *a);
extern integer s_wsfi(struct f2c_state_s *f2c, icilist *a);
extern integer s_rdfe(struct f2c_state_s *f2c, cilist *a);
extern integer s_wdfe(struct f2c_state_s *f2c, cilist *a);
extern integer s_rdue(struct f2c_state_s *f2c, cilist *a);
extern integer s_wdue(struct f2c_state_s *f2c, cilist *a);
extern integer s_wsni(struct f2c_state_s *f2c, icilist *a);
extern integer s_wsli(struct f2c_state_s *f2c, icilist *a);
extern integer s_rsle(struct f2c_state_s *f2c, cilist *a);
extern integer s_rsli(struct f2c_state_s *f2c, icilist *a);
extern integer s_rsni(struct f2c_state_s *f2c, icilist *a);
extern integer s_rsne(struct f2c_state_s *f2c, cilist *a);
extern integer s_rsue(struct f2c_state_s *f2c, cilist *a);
extern integer s_wsue(struct f2c_state_s *f2c, cilist *a);
extern integer s_wsle(struct f2c_state_s *f2c, cilist *a);
extern integer s_wsne(struct f2c_state_s *f2c, cilist *a);
extern integer s_wsfe(struct f2c_state_s *f2c, cilist *a);

extern integer system_(struct f2c_state_s *f2c, register char *s, ftnlen n);

extern int     t_getc(struct f2c_state_s *f2c);
extern int     t_runc(struct f2c_state_s *f2c, alist *a);

extern int     w_ed(struct f2c_state_s *f2c, struct syl *p, char *ptr, ftnlen len);
extern int     w_ned(struct f2c_state_s *f2c, struct syl *p);

extern int     wrt_E(struct f2c_state_s *f2c, ufloat *p, int w, int d, int e, ftnlen len);
extern int     wrt_F(struct f2c_state_s *f2c, ufloat *p, int w, int d, ftnlen len);
extern int     wrt_L(struct f2c_state_s *f2c, Uint *n, int len, ftnlen sz);

extern void    x_putc(struct f2c_state_s *f2c, int c);
extern int     x_rsne(struct f2c_state_s *f2c, cilist *a);
extern void    x_wsne(struct f2c_state_s *f2c, cilist *a);

extern int     x_wSL(struct f2c_state_s *f2c);

extern int     z_getc(struct f2c_state_s *f2c);
extern void    z_putc(struct f2c_state_s *f2c, int c);
extern int     z_rnew(struct f2c_state_s *f2c);
extern int     z_wnew(struct f2c_state_s *f2c);

extern double  z_abs(struct f2c_state_s *f2c, doublecomplex *z);
extern void    z_cos(struct f2c_state_s *f2c, doublecomplex *r, doublecomplex *z);
extern void    z_div(struct f2c_state_s *f2c, doublecomplex*, doublecomplex*, doublecomplex*);
extern void    z_exp(struct f2c_state_s *f2c, doublecomplex *r, doublecomplex *z);
extern void    z_log(struct f2c_state_s *f2c, doublecomplex *r, doublecomplex *z);
extern void    z_sin(struct f2c_state_s *f2c, doublecomplex *r, doublecomplex *z);
extern void    z_sqrt(struct f2c_state_s *f2c, doublecomplex *r, doublecomplex *z);

#endif

#endif