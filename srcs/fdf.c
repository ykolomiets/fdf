/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 11:24:46 by ykolomie          #+#    #+#             */
/*   Updated: 2017/09/30 15:42:06 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "read_map.h"
#include "render.h"
#include "hooks.h"

static int	fdf_init(t_fdf *all, char *name)
{
	all->mlx = mlx_init();
	if (!all->mlx)
		return (1);
	all->height = 500;
	all->width = 700;
	all->window = mlx_new_window(all->mlx, all->width, all->height, name);
	if (!all->window)
		return (2);
	all->image.image = mlx_new_image(all->mlx, all->width, all->height);
	if (!all->image.image)
		return (3);
	all->image.ps = (int *)mlx_get_data_addr(all->image.image, &all->image.bpp,
										&all->image.sl, &all->image.endian);
	all->camera.eye = v3_create(0, 0, 10);
	all->camera.gaze = v3_create(0, 0, -1);
	all->camera.view_up = v3_create(0, 1, 0);
	all->box.bottom = -100;
	all->box.top = 100;
	all->box.left = -100 * (float)all->width / (float)all->height;
	all->box.right = 100 * (float)all->width / (float)all->height;
	all->box.near = -1;
	all->box.far = -1000;
	all->view_type = ORTHOGONAL;
	all->cmode = 0;
	return (0);
}

void		fdf(char *file_name)
{
	t_fdf	all;

	if (read_map(file_name, &all.map))
		ft_putendl("error: invalid map");
	else
	{
		if (!fdf_init(&all, file_name))
		{
			render(&all);
			mlx_mouse_hook(all.window, mouse_hook, &all);
			mlx_key_hook(all.window, keys_hook, &all);
			mlx_hook(all.window, 2, 0, pressed_hook, &all);
			mlx_expose_hook(all.window, expose_hook, &all);
			mlx_loop(all.mlx);
		}
		else
			ft_putendl("error: initialization failed");
	}
}
