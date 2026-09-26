/* 215 Assembler */
/* Version: M0N0P1P */
/* Created by UnSynk, TSesuv Xanuc Notsel */

#include <stdio.h>
#include <stdlib.h>
#include "215.h"



int main(uint ac, char **av)
{	if(3 < ac)
		return 1;

	chr *aName = malloc(1 + slen("FILE.ASM"));
	chr *oName = malloc(1 + slen("a.215"));
	scpy(aName, "FILE.ASM");
	scpy(oName, "A.215");

	if(1 < ac && scmpa(&av[1][slen(av[1]) - 4], ".ASM", 4) == 4)
	{	aName = realloc(aName, 1 + slen(av[1]));
		scpy(aName, av[1]);

		if(2 < ac)
			scpy(oName, av[2]);
	} else if(2 < ac && scmpa(&av[2][slen(av[2]) - 4], ".ASM", 4) == 4)
	{	aName = realloc(aName, 1 + slen(av[2]));
		scpy(aName, av[2]);

		scpy(oName, av[1]);
	}

	printf("ASM: %s\nBIN: %s\n", aName, oName);

	free(oName);
	free(aName);

	return 0;
}
