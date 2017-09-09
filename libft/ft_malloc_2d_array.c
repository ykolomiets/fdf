#include <stdlib.h>

void    *ft_malloc_2d_array(int rows, int columns, int elem_size)
{
    void    **res;

    res = malloc(sizeof(void*) * rows);
    while (rows--)
        res[rows] = malloc(elem_size * columns);

    return ((void *)res);
}

