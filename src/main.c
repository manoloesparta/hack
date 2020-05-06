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
		int a[] = {1,0,1,0,1,0,0,0,1,0,1,0,1,1,0,0};
		int b[] = {1,0,0,1,0,1,1,1,1,0,1,1,0,1,1,0};
		int* res = ALU(a,b,0,0,0,0,1,0);
		printf("Log %d:", i);
		printmalloc(res, 18);
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