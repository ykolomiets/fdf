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

# define WIN_HEIGHT	720
# define WIN_WIDTH	1280

void	    map_change(t_vector4** map, int rows, int columns, t_matrix4 mat);
t_vector4	**read_map(char *map_file, int *rows, int* columns);
void		draw_line(int *data_map, t_vector2 from, t_vector2 to, int color);
void		draw_map(t_vector4 **map, int rows, int columns, t_window *wind);
int	        fdf(char *map_file);

#endif
