#include "mathx.h"
#include <stdlib.h>

matrix4     m4_rotate_basis_to_basis(matrix4 orig, matrix4 final)
{
    matrix4 rot;
    matrix4 orig_inverse;

    orig_inverse = m4_create_null();
    m4_inverse(orig, orig_inverse);
    rot = m4_create_null();
    m4_mult(final, orig_inverse, rot);
    free(orig_inverse);

    return (rot);
}

matrix4     m4_viewport(int nx, int ny)
{
    matrix4 vp;

    vp = m4_create_identity();
    vp[0] = nx / 2.0;
    vp[5] = ny / 2.0;
    vp[3] = (nx - 1) / 2.0;
    vp[7] = (ny - 1) / 2.0;

    return (vp);
}