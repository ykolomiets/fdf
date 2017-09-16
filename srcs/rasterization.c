#include "rasterization.h"

void    draw_line_dda(t_line_segment *line, int *image, int width)
{
    int     deltas[2];
    int     steps;
    int     k;
    float   incs[2];
    float   xy[2];
    int     temp;

    deltas[0] = ROUND(line->p2->position[0]) - ROUND(line->p1->position[0]);
    deltas[1] = ROUND(line->p2->position[1]) - ROUND(line->p1->position[1]);
    xy[0] = ROUND(line->p1->position[0]);
    xy[1] = ROUND(line->p1->position[1]);

    if (ABS(deltas[0]) > ABS(deltas[1]))
        steps = ABS(deltas[0]);
    else
        steps = ABS(deltas[1]);
    incs[0] = deltas[0] / (float) steps;
    incs[1] = deltas[1] / (float) steps;
    temp = ROUND(xy[1]) * width + ROUND(xy[0]);
    if (temp >=0 && temp < 1600 * 900)
        image[temp] = 0xffffff;
    k = 0;
    while (k++ < steps)
    {
        xy[0] += incs[0];
        xy[1] += incs[1];
        temp = ROUND(xy[1]) * width + ROUND(xy[0]);
        if (temp >= 0 && temp < 1600 * 900)
            image[temp] = 0xffffff;
    }
}
