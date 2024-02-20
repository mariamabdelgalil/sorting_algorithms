#include "sort.h"
#include <stdio.h>

/**
 * Range - Prints a range of elements in an array
 * @array: The array to print
 * @start: The first element to print
 * @end: The last element to print
 */
void Range(int *array, int start, int end)
{
	int index;

	/* Initialize index to the starting point of the range */
	index = start;
	while (index <= end) /* Continue until the end of the range is reached */
	{
		/* Print a comma for separation except before the first element */
		if (index > start)
			printf(", ");
		/* Print the current element of the array */
		printf("%d", array[index]);
		index++; /* Move to the next element */
	}
	printf("\n"); /* End the line after printing the range */
}

/**
 * swap - Swaps two elements in an array
 * @array: The array to swap elements in
 * @index1: The index of the first element to swap
 * @index2: The index of the second element to swap
 * @dir: The direction of the swap
 */
void swap(int *array, int index1, int index2, int dir)
{
	int swapTemp;

	/* The direction dir determines whether a */
	/* swap should happen based on the comparison */
	switch (dir)
	{
	case 1:
		if (array[index1] > array[index2])
		{
			swapTemp = array[index1];
			array[index1] = array[index2];
			array[index2] = swapTemp;
		}
		break;
	case 0:
		if (array[index1] < array[index2])
		{
			swapTemp = array[index1];
			array[index1] = array[index2];
			array[index2] = swapTemp;
		}
		break;
	}
}

/**
 * merge_Bit - Merges two sorted arrays into a single sorted array
 * @array: The array to merge
 * @low: The lowest index of the array
 * @size: The size of the array
 * @dir: The direction of the merge
 * @arraySize: The size of the array
 */
void merge_Bit(int *array, int low, int size, int dir, const int arraySize)
{
	int half_size = size, current_index = low;

	if (size > 1)
	{
		half_size = size / 2;
		current_index = low;

		/* Swap corresponding elements in the array based on the direction */
		while (current_index < low + half_size)
		{
			swap(array, current_index, current_index + half_size, dir);
			current_index++;
		}

		/* Recursively merge the first half */
		merge_Bit(array, low, half_size, dir, arraySize);

		/* Recursively merge the second half */
		merge_Bit(array, low + half_size, half_size, dir, arraySize);
	}
}

/**
 * segmentate_S - Sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: The array to be sorted
 * @low: The lowest index of the array
 * @size: The size of the array
 * @dir: The direction of the merge
 * @arraySize: The size of the array
 */
void segmentate_S(int *array, int low, int size,
					 int dir, const int arraySize)
{
	int mid = size; /* Renaming 'k' to 'mid' for clarity */

	/* Only proceed if the segment size is greater than 1 */
	if (size > 1)
	{
		/* Output the direction of the merge and the segment size */
		switch (dir)
		{
		case 1: /* UP direction */
			printf("Merging [%d/%d] (UP):\n", size, arraySize);
			break;
		case 0: /* DOWN direction */
			printf("Merging [%d/%d] (DOWN):\n", size, arraySize);
			break;
		}
		/* Print the range of elements to be merged */
		Range(array, low, low + mid - 1);
		mid = size / 2; /* Calculate the midpoint of the segment */
		/* Sort the first half in UP direction and */
		/* the second half in DOWN direction */
		segmentate_S(array, low, mid, 1, arraySize);
		segmentate_S(array, low + mid, mid, 0, arraySize);

		/* Merge the two sorted halves */
		merge_Bit(array, low, size, dir, arraySize);

		/* Output the result of the merge */
		switch (dir)
		{
		case 1: /* UP direction */
			printf("Result [%d/%d] (UP):\n", size, arraySize);
			break;
		case 0: /* DOWN direction */
			printf("Result [%d/%d] (DOWN):\n", size, arraySize);
			break;
		}
		/* Print the final merged range */
		Range(array, low, low + 2 * mid - 1);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */

void bitonic_sort(int *array, size_t size)
{
	/* Flag indicating the sorting direction is upwards */
	int directionUp = 1;
	/* Cast size to int for consistency with other variables */
	const int totalElements = (int)size;

	/* Early return if the array is too small or null */
	if (size < 2 || !array)
		return;

	/* Begin sorting the array in the upwards */
	/* direction starting from the first element */
	segmentate_S(array, 0, totalElements, directionUp, totalElements);
}
