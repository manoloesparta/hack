#ifndef __CHIPS_H__
#define __CHIPS_H__

int HalfAdder(int a, int b);
int* FullAdder(int a, int b, int c);
int* Incremeter16(int* input);

int* Full16Adder(int* a, int* b);
int* ALU(int* a, int* b, int zx, int nx, int zy, int ny, int f, int no);

#endif