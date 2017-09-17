#ifndef MATRIX_TRANSFORMATIONS_H
#define MATRIX_TRANSFORMATIONS_H

#include "mathx.h"

void        m4_scale(float a, float b, float c, matrix4 res);
void        m4_translate(float a, float b, float c, matrix4 res);
void        m4_rotate_z(float angle, matrix4 res);
void        m4_rotate_x(float angle, matrix4 res);
void        m4_rotate_y(float angle, matrix4 res);
void        m4_shear_x(float dy, float dz, matrix4 res);
void        m4_shear_y(float dx, float dz, matrix4 res);
void        m4_shear_z(float dx, float dy, matrix4 res);
void        m4_rotate_about_vector(t_hvec v, float angle, matrix4 res);
void        m4_rotate_from_euler(float angle_x, float angle_y, float angle_z, matrix4 res);
void        m4_rotate_about_vector(t_hvec v, float angle, matrix4 res);
void        m3_rotate_about_vector(t_vec3 v, float angle, matrix3 res);

#endif
