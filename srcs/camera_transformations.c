#include "camera_transformations.h"
#include <stdlib.h>

void    camera_move(t_camera *camera, int forward)
{
    vector3 new_eye;

    new_eye = NULL;
    if (forward)
    {
        new_eye = v3_add(camera->eye, camera->gaze);
        if (v3_magnitude(new_eye) < 1)
        {
            free(new_eye);
            new_eye = NULL;
        }
    }
    else
        if (v3_magnitude(camera->eye) < 1000)
            new_eye = v3_sub(camera->eye, camera->gaze);
    if (new_eye)
    {
        free(camera->eye);
        camera->eye = new_eye;
    }
}

void    camera_roll(t_camera *camera, float angle)
{
    matrix4 trans;
    hvector new_viewup;
    hvector old_viewup;

    trans = m4_rotate_about_vector(camera->gaze, angle);
    old_viewup = hv_create_direction(camera->view_up[0],camera->view_up[1],camera->view_up[2]);
    new_viewup = hv_create_direction(0, 0, 0);
    m4_mult_hv(trans, old_viewup, new_viewup);
    camera->view_up[0] = new_viewup[0];
    camera->view_up[1] = new_viewup[1];
    camera->view_up[2] = new_viewup[2];
    v3_normalize(camera->view_up);
    free(trans);
    free(new_viewup);
    free(old_viewup);
}

void    camera_yaw(t_camera *camera, float angle)
{
    matrix4 trans;
    hvector new_eye;
    hvector old_eye;

    v3_normalize(camera->view_up);
    trans = m4_rotate_about_vector(camera->view_up, angle);
    old_eye = hv_create_point(camera->eye[0], camera->eye[1], camera->eye[2]);
    new_eye = hv_create_point(0, 0, 0);
    m4_mult_hv(trans, old_eye, new_eye);
    free(camera->eye);
    camera->eye = v3_create(new_eye[0], new_eye[1], new_eye[2]);
    camera->gaze[0] = -new_eye[0];
    camera->gaze[1] = -new_eye[1];
    camera->gaze[2] = -new_eye[2];
    v3_normalize(camera->gaze);
    free(new_eye);
    free(old_eye);
    free(trans);
}

void    camera_pitch(t_camera *camera, float angle)
{
    matrix3 trans;
    vector3 old_gaze;
    vector3 old_viewup;
    vector3 old_eye;
    vector3 axis;

    axis = v3_cross_product(camera->gaze, camera->view_up);
    v3_normalize(axis);
    trans = m3_rotate_about_vector(axis, angle);
    old_viewup = v3_create(camera->view_up[0], camera->view_up[1], camera->view_up[2]);
    m3_mult_v3(trans, old_viewup, camera->view_up);
    old_gaze = v3_create(camera->gaze[0], camera->gaze[1], camera->gaze[2]);
    m3_mult_v3(trans, old_gaze, camera->gaze);
    old_eye = v3_create(camera->eye[0], camera->eye[1], camera->eye[2]);
    m3_mult_v3(trans, old_eye, camera->eye);
    free(trans);
    free(old_eye);
    free(old_gaze);
    free(old_viewup);
}

