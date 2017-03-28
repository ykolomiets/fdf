/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 18:12:49 by ykolomie          #+#    #+#             */
/*   Updated: 2017/03/28 18:13:44 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>

void	step_by_x(t_window *window, t_point from, t_point to, int color)
{
	int	a;
	int	b;
	int	p;
	int	inc;

	a = 2 * abs(to.y - from.y);
	b = a - 2 * abs(to.x - from.x);
	p = a - abs(to.x - from.x);
	inc = to.y - from.y > 0 ? 1 : -1;
	while (from.x <= to.x)
	{
		if (p < 0)
			p += a;
		else
		{
			from.y += inc;
			p += b;
		}
		mlx_pixel_put(window->mlx, window->win, from.x, from.y, color);
		from.x++;
	}
}

void	step_by_y(t_window *window, t_point from, t_point to, int color)
{
	int	a;
	int	b;
	int	p;
	int	inc;
	
	a = 2 * abs(to.x - from.x);
	b = a - 2 * abs(to.y - from.y);
	p = a - abs(to.y - from.y);
	inc = to.x - from.x > 0 ? 1 : -1;
	while (from.y <= to.y)
	{
		if (p < 0)
			p +=a;
		else
		{
			from.x += inc;
			p +=b;
		}
		mlx_pixel_put(window->mlx, window->win, from.x, from.y, color);
		from.y++;
	}
}

void	draw_line(t_window *window, t_point from, t_point to, int color)
{
	if (abs(to.y - from.y) < abs(to.x - from.x))
	{
		if (from.x > to.x)
			step_by_x(window, to, from, color);
		else
			step_by_x(window, from, to, color);
	}
	else
	{
		if (from.y > to.y)
			step_by_y(window, to, from, color);
		else
			step_by_y(window, from, to, color);
	}
}
