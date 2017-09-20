#include "libft.h"
#include "read_map.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

t_vertex        **malloc_map(int fd, char ***splited, int *rows, int *cols)
{
    char		*file;
    int         j;
    t_vertex    **vertices;

    file = read_file(fd);
    *splited = ft_strsplit(file, '\n');
    free(file);
    *rows = 0;
    *cols = 0;
    while ((*splited)[*rows])
    {
        j = ft_count_word((*splited)[(*rows)], ' ');
        if (++(*rows) == 1)
            *cols = j;
        else if (*cols != j)
        {
            ft_putendl("error: map is not rectangle");
            return (0);
        }
    }
    if (*rows == 0)
        return (0);
    vertices = (t_vertex **)ft_malloc_2d_array(*rows, *cols, sizeof(t_vertex));
    return (vertices ? vertices : 0);
}

t_rgb       color_from_string(char *str)
{
    int res;

    res = 0xffffff;
    if (ft_strlen(str) == 8 &&
            (str[0] == '0' && str[1] == 'x'))
        res = ft_atoi_base(str + 2, "0123456789ABCDEF");
    return (rgb_from_int(res));
}

int         fill_vertex(t_vertex *ver, float x, float y, char **info)
{
    size_t  i;

    i = 0;
    if (info[0][i] == '-')
        i++;
    while (info[0][i] && ft_isdigit((int)info[0][i]))
        i++;
    if (i == ft_strlen(info[0]))
        ver->real_z = ft_atoi(info[0]);
    else
    {
        ft_putendl("error: wrong coord");
        return (1);
    }
    ver->position = hv_create_point(x, y, ver->real_z / 10);
    if (info[1])
        ver->color = color_from_string(info[1]);
    else
        ver->color = rgb_from_int(0xffffff);
    return (0);
}

int			fill_map(t_vertex  **verts, char **table, int rows, int cols)
{
    int		i;
    int		j;
    char    **temp;
    char    **v_info;

    i = -1;
    while (++i < rows)
    {
        j = -1;
        temp = ft_strsplit(table[i], ' ');
        while (++j < cols)
        {
            v_info = ft_strsplit(temp[j], ',');
            if (fill_vertex(&verts[i][j], (float)j - (cols - 1) / 2.0f,
                            (float)i - (rows - 1) / 2.0f, v_info))
            {
                ft_free_table(&temp, cols);
                ft_free_table(&v_info, 2);
                return (1);
            }
            ft_free_table(&v_info, 2);
        };
        ft_free_table(&temp, cols);
    }
    return (0);
}


int       read_map(char *map_file, t_map *map)
{
    int         fd;
    char        **splited;
    t_vertex    **vertices;
    int         rows;
    int         cols;

    fd = open(map_file, O_RDONLY);
    if (fd != -1)
    {
        vertices = malloc_map(fd, &splited, &rows, &cols);
        printf("HERE: %d, %d\n", rows, cols);
        if (!vertices || fill_map(vertices, splited, rows, cols))
            return (1);
        map->lines = form_lines(vertices, &map->line_count, rows, cols);
        find_max_min_z(vertices, rows, cols, map);
        ft_free_2d_array((void ***)&vertices, rows);
        ft_free_table(&splited, rows);
        close(fd);
        return (0);
    }
    else
        return (1);
}