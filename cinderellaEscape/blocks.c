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

t_box       init_box(int x1, int y1, int x2, int y2)
{
    t_box newBox;

    newBox.borders = NONE;
    newBox.bg_color = NONE;
    newBox.text = NULL;
    newBox.txt_color = BLACK;
    newBox.x1 = x1;
    newBox.y1 = y1;
    newBox.x2 = x2;
    newBox.y2 = y2;
    return(newBox);
}


/// This function displays a box into window

void        put_box(t_box box)
{
    BITMAP  *buffer;
    int     wdth = box.x2 - box.x1, height = box.y2 - box.y1;

    buffer = create_bitmap(wdth, height);
    clear_bitmap(buffer);
    if (box.bg_color != NONE)
        rectfill(buffer, 0, 0, wdth, height, box.bg_color);
    if (box.borders != NONE)
        rect(buffer, 0, 0, wdth, height, box.borders);
    else if (box.borderBottom != NONE || box.borderLeft != NONE || box.borderRight != NONE || box.borderTop != NONE)
    {
        if (box.borderBottom != NONE)
            line(buffer, 0, height, wdth, height, box.borderBottom);
        if (box.borderTop != NONE)
            line(buffer, 0, 0, wdth, 0, box.borderTop);
        if (box.borderLeft != NONE)
            line(buffer, 0, 0, 0, height, box.borderLeft);
        if (box.borderRight != NONE)
            line(buffer, wdth, 0, wdth, height, box.borderLeft);
    }
    if (box.text)
        textprintf_centre(buffer, font, wdth, height, box.txt_color, box.text);
    blit(buffer, screen, box.x1, box.y1, box.x2, box.y2, wdth, height);
}
