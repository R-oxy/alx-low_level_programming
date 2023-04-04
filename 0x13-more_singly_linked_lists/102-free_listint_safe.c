#include <stdlib.h>
#include "lists.h"
#include <stdio.h>

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: A pointer to the head node of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
    size_t count = 0;
    listint_t *tmp;

    if (!h || !*h)
        return (count);

    while (*h)
    {
        count++;
        if ((*h)->next >= *h)
        {
            free(*h);
            *h = NULL;
            break;
        }
        tmp = (*h)->next;
        free(*h);
        *h = tmp;
    }

    return (count);
}
