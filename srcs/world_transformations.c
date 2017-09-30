/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_transformations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 12:10:23 by ykolomie          #+#    #+#             */
/*   Updated: 2017/09/30 15:45:25 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world_transformations.h"

void	change_z(t_line *lines, int line_count, float diff)
{
	while (line_count--)
	{
		lines[line_count].p1.position.z *= diff;
		lines[line_count].p2.position.z *= diff;
	}
}

void	scale_all(t_line *lines, int line_count, float coef)
{
	while (line_count--)
	{
		lines[line_count].p1.position.x *= coef;
		lines[line_count].p2.position.x *= coef;
		lines[line_count].p1.position.y *= coef;
		lines[line_count].p2.position.y *= coef;
		lines[line_count].p1.position.z *= coef;
		lines[line_count].p2.position.z *= coef;
	}
}
