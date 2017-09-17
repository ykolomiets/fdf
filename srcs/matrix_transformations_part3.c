#include "matrix_transformations.h"
#include <math.h>

void     m4_rotate_basis_to_basis(matrix4 orig, matrix4 final, matrix4 rot)
{
    matrix4 orig_inverse;

    m4_fill_null(orig_inverse);
    m4_inverse(orig, orig_inverse);
    m4_fill_null(rot);
    m4_mult(final, orig_inverse, rot);
}

void        m3_rotate_about_vector(t_vec3 v, float angle, matrix3 res)
{
    float   rcos;
    float   rsin;
    float   diff;

    m3_identity(res);
    rcos = cosf(angle);
    diff = 1 - rcos;
    rsin = sinf(angle);
    res[0] =         rcos + v.x * v.x * diff;
    res[3] =  v.z * rsin + v.y * v.x * diff;
    res[6] = -v.y * rsin + v.z * v.x * diff;
    res[1] = -v.z * rsin + v.x * v.y * diff;
    res[4] =         rcos + v.y * v.y * diff;
    res[7] =  v.x * rsin + v.z * v.y * diff;
    res[2] =  v.y * rsin + v.x * v.z * diff;
    res[5] = -v.x * rsin + v.y * v.z * diff;
    res[8] =         rcos + v.z * v.z * diff;
}