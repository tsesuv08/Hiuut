/* Lart - Line editor */
/* Version: M1N0P0P */
/* Created by UnSynk, TSesuv Xanuc Notsel */

#include "lart.h"

FILE *fp;
chr flg = 0;

int main(int ac, chr **av)
{	if(ac < 2)
		return 1;

	if(2 < ac)
	{	if(scmpa(av[1], "/N", 3) == 3)
			flg |= 2;
	}

	chr *fname = malloc(1);
	for(uint k = 0; k < ac; k++)
	{	if(scmpa(av[k], "/F:", 3) == 3)
		{	flg |= 1;

			fname = realloc(fname, slen(av[k] - 3));

			for(uint i = 3; i < slen(av[k]); i++)
				fname[i - 3] = av[k][i];

			fname[slen(av[k]) - 3] = 0;

			fp = fopen(fname, "r+");
			if(!fp)
			{	flg |= 2;

				fp = fopen(fname, "w");
				if(fp)
					printf("New file\n");

				else
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
