#include "cinderella.h"

void    leave_game(t_box *m_buts, t_box *g_buts, BITMAP *game, BITMAP *menu)
{
    free(m_buts);
    free(g_buts);
    destroy_bitmap(game);
    destroy_bitmap(menu);
    allegro_exit();
    exit(EXIT_SUCCESS);
}
