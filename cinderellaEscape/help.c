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
