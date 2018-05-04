#include "cinderella.h"

t_page  *help_init(void)
{
    t_page *help;

    if (!(help = (t_page *)malloc(sizeof(t_page))))
        exit(EXIT_FAILURE);
    if (!(help->buts = (t_box *)malloc(sizeof(t_box) * 10))) /// 10 !!
        exit(EXIT_FAILURE);
    return (help);
}

void    help_routine(t_page *help)
{
    help->win = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(help->win);
    help->win = backgroundImg("imgs/bg2.bmp", help->win);
    (help->buts)[0] = newButton(200, 375, "Menu");
    (help->buts)[1] = newButton(300, 450, "Jeu");
    help->win = put_box(help->buts[0], help->win);
    help->win = put_box(help->buts[1], help->win);
    //menu->win = add_alph_bmp(menu->win, "imgs/banner.bmp", 200, 90, 300, 20);
}

void help_func(t_page *help, int *status)
{
    help->buts[0] = buttonStatusUpdate(help->buts[0]);
    if ((help->buts[0]).but_status == 2)
    {
        *status = 0;
        destroy_bitmap(help->win);
        return;
    }
    help->win = put_box(help->buts[0], help->win);

    help->buts[1] = buttonStatusUpdate(help->buts[1]);
    if ((help->buts[1]).but_status == 2)
    {
        *status = 1;
        destroy_bitmap(help->win);
        return;
    }
    help->win = put_box(help->buts[1], help->win);
}
