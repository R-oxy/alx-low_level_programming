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
	char* dest_end = dest;

	while (*dest_end != '\0')
	{
		dest_end++;
	}

	while (*src != '\0')
	{
		*dest_end = *src;
		dest_end++;
		src++;
	}

	*dest_end = '\0';

	return (dest);
}
