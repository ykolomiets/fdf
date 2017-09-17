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

#define ORTHOGONAL 0
#define PERSPECTIVE 1

typedef struct      s_vertex
{
    t_hvec          position;
    int             color;
}                   t_vertex;

typedef struct      s_line
{
    t_vertex        p1;
    t_vertex        p2;
}                   t_line;

typedef struct      s_map
{
    t_line          *lines;
    int             line_count;
}                   t_map;

typedef struct      s_camera
{
    t_vec3          eye;
    t_vec3          gaze;
    t_vec3          view_up;
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

typedef struct      s_image
{
    void            *image;
    int             *pixels; // TRY ANOTHER DEVICE
    int             bpp;
    int             size_line;
    int             endian;
}                   t_image;

typedef struct      s_fdf
{
    void            *mlx;
    void            *window;
    int             height;
    int             width;
    t_image         image;
    t_map           map;
    t_camera        camera;
    t_box           box;
    int             view_type;
}                   t_fdf;

#endif
