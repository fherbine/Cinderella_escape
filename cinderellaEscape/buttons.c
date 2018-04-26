#include "cinderella.h"

/**
 * In this file you can find functions to displays buttons.
**/


/// default button layout

static t_box   regularButton(t_box button)
{
    button.borderTop = LIGHTGREY;
    button.borderLeft = LIGHTGREY;
    button.borderBottom = BLACK;
    button.borderRight = BLACK;
    button.bg_color = WHITE;
    return(button);
}

/// Modify the layout when mouse hover

static t_box   hoverButton(t_box button)
{
    button.borderTop = BLACK;
    button.borderLeft = BLACK;
    button.borderBottom = LIGHTGREY;
    button.borderRight = LIGHTGREY;
    button.bg_color = ULIGHTGREY;
    return(button);
}

/// this function is used to create a new button

t_box       newButton(int x, int y, char *text)
{
    int     height = 40, width = 10 + 25 * strlen(text);
    t_box   button;

    button = init_box(x, y, x + width, y + height);
    button.but_status = 0;
    button.bg_color = WHITE;
    button.text = text;
    button = regularButton(button);
    return (button);
}

/// the following function can be use to know a button's status and change it layout during mouse hover.

t_box   buttonStatusUpdate(t_box button)
{
    if (mouse_x >= button.x1 && mouse_x <= button.x2 && mouse_y >= button.y1 && mouse_y <= button.y2 && mouse_b != 1)
    {
        button = hoverButton(button);
        button.but_status = 1;
    }
    else if (mouse_x >= button.x1 && mouse_x <= button.x2 && mouse_y >= button.y1 && mouse_y <= button.y2 && mouse_b == 1)
        button.but_status = 2;
    else if(button.but_status != 0)
    {
        button = regularButton(button);
        button.but_status = 0;
    }
    return(button);
}
