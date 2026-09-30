#include <stdio.h>
#include <stdlib.h>

typedef unsigned char chr;
typedef unsigned int uint;

typedef struct
{	chr *s;
	uint c;
} tk;

chr tkx(tk *t)
{	return 0;
}

uint slen(chr *s)
{	chr *t = s;
	while(*t++);

	return t - s - 1;
}

uint fsyz(FILE *fp)
{	uint t = 0;

	fseek(fp, 0, SEEK_END);
	t = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	t -= ftell(fp);

	return t;
}

chr bufa(chr **buf, uint *syz, chr c) // Buffer Append
{	if(*syz <= 1 + slen(*buf))
	{	*syz = 2 * (1 + *syz);
		chr *t = realloc(*buf, *syz);
		if(!t)
			return 1;

		*buf = t;
	} (*buf)[1 + slen(*buf)] = 0;
	(*buf)[slen(*buf)] = c; // Appending

	return 0;
}

int main(uint ac, chr **av)
{	if(ac != 2)
		return 1; // Error: No file path provided

	FILE *fp = fopen(av[1], "r"); // Program expects a file path to second argument
	if(!fp)
		return 2; // Error: Can't open file (general error)

	uint syz = fsyz(fp); // Get file size
	chr *fbuf = malloc(syz); // Allocate file buffer for file contents
	fread(fbuf, 1, syz, fp); // Read file contents into file buffer
	fclose(fp); // Fulfilled its role

	printf("%s\n", fbuf); // Testing file buffer

	chr *buf = malloc(1); // Allocate buffer for token
	uint bsyz = 0; // Buffer size
	buf[0] = 0; // Initialize buffer to empty string
	for(uint i = 0; i < syz; i++) // Iterate every character in file buffer
	{	switch(fbuf[i])
		{	case '+': // If c = '+'?
				if(bufa(&buf, &bsyz, '+'))	// Append '+' to buffer, and
											// if size too small, auto resizing
											// And error checking
				{	free(buf); // If error, free buffer
					free(fbuf); // Free file buffer

					return 3; // Error: Failed to append to buffer (general error)
				}

				break;
		}
	} printf("%s\n", buf); // Testing buffer contents

	free(buf); // Fulfilled its role
	free(fbuf); // same

	return 0; // Success
}
