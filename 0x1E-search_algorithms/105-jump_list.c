#include "search_algos.h"

/**
* jump_list - Searches for a value in a sorted singly linked list
*            using the Jump search algorithm.
* @list: A pointer to the head of the list to search in.
* @size: The number of nodes in the list.
* @value: The value to search for.
*
* Return: A pointer to the first node where value is located,
*         or NULL if the value is not present
*         in the list or if the list is NULL.
*/
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump_step = sqrt(size);
	listint_t *prev = list, *current = list;

	if (list == NULL)
	{
		return (NULL);
	}

	while (current->index < size && current->n < value)
	{
		prev = current;
		for (size_t i = 0; i < jump_step && current->next != NULL; i++)
		{
			current = current->next;
		}
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
	}

	printf(
		"Value found between indexes [%lu] and [%lu]\n", prev->index, current->index
		);

	while (prev->index <= current->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
		{
			return (prev);
		}
		prev = prev->next;
		if (prev == NULL)
		{
			break;
		}
	}

	return (NULL);
}
