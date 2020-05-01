#ifndef __CHIPS_H__
#define __CHIPS_H__

// res[0] = sum, res[1] = carry
int* HalfAdder(int a, int b);
int* FullAdder(int a, int b, int c);

// 16 bit res
int* Inc16(int* input);
int* Add16(int* a, int* b);

// 16 bit res + 1 bit zero + 1 bit negative
int* ALU(int* a, int* b, int za, int na, int zb, int nb, int f, int no);

#endif