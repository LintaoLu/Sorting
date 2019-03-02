#include<stdio.h>
#include<stdlib.h>

//Given heap's size, then sink index's value to an appropriate place.
void maxHeap(int *p, int index, int length);
void exchange(int *p, int i, int j);
void buildHeap(int *p, int length);
void heapSort(int *p, int length);

int main()
{
	int p[] = { 0, -21, -3, 6, 23, 98, 43, 6, -3, 4, 1, 2, 7, 9, 5, 6, 3, 8, 4};
	int length = sizeof(p) / sizeof(p[0]);
	heapSort(p, length);
	for (int i = 0; i < length; i++) printf("%d ", p[i]);
	return 0;
}

void maxHeap(int *p, int index, int length)
{
	//Our goal is to rearrange the position between parent and children,
	//if this index has illegal children, which means no need to rearrange, 
	//just return.
	if (index * 2 > length - 1) return;
	int largest = index;
	int left_child = index * 2, right_child = index * 2 + 1;
	if (left_child <= length - 1 && p[left_child] > p[largest])
		largest = left_child;
	if (right_child <= length - 1 && p[right_child] > p[largest])
		largest = right_child;
	if (largest != index)
	{
		exchange(p, largest, index);
		maxHeap(p, largest, length);
	}
}

void exchange(int *p, int i, int j)
{
	int temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}

void buildHeap(int *p, int length)
{
	for (int i = (length - 1) / 2; i > 0; i--)
		maxHeap(p, i, length);;	
}

void heapSort(int *p, int length)
{
	buildHeap(p, length);
	int temp = length;
	for (int i = length - 1; i > 0; i--)
	{
		exchange(p, 1, i);
		maxHeap(p, 1, --temp);
	}
}