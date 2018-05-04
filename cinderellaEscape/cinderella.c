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

    menu_routine(menu, game);
    game_routine(game);
    win = menu->win;
    blit(win, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    while (!key[KEY_ESC])
    {
        if (*status == 0)
        {
            menu_func(menu, game, status);
            if (*status == 1)
            {
                game->lvl = 1;
                game_routine(game);
            }
        }

        if (*status == 1)
        {
            game_func(game, status);
            if (*status == 0)
                menu_routine(menu, game);
        }

        if (*status == -1)
            leave_game(game, menu);
        win = (*status == 0) ? menu->win : game->win;
        blit(win, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
}
