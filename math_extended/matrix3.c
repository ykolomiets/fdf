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

    res = m3_create_null();
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
    if (fabsf(det) < 0.0005)
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

matrix3         m3_rotate_about_vector(vector3 v, float angle)
{
    matrix3 res;
    float   rcos;
    float   rsin;
    float   diff;

    res = m3_create_identity();
    rcos = cosf(angle);
    diff = 1 - rcos;
    rsin = sinf(angle);
    res[0] =         rcos + v[0] * v[0] * diff;
    res[3] =  v[2] * rsin + v[1] * v[0] * diff;
    res[6] = -v[1] * rsin + v[2] * v[0] * diff;
    res[1] = -v[2] * rsin + v[0] * v[1] * diff;
    res[4] =         rcos + v[1] * v[1] * diff;
    res[7] =  v[0] * rsin + v[2] * v[1] * diff;
    res[2] =  v[1] * rsin + v[0] * v[2] * diff;
    res[5] = -v[0] * rsin + v[1] * v[2] * diff;
    res[8] =         rcos + v[2] * v[2] * diff;

    return (res);
}

void            m3_mult_v3(matrix3 m, vector3 v, vector3 res)
{
    res[0] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2];
    res[1] = m[3] * v[0] + m[4] * v[1] + m[5] * v[2];
    res[2] = m[6] * v[0] + m[7] * v[1] + m[8] * v[2];
}