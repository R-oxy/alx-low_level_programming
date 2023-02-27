#include "main.h"
#include <stdio.h>

/**
  * print_rev - prints a string in reverse, followed by a newline character
  * @s: the string to print
  *
  *Return: void
  */
void print_rev(char *s)
{
	int i, len = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	for (i = len - 1; i >= 0; i--)
	{
		putchar(s[i]);
	}

	putchar('\n');
}
