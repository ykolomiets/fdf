#include "render.h"
#include "clipping.h"
#include "rasterization.h"
#include "viewing_tranformations.h"

void        clean_image(t_fdf *all)
{
    int total;
    int *pixels;

    total = all->width * all->height;
    pixels = all->image.pixels;
    while (total--)
        pixels[total] = 0;
}

void        render(t_fdf  *all)
{
    matrix4 mcam;
    matrix4 mrest;
    t_line  transformed;
    int     i;

    create_camera_transform(&all->camera, mcam);
    create_vp_proj_tranform(all, mrest);
    i = 0;
    clean_image(all);
    while (i < all->map.line_count)
    {
        transformed = all->map.lines[i++];
        transformed.p1.position = m4_mult_hv(mcam, &transformed.p1.position);
        transformed.p2.position = m4_mult_hv(mcam, &transformed.p2.position);
        if (clip_near(&transformed, all->box.near))
        {
            transformed.p1.position = m4_mult_hv(mrest, &transformed.p1.position);
            transformed.p2.position = m4_mult_hv(mrest, &transformed.p2.position);
            transformed.p1.position = hv_normalize(transformed.p1.position);
            transformed.p2.position = hv_normalize(transformed.p2.position);
            draw_line_dda(&transformed, all);
        }
    }
    mlx_put_image_to_window(all->mlx, all->window, all->image.image, 0, 0);
}