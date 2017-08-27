#include "mathx.h"
#include <stdlib.h>

vector2 v2_create(float x, float y)
{
    float *vec;

    vec = (float *)malloc(2 * sizeof(float));
    vec[0] = x;
    vec[1] = y;

    return (vec);
}

vector2 v2_add(vector2 a, vector2 b)
{
    float *vec;

    vec = (float *)malloc(2 * sizeof(float));
    vec[0] = a[0] + b[0];
    vec[1] = a[1] + b[1];

    return (vec);
}

vector2 v2_sub(vector2 a, vector2 b)
{
    float  *vec;

    vec = (float *)malloc(2 * sizeof(float));
    vec[0] = a[0] - b[0];
    vec[1] = a[1] - b[1];

    return (vec);
}

int     v2_add_with_res(vector2 a, vector2 b, vector2 res)
{
    res[0] = a[0] + b[0];
    res[1] = a[1] + b[1];

    return (0);
}

int     v2_sub_with_res(vector2 a, vector2 b, vector2 res)
{
    res[0] = a[0] - b[0];
    res[1] = a[1] - b[1];

    return (0);
}