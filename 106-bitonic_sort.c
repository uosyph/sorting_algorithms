#include "sort.h"

/**
 * swaper - Swaps the values of 2 elements in an array.
 * @left_index: Pointer to first element
 * @right_index: Pointer to second element
 */
void swaper(int *left_index, int *right_index)
{
	int tmp = *left_index;
	*left_index = *right_index;
	*right_index = tmp;
}

/**
 * bitonic_merge - Recursive bitonic merge.
 * @array: The array to be sorted
 * @size: Size of @array
 * @direction: The sort direction
 */
void bitonic_merge(int *array, size_t size, char direction)
{
	int i = 0, direction_is_r = direction == 'r' ? 1 : 0;

	if (size < 2)
		return;

	for (; i < (int)size / 2; i++)
	{
		if ((array[i] > array[i + size / 2]) == direction_is_r)
		{
			swaper(array + i, array + i + size / 2);
		}
	}
	bitonic_merge(array, size / 2, direction);
	bitonic_merge(array + size / 2, size / 2, direction);
}

/**
 * bitonic_sequency - Implements bitonic algorithm
 * @array: The array to be sorted
 * @size: Size of @array
 * @original_size: Size of the original @array
 * @direction: The sort direction
 */
void bitonic_sequency(int *array, size_t size,
					  size_t original_size, char direction)
{
	if (size < 2)
		return;

	printf("Merging [%li/%li] (%s):\n", size,
		   original_size, direction == 'r' ? "UP" : "DOWN");

	print_array(array, size);
	bitonic_sequency(array, size / 2, original_size, 'r');
	bitonic_sequency(array + size / 2, size / 2, original_size, 'l');
	bitonic_merge(array, size, direction);

	printf("Result [%li/%li] (%s):\n", size,
		   original_size, direction == 'r' ? "UP" : "DOWN");

	print_array(array, size);
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * using the Bitonic sort algorithm.
 * @array: The array to be sorted
 * @size: Size of @array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sequency(array, size, size, 'r');
}
