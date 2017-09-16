#include "mathx.h"
#include <math.h>
#include <stdio.h>

vector3    v3_normalize(vector3 v)
{
    float   magnitude;

    magnitude = v3_magnitude(v);
    if (fabsf(magnitude) > 0.00005)
    {
        v[0] /= magnitude;
        v[1] /= magnitude;
        v[2] /= magnitude;
    }
    return (v);
}