/* Lart - Line editor */
/* Version: M1N0P0P */
/* Created by UnSynk, TSesuv Xanuc Notsel */

#include "lart.h"

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char chr;
typedef unsigned int uint;

FILE *fp;
chr flg = 0;

int main(int ac, chr **av)
{	if(ac < 2)
		return 1;

	if(2 < ac)
	{	if(scmpa(av[1], "/N", 3) == 3)
			flg |= 2;
	}

	fp = fopen(av[ac - 1], "r+");
	if(!fp)
	{	flg |= 1;
		printf("New file\n");
	}

	uint byte = 1;
	chr *buf;
	if(!(flg & 1 | flg & 2))
	{	chr c = 0;
		long head = ftell(fp);

		while((c = fgetc(fp)) != 255)
			byte++;

		free(buf);
		buf = (chr *)malloc(byte);

		fseek(fp, 0, SEEK_SET);
		for(uint i = 0; i < byte; i++)
			fread(buf + i, 1, 1, fp);

		buf[byte - 1] = 0;

		fwrite(buf, 1, byte, stdout);
		fwrite("\n", 1, 2, stdout);
	} else if(!(flg & 2))
	{	fclose(fp);
		fp = fopen(av[ac - 1], "w");
	}
	while(1)
	{	chr cmd[256] = {0};
		chr i = 0;

		printf("* ");
		sget(cmd);

		if(scmpa(cmd, "S", 1) == 1)
		{	while(cmd[i] != ' ' && cmd[i])
				i++;

			if(0 < slen(cmd) - i)
			{	FILE *outf = fopen(&cmd[i], "w");
				fwrite(buf, 1, byte - 1, outf);
				fclose(outf);
			} else
				fwrite(buf, 1, byte - 1, fp);
		} else if(scmpa(cmd, "A", 1) == 1)
			return 0;
	}

	fclose(fp);

	free(buf);

	return 0;
}
