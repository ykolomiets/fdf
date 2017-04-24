/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:19:34 by ykolomie          #+#    #+#             */
/*   Updated: 2017/04/20 19:18:30 by ykolomie         ###   ########.fr       */
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
	printf("keycode: %d\n", keycode);
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

t_vector4	**malloc_map(int fd, char ***splited, int *rows, int *columns)
{
	char		*file;
	char		**tempstr;
	t_vector4	**res;
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
	res = (t_vector4 **)malloc(sizeof(t_vector4 *) * (*rows));
	i = 0;
	while (i < *rows)
		res[i++] = (t_vector4 *)malloc(sizeof(t_vector4) * (*columns));
	return (res);
}

int			fill_map(t_vector4 **map, char **splited, int rows, int columns)
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
			map[i][j].x = j;
			map[i][j].y = i;
			map[i][j].z = ft_atoi(temp[j]);
			j++;
		};
		free_arr_str(&temp, columns);
		i++;
	}
	return (0);
}

t_vector2	p3_to_p2(t_vector4 p3)
{
	t_vector2 res;

	res.x = p3.x;
	res.y = p3.y;
	return (res);
}

t_vector4	**read_map(char *map_file, int *rows, int* columns)
{
	t_vector4	**res;
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
	for (int i = 0; i < WIN_HEIGHT; i++)
		for (int j = 0; j < WIN_WIDTH; j++)
			((int*)image_addr)[i * WIN_WIDTH + j] = data_map[i * WIN_WIDTH + j];
	mlx_put_image_to_window(wind->mlx, wind->win, image, 0, 0);
}

void		draw_map(t_vector4 **map, int rows, int columns, t_window *wind)
{
	int 		i;
	int 		j;
	int			*data_map;

	data_map = (int *)ft_memalloc(WIN_WIDTH * WIN_HEIGHT * sizeof(int));
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
	t_vector4	**map;
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
