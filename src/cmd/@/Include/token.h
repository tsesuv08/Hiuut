/* UnSynk @ language Token header */
/* Version: M1N0P0P */
/* Created by UnSynk, TSesuv Xanuc Notsel */

#ifndef TOKEN_H
#define TOKEN_H

////////////////////////////////////////////////////////

#include "@.h"

////////////////////////////////////////////////////////

typedef enum
{	TK_VOID,
	TK_ENT,
	TK_IDR,
	TK_NME,
	TK_SYM,
	TK_STR,
	TK_NUM,
	TK_EOF
} tkType;

typedef struct
{	tkType type;
	byte *dat;
} Token;

////////////////////////////////////////////////////////

Token tknnew(void);
bit tknset(Token *t, tkType type, byte *d);

bit tknfree(Token *t);

byte *type2str(tkType type);

////////////////////////////////////////////////////////

Token tknnew(void)
{	Token t;

	t.type = TK_VOID;
	t.dat = (byte *)malloc(sizeof(byte));

	return t;
}

bit tknset(Token *t, tkType type, byte *d)
{	bit x;

	t->type = type;
	free(t->dat);
	t->dat = (byte *)malloc(lenn(d) * sizeof(byte));

	byteset(t->dat, d, 0, 0, lenn(d));

	set(&x, 1);

	return x;
}

bit tknfree(Token *t)
{	bit x;

	t->type = TK_VOID;
	free(t->dat);

	set(&x, 1);

	return x;
}

byte *type2str(tkType type)
{	if(type == TK_VOID) return "TK_VOID";
	else if(type == TK_ENT) return "TK_ENT";
	else if(type == TK_IDR) return "TK_IDR";
	else if(type == TK_NME) return "TK_NME";
	else if(type == TK_SYM) return "TK_SYM";
	else if(type == TK_STR) return "TK_STR";
	else if(type == TK_NUM) return "TK_NUM";
	else if(type == TK_EOF) return "TK_EOF";

	return NULL;
}

////////////////////////////////////////////////////////

#endif /* token.h */
