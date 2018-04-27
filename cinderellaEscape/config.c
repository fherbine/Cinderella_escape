#include "cinderella.h"


/**
 *      This file contain configuration functions.
**/


/// This function init allegro itself, keyboard, mouse & graphical mode.

int     init_all(void)
{
    allegro_init();

    if(install_keyboard() == -1)
    {
        allegro_message("An error occured: %s\n", allegro_error);
        return (-1);
    }
    if(install_mouse() == -1)
    {
        allegro_message("An error occured: %s\n", allegro_error);
        return (-1);
    }

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0) != 0)
    {
        set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
        allegro_message("Cannot set video mode : %s\n", allegro_error);
        return (-1);
    }

    show_mouse(screen);
    init_all_seq();
    text_mode(-1);
    return (1);
}
