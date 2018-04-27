#include "cinderella.h"

t_page  *game_init(void)
{
    t_page *game;

    if (!(game = (t_page *)malloc(sizeof(t_page))))
        exit(EXIT_FAILURE);
    if (!(game->buts = (t_box *)malloc(sizeof(t_box) * 10))) /// 10 !!
        exit(EXIT_FAILURE);
        return(game);
}

void    game_routine(t_page *game)
{
    game->win = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(game->win);
    game->win = backgroundColor(WHITE, game->win);
    (game->buts)[0] = newButton(675, 20, "Menu");
    game->win = put_box(game->buts[0], game->win);

    rect(game->win, 237, 107, 798, 598, BLACK);
    game->win = add_reg_bmp(game->win, "imgs/map1.bmp", 560, 490, 238, 108);
}

void game_func(t_page *game, int *status, t_bots *bot)
{
    game->buts[0] = buttonStatusUpdate(game->buts[0]);
    if ((game->buts[0]).but_status == 2)
    {
        *status = 0;
        destroy_bitmap(game->win);
        return;
    }
    game->win = put_box(game->buts[0], game->win);
    if (key[KEY_ENTER])
        refresh_bot(bot, 0, 0, game);
}
