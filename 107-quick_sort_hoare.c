#include "sort.h"


/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * partition2 - partition
 * @array: array
 * @lo: lower
 * @hi: higher
 * @size: array's size
 * Return: i
 */
int partition2(int *array, int lo, int hi, size_t size)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = lo - 1, below = hi + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * quick_sort_helper2 - quick sort helper
 * @array: given array
 * @lo: lower
 * @hi:higher
 * @size: array's size
 * Return: void
 */
void quick_sort_helper2(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = partition2(array, lo, hi, size);
		quick_sort_helper2(array, lo, pivot - 1, size);
		quick_sort_helper2(array, pivot, hi, size);
	}
}


/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper2(array, size, 0, size - 1);
}
