#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - Prints a listint_t linked list
 * @head: Pointer to the head node of the linked list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *node, *tmp;

	if (!head)
		exit(98);

	node = head;
	while (node)
	{
		count++;
		printf("[%p] %d\n", (void *)node, node->n);

		tmp = node;
		node = node->next;

		if (tmp <= node)
		{
			printf("-> [%p] %d\n", (void *)node, node->n);
			exit(98);
		}
	}

	return (count);
}
