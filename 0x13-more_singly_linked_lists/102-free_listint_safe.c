#include <stdlib.h>
#include "lists.h"
#include <stdio.h>

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: address of node where loop starts/NULL for no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *tortoise, *hare;

    if (head == NULL)
        return (NULL);

    tortoise = hare = head;

    while (hare && hare->next)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;

        if (tortoise == hare)
        {
            tortoise = head;

            while (tortoise != hare)
            {
                tortoise = tortoise->next;
                hare = hare->next;
            }

            return (tortoise);
        }
    }

    return (NULL);
}
