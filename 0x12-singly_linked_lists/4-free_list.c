#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees a linked list.
 * @head: The pointer to the first node of linked list
 *
 * This function frees all the memory allocated for a linked list.
 * It starts by freeing the memory of the last node, and traverses the
 * list backwards until it reaches the first node. It is important to
 * free the nodes in this order to prevent memory leaks.
 *
 * Return: Nothing
 */
void free_list(list_t *head)
{
	list_t *current = head;
	list_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
}
