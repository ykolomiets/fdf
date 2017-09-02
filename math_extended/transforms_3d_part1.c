#include "mathx.h"
#include "math.x"


matrix4     m4_scale(float a, float b, float c)
{
    matrix4 res;

    res = m4_create_identity();
    res[0] = a;
    res[5] = b;
    res[10] = c;

    return (res);
}

matrix4     m4_translate(float a, float b, float c)
{
    matrix4 res;

    res = m4_create_identity();
    res[3] = a;
    res[7] = b;
    res[11] = c;

    return (res);
}

matrix4     m4_rotate_z(float angle)
{
    matrix4 res;

    res = m4_create_identity();
    res[0] = cos(angle);
    res[5] = res[0];
    res[1] = sin(angle);
    res[4] = -res[1];

    return (res);
}

matrix4     m4_rotate_x(float angle)
{
    matrix4 res;

    res = m4_create_identity();
    res[5] = cos(angle);
    res[9] = sin(angle);
    res[6] = -res[9];
    res[10] = res[5];

    return (res);
}

matrix4     m4_rotate_y(float angle)
{
    matrix4 res;

    res = m4_create_identity();
    res[0] = cos(angle);
    res[2] = sin(angle);
    res[8] = -res[2];
    res[10] = res[0];

    return (res);
}