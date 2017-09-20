#include "rasterization.h"
#include <stdio.h>

int     color_by_mode(t_vertex *p1, t_vertex *p2, float t, t_fdf *all)
{
    t_rgb   res;
    t_hsv   hsv;
    float   z;

    if (all->cmode == 0)
        return (0x0fffff);
    else if (all->cmode == 1)
    {
        res = rgb_add_a(p1->color, p2->color, t);
        return (rgb_to_int(&res));
    }
    else if (all->cmode == 2)
    {
        z = p1->real_z + t * (p2->real_z - p1->real_z);
        hsv.s = 1;
        hsv.v = 1;
        hsv.h = 120 - (z - all->map.min_z) / (all->map.max_z - all->map.min_z) * 120;
        res = hsv_to_rgb(hsv);
        return (rgb_to_int(&res));
    }
    return 0xffffff;
}

void    draw_line_dda(t_line *line, t_fdf *all)
{
    int     deltas[2];
    int     steps;
    int     k;
    float   incs[2];
    float   xy[2];

    deltas[0] = ROUND(line->p2.position.x) - ROUND(line->p1.position.x);
    deltas[1] = ROUND(line->p2.position.y) - ROUND(line->p1.position.y);
    xy[0] = ROUND(line->p1.position.x);
    xy[1] = ROUND(line->p1.position.y);
    steps = ABS(deltas[0]) > ABS(deltas[1]) ? ABS(deltas[0]) : ABS(deltas[1]);
    incs[0] = deltas[0] / (float) steps;
    incs[1] = deltas[1] / (float) steps;
    if ( (ROUND(xy[1]) >= 0 && ROUND(xy[1]) < all->height) &&
            (ROUND(xy[0]) >= 0 && ROUND(xy[0]) < all->width))
        all->image.pixels[ROUND(xy[1]) * all->width + ROUND(xy[0])] =
                color_by_mode(&line->p1, &line->p2, (k - 1) / (float)steps, all);
    k = 0;
    while (k++ < steps)
    {
        xy[0] += incs[0];
        xy[1] += incs[1];
        if ( (ROUND(xy[1]) >= 0 && ROUND(xy[1]) < all->height) &&
             (ROUND(xy[0]) >= 0 && ROUND(xy[0]) < all->width))
            all->image.pixels[ROUND(xy[1]) * all->width + ROUND(xy[0])] =
                    color_by_mode(&line->p1, &line->p2, (k - 1) / (float)steps, all);
    }
}
