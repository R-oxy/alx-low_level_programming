#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2D array of integers previously allocated by alloc_grid
 * @grid: the 2D array of integers to be freed
 * @height: the height of the 2D array
 *
 * Return: null
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	free(grid);
}
