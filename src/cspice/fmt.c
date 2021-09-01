#include "f2c.h"
#include "fio.h"
#include "fmt.h"
#include "__cspice_state.h"
#define skip(s) while(*s==' ') s++
#ifdef interdata
#define SYLMX 300
#endif
#ifdef pdp11
#define SYLMX 300
#endif
#ifdef vax
#define SYLMX 300
#endif
#ifndef SYLMX
#define SYLMX 300
#endif
#define GLITCH '\2'

 static
#ifdef KR_headers
char *ap_end(f2c, s) f2c_state_t *f2c; char *s;
#else
char *ap_end(f2c_state_t *f2c, char *s)
#endif
{	char quote;
	quote= *s++;
	for(;*s;s++)
	{	if(*s!=quote) continue;
		if(*++s!=quote) return(s);
	}
	if(f2c->f__elist->cierr) {
		errno = 100;
		return(NULL);
	}
	f__fatal(f2c, 100, "bad string");
	/*NOTREACHED*/ return 0;
}
 static
#ifdef KR_headers
op_gen(f2c,a,b,c,d)
#else
op_gen(f2c_state_t *f2c, int a, int b, int c, int d)
#endif
{	struct syl *p= &f2c->f__syl[f2c->f__pc];
	if(f2c->f__pc>=SYLMX)
	{	fprintf(stderr,"format too complicated:\n");
		sig_die(f2c->f__fmtbuf, 1);
	}
	p->op=a;
	p->p1=b;
	p->p2.i[0]=c;
	p->p2.i[1]=d;
	return(f2c->f__pc++);
}
#ifdef KR_headers
static char *f_list();
static char *gt_num(f2c,s,n,n1) char *s; int *n, n1;
#else
static char *f_list(f2c_state_t *f2c, char*);
static char *gt_num(char *s, int *n, int n1)
#endif
{	int m=0,f__cnt=0;
	char c;
	for(c= *s;;c = *s)
	{	if(c==' ')
		{	s++;
			continue;
		}
		if(c>'9' || c<'0') break;
		m=10*m+c-'0';
		f__cnt++;
		s++;
	}
	if(f__cnt==0) {
		if (!n1)
			s = 0;
		*n=n1;
		}
	else *n=m;
	return(s);
}

 static
#ifdef KR_headers
char *f_s(f2c, s,curloc) f2c_state_t *f2c; char *s;
#else
char *f_s(f2c_state_t *f2c, char *s, int curloc)
#endif
{
	skip(s);
	if(*s++!='(')
	{
		return(NULL);
	}
	if(f2c->f__parenlvl++ ==1) f2c->f__revloc=curloc;
	if(op_gen(f2c,RET1,curloc,0,0)<0 ||
		(s=f_list(f2c, s))==NULL)
	{
		return(NULL);
	}
	skip(s);
	return(s);
}

 static
#ifdef KR_headers
ne_d(f2c,s,p) f2c_state_t *f2c; char *s,**p;
#else
ne_d(f2c_state_t *f2c, char *s, char **p)
#endif
{	int n,x,sign=0;
	struct syl *sp;
	switch(*s)
	{
	default:
		return(0);
	case ':': (void) op_gen(f2c,COLON,0,0,0); break;
	case '$':
		(void) op_gen(f2c,NONL, 0, 0, 0); break;
	case 'B':
	case 'b':
		if(*++s=='z' || *s == 'Z') (void) op_gen(f2c,BZ,0,0,0);
		else (void) op_gen(f2c,BN,0,0,0);
		break;
	case 'S':
	case 's':
		if(*(s+1)=='s' || *(s+1) == 'S')
		{	x=SS;
			s++;
		}
		else if(*(s+1)=='p' || *(s+1) == 'P')
		{	x=SP;
			s++;
		}
		else x=S;
		(void) op_gen(f2c,x,0,0,0);
		break;
	case '/': (void) op_gen(f2c,SLASH,0,0,0); break;
	case '-': sign=1;
	case '+':	s++;	/*OUTRAGEOUS CODING TRICK*/
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		if (!(s=gt_num(s,&n,0))) {
 bad:			*p = 0;
			return 1;
			}
		switch(*s)
		{
		default:
			return(0);
		case 'P':
		case 'p': if(sign) n= -n; (void) op_gen(f2c,P,n,0,0); break;
		case 'X':
		case 'x': (void) op_gen(f2c,X,n,0,0); break;
		case 'H':
		case 'h':
			sp = &f2c->f__syl[op_gen(f2c,H,n,0,0)];
			sp->p2.s = s + 1;
			s+=n;
			break;
		}
		break;
	case GLITCH:
	case '"':
	case '\'':
		sp = &f2c->f__syl[op_gen(f2c,APOS,0,0,0)];
		sp->p2.s = s;
		if((*p = ap_end(f2c,s)) == NULL)
			return(0);
		return(1);
	case 'T':
	case 't':
		if(*(s+1)=='l' || *(s+1) == 'L')
		{	x=TL;
			s++;
		}
		else if(*(s+1)=='r'|| *(s+1) == 'R')
		{	x=TR;
			s++;
		}
		else x=T;
		if (!(s=gt_num(s+1,&n,0)))
			goto bad;
		s--;
		(void) op_gen(f2c,x,n,0,0);
		break;
	case 'X':
	case 'x': (void) op_gen(f2c,X,1,0,0); break;
	case 'P':
	case 'p': (void) op_gen(f2c,P,1,0,0); break;
	}
	s++;
	*p=s;
	return(1);
}

 static
