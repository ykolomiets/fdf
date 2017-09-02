#include "mathx.h"
#include "math.h"

matrix4     m4_shear_x(float dy, float dz)
{
    matrix4 res;

    res = m3_create_identity();
    res[1] = dy;
    res[2] = dz;

    return (res);
}

matrix4     m4_shear_y(float dx, float dz)
{
    matrix4 res;

    res = m3_create_identity();
    res[4] = dy;
    res[6] = dz;

    return (res);
}

matrix4     m4_shear_z(float dx, float dy)
{
    matrix4 res;

    res = m3_create_identity();
    res[8] = dy;
    res[9] = dz;

    return (res);
}

matrix4         m4_rotate_about_vector(hvector v, float angle)
{
    matrix4 res;
    float   rcos;
    float   rsin;
    float   diff;

    res = m4_create_identity();
    rcos = cos(angle);
    diff = 1 - rcos;
    rsin = sin(angle);
    res[0][0] =         rcos + v[0] * v[0] * diff;
    res[1][0] =  v[2] * rsin + v[1] * v[0] * diff;
    res[2][0] = -v[1] * rsin + v[2] * v[0] * diff;
    res[0][1] = -v[2] * rsin + v[0] * v[1] * diff;
    res[1][1] =         rcos + v[1] * v[1] * diff;
    res[2][1] =  v[0] * rsin + v[2] * v[1] * diff;
    res[0][2] =  v[1] * rsin + v[0] * v[2] * diff;
    res[1][2] = -v[0] * rsin + v[1] * v[2] * diff;
    res[2][2] =         rcos + v[2] * v[2] * diff;

    return (res);
}

matrix4         m4_rotate_from_euler(float angle_x, float angle_y, float angle_z)
{
    matrix4 res;
    float   saved[8];

    saved[0] = cos(angle_x); //a
    saved[1] = sin(angle_x); //b
    saved[2] = cos(angle_y); //c
    saved[3] = sin(angle_y); //d
    saved[4] = cos(angle_z); //e
    saved[5] = sin(angle_z); //f
    saved[6] = saved[0] * saved[3]; //ad
    saved[7] = saved[1] * saved[3]; //bd

    res = m3_create_identity();
    mat[0]  =   saved[2] * saved[4];
    mat[1]  =  -saved[2] * saved[5];
    mat[2]  =   saved[3];
    mat[4]  =   saved[7] * saved[4] + saved[0] * saved[5];
    mat[5]  =  -saved[7] * saved[5] + saved[0] * saved[4];
    mat[6]  =  -saved[1] * saved[2];
    mat[8]  =  -saved[6] * saved[4] + saved[1] * saved[5];
    mat[9]  =   saved[6] * saved[5] + saved[1] * saved[4];
    mat[10] =   saved[0] * saved[2];

    return (res);
}