/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 11:33:18 by ykolomie          #+#    #+#             */
/*   Updated: 2017/09/30 15:45:19 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include <math.h>

t_rgb	rgb_from_int(int c)
{
	t_rgb	res;

	res.b = (unsigned char)(c & 0xff);
	c >>= 8;
	res.g = (unsigned char)(c & 0xff);
	c >>= 8;
	res.r = (unsigned char)c;
	return (res);
}

int		rgb_to_int(t_rgb *c)
{
	int res;

	res = c->r;
	res <<= 8;
	res |= c->g;
	res <<= 8;
	res |= c->b;
	return (res);
}

t_rgb	rgb_add(t_rgb c1, t_rgb c2)
{
	return (rgb_add_a(c1, c2, 0.5f));
}

t_rgb	rgb_add_a(t_rgb c1, t_rgb c2, float a)
{
	c1.r = (unsigned char)(c1.r * (1 - a) + a * c2.r);
	c1.g = (unsigned char)(c1.g * (1 - a) + a * c2.g);
	c1.b = (unsigned char)(c1.b * (1 - a) + a * c2.b);
	return (c1);
}

t_hsv	rgb_to_hsv(t_rgb rgb)
{
	double	delta;
	double	min;
	t_hsv	res;

	min = fmin(fmin(rgb.r, rgb.g), rgb.b);
	res.v = fmax(fmax(rgb.r, rgb.g), rgb.b);
	delta = res.v - min;
	res.s = (res.v == 0.0) ? 0 : delta / res.v;
	if (res.s == 0)
		res.h = 0.0;
	else
	{
		if (rgb.r == res.h)
			res.h = (rgb.g - rgb.b) / delta;
		else if (rgb.g == res.v)
			res.h = 2 + (rgb.b - rgb.r) / delta;
		else if (rgb.b == res.v)
			res.h = 4 + (rgb.r - rgb.g) / delta;
		res.h *= 60;
		if (res.h < 0.0)
			res.h = res.h + 360;
	}
	res.v /= 255;
	return (res);
}
