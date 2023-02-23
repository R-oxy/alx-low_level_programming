#include "main.h"

/**
  * _isdigit - Check if a character is a digit
  * @c: The character to be checked
  *
  * Return: 1 for c is a digit or 0 otherwise
  */
int _isdigit(int c)
{
	if (c >= 0 && c <= 9)
	{
		return (1);
	}

	return (0);
}
