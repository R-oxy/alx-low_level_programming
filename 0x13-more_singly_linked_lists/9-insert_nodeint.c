#include "lists.h"
#include <stdlib.h>

#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 * @head: Pointer to the head of the linked list
 * @idx: Index of the list where the new node should be added
 * @n: Data to be stored in the new node
 *
 * Return: Address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *temp_node;
	unsigned int i;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	temp_node = *head;
	for (i = 0; temp_node && i < idx - 1; i++)
		temp_node = temp_node->next;

	if (!temp_node)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = temp_node->next;
	temp_node->next = new_node;

	return (new_node);
}
