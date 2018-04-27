#ifndef PROJECTSTRUCT_H_INCLUDED
#define PROJECTSTRUCT_H_INCLUDED

typedef struct  s_box
{
    int         x1, y1;
    int         x2, y2;
    int         borders, borderLeft, borderRight, borderTop, borderBottom;
    int         bg_color;
    char        *text;
    int         txt_color;
    int         but_status;
}               t_box;

typedef struct  s_page
{
    BITMAP      *win;
    t_box       *buts;
}               t_page;

typedef struct  s_bots_seq
{
    char        *path;
    int         nimg;
    float        sx, sy;
    BITMAP      **img;
}               t_bots_seq;

typedef struct  s_bots
{
    t_bots_seq  seq;
    BITMAP      *buffer;
    float       pos_x, pos_y;
    float       virt_x, virt_y;
    int         cur_img;
}               t_bots;

#endif
