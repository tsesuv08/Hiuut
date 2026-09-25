/* UnSynk Sarla Interpreter */
/* Created by UnSynk, TSesuv Xanuc Notsel */
/* Version: M1N1P0P */
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char chr;
typedef unsigned int uint;

uint comment = 0;

uint pc = 0;
chr f = 0;

chr sk[256] = "";
chr sp = 0;

uint land = 0;

chr r[8] = ""; // 0から順にABCDEHLNKPQR

chr regid(chr c)
{	chr id = 255;

	switch(c)
	{	case 'A':
			id = 0;

			break;

		case 'B':
			id = 1;

			break;

		case 'C':
			id = 2;

			break;

		case 'D':
			id = 3;

			break;

		case 'E':
			id = 4;

			break;

		case 'H':
			id = 5;

			break;

		case 'L':
			id = 6;

			break;

		case 'N':
			id = 7;

			break;

		case 'K':
			id = 8;

			break;

		case 'P':
			id = 9;

			break;

		case 'Q':
			id = 10;

			break;

		case 'R':
			id = 11;

			break;
	}

	return id;
}

uint vcvt(chr *mem)
{	uint v = 0;
	uint cnt = pc;
	chr vc = '0';

	while(0x29 < vc && vc < 0x3A)
	{	v *= 10;
		v += vc - 0x30;
		vc = mem[cnt++];
	} cnt--;

	pc = cnt;

	return v;
}

chr flgchk(chr d)
{	chr rv = 0;
	switch(d)
	{	case 'Z':
			if(f & 1)
				rv = 1;

			break;

		case 'C':
			if(f & 2)
				rv = 1;

			break;

		case 'S':
			if(f & 4)
				rv = 1;

			break;

		case 'A':
			rv = 1;

			break;
	}

	return rv;
}

int main(int ac, char **av)
{	if(ac < 2)
		return 1;

	FILE *fp = fopen(av[1], "r");
	if(!fp)
		return 2;

	uint size = ftell(fp);
	fseek(fp, 0, SEEK_END);
	size = ftell(fp) - size;
	fseek(fp, 0, SEEK_SET);

	chr *mem = malloc(size);
	if(!mem)
		return 3;

	if(fread(mem, 1, size, fp) != size)
		return 4;

	fclose(fp);

	chr pwr = 1;

	while(pwr)
	{	chr code = mem[pc++];

		if(code == 0)
			pwr = 0;

		else if(code == '_')
			comment++;

		else if(code == '=')
			comment--;

		else if(comment)
			continue;

		else if(code == '!')
			printf("[] A%d, B%d, C%d, D%d, E%d, H%d, L%d, N%d, K%d, P%d, Q%d, R%d, PC%d, SP%d, F%d, SK[SP-1]%d\n", r[0], r[1], r[2], r[3], r[4], r[5], r[6], r[7], r[8], r[9], r[10], r[11], pc, sp, f, sk[sp-1]);
		else if(code == '^')
			continue;

		else if(code == '#')
		{	chr id = mem[pc++];
			r[regid(id)] = 0;
		} else if(code == '$')
		{	chr id = mem[pc++];
			chr ch = 0;

			r[regid(id)] = 0;
			while((ch = getchar()) != '\n')
			{	r[regid(id)] *= 10;
				r[regid(id)] += ch - '0';
			}
		} else if(code == '&')
		{	chr id = mem[pc++];
			putchar(r[regid(id)]);
		} else if(code == '\'')
		{	chr id = mem[pc++];
			r[regid(id)] = getchar();

			while(getchar() != '\n');
		} else if(code == '/')
		{	chr id = mem[pc++];
			r[regid(id)]++;
			if(!r[regid(id)])
				f |= 2;
		} else if(code == '\\')
		{	chr id = mem[pc++];
			r[regid(id)]--;
			if(r[regid(id)] == 255)
				f |= 2;
		} else if(code == '*')
		{	chr id = mem[pc++];
			sk[sp++] = r[regid(id)];
		} else if(code == '%')
		{	chr id = mem[pc++];
			r[regid(id)] = sk[--sp];
		} else if(code == '?')
		{	chr id = mem[pc++];
			uint v = vcvt(mem);
			if(r[regid(id)] == v)
				f |= 1;

			else
				f &= ~1;

			if(!(r[regid(id)] < v))
				f |= 2;

			else
				f &= ~2;

			if(r[regid(id)] < v)
				f |= 4;

			else
				f &= ~4;
		} else if(code == '<')
		{	chr vf = mem[pc++];
			uint v = vcvt(mem);
			if(flgchk(vf))
			{	v++;
				while(land < v)
				{	chr ch = mem[pc--];
					if(ch == '^')
						land++;
				}
			} land = 0;
		} else if(code == '>')
		{	chr vf = mem[pc++];
			uint v = vcvt(mem);
			if(flgchk(vf))
			{	v++;
				while(land < v)
				{	chr ch = mem[pc++];
					if(ch == '^')
						land++;
				}
			} land = 0;
		} else if(code == '+')
		{	chr id = mem[pc++];
			if(mem[pc] < 0x3A)
			{	uint v = vcvt(mem);

				if(256 < r[regid(id)] + v)
					f |= 2;

				else
					f &= ~2;

				r[regid(id)] += v;
			} else
			{	chr id2 = mem[pc++];

				if(256 < r[regid(id)] + r[regid(id2)])
					f |= 2;

				else
					f &= ~2;

				r[regid(id)] += r[regid(id2)];
			}
		} else if(code == '-')
		{	chr id = mem[pc++];

			if(regid(id) == 255)
			{	pc--;

				uint v1 = vcvt(mem);
				chr reg = mem[pc++];

				if(v1 - r[regid(id)] < 0)
					f |= 2;

				else
					f &= ~2;

				r[regid(reg)] = v1 - r[regid(id)];
			} else
			{	if(mem[pc] < 0x3A)
				{	uint v = vcvt(mem);

					if(r[regid(id)] - v < 0)
						f |= 2;

					else
						f &= ~2;

					r[regid(id)] -= v;
				} else
				{	chr id2 = mem[pc++];

					if(r[regid(id)] - r[regid(id2)] < 0)
						f |= 2;

					else
						f &= ~2;

					r[regid(id)] -= r[regid(id2)];
				}
			}
		}
	}

	free(mem);
	return 0;
}
