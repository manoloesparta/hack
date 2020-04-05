#ifndef __GATES__
#define __GATES__

// Every function that returns a pointer must be freed

int NOT(int input);
int OR(int a, int b);
int AND(int a, int b);
int XOR(int a, int b);
int MUX(int a, int b, int sel);
int* DMUX(int a, int b);

int* Multi16BitNOT(int* input);
int* Multi16BitAND(int* a, int* b);
int* Multi16BitOR(int* a, int* b);
int* Multi16BitMUX(int* a, int* b, int sel);

int Multi8WayOR(int* input);
int* Multi4WayMUX(int* a, int* b, int* c, int* d, int* sel);
int* Multi8WayMUX(int* a, int* b, int* c, int* d, int* e, int* f, int* g, int* h, int* sel);
int* Multi4WayDMUX(int input, int* sel);
int* Multi8WayDMUX(int input, int* sel);

#endif