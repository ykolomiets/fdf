#include "mathx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

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

hvector hv_normalize(hvector v)
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

hvector hv_vector_from_points(hvector p1, hvector p2)
{
    return hv_create_direction(p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]);
}

void    hv_print(hvector v)
{
    printf("<%.3f, %.3f, %.3f, %.3f>\n", v[0], v[1], v[2], v[3]);
}