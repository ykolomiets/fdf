#include "colors.h"



t_rgb   *hsv2rgb_help(t_rgb *out, double r, double g, double b)
{
    out->r = (unsigned char) (r * 255);
    out->g = (unsigned char) (g * 255);
    out->b = (unsigned char) (b * 255);

    return (out);
}

t_rgb   hsv_to_rgb(t_hsv in)
{
    double      temp[5];// hh, p, q, t, ff
    long        i;
    t_rgb       out;

    if(in.s <= 0.0001)
        return (*hsv2rgb_help(&out, in.v, in.v, in.v));
    temp[0] = in.h;
    if(temp[0] >= 359.999)
        temp[0] = 0.0;
    temp[0] /= 60.0;
    i = (long)temp[0];
    temp[4] = temp[0] - i;
    temp[1] = in.v * (1.0 - in.s);
    temp[2] = in.v * (1.0 - (in.s * temp[4]));
    temp[3] = in.v * (1.0 - (in.s * (1.0 - temp[4])));
    if (i == 0)
        return (*hsv2rgb_help(&out, in.v, temp[3], temp[1]));
    else if (i == 1)
        return (*hsv2rgb_help(&out, temp[2], in.v, temp[1]));
    else if (i == 2)
        return (*hsv2rgb_help(&out, temp[1], in.v, temp[3]));
    else if (i == 3)
        return (*hsv2rgb_help(&out, temp[1], temp[2], in.v));
    else if (i == 4)
        return (*hsv2rgb_help(&out, temp[3], temp[1], in.v));
    return (*hsv2rgb_help(&out, in.v, temp[1], temp[2]));
}