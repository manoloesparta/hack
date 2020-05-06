#include <stdlib.h>
#include "computer.h"

int NOT(int input)
{
	return !input;
}

int OR(int a, int b)
{
	return a || b;
}

int AND(int a, int b)
{
	return a && b;
}

int NAND(int a, int b)
{
	return NOT(AND(a,b));
}

int XOR(int a, int b)
{
	int suba = AND(a, NOT(b));
	int subb = AND(NOT(a), b);
	return OR(suba, subb);
}

int MUX(int a, int b, int sel)
{
	int suba = AND(NOT(sel), a);
	int subb = AND(sel, b);
	return OR(suba, subb);	
}

int* DMUX(int input, int sel)
{
	int* res = (int*)calloc(2, sizeof(int));

	int notsel = NOT(sel);
	*(res + 0) = AND(input, notsel);
	*(res + 1) = AND(input, sel);

	return res;
}