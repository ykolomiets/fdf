#include "mathx.h"
#include <stdlib.h>

matrix4     m4_create_null()
{
    matrix4 res;

    res = (matrix4)malloc(16 * sizeof(float));
    for (int i = 0; i < 16; i++)
    {
        res[i] = 0;
    }

    return res;
}

matrix4     m4_create_identity()
{
    matrix4 res;

    res = m4_create_null();
    res[0] = 1;
    res[5] = 1;
    res[10] = 1;
    res[15] = 1;

    return res;
}

void        m4_add(matrix4 a, matrix4 b, matrix4 res)
{
    for (int i = 0; i < 16; i++)
    {
        res[i] = a[i] + b[i];
    }
}

void        m4_sub(matrix4 a, matrix4 b, matrix4 res)
{
    for (int i = 0; i < 16; i++)
    {
        res[i] = a[i] - b[i];
    }
}

void        m4_mult(matrix4 a, matrix4 b, matrix4 res)
{
    res[0] = a[0] * b[0] + a[1] * b[4] + a[2] * b[8] + a[3] * b[12];
    res[1] = a[0] * b[1] + a[1] * b[5] + a[2] * b[9] + a[3] * b[13];
    res[2] = a[0] * b[2] + a[1] * b[6] + a[2] * b[10] + a[3] * b[14];
    res[3] = a[0] * b[3] + a[1] * b[7] + a[2] * b[11] + a[3] * b[15];
    res[4] = a[4] * b[0] + a[5] * b[4] + a[6] * b[8] + a[7] * b[12];
    res[5] = a[4] * b[1] + a[5] * b[5] + a[6] * b[9] + a[7] * b[13];
    res[6] = a[4] * b[2] + a[5] * b[6] + a[6] * b[10] + a[7] * b[14];
    res[7] = a[4] * b[3] + a[5] * b[7] + a[6] * b[11] + a[7] * b[15];
    res[8] = a[8] * b[0] + a[9] * b[4] + a[10] * b[8] + a[11] * b[12];
    res[9] = a[8] * b[1] + a[9] * b[5] + a[10] * b[9] + a[11] * b[13];
    res[10] = a[8] * b[2] + a[9] * b[6] + a[10] * b[10] + a[11] * b[14];
    res[11] = a[8] * b[3] + a[9] * b[7] + a[10] * b[11] + a[11] * b[15];
    res[12] = a[12] * b[0] + a[13] * b[4] + a[14] * b[8] + a[15] * b[12];
    res[13] = a[12] * b[1] + a[13] * b[5] + a[14] * b[9] + a[15] * b[13];
    res[14] = a[12] * b[2] + a[13] * b[6] + a[14] * b[10] + a[15] * b[14];
    res[15] = a[12] * b[3] + a[13] * b[7] + a[14] * b[11] + a[15] * b[15];
}