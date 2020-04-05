#include <stdlib.h>
#include "computer.h"

int Multi8WayOR(int* input)
{
	int pre0 = OR(*(input + 0), *(input + 1));
	int pre1 = OR(pre0, *(input + 2));
	int pre2 = OR(pre1, *(input + 3));
	int pre3 = OR(pre2, *(input + 4));
	int pre4 = OR(pre3, *(input + 5));
	int pre5 = OR(pre4, *(input + 6));
	int pre6 = OR(pre5, *(input + 7));
	return pre6;
}

int* Multi4WayMUX(int* a, int* b, int* c, int* d, int* sel)
{
	int sel0 = *(sel + 0);
	int sel1 = *(sel + 1);

	int* tmp1 = Multi16BitMUX(a, b, sel1);
	int* tmp2 = Multi16BitMUX(c, d, sel1);

	int* res = Multi16BitMUX(tmp1, tmp2, sel0);

	free(tmp1);
	free(tmp2);

	return res;
}

int* Multi8WayMUX(int* a, int* b, int* c, int* d, int* e, int* f, int* g, int* h, int* sel)
{

	int* tmp1 = Multi4WayMUX(a, b, c, d, sel + 1);
	int* tmp2 = Multi4WayMUX(e, f, g, h, sel + 1);

	int* res = Multi16BitMUX(tmp1, tmp2, *sel);

	free(tmp1);
	free(tmp2);

	return res;
}

int* Multi4WayDMUX(int input, int* sel)
{
	int* res = malloc(4 * sizeof(int));

	int* tmp = DMUX(input, *(sel + 0));
	int* tmp1 = DMUX(*(tmp + 0), *(sel + 1));
	int* tmp2 = DMUX(*(tmp + 1), *(sel + 1));
	free(tmp);

	*(res + 0) = *(tmp1 + 0);
	*(res + 1) = *(tmp1 + 1);
	free(tmp1);

	*(res + 2) = *(tmp2 + 0);
	*(res + 3) = *(tmp2 + 1);
	free(tmp2);

	return res;
}

int* Multi8WayDMUX(int input, int* sel)
{
	int* res = malloc(8 * sizeof(int));

	int* tmp = DMUX(input, *(sel + 0));
	int* tmp1  = Multi4WayDMUX(*(tmp + 0), sel + 1);
	int* tmp2  = Multi4WayDMUX(*(tmp + 1), sel + 1);
	free(tmp);

	*(res + 0) = *(tmp1 + 0);
	*(res + 1) = *(tmp1 + 1);
	*(res + 2) = *(tmp1 + 2);
	*(res + 3) = *(tmp1 + 3);
	free(tmp1);

	*(res + 4) = *(tmp2 + 0);
	*(res + 5) = *(tmp2 + 1);
	*(res + 6) = *(tmp2 + 2);
	*(res + 7) = *(tmp2 + 3);
	free(tmp2);

	return res;
}