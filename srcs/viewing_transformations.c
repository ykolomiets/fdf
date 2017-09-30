/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewing_transformations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 12:10:50 by ykolomie          #+#    #+#             */
/*   Updated: 2017/09/30 12:12:47 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewing_tranformations.h"

void	create_vp_transfrom(int width, int height, t_matrix4 mvp)
{
	m4_identity(mvp);
	mvp[0] = width / 2.0f;
	mvp[5] = height / 2.0f;
	mvp[3] = (width - 1) / 2.0f;
	mvp[7] = (height - 1) / 2.0f;
}

void	create_orth_transform(t_box *box, t_matrix4 morth)
{
	m4_identity(morth);
	morth[0] = 2 / (box->right - box->left);
	morth[5] = 2 / (box->top - box->bottom);
	morth[10] = 2 / (box->near - box->far);
	morth[3] = (box->right + box->left) / (box->left - box->right);
	morth[7] = (box->top + box->bottom) / (box->bottom - box->top);
	morth[11] = (box->near + box->far) / (box->far - box->near);
}

void	create_camera_transform(t_camera *camera, t_matrix4 mcam)
{
	t_vec3		uvw[3];
	t_matrix4	move_e;
	t_matrix4	m_uvw;

	m4_identity(move_e);
	move_e[3] = -camera->eye.x;
	move_e[7] = -camera->eye.y;
	move_e[11] = -camera->eye.z;
	uvw[2] = v3_create(-camera->gaze.x, -camera->gaze.y, -camera->gaze.z);
	uvw[2] = v3_normalize(uvw[2]);
	uvw[0] = v3_cross_product(&uvw[2], &camera->view_up);
	uvw[0] = v3_normalize(uvw[0]);
	uvw[1] = v3_cross_product(&uvw[2], &uvw[0]);
	m4_identity(m_uvw);
	m_uvw[0] = uvw[0].x;
	m_uvw[1] = uvw[0].y;
	m_uvw[2] = uvw[0].z;
	m_uvw[4] = uvw[1].x;
	m_uvw[5] = uvw[1].y;
	m_uvw[6] = uvw[1].z;
	m_uvw[8] = uvw[2].x;
	m_uvw[9] = uvw[2].y;
	m_uvw[10] = uvw[2].z;
	m4_mult(m_uvw, move_e, mcam);
}

void	create_perspective_transform(t_box *box, t_matrix4 mper)
{
	m4_fill_null(mper);
	mper[0] = 2 * box->near / (box->right - box->left);
	mper[2] = (box->left + box->right) / (box->left - box->right);
	mper[5] = 2 * box->near / (box->top - box->bottom);
	mper[6] = (box->bottom + box->top) / (box->bottom - box->top);
	mper[10] = (box->far + box->near) / (box->near - box->far);
	mper[11] = 2 * box->far * box->near / (box->far - box->near);
	mper[14] = 1;
}

void	create_vp_proj_tranform(t_fdf *all, t_matrix4 res)
{
	t_matrix4 mvp;
	t_matrix4 m_orth_per;

	create_vp_transfrom(all->width, all->height, mvp);
	if (all->view_type == ORTHOGONAL)
		create_orth_transform(&all->box, m_orth_per);
	else
		create_perspective_transform(&all->box, m_orth_per);
	m4_mult(mvp, m_orth_per, res);
}
