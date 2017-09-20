#include "clipping.h"
#include <stdio.h>

void    swap_vertices(t_vertex *v1, t_vertex *v2)
{
    t_vertex    tmp;

    tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}

int     clip_near(t_line *line, float z)
{
    float   t;

    if (line->p1.position.z <= z && line->p2.position.z <= z)
        return (1);
    else if (line->p1.position.z > z && line->p2.position.z > z)
        return (0);
    if (line->p1.position.z < line->p2.position.z)
        swap_vertices(&line->p1, &line->p2);
    t =(z - line->p1.position.z) / (line->p2.position.z - line->p1.position.z);
    line->p1.position.z += t * (line->p2.position.z - line->p1.position.z);
    line->p1.position.y += t * (line->p2.position.y - line->p1.position.y);
    line->p1.position.x += t * (line->p2.position.x - line->p1.position.x);
    return (1);
}
