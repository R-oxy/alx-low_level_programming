#include "main.h"
/**
  * _isalpha - Checks for alphabetic character
  * @c: The character being checked
  *
  * Return: 1 for c an alphabetic character,lowercase/uppercase or 0 otherwise
  */
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}

	return (0);
}
