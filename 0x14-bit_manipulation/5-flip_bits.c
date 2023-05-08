#include "main.h"

/**
  * flip_bits - the function name
  * @n: parameter of type unsigned long int .
  * @m: parameter of type unsigned long int .
  * Return: unsigned int .
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flip = n ^ m;
	unsigned int count = 0;

	while (flip)
	{
		count += flip & 1;
		flip >>= 1;
	}
	return (count);
}
