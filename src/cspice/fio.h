#ifndef __F2C_FIO_H__
#define __F2C_FIO_H__

#include "stdio.h"
#include "errno.h"
#ifndef NULL
/* ANSI C */
#include "stddef.h"
#endif

struct f2c_state_s;

#ifndef SEEK_SET
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#endif

#ifdef MSDOS
#ifndef NON_UNIX_STDIO
#define NON_UNIX_STDIO
#endif
#endif

#ifdef UIOLEN_int
typedef int uiolen;
#else
typedef long uiolen;
#endif

/*units*/
typedef struct
{	FILE *ufd;	/*0=unconnected*/
	char *ufnm;
#ifndef MSDOS
	long uinode;
	int udev;
#endif
	int url;	/*0=sequential*/
	flag useek;	/*true=can backspace, use dir, ...*/
	flag ufmt;
	flag urw;	/* (1 for can read) | (2 for can write) */
	flag ublnk;
	flag uend;
	flag uwrt;	/*last io was write*/
	flag uscrtch;
} unit;

#undef Void
#ifdef KR_headers
#define Void /*void*/
extern void x_putc();
extern long f__inode();
extern VOID sig_die();
extern int t_putc(), x_wSL();
extern int c_sfe(), err__fl(), xrd_SL(), f__putbuf();
#else
#define Void void
#ifdef __cplusplus
extern "C" {
#endif
extern void x_putc(struct f2c_state_s *,int);
extern long f__inode(char*,int*);
extern void sig_die(char*,int);
extern void f__fatal(struct f2c_state_s*,int,char*);
extern int t_runc(struct f2c_state_s*,alist*);
extern int f__nowreading(struct f2c_state_s*,unit*), f__nowwriting(struct f2c_state_s*,unit*);
extern int fk_open(struct f2c_state_s*, int,int,ftnint);
extern int en_fio(struct f2c_state_s*);
extern void f_init(struct f2c_state_s*);
extern int t_putc(int), x_wSL(struct f2c_state_s *);
extern void b_char(char*,char*,ftnlen), g_char(char*,ftnlen,char*);
extern int c_sfe(struct f2c_state_s *,cilist*), z_rnew(struct f2c_state_s *);
extern int isatty(int);
extern int err__fl(struct f2c_state_s*,int,int,char*);
extern int xrd_SL(struct f2c_state_s *);
extern int f__putbuf(struct f2c_state_s *,int);
#ifdef __cplusplus
	}
#endif
#endif
#define err(f2c,f,m,s) {if(f) errno= m; else f__fatal(f2c,m,s); return(m);}
#define errfl(f2c,f,m,s) return err__fl(f2c,(int)f,m,s)

#define WRITE	1
#define READ	2
#define SEQ	3
#define DIR	4
#define FMT	5
#define UNF	6
#define EXT	7
#define INT	8

#define buf_end(x) (x->_flag & _IONBF ? x->_ptr : x->_base + BUFSIZ)

#endif /* __F2C_FIO_H__ */