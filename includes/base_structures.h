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

typedef union	u_vector2
{
	double	coords[2];
	struct{
		double	x;
		double	y;
	};
}				t_vector2;

typedef union	u_vector4
{
	double	coords[4];
	struct{
		double	x;
		double	y;
		double	z;
		double	w;
	};
}				t_vector4;


typedef double	t_matrix3[9];
typedef	double	t_matrix4[16];

void		m4_add(t_matrix4 a, t_matrix4 b, t_matrix4 c);
void		m4_sub(t_matrix4 a, t_matrix4 b, t_matrix4 c);
void		m4_mul(t_matrix4 a, t_matrix4 b, t_matrix4 c);
double		m4_det(t_matrix4);

#endif
