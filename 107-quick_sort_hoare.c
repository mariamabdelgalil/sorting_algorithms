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
	int i = lo - 1, j = hi + 1;
	int pivot = array[hi], temp = 0;

	while (1) {
        	do {
            	i++;
        	} while (array[i] < pivot);

       		do {
            	j--;
        	} while (array[j] > pivot);

        	if (i >= j)
            		return j;
		temp = array[j];
		array[j] = array[i];
		array[i] = temp;
		if (array[i] != array[j])
			print_array(array, size);
    	}
	return (j);
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
		quick_sort_helper(array, pivot, hi, size);
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

	quick_sort_helper(array, size, 0, size - 1);
}
