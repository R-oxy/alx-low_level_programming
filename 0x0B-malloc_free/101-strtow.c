#include "main.h"
#include <stdlib.h>
#include <string.h>

int count_words(char *str);
int word_len(char *str);

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, n;

	if (str == NULL || *str == '\0')
		return (NULL);

	n = count_words(str);
	if (n == 0)
		return (NULL);

	words = malloc((n + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (i = 0, j = 0; i < n; i++)
	{
		while (str[j] == ' ')
			j++;

		k = word_len(&str[j]);
		words[i] = malloc((k + 1) * sizeof(char));
		if (words[i] == NULL)
		{
                	for (i--; i >= 0; i--)
                        	free(words[i]);
			free(words);
			return (NULL);
		}

		for (k = 0; str[j] != ' ' && str[j] != '\0'; j++, k++)
                	words[i][k] = str[j];
		words[i][k] = '\0';
	}
	words[n] = NULL;
	return (words);
}

/**
 * count_words - counts the number of words in a string
 * @str: string to count words in
 *
 * Return: number of words in string
 */
int count_words(char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		if (*str != ' ')
		{
			count++;
			while (*str != ' ' && *str != '\0')
                        	str++;
		}
		else
		{
			str++;
		}
	}

	return (count);
}

/**
 * word_len - gets the length of a word
 * @str: string containing the word
 *
 * Return: length of word
 */
int word_len(char *str)
{
	int len = 0;

	while (*str != ' ' && *str != '\0')
	{
		len++;
		str++;
	}

	return (len);
}
