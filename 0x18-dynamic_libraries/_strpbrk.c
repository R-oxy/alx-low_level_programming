#include "main.h"

char *_strpbrk(char *s, char *accept)
{
    while (*s)
    {
        char *a = accept;
        while (*a)
        {
            if (*a == *s)
                return s;
            a++;
        }
        s++;
    }
    return NULL;
}
