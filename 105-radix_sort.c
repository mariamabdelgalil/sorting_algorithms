#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order using radix sort
 * @arr: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *arr, size_t size)
{
	if (size < 2)
		return;
	count_data(arr, size, 1);
}

/**
 * count_data - Counts occurrence of each digit for radix sort.
 * @arr: Array of data to be sorted.
 * @size: Size of data.
 * @digit: Current digit to distribute.
 */
void count_data(int *arr, int size, int digit)
{
	int count_array[10] = {0};
	int i, j, num, digit_count = 10, **buffer;

	for (i = 0; i < size; i++)
	{
		num = arr[i];
		for (j = 0; j < digit; j++)
			if (j > 0)
				num /= 10;
		num %= 10;
		count_array[num]++;
	}

	if (count_array[0] == size)
		return;

	buffer = malloc(sizeof(int *) * 10);
	if (!buffer)
		return;

	for (i = 0; i < digit_count; i++)
		if (count_array[i] != 0)
			buffer[i] = malloc(sizeof(int) * count_array[i]);

	distribute_data(arr, buffer, size, digit);

	count_data(arr, size, digit + 1);

	for (i = 0; i < digit_count; i++)
		if (count_array[i] > 0)
			free(buffer[i]);
	free(buffer);
}

/**
 * distribute_data - Distributes digits to respective buffers for radix sort
 * @arr: Array of data to be sorted.
 * @buffer: Array of arrays to store sorted data.
 * @size: Size of the array.
 * @digit: Current digit to be sorted.
 */
void distribute_data(int *arr, int **buffer, int size, int digit)
{
	int i, j, num, digit_count = 10;
	int count_array[10] = {0};

	for (i = 0; i < size; i++)
	{
		num = arr[i];
		for (j = 0; j < digit; j++)
			if (j > 0)
				num /= 10;
		num %= 10;
		buffer[num][count_array[num]++] = arr[i];
	}

	for (i = 0, j = 0; i < digit_count; i++)
	{
		while (count_array[i] > 0)
		{
			arr[j] = buffer[i][--count_array[i]];
			j++;
		}
	}

	print_array(arr, size);
}
