/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewing_tranformations.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 11:10:01 by ykolomie          #+#    #+#             */
/*   Updated: 2017/09/30 11:10:03 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWING_TRANFORMATIONS_H
# define VIEWING_TRANFORMATIONS_H

# include "mathx.h"
# include "base_structures.h"

void		create_vp_transfrom(int width, int height, t_matrix4 mvp);
void		create_orth_transform(t_box *box, t_matrix4 morth);
void		create_camera_transform(t_camera *camera, t_matrix4 mcam);
void		create_perspective_transform(t_box *box, t_matrix4 mper);
void		combine_all_transforms(t_fdf *all, t_matrix4 mres);
void		create_vp_proj_tranform(t_fdf *all, t_matrix4 res);

#endif
