#include "main.h"
#include <string.h>

/**
 * infinite_add - Adds two numbers
 * @n1: The first number as a string
 * @n2: The second number as a string
 * @r: The buffer to store the result
 * @size_r: The size of the buffer
 *
 * Return: A pointer to the result, or 0 if the result cannot be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = strlen(n1);
	int len2 = strlen(n2);

	if (len1 > size_r || len2 > size_r)
		return 0;

	for (int i = 0; i < len1 / 2; i++)
	{
        	char temp = n1[i];
        	n1[i] = n1[len1 - i - 1];
        	n1[len1 - i - 1] = temp;
	}

	for (int i = 0; i < len2 / 2; i++)
	{
        	char temp = n2[i];
		n2[i] = n2[len2 - i - 1];
        	n2[len2 - i - 1] = temp;
	}

	int carry = 0;
	int i = 0;

	while (i < size_r - 1 && (i < len1 || i < len2 || carry))
	{
        	int digit1 = i < len1 ? n1[i] - '0' : 0;
        	int digit2 = i < len2 ? n2[i] - '0' : 0;
        	int sum = digit1 + digit2 + carry;
        	r[i] = sum % 10 + '0';
        	carry = sum / 10;
        	i++;
	}

	if (i == size_r - 1 && (len1 > i || len2 > i || carry))
        	return 0;

	for (int j = 0; j < i / 2; j++)
	{
        	char temp = r[j];
        	r[j] = r[i - j - 1];
        	r[i - j - 1] = temp;
	}

	r[i] = '\0';

	return r;
}
