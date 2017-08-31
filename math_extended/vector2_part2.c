#include "mathx.h"
#include <stdlib.h>
#include <math.h>

int     v2_mult_by_scalar(vector2 a, float c)
{
    a[0] *= c;
    a[1] *= c;

    return (0);
}

int     v2_div_by_scalar(vector2 a, float c)
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

float   v2_dot_product(vector2 a, vector2 b)
{
    float   res;

    res = a[0] * b[0] + a[1] * b[1];

    return (res);
}

float   v2_cross_product(vector2 a, vector2 b)
{
    float   res;

    res = a[0] * b[1] - a[1] * b[0];

    return (res);
}

float   v2_magnitude(vector2 a)
{
    return sqrt(a[0] * a[0] + a[1] * a[1]);
}