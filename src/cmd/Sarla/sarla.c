/* Unsynk Chain Interpreter */
/* Version: M1N0P0P */
/* Created by UnSynk, TSesuv Xanuc Notsel */

#include <stdio.h>

typedef unsigned char chr;
typedef unsigned int uint;

typedef enum
{	tk_null,
	tk_void,
	tk_int,
	tk_flt,
	tk_str,
	tk_eof;
} ttp;

typedef struct
{	typedef union
	{	;
	};

	chr *s;
	uint l;
} tkn;

chr f = 0;

int main(int ac, chr **av)
{	if(ac < 2)
		f |= 0x1;

	for(int i = 0; i < ac; i++)
	{	if(*av[i] == '/')
			printf("option\n");
	}

	return 0;
}
