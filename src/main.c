#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "computer.h"

void printmalloc(int* arr, int size);

int main()
{
	for(int i = 1; 1; i++)
	{
		int clock = !(i % 2);
		int a = DataFlipFlop(clock, 1);
		DataFlipFlop(clock, 0);
		printf("Log %d: %d\n", i, a);
		usleep(2 * 100000);
	}
	return 0;
}

void printmalloc(int* arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}