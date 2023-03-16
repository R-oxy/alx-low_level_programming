#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * malloc_checked - Allocate memory using malloc.
 * b: unsigned int - The number of bytes to allocate.
 *
 * Return:void* - A pointer to the allocated memory.
 */
void *malloc_checked(unsigned int b)
{
	void *p;

	p = malloc(b);

	if (p == NULL)
		exit(98);

	return (p);
}
