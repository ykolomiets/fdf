/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 11:06:06 by ykolomie          #+#    #+#             */
/*   Updated: 2017/09/30 11:06:09 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

typedef struct	s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_rgb;

typedef struct	s_hsv
{
	double			h;
	double			s;
	double			v;
}				t_hsv;

t_rgb			rgb_from_int(int c1);
int				rgb_to_int(t_rgb *c);
t_rgb			rgb_add(t_rgb c1, t_rgb c2);
t_rgb			rgb_add_a(t_rgb c1, t_rgb c2, float a);
t_hsv			rgb_to_hsv(t_rgb rgb);
t_rgb			hsv_to_rgb(t_hsv hsv);

#endif
