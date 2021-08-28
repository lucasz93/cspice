#include "f2c.h"
#include "fio.h"
#include "lio.h"
#include "__cspice_state.h"

#define MAX_NL_CACHE 3	/* maximum number of namelist hash tables to cache */
#define MAXDIM 20	/* maximum number of subscripts */

 struct dimen {
	ftnlen extent;
	ftnlen curval;
	ftnlen delta;
	ftnlen stride;
	};
 typedef struct dimen dimen;

 extern ftnlen f__typesize[];

 extern t_getc(Void);

#ifdef KR_headers
 extern char *malloc(), *memset();

#ifdef ungetc
 static int
un_getc(x,f__cf) int x; FILE *f__cf;
{ return ungetc(x,f__cf); }
#else
#define un_getc ungetc
 extern int ungetc();
#endif

#else
#undef abs
#undef min
#undef max
#include "stdlib.h"
#include "string.h"

#ifdef ungetc
 static int
un_getc(int x, FILE *f__cf)
{ return ungetc(x,f__cf); }
#else
#define un_getc ungetc
extern int ungetc(int, FILE*);	/* for systems with a buggy stdio.h */
#endif
#endif

 static Vardesc *
#ifdef KR_headers
hash(f2c, ht, s) f2c_state_t *f2c; hashtab *ht; register char *s;
#else
hash(f2c_state_t *f2c, hashtab *ht, register char *s)
#endif
{
	register int c, x;
	register hashentry *h;
	char *s0 = s;

	for(x = 0; c = *s++; x = x & 0x4000 ? ((x << 1) & 0x7fff) + 1 : x << 1)
		x += c;
	for(h = *(f2c->zot = ht->tab + x % ht->htsize); h; h = h->next)
		if (!strcmp(s0, h->name))
			return h->vd;
	return 0;
	}

 hashtab *
#ifdef KR_headers
mk_hashtab(f2c, nl) f2c_state_t *f2c; Namelist *nl;
#else
mk_hashtab(f2c_state_t *f2c, Namelist *nl)
#endif
{
	int nht, nv;
	hashtab *ht;
	Vardesc *v, **vd, **vde;
	hashentry *he;

	hashtab **x, **x0, *y;
	for(x = &f2c->nl_cache; y = *x; x0 = x, x = &y->next)
		if (nl == y->nl)
			return y;
	if (f2c->n_nlcache >= MAX_NL_CACHE) {
		/* discard least recently used namelist hash table */
		y = *x0;
		free((char *)y->next);
		y->next = 0;
		}
	else
		f2c->n_nlcache++;
	nv = nl->nvars;
	if (nv >= 0x4000)
		nht = 0x7fff;
	else {
		for(nht = 1; nht < nv; nht <<= 1);
		nht += nht - 1;
		}
	ht = (hashtab *)malloc(sizeof(hashtab) + (nht-1)*sizeof(hashentry *)
				+ nv*sizeof(hashentry));
	if (!ht)
		return 0;
	he = (hashentry *)&ht->tab[nht];
	ht->nl = nl;
	ht->htsize = nht;
	ht->next = f2c->nl_cache;
	f2c->nl_cache = ht;
	memset((char *)ht->tab, 0, nht*sizeof(hashentry *));
	vd = nl->vars;
	vde = vd + nv;
	while(vd < vde) {
		v = *vd++;
		if (!hash(f2c, ht, v->name)) {
			he->next = *f2c->zot;
			*f2c->zot = he;
			he->name = v->name;
			he->vd = v;
			he++;
			}
		}
	return ht;
	}

 static VOID
nl_init(f2c_state_t *f2c) {
	register char *s;
	register int c;

	if(!f2c->f__init)
		f_init();
	for(s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; c = *s++; )
		f2c->Alpha[c]
		= f2c->Alphanum[c]
		= f2c->Alpha[c + 'a' - 'A']
		= f2c->Alphanum[c + 'a' - 'A']
		= c;
	for(s = "0123456789_"; c = *s++; )
		f2c->Alphanum[c] = c;
	}

#define GETC(f2c,x) (x=(*f2c->l_getc)())
#define Ungetc(f2c,x,y) (*f2c->l_ungetc)(x,y)

 static int
