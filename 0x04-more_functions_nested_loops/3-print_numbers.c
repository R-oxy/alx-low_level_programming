#include "main.h"

/**
 * print_numbers - prints the numbers 0 to 9 followed by a new line
 *
 *Return - The values 0 to 9
 */
void print_numbers(void)
{
    int i;

    for (i = 0; i < 10; i++)
    {
        _putchar(i + '0');  // print the digit as a character
    }

    _putchar('\n');         // print a new line
}
