#include <stdio.h>
#include <unistd.h>
#include "computer.h"

void printmalloc(int* arr, int size);
int todecimal(int* arr, int size);

int main()
{
	while(1)
	{
		int sel[] = {0,1};
		int* res = Multi4WayDMUX(1, sel);
		printmalloc(res, 4);
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

int todecimal(int* arr, int size)
{

}