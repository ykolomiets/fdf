#include "mathx.h"
#include <stdlib.h>

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