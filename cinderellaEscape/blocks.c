#include "cinderella.h"

/**
 * In this file you can find function to change layout to modify or create main blocks.
**/


/// The following function can be use at the beginning of the code to change the background color.

void        backgroundColor(int color)
{
    BITMAP  *buffer;

    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(buffer);
    rectfill(buffer, 0, 0, SCREEN_W, SCREEN_H, color);
    blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
}


/// This function permit the initialization of a new box in the program

t_box       init_box(void)
{
    t_box newBox;

    newBox.borders = -1;
    newBox.bg_color = -1;
    newBox.text = NULL;
    return(newBox);
}
