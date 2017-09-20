#include "rasterization.h"

t_rgb   color_mode2(t_vertex *p1, t_vertex *p2, float t, t_map *map)
{
    t_rgb   res;
    float   z;
    t_hsv   hsv;

    z = p1->real_z + t * (p2->real_z - p1->real_z);
    hsv.s = 1;
    hsv.v = 1;
    hsv.h = 120 - ((z - map->min_z) / (map->max_z - map->min_z)) * 120;
    res = hsv_to_rgb(hsv);
    return (res);
}

t_rgb   color_mode3(t_vertex *p1, t_vertex *p2, float t, t_map *map)
{
    t_rgb   res;
    float   z;
    t_hsv   hsv;

    z = p1->real_z + t * (p2->real_z - p1->real_z);
    hsv.s = 1;
    hsv.v = 1;
    if (z > 0)
        hsv.h = 120 - ((map->max_z - z) / map->max_z) * 120;
    else
        hsv.h = 120 + ((map->min_z - z) / map->min_z) * 120;
    res = hsv_to_rgb(hsv);
    return (res);
}


int     color_by_mode(t_vertex *p1, t_vertex *p2, float t, t_fdf *all)
{
    t_rgb   res;

    if (all->cmode == 0)
        return (0x0fffff);
    else if (all->cmode == 1)
    {
        res = rgb_add_a(p1->color, p2->color, t);
        return (rgb_to_int(&res));
    }
    else if (all->cmode == 2)
    {
        res = color_mode2(p1, p2, t, &all->map);
        return (rgb_to_int(&res));
    }
    else if (all->cmode == 3)
    {
        res = color_mode3(p1, p2, t, &all->map);
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
