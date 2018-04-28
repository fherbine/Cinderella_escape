#include "cinderella.h"

t_page  *game_init(void)
{
    t_page *game;

    if (!(game = (t_page *)malloc(sizeof(t_page))))
        exit(EXIT_FAILURE);
    if (!(game->buts = (t_box *)malloc(sizeof(t_box) * 10))) /// 10 !!
        exit(EXIT_FAILURE);
    if (!(game->bots = (t_bots **)malloc(sizeof(t_bots *) * 20))) /// 20
        exit(EXIT_FAILURE);
    return(game);
}

void    clear_lvl1(t_page *game)
{
    game->win = add_reg_bmp(game->win, "imgs/map1.bmp", 560, 490, 238, 108);
}

void    game_routine(t_page *game)
{
    game->win = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(game->win);
    game->win = backgroundColor(WHITE, game->win);
    (game->buts)[0] = newButton(675, 20, "Menu");
    (game->buts)[1] = newButton(15, 150, "Run");
    game->win = put_box(game->buts[0], game->win);
    game->win = put_box(game->buts[1], game->win);

    rect(game->win, 237, 107, 798, 598, BLACK);
    rect(game->win, 15, 190, 220, 380, BLACK);
    game->editor = new_txt(20, 200, 220, 368);
    (game->bots)[0] = new_bot(bots_tab[0], 0, 10, game);
    clear_lvl1(game);
}

void game_func(t_page *game, int *status)
{
    game->buts[0] = buttonStatusUpdate(game->buts[0]);
    if ((game->buts[0]).but_status == 2)
    {
        *status = 0;
        destroy_bitmap(game->win);
        return;
    }
    game->win = put_box(game->buts[0], game->win);

    game->buts[1] = buttonStatusUpdate(game->buts[1]);
    game->win = put_box(game->buts[1], game->win);
    if (key[KEY_ENTER])
        refresh_bot((game->bots)[0], 0, 0, game);
    read_buf(game->editor, game);
}
