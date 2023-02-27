#include "main.h"

/**
  * rev_string - reverses a string
  * @s: string to be reversed
  *
  * Description: This function takes a pointer to a string and reverses the
  *              order of the characters in the string in place, meaning that
  *              the original string is modified.
  * Return: void
  */

void rev_string(char *s)
{
	int len = 0;
	int i, j;
	char temp;

	while (s[len] != '\0')
	{
		len++;
	}

	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}
