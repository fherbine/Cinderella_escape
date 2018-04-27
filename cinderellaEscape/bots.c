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
    printf("%d %d", i, seq.nimg);
    //while (i < seq.nimg)
   // {
  //      seq.img[i] = create_bitmap(seq.sx, seq.sy);
   //     i++;
   //     clear_bitmap(seq.img[i]);
   //     blit(tmp, seq.img[i], px, 0, 0, 0, seq.sx, seq.sy);
   //     px += seq.sx;
   // }
    destroy_bitmap(tmp);
    return(seq);
}


void    init_all_seq(void)
{
    for(int i = 0; i < NSEQ; i++)
    {
        printf("%s", bots_tab[i].path);
        bots_tab[i] = init_seq(bots_tab[i]);
    }
}

t_bots  *new_bot(t_bots_seq seq, int x, int y)
{
    t_bots *bot;

    if (!(bot = (t_bots *)malloc(sizeof(t_bots))))
        exit(EXIT_FAILURE);
    bot->virt_x = x;
    bot->virt_y = y;
    bot->pos_x = 238 + (x * 35);
    bot->pos_y = 108 + (y * 35);
    bot->seq = seq;
    return (bot);
}

t_bots  *refresh_bot(t_bots *bot, int dest_x, int dest_y, t_page *game)
{
    int cur_x = bot->virt_x, cur_y = bot->virt_y;
    int i = 0;
    text_mode(-1);
    while(cur_x < dest_x)
    {
        clear_bitmap(bot->buffer);
        masked_blit(bot->seq.img[i], bot->buffer, 0, 0, 0, 0, bot->seq.sx, bot->seq.sy);
        blit(bot->buffer, game->win, 0, 0, bot->pos_x, bot->pos_y, bot->seq.sx, bot->seq.sy);
        bot->virt_x += 1;
        bot->pos_x += bot->seq.sx;
    }
   /* while(cur_x < dest_x)
    {

    }
    while(cur_y < dest_y)
    {

    }
    while(cur_y < dest_y)
    {

    }*/
}
