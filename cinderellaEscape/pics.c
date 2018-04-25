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

BITMAP *add_reg_bmp(BITMAP *curr, char *path, int pic_w, int pic_h)
{
    BITMAP* pic ;

    pic = add_bmp(path);
    blit(pic, curr, 0, 0, 300, 20, pic_w, pic_h);
    destroy_bitmap(pic);
    return(curr);
}

BITMAP *add_alph_bmp(BITMAP *curr, char *path, int pic_w, int pic_h)
{
    BITMAP* pic ;

    pic = add_bmp(path);
    masked_blit(pic, curr, 0, 0, 300, 20, pic_w, pic_h);
    destroy_bitmap(pic);
    return(curr);
}
