#include "cinderella.h"

void    backgroundColor(int color)
{
    BITMAP *buffer;

    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(buffer);
    rectfill(buffer, 0, 0, SCREEN_W, SCREEN_H, color);
    blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
}
