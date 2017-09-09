//
// Created by columbiets on 03.05.17.
//

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

t_vector4	**malloc_map(int fd, char ***splited, int *rows, int *columns)
{
    char		*file;
    t_vector4	**res;
    int         j;

    file = read_file(fd);
    *splited = ft_strsplit(file, '\n');
    free(file);
    *rows = 0;
    *columns = 0;
    while ((*splited)[(*rows)++])
    {
        j = ft_count_word(temp_str, '\t');
        if (*rows == 1)
            *columns = j;
        else if (*columns != j)
        {
            ft_putendl("map is not rectangle");
            return (0);
        }
    }
    ft_free_table(*splited, *rows);
    res = ft_malloc_2d_array(*rows, *columns, sizeof(t_vertex));
    return (res);
}

int			fill_map(t_vector4 **map, char **splited, int rows, int columns)
{
    int		i;
    int		j;
    char	**temp;

    i = 0;
    while (i < rows)
    {
        j = 0;
        temp = ft_strsplit(splited[i], ' ');
        while (j < columns)
        {
            map[i][j].x = j;
            map[i][j].y = i;
            map[i][j].z = -ft_atoi(temp[j]);
            map[i][j].w = 1;
            j++;
        };
        ft_free_table(&temp, columns);
        i++;
    }
    return (0);
}

t_vertex    *read_map(char *map_file, int *rows, int *cols)
{
    t_vertex    *res;
    char        **splited;
    int         fd;

    fd = open(map_file, O_RDONLY);
    if (fd)
    {
        res = malloc_map(fd, &splited, rows, columns);
        fill_map(res, splited, *rows, *columns);
        pretty_look(res, *rows, *columns);
        ft_free_table(&splited, *rows);
        close(fd);
    }
    return (0);
}