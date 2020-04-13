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

int* Add16(int* a, int* b)
{
    int* res = (int*)malloc(17 * sizeof(int));

    int* tmp0 = FullAdder(*(a + 0), *(b + 0), 0);
    *(res + 0) = *tmp0;

    int* tmp1 = FullAdder(*(a + 1), *(b + 1), *(tmp0 + 1));
    *(res + 1) = *tmp1;
    free(tmp0);

    int* tmp2 = FullAdder(*(a + 2), *(b + 2), *(tmp1 + 1));
    *(res + 2) = *tmp2;
    free(tmp1);

    int* tmp3 = FullAdder(*(a + 3), *(b + 3), *(tmp2 + 1));
    *(res + 3) = *tmp3;
    free(tmp2);

    int* tmp4 = FullAdder(*(a + 4), *(b + 4), *(tmp3 + 1));
    *(res + 4) = *tmp4;
    free(tmp3);

    int* tmp5 = FullAdder(*(a + 5), *(b + 5), *(tmp4 + 1));
    *(res + 5) = *tmp5;
    free(tmp4);

    int* tmp6 = FullAdder(*(a + 6), *(b + 6), *(tmp5 + 1));
    *(res + 6) = *tmp6;
    free(tmp5);

    int* tmp7 = FullAdder(*(a + 7), *(b + 7), *(tmp6 + 1));
    *(res + 7) = *tmp7;
    free(tmp6);

    int* tmp8 = FullAdder(*(a + 8), *(b + 8), *(tmp7 + 1));
    *(res + 8) = *tmp8;
    free(tmp7);

    int* tmp9 = FullAdder(*(a + 9), *(b + 9), *(tmp8 + 1));
    *(res + 9) = *tmp9;
    free(tmp8);

    int* tmp10 = FullAdder(*(a + 10), *(b + 10), *(tmp9 + 1));
    *(res + 10) = *tmp10;
    free(tmp9);

    int* tmp11 = FullAdder(*(a + 11), *(b + 11), *(tmp10 + 1));
    *(res + 11) = *tmp11;
    free(tmp10);

    int* tmp12 = FullAdder(*(a + 12), *(b + 12), *(tmp11 + 1));
    *(res + 12) = *tmp12;
    free(tmp11);

    int* tmp13 = FullAdder(*(a + 13), *(b + 13), *(tmp12 + 1));
    *(res + 13) = *tmp13;
    free(tmp12);

    int* tmp14 = FullAdder(*(a + 14), *(b + 14), *(tmp13 + 1));
    *(res + 14) = *tmp14;
    free(tmp13);

    int* tmp15 = FullAdder(*(a + 15), *(b + 15), *(tmp14 + 1));
    *(res + 15) = *tmp15;
    *(res + 16) = *(tmp15 + 1);
    free(tmp14);
    free(tmp15);

    return res;
}

int* Inc16(int* input)
{
    int* inc = (int*)malloc(16 * sizeof(int));
    *(inc + 0) = 1;
    return Add16(input, inc);
}
