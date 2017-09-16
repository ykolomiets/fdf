#ifndef FDF_WORLD_TRANSFORMS_H
#define FDF_WORLD_TRANSFORMS_H

#include "base_structures.h"

void    change_z(t_vertex **verts, int cols, int rows, float z);
void    scale_all(t_vertex **verts, int rows, int cols, float coef);

#endif //FDF_WORLD_TRANSFORMS_H
