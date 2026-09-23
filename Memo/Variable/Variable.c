#include <stdio.h>
#include <string.h>
#include "Include/io.h"

int main(int argc, char **argv)
{
	if((argc < 2))
	{
		printf("===============DEMO===============\r\n");
		SetVarData("TESTVAR", "System: Hello, User!");
		SetVarData("2TEST", "System: How are you?\r\n");
		printf("[ DEBUG ] Value of TESTVAR: %s\r\n", (char *)GetVarData("TESTVAR"));
		SetVarData("TESTVAR", "System: New Data!");
		printf("[ DEBUG ] Value of updated TESTVAR: %s\r\n", (char *)GetVarData("TESTVAR"));
		printf("[ DEBUG ] Value of 2TEST: %s", (char *)GetVarData("2TEST"));
		SetVarData("2TEST", "Dummy: I'm fine.  Thank you!\r\n\r\n");
		printf("[ DEBUG ] Value of updated 2TEST: %s", (char *)GetVarData("2TEST"));
		printf("[ DEBUG ] TESTVAR: %s,	2TEST: %s", (char *)GetVarData("TESTVAR"), (char *)GetVarData("2TEST"));
		int CstVar = 123;
		SetVarData("TESTVAR", &CstVar);
		printf("[ DEBUG ] TESTVAR: %d\r\n", *(int *)GetVarData("TESTVAR"));
		printf("==================================\r\n");
		printf("Usage:\r\n");
		printf("	/vname <name> <data>	:	Set <data> in <name>.\r\n");
		printf("	/sview <name>		:	View data of <name> in String.\r\n");
		printf("	/iview <name>		:	View data of <name> in Integer (Casting string to integer).\r\n");
		printf("	/pview <name>		:	View data of <name> in Pointer.\r\n");
		printf("	/line			:	Print new line.\r\n");
		printf("	/stdout <data>		:	Print <data> in stdout.\r\n");
		return 0;
	}

	for(int i = 0; i < argc; i++)
	{
		if(strcmp(*(argv + i), "/vname") == 0)
		{
			SetVarData(*(argv + i + 1), *(argv + i + 2));
		}
		if(strcmp(*(argv + i), "/sview") == 0)
		{
			printf("%s", (char *)GetVarData(*(argv + i + 1)));
		}
		if(strcmp(*(argv + i), "/iview") == 0)
		{
			printf("%d", (int)GetVarData(*(argv + i + 1)));
		}
		if(strcmp(*(argv + i), "/pview") == 0)
		{
			printf("%p", GetVarData(*(argv + i + 1)));
		}
		if(strcmp(*(argv + i), "/line") == 0)
		{
			printf("\r\n");
		}
		if(strcmp(*(argv + i), "/stdout") == 0)
		{
			printf("%s", *(argv + i + 1));
		}
	}

	return 0;
}