#ifdef KR_headers
getname(f2c, s, slen) f2c_state_t *f2c; register char *s; int slen;
#else
getname(f2c_state_t *f2c, register char *s, int slen)
#endif
{
	register char *se = s + slen - 1;
	register int ch;

	GETC(f2c, ch);
	if (!(*s++ = f2c->Alpha[ch & 0xff])) {
		if (ch != EOF)
			ch = 115;
		errfl(f2c->f__elist->cierr, ch, "namelist read");
		}
	while(*s = f2c->Alphanum[GETC(f2c, ch) & 0xff])
		if (s < se)
			s++;
	if (ch == EOF)
		err(f2c->f__elist->cierr, EOF, "namelist read");
	if (ch > ' ')
		Ungetc(f2c, ch, f2c->f__cf);
	return *s = 0;
	}

 static int
#ifdef KR_headers
getnum(f2c, chp, val) f2c_state_t *f2c; int *chp; ftnlen *val;
#else
getnum(f2c_state_t *f2c, int *chp, ftnlen *val)
#endif
{
	register int ch, sign;
	register ftnlen x;

	while(GETC(f2c, ch) <= ' ' && ch >= 0);
	if (ch == '-') {
		sign = 1;
		GETC(f2c, ch);
		}
	else {
		sign = 0;
		if (ch == '+')
			GETC(f2c, ch);
		}
	x = ch - '0';
	if (x < 0 || x > 9)
		return 115;
	while(GETC(f2c, ch) >= '0' && ch <= '9')
		x = 10*x + ch - '0';
	while(ch <= ' ' && ch >= 0)
		GETC(f2c, ch);
	if (ch == EOF)
		return EOF;
	*val = sign ? -x : x;
	*chp = ch;
	return 0;
	}

 static int
#ifdef KR_headers
getdimen(f2c, chp, d, delta, extent, x1)
 f2c_state_t *f2c; int *chp; dimen *d; ftnlen delta, extent, *x1;
#else
getdimen(f2c_state_t *f2c, int *chp, dimen *d, ftnlen delta, ftnlen extent, ftnlen *x1)
#endif
{
	register int k;
	ftnlen x2, x3;

	if (k = getnum(f2c, chp, x1))
		return k;
	x3 = 1;
	if (*chp == ':') {
		if (k = getnum(f2c, chp, &x2))
			return k;
		x2 -= *x1;
		if (*chp == ':') {
			if (k = getnum(f2c, chp, &x3))
				return k;
			if (!x3)
				return 123;
			x2 /= x3;
			f2c->colonseen = 1;
			}
		if (x2 < 0 || x2 >= extent)
			return 123;
		d->extent = x2 + 1;
		}
	else
		d->extent = 1;
	d->curval = 0;
	d->delta = delta;
	d->stride = x3;
	return 0;
	}

#ifndef No_Namelist_Questions
 static Void
#ifdef KR_headers
print_ne(f2c, a) f2c_state_t *f2c; cilist *a;
#else
print_ne(f2c_state_t *f2c, cilist *a)
#endif
{
	flag intext = f2c->f__external;
	int rpsave = f2c->f__recpos;
	FILE *cfsave = f2c->f__cf;
	unit *usave = f2c->f__curunit;
	cilist t;
	t = *a;
	t.ciunit = 6;
	s_wsne(&t);
	fflush(f2c->f__cf);
	f2c->f__external = intext;
	f2c->f__reading = 1;
	f2c->f__recpos = rpsave;
	f2c->f__cf = cfsave;
	f2c->f__curunit = usave;
	f2c->f__elist = a;
	}
#endif

 static char where0[] = "namelist read start ";

