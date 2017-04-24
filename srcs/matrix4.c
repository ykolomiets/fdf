#include "base_structures.h"

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

int		m3_inverse(t_matrix3 dest, t_matrix3 src)
{
	double	det;

	det = m3_det(src);
	if (fabs(det) < 0.0005)
	{
		m3_identity(dest);
		return (0);
	}
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
	result = 0;
	i = 0;
	while (n < 4)
	{
		m4_submat(m, m3sub, 0, n);
		det = m3_det(m3sub);
		result += m[n] * det * i;
		n++;
		i *= -1;
	}
	return (res);
}
