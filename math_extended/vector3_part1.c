#include "mathx.h"
#include <stdlib.h>

vector3 v3_create(float x, float y, float z)
{
    float *vec;

    vec = (float *)malloc(3 * sizeof(float));
    vec[0] = x;
    vec[1] = y;
    vec[2] = z;

    return (vec);
}

vector3 v3_add(vector3 a, vector3 b)
{
    float *vec;

    vec = (float *)malloc(3 * sizeof(float));
    vec[0] = a[0] + b[0];
    vec[1] = a[1] + b[1];
    vec[2] = a[2] + b[2];

    return (vec);
}

vector3 v3_sub(vector3 a, vector3 b)
{
    float  *vec;

    vec = (float *)malloc(3 * sizeof(float));
    vec[0] = a[0] - b[0];
    vec[1] = a[1] - b[1];
    vec[2] = a[2] - b[2];

    return (vec);
}

int     v3_add_with_res(vector3 a, vector3 b, vector3 res)
{
    res[0] = a[0] + b[0];
    res[1] = a[1] + b[1];
    res[2] = a[2] + b[2];

    return (0);
}

int     v3_sub_with_res(vector3 a, vector3 b, vector3 res)
{
    res[0] = a[0] - b[0];
    res[1] = a[1] - b[1];
    res[2] = a[2] - b[2];

    return (0);
}