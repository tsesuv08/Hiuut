/* UnSynk @ Compiler */
/* Version: M1N0P0P */
/* Created by UnSynk, TSesuv Xanuc Notsel */

#include "Include/@.h"
#include "Include/token.h"

FILE *infile;
FILE *outfile;

int main(int ac, char **av)
{	if(ac == 1)
	{	return 0;
	}

	uint lenth = catlen((byte **)av, ac);
	byte *ag = (byte *)malloc((lenth + ac) * sizeof(byte));
	bytecat(ag, (byte **)av, ac);

	printf("Length: %d\n", lenth);
	for(uint i = 0; i < lenth; i++) printf("%c ($%02X)\n", ag[i], ag[i]);

	uint placeInName = 0;
	uint placeOutName = 0;
	bit flag[2];
	set(&flag[0], 0); // Detect & geted /i: option
	set(&flag[1], 0); // Detect & geted /o: option

	// 引数チェック部分
	for(uint i = 0; i < lenth; i++)
	{	if(get(cmpe(ag + i, "/i:", 3)) && !get(flag[0]))
		{	placeInName = i + 3;
			set(&flag[0], 1);
			printf("Detect /i: %d (p: %d, %s)\n", i, placeInName, &ag[placeInName]);
		}
		if(get(cmpe(ag + i, "/o:", 3)) && !get(flag[1]))
		{	placeOutName = i + 3;
			set(&flag[1], 1);
			printf("Detect /o: %d (p: %d, %s)\n", i, placeOutName, &ag[placeOutName]);
		}
	}

	free(ag);

	return 0;
}
