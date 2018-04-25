#include "cinderella.h"

BITMAP *game_func(BITMAP *game, int *status, t_box *g_buts)
{
    g_buts[0] = buttonStatusUpdate(g_buts[0]);
    if ((g_buts[0]).but_status == 2)
      *status = 0;
    game = put_box(g_buts[0], game);
    return(game);
}

BITMAP *menu_func(BITMAP *menu, int *status, t_box *m_buts)
{
    m_buts[0] = buttonStatusUpdate(m_buts[0]);
    if ((m_buts[0]).but_status == 2)
      *status = 1;
    menu = put_box(m_buts[0], menu);
    return (menu);
}

void cind(void)
{
    int     st_val = 0;
    int     *status;
    BITMAP  *win;
    BITMAP  *game;
    BITMAP  *menu;
    t_box   *m_buts;
    t_box   *g_buts;



    status = &st_val;
    if (!(m_buts = (t_box *)malloc(sizeof(t_box) * 3))) /// 20 !!
        exit(EXIT_FAILURE);
    if (!(g_buts = (t_box *)malloc(sizeof(t_box) * 20))) /// 20 !!
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
    g_buts[0] = newButton(600, 2, "Menu");
    menu = put_box(m_buts[0], menu);
    game = put_box(g_buts[0], game);
    menu = add_alph_bmp(menu, "imgs/banner.bmp", 200, 90);
    win = menu;
    blit(win, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    /// ------

    while (!key[KEY_ENTER])
    {
        win = (*status == 0) ? menu : game;
        if (*status == 0)
            menu = menu_func(menu, status, m_buts);
        if (*status == 1)
            game = game_func(game, status, g_buts);
        blit(win, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
}
