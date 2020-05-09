#ifndef __SEQUENTIAL_H__
#define __SEQUENTIAL_H__

// out(t) = out(t-1)
int DataFlipFlop(int clock, int in);

int Bit(int clock, int in, int load);

#endif
