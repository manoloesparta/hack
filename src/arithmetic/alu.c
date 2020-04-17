#include <stdlib.h>
#include "computer.h"

int* ALU(int* a, int* b, int za, int na, int zb, int nb, int f, int no)
{
    int* zero = (int*)malloc(16 * sizeof(int));
    
    int* zeroOrA = Multi16BitMUX(a, zero, za);
    int* zeroOrB = Multi16BitMUX(b, zero, zb);
}