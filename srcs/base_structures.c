#include "base_structures.h"
#include <stdio.h>

void        print_vertex(t_vertex *v)
{
    printf("{\n\tpos: ");
    hv_print(v->position);
    printf("\tcolor: %x\n}\n", v->color);
}