#include "sort.h"

/**
 * partition - Partitions an array of integers.
 * @array: The array to be partitioned
 * @low: Low index
 * @high: High index
 * @size: Size of @array
 * Return: The partitioned array
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, holder, i, j;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				holder = array[i];
				array[i] = array[j];
				array[j] = holder;
				print_array(array, size);
			}
		}
		j++;
	}

	if (pivot < array[i + 1])
	{
		holder = array[i + 1];
		array[i + 1] = array[high];
		array[high] = holder;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * sorting - Sorts an array of integers using recursion.
 * @array: The array to be sorted
 * @low: Low index
 * @high: High index
 * @size: Size of @array
 */
void sorting(int *array, int low, int high, size_t size)
{
	int part;
	if (low < high)
	{
		part = partition(array, low, high, size);
		sorting(array, low, part - 1, size);
		sorting(array, part + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in
 * ascending order using the Quick sort algorithm.
 * @array: The array to be sorted
 * @size: Size of @array
 */
void quick_sort(int *array, size_t size)
{
	size_t low, high;

	if (size == 0 || size == 1)
		return;

	low = 0;
	high = size - 1;
	sorting(array, low, high, size);
}
