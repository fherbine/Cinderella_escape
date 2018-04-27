#include "cinderella.h"

void cind(void)
{
    int     st_val = 0;
    int     *status;
    BITMAP  *win;
    t_page  *game = game_init();
    t_page  *menu = menu_init();
    status = &st_val;

    init_all();

    menu_routine(menu);
    game_routine(game);

    /// -----
    t_bots *bot1;
    bot1 = new_bot(bots_tab[0], 0, 10, game);
    /// ----

    win = menu->win;
    ///-----
    blit(win, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    /// ------
    while (!key[KEY_ESC])
    {
        if (*status == 0)
        {
            menu_func(menu, status);
            if (*status == 1)
                game_routine(game);
        }

        if (*status == 1)
        {
            game_func(game, status, bot1);
            if (*status == 0)
                menu_routine(menu);
        }


        printf("ll\n");
        if (*status == 2)
            leave_game(game, menu);
        win = (*status == 0) ? menu->win : game->win;
        printf("1\n");
        blit(win, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        printf("2\n");
    }
}
