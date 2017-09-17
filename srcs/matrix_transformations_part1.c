#include "matrix_transformations.h"
#include "math.h"

void     m4_scale(float a, float b, float c, matrix4 res)
{
    m4_identity(res);
    res[0] = a;
    res[5] = b;
    res[10] = c;
}

void     m4_translate(float a, float b, float c, matrix4 res)
{
    m4_identity(res);
    res[3] = a;
    res[7] = b;
    res[11] = c;
}

void     m4_rotate_z(float angle, matrix4 res)
{
    m4_identity(res);
    res[0] = cosf(angle);
    res[5] = res[0];
    res[1] = sinf(angle);
    res[4] = -res[1];
}

void     m4_rotate_x(float angle, matrix4 res)
{
    m4_identity(res);
    res[5] = cosf(angle);
    res[9] = sinf(angle);
    res[6] = -res[9];
}

void     m4_rotate_y(float angle, matrix4 res)
{
    m4_identity(res);
    res[0] = cosf(angle);
    res[2] = sinf(angle);
    res[8] = -res[2];
    res[10] = res[0];
}