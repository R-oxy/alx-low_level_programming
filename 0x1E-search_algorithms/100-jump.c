#include "search_algos.h"

/**
* jump_search - Searches for a value in a sorted array
* using Jump search algorithm
* @array: Pointer to the first element of the array
* @size: Number of elements in the array
* @value: The value to search for
* Return: Index where the value is located or -1 if not found
*/
int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size);
	size_t left = 0, right = 0;
	size_t i;

	if (array == NULL)
		return (-1);

	while (right < size && array[right] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", right, array[right]);
		left = right;
		right += step;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", left, right);

	right = right < size ? right : size - 1;
	for (i = left; i <= right; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
