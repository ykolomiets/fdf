#include "mathx.h"
#include <math.h>

void    m4_submat(matrix4 m, matrix3 sub, int i, int j)
{
    int di;
    int dj;
    int si;
    int sj;

    di = 0;
    while (di < 3)
    {
        si = di + ((dj >= i) ? 1 : 0);
        dj = 0;
        while (dj < 3)
        {
            sj = dj + ((dj >= j) ? 1 : 0);
            sub[di * 3 + dj] = m[si * 4 + sj];
            dj++;
        }
        di++;
    }
}

float   m4_det(matrix4 m)
{
    float   det;
    float   res;
    float   i;
    matrix3 sub_matrix;
    int     n;

    n = 0;
    i = 1;
    res = 0;
    m3_fill_null(sub_matrix);
    while (n < 4)
    {
        m4_submat(m, sub_matrix, 0, n);
        det = m3_det(sub_matrix);
        res += m[n] * det * i;
        n++;
        i *= -1;
    }

    return (res);
}

int     m4_inverse(matrix4 m, matrix4 res)
{
    float   det;
    matrix3 mtemp;
    int     i;
    int     j;
    int     sign;

    det = m4_det(m);
    if (fabsf(det) < 0.0005)
        return (0);

    sign = 1;
    m3_fill_null(mtemp);
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            m4_submat(m, mtemp, i, j);
            res[i + j * 4] = (m3_det(mtemp) * sign) / det;
            sign *= -1;
            j++;
        }
        i++;
    }

    return (1);
}

t_hvec  m4_mult_hv(matrix4 m, t_hvec *v)
{
    t_hvec res;

    res.x = m[0] *  v->x + m[1] *   v->y + m[2] *   v->z + m[3] *   v->w;
    res.y = m[4] *  v->x + m[5] *   v->y + m[6] *   v->z + m[7] *   v->w;
    res.z = m[8] *  v->x + m[9] *   v->y + m[10] *  v->z + m[11] *  v->w;
    res.w = m[12] * v->x + m[13] *  v->y + m[14] *  v->z + m[15] *  v->w;
    return (res);
}