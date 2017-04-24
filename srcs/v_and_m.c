#include "base_structures.h"

void	v4_x_m4(t_vector4 *v, t_matrix4 m)
{
	t_vector4	temp;

	temp = *v;
	v->x = temp.x * m[0] + temp.y * m[4] + temp.z * m[8] + temp.w * m[12];
	v->y = temp.x * m[1] + temp.y * m[5] + temp.z * m[9] + temp.w * m[13];
	v->z = temp.x * m[2] + temp.y * m[6] + temp.z * m[10] + temp.w * m[14];
	v->w = temp.x * m[3] + temp.y * m[7] + temp.z * m[11] + temp.w * m[15];
}
