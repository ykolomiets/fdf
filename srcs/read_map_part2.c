#include "read_map.h"
#include <stdlib.h>
#include <stdio.h>

void        print_line1(t_line *line)
{
    printf("\nline:\n{\n"
                   "\tp1: <%f, %f, %f, %f>\n"
                   "\tp2: <%f, %f, %f, %f>\n"
                   "}",
           line->p1.position.x,
           line->p1.position.y,
           line->p1.position.z,
           line->p1.position.w,
           line->p2.position.x,
           line->p2.position.y,
           line->p2.position.z,
           line->p2.position.w
    );
}

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