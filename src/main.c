#include <stdio.h>
#include <unistd.h>
#include "computer.h"

void printmalloc(int* arr, int size);

int main()
{
	for(int i = 0; 1; i++)
	{
		int* res = FullAdder(0,1,1);
		printf("Log %d: ", i);
		printmalloc(res, 2);
		sleep(1);
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