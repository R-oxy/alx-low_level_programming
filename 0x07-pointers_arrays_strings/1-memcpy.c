#include "main.h"

/**
 * _memcpy - Copies n bytes from memory area src to memory area dest.
 *
 * @param dest Pointer to the memory area to copy the bytes to.
 * @param src Pointer to the memory area to copy the bytes from.
 * @param n The number of bytes to be copied.
 *
 * @return Pointer to the memory area dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned char *p_dest = (unsigned char *) dest;
	unsigned char *p_src = (unsigned char *) src;
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*p_dest++ = *p_src++;
	}

	return (dest);
}
