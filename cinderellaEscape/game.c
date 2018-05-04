#include "cinderella.h"

t_page  *game_init(void)
{
    t_page *game;

    if (!(game = (t_page *)malloc(sizeof(t_page))))
        exit(EXIT_FAILURE);
    if (!(game->buts = (t_box *)malloc(sizeof(t_box) * 10))) /// 10 !!
        exit(EXIT_FAILURE);
    if (!(game->bots = (t_bots **)malloc(sizeof(t_bots *) * 20))) /// 20
        exit(EXIT_FAILURE);
    if (!(game->elems = (t_elems **)malloc(sizeof(t_elems *) * 20))) /// 20
        exit(EXIT_FAILURE);
    game->execution = 0;
    game->lvl = 0;
    return(game);
}

void    clear_lvl(t_page *game)
{
    if (game->lvl == 1)
    {
        game->win = add_reg_bmp(game->win, "imgs/map1.bmp", 560, 490, 238, 108);
        (game->elems)[0] = new_elem(15, 13, "imgs/finish.bmp", game);
        (game->elems)[1] = new_elem(10, 10, "imgs/banana.bmp", game);
        (game->elems)[2] = new_elem(5, 10, "imgs/banana.bmp", game);
        (game->elems)[3] = new_elem(3, 5, "imgs/banana.bmp", game);
        (game->elems)[4] = new_elem(12, 2, "imgs/banana.bmp", game);
        (game->elems)[5] = NULL;
    }

    if (game->lvl == 2)
    {
        game->win = add_reg_bmp(game->win, "imgs/map2.bmp", 560, 490, 238, 108);
        (game->elems)[0] = new_elem(15, 13, "imgs/finish.bmp", game);
        (game->elems)[1] = new_elem(10, 10, "imgs/banana.bmp", game);
        (game->elems)[2] = new_elem(5, 10, "imgs/banana.bmp", game);
        (game->elems)[3] = new_elem(3, 5, "imgs/banana.bmp", game);
        (game->elems)[4] = new_elem(12, 2, "imgs/banana.bmp", game);
        (game->elems)[5] = NULL;
    }

    if (game->lvl == 3)
    {
        game->win = add_reg_bmp(game->win, "imgs/map1.bmp", 560, 490, 238, 108);
        (game->elems)[0] = new_elem(15, 13, "imgs/finish.bmp", game);
        (game->elems)[1] = new_elem(10, 10, "imgs/banana.bmp", game);
        (game->elems)[2] = new_elem(5, 10, "imgs/banana.bmp", game);
        (game->elems)[3] = new_elem(3, 5, "imgs/banana.bmp", game);
        (game->elems)[4] = new_elem(12, 2, "imgs/banana.bmp", game);
        (game->elems)[5] = NULL;
    }
}

void    game_routine(t_page *game)
{
    game->win = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(game->win);
    game->win = backgroundImg("imgs/bg2.bmp", game->win);
    (game->buts)[0] = newButton(675, 20, "Menu");
    (game->buts)[1] = newButton(500, 20, "Aide");
    (game->buts)[2] = newButton(75, 400, "Run");
    (game->buts)[3] = newButton(50, 450, "Pause");
    game->win = put_box(game->buts[0], game->win);
    game->win = put_box(game->buts[1], game->win);
    game->win = put_box(game->buts[2], game->win);
    game->win = put_box(game->buts[3], game->win);

    game->win = add_alph_bmp(game->win, "imgs/banner2.bmp", 200, 90, 10, 10);
    textprintf_ex(game->win, font, 20, 120, WHITE, BLACK, "LEVEL: %d", game->lvl);
    rect(game->win, 237, 107, 798, 598, BLACK);
    rect(game->win, 15, 190, 220, 380, BLACK);
    rectfill(game->win, 15, 190, 220, 380, WHITE);
    game->editor = new_txt(20, 200, 220, 368);
    clear_lvl(game);
    if (game->lvl == 1)
        (game->bots)[0] = new_bot(bots_tab[0], 0, 5, game);
    if (game->lvl == 2)
    {
        (game->bots)[0] = new_bot(bots_tab[0], 0, 5, game);
        (game->bots)[1] = new_bot(bots_tab[1], 0, 7, game);
    }
    if (game->lvl == 3)
    {
        (game->bots)[0] = new_bot(bots_tab[0], 0, 5, game);
    }
}

void game_func(t_page *game, int *status)
{
    game->buts[0] = buttonStatusUpdate(game->buts[0]);
    if ((game->buts[0]).but_status == 2)
    {
        *status = 0;
        destroy_bitmap(game->win);
        return;
    }
    game->win = put_box(game->buts[0], game->win);

    game->buts[1] = buttonStatusUpdate(game->buts[1]);
    if ((game->buts[1]).but_status == 2){}
    game->win = put_box(game->buts[1], game->win);

    game->buts[2] = buttonStatusUpdate(game->buts[2]);
    if ((game->buts[2]).but_status == 2)
        game->execution = 1;
    game->win = put_box(game->buts[2], game->win);

    game->buts[3] = buttonStatusUpdate(game->buts[3]);
    if ((game->buts[3]).but_status == 2)
        game->execution ^= 1;
    game->win = put_box(game->buts[3], game->win);

    if (game->execution)
        exec_code(game);
    if (check_all_be_col(game) == 1)
    {
        allegro_message("You pass level %d !", game->lvl);
        game->lvl += 1;
        free_elems(game->elems);
        destroy_bitmap(game->win);
        game_routine(game);
    }
    else if (check_all_be_col(game) == -1)
    {
        allegro_message("You lose at level %d", game->lvl);
        game_routine(game);
    }
    read_buf(game->editor, game);
}
