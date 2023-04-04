#include <stdio.h>
#include "lists.h"

/**
  * listint_len - Returns number of elements in listint_t list.
  * @h: pointer to head of listint_t list.
  *
  * Return: number of nodes in listint_t list.
  */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}
