#include "read_map.h"
#include <stdlib.h>

int    lines_from_verts(t_line **lines, t_vertex **verts, int rows, int cols)
{
    int count;
    int i;
    int k;

    count = 2 * cols * rows - rows - cols;
    *lines = (t_line *)malloc(sizeof(t_line) * (count));
    k = -1;
    if (*lines)
        while (rows--)
        {
            i = -1;
            while (++i < cols)
            {
                if (rows)
                {

                    (*lines)[++k].p1= verts[rows][i];
                    (*lines)[k].p2 = verts[rows - 1][i];
                }
                if (i != cols - 1)
                {
                    (*lines)[++k].p1 = verts[rows][i];
                    (*lines)[k].p2 = verts[rows][i + 1];
                }
            }
        }
    return (count);
}

t_line  *form_lines(t_vertex **verts, int *lines_count, int rows, int cols)
{
    t_line  *lines;

    if (rows == 1 && cols == 1)
    {
        lines = (t_line *)malloc(sizeof(t_line));
        if (lines)
        {
            lines[0].p1 = verts[0][0];
            lines[0].p2 = verts[0][0];
        }
    }
    else
    {
        *lines_count = lines_from_verts(&lines, verts, rows, cols);
    }
    return (lines);
}

void    find_max_min_z(t_vertex **verts, int rows, int cols, t_map *map)
{
    int     i;
    int     j;

    i = 0;
    map->min_z = verts[0][0].real_z;
    map->max_z = verts[0][0].real_z;
    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            if (verts[i][j].real_z > map->max_z)
                map->max_z = verts[i][j].real_z;
            if (verts[i][j].real_z < map->min_z)
                map->max_z = verts[i][j].real_z;
            j++;
        }
        i++;
    }
}