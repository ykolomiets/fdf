#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "mlx.h"

typedef struct	s_window
{
	void	*mlx;
	void	*win;
}				t_window;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

void	step_by_x(t_window *window, t_point from, t_point to, int color)
{
	int	a;
	int	b;
	int	p;
	int	inc;

	a = 2 * abs(to.y - from.y);
	b = a - 2 * abs(to.x - from.x);
	p = a - abs(to.x - from.x);
	inc = to.y - from.y > 0 ? 1 : -1;
	while (from.x <= to.x)
	{
		if (p < 0)
			p += a;
		else
		{
			from.y += inc;
			p += b;
		}
		mlx_pixel_put(window->mlx, window->win, from.x, from.y, color);
		from.x++;
	}
}

void	step_by_y(t_window *window, t_point from, t_point to, int color)
{
	int	a;
	int	b;
	int	p;
	int	inc;
	
	a = 2 * abs(to.x - from.x);
	b = a - 2 * abs(to.y - from.y);
	p = a - abs(to.y - from.y);
	inc = to.x - from.x > 0 ? 1 : -1;
	while (from.y <= to.y)
	{
		if (p < 0)
			p +=a;
		else
		{
			from.x += inc;
			p +=b;
		}
		mlx_pixel_put(window->mlx, window->win, from.x, from.y, color);
		from.y++;
	}
}

void	mlx_draw_line(t_window *window, t_point from, t_point to, int color)
{
	if (abs(to.y - from.y) < abs(to.x - from.x))
	{
		if (from.x > to.x)
			step_by_x(window, to, from, color);
		else
			step_by_x(window, from, to, color);
	}
	else
	{
		if (from.y > to.y)
			step_by_y(window, to, from, color);
		else
			step_by_y(window, from, to, color);
	}
}

void	mlc_circle(t_window *window, t_point center, int radius, int color)
{
	double	angle;
	t_point	from;
	t_point	to;
	int		i = 0;

	from.x = center.x;
	from.y = center.y + radius;
	for (int i = 0; i < 360; i++)
	{
		angle = i * M_PI / 180;
		to.x = center.x + radius * sin(angle);
		to.y = center.y + radius * cos(angle);
		mlx_draw_line(window, from, to, color);
		from = to;
	}
}

int		my_keyhook_func(int keycode, void *param)
{
	t_window	*wind;

	wind = (t_window *)param;
	if (keycode == 49)
	{
		int	i = 0;
		t_point	from = {0, 250};
		t_point	to = {0, 0};
		while (to.x <= 500)
		{
			mlx_draw_line(wind, from, to, to.x * 100);
			to.x += 5;
			i++;
		}
		while (to.y <= 500)
		{
			mlx_draw_line(wind, from, to, to.y * 100);
			to.y += 5;
			i++;
		}

		while (to.x >= 0)
		{
			mlx_draw_line(wind, from, to,  0xFA8072 + to.x * 100);
			to.x -= 5;
			i++;
		}
	}
	return (0);
}

int		main(void)
{
	t_window	wind;

	wind.mlx = mlx_init();
	wind.win = mlx_new_window(wind.mlx, 500, 500, "mlx 42");
	mlx_key_hook(wind.win, my_keyhook_func, &wind);
	mlx_loop(wind.mlx);
}
