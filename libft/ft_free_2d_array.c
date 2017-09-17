#include "libft.h"
#include <stdlib.h>

void    ft_free_2d_array(void ***arr, int rows)
{
    int i;

    i = 0;
    while (i < rows)
        free((*arr)[i++]);
    free((*arr));
    *arr = 0;
}