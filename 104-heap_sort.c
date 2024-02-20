#include "sort.h"

/**
 * exchange_elements - Exchanges two elements in an array.
 * @arr: The array to perform the exchange in.
 * @idx1: The index of the first element to exchange.
 * @idx2: The index of the second element to exchange.
 * @pri_Size: The constant size for printing arrays.
 */
void exchange_elements(int *arr, int idx1, int idx2, const int pri_Size)
{
	int temp;
	(void)pri_Size;

	if (idx1 != idx2)
	{
		temp = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = temp;
		print_array(arr, (size_t)pri_Size);
	}
}

/**
 * find_largest - Finds the largest element in an array.
 * @arr: The array to search.
 * @size: The size of the array.
 * @idx: The index of the largest element.
 * @pri_Size: The constant size for printing arrays.
 */
void find_largest(int *arr, size_t size, int idx, const int pri_Size)
{
	int largest = idx;
	int L = (2 * idx) + 1;
	int R = (2 * idx) + 2;

	if (L < (int)size && arr[L] > arr[largest])
		largest = L;

	if (R < (int)size && arr[R] > arr[largest])
		largest = R;

	if (largest != idx)
	{
		exchange_elements(arr, idx, largest, pri_Size);
		find_largest(arr, size, largest, pri_Size);
	}
}

/**
 * heap_sort - Sorts an array using heap sort algorithm.
 * @arr: The array to sort.
 * @size: The size of the array.
 */
void heap_sort(int *arr, size_t size)
{
	const int pri_Size = (const int)size;
	int i;

	if (size < 2 || !arr)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		find_largest(arr, size, i, pri_Size);

	for (i = size - 1; i >= 0; i--)
	{
		exchange_elements(arr, 0, i, pri_Size);
		find_largest(arr, i, 0, pri_Size);
	}
}
