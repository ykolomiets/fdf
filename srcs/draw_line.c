/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 18:12:49 by ykolomie          #+#    #+#             */
/*   Updated: 2017/04/20 18:35:43 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void	step_by_x(int	*data_map, t_vector2 from, t_vector2 to, int color)
{
	int		a;
	int		b;
	int		p;
	int		inc;

	a = 2 * abs((int)(to.y - from.y));
	b = a - 2 * abs((int)(to.x - from.x));
	p = a - abs((int)(to.x - from.x));
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
	
		if ((from.x >= 0 && from.x < WIN_WIDTH) && 
			(from.y >= 0 && from.y < WIN_HEIGHT))	
			data_map[(int)(from.x + (int)from.y * WIN_WIDTH)] = color;
		from.x += 1;
	}
}

void	step_by_y(int	*data_map, t_vector2 from, t_vector2 to, int color)
{
	int		a;
	int		b;
	int		p;
	int		inc;
	
	a = 2 * abs((int)(to.x - from.x));
	b = a - 2 * abs((int)(to.y - from.y));
	p = a - abs((int)(to.y - from.y));
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
		if ((from.x >= 0 && from.x < WIN_WIDTH) && 
			(from.y >= 0 && from.y < WIN_HEIGHT))
			data_map[(int)(from.x + (int)from.y * WIN_WIDTH)] = color;
		from.y += 1;
	}
}

void	draw_line(int	*data_map, t_vector2 from, t_vector2 to, int color)
{
	if (fabs(to.y - from.y) < fabs(to.x - from.x))
	{
		if (from.x > to.x)
			step_by_x(data_map, to, from, color);
		else
			step_by_x(data_map, from, to, color);
	}
	else
	{
		if (from.y > to.y)
			step_by_y(data_map, to, from, color);
		else
			step_by_y(data_map, from, to, color);
	}
}
