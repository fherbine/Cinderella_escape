#include "cinderella.h"

t_page  *help_init(void)
{
    t_page *help;

    if (!(help = (t_page *)malloc(sizeof(t_page))))
        exit(EXIT_FAILURE);
    if (!(help->boxes = (t_box *)malloc(sizeof(t_box) * 10))) /// 10 !!
        exit(EXIT_FAILURE);
    return (help);
}

void    help_routine(t_page *help)
{
    help->win = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(help->win);
    help->win = backgroundImg("imgs/bg2.bmp", help->win);
    (help->boxes)[0] = newButton(200, 50, "Menu");
    (help->boxes)[1] = newButton(300, 50, "Jeu");
    help->win = put_box(help->boxes[0], help->win);
    help->win = put_box(help->boxes[1], help->win);
    //menu->win = add_alph_bmp(menu->win, "imgs/banner.bmp", 200, 90, 300, 20);
}

void help_func(t_page *help, int *status)
{
    help->boxes[0] = buttonStatusUpdate(help->boxes[0]);
    if ((help->boxes[0]).but_status == 2)
    {
        *status = 0;
        destroy_bitmap(help->win);
        return;
    }
    help->win = put_box(help->boxes[0], help->win);

    help->boxes[1] = buttonStatusUpdate(help->boxes[1]);
    if ((help->boxes[1]).but_status == 2)
    {
        *status = 1;
        destroy_bitmap(help->win);
        return;
    }
    help->win = put_box(help->boxes[1], help->win);
}
