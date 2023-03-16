#include "main.h"
#include <stdlib.h>

/**
 * _calloc - Allocate memory for an array.
 * @nmemb: Number of elements to allocate memory for
 * @size: Size of each element in bytes
 *
 * Return: Pointer to the allocated memory, or NULL
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
        void *ptr;
        unsigned int total_size;
	unsigned int i;

        if (nmemb == 0 || size == 0)
        {
                return (NULL);
        }

        total_size = nmemb * size;

        ptr = malloc(total_size);
        if (ptr == NULL)
        {
                return (NULL);
        }
	
        for (i = 0; i < total_size; i++)
        {
                *((char *) ptr + i) = 0;
        }

        return (ptr);
}
