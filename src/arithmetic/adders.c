#include <stdlib.h>
#include "computer.h"

int* HalfAdder(int a, int b)
{
    int* res = (int*)malloc(2 * sizeof(int));
    *(res + 0) = XOR(a, b);
    *(res + 1) = AND(a, b);
    return res;
}

int* FullAdder(int a, int b, int c)
{
    int* res = (int*)malloc(2 * sizeof(int));

    int* tmp0 = HalfAdder(a, b);
    int* tmp1 = HalfAdder(*(tmp0 + 0), c);
    
    *(res + 0) = *(tmp1 + 0);
    *(res + 1) = OR(*(tmp0 + 1), *(tmp1 + 1));
    free(tmp0);
    free(tmp1);

    return res;
}