#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//global array.
int *original_array;
int original_array_length;
int digits;
//define functions.
int getDigit(int num, int round);
void errorMessage(char * message);
int *countignSort(int *p);
int getMax(int *p, int length);
int *getDigitArray(int *p, int round);


int main()
{
	int p[] = { 25, 36, 11, 8, 39, 20, 3, 13, 2, 21, 4, 10, 60, 1 };
	original_array = p;
	original_array_length = sizeof(p) / sizeof(p[0]);
	digits = 2;
	int *q;
	for (int i = 1; i <= digits; i++)
	{
		q = countignSort(getDigitArray(original_array, i));
		original_array = q;
	}
	for (int i = 0; i < original_array_length; i++)
		printf("%d ", q[i]);

	return 0;
}

int getDigit(int num, int round)
{
	if (round < 1)
	{
		errorMessage("Cannot find digits less than 1!");
		return -1;
	}
	for (int i = 0; i < round-1; i++)
		num /= 10;

	return num % 10;
}

void errorMessage(char * message)
{
	printf("%s\n", message);
}

int *countignSort(int *p)
{
	int range = getMax(p, original_array_length) + 1;
	int *index_array = (int*)malloc(sizeof(int)*range);
	//Array initializtion.
	for (int i = 0; i < range; i++)
		index_array[i] = 0;
	//Frequency.
	for (int i = 0; i < original_array_length; i++)
		index_array[p[i]]++;
	//Index.
	for (int i = 1; i < range; i++)
		index_array[i] = index_array[i - 1] + index_array[i];
	//Create a new array to replace origional array.
	int *new_p = (int*)malloc(sizeof(int)*original_array_length);
	//Must iterate from right to left, or sorting result will not 
	//be stable! One digit array doesn't matter, but more than 1 
	//digits array will get trouble.
	for (int i = original_array_length-1; i >= 0; i--)
	{
		new_p[index_array[p[i]]-1] = original_array[i];
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

int *getDigitArray(int *p, int round)
{
	int * digit_array = (int*)malloc(sizeof(int)*original_array_length);
	for (int i = 0; i < original_array_length; i++)
	{
		digit_array[i] = getDigit(original_array[i], round);
	}
	return digit_array;
}