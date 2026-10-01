/* Lart - Line editor */
/* Version: M1N0P0P */
/* Created by UnSynk, TSesuv Xanuc Notsel */

#include "lart.h"

FILE *fp;
chr flg = 0;

int main(int ac, chr **av)
{	if(ac < 2)
		return 1;

	chr *fname = malloc(1);
	for(uint k = 0; k < ac; k++)
	{	if(scmpa(av[k], "/N", 3) == 3)
			flg |= 2;

		else if(scmpa(av[k], "/F:", 3) == 3)
		{	fname = realloc(fname, slen(av[k] - 3));

			for(uint i = 3; i < slen(av[k]); i++)
				fname[i - 3] = av[k][i];

			fname[slen(av[k]) - 3] = 0;

			fp = fopen(fname, "r+");
			if(!fp)
			{	fp = fopen(fname, "w");
				if(fp)
				{	flg |= 2;
					printf("New file\n");
				} else
				{	printf("File not exist\n");

					return 2;
				}
			}
		}
	}

	free(fname);
	fclose(fp);

	return 0;
}
