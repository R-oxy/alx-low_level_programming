#include "main.h"

/**
  * binary_to_uint - the function name
  * @b: parameter of type const char *.
  * Return: unsigned int .
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int i = 0;

	if (b == NULL)
	{
		return (0);
	}
	while (b[i] != '\0')
	{
		if (b[i] != '0' && b[i] != '1')
		{
			return (0);
		}
		num <<= 1;
		if (b[i] == '1')
		{
			num += 1;
		}
		i++;
	}
	return (num);
}
