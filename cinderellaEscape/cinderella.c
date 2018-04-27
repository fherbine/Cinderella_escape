#include "cinderella.h"

void game_func(t_page *game, int *status)
{
    game->buts[0] = buttonStatusUpdate(game->buts[0]);
    if ((game->buts[0]).but_status == 2)
      *status = 0;
    game->win = put_box(game->buts[0], game->win);
}

void menu_func(t_page *menu, int *status)
{
    menu->buts[0] = buttonStatusUpdate(menu->buts[0]);
    if ((menu->buts[0]).but_status == 2)
      *status = 1;
    menu->win = put_box(menu->buts[0], menu->win);

    menu->buts[1] = buttonStatusUpdate(menu->buts[1]);
    if ((menu->buts[1]).but_status == 2)
      *status = 2;
    menu->win= put_box(menu->buts[1], menu->win);
}

void cind(void)
{
    int     st_val = 0;
    int     *status;
    BITMAP  *win;
    t_page  *game;
    t_page  *menu;



    status = &st_val;
    if (!(game = (t_page *)malloc(sizeof(t_page))))
        exit(EXIT_FAILURE);
    if (!(menu = (t_page *)malloc(sizeof(t_page))))
        exit(EXIT_FAILURE);
    if (!(menu->buts = (t_box *)malloc(sizeof(t_box) * 10))) /// 10 !!
        exit(EXIT_FAILURE);
    if (!(game->buts = (t_box *)malloc(sizeof(t_box) * 10))) /// 10 !!
        exit(EXIT_FAILURE);


    init_all();

    game->win = create_bitmap(SCREEN_W, SCREEN_H);
    menu->win = create_bitmap(SCREEN_W, SCREEN_H);

    ///-----
    clear_bitmap(menu->win);
    clear_bitmap(game->win);
    game->win = backgroundColor(WHITE, game->win);
    menu->win = backgroundColor(WHITE, menu->win);

    (menu->buts)[0] = newButton(200, 400, "Nouvelle partie");
    (menu->buts)[1] = newButton(300, 500, "Quitter");
    (game->buts)[0] = newButton(675, 20, "Menu");
    menu->win = put_box(menu->buts[0], menu->win);
    menu->win = put_box(menu->buts[1], menu->win);
    game->win = put_box(game->buts[0], game->win);
    menu->win = add_alph_bmp(menu->win, "imgs/banner.bmp", 200, 90, 300, 20);
    win = menu->win;
    blit(win, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    /// ------
        rect(game->win, 237, 107, 798, 598, BLACK);
        game->win = add_reg_bmp(game->win, "imgs/map1.bmp", 560, 490, 238, 108);
    /// -----

    while (!key[KEY_ENTER])
    {
        win = (*status == 0) ? menu->win : game->win;
        if (*status == 0)
            menu_func(menu, status);

        if (*status == 1)
            game_func(game, status);

        if (*status == 2)
            leave_game(game, menu);
        blit(win, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
}