#ifdef KR_headers
e_d(f2c,s,p) f2c_state_t *f2c; char *s,**p;
#else
e_d(f2c_state_t *f2c, char *s, char **p)
#endif
{	int i,im,n,w,d,e,found=0,x=0;
	char *sv=s;
	s=gt_num(s,&n,1);
	(void) op_gen(f2c,STACK,n,0,0);
	switch(*s++)
	{
	default: break;
	case 'E':
	case 'e':	x=1;
	case 'G':
	case 'g':
		found=1;
		if (!(s=gt_num(s,&w,0))) {
 bad:
			*p = 0;
			return 1;
			}
		if(w==0) break;
		if(*s=='.') {
			if (!(s=gt_num(s+1,&d,0)))
				goto bad;
			}
		else d=0;
		if(*s!='E' && *s != 'e')
			(void) op_gen(f2c,x==1?E:G,w,d,0);	/* default is Ew.dE2 */
		else {
			if (!(s=gt_num(s+1,&e,0)))
				goto bad;
			(void) op_gen(f2c,x==1?EE:GE,w,d,e);
			}
		break;
	case 'O':
	case 'o':
		i = O;
		im = OM;
		goto finish_I;
	case 'Z':
	case 'z':
		i = Z;
		im = ZM;
		goto finish_I;
	case 'L':
	case 'l':
		found=1;
		if (!(s=gt_num(s,&w,0)))
			goto bad;
		if(w==0) break;
		(void) op_gen(f2c,L,w,0,0);
		break;
	case 'A':
	case 'a':
		found=1;
		skip(s);
		if(*s>='0' && *s<='9')
		{	s=gt_num(s,&w,1);
			if(w==0) break;
			(void) op_gen(f2c,AW,w,0,0);
			break;
		}
		(void) op_gen(f2c,A,0,0,0);
		break;
	case 'F':
	case 'f':
		if (!(s=gt_num(s,&w,0)))
			goto bad;
		found=1;
		if(w==0) break;
		if(*s=='.') {
			if (!(s=gt_num(s+1,&d,0)))
				goto bad;
			}
		else d=0;
		(void) op_gen(f2c,F,w,d,0);
		break;
	case 'D':
	case 'd':
		found=1;
		if (!(s=gt_num(s,&w,0)))
			goto bad;
		if(w==0) break;
		if(*s=='.') {
			if (!(s=gt_num(s+1,&d,0)))
				goto bad;
			}
		else d=0;
		(void) op_gen(f2c,D,w,d,0);
		break;
	case 'I':
	case 'i':
		i = I;
		im = IM;
 finish_I:
		if (!(s=gt_num(s,&w,0)))
			goto bad;
		found=1;
		if(w==0) break;
		if(*s!='.')
		{	(void) op_gen(f2c,i,w,0,0);
			break;
		}
		if (!(s=gt_num(s+1,&d,0)))
			goto bad;
		(void) op_gen(f2c,im,w,d,0);
		break;
	}
	if(found==0)
	{	f2c->f__pc--; /*unSTACK*/
		*p=sv;
		return(0);
	}
	*p=s;
	return(1);
}
 static
#ifdef KR_headers
char *i_tem(f2c,s) f2c_state_t *f2c; char *s;
#else
char *i_tem(f2c_state_t *f2c, char *s)
#endif
{	char *t;
	int n,curloc;
	if(*s==')') return(s);
	if(ne_d(f2c,s,&t)) return(t);
	if(e_d(f2c,s,&t)) return(t);
	s=gt_num(s,&n,1);
	if((curloc=op_gen(f2c,STACK,n,0,0))<0) return(NULL);
	return(f_s(f2c,s,curloc));
}

 static
#ifdef KR_headers
char *f_list(f2c,s) f2c_state_t *f2c; char *s;
#else
char *f_list(f2c_state_t *f2c, char *s)
#endif
{
	for(;*s!=0;)
	{	skip(s);
		if((s=i_tem(f2c,s))==NULL) return(NULL);
		skip(s);
		if(*s==',') s++;
		else if(*s==')')
		{	if(--f2c->f__parenlvl==0)
			{
				(void) op_gen(f2c,REVERT,f2c->f__revloc,0,0);
				return(++s);
			}
			(void) op_gen(f2c,GOTO,0,0,0);
			return(++s);
		}
	}
	return(NULL);
}

