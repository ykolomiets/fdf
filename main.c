#include "minilibx/mlx.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef	struct	s_window
{
	void	*mlx;
	void	*win;
}				t_window;

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

void	step_by_x(t_window *window, t_point from, t_point to, int color)
{		
	int a = 2 * abs(to.y - from.y);
	int b = a - 2 * abs(to.x - from.x);
	int p = a - abs(to.x - from.x);
	
	int x = from.x;
	int y = from.y;
	
	int inc = to.y - from.y > 0 ? 1 : -1;

	printf("inc = %d\n", inc);

	while (x <= to.x)
	{
		if (p < 0)
		{
			mlx_pixel_put(window->mlx, window->win, x, y, color);
			p += a;
		}
		else {
			y += inc;
			mlx_pixel_put(window->mlx, window->win, x, y, color);
			p += b;
		}
		x++;
	}	
}

void	step_by_y(t_window *window, t_point from, t_point to, int color)
{		
	int a = 2 * abs(to.x - from.x);
	int b = a - 2 * abs(to.y - from.y);
	int p = a - abs(to.y - from.y);
	
	int x = from.x;
	int y = from.y;
	
	int inc = to.x - from.x > 0 ? 1 : -1;

	printf("inc = %d\n", inc);

	while (y <= to.y)
	{
		if (p < 0)
		{
			mlx_pixel_put(window->mlx, window->win, x, y, color);
			p += a;
		}
		else {
			x += inc;
			mlx_pixel_put(window->mlx, window->win, x, y, color);
			p += b;
		}
		y++;
	}	
}

int mlx_draw_line(t_window	*window, t_point from, t_point to, int color)
{
	if (abs(to.y - from.y) < abs(to.x - from.y))
		step_by_x(window, from, to, color);
	else
		step_by_y(window, from, to, color);
	return (0);
}


int main()
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 200, 200, "mlx 42");

	t_point from, to;
	from.x = 100;
	from.y = 100;
	to.x = 150;
	to.y = 0;
	t_window	*wind = malloc(sizeof(t_window));
	wind->mlx = mlx;
	wind->win = win;
	mlx_draw_line(wind, from, to, 0xFF00FF);

	mlx_loop(mlx);
	return (0);
}
