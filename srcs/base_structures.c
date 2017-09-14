#include "base_structures.h"
#include <stdio.h>

void        print_vertex(t_vertex *v)
{
    printf("{\n\tpos: ");
    hv_print(v->position);
    printf("\tcolor: %x\n}\n", v->color);
}

void        print_line_segment(t_line_segment *l)
{
    printf("{\n v1: ");
    print_vertex(l->p1);
    printf("\n v2: ");
    print_vertex(l->p2);
    printf("\n}");
}

void                print_matrix4(matrix4 m)
{
    for(int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%f | ", m[i * 4 + j]);
        }
        printf("\n---------------------------\n");
    }
}