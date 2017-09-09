#include "mathx.h"
#include <stdio.h>

int main()
{
    vector3 x = v3_create(1, 0, 0);
    vector3 y = v3_create(0, 1, 0);

    printf("x = <%f, %f, %f>\n", x[0], x[1], x[2]);
    printf("y = <%f, %f, %f>\n", y[0], y[1], y[2]);

    vector3 z = v3_cross_product(x, y);
    printf("z = <%f, %f, %f>\n", z[0], z[1], z[2]);


    return (0);
}