/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_structures.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 18:10:40 by ykolomie          #+#    #+#             */
/*   Updated: 2017/04/20 15:41:49 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_STRUCTURES_H
# define BASE_STRUCTURES_H

#include "mathx.h"

typedef struct      s_vertex
{
    hvector         position;
    int             color;
}                   t_vertex;

typedef struct      s_line_segment
{
    hvector         p1;
    hvector         p2;
}                   t_line_segment;

typedef struct      s_map
{
    t_vertex        **verts;
    int             rows;
    int             cols;
}                   t_map;

void                print_vertex(t_vertex *v);

#endif
