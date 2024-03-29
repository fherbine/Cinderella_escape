#include "cinderella.h"

static t_bots_seq  init_seq(t_bots_seq seq)
{
    int i = 0;
    int px = 0;
    BITMAP *tmp;

    if (!(seq.img = (BITMAP **)malloc(sizeof(BITMAP *) * (seq.nimg + 1))))
        exit(EXIT_FAILURE);

    tmp = load_bitmap(seq.path, NULL);

    seq.img[seq.nimg] = NULL;
    while (i < seq.nimg)
   {
        seq.img[i] = create_bitmap(seq.sx, seq.sy);
        clear_bitmap(seq.img[i]);
        blit(tmp, seq.img[i], px, 0, 0, 0, seq.sx, seq.sy);
        i++;
        px += seq.sx;
    }
    destroy_bitmap(tmp);
    return(seq);
}


void    init_all_seq(void)
{
    int i = 0;

    for(i = 0; i < NSEQ; i++)
    {
        bots_tab[i] = init_seq(bots_tab[i]);
    }
}

void    refresh_pos(t_bots *bot, t_page *game)
{
    clear_bitmap(bot->buffer);
    blit(game->win, bot->buffer, 0, 0, 0, 0, SCREEN_W,SCREEN_H);
    rotate_sprite(bot->buffer, bot->seq.img[(int)bot->cur_img], (int)bot->pos_x, (int)bot->pos_y, itofix(bot->angle));
    blit(bot->buffer, game->win,  0, 0, 0, 0, SCREEN_W,SCREEN_H);
}

t_bots  *new_bot(t_bots_seq seq, float x, float y, t_page *game)
{
    t_bots *bot;

    if (!(bot = (t_bots *)malloc(sizeof(t_bots))))
        exit(EXIT_FAILURE);
    bot->virt_x = x;
    bot->virt_y = y;
    bot->last_x = x;
    bot->last_y = y;
    bot->dest_x = x;
    bot->dest_y = y;
    bot->angle = 0;
    bot->pos_x = 238 + (x * 35);
    bot->pos_y = 108 + (y * 35);
    bot->seq = seq;
    bot->cur_img = 0;
    bot->buffer = create_bitmap(SCREEN_W, SCREEN_H);
    //clear_lvl(game);
    clear_bitmap(bot->buffer);
    blit(game->win, bot->buffer, 0, 0, 0, 0, SCREEN_W,SCREEN_H);
    rotate_sprite(bot->buffer, bot->seq.img[(int)bot->cur_img], (int)bot->pos_x, (int)bot->pos_y, itofix(0));
    blit(bot->buffer, game->win,  0, 0, 0, 0, SCREEN_W,SCREEN_H);
    return (bot);
}

int refresh_bot(t_bots *bot, float dest_x, float dest_y, t_page *game, t_bots **bots)
{
    float cur_x = bot->virt_x, cur_y = bot->virt_y;
    int i = 0;

    bot->dest_x = dest_x;
    bot->dest_y = dest_y;
    if(cur_x < bot->dest_x)
    {
        clear_lvl(game);
        clear_bitmap(bot->buffer);
        bot->angle = 0;
        blit(game->win, bot->buffer, 0, 0, 0, 0, SCREEN_W,SCREEN_H);
        rotate_sprite(bot->buffer, bot->seq.img[(int)bot->cur_img], (int)bot->pos_x, (int)bot->pos_y, itofix(0));
        blit(bot->buffer, game->win,  0, 0, 0, 0, SCREEN_W,SCREEN_H);
        bot->virt_x += 0.05;
        cur_x += 0.05;
        bot->pos_x += bot->seq.sx / 20;
    }
    if(cur_x > bot->dest_x)
    {
        clear_lvl(game);
        clear_bitmap(bot->buffer);
        bot->angle = 128;
        blit(game->win, bot->buffer, 0, 0, 0, 0, SCREEN_W,SCREEN_H);
        rotate_sprite(bot->buffer, bot->seq.img[(int)bot->cur_img], (int)bot->pos_x, (int)bot->pos_y, itofix(128));
        blit(bot->buffer, game->win,  0, 0, 0, 0, SCREEN_W,SCREEN_H);
        bot->virt_x -= 0.05;
        cur_x -= 0.05;
        bot->pos_x -= bot->seq.sx / 20;
    }
    if(cur_y < bot->dest_y)
    {
        clear_lvl(game);
        clear_bitmap(bot->buffer);
        bot->angle = 64;
        blit(game->win, bot->buffer, 0, 0, 0, 0, SCREEN_W,SCREEN_H);
        rotate_sprite(bot->buffer, bot->seq.img[(int)bot->cur_img], (int)bot->pos_x, (int)bot->pos_y, itofix(64));
        blit(bot->buffer, game->win,  0, 0, 0, 0, SCREEN_W,SCREEN_H);
        bot->virt_y += 0.05;
        cur_y += 0.05;
        bot->pos_y += bot->seq.sy / 20;
    }
    if(cur_y > bot->dest_y)
    {
        clear_lvl(game);
        clear_bitmap(bot->buffer);
        bot->angle = 192;
        blit(game->win, bot->buffer, 0, 0, 0, 0, SCREEN_W,SCREEN_H);
        rotate_sprite(bot->buffer, bot->seq.img[(int)bot->cur_img], (int)bot->pos_x, (int)bot->pos_y, itofix(192));
        blit(bot->buffer, game->win,  0, 0, 0, 0, SCREEN_W,SCREEN_H);
        bot->virt_y -= 0.05;
        cur_y -= 0.05;
        bot->pos_y -= bot->seq.sy / 20;
    }
   // while(bots[i])
   // {
   //     rotate_sprite(bots[i]->buffer, bots[i]->seq.img[(int)bots[i]->cur_img], (int)bots[i]->pos_x, (int)bots[i]->pos_y, itofix(bots[i]->angle));
   //     blit(bots[i]->buffer, game->win,  0, 0, 0, 0, SCREEN_W,SCREEN_H);
   //     i++;
   // }
    bot->cur_img = (bot->cur_img >= 3) ? 0 : bot->cur_img + 0.1;
    if (cur_x - bot->dest_x <= 0.05 && cur_x - bot->dest_x >= -0.05 && cur_y - bot->dest_y <= 0.05 && cur_y - bot->dest_y >= -0.05)
    {
        bot->last_x = cur_x;
        bot->last_y = cur_y;
        return (1);
    }
    return (0);
}
