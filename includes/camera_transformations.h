#ifndef CAMERA_TRANFORMATIONS_H
#define CAMERA_TRANFORMATIONS_H

#include "mathx.h"
#include "base_structures.h"

void    camera_move(t_camera *camera, int forward);
void    camera_roll(t_camera *camera, float angle);
void    camera_pitch(t_camera *camera, float angle);
void    camera_yaw(t_camera *camera, float angle);

#endif //CAMERA_TRANFORMATIONS_H
