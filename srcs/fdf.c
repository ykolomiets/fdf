#include "fdf.h"
#include "libft.h"

void        fdf(char    *file_name)
{
    t_map   map;

    if (read_map(file_name, &map))
        ft_putendl("error: invalid map");
    else
        ft_putendl("all went right");
}


