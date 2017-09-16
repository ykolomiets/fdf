#include "mathx.h"
#include <math.h>

vector2         v2_normalize(vector2 a)
{
    float magnitude;

    magnitude = v2_magnitude(a);
    if (fabsf(magnitude) > 0.0005)
    {
        a[0] /= magnitude;
        a[1] /= magnitude;
    }
    return (a);
}