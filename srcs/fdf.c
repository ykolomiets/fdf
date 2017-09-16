#include "fdf.h"
#include "libft.h"
#include "viewing_tranformations.h"
#include "rasterization.h"
#include "camera_transformations.h"
#include "world_transformations.h"
#include <stdlib.h>

#define PI 3.141592653589793f

void        render(t_world  *w)
{
    matrix4 mvp = create_vp_transfrom(w->width, w->height);
    matrix4 m_orth_per;
    if (w->view_type == ORTHOGONAL)
        m_orth_per = create_orth_transform(&w->box);
    else
        m_orth_per = create_perspective_transform(&w->box);
    matrix4 mcam = create_camera_transform(&w->camera);
    matrix4 temp = m4_create_null();
    matrix4 res = m4_create_null();
    m4_mult(m_orth_per, mcam, temp);
    m4_mult(mvp, temp, res);
    for (int i = 0; i < w->map.rows; i++)
    {
        for (int j = 0; j < w->map.cols; j++)
        {
            m4_mult_hv(res, w->map.verts[i][j].position, w->map.transformed[i][j].position);
            w->map.transformed[i][j].position[0] /= w->map.transformed[i][j].position[3];
            w->map.transformed[i][j].position[1] /= w->map.transformed[i][j].position[3];
        }
    }
    for (int i = 0; i < w->width; i++)
        for (int j = 0; j < w->height; j++)
            w->pixels[i * w->height + j] = 0;
    for (int k = 0; k < w->map.line_count; k++)
    {
        draw_line_dda(&w->map.lines[k], w->pixels, w->width);
    }
    mlx_put_image_to_window(w->mlx, w->window, w->image, 0,0);
}

int         keys_hook(int keycode, t_world *world)
{
    t_camera    *camera;
    matrix4     *trans;

    camera = &world->camera;
    ft_putstr("KEYCODE: ");
    ft_putnbr(keycode);
    ft_putendl("\n");
    if (keycode == 53)
        exit(0);
    else if (keycode == 13)
        camera_pitch(camera, -PI / 180);
    else if (keycode == 1)
        camera_pitch(camera, PI / 180);
    else if (keycode == 18)
        world->view_type = ORTHOGONAL;
    else if (keycode == 19)
        world->view_type = PERSPECTIVE;
    else if (keycode == 12)//Q
        camera_roll(camera, -PI / 180 );
    else if (keycode == 14)//E
        camera_roll(camera, PI / 180);
    else if (keycode == 0)//A
        camera_yaw(camera, -PI / 180);
    else if (keycode == 2)//D
        camera_yaw(camera, PI / 180);
    else if (keycode == 38)
        change_z(world->map.verts, world->map.rows, world->map.cols, 1.2);
    else if (keycode == 40)
        change_z(world->map.verts, world->map.rows, world->map.cols, 1 / 1.2f);
    else if (keycode == 7)
        scale_all(world->map.verts, world->map.rows, world->map.cols, 1.2);
    else if (keycode == 8)
        scale_all(world->map.verts, world->map.rows, world->map.cols, 1/1.2f);

    render(world);
    return (0);
}

int         mouse_hook(int button, int x, int y, t_world *world)
{
    t_camera    *camera;
    matrix4     *trans;

    camera = &world->camera;
    if (button == 5)//W
        camera_move(camera, 1);
    else if (button == 4)//S
        camera_move(camera, 0);

    render(world);
    return (0);
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
        world.camera.eye = v3_create(0, 0, 10);
        world.camera.gaze = v3_create(0, 0, -1);
        vector3 oy = v3_create(0, 1, 0);
        vector3 temp = v3_cross_product(world.camera.gaze, oy);
        world.camera.view_up = v3_cross_product(temp, world.camera.gaze);
        world.box.bottom = -10;
        world.box.top = 10;
        world.box.left = -10 * (float)world.width / (float)world.height;
        world.box.right = 10 * (float)world.width / (float)world.height;
        world.box.near = -5;
        world.box.far = -1000;
        render(&world);
        mlx_mouse_hook(world.window, mouse_hook, &world);
        mlx_key_hook(world.window, keys_hook, &world);
        mlx_loop(world.mlx);
    }
}