#ifdef KR_headers
x_rsne(f2c, a) f2c_state_t *f2c; cilist *a;
#else
x_rsne(f2c_state_t *f2c, cilist *a)
#endif
{
	int ch, got1, k, n, nd, quote, readall;
	Namelist *nl;
	static char where[] = "namelist read";
	char buf[64];
	hashtab *ht;
	Vardesc *v;
	dimen *dn, *dn0, *dn1;
	ftnlen *dims, *dims1;
	ftnlen b, b0, b1, ex, no, no1, nomax, size, span;
	ftnint type;
	char *vaddr;
	long iva, ivae;
	dimen dimens[MAXDIM], substr;

	if (!f2c->Alpha['a'])
		nl_init(f2c);
	f2c->f__reading=1;
	f2c->f__formatted=1;
	got1 = 0;
 top:
	for(;;) switch(GETC(f2c, ch)) {
		case EOF:
 eof:
			err(a->ciend,(EOF),where0);
		case '&':
		case '$':
			goto have_amp;
#ifndef No_Namelist_Questions
		case '?':
			print_ne(f2c, a);
			continue;
#endif
		default:
			if (ch <= ' ' && ch >= 0)
				continue;
#ifndef No_Namelist_Comments
			while(GETC(f2c, ch) != '\n')
				if (ch == EOF)
					goto eof;
#else
			errfl(a->cierr, 115, where0);
#endif
		}
 have_amp:
	if (ch = getname(f2c, buf,sizeof(buf)))
		return ch;
	nl = (Namelist *)a->cifmt;
	if (strcmp(buf, nl->name))
#ifdef No_Bad_Namelist_Skip
		errfl(a->cierr, 118, where0);
#else
	{
		fprintf(stderr,
			"Skipping namelist \"%s\": seeking namelist \"%s\".\n",
			buf, nl->name);
		fflush(stderr);
		for(;;) switch(GETC(f2c, ch)) {
			case EOF:
				err(a->ciend, EOF, where0);
			case '/':
			case '&':
			case '$':
				if (f2c->f__external)
					e_rsle();
				else
					z_rnew();
				goto top;
			case '"':
			case '\'':
				quote = ch;
 more_quoted:
				while(GETC(f2c, ch) != quote)
					if (ch == EOF)
						err(a->ciend, EOF, where0);
				if (GETC(f2c, ch) == quote)
					goto more_quoted;
				Ungetc(f2c,ch,f2c->f__cf);
			default:
				continue;
			}
		}
#endif
	ht = mk_hashtab(f2c, nl);
	if (!ht)
		errfl(f2c->f__elist->cierr, 113, where0);
	for(;;) {
		for(;;) switch(GETC(f2c,ch)) {
			case EOF:
				if (got1)
					return 0;
				err(a->ciend, EOF, where0);
			case '/':
			case '$':
			case '&':
				return 0;
			default:
				if (ch <= ' ' && ch >= 0 || ch == ',')
					continue;
				Ungetc(f2c,ch,f2c->f__cf);
				if (ch = getname(f2c, buf,sizeof(buf)))
					return ch;
				goto havename;
			}
 havename:
		v = hash(f2c, ht,buf);
		if (!v)
			errfl(a->cierr, 119, where);
		while(GETC(f2c,ch) <= ' ' && ch >= 0);
		vaddr = v->addr;
		type = v->type;
		if (type < 0) {
			size = -type;
			type = TYCHAR;
			}
		else
			size = f__typesize[type];
		ivae = size;
		iva = readall = 0;
		if (ch == '(' /*)*/ ) {
			dn = dimens;
			if (!(dims = v->dims)) {
				if (type != TYCHAR)
					errfl(a->cierr, 122, where);
				if (k = getdimen(f2c, &ch, dn, (ftnlen)size,
						(ftnlen)size, &b))
					errfl(a->cierr, k, where);
				if (ch != ')')
					errfl(a->cierr, 115, where);
				b1 = dn->extent;
				if (--b < 0 || b + b1 > size)
					return 124;
				iva += b;
				size = b1;
				while(GETC(f2c, ch) <= ' ' && ch >= 0);
				goto scalar;
				}
			nd = (int)dims[0];
			nomax = span = dims[1];
			ivae = iva + size*nomax;
			f2c->colonseen = 0;
			if (k = getdimen(f2c, &ch, dn, size, nomax, &b))
				errfl(a->cierr, k, where);
			no = dn->extent;
			b0 = dims[2];
			dims1 = dims += 3;
			ex = 1;
			for(n = 1; n++ < nd; dims++) {
				if (ch != ',')
					errfl(a->cierr, 115, where);
				dn1 = dn + 1;
				span /= *dims;
				if (k = getdimen(f2c, &ch, dn1, dn->delta**dims,
						span, &b1))
					errfl(a->cierr, k, where);
				ex *= *dims;
				b += b1*ex;
				no *= dn1->extent;
				dn = dn1;
				}
			if (ch != ')')
				errfl(a->cierr, 115, where);
			readall = 1 - f2c->colonseen;
			b -= b0;
			if (b < 0 || b >= nomax)
				errfl(a->cierr, 125, where);
			iva += size * b;
			dims = dims1;
			while(GETC(f2c,ch) <= ' ' && ch >= 0);
			no1 = 1;
			dn0 = dimens;
			if (type == TYCHAR && ch == '(' /*)*/) {
				if (k = getdimen(f2c, &ch, &substr, size, size, &b))
					errfl(a->cierr, k, where);
				if (ch != ')')
					errfl(a->cierr, 115, where);
				b1 = substr.extent;
				if (--b < 0 || b + b1 > size)
					return 124;
				iva += b;
				b0 = size;
				size = b1;
				while(GETC(f2c,ch) <= ' ' && ch >= 0);
				if (b1 < b0)
					goto delta_adj;
				}
			if (readall)
				goto delta_adj;
			for(; dn0 < dn; dn0++) {
				if (dn0->extent != *dims++ || dn0->stride != 1)
					break;
				no1 *= dn0->extent;
				}
			if (dn0 == dimens && dimens[0].stride == 1) {
				no1 = dimens[0].extent;
				dn0++;
				}
 delta_adj:
			ex = 0;
			for(dn1 = dn0; dn1 <= dn; dn1++)
				ex += (dn1->extent-1)
					* (dn1->delta *= dn1->stride);
			for(dn1 = dn; dn1 > dn0; dn1--) {
				ex -= (dn1->extent - 1) * dn1->delta;
				dn1->delta -= ex;
				}
			}
		else if (dims = v->dims) {
			no = no1 = dims[1];
			ivae = iva + no*size;
			}
		else
 scalar:
			no = no1 = 1;
		if (ch != '=')
			errfl(a->cierr, 115, where);
		got1 = f2c->nml_read = 1;
		f2c->f__lcount = 0;
	 readloop:
		for(;;) {
			if (iva >= ivae || iva < 0) {
				f2c->f__lquit = 1;
				goto mustend;
				}
			else if (iva + no1*size > ivae)
				no1 = (ivae - iva)/size;
			f2c->f__lquit = 0;
			if (k = l_read(&no1, vaddr + iva, size, type))
				return k;
			if (f2c->f__lquit == 1)
				return 0;
			if (readall) {
				iva += dn0->delta;
				if (f2c->f__lcount > 0) {
					no1 = (ivae - iva)/size;
					if (no1 > f2c->f__lcount)
						no1 = f2c->f__lcount;
					iva += no1 * dn0->delta;
					if (k = l_read(&no1, vaddr + iva,
							size, type))
						return k;
					}
				}
 mustend:
			GETC(f2c, ch);
			if (readall)
				if (iva >= ivae)
					readall = 0;
				else for(;;) {
					switch(ch) {
						case ' ':
						case '\t':
						case '\n':
							GETC(f2c, ch);
							continue;
						}
					break;
					}
			if (ch == '/' || ch == '$' || ch == '&') {
				f2c->f__lquit = 1;
				return 0;
				}
			else if (f2c->f__lquit) {
				while(ch <= ' ' && ch >= 0)
					GETC(f2c, ch);
				Ungetc(f2c,ch,f2c->f__cf);
				if (!f2c->Alpha[ch & 0xff] && ch >= 0)
					errfl(a->cierr, 125, where);
				break;
				}
			Ungetc(f2c,ch,f2c->f__cf);
			if (readall && !f2c->Alpha[ch & 0xff])
				goto readloop;
			if ((no -= no1) <= 0)
				break;
			for(dn1 = dn0; dn1 <= dn; dn1++) {
				if (++dn1->curval < dn1->extent) {
					iva += dn1->delta;
					goto readloop;
					}
				dn1->curval = 0;
				}
			break;
			}
		}
	}

 integer
#ifdef KR_headers
s_rsne(f2c, a) f2c_state_t *f2c; cilist *a;
#else
s_rsne(f2c_state_t *f2c, cilist *a)
#endif
{
	int n;

	f2c->f__external=1;
	f2c->l_eof = 0;
	if(n = c_le(a))
		return n;
	if(f2c->f__curunit->uwrt && f__nowreading(f2c->f__curunit))
		err(a->cierr,errno,where0);
	f2c->l_getc = t_getc;
	f2c->l_ungetc = un_getc;
	f2c->f__doend = xrd_SL;
	n = x_rsne(f2c, a);
	f2c->nml_read = 0;
	if (n)
		return n;
	return e_rsle();
	}
