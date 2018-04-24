#include "cinderella.h"

/**
BITMAP *game(BITMAP *buff)
{
}
**/

BITMAP *menu_func(BITMAP *menu, int *status, t_box *boxes)
{
    boxes[0] = buttonStatusUpdate(boxes[0]);
    if ((boxes[0]).but_status == 2)
      *status = 1;
    menu = put_box(boxes[0], menu);
}

void cind(void)
{
    BITMAP  *win;
    BITMAP  *game;
    BITMAP  *menu;
    t_box   *boxes;
    int     *status;


    if (!(boxes = (t_box *)malloc(sizeof(t_box) * 20))) /// 20 !!
        exit(EXIT_FAILURE);

    init_all();

    game = create_bitmap(SCREEN_W, SCREEN_H);
    menu = create_bitmap(SCREEN_W, SCREEN_H);
    win = game;

    ///-----
    clear_bitmap(menu);
    clear_bitmap(game);
    game = backgroundColor(WHITE, game);
    menu = backgroundColor(WHITE, menu);
    boxes[0] = newButton(200, 400, "Nouvelle partie");
    menu = put_box(boxes[0], menu);
    win = menu;
    *status = 0;
    blit(win, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    /// ------

    while (!key[KEY_ENTER])
    {
        win = (*status == 0) ? menu : game;
        if (*status == 0)
            menu = menu_func(menu, status, boxes);
        blit(win, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
}
