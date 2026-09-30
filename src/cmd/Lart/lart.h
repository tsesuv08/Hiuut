#ifndef LART_H
#define LART_H

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char chr;
typedef unsigned int uint;

chr upper(chr p)
{	if(p < 0x61)
		return p;

	if(0x7A < p)
		return p;

	return 0xDF & p;
}

uint slen(chr *p)
{	chr *t = p;

	while(*p++);

	return p - t - 1;
}

uint scmp(chr *a, chr *b, uint c)
{	uint d = 0;

	while(c)
	{	if(*a == *b)
			d++;

		a++;
		b++;
		c--;
	}

	return d;
}

uint scmpa(chr *a, chr *b, uint c)
{	uint d = 0;

	while(c)
	{	if(upper(*a) == upper(*b))
			d++;

		a++;
		b++;
		c--;
	}

	return d;
}

chr scmpe(chr *a, chr *b)
{	if(slen(a) != slen(b))
		return 0;

	for(uint i = 0; i < slen(a); i++)
	{	if(a[i] != b[i])
			return 0;
	}

	return 1;
}

chr sget(chr *out)
{	chr c = 0;

	while(1)
	{	c = getchar();

		if(c == '\r' || c == '\n')
		{	*out = 0;

			return 0;
		} else
			*out++ = c;
	}
}

uint fsyz(FILE *fp)
{	uint t = 0;

	fseek(fp, 0, SEEK_END);
	t = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	t -= ftell(fp);

	return t;
}

chr bufa(chr **buf, uint *syz, chr c)
{	if(*syz <= 1 + slen(*buf))
	{	*syz = 2 * (1 + *syz);
		chr *t = realloc(*buf, *syz);
		if(!t)
			return 1;

		*buf = t;
	} (*buf)[1 + slen(*buf)] = 0;
	(*buf)[slen(*buf)] = c;

	return 0;
}

#endif /* lart.h */
