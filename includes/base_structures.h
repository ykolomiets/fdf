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
#include "mlx.h"

typedef struct      s_vertex
{
    hvector         position;
    int             color;
}                   t_vertex;

typedef struct      s_line_segment
{
    t_vertex        *p1;
    t_vertex        *p2;
}                   t_line_segment;

typedef struct      s_map
{
    t_vertex        **verts;
    t_line_segment  *lines;
    int             line_count;
    int             rows;
    int             cols;
    t_vertex        **transformed;
}                   t_map;

typedef struct      s_camera
{
    vector3         eye;
    vector3         gaze;
    vector3         view_up;
}                   t_camera;

typedef struct      s_box
{
    float           left;
    float           right;
    float           top;
    float           bottom;
    float           near;
    float           far;
}                   t_box;

typedef struct      s_world
{
    void            *mlx;
    void            *window;
    void            *image;
    int             *pixels;
    int             bits_per_pixel;
    int             size_line;
    int             endian;
    int             height;
    int             width;
    t_map           map;
    t_camera        camera;
    t_box           box;
    int             view_type;
}                   t_world;

void                print_vertex(t_vertex *v);
void                print_line_segment(t_line_segment *l);
void                print_matrix4(matrix4 m);

#endif
