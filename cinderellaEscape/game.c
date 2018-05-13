#include "cinderella.h"

t_page  *game_init(void)
{
    t_page *game;

    if (!(game = (t_page *)malloc(sizeof(t_page))))
        exit(EXIT_FAILURE);
    if (!(game->boxes = (t_box *)malloc(sizeof(t_box) * 10))) /// 10 !!
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
    int tmp = game->locked_time - (int)time(NULL);
    if (game->lvl == 1 || game->lvl == 3)
    {
        game->win = add_reg_bmp(game->win, "imgs/map1.bmp", 560, 490, 238, 108);
        (game->elems)[0] = new_elem(15, 13, "imgs/finish.bmp", game);
        (game->elems)[1] = new_elem(10, 10, "imgs/banana.bmp", game);
        (game->elems)[2] = new_elem(5, 10, "imgs/banana.bmp", game);
        (game->elems)[3] = new_elem(3, 5, "imgs/banana.bmp", game);
        (game->elems)[4] = new_elem(12, 2, "imgs/banana.bmp", game);
        (game->elems)[5] = NULL;
        display_color(game);
        if(game->lvl == 3)
            textprintf_ex(game->win, font, 240, 110, RED, GREEN, "0:%s%d", (tmp / 10) ?  "" : "0", tmp);
        refresh_pos((game->bots)[0], game);
    }

    if (game->lvl == 2)
    {
        game->win = add_reg_bmp(game->win, "imgs/map2.bmp", 560, 490, 238, 108);
        (game->elems)[0] = new_elem(15, 4, "imgs/finish.bmp", game);
        (game->elems)[1] = new_elem(15, 11, "imgs/finish.bmp", game);
        (game->elems)[2] = new_elem(7, 6, "imgs/banana.bmp", game);
        (game->elems)[3] = new_elem(5, 9, "imgs/banana.bmp", game);
        (game->elems)[4] = new_elem(5, 3, "imgs/banana.bmp", game);
        (game->elems)[5] = new_elem(12, 2, "imgs/banana.bmp", game);
        (game->elems)[6] = NULL;
        display_color(game);
        refresh_pos((game->bots)[0], game);
        refresh_pos((game->bots)[1], game);
    }

    if (game->lvl == 4)
    {
        game->win = add_reg_bmp(game->win, "imgs/map4.bmp", 560, 490, 238, 108);
        (game->elems)[0] = new_elem(15, 6, "imgs/finish.bmp", game);
        (game->elems)[1] = new_elem(15, 7, "imgs/finish.bmp", game);

        (game->elems)[2] = new_elem(5, 6, "imgs/banana.bmp", game);
        (game->elems)[3] = new_elem(6, 7, "imgs/banana.bmp", game);
        (game->elems)[4] = new_elem(3, 5, "imgs/banana.bmp", game);
        (game->elems)[5] = new_elem(4, 8, "imgs/banana.bmp", game);
        (game->elems)[6] = new_elem(10, 6, "imgs/banana.bmp", game);
        (game->elems)[7] = new_elem(11, 7, "imgs/banana.bmp", game);
        (game->elems)[8] = new_elem(12, 5, "imgs/banana.bmp", game);
        (game->elems)[9] = NULL;
        display_color(game);
        refresh_pos((game->bots)[0], game);
        refresh_pos((game->bots)[1], game);
    }
}

