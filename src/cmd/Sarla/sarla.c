/* Unsynk Chain Compiler */
/* Version: M1N0P0P */
/* Created by UnSynk, TSesuv Xanuc Notsel */

#include <stdio.h>

typedef unsigned char chr;
typedef unsigned int uint;

typedef enum
{	tk_null,
	tk_void,
	tk_newl,
	tk_int,
	tk_flt,
	tk_str,
	tk_eof
} ttp;

typedef struct
{	ttp type;
	chr *s;
	uint l;
} tkn;

chr spTkn(tkn *dis, chr *str)
{	return 0;
}

int main(int ac, chr **av)
{	return 0;
}
