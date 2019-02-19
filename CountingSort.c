#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int *countignSort(int *p, int length);
int getMax(int *p, int length);


int main()
{
	int p[] = { 5, 6, 1, 8, 9, 0, 3, 3, 2, 1, 4, 10, 0, 1 };
	int *q = countignSort(p, sizeof(p) / sizeof(int));
	for (int i = 0; i < sizeof(p) / sizeof(int); i++)
	{
		printf("%d ", q[i]);
	}
	return 0;
}

int *countignSort(int *p, int length)
{
	int range = getMax(p, length) + 1;
	int *index_array = (int*)malloc(sizeof(int)*range);
	//Array initializtion.
	for (int i = 0; i < range; i++)
		index_array[i] = 0;
	//Frequency.
	for (int i = 0; i < length; i++)
		index_array[p[i]]++;
	//Index.
	for (int i = 1; i < range; i++)
		index_array[i] = index_array[i - 1] + index_array[i];
	//Create a new array to replace p.
	int *new_p = (int*)malloc(sizeof(int)*length);
	for (int i = 0; i < length; i++)
	{
		new_p[index_array[p[i]] - 1] = p[i];
		index_array[p[i]]--;
	}
	free(index_array);
	return new_p;
}

int getMax(int *p, int length)
{
	int max = p[0];
	for (int i = 1; i < length; i++)
	{
		if (max < p[i]) max = p[i];
	}
	return max;
}
