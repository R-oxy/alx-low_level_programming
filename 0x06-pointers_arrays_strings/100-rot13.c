#include "main.h"

/**
 * rot13 - Encodes a string using rot13.
 * @s: The string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *rot13(char *s)
{
	int i, j;
	char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
  
	for (i = 0; s[i]; i++)
	{
  		for (j = 0; letters[j]; j++)
		{
			if (s[i] == letters[j])
			{
				s[i] = rot13[j];
				break;
			}
		}
	}

	return (s);
}
