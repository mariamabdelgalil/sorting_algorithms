#include "sort.h"

/**
 * partition - partition
 * @array: array
 * @lo: lower
 * @hi: higher
 * @size: array's size
 * Return: i
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int i = lo - 1, j = lo;
	int pivot = array[hi], temp = 0;

	for (; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (array[i] != array[j])
				print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[hi];
	array[hi] = temp;
	if (array[i + 1] != array[j])
		print_array(array, size);
	return (i + 1);
}

/**
 * quick_sort_helper - quick sort helper
 * @array: given array
 * @lo: lower
 * @hi:higher
 * @size: array's size
 * Return: void
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quick_sort_helper(array, lo, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, hi, size);
	}
}

/**
 * quick_sort - function that sorts an array of integers
 *              in ascending order using the Quick sort algorithm
 * @array: array
 * @size: array's size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quick_sort_helper(array, 0, size - 1, size);
}
