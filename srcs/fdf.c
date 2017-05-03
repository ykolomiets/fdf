/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:19:34 by ykolomie          #+#    #+#             */
/*   Updated: 2017/04/20 19:18:30 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include "base_structures.h"
#include <stdlib.h>
#include <stdio.h>

void	map_change(t_vector4** map, int rows, int columns, t_matrix4 mat)
{
	int i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			v4_x_m4(&map[i][j], mat);
			j++;
		}
		i++;
	}
}

int		keyhook_func(int keycode, void *param)
{
	t_fdf		*p;
	t_matrix4	transform_m4;
    static double      x = 0, y = 0, z = 0;

	p = (t_fdf *)param;
	m4_identity(transform_m4);
	printf("keycode: %d\n", keycode);
	if (keycode == 53)
        exit(0);
	else if (keycode == 49)
	{
		m4_translate(transform_m4, -p->center.x, -p->center.y, -p->center.z);
		m4_scale(transform_m4, 2, 2, 2);
		m4_translate(transform_m4, p->center.x, p->center.y, p->center.z);

	} 
	else if (keycode == 50)
	{
		m4_translate(transform_m4, -p->center.x, -p->center.y, -p->center.z);
		m4_scale(transform_m4, 0.5, 0.5, 0.5);
		m4_translate(transform_m4, p->center.x, p->center.y, p->center.z);
	}
	else if (keycode == 65361)
	{
		m4_translate(transform_m4, -5, 0, 0);
		p->center.x -= 5;
    }
	else if (keycode == 65362) {
        m4_translate(transform_m4, -p->center.x, -p->center.y, -p->center.z);
        m4_rotate_yaxis(transform_m4, -y);
        m4_rotate_xaxis(transform_m4, -x);
        m4_rotate_zaxis(transform_m4, -z);
        m4_scale(transform_m4, 1, 1, 1);
        m4_rotate_zaxis(transform_m4, z);
        m4_rotate_xaxis(transform_m4, x);
        m4_rotate_yaxis(transform_m4, y);
        m4_translate(transform_m4, p->center.x, p->center.y, p->center.z);
    }
    else if (keycode == 65363)
	{
		m4_translate(transform_m4, 5, 0, 0);
		p->center.x += 5;
	}
	else if (keycode == 65364)
	{
        m4_translate(transform_m4, -p->center.x, -p->center.y, -p->center.z);
        m4_rotate_yaxis(transform_m4, -y);
        m4_rotate_xaxis(transform_m4, -x);
        m4_rotate_zaxis(transform_m4, -z);
        m4_scale(transform_m4, 1, 1, 1);
        m4_rotate_zaxis(transform_m4, z);
        m4_rotate_xaxis(transform_m4, x);
        m4_rotate_yaxis(transform_m4, y);
        m4_translate(transform_m4, p->center.x, p->center.y, p->center.z);
	}
	else if (keycode == 97)
	{
		m4_translate(transform_m4, -p->center.x, -p->center.y, -p->center.z);
		m4_rotate_yaxis(transform_m4, -0.05);
        y -= 0.05;
		m4_translate(transform_m4, p->center.x, p->center.y, p->center.z);
	}
	else if (keycode == 100)
	{	m4_translate(transform_m4, -p->center.x, -p->center.y, -p->center.z);
		m4_rotate_yaxis(transform_m4, 0.05);
        y += 0.05;
		m4_translate(transform_m4, p->center.x, p->center.y, p->center.z);
	}else if (keycode == 119)
	{	m4_translate(transform_m4, -p->center.x, -p->center.y, -p->center.z);
		m4_rotate_xaxis(transform_m4, 0.05);
        x += 0.05;
		m4_translate(transform_m4, p->center.x, p->center.y, p->center.z);
	}else if (keycode == 115)
	{	m4_translate(transform_m4, -p->center.x, -p->center.y, -p->center.z);
		m4_rotate_xaxis(transform_m4, -0.05);
        x -= 0.05;
		m4_translate(transform_m4, p->center.x, p->center.y, p->center.z);
	}else if (keycode == 101)
	{	m4_translate(transform_m4, -p->center.x, -p->center.y, -p->center.z);
		m4_rotate_zaxis(transform_m4, -0.05);
        z -= 0.05;
		m4_translate(transform_m4, p->center.x, p->center.y, p->center.z);
	}else if (keycode == 113)
	{	m4_translate(transform_m4, -p->center.x, -p->center.y, -p->center.z);
		m4_rotate_zaxis(transform_m4, 0.05);
        z += 0.05;
		m4_translate(transform_m4, p->center.x, p->center.y, p->center.z);
	}else
		return (1);
	map_change(p->map, p->map_rows, p->map_columns, transform_m4);
	draw_map(p->map, p->map_rows, p->map_columns, &p->wind);

	return (0);
}

int		fdf(char *map_file)
{
	t_fdf		param;
	
	param.map = read_map(map_file, &param.map_rows, &param.map_columns);
	param.center.y = WIN_HEIGHT / 2.0;
	param.center.x = WIN_WIDTH / 2.0;
	param.center.z = 0;
	param.center.w = 1;
	param.wind.mlx = mlx_init();
	param.wind.win = mlx_new_window(param.wind.mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	draw_map(param.map, param.map_rows, param.map_columns, &param.wind);
	mlx_key_hook(param.wind.win, keyhook_func, &param);
	mlx_loop(param.wind.mlx);
	return (0);
}
