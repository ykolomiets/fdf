#include "world_transformations.h"

void    change_z(t_vertex **verts, int rows, int cols, float diff)
{
    int     i;
    hvector pos;

    while (rows--)
    {
        i = 0;
        while (i < cols)
        {
            pos = verts[rows][i++].position;
            pos[2] *= diff;
        }
    }
}

void    scale_all(t_vertex **verts, int rows, int cols, float coef)
{
    int     i;
    hvector pos;

    while (rows--)
    {
        i = 0;
        while (i < cols)
        {
            pos = verts[rows][i++].position;
            pos[0] *= coef;
            pos[1] *= coef;
            pos[2] *= coef;
        }
    }
}