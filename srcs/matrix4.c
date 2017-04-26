#include "base_structures.h"
#include <math.h>

void	m4_add(t_matrix4 a, t_matrix4 b, t_matrix4 c)
{
	int	i;

	i = -1;
	while (++i < 16)
		c[i] = a[i] + b[i];
}

void	m4_sub(t_matrix4 a, t_matrix4 b, t_matrix4 c)
{
	int	i;

	i = -1;
	while (++i < 16)
		c[i] = a[i] - b[i];
}

void	m4_mul(t_matrix4 a, t_matrix4 b, t_matrix4 c)
{
	c[0] = a[0] * b[0] + a[1] * b[4] + a[2] * b[8] + a[3] * b[12]; 
	c[1] = a[0] * b[1] + a[1] * b[5] + a[2] * b[9] + a[3] * b[13]; 
	c[2] = a[0] * b[2] + a[1] * b[6] + a[2] * b[10] + a[3] * b[14]; 
	c[3] = a[0] * b[3] + a[1] * b[7] + a[2] * b[11] + a[3] * b[15]; 
	c[4] = a[4] * b[0] + a[5] * b[4] + a[6] * b[8] + a[7] * b[12]; 
	c[5] = a[4] * b[1] + a[5] * b[5] + a[6] * b[9] + a[7] * b[13]; 
	c[6] = a[4] * b[2] + a[5] * b[6] + a[6] * b[10] + a[7] * b[14]; 
	c[7] = a[4] * b[3] + a[5] * b[7] + a[6] * b[11] + a[7] * b[15]; 
	c[8] = a[8] * b[0] + a[9] * b[4] + a[10] * b[8] + a[11] * b[12]; 
	c[9] = a[8] * b[1] + a[9] * b[5] + a[10] * b[9] + a[11] * b[13]; 
	c[10] = a[8] * b[2] + a[9] * b[6] + a[10] * b[10] + a[11] * b[14]; 
	c[11] = a[8] * b[3] + a[9] * b[7] + a[10] * b[11] + a[11] * b[15]; 
	c[12] = a[12] * b[0] + a[13] * b[4] + a[14] * b[8] + a[15] * b[12]; 
	c[13] = a[12] * b[1] + a[13] * b[5] + a[14] * b[9] + a[15] * b[13]; 
	c[14] = a[12] * b[2] + a[13] * b[6] + a[14] * b[10] + a[15] * b[14]; 
	c[15] = a[12] * b[3] + a[13] * b[7] + a[14] * b[11] + a[15] * b[15];
}

double m3_det(t_matrix3 mat)
{
	return (mat[0] * (mat[4] * mat[8] - mat[7] * mat[5])
			- mat[1] * (mat[3] * mat[8] - mat[6] * mat[5])
			+ mat[2] * (mat[3] * mat[7] - mat[6] * mat[4]));
}

void	m3_identity(t_matrix3 m)
{
	m[0] = 1;
	m[4] = 1;
	m[8] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[5] = 0;
	m[6] = 0;
	m[7] = 0;
}

int		m3_inverse(t_matrix3 dest, t_matrix3 src)
{
	double	det;

	det = m3_det(src);
	if (fabs(det) < 0.0005)
	{
		m3_identity(dest);
		return (0);
	}
	dest[0] =    src[4]*src[8] - src[5]*src[7]   / det;
    dest[1] = -( src[1]*src[8] - src[7]*src[2] ) / det;
    dest[2] =    src[1]*src[5] - src[4]*src[2]   / det;
    dest[3] = -( src[3]*src[8] - src[5]*src[6] ) / det;
    dest[4] =    src[0]*src[8] - src[6]*src[2]   / det;
    dest[5] = -( src[0]*src[5] - src[3]*src[2] ) / det;
    dest[6] =    src[3]*src[7] - src[6]*src[4]   / det;
    dest[7] = -( src[0]*src[7] - src[6]*src[1] ) / det;
    dest[8] =    src[0]*src[4] - src[1]*src[3]   / det;
    return(1);
}

