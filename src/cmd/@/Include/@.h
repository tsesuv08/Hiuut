/* UnSynk @ tool Header */
/* Version: M1N0P0P */
/* Created by UnSynk, TSesuv Xanuc Notsel */

#ifndef AT_H
#define AT_H

////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////

typedef unsigned char byte;
typedef unsigned int uint;

typedef struct
{	byte f:1;
} bit;

////////////////////////////////////////////////////////

uint catlen(byte **s, uint cnt);
uint bytecat(byte *dis, byte **src, uint cnt);
uint byteset(byte *dis, byte *src, uint to, uint from, uint len);
uint bytesete(byte *dis, byte *src, uint to, uint from, uint len, byte eto, byte *efrm);
uint bytefill(byte *dis, byte fdat, uint start, uint len);
byte *getcnk(byte *p, byte *dem, byte *sp, uint cnt);
uint getfsize(FILE *fp);
uint len(byte *p);
uint lenn(byte *p);
bit cmp(byte a, byte b);
bit cmpa(byte *a, byte *b);
bit cmpe(byte *a, byte *b, uint len);
byte get(bit b);
byte set(bit *b, byte v);

////////////////////////////////////////////////////////

uint catlen(byte **s, uint cnt)
{	uint t = 0;

	for(uint i = 0; i < cnt; i++) t += lenn(s[i]);

	return t;
}

uint bytecat(byte *t, byte **s, uint cnt)
{	uint n = 0;

	for(uint k = 0; k < cnt; k++)
	{	for(uint i = 0; i < lenn(s[k]); i++) t[n++] = *(s[k] + i);
	}

	return n;
}

uint byteset(byte *dis, byte *src, uint to, uint from, uint len)
{	for(uint i = from; i < from + len; i++)
	{	dis[to] = src[i];

		if(dis[to] != src[i]) return to;

		to++;
	}

	return len;
}

uint bytesete(byte *dis, byte *src, uint to, uint from, uint len, byte eto, byte *efrm)
{	byte f = 0;

	for(uint i = from; i < from + len; i++)
	{	dis[to] = src[i];

		for(uint k = 0; k < lenn(efrm) - 1; k++)
		{	if(dis[to] == efrm[k])
			{	dis[to] = eto;

				f = 1;
				break;
			}
		}

		if(dis[to] != src[i] && !f) return to;
		else if(dis[to] != eto && f) return to;

		f = 0;
		to++;
	}

	return len;
}

uint bytefill(byte *dis, byte fdat, uint start, uint len)
{	for(uint i = start; i < len; i++)
	{	dis[i] = fdat;

		if(dis[i] != fdat) return i - len;
	}

	return len;
}

// NULL門番文字列を返す、引数で何個目のを返すか制御。
byte *getcnk(byte *p, byte *dem, byte *sp, uint cnt)
{	byte *chank = (byte *)malloc(1 + sizeof(byte));
	uint n = 0;
	uint m = 0;
	uint memsize = 1;
	bit f[4];
	set(&f[0], 0);
	set(&f[1], 0);
	set(&f[2], 0);
	set(&f[3], 0);

	for(uint k = 0; k < lenn(p); k++)
	{	set(&f[1], 0);

		// printf("cnktrc: %d, c: %c ($%02X)\n", n, p[k], p[k]);

		for(uint i = 0; i < len(dem); i++)
		{	if(get(cmp(p[k], dem[i])))
			{	set(&f[1], 1);
				if(n == cnt)
				{	set(&f[0], 0);
				}

				if(get(f[1]) && !get(f[2])) n++;

				break;
			} else if(n == cnt && !get(f[1])) set(&f[0], 1);
		}

		if(cnt < n) break;

		if(memsize <= m)
		{	memsize *= 2;
			chank = (byte *)realloc(chank, 1 + memsize * sizeof(byte));
		}

		if(get(f[0]))
		{	if(!get(cmp(p[k], '\t'))) chank[m++] = p[k];
		}

		for(uint i = 0; i < len(sp); i++)
		{	if(get(cmp(p[k], sp[i])))
			{	if(n == cnt)
				{	set(&f[3], 1);
					chank[m++] = p[k];

					break;
				}

				n++;
			} else if(n == cnt) set(&f[0], 1);
		} if(get(f[3])) break;

		set(&f[2], get(f[1]));
	}

	chank[m] = 0;

	return chank;
}

uint getfsize(FILE *fp)
{	uint fsize = 0;

	fseek(fp, 0, SEEK_END);
	fsize = ftell(fp);
	rewind(fp);

	return fsize;
}

uint len(byte *p)
{	return lenn(p) - 1;
}

uint lenn(byte *p)
{	byte *t = p;

	while(*p++);

	return p - t;
}

bit cmp(byte a, byte b)
{	bit x;

	set(&x, a == b);

	return x;
}

bit cmpa(byte *a, byte *b)
{	bit x;

	set(&x, lenn(a) == lenn(b));
	for(uint i = 0; i < lenn(a) && get(x); i++) set(&x, a[i] == b[i]);


	return x;
}

bit cmpe(byte *a, byte *b, uint len)
{	bit x;
	set(&x, 1);

	for(uint i = 0; i < len && get(x); i++) set(&x, a[i] == b[i]);

	return x;
}

byte get(bit b)
{	return b.f;
}

byte set(bit *b, byte v)
{	return b->f = v;
}

////////////////////////////////////////////////////////

#endif /* @.h */
