#ifndef __F2C_FMT_H__
#define __F2C_FMT_H__
struct f2c_state_s;
struct syl
{	int op;
	int p1;
	union { int i[2]; char *s;} p2;
	};
#define RET1 1
#define REVERT 2
#define GOTO 3
#define X 4
#define SLASH 5
#define STACK 6
#define I 7
#define ED 8
#define NED 9
#define IM 10
#define APOS 11
#define H 12
#define TL 13
#define TR 14
#define T 15
#define COLON 16
#define S 17
#define SP 18
#define SS 19
#define P 20
#define BN 21
#define BZ 22
#define F 23
#define E 24
#define EE 25
#define D 26
#define G 27
#define GE 28
#define L 29
#define A 30
#define AW 31
#define O 32
#define NONL 33
#define OM 34
#define Z 35
#define ZM 36
typedef union
{	real pf;
	doublereal pd;
} ufloat;
typedef union
{	short is;
#ifndef KR_headers
	signed
#endif
		char ic;
	integer il;
#ifdef Allow_TYQUAD
	longint ili;
#endif
} Uint;
#ifdef KR_headers
extern int rd_ed(),rd_ned();
extern int w_ed(),w_ned();
#else
#ifdef __cplusplus
extern "C" {
#endif
extern void fmt_bg(struct f2c_state_s*);
extern int pars_f(struct f2c_state_s*,char*);
extern int rd_ed(struct f2c_state_s *,struct syl*, char*, ftnlen),rd_ned(struct f2c_state_s *, struct syl*);
extern int w_ed(struct f2c_state_s *, struct syl*, char*, ftnlen),w_ned(struct f2c_state_s *, struct syl*);
extern int wrt_E(struct f2c_state_s *, ufloat*, int, int, int, ftnlen);
extern int wrt_F(struct f2c_state_s *, ufloat*, int, int, ftnlen);
extern int wrt_L(struct f2c_state_s *, Uint*, int, ftnlen);
#ifdef __cplusplus
	}
#endif
#endif
#define GET(f2c, x) if((x=(*f2c->f__getn)(f2c))<0) return(x)
#define VAL(x) (x!='\n'?x:' ')
#define PUT(f2c, x) (*f2c->f__putn)(f2c,x)

#undef TYQUAD
#ifndef Allow_TYQUAD
#undef longint
#define longint long
#else
#define TYQUAD 14
#endif

#ifdef KR_headers
extern char *f__icvt();
#else
extern char *f__icvt(struct f2c_state_s*,longint, int*, int*, int);
#endif

#endif /* __F2C_FMT_H__ */