void    game_routine(t_page *game)
{
    printf("===================> ROUTINE\n");
    game->cbot = 0;
    game->win = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(game->win);
    game->win = backgroundImg("imgs/bg2.bmp", game->win);
    (game->boxes)[0] = newButton(675, 20, "Menu");
    (game->boxes)[1] = newButton(500, 20, "Aide");
    (game->boxes)[2] = newButton(75, 400, "Run");
    (game->boxes)[3] = newButton(50, 450, "Pause");
    (game->boxes)[4] = newButton(20, 500, "Reinit.");
    game->win = put_box(game->boxes[0], game->win);
    game->win = put_box(game->boxes[1], game->win);
    game->win = put_box(game->boxes[2], game->win);
    game->win = put_box(game->boxes[3], game->win);
    game->win = put_box(game->boxes[4], game->win);

    game->win = add_alph_bmp(game->win, "imgs/banner2.bmp", 200, 90, 10, 10);
    textprintf_ex(game->win, font, 20, 120, WHITE, BLACK, "LEVEL: %d", game->lvl);
    rect(game->win, 237, 107, 798, 598, BLACK);
    rect(game->win, 15, 190, 220, 380, BLACK);
    rectfill(game->win, 15, 190, 220, 380, WHITE);
    game->editor = new_txt(20, 200, 220, 368);
    reset_coltab(game);
    game->locked_time = (int)time(NULL) + 15;
    if (game->lvl == 1 || game->lvl == 3)
    {
        (game->bots)[0] = new_bot(bots_tab[0], 0, 5, game);
        (game->bots)[1] = NULL;
    }
    if (game->lvl == 2 || game->lvl == 4)
    {
        (game->bots)[0] = new_bot(bots_tab[0], 0, 5, game);
        (game->bots)[1] = new_bot(bots_tab[1], 0, 7, game);
        (game->bots)[2] = NULL;
    }
    add_alph_bmp(game->win, "imgs/rArrow.bmp", 30, 25, 45, 160);
    add_alph_bmp(game->win, "imgs/lArrow.bmp", 30, 25, 80, 160);
    add_alph_bmp(game->win, "imgs/uArrow.bmp", 30, 25, 115, 160);
    add_alph_bmp(game->win, "imgs/dArrow.bmp", 30, 25, 150, 160);
    clear_lvl(game);
    printf("<== ROUTINE\n");
}

void game_func(t_page *game, int *status)
{
    int tmp = game->locked_time - (int)time(NULL);

    if(game->lvl == 3)
        textprintf_ex(game->win, font, 240, 110, RED, GREEN, "0:%s%d", (tmp / 10) ?  "" : "0", tmp);
    game->boxes[0] = buttonStatusUpdate(game->boxes[0]);
    if ((game->boxes[0]).but_status == 2)
    {
        *status = 0;
        destroy_bitmap(game->win);
        return;
    }
    game->win = put_box(game->boxes[0], game->win);

    game->boxes[1] = buttonStatusUpdate(game->boxes[1]);
    if ((game->boxes[1]).but_status == 2)
    {
        *status = 4;
        return;
    }
    game->win = put_box(game->boxes[1], game->win);

    game->boxes[2] = buttonStatusUpdate(game->boxes[2]);
    if ((game->boxes[2]).but_status == 2)
        game->execution = 1;
    game->win = put_box(game->boxes[2], game->win);

    game->boxes[3] = buttonStatusUpdate(game->boxes[3]);
    if ((game->boxes[3]).but_status == 2)
        game->execution ^= 1;
    game->win = put_box(game->boxes[3], game->win);

    game->boxes[4] = buttonStatusUpdate(game->boxes[4]);
    if ((game->boxes[4]).but_status == 2)
    {
        game->execution ^= 1;
        destroy_bitmap(game->win);
        game_routine(game);
    }
    game->win = put_box(game->boxes[4], game->win);

    if (game->execution || get_one_move())
        exec_code(game);
    if (check_all_be_col(game) == 1)
    {
        game->execution = 0;
        if (game->lvl != 4)
        {
            allegro_message("You pass level %d !", game->lvl);
            game->lvl += 1;
            free_elems(game->elems);
            destroy_bitmap(game->win);
            game_routine(game);
        }
        else
        {
            allegro_message("Congratulations, you won!", game->lvl);
            *status = 0;
            destroy_bitmap(game->win);
            return;
        }
    }
    else if (check_all_be_col(game) == -1 || (tmp == 0 && game->lvl == 3))
    {
        allegro_message("You lose at level %d", game->lvl);
        game_routine(game);
        game->execution = 0;
    }
    read_buf(game->editor, game);
}
