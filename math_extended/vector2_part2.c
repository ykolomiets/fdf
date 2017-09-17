#include "mathx.h"
#include <math.h>

int         v2_mult_by_scalar(t_vec2 *a, float c)
{
    a->x *= c;
    a->y *= c;

    return (0);
}

int         v2_div_by_scalar(t_vec2 *a, float c)
{
    if (fabsf(c) < 0.00005)
        return (1);
    a->x *= c;
    a->y *= c;
    return (0);
}

float   v2_dot_product(t_vec2 *a, t_vec2 *b)
{
    float   res;

    res = a->x * b->x + a->y * b->y;

    return (res);
}

float   v2_magnitude(t_vec2 *a)
{
    return sqrtf(a->x * a->x + a->y * a->y);
}

t_vec2         v2_normalize(t_vec2 a)
{
    float   magnitude;

    magnitude = v2_magnitude(&a);
    if (fabsf(magnitude) > 0.00005)
    {
        a.x /= magnitude;
        a.y /= magnitude;
    }
    return (a);
}