#ifdef KR_headers
pars_f(f2c,s) f2c_state_t *f2c; char *s;
#else
pars_f(f2c_state_t *f2c, char *s)
#endif
{
	f2c->f__parenlvl=f2c->f__revloc=f2c->f__pc=0;
	if(f_s(f2c,s,0) == NULL)
	{
		return(-1);
	}
	return(0);
}

 static
#ifdef KR_headers
type_f(n)
#else
type_f(int n)
#endif
{
	switch(n)
	{
	default:
		return(n);
	case RET1:
		return(RET1);
	case REVERT: return(REVERT);
	case GOTO: return(GOTO);
	case STACK: return(STACK);
	case X:
	case SLASH:
	case APOS: case H:
	case T: case TL: case TR:
		return(NED);
	case F:
	case I:
	case IM:
	case A: case AW:
	case O: case OM:
	case L:
	case E: case EE: case D:
	case G: case GE:
	case Z: case ZM:
		return(ED);
	}
}
#ifdef KR_headers
integer do_fio(f2c,number,ptr,len) f2c_state_t *f2c; ftnint *number; ftnlen len; char *ptr;
#else
integer do_fio(f2c_state_t *f2c, ftnint *number, char *ptr, ftnlen len)
#endif
{	struct syl *p;
	int n,i;
	for(i=0;i<*number;i++,ptr+=len)
	{
loop:	switch(type_f((p= &f2c->f__syl[f2c->f__pc])->op))
	{
	default:
		fprintf(stderr,"unknown code in do_fio: %d\n%s\n",
			p->op,f2c->f__fmtbuf);
		err(f2c,f2c->f__elist->cierr,100,"do_fio");
	case NED:
		if((*f2c->f__doned)(f2c,p))
		{	f2c->f__pc++;
			goto loop;
		}
		f2c->f__pc++;
		continue;
	case ED:
		if(f2c->f__cnt[f2c->f__cp]<=0)
		{	f2c->f__cp--;
			f2c->f__pc++;
			goto loop;
		}
		if(ptr==NULL)
			return((*f2c->f__doend)(f2c));
		f2c->f__cnt[f2c->f__cp]--;
		f2c->f__workdone=1;
		if((n=(*f2c->f__doed)(f2c,p,ptr,len))>0)
			errfl(f2c,f2c->f__elist->cierr,errno,"fmt");
		if(n<0)
			err(f2c,f2c->f__elist->ciend,(EOF),"fmt");
		continue;
	case STACK:
		f2c->f__cnt[++f2c->f__cp]=p->p1;
		f2c->f__pc++;
		goto loop;
	case RET1:
		f2c->f__ret[++f2c->f__rp]=p->p1;
		f2c->f__pc++;
		goto loop;
	case GOTO:
		if(--f2c->f__cnt[f2c->f__cp]<=0)
		{	f2c->f__cp--;
			f2c->f__rp--;
			f2c->f__pc++;
			goto loop;
		}
		f2c->f__pc=1+f2c->f__ret[f2c->f__rp--];
		goto loop;
	case REVERT:
		f2c->f__rp=f2c->f__cp=0;
		f2c->f__pc = p->p1;
		if(ptr==NULL)
			return((*f2c->f__doend)(f2c));
		if(!f2c->f__workdone) return(0);
		if((n=(*f2c->f__dorevert)(f2c)) != 0) return(n);
		goto loop;
	case COLON:
		if(ptr==NULL)
			return((*f2c->f__doend)(f2c));
		f2c->f__pc++;
		goto loop;
	case NONL:
		f2c->f__nonl = 1;
		f2c->f__pc++;
		goto loop;
	case S:
	case SS:
		f2c->f__cplus=0;
		f2c->f__pc++;
		goto loop;
	case SP:
		f2c->f__cplus = 1;
		f2c->f__pc++;
		goto loop;
	case P:	f2c->f__scale=p->p1;
		f2c->f__pc++;
		goto loop;
	case BN:
		f2c->f__cblank=0;
		f2c->f__pc++;
		goto loop;
	case BZ:
		f2c->f__cblank=1;
		f2c->f__pc++;
		goto loop;
	}
	}
	return(0);
}
en_fio(f2c_state_t *f2c)
{	ftnint one=1;
	return(do_fio(f2c,&one,(char *)NULL,(ftnint)0));
}
 VOID
fmt_bg(f2c_state_t *f2c)
{
	f2c->f__workdone=f2c->f__cp=f2c->f__rp=f2c->f__pc=f2c->f__cursor=0;
	f2c->f__cnt[0]=f2c->f__ret[0]=0;
}
