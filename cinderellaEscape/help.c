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
    (help->boxes)[0] = init_box(80, 15, 720, 585);
    (help->boxes)[0].bg_color = WHITE;
    (help->boxes)[0].borders = BLACK;
    (help->boxes)[1] = newButton(400, 50, "Menu");
    (help->boxes)[2] = newButton(550, 50, "Jeu");
    help->win = put_box(help->boxes[0], help->win);
    help->win = put_box(help->boxes[1], help->win);
    help->win = put_box(help->boxes[2], help->win);
    help->win = add_alph_bmp(help->win, "imgs/banner.bmp", 200, 90, 100, 40);
    line(help->win, 100, 140, 700, 140, BLACK);

    textprintf_ex(help->win, font, 100, 170,  BLACK, WHITE, "BYTECODE:");
    textprintf_ex(help->win, font, 100, 185,  BLACK, WHITE, "- u<x>: Monter de x cases.         - d<x>: Descendre de x cases.");
    textprintf_ex(help->win, font, 100, 195,  BLACK, WHITE, "- r<x>: Aller a droite de x cases. - l<x>: Aller a gauche de x cases.");
    textprintf_ex(help->win, font, 100, 205,  BLACK, WHITE, "- R: Recommencer le bytecode.");
}

void help_func(t_page *help, int *status)
{
    //help->win = put_box(help->boxes[0], help->win);

    help->boxes[1] = buttonStatusUpdate(help->boxes[1]);
    if ((help->boxes[1]).but_status == 2)
    {
        *status = 0;
        destroy_bitmap(help->win);
        return;
    }
    help->win = put_box(help->boxes[1], help->win);

    help->boxes[2] = buttonStatusUpdate(help->boxes[2]);
    if ((help->boxes[2]).but_status == 2)
    {
        *status = 1;
        destroy_bitmap(help->win);
        return;
    }
    help->win = put_box(help->boxes[2], help->win);
}
