#include "search_algos.h"

/**
* advanced_binary_helper - Recursive helper function for advanced_binary.
* @array: A pointer to the first element of the array to search in.
* @left: The leftmost index of the subarray.
* @right: The rightmost index of the subarray.
* @value: The value to search for.
*
* Return: The first index where the value is located, or -1 if the value
*         is not present in the array or if the array is NULL.
*/
int advanced_binary_helper(int *array, size_t left, size_t right, int value)
{
	size_t mid, i;

	if (left <= right)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
		{
			printf("%d, ", array[i]);
		}
		printf("%d\n", array[right]);

		mid = left + (right - left) / 2;

		if (array[mid] == value)
		{
			if (mid == 0 || array[mid - 1] != value)
				return ((int)mid);
			else
				return (advanced_binary_helper(array, left, mid, value));
		}

		if (array[mid] < value)
		{
			return (advanced_binary_helper(array, mid + 1, right, value));
		}
		else
		{
			return (advanced_binary_helper(array, left, mid, value));
		}
	}

	return (-1);
}

/**
* advanced_binary - Searches for a value in a sorted array of integers
*                   using a modified Binary search algorithm.
* @array: A pointer to the first element of the array to search in.
* @size: The number of elements in the array.
* @value: The value to search for.
*
* Return: The first index where the value is located, or -1 if the value
*         is not present in the array or if the array is NULL.
*/
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
	{
		return (-1);
	}

	return (advanced_binary_helper(array, 0, size - 1, value));
}
