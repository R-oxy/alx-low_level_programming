#include "main.h"

/**
  * print_diagonal - Draws a diagonal line according to parameters
  * @n: The number of times the character \ should is printed
  *
  * Return: \n for n equal or less than zero
  */
void print_diagonal(int n)
{
	int i, j;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < i; j++)
			{
				_putchar(32);
			}

			_putchar(92);
			_putchar('\n');
		}
	}
}
