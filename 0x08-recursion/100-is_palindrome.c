#include "main.h"

int check_palindrome(char *s, int start, int end);

/**
  * is_palindrome - Returns if a string is palindrome
  * @s: the string value to be checked
  *
  * Return: integer value
  */
int is_palindrome(char *s)
{
	if (*s == '\0')
		return (1);

	return (check_palindrome(s, 0, _strlen_recursion(s) - 1));
}

/**
  * check_palindrome - Check if a string is palindrome
  * @s: the string value to be checked
  * @start: the starting index of the string to check
  * @end: the ending index of the string to check
  *
  * Return: integer value
  */
int check_palindrome(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] != s[end])
		return (0);

	return (check_palindrome(s, start + 1, end - 1));
}

/**
  * _strlen_recursion - Get the length of a string
  * @s: the string to get the length
  *
  * Return: the string length
  */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);

	return (_strlen_recursion(s + 1) + 1);
}
