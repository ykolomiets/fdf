#include "base_structures.h"
#include <math.h>

void		v4_add(t_vector4 a, t_vector4 b, t_vector4 c)
{
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	c.w = a.w + b.w;
}

void		v4_sub(t_vector4 a, t_vector4 b, t_vector4 c)
{
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	c.w = a.w - b.w;
}
