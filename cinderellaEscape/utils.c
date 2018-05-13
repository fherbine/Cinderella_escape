#include "cinderella.h"

void    leave_game(t_page *game, t_page *menu)
{
    free(menu->boxes);
    free(game->boxes);
    // destroy_bitmap(game->win);
    destroy_bitmap(menu->win);
    free(menu);
    free(game);
    allegro_exit();
    exit(EXIT_SUCCESS);
}


int     check_be_col(t_bots *bot, t_elems **elems, int i, int max_n)
{
    while (elems[i] && i < max_n)
    {
        if (round(bot->virt_x) == elems[i]->virt_x && round(bot->virt_y) == elems[i]->virt_y)
            return (1);
        i++;
    }
    return(0);
}

int check_all_be_col(t_page *game)
{
    if (game->lvl == 1)
    {
        if (check_be_col(game->bots[0], game->elems, 1, 5))
            return (-1);
        if (check_be_col(game->bots[0], game->elems, 0, 1))
            return (1);
    }
    else if (game->lvl == 2)
    {
        if (check_be_col(game->bots[0], game->elems, 2, 6 ) || check_be_col(game->bots[1], game->elems, 2, 6 ))
            return (-1);
        if (check_be_col(game->bots[0], game->elems, 0, 2) && check_be_col(game->bots[1], game->elems, 0, 2))
            return (1);
    }
    else if (game->lvl == 4)
    {
        if (check_be_col(game->bots[0], game->elems, 2, 9 ) || check_be_col(game->bots[1], game->elems, 2, 9 ))
            return (-1);
        if (check_be_col(game->bots[0], game->elems, 0, 2) && check_be_col(game->bots[1], game->elems, 0, 2))
            return (1);
    }
    else if (game->lvl == 3)
    {
        if (check_be_col(game->bots[0], game->elems, 1, 5))
            return (-1);
        if (check_be_col(game->bots[0], game->elems, 0, 1))
            return (1);
    }
}
