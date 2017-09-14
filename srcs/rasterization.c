#include "rasterization.h"
#include <math.h>

void    draw_line_dda(t_line_segment *line, int *image, int width)
{
    int     deltas[2];//[0] = int_temps[0], [1] = dy, [2] = steps, [3] = k
    int     steps;
    int     k;
    float   incs[2];
    float   xy[2];//[0] = xInc, [1] = yInc, [2] = x, [3] = y

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
    image[ROUND(xy[1]) * width + ROUND(xy[0])] = 0xffffff;
    k = 0;
    while (k++ < steps)
    {
        xy[0] += incs[0];
        xy[1] += incs[1];
        image[ROUND(xy[1]) * width + ROUND(xy[0])] = 0xffffff;
    }
}
