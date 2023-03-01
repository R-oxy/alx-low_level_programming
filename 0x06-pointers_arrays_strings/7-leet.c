#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: string to encode
 *
 * Return: pointer to the encoded string
 */
char *leet(char *s)
{
	int i, j;
	char leet[] = {'A', 'E', 'O', 'T', 'L'};
	char nums[] = {'4', '3', '0', '7', '1'};

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (s[i] == leet[j] || s[i] == leet[j] + 32)
			{
				s[i] = nums[j];
				break;
			}
		}
	}

	return (s);
}
