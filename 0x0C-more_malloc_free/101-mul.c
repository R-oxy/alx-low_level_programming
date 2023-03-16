#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int _strlen(char *s);
void *_memset(void *s, int c, unsigned int n);
void _puts(char *s);
void print_error(void);
int _atoi(char *s);
void *_calloc(unsigned int nmemb, unsigned int size);
void multiply(char *s1, char *s2);

/**
 * _strlen - Computes the length of a string
 *
 * @s: Pointer to the string
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
    int len = 0;

    while (*s != '\0')
    {
        len++;
        s++;
    }

    return len;
}

/**
 * _memset - Fills memory with a constant byte
 *
 * @s: Pointer to the start of the memory block
 * @c: Value to be set
 * @n: Number of bytes to be set to the value
 *
 * Return: Pointer to the start of the memory block
 */
void *_memset(void *s, int c, unsigned int n)
{
    unsigned int i;
    unsigned char *p = s;

    for (i = 0; i < n; i++)
        p[i] = c;

    return s;
}

/**
 * _puts - Prints a string to stdout
 *
 * @s: Pointer to the string
 */
void _puts(char *s)
{
    while (*s != '\0')
    {
        write(1, s, 1);
        s++;
    }
}

/**
 * print_error - Prints an error message to stderr and exits with status 98
 */
void print_error(void)
{
    _memset(&errno, 0, sizeof(errno));
    _puts("Error\n");
    exit(98);
}

/**
 * _atoi - Converts a string to an integer
 *
 * @s: Pointer to the string
 *
 * Return: The integer value of the string
 */
int _atoi(char *s)
{
    int res = 0;
    int sign = 1;

    if (*s == '-')
    {
        sign = -1;
        s++;
    }

    while (*s != '\0')
    {
        if (*s < '0' || *s > '9')
            print_error();

        res = res * 10 + (*s - '0');
        s++;
    }

    return sign * res;
}

/**
 * _calloc - Allocates memory for an array
 *
 * @nmemb: Number of elements in the array
 * @size: Size of each element in bytes
 *
 * Return: Pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
    void *mem;

    if (nmemb == 0 || size == 0)
        return NULL;

    mem = malloc(nmemb * size);

    if (mem == NULL)
        return NULL;

    _memset(mem, 0, nmemb * size);

    return mem;
}

/**
 * multiply - Multiplies two positive numbers represented as strings
 *
 * @s1: First number as a string
 * @s2: Second number as a string
 */
void multiply(char *s1, char *s2)
{
    int i, j, k, len1, len2, carry, num1, num2, *res;
    char *result;

    len1 = _strlen(s1);
    len2 = _strlen(s2);

    res = _calloc(len1 + len2, sizeof(int));

    if (res == NULL)
        print_error();

    for (i = len1 - 1; i >= 0; i--)
    {
        num1 = s1[i] - '0';
        carry = 0;

        for (j = len2 - 1; j >= 0; j--)
        {
            num2 = s2[j] - '0';
            k = i + j + 1;

            res[k] += num1 * num2 + carry;
            carry = res[k] / 10;
            res[k] %= 10;
        }

        res[i + j + 1] += carry;
    }

    while (*res == 0 && len1 + len2 > 1)
    {
        res++;
        len1--;
    }

    result = _calloc(len1 + len2 + 1, sizeof(char));

    if (result == NULL)
        print_error();

    for (i = 0; i < len1 + len2; i++)
        result[i] = res[i] + '0';

    result[i] = '\0';

    _puts(result);

    free(res);
}

int main(void)
{
    char s1[] = "1234";
    char s2[] = "5678";
    multiply(s1, s2);
    return 0;
}
