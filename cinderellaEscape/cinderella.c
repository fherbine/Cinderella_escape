#include "cinderella.h"

/**
BITMAP *game(BITMAP *buff)
{
}
**/

BITMAP *menu_func(BITMAP *menu, int *status, t_box *m_buts)
{
    m_buts[0] = buttonStatusUpdate(m_buts[0]);
    if ((m_buts[0]).but_status == 2)
      *status = 1;
    menu = put_box(m_buts[0], menu);
}

void cind(void)
{
    BITMAP  *win;
    BITMAP  *game;
    BITMAP  *menu;
    t_box   *m_buts;
    t_box   *g_buts;
    int     *status;


    if (!(m_buts = (t_box *)malloc(sizeof(t_box) * 20))) /// 20 !!
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
    m_buts[0] = newButton(200, 400, "Nouvelle partie");
    menu = put_box(m_buts[0], menu);
    menu = add_alph_bmp(menu, "imgs/banner.bmp", 200, 90);
    win = menu;
    *status = 0;
    blit(win, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    /// ------

    while (!key[KEY_ENTER])
    {
        win = (*status == 0) ? menu : game;
        if (*status == 0)
            menu = menu_func(menu, status, m_buts);
        blit(win, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
}
