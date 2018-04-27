#include "cinderella.h"

void game_func(t_page *game, int *status, t_bots *bot)
{
    game->buts[0] = buttonStatusUpdate(game->buts[0]);
    if ((game->buts[0]).but_status == 2)
      *status = 0;
    game->win = put_box(game->buts[0], game->win);
    if (key[KEY_ENTER])
        refresh_bot(bot, 10, 0, game);
}



void cind(void)
{
    int     st_val = 0;
    int     *status;
    BITMAP  *win;
    t_page  *game;
    t_page  *menu = menu_init();



    status = &st_val;
    if (!(game = (t_page *)malloc(sizeof(t_page))))
        exit(EXIT_FAILURE);

    if (!(game->buts = (t_box *)malloc(sizeof(t_box) * 10))) /// 10 !!
        exit(EXIT_FAILURE);


    init_all();

    menu_routine(menu);

    game->win = create_bitmap(SCREEN_W, SCREEN_H);


    ///-----

    clear_bitmap(game->win);
    game->win = backgroundColor(WHITE, game->win);

    (game->buts)[0] = newButton(675, 20, "Menu");

    game->win = put_box(game->buts[0], game->win);
    win = menu->win;
    blit(win, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    /// ------
        rect(game->win, 237, 107, 798, 598, BLACK);
        game->win = add_reg_bmp(game->win, "imgs/map1.bmp", 560, 490, 238, 108);
    /// -----


    /// -----
    t_bots *bot1;

    bot1 = new_bot(bots_tab[0], 0, 0, game);
    /// ----

    while (!key[KEY_ESC])
    {
        if (*status == 0)
            menu_func(menu, status);

        if (*status == 1)
        {
            printf("tutu");
            game_func(game, status, bot1);
            printf("tutu");
            if (*status == 0)
            {
                menu_routine(menu);
            }
        }


        if (*status == 2)
            leave_game(game, menu);
        win = (*status == 0) ? menu->win : game->win;
        blit(win, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
}
