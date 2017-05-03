//
// Created by columbiets on 03.05.17.
//

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

t_vector2	p3_to_p2(t_vector4 p3)
{
    t_vector2 res;

    res.x = p3.x;
    res.y = p3.y;
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
            if (i + 1 != rows)
                draw_line(data_map, p3_to_p2(map[i][j]), p3_to_p2(map[i + 1][j]), 0xffffff);
            if (j + 1 != columns)
                draw_line(data_map, p3_to_p2(map[i][j]), p3_to_p2(map[i][j + 1]), 0xffffff);
            j++;
        }
        i++;
    }
    map_to_win(data_map, wind);
}