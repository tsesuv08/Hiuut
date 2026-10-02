#ifndef S_H
#define S_H

#include <stdio.h>

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
	} return 1;
}

chr sgetc(chr *out, uint cnt)
{	chr c = 0;

	while(cnt)
	{	c = getchar();

		if(c == '\r' || c == '\n')
		{	*out = 0;

			return 0;
		} else
			*out++ = c;
	} return 1;
}

uint fsyz(FILE *file)
{	uint t = 0;

	fseek(file, 0, SEEK_END);
	t = ftell(file);
	fseek(file, 0, SEEK_SET);
	t -= ftell(file);

	return t;
}
chr mcpy(chr *d, chr *s)
{	while(*d++ = *s++);

	return 0;
}

chr mncpy(chr *d, chr *s, uint n)
{	while(n--)
		*d++ = *s++;

	return 0;
}

#endif /* s.h */
