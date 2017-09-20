#include "world_transformations.h"
#include <stdio.h>

void    change_z(t_line *lines, int line_count, float diff)
{
    while (line_count--)
    {
        lines[line_count].p1.position.z *= diff;
        lines[line_count].p2.position.z *= diff;
    }
}

void    print_line(t_line *line)
{
   printf("LINE:\n"
                  "\tp1: <%f, %f, %f, %f>\n"
                  "\tp2: <%f, %f, %f, %f>\n",
          line->p1.position.x,  line->p1.position.y,  line->p1.position.z, line->p1.position.w,
          line->p2.position.x,  line->p2.position.y,  line->p2.position.z, line->p2.position.w);
}

void    scale_all(t_line *lines, int line_count, float coef)
{
    while (line_count--)
    {
        lines[line_count].p1.position.x *= coef;
        lines[line_count].p2.position.x *= coef;
        lines[line_count].p1.position.y *= coef;
        lines[line_count].p2.position.y *= coef;
        lines[line_count].p1.position.z *= coef;
        lines[line_count].p2.position.z *= coef;
    }
}