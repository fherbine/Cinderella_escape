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


t_bots_seq  *init_all_seq(t_bots_seq *seqs)
{
    for(int i = 0; i < NSEQ; i++)
    {
        seqs[i] = init_seq(seqs[i]);
    }
    return (seqs);
}

t_bots  new_bot(t_bots_seq seq, int x, int y)
{
    t_bots bot;

    bot.virt_x = x;
    bot.virt_y = y;
    bot.pos_x = 238 + (x * 35);
    bot.pos_y = 108 + (y * 35);
    bot.cur_bot = seq;
    return (bot);
}

t_bots  refresh_bot(t_bots bot, int dest_x, int dest_y)
{
    int cur_x = bot.virt_x, cur_y = bot.virt_y;
    text_mode(-1);
    while(cur_x < dest_x)
    {
    }
    while(cur_x < dest_x)
    {

    }
    while(cur_y < dest_y)
    {

    }
    while(cur_y < dest_y)
    {

    }
}
