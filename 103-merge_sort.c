#include "sort.h"


/**
 * merge_sort - Write a function that sorts an array
 * of integers in ascending order using the Merge sort algorithm
 * using the Merge sort algorithm
 * @arr: The array to be sorted
 * @len: The size of the array
 */

void merge_sort(int *arr, size_t len)
{
	/* Allocate memory for a temporary buffer to assist with merging */
	int *temp_buffer;

	/* Return early if the array is NULL or its length is less than 2 */
	if (arr == NULL || len < 2)
		return;

	temp_buffer = malloc(sizeof(int) * (len + 1));

	/* If memory allocation for the temporary buffer fails, return early */
	if (temp_buffer == NULL)
		return;

	/* Execute the recursive merge sort starting from the full array range */
	merge_rec(arr, 0, len - 1, temp_buffer);

	/* Free the memory allocated for the temporary buffer */
	free(temp_buffer);
}

/**
 * merge_rec - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: The array to be sorted
 * @low: Lowest index of split
 * @high: high index of split
 * @temp_buffer: temp array for merging
 */

void merge_rec(int *array, int low, int high, int *temp_buffer)
{
	int mid;
	/* Check if low index is smaller than high, */
	/* if not, then it is the base case */
	if (low < high)
	{
		/* Find the middle point to divide the array into two halves */
		mid = ((high + low - 1) / 2);

		/* Recursively sort the first half */
		merge_rec(array, low, mid, temp_buffer);
		/* Recursively sort the second half */
		merge_rec(array, mid + 1, high, temp_buffer);

		/* Output the progress */
		printf("Merging...\n");

		/* Merge the sorted halves */
		merge_array(array, low, mid, high, temp_buffer);
	}
}

/**
 * merge_array - Integrates two sorted subarrays into one sorted array
 * @array: The main array containing the subarrays to be combined
 * @lowIndex: Index at which the first subarray starts
 * @midIndex: Index separating the first and second subarray
 * @highIndex: Index at which the second subarray ends
 * @buffer: Temporary array used for merging elements
 */

void merge_array(int *array, int lowIndex,
int midIndex, int highIndex, int *buffer)
{	/* Cursors for left, right, and merged arrays */
	int leftCursor, rightCursor, mergeCursor;
	int leftTempSize, rightTempSize;				/*Sizes of left & right temporary arrays*/
	int debugIdx;									/* Index used for debugging output */
	int leftTempArray[2048], rightTempArray[2048];	/*Temporary arrays for L & R*/
	/* Initialize indices and sizes */
	leftCursor = lowIndex, rightCursor = midIndex + 1,
	mergeCursor = leftTempSize = rightTempSize = 0;
	/* Merge elements from left and right halves until one is exhausted */
	while (leftCursor <= midIndex && rightCursor <= highIndex)
	{
		if (array[leftCursor] <= array[rightCursor])
			buffer[mergeCursor] = leftTempArray[leftTempSize] = array[leftCursor],
			mergeCursor++, leftCursor++, leftTempSize++;
		else
			buffer[mergeCursor] = rightTempArray[rightTempSize] = array[rightCursor],
			mergeCursor++, rightCursor++, rightTempSize++;
	}
	while (leftCursor <= midIndex) /* Copy remaining elements from left half */
		buffer[mergeCursor] = leftTempArray[leftTempSize] = array[leftCursor],
		mergeCursor++, leftCursor++, leftTempSize++;
	while (rightCursor <= highIndex) /* Copy remaining elements from right half */
		buffer[mergeCursor] = rightTempArray[rightTempSize] = array[rightCursor],
		mergeCursor++, rightCursor++, rightTempSize++;
	printf("[left]: ");
	for (debugIdx = 0; debugIdx < leftTempSize; debugIdx++)
	{	/* Debug output for the left temporary array */
		(debugIdx == 0) ? printf("%d", leftTempArray[debugIdx]) :
		printf(", %d", leftTempArray[debugIdx]);
	}
	printf("\n[right]: ");
	/* Debug output for the right temporary array */
	for (debugIdx = 0; debugIdx < rightTempSize; debugIdx++)
		(debugIdx == 0) ? printf("%d", rightTempArray[debugIdx]) :
		printf(", %d", rightTempArray[debugIdx]);
	printf("\n[Done]: ");
	/* Finalize merging by copying sorted elements back to the original array */
	for (leftCursor = lowIndex; leftCursor <= highIndex; leftCursor++)
		array[leftCursor] = buffer[leftCursor - lowIndex],
		printf("%d", array[leftCursor]);
		(leftCursor != highIndex) ? printf(", ") : printf("\n");
}
