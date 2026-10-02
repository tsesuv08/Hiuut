/* Unsynk Chain Compiler */
/* Version: M1N0P0P */
/* Created by UnSynk, TSesuv Xanuc Notsel */

#define DEFAULT_SRC_FILE_NAME "MAIN.SRL"
#define DEFAULT_TKN_FILE_NAME "A.TKN"

#include "s.h"
#include <stdlib.h>

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

FILE *sfile;
FILE *tfile;

int main(int ac, chr **av)
{	chr *sfname = malloc(slen(DEFAULT_SRC_FILE_NAME));
	chr *tfname = malloc(slen(DEFAULT_TKN_FILE_NAME));

	mncpy(sfname, DEFAULT_SRC_FILE_NAME, slen(DEFAULT_SRC_FILE_NAME));
	mncpy(tfname, DEFAULT_TKN_FILE_NAME, slen(DEFAULT_TKN_FILE_NAME));

	for(uint i = 0; i < ac; i++)
	{	if(scmpa(av[i], "/SRC:", 5) == 5)
		{	sfname = realloc(sfname, slen(av[i]) - 5);
			mncpy(sfname, 5 + av[i], slen(av[i]) - 5);
		} else if(scmpa(av[i], "/TKN:", 5) == 5)
		{	tfname = realloc(tfname, slen(av[i]) - 5);
			mncpy(tfname, 5 + av[i], slen(av[i]) - 5);
		}
	} sfile = fopen(sfname, "r");
	if(!sfile)
	{	printf("Sarla: ERR: Can't open file: %s\n", sfname);

		return 1;
	}

	uint sfsyze = fsyz(sfile);

	for(uint i = 0; i < sfsyze; i++)
	{	chr c = fgetc(sfile);

		printf("%c", c);
	}

	fclose(sfile);

	free(tfname);
	free(sfname);

	return 0;
}
