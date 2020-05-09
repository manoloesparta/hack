#include "computer.h"

int DataFlipFlop(int clock, int in)
{
    int almost = NAND(clock, in);
    int notalmost = NAND(clock, NOT(in));

    static int q = 0;
    static int notq = 1;

    q = NAND(almost, notq);
    notq = NAND(notalmost, q);

    return q;
}

int Bit(int clock, int in, int load)
{
   
}