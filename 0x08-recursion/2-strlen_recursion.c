#include "main.h"

/**
 * _strlen_recursion - returns the length of a string using recursion
 * @s: the string whose length is to be calculated
 *
 * Return: the length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}

	s++;
	return (_strlen_recursion(s) + 1);
}
