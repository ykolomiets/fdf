#include "mathx.h"

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
    if (fabs(det) < 0.0005)
        return (0);

    i = 0;
    sign = 1;
    mtemp = m3_create_null();
    while (i < 4)
    {
        while (j < 4)
        {
            m4_submat(m, mtemp, i, j);
            res[i + j * 4] = (m3_det(mtemp) * sign) / det;
            sign *= -1;
        }
    }
    return (1);
}