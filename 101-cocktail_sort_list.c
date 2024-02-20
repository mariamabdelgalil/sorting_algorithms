#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swapNodes - Function to swap two nodes in a doubly linked list
 * Return: Nothing
 * Prototype: void swapNodes(listint_t **head,
 * listint_t *node1, listint_t *node2);
 * @head: The pointer to the head of the list
 * @node1: The first node to swap
 * @node2: The second node to swap
 */
void swapNodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*head = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (node1->next)
		node1->next->prev = node1;
}

/**
 * bubbleUp - Function to perform bubble up operation in
 * a doubly linked list
 * Return: Nothing
 * Prototype: void bubbleUp(listint_t **list,
 * listint_t **leftBound, listint_t *rightBound, int *swapped);
 * @list: The pointer to the head of the list
 * @leftBound: The pointer to the left bound of the list
 * @rightBound: The pointer to the right bound of the list
 * @swapped: The pointer to the swapped variable
 */
void bubbleUp(listint_t **list, listint_t **leftBound,
		listint_t *rightBound, int *swapped)
{
	*swapped = 0;
	*leftBound = (*list);
	while ((*leftBound)->next != rightBound)
	{
		if ((*leftBound)->n > (*leftBound)->next->n)
		{
			swapNodes(list, *leftBound, (*leftBound)->next);
			print_list(*list);
			*swapped = 1;
		}
		else
		{
			*leftBound = (*leftBound)->next;
		}
	}
}

/**
 * bubbleDown - Function to perform bubble down operation
 * in a doubly linked list
 * Return: Nothing
 * Prototype: void bubbleDown(listint_t **list,
 * listint_t **leftBound, int *swapped);
 * @list: The pointer to the head of the list
 * @leftBound: The pointer to the left bound of the list
 * @swapped: The pointer to the swapped variable
 */
void bubbleDown(listint_t **list, listint_t **leftBound, int *swapped)
{
	*swapped = 0;
	while ((*leftBound)->prev != NULL)
	{
		if ((*leftBound)->n < (*leftBound)->prev->n)
		{
			swapNodes(list, (*leftBound)->prev, *leftBound);
			print_list(*list);
			*swapped = 1;
		}
		else
		{
			*leftBound = (*leftBound)->prev;
		}
	}
}

/**
 * cocktail_sort_list - Function to perform cocktail
 * sort algorithm on a doubly linked list
 * Return: Nothing
 * Prototype: void cocktail_sort_list(listint_t **list);
 * @list: The pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *leftBound = NULL;
	listint_t *rightBound = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		bubbleUp(list, &leftBound, rightBound, &swapped);
		if (!swapped)
			break;
		rightBound = leftBound;
		bubbleDown(list, &leftBound, &swapped);
	}
}
