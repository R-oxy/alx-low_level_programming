#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring
 * @haystack: string to search
 * @needle: substring to find
 *
 * Return: pointer to beginning of located substring, or NULL if not found
 */
char *_strstr(char *haystack, char *needle)
{
	char *start;
	char *search;

	while (*haystack != '\0')
	{
		start = haystack;
		search = needle;

		while (*haystack == *search && *search != '\0' && *haystack != '\0')
		{
			haystack++;
			search++;
		}

		if (*search == '\0')
			return (start);

		haystack = start + 1;
	}

	return (NULL);
}
