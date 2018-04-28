#include "cinderella.h"

static BITMAP *add_bmp(char *path)
{
    BITMAP* pic ;

    pic = load_bitmap(path, NULL) ;

    if(!pic) {
        set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
        allegro_message("Error ! Image cannot be read !");
        exit(EXIT_FAILURE);
    }
    return (pic);
}

BITMAP *add_reg_bmp(BITMAP *curr, char *path, int pic_w, int pic_h, int dest_x, int dest_y)
{
    BITMAP* pic ;

    pic = add_bmp(path);
    blit(pic, curr, 0, 0, dest_x, dest_y, pic_w, pic_h);
    destroy_bitmap(pic);
    return(curr);
}

BITMAP *add_alph_bmp(BITMAP *curr, char *path, int pic_w, int pic_h, int dest_x, int dest_y)
{
    BITMAP* pic ;

    pic = add_bmp(path);
    masked_blit(pic, curr, 0, 0, dest_x, dest_y, pic_w, pic_h);
    destroy_bitmap(pic);
    return(curr);
}

t_elems *new_elem(int x, int y, char *path, t_page *game)
{
    t_elems *elem;

    if (!(elem = (t_elems *)malloc(sizeof(t_elems))))
        exit(EXIT_FAILURE);
    elem->virt_x = x;
    elem->virt_y = y;
    add_reg_bmp(game->win, "imgs/finish.bmp", 35, 35, 238 + (x * 35), 108 + (y * 35));
    return (elem);
}
