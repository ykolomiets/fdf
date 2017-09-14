#include "fdf.h"
#include "libft.h"
#include <stdio.h>
#include "viewing_tranformations.h"
#include "rasterization.h"
#include <math.h>

void        render(t_world  *w)
{
    matrix4 mvp = create_vp_transfrom(w->width, w->height);
    ft_putendl("\nMVP:\n");
    print_matrix4(mvp);
    matrix4 morth = create_orth_transform(&w->box);
    ft_putendl("\nORTH:\n");
    print_matrix4(morth);
    matrix4 mcam = create_camera_transform(&w->camera);
    ft_putendl("\nCAM:\n");
    print_matrix4(mcam);
    matrix4 temp = m4_create_null();
    matrix4 res = m4_create_null();

    m4_mult(morth, mcam, temp);
    ft_putendl("\n ORTH * CAM:\n");
    print_matrix4(temp);
    m4_mult(mvp, temp, res);
    ft_putendl("\nRES:\n");
    print_matrix4(res);
    for (int i = 0; i < w->map.rows; i++)
    {
        for (int j = 0; j < w->map.cols; j++)
        {
            m4_mult_hv(res, w->map.verts[i][j].position, w->map.transformed[i][j].position);
            print_vertex(&w->map.transformed[i][j]);
        }
    }

    for (int k = 0; k < w->map.line_count; k++)
    {
        draw_line_dda(&w->map.lines[k], w->pixels, w->width);
    }

    mlx_put_image_to_window(w->mlx, w->window, w->image, 0,0);
    mlx_loop(w->mlx);
}

void        test()
{
    void    *mlx = mlx_init();
    void    *window = mlx_new_window(mlx, 1600, 900, "FDF");
    void    *image = mlx_new_image(mlx, 1600, 900);
    int     endian, bit_per_pixel, size_line;
    int     *pixels_arr = (int *)mlx_get_data_addr(image, &bit_per_pixel, &size_line, &endian);

    t_vertex    v1, v2;
    v1.position = hv_create_point(0, 700, 1);
    v2.position = hv_create_point(1000, 0, 1);
    t_line_segment  line;
    line.p1 = &v1;
    line.p2 = &v2;

    draw_line_dda(&line, pixels_arr, 1600);
    mlx_put_image_to_window(mlx, window, image, 0, 0);
    mlx_loop(mlx);
}

void        fdf(char    *file_name)
{
    t_world world;


    if (read_map(file_name, &world.map))
        ft_putendl("error: invalid map");
    else
    {
        world.mlx = mlx_init();
        world.height = 900;
        world.width = 1600;
        world.window = mlx_new_window(world.mlx, world.width, world.height, "FDF");
        world.image = mlx_new_image(world.mlx, world.width, world.height);
        world.pixels = (int *)mlx_get_data_addr(world.image, &world.bits_per_pixel, &world.size_line, &world.endian);
        world.camera.eye = v3_create(0, 0, 0);
        world.camera.gaze = v3_create(0, cos(0.52333333333), -1);
        vector3 oy = v3_create(0, 1, 0);
        vector3 temp = v3_cross_product(world.camera.gaze, oy);
        world.camera.view_up = v3_cross_product(temp, world.camera.gaze);
        //world.camera.view_up = v3_create(0, 1, 0);
        world.box.bottom = -10;
        world.box.top = 10;
        world.box.left = -10 * (float)world.width / (float)world.height;
        world.box.right = 10 * (float)world.width / (float)world.height;
        world.box.near = -1;
        world.box.far = -100;
        printf("gaze: <%.3f, %.3f, %.3f>\n", world.camera.gaze[0], world.camera.gaze[1], world.camera.gaze[2]);
        printf("view-up: <%.3f, %.3f, %.3f>\n", world.camera.view_up[0], world.camera.view_up[1], world.camera.view_up[2]);
        render(&world);
    }
}


