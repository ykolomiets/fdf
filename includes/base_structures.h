/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_structures.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 18:10:40 by ykolomie          #+#    #+#             */
/*   Updated: 2017/04/20 15:41:49 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_STRUCTURES_H
# define BASE_STRUCTURES_H

# define X 0
# define Y 1
# define Z 2

typedef struct	s_window
{
	void	*mlx;
	void	*win;
}				t_window;

typedef struct	s_vector2
{
		double	x;
		double	y;
}				t_vector2;

typedef struct	s_vector4
{
		double	x;
		double	y;
		double	z;
		double	w;
}				t_vector4;

typedef struct	s_fdf
{
	t_window	wind;
	t_vector4	**map;
	t_vector4	center;
	int			map_rows;
	int			map_columns;
}				t_fdf;

void		v4_add(t_vector4 a, t_vector4 b, t_vector4 c);
void		v4_sub(t_vector4 a, t_vector4 b, t_vector4 c);
double		v4_dot_product(t_vector4 a, t_vector4 b);
void		v4_cross_product(t_vector4 a, t_vector4 b, t_vector4 c);

typedef double	t_matrix3[9];
typedef	double	t_matrix4[16];

void		m4_add(t_matrix4 a, t_matrix4 b, t_matrix4 c);
void		m4_sub(t_matrix4 a, t_matrix4 b, t_matrix4 c);
void		m4_mul(t_matrix4 a, t_matrix4 b, t_matrix4 c);
double		m4_det(t_matrix4);
void		m4_identity(t_matrix4 m);

void		m4_translate(t_matrix4 res, double x, double y, double z);
void		m4_scale(t_matrix4 res, double x, double y, double z);
void		m4_rotate_xaxis(t_matrix4 mat, double angle);
void		m4_rotate_yaxis(t_matrix4 mat, double angle);
void		m4_rotate_zaxis(t_matrix4 mat, double angle);

void		v4_x_m4(t_vector4 *v, t_matrix4 m);

#endif
