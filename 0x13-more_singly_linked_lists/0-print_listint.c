#include <stdio.h>
#include "lists.h"

/**
  * print_listint - Prints all elements of listint_t list.
  * @h: pointer to the head of listint_t list.
  *
  * Return: number of nodes in listint_t list.
  */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	if (h != NULL)
	{
		while (h)
		{
			printf("%d\n", h->n);
			h = h->next;
			count++;
		}
	}

	return (count);
}
