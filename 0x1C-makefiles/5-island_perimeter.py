#!/usr/bin/python3
""" A function that returns a perimeter """

def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in grid.

    Args:
        grid (list): A list of list of integers representing the island grid.

    Returns:
        int: The perimeter of the island.
    """
    if len(grid) == 0 or grid is None:
        return 0

    height = len(grid)
    length = len(grid[0])
    perimeter = 0

    for lists in grid:
        for items in lists:
            if type(items) is not int:
                return

    for y in range(height):
        for x in range(length):
            if grid[y][x] == 0:
                continue
            if y == 0 or grid[y - 1][x] == 0:
                perimeter += 1
            if y == height - 1 or grid[y + 1][x] == 0:
                perimeter += 1
            if x == 0 or grid[y][x - 1] == 0:
                perimeter += 1
            if x == length - 1 or grid[y][x + 1] == 0:
                perimeter += 1
    return perimeter
