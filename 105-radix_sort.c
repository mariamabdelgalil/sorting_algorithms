#include <stdlib.h>
#include "sort.h"

/**
 * distribute_data - auxiliary function of radix sort
 * @array: array of data to be sorted
 * @buffer: array of arrays to be sorted
 * @size: size of the array
 * @digit: digit to be sorted
 */
void distribute_data(int *array, int **buffer, int size, int digit)
{
	int index, position, currentValue, base = 10;
	/* Initialize tally for counting occurrences of each digit */
	int tally[10] = {0};
	int secondTally[10] = {0}; /* Secondary tally for distribution */

	for (index = 0; index < size; index++)
	{
		currentValue = array[index];
		for (position = 0; position < digit; position++)
			if (position > 0)
				currentValue /= base; /* Reduce number by a factor of 10 */
		currentValue %= base;		  /* Get the digit at the current place value */
		buffer[currentValue][tally[currentValue]] = array[index];
		tally[currentValue]++;
	}

	index = 0;
	position = 0;
	while (position < base)
	{
		while (tally[position] > 0)
		{
			array[index++] = buffer[position][secondTally[position]];
			secondTally[position]++;
			tally[position]--;
		}
		position++;
	}

	/* Print the sorted array */
	print_array(array, size);
}

/**
 * count_data - auxiliary function of radix sort
 * @array: array of data to be sorted
 * @size: size of data
 * @digit: Current digit to distribute
 */
void count_data(int *array, int size, int digit)
{
	int frequency[10] = {0}; /* Array to keep track of digit frequencies */
	int idx, digitIdx, number, base = 10, **digitBuckets;
	/* Calculate frequency of each digit at the current place value */
	for (idx = 0; idx < size; idx++)
	{
		number = array[idx]; /* Isolate the digit at 'digit' place */
		for (digitIdx = 0; digitIdx < digit; digitIdx++)
			if (digitIdx > 0)
				number /= base; /* Reduce the number by a factor of base (10) */
		number %= base;			/* Get the digit */
		frequency[number]++;	/* Increment frequency count for this digit */
	}
	/* If all numbers have the same digit at the current place value, skip */
	if (frequency[0] == size)
		return;
	/* Allocate buffer for digit sorting */
	digitBuckets = malloc(sizeof(int *) * base);
	if (!digitBuckets)
		return;
	/* Allocate space for each bucket based on frequency count */
	idx = 0;
	while (idx < base)
	{
		if (frequency[idx] > 0)
			digitBuckets[idx] = malloc(sizeof(int) * frequency[idx]);
		idx++;
	}
	/* Distribute the numbers into corresponding digit buckets */
	distribute_data(array, digitBuckets, size, digit);
	/* Recursively call count_data for the next digit place */
	count_data(array, size, digit + 1);
	/* Free the allocated memory for each non-empty bucket and the buffer */
	idx = 0;
	while (idx < base)
	{
		if (frequency[idx] > 0)
			free(digitBuckets[idx]);
		idx++;
	}
	free(digitBuckets);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the radix sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */

void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	count_data(array, size, 1);
}
