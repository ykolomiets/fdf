#ifndef FDF_RASTERIZATION_H
#define FDF_RASTERIZATION_H

#include "base_structures.h"

# define ROUND(a) ((int)(a + 0.5))
# define ABS(a) ((a) < 0 ? -(a) : (a))

void    draw_line_dda(t_line_segment *line, int *image, int width);
void    clip_and_draw_line(t_line_segment *line, t_box *box, int *image, int width);

#endif //FDF_RASTERIZATION_H
