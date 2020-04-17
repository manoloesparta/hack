#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "computer.h"

void printmalloc(int* arr, int size);

int main()
{
	for(int i = 0; 1; i++)
	{
		int a[] = {1,0,1,0,1,0,0,0,1,0,1,0,1,1,0,0};
		int b[] = {1,0,0,1,0,1,1,1,1,0,1,1,0,1,1,0};
		int d[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
		int c[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		int* res = Add16(a,b);
		printf("Log %d: ", i);
		printmalloc(res, 16);
		free(res);
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