//
// Created by columbiets on 03.05.17.
//

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int         malloc_map(int fd, char ***splited, t_map *map)
{
    char		*file;
    int         j;

    file = read_file(fd);
    *splited = ft_strsplit(file, '\n');
    free(file);
    map->rows = 0;
    map->cols = 0;
    while ((*splited)[map->rows])
    {
        j = ft_count_word((*splited)[map->rows++], ' ');
        if (map->rows == 1)
            map->cols = j;
        else if (map->cols != j)
        {
            ft_putendl("error: map is not rectangle");
            return (1);
        }
    }
    map->verts = (t_vertex **)ft_malloc_2d_array(map->rows, map->cols, sizeof(t_vertex));
    map->transformed = (t_vertex **)ft_malloc_2d_array(map->rows, map->cols, sizeof(t_vertex));
    for (int i = 0; i < map->rows; i++)
    {
        for (int j = 0; j < map->cols; j++)
        {
            map->transformed[i][j].position = hv_create_point(0, 0, 0);
        }
    }
    return (0);
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
    if (info[0][i] == '-')
        i++;
    while (info[0][i] && ft_isdigit((int)info[0][i]))
        i++;
    if (i == ft_strlen(info[0]))
        z = (float) ft_atoi(info[0]) / 10.0f;
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
            if (fill_vertex(&map[i][j], (float)j - (columns - 1) / 2.0f, (float)i - (rows - 1) / 2.0f, vertex_info))
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

t_line_segment  *form_line_segments(t_vertex **verts, int *lines_count, int cols, int rows)
{
    t_line_segment  *lines;
    int             k;
    int             i;

    *lines_count = 2 * cols * rows - rows - cols;
    if (*lines_count)
    {
        lines = (t_line_segment *)malloc(sizeof(t_line_segment) * (*lines_count));
        k = -1;
        while(rows--)
        {
            i = -1;
            while (++i < cols)
            {
                if (rows)
                {
                    lines[++k].p1 = &verts[rows][i];
                    lines[k].p2 = &verts[rows - 1][i];
                }

                if (i != cols - 1)
                {
                    lines[++k].p1 = &verts[rows][i];
                    lines[k].p2 = &verts[rows][i + 1];
                }
            }
        }
    }
    else
    {
        lines = (t_line_segment *)malloc(sizeof(t_line_segment));
        lines[0].p1 = &verts[0][0];
        lines[1].p2 = &verts[0][0];
    }
    return (lines);
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
        if (!malloc_map(fd, &splited, map) && !fill_map(map->verts, splited, map->rows, map->cols))
        {
            map->lines = form_line_segments(map->transformed, &map->line_count, map->cols, map->rows);
            res = 0;
        }
        ft_free_table(&splited, map->rows);
        close(fd);
    }
    return (res);
}