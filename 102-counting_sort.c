#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * findMaximum - Finds the maximum value in an array
 * Return: The maximum value in the array
 * Prototype: int findMaximum(int *array, size_t size);
 * @array: The array of integers to find the maximum value in
 * @size: The size of the array
 */
int findMaximum(int *array, size_t size)
{
	size_t index;
	int max = 0;

	for (index = 0; index < size; index++)
	{
		if (max < array[index])
			max = array[index];
	}

	return (max);
}

/**
 * initializeZeroArray - Initializes an array of integers with zeros
 * Return: A pointer to the initialized array
 * Prototype: int *initializeZeroArray(int size);
 * @size: The size of the array
 */
int *initializeZeroArray(int size)
{
	int *array = NULL;
	int i;

	array = malloc(size * sizeof(int));

	for (i = 0; i < size; i++)
		array[i] = 0;

	return (array);
}

/**
 * counting_sort - Sorts an array of integers in
 * ascending order using the counting sort algorithm
 * Prototype: void counting_sort(int *array, size_t size);
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j;
	int maxValue = 0;
	int *countArray = NULL, *sortedArray = NULL;

	if (size < 2)
		return;
	maxValue = findMaximum(array, size);
	countArray = initializeZeroArray(maxValue + 1);
	if (!countArray)
		return;

	for (i = 0; i < size; i++)
	{
		countArray[array[i]] += 1;
	}

	for (i = 0; (int)i < maxValue; i++)
	{
		countArray[i + 1] = countArray[i] + countArray[i + 1];
	}
	print_array(countArray, maxValue + 1);
	sortedArray = malloc(size * sizeof(int));
	if (!sortedArray)
	{
		free(countArray);
		return;
	}
	for (i = 0; i < size; i++)
	{
		sortedArray[countArray[array[i]] - 1] = array[i];
		countArray[array[i]] -= 1;
	}
	for (j = 0; j < size; j++)
		array[j] = sortedArray[j];
	free(sortedArray);
	free(countArray);
}
