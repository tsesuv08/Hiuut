#include <stdio.h>

typedef unsigned char chr;

typedef struct
{	union
	{	chr ax[2];
		chr as;
	};

	union
	{	chr bx[2];
		chr bs;
	};

	union
	{	chr cx[2];
		chr cs;
	};

	union
	{	chr dx[2];
		chr ds;
	};

	union
	{	chr ex[2];
		chr es;
	};

	union
	{	chr hx[2];
		chr hs;
	};

	union
	{	chr lx[2];
		chr ls;
	};

	chr sp[8];
	chr kx[4];

	chr f[2];
	chr pc[8];
} regs;

int main(void)
{	return 0;
}
