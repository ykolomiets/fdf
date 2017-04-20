/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 18:13:49 by ykolomie          #+#    #+#             */
/*   Updated: 2017/04/20 17:57:43 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "base_structures.h"

# define WIN_HEIGHT	900
# define WIN_WIDTH	1600

void	draw_line(int *data_map, t_point2 from, t_point2 to, int color);
int		fdf(char *map_file);
#endif
