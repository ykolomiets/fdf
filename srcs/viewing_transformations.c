#include "viewing_tranformations.h"

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
    vector3 u, v, w;
    matrix4 move_e;
    matrix4 m_uvw;
    matrix4 res;

    move_e = m4_create_identity();
    move_e[3] = -camera->eye[0];
    move_e[7] = -camera->eye[1];
    move_e[11] = -camera->eye[2];
    m_uvw = m4_create_identity();
    w = v3_create(-camera->gaze[0], -camera->gaze[1], -camera->gaze[2]);
    v3_normalize(w);
    u = v3_cross_product(w, camera->view_up);
    v3_normalize(u);
    v = v3_cross_product(w, u);
    m_uvw[0] = u[0];
    m_uvw[1] = u[1];
    m_uvw[2] = u[2];
    m_uvw[4] = v[0];
    m_uvw[5] = v[1];
    m_uvw[6] = v[2];
    m_uvw[8] = w[0];
    m_uvw[9] = w[1];
    m_uvw[10] = w[2];
    res = m4_create_null();
    m4_mult(m_uvw, move_e, res);

    return(res);
}