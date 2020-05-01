#include <stdlib.h>
#include "computer.h"

int* Multi16BitNOT(int* input)
{
	int* res = (int*)malloc(16 * sizeof(int));
	*(res + 0) = NOT(*(input + 0));
	*(res + 1) = NOT(*(input + 1));
	*(res + 2) = NOT(*(input + 2));
	*(res + 3) = NOT(*(input + 3));
	*(res + 4) = NOT(*(input + 4));
	*(res + 5) = NOT(*(input + 5));
	*(res + 6) = NOT(*(input + 6));
	*(res + 7) = NOT(*(input + 7));
	*(res + 8) = NOT(*(input + 8));
	*(res + 9) = NOT(*(input + 9));
	*(res + 10) = NOT(*(input + 10));
	*(res + 11) = NOT(*(input + 11));
	*(res + 12) = NOT(*(input + 12));
	*(res + 13) = NOT(*(input + 13));
	*(res + 14) = NOT(*(input + 14));
	*(res + 15) = NOT(*(input + 15));
	return res;
}

int* Multi16BitAND(int* a, int* b)
{
	int* res = (int*)malloc(16 * sizeof(int));
	*(res + 0) = AND(*(a + 0), *(b + 0));
	*(res + 1) = AND(*(a + 1), *(b + 1));
	*(res + 2) = AND(*(a + 2), *(b + 2));
	*(res + 3) = AND(*(a + 3), *(b + 3));
	*(res + 4) = AND(*(a + 4), *(b + 4));
	*(res + 5) = AND(*(a + 5), *(b + 5));
	*(res + 6) = AND(*(a + 6), *(b + 6));
	*(res + 7) = AND(*(a + 7), *(b + 7));
	*(res + 8) = AND(*(a + 8), *(b + 8));
	*(res + 9) = AND(*(a + 9), *(b + 9));
	*(res + 10) = AND(*(a + 10), *(b + 10));
	*(res + 11) = AND(*(a + 11), *(b + 11));
	*(res + 12) = AND(*(a + 12), *(b + 12));
	*(res + 13) = AND(*(a + 13), *(b + 13));
	*(res + 14) = AND(*(a + 14), *(b + 14));
	*(res + 15) = AND(*(a + 15), *(b + 15));
	return res;
}

int* Multi16BitOR(int* a, int* b)
{
	int* res = (int*)malloc(16 * sizeof(int));
	*(res + 0) = OR(*(a + 0), *(b + 0));
	*(res + 1) = OR(*(a + 1), *(b + 1));
	*(res + 2) = OR(*(a + 2), *(b + 2));
	*(res + 3) = OR(*(a + 3), *(b + 3));
	*(res + 4) = OR(*(a + 4), *(b + 4));
	*(res + 5) = OR(*(a + 5), *(b + 5));
	*(res + 6) = OR(*(a + 6), *(b + 6));
	*(res + 7) = OR(*(a + 7), *(b + 7));
	*(res + 8) = OR(*(a + 8), *(b + 8));
	*(res + 9) = OR(*(a + 9), *(b + 9));
	*(res + 10) = OR(*(a + 10), *(b + 10));
	*(res + 11) = OR(*(a + 11), *(b + 11));
	*(res + 12) = OR(*(a + 12), *(b + 12));
	*(res + 13) = OR(*(a + 13), *(b + 13));
	*(res + 14) = OR(*(a + 14), *(b + 14));
	*(res + 15) = OR(*(a + 15), *(b + 15));
	return res;
}

int* Multi16BitMUX(int* a, int* b, int sel)
{
	int* res = (int*)malloc(16 * sizeof(int));
	*(res + 0) = MUX(*(a + 0), *(b + 0), sel);
	*(res + 1) = MUX(*(a + 1), *(b + 1), sel);
	*(res + 2) = MUX(*(a + 2), *(b + 2), sel);
	*(res + 3) = MUX(*(a + 3), *(b + 3), sel);
	*(res + 4) = MUX(*(a + 4), *(b + 4), sel);
	*(res + 5) = MUX(*(a + 5), *(b + 5), sel);
	*(res + 6) = MUX(*(a + 6), *(b + 6), sel);
	*(res + 7) = MUX(*(a + 7), *(b + 7), sel);
	*(res + 8) = MUX(*(a + 8), *(b + 8), sel);
	*(res + 9) = MUX(*(a + 9), *(b + 9), sel);
	*(res + 10) = MUX(*(a + 10), *(b + 10), sel);
	*(res + 11) = MUX(*(a + 11), *(b + 11), sel);
	*(res + 12) = MUX(*(a + 12), *(b + 12), sel);
	*(res + 13) = MUX(*(a + 13), *(b + 13), sel);
	*(res + 14) = MUX(*(a + 14), *(b + 14), sel);
	*(res + 15) = MUX(*(a + 15), *(b + 15), sel);
	return res;
}