#include <stdio.h>
#include <unistd.h>
#include "computer.h"

void printmalloc(int* arr, int size);

int main()
{
	while(1)
	{
		int sel[] = {1,1,0};
		int* res = Multi8WayDMUX(1, sel);
		printmalloc(res, 8);
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