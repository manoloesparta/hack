#ifndef __GATES_H__
#define __GATES_H__

// 1 bit
int NOT(int input);
int OR(int a, int b);
int AND(int a, int b);
int XOR(int a, int b);
int MUX(int a, int b, int sel);

// res[0] = a, res[1] = b
int* DMUX(int input, int sel);

// 16 bit
int* Multi16BitNOT(int* input);
int* Multi16BitAND(int* a, int* b);
int* Multi16BitOR(int* a, int* b);
int* Multi16BitMUX(int* a, int* b, int sel);

// 1 bit
int Multi8WayOR(int* input);

// 16 bit
int* Multi4WayMUX(int* a, int* b, int* c, int* d, int* sel);
int* Multi8WayMUX(int* a, int* b, int* c, int* d, int* e, int* f, int* g, int* h, int* sel);

// res[0] = a, res[1] = b, res[2] = c, res[3] = d
int* Multi4WayDMUX(int input, int* sel);

// res[0] = a, res[1] = b, res[2] = c, res[3] = d, res[4] = e, res[5] = f, res[6] = g, res[7] = h
int* Multi8WayDMUX(int input, int* sel);

#endif