#include "cinderella.h"

void    exec_code(t_page *game)
{
    int end = 0;
    t_bots *current_bot;
    t_text *text;
    text = game->editor;

    current_bot = (game->bots)[0];
    if ((text->buf)[text->i])
    {
        if (strcmp(&((text->buf)[text->i]), "c[") == 0)
            current_bot = (game->bots)[0];
        if (strcmp(&((text->buf)[text->i]), "p[") == 0 && game->lvl == 2)
            current_bot = (game->bots)[1];
        if (text->n == -1 && strchr("123456789", (text->buf)[text->i + 1]))
        {
            text->n = atoi(&((text->buf)[text->i + 1]));
            text->n = (text->n == 0) ? 1 : text->n;
        }
        else if (text->n == -1)
            text->n = 1;

        if (((text->buf)[text->i] == 'r' || get_def_click(45, 160, 75, 185)) && current_bot->last_x + text->n <= 15)
            end = refresh_bot(current_bot, current_bot->last_x + text->n, current_bot->last_y, game, game->bots);
        else if (((text->buf)[text->i] == 'l' || get_def_click(80, 160, 110, 185)) && current_bot->last_x - text->n >= 0)
            end = refresh_bot(current_bot, current_bot->last_x - text->n, current_bot->last_y, game, game->bots);
        else if (((text->buf)[text->i] == 'd' || get_def_click(150, 160, 180, 185)) && current_bot->last_y + text->n < 14)
            end = refresh_bot(current_bot, current_bot->last_x, current_bot->last_y + text->n, game, game->bots);
        else if (((text->buf)[text->i] == 'u' || get_def_click(115, 160, 145, 185)) && current_bot->last_y - text->n >= 0)
            end = refresh_bot(current_bot, current_bot->last_x, current_bot->last_y - text->n, game, game->bots);
        else if ((text->buf)[text->i] == 'R')
            text->i = 0;
        else
            end = 1;
        text->i += (end) ? 1 : 0;
        text->n = (end) ? -1 : text->n;
    }
    else
    {
        current_bot->virt_x = round(current_bot->virt_x);
        current_bot->virt_y = round(current_bot->virt_y);
        game->execution = 0;
        text->i = 0;
        text->n = -1;
    }
}

int get_one_move(void)
{
    if (get_def_click(45, 160, 75, 185) || get_def_click(80, 160, 110, 185) || get_def_click(115, 160, 145, 185) || get_def_click(150, 160, 180, 185))
        return (1);
    return (0);
}
