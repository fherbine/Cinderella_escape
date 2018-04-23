#include "cinderella.h"

/**
 * In this file you can find function to change layout to modify or create main blocks.
**/


/// The following function can be use at the beginning of the code to change the background color.

void    backgroundColor(int color)
{
    BITMAP *buffer;

    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(buffer);
    rectfill(buffer, 0, 0, SCREEN_W, SCREEN_H, color);
    blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
}
