#include "rgb.h"

t_rgb   rgb_from_int(int c)
{
    t_rgb   res;

    res.b = (unsigned char)(c & 0xff);
    c >>= 8;
    res.g = (unsigned char)(c & 0xff);
    c >>= 8;
    res.r = (unsigned char)c;
    return (res);
}

int     rgb_to_int(t_rgb *c)
{
    int res;

    res = c->r;
    res <<= 8;
    res |= c->g;
    res <<= 8;
    res |= c->b;
    return (res);
}

t_rgb   rgb_add(t_rgb c1, t_rgb c2)
{
    return (rgb_add_a(c1, c2, 0.5f));
}

t_rgb   rgb_add_a(t_rgb c1, t_rgb c2, float a)
{

    c1.r = (unsigned char )(c1.r * a + (1 - a) * c2.r);
    c1.g = (unsigned char )(c1.g * a + (1 - a) * c2.g);
    c1.b = (unsigned char )(c1.b * a + (1 - a) * c2.b);
    return (c1);
}
