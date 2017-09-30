/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 09:56:13 by ykolomie          #+#    #+#             */
/*   Updated: 2017/09/30 09:56:16 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHX_H
# define MATHX_H

# define PI 3.141592653589793f
# define ROUND(a) ((int)(a + 0.5))
# define ABS(a) ((a) < 0 ? -(a) : (a))

typedef struct	s_vec2
{
	float	x;
	float	y;
}				t_vec2;

typedef struct	s_vec3
{
	float x;
	float y;
	float z;
}				t_vec3;

typedef struct	s_hvec
{
	float x;
	float y;
	float z;
	float w;
}				t_hvec;

typedef float	t_matrix3[9];
typedef float	t_matrix4[16];

t_vec2			v2_create(float x, float y);
t_vec2			v2_add(t_vec2 a, t_vec2 b);
t_vec2			v2_sub(t_vec2 a, t_vec2 b);
int				v2_mult_by_scalar(t_vec2 *a, float c);
int				v2_div_by_scalar(t_vec2 *a, float c);
float			v2_dot_product(t_vec2 *a, t_vec2 *b);
float			v2_magnitude(t_vec2 *a);
t_vec2			v2_normalize(t_vec2 a);

t_vec3			v3_create(float x, float y, float z);
t_vec3			v3_add(t_vec3 a, t_vec3 b);
t_vec3			v3_sub(t_vec3 a, t_vec3 b);
int				v3_mult_by_scalar(t_vec3 *a, float c);
int				v3_div_by_scalar(t_vec3 *a, float c);
float			v3_dot_product(t_vec3 *a, t_vec3 *b);
t_vec3			v3_cross_product(t_vec3 *a, t_vec3 *b);
float			v3_magnitude(t_vec3 *a);
t_vec3			v3_normalize(t_vec3 v);

t_hvec			hv_create_point(float x, float y, float z);
t_hvec			hv_create_direction(float x, float y, float z);
t_hvec			hv_normalize(t_hvec v);

void			m3_fill_null(t_matrix3 m);
void			m3_identity(t_matrix3 m);
float			m3_det(t_matrix3 m);
int				m3_inverse(t_matrix3 m, t_matrix3 res);

t_vec3			m3_mult_v3(t_matrix3 m, t_vec3 *v);

void			m4_fill_null(t_matrix4 m);
void			m4_identity(t_matrix4 m);
void			m4_mult(t_matrix4 a, t_matrix4 b, t_matrix4 res);
void			m4_add(t_matrix4 a, t_matrix4 b, t_matrix4 res);
void			m4_sub(t_matrix4 a, t_matrix4 b, t_matrix4 res);
void			m4_submat(t_matrix4 m, t_matrix3 sub, int i, int j);
float			m4_det(t_matrix4 m);
int				m4_inverse(t_matrix4 m, t_matrix4 res);

t_hvec			m4_mult_hv(t_matrix4 m, t_hvec *v);

#endif
