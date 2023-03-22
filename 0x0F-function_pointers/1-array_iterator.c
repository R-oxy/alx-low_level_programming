#include "function_pointers.h"

/**
 * array_iterator - Execute a function on each element of an array.
 *
 * @array: Pointer to the first element of the array.
 * @size: The size of the array.
 * @action: Pointer to the function
 *
 * Return: Nothing.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;
	if (array != NULL && action != NULL)
	{
		for (i = 0; i < size; i++)
		{
			action(array[i]);
		}
	}
}
