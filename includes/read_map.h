#ifndef READ_MAP_H
#define READ_MAP_H

#include "base_structures.h"

int     read_map(char *map_file, t_map *map);
t_line  *form_lines(t_vertex **verts, int *lines_count, int rows, int cols);

#endif