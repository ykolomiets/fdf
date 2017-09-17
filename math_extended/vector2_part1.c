#include "mathx.h"
#include <stdlib.h>

t_vec2 v2_create(float x, float y)
{
    return (t_vec2){x, y};
}

t_vec2 v2_add(t_vec2 a, t_vec2 b)
{
    return (t_vec2){a.x + b.x, a.y + b.y};
}

t_vec2 v2_sub(t_vec2 a, t_vec2 b)
{
    return (t_vec2){a.x - b.x, a.y - b.y};
}
