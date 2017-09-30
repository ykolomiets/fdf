/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_transformations.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 11:10:26 by ykolomie          #+#    #+#             */
/*   Updated: 2017/09/30 11:10:44 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_TRANSFORMATIONS_H
# define WORLD_TRANSFORMATIONS_H

# include "base_structures.h"

void	change_z(t_line *lines, int line_count, float z);
void	scale_all(t_line *lines, int line_count, float coef);

#endif
