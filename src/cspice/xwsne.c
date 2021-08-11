#include "f2c.h"
#include "fio.h"
#include "lio.h"
#include "fmt.h"
#include "__cspice_state.h"

 static VOID
nl_donewrec(Void)
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	(*f2c->f__donewrec)();
	PUT(f2c,' ');
	}

#ifdef KR_headers
x_wsne(a) cilist *a;
#else
#include "string.h"

 VOID
x_wsne(cilist *a)
#endif
{
	f2c_state_t* f2c = &__cspice_get_state()->user.f2c;
	Namelist *nl;
	char *s;
	Vardesc *v, **vd, **vde;
	ftnint *number, type;
	ftnlen *dims;
	ftnlen size;
	/* MECHSOFT: Read only. Safe to keep static. */
	static ftnint one = 1;
	extern ftnlen f__typesize[];

	nl = (Namelist *)a->cifmt;
	PUT(f2c,'&');
	for(s = nl->name; *s; s++)
		PUT(f2c,*s);
	PUT(f2c,' ');
	f2c->f__Aquote = 1;
	vd = nl->vars;
	vde = vd + nl->nvars;
	while(vd < vde) {
		v = *vd++;
		s = v->name;
#ifdef No_Extra_Namelist_Newlines
		if (f2c->f__recpos+strlen(s)+2 >= L_len)
#endif
			nl_donewrec();
		while(*s)
			PUT(f2c,*s++);
		PUT(f2c,' ');
		PUT(f2c,'=');
		number = (dims = v->dims) ? dims + 1 : &one;
		type = v->type;
		if (type < 0) {
			size = -type;
			type = TYCHAR;
			}
		else
			size = f__typesize[type];
		l_write(number, v->addr, size, type);
		if (vd < vde) {
			if (f2c->f__recpos+2 >= f2c->L_len)
				nl_donewrec();
			PUT(f2c,',');
			PUT(f2c,' ');
			}
		else if (f2c->f__recpos+1 >= f2c->L_len)
			nl_donewrec();
		}
	f2c->f__Aquote = 0;
	PUT(f2c,'/');
	}
