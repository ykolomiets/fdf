/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations_part2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 11:37:57 by ykolomie          #+#    #+#             */
/*   Updated: 2017/09/30 12:17:20 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_transformations.h"
#include "math.h"

void	m4_shear_x(float dy, float dz, t_matrix4 res)
{
	m4_identity(res);
	res[1] = dy;
	res[2] = dz;
}

void	m4_shear_y(float dx, float dz, t_matrix4 res)
{
	m4_identity(res);
	res[4] = dx;
	res[6] = dz;
}

void	m4_shear_z(float dx, float dy, t_matrix4 res)
{
	m4_identity(res);
	res[8] = dx;
	res[9] = dy;
}

void	m4_rotate_about_vector(t_hvec v, float angle, t_matrix4 res)
{
	float	rcos;
	float	rsin;
	float	diff;

	m4_identity(res);
	rcos = cosf(angle);
	diff = 1 - rcos;
	rsin = sinf(angle);
	res[0] = rcos + v.x * v.x * diff;
	res[4] = v.z * rsin + v.y * v.x * diff;
	res[8] = -v.y * rsin + v.z * v.x * diff;
	res[1] = -v.z * rsin + v.x * v.y * diff;
	res[5] = rcos + v.y * v.y * diff;
	res[9] = v.x * rsin + v.z * v.y * diff;
	res[2] = v.y * rsin + v.x * v.z * diff;
	res[6] = -v.x * rsin + v.y * v.z * diff;
	res[10] = rcos + v.z * v.z * diff;
}

void	m4_rotate_from_euler(float ax, float ay, float az, t_matrix4 r)
{
	float	saved[8];

	saved[0] = cosf(ax);
	saved[1] = sinf(ax);
	saved[2] = cosf(ay);
	saved[3] = sinf(ay);
	saved[4] = cosf(az);
	saved[5] = sinf(az);
	saved[6] = saved[0] * saved[3];
	saved[7] = saved[1] * saved[3];
	m4_identity(r);
	r[0] = saved[2] * saved[4];
	r[1] = -saved[2] * saved[5];
	r[2] = saved[3];
	r[4] = saved[7] * saved[4] + saved[0] * saved[5];
	r[5] = -saved[7] * saved[5] + saved[0] * saved[4];
	r[6] = -saved[1] * saved[2];
	r[8] = -saved[6] * saved[4] + saved[1] * saved[5];
	r[9] = saved[6] * saved[5] + saved[1] * saved[4];
	r[10] = saved[0] * saved[2];
}
