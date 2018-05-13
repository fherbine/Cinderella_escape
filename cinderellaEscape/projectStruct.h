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

typedef struct  s_text
{
    char        buf[256];
    int         x1, y1; // box coord1
    int         x2, y2; // box coord2
    int         cx, cy; // cursor position
    int         cursor; // cursor position in buffer
    int         i;
    float       n;
}               t_text;

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
    float       last_x, last_y;
    float       dest_x, dest_y;
    float       cur_img;
    int         angle;
}               t_bots;

typedef struct  s_elems
{
    float         virt_x, virt_y;
}               t_elems;

typedef struct  s_page
{
    BITMAP      *win;
    t_box       *boxes;
    t_text      *editor;
    t_bots      **bots;
    int         cbot;
    t_elems     **elems;
    int         execution, lvl;
}               t_page;

#endif
