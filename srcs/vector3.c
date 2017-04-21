#include "vector3.h"
#include <stdlib.h>

typedef union	u_vector3
{
	float xyz[3];
	struct
	{
		float x;
		float y;
		float z;
	}
}		t_vector3;

t_vector3		*createVector3(float x, float y, float z)
{
	t_vector3	*res;

	res = (t_vector3*)malloc(sizeof(t_vector3));
	res->x = x;
	res->y = y;
	res->z = z;
	return (res);
}
