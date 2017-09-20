#include "fdf.h"
#include "libft.h"
#include "read_map.h"
#include "render.h"
#include "camera_transformations.h"
#include "world_transformations.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void        keys_hook2(int keycode, t_fdf *all)
{
    float   temp;

    if (keycode == 38)
        change_z(all->map.lines, all->map.line_count, 1.2);
    else if (keycode == 40)
        change_z(all->map.lines, all->map.line_count, 1 / 1.2f);
    else if (keycode == 7)
        scale_all(all->map.lines, all->map.line_count, 1.2);
    else if (keycode == 8)
        scale_all(all->map.lines, all->map.line_count, 1 / 1.2f);
    else if (keycode == 32)
    {
        temp = all->box.near + 1;
        if (temp < -0.0005f)
            all->box.near = temp;
    }
    else if (keycode == 34)
    {
        temp = all->box.near - 1;
        if (temp > all->box.far)
            all->box.near = temp;
    }
}

int         keys_hook(int keycode, t_fdf *all)
{
    printf("keycode: %d\n", keycode);
    if (keycode == 53)
        exit(0);
    else if (keycode == 13)
        camera_pitch(&(all->camera), -PI / 180);
    else if (keycode == 1)
        camera_pitch(&(all->camera), PI / 180);
    else if (keycode == 18)
        all->view_type = 1 - all->view_type;
    else if (keycode == 19)
        all->cmode = (all->cmode + 1) % 3;
    else if (keycode == 12)
        camera_roll(&(all->camera), PI / 180 );
    else if (keycode == 14)
        camera_roll(&(all->camera), -PI / 180);
    else if (keycode == 0)
        camera_yaw(&(all->camera), PI / 180);
    else if (keycode == 2)
        camera_yaw(&(all->camera), -PI / 180);
    else
        keys_hook2(keycode, all);

    render(all);
    return (0);
}

int         mouse_hook(int button, int x, int y, t_fdf *all)
{
    if (button == 5)
        camera_move(&all->camera, 1);
    else if (button == 4)
        camera_move(&all->camera, 0);

    render(all);
    return (0);
}

int         fdf_init(t_fdf  *all, char *name)
{
    all->mlx = mlx_init();
    if (!all->mlx)
        return (1);
    all->height = 400;
    all->width = 400;
    all->window = mlx_new_window(all->mlx, all->width, all->height, name);
    if (!all->window)
        return (2);
    all->image.image = mlx_new_image(all->mlx, all->width, all->height);
    if (!all->image.image)
        return (3);
    all->image.pixels = (int *)mlx_get_data_addr(all->image.image, &all->image.bpp,
                                          &all->image.size_line, &all->image.endian);
    all->camera.eye = v3_create(0, 0, 10);
    all->camera.gaze = v3_create(0, 0, -1);
    all->camera.view_up = v3_create(0, 1, 0);
    all->box.bottom = -10;
    all->box.top = 10;
    all->box.left = -10 * (float)all->width / (float)all->height;
    all->box.right = 10 * (float)all->width / (float)all->height;
    all->box.near = -1;
    all->box.far = -1000;
    all->view_type = ORTHOGONAL;
    all->cmode = 0;
    return (0);
}

void        fdf(char    *file_name)
{
    t_fdf   all;

    if (read_map(file_name, &all.map))
        ft_putendl("error: invalid map");
    else
    {
        if (!fdf_init(&all, file_name))
        {
            render(&all);
            mlx_mouse_hook(all.window, mouse_hook, &all);
            mlx_key_hook(all.window, keys_hook, &all);
            mlx_loop(all.mlx);
        }
        else
            ft_putendl("error: initialization failed");
    }
}


