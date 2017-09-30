/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_transformations.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 11:03:01 by ykolomie          #+#    #+#             */
/*   Updated: 2017/09/30 11:07:31 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_TRANSFORMATIONS_H
# define CAMERA_TRANSFORMATIONS_H

# include "mathx.h"
# include "base_structures.h"

void	camera_move(t_camera *camera, int forward);
void	camera_roll(t_camera *camera, float angle);
void	camera_pitch(t_camera *camera, float angle);
void	camera_yaw(t_camera *camera, float angle);

#endif
