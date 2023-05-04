#include "main.h"

/**
  * clear_bit - the function name
  * @n: parameter of type unsigned long int *.
  * @index: parameter of type unsigned int .
  * Return: int .
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index >= (sizeof(unsigned long int) * 8))
	{
		return (-1);
	}
	mask = 1 << index;
	mask = ~mask;
	*n = *n & mask;
	return (1);
}
