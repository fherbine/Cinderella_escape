#include "cinderella.h"

/**
 * In this file you can find functions to displays buttons.
**/


/// this function is used to create a new button

t_box   newButton(int x, int y, char *text)
{
    int     color1 = LIGHTGREY, color2 = BLACK;
    int     height = 40, width = 10 + 25 * strlen(text);
    t_box   button;

    button = init_box(x, y, x + width, y + height);
    button.bg_color = WHITE;
    button.borderTop = color1;
    button.borderLeft = color1;
    button.borderBottom = color2;
    button.borderRight = color2;
    button.text = text;
    return (button);
}
