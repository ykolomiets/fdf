#include "mathx.h"
#include <math.h>

void        m3_fill_null(matrix3 m)
{
    m[0] = 0;
    m[1] = 0;
    m[2] = 0;
    m[3] = 0;
    m[4] = 0;
    m[5] = 0;
    m[6] = 0;
    m[7] = 0;
    m[8] = 0;
}

void        m3_identity(matrix3 m)
{
    m[0] = 1;
    m[1] = 0;
    m[2] = 0;
    m[3] = 0;
    m[4] = 1;
    m[5] = 0;
    m[6] = 0;
    m[7] = 0;
    m[8] = 1;
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
    if (fabsf(det) < 0.00005)
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


t_vec3      m3_mult_v3(matrix3 m, t_vec3 *v)
{
    t_vec3 res;

    res.x = m[0] * v->x + m[1] * v->y + m[2] * v->z;
    res.y = m[3] * v->x + m[4] * v->y + m[5] * v->z;
    res.z = m[6] * v->x + m[7] * v->y + m[8] * v->z;
    return (res);
}