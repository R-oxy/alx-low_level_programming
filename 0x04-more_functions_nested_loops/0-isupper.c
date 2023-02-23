#include "main.h"

/**
  * _isupper - Check if a character is uppercase
  * @c: The character to be checked
  *
  * Return: 1 for c is  uppercase and 0 otherwise
  */
int _isupper(int c);
{
	if (c >= 65 && c <= 90)
	{
		return (1);
	}

	return (0);
}