void	m4_submat(t_matrix4 m, t_matrix3 msub, int i, int j)
{
	int	di;
	int	dj;
	int	si;
	int sj;

	di = 0;
	while (di < 3)
	{
		dj = 0;
		while (dj < 3)
		{
			si = di + ((di >= i) ? 1 : 0);
			sj = dj + ((dj >= j) ? 1: 0 );
			msub[di * 3 + dj] = m[si * 4 + sj];
			dj++;
		}
		di++;
	}
}

double	m4_det(t_matrix4 m)
{
	double		det;
	double		res;
	int			i;
	t_matrix3	m3sub;
	int			n;

	n = 0;
	res = 0;
	i = 0;
	while (n < 4)
	{
		m4_submat(m, m3sub, 0, n);
		det = m3_det(m3sub);
		res += m[n] * det * i;
		n++;
		i *= -1;
	}
	return (res);
}

void	m4_identity(t_matrix4 m)
{
	m[0] = m[5] = m[10] = m[15] = 1;
	m[1] = m[2] = m[3] = m[4] =
		m[6] = m[7] = m[8] = m[9] =
		m[11] = m[12] = m[13] = m[14] = 0;
}

void	m4_scale(t_matrix4 mat, double x, double y, double z)
{
	mat[0] *= x;
	mat[4] *= x;
	mat[8] *= x;
	mat[12] *= x;	
	mat[1] *= y;
	mat[5] *= y;
	mat[9] *= y;
	mat[13] *= y;
	mat[2] *= z;
	mat[6] *= z;
	mat[10] *= z;
	mat[14] *= z;
}

void	m4_translate(t_matrix4 mat, double x, double y, double z)
{
	mat[0] += mat[3] * x;
	mat[1] += mat[3] * y;
	mat[2] += mat[3] * z;
	mat[4] += mat[7] * x;
	mat[5] += mat[7] * y;
	mat[6] += mat[7] * z;
	mat[8] += mat[11] * x;
	mat[9] += mat[11] * y;
	mat[10] += mat[11] * z;
	mat[12] += mat[15] * x;
	mat[13] += mat[15] * y;
	mat[14] += mat[15] * z;
}

void	m4_rotate_xaxis(t_matrix4 mat, double angle)
{
	t_matrix4	 rotation_matrix;
	t_matrix4	temp;
	int			i;

	m4_identity(rotation_matrix);
	rotation_matrix[5] = cos(angle);
	rotation_matrix[6] = -sin(angle);
	rotation_matrix[9] = sin(angle);
	rotation_matrix[10] = cos(angle);
	i = 0;
	while (i < 16)
	{
		temp[i] = mat[i];
		i++;
	}
	m4_mul(temp, rotation_matrix, mat);
}

void	m4_rotate_yaxis(t_matrix4 mat, double angle)
{
	t_matrix4	 rotation_matrix;
	t_matrix4	temp;
	int			i;

	m4_identity(rotation_matrix);
	rotation_matrix[0] = cos(angle);
	rotation_matrix[8] = -sin(angle);
	rotation_matrix[2] = sin(angle);
	rotation_matrix[10] = cos(angle);
	i = 0;
	while (i < 16)
	{
		temp[i] = mat[i];
		i++;
	}
	m4_mul(temp, rotation_matrix, mat);
}

void	m4_rotate_zaxis(t_matrix4 mat, double angle)
{
	t_matrix4	 rotation_matrix;
	t_matrix4	temp;
	int			i;

	m4_identity(rotation_matrix);
	rotation_matrix[0] = cos(angle);
	rotation_matrix[1] = -sin(angle);
	rotation_matrix[4] = sin(angle);
	rotation_matrix[5] = cos(angle);
	i = 0;
	while (i < 16)
	{
		temp[i] = mat[i];
		i++;
	}
	m4_mul(temp, rotation_matrix, mat);
}
