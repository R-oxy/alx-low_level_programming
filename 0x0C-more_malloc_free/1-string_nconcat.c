#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * string_nconcat - Concatenates two strings s1 and s2, with the first n bytes of s2.
 * @s1: char* - The first string to concatenate.
 * @s2: char* - The second string to concatenate.
 * @n: unsigned int - The number of bytes to copy from s2.
 *
 * Return: null or a pointer to the newly allocated string.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
        char *concatenated_string;
        unsigned int len1, len2, i;

        if (s1 == NULL)
        {
                s1 = "";
        }

        if (s2 == NULL)
        {
                s2 = "";
        }

        len1 = 0;
        while (s1[len1] != '\0')
        {
                len1++;
        }

        len2 = 0;
        while (s2[len2] != '\0')
        {
                len2++;
        }

        if (n >= len2)
        {
                n = len2;
        }

        concatenated_string = malloc((len1 + n + 1) * sizeof(char));
        if (concatenated_string == NULL)
        {
                exit(98);
        }

        for (i = 0; i < len1; i++)
        {
                concatenated_string[i] = s1[i];
        }

        for (i = 0; i < n; i++)
        {
                concatenated_string[len1 + i] = s2[i];
        }

        concatenated_string[len1 + n] = '\0';

        return (concatenated_string);
}
