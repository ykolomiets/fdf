#include "mathx.h"
#include <stdlib.h>
#include <math.h>

matrix3     m3_create_null()
{
    matrix3 res;

    res = (matrix3)malloc(9 * sizeof(float));
    for (int i = 0; i < 9; i++)
    {
        res[i] = 0;
    }

    return res;
}

matrix3     m3_create_identity()
{
    matrix3 res;

    re3 = m3_create_null();
    res[0] = 1;
    res[4] = 1;
    res[8] = 1;

    return res;
}

float       m3_det(matrix3 m)
{
    float   det;

    det =   m[0] * (m[4] * m[8] - m[7] * m[5])
            - m[1] * (m[3] * m[8] - m[6] * m[5])
            + m[2] * (m[3] * m[7] - m[6] * m[4]);

    return (det);
}

int         m3_inverse(matrix3 m, matrix3 res)
{
    float   det;

    det = m3_det(m);
    if (fabs(det) < 0.0005)
        return (0);
    res[0] =    m[4] * m[8] - m[5] * m[7]   / det;
    res[1] = -( m[1] * m[8] - m[7] * m[2] ) / det;
    res[2] =    m[1] * m[5] - m[4] * m[2]   / det;
    res[3] = -( m[3] * m[8] - m[5] * m[6] ) / det;
    res[4] =    m[0] * m[8] - m[6] * m[2]   / det;
    res[5] = -( m[0] * m[5] - m[3] * m[2] ) / det;
    res[6] =    m[3] * m[7] - m[6] * m[4]   / det;
    res[7] = -( m[0] * m[7] - m[6] * m[1] ) / det;
    res[8] =    m[0] * m[4] - m[1] * m[3]   / det;
    return(1);
}