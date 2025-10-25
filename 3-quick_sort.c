#include "sort.h"

/**
 * swap_int - swaps two integers
 * @a: first integer
 * @b: second integer
 */
static void swap_int(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: array of integers
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 *
 * Return: index of pivot after partition
 */
static size_t lomuto_partition(int *array, size_t low, size_t high,
	size_t size)
{
	int pivot = array[high];
	size_t i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[high])
	{
		swap_int(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quicksort_recursive - recursively sorts array using Quick sort
 * @array: array of integers
 * @low: starting index
 * @high: ending index
 * @size: size of array
 */
static void quicksort_recursive(int *array, size_t low, size_t high,
	size_t size)
{
	size_t p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		if (p > 0)
			quicksort_recursive(array, low, p - 1, size);
		quicksort_recursive(array, p + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers using Quick sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}

