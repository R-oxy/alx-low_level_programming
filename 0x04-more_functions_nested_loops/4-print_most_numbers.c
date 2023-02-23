#include "main.h"

/**
 * print_most_numbers - prints the numbers 0 to 9, excluding 2 and 4, followed by a new line
 *
 * Return - The numbers 0 to 9 excluding 2 and 4
 */
void print_most_numbers(void)
{
    int i;

    for (i = 0; i < 10; i++)
    {
        if (i != 2 && i != 4)
        {
            _putchar(i + '0');  // print the digit as a character
        }
    }

    _putchar('\n');         // print a new line
}
