#include "cinderella.h"

t_page  *menu_init(void)
{
    t_page *menu;

    if (!(menu = (t_page *)malloc(sizeof(t_page))))
        exit(EXIT_FAILURE);
    if (!(menu->buts = (t_box *)malloc(sizeof(t_box) * 10))) /// 10 !!
        exit(EXIT_FAILURE);
    return (menu);
}
void    menu_routine(t_page *menu, t_page *game)
{
    menu->win = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(menu->win);
    menu->win = backgroundImg("imgs/bg.bmp", menu->win);
    (menu->buts)[0] = newButton(200, 375, "Nouvelle partie");
    (menu->buts)[1] = newButton(300, 450, "Quitter");
    (menu->buts)[2] = newButton(45, 300, "LVL 1");
    (menu->buts)[3] = newButton(195, 300, "LVL 2");
    (menu->buts)[4] = newButton(345, 300, "LVL 3");
    (menu->buts)[5] = newButton(480, 300, "LVL 4");
    menu->win = put_box(menu->buts[0], menu->win);
    menu->win = put_box(menu->buts[1], menu->win);
    if (game->lvl)
        menu->win = put_box(menu->buts[2], menu->win);
    //menu->win = add_alph_bmp(menu->win, "imgs/banner.bmp", 200, 90, 300, 20);
}

static int display_game_lvl(t_page *menu, t_page *game, int *status, int lvl)
{
    int i = 1;

    for (i = 1; i <= lvl; i++)
    {
        menu->buts[i + 1] = buttonStatusUpdate(menu->buts[i + 1]);
        if ((menu->buts[i + 1]).but_status == 2)
        {
            game->lvl = i;
            destroy_bitmap(menu->win);
            *status = 1;
            game_routine(game);
            return (0);
        }
        menu->win = put_box(menu->buts[i + 1], menu->win);
    }
    return (1);
}

void menu_func(t_page *menu, t_page *game, int *status)
{
    menu->buts[0] = buttonStatusUpdate(menu->buts[0]);
    if ((menu->buts[0]).but_status == 2)
    {
        *status = 1;
        destroy_bitmap(menu->win);
        return;
    }

    menu->win = put_box(menu->buts[0], menu->win);

    menu->buts[1] = buttonStatusUpdate(menu->buts[1]);
    if ((menu->buts[1]).but_status == 2)
      *status = 2;
    menu->win= put_box(menu->buts[1], menu->win);

    if (game->lvl)
    {
        if (!display_game_lvl(menu, game, status, game->lvl))
        return ;
    }
}

