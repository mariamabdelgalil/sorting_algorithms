#ifndef _SORT_H_
#define _SORT_H_
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void merge_array(int *array, int lowIndex,
int midIndex, int highIndex, int *buffer);
void merge_rec(int *array, int low, int high, int *temp_buffer);
void merge_sort(int *arr, size_t len);
void swapNodes(listint_t **head, listint_t *node1, listint_t *node2);
void bubbleUp(listint_t **list, listint_t **leftBound,
listint_t *rightBound, int *swapped);
void bubbleDown(listint_t **list, listint_t **leftBound, int *swapped);
void cocktail_sort_list(listint_t **list);
#endif
