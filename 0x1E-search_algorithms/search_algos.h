#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/* Structures */
/**
 * struct skiplist_s - Singly linked list with an express lane
 * @n: Integer stored in the node
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 */
typedef struct skiplist_s
{
    int n;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for ALX project
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/* Function Prototypes */
int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);
skiplist_t *linear_skip(skiplist_t *list, int value);

#endif /* SEARCH_ALGOS_H */
