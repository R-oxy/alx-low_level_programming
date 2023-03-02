#include "main.h"
#include <stdio.h>

/**
 * _strcat - Concatenates two strings.
 * Appends the src string to the dest string, overwriting the terminating null byte
 * at the end of dest, and then adds a terminating null byte.
 * 
 * @param dest Pointer to the destination string.
 * @param src Pointer to the source string.
 * 
 * @return Pointer to the resulting string dest.
 */
char* _strcat(char* dest, char* src)
{
	int dlen = 0, i;

	while (dest[dlen])
	{
		dlen++;
	}

	for (i = 0; src[i] != 0; i++)
	{
		dest[dlen] = src[i];
		dlen++;
	}

	dest[dlen] = '\0';
	return (dest);
}
