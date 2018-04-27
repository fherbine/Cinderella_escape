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
void    menu_routine(t_page *menu)
{
    menu->win = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(menu->win);
    menu->win = backgroundColor(WHITE, menu->win);
    (menu->buts)[0] = newButton(200, 400, "Nouvelle partie");
    (menu->buts)[1] = newButton(300, 500, "Quitter");
    menu->win = put_box(menu->buts[0], menu->win);
    menu->win = put_box(menu->buts[1], menu->win);
    menu->win = add_alph_bmp(menu->win, "imgs/banner.bmp", 200, 90, 300, 20);
}

void menu_func(t_page *menu, int *status)
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
}

