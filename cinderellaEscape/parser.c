#include "cinderella.h"

void    exec_code(t_text *text, t_page *game)
{
    int n = 1;
    t_bots *current_bot;

    current_bot = (game->bots)[0];
    if ((text->buf)[text->i])
    {
        if (strcmp(&((text->buf)[text->i]), "c[") == 0)
            current_bot = (game->bots)[0];
        if (strchr("123456789", (text->buf)[text->i + 1]))
            n = atoi(&((text->buf)[text->i + 1]));
        if ((text->buf)[text->i] == 'r' && current_bot->virt_x + n <= 16)
            refresh_bot(current_bot, current_bot->virt_x + n, current_bot->virt_y, game);
        else if ((text->buf)[text->i] == 'l' && current_bot->virt_x - n >= 0)
            refresh_bot(current_bot, current_bot->virt_x - n, current_bot->virt_y, game);
        else if ((text->buf)[text->i] == 'd' && current_bot->virt_y + n <= 14)
            refresh_bot(current_bot, current_bot->virt_x, current_bot->virt_y + n, game);
        else if ((text->buf)[text->i] == 'u' && current_bot->virt_y - n >= 0)
            refresh_bot(current_bot, current_bot->virt_x, current_bot->virt_y - n, game);
        text->i += 1;
    }
}
