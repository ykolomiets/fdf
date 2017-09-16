#ifndef FDF_VIEWING_TRANFORMATIONS_H
#define FDF_VIEWING_TRANFORMATIONS_H

#include "mathx.h"
#include "base_structures.h"


matrix4     create_vp_transfrom(int width, int height);
matrix4     create_orth_transform(t_box *box);
matrix4     create_camera_transform(t_camera *camera);
matrix4     create_perspective_transform(t_box *box);

#endif //FDF_VIEWING_TRANFORMATIONS_H
