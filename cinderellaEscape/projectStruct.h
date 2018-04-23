#ifndef PROJECTSTRUCT_H_INCLUDED
#define PROJECTSTRUCT_H_INCLUDED

typedef struct  s_box
{
    int         x1, y1;
    int         x2, y2;
    int         borders, borderLeft, borderRight, borderTop, borderBottom;
    int         bg_color;
    char        *text;
}               t_box;

#endif
