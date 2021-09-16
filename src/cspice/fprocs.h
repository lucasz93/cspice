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

extern void    s_cat();
extern integer s_cmp();
extern void    s_copy();
extern int     s_paus(), s_stop();

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
extern char *  f__icvt(f2c_state_t *f2c, longint value, int *ndigit, int *sign, int base);
extern void    f__fatal(f2c_state_t *f2c, int n, char *s);
extern int     f__nowreading(f2c_state_t *f2c, unit *x);
extern int     f__nowwriting(f2c_state_t *f2c, unit *x);
extern int     f__putbuf(f2c_state_t *f2c, int c);
extern long    f__inode(f2c_state_t *f2c, char *a, int *dev);
extern int     err__fl(f2c_state_t *f2c, int f, int m, char *s);

extern void    b_char(f2c_state_t *f2c, char *a, char *b, ftnlen blen);

extern int     c_dfe(f2c_state_t *f2c, cilist *a);
extern int     c_due(f2c_state_t *f2c, cilist *a);
extern int     c_si(f2c_state_t *f2c, icilist *a);
extern int     c_sfe(f2c_state_t *f2c, cilist *a);
extern integer c_sue(f2c_state_t *f2c, cilist *a);
extern int     c_le(f2c_state_t *f2c, cilist *a);

extern double  c_abs(f2c_state_t *f2c, complex *z);
extern void    c_cos(f2c_state_t *f2c, complex *r, complex *z);
extern void    c_div(f2c_state_t *f2c, complex *c, complex *a, complex *b);
extern void    c_exp(f2c_state_t *f2c, complex *r, complex *z);
extern void    c_sin(f2c_state_t *f2c, complex *r, complex *z);
extern void    c_sqrt(f2c_state_t *f2c, complex *r, complex *z);

extern double  d_abs(f2c_state_t *f2c, doublereal *x);
extern double  d_asin(f2c_state_t *f2c, doublereal *x);
extern double  d_atan(f2c_state_t *f2c, doublereal *x);
extern double  d_atn2(f2c_state_t *f2c, doublereal *x, doublereal *y);
extern void    d_cnjg(f2c_state_t *f2c, doublecomplex *r, doublecomplex *z);
extern double  d_cos(f2c_state_t *f2c, doublereal *x);
extern double  d_dim(f2c_state_t *f2c, doublereal *a, doublereal *b);
extern double  d_exp(f2c_state_t *f2c, doublereal *x);
extern double  d_imag(f2c_state_t *f2c, doublecomplex *z);
extern double  d_int(f2c_state_t *f2c, doublereal *x);
extern double  d_lg10(f2c_state_t *f2c, doublereal *x);
extern double  d_log(f2c_state_t *f2c, doublereal *x);
extern double  d_mod(f2c_state_t *f2c, doublereal *x, doublereal *y);
extern double  d_nint(f2c_state_t *f2c, doublereal *x);
extern double  d_prod(f2c_state_t *f2c, real *x, real *y);
extern double  d_sign(f2c_state_t *f2c, doublereal *a, doublereal *b);
extern double  d_sin(f2c_state_t *f2c, doublereal *x);
extern double  d_sinh(f2c_state_t *f2c, doublereal *x);
extern double  d_sqrt(f2c_state_t *f2c, doublereal *x);
extern double  d_tan(f2c_state_t *f2c, doublereal *x);
extern double  d_tanh(f2c_state_t *f2c, doublereal *x);

extern integer do_lio(f2c_state_t *f2c, ftnint *type, ftnint *number, char *ptr, ftnlen len);
extern integer do_fio(f2c_state_t *f2c, ftnint *number, char *ptr, ftnlen len);
extern int     do_us(f2c_state_t *f2c, ftnint *number, char *ptr, ftnlen len);
extern integer do_ud(f2c_state_t *f2c, ftnint *number, char *ptr, ftnlen len);
extern integer do_uio(f2c_state_t *f2c, ftnint *number, char *ptr, ftnlen len);

extern double  derf_(f2c_state_t *f2c, doublereal *x);
extern double  dtime_(f2c_state_t *f2c, float *tarray);

extern integer e_rsli();
extern integer e_rsfi(f2c_state_t *f2c);
extern integer e_wsfi(f2c_state_t *f2c);
extern integer e_rdue(f2c_state_t *f2c);
extern integer e_wdue(f2c_state_t *f2c);
extern integer e_rsle(f2c_state_t *f2c);
extern integer e_rsfe(f2c_state_t *f2c);
extern integer e_wsfe(f2c_state_t *f2c);
extern integer e_wsue(f2c_state_t *f2c);
extern integer e_rsue(f2c_state_t *f2c);
extern integer e_wsle(f2c_state_t *f2c);

extern int     ef1asc_(f2c_state_t *f2c, ftnint *a, ftnlen *la, ftnint *b, ftnlen *lb);
extern int     en_fio(f2c_state_t *f2c);
extern double  erf_(f2c_state_t *f2c, real *x);
extern double  etime_(f2c_state_t *f2c, float *tarray);
extern void    exit_(f2c_state_t *f2c, integer *rc);

