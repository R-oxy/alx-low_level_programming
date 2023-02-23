#include "main.h"

/**
 *print_line - draws a straight line in the terminal
 *
 *@n: number of times the character _ should be printed
 *
 *Return - \n for n less than or equal to zero
 */
void print_line(int n)
{
	int n;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			_putchar(95);
		}

		_putchar('\n');
	}
}
