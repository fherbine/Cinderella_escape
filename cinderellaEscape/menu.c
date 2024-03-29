#include "cinderella.h"

t_page  *menu_init(void)
{
    t_page *menu;

    if (!(menu = (t_page *)malloc(sizeof(t_page))))
        exit(EXIT_FAILURE);
    if (!(menu->boxes = (t_box *)malloc(sizeof(t_box) * 10))) /// 10 !!
        exit(EXIT_FAILURE);
    return (menu);
}
void    menu_routine(t_page *menu, t_page *game)
{
    menu->win = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(menu->win);
    menu->win = backgroundImg("imgs/bg.bmp", menu->win);
    (menu->boxes)[0] = newButton(200, 375, "Nouvelle partie");
    (menu->boxes)[1] = newButton(300, 450, "Quitter");
    (menu->boxes)[2] = newButton(108, 300, "LVL 1");
    (menu->boxes)[3] = newButton(258, 300, "LVL 2");
    (menu->boxes)[4] = newButton(408, 300, "LVL 3");
    (menu->boxes)[5] = newButton(558, 300, "LVL 4");
    menu->win = put_box(menu->boxes[0], menu->win);
    menu->win = put_box(menu->boxes[1], menu->win);
    if (game->lvl)
        menu->win = put_box(menu->boxes[2], menu->win);
    //menu->win = add_alph_bmp(menu->win, "imgs/banner.bmp", 200, 90, 300, 20);
}

static int display_game_lvl(t_page *menu, t_page *game, int *status, int lvl)
{
    int i = 1;

    for (i = 1; i <= lvl; i++)
    {
        menu->boxes[i + 1] = buttonStatusUpdate(menu->boxes[i + 1]);
        if ((menu->boxes[i + 1]).but_status == 2)
        {
            game->lvl = i;
            destroy_bitmap(menu->win);
            *status = 3;
            game_routine(game);
            return (0);
        }
        menu->win = put_box(menu->boxes[i + 1], menu->win);
    }
    return (1);
}

void menu_func(t_page *menu, t_page *game, int *status)
{
    menu->boxes[0] = buttonStatusUpdate(menu->boxes[0]);
    if ((menu->boxes[0]).but_status == 2)
    {
        *status = 1;
        destroy_bitmap(menu->win);
        return;
    }

    menu->win = put_box(menu->boxes[0], menu->win);

    menu->boxes[1] = buttonStatusUpdate(menu->boxes[1]);
    if ((menu->boxes[1]).but_status == 2)
      *status = -1;
    menu->win= put_box(menu->boxes[1], menu->win);

    if (game->lvl)
    {
        if (!display_game_lvl(menu, game, status, game->lvl))
            return ;
    }
}

