/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 11:07:56 by ykolomie          #+#    #+#             */
/*   Updated: 2017/09/30 11:08:46 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_TRANSFORMATIONS_H
# define MATRIX_TRANSFORMATIONS_H

# include "mathx.h"

void		m4_scale(float a, float b, float c, t_matrix4 res);
void		m4_translate(float a, float b, float c, t_matrix4 res);
void		m4_rotate_z(float angle, t_matrix4 res);
void		m4_rotate_x(float angle, t_matrix4 res);
void		m4_rotate_y(float angle, t_matrix4 res);
void		m4_shear_x(float dy, float dz, t_matrix4 res);
void		m4_shear_y(float dx, float dz, t_matrix4 res);
void		m4_shear_z(float dx, float dy, t_matrix4 res);
void		m4_rotate_about_vector(t_hvec v, float angle, t_matrix4 res);
void		m4_rotate_from_euler(float ax, float ay, float az, t_matrix4 r);
void		m4_rotate_about_vector(t_hvec v, float angle, t_matrix4 res);
void		m3_rotate_about_vector(t_vec3 v, float angle, t_matrix3 res);

#endif
