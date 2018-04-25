#include "cinderella.h"

BITMAP *add_alph_bmp(BITMAP *curr, char *path, int pic_w, int pic_h)
{
    printf("\ntutu\n");
    BITMAP* pic ;

    printf("\ntutu\n");
    pic = load_bitmap(path, NULL) ;
    printf("\ntutu\n");

    if(!pic) {
        set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
        allegro_message("Error ! Image cannot be read !");
        exit(EXIT_FAILURE);
    }
    masked_blit(pic, curr, 0, 0, 300, 20, pic_w, pic_h);
    destroy_bitmap(pic);
    return(curr);
}
