/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 12:14:52 by ykolomie          #+#    #+#             */
/*   Updated: 2017/09/30 15:45:16 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "clipping.h"
#include "rasterization.h"
#include "viewing_tranformations.h"

static void	clean_image(t_fdf *all)
{
	int total;
	int *pixels;

	total = all->width * all->height;
	pixels = all->image.ps;
	while (total--)
		pixels[total] = 0;
}

void		render(t_fdf *all)
{
	t_matrix4	mcam;
	t_matrix4	mr;
	t_line		transformed;
	int			i;

	create_camera_transform(&all->camera, mcam);
	create_vp_proj_tranform(all, mr);
	i = 0;
	clean_image(all);
	while (i < all->map.line_count)
	{
		transformed = all->map.lines[i++];
		transformed.p1.position = m4_mult_hv(mcam, &transformed.p1.position);
		transformed.p2.position = m4_mult_hv(mcam, &transformed.p2.position);
		if (clip_near(&transformed, all->box.near))
		{
			transformed.p1.position = m4_mult_hv(mr, &transformed.p1.position);
			transformed.p2.position = m4_mult_hv(mr, &transformed.p2.position);
			transformed.p1.position = hv_normalize(transformed.p1.position);
			transformed.p2.position = hv_normalize(transformed.p2.position);
			draw_line_dda(&transformed, all);
		}
	}
	mlx_put_image_to_window(all->mlx, all->window, all->image.image, 0, 0);
}
