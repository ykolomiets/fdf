/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 11:22:24 by ykolomie          #+#    #+#             */
/*   Updated: 2017/09/30 12:47:32 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "world_transformations.h"
#include "camera_transformations.h"
#include "render.h"
#include <stdlib.h>

int		keys_hook(int keycode, t_fdf *all)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 18)
		all->view_type = 1 - all->view_type;
	else if (keycode == 19)
		all->cmode = (all->cmode + 1) % 3;
	render(all);
	return (0);
}

void	pressed_hook2(int keycode, t_fdf *all)
{
	float	temp;

	if (keycode == 38)
		change_z(all->map.lines, all->map.line_count, 1.2);
	else if (keycode == 40)
		change_z(all->map.lines, all->map.line_count, 1 / 1.2f);
	else if (keycode == 7)
		scale_all(all->map.lines, all->map.line_count, 1.2);
	else if (keycode == 8)
		scale_all(all->map.lines, all->map.line_count, 1 / 1.2f);
	else if (keycode == 32)
	{
		temp = all->box.near + 1;
		if (temp < -0.0005f)
			all->box.near = temp;
	}
	else if (keycode == 34)
	{
		temp = all->box.near - 1;
		if (temp > all->box.far)
			all->box.near = temp;
	}
}

int		pressed_hook(int keycode, t_fdf *all)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 13)
		camera_pitch(&(all->camera), -PI / 180);
	else if (keycode == 1)
		camera_pitch(&(all->camera), PI / 180);
	else if (keycode == 12)
		camera_roll(&(all->camera), PI / 180);
	else if (keycode == 14)
		camera_roll(&(all->camera), -PI / 180);
	else if (keycode == 0)
		camera_yaw(&(all->camera), PI / 180);
	else if (keycode == 2)
		camera_yaw(&(all->camera), -PI / 180);
	else
		pressed_hook2(keycode, all);
	render(all);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_fdf *all)
{
	(void)x;
	(void)y;
	if (button == 5)
		camera_move(&all->camera, 1);
	else if (button == 4)
		camera_move(&all->camera, 0);
	render(all);
	return (0);
}

int		expose_hook(t_fdf *all)
{
	render(all);
	return (0);
}
