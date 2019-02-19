#include<stdlib.h>
#include<stdio.h>


//Define functions.
void quickSort(int *p, int first, int last);
int partition(int *p, int first, int last);
void exchange(int *p, int i, int j);
void shuffle(int *array, int n);

int main()
{
	int p[] = {-1, 3, 5, 9, 1, 7, 4, 6, -7, 0, 2, 1, 4};
	int length = sizeof(p) / sizeof(p[0]);
	shuffle(p, length);
	for (int i = 0; i < length; i++)
	{
		printf("%d ", p[i]);
	}

	printf("\n ");
	quickSort(p, 0, length-1);
	for (int i = 0; i < length; i++)
	{ printf("%d ", p[i]); }
	
	return 0;
}

//Keep splitting array to subarrays, until there is only one 
//element in subarrays (first < last).
void quickSort(int *p, int first, int last)
{
	if (first < last)
	{
		int q = partition(p, first, last);
		quickSort(p, first, q-1);
		quickSort(p, q+1, last);
	}
}

//Partition divided an array to 4 areas: small elements area; large
//elements ares; uncheck element area; pivot number. There are two pinters,
//i and j. i point to the end (rightmost) element of smaller elements area
//(less or equal than pivot number); j is always moving and it trying to 
//find a smaller element (less than pivot) form uncheck area. Once j find
//a smaller number, i add 1 (point to the first or leftmost element of large
//elements area), then relocate the smaller number to i's position (exchange).
int partition(int *p, int first, int last)
{
	int i = first - 1;
	int pivot = p[last];
	for (int j = first; j < last; j++)
	{
		if (p[j] <= pivot)
		{
			i++;
			exchange(p, i, j);
		}
	}
	exchange(p, i + 1, last);
	return i + 1;
}

void exchange(int *p, int i, int j)
{
	int temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}

//To avoid wrost cases (array has already sorted in order O(n^2)),
//we must shuffle the array first in order to get O(nlgn).
void shuffle(int *array, int n)
{
	if (n > 1)
	{
		int i;
		for (i = 0; i < n - 1; i++)
		{
			int j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
		}
	}
}