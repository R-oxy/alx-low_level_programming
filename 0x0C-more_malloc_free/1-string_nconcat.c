#include "main.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * string_nconcat - Concatenates two strings s1 and s2, with the first n bytes of s2.
 * @s1: char* - The first string to concatenate.
 * @s2: char* - The second string to concatenate.
 * @n: unsigned int - The number of bytes to copy from s2.
 *
 * Return: null or a pointer to the newly allocated string.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0, i, j;
	char *result;

	if (s1 == NULL)
	{
		s1 = "";
	}

	if (s2 == NULL)
	{
		s2 = "";
	}

	len1 = strlen(s1);
	len2 = strlen(s2);

	if (n >= len2)
	{
		n = len2;
	}

	result = (char *) malloc(sizeof(char) * (len1 + n + 1));
	if (result == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len1; i++)
	{
		result[i] = s1[i];
	}

	for (j = 0; j < n; j++)
	{
		result[i+j] = s2[j];
	}

	result[i+j] = '\0';

	return (result);
}
