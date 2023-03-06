#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the input string
 * @accept: the set of acceptable characters
 *
 * Return: the number of bytes in the initial segment of s which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int len = 0;
	char *p = accept;

	while (*s != '\0')
	{
		p = accept;
		while (*p != '\0')
		{
			if (*s == *p)
			{
				len++;
				break;
			}
			p++;
		}
		if (*p == '\0')
		{
			break;
		}
		s++;
	}
	return (len);
}
