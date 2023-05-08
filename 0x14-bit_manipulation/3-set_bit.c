#include "main.h"

/**
  * set_bit - the function name
  * @n: parameter of type unsigned long int *.
  * @index: parameter of type unsigned int .
  * Return: int .
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > (sizeof(unsigned long int) * 8 - 1))
	{
		return (-1);
	}
	*n |= (1 << index);
	return (1);
}