extern char *  F77_aloc(f2c_state_t *f2c, integer Len, char *whence);

extern integer f_back(f2c_state_t *f2c, alist *a);
extern integer f_clos(struct f2c_state_s *, cllist *a);
extern integer f_end(f2c_state_t *f2c, alist *a);
extern void    f_exit(struct f2c_state_s *);
extern void    f_init(f2c_state_t *f2c);
extern integer f_inqu(f2c_state_t *f2c, inlist *a);
extern integer f_open(f2c_state_t *f2c, olist *a);
extern int     fk_open(f2c_state_t *f2c, int seq, int fmt, ftnint n);
extern integer f_rew(f2c_state_t *f2c, alist *a);

extern integer ftell_(f2c_state_t *f2c, integer *Unit);
extern int     fseek_(f2c_state_t *f2c, integer *Unit, integer *offset, integer *whence);

extern int     flush_(f2c_state_t *f2c);
extern void    fmt_bg(f2c_state_t *f2c);

extern void    getenv_(f2c_state_t *f2c, char *fname, char *value, ftnlen flen, ftnlen vlen);

extern void    g_char(f2c_state_t *f2c, char *a, ftnlen alen, char *b);

extern shortint h_abs(f2c_state_t *f2c, shortint *x);
extern shortint h_dim(f2c_state_t *f2c, shortint *a, shortint *b);
extern shortint h_indx(f2c_state_t *f2c, char *a, char *b, ftnlen la, ftnlen lb);
extern shortint h_len(f2c_state_t *f2c, char *s, ftnlen n);
extern shortint h_mod(f2c_state_t *f2c, short *a, short *b);
extern shortint h_nint(f2c_state_t *f2c, real *x);
extern shortint h_sign(f2c_state_t *f2c, shortint *a, shortint *b);

extern shortlogical hl_ge(f2c_state_t *f2c, char *a, char *b, ftnlen la, ftnlen lb);
extern shortlogical hl_gt(f2c_state_t *f2c, char *a, char *b, ftnlen la, ftnlen lb);
extern shortlogical hl_le(f2c_state_t *f2c, char *a, char *b, ftnlen la, ftnlen lb);
extern shortlogical hl_lt(f2c_state_t *f2c, char *a, char *b, ftnlen la, ftnlen lb);

extern integer i_abs(f2c_state_t *f2c, integer *x);
extern integer i_dim(f2c_state_t *f2c, integer *a, integer *b);
extern integer i_dnnt(f2c_state_t *f2c, doublereal *x);
extern integer i_indx(f2c_state_t *f2c, char *a, char *b, ftnlen la, ftnlen lb);
extern integer i_len(f2c_state_t *f2c, char *s, ftnlen n);
extern integer i_mod(f2c_state_t *f2c, integer *a, integer *b);
extern integer i_nint(f2c_state_t *f2c, real *x);
extern integer i_sign(f2c_state_t *f2c, integer *a, integer *b);

extern logical l_ge(f2c_state_t *f2c, char *a, char *b, ftnlen la, ftnlen lb);
extern logical l_gt(f2c_state_t *f2c, char *a, char *b, ftnlen la, ftnlen lb);
extern logical l_le(f2c_state_t *f2c, char *a, char *b, ftnlen la, ftnlen lb);
extern logical l_lt(f2c_state_t *f2c, char *a, char *b, ftnlen la, ftnlen lb);

extern int     l_read(f2c_state_t *f2c, ftnint *number, char *ptr, ftnlen len, ftnint type);
extern int     l_write(f2c_state_t *f2c, ftnint *number, char *ptr, ftnlen len, ftnint type);

extern integer lbit_bits(f2c_state_t *f2c, integer a, integer b, integer len);
extern integer lbit_cshift(f2c_state_t *f2c, integer a, integer b, integer len);
extern integer lbit_shift(f2c_state_t *f2c, integer a, integer b);

extern int     iw_rev(f2c_state_t *f2c);

extern double  r_abs(f2c_state_t *f2c, real *x);
extern double  r_acos(f2c_state_t *f2c, real *x);
extern double  r_asin(f2c_state_t *f2c, real *x);
extern double  r_atan(f2c_state_t *f2c, real *x);
extern double  r_atn2(f2c_state_t *f2c, real *x, real *y);
extern void    r_cnjg(f2c_state_t *f2c, complex *r, complex *z);
extern double  r_cos(f2c_state_t *f2c, real *x);
extern double  r_cosh(f2c_state_t *f2c, real *x);
extern double  r_dim(f2c_state_t *f2c, real *a, real *b);
extern double  r_exp(f2c_state_t *f2c, real *x);
extern double  r_imag(f2c_state_t *f2c, complex *z);
extern double  r_int(f2c_state_t *f2c, real *x);
extern double  r_lg10(f2c_state_t *f2c, real *x);
extern double  r_log(f2c_state_t *f2c, real *x);
extern double  r_mod(f2c_state_t *f2c, real *x, real *y);
extern double  r_nint(f2c_state_t *f2c, real *x);
extern double  r_sign(f2c_state_t *f2c, real *a, real *b);
extern double  r_sin(f2c_state_t *f2c, real *x);
extern double  r_sinh(f2c_state_t *f2c, real *x);
extern double  r_sqrt(f2c_state_t *f2c, real *x);
extern double  r_tan(f2c_state_t *f2c, real *x);
extern double  r_tanh(f2c_state_t *f2c, real *x);

