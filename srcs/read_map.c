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
    char		**tempstr;
    t_vector4	**res;
    int			i;

    file = read_file(fd);
    *splited = ft_strsplit(file, '\n');
    free(file);
    *rows = 0;
    *columns = 0;
    while ((*splited)[(*rows)])
        (*rows)++;
    tempstr = ft_strsplit((*splited)[0], ' ');
    while (tempstr[(*columns)])
        (*columns)++;
    ft_free_table(&tempstr, *columns);
    res = (t_vector4 **)malloc(sizeof(t_vector4 *) * (*rows));
    i = 0;
    while (i < *rows)
        res[i++] = (t_vector4 *)malloc(sizeof(t_vector4) * (*columns));
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

void        pretty_look(t_vector4 **map, int rows, int columns)
{
    t_matrix4   trans_matrix;
    double      scale_coef;

    if (rows > columns)
        scale_coef = (double) WIN_HEIGHT / rows / 1.5;
    else
        scale_coef = (double) WIN_WIDTH / columns / 1.5;
    m4_identity(trans_matrix);
    m4_translate(trans_matrix, -((columns - 1) / 2.0), -((rows - 1) / 2.0), 0);
    m4_scale(trans_matrix, scale_coef, scale_coef, 1);
    m4_translate(trans_matrix, WIN_WIDTH / 2.0 , WIN_HEIGHT / 2.0, 0);
    map_change(map, rows, columns, trans_matrix);
}

t_vector4	**read_map(char *map_file, int *rows, int* columns)
{
    t_vector4	**res;
    char		**splited;
    int			fd;

    fd = open(map_file, O_RDONLY);
    res = malloc_map(fd, &splited, rows, columns);
    fill_map(res, splited, *rows, *columns);
    pretty_look(res, *rows, *columns);
    ft_free_table(&splited, *rows);
    close(fd);
    return (res);
}