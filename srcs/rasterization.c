#include "rasterization.h"

void    draw_line_dda(t_line *line, t_fdf *all)
{
    int     deltas[2];
    int     steps;
    int     k;
    float   incs[2];
    float   xy[2];
    int     temp;

    deltas[0] = ROUND(line->p2.position.x) - ROUND(line->p1.position.x);
    deltas[1] = ROUND(line->p2.position.y) - ROUND(line->p1.position.y);
    xy[0] = ROUND(line->p1.position.x);
    xy[1] = ROUND(line->p1.position.y);
    if (ABS(deltas[0]) > ABS(deltas[1]))
        steps = ABS(deltas[0]);
    else
        steps = ABS(deltas[1]);
    incs[0] = deltas[0] / (float) steps;
    incs[1] = deltas[1] / (float) steps;
    temp = ROUND(xy[1]) * all->width + ROUND(xy[0]);
    if (temp >=0 && temp < 1600 * 900)
        all->image.pixels[temp] = 0xffffff;
    k = 0;
    while (k++ < steps)
    {
        xy[0] += incs[0];
        xy[1] += incs[1];
        temp = ROUND(xy[1]) * all->width + ROUND(xy[0]);
        if (temp >= 0 && temp < 1600 * 900)
            all->image.pixels[temp] = 0xffffff;
    }
}
