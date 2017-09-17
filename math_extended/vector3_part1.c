#include "mathx.h"
#include <math.h>

t_vec3 v3_create(float x, float y, float z)
{
    return (t_vec3){x, y, z};
}

t_vec3 v3_add(t_vec3 a, t_vec3 b)
{
    t_vec3 vec;

    vec.x = a.x + b.x;
    vec.y = a.y + b.y;
    vec.z = a.z + b.z;

    return (vec);
}

t_vec3 v3_sub(t_vec3 a, t_vec3 b)
{
    t_vec3 vec;

    vec.x = a.x - b.x;
    vec.y = a.y - b.y;
    vec.z = a.z - b.z;

    return (vec);
}

int     v3_mult_by_scalar(t_vec3 *a, float c)
{
    a->x *= c;
    a->y *= c;

    return (0);
}

int     v3_div_by_scalar(t_vec3 *a, float c)
{
    if (fabsf(c) < 0.00005)
        return (1);
    else
    {
        a->x /= c;
        a->y /= c;
        return (0);
    }
}