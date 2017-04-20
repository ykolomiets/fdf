/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:19:34 by ykolomie          #+#    #+#             */
/*   Updated: 2017/04/20 18:36:32 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include "base_structures.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int		keyhook_func(int keycode, void *param)
{
	t_window	*wind;

	wind = (t_window *)param;
	printf("keycode: %d", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

void		free_arr_str(char ***table, int size)
{
	while (size--)
		free((*table)[size]);
	free(*table);
	*table = 0;
}

t_point3	**malloc_map(int fd, char ***splited, int *rows, int *columns)
{
	char		*file;
	char		**tempstr;
	t_point3	**res;
	int			i;
	
	file = read_file(fd);
	*splited = ft_strsplit(file, '\n');
	free(file);
	*rows = 0;
	*columns = 0;
	while ((*splited)[(*rows)])
		(*rows)++;
	tempstr = ft_strsplit((*splited)[0], ' ');
	while (tempstr[(*columns)])
		(*columns)++;
	free_arr_str(&tempstr, *columns);
	res = (t_point3 **)malloc(sizeof(t_point3 *) * (*rows));
	i = 0;
	while (i < *rows)
		res[i++] = (t_point3 *)malloc(sizeof(t_point3) * (*columns));
	ft_putstr("size: ");
	ft_putnbr(*rows);
	ft_putchar('x');
	ft_putnbr(*columns);
	return (res);
}

int			fill_map(t_point3 **map, char **splited, int rows, int columns)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	while (i < rows)
	{
		j = 0;
		temp = ft_strsplit(splited[i], ' ');
		while (j < columns)
		{
			map[i][j].x = j * WIN_WIDTH / columns + WIN_WIDTH / columns / 2;
			map[i][j].y = i * WIN_HEIGHT / rows + WIN_HEIGHT / rows / 2;
			map[i][j].z = ft_atoi(temp[j]);
			j++;
		};
		free_arr_str(&temp, columns);
		i++;
	}
	return (0);
}

t_point2	p3_to_p2(t_point3 p3)
{
	t_point2 res;

	res.x = p3.x;
	res.y = p3.y;
	return (res);
}

t_point3	**read_map(char *map_file, int *rows, int* columns)
{
	t_point3	**res;
	char		**splited;
	int			fd;

	fd = open(map_file, O_RDONLY);
	res = malloc_map(fd, &splited, rows, columns);
	fill_map(res, splited, *rows, *columns);
	free_arr_str(&splited, *rows);
	close(fd);
	return (res);
}

void		map_to_win(int	*data_map, t_window *wind)
{
	void	*image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*image_addr;

	image = mlx_new_image(wind->mlx, WIN_WIDTH, WIN_HEIGHT);
	image_addr = mlx_get_data_addr(image, &bits_per_pixel, &size_line, &endian);
	ft_putstr(image_addr);
	printf("bits_per_pixel: %d, size_line: %d, endian: %d\n", bits_per_pixel, size_line, endian);
	for (int i = 0; i < WIN_HEIGHT; i++)
		for (int j = 0; j < WIN_WIDTH; j++)
		{
			((int*)image_addr)[i * WIN_HEIGHT + j] = data_map[i * WIN_HEIGHT + j];
			printf("%d \t %d\n", i, j);
		}
	mlx_put_image_to_window(wind->mlx, wind->win, image, WIN_WIDTH, WIN_HEIGHT);
	printf("map to win end");
}

void		draw_map(t_point3 **map, int rows, int columns, t_window *wind)
{
	int 		i;
	int 		j;
	int			*data_map;

	data_map = (int *)ft_memalloc(WIN_WIDTH * WIN_HEIGHT);
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			if (i + 1 != columns)
				draw_line(data_map, p3_to_p2(map[i][j]), p3_to_p2(map[i + 1][j]), 0xffffff);
			if (j + 1 != rows)
				draw_line(data_map, p3_to_p2(map[i][j]), p3_to_p2(map[i][j + 1]), 0xffffff);
			j++;
		}
		i++;
	}
	map_to_win(data_map, wind);
}

int		fdf(char *map_file)
{
	t_window	wind;
	t_point3	**map;
	int			rows;
	int			columns;

	map = read_map(map_file, &rows, &columns);
	wind.mlx = mlx_init();
	wind.win = mlx_new_window(wind.mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	draw_map(map, rows, columns, &wind);
	mlx_key_hook(wind.win, keyhook_func, &wind);
	mlx_loop(wind.mlx);
	return (0);
}
