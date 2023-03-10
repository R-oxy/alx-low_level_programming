#include <stdio.h>
#include "main.h"

/**
 * main - Prints all the arguments passed to the program
 * @argc: Number of arguments passed to the program
 * @argv: Array of strings containing the arguments passed to the program
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}
