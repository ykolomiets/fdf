#include "mathx.h"
#include <math.h>

float   v3_dot_product(t_vec3 *a, t_vec3 *b)
{
    float   res;

    res = a->x * b->x + a->y * b->y + a->z * b->z;

    return (res);
}

t_vec3  v3_cross_product(t_vec3 *a, t_vec3 *b)
{
    t_vec3 res;

    res.x = a->y * b->z - a->z * b->y;
    res.y = a->z * b->x - a->x * b->z;
    res.z = a->x * b->y - a->y * b->x;

    return (res);
}

float   v3_magnitude(t_vec3 *a)
{
    return sqrtf(a->x * a->x + a->y * a->y + a->z * a->z);
}

t_vec3  v3_normalize(t_vec3 v)
{
    float   magnitude;

    magnitude = v3_magnitude(&v);
    if (fabsf(magnitude) > 0.00005)
    {
        v.x /= magnitude;
        v.y /= magnitude;
        v.z /= magnitude;
    }
    return (v);
}