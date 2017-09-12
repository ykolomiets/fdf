//
// Created by columbiets on 03.05.17.
//

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

t_vertex	**malloc_map(int fd, char ***splited, int *rows, int *columns)
{
    char		*file;
    t_vertex	**res;
    int         j;

    file = read_file(fd);
    *splited = ft_strsplit(file, '\n');
    free(file);
    *rows = 0;
    *columns = 0;
    while ((*splited)[(*rows)])
    {
        j = ft_count_word((*splited)[(*rows)++], ' ');
        if (*rows == 1)
            *columns = j;
        else if (*columns != j)
        {
            ft_putendl("error: map is not rectangle");
            return (0);
        }
    }
    res = (t_vertex **)ft_malloc_2d_array(*rows, *columns, sizeof(t_vertex));
    return (res);
}

int         color_from_string(char *str)
{
    int res;

    res = -1;
    if (ft_strlen(str) == 8 &&
            (str[0] == '0' && str[1] == 'x'))
        res = ft_atoi_base(str + 2, "0123456789ABCDEF");
    else
        ft_putendl("error: wrong color format");
    return (res);
}

int         fill_vertex(t_vertex *ver, float x, float y, char **info)
{
    size_t  i;
    float   z;

    i = 0;
    while (info[0][i] && ft_isdigit((int)info[0][i]))
        i++;
    if (i == ft_strlen(info[0]))
        z = (float) ft_atoi(info[0]);
    else
    {
        ft_putendl("error: wrong coord");
        return (1);
    }
    ver->position = hv_create_point(x, y, z);
    if (info[1])
        ver->color = color_from_string(info[1]);
    else
        ver->color = 0xffffff;
    print_vertex(ver);
    return (0);
}

int			fill_map(t_vertex **map, char **splited, int rows, int columns)
{
    int		i;
    int		j;
    char    **temp;
    char    **vertex_info;

    i = 0;
    while (i < rows)
    {
        j = 0;
        temp = ft_strsplit(splited[i], ' ');
        while (j < columns)
        {
            vertex_info = ft_strsplit(temp[j], ',');
            if (fill_vertex(&map[i][j], (i - rows) / 2.0, (j - columns) / 2.0, vertex_info))
            {
                ft_free_table(&temp, columns);
                ft_free_table(&vertex_info, ft_table_size(vertex_info));
                return (1);
            }
            ft_free_table(&vertex_info, ft_table_size(vertex_info));
            j++;
        };
        ft_free_table(&temp, columns);
        i++;
    }
    return (0);
}

int       read_map(char *map_file, t_map *map)
{
    int         res;
    char        **splited;
    int         fd;

    fd = open(map_file, O_RDONLY);
    res = 1;
    if (fd)
    {
        map->verts = malloc_map(fd, &splited, &(map->rows), &(map->cols));
        if (map->verts && !fill_map(map->verts, splited, map->rows, map->cols))
            res = 0;
        ft_free_table(&splited, map->rows);
        close(fd);
    }
    return (res);
}