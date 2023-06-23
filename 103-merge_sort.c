#include "sort.h"

/**
 * print_parts - Prints a part of the array.
 * @array: The array to be printed
 * @min: Starting point of the array
 * @max: Ending point of the array
 */
void print_parts(int *array, size_t min, size_t max)
{
	size_t i;
	i = min;
	while (i < max)
	{
		if (i > min)
			printf(", ");
		printf("%d", array[i]);
		i++;
	}
	printf("\n");
}

/**
 * top_down - Merges an array using top down method.
 * @A: The left array
 * @B: The right array
 * @min: Starting point of the array
 * @mid: Middle point of the array
 * @max: Ending point of the array
 */
void top_down(int *A, int *B, size_t min, size_t mid, size_t max)
{
	size_t i = min, j = mid, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_parts(A, min, mid);
	printf("[right]: ");
	print_parts(A, mid, max);

	for (k = min; k < max; k++)
	{
		if (i < mid && (j >= max || A[i] <= A[j]))
		{
			B[k] = A[i];
			i++;
		}
		else
		{
			B[k] = A[j];
			j++;
		}
	}

	printf("[Done]: ");
	print_parts(B, min, max);

	for (k = min; k < max; k++)
		A[k] = B[k];
}

/**
 * top_down_split - Splits array into two parts.
 * @A: The left array
 * @B: The right array
 * @min: Starting point of the array
 * @max: Ending point of the array
 */
void top_down_split(int *A, int *B, size_t min, size_t max)
{
	size_t mid;

	if (max - min < 2)
		return;

	mid = (min + max) / 2;
	top_down_split(A, B, min, mid);
	top_down_split(A, B, mid, max);
	top_down(A, B, min, mid, max);
}

/**
 * merge_sort - Sorts an array of integers in
 * ascending order using the Merge sort algorithm.
 * @array: The array to be sorted
 * @size: Size of @array
 */
void merge_sort(int *array, size_t size)
{
	int *newlist;

	if (size == 0 || size == 1)
		return;

	newlist = malloc(sizeof(int) * size);
	if (newlist == NULL)
		return;

	top_down_split(array, newlist, 0, size);
	free(newlist);
}
