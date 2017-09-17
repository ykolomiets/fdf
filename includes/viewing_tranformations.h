#ifndef VIEWING_TRANFORMATIONS_H
#define VIEWING_TRANFORMATIONS_H

#include "mathx.h"
#include "base_structures.h"


void        create_vp_transfrom(int width, int height, matrix4 mvp);
void        create_orth_transform(t_box *box, matrix4 morth);
void        create_camera_transform(t_camera *camera, matrix4 mcam);
void        create_perspective_transform(t_box *box, matrix4 mper);
void        combine_all_transforms(t_fdf *all, matrix4 mres);

#endif
