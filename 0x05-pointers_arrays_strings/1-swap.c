#include "main.h"

/**
  * swap_int - Swaps the values of two integers
  *
  * @a: First integer to swap
  * @b: The other integer to swap
  *
  * Return: void
  */
void swap_int(int *a, int *b)
{
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;
}
