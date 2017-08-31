/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 22:47:27 by ykolomie          #+#    #+#             */
/*   Updated: 2017/04/20 16:19:38 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHX_H
# define MATHX_H

typedef float   *vector2;
typedef float   *vector3;
typedef float   *hvector;

typedef float   *matrix3;
typedef float   *matrix4;

vector2         v2_create(float x, float y);
vector2         v2_add(vector2 a, vector2 b);
vector2         v2_sub(vector2 a, vector2 b);
int             v2_add_with_res(vector2 a, vector2 b, vector2 res);
int             v2_sub_with_res(vector2 a, vector2 b, vector2 res);
int             v2_mult_by_scalar(vector2 a, float c);
int             v2_div_by_scalar(vector2 a, float c);
float           v2_dot_product(vector2 a, vector2 b);
float           v2_cross_product(vector2 a, vector2 b);
float           v2_magnitude(vector2 a);

vector3         v3_create(float x, float y, float z);
vector3         v3_add(vector3 a, vector3 b);
vector3         v3_sub(vector3 a, vector3 b);
int             v3_add_with_res(vector3 a, vector3 b, vector3 res);
int             v3_sub_with_res(vector3 a, vector3 b, vector3 res);
int             v3_mult_by_scalar(vector3 a, float c);
int             v3_div_by_scalar(vector3 a, float c);
float           v3_dot_product(vector3 a, vector3 b);
vector3         v3_cross_product(vector3 a, vector3 b);
vector3         v3_magnitude(vector3 a);

hvector         hv_create_point(float x, float y, float z);
hvector         hv_create_direction(float x, float y, float z);

matrix3         m3_create_null();
matrix3         m3_create_identity();
float           m3_det(matrix3 m);
int             m3_inverse(matrix3 m, matrix3 res);

matrix4         m4_create_null();
matrix4         m4_create_identity();
void            m4_mult(matrix4 a, matrix4 b, matrix4 res);
void            m4_add(matrix4 a, matrix4 b, matrix4 res);
void            m4_sub(matrix4 a, matrix4 b, matrix4 res);
void            m4_submat(matrix4 m, matrix3 sub, int i, int j);
float           m4_det(matrix4 m);
int             m4_inverse(matrix4 m, matrix4 res);

#endif
