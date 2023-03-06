#include "main.h"

/**
 * _memset - Fills the first n bytes of the memory area pointed to by swith the constant byte b.
 *
 * @param s Pointer to the memory area to be filled.
 * @param b The constant byte to fill the memory with.
 * @param n The number of bytes to be filled.
 *
 * @return Pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned char *p = (unsigned char *) s;
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*p++ = (unsigned char) b;
	}

	return (s);
}
