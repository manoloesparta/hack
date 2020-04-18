#include <stdlib.h>
#include "computer.h"

int* ALU(int* a, int* b, int za, int na, int zb, int nb, int f, int no)
{
    int* res = (int*)malloc(18 * sizeof(int));

    int* zero = (int*)malloc(16 * sizeof(int));

    int* nota = NOT16(a);
    int* notb = NOT16(b);
       
    int* zeroOrA = Multi16BitMUX(a, zero, za);
    int* finalA = Multi16BitMUX(zeroOrA, nota, na);
    free(nota);
    free(zeroOrA);

    int* zeroOrB = Multi16BitMUX(b, zero, zb);
    int* finalB = Multi16BitMUX(zeroOrB, notb, nb);
    free(notb);
    free(zeroOrB);

    int* sumAB = Add16(finalA, finalB);
    int* andAB = Multi16BitAND(finalA, finalB);
    free(finalA);
    free(finalB);

    int* almost = Multi16BitMUX(andAB, sumAB, f);
    int* notalmost = NOT16(almost);

    int* final = Multi16BitMUX(almost, notalmost, no);
    free(almost);
    free(notalmost);

    int negative = *(final + 15);

    int isZero = Multi8WayOR(final);
    int isAnswer = NOT(isZero);

    *(res + 0) = *(final + 0);
    *(res + 1) = *(final + 1);
    *(res + 2) = *(final + 2);
    *(res + 3) = *(final + 3);
    *(res + 4) = *(final + 4);
    *(res + 5) = *(final + 5);
    *(res + 6) = *(final + 6);
    *(res + 7) = *(final + 7);
    *(res + 8) = *(final + 8);
    *(res + 9) = *(final + 9);
    *(res + 10) = *(final + 10);
    *(res + 11) = *(final + 11);
    *(res + 12) = *(final + 12);
    *(res + 13) = *(final + 13);
    *(res + 14) = *(final + 14);
    *(res + 15) = *(final + 15);
    *(res + 16) = isAnswer;
    *(res + 17) = negative;

    free(final);

    return res;
}