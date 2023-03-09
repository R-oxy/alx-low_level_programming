#include "main.h"

/**
 * wildcmp - compares if two strings are identical
 * @s1: the first string to compare
 * @s2: the second string to compare
 *
 * Return: 1 if s1 and s2 are identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}

	if (*s2 == '*')
	{
		return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));
	}

	if (*s1 == '\0' || *s2 == '\0')
	{
		return (0);
	}

	if (*s1 == *s2)
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}

	return (0);
}
