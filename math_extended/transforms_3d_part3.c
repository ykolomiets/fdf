#include "mathx.h"

matrix4     m4_rotate_basis_to_basis(matrix4 orig, matrix4 final)
{
    matrix4 rot;
    matrix4 orig_inverse;

    orig_inverse = m4_create_null();
    m4_inverse(orig, orig_inverse);
    rot = m4_create_null();
    m4_mult(final * orig_inverse);
    free(orig_inverse);

    return (rot);
}