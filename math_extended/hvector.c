#include "mathx.h"
#include <stdlib.h>
#include <math.h>

hvector hv_create_point(float x, float y, float z)
{
    float *vec;

    vec = (float *)malloc(4 * sizeof(float));
    vec[0] = x;
    vec[1] = y;
    vec[2] = z;
    vec[3] = 1;

    return (vec);
}

hvector hv_create_direction(float x, float y, float z)
{
    float *vec;

    vec = (float *)malloc(4 * sizeof(float));
    vec[0] = x;
    vec[1] = y;
    vec[2] = z;
    vec[3] = 0;

    return (vec);
}

void    hv_normalize(hvector v)
{
    float   magnitude;

    magnitude = v3_magnitude(v);
    if (fabsf(magnitude) > 0.00005)
    {
        v[0] /= magnitude;
        v[1] /= magnitude;
        v[2] /= magnitude;
    }
}