#include "main.h"

/**
  * get_bit - the function name
  * @n: parameter of type unsigned long int .
  * @index: parameter of type unsigned int .
  * Return: int .
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
	{
		return (-1);
	}
	return ((n >> index) & 1);
}
