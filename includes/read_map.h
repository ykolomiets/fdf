/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 11:07:03 by ykolomie          #+#    #+#             */
/*   Updated: 2017/09/30 11:07:04 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_H
# define READ_MAP_H

# include "base_structures.h"

int		read_map(char *map_file, t_map *map);
t_line	*form_lines(t_vertex **verts, int *lines_count, int rows, int cols);
void	find_max_min_z(t_vertex **verts, int rows, int cols, t_map *map);

#endif
