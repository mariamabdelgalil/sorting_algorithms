#include "sort.h"
#include <unistd.h>

/**
 * shell_sort - Execute the Shell sort algorithm to order an array
 * of integers in non-decreasing sequence
 * @array: Pointer to the integer array that will be ordered
 * @size: The number of elements contained in the array
 */

void shell_sort(int *array, size_t size)
{
	/* Interval for gap sequence */
	size_t gap = 1;
	/* Pointers for the current element and the element to compare with */
	ssize_t index, compareIndex;
	/* Holder for the element being inserted */
	int insertValue;
	/* Calculate the initial gap using Knuth's formula */
	while (gap < size / 3)
		gap = gap * 3 + 1;
	/* Edge case check for invalid input */
	if (array == NULL || size < 2)
		return;
	/* Continue sorting until the gap is zero */
	while (gap > 0)
	{
		/* Perform a gapped insertion sort */
		for (index = (ssize_t)gap; index < (ssize_t)size; index++)
		{
			/* Store the value of the current element */
			insertValue = array[index];
			compareIndex = index;

			/* Compare and shift elements that are larger than the insert value */
			while (
				compareIndex >= (ssize_t)gap &&
				array[compareIndex - gap] > insertValue
			)
			{
				array[compareIndex] = array[compareIndex - gap];
				compareIndex -= gap;
			}

			/* Place the insert value in its correct sorted position */
			array[compareIndex] = insertValue;
		}
		/* Output the array after sorting with the current gap */
		print_array(array, size);
		/* Decrease the gap for the next iteration */
		gap = (gap - 1) / 3;
	}
}
