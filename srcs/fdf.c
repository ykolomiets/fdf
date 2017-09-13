#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include <stdio.h>

void        render(t_world  *w)
{
    matrix4 mvp = create_vp_transfrom(w->width, w->height);
    matrix4 morth = create_orth_transform(&w->box);
    matrix4 mcam = create_camera_transform(&w->camera);
    matrix4 temp = m4_create_null();
    matrix4 res = m4_create_null();

    m4_mult(morth, mcam, temp);
    m4_mult(mvp, temp, res);
    for (int i = 0; i < w->map.rows; i++)
    {
        for (int j = 0; j < w->map.cols; j++)
        {
            m4_mult_hv(res, w->map.verts[i][j].position, )
        }
    }
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
        world.camera.eye = v3_create(5, 5, 5);
        world.camera.gaze = v3_create(-5, -5, -5);
        vector3 oy = v3_create(0, 1, 0);
        vector3 temp = v3_cross_product(world.camera.gaze, oy);
        world.camera.view_up = v3_cross_product(temp, world.camera.gaze);
        printf("gaze: <%.3f, %.3f, %.3f>\n", world.camera.gaze[0], world.camera.gaze[1], world.camera.gaze[2]);
        printf("view-up: <%.3f, %.3f, %.3f>\n", world.camera.view_up[0], world.camera.view_up[1], world.camera.view_up[2]);

        render(&world);
    }
}


