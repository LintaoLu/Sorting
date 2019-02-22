#include<stdio.h>
#include<stdlib.h>

int *mergeSort(int *p, int length);
int *merge(int *left, int left_length, int *right, int right_length);

int main()
{
	int p[] = { 60, -34, 5, 1, 2, 9, 9, 0, -2 };
	int p_length = sizeof(p) / sizeof(p[0]);
	int *q = mergeSort(p, p_length);
	for (int i = 0; i < p_length; i++) printf("%d ", q[i]);
	return 0;
}

//mergeSort splits 1 array to 2 sub arrays, form top layer 
//(lenght of array is n) to bottom layer (length of array 
//is 1). 
int* mergeSort(int *p, int length)
{
	if (length <= 1) return p;

	int left_length = length / 2;
	int *left = (int*)malloc(sizeof(int)*left_length);
	for (int i = 0; i < left_length; i++) left[i] = p[i];

	int right_length = length - left_length;
	int *right = (int*)malloc(sizeof(int)*right_length);
	for (int i = 0; i < right_length; i++) right[i] = p[left_length + i];

	int *left_merge_sort = mergeSort(left, left_length);
	int *right_merge_sort = mergeSort(right, right_length);
	p = merge(left_merge_sort, left_length, right_merge_sort, right_length);
	
	//The bottom layer doesn't use merge method, it directly return addresses
	//of left and right. Since one object cannot be free twice, so I check 
	//their values before free.
	if (left_merge_sort != left) free(left_merge_sort);
	if (right_merge_sort != right) free(right_merge_sort);
	free(left);
	free(right);

	return p;
}

//merge starts from bottom layer (arrays that has only 1 element), then merge 
//two consequent arrays to one sorted array. Finally it returns the sorted 
//merged array.
int *merge(int *left, int left_length, int *right, int right_length)
{
	int *p = (int*)malloc(sizeof(int)*(left_length + right_length));
	int i = 0, j = 0, k = 0;
	while (i < left_length && j < right_length)
	{
		//Left must be less or equal to right, or the sorting algoritms
		//is not stable!
		if (left[i] <= right[j]) p[k++] = left[i++];
		else p[k++] = right[j++];
	}
	for (; i < left_length;) p[k++] = left[i++];
	for (; j < right_length;) p[k++] = right[j++];

	return p;
}