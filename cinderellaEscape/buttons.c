#include "cinderella.h"

/**
 * In this file you can find functions to displays buttons.
**/


/// this function is used to create a new button

t_box       newButton(int x, int y, char *text)
{
    int     height = 40, width = 10 + 25 * strlen(text);
    t_box   button;

    button = init_box(x, y, x + width, y + height);
    button.bg_color = WHITE;
    button.text = text;
    button = regularButton(button);
    return (button);
}


t_box   regularButton(t_box button)
{
    button.borderTop = LIGHTGREY;
    button.borderLeft = LIGHTGREY;
    button.borderBottom = BLACK;
    button.borderRight = BLACK;
    return(button);
}

t_box   hoverButton(t_box button)
{
    button.borderTop = BLACK;
    button.borderLeft = BLACK;
    button.borderBottom = LIGHTGREY;
    button.borderRight = LIGHTGREY;
    button.bg_color = ULIGHTGREY;
    return(button);
}

/// on peut opti

t_box   buttonStatusUpdate(t_box button)
{
    if (mouse_x >= button.x1 && mouse_x <= button.x2 && mouse_y >= button.y1 && mouse_y <= button.y2)
    {
        button = hoverButton(button);
    }
    else
        button = regularButton(button);
    put_box(button);
    return(button);
}
