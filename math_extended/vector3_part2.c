#include "mathx.h"
#include <stdlib.h>
#include <math.h>

int     v3_mult_by_scalar(vector3 a, float c)
{
    a[0] *= c;
    a[1] *= c;
    a[2] *= c;

    return (0);
}

int     v3_div_by_scalar(vector3 a, float c)
{
    if (fabs(c) < 0.0005)
        return (1);
    else
    {
        a[0] /= c;
        a[1] /= c;
        return (0);
    }
}

float   v3_dot_product(vector3 a, vector3 b)
{
    float   res;

    res = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];

    return (res);
}

vector3 v3_cross_product(vector3 a, vector3 b)
{
    vector3 res;

    res = (vector3)malloc(3 * sizeof(float));
    res[0] = a[1] * b[2] - a[2] * b[1];
    res[1] = a[2] * b[0] - a[0] * b[2];
    res[2] = a[0] * b[1] - a[1] * b[0];

    return (res);
}

float   v3_magnitude(vector3 a)
{
    return sqrt(a[0] * a[0] + a[1] * a[1] * a[2] * a[2]);
}