extern int     pars_f(f2c_state_t *f2c, char *s);
extern void    pow_ci(f2c_state_t *f2c, complex *p, complex *a, integer *b);
extern double  pow_dd(f2c_state_t *f2c, doublereal *ap, doublereal *bp);
extern double  pow_di(f2c_state_t *f2c, doublereal *ap, integer *bp);
extern shortint pow_hh(f2c_state_t *f2c, shortint *ap, shortint *bp);
extern integer pow_ii(f2c_state_t *f2c, integer *ap, integer *bp);
extern double  pow_ri(f2c_state_t *f2c, real *ap, integer *bp);
extern void    pow_zi(f2c_state_t *f2c, doublecomplex*, doublecomplex*, integer*);
extern void    pow_zz(f2c_state_t *f2c, doublecomplex *r, doublecomplex *a, doublecomplex *b);

extern int     rd_ed(f2c_state_t *f2c, struct syl *p, char *ptr, ftnlen len);
extern int     rd_ned(f2c_state_t *f2c, struct syl *p);

extern void    sig_die(f2c_state_t *f2c, register char *s, int kill);

extern void    s_cat(f2c_state_t *f2c, char *lp, char *rpp[], ftnlen rnp[], ftnlen *np, ftnlen ll);
extern integer s_cmp(struct f2c_state_s *,char*,char*,ftnlen,ftnlen);
extern void    s_copy(struct f2c_state_s *,char*,char*,ftnlen,ftnlen);
extern int     s_paus(f2c_state_t *f2c, char *s, ftnlen n);
extern int     s_stop(f2c_state_t *f2c, char *s, ftnlen n);

extern integer s_rsfe(f2c_state_t *f2c, cilist *a);
extern integer s_rsfi(f2c_state_t *f2c, icilist *a);
extern integer s_wsfi(f2c_state_t *f2c, icilist *a);
extern integer s_rdfe(f2c_state_t *f2c, cilist *a);
extern integer s_wdfe(f2c_state_t *f2c, cilist *a);
extern integer s_rdue(f2c_state_t *f2c, cilist *a);
extern integer s_wdue(f2c_state_t *f2c, cilist *a);
extern integer s_wsni(f2c_state_t *f2c, icilist *a);
extern integer s_wsli(f2c_state_t *f2c, icilist *a);
extern integer s_rsle(f2c_state_t *f2c, cilist *a);
extern integer s_rsli(f2c_state_t *f2c, icilist *a);
extern integer s_rsni(f2c_state_t *f2c, icilist *a);
extern integer s_rsne(f2c_state_t *f2c, cilist *a);
extern integer s_rsue(f2c_state_t *f2c, cilist *a);
extern integer s_wsue(f2c_state_t *f2c, cilist *a);
extern integer s_wsle(f2c_state_t *f2c, cilist *a);
extern integer s_wsne(f2c_state_t *f2c, cilist *a);
extern integer s_wsfe(f2c_state_t *f2c, cilist *a);

extern int     t_getc(f2c_state_t *f2c);
extern int     t_runc(f2c_state_t *f2c, alist *a);

extern int     w_ed(f2c_state_t *f2c, struct syl *p, char *ptr, ftnlen len);
extern int     w_ned(f2c_state_t *f2c, struct syl *p);

extern int     wrt_E(f2c_state_t *f2c, ufloat *p, int w, int d, int e, ftnlen len);
extern int     wrt_F(f2c_state_t *f2c, ufloat *p, int w, int d, ftnlen len);
extern int     wrt_L(f2c_state_t *f2c, Uint *n, int len, ftnlen sz);

extern void    x_putc(f2c_state_t *f2c, int c);
extern int     x_rsne(f2c_state_t *f2c, cilist *a);
extern void    x_wsne(f2c_state_t *f2c, cilist *a);

extern int     x_wSL(f2c_state_t *f2c);

extern int     z_getc(f2c_state_t *f2c);
extern void    z_putc(f2c_state_t *f2c, int c);
extern int     z_rnew(f2c_state_t *f2c);
extern int     z_wnew(f2c_state_t *f2c);

extern double  z_abs(f2c_state_t *f2c, doublecomplex *z);
extern void    z_cos(f2c_state_t *f2c, doublecomplex *r, doublecomplex *z);
extern void    z_div(f2c_state_t *f2c, doublecomplex*, doublecomplex*, doublecomplex*);
extern void    z_exp(f2c_state_t *f2c, doublecomplex *r, doublecomplex *z);
extern void    z_log(f2c_state_t *f2c, doublecomplex *r, doublecomplex *z);
extern void    z_sin(f2c_state_t *f2c, doublecomplex *r, doublecomplex *z);
extern void    z_sqrt(f2c_state_t *f2c, doublecomplex *r, doublecomplex *z);

#endif

#endif