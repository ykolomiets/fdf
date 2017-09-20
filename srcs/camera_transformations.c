#include "camera_transformations.h"
#include "matrix_transformations.h"
#include "libft.h"
#include <stdio.h>

void    camera_move(t_camera *camera, int forward)
{
    t_vec3  new_eye;

    if (forward)
    {
        new_eye = v3_add(camera->eye, camera->gaze);
        if (v3_magnitude(&new_eye) > 1)
            camera->eye = new_eye;
    }
    else
    {
        if (v3_magnitude(&camera->eye) < 1000)
            camera->eye = v3_sub(camera->eye, camera->gaze);
    }
}

void    camera_roll(t_camera *camera, float angle)
{
    matrix3 trans;

    m3_rotate_about_vector(camera->gaze, angle, trans);
    camera->view_up = m3_mult_v3(trans, &camera->view_up);
    v3_normalize(camera->view_up);
}

void    camera_yaw(t_camera *camera, float angle)
{
    matrix3 trans;

    camera->view_up = v3_normalize(camera->view_up);
    m3_rotate_about_vector(camera->view_up, angle, trans);
    camera->eye = m3_mult_v3(trans, &camera->eye);
    camera->gaze.x = -camera->eye.x;
    camera->gaze.y = -camera->eye.y;
    camera->gaze.z = -camera->eye.z;
    camera->gaze = v3_normalize(camera->gaze);
}

void    camera_pitch(t_camera *camera, float angle)
{
    matrix3 trans;
    t_vec3  axis;

    axis = v3_cross_product(&camera->gaze, &camera->view_up);
    axis = v3_normalize(axis);
    m3_rotate_about_vector(axis, angle, trans);
    camera->view_up = m3_mult_v3(trans, &camera->view_up);
    camera->gaze = m3_mult_v3(trans, &camera->gaze);
    camera->eye =  m3_mult_v3(trans, &camera->eye);
}

