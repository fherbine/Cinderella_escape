#include "cinderella.h"

/**
 * In this file you can find functions to change layout to modify or create main blocks.
**/


/// The following function can be use at the beginning of the code to change the background color.

BITMAP      *backgroundColor(int color, BITMAP *buff)
{
    BITMAP  *buffer;

    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    //clear_bitmap(buffer);
    rectfill(buffer, 0, 0, SCREEN_W, SCREEN_H, color);
    blit(buffer, buff, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    destroy_bitmap(buffer);
    return (buff);
}

BITMAP      *backgroundImg(char *path, BITMAP *buff)
{
    buff = add_reg_bmp(buff, path, 800, 600, 0, 0);
    return (buff);
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
    newBox.but_status = -1;
    return(newBox);
}


/// This function displays a box into window

BITMAP  *put_box(t_box box, BITMAP *buff)
{
    int     wdth = box.x2 - box.x1, height = box.y2 - box.y1;
    BITMAP  *buffer;

    buffer = create_bitmap(wdth + 1, height + 1);
    //clear_bitmap(buffer);
    if (box.bg_color != NONE)
        rectfill(buffer, 0, 0, wdth, height, box.bg_color);
    if (box.borders != NONE)
        rect(buffer, 0, 0, wdth, height, box.borders);
    else if (box.borderBottom != NONE || box.borderLeft != NONE || box.borderRight != NONE || box.borderTop != NONE)
    {
            rect(buffer, 0, 0, wdth, height, WHITE);
        if (box.borderBottom != NONE)
            line(buffer, 1, height, wdth, height, box.borderBottom);
        if (box.borderTop != NONE)
            line(buffer, 0, 0, wdth + 1, 0, box.borderTop);
        if (box.borderLeft != NONE)
            line(buffer, 0, 0, 0, height + 1, box.borderLeft);
        if (box.borderRight != NONE)
            line(buffer, wdth, 1, wdth, height, box.borderRight);
    }
    //text_mode(-1);
    if (box.text)
        textprintf_centre(buffer, font, wdth / 2, height / 2 - (text_height(font) / 2), box.txt_color, box.text);
    blit(buffer, buff, 0, 0, box.x1, box.y1, wdth + 1, height + 1);
    destroy_bitmap(buffer);
    return (buff);
}


