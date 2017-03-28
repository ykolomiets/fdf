#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "mlx.h"
#include "fdf.h"

int		my_keyhook_func(int keycode, void *param)
{
	t_window	*wind;

	wind = (t_window *)param;
	printf("keycode = %d\n", keycode);
	if (keycode == 18)
	{
		int	i = 0;
		t_point	from = {0, 250};
		t_point	to = {0, 0};
		while (to.x <= 500)
		{
			draw_line(wind, from, to, to.x * 100);
			to.x += 5;
			i++;
		}
		while (to.y <= 500)
		{
			draw_line(wind, from, to, to.y * 100);
			to.y += 5;
			i++;
		}

		while (to.x >= 0)
		{
			draw_line(wind, from, to,  0xFA8072 + to.x * 100);
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
