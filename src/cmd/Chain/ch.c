/* Unsynk Chain Interpreter */
/* Version: M1N0P0P */
/* Created by UnSynk, TSesuv Xanuc Notsel */

#include <stdio.h>

typedef unsigned char chr;

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
