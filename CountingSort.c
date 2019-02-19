#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int *counting_sort(int *p, int length);
int find_max(int *p, int length);

int main()
{
	int p[] = { 5, 6, 7, 2, 4, 5, 1 };
	int length = sizeof(p) / sizeof(int);
	int *q = counting_sort(p, length);
	for (int i = 0; i < length; i++)
		printf("%d ", q[i]);
	return 0;
}

int *counting_sort(int *p, int p_length)
{
	int max = find_max(p, p_length) + 1;
	int *index_array = (int*)malloc(sizeof(int)*max);
	for (int i = 0; i < max; i++)
		index_array[i] = 0;
	for (int i = 0; i < p_length; i++)
		index_array[p[i]]++;
	for (int i = 1; i < max; i++)
		index_array[i] = index_array[i - 1] + index_array[i];
	for (int i = 0; i < max; i++)
		printf("index_array[%d] %d \n", i, index_array[i]);
	int *new_p = (int*)malloc(sizeof(int)*p_length);
	//Must start from last to first, because we know last must exist, but we 
	//don't know if first exist.
	for (int i = p_length-1; i >= 0; i--)
	{
		new_p[index_array[p[i]]-1] = p[i];
		index_array[p[i]]--;
	}
	free(index_array);
	return new_p;
}

int find_max(int *p, int length)
{
	printf("max = %d ", sizeof(p) / sizeof(p[0]));
	int max = p[0];
	for (int i = 1; i < length; i++)
	{
		if (p[i] > max)
			max = p[i];
	}
	return max;
}
