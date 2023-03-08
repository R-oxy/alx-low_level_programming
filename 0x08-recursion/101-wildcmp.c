#include "main.h"

/**
 * wildcmp - compares two strings and returns 1 if they are identical, 0 otherwise
 * @s1: the first string to compare
 * @s2: the second string to compare
 *
 * Return: 1 if s1 and s2 are identical, 0 otherwise
 */

int wildcmp(char *s1, char *s2)
{
	if (*s2 == '\0')
	{
		return (*s1 == '\0');
	}

	if (*s2 == '*')
	{
		while (*s2 == '*')
		{
			s2++;
		}

		if (*s2 == '\0')
		{
			return 1;
		}

		while (*s1 != '\0' && *s2 != '\0')
		{
			if (*s1 == *s2 || *s2 == '?')
			{
				if (wildcmp(s1 + 1, s2 + 1))
				{
					return 1;
				}
			}

			s1++;
		}

		return 0;
	}
	else
	{
		if (*s1 == *s2 || *s2 == '?')
		{
			if (wildcmp(s1 + 1, s2 + 1))
			{
				return 1;
			}
		}
		return 0;
	}
}
