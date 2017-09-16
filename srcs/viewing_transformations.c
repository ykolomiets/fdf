#include "viewing_tranformations.h"
#include <stdlib.h>
#include <stdio.h>

matrix4     create_vp_transfrom(int width, int height)
{
    matrix4 mvp;

    mvp = m4_create_identity();
    mvp[0] = width / 2.0f;
    mvp[5] = height / 2.0f;
    mvp[3] = (width - 1) / 2.0f;
    mvp[7] = (height - 1) / 2.0f;

    return (mvp);
}

matrix4     create_orth_transform(t_box *box)
{
    matrix4 morth;

    morth = m4_create_identity();
    morth[0] = 2 / (box->right - box->left);
    morth[5] = 2 / (box->top - box->bottom);
    morth[10] = 2 / (box->near - box->far);
    morth[3] = (box->right + box->left) / (box->left - box->right);
    morth[7] = (box->top + box->bottom) / (box->bottom - box->top);
    morth[11] = (box->near + box->far) / (box->far - box->near);

    return (morth);
}

matrix4     create_camera_transform(t_camera *camera)
{
    vector3 uvw[3];
    matrix4 move_e;
    matrix4 m_uvw;
    matrix4 res;

    move_e = m4_create_identity();
    move_e[3] = -camera->eye[0];
    move_e[7] = -camera->eye[1];
    move_e[11] = -camera->eye[2];
    uvw[2] = v3_create(-camera->gaze[0], -camera->gaze[1], -camera->gaze[2]);
    v3_normalize(uvw[2]);
    uvw[0] = v3_cross_product(uvw[2], camera->view_up);
    v3_normalize(uvw[0]);
    uvw[1] = v3_cross_product(uvw[2], uvw[0]);
    m_uvw = m4_create_identity();
    m_uvw[0] = uvw[0][0];
    m_uvw[1] = uvw[0][1];
    m_uvw[2] = uvw[0][2];
    m_uvw[4] = uvw[1][0];
    m_uvw[5] = uvw[1][1];
    m_uvw[6] = uvw[1][2];
    m_uvw[8] = uvw[2][0];
    m_uvw[9] = uvw[2][1];
    m_uvw[10] = uvw[2][2];
    res = m4_create_null();
    m4_mult(m_uvw, move_e, res);
    free(m_uvw);
    free(move_e);
    return(res);
}

matrix4     create_perspective_transform(t_box *box)
{
    matrix4 mper;

    mper = m4_create_null();
    mper[0] = 2 * box->near / (box->right - box->left);
    mper[2] = (box->left + box->right) / (box->left - box->right);
    mper[5] = 2 * box->near / (box->top - box->bottom);
    mper[6] = (box->bottom + box->top) / (box->bottom - box->top);
    mper[10] = (box->far + box->near) / (box->near - box->far);
    mper[11] = 2 * box->far * box->near / (box->far - box->near);
    mper[14] = 1;
    return (mper);
}