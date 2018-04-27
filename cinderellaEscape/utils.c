#include "cinderella.h"

void    leave_game(t_page *game, t_page *menu)
{
    free(menu->buts);
    free(game->buts);
    destroy_bitmap(game->win);
    destroy_bitmap(menu->win);
    free(menu);
    free(game);
    allegro_exit();
    exit(EXIT_SUCCESS);
}
