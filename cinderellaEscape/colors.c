#include "cinderella.h"


void    reset_coltab(t_page *game)
{
    game->cols[0].x = -1;
}

void    add_color_case(t_page *game, t_bots *current)
{
    int i = 0;

    while (game->cols[i].x != -1)
        i++;
    (game->cols[i]).x = 238 + (current->virt_x * 35);
    (game->cols[i]).y = 108 + (current->virt_y * 35);
    game->cols[i + 1].x = -1;
    //printf("okok");
}

void    display_color(t_page *game)
{
    int i = 0;

    //printf("toot\n");
    while (game->cols[i].x != -1)
    {
        //printf("tutu");
        rectfill(game->win, (game->cols[i]).x, (game->cols[i]).y,(game->cols[i]).x + 35, (game->cols[i]).y + 35, YELLOW);
        i++;
    }
}
